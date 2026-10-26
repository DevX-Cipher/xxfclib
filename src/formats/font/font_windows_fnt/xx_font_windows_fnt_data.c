/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * font windows fnt data structures, moved out of the fontbinary schema family. */
#include "../../xx_format_schema_fontbinary.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxfb_windows_fnt2_header_fields[] = {
    SX_FIELD("version","uint16",0,2,SX_ID),
    SX_FIELD("file_size","uint32",2,4,SX_SIZE),
    SX_FIELD("copyright","char[60]",6,60,SX_STRING),
    SX_FIELD("font_type","uint16",66,2,SX_FLAGS),
    SX_FIELD("point_size","uint16",68,2,SX_NONE),
    SX_FIELD("vertical_resolution","uint16",70,2,SX_NONE),
    SX_FIELD("horizontal_resolution","uint16",72,2,SX_NONE),
    SX_FIELD("ascent","uint16",74,2,SX_NONE),
    SX_FIELD("internal_leading","uint16",76,2,SX_NONE),
    SX_FIELD("external_leading","uint16",78,2,SX_NONE),
    SX_FIELD("italic","uint8",80,1,SX_FLAGS),
    SX_FIELD("underline","uint8",81,1,SX_FLAGS),
    SX_FIELD("strikeout","uint8",82,1,SX_FLAGS),
    SX_FIELD("weight","uint16",83,2,SX_NONE),
    SX_FIELD("character_set","uint8",85,1,SX_ID),
    SX_FIELD("pixel_width","uint16",86,2,SX_COUNT_PROP),
    SX_FIELD("pixel_height","uint16",88,2,SX_COUNT_PROP),
    SX_FIELD("pitch_and_family","uint8",90,1,SX_FLAGS),
    SX_FIELD("average_width","uint16",91,2,SX_COUNT_PROP),
    SX_FIELD("maximum_width","uint16",93,2,SX_COUNT_PROP),
    SX_FIELD("first_character","uint8",95,1,SX_ID),
    SX_FIELD("last_character","uint8",96,1,SX_ID),
    SX_FIELD("default_character_index","uint8",97,1,SX_ID),
    SX_FIELD("break_character_index","uint8",98,1,SX_ID),
    SX_FIELD("bytes_per_row","uint16",99,2,SX_SIZE),
    SX_FIELD("device_name_offset","uint32",101,4,SX_OFFSET),
    SX_FIELD("face_name_offset","uint32",105,4,SX_OFFSET),
    SX_FIELD("bits_pointer","uint32",109,4,SX_POINTER),
    SX_FIELD("bits_offset","uint32",113,4,SX_OFFSET),
    SX_FIELD("reserved","uint8",117,1,SX_RESERVED),
};
const sx_layout sxfb_windows_fnt2_header = {UINT32_C(0x60190015),"windows_fnt2_header",sxfb_windows_fnt2_header_fields,SX_COUNT(sxfb_windows_fnt2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_windows_fnt3_header_fields[] = {
    SX_FIELD("version","uint16",0,2,SX_ID),
    SX_FIELD("file_size","uint32",2,4,SX_SIZE),
    SX_FIELD("copyright","char[60]",6,60,SX_STRING),
    SX_FIELD("font_type","uint16",66,2,SX_FLAGS),
    SX_FIELD("point_size","uint16",68,2,SX_NONE),
    SX_FIELD("vertical_resolution","uint16",70,2,SX_NONE),
    SX_FIELD("horizontal_resolution","uint16",72,2,SX_NONE),
    SX_FIELD("ascent","uint16",74,2,SX_NONE),
    SX_FIELD("internal_leading","uint16",76,2,SX_NONE),
    SX_FIELD("external_leading","uint16",78,2,SX_NONE),
    SX_FIELD("italic","uint8",80,1,SX_FLAGS),
    SX_FIELD("underline","uint8",81,1,SX_FLAGS),
    SX_FIELD("strikeout","uint8",82,1,SX_FLAGS),
    SX_FIELD("weight","uint16",83,2,SX_NONE),
    SX_FIELD("character_set","uint8",85,1,SX_ID),
    SX_FIELD("pixel_width","uint16",86,2,SX_COUNT_PROP),
    SX_FIELD("pixel_height","uint16",88,2,SX_COUNT_PROP),
    SX_FIELD("pitch_and_family","uint8",90,1,SX_FLAGS),
    SX_FIELD("average_width","uint16",91,2,SX_COUNT_PROP),
    SX_FIELD("maximum_width","uint16",93,2,SX_COUNT_PROP),
    SX_FIELD("first_character","uint8",95,1,SX_ID),
    SX_FIELD("last_character","uint8",96,1,SX_ID),
    SX_FIELD("default_character_index","uint8",97,1,SX_ID),
    SX_FIELD("break_character_index","uint8",98,1,SX_ID),
    SX_FIELD("bytes_per_row","uint16",99,2,SX_SIZE),
    SX_FIELD("device_name_offset","uint32",101,4,SX_OFFSET),
    SX_FIELD("face_name_offset","uint32",105,4,SX_OFFSET),
    SX_FIELD("bits_pointer","uint32",109,4,SX_POINTER),
    SX_FIELD("bits_offset","uint32",113,4,SX_OFFSET),
    SX_FIELD("reserved","uint8",117,1,SX_RESERVED),
    SX_FIELD("flags","uint32",118,4,SX_FLAGS),
    SX_FIELD("a_space","uint16",122,2,SX_NONE),
    SX_FIELD("b_space","uint16",124,2,SX_NONE),
    SX_FIELD("c_space","uint16",126,2,SX_NONE),
    SX_FIELD("color_table_offset","uint32",128,4,SX_OFFSET),
    SX_FIELD("reserved1","uint32[4]",132,16,SX_RESERVED),
};
const sx_layout sxfb_windows_fnt3_header = {UINT32_C(0x60190016),"windows_fnt3_header",sxfb_windows_fnt3_header_fields,SX_COUNT(sxfb_windows_fnt3_header_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_windows_fnt2_glyph_fields[] = {
    SX_FIELD("pixel_width","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("bitmap_offset","uint16",2,2,SX_OFFSET),
};
const sx_layout sxfb_windows_fnt2_glyph = {UINT32_C(0x60190017),"windows_fnt2_glyph",sxfb_windows_fnt2_glyph_fields,SX_COUNT(sxfb_windows_fnt2_glyph_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_windows_fnt3_glyph_fields[] = {
    SX_FIELD("pixel_width","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("bitmap_offset","uint32",2,4,SX_OFFSET),
};
const sx_layout sxfb_windows_fnt3_glyph = {UINT32_C(0x60190018),"windows_fnt3_glyph",sxfb_windows_fnt3_glyph_fields,SX_COUNT(sxfb_windows_fnt3_glyph_fields),SX_LE};
static bool sxfb_windows(sx_context *c)
{
 uint8_t h[148];if(!sxfb_read(c,0,h,118))return false;uint32_t version=sxfb16(h,false),size=version==0x200?118:version==0x300?148:0;
 if(!size||!sxfb_read(c,0,h,size)||!sxfb_add(c,size==118?&sxfb_windows_fnt2_header:&sxfb_windows_fnt3_header,0))return false;
 if(h[96]<h[95])return true;uint32_t count=(uint32_t)h[96]-h[95]+2,entry=size==118?4:6;
 if(sxfb_span(c,size,(uint64_t)entry*count)&&!sx_table(c,size==118?&sxfb_windows_fnt2_glyph:&sxfb_windows_fnt3_glyph,size,entry,count))return false;return true;
}
bool sx_font_windows_fnt_build(sx_context*c)
{
 return sxfb_windows(c);
}
