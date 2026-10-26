/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Quarterdeck QP data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_qp_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("index_size","uint32",4,4,SX_SIZE),
 SX_FIELD("version","uint16",8,2,SX_NONE),
 SX_FIELD("reserved","uint8[6]",10,6,SX_NONE),
};
const sx_layout sxasy_qp_header = {UINT32_C(0x60440023),"qp_header",sxasy_qp_header_fields,SX_COUNT(sxasy_qp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_qp_index_fields[] = {
 SX_FIELD("member_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("name","char[12]",4,12,SX_NONE),
};
const sx_layout sxasy_qp_index = {UINT32_C(0x60440024),"qp_index",sxasy_qp_index_fields,SX_COUNT(sxasy_qp_index_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_qp_path_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("kind","uint16",2,2,SX_NONE),
 SX_FIELD("path_blob_size","uint32",4,4,SX_SIZE),
 SX_FIELD("sequence","uint16",8,2,SX_NONE),
 SX_FIELD("reserved","uint32",10,4,SX_NONE),
};
const sx_layout sxasy_qp_path = {UINT32_C(0x60440025),"qp_path",sxasy_qp_path_fields,SX_COUNT(sxasy_qp_path_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_qp_member_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("kind","uint16",2,2,SX_NONE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("sequence","uint16",8,2,SX_NONE),
 SX_FIELD("crc32","uint32",10,4,SX_CHECKSUM),
 SX_FIELD("attributes","uint8",14,1,SX_NONE),
 SX_FIELD("dos_time","uint16",15,2,SX_NONE),
 SX_FIELD("dos_date","uint16",17,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",19,4,SX_SIZE),
 SX_FIELD("name","char[13]",23,13,SX_NONE),
};
const sx_layout sxasy_qp_member = {UINT32_C(0x60440026),"qp_member",sxasy_qp_member_fields,SX_COUNT(sxasy_qp_member_fields),SX_LE};
static bool sxasy_qp(sx_context*c){uint64_t n,p;if(!sxasy_word(c,2,2,false,&n)||!sxasy_span(c,16,n*16)||!sxasy_add(c,&sxasy_qp_header,0))return false;for(uint64_t i=0;i<n;i++)if(!sxasy_add(c,&sxasy_qp_index,16+16*i))return false;p=16+16*n;for(unsigned i=0;i<SXASY_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[36];if(!sxasy_read(c,p,h,14)||h[0]!='Q'||h[1]!='D')return false;uint64_t kind=sxasy_uint(h+2,2,false),z=sxasy_uint(h+4,4,false),hs=kind==1?14:36;if(kind>1||!sxasy_span(c,p,hs)||!sxasy_span(c,p+hs,z)||!sxasy_add(c,kind?&sxasy_qp_path:&sxasy_qp_member,p))return false;if(!kind&&!sxasy_dcl(c,p+hs,z))return false;p+=hs+z;}return true;}
bool sx_quarterdeckqp_build(sx_context*c)
{
 return sxasy_qp(c);
}
