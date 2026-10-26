/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LOFI data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_lofi_header_fields[] = {
    SX_FIELD("algorithm","char[36]",0,36,SX_NONE),
    SX_FIELD("segment_size","uint32",36,4,SX_SIZE),
    SX_FIELD("index_count","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("last_segment_size","uint32",44,4,SX_SIZE),
};
const sx_layout sxsl_lofi_header = {0x60330001U,"lofi_header",sxsl_lofi_header_fields,SX_COUNT(sxsl_lofi_header_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_lofi_index_fields[] = {
    SX_FIELD("segment_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxsl_lofi_index = {0x60330002U,"lofi_index",sxsl_lofi_index_fields,SX_COUNT(sxsl_lofi_index_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_lofi_segment_fields[] = {
    SX_FIELD("compressed","uint8",0,1,SX_ID),
};
const sx_layout sxsl_lofi_segment = {0x60330003U,"lofi_segment",sxsl_lofi_segment_fields,SX_COUNT(sxsl_lofi_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_lofi_lzma_header_fields[] = {
    SX_FIELD("properties","uint8",0,1,SX_ID),
    SX_FIELD("dictionary_size","uint32",1,4,SX_SIZE),
    SX_FIELD("uncompressed_size","uint64",5,8,SX_SIZE),
};
const sx_layout sxsl_lofi_lzma_header = {0x60330004U,"lofi_lzma_header",sxsl_lofi_lzma_header_fields,SX_COUNT(sxsl_lofi_lzma_header_fields),SX_LE};
#define SXSL_LIMIT 24000U
#define SXSL_ROWS 1048576U
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
#define SXSL_TABLE(c,l,p,n) sxsl_put(c,&sxsl_##l,p,n)
static bool sxsl_lofi(sx_context*c){uint8_t h[48];if(!sxsl_read(c,0,h,48)||!SXSL_ADD(c,lofi_header,0))return false;uint64_t n=sxsl_uint(h+40,4,true),base=48+n*8;if(n<2||n>SXSL_ROWS||!SXSL_TABLE(c,lofi_index,48,n))return true;bool lzma=!xx_rt_memcmp(h,"lzma",4);for(uint64_t i=0;i+1<n&&c->count<SXSL_LIMIT;i++){uint64_t a,b;uint8_t flag;if(!sxsl_word(c,48+i*8,8,true,&a)||!sxsl_word(c,56+i*8,8,true,&b)||a>b||b>(uint64_t)c->size-base||!sxsl_read(c,base+a,&flag,1)||!SXSL_ADD(c,lofi_segment,base+a))break;if(flag==1&&lzma&&b-a>=14&&!SXSL_ADD(c,lofi_lzma_header,base+a+1))return false;}return true;}
bool sx_lofi_build(sx_context*c)
{
bool ok=false;
ok=sxsl_lofi(c);
return ok&&sxsl_finish(c);
}
