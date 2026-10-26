/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * postgres_custom data structures, moved out of the databases schema family. */
#include "../../xx_format_schema_databases.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxd_postgres_compression_legacy_fields[] = {
    SX_FIELD("compression_sign", "uint8", 0, 1, SX_NONE),
    SX_FIELD("compression_magnitude", "uint32", 1, 4, SX_NONE),
};
const sx_layout sxd_postgres_compression_legacy = {UINT32_C(0x601A0011),"postgres_compression_legacy",sxd_postgres_compression_legacy_fields,SX_COUNT(sxd_postgres_compression_legacy_fields),SX_LE};
static const xx_data_struct_field_desc sxd_postgres_toc_count_fields[] = {
    SX_FIELD("count_sign", "uint8", 0, 1, SX_NONE),
    SX_FIELD("count_magnitude", "uint32", 1, 4, SX_COUNT_PROP),
};
const sx_layout sxd_postgres_toc_count = {UINT32_C(0x601A0014),"postgres_toc_count",sxd_postgres_toc_count_fields,SX_COUNT(sxd_postgres_toc_count_fields),SX_LE};
static const xx_data_struct_field_desc sxd_postgres_toc_prefix_fields[] = {
    SX_FIELD("dump_id_sign", "uint8", 0, 1, SX_NONE),
    SX_FIELD("dump_id_magnitude", "uint32", 1, 4, SX_ID),
    SX_FIELD("has_dumper_sign", "uint8", 5, 1, SX_NONE),
    SX_FIELD("has_dumper_magnitude", "uint32", 6, 4, SX_FLAGS),
};
const sx_layout sxd_postgres_toc_prefix = {UINT32_C(0x601A0015),"postgres_toc_prefix",sxd_postgres_toc_prefix_fields,SX_COUNT(sxd_postgres_toc_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxd_postgres_chunk_length_fields[] = {
    SX_FIELD("length_sign", "uint8", 0, 1, SX_NONE),
    SX_FIELD("length_magnitude", "uint32", 1, 4, SX_SIZE),
};
const sx_layout sxd_postgres_chunk_length = {UINT32_C(0x601A0019),"postgres_chunk_length",sxd_postgres_chunk_length_fields,SX_COUNT(sxd_postgres_chunk_length_fields),SX_LE};
static bool sxd_pg_int(sx_context *c,const uint8_t *b,uint64_t *at,int64_t *v,const sx_layout *l)
{
    if(!sxd_can(c,*at,5)||b[*at]>1||sxd_u32(b+*at+1)>INT32_MAX)return false;*v=sxd_u32(b+*at+1);if(b[*at])*v=-*v;if(l&&!sxd_add(c,l,*at,5))return false;*at+=5;return true;
}
static bool sxd_pg_string(sx_context *c,const uint8_t *b,uint64_t *at,bool *null)
{
    int64_t n;if(!sxd_pg_int(c,b,at,&n,&sxd_postgres_string_length)||n< -1||n>65536)return false;*null=n==-1;if(!*null){if(!sxd_can(c,*at,(uint64_t)n))return false;*at+=(uint64_t)n;}return true;
}
static bool sxd_postgres(sx_context *c,const uint8_t *b)
{
    uint64_t at=11;int64_t n,v;bool null;if(!sxd_add(c,&sxd_postgres_header,0,11))return false;
    if(b[6]>=15){if(!sxd_add(c,&sxd_postgres_compression_v15,at++,1))return false;}else if(!sxd_pg_int(c,b,&at,&v,&sxd_postgres_compression_legacy))return false;
    if(!sxd_add(c,&sxd_postgres_time,at,35))return false;at+=35;for(unsigned i=0;i<3;i++)if(!sxd_pg_string(c,b,&at,&null))return false;
    if(!sxd_pg_int(c,b,&at,&n,&sxd_postgres_toc_count)||n<=0||n>1024)return false;
    for(int64_t i=0;i<n;i++){
        if(!sxd_add(c,&sxd_postgres_toc_prefix,at,10))return false;at+=10;for(unsigned j=0;j<4;j++)if(!sxd_pg_string(c,b,&at,&null))return false;
        if(!sxd_pg_int(c,b,&at,&v,&sxd_postgres_section))return false;
        for(unsigned j=0;j<(b[6]>=14?8U:7U);j++)if(!sxd_pg_string(c,b,&at,&null))return false;
        unsigned deps=0;do{if(++deps>1024||!sxd_pg_string(c,b,&at,&null))return false;}while(!null);
        if(!sxd_add(c,&sxd_postgres_data_offset,at,9))return false;at+=9;
    }
    while(at<(uint64_t)c->size){if(!sxd_add(c,&sxd_postgres_block_header,at,6))return false;at+=6;do{if(!sxd_pg_int(c,b,&at,&n,&sxd_postgres_chunk_length)||n<0||!sxd_can(c,at,(uint64_t)n))return false;at+=(uint64_t)n;}while(n);}
    return true;
}
bool sx_postgres_custom_build(sx_context *c,uint8_t *b)
{
 return sxd_postgres(c,b);
}
