/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CP/M LU library (.LBR) data structures, moved out of the archivemore schema family. */
#include "../../xx_format_schema_archivemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxar_lbr_directory_entry_fields[] = {
    SX_FIELD("status","uint8",0,1,SX_ID),
    SX_FIELD("name","char[8]",1,8,SX_STRING),
    SX_FIELD("extension","char[3]",9,3,SX_STRING),
    SX_FIELD("first_sector","uint16",12,2,SX_NONE),
    SX_FIELD("sector_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("crc16","uint16",16,2,SX_CHECKSUM),
    SX_FIELD("created_date","uint16",18,2,SX_NONE),
    SX_FIELD("modified_date","uint16",20,2,SX_NONE),
    SX_FIELD("created_time","uint16",22,2,SX_NONE),
    SX_FIELD("modified_time","uint16",24,2,SX_NONE),
    SX_FIELD("pad_size","uint8",26,1,SX_SIZE),
    SX_FIELD("reserved","uint8[5]",27,5,SX_RESERVED),
};
const sx_layout sxar_lbr_directory_entry = {UINT32_C(0x601c0031),"lbr_directory_entry",sxar_lbr_directory_entry_fields,SX_COUNT(sxar_lbr_directory_entry_fields),SX_LE};
#define SXAR_LIMIT 20000U
static bool sxar_lbr(sx_context *c){uint8_t b[32];if(!sxar_read(c,0,b,32))return false;uint64_t n=(uint64_t)sxar16(b+14,false)*4;if(!n||n>SXAR_LIMIT||!sxar_span(c,0,n*32))return false;return sx_table(c,&sxar_lbr_directory_entry,0,32,n);}
bool sx_lbr_build(sx_context*c)
{
 return sxar_lbr(c);
}
