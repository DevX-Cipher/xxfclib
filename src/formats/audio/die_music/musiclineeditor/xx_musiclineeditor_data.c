/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * musiclineeditor data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_chunk_be_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxnextm_chunk_be={UINT32_C(0x608B000A),"chunk_be",sxnextm_chunk_be_fields,SX_COUNT(sxnextm_chunk_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_mle_magic_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
};
const sx_layout sxnextm_mle_magic={UINT32_C(0x608B0055),"mle_magic",sxnextm_mle_magic_fields,SX_COUNT(sxnextm_mle_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_mle_tune_fields[]={
 SX_FIELD("title","char[32]",0,32,SX_NONE),
 SX_FIELD("tempo","uint16",32,2,SX_NONE),
 SX_FIELD("speed","uint8",34,1,SX_NONE),
 SX_FIELD("groove","uint8",35,1,SX_NONE),
 SX_FIELD("volume","uint16",36,2,SX_NONE),
 SX_FIELD("mixer_mode","uint8",38,1,SX_FLAGS),
 SX_FIELD("channels","uint8",39,1,SX_COUNT_PROP),
};
const sx_layout sxnextm_mle_tune={UINT32_C(0x608B0056),"mle_tune",sxnextm_mle_tune_fields,SX_COUNT(sxnextm_mle_tune_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_mle_sequence_fields[]={
 SX_FIELD("part_and_control","uint16",0,2,SX_FLAGS),
};
const sx_layout sxnextm_mle_sequence={UINT32_C(0x608B0057),"mle_sequence",sxnextm_mle_sequence_fields,SX_COUNT(sxnextm_mle_sequence_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_mle_index_fields[]={
 SX_FIELD("index","uint16",0,2,SX_ID),
};
const sx_layout sxnextm_mle_index={UINT32_C(0x608B0058),"mle_index",sxnextm_mle_index_fields,SX_COUNT(sxnextm_mle_index_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_mle_part_note_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
};
const sx_layout sxnextm_mle_part_note={UINT32_C(0x608B005A),"mle_part_note",sxnextm_mle_part_note_fields,SX_COUNT(sxnextm_mle_part_note_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_mle_effect_fields[]={
 SX_FIELD("effect","uint8",0,1,SX_ID),
 SX_FIELD("argument","uint8",1,1,SX_NONE),
};
const sx_layout sxnextm_mle_effect={UINT32_C(0x608B005B),"mle_effect",sxnextm_mle_effect_fields,SX_COUNT(sxnextm_mle_effect_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_mle_arpeggio_fields[]={
 SX_FIELD("note_transpose","int8",0,1,SX_NONE),
 SX_FIELD("sample_index","uint8",1,1,SX_ID),
 SX_FIELD("effect1","uint8",2,1,SX_ID),
 SX_FIELD("argument1","uint8",3,1,SX_NONE),
 SX_FIELD("effect2","uint8",4,1,SX_ID),
 SX_FIELD("argument2","uint8",5,1,SX_NONE),
};
const sx_layout sxnextm_mle_arpeggio={UINT32_C(0x608B005C),"mle_arpeggio",sxnextm_mle_arpeggio_fields,SX_COUNT(sxnextm_mle_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_mle_instrument_fields[]={
 SX_FIELD("title","char[32]",0,32,SX_NONE),
 SX_FIELD("sample_number","uint8",32,1,SX_ID),
 SX_FIELD("sample_type","uint8",33,1,SX_ID),
 SX_FIELD("unknown0","bytes",34,4,SX_NONE),
 SX_FIELD("sample_length","uint16",38,2,SX_NONE),
 SX_FIELD("unknown1","bytes",40,4,SX_NONE),
 SX_FIELD("sample_repeat_length","uint16",44,2,SX_NONE),
 SX_FIELD("fine_tune","int16",46,2,SX_NONE),
 SX_FIELD("semi_tone","int16",48,2,SX_NONE),
 SX_FIELD("sample_start","uint16",50,2,SX_NONE),
 SX_FIELD("sample_end","uint16",52,2,SX_NONE),
 SX_FIELD("sample_repeat_start","uint16",54,2,SX_NONE),
 SX_FIELD("sample_repeat_len","uint16",56,2,SX_NONE),
 SX_FIELD("volume","uint16",58,2,SX_NONE),
 SX_FIELD("transposable","uint8",60,1,SX_FLAGS),
 SX_FIELD("slide_speed","uint8",61,1,SX_NONE),
 SX_FIELD("effect1","uint8",62,1,SX_ID),
 SX_FIELD("effect2","uint8",63,1,SX_ID),
 SX_FIELD("envelope_attack_length","uint16",64,2,SX_NONE),
 SX_FIELD("envelope_decay_length","uint16",66,2,SX_NONE),
 SX_FIELD("envelope_sustain_length","uint16",68,2,SX_NONE),
 SX_FIELD("envelope_release_length","uint16",70,2,SX_NONE),
 SX_FIELD("envelope_attack_speed","uint16",72,2,SX_NONE),
 SX_FIELD("envelope_decay_speed","uint16",74,2,SX_NONE),
 SX_FIELD("envelope_sustain_speed","uint16",76,2,SX_NONE),
 SX_FIELD("envelope_release_speed","uint16",78,2,SX_NONE),
 SX_FIELD("envelope_attack_volume","uint16",80,2,SX_NONE),
 SX_FIELD("envelope_decay_volume","uint16",82,2,SX_NONE),
 SX_FIELD("envelope_sustain_volume","uint16",84,2,SX_NONE),
 SX_FIELD("envelope_release_volume","uint16",86,2,SX_NONE),
 SX_FIELD("vibrato_direction","uint8",88,1,SX_FLAGS),
 SX_FIELD("vibrato_wave_type","uint8",89,1,SX_ID),
 SX_FIELD("vibrato_speed","uint16",90,2,SX_NONE),
 SX_FIELD("vibrato_delay","uint16",92,2,SX_NONE),
 SX_FIELD("vibrato_attack_speed","uint16",94,2,SX_NONE),
 SX_FIELD("vibrato_attack","uint16",96,2,SX_NONE),
 SX_FIELD("vibrato_depth","uint16",98,2,SX_NONE),
 SX_FIELD("tremolo_direction","uint8",100,1,SX_FLAGS),
 SX_FIELD("tremolo_wave_type","uint8",101,1,SX_ID),
 SX_FIELD("tremolo_speed","uint16",102,2,SX_NONE),
 SX_FIELD("tremolo_delay","uint16",104,2,SX_NONE),
 SX_FIELD("tremolo_attack_speed","uint16",106,2,SX_NONE),
 SX_FIELD("tremolo_attack","uint16",108,2,SX_NONE),
 SX_FIELD("tremolo_depth","uint16",110,2,SX_NONE),
 SX_FIELD("arpeggio_table","uint16",112,2,SX_ID),
 SX_FIELD("arpeggio_speed","uint8",114,1,SX_NONE),
 SX_FIELD("arpeggio_groove","uint8",115,1,SX_NONE),
 SX_FIELD("env_tra_pha_fil_bits","uint8",116,1,SX_FLAGS),
 SX_FIELD("transform_wave0","uint8",117,1,SX_ID),
 SX_FIELD("transform_wave1","uint8",118,1,SX_ID),
 SX_FIELD("transform_wave2","uint8",119,1,SX_ID),
 SX_FIELD("transform_wave3","uint8",120,1,SX_ID),
 SX_FIELD("transform_wave4","uint8",121,1,SX_ID),
 SX_FIELD("transform_start","uint16",122,2,SX_NONE),
 SX_FIELD("transform_repeat","uint16",124,2,SX_NONE),
 SX_FIELD("transform_repeat_end","uint16",126,2,SX_NONE),
 SX_FIELD("transform_speed","uint16",128,2,SX_NONE),
 SX_FIELD("transform_turns","uint16",130,2,SX_NONE),
 SX_FIELD("transform_delay","uint16",132,2,SX_NONE),
 SX_FIELD("phase_start","uint16",134,2,SX_NONE),
 SX_FIELD("phase_repeat","uint16",136,2,SX_NONE),
 SX_FIELD("phase_repeat_end","uint16",138,2,SX_NONE),
 SX_FIELD("phase_speed","uint16",140,2,SX_NONE),
 SX_FIELD("phase_turns","uint16",142,2,SX_NONE),
 SX_FIELD("phase_delay","uint16",144,2,SX_NONE),
 SX_FIELD("phase_type","uint16",146,2,SX_ID),
 SX_FIELD("mix_res_loo_bits","uint8",148,1,SX_FLAGS),
 SX_FIELD("mix_wave_number","uint8",149,1,SX_ID),
 SX_FIELD("mix_start","uint16",150,2,SX_NONE),
 SX_FIELD("mix_repeat","uint16",152,2,SX_NONE),
 SX_FIELD("mix_repeat_end","uint16",154,2,SX_NONE),
 SX_FIELD("mix_speed","uint16",156,2,SX_NONE),
 SX_FIELD("mix_turns","uint16",158,2,SX_NONE),
 SX_FIELD("mix_delay","uint16",160,2,SX_NONE),
 SX_FIELD("resonance_start","uint16",162,2,SX_NONE),
 SX_FIELD("resonance_repeat","uint16",164,2,SX_NONE),
 SX_FIELD("resonance_repeat_end","uint16",166,2,SX_NONE),
 SX_FIELD("resonance_speed","uint16",168,2,SX_NONE),
 SX_FIELD("resonance_turns","uint16",170,2,SX_NONE),
 SX_FIELD("resonance_delay","uint16",172,2,SX_NONE),
 SX_FIELD("mix_res_fil_boost","uint8",174,1,SX_FLAGS),
 SX_FIELD("responance_amp","uint8",175,1,SX_NONE),
 SX_FIELD("filter_start","uint16",176,2,SX_NONE),
 SX_FIELD("filter_repeat","uint16",178,2,SX_NONE),
 SX_FIELD("filter_repeat_end","uint16",180,2,SX_NONE),
 SX_FIELD("filter_speed","uint16",182,2,SX_NONE),
 SX_FIELD("filter_turns","uint16",184,2,SX_NONE),
 SX_FIELD("filter_delay","uint16",186,2,SX_NONE),
 SX_FIELD("unknown2","bytes",188,1,SX_NONE),
 SX_FIELD("filter_type","uint8",189,1,SX_ID),
 SX_FIELD("loop_start","uint16",190,2,SX_NONE),
 SX_FIELD("loop_repeat","uint16",192,2,SX_NONE),
 SX_FIELD("loop_repeat_end","uint16",194,2,SX_NONE),
 SX_FIELD("loop_length","uint16",196,2,SX_NONE),
 SX_FIELD("loop_loop_step","uint16",198,2,SX_NONE),
 SX_FIELD("loop_wait","uint16",200,2,SX_NONE),
 SX_FIELD("loop_delay","uint16",202,2,SX_NONE),
 SX_FIELD("loop_turns","uint16",204,2,SX_NONE),
};
const sx_layout sxnextm_mle_instrument={UINT32_C(0x608B005E),"mle_instrument",sxnextm_mle_instrument_fields,SX_COUNT(sxnextm_mle_instrument_fields),SX_BE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
#define NX_TAKE(l,p,n,end) sxnextm_take(v,&sxnextm_##l,(p),(n),(end))
static bool sxnextm_mle(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,p=4,z;uint8_t id[4];
 if(!sxnextm_eq(v,0,"MLEDMODL",8,e)||!NX_ROW(mle_magic,0,e))return false;
 /* The live native accepts the explicit MODL length variant. Older loader
    support without that length is deliberately not advertised here. */
 while(p<e){if(!sxnextm_read(v,p,id,4,e)||!sxnextm_be(v,p+4,4,&z,e)||!(xx_rt_memcmp(id,"TUNE",4)?NX_ROW(chunk_be,p,e):NX_ROW(mle_tune_chunk,p,e)))return false;uint64_t q=p+8,end;if(!xx_rt_memcmp(id,"SMPL",4)){if(z>UINT64_MAX-6)return false;z+=6;}if(!xx_rt_memcmp(id,"TUNE",4)){uint64_t ch,part;if(!sxnextm_u(v,q+39,1,&ch,e)||!sxnextm_span(v,q,40+ch*4,e))return false;z=40+ch*4;for(uint64_t i=0;i<ch;i++){if(!sxnextm_be(v,q+40+i*4,4,&part,e)||part>e-q-z)return false;z+=part;}}if(!sxnextm_span(v,q,z,e))return false;end=q+z;
 if(!xx_rt_memcmp(id,"TUNE",4)){uint64_t n,start;if(!sxnextm_u(v,q+39,1,&n,end)||!NX_TAKE(mle_tune,&q,1,end))return false;start=q;if(!NX_TAKE(bytes32,&q,n,end))return false;for(uint64_t i=0;i<n;i++){uint64_t k;if(!sxnextm_be(v,start+i*4,4,&k,end)||k%2||!NX_TAKE(mle_sequence,&q,k/2,end))return false;}}
 else if(!xx_rt_memcmp(id,"PART",4)){if(!NX_TAKE(mle_index,&q,1,end))return false;unsigned rows=0;while(q<end){uint64_t flags;if(!sxnextm_u(v,q,1,&flags,end)||!NX_TAKE(mle_part_control,&q,1,end))return false;if(flags==255)break;if(rows++>=256)return false;if((flags&1)&&!NX_TAKE(mle_part_note,&q,1,end))return false;for(unsigned i=1;i<=5;i++)if((flags&(1U<<i))&&!NX_TAKE(mle_effect,&q,1,end))return false;}}
 else if(!xx_rt_memcmp(id,"ARPG",4)){if(z<2||(z-2)%6||!NX_TAKE(mle_index,&q,1,end)||!NX_TAKE(mle_arpeggio,&q,(z-2)/6,end))return false;}
 else if(!xx_rt_memcmp(id,"INST",4)){if(!NX_ROW(mle_instrument,q,end))return false;}
 else if(!xx_rt_memcmp(id,"SMPL",4)){if(!NX_ROW(mle_sample,q,end))return false;}
 else if(!xx_rt_memcmp(id,"INFO",4)){if(!sxnextm_text_emit(v,q,z,end))return false;}
 p=end;if(!xx_rt_memcmp(id,"PART",4)&&(p&1)){if(!sxnextm_skip(v,&p,1,e))return false;}
 }return true;}
bool sx_musiclineeditor_build(sxnextm_view*v)
{
 return sxnextm_mle(v);
}
#undef NX_ROW
#undef NX_TAKE
