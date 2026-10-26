/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Bent 'SHOGUN' Nielsen's Delta Music module (.DM) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmn_d1_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("track0_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("track1_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("track2_bytes","uint32",12,4,SX_SIZE),
 SX_FIELD("track3_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("patterns_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("instrument0_bytes","uint32",24,4,SX_SIZE),
 SX_FIELD("instrument1_bytes","uint32",28,4,SX_SIZE),
 SX_FIELD("instrument2_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("instrument3_bytes","uint32",36,4,SX_SIZE),
 SX_FIELD("instrument4_bytes","uint32",40,4,SX_SIZE),
 SX_FIELD("instrument5_bytes","uint32",44,4,SX_SIZE),
 SX_FIELD("instrument6_bytes","uint32",48,4,SX_SIZE),
 SX_FIELD("instrument7_bytes","uint32",52,4,SX_SIZE),
 SX_FIELD("instrument8_bytes","uint32",56,4,SX_SIZE),
 SX_FIELD("instrument9_bytes","uint32",60,4,SX_SIZE),
 SX_FIELD("instrument10_bytes","uint32",64,4,SX_SIZE),
 SX_FIELD("instrument11_bytes","uint32",68,4,SX_SIZE),
 SX_FIELD("instrument12_bytes","uint32",72,4,SX_SIZE),
 SX_FIELD("instrument13_bytes","uint32",76,4,SX_SIZE),
 SX_FIELD("instrument14_bytes","uint32",80,4,SX_SIZE),
 SX_FIELD("instrument15_bytes","uint32",84,4,SX_SIZE),
 SX_FIELD("instrument16_bytes","uint32",88,4,SX_SIZE),
 SX_FIELD("instrument17_bytes","uint32",92,4,SX_SIZE),
 SX_FIELD("instrument18_bytes","uint32",96,4,SX_SIZE),
 SX_FIELD("instrument19_bytes","uint32",100,4,SX_SIZE),
};
const sx_layout sxmn_d1_header={UINT32_C(0x60760061),"d1_header",sxmn_d1_header_fields,SX_COUNT(sxmn_d1_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_d1_track_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
const sx_layout sxmn_d1_track={UINT32_C(0x60760062),"d1_track",sxmn_d1_track_fields,SX_COUNT(sxmn_d1_track_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_d1_pattern_fields[]={
 SX_FIELD("sample","uint8",0,1,SX_ID),
 SX_FIELD("note","uint8",1,1,SX_ID),
 SX_FIELD("effect_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
const sx_layout sxmn_d1_pattern={UINT32_C(0x60760064),"d1_pattern",sxmn_d1_pattern_fields,SX_COUNT(sxmn_d1_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_d1_synth_entry_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
const sx_layout sxmn_d1_synth_entry={UINT32_C(0x60760066),"d1_synth_entry",sxmn_d1_synth_entry_fields,SX_COUNT(sxmn_d1_synth_entry_fields),SX_LE};
#define MN_ROW(l,at,end) sxmn_row(v,&sxmn_##l,(at),(end))
static bool sxmn_d1(sxmn_view*v)
{uint64_t end=v->c->size,at=104,lengths[25];if(!MN_ROW(d1_header,0,end))return false;for(unsigned i=0;i<25;i++)if(!sxmn_word(v,4+4*i,4,true,&lengths[i],end))return false;for(unsigned i=0;i<4;i++){uint64_t limit;if(lengths[i]<4||lengths[i]%2||!sxmn_span(v,at,lengths[i],end))return false;limit=at+lengths[i];while(at<limit){uint64_t code;if(!sxmn_word(v,at,2,true,&code,limit))return false;if(code==65535||at==limit-4){if(!MN_ROW(d1_control,at,limit))return false;at+=4;}else{if(!MN_ROW(d1_track,at,limit))return false;at+=2;}}}if(lengths[4]%4||!sxmn_table(v,&sxmn_d1_pattern,at,lengths[4]/4,end))return false;at+=lengths[4];for(unsigned i=5;i<25;i++){uint64_t z=lengths[i],sampled;if(!z)continue;if(!sxmn_span(v,at,z,end)||!MN_ROW(d1_instrument,at,at+z)||!sxmn_word(v,at+14,1,false,&sampled,end))return false;if(!sampled&&!sxmn_table(v,&sxmn_d1_synth_entry,at+30,48,at+z))return false;at+=z;}return true;}
bool sx_shogun_deltamusic1_build(sxmn_view*v)
{
 return sxmn_d1(v);
}
#undef MN_ROW
