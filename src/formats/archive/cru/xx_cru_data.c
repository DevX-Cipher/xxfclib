/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CRU data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_cru_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("separator","char[1]",8,1,SX_NONE),
 SX_FIELD("minor_version","uint8",9,1,SX_NONE),
 SX_FIELD("guard","uint8[3]",10,3,SX_SIGNATURE),
 SX_FIELD("opaque","uint8[3]",13,3,SX_NONE),
 SX_FIELD("directory_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("member_count","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("reserved","uint16",20,2,SX_NONE),
 SX_FIELD("directory_offset","uint32",22,4,SX_OFFSET),
};
const sx_layout sxasy_cru_header = {UINT32_C(0x6044000a),"cru_header",sxasy_cru_header_fields,SX_COUNT(sxasy_cru_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_cru_entry_fields[] = {
 SX_FIELD("directory_index","uint8",0,1,SX_NONE),
 SX_FIELD("opaque1","uint8",1,1,SX_NONE),
 SX_FIELD("dos_time","uint16",2,2,SX_NONE),
 SX_FIELD("dos_date","uint16",4,2,SX_NONE),
 SX_FIELD("stored_size","uint32",6,4,SX_SIZE),
 SX_FIELD("name","char[12]",10,12,SX_NONE),
 SX_FIELD("opaque2","uint8[2]",22,2,SX_NONE),
};
const sx_layout sxasy_cru_entry = {UINT32_C(0x6044000b),"cru_entry",sxasy_cru_entry_fields,SX_COUNT(sxasy_cru_entry_fields),SX_LE};
static bool sxasy_cru(sx_context*c){uint64_t n,p;if(!sxasy_word(c,18,2,false,&n)||!sxasy_word(c,22,4,false,&p)||!sxasy_span(c,p,n*24)||!sxasy_add(c,&sxasy_cru_header,0))return false;for(uint64_t i=0;i<n;i++)if(!sxasy_add(c,&sxasy_cru_entry,p+i*24))return false;return true;}
bool sx_cru_build(sx_context*c)
{
 return sxasy_cru(c);
}
