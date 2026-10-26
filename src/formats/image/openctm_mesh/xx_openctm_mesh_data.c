/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * OPENCTM_MESH data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_openctm_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("compression_method","char[4]",8,4,SX_ID),
    SX_FIELD("vertex_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("triangle_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("uv_map_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("attribute_map_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",28,4,SX_FLAGS),
};
const sx_layout sxmo_openctm_header = {UINT32_C(0x60210062),"openctm_header",sxmo_openctm_header_fields,SX_COUNT(sxmo_openctm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_openctm_string_length_fields[] = {
    SX_FIELD("byte_length","uint32",0,4,SX_SIZE),
};
const sx_layout sxmo_openctm_string_length = {UINT32_C(0x60210063),"openctm_string_length",sxmo_openctm_string_length_fields,SX_COUNT(sxmo_openctm_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_openctm_tag_fields[] = {
    SX_FIELD("section","char[4]",0,4,SX_ID),
};
const sx_layout sxmo_openctm_tag = {UINT32_C(0x60210064),"openctm_tag",sxmo_openctm_tag_fields,SX_COUNT(sxmo_openctm_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_openctm_triangle_fields[] = {
    SX_FIELD("vertex0","uint32",0,4,SX_ID),
    SX_FIELD("vertex1","uint32",4,4,SX_ID),
    SX_FIELD("vertex2","uint32",8,4,SX_ID),
};
const sx_layout sxmo_openctm_triangle = {UINT32_C(0x60210065),"openctm_triangle",sxmo_openctm_triangle_fields,SX_COUNT(sxmo_openctm_triangle_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_openctm_vertex_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
const sx_layout sxmo_openctm_vertex = {UINT32_C(0x60210066),"openctm_vertex",sxmo_openctm_vertex_fields,SX_COUNT(sxmo_openctm_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_openctm_normal_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
const sx_layout sxmo_openctm_normal = {UINT32_C(0x60210067),"openctm_normal",sxmo_openctm_normal_fields,SX_COUNT(sxmo_openctm_normal_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_openctm_uv_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
};
const sx_layout sxmo_openctm_uv = {UINT32_C(0x60210068),"openctm_uv",sxmo_openctm_uv_fields,SX_COUNT(sxmo_openctm_uv_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_openctm_attribute_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
    SX_FIELD("w","float32",12,4,SX_NONE),
};
const sx_layout sxmo_openctm_attribute = {UINT32_C(0x60210069),"openctm_attribute",sxmo_openctm_attribute_fields,SX_COUNT(sxmo_openctm_attribute_fields),SX_LE};
static bool sxmo_ctm(sx_context*c){uint8_t h[32];if(!sxmo_read(c,0,h,32)||xx_rt_memcmp(h,"OCTM",4)||!sxmo_add(c,&sxmo_openctm_header,0))return false;uint64_t p=32,end=(uint64_t)c->size;uint32_t verts=sxmo32(h+12,false),tris=sxmo32(h+16,false),uv=sxmo32(h+20,false),attrs=sxmo32(h+24,false),flags=sxmo32(h+28,false);if(!sxmo_text(c,&sxmo_openctm_string_length,&p,end)||xx_rt_memcmp(h+8,"RAW\0",4)||verts>1000000||tris>1000000||uv>16||attrs>16)return !c->failed;
 const sx_layout*layouts[]={&sxmo_openctm_triangle,&sxmo_openctm_vertex,&sxmo_openctm_normal};for(unsigned i=0;i<2+(flags&1);i++){uint64_t n=i==0?tris:verts;if(end-p<4+n*12)return true;if(!sxmo_take(c,&sxmo_openctm_tag,&p,end)||!sxmo_table(c,layouts[i],p,n))return false;p+=n*12;}
 for(unsigned i=0;i<uv+attrs;i++){bool tex=i<uv;if(end-p<4)return true;if(!sxmo_take(c,&sxmo_openctm_tag,&p,end)||!sxmo_text(c,&sxmo_openctm_string_length,&p,end)||(tex&&!sxmo_text(c,&sxmo_openctm_string_length,&p,end)))return !c->failed;uint64_t z=tex?8:16;if(verts*z>end-p)return true;if(!sxmo_table(c,tex?&sxmo_openctm_uv:&sxmo_openctm_attribute,p,verts))return false;p+=verts*z;}return !c->failed;}
bool sx_openctm_mesh_build(sx_context*c)
{
bool ok=false;
ok=sxmo_ctm(c);
return ok&&c->count>0&&sxmo_finish(c);
}
