/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * wilenius_fmkingtracker data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_offset32le_fields[]={
 SX_FIELD("offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxnextm_offset32le={UINT32_C(0x608B003D),"offset32le",sxnextm_offset32le_fields,SX_COUNT(sxnextm_offset32le_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_instrument_fields[]={
 SX_FIELD("unknown","bytes",0,39,SX_NONE),
 SX_FIELD("opl_20","uint8",39,1,SX_FLAGS),
 SX_FIELD("opl_23","uint8",40,1,SX_FLAGS),
 SX_FIELD("opl_40","uint8",41,1,SX_FLAGS),
 SX_FIELD("opl_43","uint8",42,1,SX_FLAGS),
 SX_FIELD("opl_60","uint8",43,1,SX_FLAGS),
 SX_FIELD("opl_63","uint8",44,1,SX_FLAGS),
 SX_FIELD("opl_80","uint8",45,1,SX_FLAGS),
 SX_FIELD("opl_83","uint8",46,1,SX_FLAGS),
 SX_FIELD("opl_e0","uint8",47,1,SX_FLAGS),
 SX_FIELD("opl_e3","uint8",48,1,SX_FLAGS),
 SX_FIELD("opl_c0","uint8",49,1,SX_FLAGS),
};
const sx_layout sxnextm_fmk_instrument={UINT32_C(0x608B0044),"fmk_instrument",sxnextm_fmk_instrument_fields,SX_COUNT(sxnextm_fmk_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_note_fields[]={
 SX_FIELD("packed_note","uint8",0,1,SX_FLAGS),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
};
const sx_layout sxnextm_fmk_note={UINT32_C(0x608B0047),"fmk_note",sxnextm_fmk_note_fields,SX_COUNT(sxnextm_fmk_note_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_volume_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
};
const sx_layout sxnextm_fmk_volume={UINT32_C(0x608B0048),"fmk_volume",sxnextm_fmk_volume_fields,SX_COUNT(sxnextm_fmk_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_effect_fields[]={
 SX_FIELD("effect","uint8",0,1,SX_ID),
 SX_FIELD("argument","uint8",1,1,SX_NONE),
};
const sx_layout sxnextm_fmk_effect={UINT32_C(0x608B0049),"fmk_effect",sxnextm_fmk_effect_fields,SX_COUNT(sxnextm_fmk_effect_fields),SX_LE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
#define NX_TAKE(l,p,n,end) sxnextm_take(v,&sxnextm_##l,(p),(n),(end))
static bool sxnextm_fmk(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,p=82,t,no,ni,np,inst,pat,z,off;
 if(!sxnextm_eq(v,0,"FMK!",4,e)||!NX_ROW(fmk_header,0,e)||!sxnextm_u(v,61,1,&t,e)||!sxnextm_u(v,74,1,&no,e)||!sxnextm_u(v,75,1,&ni,e)||!sxnextm_u(v,76,1,&np,e)||!NX_TAKE(fmk_track_setting,&p,t>=2?18:20,e)||!NX_TAKE(order8,&p,no,e)||!NX_TAKE(offset16le,&p,1,e))return false;
 inst=p;if(!NX_TAKE(offset16le,&p,ni,e))return false;pat=p;if(!NX_TAKE(offset32le,&p,np,e))return false;
 for(uint64_t i=0;i<ni;i++){if(!sxnextm_u(v,inst+i*2,2,&off,e))return false;if(off&&!NX_ROW(fmk_instrument,off,e))return false;}
 for(uint64_t i=0;i<np;i++){if(!sxnextm_u(v,pat+i*4,4,&off,e))return false;if(!off)continue;if(!sxnextm_u(v,off,2,&z,e)||!NX_ROW(fmk_pattern,off,e)||!sxnextm_span(v,off+2,z,e))return false;uint64_t q=off+2,end=q+z,rows=0;
 while(q<end&&rows<64){uint64_t c;if(!sxnextm_u(v,q,1,&c,end)||!NX_TAKE(fmk_control,&q,1,end))return false;if(!c){rows++;continue;}if((c&32)&&!NX_TAKE(fmk_note,&q,1,end))return false;if((c&64)&&!NX_TAKE(fmk_volume,&q,1,end))return false;if((c&128)&&!NX_TAKE(fmk_effect,&q,1,end))return false;}}
 return true;}
bool sx_wilenius_fmkingtracker_build(sxnextm_view*v)
{
 return sxnextm_fmk(v);
}
#undef NX_ROW
#undef NX_TAKE
