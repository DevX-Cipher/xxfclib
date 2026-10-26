/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * relic chunky data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_chunky_header_fields[]={
 SX_FIELD("magic","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("version","uint32",16,4,SX_ID),
 SX_FIELD("platform","uint32",20,4,SX_ID),
 SX_FIELD("header_size","uint32",24,4,SX_SIZE),
 SX_FIELD("chunk_header_size","uint32",28,4,SX_SIZE),
 SX_FIELD("unknown","uint32",32,4,SX_NONE),
};
const sx_layout sxmx_chunky_header={UINT32_C(0x602E0038),"chunky_header",sxmx_chunky_header_fields,SX_COUNT(sxmx_chunky_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_chunky_chunk_fields[]={
 SX_FIELD("kind","char[4]",0,4,SX_ID),
 SX_FIELD("chunk_id","char[4]",4,4,SX_ID),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("data_size","uint32",12,4,SX_SIZE),
 SX_FIELD("name_size","uint32",16,4,SX_SIZE),
 SX_FIELD("unknown1","uint32",20,4,SX_NONE),
 SX_FIELD("unknown2","uint32",24,4,SX_NONE),
};
const sx_layout sxmx_chunky_chunk={UINT32_C(0x602E0039),"chunky_chunk",sxmx_chunky_chunk_fields,SX_COUNT(sxmx_chunky_chunk_fields),SX_LE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_chunky_nodes(sxmx_view*v,size_t at,size_t end,unsigned depth)
{if(depth>32)return false;while(at<end){if(!SM_ROW(chunky_chunk,at,end))return false;uint32_t size=sxmx_u32(v->p+at+12,false),names=sxmx_u32(v->p+at+16,false);bool folder=!xx_rt_memcmp(v->p+at,"FOLD",4);at+=28;if(!sxmx_need(v,at,(uint64_t)names+size,end))return false;at+=names;if(folder&&!sxmx_chunky_nodes(v,at,at+size,depth+1))return false;at+=size;}return at==end;}
static bool sxmx_chunky(sxmx_view*v){return SM_ROW(chunky_header,0,v->n)&&sxmx_chunky_nodes(v,36,v->n,0);}
bool sx_relic_chunky_build(sxmx_view*v)
{
 return sxmx_chunky(v);
}
#undef SM_ROW
