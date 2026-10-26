/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * bethesda_ba2 data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_game_name_length16_fields[] = {
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxgm_game_name_length16 = {UINT32_C(0x60270040),"game_name_length16",sxgm_game_name_length16_fields,SX_COUNT(sxgm_game_name_length16_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_ba2_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("archive_type","char[4]",8,4,SX_ID),
 SX_FIELD("entry_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("names_offset","uint64",16,8,SX_OFFSET),
};
const sx_layout sxgm_ba2_header = {UINT32_C(0x60270041),"ba2_header",sxgm_ba2_header_fields,SX_COUNT(sxgm_ba2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_ba2_v2_extension_fields[] = {
 SX_FIELD("unknown","uint64",0,8,SX_NONE),
};
const sx_layout sxgm_ba2_v2_extension = {UINT32_C(0x60270042),"ba2_v2_extension",sxgm_ba2_v2_extension_fields,SX_COUNT(sxgm_ba2_v2_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_ba2_v3_compression_fields[] = {
 SX_FIELD("compression","uint32",0,4,SX_ID),
};
const sx_layout sxgm_ba2_v3_compression = {UINT32_C(0x60270043),"ba2_v3_compression",sxgm_ba2_v3_compression_fields,SX_COUNT(sxgm_ba2_v3_compression_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_ba2_general_entry_fields[] = {
 SX_FIELD("name_hash","uint32",0,4,SX_CHECKSUM),
 SX_FIELD("extension","char[4]",4,4,SX_STRING),
 SX_FIELD("directory_hash","uint32",8,4,SX_CHECKSUM),
 SX_FIELD("flags","uint32",12,4,SX_FLAGS),
 SX_FIELD("data_offset","uint64",16,8,SX_OFFSET),
 SX_FIELD("packed_size","uint32",24,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",28,4,SX_SIZE),
 SX_FIELD("alignment","uint32",32,4,SX_SIGNATURE),
};
const sx_layout sxgm_ba2_general_entry = {UINT32_C(0x60270044),"ba2_general_entry",sxgm_ba2_general_entry_fields,SX_COUNT(sxgm_ba2_general_entry_fields),SX_LE};
#define SXGM_LIMIT 20000U
static bool sxgm_ba2(sx_context *c){uint8_t b[36];if(!sxgm_read(c,0,b,24)||!sxgm_add(c,&sxgm_ba2_header,0))return false;unsigned v=sxgm32(b+4,false);uint64_t n=sxgm32(b+12,false),p=sxgm_uint(b+16,8,false);unsigned h=v==2?32:v==3?36:24;if(v==2||v==3){if(!sxgm_span(c,24,h-24))return true;if(!sxgm_add(c,&sxgm_ba2_v2_extension,24))return false;if(v==3&&!sxgm_add(c,&sxgm_ba2_v3_compression,32))return false;}if(xx_rt_memcmp(b+8,"GNRL",4))return true;if(!sxgm_table(c,&sxgm_ba2_general_entry,h,n))return false;for(uint64_t i=0;i<n&&i<SXGM_LIMIT&&c->count<SXGM_LIMIT;i++){uint64_t z;if(!sxgm_word(c,p,2,false,&z)||!sxgm_span(c,p+2,z))break;if(!sxgm_add(c,&sxgm_game_name_length16,p))return false;p+=2+z;}return true;}
bool sx_bethesda_ba2_build(sx_context*c)
{
 return sxgm_ba2(c);
}
