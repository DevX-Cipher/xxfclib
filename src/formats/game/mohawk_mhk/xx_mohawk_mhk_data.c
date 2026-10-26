/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * mohawk mhk data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_mhk_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("file_size","uint32",4,4,SX_SIZE),
 SX_FIELD("resource_magic","char[4]",8,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",12,2,SX_ID),
 SX_FIELD("compaction","uint16",14,2,SX_NONE),
 SX_FIELD("resource_size","uint32",16,4,SX_SIZE),
 SX_FIELD("directory_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("file_table_offset","uint16",24,2,SX_OFFSET),
 SX_FIELD("file_table_size","uint16",26,2,SX_SIZE),
};
const sx_layout sxmx_mhk_header={UINT32_C(0x602E0006),"mhk_header",sxmx_mhk_header_fields,SX_COUNT(sxmx_mhk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_mhk_directory_fields[]={
 SX_FIELD("string_table_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("type_count","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxmx_mhk_directory={UINT32_C(0x602E0007),"mhk_directory",sxmx_mhk_directory_fields,SX_COUNT(sxmx_mhk_directory_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_mhk_type_fields[]={
 SX_FIELD("type_tag","char[4]",0,4,SX_ID),
 SX_FIELD("resource_table_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("name_table_offset","uint16",6,2,SX_OFFSET),
};
const sx_layout sxmx_mhk_type={UINT32_C(0x602E0008),"mhk_type",sxmx_mhk_type_fields,SX_COUNT(sxmx_mhk_type_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_mhk_count32_fields[]={
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmx_mhk_count32={UINT32_C(0x602E0009),"mhk_count32",sxmx_mhk_count32_fields,SX_COUNT(sxmx_mhk_count32_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_mhk_count16_fields[]={
 SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxmx_mhk_count16={UINT32_C(0x602E000A),"mhk_count16",sxmx_mhk_count16_fields,SX_COUNT(sxmx_mhk_count16_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_mhk_file_fields[]={
 SX_FIELD("file_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("size_low16","uint16",4,2,SX_NONE),
 SX_FIELD("size_high8","uint8",6,1,SX_NONE),
 SX_FIELD("size_high3_and_flags","uint8",7,1,SX_FLAGS),
 SX_FIELD("unknown","uint16",8,2,SX_NONE),
};
const sx_layout sxmx_mhk_file={UINT32_C(0x602E000B),"mhk_file",sxmx_mhk_file_fields,SX_COUNT(sxmx_mhk_file_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_mhk_resource_fields[]={
 SX_FIELD("resource_id","uint16",0,2,SX_ID),
 SX_FIELD("file_index","uint16",2,2,SX_ID),
};
const sx_layout sxmx_mhk_resource={UINT32_C(0x602E000C),"mhk_resource",sxmx_mhk_resource_fields,SX_COUNT(sxmx_mhk_resource_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_mhk_name_fields[]={
 SX_FIELD("string_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("file_index","uint16",2,2,SX_ID),
};
const sx_layout sxmx_mhk_name={UINT32_C(0x602E000D),"mhk_name",sxmx_mhk_name_fields,SX_COUNT(sxmx_mhk_name_fields),SX_BE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_mhk(sxmx_view*v)
{if(!SM_ROW(mhk_header,0,v->n))return false;size_t base=sxmx_u32(v->p+20,true),ft=base+sxmx_u16(v->p+24,true);if(!SM_ROW(mhk_directory,base,v->n)||!SM_ROW(mhk_count32,ft,v->n))return false;uint32_t n=sxmx_u32(v->p+ft,true),types=sxmx_u16(v->p+base+2,true);if(!sxmx_table(v,&sxmx_mhk_file,ft+4,n,v->n)||!sxmx_table(v,&sxmx_mhk_type,base+4,types,v->n))return false;for(uint32_t i=0;i<types;i++){const uint8_t*p=v->p+base+4+(size_t)i*8;size_t rt=base+sxmx_u16(p+4,true),nt=base+sxmx_u16(p+6,true);if(!SM_ROW(mhk_count16,rt,v->n)||!SM_ROW(mhk_count16,nt,v->n)||!sxmx_table(v,&sxmx_mhk_resource,rt+2,sxmx_u16(v->p+rt,true),v->n)||!sxmx_table(v,&sxmx_mhk_name,nt+2,sxmx_u16(v->p+nt,true),v->n))return false;}return true;}
bool sx_mohawk_mhk_build(sxmx_view*v)
{
 return sxmx_mhk(v);
}
#undef SM_ROW
