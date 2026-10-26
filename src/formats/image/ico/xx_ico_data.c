/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ico data structures, moved out of the image schema family. */
#include "../../xx_format_schema_image.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sx_image_ico(sx_context *c)
{
    uint16_t reserved, type, count;
    uint32_t i;
    if (!sx_u16(c, 0, false, &reserved) || reserved || !sx_u16(c, 2, false, &type) || (type != 1 && type != 2) ||
        !sx_u16(c, 4, false, &count) || !count || count > 4096 || !sx_image_range(c, 6, (uint64_t)count * 16) ||
        !sx_add(c, &sxi_ico_header, 0, 6)) return false;
    for (i = 0; i < count; ++i) {
        int64_t at = 6 + (int64_t)i * 16;
        uint32_t size, off;
        if (!sx_u32(c, at + 8, false, &size) || !sx_u32(c, at + 12, false, &off) || off < 6U + (uint32_t)count * 16U || !size ||
            !sx_add(c, type == 2 ? &sxi_cur_entry : &sxi_ico_entry, at, 16) || !sx_raw(c, off, size)) return false;
    }
    return true;
}
bool sx_ico_build(sx_context*c)
{
    return sx_image_ico(c);
}
