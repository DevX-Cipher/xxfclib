/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SFPack (.sfpack) data structures, moved out of the audiolater schema family. */
#include "../../xx_format_schema_audiolater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaul_sfpack_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_ID),
    SX_FIELD("flags","uint16",6,2,SX_FLAGS),
    SX_FIELD("declared_sf2_bytes","int32",8,4,SX_SIZE),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
const sx_layout sxaul_sfpack_header = {UINT32_C(0x60380091),"sfpack_header",sxaul_sfpack_header_fields,SX_COUNT(sxaul_sfpack_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sfpack_chunk_fields[] = {
    SX_FIELD("chunk_bytes","int32",0,4,SX_SIZE),
    SX_FIELD("tag","char[4]",4,4,SX_ID),
    SX_FIELD("decoded_bytes","int32",8,4,SX_SIZE),
};
const sx_layout sxaul_sfpack_chunk = {UINT32_C(0x60380092),"sfpack_chunk",sxaul_sfpack_chunk_fields,SX_COUNT(sxaul_sfpack_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sfpack_skip_fields[] = {
    SX_FIELD("opaque_bytes","int32",0,4,SX_SIZE),
};
const sx_layout sxaul_sfpack_skip = {UINT32_C(0x60380093),"sfpack_skip",sxaul_sfpack_skip_fields,SX_COUNT(sxaul_sfpack_skip_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sfpack_table_fields[] = {
    SX_FIELD("table_bytes","int32",0,4,SX_SIZE),
};
const sx_layout sxaul_sfpack_table = {UINT32_C(0x60380094),"sfpack_table",sxaul_sfpack_table_fields,SX_COUNT(sxaul_sfpack_table_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sfpack_offset_fields[] = {
    SX_FIELD("sample_stream_offset","int32",0,4,SX_OFFSET),
};
const sx_layout sxaul_sfpack_offset = {UINT32_C(0x60380095),"sfpack_offset",sxaul_sfpack_offset_fields,SX_COUNT(sxaul_sfpack_offset_fields),SX_LE};
#define AL(n,k) do{if(!sxaul_take(c,&sxaul_##n,&at,end,(k)))return false;}while(0)
#define SK(n) do{if(!sxaul_skip(&at,end,(n)))return false;}while(0)
#define N(p,w) sxaul_num(c,(p),(w),false)
static bool sxaul_sfpack(sx_context*c)
{
 int64_t at=0,end=c->size;AL(sfpack_header,1);
 for(unsigned i=0;i<2;i++){
  if(end-at<12) return true;uint32_t size=N(at,4);
  if(size<9||size>INT32_MAX||size-8>(uint64_t)(end-at-12))return true;
  AL(sfpack_chunk,1);SK(size-8);
 }
 if(end-at<4)return true;uint32_t size=N(at,4);AL(sfpack_skip,1);
 if(!size||size>INT32_MAX||size>(uint64_t)(end-at))return true;SK(size);
 if(end-at<4)return true;size=N(at,4);AL(sfpack_table,1);
 if(!size||size>INT32_MAX||size%4||size>(uint64_t)(end-at))return true;
 AL(sfpack_offset,size/4);return !c->failed;
}
bool sx_sfpack_build(sx_context*c)
{
 return sxaul_sfpack(c)&&sxaul_finish(c);
}
#undef AL
#undef SK
#undef N
