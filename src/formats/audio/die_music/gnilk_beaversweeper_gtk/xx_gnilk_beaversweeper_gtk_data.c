/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC GNILK BEAVERSWEEPER GTK data structures, moved out of the pcmusic schema family. */
#include "../../../xx_format_schema_pcmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxpcm_beaver_synth_marker_fields[]={
 SX_FIELD("marker","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxpcm_beaver_synth_marker={UINT32_C(0x6094004A),"beaver_synth_marker",sxpcm_beaver_synth_marker_fields,SX_COUNT(sxpcm_beaver_synth_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_sample_length_fields[]={
 SX_FIELD("sample_count","uint24",0,3,SX_COUNT_PROP),
};
const sx_layout sxpcm_beaver_sample_length={UINT32_C(0x6094004C),"beaver_sample_length",sxpcm_beaver_sample_length_fields,SX_COUNT(sxpcm_beaver_sample_length_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_sample_loop_fields[]={
 SX_FIELD("loop_start_sample","uint24",0,3,SX_NONE),
 SX_FIELD("loop_end_sample","uint24",3,3,SX_NONE),
};
const sx_layout sxpcm_beaver_sample_loop={UINT32_C(0x6094004D),"beaver_sample_loop",sxpcm_beaver_sample_loop_fields,SX_COUNT(sxpcm_beaver_sample_loop_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_voice_count_fields[]={
 SX_FIELD("voice_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxpcm_beaver_voice_count={UINT32_C(0x6094004E),"beaver_voice_count",sxpcm_beaver_voice_count_fields,SX_COUNT(sxpcm_beaver_voice_count_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_polyphony_fields[]={
 SX_FIELD("polyphony","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxpcm_beaver_polyphony={UINT32_C(0x6094004F),"beaver_polyphony",sxpcm_beaver_polyphony_fields,SX_COUNT(sxpcm_beaver_polyphony_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_voice_range_fields[]={
 SX_FIELD("first_note","uint8",0,1,SX_NONE),
 SX_FIELD("last_note","uint8",1,1,SX_NONE),
};
const sx_layout sxpcm_beaver_voice_range={UINT32_C(0x60940050),"beaver_voice_range",sxpcm_beaver_voice_range_fields,SX_COUNT(sxpcm_beaver_voice_range_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_modulator_count_fields[]={
 SX_FIELD("modulator_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxpcm_beaver_modulator_count={UINT32_C(0x60940051),"beaver_modulator_count",sxpcm_beaver_modulator_count_fields,SX_COUNT(sxpcm_beaver_modulator_count_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_oscillator_count_fields[]={
 SX_FIELD("oscillator_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxpcm_beaver_oscillator_count={UINT32_C(0x60940052),"beaver_oscillator_count",sxpcm_beaver_oscillator_count_fields,SX_COUNT(sxpcm_beaver_oscillator_count_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_insert_count_fields[]={
 SX_FIELD("insert_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxpcm_beaver_insert_count={UINT32_C(0x60940053),"beaver_insert_count",sxpcm_beaver_insert_count_fields,SX_COUNT(sxpcm_beaver_insert_count_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_type_fields[]={
 SX_FIELD("component_type","uint8",0,1,SX_ID),
};
const sx_layout sxpcm_beaver_type={UINT32_C(0x60940054),"beaver_type",sxpcm_beaver_type_fields,SX_COUNT(sxpcm_beaver_type_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_envelope_fields[]={
 SX_FIELD("attack_ticks","uint8",0,1,SX_NONE),
 SX_FIELD("decay_ticks","uint8",1,1,SX_NONE),
 SX_FIELD("release_ticks","uint8",2,1,SX_NONE),
 SX_FIELD("sustain_level","float32",3,4,SX_NONE),
 SX_FIELD("velocity_sensitivity","float32",7,4,SX_NONE),
 SX_FIELD("use_sustain","uint8",11,1,SX_FLAGS),
};
const sx_layout sxpcm_beaver_envelope={UINT32_C(0x60940055),"beaver_envelope",sxpcm_beaver_envelope_fields,SX_COUNT(sxpcm_beaver_envelope_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_lfo_fields[]={
 SX_FIELD("waveform","uint8",0,1,SX_ID),
 SX_FIELD("invert","uint8",1,1,SX_FLAGS),
 SX_FIELD("offset","float32",2,4,SX_NONE),
 SX_FIELD("attack_ticks","uint8",6,1,SX_NONE),
 SX_FIELD("retrigger","uint8",7,1,SX_FLAGS),
 SX_FIELD("velocity_sensitivity","float32",8,4,SX_NONE),
 SX_FIELD("period_ticks","uint16",12,2,SX_NONE),
};
const sx_layout sxpcm_beaver_lfo={UINT32_C(0x60940056),"beaver_lfo",sxpcm_beaver_lfo_fields,SX_COUNT(sxpcm_beaver_lfo_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_controller_fields[]={
 SX_FIELD("smoothing_cutoff","float32",0,4,SX_NONE),
 SX_FIELD("controller_number","uint8",4,1,SX_ID),
};
const sx_layout sxpcm_beaver_controller={UINT32_C(0x60940057),"beaver_controller",sxpcm_beaver_controller_fields,SX_COUNT(sxpcm_beaver_controller_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_oscillator_fields[]={
 SX_FIELD("detune","float32",0,4,SX_NONE),
 SX_FIELD("dc_offset","float32",4,4,SX_NONE),
 SX_FIELD("multiplier","uint8",8,1,SX_NONE),
 SX_FIELD("transpose","int8",9,1,SX_NONE),
 SX_FIELD("portamento","float32",10,4,SX_NONE),
 SX_FIELD("waveform","uint8",14,1,SX_ID),
 SX_FIELD("sync","uint8",15,1,SX_FLAGS),
 SX_FIELD("mode","uint8",16,1,SX_ID),
 SX_FIELD("mix","float32",17,4,SX_NONE),
 SX_FIELD("fm_amount","float32",21,4,SX_NONE),
 SX_FIELD("modulator_0","uint8",25,1,SX_ID),
 SX_FIELD("modulation_0","float32",26,4,SX_NONE),
 SX_FIELD("modulator_1","uint8",30,1,SX_ID),
 SX_FIELD("modulation_1","float32",31,4,SX_NONE),
 SX_FIELD("modulator_2","uint8",35,1,SX_ID),
 SX_FIELD("modulation_2","float32",36,4,SX_NONE),
 SX_FIELD("modulator_3","uint8",40,1,SX_ID),
 SX_FIELD("modulation_3","float32",41,4,SX_NONE),
 SX_FIELD("modulator_4","uint8",45,1,SX_ID),
 SX_FIELD("modulation_4","float32",46,4,SX_NONE),
 SX_FIELD("modulator_5","uint8",50,1,SX_ID),
 SX_FIELD("modulation_5","float32",51,4,SX_NONE),
};
const sx_layout sxpcm_beaver_oscillator={UINT32_C(0x60940058),"beaver_oscillator",sxpcm_beaver_oscillator_fields,SX_COUNT(sxpcm_beaver_oscillator_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_filter_fields[]={
 SX_FIELD("mode","uint8",0,1,SX_ID),
 SX_FIELD("cascade","uint8",1,1,SX_FLAGS),
 SX_FIELD("cutoff","float32",2,4,SX_NONE),
 SX_FIELD("resonance","float32",6,4,SX_NONE),
 SX_FIELD("gain","float32",10,4,SX_NONE),
 SX_FIELD("modulator_0","uint8",14,1,SX_ID),
 SX_FIELD("modulation_0","float32",15,4,SX_NONE),
 SX_FIELD("modulator_1","uint8",19,1,SX_ID),
 SX_FIELD("modulation_1","float32",20,4,SX_NONE),
 SX_FIELD("modulator_2","uint8",24,1,SX_ID),
 SX_FIELD("modulation_2","float32",25,4,SX_NONE),
};
const sx_layout sxpcm_beaver_filter={UINT32_C(0x60940059),"beaver_filter",sxpcm_beaver_filter_fields,SX_COUNT(sxpcm_beaver_filter_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_distortion_fields[]={
 SX_FIELD("amount","float32",0,4,SX_NONE),
 SX_FIELD("output_volume","float32",4,4,SX_NONE),
 SX_FIELD("mode","uint8",8,1,SX_ID),
};
const sx_layout sxpcm_beaver_distortion={UINT32_C(0x6094005A),"beaver_distortion",sxpcm_beaver_distortion_fields,SX_COUNT(sxpcm_beaver_distortion_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_delay_fields[]={
 SX_FIELD("left_delay_ticks","uint8",0,1,SX_NONE),
 SX_FIELD("left_echo_ticks","uint8",1,1,SX_NONE),
 SX_FIELD("left_volume","float32",2,4,SX_NONE),
 SX_FIELD("left_feedback","float32",6,4,SX_NONE),
 SX_FIELD("right_delay_ticks","uint8",10,1,SX_NONE),
 SX_FIELD("right_echo_ticks","uint8",11,1,SX_NONE),
 SX_FIELD("right_volume","float32",12,4,SX_NONE),
 SX_FIELD("right_feedback","float32",16,4,SX_NONE),
 SX_FIELD("dry_mix","float32",20,4,SX_NONE),
};
const sx_layout sxpcm_beaver_delay={UINT32_C(0x6094005B),"beaver_delay",sxpcm_beaver_delay_fields,SX_COUNT(sxpcm_beaver_delay_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_chorus_fields[]={
 SX_FIELD("speed","float32",0,4,SX_NONE),
 SX_FIELD("depth","float32",4,4,SX_NONE),
 SX_FIELD("spread","float32",8,4,SX_NONE),
 SX_FIELD("feedback","float32",12,4,SX_NONE),
 SX_FIELD("volume","float32",16,4,SX_NONE),
 SX_FIELD("dry_mix","float32",20,4,SX_NONE),
 SX_FIELD("high_fidelity","uint8",24,1,SX_FLAGS),
};
const sx_layout sxpcm_beaver_chorus={UINT32_C(0x6094005C),"beaver_chorus",sxpcm_beaver_chorus_fields,SX_COUNT(sxpcm_beaver_chorus_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_voice_modulation_fields[]={
 SX_FIELD("volume_modulator","uint8",0,1,SX_ID),
 SX_FIELD("panning_modulator","uint8",1,1,SX_ID),
 SX_FIELD("volume_amount","float32",2,4,SX_NONE),
 SX_FIELD("panning_amount","float32",6,4,SX_NONE),
};
const sx_layout sxpcm_beaver_voice_modulation={UINT32_C(0x6094005D),"beaver_voice_modulation",sxpcm_beaver_voice_modulation_fields,SX_COUNT(sxpcm_beaver_voice_modulation_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_distortion_enabled_fields[]={
 SX_FIELD("enabled","uint8",0,1,SX_FLAGS),
};
const sx_layout sxpcm_beaver_distortion_enabled={UINT32_C(0x6094005E),"beaver_distortion_enabled",sxpcm_beaver_distortion_enabled_fields,SX_COUNT(sxpcm_beaver_distortion_enabled_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_arpeggio_enabled_fields[]={
 SX_FIELD("enabled","uint8",0,1,SX_FLAGS),
};
const sx_layout sxpcm_beaver_arpeggio_enabled={UINT32_C(0x6094005F),"beaver_arpeggio_enabled",sxpcm_beaver_arpeggio_enabled_fields,SX_COUNT(sxpcm_beaver_arpeggio_enabled_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_arpeggio_timing_fields[]={
 SX_FIELD("ticks_per_row","uint8",0,1,SX_NONE),
};
const sx_layout sxpcm_beaver_arpeggio_timing={UINT32_C(0x60940061),"beaver_arpeggio_timing",sxpcm_beaver_arpeggio_timing_fields,SX_COUNT(sxpcm_beaver_arpeggio_timing_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_mixer_fields[]={
 SX_FIELD("volume","float32",0,4,SX_NONE),
 SX_FIELD("panning","float32",4,4,SX_NONE),
 SX_FIELD("effect1_gain","float32",8,4,SX_NONE),
 SX_FIELD("effect2_gain","float32",12,4,SX_NONE),
 SX_FIELD("effect3_gain","float32",16,4,SX_NONE),
};
const sx_layout sxpcm_beaver_mixer={UINT32_C(0x60940062),"beaver_mixer",sxpcm_beaver_mixer_fields,SX_COUNT(sxpcm_beaver_mixer_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_chain_fields[]={
 SX_FIELD("enabled_effect_mask","uint8",0,1,SX_FLAGS),
};
const sx_layout sxpcm_beaver_chain={UINT32_C(0x60940063),"beaver_chain",sxpcm_beaver_chain_fields,SX_COUNT(sxpcm_beaver_chain_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_channel_v102_fields[]={
 SX_FIELD("channel_id","uint8",0,1,SX_ID),
 SX_FIELD("position_count","uint8",1,1,SX_COUNT_PROP),
};
const sx_layout sxpcm_beaver_channel_v102={UINT32_C(0x60940065),"beaver_channel_v102",sxpcm_beaver_channel_v102_fields,SX_COUNT(sxpcm_beaver_channel_v102_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_channel_fields[]={
 SX_FIELD("channel_id","uint8",0,1,SX_ID),
 SX_FIELD("position_count","uint16",1,2,SX_COUNT_PROP),
};
const sx_layout sxpcm_beaver_channel={UINT32_C(0x60940066),"beaver_channel",sxpcm_beaver_channel_fields,SX_COUNT(sxpcm_beaver_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_mask_fields[]={
 SX_FIELD("stored_field_mask","uint16",0,2,SX_FLAGS),
};
const sx_layout sxpcm_beaver_position_mask={UINT32_C(0x60940067),"beaver_position_mask",sxpcm_beaver_position_mask_fields,SX_COUNT(sxpcm_beaver_position_mask_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_pattern_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_NONE),
};
const sx_layout sxpcm_beaver_position_pattern={UINT32_C(0x60940068),"beaver_position_pattern",sxpcm_beaver_position_pattern_fields,SX_COUNT(sxpcm_beaver_position_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_transpose_fields[]={
 SX_FIELD("transpose","int8",0,1,SX_NONE),
};
const sx_layout sxpcm_beaver_position_transpose={UINT32_C(0x60940069),"beaver_position_transpose",sxpcm_beaver_position_transpose_fields,SX_COUNT(sxpcm_beaver_position_transpose_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_effect_fields[]={
 SX_FIELD("effect","uint8",0,1,SX_NONE),
};
const sx_layout sxpcm_beaver_position_effect={UINT32_C(0x6094006A),"beaver_position_effect",sxpcm_beaver_position_effect_fields,SX_COUNT(sxpcm_beaver_position_effect_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_effect_parameter_1_fields[]={
 SX_FIELD("effect_parameter_1","uint8",0,1,SX_NONE),
};
const sx_layout sxpcm_beaver_position_effect_parameter_1={UINT32_C(0x6094006B),"beaver_position_effect_parameter_1",sxpcm_beaver_position_effect_parameter_1_fields,SX_COUNT(sxpcm_beaver_position_effect_parameter_1_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_effect_parameter_2_fields[]={
 SX_FIELD("effect_parameter_2","uint8",0,1,SX_NONE),
};
const sx_layout sxpcm_beaver_position_effect_parameter_2={UINT32_C(0x6094006C),"beaver_position_effect_parameter_2",sxpcm_beaver_position_effect_parameter_2_fields,SX_COUNT(sxpcm_beaver_position_effect_parameter_2_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_effect_parameter_3_fields[]={
 SX_FIELD("effect_parameter_3","uint8",0,1,SX_NONE),
};
const sx_layout sxpcm_beaver_position_effect_parameter_3={UINT32_C(0x6094006D),"beaver_position_effect_parameter_3",sxpcm_beaver_position_effect_parameter_3_fields,SX_COUNT(sxpcm_beaver_position_effect_parameter_3_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_effect_parameter_4_fields[]={
 SX_FIELD("effect_parameter_4","uint8",0,1,SX_NONE),
};
const sx_layout sxpcm_beaver_position_effect_parameter_4={UINT32_C(0x6094006E),"beaver_position_effect_parameter_4",sxpcm_beaver_position_effect_parameter_4_fields,SX_COUNT(sxpcm_beaver_position_effect_parameter_4_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_effect_parameter_5_fields[]={
 SX_FIELD("effect_parameter_5","uint8",0,1,SX_NONE),
};
const sx_layout sxpcm_beaver_position_effect_parameter_5={UINT32_C(0x6094006F),"beaver_position_effect_parameter_5",sxpcm_beaver_position_effect_parameter_5_fields,SX_COUNT(sxpcm_beaver_position_effect_parameter_5_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_effect_parameter_6_fields[]={
 SX_FIELD("effect_parameter_6","uint8",0,1,SX_NONE),
};
const sx_layout sxpcm_beaver_position_effect_parameter_6={UINT32_C(0x60940070),"beaver_position_effect_parameter_6",sxpcm_beaver_position_effect_parameter_6_fields,SX_COUNT(sxpcm_beaver_position_effect_parameter_6_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_pattern_v102_fields[]={
 SX_FIELD("pattern_id","uint8",0,1,SX_ID),
 SX_FIELD("row_count","uint8",1,1,SX_COUNT_PROP),
};
const sx_layout sxpcm_beaver_pattern_v102={UINT32_C(0x60940071),"beaver_pattern_v102",sxpcm_beaver_pattern_v102_fields,SX_COUNT(sxpcm_beaver_pattern_v102_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_pattern_fields[]={
 SX_FIELD("pattern_id","uint8",0,1,SX_ID),
 SX_FIELD("row_count","uint16",1,2,SX_COUNT_PROP),
};
const sx_layout sxpcm_beaver_pattern={UINT32_C(0x60940072),"beaver_pattern",sxpcm_beaver_pattern_fields,SX_COUNT(sxpcm_beaver_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_pattern_row_fields[]={
 SX_FIELD("active_channel_mask","uint32",0,4,SX_FLAGS),
};
const sx_layout sxpcm_beaver_pattern_row={UINT32_C(0x60940073),"beaver_pattern_row",sxpcm_beaver_pattern_row_fields,SX_COUNT(sxpcm_beaver_pattern_row_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("velocity","uint8",1,1,SX_NONE),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("effect_parameter","uint8",3,1,SX_NONE),
};
const sx_layout sxpcm_beaver_event={UINT32_C(0x60940074),"beaver_event",sxpcm_beaver_event_fields,SX_COUNT(sxpcm_beaver_event_fields),SX_LE};
#define SXPCM_ADD(c,n,p) sxpcm_put(c,&sxpcm_##n,p,1)
static bool sxpcm_beaver_take(sx_context*c,uint64_t*p,const sx_layout*l){uint64_t z=sxpcm_width(l);if(!sxpcm_put(c,l,*p,1))return false;*p+=z;return true;}
static bool sxpcm_beaver_component(sx_context*c,uint64_t*p){
 uint8_t t;if(!sxpcm_u8(c,*p,&t)||!sxpcm_beaver_take(c,p,&sxpcm_beaver_type))return false;
 static const sx_layout*const rows[]={NULL,&sxpcm_beaver_envelope,&sxpcm_beaver_lfo,&sxpcm_beaver_controller,&sxpcm_beaver_oscillator,&sxpcm_beaver_filter,&sxpcm_beaver_distortion,&sxpcm_beaver_delay,&sxpcm_beaver_chorus};
 return t>0&&t<SX_COUNT(rows)&&sxpcm_beaver_take(c,p,rows[t]);
}
static bool sxpcm_beaver_types(sx_context*c,uint64_t*p,const sx_layout*counter){uint8_t n;if(!sxpcm_u8(c,*p,&n)||!sxpcm_beaver_take(c,p,counter))return false;for(unsigned i=0;i<n;i++)if(!sxpcm_beaver_component(c,p))return false;return true;}
static bool sxpcm_beaver(sx_context*c){
 if(!sxpcm_eq(c,0,"+SNT",4)||!SXPCM_ADD(c,beaver_synth_marker,0))return false;uint64_t p=4;
 for(unsigned i=0;i<32;i++){uint8_t flags;if(!sxpcm_u8(c,p,&flags)||!sxpcm_beaver_take(c,&p,&sxpcm_beaver_sample_flags)||flags>7)return true;if(flags&1){uint8_t b[3];if(!sxpcm_read(c,p,b,3)||!sxpcm_beaver_take(c,&p,&sxpcm_beaver_sample_length))return true;uint64_t n=(uint64_t)b[0]|(uint64_t)b[1]<<8|(uint64_t)b[2]<<16;if(!sxpcm_span(c,p,n*2))return true;p+=n*2;if(!sxpcm_beaver_take(c,&p,&sxpcm_beaver_sample_loop))return true;}}
 for(unsigned i=0;i<16;i++){uint8_t n;if(!sxpcm_u8(c,p,&n)||!sxpcm_beaver_take(c,&p,&sxpcm_beaver_voice_count)||!sxpcm_put(c,&sxpcm_beaver_polyphony,p,n))return true;p+=n;
  for(unsigned j=0;j<n;j++){if(!sxpcm_beaver_take(c,&p,&sxpcm_beaver_voice_range))return true;uint8_t mods,type;
   if(!sxpcm_u8(c,p,&mods)||!sxpcm_beaver_take(c,&p,&sxpcm_beaver_modulator_count)||!mods||!sxpcm_u8(c,p,&type)||type!=1)return true;
   for(unsigned m=0;m<mods;m++)if(!sxpcm_beaver_component(c,&p))return true;uint8_t oscillators;
   if(!sxpcm_u8(c,p,&oscillators)||!sxpcm_beaver_take(c,&p,&sxpcm_beaver_oscillator_count)||!sxpcm_put(c,&sxpcm_beaver_oscillator,p,oscillators))return true;p+=(uint64_t)oscillators*55;
   if(!sxpcm_beaver_types(c,&p,&sxpcm_beaver_insert_count)||!sxpcm_beaver_take(c,&p,&sxpcm_beaver_voice_modulation))return true;
  }
  uint8_t enabled;if(!sxpcm_u8(c,p,&enabled)||!sxpcm_beaver_take(c,&p,&sxpcm_beaver_distortion_enabled)||enabled>1)return true;if(enabled){uint8_t type;if(!sxpcm_u8(c,p,&type)||type!=6||!sxpcm_beaver_component(c,&p))return true;}
  if(!sxpcm_u8(c,p,&enabled)||!sxpcm_beaver_take(c,&p,&sxpcm_beaver_arpeggio_enabled)||enabled>1)return true;if(enabled){if(!sxpcm_put(c,&sxpcm_beaver_arpeggio_step,p,32))return true;p+=192;if(!sxpcm_beaver_take(c,&p,&sxpcm_beaver_arpeggio_timing))return true;}
 }
 if(!sxpcm_put(c,&sxpcm_beaver_mixer,p,16))return true;p+=320;
 for(unsigned i=0;i<3;i++){uint8_t flags;if(!sxpcm_u8(c,p,&flags)||!sxpcm_beaver_take(c,&p,&sxpcm_beaver_chain))return true;for(unsigned j=0;j<3;j++)if((flags&(1U<<j))&&!sxpcm_beaver_component(c,&p))return true;}
 if(!sxpcm_eq(c,p,"-SNT",4)||!sxpcm_beaver_take(c,&p,&sxpcm_beaver_synth_marker)||!sxpcm_eq(c,p,"GOAT",4))return true;
 uint8_t h[12];if(!sxpcm_read(c,p,h,12)||!sxpcm_beaver_take(c,&p,&sxpcm_beaver_song_header))return true;uint16_t version=sxpcm16(h+4);if(version!=0x102&&version!=0x103)return true;
 for(unsigned i=0;i<h[6];i++){uint16_t count;if(version==0x102){uint8_t n;if(!sxpcm_u8(c,p+1,&n))return true;count=n;}else if(!sxpcm_u16(c,p+1,&count))return true;
  if(!sxpcm_beaver_take(c,&p,version==0x102?&sxpcm_beaver_channel_v102:&sxpcm_beaver_channel))return true;
  static const sx_layout*const fields[]={&sxpcm_beaver_position_pattern,&sxpcm_beaver_position_transpose,&sxpcm_beaver_position_effect,&sxpcm_beaver_position_effect_parameter_1,&sxpcm_beaver_position_effect_parameter_2,&sxpcm_beaver_position_effect_parameter_3,&sxpcm_beaver_position_effect_parameter_4,&sxpcm_beaver_position_effect_parameter_5,&sxpcm_beaver_position_effect_parameter_6};
  for(unsigned j=0;j<count;j++){uint16_t flags;if(!sxpcm_u16(c,p,&flags)||!sxpcm_beaver_take(c,&p,&sxpcm_beaver_position_mask)||flags&~0x1ffU)return true;for(unsigned k=0;k<9;k++)if((flags&(1U<<k))&&!sxpcm_beaver_take(c,&p,fields[k]))return true;}
 }
 for(unsigned i=0;i<h[7];i++){uint16_t count;if(version==0x102){uint8_t n;if(!sxpcm_u8(c,p+1,&n))return true;count=n;}else if(!sxpcm_u16(c,p+1,&count))return true;
  if(!sxpcm_beaver_take(c,&p,version==0x102?&sxpcm_beaver_pattern_v102:&sxpcm_beaver_pattern))return true;
  for(unsigned j=0;j<count;j++){uint32_t flags;if(!sxpcm_u32(c,p,&flags)||!sxpcm_beaver_take(c,&p,&sxpcm_beaver_pattern_row)||flags&0xffff0000U)return true;for(unsigned k=0;k<16;k++)if((flags&(1U<<k))&&!sxpcm_beaver_take(c,&p,&sxpcm_beaver_event))return true;}
 }return true;
}
bool sx_gnilk_beaversweeper_gtk_build(sx_context*c)
{
 return sxpcm_beaver(c);
}
