/*
 * Floppy drive sound effects: simple PCM mixer using WAV assets in floppysounds/
 */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include <86box/86box.h>
#include <86box/plat_unused.h>
#include <86box/timer.h>
#include <86box/fdd.h>
#include <86box/sound.h>
#include <86box/fdd_sfx.h>

#define MAX_VOICES 16
#define MAX_DRIVES 4

typedef struct sample_t {
    int16_t *data;
    int      length;      /* frames (mono) */
    int      rate;        /* Hz */
} sample_t;

typedef struct voice_t {
    const sample_t *smp;
    int             loop;
    float           gain;      /* linear 0..1 */
    uint32_t        pos_fp;    /* 16.16 fixed */
    uint32_t        inc_fp;    /* increment per output sample */
    int             active;
} voice_t;

static int      s_enabled = 1;
static int      s_inited  = 0;
static voice_t  s_voices[MAX_VOICES];
static int      s_motor_active[MAX_DRIVES];

/* Loaded samples */
static sample_t s_spinup;
static sample_t s_spinloop;
static sample_t s_spindown;
static sample_t s_step;
static sample_t s_insert;
static sample_t s_eject;
static sample_t s_tick;

static int      s_tick_period[MAX_DRIVES];     /* in output samples */
static int      s_tick_countdown[MAX_DRIVES];  /* in output samples */

/* Very small WAV PCM16 mono loader */
static int load_wav_mono16(const char *path, sample_t *out)
{
    FILE *f = fopen(path, "rb");
    if (!f) return 0;
    uint8_t hdr[44];
    if (fread(hdr, 1, 44, f) != 44) { fclose(f); return 0; }
    if (memcmp(hdr, "RIFF", 4) || memcmp(hdr+8, "WAVE", 4)) { fclose(f); return 0; }
    /* naive parse: assume fmt chunk at 12, data at 36 */
    uint16_t audfmt = hdr[20] | (hdr[21] << 8);
    uint16_t chans  = hdr[22] | (hdr[23] << 8);
    uint32_t rate   = hdr[24] | (hdr[25] << 8) | (hdr[26] << 16) | (hdr[27] << 24);
    uint16_t bps    = hdr[34] | (hdr[35] << 8);
    uint32_t datasz = hdr[40] | (hdr[41] << 8) | (hdr[42] << 16) | (hdr[43] << 24);
    if (audfmt != 1 || chans != 1 || bps != 16 || datasz == 0) { fclose(f); return 0; }
    int frames = datasz / 2;
    int16_t *buf = (int16_t*)malloc(datasz);
    if (!buf) { fclose(f); return 0; }
    if (fread(buf, 1, datasz, f) != datasz) { free(buf); fclose(f); return 0; }
    fclose(f);
    out->data   = buf;
    out->length = frames;
    out->rate   = (int)rate;
    return 1;
}

static void free_sample(sample_t *s) { if (s->data) { free(s->data); s->data = NULL; } }

static int try_load_variant(const char *variant, const char *stem, sample_t *dst)
{
    char path[512];
    const char *candidates[] = {
        /* current working directory */
        "floppysounds/%s_%s.wav",
        /* macOS bundle Resources when CWD is MacOS/ */
        "../Resources/floppysounds/%s_%s.wav",
        /* Resources from CWD */
        "Resources/floppysounds/%s_%s.wav",
        /* parent floppysounds (if running from bin/) */
        "../floppysounds/%s_%s.wav",
    };
    for (size_t i = 0; i < sizeof(candidates)/sizeof(candidates[0]); i++) {
        snprintf(path, sizeof(path), candidates[i], stem, variant);
        if (load_wav_mono16(path, dst)) return 1;
    }
    return 0;
}

static void sfx_load_assets(void)
{
    /* prefer A500Real, then A500, then ST, then LOUD */
    const char *variants[] = { "A500Real", "A500", "ST", "LOUD" };
    const int   nvar = 4;
    const char *spinup_stem   = "drive_startup";
    const char *spinloop_stem = "drive_spin";
    const char *spindown_stem = "drive_spind"; /* some packs use this naming */
    const char *step_stem     = "drive_snatch";
    const char *insert_stem   = "drive_insert";
    const char *eject_stem    = "drive_eject";
    const char *tick_stem     = "drive_click"; /* index tick */

    for (int i = 0; i < nvar && !s_spinup.data; i++)   try_load_variant(variants[i], spinup_stem, &s_spinup);
    for (int i = 0; i < nvar && !s_spinloop.data; i++) try_load_variant(variants[i], spinloop_stem, &s_spinloop);
    for (int i = 0; i < nvar && !s_spindown.data; i++) try_load_variant(variants[i], spindown_stem, &s_spindown);
    for (int i = 0; i < nvar && !s_step.data; i++)     try_load_variant(variants[i], step_stem, &s_step);
    for (int i = 0; i < nvar && !s_insert.data; i++)   try_load_variant(variants[i], insert_stem, &s_insert);
    for (int i = 0; i < nvar && !s_eject.data; i++)    try_load_variant(variants[i], eject_stem, &s_eject);
    for (int i = 0; i < nvar && !s_tick.data; i++)     try_load_variant(variants[i], tick_stem, &s_tick);
}

static void voice_start(const sample_t *smp, int loop, float gain)
{
    if (!smp || !smp->data || smp->length <= 0) return;
    for (int i = 0; i < MAX_VOICES; i++) {
        if (!s_voices[i].active) {
            s_voices[i].smp    = smp;
            s_voices[i].loop   = loop;
            s_voices[i].gain   = gain;
            s_voices[i].pos_fp = 0;
            /* fixed-point increment to convert sample rate to SOUND_FREQ */
            double inc = (double)smp->rate / (double)SOUND_FREQ;
            s_voices[i].inc_fp = (uint32_t)lrint(inc * 65536.0);
            if (s_voices[i].inc_fp == 0) s_voices[i].inc_fp = 1;
            s_voices[i].active = 1;
            return;
        }
    }
}

static void voice_stop_loop_of(const sample_t *smp)
{
    for (int i = 0; i < MAX_VOICES; i++)
        if (s_voices[i].active && s_voices[i].smp == smp && s_voices[i].loop)
            s_voices[i].active = 0;
}

static void fdd_sfx_get_buffer(int32_t *buffer, int len, void *priv)
{
    if (!s_enabled || !s_inited) return;
    /* index tick scheduling per drive */
    for (int d = 0; d < MAX_DRIVES; d++) {
        if (s_motor_active[d] && s_tick.data && s_tick.length > 0 && s_tick_period[d] > 0) {
            int remain = s_tick_countdown[d] - len;
            while (remain <= 0) {
                voice_start(&s_tick, 0, 0.5f);
                remain += s_tick_period[d];
            }
            s_tick_countdown[d] = remain;
        }
    }
    for (int i = 0; i < len; i++) {
        int32_t mix = 0;
        for (int v = 0; v < MAX_VOICES; v++) {
            voice_t *vc = &s_voices[v];
            if (!vc->active) continue;
            const sample_t *sm = vc->smp;
            uint32_t idx = vc->pos_fp >> 16;
            if (idx >= (uint32_t)sm->length) {
                if (vc->loop) {
                    vc->pos_fp %= (sm->length << 16);
                    idx = vc->pos_fp >> 16;
                } else {
                    vc->active = 0;
                    continue;
                }
            }
            int32_t s = sm->data[idx];
            mix += (int32_t)(s * vc->gain);
            vc->pos_fp += vc->inc_fp;
        }
        /* stereo: duplicate to both */
        buffer[(i<<1)+0] += mix;
        buffer[(i<<1)+1] += mix;
    }
}

void fdd_sfx_init(void)
{
    if (s_inited) return;
    memset(s_voices, 0, sizeof(s_voices));
    memset(s_motor_active, 0, sizeof(s_motor_active));
    sfx_load_assets();
    sound_add_handler(fdd_sfx_get_buffer, NULL);
    s_inited = 1;
}

void fdd_sfx_enable(int enabled)
{
    s_enabled = enabled ? 1 : 0;
}

int fdd_sfx_is_enabled(void) { return s_enabled; }

void fdd_sfx_motor(int drive, int on)
{
    (void)drive;
    if (!s_inited || !s_enabled) return;
    if (on) {
        if (!s_motor_active[drive]) {
            if (s_spinup.data)
                voice_start(&s_spinup, 0, 0.8f);
            if (s_spinloop.data)
                voice_start(&s_spinloop, 1, 0.35f);
            s_motor_active[drive] = 1;
            /* setup index tick period from current RPM */
            if (s_tick.data && s_tick.length > 0) {
                int rpm = fdd_getrpm(drive);
                if (rpm <= 0) rpm = 300;
                double period_sec = 60.0 / (double)rpm;
                int period_samples = (int)(period_sec * (double)SOUND_FREQ + 0.5);
                if (period_samples < 1) period_samples = SOUND_FREQ / 5; /* sane default */
                s_tick_period[drive]    = period_samples;
                s_tick_countdown[drive] = period_samples;
            } else {
                s_tick_period[drive] = s_tick_countdown[drive] = 0;
            }
        }
    } else {
        if (s_motor_active[drive]) {
            voice_stop_loop_of(&s_spinloop);
            if (s_spindown.data)
                voice_start(&s_spindown, 0, 0.8f);
            s_motor_active[drive] = 0;
            s_tick_period[drive] = s_tick_countdown[drive] = 0;
        }
    }
}

void fdd_sfx_step(int drive)
{
    (void)drive;
    if (!s_inited || !s_enabled) return;
    if (s_step.data)
        voice_start(&s_step, 0, 0.9f);
}

void fdd_sfx_insert(int drive)
{
    (void)drive;
    if (!s_inited || !s_enabled) return;
    if (s_insert.data)
        voice_start(&s_insert, 0, 0.9f);
}

void fdd_sfx_eject(int drive)
{
    (void)drive;
    if (!s_inited || !s_enabled) return;
    if (s_eject.data)
        voice_start(&s_eject, 0, 0.9f);
}
