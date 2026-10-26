/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Andreas Tadic's Game Music Creator module (.GMC) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_gmc_orders_fields[]={
 SX_FIELD("zero","bytes",0,3,SX_RESERVED),
 SX_FIELD("orders","uint8",3,1,SX_COUNT_PROP),
};
const sx_layout sxmta_gmc_orders={UINT32_C(0x60810027),"gmc_orders",sxmta_gmc_orders_fields,SX_COUNT(sxmta_gmc_orders_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gmc_event_fields[]={
 SX_FIELD("period","uint16",0,2,SX_NONE),
 SX_FIELD("instrument_effect","uint8",2,1,SX_FLAGS),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
const sx_layout sxmta_gmc_event={UINT32_C(0x60810029),"gmc_event",sxmta_gmc_event_fields,SX_COUNT(sxmta_gmc_event_fields),SX_BE};
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_gmc(sxmta_view*v)
{uint64_t end=v->c->size,p=0,total=0,x,orders,np=1;
 for(unsigned i=0;i<15;i++){if(!sxmta_be(v,p+4,2,&x,end)||!MTA_TAKE(gmc_sample,&p,1,end))return false;total+=2*x;}
 if(!sxmta_u(v,p+3,1,&orders,end)||!orders||orders>100||!MTA_TAKE(gmc_orders,&p,1,end))return false;
 for(uint64_t i=0;i<orders;i++){if(!sxmta_be(v,p+2*i,2,&x,end)||x%1024)return false;x/=1024;if(x!=63&&x>=np)np=x+1;}
 if(np>64||!MTA_TAKE(gmc_pattern_offset,&p,100,end)||!MTA_TAKE(gmc_event,&p,np*256,end))return false;return sxmta_span(v,p,total,end);}
bool sx_tadic_gamemusiccreator_build(sxmta_view*v)
{
 return sxmta_gmc(v);
}
#undef MTA_TAKE
