/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * meyrignac_pumatracker data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_puma_position_fields[]={
 SX_FIELD("channel0_track","uint8",0,1,SX_ID),
 SX_FIELD("channel0_instrument_transpose","int8",1,1,SX_NONE),
 SX_FIELD("channel0_note_transpose","int8",2,1,SX_NONE),
 SX_FIELD("channel1_track","uint8",3,1,SX_ID),
 SX_FIELD("channel1_instrument_transpose","int8",4,1,SX_NONE),
 SX_FIELD("channel1_note_transpose","int8",5,1,SX_NONE),
 SX_FIELD("channel2_track","uint8",6,1,SX_ID),
 SX_FIELD("channel2_instrument_transpose","int8",7,1,SX_NONE),
 SX_FIELD("channel2_note_transpose","int8",8,1,SX_NONE),
 SX_FIELD("channel3_track","uint8",9,1,SX_ID),
 SX_FIELD("channel3_instrument_transpose","int8",10,1,SX_NONE),
 SX_FIELD("channel3_note_transpose","int8",11,1,SX_NONE),
 SX_FIELD("speed","uint8",12,1,SX_NONE),
 SX_FIELD("unknown","uint8",13,1,SX_NONE),
};
const sx_layout sxnextm_puma_position={UINT32_C(0x608B0060),"puma_position",sxnextm_puma_position_fields,SX_COUNT(sxnextm_puma_position_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_puma_marker_fields[]={
 SX_FIELD("marker","bytes",0,4,SX_ID),
};
const sx_layout sxnextm_puma_marker={UINT32_C(0x608B0061),"puma_marker",sxnextm_puma_marker_fields,SX_COUNT(sxnextm_puma_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_puma_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument_and_effect","uint8",1,1,SX_FLAGS),
 SX_FIELD("argument","uint8",2,1,SX_NONE),
 SX_FIELD("rows_to_wait","uint8",3,1,SX_COUNT_PROP),
};
const sx_layout sxnextm_puma_event={UINT32_C(0x608B0062),"puma_event",sxnextm_puma_event_fields,SX_COUNT(sxnextm_puma_event_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_puma_command_fields[]={
 SX_FIELD("command","uint8",0,1,SX_ID),
 SX_FIELD("argument1","uint8",1,1,SX_NONE),
 SX_FIELD("argument2","uint8",2,1,SX_NONE),
 SX_FIELD("argument3","uint8",3,1,SX_NONE),
};
const sx_layout sxnextm_puma_command={UINT32_C(0x608B0063),"puma_command",sxnextm_puma_command_fields,SX_COUNT(sxnextm_puma_command_fields),SX_LE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
#define NX_TAKE(l,p,n,end) sxnextm_take(v,&sxnextm_##l,(p),(n),(end))
static bool sxnextm_puma(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,n,tracks,ins,p=80;
 if(!NX_ROW(puma_header,0,e)||!sxnextm_be(v,12,2,&n,e)||!sxnextm_be(v,14,2,&tracks,e)||!sxnextm_be(v,16,2,&ins,e)||!NX_TAKE(puma_position,&p,n+1,e))return false;
 for(uint64_t i=0;i<tracks;i++){if(!sxnextm_eq(v,p,"patt",4,e)||!NX_TAKE(puma_marker,&p,1,e))return false;uint64_t rows=0;unsigned count=0;while(rows<32){uint64_t wait;if(count++>=65536||!sxnextm_u(v,p+3,1,&wait,e)||!NX_TAKE(puma_event,&p,1,e))return false;rows+=wait;}}
 if(!sxnextm_eq(v,p,"patt",4,e)||!NX_TAKE(puma_marker,&p,1,e))return false;
 for(uint64_t i=0;i<ins;i++)for(unsigned kind=0;kind<2;kind++){if(!sxnextm_eq(v,p,kind?"insf":"inst",4,e)||!NX_TAKE(puma_marker,&p,1,e))return false;for(unsigned j=0;;j++){uint64_t op;if(j>=65536||!sxnextm_u(v,p,1,&op,e))return false;if(sxnextm_eq(v,p,"inst",4,e))break;if(!NX_TAKE(puma_command,&p,1,e))return false;if(op==0xe0||op==0xb0)break;}}
 if(p<e&&sxnextm_eq(v,p,"inst",4,e)&&!NX_ROW(puma_marker,p,e))return false;return true;}
bool sx_meyrignac_pumatracker_build(sxnextm_view*v)
{
 return sxnextm_puma(v);
}
#undef NX_ROW
#undef NX_TAKE
