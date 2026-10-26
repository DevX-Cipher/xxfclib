/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RCF data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_rcf_header_fields[] = {
 SX_FIELD("tag_size","uint8",0,1,SX_SIZE),
 SX_FIELD("encoded_signature","uint8[3]",1,3,SX_SIGNATURE),
 SX_FIELD("version_size","uint8",4,1,SX_SIZE),
 SX_FIELD("version","char[3]",5,3,SX_NONE),
 SX_FIELD("reserved","uint16",8,2,SX_NONE),
};
const sx_layout sxasy_rcf_header = {UINT32_C(0x60440027),"rcf_header",sxasy_rcf_header_fields,SX_COUNT(sxasy_rcf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_rcf_entry_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_NONE),
 SX_FIELD("compressed_size","int32",13,4,SX_SIZE),
};
const sx_layout sxasy_rcf_entry = {UINT32_C(0x60440028),"rcf_entry",sxasy_rcf_entry_fields,SX_COUNT(sxasy_rcf_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_rcf_count_fields[] = {
 SX_FIELD("member_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxasy_rcf_count = {UINT32_C(0x60440029),"rcf_count",sxasy_rcf_count_fields,SX_COUNT(sxasy_rcf_count_fields),SX_LE};
static bool sxasy_rcf(sx_context*c){uint64_t n,end=(uint64_t)c->size;if(end<12||!sxasy_word(c,end-2,2,false,&n)||n>(end-12)/17||!sxasy_add(c,&sxasy_rcf_header,0)||!sxasy_add(c,&sxasy_rcf_count,end-2))return false;uint64_t table=end-2-n*17,p=10;for(uint64_t i=0;i<n;i++){uint64_t z;if(!sxasy_word(c,table+i*17+13,4,false,&z)||z>INT32_MAX||p>table||z>table-p||!sxasy_add(c,&sxasy_rcf_entry,table+i*17)||!sxasy_dcl(c,p,z))return false;p+=z;}return p==table;}
bool sx_rcf_build(sx_context*c)
{
 return sxasy_rcf(c);
}
