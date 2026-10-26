/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * gif data structures, moved out of the image schema family. */
#include "../../xx_format_schema_image.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxi_gif_header_fields[] = {
    SX_FIELD("signature", "char[3]", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "char[3]", 3, 3, SX_ID),
};
const sx_layout sxi_gif_header = { UINT32_C(0x60010017), "GIF_HEADER", sxi_gif_header_fields, SX_COUNT(sxi_gif_header_fields), SX_LE };
static const xx_data_struct_field_desc sxi_gif_extension_fields[] = {
    SX_FIELD("extension_introducer", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("extension_label", "uint8", 1, 1, SX_ID),
};
const sx_layout sxi_gif_extension = { UINT32_C(0x6001001A), "GIF_EXTENSION_HEADER", sxi_gif_extension_fields, SX_COUNT(sxi_gif_extension_fields), SX_LE };
static const xx_data_struct_field_desc sxi_gif_application_fields[] = {
    SX_FIELD("extension_introducer", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("application_label", "uint8", 1, 1, SX_ID),
    SX_FIELD("block_size", "uint8", 2, 1, SX_SIZE),
    SX_FIELD("application_identifier", "char[8]", 3, 8, SX_ID),
    SX_FIELD("application_authentication_code", "uint8[3]", 11, 3, SX_ID),
};
const sx_layout sxi_gif_application = { UINT32_C(0x6001001C), "GIF_APPLICATION_EXTENSION", sxi_gif_application_fields, SX_COUNT(sxi_gif_application_fields), SX_LE };
static const xx_data_struct_field_desc sxi_gif_text_fields[] = {
    SX_FIELD("extension_introducer", "uint8", 0, 1, SX_SIGNATURE),
    SX_FIELD("plain_text_label", "uint8", 1, 1, SX_ID),
    SX_FIELD("block_size", "uint8", 2, 1, SX_SIZE),
    SX_FIELD("text_grid_left_position", "uint16", 3, 2, SX_NONE),
    SX_FIELD("text_grid_top_position", "uint16", 5, 2, SX_NONE),
    SX_FIELD("text_grid_width", "uint16", 7, 2, SX_NONE),
    SX_FIELD("text_grid_height", "uint16", 9, 2, SX_NONE),
    SX_FIELD("character_cell_width", "uint8", 11, 1, SX_NONE),
    SX_FIELD("character_cell_height", "uint8", 12, 1, SX_NONE),
    SX_FIELD("text_foreground_color_index", "uint8", 13, 1, SX_NONE),
    SX_FIELD("text_background_color_index", "uint8", 14, 1, SX_NONE),
};
const sx_layout sxi_gif_text = { UINT32_C(0x6001001D), "GIF_PLAIN_TEXT_EXTENSION", sxi_gif_text_fields, SX_COUNT(sxi_gif_text_fields), SX_LE };
static const xx_data_struct_field_desc sxi_gif_subblock_fields[] = {
    SX_FIELD("block_size", "uint8", 0, 1, SX_SIZE),
};
const sx_layout sxi_gif_subblock = { UINT32_C(0x6001001E), "GIF_DATA_SUB_BLOCK_HEADER", sxi_gif_subblock_fields, SX_COUNT(sxi_gif_subblock_fields), SX_LE };
static const xx_data_struct_field_desc sxi_gif_lzw_fields[] = {
    SX_FIELD("lzw_minimum_code_size", "uint8", 0, 1, SX_NONE),
};
const sx_layout sxi_gif_lzw = { UINT32_C(0x6001001F), "GIF_LZW_MINIMUM_CODE_SIZE", sxi_gif_lzw_fields, SX_COUNT(sxi_gif_lzw_fields), SX_LE };
static const xx_data_struct_field_desc sxi_gif_trailer_fields[] = {
    SX_FIELD("trailer", "uint8", 0, 1, SX_SIGNATURE),
};
const sx_layout sxi_gif_trailer = { UINT32_C(0x60010020), "GIF_TRAILER", sxi_gif_trailer_fields, SX_COUNT(sxi_gif_trailer_fields), SX_LE };
static bool sx_image_gif_subblocks(sx_context *c, int64_t *at)
{
    unsigned count = 0;
    while (++count <= 100000U) {
        uint8_t n;
        if (!sx_read(c, *at, &n, 1) || !sx_add(c, &sxi_gif_subblock, *at, 1)) return false;
        ++*at;
        if (!n) return true;
        if (!sx_raw(c, *at, n)) return false;
        *at += n;
    }
    return false;
}
static bool sx_image_gif(sx_context *c)
{
    uint8_t h[13];
    int64_t at = 13;
    unsigned blocks = 0;
    if (!sx_read(c, 0, h, 13) || (xx_rt_memcmp(h, "GIF87a", 6) && xx_rt_memcmp(h, "GIF89a", 6)) ||
        !sx_add(c, &sxi_gif_header, 0, 6) || !sx_add(c, &sxi_gif_screen, 6, 7)) return false;
    if (h[10] & 0x80) {
        unsigned n = 2U << (h[10] & 7);
        if (!sx_table(c, &sxi_rgb, at, 3, n)) return false;
        at += (int64_t)n * 3;
    }
    while (++blocks <= 100000U) {
        uint8_t kind;
        if (!sx_read(c, at, &kind, 1)) return false;
        if (kind == 0x3b) return sx_add(c, &sxi_gif_trailer, at, 1);
        if (kind == 0x2c) {
            if (!sx_read(c, at, h, 10) || !sx_add(c, &sxi_gif_image, at, 10)) return false;
            at += 10;
            if (h[9] & 0x80) {
                unsigned n = 2U << (h[9] & 7);
                if (!sx_table(c, &sxi_rgb, at, 3, n)) return false;
                at += (int64_t)n * 3;
            }
            if (!sx_read(c, at, &kind, 1) || kind < 2 || kind > 8 || !sx_add(c, &sxi_gif_lzw, at, 1)) return false;
            ++at;
        } else if (kind == 0x21) {
            if (!sx_read(c, at, h, 3)) return false;
            if (h[1] == 0xf9) {
                if (h[2] != 4 || !sx_read(c, at + 7, &kind, 1) || kind || !sx_add(c, &sxi_gif_graphic, at, 8)) return false;
                at += 8;
                continue;
            }
            if (h[1] == 0xff) {
                if (h[2] != 11 || !sx_add(c, &sxi_gif_application, at, 14)) return false;
                at += 14;
            } else if (h[1] == 0x01) {
                if (h[2] != 12 || !sx_add(c, &sxi_gif_text, at, 15)) return false;
                at += 15;
            } else {
                if (!sx_add(c, &sxi_gif_extension, at, 2)) return false;
                at += 2;
            }
        } else return false;
        if (!sx_image_gif_subblocks(c, &at)) return false;
    }
    return false;
}
bool sx_gif_build(sx_context*c)
{
    return sx_image_gif(c);
}
