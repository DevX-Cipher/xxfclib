/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * idtech iqm data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_iqm_header_fields[]={
 SX_FIELD("magic","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("version","uint32",16,4,SX_ID),
 SX_FIELD("file_size","uint32",20,4,SX_SIZE),
 SX_FIELD("flags","uint32",24,4,SX_FLAGS),
 SX_FIELD("text_size","uint32",28,4,SX_SIZE),
 SX_FIELD("text_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("mesh_count","uint32",36,4,SX_COUNT_PROP),
 SX_FIELD("mesh_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("vertex_array_count","uint32",44,4,SX_COUNT_PROP),
 SX_FIELD("vertex_count","uint32",48,4,SX_COUNT_PROP),
 SX_FIELD("vertex_array_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("triangle_count","uint32",56,4,SX_COUNT_PROP),
 SX_FIELD("triangle_offset","uint32",60,4,SX_OFFSET),
 SX_FIELD("adjacency_offset","uint32",64,4,SX_OFFSET),
 SX_FIELD("joint_count","uint32",68,4,SX_COUNT_PROP),
 SX_FIELD("joint_offset","uint32",72,4,SX_OFFSET),
 SX_FIELD("pose_count","uint32",76,4,SX_COUNT_PROP),
 SX_FIELD("pose_offset","uint32",80,4,SX_OFFSET),
 SX_FIELD("animation_count","uint32",84,4,SX_COUNT_PROP),
 SX_FIELD("animation_offset","uint32",88,4,SX_OFFSET),
 SX_FIELD("frame_count","uint32",92,4,SX_COUNT_PROP),
 SX_FIELD("frame_channel_count","uint32",96,4,SX_COUNT_PROP),
 SX_FIELD("frame_offset","uint32",100,4,SX_OFFSET),
 SX_FIELD("bounds_offset","uint32",104,4,SX_OFFSET),
 SX_FIELD("comment_size","uint32",108,4,SX_SIZE),
 SX_FIELD("comment_offset","uint32",112,4,SX_OFFSET),
 SX_FIELD("extension_count","uint32",116,4,SX_COUNT_PROP),
 SX_FIELD("extension_offset","uint32",120,4,SX_OFFSET),
};
const sx_layout sxmx_iqm_header={UINT32_C(0x602E008B),"iqm_header",sxmx_iqm_header_fields,SX_COUNT(sxmx_iqm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_iqm_mesh_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("material_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("first_vertex","uint32",8,4,SX_ID),
 SX_FIELD("vertex_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("first_triangle","uint32",16,4,SX_ID),
 SX_FIELD("triangle_count","uint32",20,4,SX_COUNT_PROP),
};
const sx_layout sxmx_iqm_mesh={UINT32_C(0x602E008C),"iqm_mesh",sxmx_iqm_mesh_fields,SX_COUNT(sxmx_iqm_mesh_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_iqm_vertex_array_fields[]={
 SX_FIELD("type","uint32",0,4,SX_ID),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("format","uint32",8,4,SX_ID),
 SX_FIELD("components","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("data_offset","uint32",16,4,SX_OFFSET),
};
const sx_layout sxmx_iqm_vertex_array={UINT32_C(0x602E008D),"iqm_vertex_array",sxmx_iqm_vertex_array_fields,SX_COUNT(sxmx_iqm_vertex_array_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_iqm_triangle_fields[]={
 SX_FIELD("vertex0","uint32",0,4,SX_ID),
 SX_FIELD("vertex1","uint32",4,4,SX_ID),
 SX_FIELD("vertex2","uint32",8,4,SX_ID),
};
const sx_layout sxmx_iqm_triangle={UINT32_C(0x602E008E),"iqm_triangle",sxmx_iqm_triangle_fields,SX_COUNT(sxmx_iqm_triangle_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_iqm_adjacency_fields[]={
 SX_FIELD("triangle0","uint32",0,4,SX_ID),
 SX_FIELD("triangle1","uint32",4,4,SX_ID),
 SX_FIELD("triangle2","uint32",8,4,SX_ID),
};
const sx_layout sxmx_iqm_adjacency={UINT32_C(0x602E008F),"iqm_adjacency",sxmx_iqm_adjacency_fields,SX_COUNT(sxmx_iqm_adjacency_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_iqm_float_fields[]={
 SX_FIELD("component","float",0,4,SX_NONE),
};
const sx_layout sxmx_iqm_float={UINT32_C(0x602E0090),"iqm_float",sxmx_iqm_float_fields,SX_COUNT(sxmx_iqm_float_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_iqm_color_fields[]={
 SX_FIELD("red","uint8",0,1,SX_NONE),
 SX_FIELD("green","uint8",1,1,SX_NONE),
 SX_FIELD("blue","uint8",2,1,SX_NONE),
 SX_FIELD("alpha","uint8",3,1,SX_NONE),
};
const sx_layout sxmx_iqm_color={UINT32_C(0x602E0091),"iqm_color",sxmx_iqm_color_fields,SX_COUNT(sxmx_iqm_color_fields),SX_LE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_iqm(sxmx_view*v)
{if(!SM_ROW(iqm_header,0,v->n))return false;uint32_t meshes=sxmx_u32(v->p+36,false),arrays=sxmx_u32(v->p+44,false),verts=sxmx_u32(v->p+48,false),tris=sxmx_u32(v->p+56,false);size_t ao=sxmx_u32(v->p+52,false);if(arrays>7||verts>65536||!sxmx_table(v,&sxmx_iqm_mesh,sxmx_u32(v->p+40,false),meshes,v->n)||!sxmx_table(v,&sxmx_iqm_vertex_array,ao,arrays,v->n)||!sxmx_table(v,&sxmx_iqm_triangle,sxmx_u32(v->p+60,false),tris,v->n))return false;size_t adj=sxmx_u32(v->p+64,false);if(adj&&!sxmx_table(v,&sxmx_iqm_adjacency,adj,tris,v->n))return false;for(uint32_t i=0;i<arrays;i++){const uint8_t*p=v->p+ao+(size_t)i*20;uint32_t fmt=sxmx_u32(p+8,false),components=sxmx_u32(p+12,false);size_t at=sxmx_u32(p+16,false);if(components>4)return false;if(fmt==7){if(!sxmx_table(v,&sxmx_iqm_float,at,(uint64_t)verts*components,v->n))return false;}else if(fmt==1&&components==4){if(!sxmx_table(v,&sxmx_iqm_color,at,verts,v->n))return false;}}return true;}
bool sx_idtech_iqm_build(sxmx_view*v)
{
 return sxmx_iqm(v);
}
#undef SM_ROW
