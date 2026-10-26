/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LingvoArc data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_lingvo_header_fields[] = {
 SX_FIELD("signature","char[9]",0,9,SX_SIGNATURE),
 SX_FIELD("version","char[1]",9,1,SX_NONE),
 SX_FIELD("marker","uint8[6]",10,6,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",16,2,SX_COUNT_PROP),
};
const sx_layout sxap_lingvo_header = {UINT32_C(0x60720003),"lingvo_header",sxap_lingvo_header_fields,SX_COUNT(sxap_lingvo_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_lingvo_index_v1_fields[] = {
 SX_FIELD("name","char[46]",0,46,SX_NONE),
 SX_FIELD("descriptor_offset","uint32",46,4,SX_OFFSET),
 SX_FIELD("unknown","uint8[4]",50,4,SX_NONE),
};
const sx_layout sxap_lingvo_index_v1 = {UINT32_C(0x60720004),"lingvo_index_v1",sxap_lingvo_index_v1_fields,SX_COUNT(sxap_lingvo_index_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxap_lingvo_member_v1_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("payload_size","uint32",13,4,SX_SIZE),
 SX_FIELD("dos_datetime","uint32",17,4,SX_NONE),
 SX_FIELD("fragment_method","uint16",21,2,SX_NONE),
};
const sx_layout sxap_lingvo_member_v1 = {UINT32_C(0x60720005),"lingvo_member_v1",sxap_lingvo_member_v1_fields,SX_COUNT(sxap_lingvo_member_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxap_lingvo_index_v2_fields[] = {
 SX_FIELD("name","char[101]",0,101,SX_NONE),
 SX_FIELD("descriptor_offset","uint32",101,4,SX_OFFSET),
 SX_FIELD("unknown","uint8[4]",105,4,SX_NONE),
};
const sx_layout sxap_lingvo_index_v2 = {UINT32_C(0x60720006),"lingvo_index_v2",sxap_lingvo_index_v2_fields,SX_COUNT(sxap_lingvo_index_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxap_lingvo_member_v2_fields[] = {
 SX_FIELD("name","char[61]",0,61,SX_NONE),
 SX_FIELD("payload_size","uint32",61,4,SX_SIZE),
 SX_FIELD("dos_datetime","uint32",65,4,SX_NONE),
 SX_FIELD("fragment_method","uint16",69,2,SX_NONE),
};
const sx_layout sxap_lingvo_member_v2 = {UINT32_C(0x60720007),"lingvo_member_v2",sxap_lingvo_member_v2_fields,SX_COUNT(sxap_lingvo_member_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxap_finear_header_fields[] = {
 SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("marker","uint8[3]",6,3,SX_SIGNATURE),
 SX_FIELD("crc16_word","uint32",9,4,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","uint32",13,4,SX_SIZE),
};
const sx_layout sxap_finear_header = {UINT32_C(0x60720008),"finear_header",sxap_finear_header_fields,SX_COUNT(sxap_finear_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_lingvo_stream_header_fields[] = {
 SX_FIELD("signature","char[10]",0,10,SX_SIGNATURE),
 SX_FIELD("parameters","uint8[16]",10,16,SX_NONE),
};
const sx_layout sxap_lingvo_stream_header = {UINT32_C(0x60720009),"lingvo_stream_header",sxap_lingvo_stream_header_fields,SX_COUNT(sxap_lingvo_stream_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_lingvo_code_length_fields[] = {
 SX_FIELD("code_bits","uint8",0,1,SX_NONE),
};
const sx_layout sxap_lingvo_code_length = {UINT32_C(0x6072000a),"lingvo_code_length",sxap_lingvo_code_length_fields,SX_COUNT(sxap_lingvo_code_length_fields),SX_LE};
static bool sxap_lingvo(sx_context*c){uint8_t h[26];if(!sxap_read(c,0,h,18))return false;if(!xx_rt_memcmp(h,"LingvoArch",10))return sxap_add(c,&sxap_lingvo_stream_header,0)&&sxap_table(c,&sxap_lingvo_code_length,26,1,321);uint64_t count=sxap_uint(h+16,2,false),is2=h[9]=='2',width=is2?109:54,names=is2?101:46,desc=is2?71:23,p=18;if(!sxap_add(c,&sxap_lingvo_header,0)||!sxap_table(c,is2?&sxap_lingvo_index_v2:&sxap_lingvo_index_v1,p,width,count))return false;for(uint64_t i=0;i<count;i++){uint64_t q,z,method;if(!sxap_word(c,p+i*width+names,4,false,&q)||!sxap_add(c,is2?&sxap_lingvo_member_v2:&sxap_lingvo_member_v1,q)||!sxap_word(c,q+desc-10,4,false,&z)||!sxap_word(c,q+desc-2,2,false,&method))return false;q+=desc;if((method==0||method==6)&&z>=17&&sxap_span(c,q,z)&&sxap_read(c,q,h,9)&&!xx_rt_memcmp(h,"FINEAR\xdd\x88\xdd",9)&&!sxap_add(c,&sxap_finear_header,q))return false;}return true;}
bool sx_lingvoarc_build(sx_context*c)
{
 return sxap_lingvo(c);
}
