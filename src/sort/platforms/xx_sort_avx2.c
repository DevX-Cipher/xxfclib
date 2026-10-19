/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#include "../xx_sort_internal.h"

#if defined(_M_IX86) || defined(_M_X64) || defined(__i386__) || defined(__x86_64__)

#include <immintrin.h>

static void xx_sort_swap_bytes(char *pLeft, char *pRight, size_t nSize)
{
    size_t i = 0;

    if (pLeft == pRight) {
        return;
    }

    /* Unaligned exchanges remain strictly inside each element. The
     * compiler handles AVX upper-lane cleanup at scalar call boundaries. */
    for (; nSize - i >= 32; i += 32) {
        __m256i nLeft = _mm256_loadu_si256((const __m256i *)(pLeft + i));
        __m256i nRight = _mm256_loadu_si256((const __m256i *)(pRight + i));

        _mm256_storeu_si256((__m256i *)(pLeft + i), nRight);
        _mm256_storeu_si256((__m256i *)(pRight + i), nLeft);
    }

    for (; nSize - i >= 16; i += 16) {
        __m128i nLeft = _mm_loadu_si128((const __m128i *)(pLeft + i));
        __m128i nRight = _mm_loadu_si128((const __m128i *)(pRight + i));

        _mm_storeu_si128((__m128i *)(pLeft + i), nRight);
        _mm_storeu_si128((__m128i *)(pRight + i), nLeft);
    }

    for (; i < nSize; i++) {
        char nTemp = pLeft[i];

        pLeft[i] = pRight[i];
        pRight[i] = nTemp;
    }
}

void xx_sort_swap_avx2(char *pLeft, char *pRight, size_t nSize)
{
    xx_sort_swap_bytes(pLeft, pRight, nSize);
}

#define XX_SORT_IMPL(name) name##_avx2
#include "../xx_sort_algorithms.inc"
#undef XX_SORT_IMPL

#endif
