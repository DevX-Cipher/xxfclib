/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * hadoop_sequencefile data structures, moved out of the databases schema family. */
#include "../../xx_format_schema_databases.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxd_sequence_header_fields[] = {
    SX_FIELD("magic", "char[3]", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 3, 1, SX_ID),
};
const sx_layout sxd_sequence_header = {UINT32_C(0x601A0001),"sequence_header",sxd_sequence_header_fields,SX_COUNT(sxd_sequence_header_fields),SX_LE};
static const xx_data_struct_field_desc sxd_sequence_sync_fields[] = {
    SX_FIELD("sync_marker", "uint8[16]", 0, 16, SX_SIGNATURE),
};
const sx_layout sxd_sequence_sync = {UINT32_C(0x601A0003),"sequence_sync",sxd_sequence_sync_fields,SX_COUNT(sxd_sequence_sync_fields),SX_LE};
static const xx_data_struct_field_desc sxd_sequence_sync_record_fields[] = {
    SX_FIELD("sync_escape", "int32", 0, 4, SX_SIGNATURE),
    SX_FIELD("sync_marker", "uint8[16]", 4, 16, SX_SIGNATURE),
};
const sx_layout sxd_sequence_sync_record = {UINT32_C(0x601A0004),"sequence_sync_record",sxd_sequence_sync_record_fields,SX_COUNT(sxd_sequence_sync_record_fields),SX_BE};
static const xx_data_struct_field_desc sxd_sequence_record_fields[] = {
    SX_FIELD("record_length", "int32", 0, 4, SX_SIZE),
    SX_FIELD("key_length", "int32", 4, 4, SX_SIZE),
};
const sx_layout sxd_sequence_record = {UINT32_C(0x601A0005),"sequence_record",sxd_sequence_record_fields,SX_COUNT(sxd_sequence_record_fields),SX_BE};
static const xx_data_struct_field_desc sxd_sequence_text_length_0_fields[] = {
    SX_FIELD("length", "uint8", 0, 1, SX_SIZE),
};
const sx_layout sxd_sequence_text_length_0 = {UINT32_C(0x601A0006),"sequence_text_length_0",sxd_sequence_text_length_0_fields,SX_COUNT(sxd_sequence_text_length_0_fields),SX_LE};
static const xx_data_struct_field_desc sxd_sequence_text_length_1_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint8be", 1, 1, SX_NONE),
};
const sx_layout sxd_sequence_text_length_1 = {UINT32_C(0x601A0007),"sequence_text_length_1",sxd_sequence_text_length_1_fields,SX_COUNT(sxd_sequence_text_length_1_fields),SX_LE};
static const xx_data_struct_field_desc sxd_sequence_text_length_2_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint16be", 1, 2, SX_NONE),
};
const sx_layout sxd_sequence_text_length_2 = {UINT32_C(0x601A0008),"sequence_text_length_2",sxd_sequence_text_length_2_fields,SX_COUNT(sxd_sequence_text_length_2_fields),SX_LE};
static const xx_data_struct_field_desc sxd_sequence_text_length_3_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint24be", 1, 3, SX_NONE),
};
const sx_layout sxd_sequence_text_length_3 = {UINT32_C(0x601A0009),"sequence_text_length_3",sxd_sequence_text_length_3_fields,SX_COUNT(sxd_sequence_text_length_3_fields),SX_LE};
static const xx_data_struct_field_desc sxd_sequence_text_length_4_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint32be", 1, 4, SX_NONE),
};
const sx_layout sxd_sequence_text_length_4 = {UINT32_C(0x601A000A),"sequence_text_length_4",sxd_sequence_text_length_4_fields,SX_COUNT(sxd_sequence_text_length_4_fields),SX_LE};
static const xx_data_struct_field_desc sxd_sequence_text_length_5_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint40be", 1, 5, SX_NONE),
};
const sx_layout sxd_sequence_text_length_5 = {UINT32_C(0x601A000B),"sequence_text_length_5",sxd_sequence_text_length_5_fields,SX_COUNT(sxd_sequence_text_length_5_fields),SX_LE};
static const xx_data_struct_field_desc sxd_sequence_text_length_6_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint48be", 1, 6, SX_NONE),
};
const sx_layout sxd_sequence_text_length_6 = {UINT32_C(0x601A000C),"sequence_text_length_6",sxd_sequence_text_length_6_fields,SX_COUNT(sxd_sequence_text_length_6_fields),SX_LE};
static const xx_data_struct_field_desc sxd_sequence_text_length_7_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint56be", 1, 7, SX_NONE),
};
const sx_layout sxd_sequence_text_length_7 = {UINT32_C(0x601A000D),"sequence_text_length_7",sxd_sequence_text_length_7_fields,SX_COUNT(sxd_sequence_text_length_7_fields),SX_LE};
static const xx_data_struct_field_desc sxd_sequence_text_length_8_fields[] = {
    SX_FIELD("marker", "int8", 0, 1, SX_NONE),
    SX_FIELD("encoded_magnitude", "uint64be", 1, 8, SX_NONE),
};
const sx_layout sxd_sequence_text_length_8 = {UINT32_C(0x601A000E),"sequence_text_length_8",sxd_sequence_text_length_8_fields,SX_COUNT(sxd_sequence_text_length_8_fields),SX_LE};
static const sx_layout *const sxd_sequence_text_length_rows[] = {&sxd_sequence_text_length_0,&sxd_sequence_text_length_1,&sxd_sequence_text_length_2,&sxd_sequence_text_length_3,&sxd_sequence_text_length_4,&sxd_sequence_text_length_5,&sxd_sequence_text_length_6,&sxd_sequence_text_length_7,&sxd_sequence_text_length_8};
static bool sxd_sequence_text(sx_context *c,const uint8_t *b,uint64_t *at)
{
    if(!sxd_can(c,*at,1))return false;uint64_t start=*at,n=0;int marker=(int)(int8_t)b[(*at)++];unsigned width=marker>=-112?0:(unsigned)(marker<-120?-120-marker:-112-marker);
    if(width>8||!sxd_can(c,*at,width))return false;
    if(!width){if(marker<0)return false;n=(unsigned)marker;}else{for(unsigned i=0;i<width;i++)n=(n<<8)|b[(*at)++];if(marker<-120)n=~n;}
    if(n>65536||!sxd_can(c,*at,n)||!sxd_add(c,sxd_sequence_text_length_rows[width],start,width+1))return false;*at+=n;return true;
}
static bool sxd_sequence(sx_context *c,const uint8_t *b)
{
    uint64_t at=4;if(!sxd_add(c,&sxd_sequence_header,0,4)||!sxd_sequence_text(c,b,&at)||!sxd_sequence_text(c,b,&at)||!sxd_can(c,at,6))return false;
    uint32_t n=sxd_be32(b+at+2);if(n>4094||b[at]||b[at+1]||!sxd_add(c,&sxd_sequence_options,at,6))return false;at+=6;
    for(uint32_t i=0;i<n;i++)if(!sxd_sequence_text(c,b,&at)||!sxd_sequence_text(c,b,&at))return false;
    if(!sxd_add(c,&sxd_sequence_sync,at,16))return false;at+=16;
    while(at<(uint64_t)c->size){if(!sxd_can(c,at,4))return false;if(sxd_be32(b+at)==UINT32_MAX){if(!sxd_add(c,&sxd_sequence_sync_record,at,20))return false;at+=20;if(at==(uint64_t)c->size)break;}
        if(!sxd_can(c,at,8))return false;uint32_t n=sxd_be32(b+at),k=sxd_be32(b+at+4);if(k>n||!sxd_add(c,&sxd_sequence_record,at,8)||!sxd_can(c,at+8,n))return false;at+=8+n;
    }return true;
}
bool sx_hadoop_sequencefile_build(sx_context *c,uint8_t *b)
{
 return sxd_sequence(c,b);
}
