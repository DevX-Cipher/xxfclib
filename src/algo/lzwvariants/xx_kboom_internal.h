/* Copyright (c) 2026 hors<horsicq@gmail.com>. SPDX-License-Identifier: MIT */
#ifndef XX_KBOOM_INTERNAL_H
#define XX_KBOOM_INTERNAL_H
#include "xxfclib/algo/lzwvariants/xx_lzwvariants.h"
/* Internal layout discriminator: allocated codes only, exact input extent.
 * NULL output validates the stream without allocating its plaintext. */
bool xx_kboom_decode_exact_memory(const uint8_t *input, size_t input_size, uint8_t *output, size_t output_size, size_t *written);
#endif
