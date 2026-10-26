/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo bfres data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_bfres_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("byte_order","uint16",8,2,SX_ID),
 SX_FIELD("header_size","uint16",10,2,SX_SIZE),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
 SX_FIELD("alignment","uint32",16,4,SX_SIZE),
 SX_FIELD("name_relative","int32",20,4,SX_OFFSET),
 SX_FIELD("string_pool_size","uint32",24,4,SX_SIZE),
 SX_FIELD("string_pool_relative","int32",28,4,SX_OFFSET),
 SX_FIELD("model_dictionary_relative","int32",32,4,SX_OFFSET),
 SX_FIELD("texture_dictionary_relative","int32",36,4,SX_OFFSET),
 SX_FIELD("skeletal_animation_dictionary_relative","int32",40,4,SX_OFFSET),
 SX_FIELD("shader_parameter_animation_dictionary_relative","int32",44,4,SX_OFFSET),
 SX_FIELD("color_animation_dictionary_relative","int32",48,4,SX_OFFSET),
 SX_FIELD("texture_srt_animation_dictionary_relative","int32",52,4,SX_OFFSET),
 SX_FIELD("texture_pattern_animation_dictionary_relative","int32",56,4,SX_OFFSET),
 SX_FIELD("bone_visibility_animation_dictionary_relative","int32",60,4,SX_OFFSET),
 SX_FIELD("material_visibility_animation_dictionary_relative","int32",64,4,SX_OFFSET),
 SX_FIELD("shape_animation_dictionary_relative","int32",68,4,SX_OFFSET),
 SX_FIELD("scene_animation_dictionary_relative","int32",72,4,SX_OFFSET),
 SX_FIELD("external_file_dictionary_relative","int32",76,4,SX_OFFSET),
 SX_FIELD("model_count","uint16",80,2,SX_COUNT_PROP),
 SX_FIELD("texture_count","uint16",82,2,SX_COUNT_PROP),
 SX_FIELD("skeletal_animation_count","uint16",84,2,SX_COUNT_PROP),
 SX_FIELD("shader_parameter_animation_count","uint16",86,2,SX_COUNT_PROP),
 SX_FIELD("color_animation_count","uint16",88,2,SX_COUNT_PROP),
 SX_FIELD("texture_srt_animation_count","uint16",90,2,SX_COUNT_PROP),
 SX_FIELD("texture_pattern_animation_count","uint16",92,2,SX_COUNT_PROP),
 SX_FIELD("bone_visibility_animation_count","uint16",94,2,SX_COUNT_PROP),
 SX_FIELD("material_visibility_animation_count","uint16",96,2,SX_COUNT_PROP),
 SX_FIELD("shape_animation_count","uint16",98,2,SX_COUNT_PROP),
 SX_FIELD("scene_animation_count","uint16",100,2,SX_COUNT_PROP),
 SX_FIELD("external_file_count","uint16",102,2,SX_COUNT_PROP),
 SX_FIELD("user_pointer","uint32",104,4,SX_POINTER),
};
const sx_layout sxmx_bfres_header={UINT32_C(0x602E0049),"bfres_header",sxmx_bfres_header_fields,SX_COUNT(sxmx_bfres_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_bfres_external_fields[]={
 SX_FIELD("data_relative","int32",0,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxmx_bfres_external={UINT32_C(0x602E004C),"bfres_external",sxmx_bfres_external_fields,SX_COUNT(sxmx_bfres_external_fields),SX_BE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_bfres(sxmx_view*v)
{size_t at;if(!SM_ROW(bfres_header,0,v->n)||!sxmx_relative(v,76,true,&at)||!SM_ROW(bfres_dictionary,at,v->n))return false;uint32_t n=sxmx_u32(v->p+at+4,true);if(n>1024||!sxmx_table(v,&sxmx_bfres_node,at+8,(uint64_t)n+1,v->n))return false;for(uint32_t i=1;i<=n;i++){size_t target;if(!sxmx_relative(v,at+8+(size_t)i*16+12,true,&target)||!SM_ROW(bfres_external,target,v->n))return false;}return true;}
bool sx_nintendo_bfres_build(sxmx_view*v)
{
 return sxmx_bfres(v);
}
#undef SM_ROW
