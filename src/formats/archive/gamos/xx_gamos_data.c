/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GAMOS data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_gamos_header_fields[] = {
 SX_FIELD("signature","uint8[18]",0,18,SX_SIGNATURE),
 SX_FIELD("zero","uint8",18,1,SX_NONE),
 SX_FIELD("marker1","uint8",19,1,SX_NONE),
 SX_FIELD("reserved","uint16",20,2,SX_NONE),
 SX_FIELD("marker2","uint8",22,1,SX_NONE),
 SX_FIELD("member_count","uint16",23,2,SX_COUNT_PROP),
 SX_FIELD("unused","uint8[8]",25,8,SX_NONE),
};
const sx_layout sxat_gamos_header = {UINT32_C(0x6064000b),"gamos_header",sxat_gamos_header_fields,SX_COUNT(sxat_gamos_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_gamos_member_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("method","uint8",13,1,SX_NONE),
 SX_FIELD("payload_offset","int32",14,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint16",18,2,SX_SIZE),
 SX_FIELD("uncompressed_size","uint16",20,2,SX_SIZE),
};
const sx_layout sxat_gamos_member = {UINT32_C(0x6064000c),"gamos_member",sxat_gamos_member_fields,SX_COUNT(sxat_gamos_member_fields),SX_LE};
static bool sxat_gamos(sx_context*c){uint64_t n;return sxat_word(c,23,2,false,&n)&&sxat_add(c,&sxat_gamos_header,0)&&sxat_table(c,&sxat_gamos_member,33,22,n);}
bool sx_gamos_build(sx_context*c)
{
 return sxat_gamos(c);
}
