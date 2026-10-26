/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ALDUS data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_aldus_header_fields[] = {
 SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",16,2,SX_SIZE),
 SX_FIELD("name","char[32]",18,32,SX_STRING),
 SX_FIELD("unpacked_size","uint32",50,4,SX_SIZE),
};
const sx_layout sxal_aldus_header = {UINT32_C(0x60200001),"aldus_header",sxal_aldus_header_fields,SX_COUNT(sxal_aldus_header_fields),SX_BE};
static const xx_data_struct_field_desc sxal_aldus_timestamp_fields[] = {
 SX_FIELD("modified","uint32",0,4,SX_NONE),
};
const sx_layout sxal_aldus_timestamp = {UINT32_C(0x60200002),"aldus_timestamp",sxal_aldus_timestamp_fields,SX_COUNT(sxal_aldus_timestamp_fields),SX_LE};
static const xx_data_struct_field_desc sxal_aldus_stream_fields[] = {
 SX_FIELD("header_size","uint16",0,2,SX_SIZE),
 SX_FIELD("block_size","uint16",2,2,SX_SIZE),
 SX_FIELD("last_block_size","uint16",4,2,SX_SIZE),
 SX_FIELD("block_count","uint32",6,4,SX_COUNT_PROP),
 SX_FIELD("block_table_offset","uint32",10,4,SX_OFFSET),
 SX_FIELD("data_offset","uint32",14,4,SX_OFFSET),
 SX_FIELD("archive_size","uint32",18,4,SX_SIZE),
};
const sx_layout sxal_aldus_stream = {UINT32_C(0x60200003),"aldus_stream",sxal_aldus_stream_fields,SX_COUNT(sxal_aldus_stream_fields),SX_BE};
static const xx_data_struct_field_desc sxal_aldus_block_size_fields[] = {
 SX_FIELD("packed_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxal_aldus_block_size = {UINT32_C(0x60200004),"aldus_block_size",sxal_aldus_block_size_fields,SX_COUNT(sxal_aldus_block_size_fields),SX_BE};
static bool sxal_aldus(sx_context *c){uint8_t b[64];if(!sxal_read(c,0,b,58)||!sxal_add(c,&sxal_aldus_header,0)||!sxal_add(c,&sxal_aldus_timestamp,54))return false;uint32_t h=sxal16(b+16,true);if((h!=100&&h!=200)||!sxal_read(c,h,b,22)||!sxal_add(c,&sxal_aldus_stream,h))return true;uint64_t n=sxal32(b+6,true),p=sxal32(b+10,true);if(n&&n<=SXAL_LIMIT&&p>=h+22&&sxal_span(c,p,n*2)&&!sx_table(c,&sxal_aldus_block_size,(int64_t)p,2,n))return false;return true;}
bool sx_aldus_build(sx_context*c)
{
 return sxal_aldus(c);
}
