/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RED data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_red_member_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint8",2,1,SX_NONE),
 SX_FIELD("header_size","uint8",3,1,SX_SIZE),
 SX_FIELD("dos_time","uint16",4,2,SX_NONE),
 SX_FIELD("dos_date","uint16",6,2,SX_NONE),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("crc1","uint16",16,2,SX_CHECKSUM),
 SX_FIELD("crc2","uint16",18,2,SX_CHECKSUM),
 SX_FIELD("fragment_number","uint16",20,2,SX_NONE),
 SX_FIELD("last_fragment","uint16",22,2,SX_NONE),
 SX_FIELD("method","uint16",24,2,SX_NONE),
};
const sx_layout sxao_red_member = {UINT32_C(0x60700036),"red_member",sxao_red_member_fields,SX_COUNT(sxao_red_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_red_header_crc_fields[] = {
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
const sx_layout sxao_red_header_crc = {UINT32_C(0x60700037),"red_header_crc",sxao_red_header_crc_fields,SX_COUNT(sxao_red_header_crc_fields),SX_BE};
static const xx_data_struct_field_desc sxao_red_segment_crc_fields[] = {
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
const sx_layout sxao_red_segment_crc = {UINT32_C(0x60700038),"red_segment_crc",sxao_red_segment_crc_fields,SX_COUNT(sxao_red_segment_crc_fields),SX_BE};
static bool sxao_red(sx_context*c){uint64_t p=0;while(sxao_span(c,p,39)){uint8_t h[26];if(!sxao_read(c,p,h,26))return false;uint64_t hs=h[3],z=sxao_uint(h+8,4,false),method=sxao_uint(h+24,2,false);if(hs<39||!sxao_span(c,p,hs)||!sxao_add(c,&sxao_red_member,p)||!sxao_text(c,&sxao_archiveobsolete_name,p+26,12,true)||!sxao_put(c,&sxao_red_header_crc,p+hs-2,2,true))return false;p+=hs;if(!sxao_span(c,p,z))return true;if(method==11){uint64_t q=p,remain=z;while(remain){uint64_t block=remain>4096?4096:remain;if(block>=2&&!sxao_add(c,&sxao_red_segment_crc,q+block-2))return false;q+=block;remain-=block;}}p+=z;}return true;}
bool sx_red_build(sx_context*c)
{
 return sxao_red(c);
}
