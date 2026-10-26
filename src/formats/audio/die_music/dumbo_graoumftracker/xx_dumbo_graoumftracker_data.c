/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Laurent 'Dumbo' de Soras's Graoumf Tracker module (.GTK) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_gtk_header_fields[]={
 SX_FIELD("magic","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("title","char[32]",4,32,SX_NONE),
 SX_FIELD("comment","char[160]",36,160,SX_NONE),
 SX_FIELD("samples","uint16",196,2,SX_COUNT_PROP),
 SX_FIELD("rows","uint16",198,2,SX_COUNT_PROP),
 SX_FIELD("channels","uint16",200,2,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",202,2,SX_COUNT_PROP),
 SX_FIELD("restart_order","uint16",204,2,SX_NONE),
};
const sx_layout sxmta_gtk_header={UINT32_C(0x6081000C),"gtk_header",sxmta_gtk_header_fields,SX_COUNT(sxmta_gtk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gtk_event4_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
const sx_layout sxmta_gtk_event4={UINT32_C(0x60810010),"gtk_event4",sxmta_gtk_event4_fields,SX_COUNT(sxmta_gtk_event4_fields),SX_LE};
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_gtk(sxmta_view*v)
{uint64_t end=v->c->size,p=206,ver,ns,rows,ch,orders,x,np=0,total=0;const sx_layout*sl;
 if(!sxmta_eq(v,0,"GTK",3,end)||!sxmta_u(v,3,1,&ver,end)||ver<1||ver>4||!sxmta_be(v,196,2,&ns,end)||ns>255||!sxmta_be(v,198,2,&rows,end)||!rows||rows>256||!sxmta_be(v,200,2,&ch,end)||!ch||ch>32||!sxmta_be(v,202,2,&orders,end)||orders>256||!MTA_ROW(gtk_header,0,end))return false;
 sl=ver==1?&sxmta_gtk_sample1:ver==2?&sxmta_gtk_sample2:&sxmta_gtk_sample3;
 for(uint64_t i=0;i<ns;i++){if(!sxmta_be(v,p+(ver<3?32:48),4,&x,end)||x>UINT64_MAX-total||!sxmta_take(v,sl,&p,1,end))return false;total+=x;}
 for(uint64_t i=0;i<orders;i++){if(!sxmta_be(v,p+i*2,2,&x,end)||x>=256)return false;if(x>=np)np=x+1;}
 if(!MTA_TAKE(order16be,&p,256,end)||!sxmta_take(v,ver==4?&sxmta_gtk_event5:&sxmta_gtk_event4,&p,np*rows*ch,end))return false;return sxmta_span(v,p,total,end);}
bool sx_dumbo_graoumftracker_build(sxmta_view*v)
{
 return sxmta_gtk(v);
}
#undef MTA_ROW
#undef MTA_TAKE
