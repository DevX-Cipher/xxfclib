/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#ifndef XX_LZMA_ASM_H
#define XX_LZMA_ASM_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER) && defined(_M_X64)
#define XX_LZMA_HAS_ASM 1
#else
#define XX_LZMA_HAS_ASM 0
#endif

#ifdef __cplusplus
}
#endif

#endif /* XX_LZMA_ASM_H */
