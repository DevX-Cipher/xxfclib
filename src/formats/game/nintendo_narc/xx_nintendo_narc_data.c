/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo_narc data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_narc_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order_mark","uint16",4,2,SX_ID),
 SX_FIELD("version","uint16",6,2,SX_ID),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("header_size","uint16",12,2,SX_SIZE),
 SX_FIELD("block_count","uint16",14,2,SX_COUNT_PROP),
};
const sx_layout sxgm_narc_header = {UINT32_C(0x6027001f),"narc_header",sxgm_narc_header_fields,SX_COUNT(sxgm_narc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_narc_fat_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("block_size","uint32",4,4,SX_SIZE),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxgm_narc_fat = {UINT32_C(0x60270020),"narc_fat",sxgm_narc_fat_fields,SX_COUNT(sxgm_narc_fat_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_narc_entry_fields[] = {
 SX_FIELD("start_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("end_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxgm_narc_entry = {UINT32_C(0x60270021),"narc_entry",sxgm_narc_entry_fields,SX_COUNT(sxgm_narc_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_narc_block_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_ID),
 SX_FIELD("block_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxgm_narc_block = {UINT32_C(0x60270022),"narc_block",sxgm_narc_block_fields,SX_COUNT(sxgm_narc_block_fields),SX_LE};
static bool sxgm_narc(sx_context *c){uint8_t b[12];if(!sxgm_add(c,&sxgm_narc_header,0)||!sxgm_read(c,16,b,12)||!sxgm_add(c,&sxgm_narc_fat,16))return false;uint64_t fat=sxgm32(b+4,false),n=sxgm32(b+8,false);if(fat<12||!sxgm_span(c,16,fat)||!sxgm_table(c,&sxgm_narc_entry,28,n))return true;uint64_t p=16+fat;if(!sxgm_read(c,p,b,8))return true;uint64_t z=sxgm32(b+4,false);if(z<8||!sxgm_span(c,p,z))return true;if(!sxgm_add(c,&sxgm_narc_block,p))return false;p+=z;if(sxgm_span(c,p,8)&&!sxgm_add(c,&sxgm_narc_block,p))return false;return true;}
bool sx_nintendo_narc_build(sx_context*c)
{
 return sxgm_narc(c);
}
