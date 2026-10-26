/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical music header and table metadata; compressed and unknown bodies stay raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_amigamore.h"
static const xx_data_struct_field_desc sxamore_original_address_fields[]={
 SX_FIELD("original_address","uint32",0,4,SX_ADDRESS),
};
const sx_layout sxamore_original_address={UINT32_C(0x60950003),"original_address",sxamore_original_address_fields,SX_COUNT(sxamore_original_address_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_signed_displacement_fields[]={
 SX_FIELD("relative_displacement","int16",0,2,SX_OFFSET),
};
const sx_layout sxamore_signed_displacement={UINT32_C(0x60950004),"signed_displacement",sxamore_signed_displacement_fields,SX_COUNT(sxamore_signed_displacement_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_prt_header_fields[]={
 SX_FIELD("signature","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("position_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("pattern_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("instrument_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("wave_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("song_name","char[20]",20,20,SX_NONE),
 SX_FIELD("author","char[20]",40,20,SX_NONE),
 SX_FIELD("restart_position","uint8",60,1,SX_NONE),
 SX_FIELD("pattern_count","uint8",61,1,SX_COUNT_PROP),
 SX_FIELD("song_positions","uint8",62,1,SX_COUNT_PROP),
 SX_FIELD("pattern_rows","uint8",63,1,SX_COUNT_PROP),
 SX_FIELD("instrument_count","uint8",64,1,SX_COUNT_PROP),
 SX_FIELD("wave_count","uint8",65,1,SX_COUNT_PROP),
};
const sx_layout sxamore_prt_header={UINT32_C(0x60950006),"prt_header",sxamore_prt_header_fields,SX_COUNT(sxamore_prt_header_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_prt_header30_fields[]={
 SX_FIELD("signature","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("position_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("pattern_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("instrument_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("wave_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("song_name","char[20]",20,20,SX_NONE),
 SX_FIELD("author","char[20]",40,20,SX_NONE),
 SX_FIELD("legacy_parameters","bytes",60,4,SX_NONE),
 SX_FIELD("instrument_count","uint8",64,1,SX_COUNT_PROP),
 SX_FIELD("wave_count","uint8",65,1,SX_COUNT_PROP),
};
const sx_layout sxamore_prt_header30={UINT32_C(0x60950007),"prt_header30",sxamore_prt_header30_fields,SX_COUNT(sxamore_prt_header30_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_prt_generation_order_fields[]={
 SX_FIELD("wave_order","bytes",0,24,SX_NONE),
};
const sx_layout sxamore_prt_generation_order={UINT32_C(0x60950008),"prt_generation_order",sxamore_prt_generation_order_fields,SX_COUNT(sxamore_prt_generation_order_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_prt_subsong_fields[]={
 SX_FIELD("restart_position","uint8",0,1,SX_NONE),
 SX_FIELD("pattern_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("pattern_rows","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("song_positions","uint8",3,1,SX_COUNT_PROP),
 SX_FIELD("pattern_relative_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxamore_prt_subsong={UINT32_C(0x6095000A),"prt_subsong",sxamore_prt_subsong_fields,SX_COUNT(sxamore_prt_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_prt_position_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
const sx_layout sxamore_prt_position={UINT32_C(0x6095000B),"prt_position",sxamore_prt_position_fields,SX_COUNT(sxamore_prt_position_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_prt_pattern_fields[]={
 SX_FIELD("pitch_control","uint8",0,1,SX_FLAGS),
 SX_FIELD("instrument_effect","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect_data","uint8",2,1,SX_NONE),
};
const sx_layout sxamore_prt_pattern={UINT32_C(0x6095000C),"prt_pattern",sxamore_prt_pattern_fields,SX_COUNT(sxamore_prt_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_prt_instrument_pattern_fields[]={
 SX_FIELD("pitch_control","uint8",0,1,SX_FLAGS),
 SX_FIELD("effect_command","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect_data","uint8",2,1,SX_NONE),
};
const sx_layout sxamore_prt_instrument_pattern={UINT32_C(0x6095000D),"prt_instrument_pattern",sxamore_prt_instrument_pattern_fields,SX_COUNT(sxamore_prt_instrument_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_prt_instrument_fields[]={
 SX_FIELD("vibrato_delay","uint8",0,1,SX_NONE),
 SX_FIELD("vibrato_depth","uint8",1,1,SX_NONE),
 SX_FIELD("vibrato_speed","uint8",2,1,SX_NONE),
 SX_FIELD("attack","uint8",3,1,SX_NONE),
 SX_FIELD("decay","uint8",4,1,SX_NONE),
 SX_FIELD("sustain","uint8",5,1,SX_NONE),
 SX_FIELD("release","uint8",6,1,SX_NONE),
 SX_FIELD("pattern_steps","uint8",7,1,SX_COUNT_PROP),
};
const sx_layout sxamore_prt_instrument={UINT32_C(0x6095000E),"prt_instrument",sxamore_prt_instrument_fields,SX_COUNT(sxamore_prt_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_prt_wave_fields[]={
 SX_FIELD("loop_start","uint16",0,2,SX_OFFSET),
 SX_FIELD("loop_end","uint16",2,2,SX_OFFSET),
 SX_FIELD("subloop_length","uint16",4,2,SX_SIZE),
 SX_FIELD("allow_9xx","uint8",6,1,SX_NONE),
 SX_FIELD("subloop_wait","uint8",7,1,SX_NONE),
 SX_FIELD("subloop_step","uint16",8,2,SX_NONE),
 SX_FIELD("chipram_bytes","uint16",10,2,SX_SIZE),
 SX_FIELD("loop_offset","uint16",12,2,SX_OFFSET),
 SX_FIELD("chord_note0","uint8",14,1,SX_NONE),
 SX_FIELD("chord_note1","uint8",15,1,SX_NONE),
 SX_FIELD("chord_note2","uint8",16,1,SX_NONE),
 SX_FIELD("chord_shift","uint8",17,1,SX_NONE),
 SX_FIELD("unknown_oscillator","uint8",18,1,SX_NONE),
 SX_FIELD("oscillator_phase_speed","uint8",19,1,SX_NONE),
 SX_FIELD("flags","uint8",20,1,SX_FLAGS),
 SX_FIELD("oscillator_phase_min","uint8",21,1,SX_NONE),
 SX_FIELD("oscillator_phase_max","uint8",22,1,SX_NONE),
 SX_FIELD("base_note","uint8",23,1,SX_NONE),
 SX_FIELD("gain","uint8",24,1,SX_NONE),
 SX_FIELD("sample_blocks_minus_one","uint8",25,1,SX_NONE),
 SX_FIELD("mix_wave","uint8",26,1,SX_ID),
 SX_FIELD("volume_attack","uint8",27,1,SX_NONE),
 SX_FIELD("volume_delay","uint8",28,1,SX_NONE),
 SX_FIELD("volume_decay","uint8",29,1,SX_NONE),
 SX_FIELD("volume_sustain","uint8",30,1,SX_NONE),
 SX_FIELD("filter_type","uint8",31,1,SX_ID),
 SX_FIELD("filter_resonance","uint8",32,1,SX_NONE),
 SX_FIELD("pitch_ramp","uint8",33,1,SX_NONE),
 SX_FIELD("filter_start","uint8",34,1,SX_NONE),
 SX_FIELD("filter_min","uint8",35,1,SX_NONE),
 SX_FIELD("filter_max","uint8",36,1,SX_NONE),
 SX_FIELD("filter_speed","uint8",37,1,SX_NONE),
 SX_FIELD("modulation_wetness","uint8",38,1,SX_NONE),
 SX_FIELD("modulation_length","uint8",39,1,SX_NONE),
 SX_FIELD("modulation_predelay","uint8",40,1,SX_NONE),
 SX_FIELD("modulation_density_control","uint8",41,1,SX_FLAGS),
};
const sx_layout sxamore_prt_wave={UINT32_C(0x6095000F),"prt_wave",sxamore_prt_wave_fields,SX_COUNT(sxamore_prt_wave_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_thm_header_fields[]={
 SX_FIELD("pattern_table0","uint32",0,4,SX_ADDRESS),
 SX_FIELD("pattern_table1","uint32",4,4,SX_ADDRESS),
 SX_FIELD("pattern_table2","uint32",8,4,SX_ADDRESS),
 SX_FIELD("pattern_table3","uint32",12,4,SX_ADDRESS),
 SX_FIELD("order_table0","uint32",16,4,SX_ADDRESS),
 SX_FIELD("order_table1","uint32",20,4,SX_ADDRESS),
 SX_FIELD("order_table2","uint32",24,4,SX_ADDRESS),
 SX_FIELD("order_table3","uint32",28,4,SX_ADDRESS),
 SX_FIELD("loop_position","uint8",32,1,SX_NONE),
 SX_FIELD("end_position","uint8",33,1,SX_NONE),
 SX_FIELD("first_position","uint8",34,1,SX_NONE),
 SX_FIELD("sample_count","uint8",35,1,SX_COUNT_PROP),
 SX_FIELD("stored_address","uint32",36,4,SX_ADDRESS),
 SX_FIELD("unknown40","uint8",40,1,SX_NONE),
 SX_FIELD("rows_minus_one","uint8",41,1,SX_NONE),
 SX_FIELD("cia_timer","uint16",42,2,SX_NONE),
 SX_FIELD("speed_minus_two","uint8",44,1,SX_NONE),
 SX_FIELD("unknown45","uint8",45,1,SX_NONE),
 SX_FIELD("original_base","uint32",46,4,SX_ADDRESS),
 SX_FIELD("channel0_mute","uint8",50,1,SX_NONE),
 SX_FIELD("channel1_mute","uint8",51,1,SX_NONE),
 SX_FIELD("channel2_mute","uint8",52,1,SX_NONE),
 SX_FIELD("channel3_mute","uint8",53,1,SX_NONE),
 SX_FIELD("unknown_tail","bytes",54,10,SX_NONE),
};
const sx_layout sxamore_thm_header={UINT32_C(0x60950010),"thm_header",sxamore_thm_header_fields,SX_COUNT(sxamore_thm_header_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_thm_sample_fields[]={
 SX_FIELD("sample_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("unknown4","uint16",4,2,SX_NONE),
 SX_FIELD("runtime_sample_address_slot","uint32",6,4,SX_NONE),
 SX_FIELD("unknown10","bytes",10,6,SX_NONE),
 SX_FIELD("sample_name","char[22]",16,22,SX_NONE),
 SX_FIELD("unknown_tail","bytes",38,10,SX_NONE),
};
const sx_layout sxamore_thm_sample={UINT32_C(0x60950012),"thm_sample",sxamore_thm_sample_fields,SX_COUNT(sxamore_thm_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rh_sample_count_fields[]={
 SX_FIELD("samples_minus_one","uint8",0,1,SX_NONE),
};
const sx_layout sxamore_rh_sample_count={UINT32_C(0x60950013),"rh_sample_count",sxamore_rh_sample_count_fields,SX_COUNT(sxamore_rh_sample_count_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_rh_sample_fields[]={
 SX_FIELD("sample_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("unknown","uint16",4,2,SX_NONE),
};
const sx_layout sxamore_rh_sample={UINT32_C(0x60950014),"rh_sample",sxamore_rh_sample_fields,SX_COUNT(sxamore_rh_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rh_subsong_fields[]={
 SX_FIELD("control","uint16",0,2,SX_NONE),
 SX_FIELD("channel0_offset","uint32",2,4,SX_OFFSET),
 SX_FIELD("channel1_offset","uint32",6,4,SX_OFFSET),
 SX_FIELD("channel2_offset","uint32",10,4,SX_OFFSET),
 SX_FIELD("channel3_offset","uint32",14,4,SX_OFFSET),
};
const sx_layout sxamore_rh_subsong={UINT32_C(0x60950015),"rh_subsong",sxamore_rh_subsong_fields,SX_COUNT(sxamore_rh_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_jt_subsong_fields[]={
 SX_FIELD("channel0_address","uint32",0,4,SX_ADDRESS),
 SX_FIELD("channel1_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("channel2_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("channel3_address","uint32",12,4,SX_ADDRESS),
 SX_FIELD("marker","uint8",16,1,SX_ID),
 SX_FIELD("control","uint8",17,1,SX_NONE),
};
const sx_layout sxamore_jt_subsong={UINT32_C(0x60950016),"jt_subsong",sxamore_jt_subsong_fields,SX_COUNT(sxamore_jt_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_jt_sample_fields[]={
 SX_FIELD("unknown","uint16",0,2,SX_NONE),
 SX_FIELD("length_words","uint16",2,2,SX_NONE),
 SX_FIELD("sample_address","uint32",4,4,SX_ADDRESS),
};
const sx_layout sxamore_jt_sample={UINT32_C(0x60950017),"jt_sample",sxamore_jt_sample_fields,SX_COUNT(sxamore_jt_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_wb_subsong_fields[]={
 SX_FIELD("channel0_address","uint32",0,4,SX_ADDRESS),
 SX_FIELD("channel1_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("channel2_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("channel3_address","uint32",12,4,SX_ADDRESS),
};
const sx_layout sxamore_wb_subsong={UINT32_C(0x60950018),"wb_subsong",sxamore_wb_subsong_fields,SX_COUNT(sxamore_wb_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_wb_count_fields[]={
 SX_FIELD("subsongs_plus_one","uint32",0,4,SX_NONE),
};
const sx_layout sxamore_wb_count={UINT32_C(0x60950019),"wb_count",sxamore_wb_count_fields,SX_COUNT(sxamore_wb_count_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_sun_initial_channels_fields[]={
 SX_FIELD("channel0_address","uint32",0,4,SX_ADDRESS),
 SX_FIELD("channel1_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("channel2_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("channel3_address","uint32",12,4,SX_ADDRESS),
 SX_FIELD("control0","uint8",16,1,SX_NONE),
 SX_FIELD("control1","uint8",17,1,SX_NONE),
 SX_FIELD("control2","uint8",18,1,SX_NONE),
 SX_FIELD("control3","uint8",19,1,SX_NONE),
};
const sx_layout sxamore_sun_initial_channels={UINT32_C(0x6095001A),"sun_initial_channels",sxamore_sun_initial_channels_fields,SX_COUNT(sxamore_sun_initial_channels_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_hunk_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("resident_names_end","uint32",4,4,SX_ID),
 SX_FIELD("table_entries","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("first_hunk","uint32",12,4,SX_ID),
 SX_FIELD("last_hunk","uint32",16,4,SX_ID),
 SX_FIELD("allocation_words_and_flags","uint32",20,4,SX_FLAGS),
 SX_FIELD("code_hunk","uint32",24,4,SX_ID),
 SX_FIELD("code_words","uint32",28,4,SX_COUNT_PROP),
};
const sx_layout sxamore_rk_hunk_header={UINT32_C(0x6095001B),"rk_hunk_header",sxamore_rk_hunk_header_fields,SX_COUNT(sxamore_rk_hunk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_jump_fields[]={
 SX_FIELD("opcode","uint16",0,2,SX_ID),
 SX_FIELD("code_relative_offset","uint32",2,4,SX_OFFSET),
};
const sx_layout sxamore_rk_jump={UINT32_C(0x6095001C),"rk_jump",sxamore_rk_jump_fields,SX_COUNT(sxamore_rk_jump_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_subsong_fields[]={
 SX_FIELD("channel0_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("channel1_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("channel2_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("channel3_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sxamore_rk_subsong={UINT32_C(0x6095001E),"rk_subsong",sxamore_rk_subsong_fields,SX_COUNT(sxamore_rk_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_position_fields[]={
 SX_FIELD("track_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("unknown4","bytes",4,2,SX_NONE),
 SX_FIELD("transpose","int16",6,2,SX_NONE),
 SX_FIELD("unknown8","bytes",8,2,SX_NONE),
 SX_FIELD("repeat_count","uint16",10,2,SX_COUNT_PROP),
};
const sx_layout sxamore_rk_position={UINT32_C(0x6095001F),"rk_position",sxamore_rk_position_fields,SX_COUNT(sxamore_rk_position_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_cia_write_fields[]={
 SX_FIELD("opcode","uint16",0,2,SX_ID),
 SX_FIELD("immediate","uint16",2,2,SX_NONE),
 SX_FIELD("register_address","uint32",4,4,SX_ADDRESS),
};
const sx_layout sxamore_rk_cia_write={UINT32_C(0x60950021),"rk_cia_write",sxamore_rk_cia_write_fields,SX_COUNT(sxamore_rk_cia_write_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_vector_write_fields[]={
 SX_FIELD("opcode","uint16",0,2,SX_ID),
 SX_FIELD("code_relative_offset","uint32",2,4,SX_OFFSET),
 SX_FIELD("vector_address","uint32",6,4,SX_ADDRESS),
};
const sx_layout sxamore_rk_vector_write={UINT32_C(0x60950022),"rk_vector_write",sxamore_rk_vector_write_fields,SX_COUNT(sxamore_rk_vector_write_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rjp_section_fields[]={
 SX_FIELD("payload_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxamore_rjp_section={UINT32_C(0x60950024),"rjp_section",sxamore_rjp_section_fields,SX_COUNT(sxamore_rjp_section_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rjp_sample_fields[]={
 SX_FIELD("sample_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("sample_related_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("other_sample_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("envelope_offset","int16",12,2,SX_OFFSET),
 SX_FIELD("volume_control","int16",14,2,SX_NONE),
 SX_FIELD("start_words","uint16",16,2,SX_NONE),
 SX_FIELD("length_words","uint16",18,2,SX_NONE),
 SX_FIELD("control20","uint16",20,2,SX_NONE),
 SX_FIELD("control22","uint16",22,2,SX_NONE),
 SX_FIELD("control24","uint16",24,2,SX_NONE),
 SX_FIELD("other_length_words","uint16",26,2,SX_NONE),
 SX_FIELD("control28","uint16",28,2,SX_NONE),
 SX_FIELD("third_length_words","uint16",30,2,SX_NONE),
};
const sx_layout sxamore_rjp_sample={UINT32_C(0x60950025),"rjp_sample",sxamore_rjp_sample_fields,SX_COUNT(sxamore_rjp_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rjp_position_offset_fields[]={
 SX_FIELD("position_relative_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxamore_rjp_position_offset={UINT32_C(0x60950027),"rjp_position_offset",sxamore_rjp_position_offset_fields,SX_COUNT(sxamore_rjp_position_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rjp_step_offset_fields[]={
 SX_FIELD("step_relative_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxamore_rjp_step_offset={UINT32_C(0x60950028),"rjp_step_offset",sxamore_rjp_step_offset_fields,SX_COUNT(sxamore_rjp_step_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_index_extension_fields[]={
 SX_FIELD("index_control","uint8",0,1,SX_FLAGS),
 SX_FIELD("global_relative_displacement","int8",1,1,SX_OFFSET),
};
const sx_layout sxamore_rk_index_extension={UINT32_C(0x60950029),"rk_index_extension",sxamore_rk_index_extension_fields,SX_COUNT(sxamore_rk_index_extension_fields),SX_LE};
static const sx_layout *const sx_amigamore_layouts[]={
 &sxamore_text,
 &sxamore_nul,
 &sxamore_original_address,
 &sxamore_signed_displacement,
 &sxamore_end_word,
 &sxamore_prt_header,
 &sxamore_prt_header30,
 &sxamore_prt_generation_order,
 &sxamore_prt_subsong_count,
 &sxamore_prt_subsong,
 &sxamore_prt_position,
 &sxamore_prt_pattern,
 &sxamore_prt_instrument_pattern,
 &sxamore_prt_instrument,
 &sxamore_prt_wave,
 &sxamore_thm_header,
 &sxamore_thm_order,
 &sxamore_thm_sample,
 &sxamore_rh_sample_count,
 &sxamore_rh_sample,
 &sxamore_rh_subsong,
 &sxamore_jt_subsong,
 &sxamore_jt_sample,
 &sxamore_wb_subsong,
 &sxamore_wb_count,
 &sxamore_sun_initial_channels,
 &sxamore_rk_hunk_header,
 &sxamore_rk_jump,
 &sxamore_rk_selector,
 &sxamore_rk_subsong,
 &sxamore_rk_position,
 &sxamore_rk_position_end,
 &sxamore_rk_cia_write,
 &sxamore_rk_vector_write,
 &sxamore_rjp_header,
 &sxamore_rjp_section,
 &sxamore_rjp_sample,
 &sxamore_rjp_subsong,
 &sxamore_rjp_position_offset,
 &sxamore_rjp_step_offset,
 &sxamore_rk_index_extension,
 &sxamore_sun_end,
};
bool sxamore_span(sxamore_view*v,uint64_t at,uint64_t n,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&v->c->size>=0&&end<=(uint64_t)v->c->size&&at<=end&&n<=end-at;}
static bool sxamore_read(sxamore_view*v,uint64_t at,void*p,size_t n,uint64_t end)
{return ++v->work<=4000000&&sxamore_span(v,at,n,end)&&sx_read(v->c,(int64_t)at,p,n);}
static bool sxamore_word(sxamore_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!n||n>8||!sxamore_read(v,at,b,n,end))return false;uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[be?n-i-1:i]<<(8*i);*out=x;return true;}
bool sxamore_row(sxamore_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxamore_span(v,at,z,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)z);}
bool sxamore_table(sxamore_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>4000000||count>UINT64_MAX/z||!sxamore_span(v,at,count*z,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++,at+=z)if(!sxamore_row(v,l,at,end))return false;return true;}
static int sxamore_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxamore_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxamore_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxamore_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
bool sxamore_be(sxamore_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxamore_word(v,p,n,true,x,end);}
bool sxamore_eq(sxamore_view*v,uint64_t p,const char*s,size_t n,uint64_t end){uint8_t b[64];return n<=sizeof(b)&&sxamore_read(v,p,b,n,end)&&!xx_rt_memcmp(b,s,n);}
bool sxamore_take(sxamore_view*v,const sx_layout*l,uint64_t*p,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!sxamore_table(v,l,*p,count,end))return false;*p+=count*z;return true;}
bool sxamore_signed16(sxamore_view*v,uint64_t at,uint64_t base,uint64_t*out,uint64_t end)
{uint64_t u;if(!sxamore_be(v,at,2,&u,end))return false;int64_t d=u<32768?(int64_t)u:(int64_t)u-65536;
 if(d<0){uint64_t n=(uint64_t)(-d);if(base<n)return false;*out=base-n;}else{if(base>end||(uint64_t)d>end-base)return false;*out=base+(uint64_t)d;}return *out<=end;}
bool sxamore_find(sxamore_view*v,uint64_t*at,uint64_t end,uint64_t pattern,unsigned width,unsigned step)
{if(!step||!width||width>8||*at>end)return false;uint64_t limit=end;if(limit-*at>UINT64_C(1048576))limit=*at+UINT64_C(1048576);for(;*at<=limit&&width<=limit-*at;*at+=step){uint64_t x;if(!sxamore_be(v,*at,width,&x,end))return false;if(x==pattern)return true;}return false;}
bool sxamore_map(uint64_t address,uint64_t origin,uint64_t end,uint64_t*out)
{if(address<origin||address-origin>end)return false;*out=address-origin;return true;}
static bool sx_amigamore_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_DIE_MUSIC_PINK_PRETRACKER_PRT:
case XX_FILE_TYPE_DIE_MUSIC_RICHARDJOSEPH_RJP_SNG:
case XX_FILE_TYPE_DIE_MUSIC_THOMASHERMANN_THM:
case XX_FILE_TYPE_DIE_MUSIC_RONKLAREN_RK:
case XX_FILE_TYPE_DIE_MUSIC_ROBHUBBARD_RH:
case XX_FILE_TYPE_DIE_MUSIC_SCHMIDT_SUNTRONIC:
case XX_FILE_TYPE_DIE_MUSIC_WALLYBEBEN:
case XX_FILE_TYPE_DIE_MUSIC_JEROENTEL:
return true;default:return false;}}
static bool sx_amigamore_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxamore_view view={c,0},*v=&view;bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_DIE_MUSIC_PINK_PRETRACKER_PRT:ok=sx_pink_pretracker_prt_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_RICHARDJOSEPH_RJP_SNG:ok=sx_richardjoseph_rjp_sng_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_THOMASHERMANN_THM:ok=sx_thomashermann_thm_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_RONKLAREN_RK:ok=sx_ronklaren_rk_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_ROBHUBBARD_RH:ok=sx_robhubbard_rh_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_SCHMIDT_SUNTRONIC:ok=sx_schmidt_suntronic_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_WALLYBEBEN:ok=sx_wallybeben_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_JEROENTEL:ok=sx_jeroentel_build(v);break;
default:break;}return ok&&sxamore_finish(c); }
static bool sxamore_name_is(const xx_data_struct_record*r,const wchar_t*n){return !xx_rt_wcscmp(r->name,n);}
static bool sx_amigamore_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id<UINT32_C(0x60950001)||id>=UINT32_C(0x60960000))return true;
 const wchar_t*s=NULL;
 if(id==sxamore_original_address.id)s=L"Original stored address before replay relocation; metadata mapping subtracts the loader-authenticated original base";
 else if(id==sxamore_signed_displacement.id)s=L"Signed 16-bit byte displacement in an authenticated player operand; the origin is format-specific";
 else if(id==sxamore_prt_header.id||id==sxamore_prt_header30.id){
  if(r->property&SX_OFFSET)s=L"Absolute byte offset from the start of the PRT file";
  else if(sxamore_name_is(r,L"version"))s=L"19 hex: PreTracker 0.x; 1B hex: 1.0; 1E hex: 1.5 physical dialect";
  else if(sxamore_name_is(r,L"legacy_parameters"))s=L"Legacy single-song parameters replaced by per-subsong records in version 1.5; original bytes preserved";
 }
 else if(id==sxamore_prt_generation_order.id)s=L"Twenty-four stored waveform indices used in generation order; no generated PCM exists here";
 else if(id==sxamore_prt_subsong.id&&sxamore_name_is(r,L"pattern_relative_offset"))s=L"Byte offset relative to the PATT block named by header pattern_offset";
 else if(id==sxamore_prt_position.id&&sxamore_name_is(r,L"transpose"))s=L"Signed pitch shift for this channel position";
 else if(id==sxamore_prt_pattern.id){if(sxamore_name_is(r,L"pitch_control"))s=L"Bits 0..5 pitch; bit 6 arpeggio/effect selector; bit 7 instrument bit 4";else if(sxamore_name_is(r,L"instrument_effect"))s=L"High nibble instrument bits 0..3; low nibble effect command";}
 else if(id==sxamore_prt_instrument_pattern.id){if(sxamore_name_is(r,L"pitch_control"))s=L"Bits 0..5 pitch; bit 6 fixed pitch; bit 7 joins the next note";else s=L"Stored instrument-pattern effect bytes, not a separate length prefix";}
 else if(id==sxamore_prt_instrument.id&&!(r->property&SX_COUNT_PROP))s=L"Encoded player table/control value; preserve the stored byte rather than a replay-derived rate";
 else if(id==sxamore_prt_wave.id){
  if(r->property&SX_OFFSET)s=L"Byte position in the generated waveform, not an offset into this file";
  else if(r->property&SX_SIZE)s=L"Byte extent in the generated waveform, not a physical payload length";
  else if(sxamore_name_is(r,L"sample_blocks_minus_one"))s=L"Generated sample size in bytes is (stored value + 1) times 128";
  else if(sxamore_name_is(r,L"flags"))s=L"Bits 0..1 oscillator type; bit 2 extra octaves; bit 3 boost; bit 4 linear pitch; bit 5 fast volume";
  else if(sxamore_name_is(r,L"filter_type"))s=L"1 low-pass; 2 high-pass; 3 band-pass; 4 notch";
  else if(sxamore_name_is(r,L"modulation_density_control"))s=L"Bits 0..2 density; bits 3..4 unison control; bit 5 post-processing";
  else if(sxamore_name_is(r,L"subloop_step"))s=L"Unsigned byte-distance step within the generated sample; the player chooses traversal direction";
 }
 else if(id==sxamore_thm_header.id){if(r->property&SX_ADDRESS)s=L"Original address before replay relocation; subtract original_base for physical metadata coordinates";else if(sxamore_name_is(r,L"rows_minus_one"))s=L"Stored row count minus one; FF encodes 256 rows";else if(sxamore_name_is(r,L"speed_minus_two"))s=L"Stored speed control; original player adds two";else if(sxamore_name_is(r,L"cia_timer"))s=L"CIA timer period in E-clock ticks; not a wall-clock timestamp";}
 else if(id==sxamore_thm_sample.id){if(sxamore_name_is(r,L"sample_bytes"))s=L"Required byte count from a separate sample file; no in-file sample body is inferred";else if(sxamore_name_is(r,L"runtime_sample_address_slot"))s=L"Original stored slot is overwritten by the player with an external sample address; not followed in this file";}
 else if(id==sxamore_rh_sample_count.id)s=L"Stored sample count minus one";
 else if(id==sxamore_rh_sample.id&&sxamore_name_is(r,L"sample_bytes"))s=L"Sample payload bytes following this six-byte header";
 else if(id==sxamore_rh_subsong.id&&(r->property&SX_OFFSET))s=L"Byte offset relative to the start of the RH module";
 else if(id==sxamore_jt_sample.id&&sxamore_name_is(r,L"length_words"))s=L"Unsigned sample length in two-byte words";
 else if(id==sxamore_wb_count.id)s=L"Stored subsong count plus one; the original player subtracts one";
 else if(id==sxamore_wb_subsong.id||id==sxamore_jt_subsong.id||id==sxamore_sun_initial_channels.id){if(r->property&SX_ADDRESS)s=L"Original stored channel address before replay relocation; player code and command bodies remain raw";}
 else if(id==sxamore_rk_hunk_header.id){if(sxamore_name_is(r,L"allocation_words_and_flags"))s=L"Low 30 bits allocation size in 32-bit words; high bits Amiga memory flags";else if(sxamore_name_is(r,L"code_words"))s=L"Code payload size in 32-bit words";}
 else if(id==sxamore_rk_jump.id||id==sxamore_rk_subsong.id||id==sxamore_rk_vector_write.id||id==sxamore_rk_position.id){if(r->property&SX_OFFSET)s=L"Byte offset relative to the code payload, which begins at physical file offset 20 hex";}
 else if(id==sxamore_rk_index_extension.id){if(r->property&SX_OFFSET)s=L"Signed brief-extension displacement from the authenticated global-data base";else s=L"68000 brief-index control byte; this provider follows only the original D0.W nonnegative-displacement variant";}
 else if(id==sxamore_rk_cia_write.id&&sxamore_name_is(r,L"immediate"))s=L"MOVE.B immediate occupies a word; its low byte is written to the CIA timer register";
 else if(id==sxamore_rjp_section.id)s=L"Physical payload bytes excluding this four-byte big-endian section-length word";
 else if(id==sxamore_rjp_sample.id){
  if(r->property&SX_OFFSET)s=sxamore_name_is(r,L"envelope_offset")?L"Signed byte displacement from the volume/envelope section payload":L"Byte offset from offset 4 of the separate INS sample file; not a coordinate within this SNG";
  else if(sxamore_name_is(r,L"volume_control"))s=L"Signed stored multiplication control used by the original player";
  else if(sxamore_name_is(r,L"start_words")||sxamore_name_is(r,L"length_words")||sxamore_name_is(r,L"other_length_words")||sxamore_name_is(r,L"third_length_words"))s=L"Stored two-byte-word unit; original replay expands this value for sample addressing";
 }
 else if(id==sxamore_rjp_position_offset.id)s=L"Byte offset relative to section 5 PositionPtr payload";
 else if(id==sxamore_rjp_step_offset.id)s=L"Byte offset relative to section 6 FirstStepPtr payload; four leading table entries are retained";
 return !s||xx_data_struct_record_set_comment(r,s);
}
const sx_family sx_amigamore_family={sx_amigamore_supports,sx_amigamore_build,sx_amigamore_layouts,SX_COUNT(sx_amigamore_layouts),sx_amigamore_comment};
