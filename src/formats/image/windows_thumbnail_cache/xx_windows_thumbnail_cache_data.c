/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Format facts data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_thumb_header_old_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("cache_type","uint32",8,4,SX_ID),
 SX_FIELD("first_entry_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("available_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",20,4,SX_COUNT_PROP),
};
const sx_layout sxnx_thumb_header_old={UINT32_C(0x60320061),"thumb_header_old",sxnx_thumb_header_old_fields,SX_COUNT(sxnx_thumb_header_old_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_thumb_header_28_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("cache_type","uint32",8,4,SX_ID),
 SX_FIELD("unknown","uint32",12,4,SX_NONE),
 SX_FIELD("first_entry_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("available_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",24,4,SX_COUNT_PROP),
};
const sx_layout sxnx_thumb_header_28={UINT32_C(0x60320062),"thumb_header_28",sxnx_thumb_header_28_fields,SX_COUNT(sxnx_thumb_header_28_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_thumb_header_new_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("cache_type","uint32",8,4,SX_ID),
 SX_FIELD("unknown","uint32",12,4,SX_NONE),
 SX_FIELD("first_entry_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("available_offset","uint32",20,4,SX_OFFSET),
};
const sx_layout sxnx_thumb_header_new={UINT32_C(0x60320063),"thumb_header_new",sxnx_thumb_header_new_fields,SX_COUNT(sxnx_thumb_header_new_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_thumb_entry_20_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("entry_size","uint32",4,4,SX_SIZE),
 SX_FIELD("cache_id","uint64",8,8,SX_ID),
 SX_FIELD("extension_utf16","bytes",16,8,SX_NONE),
 SX_FIELD("identifier_bytes","uint32",24,4,SX_SIZE),
 SX_FIELD("padding_bytes","uint32",28,4,SX_SIZE),
 SX_FIELD("data_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("unknown","uint32",36,4,SX_NONE),
 SX_FIELD("data_checksum","uint64",40,8,SX_CHECKSUM),
 SX_FIELD("header_checksum","uint64",48,8,SX_CHECKSUM),
};
const sx_layout sxnx_thumb_entry_20={UINT32_C(0x60320064),"thumb_entry_20",sxnx_thumb_entry_20_fields,SX_COUNT(sxnx_thumb_entry_20_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_thumb_entry_21_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("entry_size","uint32",4,4,SX_SIZE),
 SX_FIELD("cache_id","uint64",8,8,SX_ID),
 SX_FIELD("identifier_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("padding_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("data_bytes","uint32",24,4,SX_SIZE),
 SX_FIELD("unknown","uint32",28,4,SX_NONE),
 SX_FIELD("data_checksum","uint64",32,8,SX_CHECKSUM),
 SX_FIELD("header_checksum","uint64",40,8,SX_CHECKSUM),
};
const sx_layout sxnx_thumb_entry_21={UINT32_C(0x60320065),"thumb_entry_21",sxnx_thumb_entry_21_fields,SX_COUNT(sxnx_thumb_entry_21_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_thumb_entry_new_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("entry_size","uint32",4,4,SX_SIZE),
 SX_FIELD("cache_id","uint64",8,8,SX_ID),
 SX_FIELD("identifier_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("padding_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("data_bytes","uint32",24,4,SX_SIZE),
 SX_FIELD("width","uint32",28,4,SX_NONE),
 SX_FIELD("height","uint32",32,4,SX_NONE),
 SX_FIELD("unknown","uint32",36,4,SX_NONE),
 SX_FIELD("data_checksum","uint64",40,8,SX_CHECKSUM),
 SX_FIELD("header_checksum","uint64",48,8,SX_CHECKSUM),
};
const sx_layout sxnx_thumb_entry_new={UINT32_C(0x60320066),"thumb_entry_new",sxnx_thumb_entry_new_fields,SX_COUNT(sxnx_thumb_entry_new_fields),SX_LE};
static bool sxnx_thumb(sxnx_view*v)
{if(!sxnx_need(v,0,12,v->n))return false;unsigned version=sxnx_u32(v->p+4,false),hs=version==28?28:24;const sx_layout*l=version<=26?&sxnx_thumb_header_old:version==28?&sxnx_thumb_header_28:&sxnx_thumb_header_new;if(!sxnx_row(v,l,0,v->n))return false;unsigned off=version<=26?12:16,start=sxnx_u32(v->p+off,false),available=sxnx_u32(v->p+off+4,false);size_t p=start?start:hs,end=available?available:v->n;if(end>v->n||p>end)return false;l=version==20?&sxnx_thumb_entry_20:version==21?&sxnx_thumb_entry_21:&sxnx_thumb_entry_new;
 while(p<end){if(!sxnx_row(v,l,p,end))return false;unsigned n=sxnx_u32(v->p+p+4,false);if(n<(version==21?48:56)||!sxnx_need(v,p,n,end))return false;p+=n;}return true;}
bool sx_windows_thumbnail_cache_build(sxnx_view*v)
{
 return sxnx_thumb(v);
}
