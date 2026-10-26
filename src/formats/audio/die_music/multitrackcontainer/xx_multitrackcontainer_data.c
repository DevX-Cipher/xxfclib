/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE_MUSIC_MULTITRACKCONTAINER data structures, moved out of the pcmusicmore schema family. */
#include "../../../xx_format_schema_pcmusicmore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SXPCMORE_LIMIT 24000U
#define SXPCMORE_ADD(c,n,p) sxpcmore_put(c,&sxpcmore_##n,p,1)
static bool sxpcmore_text(sx_context*c,uint64_t p,uint64_t n){
 if(!sxpcmore_span(c,p,n))return false;if(!n||c->count>=SXPCMORE_LIMIT)return true;
 for(size_t i=0;i<c->count;i++){uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<a+z&&a<p+n)return true;}
 return sx_add(c,&sxpcmore_pcmore_text,(int64_t)p,(int64_t)n);
}
/* Known MTC nesting is MTC1 -> TRCK -> leaf. Chunk sizes do not include
 * alignment padding; arbitrary DATA bytes are never recursively interpreted. */
static bool sxpcmore_mtc_list(sx_context*c,uint64_t p,uint64_t end,unsigned depth,uint32_t*work){
 while(p<=end&&end-p>=8&&*work<1000000U){
  uint8_t h[8];if(!sxpcmore_read(c,p,h,8))return false;(*work)++;
  if(!SXPCMORE_ADD(c,mtc_chunk,p))return false;
  uint64_t n=sxpcmore_be32(h+4),body=p+8;if(n>end-body)return true;
  if(depth==0&&!xx_rt_memcmp(h,"TRCK",4)){if(!sxpcmore_mtc_list(c,body,body+n,1,work))return false;}
  else if(!xx_rt_memcmp(h,"NAME",4)||!xx_rt_memcmp(h,"AUTH",4)||!xx_rt_memcmp(h,"ANNO",4)||!xx_rt_memcmp(h,"PROP",4)){
   if(!sxpcmore_text(c,body,n))return false;
  }
  p=body+n;if(n&1){if(p==end)return true;p++;}
 }
 return !xx_pd_is_stopped(c->pd);
}
static bool sxpcmore_mtc(sx_context*c){
 uint8_t h[8];if(!sxpcmore_read(c,0,h,8)||xx_rt_memcmp(h,"MTC1",4))return false;
 if(!SXPCMORE_ADD(c,mtc_chunk,0))return false;
 uint64_t n=sxpcmore_be32(h+4);uint32_t work=0;
 return !sxpcmore_span(c,8,n)||sxpcmore_mtc_list(c,8,8+n,0,&work);
}
bool sx_multitrackcontainer_build(sx_context*c)
{
bool ok=false;
ok=sxpcmore_mtc(c);
(void)ok;return c->count&&sxpcmore_finish(c);
}
