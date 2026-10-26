/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GPT partition table data structures, moved out of the volume schema family. */
#include "../../xx_format_schema_volume.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/formats/filesystem/volume/xx_volume.h"
#include "xxfclib/formats/filesystem/gpt/xx_gpt.h"

/* Header CRC failures do not erase a recognizable physical header. The native
 * selected copy establishes validity; alternate copies need independently safe
 * framing before their physical members may be displayed. */
typedef struct sx_v_gpt_copy_info {
    uint64_t header,header_end,entries;
    uint32_t count,stride;
    bool framed,array;
} sx_v_gpt_copy_info;
static bool sx_v_gpt_read_header(sx_context *c,uint64_t at,uint64_t bs,bool selected,sx_v_gpt_copy_info *copy)
{
    uint8_t h[92];uint64_t entries;uint32_t count,stride,header_size;
    xx_mem_zero(copy,sizeof(*copy));
    if(!sx_v_fits(c,at,92))return !selected;
    if(!sx_read(c,(int64_t)at,h,92))return false;
    header_size=xx_data_get_u32(h,92,12,false);
    if(xx_rt_memcmp(h,"EFI PART",8)||header_size<92||header_size>bs||!sx_v_fits(c,at,header_size)||xx_data_get_u64(h,92,24,false)!=at/bs)return !selected;
    copy->framed=true;copy->header=at;copy->header_end=at+header_size;
    if(!sx_add(c,&sx_v_gpt_header,(int64_t)at,92))return false;
    entries=xx_data_get_u64(h,92,72,false);count=xx_data_get_u32(h,92,80,false);stride=xx_data_get_u32(h,92,84,false);
    if(!entries||entries>(uint64_t)INT64_MAX/bs||!count||count>4096||stride<128||stride>4096||stride%8)return !selected;
    entries*=bs;
    if(!sx_v_fits(c,entries,((uint64_t)count-1)*stride+128))return !selected;
    copy->array=true;copy->entries=entries;copy->count=count;copy->stride=stride;return true;
}
static bool sx_v_gpt_entries(sx_context *c,const sx_v_gpt_copy_info *copy,const sx_v_gpt_copy_info *headers,size_t nh)
{
    if(!copy->array)return true;
    uint64_t entries=copy->entries,end=entries+((uint64_t)copy->count-1)*copy->stride+128;
    bool overlap=false;
    /* Both safely framed headers are reserved first, including unknown header
     * extensions. A corrupt cross-copy array must not reinterpret those bytes
     * as partition entries. Their extension bytes remain RAW_DATA. */
    for(size_t j=0;j<nh;j++)if(headers[j].framed&&headers[j].header<end&&entries<headers[j].header_end)overlap=true;
    for(size_t j=0;j<c->count&&!overlap;j++) {
        uint64_t start=(uint64_t)(c->items[j].offset-c->f->base_address);
        if(start<end&&entries<start+(uint64_t)c->items[j].total_size)overlap=true;
    }
    if(!overlap&&copy->stride==128)return sx_table(c,&sx_v_gpt_partition_entry,(int64_t)entries,128,copy->count);
    for(uint32_t i=0;i<copy->count;i++) {
        uint64_t off=entries+(uint64_t)i*copy->stride;bool covered=false;
        for(size_t j=0;j<nh;j++)if(headers[j].framed&&headers[j].header<off+128&&off<headers[j].header_end)covered=true;
        for(size_t j=0;j<c->count&&!covered;j++) {
            uint64_t start=(uint64_t)(c->items[j].offset-c->f->base_address);
            if(start<off+128&&off<start+(uint64_t)c->items[j].total_size)covered=true;
        }
        if(!covered&&!sx_add(c,&sx_v_gpt_partition_entry,(int64_t)off,128))return false;
    }
    return true;
}
static bool sx_v_gpt(sx_context *c)
{
    const xx_gpt *g=(const xx_gpt *)c->f;uint64_t bs=g->block_size,backup;sx_v_gpt_copy_info copies[2];
    if((bs!=512&&bs!=4096)||c->size<(int64_t)(bs*2))return false;
    backup=((uint64_t)c->size/bs-1)*bs;
    if(!sx_v_gpt_read_header(c,g->used_backup?backup:bs,bs,true,&copies[0]))return false;
    xx_mem_zero(&copies[1],sizeof(copies[1]));
    if(backup!=bs&&!sx_v_gpt_read_header(c,g->used_backup?bs:backup,bs,false,&copies[1]))return false;
    return sx_v_gpt_entries(c,&copies[0],copies,2)&&sx_v_gpt_entries(c,&copies[1],copies,2);
}
bool sx_gpt_build(sx_context*c)
{
    if(!sx_v_gpt(c))return false;return true;
}
