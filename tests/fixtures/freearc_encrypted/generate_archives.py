#!/usr/bin/env python3
"""Independent small FreeArc containers, using hashlib/PyCryptodome ciphers.

Run --check to verify checked-in fixtures. No xxfclib code or user files are
invoked/read. Container layout follows pinned upstream FreeArc Archive.hs;
the cipher generator records primary protocol sources and independent CTR
cross-checks. Native tests need only the checked-in .arc files.
"""
import argparse
from pathlib import Path
import struct
import zlib
from generate_cipher_vectors import vector

ROOT = Path(__file__).parent
PASSWORD = "FreeArc-fixture-password"
FILES = [("first.txt", b"FreeArc encrypted first member.\n" * 3),
         ("second.bin", bytes(range(256)) + b"\x00\xfftail")]


def num(value):
    for extra in range(8):
        if value < 1 << (7 * (extra + 1)):
            return ((value << (extra + 1)) | ((1 << extra) - 1)).to_bytes(extra + 1, "little")
    return b"\xff" + struct.pack("<Q", value)


def text(value):
    return value.encode("utf-8") + b"\0"


def crc(data):
    return struct.pack("<I", zlib.crc32(data))


def descriptor(kind, method, plain, packed):
    head = b"ArC\1" + num(kind) + text(method) + num(len(plain)) + num(len(packed)) + crc(plain)
    return head + crc(head)


def encrypt(data, fixed, tag, enabled=True):
    if not enabled:
        return "storing", data
    # Every control/data block gets a distinct deterministic test salt/IV.
    answer = vector("container", password=PASSWORD, fixed=fixed,
                    salt=bytes((i + tag) & 255 for i in range(32)),
                    iv=bytes((i * 13 + tag) & 255 for i in range(16)),
                    data=data, lzma_chain=True)
    return answer["chain_method"], bytes.fromhex(answer["ciphertext_hex"])


def archive(fixed=False, metadata=True, members=True):
    header = b"ArC\1\0\0\6\7"
    out = bytearray(header + descriptor(1, "storing", header, header))
    payload = b"".join(data for name, data in FILES)
    member_at = len(out)
    member_method, member_packed = encrypt(payload, fixed, 17, members)
    out += member_packed
    directory_at = len(out)
    directory = (num(1) + num(len(FILES)) + text(member_method)
                 + num(directory_at - member_at) + num(len(member_packed))
                 + num(1) + text("")
                 + b"".join(text(name) for name, data in FILES)
                 + num(0) * len(FILES)
                 + b"".join(num(len(data)) for name, data in FILES)
                 + struct.pack("<I", 1700000000) * len(FILES)
                 + b"\0" * len(FILES)
                 + b"".join(crc(data) for name, data in FILES))
    directory_method, directory_packed = encrypt(directory, fixed, 43, metadata)
    out += directory_packed + descriptor(3, directory_method, directory, directory_packed)
    footer_at = len(out)
    footer = (num(1) + num(3) + text(directory_method)
              + num(footer_at - directory_at) + num(len(directory))
              + num(len(directory_packed)) + crc(directory) + b"\0\0")
    footer_method, footer_packed = encrypt(footer, fixed, 71, metadata)
    out += footer_packed + descriptor(4, footer_method, footer, footer_packed)
    return bytes(out)


def build():
    return {
        "legacy_headers_and_members.arc": archive(),
        "fixed_headers_and_members.arc": archive(fixed=True),
        "legacy_members_only.arc": archive(metadata=False),
        "plain.arc": archive(metadata=False, members=False),
    }


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--check", action="store_true")
    args = p.parse_args()
    for name, data in build().items():
        path = ROOT / name
        if args.check:
            assert path.read_bytes() == data, name
        else:
            path.write_bytes(data)
        print(("Verified" if args.check else "Wrote"), name, len(data))


if __name__ == "__main__":
    main()
