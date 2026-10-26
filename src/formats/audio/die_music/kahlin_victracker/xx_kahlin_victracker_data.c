/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC KAHLIN VICTRACKER data structures, moved out of the pcmusic schema family. */
#include "../../../xx_format_schema_pcmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxpcm_victracker_header_fields[]={
 SX_FIELD("load_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("signature","char[2]",2,2,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("revision","uint8",5,1,SX_ID),
 SX_FIELD("play_mode","uint8",6,1,SX_ID),
 SX_FIELD("scale","uint8",7,1,SX_ID),
 SX_FIELD("reserved","uint8",8,1,SX_RESERVED),
 SX_FIELD("song_count","uint8",9,1,SX_COUNT_PROP),
};
const sx_layout sxpcm_victracker_header={UINT32_C(0x6094002A),"victracker_header",sxpcm_victracker_header_fields,SX_COUNT(sxpcm_victracker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_arpeggio_fields[]={
 SX_FIELD("steps","uint8[16]",0,16,SX_NONE),
};
const sx_layout sxpcm_victracker_arpeggio={UINT32_C(0x6094002C),"victracker_arpeggio",sxpcm_victracker_arpeggio_fields,SX_COUNT(sxpcm_victracker_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_arpeggio_config_fields[]={
 SX_FIELD("configuration","uint8[2]",0,2,SX_FLAGS),
};
const sx_layout sxpcm_victracker_arpeggio_config={UINT32_C(0x6094002D),"victracker_arpeggio_config",sxpcm_victracker_arpeggio_config_fields,SX_COUNT(sxpcm_victracker_arpeggio_config_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_title_fields[]={
 SX_FIELD("reserved","bytes",0,60,SX_RESERVED),
 SX_FIELD("title","char[16]",60,16,SX_NONE),
 SX_FIELD("author","char[16]",76,16,SX_NONE),
 SX_FIELD("year","char[4]",92,4,SX_NONE),
};
const sx_layout sxpcm_victracker_title={UINT32_C(0x6094002E),"victracker_title",sxpcm_victracker_title_fields,SX_COUNT(sxpcm_victracker_title_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_sound_fields[]={
 SX_FIELD("note_length","uint8",0,1,SX_NONE),
 SX_FIELD("frequency_offset","uint8",1,1,SX_NONE),
 SX_FIELD("frequency_glide","uint8",2,1,SX_NONE),
 SX_FIELD("arpeggio","uint8",3,1,SX_ID),
 SX_FIELD("reserved","bytes",4,4,SX_RESERVED),
};
const sx_layout sxpcm_victracker_sound={UINT32_C(0x6094002F),"victracker_sound",sxpcm_victracker_sound_fields,SX_COUNT(sxpcm_victracker_sound_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_event_fields[]={
 SX_FIELD("pitch","uint8",0,1,SX_NONE),
 SX_FIELD("parameter","uint8",1,1,SX_NONE),
};
const sx_layout sxpcm_victracker_event={UINT32_C(0x60940031),"victracker_event",sxpcm_victracker_event_fields,SX_COUNT(sxpcm_victracker_event_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_reserved_fields[]={
 SX_FIELD("reserved","bytes",0,128,SX_RESERVED),
};
const sx_layout sxpcm_victracker_reserved={UINT32_C(0x60940040),"victracker_reserved",sxpcm_victracker_reserved_fields,SX_COUNT(sxpcm_victracker_reserved_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_sequence_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
};
const sx_layout sxpcm_victracker_sequence={UINT32_C(0x60940041),"victracker_sequence",sxpcm_victracker_sequence_fields,SX_COUNT(sxpcm_victracker_sequence_fields),SX_LE};
#define SXPCM_ADD(c,n,p) sxpcm_put(c,&sxpcm_##n,p,1)
static bool sxpcm_vic(sx_context*c){
 uint8_t h[10];if(!sxpcm_read(c,0,h,10)||h[2]!='T'||h[3]!='1'||h[4]!=2||h[5]>1||!SXPCM_ADD(c,victracker_header,0))return false;
 if(!sxpcm_opt(c,&sxpcm_victracker_song,10,14)||!sxpcm_opt(c,&sxpcm_victracker_arpeggio,66,16)||!sxpcm_opt(c,&sxpcm_victracker_arpeggio_config,322,16)||!sxpcm_opt(c,&sxpcm_victracker_title,354,1)||!sxpcm_opt(c,&sxpcm_victracker_sound,450,16)||!sxpcm_opt(c,&sxpcm_victracker_reserved,578,1)||!sxpcm_opt(c,&sxpcm_victracker_sequence_length,706,256)||!sxpcm_opt(c,&sxpcm_victracker_sequence,962,5*256))return false;
 /* The producer writes256 complete32-row patterns. A truncated native identity
  * retains only physically complete events; no inferred logical samples. */
 if(c->size>2242){uint64_t count=((uint64_t)c->size-2242)/2;if(count>256*32)count=256*32;return sxpcm_put(c,&sxpcm_victracker_event,2242,count);}return true;
}
bool sx_kahlin_victracker_build(sx_context*c)
{
 return sxpcm_vic(c);
}
