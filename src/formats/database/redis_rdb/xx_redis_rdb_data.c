/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * redis_rdb data structures, moved out of the databases schema family. */
#include "../../xx_format_schema_databases.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxd_redis_header_fields[] = {
    SX_FIELD("magic", "char[5]", 0, 5, SX_SIGNATURE),
    SX_FIELD("version", "char[4]", 5, 4, SX_ID),
};
const sx_layout sxd_redis_header = {UINT32_C(0x601A0028),"redis_header",sxd_redis_header_fields,SX_COUNT(sxd_redis_header_fields),SX_LE};
static const xx_data_struct_field_desc sxd_redis_expire_milliseconds_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("expire_time_ms", "int64", 1, 8, SX_TIME),
};
const sx_layout sxd_redis_expire_milliseconds = {UINT32_C(0x601A002B),"redis_expire_milliseconds",sxd_redis_expire_milliseconds_fields,SX_COUNT(sxd_redis_expire_milliseconds_fields),SX_LE};
static const xx_data_struct_field_desc sxd_redis_expire_seconds_fields[] = {
    SX_FIELD("opcode", "uint8", 0, 1, SX_ID),
    SX_FIELD("expire_time_seconds", "int32", 1, 4, SX_TIME),
};
const sx_layout sxd_redis_expire_seconds = {UINT32_C(0x601A002C),"redis_expire_seconds",sxd_redis_expire_seconds_fields,SX_COUNT(sxd_redis_expire_seconds_fields),SX_LE};
static const xx_data_struct_field_desc sxd_redis_length_6_fields[] = {
    SX_FIELD("encoding_and_length", "uint8", 0, 1, SX_NONE),
};
const sx_layout sxd_redis_length_6 = {UINT32_C(0x601A002E),"redis_length_6",sxd_redis_length_6_fields,SX_COUNT(sxd_redis_length_6_fields),SX_LE};
static const xx_data_struct_field_desc sxd_redis_length_14_fields[] = {
    SX_FIELD("encoding_and_length_high", "uint8", 0, 1, SX_NONE),
    SX_FIELD("length_low", "uint8", 1, 1, SX_NONE),
};
const sx_layout sxd_redis_length_14 = {UINT32_C(0x601A002F),"redis_length_14",sxd_redis_length_14_fields,SX_COUNT(sxd_redis_length_14_fields),SX_LE};
static const xx_data_struct_field_desc sxd_redis_length_32_fields[] = {
    SX_FIELD("encoding", "uint8", 0, 1, SX_NONE),
    SX_FIELD("encoded_length", "uint32", 1, 4, SX_NONE),
};
const sx_layout sxd_redis_length_32 = {UINT32_C(0x601A0030),"redis_length_32",sxd_redis_length_32_fields,SX_COUNT(sxd_redis_length_32_fields),SX_BE};
static const xx_data_struct_field_desc sxd_redis_length_64_fields[] = {
    SX_FIELD("encoding", "uint8", 0, 1, SX_NONE),
    SX_FIELD("encoded_length", "uint64", 1, 8, SX_NONE),
};
const sx_layout sxd_redis_length_64 = {UINT32_C(0x601A0031),"redis_length_64",sxd_redis_length_64_fields,SX_COUNT(sxd_redis_length_64_fields),SX_BE};
static const xx_data_struct_field_desc sxd_redis_encoded_string_fields[] = {
    SX_FIELD("encoding_and_integer_type", "uint8", 0, 1, SX_ID),
};
const sx_layout sxd_redis_encoded_string = {UINT32_C(0x601A0032),"redis_encoded_string",sxd_redis_encoded_string_fields,SX_COUNT(sxd_redis_encoded_string_fields),SX_LE};
static const xx_data_struct_field_desc sxd_redis_integer_1_fields[] = {
    SX_FIELD("signed_integer", "int8", 0, 1, SX_NONE),
};
const sx_layout sxd_redis_integer_1 = {UINT32_C(0x601A0033),"redis_integer_1",sxd_redis_integer_1_fields,SX_COUNT(sxd_redis_integer_1_fields),SX_LE};
static const xx_data_struct_field_desc sxd_redis_integer_2_fields[] = {
    SX_FIELD("signed_integer", "int16", 0, 2, SX_NONE),
};
const sx_layout sxd_redis_integer_2 = {UINT32_C(0x601A0034),"redis_integer_2",sxd_redis_integer_2_fields,SX_COUNT(sxd_redis_integer_2_fields),SX_LE};
static const xx_data_struct_field_desc sxd_redis_integer_4_fields[] = {
    SX_FIELD("signed_integer", "int32", 0, 4, SX_NONE),
};
const sx_layout sxd_redis_integer_4 = {UINT32_C(0x601A0035),"redis_integer_4",sxd_redis_integer_4_fields,SX_COUNT(sxd_redis_integer_4_fields),SX_LE};
static const xx_data_struct_field_desc sxd_redis_score_length_fields[] = {
    SX_FIELD("score_length_or_infinity", "uint8", 0, 1, SX_NONE),
};
const sx_layout sxd_redis_score_length = {UINT32_C(0x601A0036),"redis_score_length",sxd_redis_score_length_fields,SX_COUNT(sxd_redis_score_length_fields),SX_LE};
static const xx_data_struct_field_desc sxd_redis_score_binary_fields[] = {
    SX_FIELD("ieee754_binary64_bits", "uint64", 0, 8, SX_NONE),
};
const sx_layout sxd_redis_score_binary = {UINT32_C(0x601A0037),"redis_score_binary",sxd_redis_score_binary_fields,SX_COUNT(sxd_redis_score_binary_fields),SX_LE};
static bool sxd_redis_len(sx_context *c,const uint8_t *b,uint64_t *at,uint64_t *v,bool *encoded)
{
    if(!sxd_can(c,*at,1))return false;uint64_t start=*at;uint8_t x=b[(*at)++];*encoded=x>=192;*v=x&63;
    if(*encoded)return *v<=3&&sxd_add(c,&sxd_redis_encoded_string,start,1);
    if(x<64)return sxd_add(c,&sxd_redis_length_6,start,1);
    if(x<128){if(!sxd_can(c,*at,1))return false;*v=(*v<<8)|b[(*at)++];return sxd_add(c,&sxd_redis_length_14,start,2);}
    unsigned n=x==128?4:x==129?8:0;if(!n||!sxd_can(c,*at,n))return false;*v=n==4?sxd_be32(b+*at):xx_data_get_u64(b+*at,8,0,true);*at+=n;return sxd_add(c,n==4?&sxd_redis_length_32:&sxd_redis_length_64,start,n+1);
}
static bool sxd_redis_plain(sx_context *c,const uint8_t *b,uint64_t *at,uint64_t *v){bool encoded;return sxd_redis_len(c,b,at,v,&encoded)&&!encoded;}
static bool sxd_redis_string(sx_context *c,const uint8_t *b,uint64_t *at)
{
    uint64_t n,m;bool enc;if(!sxd_redis_len(c,b,at,&n,&enc))return false;
    if(enc&&n<3){unsigned width=1U<<(unsigned)n;if(!sxd_add(c,n==0?&sxd_redis_integer_1:n==1?&sxd_redis_integer_2:&sxd_redis_integer_4,*at,width))return false;*at+=width;return true;}
    if(enc){if(!sxd_redis_plain(c,b,at,&n)||!sxd_redis_plain(c,b,at,&m))return false;}
    if(!sxd_can(c,*at,n))return false;*at+=n;return true;
}
static bool sxd_redis(sx_context *c,const uint8_t *b)
{
    uint64_t at=9;if(!sxd_add(c,&sxd_redis_header,0,9))return false;
    while(at<(uint64_t)c->size-8){uint64_t start=at,n;uint8_t type=b[at++];if(type==255)return sxd_add(c,&sxd_redis_trailer,start,9)&&at+8==(uint64_t)c->size;
        if(type==252||type==253||type==249){unsigned width=type==252?8:type==253?4:1;if(!sxd_add(c,type==252?&sxd_redis_expire_milliseconds:type==253?&sxd_redis_expire_seconds:&sxd_redis_frequency,start,width+1))return false;at+=width;continue;}
        if(!sxd_add(c,&sxd_redis_opcode,start,1))return false;
        if(type==250){if(!sxd_redis_string(c,b,&at)||!sxd_redis_string(c,b,&at))return false;continue;}
        if(type==254||type==251||type==248){if(!sxd_redis_plain(c,b,&at,&n)||(type==251&&!sxd_redis_plain(c,b,&at,&n)))return false;continue;}
        if(type>5||!sxd_redis_string(c,b,&at))return false;
        if(!type){if(!sxd_redis_string(c,b,&at))return false;continue;}
        if(!sxd_redis_plain(c,b,&at,&n)||n>65536)return false;
        for(uint64_t i=0;i<n;i++){if(!sxd_redis_string(c,b,&at))return false;if(type==4){if(!sxd_redis_string(c,b,&at))return false;}else if(type==5){if(!sxd_add(c,&sxd_redis_score_binary,at,8))return false;at+=8;}else if(type==3){if(!sxd_can(c,at,1)||!sxd_add(c,&sxd_redis_score_length,at,1))return false;uint8_t len=b[at++];if(len<253){if(!sxd_can(c,at,len))return false;at+=len;}}}
    }return false;
}
bool sx_redis_rdb_build(sx_context *c,uint8_t *b)
{
 return sxd_redis(c,b);
}
