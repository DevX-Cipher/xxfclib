/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC KANEDA MVSTRACKERSUITE MUS data structures, moved out of the pcmusic schema family. */
#include "../../../xx_format_schema_pcmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxpcm_pc_order_count_fields[]={
 SX_FIELD("order_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxpcm_pc_order_count={UINT32_C(0x60940007),"pc_order_count",sxpcm_pc_order_count_fields,SX_COUNT(sxpcm_pc_order_count_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_mvs_header_fields[]={
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
};
const sx_layout sxpcm_mvs_header={UINT32_C(0x60940042),"mvs_header",sxpcm_mvs_header_fields,SX_COUNT(sxpcm_mvs_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_mvs_instrument_fields[]={
 SX_FIELD("operator_detune_multiple","uint8[4]",0,4,SX_FLAGS),
 SX_FIELD("operator_total_level","uint8[4]",4,4,SX_FLAGS),
 SX_FIELD("operator_keyscale_attack","uint8[4]",8,4,SX_FLAGS),
 SX_FIELD("operator_am_decay","uint8[4]",12,4,SX_FLAGS),
 SX_FIELD("operator_sustain_rate","uint8[4]",16,4,SX_FLAGS),
 SX_FIELD("operator_sustain_release","uint8[4]",20,4,SX_FLAGS),
 SX_FIELD("feedback_algorithm","uint8",24,1,SX_FLAGS),
};
const sx_layout sxpcm_mvs_instrument={UINT32_C(0x60940043),"mvs_instrument",sxpcm_mvs_instrument_fields,SX_COUNT(sxpcm_mvs_instrument_fields),SX_LE};
#define SXPCM_ADD(c,n,p) sxpcm_put(c,&sxpcm_##n,p,1)
static bool sxpcm_mvs_name(sx_context*c,uint64_t*p){uint8_t b;uint64_t start=*p;for(unsigned i=0;i<256;i++){if(!sxpcm_u8(c,(*p)++,&b))return false;if(!b)return sxpcm_text(c,start,*p-start);}return false;}
static bool sxpcm_mvs(sx_context*c){
 if(!sxpcm_eq(c,0,"MVSM1",5)||!SXPCM_ADD(c,mvs_header,0))return false;uint64_t p=5;
 for(unsigned i=0;i<31;i++){if(!sxpcm_mvs_name(c,&p)||!SXPCM_ADD(c,mvs_instrument,p))return true;p+=25;}
 uint8_t n;if(!sxpcm_u8(c,p,&n)||!SXPCM_ADD(c,pc_order_count,p++))return true;if(n>64||!sxpcm_put(c,&sxpcm_pc_pattern_index,p,n))return true;p+=n;
 if(!sxpcm_u8(c,p,&n)||!SXPCM_ADD(c,pc_pattern_count,p++))return true;if(n>64)return true;
 for(unsigned i=0;i<n;i++){if(!sxpcm_mvs_name(c,&p)||!sxpcm_put(c,&sxpcm_mvs_event,p,256))return true;p+=1024;}
 return true;
}
bool sx_kaneda_mvstrackersuite_mus_build(sx_context*c)
{
 return sxpcm_mvs(c);
}
