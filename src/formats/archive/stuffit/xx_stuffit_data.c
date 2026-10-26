/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * StuffIt (SIT!) archives data structures, moved out of the archivemore schema family. */
#include "../../xx_format_schema_archivemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxar_stuffit_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("top_level_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("archive_size","uint32",6,4,SX_SIZE),
    SX_FIELD("signature","char[4]",10,4,SX_SIGNATURE),
    SX_FIELD("version","uint8",14,1,SX_ID),
    SX_FIELD("reserved","uint8[7]",15,7,SX_RESERVED),
};
const sx_layout sxar_stuffit_header = {UINT32_C(0x601c001a),"stuffit_header",sxar_stuffit_header_fields,SX_COUNT(sxar_stuffit_header_fields),SX_BE};
static const xx_data_struct_field_desc sxar_stuffit_member_fields[] = {
    SX_FIELD("resource_method","uint8",0,1,SX_ID),
    SX_FIELD("data_method","uint8",1,1,SX_ID),
    SX_FIELD("name_size","uint8",2,1,SX_SIZE),
    SX_FIELD("name","char[63]",3,63,SX_STRING),
    SX_FIELD("file_type","char[4]",66,4,SX_ID),
    SX_FIELD("creator","char[4]",70,4,SX_ID),
    SX_FIELD("finder_flags","uint16",74,2,SX_FLAGS),
    SX_FIELD("created","uint32",76,4,SX_NONE),
    SX_FIELD("modified","uint32",80,4,SX_NONE),
    SX_FIELD("resource_unpacked_size","uint32",84,4,SX_SIZE),
    SX_FIELD("data_unpacked_size","uint32",88,4,SX_SIZE),
    SX_FIELD("resource_packed_size","uint32",92,4,SX_SIZE),
    SX_FIELD("data_packed_size","uint32",96,4,SX_SIZE),
    SX_FIELD("resource_crc16","uint16",100,2,SX_CHECKSUM),
    SX_FIELD("data_crc16","uint16",102,2,SX_CHECKSUM),
    SX_FIELD("reserved","uint8[6]",104,6,SX_RESERVED),
    SX_FIELD("header_crc16","uint16",110,2,SX_CHECKSUM),
};
const sx_layout sxar_stuffit_member = {UINT32_C(0x601c001b),"stuffit_member",sxar_stuffit_member_fields,SX_COUNT(sxar_stuffit_member_fields),SX_BE};
#define SXAR_LIMIT 20000U
static bool sxar_stuffit(sx_context *c){uint8_t b[112];if(!sxar_read(c,0,b,22)||!sxar_add(c,&sxar_stuffit_header,0))return false;uint64_t p=22;for(unsigned i=0;i<SXAR_LIMIT&&p<(uint64_t)c->size;i++){if(!sxar_read(c,p,b,112))break;if(!sxar_add(c,&sxar_stuffit_member,p))return false;uint8_t rm=(uint8_t)(b[0]&~0x90U),dm=(uint8_t)(b[1]&~0x90U);uint64_t n=(rm==32||rm==33||dm==32||dm==33)?0:(uint64_t)sxar32(b+92,true)+sxar32(b+96,true);if(!sxar_span(c,p+112,n))break;p+=112+n;}return true;}
bool sx_stuffit_build(sx_context*c)
{
 return sxar_stuffit(c);
}
