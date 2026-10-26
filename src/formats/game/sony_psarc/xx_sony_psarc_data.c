/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sony_psarc data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_psarc_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("compression","char[4]",8,4,SX_ID),
 SX_FIELD("toc_size","uint32",12,4,SX_SIZE),
 SX_FIELD("entry_size","uint32",16,4,SX_SIZE),
 SX_FIELD("entry_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("block_size","uint32",24,4,SX_SIZE),
 SX_FIELD("flags","uint32",28,4,SX_FLAGS),
};
const sx_layout sxgm_psarc_header = {UINT32_C(0x6027002e),"psarc_header",sxgm_psarc_header_fields,SX_COUNT(sxgm_psarc_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_psarc_entry_fields[] = {
 SX_FIELD("name_md5","uint8[16]",0,16,SX_CHECKSUM),
 SX_FIELD("first_block_index","uint32",16,4,SX_ID),
 SX_FIELD("unpacked_size","uint40",20,5,SX_SIZE),
 SX_FIELD("data_offset","uint40",25,5,SX_OFFSET),
};
const sx_layout sxgm_psarc_entry = {UINT32_C(0x6027002f),"psarc_entry",sxgm_psarc_entry_fields,SX_COUNT(sxgm_psarc_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_psarc_block_length_fields[] = {
 SX_FIELD("stored_length","uint16",0,2,SX_NONE),
};
const sx_layout sxgm_psarc_block_length = {UINT32_C(0x60270030),"psarc_block_length",sxgm_psarc_block_length_fields,SX_COUNT(sxgm_psarc_block_length_fields),SX_BE};
#define SXGM_LIMIT 20000U
static bool sxgm_psarc(sx_context *c){uint8_t b[32];if(!sxgm_read(c,0,b,32)||!sxgm_add(c,&sxgm_psarc_header,0))return false;uint64_t toc=sxgm32(b+12,true),stride=sxgm32(b+16,true),n=sxgm32(b+20,true);if(stride!=30||n>SXGM_LIMIT||toc<32+n*30||!sxgm_span(c,0,toc))return true;return sxgm_table(c,&sxgm_psarc_entry,32,n)&&sxgm_table(c,&sxgm_psarc_block_length,32+n*30,(toc-32-n*30)/2);}
bool sx_sony_psarc_build(sx_context*c)
{
 return sxgm_psarc(c);
}
