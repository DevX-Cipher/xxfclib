/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * microsoft_xsb data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_xsb_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("content_version","uint16",4,2,SX_ID),
 SX_FIELD("tool_version","uint16",6,2,SX_ID),
 SX_FIELD("crc","uint16",8,2,SX_CHECKSUM),
 SX_FIELD("last_modified","uint64",10,8,SX_TIME),
 SX_FIELD("platform","uint8",18,1,SX_ID),
 SX_FIELD("simple_cues","uint16",19,2,SX_COUNT_PROP),
 SX_FIELD("complex_cues","uint16",21,2,SX_COUNT_PROP),
 SX_FIELD("unknown_17","bytes",23,4,SX_NONE),
 SX_FIELD("wave_banks","uint8",27,1,SX_COUNT_PROP),
 SX_FIELD("sounds","uint16",28,2,SX_COUNT_PROP),
 SX_FIELD("cue_name_bytes","uint16",30,2,SX_SIZE),
 SX_FIELD("unknown_20","bytes",32,2,SX_NONE),
 SX_FIELD("simple_cues_offset","uint32",34,4,SX_OFFSET),
 SX_FIELD("complex_cues_offset","uint32",38,4,SX_OFFSET),
 SX_FIELD("cue_names_offset","uint32",42,4,SX_OFFSET),
 SX_FIELD("unknown_offset","uint32",46,4,SX_OFFSET),
 SX_FIELD("variation_tables_offset","uint32",50,4,SX_OFFSET),
 SX_FIELD("transition_tables_offset","uint32",54,4,SX_OFFSET),
 SX_FIELD("wave_bank_names_offset","uint32",58,4,SX_OFFSET),
 SX_FIELD("cue_name_hash_offset","uint32",62,4,SX_OFFSET),
 SX_FIELD("cue_name_index_offset","uint32",66,4,SX_OFFSET),
 SX_FIELD("sounds_offset","uint32",70,4,SX_OFFSET),
 SX_FIELD("bank_name","char[64]",74,64,SX_STRING),
};
const sx_layout sxau_xsb_header={UINT32_C(0x602C000B),"xsb_header",sxau_xsb_header_fields,SX_COUNT(sxau_xsb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_xsb_cue_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("sound_offset","uint32",1,4,SX_OFFSET),
};
const sx_layout sxau_xsb_cue={UINT32_C(0x602C000C),"xsb_cue",sxau_xsb_cue_fields,SX_COUNT(sxau_xsb_cue_fields),SX_LE};
static const xx_data_struct_field_desc sxau_xsb_simple_sound_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("category","uint16",1,2,SX_ID),
 SX_FIELD("volume","uint8",3,1,SX_NONE),
 SX_FIELD("pitch_cents","int16",4,2,SX_NONE),
 SX_FIELD("priority","uint8",6,1,SX_NONE),
 SX_FIELD("sound_length","uint16",7,2,SX_SIZE),
 SX_FIELD("wave_index","uint16",9,2,SX_ID),
 SX_FIELD("wave_bank_index","uint8",11,1,SX_ID),
};
const sx_layout sxau_xsb_simple_sound={UINT32_C(0x602C000D),"xsb_simple_sound",sxau_xsb_simple_sound_fields,SX_COUNT(sxau_xsb_simple_sound_fields),SX_LE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_xsb(sxau_view*v)
{if(!SA_ROW(xsb_header,0,v->n))return false;return sxau_table(v,&sxau_xsb_cue,sxau_u32(v->p+34,false),sxau_u16(v->p+19,false),v->n)&&sxau_table(v,&sxau_xsb_simple_sound,sxau_u32(v->p+70,false),sxau_u16(v->p+28,false),v->n)&&sxau_table(v,&sxau_xact_name,sxau_u32(v->p+58,false),v->p[27],v->n);}
bool sx_microsoft_xsb_build(sxau_view*v)
{
 return sxau_xsb(v);
}
#undef SA_ROW
