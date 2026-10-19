/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#include "xx_deflate_platform.h"

#ifdef XX_DEFLATE_NEON
#include <arm_neon.h>

size_t xx_deflate_match_neon(const uint8_t *a, const uint8_t *b, size_t maximum)
{
    size_t at = 0U;
    for (; maximum - at >= 16U; at += 16U) {
        uint8x16_t equal = vceqq_u8(vld1q_u8(a + at), vld1q_u8(b + at));
        if (vminvq_u8(equal) != UINT8_MAX) {
            uint8_t lanes[16];
            size_t lane;
            vst1q_u8(lanes, equal);
            for (lane = 0U; lane < 16U; ++lane) {
                if (lanes[lane] == 0U) return at + lane;
            }
        }
    }
    return at + xx_deflate_match_words(a + at, b + at, maximum - at);
}
#endif /* XX_DEFLATE_NEON */
