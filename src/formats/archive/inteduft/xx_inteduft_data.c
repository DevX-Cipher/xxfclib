/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * InterEdu FT data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_inteduft_header_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",4,2,SX_COUNT_PROP),
};
const sx_layout sxasy_inteduft_header = {UINT32_C(0x60440016),"inteduft_header",sxasy_inteduft_header_fields,SX_COUNT(sxasy_inteduft_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_inteduft_index_fields[] = {
 SX_FIELD("member_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("name_size","uint8",4,1,SX_SIZE),
};
const sx_layout sxasy_inteduft_index = {UINT32_C(0x60440017),"inteduft_index",sxasy_inteduft_index_fields,SX_COUNT(sxasy_inteduft_index_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_inteduft_member_fields[] = {
 SX_FIELD("reserved_flags","uint16",0,2,SX_NONE),
 SX_FIELD("method","uint16",2,2,SX_NONE),
 SX_FIELD("crc32","uint32",4,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","int32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_size","int32",12,4,SX_SIZE),
};
const sx_layout sxasy_inteduft_member = {UINT32_C(0x60440018),"inteduft_member",sxasy_inteduft_member_fields,SX_COUNT(sxasy_inteduft_member_fields),SX_LE};
static bool sxasy_intedu(sx_context*c){uint64_t n,p=6;if(!sxasy_word(c,4,2,false,&n)||!sxasy_add(c,&sxasy_inteduft_header,0))return false;for(uint64_t i=0;i<n;i++){uint8_t h[5];if(!sxasy_read(c,p,h,5)||!sxasy_span(c,p+5,h[4])||!sxasy_add(c,&sxasy_inteduft_index,p))return false;p+=5+h[4];}uint64_t end=p;p=6;for(uint64_t i=0;i<n;i++){uint8_t h[16],idx[5];if(!sxasy_read(c,p,idx,5))return false;uint64_t q=sxasy_uint(idx,4,false);if(q<end||q>INT32_MAX||!sxasy_read(c,q,h,16)||!sxasy_span(c,q+16,sxasy_uint(h+8,4,false))||!sxasy_add(c,&sxasy_inteduft_member,q))return false;p+=5+idx[4];}return true;}
bool sx_inteduft_build(sx_context*c)
{
 return sxasy_intedu(c);
}
