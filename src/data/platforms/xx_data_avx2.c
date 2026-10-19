/* Copyright (c) 2026 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * @file xx_data_avx2.c
 * @brief AVX2 vectorized search implementation.
 */

#include "xx_data_platform.h"
#include "xx_data_filter.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/data/xx_pd.h"

#if (defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))) || ((defined(__GNUC__) || defined(__clang__)) && (defined(__i386__) || defined(__x86_64__)))
#if defined(_MSC_VER)
#include <intrin.h>
#include <immintrin.h>
#else
#include <immintrin.h>
#endif
#endif

#if defined(__GNUC__) || defined(__clang__)
#define XX_TARGET_AVX2 __attribute__((__target__("avx2")))
#else
#define XX_TARGET_AVX2
#endif

#if (defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))) || ((defined(__GNUC__) || defined(__clang__)) && (defined(__i386__) || defined(__x86_64__)))

static inline bool xx_fast_pattern_equal(const uint8_t *a, const uint8_t *b, size_t len)
{
    if (len <= 4) {
        if (len == 1) return a[0] == b[0];
        if (len == 2) {
            uint16_t v1, v2;
            xx_mem_copy(&v1, a, 2);
            xx_mem_copy(&v2, b, 2);
            return v1 == v2;
        }
        if (len == 3) {
            uint16_t v1, v2;
            xx_mem_copy(&v1, a, 2);
            xx_mem_copy(&v2, b, 2);
            return (v1 == v2) && (a[2] == b[2]);
        }
        uint32_t v1, v2;
        xx_mem_copy(&v1, a, 4);
        xx_mem_copy(&v2, b, 4);
        return v1 == v2;
    }
    if (len <= 8) {
        uint32_t v1a, v1b, v2a, v2b;
        xx_mem_copy(&v1a, a, 4);
        xx_mem_copy(&v2a, b, 4);
        xx_mem_copy(&v1b, a + len - 4, 4);
        xx_mem_copy(&v2b, b + len - 4, 4);
        return (v1a == v2a) && (v1b == v2b);
    }
    return xx_mem_compare(a, b, len) == 0;
}

XX_TARGET_AVX2
int64_t xx_data_find_bytes_avx2(const uint8_t *pdata, size_t data_size, size_t start_offset, const uint8_t *pat, size_t pattern_size, xx_pd_struct *pd)
{
    if (!pdata || !pat || pattern_size == 0 || start_offset + pattern_size > data_size || start_offset + pattern_size < start_offset) {
        return -1;
    }
    if (xx_pd_is_stopped(pd)) {
        return -1;
    }

    if (pattern_size == 1) {
        uint8_t target = pat[0];
        size_t limit = data_size - 1;
        size_t i = start_offset;
        __m256i target_v = _mm256_set1_epi8((char)target);

        /* 4x unrolled 128-byte loop */
        while (i + 128 <= data_size) {
            if (pd && (i & 0x7FFF) == 0 && xx_pd_is_stopped(pd)) {
                return -1;
            }
            __m256i b0 = _mm256_loadu_si256((const __m256i *)(pdata + i));
            __m256i b1 = _mm256_loadu_si256((const __m256i *)(pdata + i + 32));
            __m256i b2 = _mm256_loadu_si256((const __m256i *)(pdata + i + 64));
            __m256i b3 = _mm256_loadu_si256((const __m256i *)(pdata + i + 96));

            __m256i m0 = _mm256_cmpeq_epi8(b0, target_v);
            __m256i m1 = _mm256_cmpeq_epi8(b1, target_v);
            __m256i m2 = _mm256_cmpeq_epi8(b2, target_v);
            __m256i m3 = _mm256_cmpeq_epi8(b3, target_v);

            __m256i any = _mm256_or_si256(_mm256_or_si256(m0, m1), _mm256_or_si256(m2, m3));
            if (_mm256_testz_si256(any, any)) {
                i += 128;
                continue;
            }

            unsigned int mask0 = (unsigned int)_mm256_movemask_epi8(m0);
            if (mask0 != 0) {
                unsigned long bit_idx;
#if defined(_MSC_VER)
                _BitScanForward(&bit_idx, (unsigned long)mask0);
#else
                bit_idx = (unsigned long)__builtin_ctz((unsigned int)mask0);
#endif
                return (int64_t)(i + bit_idx);
            }

            unsigned int mask1 = (unsigned int)_mm256_movemask_epi8(m1);
            if (mask1 != 0) {
                unsigned long bit_idx;
#if defined(_MSC_VER)
                _BitScanForward(&bit_idx, (unsigned long)mask1);
#else
                bit_idx = (unsigned long)__builtin_ctz((unsigned int)mask1);
#endif
                return (int64_t)(i + 32 + bit_idx);
            }

            unsigned int mask2 = (unsigned int)_mm256_movemask_epi8(m2);
            if (mask2 != 0) {
                unsigned long bit_idx;
#if defined(_MSC_VER)
                _BitScanForward(&bit_idx, (unsigned long)mask2);
#else
                bit_idx = (unsigned long)__builtin_ctz((unsigned int)mask2);
#endif
                return (int64_t)(i + 64 + bit_idx);
            }

            unsigned int mask3 = (unsigned int)_mm256_movemask_epi8(m3);
            if (mask3 != 0) {
                unsigned long bit_idx;
#if defined(_MSC_VER)
                _BitScanForward(&bit_idx, (unsigned long)mask3);
#else
                bit_idx = (unsigned long)__builtin_ctz((unsigned int)mask3);
#endif
                return (int64_t)(i + 96 + bit_idx);
            }
            i += 128;
        }

        while (i + 32 <= data_size) {
            __m256i block = _mm256_loadu_si256((const __m256i *)(pdata + i));
            unsigned int mask = (unsigned int)_mm256_movemask_epi8(_mm256_cmpeq_epi8(block, target_v));
            if (mask != 0) {
                unsigned long bit_idx;
#if defined(_MSC_VER)
                _BitScanForward(&bit_idx, (unsigned long)mask);
#else
                bit_idx = (unsigned long)__builtin_ctz((unsigned int)mask);
#endif
                return (int64_t)(i + bit_idx);
            }
            i += 32;
        }

        while (i <= limit) {
            if (pdata[i] == target) {
                return (int64_t)i;
            }
            i++;
        }
        return -1;
    } else {
        size_t limit = data_size - pattern_size;
        size_t idx1, idx2;
        xx_select_filter_indices(pat, pattern_size, &idx1, &idx2);

        __m256i v1 = _mm256_set1_epi8((char)pat[idx1]);
        __m256i v2 = _mm256_set1_epi8((char)pat[idx2]);
        size_t i = start_offset;

        /* 4x unrolled 128-byte loop */
        while (i + 128 + idx2 <= data_size && i + 128 <= limit + 1) {
            if (pd && (i & 0x7FFF) == 0 && xx_pd_is_stopped(pd)) {
                return -1;
            }
            __m256i f0 = _mm256_loadu_si256((const __m256i *)(pdata + i + idx1));
            __m256i l0 = _mm256_loadu_si256((const __m256i *)(pdata + i + idx2));
            __m256i f1 = _mm256_loadu_si256((const __m256i *)(pdata + i + 32 + idx1));
            __m256i l1 = _mm256_loadu_si256((const __m256i *)(pdata + i + 32 + idx2));
            __m256i f2 = _mm256_loadu_si256((const __m256i *)(pdata + i + 64 + idx1));
            __m256i l2 = _mm256_loadu_si256((const __m256i *)(pdata + i + 64 + idx2));
            __m256i f3 = _mm256_loadu_si256((const __m256i *)(pdata + i + 96 + idx1));
            __m256i l3 = _mm256_loadu_si256((const __m256i *)(pdata + i + 96 + idx2));

            __m256i m0 = _mm256_and_si256(_mm256_cmpeq_epi8(f0, v1), _mm256_cmpeq_epi8(l0, v2));
            __m256i m1 = _mm256_and_si256(_mm256_cmpeq_epi8(f1, v1), _mm256_cmpeq_epi8(l1, v2));
            __m256i m2 = _mm256_and_si256(_mm256_cmpeq_epi8(f2, v1), _mm256_cmpeq_epi8(l2, v2));
            __m256i m3 = _mm256_and_si256(_mm256_cmpeq_epi8(f3, v1), _mm256_cmpeq_epi8(l3, v2));

            __m256i any = _mm256_or_si256(_mm256_or_si256(m0, m1), _mm256_or_si256(m2, m3));
            if (_mm256_testz_si256(any, any)) {
                i += 128;
                continue;
            }

            unsigned int mask0 = (unsigned int)_mm256_movemask_epi8(m0);
            while (mask0 != 0) {
                unsigned long bit_idx;
#if defined(_MSC_VER)
                _BitScanForward(&bit_idx, (unsigned long)mask0);
#else
                bit_idx = (unsigned long)__builtin_ctz((unsigned int)mask0);
#endif
                size_t off = i + bit_idx;
                if (off <= limit && (pattern_size <= 2 || xx_fast_pattern_equal(pdata + off, pat, pattern_size))) {
                    return (int64_t)off;
                }
                mask0 &= mask0 - 1;
            }

            unsigned int mask1 = (unsigned int)_mm256_movemask_epi8(m1);
            while (mask1 != 0) {
                unsigned long bit_idx;
#if defined(_MSC_VER)
                _BitScanForward(&bit_idx, (unsigned long)mask1);
#else
                bit_idx = (unsigned long)__builtin_ctz((unsigned int)mask1);
#endif
                size_t off = i + 32 + bit_idx;
                if (off <= limit && (pattern_size <= 2 || xx_fast_pattern_equal(pdata + off, pat, pattern_size))) {
                    return (int64_t)off;
                }
                mask1 &= mask1 - 1;
            }

            unsigned int mask2 = (unsigned int)_mm256_movemask_epi8(m2);
            while (mask2 != 0) {
                unsigned long bit_idx;
#if defined(_MSC_VER)
                _BitScanForward(&bit_idx, (unsigned long)mask2);
#else
                bit_idx = (unsigned long)__builtin_ctz((unsigned int)mask2);
#endif
                size_t off = i + 64 + bit_idx;
                if (off <= limit && (pattern_size <= 2 || xx_fast_pattern_equal(pdata + off, pat, pattern_size))) {
                    return (int64_t)off;
                }
                mask2 &= mask2 - 1;
            }

            unsigned int mask3 = (unsigned int)_mm256_movemask_epi8(m3);
            while (mask3 != 0) {
                unsigned long bit_idx;
#if defined(_MSC_VER)
                _BitScanForward(&bit_idx, (unsigned long)mask3);
#else
                bit_idx = (unsigned long)__builtin_ctz((unsigned int)mask3);
#endif
                size_t off = i + 96 + bit_idx;
                if (off <= limit && (pattern_size <= 2 || xx_fast_pattern_equal(pdata + off, pat, pattern_size))) {
                    return (int64_t)off;
                }
                mask3 &= mask3 - 1;
            }

            i += 128;
        }

        /* 32-byte loop */
        while (i + 32 + idx2 <= data_size && i + 32 <= limit + 1) {
            if (pd && (i & 0x7FFF) == 0 && xx_pd_is_stopped(pd)) {
                return -1;
            }
            __m256i b_first = _mm256_loadu_si256((const __m256i *)(pdata + i + idx1));
            __m256i b_last = _mm256_loadu_si256((const __m256i *)(pdata + i + idx2));
            unsigned int mask = (unsigned int)_mm256_movemask_epi8(_mm256_and_si256(_mm256_cmpeq_epi8(b_first, v1), _mm256_cmpeq_epi8(b_last, v2)));

            while (mask != 0) {
                unsigned long bit_idx;
#if defined(_MSC_VER)
                _BitScanForward(&bit_idx, (unsigned long)mask);
#else
                bit_idx = (unsigned long)__builtin_ctz((unsigned int)mask);
#endif
                size_t off = i + bit_idx;
                if (off <= limit && (pattern_size <= 2 || xx_fast_pattern_equal(pdata + off, pat, pattern_size))) {
                    return (int64_t)off;
                }
                mask &= mask - 1;
            }
            i += 32;
        }

        /* Scalar tail */
        while (i <= limit) {
            if (pdata[i + idx1] == pat[idx1] && pdata[i + idx2] == pat[idx2]) {
                if (pattern_size <= 2 || xx_fast_pattern_equal(pdata + i, pat, pattern_size)) {
                    return (int64_t)i;
                }
            }
            i++;
        }
        return -1;
    }
}

static inline bool xx_masked_equal_avx2(const uint8_t *data, const uint8_t *value, const uint8_t *mask, size_t size)
{
    size_t i;
    for (i = 0; i < size; ++i) {
        if ((uint8_t)(data[i] & mask[i]) != value[i]) return false;
    }
    return true;
}

XX_TARGET_AVX2
int64_t xx_data_find_masked_avx2(const uint8_t *data, size_t size, const uint8_t *value, const uint8_t *mask, size_t pattern_size, size_t idx1, size_t idx2)
{
    size_t last;
    size_t p = 0;
    __m256i b1;
    __m256i b2;

    if (!data || !value || !mask || pattern_size == 0 || pattern_size > size || idx1 >= pattern_size || idx2 >= pattern_size) {
        return -1;
    }

    last = size - pattern_size;
    b1 = _mm256_set1_epi8((char)value[idx1]);
    b2 = _mm256_set1_epi8((char)value[idx2]);

    /* 32 starts per step. p + 31 <= last keeps both loads inside the data:
     * p + idx + 31 <= size - pattern_size + idx <= size - 1. */
    while (last >= 31 && p <= last - 31) {
        __m256i d1 = _mm256_loadu_si256((const __m256i *)(const void *)(data + p + idx1));
        __m256i d2 = _mm256_loadu_si256((const __m256i *)(const void *)(data + p + idx2));
        uint32_t bits = (uint32_t)_mm256_movemask_epi8(_mm256_and_si256(_mm256_cmpeq_epi8(d1, b1), _mm256_cmpeq_epi8(d2, b2)));

        while (bits) {
            unsigned long bit;
#if defined(_MSC_VER)
            _BitScanForward(&bit, (unsigned long)bits);
#else
            bit = (unsigned long)__builtin_ctz(bits);
#endif
            if (xx_masked_equal_avx2(data + p + bit, value, mask, pattern_size)) {
                return (int64_t)(p + bit);
            }
            bits &= bits - 1U;
        }
        p += 32;
    }

    for (; p <= last; ++p) {
        if (data[p + idx1] == value[idx1] && data[p + idx2] == value[idx2] && xx_masked_equal_avx2(data + p, value, mask, pattern_size)) {
            return (int64_t)p;
        }
    }
    return -1;
}
#else
int64_t xx_data_find_masked_avx2(const uint8_t *data, size_t size, const uint8_t *value, const uint8_t *mask, size_t pattern_size, size_t idx1, size_t idx2)
{
    (void)data;
    (void)size;
    (void)value;
    (void)mask;
    (void)pattern_size;
    (void)idx1;
    (void)idx2;
    return -1;
}
int64_t xx_data_find_bytes_avx2(const uint8_t *pdata, size_t data_size, size_t start_offset, const uint8_t *pat, size_t pattern_size, xx_pd_struct *pd)
{
    (void)pdata;
    (void)data_size;
    (void)start_offset;
    (void)pat;
    (void)pattern_size;
    (void)pd;
    return -1;
}
#endif
