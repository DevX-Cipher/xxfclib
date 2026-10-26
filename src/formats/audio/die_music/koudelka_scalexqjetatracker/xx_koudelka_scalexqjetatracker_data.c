/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC KOUDELKA SCALEXQJETATRACKER data structures, moved out of the chipmusic schema family. */
#include "../../../xx_format_schema_chipmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxchip_chip_sqt_sample_reference_fields[]={
 SX_FIELD("sample_reference","uint16",0,2,SX_ADDRESS),
};
const sx_layout sxchip_chip_sqt_sample_reference={UINT32_C(0x608F0014),"chip_sqt_sample_reference",sxchip_chip_sqt_sample_reference_fields,SX_COUNT(sxchip_chip_sqt_sample_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_sqt_ornament_reference_fields[]={
 SX_FIELD("ornament_reference","uint16",0,2,SX_ADDRESS),
};
const sx_layout sxchip_chip_sqt_ornament_reference={UINT32_C(0x608F0015),"chip_sqt_ornament_reference",sxchip_chip_sqt_ornament_reference_fields,SX_COUNT(sxchip_chip_sqt_ornament_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_sqt_pattern_reference_fields[]={
 SX_FIELD("pattern_reference","uint16",0,2,SX_ADDRESS),
};
const sx_layout sxchip_chip_sqt_pattern_reference={UINT32_C(0x608F0016),"chip_sqt_pattern_reference",sxchip_chip_sqt_pattern_reference_fields,SX_COUNT(sxchip_chip_sqt_pattern_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_sqt_loop_fields[]={
 SX_FIELD("loop_index","uint8",0,1,SX_NONE),
 SX_FIELD("loop_length","uint8",1,1,SX_COUNT_PROP),
};
const sx_layout sxchip_chip_sqt_loop={UINT32_C(0x608F0018),"chip_sqt_loop",sxchip_chip_sqt_loop_fields,SX_COUNT(sxchip_chip_sqt_loop_fields),SX_LE};
#define SXCHIP_ADD(c,n,p) sxchip_put(c,&sxchip_##n,p,1)
static bool sxchip_sqt(sx_context*c){
 uint8_t h[12];if(!sxchip_read(c,0,h,12))return false;if(!SXCHIP_ADD(c,chip_sqt_header,0))return false;
 uint64_t declared=sxchip16(h),s=sxchip16(h+2),o=sxchip16(h+4),t=sxchip16(h+6),p=sxchip16(h+8);
 if(s<10||o<=s||t<o||p<=t)return true;uint64_t delta=s-10;s=12;o=o-delta+2;t=t-delta+2;p-=delta;
 if(declared>(uint64_t)c->size||declared<12||o<s||t<o||p<t||p>=declared)return true;
 uint64_t sn=(o-s)/2,on=(t-o)/2;if(sn>26||on>26||(o-s)%2||(t-o)%2)return true;
 if(!sxchip_put(c,&sxchip_chip_sqt_sample_reference,s,sn)||!sxchip_put(c,&sxchip_chip_sqt_ornament_reference,o,on))return false;
 unsigned maxpat=0;uint64_t pos=p;
 for(unsigned n=0;n<1024&&pos+7<=declared;n++,pos+=7){uint8_t r[7];if(!sxchip_read(c,pos,r,7))break;if(!SXCHIP_ADD(c,chip_sqt_position,pos))return false;
  if(!(r[0]&127)||!(r[2]&127)||!(r[4]&127))break;
  for(unsigned j=0;j<6;j+=2)if((r[j]&127)>maxpat)maxpat=r[j]&127;
 }
 if(maxpat>99)return true;
 if(!sxchip_opt(c,&sxchip_chip_sqt_pattern_reference,t,maxpat))return false;
 for(unsigned k=0;k<2;k++){uint64_t at=k?o:s,n=k?on:sn;
  for(uint64_t i=0;i<n;i++){uint16_t ref;if(!sxchip_u16(c,at+2*i,&ref))break;if(ref<delta)continue;uint64_t q=ref-delta;
   if(!sxchip_span(c,q,k?34:98))continue;if(!SXCHIP_ADD(c,chip_sqt_loop,q))return false;
   if(!sxchip_put(c,k?&sxchip_chip_note_step:&sxchip_chip_sqt_sample_line,q+2,32))return false;
  }
 }
 return true;
}
bool sx_koudelka_scalexqjetatracker_build(sx_context*c)
{
 return sxchip_sqt(c);
}
