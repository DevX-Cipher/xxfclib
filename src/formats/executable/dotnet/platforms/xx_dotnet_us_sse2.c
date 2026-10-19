/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#include "xx_dotnet_us_simd.h"

#if XX_DOTNET_HAVE_X86_SIMD

#include <emmintrin.h>

#if defined(_MSC_VER)
#define XX_DOTNET_US_SSE2_NOINLINE __declspec(noinline)
#elif (defined(__GNUC__) || defined(__clang__)) && defined(__i386__) && !defined(__SSE2__)
#define XX_DOTNET_US_SSE2_NOINLINE __attribute__((noinline, target("sse2")))
#elif defined(__GNUC__) || defined(__clang__)
#define XX_DOTNET_US_SSE2_NOINLINE __attribute__((noinline))
#else
#define XX_DOTNET_US_SSE2_NOINLINE
#endif
XX_DOTNET_US_SSE2_NOINLINE
size_t xx_dotnet_us_ascii_sse2(const uint8_t *source, size_t units, uint8_t *destination, size_t capacity)
{
    const __m128i zero = _mm_setzero_si128();
    const __m128i non_ascii_mask = _mm_set1_epi16(-128);
    size_t at = 0;

    while (units - at >= 8U && capacity - at >= 8U) {
        __m128i values = _mm_loadu_si128((const __m128i *)(const void *)(source + at * 2U));
        __m128i non_ascii = _mm_and_si128(values, non_ascii_mask);
        __m128i is_ascii = _mm_cmpeq_epi16(non_ascii, zero);
        __m128i packed;

        if ((unsigned)_mm_movemask_epi8(is_ascii) != UINT16_MAX) break;
        packed = _mm_packus_epi16(values, zero);
        _mm_storel_epi64((__m128i *)(void *)(destination + at), packed);
        at += 8U;
    }
    return at;
}

#undef XX_DOTNET_US_SSE2_NOINLINE

#endif
