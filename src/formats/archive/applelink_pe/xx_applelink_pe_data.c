/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AppleLink Package (ACU) data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_applelink_header_fields[] = {
 SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("source_filesystem","uint16",2,2,SX_ID),
 SX_FIELD("signature","char[5]",4,5,SX_SIGNATURE),
 SX_FIELD("version","uint8",9,1,SX_ID),
 SX_FIELD("member_header_size","uint16",10,2,SX_SIZE),
 SX_FIELD("reserved","uint8[7]",12,7,SX_RESERVED),
 SX_FIELD("producer","uint8",19,1,SX_NONE),
};
const sx_layout sxag_applelink_header = {UINT32_C(0x6025000a),"applelink_header",sxag_applelink_header_fields,SX_COUNT(sxag_applelink_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_applelink_member_fields[] = {
 SX_FIELD("resource_method","uint8",0,1,SX_ID),
 SX_FIELD("data_method","uint8",1,1,SX_ID),
 SX_FIELD("resource_crc16","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("data_crc16","uint16",4,2,SX_CHECKSUM),
 SX_FIELD("resource_storage_blocks","uint32",6,4,SX_COUNT_PROP),
 SX_FIELD("data_storage_blocks","uint32",10,4,SX_COUNT_PROP),
 SX_FIELD("resource_packed_size","uint32",14,4,SX_SIZE),
 SX_FIELD("data_packed_size","uint32",18,4,SX_SIZE),
 SX_FIELD("access","uint16",22,2,SX_FLAGS),
 SX_FIELD("file_type","uint16",24,2,SX_ID),
 SX_FIELD("aux_type","uint32",26,4,SX_ID),
 SX_FIELD("reserved","uint16",30,2,SX_RESERVED),
 SX_FIELD("storage_type","uint16",32,2,SX_ID),
 SX_FIELD("resource_unpacked_size","uint32",34,4,SX_SIZE),
 SX_FIELD("data_unpacked_size","uint32",38,4,SX_SIZE),
 SX_FIELD("created_date","uint16",42,2,SX_NONE),
 SX_FIELD("created_time","uint16",44,2,SX_NONE),
 SX_FIELD("modified_date","uint16",46,2,SX_NONE),
 SX_FIELD("modified_time","uint16",48,2,SX_NONE),
 SX_FIELD("name_size","uint16",50,2,SX_SIZE),
 SX_FIELD("header_crc16","uint16",52,2,SX_CHECKSUM),
};
const sx_layout sxag_applelink_member = {UINT32_C(0x6025000b),"applelink_member",sxag_applelink_member_fields,SX_COUNT(sxag_applelink_member_fields),SX_LE};
#define SXAG_LIMIT 20000U
static bool sxag_applelink(sx_context *c){uint8_t b[54];if(!sxag_read(c,0,b,20)||!sxag_add(c,&sxag_applelink_header,0))return false;unsigned count=sxag16(b,false);uint64_t p=20;for(unsigned i=0;i<count&&i<SXAG_LIMIT;i++){if(!sxag_read(c,p,b,54))break;uint64_t name=sxag16(b+50,false),data=(uint64_t)sxag32(b+14,false)+sxag32(b+18,false);if(!sxag_span(c,p+54,name))break;if(!sxag_add(c,&sxag_applelink_member,p))return false;p+=54+name;if(!sxag_span(c,p,data))break;p+=data;}return true;}
bool sx_applelink_pe_build(sx_context*c)
{
 return sxag_applelink(c);
}
