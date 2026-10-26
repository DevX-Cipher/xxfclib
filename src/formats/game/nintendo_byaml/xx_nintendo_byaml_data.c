/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo byaml data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_byaml_header_le_fields[]={
 SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint16",2,2,SX_ID),
 SX_FIELD("key_table_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("string_table_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("root_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sxmx_byaml_header_le={UINT32_C(0x602E005E),"byaml_header_le",sxmx_byaml_header_le_fields,SX_COUNT(sxmx_byaml_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_node_le_fields[]={
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("entry_count","uint24",1,3,SX_COUNT_PROP),
};
const sx_layout sxmx_byaml_node_le={UINT32_C(0x602E005F),"byaml_node_le",sxmx_byaml_node_le_fields,SX_COUNT(sxmx_byaml_node_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_string_offset_le_fields[]={
 SX_FIELD("string_relative","uint32",0,4,SX_OFFSET),
};
const sx_layout sxmx_byaml_string_offset_le={UINT32_C(0x602E0060),"byaml_string_offset_le",sxmx_byaml_string_offset_le_fields,SX_COUNT(sxmx_byaml_string_offset_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_map_key_le_fields[]={
 SX_FIELD("key_index","uint24",0,3,SX_ID),
 SX_FIELD("value_kind","uint8",3,1,SX_ID),
};
const sx_layout sxmx_byaml_map_key_le={UINT32_C(0x602E0061),"byaml_map_key_le",sxmx_byaml_map_key_le_fields,SX_COUNT(sxmx_byaml_map_key_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_array_kind_le_fields[]={
 SX_FIELD("value_kind","uint8",0,1,SX_ID),
};
const sx_layout sxmx_byaml_array_kind_le={UINT32_C(0x602E0062),"byaml_array_kind_le",sxmx_byaml_array_kind_le_fields,SX_COUNT(sxmx_byaml_array_kind_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_string_le_fields[]={
 SX_FIELD("value","uint32",0,4,SX_ID),
};
const sx_layout sxmx_byaml_string_le={UINT32_C(0x602E0063),"byaml_string_le",sxmx_byaml_string_le_fields,SX_COUNT(sxmx_byaml_string_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_bool_le_fields[]={
 SX_FIELD("value","uint32",0,4,SX_FLAGS),
};
const sx_layout sxmx_byaml_bool_le={UINT32_C(0x602E0064),"byaml_bool_le",sxmx_byaml_bool_le_fields,SX_COUNT(sxmx_byaml_bool_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_int_le_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxmx_byaml_int_le={UINT32_C(0x602E0065),"byaml_int_le",sxmx_byaml_int_le_fields,SX_COUNT(sxmx_byaml_int_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_float_le_fields[]={
 SX_FIELD("value","float",0,4,SX_NONE),
};
const sx_layout sxmx_byaml_float_le={UINT32_C(0x602E0066),"byaml_float_le",sxmx_byaml_float_le_fields,SX_COUNT(sxmx_byaml_float_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_uint_le_fields[]={
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
const sx_layout sxmx_byaml_uint_le={UINT32_C(0x602E0067),"byaml_uint_le",sxmx_byaml_uint_le_fields,SX_COUNT(sxmx_byaml_uint_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_node_value_le_fields[]={
 SX_FIELD("value","uint32",0,4,SX_OFFSET),
};
const sx_layout sxmx_byaml_node_value_le={UINT32_C(0x602E0068),"byaml_node_value_le",sxmx_byaml_node_value_le_fields,SX_COUNT(sxmx_byaml_node_value_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_null_le_fields[]={
 SX_FIELD("value","uint32",0,4,SX_RESERVED),
};
const sx_layout sxmx_byaml_null_le={UINT32_C(0x602E0069),"byaml_null_le",sxmx_byaml_null_le_fields,SX_COUNT(sxmx_byaml_null_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_byaml_header_be_fields[]={
 SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint16",2,2,SX_ID),
 SX_FIELD("key_table_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("string_table_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("root_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sxmx_byaml_header_be={UINT32_C(0x602E006A),"byaml_header_be",sxmx_byaml_header_be_fields,SX_COUNT(sxmx_byaml_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_node_be_fields[]={
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("entry_count","uint24",1,3,SX_COUNT_PROP),
};
const sx_layout sxmx_byaml_node_be={UINT32_C(0x602E006B),"byaml_node_be",sxmx_byaml_node_be_fields,SX_COUNT(sxmx_byaml_node_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_string_offset_be_fields[]={
 SX_FIELD("string_relative","uint32",0,4,SX_OFFSET),
};
const sx_layout sxmx_byaml_string_offset_be={UINT32_C(0x602E006C),"byaml_string_offset_be",sxmx_byaml_string_offset_be_fields,SX_COUNT(sxmx_byaml_string_offset_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_map_key_be_fields[]={
 SX_FIELD("key_index","uint24",0,3,SX_ID),
 SX_FIELD("value_kind","uint8",3,1,SX_ID),
};
const sx_layout sxmx_byaml_map_key_be={UINT32_C(0x602E006D),"byaml_map_key_be",sxmx_byaml_map_key_be_fields,SX_COUNT(sxmx_byaml_map_key_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_array_kind_be_fields[]={
 SX_FIELD("value_kind","uint8",0,1,SX_ID),
};
const sx_layout sxmx_byaml_array_kind_be={UINT32_C(0x602E006E),"byaml_array_kind_be",sxmx_byaml_array_kind_be_fields,SX_COUNT(sxmx_byaml_array_kind_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_string_be_fields[]={
 SX_FIELD("value","uint32",0,4,SX_ID),
};
const sx_layout sxmx_byaml_string_be={UINT32_C(0x602E006F),"byaml_string_be",sxmx_byaml_string_be_fields,SX_COUNT(sxmx_byaml_string_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_bool_be_fields[]={
 SX_FIELD("value","uint32",0,4,SX_FLAGS),
};
const sx_layout sxmx_byaml_bool_be={UINT32_C(0x602E0070),"byaml_bool_be",sxmx_byaml_bool_be_fields,SX_COUNT(sxmx_byaml_bool_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_int_be_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxmx_byaml_int_be={UINT32_C(0x602E0071),"byaml_int_be",sxmx_byaml_int_be_fields,SX_COUNT(sxmx_byaml_int_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_float_be_fields[]={
 SX_FIELD("value","float",0,4,SX_NONE),
};
const sx_layout sxmx_byaml_float_be={UINT32_C(0x602E0072),"byaml_float_be",sxmx_byaml_float_be_fields,SX_COUNT(sxmx_byaml_float_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_uint_be_fields[]={
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
const sx_layout sxmx_byaml_uint_be={UINT32_C(0x602E0073),"byaml_uint_be",sxmx_byaml_uint_be_fields,SX_COUNT(sxmx_byaml_uint_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_node_value_be_fields[]={
 SX_FIELD("value","uint32",0,4,SX_OFFSET),
};
const sx_layout sxmx_byaml_node_value_be={UINT32_C(0x602E0074),"byaml_node_value_be",sxmx_byaml_node_value_be_fields,SX_COUNT(sxmx_byaml_node_value_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_byaml_null_be_fields[]={
 SX_FIELD("value","uint32",0,4,SX_RESERVED),
};
const sx_layout sxmx_byaml_null_be={UINT32_C(0x602E0075),"byaml_null_be",sxmx_byaml_null_be_fields,SX_COUNT(sxmx_byaml_null_be_fields),SX_BE};
static bool sxmx_by_value(sxmx_view*v,size_t at,unsigned kind,bool be,unsigned depth);
static bool sxmx_by_node(sxmx_view*v,size_t at,bool be,unsigned depth)
{if(depth>32||!sxmx_row(v,be?&sxmx_byaml_node_be:&sxmx_byaml_node_le,at,v->n))return false;uint32_t n=xx_data_get_u24(v->p+at+1,3,0,be);unsigned kind=v->p[at];if(n>1024||(kind!=0xc0&&kind!=0xc1))return false;if(kind==0xc1){if(!sxmx_need(v,at+4,(uint64_t)n*8,v->n))return false;for(uint32_t i=0;i<n;i++){size_t row=at+4+(size_t)i*8;if(!sxmx_row(v,be?&sxmx_byaml_map_key_be:&sxmx_byaml_map_key_le,row,v->n)||!sxmx_by_value(v,row+4,v->p[row+3],be,depth))return false;}}else{size_t values=at+4+((n+3U)&~3U);if(!sxmx_table(v,be?&sxmx_byaml_array_kind_be:&sxmx_byaml_array_kind_le,at+4,n,v->n)||!sxmx_need(v,values,(uint64_t)n*4,v->n))return false;for(uint32_t i=0;i<n;i++)if(!sxmx_by_value(v,values+(size_t)i*4,v->p[at+4+i],be,depth))return false;}return true;}
static bool sxmx_by_value(sxmx_view*v,size_t at,unsigned kind,bool be,unsigned depth)
{const sx_layout*l=NULL;switch(kind){case 0xa0:l=be?&sxmx_byaml_string_be:&sxmx_byaml_string_le;break;case 0xd0:l=be?&sxmx_byaml_bool_be:&sxmx_byaml_bool_le;break;case 0xd1:l=be?&sxmx_byaml_int_be:&sxmx_byaml_int_le;break;case 0xd2:l=be?&sxmx_byaml_float_be:&sxmx_byaml_float_le;break;case 0xd3:l=be?&sxmx_byaml_uint_be:&sxmx_byaml_uint_le;break;case 0xff:l=be?&sxmx_byaml_null_be:&sxmx_byaml_null_le;break;case 0xc0:case 0xc1:l=be?&sxmx_byaml_node_value_be:&sxmx_byaml_node_value_le;break;default:return false;}
 if(kind==0xc0||kind==0xc1){if(!sxmx_row(v,be?&sxmx_byaml_node_value_be:&sxmx_byaml_node_value_le,at,v->n))return false;return sxmx_by_node(v,sxmx_u32(v->p+at,be),be,depth+1);}return sxmx_row(v,l,at,v->n);}
static bool sxmx_byaml(sxmx_view*v)
{if(!sxmx_need(v,0,16,v->n))return false;bool be=v->p[0]=='B';if(!sxmx_row(v,be?&sxmx_byaml_header_be:&sxmx_byaml_header_le,0,v->n))return false;for(unsigned i=4;i<=8;i+=4){size_t at=sxmx_u32(v->p+i,be);if(at){if(!sxmx_row(v,be?&sxmx_byaml_node_be:&sxmx_byaml_node_le,at,v->n))return false;uint32_t n=xx_data_get_u24(v->p+at+1,3,0,be);if(n>1024||!sxmx_table(v,be?&sxmx_byaml_string_offset_be:&sxmx_byaml_string_offset_le,at+4,(uint64_t)n+1,v->n))return false;}}return sxmx_by_node(v,sxmx_u32(v->p+12,be),be,0);}
bool sx_nintendo_byaml_build(sxmx_view*v)
{
 return sxmx_byaml(v);
}
