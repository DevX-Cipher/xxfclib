/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * B. Birney's PlayerPro module (.MAD) data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmw_madg_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("song_name","char[32]",4,32,SX_NONE),
};
const sx_layout sxmw_madg_header={UINT32_C(0x60870018),"madg_header",sxmw_madg_header_fields,SX_COUNT(sxmw_madg_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmw_madg_orders_fields[]={
 SX_FIELD("pattern_count","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("order_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("orders","bytes",2,128,SX_NONE),
 SX_FIELD("tracks","uint8",130,1,SX_COUNT_PROP),
 SX_FIELD("padding","uint8",131,1,SX_RESERVED),
};
const sx_layout sxmw_madg_orders={UINT32_C(0x6087001A),"madg_orders",sxmw_madg_orders_fields,SX_COUNT(sxmw_madg_orders_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_madg_pattern_fields[]={
 SX_FIELD("rows","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("encoding","bytes",4,4,SX_ID),
 SX_FIELD("name","char[20]",8,20,SX_NONE),
 SX_FIELD("packed_bytes","int32",28,4,SX_SIZE),
 SX_FIELD("unused","int32",32,4,SX_RESERVED),
};
const sx_layout sxmw_madg_pattern={UINT32_C(0x6087001B),"madg_pattern",sxmw_madg_pattern_fields,SX_COUNT(sxmw_madg_pattern_fields),SX_BE};
static const xx_data_struct_field_desc sxmw_madg_event_fields[]={
 SX_FIELD("instrument","uint8",0,1,SX_ID),
 SX_FIELD("note","uint8",1,1,SX_NONE),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("argument","uint8",3,1,SX_NONE),
};
const sx_layout sxmw_madg_event={UINT32_C(0x6087001C),"madg_event",sxmw_madg_event_fields,SX_COUNT(sxmw_madg_event_fields),SX_LE};
#define MW_ROW(l,at,end) sxmw_row(v,&sxmw_##l,(at),(end))
#define MW_TAKE(l,p,n,end) sxmw_take(v,&sxmw_##l,(p),(n),(end))
static bool sxmw_madg(sxmw_view*v)
{uint64_t end=v->c->size,p=36,total=0,x,patterns,tracks;
 if(!sxmw_eq(v,0,"MADG",4,end)||!MW_ROW(madg_header,0,end))return false;
 for(unsigned i=0;i<64;i++){if(!sxmw_be(v,p+32,4,&x,end)||x>INT32_MAX||!MW_TAKE(madg_instrument,&p,1,end))return false;total+=x;}
 if(!sxmw_u(v,p,1,&patterns,end)||!sxmw_u(v,p+130,1,&tracks,end)||!tracks||tracks>64||!MW_TAKE(madg_orders,&p,1,end))return false;
 for(uint64_t i=0;i<patterns;i++){uint64_t rows,packed;bool coded=sxmw_eq(v,p+4,"MAD1",4,end);if(!sxmw_be(v,p,4,&rows,end)||!rows||rows>INT32_MAX||!sxmw_be(v,p+28,4,&packed,end)||packed>INT32_MAX||!MW_TAKE(madg_pattern,&p,1,end))return false;
  if(coded){if(!sxmw_skip(v,&p,packed,end))return false;}else if(!MW_TAKE(madg_event,&p,rows*tracks,end))return false;
 }return sxmw_span(v,p,total,end);}
bool sx_birney_playerpro_mad_build(sxmw_view*v)
{
 return sxmw_madg(v);
}
#undef MW_ROW
#undef MW_TAKE
