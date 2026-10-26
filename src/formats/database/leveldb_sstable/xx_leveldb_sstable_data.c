/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * leveldb_sstable data structures, moved out of the databases schema family. */
#include "../../xx_format_schema_databases.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxd_leveldb_restart_offset_fields[] = {
    SX_FIELD("restart_offset", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxd_leveldb_restart_offset = {UINT32_C(0x601A0025),"leveldb_restart_offset",sxd_leveldb_restart_offset_fields,SX_COUNT(sxd_leveldb_restart_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxd_leveldb_restart_count_fields[] = {
    SX_FIELD("restart_count", "uint32", 0, 4, SX_COUNT_PROP),
};
const sx_layout sxd_leveldb_restart_count = {UINT32_C(0x601A0026),"leveldb_restart_count",sxd_leveldb_restart_count_fields,SX_COUNT(sxd_leveldb_restart_count_fields),SX_LE};
static const xx_data_struct_field_desc sxd_leveldb_footer_magic_fields[] = {
    SX_FIELD("magic", "uint64", 0, 8, SX_SIGNATURE),
};
const sx_layout sxd_leveldb_footer_magic = {UINT32_C(0x601A0027),"leveldb_footer_magic",sxd_leveldb_footer_magic_fields,SX_COUNT(sxd_leveldb_footer_magic_fields),SX_LE};
typedef struct sxd_handle{uint64_t at,size;}sxd_handle;
static bool sxd_level_block(sx_context *c,const uint8_t *b,sxd_handle h,unsigned mode,sxd_handle *handles,size_t *count)
{
    if(h.size<8||h.size>INT64_MAX-5||!sxd_can(c,h.at,h.size+5))return false;uint32_t n=sxd_u32(b+h.at+h.size-4);if(!n||n>4096||(uint64_t)n*4>h.size-4)return false;
    uint64_t end=h.at+h.size-4-(uint64_t)n*4,at=h.at;
    while(at<end){uint64_t shared,key,value;if(!sxd_var(c,b,&at,end,&shared,sxd_database_varuint_size_rows)||!sxd_var(c,b,&at,end,&key,sxd_database_varuint_size_rows)||!sxd_var(c,b,&at,end,&value,sxd_database_varuint_size_rows)||key>end-at||value>end-at-key)return false;at+=key;
        if(mode==1){uint64_t ve=at+value,x,y;if(!sxd_var(c,b,&at,ve,&x,sxd_database_varuint_offset_rows)||!sxd_var(c,b,&at,ve,&y,sxd_database_varuint_size_rows)||at!=ve||*count>=1024)return false;handles[(*count)++]=(sxd_handle){x,y};}else at+=value;
    }
    return sxd_table(c,&sxd_leveldb_restart_offset,end,4,n)&&sxd_add(c,&sxd_leveldb_restart_count,h.at+h.size-4,4)&&sxd_add(c,&sxd_leveldb_block_trailer,h.at+h.size,5);
}
static bool sxd_leveldb(sx_context *c,const uint8_t *b)
{
    if(c->size<48)return false;uint64_t footer=(uint64_t)c->size-48,at=footer;uint64_t v[4];for(unsigned i=0;i<4;i++)if(!sxd_var(c,b,&at,footer+40,&v[i],i%2?sxd_database_varuint_size_rows:sxd_database_varuint_offset_rows))return false;
    if(!sxd_add(c,&sxd_leveldb_footer_magic,footer+40,8))return false;sxd_handle handles[1024];size_t count=0;
    if(!sxd_level_block(c,b,(sxd_handle){v[0],v[1]},2,NULL,NULL)||!sxd_level_block(c,b,(sxd_handle){v[2],v[3]},1,handles,&count))return false;
    for(size_t i=0;i<count;i++)if(!sxd_level_block(c,b,handles[i],0,NULL,NULL))return false;return true;
}
bool sx_leveldb_sstable_build(sx_context *c,uint8_t *b)
{
 return sxd_leveldb(c,b);
}
