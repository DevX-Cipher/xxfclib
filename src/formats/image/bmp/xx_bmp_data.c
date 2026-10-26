/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * bmp data structures, moved out of the image schema family. */
#include "../../xx_format_schema_image.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxi_bmp_file_fields[] = {
    SX_FIELD("bfType", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("bfSize", "uint32", 2, 4, SX_SIZE),
    SX_FIELD("bfReserved1", "uint16", 6, 2, SX_RESERVED),
    SX_FIELD("bfReserved2", "uint16", 8, 2, SX_RESERVED),
    SX_FIELD("bfOffBits", "uint32", 10, 4, SX_OFFSET),
};
const sx_layout sxi_bmp_file = { UINT32_C(0x6001000E), "BITMAPFILEHEADER", sxi_bmp_file_fields, SX_COUNT(sxi_bmp_file_fields), SX_LE };
static const xx_data_struct_field_desc sxi_bmp_core_fields[] = {
    SX_FIELD("bcSize", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("bcWidth", "uint16", 4, 2, SX_NONE),
    SX_FIELD("bcHeight", "uint16", 6, 2, SX_NONE),
    SX_FIELD("bcPlanes", "uint16", 8, 2, SX_COUNT_PROP),
    SX_FIELD("bcBitCount", "uint16", 10, 2, SX_NONE),
};
const sx_layout sxi_bmp_core = { UINT32_C(0x6001000F), "BITMAPCOREHEADER", sxi_bmp_core_fields, SX_COUNT(sxi_bmp_core_fields), SX_LE };
static const xx_data_struct_field_desc sxi_bmp_rgbtriple_fields[] = {
    SX_FIELD("rgbtBlue", "uint8", 0, 1, SX_NONE),
    SX_FIELD("rgbtGreen", "uint8", 1, 1, SX_NONE),
    SX_FIELD("rgbtRed", "uint8", 2, 1, SX_NONE),
};
const sx_layout sxi_bmp_rgbtriple = { UINT32_C(0x60010013), "RGBTRIPLE", sxi_bmp_rgbtriple_fields, SX_COUNT(sxi_bmp_rgbtriple_fields), SX_LE };
static const xx_data_struct_field_desc sxi_bmp_rgbquad_fields[] = {
    SX_FIELD("rgbBlue", "uint8", 0, 1, SX_NONE),
    SX_FIELD("rgbGreen", "uint8", 1, 1, SX_NONE),
    SX_FIELD("rgbRed", "uint8", 2, 1, SX_NONE),
    SX_FIELD("rgbReserved", "uint8", 3, 1, SX_RESERVED),
};
const sx_layout sxi_bmp_rgbquad = { UINT32_C(0x60010014), "RGBQUAD", sxi_bmp_rgbquad_fields, SX_COUNT(sxi_bmp_rgbquad_fields), SX_LE };
static const xx_data_struct_field_desc sxi_bmp_masks_fields[] = {
    SX_FIELD("red_mask", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("green_mask", "uint32", 4, 4, SX_FLAGS),
    SX_FIELD("blue_mask", "uint32", 8, 4, SX_FLAGS),
};
const sx_layout sxi_bmp_masks = { UINT32_C(0x60010015), "BITMAP_BITFIELDS", sxi_bmp_masks_fields, SX_COUNT(sxi_bmp_masks_fields), SX_LE };
static const xx_data_struct_field_desc sxi_bmp_alpha_masks_fields[] = {
    SX_FIELD("red_mask", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("green_mask", "uint32", 4, 4, SX_FLAGS),
    SX_FIELD("blue_mask", "uint32", 8, 4, SX_FLAGS),
    SX_FIELD("alpha_mask", "uint32", 12, 4, SX_FLAGS),
};
const sx_layout sxi_bmp_alpha_masks = { UINT32_C(0x60010016), "BITMAP_ALPHA_BITFIELDS", sxi_bmp_alpha_masks_fields, SX_COUNT(sxi_bmp_alpha_masks_fields), SX_LE };
static bool sx_image_bmp(sx_context *c)
{
    uint8_t magic[2];
    uint16_t bits;
    uint32_t length, pixels, dib, compression = 0, colors = 0;
    int64_t at, palette_size;
    const sx_layout *header, *color;
    if (!sx_read(c, 0, magic, 2) || xx_rt_memcmp(magic, "BM", 2) || !sx_u32(c, 2, false, &length) ||
        !sx_u32(c, 10, false, &pixels) || !sx_u32(c, 14, false, &dib) || length > (uint64_t)c->size || pixels > length) return false;
    if (dib == 12) { header = &sxi_bmp_core; color = &sxi_bmp_rgbtriple; palette_size = 3; }
    else if (dib == 40 || dib == 108 || dib == 124) {
        header = dib == 40 ? &sxi_bmp_info : dib == 108 ? &sxi_bmp_v4 : &sxi_bmp_v5;
        color = &sxi_bmp_rgbquad;
        palette_size = 4;
        if (!sx_u32(c, 30, false, &compression) || !sx_u32(c, 46, false, &colors)) return false;
    } else return false;
    if ((uint64_t)14 + dib > pixels || !sx_add(c, &sxi_bmp_file, 0, 14) || !sx_add(c, header, 14, dib) ||
        !sx_u16(c, dib == 12 ? 24 : 28, false, &bits)) return false;
    at = 14 + (int64_t)dib;
    if (dib == 40 && (compression == 3 || compression == 6)) {
        int64_t masks = compression == 6 ? 16 : 12;
        if ((uint64_t)at + (uint64_t)masks > pixels || !sx_add(c, compression == 6 ? &sxi_bmp_alpha_masks : &sxi_bmp_masks, at, masks)) return false;
        at += masks;
    }
    if (bits <= 8 && bits && !colors) colors = 1U << bits;
    if ((uint64_t)colors * (uint64_t)palette_size > (uint64_t)((int64_t)pixels - at) ||
        !sx_table(c, color, at, palette_size, colors)) return false;
    at += (int64_t)colors * palette_size;
    return sx_raw(c, at, (int64_t)pixels - at) && sx_raw(c, pixels, (int64_t)length - pixels);
}
bool sx_bmp_build(sx_context*c)
{
    return sx_image_bmp(c);
}
