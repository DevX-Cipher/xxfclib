/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * KA data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_ka_header_fields[] = {
 SX_FIELD("signature","char[11]",0,11,SX_SIGNATURE),
 SX_FIELD("reserved","uint8[9]",11,9,SX_NONE),
 SX_FIELD("member_count","uint16",20,2,SX_COUNT_PROP),
};
const sx_layout sxaf_ka_header = {UINT32_C(0x603c001c),"ka_header",sxaf_ka_header_fields,SX_COUNT(sxaf_ka_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_ka_entry_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("payload_offset","uint32",13,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",17,4,SX_SIZE),
};
const sx_layout sxaf_ka_entry = {UINT32_C(0x603c001d),"ka_entry",sxaf_ka_entry_fields,SX_COUNT(sxaf_ka_entry_fields),SX_LE};
bool sx_ka_build(sx_context*c)
{
 return sxaf_table(c,&sxaf_ka_header,&sxaf_ka_entry,20,2,22,21);
}
