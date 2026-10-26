/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * png data structures, moved out of the image schema family. */
#include "../../xx_format_schema_image.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxi_png_signature_fields[] = {
    SX_FIELD("signature", "uint8[8]", 0, 8, SX_SIGNATURE),
};
const sx_layout sxi_png_signature = { UINT32_C(0x60010001), "PNG_SIGNATURE", sxi_png_signature_fields, SX_COUNT(sxi_png_signature_fields), SX_BE };
static const xx_data_struct_field_desc sxi_png_chunk_fields[] = {
    SX_FIELD("length", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("type", "char[4]", 4, 4, SX_ID),
};
const sx_layout sxi_png_chunk = { UINT32_C(0x60010002), "PNG_CHUNK_HEADER", sxi_png_chunk_fields, SX_COUNT(sxi_png_chunk_fields), SX_BE };
static const xx_data_struct_field_desc sxi_png_crc_fields[] = {
    SX_FIELD("crc", "uint32", 0, 4, SX_CHECKSUM),
};
const sx_layout sxi_png_crc = { UINT32_C(0x60010003), "PNG_CHUNK_CRC", sxi_png_crc_fields, SX_COUNT(sxi_png_crc_fields), SX_BE };
static const xx_data_struct_field_desc sxi_png_actl_fields[] = {
    SX_FIELD("num_frames", "uint32", 0, 4, SX_COUNT_PROP),
    SX_FIELD("num_plays", "uint32", 4, 4, SX_COUNT_PROP),
};
const sx_layout sxi_png_actl = { UINT32_C(0x60010005), "PNG_acTL", sxi_png_actl_fields, SX_COUNT(sxi_png_actl_fields), SX_BE };
static const xx_data_struct_field_desc sxi_png_fdat_fields[] = {
    SX_FIELD("sequence_number", "uint32", 0, 4, SX_NONE),
};
const sx_layout sxi_png_fdat = { UINT32_C(0x60010007), "PNG_fdAT_HEADER", sxi_png_fdat_fields, SX_COUNT(sxi_png_fdat_fields), SX_BE };
static const xx_data_struct_field_desc sxi_png_gama_fields[] = {
    SX_FIELD("image_gamma", "uint32", 0, 4, SX_NONE),
};
const sx_layout sxi_png_gama = { UINT32_C(0x6001000A), "PNG_gAMA", sxi_png_gama_fields, SX_COUNT(sxi_png_gama_fields), SX_BE };
static const xx_data_struct_field_desc sxi_png_chrm_fields[] = {
    SX_FIELD("white_point_x", "uint32", 0, 4, SX_NONE),
    SX_FIELD("white_point_y", "uint32", 4, 4, SX_NONE),
    SX_FIELD("red_x", "uint32", 8, 4, SX_NONE),
    SX_FIELD("red_y", "uint32", 12, 4, SX_NONE),
    SX_FIELD("green_x", "uint32", 16, 4, SX_NONE),
    SX_FIELD("green_y", "uint32", 20, 4, SX_NONE),
    SX_FIELD("blue_x", "uint32", 24, 4, SX_NONE),
    SX_FIELD("blue_y", "uint32", 28, 4, SX_NONE),
};
const sx_layout sxi_png_chrm = { UINT32_C(0x6001000B), "PNG_cHRM", sxi_png_chrm_fields, SX_COUNT(sxi_png_chrm_fields), SX_BE };
static const xx_data_struct_field_desc sxi_png_time_fields[] = {
    SX_FIELD("year", "uint16", 0, 2, SX_NONE),
    SX_FIELD("month", "uint8", 2, 1, SX_NONE),
    SX_FIELD("day", "uint8", 3, 1, SX_NONE),
    SX_FIELD("hour", "uint8", 4, 1, SX_NONE),
    SX_FIELD("minute", "uint8", 5, 1, SX_NONE),
    SX_FIELD("second", "uint8", 6, 1, SX_NONE),
};
const sx_layout sxi_png_time = { UINT32_C(0x6001000D), "PNG_tIME", sxi_png_time_fields, SX_COUNT(sxi_png_time_fields), SX_BE };
static bool sx_image_png(sx_context *c)
{
    uint8_t h[8];
    int64_t at = 8;
    unsigned chunks = 0;
    bool have_ihdr = false, have_idat = false;
    if (!sx_read(c, 0, h, 8) || xx_rt_memcmp(h, "\x89PNG\r\n\x1a\n", 8) || !sx_add(c, &sxi_png_signature, 0, 8)) return false;
    while (sx_image_range(c, at, 12) && ++chunks <= 100000U) {
        uint32_t n;
        int64_t data = at + 8;
        const sx_layout *layout = NULL;
        int64_t fixed = 0;
        if (!sx_read(c, at, h, 8) || !sx_u32(c, at, true, &n) || n > INT32_MAX || !sx_image_range(c, at, (uint64_t)n + 12)) return false;
        if (!sx_add(c, &sxi_png_chunk, at, 8)) return false;
        if (!xx_rt_memcmp(h + 4, "IHDR", 4)) {
            if (have_ihdr || chunks != 1 || n != 13) return false;
            have_ihdr = true;
            layout = &sxi_png_ihdr;
            fixed = 13;
        } else if (!have_ihdr) return false;
        else if (!xx_rt_memcmp(h + 4, "acTL", 4)) { layout = &sxi_png_actl; fixed = 8; }
        else if (!xx_rt_memcmp(h + 4, "fcTL", 4)) { layout = &sxi_png_fctl; fixed = 26; }
        else if (!xx_rt_memcmp(h + 4, "fdAT", 4)) {
            if (n < 4 || !sx_add(c, &sxi_png_fdat, data, 4) || !sx_raw(c, data + 4, (int64_t)n - 4)) return false;
        } else if (!xx_rt_memcmp(h + 4, "pHYs", 4)) { layout = &sxi_png_phys; fixed = 9; }
        else if (!xx_rt_memcmp(h + 4, "gAMA", 4)) { layout = &sxi_png_gama; fixed = 4; }
        else if (!xx_rt_memcmp(h + 4, "cHRM", 4)) { layout = &sxi_png_chrm; fixed = 32; }
        else if (!xx_rt_memcmp(h + 4, "sRGB", 4)) { layout = &sxi_png_srgb; fixed = 1; }
        else if (!xx_rt_memcmp(h + 4, "tIME", 4)) { layout = &sxi_png_time; fixed = 7; }
        else if (!xx_rt_memcmp(h + 4, "PLTE", 4)) {
            if (!n || n > 768 || n % 3 || !sx_table(c, &sxi_rgb, data, 3, n / 3)) return false;
        } else if (!xx_rt_memcmp(h + 4, "IDAT", 4)) {
            have_idat = true;
            if (!sx_raw(c, data, n)) return false;
        } else if (!xx_rt_memcmp(h + 4, "IEND", 4)) {
            return n == 0 && have_idat && sx_add(c, &sxi_png_crc, data, 4);
        } else if (!sx_raw(c, data, n)) return false;
        if (layout && (n != (uint32_t)fixed || !sx_add(c, layout, data, fixed))) return false;
        if (!sx_add(c, &sxi_png_crc, data + n, 4)) return false;
        at += (int64_t)n + 12;
    }
    return false;
}
bool sx_png_build(sx_context*c)
{
    return sx_image_png(c);
}
