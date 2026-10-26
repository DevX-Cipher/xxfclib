/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Now Compress archives data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_nowcompress_header_fields[] = {
 SX_FIELD("signature","uint8[2]",0,2,SX_SIGNATURE),
 SX_FIELD("unknown2","uint8[6]",2,6,SX_NONE),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("unknown12","uint8[12]",12,12,SX_NONE),
};
const sx_layout sxag_nowcompress_header = {UINT32_C(0x60250005),"nowcompress_header",sxag_nowcompress_header_fields,SX_COUNT(sxag_nowcompress_header_fields),SX_BE};
static const xx_data_struct_field_desc sxag_nowcompress_entry_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[31]",1,31,SX_STRING),
 SX_FIELD("unknown32","uint8[4]",32,4,SX_NONE),
 SX_FIELD("flags","uint16",36,2,SX_FLAGS),
 SX_FIELD("finder_info","uint8[16]",38,16,SX_NONE),
 SX_FIELD("created","uint32",54,4,SX_NONE),
 SX_FIELD("modified","uint32",58,4,SX_NONE),
 SX_FIELD("accessed","uint32",62,4,SX_NONE),
 SX_FIELD("unknown66","uint8[16]",66,16,SX_NONE),
 SX_FIELD("child_count","uint16",82,2,SX_COUNT_PROP),
 SX_FIELD("unknown84","uint16",84,2,SX_NONE),
 SX_FIELD("data_size","uint32",86,4,SX_SIZE),
 SX_FIELD("resource_size","uint32",90,4,SX_SIZE),
 SX_FIELD("unknown94","uint32",94,4,SX_NONE),
 SX_FIELD("stream_start","uint32",98,4,SX_OFFSET),
 SX_FIELD("stream_end","uint32",102,4,SX_OFFSET),
 SX_FIELD("checksum","uint32",106,4,SX_CHECKSUM),
};
const sx_layout sxag_nowcompress_entry = {UINT32_C(0x60250006),"nowcompress_entry",sxag_nowcompress_entry_fields,SX_COUNT(sxag_nowcompress_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxag_nowcompress_stream_fields[] = {
 SX_FIELD("first_data_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxag_nowcompress_stream = {UINT32_C(0x60250007),"nowcompress_stream",sxag_nowcompress_stream_fields,SX_COUNT(sxag_nowcompress_stream_fields),SX_BE};
static const xx_data_struct_field_desc sxag_nowcompress_block_fields[] = {
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("padding_size","uint16",2,2,SX_SIZE),
 SX_FIELD("next_data_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxag_nowcompress_block = {UINT32_C(0x60250008),"nowcompress_block",sxag_nowcompress_block_fields,SX_COUNT(sxag_nowcompress_block_fields),SX_BE};
static const xx_data_struct_field_desc sxag_nowcompress_stream_end_fields[] = {
 SX_FIELD("unknown","uint32",0,4,SX_NONE),
 SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
};
const sx_layout sxag_nowcompress_stream_end = {UINT32_C(0x60250009),"nowcompress_stream_end",sxag_nowcompress_stream_end_fields,SX_COUNT(sxag_nowcompress_stream_end_fields),SX_BE};
#define SXAG_LIMIT 20000U
static bool sxag_now(sx_context *c){uint8_t b[110];if(!sxag_read(c,0,b,24)||!sxag_add(c,&sxag_nowcompress_header,0))return false;uint64_t n=sxag32(b+8,true);if(!n||n>SXAG_LIMIT||!sxag_span(c,24,n*110))return true;if(!sxag_table(c,&sxag_nowcompress_entry,24,n))return false;uint64_t directory_end=24+n*110;
 for(uint64_t i=0;i<n&&c->count<SXAG_LIMIT;i++){if(!sxag_read(c,24+i*110,b,110))break;if((sxag16(b+36,true)&16)||(!sxag32(b+86,true)&&!sxag32(b+90,true)))continue;uint64_t start=sxag32(b+98,true),end=sxag32(b+102,true);if(start<directory_end||end<=start||!sxag_span(c,start,end-start)||!sxag_read(c,start,b,4))continue;uint64_t first=sxag32(b,true);if(first<start+20||first>end||(first-start-4)%8)continue;uint64_t blocks=(first-start-4)/8-1;if(!blocks||blocks>8191||!sxag_free(c,start,first-start))continue;if(!sxag_add(c,&sxag_nowcompress_stream,start)||!sxag_table(c,&sxag_nowcompress_block,start+4,blocks)||!sxag_add(c,&sxag_nowcompress_stream_end,first-8))return false;}
 return true;}
bool sx_nowcompress_build(sx_context*c)
{
 return sxag_now(c);
}
