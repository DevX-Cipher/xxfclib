/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#ifndef XX_BZIP2_ASM_H
#define XX_BZIP2_ASM_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER) && defined(_M_X64)
#define XX_BZIP2_HAS_ASM 1
bool xx_bzip2_bwt_traverse_x64(const uint32_t *tt, int tt_count, uint32_t orig_ptr, uint8_t *dest, size_t dest_cap, size_t *out_written);
void xx_bzip2_bwt_build_x64(const uint8_t *bwt_bytes, uint32_t *tt, const uint32_t *freq, int tt_count);
#elif defined(_MSC_VER) && defined(_M_IX86)
#define XX_BZIP2_HAS_ASM 1
bool xx_bzip2_bwt_traverse_x86(const uint32_t *tt, int tt_count, uint32_t orig_ptr, uint8_t *dest, size_t dest_cap, size_t *out_written);
void xx_bzip2_bwt_build_x86(const uint8_t *bwt_bytes, uint32_t *tt, const uint32_t *freq, int tt_count);
#else
#define XX_BZIP2_HAS_ASM 0
#endif

#ifdef __cplusplus
}
#endif

#endif /* XX_BZIP2_ASM_H */
