/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Anders 'AN Cool' Nilsson's TCB Tracker module (.TCB) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_tcb_amiga_flag_fields[]={
 SX_FIELD("amiga_frequencies","uint16",0,2,SX_FLAGS),
};
const sx_layout sxmta_tcb_amiga_flag={UINT32_C(0x6081001F),"tcb_amiga_flag",sxmta_tcb_amiga_flag_fields,SX_COUNT(sxmta_tcb_amiga_flag_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_tcb_instrument_name_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_NONE),
};
const sx_layout sxmta_tcb_instrument_name={UINT32_C(0x60810020),"tcb_instrument_name",sxmta_tcb_instrument_name_fields,SX_COUNT(sxmta_tcb_instrument_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_tcb_special_fields[]={
 SX_FIELD("special_value","int16",0,2,SX_NONE),
};
const sx_layout sxmta_tcb_special={UINT32_C(0x60810021),"tcb_special",sxmta_tcb_special_fields,SX_COUNT(sxmta_tcb_special_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_tcb_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument_effect","uint8",1,1,SX_FLAGS),
};
const sx_layout sxmta_tcb_event={UINT32_C(0x60810022),"tcb_event",sxmta_tcb_event_fields,SX_COUNT(sxmta_tcb_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_tcb_sample_area_fields[]={
 SX_FIELD("remaining_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxmta_tcb_sample_area={UINT32_C(0x60810023),"tcb_sample_area",sxmta_tcb_sample_area_fields,SX_COUNT(sxmta_tcb_sample_area_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_tcb_sample_properties_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
 SX_FIELD("unused","uint8",1,1,SX_RESERVED),
 SX_FIELD("loop_tail_bytes","uint16",2,2,SX_SIZE),
};
const sx_layout sxmta_tcb_sample_properties={UINT32_C(0x60810024),"tcb_sample_properties",sxmta_tcb_sample_properties_fields,SX_COUNT(sxmta_tcb_sample_properties_fields),SX_BE};
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_tcb(sxmta_view*v)
{uint64_t end=v->c->size,p=144,np,x,base,n;
 if(!sxmta_eq(v,0,"AN COOL",7,end)||!sxmta_u(v,7,1,&x,end)||(x!='!'&&x!='.')||!sxmta_be(v,8,4,&np,end)||np>127||!MTA_ROW(tcb_header,0,end))return false;
 if(x=='.'&&!MTA_TAKE(tcb_amiga_flag,&p,1,end))return false;
 if(!MTA_TAKE(tcb_instrument_name,&p,16,end)||(x=='.'&&!MTA_TAKE(tcb_special,&p,16,end))||!MTA_TAKE(tcb_event,&p,np*256,end))return false;base=p;
 if(!sxmta_be(v,p,4,&n,end)||!sxmta_span(v,p,n,end)||!MTA_TAKE(tcb_sample_area,&p,1,end)||!MTA_TAKE(tcb_sample_properties,&p,16,end))return false;
 for(unsigned i=0;i<16;i++){uint64_t len;if(!sxmta_be(v,p,4,&x,end)||!sxmta_be(v,p+4,4,&len,end)||!MTA_TAKE(tcb_sample_location,&p,1,end))return false;if(len>1&&(!sxmta_span(v,base,x,end)||!sxmta_span(v,base+x,len,end)))return false;}
 return true;}
bool sx_ancool_tcbtracker_build(sxmta_view*v)
{
 return sxmta_tcb(v);
}
#undef MTA_ROW
#undef MTA_TAKE
