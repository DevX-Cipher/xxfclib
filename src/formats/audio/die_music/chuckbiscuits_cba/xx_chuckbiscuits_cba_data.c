/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Chuck Biscuits & Zenic/Heretics' module (.CBA) data structures, moved out of the musicremaining schema family. */
#include "../../../xx_format_schema_musicremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmr_pan_position_fields[]={
 SX_FIELD("pan","uint8",0,1,SX_NONE),
};
const sx_layout sxmr_pan_position={UINT32_C(0x607D0012),"pan_position",sxmr_pan_position_fields,SX_COUNT(sxmr_pan_position_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_cba_event_fields[]={
 SX_FIELD("instrument","uint8",0,1,SX_ID),
 SX_FIELD("note","uint8",1,1,SX_NONE),
 SX_FIELD("volume","uint8",2,1,SX_NONE),
 SX_FIELD("effect","uint8",3,1,SX_ID),
 SX_FIELD("parameter","uint8",4,1,SX_NONE),
};
const sx_layout sxmr_cba_event={UINT32_C(0x607D0015),"cba_event",sxmr_cba_event_fields,SX_COUNT(sxmr_cba_event_fields),SX_LE};
#define MR_ROW(l,at,end) sxmr_row(v,&sxmr_##l,(at),(end))
static bool sxmr_cba(sxmr_view*v)
{uint64_t end=v->c->size,msg,ch,last,ns,x,p=332,total=0;
 if(!sxmr_eq(v,0,"CBA\xf9",4,end)||!sxmr_u(v,36,1,&x,end)||x!=26||!sxmr_u(v,37,2,&msg,end)||!sxmr_u(v,39,1,&ch,end)||!ch||ch>32||!sxmr_u(v,40,1,&last,end)||!sxmr_u(v,42,1,&ns,end)||!MR_ROW(cba_header,0,end)||!sxmr_table(v,&sxmr_pan_position,45,32,end)||!sxmr_table(v,&sxmr_order8,77,255,end))return false;
 for(uint64_t i=0;i<ns;i++,p+=48){if(!sxmr_u(v,p+36,4,&x,end)||!MR_ROW(cba_sample,p,end)||x>UINT64_MAX-total)return false;total+=x;}
 x=(last+1)*64*ch;if(!sxmr_table(v,&sxmr_cba_event,p,x,end))return false;p+=x*5;
 if(!sxmr_span(v,p,total,end))return false;p+=total;return sxmr_text_emit(v,p,msg,end);}
bool sx_chuckbiscuits_cba_build(sxmr_view*v)
{
 return sxmr_cba(v);
}
#undef MR_ROW
