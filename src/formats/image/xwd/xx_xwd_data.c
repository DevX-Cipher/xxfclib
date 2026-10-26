/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * xwd data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_xwd_header_fields[] = {
    SX_FIELD("header_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("version", "uint32", 4, 4, SX_ID),
    SX_FIELD("pixmap_format", "uint32", 8, 4, SX_ID),
    SX_FIELD("pixmap_depth", "uint32", 12, 4, SX_NONE),
    SX_FIELD("pixmap_width", "uint32", 16, 4, SX_NONE),
    SX_FIELD("pixmap_height", "uint32", 20, 4, SX_NONE),
    SX_FIELD("x_offset", "uint32", 24, 4, SX_NONE),
    SX_FIELD("byte_order", "uint32", 28, 4, SX_ID),
    SX_FIELD("bitmap_unit", "uint32", 32, 4, SX_NONE),
    SX_FIELD("bitmap_bit_order", "uint32", 36, 4, SX_ID),
    SX_FIELD("bitmap_pad", "uint32", 40, 4, SX_NONE),
    SX_FIELD("bits_per_pixel", "uint32", 44, 4, SX_NONE),
    SX_FIELD("bytes_per_line", "uint32", 48, 4, SX_SIZE),
    SX_FIELD("visual_class", "uint32", 52, 4, SX_ID),
    SX_FIELD("red_mask", "uint32", 56, 4, SX_FLAGS),
    SX_FIELD("green_mask", "uint32", 60, 4, SX_FLAGS),
    SX_FIELD("blue_mask", "uint32", 64, 4, SX_FLAGS),
    SX_FIELD("bits_per_rgb", "uint32", 68, 4, SX_NONE),
    SX_FIELD("colormap_entries", "uint32", 72, 4, SX_COUNT_PROP),
    SX_FIELD("color_count", "uint32", 76, 4, SX_COUNT_PROP),
    SX_FIELD("window_width", "uint32", 80, 4, SX_NONE),
    SX_FIELD("window_height", "uint32", 84, 4, SX_NONE),
    SX_FIELD("window_x", "uint32", 88, 4, SX_NONE),
    SX_FIELD("window_y", "uint32", 92, 4, SX_NONE),
    SX_FIELD("window_border_width", "uint32", 96, 4, SX_NONE),
};
const sx_layout sxm_xwd_header = {UINT32_C(0x60060020), "xwd_header", sxm_xwd_header_fields, SX_COUNT(sxm_xwd_header_fields), SX_BE};
static const xx_data_struct_field_desc sxm_xwd_color_fields[] = {
    SX_FIELD("pixel", "uint32", 0, 4, SX_NONE),
    SX_FIELD("red", "uint16", 4, 2, SX_NONE),
    SX_FIELD("green", "uint16", 6, 2, SX_NONE),
    SX_FIELD("blue", "uint16", 8, 2, SX_NONE),
    SX_FIELD("flags", "uint8", 10, 1, SX_FLAGS),
    SX_FIELD("pad", "uint8", 11, 1, SX_RESERVED),
};
const sx_layout sxm_xwd_color = {UINT32_C(0x60060021), "xwd_color", sxm_xwd_color_fields, SX_COUNT(sxm_xwd_color_fields), SX_BE};
bool sx_xwd_build(sx_context*c,uint8_t*h,size_t n)
{
 uint32_t header,count;if(n<100||xx_data_get_u32(h,n,4,true)!=7)return false;header=xx_data_get_u32(h,n,0,true);count=xx_data_get_u32(h,n,76,true);return header>=100&&sx_add(c,&sxm_xwd_header,0,100)&&sxm_raw(c,100,header-100)&&sx_table(c,&sxm_xwd_color,header,12,count)&&sxm_tail(c,header+(uint64_t)count*12);
}
