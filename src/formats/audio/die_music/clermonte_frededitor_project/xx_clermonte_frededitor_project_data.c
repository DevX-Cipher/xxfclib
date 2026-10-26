/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * clermonte_frededitor_project data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_fred_header_fields[]={
 SX_FIELD("signature","bytes",0,12,SX_SIGNATURE),
 SX_FIELD("version","uint16",12,2,SX_ID),
 SX_FIELD("subsong_count","uint16",14,2,SX_COUNT_PROP),
};
const sx_layout sxnextm_fred_header={UINT32_C(0x608B0014),"fred_header",sxnextm_fred_header_fields,SX_COUNT(sxnextm_fred_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_track_length_fields[]={
 SX_FIELD("track_bytes","int32",0,4,SX_SIZE),
};
const sx_layout sxnextm_fred_track_length={UINT32_C(0x608B0015),"fred_track_length",sxnextm_fred_track_length_fields,SX_COUNT(sxnextm_fred_track_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_sample_fields[]={
 SX_FIELD("instrument_index","uint16",0,2,SX_ID),
 SX_FIELD("sample_bytes","uint16",2,2,SX_SIZE),
};
const sx_layout sxnextm_fred_sample={UINT32_C(0x608B0017),"fred_sample",sxnextm_fred_sample_fields,SX_COUNT(sxnextm_fred_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_end_fields[]={
 SX_FIELD("end_marker","uint32",0,4,SX_ID),
};
const sx_layout sxnextm_fred_end={UINT32_C(0x608B0018),"fred_end",sxnextm_fred_end_fields,SX_COUNT(sxnextm_fred_end_fields),SX_BE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
#define NX_TAKE(l,p,n,end) sxnextm_take(v,&sxnextm_##l,(p),(n),(end))
static bool sxnextm_fred(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,p=16,n,z;
 if(!sxnextm_eq(v,0,"Fred Editor \0\0",14,e)||!sxnextm_be(v,14,2,&n,e)||n>10||!NX_ROW(fred_header,0,e)||!NX_TAKE(u8,&p,n,e)||!NX_TAKE(i8,&p,n*1024,e))return false;
 for(unsigned i=0;i<128;i++){if(!sxnextm_be(v,p,4,&z,e)||z>INT32_MAX||!NX_TAKE(fred_track_length,&p,1,e)||!sxnextm_skip(v,&p,z,e))return false;}
 if(!sxnextm_be(v,p,2,&n,e)||!NX_TAKE(count16,&p,1,e)||!NX_TAKE(fred_instrument,&p,n,e)||!sxnextm_be(v,p,2,&n,e)||!NX_TAKE(count16,&p,1,e))return false;
 for(uint64_t i=0;i<n;i++){if(!sxnextm_be(v,p+2,2,&z,e)||!NX_TAKE(fred_sample,&p,1,e)||!sxnextm_skip(v,&p,z,e))return false;}
 return sxnextm_eq(v,p,"\x12\x34\x56\x78",4,e)&&NX_ROW(fred_end,p,e);}
bool sx_clermonte_frededitor_project_build(sxnextm_view*v)
{
 return sxnextm_fred(v);
}
#undef NX_ROW
#undef NX_TAKE
