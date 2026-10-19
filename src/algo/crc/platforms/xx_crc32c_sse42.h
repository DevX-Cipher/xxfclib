/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#ifndef XX_CRC32C_SSE42_H
#define XX_CRC32C_SSE42_H

#include <stddef.h>
#include <stdint.h>

#if defined(_M_IX86) || defined(_M_X64) || defined(__i386__) || defined(__x86_64__)
#define XX_CRC32C_SSE42_X86 1

/* Uses the public CRC32C seed/finalization convention. The caller must check
 * SSE4.2 support before entering this function. */
uint32_t xx_crc32c_sse42(uint32_t crc, const void *data, size_t size);
#endif

#endif /* XX_CRC32C_SSE42_H */
