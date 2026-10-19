/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#include "xx_lzma_platform.h"

#ifdef XX_LZMA_NEON
#include <arm_neon.h>

void xx_lzma_fill_probs_neon(uint16_t *probabilities, size_t count)
{
    uint16x8_t value = vdupq_n_u16(1024U);
    size_t at = 0U;
    for (; count - at >= 8U; at += 8U) vst1q_u16(probabilities + at, value);
    for (; at < count; ++at) probabilities[at] = 1024U;
}

size_t xx_lzma_match_length_neon(const uint8_t *first, const uint8_t *second, size_t maximum)
{
    size_t at = 0U;
    for (; maximum - at >= 16U; at += 16U) {
        uint8x16_t equal = vceqq_u8(vld1q_u8(first + at), vld1q_u8(second + at));
        if (vminvq_u8(equal) != UINT8_MAX) {
            uint8_t lanes[16];
            size_t lane;
            vst1q_u8(lanes, equal);
            for (lane = 0U; lane < 16U; ++lane) {
                if (lanes[lane] == 0U) return at + lane;
            }
        }
    }
    while (at < maximum && first[at] == second[at]) ++at;
    return at;
}
#endif /* XX_LZMA_NEON */
