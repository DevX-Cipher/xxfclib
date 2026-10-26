/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * cri utf data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_utf_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("table_size_after_prefix","uint32",4,4,SX_SIZE),
 SX_FIELD("version","uint16",8,2,SX_ID),
 SX_FIELD("rows_relative","uint16",10,2,SX_OFFSET),
 SX_FIELD("strings_relative","uint32",12,4,SX_OFFSET),
 SX_FIELD("data_relative","uint32",16,4,SX_OFFSET),
 SX_FIELD("table_name_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("column_count","uint16",24,2,SX_COUNT_PROP),
 SX_FIELD("row_size","uint16",26,2,SX_SIZE),
 SX_FIELD("row_count","uint32",28,4,SX_COUNT_PROP),
};
const sx_layout sxmx_utf_header={UINT32_C(0x602E007C),"utf_header",sxmx_utf_header_fields,SX_COUNT(sxmx_utf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_column_fields[]={
 SX_FIELD("storage_and_type","uint8",0,1,SX_FLAGS),
 SX_FIELD("name_offset","uint32",1,4,SX_OFFSET),
};
const sx_layout sxmx_utf_column={UINT32_C(0x602E007D),"utf_column",sxmx_utf_column_fields,SX_COUNT(sxmx_utf_column_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_u8_fields[]={
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
const sx_layout sxmx_utf_u8={UINT32_C(0x602E007E),"utf_u8",sxmx_utf_u8_fields,SX_COUNT(sxmx_utf_u8_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_i8_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
const sx_layout sxmx_utf_i8={UINT32_C(0x602E007F),"utf_i8",sxmx_utf_i8_fields,SX_COUNT(sxmx_utf_i8_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_u16_fields[]={
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
const sx_layout sxmx_utf_u16={UINT32_C(0x602E0080),"utf_u16",sxmx_utf_u16_fields,SX_COUNT(sxmx_utf_u16_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_i16_fields[]={
 SX_FIELD("value","int16",0,2,SX_NONE),
};
const sx_layout sxmx_utf_i16={UINT32_C(0x602E0081),"utf_i16",sxmx_utf_i16_fields,SX_COUNT(sxmx_utf_i16_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_u32_fields[]={
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
const sx_layout sxmx_utf_u32={UINT32_C(0x602E0082),"utf_u32",sxmx_utf_u32_fields,SX_COUNT(sxmx_utf_u32_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_i32_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxmx_utf_i32={UINT32_C(0x602E0083),"utf_i32",sxmx_utf_i32_fields,SX_COUNT(sxmx_utf_i32_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_u64_fields[]={
 SX_FIELD("value","uint64",0,8,SX_NONE),
};
const sx_layout sxmx_utf_u64={UINT32_C(0x602E0084),"utf_u64",sxmx_utf_u64_fields,SX_COUNT(sxmx_utf_u64_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_i64_fields[]={
 SX_FIELD("value","int64",0,8,SX_NONE),
};
const sx_layout sxmx_utf_i64={UINT32_C(0x602E0085),"utf_i64",sxmx_utf_i64_fields,SX_COUNT(sxmx_utf_i64_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_float_fields[]={
 SX_FIELD("value","float",0,4,SX_NONE),
};
const sx_layout sxmx_utf_float={UINT32_C(0x602E0086),"utf_float",sxmx_utf_float_fields,SX_COUNT(sxmx_utf_float_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_double_fields[]={
 SX_FIELD("value","double",0,8,SX_NONE),
};
const sx_layout sxmx_utf_double={UINT32_C(0x602E0087),"utf_double",sxmx_utf_double_fields,SX_COUNT(sxmx_utf_double_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_string_fields[]={
 SX_FIELD("string_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxmx_utf_string={UINT32_C(0x602E0088),"utf_string",sxmx_utf_string_fields,SX_COUNT(sxmx_utf_string_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_binary_fields[]={
 SX_FIELD("data_relative","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxmx_utf_binary={UINT32_C(0x602E0089),"utf_binary",sxmx_utf_binary_fields,SX_COUNT(sxmx_utf_binary_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_utf_guid_fields[]={
 SX_FIELD("guid","bytes",0,16,SX_ID),
};
const sx_layout sxmx_utf_guid={UINT32_C(0x602E008A),"utf_guid",sxmx_utf_guid_fields,SX_COUNT(sxmx_utf_guid_fields),SX_BE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_utf(sxmx_view*v)
{if(!SM_ROW(utf_header,0,v->n))return false;const sx_layout*ls[]={&sxmx_utf_u8,&sxmx_utf_i8,&sxmx_utf_u16,&sxmx_utf_i16,&sxmx_utf_u32,&sxmx_utf_i32,&sxmx_utf_u64,&sxmx_utf_i64,&sxmx_utf_float,&sxmx_utf_double,&sxmx_utf_string,&sxmx_utf_binary,&sxmx_utf_guid};const unsigned sizes[]={1,1,2,2,4,4,8,8,4,8,4,8,16};unsigned kinds[128],flags[128];size_t positions[128],width=0,at=32,row=8+(size_t)sxmx_u16(v->p+10,true),strings=8+(size_t)sxmx_u32(v->p+12,true);uint32_t n=sxmx_u16(v->p+24,true),rows=sxmx_u32(v->p+28,true),stride=sxmx_u16(v->p+26,true);if(n>128||rows>1024||row>strings||strings>v->n)return false;for(uint32_t i=0;i<n;i++){if(!SM_ROW(utf_column,at,row))return false;kinds[i]=v->p[at]&15;flags[i]=v->p[at]&0xf0;positions[i]=width;at+=5;if(kinds[i]>12)return false;if(flags[i]&0x20){if(!sxmx_row(v,ls[kinds[i]],at,row))return false;at+=sizes[kinds[i]];}if(flags[i]&0x40)width+=sizes[kinds[i]];}if(width!=stride||!sxmx_need(v,row,(uint64_t)rows*stride,strings))return false;for(uint32_t j=0;j<rows;j++)for(uint32_t i=0;i<n;i++)if((flags[i]&0x40)&&!sxmx_row(v,ls[kinds[i]],row+(size_t)j*stride+positions[i],strings))return false;return true;}
bool sx_cri_utf_build(sxmx_view*v)
{
 return sxmx_utf(v);
}
#undef SM_ROW
