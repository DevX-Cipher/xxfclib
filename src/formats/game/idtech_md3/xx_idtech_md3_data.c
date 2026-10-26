/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * idtech_md3 data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_md3_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("name","char[64]",8,64,SX_STRING),
 SX_FIELD("flags","int32",72,4,SX_FLAGS),
 SX_FIELD("frame_count","int32",76,4,SX_COUNT_PROP),
 SX_FIELD("tag_count","int32",80,4,SX_COUNT_PROP),
 SX_FIELD("surface_count","int32",84,4,SX_COUNT_PROP),
 SX_FIELD("skin_count","int32",88,4,SX_COUNT_PROP),
 SX_FIELD("frames_offset","int32",92,4,SX_OFFSET),
 SX_FIELD("tags_offset","int32",96,4,SX_OFFSET),
 SX_FIELD("surfaces_offset","int32",100,4,SX_OFFSET),
 SX_FIELD("end_offset","int32",104,4,SX_OFFSET),
};
const sx_layout sxgm_md3_header = {UINT32_C(0x60270051),"md3_header",sxgm_md3_header_fields,SX_COUNT(sxgm_md3_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md3_frame_fields[] = {
 SX_FIELD("bounds_min_0","float32",0,4,SX_NONE),
 SX_FIELD("bounds_min_1","float32",4,4,SX_NONE),
 SX_FIELD("bounds_min_2","float32",8,4,SX_NONE),
 SX_FIELD("bounds_max_0","float32",12,4,SX_NONE),
 SX_FIELD("bounds_max_1","float32",16,4,SX_NONE),
 SX_FIELD("bounds_max_2","float32",20,4,SX_NONE),
 SX_FIELD("origin_0","float32",24,4,SX_NONE),
 SX_FIELD("origin_1","float32",28,4,SX_NONE),
 SX_FIELD("origin_2","float32",32,4,SX_NONE),
 SX_FIELD("radius","float32",36,4,SX_NONE),
 SX_FIELD("name","char[16]",40,16,SX_STRING),
};
const sx_layout sxgm_md3_frame = {UINT32_C(0x60270052),"md3_frame",sxgm_md3_frame_fields,SX_COUNT(sxgm_md3_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md3_tag_fields[] = {
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("origin_0","float32",64,4,SX_NONE),
 SX_FIELD("origin_1","float32",68,4,SX_NONE),
 SX_FIELD("origin_2","float32",72,4,SX_NONE),
 SX_FIELD("axis_0","float32",76,4,SX_NONE),
 SX_FIELD("axis_1","float32",80,4,SX_NONE),
 SX_FIELD("axis_2","float32",84,4,SX_NONE),
 SX_FIELD("axis_3","float32",88,4,SX_NONE),
 SX_FIELD("axis_4","float32",92,4,SX_NONE),
 SX_FIELD("axis_5","float32",96,4,SX_NONE),
 SX_FIELD("axis_6","float32",100,4,SX_NONE),
 SX_FIELD("axis_7","float32",104,4,SX_NONE),
 SX_FIELD("axis_8","float32",108,4,SX_NONE),
};
const sx_layout sxgm_md3_tag = {UINT32_C(0x60270053),"md3_tag",sxgm_md3_tag_fields,SX_COUNT(sxgm_md3_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md3_surface_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("name","char[64]",4,64,SX_STRING),
 SX_FIELD("flags","int32",68,4,SX_FLAGS),
 SX_FIELD("frame_count","int32",72,4,SX_COUNT_PROP),
 SX_FIELD("shader_count","int32",76,4,SX_COUNT_PROP),
 SX_FIELD("vertex_count","int32",80,4,SX_COUNT_PROP),
 SX_FIELD("triangle_count","int32",84,4,SX_COUNT_PROP),
 SX_FIELD("triangles_offset","int32",88,4,SX_OFFSET),
 SX_FIELD("shaders_offset","int32",92,4,SX_OFFSET),
 SX_FIELD("texcoords_offset","int32",96,4,SX_OFFSET),
 SX_FIELD("vertices_offset","int32",100,4,SX_OFFSET),
 SX_FIELD("end_offset","int32",104,4,SX_OFFSET),
};
const sx_layout sxgm_md3_surface = {UINT32_C(0x60270054),"md3_surface",sxgm_md3_surface_fields,SX_COUNT(sxgm_md3_surface_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md3_triangle_fields[] = {
 SX_FIELD("vertex0","int32",0,4,SX_ID),
 SX_FIELD("vertex1","int32",4,4,SX_ID),
 SX_FIELD("vertex2","int32",8,4,SX_ID),
};
const sx_layout sxgm_md3_triangle = {UINT32_C(0x60270055),"md3_triangle",sxgm_md3_triangle_fields,SX_COUNT(sxgm_md3_triangle_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md3_shader_fields[] = {
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("shader_index","int32",64,4,SX_ID),
};
const sx_layout sxgm_md3_shader = {UINT32_C(0x60270056),"md3_shader",sxgm_md3_shader_fields,SX_COUNT(sxgm_md3_shader_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md3_texcoord_fields[] = {
 SX_FIELD("s","float32",0,4,SX_NONE),
 SX_FIELD("t","float32",4,4,SX_NONE),
};
const sx_layout sxgm_md3_texcoord = {UINT32_C(0x60270057),"md3_texcoord",sxgm_md3_texcoord_fields,SX_COUNT(sxgm_md3_texcoord_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_md3_vertex_fields[] = {
 SX_FIELD("x","int16",0,2,SX_NONE),
 SX_FIELD("y","int16",2,2,SX_NONE),
 SX_FIELD("z","int16",4,2,SX_NONE),
 SX_FIELD("normal","int16",6,2,SX_NONE),
};
const sx_layout sxgm_md3_vertex = {UINT32_C(0x60270058),"md3_vertex",sxgm_md3_vertex_fields,SX_COUNT(sxgm_md3_vertex_fields),SX_LE};
#define SXGM_LIMIT 20000U
static bool sxgm_md3(sx_context *c){uint8_t b[108];if(!sxgm_read(c,0,b,108)||!sxgm_add(c,&sxgm_md3_header,0))return false;uint64_t frames=sxgm32(b+76,false),tags=sxgm32(b+80,false),surfaces=sxgm32(b+84,false),p=sxgm32(b+100,false);if(frames>1024||tags>16||surfaces>32)return true;if(!sxgm_table(c,&sxgm_md3_frame,sxgm32(b+92,false),frames)||!sxgm_table(c,&sxgm_md3_tag,sxgm32(b+96,false),frames*tags))return false;
 for(uint64_t i=0;i<surfaces&&c->count<SXGM_LIMIT;i++){if(!sxgm_read(c,p,b,108)||xx_rt_memcmp(b,"IDP3",4))break;uint64_t sf=sxgm32(b+72,false),sh=sxgm32(b+76,false),v=sxgm32(b+80,false),t=sxgm32(b+84,false),z=sxgm32(b+104,false);if(z<108||!sxgm_span(c,p,z))break;if(!sxgm_add(c,&sxgm_md3_surface,p))return false;const sx_layout *ls[]={&sxgm_md3_triangle,&sxgm_md3_shader,&sxgm_md3_texcoord,&sxgm_md3_vertex};uint64_t counts[]={t,sh,v,sf<=1024&&v<=4096?sf*v:UINT64_MAX};unsigned widths[]={12,68,8,8};for(unsigned j=0;j<4;j++){uint64_t at=sxgm32(b+88+j*4,false),n=counts[j];if(n<=SXGM_LIMIT&&at<=z&&n<=(z-at)/widths[j]&&!sxgm_table(c,ls[j],p+at,n))return false;}p+=z;}return true;}
bool sx_idtech_md3_build(sx_context*c)
{
 return sxgm_md3(c);
}
