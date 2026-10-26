/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Kva Prosoundcreator data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxzxm_prosoundcreator_position_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
 SX_FIELD("line_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("channel_a_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("channel_b_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("channel_c_offset","uint16",6,2,SX_OFFSET),
};
const sx_layout sxzxm_prosoundcreator_position={UINT32_C(0x608A002B),"prosoundcreator_position",sxzxm_prosoundcreator_position_fields,SX_COUNT(sxzxm_prosoundcreator_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundcreator_end_fields[]={
 SX_FIELD("loop_position","uint8",0,1,SX_NONE),
 SX_FIELD("marker","uint8",1,1,SX_ID),
};
const sx_layout sxzxm_prosoundcreator_end={UINT32_C(0x608A002C),"prosoundcreator_end",sxzxm_prosoundcreator_end_fields,SX_COUNT(sxzxm_prosoundcreator_end_fields),SX_LE};
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
static bool sxzxm_psc(sx_context*c){
 uint8_t h[76];if(!sxzxm_read(c,0,h,76)||!SXZXM_ADD(c,prosoundcreator_header,0))return false;
 unsigned samples=sxzxm16(h+69),pos=sxzxm16(h+71),orn=sxzxm16(h+74);if(orn<76||samples<orn)return true;
 unsigned sc=(orn-76)/2,oc=(samples-orn)/2;if(sc>32)sc=32;if(oc>32)oc=32;
 if(!sxzxm_opt(c,&sxzxm_prosoundcreator_sample_ref,76,sc)||!sxzxm_opt(c,&sxzxm_prosoundcreator_ornament_ref,orn,oc))return false;
 /* Confirm the known writer variant by the first physical sample: its
  * pointer targets SamplesStart+1, after the unused index byte. */
 uint16_t first;bool relative=false,known=false;if(sxzxm_u16(c,76,&first)){if((uint64_t)first+76==(uint64_t)samples+1)relative=known=true;else if(first==(unsigned)samples+1)known=true;}
 if(known)for(unsigned k=0;k<2;k++){unsigned tab=k?orn:76,count=k?oc:sc,width=k?2:6,max=32;const sx_layout*l=k?&sxzxm_prosoundcreator_ornament_line:&sxzxm_prosoundcreator_sample_line;
  for(unsigned i=0;i<count;i++){uint16_t ref;if(!sxzxm_u16(c,tab+2U*i,&ref))break;uint64_t p=(uint64_t)ref+(relative?tab:0);uint8_t f;unsigned n=0;if(p<=samples)continue;for(;n<max;n++){if(!sxzxm_span(c,p+(uint64_t)n*width,width)||!sxzxm_u8(c,p+(uint64_t)n*width+(k?0:4),&f))break;if(!(f&32)){n++;break;}}if(!sxzxm_opt(c,l,p,n))return false;}}
 for(unsigned i=0;i<256;i++){uint64_t p=(uint64_t)pos+8U*i;uint8_t b;if(!sxzxm_u8(c,p+1,&b))break;if(b==255){if(!sxzxm_opt(c,&sxzxm_prosoundcreator_end,p,1)||!sxzxm_opt(c,&sxzxm_prosoundcreator_loop,p+2,1))return false;break;}if(!sxzxm_span(c,p,8))break;if(!SXZXM_ADD(c,prosoundcreator_position,p))return false;}
 return true;
}
bool sx_kva_prosoundcreator_build(sx_context*c)
{
 return sxzxm_psc(c);
}
