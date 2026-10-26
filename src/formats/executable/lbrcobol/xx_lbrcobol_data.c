/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LBRCOBOL data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_lbrcobol_title_fields[] = {
 SX_FIELD("title","char[34]",0,34,SX_SIGNATURE),
 SX_FIELD("creation_stamp","char[21]",34,21,SX_NONE),
};
const sx_layout sxbx_lbrcobol_title = {UINT32_C(0x603000a2),"lbrcobol_title",sxbx_lbrcobol_title_fields,SX_COUNT(sxbx_lbrcobol_title_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lbrcobol_directory_header_fields[] = {
 SX_FIELD("block_size","uint16",0,2,SX_NONE),
 SX_FIELD("record_count","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxbx_lbrcobol_directory_header = {UINT32_C(0x603000a3),"lbrcobol_directory_header",sxbx_lbrcobol_directory_header_fields,SX_COUNT(sxbx_lbrcobol_directory_header_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_lbrcobol_header_constants_fields[] = {
 SX_FIELD("constant1","uint32",0,4,SX_NONE),
 SX_FIELD("constant2","uint32",4,4,SX_NONE),
};
const sx_layout sxbx_lbrcobol_header_constants = {UINT32_C(0x603000a4),"lbrcobol_header_constants",sxbx_lbrcobol_header_constants_fields,SX_COUNT(sxbx_lbrcobol_header_constants_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_lbrcobol_member_fields[] = {
 SX_FIELD("next_record_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("payload_block","uint32",4,4,SX_NONE),
 SX_FIELD("payload_size","uint32",8,4,SX_SIZE),
 SX_FIELD("dos_time","uint16",12,2,SX_NONE),
 SX_FIELD("dos_date","uint16",14,2,SX_NONE),
};
const sx_layout sxbx_lbrcobol_member = {UINT32_C(0x603000a5),"lbrcobol_member",sxbx_lbrcobol_member_fields,SX_COUNT(sxbx_lbrcobol_member_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_lbrcobol_member_tail_fields[] = {
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("name_size","uint8",2,1,SX_SIZE),
};
const sx_layout sxbx_lbrcobol_member_tail = {UINT32_C(0x603000a6),"lbrcobol_member_tail",sxbx_lbrcobol_member_tail_fields,SX_COUNT(sxbx_lbrcobol_member_tail_fields),SX_LE};
#define SXBX_LIMIT 20000U
static bool sxbx_lbr(sx_context*c){uint64_t n,p=256;if(!sxbx_add(c,&sxbx_lbrcobol_title,0)||!sxbx_add(c,&sxbx_lbrcobol_directory_header,144)||!sxbx_add(c,&sxbx_lbrcobol_header_constants,148)||!sxbx_word(c,146,2,true,&n))return false;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++){uint8_t b[19];if(!sxbx_read(c,p,b,19)||!sxbx_span(c,p+19,b[18])||!sxbx_free(c,p,19))break;if(!sxbx_add(c,&sxbx_lbrcobol_member,p)||!sxbx_add(c,&sxbx_lbrcobol_member_tail,p+16))return false;p=sxbx32(b,true);}return true;}
bool sx_lbrcobol_build(sx_context*c)
{
 return sxbx_lbr(c);
}
