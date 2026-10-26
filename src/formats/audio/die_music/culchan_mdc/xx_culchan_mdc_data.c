/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE_MUSIC_CULCHAN_MDC data structures, moved out of the pcmusicmore schema family. */
#include "../../../xx_format_schema_pcmusicmore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxpcmore_mdc_track_count_fields[]={
 SX_FIELD("track_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxpcmore_mdc_track_count={UINT32_C(0x6099000D),"mdc_track_count",sxpcmore_mdc_track_count_fields,SX_COUNT(sxpcmore_mdc_track_count_fields),SX_BE};
#define SXPCMORE_LIMIT 24000U
#define SXPCMORE_ADD(c,n,p) sxpcmore_put(c,&sxpcmore_##n,p,1)
/* Strings have dynamic physical width but share a genuine string-field layout. */
static bool sxpcmore_string(sx_context*c,uint64_t p){uint8_t ch;uint64_t n=0;while(n<4096&&sxpcmore_u8(c,p+n,&ch)){n++;if(!ch){if(c->count>=SXPCMORE_LIMIT)return true;for(size_t i=0;i<c->count;i++){uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<a+z&&a<p+n)return true;}return sx_add(c,&sxpcmore_pcmore_text,(int64_t)p,(int64_t)n);}}return true;}
static uint16_t sxpcmorebe16(const uint8_t*b){return (uint16_t)((uint16_t)b[0]<<8)|b[1];}
static bool sxpcmore_mdc(sx_context*c){
 uint8_t h[64];if(!sxpcmore_read(c,0,h,sizeof(h))||xx_rt_memcmp(h,"MDC\032\000\010\000\100",8))return false;
 if(!SXPCMORE_ADD(c,mdc_header,0))return false;
 uint64_t table=sxpcmore_be32(h+16),comment=sxpcmore_be32(h+20);uint8_t n[2];
 if(table>=64&&sxpcmore_read(c,table,n,2)){
  uint16_t count=sxpcmorebe16(n);if(!SXPCMORE_ADD(c,mdc_track_count,table))return false;
  if(sxpcmore_span(c,table+2,(uint64_t)count*8)&&!sxpcmore_put(c,&sxpcmore_mdc_track,table+2,count))return false;
 }
 if(comment>=64&&sxpcmore_span(c,comment,1)&&!sxpcmore_string(c,comment))return false;
 return true;
}
bool sx_culchan_mdc_build(sx_context*c)
{
bool ok=false;
ok=sxpcmore_mdc(c);
(void)ok;return c->count&&sxpcmore_finish(c);
}
