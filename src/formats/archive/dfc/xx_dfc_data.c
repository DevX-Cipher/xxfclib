/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DFC data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_dfc_header_fields[] = {
 SX_FIELD("member_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("version","uint16",2,2,SX_NONE),
};
const sx_layout sxaf_dfc_header = {UINT32_C(0x603c001a),"dfc_header",sxaf_dfc_header_fields,SX_COUNT(sxaf_dfc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_dfc_entry_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_NONE),
 SX_FIELD("payload_offset","uint32",13,4,SX_OFFSET),
 SX_FIELD("uncompressed_size","uint32",17,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",21,4,SX_SIZE),
 SX_FIELD("complemented_crc32","uint32",25,4,SX_CHECKSUM),
 SX_FIELD("opaque_word","uint16",29,2,SX_NONE),
 SX_FIELD("method","uint8",31,1,SX_NONE),
 SX_FIELD("opaque_tail","uint8[3]",32,3,SX_NONE),
};
const sx_layout sxaf_dfc_entry = {UINT32_C(0x603c001b),"dfc_entry",sxaf_dfc_entry_fields,SX_COUNT(sxaf_dfc_entry_fields),SX_LE};
bool sx_dfc_build(sx_context*c)
{
 return sxaf_table(c,&sxaf_dfc_header,&sxaf_dfc_entry,0,2,4,35);
}
