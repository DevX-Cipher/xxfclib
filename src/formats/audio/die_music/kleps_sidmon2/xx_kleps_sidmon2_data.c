/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Michael Kleps's SIDMon II MIDI module (.SID2) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_sid2_header_fields[]={
 SX_FIELD("midi_mode","uint16",0,2,SX_FLAGS),
 SX_FIELD("last_order","uint8",2,1,SX_NONE),
 SX_FIELD("speed","uint8",3,1,SX_NONE),
 SX_FIELD("sample_header_bytes","uint16",4,2,SX_SIZE),
 SX_FIELD("id_bytes","uint32",6,4,SX_SIZE),
 SX_FIELD("song_length_bytes","uint32",10,4,SX_SIZE),
 SX_FIELD("position_bytes","uint32",14,4,SX_SIZE),
 SX_FIELD("note_transpose_bytes","uint32",18,4,SX_SIZE),
 SX_FIELD("instrument_transpose_bytes","uint32",22,4,SX_SIZE),
 SX_FIELD("instrument_bytes","uint32",26,4,SX_SIZE),
 SX_FIELD("waveform_list_bytes","uint32",30,4,SX_SIZE),
 SX_FIELD("arpeggio_bytes","uint32",34,4,SX_SIZE),
 SX_FIELD("vibrato_bytes","uint32",38,4,SX_SIZE),
 SX_FIELD("sample_info_bytes","uint32",42,4,SX_SIZE),
 SX_FIELD("track_table_bytes","uint32",46,4,SX_SIZE),
 SX_FIELD("track_data_bytes","uint32",50,4,SX_SIZE),
 SX_FIELD("unused","bytes",54,4,SX_NONE),
 SX_FIELD("magic","char[28]",58,28,SX_SIGNATURE),
};
const sx_layout sxmta_sid2_header={UINT32_C(0x60810073),"sid2_header",sxmta_sid2_header_fields,SX_COUNT(sxmta_sid2_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_sid2_track_number_fields[]={
 SX_FIELD("track","uint8",0,1,SX_ID),
};
const sx_layout sxmta_sid2_track_number={UINT32_C(0x60810074),"sid2_track_number",sxmta_sid2_track_number_fields,SX_COUNT(sxmta_sid2_track_number_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_sid2_transpose_fields[]={
 SX_FIELD("transpose","int8",0,1,SX_NONE),
};
const sx_layout sxmta_sid2_transpose={UINT32_C(0x60810075),"sid2_transpose",sxmta_sid2_transpose_fields,SX_COUNT(sxmta_sid2_transpose_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_sid2_sample_fields[]={
 SX_FIELD("address_placeholder","uint32",0,4,SX_ADDRESS),
 SX_FIELD("sample_words","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("loop_start_words","uint16",6,2,SX_NONE),
 SX_FIELD("loop_words","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("negate_start_words","uint16",10,2,SX_NONE),
 SX_FIELD("negate_end_words","uint16",12,2,SX_NONE),
 SX_FIELD("negate_loop_index","uint16",14,2,SX_NONE),
 SX_FIELD("negate_status","uint16",16,2,SX_FLAGS),
 SX_FIELD("negate_speed","int16",18,2,SX_NONE),
 SX_FIELD("negate_position","int32",20,4,SX_NONE),
 SX_FIELD("negate_index","uint16",24,2,SX_NONE),
 SX_FIELD("negate_enabled","int16",26,2,SX_NONE),
 SX_FIELD("unused","bytes",28,4,SX_NONE),
 SX_FIELD("name","char[32]",32,32,SX_NONE),
};
const sx_layout sxmta_sid2_sample={UINT32_C(0x60810078),"sid2_sample",sxmta_sid2_sample_fields,SX_COUNT(sxmta_sid2_sample_fields),SX_BE};
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
static bool sxmta_sid2(sxmta_view*v)
{uint64_t end=v->c->size,p=58,x,n,ns,total=0;uint64_t lengths[10];
 if(!sxmta_eq(v,58,"SIDMON II - THE MIDI VERSION",27,end)||!sxmta_be(v,4,2,&ns,end)||ns%64||!MTA_ROW(sid2_header,0,end)||!sxmta_be(v,6,4,&x,end)||!sxmta_skip(v,&p,x,end)||!sxmta_be(v,10,4,&x,end)||!sxmta_skip(v,&p,x,end)||p<86)return false;
 for(unsigned i=0;i<10;i++)if(!sxmta_be(v,14+4*i,4,&lengths[i],end))return false;
 for(unsigned i=0;i<10;i++){n=lengths[i];if(!sxmta_span(v,p,n,end))return false;
  if(i==0){if(!sxmta_table(v,&sxmta_sid2_track_number,p,n,p+n))return false;}
  else if(i==1||i==2){if(!sxmta_table(v,&sxmta_sid2_transpose,p,n,p+n))return false;}
  else if(i==3){if(n%32||!sxmta_table(v,&sxmta_sid2_instrument,p,n/32,p+n))return false;}
  else if(i==7){if(n!=ns||n%64||!sxmta_table(v,&sxmta_sid2_sample,p,n/64,p+n))return false;for(uint64_t j=0;j<n;j+=64){if(!sxmta_be(v,p+j+4,2,&x,end))return false;total+=x*2;}}
  else if(i==8){if(n%2||!sxmta_table(v,&sxmta_sid2_track_offset,p,n/2,p+n))return false;for(uint64_t j=0;j<n;j+=2){if(!sxmta_be(v,p+j,2,&x,end)||x>lengths[9])return false;}}
  p+=n;
 }
 if(p&1){if(!sxmta_skip(v,&p,1,end))return false;}return sxmta_span(v,p,total,end);}
bool sx_kleps_sidmon2_build(sxmta_view*v)
{
 return sxmta_sid2(v);
}
#undef MTA_ROW
