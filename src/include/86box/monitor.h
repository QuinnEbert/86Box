/*
 * 86Box    A hypervisor and IBM PC system emulator that specializes in
 *          running old operating systems and software designed for IBM
 *          PC systems and compatibles from 1981 through fairly recent
 *          system designs based on the PCI bus.
 *
 *          This file is part of the 86Box distribution.
 *
 *          Definitions for the TCP monitor server.
 *
 * Authors: Based on gdbstub.h by RichardG
 *
 *          Copyright 2024.
 */
#ifndef EMU_MONITOR_H
#define EMU_MONITOR_H

extern int monitor_port;

extern void monitor_init(void);
extern void monitor_close(void);

#endif
