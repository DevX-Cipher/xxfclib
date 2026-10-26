/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PEBBLE data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_pebble_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("structure_major","uint8",8,1,SX_ID),
 SX_FIELD("structure_minor","uint8",9,1,SX_ID),
 SX_FIELD("sdk_major","uint8",10,1,SX_ID),
 SX_FIELD("sdk_minor","uint8",11,1,SX_ID),
 SX_FIELD("application_major","uint8",12,1,SX_ID),
 SX_FIELD("application_minor","uint8",13,1,SX_ID),
 SX_FIELD("image_size","uint16",14,2,SX_SIZE),
 SX_FIELD("entry_point","uint32",16,4,SX_OFFSET),
 SX_FIELD("image_crc32","uint32",20,4,SX_CHECKSUM),
 SX_FIELD("application_name","char[32]",24,32,SX_STRING),
 SX_FIELD("company_name","char[32]",56,32,SX_STRING),
 SX_FIELD("icon_resource_id","uint32",88,4,SX_ID),
 SX_FIELD("symbol_table_address","uint32",92,4,SX_ADDRESS),
 SX_FIELD("flags","uint32",96,4,SX_FLAGS),
 SX_FIELD("relocation_count","uint32",100,4,SX_COUNT_PROP),
 SX_FIELD("uuid","uint8[16]",104,16,SX_ID),
 SX_FIELD("header_crc32","uint32",120,4,SX_CHECKSUM),
};
const sx_layout sxexm_pebble_header = {UINT32_C(0x602b0018),"pebble_header",sxexm_pebble_header_fields,SX_COUNT(sxexm_pebble_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexm_pebble_relocation_fields[] = {
 SX_FIELD("relocation_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxexm_pebble_relocation = {UINT32_C(0x602b0019),"pebble_relocation",sxexm_pebble_relocation_fields,SX_COUNT(sxexm_pebble_relocation_fields),SX_LE};
bool sx_pebble_build(sx_context*c)
{
bool ok=false;uint64_t p,n;
ok=sxexm_add(c,&sxexm_pebble_header,0)&&sxexm_word(c,14,2,false,&p)&&sxexm_word(c,100,4,false,&n)&&sxexm_table(c,&sxexm_pebble_relocation,p,n);
return ok&&sxexm_finish(c);
}
