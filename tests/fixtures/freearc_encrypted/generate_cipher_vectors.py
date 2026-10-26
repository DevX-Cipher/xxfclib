#!/usr/bin/env python3
"""Generate independent FreeArc AES-CTR known answers.

Requires PyCryptodome. PBKDF2 comes from Python's hashlib; AES comes from
PyCryptodome. Manual ECB/counter encryption is independently checked against
PyCryptodome's CTR implementation before a vector is emitted. This generator
does not import, compile, or invoke xxfclib.

These are cipher/method-chain vectors, not complete archive containers.
Run with --check to compare the checked-in JSON without modifying it.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import lzma
from pathlib import Path

from Crypto.Cipher import AES
from Crypto.Util import Counter


COMMIT = "71f3ab36df26401fff4301b4c8600a31a90d8da9"
UPSTREAM = f"https://github.com/mirror/freearc/blob/{COMMIT}/"


def legacy_hex_decode(hex_string: str) -> bytes:
    """Upstream buggy_char2int omits +10 for a..f, for key and IV only."""
    def digit(char: str) -> int:
        return int(char) if char.isdigit() else ord(char.lower()) - ord("a")

    return bytes(
        16 * digit(hex_string[pos]) + digit(hex_string[pos + 1])
        for pos in range(0, len(hex_string), 2)
    )


def ctr_crypt(key: bytes, iv: bytes, data: bytes) -> tuple[bytes, list[str]]:
    """First counter is IV; carry propagates from byte 0 through byte 15."""
    aes = AES.new(key, AES.MODE_ECB)
    initial = int.from_bytes(iv, "little")
    output = bytearray()
    counter_blocks = []
    for offset in range(0, len(data), 16):
        count = (initial + offset // 16) % (1 << 128)
        counter = count.to_bytes(16, "little")
        counter_blocks.append(counter.hex())
        block = data[offset:offset + 16]
        output.extend(a ^ b for a, b in zip(block, aes.encrypt(counter)))

    independent_counter = Counter.new(128, initial_value=initial, little_endian=True)
    independent = AES.new(key, AES.MODE_CTR, counter=independent_counter).encrypt(data)
    assert bytes(output) == independent, "Manual ECB/CTR differs from PyCryptodome CTR"
    return bytes(output), counter_blocks


def vector(
    name: str,
    *,
    password: str = "FreeArc-test-password",
    fixed: bool = False,
    key_bits: int = 256,
    iterations: int = 1000,
    rounds: int = 0,
    salt: bytes = bytes(range(32)),
    iv: bytes = bytes.fromhex("00112233445566778899aabbccddeeff"),
    check_size: int = 2,
    data: bytes = bytes(range(49)),
    lzma_chain: bool = False,
) -> dict:
    # GHC 6.10/6.12 withCStringLen aliases withCAStringLen, whose conversion
    # is fromIntegral (ord ch). The no-:f representation is Unicode Char8,
    # not the original UTF-8 input bytes. :f adds upstream unicode2utf8 first.
    password_bytes = (
        password.encode("utf-8") if fixed
        else bytes(ord(char) & 255 for char in password)
    )
    key_size = key_bits // 8
    derived = hashlib.pbkdf2_hmac(
        "sha512", password_bytes, salt, iterations, dklen=key_size + check_size
    )
    key, check = derived[:key_size], derived[key_size:]
    effective_key = key if fixed else legacy_hex_decode(key.hex())
    effective_iv = iv if fixed else legacy_hex_decode(iv.hex())
    cipher_input = data
    prefix = "storing+"
    if lzma_chain:
        cipher_input = lzma.compress(
            data,
            format=lzma.FORMAT_RAW,
            filters=[{
                "id": lzma.FILTER_LZMA1,
                "dict_size": 1 << 20,
                "lc": 3,
                "lp": 0,
                "pb": 2,
                "mode": lzma.MODE_NORMAL,
                "mf": lzma.MF_BT4,
            }],
        )
        prefix = "lzma:1mb:lc3:lp0:pb2+"

    ciphertext, counters = ctr_crypt(effective_key, effective_iv, cipher_input)
    assert ctr_crypt(effective_key, effective_iv, ciphertext)[0] == cipher_input
    method = (
        f"aes-{key_bits}/ctr" + (":f" if fixed else "")
        + f":n{iterations}:r{rounds}:s{salt.hex()}:c{check.hex()}:i{iv.hex()}"
    )
    return {
        "name": name,
        "method": method,
        "chain_method": prefix + method,
        "password_text": password,
        "password_input_utf8_hex": password.encode("utf-8").hex(),
        "password_kdf_hex": password_bytes.hex(),
        "fixed": fixed,
        "key_bits": key_bits,
        "iterations": iterations,
        "rounds": rounds,
        "salt_hex": salt.hex(),
        "check_hex": check.hex(),
        "derived_key_and_check_hex": derived.hex(),
        "effective_key_hex": effective_key.hex(),
        "stored_iv_hex": iv.hex(),
        "effective_iv_hex": effective_iv.hex(),
        "counter_blocks_hex": counters,
        "plaintext_hex": data.hex(),
        "cipher_input_hex": cipher_input.hex(),
        "ciphertext_hex": ciphertext.hex(),
    }


def build_document() -> dict:
    return {
        "schema": "xxfclib.freearc_cipher_vectors.v1",
        "generator": "generate_cipher_vectors.py",
        "provenance": [
            UPSTREAM + "Encryption.hs#L65-L85",
            UPSTREAM + "Encryption.hs#L114-L117",
            UPSTREAM + "Compression/_Encryption/C_Encryption.cpp#L125-L160",
            UPSTREAM + "Compression/_Encryption/C_Encryption.cpp#L221-L267",
            UPSTREAM + "Compression/_Encryption/C_Encryption.cpp#L300-L305",
            UPSTREAM + "Compression/Common.h#L787-L790",
            "https://downloads.haskell.org/~ghc/6.12.2/docs/html/libraries/"
            "base-4.2.0.1/src/Foreign-C-String.html#withCStringLen",
        ],
        "notes": [
            "Known passwords and deterministic test data only; no user input files are read.",
            "KDF is hashlib PBKDF2-HMAC-SHA512; cipher is PyCryptodome AES.",
            "All CTR answers compare manual ECB with PyCryptodome CTR.",
            "No :f means key and IV use buggy hex; salt and check use ordinary hex.",
            "No :f password bytes are low eight bits of each Unicode scalar (GHC Char8).",
            ":f password bytes are UTF-8; CTR starts at IV and increments little endian.",
            "cipher_input is plaintext or raw LZMA; cipher length is unchanged.",
        ],
        "vectors": [
            vector("legacy_ascii_partial", data=b"partial"),
            vector("legacy_ascii_multiple_blocks"),
            vector("fixed_ascii_multiple_blocks", fixed=True),
            vector("fixed_utf8_password", fixed=True, password="p\u00e4ss-\u20ac-\U0001f510"),
            vector("legacy_unicode_char8", password="p\u00e4ss-\u20ac-\U0001f510"),
            vector("fixed_counter_carry_byte0", fixed=True,
                   iv=bytes.fromhex("ff112233445566778899aabbccddeeff")),
            vector("fixed_counter_carry_64bit", fixed=True,
                   iv=bytes.fromhex("ffffffffffffffff8899aabbccddeeff")),
            vector("fixed_counter_wrap_128bit", fixed=True, iv=bytes.fromhex("ff" * 16)),
            vector("fixed_aes128_explicit_rounds", fixed=True, key_bits=128,
                   rounds=10, salt=bytes(range(16))),
            vector("fixed_aes192_explicit_rounds", fixed=True, key_bits=192,
                   rounds=12, salt=bytes(range(24))),
            vector("fixed_variable_salt_check", fixed=True, iterations=17,
                   salt=b"salt", check_size=7, data=b"FreeArc variable KDF lengths"),
            vector("legacy_empty_check", check_size=0, data=b"no check"),
            vector("legacy_lzma_chain", lzma_chain=True,
                   data=(b"FreeArc encrypted raw LZMA test.\n" * 13)),
            vector("fixed_utf8_lzma_chain", fixed=True,
                   password="\u00e4\u20ac\U0001f510", lzma_chain=True,
                   data=(b"Fixed FreeArc UTF-8 chain test.\n" * 17)),
            vector("fixed_empty_input", fixed=True, data=b""),
            vector("fixed_empty_password", fixed=True, password=""),
            vector("legacy_hmac_long_password", password="A" * 150),
        ],
    }


def c_array(name: str, data: bytes) -> str:
    lines = []
    for offset in range(0, len(data), 16):
        lines.append("    " + ", ".join(f"0x{value:02x}" for value in data[offset:offset + 16]) + ",")
    # C has no portable zero-length array; the accompanying length remains 0.
    if not lines:
        lines.append("    0x00,")
    return f"static const unsigned char {name}[] = {{\n" + "\n".join(lines) + "\n};\n"


def build_c_include(document: dict) -> str:
    text = [
        "/* Generated by generate_cipher_vectors.py; do not edit manually.",
        " * Independent hashlib SHA512 / PyCryptodome AES known answers.",
        " * Define struct freearc_cipher_vector before including this file:",
        " *   const char *name, *method, *password_utf8;",
        " *   const unsigned char *ciphertext; size_t ciphertext_size;",
        " *   const unsigned char *expected; size_t expected_size;",
        " * Methods are full decode chains; expected bytes are final plaintext.",
        " * AES-128 and AES-192 JSON vectors are intentionally excluded here.",
        " */\n",
    ]
    vectors = [item for item in document["vectors"] if item["key_bits"] == 256]
    for index, item in enumerate(vectors):
        text.append(c_array(f"freearc_cipher_{index}", bytes.fromhex(item["ciphertext_hex"])))
        text.append(c_array(f"freearc_expected_{index}", bytes.fromhex(item["plaintext_hex"])))
    text.append("static const struct freearc_cipher_vector freearc_cipher_vectors[] = {\n")
    for index, item in enumerate(vectors):
        # Every byte is escaped separately; supplementary Unicode code points
        # therefore reach the native test as the exact UTF-8 API input bytes.
        password_literal = '"' + "".join(
            f"\\x{value:02x}" for value in bytes.fromhex(item["password_input_utf8_hex"])
        ) + '"'
        text.append(
            "    {" + json.dumps(item["name"]) + ",\n"
            "     " + json.dumps(item["chain_method"]) + ",\n"
            "     " + password_literal + ",\n"
            f"     freearc_cipher_{index}, {len(bytes.fromhex(item['ciphertext_hex']))}U, "
            f"freearc_expected_{index}, {len(bytes.fromhex(item['plaintext_hex']))}U" + "},\n"
        )
    text.append("};\n")
    return "\n".join(text)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    parser.add_argument("--output", type=Path,
                        default=Path(__file__).with_name("cipher_vectors.json"))
    parser.add_argument("--c-output", type=Path,
                        default=Path(__file__).with_name("cipher_vectors.inc"))
    args = parser.parse_args()
    document = build_document()
    encoded = json.dumps(document, indent=2, ensure_ascii=True) + "\n"
    c_encoded = build_c_include(document)
    json_count = len(document["vectors"])
    c_count = sum(item["key_bits"] == 256 for item in document["vectors"])
    if args.check:
        if args.output.read_text(encoding="utf-8") != encoded:
            raise SystemExit("cipher_vectors.json differs; regenerate it")
        if args.c_output.read_text(encoding="utf-8") != c_encoded:
            raise SystemExit("cipher_vectors.inc differs; regenerate it")
        print(f"Verified {json_count} independent FreeArc JSON vectors and {c_count} AES-256 C vectors")
    else:
        args.output.write_text(encoded, encoding="utf-8", newline="\n")
        args.c_output.write_text(c_encoded, encoding="utf-8", newline="\n")
        print(f"Wrote {json_count} independent FreeArc JSON vectors: {args.output}")
        print(f"Wrote {c_count} independent AES-256 C vectors: {args.c_output}")


if __name__ == "__main__":
    main()
