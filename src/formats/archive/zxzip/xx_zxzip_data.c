/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ZXZip data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_zxzip_header_fields[] = {
 SX_FIELD("name","char[8]",0,8,SX_NONE),
 SX_FIELD("signature","char[3]",8,3,SX_SIGNATURE),
 SX_FIELD("chain_size","uint16",11,2,SX_SIZE),
 SX_FIELD("reserved","uint8",13,1,SX_NONE),
 SX_FIELD("size_high_guard","uint8",14,1,SX_NONE),
 SX_FIELD("header_checksum","uint16",15,2,SX_CHECKSUM),
};
const sx_layout sxat_zxzip_header = {UINT32_C(0x60640001),"zxzip_header",sxat_zxzip_header_fields,SX_COUNT(sxat_zxzip_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_zxzip_member_fields[] = {
 SX_FIELD("name","char[8]",0,8,SX_NONE),
 SX_FIELD("trdos_type","char[1]",8,1,SX_NONE),
 SX_FIELD("start_or_basic_size","uint16",9,2,SX_NONE),
 SX_FIELD("length","uint16",11,2,SX_SIZE),
 SX_FIELD("sector_count","uint8",13,1,SX_COUNT_PROP),
 SX_FIELD("compressed_size","uint16",14,2,SX_SIZE),
 SX_FIELD("checksum","uint32",16,4,SX_CHECKSUM),
 SX_FIELD("method","uint8",20,1,SX_NONE),
 SX_FIELD("submethod","uint8",21,1,SX_NONE),
};
const sx_layout sxat_zxzip_member = {UINT32_C(0x60640002),"zxzip_member",sxat_zxzip_member_fields,SX_COUNT(sxat_zxzip_member_fields),SX_LE};
static bool sxat_zxzip(sx_context*c){uint64_t p=17,remain;if(!sxat_word(c,11,2,false,&remain)||!sxat_add(c,&sxat_zxzip_header,0))return false;while(remain>=22){uint64_t z;if(!sxat_word(c,p+14,2,false,&z)||!sxat_add(c,&sxat_zxzip_member,p))return false;p+=22;remain-=22;if(z>remain||!sxat_span(c,p,z))return true;p+=z;remain-=z;}return true;}
bool sx_zxzip_build(sx_context*c)
{
 return sxat_zxzip(c);
}
