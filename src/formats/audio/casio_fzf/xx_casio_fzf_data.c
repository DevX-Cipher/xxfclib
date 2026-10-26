/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * casio fzf data structures, moved out of the samplebanks schema family. */
#include "../../xx_format_schema_samplebanks.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsb_casio_fz_bank_fields[] = {
    SX_FIELD("area_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("high_key","uint8[64]",2,64,SX_NONE),
    SX_FIELD("low_key","uint8[64]",66,64,SX_NONE),
    SX_FIELD("high_velocity","uint8[64]",130,64,SX_NONE),
    SX_FIELD("low_velocity","uint8[64]",194,64,SX_NONE),
    SX_FIELD("original_key","uint8[64]",258,64,SX_NONE),
    SX_FIELD("midi_channel","uint8[64]",322,64,SX_NONE),
    SX_FIELD("generator_mask","uint8[64]",386,64,SX_FLAGS),
    SX_FIELD("volume","uint8[64]",450,64,SX_NONE),
    SX_FIELD("voice_number","uint16[64]",514,128,SX_NONE),
    SX_FIELD("name","char[12]",642,12,SX_NONE),
    SX_FIELD("name_padding","byte[2]",654,2,SX_RESERVED),
};
const sx_layout sxsb_casio_fz_bank = {0x603a0010U,"casio_fz_bank",sxsb_casio_fz_bank_fields,SX_COUNT(sxsb_casio_fz_bank_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_casio_fz_voice_fields[] = {
    SX_FIELD("wave_start","uint32",0,4,SX_ADDRESS),
    SX_FIELD("wave_end","uint32",4,4,SX_ADDRESS),
    SX_FIELD("generator_start","uint32",8,4,SX_ADDRESS),
    SX_FIELD("generator_end","uint32",12,4,SX_ADDRESS),
    SX_FIELD("sounding_mode","uint16",16,2,SX_FLAGS),
    SX_FIELD("sustain_loop","uint8",18,1,SX_NONE),
    SX_FIELD("end_loop","uint8",19,1,SX_NONE),
    SX_FIELD("loop_start_encoded","uint32[8]",20,32,SX_FLAGS),
    SX_FIELD("loop_end_encoded","uint32[8]",52,32,SX_FLAGS),
    SX_FIELD("loop_crossfade_encoded","uint16[8]",84,16,SX_NONE),
    SX_FIELD("loop_time_encoded","uint16[8]",100,16,SX_NONE),
    SX_FIELD("pitch_detune","int16",116,2,SX_NONE),
    SX_FIELD("filter_offset","uint8",118,1,SX_NONE),
    SX_FIELD("filter_q_offset","uint8",119,1,SX_NONE),
    SX_FIELD("amplitude_sustain_point","uint8",120,1,SX_NONE),
    SX_FIELD("amplitude_end_point","uint8",121,1,SX_NONE),
    SX_FIELD("amplitude_rate","uint8[8]",122,8,SX_FLAGS),
    SX_FIELD("amplitude_stop","uint8[8]",130,8,SX_NONE),
    SX_FIELD("filter_sustain_point","uint8",138,1,SX_NONE),
    SX_FIELD("filter_end_point","uint8",139,1,SX_NONE),
    SX_FIELD("filter_rate","uint8[8]",140,8,SX_FLAGS),
    SX_FIELD("filter_stop","uint8[8]",148,8,SX_NONE),
    SX_FIELD("lfo_delay_encoded","uint16",156,2,SX_NONE),
    SX_FIELD("lfo_waveform","uint8",158,1,SX_FLAGS),
    SX_FIELD("lfo_attack","uint8",159,1,SX_NONE),
    SX_FIELD("lfo_rate_encoded","uint8",160,1,SX_NONE),
    SX_FIELD("lfo_pitch_depth","uint8",161,1,SX_NONE),
    SX_FIELD("lfo_amplitude_depth","uint8",162,1,SX_NONE),
    SX_FIELD("lfo_filter_depth","uint8",163,1,SX_NONE),
    SX_FIELD("lfo_q_depth","uint8",164,1,SX_NONE),
    SX_FIELD("velocity_q_follow","int8",165,1,SX_NONE),
    SX_FIELD("amplitude_keyboard_follow","int8",166,1,SX_NONE),
    SX_FIELD("amplitude_note_rate_scale","int8",167,1,SX_NONE),
    SX_FIELD("filter_keyboard_follow","int8",168,1,SX_NONE),
    SX_FIELD("filter_note_rate_scale","int8",169,1,SX_NONE),
    SX_FIELD("velocity_amplitude_follow","int8",170,1,SX_NONE),
    SX_FIELD("velocity_amplitude_rate_scale","int8",171,1,SX_NONE),
    SX_FIELD("velocity_filter_follow","int8",172,1,SX_NONE),
    SX_FIELD("velocity_filter_rate_scale","int8",173,1,SX_NONE),
    SX_FIELD("high_key","uint8",174,1,SX_NONE),
    SX_FIELD("low_key","uint8",175,1,SX_NONE),
    SX_FIELD("original_key","uint8",176,1,SX_NONE),
    SX_FIELD("sample_rate_code","uint8",177,1,SX_ID),
    SX_FIELD("name","char[12]",178,12,SX_NONE),
    SX_FIELD("name_padding","byte[2]",190,2,SX_RESERVED),
};
const sx_layout sxsb_casio_fz_voice = {0x603a0011U,"casio_fz_voice",sxsb_casio_fz_voice_fields,SX_COUNT(sxsb_casio_fz_voice_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_casio_fz_effect_fields[] = {
    SX_FIELD("pitch_bend_depth","uint8",0,1,SX_NONE),
    SX_FIELD("unused_master_volume","uint8",1,1,SX_NONE),
    SX_FIELD("unused_sustain_switch","uint8",2,1,SX_NONE),
    SX_FIELD("modulation_lfo_pitch","uint8",3,1,SX_NONE),
    SX_FIELD("modulation_lfo_amplitude","uint8",4,1,SX_NONE),
    SX_FIELD("modulation_lfo_filter","uint8",5,1,SX_NONE),
    SX_FIELD("modulation_lfo_q","uint8",6,1,SX_NONE),
    SX_FIELD("modulation_filter","uint8",7,1,SX_NONE),
    SX_FIELD("modulation_amplitude","uint8",8,1,SX_NONE),
    SX_FIELD("modulation_q","uint8",9,1,SX_NONE),
    SX_FIELD("foot_lfo_pitch","uint8",10,1,SX_NONE),
    SX_FIELD("foot_lfo_amplitude","uint8",11,1,SX_NONE),
    SX_FIELD("foot_lfo_filter","uint8",12,1,SX_NONE),
    SX_FIELD("foot_lfo_q","uint8",13,1,SX_NONE),
    SX_FIELD("foot_amplitude","uint8",14,1,SX_NONE),
    SX_FIELD("foot_filter","uint8",15,1,SX_NONE),
    SX_FIELD("foot_q","uint8",16,1,SX_NONE),
    SX_FIELD("aftertouch_lfo_pitch","uint8",17,1,SX_NONE),
    SX_FIELD("aftertouch_lfo_amplitude","uint8",18,1,SX_NONE),
    SX_FIELD("aftertouch_lfo_filter","uint8",19,1,SX_NONE),
    SX_FIELD("aftertouch_lfo_q","uint8",20,1,SX_NONE),
    SX_FIELD("aftertouch_amplitude","uint8",21,1,SX_NONE),
    SX_FIELD("aftertouch_filter","uint8",22,1,SX_NONE),
    SX_FIELD("aftertouch_q","uint8",23,1,SX_NONE),
};
const sx_layout sxsb_casio_fz_effect = {0x603a0012U,"casio_fz_effect",sxsb_casio_fz_effect_fields,SX_COUNT(sxsb_casio_fz_effect_fields),SX_LE};
static const xx_data_struct_field_desc sxsb_casio_fzf_dump_workspace_fields[] = {
    SX_FIELD("opaque_00","byte[5]",0,5,SX_NONE),
    SX_FIELD("dump_type","uint8",5,1,SX_ID),
    SX_FIELD("opaque_06","uint8",6,1,SX_NONE),
    SX_FIELD("bank_count","uint8",7,1,SX_COUNT_PROP),
    SX_FIELD("voice_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("content_blocks","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("waveform_blocks","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("opaque_0e","byte[10]",14,10,SX_NONE),
};
const sx_layout sxsb_casio_fzf_dump_workspace = {0x603a0013U,"casio_fzf_dump_workspace",sxsb_casio_fzf_dump_workspace_fields,SX_COUNT(sxsb_casio_fzf_dump_workspace_fields),SX_LE};
#define SXSB_ADD(c,l,p) sxsb_put(c,&sxsb_##l,p,1)
static bool sxsb_casio(sx_context*c){
 uint8_t h[24],b[656],v[192];if(c->size<3072||(c->size&1023)||!sxsb_read(c,1000,h,24))return false;
 uint32_t banks=1,voices=0,wave=sxsb16(h+12);bool declared=h[7]||h[8]||wave,referenced[64]={false};
 if(declared){banks=h[7];voices=h[8];if((h[5]!=0&&h[5]!=2)||h[6]||!banks||banks>8||!voices||voices>64||!wave||(h[5]==2&&banks!=1)||(uint64_t)(banks+(voices+3)/4+wave)*1024!=(uint64_t)c->size)return false;}
 for(uint32_t k=0;k<banks;k++){
  if(!sxsb_read(c,(uint64_t)k*1024,b,656))return false;uint32_t areas=sxsb16(b);if(!areas||areas>64)return false;
  for(uint32_t i=0;i<areas;i++){uint32_t id=sxsb16(b+514+2*i);if(id>=(declared?voices:64))return false;referenced[id]=true;if(!declared&&id+1>voices)voices=id+1;}
 }
 uint64_t audio=(uint64_t)(banks+(voices+3)/4)*1024;if(audio>=(uint64_t)c->size)return false;
 for(uint32_t k=0;k<banks;k++)if(!SXSB_ADD(c,casio_fz_bank,(uint64_t)k*1024))return false;
 if(declared&&(!SXSB_ADD(c,casio_fzf_dump_workspace,1000)||(!h[5]&&!SXSB_ADD(c,casio_fz_effect,960))))return false;
 for(uint32_t i=0;i<voices;i++)if(declared||referenced[i]){
  uint64_t p=(uint64_t)banks*1024+i*256;if(!sxsb_read(c,p,v,192))return false;
  uint32_t a=sxsb32(v),z=sxsb32(v+4),g=sxsb32(v+8),e=sxsb32(v+12);
  if(a>g||g>e||e>z||z>((uint64_t)c->size-audio)/2)continue;
  if(!SXSB_ADD(c,casio_fz_voice,p))return false;
 }
 return true;
}
#undef SXSB_ADD
bool sx_casio_fzf_build(sx_context*c)
{
 return sxsb_casio(c);
}
