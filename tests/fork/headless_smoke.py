#!/usr/bin/env python3
"""Exercise a built emulator's VNC and TCP-monitor interfaces with disposable state."""
import argparse
import os
from pathlib import Path
import socket
import struct
import subprocess
import tempfile
import time


def exact(stream, size):
    data = bytearray()
    while len(data) < size:
        part = stream.recv(size - len(data))
        if not part:
            raise RuntimeError("VNC connection closed early")
        data.extend(part)
    return bytes(data)


def free_port():
    with socket.socket() as stream:
        stream.bind(("127.0.0.1", 0))
        return stream.getsockname()[1]


def connect(process, port):
    deadline = time.monotonic() + 30
    while time.monotonic() < deadline:
        if process.poll() is not None:
            raise RuntimeError(f"Emulator exited with {process.returncode}")
        try:
            stream = socket.create_connection(("127.0.0.1", port), timeout=0.25)
            stream.settimeout(10)
            return stream
        except OSError:
            time.sleep(0.1)
    raise RuntimeError(f"No listener on port {port}")


def command(stream, text):
    stream.sendall(text.encode() + b"\n")
    response = bytearray()
    while not response.endswith(b"\n"):
        part = stream.recv(4096)
        if not part:
            raise RuntimeError(f"Monitor closed during {text}")
        response.extend(part)
    return response.decode().strip()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--binary", required=True, type=Path)
    parser.add_argument("--roms", required=True, type=Path)
    parser.add_argument("--qt", action="store_true", help="Enable Qt startup options")
    parser.add_argument("--no-client", action="store_true", help="Quit while waiting for VNC")
    args = parser.parse_args()
    binary, roms = args.binary.resolve(), args.roms.resolve()
    with tempfile.TemporaryDirectory(prefix="86box-headless-") as directory:
        vm = Path(directory)
        (vm / "86box.cfg").write_text(
            "[Machine]\nmachine = ibmpc\ncpu_family = 8088\nmem_size = 64\n"
            "\n[Video]\ngfxcard = cga\n\n[Input devices]\nmouse_type = none\n"
            "\n[General]\nvid_renderer = vnc\n"
            "\n[Floppy and CD-ROM drives]\nfdd_01_type = 35_2hd\n"
        )
        floppy = vm / "test.img"
        floppy.write_bytes(bytes(1440 * 1024))
        vnc_port, monitor_port = free_port(), free_port()
        while monitor_port == vnc_port:
            monitor_port = free_port()
        argv = [str(binary), "-P", str(vm), "-R", str(roms), "--headless",
                "--vnc-port", str(vnc_port), "--monitor-port", str(monitor_port)]
        if args.qt:
            argv.append("--assume_moved_vm")
        env = dict(os.environ, ALSOFT_DRIVERS="null")
        if args.qt:
            env["QT_QPA_PLATFORM"] = "offscreen"
        with (vm / "emulator.log").open("w") as log:
            process = subprocess.Popen(argv, stdout=log, stderr=log, env=env)
            vnc = None
            try:
                with connect(process, monitor_port) as monitor:
                    assert command(monitor, "info status") == "paused"
                    if not args.no_client:
                        vnc = connect(process, vnc_port)
                        assert exact(vnc, 12).startswith(b"RFB 003.")
                        vnc.sendall(b"RFB 003.008\n")
                        count = exact(vnc, 1)[0]
                        assert 1 in exact(vnc, count), "No unauthenticated local test connection"
                        vnc.sendall(b"\1")
                        assert exact(vnc, 4) == bytes(4)
                        vnc.sendall(b"\1")
                        header = exact(vnc, 24)
                        width, height = struct.unpack(">HH", header[:4])
                        name = exact(vnc, int.from_bytes(header[20:24], "big")).decode()
                        assert width > 0 and height > 0
                        print(f"VNC: {width}x{height}, {name}")
                        assert command(monitor, "info status") == "running"
                        assert command(monitor, "stop") == "OK"
                        assert command(monitor, "info status") == "paused"
                        assert command(monitor, f'change floppy0 "{floppy}"') == "OK"
                        assert str(floppy) in command(monitor, "info floppy0")
                        assert command(monitor, "eject floppy0") == "OK"
                        assert command(monitor, "info floppy0") == "floppy0: [empty]"
                        assert command(monitor, "info cdrom0") == "cdrom0: [empty]"
                        assert command(monitor, "cont") == "OK"
                        assert command(monitor, "info status") == "running"
                        assert command(monitor, "sendkey ctrl-alt-delete") == "OK"
                        assert command(monitor, "system_reset") == "OK"
                    assert command(monitor, "quit") == "OK"
                if vnc:
                    vnc.close()
                    vnc = None
                assert process.wait(timeout=10) == 0
                print("PASS: clean shutdown" + (" without a VNC client" if args.no_client else ", VNC and monitor controls"))
            except Exception:
                print((vm / "emulator.log").read_text(errors="replace"))
                raise
            finally:
                if vnc:
                    vnc.close()
                if process.poll() is None:
                    process.kill()
                    process.wait(timeout=5)


if __name__ == "__main__":
    main()
