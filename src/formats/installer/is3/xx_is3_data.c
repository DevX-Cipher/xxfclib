/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IS3 data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_is3_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("reserved","uint16",6,2,SX_NONE),
 SX_FIELD("unknown1","uint8[4]",8,4,SX_NONE),
 SX_FIELD("member_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("timestamp","uint32",14,4,SX_NONE),
 SX_FIELD("archive_size","uint32",18,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",22,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",26,4,SX_OFFSET),
 SX_FIELD("unknown2","uint8[11]",30,11,SX_NONE),
 SX_FIELD("directory_offset","uint32",41,4,SX_OFFSET),
 SX_FIELD("directory_size","uint32",45,4,SX_SIZE),
 SX_FIELD("directory_count","uint16",49,2,SX_COUNT_PROP),
 SX_FIELD("file_table_offset","uint32",51,4,SX_OFFSET),
 SX_FIELD("file_table_size","uint32",55,4,SX_SIZE),
};
const sx_layout sxan_is3_header = {UINT32_C(0x60770001),"is3_header",sxan_is3_header_fields,SX_COUNT(sxan_is3_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is3_directory_fields[] = {
 SX_FIELD("member_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("entry_size","uint16",2,2,SX_SIZE),
 SX_FIELD("name_size","uint16",4,2,SX_SIZE),
};
const sx_layout sxan_is3_directory = {UINT32_C(0x60770002),"is3_directory",sxan_is3_directory_fields,SX_COUNT(sxan_is3_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is3_member_fields[] = {
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved","uint16",1,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",3,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",11,4,SX_OFFSET),
 SX_FIELD("timestamp","uint32",15,4,SX_NONE),
 SX_FIELD("attributes","uint32",19,4,SX_FLAGS),
 SX_FIELD("entry_size","uint16",23,2,SX_SIZE),
 SX_FIELD("volume","uint16",25,2,SX_NONE),
 SX_FIELD("unknown","uint16",27,2,SX_NONE),
 SX_FIELD("name_size","uint8",29,1,SX_SIZE),
};
const sx_layout sxan_is3_member = {UINT32_C(0x60770003),"is3_member",sxan_is3_member_fields,SX_COUNT(sxan_is3_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is3_payload_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("copyright","char[70]",8,70,SX_NONE),
 SX_FIELD("member_count","uint32",78,4,SX_COUNT_PROP),
};
const sx_layout sxan_is3_payload_header = {UINT32_C(0x60770004),"is3_payload_header",sxan_is3_payload_header_fields,SX_COUNT(sxan_is3_payload_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is3_payload_member_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("reserved1","uint32",12,4,SX_NONE),
 SX_FIELD("reserved2","uint32",16,4,SX_NONE),
 SX_FIELD("name_size","uint16",20,2,SX_SIZE),
};
const sx_layout sxan_is3_payload_member = {UINT32_C(0x60770005),"is3_payload_member",sxan_is3_payload_member_fields,SX_COUNT(sxan_is3_payload_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_is3_second_name_fields[] = {
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxan_is3_second_name = {UINT32_C(0x60770006),"is3_second_name",sxan_is3_second_name_fields,SX_COUNT(sxan_is3_second_name_fields),SX_LE};
static bool sxan_is3(sx_context*c){uint64_t magic,n,p,end,z,len;if(!sxan_word(c,0,4,false,&magic))return false;if(magic==0xd879ab2aU){if(!sxan_add(c,&sxan_is3_payload_header,0)||!sxan_word(c,78,4,false,&n))return false;p=82;for(uint64_t i=0;i<n;i++){if(!sxan_add(c,&sxan_is3_payload_member,p)||!sxan_word(c,p+20,2,false,&len)||!sxan_named(c,p+22,len))return false;p+=22+len;if(!sxan_word(c,p,2,false,&len)||!sxan_add(c,&sxan_is3_second_name,p)||!sxan_named(c,p+2,len))return false;p+=2+len;}return true;}
 if(!sxan_add(c,&sxan_is3_header,0)||!sxan_word(c,41,4,false,&p)||!sxan_word(c,45,4,false,&z)||!sxan_span(c,p,z)||!sxan_word(c,49,2,false,&n))return false;end=p+z;for(uint64_t i=0;i<n;i++){if(p>end||end-p<6||!sxan_word(c,p+2,2,false,&z)||!sxan_word(c,p+4,2,false,&len)||z<6||z>end-p||len>z-6||!sxan_add(c,&sxan_is3_directory,p)||!sxan_named(c,p+6,len))return false;p+=z;}
 if(!sxan_word(c,51,4,false,&p)||!sxan_word(c,55,4,false,&z)||!sxan_span(c,p,z)||!sxan_word(c,12,2,false,&n))return false;end=p+z;for(uint64_t i=0;i<n;i++){if(p>end||end-p<30||!sxan_word(c,p+23,2,false,&z)||!sxan_word(c,p+29,1,false,&len)||z<30||z>end-p||len>z-30||!sxan_add(c,&sxan_is3_member,p)||!sxan_named(c,p+30,len))return false;p+=z;}return true;}
bool sx_is3_build(sx_context*c)
{
bool ok=false;
ok=sxan_is3(c);
(void)ok;return c->count&&sxan_finish(c);
}
