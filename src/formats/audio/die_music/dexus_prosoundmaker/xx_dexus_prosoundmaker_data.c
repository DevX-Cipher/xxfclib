/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Dexus Prosoundmaker data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxzxm_prosoundmaker_header_fields[]={
 SX_FIELD("positions_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("samples_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("ornaments_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("patterns_offset","uint16",6,2,SX_OFFSET),
};
const sx_layout sxzxm_prosoundmaker_header={UINT32_C(0x608A0030),"prosoundmaker_header",sxzxm_prosoundmaker_header_fields,SX_COUNT(sxzxm_prosoundmaker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundmaker_pattern_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("channel_a_offset","uint16",1,2,SX_OFFSET),
 SX_FIELD("channel_b_offset","uint16",3,2,SX_OFFSET),
 SX_FIELD("channel_c_offset","uint16",5,2,SX_OFFSET),
};
const sx_layout sxzxm_prosoundmaker_pattern={UINT32_C(0x608A0032),"prosoundmaker_pattern",sxzxm_prosoundmaker_pattern_fields,SX_COUNT(sxzxm_prosoundmaker_pattern_fields),SX_LE};
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
static bool sxzxm_psm(sx_context*c){
 uint8_t h[8];if(!sxzxm_read(c,0,h,8)||!SXZXM_ADD(c,prosoundmaker_header,0))return false;unsigned pos=sxzxm16(h),sp=sxzxm16(h+2),op=sxzxm16(h+4),pt=sxzxm16(h+6),patterns=0,n=0;uint8_t v;
 for(;n<256;n++){if(!sxzxm_span(c,(uint64_t)pos+2U*n,2)||!sxzxm_u8(c,(uint64_t)pos+2U*n,&v))break;if(v==255){n++;break;}if(v>=32)break;if((unsigned)v+1>patterns)patterns=v+1;}
 if(!sxzxm_opt(c,&sxzxm_prosoundmaker_position,pos,n)||!sxzxm_opt(c,&sxzxm_prosoundmaker_pattern,pt,patterns))return false;
 uint16_t first;unsigned sc=0,oc=0;
 if(sxzxm_u16(c,sp,&first)&&first>=sp&&(first-sp)%2==0)sc=(first-sp)/2;
 if(op!=pt&&sxzxm_u16(c,op,&first)&&first>=op&&(first-op)%2==0)oc=(first-op)/2;
 if(sc>32)sc=0;if(oc>16)oc=0;
 for(unsigned k=0;k<2;k++){unsigned tab=k?op:sp,count=k?oc:sc;if(!sxzxm_opt(c,k?&sxzxm_zx_ornament_offset:&sxzxm_zx_sample_offset,tab,count))return false;for(unsigned i=0;i<count;i++){uint16_t p;if(!sxzxm_u16(c,tab+2U*i,&p))break;if(p>=8&&!sxzxm_object(c,p,k?9:8))return false;}}
 return true;
}
bool sx_dexus_prosoundmaker_build(sx_context*c)
{
 return sxzxm_psm(c);
}
