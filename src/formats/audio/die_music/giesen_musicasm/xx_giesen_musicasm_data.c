/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * giesen_musicasm data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_ma_speed_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
};
const sx_layout sxnextm_ma_speed={UINT32_C(0x608B0068),"ma_speed",sxnextm_ma_speed_fields,SX_COUNT(sxnextm_ma_speed_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ma_instrument_fields[]={
 SX_FIELD("sample_number","uint8",0,1,SX_ID),
 SX_FIELD("attack","uint8",1,1,SX_NONE),
 SX_FIELD("decay_sustain","uint8",2,1,SX_FLAGS),
 SX_FIELD("vibrato_delay","uint8",3,1,SX_NONE),
 SX_FIELD("release","uint8",4,1,SX_NONE),
 SX_FIELD("vibrato_speed","uint8",5,1,SX_NONE),
 SX_FIELD("vibrato_level","uint8",6,1,SX_NONE),
 SX_FIELD("arpeggio","uint8",7,1,SX_FLAGS),
 SX_FIELD("fx_arpeggio_speed_loop","uint8",8,1,SX_FLAGS),
 SX_FIELD("hold","uint8",9,1,SX_NONE),
 SX_FIELD("key_wave_rate","uint8",10,1,SX_FLAGS),
 SX_FIELD("wave_level_speed","uint8",11,1,SX_FLAGS),
 SX_FIELD("unknown","bytes",12,4,SX_NONE),
};
const sx_layout sxnextm_ma_instrument={UINT32_C(0x608B0069),"ma_instrument",sxnextm_ma_instrument_fields,SX_COUNT(sxnextm_ma_instrument_fields),SX_LE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
#define NX_TAKE(l,p,n,end) sxnextm_take(v,&sxnextm_##l,(p),(n),(end))
static bool sxnextm_ma(sxnextm_view*v)
{uint64_t e=(uint64_t)v->c->size,limit=e<0x700?e:0x700,p,n,speeds,subs,base,ip,sp,tp,ins,samples,tracks,minpos=UINT64_MAX,maxtrack=0;bool have_track=false;
 if(e<0x622||!sxnextm_eq(v,0,"\x60\x00",2,e)||!sxnextm_eq(v,4,"\x60\x00",2,e)||!sxnextm_eq(v,8,"\x60\x00",2,e)||!sxnextm_eq(v,12,"\x48\xe7",2,e)||!sxnextm_rel(v,2,2,2,&p,limit)||!sxnextm_find16(v,&p,0xb07c,limit-4,e)||!sxnextm_be(v,p+2,2,&n,e)||!n||n>256)return false;
 p+=4;if(!sxnextm_find16(v,&p,0x49fa,limit-4,e)||!sxnextm_rel(v,p+2,2,p+2,&speeds,e))return false;
 p+=4;if(!sxnextm_find16(v,&p,0x49fb,limit-4,e)||!sxnextm_rel(v,p+3,1,p+2,&subs,e))return false;
 p=12;if(!sxnextm_find16(v,&p,0x43fa,limit-4,e)||!sxnextm_rel(v,p+2,2,p+2,&base,e))return false;
 p+=4;if(!sxnextm_find16(v,&p,0xd3fa,limit-8,e)||!sxnextm_rel(v,p+2,2,p+2,&ip,e)||!sxnextm_eq(v,p+4,"\xd5\xfa",2,e)||!sxnextm_rel(v,p+6,2,p+6,&sp,e))return false;
 p+=8;for(;p+2<limit;p+=2){uint64_t op;if(!sxnextm_u(v,p,1,&op,e))return false;if(op==0x61)break;}
 if(p+2>=limit||!sxnextm_rel(v,p+1,1,p+2,&p,limit)||!sxnextm_find16(v,&p,0xdbfa,limit-4,e)||!sxnextm_rel(v,p+2,2,p+2,&tp,e)||!sxnextm_rel32(v,ip,base,&ins,e)||!sxnextm_rel32(v,sp,base,&samples,e)||!sxnextm_rel32(v,tp,base,&tracks,e))return false;
 if(!NX_ROW(ma_relative32,ip,e)||!NX_ROW(ma_relative32,sp,e)||!NX_ROW(ma_relative32,tp,e)||!sxnextm_table(v,&sxnextm_ma_speed,speeds,n,e)||!sxnextm_table(v,&sxnextm_ma_subsong,subs,n,e))return false;
 for(uint64_t i=0;i<n*4;i++){uint64_t rel,pos;if(!sxnextm_be(v,subs+i*2,2,&rel,e)||rel>e-base)return false;pos=base+rel;if(pos<minpos)minpos=pos;
  for(unsigned j=0;;j++){uint64_t track;if(j>=65536||!sxnextm_u(v,pos,1,&track,e)||!NX_TAKE(ma_position,&pos,1,e))return false;if(track>=254)break;if(track+1>maxtrack)maxtrack=track+1;have_track=true;}}
 if(have_track){if(!sxnextm_table(v,&sxnextm_ma_track_offset,base,maxtrack,e))return false;for(uint64_t i=0;i<maxtrack;i++){uint64_t x;if(!sxnextm_be(v,base+i*2,2,&x,e)||x>e-tracks)return false;}}
 if(ins>samples||samples>minpos||(samples-ins)%16||(minpos-samples)%24||!sxnextm_table(v,&sxnextm_ma_instrument,ins,(samples-ins)/16,e)||!sxnextm_table(v,&sxnextm_ma_sample,samples,(minpos-samples)/24,e))return false;
 return true;}
bool sx_giesen_musicasm_build(sxnextm_view*v)
{
 return sxnextm_ma(v);
}
#undef NX_ROW
#undef NX_TAKE
