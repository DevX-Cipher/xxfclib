/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo brres data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_brres_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("version","uint16",6,2,SX_ID),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("root_offset","uint16",12,2,SX_OFFSET),
 SX_FIELD("section_count","uint16",14,2,SX_COUNT_PROP),
};
const sx_layout sxmx_brres_header={UINT32_C(0x602E001F),"brres_header",sxmx_brres_header_fields,SX_COUNT(sxmx_brres_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brres_root_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("size","int32",4,4,SX_SIZE),
};
const sx_layout sxmx_brres_root={UINT32_C(0x602E0020),"brres_root",sxmx_brres_root_fields,SX_COUNT(sxmx_brres_root_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brres_dictionary_fields[]={
 SX_FIELD("size","int32",0,4,SX_SIZE),
 SX_FIELD("entry_count","int32",4,4,SX_COUNT_PROP),
};
const sx_layout sxmx_brres_dictionary={UINT32_C(0x602E0021),"brres_dictionary",sxmx_brres_dictionary_fields,SX_COUNT(sxmx_brres_dictionary_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brres_node_fields[]={
 SX_FIELD("reference_id","uint16",0,2,SX_ID),
 SX_FIELD("unknown","uint16",2,2,SX_NONE),
 SX_FIELD("left_index","uint16",4,2,SX_ID),
 SX_FIELD("right_index","uint16",6,2,SX_ID),
 SX_FIELD("name_relative","int32",8,4,SX_OFFSET),
 SX_FIELD("data_relative","int32",12,4,SX_OFFSET),
};
const sx_layout sxmx_brres_node={UINT32_C(0x602E0022),"brres_node",sxmx_brres_node_fields,SX_COUNT(sxmx_brres_node_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brres_resource_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("size","int32",4,4,SX_SIZE),
 SX_FIELD("version","int32",8,4,SX_ID),
 SX_FIELD("archive_relative","int32",12,4,SX_OFFSET),
};
const sx_layout sxmx_brres_resource={UINT32_C(0x602E0023),"brres_resource",sxmx_brres_resource_fields,SX_COUNT(sxmx_brres_resource_fields),SX_BE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_brres(sxmx_view*v)
{if(!SM_ROW(brres_header,0,v->n))return false;size_t root=sxmx_u16(v->p+12,true),master=root+8;if(!SM_ROW(brres_root,root,v->n)||!SM_ROW(brres_dictionary,master,v->n))return false;uint32_t groups=sxmx_u32(v->p+master+4,true);if(!sxmx_table(v,&sxmx_brres_node,master+8,(uint64_t)groups+1,v->n))return false;for(uint32_t i=0;i<groups;i++){int64_t sub=(int64_t)master+(int32_t)sxmx_u32(v->p+master+24+(size_t)i*16+12,true);if(sub<0||(uint64_t)sub>v->n||!SM_ROW(brres_dictionary,(size_t)sub,v->n))return false;uint32_t n=sxmx_u32(v->p+sub+4,true);if(!sxmx_table(v,&sxmx_brres_node,(size_t)sub+8,(uint64_t)n+1,v->n))return false;for(uint32_t j=0;j<n;j++){int64_t at=sub+(int32_t)sxmx_u32(v->p+sub+24+(size_t)j*16+12,true);if(at<0||(uint64_t)at>v->n||!SM_ROW(brres_resource,(size_t)at,v->n))return false;}}return true;}
bool sx_nintendo_brres_build(sxmx_view*v)
{
 return sxmx_brres(v);
}
#undef SM_ROW
