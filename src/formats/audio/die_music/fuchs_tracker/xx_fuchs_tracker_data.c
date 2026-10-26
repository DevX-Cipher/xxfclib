/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Andreas Fuchs's FuchsTracker module (.FUCHS) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_fuchs_event_fields[]={
 SX_FIELD("instrument_period_high","uint8",0,1,SX_FLAGS),
 SX_FIELD("period_low","uint8",1,1,SX_NONE),
 SX_FIELD("instrument_effect","uint8",2,1,SX_FLAGS),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
const sx_layout sxmta_fuchs_event={UINT32_C(0x6081002A),"fuchs_event",sxmta_fuchs_event_fields,SX_COUNT(sxmta_fuchs_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_fuchs_header_fields[]={
 SX_FIELD("title","char[10]",0,10,SX_NONE),
 SX_FIELD("sample_data_bytes","uint32",10,4,SX_SIZE),
};
const sx_layout sxmta_fuchs_header={UINT32_C(0x6081006C),"fuchs_header",sxmta_fuchs_header_fields,SX_COUNT(sxmta_fuchs_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_fuchs_sample_bytes_fields[]={
 SX_FIELD("sample_bytes","uint16",0,2,SX_SIZE),
};
const sx_layout sxmta_fuchs_sample_bytes={UINT32_C(0x6081006D),"fuchs_sample_bytes",sxmta_fuchs_sample_bytes_fields,SX_COUNT(sxmta_fuchs_sample_bytes_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_fuchs_order_count_fields[]={
 SX_FIELD("orders","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxmta_fuchs_order_count={UINT32_C(0x60810070),"fuchs_order_count",sxmta_fuchs_order_count_fields,SX_COUNT(sxmta_fuchs_order_count_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_fuchs_pattern_chunk_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("pattern_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxmta_fuchs_pattern_chunk={UINT32_C(0x60810071),"fuchs_pattern_chunk",sxmta_fuchs_pattern_chunk_fields,SX_COUNT(sxmta_fuchs_pattern_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_fuchs_samples_marker_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_ID),
};
const sx_layout sxmta_fuchs_samples_marker={UINT32_C(0x60810072),"fuchs_samples_marker",sxmta_fuchs_samples_marker_fields,SX_COUNT(sxmta_fuchs_samples_marker_fields),SX_LE};
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_fuchs(sxmta_view*v)
{uint64_t end=v->c->size,p=0,n,total;
 if(!sxmta_be(v,10,4,&total,end)||!MTA_TAKE(fuchs_header,&p,1,end)||!MTA_TAKE(fuchs_sample_bytes,&p,16,end)||!MTA_TAKE(fuchs_volume,&p,16,end)||!MTA_TAKE(fuchs_loop,&p,16,end)||!MTA_TAKE(fuchs_order_count,&p,1,end)||!MTA_TAKE(order16be,&p,40,end)||!sxmta_eq(v,p,"SONG",4,end)||!sxmta_be(v,p+4,4,&n,end)||n%1024||!MTA_TAKE(fuchs_pattern_chunk,&p,1,end)||!MTA_TAKE(fuchs_event,&p,n/4,end)||!sxmta_eq(v,p,"INST",4,end)||!MTA_TAKE(fuchs_samples_marker,&p,1,end))return false;return sxmta_span(v,p,total,end);}
bool sx_fuchs_tracker_build(sxmta_view*v)
{
 return sxmta_fuchs(v);
}
#undef MTA_TAKE
