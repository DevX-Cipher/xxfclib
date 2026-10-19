/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#include "xx_memory_platform.h"

#ifdef XX_MEMORY_ARM_NEON
#include <arm_neon.h>

static int xx_memory_neon_all_equal(uint8x16_t value)
{
    uint64x2_t words = vreinterpretq_u64_u8(value);
    return vgetq_lane_u64(words, 0) == UINT64_MAX && vgetq_lane_u64(words, 1) == UINT64_MAX;
}

static int xx_memory_neon_any(uint8x16_t value)
{
    uint64x2_t words = vreinterpretq_u64_u8(value);
    return (vgetq_lane_u64(words, 0) | vgetq_lane_u64(words, 1)) != 0;
}
#endif

void xx_memory_copy_neon(uint8_t *destination, const uint8_t *source, size_t size)
{
#ifdef XX_MEMORY_ARM_NEON
    size_t at = 0;

    for (; size - at >= 64; at += 64) {
        uint8x16_t a = vld1q_u8(source + at);
        uint8x16_t b = vld1q_u8(source + at + 16);
        uint8x16_t c = vld1q_u8(source + at + 32);
        uint8x16_t d = vld1q_u8(source + at + 48);
        vst1q_u8(destination + at, a);
        vst1q_u8(destination + at + 16, b);
        vst1q_u8(destination + at + 32, c);
        vst1q_u8(destination + at + 48, d);
    }
    for (; size - at >= 16; at += 16) {
        vst1q_u8(destination + at, vld1q_u8(source + at));
    }
    xx_memory_copy_scalar(destination + at, source + at, size - at);
#else
    xx_memory_copy_scalar(destination, source, size);
#endif
}

void xx_memory_move_neon(uint8_t *destination, const uint8_t *source, size_t size)
{
#ifdef XX_MEMORY_ARM_NEON
    uintptr_t d = (uintptr_t)destination;
    uintptr_t s = (uintptr_t)source;
    size_t at;

    if (size == 0 || d == s) return;
    if (d > s && d - s < size) {
        at = size;
        while (at >= 16) {
            uint8x16_t value;
            at -= 16;
            value = vld1q_u8(source + at);
            vst1q_u8(destination + at, value);
        }
        xx_memory_move_scalar(destination, source, at);
    } else if (d < s && s - d < size) {
        at = 0;
        for (; size - at >= 16; at += 16) {
            uint8x16_t value = vld1q_u8(source + at);
            vst1q_u8(destination + at, value);
        }
        xx_memory_move_scalar(destination + at, source + at, size - at);
    } else {
        xx_memory_copy_neon(destination, source, size);
    }
#else
    xx_memory_move_scalar(destination, source, size);
#endif
}

void xx_memory_set_neon(uint8_t *destination, uint8_t value, size_t size)
{
#ifdef XX_MEMORY_ARM_NEON
    uint8x16_t bytes = vdupq_n_u8(value);
    size_t at = 0;

    for (; size - at >= 64; at += 64) {
        vst1q_u8(destination + at, bytes);
        vst1q_u8(destination + at + 16, bytes);
        vst1q_u8(destination + at + 32, bytes);
        vst1q_u8(destination + at + 48, bytes);
    }
    for (; size - at >= 16; at += 16) {
        vst1q_u8(destination + at, bytes);
    }
    xx_memory_set_scalar(destination + at, value, size - at);
#else
    xx_memory_set_scalar(destination, value, size);
#endif
}

int xx_memory_compare_neon(const uint8_t *first, const uint8_t *second, size_t size)
{
#ifdef XX_MEMORY_ARM_NEON
    size_t at = 0;

    for (; size - at >= 16; at += 16) {
        uint8x16_t equal = vceqq_u8(vld1q_u8(first + at), vld1q_u8(second + at));
        if (!xx_memory_neon_all_equal(equal)) {
            uint8_t lanes[16];
            size_t lane;
            vst1q_u8(lanes, equal);
            for (lane = 0; lane < 16; ++lane) {
                if (lanes[lane] == 0) return (int)first[at + lane] - (int)second[at + lane];
            }
        }
    }
    return xx_memory_compare_scalar(first + at, second + at, size - at);
#else
    return xx_memory_compare_scalar(first, second, size);
#endif
}

const uint8_t *xx_memory_find_neon(const uint8_t *source, uint8_t value, size_t size)
{
#ifdef XX_MEMORY_ARM_NEON
    uint8x16_t wanted = vdupq_n_u8(value);
    size_t at = 0;

    for (; size - at >= 16; at += 16) {
        uint8x16_t matches = vceqq_u8(vld1q_u8(source + at), wanted);
        if (xx_memory_neon_any(matches)) {
            uint8_t lanes[16];
            size_t lane;
            vst1q_u8(lanes, matches);
            for (lane = 0; lane < 16; ++lane) {
                if (lanes[lane] != 0) return source + at + lane;
            }
        }
    }
    return xx_memory_find_scalar(source + at, value, size - at);
#else
    return xx_memory_find_scalar(source, value, size);
#endif
}
