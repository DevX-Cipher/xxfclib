/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * mythic myp data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_myp_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("signature","uint32",8,4,SX_SIGNATURE),
 SX_FIELD("first_block_offset","uint64",12,8,SX_OFFSET),
 SX_FIELD("block_capacity","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("file_count","uint32",24,4,SX_COUNT_PROP),
};
const sx_layout sxmx_myp_header={UINT32_C(0x602E0015),"myp_header",sxmx_myp_header_fields,SX_COUNT(sxmx_myp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_myp_block_fields[]={
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("next_block_offset","uint64",4,8,SX_OFFSET),
};
const sx_layout sxmx_myp_block={UINT32_C(0x602E0016),"myp_block",sxmx_myp_block_fields,SX_COUNT(sxmx_myp_block_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_myp_entry_fields[]={
 SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("name_hash","uint64",20,8,SX_CHECKSUM),
 SX_FIELD("data_hash","uint32",28,4,SX_CHECKSUM),
 SX_FIELD("compression","uint16",32,2,SX_ID),
};
const sx_layout sxmx_myp_entry={UINT32_C(0x602E0017),"myp_entry",sxmx_myp_entry_fields,SX_COUNT(sxmx_myp_entry_fields),SX_LE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static uint64_t sxmx_u64(const uint8_t*p,bool be){return xx_data_get_u64(p,8,0,be);}
static bool sxmx_myp(sxmx_view*v)
{if(!SM_ROW(myp_header,0,v->n))return false;uint64_t at=sxmx_u64(v->p+12,false);for(unsigned steps=0;at;steps++){if(steps>=1024||at>v->n||!SM_ROW(myp_block,(size_t)at,v->n))return false;uint32_t n=sxmx_u32(v->p+at,false);uint64_t next=sxmx_u64(v->p+at+4,false);if(!sxmx_table(v,&sxmx_myp_entry,(size_t)at+12,n,v->n))return false;if(next&&next<at+12+(uint64_t)n*34)return false;at=next;}return true;}
bool sx_mythic_myp_build(sxmx_view*v)
{
 return sxmx_myp(v);
}
#undef SM_ROW
