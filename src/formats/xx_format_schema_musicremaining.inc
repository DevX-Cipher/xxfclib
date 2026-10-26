/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical music header and table metadata; compressed and unknown bodies stay raw. */
static const xx_data_struct_field_desc sxmr_ams2_magic_fields[]={
 SX_FIELD("magic","bytes",0,7,SX_SIGNATURE),
 SX_FIELD("title_bytes","uint8",7,1,SX_SIZE),
};
static const sx_layout sxmr_ams2_magic={UINT32_C(0x607D0001),"ams2_magic",sxmr_ams2_magic_fields,SX_COUNT(sxmr_ams2_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_header_fields[]={
 SX_FIELD("minor","uint8",0,1,SX_ID),
 SX_FIELD("major","uint8",1,1,SX_ID),
 SX_FIELD("instruments","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("patterns","uint16",3,2,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",5,2,SX_COUNT_PROP),
};
static const sx_layout sxmr_ams2_header={UINT32_C(0x607D0002),"ams2_header",sxmr_ams2_header_fields,SX_COUNT(sxmr_ams2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_timing20_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("speed","uint8",1,1,SX_NONE),
 SX_FIELD("flags","uint8",2,1,SX_FLAGS),
};
static const sx_layout sxmr_ams2_timing20={UINT32_C(0x607D0003),"ams2_timing20",sxmr_ams2_timing20_fields,SX_COUNT(sxmr_ams2_timing20_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_timing22_fields[]={
 SX_FIELD("tempo_8_8","uint16",0,2,SX_NONE),
 SX_FIELD("speed","uint8",2,1,SX_NONE),
 SX_FIELD("editor_defaults","bytes",3,3,SX_NONE),
 SX_FIELD("flags","uint16",6,2,SX_FLAGS),
};
static const sx_layout sxmr_ams2_timing22={UINT32_C(0x607D0004),"ams2_timing22",sxmr_ams2_timing22_fields,SX_COUNT(sxmr_ams2_timing22_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_pascal_text_length_fields[]={
 SX_FIELD("text_bytes","uint8",0,1,SX_SIZE),
};
static const sx_layout sxmr_pascal_text_length={UINT32_C(0x607D0005),"pascal_text_length",sxmr_pascal_text_length_fields,SX_COUNT(sxmr_pascal_text_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_text_fields[]={
 SX_FIELD("text","char",0,0,SX_NONE),
};
static const sx_layout sxmr_text={UINT32_C(0x607D0006),"text",sxmr_text_fields,SX_COUNT(sxmr_text_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_nul_fields[]={
 SX_FIELD("terminator","uint8",0,1,SX_SIGNATURE),
};
static const sx_layout sxmr_nul={UINT32_C(0x607D0007),"nul",sxmr_nul_fields,SX_COUNT(sxmr_nul_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_sample_count_fields[]={
 SX_FIELD("samples","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxmr_ams2_sample_count={UINT32_C(0x607D0008),"ams2_sample_count",sxmr_ams2_sample_count_fields,SX_COUNT(sxmr_ams2_sample_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_note_sample_fields[]={
 SX_FIELD("sample_index","uint8",0,1,SX_ID),
};
static const sx_layout sxmr_ams2_note_sample={UINT32_C(0x607D0009),"ams2_note_sample",sxmr_ams2_note_sample_fields,SX_COUNT(sxmr_ams2_note_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_envelope_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
 SX_FIELD("sustain_point","uint8",1,1,SX_NONE),
 SX_FIELD("loop_start_point","uint8",2,1,SX_NONE),
 SX_FIELD("loop_end_point","uint8",3,1,SX_NONE),
 SX_FIELD("points","uint8",4,1,SX_COUNT_PROP),
};
static const sx_layout sxmr_ams2_envelope={UINT32_C(0x607D000A),"ams2_envelope",sxmr_ams2_envelope_fields,SX_COUNT(sxmr_ams2_envelope_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_envelope_point_fields[]={
 SX_FIELD("delta_low","uint8",0,1,SX_NONE),
 SX_FIELD("delta_flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("value","uint8",2,1,SX_NONE),
};
static const sx_layout sxmr_ams2_envelope_point={UINT32_C(0x607D000B),"ams2_envelope_point",sxmr_ams2_envelope_point_fields,SX_COUNT(sxmr_ams2_envelope_point_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_instrument_fields[]={
 SX_FIELD("shadow_instrument","uint8",0,1,SX_ID),
 SX_FIELD("vibrato_fadeout","uint16",1,2,SX_FLAGS),
 SX_FIELD("envelope_flags","uint16",3,2,SX_FLAGS),
};
static const sx_layout sxmr_ams2_instrument={UINT32_C(0x607D000C),"ams2_instrument",sxmr_ams2_instrument_fields,SX_COUNT(sxmr_ams2_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_sample_fields[]={
 SX_FIELD("sample_frames","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("loop_start_frame","uint32",4,4,SX_NONE),
 SX_FIELD("loop_end_frame","uint32",8,4,SX_NONE),
 SX_FIELD("recorded_rate","uint16",12,2,SX_NONE),
 SX_FIELD("pan_finetune","uint8",14,1,SX_FLAGS),
 SX_FIELD("c4_rate","uint16",15,2,SX_NONE),
 SX_FIELD("relative_tone","int8",17,1,SX_NONE),
 SX_FIELD("volume","uint8",18,1,SX_NONE),
 SX_FIELD("flags","uint8",19,1,SX_FLAGS),
};
static const sx_layout sxmr_ams2_sample={UINT32_C(0x607D000D),"ams2_sample",sxmr_ams2_sample_fields,SX_COUNT(sxmr_ams2_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_description_fields[]={
 SX_FIELD("packed_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("unpacked_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("pack_routine","uint8",8,1,SX_ID),
 SX_FIELD("preprocessing","uint8",9,1,SX_ID),
 SX_FIELD("packing_method","uint8",10,1,SX_ID),
};
static const sx_layout sxmr_ams2_description={UINT32_C(0x607D000E),"ams2_description",sxmr_ams2_description_fields,SX_COUNT(sxmr_ams2_description_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_order16_fields[]={
 SX_FIELD("pattern","uint16",0,2,SX_ID),
};
static const sx_layout sxmr_order16={UINT32_C(0x607D000F),"order16",sxmr_order16_fields,SX_COUNT(sxmr_order16_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_ams2_pattern_fields[]={
 SX_FIELD("packed_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("rows_minus_one","uint8",4,1,SX_NONE),
 SX_FIELD("channels_commands","uint8",5,1,SX_FLAGS),
};
static const sx_layout sxmr_ams2_pattern={UINT32_C(0x607D0010),"ams2_pattern",sxmr_ams2_pattern_fields,SX_COUNT(sxmr_ams2_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_cba_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("title","char[32]",4,32,SX_NONE),
 SX_FIELD("eof_marker","uint8",36,1,SX_SIGNATURE),
 SX_FIELD("message_bytes","uint16",37,2,SX_SIZE),
 SX_FIELD("channels","uint8",39,1,SX_COUNT_PROP),
 SX_FIELD("last_pattern","uint8",40,1,SX_NONE),
 SX_FIELD("orders","uint8",41,1,SX_COUNT_PROP),
 SX_FIELD("samples","uint8",42,1,SX_COUNT_PROP),
 SX_FIELD("speed","uint8",43,1,SX_NONE),
 SX_FIELD("tempo","uint8",44,1,SX_NONE),
};
static const sx_layout sxmr_cba_header={UINT32_C(0x607D0011),"cba_header",sxmr_cba_header_fields,SX_COUNT(sxmr_cba_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_pan_position_fields[]={
 SX_FIELD("pan","uint8",0,1,SX_NONE),
};
static const sx_layout sxmr_pan_position={UINT32_C(0x607D0012),"pan_position",sxmr_pan_position_fields,SX_COUNT(sxmr_pan_position_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_order8_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
};
static const sx_layout sxmr_order8={UINT32_C(0x607D0013),"order8",sxmr_order8_fields,SX_COUNT(sxmr_order8_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_cba_sample_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_NONE),
 SX_FIELD("flags","uint8",32,1,SX_FLAGS),
 SX_FIELD("volume","uint8",33,1,SX_NONE),
 SX_FIELD("sample_rate","uint16",34,2,SX_NONE),
 SX_FIELD("sample_bytes","uint32",36,4,SX_SIZE),
 SX_FIELD("loop_start","uint32",40,4,SX_OFFSET),
 SX_FIELD("loop_end","uint32",44,4,SX_OFFSET),
};
static const sx_layout sxmr_cba_sample={UINT32_C(0x607D0014),"cba_sample",sxmr_cba_sample_fields,SX_COUNT(sxmr_cba_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_cba_event_fields[]={
 SX_FIELD("instrument","uint8",0,1,SX_ID),
 SX_FIELD("note","uint8",1,1,SX_NONE),
 SX_FIELD("volume","uint8",2,1,SX_NONE),
 SX_FIELD("effect","uint8",3,1,SX_ID),
 SX_FIELD("parameter","uint8",4,1,SX_NONE),
};
static const sx_layout sxmr_cba_event={UINT32_C(0x607D0015),"cba_event",sxmr_cba_event_fields,SX_COUNT(sxmr_cba_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_plm_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("header_bytes","uint8",4,1,SX_SIZE),
 SX_FIELD("version","uint8",5,1,SX_ID),
 SX_FIELD("title","char[48]",6,48,SX_NONE),
 SX_FIELD("channels","uint8",54,1,SX_COUNT_PROP),
 SX_FIELD("flags","uint8",55,1,SX_FLAGS),
 SX_FIELD("max_volume","uint8",56,1,SX_NONE),
 SX_FIELD("amplification","uint8",57,1,SX_NONE),
 SX_FIELD("tempo","uint8",58,1,SX_NONE),
 SX_FIELD("speed","uint8",59,1,SX_NONE),
 SX_FIELD("pan_positions","bytes",60,32,SX_NONE),
 SX_FIELD("samples","uint8",92,1,SX_COUNT_PROP),
 SX_FIELD("patterns","uint8",93,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",94,2,SX_COUNT_PROP),
};
static const sx_layout sxmr_plm_header={UINT32_C(0x607D0016),"plm_header",sxmr_plm_header_fields,SX_COUNT(sxmr_plm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_plm_order_fields[]={
 SX_FIELD("start_row","uint16",0,2,SX_NONE),
 SX_FIELD("first_channel","uint8",2,1,SX_ID),
 SX_FIELD("pattern","uint8",3,1,SX_ID),
};
static const sx_layout sxmr_plm_order={UINT32_C(0x607D0017),"plm_order",sxmr_plm_order_fields,SX_COUNT(sxmr_plm_order_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_pattern_offset_fields[]={
 SX_FIELD("pattern_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmr_pattern_offset={UINT32_C(0x607D0018),"pattern_offset",sxmr_pattern_offset_fields,SX_COUNT(sxmr_pattern_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_sample_offset_fields[]={
 SX_FIELD("sample_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmr_sample_offset={UINT32_C(0x607D0019),"sample_offset",sxmr_sample_offset_fields,SX_COUNT(sxmr_sample_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_instrument_offset_fields[]={
 SX_FIELD("instrument_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmr_instrument_offset={UINT32_C(0x607D001A),"instrument_offset",sxmr_instrument_offset_fields,SX_COUNT(sxmr_instrument_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_plm_sample_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("header_bytes","uint8",4,1,SX_SIZE),
 SX_FIELD("version","uint8",5,1,SX_ID),
 SX_FIELD("name","char[32]",6,32,SX_NONE),
 SX_FIELD("filename","char[12]",38,12,SX_NONE),
 SX_FIELD("pan","uint8",50,1,SX_NONE),
 SX_FIELD("volume","uint8",51,1,SX_NONE),
 SX_FIELD("flags","uint8",52,1,SX_FLAGS),
 SX_FIELD("sample_rate","uint16",53,2,SX_NONE),
 SX_FIELD("reserved","bytes",55,4,SX_RESERVED),
 SX_FIELD("loop_start","uint32",59,4,SX_OFFSET),
 SX_FIELD("loop_end","uint32",63,4,SX_OFFSET),
 SX_FIELD("sample_bytes","uint32",67,4,SX_SIZE),
};
static const sx_layout sxmr_plm_sample={UINT32_C(0x607D001B),"plm_sample",sxmr_plm_sample_fields,SX_COUNT(sxmr_plm_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_plm_pattern_fields[]={
 SX_FIELD("pattern_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("rows","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("channels","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("color","uint8",6,1,SX_ID),
 SX_FIELD("name","char[25]",7,25,SX_NONE),
};
static const sx_layout sxmr_plm_pattern={UINT32_C(0x607D001C),"plm_pattern",sxmr_plm_pattern_fields,SX_COUNT(sxmr_plm_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_plm_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("volume","uint8",2,1,SX_NONE),
 SX_FIELD("effect","uint8",3,1,SX_ID),
 SX_FIELD("parameter","uint8",4,1,SX_NONE),
};
static const sx_layout sxmr_plm_event={UINT32_C(0x607D001D),"plm_event",sxmr_plm_event_fields,SX_COUNT(sxmr_plm_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_mxm_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("orders","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("restart_order","uint32",8,4,SX_NONE),
 SX_FIELD("channels","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("patterns","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("instruments","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("ticks_per_row","uint8",24,1,SX_NONE),
 SX_FIELD("beats_per_minute","uint8",25,1,SX_NONE),
 SX_FIELD("options","uint16",26,2,SX_FLAGS),
 SX_FIELD("sample_data_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("samples_8bit","uint32",32,4,SX_COUNT_PROP),
 SX_FIELD("samples_16bit","uint32",36,4,SX_COUNT_PROP),
 SX_FIELD("lowest_pitch","int32",40,4,SX_NONE),
 SX_FIELD("highest_pitch","int32",44,4,SX_NONE),
 SX_FIELD("pan_positions","bytes",48,32,SX_NONE),
};
static const sx_layout sxmr_mxm_header={UINT32_C(0x607D001E),"mxm_header",sxmr_mxm_header_fields,SX_COUNT(sxmr_mxm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_mxm_instrument_fields[]={
 SX_FIELD("samples","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("note_sample_map","bytes",4,96,SX_NONE),
 SX_FIELD("volume_fadeout","uint16",100,2,SX_NONE),
 SX_FIELD("vibrato_type","uint8",102,1,SX_ID),
 SX_FIELD("vibrato_sweep","uint8",103,1,SX_NONE),
 SX_FIELD("vibrato_depth","uint8",104,1,SX_NONE),
 SX_FIELD("vibrato_rate","uint8",105,1,SX_NONE),
 SX_FIELD("volume_last_point","uint8",106,1,SX_NONE),
 SX_FIELD("volume_sustain","uint8",107,1,SX_NONE),
 SX_FIELD("volume_loop_start","uint8",108,1,SX_NONE),
 SX_FIELD("volume_loop_end","uint8",109,1,SX_NONE),
 SX_FIELD("volume_0_delta_ticks","uint16",110,2,SX_NONE),
 SX_FIELD("volume_0_value","uint16",112,2,SX_NONE),
 SX_FIELD("volume_1_delta_ticks","uint16",114,2,SX_NONE),
 SX_FIELD("volume_1_value","uint16",116,2,SX_NONE),
 SX_FIELD("volume_2_delta_ticks","uint16",118,2,SX_NONE),
 SX_FIELD("volume_2_value","uint16",120,2,SX_NONE),
 SX_FIELD("volume_3_delta_ticks","uint16",122,2,SX_NONE),
 SX_FIELD("volume_3_value","uint16",124,2,SX_NONE),
 SX_FIELD("volume_4_delta_ticks","uint16",126,2,SX_NONE),
 SX_FIELD("volume_4_value","uint16",128,2,SX_NONE),
 SX_FIELD("volume_5_delta_ticks","uint16",130,2,SX_NONE),
 SX_FIELD("volume_5_value","uint16",132,2,SX_NONE),
 SX_FIELD("volume_6_delta_ticks","uint16",134,2,SX_NONE),
 SX_FIELD("volume_6_value","uint16",136,2,SX_NONE),
 SX_FIELD("volume_7_delta_ticks","uint16",138,2,SX_NONE),
 SX_FIELD("volume_7_value","uint16",140,2,SX_NONE),
 SX_FIELD("volume_8_delta_ticks","uint16",142,2,SX_NONE),
 SX_FIELD("volume_8_value","uint16",144,2,SX_NONE),
 SX_FIELD("volume_9_delta_ticks","uint16",146,2,SX_NONE),
 SX_FIELD("volume_9_value","uint16",148,2,SX_NONE),
 SX_FIELD("volume_10_delta_ticks","uint16",150,2,SX_NONE),
 SX_FIELD("volume_10_value","uint16",152,2,SX_NONE),
 SX_FIELD("volume_11_delta_ticks","uint16",154,2,SX_NONE),
 SX_FIELD("volume_11_value","uint16",156,2,SX_NONE),
 SX_FIELD("pan_last_point","uint8",158,1,SX_NONE),
 SX_FIELD("pan_sustain","uint8",159,1,SX_NONE),
 SX_FIELD("pan_loop_start","uint8",160,1,SX_NONE),
 SX_FIELD("pan_loop_end","uint8",161,1,SX_NONE),
 SX_FIELD("pan_0_delta_ticks","uint16",162,2,SX_NONE),
 SX_FIELD("pan_0_value","uint16",164,2,SX_NONE),
 SX_FIELD("pan_1_delta_ticks","uint16",166,2,SX_NONE),
 SX_FIELD("pan_1_value","uint16",168,2,SX_NONE),
 SX_FIELD("pan_2_delta_ticks","uint16",170,2,SX_NONE),
 SX_FIELD("pan_2_value","uint16",172,2,SX_NONE),
 SX_FIELD("pan_3_delta_ticks","uint16",174,2,SX_NONE),
 SX_FIELD("pan_3_value","uint16",176,2,SX_NONE),
 SX_FIELD("pan_4_delta_ticks","uint16",178,2,SX_NONE),
 SX_FIELD("pan_4_value","uint16",180,2,SX_NONE),
 SX_FIELD("pan_5_delta_ticks","uint16",182,2,SX_NONE),
 SX_FIELD("pan_5_value","uint16",184,2,SX_NONE),
 SX_FIELD("pan_6_delta_ticks","uint16",186,2,SX_NONE),
 SX_FIELD("pan_6_value","uint16",188,2,SX_NONE),
 SX_FIELD("pan_7_delta_ticks","uint16",190,2,SX_NONE),
 SX_FIELD("pan_7_value","uint16",192,2,SX_NONE),
 SX_FIELD("pan_8_delta_ticks","uint16",194,2,SX_NONE),
 SX_FIELD("pan_8_value","uint16",196,2,SX_NONE),
 SX_FIELD("pan_9_delta_ticks","uint16",198,2,SX_NONE),
 SX_FIELD("pan_9_value","uint16",200,2,SX_NONE),
 SX_FIELD("pan_10_delta_ticks","uint16",202,2,SX_NONE),
 SX_FIELD("pan_10_value","uint16",204,2,SX_NONE),
 SX_FIELD("pan_11_delta_ticks","uint16",206,2,SX_NONE),
 SX_FIELD("pan_11_value","uint16",208,2,SX_NONE),
 SX_FIELD("reserved","bytes",210,46,SX_RESERVED),
};
static const sx_layout sxmr_mxm_instrument={UINT32_C(0x607D001F),"mxm_instrument",sxmr_mxm_instrument_fields,SX_COUNT(sxmr_mxm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_mxm_sample_fields[]={
 SX_FIELD("gus_start","uint24",0,3,SX_ADDRESS),
 SX_FIELD("gus_loop_start","uint24",3,3,SX_ADDRESS),
 SX_FIELD("gus_loop_end","uint24",6,3,SX_ADDRESS),
 SX_FIELD("mode","uint8",9,1,SX_FLAGS),
 SX_FIELD("volume","uint8",10,1,SX_NONE),
 SX_FIELD("pan","uint8",11,1,SX_NONE),
 SX_FIELD("relative_pitch","int16",12,2,SX_NONE),
 SX_FIELD("reserved","bytes",14,2,SX_RESERVED),
};
static const sx_layout sxmr_mxm_sample={UINT32_C(0x607D0020),"mxm_sample",sxmr_mxm_sample_fields,SX_COUNT(sxmr_mxm_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_mxm_pattern_fields[]={
 SX_FIELD("rows","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmr_mxm_pattern={UINT32_C(0x607D0021),"mxm_pattern",sxmr_mxm_pattern_fields,SX_COUNT(sxmr_mxm_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_mxm_event_flags_fields[]={
 SX_FIELD("channel_flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxmr_mxm_event_flags={UINT32_C(0x607D0022),"mxm_event_flags",sxmr_mxm_event_flags_fields,SX_COUNT(sxmr_mxm_event_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_mxm_note_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
};
static const sx_layout sxmr_mxm_note={UINT32_C(0x607D0023),"mxm_note",sxmr_mxm_note_fields,SX_COUNT(sxmr_mxm_note_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_mxm_volume_fields[]={
 SX_FIELD("volume_effect","uint8",0,1,SX_NONE),
};
static const sx_layout sxmr_mxm_volume={UINT32_C(0x607D0024),"mxm_volume",sxmr_mxm_volume_fields,SX_COUNT(sxmr_mxm_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_mxm_effect_fields[]={
 SX_FIELD("effect","uint8",0,1,SX_ID),
 SX_FIELD("parameter","uint8",1,1,SX_NONE),
};
static const sx_layout sxmr_mxm_effect={UINT32_C(0x607D0025),"mxm_effect",sxmr_mxm_effect_fields,SX_COUNT(sxmr_mxm_effect_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_fpt_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("name","char[32]",4,32,SX_NONE),
 SX_FIELD("text_marker","bytes",36,3,SX_SIGNATURE),
 SX_FIELD("pattern_bytes","uint16",39,2,SX_SIZE),
 SX_FIELD("break_row","uint8",41,1,SX_NONE),
 SX_FIELD("unused","uint8",42,1,SX_RESERVED),
};
static const sx_layout sxmr_fpt_header={UINT32_C(0x607D0026),"fpt_header",sxmr_fpt_header_fields,SX_COUNT(sxmr_fpt_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_far_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("volume_nibbles","uint8",2,1,SX_NONE),
 SX_FIELD("effect_parameter","uint8",3,1,SX_FLAGS),
};
static const sx_layout sxmr_far_event={UINT32_C(0x607D0027),"far_event",sxmr_far_event_fields,SX_COUNT(sxmr_far_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_fsm_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("name","char[32]",4,32,SX_NONE),
 SX_FIELD("text_marker","bytes",36,3,SX_SIGNATURE),
 SX_FIELD("sample_bytes","uint32",39,4,SX_SIZE),
 SX_FIELD("finetune","uint8",43,1,SX_NONE),
 SX_FIELD("volume","uint8",44,1,SX_NONE),
 SX_FIELD("loop_start","uint32",45,4,SX_OFFSET),
 SX_FIELD("loop_end","uint32",49,4,SX_OFFSET),
 SX_FIELD("sample_type","uint8",53,1,SX_FLAGS),
 SX_FIELD("loop_mode","uint8",54,1,SX_FLAGS),
};
static const sx_layout sxmr_fsm_header={UINT32_C(0x607D0028),"fsm_header",sxmr_fsm_header_fields,SX_COUNT(sxmr_fsm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_psg_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_NONE),
 SX_FIELD("interrupts_per_second","uint8",5,1,SX_NONE),
 SX_FIELD("unknown_header_bytes","bytes",6,10,SX_NONE),
};
static const sx_layout sxmr_psg_header={UINT32_C(0x607D0029),"psg_header",sxmr_psg_header_fields,SX_COUNT(sxmr_psg_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_psg_legacy_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
};
static const sx_layout sxmr_psg_legacy_header={UINT32_C(0x607D002A),"psg_legacy_header",sxmr_psg_legacy_header_fields,SX_COUNT(sxmr_psg_legacy_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_psg_control_fields[]={
 SX_FIELD("command","uint8",0,1,SX_ID),
};
static const sx_layout sxmr_psg_control={UINT32_C(0x607D002B),"psg_control",sxmr_psg_control_fields,SX_COUNT(sxmr_psg_control_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_psg_skip_fields[]={
 SX_FIELD("command","uint8",0,1,SX_ID),
 SX_FIELD("frame_groups","uint8",1,1,SX_COUNT_PROP),
};
static const sx_layout sxmr_psg_skip={UINT32_C(0x607D002C),"psg_skip",sxmr_psg_skip_fields,SX_COUNT(sxmr_psg_skip_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_psg_write_fields[]={
 SX_FIELD("register","uint8",0,1,SX_ID),
 SX_FIELD("value","uint8",1,1,SX_NONE),
};
static const sx_layout sxmr_psg_write={UINT32_C(0x607D002D),"psg_write",sxmr_psg_write_fields,SX_COUNT(sxmr_psg_write_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_epsg_header_fields[]={
 SX_FIELD("magic","bytes",0,5,SX_SIGNATURE),
 SX_FIELD("machine","uint8",5,1,SX_ID),
 SX_FIELD("tacts_per_interrupt","uint32",6,4,SX_NONE),
 SX_FIELD("reserved","bytes",10,6,SX_RESERVED),
};
static const sx_layout sxmr_epsg_header={UINT32_C(0x607D002E),"epsg_header",sxmr_epsg_header_fields,SX_COUNT(sxmr_epsg_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_epsg_write_fields[]={
 SX_FIELD("register","uint8",0,1,SX_ID),
 SX_FIELD("value","uint8",1,1,SX_NONE),
 SX_FIELD("tact","uint24",2,3,SX_NONE),
};
static const sx_layout sxmr_epsg_write={UINT32_C(0x607D002F),"epsg_write",sxmr_epsg_write_fields,SX_COUNT(sxmr_epsg_write_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_epsg_frame_fields[]={
 SX_FIELD("marker","bytes",0,5,SX_SIGNATURE),
};
static const sx_layout sxmr_epsg_frame={UINT32_C(0x607D0030),"epsg_frame",sxmr_epsg_frame_fields,SX_COUNT(sxmr_epsg_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_gbr_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("rom_banks","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("first_bank_0000","uint8",5,1,SX_ID),
 SX_FIELD("first_bank_4000","uint8",6,1,SX_ID),
 SX_FIELD("interrupt_flags","uint8",7,1,SX_FLAGS),
 SX_FIELD("init_address","uint16",8,2,SX_ADDRESS),
 SX_FIELD("vsync_address","uint16",10,2,SX_ADDRESS),
 SX_FIELD("timer_address","uint16",12,2,SX_ADDRESS),
 SX_FIELD("timer_modulo","uint8",14,1,SX_NONE),
 SX_FIELD("timer_control","uint8",15,1,SX_FLAGS),
 SX_FIELD("reserved","bytes",16,16,SX_RESERVED),
};
static const sx_layout sxmr_gbr_header={UINT32_C(0x607D0031),"gbr_header",sxmr_gbr_header_fields,SX_COUNT(sxmr_gbr_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_wsr_footer_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("first_song","uint8",5,1,SX_ID),
 SX_FIELD("reserved","bytes",6,10,SX_RESERVED),
 SX_FIELD("startup_opcode","uint8",16,1,SX_ID),
 SX_FIELD("startup_offset","uint16",17,2,SX_ADDRESS),
 SX_FIELD("startup_segment","uint16",19,2,SX_ADDRESS),
 SX_FIELD("maintenance_flags","uint8",21,1,SX_FLAGS),
 SX_FIELD("developer","uint8",22,1,SX_ID),
 SX_FIELD("minimum_system","uint8",23,1,SX_ID),
 SX_FIELD("cartridge_id","uint8",24,1,SX_ID),
 SX_FIELD("revision_flags","uint8",25,1,SX_FLAGS),
 SX_FIELD("rom_size_code","uint8",26,1,SX_ID),
 SX_FIELD("save_size_code","uint8",27,1,SX_ID),
 SX_FIELD("bus_orientation_flags","uint8",28,1,SX_FLAGS),
 SX_FIELD("mapper_flags","uint8",29,1,SX_FLAGS),
 SX_FIELD("rom_checksum","uint16",30,2,SX_CHECKSUM),
};
static const sx_layout sxmr_wsr_footer={UINT32_C(0x607D0032),"wsr_footer",sxmr_wsr_footer_fields,SX_COUNT(sxmr_wsr_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_vtx_header_fields[]={
 SX_FIELD("chip","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("stereo","uint8",2,1,SX_ID),
 SX_FIELD("loop_frame","uint16",3,2,SX_NONE),
 SX_FIELD("clock_hz","uint32",5,4,SX_NONE),
 SX_FIELD("player_hz","uint8",9,1,SX_NONE),
 SX_FIELD("year","uint16",10,2,SX_NONE),
 SX_FIELD("unpacked_bytes","uint32",12,4,SX_SIZE),
};
static const sx_layout sxmr_vtx_header={UINT32_C(0x607D0033),"vtx_header",sxmr_vtx_header_fields,SX_COUNT(sxmr_vtx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_vtx_legacy_header_fields[]={
 SX_FIELD("chip","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("stereo","uint8",2,1,SX_ID),
 SX_FIELD("loop_frame","uint16",3,2,SX_NONE),
 SX_FIELD("clock_hz","uint32",5,4,SX_NONE),
 SX_FIELD("player_hz","uint8",9,1,SX_NONE),
 SX_FIELD("unpacked_bytes","uint32",10,4,SX_SIZE),
};
static const sx_layout sxmr_vtx_legacy_header={UINT32_C(0x607D0034),"vtx_legacy_header",sxmr_vtx_legacy_header_fields,SX_COUNT(sxmr_vtx_legacy_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_kdm_header_fields[]={
 SX_FIELD("version","int32",0,4,SX_ID),
 SX_FIELD("notes","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("tracks","int32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxmr_kdm_header={UINT32_C(0x607D0035),"kdm_header",sxmr_kdm_header_fields,SX_COUNT(sxmr_kdm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_kdm_instrument_fields[]={
 SX_FIELD("wave_index","uint8",0,1,SX_ID),
};
static const sx_layout sxmr_kdm_instrument={UINT32_C(0x607D0036),"kdm_instrument",sxmr_kdm_instrument_fields,SX_COUNT(sxmr_kdm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_kdm_quantization_fields[]={
 SX_FIELD("quantization","uint8",0,1,SX_NONE),
};
static const sx_layout sxmr_kdm_quantization={UINT32_C(0x607D0037),"kdm_quantization",sxmr_kdm_quantization_fields,SX_COUNT(sxmr_kdm_quantization_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_kdm_volume_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
};
static const sx_layout sxmr_kdm_volume={UINT32_C(0x607D0038),"kdm_volume",sxmr_kdm_volume_fields,SX_COUNT(sxmr_kdm_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_kdm_time_fields[]={
 SX_FIELD("tick","int32",0,4,SX_NONE),
};
static const sx_layout sxmr_kdm_time={UINT32_C(0x607D0039),"kdm_time",sxmr_kdm_time_fields,SX_COUNT(sxmr_kdm_time_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_kdm_track_fields[]={
 SX_FIELD("track","uint8",0,1,SX_ID),
};
static const sx_layout sxmr_kdm_track={UINT32_C(0x607D003A),"kdm_track",sxmr_kdm_track_fields,SX_COUNT(sxmr_kdm_track_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_kdm_pitch_fields[]={
 SX_FIELD("pitch","uint8",0,1,SX_NONE),
};
static const sx_layout sxmr_kdm_pitch={UINT32_C(0x607D003B),"kdm_pitch",sxmr_kdm_pitch_fields,SX_COUNT(sxmr_kdm_pitch_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_kdm_effect_fields[]={
 SX_FIELD("effect","uint8",0,1,SX_ID),
};
static const sx_layout sxmr_kdm_effect={UINT32_C(0x607D003C),"kdm_effect",sxmr_kdm_effect_fields,SX_COUNT(sxmr_kdm_effect_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_spu_metadata_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("game","char[64]",4,64,SX_NONE),
 SX_FIELD("title","char[64]",68,64,SX_NONE),
 SX_FIELD("artist","char[32]",132,32,SX_NONE),
 SX_FIELD("comment","char[3840]",164,3840,SX_NONE),
};
static const sx_layout sxmr_spu_metadata={UINT32_C(0x607D003D),"spu_metadata",sxmr_spu_metadata_fields,SX_COUNT(sxmr_spu_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_spu_register_fields[]={
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
static const sx_layout sxmr_spu_register={UINT32_C(0x607D003E),"spu_register",sxmr_spu_register_fields,SX_COUNT(sxmr_spu_register_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_spu_old_timing_fields[]={
 SX_FIELD("sample_rate","uint32",0,4,SX_NONE),
 SX_FIELD("events","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxmr_spu_old_timing={UINT32_C(0x607D003F),"spu_old_timing",sxmr_spu_old_timing_fields,SX_COUNT(sxmr_spu_old_timing_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_spu_new_timing_fields[]={
 SX_FIELD("end_tick","uint32",0,4,SX_NONE),
 SX_FIELD("first_tick","uint32",4,4,SX_NONE),
};
static const sx_layout sxmr_spu_new_timing={UINT32_C(0x607D0040),"spu_new_timing",sxmr_spu_new_timing_fields,SX_COUNT(sxmr_spu_new_timing_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_spu_old_event_fields[]={
 SX_FIELD("tick","uint32",0,4,SX_NONE),
 SX_FIELD("register_address","uint32",4,4,SX_ADDRESS),
 SX_FIELD("value","uint16",8,2,SX_NONE),
 SX_FIELD("unused","bytes",10,2,SX_NONE),
};
static const sx_layout sxmr_spu_old_event={UINT32_C(0x607D0041),"spu_old_event",sxmr_spu_old_event_fields,SX_COUNT(sxmr_spu_old_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_spu_write_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("register_address","uint32",1,4,SX_ADDRESS),
 SX_FIELD("value","uint16",5,2,SX_NONE),
 SX_FIELD("next_tick","uint32",7,4,SX_NONE),
};
static const sx_layout sxmr_spu_write={UINT32_C(0x607D0042),"spu_write",sxmr_spu_write_fields,SX_COUNT(sxmr_spu_write_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_spu_read_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("register_address","uint32",1,4,SX_ADDRESS),
 SX_FIELD("next_tick","uint32",5,4,SX_NONE),
};
static const sx_layout sxmr_spu_read={UINT32_C(0x607D0043),"spu_read",sxmr_spu_read_fields,SX_COUNT(sxmr_spu_read_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_spu_transfer_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("payload_bytes","uint32",1,4,SX_SIZE),
};
static const sx_layout sxmr_spu_transfer={UINT32_C(0x607D0044),"spu_transfer",sxmr_spu_transfer_fields,SX_COUNT(sxmr_spu_transfer_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_spu_dma_read_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("transfer_bytes","uint32",1,4,SX_SIZE),
 SX_FIELD("next_tick","uint32",5,4,SX_NONE),
};
static const sx_layout sxmr_spu_dma_read={UINT32_C(0x607D0045),"spu_dma_read",sxmr_spu_dma_read_fields,SX_COUNT(sxmr_spu_dma_read_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_spu_xa_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("xa_metadata","bytes",1,32,SX_NONE),
};
static const sx_layout sxmr_spu_xa={UINT32_C(0x607D0046),"spu_xa",sxmr_spu_xa_fields,SX_COUNT(sxmr_spu_xa_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_spu_tick_fields[]={
 SX_FIELD("next_tick","uint32",0,4,SX_NONE),
};
static const sx_layout sxmr_spu_tick={UINT32_C(0x607D0047),"spu_tick",sxmr_spu_tick_fields,SX_COUNT(sxmr_spu_tick_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_pt36_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("form_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","bytes",8,4,SX_ID),
};
static const sx_layout sxmr_pt36_header={UINT32_C(0x607D0048),"pt36_header",sxmr_pt36_header_fields,SX_COUNT(sxmr_pt36_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_pt36_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("chunk_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmr_pt36_chunk={UINT32_C(0x607D0049),"pt36_chunk",sxmr_pt36_chunk_fields,SX_COUNT(sxmr_pt36_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_pt36_info_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_NONE),
 SX_FIELD("samples","uint16",32,2,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",34,2,SX_COUNT_PROP),
 SX_FIELD("patterns","uint16",36,2,SX_COUNT_PROP),
 SX_FIELD("volume","uint16",38,2,SX_NONE),
 SX_FIELD("tempo","uint16",40,2,SX_NONE),
 SX_FIELD("flags","uint16",42,2,SX_FLAGS),
 SX_FIELD("day","uint16",44,2,SX_NONE),
 SX_FIELD("month","uint16",46,2,SX_NONE),
 SX_FIELD("year","uint16",48,2,SX_NONE),
 SX_FIELD("hour","uint16",50,2,SX_NONE),
 SX_FIELD("minute","uint16",52,2,SX_NONE),
 SX_FIELD("second","uint16",54,2,SX_NONE),
 SX_FIELD("play_hours","uint16",56,2,SX_NONE),
 SX_FIELD("play_minutes","uint16",58,2,SX_NONE),
 SX_FIELD("play_seconds","uint16",60,2,SX_NONE),
 SX_FIELD("play_milliseconds","uint16",62,2,SX_NONE),
};
static const sx_layout sxmr_pt36_info={UINT32_C(0x607D004A),"pt36_info",sxmr_pt36_info_fields,SX_COUNT(sxmr_pt36_info_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_sndh_header_fields[]={
 SX_FIELD("init_instruction","bytes",0,4,SX_NONE),
 SX_FIELD("exit_instruction","bytes",4,4,SX_NONE),
 SX_FIELD("play_instruction","bytes",8,4,SX_NONE),
 SX_FIELD("magic","bytes",12,4,SX_SIGNATURE),
};
static const sx_layout sxmr_sndh_header={UINT32_C(0x607D004B),"sndh_header",sxmr_sndh_header_fields,SX_COUNT(sxmr_sndh_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_sndh_tag_fields[]={
 SX_FIELD("tag","bytes",0,4,SX_ID),
};
static const sx_layout sxmr_sndh_tag={UINT32_C(0x607D004C),"sndh_tag",sxmr_sndh_tag_fields,SX_COUNT(sxmr_sndh_tag_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_sndh_tunes_fields[]={
 SX_FIELD("tag","bytes",0,2,SX_ID),
 SX_FIELD("tunes","ascii_decimal[2]",2,2,SX_COUNT_PROP),
};
static const sx_layout sxmr_sndh_tunes={UINT32_C(0x607D004D),"sndh_tunes",sxmr_sndh_tunes_fields,SX_COUNT(sxmr_sndh_tunes_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_sndh_default_fields[]={
 SX_FIELD("tag","bytes",0,2,SX_ID),
 SX_FIELD("default_tune","ascii_decimal[2]",2,2,SX_NONE),
};
static const sx_layout sxmr_sndh_default={UINT32_C(0x607D004E),"sndh_default",sxmr_sndh_default_fields,SX_COUNT(sxmr_sndh_default_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_sndh_timer_fields[]={
 SX_FIELD("timer","bytes",0,2,SX_ID),
};
static const sx_layout sxmr_sndh_timer={UINT32_C(0x607D004F),"sndh_timer",sxmr_sndh_timer_fields,SX_COUNT(sxmr_sndh_timer_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_sndh_name_offset_fields[]={
 SX_FIELD("name_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxmr_sndh_name_offset={UINT32_C(0x607D0050),"sndh_name_offset",sxmr_sndh_name_offset_fields,SX_COUNT(sxmr_sndh_name_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_sndh_frames_fields[]={
 SX_FIELD("frames","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmr_sndh_frames={UINT32_C(0x607D0051),"sndh_frames",sxmr_sndh_frames_fields,SX_COUNT(sxmr_sndh_frames_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_sndh_seconds_fields[]={
 SX_FIELD("seconds","uint16",0,2,SX_NONE),
};
static const sx_layout sxmr_sndh_seconds={UINT32_C(0x607D0052),"sndh_seconds",sxmr_sndh_seconds_fields,SX_COUNT(sxmr_sndh_seconds_fields),SX_BE};
static const xx_data_struct_field_desc sxmr_psg2_magic_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
};
static const sx_layout sxmr_psg2_magic={UINT32_C(0x607D0053),"psg2_magic",sxmr_psg2_magic_fields,SX_COUNT(sxmr_psg2_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_psg2_map_fields[]={
 SX_FIELD("register_bitmap","bytes",0,2,SX_FLAGS),
};
static const sx_layout sxmr_psg2_map={UINT32_C(0x607D0054),"psg2_map",sxmr_psg2_map_fields,SX_COUNT(sxmr_psg2_map_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_psg2_reuse_fields[]={
 SX_FIELD("interrupts","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxmr_psg2_reuse={UINT32_C(0x607D0055),"psg2_reuse",sxmr_psg2_reuse_fields,SX_COUNT(sxmr_psg2_reuse_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_psg2_value_fields[]={
 SX_FIELD("register_value","uint8",0,1,SX_NONE),
};
static const sx_layout sxmr_psg2_value={UINT32_C(0x607D0056),"psg2_value",sxmr_psg2_value_fields,SX_COUNT(sxmr_psg2_value_fields),SX_LE};
static const sx_layout *const sx_musicremaining_layouts[]={
 &sxmr_ams2_magic,
 &sxmr_ams2_header,
 &sxmr_ams2_timing20,
 &sxmr_ams2_timing22,
 &sxmr_pascal_text_length,
 &sxmr_text,
 &sxmr_nul,
 &sxmr_ams2_sample_count,
 &sxmr_ams2_note_sample,
 &sxmr_ams2_envelope,
 &sxmr_ams2_envelope_point,
 &sxmr_ams2_instrument,
 &sxmr_ams2_sample,
 &sxmr_ams2_description,
 &sxmr_order16,
 &sxmr_ams2_pattern,
 &sxmr_cba_header,
 &sxmr_pan_position,
 &sxmr_order8,
 &sxmr_cba_sample,
 &sxmr_cba_event,
 &sxmr_plm_header,
 &sxmr_plm_order,
 &sxmr_pattern_offset,
 &sxmr_sample_offset,
 &sxmr_instrument_offset,
 &sxmr_plm_sample,
 &sxmr_plm_pattern,
 &sxmr_plm_event,
 &sxmr_mxm_header,
 &sxmr_mxm_instrument,
 &sxmr_mxm_sample,
 &sxmr_mxm_pattern,
 &sxmr_mxm_event_flags,
 &sxmr_mxm_note,
 &sxmr_mxm_volume,
 &sxmr_mxm_effect,
 &sxmr_fpt_header,
 &sxmr_far_event,
 &sxmr_fsm_header,
 &sxmr_psg_header,
 &sxmr_psg_legacy_header,
 &sxmr_psg_control,
 &sxmr_psg_skip,
 &sxmr_psg_write,
 &sxmr_epsg_header,
 &sxmr_epsg_write,
 &sxmr_epsg_frame,
 &sxmr_gbr_header,
 &sxmr_wsr_footer,
 &sxmr_vtx_header,
 &sxmr_vtx_legacy_header,
 &sxmr_kdm_header,
 &sxmr_kdm_instrument,
 &sxmr_kdm_quantization,
 &sxmr_kdm_volume,
 &sxmr_kdm_time,
 &sxmr_kdm_track,
 &sxmr_kdm_pitch,
 &sxmr_kdm_effect,
 &sxmr_spu_metadata,
 &sxmr_spu_register,
 &sxmr_spu_old_timing,
 &sxmr_spu_new_timing,
 &sxmr_spu_old_event,
 &sxmr_spu_write,
 &sxmr_spu_read,
 &sxmr_spu_transfer,
 &sxmr_spu_dma_read,
 &sxmr_spu_xa,
 &sxmr_spu_tick,
 &sxmr_pt36_header,
 &sxmr_pt36_chunk,
 &sxmr_pt36_info,
 &sxmr_sndh_header,
 &sxmr_sndh_tag,
 &sxmr_sndh_tunes,
 &sxmr_sndh_default,
 &sxmr_sndh_timer,
 &sxmr_sndh_name_offset,
 &sxmr_sndh_frames,
 &sxmr_sndh_seconds,
 &sxmr_psg2_magic,
 &sxmr_psg2_map,
 &sxmr_psg2_reuse,
 &sxmr_psg2_value,
};
/* Stream metadata directly: a large ROM/disc payload never becomes a scratch buffer. */
typedef struct sxmr_view {sx_context*c;unsigned work;}sxmr_view;
static bool sxmr_span(sxmr_view*v,uint64_t at,uint64_t n,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&v->c->size>=0&&end<=(uint64_t)v->c->size&&at<=end&&n<=end-at;}
static bool sxmr_read(sxmr_view*v,uint64_t at,void*p,size_t n,uint64_t end)
{return ++v->work<=4000000&&sxmr_span(v,at,n,end)&&sx_read(v->c,(int64_t)at,p,n);}
static bool sxmr_word(sxmr_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!n||n>8||!sxmr_read(v,at,b,n,end))return false;uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[be?n-i-1:i]<<(8*i);*out=x;return true;}
static bool sxmr_row(sxmr_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxmr_span(v,at,z,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)z);}
#define MR_ROW(l,at,end) sxmr_row(v,&sxmr_##l,(at),(end))
static bool sxmr_table(sxmr_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>4000000||count>UINT64_MAX/z||!sxmr_span(v,at,count*z,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++,at+=z)if(!sxmr_row(v,l,at,end))return false;return true;}
static int sxmr_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxmr_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxmr_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxmr_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxmr_cstring(sxmr_view*v,uint64_t*p,uint64_t end,uint64_t max)
{uint64_t start=*p,c;while(*p<end&&*p-start<max){if(++v->work>4000000||!sxmr_word(v,*p,1,false,&c,end))return false;(*p)++;if(!c)return true;}return false;}

static bool sxmr_u(sxmr_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxmr_word(v,p,n,false,x,end);}
static bool sxmr_be(sxmr_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxmr_word(v,p,n,true,x,end);}
static bool sxmr_eq(sxmr_view*v,uint64_t p,const char*s,size_t n,uint64_t end){uint8_t b[64];return n<=sizeof(b)&&sxmr_read(v,p,b,n,end)&&!xx_rt_memcmp(b,s,n);}
static bool sxmr_text_emit(sxmr_view*v,uint64_t p,uint64_t n,uint64_t end){if(!sxmr_span(v,p,n,end))return false;return !n||n>4096||v->c->count>=24000||sx_add(v->c,&sxmr_text,(int64_t)p,(int64_t)n);}
static bool sxmr_string(sxmr_view*v,uint64_t*p,uint64_t end){uint64_t at=*p;if(!sxmr_cstring(v,p,end,1048576))return false;return sxmr_text_emit(v,at,*p-at-1,end)&&MR_ROW(nul,*p-1,end);}
static bool sxmr_pascal(sxmr_view*v,uint64_t*p,uint64_t end){uint64_t n;if(!sxmr_u(v,*p,1,&n,end)||!MR_ROW(pascal_text_length,*p,end))return false;(*p)++;if(!sxmr_text_emit(v,*p,n,end))return false;*p+=n;return true;}
static bool sxmr_ams(sxmr_view*v)
{uint64_t end=v->c->size,p=8,n,minor,major,ins,pats,ords,x,samples;
 if(!sxmr_eq(v,0,"AMShdr\x1a",7,end)||!sxmr_u(v,7,1,&n,end)||n>30||!MR_ROW(ams2_magic,0,end)||!sxmr_text_emit(v,p,n,end))return false;p+=n;
 if(!sxmr_u(v,p,1,&minor,end)||!sxmr_u(v,p+1,1,&major,end)||major!=2||minor>2||!sxmr_u(v,p+2,1,&ins,end)||!sxmr_u(v,p+3,2,&pats,end)||!sxmr_u(v,p+5,2,&ords,end)||!MR_ROW(ams2_header,p,end))return false;p+=7;
 if(minor==2){if(!MR_ROW(ams2_timing22,p,end))return false;p+=8;}else{if(!MR_ROW(ams2_timing20,p,end))return false;p+=3;}
 for(uint64_t i=0;i<ins;i++){if(!sxmr_pascal(v,&p,end)||!sxmr_u(v,p,1,&samples,end)||!MR_ROW(ams2_sample_count,p,end))return false;p++;if(!samples)continue;
  n=minor?120:96;if(!sxmr_table(v,&sxmr_ams2_note_sample,p,n,end))return false;p+=n;
  for(unsigned j=0;j<3;j++){if(!sxmr_u(v,p+4,1,&n,end)||!MR_ROW(ams2_envelope,p,end))return false;p+=5;if(!sxmr_table(v,&sxmr_ams2_envelope_point,p,n,end))return false;p+=n*3;}
  if(!MR_ROW(ams2_instrument,p,end))return false;p+=5;
  for(uint64_t j=0;j<samples;j++){if(!sxmr_pascal(v,&p,end)||!MR_ROW(ams2_sample,p,end))return false;p+=20;}
 }
 for(unsigned j=0;j<33;j++)if(!sxmr_pascal(v,&p,end))return false;
 if(!sxmr_u(v,p,4,&n,end)||n<11||!sxmr_span(v,p,n,end)||!MR_ROW(ams2_description,p,end))return false;p+=n;
 if(!sxmr_table(v,&sxmr_order16,p,ords,end))return false;p+=2*ords;
 for(uint64_t i=0;i<pats;i++){if(!sxmr_u(v,p,4,&n,end)||n<3||!sxmr_span(v,p+4,n,end)||!MR_ROW(ams2_pattern,p,end))return false;x=p+4+n;p+=6;if(!sxmr_pascal(v,&p,x))return false;p=x;}
 /* Packed and shadow sample bodies are deliberately left raw. */
 return true;}
static bool sxmr_cba(sxmr_view*v)
{uint64_t end=v->c->size,msg,ch,last,ns,x,p=332,total=0;
 if(!sxmr_eq(v,0,"CBA\xf9",4,end)||!sxmr_u(v,36,1,&x,end)||x!=26||!sxmr_u(v,37,2,&msg,end)||!sxmr_u(v,39,1,&ch,end)||!ch||ch>32||!sxmr_u(v,40,1,&last,end)||!sxmr_u(v,42,1,&ns,end)||!MR_ROW(cba_header,0,end)||!sxmr_table(v,&sxmr_pan_position,45,32,end)||!sxmr_table(v,&sxmr_order8,77,255,end))return false;
 for(uint64_t i=0;i<ns;i++,p+=48){if(!sxmr_u(v,p+36,4,&x,end)||!MR_ROW(cba_sample,p,end)||x>UINT64_MAX-total)return false;total+=x;}
 x=(last+1)*64*ch;if(!sxmr_table(v,&sxmr_cba_event,p,x,end))return false;p+=x*5;
 if(!sxmr_span(v,p,total,end))return false;p+=total;return sxmr_text_emit(v,p,msg,end);}
static bool sxmr_plm(sxmr_view*v)
{uint64_t end=v->c->size,hs,ch,ns,np,no,p,pt,st,at,n,x,y;
 if(!sxmr_eq(v,0,"PLM\x1a",4,end)||!sxmr_u(v,4,1,&hs,end)||hs<96||!sxmr_u(v,5,1,&x,end)||x!=16||!sxmr_u(v,54,1,&ch,end)||!ch||ch>32||!sxmr_u(v,92,1,&ns,end)||!sxmr_u(v,93,1,&np,end)||!sxmr_u(v,94,2,&no,end)||!MR_ROW(plm_header,0,end))return false;
 p=hs;if(!sxmr_table(v,&sxmr_plm_order,p,no,end))return false;p+=no*4;pt=p;if(!sxmr_table(v,&sxmr_pattern_offset,p,np,end))return false;p+=np*4;st=p;if(!sxmr_table(v,&sxmr_sample_offset,p,ns,end))return false;
 for(uint64_t i=0;i<np;i++){if(!sxmr_u(v,pt+i*4,4,&at,end))return false;if(!at)continue;if(!sxmr_u(v,at,4,&n,end)||n<32||!sxmr_span(v,at,n,end)||!sxmr_u(v,at+4,1,&x,end)||!sxmr_u(v,at+5,1,&y,end)||y>32||!MR_ROW(plm_pattern,at,end)||!sxmr_table(v,&sxmr_plm_event,at+32,x*y,at+n))return false;}
 for(uint64_t i=0;i<ns;i++){if(!sxmr_u(v,st+i*4,4,&at,end))return false;if(!at)continue;if(!sxmr_eq(v,at,"PLS\x1a",4,end)||!sxmr_u(v,at+4,1,&hs,end)||hs<71||!sxmr_u(v,at+67,4,&n,end)||!sxmr_span(v,at,hs,end)||!sxmr_span(v,at+hs,n,end)||!MR_ROW(plm_sample,at,end))return false;}
 return true;}
static bool sxmr_mxm(sxmr_view*v)
{uint64_t end=v->c->size,np,ni,ch,orders,restart,p,at,n,rows,flags,sm,b8,b16;
 if(!sxmr_eq(v,0,"MXM\0",4,end)||!sxmr_u(v,4,4,&orders,end)||!orders||orders>256||!sxmr_u(v,8,4,&restart,end)||restart>=orders||!sxmr_u(v,12,4,&ch,end)||!ch||ch>32||!sxmr_u(v,16,4,&np,end)||!np||np>256||!sxmr_u(v,20,4,&ni,end)||ni>128||!sxmr_u(v,28,4,&sm,end)||!sxmr_u(v,32,4,&b8,end)||!sxmr_u(v,36,4,&b16,end)||!MR_ROW(mxm_header,0,end))return false;
 if(!sxmr_table(v,&sxmr_order8,80,256,end)||!sxmr_table(v,&sxmr_instrument_offset,336,128,end)||!sxmr_table(v,&sxmr_pattern_offset,848,256,end)||!sxmr_span(v,sm,b8+2*b16,end))return false;
 for(uint64_t i=0;i<ni;i++){if(!sxmr_u(v,336+i*4,4,&at,end)||!at||!sxmr_u(v,at,4,&n,end)||n>256||!MR_ROW(mxm_instrument,at,end)||!sxmr_table(v,&sxmr_mxm_sample,at+256,n,end))return false;}
 for(uint64_t i=0;i<np;i++){if(!sxmr_u(v,848+i*4,4,&at,end)||!at||!sxmr_u(v,at,4,&rows,end)||!rows||rows>65535||!MR_ROW(mxm_pattern,at,end))return false;p=at+4;
  for(uint64_t r=0;r<rows;r++){for(;;){if(!sxmr_u(v,p,1,&flags,end)||!MR_ROW(mxm_event_flags,p,end))return false;p++;if(!flags)break;if(!(flags&224)||(flags&31)>=ch)return false;
    if(flags&32){if(!MR_ROW(mxm_note,p,end))return false;p+=2;}if(flags&64){if(!MR_ROW(mxm_volume,p,end))return false;p++;}if(flags&128){if(!MR_ROW(mxm_effect,p,end))return false;p+=2;}
  }}
 }
 return true;}
static bool sxmr_far(sxmr_view*v,bool sample)
{uint64_t end=v->c->size,n;if(sample){if(!sxmr_eq(v,0,"FSM\xfe",4,end)||!sxmr_eq(v,36,"\x0a\x0d\x1a",3,end)||!sxmr_u(v,39,4,&n,end)||!MR_ROW(fsm_header,0,end))return false;return sxmr_span(v,55,n,end);}
 /* Existing detector uses CR LF SUB; the author's document says LF CR SUB. Retain the native-compatible variant. */
 if(!sxmr_eq(v,0,"FPT\xfe",4,end)||(!sxmr_eq(v,36,"\x0d\x0a\x1a",3,end)&&!sxmr_eq(v,36,"\x0a\x0d\x1a",3,end))||!sxmr_u(v,39,2,&n,end)||n<2||(n-2)%64||!sxmr_span(v,41,n,end)||!MR_ROW(fpt_header,0,end))return false;return sxmr_table(v,&sxmr_far_event,43,(n-2)/4,41+n);}
static bool sxmr_psg(sxmr_view*v,bool extended)
{uint64_t end=v->c->size,p=16,x;if(extended){if(!sxmr_eq(v,0,"EPSG\x1a",5,end)||!MR_ROW(epsg_header,0,end))return false;while(p<end){if(!sxmr_span(v,p,5,end))return false;if(sxmr_eq(v,p,"\xff\xff\xff\xff\xff",5,end)){if(!MR_ROW(epsg_frame,p,end))return false;}else{if(!sxmr_u(v,p,1,&x,end)||x>15||!MR_ROW(epsg_write,p,end))return false;}p+=5;}return true;}
 if(!sxmr_eq(v,0,"PSG\x1a",4,end)||!sxmr_u(v,4,1,&x,end))return false;if(x==255){p=4;if(!MR_ROW(psg_legacy_header,0,end))return false;}else if(!MR_ROW(psg_header,0,end))return false;
 while(p<end){if(!sxmr_u(v,p,1,&x,end))return false;if(x==255||x==253){if(!MR_ROW(psg_control,p,end))return false;p++;if(x==253)return true;}else if(x==254){if(!MR_ROW(psg_skip,p,end))return false;p+=2;}else if(x<=15){if(!MR_ROW(psg_write,p,end))return false;p+=2;}else return false;}
 return true;}
static bool sxmr_gbr(sxmr_view*v)
{uint64_t n,end=v->c->size;if(!sxmr_eq(v,0,"GBRF",4,end)||!sxmr_u(v,4,1,&n,end)||!n||!MR_ROW(gbr_header,0,end))return false;return sxmr_span(v,32,n*16384,end);}
static bool sxmr_wsr(sxmr_view*v)
{uint64_t end=v->c->size;if(end<32||!sxmr_eq(v,end-32,"WSRF",4,end)||!sxmr_eq(v,end-16,"\xea",1,end))return false;return MR_ROW(wsr_footer,end-32,end);}
static bool sxmr_vtx(sxmr_view*v)
{uint64_t end=v->c->size,p,mode,x,clock;bool old=sxmr_eq(v,0,"AY",2,end)||sxmr_eq(v,0,"YM",2,end);
 if(!old&&!sxmr_eq(v,0,"ay",2,end)&&!sxmr_eq(v,0,"ym",2,end))return false;
 if(!sxmr_u(v,2,1,&mode,end)||mode>6||!sxmr_u(v,5,4,&clock,end)||clock<800000||clock>4000000)return false;
 if(old){p=14;if(!MR_ROW(vtx_legacy_header,0,end))return false;}else{p=16;if(!MR_ROW(vtx_header,0,end))return false;}
 if(!sxmr_u(v,p-4,4,&x,end)||x<2||x>0xa00000)return false;
 for(unsigned i=0;i<(old?2:5);i++)if(!sxmr_string(v,&p,end))return false;return p<end;}
static bool sxmr_kdm(sxmr_view*v)
{uint64_t end=v->c->size,n,t,x,p=12;const sx_layout*tr[4]={&sxmr_kdm_instrument,&sxmr_kdm_quantization,&sxmr_kdm_volume,&sxmr_kdm_volume};const sx_layout*nt[7]={&sxmr_kdm_track,&sxmr_kdm_pitch,&sxmr_kdm_volume,&sxmr_kdm_volume,&sxmr_kdm_effect,&sxmr_kdm_effect,&sxmr_kdm_effect};
 if(!sxmr_u(v,0,4,&x,end)||x||!sxmr_u(v,4,4,&n,end)||!n||n>8192||!sxmr_u(v,8,4,&t,end)||!t||t>256||!MR_ROW(kdm_header,0,end)||(end!=12+4*t+11*n&&end!=12+4*t+10*n))return false;
 for(unsigned i=0;i<4;i++){if(!sxmr_table(v,tr[i],p,t,end))return false;p+=t;}
 if(!sxmr_table(v,&sxmr_kdm_time,p,n,end))return false;p+=4*n;
 for(unsigned i=0;i<7&&p<end;i++){if(!sxmr_table(v,nt[i],p,n,end))return false;p+=n;}return true;}
static bool sxmr_spu(sxmr_view*v)
{uint64_t end=v->c->size,n,x,p=0x80208,ticks;if(!sxmr_eq(v,0,"SPU",3,end)||!sxmr_u(v,3,1,&x,end)||(x!=0&&x!='1')||!MR_ROW(spu_metadata,0,end)||!sxmr_table(v,&sxmr_spu_register,0x80000,256,end)||!sxmr_u(v,0x80200,4,&ticks,end)||!sxmr_u(v,0x80204,4,&n,end))return false;
 if(ticks==44100&&n<=(end-p)/12){return MR_ROW(spu_old_timing,0x80200,end)&&sxmr_table(v,&sxmr_spu_old_event,p,n,end);}
 if(!MR_ROW(spu_new_timing,0x80200,end))return false;
 while(p<end&&n<ticks){if(!sxmr_u(v,p,1,&x,end))return false;
  if(x==0){if(!MR_ROW(spu_write,p,end)||!sxmr_u(v,p+7,4,&n,end))return false;p+=11;}
  else if(x==1){if(!MR_ROW(spu_read,p,end)||!sxmr_u(v,p+5,4,&n,end))return false;p+=9;}
  else if(x==2||x==5){if(!sxmr_u(v,p+1,4,&x,end)||!MR_ROW(spu_transfer,p,end))return false;p+=5;if(!sxmr_span(v,p,x,end))return false;p+=x;if(!MR_ROW(spu_tick,p,end)||!sxmr_u(v,p,4,&n,end))return false;p+=4;}
  else if(x==3){if(!MR_ROW(spu_dma_read,p,end)||!sxmr_u(v,p+5,4,&n,end))return false;p+=9;}
  else if(x==4){if(!MR_ROW(spu_xa,p,end)||!sxmr_span(v,p+33,16384,end))return false;p+=33+16384;if(!MR_ROW(spu_tick,p,end)||!sxmr_u(v,p,4,&n,end))return false;p+=4;}
  else return false;
 }
 return n>=ticks;}
static bool sxmr_pt36(sxmr_view*v)
{uint64_t end=v->c->size,p=12,n,first=4;uint8_t id[4];if(!sxmr_eq(v,0,"FORM",4,end)||!sxmr_eq(v,8,"MODL",4,end)||!MR_ROW(pt36_header,0,end))return false;
 while(p<end){if(!sxmr_read(v,p,id,4,end)||!sxmr_be(v,p+4,4,&n,end)||n<8+first||!MR_ROW(pt36_chunk,p,end))return false;n-=8+first;first=0;p+=8;if(!sxmr_span(v,p,n,end))return false;
  if(!xx_rt_memcmp(id,"INFO",4)&&n>=64){if(!MR_ROW(pt36_info,p,end))return false;}
  else if(!xx_rt_memcmp(id,"VERS",4)&&n>4){if(!sxmr_text_emit(v,p+4,n-4,end))return false;}
  else if(!xx_rt_memcmp(id,"CMNT",4)){if(!sxmr_text_emit(v,p,n,end))return false;}
  p+=n;
 }
 return true;}
static bool sxmr_sndh(sxmr_view*v)
{uint64_t end=v->c->size,p=16,n=1,x,base,last,q;uint8_t b[4];if(!sxmr_eq(v,12,"SNDH",4,end)||!MR_ROW(sndh_header,0,end))return false;
 while(p<end){if(!sxmr_read(v,p,b,4,end))return false;
  if(!xx_rt_memcmp(b,"HDNS",4))return MR_ROW(sndh_tag,p,end);
  if(!b[0]){p++;continue;}
  if(!xx_rt_memcmp(b,"##",2)||(!xx_rt_memcmp(b,"#!",2)&&xx_rt_memcmp(b,"#!SN",4))){if(b[2]<'0'||b[2]>'9'||b[3]<'0'||b[3]>'9')return false;x=(b[2]-'0')*10+b[3]-'0';if(b[1]=='#'){if(!x||!MR_ROW(sndh_tunes,p,end))return false;n=x;}else if(!MR_ROW(sndh_default,p,end))return false;p+=4;continue;}
  if(!xx_rt_memcmp(b,"TITL",4)||!xx_rt_memcmp(b,"COMM",4)||!xx_rt_memcmp(b,"RIPP",4)||!xx_rt_memcmp(b,"CONV",4)||!xx_rt_memcmp(b,"YEAR",4)||!xx_rt_memcmp(b,"FLAG",4)){if(!MR_ROW(sndh_tag,p,end))return false;p+=4;if(!sxmr_string(v,&p,end))return false;continue;}
  if((b[0]=='T'&&b[1]>='A'&&b[1]<='D')||(b[0]=='!'&&b[1]=='V')){if(!MR_ROW(sndh_timer,p,end))return false;p+=2;if(!sxmr_string(v,&p,end))return false;continue;}
  if(!xx_rt_memcmp(b,"TIME",4)||!xx_rt_memcmp(b,"FRMS",4)){if(!MR_ROW(sndh_tag,p,end))return false;p+=4;x=b[0]=='T'?2:4;if(!sxmr_table(v,x==2?&sxmr_sndh_seconds:&sxmr_sndh_frames,p,n,end))return false;p+=n*x;continue;}
  if(!xx_rt_memcmp(b,"#!SN",4)){if(!MR_ROW(sndh_tag,p,end))return false;p+=4;base=p;last=p+2*n;if(!sxmr_table(v,&sxmr_sndh_name_offset,p,n,end))return false;
   for(uint64_t i=0;i<n;i++){if(!sxmr_be(v,base+2*i,2,&x,end)||x<2*n||!sxmr_span(v,base,x,end))return false;q=base+x;if(!sxmr_string(v,&q,end))return false;if(q>last)last=q;}p=last;continue;}
  /* Unrecognized extension tags have no length grammar; preserve them and later code verbatim. */
  return true;
 }
 return false;}

static bool sxmr_psg2(sxmr_view*v)
{uint64_t end=v->c->size,p=4,n;uint8_t b[2];if(!sxmr_eq(v,0,"PSG2",4,end)||!MR_ROW(psg2_magic,0,end))return false;
 while(p<end){if(!sxmr_read(v,p,b,2,end)||!MR_ROW(psg2_map,p,end))return false;p+=2;if(b[0]==255&&b[1]==255)return true;
  if(!sxmr_u(v,p,1,&n,end)||!MR_ROW(psg2_reuse,p,end))return false;p++;if(!n)return true;unsigned bits=0;for(unsigned j=0;j<2;j++)for(unsigned k=0;k<8;k++)bits+=(b[j]>>k)&1U;
  if(!sxmr_table(v,&sxmr_psg2_value,p,n*bits,end))return false;p+=n*bits;
 }return true;}

static bool sx_musicremaining_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_DIE_MUSIC_VELVETSTUDIO_AMS:
case XX_FILE_TYPE_DIE_MUSIC_CHUCKBISCUITS_CBA:
case XX_FILE_TYPE_DIE_MUSIC_STATIX_DISORDERTRACKER2_PLM:
case XX_FILE_TYPE_DIE_MUSIC_BEISERT_MXMPLAY:
case XX_FILE_TYPE_DIE_MUSIC_POTTER_FARANDOLE_FPT:
case XX_FILE_TYPE_DIE_MUSIC_POTTER_FARANDOLE_FSM:
case XX_FILE_TYPE_DIE_MUSIC_KOLPAKOV_FMSXX128_PSG:
case XX_FILE_TYPE_DIE_MUSIC_KOLPAKOV_EXTENDED_PSG:
case XX_FILE_TYPE_DIE_MUSIC_KOLPAKOV_PSG2:
case XX_FILE_TYPE_DIE_MUSIC_GAMEBOY_RIPPEDFORMAT:
case XX_FILE_TYPE_DIE_MUSIC_WONDERSWANR_WSRF:
case XX_FILE_TYPE_DIE_MUSIC_VSOFT_VORTEXPROJECT:
case XX_FILE_TYPE_DIE_MUSIC_SILVERMAN_DIGITALMUSIC_KDM:
case XX_FILE_TYPE_DIE_MUSIC_PSXALT_ETERNALSPUPLUGIN:
case XX_FILE_TYPE_DIE_MUSIC_PROTRACKER_IFF_PTM:
case XX_FILE_TYPE_DIE_MUSIC_ATARIST_SOUNDHEADER:
return true;default:return false;}}
static bool sx_musicremaining_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxmr_view view={c,0},*v=&view;bool ok=false;
 switch(c->f->file_type){
case XX_FILE_TYPE_DIE_MUSIC_VELVETSTUDIO_AMS:ok=sxmr_ams(v);break;
case XX_FILE_TYPE_DIE_MUSIC_CHUCKBISCUITS_CBA:ok=sxmr_cba(v);break;
case XX_FILE_TYPE_DIE_MUSIC_STATIX_DISORDERTRACKER2_PLM:ok=sxmr_plm(v);break;
case XX_FILE_TYPE_DIE_MUSIC_BEISERT_MXMPLAY:ok=sxmr_mxm(v);break;
case XX_FILE_TYPE_DIE_MUSIC_POTTER_FARANDOLE_FPT:ok=sxmr_far(v,false);break;
case XX_FILE_TYPE_DIE_MUSIC_POTTER_FARANDOLE_FSM:ok=sxmr_far(v,true);break;
case XX_FILE_TYPE_DIE_MUSIC_KOLPAKOV_FMSXX128_PSG:ok=sxmr_psg(v,false);break;
case XX_FILE_TYPE_DIE_MUSIC_KOLPAKOV_EXTENDED_PSG:ok=sxmr_psg(v,true);break;
case XX_FILE_TYPE_DIE_MUSIC_KOLPAKOV_PSG2:ok=sxmr_psg2(v);break;
case XX_FILE_TYPE_DIE_MUSIC_GAMEBOY_RIPPEDFORMAT:ok=sxmr_gbr(v);break;
case XX_FILE_TYPE_DIE_MUSIC_WONDERSWANR_WSRF:ok=sxmr_wsr(v);break;
case XX_FILE_TYPE_DIE_MUSIC_VSOFT_VORTEXPROJECT:ok=sxmr_vtx(v);break;
case XX_FILE_TYPE_DIE_MUSIC_SILVERMAN_DIGITALMUSIC_KDM:ok=sxmr_kdm(v);break;
case XX_FILE_TYPE_DIE_MUSIC_PSXALT_ETERNALSPUPLUGIN:ok=sxmr_spu(v);break;
case XX_FILE_TYPE_DIE_MUSIC_PROTRACKER_IFF_PTM:ok=sxmr_pt36(v);break;
case XX_FILE_TYPE_DIE_MUSIC_ATARIST_SOUNDHEADER:ok=sxmr_sndh(v);break;
default:break;}
 return ok&&sxmr_finish(c);}
#undef MR_ROW
static bool sx_musicremaining_comment(xx_data_struct_record*r,uint32_t id)
{if(!r||!r->name||id<UINT32_C(0x607d0001)||id>=UINT32_C(0x607e0000))return true;
 const wchar_t*msg=NULL;
 if(id==sxmr_ams2_sample.id){if(!xx_rt_wcscmp(r->name,L"sample_frames")||(!xx_rt_wcscmp(r->name,L"loop_start_frame")||!xx_rt_wcscmp(r->name,L"loop_end_frame")))msg=L"Sample-frame units; each frame is one byte or two bytes according to flags bit 2";else if(!xx_rt_wcscmp(r->name,L"flags"))msg=L"bits 0..1 packed; bit 2 16-bit; bit 3 loop; bit 4 bidirectional; bit 6 reverse";else if(!xx_rt_wcscmp(r->name,L"volume"))msg=L"Volume on a 0..127 scale";else if(!xx_rt_wcscmp(r->name,L"relative_tone"))msg=L"Signed semitone transposition";}
 if(id==sxmr_ams2_envelope_point.id&& !xx_rt_wcscmp(r->name,L"delta_flags"))msg=L"Bit 0 is the ninth time-delta bit; remaining bits are retained";
 if(id==sxmr_ams2_timing22.id&&!xx_rt_wcscmp(r->name,L"tempo_8_8"))msg=L"Unsigned 8.8 fixed-point beats per minute";
 if(id==sxmr_ams2_description.id&&!xx_rt_wcscmp(r->name,L"packed_bytes"))msg=L"Stored block byte count includes this 11-byte header";
 if(id==sxmr_cba_header.id&&!xx_rt_wcscmp(r->name,L"last_pattern"))msg=L"Zero-based last pattern index; physical pattern count is this value plus one";
 if((id==sxmr_cba_sample.id||id==sxmr_plm_sample.id||id==sxmr_fsm_header.id)&&(r->property&SX_OFFSET))msg=L"Byte offset relative to this sample's data; not a file offset";
 if(id==sxmr_cba_sample.id&&!xx_rt_wcscmp(r->name,L"flags"))msg=L"Bit 3 enables sample looping; sample payload is 8-bit delta PCM";
 if(id==sxmr_plm_sample.id&&!xx_rt_wcscmp(r->name,L"flags"))msg=L"Bit 0: 16-bit samples; bit 1: ping-pong loop; lengths and loop offsets remain bytes";
 if(id==sxmr_mxm_instrument.id&&(!xx_rt_wcscmp(r->name,L"volume_last_point")||!xx_rt_wcscmp(r->name,L"pan_last_point")))msg=L"Last envelope point index (point count minus one); zero represents a single stored point";
 if(id==sxmr_mxm_instrument.id){size_t len=xx_rt_wcslen(r->name);if(len>=12&&!xx_rt_wcscmp(r->name+len-12,L"_delta_ticks"))msg=L"Delta ticks from this envelope point to the next; final point stores zero";}
 if(id==sxmr_mxm_sample.id&&(r->property&SX_ADDRESS))msg=L"Encoded 24-bit Gravis UltraSound sample-memory address; 16-bit samples use the GUS bank/word transformation, not a file offset";
 if(id==sxmr_mxm_sample.id&&!xx_rt_wcscmp(r->name,L"relative_pitch"))msg=L"Signed pitch in 1/256-semitone units";
 if(id==sxmr_mxm_header.id&&!xx_rt_wcscmp(r->name,L"options"))msg=L"bit 0 linear pitch; bit 1 forced panning; bit 2 delta-coded sample data";
 if(id==sxmr_mxm_event_flags.id)msg=L"Zero ends a row; low five bits channel; 0x20 note/instrument, 0x40 volume, 0x80 effect/parameter follow";
 if(id==sxmr_far_event.id&&!xx_rt_wcscmp(r->name,L"volume_nibbles"))msg=L"Historical swapped volume nibbles; low nibble is the coarse volume adjustment";
 if(id==sxmr_far_event.id&&!xx_rt_wcscmp(r->name,L"effect_parameter"))msg=L"High nibble effect, low nibble parameter";
 if(id==sxmr_psg_header.id&&!xx_rt_wcscmp(r->name,L"interrupts_per_second"))msg=L"Player frequency in Hz for version 10 and later; earlier versions leave this byte unspecified";
 if(id==sxmr_psg_header.id&&!xx_rt_wcscmp(r->name,L"unknown_header_bytes"))msg=L"Ten physical header bytes; the recovered format description leaves their meaning unspecified";
 if(id==sxmr_psg_skip.id&&!xx_rt_wcscmp(r->name,L"frame_groups"))msg=L"Number of groups of four interrupt frames";
 if(id==sxmr_psg_control.id)msg=L"0xFF begins an interrupt frame; 0xFD ends music";
 if(id==sxmr_epsg_write.id&&!xx_rt_wcscmp(r->name,L"tact"))msg=L"CPU tact within the current interrupt interval; not a wall-clock timestamp";
 if(id==sxmr_epsg_header.id&&!xx_rt_wcscmp(r->name,L"machine"))msg=L"0 ZX Spectrum 128K; 1 Pentagon; 255 custom timing";
 if(id==sxmr_gbr_header.id&&!xx_rt_wcscmp(r->name,L"rom_banks"))msg=L"Count of 16-KiB ROM banks after the 32-byte header";
 if(id==sxmr_gbr_header.id&&(r->property&SX_ADDRESS))msg=L"Game Boy CPU address";
 if(id==sxmr_wsr_footer.id&&!xx_rt_wcscmp(r->name,L"rom_checksum"))msg=L"Stored ROM checksum; not format magic";
 if((id==sxmr_vtx_header.id||id==sxmr_vtx_legacy_header.id)&&!xx_rt_wcscmp(r->name,L"loop_frame"))msg=L"Zero-based interrupt-frame loop index; not a byte offset";
 if((id==sxmr_vtx_header.id||id==sxmr_vtx_legacy_header.id)&&!xx_rt_wcscmp(r->name,L"stereo"))msg=L"0 mono, 1 ABC, 2 ACB, 3 BAC, 4 BCA, 5 CAB, 6 CBA";
 if(id==sxmr_vtx_header.id&&!xx_rt_wcscmp(r->name,L"year"))msg=L"Composition calendar year; zero if unknown";
 if(id==sxmr_kdm_time.id)msg=L"Music tick counter, 120 ticks per second; not a wall-clock timestamp";
 if(id==sxmr_spu_old_event.id||id==sxmr_spu_write.id||id==sxmr_spu_read.id){if(r->property&SX_ADDRESS)msg=L"PlayStation SPU register address";}
 if((id==sxmr_spu_old_timing.id||id==sxmr_spu_new_timing.id||id==sxmr_spu_tick.id||id==sxmr_spu_old_event.id||id==sxmr_spu_write.id||id==sxmr_spu_read.id||id==sxmr_spu_dma_read.id)&&(!xx_rt_wcscmp(r->name,L"tick")||!xx_rt_wcscmp(r->name,L"first_tick")||!xx_rt_wcscmp(r->name,L"end_tick")||!xx_rt_wcscmp(r->name,L"next_tick")))msg=L"SPU tick counter at 44100 Hz; not a wall-clock timestamp";
 if(id==sxmr_pt36_chunk.id&&!xx_rt_wcscmp(r->name,L"chunk_bytes"))msg=L"Includes this 8-byte chunk header; the first chunk additionally includes the 4-byte MODL tag";
 if(id==sxmr_sndh_name_offset.id)msg=L"Byte offset relative to the start of the word-offset table immediately after #!SN";
 if(id==sxmr_sndh_frames.id)msg=L"Subtune duration in interrupt frames; zero means indefinite looping";
 if(id==sxmr_sndh_seconds.id)msg=L"Legacy subtune duration in seconds; not a timestamp";
 if(id==sxmr_psg2_map.id)msg=L"Raw two-byte register-change bitmap; 0xFFFF ends music. Values for set registers follow in register order; byte order is preserved without reinterpretation";
 if(id==sxmr_psg2_reuse.id)msg=L"Number of interrupts using the preceding change bitmap; zero-count variants remain raw after this field";
 if(!msg&&(r->property&SX_OFFSET))msg=L"Byte offset relative to the start of this file";
 if(!msg&&(r->property&SX_ADDRESS))msg=L"Stored target-machine address component; not a file offset";
 return !msg||xx_data_struct_record_set_comment(r,msg);}
