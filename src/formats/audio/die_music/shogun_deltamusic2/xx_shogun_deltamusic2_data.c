/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Bent 'SHOGUN' Nielsen's Delta Music 2 module (.DM2) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmn_d2_marker_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxmn_d2_marker={UINT32_C(0x60760067),"d2_marker",sxmn_d2_marker_fields,SX_COUNT(sxmn_d2_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_d2_arpeggio_fields[]={
 SX_FIELD("semitones","int8",0,1,SX_NONE),
};
const sx_layout sxmn_d2_arpeggio={UINT32_C(0x60760068),"d2_arpeggio",sxmn_d2_arpeggio_fields,SX_COUNT(sxmn_d2_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_d2_track_header_fields[]={
 SX_FIELD("restart_bytes","uint16",0,2,SX_OFFSET),
 SX_FIELD("track_bytes","uint16",2,2,SX_SIZE),
};
const sx_layout sxmn_d2_track_header={UINT32_C(0x60760069),"d2_track_header",sxmn_d2_track_header_fields,SX_COUNT(sxmn_d2_track_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_d2_track_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
const sx_layout sxmn_d2_track={UINT32_C(0x6076006A),"d2_track",sxmn_d2_track_fields,SX_COUNT(sxmn_d2_track_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_d2_pattern_size_fields[]={
 SX_FIELD("patterns_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxmn_d2_pattern_size={UINT32_C(0x6076006B),"d2_pattern_size",sxmn_d2_pattern_size_fields,SX_COUNT(sxmn_d2_pattern_size_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_d2_pattern_fields[]={
 SX_FIELD("note","uint8",0,1,SX_ID),
 SX_FIELD("sample","uint8",1,1,SX_ID),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
const sx_layout sxmn_d2_pattern={UINT32_C(0x6076006C),"d2_pattern",sxmn_d2_pattern_fields,SX_COUNT(sxmn_d2_pattern_fields),SX_LE};
#define MN_ROW(l,at,end) sxmn_row(v,&sxmn_##l,(at),(end))
static bool sxmn_d2(sxmn_view*v)
{uint64_t end=v->c->size,at=4058,total=0;if(!MN_ROW(d2_marker,3014,end)||!sxmn_table(v,&sxmn_d2_arpeggio,3018,1024,end)||!sxmn_table(v,&sxmn_d2_track_header,4042,4,end))return false;for(unsigned i=0;i<4;i++){uint64_t z;if(!sxmn_word(v,4044+4*i,2,true,&z,end)||z%2)return false;total+=z;}if(!sxmn_table(v,&sxmn_d2_track,at,total/2,end))return false;at+=total;uint64_t z;if(!MN_ROW(d2_pattern_size,at,end)||!sxmn_word(v,at,4,true,&z,end)||z%4||!sxmn_table(v,&sxmn_d2_pattern,at+4,z/4,end))return false;at+=4+z;if(!sxmn_table(v,&sxmn_d2_instrument_offset,at,128,end))return false;uint64_t base=at+256,sentinel,seen[129]={0};unsigned n=1;if(!sxmn_word(v,at+254,2,true,&sentinel,end))return false;for(unsigned i=0;i<128;i++){uint64_t rel;if(!sxmn_word(v,at+2*i,2,true,&rel,end))return false;if(rel==sentinel)continue;bool found=false;for(unsigned j=0;j<n;j++)if(seen[j]==rel)found=true;if(!found)seen[n++]=rel;}for(unsigned i=0;i<n;i++)if(!MN_ROW(d2_instrument,base+seen[i],end))return false;return true;}
bool sx_shogun_deltamusic2_build(sxmn_view*v)
{
 return sxmn_d2(v);
}
#undef MN_ROW
