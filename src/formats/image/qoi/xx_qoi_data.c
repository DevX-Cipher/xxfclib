/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * qoi data structures, moved out of the image schema family. */
#include "../../xx_format_schema_image.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxi_qoi_end_fields[] = {
    SX_FIELD("end_marker", "uint8[8]", 0, 8, SX_SIGNATURE),
};
const sx_layout sxi_qoi_end = { UINT32_C(0x60010025), "QOI_END_MARKER", sxi_qoi_end_fields, SX_COUNT(sxi_qoi_end_fields), SX_BE };
static bool sx_image_qoi(sx_context *c)
{
    uint8_t h[14], marker[8];
    uint32_t width, height;
    uint64_t remaining;
    int64_t at = 14;
    sxi_cursor cursor = {c, -1, 0, {0}};
    if (!sx_read(c, 0, h, 14) || xx_rt_memcmp(h, "qoif", 4) || (h[12] != 3 && h[12] != 4) || h[13] > 1 ||
        !sx_u32(c, 4, true, &width) || !sx_u32(c, 8, true, &height) || !width || !height ||
        !sx_add(c, &sxi_qoi_header, 0, 14)) return false;
    remaining = (uint64_t)width * height;
    /* Follow opcode widths/runs to locate the end marker. A trailer following
     * the image must not be mistaken for image data or its terminator. */
    while (remaining) {
        uint8_t op;
        unsigned bytes = 1, pixels = 1;
        if (!sxi_byte(&cursor, at, &op)) return false;
        if (op == 0xfe) bytes = 4;
        else if (op == 0xff) bytes = 5;
        else if ((op & 0xc0) == 0x80) bytes = 2;
        else if ((op & 0xc0) == 0xc0) pixels = (op & 0x3f) + 1U;
        if (pixels > remaining || !sx_image_range(c, at, bytes)) return false;
        at += bytes;
        remaining -= pixels;
    }
    if (!sx_read(c, at, marker, 8) || xx_rt_memcmp(marker, "\0\0\0\0\0\0\0\1", 8)) return false;
    return sx_raw(c, 14, at - 14) && sx_add(c, &sxi_qoi_end, at, 8);
}
bool sx_qoi_build(sx_context*c)
{
    return sx_image_qoi(c);
}
