/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GENIUS data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_genius_header_fields[] = {
 SX_FIELD("signature","char[14]",0,14,SX_SIGNATURE),
 SX_FIELD("terminator","uint8",14,1,SX_NONE),
 SX_FIELD("unused","uint8",15,1,SX_NONE),
 SX_FIELD("reserved","uint16",16,2,SX_NONE),
 SX_FIELD("uninitialized","uint8[2]",18,2,SX_NONE),
 SX_FIELD("member_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("opaque","uint8[8]",24,8,SX_NONE),
};
const sx_layout sxacl_genius_header = {UINT32_C(0x6050002e),"genius_header",sxacl_genius_header_fields,SX_COUNT(sxacl_genius_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_genius_member_fields[] = {
 SX_FIELD("payload_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("compressed_size","uint64",8,8,SX_SIZE),
 SX_FIELD("uncompressed_size","uint64",16,8,SX_SIZE),
 SX_FIELD("opaque1","uint8[16]",24,16,SX_NONE),
 SX_FIELD("write_time","uint64",40,8,SX_NONE),
 SX_FIELD("opaque2","uint8[3]",48,3,SX_NONE),
 SX_FIELD("method","uint8",51,1,SX_NONE),
 SX_FIELD("name_size","uint16",52,2,SX_SIZE),
};
const sx_layout sxacl_genius_member = {UINT32_C(0x6050002f),"genius_member",sxacl_genius_member_fields,SX_COUNT(sxacl_genius_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_genius_block_size_fields[] = {
 SX_FIELD("compressed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxacl_genius_block_size = {UINT32_C(0x60500030),"genius_block_size",sxacl_genius_block_size_fields,SX_COUNT(sxacl_genius_block_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_genius_footer_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("crc32","uint32",4,4,SX_CHECKSUM),
};
const sx_layout sxacl_genius_footer = {UINT32_C(0x60500031),"genius_footer",sxacl_genius_footer_fields,SX_COUNT(sxacl_genius_footer_fields),SX_LE};
static bool sxacl_genius(sx_context*c){uint64_t n,p=32;if(!sxacl_word(c,20,4,false,&n)||!sxacl_add(c,&sxacl_genius_header,0))return false;for(uint64_t i=0;i<n;i++){uint8_t h[54];if(!sxacl_read(c,p,h,54))return false;uint64_t z=sxacl_uint(h+8,8,false),names=sxacl_uint(h+52,2,false),q=p+54+names;if(!sxacl_span(c,p+54,names)||!sxacl_span(c,q,z)||!sxacl_add(c,&sxacl_genius_member,p))return false;if(h[51]==1&&z>=8){uint64_t cursor=q,end=q+z-8;while(cursor<end){uint64_t k;if(end-cursor<4||!sxacl_word(c,cursor,4,false,&k)||k>end-cursor-4)break;if(!sxacl_add(c,&sxacl_genius_block_size,cursor)||!sxacl_dcl(c,cursor+4,k))return false;cursor+=4+k;}if(!sxacl_add(c,&sxacl_genius_footer,end))return false;}p=q+z;}return true;}
bool sx_genius_build(sx_context*c)
{
 return sxacl_genius(c);
}
