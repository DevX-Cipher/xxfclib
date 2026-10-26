/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * font_bmfont data structures, moved out of the media schema family. */
#include "../../xx_format_schema_media.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxm_bmfont_header_fields[] = {
    SX_FIELD("magic", "char[3]", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 3, 1, SX_ID),
};
const sx_layout sxm_bmfont_header = {UINT32_C(0x60060028), "bmfont_header", sxm_bmfont_header_fields, SX_COUNT(sxm_bmfont_header_fields), SX_LE};
static const xx_data_struct_field_desc sxm_bmfont_block_fields[] = {
    SX_FIELD("type", "uint8", 0, 1, SX_ID),
    SX_FIELD("size", "uint32", 1, 4, SX_SIZE),
};
const sx_layout sxm_bmfont_block = {UINT32_C(0x60060029), "bmfont_block", sxm_bmfont_block_fields, SX_COUNT(sxm_bmfont_block_fields), SX_LE};
static const xx_data_struct_field_desc sxm_bmfont_info_fields[] = {
    SX_FIELD("font_size", "int16", 0, 2, SX_NONE),
    SX_FIELD("bit_field", "uint8", 2, 1, SX_FLAGS),
    SX_FIELD("charset", "uint8", 3, 1, SX_ID),
    SX_FIELD("stretch_height_percent", "uint16", 4, 2, SX_NONE),
    SX_FIELD("antialiasing", "uint8", 6, 1, SX_NONE),
    SX_FIELD("padding_up", "uint8", 7, 1, SX_NONE),
    SX_FIELD("padding_right", "uint8", 8, 1, SX_NONE),
    SX_FIELD("padding_down", "uint8", 9, 1, SX_NONE),
    SX_FIELD("padding_left", "uint8", 10, 1, SX_NONE),
    SX_FIELD("spacing_horizontal", "uint8", 11, 1, SX_NONE),
    SX_FIELD("spacing_vertical", "uint8", 12, 1, SX_NONE),
    SX_FIELD("outline", "uint8", 13, 1, SX_NONE),
};
const sx_layout sxm_bmfont_info = {UINT32_C(0x6006002A), "bmfont_info", sxm_bmfont_info_fields, SX_COUNT(sxm_bmfont_info_fields), SX_LE};
static const xx_data_struct_field_desc sxm_bmfont_common_fields[] = {
    SX_FIELD("line_height", "uint16", 0, 2, SX_NONE),
    SX_FIELD("base", "uint16", 2, 2, SX_NONE),
    SX_FIELD("scale_width", "uint16", 4, 2, SX_NONE),
    SX_FIELD("scale_height", "uint16", 6, 2, SX_NONE),
    SX_FIELD("pages", "uint16", 8, 2, SX_COUNT_PROP),
    SX_FIELD("bit_field", "uint8", 10, 1, SX_FLAGS),
    SX_FIELD("alpha_channel", "uint8", 11, 1, SX_NONE),
    SX_FIELD("red_channel", "uint8", 12, 1, SX_NONE),
    SX_FIELD("green_channel", "uint8", 13, 1, SX_NONE),
    SX_FIELD("blue_channel", "uint8", 14, 1, SX_NONE),
};
const sx_layout sxm_bmfont_common = {UINT32_C(0x6006002B), "bmfont_common", sxm_bmfont_common_fields, SX_COUNT(sxm_bmfont_common_fields), SX_LE};
static const xx_data_struct_field_desc sxm_bmfont_char_fields[] = {
    SX_FIELD("id", "uint32", 0, 4, SX_ID),
    SX_FIELD("x", "uint16", 4, 2, SX_NONE),
    SX_FIELD("y", "uint16", 6, 2, SX_NONE),
    SX_FIELD("width", "uint16", 8, 2, SX_NONE),
    SX_FIELD("height", "uint16", 10, 2, SX_NONE),
    SX_FIELD("x_offset", "int16", 12, 2, SX_NONE),
    SX_FIELD("y_offset", "int16", 14, 2, SX_NONE),
    SX_FIELD("x_advance", "int16", 16, 2, SX_NONE),
    SX_FIELD("page", "uint8", 18, 1, SX_NONE),
    SX_FIELD("channel", "uint8", 19, 1, SX_FLAGS),
};
const sx_layout sxm_bmfont_char = {UINT32_C(0x6006002C), "bmfont_char", sxm_bmfont_char_fields, SX_COUNT(sxm_bmfont_char_fields), SX_LE};
static const xx_data_struct_field_desc sxm_bmfont_kerning_fields[] = {
    SX_FIELD("first", "uint32", 0, 4, SX_ID),
    SX_FIELD("second", "uint32", 4, 4, SX_ID),
    SX_FIELD("amount", "int16", 8, 2, SX_NONE),
};
const sx_layout sxm_bmfont_kerning = {UINT32_C(0x6006002D), "bmfont_kerning", sxm_bmfont_kerning_fields, SX_COUNT(sxm_bmfont_kerning_fields), SX_LE};
static bool sxm_bmfont(sx_context *c,const uint8_t *h)
{
    uint64_t at=4;
    if(xx_rt_memcmp(h,"BMF\3",4)||!sx_add(c,&sxm_bmfont_header,0,4))return false;
    while(at<(uint64_t)c->size){uint8_t b[5];uint32_t n;uint64_t data;
        if(!sx_read(c,(int64_t)at,b,5))return false;n=xx_data_get_u32(b,5,1,false);data=at+5;
        if(!sxm_span(c,data,n)||!sx_add(c,&sxm_bmfont_block,(int64_t)at,5))return false;
        if(b[0]==1){if(n<14||!sx_add(c,&sxm_bmfont_info,(int64_t)data,14)||!sxm_raw(c,data+14,n-14))return false;}
        else if(b[0]==2){if(n!=15||!sx_add(c,&sxm_bmfont_common,(int64_t)data,15))return false;}
        else if(b[0]==4){if(n%20||!sx_table(c,&sxm_bmfont_char,(int64_t)data,20,n/20))return false;}
        else if(b[0]==5){if(n%10||!sx_table(c,&sxm_bmfont_kerning,(int64_t)data,10,n/10))return false;}
        else if(!sxm_raw(c,data,n))return false;
        at=data+n;
    }
    return true;
}
bool sx_font_bmfont_build(sx_context*c,uint8_t*h,size_t n)
{
 return n>=4&&sxm_bmfont(c,h);
}
