/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RiverSoft data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_riversoft_header_fields[] = {
 SX_FIELD("signature","char[23]",0,23,SX_SIGNATURE),
 SX_FIELD("major_version","uint8",23,1,SX_NONE),
 SX_FIELD("opaque","uint8",24,1,SX_NONE),
 SX_FIELD("minor_version","uint8",25,1,SX_NONE),
 SX_FIELD("member_count","uint16",26,2,SX_COUNT_PROP),
 SX_FIELD("total_uncompressed_size","uint32",28,4,SX_SIZE),
};
const sx_layout sxasy_riversoft_header = {UINT32_C(0x6044002a),"riversoft_header",sxasy_riversoft_header_fields,SX_COUNT(sxasy_riversoft_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_riversoft_entry_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_NONE),
 SX_FIELD("payload_offset","uint32",13,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint16",17,2,SX_SIZE),
 SX_FIELD("uncompressed_size","uint16",19,2,SX_SIZE),
};
const sx_layout sxasy_riversoft_entry = {UINT32_C(0x6044002b),"riversoft_entry",sxasy_riversoft_entry_fields,SX_COUNT(sxasy_riversoft_entry_fields),SX_LE};
static bool sxasy_river(sx_context*c){uint64_t n,end=(uint64_t)c->size;if(!sxasy_word(c,26,2,false,&n)||end<32||n>(end-32)/21||!sxasy_add(c,&sxasy_riversoft_header,0))return false;uint64_t p=end-n*21;for(uint64_t i=0;i<n;i++){uint8_t h[21];if(!sxasy_read(c,p+i*21,h,21)||!sxasy_add(c,&sxasy_riversoft_entry,p+i*21))return false;uint64_t off=sxasy_uint(h+13,4,false),z=sxasy_uint(h+17,2,false);if(off>=32&&off<=p&&z<=p-off&&!sxasy_dcl(c,off,z))return false;}return true;}
bool sx_riversoft_build(sx_context*c)
{
 return sxasy_river(c);
}
