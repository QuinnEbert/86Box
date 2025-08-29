#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <wchar.h>
/* Use 86Box's portable dir APIs; they include <dirent.h> on POSIX and
 * provide compatible definitions on Windows. Avoid including <dirent.h>
 * directly to prevent redefinition conflicts on MinGW/MSVC builds. */

#include <86box/86box.h>
#include <86box/path.h>
#include <86box/plat.h>
#include <86box/plat_dir.h>
#include <86box/hdd.h>

#include "hostfat.h"

typedef struct hostfat_entry {
    char     name_sfn[12]; /* 8+3 (no dot), padded spaces */
    char     name_lfn[260]; /* UTF-8 long name */
    uint8_t  attr;  /* 0x10 dir, 0x20 file */
    uint32_t size;  /* for files */
    uint32_t start_cluster; /* low 16|high 16 composed for FAT32 */
    uint32_t first_cluster_alloc; /* internal */
    char     host_path[2048];
    struct hostfat_entry *parent;
    struct hostfat_entry *next;
    struct hostfat_entry *children; /* for dirs */
    /* Directory blob for this node (for dirs only) */
    uint8_t *dir_blob;
    uint32_t dir_blob_bytes;
} hostfat_entry_t;

typedef struct cluster_map_entry {
    hostfat_entry_t *entry;
    uint32_t         chunk_index; /* cluster index within entry logical stream */
    uint8_t          is_dir; /* 1 if maps directory blob */
} cluster_map_entry_t;

static void write_le16(uint8_t *p, uint16_t v) { p[0] = v & 0xFF; p[1] = (v >> 8) & 0xFF; }
static void write_le32(uint8_t *p, uint32_t v) { p[0] = v & 0xFF; p[1] = (v >> 8) & 0xFF; p[2] = (v >> 16) & 0xFF; p[3] = (v >> 24) & 0xFF; }

struct hostfat {
    char     root_path[1024];
    uint8_t  fat_type;     /* 16 or 32 */
    uint8_t  os_level;     /* 0 auto, 1 dos, 2 win9x, 3 nt */

    uint16_t bps;          /* bytes per sector (512) */
    uint8_t  spc;          /* sectors per cluster */
    uint16_t reserved;     /* reserved sectors */
    uint8_t  nfats;        /* number of FATs (2) */
    uint32_t spf;          /* sectors per FAT */
    uint16_t root_entries; /* FAT16 only */
    uint16_t root_sectors; /* FAT16 only */
    uint32_t root_cluster; /* FAT32 only */
    uint32_t fsinfo_sector;/* FAT32 only */
    uint32_t part_lba;     /* partition start LBA (2048) */
    uint32_t total_sectors;/* partition total sectors */
    uint32_t data_start;   /* LBA of first data sector, relative to partition */
    uint32_t cluster_count;

    uint32_t *fat;         /* entries (cluster_count + 2), 16-bit if FAT16, 32-bit if FAT32 (we store 32) */
    cluster_map_entry_t *cluster_map; /* [cluster_count + 2] mapping to file/dir blobs */

    hostfat_entry_t *root; /* in-memory tree */

    /* Flattened directory blobs for quick mapping */
    /* We build on demand and invalidate upon write */
};

/* Forward declarations */
static void build_dir_blob_for_node(hostfat_t *hf, hostfat_entry_t *dir);
static void reconcile_directory(hostfat_t *hf, hostfat_entry_t *dir);
static uint32_t cluster_bytes(const hostfat_t *hf);
static void rebuild_cluster_map(hostfat_t *hf);

static uint32_t ceil_div_u32(uint32_t a, uint32_t b) { return (a + b - 1) / b; }

static void sfn_from_name_simple(const char *name, char out_name[8], char out_ext[3])
{
    memset(out_name, ' ', 8);
    memset(out_ext,  ' ', 3);
    const char *dot = strrchr(name, '.');
    size_t nlen = dot ? (size_t)(dot - name) : strlen(name);
    size_t elen = dot ? strlen(dot + 1) : 0;
    if (nlen > 8) nlen = 8;
    if (elen > 3) elen = 3;
    for (size_t i = 0; i < nlen; i++) {
        char c = name[i]; if (c >= 'a' && c <= 'z') c -= 32; if (c == ' ' || c == '.' || c == '+' || c == ',' || c == ';' || c == '=' || c == '[' || c == ']' || c == ':') c = '_'; out_name[i] = c;
    }
    if (dot) {
        for (size_t i = 0; i < elen; i++) { char c = dot[1 + i]; if (c >= 'a' && c <= 'z') c -= 32; out_ext[i] = c; }
    }
}

static void make_sfn_tilde(const char *base, int seq, char name[8])
{
    /* base is uppercase 8 chars; replace tail with ~n */
    (void)base; /* base already in name[] */
    int n = seq;
    int digits = (n < 10) ? 1 : (n < 100) ? 2 : 3;
    int cut = 8 - (digits + 1);
    if (cut < 1) cut = 1;
    for (int i = cut; i < 8; i++) name[i] = ' ';
    name[cut] = '~';
    for (int i = 0; i < digits; i++) {
        name[cut + 1 + digits - 1 - i] = '0' + (n % 10);
        n /= 10;
    }
}

static uint8_t lfn_checksum(const uint8_t sfn[11])
{
    uint8_t sum = 0;
    for (int i = 0; i < 11; i++) sum = ((sum & 1) ? 0x80 : 0) + (sum >> 1) + sfn[i];
    return sum;
}

/* UTF-8 to UCS-2 (very limited: BMP only) */
static int utf8_to_ucs2(const char *s, uint16_t *out, int max)
{
    int n = 0;
    while (*s && n < max) {
        unsigned char c = (unsigned char)*s++;
        if (c < 0x80) out[n++] = c;
        else if ((c & 0xE0) == 0xC0) { unsigned char c2 = (unsigned char)*s++; out[n++] = ((c & 0x1F) << 6) | (c2 & 0x3F); }
        else if ((c & 0xF0) == 0xE0) { unsigned char c2 = (unsigned char)*s++; unsigned char c3 = (unsigned char)*s++; out[n++] = ((c & 0x0F) << 12) | ((c2 & 0x3F) << 6) | (c3 & 0x3F); }
        else { /* skip 4-byte */ s += 2; }
    }
    return n;
}

static void append_lfn_entries(uint8_t **p, const char *lfn_utf8, const uint8_t sfn[11])
{
    /* Build VFAT LFN entries if OS level requires it */
    uint16_t ucs[260];
    int ulen = utf8_to_ucs2(lfn_utf8, ucs, 260);
    if (ulen <= 0) return;
    int lfn_count = ceil_div_u32((uint32_t)ulen, 13);
    uint8_t checksum = lfn_checksum(sfn);
    for (int i = lfn_count; i >= 1; i--) {
        uint8_t *e = *p;
        memset(e, 0xFF, 32);
        e[0] = (uint8_t)i; if (i == lfn_count) e[0] |= 0x40;
        e[11] = 0x0F; /* LFN attr */
        e[13] = checksum;
        int idx = (i - 1) * 13;
        uint16_t slots[13] = {0xFFFF};
        for (int j = 0; j < 13; j++) slots[j] = (idx + j < ulen) ? ucs[idx + j] : 0xFFFF;
        /* name fields: 1-5, 14-26, 28-31 */
        for (int j = 0; j < 5; j++) *((uint16_t *)(e + 1 + j * 2)) = slots[j];
        for (int j = 0; j < 6; j++) *((uint16_t *)(e + 14 + j * 2)) = slots[5 + j];
        for (int j = 0; j < 2; j++) *((uint16_t *)(e + 28 + j * 2)) = slots[11 + j];
        *p += 32;
    }
}

/* Check SFN uniqueness among siblings and add tilde sequence if needed */
static void ensure_unique_sfn_in_dir(hostfat_entry_t *dir, char name[8], char ext[3])
{
    int seq = 1;
    for (;;) {
        int clash = 0;
        for (hostfat_entry_t *e = dir->children; e; e = e->next) {
            if (!memcmp(e->name_sfn, name, 8) && !memcmp(e->name_sfn + 8, ext, 3)) { clash = 1; break; }
        }
        if (!clash) break;
        char base8[8]; memcpy(base8, name, 8);
        make_sfn_tilde((const char*)base8, seq++, name);
    }
}

static hostfat_entry_t *new_entry(hostfat_entry_t *parent, const char *basename, const char *path, int is_dir)
{
    hostfat_entry_t *e = (hostfat_entry_t *)calloc(1, sizeof(hostfat_entry_t));
    e->parent = parent;
    strncpy(e->host_path, path, sizeof(e->host_path) - 1);
    strncpy(e->name_lfn, basename, sizeof(e->name_lfn) - 1);
    e->attr = is_dir ? 0x10 : 0x20;
    char n8[8], x3[3];
    sfn_from_name_simple(basename, n8, x3);
    /* ensure SFN uniqueness */
    if (parent) ensure_unique_sfn_in_dir(parent, n8, x3);
    memcpy(e->name_sfn, n8, 8); memcpy(e->name_sfn + 8, x3, 3);
    e->size = 0;
    e->start_cluster = 0;
    /* link into parent */
    if (parent) {
        e->next = parent->children;
        parent->children = e;
    }
    return e;
}

static void scan_dir_recursive(hostfat_t *hf, hostfat_entry_t *parent)
{
    DIR *d = opendir(parent->host_path);
    if (!d) return;
    struct dirent *de; char pathbuf[2048];
    while ((de = readdir(d))) {
        if (!strcmp(de->d_name, ".") || !strcmp(de->d_name, "..")) continue;
        snprintf(pathbuf, sizeof(pathbuf), "%s%s%s", parent->host_path, path_get_slash(parent->host_path), de->d_name);
        struct stat st; if (stat(pathbuf, &st) != 0) continue;
        if (S_ISDIR(st.st_mode)) {
            hostfat_entry_t *dir = new_entry(parent, de->d_name, pathbuf, 1);
            scan_dir_recursive(hf, dir);
        } else if (S_ISREG(st.st_mode)) {
            hostfat_entry_t *fe = new_entry(parent, de->d_name, pathbuf, 0);
            fe->size = (uint32_t)st.st_size;
        }
    }
    closedir(d);
}

static uint32_t cluster_bytes(const hostfat_t *hf) { return hf->bps * hf->spc; }

static void fat_set_end(hostfat_t *hf, uint32_t c)
{
    hf->fat[c] = (hf->fat_type == 16) ? 0xFFFF : 0x0FFFFFFF;
}

static void allocate_file(hostfat_t *hf, hostfat_entry_t *e, uint32_t *next_free)
{
    uint32_t cb = cluster_bytes(hf);
    uint32_t need = (e->size + cb - 1) / cb; if (!need) need = 1;
    uint32_t first = *next_free;
    for (uint32_t i = 0; i < need; i++) {
        uint32_t c = (*next_free)++;
        hf->fat[c] = (i == need - 1) ? ((hf->fat_type == 16) ? 0xFFFF : 0x0FFFFFFF) : (c + 1);
        hf->cluster_map[c].entry = e; hf->cluster_map[c].chunk_index = i; hf->cluster_map[c].is_dir = 0;
    }
    e->start_cluster = first;
}

static void build_dir_blob_for_node(hostfat_t *hf, hostfat_entry_t *dir)
{
    /* Calculate needed bytes (LFN entries if os_level >= 2) */
    int with_lfn = (hf->os_level >= 2);
    uint32_t entries = 2; /* . and .. */
    for (hostfat_entry_t *c = dir->children; c; c = c->next) {
        uint32_t l = (uint32_t)strlen(c->name_lfn);
        uint32_t lfn_cnt = with_lfn ? ceil_div_u32(l, 13) : 0;
        entries += lfn_cnt + 1;
    }
    uint32_t bytes = entries * 32;
    dir->dir_blob_bytes = ((bytes + 31) / 32) * 32;
    dir->dir_blob = (uint8_t *)calloc(dir->dir_blob_bytes, 1);
    uint8_t *p = dir->dir_blob;
    /* . */
    memset(p, ' ', 11); p[0] = '.'; p[11] = 0x10; write_le16(p + 0x1A, 0); p += 32;
    /* .. */
    memset(p, ' ', 11); p[0] = '.'; p[1] = '.'; p[11] = 0x10; write_le16(p + 0x1A, 0); p += 32;
    for (hostfat_entry_t *c = dir->children; c; c = c->next) {
        uint8_t sfn[11]; memcpy(sfn, c->name_sfn, 11);
        if (with_lfn) append_lfn_entries(&p, c->name_lfn, sfn);
        memset(p, 0, 32);
        memcpy(p + 0, sfn, 11);
        p[11] = c->attr;
        if (hf->fat_type == 32) write_le16(p + 0x14, (uint16_t)((c->start_cluster >> 16) & 0xFFFF));
        write_le16(p + 0x1A, (uint16_t)(c->start_cluster & 0xFFFF));
        write_le32(p + 0x1C, c->size);
        p += 32;
    }
}

static void allocate_directory(hostfat_t *hf, hostfat_entry_t *dir, uint32_t *next_free)
{
    build_dir_blob_for_node(hf, dir);
    if (hf->fat_type == 16 && dir == hf->root) return; /* FAT16 root outside data */
    uint32_t cb = cluster_bytes(hf);
    uint32_t need = (dir->dir_blob_bytes + cb - 1) / cb; if (!need) need = 1;
    uint32_t first = *next_free;
    for (uint32_t i = 0; i < need; i++) {
        uint32_t c = (*next_free)++;
        hf->fat[c] = (i == need - 1) ? ((hf->fat_type == 16) ? 0xFFFF : 0x0FFFFFFF) : (c + 1);
        hf->cluster_map[c].entry = dir; hf->cluster_map[c].chunk_index = i; hf->cluster_map[c].is_dir = 1;
    }
    dir->start_cluster = first;
}

static void allocate_dirs_recursive(hostfat_t *hf, hostfat_entry_t *dir, uint32_t *next_free)
{
    for (hostfat_entry_t *c = dir->children; c; c = c->next) {
        if (c->attr & 0x10) { /* directory */
            allocate_directory(hf, c, next_free);
            allocate_dirs_recursive(hf, c, next_free);
        }
    }
}

static void allocate_files_recursive(hostfat_t *hf, hostfat_entry_t *dir, uint32_t *next_free)
{
    for (hostfat_entry_t *c = dir->children; c; c = c->next) {
        if (c->attr & 0x10) allocate_files_recursive(hf, c, next_free);
        else allocate_file(hf, c, next_free);
    }
}

/* Rebuild cluster_map by walking FAT chains for every entry based on
   start cluster and size (for files) or dir_blob_bytes (for dirs). */
static void rebuild_cluster_map(hostfat_t *hf)
{
    memset(hf->cluster_map, 0, sizeof(cluster_map_entry_t) * (hf->cluster_count + 2));
    uint32_t cb = cluster_bytes(hf);
    /* Walk tree non-recursively using a stack */
    hostfat_entry_t *stack[8192]; int sp = 0; if (hf->root) stack[sp++] = hf->root;
    while (sp) {
        hostfat_entry_t *e = stack[--sp];
        for (hostfat_entry_t *c = e->children; c; c = c->next) stack[sp++] = c;
        if ((hf->fat_type == 16) && (e == hf->root) && (e->attr & 0x10))
            continue; /* FAT16 root not cluster mapped */
        uint32_t remaining = (e->attr & 0x10) ? (e->dir_blob_bytes ? e->dir_blob_bytes : cb) : (e->size ? e->size : cb);
        uint32_t cnum = e->start_cluster; uint32_t chunk = 0;
        while (cnum >= 2 && cnum < hf->cluster_count + 2 && remaining) {
            hf->cluster_map[cnum].entry = e;
            hf->cluster_map[cnum].chunk_index = chunk++;
            hf->cluster_map[cnum].is_dir = !!(e->attr & 0x10);
            remaining = (remaining > cb) ? (remaining - cb) : 0;
            uint32_t next = hf->fat[cnum];
            if (hf->fat_type == 12) { if ((next & 0x0FFF) >= 0x0FF8) break; next &= 0x0FFF; }
            else if (hf->fat_type == 16) { if (next >= 0xFFF8) break; }
            else { if (next >= 0x0FFFFFF8) break; }
            cnum = next;
        }
    }
}

/* TODO: recursive scan, FAT allocation, cluster_map creation, dir blob creation, and parsing writes. */

/* For now: stub mount that prepares a minimal structure so compilation succeeds while we continue implementing. */

int hostfat_mount(hard_disk_t *hd, hostfat_t **out)
{
    hostfat_t *hf = (hostfat_t *)calloc(1, sizeof(hostfat_t));
    strncpy(hf->root_path, hd->fn, sizeof(hf->root_path) - 1);
    hf->bps = 512;
    hf->nfats = 2;
    hf->part_lba = 2048;
    hf->os_level = hd->shared_os_level;
    uint32_t fake_size_mb = hd->shared_fake_size_mb ? hd->shared_fake_size_mb : 512;
    if (fake_size_mb > 1920) fake_size_mb = 1920;
    /* FS select and layout */
    uint8_t req = hd->shared_fs_type;
    if (req == 0) {
        if (hf->os_level == 4) req = 12; /* DOS 1-2 */
        else req = 16;
    }
    hf->fat_type = (req == 12 || req == 16 || req == 32) ? req : 16;
    uint8_t layout = hd->shared_layout;
    if (layout == 0) layout = (hf->fat_type == 12) ? 2 : 1; /* FAT12 -> superfloppy */
    if (layout == 2) hf->part_lba = 0; else hf->part_lba = 2048;
    hf->total_sectors = fake_size_mb * 2048u;
    if (hf->fat_type == 16) {
        hf->spc = 64; hf->reserved = 1; hf->root_entries = 512; hf->root_sectors = (uint16_t)ceil_div_u32(hf->root_entries * 32, hf->bps);
        /* SPF iteration */
        uint32_t spf = 0; for (int it = 0; it < 4; it++) { uint32_t data_guess = hf->total_sectors - hf->reserved - hf->root_sectors - hf->nfats * (spf ? spf : 1); uint32_t cl = data_guess / hf->spc; uint32_t fat_entries = cl + 2; spf = ceil_div_u32(fat_entries * 2, hf->bps);} hf->spf = spf;
        hf->data_start = hf->reserved + hf->nfats * hf->spf + hf->root_sectors;
        hf->cluster_count = (hf->total_sectors - hf->reserved - hf->root_sectors - hf->nfats * hf->spf) / hf->spc;
    } else if (hf->fat_type == 12) {
        hf->spc = 4; hf->reserved = 1; hf->root_entries = 224; hf->root_sectors = (uint16_t)ceil_div_u32(hf->root_entries * 32, hf->bps);
        uint32_t spf = 1; for (int it = 0; it < 6; it++) { uint32_t data_guess = hf->total_sectors - hf->reserved - hf->root_sectors - hf->nfats * (spf ? spf : 1); uint32_t cl = data_guess / hf->spc; uint32_t fat_entries = cl + 2; uint32_t fat_bytes = (fat_entries * 3 + 1) / 2; spf = ceil_div_u32(fat_bytes, hf->bps);} hf->spf = spf;
        hf->data_start = hf->reserved + hf->nfats * hf->spf + hf->root_sectors;
        hf->cluster_count = (hf->total_sectors - hf->reserved - hf->root_sectors - hf->nfats * hf->spf) / hf->spc;
    } else {
        hf->spc = 16; hf->reserved = 32; hf->root_cluster = 2; hf->fsinfo_sector = 1;
        uint32_t spf = 0; for (int it = 0; it < 4; it++) { uint32_t data_guess = hf->total_sectors - hf->reserved - hf->nfats * (spf ? spf : 1); uint32_t cl = data_guess / hf->spc; uint32_t fat_entries = cl + 2; spf = ceil_div_u32(fat_entries * 4, hf->bps);} hf->spf = spf;
        hf->data_start = hf->reserved + hf->nfats * hf->spf;
        hf->cluster_count = (hf->total_sectors - hf->reserved - hf->nfats * hf->spf) / hf->spc;
    }
    hf->fat = (uint32_t *)calloc(hf->cluster_count + 2, sizeof(uint32_t));
    hf->cluster_map = (cluster_map_entry_t *)calloc(hf->cluster_count + 2, sizeof(cluster_map_entry_t));
    if (hf->fat_type == 16) { hf->fat[0] = 0xFFF8; hf->fat[1] = 0xFFFF; }
    else { hf->fat[0] = 0x0FFFFFF8; hf->fat[1] = 0x0FFFFFFF; }

    /* Build directory tree */
    hf->root = (hostfat_entry_t *)calloc(1, sizeof(hostfat_entry_t));
    hf->root->attr = 0x10; strncpy(hf->root->host_path, hd->fn, sizeof(hf->root->host_path)-1);
    memcpy(hf->root->name_sfn, "ROOT      ", 11);
    scan_dir_recursive(hf, hf->root);
    /* Allocate clusters sequentially */
    uint32_t next_free = 2;
    /* FAT16 root is outside data; make its blob */
    if (hf->fat_type == 16) { build_dir_blob_for_node(hf, hf->root); }
    else { allocate_directory(hf, hf->root, &next_free); }
    /* Allocate directories recursively, then files recursively */
    allocate_dirs_recursive(hf, hf->root, &next_free);
    allocate_files_recursive(hf, hf->root, &next_free);
    *out = hf;
    return 0;
}

void hostfat_unmount(hostfat_t *hf)
{
    if (!hf) return;
    if (hf->fat) free(hf->fat);
    if (hf->cluster_map) free(hf->cluster_map);
    /* Free tree */
    if (hf->root) {
        /* simple post-order free */
        hostfat_entry_t *stack[4096]; int sp = 0; stack[sp++] = hf->root;
        while (sp) {
            hostfat_entry_t *e = stack[--sp];
            for (hostfat_entry_t *c = e->children; c; c = c->next) stack[sp++] = c;
            if (e->dir_blob) free(e->dir_blob);
            free(e);
        }
    }
    free(hf);
}

uint32_t hostfat_last_sector(const hostfat_t *hf)
{
    return hf->part_lba + hf->total_sectors - 1;
}

/* duplicate removed */

static void fill_bpb(hostfat_t *hf, uint8_t *dst)
{
    memset(dst, 0, 512);
    dst[0] = 0xEB; dst[1] = 0x58; dst[2] = 0x90; memcpy(dst+3, "MSDOS5.0", 8);
    write_le16(dst + 11, hf->bps);
    dst[13] = hf->spc;
    write_le16(dst + 14, hf->reserved);
    dst[16] = hf->nfats;
    if (hf->fat_type == 16) {
        write_le16(dst + 17, hf->root_entries);
        write_le16(dst + 19, (hf->total_sectors <= 0xFFFF) ? (uint16_t)hf->total_sectors : 0);
        dst[21] = 0xF8;
        write_le16(dst + 22, (uint16_t)hf->spf);
        write_le16(dst + 24, 63);
        write_le16(dst + 26, 255);
        write_le32(dst + 28, hf->part_lba);
        write_le32(dst + 32, (hf->total_sectors > 0xFFFF) ? hf->total_sectors : 0);
        dst[36] = 0x80; dst[38] = 0x29; write_le32(dst + 39, 0x12345678);
        memcpy(dst + 43, "86BOX HOST ", 11);
        memcpy(dst + 54, "FAT16   ", 8);
    } else {
        write_le16(dst + 17, 0);
        write_le16(dst + 19, 0);
        dst[21] = 0xF8;
        write_le16(dst + 22, 0);
        write_le16(dst + 24, 63);
        write_le16(dst + 26, 255);
        write_le32(dst + 28, hf->part_lba);
        write_le32(dst + 32, hf->total_sectors);
        write_le32(dst + 36, hf->spf);
        write_le16(dst + 40, 0); write_le16(dst + 42, 0);
        write_le32(dst + 44, hf->root_cluster);
        write_le16(dst + 48, hf->fsinfo_sector);
        write_le16(dst + 50, 6);
        dst[64] = 0x80; dst[66] = 0x29; write_le32(dst + 67, 0x12345678);
        memcpy(dst + 71, "86BOX HOST ", 11);
        memcpy(dst + 82, "FAT32   ", 8);
    }
    dst[510] = 0x55; dst[511] = 0xAA;
}

int hostfat_read_sector(hostfat_t *hf, uint32_t lba, uint8_t *dst)
{
    memset(dst, 0, 512);
    if (lba == 0 && hf->part_lba != 0) {
        /* MBR */
        uint8_t *p = dst + 0x1BE;
        p[0] = 0x00; p[4] = (hf->fat_type == 32) ? 0x0C : 0x0E; write_le32(p + 8, hf->part_lba); write_le32(p + 12, hf->total_sectors);
        dst[0x1FE] = 0x55; dst[0x1FF] = 0xAA;
        return 0;
    }
    if (lba < hf->part_lba) return 0;
    uint32_t rel = lba - hf->part_lba;
    if (rel == 0) { fill_bpb(hf, dst); return 0; }
    if (hf->fat_type == 32 && rel == hf->fsinfo_sector) {
        memcpy(dst, "RRaA", 4); memcpy(dst + 484, "rrAa", 4);
        write_le32(dst + 488, 0xFFFFFFFF); write_le32(dst + 492, 0xFFFFFFFF);
        dst[510] = 0x55; dst[511] = 0xAA; return 0;
    }
    /* FAT region */
    uint32_t fat_start = hf->reserved;
    uint32_t fat_end = hf->reserved + hf->nfats * hf->spf;
    if (rel >= fat_start && rel < fat_end) {
        uint32_t fat_sec = (rel - fat_start) % hf->spf;
        if (hf->fat_type == 32) {
            uint32_t ents = 512 / 4; uint32_t start = fat_sec * ents;
            for (uint32_t i = 0; i < ents; i++) { uint32_t idx = start + i; uint32_t v = (idx < hf->cluster_count + 2) ? hf->fat[idx] : 0; write_le32(dst + i * 4, v); }
        } else if (hf->fat_type == 12) {
            /* pack FAT12 */
            uint32_t ents_total = hf->cluster_count + 2;
            uint32_t start_entry = (fat_sec * hf->bps * 2) / 3;
            uint32_t si = 0;
            for (uint32_t i = 0; i < hf->bps; ) {
                uint32_t idx0 = start_entry;
                uint32_t idx1 = start_entry + 1;
                uint16_t v0 = (idx0 < ents_total) ? (hf->fat[idx0] & 0x0FFF) : 0;
                uint16_t v1 = (idx1 < ents_total) ? (hf->fat[idx1] & 0x0FFF) : 0;
                dst[i++] = (uint8_t)(v0 & 0xFF);
                if (i < hf->bps) dst[i++] = (uint8_t)((v0 >> 8) | ((v1 & 0x000F) << 4));
                if (i < hf->bps) dst[i++] = (uint8_t)((v1 >> 4) & 0xFF);
                start_entry += 2;
            }
        } else {
            uint32_t ents = 512 / 2; uint32_t start = fat_sec * ents;
            for (uint32_t i = 0; i < ents; i++) { uint32_t idx = start + i; uint32_t v = (idx < hf->cluster_count + 2) ? hf->fat[idx] : 0; write_le16(dst + i * 2, (uint16_t)v); }
        }
        return 0;
    }
    /* FAT12/16 root directory */
    if (hf->fat_type == 16 || hf->fat_type == 12) {
        uint32_t root_lba0 = hf->reserved + hf->nfats * hf->spf;
        if (rel >= root_lba0 && rel < (root_lba0 + hf->root_sectors)) {
            uint32_t off = (rel - root_lba0) * hf->bps;
            if (hf->root && hf->root->dir_blob && off < hf->root->dir_blob_bytes) memcpy(dst, hf->root->dir_blob + off, hf->bps);
            return 0;
        }
    }
    /* Data region */
    uint32_t data_rel = rel - hf->data_start;
    if (hf->fat_type == 16) data_rel = rel - (hf->reserved + hf->nfats * hf->spf + hf->root_sectors);
    uint32_t cluster_index = data_rel / hf->spc;
    uint32_t sector_in_cluster = data_rel % hf->spc;
    uint32_t cluster_num = 2 + cluster_index;
    /* Map cluster to entry */
    if (cluster_num < hf->cluster_count + 2) {
        cluster_map_entry_t *m = &hf->cluster_map[cluster_num];
        if (m->entry) {
            uint32_t off_in_cluster = sector_in_cluster * hf->bps;
            if (m->is_dir) {
                hostfat_entry_t *d = m->entry;
                uint32_t dir_off = m->chunk_index * cluster_bytes(hf) + off_in_cluster;
                if (d->dir_blob && dir_off < d->dir_blob_bytes) memcpy(dst, d->dir_blob + dir_off, hf->bps);
            } else {
                FILE *fp = plat_fopen(m->entry->host_path, "rb");
                if (fp) { fseeko64(fp, (off64_t)m->chunk_index * cluster_bytes(hf) + off_in_cluster, SEEK_SET); fread(dst, 1, hf->bps, fp); fclose(fp);}            }
        }
    }
    return 0;
}

int hostfat_write_sector(hostfat_t *hf, uint32_t lba, const uint8_t *src)
{
    if (lba < hf->part_lba) return 0;
    uint32_t rel = lba - hf->part_lba;
    /* FAT region writes */
    uint32_t fat_start = hf->reserved;
    uint32_t fat_end = hf->reserved + hf->nfats * hf->spf;
    if (rel >= fat_start && rel < fat_end) {
        uint32_t fat_sec = (rel - fat_start) % hf->spf;
        if (hf->fat_type == 32) {
            uint32_t ents = 512 / 4; uint32_t start = fat_sec * ents;
            for (uint32_t i = 0; i < ents; i++) { uint32_t idx = start + i; if (idx < hf->cluster_count + 2) { uint32_t v = *((const uint32_t *)(src + i * 4)); hf->fat[idx] = v; } }
        } else if (hf->fat_type == 12) {
            uint32_t ents = (hf->bps * 2) / 3; uint32_t start = fat_sec * ents;
            uint32_t si = 0;
            for (uint32_t i = 0; i < ents; i += 2) {
                uint32_t idx0 = start + i, idx1 = start + i + 1;
                if (si + 2 >= hf->bps) break;
                uint16_t b0 = src[si++]; uint16_t b1 = src[si++]; uint16_t b2 = src[si++];
                uint16_t v0 = b0 | ((b1 & 0x0F) << 8);
                uint16_t v1 = ((b1 >> 4) & 0x0F) | (b2 << 4);
                if (idx0 < hf->cluster_count + 2) hf->fat[idx0] = v0 & 0x0FFF;
                if (idx1 < hf->cluster_count + 2) hf->fat[idx1] = v1 & 0x0FFF;
            }
        } else {
            uint32_t ents = 512 / 2; uint32_t start = fat_sec * ents;
            for (uint32_t i = 0; i < ents; i++) { uint32_t idx = start + i; if (idx < hf->cluster_count + 2) { uint16_t v = *((const uint16_t *)(src + i * 2)); hf->fat[idx] = v; } }
        }
        rebuild_cluster_map(hf);
        return 0;
    }
    /* FAT12/16 root directory */
    if (hf->fat_type == 16 || hf->fat_type == 12) {
        uint32_t root_lba0 = hf->reserved + hf->nfats * hf->spf;
        if (rel >= root_lba0 && rel < (root_lba0 + hf->root_sectors)) {
            uint32_t off = (rel - root_lba0) * hf->bps;
            if (hf->root && hf->root->dir_blob && off < hf->root->dir_blob_bytes) memcpy(hf->root->dir_blob + off, src, hf->bps);
            /* Resync host FS from updated directory blob */
            extern void reconcile_directory(hostfat_t *hf, hostfat_entry_t *dir);
            reconcile_directory(hf, hf->root);
            return 0;
        }
    }
    /* Data region writes */
    uint32_t data_rel = rel - hf->data_start;
    if (hf->fat_type == 16) data_rel = rel - (hf->reserved + hf->nfats * hf->spf + hf->root_sectors);
    uint32_t cluster_index = data_rel / hf->spc;
    uint32_t sector_in_cluster = data_rel % hf->spc;
    uint32_t cluster_num = 2 + cluster_index;
    if (cluster_num < hf->cluster_count + 2) {
        cluster_map_entry_t *m = &hf->cluster_map[cluster_num];
        if (m->entry) {
            uint32_t off_in_cluster = sector_in_cluster * hf->bps;
            if (m->is_dir) {
                hostfat_entry_t *d = m->entry;
                uint32_t dir_off = m->chunk_index * cluster_bytes(hf) + off_in_cluster;
                if (d->dir_blob && dir_off < d->dir_blob_bytes) memcpy(d->dir_blob + dir_off, src, hf->bps);
                extern void reconcile_directory(hostfat_t *hf, hostfat_entry_t *dir);
                reconcile_directory(hf, d);
            } else {
                FILE *fp = plat_fopen(m->entry->host_path, "rb+");
                if (!fp) fp = plat_fopen(m->entry->host_path, "wb+");
                if (fp) {
                    fseeko64(fp, (off64_t)m->chunk_index * cluster_bytes(hf) + off_in_cluster, SEEK_SET);
                    fwrite(src, 1, hf->bps, fp);
                    fclose(fp);
                }
            }
        }
    }
    return 0;
}

/* --- Directory reconciliation --- */

static void ucs2_to_utf8(const uint16_t *ucs, int n, char *out, int outsz)
{
    int k = 0;
    for (int i = 0; i < n && k < outsz - 1; i++) {
        uint16_t c = ucs[i];
        if (c == 0x0000 || c == 0xFFFF) break;
        if (c < 0x80) out[k++] = (char)c;
        else if (c < 0x800 && k < outsz - 2) { out[k++] = 0xC0 | (c >> 6); out[k++] = 0x80 | (c & 0x3F); }
        else if (k < outsz - 3) { out[k++] = 0xE0 | (c >> 12); out[k++] = 0x80 | ((c >> 6) & 0x3F); out[k++] = 0x80 | (c & 0x3F); }
    }
    out[k] = 0;
}

static void sfn11_to_name(const uint8_t sfn[11], char *out, int outsz)
{
    char name[9], ext[4]; memcpy(name, sfn, 8); name[8]=0; memcpy(ext, sfn+8, 3); ext[3]=0;
    for (int i=7;i>=0;i--){ if (name[i]==' ') name[i]=0; else break; }
    for (int i=2;i>=0;i--){ if (ext[i]==' ') ext[i]=0; else break; }
    if (ext[0]) snprintf(out,outsz,"%s.%s",name,ext); else snprintf(out,outsz,"%s",name);
}

static int ensure_dir_exists(const char *path)
{
    struct stat st; if (stat(path,&st)==0) return S_ISDIR(st.st_mode)?0:-1;
    return plat_dir_create((char*)path);
}

static void remove_recursive(const char *path)
{
    struct stat st; if (stat(path,&st)!=0) return;
    if (S_ISDIR(st.st_mode)) {
        DIR *d = opendir(path); if (!d) return; struct dirent *de; char buf[2048];
        while ((de = readdir(d))) { if (!strcmp(de->d_name,".")||!strcmp(de->d_name,"..")) continue; snprintf(buf,sizeof(buf),"%s/%s",path,de->d_name); remove_recursive(buf);} closedir(d);
        rmdir(path);
    } else remove(path);
}

void reconcile_directory(hostfat_t *hf, hostfat_entry_t *dir)
{
    if (!dir->dir_blob) return;
    /* Map seen SFNs to mark existing */
    for (hostfat_entry_t *c = dir->children; c; c = c->next) c->first_cluster_alloc = 0xFFFFFFFF; /* reuse as seen flag */
    int entry_count = dir->dir_blob_bytes / 32;
    char pending_lfn[260]; pending_lfn[0]=0;
    for (int i = 0; i < entry_count; i++) {
        uint8_t *e = dir->dir_blob + i*32;
        if (e[0] == 0x00) break; /* end */
        if (e[0] == 0xE5) { pending_lfn[0]=0; continue; }
        if (e[11] == 0x0F) {
            /* accumulate */
            /* extract 13 UCS-2 */
            uint16_t u[13]; memset(u,0,sizeof(u));
            for (int j=0;j<5;j++) u[j] = *((uint16_t*)(e+1+j*2));
            for (int j=0;j<6;j++) u[5+j] = *((uint16_t*)(e+14+j*2));
            for (int j=0;j<2;j++) u[11+j]= *((uint16_t*)(e+28+j*2));
            char part[40]; ucs2_to_utf8(u,13,part,sizeof(part));
            /* prepend as we walk backwards, but for simplicity, append and reset on SFN */
            strncat(pending_lfn, part, sizeof(pending_lfn)-strlen(pending_lfn)-1);
            continue;
        }
        /* SFN */
        uint8_t sfn[11]; memcpy(sfn,e,11);
        uint8_t attr = e[11];
        char name_guess[300]; if (pending_lfn[0]) strncpy(name_guess,pending_lfn,sizeof(name_guess)-1), name_guess[sizeof(name_guess)-1]=0; else sfn11_to_name(sfn,name_guess,sizeof(name_guess));
        pending_lfn[0]=0;
        /* find existing by SFN */
        hostfat_entry_t *found = NULL;
        for (hostfat_entry_t *c = dir->children; c; c=c->next) { if (!memcmp(c->name_sfn,sfn,11)) { found = c; break; } }
        char target[2048]; snprintf(target,sizeof(target),"%s%s%s", dir->host_path, path_get_slash(dir->host_path), name_guess);
        if (!found) {
            if (attr & 0x10) { ensure_dir_exists(target); }
            else {
                FILE *fp = plat_fopen(target,"wb+"); if (fp) fclose(fp);
            }
            found = new_entry(dir, name_guess, target, (attr & 0x10) ? 1 : 0);
        } else {
            /* rename if name differs */
            /* compare basename */
            const char *slash = strrchr(found->host_path, '/');
            const char *base = slash ? slash + 1 : found->host_path;
            if (strcmp(base, name_guess)) {
                char newpath[2048]; snprintf(newpath,sizeof(newpath),"%s%s%s", dir->host_path, path_get_slash(dir->host_path), name_guess);
                rename(found->host_path, newpath);
                strncpy(found->host_path, newpath, sizeof(found->host_path)-1);
                strncpy(found->name_lfn, name_guess, sizeof(found->name_lfn)-1);
                memcpy(found->name_sfn, sfn, 11);
            }
        }
        found->first_cluster_alloc = 0; /* mark seen */
        uint32_t fsize = *((uint32_t*)(e+0x1C));
        if (!(attr & 0x10)) {
            struct stat st; if (stat(found->host_path,&st)==0) {
                if ((uint32_t)st.st_size != fsize) {
                    FILE *fp = plat_fopen(found->host_path,"rb+"); if (fp) { fseeko64(fp, fsize, SEEK_SET); int fd = fileno(fp); if (fd>=0) { /* fallback truncate */ } fclose(fp);} }
            }
        }
    }
    /* deletions */
    hostfat_entry_t **pp = &dir->children; hostfat_entry_t *c = dir->children;
    while (c) {
        if (c->first_cluster_alloc == 0xFFFFFFFF) {
            remove_recursive(c->host_path);
            hostfat_entry_t *t = c; *pp = c->next; c = c->next; if (t->dir_blob) free(t->dir_blob); free(t); continue;
        }
        pp = &c->next; c = c->next;
    }
}
