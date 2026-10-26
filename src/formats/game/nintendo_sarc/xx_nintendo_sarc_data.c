/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo_sarc data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_sarc_header_le_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("byte_order_mark","uint16",6,2,SX_ID),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("version","uint16",16,2,SX_ID),
 SX_FIELD("reserved","uint16",18,2,SX_RESERVED),
};
const sx_layout sxgm_sarc_header_le = {UINT32_C(0x60270023),"sarc_header_le",sxgm_sarc_header_le_fields,SX_COUNT(sxgm_sarc_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_sarc_header_be_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("byte_order_mark","uint16",6,2,SX_ID),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("version","uint16",16,2,SX_ID),
 SX_FIELD("reserved","uint16",18,2,SX_RESERVED),
};
const sx_layout sxgm_sarc_header_be = {UINT32_C(0x60270024),"sarc_header_be",sxgm_sarc_header_be_fields,SX_COUNT(sxgm_sarc_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_sarc_fat_le_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("entry_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("hash_multiplier","uint32",8,4,SX_NONE),
};
const sx_layout sxgm_sarc_fat_le = {UINT32_C(0x60270025),"sarc_fat_le",sxgm_sarc_fat_le_fields,SX_COUNT(sxgm_sarc_fat_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_sarc_fat_be_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("entry_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("hash_multiplier","uint32",8,4,SX_NONE),
};
const sx_layout sxgm_sarc_fat_be = {UINT32_C(0x60270026),"sarc_fat_be",sxgm_sarc_fat_be_fields,SX_COUNT(sxgm_sarc_fat_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_sarc_entry_le_fields[] = {
 SX_FIELD("name_hash","uint32",0,4,SX_CHECKSUM),
 SX_FIELD("name_attributes","uint32",4,4,SX_FLAGS),
 SX_FIELD("start_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("end_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sxgm_sarc_entry_le = {UINT32_C(0x60270027),"sarc_entry_le",sxgm_sarc_entry_le_fields,SX_COUNT(sxgm_sarc_entry_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_sarc_entry_be_fields[] = {
 SX_FIELD("name_hash","uint32",0,4,SX_CHECKSUM),
 SX_FIELD("name_attributes","uint32",4,4,SX_FLAGS),
 SX_FIELD("start_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("end_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sxgm_sarc_entry_be = {UINT32_C(0x60270028),"sarc_entry_be",sxgm_sarc_entry_be_fields,SX_COUNT(sxgm_sarc_entry_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_sarc_names_le_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
};
const sx_layout sxgm_sarc_names_le = {UINT32_C(0x60270029),"sarc_names_le",sxgm_sarc_names_le_fields,SX_COUNT(sxgm_sarc_names_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_sarc_names_be_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
};
const sx_layout sxgm_sarc_names_be = {UINT32_C(0x6027002a),"sarc_names_be",sxgm_sarc_names_be_fields,SX_COUNT(sxgm_sarc_names_be_fields),SX_BE};
static bool sxgm_sarc(sx_context *c){uint8_t b[32];if(!sxgm_read(c,0,b,32))return false;bool be=b[6]==0xfe&&b[7]==0xff;uint64_t n=sxgm16(b+26,be);return sxgm_add(c,be?&sxgm_sarc_header_be:&sxgm_sarc_header_le,0)&&sxgm_add(c,be?&sxgm_sarc_fat_be:&sxgm_sarc_fat_le,20)&&sxgm_table(c,be?&sxgm_sarc_entry_be:&sxgm_sarc_entry_le,32,n)&&(sxgm_span(c,32+n*16,8)?sxgm_add(c,be?&sxgm_sarc_names_be:&sxgm_sarc_names_le,32+n*16):true);}
bool sx_nintendo_sarc_build(sx_context*c)
{
 return sxgm_sarc(c);
}
