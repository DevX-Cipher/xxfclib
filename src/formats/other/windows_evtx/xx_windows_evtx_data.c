/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * windows evtx data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_evtx_header_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("first_chunk","uint64",8,8,SX_NONE),
 SX_FIELD("last_chunk","uint64",16,8,SX_NONE),
 SX_FIELD("next_record_id","uint64",24,8,SX_ID),
 SX_FIELD("header_size","uint32",32,4,SX_SIZE),
 SX_FIELD("minor","uint16",36,2,SX_NONE),
 SX_FIELD("major","uint16",38,2,SX_NONE),
 SX_FIELD("header_block_size","uint16",40,2,SX_SIZE),
 SX_FIELD("chunk_count","uint32",42,4,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8[74]",46,74,SX_NONE),
 SX_FIELD("flags","uint32",120,4,SX_FLAGS),
 SX_FIELD("checksum","uint32",124,4,SX_CHECKSUM),
};
const sx_layout sxbx_evtx_header = {UINT32_C(0x60300024),"evtx_header",sxbx_evtx_header_fields,SX_COUNT(sxbx_evtx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evtx_chunk_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("first_record_number","uint64",8,8,SX_NONE),
 SX_FIELD("last_record_number","uint64",16,8,SX_NONE),
 SX_FIELD("first_record_id","uint64",24,8,SX_ID),
 SX_FIELD("last_record_id","uint64",32,8,SX_ID),
 SX_FIELD("header_size","uint32",40,4,SX_SIZE),
 SX_FIELD("last_record_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("free_space_offset","uint32",48,4,SX_OFFSET),
 SX_FIELD("records_checksum","uint32",52,4,SX_CHECKSUM),
 SX_FIELD("reserved","uint8[64]",56,64,SX_NONE),
 SX_FIELD("flags_or_unknown","uint32",120,4,SX_NONE),
 SX_FIELD("header_checksum","uint32",124,4,SX_CHECKSUM),
};
const sx_layout sxbx_evtx_chunk = {UINT32_C(0x60300025),"evtx_chunk",sxbx_evtx_chunk_fields,SX_COUNT(sxbx_evtx_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evtx_string_offset_fields[] = {
 SX_FIELD("string_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxbx_evtx_string_offset = {UINT32_C(0x60300026),"evtx_string_offset",sxbx_evtx_string_offset_fields,SX_COUNT(sxbx_evtx_string_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evtx_template_offset_fields[] = {
 SX_FIELD("template_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxbx_evtx_template_offset = {UINT32_C(0x60300027),"evtx_template_offset",sxbx_evtx_template_offset_fields,SX_COUNT(sxbx_evtx_template_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evtx_record_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("record_size","uint32",4,4,SX_SIZE),
 SX_FIELD("record_id","uint64",8,8,SX_ID),
 SX_FIELD("timestamp","uint64",16,8,SX_NONE),
};
const sx_layout sxbx_evtx_record = {UINT32_C(0x60300028),"evtx_record",sxbx_evtx_record_fields,SX_COUNT(sxbx_evtx_record_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_evtx_record_trailer_fields[] = {
 SX_FIELD("record_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxbx_evtx_record_trailer = {UINT32_C(0x60300029),"evtx_record_trailer",sxbx_evtx_record_trailer_fields,SX_COUNT(sxbx_evtx_record_trailer_fields),SX_LE};
#define SXBX_LIMIT 20000U
static bool sxbx_evtx(sx_context*c){uint64_t n;if(!sxbx_add(c,&sxbx_evtx_header,0)||!sxbx_word(c,42,4,false,&n))return false;if(n>1024)return true;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++){uint64_t p=4096+i*65536,end;if(!sxbx_span(c,p,65536)||!sxbx_word(c,p+48,4,false,&end)||end<512||end>65536)break;if(!sxbx_add(c,&sxbx_evtx_chunk,p)||!sxbx_table(c,&sxbx_evtx_string_offset,p+128,64)||!sxbx_table(c,&sxbx_evtx_template_offset,p+384,32))return false;end+=p;uint64_t q=p+512;while(q<end&&c->count<SXBX_LIMIT){uint64_t magic,z;if(!sxbx_word(c,q,4,false,&magic)||magic!=0x2a2a||!sxbx_word(c,q+4,4,false,&z)||z<28||z%8||z>end-q)break;if(!sxbx_add(c,&sxbx_evtx_record,q)||!sxbx_add(c,&sxbx_evtx_record_trailer,q+z-4))return false;q+=z;}}return true;}
bool sx_windows_evtx_build(sx_context*c)
{
 return sxbx_evtx(c);
}
