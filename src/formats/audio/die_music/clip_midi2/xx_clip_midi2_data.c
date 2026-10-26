/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MIDI 2.0 Clip data structures, moved out of the musiclogs schema family. */
#include "../../../xx_format_schema_musiclogs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxlog_midi_clip_header_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
};
const sx_layout sxlog_midi_clip_header={0x608c0001U,"midi_clip_header",sxlog_midi_clip_header_fields,SX_COUNT(sxlog_midi_clip_header_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_midi_ump_utility_fields[]={
 SX_FIELD("message_type_reserved","uint8",0,1,SX_FLAGS),
 SX_FIELD("status_and_tick_high_bits","uint8",1,1,SX_FLAGS),
 SX_FIELD("tick_low_bits","uint16",2,2,SX_NONE),
};
const sx_layout sxlog_midi_ump_utility={0x608c0002U,"midi_ump_utility",sxlog_midi_ump_utility_fields,SX_COUNT(sxlog_midi_ump_utility_fields),SX_BE};
static const xx_data_struct_field_desc sxlog_midi_ump_system_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("system_status","uint8",1,1,SX_FLAGS),
 SX_FIELD("parameter_1","uint8",2,1,SX_NONE),
 SX_FIELD("parameter_2","uint8",3,1,SX_NONE),
};
const sx_layout sxlog_midi_ump_system={0x608c0003U,"midi_ump_system",sxlog_midi_ump_system_fields,SX_COUNT(sxlog_midi_ump_system_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_midi_ump_midi1_note_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("status_and_channel","uint8",1,1,SX_FLAGS),
 SX_FIELD("note","uint8",2,1,SX_NONE),
 SX_FIELD("velocity","uint8",3,1,SX_NONE),
};
const sx_layout sxlog_midi_ump_midi1_note={0x608c0004U,"midi_ump_midi1_note",sxlog_midi_ump_midi1_note_fields,SX_COUNT(sxlog_midi_ump_midi1_note_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_midi_ump_midi1_channel_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("status_and_channel","uint8",1,1,SX_FLAGS),
 SX_FIELD("data_1","uint8",2,1,SX_NONE),
 SX_FIELD("data_2","uint8",3,1,SX_NONE),
};
const sx_layout sxlog_midi_ump_midi1_channel={0x608c0005U,"midi_ump_midi1_channel",sxlog_midi_ump_midi1_channel_fields,SX_COUNT(sxlog_midi_ump_midi1_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_midi_ump_midi2_note_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("status_and_channel","uint8",1,1,SX_FLAGS),
 SX_FIELD("note","uint8",2,1,SX_NONE),
 SX_FIELD("attribute_type","uint8",3,1,SX_FLAGS),
 SX_FIELD("velocity","uint16",4,2,SX_NONE),
 SX_FIELD("attribute_data","uint16",6,2,SX_NONE),
};
const sx_layout sxlog_midi_ump_midi2_note={0x608c0006U,"midi_ump_midi2_note",sxlog_midi_ump_midi2_note_fields,SX_COUNT(sxlog_midi_ump_midi2_note_fields),SX_BE};
static const xx_data_struct_field_desc sxlog_midi_ump_midi2_channel_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("status_and_channel","uint8",1,1,SX_FLAGS),
 SX_FIELD("index_or_options","uint16",2,2,SX_NONE),
 SX_FIELD("data","uint32",4,4,SX_NONE),
};
const sx_layout sxlog_midi_ump_midi2_channel={0x608c0007U,"midi_ump_midi2_channel",sxlog_midi_ump_midi2_channel_fields,SX_COUNT(sxlog_midi_ump_midi2_channel_fields),SX_BE};
static const xx_data_struct_field_desc sxlog_midi_ump_sysex7_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("status_and_byte_count","uint8",1,1,SX_FLAGS),
 SX_FIELD("data","uint8[6]",2,6,SX_NONE),
};
const sx_layout sxlog_midi_ump_sysex7={0x608c0008U,"midi_ump_sysex7",sxlog_midi_ump_sysex7_fields,SX_COUNT(sxlog_midi_ump_sysex7_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_midi_ump_data128_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("status_and_byte_count","uint8",1,1,SX_FLAGS),
 SX_FIELD("data","uint8[14]",2,14,SX_NONE),
};
const sx_layout sxlog_midi_ump_data128={0x608c0009U,"midi_ump_data128",sxlog_midi_ump_data128_fields,SX_COUNT(sxlog_midi_ump_data128_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_midi_ump_flex_fields[]={
 SX_FIELD("type_and_group","uint8",0,1,SX_FLAGS),
 SX_FIELD("format_address_channel","uint8",1,1,SX_FLAGS),
 SX_FIELD("status_bank","uint8",2,1,SX_FLAGS),
 SX_FIELD("status","uint8",3,1,SX_FLAGS),
 SX_FIELD("data","uint8[12]",4,12,SX_NONE),
};
const sx_layout sxlog_midi_ump_flex={0x608c000aU,"midi_ump_flex",sxlog_midi_ump_flex_fields,SX_COUNT(sxlog_midi_ump_flex_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_midi_ump_stream_fields[]={
 SX_FIELD("type_format_status","uint16",0,2,SX_FLAGS),
 SX_FIELD("message_data","uint8[14]",2,14,SX_NONE),
};
const sx_layout sxlog_midi_ump_stream={0x608c000bU,"midi_ump_stream",sxlog_midi_ump_stream_fields,SX_COUNT(sxlog_midi_ump_stream_fields),SX_BE};
static bool sxlog_midi(sx_context*c)
{uint8_t b[8];int64_t at=8;unsigned work=0;
 if(!sx_read(c,0,b,8)||xx_rt_memcmp(b,"SMF2CLIP",8)||!sx_add(c,&sxlog_midi_clip_header,0,8))return false;
 while(at<c->size&&work++<16000){const sx_layout*l=NULL;unsigned size=0;if(c->size-at<4)break;if(!sx_read(c,at,b,4))return false;unsigned mt=b[0]>>4,st=b[1]>>4;
  switch(mt){case 0:l=&sxlog_midi_ump_utility;size=4;break;case 1:l=&sxlog_midi_ump_system;size=4;break;
  case 2:l=(st==8||st==9)?&sxlog_midi_ump_midi1_note:&sxlog_midi_ump_midi1_channel;size=4;break;
  case 3:l=&sxlog_midi_ump_sysex7;size=8;break;case 4:l=(st==8||st==9)?&sxlog_midi_ump_midi2_note:&sxlog_midi_ump_midi2_channel;size=8;break;
  case 5:l=&sxlog_midi_ump_data128;size=16;break;case 13:l=&sxlog_midi_ump_flex;size=16;break;case 15:l=&sxlog_midi_ump_stream;size=16;break;default:break;}
  if(!l||size>(uint64_t)(c->size-at))break;if(!sx_add(c,l,at,size))return false;at+=size;
 }return sx_raw(c,at,c->size-at);}
bool sx_clip_midi2_build(sx_context*c)
{
 return sxlog_midi(c);
}
