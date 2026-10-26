/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE_MUSIC_BAKTERY_SKALETRACKER_SKM data structures, moved out of the pcmusicmore schema family. */
#include "../../../xx_format_schema_pcmusicmore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxpcmore_skm_title_fields[]={
 SX_FIELD("title","char",0,0,SX_NONE),
};
const sx_layout sxpcmore_skm_title={UINT32_C(0x60990013),"skm_title",sxpcmore_skm_title_fields,SX_COUNT(sxpcmore_skm_title_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_skm_channel_fields[]={
 SX_FIELD("channel_index","uint8",0,1,SX_NONE),
};
const sx_layout sxpcmore_skm_channel={UINT32_C(0x60990018),"skm_channel",sxpcmore_skm_channel_fields,SX_COUNT(sxpcmore_skm_channel_fields),SX_LE};
#define SXPCMORE_LIMIT 24000U
#define SXPCMORE_ADD(c,n,p) sxpcmore_put(c,&sxpcmore_##n,p,1)
static uint32_t sxpcmore32(const uint8_t*b){return (uint32_t)b[0]|(uint32_t)b[1]<<8|(uint32_t)b[2]<<16|(uint32_t)b[3]<<24;}
static bool sxpcmore_skm_tracks(sx_context*c,uint64_t p,uint64_t end,uint32_t*work){
 while(p<=end&&end-p>=4&&*work<1000000U){
  uint8_t h[4];if(!sxpcmore_read(c,p,h,4))return false;(*work)++;
  if(!SXPCMORE_ADD(c,skm_track_chunk,p))return false;uint64_t n=sxpcmore16(h+2);p+=4;
  if(n>end-p)return true;
  if(h[0]==1&&h[1]==1&&n&&!SXPCMORE_ADD(c,skm_channel,p))return false;
  p+=n;if(h[1]==255)return true;
 }
 return !xx_pd_is_stopped(c->pd);
}
static bool sxpcmore_skm_patterns(sx_context*c,uint64_t p,uint64_t end,uint32_t*work){
 while(p<=end&&end-p>=8&&*work<1000000U){
  uint8_t h[8];if(!sxpcmore_read(c,p,h,8))return false;(*work)++;
  if(!SXPCMORE_ADD(c,skm_chunk,p))return false;uint64_t n=sxpcmore32(h+4);p+=8;
  if(n>end-p)return true;
  if(sxpcmore16(h)==1&&sxpcmore16(h+2)==1&&n>=3){
   if(!SXPCMORE_ADD(c,skm_pattern,p)||!sxpcmore_skm_tracks(c,p+3,p+n,work))return false;
  }
  p+=n;if(sxpcmore16(h+2)==65535)return true;
 }
 return !xx_pd_is_stopped(c->pd);
}
static bool sxpcmore_skm(sx_context*c){
 uint8_t head[17];if(!sxpcmore_read(c,0,head,17)||sxpcmore16(head)!=1||sxpcmore16(head+2)!=65534||sxpcmore32(head+4)!=9||xx_rt_memcmp(head+8,"ALIM3",5))return false;
 if(!SXPCMORE_ADD(c,skm_chunk,0)||!SXPCMORE_ADD(c,skm_file_payload,8))return false;
 uint64_t p=17,end=(uint64_t)c->size;uint32_t work=0;
 while(p<=end&&end-p>=8&&work<1000000U){
  uint8_t h[8];if(!sxpcmore_read(c,p,h,8))return false;work++;
  if(!SXPCMORE_ADD(c,skm_chunk,p))return false;uint64_t n=sxpcmore32(h+4);p+=8;
  if(n>end-p)return true;
  uint16_t tag=sxpcmore16(h+2);
  if(tag==1&&n>=9){
   uint64_t text_end=p+n-8,z=p;uint8_t ch=1;
   while(z<text_end&&z-p<1048576U){if(!sxpcmore_u8(c,z++,&ch))return false;if(!ch)break;}
   if(!ch){
    if(c->count<SXPCMORE_LIMIT&&!sx_add(c,&sxpcmore_skm_title,(int64_t)p,(int64_t)(z-p)))return false;
    if(z<text_end&&sxpcmore_u8(c,z,&ch)&&!ch)z++;
    if(z<text_end&&c->count<SXPCMORE_LIMIT&&!sx_add(c,&sxpcmore_skm_message,(int64_t)z,(int64_t)(text_end-z)))return false;
   }
   if(!SXPCMORE_ADD(c,skm_song_timing,text_end))return false;
  }else if(tag==2&&n>=259){
   if(!SXPCMORE_ADD(c,skm_orders,p)||!sxpcmore_skm_patterns(c,p+259,p+n,&work))return false;
  }
  p+=n;if(tag==65535)return true;
 }
 return !xx_pd_is_stopped(c->pd);
}
bool sx_baktery_skaletracker_skm_build(sx_context*c)
{
bool ok=false;
ok=sxpcmore_skm(c);
(void)ok;return c->count&&sxpcmore_finish(c);
}
