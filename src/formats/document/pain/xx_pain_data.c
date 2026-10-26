/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PAIN documents data structures, moved out of the docmeta schema family. */
#include "../../xx_format_schema_docmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdm_pain_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("directory_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("member_count","uint32",12,4,SX_COUNT_PROP),
};
const sx_layout sxdm_pain_header={UINT32_C(0x60230007),"pain_header",sxdm_pain_header_fields,SX_COUNT(sxdm_pain_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_pain_directory_entry_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("method","uint32",4,4,SX_ID),
 SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
 SX_FIELD("filename","char[64]",16,64,SX_STRING),
};
const sx_layout sxdm_pain_directory_entry={UINT32_C(0x60230008),"pain_directory_entry",sxdm_pain_directory_entry_fields,SX_COUNT(sxdm_pain_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_pain_lzss_block_header_fields[]={
 SX_FIELD("block_type","uint32",0,4,SX_ID),
};
const sx_layout sxdm_pain_lzss_block_header={UINT32_C(0x60230009),"pain_lzss_block_header",sxdm_pain_lzss_block_header_fields,SX_COUNT(sxdm_pain_lzss_block_header_fields),SX_LE};
static bool sxdm_pain(sx_context *c)
{
 uint8_t b[80];if(!sx_read(c,0,b,16)||!sxdm_add(c,&sxdm_pain_header,0,16))return false;uint32_t dir=sxdm_u32(b+8),n=sxdm_u32(b+12);if(n>65536||dir<16||!sxdm_span(c,dir,(uint64_t)n*80))return false;
 for(uint32_t i=0;i<n;i++){int64_t at=(int64_t)dir+i*80;if(!sx_read(c,at,b,80)||!sxdm_add(c,&sxdm_pain_directory_entry,at,80))return false;uint32_t pos=sxdm_u32(b),method=sxdm_u32(b+4),bytes=sxdm_u32(b+8);if(!sxdm_span(c,pos,bytes))return false;if(method==3&&bytes>=4){uint32_t tag;if(!sx_u32(c,pos,false,&tag))return false;if(tag<=1&&!sxdm_add(c,&sxdm_pain_lzss_block_header,pos,4))return false;}}
 return true;
}
bool sx_pain_build(sx_context*c)
{
 return sxdm_pain(c);
}
