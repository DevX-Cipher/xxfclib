/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MILKSHAPE_MS3D data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_ms3d_header_fields[] = {
    SX_FIELD("signature","char[10]",0,10,SX_SIGNATURE),
    SX_FIELD("version","int32",10,4,SX_ID),
};
const sx_layout sxmo_ms3d_header = {UINT32_C(0x6021000f),"ms3d_header",sxmo_ms3d_header_fields,SX_COUNT(sxmo_ms3d_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_vertex_count_fields[] = {
    SX_FIELD("vertex_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxmo_ms3d_vertex_count = {UINT32_C(0x60210010),"ms3d_vertex_count",sxmo_ms3d_vertex_count_fields,SX_COUNT(sxmo_ms3d_vertex_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_triangle_count_fields[] = {
    SX_FIELD("triangle_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxmo_ms3d_triangle_count = {UINT32_C(0x60210011),"ms3d_triangle_count",sxmo_ms3d_triangle_count_fields,SX_COUNT(sxmo_ms3d_triangle_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_group_count_fields[] = {
    SX_FIELD("group_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxmo_ms3d_group_count = {UINT32_C(0x60210012),"ms3d_group_count",sxmo_ms3d_group_count_fields,SX_COUNT(sxmo_ms3d_group_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_material_count_fields[] = {
    SX_FIELD("material_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxmo_ms3d_material_count = {UINT32_C(0x60210013),"ms3d_material_count",sxmo_ms3d_material_count_fields,SX_COUNT(sxmo_ms3d_material_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_vertex_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("position","float32[3]",1,12,SX_NONE),
    SX_FIELD("bone_index","int8",13,1,SX_ID),
    SX_FIELD("reference_count","uint8",14,1,SX_COUNT_PROP),
};
const sx_layout sxmo_ms3d_vertex = {UINT32_C(0x60210014),"ms3d_vertex",sxmo_ms3d_vertex_fields,SX_COUNT(sxmo_ms3d_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_triangle_fields[] = {
    SX_FIELD("flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("vertex_indices","uint16[3]",2,6,SX_ID),
    SX_FIELD("vertex_normals","float32[9]",8,36,SX_NONE),
    SX_FIELD("texture_s","float32[3]",44,12,SX_NONE),
    SX_FIELD("texture_t","float32[3]",56,12,SX_NONE),
    SX_FIELD("smoothing_group","uint8",68,1,SX_ID),
    SX_FIELD("group_index","uint8",69,1,SX_ID),
};
const sx_layout sxmo_ms3d_triangle = {UINT32_C(0x60210015),"ms3d_triangle",sxmo_ms3d_triangle_fields,SX_COUNT(sxmo_ms3d_triangle_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_group_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("name","char[32]",1,32,SX_STRING),
    SX_FIELD("triangle_count","uint16",33,2,SX_COUNT_PROP),
};
const sx_layout sxmo_ms3d_group = {UINT32_C(0x60210016),"ms3d_group",sxmo_ms3d_group_fields,SX_COUNT(sxmo_ms3d_group_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_triangle_index_fields[] = {
    SX_FIELD("triangle_index","uint16",0,2,SX_ID),
};
const sx_layout sxmo_ms3d_triangle_index = {UINT32_C(0x60210017),"ms3d_triangle_index",sxmo_ms3d_triangle_index_fields,SX_COUNT(sxmo_ms3d_triangle_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_material_index_fields[] = {
    SX_FIELD("material_index","int8",0,1,SX_ID),
};
const sx_layout sxmo_ms3d_material_index = {UINT32_C(0x60210018),"ms3d_material_index",sxmo_ms3d_material_index_fields,SX_COUNT(sxmo_ms3d_material_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_material_fields[] = {
    SX_FIELD("name","char[32]",0,32,SX_STRING),
    SX_FIELD("ambient","float32[4]",32,16,SX_NONE),
    SX_FIELD("diffuse","float32[4]",48,16,SX_NONE),
    SX_FIELD("specular","float32[4]",64,16,SX_NONE),
    SX_FIELD("emissive","float32[4]",80,16,SX_NONE),
    SX_FIELD("shininess","float32",96,4,SX_NONE),
    SX_FIELD("transparency","float32",100,4,SX_NONE),
    SX_FIELD("mode","uint8",104,1,SX_FLAGS),
    SX_FIELD("texture","char[128]",105,128,SX_STRING),
    SX_FIELD("alpha_map","char[128]",233,128,SX_STRING),
};
const sx_layout sxmo_ms3d_material = {UINT32_C(0x60210019),"ms3d_material",sxmo_ms3d_material_fields,SX_COUNT(sxmo_ms3d_material_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ms3d_animation_fields[] = {
    SX_FIELD("frames_per_second","float32",0,4,SX_NONE),
    SX_FIELD("current_time","float32",4,4,SX_NONE),
    SX_FIELD("total_frames","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("joint_count","uint16",12,2,SX_COUNT_PROP),
};
const sx_layout sxmo_ms3d_animation = {UINT32_C(0x6021001a),"ms3d_animation",sxmo_ms3d_animation_fields,SX_COUNT(sxmo_ms3d_animation_fields),SX_LE};
static bool sxmo_ms3d(sx_context*c){uint8_t h[35];if(!sxmo_read(c,0,h,14)||xx_rt_memcmp(h,"MS3D000000",10)||!sxmo_add(c,&sxmo_ms3d_header,0))return false;uint64_t p=14,end=(uint64_t)c->size;const sx_layout*counts[]={&sxmo_ms3d_vertex_count,&sxmo_ms3d_triangle_count,&sxmo_ms3d_group_count,&sxmo_ms3d_material_count};
 for(unsigned kind=0;kind<4;kind++){if(end-p<2||!sxmo_read(c,p,h,2))return true;unsigned n=sxmo16(h,false);if(!sxmo_take(c,counts[kind],&p,end))return false;if(kind==2){if(n>128)return true;for(unsigned i=0;i<n;i++){if(end-p<35||!sxmo_read(c,p,h,35))return true;unsigned tris=sxmo16(h+33,false);if((uint64_t)tris*2+36>end-p)return true;if(!sxmo_take(c,&sxmo_ms3d_group,&p,end)||!sxmo_table(c,&sxmo_ms3d_triangle_index,p,tris))return false;p+=tris*2;if(!sxmo_take(c,&sxmo_ms3d_material_index,&p,end))return false;}}
 else{const sx_layout*l=kind==0?&sxmo_ms3d_vertex:kind==1?&sxmo_ms3d_triangle:&sxmo_ms3d_material;uint64_t z=kind==0?15:kind==1?70:361;if(n*z>end-p)return true;if(!sxmo_table(c,l,p,n))return false;p+=n*z;}}
 return end-p<14||sxmo_add(c,&sxmo_ms3d_animation,p);}
bool sx_milkshape_ms3d_build(sx_context*c)
{
bool ok=false;
ok=sxmo_ms3d(c);
return ok&&c->count>0&&sxmo_finish(c);
}
