/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical music header and table metadata; compressed and unknown bodies stay raw. */
static const xx_data_struct_field_desc sxamip_text_fields[]={
 SX_FIELD("text","char",0,0,SX_NONE),
};
static const sx_layout sxamip_text={UINT32_C(0x60900001),"text",sxamip_text_fields,SX_COUNT(sxamip_text_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_count16_fields[]={
 SX_FIELD("count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxamip_count16={UINT32_C(0x60900002),"count16",sxamip_count16_fields,SX_COUNT(sxamip_count16_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_count32_fields[]={
 SX_FIELD("count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxamip_count32={UINT32_C(0x60900003),"count32",sxamip_count32_fields,SX_COUNT(sxamip_count32_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_relative32_fields[]={
 SX_FIELD("relative_offset","int32",0,4,SX_OFFSET),
};
static const sx_layout sxamip_relative32={UINT32_C(0x60900004),"relative32",sxamip_relative32_fields,SX_COUNT(sxamip_relative32_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_word_length_fields[]={
 SX_FIELD("length_words","uint16",0,2,SX_NONE),
};
static const sx_layout sxamip_word_length={UINT32_C(0x60900005),"word_length",sxamip_word_length_fields,SX_COUNT(sxamip_word_length_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_amc_header_fields[]={
 SX_FIELD("signature","bytes",0,16,SX_SIGNATURE),
 SX_FIELD("unknown0","bytes",16,4,SX_NONE),
 SX_FIELD("song_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("sample_table_end","uint32",24,4,SX_OFFSET),
 SX_FIELD("section1_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("section2_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("section3_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("section4_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("section5_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("section6_offset","uint32",48,4,SX_OFFSET),
 SX_FIELD("section7_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("unknown1","uint8",56,1,SX_NONE),
 SX_FIELD("player_timing","uint8",57,1,SX_NONE),
 SX_FIELD("unknown_tail","bytes",58,14,SX_NONE),
};
static const sx_layout sxamip_amc_header={UINT32_C(0x60900006),"amc_header",sxamip_amc_header_fields,SX_COUNT(sxamip_amc_header_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_amc_sample_fields[]={
 SX_FIELD("sample_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("length_words","uint16",4,2,SX_NONE),
 SX_FIELD("unknown","bytes",6,10,SX_NONE),
};
static const sx_layout sxamip_amc_sample={UINT32_C(0x60900007),"amc_sample",sxamip_amc_sample_fields,SX_COUNT(sxamip_amc_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_mxtx_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("tempo","uint16",4,2,SX_NONE),
 SX_FIELD("flags","uint16",6,2,SX_FLAGS),
};
static const sx_layout sxamip_mxtx_header={UINT32_C(0x60900008),"mxtx_header",sxamip_mxtx_header_fields,SX_COUNT(sxamip_mxtx_header_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_mxtx_event_fields[]={
 SX_FIELD("command","uint8",0,1,SX_ID),
 SX_FIELD("data","uint8",1,1,SX_NONE),
 SX_FIELD("start_time","uint16",2,2,SX_NONE),
 SX_FIELD("stop_time_or_value","uint16",4,2,SX_NONE),
};
static const sx_layout sxamip_mxtx_event={UINT32_C(0x60900009),"mxtx_event",sxamip_mxtx_event_fields,SX_COUNT(sxamip_mxtx_event_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_mxtx_sample_fields[]={
 SX_FIELD("sample_number","uint16",0,2,SX_ID),
 SX_FIELD("tune","int16",2,2,SX_NONE),
 SX_FIELD("volume","uint16",4,2,SX_NONE),
 SX_FIELD("octaves","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("attack_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("sustain_bytes","uint32",12,4,SX_SIZE),
 SX_FIELD("attack_segments","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("release_segments","uint16",18,2,SX_COUNT_PROP),
};
static const sx_layout sxamip_mxtx_sample={UINT32_C(0x6090000A),"mxtx_sample",sxamip_mxtx_sample_fields,SX_COUNT(sxamip_mxtx_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_mxtx_envelope_fields[]={
 SX_FIELD("duration_ms","uint16",0,2,SX_NONE),
 SX_FIELD("volume","uint16",2,2,SX_NONE),
};
static const sx_layout sxamip_mxtx_envelope={UINT32_C(0x6090000B),"mxtx_envelope",sxamip_mxtx_envelope_fields,SX_COUNT(sxamip_mxtx_envelope_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_omf_identity_fields[]={
 SX_FIELD("signature","char[15]",0,15,SX_SIGNATURE),
 SX_FIELD("eof_marker","uint8",15,1,SX_ID),
 SX_FIELD("zero","uint8",16,1,SX_NONE),
 SX_FIELD("version","uint8",17,1,SX_ID),
};
static const sx_layout sxamip_omf_identity={UINT32_C(0x6090000C),"omf_identity",sxamip_omf_identity_fields,SX_COUNT(sxamip_omf_identity_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_omf_position_fields[]={
 SX_FIELD("encoded_pattern_number","uint16",0,2,SX_NONE),
};
static const sx_layout sxamip_omf_position={UINT32_C(0x6090000D),"omf_position",sxamip_omf_position_fields,SX_COUNT(sxamip_omf_position_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_omf_header_tail_fields[]={
 SX_FIELD("channels_minus_one","uint8",0,1,SX_NONE),
 SX_FIELD("patterns_minus_one","uint8",1,1,SX_NONE),
 SX_FIELD("positions_minus_one_times_two","uint8",2,1,SX_NONE),
 SX_FIELD("title","char[31]",3,31,SX_NONE),
};
static const sx_layout sxamip_omf_header_tail={UINT32_C(0x6090000E),"omf_header_tail",sxamip_omf_header_tail_fields,SX_COUNT(sxamip_omf_header_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_omf_sample_fields[]={
 SX_FIELD("name","char[21]",0,21,SX_NONE),
 SX_FIELD("volume","uint8",21,1,SX_NONE),
 SX_FIELD("finetune_encoded","int16",22,2,SX_NONE),
 SX_FIELD("sample_bytes","uint16",24,2,SX_SIZE),
 SX_FIELD("repeat_bytes","uint16",26,2,SX_SIZE),
};
static const sx_layout sxamip_omf_sample={UINT32_C(0x6090000F),"omf_sample",sxamip_omf_sample_fields,SX_COUNT(sxamip_omf_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_omf_unknown_fields[]={
 SX_FIELD("unknown","uint16",0,2,SX_NONE),
};
static const sx_layout sxamip_omf_unknown={UINT32_C(0x60900010),"omf_unknown",sxamip_omf_unknown_fields,SX_COUNT(sxamip_omf_unknown_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_omf_pattern_fields[]={
 SX_FIELD("zero","uint16",0,2,SX_NONE),
 SX_FIELD("channels","uint8",2,1,SX_COUNT_PROP),
};
static const sx_layout sxamip_omf_pattern={UINT32_C(0x60900011),"omf_pattern",sxamip_omf_pattern_fields,SX_COUNT(sxamip_omf_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_omf_event_fields[]={
 SX_FIELD("period_low","uint8",0,1,SX_NONE),
 SX_FIELD("period_high_and_effect","uint8",1,1,SX_FLAGS),
 SX_FIELD("sample","uint8",2,1,SX_ID),
 SX_FIELD("effect_argument","uint8",3,1,SX_NONE),
};
static const sx_layout sxamip_omf_event={UINT32_C(0x60900012),"omf_event",sxamip_omf_event_fields,SX_COUNT(sxamip_omf_event_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_omf_sample_data_fields[]={
 SX_FIELD("marker","uint8",0,1,SX_ID),
 SX_FIELD("sample_bytes","uint16",1,2,SX_SIZE),
};
static const sx_layout sxamip_omf_sample_data={UINT32_C(0x60900013),"omf_sample_data",sxamip_omf_sample_data_fields,SX_COUNT(sxamip_omf_sample_data_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_plx_header_fields[]={
 SX_FIELD("signature","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("type","uint8",3,1,SX_ID),
 SX_FIELD("speed_scale","uint8",4,1,SX_NONE),
 SX_FIELD("speed","uint16",5,2,SX_NONE),
 SX_FIELD("channel0_offset","uint16",7,2,SX_OFFSET),
 SX_FIELD("channel1_offset","uint16",9,2,SX_OFFSET),
 SX_FIELD("channel2_offset","uint16",11,2,SX_OFFSET),
 SX_FIELD("channel3_offset","uint16",13,2,SX_OFFSET),
 SX_FIELD("channel4_offset","uint16",15,2,SX_OFFSET),
 SX_FIELD("channel5_offset","uint16",17,2,SX_OFFSET),
 SX_FIELD("channel6_offset","uint16",19,2,SX_OFFSET),
 SX_FIELD("channel7_offset","uint16",21,2,SX_OFFSET),
 SX_FIELD("channel8_offset","uint16",23,2,SX_OFFSET),
};
static const sx_layout sxamip_plx_header={UINT32_C(0x60900014),"plx_header",sxamip_plx_header_fields,SX_COUNT(sxamip_plx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_plx_control_fields[]={
 SX_FIELD("fields_present","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxamip_plx_control={UINT32_C(0x60900015),"plx_control",sxamip_plx_control_fields,SX_COUNT(sxamip_plx_control_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_plx_instrument_offset_fields[]={
 SX_FIELD("instrument_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxamip_plx_instrument_offset={UINT32_C(0x60900016),"plx_instrument_offset",sxamip_plx_instrument_offset_fields,SX_COUNT(sxamip_plx_instrument_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_plx_volume_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
};
static const sx_layout sxamip_plx_volume={UINT32_C(0x60900017),"plx_volume",sxamip_plx_volume_fields,SX_COUNT(sxamip_plx_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_plx_note_fields[]={
 SX_FIELD("note_times_two","uint8",0,1,SX_NONE),
};
static const sx_layout sxamip_plx_note={UINT32_C(0x60900018),"plx_note",sxamip_plx_note_fields,SX_COUNT(sxamip_plx_note_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_plx_frequency_fields[]={
 SX_FIELD("opl_frequency_word","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxamip_plx_frequency={UINT32_C(0x60900019),"plx_frequency",sxamip_plx_frequency_fields,SX_COUNT(sxamip_plx_frequency_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_plx_speed_fields[]={
 SX_FIELD("speed","uint16",0,2,SX_NONE),
};
static const sx_layout sxamip_plx_speed={UINT32_C(0x6090001A),"plx_speed",sxamip_plx_speed_fields,SX_COUNT(sxamip_plx_speed_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_plx_delay_fields[]={
 SX_FIELD("delay","uint8",0,1,SX_NONE),
};
static const sx_layout sxamip_plx_delay={UINT32_C(0x6090001B),"plx_delay",sxamip_plx_delay_fields,SX_COUNT(sxamip_plx_delay_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_plx_instrument_fields[]={
 SX_FIELD("unknown","uint8",0,1,SX_NONE),
 SX_FIELD("feedback_algorithm","uint8",1,1,SX_FLAGS),
 SX_FIELD("modulator_20","uint8",2,1,SX_FLAGS),
 SX_FIELD("modulator_40","uint8",3,1,SX_FLAGS),
 SX_FIELD("modulator_60","uint8",4,1,SX_FLAGS),
 SX_FIELD("modulator_80","uint8",5,1,SX_FLAGS),
 SX_FIELD("modulator_e0","uint8",6,1,SX_FLAGS),
 SX_FIELD("carrier_23","uint8",7,1,SX_FLAGS),
 SX_FIELD("carrier_43","uint8",8,1,SX_FLAGS),
 SX_FIELD("carrier_63","uint8",9,1,SX_FLAGS),
 SX_FIELD("carrier_83","uint8",10,1,SX_FLAGS),
 SX_FIELD("carrier_e3","uint8",11,1,SX_FLAGS),
};
static const sx_layout sxamip_plx_instrument={UINT32_C(0x6090001C),"plx_instrument",sxamip_plx_instrument_fields,SX_COUNT(sxamip_plx_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_mso_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("song_table_relative_offset","int32",4,4,SX_OFFSET),
 SX_FIELD("block1_relative_offset","int32",8,4,SX_OFFSET),
 SX_FIELD("block2_relative_offset","int32",12,4,SX_OFFSET),
 SX_FIELD("block3_relative_offset","int32",16,4,SX_OFFSET),
};
static const sx_layout sxamip_mso_header={UINT32_C(0x6090001D),"mso_header",sxamip_mso_header_fields,SX_COUNT(sxamip_mso_header_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_ea_header_fields[]={
 SX_FIELD("pattern_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("position_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("instrument_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("sample_info_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("waveform0_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("waveform1_offset","uint32",20,4,SX_OFFSET),
};
static const sx_layout sxamip_ea_header={UINT32_C(0x6090001E),"ea_header",sxamip_ea_header_fields,SX_COUNT(sxamip_ea_header_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_ea_pattern_fields[]={
 SX_FIELD("channel0_note","uint8",0,1,SX_NONE),
 SX_FIELD("channel0_instrument","uint8",1,1,SX_ID),
 SX_FIELD("channel1_note","uint8",2,1,SX_NONE),
 SX_FIELD("channel1_instrument","uint8",3,1,SX_ID),
 SX_FIELD("channel2_note","uint8",4,1,SX_NONE),
 SX_FIELD("channel2_instrument","uint8",5,1,SX_ID),
 SX_FIELD("channel3_note","uint8",6,1,SX_NONE),
 SX_FIELD("channel3_instrument","uint8",7,1,SX_ID),
};
static const sx_layout sxamip_ea_pattern={UINT32_C(0x6090001F),"ea_pattern",sxamip_ea_pattern_fields,SX_COUNT(sxamip_ea_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_ea_position_fields[]={
 SX_FIELD("first_pattern_or_end","uint16",0,2,SX_NONE),
 SX_FIELD("last_pattern_and_speed","uint16",2,2,SX_FLAGS),
};
static const sx_layout sxamip_ea_position={UINT32_C(0x60900020),"ea_position",sxamip_ea_position_fields,SX_COUNT(sxamip_ea_position_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_ea_sample_fields[]={
 SX_FIELD("sample_offset_dwords","uint16",0,2,SX_NONE),
 SX_FIELD("length_words","uint16",2,2,SX_NONE),
};
static const sx_layout sxamip_ea_sample={UINT32_C(0x60900021),"ea_sample",sxamip_ea_sample_fields,SX_COUNT(sxamip_ea_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_ea_instrument_fields[]={
 SX_FIELD("sample_and_control","uint8",0,1,SX_FLAGS),
 SX_FIELD("retrigger_delay","uint8",1,1,SX_NONE),
 SX_FIELD("waveform0_and_control","uint8",2,1,SX_FLAGS),
 SX_FIELD("waveform1_and_control","uint8",3,1,SX_FLAGS),
 SX_FIELD("control4","uint16",4,2,SX_NONE),
 SX_FIELD("control6","uint16",6,2,SX_NONE),
 SX_FIELD("unknown8","uint8",8,1,SX_NONE),
 SX_FIELD("volume","uint8",9,1,SX_NONE),
 SX_FIELD("fine_tune","int8",10,1,SX_NONE),
 SX_FIELD("unknown_tail","bytes",11,5,SX_NONE),
};
static const sx_layout sxamip_ea_instrument={UINT32_C(0x60900022),"ea_instrument",sxamip_ea_instrument_fields,SX_COUNT(sxamip_ea_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_ea_magic_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
};
static const sx_layout sxamip_ea_magic={UINT32_C(0x60900023),"ea_magic",sxamip_ea_magic_fields,SX_COUNT(sxamip_ea_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_hunk_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("resident_names_end","uint32",4,4,SX_ID),
 SX_FIELD("table_entries","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("first_hunk","uint32",12,4,SX_ID),
 SX_FIELD("last_hunk","uint32",16,4,SX_ID),
 SX_FIELD("allocation_words_and_flags","uint32",20,4,SX_FLAGS),
 SX_FIELD("code_hunk","uint32",24,4,SX_ID),
 SX_FIELD("code_words","uint32",28,4,SX_COUNT_PROP),
};
static const sx_layout sxamip_hunk_header={UINT32_C(0x60900024),"hunk_header",sxamip_hunk_header_fields,SX_COUNT(sxamip_hunk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_hunk_reloc_header_fields[]={
 SX_FIELD("relocation_hunk","uint32",0,4,SX_ID),
};
static const sx_layout sxamip_hunk_reloc_header={UINT32_C(0x60900025),"hunk_reloc_header",sxamip_hunk_reloc_header_fields,SX_COUNT(sxamip_hunk_reloc_header_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_hunk_reloc_block_fields[]={
 SX_FIELD("relocation_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("target_hunk","uint32",4,4,SX_ID),
};
static const sx_layout sxamip_hunk_reloc_block={UINT32_C(0x60900026),"hunk_reloc_block",sxamip_hunk_reloc_block_fields,SX_COUNT(sxamip_hunk_reloc_block_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_hunk_reloc_offset_fields[]={
 SX_FIELD("source_hunk_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxamip_hunk_reloc_offset={UINT32_C(0x60900027),"hunk_reloc_offset",sxamip_hunk_reloc_offset_fields,SX_COUNT(sxamip_hunk_reloc_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_hunk_zero_fields[]={
 SX_FIELD("relocation_end","uint32",0,4,SX_ID),
};
static const sx_layout sxamip_hunk_zero={UINT32_C(0x60900028),"hunk_zero",sxamip_hunk_zero_fields,SX_COUNT(sxamip_hunk_zero_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_hunk_end_fields[]={
 SX_FIELD("end_hunk","uint32",0,4,SX_ID),
};
static const sx_layout sxamip_hunk_end={UINT32_C(0x60900029),"hunk_end",sxamip_hunk_end_fields,SX_COUNT(sxamip_hunk_end_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_core_prefix_fields[]={
 SX_FIELD("entry_code","bytes",0,4,SX_NONE),
 SX_FIELD("identity","bytes",4,8,SX_SIGNATURE),
 SX_FIELD("play_pointer","uint32",12,4,SX_POINTER),
 SX_FIELD("interrupt_pointer","uint32",16,4,SX_POINTER),
 SX_FIELD("init_pointer","uint32",20,4,SX_POINTER),
 SX_FIELD("end_pointer","uint32",24,4,SX_POINTER),
 SX_FIELD("subsong_count","uint32",28,4,SX_COUNT_PROP),
 SX_FIELD("sample_info_pointer","uint32",32,4,SX_POINTER),
 SX_FIELD("sample_info_end_pointer","uint32",36,4,SX_POINTER),
 SX_FIELD("song_name_pointer","uint32",40,4,SX_POINTER),
 SX_FIELD("author_name_pointer","uint32",44,4,SX_POINTER),
 SX_FIELD("information_pointer","uint32",48,4,SX_POINTER),
 SX_FIELD("load_bytes","uint32",52,4,SX_SIZE),
 SX_FIELD("calculated_bytes","uint32",56,4,SX_SIZE),
 SX_FIELD("sample_bytes","uint32",60,4,SX_SIZE),
 SX_FIELD("song_bytes","uint32",64,4,SX_SIZE),
};
static const sx_layout sxamip_core_prefix={UINT32_C(0x6090002A),"core_prefix",sxamip_core_prefix_fields,SX_COUNT(sxamip_core_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_core_sample_fields[]={
 SX_FIELD("unknown_prefix","bytes",0,6,SX_NONE),
 SX_FIELD("sample_length_pointer","uint32",6,4,SX_POINTER),
 SX_FIELD("unknown_tail","bytes",10,4,SX_NONE),
};
static const sx_layout sxamip_core_sample={UINT32_C(0x6090002B),"core_sample",sxamip_core_sample_fields,SX_COUNT(sxamip_core_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_future_prefix_fields[]={
 SX_FIELD("entry_code","bytes",0,4,SX_NONE),
 SX_FIELD("identity","bytes",4,8,SX_SIGNATURE),
 SX_FIELD("song_name_pointer","uint32",12,4,SX_POINTER),
 SX_FIELD("author_name_pointer","uint32",16,4,SX_POINTER),
 SX_FIELD("information_pointer","uint32",20,4,SX_POINTER),
 SX_FIELD("unknown","uint32",24,4,SX_NONE),
 SX_FIELD("calculated_bytes","uint32",28,4,SX_SIZE),
};
static const sx_layout sxamip_future_prefix={UINT32_C(0x6090002C),"future_prefix",sxamip_future_prefix_fields,SX_COUNT(sxamip_future_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_future_subsong_fields[]={
 SX_FIELD("song_pointer","uint32",0,4,SX_POINTER),
 SX_FIELD("parameter0","uint16",4,2,SX_NONE),
 SX_FIELD("parameter1","uint16",6,2,SX_NONE),
};
static const sx_layout sxamip_future_subsong={UINT32_C(0x6090002D),"future_subsong",sxamip_future_subsong_fields,SX_COUNT(sxamip_future_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_future_end_fields[]={
 SX_FIELD("song_pointer","uint32",0,4,SX_POINTER),
};
static const sx_layout sxamip_future_end={UINT32_C(0x6090002E),"future_end",sxamip_future_end_fields,SX_COUNT(sxamip_future_end_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_future_song_voices_fields[]={
 SX_FIELD("voice0_pointer","uint32",0,4,SX_POINTER),
 SX_FIELD("voice1_pointer","uint32",4,4,SX_POINTER),
 SX_FIELD("voice2_pointer","uint32",8,4,SX_POINTER),
 SX_FIELD("voice3_pointer","uint32",12,4,SX_POINTER),
};
static const sx_layout sxamip_future_song_voices={UINT32_C(0x6090002F),"future_song_voices",sxamip_future_song_voices_fields,SX_COUNT(sxamip_future_song_voices_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_jmf_prefix_fields[]={
 SX_FIELD("entry_code","bytes",0,4,SX_NONE),
 SX_FIELD("identity","bytes",4,8,SX_SIGNATURE),
 SX_FIELD("interrupt_pointer","uint32",12,4,SX_POINTER),
 SX_FIELD("init_pointer","uint32",16,4,SX_POINTER),
 SX_FIELD("subsong_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("synth_sample_count","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("song_name_pointer","uint32",28,4,SX_POINTER),
 SX_FIELD("author_name_pointer","uint32",32,4,SX_POINTER),
 SX_FIELD("information_pointer","uint32",36,4,SX_POINTER),
 SX_FIELD("load_bytes","uint32",40,4,SX_SIZE),
 SX_FIELD("calculated_bytes","uint32",44,4,SX_SIZE),
};
static const sx_layout sxamip_jmf_prefix={UINT32_C(0x60900030),"jmf_prefix",sxamip_jmf_prefix_fields,SX_COUNT(sxamip_jmf_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_daglish_prefix_fields[]={
 SX_FIELD("entry_code","bytes",0,4,SX_NONE),
 SX_FIELD("identity","bytes",4,8,SX_SIGNATURE),
 SX_FIELD("play_pointer","uint32",12,4,SX_POINTER),
 SX_FIELD("interrupt_pointer","uint32",16,4,SX_POINTER),
 SX_FIELD("init_pointer","uint32",20,4,SX_POINTER),
 SX_FIELD("subsong_count","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("song_name_pointer","uint32",28,4,SX_POINTER),
 SX_FIELD("author_name_pointer","uint32",32,4,SX_POINTER),
 SX_FIELD("information_pointer","uint32",36,4,SX_POINTER),
 SX_FIELD("load_bytes","uint32",40,4,SX_SIZE),
 SX_FIELD("calculated_bytes","uint32",44,4,SX_SIZE),
 SX_FIELD("sample_bytes","uint32",48,4,SX_SIZE),
 SX_FIELD("song_bytes","uint32",52,4,SX_SIZE),
};
static const sx_layout sxamip_daglish_prefix={UINT32_C(0x60900031),"daglish_prefix",sxamip_daglish_prefix_fields,SX_COUNT(sxamip_daglish_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_lowe_prefix_fields[]={
 SX_FIELD("entry_code","bytes",0,4,SX_NONE),
 SX_FIELD("identity","bytes",4,8,SX_SIGNATURE),
 SX_FIELD("init_pointer","uint32",12,4,SX_POINTER),
 SX_FIELD("play_pointer","uint32",16,4,SX_POINTER),
 SX_FIELD("end_pointer","uint32",20,4,SX_POINTER),
 SX_FIELD("subsong_control_pointer","uint32",24,4,SX_POINTER),
 SX_FIELD("sample_info_pointer","uint32",28,4,SX_POINTER),
 SX_FIELD("sample_info_end_pointer","uint32",32,4,SX_POINTER),
 SX_FIELD("init2_pointer","uint32",36,4,SX_POINTER),
 SX_FIELD("init_player_pointer","uint32",40,4,SX_POINTER),
 SX_FIELD("first_subsong_pointer","uint32",44,4,SX_POINTER),
 SX_FIELD("song_name_pointer","uint32",48,4,SX_POINTER),
 SX_FIELD("author_name_pointer","uint32",52,4,SX_POINTER),
 SX_FIELD("information_pointer","uint32",56,4,SX_POINTER),
 SX_FIELD("load_bytes","uint32",60,4,SX_SIZE),
 SX_FIELD("calculated_bytes","uint32",64,4,SX_SIZE),
 SX_FIELD("sample_bytes","uint32",68,4,SX_SIZE),
 SX_FIELD("song_bytes","uint32",72,4,SX_SIZE),
 SX_FIELD("special_fx_number","uint32",76,4,SX_NONE),
};
static const sx_layout sxamip_lowe_prefix={UINT32_C(0x60900032),"lowe_prefix",sxamip_lowe_prefix_fields,SX_COUNT(sxamip_lowe_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_lowe_sample_fields[]={
 SX_FIELD("unknown_prefix","bytes",0,2,SX_NONE),
 SX_FIELD("sample_pointer","uint32",2,4,SX_POINTER),
 SX_FIELD("length_words","uint16",6,2,SX_NONE),
 SX_FIELD("unknown_tail","bytes",8,6,SX_NONE),
};
static const sx_layout sxamip_lowe_sample={UINT32_C(0x60900033),"lowe_sample",sxamip_lowe_sample_fields,SX_COUNT(sxamip_lowe_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_art_table_operand_fields[]={
 SX_FIELD("table_displacement","int16",0,2,SX_OFFSET),
};
static const sx_layout sxamip_art_table_operand={UINT32_C(0x60900034),"art_table_operand",sxamip_art_table_operand_fields,SX_COUNT(sxamip_art_table_operand_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_art_limit_operand_fields[]={
 SX_FIELD("limit_displacement","int16",0,2,SX_OFFSET),
};
static const sx_layout sxamip_art_limit_operand={UINT32_C(0x60900035),"art_limit_operand",sxamip_art_limit_operand_fields,SX_COUNT(sxamip_art_limit_operand_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_art_relocation_fields[]={
 SX_FIELD("original_address","uint32",0,4,SX_ADDRESS),
};
static const sx_layout sxamip_art_relocation={UINT32_C(0x60900036),"art_relocation",sxamip_art_relocation_fields,SX_COUNT(sxamip_art_relocation_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_art_marker_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
};
static const sx_layout sxamip_art_marker={UINT32_C(0x60900037),"art_marker",sxamip_art_marker_fields,SX_COUNT(sxamip_art_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxamip_turner_address_fields[]={
 SX_FIELD("original_address","uint32",0,4,SX_ADDRESS),
};
static const sx_layout sxamip_turner_address={UINT32_C(0x60900038),"turner_address",sxamip_turner_address_fields,SX_COUNT(sxamip_turner_address_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_turner_subsong_fields[]={
 SX_FIELD("priority_control","uint8",0,1,SX_NONE),
 SX_FIELD("interval_control","uint8",1,1,SX_NONE),
 SX_FIELD("timing_control","uint8",2,1,SX_NONE),
 SX_FIELD("unused3","uint8",3,1,SX_NONE),
 SX_FIELD("channel0_offset","int16",4,2,SX_OFFSET),
 SX_FIELD("channel1_offset","int16",6,2,SX_OFFSET),
 SX_FIELD("channel2_offset","int16",8,2,SX_OFFSET),
 SX_FIELD("channel3_offset","int16",10,2,SX_OFFSET),
};
static const sx_layout sxamip_turner_subsong={UINT32_C(0x60900039),"turner_subsong",sxamip_turner_subsong_fields,SX_COUNT(sxamip_turner_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_turner_sample_table_fields[]={
 SX_FIELD("pointer_count_times_four","uint32",0,4,SX_NONE),
 SX_FIELD("sample_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("unknown","bytes",8,18,SX_NONE),
};
static const sx_layout sxamip_turner_sample_table={UINT32_C(0x6090003A),"turner_sample_table",sxamip_turner_sample_table_fields,SX_COUNT(sxamip_turner_sample_table_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_turner_sample_offset_fields[]={
 SX_FIELD("length_word_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxamip_turner_sample_offset={UINT32_C(0x6090003B),"turner_sample_offset",sxamip_turner_sample_offset_fields,SX_COUNT(sxamip_turner_sample_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_turner_sample_length_fields[]={
 SX_FIELD("stored_length","uint16",0,2,SX_NONE),
};
static const sx_layout sxamip_turner_sample_length={UINT32_C(0x6090003C),"turner_sample_length",sxamip_turner_sample_length_fields,SX_COUNT(sxamip_turner_sample_length_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_cooksey_displacement_fields[]={
 SX_FIELD("pc_relative_displacement","int16",0,2,SX_OFFSET),
};
static const sx_layout sxamip_cooksey_displacement={UINT32_C(0x6090003D),"cooksey_displacement",sxamip_cooksey_displacement_fields,SX_COUNT(sxamip_cooksey_displacement_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_cooksey_sample_offset_fields[]={
 SX_FIELD("entry_relative_offset","int16",0,2,SX_OFFSET),
};
static const sx_layout sxamip_cooksey_sample_offset={UINT32_C(0x6090003E),"cooksey_sample_offset",sxamip_cooksey_sample_offset_fields,SX_COUNT(sxamip_cooksey_sample_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_cooksey_sample_fields[]={
 SX_FIELD("sample_data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("unknown","bytes",4,12,SX_NONE),
 SX_FIELD("length_words","uint16",16,2,SX_NONE),
};
static const sx_layout sxamip_cooksey_sample={UINT32_C(0x6090003F),"cooksey_sample",sxamip_cooksey_sample_fields,SX_COUNT(sxamip_cooksey_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxamip_cooksey_shifted_sample_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_ID),
 SX_FIELD("unknown","uint16",2,2,SX_NONE),
 SX_FIELD("sample_data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("unknown_tail","bytes",8,10,SX_NONE),
 SX_FIELD("length_words","uint16",18,2,SX_NONE),
};
static const sx_layout sxamip_cooksey_shifted_sample={UINT32_C(0x60900040),"cooksey_shifted_sample",sxamip_cooksey_shifted_sample_fields,SX_COUNT(sxamip_cooksey_shifted_sample_fields),SX_BE};
static const sx_layout *const sx_amigaplayers_layouts[]={
 &sxamip_text,
 &sxamip_count16,
 &sxamip_count32,
 &sxamip_relative32,
 &sxamip_word_length,
 &sxamip_amc_header,
 &sxamip_amc_sample,
 &sxamip_mxtx_header,
 &sxamip_mxtx_event,
 &sxamip_mxtx_sample,
 &sxamip_mxtx_envelope,
 &sxamip_omf_identity,
 &sxamip_omf_position,
 &sxamip_omf_header_tail,
 &sxamip_omf_sample,
 &sxamip_omf_unknown,
 &sxamip_omf_pattern,
 &sxamip_omf_event,
 &sxamip_omf_sample_data,
 &sxamip_plx_header,
 &sxamip_plx_control,
 &sxamip_plx_instrument_offset,
 &sxamip_plx_volume,
 &sxamip_plx_note,
 &sxamip_plx_frequency,
 &sxamip_plx_speed,
 &sxamip_plx_delay,
 &sxamip_plx_instrument,
 &sxamip_mso_header,
 &sxamip_ea_header,
 &sxamip_ea_pattern,
 &sxamip_ea_position,
 &sxamip_ea_sample,
 &sxamip_ea_instrument,
 &sxamip_ea_magic,
 &sxamip_hunk_header,
 &sxamip_hunk_reloc_header,
 &sxamip_hunk_reloc_block,
 &sxamip_hunk_reloc_offset,
 &sxamip_hunk_zero,
 &sxamip_hunk_end,
 &sxamip_core_prefix,
 &sxamip_core_sample,
 &sxamip_future_prefix,
 &sxamip_future_subsong,
 &sxamip_future_end,
 &sxamip_future_song_voices,
 &sxamip_jmf_prefix,
 &sxamip_daglish_prefix,
 &sxamip_lowe_prefix,
 &sxamip_lowe_sample,
 &sxamip_art_table_operand,
 &sxamip_art_limit_operand,
 &sxamip_art_relocation,
 &sxamip_art_marker,
 &sxamip_turner_address,
 &sxamip_turner_subsong,
 &sxamip_turner_sample_table,
 &sxamip_turner_sample_offset,
 &sxamip_turner_sample_length,
 &sxamip_cooksey_displacement,
 &sxamip_cooksey_sample_offset,
 &sxamip_cooksey_sample,
 &sxamip_cooksey_shifted_sample,
};
/* Read physical metadata without buffering whole sample or track payloads. */
typedef struct sxamip_view {sx_context*c;unsigned work;}sxamip_view;
static bool sxamip_span(sxamip_view*v,uint64_t at,uint64_t n,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&v->c->size>=0&&end<=(uint64_t)v->c->size&&at<=end&&n<=end-at;}
static bool sxamip_read(sxamip_view*v,uint64_t at,void*p,size_t n,uint64_t end)
{return ++v->work<=4000000&&sxamip_span(v,at,n,end)&&sx_read(v->c,(int64_t)at,p,n);}
static bool sxamip_word(sxamip_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!n||n>8||!sxamip_read(v,at,b,n,end))return false;uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[be?n-i-1:i]<<(8*i);*out=x;return true;}
static bool sxamip_row(sxamip_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxamip_span(v,at,z,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)z);}
#define AP_ROW(l,at,end) sxamip_row(v,&sxamip_##l,(at),(end))
static bool sxamip_table(sxamip_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>4000000||count>UINT64_MAX/z||!sxamip_span(v,at,count*z,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++,at+=z)if(!sxamip_row(v,l,at,end))return false;return true;}
static int sxamip_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxamip_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxamip_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxamip_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxamip_u(sxamip_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxamip_word(v,p,n,false,x,end);}
static bool sxamip_be(sxamip_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxamip_word(v,p,n,true,x,end);}
static bool sxamip_eq(sxamip_view*v,uint64_t p,const char*s,size_t n,uint64_t end){uint8_t b[64];return n<=sizeof(b)&&sxamip_read(v,p,b,n,end)&&!xx_rt_memcmp(b,s,n);}
static bool sxamip_text_emit(sxamip_view*v,uint64_t p,uint64_t n,uint64_t end){if(!sxamip_span(v,p,n,end))return false;return !n||n>4096||v->c->count>=24000||sx_add(v->c,&sxamip_text,(int64_t)p,(int64_t)n);}
static bool sxamip_take(sxamip_view*v,const sx_layout*l,uint64_t*p,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!sxamip_table(v,l,*p,count,end))return false;*p+=count*z;return true;}
static bool sxamip_skip(sxamip_view*v,uint64_t*p,uint64_t n,uint64_t end)
{if(!sxamip_span(v,*p,n,end))return false;*p+=n;return true;}
#define AP_TAKE(l,p,n,end) sxamip_take(v,&sxamip_##l,(p),(n),(end))

static bool sxamip_amc(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,stop,p=72,n,off,z;
 if(!sxamip_eq(v,0,"AMC V1.2 REPLAY!",16,e)||!AP_ROW(amc_header,0,e)||!sxamip_be(v,24,4,&stop,e)||stop<88||(stop-72)%16||!sxamip_span(v,72,stop-72,e))return false;
 n=(stop-72)/16;
 for(uint64_t i=0;i<n;i++,p+=16){if(!sxamip_be(v,p,4,&off,e)||!sxamip_be(v,p+4,2,&z,e)||!sxamip_span(v,off,z*2,e)||!AP_ROW(amc_sample,p,e))return false;}
 return true;
}
static bool sxamip_mxtx(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,p=8,flags,n,z,samples;
 if(!sxamip_eq(v,0,"MXTX",4,e)||!AP_ROW(mxtx_header,0,e)||!sxamip_be(v,6,2,&flags,e))return false;
 /* The retained microtonal loader's read and skip byte counts disagree.
    Preserve only the known prefix instead of inventing its table extent. */
 if(flags&0x8000)return true;
 if(!sxamip_be(v,p,2,&n,e)||!AP_TAKE(count16,&p,1,e))return false;
 for(uint64_t i=0;i<n;i++){if(!sxamip_be(v,p,4,&z,e)||!AP_TAKE(count32,&p,1,e)||!AP_TAKE(mxtx_event,&p,z,e))return false;}
 if(!sxamip_be(v,p,2,&samples,e)||!AP_TAKE(count16,&p,1,e))return false;
 for(uint64_t i=0;i<samples;i++){
  uint64_t oct,a,b,na,nr;
  if(!sxamip_span(v,p,20,e)||!sxamip_be(v,p+6,2,&oct,e)||!sxamip_be(v,p+8,4,&a,e)||!sxamip_be(v,p+12,4,&b,e)||!sxamip_be(v,p+16,2,&na,e)||!sxamip_be(v,p+18,2,&nr,e)||!AP_TAKE(mxtx_sample,&p,1,e)||!AP_TAKE(mxtx_envelope,&p,na+nr,e))return false;
  z=a+b;if(oct>64&&z)return false;
  for(uint64_t k=0;k<oct&&z;k++){if(!sxamip_skip(v,&p,z,e))return false;if(k+1<oct){if(z>UINT64_MAX/2)return false;z*=2;}}
 }
 return true;
}
static bool sxamip_omf(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,channels,patterns,positions,p=1306,z;
 if(!sxamip_eq(v,0,"Onyx Music File\032\000\001",18,e)||!sxamip_span(v,0,p,e)||!sxamip_u(v,402,1,&channels,e)||!sxamip_u(v,403,1,&patterns,e)||!sxamip_u(v,404,1,&positions,e)||(positions&1))return false;
 channels++;patterns++;positions=positions/2+1;
 if(positions>128||!AP_ROW(omf_identity,0,e)||!sxamip_table(v,&sxamip_omf_position,18,128,e)||!AP_ROW(omf_header_tail,402,e)||!sxamip_table(v,&sxamip_omf_sample,436,31,e)||!AP_ROW(omf_unknown,1304,e))return false;
 for(uint64_t i=0;i<patterns;i++){
  uint64_t nc,zero;if(!sxamip_u(v,p,2,&zero,e)||zero||!sxamip_u(v,p+2,1,&nc,e)||nc!=channels||!AP_TAKE(omf_pattern,&p,1,e)||!AP_TAKE(omf_event,&p,64*channels,e))return false;
 }
 for(uint64_t i=0;i<31;i++){
  uint64_t declared;if(!sxamip_u(v,436+i*28+24,2,&declared,e))return false;
  if(declared){uint64_t mark;if(!sxamip_u(v,p,1,&mark,e)||mark||!sxamip_u(v,p+1,2,&z,e)||z!=declared||!AP_TAKE(omf_sample_data,&p,1,e)||!sxamip_skip(v,&p,z,e))return false;}
 }
 return true;
}
static bool sxamip_plx(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,type,scale,p,flags,off;
 if(!sxamip_eq(v,0,"PLX",3,e)||!sxamip_u(v,3,1,&type,e)||type||!sxamip_u(v,4,1,&scale,e)||!AP_ROW(plx_header,0,e))return false;
 for(unsigned i=0;i<9;i++){
  if(!sxamip_u(v,7+2*i,2,&p,e))return false;if(!p)continue;
  for(unsigned step=0;step<65536;step++){
   if(!sxamip_u(v,p,1,&flags,e)||!AP_TAKE(plx_control,&p,1,e))return false;
   if(!flags)break;
   if(flags!=128){
    if(flags&1){if(!sxamip_u(v,p,2,&off,e)||!AP_TAKE(plx_instrument_offset,&p,1,e)||!AP_ROW(plx_instrument,off,e))return false;}
    if((flags&2)&&!AP_TAKE(plx_volume,&p,1,e))return false;
    if((flags&8)&&!AP_TAKE(plx_note,&p,1,e))return false;
    if((flags&16)&&!AP_TAKE(plx_frequency,&p,1,e))return false;
    if((flags&64)&&!AP_TAKE(plx_speed,&p,1,e))return false;
   }
   if(!AP_TAKE(plx_delay,&p,1,e))return false;
   if(step==65535)return false;
  }
 }
 return true;
}
static bool sxamip_relative_target32(sxamip_view*v,uint64_t at,uint64_t*out,uint64_t end)
{
 uint64_t x;if(!sxamip_be(v,at,4,&x,end))return false;int64_t d=x&0x80000000U?(int64_t)x-INT64_C(4294967296):(int64_t)x;
 if(d<0){if(at<(uint64_t)(-d))return false;*out=at-(uint64_t)(-d);}else{if((uint64_t)d>end-at)return false;*out=at+(uint64_t)d;}return *out<=end;
}
static bool sxamip_mso(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,table,n,target;
 if(!sxamip_eq(v,0,"MSOB",4,e)||!AP_ROW(mso_header,0,e))return false;
 for(unsigned i=0;i<4;i++)if(!sxamip_relative_target32(v,4+4*i,&target,e))return false;
 if(!sxamip_relative_target32(v,4,&table,e))return false;
 /* Replay compares its byte song index with the low byte of this word. */
 if(table<2||!sxamip_be(v,table-2,2,&n,e)||!AP_ROW(count16,table-2,e)||n>255||!sxamip_span(v,table,4*(n+1),e))return false;
 for(uint64_t i=1;i<=n;i++){
  uint64_t at=table+i*4;if(!sxamip_relative_target32(v,at,&target,e)||!AP_ROW(relative32,at,e))return false;
 }
 return true;
}
static bool sxamip_ea(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,base=0,off[6],p,maxpat=0,maxins=0;
 if(sxamip_eq(v,0,"EASO",4,e)){base=4;if(!AP_ROW(ea_magic,0,e))return false;}
 else return false;
 if(!sxamip_span(v,base,24,e))return false;
 for(unsigned i=0;i<6;i++){if(!sxamip_be(v,base+4*i,4,&off[i],e)||off[i]>e-base)return false;off[i]+=base;}
 if(off[0]!=base+24||off[1]<=off[0]||(off[1]-off[0])%8||off[4]<=off[2]||(off[4]-off[2])%16||!AP_ROW(ea_header,base,e))return false;
 p=off[1];for(unsigned i=0;i<65536;i++){
  uint64_t a,b;if(!sxamip_be(v,p,2,&a,e)||!sxamip_be(v,p+2,2,&b,e)||!AP_TAKE(ea_position,&p,1,e))return false;if(a==65535)break;
  if((a&4095)>maxpat)maxpat=a&4095;if((b&4095)>maxpat)maxpat=b&4095;
  if(i==65535)return false;
 }
 if(maxpat+1>(off[1]-off[0])/8)return false;
 for(uint64_t i=0;i<=maxpat;i++){
  p=off[0]+i*8;if(!AP_ROW(ea_pattern,p,e))return false;
  for(unsigned ch=0;ch<4;ch++){uint64_t a,b;if(!sxamip_be(v,p+ch*2,2,&a,e))return false;b=a&255;if(a&&b>maxins)maxins=b;}
 }
 if(!sxamip_table(v,&sxamip_ea_instrument,off[2],maxins+1,e))return false;
 p=off[3];for(unsigned i=0;i<128;i++){
  uint64_t a,z;if(!sxamip_be(v,p,2,&a,e)||!sxamip_be(v,p+2,2,&z,e)||!AP_TAKE(ea_sample,&p,1,e))return false;
  if(!a&&!z)break;if(!sxamip_span(v,base+a*4,z*2,e))return false;if(i==127)return false;
 }
 return true;
}

/* Only a single code hunk with HUNK_RELOC32-to-hunk0 is traversed here.
   Stored addends stay unmodified; metadata addresses require an actual
   relocation entry for that precise field. */
typedef struct sxamip_hunk {uint64_t first,end;uint32_t rel[4096];size_t n;}sxamip_hunk;
static int sxamip_reloc_order(const void*a,const void*b)
{uint32_t x=*(const uint32_t*)a,y=*(const uint32_t*)b;return x<y?-1:x>y?1:0;}
static bool sxamip_hunk_parse(sxamip_view*v,sxamip_hunk*h)
{
 uint64_t e=(uint64_t)v->c->size,magic,n,first,last,alloc,code,words,p,tag;
 xx_rt_memset(h,0,sizeof(*h));
 if(!sxamip_be(v,0,4,&magic,e)||magic!=1011||!sxamip_be(v,4,4,&n,e)||n||!sxamip_be(v,8,4,&n,e)||n!=1||!sxamip_be(v,12,4,&first,e)||first||!sxamip_be(v,16,4,&last,e)||last||!sxamip_be(v,20,4,&alloc,e)||!sxamip_be(v,24,4,&code,e)||(code&0x3fffffff)!=1001||!sxamip_be(v,28,4,&words,e)||!words||words>(alloc&0x3fffffff)||!sxamip_span(v,32,words*4,e))return false;
 h->first=32;h->end=32+words*4;p=h->end;
 if(!AP_ROW(hunk_header,0,e))return false;
 for(unsigned blocks=0;blocks<4096;blocks++){
  if(!sxamip_be(v,p,4,&tag,e))return false;
  if(tag==1010){
   xx_rt_qsort(h->rel,h->n,sizeof(h->rel[0]),sxamip_reloc_order);
   for(size_t i=1;i<h->n;i++)if(h->rel[i]-h->rel[i-1]<4)return false;
   return AP_ROW(hunk_end,p,e);
  }
  if(tag!=1004||!AP_TAKE(hunk_reloc_header,&p,1,e))return false;
  for(unsigned runs=0;runs<4096;runs++){
   if(!sxamip_be(v,p,4,&n,e))return false;
   if(!n){if(!AP_TAKE(hunk_zero,&p,1,e))return false;break;}
   uint64_t target;if(n>4096-h->n||!sxamip_be(v,p+4,4,&target,e)||target||!AP_TAKE(hunk_reloc_block,&p,1,e))return false;
   for(uint64_t j=0;j<n;j++){
    uint64_t off;if(!sxamip_be(v,p,4,&off,e)||(off&1)||off>words*4-4||!AP_TAKE(hunk_reloc_offset,&p,1,e))return false;
    h->rel[h->n++]=(uint32_t)off;
   }
   if(runs==4095)return false;
  }
 }
 return false;
}
static bool sxamip_hunk_ptr(sxamip_view*v,const sxamip_hunk*h,uint64_t at,uint64_t*out)
{
 uint64_t add;if(at<h->first||!sxamip_be(v,at,4,&add,h->end)||add>h->end-h->first)return false;
 bool found=false;for(size_t i=0;i<h->n;i++)if(h->rel[i]==at-h->first){found=true;break;}
 if(!found)return false;*out=h->first+add;return true;
}
static bool sxamip_hunk_text(sxamip_view*v,const sxamip_hunk*h,uint64_t at)
{
 uint64_t p,n=0,x;if(!sxamip_hunk_ptr(v,h,at,&p))return true;
 while(n<4096&&p+n<h->end){if(!sxamip_be(v,p+n,1,&x,h->end))return false;if(!x)return sxamip_text_emit(v,p,n,h->end);n++;}
 return true;
}
static bool sxamip_hunk_metadata(sxamip_view*v,unsigned kind)
{
 sxamip_hunk h;if(!sxamip_hunk_parse(v,&h))return false;
 uint64_t p=h.first,e=h.end,a,b,x;
 if(!sxamip_eq(v,p,"\x70\xff\x4e\x75",4,e))return false;
 if(kind==0){
  if(!sxamip_eq(v,p+4,"S.PHIPPS",8,e)||!AP_ROW(core_prefix,p,e))return false;
  for(unsigned k=40;k<=48;k+=4)if(!sxamip_hunk_text(v,&h,p+k))return false;
  if(sxamip_hunk_ptr(v,&h,p+32,&a)&&sxamip_hunk_ptr(v,&h,p+36,&b)&&b>=a&&(b-a)%14==0){
   for(uint64_t row=a;row<b;row+=14){if(!AP_ROW(core_sample,row,e))return false;
    if(sxamip_hunk_ptr(v,&h,row+6,&x)){uint64_t z;if(!sxamip_be(v,x,2,&z,e)||!sxamip_span(v,x+2,z*2,e)||!AP_ROW(word_length,x,e))return false;}}
  }
 }else if(kind==1){
  if(!sxamip_eq(v,p+4,"F.PLAYER",8,e)||!AP_ROW(future_prefix,p,e))return false;
  for(unsigned k=12;k<=20;k+=4)if(!sxamip_hunk_text(v,&h,p+k))return false;
  for(uint64_t row=p+32;row<e;row+=8){
   if(!sxamip_be(v,row,4,&x,e))return false;
   if(!x)return AP_ROW(future_end,row,e);
   if(!AP_ROW(future_subsong,row,e))return false;
   if(sxamip_hunk_ptr(v,&h,row,&a)&&sxamip_span(v,a,24,e)&&!AP_ROW(future_song_voices,a+8,e))return false;
  }
  return false;
 }else if(kind==2){
  if(!sxamip_eq(v,p+4,"J.FLOGEL",8,e)||!AP_ROW(jmf_prefix,p,e))return false;
  for(unsigned k=28;k<=36;k+=4)if(!sxamip_hunk_text(v,&h,p+k))return false;
 }else if(kind==3){
  if(!sxamip_eq(v,p+4,"DAGLISH!",8,e)||!AP_ROW(daglish_prefix,p,e))return false;
  for(unsigned k=28;k<=36;k+=4)if(!sxamip_hunk_text(v,&h,p+k))return false;
 }else{
  if(!sxamip_eq(v,p+4,"UNCLEART",8,e)||!AP_ROW(lowe_prefix,p,e))return false;
  for(unsigned k=48;k<=56;k+=4)if(!sxamip_hunk_text(v,&h,p+k))return false;
  if(sxamip_hunk_ptr(v,&h,p+28,&a)&&sxamip_hunk_ptr(v,&h,p+32,&b)&&b>=a&&(b-a)%14==0){
   for(uint64_t row=a;row<b;row+=14){if(!AP_ROW(lowe_sample,row,e))return false;
    if(sxamip_hunk_ptr(v,&h,row+2,&x)){uint64_t z;if(!sxamip_be(v,row+6,2,&z,e)||!sxamip_span(v,x,z*2,e))return false;}}
  }
 }
 return true;
}

static bool sxamip_signed16_target(sxamip_view*v,uint64_t at,uint64_t base,uint64_t*out,uint64_t end)
{
 uint64_t x;if(!sxamip_be(v,at,2,&x,end))return false;int64_t d=x&32768?(int64_t)x-65536:(int64_t)x;
 if(d<0){if(base<(uint64_t)(-d))return false;*out=base-(uint64_t)(-d);}else{if((uint64_t)d>end||base>end-(uint64_t)d)return false;*out=base+(uint64_t)d;}return *out<=end;
}
static bool sxamip_art(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,x,p,q;
 if(e<0x160||!sxamip_eq(v,26,"EXIT",4,e)||!sxamip_eq(v,e-4,"EXIT",4,e)||!sxamip_be(v,0xe2,2,&x,e))return false;
 p=(x+0xe2)&65535;if(p&32768)return false;
 if(!sxamip_be(v,0x15e,2,&x,e))return false;q=(x+0x155)&65535;
 if(q&32768||q<p+40||(q-p-40)%4||!sxamip_span(v,p,q-p+4,e))return false;
 if(!AP_ROW(art_table_operand,0xe2,e)||!AP_ROW(art_limit_operand,0x15e,e)||!AP_ROW(art_marker,26,e)||!AP_ROW(art_marker,e-4,e))return false;
 for(unsigned i=0;i<5;i++)if(!AP_ROW(art_relocation,p+i*8,e))return false;
 return sxamip_table(v,&sxamip_art_relocation,p+40,(q-p-40)/4+1,e);
}
static bool sxamip_turner_target(uint64_t stored,uint64_t origin,uint64_t extra,uint64_t end,uint64_t*out)
{if(stored<origin){uint64_t d=origin-stored;if(d>extra)return false;*out=extra-d;}else{uint64_t d=stored-origin;if(d>end||extra>end-d)return false;*out=d+extra;}return *out<=end;}
static bool sxamip_turner(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,origin,sub,trk,smp,a,p,z,n;
 if(!sxamip_span(v,0,46,e))return false;
 for(unsigned i=0;i<4;i++)if(!sxamip_eq(v,i*8,"\x2b\x7c",2,e)||!AP_ROW(turner_address,2+i*8,e))return false;
 if(!sxamip_eq(v,32,"\x30\x3c\0\xff\x32\0\x4e\xb9",8,e)||!sxamip_eq(v,44,"\x4e\x75",2,e)||!sxamip_be(v,2,4,&origin,e)||origin<46||!sxamip_be(v,10,4,&a,e)||!sxamip_turner_target(a,origin,46,e,&sub)||!sxamip_be(v,18,4,&a,e)||!sxamip_turner_target(a,origin,46,e,&trk)||!sxamip_be(v,26,4,&a,e)||!sxamip_turner_target(a,origin,20,e,&smp))return false;
 p=sub;for(unsigned i=0;i<4096;i++){
  if(!sxamip_be(v,p,2,&a,e))return false;if(a&0xfff0)break;
  if(!AP_ROW(turner_subsong,p,e))return false;
  for(unsigned k=4;k<12;k+=2){uint64_t target;if(!sxamip_be(v,p+k,2,&a,e))return false;if(a&&(!sxamip_signed16_target(v,p+k,sub,&target,e)||!sxamip_span(v,target,1,e)))return false;}
  p+=12;if(i==4095)return false;
 }
 /* The source's sample-information prefix lies26 bytes before its pointer table. */
 if(!sxamip_be(v,smp,4,&n,e)||!n||(n&3)||n/4>4096||!AP_ROW(turner_sample_table,smp,e))return false;
 p=smp+26;if(!sxamip_span(v,p,n,e))return false;
 for(uint64_t i=0;i<n/4;i++){
  if(!sxamip_be(v,p+i*4,4,&a,e)||!AP_ROW(turner_sample_offset,p+i*4,e))return false;
  if(!a)continue;if(a>e-p||!sxamip_be(v,p+a,2,&z,e)||p+a<6||!sxamip_span(v,p+a-6,z+8,e)||!AP_ROW(turner_sample_length,p+a,e))return false;
 }
 /* Track opcodes remain raw: the independent source does not expose a
    version-independent decoded-event table for this stored address. */
 return sxamip_span(v,trk,2,e);
}
static bool sxamip_find_word(sxamip_view*v,uint64_t*p,uint16_t wanted,uint64_t end)
{for(;*p+2<=end;*p+=2){uint64_t x;if(!sxamip_be(v,*p,2,&x,end))return false;if(x==wanted)return true;}return false;}
static bool sxamip_cooksey(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,lim=e<1048576?e:1048576,p,sub,subend,info,samples;
 if(!sxamip_eq(v,0,"\xd0\x40\xd0\x40\x4e\xfb",6,e))return false;
 for(unsigned i=8;i<=20;i+=4)if(!sxamip_eq(v,i,"\x60\0",2,e))return false;
 p=sxamip_eq(v,40,"\x43\xfa",2,e)?40:150;
 if(!sxamip_eq(v,p,"\x43\xfa",2,e))return false;p+=2;
 if(!sxamip_signed16_target(v,p,p,&sub,e)||!AP_ROW(cooksey_displacement,p,e))return false;
 uint64_t scan=p;if(!sxamip_find_word(v,&scan,0x43fa,lim))return false;scan+=2;
 if(!sxamip_signed16_target(v,scan,scan,&subend,e)||subend<sub||(subend-sub)%16||!AP_ROW(cooksey_displacement,scan,e)||!sxamip_span(v,sub,subend-sub,e))return false;
 p=scan;
 for(;;){if(!sxamip_span(v,p,6,lim))return false;if(sxamip_eq(v,p,"\0\0\x41\xfa",4,lim))break;p+=2;}
 p+=4;if(!sxamip_signed16_target(v,p,p,&info,e)||!AP_ROW(cooksey_displacement,p,e))return false;
 scan=p;if(!sxamip_find_word(v,&scan,0x43fa,lim))return false;scan+=2;
 if(!sxamip_signed16_target(v,scan,scan,&samples,e)||!AP_ROW(cooksey_displacement,scan,e))return false;
 uint64_t first;if(!sxamip_be(v,info,2,&first,e)||(first&1)||!first||first>=32768||first/2>4096||!sxamip_span(v,info,first,e))return false;
 for(uint64_t i=0;i<first/2;i++){
  uint64_t at=info+i*2,row,x,z;if(!sxamip_signed16_target(v,at,at,&row,e)||!AP_ROW(cooksey_sample_offset,at,e))return false;
  if(!sxamip_be(v,row,4,&x,e))return false;
  if(x){if(!sxamip_be(v,row+16,2,&z,e)||!AP_ROW(cooksey_sample,row,e))return false;}
  else{if(!sxamip_be(v,row+4,4,&x,e)||!sxamip_be(v,row+18,2,&z,e)||!AP_ROW(cooksey_shifted_sample,row,e))return false;}
  if(x>e-samples||!sxamip_span(v,samples+x,z*2,e))return false;
 }
 return true;
}

static bool sx_amigaplayers_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_DIE_MUSIC_HAWLITZECK_AMCOMPOSER:
case XX_FILE_TYPE_DIE_MUSIC_TALIN_MAXTRAX_MUSICX:
case XX_FILE_TYPE_DIE_MUSIC_ALTAR_ONYXMUSICFILE:
case XX_FILE_TYPE_DIE_MUSIC_RAINBOWARTS_PALLADIXSS_PLX:
case XX_FILE_TYPE_DIE_MUSIC_VDVALK_MEDLEYSOUND_MSO:
case XX_FILE_TYPE_DIE_MUSIC_GROULEFF_EARACHE:
case XX_FILE_TYPE_DIE_MUSIC_PHIPPS_COREDESIGN:
case XX_FILE_TYPE_DIE_MUSIC_VDVALK_FUTUREPLAYER:
case XX_FILE_TYPE_DIE_MUSIC_JMFLOGEL:
case XX_FILE_TYPE_DIE_MUSIC_BENDAGLISH_SID:
case XX_FILE_TYPE_DIE_MUSIC_DAVELOWE_UNCLEART:
case XX_FILE_TYPE_DIE_MUSIC_SAUER_ARTANDMAGIC:
case XX_FILE_TYPE_DIE_MUSIC_TURNER_JPO:
case XX_FILE_TYPE_DIE_MUSIC_MARK_COOKSEY:
return true;default:return false;}}
static bool sx_amigaplayers_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxamip_view view={c,0},*v=&view;bool ok=false;
 switch(c->f->file_type){
case XX_FILE_TYPE_DIE_MUSIC_HAWLITZECK_AMCOMPOSER:ok=sxamip_amc(v);break;
case XX_FILE_TYPE_DIE_MUSIC_TALIN_MAXTRAX_MUSICX:ok=sxamip_mxtx(v);break;
case XX_FILE_TYPE_DIE_MUSIC_ALTAR_ONYXMUSICFILE:ok=sxamip_omf(v);break;
case XX_FILE_TYPE_DIE_MUSIC_RAINBOWARTS_PALLADIXSS_PLX:ok=sxamip_plx(v);break;
case XX_FILE_TYPE_DIE_MUSIC_VDVALK_MEDLEYSOUND_MSO:ok=sxamip_mso(v);break;
case XX_FILE_TYPE_DIE_MUSIC_GROULEFF_EARACHE:ok=sxamip_ea(v);break;
case XX_FILE_TYPE_DIE_MUSIC_PHIPPS_COREDESIGN:ok=sxamip_hunk_metadata(v,0);break;
case XX_FILE_TYPE_DIE_MUSIC_VDVALK_FUTUREPLAYER:ok=sxamip_hunk_metadata(v,1);break;
case XX_FILE_TYPE_DIE_MUSIC_JMFLOGEL:ok=sxamip_hunk_metadata(v,2);break;
case XX_FILE_TYPE_DIE_MUSIC_BENDAGLISH_SID:ok=sxamip_hunk_metadata(v,3);break;
case XX_FILE_TYPE_DIE_MUSIC_DAVELOWE_UNCLEART:ok=sxamip_hunk_metadata(v,4);break;
case XX_FILE_TYPE_DIE_MUSIC_SAUER_ARTANDMAGIC:ok=sxamip_art(v);break;
case XX_FILE_TYPE_DIE_MUSIC_TURNER_JPO:ok=sxamip_turner(v);break;
case XX_FILE_TYPE_DIE_MUSIC_MARK_COOKSEY:ok=sxamip_cooksey(v);break;
default:break;}
 return ok&&sxamip_finish(c);}
#undef AP_ROW
#undef AP_TAKE
static bool sxamip_name(const xx_data_struct_record*r,const wchar_t*n){return !xx_rt_wcscmp(r->name,n);}
static bool sx_amigaplayers_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id<UINT32_C(0x60900001)||id>=UINT32_C(0x60910000))return true;
 const wchar_t*s=NULL;
 if(sxamip_name(r,L"length_words"))s=L"Length in two-byte sample words; multiply by 2 for bytes";
 if(r->property&SX_POINTER)s=L"Original HUNK relocation addend in bytes; following the pointer requires a matching RELOC32 entry";
 if(id==sxamip_amc_header.id||id==sxamip_amc_sample.id){if(r->property&SX_OFFSET)s=L"Byte offset relative to the start of the AMC module";}
 else if(id==sxamip_mxtx_header.id&&sxamip_name(r,L"flags"))s=L"Bit 0 audio filter; bit 1 attack velocity; bit 15 microtonal table (body left raw by this provider)";
 else if(id==sxamip_mxtx_event.id){if(sxamip_name(r,L"start_time"))s=L"Stored score timing word; not a wall-clock timestamp";else if(sxamip_name(r,L"stop_time_or_value"))s=L"Command-dependent timing or controller operand; not a wall-clock timestamp";}
 else if(id==sxamip_mxtx_sample.id&&sxamip_name(r,L"tune"))s=L"Signed tuning: the original player adds tune/24 semitones to the note";
 else if(id==sxamip_mxtx_envelope.id&&sxamip_name(r,L"duration_ms"))s=L"Envelope segment duration in milliseconds";
 else if(id==sxamip_omf_position.id)s=L"Pattern number multiplied by 16 times channel count; active entries are stored in reverse song order";
 else if(id==sxamip_omf_header_tail.id){if(sxamip_name(r,L"channels_minus_one"))s=L"Encoded channel count minus one";else if(sxamip_name(r,L"patterns_minus_one"))s=L"Encoded pattern count minus one";else if(sxamip_name(r,L"positions_minus_one_times_two"))s=L"Twice the sequence-position count minus two";}
 else if(id==sxamip_omf_sample.id){if(sxamip_name(r,L"finetune_encoded"))s=L"Signed finetune multiplied by -487";else if(sxamip_name(r,L"repeat_bytes"))s=L"Loop length in bytes, measured backwards from the end of the stored sample";}
 else if(id==sxamip_omf_event.id&&sxamip_name(r,L"period_high_and_effect"))s=L"Low nibble period bits 8..11; high nibble effect command; pattern rows are physically reversed";
 else if(id==sxamip_plx_header.id){if(r->property&SX_OFFSET)s=L"Absolute byte offset of the channel command stream; zero disables the channel";else if(sxamip_name(r,L"speed_scale"))s=L"Stored speed divisor; zero is treated as one during playback";else if(sxamip_name(r,L"speed"))s=L"Player speed control; zero is treated as one during playback, not beats per minute";}
 else if(id==sxamip_plx_control.id)s=L"0 ends stream; 80 only delay. Otherwise bits 0 instrument, 1 volume, 2 key-off, 3 note, 4 frequency, 5 key-on, 6 speed";
 else if(id==sxamip_plx_instrument_offset.id)s=L"Absolute byte offset to the 12-byte OPL instrument";
 else if(id==sxamip_plx_note.id)s=L"Stored note number multiplied by two";
 else if(id==sxamip_plx_frequency.id)s=L"OPL frequency/block/key register bits; not a frequency in Hz";
 else if(id==sxamip_mso_header.id&&(r->property&SX_OFFSET))s=L"Byte displacement relative to this offset word itself";
 else if(id==sxamip_relative32.id)s=L"Byte displacement relative to this song-table word itself";
 else if(id==sxamip_ea_header.id)s=L"Byte offset relative to the EarAche data header, after the EASO prefix";
 else if(id==sxamip_ea_sample.id&&sxamip_name(r,L"sample_offset_dwords"))s=L"Sample byte position is four times this value, relative to the data header";
 else if(id==sxamip_ea_position.id){if(sxamip_name(r,L"first_pattern_or_end"))s=L"Low 12 bits first pattern row; FFFF is the sequence-end/restart control";else s=L"Low 12 bits last pattern row or restart operand; high nibble speed";}
 else if(id==sxamip_ea_instrument.id&&sxamip_name(r,L"fine_tune"))s=L"Signed period adjustment scaled by the played octave";
 else if(id==sxamip_hunk_header.id){if(sxamip_name(r,L"allocation_words_and_flags"))s=L"Low 30 bits allocation size in 32-bit words; high bits Amiga memory flags";else if(sxamip_name(r,L"code_words"))s=L"Code payload length in 32-bit words; not bytes";}
 else if(id==sxamip_hunk_reloc_offset.id)s=L"Byte offset within the source code hunk of a stored 32-bit relocation addend";
 else if(id==sxamip_future_subsong.id&&!(r->property&SX_POINTER))s=L"Stored 16-bit player parameter; no count or physical-address meaning is inferred";
 else if(id==sxamip_art_table_operand.id)s=L"Stored 16-bit displacement; add E2 hex with 16-bit wrap, then sign-extend to locate the relocation table";
 else if(id==sxamip_art_limit_operand.id)s=L"Stored 16-bit displacement; add 155 hex with 16-bit wrap, then sign-extend to locate the final relocation word";
 else if(id==sxamip_art_relocation.id)s=L"Original pre-relocation address; the player adds a single relocation delta derived from the final word and its location";
 else if(id==sxamip_turner_address.id)s=L"Original stored address; metadata locations use stored address minus origin at byte2, plus2E hex (sample prefix uses14 hex)";
 else if(id==sxamip_turner_subsong.id){if(r->property&SX_OFFSET)s=L"Signed byte displacement relative to the first subsong-table record; zero disables this channel";else if(sxamip_name(r,L"unused3"))s=L"Physical prefix byte skipped by the retained player";else s=L"Stored byte consumed separately by the original player; no packed channel-mask meaning is inferred";}
 else if(id==sxamip_turner_sample_table.id&&sxamip_name(r,L"pointer_count_times_four"))s=L"Sample-pointer count multiplied by four; each stored pointer occupies four bytes";
 else if(id==sxamip_turner_sample_offset.id)s=L"Byte offset relative to the sample-pointer table, to the stored length word";
 else if(id==sxamip_turner_sample_length.id)s=L"Original word used by the replayer: exposed sample starts six bytes before this word and spans stored length plus eight bytes";
 else if(id==sxamip_cooksey_displacement.id)s=L"Signed 16-bit PC-relative displacement, based at this operand word";
 else if(id==sxamip_cooksey_sample_offset.id)s=L"Signed byte displacement relative to this sample-table entry word";
 else if((id==sxamip_cooksey_sample.id||id==sxamip_cooksey_shifted_sample.id)&&sxamip_name(r,L"sample_data_offset"))s=L"Byte offset relative to the separately located sample-data block";
 return !s||xx_data_struct_record_set_comment(r,s);
}
