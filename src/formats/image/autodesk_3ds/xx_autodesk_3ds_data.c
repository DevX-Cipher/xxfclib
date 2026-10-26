/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AUTODESK_3DS data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_3ds_chunk_fields[] = {
    SX_FIELD("chunk_type","uint16",0,2,SX_ID),
    SX_FIELD("chunk_size","uint32",2,4,SX_SIZE),
};
const sx_layout sxmo_3ds_chunk = {UINT32_C(0x60210048),"3ds_chunk",sxmo_3ds_chunk_fields,SX_COUNT(sxmo_3ds_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_version_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
};
const sx_layout sxmo_3ds_version = {UINT32_C(0x60210049),"3ds_version",sxmo_3ds_version_fields,SX_COUNT(sxmo_3ds_version_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_vertex_count_fields[] = {
    SX_FIELD("vertex_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxmo_3ds_vertex_count = {UINT32_C(0x6021004a),"3ds_vertex_count",sxmo_3ds_vertex_count_fields,SX_COUNT(sxmo_3ds_vertex_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_face_count_fields[] = {
    SX_FIELD("face_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxmo_3ds_face_count = {UINT32_C(0x6021004b),"3ds_face_count",sxmo_3ds_face_count_fields,SX_COUNT(sxmo_3ds_face_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_uv_count_fields[] = {
    SX_FIELD("uv_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxmo_3ds_uv_count = {UINT32_C(0x6021004c),"3ds_uv_count",sxmo_3ds_uv_count_fields,SX_COUNT(sxmo_3ds_uv_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_vertex_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
const sx_layout sxmo_3ds_vertex = {UINT32_C(0x6021004d),"3ds_vertex",sxmo_3ds_vertex_fields,SX_COUNT(sxmo_3ds_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_uv_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
};
const sx_layout sxmo_3ds_uv = {UINT32_C(0x6021004e),"3ds_uv",sxmo_3ds_uv_fields,SX_COUNT(sxmo_3ds_uv_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_face_fields[] = {
    SX_FIELD("vertex0","uint16",0,2,SX_ID),
    SX_FIELD("vertex1","uint16",2,2,SX_ID),
    SX_FIELD("vertex2","uint16",4,2,SX_ID),
    SX_FIELD("flags","uint16",6,2,SX_FLAGS),
};
const sx_layout sxmo_3ds_face = {UINT32_C(0x6021004f),"3ds_face",sxmo_3ds_face_fields,SX_COUNT(sxmo_3ds_face_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_3ds_local_matrix_fields[] = {
    SX_FIELD("x_axis","float32[3]",0,12,SX_NONE),
    SX_FIELD("y_axis","float32[3]",12,12,SX_NONE),
    SX_FIELD("z_axis","float32[3]",24,12,SX_NONE),
    SX_FIELD("origin","float32[3]",36,12,SX_NONE),
};
const sx_layout sxmo_3ds_local_matrix = {UINT32_C(0x60210050),"3ds_local_matrix",sxmo_3ds_local_matrix_fields,SX_COUNT(sxmo_3ds_local_matrix_fields),SX_LE};
static bool sxmo_3ds_chunks(sx_context*c,uint64_t p,uint64_t end,unsigned depth,unsigned*budget){while(p<end&&depth<12&&*budget<16000){(*budget)++;uint8_t h[6];if(end-p<6||!sxmo_read(c,p,h,6))break;unsigned id=sxmo16(h,false);uint64_t n=sxmo32(h+2,false);if(n<6||n>end-p)break;if(!sxmo_add(c,&sxmo_3ds_chunk,p))return false;uint64_t q=p+6,stop=p+n;
 if(id==0x4d4d||id==0x3d3d||id==0x4100){if(!sxmo_3ds_chunks(c,q,stop,depth+1,budget))return false;}
 else if(id==0x4000){if(sxmo_string(c,&q,stop,0)&&!sxmo_3ds_chunks(c,q,stop,depth+1,budget))return false;}
 else if((id==2||id==0x3d3e)&&stop-q>=4){if(!sxmo_add(c,&sxmo_3ds_version,q))return false;}
 else if((id==0x4110||id==0x4120||id==0x4140)&&stop-q>=2){if(!sxmo_read(c,q,h,2))return false;unsigned count=sxmo16(h,false),z=id==0x4110?12:8;if((uint64_t)count*z<=stop-q-2){const sx_layout*a=id==0x4110?&sxmo_3ds_vertex_count:id==0x4120?&sxmo_3ds_face_count:&sxmo_3ds_uv_count,*b=id==0x4110?&sxmo_3ds_vertex:id==0x4120?&sxmo_3ds_face:&sxmo_3ds_uv;if(!sxmo_add(c,a,q)||!sxmo_table(c,b,q+2,count))return false;}}
 else if(id==0x4160&&stop-q>=48&&!sxmo_add(c,&sxmo_3ds_local_matrix,q))return false;p=stop;}return !c->failed;}
static bool sxmo_3ds(sx_context*c){uint8_t h[2];if(!sxmo_read(c,0,h,2)||sxmo16(h,false)!=0x4d4d)return false;unsigned budget=0;return sxmo_3ds_chunks(c,0,(uint64_t)c->size,0,&budget);}
bool sx_autodesk_3ds_build(sx_context*c)
{
bool ok=false;
ok=sxmo_3ds(c);
return ok&&c->count>0&&sxmo_finish(c);
}
