/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Krister Wombell's ChipTracker module (.KRIS,.MOD) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_kris_title_fields[]={
 SX_FIELD("title","char[22]",0,22,SX_NONE),
};
const sx_layout sxmta_kris_title={UINT32_C(0x6081002B),"kris_title",sxmta_kris_title_fields,SX_COUNT(sxmta_kris_title_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_kris_sample_fields[]={
 SX_FIELD("name","char[22]",0,22,SX_NONE),
 SX_FIELD("sample_words","uint16",22,2,SX_COUNT_PROP),
 SX_FIELD("finetune","uint8",24,1,SX_NONE),
 SX_FIELD("volume","uint8",25,1,SX_NONE),
 SX_FIELD("loop_start_words","uint16",26,2,SX_NONE),
 SX_FIELD("loop_words","uint16",28,2,SX_COUNT_PROP),
};
const sx_layout sxmta_kris_sample={UINT32_C(0x6081002C),"kris_sample",sxmta_kris_sample_fields,SX_COUNT(sxmta_kris_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_kris_synth_fields[]={
 SX_FIELD("synth_parameters","bytes",0,30,SX_NONE),
};
const sx_layout sxmta_kris_synth={UINT32_C(0x6081002D),"kris_synth",sxmta_kris_synth_fields,SX_COUNT(sxmta_kris_synth_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_kris_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("orders","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("restart_order","uint8",5,1,SX_NONE),
};
const sx_layout sxmta_kris_header={UINT32_C(0x6081002E),"kris_header",sxmta_kris_header_fields,SX_COUNT(sxmta_kris_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_kris_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
const sx_layout sxmta_kris_event={UINT32_C(0x60810030),"kris_event",sxmta_kris_event_fields,SX_COUNT(sxmta_kris_event_fields),SX_LE};
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_kris(sxmta_view*v)
{uint64_t end=v->c->size,p=22,x,y,total=0,waves=0,orders,np=1;
 if(!MTA_ROW(kris_title,0,end))return false;
 for(unsigned i=0;i<31;i++){if(!sxmta_u(v,p,1,&x,end))return false;if(x){if(!sxmta_be(v,p+22,2,&x,end)||!MTA_TAKE(kris_sample,&p,1,end))return false;total+=2*x;}else{unsigned a[4]={1,5,10,19};for(unsigned j=0;j<4;j++){if(!sxmta_u(v,p+a[j],1,&x,end))return false;if(x&&x>=waves)waves=x+1;}if(!MTA_TAKE(kris_synth,&p,1,end))return false;}}
 if(!sxmta_eq(v,p,"KRIS",4,end)||!sxmta_u(v,p+4,1,&orders,end)||orders>128||!MTA_TAKE(kris_header,&p,1,end))return false;
 for(uint64_t i=0;i<orders*4;i++){if(!sxmta_u(v,p+2*i,1,&x,end))return false;if(x>=np)np=x+1;}
 if(!MTA_TAKE(kris_track_ref,&p,512,end)||!sxmta_skip(v,&p,2+waves*64,end)||!MTA_TAKE(kris_event,&p,np*64,end))return false;y=total;return sxmta_span(v,p,y,end);}
bool sx_wombell_chiptracker_kris_build(sxmta_view*v)
{
 return sxmta_kris(v);
}
#undef MTA_ROW
#undef MTA_TAKE
