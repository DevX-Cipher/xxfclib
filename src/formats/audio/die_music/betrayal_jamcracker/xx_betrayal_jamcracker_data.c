/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Gemmel & Xag/Betrayal's JamCracker/Pro module (.JAM,.JC) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_jam_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("samples","uint16",4,2,SX_COUNT_PROP),
};
const sx_layout sxmta_jam_header={UINT32_C(0x60810062),"jam_header",sxmta_jam_header_fields,SX_COUNT(sxmta_jam_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_jam_sample_fields[]={
 SX_FIELD("name","char[31]",0,31,SX_NONE),
 SX_FIELD("flags","uint8",31,1,SX_FLAGS),
 SX_FIELD("sample_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("sample_address","uint32",36,4,SX_ADDRESS),
};
const sx_layout sxmta_jam_sample={UINT32_C(0x60810063),"jam_sample",sxmta_jam_sample_fields,SX_COUNT(sxmta_jam_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_jam_pattern_fields[]={
 SX_FIELD("rows","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("pattern_address","uint32",2,4,SX_ADDRESS),
};
const sx_layout sxmta_jam_pattern={UINT32_C(0x60810064),"jam_pattern",sxmta_jam_pattern_fields,SX_COUNT(sxmta_jam_pattern_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_jam_event_fields[]={
 SX_FIELD("period","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","int8",1,1,SX_NONE),
 SX_FIELD("speed","uint8",2,1,SX_NONE),
 SX_FIELD("arpeggio","uint8",3,1,SX_NONE),
 SX_FIELD("vibrato","uint8",4,1,SX_NONE),
 SX_FIELD("phase","uint8",5,1,SX_NONE),
 SX_FIELD("volume","uint8",6,1,SX_NONE),
 SX_FIELD("portamento","uint8",7,1,SX_NONE),
};
const sx_layout sxmta_jam_event={UINT32_C(0x60810065),"jam_event",sxmta_jam_event_fields,SX_COUNT(sxmta_jam_event_fields),SX_LE};
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_jam(sxmta_view*v)
{uint64_t end=v->c->size,p=6,ns,np,no,x,events=0,total=0;
 if(!sxmta_eq(v,0,"BeEp",4,end)||!sxmta_be(v,4,2,&ns,end)||ns>256||!MTA_ROW(jam_header,0,end))return false;
 for(uint64_t i=0;i<ns;i++){if(!sxmta_be(v,p+32,4,&x,end)||!MTA_TAKE(jam_sample,&p,1,end))return false;total+=x;}
 if(!sxmta_be(v,p,2,&np,end)||!MTA_TAKE(count16be,&p,1,end))return false;
 for(uint64_t i=0;i<np;i++){if(!sxmta_be(v,p,2,&x,end)||!MTA_TAKE(jam_pattern,&p,1,end))return false;events+=x*4;}
 if(!sxmta_be(v,p,2,&no,end)||!MTA_TAKE(count16be,&p,1,end)||!MTA_TAKE(order16be,&p,no,end)||!MTA_TAKE(jam_event,&p,events,end))return false;return sxmta_span(v,p,total,end);}
bool sx_betrayal_jamcracker_build(sxmta_view*v)
{
 return sxmta_jam(v);
}
#undef MTA_ROW
#undef MTA_TAKE
