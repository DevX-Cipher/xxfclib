/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sony_vab data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_vab_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("bank_id","uint32",8,4,SX_ID),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
 SX_FIELD("reserved","uint16",16,2,SX_RESERVED),
 SX_FIELD("program_count","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("tone_count","uint16",20,2,SX_COUNT_PROP),
 SX_FIELD("sample_count","uint16",22,2,SX_COUNT_PROP),
 SX_FIELD("master_volume","uint8",24,1,SX_NONE),
 SX_FIELD("master_pan","uint8",25,1,SX_NONE),
 SX_FIELD("bank_attributes1","uint8",26,1,SX_FLAGS),
 SX_FIELD("bank_attributes2","uint8",27,1,SX_FLAGS),
 SX_FIELD("reserved2","uint32",28,4,SX_RESERVED),
};
const sx_layout sxau_vab_header={UINT32_C(0x602C0049),"vab_header",sxau_vab_header_fields,SX_COUNT(sxau_vab_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vab_program_fields[]={
 SX_FIELD("tone_count","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("master_volume","uint8",1,1,SX_NONE),
 SX_FIELD("priority","uint8",2,1,SX_NONE),
 SX_FIELD("mode","uint8",3,1,SX_FLAGS),
 SX_FIELD("pan","uint8",4,1,SX_NONE),
 SX_FIELD("reserved","bytes",5,11,SX_RESERVED),
};
const sx_layout sxau_vab_program={UINT32_C(0x602C004A),"vab_program",sxau_vab_program_fields,SX_COUNT(sxau_vab_program_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vab_tone_fields[]={
 SX_FIELD("priority","uint8",0,1,SX_NONE),
 SX_FIELD("mode","uint8",1,1,SX_FLAGS),
 SX_FIELD("volume","uint8",2,1,SX_NONE),
 SX_FIELD("pan","uint8",3,1,SX_NONE),
 SX_FIELD("center_note","uint8",4,1,SX_NONE),
 SX_FIELD("pitch_shift","uint8",5,1,SX_NONE),
 SX_FIELD("minimum_note","uint8",6,1,SX_NONE),
 SX_FIELD("maximum_note","uint8",7,1,SX_NONE),
 SX_FIELD("vibrato_width","uint8",8,1,SX_NONE),
 SX_FIELD("vibrato_time","uint8",9,1,SX_NONE),
 SX_FIELD("portamento_width","uint8",10,1,SX_NONE),
 SX_FIELD("portamento_time","uint8",11,1,SX_NONE),
 SX_FIELD("pitch_bend_min","uint8",12,1,SX_NONE),
 SX_FIELD("pitch_bend_max","uint8",13,1,SX_NONE),
 SX_FIELD("reserved","bytes",14,2,SX_RESERVED),
 SX_FIELD("adsr1","uint16",16,2,SX_FLAGS),
 SX_FIELD("adsr2","uint16",18,2,SX_FLAGS),
 SX_FIELD("program_index","uint16",20,2,SX_ID),
 SX_FIELD("sample_index","uint16",22,2,SX_ID),
 SX_FIELD("reserved2","bytes",24,8,SX_RESERVED),
};
const sx_layout sxau_vab_tone={UINT32_C(0x602C004B),"vab_tone",sxau_vab_tone_fields,SX_COUNT(sxau_vab_tone_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vab_sample_size_fields[]={
 SX_FIELD("size_in_8byte_units","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxau_vab_sample_size={UINT32_C(0x602C004C),"vab_sample_size",sxau_vab_sample_size_fields,SX_COUNT(sxau_vab_sample_size_fields),SX_LE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_vab(sxau_view*v)
{if(!SA_ROW(vab_header,0,v->n)||!sxau_table(v,&sxau_vab_program,32,128,v->n))return false;size_t programs=sxau_u16(v->p+18,false),at=2080;if(programs>128||!sxau_table(v,&sxau_vab_tone,at,programs*16,v->n))return false;at+=programs*512;return sxau_table(v,&sxau_vab_sample_size,at,256,v->n);}
bool sx_sony_vab_build(sxau_view*v)
{
 return sxau_vab(v);
}
#undef SA_ROW
