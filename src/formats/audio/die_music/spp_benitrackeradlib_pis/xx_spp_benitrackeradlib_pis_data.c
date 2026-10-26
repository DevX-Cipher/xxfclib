/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC SPP BENITRACKERADLIB PIS data structures, moved out of the pcmusic schema family. */
#include "../../../xx_format_schema_pcmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxpcm_beni_header_fields[]={
 SX_FIELD("order_count","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("pattern_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("instrument_count","uint8",2,1,SX_COUNT_PROP),
};
const sx_layout sxpcm_beni_header={UINT32_C(0x6094000C),"beni_header",sxpcm_beni_header_fields,SX_COUNT(sxpcm_beni_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beni_pattern_map_fields[]={
 SX_FIELD("pattern_id","uint8",0,1,SX_ID),
};
const sx_layout sxpcm_beni_pattern_map={UINT32_C(0x6094000D),"beni_pattern_map",sxpcm_beni_pattern_map_fields,SX_COUNT(sxpcm_beni_pattern_map_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beni_instrument_map_fields[]={
 SX_FIELD("instrument_id","uint8",0,1,SX_ID),
};
const sx_layout sxpcm_beni_instrument_map={UINT32_C(0x6094000E),"beni_instrument_map",sxpcm_beni_instrument_map_fields,SX_COUNT(sxpcm_beni_instrument_map_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beni_event_fields[]={
 SX_FIELD("packed_note_instrument_effect","uint24be",0,3,SX_FLAGS),
};
const sx_layout sxpcm_beni_event={UINT32_C(0x6094000F),"beni_event",sxpcm_beni_event_fields,SX_COUNT(sxpcm_beni_event_fields),SX_BE};
static const xx_data_struct_field_desc sxpcm_beni_instrument_fields[]={
 SX_FIELD("modulator_characteristics","uint8",0,1,SX_FLAGS),
 SX_FIELD("carrier_characteristics","uint8",1,1,SX_FLAGS),
 SX_FIELD("modulator_level","uint8",2,1,SX_FLAGS),
 SX_FIELD("carrier_level","uint8",3,1,SX_FLAGS),
 SX_FIELD("modulator_attack_decay","uint8",4,1,SX_FLAGS),
 SX_FIELD("carrier_attack_decay","uint8",5,1,SX_FLAGS),
 SX_FIELD("modulator_sustain_release","uint8",6,1,SX_FLAGS),
 SX_FIELD("carrier_sustain_release","uint8",7,1,SX_FLAGS),
 SX_FIELD("modulator_waveform","uint8",8,1,SX_ID),
 SX_FIELD("carrier_waveform","uint8",9,1,SX_ID),
 SX_FIELD("feedback_connection","uint8",10,1,SX_FLAGS),
};
const sx_layout sxpcm_beni_instrument={UINT32_C(0x60940010),"beni_instrument",sxpcm_beni_instrument_fields,SX_COUNT(sxpcm_beni_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beni_version_fields[]={
 SX_FIELD("marker","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxpcm_beni_version={UINT32_C(0x60940011),"beni_version",sxpcm_beni_version_fields,SX_COUNT(sxpcm_beni_version_fields),SX_LE};
#define SXPCM_ADD(c,n,p) sxpcm_put(c,&sxpcm_##n,p,1)
static bool sxpcm_beni(sx_context*c){
 uint8_t h[3];if(!sxpcm_read(c,0,h,3)||!h[1]||h[1]>204||h[2]>31||!SXPCM_ADD(c,beni_header,0))return false;
 uint64_t p=3;if(!sxpcm_put(c,&sxpcm_beni_pattern_map,p,h[1]))return true;p+=h[1];if(!sxpcm_put(c,&sxpcm_beni_instrument_map,p,h[2]))return true;p+=h[2];
 if(!sxpcm_put(c,&sxpcm_pc_pattern_index,p,(uint64_t)h[0]*9))return true;p+=(uint64_t)h[0]*9;
 if(!sxpcm_put(c,&sxpcm_beni_event,p,(uint64_t)h[1]*64))return true;p+=(uint64_t)h[1]*192;
 if(!sxpcm_put(c,&sxpcm_beni_instrument,p,h[2]))return true;p+=(uint64_t)h[2]*11;
 if(sxpcm_eq(c,p,"B.J.",4))return SXPCM_ADD(c,beni_version,p);return true;
}
bool sx_spp_benitrackeradlib_pis_build(sx_context*c)
{
 return sxpcm_beni(c);
}
