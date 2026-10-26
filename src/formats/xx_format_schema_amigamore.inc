/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical music header and table metadata; compressed and unknown bodies stay raw. */
static const xx_data_struct_field_desc sxamore_text_fields[]={
 SX_FIELD("text","char",0,0,SX_NONE),
};
static const sx_layout sxamore_text={UINT32_C(0x60950001),"text",sxamore_text_fields,SX_COUNT(sxamore_text_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_nul_fields[]={
 SX_FIELD("terminator","uint8",0,1,SX_ID),
};
static const sx_layout sxamore_nul={UINT32_C(0x60950002),"nul",sxamore_nul_fields,SX_COUNT(sxamore_nul_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_original_address_fields[]={
 SX_FIELD("original_address","uint32",0,4,SX_ADDRESS),
};
static const sx_layout sxamore_original_address={UINT32_C(0x60950003),"original_address",sxamore_original_address_fields,SX_COUNT(sxamore_original_address_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_signed_displacement_fields[]={
 SX_FIELD("relative_displacement","int16",0,2,SX_OFFSET),
};
static const sx_layout sxamore_signed_displacement={UINT32_C(0x60950004),"signed_displacement",sxamore_signed_displacement_fields,SX_COUNT(sxamore_signed_displacement_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_end_word_fields[]={
 SX_FIELD("end_marker","uint16",0,2,SX_ID),
};
static const sx_layout sxamore_end_word={UINT32_C(0x60950005),"end_word",sxamore_end_word_fields,SX_COUNT(sxamore_end_word_fields),SX_BE};
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
static const sx_layout sxamore_prt_header={UINT32_C(0x60950006),"prt_header",sxamore_prt_header_fields,SX_COUNT(sxamore_prt_header_fields),SX_BE};
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
static const sx_layout sxamore_prt_header30={UINT32_C(0x60950007),"prt_header30",sxamore_prt_header30_fields,SX_COUNT(sxamore_prt_header30_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_prt_generation_order_fields[]={
 SX_FIELD("wave_order","bytes",0,24,SX_NONE),
};
static const sx_layout sxamore_prt_generation_order={UINT32_C(0x60950008),"prt_generation_order",sxamore_prt_generation_order_fields,SX_COUNT(sxamore_prt_generation_order_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_prt_subsong_count_fields[]={
 SX_FIELD("subsong_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxamore_prt_subsong_count={UINT32_C(0x60950009),"prt_subsong_count",sxamore_prt_subsong_count_fields,SX_COUNT(sxamore_prt_subsong_count_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_prt_subsong_fields[]={
 SX_FIELD("restart_position","uint8",0,1,SX_NONE),
 SX_FIELD("pattern_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("pattern_rows","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("song_positions","uint8",3,1,SX_COUNT_PROP),
 SX_FIELD("pattern_relative_offset","uint32",4,4,SX_OFFSET),
};
static const sx_layout sxamore_prt_subsong={UINT32_C(0x6095000A),"prt_subsong",sxamore_prt_subsong_fields,SX_COUNT(sxamore_prt_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_prt_position_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
static const sx_layout sxamore_prt_position={UINT32_C(0x6095000B),"prt_position",sxamore_prt_position_fields,SX_COUNT(sxamore_prt_position_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_prt_pattern_fields[]={
 SX_FIELD("pitch_control","uint8",0,1,SX_FLAGS),
 SX_FIELD("instrument_effect","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect_data","uint8",2,1,SX_NONE),
};
static const sx_layout sxamore_prt_pattern={UINT32_C(0x6095000C),"prt_pattern",sxamore_prt_pattern_fields,SX_COUNT(sxamore_prt_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_prt_instrument_pattern_fields[]={
 SX_FIELD("pitch_control","uint8",0,1,SX_FLAGS),
 SX_FIELD("effect_command","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect_data","uint8",2,1,SX_NONE),
};
static const sx_layout sxamore_prt_instrument_pattern={UINT32_C(0x6095000D),"prt_instrument_pattern",sxamore_prt_instrument_pattern_fields,SX_COUNT(sxamore_prt_instrument_pattern_fields),SX_LE};
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
static const sx_layout sxamore_prt_instrument={UINT32_C(0x6095000E),"prt_instrument",sxamore_prt_instrument_fields,SX_COUNT(sxamore_prt_instrument_fields),SX_LE};
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
static const sx_layout sxamore_prt_wave={UINT32_C(0x6095000F),"prt_wave",sxamore_prt_wave_fields,SX_COUNT(sxamore_prt_wave_fields),SX_BE};
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
static const sx_layout sxamore_thm_header={UINT32_C(0x60950010),"thm_header",sxamore_thm_header_fields,SX_COUNT(sxamore_thm_header_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_thm_order_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
};
static const sx_layout sxamore_thm_order={UINT32_C(0x60950011),"thm_order",sxamore_thm_order_fields,SX_COUNT(sxamore_thm_order_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_thm_sample_fields[]={
 SX_FIELD("sample_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("unknown4","uint16",4,2,SX_NONE),
 SX_FIELD("runtime_sample_address_slot","uint32",6,4,SX_NONE),
 SX_FIELD("unknown10","bytes",10,6,SX_NONE),
 SX_FIELD("sample_name","char[22]",16,22,SX_NONE),
 SX_FIELD("unknown_tail","bytes",38,10,SX_NONE),
};
static const sx_layout sxamore_thm_sample={UINT32_C(0x60950012),"thm_sample",sxamore_thm_sample_fields,SX_COUNT(sxamore_thm_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rh_sample_count_fields[]={
 SX_FIELD("samples_minus_one","uint8",0,1,SX_NONE),
};
static const sx_layout sxamore_rh_sample_count={UINT32_C(0x60950013),"rh_sample_count",sxamore_rh_sample_count_fields,SX_COUNT(sxamore_rh_sample_count_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_rh_sample_fields[]={
 SX_FIELD("sample_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("unknown","uint16",4,2,SX_NONE),
};
static const sx_layout sxamore_rh_sample={UINT32_C(0x60950014),"rh_sample",sxamore_rh_sample_fields,SX_COUNT(sxamore_rh_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rh_subsong_fields[]={
 SX_FIELD("control","uint16",0,2,SX_NONE),
 SX_FIELD("channel0_offset","uint32",2,4,SX_OFFSET),
 SX_FIELD("channel1_offset","uint32",6,4,SX_OFFSET),
 SX_FIELD("channel2_offset","uint32",10,4,SX_OFFSET),
 SX_FIELD("channel3_offset","uint32",14,4,SX_OFFSET),
};
static const sx_layout sxamore_rh_subsong={UINT32_C(0x60950015),"rh_subsong",sxamore_rh_subsong_fields,SX_COUNT(sxamore_rh_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_jt_subsong_fields[]={
 SX_FIELD("channel0_address","uint32",0,4,SX_ADDRESS),
 SX_FIELD("channel1_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("channel2_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("channel3_address","uint32",12,4,SX_ADDRESS),
 SX_FIELD("marker","uint8",16,1,SX_ID),
 SX_FIELD("control","uint8",17,1,SX_NONE),
};
static const sx_layout sxamore_jt_subsong={UINT32_C(0x60950016),"jt_subsong",sxamore_jt_subsong_fields,SX_COUNT(sxamore_jt_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_jt_sample_fields[]={
 SX_FIELD("unknown","uint16",0,2,SX_NONE),
 SX_FIELD("length_words","uint16",2,2,SX_NONE),
 SX_FIELD("sample_address","uint32",4,4,SX_ADDRESS),
};
static const sx_layout sxamore_jt_sample={UINT32_C(0x60950017),"jt_sample",sxamore_jt_sample_fields,SX_COUNT(sxamore_jt_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_wb_subsong_fields[]={
 SX_FIELD("channel0_address","uint32",0,4,SX_ADDRESS),
 SX_FIELD("channel1_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("channel2_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("channel3_address","uint32",12,4,SX_ADDRESS),
};
static const sx_layout sxamore_wb_subsong={UINT32_C(0x60950018),"wb_subsong",sxamore_wb_subsong_fields,SX_COUNT(sxamore_wb_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_wb_count_fields[]={
 SX_FIELD("subsongs_plus_one","uint32",0,4,SX_NONE),
};
static const sx_layout sxamore_wb_count={UINT32_C(0x60950019),"wb_count",sxamore_wb_count_fields,SX_COUNT(sxamore_wb_count_fields),SX_BE};
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
static const sx_layout sxamore_sun_initial_channels={UINT32_C(0x6095001A),"sun_initial_channels",sxamore_sun_initial_channels_fields,SX_COUNT(sxamore_sun_initial_channels_fields),SX_BE};
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
static const sx_layout sxamore_rk_hunk_header={UINT32_C(0x6095001B),"rk_hunk_header",sxamore_rk_hunk_header_fields,SX_COUNT(sxamore_rk_hunk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_jump_fields[]={
 SX_FIELD("opcode","uint16",0,2,SX_ID),
 SX_FIELD("code_relative_offset","uint32",2,4,SX_OFFSET),
};
static const sx_layout sxamore_rk_jump={UINT32_C(0x6095001C),"rk_jump",sxamore_rk_jump_fields,SX_COUNT(sxamore_rk_jump_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_selector_fields[]={
 SX_FIELD("opcode","uint16",0,2,SX_ID),
 SX_FIELD("subsong","uint16",2,2,SX_ID),
 SX_FIELD("branch_code","bytes",4,4,SX_NONE),
};
static const sx_layout sxamore_rk_selector={UINT32_C(0x6095001D),"rk_selector",sxamore_rk_selector_fields,SX_COUNT(sxamore_rk_selector_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_subsong_fields[]={
 SX_FIELD("channel0_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("channel1_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("channel2_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("channel3_offset","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxamore_rk_subsong={UINT32_C(0x6095001E),"rk_subsong",sxamore_rk_subsong_fields,SX_COUNT(sxamore_rk_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_position_fields[]={
 SX_FIELD("track_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("unknown4","bytes",4,2,SX_NONE),
 SX_FIELD("transpose","int16",6,2,SX_NONE),
 SX_FIELD("unknown8","bytes",8,2,SX_NONE),
 SX_FIELD("repeat_count","uint16",10,2,SX_COUNT_PROP),
};
static const sx_layout sxamore_rk_position={UINT32_C(0x6095001F),"rk_position",sxamore_rk_position_fields,SX_COUNT(sxamore_rk_position_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_position_end_fields[]={
 SX_FIELD("end_marker","int32",0,4,SX_ID),
};
static const sx_layout sxamore_rk_position_end={UINT32_C(0x60950020),"rk_position_end",sxamore_rk_position_end_fields,SX_COUNT(sxamore_rk_position_end_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_cia_write_fields[]={
 SX_FIELD("opcode","uint16",0,2,SX_ID),
 SX_FIELD("immediate","uint16",2,2,SX_NONE),
 SX_FIELD("register_address","uint32",4,4,SX_ADDRESS),
};
static const sx_layout sxamore_rk_cia_write={UINT32_C(0x60950021),"rk_cia_write",sxamore_rk_cia_write_fields,SX_COUNT(sxamore_rk_cia_write_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_vector_write_fields[]={
 SX_FIELD("opcode","uint16",0,2,SX_ID),
 SX_FIELD("code_relative_offset","uint32",2,4,SX_OFFSET),
 SX_FIELD("vector_address","uint32",6,4,SX_ADDRESS),
};
static const sx_layout sxamore_rk_vector_write={UINT32_C(0x60950022),"rk_vector_write",sxamore_rk_vector_write_fields,SX_COUNT(sxamore_rk_vector_write_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rjp_header_fields[]={
 SX_FIELD("signature","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("module_marker","bytes",4,4,SX_ID),
};
static const sx_layout sxamore_rjp_header={UINT32_C(0x60950023),"rjp_header",sxamore_rjp_header_fields,SX_COUNT(sxamore_rjp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_rjp_section_fields[]={
 SX_FIELD("payload_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxamore_rjp_section={UINT32_C(0x60950024),"rjp_section",sxamore_rjp_section_fields,SX_COUNT(sxamore_rjp_section_fields),SX_BE};
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
static const sx_layout sxamore_rjp_sample={UINT32_C(0x60950025),"rjp_sample",sxamore_rjp_sample_fields,SX_COUNT(sxamore_rjp_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rjp_subsong_fields[]={
 SX_FIELD("channel0","uint8",0,1,SX_ID),
 SX_FIELD("channel1","uint8",1,1,SX_ID),
 SX_FIELD("channel2","uint8",2,1,SX_ID),
 SX_FIELD("channel3","uint8",3,1,SX_ID),
};
static const sx_layout sxamore_rjp_subsong={UINT32_C(0x60950026),"rjp_subsong",sxamore_rjp_subsong_fields,SX_COUNT(sxamore_rjp_subsong_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_rjp_position_offset_fields[]={
 SX_FIELD("position_relative_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxamore_rjp_position_offset={UINT32_C(0x60950027),"rjp_position_offset",sxamore_rjp_position_offset_fields,SX_COUNT(sxamore_rjp_position_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rjp_step_offset_fields[]={
 SX_FIELD("step_relative_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxamore_rjp_step_offset={UINT32_C(0x60950028),"rjp_step_offset",sxamore_rjp_step_offset_fields,SX_COUNT(sxamore_rjp_step_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxamore_rk_index_extension_fields[]={
 SX_FIELD("index_control","uint8",0,1,SX_FLAGS),
 SX_FIELD("global_relative_displacement","int8",1,1,SX_OFFSET),
};
static const sx_layout sxamore_rk_index_extension={UINT32_C(0x60950029),"rk_index_extension",sxamore_rk_index_extension_fields,SX_COUNT(sxamore_rk_index_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxamore_sun_end_fields[]={
 SX_FIELD("end_marker","uint32",0,4,SX_ID),
};
static const sx_layout sxamore_sun_end={UINT32_C(0x6095002A),"sun_end",sxamore_sun_end_fields,SX_COUNT(sxamore_sun_end_fields),SX_BE};
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
/* Read physical metadata without buffering whole sample or track payloads. */
typedef struct sxamore_view {sx_context*c;unsigned work;}sxamore_view;
static bool sxamore_span(sxamore_view*v,uint64_t at,uint64_t n,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&v->c->size>=0&&end<=(uint64_t)v->c->size&&at<=end&&n<=end-at;}
static bool sxamore_read(sxamore_view*v,uint64_t at,void*p,size_t n,uint64_t end)
{return ++v->work<=4000000&&sxamore_span(v,at,n,end)&&sx_read(v->c,(int64_t)at,p,n);}
static bool sxamore_word(sxamore_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!n||n>8||!sxamore_read(v,at,b,n,end))return false;uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[be?n-i-1:i]<<(8*i);*out=x;return true;}
static bool sxamore_row(sxamore_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxamore_span(v,at,z,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)z);}
#define AM_ROW(l,at,end) sxamore_row(v,&sxamore_##l,(at),(end))
static bool sxamore_table(sxamore_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>4000000||count>UINT64_MAX/z||!sxamore_span(v,at,count*z,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++,at+=z)if(!sxamore_row(v,l,at,end))return false;return true;}
static int sxamore_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxamore_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxamore_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxamore_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxamore_be(sxamore_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxamore_word(v,p,n,true,x,end);}
static bool sxamore_eq(sxamore_view*v,uint64_t p,const char*s,size_t n,uint64_t end){uint8_t b[64];return n<=sizeof(b)&&sxamore_read(v,p,b,n,end)&&!xx_rt_memcmp(b,s,n);}
static bool sxamore_text_emit(sxamore_view*v,uint64_t p,uint64_t n,uint64_t end){if(!sxamore_span(v,p,n,end))return false;return !n||n>4096||v->c->count>=24000||sx_add(v->c,&sxamore_text,(int64_t)p,(int64_t)n);}
static bool sxamore_take(sxamore_view*v,const sx_layout*l,uint64_t*p,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!sxamore_table(v,l,*p,count,end))return false;*p+=count*z;return true;}
static bool sxamore_skip(sxamore_view*v,uint64_t*p,uint64_t n,uint64_t end)
{if(!sxamore_span(v,*p,n,end))return false;*p+=n;return true;}
#define AM_TAKE(l,p,n,end) sxamore_take(v,&sxamore_##l,(p),(n),(end))
static bool sxamore_signed16(sxamore_view*v,uint64_t at,uint64_t base,uint64_t*out,uint64_t end)
{uint64_t u;if(!sxamore_be(v,at,2,&u,end))return false;int64_t d=u<32768?(int64_t)u:(int64_t)u-65536;
 if(d<0){uint64_t n=(uint64_t)(-d);if(base<n)return false;*out=base-n;}else{if(base>end||(uint64_t)d>end-base)return false;*out=base+(uint64_t)d;}return *out<=end;}
static bool sxamore_find(sxamore_view*v,uint64_t*at,uint64_t end,uint64_t pattern,unsigned width,unsigned step)
{if(!step||!width||width>8||*at>end)return false;uint64_t limit=end;if(limit-*at>UINT64_C(1048576))limit=*at+UINT64_C(1048576);for(;*at<=limit&&width<=limit-*at;*at+=step){uint64_t x;if(!sxamore_be(v,*at,width,&x,end))return false;if(x==pattern)return true;}return false;}
static bool sxamore_map(uint64_t address,uint64_t origin,uint64_t end,uint64_t*out)
{if(address<origin||address-origin>end)return false;*out=address-origin;return true;}
/* The format's 23-byte field is a bounded byte string, not assumed UTF-8. */
static bool sxamore_name(sxamore_view*v,uint64_t*p,uint64_t end)
{uint64_t start=*p,x;for(unsigned i=0;i<23;i++){if(!sxamore_be(v,*p,1,&x,end))return false;if(!x){if(!sxamore_text_emit(v,start,*p-start,end)||!AM_TAKE(nul,p,1,end))return false;return true;}++*p;}return sxamore_text_emit(v,start,23,end);}

static bool sxamore_prt(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,version,pos,pat,inst,wave,nins,nwave;
 if(!sxamore_eq(v,0,"PRT",3,e)||!sxamore_be(v,3,1,&version,e)||(version!=25&&version!=27&&version!=30)||!sxamore_be(v,4,4,&pos,e)||!sxamore_be(v,8,4,&pat,e)||!sxamore_be(v,12,4,&inst,e)||!sxamore_be(v,16,4,&wave,e)||!sxamore_be(v,64,1,&nins,e)||!nins||nins>64||!sxamore_be(v,65,1,&nwave,e)||nwave>24 )return false;
 if(!sxamore_row(v,version==30?&sxamore_prt_header30:&sxamore_prt_header,0,e))return false;
 if(version>=27&&!AM_ROW(prt_generation_order,66,e))return false;
 if(pos<66||pat<66||inst<66||wave<66||pos>e||pat>e||inst>e||wave>e)return false;
 if(version==30){
  uint64_t songs;if(!sxamore_be(v,90,1,&songs,e)||!songs||!AM_ROW(prt_subsong_count,90,e))return false;
  for(uint64_t i=0;i<songs;i++){
   uint64_t patterns,rows,positions,rel;
   if(!sxamore_be(v,pos+1,1,&patterns,e)||!sxamore_be(v,pos+2,1,&rows,e)||!sxamore_be(v,pos+3,1,&positions,e)||!sxamore_be(v,pos+4,4,&rel,e)||!patterns||!rows||!positions||rel>e-pat||!AM_TAKE(prt_subsong,&pos,1,e)||!AM_TAKE(prt_position,&pos,positions*4,e)||!sxamore_table(v,&sxamore_prt_pattern,pat+rel,patterns*rows,e))return false;
  }
 }else{
  uint64_t patterns,rows,positions;if(!sxamore_be(v,61,1,&patterns,e)||!patterns||!sxamore_be(v,62,1,&positions,e)||!positions||!sxamore_be(v,63,1,&rows,e)||!rows||!sxamore_table(v,&sxamore_prt_position,pos,positions*4,e)||!sxamore_table(v,&sxamore_prt_pattern,pat,patterns*rows,e))return false;
 }
 uint64_t p=inst;for(unsigned i=0;i<(version==30?64U:32U);i++)if(!sxamore_name(v,&p,e))return false;
 uint64_t info=p;if(!AM_TAKE(prt_instrument,&p,nins,e))return false;
 for(uint64_t i=0;i<nins;i++){uint64_t steps;if(!sxamore_be(v,info+i*8+7,1,&steps,e)||!AM_TAKE(prt_instrument_pattern,&p,steps,e))return false;}
 p=wave;for(unsigned i=0;i<24;i++)if(!sxamore_name(v,&p,e))return false;
 if(p&1){if(p==e)return false;p++;}return AM_TAKE(prt_wave,&p,nwave,e);
}
static bool sxamore_rjp(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,p=8,base[7],size[7];
 if(!sxamore_eq(v,0,"RJP",3,e)||!sxamore_eq(v,4,"SMOD",4,e))return false;
 for(unsigned i=0;i<7;i++){if(!sxamore_be(v,p,4,&size[i],e)||!sxamore_span(v,p+4,size[i],e))return false;base[i]=p+4;p+=4+size[i];}
 if(!AM_ROW(rjp_header,0,e))return false;
 for(unsigned i=0;i<7;i++)if(!AM_ROW(rjp_section,base[i]-4,e))return false;
 if(!sxamore_table(v,&sxamore_rjp_sample,base[0],size[0]/32,base[0]+size[0])||!sxamore_table(v,&sxamore_rjp_subsong,base[2],size[2]/4,base[2]+size[2])||!sxamore_table(v,&sxamore_rjp_position_offset,base[3],size[3]/4,base[3]+size[3])||!sxamore_table(v,&sxamore_rjp_step_offset,base[4],size[4]/4,base[4]+size[4]))return false;
 return true;
}
static bool sxamore_thm(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,origin,n,rows;
 if(!sxamore_be(v,46,4,&origin,e)||!origin||(origin&1)||origin>=UINT64_C(0x80000000)||!sxamore_be(v,35,1,&n,e)||n>31||!sxamore_be(v,41,1,&rows,e))return false;
 for(unsigned i=0;i<8;i++){uint64_t x,want=i<4?64+i*1024:4160+(i-4)*256;if(!sxamore_be(v,i*4,4,&x,e)||x<origin||x-origin!=want)return false;}
 if(!AM_ROW(thm_header,0,e)||!sxamore_table(v,&sxamore_original_address,64,1024,e)||!sxamore_table(v,&sxamore_thm_order,4160,1024,e)||!sxamore_table(v,&sxamore_original_address,5184,32,e)||!sxamore_table(v,&sxamore_thm_sample,5358,n,e))return false;
 return true;
}

static bool sxamore_rk(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,x,words,alloc,p=64,jumps=0,songs=0,irq=0,init=0,targets[2]={0,0};
 if(!sxamore_be(v,0,4,&x,e)||x!=1011||!sxamore_be(v,4,4,&x,e)||x||!sxamore_be(v,8,4,&x,e)||x!=1||!sxamore_be(v,12,4,&x,e)||x||!sxamore_be(v,16,4,&x,e)||x||!sxamore_be(v,20,4,&alloc,e)||!sxamore_be(v,24,4,&x,e)||(x&0x3fffffff)!=1001||!sxamore_be(v,28,4,&words,e)||words<656||words>(alloc&0x3fffffff)||!sxamore_span(v,32,words*4,e)||!sxamore_eq(v,40,"RON_KLAREN_SOUNDMODULE!\0",23,e))return false;
 uint64_t end=32+words*4,scan_end=end<2656?end:2656;
 while(jumps<128&&sxamore_be(v,p,2,&x,scan_end)&&x==0x4ef9){uint64_t off;if(!sxamore_be(v,p+2,4,&off,scan_end)||off>=words*4)return false;if(jumps<2)targets[jumps]=32+off;jumps++;p+=6;}
 if(jumps<2)return false;uint64_t selectors=p;
 while(songs<128&&sxamore_be(v,p,2,&x,scan_end)&&x==0x303c){if(!sxamore_span(v,p,8,scan_end))return false;songs++;p+=8;}
 if(!songs)return false;
 for(unsigned i=0;i<2;i++){if(!sxamore_be(v,targets[i],2,&x,scan_end))return false;if(x==0x6100||x==0x33fc){init=targets[i];break;}}
 uint64_t writes_at[128];unsigned writes_kind[128],nwrites=0;uint64_t cia_lo=0,cia_hi=0;
 if(init){
  p=init;for(unsigned i=0;i<1024;i++,p+=2){if(!sxamore_be(v,p,2,&x,scan_end))return false;if(x==0x4e75)break;
   if(x==0x13fc){uint64_t value,reg;if(!sxamore_be(v,p+2,2,&value,scan_end)||!sxamore_be(v,p+4,4,&reg,scan_end))return false;if(reg==0xbfd400)cia_lo=value&255;if(reg==0xbfd500)cia_hi=value&255;if(nwrites<128){writes_at[nwrites]=p;writes_kind[nwrites++]=0;}p+=6;
   }else if(x==0x23fc){uint64_t off,reg;if(!sxamore_be(v,p+2,4,&off,scan_end)||!sxamore_be(v,p+6,4,&reg,scan_end))return false;if(reg==0x78){if(off>=words*4)return false;irq=32+off;if(nwrites<128){writes_at[nwrites]=p;writes_kind[nwrites++]=1;}}p+=8;}
  }
  if(!irq||!(cia_lo|cia_hi))return false;
 }else{irq=targets[1];if(!sxamore_be(v,irq,2,&x,scan_end)||x!=0x41fa)return false;}
 p=irq;if(!sxamore_find(v,&p,scan_end,0x41fa,2,2))return false;uint64_t global,global_op=p+2;if(!sxamore_signed16(v,p+2,p+2,&global,end))return false;p+=4;
 uint64_t index_op=0;
 for(unsigned i=0;i<1024;i++,p+=2){if(!sxamore_be(v,p,2,&x,scan_end))return false;if(x==0x4e73||x==0x4e75)return false;if(sxamore_eq(v,p,"\x02\x40\x00\x0f\x53\x40\xe9\x48\x47\xf0",10,scan_end)){index_op=p+10;break;}}
 /* This loader's published variant uses D0.w and a nonnegative brief
    displacement. Other index-register/full-extension forms stay raw. */
 if(!index_op||!sxamore_be(v,index_op,2,&x,scan_end)||x>127||global>end||x>end-global)return false;uint64_t table=global+x;
 if(!sxamore_span(v,table,songs*16,end)||!AM_ROW(rk_hunk_header,0,e)||!sxamore_table(v,&sxamore_rk_jump,64,jumps,scan_end)||!sxamore_table(v,&sxamore_rk_selector,selectors,songs,scan_end)||!AM_ROW(signed_displacement,global_op,scan_end)||!AM_ROW(rk_index_extension,index_op,scan_end)||!sxamore_table(v,&sxamore_rk_subsong,table,songs,end))return false;
 for(unsigned i=0;i<nwrites;i++)if(!sxamore_row(v,writes_kind[i]?&sxamore_rk_vector_write:&sxamore_rk_cia_write,writes_at[i],scan_end))return false;
 for(uint64_t i=0;i<songs*4;i++){
  uint64_t off;if(!sxamore_be(v,table+i*4,4,&off,end)||off>words*4)return false;p=32+off;
  for(unsigned j=0;j<4096;j++){
   if(!sxamore_be(v,p,4,&x,end))return false;if(x&UINT64_C(0x80000000)){if(!AM_ROW(rk_position_end,p,end))return false;break;}
   if(x>=words*4||!AM_TAKE(rk_position,&p,1,end))return false;if(j==4095)return false;
  }
 }
 return true;
}

/* The anchors below are the original loaders' operand sequences. Search caps
   bound corrupted cached-valid readers; no code is executed or relocated. */
static bool sxamore_rh(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,p=64,n,operand=54,samples,sub=130,x;
 for(unsigned i=0;i<5;i++)if(!sxamore_be(v,i*4,2,&x,e)||x!=0x6000)return false;
 if(!sxamore_eq(v,20,"\x41\xfa",2,e)||!sxamore_eq(v,28,"\x4e\x75\x41\xfa",4,e)||!sxamore_find(v,&p,e<80?e:80,0x2418,2,2)||!sxamore_be(v,p-1,1,&n,e)||!sxamore_find(v,&operand,e<64?e:64,0x41fa,2,2))return false;
 operand+=2;if(!sxamore_signed16(v,operand,operand,&samples,e)||!sxamore_be(v,operand+2,2,&x,e))return false;if(x==0xd1fc){if(!sxamore_span(v,samples,64,e))return false;samples+=64;}
 if(!sxamore_find(v,&sub,e<150?e:150,0x41eb,2,2))return false;sub+=2;
 uint64_t song;if(!sxamore_signed16(v,sub,0,&song,e)||!sxamore_span(v,song,18,e)||!AM_ROW(rh_sample_count,p-1,e)||!AM_ROW(signed_displacement,operand,e)||!AM_ROW(signed_displacement,sub,e))return false;
 p=samples;for(uint64_t i=0;i<=n;i++){uint64_t bytes;if(!sxamore_be(v,p,4,&bytes,e)||bytes>65536||!AM_TAKE(rh_sample,&p,1,e)||!sxamore_skip(v,&p,bytes,e))return false;}
 if(!sxamore_be(v,p,2,&x,e)||x!=0x4e71||!AM_ROW(end_word,p,e))return false;
 for(unsigned i=0;i<4096;i++,song+=18){if(!AM_ROW(rh_subsong,song,e)||!sxamore_be(v,song+18,2,&x,e))return false;if(!x)return AM_ROW(end_word,song+18,e);}
 return false;
}
static bool sxamore_sun(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,x,base,p=0,a,b,c,operands[4];
 if(!sxamore_eq(v,0,"\x48\xe7\xff\xfe\x4d\xfa",6,e)||!sxamore_be(v,8,4,&x,e)||(x!=0x4a2e0018&&x!=0x4a2e0010)||!sxamore_signed16(v,6,6,&base,e)||base<14)return false;
 bool four_channels=x==0x4a2e0018;uint64_t bound=base<e?base:e;
 if(!sxamore_find(v,&p,bound,0x43ee,2,2))return false;operands[0]=p+2;
 if(!sxamore_signed16(v,p+2,base,&a,e)||!sxamore_span(v,a,four_channels?20:4,e))return false;
 p=0;for(unsigned i=1;i<4;i++){if(!sxamore_find(v,&p,bound,0x45ee,2,2))return false;operands[i]=p+2;p+=2;}
 if(!sxamore_signed16(v,operands[2],base,&b,e)||!sxamore_signed16(v,operands[3],base,&c,e)||b>c)return false;
 if(!AM_ROW(signed_displacement,6,e))return false;
 if(four_channels){if(!AM_ROW(sun_initial_channels,a,e))return false;}
 else{bool done=false;for(unsigned i=0;i<4096;i++,a+=4){if(!sxamore_be(v,a,4,&x,e))return false;if(!x){if(!AM_ROW(sun_end,a,e))return false;done=true;break;}if(!AM_ROW(original_address,a,e))return false;}if(!done)return false;}
 for(unsigned i=0;i<4;i++)if(!AM_ROW(signed_displacement,operands[i],e))return false;
 /* b..c mixes original pointers with control words in the two dialects.
    Their physical extent remains raw instead of pretending it is a u32 array. */
 return true;
}
static bool sxamore_wb(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,p=0,after,address,origin,n,table,operands[3];
 if(!sxamore_eq(v,0,"\x60\x00",2,e)||!sxamore_eq(v,4,"\x48\xe7\xff\xfe\x61\x00\x00",7,e)||!sxamore_eq(v,12,"\x4c\xdf\x7f\xff\x4e\x75",6,e)||!sxamore_find(v,&p,e,0x4e75,2,2))return false;after=p+2;
 if(!sxamore_find(v,&p,e,0x1039,2,2))return false;p+=2;operands[0]=p;if(!sxamore_be(v,p,4,&address,e)||address<after)return false;origin=address-after;
 p+=4;if(!sxamore_find(v,&p,e,0x223c,2,2))return false;p+=2;operands[1]=p;if(!sxamore_be(v,p,4,&n,e)||n<2||n>4097)return false;n--;
 p+=4;if(!sxamore_find(v,&p,e,0x41f9,2,2))return false;p+=2;operands[2]=p;if(!sxamore_be(v,p,4,&address,e)||!sxamore_map(address,origin,e,&table)||!sxamore_span(v,table,n*16,e))return false;
 uint64_t minimum=e;for(uint64_t j=0;j<n*4;j++){uint64_t target;if(!sxamore_be(v,table+j*4,4,&address,e)||!sxamore_map(address,origin,e,&target))return false;if(target<minimum)minimum=target;}
 uint64_t end=table+n*16;if(minimum<end||(minimum-end)%4)return false;
 if(!AM_ROW(original_address,operands[0],e)||!AM_ROW(wb_count,operands[1],e)||!AM_ROW(original_address,operands[2],e)||!sxamore_table(v,&sxamore_wb_subsong,table,n,e)||!sxamore_table(v,&sxamore_original_address,end,(minimum-end)/4,e))return false;
 return true;
}
static bool sxamore_jt(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,p=0,period_address,period_at,origin,op[5],info_table,subsong,address;
 if(!sxamore_find(v,&p,e,UINT64_C(0x1400e302),4,2)||!sxamore_be(v,p+6,4,&period_address,e))return false;op[0]=p+6;
 if(!sxamore_find(v,&p,e,UINT64_C(0x03580328),4,2)||period_address<p)return false;period_at=p;origin=period_address-period_at;
 p=0;uint64_t a=0,b=0;bool aa=sxamore_find(v,&a,e,UINT64_C(0xb23c00ff),4,2),bb=sxamore_find(v,&b,e,UINT64_C(0x0c0100ff),4,2);if(!aa&&!bb)return false;p=aa&&(!bb||a<b)?a:b;
 if(!sxamore_find(v,&p,e,0x267c,2,2))return false;op[1]=p+2;p+=6;
 if(!sxamore_find(v,&p,e,0x49f9,2,2))return false;op[2]=p+2;if(!sxamore_be(v,p+2,4,&address,e)||!sxamore_map(address,origin,e,&info_table))return false;p+=6;
 if(!sxamore_find(v,&p,e,UINT64_C(0x0026267c),4,2))return false;op[3]=p+4;p+=8;
 if(!sxamore_find(v,&p,e,0x23f4,2,2)||p<4)return false;op[4]=p-4;if(!sxamore_be(v,p-4,4,&address,e)||!sxamore_map(address,origin,e,&subsong))return false;
 uint64_t first;if(!sxamore_be(v,info_table,4,&address,e)||!sxamore_map(address,origin,e,&first)||first<=info_table||(first-info_table)%4||(first-info_table)/4>4096)return false;
 for(unsigned i=0;i<5;i++)if(!AM_ROW(original_address,op[i],e))return false;
 bool seen=false;for(unsigned i=0;i<4096;i++,subsong+=18){uint64_t marker,channels[4];if(!sxamore_be(v,subsong+16,1,&marker,e))return false;if(marker!=12)break;for(unsigned j=0;j<4;j++)if(!sxamore_be(v,subsong+j*4,4,&channels[j],e))return false;if(channels[0]==channels[1]&&channels[0]==channels[2]&&channels[0]==channels[3])break;if(!AM_ROW(jt_subsong,subsong,e))return false;seen=true;}
 if(!seen)return false;
 for(uint64_t row=info_table;row<first;row+=4){uint64_t at,length,data;if(!sxamore_be(v,row,4,&address,e)||!sxamore_map(address,origin,e,&at)||!sxamore_be(v,at+2,2,&length,e)||!sxamore_be(v,at+4,4,&address,e)||!AM_ROW(original_address,row,e)||!AM_ROW(jt_sample,at,e))return false;if(address&&(!sxamore_map(address,origin,e,&data)||!sxamore_span(v,data,length*2,e)))return false;}
 return true;
}

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
case XX_FILE_TYPE_DIE_MUSIC_PINK_PRETRACKER_PRT:ok=sxamore_prt(v);break;
case XX_FILE_TYPE_DIE_MUSIC_RICHARDJOSEPH_RJP_SNG:ok=sxamore_rjp(v);break;
case XX_FILE_TYPE_DIE_MUSIC_THOMASHERMANN_THM:ok=sxamore_thm(v);break;
case XX_FILE_TYPE_DIE_MUSIC_RONKLAREN_RK:ok=sxamore_rk(v);break;
case XX_FILE_TYPE_DIE_MUSIC_ROBHUBBARD_RH:ok=sxamore_rh(v);break;
case XX_FILE_TYPE_DIE_MUSIC_SCHMIDT_SUNTRONIC:ok=sxamore_sun(v);break;
case XX_FILE_TYPE_DIE_MUSIC_WALLYBEBEN:ok=sxamore_wb(v);break;
case XX_FILE_TYPE_DIE_MUSIC_JEROENTEL:ok=sxamore_jt(v);break;
default:break;}return ok&&sxamore_finish(c); }
#undef AM_ROW
#undef AM_TAKE
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
