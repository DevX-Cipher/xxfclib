/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#ifndef XX_CRC32_ARM_H
#define XX_CRC32_ARM_H

#include <stddef.h>
#include <stdint.h>

#if (defined(_M_ARM64) && !defined(_M_ARM64EC)) || defined(__aarch64__)
#define XX_CRC32_ARM 1

/* Uses the public seed/finalization convention. Callers must gate entry with
 * xx_is_arm_crc32_enabled() because these functions contain optional Armv8
 * CRC instructions. */
/* PMULL paths also require xx_is_arm_pmull_enabled(). */
uint32_t xx_crc32_arm_pmull(uint32_t crc, const void *data, size_t size);
uint32_t xx_crc32c_arm_pmull(uint32_t crc, const void *data, size_t size);

uint32_t xx_crc32_arm(uint32_t crc, const void *data, size_t size);
uint32_t xx_crc32c_arm(uint32_t crc, const void *data, size_t size);
uint32_t xx_crc32_mpeg2_arm(uint32_t reg, const void *data, size_t size);
#endif

#endif /* XX_CRC32_ARM_H */
