/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Brian Postma's SoundMon module (.BP) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_bp_header_fields[]={
 SX_FIELD("title","char[26]",0,26,SX_NONE),
 SX_FIELD("magic","bytes",26,3,SX_SIGNATURE),
 SX_FIELD("waveforms","uint8",29,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",30,2,SX_COUNT_PROP),
};
const sx_layout sxmta_bp_header={UINT32_C(0x60810066),"bp_header",sxmta_bp_header_fields,SX_COUNT(sxmta_bp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_bp_synth1_fields[]={
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("waveform","uint8",1,1,SX_ID),
 SX_FIELD("waveform_words","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("adsr_control","uint8",4,1,SX_FLAGS),
 SX_FIELD("adsr_table","uint8",5,1,SX_ID),
 SX_FIELD("adsr_length","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("adsr_speed","uint8",8,1,SX_NONE),
 SX_FIELD("lfo_control","uint8",9,1,SX_FLAGS),
 SX_FIELD("lfo_table","uint8",10,1,SX_ID),
 SX_FIELD("lfo_depth","uint8",11,1,SX_NONE),
 SX_FIELD("lfo_length","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("unused1","uint8",14,1,SX_NONE),
 SX_FIELD("lfo_delay","uint8",15,1,SX_NONE),
 SX_FIELD("lfo_speed","uint8",16,1,SX_NONE),
 SX_FIELD("envelope_control","uint8",17,1,SX_FLAGS),
 SX_FIELD("envelope_table","uint8",18,1,SX_ID),
 SX_FIELD("unused2","uint8",19,1,SX_NONE),
 SX_FIELD("envelope_length","uint16",20,2,SX_COUNT_PROP),
 SX_FIELD("unused3","uint8",22,1,SX_NONE),
 SX_FIELD("envelope_delay","uint8",23,1,SX_NONE),
 SX_FIELD("envelope_speed","uint8",24,1,SX_NONE),
 SX_FIELD("volume","uint8",25,1,SX_NONE),
 SX_FIELD("unused4","bytes",26,6,SX_NONE),
};
const sx_layout sxmta_bp_synth1={UINT32_C(0x60810068),"bp_synth1",sxmta_bp_synth1_fields,SX_COUNT(sxmta_bp_synth1_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_bp_synth2_fields[]={
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("waveform","uint8",1,1,SX_ID),
 SX_FIELD("waveform_words","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("adsr_control","uint8",4,1,SX_FLAGS),
 SX_FIELD("adsr_table","uint8",5,1,SX_ID),
 SX_FIELD("adsr_length","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("adsr_speed","uint8",8,1,SX_NONE),
 SX_FIELD("lfo_control","uint8",9,1,SX_FLAGS),
 SX_FIELD("lfo_table","uint8",10,1,SX_ID),
 SX_FIELD("lfo_depth","uint8",11,1,SX_NONE),
 SX_FIELD("lfo_length","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("lfo_delay","uint8",14,1,SX_NONE),
 SX_FIELD("lfo_speed","uint8",15,1,SX_NONE),
 SX_FIELD("envelope_control","uint8",16,1,SX_FLAGS),
 SX_FIELD("envelope_table","uint8",17,1,SX_ID),
 SX_FIELD("envelope_length","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("envelope_delay","uint8",20,1,SX_NONE),
 SX_FIELD("envelope_speed","uint8",21,1,SX_NONE),
 SX_FIELD("effect_control","uint8",22,1,SX_FLAGS),
 SX_FIELD("effect_speed","uint8",23,1,SX_NONE),
 SX_FIELD("effect_delay","uint8",24,1,SX_NONE),
 SX_FIELD("modulation_control","uint8",25,1,SX_FLAGS),
 SX_FIELD("modulation_table","uint8",26,1,SX_ID),
 SX_FIELD("modulation_speed","uint8",27,1,SX_NONE),
 SX_FIELD("modulation_delay","uint8",28,1,SX_NONE),
 SX_FIELD("volume","uint8",29,1,SX_NONE),
 SX_FIELD("modulation_length","uint16",30,2,SX_COUNT_PROP),
};
const sx_layout sxmta_bp_synth2={UINT32_C(0x60810069),"bp_synth2",sxmta_bp_synth2_fields,SX_COUNT(sxmta_bp_synth2_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_bp_step_fields[]={
 SX_FIELD("track","uint16",0,2,SX_ID),
 SX_FIELD("sound_transpose","int8",2,1,SX_NONE),
 SX_FIELD("note_transpose","int8",3,1,SX_NONE),
};
const sx_layout sxmta_bp_step={UINT32_C(0x6081006A),"bp_step",sxmta_bp_step_fields,SX_COUNT(sxmta_bp_step_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_bp_event_fields[]={
 SX_FIELD("note","int8",0,1,SX_NONE),
 SX_FIELD("instrument_option","uint8",1,1,SX_FLAGS),
 SX_FIELD("parameter","uint8",2,1,SX_NONE),
};
const sx_layout sxmta_bp_event={UINT32_C(0x6081006B),"bp_event",sxmta_bp_event_fields,SX_COUNT(sxmta_bp_event_fields),SX_LE};
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_bp(sxmta_view*v)
{uint64_t end=v->c->size,p=32,ver,waves,orders,x,total=0,tracks=0;
 if(!sxmta_eq(v,26,"V.",2,end)||!sxmta_u(v,28,1,&ver,end)||(ver!='2'&&ver!='3')||!sxmta_u(v,29,1,&waves,end)||!sxmta_be(v,30,2,&orders,end)||!MTA_ROW(bp_header,0,end))return false;
 for(unsigned i=0;i<15;i++){if(!sxmta_u(v,p,1,&x,end))return false;if(x==255){if(!sxmta_take(v,ver=='2'?&sxmta_bp_synth1:&sxmta_bp_synth2,&p,1,end))return false;}else{if(!sxmta_be(v,p+24,2,&x,end)||!MTA_TAKE(bp_sample,&p,1,end))return false;total+=2*x;}}
 for(uint64_t i=0;i<orders*4;i++){if(!sxmta_be(v,p,2,&x,end)||!MTA_TAKE(bp_step,&p,1,end))return false;if(x>tracks)tracks=x;}
 if(!MTA_TAKE(bp_event,&p,tracks*16,end)||!sxmta_skip(v,&p,waves*64,end))return false;return sxmta_span(v,p,total,end);}
bool sx_postma_soundmon_bp_build(sxmta_view*v)
{
 return sxmta_bp(v);
}
#undef MTA_ROW
#undef MTA_TAKE
