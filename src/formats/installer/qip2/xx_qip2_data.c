/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * QIP2 data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_qip_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("index_size","uint32",4,4,SX_SIZE),
 SX_FIELD("version","uint32",8,4,SX_NONE),
 SX_FIELD("reserved","uint32",12,4,SX_NONE),
};
const sx_layout sxap_qip_header = {UINT32_C(0x60720017),"qip_header",sxap_qip_header_fields,SX_COUNT(sxap_qip_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_qip_index_fields[] = {
 SX_FIELD("member_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("name","char[12]",4,12,SX_NONE),
};
const sx_layout sxap_qip_index = {UINT32_C(0x60720018),"qip_index",sxap_qip_index_fields,SX_COUNT(sxap_qip_index_fields),SX_LE};
static const xx_data_struct_field_desc sxap_qip_member_v1_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("kind","uint16",2,2,SX_NONE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("sequence_number","uint16",8,2,SX_NONE),
 SX_FIELD("flags","uint8",10,1,SX_FLAGS),
 SX_FIELD("dos_time","uint16",11,2,SX_NONE),
 SX_FIELD("dos_date","uint16",13,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",15,4,SX_SIZE),
 SX_FIELD("name","char[13]",19,13,SX_NONE),
};
const sx_layout sxap_qip_member_v1 = {UINT32_C(0x60720019),"qip_member_v1",sxap_qip_member_v1_fields,SX_COUNT(sxap_qip_member_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxap_qip_member_v2_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("kind","uint16",2,2,SX_NONE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("sequence_number","uint16",8,2,SX_NONE),
 SX_FIELD("flags","uint8",10,1,SX_FLAGS),
 SX_FIELD("dos_time","uint16",11,2,SX_NONE),
 SX_FIELD("dos_date","uint16",13,2,SX_NONE),
 SX_FIELD("unknown","uint32",15,4,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",19,4,SX_SIZE),
 SX_FIELD("name","char[13]",23,13,SX_NONE),
};
const sx_layout sxap_qip_member_v2 = {UINT32_C(0x6072001a),"qip_member_v2",sxap_qip_member_v2_fields,SX_COUNT(sxap_qip_member_v2_fields),SX_LE};
static bool sxap_qip(sx_context*c){uint64_t n,ver;if(!sxap_word(c,2,2,false,&n)||!sxap_word(c,8,4,false,&ver)||!sxap_add(c,&sxap_qip_header,0)||!sxap_table(c,&sxap_qip_index,16,16,n))return false;uint64_t width=ver==1?32:36;for(uint64_t i=0;i<n;i++){uint64_t p,z;if(!sxap_word(c,16+i*16,4,false,&p)||!sxap_word(c,p+4,4,false,&z)||!sxap_add(c,ver==1?&sxap_qip_member_v1:&sxap_qip_member_v2,p)||!sxap_span(c,p+width,z)||!sxap_dcl(c,p+width,z))return false;}return true;}
bool sx_qip2_build(sx_context*c)
{
 return sxap_qip(c);
}
