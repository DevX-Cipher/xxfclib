/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ISZ data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_isz_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_size","uint8",4,1,SX_SIZE),
    SX_FIELD("version","uint8",5,1,SX_NONE),
    SX_FIELD("volume_serial","uint32",6,4,SX_ID),
    SX_FIELD("sector_size","uint16",10,2,SX_SIZE),
    SX_FIELD("sector_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("encryption","uint8",16,1,SX_ID),
    SX_FIELD("volume_size","uint64",17,8,SX_SIZE),
    SX_FIELD("chunk_count","uint32",25,4,SX_COUNT_PROP),
    SX_FIELD("chunk_size","uint32",29,4,SX_SIZE),
    SX_FIELD("pointer_size","uint8",33,1,SX_SIZE),
    SX_FIELD("volume_number","uint8",34,1,SX_NONE),
    SX_FIELD("pointer_table_offset","uint32",35,4,SX_OFFSET),
    SX_FIELD("segment_table_offset","uint32",39,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",43,4,SX_OFFSET),
    SX_FIELD("reserved","uint8",47,1,SX_RESERVED),
};
const sx_layout sxsl_isz_header = {0x60330012U,"isz_header",sxsl_isz_header_fields,SX_COUNT(sxsl_isz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_isz_checksum_tail_fields[] = {
    SX_FIELD("checksum1","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("unknown","uint32",8,4,SX_NONE),
    SX_FIELD("checksum2","uint32",12,4,SX_CHECKSUM),
};
const sx_layout sxsl_isz_checksum_tail = {0x60330013U,"isz_checksum_tail",sxsl_isz_checksum_tail_fields,SX_COUNT(sxsl_isz_checksum_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_isz_encoded_pointer1_fields[] = {
    SX_FIELD("encoded_size_and_type","byte[1]",0,1,SX_NONE),
};
const sx_layout sxsl_isz_encoded_pointer1 = {0x60330014U,"isz_encoded_pointer1",sxsl_isz_encoded_pointer1_fields,SX_COUNT(sxsl_isz_encoded_pointer1_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_isz_encoded_pointer2_fields[] = {
    SX_FIELD("encoded_size_and_type","byte[2]",0,2,SX_NONE),
};
const sx_layout sxsl_isz_encoded_pointer2 = {0x60330015U,"isz_encoded_pointer2",sxsl_isz_encoded_pointer2_fields,SX_COUNT(sxsl_isz_encoded_pointer2_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_isz_encoded_pointer3_fields[] = {
    SX_FIELD("encoded_size_and_type","byte[3]",0,3,SX_NONE),
};
const sx_layout sxsl_isz_encoded_pointer3 = {0x60330016U,"isz_encoded_pointer3",sxsl_isz_encoded_pointer3_fields,SX_COUNT(sxsl_isz_encoded_pointer3_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_isz_encoded_pointer4_fields[] = {
    SX_FIELD("encoded_size_and_type","byte[4]",0,4,SX_NONE),
};
const sx_layout sxsl_isz_encoded_pointer4 = {0x60330017U,"isz_encoded_pointer4",sxsl_isz_encoded_pointer4_fields,SX_COUNT(sxsl_isz_encoded_pointer4_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_isz_encoded_segment_fields[] = {
    SX_FIELD("encoded_volume_size","byte[8]",0,8,SX_NONE),
    SX_FIELD("encoded_chunk_count","byte[4]",8,4,SX_NONE),
    SX_FIELD("encoded_first_chunk","byte[4]",12,4,SX_NONE),
    SX_FIELD("encoded_data_offset","byte[4]",16,4,SX_NONE),
    SX_FIELD("encoded_last_chunk_continuation","byte[4]",20,4,SX_NONE),
};
const sx_layout sxsl_isz_encoded_segment = {0x60330018U,"isz_encoded_segment",sxsl_isz_encoded_segment_fields,SX_COUNT(sxsl_isz_encoded_segment_fields),SX_LE};
#define SXSL_LIMIT 24000U
#define SXSL_ROWS 1048576U
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
static bool sxsl_isz(sx_context*c){uint8_t h[48],b[24];if(!sxsl_read(c,0,h,48)||!SXSL_ADD(c,isz_header,0))return false;if(h[4]>=64&&sxsl_span(c,48,16)&&!SXSL_ADD(c,isz_checksum_tail,48))return false;uint64_t p=sxsl32(h+35),n=sxsl32(h+25);unsigned w=h[33];const sx_layout*ls[]={&sxsl_isz_encoded_pointer1,&sxsl_isz_encoded_pointer2,&sxsl_isz_encoded_pointer3,&sxsl_isz_encoded_pointer4};if(p>=h[4]&&w>=1&&w<=4&&n<=SXSL_ROWS&&sxsl_span(c,p,n*w)&&!sxsl_put(c,ls[w-1],p,n))return false;p=sxsl32(h+39);if(p>=h[4])for(unsigned i=0;i<1024&&c->count<SXSL_LIMIT;i++){if(!sxsl_read(c,p,b,24))break;if(!SXSL_ADD(c,isz_encoded_segment,p))return false;for(unsigned j=0;j<24;j++)b[j]^=(uint8_t)~"IsZ!"[j%4];if(!sxsl_uint(b,8,false))break;p+=24;}return true;}
bool sx_isz_build(sx_context*c)
{
bool ok=false;
ok=sxsl_isz(c);
return ok&&sxsl_finish(c);
}
