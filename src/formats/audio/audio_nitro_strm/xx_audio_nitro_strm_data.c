/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * audio_nitro_strm data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_nitro_header_le_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("version","uint16",6,2,SX_ID),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("header_size","uint16",12,2,SX_SIZE),
 SX_FIELD("block_count","uint16",14,2,SX_COUNT_PROP),
};
const sx_layout sxau_nitro_header_le={UINT32_C(0x602C0066),"nitro_header_le",sxau_nitro_header_le_fields,SX_COUNT(sxau_nitro_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxau_nitro_chunk_le_fields[]={
 SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
 SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxau_nitro_chunk_le={UINT32_C(0x602C0067),"nitro_chunk_le",sxau_nitro_chunk_le_fields,SX_COUNT(sxau_nitro_chunk_le_fields),SX_LE};
static const xx_data_struct_field_desc sxau_nitro_stream_le_fields[]={
 SX_FIELD("encoding","uint8",0,1,SX_ID),
 SX_FIELD("loop_flag","uint8",1,1,SX_FLAGS),
 SX_FIELD("channels","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
 SX_FIELD("sample_rate","uint16",4,2,SX_NONE),
 SX_FIELD("timer","uint16",6,2,SX_NONE),
 SX_FIELD("loop_start_sample","uint32",8,4,SX_NONE),
 SX_FIELD("total_samples","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("data_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("block_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("block_bytes","uint32",24,4,SX_SIZE),
 SX_FIELD("samples_per_block","uint32",28,4,SX_COUNT_PROP),
 SX_FIELD("last_block_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("last_block_samples","uint32",36,4,SX_COUNT_PROP),
};
const sx_layout sxau_nitro_stream_le={UINT32_C(0x602C0068),"nitro_stream_le",sxau_nitro_stream_le_fields,SX_COUNT(sxau_nitro_stream_le_fields),SX_LE};
static const xx_data_struct_field_desc sxau_nitro_header_be_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("version","uint16",6,2,SX_ID),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("header_size","uint16",12,2,SX_SIZE),
 SX_FIELD("block_count","uint16",14,2,SX_COUNT_PROP),
};
const sx_layout sxau_nitro_header_be={UINT32_C(0x602C006B),"nitro_header_be",sxau_nitro_header_be_fields,SX_COUNT(sxau_nitro_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxau_nitro_chunk_be_fields[]={
 SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
 SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxau_nitro_chunk_be={UINT32_C(0x602C006C),"nitro_chunk_be",sxau_nitro_chunk_be_fields,SX_COUNT(sxau_nitro_chunk_be_fields),SX_BE};
static const xx_data_struct_field_desc sxau_nitro_stream_be_fields[]={
 SX_FIELD("encoding","uint8",0,1,SX_ID),
 SX_FIELD("loop_flag","uint8",1,1,SX_FLAGS),
 SX_FIELD("channels","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
 SX_FIELD("sample_rate","uint16",4,2,SX_NONE),
 SX_FIELD("timer","uint16",6,2,SX_NONE),
 SX_FIELD("loop_start_sample","uint32",8,4,SX_NONE),
 SX_FIELD("total_samples","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("data_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("block_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("block_bytes","uint32",24,4,SX_SIZE),
 SX_FIELD("samples_per_block","uint32",28,4,SX_COUNT_PROP),
 SX_FIELD("last_block_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("last_block_samples","uint32",36,4,SX_COUNT_PROP),
};
const sx_layout sxau_nitro_stream_be={UINT32_C(0x602C006D),"nitro_stream_be",sxau_nitro_stream_be_fields,SX_COUNT(sxau_nitro_stream_be_fields),SX_BE};
static bool sxau_nitro(sxau_view*v)
{if(!sxau_need(v,0,6,v->n))return false;bool be=v->p[4]==254;if(!sxau_row(v,be?&sxau_nitro_header_be:&sxau_nitro_header_le,0,v->n)||!sxau_row(v,be?&sxau_nitro_chunk_be:&sxau_nitro_chunk_le,16,v->n))return false;size_t n=sxau_u32(v->p+20,be);if(n<48||!sxau_need(v,16,n,v->n)||!sxau_row(v,be?&sxau_nitro_stream_be:&sxau_nitro_stream_le,24,16+n))return false;return sxau_row(v,be?&sxau_nitro_chunk_be:&sxau_nitro_chunk_le,16+n,v->n);}
bool sx_audio_nitro_strm_build(sxau_view*v)
{
 return sxau_nitro(v);
}
