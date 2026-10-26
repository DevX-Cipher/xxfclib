/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfArk v2 compressed SoundFont data structures, moved out of the audiolater schema family. */
#include "../../xx_format_schema_audiolater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaul_sfark_header_fields[] = {
    SX_FIELD("flags","uint32",0,4,SX_FLAGS),
    SX_FIELD("original_bytes","uint32",4,4,SX_SIZE),
    SX_FIELD("compressed_bytes","uint32",8,4,SX_SIZE),
    SX_FIELD("file_checksum","uint32",12,4,SX_CHECKSUM),
    SX_FIELD("header_checksum","uint32",16,4,SX_CHECKSUM),
    SX_FIELD("version_needed","uint8",20,1,SX_ID),
    SX_FIELD("program_version","char[5]",21,5,SX_STRING),
    SX_FIELD("magic","char[5]",26,5,SX_SIGNATURE),
    SX_FIELD("method","uint8",31,1,SX_ID),
    SX_FIELD("file_type","uint16",32,2,SX_ID),
    SX_FIELD("audio_start","uint32",34,4,SX_OFFSET),
    SX_FIELD("post_audio_start","uint32",38,4,SX_OFFSET),
};
const sx_layout sxaul_sfark_header = {UINT32_C(0x6038008e),"sfark_header",sxaul_sfark_header_fields,SX_COUNT(sxaul_sfark_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sfark_name_byte_fields[] = {
    SX_FIELD("filename_byte","char[1]",0,1,SX_STRING),
};
const sx_layout sxaul_sfark_name_byte = {UINT32_C(0x6038008f),"sfark_name_byte",sxaul_sfark_name_byte_fields,SX_COUNT(sxaul_sfark_name_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sfark_text_fields[] = {
    SX_FIELD("compressed_text_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxaul_sfark_text = {UINT32_C(0x60380090),"sfark_text",sxaul_sfark_text_fields,SX_COUNT(sxaul_sfark_text_fields),SX_LE};
#define AL(n,k) do{if(!sxaul_take(c,&sxaul_##n,&at,end,(k)))return false;}while(0)
#define SK(n) do{if(!sxaul_skip(&at,end,(n)))return false;}while(0)
#define N(p,w) sxaul_num(c,(p),(w),false)
/* Compressed SoundFont metadata is physical; decoded sample offsets are labelled
 * explicitly and never become physical addresses or decoded structure ranges. */
static bool sxaul_sfark(sx_context*c)
{
 int64_t at=0,end=c->size;uint32_t flags=N(0,4);AL(sfark_header,1);
 int64_t start=at;while(at<end&&at-start<1024&&N(at,1))at++;
 if(at>=end||at-start>=1024)return c->count>0;
 at++;int64_t after=at;at=start;AL(sfark_name_byte,after-start);
 for(unsigned i=0;i<2;i++)if(flags&(i?1:2)){
  if(end-at<4)break;uint32_t size=N(at,4);AL(sfark_text,1);
  if(!size||size>(uint64_t)(end-at))break;SK(size);
 }return !c->failed;
}
bool sx_sfark_compressed_soundfont_build(sx_context*c)
{
 return sxaul_sfark(c)&&sxaul_finish(c);
}
#undef AL
#undef SK
#undef N
