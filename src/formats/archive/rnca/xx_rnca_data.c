/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RNCA data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_rnca_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("first_member_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("directory_checkword","uint16",6,2,SX_SIGNATURE),
 SX_FIELD("first_member_offset_copy","uint16",8,2,SX_OFFSET),
 SX_FIELD("reserved","uint8",10,1,SX_NONE),
};
const sx_layout sxaf_rnca_header = {UINT32_C(0x603c0012),"rnca_header",sxaf_rnca_header_fields,SX_COUNT(sxaf_rnca_header_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_rnca_directory_offset_fields[] = {
 SX_FIELD("member_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxaf_rnca_directory_offset = {UINT32_C(0x603c0013),"rnca_directory_offset",sxaf_rnca_directory_offset_fields,SX_COUNT(sxaf_rnca_directory_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_rnca_stored_member_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("method","uint8",3,1,SX_NONE),
 SX_FIELD("stored_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxaf_rnca_stored_member = {UINT32_C(0x603c0014),"rnca_stored_member",sxaf_rnca_stored_member_fields,SX_COUNT(sxaf_rnca_stored_member_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_rnca_compressed_member_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("method","uint8",3,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_crc16","uint16",12,2,SX_CHECKSUM),
 SX_FIELD("compressed_crc16","uint16",14,2,SX_CHECKSUM),
 SX_FIELD("leeway","uint8",16,1,SX_NONE),
 SX_FIELD("chunk_count","uint8",17,1,SX_COUNT_PROP),
};
const sx_layout sxaf_rnca_compressed_member = {UINT32_C(0x603c0015),"rnca_compressed_member",sxaf_rnca_compressed_member_fields,SX_COUNT(sxaf_rnca_compressed_member_fields),SX_BE};
static bool sxaf_rnca(sx_context*c){uint64_t end,p=11;if(!sxaf_word(c,4,2,true,&end)||end<12||!sxaf_span(c,0,end)||!sxaf_add(c,&sxaf_rnca_header,0))return false;while(p<end){uint8_t b;if(!sxaf_read(c,p,&b,1))return false;if(!b)break;if(!sxaf_zstr(c,&p,end,256,0)||end-p<4)return false;uint64_t off;if(!sxaf_word(c,p,4,true,&off)||!sxaf_add(c,&sxaf_rnca_directory_offset,p))return false;p+=4;uint8_t h[4];if(sxaf_read(c,off,h,4)&&!xx_rt_memcmp(h,"RNC",3)){const sx_layout*l=h[3]?&sxaf_rnca_compressed_member:&sxaf_rnca_stored_member;if(!sxaf_add(c,l,off))return false;}}return true;}
bool sx_rnca_build(sx_context*c)
{
 return sxaf_rnca(c);
}
