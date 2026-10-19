/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#ifndef XX_CRC64_PLATFORM_H
#define XX_CRC64_PLATFORM_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* The 256-bit intrinsic is available in GCC and Clang, including MinGW and
 * clang-cl. Pure MSVC builds retain the existing AVX2/PCLMUL backend. */
#if defined(_M_IX86) || defined(_M_X64) || defined(__i386__) || defined(__x86_64__)
#if (defined(__clang__) && __clang_major__ >= 8) || (defined(__GNUC__) && !defined(__clang__) && __GNUC__ >= 8)
#define XX_CRC64_HAVE_VPCLMUL 1
#endif
#endif

/* Private implementations have the same incremental seed/finalization as the
 * public CRC64 functions. SIMD entry points require PCLMULQDQ in addition to
 * their named ISA; call them only after checking the selected platform. The
 * VPCLMULQDQ path also requires AVX2 and OS support for XMM/YMM registers. */
typedef struct xx_crc64_platform_s {
    const char *name;
    uint64_t (*xz)(uint64_t, const void *, size_t);
    uint64_t (*ecma)(uint64_t, const void *, size_t);
} xx_crc64_platform;

bool xx_crc64_has_pclmul(void);
const xx_crc64_platform *xx_crc64_platform_select(void);
uint64_t xx_crc64_xz_scalar(uint64_t, const void *, size_t);
uint64_t xx_crc64_ecma_scalar(uint64_t, const void *, size_t);
uint64_t xx_crc64_xz_sse2(uint64_t, const void *, size_t);
uint64_t xx_crc64_ecma_sse2(uint64_t, const void *, size_t);
uint64_t xx_crc64_xz_avx2(uint64_t, const void *, size_t);
uint64_t xx_crc64_ecma_avx2(uint64_t, const void *, size_t);
uint64_t xx_crc64_xz_vpclmul(uint64_t, const void *, size_t);
uint64_t xx_crc64_ecma_vpclmul(uint64_t, const void *, size_t);

#endif
