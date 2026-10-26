/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * richardjoseph_rjp_sng data structures, moved out of the amigamore schema family. */
#include "../../../xx_format_schema_amigamore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxamore_rjp_header_fields[]={
 SX_FIELD("signature","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("module_marker","bytes",4,4,SX_ID),
};
const sx_layout sxamore_rjp_header={UINT32_C(0x60950023),"rjp_header",sxamore_rjp_header_fields,SX_COUNT(sxamore_rjp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_rjp_subsong_fields[]={
 SX_FIELD("channel0","uint8",0,1,SX_ID),
 SX_FIELD("channel1","uint8",1,1,SX_ID),
 SX_FIELD("channel2","uint8",2,1,SX_ID),
 SX_FIELD("channel3","uint8",3,1,SX_ID),
};
const sx_layout sxamore_rjp_subsong={UINT32_C(0x60950026),"rjp_subsong",sxamore_rjp_subsong_fields,SX_COUNT(sxamore_rjp_subsong_fields),SX_LE};
#define AM_ROW(l,at,end) sxamore_row(v,&sxamore_##l,(at),(end))
static bool sxamore_rjp(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,p=8,base[7],size[7];
 if(!sxamore_eq(v,0,"RJP",3,e)||!sxamore_eq(v,4,"SMOD",4,e))return false;
 for(unsigned i=0;i<7;i++){if(!sxamore_be(v,p,4,&size[i],e)||!sxamore_span(v,p+4,size[i],e))return false;base[i]=p+4;p+=4+size[i];}
 if(!AM_ROW(rjp_header,0,e))return false;
 for(unsigned i=0;i<7;i++)if(!AM_ROW(rjp_section,base[i]-4,e))return false;
 if(!sxamore_table(v,&sxamore_rjp_sample,base[0],size[0]/32,base[0]+size[0])||!sxamore_table(v,&sxamore_rjp_subsong,base[2],size[2]/4,base[2]+size[2])||!sxamore_table(v,&sxamore_rjp_position_offset,base[3],size[3]/4,base[3]+size[3])||!sxamore_table(v,&sxamore_rjp_step_offset,base[4],size[4]/4,base[4]+size[4]))return false;
 return true;
}
bool sx_richardjoseph_rjp_sng_build(sxamore_view*v)
{
 return sxamore_rjp(v);
}
#undef AM_ROW
