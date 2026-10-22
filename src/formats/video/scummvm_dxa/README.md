# ScummVM DXA video

This reader handles the `DEXA` video container used by ScummVM and The
Feeble Files. It is a separate format from the DxLib resource archives
that also use the `.dxa` extension.

Extraction produces `audio.wav` when a RIFF/WAVE soundtrack is embedded,
followed by `frame-000001.bmp`, and so on. Frames are standard 8-bit indexed
BMPs with a complete palette, top-down rows, and DWORD row padding.
The WAV bytes are preserved exactly.

The supported picture methods are zlib keyframes (2), zlib XOR deltas (3),
and unchanged pictures (`NULL`). Palettes are updated by `CMAP` and carried
forward through `NULL` palette entries. Each logical frame has a palette
tag and a picture tag; an unchanged frame therefore has two `NULL` tags.
Doubled heights repeat each coded row. Interlaced heights insert palette
index zero on the unencoded rows, as in the original indexed display.

Methods 12 and 13, extended headers, dimensions above 2048 pixels, and
compressed pictures above 16 MiB are rejected explicitly. The frame count
is the format's 16-bit count, at most 65535. Memory use is bounded by the
frame index, two indexed picture buffers, and one compressed picture.
All input extents are checked before reads. Extraction verifies each zlib
stream's decoded length and Adler-32, polls cancellation, and removes a
partially written member after a failure. A structural listing does not
claim that compressed picture checksums have been verified.

The implementation is original MIT-licensed C. Container and simple
zlib/XOR format facts were checked against the primary
[ScummVM decoder](https://github.com/scummvm/scummvm/blob/master/video/dxa_decoder.cpp)
and [ScummVM Tools encoder](https://github.com/scummvm/scummvm-tools/blob/master/encode_dxa.cpp).
No GPL decoder code is incorporated. Decompression uses xxfclib's native
RFC 1950 implementation; no external decoder is required at runtime.

`tests/test_scummvm_dxa_native.c` constructs fixtures to verify exact BMP
pixels, XOR deltas, unchanged pictures, palette carry-over and replacement,
height modes, row padding, truncation, unsupported methods, cancellation,
and corrupted checksums. Real-file validation should additionally compare
the exported frames and audio with an independent decoder. A reference
demuxer that counts each `NULL` separately needs the palette-only `NULL`
tags removed from its temporary input to preserve the logical frame count.
