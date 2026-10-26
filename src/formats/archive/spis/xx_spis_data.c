/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SPIS data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_spis_header_fields[] = {
 SX_FIELD("signature","uint8[5]",0,5,SX_SIGNATURE),
 SX_FIELD("method_tag","char[3]",5,3,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("archive_type","uint8",12,1,SX_NONE),
 SX_FIELD("checksum","uint32",13,4,SX_CHECKSUM),
 SX_FIELD("flags","uint32",17,4,SX_NONE),
};
const sx_layout sxacl_spis_header = {UINT32_C(0x6050001f),"spis_header",sxacl_spis_header_fields,SX_COUNT(sxacl_spis_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_spis_member_fields[] = {
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
 SX_FIELD("dos_timestamp","uint32",2,4,SX_NONE),
 SX_FIELD("attributes","uint16",6,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("method","uint8",16,1,SX_NONE),
 SX_FIELD("checksum","uint32",17,4,SX_CHECKSUM),
 SX_FIELD("flags","uint32",21,4,SX_NONE),
};
const sx_layout sxacl_spis_member = {UINT32_C(0x60500020),"spis_member",sxacl_spis_member_fields,SX_COUNT(sxacl_spis_member_fields),SX_LE};
#define SXACL_LIMIT 20000U
static bool sxacl_spis(sx_context*c){uint64_t p=0;bool members=false;for(unsigned i=0;i<SXACL_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[25];if(!sxacl_read(c,p,h,5))return false;if(!xx_rt_memcmp(h,"SPIS\032",5)){if(!sxacl_read(c,p,h,21)||!sxacl_add(c,&sxacl_spis_header,p))return false;members=h[12]==1;p+=21;if(!members)return true;}else{if(!members||!sxacl_read(c,p,h,25))return false;uint64_t n=sxacl_uint(h,2,false),z=sxacl_uint(h+12,4,false);if(!n||n>4096||!sxacl_span(c,p+25,n)||!sxacl_span(c,p+25+n,z)||!sxacl_add(c,&sxacl_spis_member,p))return false;p+=25+n+z;}}return true;}
bool sx_spis_build(sx_context*c)
{
 return sxacl_spis(c);
}
