/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * QUALITAS data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_qualitas_header_fields[] = {
 SX_FIELD("opaque1","uint8[4]",0,4,SX_NONE),
 SX_FIELD("header_size","uint16",4,2,SX_SIZE),
 SX_FIELD("directory_size","uint16",6,2,SX_SIZE),
 SX_FIELD("opaque2","uint8[2]",8,2,SX_NONE),
 SX_FIELD("member_count","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("opaque3","uint8[2]",12,2,SX_NONE),
};
const sx_layout sxacl_qualitas_header = {UINT32_C(0x60500015),"qualitas_header",sxacl_qualitas_header_fields,SX_COUNT(sxacl_qualitas_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_qualitas_member_fields[] = {
 SX_FIELD("next_record_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("unused","uint8[2]",4,2,SX_NONE),
 SX_FIELD("payload_offset","int32",6,4,SX_OFFSET),
 SX_FIELD("dos_time","uint16",10,2,SX_NONE),
 SX_FIELD("dos_date","uint16",12,2,SX_NONE),
 SX_FIELD("uncompressed_size","int32",14,4,SX_SIZE),
 SX_FIELD("block_size","int32",18,4,SX_SIZE),
 SX_FIELD("attributes","uint16",22,2,SX_NONE),
 SX_FIELD("disk_number","uint8",24,1,SX_NONE),
 SX_FIELD("method","uint8",25,1,SX_NONE),
};
const sx_layout sxacl_qualitas_member = {UINT32_C(0x60500016),"qualitas_member",sxacl_qualitas_member_fields,SX_COUNT(sxacl_qualitas_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_qualitas_crc32_fields[] = {
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxacl_qualitas_crc32 = {UINT32_C(0x60500017),"qualitas_crc32",sxacl_qualitas_crc32_fields,SX_COUNT(sxacl_qualitas_crc32_fields),SX_LE};
static bool sxacl_zstr(sx_context*c,uint64_t*p,uint64_t end,unsigned cap){for(unsigned i=0;i<cap&&*p<end;i++){uint8_t b;if(!sxacl_read(c,(*p)++,&b,1))return false;if(!b)return true;}return false;}
static bool sxacl_qualitas(sx_context*c){uint64_t z,n,p=14;if(!sxacl_word(c,6,2,false,&z)||!sxacl_word(c,10,2,false,&n)||!sxacl_span(c,p,z)||!sxacl_add(c,&sxacl_qualitas_header,0))return false;uint64_t end=p+z;for(uint64_t i=0;i<n;i++){uint8_t h[26];if(p>end||end-p<26||!sxacl_read(c,p,h,26)||!sxacl_add(c,&sxacl_qualitas_member,p))return false;uint64_t next=sxacl_uint(h,4,false),data=sxacl_uint(h+6,4,false),packed=sxacl_uint(h+18,4,false),q=p+26;if(!sxacl_zstr(c,&q,end,256)||next!=q)return false;if(h[24]==1&&h[25]<=1&&data>=end&&packed>=4&&packed<=INT32_MAX&&sxacl_span(c,data,packed)){if(!sxacl_add(c,&sxacl_qualitas_crc32,data)||!sxacl_dcl(c,data+4,packed-4))return false;}p=q;}return true;}
bool sx_qualitas_build(sx_context*c)
{
 return sxacl_qualitas(c);
}
