/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Apple II cassette WAV data structures, moved out of the diskremaining schema family. */
#include "../../xx_format_schema_diskremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdr_cassette_riff_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("riff_bytes","uint32",4,4,SX_SIZE),
    SX_FIELD("form_type","char[4]",8,4,SX_ID),
};
const sx_layout sxdr_cassette_riff = {0x607f001aU,"cassette_riff",sxdr_cassette_riff_fields,SX_COUNT(sxdr_cassette_riff_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_cassette_chunk_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("data_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxdr_cassette_chunk = {0x607f001bU,"cassette_chunk",sxdr_cassette_chunk_fields,SX_COUNT(sxdr_cassette_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_cassette_pcm_format_fields[] = {
    SX_FIELD("format_tag","uint16",0,2,SX_ID),
    SX_FIELD("channels","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("sample_rate","uint32",4,4,SX_NONE),
    SX_FIELD("byte_rate","uint32",8,4,SX_NONE),
    SX_FIELD("block_alignment","uint16",12,2,SX_SIZE),
    SX_FIELD("bits_per_sample","uint16",14,2,SX_NONE),
};
const sx_layout sxdr_cassette_pcm_format = {0x607f001cU,"cassette_pcm_format",sxdr_cassette_pcm_format_fields,SX_COUNT(sxdr_cassette_pcm_format_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_cassette_pcm_extension_fields[] = {
    SX_FIELD("extension_bytes","uint16",0,2,SX_SIZE),
};
const sx_layout sxdr_cassette_pcm_extension = {0x607f0033U,"cassette_pcm_extension",sxdr_cassette_pcm_extension_fields,SX_COUNT(sxdr_cassette_pcm_extension_fields),SX_LE};
#define SXDR_ADD(c,n,p) sxdr_put(c,&sxdr_##n,p,1)
static bool sxdr_cassette(sx_context*c){uint8_t h[16];if(!sxdr_read(c,0,h,12)||xx_rt_memcmp(h,"RIFF",4)||xx_rt_memcmp(h+8,"WAVE",4)||!SXDR_ADD(c,cassette_riff,0))return false;uint64_t end=8+(uint64_t)sxdr32(h+4,false),p=12;if(end>(uint64_t)c->size)return true;
 while(p<=end&&end-p>=8){if(!sxdr_read(c,p,h,8)||!SXDR_ADD(c,cassette_chunk,p))return false;uint64_t n=sxdr32(h+4,false);p+=8;if(n>end-p)break;if(!xx_rt_memcmp(h,"fmt ",4)&&n>=16){if(!SXDR_ADD(c,cassette_pcm_format,p))return false;if(n==18&&!SXDR_ADD(c,cassette_pcm_extension,p+16))return false;}p+=n;if(n&1){if(p==end)break;p++;}}return true;}
#undef SXDR_ADD
bool sx_apple_cassette_build(sx_context*c)
{
 return sxdr_cassette(c);
}
