/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Reinier 'Rhino' van Vliet's Digital Mugician module (.DMU,.MUG) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_dmu_header_fields[]={
 SX_FIELD("magic","char[24]",0,24,SX_SIGNATURE),
 SX_FIELD("arpeggios_enabled","uint16",24,2,SX_FLAGS),
 SX_FIELD("tracks","uint16",26,2,SX_COUNT_PROP),
 SX_FIELD("sequence_0_count","uint32",28,4,SX_COUNT_PROP),
 SX_FIELD("sequence_1_count","uint32",32,4,SX_COUNT_PROP),
 SX_FIELD("sequence_2_count","uint32",36,4,SX_COUNT_PROP),
 SX_FIELD("sequence_3_count","uint32",40,4,SX_COUNT_PROP),
 SX_FIELD("sequence_4_count","uint32",44,4,SX_COUNT_PROP),
 SX_FIELD("sequence_5_count","uint32",48,4,SX_COUNT_PROP),
 SX_FIELD("sequence_6_count","uint32",52,4,SX_COUNT_PROP),
 SX_FIELD("sequence_7_count","uint32",56,4,SX_COUNT_PROP),
 SX_FIELD("instruments","uint32",60,4,SX_COUNT_PROP),
 SX_FIELD("waveforms","uint32",64,4,SX_COUNT_PROP),
 SX_FIELD("samples","uint32",68,4,SX_COUNT_PROP),
 SX_FIELD("sample_data_bytes","uint32",72,4,SX_SIZE),
};
const sx_layout sxmta_dmu_header={UINT32_C(0x6081005C),"dmu_header",sxmta_dmu_header_fields,SX_COUNT(sxmta_dmu_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_dmu_subsong_fields[]={
 SX_FIELD("loop_enabled","uint8",0,1,SX_FLAGS),
 SX_FIELD("loop_order","uint8",1,1,SX_NONE),
 SX_FIELD("speed","uint8",2,1,SX_NONE),
 SX_FIELD("sequences","uint8",3,1,SX_COUNT_PROP),
 SX_FIELD("name","char[12]",4,12,SX_NONE),
};
const sx_layout sxmta_dmu_subsong={UINT32_C(0x6081005D),"dmu_subsong",sxmta_dmu_subsong_fields,SX_COUNT(sxmta_dmu_subsong_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dmu_sequence_fields[]={
 SX_FIELD("track","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
const sx_layout sxmta_dmu_sequence={UINT32_C(0x6081005E),"dmu_sequence",sxmta_dmu_sequence_fields,SX_COUNT(sxmta_dmu_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dmu_instrument_fields[]={
 SX_FIELD("waveform","uint8",0,1,SX_ID),
 SX_FIELD("loop_words","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("volume","uint8",2,1,SX_NONE),
 SX_FIELD("volume_speed","uint8",3,1,SX_NONE),
 SX_FIELD("arpeggio","uint8",4,1,SX_ID),
 SX_FIELD("pitch","uint8",5,1,SX_NONE),
 SX_FIELD("effect_index","uint8",6,1,SX_ID),
 SX_FIELD("delay","uint8",7,1,SX_NONE),
 SX_FIELD("finetune","uint8",8,1,SX_NONE),
 SX_FIELD("pitch_loop","uint8",9,1,SX_NONE),
 SX_FIELD("pitch_speed","uint8",10,1,SX_NONE),
 SX_FIELD("effect","uint8",11,1,SX_ID),
 SX_FIELD("source_wave1","uint8",12,1,SX_ID),
 SX_FIELD("source_wave2","uint8",13,1,SX_ID),
 SX_FIELD("effect_speed","uint8",14,1,SX_NONE),
 SX_FIELD("volume_loop","uint8",15,1,SX_FLAGS),
};
const sx_layout sxmta_dmu_instrument={UINT32_C(0x6081005F),"dmu_instrument",sxmta_dmu_instrument_fields,SX_COUNT(sxmta_dmu_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dmu_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
const sx_layout sxmta_dmu_event={UINT32_C(0x60810061),"dmu_event",sxmta_dmu_event_fields,SX_COUNT(sxmta_dmu_event_fields),SX_LE};
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_dmu(sxmta_view*v)
{uint64_t end=v->c->size,p=76,ni,nw,ns,nt,n,x,seq=0,arp,total;
 if((!sxmta_eq(v,0," MUGICIAN/SOFTEYES 1990 ",23,end)&&!sxmta_eq(v,0," MUGICIAN2/SOFTEYES 1990",23,end))||!MTA_ROW(dmu_header,0,end)||!sxmta_be(v,24,2,&arp,end)||!sxmta_be(v,26,2,&nt,end)||!sxmta_be(v,60,4,&ni,end)||!sxmta_be(v,64,4,&nw,end)||!sxmta_be(v,68,4,&ns,end)||!sxmta_be(v,72,4,&total,end))return false;
 for(unsigned i=0;i<8;i++){if(!sxmta_be(v,28+i*4,4,&x,end))return false;seq+=x;}
 if(!MTA_TAKE(dmu_subsong,&p,8,end)||!MTA_TAKE(dmu_sequence,&p,seq*4,end)||!MTA_TAKE(dmu_instrument,&p,ni,end)||!sxmta_skip(v,&p,nw*128,end))return false;n=p;
 if(!MTA_TAKE(dmu_sample,&p,ns,end)||!MTA_TAKE(dmu_event,&p,nt*64,end))return false;
 for(uint64_t i=0;i<ns;i++){uint64_t a,b;if(!sxmta_be(v,n+i*32,4,&a,end)||!sxmta_be(v,n+i*32+4,4,&b,end)||a>b||b>total)return false;}
 if(!sxmta_skip(v,&p,total,end)||(arp&&!MTA_TAKE(is_unsigned_value,&p,256,end)))return false;return true;}
bool sx_rhino_digitalmugician_build(sxmta_view*v)
{
 return sxmta_dmu(v);
}
#undef MTA_ROW
#undef MTA_TAKE
