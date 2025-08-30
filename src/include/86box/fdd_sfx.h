/* Minimal floppy SFX interface */
#ifndef FDD_SFX_H
#define FDD_SFX_H

#ifdef __cplusplus
extern "C" {
#endif

void fdd_sfx_init(void);
void fdd_sfx_enable(int enabled);
int  fdd_sfx_is_enabled(void);
void fdd_sfx_motor(int drive, int on);
void fdd_sfx_step(int drive);
void fdd_sfx_insert(int drive);
void fdd_sfx_eject(int drive);

#ifdef __cplusplus
}
#endif

#endif /* FDD_SFX_H */

