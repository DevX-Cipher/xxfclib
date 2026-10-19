/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#ifndef XX_DATA_FILTER_H
#define XX_DATA_FILTER_H

#include <stddef.h>
#include <stdint.h>

/* Prefer bytes that are less likely to occur in ordinary binary and text data.
 * The two selected positions are only a prefilter; callers must still compare
 * the complete pattern before reporting a match. */
static inline uint8_t xx_byte_weight(uint8_t c)
{
    if (c == 0x00) return 255;
    if (c == 0xFF) return 220;
    if (c == 0x20) return 180;
    if (c >= 'a' && c <= 'z') return 100;
    if (c >= 'A' && c <= 'Z') return 100;
    if (c >= '0' && c <= '9') return 120;
    return 50;
}

static inline void xx_select_filter_indices(const uint8_t *pat, size_t len, size_t *out_idx1, size_t *out_idx2)
{
    size_t i1;
    size_t i2;
    uint8_t w1;
    uint8_t w2;
    size_t k;

    if (len <= 1) {
        *out_idx1 = 0;
        *out_idx2 = 0;
        return;
    }
    if (len == 2) {
        *out_idx1 = 0;
        *out_idx2 = 1;
        return;
    }

    i1 = 0;
    i2 = len - 1;
    w1 = 255;
    w2 = 255;
    for (k = 0; k < len; ++k) {
        uint8_t w = xx_byte_weight(pat[k]);
        if (w < w1) {
            w2 = w1;
            i2 = i1;
            w1 = w;
            i1 = k;
        } else if (w < w2 && k != i1) {
            w2 = w;
            i2 = k;
        }
    }
    if (i1 == i2) {
        i2 = (i1 == 0) ? (len - 1) : 0;
    }
    if (i1 > i2) {
        size_t tmp = i1;
        i1 = i2;
        i2 = tmp;
    }
    *out_idx1 = i1;
    *out_idx2 = i2;
}

#endif
