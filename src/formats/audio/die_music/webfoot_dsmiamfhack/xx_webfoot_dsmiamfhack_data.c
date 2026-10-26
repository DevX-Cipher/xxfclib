/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE_MUSIC_WEBFOOT_DSMIAMFHACK data structures, moved out of the pcmusicmore schema family. */
#include "../../../xx_format_schema_pcmusicmore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxpcmore_webfoot_dmf_header_fields[]={
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("sample_count","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("order_count","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("logical_track_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("channel_count","uint8",8,1,SX_COUNT_PROP),
};
const sx_layout sxpcmore_webfoot_dmf_header={UINT32_C(0x60990002),"webfoot_dmf_header",sxpcmore_webfoot_dmf_header_fields,SX_COUNT(sxpcmore_webfoot_dmf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_webfoot_dmf_timing_fields[]={
 SX_FIELD("tempo_bpm","uint8",0,1,SX_NONE),
 SX_FIELD("speed","uint8",1,1,SX_NONE),
};
const sx_layout sxpcmore_webfoot_dmf_timing={UINT32_C(0x60990004),"webfoot_dmf_timing",sxpcmore_webfoot_dmf_timing_fields,SX_COUNT(sxpcmore_webfoot_dmf_timing_fields),SX_LE};
static const xx_data_struct_field_desc sxpcmore_webfoot_dmf_order_fields[]={
 SX_FIELD("row_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxpcmore_webfoot_dmf_order={UINT32_C(0x60990005),"webfoot_dmf_order",sxpcmore_webfoot_dmf_order_fields,SX_COUNT(sxpcmore_webfoot_dmf_order_fields),SX_LE};
static bool sxpcmore_u16(sx_context*c,uint64_t p,uint16_t*v){uint8_t b[2];if(!sxpcmore_read(c,p,b,2))return false;*v=sxpcmore16(b);return true;}
#define SXPCMORE_ADD(c,n,p) sxpcmore_put(c,&sxpcmore_##n,p,1)
static bool sxpcmore_webfoot(sx_context*c){
 uint8_t h[9];if(!sxpcmore_read(c,0,h,sizeof(h))||xx_rt_memcmp(h,"DMF\016",4))return false;
 if(!SXPCMORE_ADD(c,webfoot_dmf_header,0))return false;
 unsigned samples=h[4],orders=h[5],tracks=sxpcmore16(h+6),channels=h[8];uint64_t p=9;
 if(!channels||channels>32)return true;
 if(!sxpcmore_span(c,p,34))return true;
 if(!SXPCMORE_ADD(c,webfoot_dmf_panning,p)||!SXPCMORE_ADD(c,webfoot_dmf_timing,p+32))return false;p+=34;
 for(unsigned i=0;i<orders;i++){
  if(!sxpcmore_span(c,p,2+2U*channels))return true;
  if(!SXPCMORE_ADD(c,webfoot_dmf_order,p)||!sxpcmore_put(c,&sxpcmore_webfoot_dmf_track_reference,p+2,channels))return false;p+=2+2U*channels;
 }
 if(!sxpcmore_span(c,p,20U*samples))return true;
 if(!sxpcmore_put(c,&sxpcmore_webfoot_dmf_sample,p,samples))return false;p+=20U*samples;
 if(!sxpcmore_span(c,p,2U*tracks))return true;
 unsigned highest=0;for(unsigned i=0;i<tracks;i++){uint16_t n;if(!sxpcmore_u16(c,p+2U*i,&n))return false;if(n>highest)highest=n;}
 if(!sxpcmore_put(c,&sxpcmore_webfoot_dmf_track_map,p,tracks))return false;p+=2U*tracks;
 for(unsigned i=0;i<highest;i++){
  uint8_t b[3];if(!sxpcmore_read(c,p,b,3))return true;
  if(!SXPCMORE_ADD(c,webfoot_dmf_track,p))return false;p+=3;
  uint16_t n=sxpcmore16(b);if(!sxpcmore_span(c,p,3U*n))return true;
  if(!sxpcmore_put(c,&sxpcmore_webfoot_dmf_event,p,n))return false;p+=3U*n;
 }
 return true;
}
bool sx_webfoot_dsmiamfhack_build(sx_context*c)
{
bool ok=false;
ok=sxpcmore_webfoot(c);
(void)ok;return c->count&&sxpcmore_finish(c);
}
