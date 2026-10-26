/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo j3d btk data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_btk_ttk1_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("section_size","uint32",4,4,SX_SIZE),
 SX_FIELD("loop_mode","uint8",8,1,SX_ID),
 SX_FIELD("angle_scale","uint8",9,1,SX_NONE),
 SX_FIELD("duration_frames","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("animation_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("scale_count","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("rotation_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("translation_count","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("animation_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("remap_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("name_table_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("texture_matrix_index_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("center_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("scale_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("rotation_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("translation_offset","uint32",48,4,SX_OFFSET),
};
const sx_layout sxmx_btk_ttk1={UINT32_C(0x602E003B),"btk_ttk1",sxmx_btk_ttk1_fields,SX_COUNT(sxmx_btk_ttk1_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_btk_selection_fields[]={
 SX_FIELD("scale_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("scale_first","uint16",2,2,SX_ID),
 SX_FIELD("scale_tangent_type","uint16",4,2,SX_ID),
 SX_FIELD("rotation_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("rotation_first","uint16",8,2,SX_ID),
 SX_FIELD("rotation_tangent_type","uint16",10,2,SX_ID),
 SX_FIELD("translation_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("translation_first","uint16",14,2,SX_ID),
 SX_FIELD("translation_tangent_type","uint16",16,2,SX_ID),
};
const sx_layout sxmx_btk_selection={UINT32_C(0x602E003C),"btk_selection",sxmx_btk_selection_fields,SX_COUNT(sxmx_btk_selection_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_btk_remap_fields[]={
 SX_FIELD("animation_index","uint16",0,2,SX_ID),
};
const sx_layout sxmx_btk_remap={UINT32_C(0x602E003D),"btk_remap",sxmx_btk_remap_fields,SX_COUNT(sxmx_btk_remap_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_btk_texture_matrix_index_fields[]={
 SX_FIELD("texture_matrix_index","uint8",0,1,SX_ID),
};
const sx_layout sxmx_btk_texture_matrix_index={UINT32_C(0x602E003E),"btk_texture_matrix_index",sxmx_btk_texture_matrix_index_fields,SX_COUNT(sxmx_btk_texture_matrix_index_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_btk_float_fields[]={
 SX_FIELD("value","float",0,4,SX_NONE),
};
const sx_layout sxmx_btk_float={UINT32_C(0x602E003F),"btk_float",sxmx_btk_float_fields,SX_COUNT(sxmx_btk_float_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_btk_rotation_fields[]={
 SX_FIELD("angle_units","int16",0,2,SX_NONE),
};
const sx_layout sxmx_btk_rotation={UINT32_C(0x602E0040),"btk_rotation",sxmx_btk_rotation_fields,SX_COUNT(sxmx_btk_rotation_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_j3d_name_table_fields[]={
 SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("padding","bytes",2,2,SX_NONE),
};
const sx_layout sxmx_j3d_name_table={UINT32_C(0x602E0041),"j3d_name_table",sxmx_j3d_name_table_fields,SX_COUNT(sxmx_j3d_name_table_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_j3d_name_fields[]={
 SX_FIELD("hash","uint16",0,2,SX_CHECKSUM),
 SX_FIELD("name_relative","uint16",2,2,SX_OFFSET),
};
const sx_layout sxmx_j3d_name={UINT32_C(0x602E0042),"j3d_name",sxmx_j3d_name_fields,SX_COUNT(sxmx_j3d_name_fields),SX_BE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_btk(sxmx_view*v)
{if(!SM_ROW(j3d_header,0,v->n)||!SM_ROW(btk_ttk1,32,v->n))return false;const uint8_t*p=v->p+32;size_t end=32+(size_t)sxmx_u32(p+4,true);if(end>v->n)return false;uint32_t n=sxmx_u16(p+12,true);uint32_t count[8]={n,n/3,n/3,n/3,n,sxmx_u16(p+14,true),sxmx_u16(p+16,true),sxmx_u16(p+18,true)};const sx_layout*ls[8]={&sxmx_btk_selection,&sxmx_btk_remap,NULL,&sxmx_btk_texture_matrix_index,&sxmx_btk_float,&sxmx_btk_float,&sxmx_btk_rotation,&sxmx_btk_float};for(unsigned i=0;i<8;i++){size_t at=32+(size_t)sxmx_u32(p+20+i*4,true);if(i==2){if(!SM_ROW(j3d_name_table,at,end)||!sxmx_table(v,&sxmx_j3d_name,at+4,count[i],end))return false;}else if(!sxmx_table(v,ls[i],at,count[i],end))return false;}return true;}
bool sx_nintendo_j3d_btk_build(sxmx_view*v)
{
 return sxmx_btk(v);
}
#undef SM_ROW
