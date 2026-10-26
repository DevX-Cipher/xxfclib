/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Teijo Kinnunen's OctaMED module (.MED) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_med2_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
};
const sx_layout sxmta_med2_header={UINT32_C(0x60810079),"med2_header",sxmta_med2_header_fields,SX_COUNT(sxmta_med2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_med2_name_fields[]={
 SX_FIELD("name","char[40]",0,40,SX_NONE),
};
const sx_layout sxmta_med2_name={UINT32_C(0x6081007A),"med2_name",sxmta_med2_name_fields,SX_COUNT(sxmta_med2_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_med2_loop_bytes_fields[]={
 SX_FIELD("loop_bytes","uint16",0,2,SX_SIZE),
};
const sx_layout sxmta_med2_loop_bytes={UINT32_C(0x6081007C),"med2_loop_bytes",sxmta_med2_loop_bytes_fields,SX_COUNT(sxmta_med2_loop_bytes_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_med2_song_fields[]={
 SX_FIELD("orders","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("tempo","uint16",2,2,SX_NONE),
 SX_FIELD("flags","uint16",4,2,SX_FLAGS),
 SX_FIELD("sliding","uint16",6,2,SX_NONE),
 SX_FIELD("jump_mask","uint32",8,4,SX_FLAGS),
 SX_FIELD("rgb","bytes",12,16,SX_NONE),
};
const sx_layout sxmta_med2_song={UINT32_C(0x6081007D),"med2_song",sxmta_med2_song_fields,SX_COUNT(sxmta_med2_song_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_med2_pattern_header_fields[]={
 SX_FIELD("pattern_address","uint32",0,4,SX_ADDRESS),
};
const sx_layout sxmta_med2_pattern_header={UINT32_C(0x6081007E),"med2_pattern_header",sxmta_med2_pattern_header_fields,SX_COUNT(sxmta_med2_pattern_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_med2_event_fields[]={
 SX_FIELD("period","uint16",0,2,SX_NONE),
 SX_FIELD("instrument_effect","uint8",2,1,SX_FLAGS),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
const sx_layout sxmta_med2_event={UINT32_C(0x6081007F),"med2_event",sxmta_med2_event_fields,SX_COUNT(sxmta_med2_event_fields),SX_BE};
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_med2(sxmta_view*v)
{uint64_t end=v->c->size,p=4,n;
 if(!sxmta_eq(v,0,"MED\x02",4,end)||!MTA_ROW(med2_header,0,end)||!MTA_TAKE(med2_name,&p,32,end)||!MTA_TAKE(volume8,&p,32,end)||!MTA_TAKE(med2_loop_start,&p,32,end)||!MTA_TAKE(med2_loop_bytes,&p,32,end)||!sxmta_be(v,p,2,&n,end)||n>256||!MTA_TAKE(count16be,&p,1,end)||!MTA_TAKE(order8,&p,100,end)||!MTA_TAKE(med2_song,&p,1,end))return false;
 for(uint64_t i=0;i<n;i++)if(!MTA_TAKE(med2_pattern_header,&p,1,end)||!MTA_TAKE(med2_event,&p,256,end))return false;return true;}
bool sx_kinnunen_octamed_med_build(sxmta_view*v)
{
 return sxmta_med2(v);
}
#undef MTA_ROW
#undef MTA_TAKE
