# Upstream integration, 16 November 2026

The initial integration merges upstream `7437a4a66` into fork `4a4015245`,
preserving both histories. It also includes the subsequent upstream commits
`2705f94f4` and `6511eade0` (memory-viewer strings and file-dialog filters),
fetched on 16 November. The original local branch is
`backup/pre-upstream-20261116`; development takes place on
`integrate/upstream-20261116` until platform validation finishes.

## Fork features retained

| Feature | Main implementation | Integration work |
| --- | --- | --- |
| Turbo, cycle skip, and configurable turbo batches | `src/runctl.c`, Qt Actions menu | Restore the execution paths lost in an older merge; use current run-control safe points and speed measurement. |
| Virtualized CPU/cache mode | `src/cpu/386_dynarec.c`, `cpu.c` | Port onto current recompiler interfaces; keep the existing macOS exclusion and apply changes on the CPU thread. |
| QUINNEHD disk preset | `src/disk/hdd.c` | Restore the named preset and zero-RPM timing bypass lost in an older merge. |
| Host-folder disks, filesystem/layout selection, capacity, and reported model | `hostfat.c`, disk image layer, IDE/SCSI, Qt Shared folders | Preserve directory-backed disks alongside current removable-media I/O and custom drive identification. Keep settings edits local until saving; save regular disks and shared folders independently. |
| Floppy sounds and bundled WAV assets | `fdd_sfx.c`, floppy and sound core, Qt settings | Reconnect motor/seek/mixer hooks; re-register after reset; accommodate all eight upstream drives. |
| Function-key injection and Input menu | Qt main window | Retain F1–F12 scancode injection. |
| CPU/RAM, hardware, storage, and attachment status summaries | Qt machine status | Keep custom summaries alongside upstream's recompiler indicator; use the new floppy structures. |
| Machine search and CPU-family summaries | Qt machine settings and machine table | Retain search with stable machine IDs; restore CPU summary labels using the fork's existing helpers. |
| Missing-ROM diagnostics and automatic ROM download | device layer and Qt startup | Preserve diagnostics while retaining upstream's optional-ROM semantics. |
| Headless VNC, custom port/password, modifier handling | VNC renderer and SDL/Qt startup | Integrate current pause ownership, renderer initialization, offscreen Qt startup, and clean exit. |
| Localhost TCP monitor | `src/monitor.c` | Preserve reset, quit, pause/resume, Ctrl-Alt-Delete, and floppy/CD mount/eject/query commands. Execute commands at CPU safe points and start the listener after machine initialization. |
| macOS packaging/universal-build helper and fork autobuilds | CMake, `scripts/macos`, Actions | Retain assets and bundling; update dependencies and checks for current upstream. |

Upstream's current 64-bit recompiler replaces the old ODR/NDR matrix. The
workflow covers Linux x86_64/arm64 with SDL and Qt, macOS arm64 with SDL and
Qt, and Windows x86_64/arm64 with Qt. Every configuration has Debug and Dev
builds. Windows keeps Qt 5 compatibility; Linux and macOS use Qt 6. Linux
currently uses SDL 2 while macOS and Windows use SDL 3. macOS uses the supported
`macos-15` Apple Silicon pool and checks its actual architecture. macOS 26 was
also tried but jobs remained queued without receiving runners. All four macOS
configurations share one job and dependency installation to avoid repeated
runner allocation delays.

Release publication requires all platform jobs to succeed and is restricted
to master/tag runs. Integration-branch pushes produce artifacts without
publishing releases.

## Validation

- Both macOS arm64 frontends compile locally.
- The focused suite passes 25 tests: disk image preservation/extension,
  real host-folder sector reads and writes, actual bundled floppy samples,
  sound disable/reset, eighth-drive handling, CPU block accounting,
  recompiler reuse thresholds, INI handling, random state, and memory rows.
- Actions runs the focused suite in the Linux x86_64 SDL Debug job.
- Real SDL and Qt headless sessions complete the VNC handshake and exercise
  monitor status, pause/resume, media queries, Ctrl-Alt-Delete, hard reset,
  and clean shutdown. Startup and quit without a VNC client are checked too.
  SDL retains the fork's unattended startup (runs without a client); Qt retains
  its initial wait for a VNC client.
- Local SDL and Qt installation creates bundles with copied dependencies;
  bundles are ad-hoc signed and checked separately from compilation.
- The offscreen settings harness checks independent regular/shared disk pages,
  deferred edits, repeated saves, and INI reload of capacity and model overrides.
- The macOS job smoke-tests each signed, installed app and runs the settings
  harness against its Qt Dev build.
- `actionlint` validates the workflow.

The broad upstream test build currently stops in the unchanged
`tests/cdrom/cdrom_burn_drive_test.cpp`, which refers to the removed
`cdrom_t::is_yamaha` field. That suite is not used as a passing validation
claim. Native UI automation could not start on this workstation; native
visual checks and a comprehensive guest-OS compatibility matrix remain
outside the automated evidence above. The host-folder regression exercises
FAT16 reads/writes, not every filesystem operation or FAT12/FAT32 variant.

For future upstream merges, compare the result against upstream as well as
the old fork: earlier merges left stale infrastructure and disconnected UI
controls that did not produce textual conflicts. Do not resolve all conflicts
with an ours/theirs strategy.
