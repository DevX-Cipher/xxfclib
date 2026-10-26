/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BGEN data structures, moved out of the sciencewire schema family. */
#include "../../xx_format_schema_sciencewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsw_bgen_header_fields[] = {
    SX_FIELD("first_variant_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("header_size","uint32",4,4,SX_SIZE),
    SX_FIELD("variant_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("sample_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("signature","char[4]",16,4,SX_SIGNATURE),
};
const sx_layout sxsw_bgen_header = {UINT32_C(0x602d0018),"bgen_header",sxsw_bgen_header_fields,SX_COUNT(sxsw_bgen_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_bgen_flags_fields[] = {
    SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sxsw_bgen_flags = {UINT32_C(0x602d0019),"bgen_flags",sxsw_bgen_flags_fields,SX_COUNT(sxsw_bgen_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_bgen_sample_header_fields[] = {
    SX_FIELD("block_size","uint32",0,4,SX_SIZE),
    SX_FIELD("sample_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxsw_bgen_sample_header = {UINT32_C(0x602d001a),"bgen_sample_header",sxsw_bgen_sample_header_fields,SX_COUNT(sxsw_bgen_sample_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_bgen_string16_fields[] = {
    SX_FIELD("string_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxsw_bgen_string16 = {UINT32_C(0x602d001b),"bgen_string16",sxsw_bgen_string16_fields,SX_COUNT(sxsw_bgen_string16_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_bgen_string32_fields[] = {
    SX_FIELD("string_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxsw_bgen_string32 = {UINT32_C(0x602d001c),"bgen_string32",sxsw_bgen_string32_fields,SX_COUNT(sxsw_bgen_string32_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_bgen_variant_sample_count_fields[] = {
    SX_FIELD("sample_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxsw_bgen_variant_sample_count = {UINT32_C(0x602d001d),"bgen_variant_sample_count",sxsw_bgen_variant_sample_count_fields,SX_COUNT(sxsw_bgen_variant_sample_count_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_bgen_variant_position_fields[] = {
    SX_FIELD("position","uint32",0,4,SX_NONE),
};
const sx_layout sxsw_bgen_variant_position = {UINT32_C(0x602d001e),"bgen_variant_position",sxsw_bgen_variant_position_fields,SX_COUNT(sxsw_bgen_variant_position_fields),SX_LE};
static bool sxsw_bgen_string(sx_context *c,int64_t *at,bool wide)
{
 uint32_t n;if(wide){if(!sx_u32(c,*at,false,&n))return false;}else{uint16_t x;if(!sx_u16(c,*at,false,&x))return false;n=x;}
 unsigned width=wide?4:2;if(!sxsw_add(c,wide?&sxsw_bgen_string32:&sxsw_bgen_string16,*at,width)||!sxsw_span(c,*at+width,n))return false;*at+=width+n;return true;
}
static bool sxsw_bgen(sx_context *c)
{
 uint8_t b[20];if(!sx_read(c,0,b,20))return false;uint32_t offset=sxsw32(b,false),header=sxsw32(b+4,false),variants=sxsw32(b+8,false),samples=sxsw32(b+12,false),flags;int64_t at=(int64_t)header+4;
 if(!sxsw_add(c,&sxsw_bgen_header,0,20)||!sx_u32(c,header,false,&flags)||!sxsw_add(c,&sxsw_bgen_flags,header,4))return false;
 if(flags&0x80000000U){uint32_t count;if(!sx_u32(c,at+4,false,&count)||count!=samples||!sxsw_add(c,&sxsw_bgen_sample_header,at,8))return false;at+=8;for(uint32_t i=0;i<count;i++)if(!sxsw_bgen_string(c,&at,false))return false;}
 at=(int64_t)offset+4;if(variants>1024||samples>1000000)return false;
 for(uint32_t i=0;i<variants;i++){if(!sxsw_add(c,&sxsw_bgen_variant_sample_count,at,4))return false;at+=4;for(unsigned j=0;j<3;j++)if(!sxsw_bgen_string(c,&at,false))return false;
  if(!sxsw_add(c,&sxsw_bgen_variant_position,at,4))return false;at+=4;
  for(unsigned j=0;j<2;j++)if(!sxsw_bgen_string(c,&at,true))return false;
  if(!sxsw_span(c,at,(uint64_t)samples*6))return false;at+=(int64_t)samples*6;
 }return at==c->size;
}
bool sx_genomics_bgen_build(sx_context*c)
{
 return sxsw_bgen(c);
}
