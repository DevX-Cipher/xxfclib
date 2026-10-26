/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IRIS & Up Rough's Hively Tracker module (.HVL) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmn_hvl_subsong_fields[]={
 SX_FIELD("position","uint16",0,2,SX_ID),
};
const sx_layout sxmn_hvl_subsong={UINT32_C(0x60760042),"hvl_subsong",sxmn_hvl_subsong_fields,SX_COUNT(sxmn_hvl_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_hvl_position_fields[]={
 SX_FIELD("track","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
const sx_layout sxmn_hvl_position={UINT32_C(0x60760043),"hvl_position",sxmn_hvl_position_fields,SX_COUNT(sxmn_hvl_position_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_hvl_empty_event_fields[]={
 SX_FIELD("empty_marker","uint8",0,1,SX_ID),
};
const sx_layout sxmn_hvl_empty_event={UINT32_C(0x60760044),"hvl_empty_event",sxmn_hvl_empty_event_fields,SX_COUNT(sxmn_hvl_empty_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_hvl_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_ID),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("effects","uint8",2,1,SX_FLAGS),
 SX_FIELD("first_parameter","uint8",3,1,SX_NONE),
 SX_FIELD("second_parameter","uint8",4,1,SX_NONE),
};
const sx_layout sxmn_hvl_event={UINT32_C(0x60760045),"hvl_event",sxmn_hvl_event_fields,SX_COUNT(sxmn_hvl_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_hvl_instrument_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
 SX_FIELD("filter_wave_flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("attack_frames","uint8",2,1,SX_NONE),
 SX_FIELD("attack_volume","uint8",3,1,SX_NONE),
 SX_FIELD("decay_frames","uint8",4,1,SX_NONE),
 SX_FIELD("decay_volume","uint8",5,1,SX_NONE),
 SX_FIELD("sustain_frames","uint8",6,1,SX_NONE),
 SX_FIELD("release_frames","uint8",7,1,SX_NONE),
 SX_FIELD("release_volume","uint8",8,1,SX_NONE),
 SX_FIELD("unused","bytes",9,3,SX_NONE),
 SX_FIELD("filter_lower_flags","uint8",12,1,SX_FLAGS),
 SX_FIELD("vibrato_delay","uint8",13,1,SX_NONE),
 SX_FIELD("release_vibrato_flags","uint8",14,1,SX_FLAGS),
 SX_FIELD("vibrato_speed","uint8",15,1,SX_NONE),
 SX_FIELD("square_lower","uint8",16,1,SX_NONE),
 SX_FIELD("square_upper","uint8",17,1,SX_NONE),
 SX_FIELD("square_speed","uint8",18,1,SX_NONE),
 SX_FIELD("filter_upper_flags","uint8",19,1,SX_FLAGS),
 SX_FIELD("playlist_speed","uint8",20,1,SX_NONE),
 SX_FIELD("playlist_entries","uint8",21,1,SX_COUNT_PROP),
};
const sx_layout sxmn_hvl_instrument={UINT32_C(0x60760046),"hvl_instrument",sxmn_hvl_instrument_fields,SX_COUNT(sxmn_hvl_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_hvl_playlist_fields[]={
 SX_FIELD("effect_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("effect_wave_flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("note_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("first_parameter","uint8",3,1,SX_NONE),
 SX_FIELD("second_parameter","uint8",4,1,SX_NONE),
};
const sx_layout sxmn_hvl_playlist={UINT32_C(0x60760047),"hvl_playlist",sxmn_hvl_playlist_fields,SX_COUNT(sxmn_hvl_playlist_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_hvl_name_byte_fields[]={
 SX_FIELD("name_byte","char[1]",0,1,SX_STRING),
};
const sx_layout sxmn_hvl_name_byte={UINT32_C(0x60760048),"hvl_name_byte",sxmn_hvl_name_byte_fields,SX_COUNT(sxmn_hvl_name_byte_fields),SX_LE};
#define MN_ROW(l,at,end) sxmn_row(v,&sxmn_##l,(at),(end))
static bool sxmn_hvl(sxmn_view*v)
{uint64_t end=v->c->size,flags,pos,channels,subs,rows,last,ins,at,names;if(!MN_ROW(hvl_header,0,end)||!sxmn_word(v,4,2,true,&names,end)||!sxmn_word(v,6,2,true,&flags,end)||!sxmn_word(v,8,1,false,&channels,end)||!sxmn_word(v,10,1,false,&rows,end)||!sxmn_word(v,11,1,false,&last,end)||!sxmn_word(v,12,1,false,&ins,end)||!sxmn_word(v,13,1,false,&subs,end))return false;pos=flags&4095;channels=(channels>>2)+4;if(!pos||channels>16||!rows||rows>64||ins>63||!sxmn_table(v,&sxmn_hvl_subsong,16,subs,end)||!sxmn_table(v,&sxmn_hvl_position,16+subs*2,pos*channels,end))return false;at=16+subs*2+pos*channels*2;for(uint64_t t=(flags&0x8000)?1:0;t<=last;t++)for(uint64_t r=0;r<rows;r++){uint64_t b;if(!sxmn_word(v,at,1,false,&b,end)||!sxmn_row(v,b==63?&sxmn_hvl_empty_event:&sxmn_hvl_event,at,end))return false;at+=b==63?1:5;}for(uint64_t i=0;i<ins;i++){uint64_t n;if(!MN_ROW(hvl_instrument,at,end)||!sxmn_word(v,at+21,1,false,&n,end)||!sxmn_table(v,&sxmn_hvl_playlist,at+22,n,end))return false;at+=22+n*5;}if(names<at||names>end)return false;at=names;for(uint64_t i=0;i<=ins;i++){uint64_t start=at;if(!sxmn_cstring(v,&at,end,65536)||!sxmn_table(v,&sxmn_hvl_name_byte,start,at-start,end))return false;}return true;}
bool sx_iris_hivelytracker_build(sxmn_view*v)
{
 return sxmn_hvl(v);
}
#undef MN_ROW
