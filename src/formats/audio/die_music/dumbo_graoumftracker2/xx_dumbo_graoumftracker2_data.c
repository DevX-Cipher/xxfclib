/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Laurent 'Dumbo' de Soras's Graoumf Tracker 2 module (.GT2) data structures, moved out of the musictail schema family. */
#include "../../../xx_format_schema_musictail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmta_gt2_header_new_fields[]={
 SX_FIELD("magic","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("header_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("title","char[32]",8,32,SX_NONE),
 SX_FIELD("comment","char[160]",40,160,SX_NONE),
 SX_FIELD("day","uint8",200,1,SX_NONE),
 SX_FIELD("month","uint8",201,1,SX_NONE),
 SX_FIELD("year","uint16",202,2,SX_NONE),
 SX_FIELD("tracker","char[24]",204,24,SX_NONE),
};
const sx_layout sxmta_gt2_header_new={UINT32_C(0x60810012),"gt2_header_new",sxmta_gt2_header_new_fields,SX_COUNT(sxmta_gt2_header_new_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_header_old_fields[]={
 SX_FIELD("magic","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("header_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("title","char[32]",8,32,SX_NONE),
 SX_FIELD("comment","char[160]",40,160,SX_NONE),
 SX_FIELD("day","uint8",200,1,SX_NONE),
 SX_FIELD("month","uint8",201,1,SX_NONE),
 SX_FIELD("year","uint16",202,2,SX_NONE),
 SX_FIELD("tracker","char[24]",204,24,SX_NONE),
 SX_FIELD("speed","uint16",228,2,SX_NONE),
 SX_FIELD("tempo","uint16",230,2,SX_NONE),
 SX_FIELD("master_volume","uint16",232,2,SX_NONE),
 SX_FIELD("panned_tracks","uint16",234,2,SX_COUNT_PROP),
};
const sx_layout sxmta_gt2_header_old={UINT32_C(0x60810013),"gt2_header_old",sxmta_gt2_header_old_fields,SX_COUNT(sxmta_gt2_header_old_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_song_fields[]={
 SX_FIELD("orders","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("restart_order","uint16",2,2,SX_NONE),
};
const sx_layout sxmta_gt2_song={UINT32_C(0x60810015),"gt2_song",sxmta_gt2_song_fields,SX_COUNT(sxmta_gt2_song_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_track_name_fields[]={
 SX_FIELD("track_type","uint16",0,2,SX_ID),
 SX_FIELD("track_index","uint16",2,2,SX_ID),
 SX_FIELD("name","char[32]",4,32,SX_NONE),
};
const sx_layout sxmta_gt2_track_name={UINT32_C(0x60810017),"gt2_track_name",sxmta_gt2_track_name_fields,SX_COUNT(sxmta_gt2_track_name_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_instrument_fields[]={
 SX_FIELD("instrument","uint16",0,2,SX_ID),
 SX_FIELD("name","char[28]",2,28,SX_NONE),
 SX_FIELD("instrument_type","uint16",30,2,SX_ID),
 SX_FIELD("default_velocity","uint16",32,2,SX_NONE),
 SX_FIELD("default_pan","int16",34,2,SX_NONE),
 SX_FIELD("volume_envelope","uint16",36,2,SX_ID),
 SX_FIELD("tone_envelope","uint16",38,2,SX_ID),
 SX_FIELD("pan_envelope","uint16",40,2,SX_ID),
 SX_FIELD("cutoff_envelope","uint16",42,2,SX_ID),
 SX_FIELD("resonance_envelope","uint16",44,2,SX_ID),
 SX_FIELD("reserved","bytes",46,4,SX_RESERVED),
 SX_FIELD("version","uint16",50,2,SX_ID),
};
const sx_layout sxmta_gt2_instrument={UINT32_C(0x6081001C),"gt2_instrument",sxmta_gt2_instrument_fields,SX_COUNT(sxmta_gt2_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_note_map_fields[]={
 SX_FIELD("sample","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
const sx_layout sxmta_gt2_note_map={UINT32_C(0x6081001D),"gt2_note_map",sxmta_gt2_note_map_fields,SX_COUNT(sxmta_gt2_note_map_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_gt2_volume_fields[]={
 SX_FIELD("volume","uint16",0,2,SX_NONE),
};
const sx_layout sxmta_gt2_volume={UINT32_C(0x60810051),"gt2_volume",sxmta_gt2_volume_fields,SX_COUNT(sxmta_gt2_volume_fields),SX_BE};
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
static bool sxmta_gt2(sxmta_view*v)
{uint64_t end=v->c->size,p,n,ver,x,y,z,ce,at;uint8_t tag[4];
 if(!sxmta_eq(v,0,"GT2",3,end)||!sxmta_u(v,3,1,&ver,end)||ver>9||!sxmta_be(v,4,4,&p,end)||!sxmta_span(v,0,p,end))return false;
 if(ver<=5){if(p<236||!MTA_ROW(gt2_header_old,0,end)||!sxmta_be(v,234,2,&n,end)||!sxmta_table(v,&sxmta_pan16be,236,n,p))return false;}else if(p<228||!MTA_ROW(gt2_header_new,0,end))return false;
 while(p<end){if(!sxmta_read(v,p,tag,4,end)||!sxmta_be(v,p+4,4,&n,end)||n<8||!sxmta_span(v,p,n,end)||!MTA_ROW(gt2_chunk,p,end))return false;ce=p+n;at=p;p+=8;
  if(!xx_rt_memcmp(tag,"PATS",4)){if(!MTA_ROW(count16be,p,ce))return false;}
  else if(!xx_rt_memcmp(tag,"SONG",4)){if(!sxmta_be(v,p,2,&x,ce)||!MTA_TAKE(gt2_song,&p,1,ce)||!MTA_TAKE(order16be,&p,x,ce))return false;}
  else if(!xx_rt_memcmp(tag,"PATD",4)){if(!sxmta_be(v,p+18,2,&x,ce)||!sxmta_be(v,p+20,2,&y,ce)||!sxmta_be(v,p+22,2,&z,ce)||!MTA_TAKE(gt2_pattern,&p,1,ce))return false;if(x<=1&&!MTA_TAKE(gtk_event5,&p,y*z,ce))return false;}
  else if(!xx_rt_memcmp(tag,"TNAM",4)||!xx_rt_memcmp(tag,"TVOL",4)){if(!sxmta_be(v,p,2,&x,ce)||!MTA_TAKE(count16be,&p,1,ce)||!sxmta_take(v,tag[1]=='N'?&sxmta_gt2_track_name:&sxmta_gt2_volume,&p,x,ce))return false;}
  else if(!xx_rt_memcmp(tag,"TCN2",4)){if(!sxmta_be(v,p,2,&x,ce)||!MTA_TAKE(gt2_timing,&p,1,ce)||(x&&!MTA_TAKE(gt2_period_mode,&p,1,ce)))return false;}
  else if(!xx_rt_memcmp(tag,"INST",4)){if(!MTA_TAKE(gt2_instrument,&p,1,ce)||!MTA_TAKE(gt2_note_map,&p,128,ce))return false;}
  else if(!xx_rt_memcmp(tag,"SAMP",4)){if(!MTA_ROW(gt2_sample1,p,ce))return false;}
  else if(!xx_rt_memcmp(tag,"SAM2",4)){uint64_t kind,bits,channels,frames,pcm=0;
   if(!sxmta_be(v,p+30,2,&kind,ce)||!sxmta_be(v,p+32,2,&bits,ce)||!sxmta_be(v,p+36,2,&channels,ce)||!sxmta_be(v,p+48,2,&x,ce)||!sxmta_be(v,p+50,2,&y,ce)||!sxmta_be(v,p+58,4,&frames,ce)||!sxmta_be(v,p+74,4,&z,ce)||!MTA_TAKE(gt2_sample2,&p,1,ce))return false;
   /* The filename follows any in-memory PCM at chunk-relative dataOffset.
    * Unknown encodings remain raw rather than inventing a text coordinate. */
   if(kind<=1&&x<=1&&(bits==8||bits==16)&&(channels==1||channels==2)){
    if(kind==0)pcm=frames*channels*(bits/8);
    if(z<86||!sxmta_span(v,at,z,ce)||!sxmta_span(v,at+z,pcm,ce)||!sxmta_text_emit(v,at+z+pcm,y,ce))return false;
   }
  }
  p=ce;if(!xx_rt_memcmp(tag,"ENDC",4))return true;
 }return true;}
bool sx_dumbo_graoumftracker2_build(sxmta_view*v)
{
 return sxmta_gt2(v);
}
#undef MTA_ROW
#undef MTA_TAKE
