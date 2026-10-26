/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CPX / CPX4 data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_cpx_header_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_NONE),
 SX_FIELD("signature","uint8[3]",1,3,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",4,2,SX_COUNT_PROP),
};
const sx_layout sxao_cpx_header = {UINT32_C(0x60700032),"cpx_header",sxao_cpx_header_fields,SX_COUNT(sxao_cpx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_cpx_member_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("group","uint8",13,1,SX_NONE),
 SX_FIELD("dos_datetime","uint32",14,4,SX_NONE),
 SX_FIELD("size_and_stored_flag","uint32",18,4,SX_FLAGS),
 SX_FIELD("payload_offset","uint32",22,4,SX_OFFSET),
};
const sx_layout sxao_cpx_member = {UINT32_C(0x60700033),"cpx_member",sxao_cpx_member_fields,SX_COUNT(sxao_cpx_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_cpx4_header_fields[] = {
 SX_FIELD("version_stamp","uint8",0,1,SX_NONE),
 SX_FIELD("signature","uint8[3]",1,3,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("version","uint16",6,2,SX_NONE),
 SX_FIELD("record_table_size","uint32",8,4,SX_SIZE),
 SX_FIELD("record_table_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("name_table_size","uint32",16,4,SX_SIZE),
 SX_FIELD("name_table_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("extra_size","uint32",24,4,SX_SIZE),
 SX_FIELD("extra_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("stamp","uint32",32,4,SX_NONE),
};
const sx_layout sxao_cpx4_header = {UINT32_C(0x60700034),"cpx4_header",sxao_cpx4_header_fields,SX_COUNT(sxao_cpx4_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_cpx4_member_fields[] = {
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("attributes","uint32",4,4,SX_FLAGS),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("timestamp","uint32",12,4,SX_NONE),
 SX_FIELD("flags","uint32",16,4,SX_FLAGS),
 SX_FIELD("compressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("payload_offset","uint32",24,4,SX_OFFSET),
};
const sx_layout sxao_cpx4_member = {UINT32_C(0x60700035),"cpx4_member",sxao_cpx4_member_fields,SX_COUNT(sxao_cpx4_member_fields),SX_LE};
#define SXAO_LIMIT 20000U
static bool sxao_cpx(sx_context*c){uint64_t version;if(!sxao_word(c,0,1,false,&version))return false;if(version!=0x2c){uint64_t n;return sxao_word(c,4,2,false,&n)&&sxao_add(c,&sxao_cpx_header,0)&&sxao_table(c,&sxao_cpx_member,6,26,n);}uint64_t size,off,names,nsize;if(!sxao_word(c,8,4,false,&size)||!sxao_word(c,12,4,false,&off)||!sxao_word(c,16,4,false,&nsize)||!sxao_word(c,20,4,false,&names)||!sxao_add(c,&sxao_cpx4_header,0)||size%28||!sxao_table(c,&sxao_cpx4_member,off,28,size/28)||!sxao_span(c,names,nsize))return false;for(uint64_t i=0;i<size/28&&c->count<SXAO_LIMIT;i++){uint64_t rel,n;if(!sxao_word(c,off+i*28,4,false,&rel))return false;if(rel<nsize&&sxao_zlen(c,names+rel,names+nsize,&n)&&!sxao_text(c,&sxao_archiveobsolete_name,names+rel,n,false))return false;}return true;}
bool sx_cpx_build(sx_context*c)
{
 return sxao_cpx(c);
}
