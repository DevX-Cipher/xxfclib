/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * amiga_ahx data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_amiga_ahx_header_fields[]={
 SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("names_offset_low16","uint16",4,2,SX_OFFSET),
 SX_FIELD("flags_and_position_count","uint16",6,2,SX_FLAGS),
 SX_FIELD("restart_position","uint16",8,2,SX_ID),
 SX_FIELD("rows_per_track","uint8",10,1,SX_COUNT_PROP),
 SX_FIELD("maximum_track","uint8",11,1,SX_ID),
 SX_FIELD("instrument_count","uint8",12,1,SX_COUNT_PROP),
 SX_FIELD("subsong_count","uint8",13,1,SX_COUNT_PROP),
};
const sx_layout sxau_amiga_ahx_header={UINT32_C(0x602C0044),"amiga_ahx_header",sxau_amiga_ahx_header_fields,SX_COUNT(sxau_amiga_ahx_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_amiga_ahx_subsong_fields[]={
 SX_FIELD("start_position","uint16",0,2,SX_ID),
};
const sx_layout sxau_amiga_ahx_subsong={UINT32_C(0x602C0045),"amiga_ahx_subsong",sxau_amiga_ahx_subsong_fields,SX_COUNT(sxau_amiga_ahx_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxau_amiga_ahx_channel_order_fields[]={
 SX_FIELD("track_index","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
const sx_layout sxau_amiga_ahx_channel_order={UINT32_C(0x602C0046),"amiga_ahx_channel_order",sxau_amiga_ahx_channel_order_fields,SX_COUNT(sxau_amiga_ahx_channel_order_fields),SX_BE};
static const xx_data_struct_field_desc sxau_amiga_ahx_instrument_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
 SX_FIELD("filter_speed_and_wave_length","uint8",1,1,SX_FLAGS),
 SX_FIELD("attack_frames","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("attack_volume","uint8",3,1,SX_NONE),
 SX_FIELD("decay_frames","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("decay_volume","uint8",5,1,SX_NONE),
 SX_FIELD("sustain_frames","uint8",6,1,SX_COUNT_PROP),
 SX_FIELD("release_frames","uint8",7,1,SX_COUNT_PROP),
 SX_FIELD("release_volume","uint8",8,1,SX_NONE),
 SX_FIELD("unknown_a","bytes",9,12,SX_NONE),
 SX_FIELD("playlist_length","uint8",21,1,SX_COUNT_PROP),
};
const sx_layout sxau_amiga_ahx_instrument={UINT32_C(0x602C0047),"amiga_ahx_instrument",sxau_amiga_ahx_instrument_fields,SX_COUNT(sxau_amiga_ahx_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxau_amiga_ahx_playlist_fields[]={
 SX_FIELD("effects_and_waveform","uint8",0,1,SX_FLAGS),
 SX_FIELD("note_and_fixed","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect_parameter1","uint8",2,1,SX_NONE),
 SX_FIELD("effect_parameter2","uint8",3,1,SX_NONE),
};
const sx_layout sxau_amiga_ahx_playlist={UINT32_C(0x602C0048),"amiga_ahx_playlist",sxau_amiga_ahx_playlist_fields,SX_COUNT(sxau_amiga_ahx_playlist_fields),SX_BE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_amiga(sxau_view*v)
{if(!SA_ROW(amiga_ahx_header,0,v->n))return false;size_t at=14,subs=v->p[13],pos=sxau_u16(v->p+6,true)&4095,tracks=v->p[11]+((v->p[6]&128)?0:1),rows=v->p[10],ins=v->p[12];if(!sxau_table(v,&sxau_amiga_ahx_subsong,at,subs,v->n))return false;at+=subs*2;if(!sxau_table(v,&sxau_amiga_ahx_channel_order,at,pos*4,v->n))return false;at+=pos*8;if(!sxau_need(v,at,tracks*rows*3,v->n))return false;at+=tracks*rows*3;for(size_t i=0;i<ins;i++){if(!SA_ROW(amiga_ahx_instrument,at,v->n))return false;unsigned count=v->p[at+21];at+=22;if(!sxau_table(v,&sxau_amiga_ahx_playlist,at,count,v->n))return false;at+=count*4;}return at<=v->n;}
bool sx_amiga_ahx_build(sxau_view*v)
{
 return sxau_amiga(v);
}
#undef SA_ROW
