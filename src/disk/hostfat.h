#ifndef HOSTFAT_H
#define HOSTFAT_H

#include <stdint.h>
#include <stdio.h>

typedef struct hard_disk_t hard_disk_t;

typedef struct hostfat hostfat_t;

int  hostfat_mount(hard_disk_t *hd, hostfat_t **out);
void hostfat_unmount(hostfat_t *hf);

/* Logical block address is absolute from LBA 0 (MBR). */
int  hostfat_read_sector(hostfat_t *hf, uint32_t lba, uint8_t *dst512);
int  hostfat_write_sector(hostfat_t *hf, uint32_t lba, const uint8_t *src512);

/* Helpers to expose disk size in sectors */
uint32_t hostfat_last_sector(const hostfat_t *hf); /* absolute last LBA */

#endif /* HOSTFAT_H */

