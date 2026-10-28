/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#include "xx_regex_search.h"
#include "xxfclib/global/xx_global.h"
#include "xxfclib/rt/xx_rt.h"

#if !defined(_M_ARM64EC) && (defined(_M_IX86) || defined(_M_X64) || defined(__i386__) || defined(__x86_64__))
#define XX_REGEX_X86 1
#include <emmintrin.h>
#if defined(_MSC_VER)
#include <intrin.h>
#endif
#endif

#if !defined(_M_ARM64EC) && (defined(_M_ARM64) || defined(__aarch64__))
#define XX_REGEX_NEON 1
#include <arm_neon.h>
#endif

#if (defined(__GNUC__) || defined(__clang__)) && defined(XX_REGEX_X86)
#define XX_REGEX_SSE2 __attribute__((target("sse2")))
#else
#define XX_REGEX_SSE2
#endif

static const unsigned char *find_pair_scalar(const unsigned char *text, size_t candidates,
                                            unsigned char first, size_t offset,
                                            unsigned char second)
{
    size_t at;
    for (at = 0; at < candidates; ++at) {
        if (text[at] == first && text[at + offset] == second) return text + at;
    }
    return NULL;
}

#ifdef XX_REGEX_X86
XX_REGEX_SSE2
static const unsigned char *find_pair_sse2(const unsigned char *text, size_t candidates,
                                          unsigned char first, size_t offset,
                                          unsigned char second)
{
    const __m128i a = _mm_set1_epi8((char)first);
    const __m128i b = _mm_set1_epi8((char)second);
    size_t at = 0;
    for (; candidates - at >= 16; at += 16) {
        const __m128i left = _mm_loadu_si128((const __m128i *)(const void *)(text + at));
        const __m128i right = _mm_loadu_si128((const __m128i *)(const void *)(text + at + offset));
        unsigned int mask = (unsigned int)_mm_movemask_epi8(_mm_and_si128(_mm_cmpeq_epi8(left, a), _mm_cmpeq_epi8(right, b)));
        if (mask) {
#if defined(_MSC_VER)
            unsigned long bit;
            _BitScanForward(&bit, mask);
            return text + at + bit;
#else
            return text + at + (unsigned int)__builtin_ctz(mask);
#endif
        }
    }
    return find_pair_scalar(text + at, candidates - at, first, offset, second);
}
#endif

#ifdef XX_REGEX_NEON
static const unsigned char *find_pair_neon(const unsigned char *text, size_t candidates,
                                          unsigned char first, size_t offset,
                                          unsigned char second)
{
    const uint8x16_t a = vdupq_n_u8(first);
    const uint8x16_t b = vdupq_n_u8(second);
    size_t at = 0;
    for (; candidates - at >= 16; at += 16) {
        const uint8x16_t equal = vandq_u8(vceqq_u8(vld1q_u8(text + at), a),
                                        vceqq_u8(vld1q_u8(text + at + offset), b));
        const uint64x2_t words = vreinterpretq_u64_u8(equal);
        if (vgetq_lane_u64(words, 0) || vgetq_lane_u64(words, 1)) {
            return find_pair_scalar(text + at, 16, first, offset, second);
        }
    }
    return find_pair_scalar(text + at, candidates - at, first, offset, second);
}
#endif

const unsigned char *xx_regex_find_pair(const unsigned char *text, size_t size,
                                       unsigned char first, size_t offset,
                                       unsigned char second)
{
    size_t candidates;
    const unsigned char *candidate;
    if (!text || offset >= size) return NULL;
    candidates = size - offset;
    /* Preserve the runtime's wide single-byte search for sparse inputs. Only
     * switch to the pair filter after an actual false candidate is found. */
    candidate = (const unsigned char *)xx_rt_memchr(text, first, candidates);
    if (!candidate || candidate[offset] == second) return candidate;
    candidates -= (size_t)(candidate - text) + 1;
    text = candidate + 1;
    if (candidates >= 32) {
#ifdef XX_REGEX_X86
        if (xx_is_sse2_enabled()) return find_pair_sse2(text, candidates, first, offset, second);
#endif
#ifdef XX_REGEX_NEON
        if (xx_is_neon_enabled()) return find_pair_neon(text, candidates, first, offset, second);
#endif
    }
    return find_pair_scalar(text, candidates, first, offset, second);
}
