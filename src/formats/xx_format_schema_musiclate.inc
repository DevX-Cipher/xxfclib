/* SPDX-License-Identifier: MIT. Independently implemented physical music records. */
static const xx_data_struct_field_desc sxlate_buzz2_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version_major","uint16",4,2,SX_NONE),
 SX_FIELD("version_minor","uint16",6,2,SX_NONE),
 SX_FIELD("master_volume","float",8,4,SX_NONE),
 SX_FIELD("tempo_bpm","int32",12,4,SX_NONE),
 SX_FIELD("start_sequence","int32",16,4,SX_NONE),
 SX_FIELD("end_sequence","int32",20,4,SX_NONE),
 SX_FIELD("looping","uint8",24,1,SX_NONE),
 SX_FIELD("unused","uint8[128]",25,128,SX_NONE),
 SX_FIELD("alignment_padding","uint8[3]",153,3,SX_NONE),
};
static const sx_layout sxlate_buzz2_header={0x60930001U,"buzz2_header",sxlate_buzz2_header_fields,SX_COUNT(sxlate_buzz2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_counts_fields[]={
 SX_FIELD("pattern_count","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("sequence_count","int32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxlate_buzz2_counts={0x60930002U,"buzz2_counts",sxlate_buzz2_counts_fields,SX_COUNT(sxlate_buzz2_counts_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_capacities_fields[]={
 SX_FIELD("pattern_capacity","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("sequence_capacity","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("sequence_length","int32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxlate_buzz2_capacities={0x60930003U,"buzz2_capacities",sxlate_buzz2_capacities_fields,SX_COUNT(sxlate_buzz2_capacities_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_pattern_fields[]={
 SX_FIELD("note","uint8[16]",0,16,SX_NONE),
};
static const sx_layout sxlate_buzz2_pattern={0x60930004U,"buzz2_pattern",sxlate_buzz2_pattern_fields,SX_COUNT(sxlate_buzz2_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_sequence_fields[]={
 SX_FIELD("pattern_index","uint8",0,0,SX_NONE),
};
static const sx_layout sxlate_buzz2_sequence={0x60930005U,"buzz2_sequence",sxlate_buzz2_sequence_fields,SX_COUNT(sxlate_buzz2_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_name_fields[]={
 SX_FIELD("name","char[64]",0,64,SX_NONE),
};
static const sx_layout sxlate_buzz2_name={0x60930006U,"buzz2_name",sxlate_buzz2_name_fields,SX_COUNT(sxlate_buzz2_name_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_instrument_count_fields[]={
 SX_FIELD("instrument_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxlate_buzz2_instrument_count={0x60930007U,"buzz2_instrument_count",sxlate_buzz2_instrument_count_fields,SX_COUNT(sxlate_buzz2_instrument_count_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_instrument_fields[]={
 SX_FIELD("name","char[128]",0,128,SX_NONE),
 SX_FIELD("muted","uint8",128,1,SX_NONE),
 SX_FIELD("note","int8",129,1,SX_NONE),
 SX_FIELD("note_length","int8",130,1,SX_NONE),
 SX_FIELD("volume","int8",131,1,SX_NONE),
 SX_FIELD("operation_pointer_snapshot","uint32le[64]",132,256,SX_ADDRESS),
 SX_FIELD("operation_count","int32",388,4,SX_COUNT_PROP),
};
static const sx_layout sxlate_buzz2_instrument={0x60930008U,"buzz2_instrument",sxlate_buzz2_instrument_fields,SX_COUNT(sxlate_buzz2_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_connection_fields[]={
 SX_FIELD("source_operation","int32",0,4,SX_NONE),
 SX_FIELD("destination_operation","int32",4,4,SX_NONE),
 SX_FIELD("input_index","int32",8,4,SX_NONE),
};
static const sx_layout sxlate_buzz2_connection={0x60930009U,"buzz2_connection",sxlate_buzz2_connection_fields,SX_COUNT(sxlate_buzz2_connection_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_instrument_tail_fields[]={
 SX_FIELD("connection_count","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("program","uint8[1024]",4,1024,SX_NONE),
 SX_FIELD("program_bytes","int32",1028,4,SX_SIZE),
 SX_FIELD("unused","uint8[128]",1032,128,SX_NONE),
};
static const sx_layout sxlate_buzz2_instrument_tail={0x6093000aU,"buzz2_instrument_tail",sxlate_buzz2_instrument_tail_fields,SX_COUNT(sxlate_buzz2_instrument_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_buzz2_operation_fields[]={
 SX_FIELD("vtable_snapshot","uint32",0,4,SX_ADDRESS),
 SX_FIELD("type","int32",4,4,SX_NONE),
 SX_FIELD("name","char[128]",8,128,SX_NONE),
 SX_FIELD("width","int32",136,4,SX_NONE),
 SX_FIELD("height","int32",140,4,SX_NONE),
 SX_FIELD("x","int32",144,4,SX_NONE),
 SX_FIELD("y","int32",148,4,SX_NONE),
 SX_FIELD("opcode","int32",152,4,SX_NONE),
 SX_FIELD("input_count","int32",156,4,SX_COUNT_PROP),
 SX_FIELD("parameter_count","int32",160,4,SX_COUNT_PROP),
 SX_FIELD("parameter_0","float",164,4,SX_NONE),
 SX_FIELD("parameter_1","float",168,4,SX_NONE),
 SX_FIELD("parameter_2","float",172,4,SX_NONE),
 SX_FIELD("parameter_3","float",176,4,SX_NONE),
 SX_FIELD("parameter_4","float",180,4,SX_NONE),
 SX_FIELD("parameter_5","float",184,4,SX_NONE),
 SX_FIELD("parameter_6","float",188,4,SX_NONE),
 SX_FIELD("parameter_7","float",192,4,SX_NONE),
 SX_FIELD("parameter_8","float",196,4,SX_NONE),
 SX_FIELD("parameter_9","float",200,4,SX_NONE),
 SX_FIELD("parameter_10","float",204,4,SX_NONE),
 SX_FIELD("parameter_11","float",208,4,SX_NONE),
 SX_FIELD("parameter_12","float",212,4,SX_NONE),
 SX_FIELD("parameter_13","float",216,4,SX_NONE),
 SX_FIELD("parameter_14","float",220,4,SX_NONE),
 SX_FIELD("parameter_15","float",224,4,SX_NONE),
 SX_FIELD("parameter_type","int32le[16]",228,64,SX_NONE),
 SX_FIELD("parameter_name_0","char[16]",292,16,SX_NONE),
 SX_FIELD("parameter_name_1","char[16]",308,16,SX_NONE),
 SX_FIELD("parameter_name_2","char[16]",324,16,SX_NONE),
 SX_FIELD("parameter_name_3","char[16]",340,16,SX_NONE),
 SX_FIELD("parameter_name_4","char[16]",356,16,SX_NONE),
 SX_FIELD("parameter_name_5","char[16]",372,16,SX_NONE),
 SX_FIELD("parameter_name_6","char[16]",388,16,SX_NONE),
 SX_FIELD("parameter_name_7","char[16]",404,16,SX_NONE),
 SX_FIELD("parameter_name_8","char[16]",420,16,SX_NONE),
 SX_FIELD("parameter_name_9","char[16]",436,16,SX_NONE),
 SX_FIELD("parameter_name_10","char[16]",452,16,SX_NONE),
 SX_FIELD("parameter_name_11","char[16]",468,16,SX_NONE),
 SX_FIELD("parameter_name_12","char[16]",484,16,SX_NONE),
 SX_FIELD("parameter_name_13","char[16]",500,16,SX_NONE),
 SX_FIELD("parameter_name_14","char[16]",516,16,SX_NONE),
 SX_FIELD("parameter_name_15","char[16]",532,16,SX_NONE),
 SX_FIELD("background_color","uint32",548,4,SX_NONE),
};
static const sx_layout sxlate_buzz2_operation={0x6093000bU,"buzz2_operation",sxlate_buzz2_operation_fields,SX_COUNT(sxlate_buzz2_operation_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_header_fields[]={
 SX_FIELD("version","int16",0,2,SX_NONE),
 SX_FIELD("reserved_0","int16",2,2,SX_NONE),
 SX_FIELD("pattern_count","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("subsong_count","int32",8,4,SX_COUNT_PROP),
 SX_FIELD("instrument_count","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8[36]",16,36,SX_NONE),
};
static const sx_layout sxlate_jxs_header={0x6093000cU,"jxs_header",sxlate_jxs_header_fields,SX_COUNT(sxlate_jxs_header_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_subsong_fields[]={
 SX_FIELD("reserved_0","uint8[64]",0,64,SX_NONE),
 SX_FIELD("channel_muted","uint8[16]",64,16,SX_NONE),
 SX_FIELD("step_delay","int32",80,4,SX_NONE),
 SX_FIELD("groove","int32",84,4,SX_NONE),
 SX_FIELD("start_position","int32",88,4,SX_NONE),
 SX_FIELD("start_step","int32",92,4,SX_NONE),
 SX_FIELD("end_position","int32",96,4,SX_NONE),
 SX_FIELD("end_step","int32",100,4,SX_NONE),
 SX_FIELD("loop_position","int32",104,4,SX_NONE),
 SX_FIELD("loop_step","int32",108,4,SX_NONE),
 SX_FIELD("loop_enabled","int16",112,2,SX_NONE),
 SX_FIELD("name","char[32]",114,32,SX_NONE),
 SX_FIELD("channel_count","int16",146,2,SX_COUNT_PROP),
 SX_FIELD("echo_delay","uint16",148,2,SX_NONE),
 SX_FIELD("channel_echo_amount","uint8[16]",150,16,SX_NONE),
 SX_FIELD("amplification","int16",166,2,SX_NONE),
 SX_FIELD("reserved_1","uint8[12]",168,12,SX_NONE),
};
static const sx_layout sxlate_jxs_subsong={0x6093000dU,"jxs_subsong",sxlate_jxs_subsong_fields,SX_COUNT(sxlate_jxs_subsong_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_order_fields[]={
 SX_FIELD("pattern_index","int16",0,2,SX_NONE),
 SX_FIELD("pattern_length","int16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxlate_jxs_order={0x6093000eU,"jxs_order",sxlate_jxs_order_fields,SX_COUNT(sxlate_jxs_order_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_event_fields[]={
 SX_FIELD("source_note","uint8",0,1,SX_NONE),
 SX_FIELD("destination_note","uint8",1,1,SX_NONE),
 SX_FIELD("instrument","uint8",2,1,SX_NONE),
 SX_FIELD("parameter","int8",3,1,SX_NONE),
 SX_FIELD("script","uint8",4,1,SX_NONE),
};
static const sx_layout sxlate_jxs_event={0x6093000fU,"jxs_event",sxlate_jxs_event_fields,SX_COUNT(sxlate_jxs_event_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_pattern_name_size_fields[]={
 SX_FIELD("name_bytes","int32",0,4,SX_SIZE),
};
static const sx_layout sxlate_jxs_pattern_name_size={0x60930010U,"jxs_pattern_name_size",sxlate_jxs_pattern_name_size_fields,SX_COUNT(sxlate_jxs_pattern_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_pattern_name_fields[]={
 SX_FIELD("name","char",0,0,SX_NONE),
};
static const sx_layout sxlate_jxs_pattern_name={0x60930011U,"jxs_pattern_name",sxlate_jxs_pattern_name_fields,SX_COUNT(sxlate_jxs_pattern_name_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_instrument_fields[]={
 SX_FIELD("version","int16",0,2,SX_NONE),
 SX_FIELD("name","char[32]",2,32,SX_NONE),
 SX_FIELD("waveform","int16",34,2,SX_NONE),
 SX_FIELD("wavelength","int16",36,2,SX_NONE),
 SX_FIELD("master_volume","int16",38,2,SX_NONE),
 SX_FIELD("am_wave","int16",40,2,SX_NONE),
 SX_FIELD("am_speed","int16",42,2,SX_NONE),
 SX_FIELD("am_loop_point","int16",44,2,SX_NONE),
 SX_FIELD("fine_tune","int16",46,2,SX_NONE),
 SX_FIELD("fm_wave","int16",48,2,SX_NONE),
 SX_FIELD("fm_speed","int16",50,2,SX_NONE),
 SX_FIELD("fm_loop_point","int16",52,2,SX_NONE),
 SX_FIELD("fm_delay","int16",54,2,SX_NONE),
 SX_FIELD("arpeggio","int16",56,2,SX_NONE),
 SX_FIELD("reset_wave","int8[16]",58,16,SX_NONE),
 SX_FIELD("pan_wave","int16",74,2,SX_NONE),
 SX_FIELD("pan_speed","int16",76,2,SX_NONE),
 SX_FIELD("pan_loop_point","int16",78,2,SX_NONE),
 SX_FIELD("reserved","uint8[12]",80,12,SX_NONE),
};
static const sx_layout sxlate_jxs_instrument={0x60930012U,"jxs_instrument",sxlate_jxs_instrument_fields,SX_COUNT(sxlate_jxs_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_effect_fields[]={
 SX_FIELD("destination_effect","int32",0,4,SX_NONE),
 SX_FIELD("source_effect_1","int32",4,4,SX_NONE),
 SX_FIELD("source_effect_2","int32",8,4,SX_NONE),
 SX_FIELD("oscillator_effect","int32",12,4,SX_NONE),
 SX_FIELD("effect_variable_1","int32",16,4,SX_NONE),
 SX_FIELD("effect_variable_2","int32",20,4,SX_NONE),
 SX_FIELD("effect_speed","int32",24,4,SX_NONE),
 SX_FIELD("oscillator_speed","int32",28,4,SX_NONE),
 SX_FIELD("effect_type","int32",32,4,SX_NONE),
 SX_FIELD("oscillator_flag","int8",36,1,SX_NONE),
 SX_FIELD("reset_effect","int8",37,1,SX_NONE),
 SX_FIELD("reserved","int16",38,2,SX_NONE),
};
static const sx_layout sxlate_jxs_effect={0x60930013U,"jxs_effect",sxlate_jxs_effect_fields,SX_COUNT(sxlate_jxs_effect_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_sample_info_fields[]={
 SX_FIELD("sample_path","char[192]",0,192,SX_NONE),
 SX_FIELD("reserved","uint8[50]",192,50,SX_NONE),
 SX_FIELD("sharing","int16",242,2,SX_NONE),
 SX_FIELD("loop_enabled","int16",244,2,SX_NONE),
 SX_FIELD("bidirectional_loop","int16",246,2,SX_NONE),
 SX_FIELD("start_point","int32",248,4,SX_NONE),
 SX_FIELD("loop_point","int32",252,4,SX_NONE),
 SX_FIELD("end_point","int32",256,4,SX_NONE),
 SX_FIELD("sample_pointer_snapshot","int32",260,4,SX_ADDRESS),
 SX_FIELD("sample_bytes","int32",264,4,SX_SIZE),
};
static const sx_layout sxlate_jxs_sample_info={0x60930014U,"jxs_sample_info",sxlate_jxs_sample_info_fields,SX_COUNT(sxlate_jxs_sample_info_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_wave_fields[]={
 SX_FIELD("sample","int16le[256]",0,512,SX_NONE),
};
static const sx_layout sxlate_jxs_wave={0x60930015U,"jxs_wave",sxlate_jxs_wave_fields,SX_COUNT(sxlate_jxs_wave_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_jxs_arpeggio_fields[]={
 SX_FIELD("step","uint8[16]",0,16,SX_NONE),
};
static const sx_layout sxlate_jxs_arpeggio={0x60930016U,"jxs_arpeggio",sxlate_jxs_arpeggio_fields,SX_COUNT(sxlate_jxs_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_header_fields[]={
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("order_count","uint16",1,2,SX_COUNT_PROP),
 SX_FIELD("instrument_count","uint16",3,2,SX_COUNT_PROP),
 SX_FIELD("sample_count","uint16",5,2,SX_COUNT_PROP),
 SX_FIELD("pattern_count","uint16",7,2,SX_COUNT_PROP),
 SX_FIELD("global_volume","uint8",9,1,SX_NONE),
 SX_FIELD("mix_volume","uint8",10,1,SX_NONE),
 SX_FIELD("speed","uint8",11,1,SX_NONE),
 SX_FIELD("tempo","uint8",12,1,SX_NONE),
 SX_FIELD("title","char[26]",13,26,SX_NONE),
 SX_FIELD("channel_volume","uint8[64]",39,64,SX_NONE),
 SX_FIELD("channel_pan","uint8[64]",103,64,SX_NONE),
};
static const sx_layout sxlate_ixs_header={0x60930017U,"ixs_header",sxlate_ixs_header_fields,SX_COUNT(sxlate_ixs_header_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_orders_fields[]={
 SX_FIELD("pattern_index","uint8",0,0,SX_NONE),
};
static const sx_layout sxlate_ixs_orders={0x60930018U,"ixs_orders",sxlate_ixs_orders_fields,SX_COUNT(sxlate_ixs_orders_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_record_tag_fields[]={
 SX_FIELD("tag","char[1]",0,1,SX_SIGNATURE),
};
static const sx_layout sxlate_ixs_record_tag={0x60930019U,"ixs_record_tag",sxlate_ixs_record_tag_fields,SX_COUNT(sxlate_ixs_record_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_instrument_fields[]={
 SX_FIELD("fadeout","uint16",0,2,SX_NONE),
 SX_FIELD("global_volume","uint8",2,1,SX_NONE),
 SX_FIELD("default_pan","uint8",3,1,SX_NONE),
 SX_FIELD("first_note","uint8",4,1,SX_NONE),
 SX_FIELD("first_sample_and_map_flag","uint8",5,1,SX_FLAGS),
};
static const sx_layout sxlate_ixs_instrument={0x6093001aU,"ixs_instrument",sxlate_ixs_instrument_fields,SX_COUNT(sxlate_ixs_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_keyboard_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("sample","uint8",1,1,SX_NONE),
};
static const sx_layout sxlate_ixs_keyboard={0x6093001bU,"ixs_keyboard",sxlate_ixs_keyboard_fields,SX_COUNT(sxlate_ixs_keyboard_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_envelope_flags_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxlate_ixs_envelope_flags={0x6093001cU,"ixs_envelope_flags",sxlate_ixs_envelope_flags_fields,SX_COUNT(sxlate_ixs_envelope_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_envelope_fields[]={
 SX_FIELD("point_count","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("loop_begin","uint8",1,1,SX_NONE),
 SX_FIELD("loop_end","uint8",2,1,SX_NONE),
 SX_FIELD("sustain_begin","uint8",3,1,SX_NONE),
 SX_FIELD("sustain_end","uint8",4,1,SX_NONE),
};
static const sx_layout sxlate_ixs_envelope={0x6093001dU,"ixs_envelope",sxlate_ixs_envelope_fields,SX_COUNT(sxlate_ixs_envelope_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_envelope_point_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
 SX_FIELD("tick","uint16",1,2,SX_NONE),
};
static const sx_layout sxlate_ixs_envelope_point={0x6093001eU,"ixs_envelope_point",sxlate_ixs_envelope_point_fields,SX_COUNT(sxlate_ixs_envelope_point_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_sample_fields[]={
 SX_FIELD("global_volume","uint8",0,1,SX_NONE),
 SX_FIELD("flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("volume","uint8",2,1,SX_NONE),
 SX_FIELD("sample_count","uint32",3,4,SX_COUNT_PROP),
 SX_FIELD("loop_begin","uint32",7,4,SX_NONE),
 SX_FIELD("loop_end","uint32",11,4,SX_NONE),
 SX_FIELD("sustain_begin","uint32",15,4,SX_NONE),
 SX_FIELD("sustain_end","uint32",19,4,SX_NONE),
 SX_FIELD("c5_speed","uint32",23,4,SX_NONE),
 SX_FIELD("vibrato_speed","uint8",27,1,SX_NONE),
 SX_FIELD("vibrato_depth","uint8",28,1,SX_NONE),
 SX_FIELD("vibrato_rate","uint8",29,1,SX_NONE),
 SX_FIELD("vibrato_type","uint8",30,1,SX_NONE),
 SX_FIELD("default_pan","uint8",31,1,SX_NONE),
 SX_FIELD("filename","char[13]",32,13,SX_NONE),
};
static const sx_layout sxlate_ixs_sample={0x6093001fU,"ixs_sample",sxlate_ixs_sample_fields,SX_COUNT(sxlate_ixs_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_ixs_pattern_fields[]={
 SX_FIELD("packed_bytes","uint16",0,2,SX_SIZE),
 SX_FIELD("row_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxlate_ixs_pattern={0x60930020U,"ixs_pattern",sxlate_ixs_pattern_fields,SX_COUNT(sxlate_ixs_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_opx_text_header_fields[]={
 SX_FIELD("title","uint8[53]",0,53,SX_NONE),
 SX_FIELD("title_ending","uint8[2]",53,2,SX_NONE),
 SX_FIELD("memo","uint8[53]",55,53,SX_NONE),
 SX_FIELD("memo_ending","uint8[2]",108,2,SX_NONE),
 SX_FIELD("code","uint8[13]",110,13,SX_NONE),
 SX_FIELD("code_ending","uint8[2]",123,2,SX_NONE),
 SX_FIELD("text_eof","uint8",125,1,SX_NONE),
 SX_FIELD("unknown_tail","uint8[2]",126,2,SX_NONE),
};
static const sx_layout sxlate_opx_text_header={0x60930021U,"opx_text_header",sxlate_opx_text_header_fields,SX_COUNT(sxlate_opx_text_header_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_opx_info_fields[]={
 SX_FIELD("unknown_80","uint8[2]",0,2,SX_NONE),
 SX_FIELD("fm_voice_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("unknown_83","uint8",3,1,SX_NONE),
 SX_FIELD("envelope_count","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("mode_flags","uint8",5,1,SX_FLAGS),
 SX_FIELD("version","uint8",6,1,SX_NONE),
 SX_FIELD("track_0_offset","uint16",7,2,SX_OFFSET),
 SX_FIELD("track_1_offset","uint16",9,2,SX_OFFSET),
 SX_FIELD("track_2_offset","uint16",11,2,SX_OFFSET),
 SX_FIELD("track_3_offset","uint16",13,2,SX_OFFSET),
 SX_FIELD("track_4_offset","uint16",15,2,SX_OFFSET),
 SX_FIELD("track_5_offset","uint16",17,2,SX_OFFSET),
 SX_FIELD("track_6_offset","uint16",19,2,SX_OFFSET),
 SX_FIELD("track_7_offset","uint16",21,2,SX_OFFSET),
 SX_FIELD("track_8_offset","uint16",23,2,SX_OFFSET),
 SX_FIELD("track_9_offset","uint16",25,2,SX_OFFSET),
 SX_FIELD("track_10_offset","uint16",27,2,SX_OFFSET),
 SX_FIELD("track_11_offset","uint16",29,2,SX_OFFSET),
};
static const sx_layout sxlate_opx_info={0x60930022U,"opx_info",sxlate_opx_info_fields,SX_COUNT(sxlate_opx_info_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_header_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
 SX_FIELD("order_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("pattern_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("sample_count","uint8",3,1,SX_COUNT_PROP),
 SX_FIELD("fm_instrument_count","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("loop_order","uint8",5,1,SX_NONE),
 SX_FIELD("sample_offset","uint32",6,4,SX_OFFSET),
};
static const sx_layout sxlate_c670_header={0x60930023U,"c670_header",sxlate_c670_header_fields,SX_COUNT(sxlate_c670_header_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_sample_fields[]={
 SX_FIELD("unknown_address_placeholder","uint32",0,4,SX_NONE),
 SX_FIELD("sample_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("loop_begin","uint32",8,4,SX_NONE),
 SX_FIELD("loop_end","uint32",12,4,SX_NONE),
};
static const sx_layout sxlate_c670_sample={0x60930024U,"c670_sample",sxlate_c670_sample_fields,SX_COUNT(sxlate_c670_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_fm_instrument_fields[]={
 SX_FIELD("feedback_connection","uint8",0,1,SX_NONE),
 SX_FIELD("modulator_characteristics","uint8",1,1,SX_NONE),
 SX_FIELD("modulator_level","uint8",2,1,SX_NONE),
 SX_FIELD("modulator_attack_decay","uint8",3,1,SX_NONE),
 SX_FIELD("modulator_sustain_release","uint8",4,1,SX_NONE),
 SX_FIELD("modulator_waveform","uint8",5,1,SX_NONE),
 SX_FIELD("carrier_characteristics","uint8",6,1,SX_NONE),
 SX_FIELD("carrier_level","uint8",7,1,SX_NONE),
 SX_FIELD("carrier_attack_decay","uint8",8,1,SX_NONE),
 SX_FIELD("carrier_sustain_release","uint8",9,1,SX_NONE),
 SX_FIELD("carrier_waveform","uint8",10,1,SX_NONE),
};
static const sx_layout sxlate_c670_fm_instrument={0x60930025U,"c670_fm_instrument",sxlate_c670_fm_instrument_fields,SX_COUNT(sxlate_c670_fm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_orders_fields[]={
 SX_FIELD("pattern_index","uint8",0,0,SX_NONE),
};
static const sx_layout sxlate_c670_orders={0x60930026U,"c670_orders",sxlate_c670_orders_fields,SX_COUNT(sxlate_c670_orders_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_pattern_offset_fields[]={
 SX_FIELD("relative_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxlate_c670_pattern_offset={0x60930027U,"c670_pattern_offset",sxlate_c670_pattern_offset_fields,SX_COUNT(sxlate_c670_pattern_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_note_fields[]={
 SX_FIELD("channel","uint8",0,1,SX_NONE),
 SX_FIELD("note_and_instrument_high","uint8",1,1,SX_NONE),
 SX_FIELD("instrument_low_and_volume","uint8",2,1,SX_NONE),
};
static const sx_layout sxlate_c670_note={0x60930028U,"c670_note",sxlate_c670_note_fields,SX_COUNT(sxlate_c670_note_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_volume_fields[]={
 SX_FIELD("command_channel","uint8",0,1,SX_NONE),
 SX_FIELD("volume","uint8",1,1,SX_NONE),
};
static const sx_layout sxlate_c670_volume={0x60930029U,"c670_volume",sxlate_c670_volume_fields,SX_COUNT(sxlate_c670_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_delay_fields[]={
 SX_FIELD("command","uint8",0,1,SX_NONE),
 SX_FIELD("row_delay","uint8",1,1,SX_NONE),
};
static const sx_layout sxlate_c670_delay={0x6093002aU,"c670_delay",sxlate_c670_delay_fields,SX_COUNT(sxlate_c670_delay_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_c670_end_fields[]={
 SX_FIELD("command","uint8",0,1,SX_NONE),
};
static const sx_layout sxlate_c670_end={0x6093002bU,"c670_end",sxlate_c670_end_fields,SX_COUNT(sxlate_c670_end_fields),SX_LE};
static const xx_data_struct_field_desc sxlate_quartet_header_fields[]={
 SX_FIELD("sampling_rate_khz","uint16",0,2,SX_NONE),
 SX_FIELD("measure","uint16",2,2,SX_NONE),
 SX_FIELD("tempo","uint16",4,2,SX_NONE),
 SX_FIELD("time_signature_numerator","uint8",6,1,SX_NONE),
 SX_FIELD("time_signature_denominator","uint8",7,1,SX_NONE),
 SX_FIELD("reserved","uint8[4]",8,4,SX_NONE),
 SX_FIELD("timer_tag","char[2]",12,2,SX_NONE),
 SX_FIELD("timer_rate","uint16",14,2,SX_NONE),
};
static const sx_layout sxlate_quartet_header={0x6093002cU,"quartet_header",sxlate_quartet_header_fields,SX_COUNT(sxlate_quartet_header_fields),SX_BE};
static const xx_data_struct_field_desc sxlate_quartet_sequence_fields[]={
 SX_FIELD("command","uint16",0,2,SX_NONE),
 SX_FIELD("length","uint16",2,2,SX_NONE),
 SX_FIELD("step","uint32",4,4,SX_NONE),
 SX_FIELD("parameter","uint32",8,4,SX_NONE),
};
static const sx_layout sxlate_quartet_sequence={0x6093002dU,"quartet_sequence",sxlate_quartet_sequence_fields,SX_COUNT(sxlate_quartet_sequence_fields),SX_BE};
static const xx_data_struct_field_desc sxlate_ultima6_header_fields[]={
 SX_FIELD("unpacked_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxlate_ultima6_header={0x6093002eU,"ultima6_header",sxlate_ultima6_header_fields,SX_COUNT(sxlate_ultima6_header_fields),SX_LE};
static const sx_layout*const sx_musiclate_layouts[]={&sxlate_buzz2_header,&sxlate_buzz2_counts,&sxlate_buzz2_capacities,&sxlate_buzz2_pattern,&sxlate_buzz2_sequence,&sxlate_buzz2_name,&sxlate_buzz2_instrument_count,&sxlate_buzz2_instrument,&sxlate_buzz2_connection,&sxlate_buzz2_instrument_tail,&sxlate_buzz2_operation,&sxlate_jxs_header,&sxlate_jxs_subsong,&sxlate_jxs_order,&sxlate_jxs_event,&sxlate_jxs_pattern_name_size,&sxlate_jxs_pattern_name,&sxlate_jxs_instrument,&sxlate_jxs_effect,&sxlate_jxs_sample_info,&sxlate_jxs_wave,&sxlate_jxs_arpeggio,&sxlate_ixs_header,&sxlate_ixs_orders,&sxlate_ixs_record_tag,&sxlate_ixs_instrument,&sxlate_ixs_keyboard,&sxlate_ixs_envelope_flags,&sxlate_ixs_envelope,&sxlate_ixs_envelope_point,&sxlate_ixs_sample,&sxlate_ixs_pattern,&sxlate_opx_text_header,&sxlate_opx_info,&sxlate_c670_header,&sxlate_c670_sample,&sxlate_c670_fm_instrument,&sxlate_c670_orders,&sxlate_c670_pattern_offset,&sxlate_c670_note,&sxlate_c670_volume,&sxlate_c670_delay,&sxlate_c670_end,&sxlate_quartet_header,&sxlate_quartet_sequence,&sxlate_ultima6_header};
static bool sxlate_span(sx_context*c,uint64_t p,uint64_t n,uint64_t end)
{return c&&c->size>=0&&end<=(uint64_t)c->size&&p<=end&&n<=end-p&&!xx_pd_is_stopped(c->pd);}
static bool sxlate_read(sx_context*c,uint64_t p,void*b,size_t n,uint64_t end)
{return sxlate_span(c,p,n,end)&&sx_read(c,(int64_t)p,b,n);}
static bool sxlate_byte(sx_context*c,uint64_t p,uint8_t*b,uint64_t end)
{return sxlate_read(c,p,b,1,end);}
static bool sxlate_row(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,uint64_t end)
{return sxlate_span(c,p,n,end)&&sx_add(c,l,(int64_t)p,(int64_t)n);}
static bool sxlate_plane(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t n,uint64_t end)
{
    if(!sxlate_span(c,*p,n,end))return false;
    uint64_t shown=n>4096?4096:n;
    if(shown&&!sx_add(c,l,(int64_t)*p,(int64_t)shown))return false;
    *p+=n;return true;
}
static bool sxlate_string(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t end)
{
    uint64_t start=*p;uint8_t b;
    while(*p<end&&*p-start<4096){
        if(!sxlate_byte(c,(*p)++,&b,end))return false;
        if(!b)return sxlate_row(c,l,start,*p-start,end);
    }
    return false;
}
static int sxlate_order(const void*a,const void*b)
{const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxlate_finish(sx_context*c)
{
    size_t n=c->count;uint64_t end=0;
    xx_rt_qsort(c->items,n,sizeof(*c->items),sxlate_order);
    for(size_t i=0;i<n;i++){
        uint64_t at=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;
        if(at<end)return false;
        if(at>end&&!sx_raw(c,(int64_t)end,(int64_t)(at-end)))return false;
        end=at+z;
    }
    if(end<(uint64_t)c->size&&!sx_raw(c,(int64_t)end,c->size-(int64_t)end))return false;
    xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxlate_order);
    return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sxlate_table(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t stride,uint64_t count,uint64_t end)
{
    if(!stride||count>UINT64_MAX/stride||!sxlate_span(c,*p,count*stride,end))return false;
    if(count&&!sx_table(c,l,(int64_t)*p,(int64_t)stride,count))return false;
    *p+=count*stride;return true;
}
static bool sxlate_u32(sx_context*c,uint64_t p,uint32_t*v,uint64_t end)
{return sxlate_span(c,p,4,end)&&sx_u32(c,(int64_t)p,false,v);}
static bool sxlate_buzz2(sx_context*c)
{
    uint64_t end=(uint64_t)c->size,p=156;uint8_t h[8];uint32_t patterns=64,sequences=64,length=128,instruments;
    if(!sxlate_read(c,0,h,8,end)||xx_rt_memcmp(h,"buz2",4)||xx_data_get_u16(h,8,4,false)!=2||!sxlate_row(c,&sxlate_buzz2_header,0,156,end)||!sxlate_row(c,&sxlate_buzz2_counts,p,8,end))return false;
    p+=8;
    if(xx_data_get_u16(h,8,6,false)){
        if(!sxlate_row(c,&sxlate_buzz2_capacities,p,12,end)||!sxlate_u32(c,p,&patterns,end)||!sxlate_u32(c,p+4,&sequences,end)||!sxlate_u32(c,p+8,&length,end))return false;
        p+=12;
    }
    if(patterns>1024||sequences>1024||!length||length>4096)return true;
    if(!sxlate_table(c,&sxlate_buzz2_pattern,&p,16,patterns,end))return false;
    for(uint32_t i=0;i<sequences;i++)if(!sxlate_plane(c,&sxlate_buzz2_sequence,&p,length,end))return false;
    if(!sxlate_table(c,&sxlate_buzz2_name,&p,64,128,end)||!sxlate_u32(c,p,&instruments,end)||!sxlate_row(c,&sxlate_buzz2_instrument_count,p,4,end))return false;
    p+=4;if(instruments>128)return true;
    for(uint32_t i=0;i<instruments;i++){
        uint32_t operations;
        if(!sxlate_u32(c,p+388,&operations,end)||!sxlate_row(c,&sxlate_buzz2_instrument,p,392,end))return false;
        p+=392;
        if(!sxlate_table(c,&sxlate_buzz2_connection,&p,12,640,end)||!sxlate_row(c,&sxlate_buzz2_instrument_tail,p,1160,end))return false;
        p+=1160;
        if(operations>64)return true;
        if(!sxlate_table(c,&sxlate_buzz2_operation,&p,552,operations,end))return false;
    }
    return true;
}
static bool sxlate_jxs(sx_context*c)
{
    uint8_t h[16];uint64_t end=(uint64_t)c->size,p=52;uint32_t patterns,songs,instruments;
    if(!sxlate_read(c,0,h,16,end))return false;
    uint16_t version=xx_data_get_u16(h,16,0,false);
    if(version<3456||version>3457||!sxlate_row(c,&sxlate_jxs_header,0,52,end))return false;
    patterns=xx_data_get_u32(h,16,4,false);songs=xx_data_get_u32(h,16,8,false);instruments=xx_data_get_u32(h,16,12,false);
    if(patterns>4096||songs>256||instruments>256)return true;
    for(uint32_t i=0;i<songs;i++){
        if(!sxlate_row(c,&sxlate_jxs_subsong,p,180,end))return false;p+=180;
        if(!sxlate_table(c,&sxlate_jxs_order,&p,4,4096,end))return false;
    }
    if(!sxlate_table(c,&sxlate_jxs_event,&p,5,(uint64_t)patterns*64,end))return false;
    for(uint32_t i=0;i<patterns;i++){
        uint32_t n;
        if(!sxlate_u32(c,p,&n,end)||!sxlate_row(c,&sxlate_jxs_pattern_name_size,p,4,end))return false;p+=4;
        if(n>4096)return true;
        if(n&&!sxlate_row(c,&sxlate_jxs_pattern_name,p,n,end))return false;p+=n;
    }
    for(uint32_t i=0;i<instruments;i++){
        uint32_t pointer,n;
        if(!sxlate_u32(c,p+512,&pointer,end)||!sxlate_u32(c,p+516,&n,end)||!sxlate_row(c,&sxlate_jxs_instrument,p,92,end))return false;p+=92;
        if(!sxlate_table(c,&sxlate_jxs_effect,&p,40,4,end)||!sxlate_row(c,&sxlate_jxs_sample_info,p,268,end))return false;p+=268;
        if(!sxlate_table(c,&sxlate_jxs_wave,&p,512,16,end))return false;
        if(pointer){if(!sxlate_span(c,p,n,end))return false;p+=n;}
    }
    return sxlate_table(c,&sxlate_jxs_arpeggio,&p,16,16,end);
}
static bool sxlate_ixs(sx_context*c)
{
    uint8_t h[9],tag;uint64_t end=(uint64_t)c->size,p=167;
    if(!sxlate_read(c,0,h,9,end)||h[0]!=33||!sxlate_row(c,&sxlate_ixs_header,0,167,end))return false;
    uint16_t orders=xx_data_get_u16(h,9,1,false),instruments=xx_data_get_u16(h,9,3,false),samples=xx_data_get_u16(h,9,5,false),patterns=xx_data_get_u16(h,9,7,false);
    if(!sxlate_plane(c,&sxlate_ixs_orders,&p,orders,end))return false;
    if(instruments>1024||samples>1024||patterns>4096)return true;
    for(unsigned i=0;i<instruments;i++){
        if(!sxlate_byte(c,p,&tag,end)||(tag!='I'&&tag!='i')||!sxlate_row(c,&sxlate_ixs_record_tag,p++,1,end))return false;
        if(tag=='i')continue;
        uint8_t flags;
        if(!sxlate_byte(c,p+5,&flags,end)||!sxlate_row(c,&sxlate_ixs_instrument,p,6,end))return false;p+=6;
        if(!(flags&128)&&!sxlate_table(c,&sxlate_ixs_keyboard,&p,2,119,end))return false;
        for(unsigned e=0;e<3;e++){
            if(!sxlate_byte(c,p,&flags,end)||!sxlate_row(c,&sxlate_ixs_envelope_flags,p++,1,end))return false;
            if(flags){uint8_t count;
                if(!sxlate_byte(c,p,&count,end)||!sxlate_row(c,&sxlate_ixs_envelope,p,5,end))return false;p+=5;
                if(!sxlate_table(c,&sxlate_ixs_envelope_point,&p,3,count,end))return false;
            }
        }
    }
    for(unsigned i=0;i<samples;i++){
        if(!sxlate_byte(c,p,&tag,end)||(tag!='S'&&tag!='s')||!sxlate_row(c,&sxlate_ixs_record_tag,p++,1,end))return false;
        if(tag=='S'){if(!sxlate_row(c,&sxlate_ixs_sample,p,45,end))return false;p+=45;}
    }
    for(unsigned i=0;i<patterns;i++){
        if(!sxlate_byte(c,p,&tag,end)||(tag!='P'&&tag!='p')||!sxlate_row(c,&sxlate_ixs_record_tag,p++,1,end))return false;
        if(tag=='P'){uint16_t n;
            if(!sxlate_span(c,p,4,end)||!sx_u16(c,(int64_t)p,false,&n)||!sxlate_row(c,&sxlate_ixs_pattern,p,4,end))return false;p+=4;
            if(!sxlate_span(c,p,n,end))return false;p+=n;
        }
    }
    /* External SFXI/sample-cache data is not part of this physical reader. */
    return true;
}
static bool sxlate_opx_at(sx_context*c,uint64_t p)
{
    uint64_t end=(uint64_t)c->size;uint8_t h[159];
    if(!sxlate_read(c,p,h,sizeof(h),end))return false;
    bool marked=!xx_rt_memcmp(h+122," \r\n\032",4)&&!xx_rt_memcmp(h+53,"\r\n",2)&&!xx_rt_memcmp(h+108,"\r\n",2);
    if(!marked&&xx_rt_memcmp(h+122,"    ",4))return false;
    if(h[134]>1)return false;
    for(unsigned i=0;i<12;i++)if(xx_data_get_u16(h,sizeof(h),135+i*2,false)>=0x4000)return false;
    return sxlate_row(c,&sxlate_opx_text_header,p,128,end)&&sxlate_row(c,&sxlate_opx_info,p+128,31,end);
}
static bool sxlate_c670(sx_context*c)
{
    uint64_t end=(uint64_t)c->size,p=10;uint8_t h[10];uint32_t offsets[256];
    if(!sxlate_read(c,0,h,10,end)||!h[0]||h[0]>15||!sxlate_row(c,&sxlate_c670_header,0,10,end))return false;
    uint32_t sample_offset=xx_data_get_u32(h,10,6,false);unsigned orders=h[1],patterns=h[2],samples=h[3],fm=h[4];
    if(sample_offset>end||!sxlate_plane(c,&sxlate_c670_orders,&p,orders,end))return false;
    for(unsigned i=0;i<patterns;i++)if(!sxlate_u32(c,p+i*4,&offsets[i],end))return false;
    if(!sxlate_table(c,&sxlate_c670_pattern_offset,&p,4,patterns,end)||!sxlate_table(c,&sxlate_c670_sample,&p,16,samples,end)||!sxlate_table(c,&sxlate_c670_fm_instrument,&p,11,fm,end))return false;
    uint64_t base=p;
    if(base>sample_offset)return false;
    for(unsigned i=0;i<patterns;i++){
        uint64_t q=base+offsets[i],stop=i+1<patterns?base+offsets[i+1]:sample_offset;
        if(q<base||q>stop||stop>sample_offset)return false;
        while(q<stop&&c->count<30000){uint8_t cmd;const sx_layout*l;uint64_t n;
            if(!sxlate_byte(c,q,&cmd,stop))return false;
            if(cmd<=12){l=&sxlate_c670_note;n=3;}
            else if(cmd>=32&&cmd<=44){l=&sxlate_c670_volume;n=2;}
            else if(cmd>=64&&cmd<96){l=&sxlate_c670_delay;n=2;}
            else if(cmd>=96&&cmd<128){l=&sxlate_c670_end;n=1;}
            else return true;
            if(!sxlate_row(c,l,q,n,stop))return false;q+=n;
            if(cmd>=96&&cmd<128)break;
        }
        if(c->count>=30000)return true;
    }
    return true;
}
static bool sxlate_quartet(sx_context*c)
{
    uint64_t end=(uint64_t)c->size,p=16;unsigned channels=0;uint16_t cmd;
    if(!sxlate_row(c,&sxlate_quartet_header,0,16,end))return false;
    while(end-p>=12&&channels<4&&c->count<30000){
        if(!sx_u16(c,(int64_t)p,true,&cmd))return false;
        if(cmd!='F'&&cmd!='P'&&cmd!='S'&&cmd!='R'&&cmd!='L'&&cmd!='V'&&cmd!='l')return true;
        if(!sxlate_row(c,&sxlate_quartet_sequence,p,12,end))return false;p+=12;
        if(cmd=='F')++channels;
    }
    return true;
}
static bool sxlate_ultima6(sx_context*c)
{
    uint8_t h[6];uint64_t end=(uint64_t)c->size;
    if(!sxlate_read(c,0,h,6,end)||h[2]||h[3]||h[4]||!(h[5]&1))return false;
    return sxlate_row(c,&sxlate_ultima6_header,0,4,end);
}
static bool sx_musiclate_supports(xx_file_type_t t)
{
    switch(t){
    case XX_FILE_TYPE_DIE_MUSIC_STEPANOV_BUZZIC2:
    case XX_FILE_TYPE_DIE_MUSIC_RHINO_JAYTRAXSYNTRAX_JXS:
    case XX_FILE_TYPE_DIE_MUSIC_SAHARASURFERS_IXALANCE_IXS_UNP:
    case XX_FILE_TYPE_DIE_MUSIC_MSXPERFORMER_OPX:
    case XX_FILE_TYPE_DIE_MUSIC_TRAN_CDFM_COMPOSER670_CO:
    case XX_FILE_TYPE_DIE_MUSIC_MICRODEAL_QUARTET_SMP:
    case XX_FILE_TYPE_DIE_MUSIC_ORIGINSYSTEMS_ULTIMA6:return true;
    default:return false;
    }
}
static bool sx_musiclate_build(sx_context*c)
{
    if(!c||!c->f||!sx_musiclate_supports(c->f->file_type)||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<0)return false;
    bool ok=false;
    switch(c->f->file_type){
    case XX_FILE_TYPE_DIE_MUSIC_STEPANOV_BUZZIC2:ok=sxlate_buzz2(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_RHINO_JAYTRAXSYNTRAX_JXS:ok=sxlate_jxs(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_SAHARASURFERS_IXALANCE_IXS_UNP:ok=sxlate_ixs(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_MSXPERFORMER_OPX:ok=sxlate_opx_at(c,0)||sxlate_opx_at(c,0xC00);break;
    case XX_FILE_TYPE_DIE_MUSIC_TRAN_CDFM_COMPOSER670_CO:ok=sxlate_c670(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_MICRODEAL_QUARTET_SMP:ok=sxlate_quartet(c);break;
    case XX_FILE_TYPE_DIE_MUSIC_ORIGINSYSTEMS_ULTIMA6:ok=sxlate_ultima6(c);break;
    default:break;
    }
    return ok&&sxlate_finish(c);
}
static bool sx_musiclate_comment(xx_data_struct_record*r,uint32_t id)
{
    if(!r||!r->name||id<0x60930001U||id>sxlate_ultima6_header.id)return true;
    const wchar_t*s=L"Physical stored member; music playback and decoded or generated payload values are not represented here.";
    if(id==sxlate_buzz2_header.id)s=L"Original Buzzic2 Win32 file header, including its three stored alignment bytes. Version halves are little-endian; master volume is IEEE754 binary32.";
    else if(id==sxlate_buzz2_operation.id||id==sxlate_buzz2_instrument.id)s=L"Original Win32 object snapshot. Pointer and vtable values are stored 32-bit snapshots, never dereferenced. Operator parameters preserve IEEE754 binary32 values.";
    else if(id==sxlate_jxs_sample_info.id)s=L"Stored Jaytrax sample metadata. A nonzero saved sample pointer means sample_bytes follow the sixteen waveform tables. No virtual pointer is used.";
    else if(id==sxlate_jxs_subsong.id)s=L"Packed Jaytrax subsong metadata followed by sixteen channels of 256 order records. Stored signed integers are preserved.";
    else if(id==sxlate_ixs_instrument.id)s=L"High bit of first_sample_and_map_flag suppresses the remaining 119 keyboard mappings; they are synthesized by the player and are not physical file members.";
    else if(id==sxlate_ixs_pattern.id)s=L"The packed pattern byte count excludes this four-byte header. Event decompression and external sample caches are outside this physical view.";
    else if(id==sxlate_opx_text_header.id)s=L"Original MSX OPLLdriver2 title, memo and code byte ranges. Encoded text bytes are preserved without a lossy character conversion.";
    else if(id==sxlate_opx_info.id)s=L"Track offsets are relative to the music-data block and are bounded by the original driver's 16 KiB storage. Unproven information bytes remain explicitly unknown.";
    else if(id==sxlate_c670_pattern_offset.id)s=L"Little-endian byte offset relative to the beginning of compact .670 pattern data, immediately after the instrument records.";
    else if(id==sxlate_c670_delay.id)s=L"DELAY: command class 010xxxxx; the low five command bits are ignored by the original player. row_delay advances the pattern. The following command starts after two bytes.";
    else if(id==sxlate_c670_end.id)s=L"END_PATTERN: command class 011xxxxx; the low five command bits are ignored by the original player.";
    else if(id==sxlate_c670_header.id)s=L"Compact Composer670 header from the author's converter source. sample_offset is an absolute file offset; playback speed is not beats per minute.";
    else if(id==sxlate_quartet_header.id)s=L"Quartet score header, stored big-endian. A WT timer tag enables the trailing timer rate; without WT those bytes are reserved.";
    else if(id==sxlate_quartet_sequence.id)s=L"Stored 12-byte Quartet score command. F ends a channel, P plays, S slides, R rests, L/l control loops, V selects a voice. Parameter interpretation depends on the command.";
    else if(id==sxlate_ultima6_header.id)s=L"Ultima 6 LZW container header. unpacked_bytes is the stored output length; the compressed music stream stays raw.";
    return xx_data_struct_record_set_comment(r,s);
}
