/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SEG-2 seismic data data structures, moved out of the sciencemeta schema family. */
#include "../../xx_format_schema_sciencemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsc_seg2_file_header_le_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("revision","uint16",2,2,SX_ID),
    SX_FIELD("trace_pointer_size","uint16",4,2,SX_SIZE),
    SX_FIELD("trace_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("string_terminator_size","uint8",8,1,SX_SIZE),
    SX_FIELD("string_terminator","uint8[2]",9,2,SX_NONE),
    SX_FIELD("line_terminator_size","uint8",11,1,SX_SIZE),
    SX_FIELD("line_terminator","uint8[2]",12,2,SX_NONE),
    SX_FIELD("reserved","uint8[18]",14,18,SX_RESERVED),
};
const sx_layout sxsc_seg2_file_header_le = {UINT32_C(0x60280012),"seg2_file_header_le",sxsc_seg2_file_header_le_fields,SX_COUNT(sxsc_seg2_file_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_seg2_trace_pointer_le_fields[] = {
    SX_FIELD("trace_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxsc_seg2_trace_pointer_le = {UINT32_C(0x60280013),"seg2_trace_pointer_le",sxsc_seg2_trace_pointer_le_fields,SX_COUNT(sxsc_seg2_trace_pointer_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_seg2_string_length_le_fields[] = {
    SX_FIELD("record_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxsc_seg2_string_length_le = {UINT32_C(0x60280015),"seg2_string_length_le",sxsc_seg2_string_length_le_fields,SX_COUNT(sxsc_seg2_string_length_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_seg2_file_header_be_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("revision","uint16",2,2,SX_ID),
    SX_FIELD("trace_pointer_size","uint16",4,2,SX_SIZE),
    SX_FIELD("trace_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("string_terminator_size","uint8",8,1,SX_SIZE),
    SX_FIELD("string_terminator","uint8[2]",9,2,SX_NONE),
    SX_FIELD("line_terminator_size","uint8",11,1,SX_SIZE),
    SX_FIELD("line_terminator","uint8[2]",12,2,SX_NONE),
    SX_FIELD("reserved","uint8[18]",14,18,SX_RESERVED),
};
const sx_layout sxsc_seg2_file_header_be = {UINT32_C(0x60280016),"seg2_file_header_be",sxsc_seg2_file_header_be_fields,SX_COUNT(sxsc_seg2_file_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_seg2_trace_pointer_be_fields[] = {
    SX_FIELD("trace_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxsc_seg2_trace_pointer_be = {UINT32_C(0x60280017),"seg2_trace_pointer_be",sxsc_seg2_trace_pointer_be_fields,SX_COUNT(sxsc_seg2_trace_pointer_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsc_seg2_string_length_be_fields[] = {
    SX_FIELD("record_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxsc_seg2_string_length_be = {UINT32_C(0x60280019),"seg2_string_length_be",sxsc_seg2_string_length_be_fields,SX_COUNT(sxsc_seg2_string_length_be_fields),SX_BE};
static bool sxsc_seg2_strings(sx_context *c,int64_t at,int64_t end,bool be)
{
 for(unsigned i=0;at<end;i++){uint16_t n;if(i>=512||end-at<2||!sx_u16(c,at,be,&n)||!sxsc_add(c,be?&sxsc_seg2_string_length_be:&sxsc_seg2_string_length_le,at,2))return false;if(!n)return true;if(n<3||n>end-at)return false;at+=n;}return true;
}
static bool sxsc_seg2(sx_context *c)
{
 uint8_t b[32];if(!sx_read(c,0,b,32))return false;bool be=sxsc16(b,true)==0x3a55;if(!be&&sxsc16(b,false)!=0x3a55)return false;
 uint32_t count=sxsc16(b+6,be),pointers=sxsc16(b+4,be),first;if(!count||count>1024||pointers!=count*4||!sxsc_add(c,be?&sxsc_seg2_file_header_be:&sxsc_seg2_file_header_le,0,32)||!sxsc_table(c,be?&sxsc_seg2_trace_pointer_be:&sxsc_seg2_trace_pointer_le,32,4,count)||!sx_u32(c,32,be,&first)||first<32+pointers||!sxsc_span(c,0,first)||!sxsc_seg2_strings(c,32+pointers,first,be))return false;
 for(uint32_t i=0;i<count;i++){
  uint32_t pos;if(!sx_u32(c,32+(int64_t)i*4,be,&pos)||!sx_read(c,pos,b,32)||sxsc16(b,be)!=0x4422)return false;uint32_t header=sxsc16(b+2,be),bytes=sxsc32(b+4,be);
  if(header<34||!sxsc_span(c,pos,(uint64_t)header+bytes)||!sxsc_add(c,be?&sxsc_seg2_trace_header_be:&sxsc_seg2_trace_header_le,pos,32)||!sxsc_seg2_strings(c,(int64_t)pos+32,(int64_t)pos+header,be))return false;
 }return true;
}
bool sx_seismic_seg2_build(sx_context*c)
{
 return sxsc_seg2(c);
}
