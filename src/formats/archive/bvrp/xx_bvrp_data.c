/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BVRP data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_bvrp_header_fields[] = {
 SX_FIELD("banner","char[76]",0,76,SX_SIGNATURE),
 SX_FIELD("terminator","uint8[4]",76,4,SX_SIGNATURE),
 SX_FIELD("signature","uint16",80,2,SX_SIGNATURE),
 SX_FIELD("writer_version","uint16",82,2,SX_NONE),
 SX_FIELD("opaque","uint8[8]",84,8,SX_NONE),
 SX_FIELD("first_member_offset","uint32",92,4,SX_OFFSET),
 SX_FIELD("member_count","uint16",96,2,SX_COUNT_PROP),
};
const sx_layout sxat_bvrp_header = {UINT32_C(0x60640024),"bvrp_header",sxat_bvrp_header_fields,SX_COUNT(sxat_bvrp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_bvrp_member_fields[] = {
 SX_FIELD("name","char[12]",0,12,SX_NONE),
 SX_FIELD("attributes","uint16",12,2,SX_FLAGS),
 SX_FIELD("dos_date","uint16",14,2,SX_NONE),
 SX_FIELD("dos_time","uint16",16,2,SX_NONE),
 SX_FIELD("method","uint8",18,1,SX_NONE),
 SX_FIELD("next_header_offset","uint32",19,4,SX_OFFSET),
 SX_FIELD("uncompressed_size","uint32",23,4,SX_SIZE),
 SX_FIELD("crc16","uint16",27,2,SX_CHECKSUM),
 SX_FIELD("name_tail_size","uint16",29,2,SX_SIZE),
 SX_FIELD("padding","uint8",31,1,SX_NONE),
};
const sx_layout sxat_bvrp_member = {UINT32_C(0x60640025),"bvrp_member",sxat_bvrp_member_fields,SX_COUNT(sxat_bvrp_member_fields),SX_LE};
static bool sxat_bvrp(sx_context*c){uint64_t p,n;if(!sxat_word(c,92,4,false,&p)||!sxat_word(c,96,2,false,&n)||!sxat_add(c,&sxat_bvrp_header,0))return false;for(uint64_t i=0;i<n;i++){uint64_t next;if(!sxat_word(c,p+19,4,false,&next)||!sxat_span(c,p,32)||next<p+32||next>(uint64_t)c->size||!sxat_add(c,&sxat_bvrp_member,p))return false;p=next;}return true;}
bool sx_bvrp_build(sx_context*c)
{
 return sxat_bvrp(c);
}
