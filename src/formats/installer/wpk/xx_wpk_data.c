/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WPK data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_wpk_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("directory_size","uint16",6,2,SX_SIZE),
 SX_FIELD("directory_offset","uint32",8,4,SX_OFFSET),
};
const sx_layout sxafr_wpk_header = {UINT32_C(0x60540027),"wpk_header",sxafr_wpk_header_fields,SX_COUNT(sxafr_wpk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_wpk_member_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("payload_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("timestamp","uint32",8,4,SX_NONE),
 SX_FIELD("crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("method_and_name_size","uint8",16,1,SX_FLAGS),
};
const sx_layout sxafr_wpk_member = {UINT32_C(0x60540028),"wpk_member",sxafr_wpk_member_fields,SX_COUNT(sxafr_wpk_member_fields),SX_LE};
static bool sxafr_wpk(sx_context*c){uint64_t p,n,z;if(!sxafr_word(c,4,2,false,&n)||!sxafr_word(c,6,2,false,&z)||!sxafr_word(c,8,4,false,&p)||!sxafr_span(c,p,z)||!sxafr_add(c,&sxafr_wpk_header,0))return false;uint64_t end=p+z;for(uint64_t i=0;i<n;i++){uint64_t flags;if(p>end||end-p<17||!sxafr_word(c,p+16,1,false,&flags)||((flags&127)>end-p-17)||!sxafr_add(c,&sxafr_wpk_member,p))return false;p+=17+(flags&127);}return true;}
bool sx_wpk_build(sx_context*c)
{
 return sxafr_wpk(c);
}
