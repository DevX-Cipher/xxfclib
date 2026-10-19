/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#ifndef XX_ZSTD_DEC_H
#define XX_ZSTD_DEC_H

#include <stdbool.h>
#include <stddef.h>

bool xx_zstd_decode_frames(const void *source, size_t source_size, void *destination, size_t destination_size, size_t *out_written);

bool xx_zstd_decode_frames_bounded(const void *source, size_t source_size, void *destination, size_t destination_capacity, size_t *out_written);

/* Internal retry interface: distinguishes an output-capacity stop from other
 * failures. Later bytes can still be malformed. The caller may grow only on
 * this signal, up to an independently scanned bound. */
bool xx_zstd_decode_frames_bounded_retry(const void *source, size_t source_size, void *destination, size_t destination_capacity, size_t *out_written,
                                         bool *needs_more_output);
/* Internal: xx_zstd_decode_frames_bounded, but for input that may end
 * inside a frame (a cut file). It then fails with *cut set and *out_written
 * the bytes of the whole blocks before that point, and of what there is of a
 * cut raw block; the cut frame's checksum cannot check them. Whole or cut,
 * *checked (optional) gets the bytes from the start that frame checksums
 * vouch for: the frames up to the first one without a checksum, or without
 * all of it. */
bool xx_zstd_decode_frames_prefix(const void *source, size_t source_size, void *destination, size_t destination_size, size_t *out_written, bool *cut, size_t *checked);

#endif /* XX_ZSTD_DEC_H */
