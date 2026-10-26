# Independent FreeArc cipher known answers

These deterministic test fixtures are independent cryptographic known answers,
generated from the published FreeArc algorithms. They are not generated with
xxfclib and contain no data from the user's archive files. The passwords are
public test strings. They establish cipher and method-chain compatibility;
they are not output captured from a FreeArc executable. The additional `.arc`
fixtures below exercise complete container parsing.

`generate_cipher_vectors.py` uses Python `hashlib.pbkdf2_hmac("sha512", ...)`
and PyCryptodome AES. Each manually formed little-endian AES-ECB counter stream
is checked against PyCryptodome's AES-CTR implementation. Raw LZMA chain inputs
come from Python's `lzma` module. No xxfclib code is imported or invoked.

`cipher_vectors.json` contains 17 vectors including derived key/check material,
effective legacy key/IV bytes, the counter blocks, API password UTF-8 bytes,
actual KDF password bytes, cipher input/output, and final plaintext.

`cipher_vectors.inc` includes the 15 AES-256/CTR cases. AES-128 and AES-192
vectors remain in JSON for documentation and are intentionally absent from the
native C include because this reader implements AES-256 only. The C include
expects this struct to be defined first:

```c
struct freearc_cipher_vector {
    const char *name;
    const char *method;
    const char *password_utf8;
    const unsigned char *ciphertext;
    size_t ciphertext_size;
    const unsigned char *expected;
    size_t expected_size;
};
```

The table is `freearc_cipher_vectors`. Its `method` includes the complete
`storing+aes` or `lzma+aes` chain; `expected` is the final plaintext after the
whole chain is decoded. Passwords use explicit UTF-8 byte escapes. Empty
byte arrays have one unused dummy byte and a declared data size of zero.

Coverage includes the legacy hex-decoding bug, fixed `:f` encoding, ASCII and
Unicode passwords, partial and multiple cipher blocks, carry at byte zero and
64 bits and wrap at 128 bits, variable salt/check lengths, no check bytes,
empty input, an explicitly empty password, a 150-byte ASCII password exercising
HMAC-SHA512's key-hash path, and raw-LZMA/AES method composition.

Regenerate with Python 3 and PyCryptodome installed:

```text
python generate_cipher_vectors.py
python generate_cipher_vectors.py --check
```

Primary implementation references, pinned to FreeArc source commit
`71f3ab36df26401fff4301b4c8600a31a90d8da9`:

- [Key derivation, check bytes, legacy versus UTF-8 password behavior](https://github.com/mirror/freearc/blob/71f3ab36df26401fff4301b4c8600a31a90d8da9/Encryption.hs#L65-L117).
- [C password/salt marshalling](https://github.com/mirror/freearc/blob/71f3ab36df26401fff4301b4c8600a31a90d8da9/Compression/EncryptionLib.hs#L24-L31).
- [CTR initialization, SHA512 KDF, exact-length stream handling, key/IV decoding](https://github.com/mirror/freearc/blob/71f3ab36df26401fff4301b4c8600a31a90d8da9/Compression/_Encryption/C_Encryption.cpp#L125-L305).
- [Legacy `buggy_char2int` omits ten for letters](https://github.com/mirror/freearc/blob/71f3ab36df26401fff4301b4c8600a31a90d8da9/Compression/Common.h#L787-L790).
- [Little-endian counter increment](https://github.com/mirror/freearc/blob/71f3ab36df26401fff4301b4c8600a31a90d8da9/Compression/_Encryption/modes/ctr/ctr_encrypt.c#L61-L103).
- [Optimized AES counter carries through all 128 bits](https://github.com/mirror/freearc/blob/71f3ab36df26401fff4301b4c8600a31a90d8da9/Compression/_Encryption/7zAES/Aes.c#L265-L282).
- [GHC 6.10 documentation: CString functions alias CAString functions](https://downloads.haskell.org/~ghc/6.10.1/docs/html/libraries/base/Foreign-C-String.html).
- [GHC 6.12 source: `withCStringLen` alias and Char8 conversion](https://downloads.haskell.org/~ghc/6.12.2/docs/html/libraries/base-4.2.0.1/src/Foreign-C-String.html).

The historical no-`:f` password conversion uses the low eight bits of each
Unicode code point after the application's input charset decoding. It does
not hash the original UTF-8 input bytes. With `:f`, the application first
encodes Unicode as UTF-8. Salt and check strings always use correct hex;
only the key and IV use buggy hex when `:f` is absent.

`generate_archives.py` independently assembles four small containers:
legacy encrypted metadata and members, fixed encrypted metadata and members,
legacy encrypted members with plain metadata, and a plain baseline. Each has
`first.txt` (three copies of `FreeArc encrypted first member.\n`) and
`second.bin` (bytes 0..255, then `00 ff 74 61 69 6c`). Their public password is
`FreeArc-fixture-password`. Regenerate/check with `python generate_archives.py`
or `python generate_archives.py --check`.

Native AES support is bounded to AES-256/CTR with standard rounds (`r0` or
`r14`), at most 1,000,000 aggregate PBKDF2 rounds per method chain, 64 salt
bytes and 32 check bytes. The IV must contain exactly 16 bytes. Existing
control and solid-block memory limits remain in force. Encryption has no
authentication tag: the reader validates control CRCs before listing and
member CRCs before publishing extracted files. Keyfile concatenation is not
provided by the password string API.
