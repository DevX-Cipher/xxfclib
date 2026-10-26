/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * fujitsu_euphony_eup data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_eup_header_fields[]={
 SX_FIELD("title","char[32]",0,32,SX_NONE),
 SX_FIELD("artist","char[8]",32,8,SX_NONE),
 SX_FIELD("unknown","bytes",40,44,SX_NONE),
};
const sx_layout sxnextm_eup_header={UINT32_C(0x608B0028),"eup_header",sxnextm_eup_header_fields,SX_COUNT(sxnextm_eup_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_track_name_fields[]={
 SX_FIELD("name","char[16]",0,16,SX_NONE),
};
const sx_layout sxnextm_eup_track_name={UINT32_C(0x608B0029),"eup_track_name",sxnextm_eup_track_name_fields,SX_COUNT(sxnextm_eup_track_name_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_short_name_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_NONE),
};
const sx_layout sxnextm_eup_short_name={UINT32_C(0x608B002A),"eup_short_name",sxnextm_eup_short_name_fields,SX_COUNT(sxnextm_eup_short_name_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_mute_fields[]={
 SX_FIELD("mute","uint8",0,1,SX_FLAGS),
};
const sx_layout sxnextm_eup_mute={UINT32_C(0x608B002B),"eup_mute",sxnextm_eup_mute_fields,SX_COUNT(sxnextm_eup_mute_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_port_fields[]={
 SX_FIELD("port","uint8",0,1,SX_ID),
};
const sx_layout sxnextm_eup_port={UINT32_C(0x608B002C),"eup_port",sxnextm_eup_port_fields,SX_COUNT(sxnextm_eup_port_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_channel_fields[]={
 SX_FIELD("midi_channel","uint8",0,1,SX_ID),
};
const sx_layout sxnextm_eup_channel={UINT32_C(0x608B002D),"eup_channel",sxnextm_eup_channel_fields,SX_COUNT(sxnextm_eup_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_key_bias_fields[]={
 SX_FIELD("key_bias","int8",0,1,SX_NONE),
};
const sx_layout sxnextm_eup_key_bias={UINT32_C(0x608B002E),"eup_key_bias",sxnextm_eup_key_bias_fields,SX_COUNT(sxnextm_eup_key_bias_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_transpose_fields[]={
 SX_FIELD("transpose","int8",0,1,SX_NONE),
};
const sx_layout sxnextm_eup_transpose={UINT32_C(0x608B002F),"eup_transpose",sxnextm_eup_transpose_fields,SX_COUNT(sxnextm_eup_transpose_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_filter_fields[]={
 SX_FIELD("filter_bytes","bytes",0,7,SX_NONE),
};
const sx_layout sxnextm_eup_filter={UINT32_C(0x608B0030),"eup_filter",sxnextm_eup_filter_fields,SX_COUNT(sxnextm_eup_filter_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_instrument_name_fields[]={
 SX_FIELD("name","char[4]",0,4,SX_NONE),
};
const sx_layout sxnextm_eup_instrument_name={UINT32_C(0x608B0031),"eup_instrument_name",sxnextm_eup_instrument_name_fields,SX_COUNT(sxnextm_eup_instrument_name_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_bank_names_fields[]={
 SX_FIELD("fm_bank_name","char[8]",0,8,SX_NONE),
 SX_FIELD("pcm_bank_name","char[8]",8,8,SX_NONE),
};
const sx_layout sxnextm_eup_bank_names={UINT32_C(0x608B0032),"eup_bank_names",sxnextm_eup_bank_names_fields,SX_COUNT(sxnextm_eup_bank_names_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_application_fields[]={
 SX_FIELD("application_name","char[8]",0,8,SX_NONE),
 SX_FIELD("application_version","char[2]",8,2,SX_NONE),
};
const sx_layout sxnextm_eup_application={UINT32_C(0x608B0033),"eup_application",sxnextm_eup_application_fields,SX_COUNT(sxnextm_eup_application_fields),SX_LE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
#define NX_TAKE(l,p,n,end) sxnextm_take(v,&sxnextm_##l,(p),(n),(end))
static bool sxnextm_eup(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,p=84;
 if(e<2060||!NX_ROW(eup_header,0,e)||!NX_TAKE(eup_track_name,&p,32,e)||!NX_TAKE(eup_short_name,&p,32,e)||!NX_TAKE(eup_mute,&p,32,e)||!NX_TAKE(eup_port,&p,32,e)||!NX_TAKE(eup_channel,&p,32,e)||!NX_TAKE(eup_key_bias,&p,32,e)||!NX_TAKE(eup_transpose,&p,32,e)||!NX_TAKE(eup_filter,&p,32,e)||!NX_TAKE(eup_instrument_name,&p,128,e)||!NX_TAKE(eup_channel,&p,14,e)||!NX_TAKE(eup_bank_names,&p,1,e))return false;
 return p==0x6f2&&NX_ROW(eup_application,0x7f6,e)&&NX_ROW(eup_event_header,0x800,e);}
bool sx_fujitsu_euphony_eup_build(sxnextm_view*v)
{
 return sxnextm_eup(v);
}
#undef NX_ROW
#undef NX_TAKE
