/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC XORJS FMTRACKER data structures, moved out of the pcmusic schema family. */
#include "../../../xx_format_schema_pcmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxpcm_xorjs_header_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("speed","uint8",8,1,SX_NONE),
 SX_FIELD("bpm","uint8",9,1,SX_NONE),
};
const sx_layout sxpcm_xorjs_header={UINT32_C(0x60940016),"xorjs_header",sxpcm_xorjs_header_fields,SX_COUNT(sxpcm_xorjs_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_xorjs_instrument_fields[]={
 SX_FIELD("modulator_characteristics","uint8",0,1,SX_FLAGS),
 SX_FIELD("modulator_level","uint8",1,1,SX_FLAGS),
 SX_FIELD("modulator_attack_decay","uint8",2,1,SX_FLAGS),
 SX_FIELD("modulator_sustain_release","uint8",3,1,SX_FLAGS),
 SX_FIELD("modulator_waveform","uint8",4,1,SX_ID),
 SX_FIELD("modulator_feedback_connection","uint8",5,1,SX_FLAGS),
 SX_FIELD("carrier_characteristics","uint8",6,1,SX_FLAGS),
 SX_FIELD("carrier_level","uint8",7,1,SX_FLAGS),
 SX_FIELD("carrier_attack_decay","uint8",8,1,SX_FLAGS),
 SX_FIELD("carrier_sustain_release","uint8",9,1,SX_FLAGS),
 SX_FIELD("carrier_waveform","uint8",10,1,SX_ID),
 SX_FIELD("carrier_feedback_connection","uint8",11,1,SX_FLAGS),
 SX_FIELD("name","char[24]",12,24,SX_NONE),
};
const sx_layout sxpcm_xorjs_instrument={UINT32_C(0x60940017),"xorjs_instrument",sxpcm_xorjs_instrument_fields,SX_COUNT(sxpcm_xorjs_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_xorjs_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("volume","uint8",2,1,SX_NONE),
};
const sx_layout sxpcm_xorjs_event={UINT32_C(0x60940018),"xorjs_event",sxpcm_xorjs_event_fields,SX_COUNT(sxpcm_xorjs_event_fields),SX_LE};
#define SXPCM_ADD(c,n,p) sxpcm_put(c,&sxpcm_##n,p,1)
static bool sxpcm_xorjs(sx_context*c){
 if(!sxpcm_eq(c,0,"JSR_FMT~",8)||!SXPCM_ADD(c,xorjs_header,0))return false;
 if(!sxpcm_put(c,&sxpcm_xorjs_instrument,10,256)||!sxpcm_put(c,&sxpcm_pc_pattern_index,9226,256))return true;
 uint8_t n;if(!sxpcm_u8(c,9482,&n)||!SXPCM_ADD(c,pc_pattern_count,9482))return true;uint64_t p=9483;
 for(unsigned i=0;i<n;i++){if(!SXPCM_ADD(c,pc_pattern_index,p++))return true;if(!sxpcm_put(c,&sxpcm_xorjs_event,p,64*18))return true;p+=64*18*3;}
 return true;
}
bool sx_xorjs_fmtracker_build(sx_context*c)
{
 return sxpcm_xorjs(c);
}
