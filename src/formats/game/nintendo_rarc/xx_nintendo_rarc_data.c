/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo_rarc data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_rarc_header_le_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("file_size","uint32",4,4,SX_SIZE),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",16,4,SX_SIZE),
 SX_FIELD("mram_data_size","uint32",20,4,SX_SIZE),
 SX_FIELD("aram_data_size","uint32",24,4,SX_SIZE),
 SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
 SX_FIELD("node_count","uint32",32,4,SX_COUNT_PROP),
 SX_FIELD("nodes_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",40,4,SX_COUNT_PROP),
 SX_FIELD("entries_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("strings_size","uint32",48,4,SX_SIZE),
 SX_FIELD("strings_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("next_file_id","uint16",56,2,SX_ID),
 SX_FIELD("sync_file_ids","uint8",58,1,SX_FLAGS),
 SX_FIELD("reserved59","uint8[5]",59,5,SX_RESERVED),
};
const sx_layout sxgm_rarc_header_le = {UINT32_C(0x60270017),"rarc_header_le",sxgm_rarc_header_le_fields,SX_COUNT(sxgm_rarc_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_rarc_header_be_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("file_size","uint32",4,4,SX_SIZE),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",16,4,SX_SIZE),
 SX_FIELD("mram_data_size","uint32",20,4,SX_SIZE),
 SX_FIELD("aram_data_size","uint32",24,4,SX_SIZE),
 SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
 SX_FIELD("node_count","uint32",32,4,SX_COUNT_PROP),
 SX_FIELD("nodes_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",40,4,SX_COUNT_PROP),
 SX_FIELD("entries_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("strings_size","uint32",48,4,SX_SIZE),
 SX_FIELD("strings_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("next_file_id","uint16",56,2,SX_ID),
 SX_FIELD("sync_file_ids","uint8",58,1,SX_FLAGS),
 SX_FIELD("reserved59","uint8[5]",59,5,SX_RESERVED),
};
const sx_layout sxgm_rarc_header_be = {UINT32_C(0x60270018),"rarc_header_be",sxgm_rarc_header_be_fields,SX_COUNT(sxgm_rarc_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_rarc_node_le_fields[] = {
 SX_FIELD("type","char[4]",0,4,SX_ID),
 SX_FIELD("name_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("name_hash","uint16",8,2,SX_CHECKSUM),
 SX_FIELD("entry_count","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("first_entry_index","uint32",12,4,SX_ID),
};
const sx_layout sxgm_rarc_node_le = {UINT32_C(0x60270019),"rarc_node_le",sxgm_rarc_node_le_fields,SX_COUNT(sxgm_rarc_node_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_rarc_node_be_fields[] = {
 SX_FIELD("type","char[4]",0,4,SX_ID),
 SX_FIELD("name_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("name_hash","uint16",8,2,SX_CHECKSUM),
 SX_FIELD("entry_count","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("first_entry_index","uint32",12,4,SX_ID),
};
const sx_layout sxgm_rarc_node_be = {UINT32_C(0x6027001a),"rarc_node_be",sxgm_rarc_node_be_fields,SX_COUNT(sxgm_rarc_node_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_rarc_file_le_fields[] = {
 SX_FIELD("file_id","uint16",0,2,SX_ID),
 SX_FIELD("name_hash","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("name_offset","uint24",4,3,SX_OFFSET),
 SX_FIELD("attributes","uint8",7,1,SX_FLAGS),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",12,4,SX_SIZE),
 SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
};
const sx_layout sxgm_rarc_file_le = {UINT32_C(0x6027001b),"rarc_file_le",sxgm_rarc_file_le_fields,SX_COUNT(sxgm_rarc_file_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_rarc_directory_le_fields[] = {
 SX_FIELD("file_id","uint16",0,2,SX_ID),
 SX_FIELD("name_hash","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("name_offset","uint24",4,3,SX_OFFSET),
 SX_FIELD("attributes","uint8",7,1,SX_FLAGS),
 SX_FIELD("node_index","uint32",8,4,SX_ID),
 SX_FIELD("data_size","uint32",12,4,SX_SIZE),
 SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
};
const sx_layout sxgm_rarc_directory_le = {UINT32_C(0x6027001c),"rarc_directory_le",sxgm_rarc_directory_le_fields,SX_COUNT(sxgm_rarc_directory_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_rarc_file_be_fields[] = {
 SX_FIELD("file_id","uint16",0,2,SX_ID),
 SX_FIELD("name_hash","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("attributes","uint8",4,1,SX_FLAGS),
 SX_FIELD("name_offset","uint24",5,3,SX_OFFSET),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",12,4,SX_SIZE),
 SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
};
const sx_layout sxgm_rarc_file_be = {UINT32_C(0x6027001d),"rarc_file_be",sxgm_rarc_file_be_fields,SX_COUNT(sxgm_rarc_file_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_rarc_directory_be_fields[] = {
 SX_FIELD("file_id","uint16",0,2,SX_ID),
 SX_FIELD("name_hash","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("attributes","uint8",4,1,SX_FLAGS),
 SX_FIELD("name_offset","uint24",5,3,SX_OFFSET),
 SX_FIELD("node_index","uint32",8,4,SX_ID),
 SX_FIELD("data_size","uint32",12,4,SX_SIZE),
 SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
};
const sx_layout sxgm_rarc_directory_be = {UINT32_C(0x6027001e),"rarc_directory_be",sxgm_rarc_directory_be_fields,SX_COUNT(sxgm_rarc_directory_be_fields),SX_BE};
#define SXGM_LIMIT 20000U
static bool sxgm_rarc(sx_context *c){uint8_t b[64];if(!sxgm_read(c,0,b,64))return false;bool be=!xx_rt_memcmp(b,"RARC",4);if(!be&&xx_rt_memcmp(b,"CRAR",4))return false;if(!sxgm_add(c,be?&sxgm_rarc_header_be:&sxgm_rarc_header_le,0))return false;uint64_t n=sxgm32(b+32,be),p=(uint64_t)sxgm32(b+36,be)+32,k=sxgm32(b+40,be),q=(uint64_t)sxgm32(b+44,be)+32;if(!sxgm_table(c,be?&sxgm_rarc_node_be:&sxgm_rarc_node_le,p,n))return false;if(k>SXGM_LIMIT||!sxgm_span(c,q,k*20))return true;for(uint64_t i=0;i<k&&c->count<SXGM_LIMIT;i++){uint8_t e[20];if(!sxgm_read(c,q+i*20,e,20))break;bool dir=(sxgm32(e+4,be)>>24)&2;const sx_layout *l=dir?(be?&sxgm_rarc_directory_be:&sxgm_rarc_directory_le):(be?&sxgm_rarc_file_be:&sxgm_rarc_file_le);if(!sxgm_add(c,l,q+i*20))return false;}return true;}
bool sx_nintendo_rarc_build(sx_context*c)
{
 return sxgm_rarc(c);
}
