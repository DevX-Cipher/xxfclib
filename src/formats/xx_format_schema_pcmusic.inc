/* SPDX-License-Identifier: MIT
 * Physical PC/FM/C64/PC-98 tracker metadata. Encoded event streams and samples stay raw.
 * See docs/data_struct_pcmusic_scope.txt for format-specific limits. */
static const xx_data_struct_field_desc sxpcm_pc_text_fields[]={
 SX_FIELD("text","char",0,0,SX_NONE),
};
static const sx_layout sxpcm_pc_text={UINT32_C(0x60940001),"pc_text",sxpcm_pc_text_fields,SX_COUNT(sxpcm_pc_text_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_pc_u8_length_fields[]={
 SX_FIELD("byte_length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxpcm_pc_u8_length={UINT32_C(0x60940002),"pc_u8_length",sxpcm_pc_u8_length_fields,SX_COUNT(sxpcm_pc_u8_length_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_pc_u16_length_fields[]={
 SX_FIELD("byte_length","uint16",0,2,SX_SIZE),
};
static const sx_layout sxpcm_pc_u16_length={UINT32_C(0x60940003),"pc_u16_length",sxpcm_pc_u16_length_fields,SX_COUNT(sxpcm_pc_u16_length_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_pc_u32_length_fields[]={
 SX_FIELD("byte_length","uint32",0,4,SX_SIZE),
};
static const sx_layout sxpcm_pc_u32_length={UINT32_C(0x60940004),"pc_u32_length",sxpcm_pc_u32_length_fields,SX_COUNT(sxpcm_pc_u32_length_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_pc_pattern_index_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_pc_pattern_index={UINT32_C(0x60940005),"pc_pattern_index",sxpcm_pc_pattern_index_fields,SX_COUNT(sxpcm_pc_pattern_index_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_pc_pattern_count_fields[]={
 SX_FIELD("pattern_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxpcm_pc_pattern_count={UINT32_C(0x60940006),"pc_pattern_count",sxpcm_pc_pattern_count_fields,SX_COUNT(sxpcm_pc_pattern_count_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_pc_order_count_fields[]={
 SX_FIELD("order_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxpcm_pc_order_count={UINT32_C(0x60940007),"pc_order_count",sxpcm_pc_order_count_fields,SX_COUNT(sxpcm_pc_order_count_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_pc_present_fields[]={
 SX_FIELD("present","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxpcm_pc_present={UINT32_C(0x60940008),"pc_present",sxpcm_pc_present_fields,SX_COUNT(sxpcm_pc_present_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_pc_packed_pattern_fields[]={
 SX_FIELD("packed_byte_length","uint16",0,2,SX_SIZE),
};
static const sx_layout sxpcm_pc_packed_pattern={UINT32_C(0x60940009),"pc_packed_pattern",sxpcm_pc_packed_pattern_fields,SX_COUNT(sxpcm_pc_packed_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_defy_header_fields[]={
 SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("version","uint8",12,1,SX_ID),
 SX_FIELD("title","char[20]",13,20,SX_NONE),
 SX_FIELD("author","char[20]",33,20,SX_NONE),
 SX_FIELD("pattern_count","uint8",53,1,SX_COUNT_PROP),
 SX_FIELD("instrument_last_index","uint8",54,1,SX_NONE),
};
static const sx_layout sxpcm_defy_header={UINT32_C(0x6094000A),"defy_header",sxpcm_defy_header_fields,SX_COUNT(sxpcm_defy_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_defy_instrument_fields[]={
 SX_FIELD("carrier_characteristics","uint8",0,1,SX_FLAGS),
 SX_FIELD("modulator_characteristics","uint8",1,1,SX_FLAGS),
 SX_FIELD("carrier_level","uint8",2,1,SX_FLAGS),
 SX_FIELD("modulator_level","uint8",3,1,SX_FLAGS),
 SX_FIELD("carrier_attack_decay","uint8",4,1,SX_FLAGS),
 SX_FIELD("modulator_attack_decay","uint8",5,1,SX_FLAGS),
 SX_FIELD("carrier_sustain_release","uint8",6,1,SX_FLAGS),
 SX_FIELD("modulator_sustain_release","uint8",7,1,SX_FLAGS),
 SX_FIELD("feedback_connection","uint8",8,1,SX_FLAGS),
 SX_FIELD("carrier_waveform","uint8",9,1,SX_ID),
 SX_FIELD("modulator_waveform","uint8",10,1,SX_ID),
 SX_FIELD("extra_byte","uint8",11,1,SX_NONE),
};
static const sx_layout sxpcm_defy_instrument={UINT32_C(0x6094000B),"defy_instrument",sxpcm_defy_instrument_fields,SX_COUNT(sxpcm_defy_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beni_header_fields[]={
 SX_FIELD("order_count","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("pattern_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("instrument_count","uint8",2,1,SX_COUNT_PROP),
};
static const sx_layout sxpcm_beni_header={UINT32_C(0x6094000C),"beni_header",sxpcm_beni_header_fields,SX_COUNT(sxpcm_beni_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beni_pattern_map_fields[]={
 SX_FIELD("pattern_id","uint8",0,1,SX_ID),
};
static const sx_layout sxpcm_beni_pattern_map={UINT32_C(0x6094000D),"beni_pattern_map",sxpcm_beni_pattern_map_fields,SX_COUNT(sxpcm_beni_pattern_map_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beni_instrument_map_fields[]={
 SX_FIELD("instrument_id","uint8",0,1,SX_ID),
};
static const sx_layout sxpcm_beni_instrument_map={UINT32_C(0x6094000E),"beni_instrument_map",sxpcm_beni_instrument_map_fields,SX_COUNT(sxpcm_beni_instrument_map_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beni_event_fields[]={
 SX_FIELD("packed_note_instrument_effect","uint24be",0,3,SX_FLAGS),
};
static const sx_layout sxpcm_beni_event={UINT32_C(0x6094000F),"beni_event",sxpcm_beni_event_fields,SX_COUNT(sxpcm_beni_event_fields),SX_BE};
static const xx_data_struct_field_desc sxpcm_beni_instrument_fields[]={
 SX_FIELD("modulator_characteristics","uint8",0,1,SX_FLAGS),
 SX_FIELD("carrier_characteristics","uint8",1,1,SX_FLAGS),
 SX_FIELD("modulator_level","uint8",2,1,SX_FLAGS),
 SX_FIELD("carrier_level","uint8",3,1,SX_FLAGS),
 SX_FIELD("modulator_attack_decay","uint8",4,1,SX_FLAGS),
 SX_FIELD("carrier_attack_decay","uint8",5,1,SX_FLAGS),
 SX_FIELD("modulator_sustain_release","uint8",6,1,SX_FLAGS),
 SX_FIELD("carrier_sustain_release","uint8",7,1,SX_FLAGS),
 SX_FIELD("modulator_waveform","uint8",8,1,SX_ID),
 SX_FIELD("carrier_waveform","uint8",9,1,SX_ID),
 SX_FIELD("feedback_connection","uint8",10,1,SX_FLAGS),
};
static const sx_layout sxpcm_beni_instrument={UINT32_C(0x60940010),"beni_instrument",sxpcm_beni_instrument_fields,SX_COUNT(sxpcm_beni_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beni_version_fields[]={
 SX_FIELD("marker","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxpcm_beni_version={UINT32_C(0x60940011),"beni_version",sxpcm_beni_version_fields,SX_COUNT(sxpcm_beni_version_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_taylor_header_fields[]={
 SX_FIELD("signature","char[9]",0,9,SX_SIGNATURE),
 SX_FIELD("major_version","uint8",9,1,SX_ID),
 SX_FIELD("minor_version","uint8",10,1,SX_ID),
 SX_FIELD("tracker","char[20]",11,20,SX_NONE),
 SX_FIELD("title","char[32]",31,32,SX_NONE),
};
static const sx_layout sxpcm_taylor_header={UINT32_C(0x60940012),"taylor_header",sxpcm_taylor_header_fields,SX_COUNT(sxpcm_taylor_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_taylor_instrument_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_NONE),
 SX_FIELD("modulator_characteristics","uint8",8,1,SX_FLAGS),
 SX_FIELD("carrier_characteristics","uint8",9,1,SX_FLAGS),
 SX_FIELD("modulator_level","uint8",10,1,SX_FLAGS),
 SX_FIELD("carrier_level","uint8",11,1,SX_FLAGS),
 SX_FIELD("modulator_attack_decay","uint8",12,1,SX_FLAGS),
 SX_FIELD("carrier_attack_decay","uint8",13,1,SX_FLAGS),
 SX_FIELD("modulator_sustain_release","uint8",14,1,SX_FLAGS),
 SX_FIELD("carrier_sustain_release","uint8",15,1,SX_FLAGS),
 SX_FIELD("modulator_waveform","uint8",16,1,SX_ID),
 SX_FIELD("carrier_waveform","uint8",17,1,SX_ID),
 SX_FIELD("feedback_connection","uint8",18,1,SX_FLAGS),
};
static const sx_layout sxpcm_taylor_instrument={UINT32_C(0x60940013),"taylor_instrument",sxpcm_taylor_instrument_fields,SX_COUNT(sxpcm_taylor_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_taylor_counts_fields[]={
 SX_FIELD("pattern_rows_minus_one","uint8",0,1,SX_NONE),
 SX_FIELD("order_count_minus_one","uint8",1,1,SX_NONE),
 SX_FIELD("pattern_count_minus_one","uint8",2,1,SX_NONE),
};
static const sx_layout sxpcm_taylor_counts={UINT32_C(0x60940014),"taylor_counts",sxpcm_taylor_counts_fields,SX_COUNT(sxpcm_taylor_counts_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_taylor_delay_fields[]={
 SX_FIELD("delay","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_taylor_delay={UINT32_C(0x60940015),"taylor_delay",sxpcm_taylor_delay_fields,SX_COUNT(sxpcm_taylor_delay_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_xorjs_header_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("speed","uint8",8,1,SX_NONE),
 SX_FIELD("bpm","uint8",9,1,SX_NONE),
};
static const sx_layout sxpcm_xorjs_header={UINT32_C(0x60940016),"xorjs_header",sxpcm_xorjs_header_fields,SX_COUNT(sxpcm_xorjs_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_xorjs_instrument_fields[]={
 SX_FIELD("modulator_characteristics","uint8",0,1,SX_FLAGS),
 SX_FIELD("modulator_level","uint8",1,1,SX_FLAGS),
 SX_FIELD("modulator_attack_decay","uint8",2,1,SX_FLAGS),
 SX_FIELD("modulator_sustain_release","uint8",3,1,SX_FLAGS),
 SX_FIELD("modulator_waveform","uint8",4,1,SX_ID),
 SX_FIELD("modulator_feedback_connection","uint8",5,1,SX_FLAGS),
 SX_FIELD("carrier_characteristics","uint8",6,1,SX_FLAGS),
 SX_FIELD("carrier_level","uint8",7,1,SX_FLAGS),
 SX_FIELD("carrier_attack_decay","uint8",8,1,SX_FLAGS),
 SX_FIELD("carrier_sustain_release","uint8",9,1,SX_FLAGS),
 SX_FIELD("carrier_waveform","uint8",10,1,SX_ID),
 SX_FIELD("carrier_feedback_connection","uint8",11,1,SX_FLAGS),
 SX_FIELD("name","char[24]",12,24,SX_NONE),
};
static const sx_layout sxpcm_xorjs_instrument={UINT32_C(0x60940017),"xorjs_instrument",sxpcm_xorjs_instrument_fields,SX_COUNT(sxpcm_xorjs_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_xorjs_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("volume","uint8",2,1,SX_NONE),
};
static const sx_layout sxpcm_xorjs_event={UINT32_C(0x60940018),"xorjs_event",sxpcm_xorjs_event_fields,SX_COUNT(sxpcm_xorjs_event_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_header_fields[]={
 SX_FIELD("load_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("signature","char[8]",2,8,SX_SIGNATURE),
 SX_FIELD("minor_version","uint8",10,1,SX_ID),
 SX_FIELD("major_version","uint8",11,1,SX_ID),
 SX_FIELD("table_count","uint8",12,1,SX_COUNT_PROP),
};
static const sx_layout sxpcm_cybertracker_header={UINT32_C(0x60940019),"cybertracker_header",sxpcm_cybertracker_header_fields,SX_COUNT(sxpcm_cybertracker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_vibrato_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
 SX_FIELD("depth","uint8",1,1,SX_NONE),
};
static const sx_layout sxpcm_cybertracker_vibrato={UINT32_C(0x6094001A),"cybertracker_vibrato",sxpcm_cybertracker_vibrato_fields,SX_COUNT(sxpcm_cybertracker_vibrato_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_vibrato_depth_fields[]={
 SX_FIELD("depth","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_cybertracker_vibrato_depth={UINT32_C(0x6094001B),"cybertracker_vibrato_depth",sxpcm_cybertracker_vibrato_depth_fields,SX_COUNT(sxpcm_cybertracker_vibrato_depth_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_vibrato_speed_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_cybertracker_vibrato_speed={UINT32_C(0x6094001C),"cybertracker_vibrato_speed",sxpcm_cybertracker_vibrato_speed_fields,SX_COUNT(sxpcm_cybertracker_vibrato_speed_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_arpeggio_fields[]={
 SX_FIELD("packed_semitone_offsets","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxpcm_cybertracker_arpeggio={UINT32_C(0x6094001D),"cybertracker_arpeggio",sxpcm_cybertracker_arpeggio_fields,SX_COUNT(sxpcm_cybertracker_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_adsr_fields[]={
 SX_FIELD("attack_decay","uint8",0,1,SX_FLAGS),
 SX_FIELD("sustain_release","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxpcm_cybertracker_adsr={UINT32_C(0x6094001E),"cybertracker_adsr",sxpcm_cybertracker_adsr_fields,SX_COUNT(sxpcm_cybertracker_adsr_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_name_fields[]={
 SX_FIELD("name","char[16]",0,16,SX_NONE),
};
static const sx_layout sxpcm_cybertracker_name={UINT32_C(0x6094001F),"cybertracker_name",sxpcm_cybertracker_name_fields,SX_COUNT(sxpcm_cybertracker_name_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_multieffect_fields[]={
 SX_FIELD("effect","uint8",0,1,SX_ID),
 SX_FIELD("parameter","uint8",1,1,SX_NONE),
};
static const sx_layout sxpcm_cybertracker_multieffect={UINT32_C(0x60940020),"cybertracker_multieffect",sxpcm_cybertracker_multieffect_fields,SX_COUNT(sxpcm_cybertracker_multieffect_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_song_length_fields[]={
 SX_FIELD("position_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxpcm_cybertracker_song_length={UINT32_C(0x60940021),"cybertracker_song_length",sxpcm_cybertracker_song_length_fields,SX_COUNT(sxpcm_cybertracker_song_length_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_song_repeat_fields[]={
 SX_FIELD("repeat_position","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_cybertracker_song_repeat={UINT32_C(0x60940022),"cybertracker_song_repeat",sxpcm_cybertracker_song_repeat_fields,SX_COUNT(sxpcm_cybertracker_song_repeat_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_loop_start_fields[]={
 SX_FIELD("loop_point","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_cybertracker_loop_start={UINT32_C(0x60940023),"cybertracker_loop_start",sxpcm_cybertracker_loop_start_fields,SX_COUNT(sxpcm_cybertracker_loop_start_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_envelope_length_fields[]={
 SX_FIELD("point_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxpcm_cybertracker_envelope_length={UINT32_C(0x60940024),"cybertracker_envelope_length",sxpcm_cybertracker_envelope_length_fields,SX_COUNT(sxpcm_cybertracker_envelope_length_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_x_low_fields[]={
 SX_FIELD("x_low","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_cybertracker_x_low={UINT32_C(0x60940025),"cybertracker_x_low",sxpcm_cybertracker_x_low_fields,SX_COUNT(sxpcm_cybertracker_x_low_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_x_high_fields[]={
 SX_FIELD("x_high","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_cybertracker_x_high={UINT32_C(0x60940026),"cybertracker_x_high",sxpcm_cybertracker_x_high_fields,SX_COUNT(sxpcm_cybertracker_x_high_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_y_low_fields[]={
 SX_FIELD("y_low","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_cybertracker_y_low={UINT32_C(0x60940027),"cybertracker_y_low",sxpcm_cybertracker_y_low_fields,SX_COUNT(sxpcm_cybertracker_y_low_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_y_high_fields[]={
 SX_FIELD("y_high","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_cybertracker_y_high={UINT32_C(0x60940028),"cybertracker_y_high",sxpcm_cybertracker_y_high_fields,SX_COUNT(sxpcm_cybertracker_y_high_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_cybertracker_pattern_length_fields[]={
 SX_FIELD("encoded_pattern_byte_length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxpcm_cybertracker_pattern_length={UINT32_C(0x60940029),"cybertracker_pattern_length",sxpcm_cybertracker_pattern_length_fields,SX_COUNT(sxpcm_cybertracker_pattern_length_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_header_fields[]={
 SX_FIELD("load_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("signature","char[2]",2,2,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("revision","uint8",5,1,SX_ID),
 SX_FIELD("play_mode","uint8",6,1,SX_ID),
 SX_FIELD("scale","uint8",7,1,SX_ID),
 SX_FIELD("reserved","uint8",8,1,SX_RESERVED),
 SX_FIELD("song_count","uint8",9,1,SX_COUNT_PROP),
};
static const sx_layout sxpcm_victracker_header={UINT32_C(0x6094002A),"victracker_header",sxpcm_victracker_header_fields,SX_COUNT(sxpcm_victracker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_song_fields[]={
 SX_FIELD("first_step","uint8",0,1,SX_NONE),
 SX_FIELD("last_step","uint8",1,1,SX_NONE),
 SX_FIELD("repeat_step","uint8",2,1,SX_NONE),
 SX_FIELD("speed_flags","uint8",3,1,SX_FLAGS),
};
static const sx_layout sxpcm_victracker_song={UINT32_C(0x6094002B),"victracker_song",sxpcm_victracker_song_fields,SX_COUNT(sxpcm_victracker_song_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_arpeggio_fields[]={
 SX_FIELD("steps","uint8[16]",0,16,SX_NONE),
};
static const sx_layout sxpcm_victracker_arpeggio={UINT32_C(0x6094002C),"victracker_arpeggio",sxpcm_victracker_arpeggio_fields,SX_COUNT(sxpcm_victracker_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_arpeggio_config_fields[]={
 SX_FIELD("configuration","uint8[2]",0,2,SX_FLAGS),
};
static const sx_layout sxpcm_victracker_arpeggio_config={UINT32_C(0x6094002D),"victracker_arpeggio_config",sxpcm_victracker_arpeggio_config_fields,SX_COUNT(sxpcm_victracker_arpeggio_config_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_title_fields[]={
 SX_FIELD("reserved","bytes",0,60,SX_RESERVED),
 SX_FIELD("title","char[16]",60,16,SX_NONE),
 SX_FIELD("author","char[16]",76,16,SX_NONE),
 SX_FIELD("year","char[4]",92,4,SX_NONE),
};
static const sx_layout sxpcm_victracker_title={UINT32_C(0x6094002E),"victracker_title",sxpcm_victracker_title_fields,SX_COUNT(sxpcm_victracker_title_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_sound_fields[]={
 SX_FIELD("note_length","uint8",0,1,SX_NONE),
 SX_FIELD("frequency_offset","uint8",1,1,SX_NONE),
 SX_FIELD("frequency_glide","uint8",2,1,SX_NONE),
 SX_FIELD("arpeggio","uint8",3,1,SX_ID),
 SX_FIELD("reserved","bytes",4,4,SX_RESERVED),
};
static const sx_layout sxpcm_victracker_sound={UINT32_C(0x6094002F),"victracker_sound",sxpcm_victracker_sound_fields,SX_COUNT(sxpcm_victracker_sound_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_sequence_length_fields[]={
 SX_FIELD("last_row_index","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_victracker_sequence_length={UINT32_C(0x60940030),"victracker_sequence_length",sxpcm_victracker_sequence_length_fields,SX_COUNT(sxpcm_victracker_sequence_length_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_event_fields[]={
 SX_FIELD("pitch","uint8",0,1,SX_NONE),
 SX_FIELD("parameter","uint8",1,1,SX_NONE),
};
static const sx_layout sxpcm_victracker_event={UINT32_C(0x60940031),"victracker_event",sxpcm_victracker_event_fields,SX_COUNT(sxpcm_victracker_event_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_muap_header_fields[]={
 SX_FIELD("channel_offsets","uint16[17]",0,34,SX_OFFSET),
};
static const sx_layout sxpcm_muap_header={UINT32_C(0x60940032),"muap_header",sxpcm_muap_header_fields,SX_COUNT(sxpcm_muap_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_muap_tone_fields[]={
 SX_FIELD("operator_detune_multiple","uint8[4]",0,4,SX_FLAGS),
 SX_FIELD("operator_total_level","uint8[4]",4,4,SX_FLAGS),
 SX_FIELD("operator_keyscale_attack","uint8[4]",8,4,SX_FLAGS),
 SX_FIELD("operator_am_decay","uint8[4]",12,4,SX_FLAGS),
 SX_FIELD("operator_sustain_rate","uint8[4]",16,4,SX_FLAGS),
 SX_FIELD("operator_sustain_release","uint8[4]",20,4,SX_FLAGS),
 SX_FIELD("feedback_algorithm","uint8",24,1,SX_FLAGS),
};
static const sx_layout sxpcm_muap_tone={UINT32_C(0x60940033),"muap_tone",sxpcm_muap_tone_fields,SX_COUNT(sxpcm_muap_tone_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_pmd_header_fields[]={
 SX_FIELD("target_mode","int8",0,1,SX_ID),
 SX_FIELD("fm_channel_offsets","uint16[6]",1,12,SX_OFFSET),
 SX_FIELD("ssg_channel_offsets","uint16[3]",13,6,SX_OFFSET),
 SX_FIELD("adpcm_channel_offset","uint16",19,2,SX_OFFSET),
 SX_FIELD("rhythm_channel_offset","uint16",21,2,SX_OFFSET),
 SX_FIELD("rhythm_table_offset","uint16",23,2,SX_OFFSET),
};
static const sx_layout sxpcm_pmd_header={UINT32_C(0x60940034),"pmd_header",sxpcm_pmd_header_fields,SX_COUNT(sxpcm_pmd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_pmd_program_pointer_fields[]={
 SX_FIELD("program_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxpcm_pmd_program_pointer={UINT32_C(0x60940035),"pmd_program_pointer",sxpcm_pmd_program_pointer_fields,SX_COUNT(sxpcm_pmd_program_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_pmd_memo_header_fields[]={
 SX_FIELD("memo_table_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("driver_version","uint8",2,1,SX_ID),
 SX_FIELD("driver_marker","uint8",3,1,SX_NONE),
};
static const sx_layout sxpcm_pmd_memo_header={UINT32_C(0x60940036),"pmd_memo_header",sxpcm_pmd_memo_header_fields,SX_COUNT(sxpcm_pmd_memo_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_pmd_memo_pointer_fields[]={
 SX_FIELD("string_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxpcm_pmd_memo_pointer={UINT32_C(0x60940037),"pmd_memo_pointer",sxpcm_pmd_memo_pointer_fields,SX_COUNT(sxpcm_pmd_memo_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_toast_signature_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
};
static const sx_layout sxpcm_toast_signature={UINT32_C(0x60940038),"toast_signature",sxpcm_toast_signature_fields,SX_COUNT(sxpcm_toast_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_toast_synth_fields[]={
 SX_FIELD("waveform","uint8[16]",0,16,SX_ID),
 SX_FIELD("link","uint8[16]",16,16,SX_NONE),
 SX_FIELD("link_factor","float32[16]",32,64,SX_NONE),
 SX_FIELD("output_factor","float32[16]",96,64,SX_NONE),
 SX_FIELD("start_volume","float32[16]",160,64,SX_NONE),
 SX_FIELD("start_volume_factor","float32[16]",224,64,SX_NONE),
 SX_FIELD("start_phase_factor","float32[16]",288,64,SX_NONE),
 SX_FIELD("panning","uint8[16]",352,16,SX_NONE),
 SX_FIELD("event_offset","int32[16]",368,64,SX_NONE),
 SX_FIELD("note_offset","int32[16]",432,64,SX_NONE),
 SX_FIELD("volume_offset","int32[16]",496,64,SX_NONE),
};
static const sx_layout sxpcm_toast_synth={UINT32_C(0x60940039),"toast_synth",sxpcm_toast_synth_fields,SX_COUNT(sxpcm_toast_synth_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_toast_adsr_fields[]={
 SX_FIELD("attack_step","float32[16]",0,64,SX_NONE),
 SX_FIELD("decay_step","float32[16]",64,64,SX_NONE),
 SX_FIELD("decay_destination","float32[16]",128,64,SX_NONE),
 SX_FIELD("sustain","uint8[16]",192,16,SX_FLAGS),
 SX_FIELD("release_step","float32[16]",208,64,SX_NONE),
};
static const sx_layout sxpcm_toast_adsr={UINT32_C(0x6094003A),"toast_adsr",sxpcm_toast_adsr_fields,SX_COUNT(sxpcm_toast_adsr_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_toast_settings_fields[]={
 SX_FIELD("minor_row_highlight","uint8",0,1,SX_NONE),
 SX_FIELD("major_row_highlight","uint8",1,1,SX_NONE),
 SX_FIELD("drum_mode","uint8",2,1,SX_ID),
 SX_FIELD("chip_mode","uint8",3,1,SX_ID),
 SX_FIELD("channel_count","uint8",4,1,SX_COUNT_PROP),
};
static const sx_layout sxpcm_toast_settings={UINT32_C(0x6094003B),"toast_settings",sxpcm_toast_settings_fields,SX_COUNT(sxpcm_toast_settings_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_toast_channel_fields[]={
 SX_FIELD("mode","uint8",0,1,SX_ID),
 SX_FIELD("mute","uint8",1,1,SX_FLAGS),
 SX_FIELD("active","uint8",2,1,SX_FLAGS),
};
static const sx_layout sxpcm_toast_channel={UINT32_C(0x6094003C),"toast_channel",sxpcm_toast_channel_fields,SX_COUNT(sxpcm_toast_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_toast_instrument_fields[]={
 SX_FIELD("name_length","uint8",0,1,SX_SIZE),
 SX_FIELD("name_storage","char[24]",1,24,SX_NONE),
};
static const sx_layout sxpcm_toast_instrument={UINT32_C(0x6094003D),"toast_instrument",sxpcm_toast_instrument_fields,SX_COUNT(sxpcm_toast_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_toast_orders_fields[]={
 SX_FIELD("order_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxpcm_toast_orders={UINT32_C(0x6094003E),"toast_orders",sxpcm_toast_orders_fields,SX_COUNT(sxpcm_toast_orders_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_toast_restart_fields[]={
 SX_FIELD("restart_position","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_toast_restart={UINT32_C(0x6094003F),"toast_restart",sxpcm_toast_restart_fields,SX_COUNT(sxpcm_toast_restart_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_reserved_fields[]={
 SX_FIELD("reserved","bytes",0,128,SX_RESERVED),
};
static const sx_layout sxpcm_victracker_reserved={UINT32_C(0x60940040),"victracker_reserved",sxpcm_victracker_reserved_fields,SX_COUNT(sxpcm_victracker_reserved_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_victracker_sequence_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_victracker_sequence={UINT32_C(0x60940041),"victracker_sequence",sxpcm_victracker_sequence_fields,SX_COUNT(sxpcm_victracker_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_mvs_header_fields[]={
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
};
static const sx_layout sxpcm_mvs_header={UINT32_C(0x60940042),"mvs_header",sxpcm_mvs_header_fields,SX_COUNT(sxpcm_mvs_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_mvs_instrument_fields[]={
 SX_FIELD("operator_detune_multiple","uint8[4]",0,4,SX_FLAGS),
 SX_FIELD("operator_total_level","uint8[4]",4,4,SX_FLAGS),
 SX_FIELD("operator_keyscale_attack","uint8[4]",8,4,SX_FLAGS),
 SX_FIELD("operator_am_decay","uint8[4]",12,4,SX_FLAGS),
 SX_FIELD("operator_sustain_rate","uint8[4]",16,4,SX_FLAGS),
 SX_FIELD("operator_sustain_release","uint8[4]",20,4,SX_FLAGS),
 SX_FIELD("feedback_algorithm","uint8",24,1,SX_FLAGS),
};
static const sx_layout sxpcm_mvs_instrument={UINT32_C(0x60940043),"mvs_instrument",sxpcm_mvs_instrument_fields,SX_COUNT(sxpcm_mvs_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_mvs_event_fields[]={
 SX_FIELD("octave_and_note","uint8",0,1,SX_FLAGS),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("effect_parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxpcm_mvs_event={UINT32_C(0x60940044),"mvs_event",sxpcm_mvs_event_fields,SX_COUNT(sxpcm_mvs_event_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_axs_form_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("form_byte_size","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","char[4]",8,4,SX_ID),
};
static const sx_layout sxpcm_axs_form={UINT32_C(0x60940045),"axs_form",sxpcm_axs_form_fields,SX_COUNT(sxpcm_axs_form_fields),SX_BE};
static const xx_data_struct_field_desc sxpcm_axs_chunk_fields[]={
 SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
 SX_FIELD("payload_byte_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxpcm_axs_chunk={UINT32_C(0x60940046),"axs_chunk",sxpcm_axs_chunk_fields,SX_COUNT(sxpcm_axs_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxpcm_axs_settings_fields[]={
 SX_FIELD("opaque_prefix","bytes",0,2,SX_NONE),
 SX_FIELD("tempo_bpm","uint8",2,1,SX_NONE),
 SX_FIELD("opaque_parameter_3","bytes",3,1,SX_NONE),
 SX_FIELD("sync_flags","uint8",4,1,SX_FLAGS),
 SX_FIELD("delay_fraction_code","uint8",5,1,SX_ID),
 SX_FIELD("delay_5ms_units","uint8",6,1,SX_NONE),
 SX_FIELD("pan","uint8",7,1,SX_NONE),
 SX_FIELD("feedback","uint8",8,1,SX_NONE),
 SX_FIELD("reverb_preset","uint8",9,1,SX_ID),
 SX_FIELD("block_count","uint8",10,1,SX_COUNT_PROP),
 SX_FIELD("sequence_count","uint8",11,1,SX_COUNT_PROP),
 SX_FIELD("opaque_tail","bytes",12,8,SX_NONE),
};
static const sx_layout sxpcm_axs_settings={UINT32_C(0x60940047),"axs_settings",sxpcm_axs_settings_fields,SX_COUNT(sxpcm_axs_settings_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_axs_sequence_fields[]={
 SX_FIELD("block_index","uint8",0,1,SX_NONE),
 SX_FIELD("opaque_index_extension","bytes",1,3,SX_NONE),
 SX_FIELD("disabled_channel_mask","uint16",4,2,SX_FLAGS),
 SX_FIELD("opaque_tail","bytes",6,2,SX_NONE),
};
static const sx_layout sxpcm_axs_sequence={UINT32_C(0x60940048),"axs_sequence",sxpcm_axs_sequence_fields,SX_COUNT(sxpcm_axs_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_axs_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("velocity","uint8",1,1,SX_NONE),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("effect_parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxpcm_axs_event={UINT32_C(0x60940049),"axs_event",sxpcm_axs_event_fields,SX_COUNT(sxpcm_axs_event_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_synth_marker_fields[]={
 SX_FIELD("marker","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxpcm_beaver_synth_marker={UINT32_C(0x6094004A),"beaver_synth_marker",sxpcm_beaver_synth_marker_fields,SX_COUNT(sxpcm_beaver_synth_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_sample_flags_fields[]={
 SX_FIELD("sample_flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxpcm_beaver_sample_flags={UINT32_C(0x6094004B),"beaver_sample_flags",sxpcm_beaver_sample_flags_fields,SX_COUNT(sxpcm_beaver_sample_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_sample_length_fields[]={
 SX_FIELD("sample_count","uint24",0,3,SX_COUNT_PROP),
};
static const sx_layout sxpcm_beaver_sample_length={UINT32_C(0x6094004C),"beaver_sample_length",sxpcm_beaver_sample_length_fields,SX_COUNT(sxpcm_beaver_sample_length_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_sample_loop_fields[]={
 SX_FIELD("loop_start_sample","uint24",0,3,SX_NONE),
 SX_FIELD("loop_end_sample","uint24",3,3,SX_NONE),
};
static const sx_layout sxpcm_beaver_sample_loop={UINT32_C(0x6094004D),"beaver_sample_loop",sxpcm_beaver_sample_loop_fields,SX_COUNT(sxpcm_beaver_sample_loop_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_voice_count_fields[]={
 SX_FIELD("voice_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxpcm_beaver_voice_count={UINT32_C(0x6094004E),"beaver_voice_count",sxpcm_beaver_voice_count_fields,SX_COUNT(sxpcm_beaver_voice_count_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_polyphony_fields[]={
 SX_FIELD("polyphony","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxpcm_beaver_polyphony={UINT32_C(0x6094004F),"beaver_polyphony",sxpcm_beaver_polyphony_fields,SX_COUNT(sxpcm_beaver_polyphony_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_voice_range_fields[]={
 SX_FIELD("first_note","uint8",0,1,SX_NONE),
 SX_FIELD("last_note","uint8",1,1,SX_NONE),
};
static const sx_layout sxpcm_beaver_voice_range={UINT32_C(0x60940050),"beaver_voice_range",sxpcm_beaver_voice_range_fields,SX_COUNT(sxpcm_beaver_voice_range_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_modulator_count_fields[]={
 SX_FIELD("modulator_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxpcm_beaver_modulator_count={UINT32_C(0x60940051),"beaver_modulator_count",sxpcm_beaver_modulator_count_fields,SX_COUNT(sxpcm_beaver_modulator_count_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_oscillator_count_fields[]={
 SX_FIELD("oscillator_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxpcm_beaver_oscillator_count={UINT32_C(0x60940052),"beaver_oscillator_count",sxpcm_beaver_oscillator_count_fields,SX_COUNT(sxpcm_beaver_oscillator_count_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_insert_count_fields[]={
 SX_FIELD("insert_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxpcm_beaver_insert_count={UINT32_C(0x60940053),"beaver_insert_count",sxpcm_beaver_insert_count_fields,SX_COUNT(sxpcm_beaver_insert_count_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_type_fields[]={
 SX_FIELD("component_type","uint8",0,1,SX_ID),
};
static const sx_layout sxpcm_beaver_type={UINT32_C(0x60940054),"beaver_type",sxpcm_beaver_type_fields,SX_COUNT(sxpcm_beaver_type_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_envelope_fields[]={
 SX_FIELD("attack_ticks","uint8",0,1,SX_NONE),
 SX_FIELD("decay_ticks","uint8",1,1,SX_NONE),
 SX_FIELD("release_ticks","uint8",2,1,SX_NONE),
 SX_FIELD("sustain_level","float32",3,4,SX_NONE),
 SX_FIELD("velocity_sensitivity","float32",7,4,SX_NONE),
 SX_FIELD("use_sustain","uint8",11,1,SX_FLAGS),
};
static const sx_layout sxpcm_beaver_envelope={UINT32_C(0x60940055),"beaver_envelope",sxpcm_beaver_envelope_fields,SX_COUNT(sxpcm_beaver_envelope_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_lfo_fields[]={
 SX_FIELD("waveform","uint8",0,1,SX_ID),
 SX_FIELD("invert","uint8",1,1,SX_FLAGS),
 SX_FIELD("offset","float32",2,4,SX_NONE),
 SX_FIELD("attack_ticks","uint8",6,1,SX_NONE),
 SX_FIELD("retrigger","uint8",7,1,SX_FLAGS),
 SX_FIELD("velocity_sensitivity","float32",8,4,SX_NONE),
 SX_FIELD("period_ticks","uint16",12,2,SX_NONE),
};
static const sx_layout sxpcm_beaver_lfo={UINT32_C(0x60940056),"beaver_lfo",sxpcm_beaver_lfo_fields,SX_COUNT(sxpcm_beaver_lfo_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_controller_fields[]={
 SX_FIELD("smoothing_cutoff","float32",0,4,SX_NONE),
 SX_FIELD("controller_number","uint8",4,1,SX_ID),
};
static const sx_layout sxpcm_beaver_controller={UINT32_C(0x60940057),"beaver_controller",sxpcm_beaver_controller_fields,SX_COUNT(sxpcm_beaver_controller_fields),SX_LE};
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
static const sx_layout sxpcm_beaver_oscillator={UINT32_C(0x60940058),"beaver_oscillator",sxpcm_beaver_oscillator_fields,SX_COUNT(sxpcm_beaver_oscillator_fields),SX_LE};
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
static const sx_layout sxpcm_beaver_filter={UINT32_C(0x60940059),"beaver_filter",sxpcm_beaver_filter_fields,SX_COUNT(sxpcm_beaver_filter_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_distortion_fields[]={
 SX_FIELD("amount","float32",0,4,SX_NONE),
 SX_FIELD("output_volume","float32",4,4,SX_NONE),
 SX_FIELD("mode","uint8",8,1,SX_ID),
};
static const sx_layout sxpcm_beaver_distortion={UINT32_C(0x6094005A),"beaver_distortion",sxpcm_beaver_distortion_fields,SX_COUNT(sxpcm_beaver_distortion_fields),SX_LE};
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
static const sx_layout sxpcm_beaver_delay={UINT32_C(0x6094005B),"beaver_delay",sxpcm_beaver_delay_fields,SX_COUNT(sxpcm_beaver_delay_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_chorus_fields[]={
 SX_FIELD("speed","float32",0,4,SX_NONE),
 SX_FIELD("depth","float32",4,4,SX_NONE),
 SX_FIELD("spread","float32",8,4,SX_NONE),
 SX_FIELD("feedback","float32",12,4,SX_NONE),
 SX_FIELD("volume","float32",16,4,SX_NONE),
 SX_FIELD("dry_mix","float32",20,4,SX_NONE),
 SX_FIELD("high_fidelity","uint8",24,1,SX_FLAGS),
};
static const sx_layout sxpcm_beaver_chorus={UINT32_C(0x6094005C),"beaver_chorus",sxpcm_beaver_chorus_fields,SX_COUNT(sxpcm_beaver_chorus_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_voice_modulation_fields[]={
 SX_FIELD("volume_modulator","uint8",0,1,SX_ID),
 SX_FIELD("panning_modulator","uint8",1,1,SX_ID),
 SX_FIELD("volume_amount","float32",2,4,SX_NONE),
 SX_FIELD("panning_amount","float32",6,4,SX_NONE),
};
static const sx_layout sxpcm_beaver_voice_modulation={UINT32_C(0x6094005D),"beaver_voice_modulation",sxpcm_beaver_voice_modulation_fields,SX_COUNT(sxpcm_beaver_voice_modulation_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_distortion_enabled_fields[]={
 SX_FIELD("enabled","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxpcm_beaver_distortion_enabled={UINT32_C(0x6094005E),"beaver_distortion_enabled",sxpcm_beaver_distortion_enabled_fields,SX_COUNT(sxpcm_beaver_distortion_enabled_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_arpeggio_enabled_fields[]={
 SX_FIELD("enabled","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxpcm_beaver_arpeggio_enabled={UINT32_C(0x6094005F),"beaver_arpeggio_enabled",sxpcm_beaver_arpeggio_enabled_fields,SX_COUNT(sxpcm_beaver_arpeggio_enabled_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_arpeggio_step_fields[]={
 SX_FIELD("note_indexes","uint8[3]",0,3,SX_NONE),
 SX_FIELD("octave","int8",3,1,SX_NONE),
 SX_FIELD("velocity","uint8",4,1,SX_NONE),
 SX_FIELD("length_ticks","uint8",5,1,SX_NONE),
};
static const sx_layout sxpcm_beaver_arpeggio_step={UINT32_C(0x60940060),"beaver_arpeggio_step",sxpcm_beaver_arpeggio_step_fields,SX_COUNT(sxpcm_beaver_arpeggio_step_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_arpeggio_timing_fields[]={
 SX_FIELD("ticks_per_row","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_beaver_arpeggio_timing={UINT32_C(0x60940061),"beaver_arpeggio_timing",sxpcm_beaver_arpeggio_timing_fields,SX_COUNT(sxpcm_beaver_arpeggio_timing_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_mixer_fields[]={
 SX_FIELD("volume","float32",0,4,SX_NONE),
 SX_FIELD("panning","float32",4,4,SX_NONE),
 SX_FIELD("effect1_gain","float32",8,4,SX_NONE),
 SX_FIELD("effect2_gain","float32",12,4,SX_NONE),
 SX_FIELD("effect3_gain","float32",16,4,SX_NONE),
};
static const sx_layout sxpcm_beaver_mixer={UINT32_C(0x60940062),"beaver_mixer",sxpcm_beaver_mixer_fields,SX_COUNT(sxpcm_beaver_mixer_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_chain_fields[]={
 SX_FIELD("enabled_effect_mask","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxpcm_beaver_chain={UINT32_C(0x60940063),"beaver_chain",sxpcm_beaver_chain_fields,SX_COUNT(sxpcm_beaver_chain_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_song_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("channel_count","uint8",6,1,SX_COUNT_PROP),
 SX_FIELD("pattern_count","uint8",7,1,SX_COUNT_PROP),
 SX_FIELD("instrument_count","uint8",8,1,SX_COUNT_PROP),
 SX_FIELD("initial_bpm","uint8",9,1,SX_NONE),
 SX_FIELD("initial_pattern_tick","uint8",10,1,SX_NONE),
 SX_FIELD("sequence_tick_units","uint8",11,1,SX_NONE),
};
static const sx_layout sxpcm_beaver_song_header={UINT32_C(0x60940064),"beaver_song_header",sxpcm_beaver_song_header_fields,SX_COUNT(sxpcm_beaver_song_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_channel_v102_fields[]={
 SX_FIELD("channel_id","uint8",0,1,SX_ID),
 SX_FIELD("position_count","uint8",1,1,SX_COUNT_PROP),
};
static const sx_layout sxpcm_beaver_channel_v102={UINT32_C(0x60940065),"beaver_channel_v102",sxpcm_beaver_channel_v102_fields,SX_COUNT(sxpcm_beaver_channel_v102_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_channel_fields[]={
 SX_FIELD("channel_id","uint8",0,1,SX_ID),
 SX_FIELD("position_count","uint16",1,2,SX_COUNT_PROP),
};
static const sx_layout sxpcm_beaver_channel={UINT32_C(0x60940066),"beaver_channel",sxpcm_beaver_channel_fields,SX_COUNT(sxpcm_beaver_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_mask_fields[]={
 SX_FIELD("stored_field_mask","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxpcm_beaver_position_mask={UINT32_C(0x60940067),"beaver_position_mask",sxpcm_beaver_position_mask_fields,SX_COUNT(sxpcm_beaver_position_mask_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_pattern_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_beaver_position_pattern={UINT32_C(0x60940068),"beaver_position_pattern",sxpcm_beaver_position_pattern_fields,SX_COUNT(sxpcm_beaver_position_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_transpose_fields[]={
 SX_FIELD("transpose","int8",0,1,SX_NONE),
};
static const sx_layout sxpcm_beaver_position_transpose={UINT32_C(0x60940069),"beaver_position_transpose",sxpcm_beaver_position_transpose_fields,SX_COUNT(sxpcm_beaver_position_transpose_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_effect_fields[]={
 SX_FIELD("effect","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_beaver_position_effect={UINT32_C(0x6094006A),"beaver_position_effect",sxpcm_beaver_position_effect_fields,SX_COUNT(sxpcm_beaver_position_effect_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_effect_parameter_1_fields[]={
 SX_FIELD("effect_parameter_1","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_beaver_position_effect_parameter_1={UINT32_C(0x6094006B),"beaver_position_effect_parameter_1",sxpcm_beaver_position_effect_parameter_1_fields,SX_COUNT(sxpcm_beaver_position_effect_parameter_1_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_effect_parameter_2_fields[]={
 SX_FIELD("effect_parameter_2","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_beaver_position_effect_parameter_2={UINT32_C(0x6094006C),"beaver_position_effect_parameter_2",sxpcm_beaver_position_effect_parameter_2_fields,SX_COUNT(sxpcm_beaver_position_effect_parameter_2_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_effect_parameter_3_fields[]={
 SX_FIELD("effect_parameter_3","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_beaver_position_effect_parameter_3={UINT32_C(0x6094006D),"beaver_position_effect_parameter_3",sxpcm_beaver_position_effect_parameter_3_fields,SX_COUNT(sxpcm_beaver_position_effect_parameter_3_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_effect_parameter_4_fields[]={
 SX_FIELD("effect_parameter_4","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_beaver_position_effect_parameter_4={UINT32_C(0x6094006E),"beaver_position_effect_parameter_4",sxpcm_beaver_position_effect_parameter_4_fields,SX_COUNT(sxpcm_beaver_position_effect_parameter_4_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_effect_parameter_5_fields[]={
 SX_FIELD("effect_parameter_5","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_beaver_position_effect_parameter_5={UINT32_C(0x6094006F),"beaver_position_effect_parameter_5",sxpcm_beaver_position_effect_parameter_5_fields,SX_COUNT(sxpcm_beaver_position_effect_parameter_5_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_position_effect_parameter_6_fields[]={
 SX_FIELD("effect_parameter_6","uint8",0,1,SX_NONE),
};
static const sx_layout sxpcm_beaver_position_effect_parameter_6={UINT32_C(0x60940070),"beaver_position_effect_parameter_6",sxpcm_beaver_position_effect_parameter_6_fields,SX_COUNT(sxpcm_beaver_position_effect_parameter_6_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_pattern_v102_fields[]={
 SX_FIELD("pattern_id","uint8",0,1,SX_ID),
 SX_FIELD("row_count","uint8",1,1,SX_COUNT_PROP),
};
static const sx_layout sxpcm_beaver_pattern_v102={UINT32_C(0x60940071),"beaver_pattern_v102",sxpcm_beaver_pattern_v102_fields,SX_COUNT(sxpcm_beaver_pattern_v102_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_pattern_fields[]={
 SX_FIELD("pattern_id","uint8",0,1,SX_ID),
 SX_FIELD("row_count","uint16",1,2,SX_COUNT_PROP),
};
static const sx_layout sxpcm_beaver_pattern={UINT32_C(0x60940072),"beaver_pattern",sxpcm_beaver_pattern_fields,SX_COUNT(sxpcm_beaver_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_pattern_row_fields[]={
 SX_FIELD("active_channel_mask","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxpcm_beaver_pattern_row={UINT32_C(0x60940073),"beaver_pattern_row",sxpcm_beaver_pattern_row_fields,SX_COUNT(sxpcm_beaver_pattern_row_fields),SX_LE};
static const xx_data_struct_field_desc sxpcm_beaver_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("velocity","uint8",1,1,SX_NONE),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("effect_parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxpcm_beaver_event={UINT32_C(0x60940074),"beaver_event",sxpcm_beaver_event_fields,SX_COUNT(sxpcm_beaver_event_fields),SX_LE};
static const sx_layout *const sx_pcmusic_layouts[]={
 &sxpcm_pc_text,
 &sxpcm_pc_u8_length,
 &sxpcm_pc_u16_length,
 &sxpcm_pc_u32_length,
 &sxpcm_pc_pattern_index,
 &sxpcm_pc_pattern_count,
 &sxpcm_pc_order_count,
 &sxpcm_pc_present,
 &sxpcm_pc_packed_pattern,
 &sxpcm_defy_header,
 &sxpcm_defy_instrument,
 &sxpcm_beni_header,
 &sxpcm_beni_pattern_map,
 &sxpcm_beni_instrument_map,
 &sxpcm_beni_event,
 &sxpcm_beni_instrument,
 &sxpcm_beni_version,
 &sxpcm_taylor_header,
 &sxpcm_taylor_instrument,
 &sxpcm_taylor_counts,
 &sxpcm_taylor_delay,
 &sxpcm_xorjs_header,
 &sxpcm_xorjs_instrument,
 &sxpcm_xorjs_event,
 &sxpcm_cybertracker_header,
 &sxpcm_cybertracker_vibrato,
 &sxpcm_cybertracker_vibrato_depth,
 &sxpcm_cybertracker_vibrato_speed,
 &sxpcm_cybertracker_arpeggio,
 &sxpcm_cybertracker_adsr,
 &sxpcm_cybertracker_name,
 &sxpcm_cybertracker_multieffect,
 &sxpcm_cybertracker_song_length,
 &sxpcm_cybertracker_song_repeat,
 &sxpcm_cybertracker_loop_start,
 &sxpcm_cybertracker_envelope_length,
 &sxpcm_cybertracker_x_low,
 &sxpcm_cybertracker_x_high,
 &sxpcm_cybertracker_y_low,
 &sxpcm_cybertracker_y_high,
 &sxpcm_cybertracker_pattern_length,
 &sxpcm_victracker_header,
 &sxpcm_victracker_song,
 &sxpcm_victracker_arpeggio,
 &sxpcm_victracker_arpeggio_config,
 &sxpcm_victracker_title,
 &sxpcm_victracker_sound,
 &sxpcm_victracker_sequence_length,
 &sxpcm_victracker_event,
 &sxpcm_muap_header,
 &sxpcm_muap_tone,
 &sxpcm_pmd_header,
 &sxpcm_pmd_program_pointer,
 &sxpcm_pmd_memo_header,
 &sxpcm_pmd_memo_pointer,
 &sxpcm_toast_signature,
 &sxpcm_toast_synth,
 &sxpcm_toast_adsr,
 &sxpcm_toast_settings,
 &sxpcm_toast_channel,
 &sxpcm_toast_instrument,
 &sxpcm_toast_orders,
 &sxpcm_toast_restart,
 &sxpcm_victracker_reserved,
 &sxpcm_victracker_sequence,
 &sxpcm_mvs_header,
 &sxpcm_mvs_instrument,
 &sxpcm_mvs_event,
 &sxpcm_axs_form,
 &sxpcm_axs_chunk,
 &sxpcm_axs_settings,
 &sxpcm_axs_sequence,
 &sxpcm_axs_event,
 &sxpcm_beaver_synth_marker,
 &sxpcm_beaver_sample_flags,
 &sxpcm_beaver_sample_length,
 &sxpcm_beaver_sample_loop,
 &sxpcm_beaver_voice_count,
 &sxpcm_beaver_polyphony,
 &sxpcm_beaver_voice_range,
 &sxpcm_beaver_modulator_count,
 &sxpcm_beaver_oscillator_count,
 &sxpcm_beaver_insert_count,
 &sxpcm_beaver_type,
 &sxpcm_beaver_envelope,
 &sxpcm_beaver_lfo,
 &sxpcm_beaver_controller,
 &sxpcm_beaver_oscillator,
 &sxpcm_beaver_filter,
 &sxpcm_beaver_distortion,
 &sxpcm_beaver_delay,
 &sxpcm_beaver_chorus,
 &sxpcm_beaver_voice_modulation,
 &sxpcm_beaver_distortion_enabled,
 &sxpcm_beaver_arpeggio_enabled,
 &sxpcm_beaver_arpeggio_step,
 &sxpcm_beaver_arpeggio_timing,
 &sxpcm_beaver_mixer,
 &sxpcm_beaver_chain,
 &sxpcm_beaver_song_header,
 &sxpcm_beaver_channel_v102,
 &sxpcm_beaver_channel,
 &sxpcm_beaver_position_mask,
 &sxpcm_beaver_position_pattern,
 &sxpcm_beaver_position_transpose,
 &sxpcm_beaver_position_effect,
 &sxpcm_beaver_position_effect_parameter_1,
 &sxpcm_beaver_position_effect_parameter_2,
 &sxpcm_beaver_position_effect_parameter_3,
 &sxpcm_beaver_position_effect_parameter_4,
 &sxpcm_beaver_position_effect_parameter_5,
 &sxpcm_beaver_position_effect_parameter_6,
 &sxpcm_beaver_pattern_v102,
 &sxpcm_beaver_pattern,
 &sxpcm_beaver_pattern_row,
 &sxpcm_beaver_event,
};
#define SXPCM_LIMIT 24000U
static bool sxpcm_span(sx_context*c,uint64_t p,uint64_t n){return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
static bool sxpcm_read(sx_context*c,uint64_t p,void*b,size_t n){return sxpcm_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint16_t sxpcm16(const uint8_t*b){return (uint16_t)b[0]|(uint16_t)((uint16_t)b[1]<<8);}
static bool sxpcm_u16(sx_context*c,uint64_t p,uint16_t*v){uint8_t b[2];if(!sxpcm_read(c,p,b,2))return false;*v=sxpcm16(b);return true;}
static bool sxpcm_u8(sx_context*c,uint64_t p,uint8_t*v){return sxpcm_read(c,p,v,1);}
static bool sxpcm_eq(sx_context*c,uint64_t p,const char*s,size_t n){uint8_t b[64];return n<=sizeof(b)&&sxpcm_read(c,p,b,n)&&!xx_rt_memcmp(b,s,n);}
static uint64_t sxpcm_width(const sx_layout*l){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;return (uint64_t)f->rel_offset+(uint64_t)f->size;}
/* Insert only disjoint physical records. Shared pointers are decoded once;
 * conflicting interpretations remain covered by the first authenticated row.
 * Display-budget exhaustion retains earlier metadata and raw remainder. */
static bool sxpcm_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){
 uint64_t z=sxpcm_width(l);if(!count)return true;if(!z||count>UINT64_MAX/z||!sxpcm_span(c,p,count*z))return false;
 if(c->count>=SXPCM_LIMIT)return true;
 uint64_t end=p+count*z;
 for(size_t i=0;i<c->count;i++){int64_t rel=c->items[i].offset-c->f->base_address;uint64_t n=(uint64_t)c->items[i].total_size;
  if(rel>=0&&p<(uint64_t)rel+n&&(uint64_t)rel<end)return true;}
 return count==1?sx_add(c,l,(int64_t)p,(int64_t)z):sx_table(c,l,(int64_t)p,(int64_t)z,(int64_t)count);
}
#define SXPCM_ADD(c,n,p) sxpcm_put(c,&sxpcm_##n,p,1)
static bool sxpcm_opt(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){uint64_t z=sxpcm_width(l);return !count||!z||count>UINT64_MAX/z||!sxpcm_span(c,p,count*z)?true:sxpcm_put(c,l,p,count);}
static int sxpcm_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset;}
static bool sxpcm_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxpcm_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end||z<=0||p>c->size||z>c->size-p)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxpcm_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
/* Strings have dynamic physical width but share a genuine string-field layout. */
static bool sxpcm_string(sx_context*c,uint64_t p){uint8_t ch;uint64_t n=0;while(n<4096&&sxpcm_u8(c,p+n,&ch)){n++;if(!ch){if(c->count>=SXPCM_LIMIT)return true;for(size_t i=0;i<c->count;i++){uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<a+z&&a<p+n)return true;}return sx_add(c,&sxpcm_pc_text,(int64_t)p,(int64_t)n);}}return true;}
static bool sxpcm_lines(sx_context*c,const sx_layout*l,uint64_t p,unsigned count){return sxpcm_opt(c,l,p,count);}
static uint32_t sxpcm32(const uint8_t*b){return (uint32_t)b[0]|(uint32_t)b[1]<<8|(uint32_t)b[2]<<16|(uint32_t)b[3]<<24;}
static uint16_t sxpcmbe16(const uint8_t*b){return (uint16_t)((uint16_t)b[0]<<8)|b[1];}
static bool sxpcm_text(sx_context*c,uint64_t p,uint64_t n){
 if(!sxpcm_span(c,p,n))return false;if(!n||c->count>=SXPCM_LIMIT)return true;
 for(size_t i=0;i<c->count;i++){uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<a+z&&a<p+n)return true;}
 return sx_add(c,&sxpcm_pc_text,(int64_t)p,(int64_t)n);
}
static bool sxpcm_u32(sx_context*c,uint64_t p,uint32_t*v){uint8_t b[4];if(!sxpcm_read(c,p,b,4))return false;*v=sxpcm32(b);return true;}
/* Primary writers/loaders: DeFy/AdPlug dtm.cpp; Taylor FMTRACK.BAS;
 * XorJS FM.ASM; Beni BT18 loadmod and maintained AdPlug pis.cpp. */
static bool sxpcm_defy(sx_context*c){
 uint8_t h[55];if(!sxpcm_read(c,0,h,sizeof(h))||xx_rt_memcmp(h,"DeFy DTM ",9)||h[12]!=0x10)return false;
 if(!SXPCM_ADD(c,defy_header,0))return false;uint64_t p=55;uint8_t z;
 for(unsigned i=0;i<16;i++){if(!sxpcm_u8(c,p,&z)||z>80||!SXPCM_ADD(c,pc_u8_length,p++))return true;if(!sxpcm_text(c,p,z))return true;p+=z;}
 unsigned count=(unsigned)h[54]+1;if(count>128)return true;
 for(unsigned i=0;i<count;i++){if(!sxpcm_u8(c,p,&z)||z>=13||!SXPCM_ADD(c,pc_u8_length,p++))return true;if(!sxpcm_text(c,p,z))return true;p+=z;if(!SXPCM_ADD(c,defy_instrument,p))return true;p+=12;}
 if(!sxpcm_put(c,&sxpcm_pc_pattern_index,p,100))return true;p+=100;
 for(unsigned i=0;i<h[53];i++){uint16_t n;if(!sxpcm_u16(c,p,&n)||!SXPCM_ADD(c,pc_packed_pattern,p))return true;p+=2;if(!sxpcm_span(c,p,n))return true;p+=n;}
 return true;
}
static bool sxpcm_beni(sx_context*c){
 uint8_t h[3];if(!sxpcm_read(c,0,h,3)||!h[1]||h[1]>204||h[2]>31||!SXPCM_ADD(c,beni_header,0))return false;
 uint64_t p=3;if(!sxpcm_put(c,&sxpcm_beni_pattern_map,p,h[1]))return true;p+=h[1];if(!sxpcm_put(c,&sxpcm_beni_instrument_map,p,h[2]))return true;p+=h[2];
 if(!sxpcm_put(c,&sxpcm_pc_pattern_index,p,(uint64_t)h[0]*9))return true;p+=(uint64_t)h[0]*9;
 if(!sxpcm_put(c,&sxpcm_beni_event,p,(uint64_t)h[1]*64))return true;p+=(uint64_t)h[1]*192;
 if(!sxpcm_put(c,&sxpcm_beni_instrument,p,h[2]))return true;p+=(uint64_t)h[2]*11;
 if(sxpcm_eq(c,p,"B.J.",4))return SXPCM_ADD(c,beni_version,p);return true;
}
static bool sxpcm_taylor(sx_context*c){
 uint8_t n[3];if(!sxpcm_eq(c,0,"FMTracker",9)||!SXPCM_ADD(c,taylor_header,0))return false;
 if(!sxpcm_put(c,&sxpcm_taylor_instrument,63,8))return true;
 if(!sxpcm_read(c,215,n,3)||!SXPCM_ADD(c,taylor_counts,215))return true;uint64_t p=218,count=(unsigned)n[1]+1;
 if(!sxpcm_put(c,&sxpcm_pc_pattern_index,p,count))return true;p+=count;
 if(!sxpcm_put(c,&sxpcm_taylor_delay,p,count))return true;p+=count;
 return sxpcm_opt(c,&sxpcm_pc_pattern_index,p,(unsigned)n[2]+1);
}
static bool sxpcm_xorjs(sx_context*c){
 if(!sxpcm_eq(c,0,"JSR_FMT~",8)||!SXPCM_ADD(c,xorjs_header,0))return false;
 if(!sxpcm_put(c,&sxpcm_xorjs_instrument,10,256)||!sxpcm_put(c,&sxpcm_pc_pattern_index,9226,256))return true;
 uint8_t n;if(!sxpcm_u8(c,9482,&n)||!SXPCM_ADD(c,pc_pattern_count,9482))return true;uint64_t p=9483;
 for(unsigned i=0;i<n;i++){if(!SXPCM_ADD(c,pc_pattern_index,p++))return true;if(!sxpcm_put(c,&sxpcm_xorjs_event,p,64*18))return true;p+=64*18*3;}
 return true;
}
static bool sxpcm_mvs_name(sx_context*c,uint64_t*p){uint8_t b;uint64_t start=*p;for(unsigned i=0;i<256;i++){if(!sxpcm_u8(c,(*p)++,&b))return false;if(!b)return sxpcm_text(c,start,*p-start);}return false;}
static bool sxpcm_mvs(sx_context*c){
 if(!sxpcm_eq(c,0,"MVSM1",5)||!SXPCM_ADD(c,mvs_header,0))return false;uint64_t p=5;
 for(unsigned i=0;i<31;i++){if(!sxpcm_mvs_name(c,&p)||!SXPCM_ADD(c,mvs_instrument,p))return true;p+=25;}
 uint8_t n;if(!sxpcm_u8(c,p,&n)||!SXPCM_ADD(c,pc_order_count,p++))return true;if(n>64||!sxpcm_put(c,&sxpcm_pc_pattern_index,p,n))return true;p+=n;
 if(!sxpcm_u8(c,p,&n)||!SXPCM_ADD(c,pc_pattern_count,p++))return true;if(n>64)return true;
 for(unsigned i=0;i<n;i++){if(!sxpcm_mvs_name(c,&p)||!sxpcm_put(c,&sxpcm_mvs_event,p,256))return true;p+=1024;}
 return true;
}
static bool sxpcm_cyber(sx_context*c,bool instrument){
 uint8_t h[13];if(!sxpcm_read(c,0,h,13)||xx_rt_memcmp(h+2,instrument?"NNTRKINS":"NNTRKMZX",8)||h[11]!=1||h[10]>1||!SXPCM_ADD(c,cybertracker_header,0))return false;
 static const sx_layout*const module[]={&sxpcm_cybertracker_vibrato_depth,&sxpcm_cybertracker_vibrato_speed,&sxpcm_cybertracker_arpeggio,&sxpcm_cybertracker_adsr,&sxpcm_cybertracker_name,&sxpcm_cybertracker_multieffect,&sxpcm_cybertracker_song_length,&sxpcm_cybertracker_song_repeat,&sxpcm_cybertracker_loop_start,&sxpcm_cybertracker_x_low,&sxpcm_cybertracker_x_high,&sxpcm_cybertracker_y_low,&sxpcm_cybertracker_y_high,NULL,&sxpcm_cybertracker_pattern_length,&sxpcm_cybertracker_envelope_length,NULL};
 static const sx_layout*const inst[]={&sxpcm_cybertracker_vibrato,&sxpcm_cybertracker_arpeggio,&sxpcm_cybertracker_adsr,&sxpcm_cybertracker_name,&sxpcm_cybertracker_loop_start,&sxpcm_cybertracker_envelope_length,&sxpcm_cybertracker_x_low,&sxpcm_cybertracker_x_high,&sxpcm_cybertracker_y_low,&sxpcm_cybertracker_y_high};
 uint64_t p=13;for(unsigned i=0;i<h[12];i++){
  uint16_t n;if(!sxpcm_u16(c,p,&n)||!SXPCM_ADD(c,pc_u16_length,p))return true;p+=2;if(!sxpcm_span(c,p,n))return true;
  const sx_layout*l=instrument?(i<SX_COUNT(inst)?inst[i]:NULL):(i<SX_COUNT(module)?module[i]:NULL);
  if(l){uint64_t z=sxpcm_width(l);if(n%z==0&&!sxpcm_put(c,l,p,n/z))return false;}p+=n;
 }return true;
}
static bool sxpcm_vic(sx_context*c){
 uint8_t h[10];if(!sxpcm_read(c,0,h,10)||h[2]!='T'||h[3]!='1'||h[4]!=2||h[5]>1||!SXPCM_ADD(c,victracker_header,0))return false;
 if(!sxpcm_opt(c,&sxpcm_victracker_song,10,14)||!sxpcm_opt(c,&sxpcm_victracker_arpeggio,66,16)||!sxpcm_opt(c,&sxpcm_victracker_arpeggio_config,322,16)||!sxpcm_opt(c,&sxpcm_victracker_title,354,1)||!sxpcm_opt(c,&sxpcm_victracker_sound,450,16)||!sxpcm_opt(c,&sxpcm_victracker_reserved,578,1)||!sxpcm_opt(c,&sxpcm_victracker_sequence_length,706,256)||!sxpcm_opt(c,&sxpcm_victracker_sequence,962,5*256))return false;
 /* The producer writes256 complete32-row patterns. A truncated native identity
  * retains only physically complete events; no inferred logical samples. */
 if(c->size>2242){uint64_t count=((uint64_t)c->size-2242)/2;if(count>256*32)count=256*32;return sxpcm_put(c,&sxpcm_victracker_event,2242,count);}return true;
}
static bool sxpcm_muap(sx_context*c,bool tones){
 if(tones)return sxpcm_put(c,&sxpcm_muap_tone,0,256);
 return SXPCM_ADD(c,muap_header,0);
}
static bool sxpcm_pmd(sx_context*c){
 uint16_t first,p;if(!sxpcm_u16(c,1,&first)||(first!=0x18&&first!=0x1a)||!SXPCM_ADD(c,pmd_header,0))return false;
 if(first!=0x1a)return true;
 if(!sxpcm_u16(c,25,&p)||!SXPCM_ADD(c,pmd_program_pointer,25))return true;
 if(p<4)return true;uint64_t q=(uint64_t)p-3;uint8_t m[4];
 if(!sxpcm_read(c,q,m,4)||(m[2]!=0x40&&(m[2]<0x41||m[3]!=0xfe)))return true;
 if(!SXPCM_ADD(c,pmd_memo_header,q))return false;
 q=1+(uint64_t)sxpcm16(m);uint64_t end=(uint64_t)c->size;
 /* Memo-list terminator and earliest string target bound the pointer table.
  * No decoded audio/event positions are assigned physical coordinates. */
 for(unsigned i=0;i<256&&q<=end&&end-q>=2;i++,q+=2){uint16_t off;if(!sxpcm_u16(c,q,&off)||!SXPCM_ADD(c,pmd_memo_pointer,q))return true;if(!off)break;
  uint64_t target=(uint64_t)off+1;if(target<=q+1||target>=(uint64_t)c->size)break;if(target<end)end=target;
  if(!sxpcm_string(c,target))return false;
 }return true;
}
static bool sxpcm_toast_pattern(sx_context*c,uint64_t*p,unsigned channels){
 uint8_t present;if(!sxpcm_u8(c,*p,&present)||!SXPCM_ADD(c,pc_present,(*p)++))return false;if(!present)return true;
 /* The bytecode is not expanded. Its producer framing is used solely to locate
  * following physical records; invalid references leave this tail raw. */
 for(unsigned ch=0;ch<channels;ch++){
  unsigned row=0,work=0;while(row<64){uint8_t b,n,back;if(++work>65536||!sxpcm_u8(c,(*p)++,&b))return false;
   if(b&128){n=b&127;if(!n){row++;continue;}if(!sxpcm_u8(c,(*p)++,&back)||back>row||!back)return false;row+=n;if(row>64)row=64;
   }else{unsigned size=0;for(unsigned j=0;j<6;j++)size+=(b>>j)&1;if(!sxpcm_span(c,*p,size))return false;*p+=size;
    if(b&64){if(!sxpcm_u8(c,(*p)++,&n))return false;row+=n;if(row>64)row=64;}else row++;
   }
  }
 }return true;
}
static bool sxpcm_toast(sx_context*c,bool instrument){
 if(instrument){if(!sxpcm_eq(c,0,"T0ASTINS",8)||!SXPCM_ADD(c,toast_signature,0))return false;return sxpcm_opt(c,&sxpcm_toast_instrument,8,1);}
 bool modern=sxpcm_eq(c,0,"T0AST\1\0\1",8);if(!modern&&!sxpcm_eq(c,0,"T0AST0OK",8))return false;
 if(!SXPCM_ADD(c,toast_signature,0)||!SXPCM_ADD(c,toast_synth,8))return false;uint64_t p=568;
 if(modern){if(!SXPCM_ADD(c,toast_adsr,p))return true;p+=272;}
 uint8_t n,present;if(!sxpcm_u8(c,p+4,&n)||!SXPCM_ADD(c,toast_settings,p))return true;p+=5;if(n>16)return true;
 for(unsigned i=0;i<n;i++){if(!sxpcm_u8(c,p,&present)||!SXPCM_ADD(c,pc_present,p++))return true;if(present){if(!SXPCM_ADD(c,toast_channel,p))return true;p+=3;}}
 for(unsigned i=0;i<n;i++){if(!sxpcm_u8(c,p,&present)||!SXPCM_ADD(c,pc_present,p++))return true;if(present){if(!SXPCM_ADD(c,toast_instrument,p))return true;p+=25;}}
 uint16_t orders;if(!sxpcm_u16(c,p,&orders)||!SXPCM_ADD(c,toast_orders,p))return true;p+=2;if(orders>256||!sxpcm_put(c,&sxpcm_pc_pattern_index,p,orders))return true;p+=orders;
 for(unsigned i=0;i<256;i++)if(!sxpcm_toast_pattern(c,&p,n))return true;
 if(!SXPCM_ADD(c,toast_restart,p++))return true;
 for(unsigned i=0;i<3;i++){uint32_t length;if(!sxpcm_u32(c,p,&length)||!SXPCM_ADD(c,pc_u32_length,p))return true;p+=4;if(!sxpcm_text(c,p,length))return true;p+=length;}
 return true;
}
static bool sxpcm_axs(sx_context*c){
 uint8_t h[12];if(!sxpcm_read(c,0,h,12)||xx_rt_memcmp(h,"FORM",4)||xx_rt_memcmp(h+8,"AXSF",4)||!SXPCM_ADD(c,axs_form,0))return false;
 uint64_t end=8+((uint64_t)h[4]<<24|((uint64_t)h[5]<<16)|((uint64_t)h[6]<<8)|h[7]);if(end>(uint64_t)c->size)end=(uint64_t)c->size;uint64_t p=12;
 /* AXS chunks are not padded to even boundaries. Unknown payloads, including
  * synth parameters and sample bodies, retain their physical raw spans. */
 for(unsigned work=0;work<100000&&p<=end&&end-p>=8;work++){
  uint8_t b[8];if(!sxpcm_read(c,p,b,8)||!SXPCM_ADD(c,axs_chunk,p))return true;p+=8;
  uint64_t n=((uint64_t)b[4]<<24)|((uint64_t)b[5]<<16)|((uint64_t)b[6]<<8)|b[7];if(n>end-p)break;
  if(!xx_rt_memcmp(b,"USER",4)||!xx_rt_memcmp(b,"INNM",4)){if(!sxpcm_text(c,p,n))return false;}
  else if(!xx_rt_memcmp(b,"SHDR",4)&&n==20){if(!SXPCM_ADD(c,axs_settings,p))return false;}
  else if(!xx_rt_memcmp(b,"SONG",4)&&n%8==0){if(!sxpcm_put(c,&sxpcm_axs_sequence,p,n/8))return false;}
  else if(!xx_rt_memcmp(b,"TRAK",4)&&n==256){if(!sxpcm_put(c,&sxpcm_axs_event,p,64))return false;}
  p+=n;
 }return true;
}
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
static bool sx_pcmusic_supports(xx_file_type_t t){switch(t){
 case XX_FILE_TYPE_DIE_MUSIC_CYBERBRAIN_CYBERTRACKER:
 case XX_FILE_TYPE_DIE_MUSIC_CYBERBRAIN_CYBERTRACKER_CI:
 case XX_FILE_TYPE_DIE_MUSIC_DEFY_ADLIBTRACKER_DTM:
 case XX_FILE_TYPE_DIE_MUSIC_TAYLOR_FMTRACKER:
 case XX_FILE_TYPE_DIE_MUSIC_XORJS_FMTRACKER:
 case XX_FILE_TYPE_DIE_MUSIC_PACKEN_MUAP98_TONESDTA:
 case XX_FILE_TYPE_DIE_MUSIC_BERO_T0AST:
 case XX_FILE_TYPE_DIE_MUSIC_BERO_TOAST_INS:
 case XX_FILE_TYPE_DIE_MUSIC_KAHLIN_VICTRACKER:
 case XX_FILE_TYPE_DIE_MUSIC_KAJAPON_PROFESSIONALMD_M:
 case XX_FILE_TYPE_DIE_MUSIC_PACKEN_MUAP98_OBJECT:
 case XX_FILE_TYPE_DIE_MUSIC_SPP_BENITRACKERADLIB_PIS:
 case XX_FILE_TYPE_DIE_MUSIC_KANEDA_MVSTRACKERSUITE_MUS:
 case XX_FILE_TYPE_DIE_MUSIC_RESOLUTION_AXS:
 case XX_FILE_TYPE_DIE_MUSIC_GNILK_BEAVERSWEEPER_GTK:
 return true;default:return false;}}
static bool sx_pcmusic_build(sx_context*c){bool ok=false;switch(c->f->file_type){
 case XX_FILE_TYPE_DIE_MUSIC_CYBERBRAIN_CYBERTRACKER:ok=sxpcm_cyber(c,false);break;
 case XX_FILE_TYPE_DIE_MUSIC_CYBERBRAIN_CYBERTRACKER_CI:ok=sxpcm_cyber(c,true);break;
 case XX_FILE_TYPE_DIE_MUSIC_DEFY_ADLIBTRACKER_DTM:ok=sxpcm_defy(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_TAYLOR_FMTRACKER:ok=sxpcm_taylor(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_XORJS_FMTRACKER:ok=sxpcm_xorjs(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_PACKEN_MUAP98_TONESDTA:ok=sxpcm_muap(c,true);break;
 case XX_FILE_TYPE_DIE_MUSIC_BERO_T0AST:ok=sxpcm_toast(c,false);break;
 case XX_FILE_TYPE_DIE_MUSIC_BERO_TOAST_INS:ok=sxpcm_toast(c,true);break;
 case XX_FILE_TYPE_DIE_MUSIC_KAHLIN_VICTRACKER:ok=sxpcm_vic(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_KAJAPON_PROFESSIONALMD_M:ok=sxpcm_pmd(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_PACKEN_MUAP98_OBJECT:ok=sxpcm_muap(c,false);break;
 case XX_FILE_TYPE_DIE_MUSIC_SPP_BENITRACKERADLIB_PIS:ok=sxpcm_beni(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_KANEDA_MVSTRACKERSUITE_MUS:ok=sxpcm_mvs(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_RESOLUTION_AXS:ok=sxpcm_axs(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_GNILK_BEAVERSWEEPER_GTK:ok=sxpcm_beaver(c);break;
 default:return false;} (void)ok;return c->count&&sxpcm_finish(c);}
static bool sx_pcmusic_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60940000U||id>=0x60950000U)return true;
 if(id==sxpcm_defy_header.id&&!xx_rt_wcscmp(r->name,L"instrument_last_index"))return xx_data_struct_record_set_comment(r,L"Stored instrument count minus one; the producer reserves a default instrument for each of nine channels.");
 if(id==sxpcm_taylor_counts.id&&!xx_rt_wcscmp(r->name,L"pattern_rows_minus_one"))return xx_data_struct_record_set_comment(r,L"Stored count minus one; add one for the corresponding row/order/pattern count.");
 if(id==sxpcm_taylor_counts.id&&!xx_rt_wcscmp(r->name,L"order_count_minus_one"))return xx_data_struct_record_set_comment(r,L"Stored count minus one; add one for the corresponding row/order/pattern count.");
 if(id==sxpcm_taylor_counts.id&&!xx_rt_wcscmp(r->name,L"pattern_count_minus_one"))return xx_data_struct_record_set_comment(r,L"Stored count minus one; add one for the corresponding row/order/pattern count.");
 if(id==sxpcm_cybertracker_loop_start.id&&!xx_rt_wcscmp(r->name,L"loop_point"))return xx_data_struct_record_set_comment(r,L"Zero-based envelope point index; 0xFF disables looping.");
 if(id==sxpcm_cybertracker_x_low.id&&!xx_rt_wcscmp(r->name,L"x_low"))return xx_data_struct_record_set_comment(r,L"Stored low byte plane of the envelope x coordinate; combine with the corresponding plane without changing source bytes.");
 if(id==sxpcm_cybertracker_x_high.id&&!xx_rt_wcscmp(r->name,L"x_high"))return xx_data_struct_record_set_comment(r,L"Stored high byte plane of the envelope x coordinate; combine with the corresponding plane without changing source bytes.");
 if(id==sxpcm_cybertracker_y_low.id&&!xx_rt_wcscmp(r->name,L"y_low"))return xx_data_struct_record_set_comment(r,L"Stored low byte plane of the envelope y coordinate; combine with the corresponding plane without changing source bytes.");
 if(id==sxpcm_cybertracker_y_high.id&&!xx_rt_wcscmp(r->name,L"y_high"))return xx_data_struct_record_set_comment(r,L"Stored high byte plane of the envelope y coordinate; combine with the corresponding plane without changing source bytes.");
 if(id==sxpcm_cybertracker_pattern_length.id&&!xx_rt_wcscmp(r->name,L"encoded_pattern_byte_length"))return xx_data_struct_record_set_comment(r,L"Number of saved pattern-memory bytes, as defined by the original Cybertracker1.01 format guide; not a row count.");
 if(id==sxpcm_victracker_song.id&&!xx_rt_wcscmp(r->name,L"last_step"))return xx_data_struct_record_set_comment(r,L"Inclusive last sequence step, not a count.");
 if(id==sxpcm_victracker_song.id&&!xx_rt_wcscmp(r->name,L"speed_flags"))return xx_data_struct_record_set_comment(r,L"Low six bits are initial speed; high two bits select loop, repeat or one-shot behavior.");
 if(id==sxpcm_victracker_sequence_length.id&&!xx_rt_wcscmp(r->name,L"last_row_index"))return xx_data_struct_record_set_comment(r,L"Inclusive last row index; the producer iterates rows zero through this value (maximum31).");
 if(id==sxpcm_muap_header.id&&!xx_rt_wcscmp(r->name,L"channel_offsets"))return xx_data_struct_record_set_comment(r,L"Seventeen stored module-relative byte offsets into channel bytecode; the original player supports FM, SSG, rhythm and expanded channels.");
 if(id==sxpcm_pmd_memo_header.id&&!xx_rt_wcscmp(r->name,L"driver_marker"))return xx_data_struct_record_set_comment(r,L"Version0x40 does not validate this byte; later supported versions require marker0xFE.");
 if(id==sxpcm_pmd_header.id&&!xx_rt_wcscmp(r->name,L"fm_channel_offsets"))return xx_data_struct_record_set_comment(r,L"Stored byte offset relative to module byte 1, immediately after target_mode; not relative to the field or absolute device origin.");
 if(id==sxpcm_pmd_header.id&&!xx_rt_wcscmp(r->name,L"ssg_channel_offsets"))return xx_data_struct_record_set_comment(r,L"Stored byte offset relative to module byte 1, immediately after target_mode; not relative to the field or absolute device origin.");
 if(id==sxpcm_pmd_header.id&&!xx_rt_wcscmp(r->name,L"adpcm_channel_offset"))return xx_data_struct_record_set_comment(r,L"Stored byte offset relative to module byte 1, immediately after target_mode; not relative to the field or absolute device origin.");
 if(id==sxpcm_pmd_header.id&&!xx_rt_wcscmp(r->name,L"rhythm_channel_offset"))return xx_data_struct_record_set_comment(r,L"Stored byte offset relative to module byte 1, immediately after target_mode; not relative to the field or absolute device origin.");
 if(id==sxpcm_pmd_header.id&&!xx_rt_wcscmp(r->name,L"rhythm_table_offset"))return xx_data_struct_record_set_comment(r,L"Stored byte offset relative to module byte 1, immediately after target_mode; not relative to the field or absolute device origin.");
 if(id==sxpcm_pmd_program_pointer.id&&!xx_rt_wcscmp(r->name,L"program_offset"))return xx_data_struct_record_set_comment(r,L"Stored byte offset relative to module byte 1, immediately after target_mode; not relative to the field or absolute device origin.");
 if(id==sxpcm_pmd_memo_header.id&&!xx_rt_wcscmp(r->name,L"memo_table_offset"))return xx_data_struct_record_set_comment(r,L"Stored byte offset relative to module byte 1, immediately after target_mode; not relative to the field or absolute device origin.");
 if(id==sxpcm_pmd_memo_pointer.id&&!xx_rt_wcscmp(r->name,L"string_offset"))return xx_data_struct_record_set_comment(r,L"Stored byte offset relative to module byte 1, immediately after target_mode; not relative to the field or absolute device origin.");
 if(id==sxpcm_toast_synth.id&&!xx_rt_wcscmp(r->name,L"event_offset"))return xx_data_struct_record_set_comment(r,L"Signed synthesizer parameter offset; this is not a byte offset into the source file.");
 if(id==sxpcm_toast_synth.id&&!xx_rt_wcscmp(r->name,L"note_offset"))return xx_data_struct_record_set_comment(r,L"Signed synthesizer parameter offset; this is not a byte offset into the source file.");
 if(id==sxpcm_toast_synth.id&&!xx_rt_wcscmp(r->name,L"volume_offset"))return xx_data_struct_record_set_comment(r,L"Signed synthesizer parameter offset; this is not a byte offset into the source file.");
 if(id==sxpcm_toast_instrument.id&&!xx_rt_wcscmp(r->name,L"name_storage"))return xx_data_struct_record_set_comment(r,L"Pascal shortstring stores up to24 bytes; name_length selects meaningful bytes and remaining storage is preserved.");
 if(id==sxpcm_mvs_event.id&&!xx_rt_wcscmp(r->name,L"octave_and_note"))return xx_data_struct_record_set_comment(r,L"Low nibble is serialized note code, high nibble the adjusted octave; C decrements the stored octave, and byte0 is blank.");
 if(id==sxpcm_mvs_event.id&&!xx_rt_wcscmp(r->name,L"instrument"))return xx_data_struct_record_set_comment(r,L"Physical0xFF represents the editor's absent-instrument sentinel (-1).");
 if(id==sxpcm_axs_form.id&&!xx_rt_wcscmp(r->name,L"form_byte_size"))return xx_data_struct_record_set_comment(r,L"Bytes following the8-byte FORM prefix, including theAXSF form type.");
 if(id==sxpcm_axs_settings.id&&!xx_rt_wcscmp(r->name,L"sync_flags"))return xx_data_struct_record_set_comment(r,L"Original AXS Check identifies0 as disabled and0x40 as enabled.");
 if(id==sxpcm_axs_settings.id&&!xx_rt_wcscmp(r->name,L"delay_fraction_code"))return xx_data_struct_record_set_comment(r,L"Original parser maps codes1..6 to quarter-note fractions1/4,1/3,2/4,2/3,3/4,4/4.");
 if(id==sxpcm_axs_settings.id&&!xx_rt_wcscmp(r->name,L"delay_5ms_units"))return xx_data_struct_record_set_comment(r,L"Stored delay in units of5milliseconds; physical value is not multiplied.");
 if(id==sxpcm_axs_sequence.id&&!xx_rt_wcscmp(r->name,L"disabled_channel_mask"))return xx_data_struct_record_set_comment(r,L"Original parser treats a set bit as channel disabled; sixteen channel bits, little-endian.");
 if(id==sxpcm_beaver_sample_flags.id&&!xx_rt_wcscmp(r->name,L"sample_flags"))return xx_data_struct_record_set_comment(r,L"Bit0 stores an embedded16-bit mono sample; bit1 enables looping and bit2 ping-pong looping.");
 if(id==sxpcm_beaver_song_header.id&&!xx_rt_wcscmp(r->name,L"sequence_tick_units"))return xx_data_struct_record_set_comment(r,L"Stored unit is sixteen sequence ticks; the original player computes def_seqtick=16*internal_seqtick.");
 if(id==sxpcm_beaver_arpeggio_step.id&&!xx_rt_wcscmp(r->name,L"note_indexes"))return xx_data_struct_record_set_comment(r,L"Indexes into the currently held-note list:0 is its first note and0xFF means no note; these are not voice indexes.");
 if(r->property&SX_OFFSET)return xx_data_struct_record_set_comment(r,L"Stored byte offset relative to the module start, unless the enclosing structure specifies another origin.");
 if(r->property&SX_ADDRESS)return xx_data_struct_record_set_comment(r,L"Encoded target-machine memory address; the field source-file offset is shown separately.");
 return true;
}
