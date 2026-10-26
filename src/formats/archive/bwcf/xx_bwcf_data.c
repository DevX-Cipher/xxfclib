/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BWCF data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_bwcf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_NONE),
 SX_FIELD("description","char[81]",5,81,SX_NONE),
};
const sx_layout sxacl_bwcf_header = {UINT32_C(0x60500021),"bwcf_header",sxacl_bwcf_header_fields,SX_COUNT(sxacl_bwcf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_bwcf_name_v1_fields[] = {
 SX_FIELD("name","char[268]",0,268,SX_NONE),
};
const sx_layout sxacl_bwcf_name_v1 = {UINT32_C(0x60500022),"bwcf_name_v1",sxacl_bwcf_name_v1_fields,SX_COUNT(sxacl_bwcf_name_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_bwcf_name_v2_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_NONE),
 SX_FIELD("name_size","uint8",5,1,SX_SIZE),
};
const sx_layout sxacl_bwcf_name_v2 = {UINT32_C(0x60500023),"bwcf_name_v2",sxacl_bwcf_name_v2_fields,SX_COUNT(sxacl_bwcf_name_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_bwcf_directory_size_fields[] = {
 SX_FIELD("directory_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxacl_bwcf_directory_size = {UINT32_C(0x60500024),"bwcf_directory_size",sxacl_bwcf_directory_size_fields,SX_COUNT(sxacl_bwcf_directory_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_bwcf_member_fields[] = {
 SX_FIELD("dos_time","uint16",0,2,SX_NONE),
 SX_FIELD("dos_date","uint16",2,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("block_size","int32",8,4,SX_SIZE),
 SX_FIELD("reserved","uint32",12,4,SX_NONE),
 SX_FIELD("method","uint8",16,1,SX_NONE),
};
const sx_layout sxacl_bwcf_member = {UINT32_C(0x60500025),"bwcf_member",sxacl_bwcf_member_fields,SX_COUNT(sxacl_bwcf_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_bwcf_block_size_fields[] = {
 SX_FIELD("uncompressed_size","int32",0,4,SX_SIZE),
};
const sx_layout sxacl_bwcf_block_size = {UINT32_C(0x60500026),"bwcf_block_size",sxacl_bwcf_block_size_fields,SX_COUNT(sxacl_bwcf_block_size_fields),SX_LE};
#define SXACL_LIMIT 20000U
static bool sxacl_bwcf(sx_context*c){uint64_t version,p=86;if(!sxacl_word(c,4,1,false,&version)||(version!=1&&version!=2)||!sxacl_add(c,&sxacl_bwcf_header,0))return false;for(unsigned i=0;i<SXACL_LIMIT&&p<(uint64_t)c->size;i++){if(version==1){if(!sxacl_add(c,&sxacl_bwcf_name_v1,p))return false;p+=268;}else{uint64_t n;if(!sxacl_word(c,p+5,1,false,&n)||!sxacl_span(c,p+6,n)||!sxacl_add(c,&sxacl_bwcf_name_v2,p))return false;p+=6+n;if(!sxacl_word(c,p,1,false,&n)||!sxacl_span(c,p+1,n)||!sxacl_add(c,&sxacl_bwcf_directory_size,p))return false;p+=1+n;}uint64_t z;if(!sxacl_word(c,p+8,4,false,&z)||z<4||z>INT32_MAX||!sxacl_span(c,p+17,z)||!sxacl_add(c,&sxacl_bwcf_member,p)||!sxacl_add(c,&sxacl_bwcf_block_size,p+17))return false;p+=17+z;}return true;}
bool sx_bwcf_build(sx_context*c)
{
 return sxacl_bwcf(c);
}
