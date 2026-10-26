/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MCC data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_mcc_member_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("method","uint8",3,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("xor_key","uint8",12,1,SX_NONE),
 SX_FIELD("attributes","uint8",13,1,SX_FLAGS),
 SX_FIELD("reserved","uint8",14,1,SX_NONE),
 SX_FIELD("dos_datetime","uint32",15,4,SX_NONE),
 SX_FIELD("crc16","uint16",19,2,SX_CHECKSUM),
 SX_FIELD("name_size","uint8",21,1,SX_SIZE),
 SX_FIELD("name","char[12]",22,12,SX_NONE),
};
const sx_layout sxat_mcc_member = {UINT32_C(0x6064001f),"mcc_member",sxat_mcc_member_fields,SX_COUNT(sxat_mcc_member_fields),SX_LE};
static bool sxat_mcc(sx_context*c){uint64_t p=0;while(sxat_span(c,p,34)){uint8_t h[34];if(!sxat_read(c,p,h,34)||xx_rt_memcmp(h,"MCC",3))return true;uint64_t z=sxat_uint(h+8,4,false);if(!sxat_add(c,&sxat_mcc_member,p))return false;p+=34;if(!sxat_span(c,p,z))return true;p+=z;}return true;}
bool sx_mcc_build(sx_context*c)
{
 return sxat_mcc(c);
}
