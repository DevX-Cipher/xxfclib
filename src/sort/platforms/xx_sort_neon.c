/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#include "../xx_sort_internal.h"

#ifdef XX_SORT_ARM_NEON

#include <arm_neon.h>

static void xx_sort_swap_bytes(char *pLeft, char *pRight, size_t nSize)
{
    size_t i = 0;

    if (pLeft == pRight) return;

    /* Load both sides before either store so overlapping-looking compiler
     * schedules cannot destroy one of the values. Elements need no padding. */
    for (; nSize - i >= 16; i += 16) {
        uint8x16_t left = vld1q_u8((const uint8_t *)pLeft + i);
        uint8x16_t right = vld1q_u8((const uint8_t *)pRight + i);
        vst1q_u8((uint8_t *)pLeft + i, right);
        vst1q_u8((uint8_t *)pRight + i, left);
    }

    for (; i < nSize; ++i) {
        char value = pLeft[i];
        pLeft[i] = pRight[i];
        pRight[i] = value;
    }
}

void xx_sort_swap_neon(char *pLeft, char *pRight, size_t nSize)
{
    xx_sort_swap_bytes(pLeft, pRight, nSize);
}

#define XX_SORT_IMPL(name) name##_neon
#include "../xx_sort_algorithms.inc"
#undef XX_SORT_IMPL

#endif
