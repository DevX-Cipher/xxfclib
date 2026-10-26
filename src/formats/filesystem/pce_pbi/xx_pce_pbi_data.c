/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PCE PBI data structures, moved out of the pcedisks schema family. */
#include "../../xx_format_schema_pcedisks.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_pc_pbi_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("l1_index_bits","uint8",12,1,SX_NONE),
    SX_FIELD("l2_index_bits","uint8",13,1,SX_NONE),
    SX_FIELD("block_size_shift","uint8",14,1,SX_NONE),
    SX_FIELD("reserved","uint8",15,1,SX_RESERVED),
    SX_FIELD("image_size","uint64",16,8,SX_SIZE),
    SX_FIELD("l1_offset","uint64",24,8,SX_OFFSET),
    SX_FIELD("file_size","uint64",32,8,SX_SIZE),
};
const sx_layout sx_pc_pbi_header = {0x60140018U,"pbi_header",sx_pc_pbi_header_fields,SX_COUNT(sx_pc_pbi_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_pc_pbi_l1_entry_fields[] = {
    SX_FIELD("l2_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sx_pc_pbi_l1_entry = {0x60140019U,"pbi_l1_entry",sx_pc_pbi_l1_entry_fields,SX_COUNT(sx_pc_pbi_l1_entry_fields),SX_BE};
static const xx_data_struct_field_desc sx_pc_pbi_l2_entry_fields[] = {
    SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sx_pc_pbi_l2_entry = {0x6014001aU,"pbi_l2_entry",sx_pc_pbi_l2_entry_fields,SX_COUNT(sx_pc_pbi_l2_entry_fields),SX_BE};
static bool sx_pc_free(sx_context *c,uint64_t at,uint64_t n)
{
    if(!sx_pc_span(c,at,n)||c->count>=50000)return false;
    for(size_t i=0;i<c->count;i++) {
        uint64_t o=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;
        if(at<o+z&&o<at+n)return false;
    }
    return true;
}
static bool sx_pc_pbi(sx_context *c)
{
    uint8_t b[48];uint64_t header=0;
    if(!sx_read(c,0,b,sizeof(b)))return false;
    if(!xx_rt_memcmp(b,"PBIn",4)) {
        if(b[14]<9||b[14]>24||(uint64_t)c->size<(UINT64_C(1)<<b[14]))return false;
        header=(uint64_t)c->size-(UINT64_C(1)<<b[14]);
        if(header<48||!sx_read(c,(int64_t)header,b,sizeof(b))||!sx_add(c,&sx_pc_pbi_header,0,40))return false;
    }
    if(xx_rt_memcmp(b,"PBI ",4)||b[12]>24||b[13]>24||b[14]<9||b[14]>24||!sx_add(c,&sx_pc_pbi_header,(int64_t)header,40))return false;
    uint64_t at=xx_data_get_u64(b,48,24,true),n=UINT64_C(1)<<b[12],m=UINT64_C(1)<<b[13],volume=xx_data_get_u64(b,48,16,true),block=UINT64_C(1)<<b[14];
    if(n>4096)n=4096;
    if(!sx_pc_free(c,at,n*8))return true;
    if(!sx_table(c,&sx_pc_pbi_l1_entry,(int64_t)at,8,n))return false;
    uint64_t blocks=volume/block+(volume%block!=0),needed=blocks/m+(blocks%m!=0);if(n>needed)n=needed;
    for(uint64_t i=0;i<n;i++) {
        uint64_t ptr;if(!sx_u64(c,(int64_t)(at+i*8),true,&ptr))return false;
        uint64_t entries=m;if(entries>4096)entries=4096;
        if(!ptr||!sx_pc_free(c,ptr,entries*8))continue;
        for(uint64_t j=0;j<entries;j++) {
            uint64_t value;if(!sx_u64(c,(int64_t)(ptr+j*8),true,&value))return false;
            if(c->count>=50000)return true;
            if(!sx_add(c,value&2U?&sx_pc_pbi_l2_fill:&sx_pc_pbi_l2_entry,(int64_t)(ptr+j*8),8))return false;
        }
    }
    return true;
}
bool sx_pce_pbi_build(sx_context*c)
{
    return sx_pc_pbi(c);
}
