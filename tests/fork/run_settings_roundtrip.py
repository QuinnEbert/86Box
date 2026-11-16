#!/usr/bin/env python3
"""Run the offscreen settings harness against a completed Ninja Qt build (Unix)."""
import argparse
import os
from pathlib import Path
import shlex
import subprocess
import tempfile


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--build", required=True, type=Path)
    parser.add_argument("--roms", required=True, type=Path)
    args = parser.parse_args()
    repo = Path(__file__).resolve().parents[2]
    build, roms = args.build.resolve(), args.roms.resolve()
    with tempfile.TemporaryDirectory(prefix="86box-settings-") as directory:
        root = Path(directory)
        obj, binary = root / "settings_roundtrip.o", root / "settings_roundtrip"

        def commands(target):
            return subprocess.check_output(["ninja", "-C", str(build), "-t", "commands", target], text=True).splitlines()

        compile_args = shlex.split(commands("src/qt/CMakeFiles/plat.dir/qt_main.cpp.o")[-1])
        compile_args[compile_args.index("-o") + 1] = str(obj)
        compile_args[compile_args.index("-c") + 1] = str(repo / "tests/fork/settings_roundtrip.cpp")
        compile_args[compile_args.index("-MF") + 1] = str(obj) + ".d"
        subprocess.run(compile_args, cwd=build, check=True)
        link_args = shlex.split(commands("86Box")[-1])
        if link_args[:2] != [":", "&&"] or link_args[-2:] != ["&&", ":"]:
            raise RuntimeError("Unrecognized Ninja link rule; use a standard Unix Ninja build")
        link_args = link_args[2:-2]
        link_args[link_args.index("-o") + 1] = str(binary)
        link_args.insert(1, str(obj))
        subprocess.run(link_args, cwd=build, check=True)

        vm = root / "vm"
        vm.mkdir()
        folder, disk = vm / "Shared", vm / "disk.img"
        folder.mkdir()
        disk.write_bytes(bytes(1024 * 1024))
        (vm / "86box.cfg").write_text(f"""[Machine]
machine = ibmpc
cpu_family = 8088
mem_size = 64

[Video]
gfxcard = cga

[Hard disks]
hdd_01_parameters = 63, 16, 64, 0, ide
hdd_01_ide_channel = 0:0
hdd_01_fn = {disk}
hdd_02_parameters = 63, 16, 128, 0, ide
hdd_02_ide_channel = 0:1
hdd_02_fn = {folder}
hdd_02_shared_fake_size_mb = 64
hdd_02_shared_fs = fat16
hdd_02_shared_layout = partitioned
""")
        env = dict(os.environ, QT_QPA_PLATFORM="offscreen", FORK_TEST_FOLDER=str(folder),
                   FORK_TEST_DISK=str(disk), ALSOFT_DRIVERS="null")
        subprocess.run([str(binary), "-P", str(vm), "-R", str(roms), "--settings", "--assume_moved_vm"],
                       cwd=repo, env=env, check=True, timeout=30)


if __name__ == "__main__":
    main()
