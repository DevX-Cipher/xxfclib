/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Fox SQZ compressed archive data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_fox_sqz_header_fields[] = {
 SX_FIELD("signature","char[24]",0,24,SX_SIGNATURE),
 SX_FIELD("base_key_size","uint8",24,1,SX_SIZE),
 SX_FIELD("encoded_key","uint8[4]",25,4,SX_NONE),
 SX_FIELD("opaque0","uint8[3]",29,3,SX_NONE),
 SX_FIELD("method","uint16",32,2,SX_NONE),
 SX_FIELD("opaque1","uint8[2]",34,2,SX_NONE),
 SX_FIELD("extra_key_size","uint16",36,2,SX_SIZE),
 SX_FIELD("opaque_tail","uint8[8]",38,8,SX_NONE),
};
const sx_layout sxas_fox_sqz_header = {UINT32_C(0x6043000e),"fox_sqz_header",sxas_fox_sqz_header_fields,SX_COUNT(sxas_fox_sqz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_fox_sqz_member_fields[] = {
 SX_FIELD("tag","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("opaque0","uint8",2,1,SX_NONE),
 SX_FIELD("compressed_size","uint32",3,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("checksum","uint16",11,2,SX_CHECKSUM),
 SX_FIELD("opaque1","uint8[8]",13,8,SX_NONE),
 SX_FIELD("name_size","uint16",21,2,SX_SIZE),
};
const sx_layout sxas_fox_sqz_member = {UINT32_C(0x6043000f),"fox_sqz_member",sxas_fox_sqz_member_fields,SX_COUNT(sxas_fox_sqz_member_fields),SX_LE};
static const xx_data_struct_field_desc sxas_fox_sqz_end_fields[] = {
 SX_FIELD("tag","uint16",0,2,SX_SIGNATURE),
};
const sx_layout sxas_fox_sqz_end = {UINT32_C(0x60430010),"fox_sqz_end",sxas_fox_sqz_end_fields,SX_COUNT(sxas_fox_sqz_end_fields),SX_LE};
static bool sxas_fox(sx_context*c){uint8_t b[46];if(!sxas_read(c,0,b,46)||!sxas_add(c,&sxas_fox_sqz_header,0))return false;if(b[24])return true;uint64_t p=46;while(sxas_span(c,p,23)){if(!sxas_read(c,p,b,23))return false;uint64_t tag=sxas_uint(b,2,false);if(tag==0xfe)return sxas_add(c,&sxas_fox_sqz_end,p);if(tag!=0xeb)return false;uint64_t packed=sxas_uint(b+3,4,false),names=sxas_uint(b+21,2,false);if(!sxas_span(c,p+23,names)||!sxas_span(c,p+23+names,packed)||!sxas_add(c,&sxas_fox_sqz_member,p))return false;p+=23+names+packed;}return false;}
bool sx_fox_sqz_build(sx_context*c)
{
 return sxas_fox(c);
}
