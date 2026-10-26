/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * OGRE_MESH data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_ogre_mesh_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("serializer_version","char[24]",2,24,SX_STRING),
};
const sx_layout sxmo_ogre_mesh_header = {UINT32_C(0x6021001d),"ogre_mesh_header",sxmo_ogre_mesh_header_fields,SX_COUNT(sxmo_ogre_mesh_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_mesh_chunk_fields[] = {
    SX_FIELD("chunk_type","uint16",0,2,SX_ID),
    SX_FIELD("chunk_size","uint32",2,4,SX_SIZE),
};
const sx_layout sxmo_ogre_mesh_chunk = {UINT32_C(0x6021001e),"ogre_mesh_chunk",sxmo_ogre_mesh_chunk_fields,SX_COUNT(sxmo_ogre_mesh_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_mesh_animation_fields[] = {
    SX_FIELD("skeletally_animated","uint8",0,1,SX_FLAGS),
};
const sx_layout sxmo_ogre_mesh_animation = {UINT32_C(0x6021001f),"ogre_mesh_animation",sxmo_ogre_mesh_animation_fields,SX_COUNT(sxmo_ogre_mesh_animation_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_submesh_fields[] = {
    SX_FIELD("use_shared_vertices","uint8",0,1,SX_FLAGS),
    SX_FIELD("index_count","uint32",1,4,SX_COUNT_PROP),
    SX_FIELD("indices_are_32bit","uint8",5,1,SX_FLAGS),
};
const sx_layout sxmo_ogre_submesh = {UINT32_C(0x60210020),"ogre_submesh",sxmo_ogre_submesh_fields,SX_COUNT(sxmo_ogre_submesh_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_index16_fields[] = {
    SX_FIELD("vertex_index","uint16",0,2,SX_ID),
};
const sx_layout sxmo_ogre_index16 = {UINT32_C(0x60210021),"ogre_index16",sxmo_ogre_index16_fields,SX_COUNT(sxmo_ogre_index16_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_vertex_count_fields[] = {
    SX_FIELD("vertex_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmo_ogre_vertex_count = {UINT32_C(0x60210022),"ogre_vertex_count",sxmo_ogre_vertex_count_fields,SX_COUNT(sxmo_ogre_vertex_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_vertex_element_fields[] = {
    SX_FIELD("source","uint16",0,2,SX_ID),
    SX_FIELD("element_type","uint16",2,2,SX_ID),
    SX_FIELD("semantic","uint16",4,2,SX_ID),
    SX_FIELD("offset","uint16",6,2,SX_OFFSET),
    SX_FIELD("semantic_index","uint16",8,2,SX_ID),
};
const sx_layout sxmo_ogre_vertex_element = {UINT32_C(0x60210023),"ogre_vertex_element",sxmo_ogre_vertex_element_fields,SX_COUNT(sxmo_ogre_vertex_element_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_vertex_buffer_fields[] = {
    SX_FIELD("binding_index","uint16",0,2,SX_ID),
    SX_FIELD("vertex_size","uint16",2,2,SX_SIZE),
};
const sx_layout sxmo_ogre_vertex_buffer = {UINT32_C(0x60210024),"ogre_vertex_buffer",sxmo_ogre_vertex_buffer_fields,SX_COUNT(sxmo_ogre_vertex_buffer_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_position_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
const sx_layout sxmo_ogre_position = {UINT32_C(0x60210025),"ogre_position",sxmo_ogre_position_fields,SX_COUNT(sxmo_ogre_position_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_operation_fields[] = {
    SX_FIELD("operation_type","uint16",0,2,SX_ID),
};
const sx_layout sxmo_ogre_operation = {UINT32_C(0x60210026),"ogre_operation",sxmo_ogre_operation_fields,SX_COUNT(sxmo_ogre_operation_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_ogre_bounds_fields[] = {
    SX_FIELD("minimum","float32[3]",0,12,SX_NONE),
    SX_FIELD("maximum","float32[3]",12,12,SX_NONE),
    SX_FIELD("radius","float32",24,4,SX_NONE),
};
const sx_layout sxmo_ogre_bounds = {UINT32_C(0x60210027),"ogre_bounds",sxmo_ogre_bounds_fields,SX_COUNT(sxmo_ogre_bounds_fields),SX_LE};
static bool sxmo_ogre_mesh_chunks(sx_context*c,uint64_t p,uint64_t end,unsigned depth,unsigned*budget){while(p<end&&depth<8&&*budget<16000){(*budget)++;uint8_t h[6];if(end-p<6||!sxmo_read(c,p,h,6))break;unsigned tag=sxmo16(h,false);uint64_t n=sxmo32(h+2,false);if(n<6||n>end-p)break;uint64_t q=p+6,stop=p+n;if(!sxmo_add(c,&sxmo_ogre_mesh_chunk,p))return false;
 if(tag==0x3000&&stop-q>=1){if(!sxmo_take(c,&sxmo_ogre_mesh_animation,&q,stop)||!sxmo_ogre_mesh_chunks(c,q,stop,depth+1,budget))return false;}
 else if(tag==0x4000&&sxmo_string(c,&q,stop,10)&&stop-q>=6){if(!sxmo_read(c,q,h,6))return false;uint64_t count=sxmo32(h+1,false),z=h[5]?4:2;if(!h[5]&&count<=1000000&&count*z<=stop-q-6){if(!sxmo_take(c,&sxmo_ogre_submesh,&q,stop)||!sxmo_table(c,&sxmo_ogre_index16,q,count))return false;q+=count*z;if(!sxmo_ogre_mesh_chunks(c,q,stop,depth+1,budget))return false;}}
 else if(tag==0x5000&&stop-q>=4){if(!sxmo_take(c,&sxmo_ogre_vertex_count,&q,stop)||!sxmo_ogre_mesh_chunks(c,q,stop,depth+1,budget))return false;}
 else if(tag==0x5100){if(!sxmo_ogre_mesh_chunks(c,q,stop,depth+1,budget))return false;}
 else if(tag==0x5110&&stop-q>=10){if(!sxmo_add(c,&sxmo_ogre_vertex_element,q))return false;}
 else if(tag==0x5200&&stop-q>=4){if(!sxmo_take(c,&sxmo_ogre_vertex_buffer,&q,stop)||!sxmo_ogre_mesh_chunks(c,q,stop,depth+1,budget))return false;}
 else if(tag==0x5210&&(stop-q)%12==0&&(stop-q)/12<=1000000){if(!sxmo_table(c,&sxmo_ogre_position,q,(stop-q)/12))return false;}
 else if(tag==0x4010&&stop-q>=2){if(!sxmo_add(c,&sxmo_ogre_operation,q))return false;}
 else if(tag==0x9000&&stop-q>=28&&!sxmo_add(c,&sxmo_ogre_bounds,q))return false;p=stop;}return !c->failed;}
static bool sxmo_ogre_mesh(sx_context*c){uint8_t h[26];if(!sxmo_read(c,0,h,26)||xx_rt_memcmp(h,"\0\x10[MeshSerializer_v1.100]\n",26)||!sxmo_add(c,&sxmo_ogre_mesh_header,0))return false;unsigned budget=0;return sxmo_ogre_mesh_chunks(c,26,(uint64_t)c->size,0,&budget);}
bool sx_ogre_mesh_build(sx_context*c)
{
bool ok=false;
ok=sxmo_ogre_mesh(c);
return ok&&c->count>0&&sxmo_finish(c);
}
