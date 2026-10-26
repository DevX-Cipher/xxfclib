/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Hans Bergstedt's Sound Invasion Music System/In Stereo! module (.IS) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_is1_sample_info_fields[]={
 SX_FIELD("unknown0","uint8",0,1,SX_NONE),
 SX_FIELD("name","char[23]",1,23,SX_NONE),
 SX_FIELD("unknown24","bytes",24,4,SX_NONE),
};
const sx_layout sxmta_is1_sample_info={UINT32_C(0x60810087),"is1_sample_info",sxmta_is1_sample_info_fields,SX_COUNT(sxmta_is1_sample_info_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_is1_subsong_fields[]={
 SX_FIELD("unknown0","bytes",0,4,SX_NONE),
 SX_FIELD("speed","uint8",4,1,SX_NONE),
 SX_FIELD("rows_per_track","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("first_position","uint16",6,2,SX_NONE),
 SX_FIELD("last_position","uint16",8,2,SX_NONE),
 SX_FIELD("restart_position","uint16",10,2,SX_NONE),
 SX_FIELD("unknown12","bytes",12,2,SX_NONE),
};
const sx_layout sxmta_is1_subsong={UINT32_C(0x6081008A),"is1_subsong",sxmta_is1_subsong_fields,SX_COUNT(sxmta_is1_subsong_fields),SX_BE};
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_is1(sxmta_view*v)
{uint64_t end=v->c->size,p=204,np,nr,ns,nw,ni,nsub,neg,nad,x,total=0;
 if(!sxmta_eq(v,0,"ISM!V1.2",8,end)||!MTA_ROW(is1_header,0,end)||!sxmta_be(v,8,2,&np,end)||!sxmta_be(v,10,2,&nr,end)||!sxmta_u(v,16,1,&ns,end)||!sxmta_u(v,17,1,&nw,end)||!sxmta_u(v,18,1,&ni,end)||!sxmta_u(v,19,1,&nsub,end)||!sxmta_u(v,20,1,&neg,end)||!sxmta_u(v,21,1,&nad,end)||!MTA_TAKE(is1_sample_info,&p,ns,end))return false;
 for(uint64_t i=0;i<ns;i++){if(!sxmta_be(v,p,4,&x,end)||!MTA_TAKE(is_sample_bytes,&p,1,end))return false;total+=x;}
 if(!MTA_TAKE(is_unsigned_value,&p,neg*128+nad*256,end)||!MTA_TAKE(is1_instrument,&p,ni,end)||!MTA_TAKE(is_unsigned_value,&p,256,end)||!MTA_TAKE(is1_subsong,&p,nsub,end)||!sxmta_skip(v,&p,14,end)||!sxmta_skip(v,&p,nw*256,end)||!MTA_TAKE(is_position,&p,np*4,end)||!MTA_TAKE(is1_event,&p,nr+64,end))return false;return sxmta_span(v,p,total,end);}
bool sx_bergstedt_sims_instereo1_build(sxmta_view*v)
{
 return sxmta_is1(v);
}
#undef MTA_ROW
#undef MTA_TAKE
