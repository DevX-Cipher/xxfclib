/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * bioware_biff data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_biff_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","char[4]",4,4,SX_ID),
 SX_FIELD("variable_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("fixed_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("table_offset","uint32",16,4,SX_OFFSET),
};
const sx_layout sxgm_biff_header = {UINT32_C(0x60270031),"biff_header",sxgm_biff_header_fields,SX_COUNT(sxgm_biff_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_biff_entry_v1_fields[] = {
 SX_FIELD("resource_id","uint32",0,4,SX_ID),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
 SX_FIELD("resource_type","uint32",12,4,SX_ID),
};
const sx_layout sxgm_biff_entry_v1 = {UINT32_C(0x60270032),"biff_entry_v1",sxgm_biff_entry_v1_fields,SX_COUNT(sxgm_biff_entry_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_biff_entry_v2_fields[] = {
 SX_FIELD("resource_id","uint64",0,8,SX_ID),
 SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",12,4,SX_SIZE),
 SX_FIELD("resource_type","uint32",16,4,SX_ID),
};
const sx_layout sxgm_biff_entry_v2 = {UINT32_C(0x60270033),"biff_entry_v2",sxgm_biff_entry_v2_fields,SX_COUNT(sxgm_biff_entry_v2_fields),SX_LE};
static bool sxgm_biff(sx_context *c){uint8_t b[20];if(!sxgm_read(c,0,b,20)||!sxgm_add(c,&sxgm_biff_header,0))return false;return sxgm_table(c,b[7]=='1'?&sxgm_biff_entry_v2:&sxgm_biff_entry_v1,sxgm32(b+16,false),sxgm32(b+8,false));}
bool sx_bioware_biff_build(sx_context*c)
{
 return sxgm_biff(c);
}
