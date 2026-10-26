/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC DEFY ADLIBTRACKER DTM data structures, moved out of the pcmusic schema family. */
#include "../../../xx_format_schema_pcmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxpcm_pc_u8_length_fields[]={
 SX_FIELD("byte_length","uint8",0,1,SX_SIZE),
};
const sx_layout sxpcm_pc_u8_length={UINT32_C(0x60940002),"pc_u8_length",sxpcm_pc_u8_length_fields,SX_COUNT(sxpcm_pc_u8_length_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_pc_packed_pattern_fields[]={
 SX_FIELD("packed_byte_length","uint16",0,2,SX_SIZE),
};
const sx_layout sxpcm_pc_packed_pattern={UINT32_C(0x60940009),"pc_packed_pattern",sxpcm_pc_packed_pattern_fields,SX_COUNT(sxpcm_pc_packed_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_defy_instrument_fields[]={
 SX_FIELD("carrier_characteristics","uint8",0,1,SX_FLAGS),
 SX_FIELD("modulator_characteristics","uint8",1,1,SX_FLAGS),
 SX_FIELD("carrier_level","uint8",2,1,SX_FLAGS),
 SX_FIELD("modulator_level","uint8",3,1,SX_FLAGS),
 SX_FIELD("carrier_attack_decay","uint8",4,1,SX_FLAGS),
 SX_FIELD("modulator_attack_decay","uint8",5,1,SX_FLAGS),
 SX_FIELD("carrier_sustain_release","uint8",6,1,SX_FLAGS),
 SX_FIELD("modulator_sustain_release","uint8",7,1,SX_FLAGS),
 SX_FIELD("feedback_connection","uint8",8,1,SX_FLAGS),
 SX_FIELD("carrier_waveform","uint8",9,1,SX_ID),
 SX_FIELD("modulator_waveform","uint8",10,1,SX_ID),
 SX_FIELD("extra_byte","uint8",11,1,SX_NONE),
};
const sx_layout sxpcm_defy_instrument={UINT32_C(0x6094000B),"defy_instrument",sxpcm_defy_instrument_fields,SX_COUNT(sxpcm_defy_instrument_fields),SX_LE};
#define SXPCM_ADD(c,n,p) sxpcm_put(c,&sxpcm_##n,p,1)
/* Primary writers/loaders: DeFy/AdPlug dtm.cpp; Taylor FMTRACK.BAS;
 * XorJS FM.ASM; Beni BT18 loadmod and maintained AdPlug pis.cpp. */
static bool sxpcm_defy(sx_context*c){
 uint8_t h[55];if(!sxpcm_read(c,0,h,sizeof(h))||xx_rt_memcmp(h,"DeFy DTM ",9)||h[12]!=0x10)return false;
 if(!SXPCM_ADD(c,defy_header,0))return false;uint64_t p=55;uint8_t z;
 for(unsigned i=0;i<16;i++){if(!sxpcm_u8(c,p,&z)||z>80||!SXPCM_ADD(c,pc_u8_length,p++))return true;if(!sxpcm_text(c,p,z))return true;p+=z;}
 unsigned count=(unsigned)h[54]+1;if(count>128)return true;
 for(unsigned i=0;i<count;i++){if(!sxpcm_u8(c,p,&z)||z>=13||!SXPCM_ADD(c,pc_u8_length,p++))return true;if(!sxpcm_text(c,p,z))return true;p+=z;if(!SXPCM_ADD(c,defy_instrument,p))return true;p+=12;}
 if(!sxpcm_put(c,&sxpcm_pc_pattern_index,p,100))return true;p+=100;
 for(unsigned i=0;i<h[53];i++){uint16_t n;if(!sxpcm_u16(c,p,&n)||!SXPCM_ADD(c,pc_packed_pattern,p))return true;p+=2;if(!sxpcm_span(c,p,n))return true;p+=n;}
 return true;
}
bool sx_defy_adlibtracker_dtm_build(sx_context*c)
{
 return sxpcm_defy(c);
}
