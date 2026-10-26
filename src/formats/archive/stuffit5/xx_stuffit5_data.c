/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * STUFFIT5 data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_sit5_header_fields[] = {
 SX_FIELD("banner","char[80]",0,80,SX_SIGNATURE),
 SX_FIELD("marker","uint16",80,2,SX_SIGNATURE),
 SX_FIELD("version","uint8",82,1,SX_ID),
 SX_FIELD("flags","uint8",83,1,SX_FLAGS),
 SX_FIELD("archive_size","uint32",84,4,SX_SIZE),
 SX_FIELD("entry_offset","uint32",88,4,SX_OFFSET),
 SX_FIELD("root_entry_count","uint16",92,2,SX_COUNT_PROP),
 SX_FIELD("first_entry_offset","uint32",94,4,SX_OFFSET),
 SX_FIELD("header_crc16","uint16",98,2,SX_CHECKSUM),
};
const sx_layout sxal_sit5_header = {UINT32_C(0x6020001f),"sit5_header",sxal_sit5_header_fields,SX_COUNT(sxal_sit5_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_sit5_file_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("unknown5","uint8",5,1,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("unknown8","uint8",8,1,SX_NONE),
 SX_FIELD("flags","uint8",9,1,SX_FLAGS),
 SX_FIELD("created","uint32",10,4,SX_NONE),
 SX_FIELD("modified","uint32",14,4,SX_NONE),
 SX_FIELD("previous_entry_offset","uint32",18,4,SX_OFFSET),
 SX_FIELD("next_entry_offset","uint32",22,4,SX_OFFSET),
 SX_FIELD("parent_entry_offset","uint32",26,4,SX_OFFSET),
 SX_FIELD("name_size","uint16",30,2,SX_SIZE),
 SX_FIELD("header_crc16","uint16",32,2,SX_CHECKSUM),
 SX_FIELD("data_unpacked_size","uint32",34,4,SX_SIZE),
 SX_FIELD("data_packed_size","uint32",38,4,SX_SIZE),
 SX_FIELD("data_crc16","uint16",42,2,SX_CHECKSUM),
 SX_FIELD("unknown44","uint16",44,2,SX_NONE),
 SX_FIELD("method","uint8",46,1,SX_ID),
 SX_FIELD("password_size","uint8",47,1,SX_SIZE),
};
const sx_layout sxal_sit5_file = {UINT32_C(0x60200020),"sit5_file",sxal_sit5_file_fields,SX_COUNT(sxal_sit5_file_fields),SX_BE};
static const xx_data_struct_field_desc sxal_sit5_folder_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("unknown5","uint8",5,1,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("unknown8","uint8",8,1,SX_NONE),
 SX_FIELD("flags","uint8",9,1,SX_FLAGS),
 SX_FIELD("created","uint32",10,4,SX_NONE),
 SX_FIELD("modified","uint32",14,4,SX_NONE),
 SX_FIELD("previous_entry_offset","uint32",18,4,SX_OFFSET),
 SX_FIELD("next_entry_offset","uint32",22,4,SX_OFFSET),
 SX_FIELD("parent_entry_offset","uint32",26,4,SX_OFFSET),
 SX_FIELD("name_size","uint16",30,2,SX_SIZE),
 SX_FIELD("header_crc16","uint16",32,2,SX_CHECKSUM),
 SX_FIELD("first_child_offset","uint32",34,4,SX_OFFSET),
 SX_FIELD("folder_size","uint32",38,4,SX_SIZE),
 SX_FIELD("unknown42","uint8[4]",42,4,SX_NONE),
 SX_FIELD("child_count","uint16",46,2,SX_COUNT_PROP),
};
const sx_layout sxal_sit5_folder = {UINT32_C(0x60200021),"sit5_folder",sxal_sit5_folder_fields,SX_COUNT(sxal_sit5_folder_fields),SX_BE};
static const xx_data_struct_field_desc sxal_sit5_second_v1_fields[] = {
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("unknown2","uint16",2,2,SX_NONE),
 SX_FIELD("file_type","char[4]",4,4,SX_ID),
 SX_FIELD("creator","char[4]",8,4,SX_ID),
 SX_FIELD("finder_flags","uint16",12,2,SX_FLAGS),
 SX_FIELD("finder_metadata","uint8[22]",14,22,SX_NONE),
};
const sx_layout sxal_sit5_second_v1 = {UINT32_C(0x60200022),"sit5_second_v1",sxal_sit5_second_v1_fields,SX_COUNT(sxal_sit5_second_v1_fields),SX_BE};
static const xx_data_struct_field_desc sxal_sit5_second_v3_fields[] = {
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("unknown2","uint16",2,2,SX_NONE),
 SX_FIELD("file_type","char[4]",4,4,SX_ID),
 SX_FIELD("creator","char[4]",8,4,SX_ID),
 SX_FIELD("finder_flags","uint16",12,2,SX_FLAGS),
 SX_FIELD("finder_metadata","uint8[18]",14,18,SX_NONE),
};
const sx_layout sxal_sit5_second_v3 = {UINT32_C(0x60200023),"sit5_second_v3",sxal_sit5_second_v3_fields,SX_COUNT(sxal_sit5_second_v3_fields),SX_BE};
static const xx_data_struct_field_desc sxal_sit5_resource_fields[] = {
 SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
 SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("crc16","uint16",8,2,SX_CHECKSUM),
 SX_FIELD("unknown10","uint16",10,2,SX_NONE),
 SX_FIELD("method","uint8",12,1,SX_ID),
 SX_FIELD("password_size","uint8",13,1,SX_SIZE),
};
const sx_layout sxal_sit5_resource = {UINT32_C(0x60200024),"sit5_resource",sxal_sit5_resource_fields,SX_COUNT(sxal_sit5_resource_fields),SX_BE};
static bool sxal_sit5(sx_context *c){uint8_t b[100];if(!sxal_read(c,0,b,100)||!sxal_add(c,&sxal_sit5_header,0))return false;uint64_t p=sxal32(b+94,true);if(p<100)return true;
 for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){if(!sxal_read(c,p,b,48)||sxal32(b,true)!=0xa5a5a5a5U)break;unsigned head=sxal16(b+6,true),v=b[4];bool folder=(b[9]&64)!=0;uint64_t packed=folder?0:sxal32(b+38,true);bool last=folder&&sxal32(b+34,true)==UINT32_MAX;if(head<48||!sxal_span(c,p,head))break;if(!sxal_add(c,folder?&sxal_sit5_folder:&sxal_sit5_file,p))return false;p+=head;if(last)continue;
  unsigned second=v==1?36:32;if(!sxal_read(c,p,b,second))break;bool resource=(sxal16(b,true)&1)!=0;if(!sxal_add(c,v==1?&sxal_sit5_second_v1:&sxal_sit5_second_v3,p))return false;p+=second;
  if(!folder&&resource){if(!sxal_read(c,p,b,14))break;packed+=sxal32(b+4,true);if(!sxal_add(c,&sxal_sit5_resource,p))return false;p+=14;if(!sxal_span(c,p,b[13]))break;p+=b[13];}if(!sxal_span(c,p,packed))break;p+=packed;
 }return true;}
bool sx_stuffit5_build(sx_context*c)
{
 return sxal_sit5(c);
}
