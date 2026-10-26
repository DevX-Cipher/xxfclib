/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical music header and table metadata; compressed and unknown bodies stay raw. */
static const xx_data_struct_field_desc sxnextm_text_fields[]={
 SX_FIELD("text","char",0,0,SX_NONE),
};
static const sx_layout sxnextm_text={UINT32_C(0x608B0001),"text",sxnextm_text_fields,SX_COUNT(sxnextm_text_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_u8_fields[]={
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sxnextm_u8={UINT32_C(0x608B0002),"u8",sxnextm_u8_fields,SX_COUNT(sxnextm_u8_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_i8_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
static const sx_layout sxnextm_i8={UINT32_C(0x608B0003),"i8",sxnextm_i8_fields,SX_COUNT(sxnextm_i8_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_count16_fields[]={
 SX_FIELD("count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxnextm_count16={UINT32_C(0x608B0004),"count16",sxnextm_count16_fields,SX_COUNT(sxnextm_count16_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_offset16_fields[]={
 SX_FIELD("offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxnextm_offset16={UINT32_C(0x608B0005),"offset16",sxnextm_offset16_fields,SX_COUNT(sxnextm_offset16_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_bytes32_fields[]={
 SX_FIELD("byte_count","uint32",0,4,SX_SIZE),
};
static const sx_layout sxnextm_bytes32={UINT32_C(0x608B0006),"bytes32",sxnextm_bytes32_fields,SX_COUNT(sxnextm_bytes32_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_track16_fields[]={
 SX_FIELD("track_index","uint16",0,2,SX_ID),
};
static const sx_layout sxnextm_track16={UINT32_C(0x608B0007),"track16",sxnextm_track16_fields,SX_COUNT(sxnextm_track16_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_order8_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_ID),
};
static const sx_layout sxnextm_order8={UINT32_C(0x608B0008),"order8",sxnextm_order8_fields,SX_COUNT(sxnextm_order8_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_chunk_le_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxnextm_chunk_le={UINT32_C(0x608B0009),"chunk_le",sxnextm_chunk_le_fields,SX_COUNT(sxnextm_chunk_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_chunk_be_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxnextm_chunk_be={UINT32_C(0x608B000A),"chunk_be",sxnextm_chunk_be_fields,SX_COUNT(sxnextm_chunk_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_ast_header_fields[]={
 SX_FIELD("tempo","uint16",0,2,SX_NONE),
 SX_FIELD("section0_bytes","uint32",2,4,SX_SIZE),
 SX_FIELD("section1_bytes","uint32",6,4,SX_SIZE),
 SX_FIELD("section2_bytes","uint32",10,4,SX_SIZE),
 SX_FIELD("section3_bytes","uint32",14,4,SX_SIZE),
 SX_FIELD("section4_bytes","uint32",18,4,SX_SIZE),
 SX_FIELD("section5_bytes","uint32",22,4,SX_SIZE),
 SX_FIELD("section6_bytes","uint32",26,4,SX_SIZE),
 SX_FIELD("section7_bytes","uint32",30,4,SX_SIZE),
 SX_FIELD("section8_bytes","uint32",34,4,SX_SIZE),
 SX_FIELD("section9_bytes","uint32",38,4,SX_SIZE),
 SX_FIELD("section10_bytes","uint32",42,4,SX_SIZE),
 SX_FIELD("section11_bytes","uint32",46,4,SX_SIZE),
 SX_FIELD("section12_bytes","uint32",50,4,SX_SIZE),
 SX_FIELD("section13_bytes","uint32",54,4,SX_SIZE),
 SX_FIELD("section14_bytes","uint32",58,4,SX_SIZE),
};
static const sx_layout sxnextm_ast_header={UINT32_C(0x608B000B),"ast_header",sxnextm_ast_header_fields,SX_COUNT(sxnextm_ast_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_ast_banner_fields[]={
 SX_FIELD("signature","bytes",0,22,SX_SIGNATURE),
 SX_FIELD("unknown","bytes",22,2,SX_NONE),
 SX_FIELD("version_text","char[3]",24,3,SX_NONE),
};
static const sx_layout sxnextm_ast_banner={UINT32_C(0x608B000C),"ast_banner",sxnextm_ast_banner_fields,SX_COUNT(sxnextm_ast_banner_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ast_module_size_fields[]={
 SX_FIELD("module_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxnextm_ast_module_size={UINT32_C(0x608B000D),"ast_module_size",sxnextm_ast_module_size_fields,SX_COUNT(sxnextm_ast_module_size_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_ast_instrument_fields[]={
 SX_FIELD("sample_list_index","uint8",0,1,SX_ID),
 SX_FIELD("sample_value_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("sample_start_counter_delta","uint8",2,1,SX_NONE),
 SX_FIELD("sample_counter_end","uint8",3,1,SX_NONE),
 SX_FIELD("arpeggio_list_index","uint8",4,1,SX_ID),
 SX_FIELD("arpeggio_value_count","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("arpeggio_start_counter_delta","uint8",6,1,SX_NONE),
 SX_FIELD("arpeggio_counter_end","uint8",7,1,SX_NONE),
 SX_FIELD("frequency_list_index","uint8",8,1,SX_ID),
 SX_FIELD("frequency_value_count","uint8",9,1,SX_COUNT_PROP),
 SX_FIELD("frequency_start_counter_delta","uint8",10,1,SX_NONE),
 SX_FIELD("frequency_counter_end","uint8",11,1,SX_NONE),
 SX_FIELD("portamento_increment","int8",12,1,SX_NONE),
 SX_FIELD("portamento_delay","uint8",13,1,SX_NONE),
 SX_FIELD("note_transpose","int8",14,1,SX_NONE),
 SX_FIELD("unknown0","uint8",15,1,SX_NONE),
 SX_FIELD("attack_end_volume","uint8",16,1,SX_NONE),
 SX_FIELD("attack_speed","uint8",17,1,SX_NONE),
 SX_FIELD("decay_end_volume","uint8",18,1,SX_NONE),
 SX_FIELD("decay_speed","uint8",19,1,SX_NONE),
 SX_FIELD("sustain_delay","uint8",20,1,SX_NONE),
 SX_FIELD("release_end_volume","uint8",21,1,SX_NONE),
 SX_FIELD("release_speed","uint8",22,1,SX_NONE),
 SX_FIELD("unknown_tail","bytes",23,9,SX_NONE),
};
static const sx_layout sxnextm_ast_instrument={UINT32_C(0x608B000E),"ast_instrument",sxnextm_ast_instrument_fields,SX_COUNT(sxnextm_ast_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ast_subsong_fields[]={
 SX_FIELD("first_position","uint8",0,1,SX_ID),
 SX_FIELD("last_position","uint8",1,1,SX_ID),
 SX_FIELD("loop_position","uint8",2,1,SX_ID),
 SX_FIELD("speed","uint8",3,1,SX_NONE),
};
static const sx_layout sxnextm_ast_subsong={UINT32_C(0x608B000F),"ast_subsong",sxnextm_ast_subsong_fields,SX_COUNT(sxnextm_ast_subsong_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ast_sample_fields[]={
 SX_FIELD("stored_data_pointer","uint32",0,4,SX_NONE),
 SX_FIELD("length_words","uint16",4,2,SX_NONE),
 SX_FIELD("loop_start_words","uint16",6,2,SX_NONE),
 SX_FIELD("loop_length_words","uint16",8,2,SX_NONE),
 SX_FIELD("effect_start","uint16",10,2,SX_NONE),
 SX_FIELD("effect_length","uint16",12,2,SX_NONE),
 SX_FIELD("effect_speed","uint16",14,2,SX_NONE),
 SX_FIELD("effect_mode","uint16",16,2,SX_ID),
 SX_FIELD("effect_increment","int16",18,2,SX_NONE),
 SX_FIELD("effect_position","int32",20,4,SX_NONE),
 SX_FIELD("effect_counter","uint16",24,2,SX_NONE),
 SX_FIELD("already_taken","uint16",26,2,SX_FLAGS),
 SX_FIELD("unknown","bytes",28,4,SX_NONE),
 SX_FIELD("name","char[32]",32,32,SX_NONE),
};
static const sx_layout sxnextm_ast_sample={UINT32_C(0x608B0010),"ast_sample",sxnextm_ast_sample_fields,SX_COUNT(sxnextm_ast_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_dss_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("unknown","bytes",4,4,SX_NONE),
 SX_FIELD("tempo","uint8",8,1,SX_NONE),
 SX_FIELD("speed","uint8",9,1,SX_NONE),
};
static const sx_layout sxnextm_dss_header={UINT32_C(0x608B0011),"dss_header",sxnextm_dss_header_fields,SX_COUNT(sxnextm_dss_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dss_sample_fields[]={
 SX_FIELD("name","char[30]",0,30,SX_NONE),
 SX_FIELD("start_offset_encoded","uint32",30,4,SX_NONE),
 SX_FIELD("length_words","uint16",34,2,SX_NONE),
 SX_FIELD("loop_start","uint32",36,4,SX_OFFSET),
 SX_FIELD("loop_length_words","uint16",40,2,SX_NONE),
 SX_FIELD("finetune","uint8",42,1,SX_NONE),
 SX_FIELD("volume","uint8",43,1,SX_NONE),
 SX_FIELD("frequency","uint16",44,2,SX_NONE),
};
static const sx_layout sxnextm_dss_sample={UINT32_C(0x608B0012),"dss_sample",sxnextm_dss_sample_fields,SX_COUNT(sxnextm_dss_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_dss_event_fields[]={
 SX_FIELD("sample_and_period_high","uint8",0,1,SX_FLAGS),
 SX_FIELD("period_low","uint8",1,1,SX_NONE),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("effect_argument","uint8",3,1,SX_NONE),
};
static const sx_layout sxnextm_dss_event={UINT32_C(0x608B0013),"dss_event",sxnextm_dss_event_fields,SX_COUNT(sxnextm_dss_event_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fred_header_fields[]={
 SX_FIELD("signature","bytes",0,12,SX_SIGNATURE),
 SX_FIELD("version","uint16",12,2,SX_ID),
 SX_FIELD("subsong_count","uint16",14,2,SX_COUNT_PROP),
};
static const sx_layout sxnextm_fred_header={UINT32_C(0x608B0014),"fred_header",sxnextm_fred_header_fields,SX_COUNT(sxnextm_fred_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_track_length_fields[]={
 SX_FIELD("track_bytes","int32",0,4,SX_SIZE),
};
static const sx_layout sxnextm_fred_track_length={UINT32_C(0x608B0015),"fred_track_length",sxnextm_fred_track_length_fields,SX_COUNT(sxnextm_fred_track_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_instrument_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_NONE),
 SX_FIELD("instrument_index","uint32",32,4,SX_ID),
 SX_FIELD("repeat_start","uint16",36,2,SX_OFFSET),
 SX_FIELD("length_words","uint16",38,2,SX_NONE),
 SX_FIELD("period","uint16",40,2,SX_NONE),
 SX_FIELD("vibrato_delay","uint8",42,1,SX_NONE),
 SX_FIELD("unknown0","uint8",43,1,SX_NONE),
 SX_FIELD("vibrato_speed","int8",44,1,SX_NONE),
 SX_FIELD("vibrato_amplitude","int8",45,1,SX_NONE),
 SX_FIELD("envelope_volume","uint8",46,1,SX_NONE),
 SX_FIELD("attack_speed","uint8",47,1,SX_NONE),
 SX_FIELD("attack_volume","uint8",48,1,SX_NONE),
 SX_FIELD("decay_speed","uint8",49,1,SX_NONE),
 SX_FIELD("decay_volume","uint8",50,1,SX_NONE),
 SX_FIELD("sustain_delay","uint8",51,1,SX_NONE),
 SX_FIELD("release_speed","uint8",52,1,SX_NONE),
 SX_FIELD("release_volume","uint8",53,1,SX_NONE),
 SX_FIELD("arpeggio0","int8",54,1,SX_NONE),
 SX_FIELD("arpeggio1","int8",55,1,SX_NONE),
 SX_FIELD("arpeggio2","int8",56,1,SX_NONE),
 SX_FIELD("arpeggio3","int8",57,1,SX_NONE),
 SX_FIELD("arpeggio4","int8",58,1,SX_NONE),
 SX_FIELD("arpeggio5","int8",59,1,SX_NONE),
 SX_FIELD("arpeggio6","int8",60,1,SX_NONE),
 SX_FIELD("arpeggio7","int8",61,1,SX_NONE),
 SX_FIELD("arpeggio8","int8",62,1,SX_NONE),
 SX_FIELD("arpeggio9","int8",63,1,SX_NONE),
 SX_FIELD("arpeggio10","int8",64,1,SX_NONE),
 SX_FIELD("arpeggio11","int8",65,1,SX_NONE),
 SX_FIELD("arpeggio12","int8",66,1,SX_NONE),
 SX_FIELD("arpeggio13","int8",67,1,SX_NONE),
 SX_FIELD("arpeggio14","int8",68,1,SX_NONE),
 SX_FIELD("arpeggio15","int8",69,1,SX_NONE),
 SX_FIELD("arpeggio_speed","uint8",70,1,SX_NONE),
 SX_FIELD("instrument_type","uint8",71,1,SX_ID),
 SX_FIELD("pulse_rate_min","int8",72,1,SX_NONE),
 SX_FIELD("pulse_rate_plus","int8",73,1,SX_NONE),
 SX_FIELD("pulse_speed","uint8",74,1,SX_NONE),
 SX_FIELD("pulse_start","uint8",75,1,SX_NONE),
 SX_FIELD("pulse_end","uint8",76,1,SX_NONE),
 SX_FIELD("pulse_delay","uint8",77,1,SX_NONE),
 SX_FIELD("synchronization","uint8",78,1,SX_FLAGS),
 SX_FIELD("blend","uint8",79,1,SX_NONE),
 SX_FIELD("blend_delay","uint8",80,1,SX_NONE),
 SX_FIELD("pulse_shot_counter","uint8",81,1,SX_NONE),
 SX_FIELD("blend_shot_counter","uint8",82,1,SX_NONE),
 SX_FIELD("arpeggio_count","uint8",83,1,SX_NONE),
 SX_FIELD("unknown_tail","bytes",84,12,SX_NONE),
};
static const sx_layout sxnextm_fred_instrument={UINT32_C(0x608B0016),"fred_instrument",sxnextm_fred_instrument_fields,SX_COUNT(sxnextm_fred_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_sample_fields[]={
 SX_FIELD("instrument_index","uint16",0,2,SX_ID),
 SX_FIELD("sample_bytes","uint16",2,2,SX_SIZE),
};
static const sx_layout sxnextm_fred_sample={UINT32_C(0x608B0017),"fred_sample",sxnextm_fred_sample_fields,SX_COUNT(sxnextm_fred_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_end_fields[]={
 SX_FIELD("end_marker","uint32",0,4,SX_ID),
};
static const sx_layout sxnextm_fred_end={UINT32_C(0x608B0018),"fred_end",sxnextm_fred_end_fields,SX_COUNT(sxnextm_fred_end_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_dtm_info_fields[]={
 SX_FIELD("channels","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("sequence_length","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("patterns","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("tracks","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("instruments","uint16",8,2,SX_COUNT_PROP),
};
static const sx_layout sxnextm_dtm_info={UINT32_C(0x608B0019),"dtm_info",sxnextm_dtm_info_fields,SX_COUNT(sxnextm_dtm_info_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_speed_fields[]={
 SX_FIELD("frames_per_row","uint16",0,2,SX_NONE),
 SX_FIELD("beats_per_minute","uint16",2,2,SX_NONE),
};
static const sx_layout sxnextm_dtm_speed={UINT32_C(0x608B001A),"dtm_speed",sxnextm_dtm_speed_fields,SX_COUNT(sxnextm_dtm_speed_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_pan_fields[]={
 SX_FIELD("left_volume","uint8",0,1,SX_NONE),
 SX_FIELD("right_volume","uint8",1,1,SX_NONE),
};
static const sx_layout sxnextm_dtm_pan={UINT32_C(0x608B001B),"dtm_pan",sxnextm_dtm_pan_fields,SX_COUNT(sxnextm_dtm_pan_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_sample_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_NONE),
 SX_FIELD("sample_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("loop_start","uint32",36,4,SX_OFFSET),
 SX_FIELD("loop_end","uint32",40,4,SX_OFFSET),
 SX_FIELD("c4_sample_rate","uint16",44,2,SX_NONE),
 SX_FIELD("volume","uint8",46,1,SX_NONE),
 SX_FIELD("bits_per_sample","uint8",47,1,SX_NONE),
 SX_FIELD("filename","char[13]",48,13,SX_NONE),
 SX_FIELD("reserved","bytes",61,3,SX_RESERVED),
};
static const sx_layout sxnextm_dtm_sample={UINT32_C(0x608B001C),"dtm_sample",sxnextm_dtm_sample_fields,SX_COUNT(sxnextm_dtm_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_rows_fields[]={
 SX_FIELD("rows","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxnextm_dtm_rows={UINT32_C(0x608B001D),"dtm_rows",sxnextm_dtm_rows_fields,SX_COUNT(sxnextm_dtm_rows_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_pitch_fields[]={
 SX_FIELD("pitch_or_noteoff","uint8",0,1,SX_NONE),
};
static const sx_layout sxnextm_dtm_pitch={UINT32_C(0x608B001E),"dtm_pitch",sxnextm_dtm_pitch_fields,SX_COUNT(sxnextm_dtm_pitch_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_instrument_fields[]={
 SX_FIELD("instrument","uint8",0,1,SX_ID),
};
static const sx_layout sxnextm_dtm_instrument={UINT32_C(0x608B001F),"dtm_instrument",sxnextm_dtm_instrument_fields,SX_COUNT(sxnextm_dtm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_volume_fields[]={
 SX_FIELD("volume_plus_one","uint8",0,1,SX_NONE),
};
static const sx_layout sxnextm_dtm_volume={UINT32_C(0x608B0020),"dtm_volume",sxnextm_dtm_volume_fields,SX_COUNT(sxnextm_dtm_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_effect_fields[]={
 SX_FIELD("effect_plus_one","uint8",0,1,SX_ID),
};
static const sx_layout sxnextm_dtm_effect={UINT32_C(0x608B0021),"dtm_effect",sxnextm_dtm_effect_fields,SX_COUNT(sxnextm_dtm_effect_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_argument_high_fields[]={
 SX_FIELD("argument_high","uint8",0,1,SX_NONE),
};
static const sx_layout sxnextm_dtm_argument_high={UINT32_C(0x608B0022),"dtm_argument_high",sxnextm_dtm_argument_high_fields,SX_COUNT(sxnextm_dtm_argument_high_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_argument_low_fields[]={
 SX_FIELD("argument_low","uint8",0,1,SX_NONE),
};
static const sx_layout sxnextm_dtm_argument_low={UINT32_C(0x608B0023),"dtm_argument_low",sxnextm_dtm_argument_low_fields,SX_COUNT(sxnextm_dtm_argument_low_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ftm_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("samples","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("measures","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("tempo_timer","uint16",8,2,SX_NONE),
 SX_FIELD("tonality","uint8",10,1,SX_ID),
 SX_FIELD("channel_enable_mask","uint8",11,1,SX_FLAGS),
 SX_FIELD("global_volume","uint8",12,1,SX_NONE),
 SX_FIELD("flags","uint8",13,1,SX_FLAGS),
 SX_FIELD("ticks_per_row","uint8",14,1,SX_NONE),
 SX_FIELD("rows_per_measure","uint8",15,1,SX_COUNT_PROP),
 SX_FIELD("title","char[32]",16,32,SX_NONE),
 SX_FIELD("artist","char[32]",48,32,SX_NONE),
 SX_FIELD("effects","uint8",80,1,SX_COUNT_PROP),
 SX_FIELD("padding","uint8",81,1,SX_RESERVED),
};
static const sx_layout sxnextm_ftm_header={UINT32_C(0x608B0024),"ftm_header",sxnextm_ftm_header_fields,SX_COUNT(sxnextm_ftm_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_ftm_sample_fields[]={
 SX_FIELD("name","char[30]",0,30,SX_NONE),
 SX_FIELD("unknown","uint8",30,1,SX_NONE),
 SX_FIELD("iff_octave","uint8",31,1,SX_NONE),
};
static const sx_layout sxnextm_ftm_sample={UINT32_C(0x608B0025),"ftm_sample",sxnextm_ftm_sample_fields,SX_COUNT(sxnextm_ftm_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ftm_script_header_fields[]={
 SX_FIELD("script_lines","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("effect_index","uint16",2,2,SX_ID),
};
static const sx_layout sxnextm_ftm_script_header={UINT32_C(0x608B0026),"ftm_script_header",sxnextm_ftm_script_header_fields,SX_COUNT(sxnextm_ftm_script_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_ftm_script_event_fields[]={
 SX_FIELD("command","uint8",0,1,SX_ID),
 SX_FIELD("argument","uint24",1,3,SX_NONE),
};
static const sx_layout sxnextm_ftm_script_event={UINT32_C(0x608B0027),"ftm_script_event",sxnextm_ftm_script_event_fields,SX_COUNT(sxnextm_ftm_script_event_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_eup_header_fields[]={
 SX_FIELD("title","char[32]",0,32,SX_NONE),
 SX_FIELD("artist","char[8]",32,8,SX_NONE),
 SX_FIELD("unknown","bytes",40,44,SX_NONE),
};
static const sx_layout sxnextm_eup_header={UINT32_C(0x608B0028),"eup_header",sxnextm_eup_header_fields,SX_COUNT(sxnextm_eup_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_track_name_fields[]={
 SX_FIELD("name","char[16]",0,16,SX_NONE),
};
static const sx_layout sxnextm_eup_track_name={UINT32_C(0x608B0029),"eup_track_name",sxnextm_eup_track_name_fields,SX_COUNT(sxnextm_eup_track_name_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_short_name_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_NONE),
};
static const sx_layout sxnextm_eup_short_name={UINT32_C(0x608B002A),"eup_short_name",sxnextm_eup_short_name_fields,SX_COUNT(sxnextm_eup_short_name_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_mute_fields[]={
 SX_FIELD("mute","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxnextm_eup_mute={UINT32_C(0x608B002B),"eup_mute",sxnextm_eup_mute_fields,SX_COUNT(sxnextm_eup_mute_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_port_fields[]={
 SX_FIELD("port","uint8",0,1,SX_ID),
};
static const sx_layout sxnextm_eup_port={UINT32_C(0x608B002C),"eup_port",sxnextm_eup_port_fields,SX_COUNT(sxnextm_eup_port_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_channel_fields[]={
 SX_FIELD("midi_channel","uint8",0,1,SX_ID),
};
static const sx_layout sxnextm_eup_channel={UINT32_C(0x608B002D),"eup_channel",sxnextm_eup_channel_fields,SX_COUNT(sxnextm_eup_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_key_bias_fields[]={
 SX_FIELD("key_bias","int8",0,1,SX_NONE),
};
static const sx_layout sxnextm_eup_key_bias={UINT32_C(0x608B002E),"eup_key_bias",sxnextm_eup_key_bias_fields,SX_COUNT(sxnextm_eup_key_bias_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_transpose_fields[]={
 SX_FIELD("transpose","int8",0,1,SX_NONE),
};
static const sx_layout sxnextm_eup_transpose={UINT32_C(0x608B002F),"eup_transpose",sxnextm_eup_transpose_fields,SX_COUNT(sxnextm_eup_transpose_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_filter_fields[]={
 SX_FIELD("filter_bytes","bytes",0,7,SX_NONE),
};
static const sx_layout sxnextm_eup_filter={UINT32_C(0x608B0030),"eup_filter",sxnextm_eup_filter_fields,SX_COUNT(sxnextm_eup_filter_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_instrument_name_fields[]={
 SX_FIELD("name","char[4]",0,4,SX_NONE),
};
static const sx_layout sxnextm_eup_instrument_name={UINT32_C(0x608B0031),"eup_instrument_name",sxnextm_eup_instrument_name_fields,SX_COUNT(sxnextm_eup_instrument_name_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_bank_names_fields[]={
 SX_FIELD("fm_bank_name","char[8]",0,8,SX_NONE),
 SX_FIELD("pcm_bank_name","char[8]",8,8,SX_NONE),
};
static const sx_layout sxnextm_eup_bank_names={UINT32_C(0x608B0032),"eup_bank_names",sxnextm_eup_bank_names_fields,SX_COUNT(sxnextm_eup_bank_names_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_application_fields[]={
 SX_FIELD("application_name","char[8]",0,8,SX_NONE),
 SX_FIELD("application_version","char[2]",8,2,SX_NONE),
};
static const sx_layout sxnextm_eup_application={UINT32_C(0x608B0033),"eup_application",sxnextm_eup_application_fields,SX_COUNT(sxnextm_eup_application_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_eup_event_header_fields[]={
 SX_FIELD("event_bytes","int32",0,4,SX_SIZE),
 SX_FIELD("marker","uint8",4,1,SX_ID),
 SX_FIELD("initial_tempo","uint8",5,1,SX_NONE),
};
static const sx_layout sxnextm_eup_event_header={UINT32_C(0x608B0034),"eup_event_header",sxnextm_eup_event_header_fields,SX_COUNT(sxnextm_eup_event_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_syn_header_fields[]={
 SX_FIELD("signature","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("positions","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("track_rows","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("unknown0","bytes",12,4,SX_NONE),
 SX_FIELD("samples","uint8",16,1,SX_COUNT_PROP),
 SX_FIELD("waveforms","uint8",17,1,SX_COUNT_PROP),
 SX_FIELD("instruments","uint8",18,1,SX_COUNT_PROP),
 SX_FIELD("subsongs","uint8",19,1,SX_COUNT_PROP),
 SX_FIELD("envelope_tables","uint8",20,1,SX_COUNT_PROP),
 SX_FIELD("adsr_tables","uint8",21,1,SX_COUNT_PROP),
 SX_FIELD("noise_length","uint8",22,1,SX_NONE),
 SX_FIELD("unknown1","bytes",23,13,SX_NONE),
 SX_FIELD("title","char[28]",36,28,SX_NONE),
 SX_FIELD("unused_text","char[140]",64,140,SX_NONE),
};
static const sx_layout sxnextm_syn_header={UINT32_C(0x608B0035),"syn_header",sxnextm_syn_header_fields,SX_COUNT(sxnextm_syn_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_syn_sample_name_fields[]={
 SX_FIELD("unknown","uint8",0,1,SX_NONE),
 SX_FIELD("name","char[27]",1,27,SX_NONE),
};
static const sx_layout sxnextm_syn_sample_name={UINT32_C(0x608B0036),"syn_sample_name",sxnextm_syn_sample_name_fields,SX_COUNT(sxnextm_syn_sample_name_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_syn_instrument_fields[]={
 SX_FIELD("waveform","uint8",0,1,SX_ID),
 SX_FIELD("synthesis","uint8",1,1,SX_FLAGS),
 SX_FIELD("waveform_length","uint16",2,2,SX_NONE),
 SX_FIELD("repeat_length","uint16",4,2,SX_NONE),
 SX_FIELD("volume","uint8",6,1,SX_NONE),
 SX_FIELD("portamento_speed","int8",7,1,SX_NONE),
 SX_FIELD("adsr_enabled","uint8",8,1,SX_FLAGS),
 SX_FIELD("adsr_table","uint8",9,1,SX_ID),
 SX_FIELD("adsr_length","uint16",10,2,SX_NONE),
 SX_FIELD("unknown","uint8",12,1,SX_NONE),
 SX_FIELD("arpeggio_start","uint8",13,1,SX_NONE),
 SX_FIELD("arpeggio_length","uint8",14,1,SX_NONE),
 SX_FIELD("arpeggio_repeat_length","uint8",15,1,SX_NONE),
 SX_FIELD("effect","uint8",16,1,SX_ID),
 SX_FIELD("argument1","uint8",17,1,SX_NONE),
 SX_FIELD("argument2","uint8",18,1,SX_NONE),
 SX_FIELD("argument3","uint8",19,1,SX_NONE),
 SX_FIELD("vibrato_delay","uint8",20,1,SX_NONE),
 SX_FIELD("vibrato_speed","uint8",21,1,SX_NONE),
 SX_FIELD("vibrato_level","uint8",22,1,SX_NONE),
 SX_FIELD("envelope_counter_offset","uint8",23,1,SX_NONE),
 SX_FIELD("envelope_counter_mode","uint8",24,1,SX_ID),
 SX_FIELD("envelope_table","uint8",25,1,SX_ID),
 SX_FIELD("envelope_table_length","uint16",26,2,SX_NONE),
};
static const sx_layout sxnextm_syn_instrument={UINT32_C(0x608B0037),"syn_instrument",sxnextm_syn_instrument_fields,SX_COUNT(sxnextm_syn_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_syn_subsong_fields[]={
 SX_FIELD("unknown0","bytes",0,4,SX_NONE),
 SX_FIELD("speed","uint8",4,1,SX_NONE),
 SX_FIELD("rows_per_track","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("first_position","uint16",6,2,SX_ID),
 SX_FIELD("last_position","uint16",8,2,SX_ID),
 SX_FIELD("restart_position","uint16",10,2,SX_ID),
 SX_FIELD("unknown_tail","bytes",12,2,SX_NONE),
};
static const sx_layout sxnextm_syn_subsong={UINT32_C(0x608B0038),"syn_subsong",sxnextm_syn_subsong_fields,SX_COUNT(sxnextm_syn_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_syn_position_fields[]={
 SX_FIELD("first_track_row","uint16",0,2,SX_ID),
 SX_FIELD("instrument_transpose","int8",2,1,SX_NONE),
 SX_FIELD("note_transpose","int8",3,1,SX_NONE),
};
static const sx_layout sxnextm_syn_position={UINT32_C(0x608B0039),"syn_position",sxnextm_syn_position_fields,SX_COUNT(sxnextm_syn_position_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_syn_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("arpeggio_and_effect","uint8",2,1,SX_FLAGS),
 SX_FIELD("argument","uint8",3,1,SX_NONE),
};
static const sx_layout sxnextm_syn_event={UINT32_C(0x608B003A),"syn_event",sxnextm_syn_event_fields,SX_COUNT(sxnextm_syn_event_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_d00_header_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("speed","uint8",1,1,SX_NONE),
 SX_FIELD("subsongs","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("track_table_offset","uint16",3,2,SX_OFFSET),
 SX_FIELD("sequence_table_offset","uint16",5,2,SX_OFFSET),
 SX_FIELD("instrument_table_offset","uint16",7,2,SX_OFFSET),
 SX_FIELD("information_offset","uint16",9,2,SX_OFFSET),
};
static const sx_layout sxnextm_d00_header={UINT32_C(0x608B003B),"d00_header",sxnextm_d00_header_fields,SX_COUNT(sxnextm_d00_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_offset16le_fields[]={
 SX_FIELD("offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxnextm_offset16le={UINT32_C(0x608B003C),"offset16le",sxnextm_offset16le_fields,SX_COUNT(sxnextm_offset16le_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_offset32le_fields[]={
 SX_FIELD("offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxnextm_offset32le={UINT32_C(0x608B003D),"offset32le",sxnextm_offset32le_fields,SX_COUNT(sxnextm_offset32le_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_offset32be_fields[]={
 SX_FIELD("offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxnextm_offset32be={UINT32_C(0x608B003E),"offset32be",sxnextm_offset32be_fields,SX_COUNT(sxnextm_offset32be_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_d00_end_fields[]={
 SX_FIELD("end_marker","uint16",0,2,SX_ID),
};
static const sx_layout sxnextm_d00_end={UINT32_C(0x608B003F),"d00_end",sxnextm_d00_end_fields,SX_COUNT(sxnextm_d00_end_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_d00_tracks_fields[]={
 SX_FIELD("channel0_order_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("channel1_order_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("channel2_order_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("channel3_order_offset","uint16",6,2,SX_OFFSET),
 SX_FIELD("channel4_order_offset","uint16",8,2,SX_OFFSET),
 SX_FIELD("channel5_order_offset","uint16",10,2,SX_OFFSET),
 SX_FIELD("channel6_order_offset","uint16",12,2,SX_OFFSET),
 SX_FIELD("channel7_order_offset","uint16",14,2,SX_OFFSET),
 SX_FIELD("channel8_order_offset","uint16",16,2,SX_OFFSET),
 SX_FIELD("channel0_volume","uint8",18,1,SX_NONE),
 SX_FIELD("channel1_volume","uint8",19,1,SX_NONE),
 SX_FIELD("channel2_volume","uint8",20,1,SX_NONE),
 SX_FIELD("channel3_volume","uint8",21,1,SX_NONE),
 SX_FIELD("channel4_volume","uint8",22,1,SX_NONE),
 SX_FIELD("channel5_volume","uint8",23,1,SX_NONE),
 SX_FIELD("channel6_volume","uint8",24,1,SX_NONE),
 SX_FIELD("channel7_volume","uint8",25,1,SX_NONE),
 SX_FIELD("channel8_volume","uint8",26,1,SX_NONE),
 SX_FIELD("unknown","bytes",27,5,SX_NONE),
};
static const sx_layout sxnextm_d00_tracks={UINT32_C(0x608B0040),"d00_tracks",sxnextm_d00_tracks_fields,SX_COUNT(sxnextm_d00_tracks_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_d00_speed_fields[]={
 SX_FIELD("track_speed","uint16",0,2,SX_NONE),
};
static const sx_layout sxnextm_d00_speed={UINT32_C(0x608B0041),"d00_speed",sxnextm_d00_speed_fields,SX_COUNT(sxnextm_d00_speed_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("title","char[28]",4,28,SX_NONE),
 SX_FIELD("composer","char[28]",32,28,SX_NONE),
 SX_FIELD("marker","uint8",60,1,SX_ID),
 SX_FIELD("file_type","uint8",61,1,SX_ID),
 SX_FIELD("global_setting","uint8",62,1,SX_NONE),
 SX_FIELD("base_refresh_hz","uint8",63,1,SX_NONE),
 SX_FIELD("initial_ticks","uint8",64,1,SX_NONE),
 SX_FIELD("unknown","bytes",65,9,SX_NONE),
 SX_FIELD("order_count","uint8",74,1,SX_COUNT_PROP),
 SX_FIELD("instruments","uint8",75,1,SX_COUNT_PROP),
 SX_FIELD("patterns","uint8",76,1,SX_COUNT_PROP),
 SX_FIELD("packed_pan","bytes",77,5,SX_FLAGS),
};
static const sx_layout sxnextm_fmk_header={UINT32_C(0x608B0042),"fmk_header",sxnextm_fmk_header_fields,SX_COUNT(sxnextm_fmk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_track_setting_fields[]={
 SX_FIELD("type_and_opl_channel","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxnextm_fmk_track_setting={UINT32_C(0x608B0043),"fmk_track_setting",sxnextm_fmk_track_setting_fields,SX_COUNT(sxnextm_fmk_track_setting_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_instrument_fields[]={
 SX_FIELD("unknown","bytes",0,39,SX_NONE),
 SX_FIELD("opl_20","uint8",39,1,SX_FLAGS),
 SX_FIELD("opl_23","uint8",40,1,SX_FLAGS),
 SX_FIELD("opl_40","uint8",41,1,SX_FLAGS),
 SX_FIELD("opl_43","uint8",42,1,SX_FLAGS),
 SX_FIELD("opl_60","uint8",43,1,SX_FLAGS),
 SX_FIELD("opl_63","uint8",44,1,SX_FLAGS),
 SX_FIELD("opl_80","uint8",45,1,SX_FLAGS),
 SX_FIELD("opl_83","uint8",46,1,SX_FLAGS),
 SX_FIELD("opl_e0","uint8",47,1,SX_FLAGS),
 SX_FIELD("opl_e3","uint8",48,1,SX_FLAGS),
 SX_FIELD("opl_c0","uint8",49,1,SX_FLAGS),
};
static const sx_layout sxnextm_fmk_instrument={UINT32_C(0x608B0044),"fmk_instrument",sxnextm_fmk_instrument_fields,SX_COUNT(sxnextm_fmk_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_pattern_fields[]={
 SX_FIELD("encoded_bytes","uint16",0,2,SX_SIZE),
};
static const sx_layout sxnextm_fmk_pattern={UINT32_C(0x608B0045),"fmk_pattern",sxnextm_fmk_pattern_fields,SX_COUNT(sxnextm_fmk_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_control_fields[]={
 SX_FIELD("track_and_fields","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxnextm_fmk_control={UINT32_C(0x608B0046),"fmk_control",sxnextm_fmk_control_fields,SX_COUNT(sxnextm_fmk_control_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_note_fields[]={
 SX_FIELD("packed_note","uint8",0,1,SX_FLAGS),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
};
static const sx_layout sxnextm_fmk_note={UINT32_C(0x608B0047),"fmk_note",sxnextm_fmk_note_fields,SX_COUNT(sxnextm_fmk_note_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_volume_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
};
static const sx_layout sxnextm_fmk_volume={UINT32_C(0x608B0048),"fmk_volume",sxnextm_fmk_volume_fields,SX_COUNT(sxnextm_fmk_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_effect_fields[]={
 SX_FIELD("effect","uint8",0,1,SX_ID),
 SX_FIELD("argument","uint8",1,1,SX_NONE),
};
static const sx_layout sxnextm_fmk_effect={UINT32_C(0x608B0049),"fmk_effect",sxnextm_fmk_effect_fields,SX_COUNT(sxnextm_fmk_effect_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_sct_header_fields[]={
 SX_FIELD("title","char[16]",0,16,SX_NONE),
 SX_FIELD("track_section_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("sample_section_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("position_section_bytes","uint32",24,4,SX_SIZE),
 SX_FIELD("instrument_section_bytes","uint32",28,4,SX_SIZE),
 SX_FIELD("format_word","uint16",32,2,SX_ID),
 SX_FIELD("speed","uint16",34,2,SX_NONE),
 SX_FIELD("unknown","bytes",36,28,SX_NONE),
};
static const sx_layout sxnextm_sct_header={UINT32_C(0x608B004A),"sct_header",sxnextm_sct_header_fields,SX_COUNT(sxnextm_sct_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_sct_track_fields[]={
 SX_FIELD("name","char[16]",0,16,SX_NONE),
};
static const sx_layout sxnextm_sct_track={UINT32_C(0x608B004B),"sct_track",sxnextm_sct_track_fields,SX_COUNT(sxnextm_sct_track_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_sct_position_fields[]={
 SX_FIELD("track_index","uint8",0,1,SX_ID),
 SX_FIELD("ignored","uint8",1,1,SX_NONE),
};
static const sx_layout sxnextm_sct_position={UINT32_C(0x608B004C),"sct_position",sxnextm_sct_position_fields,SX_COUNT(sxnextm_sct_position_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_sct_instrument_fields[]={
 SX_FIELD("name","char[16]",0,16,SX_NONE),
 SX_FIELD("command_bytes","uint16",16,2,SX_SIZE),
 SX_FIELD("attack_speed","uint8",18,1,SX_NONE),
 SX_FIELD("attack_increment","uint8",19,1,SX_NONE),
 SX_FIELD("decay_speed","uint8",20,1,SX_NONE),
 SX_FIELD("decay_decrement","uint8",21,1,SX_NONE),
 SX_FIELD("decay_value","uint16",22,2,SX_NONE),
 SX_FIELD("release_speed","uint8",24,1,SX_NONE),
 SX_FIELD("release_decrement","uint8",25,1,SX_NONE),
 SX_FIELD("unused","bytes",26,22,SX_NONE),
};
static const sx_layout sxnextm_sct_instrument={UINT32_C(0x608B004D),"sct_instrument",sxnextm_sct_instrument_fields,SX_COUNT(sxnextm_sct_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_sct_command_fields[]={
 SX_FIELD("command","uint16",0,2,SX_ID),
 SX_FIELD("argument1","uint16",2,2,SX_NONE),
 SX_FIELD("argument2","uint16",4,2,SX_NONE),
};
static const sx_layout sxnextm_sct_command={UINT32_C(0x608B004E),"sct_command",sxnextm_sct_command_fields,SX_COUNT(sxnextm_sct_command_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_sct_sample_fields[]={
 SX_FIELD("name","char[16]",0,16,SX_NONE),
 SX_FIELD("length_words","uint16",16,2,SX_NONE),
 SX_FIELD("loop_start_words","uint16",18,2,SX_NONE),
 SX_FIELD("loop_end_words","uint16",20,2,SX_NONE),
 SX_FIELD("unknown0","bytes",22,20,SX_NONE),
 SX_FIELD("note_transpose","int16",42,2,SX_NONE),
 SX_FIELD("unknown1","bytes",44,16,SX_NONE),
 SX_FIELD("total_record_bytes","uint32",60,4,SX_SIZE),
};
static const sx_layout sxnextm_sct_sample={UINT32_C(0x608B004F),"sct_sample",sxnextm_sct_sample_fields,SX_COUNT(sxnextm_sct_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_psf_header_fields[]={
 SX_FIELD("module_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxnextm_psf_header={UINT32_C(0x608B0050),"psf_header",sxnextm_psf_header_fields,SX_COUNT(sxnextm_psf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_psf_channels_fields[]={
 SX_FIELD("enabled_channel_mask","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxnextm_psf_channels={UINT32_C(0x608B0051),"psf_channels",sxnextm_psf_channels_fields,SX_COUNT(sxnextm_psf_channels_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_vss_footer_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("subsongs","int32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxnextm_vss_footer={UINT32_C(0x608B0052),"vss_footer",sxnextm_vss_footer_fields,SX_COUNT(sxnextm_vss_footer_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_vss_song_offset_fields[]={
 SX_FIELD("footer_relative_offset","int32",0,4,SX_OFFSET),
};
static const sx_layout sxnextm_vss_song_offset={UINT32_C(0x608B0053),"vss_song_offset",sxnextm_vss_song_offset_fields,SX_COUNT(sxnextm_vss_song_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_vss_data_offset_fields[]={
 SX_FIELD("song_relative_offset","int32",0,4,SX_OFFSET),
};
static const sx_layout sxnextm_vss_data_offset={UINT32_C(0x608B0054),"vss_data_offset",sxnextm_vss_data_offset_fields,SX_COUNT(sxnextm_vss_data_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_mle_magic_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
};
static const sx_layout sxnextm_mle_magic={UINT32_C(0x608B0055),"mle_magic",sxnextm_mle_magic_fields,SX_COUNT(sxnextm_mle_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_mle_tune_fields[]={
 SX_FIELD("title","char[32]",0,32,SX_NONE),
 SX_FIELD("tempo","uint16",32,2,SX_NONE),
 SX_FIELD("speed","uint8",34,1,SX_NONE),
 SX_FIELD("groove","uint8",35,1,SX_NONE),
 SX_FIELD("volume","uint16",36,2,SX_NONE),
 SX_FIELD("mixer_mode","uint8",38,1,SX_FLAGS),
 SX_FIELD("channels","uint8",39,1,SX_COUNT_PROP),
};
static const sx_layout sxnextm_mle_tune={UINT32_C(0x608B0056),"mle_tune",sxnextm_mle_tune_fields,SX_COUNT(sxnextm_mle_tune_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_mle_sequence_fields[]={
 SX_FIELD("part_and_control","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxnextm_mle_sequence={UINT32_C(0x608B0057),"mle_sequence",sxnextm_mle_sequence_fields,SX_COUNT(sxnextm_mle_sequence_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_mle_index_fields[]={
 SX_FIELD("index","uint16",0,2,SX_ID),
};
static const sx_layout sxnextm_mle_index={UINT32_C(0x608B0058),"mle_index",sxnextm_mle_index_fields,SX_COUNT(sxnextm_mle_index_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_mle_part_control_fields[]={
 SX_FIELD("fields_present","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxnextm_mle_part_control={UINT32_C(0x608B0059),"mle_part_control",sxnextm_mle_part_control_fields,SX_COUNT(sxnextm_mle_part_control_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_mle_part_note_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
};
static const sx_layout sxnextm_mle_part_note={UINT32_C(0x608B005A),"mle_part_note",sxnextm_mle_part_note_fields,SX_COUNT(sxnextm_mle_part_note_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_mle_effect_fields[]={
 SX_FIELD("effect","uint8",0,1,SX_ID),
 SX_FIELD("argument","uint8",1,1,SX_NONE),
};
static const sx_layout sxnextm_mle_effect={UINT32_C(0x608B005B),"mle_effect",sxnextm_mle_effect_fields,SX_COUNT(sxnextm_mle_effect_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_mle_arpeggio_fields[]={
 SX_FIELD("note_transpose","int8",0,1,SX_NONE),
 SX_FIELD("sample_index","uint8",1,1,SX_ID),
 SX_FIELD("effect1","uint8",2,1,SX_ID),
 SX_FIELD("argument1","uint8",3,1,SX_NONE),
 SX_FIELD("effect2","uint8",4,1,SX_ID),
 SX_FIELD("argument2","uint8",5,1,SX_NONE),
};
static const sx_layout sxnextm_mle_arpeggio={UINT32_C(0x608B005C),"mle_arpeggio",sxnextm_mle_arpeggio_fields,SX_COUNT(sxnextm_mle_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_mle_sample_fields[]={
 SX_FIELD("decoded_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("delta_command","uint8",4,1,SX_ID),
 SX_FIELD("unknown0","uint8",5,1,SX_NONE),
 SX_FIELD("title","char[32]",6,32,SX_NONE),
 SX_FIELD("unknown1","uint8",38,1,SX_NONE),
 SX_FIELD("sample_type","uint8",39,1,SX_ID),
 SX_FIELD("stored_sample_pointer","uint32",40,4,SX_POINTER),
 SX_FIELD("length_words","uint16",44,2,SX_NONE),
 SX_FIELD("stored_repeat_pointer","uint32",46,4,SX_POINTER),
 SX_FIELD("repeat_words","uint16",50,2,SX_NONE),
 SX_FIELD("fine_tune","int16",52,2,SX_NONE),
 SX_FIELD("semitone","int16",54,2,SX_NONE),
};
static const sx_layout sxnextm_mle_sample={UINT32_C(0x608B005D),"mle_sample",sxnextm_mle_sample_fields,SX_COUNT(sxnextm_mle_sample_fields),SX_BE};
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
static const sx_layout sxnextm_mle_instrument={UINT32_C(0x608B005E),"mle_instrument",sxnextm_mle_instrument_fields,SX_COUNT(sxnextm_mle_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_puma_header_fields[]={
 SX_FIELD("title","char[12]",0,12,SX_NONE),
 SX_FIELD("last_position","uint16",12,2,SX_NONE),
 SX_FIELD("tracks","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("instruments","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("unknown","uint16",18,2,SX_NONE),
 SX_FIELD("sample0_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("sample1_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("sample2_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("sample3_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("sample4_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("sample5_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("sample6_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("sample7_offset","uint32",48,4,SX_OFFSET),
 SX_FIELD("sample8_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("sample9_offset","uint32",56,4,SX_OFFSET),
 SX_FIELD("sample0_words_plus_one","uint16",60,2,SX_NONE),
 SX_FIELD("sample1_words_plus_one","uint16",62,2,SX_NONE),
 SX_FIELD("sample2_words_plus_one","uint16",64,2,SX_NONE),
 SX_FIELD("sample3_words_plus_one","uint16",66,2,SX_NONE),
 SX_FIELD("sample4_words_plus_one","uint16",68,2,SX_NONE),
 SX_FIELD("sample5_words_plus_one","uint16",70,2,SX_NONE),
 SX_FIELD("sample6_words_plus_one","uint16",72,2,SX_NONE),
 SX_FIELD("sample7_words_plus_one","uint16",74,2,SX_NONE),
 SX_FIELD("sample8_words_plus_one","uint16",76,2,SX_NONE),
 SX_FIELD("sample9_words_plus_one","uint16",78,2,SX_NONE),
};
static const sx_layout sxnextm_puma_header={UINT32_C(0x608B005F),"puma_header",sxnextm_puma_header_fields,SX_COUNT(sxnextm_puma_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_puma_position_fields[]={
 SX_FIELD("channel0_track","uint8",0,1,SX_ID),
 SX_FIELD("channel0_instrument_transpose","int8",1,1,SX_NONE),
 SX_FIELD("channel0_note_transpose","int8",2,1,SX_NONE),
 SX_FIELD("channel1_track","uint8",3,1,SX_ID),
 SX_FIELD("channel1_instrument_transpose","int8",4,1,SX_NONE),
 SX_FIELD("channel1_note_transpose","int8",5,1,SX_NONE),
 SX_FIELD("channel2_track","uint8",6,1,SX_ID),
 SX_FIELD("channel2_instrument_transpose","int8",7,1,SX_NONE),
 SX_FIELD("channel2_note_transpose","int8",8,1,SX_NONE),
 SX_FIELD("channel3_track","uint8",9,1,SX_ID),
 SX_FIELD("channel3_instrument_transpose","int8",10,1,SX_NONE),
 SX_FIELD("channel3_note_transpose","int8",11,1,SX_NONE),
 SX_FIELD("speed","uint8",12,1,SX_NONE),
 SX_FIELD("unknown","uint8",13,1,SX_NONE),
};
static const sx_layout sxnextm_puma_position={UINT32_C(0x608B0060),"puma_position",sxnextm_puma_position_fields,SX_COUNT(sxnextm_puma_position_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_puma_marker_fields[]={
 SX_FIELD("marker","bytes",0,4,SX_ID),
};
static const sx_layout sxnextm_puma_marker={UINT32_C(0x608B0061),"puma_marker",sxnextm_puma_marker_fields,SX_COUNT(sxnextm_puma_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_puma_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument_and_effect","uint8",1,1,SX_FLAGS),
 SX_FIELD("argument","uint8",2,1,SX_NONE),
 SX_FIELD("rows_to_wait","uint8",3,1,SX_COUNT_PROP),
};
static const sx_layout sxnextm_puma_event={UINT32_C(0x608B0062),"puma_event",sxnextm_puma_event_fields,SX_COUNT(sxnextm_puma_event_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_puma_command_fields[]={
 SX_FIELD("command","uint8",0,1,SX_ID),
 SX_FIELD("argument1","uint8",1,1,SX_NONE),
 SX_FIELD("argument2","uint8",2,1,SX_NONE),
 SX_FIELD("argument3","uint8",3,1,SX_NONE),
};
static const sx_layout sxnextm_puma_command={UINT32_C(0x608B0063),"puma_command",sxnextm_puma_command_fields,SX_COUNT(sxnextm_puma_command_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ma_relative32_fields[]={
 SX_FIELD("module_relative_offset","int32",0,4,SX_OFFSET),
};
static const sx_layout sxnextm_ma_relative32={UINT32_C(0x608B0064),"ma_relative32",sxnextm_ma_relative32_fields,SX_COUNT(sxnextm_ma_relative32_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_ma_track_offset_fields[]={
 SX_FIELD("track_data_relative_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxnextm_ma_track_offset={UINT32_C(0x608B0065),"ma_track_offset",sxnextm_ma_track_offset_fields,SX_COUNT(sxnextm_ma_track_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_ma_subsong_fields[]={
 SX_FIELD("voice0_position_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("voice1_position_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("voice2_position_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("voice3_position_offset","uint16",6,2,SX_OFFSET),
};
static const sx_layout sxnextm_ma_subsong={UINT32_C(0x608B0066),"ma_subsong",sxnextm_ma_subsong_fields,SX_COUNT(sxnextm_ma_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_ma_position_fields[]={
 SX_FIELD("track_number","uint8",0,1,SX_ID),
 SX_FIELD("transpose_and_repeat","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxnextm_ma_position={UINT32_C(0x608B0067),"ma_position",sxnextm_ma_position_fields,SX_COUNT(sxnextm_ma_position_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ma_speed_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
};
static const sx_layout sxnextm_ma_speed={UINT32_C(0x608B0068),"ma_speed",sxnextm_ma_speed_fields,SX_COUNT(sxnextm_ma_speed_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ma_instrument_fields[]={
 SX_FIELD("sample_number","uint8",0,1,SX_ID),
 SX_FIELD("attack","uint8",1,1,SX_NONE),
 SX_FIELD("decay_sustain","uint8",2,1,SX_FLAGS),
 SX_FIELD("vibrato_delay","uint8",3,1,SX_NONE),
 SX_FIELD("release","uint8",4,1,SX_NONE),
 SX_FIELD("vibrato_speed","uint8",5,1,SX_NONE),
 SX_FIELD("vibrato_level","uint8",6,1,SX_NONE),
 SX_FIELD("arpeggio","uint8",7,1,SX_FLAGS),
 SX_FIELD("fx_arpeggio_speed_loop","uint8",8,1,SX_FLAGS),
 SX_FIELD("hold","uint8",9,1,SX_NONE),
 SX_FIELD("key_wave_rate","uint8",10,1,SX_FLAGS),
 SX_FIELD("wave_level_speed","uint8",11,1,SX_FLAGS),
 SX_FIELD("unknown","bytes",12,4,SX_NONE),
};
static const sx_layout sxnextm_ma_instrument={UINT32_C(0x608B0069),"ma_instrument",sxnextm_ma_instrument_fields,SX_COUNT(sxnextm_ma_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ma_sample_fields[]={
 SX_FIELD("sample_info_relative_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("length_words","uint16",4,2,SX_NONE),
 SX_FIELD("loop_length_words","uint16",6,2,SX_NONE),
 SX_FIELD("name","char[16]",8,16,SX_NONE),
};
static const sx_layout sxnextm_ma_sample={UINT32_C(0x608B006A),"ma_sample",sxnextm_ma_sample_fields,SX_COUNT(sxnextm_ma_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_final_header_fields[]={
 SX_FIELD("played_song","uint8",0,1,SX_ID),
 SX_FIELD("last_subsong_index","uint8",1,1,SX_ID),
 SX_FIELD("current_tempo","uint8",2,1,SX_NONE),
 SX_FIELD("subsong0_start_tempo","uint8",3,1,SX_NONE),
 SX_FIELD("subsong1_start_tempo","uint8",4,1,SX_NONE),
 SX_FIELD("subsong2_start_tempo","uint8",5,1,SX_NONE),
 SX_FIELD("subsong3_start_tempo","uint8",6,1,SX_NONE),
 SX_FIELD("subsong4_start_tempo","uint8",7,1,SX_NONE),
 SX_FIELD("subsong5_start_tempo","uint8",8,1,SX_NONE),
 SX_FIELD("subsong6_start_tempo","uint8",9,1,SX_NONE),
 SX_FIELD("subsong7_start_tempo","uint8",10,1,SX_NONE),
 SX_FIELD("subsong8_start_tempo","uint8",11,1,SX_NONE),
 SX_FIELD("subsong9_start_tempo","uint8",12,1,SX_NONE),
 SX_FIELD("unknown","uint8",13,1,SX_NONE),
 SX_FIELD("instrument_offset","uint32",14,4,SX_OFFSET),
 SX_FIELD("track_offset","uint32",18,4,SX_OFFSET),
};
static const sx_layout sxnextm_fred_final_header={UINT32_C(0x608B006B),"fred_final_header",sxnextm_fred_final_header_fields,SX_COUNT(sxnextm_fred_final_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_final_subsong_fields[]={
 SX_FIELD("voice0_sequence_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("voice1_sequence_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("voice2_sequence_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("voice3_sequence_offset","uint16",6,2,SX_OFFSET),
};
static const sx_layout sxnextm_fred_final_subsong={UINT32_C(0x608B006C),"fred_final_subsong",sxnextm_fred_final_subsong_fields,SX_COUNT(sxnextm_fred_final_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_final_position_fields[]={
 SX_FIELD("track_offset","int16",0,2,SX_OFFSET),
};
static const sx_layout sxnextm_fred_final_position={UINT32_C(0x608B006D),"fred_final_position",sxnextm_fred_final_position_fields,SX_COUNT(sxnextm_fred_final_position_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_final_control_fields[]={
 SX_FIELD("sequence_control","int16",0,2,SX_NONE),
};
static const sx_layout sxnextm_fred_final_control={UINT32_C(0x608B006E),"fred_final_control",sxnextm_fred_final_control_fields,SX_COUNT(sxnextm_fred_final_control_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_final_instrument_fields[]={
 SX_FIELD("sample_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("repeat_start","uint16",4,2,SX_OFFSET),
 SX_FIELD("length_words","uint16",6,2,SX_NONE),
 SX_FIELD("period","uint16",8,2,SX_NONE),
 SX_FIELD("vibrato_delay","uint8",10,1,SX_NONE),
 SX_FIELD("unknown0","uint8",11,1,SX_NONE),
 SX_FIELD("vibrato_speed","int8",12,1,SX_NONE),
 SX_FIELD("vibrato_amplitude","int8",13,1,SX_NONE),
 SX_FIELD("envelope_volume","uint8",14,1,SX_NONE),
 SX_FIELD("attack_speed","uint8",15,1,SX_NONE),
 SX_FIELD("attack_volume","uint8",16,1,SX_NONE),
 SX_FIELD("decay_speed","uint8",17,1,SX_NONE),
 SX_FIELD("decay_volume","uint8",18,1,SX_NONE),
 SX_FIELD("sustain_delay","uint8",19,1,SX_NONE),
 SX_FIELD("release_speed","uint8",20,1,SX_NONE),
 SX_FIELD("release_volume","uint8",21,1,SX_NONE),
 SX_FIELD("arpeggio0","int8",22,1,SX_NONE),
 SX_FIELD("arpeggio1","int8",23,1,SX_NONE),
 SX_FIELD("arpeggio2","int8",24,1,SX_NONE),
 SX_FIELD("arpeggio3","int8",25,1,SX_NONE),
 SX_FIELD("arpeggio4","int8",26,1,SX_NONE),
 SX_FIELD("arpeggio5","int8",27,1,SX_NONE),
 SX_FIELD("arpeggio6","int8",28,1,SX_NONE),
 SX_FIELD("arpeggio7","int8",29,1,SX_NONE),
 SX_FIELD("arpeggio8","int8",30,1,SX_NONE),
 SX_FIELD("arpeggio9","int8",31,1,SX_NONE),
 SX_FIELD("arpeggio10","int8",32,1,SX_NONE),
 SX_FIELD("arpeggio11","int8",33,1,SX_NONE),
 SX_FIELD("arpeggio12","int8",34,1,SX_NONE),
 SX_FIELD("arpeggio13","int8",35,1,SX_NONE),
 SX_FIELD("arpeggio14","int8",36,1,SX_NONE),
 SX_FIELD("arpeggio15","int8",37,1,SX_NONE),
 SX_FIELD("arpeggio_speed","uint8",38,1,SX_NONE),
 SX_FIELD("instrument_type","uint8",39,1,SX_ID),
 SX_FIELD("pulse_rate_min","int8",40,1,SX_NONE),
 SX_FIELD("pulse_rate_plus","int8",41,1,SX_NONE),
 SX_FIELD("pulse_speed","uint8",42,1,SX_NONE),
 SX_FIELD("pulse_start","uint8",43,1,SX_NONE),
 SX_FIELD("pulse_end","uint8",44,1,SX_NONE),
 SX_FIELD("pulse_delay","uint8",45,1,SX_NONE),
 SX_FIELD("synchronization","uint8",46,1,SX_FLAGS),
 SX_FIELD("blend","uint8",47,1,SX_NONE),
 SX_FIELD("blend_delay","uint8",48,1,SX_NONE),
 SX_FIELD("pulse_shot_counter","uint8",49,1,SX_NONE),
 SX_FIELD("blend_shot_counter","uint8",50,1,SX_NONE),
 SX_FIELD("arpeggio_count","uint8",51,1,SX_NONE),
 SX_FIELD("unknown_tail","bytes",52,12,SX_NONE),
};
static const sx_layout sxnextm_fred_final_instrument={UINT32_C(0x608B006F),"fred_final_instrument",sxnextm_fred_final_instrument_fields,SX_COUNT(sxnextm_fred_final_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_sid1_base_offset_fields[]={
 SX_FIELD("player_base_relative_offset","int32",0,4,SX_OFFSET),
};
static const sx_layout sxnextm_sid1_base_offset={UINT32_C(0x608B0070),"sid1_base_offset",sxnextm_sid1_base_offset_fields,SX_COUNT(sxnextm_sid1_base_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_sid1_song_fields[]={
 SX_FIELD("mix1_source1","uint32",0,4,SX_ID),
 SX_FIELD("mix2_source1","uint32",4,4,SX_ID),
 SX_FIELD("mix1_source2","uint32",8,4,SX_ID),
 SX_FIELD("mix2_source2","uint32",12,4,SX_ID),
 SX_FIELD("mix1_destination","uint32",16,4,SX_ID),
 SX_FIELD("mix2_destination","uint32",20,4,SX_ID),
 SX_FIELD("initial_rows","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("positions_plus_one","uint32",28,4,SX_NONE),
 SX_FIELD("initial_speed","uint32",32,4,SX_NONE),
 SX_FIELD("mix1_speed","uint32",36,4,SX_NONE),
 SX_FIELD("mix2_speed","uint32",40,4,SX_NONE),
};
static const sx_layout sxnextm_sid1_song={UINT32_C(0x608B0071),"sid1_song",sxnextm_sid1_song_fields,SX_COUNT(sxnextm_sid1_song_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_sid1_sequence_fields[]={
 SX_FIELD("track_number","uint32",0,4,SX_ID),
 SX_FIELD("unknown","uint8",4,1,SX_NONE),
 SX_FIELD("note_transpose","int8",5,1,SX_NONE),
};
static const sx_layout sxnextm_sid1_sequence={UINT32_C(0x608B0072),"sid1_sequence",sxnextm_sid1_sequence_fields,SX_COUNT(sxnextm_sid1_sequence_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_mle_tune_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("declared_payload_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxnextm_mle_tune_chunk={UINT32_C(0x608B0073),"mle_tune_chunk",sxnextm_mle_tune_chunk_fields,SX_COUNT(sxnextm_mle_tune_chunk_fields),SX_BE};
static const sx_layout *const sx_nextmusic_layouts[]={
 &sxnextm_text,
 &sxnextm_u8,
 &sxnextm_i8,
 &sxnextm_count16,
 &sxnextm_offset16,
 &sxnextm_bytes32,
 &sxnextm_track16,
 &sxnextm_order8,
 &sxnextm_chunk_le,
 &sxnextm_chunk_be,
 &sxnextm_ast_header,
 &sxnextm_ast_banner,
 &sxnextm_ast_module_size,
 &sxnextm_ast_instrument,
 &sxnextm_ast_subsong,
 &sxnextm_ast_sample,
 &sxnextm_dss_header,
 &sxnextm_dss_sample,
 &sxnextm_dss_event,
 &sxnextm_fred_header,
 &sxnextm_fred_track_length,
 &sxnextm_fred_instrument,
 &sxnextm_fred_sample,
 &sxnextm_fred_end,
 &sxnextm_dtm_info,
 &sxnextm_dtm_speed,
 &sxnextm_dtm_pan,
 &sxnextm_dtm_sample,
 &sxnextm_dtm_rows,
 &sxnextm_dtm_pitch,
 &sxnextm_dtm_instrument,
 &sxnextm_dtm_volume,
 &sxnextm_dtm_effect,
 &sxnextm_dtm_argument_high,
 &sxnextm_dtm_argument_low,
 &sxnextm_ftm_header,
 &sxnextm_ftm_sample,
 &sxnextm_ftm_script_header,
 &sxnextm_ftm_script_event,
 &sxnextm_eup_header,
 &sxnextm_eup_track_name,
 &sxnextm_eup_short_name,
 &sxnextm_eup_mute,
 &sxnextm_eup_port,
 &sxnextm_eup_channel,
 &sxnextm_eup_key_bias,
 &sxnextm_eup_transpose,
 &sxnextm_eup_filter,
 &sxnextm_eup_instrument_name,
 &sxnextm_eup_bank_names,
 &sxnextm_eup_application,
 &sxnextm_eup_event_header,
 &sxnextm_syn_header,
 &sxnextm_syn_sample_name,
 &sxnextm_syn_instrument,
 &sxnextm_syn_subsong,
 &sxnextm_syn_position,
 &sxnextm_syn_event,
 &sxnextm_d00_header,
 &sxnextm_offset16le,
 &sxnextm_offset32le,
 &sxnextm_offset32be,
 &sxnextm_d00_end,
 &sxnextm_d00_tracks,
 &sxnextm_d00_speed,
 &sxnextm_fmk_header,
 &sxnextm_fmk_track_setting,
 &sxnextm_fmk_instrument,
 &sxnextm_fmk_pattern,
 &sxnextm_fmk_control,
 &sxnextm_fmk_note,
 &sxnextm_fmk_volume,
 &sxnextm_fmk_effect,
 &sxnextm_sct_header,
 &sxnextm_sct_track,
 &sxnextm_sct_position,
 &sxnextm_sct_instrument,
 &sxnextm_sct_command,
 &sxnextm_sct_sample,
 &sxnextm_psf_header,
 &sxnextm_psf_channels,
 &sxnextm_vss_footer,
 &sxnextm_vss_song_offset,
 &sxnextm_vss_data_offset,
 &sxnextm_mle_magic,
 &sxnextm_mle_tune,
 &sxnextm_mle_sequence,
 &sxnextm_mle_index,
 &sxnextm_mle_part_control,
 &sxnextm_mle_part_note,
 &sxnextm_mle_effect,
 &sxnextm_mle_arpeggio,
 &sxnextm_mle_sample,
 &sxnextm_mle_instrument,
 &sxnextm_puma_header,
 &sxnextm_puma_position,
 &sxnextm_puma_marker,
 &sxnextm_puma_event,
 &sxnextm_puma_command,
 &sxnextm_ma_relative32,
 &sxnextm_ma_track_offset,
 &sxnextm_ma_subsong,
 &sxnextm_ma_position,
 &sxnextm_ma_speed,
 &sxnextm_ma_instrument,
 &sxnextm_ma_sample,
 &sxnextm_fred_final_header,
 &sxnextm_fred_final_subsong,
 &sxnextm_fred_final_position,
 &sxnextm_fred_final_control,
 &sxnextm_fred_final_instrument,
 &sxnextm_sid1_base_offset,
 &sxnextm_sid1_song,
 &sxnextm_sid1_sequence,
 &sxnextm_mle_tune_chunk,
};
/* Read physical metadata without buffering whole sample or track payloads. */
typedef struct sxnextm_view {sx_context*c;unsigned work;}sxnextm_view;
static bool sxnextm_span(sxnextm_view*v,uint64_t at,uint64_t n,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&v->c->size>=0&&end<=(uint64_t)v->c->size&&at<=end&&n<=end-at;}
static bool sxnextm_read(sxnextm_view*v,uint64_t at,void*p,size_t n,uint64_t end)
{return ++v->work<=4000000&&sxnextm_span(v,at,n,end)&&sx_read(v->c,(int64_t)at,p,n);}
static bool sxnextm_word(sxnextm_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!n||n>8||!sxnextm_read(v,at,b,n,end))return false;uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[be?n-i-1:i]<<(8*i);*out=x;return true;}
static bool sxnextm_row(sxnextm_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxnextm_span(v,at,z,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)z);}
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
static bool sxnextm_table(sxnextm_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>4000000||count>UINT64_MAX/z||!sxnextm_span(v,at,count*z,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++,at+=z)if(!sxnextm_row(v,l,at,end))return false;return true;}
static int sxnextm_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxnextm_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxnextm_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxnextm_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxnextm_u(sxnextm_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxnextm_word(v,p,n,false,x,end);}
static bool sxnextm_be(sxnextm_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxnextm_word(v,p,n,true,x,end);}
static bool sxnextm_eq(sxnextm_view*v,uint64_t p,const char*s,size_t n,uint64_t end){uint8_t b[64];return n<=sizeof(b)&&sxnextm_read(v,p,b,n,end)&&!xx_rt_memcmp(b,s,n);}
static bool sxnextm_text_emit(sxnextm_view*v,uint64_t p,uint64_t n,uint64_t end){if(!sxnextm_span(v,p,n,end))return false;return !n||n>4096||v->c->count>=24000||sx_add(v->c,&sxnextm_text,(int64_t)p,(int64_t)n);}
static bool sxnextm_take(sxnextm_view*v,const sx_layout*l,uint64_t*p,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!sxnextm_table(v,l,*p,count,end))return false;*p+=count*z;return true;}
static bool sxnextm_skip(sxnextm_view*v,uint64_t*p,uint64_t n,uint64_t end)
{if(!sxnextm_span(v,*p,n,end))return false;*p+=n;return true;}
#define NX_TAKE(l,p,n,end) sxnextm_take(v,&sxnextm_##l,(p),(n),(end))

static bool sxnextm_ast(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,len[15],at[15],p=62;
 if(!sxnextm_eq(v,62,"ACTIONAMICS SOUND TOOL",22,e)||!NX_ROW(ast_header,0,e)||!NX_ROW(ast_banner,62,e))return false;
 for(unsigned i=0;i<15;i++){if(!sxnextm_be(v,2+4*i,4,&len[i],e)||!sxnextm_span(v,p,len[i],e))return false;at[i]=p;p+=len[i];}
 if(len[0]<27||len[1]<4||len[2]!=len[3]||len[2]!=len[4]||len[2]%4||len[5]%32||len[6]%16||len[7]%16||len[8]%16||len[11]%4||len[13]%64||len[14]%2||!NX_ROW(ast_module_size,at[1],at[1]+len[1]))return false;
 if(!sxnextm_table(v,&sxnextm_u8,at[2],len[2],e)||!sxnextm_table(v,&sxnextm_i8,at[3],len[3]+len[4],e)||!sxnextm_table(v,&sxnextm_ast_instrument,at[5],len[5]/32,e))return false;
 for(unsigned i=6;i<=8;i++)if(!sxnextm_table(v,&sxnextm_i8,at[i],len[i],e))return false;
 if(!sxnextm_table(v,&sxnextm_ast_subsong,at[11],len[11]/4,e)||!sxnextm_table(v,&sxnextm_ast_sample,at[13],len[13]/64,e)||!sxnextm_table(v,&sxnextm_offset16,at[14],len[14]/2,e))return false;
 /* Track opcodes and sample waveforms remain raw; each pointer remains a
    physical field without assigning decoded or runtime coordinates. */
 return true;}
static bool sxnextm_dss(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,p=10,n,mx=0;
 if(!sxnextm_eq(v,0,"MMU2",4,e)||!NX_ROW(dss_header,0,e)||!NX_TAKE(dss_sample,&p,31,e)||!sxnextm_be(v,p,2,&n,e)||n>128||!NX_TAKE(count16,&p,1,e))return false;
 for(uint64_t i=0;i<n;i++){uint64_t x;if(!sxnextm_u(v,p+i,1,&x,e))return false;if(x>mx)mx=x;}
 if(!NX_TAKE(order8,&p,128,e))return false;
 return !n||sxnextm_table(v,&sxnextm_dss_event,p,(mx+1)*256,e);}
static bool sxnextm_fred(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,p=16,n,z;
 if(!sxnextm_eq(v,0,"Fred Editor \0\0",14,e)||!sxnextm_be(v,14,2,&n,e)||n>10||!NX_ROW(fred_header,0,e)||!NX_TAKE(u8,&p,n,e)||!NX_TAKE(i8,&p,n*1024,e))return false;
 for(unsigned i=0;i<128;i++){if(!sxnextm_be(v,p,4,&z,e)||z>INT32_MAX||!NX_TAKE(fred_track_length,&p,1,e)||!sxnextm_skip(v,&p,z,e))return false;}
 if(!sxnextm_be(v,p,2,&n,e)||!NX_TAKE(count16,&p,1,e)||!NX_TAKE(fred_instrument,&p,n,e)||!sxnextm_be(v,p,2,&n,e)||!NX_TAKE(count16,&p,1,e))return false;
 for(uint64_t i=0;i<n;i++){if(!sxnextm_be(v,p+2,2,&z,e)||!NX_TAKE(fred_sample,&p,1,e)||!sxnextm_skip(v,&p,z,e))return false;}
 return sxnextm_eq(v,p,"\x12\x34\x56\x78",4,e)&&NX_ROW(fred_end,p,e);}
static bool sxnextm_dtm_chunks(sxnextm_view*v,uint64_t p,uint64_t e,unsigned context,unsigned depth){if(depth>3)return false;while(p<e){uint8_t id[4];uint64_t z;if(!sxnextm_read(v,p,id,4,e)||!sxnextm_u(v,p+4,4,&z,e)||!NX_ROW(chunk_le,p,e)||!sxnextm_span(v,p+8,z,e))return false;uint64_t b=p+8,end=b+z;
 if((!xx_rt_memcmp(id,"SONG",4)&&depth==0)||(!xx_rt_memcmp(id,"INIT",4)&&context==1)||(!xx_rt_memcmp(id,"INST",4)&&context==1)||(!xx_rt_memcmp(id,"TRAK",4)&&context==1)||(!xx_rt_memcmp(id,"SAMP",4)&&context==1)){unsigned next=!xx_rt_memcmp(id,"SONG",4)?1:!xx_rt_memcmp(id,"INIT",4)?2:!xx_rt_memcmp(id,"INST",4)?3:!xx_rt_memcmp(id,"TRAK",4)?4:5;if(!sxnextm_dtm_chunks(v,b,end,next,depth+1))return false;}
 else if(context==1&&!xx_rt_memcmp(id,"INFO",4)){if(!NX_ROW(dtm_info,b,end))return false;}
 else if((context==1&&!xx_rt_memcmp(id,"NAME",4))||((context==3||context==5)&&!xx_rt_memcmp(id,"text",4))){if(!sxnextm_text_emit(v,b,z,end))return false;}
 else if(context==2&&!xx_rt_memcmp(id,"sped",4)){if(!NX_ROW(dtm_speed,b,end))return false;}
 else if(context==2&&!xx_rt_memcmp(id,"vpan",4)){if(z%2||!sxnextm_table(v,&sxnextm_dtm_pan,b,z/2,end))return false;}
 else if(context==1&&!xx_rt_memcmp(id,"PSEQ",4)){if(!sxnextm_table(v,&sxnextm_order8,b,z,end))return false;}
 else if(context==1&&!xx_rt_memcmp(id,"PATT",4)){if(z%2||!sxnextm_table(v,&sxnextm_track16,b,z/2,end))return false;}
 else if(context==3&&!xx_rt_memcmp(id,"samp",4)){if(!NX_ROW(dtm_sample,b,end))return false;}
 else if(context==4&&!xx_rt_memcmp(id,"trak",4)){uint64_t n,q=b;if(!sxnextm_u(v,b,2,&n,end)||!NX_TAKE(dtm_rows,&q,1,end)||!NX_TAKE(dtm_pitch,&q,n,end)||!NX_TAKE(dtm_instrument,&q,n,end)||!NX_TAKE(dtm_volume,&q,n,end)||!NX_TAKE(dtm_effect,&q,n,end)||!NX_TAKE(dtm_argument_high,&q,n,end)||!NX_TAKE(dtm_argument_low,&q,n,end))return false;}
 p=end;}return true;}
static bool sxnextm_dtm(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,z;return sxnextm_eq(v,0,"SONG",4,e)&&sxnextm_u(v,4,4,&z,e)&&sxnextm_span(v,8,z,e)&&sxnextm_dtm_chunks(v,0,8+z,0,0);}
static bool sxnextm_ftm(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,p=82,n,fx,z;if(!sxnextm_eq(v,0,"FTMN\x03",5,e)||!NX_ROW(ftm_header,0,e)||!sxnextm_u(v,5,1,&n,e)||!sxnextm_u(v,80,1,&fx,e)||!NX_TAKE(ftm_sample,&p,n,e))return false;
 for(uint64_t i=0;i<fx;i++){if(!sxnextm_be(v,p,2,&z,e)||!NX_TAKE(ftm_script_header,&p,1,e)||!NX_TAKE(ftm_script_event,&p,z,e))return false;}return true;}
static bool sxnextm_eup(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,p=84;
 if(e<2060||!NX_ROW(eup_header,0,e)||!NX_TAKE(eup_track_name,&p,32,e)||!NX_TAKE(eup_short_name,&p,32,e)||!NX_TAKE(eup_mute,&p,32,e)||!NX_TAKE(eup_port,&p,32,e)||!NX_TAKE(eup_channel,&p,32,e)||!NX_TAKE(eup_key_bias,&p,32,e)||!NX_TAKE(eup_transpose,&p,32,e)||!NX_TAKE(eup_filter,&p,32,e)||!NX_TAKE(eup_instrument_name,&p,128,e)||!NX_TAKE(eup_channel,&p,14,e)||!NX_TAKE(eup_bank_names,&p,1,e))return false;
 return p==0x6f2&&NX_ROW(eup_application,0x7f6,e)&&NX_ROW(eup_event_header,0x800,e);}
static bool sxnextm_syn(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,b=0,p,rows,positions,n[6];if(!sxnextm_eq(v,0,"Synth4.0",8,e)){b=0x1f0e;if(!sxnextm_eq(v,b,"Synth4.2",8,e))return false;}
 if(!NX_ROW(syn_header,b,e)||!sxnextm_be(v,b+8,2,&positions,e)||!sxnextm_be(v,b+10,2,&rows,e))return false;for(unsigned i=0;i<6;i++)if(!sxnextm_u(v,b+16+i,1,&n[i],e))return false;p=b+204;
 if(!NX_TAKE(syn_sample_name,&p,n[0],e)||!NX_TAKE(bytes32,&p,n[0],e)||!NX_TAKE(u8,&p,n[4]*128+n[5]*256,e)||!NX_TAKE(syn_instrument,&p,n[2],e)||!NX_TAKE(u8,&p,256,e)||!NX_TAKE(syn_subsong,&p,n[3],e)||!sxnextm_skip(v,&p,14+n[1]*256,e)||!NX_TAKE(syn_position,&p,positions*4,e)||!NX_TAKE(syn_event,&p,rows+64,e))return false;return true;}

static bool sxnextm_d00(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,ver,n,p,q;
 if(!sxnextm_u(v,0,1,&ver,e)||ver>1||!sxnextm_u(v,2,1,&n,e)||!n||!NX_ROW(d00_header,0,e))return false;
 if(ver==1&&!NX_ROW(offset16le,11,e))return false;if(!NX_ROW(d00_end,ver?13:11,e)||!sxnextm_u(v,3,2,&p,e)||!sxnextm_table(v,&sxnextm_d00_tracks,p,n,e))return false;
 for(uint64_t i=0;i<n;i++)for(unsigned ch=0;ch<9;ch++){if(!sxnextm_u(v,p+i*32+ch*2,2,&q,e))return false;if(q&&!NX_ROW(d00_speed,q,e))return false;}
 return true;}
static bool sxnextm_fmk(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,p=82,t,no,ni,np,inst,pat,z,off;
 if(!sxnextm_eq(v,0,"FMK!",4,e)||!NX_ROW(fmk_header,0,e)||!sxnextm_u(v,61,1,&t,e)||!sxnextm_u(v,74,1,&no,e)||!sxnextm_u(v,75,1,&ni,e)||!sxnextm_u(v,76,1,&np,e)||!NX_TAKE(fmk_track_setting,&p,t>=2?18:20,e)||!NX_TAKE(order8,&p,no,e)||!NX_TAKE(offset16le,&p,1,e))return false;
 inst=p;if(!NX_TAKE(offset16le,&p,ni,e))return false;pat=p;if(!NX_TAKE(offset32le,&p,np,e))return false;
 for(uint64_t i=0;i<ni;i++){if(!sxnextm_u(v,inst+i*2,2,&off,e))return false;if(off&&!NX_ROW(fmk_instrument,off,e))return false;}
 for(uint64_t i=0;i<np;i++){if(!sxnextm_u(v,pat+i*4,4,&off,e))return false;if(!off)continue;if(!sxnextm_u(v,off,2,&z,e)||!NX_ROW(fmk_pattern,off,e)||!sxnextm_span(v,off+2,z,e))return false;uint64_t q=off+2,end=q+z,rows=0;
 while(q<end&&rows<64){uint64_t c;if(!sxnextm_u(v,q,1,&c,end)||!NX_TAKE(fmk_control,&q,1,end))return false;if(!c){rows++;continue;}if((c&32)&&!NX_TAKE(fmk_note,&q,1,end))return false;if((c&64)&&!NX_TAKE(fmk_volume,&q,1,end))return false;if((c&128)&&!NX_TAKE(fmk_effect,&q,1,end))return false;}}
 return true;}
static bool sxnextm_sct(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,b[4],z[4],p=64,off,n;
 if(!NX_ROW(sct_header,0,e))return false;for(unsigned i=0;i<4;i++){if(!sxnextm_be(v,16+i*4,4,&z[i],e)||!sxnextm_span(v,p,z[i],e))return false;b[i]=p;p+=z[i];}
 if(!sxnextm_table(v,&sxnextm_offset16,b[0],256,b[0]+z[0])||!sxnextm_table(v,&sxnextm_offset32be,b[1],256,b[1]+z[1])||z[2]%12||!sxnextm_table(v,&sxnextm_sct_position,b[2],z[2]/2,b[2]+z[2]))return false;
 if(z[3]&&!sxnextm_table(v,&sxnextm_offset16,b[3],256,b[3]+z[3]))return false;
 for(unsigned i=0;i<256;i++){if(!sxnextm_be(v,b[0]+i*2,2,&off,e))return false;if(off&&!NX_ROW(sct_track,b[0]+off,b[0]+z[0]))return false;
 if(!sxnextm_be(v,b[1]+i*4,4,&off,e))return false;if(off){p=b[1]+off;if(!NX_ROW(sct_sample,p,b[1]+z[1])||!sxnextm_be(v,p+60,4,&n,e)||n<64||!sxnextm_span(v,p,n,b[1]+z[1]))return false;}
 if(z[3]){if(!sxnextm_be(v,b[3]+i*2,2,&off,e))return false;if(off){p=b[3]+off;if(!NX_ROW(sct_instrument,p,b[3]+z[3])||!sxnextm_be(v,p+16,2,&n,e)||n%6||!sxnextm_table(v,&sxnextm_sct_command,p+48,n/6,b[3]+z[3]))return false;}}}
 return true;}
static bool sxnextm_psf(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,n;if(!sxnextm_be(v,0,4,&n,e)||n<276||!sxnextm_span(v,0,n,e)||!NX_ROW(psf_header,0,e)||!sxnextm_table(v,&sxnextm_psf_channels,4,16,n)||!sxnextm_table(v,&sxnextm_offset32be,20,64,n))return false;return true;}
static bool sxnextm_rel32(sxnextm_view*v,uint64_t word,uint64_t base,uint64_t*out,uint64_t end){uint64_t x;if(base>end||!sxnextm_be(v,word,4,&x,end))return false;int64_t d=(x&0x80000000U)?(int64_t)x-INT64_C(0x100000000):(int64_t)x;if(d<0){uint64_t n=(uint64_t)(-d);if(n>base)return false;*out=base-n;}else{if((uint64_t)d>end-base)return false;*out=base+(uint64_t)d;}return *out<=end;}
static bool sxnextm_vss(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,b,n;if(e<64)return false;for(b=(e-64+1)&~UINT64_C(1);b+8<=e;b+=2)if(sxnextm_eq(v,b,"VSS0",4,e))break;
 if(b+8>e||!sxnextm_be(v,b+4,4,&n,e)||n>=256||!NX_ROW(vss_footer,b,e)||!sxnextm_table(v,&sxnextm_vss_song_offset,b+8,n,e))return false;
 for(uint64_t i=0;i<n;i++){uint64_t song,p,min=b,x;if(!sxnextm_rel32(v,b+8+i*4,b,&song,e)||song>=b)return false;p=song;unsigned count=0;while(p<min){if(count++>=65536||!sxnextm_rel32(v,p,song,&x,e)||!NX_TAKE(vss_data_offset,&p,1,min))return false;if(x>=song&&x<min)min=x;}if(p!=min||count<4)return false;}return true;}
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
static bool sxnextm_puma(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,n,tracks,ins,p=80;
 if(!NX_ROW(puma_header,0,e)||!sxnextm_be(v,12,2,&n,e)||!sxnextm_be(v,14,2,&tracks,e)||!sxnextm_be(v,16,2,&ins,e)||!NX_TAKE(puma_position,&p,n+1,e))return false;
 for(uint64_t i=0;i<tracks;i++){if(!sxnextm_eq(v,p,"patt",4,e)||!NX_TAKE(puma_marker,&p,1,e))return false;uint64_t rows=0;unsigned count=0;while(rows<32){uint64_t wait;if(count++>=65536||!sxnextm_u(v,p+3,1,&wait,e)||!NX_TAKE(puma_event,&p,1,e))return false;rows+=wait;}}
 if(!sxnextm_eq(v,p,"patt",4,e)||!NX_TAKE(puma_marker,&p,1,e))return false;
 for(uint64_t i=0;i<ins;i++)for(unsigned kind=0;kind<2;kind++){if(!sxnextm_eq(v,p,kind?"insf":"inst",4,e)||!NX_TAKE(puma_marker,&p,1,e))return false;for(unsigned j=0;;j++){uint64_t op;if(j>=65536||!sxnextm_u(v,p,1,&op,e))return false;if(sxnextm_eq(v,p,"inst",4,e))break;if(!NX_TAKE(puma_command,&p,1,e))return false;if(op==0xe0||op==0xb0)break;}}
 if(p<e&&sxnextm_eq(v,p,"inst",4,e)&&!NX_ROW(puma_marker,p,e))return false;return true;}

/* Replay-code operands are used only to locate stored metadata. Instructions
   and executable bodies are not presented as invented container headers. */
static bool sxnextm_rel(sxnextm_view*v,uint64_t at,unsigned n,uint64_t base,uint64_t*out,uint64_t e)
{uint64_t x;if(base>e||!n||n>4||!sxnextm_be(v,at,n,&x,e))return false;int64_t delta=(x&(UINT64_C(1)<<(n*8-1)))?(int64_t)x-(INT64_C(1)<<(n*8)):(int64_t)x;if(delta<0){if((uint64_t)(-delta)>base)return false;*out=base-(uint64_t)(-delta);}else{if((uint64_t)delta>e-base)return false;*out=base+(uint64_t)delta;}return true;}
static bool sxnextm_find16(sxnextm_view*v,uint64_t*p,uint16_t word,uint64_t stop,uint64_t e)
{uint64_t x;for(;*p<stop;*p+=2){if(!sxnextm_be(v,*p,2,&x,e))return false;if(x==word)return true;}return false;}
static bool sxnextm_ma(sxnextm_view*v)
{uint64_t e=(uint64_t)v->c->size,limit=e<0x700?e:0x700,p,n,speeds,subs,base,ip,sp,tp,ins,samples,tracks,minpos=UINT64_MAX,maxtrack=0;bool have_track=false;
 if(e<0x622||!sxnextm_eq(v,0,"\x60\x00",2,e)||!sxnextm_eq(v,4,"\x60\x00",2,e)||!sxnextm_eq(v,8,"\x60\x00",2,e)||!sxnextm_eq(v,12,"\x48\xe7",2,e)||!sxnextm_rel(v,2,2,2,&p,limit)||!sxnextm_find16(v,&p,0xb07c,limit-4,e)||!sxnextm_be(v,p+2,2,&n,e)||!n||n>256)return false;
 p+=4;if(!sxnextm_find16(v,&p,0x49fa,limit-4,e)||!sxnextm_rel(v,p+2,2,p+2,&speeds,e))return false;
 p+=4;if(!sxnextm_find16(v,&p,0x49fb,limit-4,e)||!sxnextm_rel(v,p+3,1,p+2,&subs,e))return false;
 p=12;if(!sxnextm_find16(v,&p,0x43fa,limit-4,e)||!sxnextm_rel(v,p+2,2,p+2,&base,e))return false;
 p+=4;if(!sxnextm_find16(v,&p,0xd3fa,limit-8,e)||!sxnextm_rel(v,p+2,2,p+2,&ip,e)||!sxnextm_eq(v,p+4,"\xd5\xfa",2,e)||!sxnextm_rel(v,p+6,2,p+6,&sp,e))return false;
 p+=8;for(;p+2<limit;p+=2){uint64_t op;if(!sxnextm_u(v,p,1,&op,e))return false;if(op==0x61)break;}
 if(p+2>=limit||!sxnextm_rel(v,p+1,1,p+2,&p,limit)||!sxnextm_find16(v,&p,0xdbfa,limit-4,e)||!sxnextm_rel(v,p+2,2,p+2,&tp,e)||!sxnextm_rel32(v,ip,base,&ins,e)||!sxnextm_rel32(v,sp,base,&samples,e)||!sxnextm_rel32(v,tp,base,&tracks,e))return false;
 if(!NX_ROW(ma_relative32,ip,e)||!NX_ROW(ma_relative32,sp,e)||!NX_ROW(ma_relative32,tp,e)||!sxnextm_table(v,&sxnextm_ma_speed,speeds,n,e)||!sxnextm_table(v,&sxnextm_ma_subsong,subs,n,e))return false;
 for(uint64_t i=0;i<n*4;i++){uint64_t rel,pos;if(!sxnextm_be(v,subs+i*2,2,&rel,e)||rel>e-base)return false;pos=base+rel;if(pos<minpos)minpos=pos;
  for(unsigned j=0;;j++){uint64_t track;if(j>=65536||!sxnextm_u(v,pos,1,&track,e)||!NX_TAKE(ma_position,&pos,1,e))return false;if(track>=254)break;if(track+1>maxtrack)maxtrack=track+1;have_track=true;}}
 if(have_track){if(!sxnextm_table(v,&sxnextm_ma_track_offset,base,maxtrack,e))return false;for(uint64_t i=0;i<maxtrack;i++){uint64_t x;if(!sxnextm_be(v,base+i*2,2,&x,e)||x>e-tracks)return false;}}
 if(ins>samples||samples>minpos||(samples-ins)%16||(minpos-samples)%24||!sxnextm_table(v,&sxnextm_ma_instrument,ins,(samples-ins)/16,e)||!sxnextm_table(v,&sxnextm_ma_sample,samples,(minpos-samples)/24,e))return false;
 return true;}
static bool sxnextm_fred_final(sxnextm_view*v)
{uint64_t e=(uint64_t)v->c->size,init,p,module=0,base=0,word,inst,track,n,at;bool found=false;
 if(e<0xb0e)return false;for(unsigned i=0;i<4;i++)if(!sxnextm_eq(v,i*4,"\x4e\xfa",2,e))return false;
 if(!sxnextm_rel(v,2,2,2,&init,e)||!sxnextm_span(v,init,128,e))return false;
 for(unsigned i=0;i<4;i++){p=init+i*2;if(sxnextm_eq(v,p,"\x12\x3a",2,e)&&sxnextm_eq(v,p+4,"\xb0\x01",2,e)){if(!sxnextm_rel(v,p+2,2,p+1,&module,e))return false;found=true;break;}}
 if(!found)return false;found=false;for(;p<init+120;p+=2)if(sxnextm_eq(v,p,"\x47\xfa",2,e)&&sxnextm_eq(v,p+4,"\xd7\xfa",2,e)){if(!sxnextm_rel(v,p+2,2,p+2,&base,e))return false;found=true;break;}
 if(!found||!NX_ROW(fred_final_header,module,e)||!sxnextm_u(v,module+1,1,&n,e)||n>=10)return false;n++;
 if(!sxnextm_be(v,module+14,4,&word,e)||word>e-base)return false;inst=base+word;if(!sxnextm_be(v,module+18,4,&word,e)||word>e-base)return false;track=base+word;
 at=module+22;if(!sxnextm_skip(v,&at,612,e)||!NX_TAKE(fred_final_subsong,&at,n,e))return false;uint64_t end=inst<track?inst:track;
 if(at>end||(end-at)%2)return false;while(at<end){if(!sxnextm_be(v,at,2,&word,end)||!sxnextm_take(v,word&0x8000?&sxnextm_fred_final_control:&sxnextm_fred_final_position,&at,1,end))return false;}
 /* The source locates the end of the instrument array by its sample pointers
    and a documented legacy sentinel; incomplete/ambiguous tail stays raw. */
 uint64_t sample_begin=e;for(p=inst;p<sample_begin;){uint64_t off,type,test;if(!sxnextm_span(v,p,64,sample_begin))break;if(!sxnextm_be(v,p,4,&off,e)||!sxnextm_be(v,p+4,2,&test,e)||!sxnextm_u(v,p+39,1,&type,e))return false;
  if(type!=255){if(!off){if(test==0xfcf5)break;if(test!=65535&&type!=0)break;}else{if(off>e-base)break;uint64_t dest=base+off;if(dest<p+64)break;if(dest<sample_begin)sample_begin=dest;}}
  if(!NX_TAKE(fred_final_instrument,&p,1,sample_begin))return false;}
 return true;}
static bool sxnextm_sid1(sxnextm_view*v)
{uint64_t e=(uint64_t)v->c->size,limit=e<4096?e:4096,p=0,word,base,seq[4],data,n;
 if(e<1024||!sxnextm_find16(v,&p,0x41fa,limit-4,e)||!sxnextm_be(v,p+2,2,&word,e)||word>e-p-2)return false;base=p+2+word;p+=4;
 for(unsigned i=0;i<4;i++){uint64_t at;if(!sxnextm_find16(v,&p,0xd1e8,limit-4,e)||!sxnextm_rel(v,p+2,2,base,&at,e)||!NX_ROW(sid1_base_offset,at,e)||!sxnextm_rel32(v,at,base,&seq[i],e))return false;p+=4;}
 p=0;for(;p+4<limit;p+=2)if(sxnextm_eq(v,p,"\x48\xe7\xff\xfe",4,e))break;
 if(p+4>=limit||!sxnextm_find16(v,&p,0x6100,limit-4,e)||!sxnextm_find16(v,&p,0xd3e9,limit-4,e)||!sxnextm_rel(v,p+2,2,base,&word,e)||!NX_ROW(sid1_base_offset,word,e)||!sxnextm_rel32(v,word,base,&data,e)||!NX_ROW(sid1_song,data,e)||!sxnextm_be(v,data+28,4,&n,e)||!n)return false;n--;
 for(unsigned i=0;i<4;i++)if(!sxnextm_table(v,&sxnextm_sid1_sequence,seq[i],n,e))return false;return true;}

static bool sx_nextmusic_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_DIE_MUSIC_KLEPS_ACTIONAMICSSOUNDTOOL:
case XX_FILE_TYPE_DIE_MUSIC_GREATVALLEYPROD_DIGITALSOUNDSTUDIO:
case XX_FILE_TYPE_DIE_MUSIC_BEHAM_DIGITREKKER_DTM:
case XX_FILE_TYPE_DIE_MUSIC_FUJITSU_EUPHONY_EUP:
case XX_FILE_TYPE_DIE_MUSIC_WILENIUS_FMKINGTRACKER:
case XX_FILE_TYPE_DIE_MUSIC_CLERMONTE_FREDEDITOR_PROJECT:
case XX_FILE_TYPE_DIE_MUSIC_MAXON_FACETHEMUSIC:
case XX_FILE_TYPE_DIE_MUSIC_MUSICLINEEDITOR:
case XX_FILE_TYPE_DIE_MUSIC_BRAINTRACEDESIGN_SYNTHESIS:
case XX_FILE_TYPE_DIE_MUSIC_PARTL_VOODOOSUPREMESYNTHESIZER:
case XX_FILE_TYPE_DIE_MUSIC_JCH_EDLIBTRACKER_RAW:
case XX_FILE_TYPE_DIE_MUSIC_MEYRIGNAC_PUMATRACKER:
case XX_FILE_TYPE_DIE_MUSIC_GEHRMANN_SOUNDCONTROL_SCT:
case XX_FILE_TYPE_DIE_MUSIC_URWANI_SOUNDFACTORY_PSF:
case XX_FILE_TYPE_DIE_MUSIC_GIESEN_MUSICASM:
case XX_FILE_TYPE_DIE_MUSIC_CLERMONTE_FREDEDITOR_FINAL:
case XX_FILE_TYPE_DIE_MUSIC_REINIERVANVLIET_SIDMON1:
return true;default:return false;}}
static bool sx_nextmusic_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxnextm_view view={c,0},*v=&view;bool ok=false;
 switch(c->f->file_type){
case XX_FILE_TYPE_DIE_MUSIC_KLEPS_ACTIONAMICSSOUNDTOOL:ok=sxnextm_ast(v);break;
case XX_FILE_TYPE_DIE_MUSIC_GREATVALLEYPROD_DIGITALSOUNDSTUDIO:ok=sxnextm_dss(v);break;
case XX_FILE_TYPE_DIE_MUSIC_BEHAM_DIGITREKKER_DTM:ok=sxnextm_dtm(v);break;
case XX_FILE_TYPE_DIE_MUSIC_FUJITSU_EUPHONY_EUP:ok=sxnextm_eup(v);break;
case XX_FILE_TYPE_DIE_MUSIC_WILENIUS_FMKINGTRACKER:ok=sxnextm_fmk(v);break;
case XX_FILE_TYPE_DIE_MUSIC_CLERMONTE_FREDEDITOR_PROJECT:ok=sxnextm_fred(v);break;
case XX_FILE_TYPE_DIE_MUSIC_MAXON_FACETHEMUSIC:ok=sxnextm_ftm(v);break;
case XX_FILE_TYPE_DIE_MUSIC_MUSICLINEEDITOR:ok=sxnextm_mle(v);break;
case XX_FILE_TYPE_DIE_MUSIC_BRAINTRACEDESIGN_SYNTHESIS:ok=sxnextm_syn(v);break;
case XX_FILE_TYPE_DIE_MUSIC_PARTL_VOODOOSUPREMESYNTHESIZER:ok=sxnextm_vss(v);break;
case XX_FILE_TYPE_DIE_MUSIC_JCH_EDLIBTRACKER_RAW:ok=sxnextm_d00(v);break;
case XX_FILE_TYPE_DIE_MUSIC_MEYRIGNAC_PUMATRACKER:ok=sxnextm_puma(v);break;
case XX_FILE_TYPE_DIE_MUSIC_GEHRMANN_SOUNDCONTROL_SCT:ok=sxnextm_sct(v);break;
case XX_FILE_TYPE_DIE_MUSIC_URWANI_SOUNDFACTORY_PSF:ok=sxnextm_psf(v);break;
case XX_FILE_TYPE_DIE_MUSIC_GIESEN_MUSICASM:ok=sxnextm_ma(v);break;
case XX_FILE_TYPE_DIE_MUSIC_CLERMONTE_FREDEDITOR_FINAL:ok=sxnextm_fred_final(v);break;
case XX_FILE_TYPE_DIE_MUSIC_REINIERVANVLIET_SIDMON1:ok=sxnextm_sid1(v);break;
default:break;}
 return ok&&sxnextm_finish(c);}
#undef NX_ROW
#undef NX_TAKE
static bool sxnextm_name(const xx_data_struct_record*r,const wchar_t*s){return !xx_rt_wcscmp(r->name,s);}
static bool sx_nextmusic_comment(xx_data_struct_record*r,uint32_t id)
{if(!r||!r->name||id<UINT32_C(0x608b0001)||id>=UINT32_C(0x608c0000))return true;const wchar_t*s=NULL;
 if(sxnextm_name(r,L"length_words")||sxnextm_name(r,L"loop_start_words")||sxnextm_name(r,L"loop_end_words")||sxnextm_name(r,L"loop_length_words")||sxnextm_name(r,L"repeat_words"))s=L"Stored in two-byte sample words; not a byte count or file offset";
 if(id==sxnextm_ast_header.id&&sxnextm_name(r,L"tempo"))s=L"Initial tempo in beats per minute";
 else if(id==sxnextm_ast_sample.id){if(sxnextm_name(r,L"stored_data_pointer"))s=L"Stored data pointer skipped by the file loader; no physical address domain is inferred";else if(sxnextm_name(r,L"effect_start"))s=L"Effect start in two-byte sample words";else if(sxnextm_name(r,L"effect_length"))s=L"Stored effect length; original player also uses the high byte as the arpeggio-list index";}
 else if(id==sxnextm_dss_sample.id){if(sxnextm_name(r,L"start_offset_encoded"))s=L"Byte offset within this sample's stored data; loader clears bit 0 before use";else if(sxnextm_name(r,L"loop_start"))s=L"Byte offset relative to the sample start after its encoded start offset";else if(sxnextm_name(r,L"frequency"))s=L"Stored sample playback frequency in Hz";}
 else if(id==sxnextm_fred_instrument.id||id==sxnextm_fred_final_instrument.id){if(sxnextm_name(r,L"repeat_start"))s=L"PCM loop start in bytes; 0 and FFFF disable looping; synthesis instruments use their full waveform";else if(sxnextm_name(r,L"instrument_type"))s=L"0 PCM sample; 1 pulse synthesis; 2 blend synthesis; FF unused in compiled form";else if(sxnextm_name(r,L"sample_offset"))s=L"Signed byte offset relative to the compiled player's located offset base; zero denotes synthesis/unused data";else if(sxnextm_name(r,L"period"))s=L"Amiga playback period control; not a frequency in Hz";}
 else if(id==sxnextm_dtm_sample.id){if(sxnextm_name(r,L"loop_start")||sxnextm_name(r,L"loop_end"))s=L"Byte position within this sample's data";else if(sxnextm_name(r,L"c4_sample_rate"))s=L"Sample playback rate for note C4, in Hz";}
 else if(id==sxnextm_dtm_pitch.id)s=L"0 means no note; 1..96 encode C-0..B-7; 128 (80 hex) is note off";
 else if(id==sxnextm_dtm_volume.id)s=L"Zero means no change; other values store volume plus one";
 else if(id==sxnextm_dtm_effect.id)s=L"Zero means no effect; other values store the effect number plus one";
 else if(id==sxnextm_ftm_header.id){if(sxnextm_name(r,L"tempo_timer"))s=L"Amiga CIA timer period; this is not a direct BPM value";else if(sxnextm_name(r,L"flags"))s=L"Bit 0 embedded samples; bit 1 LED/filter state";else if(sxnextm_name(r,L"channel_enable_mask"))s=L"Bits 0..7 enable the corresponding music channels";}
 else if(id==sxnextm_ftm_script_event.id&&sxnextm_name(r,L"argument"))s=L"Big-endian 24-bit script argument; interpretation depends on command";
 else if(id==sxnextm_eup_event_header.id&&sxnextm_name(r,L"initial_tempo"))s=L"Encoded initial tempo; effective beats per minute is stored value plus 30";
 else if(id==sxnextm_syn_header.id&&sxnextm_name(r,L"track_rows"))s=L"Declared track-row count; the retained source loader physically reads this value plus 64 rows";
 else if(id==sxnextm_d00_header.id){if(sxnextm_name(r,L"speed"))s=L"Stored refresh-rate byte; version 0 playback overrides it with 70 Hz";else if(r->property&SX_OFFSET)s=L"Byte offset from the beginning of this raw EdLib image";}
 else if(id==sxnextm_d00_tracks.id){if(r->property&SX_OFFSET)s=L"Byte offset from raw EdLib image start to a speed word followed by sequence operands";else if(!xx_rt_wcsncmp(r->name,L"channel",7))s=L"Volume control: low 7 bits; AdPlug ignores bit 7";}
 else if(id==sxnextm_fmk_header.id){if(sxnextm_name(r,L"packed_pan"))s=L"Packed two-bit panning controls per track";else if(sxnextm_name(r,L"base_refresh_hz"))s=L"Base player update frequency in Hz";else if(sxnextm_name(r,L"initial_ticks"))s=L"Initial ticks per pattern row";}
 else if(id==sxnextm_fmk_track_setting.id)s=L"Low 3 bits track type; high 5 bits OPL channel number";
 else if(id==sxnextm_fmk_pattern.id)s=L"Encoded pattern bytes, excluding this two-byte size word";
 else if(id==sxnextm_fmk_control.id)s=L"Zero ends a row; low 5 bits track; bit 5 note/instrument; bit 6 volume; bit 7 effect/argument";
 else if(id==sxnextm_sct_sample.id&&sxnextm_name(r,L"total_record_bytes"))s=L"Sample record bytes including its 64-byte header";
 else if(id==sxnextm_sct_instrument.id&&sxnextm_name(r,L"command_bytes"))s=L"Bytes of six-byte commands following the 48-byte instrument header";
 else if(id==sxnextm_psf_channels.id)s=L"Bits 0..3 enable the four output channels for this subsong";
 else if(id==sxnextm_vss_song_offset.id)s=L"Signed byte offset relative to the VSS0 footer start";
 else if(id==sxnextm_vss_data_offset.id)s=L"Signed byte offset relative to this subsong's offset-table start";
 else if(id==sxnextm_mle_tune_chunk.id&&sxnextm_name(r,L"declared_payload_bytes"))s=L"Stored declared size; historical versions contain an incorrect value, so the physical extent is calculated from channel sizes";
 else if(id==sxnextm_mle_part_control.id)s=L"FF ends the part; bit 0 note/instrument; bits 1..5 present effect/argument pairs";
 else if(id==sxnextm_mle_sample.id){if(sxnextm_name(r,L"delta_command"))s=L"Escape byte used by the delta-coded sample stream";else if(sxnextm_name(r,L"stored_sample_pointer")||sxnextm_name(r,L"stored_repeat_pointer"))s=L"Legacy stored runtime pointer; not a physical file offset";}
 else if(id==sxnextm_puma_header.id){if(sxnextm_name(r,L"last_position"))s=L"Last zero-based position index; physical table has this value plus one entries";else if(!xx_rt_wcsncmp(r->name,L"sample",6)&&!(r->property&SX_OFFSET))s=L"Encoded sample length: stored value minus one two-byte words; zero denotes absent sample";}
 else if(id==sxnextm_ma_relative32.id)s=L"Signed byte offset relative to the module base located by the replay-code operand";
 else if(id==sxnextm_ma_subsong.id)s=L"Byte offset relative to the module base, pointing to a two-byte position list";
 else if(id==sxnextm_ma_track_offset.id)s=L"Byte offset relative to the separately located track-data block";
 else if(id==sxnextm_ma_position.id){if(sxnextm_name(r,L"track_number"))s=L"Track index; FE and FF terminate a position list";else s=L"High nibble transpose; low nibble shifted by three forms the repeat counter";}
 else if(id==sxnextm_ma_sample.id&&sxnextm_name(r,L"sample_info_relative_offset"))s=L"Signed byte offset relative to the sample-information block; negative values mean no stored PCM";
 else if(id==sxnextm_fred_final_header.id){if(sxnextm_name(r,L"last_subsong_index"))s=L"Last zero-based subsong index; number of subsongs is stored value plus one";else if(r->property&SX_OFFSET)s=L"Byte offset relative to the compiled player's located offset base";}
 else if(id==sxnextm_fred_final_subsong.id)s=L"Byte offset relative to the beginning of the subsong start-offset table";
 else if(id==sxnextm_fred_final_position.id)s=L"Nonnegative byte offset relative to the track-data block";
 else if(id==sxnextm_fred_final_control.id)s=L"Negative sequence-end/restart control word; low 15 bits encode a byte-scaled restart position";
 else if(id==sxnextm_sid1_base_offset.id)s=L"Signed byte offset relative to the located SidMon player data base";
 else if(id==sxnextm_sid1_song.id){if(sxnextm_name(r,L"positions_plus_one"))s=L"Stored position count plus one; physical sequence entry count is this value minus one";else if((r->property&SX_ID)&&!xx_rt_wcsncmp(r->name,L"mix",3))s=L"One-based waveform index used by the mixing effect; not a memory address";}
 return !s||xx_data_struct_record_set_comment(r,s);}
