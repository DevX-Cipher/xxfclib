/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * microsoft_xwb data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_xwb_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("header_version","uint32",8,4,SX_ID),
};
const sx_layout sxau_xwb_header={UINT32_C(0x602C0006),"xwb_header",sxau_xwb_header_fields,SX_COUNT(sxau_xwb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_xwb_segment_fields[]={
 SX_FIELD("segment_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("segment_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxau_xwb_segment={UINT32_C(0x602C0007),"xwb_segment",sxau_xwb_segment_fields,SX_COUNT(sxau_xwb_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxau_xwb_bank_data_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("entry_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("bank_name","char[64]",8,64,SX_STRING),
 SX_FIELD("metadata_entry_size","uint32",72,4,SX_SIZE),
 SX_FIELD("name_entry_size","uint32",76,4,SX_SIZE),
 SX_FIELD("alignment","uint32",80,4,SX_SIZE),
 SX_FIELD("compact_format","uint32",84,4,SX_FLAGS),
 SX_FIELD("build_time","uint64",88,8,SX_TIME),
};
const sx_layout sxau_xwb_bank_data={UINT32_C(0x602C0008),"xwb_bank_data",sxau_xwb_bank_data_fields,SX_COUNT(sxau_xwb_bank_data_fields),SX_LE};
static const xx_data_struct_field_desc sxau_xwb_entry_fields[]={
 SX_FIELD("flags_and_duration","uint32",0,4,SX_FLAGS),
 SX_FIELD("mini_wave_format","uint32",4,4,SX_FLAGS),
 SX_FIELD("play_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("play_length","uint32",12,4,SX_SIZE),
 SX_FIELD("loop_start_samples","uint32",16,4,SX_NONE),
 SX_FIELD("loop_length_samples","uint32",20,4,SX_COUNT_PROP),
};
const sx_layout sxau_xwb_entry={UINT32_C(0x602C0009),"xwb_entry",sxau_xwb_entry_fields,SX_COUNT(sxau_xwb_entry_fields),SX_LE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_xwb(sxau_view*v)
{if(!SA_ROW(xwb_header,0,v->n)||!sxau_table(v,&sxau_xwb_segment,12,5,v->n))return false;size_t bank=sxau_u32(v->p+12,false),meta=sxau_u32(v->p+20,false),names=sxau_u32(v->p+36,false);if(!SA_ROW(xwb_bank_data,bank,v->n))return false;uint32_t n=sxau_u32(v->p+bank+4,false);if(!sxau_table(v,&sxau_xwb_entry,meta,n,v->n))return false;return !sxau_u32(v->p+40,false)||sxau_table(v,&sxau_xact_name,names,n,v->n);}
bool sx_microsoft_xwb_build(sxau_view*v)
{
 return sxau_xwb(v);
}
#undef SA_ROW
