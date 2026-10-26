/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * tex pk data structures, moved out of the fontbinary schema family. */
#include "../../xx_format_schema_fontbinary.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxfb_pk_metrics_fields[] = {
    SX_FIELD("design_size","int32",0,4,SX_NONE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("horizontal_pixels_per_point","int32",8,4,SX_NONE),
    SX_FIELD("vertical_pixels_per_point","int32",12,4,SX_NONE),
};
const sx_layout sxfb_pk_metrics = {UINT32_C(0x6019002d),"pk_metrics",sxfb_pk_metrics_fields,SX_COUNT(sxfb_pk_metrics_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_pk_short_glyph_fields[] = {
    SX_FIELD("flag","uint8",0,1,SX_FLAGS),
    SX_FIELD("packet_size_low","uint8",1,1,SX_NONE),
    SX_FIELD("character_code","uint8",2,1,SX_ID),
    SX_FIELD("tfm_width","uint24",3,3,SX_NONE),
    SX_FIELD("dx","uint8",6,1,SX_NONE),
    SX_FIELD("width_pixels","uint8",7,1,SX_COUNT_PROP),
    SX_FIELD("height_pixels","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("horizontal_offset","int8",9,1,SX_NONE),
    SX_FIELD("vertical_offset","int8",10,1,SX_NONE),
};
const sx_layout sxfb_pk_short_glyph = {UINT32_C(0x6019002e),"pk_short_glyph",sxfb_pk_short_glyph_fields,SX_COUNT(sxfb_pk_short_glyph_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_pk_extended_glyph_fields[] = {
    SX_FIELD("flag","uint8",0,1,SX_FLAGS),
    SX_FIELD("packet_size_low","uint16",1,2,SX_NONE),
    SX_FIELD("character_code","uint8",3,1,SX_ID),
    SX_FIELD("tfm_width","uint24",4,3,SX_NONE),
    SX_FIELD("dx","uint16",7,2,SX_NONE),
    SX_FIELD("width_pixels","uint16",9,2,SX_COUNT_PROP),
    SX_FIELD("height_pixels","uint16",11,2,SX_COUNT_PROP),
    SX_FIELD("horizontal_offset","int16",13,2,SX_NONE),
    SX_FIELD("vertical_offset","int16",15,2,SX_NONE),
};
const sx_layout sxfb_pk_extended_glyph = {UINT32_C(0x6019002f),"pk_extended_glyph",sxfb_pk_extended_glyph_fields,SX_COUNT(sxfb_pk_extended_glyph_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_pk_long_glyph_fields[] = {
    SX_FIELD("flag","uint8",0,1,SX_FLAGS),
    SX_FIELD("packet_size","int32",1,4,SX_SIZE),
    SX_FIELD("character_code","int32",5,4,SX_ID),
    SX_FIELD("tfm_width","int32",9,4,SX_NONE),
    SX_FIELD("dx","int32",13,4,SX_NONE),
    SX_FIELD("dy","int32",17,4,SX_NONE),
    SX_FIELD("width_pixels","int32",21,4,SX_COUNT_PROP),
    SX_FIELD("height_pixels","int32",25,4,SX_COUNT_PROP),
    SX_FIELD("horizontal_offset","int32",29,4,SX_NONE),
    SX_FIELD("vertical_offset","int32",33,4,SX_NONE),
};
const sx_layout sxfb_pk_long_glyph = {UINT32_C(0x60190030),"pk_long_glyph",sxfb_pk_long_glyph_fields,SX_COUNT(sxfb_pk_long_glyph_fields),SX_BE};
static bool sxfb_pk(sx_context *c)
{
 uint64_t p;if(!sxfb_preamble(c,89,&p)||!sxfb_span(c,p,16)||!sxfb_add(c,&sxfb_pk_metrics,p))return false;p+=16;
 for(unsigned step=0;p<(uint64_t)c->size&&step<20000;step++){uint8_t h[37];if(!sxfb_read(c,p,h,1))return false;unsigned op=h[0];
  if(op<240){unsigned form=op&7,size=form<4?11:form<7?17:37,at=form<4?3:form<7?4:9;if(!sxfb_read(c,p,h,size))break;
   uint64_t packet=form<4?(uint64_t)form*256+h[1]:form<7?(uint64_t)(form-4)*65536+sxfb16(h+1,true):sxfb32(h+1,true);
   if(packet<size-at||!sxfb_span(c,p,at+packet))break;if(!sxfb_add(c,form<4?&sxfb_pk_short_glyph:form<7?&sxfb_pk_extended_glyph:&sxfb_pk_long_glyph,p))return false;p+=at+packet;
  }else if(op<=243){if(!sxfb_special(c,&p,op-239))break;}
  else if(op==244){if(!sxfb_span(c,p,5))break;if(!sxfb_add(c,&sxfb_tex_numeric_special,p))return false;p+=5;}
  else if(op==245||op==246){if(!sxfb_add(c,&sxfb_tex_opcode,p++))return false;}
  else break;
 }return !c->failed;
}
bool sx_tex_pk_build(sx_context*c)
{
 return sxfb_pk(c);
}
