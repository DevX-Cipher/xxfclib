/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#ifndef XX_REGEX_SEARCH_H
#define XX_REGEX_SEARCH_H

#include <stddef.h>

/* Find the first candidate whose bytes at 0 and offset match. Both reads
 * remain inside size, including vector loads and the final partial block.
 * This is only a necessary-condition filter; the matcher verifies candidates. */
const unsigned char *xx_regex_find_pair(const unsigned char *text, size_t size,
                                       unsigned char first, size_t offset,
                                       unsigned char second);

#endif
