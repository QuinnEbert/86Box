# 86Box Recent History

This README highlights the most impactful recent work in the repository. While many commits revolve around tooling, the following fifteen improvements directly enhance the emulator's usability and performance.

## Recent Highlights

1. **Add turbo mode (#7)** - Temporarily speeds up emulation when you need an extra boost.
2. **Show supported CPU types in machine list (#16)** - Clearly lists which CPUs each machine can emulate.
3. **Refine typical CPU label (#6)** - Labels CPUs to match real-world usage more accurately.
4. **Enable console output on Windows and log missing ROMs (#5)** - Troubleshooting info now appears right in the console.
5. **Show missing ROM file names in hardware unavailable message (#4)** - Instantly identifies which ROMs are missing.
6. **Improve ROM not found message (#2)** - Provides clearer guidance when required ROMs aren't located.
7. **Tandy scanline fix (#5689)** - Corrects the final scanline in double-scanned 40-column text mode.
8. **(S)VGA overscan compensation (#5688)** - Improves screen rendering accuracy on VGA hardware.
9. **Modularize video card components** - Splits external RAMDACs and clock generators into dedicated folders for cleaner organization.
10. **Introduce `mda_colors` enum** - Replaces magic numbers in the monochrome color fixup code.
11. **Simplify `mda_poll` logic** - Reduces variable scope and converts drawcursor to a boolean.
12. **Gray palette corrections** - Ensures gray shades appear as intended.
13. **9th column support fixes** - Cleans up code and handles gray/black background cases correctly.
14. **Add MDA color support** - Brings limited color capability to monochrome displays.
15. **Mach64 cleanup and performance tweaks** - Improves the Mach64 driver for smoother video output.

These updates collectively make the emulator faster, more stable, and easier to use.
