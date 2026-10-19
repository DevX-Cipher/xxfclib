/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

/**
 * @file xx_global_platform.h
 * @brief Internal platform interface for CPU and terminal feature detection.
 *
 * The axis here is instruction set and compiler, not operating system: MSVC
 * and GCC disagree about how to spell CPUID even when both target Windows on
 * x86-64. A windows/posix pair cannot express that, so the split is
 * xx_global_x86.c against xx_global_generic.c, selected by predicate the way
 * src/data/platforms/xx_data_sse2.c is.
 */

#ifndef XX_GLOBAL_PLATFORM_H
#define XX_GLOBAL_PLATFORM_H

#include "xxfclib/global/xx_global.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @brief True when the running processor supports SSE2. */
bool xx_global_platform_has_sse2(void);

/** @brief True when the running processor supports SSE4.2. */
bool xx_global_platform_has_sse42(void);

/** @brief True when the running processor supports AVX2. */
bool xx_global_platform_has_avx2(void);

/** @brief True when the running processor supports AES-NI. */
bool xx_global_platform_has_aes(void);

/** @brief True when the compiled SHA-NI backend can run on this processor. */
bool xx_global_platform_has_sha(void);

/** @brief True when the 256-bit VPCLMULQDQ CRC backend is usable. */
bool xx_global_platform_has_vpclmulqdq(void);

/** @brief True when the running Arm processor supports NEON/Advanced SIMD. */
bool xx_global_platform_has_neon(void);

/** @brief True when the running Arm processor supports CRC32 instructions. */
bool xx_global_platform_has_arm_crc32(void);

/** @brief True when the running Arm processor supports Armv8 AES/SHA crypto instructions. */
bool xx_global_platform_has_arm_crypto(void);

/** @brief True when the running Arm processor supports integer dot-product instructions. */
bool xx_global_platform_has_arm_dotprod(void);
bool xx_global_platform_has_arm_pmull(void);

/** @brief Detect stdout or stderr capability without leaving its mode changed. */
xx_terminal_type_t xx_global_platform_detect_terminal_type(bool standard_error);

#ifdef __cplusplus
}
#endif

#endif /* XX_GLOBAL_PLATFORM_H */
