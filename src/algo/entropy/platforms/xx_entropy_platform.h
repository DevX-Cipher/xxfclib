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
 * @file xx_entropy_platform.h
 * @brief Internal platform interface for SIMD-accelerated Shannon entropy operations.
 */

#ifndef XX_ENTROPY_PLATFORM_H
#define XX_ENTROPY_PLATFORM_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#if (defined(_M_ARM64) && !defined(_M_ARM64EC)) || defined(__aarch64__)
#define XX_ENTROPY_NEON 1
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Calculate Shannon entropy using SSE2 128-bit SIMD instructions.
 *
 * @param data Pointer to input buffer.
 * @param size Size of buffer in bytes.
 * @return Shannon entropy value from 0.0 to 8.0.
 */
double xx_entropy_calculate_sse2(const void *data, size_t size);

/** Build a 256-bin histogram using the SSE2 backend. The output is replaced.
 * @pre size <= UINT32_MAX. */
void xx_entropy_histogram_sse2(const void *data, size_t size, uint32_t counts[256]);

/**
 * @brief Calculate Shannon entropy using AVX2 256-bit SIMD instructions.
 *
 * @param data Pointer to input buffer.
 * @param size Size of buffer in bytes.
 * @return Shannon entropy value from 0.0 to 8.0.
 */
double xx_entropy_calculate_avx2(const void *data, size_t size);

/** Build a 256-bin histogram using the AVX2 backend. The output is replaced.
 * @pre size <= UINT32_MAX. */
void xx_entropy_histogram_avx2(const void *data, size_t size, uint32_t counts[256]);

#ifdef XX_ENTROPY_NEON
/** Calculate Shannon entropy using the Arm64 optimized histogram backend. */
double xx_entropy_calculate_neon(const void *data, size_t size);

/** Build a 256-bin histogram using the Arm64 backend. The output is replaced.
 * @pre size <= UINT32_MAX. */
void xx_entropy_histogram_neon(const void *data, size_t size, uint32_t counts[256]);
#endif

#ifdef __cplusplus
}
#endif

#endif /* XX_ENTROPY_PLATFORM_H */
