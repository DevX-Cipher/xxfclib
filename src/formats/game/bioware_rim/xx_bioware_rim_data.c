/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * bioware_rim data structures, moved out of the gamemeta schema family. */
#include "../../xx_format_schema_gamemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgm_rim_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","char[4]",4,4,SX_ID),
 SX_FIELD("unknown8","uint32",8,4,SX_NONE),
 SX_FIELD("entry_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("table_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("reserved","uint8[100]",20,100,SX_RESERVED),
};
const sx_layout sxgm_rim_header = {UINT32_C(0x60270039),"rim_header",sxgm_rim_header_fields,SX_COUNT(sxgm_rim_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_rim_entry_fields[] = {
 SX_FIELD("resref","char[16]",0,16,SX_STRING),
 SX_FIELD("resource_type","uint32",16,4,SX_ID),
 SX_FIELD("resource_id","uint32",20,4,SX_ID),
 SX_FIELD("data_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",28,4,SX_SIZE),
};
const sx_layout sxgm_rim_entry = {UINT32_C(0x6027003a),"rim_entry",sxgm_rim_entry_fields,SX_COUNT(sxgm_rim_entry_fields),SX_LE};
bool sx_bioware_rim_build(sx_context*c)
{
 return sxgm_fixed(c,&sxgm_rim_header,&sxgm_rim_entry,0,120,12,4,16,4,false);
}
