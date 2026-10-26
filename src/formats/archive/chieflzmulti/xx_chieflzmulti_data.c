/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ChiefLZ "Multiple" archives data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_chieflz_header_fields[] = {
 SX_FIELD("signature","uint8[13]",0,13,SX_SIGNATURE),
 SX_FIELD("unknown13","uint8[6]",13,6,SX_NONE),
 SX_FIELD("unused19","uint32",19,4,SX_NONE),
 SX_FIELD("entry_count","uint32",23,4,SX_COUNT_PROP),
 SX_FIELD("unused27","uint32",27,4,SX_NONE),
 SX_FIELD("unused31","uint32",31,4,SX_NONE),
 SX_FIELD("names_size","uint32",35,4,SX_SIZE),
 SX_FIELD("unknown39","uint8[4]",39,4,SX_NONE),
};
const sx_layout sxag_chieflz_header = {UINT32_C(0x6025001b),"chieflz_header",sxag_chieflz_header_fields,SX_COUNT(sxag_chieflz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_chieflz_entry_fields[] = {
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("directory_parent","uint16",1,2,SX_ID),
 SX_FIELD("file_parent","uint16",3,2,SX_ID),
 SX_FIELD("unknown5","uint8[10]",5,10,SX_NONE),
 SX_FIELD("packed_size","uint32",15,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",19,4,SX_SIZE),
 SX_FIELD("time","uint16",23,2,SX_NONE),
 SX_FIELD("date","uint16",25,2,SX_NONE),
 SX_FIELD("attributes","uint32",27,4,SX_FLAGS),
 SX_FIELD("complemented_crc32","uint32",31,4,SX_CHECKSUM),
 SX_FIELD("name_size","uint8",35,1,SX_SIZE),
 SX_FIELD("unknown36","uint8[4]",36,4,SX_NONE),
 SX_FIELD("method","uint8",40,1,SX_ID),
};
const sx_layout sxag_chieflz_entry = {UINT32_C(0x6025001c),"chieflz_entry",sxag_chieflz_entry_fields,SX_COUNT(sxag_chieflz_entry_fields),SX_LE};
#define SXAG_LIMIT 20000U
static bool sxag_chief(sx_context *c){uint8_t b[43];if(!sxag_read(c,0,b,43)||!sxag_add(c,&sxag_chieflz_header,0))return false;uint64_t n=sxag32(b+23,false);if(!n||n>SXAG_LIMIT||!sxag_span(c,126,n*41))return true;return sxag_table(c,&sxag_chieflz_entry,126,n);}
bool sx_chieflzmulti_build(sx_context*c)
{
 return sxag_chief(c);
}
