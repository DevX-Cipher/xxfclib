/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC RESOLUTION AXS data structures, moved out of the pcmusic schema family. */
#include "../../../xx_format_schema_pcmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxpcm_axs_chunk_fields[]={
 SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
 SX_FIELD("payload_byte_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxpcm_axs_chunk={UINT32_C(0x60940046),"axs_chunk",sxpcm_axs_chunk_fields,SX_COUNT(sxpcm_axs_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxpcm_axs_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("velocity","uint8",1,1,SX_NONE),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("effect_parameter","uint8",3,1,SX_NONE),
};
const sx_layout sxpcm_axs_event={UINT32_C(0x60940049),"axs_event",sxpcm_axs_event_fields,SX_COUNT(sxpcm_axs_event_fields),SX_LE};
#define SXPCM_ADD(c,n,p) sxpcm_put(c,&sxpcm_##n,p,1)
static bool sxpcm_axs(sx_context*c){
 uint8_t h[12];if(!sxpcm_read(c,0,h,12)||xx_rt_memcmp(h,"FORM",4)||xx_rt_memcmp(h+8,"AXSF",4)||!SXPCM_ADD(c,axs_form,0))return false;
 uint64_t end=8+((uint64_t)h[4]<<24|((uint64_t)h[5]<<16)|((uint64_t)h[6]<<8)|h[7]);if(end>(uint64_t)c->size)end=(uint64_t)c->size;uint64_t p=12;
 /* AXS chunks are not padded to even boundaries. Unknown payloads, including
  * synth parameters and sample bodies, retain their physical raw spans. */
 for(unsigned work=0;work<100000&&p<=end&&end-p>=8;work++){
  uint8_t b[8];if(!sxpcm_read(c,p,b,8)||!SXPCM_ADD(c,axs_chunk,p))return true;p+=8;
  uint64_t n=((uint64_t)b[4]<<24)|((uint64_t)b[5]<<16)|((uint64_t)b[6]<<8)|b[7];if(n>end-p)break;
  if(!xx_rt_memcmp(b,"USER",4)||!xx_rt_memcmp(b,"INNM",4)){if(!sxpcm_text(c,p,n))return false;}
  else if(!xx_rt_memcmp(b,"SHDR",4)&&n==20){if(!SXPCM_ADD(c,axs_settings,p))return false;}
  else if(!xx_rt_memcmp(b,"SONG",4)&&n%8==0){if(!sxpcm_put(c,&sxpcm_axs_sequence,p,n/8))return false;}
  else if(!xx_rt_memcmp(b,"TRAK",4)&&n==256){if(!sxpcm_put(c,&sxpcm_axs_event,p,64))return false;}
  p+=n;
 }return true;
}
bool sx_resolution_axs_build(sx_context*c)
{
 return sxpcm_axs(c);
}
