/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC TAYLOR FMTRACKER data structures, moved out of the pcmusic schema family. */
#include "../../../xx_format_schema_pcmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxpcm_taylor_header_fields[]={
 SX_FIELD("signature","char[9]",0,9,SX_SIGNATURE),
 SX_FIELD("major_version","uint8",9,1,SX_ID),
 SX_FIELD("minor_version","uint8",10,1,SX_ID),
 SX_FIELD("tracker","char[20]",11,20,SX_NONE),
 SX_FIELD("title","char[32]",31,32,SX_NONE),
};
const sx_layout sxpcm_taylor_header={UINT32_C(0x60940012),"taylor_header",sxpcm_taylor_header_fields,SX_COUNT(sxpcm_taylor_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_taylor_instrument_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_NONE),
 SX_FIELD("modulator_characteristics","uint8",8,1,SX_FLAGS),
 SX_FIELD("carrier_characteristics","uint8",9,1,SX_FLAGS),
 SX_FIELD("modulator_level","uint8",10,1,SX_FLAGS),
 SX_FIELD("carrier_level","uint8",11,1,SX_FLAGS),
 SX_FIELD("modulator_attack_decay","uint8",12,1,SX_FLAGS),
 SX_FIELD("carrier_attack_decay","uint8",13,1,SX_FLAGS),
 SX_FIELD("modulator_sustain_release","uint8",14,1,SX_FLAGS),
 SX_FIELD("carrier_sustain_release","uint8",15,1,SX_FLAGS),
 SX_FIELD("modulator_waveform","uint8",16,1,SX_ID),
 SX_FIELD("carrier_waveform","uint8",17,1,SX_ID),
 SX_FIELD("feedback_connection","uint8",18,1,SX_FLAGS),
};
const sx_layout sxpcm_taylor_instrument={UINT32_C(0x60940013),"taylor_instrument",sxpcm_taylor_instrument_fields,SX_COUNT(sxpcm_taylor_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_taylor_delay_fields[]={
 SX_FIELD("delay","uint8",0,1,SX_NONE),
};
const sx_layout sxpcm_taylor_delay={UINT32_C(0x60940015),"taylor_delay",sxpcm_taylor_delay_fields,SX_COUNT(sxpcm_taylor_delay_fields),SX_LE};
#define SXPCM_ADD(c,n,p) sxpcm_put(c,&sxpcm_##n,p,1)
static bool sxpcm_taylor(sx_context*c){
 uint8_t n[3];if(!sxpcm_eq(c,0,"FMTracker",9)||!SXPCM_ADD(c,taylor_header,0))return false;
 if(!sxpcm_put(c,&sxpcm_taylor_instrument,63,8))return true;
 if(!sxpcm_read(c,215,n,3)||!SXPCM_ADD(c,taylor_counts,215))return true;uint64_t p=218,count=(unsigned)n[1]+1;
 if(!sxpcm_put(c,&sxpcm_pc_pattern_index,p,count))return true;p+=count;
 if(!sxpcm_put(c,&sxpcm_taylor_delay,p,count))return true;p+=count;
 return sxpcm_opt(c,&sxpcm_pc_pattern_index,p,(unsigned)n[2]+1);
}
bool sx_taylor_fmtracker_build(sx_context*c)
{
 return sxpcm_taylor(c);
}
