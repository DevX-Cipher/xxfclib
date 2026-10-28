/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT */
#ifndef XX_LZH5_INTERNAL_H
#define XX_LZH5_INTERNAL_H
#include "xxfclib/xxfc_defs.h"
/* Private exact-container contract; the public tolerant decoder is unchanged.
 * Both pointers must be non-NULL, including empty buffers. Empty output is
 * exact only for empty input. Final zero fill is limited to seven bits. */
bool xx_lzh5_decode_exact_memory(const uint8_t *, size_t, uint8_t *, size_t, int, size_t *);
#endif
