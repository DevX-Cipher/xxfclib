/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Bzyk Soundtracker Ayst11 data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxzxm_zx_text_fields[]={
 SX_FIELD("text","char",0,0,SX_NONE),
};
const sx_layout sxzxm_zx_text={UINT32_C(0x608A000D),"zx_text",sxzxm_zx_text_fields,SX_COUNT(sxzxm_zx_text_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_ayst11_song_data_fields[]={
 SX_FIELD("channel_a","uint8",0,1,SX_ID),
 SX_FIELD("channel_b","uint8",1,1,SX_ID),
 SX_FIELD("channel_c","uint8",2,1,SX_ID),
 SX_FIELD("noise_channel","uint8",3,1,SX_ID),
 SX_FIELD("opaque","bytes",4,4,SX_NONE),
};
const sx_layout sxzxm_ayst11_song_data={UINT32_C(0x608A0061),"ayst11_song_data",sxzxm_ayst11_song_data_fields,SX_COUNT(sxzxm_ayst11_song_data_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st1_position_fields[]={
 SX_FIELD("pattern_number","uint8",0,1,SX_NONE),
 SX_FIELD("transposition","int8",1,1,SX_NONE),
};
const sx_layout sxzxm_st1_position={UINT32_C(0x608A0063),"st1_position",sxzxm_st1_position_fields,SX_COUNT(sxzxm_st1_position_fields),SX_LE};
#define SXZXM_LIMIT 24000U
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
/* Strings have dynamic physical width but share a genuine string-field layout. */
static bool sxzxm_string(sx_context*c,uint64_t p){uint8_t ch;uint64_t n=0;while(n<4096&&sxzxm_u8(c,p+n,&ch)){n++;if(!ch){if(c->count>=SXZXM_LIMIT)return true;for(size_t i=0;i<c->count;i++){uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<a+z&&a<p+n)return true;}return sx_add(c,&sxzxm_zx_text,(int64_t)p,(int64_t)n);}}return true;}
static bool sxzxm_delta(sx_context*c,uint64_t at,uint64_t*out){uint8_t b[2];if(!sxzxm_read(c,at,b,2))return false;unsigned u=(unsigned)b[0]*256U+b[1];int64_t d=u<32768?u:(int64_t)u-65536;if(d<0&&(uint64_t)(-d)>at)return false;if(d>=0&&at>UINT64_MAX-(uint64_t)d)return false;*out=d<0?at-(uint64_t)(-d):at+(uint64_t)d;return sxzxm_span(c,*out,0);}
static bool sxzxm_st1(sx_context*c,uint64_t p){
 if(!sxzxm_span(c,p,3009))return true;
 if(!sxzxm_put(c,&sxzxm_st1_sample,p,15)||!sxzxm_put(c,&sxzxm_st1_position,p+1950,256)||!SXZXM_ADD(c,st1_song_length,p+2462)||!sxzxm_put(c,&sxzxm_st1_ornament_step,p+2463,544)||!SXZXM_ADD(c,st1_playback,p+3007))return false;
 /* The AY song has no physical end pointer. Pattern bytecode and any following
  * songs remain raw rather than inferring their count from the container tail. */
 return true;
}
static bool sxzxm_ayst(sx_context*c){
 if(!SXZXM_ADD(c,ayst11_header,0))return false;uint8_t last;uint64_t p;
 for(unsigned at=12;at<=14;at+=2)if(sxzxm_delta(c,at,&p)&&!sxzxm_string(c,p))return false;
 if(!sxzxm_u8(c,16,&last)||!sxzxm_delta(c,18,&p)||!sxzxm_span(c,p,4U*((unsigned)last+1)))return true;
 if(!sxzxm_put(c,&sxzxm_ayst11_song,p,(unsigned)last+1))return false;
 for(unsigned i=0;i<=(unsigned)last;i++){uint64_t name,data,at=p+4U*i;if(sxzxm_delta(c,at,&name)&&!sxzxm_string(c,name))return false;if(sxzxm_delta(c,at+2,&data)&&sxzxm_span(c,data,8)){if(!SXZXM_ADD(c,ayst11_song_data,data)||!sxzxm_st1(c,data+8))return false;}}
 return true;
}
bool sx_bzyk_soundtracker_ayst11_build(sx_context*c)
{
 return sxzxm_ayst(c);
}
