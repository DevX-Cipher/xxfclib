/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * braintracedesign_synthesis data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_syn_sample_name_fields[]={
 SX_FIELD("unknown","uint8",0,1,SX_NONE),
 SX_FIELD("name","char[27]",1,27,SX_NONE),
};
const sx_layout sxnextm_syn_sample_name={UINT32_C(0x608B0036),"syn_sample_name",sxnextm_syn_sample_name_fields,SX_COUNT(sxnextm_syn_sample_name_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_syn_instrument_fields[]={
 SX_FIELD("waveform","uint8",0,1,SX_ID),
 SX_FIELD("synthesis","uint8",1,1,SX_FLAGS),
 SX_FIELD("waveform_length","uint16",2,2,SX_NONE),
 SX_FIELD("repeat_length","uint16",4,2,SX_NONE),
 SX_FIELD("volume","uint8",6,1,SX_NONE),
 SX_FIELD("portamento_speed","int8",7,1,SX_NONE),
 SX_FIELD("adsr_enabled","uint8",8,1,SX_FLAGS),
 SX_FIELD("adsr_table","uint8",9,1,SX_ID),
 SX_FIELD("adsr_length","uint16",10,2,SX_NONE),
 SX_FIELD("unknown","uint8",12,1,SX_NONE),
 SX_FIELD("arpeggio_start","uint8",13,1,SX_NONE),
 SX_FIELD("arpeggio_length","uint8",14,1,SX_NONE),
 SX_FIELD("arpeggio_repeat_length","uint8",15,1,SX_NONE),
 SX_FIELD("effect","uint8",16,1,SX_ID),
 SX_FIELD("argument1","uint8",17,1,SX_NONE),
 SX_FIELD("argument2","uint8",18,1,SX_NONE),
 SX_FIELD("argument3","uint8",19,1,SX_NONE),
 SX_FIELD("vibrato_delay","uint8",20,1,SX_NONE),
 SX_FIELD("vibrato_speed","uint8",21,1,SX_NONE),
 SX_FIELD("vibrato_level","uint8",22,1,SX_NONE),
 SX_FIELD("envelope_counter_offset","uint8",23,1,SX_NONE),
 SX_FIELD("envelope_counter_mode","uint8",24,1,SX_ID),
 SX_FIELD("envelope_table","uint8",25,1,SX_ID),
 SX_FIELD("envelope_table_length","uint16",26,2,SX_NONE),
};
const sx_layout sxnextm_syn_instrument={UINT32_C(0x608B0037),"syn_instrument",sxnextm_syn_instrument_fields,SX_COUNT(sxnextm_syn_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_syn_subsong_fields[]={
 SX_FIELD("unknown0","bytes",0,4,SX_NONE),
 SX_FIELD("speed","uint8",4,1,SX_NONE),
 SX_FIELD("rows_per_track","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("first_position","uint16",6,2,SX_ID),
 SX_FIELD("last_position","uint16",8,2,SX_ID),
 SX_FIELD("restart_position","uint16",10,2,SX_ID),
 SX_FIELD("unknown_tail","bytes",12,2,SX_NONE),
};
const sx_layout sxnextm_syn_subsong={UINT32_C(0x608B0038),"syn_subsong",sxnextm_syn_subsong_fields,SX_COUNT(sxnextm_syn_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_syn_position_fields[]={
 SX_FIELD("first_track_row","uint16",0,2,SX_ID),
 SX_FIELD("instrument_transpose","int8",2,1,SX_NONE),
 SX_FIELD("note_transpose","int8",3,1,SX_NONE),
};
const sx_layout sxnextm_syn_position={UINT32_C(0x608B0039),"syn_position",sxnextm_syn_position_fields,SX_COUNT(sxnextm_syn_position_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_syn_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("arpeggio_and_effect","uint8",2,1,SX_FLAGS),
 SX_FIELD("argument","uint8",3,1,SX_NONE),
};
const sx_layout sxnextm_syn_event={UINT32_C(0x608B003A),"syn_event",sxnextm_syn_event_fields,SX_COUNT(sxnextm_syn_event_fields),SX_LE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
#define NX_TAKE(l,p,n,end) sxnextm_take(v,&sxnextm_##l,(p),(n),(end))
static bool sxnextm_syn(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,b=0,p,rows,positions,n[6];if(!sxnextm_eq(v,0,"Synth4.0",8,e)){b=0x1f0e;if(!sxnextm_eq(v,b,"Synth4.2",8,e))return false;}
 if(!NX_ROW(syn_header,b,e)||!sxnextm_be(v,b+8,2,&positions,e)||!sxnextm_be(v,b+10,2,&rows,e))return false;for(unsigned i=0;i<6;i++)if(!sxnextm_u(v,b+16+i,1,&n[i],e))return false;p=b+204;
 if(!NX_TAKE(syn_sample_name,&p,n[0],e)||!NX_TAKE(bytes32,&p,n[0],e)||!NX_TAKE(u8,&p,n[4]*128+n[5]*256,e)||!NX_TAKE(syn_instrument,&p,n[2],e)||!NX_TAKE(u8,&p,256,e)||!NX_TAKE(syn_subsong,&p,n[3],e)||!sxnextm_skip(v,&p,14+n[1]*256,e)||!NX_TAKE(syn_position,&p,positions*4,e)||!NX_TAKE(syn_event,&p,rows+64,e))return false;return true;}
bool sx_braintracedesign_synthesis_build(sxnextm_view*v)
{
 return sxnextm_syn(v);
}
#undef NX_ROW
#undef NX_TAKE
