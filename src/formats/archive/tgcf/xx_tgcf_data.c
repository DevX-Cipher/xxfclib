/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TGCF data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_tgcf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("opaque1","uint8[2]",4,2,SX_NONE),
 SX_FIELD("version","uint16",6,2,SX_NONE),
 SX_FIELD("opaque2","uint8[18]",8,18,SX_NONE),
 SX_FIELD("volume_name_size","uint16",26,2,SX_SIZE),
};
const sx_layout sxasy_tgcf_header = {UINT32_C(0x6044002c),"tgcf_header",sxasy_tgcf_header_fields,SX_COUNT(sxasy_tgcf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxasy_tgcf_list_offset_fields[] = {
 SX_FIELD("member_list_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxasy_tgcf_list_offset = {UINT32_C(0x6044002d),"tgcf_list_offset",sxasy_tgcf_list_offset_fields,SX_COUNT(sxasy_tgcf_list_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxasy_tgcf_crc_fields[] = {
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxasy_tgcf_crc = {UINT32_C(0x6044002e),"tgcf_crc",sxasy_tgcf_crc_fields,SX_COUNT(sxasy_tgcf_crc_fields),SX_BE};
static const xx_data_struct_field_desc sxasy_tgcf_member_prefix_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("opaque","uint8[8]",4,8,SX_NONE),
 SX_FIELD("split_kind","uint16",12,2,SX_NONE),
 SX_FIELD("method","uint16",14,2,SX_NONE),
};
const sx_layout sxasy_tgcf_member_prefix = {UINT32_C(0x6044002f),"tgcf_member_prefix",sxasy_tgcf_member_prefix_fields,SX_COUNT(sxasy_tgcf_member_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_tgcf_member_attributes_fields[] = {
 SX_FIELD("timestamp","uint32",0,4,SX_NONE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("attributes","uint32",16,4,SX_NONE),
};
const sx_layout sxasy_tgcf_member_attributes = {UINT32_C(0x60440030),"tgcf_member_attributes",sxasy_tgcf_member_attributes_fields,SX_COUNT(sxasy_tgcf_member_attributes_fields),SX_BE};
static const xx_data_struct_field_desc sxasy_tgcf_member_flag_fields[] = {
 SX_FIELD("flag","uint8",0,1,SX_NONE),
};
const sx_layout sxasy_tgcf_member_flag = {UINT32_C(0x60440031),"tgcf_member_flag",sxasy_tgcf_member_flag_fields,SX_COUNT(sxasy_tgcf_member_flag_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_tgcf_payload_offset_fields[] = {
 SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxasy_tgcf_payload_offset = {UINT32_C(0x60440032),"tgcf_payload_offset",sxasy_tgcf_payload_offset_fields,SX_COUNT(sxasy_tgcf_payload_offset_fields),SX_BE};
static bool sxasy_tgcf(sx_context*c){uint64_t version,n,p;if(!sxasy_word(c,6,2,true,&version)||!sxasy_word(c,26,2,true,&n)||n>1024||!sxasy_span(c,28,n)||!sxasy_add(c,&sxasy_tgcf_header,0))return false;p=28+n;if(version>=0x160){uint64_t list;if(!sxasy_word(c,p,4,true,&list)||!sxasy_add(c,&sxasy_tgcf_list_offset,p)||!sxasy_add(c,&sxasy_tgcf_crc,p+4))return false;p=list;}else{if(!sxasy_add(c,&sxasy_tgcf_crc,p))return false;p+=4;}for(unsigned i=0;i<SXASY_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[36];if(!sxasy_read(c,p,h,36)||xx_rt_memcmp(h,"TGCF",4))return false;uint64_t z=sxasy_uint(h+20,4,true),q=p+36;if(!sxasy_zstr(c,&q,(uint64_t)c->size,1024)||!sxasy_zstr(c,&q,(uint64_t)c->size,1024)||!sxasy_span(c,q,version>=0x160?9:5)||!sxasy_add(c,&sxasy_tgcf_member_prefix,p)||!sxasy_add(c,&sxasy_tgcf_member_attributes,p+16)||!sxasy_add(c,&sxasy_tgcf_member_flag,q))return false;q++;if(version>=0x160){uint64_t data;if(!sxasy_word(c,q,4,true,&data)||!sxasy_span(c,data,z)||!sxasy_add(c,&sxasy_tgcf_payload_offset,q))return false;q+=4;}if(!sxasy_add(c,&sxasy_tgcf_crc,q))return false;q+=4;if(version<0x160){if(!sxasy_span(c,q,z))return false;q+=z;}p=q;}return true;}
bool sx_tgcf_build(sx_context*c)
{
 return sxasy_tgcf(c);
}
