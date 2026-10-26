/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * unity serialized data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_unity_header_fields[]={
 SX_FIELD("legacy_metadata_size","uint32",0,4,SX_SIZE),
 SX_FIELD("legacy_file_size","uint32",4,4,SX_SIZE),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("legacy_data_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("byte_order","uint8",16,1,SX_ID),
 SX_FIELD("reserved","bytes",17,3,SX_RESERVED),
 SX_FIELD("metadata_size","uint32",20,4,SX_SIZE),
 SX_FIELD("file_size","uint64",24,8,SX_SIZE),
 SX_FIELD("data_offset","uint64",32,8,SX_OFFSET),
 SX_FIELD("unknown","uint64",40,8,SX_NONE),
};
const sx_layout sxmx_unity_header={UINT32_C(0x602E0050),"unity_header",sxmx_unity_header_fields,SX_COUNT(sxmx_unity_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_unity_metadata_flags_fields[]={
 SX_FIELD("target_platform","int32",0,4,SX_ID),
 SX_FIELD("enable_type_tree","uint8",4,1,SX_FLAGS),
 SX_FIELD("type_count","int32",5,4,SX_COUNT_PROP),
};
const sx_layout sxmx_unity_metadata_flags={UINT32_C(0x602E0051),"unity_metadata_flags",sxmx_unity_metadata_flags_fields,SX_COUNT(sxmx_unity_metadata_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_unity_type_fields[]={
 SX_FIELD("class_id","int32",0,4,SX_ID),
 SX_FIELD("stripped_type","uint8",4,1,SX_FLAGS),
 SX_FIELD("script_type_index","int16",5,2,SX_ID),
 SX_FIELD("old_type_hash","bytes",7,16,SX_CHECKSUM),
};
const sx_layout sxmx_unity_type={UINT32_C(0x602E0052),"unity_type",sxmx_unity_type_fields,SX_COUNT(sxmx_unity_type_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_unity_object_count_fields[]={
 SX_FIELD("object_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmx_unity_object_count={UINT32_C(0x602E0053),"unity_object_count",sxmx_unity_object_count_fields,SX_COUNT(sxmx_unity_object_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_unity_object_fields[]={
 SX_FIELD("path_id","int64",0,8,SX_ID),
 SX_FIELD("data_relative","int64",8,8,SX_OFFSET),
 SX_FIELD("data_size","uint32",16,4,SX_SIZE),
 SX_FIELD("type_index","int32",20,4,SX_ID),
};
const sx_layout sxmx_unity_object={UINT32_C(0x602E0054),"unity_object",sxmx_unity_object_fields,SX_COUNT(sxmx_unity_object_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_unity_tail_counts_fields[]={
 SX_FIELD("script_type_count","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("external_count","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("reference_type_count","int32",8,4,SX_COUNT_PROP),
};
const sx_layout sxmx_unity_tail_counts={UINT32_C(0x602E0055),"unity_tail_counts",sxmx_unity_tail_counts_fields,SX_COUNT(sxmx_unity_tail_counts_fields),SX_LE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_unity(sxmx_view*v)
{if(!SM_ROW(unity_header,0,v->n))return false;size_t at=48,end=48+(size_t)sxmx_u32(v->p+20,true);if(end>v->n||!sxmx_cstr(v,&at,end)||!SM_ROW(unity_metadata_flags,at,end))return false;uint32_t types=sxmx_u32(v->p+at+5,false);at+=9;if(!sxmx_table(v,&sxmx_unity_type,at,types,end))return false;at+=(size_t)types*23;if(!SM_ROW(unity_object_count,at,end))return false;uint32_t n=sxmx_u32(v->p+at,false);at+=4;if(n>1024)return false;for(uint32_t i=0;i<n;i++){at=(at+3)&~(size_t)3;if(!SM_ROW(unity_object,at,end))return false;at+=24;}return SM_ROW(unity_tail_counts,at,end);}
bool sx_unity_serialized_build(sxmx_view*v)
{
 return sxmx_unity(v);
}
#undef SM_ROW
