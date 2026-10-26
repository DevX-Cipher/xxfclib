/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * idtech_mdl data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_quake_mdl_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("scale_0","float32",8,4,SX_NONE),
 SX_FIELD("scale_1","float32",12,4,SX_NONE),
 SX_FIELD("scale_2","float32",16,4,SX_NONE),
 SX_FIELD("origin_0","float32",20,4,SX_NONE),
 SX_FIELD("origin_1","float32",24,4,SX_NONE),
 SX_FIELD("origin_2","float32",28,4,SX_NONE),
 SX_FIELD("bounding_radius","float32",32,4,SX_NONE),
 SX_FIELD("eye_position_0","float32",36,4,SX_NONE),
 SX_FIELD("eye_position_1","float32",40,4,SX_NONE),
 SX_FIELD("eye_position_2","float32",44,4,SX_NONE),
 SX_FIELD("skin_count","int32",48,4,SX_COUNT_PROP),
 SX_FIELD("skin_width","int32",52,4,SX_COUNT_PROP),
 SX_FIELD("skin_height","int32",56,4,SX_COUNT_PROP),
 SX_FIELD("vertex_count","int32",60,4,SX_COUNT_PROP),
 SX_FIELD("triangle_count","int32",64,4,SX_COUNT_PROP),
 SX_FIELD("frame_count","int32",68,4,SX_COUNT_PROP),
 SX_FIELD("sync_type","int32",72,4,SX_ID),
 SX_FIELD("flags","int32",76,4,SX_FLAGS),
 SX_FIELD("model_size","float32",80,4,SX_NONE),
};
const sx_layout sxgm_quake_mdl_header = {UINT32_C(0x6027005f),"quake_mdl_header",sxgm_quake_mdl_header_fields,SX_COUNT(sxgm_quake_mdl_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_skin_type_fields[] = {
 SX_FIELD("skin_type","int32",0,4,SX_ID),
};
const sx_layout sxgm_quake_skin_type = {UINT32_C(0x60270060),"quake_skin_type",sxgm_quake_skin_type_fields,SX_COUNT(sxgm_quake_skin_type_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_stvert_fields[] = {
 SX_FIELD("on_seam","int32",0,4,SX_FLAGS),
 SX_FIELD("s","int32",4,4,SX_NONE),
 SX_FIELD("t","int32",8,4,SX_NONE),
};
const sx_layout sxgm_quake_stvert = {UINT32_C(0x60270061),"quake_stvert",sxgm_quake_stvert_fields,SX_COUNT(sxgm_quake_stvert_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_triangle_fields[] = {
 SX_FIELD("faces_front","int32",0,4,SX_FLAGS),
 SX_FIELD("vertex0","int32",4,4,SX_ID),
 SX_FIELD("vertex1","int32",8,4,SX_ID),
 SX_FIELD("vertex2","int32",12,4,SX_ID),
};
const sx_layout sxgm_quake_triangle = {UINT32_C(0x60270062),"quake_triangle",sxgm_quake_triangle_fields,SX_COUNT(sxgm_quake_triangle_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_mdl_frame_fields[] = {
 SX_FIELD("bbox_min_x","uint8",0,1,SX_NONE),
 SX_FIELD("bbox_min_y","uint8",1,1,SX_NONE),
 SX_FIELD("bbox_min_z","uint8",2,1,SX_NONE),
 SX_FIELD("bbox_min_normal","uint8",3,1,SX_ID),
 SX_FIELD("bbox_max_x","uint8",4,1,SX_NONE),
 SX_FIELD("bbox_max_y","uint8",5,1,SX_NONE),
 SX_FIELD("bbox_max_z","uint8",6,1,SX_NONE),
 SX_FIELD("bbox_max_normal","uint8",7,1,SX_ID),
 SX_FIELD("name","char[16]",8,16,SX_STRING),
};
const sx_layout sxgm_quake_mdl_frame = {UINT32_C(0x60270063),"quake_mdl_frame",sxgm_quake_mdl_frame_fields,SX_COUNT(sxgm_quake_mdl_frame_fields),SX_LE};
#define SXGM_LIMIT 20000U
static bool sxgm_mdl(sx_context *c){uint8_t b[84];if(!sxgm_read(c,0,b,84)||!sxgm_add(c,&sxgm_quake_mdl_header,0))return false;uint64_t skins=sxgm32(b+48,false),w=sxgm32(b+52,false),h=sxgm32(b+56,false),v=sxgm32(b+60,false),t=sxgm32(b+64,false),frames=sxgm32(b+68,false),p=84;if(skins>64||w>16384||h>16384||v>4096||t>65536||frames>1024)return true;for(uint64_t i=0;i<skins;i++){uint64_t kind;if(!sxgm_word(c,p,4,false,&kind)||kind||!sxgm_span(c,p+4,w*h))return true;if(!sxgm_add(c,&sxgm_quake_skin_type,p))return false;p+=4+w*h;}if(!sxgm_span(c,p,v*12+t*16))return true;if(!sxgm_table(c,&sxgm_quake_stvert,p,v)||!sxgm_table(c,&sxgm_quake_triangle,p+v*12,t))return false;p+=v*12+t*16;for(uint64_t i=0;i<frames&&c->count<SXGM_LIMIT;i++){uint64_t kind;if(!sxgm_word(c,p,4,false,&kind)||kind||!sxgm_span(c,p+4,24+v*4))break;if(!sxgm_add(c,&sxgm_quake_frame_type,p)||!sxgm_add(c,&sxgm_quake_mdl_frame,p+4)||!sxgm_table(c,&sxgm_quake_vertex,p+28,v))return false;p+=28+v*4;}return true;}
bool sx_idtech_mdl_build(sx_context*c)
{
 return sxgm_mdl(c);
}
