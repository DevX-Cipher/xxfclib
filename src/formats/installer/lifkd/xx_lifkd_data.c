/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LIFKD data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_lifkd_member_fields[] = {
 SX_FIELD("dos_datetime","ascii_hex[8]",0,8,SX_NONE),
 SX_FIELD("compressed_size","ascii_hex[8]",8,8,SX_SIZE),
 SX_FIELD("uncompressed_size","ascii_hex[8]",16,8,SX_SIZE),
 SX_FIELD("packed_crc16","ascii_hex[4]",24,4,SX_CHECKSUM),
 SX_FIELD("plain_crc16","ascii_hex[4]",28,4,SX_CHECKSUM),
 SX_FIELD("method","ascii_hex[2]",32,2,SX_NONE),
 SX_FIELD("name","char[20]",34,20,SX_NONE),
};
const sx_layout sxat_lifkd_member = {UINT32_C(0x6064001d),"lifkd_member",sxat_lifkd_member_fields,SX_COUNT(sxat_lifkd_member_fields),SX_LE};
static bool sxat_lifkd(sx_context*c){uint64_t p=0;while(sxat_span(c,p,54)){uint64_t z,v;if(!sxat_hex(c,p,8,&v)||!sxat_hex(c,p+8,8,&z)||!sxat_hex(c,p+16,8,&v)||!sxat_hex(c,p+24,4,&v)||!sxat_hex(c,p+28,4,&v)||!sxat_hex(c,p+32,2,&v)||!sxat_add(c,&sxat_lifkd_member,p))return false;p+=54;if(!sxat_span(c,p,z))return true;p+=z;}return true;}
bool sx_lifkd_build(sx_context*c)
{
 return sxat_lifkd(c);
}
