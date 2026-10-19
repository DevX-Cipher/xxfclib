/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#include "xx_dotnet_us_simd.h"

#if XX_DOTNET_HAVE_X86_SIMD

#include <immintrin.h>

#if defined(_MSC_VER)
#define XX_DOTNET_US_AVX2_NOINLINE __declspec(noinline)
#elif defined(__GNUC__) || defined(__clang__)
#define XX_DOTNET_US_AVX2_NOINLINE __attribute__((noinline, target("avx2")))
#else
#define XX_DOTNET_US_AVX2_NOINLINE
#endif
XX_DOTNET_US_AVX2_NOINLINE
size_t xx_dotnet_us_ascii_avx2(const uint8_t *source, size_t units, uint8_t *destination, size_t capacity)
{
    const __m256i non_ascii_mask = _mm256_set1_epi16(-128);
    size_t at = 0;

    while (units - at >= 16U && capacity - at >= 16U) {
        __m256i values = _mm256_loadu_si256((const __m256i *)(const void *)(source + at * 2U));
        __m256i non_ascii = _mm256_and_si256(values, non_ascii_mask);
        __m128i low;
        __m128i high;

        if (!_mm256_testz_si256(non_ascii, non_ascii)) break;
        low = _mm256_castsi256_si128(values);
        high = _mm256_extracti128_si256(values, 1);
        _mm_storeu_si128((__m128i *)(void *)(destination + at), _mm_packus_epi16(low, high));
        at += 16U;
    }
    _mm256_zeroupper();
    return at;
}

#undef XX_DOTNET_US_AVX2_NOINLINE

#endif
