/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The Loom Syndicate's Dynamic Studio module (.DSM) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmn_dynamic_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("title","char[20]",5,20,SX_STRING),
 SX_FIELD("artist","char[20]",25,20,SX_STRING),
 SX_FIELD("channels","uint8",45,1,SX_COUNT_PROP),
 SX_FIELD("samples","uint8",46,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint8",47,1,SX_COUNT_PROP),
 SX_FIELD("packing","uint8",48,1,SX_FLAGS),
 SX_FIELD("global_volume","uint8",49,1,SX_NONE),
 SX_FIELD("padding","bytes",50,14,SX_NONE),
};
const sx_layout sxmn_dynamic_header={UINT32_C(0x60760039),"dynamic_header",sxmn_dynamic_header_fields,SX_COUNT(sxmn_dynamic_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dynamic_pan_fields[]={
 SX_FIELD("pan","uint8",0,1,SX_NONE),
};
const sx_layout sxmn_dynamic_pan={UINT32_C(0x6076003A),"dynamic_pan",sxmn_dynamic_pan_fields,SX_COUNT(sxmn_dynamic_pan_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dynamic_track_name_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_STRING),
};
const sx_layout sxmn_dynamic_track_name={UINT32_C(0x6076003B),"dynamic_track_name",sxmn_dynamic_track_name_fields,SX_COUNT(sxmn_dynamic_track_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dynamic_event_fields[]={
 SX_FIELD("instrument","uint8",0,1,SX_ID),
 SX_FIELD("packed_note","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
const sx_layout sxmn_dynamic_event={UINT32_C(0x6076003D),"dynamic_event",sxmn_dynamic_event_fields,SX_COUNT(sxmn_dynamic_event_fields),SX_LE};
#define MN_ROW(l,at,end) sxmn_row(v,&sxmn_##l,(at),(end))
static bool sxmn_dynamic(sxmn_view*v)
{uint64_t end=v->c->size,chn,smp,ord,at,n=0;if(!MN_ROW(dynamic_header,0,end)||!sxmn_word(v,45,1,false,&chn,end)||!sxmn_word(v,46,1,false,&smp,end)||!sxmn_word(v,47,1,false,&ord,end)||!chn||chn>16||!smp||!ord||!sxmn_table(v,&sxmn_dynamic_pan,64,chn,end)||!sxmn_table(v,&sxmn_dsm_order,64+chn,ord,end))return false;for(uint64_t i=0;i<ord;i++){uint64_t x;if(!sxmn_word(v,64+chn+i,1,false,&x,end))return false;if(x>=n)n=x+1;}at=64+chn+ord;if(!sxmn_table(v,&sxmn_dynamic_track_name,at,n*chn,end))return false;at+=n*chn*8;if(!sxmn_table(v,&sxmn_dynamic_sample,at,smp,end))return false;uint64_t samples=at;at+=smp*32;if(!sxmn_table(v,&sxmn_dynamic_event,at,n*chn*64,end))return false;at+=n*chn*64*4;for(uint64_t i=0;i<smp;i++){uint64_t z,t;if(!sxmn_word(v,samples+i*32+22,1,false,&t,end)||!sxmn_word(v,samples+i*32+23,2,false,&z,end))return false;if(t==16)z*=2;if(!sxmn_span(v,at,z,end))return false;at+=z;}return true;}
bool sx_theloomsyndicate_dynamicstudio_dsm_build(sxmn_view*v)
{
 return sxmn_dynamic(v);
}
#undef MN_ROW
