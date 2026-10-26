/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Niklas 'pascal' Beisert's MXMplay module (.MXM) data structures, moved out of the musicremaining schema family. */
#include "../../../xx_format_schema_musicremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmr_instrument_offset_fields[]={
 SX_FIELD("instrument_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxmr_instrument_offset={UINT32_C(0x607D001A),"instrument_offset",sxmr_instrument_offset_fields,SX_COUNT(sxmr_instrument_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_mxm_pattern_fields[]={
 SX_FIELD("rows","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmr_mxm_pattern={UINT32_C(0x607D0021),"mxm_pattern",sxmr_mxm_pattern_fields,SX_COUNT(sxmr_mxm_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_mxm_note_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
};
const sx_layout sxmr_mxm_note={UINT32_C(0x607D0023),"mxm_note",sxmr_mxm_note_fields,SX_COUNT(sxmr_mxm_note_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_mxm_volume_fields[]={
 SX_FIELD("volume_effect","uint8",0,1,SX_NONE),
};
const sx_layout sxmr_mxm_volume={UINT32_C(0x607D0024),"mxm_volume",sxmr_mxm_volume_fields,SX_COUNT(sxmr_mxm_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_mxm_effect_fields[]={
 SX_FIELD("effect","uint8",0,1,SX_ID),
 SX_FIELD("parameter","uint8",1,1,SX_NONE),
};
const sx_layout sxmr_mxm_effect={UINT32_C(0x607D0025),"mxm_effect",sxmr_mxm_effect_fields,SX_COUNT(sxmr_mxm_effect_fields),SX_LE};
#define MR_ROW(l,at,end) sxmr_row(v,&sxmr_##l,(at),(end))
static bool sxmr_mxm(sxmr_view*v)
{uint64_t end=v->c->size,np,ni,ch,orders,restart,p,at,n,rows,flags,sm,b8,b16;
 if(!sxmr_eq(v,0,"MXM\0",4,end)||!sxmr_u(v,4,4,&orders,end)||!orders||orders>256||!sxmr_u(v,8,4,&restart,end)||restart>=orders||!sxmr_u(v,12,4,&ch,end)||!ch||ch>32||!sxmr_u(v,16,4,&np,end)||!np||np>256||!sxmr_u(v,20,4,&ni,end)||ni>128||!sxmr_u(v,28,4,&sm,end)||!sxmr_u(v,32,4,&b8,end)||!sxmr_u(v,36,4,&b16,end)||!MR_ROW(mxm_header,0,end))return false;
 if(!sxmr_table(v,&sxmr_order8,80,256,end)||!sxmr_table(v,&sxmr_instrument_offset,336,128,end)||!sxmr_table(v,&sxmr_pattern_offset,848,256,end)||!sxmr_span(v,sm,b8+2*b16,end))return false;
 for(uint64_t i=0;i<ni;i++){if(!sxmr_u(v,336+i*4,4,&at,end)||!at||!sxmr_u(v,at,4,&n,end)||n>256||!MR_ROW(mxm_instrument,at,end)||!sxmr_table(v,&sxmr_mxm_sample,at+256,n,end))return false;}
 for(uint64_t i=0;i<np;i++){if(!sxmr_u(v,848+i*4,4,&at,end)||!at||!sxmr_u(v,at,4,&rows,end)||!rows||rows>65535||!MR_ROW(mxm_pattern,at,end))return false;p=at+4;
  for(uint64_t r=0;r<rows;r++){for(;;){if(!sxmr_u(v,p,1,&flags,end)||!MR_ROW(mxm_event_flags,p,end))return false;p++;if(!flags)break;if(!(flags&224)||(flags&31)>=ch)return false;
    if(flags&32){if(!MR_ROW(mxm_note,p,end))return false;p+=2;}if(flags&64){if(!MR_ROW(mxm_volume,p,end))return false;p++;}if(flags&128){if(!MR_ROW(mxm_effect,p,end))return false;p+=2;}
  }}
 }
 return true;}
bool sx_beisert_mxmplay_build(sxmr_view*v)
{
 return sxmr_mxm(v);
}
#undef MR_ROW
