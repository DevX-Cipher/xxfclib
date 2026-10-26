/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BLITZ3D_B3D data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_b3d_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
    SX_FIELD("version","int32",8,4,SX_ID),
};
const sx_layout sxmo_b3d_header = {UINT32_C(0x60210001),"b3d_header",sxmo_b3d_header_fields,SX_COUNT(sxmo_b3d_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_chunk_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
};
const sx_layout sxmo_b3d_chunk = {UINT32_C(0x60210002),"b3d_chunk",sxmo_b3d_chunk_fields,SX_COUNT(sxmo_b3d_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_texture_fields[] = {
    SX_FIELD("flags","int32",0,4,SX_FLAGS),
    SX_FIELD("blend","int32",4,4,SX_ID),
    SX_FIELD("x_position","float32",8,4,SX_NONE),
    SX_FIELD("y_position","float32",12,4,SX_NONE),
    SX_FIELD("x_scale","float32",16,4,SX_NONE),
    SX_FIELD("y_scale","float32",20,4,SX_NONE),
    SX_FIELD("rotation","float32",24,4,SX_NONE),
};
const sx_layout sxmo_b3d_texture = {UINT32_C(0x60210003),"b3d_texture",sxmo_b3d_texture_fields,SX_COUNT(sxmo_b3d_texture_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_brush_count_fields[] = {
    SX_FIELD("texture_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmo_b3d_brush_count = {UINT32_C(0x60210004),"b3d_brush_count",sxmo_b3d_brush_count_fields,SX_COUNT(sxmo_b3d_brush_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_texture_index_fields[] = {
    SX_FIELD("texture_index","int32",0,4,SX_ID),
};
const sx_layout sxmo_b3d_texture_index = {UINT32_C(0x60210005),"b3d_texture_index",sxmo_b3d_texture_index_fields,SX_COUNT(sxmo_b3d_texture_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_brush_fields[] = {
    SX_FIELD("red","float32",0,4,SX_NONE),
    SX_FIELD("green","float32",4,4,SX_NONE),
    SX_FIELD("blue","float32",8,4,SX_NONE),
    SX_FIELD("alpha","float32",12,4,SX_NONE),
    SX_FIELD("shininess","float32",16,4,SX_NONE),
    SX_FIELD("blend","int32",20,4,SX_ID),
    SX_FIELD("effects","int32",24,4,SX_FLAGS),
};
const sx_layout sxmo_b3d_brush = {UINT32_C(0x60210006),"b3d_brush",sxmo_b3d_brush_fields,SX_COUNT(sxmo_b3d_brush_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_node_fields[] = {
    SX_FIELD("position","float32[3]",0,12,SX_NONE),
    SX_FIELD("scale","float32[3]",12,12,SX_NONE),
    SX_FIELD("rotation_wxyz","float32[4]",24,16,SX_NONE),
};
const sx_layout sxmo_b3d_node = {UINT32_C(0x60210007),"b3d_node",sxmo_b3d_node_fields,SX_COUNT(sxmo_b3d_node_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_brush_index_fields[] = {
    SX_FIELD("brush_index","int32",0,4,SX_ID),
};
const sx_layout sxmo_b3d_brush_index = {UINT32_C(0x60210008),"b3d_brush_index",sxmo_b3d_brush_index_fields,SX_COUNT(sxmo_b3d_brush_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_vertices_fields[] = {
    SX_FIELD("flags","int32",0,4,SX_FLAGS),
    SX_FIELD("texture_coordinate_sets","int32",4,4,SX_COUNT_PROP),
    SX_FIELD("texture_coordinate_size","int32",8,4,SX_COUNT_PROP),
};
const sx_layout sxmo_b3d_vertices = {UINT32_C(0x60210009),"b3d_vertices",sxmo_b3d_vertices_fields,SX_COUNT(sxmo_b3d_vertices_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_position_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
const sx_layout sxmo_b3d_position = {UINT32_C(0x6021000a),"b3d_position",sxmo_b3d_position_fields,SX_COUNT(sxmo_b3d_position_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_normal_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
const sx_layout sxmo_b3d_normal = {UINT32_C(0x6021000b),"b3d_normal",sxmo_b3d_normal_fields,SX_COUNT(sxmo_b3d_normal_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_color_fields[] = {
    SX_FIELD("red","float32",0,4,SX_NONE),
    SX_FIELD("green","float32",4,4,SX_NONE),
    SX_FIELD("blue","float32",8,4,SX_NONE),
    SX_FIELD("alpha","float32",12,4,SX_NONE),
};
const sx_layout sxmo_b3d_color = {UINT32_C(0x6021000c),"b3d_color",sxmo_b3d_color_fields,SX_COUNT(sxmo_b3d_color_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_texture_coordinate_fields[] = {
    SX_FIELD("coordinate","float32",0,4,SX_NONE),
};
const sx_layout sxmo_b3d_texture_coordinate = {UINT32_C(0x6021000d),"b3d_texture_coordinate",sxmo_b3d_texture_coordinate_fields,SX_COUNT(sxmo_b3d_texture_coordinate_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_b3d_triangle_fields[] = {
    SX_FIELD("vertex0","int32",0,4,SX_ID),
    SX_FIELD("vertex1","int32",4,4,SX_ID),
    SX_FIELD("vertex2","int32",8,4,SX_ID),
};
const sx_layout sxmo_b3d_triangle = {UINT32_C(0x6021000e),"b3d_triangle",sxmo_b3d_triangle_fields,SX_COUNT(sxmo_b3d_triangle_fields),SX_LE};
static bool sxmo_b3d_chunks(sx_context*c,uint64_t p,uint64_t end,unsigned depth,unsigned*budget){while(p<end&&depth<32&&*budget<16000){(*budget)++;uint8_t h[12];if(end-p<8||!sxmo_read(c,p,h,8))break;uint32_t n=sxmo32(h+4,false);if(n>INT32_MAX||n>end-p-8)break;uint64_t q=p+8,stop=q+n;if(!sxmo_add(c,&sxmo_b3d_chunk,p))return false;
 if(!xx_rt_memcmp(h,"TEXS",4)){for(unsigned i=0;q<stop&&i<1024;i++){if(!sxmo_string(c,&q,stop,0)||stop-q<28)break;if(!sxmo_take(c,&sxmo_b3d_texture,&q,stop))return false;}}
 else if(!xx_rt_memcmp(h,"BRUS",4)&&n>=4){if(!sxmo_read(c,q,h,4))return false;unsigned refs=sxmo32(h,false);if(refs<=8){if(!sxmo_take(c,&sxmo_b3d_brush_count,&q,stop))return false;for(unsigned i=0;q<stop&&i<1024;i++){if(!sxmo_string(c,&q,stop,0)||stop-q<28+refs*4)break;if(!sxmo_take(c,&sxmo_b3d_brush,&q,stop)||!sxmo_table(c,&sxmo_b3d_texture_index,q,refs))return false;q+=refs*4;}}}
 else if(!xx_rt_memcmp(h,"NODE",4)){if(sxmo_string(c,&q,stop,0)&&stop-q>=40){if(!sxmo_take(c,&sxmo_b3d_node,&q,stop)||!sxmo_b3d_chunks(c,q,stop,depth+1,budget))return false;}}
 else if(!xx_rt_memcmp(h,"MESH",4)&&n>=4){if(!sxmo_take(c,&sxmo_b3d_brush_index,&q,stop)||!sxmo_b3d_chunks(c,q,stop,depth+1,budget))return false;}
 else if(!xx_rt_memcmp(h,"TRIS",4)&&n>=4){if(!sxmo_take(c,&sxmo_b3d_brush_index,&q,stop)||!sxmo_table(c,&sxmo_b3d_triangle,q,(stop-q)/12))return false;}
 else if(!xx_rt_memcmp(h,"VRTS",4)&&n>=12){if(!sxmo_read(c,q,h,12)||!sxmo_take(c,&sxmo_b3d_vertices,&q,stop))return false;unsigned flags=sxmo32(h,false),sets=sxmo32(h+4,false),size=sxmo32(h+8,false);if(flags<=3&&sets<=4&&size<=4){uint64_t z=12+((flags&1)?12:0)+((flags&2)?16:0)+sets*size*4;for(unsigned i=0;z<=stop-q&&i<4096;i++){if(!sxmo_take(c,&sxmo_b3d_position,&q,stop)||((flags&1)&&!sxmo_take(c,&sxmo_b3d_normal,&q,stop))||((flags&2)&&!sxmo_take(c,&sxmo_b3d_color,&q,stop))||!sxmo_table(c,&sxmo_b3d_texture_coordinate,q,sets*size))return false;q+=sets*size*4;}}}p=stop;}return !c->failed;}
static bool sxmo_b3d(sx_context*c){uint8_t h[12];if(!sxmo_read(c,0,h,12)||xx_rt_memcmp(h,"BB3D",4)||sxmo32(h+8,false)!=1||!sxmo_add(c,&sxmo_b3d_header,0))return false;uint64_t end=8+(uint64_t)sxmo32(h+4,false);if(end>(uint64_t)c->size)end=(uint64_t)c->size;unsigned budget=0;return sxmo_b3d_chunks(c,12,end,0,&budget);}
bool sx_blitz3d_b3d_build(sx_context*c)
{
bool ok=false;
ok=sxmo_b3d(c);
return ok&&c->count>0&&sxmo_finish(c);
}
