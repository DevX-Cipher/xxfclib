/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * lmd container data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_lmd_header_fields[] = {
 SX_FIELD("signature_length","uint8",0,1,SX_SIZE),
 SX_FIELD("signature","char[8]",1,8,SX_SIGNATURE),
 SX_FIELD("record_count","uint32",9,4,SX_COUNT_PROP),
};
const sx_layout sxbx_lmd_header = {UINT32_C(0x60300003),"lmd_header",sxbx_lmd_header_fields,SX_COUNT(sxbx_lmd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lmd_record_offset_fields[] = {
 SX_FIELD("record_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxbx_lmd_record_offset = {UINT32_C(0x60300004),"lmd_record_offset",sxbx_lmd_record_offset_fields,SX_COUNT(sxbx_lmd_record_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lmd_flags_fields[] = {
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxbx_lmd_flags = {UINT32_C(0x60300005),"lmd_flags",sxbx_lmd_flags_fields,SX_COUNT(sxbx_lmd_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lmd_name_length_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxbx_lmd_name_length = {UINT32_C(0x60300006),"lmd_name_length",sxbx_lmd_name_length_fields,SX_COUNT(sxbx_lmd_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lmd_optional_value_fields[] = {
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
const sx_layout sxbx_lmd_optional_value = {UINT32_C(0x60300007),"lmd_optional_value",sxbx_lmd_optional_value_fields,SX_COUNT(sxbx_lmd_optional_value_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lmd_bitmap_size_fields[] = {
 SX_FIELD("bitmap_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxbx_lmd_bitmap_size = {UINT32_C(0x60300008),"lmd_bitmap_size",sxbx_lmd_bitmap_size_fields,SX_COUNT(sxbx_lmd_bitmap_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lmd_block_header_fields[] = {
 SX_FIELD("block_size","uint32",0,4,SX_SIZE),
 SX_FIELD("method","uint8",4,1,SX_ID),
};
const sx_layout sxbx_lmd_block_header = {UINT32_C(0x60300009),"lmd_block_header",sxbx_lmd_block_header_fields,SX_COUNT(sxbx_lmd_block_header_fields),SX_LE};
#define SXBX_LIMIT 20000U
static bool sxbx_lmd(sx_context*c){uint64_t n;if(!sxbx_add(c,&sxbx_lmd_header,0)||!sxbx_word(c,9,4,false,&n)||n>4096||!sxbx_span(c,13,n*4)||!sxbx_table(c,&sxbx_lmd_record_offset,13,n))return false;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++){uint64_t p,end=(uint64_t)c->size,flags,z;if(!sxbx_word(c,13+i*4,4,false,&p)||(i+1<n&&!sxbx_word(c,17+i*4,4,false,&end))||p<13+n*4||end<=p||end>(uint64_t)c->size||!sxbx_word(c,p,1,false,&flags)||!sxbx_add(c,&sxbx_lmd_flags,p))continue;p++;if(flags&2){if(!sxbx_counted(c,&p,end,&sxbx_lmd_name_length,1,false,1))continue;}if(flags&4){if(end-p<4||!sxbx_add(c,&sxbx_lmd_optional_value,p))continue;p+=4;}if(flags&8){if(end-p<4||!sxbx_word(c,p,4,false,&z)||z!=end-p-4||!sxbx_add(c,&sxbx_lmd_bitmap_size,p))continue;p+=4;if(flags&1)while(p<end&&c->count<SXBX_LIMIT){if(end-p<5||!sxbx_word(c,p,4,false,&z)||z<1||z>end-p-4)break;if(!sxbx_add(c,&sxbx_lmd_block_header,p))return false;p+=4+z;}}}return true;}
bool sx_lmd_container_build(sx_context*c)
{
 return sxbx_lmd(c);
}
