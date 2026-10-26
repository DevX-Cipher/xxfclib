/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo brlan data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_brlan_pai1_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("section_size","uint32",4,4,SX_SIZE),
 SX_FIELD("frame_count","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("loop","uint8",10,1,SX_FLAGS),
 SX_FIELD("padding","uint8",11,1,SX_NONE),
 SX_FIELD("texture_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("binding_count","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("binding_table_offset","uint32",16,4,SX_OFFSET),
};
const sx_layout sxmx_brlan_pai1={UINT32_C(0x602E0043),"brlan_pai1",sxmx_brlan_pai1_fields,SX_COUNT(sxmx_brlan_pai1_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brlan_binding_fields[]={
 SX_FIELD("name","char[20]",0,20,SX_STRING),
 SX_FIELD("group_count","uint8",20,1,SX_COUNT_PROP),
 SX_FIELD("padding","bytes",21,3,SX_NONE),
 SX_FIELD("group_relative","uint32",24,4,SX_OFFSET),
};
const sx_layout sxmx_brlan_binding={UINT32_C(0x602E0044),"brlan_binding",sxmx_brlan_binding_fields,SX_COUNT(sxmx_brlan_binding_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brlan_group_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("track_count","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("padding","bytes",5,3,SX_NONE),
};
const sx_layout sxmx_brlan_group={UINT32_C(0x602E0045),"brlan_group",sxmx_brlan_group_fields,SX_COUNT(sxmx_brlan_group_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brlan_track_fields[]={
 SX_FIELD("index","uint8",0,1,SX_ID),
 SX_FIELD("channel","uint8",1,1,SX_ID),
 SX_FIELD("curve_type","uint8",2,1,SX_ID),
 SX_FIELD("padding","uint8",3,1,SX_NONE),
 SX_FIELD("key_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
 SX_FIELD("keys_relative","uint32",8,4,SX_OFFSET),
};
const sx_layout sxmx_brlan_track={UINT32_C(0x602E0046),"brlan_track",sxmx_brlan_track_fields,SX_COUNT(sxmx_brlan_track_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_brlan_key_fields[]={
 SX_FIELD("frame","float",0,4,SX_NONE),
 SX_FIELD("value","float",4,4,SX_NONE),
 SX_FIELD("tangent","float",8,4,SX_NONE),
};
const sx_layout sxmx_brlan_key={UINT32_C(0x602E0047),"brlan_key",sxmx_brlan_key_fields,SX_COUNT(sxmx_brlan_key_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_relative_offset_be_fields[]={
 SX_FIELD("relative_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxmx_relative_offset_be={UINT32_C(0x602E0048),"relative_offset_be",sxmx_relative_offset_be_fields,SX_COUNT(sxmx_relative_offset_be_fields),SX_BE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_brlan(sxmx_view*v)
{if(!SM_ROW(nw_header,0,v->n)||!SM_ROW(brlan_pai1,16,v->n))return false;uint32_t n=sxmx_u16(v->p+30,true);size_t table=16+(size_t)sxmx_u32(v->p+32,true);if(n>32||!sxmx_table(v,&sxmx_relative_offset_be,table,n,v->n))return false;for(uint32_t i=0;i<n;i++){size_t at=16+(size_t)sxmx_u32(v->p+table+(size_t)i*4,true);if(!SM_ROW(brlan_binding,at,v->n))return false;size_t group=at+sxmx_u32(v->p+at+24,true);if(!SM_ROW(brlan_group,group,v->n))return false;uint32_t tracks=v->p[group+4];if(tracks>10||!sxmx_table(v,&sxmx_relative_offset_be,group+8,tracks,v->n))return false;for(uint32_t j=0;j<tracks;j++){size_t track=group+sxmx_u32(v->p+group+8+(size_t)j*4,true);if(!SM_ROW(brlan_track,track,v->n))return false;size_t key=track+sxmx_u32(v->p+track+8,true);if(!sxmx_table(v,&sxmx_brlan_key,key,sxmx_u16(v->p+track+4,true),v->n))return false;}}return true;}
bool sx_nintendo_brlan_build(sxmx_view*v)
{
 return sxmx_brlan(v);
}
#undef SM_ROW
