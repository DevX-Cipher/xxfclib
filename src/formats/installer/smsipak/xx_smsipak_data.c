/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SMSIPAK data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_smsipak_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("stamp","uint16",8,2,SX_NONE),
 SX_FIELD("member_area_end","uint32",10,4,SX_OFFSET),
};
const sx_layout sxao_smsipak_header = {UINT32_C(0x6070002e),"smsipak_header",sxao_smsipak_header_fields,SX_COUNT(sxao_smsipak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_smsipak_member_fields[] = {
 SX_FIELD("name","char[12]",0,12,SX_NONE),
 SX_FIELD("terminator","uint8",12,1,SX_NONE),
 SX_FIELD("dos_date","uint16",13,2,SX_NONE),
 SX_FIELD("dos_time","uint16",15,2,SX_NONE),
 SX_FIELD("crc32","uint32",17,4,SX_CHECKSUM),
 SX_FIELD("attributes","uint16",21,2,SX_FLAGS),
 SX_FIELD("method","uint8",23,1,SX_NONE),
 SX_FIELD("uncompressed_size","int32",24,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",28,4,SX_SIZE),
 SX_FIELD("zero","uint16",32,2,SX_NONE),
};
const sx_layout sxao_smsipak_member = {UINT32_C(0x6070002f),"smsipak_member",sxao_smsipak_member_fields,SX_COUNT(sxao_smsipak_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_smsipak_index_fields[] = {
 SX_FIELD("zero","uint32",0,4,SX_NONE),
 SX_FIELD("member_count","uint16",4,2,SX_COUNT_PROP),
};
const sx_layout sxao_smsipak_index = {UINT32_C(0x60700030),"smsipak_index",sxao_smsipak_index_fields,SX_COUNT(sxao_smsipak_index_fields),SX_LE};
static const xx_data_struct_field_desc sxao_smsipak_index_entry_fields[] = {
 SX_FIELD("member_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxao_smsipak_index_entry = {UINT32_C(0x60700031),"smsipak_index_entry",sxao_smsipak_index_entry_fields,SX_COUNT(sxao_smsipak_index_entry_fields),SX_LE};
static bool sxao_smsi(sx_context*c){uint64_t end,p=14;if(!sxao_word(c,10,4,false,&end)||!sxao_add(c,&sxao_smsipak_header,0)||end>(uint64_t)c->size)return false;while(p<end){uint64_t z,method;if(end-p<34||!sxao_word(c,p+28,4,false,&z)||z>INT32_MAX||!sxao_word(c,p+23,1,false,&method)||!sxao_add(c,&sxao_smsipak_member,p))return false;p+=34;if(z>end-p)return true;if(method==1&&!sxao_dcl(c,p,z))return false;p+=z;}if(sxao_span(c,end,6)){uint64_t n;if(!sxao_word(c,end+4,2,false,&n)||!sxao_add(c,&sxao_smsipak_index,end)||!sxao_table(c,&sxao_smsipak_index_entry,end+6,4,n))return false;}return true;}
bool sx_smsipak_build(sx_context*c)
{
 return sxao_smsi(c);
}
