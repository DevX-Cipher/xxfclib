/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#ifndef XX_PEF_STREAM_INTERNAL_H
#define XX_PEF_STREAM_INTERNAL_H
#include "xxfclib/formats/executable/pef/xx_pef.h"

/* Native parsing and import inspection validate the same string span. */
#define PEF_STRING_LIMIT 4096U

static inline bool pef_string_span(const uint8_t *loader, uint32_t loader_size, uint32_t strings_offset, uint32_t name_offset, size_t *length)
{
    uint64_t start;
    size_t i, available;
    if (!loader || !length || strings_offset > loader_size || name_offset >= loader_size - strings_offset) return false;
    start = (uint64_t)strings_offset + name_offset;
    available = (size_t)(loader_size - start);
    if (available > PEF_STRING_LIMIT + 1U) available = PEF_STRING_LIMIT + 1U;
    for (i = 0U; i < available; ++i) {
        if (!loader[(size_t)start + i]) {
            if (!i) return false;
            *length = i;
            return true;
        }
    }
    return false;
}

#endif
