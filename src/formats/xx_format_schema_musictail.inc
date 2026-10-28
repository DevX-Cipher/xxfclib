/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical music header and table metadata; compressed and unknown bodies stay raw. */
static const xx_data_struct_field_desc sxmta_text_fields[]={
 SX_FIELD("text","char",0,0,SX_NONE),
};
static const sx_layout sxmta_text={UINT32_C(0x60810001),"text",sxmta_text_fields,SX_COUNT(sxmta_text_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_pascal_text_length_fields[]={
 SX_FIELD("text_bytes","uint8",0,1,SX_SIZE),
};
static const sx_layout sxmta_pascal_text_length={UINT32_C(0x60810002),"pascal_text_length",sxmta_pascal_text_length_fields,SX_COUNT(sxmta_pascal_text_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_text_length16_fields[]={
 SX_FIELD("text_bytes","uint16",0,2,SX_SIZE),
};
static const sx_layout sxmta_text_length16={UINT32_C(0x60810003),"text_length16",sxmta_text_length16_fields,SX_COUNT(sxmta_text_length16_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_order8_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
};
static const sx_layout sxmta_order8={UINT32_C(0x60810004),"order8",sxmta_order8_fields,SX_COUNT(sxmta_order8_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_order16be_fields[]={
 SX_FIELD("pattern","uint16",0,2,SX_ID),
};
static const sx_layout sxmta_order16be={UINT32_C(0x60810005),"order16be",sxmta_order16be_fields,SX_COUNT(sxmta_order16be_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_order16le_fields[]={
 SX_FIELD("pattern","uint16",0,2,SX_ID),
};
static const sx_layout sxmta_order16le={UINT32_C(0x60810006),"order16le",sxmta_order16le_fields,SX_COUNT(sxmta_order16le_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_count16be_fields[]={
 SX_FIELD("count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmta_count16be={UINT32_C(0x60810007),"count16be",sxmta_count16be_fields,SX_COUNT(sxmta_count16be_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_volume8_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
};
static const sx_layout sxmta_volume8={UINT32_C(0x60810008),"volume8",sxmta_volume8_fields,SX_COUNT(sxmta_volume8_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_pan16be_fields[]={
 SX_FIELD("pan","uint16",0,2,SX_NONE),
};
static const sx_layout sxmta_pan16be={UINT32_C(0x60810009),"pan16be",sxmta_pan16be_fields,SX_COUNT(sxmta_pan16be_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_chunk_le_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmta_chunk_le={UINT32_C(0x6081000A),"chunk_le",sxmta_chunk_le_fields,SX_COUNT(sxmta_chunk_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_riff_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("form_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","bytes",8,4,SX_ID),
};
static const sx_layout sxmta_riff_header={UINT32_C(0x6081000B),"riff_header",sxmta_riff_header_fields,SX_COUNT(sxmta_riff_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_gtk_header_fields[]={
 SX_FIELD("magic","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("title","char[32]",4,32,SX_NONE),
 SX_FIELD("comment","char[160]",36,160,SX_NONE),
 SX_FIELD("samples","uint16",196,2,SX_COUNT_PROP),
 SX_FIELD("rows","uint16",198,2,SX_COUNT_PROP),
 SX_FIELD("channels","uint16",200,2,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",202,2,SX_COUNT_PROP),
 SX_FIELD("restart_order","uint16",204,2,SX_NONE),
};
static const sx_layout sxmta_gtk_header={UINT32_C(0x6081000C),"gtk_header",sxmta_gtk_header_fields,SX_COUNT(sxmta_gtk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gtk_sample1_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_NONE),
 SX_FIELD("sample_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("loop_start","uint32",36,4,SX_OFFSET),
 SX_FIELD("loop_bytes","uint32",40,4,SX_SIZE),
 SX_FIELD("volume","uint16",44,2,SX_NONE),
 SX_FIELD("finetune","int16",46,2,SX_NONE),
};
static const sx_layout sxmta_gtk_sample1={UINT32_C(0x6081000D),"gtk_sample1",sxmta_gtk_sample1_fields,SX_COUNT(sxmta_gtk_sample1_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gtk_sample2_fields[]={
 SX_FIELD("name","char[28]",0,28,SX_NONE),
 SX_FIELD("bytes_per_sample","uint16",28,2,SX_NONE),
 SX_FIELD("sample_rate","uint16",30,2,SX_NONE),
 SX_FIELD("sample_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("loop_start","uint32",36,4,SX_OFFSET),
 SX_FIELD("loop_bytes","uint32",40,4,SX_SIZE),
 SX_FIELD("volume","uint16",44,2,SX_NONE),
 SX_FIELD("finetune","int16",46,2,SX_NONE),
};
static const sx_layout sxmta_gtk_sample2={UINT32_C(0x6081000E),"gtk_sample2",sxmta_gtk_sample2_fields,SX_COUNT(sxmta_gtk_sample2_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gtk_sample3_fields[]={
 SX_FIELD("name","char[28]",0,28,SX_NONE),
 SX_FIELD("reserved","bytes",28,14,SX_RESERVED),
 SX_FIELD("default_pan","int16",42,2,SX_NONE),
 SX_FIELD("bytes_per_sample","uint16",44,2,SX_NONE),
 SX_FIELD("sample_rate","uint16",46,2,SX_NONE),
 SX_FIELD("sample_bytes","uint32",48,4,SX_SIZE),
 SX_FIELD("loop_start","uint32",52,4,SX_OFFSET),
 SX_FIELD("loop_bytes","uint32",56,4,SX_SIZE),
 SX_FIELD("volume","uint16",60,2,SX_NONE),
 SX_FIELD("finetune","int16",62,2,SX_NONE),
};
static const sx_layout sxmta_gtk_sample3={UINT32_C(0x6081000F),"gtk_sample3",sxmta_gtk_sample3_fields,SX_COUNT(sxmta_gtk_sample3_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gtk_event4_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxmta_gtk_event4={UINT32_C(0x60810010),"gtk_event4",sxmta_gtk_event4_fields,SX_COUNT(sxmta_gtk_event4_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_gtk_event5_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
 SX_FIELD("volume","uint8",4,1,SX_NONE),
};
static const sx_layout sxmta_gtk_event5={UINT32_C(0x60810011),"gtk_event5",sxmta_gtk_event5_fields,SX_COUNT(sxmta_gtk_event5_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_gt2_header_new_fields[]={
 SX_FIELD("magic","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("header_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("title","char[32]",8,32,SX_NONE),
 SX_FIELD("comment","char[160]",40,160,SX_NONE),
 SX_FIELD("day","uint8",200,1,SX_NONE),
 SX_FIELD("month","uint8",201,1,SX_NONE),
 SX_FIELD("year","uint16",202,2,SX_NONE),
 SX_FIELD("tracker","char[24]",204,24,SX_NONE),
};
static const sx_layout sxmta_gt2_header_new={UINT32_C(0x60810012),"gt2_header_new",sxmta_gt2_header_new_fields,SX_COUNT(sxmta_gt2_header_new_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_header_old_fields[]={
 SX_FIELD("magic","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("header_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("title","char[32]",8,32,SX_NONE),
 SX_FIELD("comment","char[160]",40,160,SX_NONE),
 SX_FIELD("day","uint8",200,1,SX_NONE),
 SX_FIELD("month","uint8",201,1,SX_NONE),
 SX_FIELD("year","uint16",202,2,SX_NONE),
 SX_FIELD("tracker","char[24]",204,24,SX_NONE),
 SX_FIELD("speed","uint16",228,2,SX_NONE),
 SX_FIELD("tempo","uint16",230,2,SX_NONE),
 SX_FIELD("master_volume","uint16",232,2,SX_NONE),
 SX_FIELD("panned_tracks","uint16",234,2,SX_COUNT_PROP),
};
static const sx_layout sxmta_gt2_header_old={UINT32_C(0x60810013),"gt2_header_old",sxmta_gt2_header_old_fields,SX_COUNT(sxmta_gt2_header_old_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("chunk_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmta_gt2_chunk={UINT32_C(0x60810014),"gt2_chunk",sxmta_gt2_chunk_fields,SX_COUNT(sxmta_gt2_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_song_fields[]={
 SX_FIELD("orders","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("restart_order","uint16",2,2,SX_NONE),
};
static const sx_layout sxmta_gt2_song={UINT32_C(0x60810015),"gt2_song",sxmta_gt2_song_fields,SX_COUNT(sxmta_gt2_song_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_pattern_fields[]={
 SX_FIELD("pattern","uint16",0,2,SX_ID),
 SX_FIELD("name","char[16]",2,16,SX_NONE),
 SX_FIELD("coding","uint16",18,2,SX_ID),
 SX_FIELD("rows","uint16",20,2,SX_COUNT_PROP),
 SX_FIELD("tracks","uint16",22,2,SX_COUNT_PROP),
};
static const sx_layout sxmta_gt2_pattern={UINT32_C(0x60810016),"gt2_pattern",sxmta_gt2_pattern_fields,SX_COUNT(sxmta_gt2_pattern_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_track_name_fields[]={
 SX_FIELD("track_type","uint16",0,2,SX_ID),
 SX_FIELD("track_index","uint16",2,2,SX_ID),
 SX_FIELD("name","char[32]",4,32,SX_NONE),
};
static const sx_layout sxmta_gt2_track_name={UINT32_C(0x60810017),"gt2_track_name",sxmta_gt2_track_name_fields,SX_COUNT(sxmta_gt2_track_name_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_timing_fields[]={
 SX_FIELD("version","uint16",0,2,SX_ID),
 SX_FIELD("tempo_integer","uint16",2,2,SX_NONE),
 SX_FIELD("tempo_fraction","uint16",4,2,SX_NONE),
 SX_FIELD("speed","uint16",6,2,SX_NONE),
 SX_FIELD("time_signature_numerator","uint16",8,2,SX_NONE),
 SX_FIELD("time_signature_denominator","uint16",10,2,SX_NONE),
};
static const sx_layout sxmta_gt2_timing={UINT32_C(0x60810018),"gt2_timing",sxmta_gt2_timing_fields,SX_COUNT(sxmta_gt2_timing_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_period_mode_fields[]={
 SX_FIELD("period_mode","uint16",0,2,SX_ID),
};
static const sx_layout sxmta_gt2_period_mode={UINT32_C(0x60810019),"gt2_period_mode",sxmta_gt2_period_mode_fields,SX_COUNT(sxmta_gt2_period_mode_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_sample1_fields[]={
 SX_FIELD("sample","uint16",0,2,SX_ID),
 SX_FIELD("name","char[28]",2,28,SX_NONE),
 SX_FIELD("flags","uint16",30,2,SX_FLAGS),
 SX_FIELD("default_pan","int16",32,2,SX_NONE),
 SX_FIELD("bits_per_sample","uint16",34,2,SX_NONE),
 SX_FIELD("sample_rate","uint16",36,2,SX_NONE),
 SX_FIELD("sample_bytes","uint32",38,4,SX_SIZE),
 SX_FIELD("loop_start","uint32",42,4,SX_OFFSET),
 SX_FIELD("loop_bytes","uint32",46,4,SX_SIZE),
 SX_FIELD("volume","int16",50,2,SX_NONE),
 SX_FIELD("finetune","int16",52,2,SX_NONE),
 SX_FIELD("sample_coding","uint16",54,2,SX_ID),
};
static const sx_layout sxmta_gt2_sample1={UINT32_C(0x6081001A),"gt2_sample1",sxmta_gt2_sample1_fields,SX_COUNT(sxmta_gt2_sample1_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_sample2_fields[]={
 SX_FIELD("sample","uint16",0,2,SX_ID),
 SX_FIELD("name","char[28]",2,28,SX_NONE),
 SX_FIELD("sample_type","uint16",30,2,SX_ID),
 SX_FIELD("bits_per_sample","uint16",32,2,SX_NONE),
 SX_FIELD("sample_endian","uint16",34,2,SX_ID),
 SX_FIELD("channels","uint16",36,2,SX_COUNT_PROP),
 SX_FIELD("default_pan","int16",38,2,SX_NONE),
 SX_FIELD("volume","uint16",40,2,SX_NONE),
 SX_FIELD("finetune","int16",42,2,SX_NONE),
 SX_FIELD("loop_type","uint16",44,2,SX_ID),
 SX_FIELD("midi_note","int16",46,2,SX_NONE),
 SX_FIELD("sample_coding","uint16",48,2,SX_ID),
 SX_FIELD("filename_bytes","uint16",50,2,SX_SIZE),
 SX_FIELD("y_panning","int16",52,2,SX_NONE),
 SX_FIELD("sample_rate","uint32",54,4,SX_NONE),
 SX_FIELD("sample_frames","uint32",58,4,SX_COUNT_PROP),
 SX_FIELD("loop_start_frame","uint32",62,4,SX_NONE),
 SX_FIELD("loop_frames","uint32",66,4,SX_COUNT_PROP),
 SX_FIELD("loop_buffer_frames","uint32",70,4,SX_COUNT_PROP),
 SX_FIELD("data_offset","uint32",74,4,SX_OFFSET),
};
static const sx_layout sxmta_gt2_sample2={UINT32_C(0x6081001B),"gt2_sample2",sxmta_gt2_sample2_fields,SX_COUNT(sxmta_gt2_sample2_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_instrument_fields[]={
 SX_FIELD("instrument","uint16",0,2,SX_ID),
 SX_FIELD("name","char[28]",2,28,SX_NONE),
 SX_FIELD("instrument_type","uint16",30,2,SX_ID),
 SX_FIELD("default_velocity","uint16",32,2,SX_NONE),
 SX_FIELD("default_pan","int16",34,2,SX_NONE),
 SX_FIELD("volume_envelope","uint16",36,2,SX_ID),
 SX_FIELD("tone_envelope","uint16",38,2,SX_ID),
 SX_FIELD("pan_envelope","uint16",40,2,SX_ID),
 SX_FIELD("cutoff_envelope","uint16",42,2,SX_ID),
 SX_FIELD("resonance_envelope","uint16",44,2,SX_ID),
 SX_FIELD("reserved","bytes",46,4,SX_RESERVED),
 SX_FIELD("version","uint16",50,2,SX_ID),
};
static const sx_layout sxmta_gt2_instrument={UINT32_C(0x6081001C),"gt2_instrument",sxmta_gt2_instrument_fields,SX_COUNT(sxmta_gt2_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_note_map_fields[]={
 SX_FIELD("sample","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
static const sx_layout sxmta_gt2_note_map={UINT32_C(0x6081001D),"gt2_note_map",sxmta_gt2_note_map_fields,SX_COUNT(sxmta_gt2_note_map_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_tcb_header_fields[]={
 SX_FIELD("magic","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("patterns","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("tempo","uint8",12,1,SX_NONE),
 SX_FIELD("unused","uint8",13,1,SX_RESERVED),
 SX_FIELD("orders","bytes",14,128,SX_NONE),
 SX_FIELD("order_count","uint8",142,1,SX_COUNT_PROP),
 SX_FIELD("unused2","uint8",143,1,SX_RESERVED),
};
static const sx_layout sxmta_tcb_header={UINT32_C(0x6081001E),"tcb_header",sxmta_tcb_header_fields,SX_COUNT(sxmta_tcb_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_tcb_amiga_flag_fields[]={
 SX_FIELD("amiga_frequencies","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxmta_tcb_amiga_flag={UINT32_C(0x6081001F),"tcb_amiga_flag",sxmta_tcb_amiga_flag_fields,SX_COUNT(sxmta_tcb_amiga_flag_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_tcb_instrument_name_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_NONE),
};
static const sx_layout sxmta_tcb_instrument_name={UINT32_C(0x60810020),"tcb_instrument_name",sxmta_tcb_instrument_name_fields,SX_COUNT(sxmta_tcb_instrument_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_tcb_special_fields[]={
 SX_FIELD("special_value","int16",0,2,SX_NONE),
};
static const sx_layout sxmta_tcb_special={UINT32_C(0x60810021),"tcb_special",sxmta_tcb_special_fields,SX_COUNT(sxmta_tcb_special_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_tcb_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument_effect","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxmta_tcb_event={UINT32_C(0x60810022),"tcb_event",sxmta_tcb_event_fields,SX_COUNT(sxmta_tcb_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_tcb_sample_area_fields[]={
 SX_FIELD("remaining_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxmta_tcb_sample_area={UINT32_C(0x60810023),"tcb_sample_area",sxmta_tcb_sample_area_fields,SX_COUNT(sxmta_tcb_sample_area_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_tcb_sample_properties_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
 SX_FIELD("unused","uint8",1,1,SX_RESERVED),
 SX_FIELD("loop_tail_bytes","uint16",2,2,SX_SIZE),
};
static const sx_layout sxmta_tcb_sample_properties={UINT32_C(0x60810024),"tcb_sample_properties",sxmta_tcb_sample_properties_fields,SX_COUNT(sxmta_tcb_sample_properties_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_tcb_sample_location_fields[]={
 SX_FIELD("sample_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("sample_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmta_tcb_sample_location={UINT32_C(0x60810025),"tcb_sample_location",sxmta_tcb_sample_location_fields,SX_COUNT(sxmta_tcb_sample_location_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gmc_sample_fields[]={
 SX_FIELD("sample_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("sample_words","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("zero","uint8",6,1,SX_RESERVED),
 SX_FIELD("volume","uint8",7,1,SX_NONE),
 SX_FIELD("sample_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("loop_words","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("trimmed_bytes","uint16",14,2,SX_SIZE),
};
static const sx_layout sxmta_gmc_sample={UINT32_C(0x60810026),"gmc_sample",sxmta_gmc_sample_fields,SX_COUNT(sxmta_gmc_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gmc_orders_fields[]={
 SX_FIELD("zero","bytes",0,3,SX_RESERVED),
 SX_FIELD("orders","uint8",3,1,SX_COUNT_PROP),
};
static const sx_layout sxmta_gmc_orders={UINT32_C(0x60810027),"gmc_orders",sxmta_gmc_orders_fields,SX_COUNT(sxmta_gmc_orders_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gmc_pattern_offset_fields[]={
 SX_FIELD("pattern_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxmta_gmc_pattern_offset={UINT32_C(0x60810028),"gmc_pattern_offset",sxmta_gmc_pattern_offset_fields,SX_COUNT(sxmta_gmc_pattern_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gmc_event_fields[]={
 SX_FIELD("period","uint16",0,2,SX_NONE),
 SX_FIELD("instrument_effect","uint8",2,1,SX_FLAGS),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxmta_gmc_event={UINT32_C(0x60810029),"gmc_event",sxmta_gmc_event_fields,SX_COUNT(sxmta_gmc_event_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_fuchs_event_fields[]={
 SX_FIELD("instrument_period_high","uint8",0,1,SX_FLAGS),
 SX_FIELD("period_low","uint8",1,1,SX_NONE),
 SX_FIELD("instrument_effect","uint8",2,1,SX_FLAGS),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxmta_fuchs_event={UINT32_C(0x6081002A),"fuchs_event",sxmta_fuchs_event_fields,SX_COUNT(sxmta_fuchs_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_kris_title_fields[]={
 SX_FIELD("title","char[22]",0,22,SX_NONE),
};
static const sx_layout sxmta_kris_title={UINT32_C(0x6081002B),"kris_title",sxmta_kris_title_fields,SX_COUNT(sxmta_kris_title_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_kris_sample_fields[]={
 SX_FIELD("name","char[22]",0,22,SX_NONE),
 SX_FIELD("sample_words","uint16",22,2,SX_COUNT_PROP),
 SX_FIELD("finetune","uint8",24,1,SX_NONE),
 SX_FIELD("volume","uint8",25,1,SX_NONE),
 SX_FIELD("loop_start_words","uint16",26,2,SX_NONE),
 SX_FIELD("loop_words","uint16",28,2,SX_COUNT_PROP),
};
static const sx_layout sxmta_kris_sample={UINT32_C(0x6081002C),"kris_sample",sxmta_kris_sample_fields,SX_COUNT(sxmta_kris_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_kris_synth_fields[]={
 SX_FIELD("synth_parameters","bytes",0,30,SX_NONE),
};
static const sx_layout sxmta_kris_synth={UINT32_C(0x6081002D),"kris_synth",sxmta_kris_synth_fields,SX_COUNT(sxmta_kris_synth_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_kris_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("orders","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("restart_order","uint8",5,1,SX_NONE),
};
static const sx_layout sxmta_kris_header={UINT32_C(0x6081002E),"kris_header",sxmta_kris_header_fields,SX_COUNT(sxmta_kris_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_kris_track_ref_fields[]={
 SX_FIELD("track","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
static const sx_layout sxmta_kris_track_ref={UINT32_C(0x6081002F),"kris_track_ref",sxmta_kris_track_ref_fields,SX_COUNT(sxmta_kris_track_ref_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_kris_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxmta_kris_event={UINT32_C(0x60810030),"kris_event",sxmta_kris_event_fields,SX_COUNT(sxmta_kris_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_c67_header_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
 SX_FIELD("restart_order","uint8",1,1,SX_NONE),
};
static const sx_layout sxmta_c67_header={UINT32_C(0x60810031),"c67_header",sxmta_c67_header_fields,SX_COUNT(sxmta_c67_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_c67_name_fields[]={
 SX_FIELD("name","char[13]",0,13,SX_NONE),
};
static const sx_layout sxmta_c67_name={UINT32_C(0x60810032),"c67_name",sxmta_c67_name_fields,SX_COUNT(sxmta_c67_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_c67_sample_fields[]={
 SX_FIELD("unknown_zero","uint32",0,4,SX_NONE),
 SX_FIELD("sample_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("loop_start","uint32",8,4,SX_OFFSET),
 SX_FIELD("loop_end","uint32",12,4,SX_OFFSET),
};
static const sx_layout sxmta_c67_sample={UINT32_C(0x60810033),"c67_sample",sxmta_c67_sample_fields,SX_COUNT(sxmta_c67_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_c67_fm_instrument_fields[]={
 SX_FIELD("feedback_connection","uint8",0,1,SX_FLAGS),
 SX_FIELD("modulator_characteristics","uint8",1,1,SX_FLAGS),
 SX_FIELD("modulator_level","uint8",2,1,SX_FLAGS),
 SX_FIELD("modulator_attack_decay","uint8",3,1,SX_FLAGS),
 SX_FIELD("modulator_sustain_release","uint8",4,1,SX_FLAGS),
 SX_FIELD("modulator_waveform","uint8",5,1,SX_ID),
 SX_FIELD("carrier_characteristics","uint8",6,1,SX_FLAGS),
 SX_FIELD("carrier_level","uint8",7,1,SX_FLAGS),
 SX_FIELD("carrier_attack_decay","uint8",8,1,SX_FLAGS),
 SX_FIELD("carrier_sustain_release","uint8",9,1,SX_FLAGS),
 SX_FIELD("carrier_waveform","uint8",10,1,SX_ID),
};
static const sx_layout sxmta_c67_fm_instrument={UINT32_C(0x60810034),"c67_fm_instrument",sxmta_c67_fm_instrument_fields,SX_COUNT(sxmta_c67_fm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_c67_pattern_offset_fields[]={
 SX_FIELD("pattern_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmta_c67_pattern_offset={UINT32_C(0x60810035),"c67_pattern_offset",sxmta_c67_pattern_offset_fields,SX_COUNT(sxmta_c67_pattern_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_c67_pattern_bytes_fields[]={
 SX_FIELD("pattern_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxmta_c67_pattern_bytes={UINT32_C(0x60810036),"c67_pattern_bytes",sxmta_c67_pattern_bytes_fields,SX_COUNT(sxmta_c67_pattern_bytes_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dsym_header_fields[]={
 SX_FIELD("magic","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("version","uint8",8,1,SX_ID),
 SX_FIELD("channels","uint8",9,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("tracks","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("info_bytes","uint24",14,3,SX_SIZE),
};
static const sx_layout sxmta_dsym_header={UINT32_C(0x60810037),"dsym_header",sxmta_dsym_header_fields,SX_COUNT(sxmta_dsym_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dsym_sample_flags_fields[]={
 SX_FIELD("name_length_flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxmta_dsym_sample_flags={UINT32_C(0x60810038),"dsym_sample_flags",sxmta_dsym_sample_flags_fields,SX_COUNT(sxmta_dsym_sample_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dsym_sample_words_fields[]={
 SX_FIELD("sample_words","uint24",0,3,SX_COUNT_PROP),
};
static const sx_layout sxmta_dsym_sample_words={UINT32_C(0x60810039),"dsym_sample_words",sxmta_dsym_sample_words_fields,SX_COUNT(sxmta_dsym_sample_words_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dsym_commands_fields[]={
 SX_FIELD("allowed_commands","bytes",0,8,SX_FLAGS),
};
static const sx_layout sxmta_dsym_commands={UINT32_C(0x6081003A),"dsym_commands",sxmta_dsym_commands_fields,SX_COUNT(sxmta_dsym_commands_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dsym_packing_fields[]={
 SX_FIELD("packing","uint8",0,1,SX_ID),
};
static const sx_layout sxmta_dsym_packing={UINT32_C(0x6081003B),"dsym_packing",sxmta_dsym_packing_fields,SX_COUNT(sxmta_dsym_packing_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dsym_sample_fields[]={
 SX_FIELD("loop_start_words","uint24",0,3,SX_NONE),
 SX_FIELD("loop_words","uint24",3,3,SX_COUNT_PROP),
 SX_FIELD("volume","uint8",6,1,SX_NONE),
 SX_FIELD("finetune","uint8",7,1,SX_NONE),
};
static const sx_layout sxmta_dsym_sample={UINT32_C(0x6081003C),"dsym_sample",sxmta_dsym_sample_fields,SX_COUNT(sxmta_dsym_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dsym_event_fields[]={
 SX_FIELD("note_instrument_low","uint8",0,1,SX_FLAGS),
 SX_FIELD("instrument_effect_low","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect_parameter_low","uint8",2,1,SX_FLAGS),
 SX_FIELD("parameter_high","uint8",3,1,SX_NONE),
};
static const sx_layout sxmta_dsym_event={UINT32_C(0x6081003D),"dsym_event",sxmta_dsym_event_fields,SX_COUNT(sxmta_dsym_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_sym_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
};
static const sx_layout sxmta_sym_header={UINT32_C(0x6081003E),"sym_header",sxmta_sym_header_fields,SX_COUNT(sxmta_sym_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_sym_value_fields[]={
 SX_FIELD("chunk_id","int32",0,4,SX_ID),
 SX_FIELD("value","uint32",4,4,SX_NONE),
};
static const sx_layout sxmta_sym_value={UINT32_C(0x6081003F),"sym_value",sxmta_sym_value_fields,SX_COUNT(sxmta_sym_value_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_sym_count_fields[]={
 SX_FIELD("chunk_id","int32",0,4,SX_ID),
 SX_FIELD("count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxmta_sym_count={UINT32_C(0x60810040),"sym_count",sxmta_sym_count_fields,SX_COUNT(sxmta_sym_count_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_sym_bytes_fields[]={
 SX_FIELD("chunk_id","int32",0,4,SX_ID),
 SX_FIELD("bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmta_sym_bytes={UINT32_C(0x60810041),"sym_bytes",sxmta_sym_bytes_fields,SX_COUNT(sxmta_sym_bytes_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_sym_empty_sample_fields[]={
 SX_FIELD("chunk_id","int32",0,4,SX_ID),
};
static const sx_layout sxmta_sym_empty_sample={UINT32_C(0x60810042),"sym_empty_sample",sxmta_sym_empty_sample_fields,SX_COUNT(sxmta_sym_empty_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_muse_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("variant","bytes",4,4,SX_ID),
 SX_FIELD("total_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("packed_crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("packed_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("unpacked_bytes","uint32",20,4,SX_SIZE),
};
static const sx_layout sxmta_muse_header={UINT32_C(0x60810043),"muse_header",sxmta_muse_header_fields,SX_COUNT(sxmta_muse_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_galaxy_main_fields[]={
 SX_FIELD("title","char[64]",0,64,SX_NONE),
 SX_FIELD("flags","uint8",64,1,SX_FLAGS),
 SX_FIELD("channels","uint8",65,1,SX_COUNT_PROP),
 SX_FIELD("speed","uint8",66,1,SX_NONE),
 SX_FIELD("tempo","uint8",67,1,SX_NONE),
 SX_FIELD("min_period_16x","uint16",68,2,SX_NONE),
 SX_FIELD("max_period_16x","uint16",70,2,SX_NONE),
 SX_FIELD("global_volume","uint8",72,1,SX_NONE),
};
static const sx_layout sxmta_galaxy_main={UINT32_C(0x60810044),"galaxy_main",sxmta_galaxy_main_fields,SX_COUNT(sxmta_galaxy_main_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_galaxy_order_count_fields[]={
 SX_FIELD("orders_minus_one","uint8",0,1,SX_NONE),
};
static const sx_layout sxmta_galaxy_order_count={UINT32_C(0x60810045),"galaxy_order_count",sxmta_galaxy_order_count_fields,SX_COUNT(sxmta_galaxy_order_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_galaxy_pattern_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
 SX_FIELD("packed_bytes","uint32",1,4,SX_SIZE),
 SX_FIELD("rows_minus_one","uint8",5,1,SX_NONE),
};
static const sx_layout sxmta_galaxy_pattern={UINT32_C(0x60810046),"galaxy_pattern",sxmta_galaxy_pattern_fields,SX_COUNT(sxmta_galaxy_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_galaxy_instrument4_fields[]={
 SX_FIELD("unknown","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("name","char[28]",2,28,SX_NONE),
 SX_FIELD("samples","uint8",30,1,SX_COUNT_PROP),
 SX_FIELD("sample_map","bytes",31,120,SX_NONE),
 SX_FIELD("vibrato_type","uint8",151,1,SX_ID),
 SX_FIELD("vibrato_sweep","uint16",152,2,SX_NONE),
 SX_FIELD("vibrato_depth","uint16",154,2,SX_NONE),
 SX_FIELD("vibrato_rate","uint16",156,2,SX_NONE),
};
static const sx_layout sxmta_galaxy_instrument4={UINT32_C(0x60810047),"galaxy_instrument4",sxmta_galaxy_instrument4_fields,SX_COUNT(sxmta_galaxy_instrument4_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_galaxy_instrument5_fields[]={
 SX_FIELD("header_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("unknown","uint8",4,1,SX_NONE),
 SX_FIELD("instrument","uint8",5,1,SX_ID),
 SX_FIELD("name","char[32]",6,32,SX_NONE),
 SX_FIELD("sample_map","bytes",38,128,SX_NONE),
 SX_FIELD("vibrato_type","uint8",166,1,SX_ID),
 SX_FIELD("vibrato_sweep","uint16",167,2,SX_NONE),
 SX_FIELD("vibrato_depth","uint16",169,2,SX_NONE),
 SX_FIELD("vibrato_rate","uint16",171,2,SX_NONE),
 SX_FIELD("unknown2","bytes",173,7,SX_NONE),
};
static const sx_layout sxmta_galaxy_instrument5={UINT32_C(0x60810048),"galaxy_instrument5",sxmta_galaxy_instrument5_fields,SX_COUNT(sxmta_galaxy_instrument5_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_galaxy_envelope4_fields[]={
 SX_FIELD("pan_volume_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("pan_volume_points","uint8",1,1,SX_NONE),
 SX_FIELD("pan_volume_sustain","uint8",2,1,SX_NONE),
 SX_FIELD("pan_volume_loop_start","uint8",3,1,SX_NONE),
 SX_FIELD("pan_volume_loop_end","uint8",4,1,SX_NONE),
};
static const sx_layout sxmta_galaxy_envelope4={UINT32_C(0x60810049),"galaxy_envelope4",sxmta_galaxy_envelope4_fields,SX_COUNT(sxmta_galaxy_envelope4_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_galaxy_point4_fields[]={
 SX_FIELD("tick_16x","uint16",0,2,SX_NONE),
 SX_FIELD("value","uint8",2,1,SX_NONE),
};
static const sx_layout sxmta_galaxy_point4={UINT32_C(0x6081004A),"galaxy_point4",sxmta_galaxy_point4_fields,SX_COUNT(sxmta_galaxy_point4_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_galaxy_envelope5_fields[]={
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("last_point","uint8",2,1,SX_NONE),
 SX_FIELD("sustain_point","uint8",3,1,SX_NONE),
 SX_FIELD("loop_start_point","uint8",4,1,SX_NONE),
 SX_FIELD("loop_end_point","uint8",5,1,SX_NONE),
};
static const sx_layout sxmta_galaxy_envelope5={UINT32_C(0x6081004B),"galaxy_envelope5",sxmta_galaxy_envelope5_fields,SX_COUNT(sxmta_galaxy_envelope5_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_galaxy_point5_fields[]={
 SX_FIELD("tick_16x","uint16",0,2,SX_NONE),
 SX_FIELD("value","uint16",2,2,SX_NONE),
};
static const sx_layout sxmta_galaxy_point5={UINT32_C(0x6081004C),"galaxy_point5",sxmta_galaxy_point5_fields,SX_COUNT(sxmta_galaxy_point5_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_galaxy_fadeout_fields[]={
 SX_FIELD("fadeout","uint16",0,2,SX_NONE),
};
static const sx_layout sxmta_galaxy_fadeout={UINT32_C(0x6081004D),"galaxy_fadeout",sxmta_galaxy_fadeout_fields,SX_COUNT(sxmta_galaxy_fadeout_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_galaxy_sample_count_fields[]={
 SX_FIELD("samples","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmta_galaxy_sample_count={UINT32_C(0x6081004E),"galaxy_sample_count",sxmta_galaxy_sample_count_fields,SX_COUNT(sxmta_galaxy_sample_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_galaxy_sample4_fields[]={
 SX_FIELD("name","char[28]",0,28,SX_NONE),
 SX_FIELD("pan","uint8",28,1,SX_NONE),
 SX_FIELD("volume","uint8",29,1,SX_NONE),
 SX_FIELD("flags","uint16",30,2,SX_FLAGS),
 SX_FIELD("sample_frames","uint32",32,4,SX_COUNT_PROP),
 SX_FIELD("loop_start_frame","uint32",36,4,SX_NONE),
 SX_FIELD("loop_end_frame","uint32",40,4,SX_NONE),
 SX_FIELD("sample_rate","uint32",44,4,SX_NONE),
 SX_FIELD("reserved1","uint32",48,4,SX_RESERVED),
 SX_FIELD("reserved2","uint32",52,4,SX_RESERVED),
};
static const sx_layout sxmta_galaxy_sample4={UINT32_C(0x6081004F),"galaxy_sample4",sxmta_galaxy_sample4_fields,SX_COUNT(sxmta_galaxy_sample4_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_galaxy_sample5_fields[]={
 SX_FIELD("header_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("name","char[32]",4,32,SX_NONE),
 SX_FIELD("pan","uint16",36,2,SX_NONE),
 SX_FIELD("volume","uint16",38,2,SX_NONE),
 SX_FIELD("flags","uint16",40,2,SX_FLAGS),
 SX_FIELD("unknown","uint16",42,2,SX_NONE),
 SX_FIELD("sample_frames","uint32",44,4,SX_COUNT_PROP),
 SX_FIELD("loop_start_frame","uint32",48,4,SX_NONE),
 SX_FIELD("loop_end_frame","uint32",52,4,SX_NONE),
 SX_FIELD("sample_rate","uint32",56,4,SX_NONE),
};
static const sx_layout sxmta_galaxy_sample5={UINT32_C(0x60810050),"galaxy_sample5",sxmta_galaxy_sample5_fields,SX_COUNT(sxmta_galaxy_sample5_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_gt2_volume_fields[]={
 SX_FIELD("volume","uint16",0,2,SX_NONE),
};
static const sx_layout sxmta_gt2_volume={UINT32_C(0x60810051),"gt2_volume",sxmta_gt2_volume_fields,SX_COUNT(sxmta_gt2_volume_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_aon_arpeggio_fields[]={
 SX_FIELD("note0","uint8",0,1,SX_NONE),
 SX_FIELD("note1","uint8",1,1,SX_NONE),
 SX_FIELD("note2","uint8",2,1,SX_NONE),
 SX_FIELD("note3","uint8",3,1,SX_NONE),
};
static const sx_layout sxmta_aon_arpeggio={UINT32_C(0x60810052),"aon_arpeggio",sxmta_aon_arpeggio_fields,SX_COUNT(sxmta_aon_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_galaxy_point5_signed_fields[]={
 SX_FIELD("tick_16x","uint16",0,2,SX_NONE),
 SX_FIELD("value","int16",2,2,SX_NONE),
};
static const sx_layout sxmta_galaxy_point5_signed={UINT32_C(0x60810053),"galaxy_point5_signed",sxmta_galaxy_point5_signed_fields,SX_COUNT(sxmta_galaxy_point5_signed_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_aon_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("identification","char[42]",4,42,SX_NONE),
};
static const sx_layout sxmta_aon_header={UINT32_C(0x60810054),"aon_header",sxmta_aon_header_fields,SX_COUNT(sxmta_aon_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_aon_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("payload_bytes","int32",4,4,SX_SIZE),
};
static const sx_layout sxmta_aon_chunk={UINT32_C(0x60810055),"aon_chunk",sxmta_aon_chunk_fields,SX_COUNT(sxmta_aon_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_aon_info_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("orders","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("restart_order","uint8",2,1,SX_NONE),
};
static const sx_layout sxmta_aon_info={UINT32_C(0x60810056),"aon_info",sxmta_aon_info_fields,SX_COUNT(sxmta_aon_info_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_aon_sample_fields[]={
 SX_FIELD("instrument_type","uint8",0,1,SX_ID),
 SX_FIELD("volume","uint8",1,1,SX_NONE),
 SX_FIELD("finetune","uint8",2,1,SX_NONE),
 SX_FIELD("waveform","uint8",3,1,SX_ID),
 SX_FIELD("start_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("sample_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("loop_start","uint32",12,4,SX_OFFSET),
 SX_FIELD("loop_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("unused","bytes",20,8,SX_NONE),
 SX_FIELD("envelope_start","uint8",28,1,SX_NONE),
 SX_FIELD("envelope_add","uint8",29,1,SX_NONE),
 SX_FIELD("envelope_end","uint8",30,1,SX_NONE),
 SX_FIELD("envelope_sub","uint8",31,1,SX_NONE),
};
static const sx_layout sxmta_aon_sample={UINT32_C(0x60810057),"aon_sample",sxmta_aon_sample_fields,SX_COUNT(sxmta_aon_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_aon_synth_fields[]={
 SX_FIELD("instrument_type","uint8",0,1,SX_ID),
 SX_FIELD("volume","uint8",1,1,SX_NONE),
 SX_FIELD("finetune","uint8",2,1,SX_NONE),
 SX_FIELD("waveform","uint8",3,1,SX_ID),
 SX_FIELD("waveform_length","uint8",4,1,SX_NONE),
 SX_FIELD("unused1","bytes",5,5,SX_NONE),
 SX_FIELD("vibrato_parameter","uint8",10,1,SX_NONE),
 SX_FIELD("vibrato_delay","uint8",11,1,SX_NONE),
 SX_FIELD("vibrato_waveform","uint8",12,1,SX_ID),
 SX_FIELD("wave_speed","uint8",13,1,SX_NONE),
 SX_FIELD("wave_list_length","uint8",14,1,SX_COUNT_PROP),
 SX_FIELD("wave_loop_start","uint8",15,1,SX_NONE),
 SX_FIELD("wave_loop_length","uint8",16,1,SX_COUNT_PROP),
 SX_FIELD("wave_loop_control","uint8",17,1,SX_FLAGS),
 SX_FIELD("unused2","bytes",18,10,SX_NONE),
 SX_FIELD("envelope_start","uint8",28,1,SX_NONE),
 SX_FIELD("envelope_add","uint8",29,1,SX_NONE),
 SX_FIELD("envelope_end","uint8",30,1,SX_NONE),
 SX_FIELD("envelope_sub","uint8",31,1,SX_NONE),
};
static const sx_layout sxmta_aon_synth={UINT32_C(0x60810058),"aon_synth",sxmta_aon_synth_fields,SX_COUNT(sxmta_aon_synth_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_aon_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument_arpeggio","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxmta_aon_event={UINT32_C(0x60810059),"aon_event",sxmta_aon_event_fields,SX_COUNT(sxmta_aon_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_aon_wave_length_fields[]={
 SX_FIELD("wave_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxmta_aon_wave_length={UINT32_C(0x6081005A),"aon_wave_length",sxmta_aon_wave_length_fields,SX_COUNT(sxmta_aon_wave_length_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_aon_instrument_name_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_NONE),
};
static const sx_layout sxmta_aon_instrument_name={UINT32_C(0x6081005B),"aon_instrument_name",sxmta_aon_instrument_name_fields,SX_COUNT(sxmta_aon_instrument_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dmu_header_fields[]={
 SX_FIELD("magic","char[24]",0,24,SX_SIGNATURE),
 SX_FIELD("arpeggios_enabled","uint16",24,2,SX_FLAGS),
 SX_FIELD("tracks","uint16",26,2,SX_COUNT_PROP),
 SX_FIELD("sequence_0_count","uint32",28,4,SX_COUNT_PROP),
 SX_FIELD("sequence_1_count","uint32",32,4,SX_COUNT_PROP),
 SX_FIELD("sequence_2_count","uint32",36,4,SX_COUNT_PROP),
 SX_FIELD("sequence_3_count","uint32",40,4,SX_COUNT_PROP),
 SX_FIELD("sequence_4_count","uint32",44,4,SX_COUNT_PROP),
 SX_FIELD("sequence_5_count","uint32",48,4,SX_COUNT_PROP),
 SX_FIELD("sequence_6_count","uint32",52,4,SX_COUNT_PROP),
 SX_FIELD("sequence_7_count","uint32",56,4,SX_COUNT_PROP),
 SX_FIELD("instruments","uint32",60,4,SX_COUNT_PROP),
 SX_FIELD("waveforms","uint32",64,4,SX_COUNT_PROP),
 SX_FIELD("samples","uint32",68,4,SX_COUNT_PROP),
 SX_FIELD("sample_data_bytes","uint32",72,4,SX_SIZE),
};
static const sx_layout sxmta_dmu_header={UINT32_C(0x6081005C),"dmu_header",sxmta_dmu_header_fields,SX_COUNT(sxmta_dmu_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_dmu_subsong_fields[]={
 SX_FIELD("loop_enabled","uint8",0,1,SX_FLAGS),
 SX_FIELD("loop_order","uint8",1,1,SX_NONE),
 SX_FIELD("speed","uint8",2,1,SX_NONE),
 SX_FIELD("sequences","uint8",3,1,SX_COUNT_PROP),
 SX_FIELD("name","char[12]",4,12,SX_NONE),
};
static const sx_layout sxmta_dmu_subsong={UINT32_C(0x6081005D),"dmu_subsong",sxmta_dmu_subsong_fields,SX_COUNT(sxmta_dmu_subsong_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dmu_sequence_fields[]={
 SX_FIELD("track","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
static const sx_layout sxmta_dmu_sequence={UINT32_C(0x6081005E),"dmu_sequence",sxmta_dmu_sequence_fields,SX_COUNT(sxmta_dmu_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dmu_instrument_fields[]={
 SX_FIELD("waveform","uint8",0,1,SX_ID),
 SX_FIELD("loop_words","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("volume","uint8",2,1,SX_NONE),
 SX_FIELD("volume_speed","uint8",3,1,SX_NONE),
 SX_FIELD("arpeggio","uint8",4,1,SX_ID),
 SX_FIELD("pitch","uint8",5,1,SX_NONE),
 SX_FIELD("effect_index","uint8",6,1,SX_ID),
 SX_FIELD("delay","uint8",7,1,SX_NONE),
 SX_FIELD("finetune","uint8",8,1,SX_NONE),
 SX_FIELD("pitch_loop","uint8",9,1,SX_NONE),
 SX_FIELD("pitch_speed","uint8",10,1,SX_NONE),
 SX_FIELD("effect","uint8",11,1,SX_ID),
 SX_FIELD("source_wave1","uint8",12,1,SX_ID),
 SX_FIELD("source_wave2","uint8",13,1,SX_ID),
 SX_FIELD("effect_speed","uint8",14,1,SX_NONE),
 SX_FIELD("volume_loop","uint8",15,1,SX_FLAGS),
};
static const sx_layout sxmta_dmu_instrument={UINT32_C(0x6081005F),"dmu_instrument",sxmta_dmu_instrument_fields,SX_COUNT(sxmta_dmu_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dmu_sample_fields[]={
 SX_FIELD("start_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("end_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("loop_start","int32",8,4,SX_OFFSET),
 SX_FIELD("unused","bytes",12,20,SX_NONE),
};
static const sx_layout sxmta_dmu_sample={UINT32_C(0x60810060),"dmu_sample",sxmta_dmu_sample_fields,SX_COUNT(sxmta_dmu_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_dmu_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxmta_dmu_event={UINT32_C(0x60810061),"dmu_event",sxmta_dmu_event_fields,SX_COUNT(sxmta_dmu_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_jam_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("samples","uint16",4,2,SX_COUNT_PROP),
};
static const sx_layout sxmta_jam_header={UINT32_C(0x60810062),"jam_header",sxmta_jam_header_fields,SX_COUNT(sxmta_jam_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_jam_sample_fields[]={
 SX_FIELD("name","char[31]",0,31,SX_NONE),
 SX_FIELD("flags","uint8",31,1,SX_FLAGS),
 SX_FIELD("sample_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("sample_address","uint32",36,4,SX_ADDRESS),
};
static const sx_layout sxmta_jam_sample={UINT32_C(0x60810063),"jam_sample",sxmta_jam_sample_fields,SX_COUNT(sxmta_jam_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_jam_pattern_fields[]={
 SX_FIELD("rows","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("pattern_address","uint32",2,4,SX_ADDRESS),
};
static const sx_layout sxmta_jam_pattern={UINT32_C(0x60810064),"jam_pattern",sxmta_jam_pattern_fields,SX_COUNT(sxmta_jam_pattern_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_jam_event_fields[]={
 SX_FIELD("period","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","int8",1,1,SX_NONE),
 SX_FIELD("speed","uint8",2,1,SX_NONE),
 SX_FIELD("arpeggio","uint8",3,1,SX_NONE),
 SX_FIELD("vibrato","uint8",4,1,SX_NONE),
 SX_FIELD("phase","uint8",5,1,SX_NONE),
 SX_FIELD("volume","uint8",6,1,SX_NONE),
 SX_FIELD("portamento","uint8",7,1,SX_NONE),
};
static const sx_layout sxmta_jam_event={UINT32_C(0x60810065),"jam_event",sxmta_jam_event_fields,SX_COUNT(sxmta_jam_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_bp_header_fields[]={
 SX_FIELD("title","char[26]",0,26,SX_NONE),
 SX_FIELD("magic","bytes",26,3,SX_SIGNATURE),
 SX_FIELD("waveforms","uint8",29,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",30,2,SX_COUNT_PROP),
};
static const sx_layout sxmta_bp_header={UINT32_C(0x60810066),"bp_header",sxmta_bp_header_fields,SX_COUNT(sxmta_bp_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_bp_sample_fields[]={
 SX_FIELD("name","char[24]",0,24,SX_NONE),
 SX_FIELD("sample_words","uint16",24,2,SX_COUNT_PROP),
 SX_FIELD("loop_start","uint16",26,2,SX_OFFSET),
 SX_FIELD("loop_words","uint16",28,2,SX_COUNT_PROP),
 SX_FIELD("volume","uint16",30,2,SX_NONE),
};
static const sx_layout sxmta_bp_sample={UINT32_C(0x60810067),"bp_sample",sxmta_bp_sample_fields,SX_COUNT(sxmta_bp_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_bp_synth1_fields[]={
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("waveform","uint8",1,1,SX_ID),
 SX_FIELD("waveform_words","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("adsr_control","uint8",4,1,SX_FLAGS),
 SX_FIELD("adsr_table","uint8",5,1,SX_ID),
 SX_FIELD("adsr_length","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("adsr_speed","uint8",8,1,SX_NONE),
 SX_FIELD("lfo_control","uint8",9,1,SX_FLAGS),
 SX_FIELD("lfo_table","uint8",10,1,SX_ID),
 SX_FIELD("lfo_depth","uint8",11,1,SX_NONE),
 SX_FIELD("lfo_length","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("unused1","uint8",14,1,SX_NONE),
 SX_FIELD("lfo_delay","uint8",15,1,SX_NONE),
 SX_FIELD("lfo_speed","uint8",16,1,SX_NONE),
 SX_FIELD("envelope_control","uint8",17,1,SX_FLAGS),
 SX_FIELD("envelope_table","uint8",18,1,SX_ID),
 SX_FIELD("unused2","uint8",19,1,SX_NONE),
 SX_FIELD("envelope_length","uint16",20,2,SX_COUNT_PROP),
 SX_FIELD("unused3","uint8",22,1,SX_NONE),
 SX_FIELD("envelope_delay","uint8",23,1,SX_NONE),
 SX_FIELD("envelope_speed","uint8",24,1,SX_NONE),
 SX_FIELD("volume","uint8",25,1,SX_NONE),
 SX_FIELD("unused4","bytes",26,6,SX_NONE),
};
static const sx_layout sxmta_bp_synth1={UINT32_C(0x60810068),"bp_synth1",sxmta_bp_synth1_fields,SX_COUNT(sxmta_bp_synth1_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_bp_synth2_fields[]={
 SX_FIELD("kind","uint8",0,1,SX_ID),
 SX_FIELD("waveform","uint8",1,1,SX_ID),
 SX_FIELD("waveform_words","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("adsr_control","uint8",4,1,SX_FLAGS),
 SX_FIELD("adsr_table","uint8",5,1,SX_ID),
 SX_FIELD("adsr_length","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("adsr_speed","uint8",8,1,SX_NONE),
 SX_FIELD("lfo_control","uint8",9,1,SX_FLAGS),
 SX_FIELD("lfo_table","uint8",10,1,SX_ID),
 SX_FIELD("lfo_depth","uint8",11,1,SX_NONE),
 SX_FIELD("lfo_length","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("lfo_delay","uint8",14,1,SX_NONE),
 SX_FIELD("lfo_speed","uint8",15,1,SX_NONE),
 SX_FIELD("envelope_control","uint8",16,1,SX_FLAGS),
 SX_FIELD("envelope_table","uint8",17,1,SX_ID),
 SX_FIELD("envelope_length","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("envelope_delay","uint8",20,1,SX_NONE),
 SX_FIELD("envelope_speed","uint8",21,1,SX_NONE),
 SX_FIELD("effect_control","uint8",22,1,SX_FLAGS),
 SX_FIELD("effect_speed","uint8",23,1,SX_NONE),
 SX_FIELD("effect_delay","uint8",24,1,SX_NONE),
 SX_FIELD("modulation_control","uint8",25,1,SX_FLAGS),
 SX_FIELD("modulation_table","uint8",26,1,SX_ID),
 SX_FIELD("modulation_speed","uint8",27,1,SX_NONE),
 SX_FIELD("modulation_delay","uint8",28,1,SX_NONE),
 SX_FIELD("volume","uint8",29,1,SX_NONE),
 SX_FIELD("modulation_length","uint16",30,2,SX_COUNT_PROP),
};
static const sx_layout sxmta_bp_synth2={UINT32_C(0x60810069),"bp_synth2",sxmta_bp_synth2_fields,SX_COUNT(sxmta_bp_synth2_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_bp_step_fields[]={
 SX_FIELD("track","uint16",0,2,SX_ID),
 SX_FIELD("sound_transpose","int8",2,1,SX_NONE),
 SX_FIELD("note_transpose","int8",3,1,SX_NONE),
};
static const sx_layout sxmta_bp_step={UINT32_C(0x6081006A),"bp_step",sxmta_bp_step_fields,SX_COUNT(sxmta_bp_step_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_bp_event_fields[]={
 SX_FIELD("note","int8",0,1,SX_NONE),
 SX_FIELD("instrument_option","uint8",1,1,SX_FLAGS),
 SX_FIELD("parameter","uint8",2,1,SX_NONE),
};
static const sx_layout sxmta_bp_event={UINT32_C(0x6081006B),"bp_event",sxmta_bp_event_fields,SX_COUNT(sxmta_bp_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_fuchs_header_fields[]={
 SX_FIELD("title","char[10]",0,10,SX_NONE),
 SX_FIELD("sample_data_bytes","uint32",10,4,SX_SIZE),
};
static const sx_layout sxmta_fuchs_header={UINT32_C(0x6081006C),"fuchs_header",sxmta_fuchs_header_fields,SX_COUNT(sxmta_fuchs_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_fuchs_sample_bytes_fields[]={
 SX_FIELD("sample_bytes","uint16",0,2,SX_SIZE),
};
static const sx_layout sxmta_fuchs_sample_bytes={UINT32_C(0x6081006D),"fuchs_sample_bytes",sxmta_fuchs_sample_bytes_fields,SX_COUNT(sxmta_fuchs_sample_bytes_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_fuchs_volume_fields[]={
 SX_FIELD("volume","uint16",0,2,SX_NONE),
};
static const sx_layout sxmta_fuchs_volume={UINT32_C(0x6081006E),"fuchs_volume",sxmta_fuchs_volume_fields,SX_COUNT(sxmta_fuchs_volume_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_fuchs_loop_fields[]={
 SX_FIELD("loop_start","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxmta_fuchs_loop={UINT32_C(0x6081006F),"fuchs_loop",sxmta_fuchs_loop_fields,SX_COUNT(sxmta_fuchs_loop_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_fuchs_order_count_fields[]={
 SX_FIELD("orders","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmta_fuchs_order_count={UINT32_C(0x60810070),"fuchs_order_count",sxmta_fuchs_order_count_fields,SX_COUNT(sxmta_fuchs_order_count_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_fuchs_pattern_chunk_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("pattern_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmta_fuchs_pattern_chunk={UINT32_C(0x60810071),"fuchs_pattern_chunk",sxmta_fuchs_pattern_chunk_fields,SX_COUNT(sxmta_fuchs_pattern_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_fuchs_samples_marker_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_ID),
};
static const sx_layout sxmta_fuchs_samples_marker={UINT32_C(0x60810072),"fuchs_samples_marker",sxmta_fuchs_samples_marker_fields,SX_COUNT(sxmta_fuchs_samples_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_sid2_header_fields[]={
 SX_FIELD("midi_mode","uint16",0,2,SX_FLAGS),
 SX_FIELD("last_order","uint8",2,1,SX_NONE),
 SX_FIELD("speed","uint8",3,1,SX_NONE),
 SX_FIELD("sample_header_bytes","uint16",4,2,SX_SIZE),
 SX_FIELD("id_bytes","uint32",6,4,SX_SIZE),
 SX_FIELD("song_length_bytes","uint32",10,4,SX_SIZE),
 SX_FIELD("position_bytes","uint32",14,4,SX_SIZE),
 SX_FIELD("note_transpose_bytes","uint32",18,4,SX_SIZE),
 SX_FIELD("instrument_transpose_bytes","uint32",22,4,SX_SIZE),
 SX_FIELD("instrument_bytes","uint32",26,4,SX_SIZE),
 SX_FIELD("waveform_list_bytes","uint32",30,4,SX_SIZE),
 SX_FIELD("arpeggio_bytes","uint32",34,4,SX_SIZE),
 SX_FIELD("vibrato_bytes","uint32",38,4,SX_SIZE),
 SX_FIELD("sample_info_bytes","uint32",42,4,SX_SIZE),
 SX_FIELD("track_table_bytes","uint32",46,4,SX_SIZE),
 SX_FIELD("track_data_bytes","uint32",50,4,SX_SIZE),
 SX_FIELD("unused","bytes",54,4,SX_NONE),
 SX_FIELD("magic","char[28]",58,28,SX_SIGNATURE),
};
static const sx_layout sxmta_sid2_header={UINT32_C(0x60810073),"sid2_header",sxmta_sid2_header_fields,SX_COUNT(sxmta_sid2_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_sid2_track_number_fields[]={
 SX_FIELD("track","uint8",0,1,SX_ID),
};
static const sx_layout sxmta_sid2_track_number={UINT32_C(0x60810074),"sid2_track_number",sxmta_sid2_track_number_fields,SX_COUNT(sxmta_sid2_track_number_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_sid2_transpose_fields[]={
 SX_FIELD("transpose","int8",0,1,SX_NONE),
};
static const sx_layout sxmta_sid2_transpose={UINT32_C(0x60810075),"sid2_transpose",sxmta_sid2_transpose_fields,SX_COUNT(sxmta_sid2_transpose_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_sid2_track_offset_fields[]={
 SX_FIELD("track_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxmta_sid2_track_offset={UINT32_C(0x60810076),"sid2_track_offset",sxmta_sid2_track_offset_fields,SX_COUNT(sxmta_sid2_track_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_sid2_instrument_fields[]={
 SX_FIELD("waveform_list","uint8",0,1,SX_ID),
 SX_FIELD("waveform_list_last_index","uint8",1,1,SX_NONE),
 SX_FIELD("waveform_list_speed","uint8",2,1,SX_NONE),
 SX_FIELD("waveform_list_delay","uint8",3,1,SX_NONE),
 SX_FIELD("arpeggio","uint8",4,1,SX_ID),
 SX_FIELD("arpeggio_last_index","uint8",5,1,SX_NONE),
 SX_FIELD("arpeggio_speed","uint8",6,1,SX_NONE),
 SX_FIELD("arpeggio_delay","uint8",7,1,SX_NONE),
 SX_FIELD("vibrato","uint8",8,1,SX_ID),
 SX_FIELD("vibrato_last_index","uint8",9,1,SX_NONE),
 SX_FIELD("vibrato_speed","uint8",10,1,SX_NONE),
 SX_FIELD("vibrato_delay","uint8",11,1,SX_NONE),
 SX_FIELD("pitch_bend_speed","int8",12,1,SX_NONE),
 SX_FIELD("pitch_bend_delay","uint8",13,1,SX_NONE),
 SX_FIELD("unused1","bytes",14,2,SX_NONE),
 SX_FIELD("attack_max","uint8",16,1,SX_NONE),
 SX_FIELD("attack_speed","uint8",17,1,SX_NONE),
 SX_FIELD("decay_min","uint8",18,1,SX_NONE),
 SX_FIELD("decay_speed","uint8",19,1,SX_NONE),
 SX_FIELD("sustain_time","uint8",20,1,SX_NONE),
 SX_FIELD("release_min","uint8",21,1,SX_NONE),
 SX_FIELD("release_speed","uint8",22,1,SX_NONE),
 SX_FIELD("unused2","bytes",23,9,SX_NONE),
};
static const sx_layout sxmta_sid2_instrument={UINT32_C(0x60810077),"sid2_instrument",sxmta_sid2_instrument_fields,SX_COUNT(sxmta_sid2_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_sid2_sample_fields[]={
 SX_FIELD("address_placeholder","uint32",0,4,SX_ADDRESS),
 SX_FIELD("sample_words","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("loop_start_words","uint16",6,2,SX_NONE),
 SX_FIELD("loop_words","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("negate_start_words","uint16",10,2,SX_NONE),
 SX_FIELD("negate_end_words","uint16",12,2,SX_NONE),
 SX_FIELD("negate_loop_index","uint16",14,2,SX_NONE),
 SX_FIELD("negate_status","uint16",16,2,SX_FLAGS),
 SX_FIELD("negate_speed","int16",18,2,SX_NONE),
 SX_FIELD("negate_position","int32",20,4,SX_NONE),
 SX_FIELD("negate_index","uint16",24,2,SX_NONE),
 SX_FIELD("negate_enabled","int16",26,2,SX_NONE),
 SX_FIELD("unused","bytes",28,4,SX_NONE),
 SX_FIELD("name","char[32]",32,32,SX_NONE),
};
static const sx_layout sxmta_sid2_sample={UINT32_C(0x60810078),"sid2_sample",sxmta_sid2_sample_fields,SX_COUNT(sxmta_sid2_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_med2_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
};
static const sx_layout sxmta_med2_header={UINT32_C(0x60810079),"med2_header",sxmta_med2_header_fields,SX_COUNT(sxmta_med2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_med2_name_fields[]={
 SX_FIELD("name","char[40]",0,40,SX_NONE),
};
static const sx_layout sxmta_med2_name={UINT32_C(0x6081007A),"med2_name",sxmta_med2_name_fields,SX_COUNT(sxmta_med2_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_med2_loop_start_fields[]={
 SX_FIELD("loop_start","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxmta_med2_loop_start={UINT32_C(0x6081007B),"med2_loop_start",sxmta_med2_loop_start_fields,SX_COUNT(sxmta_med2_loop_start_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_med2_loop_bytes_fields[]={
 SX_FIELD("loop_bytes","uint16",0,2,SX_SIZE),
};
static const sx_layout sxmta_med2_loop_bytes={UINT32_C(0x6081007C),"med2_loop_bytes",sxmta_med2_loop_bytes_fields,SX_COUNT(sxmta_med2_loop_bytes_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_med2_song_fields[]={
 SX_FIELD("orders","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("tempo","uint16",2,2,SX_NONE),
 SX_FIELD("flags","uint16",4,2,SX_FLAGS),
 SX_FIELD("sliding","uint16",6,2,SX_NONE),
 SX_FIELD("jump_mask","uint32",8,4,SX_FLAGS),
 SX_FIELD("rgb","bytes",12,16,SX_NONE),
};
static const sx_layout sxmta_med2_song={UINT32_C(0x6081007D),"med2_song",sxmta_med2_song_fields,SX_COUNT(sxmta_med2_song_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_med2_pattern_header_fields[]={
 SX_FIELD("pattern_address","uint32",0,4,SX_ADDRESS),
};
static const sx_layout sxmta_med2_pattern_header={UINT32_C(0x6081007E),"med2_pattern_header",sxmta_med2_pattern_header_fields,SX_COUNT(sxmta_med2_pattern_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_med2_event_fields[]={
 SX_FIELD("period","uint16",0,2,SX_NONE),
 SX_FIELD("instrument_effect","uint8",2,1,SX_FLAGS),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxmta_med2_event={UINT32_C(0x6081007F),"med2_event",sxmta_med2_event_fields,SX_COUNT(sxmta_med2_event_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_uni4_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("channels","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",5,2,SX_COUNT_PROP),
 SX_FIELD("patterns","uint16",7,2,SX_COUNT_PROP),
 SX_FIELD("tracks","uint16",9,2,SX_COUNT_PROP),
 SX_FIELD("instruments","uint16",11,2,SX_COUNT_PROP),
 SX_FIELD("speed","uint8",13,1,SX_NONE),
 SX_FIELD("tempo","uint8",14,1,SX_NONE),
 SX_FIELD("orders_fixed","bytes",15,256,SX_NONE),
 SX_FIELD("pan_fixed","bytes",271,32,SX_NONE),
 SX_FIELD("flags","uint8",303,1,SX_FLAGS),
};
static const sx_layout sxmta_uni4_header={UINT32_C(0x60810080),"uni4_header",sxmta_uni4_header_fields,SX_COUNT(sxmta_uni4_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_uni5_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("channels","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",5,2,SX_COUNT_PROP),
 SX_FIELD("restart_order","uint16",7,2,SX_NONE),
 SX_FIELD("patterns","uint16",9,2,SX_COUNT_PROP),
 SX_FIELD("tracks","uint16",11,2,SX_COUNT_PROP),
 SX_FIELD("instruments","uint16",13,2,SX_COUNT_PROP),
 SX_FIELD("speed","uint8",15,1,SX_NONE),
 SX_FIELD("tempo","uint8",16,1,SX_NONE),
 SX_FIELD("orders_fixed","bytes",17,256,SX_NONE),
 SX_FIELD("pan_fixed","bytes",273,32,SX_NONE),
 SX_FIELD("flags","uint8",305,1,SX_FLAGS),
};
static const sx_layout sxmta_uni5_header={UINT32_C(0x60810081),"uni5_header",sxmta_uni5_header_fields,SX_COUNT(sxmta_uni5_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_uni6_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("unused","uint8",4,1,SX_NONE),
 SX_FIELD("flags","uint16",5,2,SX_FLAGS),
 SX_FIELD("channels","uint8",7,1,SX_COUNT_PROP),
 SX_FIELD("voices","uint8",8,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",9,2,SX_COUNT_PROP),
 SX_FIELD("patterns","uint16",11,2,SX_COUNT_PROP),
 SX_FIELD("tracks","uint16",13,2,SX_COUNT_PROP),
 SX_FIELD("instruments","uint16",15,2,SX_COUNT_PROP),
 SX_FIELD("samples","uint16",17,2,SX_COUNT_PROP),
 SX_FIELD("restart_order","uint16",19,2,SX_NONE),
 SX_FIELD("speed","uint8",21,1,SX_NONE),
 SX_FIELD("tempo","uint8",22,1,SX_NONE),
 SX_FIELD("volume","uint8",23,1,SX_NONE),
};
static const sx_layout sxmta_uni6_header={UINT32_C(0x60810082),"uni6_header",sxmta_uni6_header_fields,SX_COUNT(sxmta_uni6_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_apun_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("flags","uint16",6,2,SX_FLAGS),
 SX_FIELD("channels","uint8",8,1,SX_COUNT_PROP),
 SX_FIELD("voices","uint8",9,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("patterns","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("tracks","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("instruments","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("samples","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("restart_order","uint16",20,2,SX_NONE),
 SX_FIELD("speed","uint8",22,1,SX_NONE),
 SX_FIELD("tempo","uint8",23,1,SX_NONE),
 SX_FIELD("volume","uint8",24,1,SX_NONE),
};
static const sx_layout sxmta_apun_header={UINT32_C(0x60810083),"apun_header",sxmta_apun_header_fields,SX_COUNT(sxmta_apun_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_uni_bpm_limit_fields[]={
 SX_FIELD("bpm_limit","uint16",0,2,SX_NONE),
};
static const sx_layout sxmta_uni_bpm_limit={UINT32_C(0x60810084),"uni_bpm_limit",sxmta_uni_bpm_limit_fields,SX_COUNT(sxmta_uni_bpm_limit_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_uni_sample_fields[]={
 SX_FIELD("flags","uint16",0,2,SX_FLAGS),
 SX_FIELD("sample_rate","uint32",2,4,SX_NONE),
 SX_FIELD("volume","uint8",6,1,SX_NONE),
 SX_FIELD("pan","uint16",7,2,SX_NONE),
 SX_FIELD("sample_frames","uint32",9,4,SX_COUNT_PROP),
 SX_FIELD("loop_start_frame","uint32",13,4,SX_NONE),
 SX_FIELD("loop_end_frame","uint32",17,4,SX_NONE),
 SX_FIELD("sustain_start_frame","uint32",21,4,SX_NONE),
 SX_FIELD("sustain_end_frame","uint32",25,4,SX_NONE),
 SX_FIELD("global_volume","uint8",29,1,SX_NONE),
 SX_FIELD("vibrato_flags","uint8",30,1,SX_FLAGS),
 SX_FIELD("vibrato_type","uint8",31,1,SX_ID),
 SX_FIELD("vibrato_sweep","uint8",32,1,SX_NONE),
 SX_FIELD("vibrato_depth","uint8",33,1,SX_NONE),
 SX_FIELD("vibrato_rate","uint8",34,1,SX_NONE),
};
static const sx_layout sxmta_uni_sample={UINT32_C(0x60810085),"uni_sample",sxmta_uni_sample_fields,SX_COUNT(sxmta_uni_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is1_header_fields[]={
 SX_FIELD("magic","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("positions","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("track_rows","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("unknown12","bytes",12,4,SX_NONE),
 SX_FIELD("samples","uint8",16,1,SX_COUNT_PROP),
 SX_FIELD("waveforms","uint8",17,1,SX_COUNT_PROP),
 SX_FIELD("instruments","uint8",18,1,SX_COUNT_PROP),
 SX_FIELD("subsongs","uint8",19,1,SX_COUNT_PROP),
 SX_FIELD("eg_tables","uint8",20,1,SX_COUNT_PROP),
 SX_FIELD("adsr_tables","uint8",21,1,SX_COUNT_PROP),
 SX_FIELD("unknown22","bytes",22,14,SX_NONE),
 SX_FIELD("name","char[28]",36,28,SX_NONE),
 SX_FIELD("skipped_text","char[140]",64,140,SX_NONE),
};
static const sx_layout sxmta_is1_header={UINT32_C(0x60810086),"is1_header",sxmta_is1_header_fields,SX_COUNT(sxmta_is1_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is1_sample_info_fields[]={
 SX_FIELD("unknown0","uint8",0,1,SX_NONE),
 SX_FIELD("name","char[23]",1,23,SX_NONE),
 SX_FIELD("unknown24","bytes",24,4,SX_NONE),
};
static const sx_layout sxmta_is1_sample_info={UINT32_C(0x60810087),"is1_sample_info",sxmta_is1_sample_info_fields,SX_COUNT(sxmta_is1_sample_info_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_is_sample_bytes_fields[]={
 SX_FIELD("sample_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxmta_is_sample_bytes={UINT32_C(0x60810088),"is_sample_bytes",sxmta_is_sample_bytes_fields,SX_COUNT(sxmta_is_sample_bytes_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is1_instrument_fields[]={
 SX_FIELD("waveform","uint8",0,1,SX_ID),
 SX_FIELD("synthesis_enabled","uint8",1,1,SX_FLAGS),
 SX_FIELD("waveform_bytes","uint16",2,2,SX_SIZE),
 SX_FIELD("repeat_bytes","uint16",4,2,SX_SIZE),
 SX_FIELD("volume","uint8",6,1,SX_NONE),
 SX_FIELD("portamento_speed","int8",7,1,SX_NONE),
 SX_FIELD("adsr_enabled","uint8",8,1,SX_FLAGS),
 SX_FIELD("adsr_table","uint8",9,1,SX_ID),
 SX_FIELD("adsr_length","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("unknown12","bytes",12,2,SX_NONE),
 SX_FIELD("portamento_enabled","uint8",14,1,SX_FLAGS),
 SX_FIELD("unknown15","bytes",15,5,SX_NONE),
 SX_FIELD("vibrato_delay","uint8",20,1,SX_NONE),
 SX_FIELD("vibrato_speed","uint8",21,1,SX_NONE),
 SX_FIELD("vibrato_level","uint8",22,1,SX_NONE),
 SX_FIELD("eg_counter_offset","uint8",23,1,SX_NONE),
 SX_FIELD("eg_counter_mode","uint8",24,1,SX_ID),
 SX_FIELD("eg_table","uint8",25,1,SX_ID),
 SX_FIELD("eg_length","uint16",26,2,SX_COUNT_PROP),
};
static const sx_layout sxmta_is1_instrument={UINT32_C(0x60810089),"is1_instrument",sxmta_is1_instrument_fields,SX_COUNT(sxmta_is1_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is1_subsong_fields[]={
 SX_FIELD("unknown0","bytes",0,4,SX_NONE),
 SX_FIELD("speed","uint8",4,1,SX_NONE),
 SX_FIELD("rows_per_track","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("first_position","uint16",6,2,SX_NONE),
 SX_FIELD("last_position","uint16",8,2,SX_NONE),
 SX_FIELD("restart_position","uint16",10,2,SX_NONE),
 SX_FIELD("unknown12","bytes",12,2,SX_NONE),
};
static const sx_layout sxmta_is1_subsong={UINT32_C(0x6081008A),"is1_subsong",sxmta_is1_subsong_fields,SX_COUNT(sxmta_is1_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is_position_fields[]={
 SX_FIELD("start_track_row","uint16",0,2,SX_NONE),
 SX_FIELD("sound_transpose","int8",2,1,SX_NONE),
 SX_FIELD("note_transpose","int8",3,1,SX_NONE),
};
static const sx_layout sxmta_is_position={UINT32_C(0x6081008B),"is_position",sxmta_is_position_fields,SX_COUNT(sxmta_is_position_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is1_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("arpeggio_effect","uint8",2,1,SX_FLAGS),
 SX_FIELD("argument","uint8",3,1,SX_NONE),
};
static const sx_layout sxmta_is1_event={UINT32_C(0x6081008C),"is1_event",sxmta_is1_event_fields,SX_COUNT(sxmta_is1_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_is_unsigned_value_fields[]={
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sxmta_is_unsigned_value={UINT32_C(0x6081008D),"is_unsigned_value",sxmta_is_unsigned_value_fields,SX_COUNT(sxmta_is_unsigned_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_is_signed_value_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
static const sx_layout sxmta_is_signed_value={UINT32_C(0x6081008E),"is_signed_value",sxmta_is_signed_value_fields,SX_COUNT(sxmta_is_signed_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_is2_header_fields[]={
 SX_FIELD("magic","bytes",0,8,SX_SIGNATURE),
};
static const sx_layout sxmta_is2_header={UINT32_C(0x6081008F),"is2_header",sxmta_is2_header_fields,SX_COUNT(sxmta_is2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_is2_section_fields[]={
 SX_FIELD("tag","bytes",0,4,SX_ID),
 SX_FIELD("count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxmta_is2_section={UINT32_C(0x60810090),"is2_section",sxmta_is2_section_fields,SX_COUNT(sxmta_is2_section_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is2_subsong_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
 SX_FIELD("rows_per_track","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("first_position","uint16",2,2,SX_NONE),
 SX_FIELD("last_position","uint16",4,2,SX_NONE),
 SX_FIELD("restart_position","uint16",6,2,SX_NONE),
 SX_FIELD("frequency_hz","uint16",8,2,SX_NONE),
};
static const sx_layout sxmta_is2_subsong={UINT32_C(0x60810091),"is2_subsong",sxmta_is2_subsong_fields,SX_COUNT(sxmta_is2_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is2_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("transpose_arpeggio_effect","uint8",2,1,SX_FLAGS),
 SX_FIELD("argument","uint8",3,1,SX_NONE),
};
static const sx_layout sxmta_is2_event={UINT32_C(0x60810092),"is2_event",sxmta_is2_event_fields,SX_COUNT(sxmta_is2_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_is2_sample_fields[]={
 SX_FIELD("one_shot_words","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("repeat_words","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("sample_number","int8",4,1,SX_NONE),
 SX_FIELD("volume","uint8",5,1,SX_NONE),
 SX_FIELD("vibrato_delay","uint8",6,1,SX_NONE),
 SX_FIELD("vibrato_speed","uint8",7,1,SX_NONE),
 SX_FIELD("vibrato_level","uint8",8,1,SX_NONE),
 SX_FIELD("portamento_speed","uint8",9,1,SX_NONE),
 SX_FIELD("unknown10","bytes",10,6,SX_NONE),
};
static const sx_layout sxmta_is2_sample={UINT32_C(0x60810093),"is2_sample",sxmta_is2_sample_fields,SX_COUNT(sxmta_is2_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is2_sample_name_fields[]={
 SX_FIELD("name","char[20]",0,20,SX_NONE),
};
static const sx_layout sxmta_is2_sample_name={UINT32_C(0x60810094),"is2_sample_name",sxmta_is2_sample_name_fields,SX_COUNT(sxmta_is2_sample_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_is2_sample_copy_fields[]={
 SX_FIELD("uninterpreted_copy","bytes",0,8,SX_NONE),
};
static const sx_layout sxmta_is2_sample_copy={UINT32_C(0x60810095),"is2_sample_copy",sxmta_is2_sample_copy_fields,SX_COUNT(sxmta_is2_sample_copy_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_is2_synth_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_ID),
 SX_FIELD("name","char[20]",4,20,SX_NONE),
 SX_FIELD("waveform_bytes","uint16",24,2,SX_SIZE),
 SX_FIELD("volume","uint8",26,1,SX_NONE),
 SX_FIELD("vibrato_delay","uint8",27,1,SX_NONE),
 SX_FIELD("vibrato_speed","uint8",28,1,SX_NONE),
 SX_FIELD("vibrato_level","uint8",29,1,SX_NONE),
 SX_FIELD("portamento_speed","uint8",30,1,SX_NONE),
 SX_FIELD("adsr_length","uint8",31,1,SX_NONE),
 SX_FIELD("adsr_repeat","uint8",32,1,SX_NONE),
 SX_FIELD("unknown33","bytes",33,4,SX_NONE),
 SX_FIELD("sustain_point","uint8",37,1,SX_NONE),
 SX_FIELD("sustain_speed","uint8",38,1,SX_NONE),
 SX_FIELD("amf_length","uint8",39,1,SX_NONE),
 SX_FIELD("amf_repeat","uint8",40,1,SX_NONE),
 SX_FIELD("eg_mode","uint8",41,1,SX_ID),
 SX_FIELD("eg_enabled","uint8",42,1,SX_FLAGS),
 SX_FIELD("start_len","uint8",43,1,SX_NONE),
 SX_FIELD("stop_rep","uint8",44,1,SX_NONE),
 SX_FIELD("speed_up","uint8",45,1,SX_NONE),
 SX_FIELD("speed_down","uint8",46,1,SX_NONE),
 SX_FIELD("unknown47","bytes",47,19,SX_NONE),
};
static const sx_layout sxmta_is2_synth={UINT32_C(0x60810096),"is2_synth",sxmta_is2_synth_fields,SX_COUNT(sxmta_is2_synth_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is2_arpeggio_fields[]={
 SX_FIELD("length","uint8",0,1,SX_NONE),
 SX_FIELD("repeat","uint8",1,1,SX_NONE),
 SX_FIELD("value0","int8",2,1,SX_NONE),
 SX_FIELD("value1","int8",3,1,SX_NONE),
 SX_FIELD("value2","int8",4,1,SX_NONE),
 SX_FIELD("value3","int8",5,1,SX_NONE),
 SX_FIELD("value4","int8",6,1,SX_NONE),
 SX_FIELD("value5","int8",7,1,SX_NONE),
 SX_FIELD("value6","int8",8,1,SX_NONE),
 SX_FIELD("value7","int8",9,1,SX_NONE),
 SX_FIELD("value8","int8",10,1,SX_NONE),
 SX_FIELD("value9","int8",11,1,SX_NONE),
 SX_FIELD("value10","int8",12,1,SX_NONE),
 SX_FIELD("value11","int8",13,1,SX_NONE),
 SX_FIELD("value12","int8",14,1,SX_NONE),
 SX_FIELD("value13","int8",15,1,SX_NONE),
};
static const sx_layout sxmta_is2_arpeggio={UINT32_C(0x60810097),"is2_arpeggio",sxmta_is2_arpeggio_fields,SX_COUNT(sxmta_is2_arpeggio_fields),SX_LE};
static const sx_layout *const sx_musictail_layouts[]={
 &sxmta_text,
 &sxmta_pascal_text_length,
 &sxmta_text_length16,
 &sxmta_order8,
 &sxmta_order16be,
 &sxmta_order16le,
 &sxmta_count16be,
 &sxmta_volume8,
 &sxmta_pan16be,
 &sxmta_chunk_le,
 &sxmta_riff_header,
 &sxmta_gtk_header,
 &sxmta_gtk_sample1,
 &sxmta_gtk_sample2,
 &sxmta_gtk_sample3,
 &sxmta_gtk_event4,
 &sxmta_gtk_event5,
 &sxmta_gt2_header_new,
 &sxmta_gt2_header_old,
 &sxmta_gt2_chunk,
 &sxmta_gt2_song,
 &sxmta_gt2_pattern,
 &sxmta_gt2_track_name,
 &sxmta_gt2_timing,
 &sxmta_gt2_period_mode,
 &sxmta_gt2_sample1,
 &sxmta_gt2_sample2,
 &sxmta_gt2_instrument,
 &sxmta_gt2_note_map,
 &sxmta_tcb_header,
 &sxmta_tcb_amiga_flag,
 &sxmta_tcb_instrument_name,
 &sxmta_tcb_special,
 &sxmta_tcb_event,
 &sxmta_tcb_sample_area,
 &sxmta_tcb_sample_properties,
 &sxmta_tcb_sample_location,
 &sxmta_gmc_sample,
 &sxmta_gmc_orders,
 &sxmta_gmc_pattern_offset,
 &sxmta_gmc_event,
 &sxmta_fuchs_event,
 &sxmta_kris_title,
 &sxmta_kris_sample,
 &sxmta_kris_synth,
 &sxmta_kris_header,
 &sxmta_kris_track_ref,
 &sxmta_kris_event,
 &sxmta_c67_header,
 &sxmta_c67_name,
 &sxmta_c67_sample,
 &sxmta_c67_fm_instrument,
 &sxmta_c67_pattern_offset,
 &sxmta_c67_pattern_bytes,
 &sxmta_dsym_header,
 &sxmta_dsym_sample_flags,
 &sxmta_dsym_sample_words,
 &sxmta_dsym_commands,
 &sxmta_dsym_packing,
 &sxmta_dsym_sample,
 &sxmta_dsym_event,
 &sxmta_sym_header,
 &sxmta_sym_value,
 &sxmta_sym_count,
 &sxmta_sym_bytes,
 &sxmta_sym_empty_sample,
 &sxmta_muse_header,
 &sxmta_galaxy_main,
 &sxmta_galaxy_order_count,
 &sxmta_galaxy_pattern,
 &sxmta_galaxy_instrument4,
 &sxmta_galaxy_instrument5,
 &sxmta_galaxy_envelope4,
 &sxmta_galaxy_point4,
 &sxmta_galaxy_envelope5,
 &sxmta_galaxy_point5,
 &sxmta_galaxy_fadeout,
 &sxmta_galaxy_sample_count,
 &sxmta_galaxy_sample4,
 &sxmta_galaxy_sample5,
 &sxmta_gt2_volume,
 &sxmta_aon_arpeggio,
 &sxmta_galaxy_point5_signed,
 &sxmta_aon_header,
 &sxmta_aon_chunk,
 &sxmta_aon_info,
 &sxmta_aon_sample,
 &sxmta_aon_synth,
 &sxmta_aon_event,
 &sxmta_aon_wave_length,
 &sxmta_aon_instrument_name,
 &sxmta_dmu_header,
 &sxmta_dmu_subsong,
 &sxmta_dmu_sequence,
 &sxmta_dmu_instrument,
 &sxmta_dmu_sample,
 &sxmta_dmu_event,
 &sxmta_jam_header,
 &sxmta_jam_sample,
 &sxmta_jam_pattern,
 &sxmta_jam_event,
 &sxmta_bp_header,
 &sxmta_bp_sample,
 &sxmta_bp_synth1,
 &sxmta_bp_synth2,
 &sxmta_bp_step,
 &sxmta_bp_event,
 &sxmta_fuchs_header,
 &sxmta_fuchs_sample_bytes,
 &sxmta_fuchs_volume,
 &sxmta_fuchs_loop,
 &sxmta_fuchs_order_count,
 &sxmta_fuchs_pattern_chunk,
 &sxmta_fuchs_samples_marker,
 &sxmta_sid2_header,
 &sxmta_sid2_track_number,
 &sxmta_sid2_transpose,
 &sxmta_sid2_track_offset,
 &sxmta_sid2_instrument,
 &sxmta_sid2_sample,
 &sxmta_med2_header,
 &sxmta_med2_name,
 &sxmta_med2_loop_start,
 &sxmta_med2_loop_bytes,
 &sxmta_med2_song,
 &sxmta_med2_pattern_header,
 &sxmta_med2_event,
 &sxmta_uni4_header,
 &sxmta_uni5_header,
 &sxmta_uni6_header,
 &sxmta_apun_header,
 &sxmta_uni_bpm_limit,
 &sxmta_uni_sample,
 &sxmta_is1_header,
 &sxmta_is1_sample_info,
 &sxmta_is_sample_bytes,
 &sxmta_is1_instrument,
 &sxmta_is1_subsong,
 &sxmta_is_position,
 &sxmta_is1_event,
 &sxmta_is_unsigned_value,
 &sxmta_is_signed_value,
 &sxmta_is2_header,
 &sxmta_is2_section,
 &sxmta_is2_subsong,
 &sxmta_is2_event,
 &sxmta_is2_sample,
 &sxmta_is2_sample_name,
 &sxmta_is2_sample_copy,
 &sxmta_is2_synth,
 &sxmta_is2_arpeggio,
};
/* Read physical metadata without buffering whole sample or track payloads. */
typedef struct sxmta_view {sx_context*c;unsigned work;}sxmta_view;
static bool sxmta_span(sxmta_view*v,uint64_t at,uint64_t n,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&v->c->size>=0&&end<=(uint64_t)v->c->size&&at<=end&&n<=end-at;}
static bool sxmta_read(sxmta_view*v,uint64_t at,void*p,size_t n,uint64_t end)
{return ++v->work<=4000000&&sxmta_span(v,at,n,end)&&sx_read(v->c,(int64_t)at,p,n);}
static bool sxmta_word(sxmta_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!n||n>8||!sxmta_read(v,at,b,n,end))return false;uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[be?n-i-1:i]<<(8*i);*out=x;return true;}
static bool sxmta_row(sxmta_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxmta_span(v,at,z,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)z);}
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
static bool sxmta_table(sxmta_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>4000000||count>UINT64_MAX/z||!sxmta_span(v,at,count*z,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++,at+=z)if(!sxmta_row(v,l,at,end))return false;return true;}
static int sxmta_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxmta_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxmta_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxmta_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxmta_u(sxmta_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxmta_word(v,p,n,false,x,end);}
static bool sxmta_be(sxmta_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxmta_word(v,p,n,true,x,end);}
static bool sxmta_eq(sxmta_view*v,uint64_t p,const char*s,size_t n,uint64_t end){uint8_t b[64];return n<=sizeof(b)&&sxmta_read(v,p,b,n,end)&&!xx_rt_memcmp(b,s,n);}
static bool sxmta_text_emit(sxmta_view*v,uint64_t p,uint64_t n,uint64_t end){if(!sxmta_span(v,p,n,end))return false;return !n||n>4096||v->c->count>=24000||sx_add(v->c,&sxmta_text,(int64_t)p,(int64_t)n);}
static bool sxmta_pascal(sxmta_view*v,uint64_t*p,uint64_t end){uint64_t n;if(!sxmta_u(v,*p,1,&n,end)||!MTA_ROW(pascal_text_length,*p,end))return false;(*p)++;if(!sxmta_text_emit(v,*p,n,end))return false;*p+=n;return true;}
static bool sxmta_take(sxmta_view*v,const sx_layout*l,uint64_t*p,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!sxmta_table(v,l,*p,count,end))return false;*p+=count*z;return true;}
static bool sxmta_skip(sxmta_view*v,uint64_t*p,uint64_t n,uint64_t end)
{if(!sxmta_span(v,*p,n,end))return false;*p+=n;return true;}
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))

static bool sxmta_gtk(sxmta_view*v)
{uint64_t end=v->c->size,p=206,ver,ns,rows,ch,orders,x,np=0,total=0;const sx_layout*sl;
 if(!sxmta_eq(v,0,"GTK",3,end)||!sxmta_u(v,3,1,&ver,end)||ver<1||ver>4||!sxmta_be(v,196,2,&ns,end)||ns>255||!sxmta_be(v,198,2,&rows,end)||!rows||rows>256||!sxmta_be(v,200,2,&ch,end)||!ch||ch>32||!sxmta_be(v,202,2,&orders,end)||orders>256||!MTA_ROW(gtk_header,0,end))return false;
 sl=ver==1?&sxmta_gtk_sample1:ver==2?&sxmta_gtk_sample2:&sxmta_gtk_sample3;
 for(uint64_t i=0;i<ns;i++){if(!sxmta_be(v,p+(ver<3?32:48),4,&x,end)||x>UINT64_MAX-total||!sxmta_take(v,sl,&p,1,end))return false;total+=x;}
 for(uint64_t i=0;i<orders;i++){if(!sxmta_be(v,p+i*2,2,&x,end)||x>=256)return false;if(x>=np)np=x+1;}
 if(!MTA_TAKE(order16be,&p,256,end)||!sxmta_take(v,ver==4?&sxmta_gtk_event5:&sxmta_gtk_event4,&p,np*rows*ch,end))return false;return sxmta_span(v,p,total,end);}
static bool sxmta_gt2(sxmta_view*v)
{uint64_t end=v->c->size,p,n,ver,x,y,z,ce,at;uint8_t tag[4];
 if(!sxmta_eq(v,0,"GT2",3,end)||!sxmta_u(v,3,1,&ver,end)||ver>9||!sxmta_be(v,4,4,&p,end)||!sxmta_span(v,0,p,end))return false;
 if(ver<=5){if(p<236||!MTA_ROW(gt2_header_old,0,end)||!sxmta_be(v,234,2,&n,end)||!sxmta_table(v,&sxmta_pan16be,236,n,p))return false;}else if(p<228||!MTA_ROW(gt2_header_new,0,end))return false;
 while(p<end){if(!sxmta_read(v,p,tag,4,end)||!sxmta_be(v,p+4,4,&n,end)||n<8||!sxmta_span(v,p,n,end)||!MTA_ROW(gt2_chunk,p,end))return false;ce=p+n;at=p;p+=8;
  if(!xx_rt_memcmp(tag,"PATS",4)){if(!MTA_ROW(count16be,p,ce))return false;}
  else if(!xx_rt_memcmp(tag,"SONG",4)){if(!sxmta_be(v,p,2,&x,ce)||!MTA_TAKE(gt2_song,&p,1,ce)||!MTA_TAKE(order16be,&p,x,ce))return false;}
  else if(!xx_rt_memcmp(tag,"PATD",4)){if(!sxmta_be(v,p+18,2,&x,ce)||!sxmta_be(v,p+20,2,&y,ce)||!sxmta_be(v,p+22,2,&z,ce)||!MTA_TAKE(gt2_pattern,&p,1,ce))return false;if(x<=1&&!MTA_TAKE(gtk_event5,&p,y*z,ce))return false;}
  else if(!xx_rt_memcmp(tag,"TNAM",4)||!xx_rt_memcmp(tag,"TVOL",4)){if(!sxmta_be(v,p,2,&x,ce)||!MTA_TAKE(count16be,&p,1,ce)||!sxmta_take(v,tag[1]=='N'?&sxmta_gt2_track_name:&sxmta_gt2_volume,&p,x,ce))return false;}
  else if(!xx_rt_memcmp(tag,"TCN2",4)){if(!sxmta_be(v,p,2,&x,ce)||!MTA_TAKE(gt2_timing,&p,1,ce)||(x&&!MTA_TAKE(gt2_period_mode,&p,1,ce)))return false;}
  else if(!xx_rt_memcmp(tag,"INST",4)){if(!MTA_TAKE(gt2_instrument,&p,1,ce)||!MTA_TAKE(gt2_note_map,&p,128,ce))return false;}
  else if(!xx_rt_memcmp(tag,"SAMP",4)){if(!MTA_ROW(gt2_sample1,p,ce))return false;}
  else if(!xx_rt_memcmp(tag,"SAM2",4)){uint64_t kind,bits,channels,frames,pcm=0;
   if(!sxmta_be(v,p+30,2,&kind,ce)||!sxmta_be(v,p+32,2,&bits,ce)||!sxmta_be(v,p+36,2,&channels,ce)||!sxmta_be(v,p+48,2,&x,ce)||!sxmta_be(v,p+50,2,&y,ce)||!sxmta_be(v,p+58,4,&frames,ce)||!sxmta_be(v,p+74,4,&z,ce)||!MTA_TAKE(gt2_sample2,&p,1,ce))return false;
   /* The filename follows any in-memory PCM at chunk-relative dataOffset.
    * Unknown encodings remain raw rather than inventing a text coordinate. */
   if(kind<=1&&x<=1&&(bits==8||bits==16)&&(channels==1||channels==2)){
    if(kind==0)pcm=frames*channels*(bits/8);
    if(z<86||!sxmta_span(v,at,z,ce)||!sxmta_span(v,at+z,pcm,ce)||!sxmta_text_emit(v,at+z+pcm,y,ce))return false;
   }
  }
  p=ce;if(!xx_rt_memcmp(tag,"ENDC",4))return true;
 }return true;}
static bool sxmta_tcb(sxmta_view*v)
{uint64_t end=v->c->size,p=144,np,x,base,n;
 if(!sxmta_eq(v,0,"AN COOL",7,end)||!sxmta_u(v,7,1,&x,end)||(x!='!'&&x!='.')||!sxmta_be(v,8,4,&np,end)||np>127||!MTA_ROW(tcb_header,0,end))return false;
 if(x=='.'&&!MTA_TAKE(tcb_amiga_flag,&p,1,end))return false;
 if(!MTA_TAKE(tcb_instrument_name,&p,16,end)||(x=='.'&&!MTA_TAKE(tcb_special,&p,16,end))||!MTA_TAKE(tcb_event,&p,np*256,end))return false;base=p;
 if(!sxmta_be(v,p,4,&n,end)||!sxmta_span(v,p,n,end)||!MTA_TAKE(tcb_sample_area,&p,1,end)||!MTA_TAKE(tcb_sample_properties,&p,16,end))return false;
 for(unsigned i=0;i<16;i++){uint64_t len;if(!sxmta_be(v,p,4,&x,end)||!sxmta_be(v,p+4,4,&len,end)||!MTA_TAKE(tcb_sample_location,&p,1,end))return false;if(len>1&&(!sxmta_span(v,base,x,end)||!sxmta_span(v,base+x,len,end)))return false;}
 return true;}
static bool sxmta_gmc(sxmta_view*v)
{uint64_t end=v->c->size,p=0,total=0,x,orders,np=1;
 for(unsigned i=0;i<15;i++){if(!sxmta_be(v,p+4,2,&x,end)||!MTA_TAKE(gmc_sample,&p,1,end))return false;total+=2*x;}
 if(!sxmta_u(v,p+3,1,&orders,end)||!orders||orders>100||!MTA_TAKE(gmc_orders,&p,1,end))return false;
 for(uint64_t i=0;i<orders;i++){if(!sxmta_be(v,p+2*i,2,&x,end)||x%1024)return false;x/=1024;if(x!=63&&x>=np)np=x+1;}
 if(np>64||!MTA_TAKE(gmc_pattern_offset,&p,100,end)||!MTA_TAKE(gmc_event,&p,np*256,end))return false;return sxmta_span(v,p,total,end);}
static bool sxmta_kris(sxmta_view*v)
{uint64_t end=v->c->size,p=22,x,y,total=0,waves=0,orders,np=1;
 if(!MTA_ROW(kris_title,0,end))return false;
 for(unsigned i=0;i<31;i++){if(!sxmta_u(v,p,1,&x,end))return false;if(x){if(!sxmta_be(v,p+22,2,&x,end)||!MTA_TAKE(kris_sample,&p,1,end))return false;total+=2*x;}else{unsigned a[4]={1,5,10,19};for(unsigned j=0;j<4;j++){if(!sxmta_u(v,p+a[j],1,&x,end))return false;if(x&&x>=waves)waves=x+1;}if(!MTA_TAKE(kris_synth,&p,1,end))return false;}}
 if(!sxmta_eq(v,p,"KRIS",4,end)||!sxmta_u(v,p+4,1,&orders,end)||orders>128||!MTA_TAKE(kris_header,&p,1,end))return false;
 for(uint64_t i=0;i<orders*4;i++){if(!sxmta_u(v,p+2*i,1,&x,end))return false;if(x>=np)np=x+1;}
 if(!MTA_TAKE(kris_track_ref,&p,512,end)||!sxmta_skip(v,&p,2+waves*64,end)||!MTA_TAKE(kris_event,&p,np*64,end))return false;y=total;return sxmta_span(v,p,y,end);}
static bool sxmta_c67(sxmta_view*v)
{uint64_t end=v->c->size,p=0,x,n,total=0,max=2978;
 if(!MTA_TAKE(c67_header,&p,1,end)||!MTA_TAKE(c67_name,&p,32,end))return false;
 for(unsigned i=0;i<32;i++){if(!sxmta_u(v,p+4,4,&x,end)||!MTA_TAKE(c67_sample,&p,1,end))return false;total+=x;}
 if(!MTA_TAKE(c67_name,&p,32,end)||!MTA_TAKE(c67_fm_instrument,&p,32,end)||!MTA_TAKE(order8,&p,256,end)||!MTA_TAKE(c67_pattern_offset,&p,128,end)||!MTA_TAKE(c67_pattern_bytes,&p,128,end))return false;
 for(unsigned i=0;i<128;i++){if(!sxmta_u(v,1954+i*4,4,&x,end)||!sxmta_u(v,2466+i*4,4,&n,end)||!sxmta_span(v,2978+x,n,end))return false;if(2978+x+n>max)max=2978+x+n;}
 return sxmta_span(v,max,total,end);}
static bool sxmta_dsym(sxmta_view*v)
{uint64_t end=v->c->size,p=17,orders,tracks,ch,x,len[63],flags[63];
 if(!sxmta_eq(v,0,"\x02\x01\x13\x13\x14\x12\x01\x0b",8,end)||!sxmta_u(v,9,1,&ch,end)||!ch||ch>8||!sxmta_u(v,10,2,&orders,end)||!sxmta_u(v,12,2,&tracks,end)||!MTA_ROW(dsym_header,0,end))return false;
 for(unsigned i=0;i<63;i++){if(!sxmta_u(v,p,1,&flags[i],end)||!MTA_TAKE(dsym_sample_flags,&p,1,end))return false;len[i]=0;if(!(flags[i]&128)){if(!sxmta_u(v,p,3,&len[i],end)||!MTA_TAKE(dsym_sample_words,&p,1,end))return false;len[i]*=2;}}
 if(!sxmta_pascal(v,&p,end)||!MTA_TAKE(dsym_commands,&p,1,end))return false;
 if(orders){if(!sxmta_u(v,p,1,&x,end)||!MTA_TAKE(dsym_packing,&p,1,end))return false;if(x)return true;if(!MTA_TAKE(order16le,&p,orders*ch,end))return false;}
 for(uint64_t i=0;i<tracks;){uint64_t n=tracks-i;if(n>2000)n=2000;if(!sxmta_u(v,p,1,&x,end)||!MTA_TAKE(dsym_packing,&p,1,end))return false;if(x)return true;if(!MTA_TAKE(dsym_event,&p,n*64,end))return false;i+=n;}
 for(unsigned i=0;i<63;i++){x=flags[i]&63;if(!sxmta_text_emit(v,p,x,end))return false;p+=x;if(flags[i]&128)continue;if(!MTA_TAKE(dsym_sample,&p,1,end))return false;if(len[i]){if(!sxmta_u(v,p,1,&x,end)||!MTA_TAKE(dsym_packing,&p,1,end))return false;if(x)return true;if(!sxmta_skip(v,&p,len[i],end))return false;}}
 return true;}
static bool sxmta_sym(sxmta_view*v)
{uint64_t end=v->c->size,p=8,id,n;
 if(!sxmta_eq(v,0,"SymM",4,end)||!MTA_ROW(sym_header,0,end))return false;
 while(p<end){if(!sxmta_be(v,p,4,&id,end))return false;int64_t k=id<=INT32_MAX?(int64_t)id:(int64_t)id-INT64_C(4294967296);
  if(k==-12){if(!MTA_TAKE(sym_empty_sample,&p,1,end))return false;continue;}
  if(k>=-21&&k<=-10){if(!sxmta_be(v,p+4,4,&n,end)||!MTA_TAKE(sym_bytes,&p,1,end)||!sxmta_skip(v,&p,n,end))return false;}
  else if((k>=-7&&k<=-1)||(k>=10&&k<=12)){if(!sxmta_take(v,k==-1||k==-2||k==-4?&sxmta_sym_count:&sxmta_sym_value,&p,1,end))return false;}
  else return true;
 }return true;}

static bool sxmta_aon(sxmta_view*v)
{uint64_t end=v->c->size,p=46,n,ce,x,ch;uint8_t tag[4];
 if((!sxmta_eq(v,0,"AON4",4,end)&&!sxmta_eq(v,0,"AON8",4,end))||!sxmta_u(v,3,1,&ch,end)||!MTA_ROW(aon_header,0,end))return false;ch-='0';
 while(p<end){if(!sxmta_u(v,p,1,&x,end))return false;if(x=='?')return true;
  if(!sxmta_read(v,p,tag,4,end)||!sxmta_be(v,p+4,4,&n,end)||n>INT32_MAX||!sxmta_span(v,p+8,n,end)||!MTA_ROW(aon_chunk,p,end))return false;p+=8;ce=p+n;
  if(!xx_rt_memcmp(tag,"NAME",4)||!xx_rt_memcmp(tag,"AUTH",4)||!xx_rt_memcmp(tag,"RMRK",4)){if(!sxmta_text_emit(v,p,n,ce))return false;}
  else if(!xx_rt_memcmp(tag,"INFO",4)){if(!MTA_ROW(aon_info,p,ce))return false;}
  else if(!xx_rt_memcmp(tag,"ARPG",4)){if(!MTA_TAKE(aon_arpeggio,&p,16,ce))return false;}
  else if(!xx_rt_memcmp(tag,"PLST",4)){if(!MTA_TAKE(order8,&p,n,ce))return false;}
  else if(!xx_rt_memcmp(tag,"PATT",4)){if(n%(ch*64*4)||!MTA_TAKE(aon_event,&p,n/4,ce))return false;}
  else if(!xx_rt_memcmp(tag,"INST",4)){if(n%32)return false;while(p<ce){if(!sxmta_u(v,p,1,&x,ce)||(x>1?!sxmta_skip(v,&p,32,ce):!sxmta_take(v,x?&sxmta_aon_synth:&sxmta_aon_sample,&p,1,ce)))return false;}}
  else if(!xx_rt_memcmp(tag,"INAM",4)){if(n%32||!MTA_TAKE(aon_instrument_name,&p,n/32,ce))return false;}
  else if(!xx_rt_memcmp(tag,"WLEN",4)){if(n%4||!MTA_TAKE(aon_wave_length,&p,n/4,ce))return false;}
  p=ce;
 }return true;}
static bool sxmta_dmu(sxmta_view*v)
{uint64_t end=v->c->size,p=76,ni,nw,ns,nt,n,x,seq=0,arp,total;
 if((!sxmta_eq(v,0," MUGICIAN/SOFTEYES 1990 ",23,end)&&!sxmta_eq(v,0," MUGICIAN2/SOFTEYES 1990",23,end))||!MTA_ROW(dmu_header,0,end)||!sxmta_be(v,24,2,&arp,end)||!sxmta_be(v,26,2,&nt,end)||!sxmta_be(v,60,4,&ni,end)||!sxmta_be(v,64,4,&nw,end)||!sxmta_be(v,68,4,&ns,end)||!sxmta_be(v,72,4,&total,end))return false;
 for(unsigned i=0;i<8;i++){if(!sxmta_be(v,28+i*4,4,&x,end))return false;seq+=x;}
 if(!MTA_TAKE(dmu_subsong,&p,8,end)||!MTA_TAKE(dmu_sequence,&p,seq*4,end)||!MTA_TAKE(dmu_instrument,&p,ni,end)||!sxmta_skip(v,&p,nw*128,end))return false;n=p;
 if(!MTA_TAKE(dmu_sample,&p,ns,end)||!MTA_TAKE(dmu_event,&p,nt*64,end))return false;
 for(uint64_t i=0;i<ns;i++){uint64_t a,b;if(!sxmta_be(v,n+i*32,4,&a,end)||!sxmta_be(v,n+i*32+4,4,&b,end)||a>b||b>total)return false;}
 if(!sxmta_skip(v,&p,total,end)||(arp&&!MTA_TAKE(is_unsigned_value,&p,256,end)))return false;return true;}
static bool sxmta_jam(sxmta_view*v)
{uint64_t end=v->c->size,p=6,ns,np,no,x,events=0,total=0;
 if(!sxmta_eq(v,0,"BeEp",4,end)||!sxmta_be(v,4,2,&ns,end)||ns>256||!MTA_ROW(jam_header,0,end))return false;
 for(uint64_t i=0;i<ns;i++){if(!sxmta_be(v,p+32,4,&x,end)||!MTA_TAKE(jam_sample,&p,1,end))return false;total+=x;}
 if(!sxmta_be(v,p,2,&np,end)||!MTA_TAKE(count16be,&p,1,end))return false;
 for(uint64_t i=0;i<np;i++){if(!sxmta_be(v,p,2,&x,end)||!MTA_TAKE(jam_pattern,&p,1,end))return false;events+=x*4;}
 if(!sxmta_be(v,p,2,&no,end)||!MTA_TAKE(count16be,&p,1,end)||!MTA_TAKE(order16be,&p,no,end)||!MTA_TAKE(jam_event,&p,events,end))return false;return sxmta_span(v,p,total,end);}
static bool sxmta_bp(sxmta_view*v)
{uint64_t end=v->c->size,p=32,ver,waves,orders,x,total=0,tracks=0;
 if(!sxmta_eq(v,26,"V.",2,end)||!sxmta_u(v,28,1,&ver,end)||(ver!='2'&&ver!='3')||!sxmta_u(v,29,1,&waves,end)||!sxmta_be(v,30,2,&orders,end)||!MTA_ROW(bp_header,0,end))return false;
 for(unsigned i=0;i<15;i++){if(!sxmta_u(v,p,1,&x,end))return false;if(x==255){if(!sxmta_take(v,ver=='2'?&sxmta_bp_synth1:&sxmta_bp_synth2,&p,1,end))return false;}else{if(!sxmta_be(v,p+24,2,&x,end)||!MTA_TAKE(bp_sample,&p,1,end))return false;total+=2*x;}}
 for(uint64_t i=0;i<orders*4;i++){if(!sxmta_be(v,p,2,&x,end)||!MTA_TAKE(bp_step,&p,1,end))return false;if(x>tracks)tracks=x;}
 if(!MTA_TAKE(bp_event,&p,tracks*16,end)||!sxmta_skip(v,&p,waves*64,end))return false;return sxmta_span(v,p,total,end);}
static bool sxmta_fuchs(sxmta_view*v)
{uint64_t end=v->c->size,p=0,n,total;
 if(!sxmta_be(v,10,4,&total,end)||!MTA_TAKE(fuchs_header,&p,1,end)||!MTA_TAKE(fuchs_sample_bytes,&p,16,end)||!MTA_TAKE(fuchs_volume,&p,16,end)||!MTA_TAKE(fuchs_loop,&p,16,end)||!MTA_TAKE(fuchs_order_count,&p,1,end)||!MTA_TAKE(order16be,&p,40,end)||!sxmta_eq(v,p,"SONG",4,end)||!sxmta_be(v,p+4,4,&n,end)||n%1024||!MTA_TAKE(fuchs_pattern_chunk,&p,1,end)||!MTA_TAKE(fuchs_event,&p,n/4,end)||!sxmta_eq(v,p,"INST",4,end)||!MTA_TAKE(fuchs_samples_marker,&p,1,end))return false;return sxmta_span(v,p,total,end);}
static bool sxmta_sid2(sxmta_view*v)
{uint64_t end=v->c->size,p=58,x,n,ns,total=0;uint64_t lengths[10];
 if(!sxmta_eq(v,58,"SIDMON II - THE MIDI VERSION",27,end)||!sxmta_be(v,4,2,&ns,end)||ns%64||!MTA_ROW(sid2_header,0,end)||!sxmta_be(v,6,4,&x,end)||!sxmta_skip(v,&p,x,end)||!sxmta_be(v,10,4,&x,end)||!sxmta_skip(v,&p,x,end)||p<86)return false;
 for(unsigned i=0;i<10;i++)if(!sxmta_be(v,14+4*i,4,&lengths[i],end))return false;
 for(unsigned i=0;i<10;i++){n=lengths[i];if(!sxmta_span(v,p,n,end))return false;
  if(i==0){if(!sxmta_table(v,&sxmta_sid2_track_number,p,n,p+n))return false;}
  else if(i==1||i==2){if(!sxmta_table(v,&sxmta_sid2_transpose,p,n,p+n))return false;}
  else if(i==3){if(n%32||!sxmta_table(v,&sxmta_sid2_instrument,p,n/32,p+n))return false;}
  else if(i==7){if(n!=ns||n%64||!sxmta_table(v,&sxmta_sid2_sample,p,n/64,p+n))return false;for(uint64_t j=0;j<n;j+=64){if(!sxmta_be(v,p+j+4,2,&x,end))return false;total+=x*2;}}
  else if(i==8){if(n%2||!sxmta_table(v,&sxmta_sid2_track_offset,p,n/2,p+n))return false;for(uint64_t j=0;j<n;j+=2){if(!sxmta_be(v,p+j,2,&x,end)||x>lengths[9])return false;}}
  p+=n;
 }
 if(p&1){if(!sxmta_skip(v,&p,1,end))return false;}return sxmta_span(v,p,total,end);}
static bool sxmta_med2(sxmta_view*v)
{uint64_t end=v->c->size,p=4,n;
 if(!sxmta_eq(v,0,"MED\x02",4,end)||!MTA_ROW(med2_header,0,end)||!MTA_TAKE(med2_name,&p,32,end)||!MTA_TAKE(volume8,&p,32,end)||!MTA_TAKE(med2_loop_start,&p,32,end)||!MTA_TAKE(med2_loop_bytes,&p,32,end)||!sxmta_be(v,p,2,&n,end)||n>256||!MTA_TAKE(count16be,&p,1,end)||!MTA_TAKE(order8,&p,100,end)||!MTA_TAKE(med2_song,&p,1,end))return false;
 for(uint64_t i=0;i<n;i++)if(!MTA_TAKE(med2_pattern_header,&p,1,end)||!MTA_TAKE(med2_event,&p,256,end))return false;return true;}
static bool sxmta_uni_string(sxmta_view*v,uint64_t*p,uint64_t end)
{uint64_t n;if(!sxmta_u(v,*p,2,&n,end)||!MTA_TAKE(text_length16,p,1,end)||!sxmta_text_emit(v,*p,n,end))return false;*p+=n;return true;}
static bool sxmta_uni(sxmta_view*v)
{uint64_t end=v->c->size,p=0,ver,ch,orders,ns=0;
 if(sxmta_eq(v,0,"APUN",4,end)){if(!sxmta_be(v,4,2,&ver,end)||ver<0x101||ver>0x106||!sxmta_u(v,8,1,&ch,end)||!sxmta_be(v,10,2,&orders,end)||!sxmta_be(v,18,2,&ns,end)||!MTA_TAKE(apun_header,&p,1,end))return false;if(ver>=0x106&&!MTA_TAKE(uni_bpm_limit,&p,1,end))return false;}
 else{if(!sxmta_eq(v,0,"UN0",3,end)||!sxmta_u(v,3,1,&ver,end)||ver<'4'||ver>'6')return false;ver-='0';if(ver==6){if(!sxmta_u(v,7,1,&ch,end)||!sxmta_be(v,9,2,&orders,end)||!sxmta_be(v,17,2,&ns,end)||!MTA_TAKE(uni6_header,&p,1,end))return false;}else if(!sxmta_take(v,ver==4?&sxmta_uni4_header:&sxmta_uni5_header,&p,1,end))return false;}
 if(!sxmta_uni_string(v,&p,end)||(ver<0x102&&!sxmta_uni_string(v,&p,end))||!sxmta_uni_string(v,&p,end))return false;
 if(ver>=6){if(ch>64||!sxmta_take(v,ver>=0x100?&sxmta_order16be:&sxmta_order8,&p,orders,end)||!MTA_TAKE(pan16be,&p,ch,end)||!MTA_TAKE(volume8,&p,ch,end))return false;for(uint64_t i=0;i<ns;i++)if(!MTA_TAKE(uni_sample,&p,1,end)||!sxmta_uni_string(v,&p,end))return false;}
 /* Instrument envelopes, bytecode tracks and PCM bodies are not decoded here. */
 return true;}

static bool sxmta_is1(sxmta_view*v)
{uint64_t end=v->c->size,p=204,np,nr,ns,nw,ni,nsub,neg,nad,x,total=0;
 if(!sxmta_eq(v,0,"ISM!V1.2",8,end)||!MTA_ROW(is1_header,0,end)||!sxmta_be(v,8,2,&np,end)||!sxmta_be(v,10,2,&nr,end)||!sxmta_u(v,16,1,&ns,end)||!sxmta_u(v,17,1,&nw,end)||!sxmta_u(v,18,1,&ni,end)||!sxmta_u(v,19,1,&nsub,end)||!sxmta_u(v,20,1,&neg,end)||!sxmta_u(v,21,1,&nad,end)||!MTA_TAKE(is1_sample_info,&p,ns,end))return false;
 for(uint64_t i=0;i<ns;i++){if(!sxmta_be(v,p,4,&x,end)||!MTA_TAKE(is_sample_bytes,&p,1,end))return false;total+=x;}
 if(!MTA_TAKE(is_unsigned_value,&p,neg*128+nad*256,end)||!MTA_TAKE(is1_instrument,&p,ni,end)||!MTA_TAKE(is_unsigned_value,&p,256,end)||!MTA_TAKE(is1_subsong,&p,nsub,end)||!sxmta_skip(v,&p,14,end)||!sxmta_skip(v,&p,nw*256,end)||!MTA_TAKE(is_position,&p,np*4,end)||!MTA_TAKE(is1_event,&p,nr+64,end))return false;return sxmta_span(v,p,total,end);}
static bool sxmta_is2_read_section(sxmta_view*v,uint64_t*p,const char*name,uint64_t*n,uint64_t end)
{return sxmta_eq(v,*p,name,4,end)&&sxmta_be(v,*p+4,4,n,end)&&MTA_TAKE(is2_section,p,1,end);}
static bool sxmta_is2(sxmta_view*v)
{uint64_t end=v->c->size,p=8,n,ns,x,total=0;
 if(!sxmta_eq(v,0,"IS20DF10",8,end)||!MTA_ROW(is2_header,0,end)||!sxmta_is2_read_section(v,&p,"STBL",&n,end)||!MTA_TAKE(is2_subsong,&p,n,end)||!sxmta_is2_read_section(v,&p,"OVTB",&n,end)||!MTA_TAKE(is_position,&p,n*4,end)||!sxmta_is2_read_section(v,&p,"NTBL",&n,end)||!MTA_TAKE(is2_event,&p,n,end)||!sxmta_is2_read_section(v,&p,"SAMP",&ns,end)||!MTA_TAKE(is2_sample,&p,ns,end)||!MTA_TAKE(is2_sample_name,&p,ns,end)||!MTA_TAKE(is2_sample_copy,&p,ns,end))return false;
 for(uint64_t i=0;i<ns;i++){if(!sxmta_be(v,p,4,&x,end)||!MTA_TAKE(is_sample_bytes,&p,1,end))return false;total+=x;}
 if(!sxmta_skip(v,&p,total,end)||!sxmta_is2_read_section(v,&p,"SYNT",&n,end)||n>4000000||!sxmta_span(v,p,n*1010,end))return false;
 for(uint64_t i=0;i<n;i++){if(!sxmta_eq(v,p,"IS20",4,end)||!MTA_TAKE(is2_synth,&p,1,end)||!MTA_TAKE(is_unsigned_value,&p,128,end)||!MTA_TAKE(is_signed_value,&p,128,end)||!MTA_TAKE(is2_arpeggio,&p,3,end)||!MTA_TAKE(is_unsigned_value,&p,128,end)||!sxmta_skip(v,&p,512,end))return false;}
 return true;}

static bool sxmta_galaxy_chunks(sxmta_view*v,uint64_t p,uint64_t end,bool modern,unsigned depth)
{if(depth>4)return false;uint64_t n,ce,x,at;uint8_t tag[4];
 while(p<end){if(!sxmta_read(v,p,tag,4,end)||!sxmta_u(v,p+4,4,&n,end)||!sxmta_span(v,p+8,n,end))return false;at=p;ce=p+8+n;
  if(!xx_rt_memcmp(tag,"RIFF",4)){if(n<4||!MTA_ROW(riff_header,p,ce))return false;
   if(sxmta_eq(v,p+8,"AI  ",4,ce)||sxmta_eq(v,p+8,"AS  ",4,ce)){if(!sxmta_galaxy_chunks(v,p+12,ce,true,depth+1))return false;}
  }else{if(!MTA_ROW(chunk_le,p,ce))return false;p+=8;
   if(!xx_rt_memcmp(tag,"MAIN",4)||!xx_rt_memcmp(tag,"INIT",4)){if(!sxmta_u(v,p+65,1,&x,ce)||!x||x>64||!MTA_TAKE(galaxy_main,&p,1,ce)||!MTA_TAKE(volume8,&p,x,ce))return false;}
   else if(!xx_rt_memcmp(tag,"ORDR",4)){if(!sxmta_u(v,p,1,&x,ce)||!MTA_TAKE(galaxy_order_count,&p,1,ce)||!MTA_TAKE(order8,&p,x+1,ce))return false;}
   else if(!xx_rt_memcmp(tag,"PATT",4)){if(!sxmta_u(v,p+1,4,&x,ce)||!MTA_ROW(galaxy_pattern,p,ce)||!sxmta_span(v,p+5,x,ce))return false;}
   else if(!xx_rt_memcmp(tag,"INST",4)){
    if(modern){if(!MTA_TAKE(galaxy_instrument5,&p,1,ce))return false;for(unsigned j=0;j<3;j++)if(!MTA_TAKE(galaxy_envelope5,&p,1,ce)||!sxmta_take(v,j?&sxmta_galaxy_point5_signed:&sxmta_galaxy_point5,&p,10,ce)||!MTA_TAKE(galaxy_fadeout,&p,1,ce))return false;if(!MTA_TAKE(galaxy_sample_count,&p,1,ce))return false;}
    else{if(!sxmta_u(v,p+30,1,&x,ce)||!MTA_TAKE(galaxy_instrument4,&p,1,ce)||!MTA_TAKE(galaxy_envelope4,&p,1,ce)||!MTA_TAKE(galaxy_point4,&p,20,ce)||!MTA_TAKE(galaxy_fadeout,&p,1,ce))return false;
     for(uint64_t j=0;j<x;j++){uint64_t b;if(!sxmta_eq(v,p,"SAMP",4,ce)||!sxmta_u(v,p+4,4,&b,ce)||!sxmta_span(v,p+8,b,ce)||!MTA_ROW(chunk_le,p,ce)||!MTA_ROW(galaxy_sample4,p+8,p+8+b))return false;p+=8+b;}
    }
   }else if(!xx_rt_memcmp(tag,"SAMP",4)&&modern){if(!MTA_ROW(galaxy_sample5,p,ce))return false;}
  }
  p=ce;if(modern&&(n&1)){if(!sxmta_skip(v,&p,1,end))return false;}if(p<=at)return false;
 }return true;}
static bool sxmta_galaxy(sxmta_view*v,bool packed)
{uint64_t end=v->c->size,n,x;
 if(packed){if(!sxmta_eq(v,0,"MUSE",4,end)||!sxmta_u(v,8,4,&n,end)||!sxmta_u(v,16,4,&x,end)||n!=end||x!=end-24||!MTA_ROW(muse_header,0,end))return false;return true;}
 if(!sxmta_eq(v,0,"RIFF",4,end)||!sxmta_u(v,4,4,&n,end)||n<4||!sxmta_span(v,8,n,end)||!MTA_ROW(riff_header,0,end))return false;
 bool modern=sxmta_eq(v,8,"AM  ",4,end);if(!modern&&!sxmta_eq(v,8,"AMFF",4,end))return false;return sxmta_galaxy_chunks(v,12,n+8,modern,0);}

static bool sx_musictail_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_DIE_MUSIC_TWICE_ARTOFNOISE:
case XX_FILE_TYPE_DIE_MUSIC_RHINO_DIGITALMUGICIAN:
case XX_FILE_TYPE_DIE_MUSIC_DUMBO_GRAOUMFTRACKER:
case XX_FILE_TYPE_DIE_MUSIC_DUMBO_GRAOUMFTRACKER2:
case XX_FILE_TYPE_DIE_MUSIC_JAZZJR2_GSS_UNP:
case XX_FILE_TYPE_DIE_MUSIC_JAZZJR2_GSS_CO:
case XX_FILE_TYPE_DIE_MUSIC_MENG_SYMPHONIE_SYMMOD:
case XX_FILE_TYPE_DIE_MUSIC_OREGANDEV_DIGITALSYMPHONY:
case XX_FILE_TYPE_DIE_MUSIC_BETRAYAL_JAMCRACKER:
case XX_FILE_TYPE_DIE_MUSIC_POSTMA_SOUNDMON_BP:
case XX_FILE_TYPE_DIE_MUSIC_ANCOOL_TCBTRACKER:
case XX_FILE_TYPE_DIE_MUSIC_TRAN_CDFM_COMPOSER670:
case XX_FILE_TYPE_DIE_MUSIC_CHRONS_UNIMODTRK:
case XX_FILE_TYPE_DIE_MUSIC_BERGSTEDT_SIMS_INSTEREO1:
case XX_FILE_TYPE_DIE_MUSIC_BERGSTEDT_SIMS_INSTEREO2:
case XX_FILE_TYPE_DIE_MUSIC_KINNUNEN_OCTAMED_MED:
case XX_FILE_TYPE_DIE_MUSIC_FUCHS_TRACKER:
case XX_FILE_TYPE_DIE_MUSIC_TADIC_GAMEMUSICCREATOR:
case XX_FILE_TYPE_DIE_MUSIC_WOMBELL_CHIPTRACKER_KRIS:
case XX_FILE_TYPE_DIE_MUSIC_KLEPS_SIDMON2:
return true;default:return false;}}
static bool sx_musictail_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxmta_view view={c,0},*v=&view;bool ok=false;
 switch(c->f->file_type){
case XX_FILE_TYPE_DIE_MUSIC_TWICE_ARTOFNOISE:ok=sxmta_aon(v);break;
case XX_FILE_TYPE_DIE_MUSIC_RHINO_DIGITALMUGICIAN:ok=sxmta_dmu(v);break;
case XX_FILE_TYPE_DIE_MUSIC_DUMBO_GRAOUMFTRACKER:ok=sxmta_gtk(v);break;
case XX_FILE_TYPE_DIE_MUSIC_DUMBO_GRAOUMFTRACKER2:ok=sxmta_gt2(v);break;
case XX_FILE_TYPE_DIE_MUSIC_JAZZJR2_GSS_UNP:ok=sxmta_galaxy(v,false);break;
case XX_FILE_TYPE_DIE_MUSIC_JAZZJR2_GSS_CO:ok=sxmta_galaxy(v,true);break;
case XX_FILE_TYPE_DIE_MUSIC_MENG_SYMPHONIE_SYMMOD:ok=sxmta_sym(v);break;
case XX_FILE_TYPE_DIE_MUSIC_OREGANDEV_DIGITALSYMPHONY:ok=sxmta_dsym(v);break;
case XX_FILE_TYPE_DIE_MUSIC_BETRAYAL_JAMCRACKER:ok=sxmta_jam(v);break;
case XX_FILE_TYPE_DIE_MUSIC_POSTMA_SOUNDMON_BP:ok=sxmta_bp(v);break;
case XX_FILE_TYPE_DIE_MUSIC_ANCOOL_TCBTRACKER:ok=sxmta_tcb(v);break;
case XX_FILE_TYPE_DIE_MUSIC_TRAN_CDFM_COMPOSER670:ok=sxmta_c67(v);break;
case XX_FILE_TYPE_DIE_MUSIC_CHRONS_UNIMODTRK:ok=sxmta_uni(v);break;
case XX_FILE_TYPE_DIE_MUSIC_BERGSTEDT_SIMS_INSTEREO1:ok=sxmta_is1(v);break;
case XX_FILE_TYPE_DIE_MUSIC_BERGSTEDT_SIMS_INSTEREO2:ok=sxmta_is2(v);break;
case XX_FILE_TYPE_DIE_MUSIC_KINNUNEN_OCTAMED_MED:ok=sxmta_med2(v);break;
case XX_FILE_TYPE_DIE_MUSIC_FUCHS_TRACKER:ok=sxmta_fuchs(v);break;
case XX_FILE_TYPE_DIE_MUSIC_TADIC_GAMEMUSICCREATOR:ok=sxmta_gmc(v);break;
case XX_FILE_TYPE_DIE_MUSIC_WOMBELL_CHIPTRACKER_KRIS:ok=sxmta_kris(v);break;
case XX_FILE_TYPE_DIE_MUSIC_KLEPS_SIDMON2:ok=sxmta_sid2(v);break;
default:break;}
 return ok&&sxmta_finish(c);}
#undef MTA_ROW
#undef MTA_TAKE
static bool sx_musictail_comment(xx_data_struct_record*r,uint32_t id)
{if(!r||!r->name||id<UINT32_C(0x60810001)||id>=UINT32_C(0x60820000))return true;const wchar_t*n=r->name,*s=NULL;
#define MTA_IS(l) (id==sxmta_##l.id)
#define MTA_NAME(x) (!xx_rt_wcscmp(n,L##x))
 if(MTA_NAME("sample_words")||MTA_NAME("loop_words")||MTA_NAME("loop_start_words")||MTA_NAME("one_shot_words")||MTA_NAME("repeat_words")||MTA_NAME("waveform_words")||MTA_NAME("negate_start_words")||MTA_NAME("negate_end_words"))s=L"Stored in two-byte words; multiply by 2 for PCM bytes";
 if(MTA_NAME("sample_frames")||MTA_NAME("loop_frames")||MTA_NAME("loop_buffer_frames"))s=L"Sample-frame count, not a byte length";
 if(MTA_NAME("loop_start_frame")||MTA_NAME("loop_end_frame")||MTA_NAME("sustain_start_frame")||MTA_NAME("sustain_end_frame"))s=L"Position in sample frames, not a file byte offset";
 if(MTA_NAME("address_placeholder")||MTA_NAME("sample_address")||MTA_NAME("pattern_address"))s=L"Stored address/pointer value; not a physical file offset";
 if(MTA_IS(gt2_chunk)&&MTA_NAME("chunk_bytes"))s=L"Total chunk bytes including the 8-byte chunk header";
 if(MTA_IS(gt2_sample2)&&MTA_NAME("data_offset"))s=L"Byte offset relative to the enclosing SAM2 chunk header";
 if(MTA_IS(c67_sample)&&MTA_NAME("unknown_zero"))s=L"Unknown zero word; the reference suggests an in-memory address placeholder, but its meaning is unconfirmed";
 if(MTA_IS(c67_pattern_offset))s=L"Byte offset relative to the pattern-data area at file offset 2978";
 if(MTA_IS(gmc_pattern_offset))s=L"Pattern byte offset; divide by 1024 for a pattern index";
 if(MTA_IS(tcb_sample_location)&&MTA_NAME("sample_offset"))s=L"Byte offset relative to the sample-area length word";
 if(MTA_IS(tcb_header)&&MTA_NAME("tempo"))s=L"Encoded timing: playback speed is 16 minus this value";
 if(MTA_IS(dmu_sample)&&(MTA_NAME("start_offset")||MTA_NAME("end_offset")||MTA_NAME("loop_start")))s=L"Byte coordinate relative to the sample-data area; zero loop start means no loop";
 if(MTA_IS(sid2_instrument)&&(MTA_NAME("waveform_list_last_index")||MTA_NAME("arpeggio_last_index")||MTA_NAME("vibrato_last_index")))s=L"Inclusive last table index; a positive value N visits indices 0 through N; zero disables the effect";
 if(MTA_IS(sid2_track_offset))s=L"Byte offset relative to the track-data block";
 if(MTA_IS(is1_header)&&MTA_NAME("track_rows"))s=L"Stored row count; the native player reads 64 additional physical rows";
 if(MTA_IS(is_position)&&MTA_NAME("start_track_row"))s=L"Track-row index, not a byte offset";
 if(MTA_IS(is2_subsong)&&MTA_NAME("frequency_hz"))s=L"Playback frequency in Hz; zero means 50 Hz";
 if(MTA_IS(is2_arpeggio)&&(MTA_NAME("length")||MTA_NAME("repeat")))s=L"Encoded arpeggio loop boundary/control; physical record always has 14 signed note offsets";
 if(MTA_IS(is2_synth)&&(MTA_NAME("start_len")||MTA_NAME("stop_rep")))s=L"Envelope mode-dependent parameters: calculated-mode value limits or free-mode initial/repeat table lengths";
 if(MTA_IS(is2_synth)&&MTA_NAME("eg_mode"))s=L"When enabled: 0 calculated envelope; nonzero free/table envelope";
 if(MTA_IS(is2_sample_copy))s=L"Opaque eight-byte stored sample/loop-length copy; player does not define individual field widths";
 if(MTA_IS(is1_instrument)&&MTA_NAME("repeat_bytes"))s=L"Byte length: zero loops the waveform; 2 disables looping";
 if(MTA_IS(is2_sample)&&MTA_NAME("repeat_words"))s=L"Two-byte words: zero loops the one-shot region; 1 disables looping";
 if(MTA_IS(galaxy_main)&&(MTA_NAME("min_period_16x")||MTA_NAME("max_period_16x")))s=L"Stored period multiplied by 16";
 if(MTA_NAME("tick_16x"))s=L"Envelope tick value stored multiplied by 16";
 if(MTA_IS(galaxy_envelope5)&&MTA_NAME("last_point"))s=L"Last envelope-point index; 255 means no points";
 if(MTA_IS(muse_header)&&MTA_NAME("packed_crc32"))s=L"CRC-32 of the physically stored compressed payload";
 if(MTA_IS(galaxy_sample5)&&MTA_NAME("header_bytes"))s=L"Header byte length, conventionally excluding this four-byte length word";
 if(MTA_IS(galaxy_point5_signed)&&MTA_NAME("value"))s=L"Signed pitch or pan envelope value; units depend on the enclosing envelope";
 if(MTA_IS(sym_value)&&MTA_NAME("value"))s=L"Chunk-specific scalar; event-size hunk uses only the low 16 bits";
 if((MTA_IS(gtk_sample1)||MTA_IS(gtk_sample2)||MTA_IS(gtk_sample3)||MTA_IS(gt2_sample1)||MTA_IS(c67_sample))&&(r->property&SX_OFFSET))s=L"Byte offset within this sample's PCM data, not a file offset";
 if(MTA_IS(aon_sample)&&(r->property&SX_OFFSET))s=L"Byte coordinate within the selected waveform data";
 if(MTA_IS(gmc_sample)&&MTA_NAME("sample_offset"))s=L"Stored sample-data file byte offset";
 if(MTA_IS(fuchs_loop)||(MTA_IS(bp_sample)&&MTA_NAME("loop_start"))||MTA_IS(med2_loop_start))s=L"Byte offset within the sample, not a file offset";
 if(MTA_IS(fuchs_volume))s=L"Physical two-byte volume word; the retained converter uses its low byte";
 if(MTA_IS(gt2_sample2)&&MTA_NAME("sample_endian"))s=L"0 big endian; 1 little endian";
 if(MTA_IS(gt2_sample2)&&MTA_NAME("sample_coding"))s=L"0 PCM in module; 1 PCM in a separate file";
 if(MTA_IS(gt2_sample2)&&MTA_NAME("sample_type"))s=L"0 memory-based; 1 disk-based";
 if(MTA_IS(gt2_sample2)&&MTA_NAME("loop_type"))s=L"0 no loop; 1 forward loop; 2 ping-pong loop";
 if(MTA_IS(gt2_sample1)&&MTA_NAME("flags"))s=L"Bit 0 stereo; bit 1 ping-pong loop";
 if(MTA_IS(gt2_period_mode))s=L"0 linear pitch; nonzero Amiga-period pitch";
 if(MTA_IS(gt2_timing)&&MTA_NAME("tempo_fraction"))s=L"Fractional tempo in units of 1/65536 BPM";
 if(MTA_IS(gt2_pattern)&&MTA_NAME("coding"))s=L"0: volume is scaled by 4; 1: volume is biased by 16; both use five-byte cells";
 if(MTA_IS(dsym_packing))s=L"Zero selects stored bytes; nonzero selects compressed or alternate coding; those bodies remain raw";
 if(MTA_IS(dsym_sample_flags))s=L"Bit 7: absent sample; low six bits: following sample-name byte count";
 if(MTA_IS(aon_sample)&&MTA_NAME("instrument_type"))s=L"0 sampled instrument";
 if(MTA_IS(aon_synth)&&MTA_NAME("instrument_type"))s=L"1 synthesized instrument";
 if(MTA_IS(kris_track_ref)&&MTA_NAME("transpose"))s=L"Signed semitone transposition";
 if(MTA_IS(galaxy_envelope4))s=L"High nibble describes pan envelope; low nibble describes volume envelope";
 if(MTA_IS(galaxy_envelope5)&&MTA_NAME("flags"))s=L"Bit 0 enabled; bit 1 sustain; bit 2 loop";
 if(MTA_IS(is2_event)&&MTA_NAME("transpose_arpeggio_effect"))s=L"Bit 7 disables sound transpose; bit 6 disables note transpose; bits 5..4 arpeggio; bits 3..0 effect";
 if(MTA_IS(is1_event)&&MTA_NAME("arpeggio_effect"))s=L"High nibble arpeggio; low nibble effect";
 if((MTA_IS(sym_count)||MTA_IS(sym_value)||MTA_IS(sym_bytes)||MTA_IS(sym_empty_sample))&&MTA_NAME("chunk_id"))s=L"Signed hunk ID: -1 channels, -2 rows, -3 pattern size, -4 instruments, -5 event size, -6 tempo, -7 external samples; -10..-21 payload hunks except -12 empty sample";
 if(s)return xx_data_struct_record_set_comment(r,s);
 return true;
#undef MTA_IS
#undef MTA_NAME
}
