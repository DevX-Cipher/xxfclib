/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NID data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_nid_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint16",2,2,SX_NONE),
 SX_FIELD("checksum","uint16",4,2,SX_CHECKSUM),
 SX_FIELD("member_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8[112]",8,112,SX_NONE),
};
const sx_layout sxat_nid_header = {UINT32_C(0x60640008),"nid_header",sxat_nid_header_fields,SX_COUNT(sxat_nid_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_nid_member_fields[] = {
 SX_FIELD("method","uint8",0,1,SX_NONE),
 SX_FIELD("payload_offset1","int32",1,4,SX_OFFSET),
 SX_FIELD("folder_key","uint32",5,4,SX_NONE),
 SX_FIELD("name","char[11]",9,11,SX_NONE),
 SX_FIELD("attributes","uint8",20,1,SX_FLAGS),
 SX_FIELD("dos_time","uint16",21,2,SX_NONE),
 SX_FIELD("dos_date","uint16",23,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",25,4,SX_SIZE),
};
const sx_layout sxat_nid_member = {UINT32_C(0x60640009),"nid_member",sxat_nid_member_fields,SX_COUNT(sxat_nid_member_fields),SX_LE};
static const xx_data_struct_field_desc sxat_nid_block_fields[] = {
 SX_FIELD("opaque","uint8",0,1,SX_NONE),
 SX_FIELD("flags","uint16",1,2,SX_FLAGS),
 SX_FIELD("compressed_size","uint16",3,2,SX_SIZE),
};
const sx_layout sxat_nid_block = {UINT32_C(0x6064000a),"nid_block",sxat_nid_block_fields,SX_COUNT(sxat_nid_block_fields),SX_LE};
static bool sxat_nid(sx_context*c){uint64_t n,work=0;if(!sxat_word(c,6,2,false,&n)||!sxat_add(c,&sxat_nid_header,0)||!sxat_table(c,&sxat_nid_member,120,29,n))return false;for(uint64_t i=0;i<n&&c->count<SXAT_LIMIT;i++){uint8_t h[29];if(!sxat_read(c,120+29*i,h,29))return false;if(h[0]!=1)continue;uint64_t p=sxat_uint(h+1,4,false);if(!p||p>INT32_MAX)continue;p--;while(sxat_span(c,p,5)){if(++work>100000)return true;uint8_t b[5];if(!sxat_read(c,p,b,5)||!sxat_add(c,&sxat_nid_block,p))break;uint64_t z=sxat_uint(b+3,2,false);p+=5;if(!sxat_span(c,p,z))break;p+=z;if(sxat_uint(b+1,2,false)&0x100)break;}}return true;}
bool sx_nid_build(sx_context*c)
{
 return sxat_nid(c);
}
