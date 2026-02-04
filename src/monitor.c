/*
 * 86Box    A hypervisor and IBM PC system emulator that specializes in
 *          running old operating systems and software designed for IBM
 *          PC systems and compatibles from 1981 through fairly recent
 *          system designs based on the PCI bus.
 *
 *          This file is part of the 86Box distribution.
 *
 *          TCP monitor server for remote control (similar to QEMU monitor).
 *
 * Authors: Based on gdbstub.c by RichardG
 *
 *          Copyright 2024.
 */
#include <inttypes.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#    ifndef __clang__
#        include <unistd.h>
#    else
#        include <io.h>
#        define ssize_t long
#    endif
#    include <winsock2.h>
#    include <ws2tcpip.h>
#else
#    include <unistd.h>
#    include <arpa/inet.h>
#    include <sys/socket.h>
#    include <errno.h>
#endif
#define HAVE_STDARG_H
#include <86box/86box.h>
#include <86box/plat.h>
#include <86box/thread.h>
#include <86box/monitor.h>
#include <86box/timer.h>
#include <86box/fdd.h>
#include <86box/cdrom.h>

#ifdef ENABLE_MONITOR_LOG
int monitor_do_log = ENABLE_MONITOR_LOG;

static void
monitor_log(const char *fmt, ...)
{
    va_list ap;

    if (monitor_do_log) {
        va_start(ap, fmt);
        pclog_ex(fmt, ap);
        va_end(ap);
    }
}
#else
#    define monitor_log(fmt, ...)
#endif

/* External declarations for emulator control */
extern void pc_reset_hard(void);
extern void pc_send_cad(void);
extern void do_pause(int p);
extern volatile int is_quit;
extern int dopause;

int monitor_port = 0;

static int monitor_socket = -1;
static thread_t *monitor_thread = NULL;

/* Process a single command and return response */
static void
monitor_process_command(int client_socket, char *cmd)
{
    char response[1280];
    char *p;

    /* Trim trailing whitespace/newlines */
    p = cmd + strlen(cmd) - 1;
    while (p >= cmd && (*p == '\n' || *p == '\r' || *p == ' '))
        *p-- = '\0';

    /* Trim leading whitespace */
    while (*cmd == ' ')
        cmd++;

    monitor_log("Monitor: Received command: '%s'\n", cmd);

    if (strlen(cmd) == 0) {
        /* Empty command, just send OK */
        strcpy(response, "OK\n");
    } else if (!strcasecmp(cmd, "system_reset")) {
        /* Hard reset the VM */
        pc_reset_hard();
        strcpy(response, "OK\n");
    } else if (!strcasecmp(cmd, "quit")) {
        /* Force quit */
        is_quit = 1;
        strcpy(response, "OK\n");
    } else if (!strcasecmp(cmd, "stop")) {
        /* Pause emulation */
        do_pause(1);
        strcpy(response, "OK\n");
    } else if (!strcasecmp(cmd, "cont")) {
        /* Resume emulation */
        do_pause(0);
        strcpy(response, "OK\n");
    } else if (!strcasecmp(cmd, "info status")) {
        /* Return running/paused status */
        if (dopause)
            strcpy(response, "paused\n");
        else
            strcpy(response, "running\n");
    } else if (!strcasecmp(cmd, "sendkey ctrl-alt-delete") ||
               !strcasecmp(cmd, "sendkey ctrl-alt-del")) {
        /* Send Ctrl+Alt+Delete */
        pc_send_cad();
        strcpy(response, "OK\n");
    } else if (!strncasecmp(cmd, "change floppy", 13)) {
        /* Mount/swap floppy image: change floppy<N> "<path>" */
        int drive = -1;
        char path[1024] = {0};
        if (sscanf(cmd + 13, "%d", &drive) == 1 && drive >= 0 && drive < FDD_NUM) {
            /* Find the path argument (after drive number, in quotes) */
            char *quote_start = strchr(cmd, '"');
            char *quote_end = quote_start ? strrchr(cmd, '"') : NULL;
            if (quote_start && quote_end && quote_end > quote_start) {
                size_t path_len = quote_end - quote_start - 1;
                if (path_len > 0 && path_len < sizeof(path)) {
                    strncpy(path, quote_start + 1, path_len);
                    path[path_len] = '\0';
                    /* Check if file exists */
                    FILE *f = fopen(path, "rb");
                    if (f) {
                        fclose(f);
                        fdd_load(drive, path);
                        strcpy(response, "OK\n");
                    } else {
                        snprintf(response, sizeof(response), "ERROR: File not found '%s'\n", path);
                    }
                } else {
                    strcpy(response, "ERROR: Empty path\n");
                }
            } else {
                strcpy(response, "ERROR: Path must be quoted\n");
            }
        } else {
            snprintf(response, sizeof(response), "ERROR: Invalid floppy drive number\n");
        }
    } else if (!strncasecmp(cmd, "eject floppy", 12)) {
        /* Eject floppy drive: eject floppy<N> */
        int drive = -1;
        if (sscanf(cmd + 12, "%d", &drive) == 1 && drive >= 0 && drive < FDD_NUM) {
            fdd_close(drive);
            strcpy(response, "OK\n");
        } else {
            snprintf(response, sizeof(response), "ERROR: Invalid floppy drive number\n");
        }
    } else if (!strncasecmp(cmd, "change cdrom", 12)) {
        /* Mount/swap CD-ROM image: change cdrom<N> "<path>" */
        int id = -1;
        char path[1024] = {0};
        if (sscanf(cmd + 12, "%d", &id) == 1 && id >= 0 && id < CDROM_NUM) {
            char *quote_start = strchr(cmd, '"');
            char *quote_end = quote_start ? strrchr(cmd, '"') : NULL;
            if (quote_start && quote_end && quote_end > quote_start) {
                size_t path_len = quote_end - quote_start - 1;
                if (path_len > 0 && path_len < sizeof(path)) {
                    strncpy(path, quote_start + 1, path_len);
                    path[path_len] = '\0';
                    FILE *f = fopen(path, "rb");
                    if (f) {
                        fclose(f);
                        cdrom_load(&cdrom[id], path, 0);
                        strcpy(response, "OK\n");
                    } else {
                        snprintf(response, sizeof(response), "ERROR: File not found '%s'\n", path);
                    }
                } else {
                    strcpy(response, "ERROR: Empty path\n");
                }
            } else {
                strcpy(response, "ERROR: Path must be quoted\n");
            }
        } else {
            snprintf(response, sizeof(response), "ERROR: Invalid CD-ROM drive number\n");
        }
    } else if (!strncasecmp(cmd, "eject cdrom", 11)) {
        /* Eject CD-ROM drive: eject cdrom<N> */
        int id = -1;
        if (sscanf(cmd + 11, "%d", &id) == 1 && id >= 0 && id < CDROM_NUM) {
            cdrom_eject(id);
            strcpy(response, "OK\n");
        } else {
            snprintf(response, sizeof(response), "ERROR: Invalid CD-ROM drive number\n");
        }
    } else if (!strncasecmp(cmd, "info floppy", 11)) {
        /* Query floppy status: info floppy<N> */
        int drive = -1;
        if (sscanf(cmd + 11, "%d", &drive) == 1 && drive >= 0 && drive < FDD_NUM) {
            if (drive_empty[drive] || strlen(floppyfns[drive]) == 0) {
                snprintf(response, sizeof(response), "floppy%d: [empty]\n", drive);
            } else {
                snprintf(response, sizeof(response), "floppy%d: %s\n", drive, floppyfns[drive]);
            }
        } else {
            snprintf(response, sizeof(response), "ERROR: Invalid floppy drive number\n");
        }
    } else if (!strncasecmp(cmd, "info cdrom", 10)) {
        /* Query CD-ROM status: info cdrom<N> */
        int id = -1;
        if (sscanf(cmd + 10, "%d", &id) == 1 && id >= 0 && id < CDROM_NUM) {
            if (cdrom_is_empty(id) || strlen(cdrom[id].image_path) == 0) {
                snprintf(response, sizeof(response), "cdrom%d: [empty]\n", id);
            } else {
                snprintf(response, sizeof(response), "cdrom%d: %s\n", id, cdrom[id].image_path);
            }
        } else {
            snprintf(response, sizeof(response), "ERROR: Invalid CD-ROM drive number\n");
        }
    } else {
        /* Unknown command */
        snprintf(response, sizeof(response), "ERROR: Unknown command '%s'\n", cmd);
    }

    send(client_socket, response, strlen(response), 0);
}

/* Client handler thread */
static void
monitor_client_thread(void *priv)
{
    int client_socket = (int)(intptr_t)priv;
    char buf[1024];
    char cmd[1024];
    int cmd_pos = 0;
    ssize_t bytes_read;

    monitor_log("Monitor: Client connected\n");

    /* Read data from client */
    while ((bytes_read = recv(client_socket, buf, sizeof(buf) - 1, 0)) > 0) {
        buf[bytes_read] = '\0';

        /* Process each character */
        for (ssize_t i = 0; i < bytes_read; i++) {
            if (buf[i] == '\n' || buf[i] == '\r') {
                if (cmd_pos > 0) {
                    cmd[cmd_pos] = '\0';
                    monitor_process_command(client_socket, cmd);
                    cmd_pos = 0;
                }
            } else if (cmd_pos < (int)(sizeof(cmd) - 1)) {
                cmd[cmd_pos++] = buf[i];
            }
        }
    }

    monitor_log("Monitor: Client disconnected\n");

    close(client_socket);
}

/* Server thread */
static void
monitor_server_thread(void *priv)
{
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_socket;

    /* Listen on socket */
    listen(monitor_socket, 5);

    monitor_log("Monitor: Server thread started, listening on port %d\n", monitor_port);

    /* Accept connections */
    while (monitor_socket != -1) {
        client_socket = accept(monitor_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            if (monitor_socket == -1)
                break;  /* Socket was closed */
            monitor_log("Monitor: accept() failed\n");
            continue;
        }

        monitor_log("Monitor: New connection from %s:%d\n",
                   inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        /* Handle client in a new thread */
        thread_create(monitor_client_thread, (void *)(intptr_t)client_socket);
    }
}

void
monitor_init(void)
{
    struct sockaddr_in bind_addr;
    int yes = 1;

    /* Check if monitor is enabled */
    if (monitor_port <= 0) {
        monitor_log("Monitor: Disabled (port not set)\n");
        return;
    }

#ifdef _WIN32
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
#endif

    /* Create server socket */
    monitor_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (monitor_socket == -1) {
        pclog("Monitor: Failed to create socket\n");
        return;
    }

    /* Set socket options */
    if (setsockopt(monitor_socket, SOL_SOCKET, SO_REUSEADDR,
#ifdef _WIN32
                   (const char *)&yes,
#else
                   &yes,
#endif
                   sizeof(yes)) == -1) {
        pclog("Monitor: setsockopt SO_REUSEADDR failed\n");
        close(monitor_socket);
        monitor_socket = -1;
        return;
    }

#ifdef _WIN32
    if (setsockopt(monitor_socket, SOL_SOCKET, SO_EXCLUSIVEADDRUSE,
                   (const char *)&yes, sizeof(yes)) == -1) {
        pclog("Monitor: setsockopt SO_EXCLUSIVEADDRUSE failed\n");
    }
#endif

    /* Bind socket */
    memset(&bind_addr, 0, sizeof(bind_addr));
    bind_addr.sin_family = AF_INET;
    bind_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);  /* Only localhost */
    bind_addr.sin_port = htons(monitor_port);

    if (bind(monitor_socket, (struct sockaddr *)&bind_addr, sizeof(bind_addr)) == -1) {
        pclog("Monitor: Failed to bind on port %d (%d)\n", monitor_port,
#ifdef _WIN32
              WSAGetLastError()
#else
              errno
#endif
        );
        close(monitor_socket);
        monitor_socket = -1;
        return;
    }

    /* Start server thread */
    pclog("Monitor: Listening on port %d\n", monitor_port);
    monitor_thread = thread_create(monitor_server_thread, NULL);
}

void
monitor_close(void)
{
    int sock;

    if (monitor_socket < 0)
        return;

    monitor_log("Monitor: Closing\n");

    /* Close the server socket to stop accepting new connections */
    sock = monitor_socket;
    monitor_socket = -1;
    close(sock);
}
