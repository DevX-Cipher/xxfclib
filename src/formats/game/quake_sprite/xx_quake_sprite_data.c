/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * quake_sprite data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_quake_sprite_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("sprite_type","int32",8,4,SX_ID),
 SX_FIELD("bounding_radius","float32",12,4,SX_NONE),
 SX_FIELD("width","int32",16,4,SX_COUNT_PROP),
 SX_FIELD("height","int32",20,4,SX_COUNT_PROP),
 SX_FIELD("frame_count","int32",24,4,SX_COUNT_PROP),
 SX_FIELD("beam_length","float32",28,4,SX_NONE),
 SX_FIELD("sync_type","int32",32,4,SX_ID),
};
const sx_layout sxgm_quake_sprite_header = {UINT32_C(0x6027005a),"quake_sprite_header",sxgm_quake_sprite_header_fields,SX_COUNT(sxgm_quake_sprite_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_group_count_fields[] = {
 SX_FIELD("frame_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxgm_quake_group_count = {UINT32_C(0x6027005c),"quake_group_count",sxgm_quake_group_count_fields,SX_COUNT(sxgm_quake_group_count_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_interval_fields[] = {
 SX_FIELD("interval","float32",0,4,SX_NONE),
};
const sx_layout sxgm_quake_interval = {UINT32_C(0x6027005d),"quake_interval",sxgm_quake_interval_fields,SX_COUNT(sxgm_quake_interval_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_sprite_frame_fields[] = {
 SX_FIELD("origin_x","int32",0,4,SX_NONE),
 SX_FIELD("origin_y","int32",4,4,SX_NONE),
 SX_FIELD("width","int32",8,4,SX_COUNT_PROP),
 SX_FIELD("height","int32",12,4,SX_COUNT_PROP),
};
const sx_layout sxgm_quake_sprite_frame = {UINT32_C(0x6027005e),"quake_sprite_frame",sxgm_quake_sprite_frame_fields,SX_COUNT(sxgm_quake_sprite_frame_fields),SX_LE};
#define SXGM_LIMIT 20000U
static bool sxgm_sprite(sx_context *c){uint8_t b[36];if(!sxgm_read(c,0,b,36)||!sxgm_add(c,&sxgm_quake_sprite_header,0))return false;uint64_t n=sxgm32(b+24,false),p=36;if(n>SXGM_LIMIT)return true;for(uint64_t i=0;i<n&&c->count<SXGM_LIMIT;i++){uint64_t kind,frames=1;if(!sxgm_word(c,p,4,false,&kind)||kind>1)break;if(!sxgm_add(c,&sxgm_quake_frame_type,p))return false;p+=4;if(kind){if(!sxgm_word(c,p,4,false,&frames)||!frames||frames>SXGM_LIMIT||!sxgm_span(c,p+4,frames*4))break;if(!sxgm_add(c,&sxgm_quake_group_count,p)||!sxgm_table(c,&sxgm_quake_interval,p+4,frames))return false;p+=4+frames*4;}
 for(uint64_t j=0;j<frames;j++){if(!sxgm_read(c,p,b,16))return true;uint64_t w=sxgm32(b+8,false),h=sxgm32(b+12,false);if(!w||!h||w>16384||h>16384||!sxgm_span(c,p+16,w*h))return true;if(!sxgm_add(c,&sxgm_quake_sprite_frame,p))return false;p+=16+w*h;}}return true;}
bool sx_quake_sprite_build(sx_context*c)
{
 return sxgm_sprite(c);
}
