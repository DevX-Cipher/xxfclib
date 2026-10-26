/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MLB_FT data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_mlbft_header_fields[] = {
 SX_FIELD("member_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("version","uint16",2,2,SX_NONE),
};
const sx_layout sxap_mlbft_header = {UINT32_C(0x60720028),"mlbft_header",sxap_mlbft_header_fields,SX_COUNT(sxap_mlbft_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_mlbft_member_fields[] = {
 SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("name","char[13]",8,13,SX_NONE),
};
const sx_layout sxap_mlbft_member = {UINT32_C(0x60720029),"mlbft_member",sxap_mlbft_member_fields,SX_COUNT(sxap_mlbft_member_fields),SX_LE};
static bool sxap_mlb(sx_context*c){uint64_t n;return sxap_word(c,0,2,false,&n)&&sxap_add(c,&sxap_mlbft_header,0)&&sxap_table(c,&sxap_mlbft_member,4,21,n);}
bool sx_mlb_ft_build(sx_context*c)
{
 return sxap_mlb(c);
}
