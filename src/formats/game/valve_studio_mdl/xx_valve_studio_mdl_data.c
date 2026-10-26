/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * valve_studio_mdl data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_studio_v10_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("name","char[64]",8,64,SX_STRING),
 SX_FIELD("file_size","int32",72,4,SX_SIZE),
 SX_FIELD("eye_position_0","float32",76,4,SX_NONE),
 SX_FIELD("eye_position_1","float32",80,4,SX_NONE),
 SX_FIELD("eye_position_2","float32",84,4,SX_NONE),
 SX_FIELD("hull_min_0","float32",88,4,SX_NONE),
 SX_FIELD("hull_min_1","float32",92,4,SX_NONE),
 SX_FIELD("hull_min_2","float32",96,4,SX_NONE),
 SX_FIELD("hull_max_0","float32",100,4,SX_NONE),
 SX_FIELD("hull_max_1","float32",104,4,SX_NONE),
 SX_FIELD("hull_max_2","float32",108,4,SX_NONE),
 SX_FIELD("bbox_min_0","float32",112,4,SX_NONE),
 SX_FIELD("bbox_min_1","float32",116,4,SX_NONE),
 SX_FIELD("bbox_min_2","float32",120,4,SX_NONE),
 SX_FIELD("bbox_max_0","float32",124,4,SX_NONE),
 SX_FIELD("bbox_max_1","float32",128,4,SX_NONE),
 SX_FIELD("bbox_max_2","float32",132,4,SX_NONE),
 SX_FIELD("flags","int32",136,4,SX_FLAGS),
 SX_FIELD("bone_count","int32",140,4,SX_COUNT_PROP),
 SX_FIELD("bones_offset","int32",144,4,SX_OFFSET),
 SX_FIELD("bone_controller_count","int32",148,4,SX_COUNT_PROP),
 SX_FIELD("bone_controllers_offset","int32",152,4,SX_OFFSET),
 SX_FIELD("hitbox_count","int32",156,4,SX_COUNT_PROP),
 SX_FIELD("hitboxs_offset","int32",160,4,SX_OFFSET),
 SX_FIELD("sequence_count","int32",164,4,SX_COUNT_PROP),
 SX_FIELD("sequences_offset","int32",168,4,SX_OFFSET),
 SX_FIELD("sequence_group_count","int32",172,4,SX_COUNT_PROP),
 SX_FIELD("sequence_groups_offset","int32",176,4,SX_OFFSET),
 SX_FIELD("texture_count","int32",180,4,SX_COUNT_PROP),
 SX_FIELD("textures_offset","int32",184,4,SX_OFFSET),
 SX_FIELD("texture_data_offset","int32",188,4,SX_OFFSET),
 SX_FIELD("skinref_count","int32",192,4,SX_COUNT_PROP),
 SX_FIELD("skin_family_count","int32",196,4,SX_COUNT_PROP),
 SX_FIELD("skins_offset","int32",200,4,SX_OFFSET),
 SX_FIELD("bodypart_count","int32",204,4,SX_COUNT_PROP),
 SX_FIELD("bodyparts_offset","int32",208,4,SX_OFFSET),
 SX_FIELD("attachment_count","int32",212,4,SX_COUNT_PROP),
 SX_FIELD("attachments_offset","int32",216,4,SX_OFFSET),
 SX_FIELD("sound_table","int32",220,4,SX_NONE),
 SX_FIELD("sound_index","int32",224,4,SX_NONE),
 SX_FIELD("sound_groups","int32",228,4,SX_NONE),
 SX_FIELD("sound_group_index","int32",232,4,SX_NONE),
 SX_FIELD("transition_count","int32",236,4,SX_COUNT_PROP),
 SX_FIELD("transitions_offset","int32",240,4,SX_OFFSET),
};
const sx_layout sxgm_studio_v10_header = {UINT32_C(0x60270064),"studio_v10_header",sxgm_studio_v10_header_fields,SX_COUNT(sxgm_studio_v10_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_studio_texture_fields[] = {
 SX_FIELD("name","char[64]",0,64,SX_STRING),
 SX_FIELD("flags","int32",64,4,SX_FLAGS),
 SX_FIELD("width","int32",68,4,SX_COUNT_PROP),
 SX_FIELD("height","int32",72,4,SX_COUNT_PROP),
 SX_FIELD("data_offset","int32",76,4,SX_OFFSET),
};
const sx_layout sxgm_studio_texture = {UINT32_C(0x60270065),"studio_texture",sxgm_studio_texture_fields,SX_COUNT(sxgm_studio_texture_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_studio_skinref_fields[] = {
 SX_FIELD("texture_index","int16",0,2,SX_ID),
};
const sx_layout sxgm_studio_skinref = {UINT32_C(0x60270066),"studio_skinref",sxgm_studio_skinref_fields,SX_COUNT(sxgm_studio_skinref_fields),SX_LE};
#define SXGM_LIMIT 20000U
static bool sxgm_studio(sx_context *c){uint8_t b[244];if(!sxgm_read(c,0,b,244)||!sxgm_add(c,&sxgm_studio_v10_header,0))return false;uint64_t n=sxgm32(b+180,false),p=sxgm32(b+184,false),refs=sxgm32(b+192,false),families=sxgm32(b+196,false),skins=sxgm32(b+200,false);if(!sxgm_table(c,&sxgm_studio_texture,p,n))return false;if(refs<=SXGM_LIMIT&&families<=SXGM_LIMIT)return sxgm_table(c,&sxgm_studio_skinref,skins,refs*families);return true;}
bool sx_valve_studio_mdl_build(sx_context*c)
{
 return sxgm_studio(c);
}
