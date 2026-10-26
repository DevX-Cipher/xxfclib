/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * greatvalleyprod_digitalsoundstudio data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_dss_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("unknown","bytes",4,4,SX_NONE),
 SX_FIELD("tempo","uint8",8,1,SX_NONE),
 SX_FIELD("speed","uint8",9,1,SX_NONE),
};
const sx_layout sxnextm_dss_header={UINT32_C(0x608B0011),"dss_header",sxnextm_dss_header_fields,SX_COUNT(sxnextm_dss_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dss_event_fields[]={
 SX_FIELD("sample_and_period_high","uint8",0,1,SX_FLAGS),
 SX_FIELD("period_low","uint8",1,1,SX_NONE),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("effect_argument","uint8",3,1,SX_NONE),
};
const sx_layout sxnextm_dss_event={UINT32_C(0x608B0013),"dss_event",sxnextm_dss_event_fields,SX_COUNT(sxnextm_dss_event_fields),SX_LE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
#define NX_TAKE(l,p,n,end) sxnextm_take(v,&sxnextm_##l,(p),(n),(end))
static bool sxnextm_dss(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,p=10,n,mx=0;
 if(!sxnextm_eq(v,0,"MMU2",4,e)||!NX_ROW(dss_header,0,e)||!NX_TAKE(dss_sample,&p,31,e)||!sxnextm_be(v,p,2,&n,e)||n>128||!NX_TAKE(count16,&p,1,e))return false;
 for(uint64_t i=0;i<n;i++){uint64_t x;if(!sxnextm_u(v,p+i,1,&x,e))return false;if(x>mx)mx=x;}
 if(!NX_TAKE(order8,&p,128,e))return false;
 return !n||sxnextm_table(v,&sxnextm_dss_event,p,(mx+1)*256,e);}
bool sx_greatvalleyprod_digitalsoundstudio_build(sxnextm_view*v)
{
 return sxnextm_dss(v);
}
#undef NX_ROW
#undef NX_TAKE
