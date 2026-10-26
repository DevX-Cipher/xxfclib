/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * lmdb_data data structures, moved out of the databases schema family. */
#include "../../xx_format_schema_databases.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxd_lmdb_meta_tail_fields[] = {
    SX_FIELD("last_page", "uint64", 0, 8, SX_NONE),
    SX_FIELD("transaction_id", "uint64", 8, 8, SX_ID),
};
const sx_layout sxd_lmdb_meta_tail = {UINT32_C(0x601A001D),"lmdb_meta_tail",sxd_lmdb_meta_tail_fields,SX_COUNT(sxd_lmdb_meta_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxd_lmdb_node_offset_fields[] = {
    SX_FIELD("node_offset", "uint16", 0, 2, SX_OFFSET),
};
const sx_layout sxd_lmdb_node_offset = {UINT32_C(0x601A001F),"lmdb_node_offset",sxd_lmdb_node_offset_fields,SX_COUNT(sxd_lmdb_node_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxd_lmdb_branch_node_fields[] = {
    SX_FIELD("child_page_low", "uint32", 0, 4, SX_NONE),
    SX_FIELD("child_page_high", "uint16", 4, 2, SX_NONE),
    SX_FIELD("key_size", "uint16", 6, 2, SX_SIZE),
};
const sx_layout sxd_lmdb_branch_node = {UINT32_C(0x601A0021),"lmdb_branch_node",sxd_lmdb_branch_node_fields,SX_COUNT(sxd_lmdb_branch_node_fields),SX_LE};
static const xx_data_struct_field_desc sxd_lmdb_overflow_reference_fields[] = {
    SX_FIELD("overflow_page", "uint64", 0, 8, SX_NONE),
};
const sx_layout sxd_lmdb_overflow_reference = {UINT32_C(0x601A0022),"lmdb_overflow_reference",sxd_lmdb_overflow_reference_fields,SX_COUNT(sxd_lmdb_overflow_reference_fields),SX_LE};
static uint16_t sxd_u16(const uint8_t *p){return xx_data_get_u16(p,2,0,false);}
static uint64_t sxd_u64(const uint8_t *p){return xx_data_get_u64(p,8,0,false);}
static bool sxd_lmdb(sx_context *c,const uint8_t *b)
{
    if(!sxd_can(c,0,152))return false;uint32_t unit=sxd_u32(b+40);if(unit<512||unit>32768||(unit&(unit-1))||!sxd_can(c,unit,152))return false;
    for(unsigned i=0;i<2;i++){uint64_t at=(uint64_t)i*unit;if(!sxd_add(c,&sxd_lmdb_meta_prefix,at,40)||!sxd_add(c,&sxd_lmdb_free_database,at+40,48)||!sxd_add(c,&sxd_lmdb_database,at+88,48)||!sxd_add(c,&sxd_lmdb_meta_tail,at+136,16))return false;}
    const uint8_t *meta=sxd_u64(b+144)>sxd_u64(b+unit+144)?b:b+unit;uint64_t last=sxd_u64(meta+136);if(last>16383||last>=(uint64_t)c->size/unit)return false;
    for(uint64_t p=2;p<=last;p++){
        uint64_t at=p*unit;if(!sxd_can(c,at,unit))return false;const uint8_t *h=b+at;uint16_t flags=sxd_u16(h+10);
        if(flags==4){uint32_t pages=sxd_u32(h+12);if(!pages||pages>last-p+1||!sxd_add(c,&sxd_lmdb_overflow_page,at,16))return false;p+=pages-1;continue;}
        if(flags!=1&&flags!=2)return false;uint16_t lower=sxd_u16(h+12),upper=sxd_u16(h+14);if(lower<16||lower>upper||upper>unit||(lower&1)||(upper&1))return false;uint32_t n=(lower-16)/2;
        if(!sxd_add(c,&sxd_lmdb_page_header,at,16)||!sxd_table(c,&sxd_lmdb_node_offset,at+16,2,n))return false;
        for(uint32_t i=0;i<n;i++){
            uint16_t off=sxd_u16(h+16+2*i);if(off<upper||off>unit-8)return false;const uint8_t *node=h+off;uint32_t k=sxd_u16(node+6),bytes=sxd_u32(node);
            if(k>unit-off-8||!sxd_add(c,flags==1?&sxd_lmdb_branch_node:&sxd_lmdb_leaf_node,at+off,8))return false;
            if(flags==2){uint16_t nf=sxd_u16(node+4);if(nf==1){if(!sxd_add(c,&sxd_lmdb_overflow_reference,at+off+8+k,8))return false;}else if(nf||bytes>unit-off-8-k)return false;}
        }
    }return true;
}
bool sx_lmdb_data_build(sx_context *c,uint8_t *b)
{
 return sxd_lmdb(c,b);
}
