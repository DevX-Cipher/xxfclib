/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SPRING_S3O data structures, moved out of the modelmeta schema family. */
#include "../../xx_format_schema_modelmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmo_s3o_header_fields[] = {
    SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
    SX_FIELD("version","int32",12,4,SX_ID),
    SX_FIELD("radius","float32",16,4,SX_NONE),
    SX_FIELD("height","float32",20,4,SX_NONE),
    SX_FIELD("midpoint","float32[3]",24,12,SX_NONE),
    SX_FIELD("root_piece_offset","int32",36,4,SX_OFFSET),
    SX_FIELD("collision_data_offset","int32",40,4,SX_OFFSET),
    SX_FIELD("texture1_offset","int32",44,4,SX_OFFSET),
    SX_FIELD("texture2_offset","int32",48,4,SX_OFFSET),
};
const sx_layout sxmo_s3o_header = {UINT32_C(0x6021005b),"s3o_header",sxmo_s3o_header_fields,SX_COUNT(sxmo_s3o_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_s3o_piece_fields[] = {
    SX_FIELD("name_offset","int32",0,4,SX_OFFSET),
    SX_FIELD("child_count","int32",4,4,SX_COUNT_PROP),
    SX_FIELD("children_offset","int32",8,4,SX_OFFSET),
    SX_FIELD("vertex_count","int32",12,4,SX_COUNT_PROP),
    SX_FIELD("vertices_offset","int32",16,4,SX_OFFSET),
    SX_FIELD("vertex_type","int32",20,4,SX_ID),
    SX_FIELD("primitive_type","int32",24,4,SX_ID),
    SX_FIELD("index_count","int32",28,4,SX_COUNT_PROP),
    SX_FIELD("indices_offset","int32",32,4,SX_OFFSET),
    SX_FIELD("collision_data_offset","int32",36,4,SX_OFFSET),
    SX_FIELD("offset","float32[3]",40,12,SX_NONE),
};
const sx_layout sxmo_s3o_piece = {UINT32_C(0x6021005c),"s3o_piece",sxmo_s3o_piece_fields,SX_COUNT(sxmo_s3o_piece_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_s3o_vertex_fields[] = {
    SX_FIELD("position","float32[3]",0,12,SX_NONE),
    SX_FIELD("normal","float32[3]",12,12,SX_NONE),
    SX_FIELD("u","float32",24,4,SX_NONE),
    SX_FIELD("v","float32",28,4,SX_NONE),
};
const sx_layout sxmo_s3o_vertex = {UINT32_C(0x6021005d),"s3o_vertex",sxmo_s3o_vertex_fields,SX_COUNT(sxmo_s3o_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_s3o_child_fields[] = {
    SX_FIELD("piece_offset","int32",0,4,SX_OFFSET),
};
const sx_layout sxmo_s3o_child = {UINT32_C(0x6021005e),"s3o_child",sxmo_s3o_child_fields,SX_COUNT(sxmo_s3o_child_fields),SX_LE};
static const xx_data_struct_field_desc sxmo_s3o_index_fields[] = {
    SX_FIELD("vertex_index","int32",0,4,SX_ID),
};
const sx_layout sxmo_s3o_index = {UINT32_C(0x6021005f),"s3o_index",sxmo_s3o_index_fields,SX_COUNT(sxmo_s3o_index_fields),SX_LE};
static bool sxmo_s3o_walk_piece(sx_context*c,uint64_t p,unsigned depth,uint64_t*seen,unsigned*count){if(depth>=32||*count>=256||p<52)return true;for(unsigned i=0;i<*count;i++)if(seen[i]==p)return true;uint8_t h[52];if(!sxmo_read(c,p,h,52))return true;seen[(*count)++]=p;if(!sxmo_add(c,&sxmo_s3o_piece,p))return false;uint64_t children=sxmo32(h+8,false),verts=sxmo32(h+16,false),indices=sxmo32(h+32,false);uint32_t nc=sxmo32(h+4,false),nv=sxmo32(h+12,false),ni=sxmo32(h+28,false);
 if(nv<=65536&&verts>=52&&sxmo_span(c,verts,(uint64_t)nv*32)&&!sxmo_table(c,&sxmo_s3o_vertex,verts,nv))return false;if(ni<=262144&&indices>=52&&sxmo_span(c,indices,(uint64_t)ni*4)&&!sxmo_table(c,&sxmo_s3o_index,indices,ni))return false;
 if(nc<=256&&children>=52&&sxmo_span(c,children,(uint64_t)nc*4)){if(!sxmo_table(c,&sxmo_s3o_child,children,nc))return false;for(unsigned i=0;i<nc;i++){if(!sxmo_read(c,children+i*4,h,4)||!sxmo_s3o_walk_piece(c,sxmo32(h,false),depth+1,seen,count))return false;}}return !c->failed;}
static bool sxmo_s3o(sx_context*c){uint8_t h[52];if(!sxmo_read(c,0,h,52)||xx_rt_memcmp(h,"Spring unit\0",12)||!sxmo_add(c,&sxmo_s3o_header,0))return false;uint64_t seen[256];unsigned count=0;return sxmo_s3o_walk_piece(c,sxmo32(h+36,false),0,seen,&count);}
bool sx_spring_s3o_build(sx_context*c)
{
bool ok=false;
ok=sxmo_s3o(c);
return ok&&c->count>0&&sxmo_finish(c);
}
