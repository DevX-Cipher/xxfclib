/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MIZ data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_miz_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("signature2","char[4]",6,4,SX_SIGNATURE),
 SX_FIELD("name_field_size","uint16",10,2,SX_SIZE),
};
const sx_layout sxasy_miz_header = {UINT32_C(0x6044001a),"miz_header",sxasy_miz_header_fields,SX_COUNT(sxasy_miz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_miz_member_fields[] = {
 SX_FIELD("dos_time","uint16",0,2,SX_NONE),
 SX_FIELD("dos_date","uint16",2,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",8,4,SX_SIZE),
};
const sx_layout sxasy_miz_member = {UINT32_C(0x6044001b),"miz_member",sxasy_miz_member_fields,SX_COUNT(sxasy_miz_member_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_miz_footer_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxasy_miz_footer = {UINT32_C(0x60440039),"miz_footer",sxasy_miz_footer_fields,SX_COUNT(sxasy_miz_footer_fields),SX_LE};
static bool sxasy_miz(sx_context*c){uint64_t n,z;if(!sxasy_word(c,10,2,false,&n)||n<2||n>64||!sxasy_add(c,&sxasy_miz_header,0)||!sxasy_word(c,20+n,4,false,&z)||!sxasy_add(c,&sxasy_miz_member,12+n))return false;return sxasy_dcl(c,24+n,z)&&sxasy_add(c,&sxasy_miz_footer,24+n+z);}
bool sx_miz_build(sx_context*c)
{
 return sxasy_miz(c);
}
