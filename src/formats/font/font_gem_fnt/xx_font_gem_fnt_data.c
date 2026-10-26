/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * font gem fnt data structures, moved out of the fontbinary schema family. */
#include "../../xx_format_schema_fontbinary.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxfb_gem_font_header_le_fields[] = {
    SX_FIELD("font_id","int16",0,2,SX_ID),
    SX_FIELD("point_size","int16",2,2,SX_NONE),
    SX_FIELD("font_name","char[32]",4,32,SX_STRING),
    SX_FIELD("first_character","uint16",36,2,SX_ID),
    SX_FIELD("last_character","uint16",38,2,SX_ID),
    SX_FIELD("top","uint16",40,2,SX_NONE),
    SX_FIELD("ascent","uint16",42,2,SX_NONE),
    SX_FIELD("half","uint16",44,2,SX_NONE),
    SX_FIELD("descent","uint16",46,2,SX_NONE),
    SX_FIELD("bottom","uint16",48,2,SX_NONE),
    SX_FIELD("maximum_character_width","uint16",50,2,SX_COUNT_PROP),
    SX_FIELD("maximum_cell_width","uint16",52,2,SX_COUNT_PROP),
    SX_FIELD("left_skew_offset","uint16",54,2,SX_NONE),
    SX_FIELD("right_skew_offset","uint16",56,2,SX_NONE),
    SX_FIELD("thicken","uint16",58,2,SX_NONE),
    SX_FIELD("underline_height","uint16",60,2,SX_COUNT_PROP),
    SX_FIELD("lighten_mask","uint16",62,2,SX_FLAGS),
    SX_FIELD("skew_mask","uint16",64,2,SX_FLAGS),
    SX_FIELD("flags","uint16",66,2,SX_FLAGS),
    SX_FIELD("horizontal_table_offset","uint32",68,4,SX_OFFSET),
    SX_FIELD("glyph_offset_table_offset","uint32",72,4,SX_OFFSET),
    SX_FIELD("bitmap_offset","uint32",76,4,SX_OFFSET),
    SX_FIELD("form_width_bytes","uint16",80,2,SX_SIZE),
    SX_FIELD("form_height_lines","uint16",82,2,SX_COUNT_PROP),
    SX_FIELD("next_font_pointer","uint32",84,4,SX_POINTER),
};
const sx_layout sxfb_gem_font_header_le = {UINT32_C(0x60190019),"gem_font_header_le",sxfb_gem_font_header_le_fields,SX_COUNT(sxfb_gem_font_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_gem_glyph_bit_position_le_fields[] = {
    SX_FIELD("bit_position","uint16",0,2,SX_NONE),
};
const sx_layout sxfb_gem_glyph_bit_position_le = {UINT32_C(0x6019001a),"gem_glyph_bit_position_le",sxfb_gem_glyph_bit_position_le_fields,SX_COUNT(sxfb_gem_glyph_bit_position_le_fields),SX_LE};
static const xx_data_struct_field_desc sxfb_gem_font_header_be_fields[] = {
    SX_FIELD("font_id","int16",0,2,SX_ID),
    SX_FIELD("point_size","int16",2,2,SX_NONE),
    SX_FIELD("font_name","char[32]",4,32,SX_STRING),
    SX_FIELD("first_character","uint16",36,2,SX_ID),
    SX_FIELD("last_character","uint16",38,2,SX_ID),
    SX_FIELD("top","uint16",40,2,SX_NONE),
    SX_FIELD("ascent","uint16",42,2,SX_NONE),
    SX_FIELD("half","uint16",44,2,SX_NONE),
    SX_FIELD("descent","uint16",46,2,SX_NONE),
    SX_FIELD("bottom","uint16",48,2,SX_NONE),
    SX_FIELD("maximum_character_width","uint16",50,2,SX_COUNT_PROP),
    SX_FIELD("maximum_cell_width","uint16",52,2,SX_COUNT_PROP),
    SX_FIELD("left_skew_offset","uint16",54,2,SX_NONE),
    SX_FIELD("right_skew_offset","uint16",56,2,SX_NONE),
    SX_FIELD("thicken","uint16",58,2,SX_NONE),
    SX_FIELD("underline_height","uint16",60,2,SX_COUNT_PROP),
    SX_FIELD("lighten_mask","uint16",62,2,SX_FLAGS),
    SX_FIELD("skew_mask","uint16",64,2,SX_FLAGS),
    SX_FIELD("flags","uint16",66,2,SX_FLAGS),
    SX_FIELD("horizontal_table_offset","uint32",68,4,SX_OFFSET),
    SX_FIELD("glyph_offset_table_offset","uint32",72,4,SX_OFFSET),
    SX_FIELD("bitmap_offset","uint32",76,4,SX_OFFSET),
    SX_FIELD("form_width_bytes","uint16",80,2,SX_SIZE),
    SX_FIELD("form_height_lines","uint16",82,2,SX_COUNT_PROP),
    SX_FIELD("next_font_pointer","uint32",84,4,SX_POINTER),
};
const sx_layout sxfb_gem_font_header_be = {UINT32_C(0x6019001b),"gem_font_header_be",sxfb_gem_font_header_be_fields,SX_COUNT(sxfb_gem_font_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gem_glyph_bit_position_be_fields[] = {
    SX_FIELD("bit_position","uint16",0,2,SX_NONE),
};
const sx_layout sxfb_gem_glyph_bit_position_be = {UINT32_C(0x6019001c),"gem_glyph_bit_position_be",sxfb_gem_glyph_bit_position_be_fields,SX_COUNT(sxfb_gem_glyph_bit_position_be_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gem_horizontal_offsets_fields[] = {
    SX_FIELD("encoded_offsets","uint8[2]",0,2,SX_NONE),
};
const sx_layout sxfb_gem_horizontal_offsets = {UINT32_C(0x6019001d),"gem_horizontal_offsets",sxfb_gem_horizontal_offsets_fields,SX_COUNT(sxfb_gem_horizontal_offsets_fields),SX_BE};
static bool sxfb_gem_header(sx_context *c,const uint8_t *h,bool be)
{
 uint32_t first=sxfb16(h+36,be),last=sxfb16(h+38,be),point=sxfb16(h+2,be),flags=sxfb16(h+66,be),width=sxfb16(h+80,be),height=sxfb16(h+82,be),off=sxfb32(h+72,be),data=sxfb32(h+76,be);
 return point>0&&point<256&&first<=last&&last<256&&!(flags&~15U)&&width&&height&&height<=8192&&off>=88&&data>=88&&!sxfb32(h+84,be)&&sxfb_span(c,off,(uint64_t)(last-first+2)*2)&&sxfb_span(c,data,(uint64_t)width*height);
}
static bool sxfb_gem(sx_context *c)
{
 uint8_t h[88];if(!sxfb_read(c,0,h,88))return false;bool be=false;if(!sxfb_gem_header(c,h,false)){be=true;if(!sxfb_gem_header(c,h,true))return false;}
 if(!sxfb_add(c,be?&sxfb_gem_font_header_be:&sxfb_gem_font_header_le,0))return false;uint32_t count=sxfb16(h+38,be)-sxfb16(h+36,be)+1,hor=sxfb32(h+68,be),off=sxfb32(h+72,be),data=sxfb32(h+76,be);
 if(off<88||(uint64_t)off+(count+1)*2!=data)return true;
 if(sxfb16(h+66,be)&2){if(hor<88||(uint64_t)hor+count*2!=off)return true;if(!sx_table(c,&sxfb_gem_horizontal_offsets,hor,2,count))return false;}
 return sx_table(c,be?&sxfb_gem_glyph_bit_position_be:&sxfb_gem_glyph_bit_position_le,off,2,count+1);
}
bool sx_font_gem_fnt_build(sx_context*c)
{
 return sxfb_gem(c);
}
