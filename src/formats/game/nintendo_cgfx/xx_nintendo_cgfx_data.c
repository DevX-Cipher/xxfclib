/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo cgfx data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_cgfx_slot_fields[]={
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("dictionary_relative","int32",4,4,SX_OFFSET),
};
const sx_layout sxmx_cgfx_slot={UINT32_C(0x602E004D),"cgfx_slot",sxmx_cgfx_slot_fields,SX_COUNT(sxmx_cgfx_slot_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_cgfx_dictionary_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("dictionary_size","uint32",4,4,SX_SIZE),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxmx_cgfx_dictionary={UINT32_C(0x602E004E),"cgfx_dictionary",sxmx_cgfx_dictionary_fields,SX_COUNT(sxmx_cgfx_dictionary_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_cgfx_node_fields[]={
 SX_FIELD("reference_bit","uint32",0,4,SX_NONE),
 SX_FIELD("left_index","uint16",4,2,SX_ID),
 SX_FIELD("right_index","uint16",6,2,SX_ID),
 SX_FIELD("name_relative","int32",8,4,SX_OFFSET),
 SX_FIELD("data_relative","int32",12,4,SX_OFFSET),
};
const sx_layout sxmx_cgfx_node={UINT32_C(0x602E004F),"cgfx_node",sxmx_cgfx_node_fields,SX_COUNT(sxmx_cgfx_node_fields),SX_LE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_cgfx(sxmx_view*v)
{if(!SM_ROW(cflyt_header_le,0,v->n)||!SM_ROW(section_le,20,v->n)||!sxmx_table(v,&sxmx_cgfx_slot,28,16,v->n))return false;size_t end=20+(size_t)sxmx_u32(v->p+24,false);if(end>v->n)return false;for(unsigned i=0;i<16;i++){size_t word=32+(size_t)i*8;if(sxmx_u32(v->p+word-4,false)){size_t at;if(!sxmx_relative(v,word,false,&at)||!SM_ROW(cgfx_dictionary,at,end))return false;uint32_t n=sxmx_u32(v->p+at+8,false);if(n>1024||!sxmx_table(v,&sxmx_cgfx_node,at+12,(uint64_t)n+1,end))return false;}}return sxmx_u32(v->p+16,false)!=2||SM_ROW(section_le,end,v->n);}
bool sx_nintendo_cgfx_build(sxmx_view*v)
{
 return sxmx_cgfx(v);
}
#undef SM_ROW
