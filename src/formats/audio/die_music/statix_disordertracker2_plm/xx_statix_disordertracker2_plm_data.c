/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Alex 'Statix' Evans' Disorder Tracker 2 module (.PLM) data structures, moved out of the musicremaining schema family. */
#include "../../../xx_format_schema_musicremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmr_plm_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("header_bytes","uint8",4,1,SX_SIZE),
 SX_FIELD("version","uint8",5,1,SX_ID),
 SX_FIELD("title","char[48]",6,48,SX_NONE),
 SX_FIELD("channels","uint8",54,1,SX_COUNT_PROP),
 SX_FIELD("flags","uint8",55,1,SX_FLAGS),
 SX_FIELD("max_volume","uint8",56,1,SX_NONE),
 SX_FIELD("amplification","uint8",57,1,SX_NONE),
 SX_FIELD("tempo","uint8",58,1,SX_NONE),
 SX_FIELD("speed","uint8",59,1,SX_NONE),
 SX_FIELD("pan_positions","bytes",60,32,SX_NONE),
 SX_FIELD("samples","uint8",92,1,SX_COUNT_PROP),
 SX_FIELD("patterns","uint8",93,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",94,2,SX_COUNT_PROP),
};
const sx_layout sxmr_plm_header={UINT32_C(0x607D0016),"plm_header",sxmr_plm_header_fields,SX_COUNT(sxmr_plm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_plm_order_fields[]={
 SX_FIELD("start_row","uint16",0,2,SX_NONE),
 SX_FIELD("first_channel","uint8",2,1,SX_ID),
 SX_FIELD("pattern","uint8",3,1,SX_ID),
};
const sx_layout sxmr_plm_order={UINT32_C(0x607D0017),"plm_order",sxmr_plm_order_fields,SX_COUNT(sxmr_plm_order_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_sample_offset_fields[]={
 SX_FIELD("sample_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxmr_sample_offset={UINT32_C(0x607D0019),"sample_offset",sxmr_sample_offset_fields,SX_COUNT(sxmr_sample_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_plm_pattern_fields[]={
 SX_FIELD("pattern_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("rows","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("channels","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("color","uint8",6,1,SX_ID),
 SX_FIELD("name","char[25]",7,25,SX_NONE),
};
const sx_layout sxmr_plm_pattern={UINT32_C(0x607D001C),"plm_pattern",sxmr_plm_pattern_fields,SX_COUNT(sxmr_plm_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_plm_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("volume","uint8",2,1,SX_NONE),
 SX_FIELD("effect","uint8",3,1,SX_ID),
 SX_FIELD("parameter","uint8",4,1,SX_NONE),
};
const sx_layout sxmr_plm_event={UINT32_C(0x607D001D),"plm_event",sxmr_plm_event_fields,SX_COUNT(sxmr_plm_event_fields),SX_LE};
#define MR_ROW(l,at,end) sxmr_row(v,&sxmr_##l,(at),(end))
static bool sxmr_plm(sxmr_view*v)
{uint64_t end=v->c->size,hs,ch,ns,np,no,p,pt,st,at,n,x,y;
 if(!sxmr_eq(v,0,"PLM\x1a",4,end)||!sxmr_u(v,4,1,&hs,end)||hs<96||!sxmr_u(v,5,1,&x,end)||x!=16||!sxmr_u(v,54,1,&ch,end)||!ch||ch>32||!sxmr_u(v,92,1,&ns,end)||!sxmr_u(v,93,1,&np,end)||!sxmr_u(v,94,2,&no,end)||!MR_ROW(plm_header,0,end))return false;
 p=hs;if(!sxmr_table(v,&sxmr_plm_order,p,no,end))return false;p+=no*4;pt=p;if(!sxmr_table(v,&sxmr_pattern_offset,p,np,end))return false;p+=np*4;st=p;if(!sxmr_table(v,&sxmr_sample_offset,p,ns,end))return false;
 for(uint64_t i=0;i<np;i++){if(!sxmr_u(v,pt+i*4,4,&at,end))return false;if(!at)continue;if(!sxmr_u(v,at,4,&n,end)||n<32||!sxmr_span(v,at,n,end)||!sxmr_u(v,at+4,1,&x,end)||!sxmr_u(v,at+5,1,&y,end)||y>32||!MR_ROW(plm_pattern,at,end)||!sxmr_table(v,&sxmr_plm_event,at+32,x*y,at+n))return false;}
 for(uint64_t i=0;i<ns;i++){if(!sxmr_u(v,st+i*4,4,&at,end))return false;if(!at)continue;if(!sxmr_eq(v,at,"PLS\x1a",4,end)||!sxmr_u(v,at+4,1,&hs,end)||hs<71||!sxmr_u(v,at+67,4,&n,end)||!sxmr_span(v,at,hs,end)||!sxmr_span(v,at+hs,n,end)||!MR_ROW(plm_sample,at,end))return false;}
 return true;}
bool sx_statix_disordertracker2_plm_build(sxmr_view*v)
{
 return sxmr_plm(v);
}
#undef MR_ROW
