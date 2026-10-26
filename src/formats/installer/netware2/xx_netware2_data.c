/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NetWare 2 data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_netware2_record_fields[] = {
 SX_FIELD("record_size","uint32",0,4,SX_SIZE),
 SX_FIELD("name_count","uint8",4,1,SX_NONE),
};
const sx_layout sxasy_netware2_record = {UINT32_C(0x60440035),"netware2_record",sxasy_netware2_record_fields,SX_COUNT(sxasy_netware2_record_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_netware2_metadata_fields[] = {
 SX_FIELD("subtag","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("flags","uint8",1,1,SX_NONE),
 SX_FIELD("date_text","char[8]",2,8,SX_NONE),
 SX_FIELD("time_text","char[8]",10,8,SX_NONE),
 SX_FIELD("attribute_identifier_text","char[34]",18,34,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",52,4,SX_SIZE),
 SX_FIELD("unidentified_stamp","uint32",56,4,SX_NONE),
 SX_FIELD("name_size","uint8",60,1,SX_SIZE),
};
const sx_layout sxasy_netware2_metadata = {UINT32_C(0x60440036),"netware2_metadata",sxasy_netware2_metadata_fields,SX_COUNT(sxasy_netware2_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_netware2_packed_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_NONE),
 SX_FIELD("method","uint8",1,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",2,4,SX_SIZE),
};
const sx_layout sxasy_netware2_packed = {UINT32_C(0x60440037),"netware2_packed",sxasy_netware2_packed_fields,SX_COUNT(sxasy_netware2_packed_fields),SX_LE};
static bool sxasy_netware2(sx_context*c){uint64_t p=0;for(unsigned i=0;i<256&&p<(uint64_t)c->size;i++){uint8_t h[69];if(!sxasy_read(c,p,h,5))return false;uint64_t z=sxasy_uint(h,4,false),n=h[4];if(!n||n>65||z<4+n||!sxasy_span(c,p,z)||!sxasy_read(c,p+5,h,(size_t)n-1)||!sxasy_add(c,&sxasy_netware2_record,p))return false;uint64_t q=p+4+n,left=z-4-n;if(n==12&&!xx_rt_memcmp(h,"NetWareFile",11)){if(left<61||!sxasy_add(c,&sxasy_netware2_metadata,q))return false;}else if(n==11&&!xx_rt_memcmp(h,"PackedData",10)){if(left<6||!sxasy_add(c,&sxasy_netware2_packed,q))return false;}p+=z;}return true;}
bool sx_netware2_build(sx_context*c)
{
 return sxasy_netware2(c);
}
