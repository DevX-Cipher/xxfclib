/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PACKIT data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_dos_packit_header_fields[] = {
 SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
};
const sx_layout sxal_dos_packit_header = {UINT32_C(0x6020000a),"dos_packit_header",sxal_dos_packit_header_fields,SX_COUNT(sxal_dos_packit_header_fields),SX_LE};
static const xx_data_struct_field_desc sxal_dos_packit_member_fields[] = {
 SX_FIELD("tag","uint16",0,2,SX_ID),
 SX_FIELD("data_size","int32",2,4,SX_SIZE),
 SX_FIELD("repeated_data_size","int32",6,4,SX_SIZE),
 SX_FIELD("date","uint16",10,2,SX_NONE),
 SX_FIELD("time","uint16",12,2,SX_NONE),
 SX_FIELD("crc32","uint32",14,4,SX_CHECKSUM),
 SX_FIELD("name_size","uint8",18,1,SX_SIZE),
};
const sx_layout sxal_dos_packit_member = {UINT32_C(0x6020000b),"dos_packit_member",sxal_dos_packit_member_fields,SX_COUNT(sxal_dos_packit_member_fields),SX_LE};
static const xx_data_struct_field_desc sxal_dos_packit_end_fields[] = {
 SX_FIELD("tag","uint16",0,2,SX_SIGNATURE),
};
const sx_layout sxal_dos_packit_end = {UINT32_C(0x6020000c),"dos_packit_end",sxal_dos_packit_end_fields,SX_COUNT(sxal_dos_packit_end_fields),SX_LE};
static bool sxal_packit(sx_context *c){uint8_t b[19];if(!sxal_read(c,0,b,16)||!sxal_add(c,&sxal_dos_packit_header,0))return false;uint64_t p=16;for(unsigned i=0;i<SXAL_LIMIT;i++){if(!sxal_read(c,p,b,2))break;unsigned tag=sxal16(b,false);if(tag==65535)return sxal_add(c,&sxal_dos_packit_end,p);if(tag!=255||!sxal_read(c,p,b,19))break;uint64_t n=sxal32(b+2,false),head=20U+b[18];if(n>INT32_MAX||!sxal_span(c,p,head)||!sxal_add(c,&sxal_dos_packit_member,p))break;if(!sxal_span(c,p+head,n))break;p+=head+n;}return !c->failed;}
bool sx_packit_build(sx_context*c)
{
 return sxal_packit(c);
}
