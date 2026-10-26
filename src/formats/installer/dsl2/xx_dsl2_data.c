/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DSL2 data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_dsl2_header_fields[] = {
 SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("revision","uint16",16,2,SX_NONE),
 SX_FIELD("member_count","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("unused","uint32",20,4,SX_NONE),
 SX_FIELD("directory_end","int32",24,4,SX_OFFSET),
};
const sx_layout sxao_dsl2_header = {UINT32_C(0x60700005),"dsl2_header",sxao_dsl2_header_fields,SX_COUNT(sxao_dsl2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_dsl2_path_length_fields[] = {
 SX_FIELD("path_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxao_dsl2_path_length = {UINT32_C(0x60700006),"dsl2_path_length",sxao_dsl2_path_length_fields,SX_COUNT(sxao_dsl2_path_length_fields),SX_LE};
static const xx_data_struct_field_desc sxao_dsl2_member_fields[] = {
 SX_FIELD("record_size","uint16_bias33_le",0,2,SX_SIZE),
 SX_FIELD("uncompressed_size","int32_bias33_le",2,4,SX_SIZE),
 SX_FIELD("compressed_size","int32_bias33_le",6,4,SX_SIZE),
 SX_FIELD("payload_offset","int32_bias33_le",10,4,SX_OFFSET),
 SX_FIELD("dos_time","uint16_bias33_le",14,2,SX_NONE),
 SX_FIELD("dos_date","uint16_bias33_le",16,2,SX_NONE),
 SX_FIELD("flags","uint16_bias33_le",18,2,SX_FLAGS),
};
const sx_layout sxao_dsl2_member = {UINT32_C(0x60700007),"dsl2_member",sxao_dsl2_member_fields,SX_COUNT(sxao_dsl2_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_dsl2_name_length_fields[] = {
 SX_FIELD("name_size","uint16_bias33_le",0,2,SX_SIZE),
};
const sx_layout sxao_dsl2_name_length = {UINT32_C(0x60700008),"dsl2_name_length",sxao_dsl2_name_length_fields,SX_COUNT(sxao_dsl2_name_length_fields),SX_LE};
static const xx_data_struct_field_desc sxao_dsl2_name_fields[] = {
 SX_FIELD("name","bias33_char",0,0,SX_NONE),
};
const sx_layout sxao_dsl2_name = {UINT32_C(0x60700009),"dsl2_name",sxao_dsl2_name_fields,SX_COUNT(sxao_dsl2_name_fields),SX_LE};
static bool sxao_dsl2(sx_context*c){uint64_t p=28,n,end;if(!sxao_add(c,&sxao_dsl2_header,0)||!sxao_word(c,18,2,false,&n)||!sxao_word(c,24,4,false,&end)||end>INT32_MAX||end>(uint64_t)c->size)return false;for(unsigned i=0;i<2;i++){uint64_t z;if(!sxao_word(c,p,2,false,&z)||!sxao_add(c,&sxao_dsl2_path_length,p)||!sxao_span(c,p+2,z)||p+2+z>end)return false;p+=2;if(!sxao_text(c,&sxao_archiveobsolete_path,p,z,false))return false;p+=z;}
 for(uint64_t i=0;i<n;i++){uint8_t b[22];if(p>end||end-p<20||!sxao_read(c,p,b,20))return false;for(unsigned j=0;j<20;j++)b[j]=(uint8_t)(b[j]-0x33U);uint64_t z=sxao_uint(b,2,false);if(z<20||z>end-p||!sxao_put(c,&sxao_dsl2_member,p,20,true))return false;uint64_t payload=sxao_uint(b+10,4,false),packed=sxao_uint(b+6,4,false);if((sxao_uint(b+18,2,false)&16)&&payload<=INT32_MAX&&packed<=INT32_MAX&&sxao_span(c,payload,packed)&&!sxao_dcl(c,payload,packed))return false;if(end-p>=22){if(!sxao_read(c,p+20,b+20,2))return false;b[20]=(uint8_t)(b[20]-0x33U);b[21]=(uint8_t)(b[21]-0x33U);uint64_t name=sxao_uint(b+20,2,false);if(name>end-p-22)name=end-p-22;if(!sxao_put(c,&sxao_dsl2_name_length,p+20,2,true)||!sxao_text(c,&sxao_dsl2_name,p+22,name,true))return false;}p+=z;}return true;}
bool sx_dsl2_build(sx_context*c)
{
 return sxao_dsl2(c);
}
