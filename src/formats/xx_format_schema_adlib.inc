/* SPDX-License-Identifier: MIT
 * Physical AdLib-family layouts; native-supported variants only.
 * Original bounded schemas based on native readers and upstream wire-field facts.
 * Scope and references: docs/data_struct_adlib_scope.txt. */
static const xx_data_struct_field_desc sxad_adlib_rad_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version","uint8_t",16,1,SX_NONE),
    SX_FIELD("flags","uint8_t",17,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_rad_header = {UINT32_C(0x600f0001),"adlib_rad_header",sxad_adlib_rad_header_fields,SX_COUNT(sxad_adlib_rad_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rad_instrument_fields[] = {
    SX_FIELD("instrument_number","uint8_t",0,1,SX_ID),
    SX_FIELD("modulator_characteristics","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",9,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",10,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",11,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_rad_instrument = {UINT32_C(0x600f0002),"adlib_rad_instrument",sxad_adlib_rad_instrument_fields,SX_COUNT(sxad_adlib_rad_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_instrument_end_fields[] = {
    SX_FIELD("terminator","uint8_t",0,1,SX_SIGNATURE),
};
static const sx_layout sxad_adlib_instrument_end = {UINT32_C(0x600f0003),"adlib_instrument_end",sxad_adlib_instrument_end_fields,SX_COUNT(sxad_adlib_instrument_end_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rad_order_count_fields[] = {
    SX_FIELD("order_count","uint8_t",0,1,SX_COUNT_PROP),
};
static const sx_layout sxad_adlib_rad_order_count = {UINT32_C(0x600f0004),"adlib_rad_order_count",sxad_adlib_rad_order_count_fields,SX_COUNT(sxad_adlib_rad_order_count_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rad_order_fields[] = {
    SX_FIELD("pattern_or_jump","uint8_t",0,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_rad_order = {UINT32_C(0x600f0005),"adlib_rad_order",sxad_adlib_rad_order_fields,SX_COUNT(sxad_adlib_rad_order_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rad_pattern_offset_fields[] = {
    SX_FIELD("pattern_offset","uint16_t",0,2,SX_OFFSET),
};
static const sx_layout sxad_adlib_rad_pattern_offset = {UINT32_C(0x600f0006),"adlib_rad_pattern_offset",sxad_adlib_rad_pattern_offset_fields,SX_COUNT(sxad_adlib_rad_pattern_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rad_row_fields[] = {
    SX_FIELD("row_flags","uint8_t",0,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_rad_row = {UINT32_C(0x600f0007),"adlib_rad_row",sxad_adlib_rad_row_fields,SX_COUNT(sxad_adlib_rad_row_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rad_event_fields[] = {
    SX_FIELD("channel_flags","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("note_octave","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("instrument_effect","uint8_t",2,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_rad_event = {UINT32_C(0x600f0008),"adlib_rad_event",sxad_adlib_rad_event_fields,SX_COUNT(sxad_adlib_rad_event_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rad_effect_event_fields[] = {
    SX_FIELD("channel_flags","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("note_octave","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("instrument_effect","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("effect_parameter","uint8_t",3,1,SX_NONE),
};
static const sx_layout sxad_adlib_rad_effect_event = {UINT32_C(0x600f0009),"adlib_rad_effect_event",sxad_adlib_rad_effect_event_fields,SX_COUNT(sxad_adlib_rad_effect_event_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_hsc_instrument_fields[] = {
    SX_FIELD("carrier_characteristics","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("modulator_characteristics","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",9,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",10,1,SX_FLAGS),
    SX_FIELD("slide_encoded","uint8_t",11,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_hsc_instrument = {UINT32_C(0x600f000a),"adlib_hsc_instrument",sxad_adlib_hsc_instrument_fields,SX_COUNT(sxad_adlib_hsc_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_hsc_order_fields[] = {
    SX_FIELD("pattern_or_jump_or_end","uint8_t",0,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_hsc_order = {UINT32_C(0x600f000b),"adlib_hsc_order",sxad_adlib_hsc_order_fields,SX_COUNT(sxad_adlib_hsc_order_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_hsc_event_fields[] = {
    SX_FIELD("note_or_instrument","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("effect_or_instrument","uint8_t",1,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_hsc_event = {UINT32_C(0x600f000c),"adlib_hsc_event",sxad_adlib_hsc_event_fields,SX_COUNT(sxad_adlib_hsc_event_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_zero_terminator_fields[] = {
    SX_FIELD("terminator","uint8_t",0,1,SX_SIGNATURE),
};
static const sx_layout sxad_adlib_zero_terminator = {UINT32_C(0x600f000d),"adlib_zero_terminator",sxad_adlib_zero_terminator_fields,SX_COUNT(sxad_adlib_zero_terminator_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_d00_header_fields[] = {
    SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
    SX_FIELD("type","uint8_t",6,1,SX_NONE),
    SX_FIELD("version","uint8_t",7,1,SX_NONE),
    SX_FIELD("speed_hz","uint8_t",8,1,SX_NONE),
    SX_FIELD("subsong_count","uint8_t",9,1,SX_COUNT_PROP),
    SX_FIELD("sound_card","uint8_t",10,1,SX_NONE),
    SX_FIELD("song_name","char[32]",11,32,SX_STRING),
    SX_FIELD("author","char[32]",43,32,SX_STRING),
    SX_FIELD("reserved","uint8_t[32]",75,32,SX_RESERVED),
    SX_FIELD("subsong_table_offset","uint16_t",107,2,SX_OFFSET),
    SX_FIELD("sequence_index_offset","uint16_t",109,2,SX_OFFSET),
    SX_FIELD("instrument_table_offset","uint16_t",111,2,SX_OFFSET),
    SX_FIELD("data_info_offset","uint16_t",113,2,SX_OFFSET),
    SX_FIELD("special_effects_offset","uint16_t",115,2,SX_OFFSET),
    SX_FIELD("end_marker","uint16_t",117,2,SX_SIGNATURE),
};
static const sx_layout sxad_adlib_d00_header = {UINT32_C(0x600f000e),"adlib_d00_header",sxad_adlib_d00_header_fields,SX_COUNT(sxad_adlib_d00_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_d00_subsong_fields[] = {
    SX_FIELD("channel0_order_offset","uint16_t",0,2,SX_OFFSET),
    SX_FIELD("channel1_order_offset","uint16_t",2,2,SX_OFFSET),
    SX_FIELD("channel2_order_offset","uint16_t",4,2,SX_OFFSET),
    SX_FIELD("channel3_order_offset","uint16_t",6,2,SX_OFFSET),
    SX_FIELD("channel4_order_offset","uint16_t",8,2,SX_OFFSET),
    SX_FIELD("channel5_order_offset","uint16_t",10,2,SX_OFFSET),
    SX_FIELD("channel6_order_offset","uint16_t",12,2,SX_OFFSET),
    SX_FIELD("channel7_order_offset","uint16_t",14,2,SX_OFFSET),
    SX_FIELD("channel8_order_offset","uint16_t",16,2,SX_OFFSET),
    SX_FIELD("channel0_volume_flags","uint8_t",18,1,SX_FLAGS),
    SX_FIELD("channel1_volume_flags","uint8_t",19,1,SX_FLAGS),
    SX_FIELD("channel2_volume_flags","uint8_t",20,1,SX_FLAGS),
    SX_FIELD("channel3_volume_flags","uint8_t",21,1,SX_FLAGS),
    SX_FIELD("channel4_volume_flags","uint8_t",22,1,SX_FLAGS),
    SX_FIELD("channel5_volume_flags","uint8_t",23,1,SX_FLAGS),
    SX_FIELD("channel6_volume_flags","uint8_t",24,1,SX_FLAGS),
    SX_FIELD("channel7_volume_flags","uint8_t",25,1,SX_FLAGS),
    SX_FIELD("channel8_volume_flags","uint8_t",26,1,SX_FLAGS),
    SX_FIELD("reserved","uint8_t[5]",27,5,SX_RESERVED),
};
static const sx_layout sxad_adlib_d00_subsong = {UINT32_C(0x600f000f),"adlib_d00_subsong",sxad_adlib_d00_subsong_fields,SX_COUNT(sxad_adlib_d00_subsong_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_d00_order_header_fields[] = {
    SX_FIELD("channel_speed","uint16_t",0,2,SX_NONE),
};
static const sx_layout sxad_adlib_d00_order_header = {UINT32_C(0x600f0010),"adlib_d00_order_header",sxad_adlib_d00_order_header_fields,SX_COUNT(sxad_adlib_d00_order_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_d00_order_word_fields[] = {
    SX_FIELD("order_word","uint16_t",0,2,SX_FLAGS),
};
static const sx_layout sxad_adlib_d00_order_word = {UINT32_C(0x600f0011),"adlib_d00_order_word",sxad_adlib_d00_order_word_fields,SX_COUNT(sxad_adlib_d00_order_word_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_d00_sequence_offset_fields[] = {
    SX_FIELD("sequence_offset","uint16_t",0,2,SX_OFFSET),
};
static const sx_layout sxad_adlib_d00_sequence_offset = {UINT32_C(0x600f0012),"adlib_d00_sequence_offset",sxad_adlib_d00_sequence_offset_fields,SX_COUNT(sxad_adlib_d00_sequence_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_d00_sequence_word_fields[] = {
    SX_FIELD("event_word","uint16_t",0,2,SX_FLAGS),
};
static const sx_layout sxad_adlib_d00_sequence_word = {UINT32_C(0x600f0013),"adlib_d00_sequence_word",sxad_adlib_d00_sequence_word_fields,SX_COUNT(sxad_adlib_d00_sequence_word_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_d00_instrument_fields[] = {
    SX_FIELD("carrier_attack_decay","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("modulator_characteristics","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",9,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",10,1,SX_FLAGS),
    SX_FIELD("tune_level","uint8_t",11,1,SX_FLAGS),
    SX_FIELD("timer","uint8_t",12,1,SX_NONE),
    SX_FIELD("sustain_release","uint8_t",13,1,SX_FLAGS),
    SX_FIELD("reserved","uint8_t[2]",14,2,SX_RESERVED),
};
static const sx_layout sxad_adlib_d00_instrument = {UINT32_C(0x600f0014),"adlib_d00_instrument",sxad_adlib_d00_instrument_fields,SX_COUNT(sxad_adlib_d00_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_d00_data_info_end_fields[] = {
    SX_FIELD("terminator","uint16_t",0,2,SX_SIGNATURE),
};
static const sx_layout sxad_adlib_d00_data_info_end = {UINT32_C(0x600f0015),"adlib_d00_data_info_end",sxad_adlib_d00_data_info_end_fields,SX_COUNT(sxad_adlib_d00_data_info_end_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bnk_header_fields[] = {
    SX_FIELD("version_major","uint8_t",0,1,SX_NONE),
    SX_FIELD("version_minor","uint8_t",1,1,SX_NONE),
    SX_FIELD("signature","char[6]",2,6,SX_SIGNATURE),
    SX_FIELD("used_entry_count","uint16_t",8,2,SX_COUNT_PROP),
    SX_FIELD("total_entry_count","uint16_t",10,2,SX_COUNT_PROP),
    SX_FIELD("name_list_offset","uint32_t",12,4,SX_OFFSET),
    SX_FIELD("instrument_data_offset","uint32_t",16,4,SX_OFFSET),
};
static const sx_layout sxad_adlib_bnk_header = {UINT32_C(0x600f0016),"adlib_bnk_header",sxad_adlib_bnk_header_fields,SX_COUNT(sxad_adlib_bnk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bnk_name_fields[] = {
    SX_FIELD("instrument_index","uint16_t",0,2,SX_ID),
    SX_FIELD("record_used","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("name","char[9]",3,9,SX_STRING),
};
static const sx_layout sxad_adlib_bnk_name = {UINT32_C(0x600f0017),"adlib_bnk_name",sxad_adlib_bnk_name_fields,SX_COUNT(sxad_adlib_bnk_name_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bnk_instrument_fields[] = {
    SX_FIELD("mode","uint8_t",0,1,SX_NONE),
    SX_FIELD("voice_number","uint8_t",1,1,SX_NONE),
    SX_FIELD("modulator_key_scale_level","uint8_t",2,1,SX_NONE),
    SX_FIELD("modulator_frequency_multiplier","uint8_t",3,1,SX_NONE),
    SX_FIELD("modulator_feedback","uint8_t",4,1,SX_NONE),
    SX_FIELD("modulator_attack_rate","uint8_t",5,1,SX_NONE),
    SX_FIELD("modulator_sustain_level","uint8_t",6,1,SX_NONE),
    SX_FIELD("modulator_sustaining_sound","uint8_t",7,1,SX_NONE),
    SX_FIELD("modulator_decay_rate","uint8_t",8,1,SX_NONE),
    SX_FIELD("modulator_release_rate","uint8_t",9,1,SX_NONE),
    SX_FIELD("modulator_output_level","uint8_t",10,1,SX_NONE),
    SX_FIELD("modulator_amplitude_vibrato","uint8_t",11,1,SX_NONE),
    SX_FIELD("modulator_frequency_vibrato","uint8_t",12,1,SX_NONE),
    SX_FIELD("modulator_envelope_scaling","uint8_t",13,1,SX_NONE),
    SX_FIELD("modulator_fm_type","uint8_t",14,1,SX_NONE),
    SX_FIELD("carrier_key_scale_level","uint8_t",15,1,SX_NONE),
    SX_FIELD("carrier_frequency_multiplier","uint8_t",16,1,SX_NONE),
    SX_FIELD("carrier_feedback","uint8_t",17,1,SX_NONE),
    SX_FIELD("carrier_attack_rate","uint8_t",18,1,SX_NONE),
    SX_FIELD("carrier_sustain_level","uint8_t",19,1,SX_NONE),
    SX_FIELD("carrier_sustaining_sound","uint8_t",20,1,SX_NONE),
    SX_FIELD("carrier_decay_rate","uint8_t",21,1,SX_NONE),
    SX_FIELD("carrier_release_rate","uint8_t",22,1,SX_NONE),
    SX_FIELD("carrier_output_level","uint8_t",23,1,SX_NONE),
    SX_FIELD("carrier_amplitude_vibrato","uint8_t",24,1,SX_NONE),
    SX_FIELD("carrier_frequency_vibrato","uint8_t",25,1,SX_NONE),
    SX_FIELD("carrier_envelope_scaling","uint8_t",26,1,SX_NONE),
    SX_FIELD("carrier_fm_type","uint8_t",27,1,SX_NONE),
    SX_FIELD("modulator_waveform","uint8_t",28,1,SX_NONE),
    SX_FIELD("carrier_waveform","uint8_t",29,1,SX_NONE),
};
static const sx_layout sxad_adlib_bnk_instrument = {UINT32_C(0x600f0018),"adlib_bnk_instrument",sxad_adlib_bnk_instrument_fields,SX_COUNT(sxad_adlib_bnk_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bam_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxad_adlib_bam_header = {UINT32_C(0x600f0019),"adlib_bam_header",sxad_adlib_bam_header_fields,SX_COUNT(sxad_adlib_bam_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bam_command_fields[] = {
    SX_FIELD("command_channel","uint8_t",0,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_bam_command = {UINT32_C(0x600f001a),"adlib_bam_command",sxad_adlib_bam_command_fields,SX_COUNT(sxad_adlib_bam_command_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bam_note_fields[] = {
    SX_FIELD("command_channel","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("note","uint8_t",1,1,SX_NONE),
};
static const sx_layout sxad_adlib_bam_note = {UINT32_C(0x600f001b),"adlib_bam_note",sxad_adlib_bam_note_fields,SX_COUNT(sxad_adlib_bam_note_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bam_instrument_fields[] = {
    SX_FIELD("command_channel","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("modulator_characteristics","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",9,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",10,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",11,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_bam_instrument = {UINT32_C(0x600f001c),"adlib_bam_instrument",sxad_adlib_bam_instrument_fields,SX_COUNT(sxad_adlib_bam_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bam_jump_fields[] = {
    SX_FIELD("command_label","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("repeat_mode","uint8_t",1,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_bam_jump = {UINT32_C(0x600f001d),"adlib_bam_jump",sxad_adlib_bam_jump_fields,SX_COUNT(sxad_adlib_bam_jump_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bmf_signature_fields[] = {
    SX_FIELD("signature_version","char[6]",0,6,SX_SIGNATURE),
};
static const sx_layout sxad_adlib_bmf_signature = {UINT32_C(0x600f001e),"adlib_bmf_signature",sxad_adlib_bmf_signature_fields,SX_COUNT(sxad_adlib_bmf_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bmf_settings_fields[] = {
    SX_FIELD("speed","uint8_t",0,1,SX_NONE),
    SX_FIELD("instrument_mask","uint32_t",1,4,SX_FLAGS),
};
static const sx_layout sxad_adlib_bmf_settings = {UINT32_C(0x600f001f),"adlib_bmf_settings",sxad_adlib_bmf_settings_fields,SX_COUNT(sxad_adlib_bmf_settings_fields),SX_BE};
static const xx_data_struct_field_desc sxad_adlib_bmf_instrument_fields[] = {
    SX_FIELD("name","char[11]",0,11,SX_STRING),
    SX_FIELD("modulator_characteristics","uint8_t",11,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",12,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",13,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",14,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",15,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",16,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",17,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",18,1,SX_FLAGS),
    SX_FIELD("frequency_low","uint8_t",19,1,SX_FLAGS),
    SX_FIELD("frequency_high_key","uint8_t",20,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",21,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",22,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",23,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_bmf_instrument = {UINT32_C(0x600f0020),"adlib_bmf_instrument",sxad_adlib_bmf_instrument_fields,SX_COUNT(sxad_adlib_bmf_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bmf_stream_flags_fields[] = {
    SX_FIELD("channel_mask","uint32_t",0,4,SX_FLAGS),
};
static const sx_layout sxad_adlib_bmf_stream_flags = {UINT32_C(0x600f0021),"adlib_bmf_stream_flags",sxad_adlib_bmf_stream_flags_fields,SX_COUNT(sxad_adlib_bmf_stream_flags_fields),SX_BE};
static const xx_data_struct_field_desc sxad_adlib_bmf_note_or_control_fields[] = {
    SX_FIELD("note_or_control","uint8_t",0,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_bmf_note_or_control = {UINT32_C(0x600f0022),"adlib_bmf_note_or_control",sxad_adlib_bmf_note_or_control_fields,SX_COUNT(sxad_adlib_bmf_note_or_control_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bmf_loop_fields[] = {
    SX_FIELD("command","uint8_t",0,1,SX_ID),
    SX_FIELD("repeat_count_encoded","uint8_t",1,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_bmf_loop = {UINT32_C(0x600f0023),"adlib_bmf_loop",sxad_adlib_bmf_loop_fields,SX_COUNT(sxad_adlib_bmf_loop_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bmf_note_delay_fields[] = {
    SX_FIELD("note_flags","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("delay_flags","uint8_t",1,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_bmf_note_delay = {UINT32_C(0x600f0024),"adlib_bmf_note_delay",sxad_adlib_bmf_note_delay_fields,SX_COUNT(sxad_adlib_bmf_note_delay_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bmf_note_command_fields[] = {
    SX_FIELD("note_flags","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("command","uint8_t",1,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_bmf_note_command = {UINT32_C(0x600f0025),"adlib_bmf_note_command",sxad_adlib_bmf_note_command_fields,SX_COUNT(sxad_adlib_bmf_note_command_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_bmf_note_delay_command_fields[] = {
    SX_FIELD("note_flags","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("delay_flags","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("command","uint8_t",2,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_bmf_note_delay_command = {UINT32_C(0x600f0026),"adlib_bmf_note_delay_command",sxad_adlib_bmf_note_delay_command_fields,SX_COUNT(sxad_adlib_bmf_note_delay_command_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_dfm_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version_major","uint8_t",4,1,SX_NONE),
    SX_FIELD("version_minor","uint8_t",5,1,SX_NONE),
    SX_FIELD("title_length","uint8_t",6,1,SX_COUNT_PROP),
    SX_FIELD("title","char[32]",7,32,SX_STRING),
    SX_FIELD("initial_speed","uint8_t",39,1,SX_NONE),
};
static const sx_layout sxad_adlib_dfm_header = {UINT32_C(0x600f0027),"adlib_dfm_header",sxad_adlib_dfm_header_fields,SX_COUNT(sxad_adlib_dfm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_dfm_instrument_name_fields[] = {
    SX_FIELD("name_length","uint8_t",0,1,SX_COUNT_PROP),
    SX_FIELD("name","char[11]",1,11,SX_STRING),
};
static const sx_layout sxad_adlib_dfm_instrument_name = {UINT32_C(0x600f0028),"adlib_dfm_instrument_name",sxad_adlib_dfm_instrument_name_fields,SX_COUNT(sxad_adlib_dfm_instrument_name_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_dfm_instrument_fields[] = {
    SX_FIELD("modulator_characteristics","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",9,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",10,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_dfm_instrument = {UINT32_C(0x600f0029),"adlib_dfm_instrument",sxad_adlib_dfm_instrument_fields,SX_COUNT(sxad_adlib_dfm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_dfm_order_fields[] = {
    SX_FIELD("pattern_or_end","uint8_t",0,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_dfm_order = {UINT32_C(0x600f002a),"adlib_dfm_order",sxad_adlib_dfm_order_fields,SX_COUNT(sxad_adlib_dfm_order_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_dfm_pattern_count_fields[] = {
    SX_FIELD("pattern_count","uint8_t",0,1,SX_COUNT_PROP),
};
static const sx_layout sxad_adlib_dfm_pattern_count = {UINT32_C(0x600f002b),"adlib_dfm_pattern_count",sxad_adlib_dfm_pattern_count_fields,SX_COUNT(sxad_adlib_dfm_pattern_count_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_dfm_pattern_header_fields[] = {
    SX_FIELD("pattern_id","uint8_t",0,1,SX_ID),
};
static const sx_layout sxad_adlib_dfm_pattern_header = {UINT32_C(0x600f002c),"adlib_dfm_pattern_header",sxad_adlib_dfm_pattern_header_fields,SX_COUNT(sxad_adlib_dfm_pattern_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_dfm_note_fields[] = {
    SX_FIELD("note_flags","uint8_t",0,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_dfm_note = {UINT32_C(0x600f002d),"adlib_dfm_note",sxad_adlib_dfm_note_fields,SX_COUNT(sxad_adlib_dfm_note_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_dfm_note_effect_fields[] = {
    SX_FIELD("note_flags","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("effect_parameter","uint8_t",1,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_dfm_note_effect = {UINT32_C(0x600f002e),"adlib_dfm_note_effect",sxad_adlib_dfm_note_effect_fields,SX_COUNT(sxad_adlib_dfm_note_effect_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_lds_header_fields[] = {
    SX_FIELD("mode","uint8_t",0,1,SX_NONE),
    SX_FIELD("timer_divisor","uint16_t",1,2,SX_NONE),
    SX_FIELD("tempo","uint8_t",3,1,SX_NONE),
    SX_FIELD("pattern_row_count","uint8_t",4,1,SX_COUNT_PROP),
    SX_FIELD("channel0_delay","uint8_t",5,1,SX_NONE),
    SX_FIELD("channel1_delay","uint8_t",6,1,SX_NONE),
    SX_FIELD("channel2_delay","uint8_t",7,1,SX_NONE),
    SX_FIELD("channel3_delay","uint8_t",8,1,SX_NONE),
    SX_FIELD("channel4_delay","uint8_t",9,1,SX_NONE),
    SX_FIELD("channel5_delay","uint8_t",10,1,SX_NONE),
    SX_FIELD("channel6_delay","uint8_t",11,1,SX_NONE),
    SX_FIELD("channel7_delay","uint8_t",12,1,SX_NONE),
    SX_FIELD("channel8_delay","uint8_t",13,1,SX_NONE),
    SX_FIELD("rhythm_register","uint8_t",14,1,SX_FLAGS),
    SX_FIELD("patch_count","uint16_t",15,2,SX_COUNT_PROP),
};
static const sx_layout sxad_adlib_lds_header = {UINT32_C(0x600f002f),"adlib_lds_header",sxad_adlib_lds_header_fields,SX_COUNT(sxad_adlib_lds_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_lds_patch_fields[] = {
    SX_FIELD("modulator_characteristics","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",9,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",10,1,SX_FLAGS),
    SX_FIELD("key_off","uint8_t",11,1,SX_NONE),
    SX_FIELD("portamento","uint8_t",12,1,SX_NONE),
    SX_FIELD("glide","uint8_t",13,1,SX_NONE),
    SX_FIELD("fine_tune","uint8_t",14,1,SX_NONE),
    SX_FIELD("vibrato","uint8_t",15,1,SX_FLAGS),
    SX_FIELD("vibrato_delay","uint8_t",16,1,SX_NONE),
    SX_FIELD("modulator_tremolo","uint8_t",17,1,SX_FLAGS),
    SX_FIELD("carrier_tremolo","uint8_t",18,1,SX_FLAGS),
    SX_FIELD("tremolo_wait","uint8_t",19,1,SX_NONE),
    SX_FIELD("arpeggio","uint8_t",20,1,SX_FLAGS),
    SX_FIELD("arpeggio_table","uint8_t[12]",21,12,SX_NONE),
    SX_FIELD("digital_start","uint16_t",33,2,SX_NONE),
    SX_FIELD("digital_size","uint16_t",35,2,SX_NONE),
    SX_FIELD("fms","uint8_t",37,1,SX_NONE),
    SX_FIELD("transpose","uint16_t",38,2,SX_NONE),
    SX_FIELD("midi_instrument","uint8_t",40,1,SX_ID),
    SX_FIELD("midi_velocity","uint8_t",41,1,SX_NONE),
    SX_FIELD("midi_key","uint8_t",42,1,SX_NONE),
    SX_FIELD("midi_transpose","uint8_t",43,1,SX_NONE),
    SX_FIELD("midi_reserved","uint8_t[2]",44,2,SX_RESERVED),
};
static const sx_layout sxad_adlib_lds_patch = {UINT32_C(0x600f0030),"adlib_lds_patch",sxad_adlib_lds_patch_fields,SX_COUNT(sxad_adlib_lds_patch_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_lds_position_count_fields[] = {
    SX_FIELD("position_count","uint16_t",0,2,SX_COUNT_PROP),
};
static const sx_layout sxad_adlib_lds_position_count = {UINT32_C(0x600f0031),"adlib_lds_position_count",sxad_adlib_lds_position_count_fields,SX_COUNT(sxad_adlib_lds_position_count_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_lds_position_fields[] = {
    SX_FIELD("pattern_offset","uint16_t",0,2,SX_OFFSET),
    SX_FIELD("transpose_flags","uint8_t",2,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_lds_position = {UINT32_C(0x600f0032),"adlib_lds_position",sxad_adlib_lds_position_fields,SX_COUNT(sxad_adlib_lds_position_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_lds_digital_count_fields[] = {
    SX_FIELD("digital_sound_count","uint16_t",0,2,SX_COUNT_PROP),
};
static const sx_layout sxad_adlib_lds_digital_count = {UINT32_C(0x600f0033),"adlib_lds_digital_count",sxad_adlib_lds_digital_count_fields,SX_COUNT(sxad_adlib_lds_digital_count_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_lds_pattern_word_fields[] = {
    SX_FIELD("event_word","uint16_t",0,2,SX_FLAGS),
};
static const sx_layout sxad_adlib_lds_pattern_word = {UINT32_C(0x600f0034),"adlib_lds_pattern_word",sxad_adlib_lds_pattern_word_fields,SX_COUNT(sxad_adlib_lds_pattern_word_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_header_fields[] = {
    SX_FIELD("version_minor","uint16_t",0,2,SX_NONE),
    SX_FIELD("version_major","uint16_t",2,2,SX_NONE),
    SX_FIELD("comment","char[40]",4,40,SX_STRING),
    SX_FIELD("ticks_per_beat","uint16_t",44,2,SX_NONE),
    SX_FIELD("beats_per_measure","uint16_t",46,2,SX_NONE),
    SX_FIELD("edit_scale_y","uint16_t",48,2,SX_NONE),
    SX_FIELD("edit_scale_x","uint16_t",50,2,SX_NONE),
    SX_FIELD("unused1","uint8_t[1]",52,1,SX_RESERVED),
    SX_FIELD("melodic_mode","uint8_t",53,1,SX_FLAGS),
    SX_FIELD("unused2","uint8_t[90]",54,90,SX_RESERVED),
    SX_FIELD("filler0","uint8_t[38]",144,38,SX_RESERVED),
    SX_FIELD("filler1","uint8_t[15]",182,15,SX_RESERVED),
    SX_FIELD("basic_tempo","float32",197,4,SX_NONE),
};
static const sx_layout sxad_adlib_rol_header = {UINT32_C(0x600f0035),"adlib_rol_header",sxad_adlib_rol_header_fields,SX_COUNT(sxad_adlib_rol_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_tempo_count_fields[] = {
    SX_FIELD("tempo_event_count","uint16_t",0,2,SX_COUNT_PROP),
};
static const sx_layout sxad_adlib_rol_tempo_count = {UINT32_C(0x600f0036),"adlib_rol_tempo_count",sxad_adlib_rol_tempo_count_fields,SX_COUNT(sxad_adlib_rol_tempo_count_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_tempo_event_fields[] = {
    SX_FIELD("tick","int16",0,2,SX_NONE),
    SX_FIELD("tempo_multiplier","float32",2,4,SX_NONE),
};
static const sx_layout sxad_adlib_rol_tempo_event = {UINT32_C(0x600f0037),"adlib_rol_tempo_event",sxad_adlib_rol_tempo_event_fields,SX_COUNT(sxad_adlib_rol_tempo_event_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_note_header_fields[] = {
    SX_FIELD("filler","uint8_t[15]",0,15,SX_RESERVED),
    SX_FIELD("total_ticks","int16",15,2,SX_NONE),
};
static const sx_layout sxad_adlib_rol_note_header = {UINT32_C(0x600f0038),"adlib_rol_note_header",sxad_adlib_rol_note_header_fields,SX_COUNT(sxad_adlib_rol_note_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_note_event_fields[] = {
    SX_FIELD("note","int16",0,2,SX_NONE),
    SX_FIELD("duration_ticks","int16",2,2,SX_NONE),
};
static const sx_layout sxad_adlib_rol_note_event = {UINT32_C(0x600f0039),"adlib_rol_note_event",sxad_adlib_rol_note_event_fields,SX_COUNT(sxad_adlib_rol_note_event_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_event_header_fields[] = {
    SX_FIELD("filler","uint8_t[15]",0,15,SX_RESERVED),
    SX_FIELD("event_count","uint16_t",15,2,SX_COUNT_PROP),
};
static const sx_layout sxad_adlib_rol_event_header = {UINT32_C(0x600f003a),"adlib_rol_event_header",sxad_adlib_rol_event_header_fields,SX_COUNT(sxad_adlib_rol_event_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_instrument_event_fields[] = {
    SX_FIELD("tick","int16",0,2,SX_NONE),
    SX_FIELD("instrument_name","char[9]",2,9,SX_STRING),
    SX_FIELD("filler","uint8_t[1]",11,1,SX_RESERVED),
    SX_FIELD("unused","uint8_t[2]",12,2,SX_RESERVED),
};
static const sx_layout sxad_adlib_rol_instrument_event = {UINT32_C(0x600f003b),"adlib_rol_instrument_event",sxad_adlib_rol_instrument_event_fields,SX_COUNT(sxad_adlib_rol_instrument_event_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_volume_event_fields[] = {
    SX_FIELD("tick","int16",0,2,SX_NONE),
    SX_FIELD("volume_multiplier","float32",2,4,SX_NONE),
};
static const sx_layout sxad_adlib_rol_volume_event = {UINT32_C(0x600f003c),"adlib_rol_volume_event",sxad_adlib_rol_volume_event_fields,SX_COUNT(sxad_adlib_rol_volume_event_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_rol_pitch_event_fields[] = {
    SX_FIELD("tick","int16",0,2,SX_NONE),
    SX_FIELD("pitch_variation","float32",2,4,SX_NONE),
};
static const sx_layout sxad_adlib_rol_pitch_event = {UINT32_C(0x600f003d),"adlib_rol_pitch_event",sxad_adlib_rol_pitch_event_fields,SX_COUNT(sxad_adlib_rol_pitch_event_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_jbm_header_fields[] = {
    SX_FIELD("format_marker","uint16_t",0,2,SX_SIGNATURE),
    SX_FIELD("timer_divisor","uint16_t",2,2,SX_NONE),
    SX_FIELD("sequence_table_offset","uint16_t",4,2,SX_OFFSET),
    SX_FIELD("instrument_table_offset","uint16_t",6,2,SX_OFFSET),
    SX_FIELD("flags","uint16_t",8,2,SX_FLAGS),
    SX_FIELD("voice0_order_offset","uint16_t",10,2,SX_OFFSET),
    SX_FIELD("voice1_order_offset","uint16_t",12,2,SX_OFFSET),
    SX_FIELD("voice2_order_offset","uint16_t",14,2,SX_OFFSET),
    SX_FIELD("voice3_order_offset","uint16_t",16,2,SX_OFFSET),
    SX_FIELD("voice4_order_offset","uint16_t",18,2,SX_OFFSET),
    SX_FIELD("voice5_order_offset","uint16_t",20,2,SX_OFFSET),
    SX_FIELD("voice6_order_offset","uint16_t",22,2,SX_OFFSET),
    SX_FIELD("voice7_order_offset","uint16_t",24,2,SX_OFFSET),
    SX_FIELD("voice8_order_offset","uint16_t",26,2,SX_OFFSET),
    SX_FIELD("voice9_order_offset","uint16_t",28,2,SX_OFFSET),
    SX_FIELD("voice10_order_offset","uint16_t",30,2,SX_OFFSET),
};
static const sx_layout sxad_adlib_jbm_header = {UINT32_C(0x600f003e),"adlib_jbm_header",sxad_adlib_jbm_header_fields,SX_COUNT(sxad_adlib_jbm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_jbm_sequence_offset_fields[] = {
    SX_FIELD("sequence_offset","uint16_t",0,2,SX_OFFSET),
};
static const sx_layout sxad_adlib_jbm_sequence_offset = {UINT32_C(0x600f003f),"adlib_jbm_sequence_offset",sxad_adlib_jbm_sequence_offset_fields,SX_COUNT(sxad_adlib_jbm_sequence_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_jbm_order_fields[] = {
    SX_FIELD("sequence_or_end","uint8_t",0,1,SX_FLAGS),
};
static const sx_layout sxad_adlib_jbm_order = {UINT32_C(0x600f0040),"adlib_jbm_order",sxad_adlib_jbm_order_fields,SX_COUNT(sxad_adlib_jbm_order_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_jbm_end_fields[] = {
    SX_FIELD("terminator","uint8_t",0,1,SX_SIGNATURE),
};
static const sx_layout sxad_adlib_jbm_end = {UINT32_C(0x600f0041),"adlib_jbm_end",sxad_adlib_jbm_end_fields,SX_COUNT(sxad_adlib_jbm_end_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_jbm_instrument_select_fields[] = {
    SX_FIELD("command","uint8_t",0,1,SX_ID),
    SX_FIELD("instrument_index","uint8_t",1,1,SX_ID),
};
static const sx_layout sxad_adlib_jbm_instrument_select = {UINT32_C(0x600f0042),"adlib_jbm_instrument_select",sxad_adlib_jbm_instrument_select_fields,SX_COUNT(sxad_adlib_jbm_instrument_select_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_jbm_note_fields[] = {
    SX_FIELD("note_flags","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("volume","uint8_t",1,1,SX_NONE),
    SX_FIELD("delay_minus_one","uint16_t",2,2,SX_NONE),
};
static const sx_layout sxad_adlib_jbm_note = {UINT32_C(0x600f0043),"adlib_jbm_note",sxad_adlib_jbm_note_fields,SX_COUNT(sxad_adlib_jbm_note_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_jbm_instrument_fields[] = {
    SX_FIELD("modulator_characteristics","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level_encoded","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level_encoded","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("waveforms_feedback","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("unused","uint8_t[7]",9,7,SX_RESERVED),
};
static const sx_layout sxad_adlib_jbm_instrument = {UINT32_C(0x600f0044),"adlib_jbm_instrument",sxad_adlib_jbm_instrument_fields,SX_COUNT(sxad_adlib_jbm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_xsm_header_fields[] = {
    SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
    SX_FIELD("notes_per_channel","uint16_t",6,2,SX_COUNT_PROP),
};
static const sx_layout sxad_adlib_xsm_header = {UINT32_C(0x600f0045),"adlib_xsm_header",sxad_adlib_xsm_header_fields,SX_COUNT(sxad_adlib_xsm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_xsm_instrument_fields[] = {
    SX_FIELD("modulator_characteristics","uint8_t",0,1,SX_FLAGS),
    SX_FIELD("carrier_characteristics","uint8_t",1,1,SX_FLAGS),
    SX_FIELD("modulator_scale_level","uint8_t",2,1,SX_FLAGS),
    SX_FIELD("carrier_scale_level","uint8_t",3,1,SX_FLAGS),
    SX_FIELD("modulator_attack_decay","uint8_t",4,1,SX_FLAGS),
    SX_FIELD("carrier_attack_decay","uint8_t",5,1,SX_FLAGS),
    SX_FIELD("modulator_sustain_release","uint8_t",6,1,SX_FLAGS),
    SX_FIELD("carrier_sustain_release","uint8_t",7,1,SX_FLAGS),
    SX_FIELD("modulator_waveform","uint8_t",8,1,SX_FLAGS),
    SX_FIELD("carrier_waveform","uint8_t",9,1,SX_FLAGS),
    SX_FIELD("feedback_connection","uint8_t",10,1,SX_FLAGS),
    SX_FIELD("unused","uint8_t[5]",11,5,SX_RESERVED),
};
static const sx_layout sxad_adlib_xsm_instrument = {UINT32_C(0x600f0046),"adlib_xsm_instrument",sxad_adlib_xsm_instrument_fields,SX_COUNT(sxad_adlib_xsm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_xsm_note_fields[] = {
    SX_FIELD("note","uint8_t",0,1,SX_NONE),
};
static const sx_layout sxad_adlib_xsm_note = {UINT32_C(0x600f0047),"adlib_xsm_note",sxad_adlib_xsm_note_fields,SX_COUNT(sxad_adlib_xsm_note_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_ksm_header_fields[] = {
    SX_FIELD("track_instruments","uint8_t[16]",0,16,SX_NONE),
    SX_FIELD("track_quantization","uint8_t[16]",16,16,SX_NONE),
    SX_FIELD("track_channel_counts","uint8_t[16]",32,16,SX_NONE),
    SX_FIELD("reserved","uint8_t[16]",48,16,SX_RESERVED),
    SX_FIELD("track_volumes","uint8_t[16]",64,16,SX_NONE),
    SX_FIELD("event_count","uint16_t",80,2,SX_COUNT_PROP),
};
static const sx_layout sxad_adlib_ksm_header = {UINT32_C(0x600f0048),"adlib_ksm_header",sxad_adlib_ksm_header_fields,SX_COUNT(sxad_adlib_ksm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_ksm_event_fields[] = {
    SX_FIELD("packed_note_event","uint32_t",0,4,SX_FLAGS),
};
static const sx_layout sxad_adlib_ksm_event = {UINT32_C(0x600f0049),"adlib_ksm_event",sxad_adlib_ksm_event_fields,SX_COUNT(sxad_adlib_ksm_event_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_raw_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("timer_divisor","uint16_t",8,2,SX_NONE),
};
static const sx_layout sxad_adlib_raw_header = {UINT32_C(0x600f004a),"adlib_raw_header",sxad_adlib_raw_header_fields,SX_COUNT(sxad_adlib_raw_header_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_raw_command_fields[] = {
    SX_FIELD("value","uint8_t",0,1,SX_NONE),
    SX_FIELD("register_or_command","uint8_t",1,1,SX_ID),
};
static const sx_layout sxad_adlib_raw_command = {UINT32_C(0x600f004b),"adlib_raw_command",sxad_adlib_raw_command_fields,SX_COUNT(sxad_adlib_raw_command_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_raw_timer_fields[] = {
    SX_FIELD("value","uint8_t",0,1,SX_NONE),
    SX_FIELD("command","uint8_t",1,1,SX_ID),
    SX_FIELD("timer_divisor","uint16_t",2,2,SX_NONE),
};
static const sx_layout sxad_adlib_raw_timer = {UINT32_C(0x600f004c),"adlib_raw_timer",sxad_adlib_raw_timer_fields,SX_COUNT(sxad_adlib_raw_timer_fields),SX_LE};
static const xx_data_struct_field_desc sxad_adlib_raw_metadata_tag_fields[] = {
    SX_FIELD("tag","uint8_t",0,1,SX_ID),
};
static const sx_layout sxad_adlib_raw_metadata_tag = {UINT32_C(0x600f004d),"adlib_raw_metadata_tag",sxad_adlib_raw_metadata_tag_fields,SX_COUNT(sxad_adlib_raw_metadata_tag_fields),SX_LE};
static const sx_layout *const sx_adlib_layouts[] = {
    &sxad_adlib_rad_header,
    &sxad_adlib_rad_instrument,
    &sxad_adlib_instrument_end,
    &sxad_adlib_rad_order_count,
    &sxad_adlib_rad_order,
    &sxad_adlib_rad_pattern_offset,
    &sxad_adlib_rad_row,
    &sxad_adlib_rad_event,
    &sxad_adlib_rad_effect_event,
    &sxad_adlib_hsc_instrument,
    &sxad_adlib_hsc_order,
    &sxad_adlib_hsc_event,
    &sxad_adlib_zero_terminator,
    &sxad_adlib_d00_header,
    &sxad_adlib_d00_subsong,
    &sxad_adlib_d00_order_header,
    &sxad_adlib_d00_order_word,
    &sxad_adlib_d00_sequence_offset,
    &sxad_adlib_d00_sequence_word,
    &sxad_adlib_d00_instrument,
    &sxad_adlib_d00_data_info_end,
    &sxad_adlib_bnk_header,
    &sxad_adlib_bnk_name,
    &sxad_adlib_bnk_instrument,
    &sxad_adlib_bam_header,
    &sxad_adlib_bam_command,
    &sxad_adlib_bam_note,
    &sxad_adlib_bam_instrument,
    &sxad_adlib_bam_jump,
    &sxad_adlib_bmf_signature,
    &sxad_adlib_bmf_settings,
    &sxad_adlib_bmf_instrument,
    &sxad_adlib_bmf_stream_flags,
    &sxad_adlib_bmf_note_or_control,
    &sxad_adlib_bmf_loop,
    &sxad_adlib_bmf_note_delay,
    &sxad_adlib_bmf_note_command,
    &sxad_adlib_bmf_note_delay_command,
    &sxad_adlib_dfm_header,
    &sxad_adlib_dfm_instrument_name,
    &sxad_adlib_dfm_instrument,
    &sxad_adlib_dfm_order,
    &sxad_adlib_dfm_pattern_count,
    &sxad_adlib_dfm_pattern_header,
    &sxad_adlib_dfm_note,
    &sxad_adlib_dfm_note_effect,
    &sxad_adlib_lds_header,
    &sxad_adlib_lds_patch,
    &sxad_adlib_lds_position_count,
    &sxad_adlib_lds_position,
    &sxad_adlib_lds_digital_count,
    &sxad_adlib_lds_pattern_word,
    &sxad_adlib_rol_header,
    &sxad_adlib_rol_tempo_count,
    &sxad_adlib_rol_tempo_event,
    &sxad_adlib_rol_note_header,
    &sxad_adlib_rol_note_event,
    &sxad_adlib_rol_event_header,
    &sxad_adlib_rol_instrument_event,
    &sxad_adlib_rol_volume_event,
    &sxad_adlib_rol_pitch_event,
    &sxad_adlib_jbm_header,
    &sxad_adlib_jbm_sequence_offset,
    &sxad_adlib_jbm_order,
    &sxad_adlib_jbm_end,
    &sxad_adlib_jbm_instrument_select,
    &sxad_adlib_jbm_note,
    &sxad_adlib_jbm_instrument,
    &sxad_adlib_xsm_header,
    &sxad_adlib_xsm_instrument,
    &sxad_adlib_xsm_note,
    &sxad_adlib_ksm_header,
    &sxad_adlib_ksm_event,
    &sxad_adlib_raw_header,
    &sxad_adlib_raw_command,
    &sxad_adlib_raw_timer,
    &sxad_adlib_raw_metadata_tag,
};
static bool sx_adlib_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<UINT32_C(0x600f0000)||id>=UINT32_C(0x60100000))return true;
    const wchar_t *comment=NULL;
    switch(id){
    case UINT32_C(0x600f0001):
        if(!xx_rt_wcscmp(r->name,L"flags"))comment=L"Low five bits: initial speed; bit6: slow timer; bit7: description present. Native reader accepts RAD1.0 only.";
        break;
    case UINT32_C(0x600f0005):
        if(!xx_rt_wcscmp(r->name,L"pattern_or_jump"))comment=L"Bit7 selects a jump to the low7-bit order index; otherwise a pattern number.";
        break;
    case UINT32_C(0x600f0006):
        if(!xx_rt_wcscmp(r->name,L"pattern_offset"))comment=L"Byte offset from the beginning of the RAD file; zero means absent.";
        break;
    case UINT32_C(0x600f0007):
        if(!xx_rt_wcscmp(r->name,L"row_flags"))comment=L"Bits0..6: row number; bit7: last row in this pattern.";
        break;
    case UINT32_C(0x600f0008):
        if(!xx_rt_wcscmp(r->name,L"channel_flags"))comment=L"Low nibble: channel; bit7: final channel entry in the row.";
        if(!xx_rt_wcscmp(r->name,L"note_octave"))comment=L"Low4 bits: note; bits4..6: octave; bit7 supplies instrument bit4.";
        if(!xx_rt_wcscmp(r->name,L"instrument_effect"))comment=L"Instrument and effect selector bits; nonzero low nibble has a following parameter.";
        break;
    case UINT32_C(0x600f0009):
        if(!xx_rt_wcscmp(r->name,L"channel_flags"))comment=L"Low nibble: channel; bit7: final channel entry in the row.";
        if(!xx_rt_wcscmp(r->name,L"note_octave"))comment=L"Low4 bits: note; bits4..6: octave; bit7 supplies instrument bit4.";
        if(!xx_rt_wcscmp(r->name,L"instrument_effect"))comment=L"Instrument and effect selector bits; nonzero low nibble has a following parameter.";
        break;
    case UINT32_C(0x600f000a):
        if(!xx_rt_wcscmp(r->name,L"carrier_characteristics"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"modulator_characteristics"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"carrier_scale_level"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"modulator_scale_level"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"carrier_attack_decay"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"modulator_attack_decay"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"carrier_sustain_release"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"modulator_sustain_release"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"feedback_connection"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"carrier_waveform"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"modulator_waveform"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        if(!xx_rt_wcscmp(r->name,L"slide_encoded"))comment=L"Encoded HSC instrument byte; slide uses the high nibble, and scale-level bits require HSC conversion.";
        break;
    case UINT32_C(0x600f000b):
        if(!xx_rt_wcscmp(r->name,L"pattern_or_jump_or_end"))comment=L"0..127: pattern; bit7: order jump; values0xB2..0xFF end the order list.";
        break;
    case UINT32_C(0x600f000c):
        if(!xx_rt_wcscmp(r->name,L"note_or_instrument"))comment=L"Bit7 selects an instrument-change event; otherwise a note, with127 for key-off.";
        if(!xx_rt_wcscmp(r->name,L"effect_or_instrument"))comment=L"Instrument index when byte0 bit7 is set; otherwise packed effect and parameter.";
        break;
    case UINT32_C(0x600f0011):
        if(!xx_rt_wcscmp(r->name,L"order_word"))comment=L"Sequence index, transpose command,0xFFFE end,0xFFFF loop, or loop target word according to position.";
        break;
    case UINT32_C(0x600f0013):
        if(!xx_rt_wcscmp(r->name,L"event_word"))comment=L"Encoded D00 event/effect word;0xFFFF terminates the sequence. Playback/effect expansion is outside the schema.";
        break;
    case UINT32_C(0x600f001a):
        if(!xx_rt_wcscmp(r->name,L"command_channel"))comment=L"High nibble: command; low nibble: channel/label. Bytes>=0x80 encode delay.";
        break;
    case UINT32_C(0x600f001c):
        if(!xx_rt_wcscmp(r->name,L"modulator_characteristics"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_characteristics"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_scale_level"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_scale_level"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_attack_decay"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_attack_decay"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_sustain_release"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_sustain_release"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_waveform"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_waveform"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"feedback_connection"))comment=L"Encoded OPL2 register value.";
        break;
    case UINT32_C(0x600f001d):
        if(!xx_rt_wcscmp(r->name,L"repeat_mode"))comment=L"0: end loop;254: endless;255: chorus; other values: repetition count.";
        break;
    case UINT32_C(0x600f001f):
        if(!xx_rt_wcscmp(r->name,L"instrument_mask"))comment=L"Bits31..0 indicate which of32 instrument records are present.";
        break;
    case UINT32_C(0x600f0021):
        if(!xx_rt_wcscmp(r->name,L"channel_mask"))comment=L"Bits31..23 indicate which of9 channel streams are present.";
        break;
    case UINT32_C(0x600f0022):
        if(!xx_rt_wcscmp(r->name,L"note_or_control"))comment=L"0xFE ends stream;0x7D loops; ordinary values encode a note and optional-field bit.";
        break;
    case UINT32_C(0x600f0023):
        if(!xx_rt_wcscmp(r->name,L"repeat_count_encoded"))comment=L"Low6 bits encode repeat count; playback decrements by one.";
        break;
    case UINT32_C(0x600f0024):
        if(!xx_rt_wcscmp(r->name,L"delay_flags"))comment=L"Low6 bits: delay; bit7 indicates delay; bit6 announces a following command.";
        break;
    case UINT32_C(0x600f0025):
        if(!xx_rt_wcscmp(r->name,L"command"))comment=L"0x20..0x3F select instrument;0x40..0x7F select volume.";
        break;
    case UINT32_C(0x600f002a):
        if(!xx_rt_wcscmp(r->name,L"pattern_or_end"))comment=L"0x80 ends the order list; preceding values index stored patterns.";
        break;
    case UINT32_C(0x600f002d):
        if(!xx_rt_wcscmp(r->name,L"note_flags"))comment=L"Packed octave/note; bit7 announces an effect byte, low nibble0xF is key-off.";
        break;
    case UINT32_C(0x600f002e):
        if(!xx_rt_wcscmp(r->name,L"effect_parameter"))comment=L"Top3 bits: effect selector; low5 bits: parameter or instrument index.";
        break;
    case UINT32_C(0x600f0030):
        if(!xx_rt_wcscmp(r->name,L"digital_start"))comment=L"Encoded digital-sound parameter, ignored by the native FM reader; no address/unit conversion is inferred.";
        if(!xx_rt_wcscmp(r->name,L"digital_size"))comment=L"Encoded digital-sound parameter ignored by the native FM reader; no byte-size unit is inferred.";
        break;
    case UINT32_C(0x600f0032):
        if(!xx_rt_wcscmp(r->name,L"pattern_offset"))comment=L"Byte offset from the pattern-word pool; physical value is even.";
        if(!xx_rt_wcscmp(r->name,L"transpose_flags"))comment=L"Bit7 selects instrument transposition; bits0..6 encode a signed7-bit transpose.";
        break;
    case UINT32_C(0x600f0034):
        if(!xx_rt_wcscmp(r->name,L"event_word"))comment=L"Encoded note/instrument or command word; duration/loop semantics remain encoded.";
        break;
    case UINT32_C(0x600f003e):
        if(!xx_rt_wcscmp(r->name,L"flags"))comment=L"Bit0 selects AdLib rhythm mode.";
        break;
    case UINT32_C(0x600f0040):
        if(!xx_rt_wcscmp(r->name,L"sequence_or_end"))comment=L"0xFF ends a voice order list; other values index the sequence table.";
        break;
    case UINT32_C(0x600f0043):
        if(!xx_rt_wcscmp(r->name,L"note_flags"))comment=L"Low7 bits: note; bit7: key-off.";
        if(!xx_rt_wcscmp(r->name,L"delay_minus_one"))comment=L"Encoded duration; playback adds one tick.";
        break;
    case UINT32_C(0x600f0044):
        if(!xx_rt_wcscmp(r->name,L"modulator_characteristics"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"modulator_scale_level_encoded"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"modulator_attack_decay"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"modulator_sustain_release"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"carrier_characteristics"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"carrier_scale_level_encoded"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"carrier_attack_decay"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"carrier_sustain_release"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        if(!xx_rt_wcscmp(r->name,L"waveforms_feedback"))comment=L"Encoded JBM OPL value; scale-level bytes invert low6 output bits; byte8 packs both waveforms and feedback.";
        break;
    case UINT32_C(0x600f0046):
        if(!xx_rt_wcscmp(r->name,L"modulator_characteristics"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_characteristics"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_scale_level"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_scale_level"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_attack_decay"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_attack_decay"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_sustain_release"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_sustain_release"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"modulator_waveform"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"carrier_waveform"))comment=L"Encoded OPL2 register value.";
        if(!xx_rt_wcscmp(r->name,L"feedback_connection"))comment=L"Encoded OPL2 register value.";
        break;
    case UINT32_C(0x600f0049):
        if(!xx_rt_wcscmp(r->name,L"packed_note_event"))comment=L"Bits0..5: note;6..7: note/volume action;8..11: track;12..31: event tick. Not a wall-clock timestamp.";
        break;
    case UINT32_C(0x600f004b):
        if(!xx_rt_wcscmp(r->name,L"register_or_command"))comment=L"0: delay;2: timer/chip control;other values: OPL register;0xFFFF pair ends stream.";
        break;
    case UINT32_C(0x600f004d):
        if(!xx_rt_wcscmp(r->name,L"tag"))comment=L"0x1A title;0x1B author;0x1C description; following NUL-terminated bytes remain raw.";
        break;
    default: break;
    }
    return !comment||xx_data_struct_record_set_comment(r,comment);
}

/* All offsets are relative to the original device base. No reader factories or
 * playback are invoked. The native reader validates supported variants; these
 * walkers independently bound every physical record, count and pointer. */
static bool sxad_byte(sx_context *c,int64_t at,uint8_t *v){return sx_read(c,at,v,1);}
static bool sxad_tag(sx_context *c,int64_t at,const char *tag,size_t n)
{
    uint8_t b[16];return n<=sizeof(b)&&sx_read(c,at,b,n)&&!xx_rt_memcmp(b,tag,n);
}
static bool sxad_zraw(sx_context *c,int64_t *at,size_t limit)
{
    int64_t start=*at;uint8_t v;
    for(size_t i=0;i<limit;i++){if(!sxad_byte(c,*at,&v))return false;(*at)++;if(!v)return sx_raw(c,start,*at-start);}return false;
}
static bool sxad_header(sx_context *c,const sx_layout *l,int64_t *at,int64_t size)
{
    if(!sx_add(c,l,*at,size))return false;*at+=size;return true;
}
/* Pointer-bearing streams can alias a complete previously emitted span, but
 * must not overlap unrelated physical fields. Sequential walkers need no scan. */
static int sxad_overlap(sx_context *c,int64_t off,int64_t size)
{
    if(off<0||size<=0||off>c->size||size>c->size-off)return -1;
    for(size_t i=0;i<c->count;i++){
        const xx_data_struct *d=&c->items[i];int64_t at=d->offset-c->f->base_address;
        if(at==off&&d->total_size==size)return 1;
        if(off<at+d->total_size&&at<off+size)return -1;
    }return 0;
}
static bool sxad_hsc(sx_context *c)
{
    if(c->size<2739||c->size>59188)return false;
    int64_t payload=c->size-1587;uint64_t patterns=(uint64_t)payload/1152;uint8_t pad;
    if(!patterns||patterns>50||(payload%1152!=0&&payload%1152!=1))return false;
    if(payload%1152&&(!sxad_byte(c,c->size-1,&pad)||pad))return false;
    if(!sx_table(c,&sxad_adlib_hsc_instrument,0,12,128)||!sx_table(c,&sxad_adlib_hsc_order,1536,1,51)||!sx_table(c,&sxad_adlib_hsc_event,1587,2,patterns*576))return false;
    return !(payload%1152)||sx_add(c,&sxad_adlib_zero_terminator,c->size-1,1);
}
static bool sxad_bnk(sx_context *c)
{
    uint8_t version[2];uint16_t used,total;uint32_t names,data;
    if(!sx_read(c,0,version,2)||version[0]!=1||version[1]||!sxad_tag(c,2,"ADLIB-",6)||!sx_u16(c,8,false,&used)||!sx_u16(c,10,false,&total)||!sx_u32(c,12,false,&names)||!sx_u32(c,16,false,&data))return false;
    if(!used||used>total||total>1000||names<20||data<(uint64_t)names+12U*total||data>(uint64_t)c->size||(c->size-data)%30)return false;
    uint64_t count=(uint64_t)(c->size-data)/30;if(!count||count>1000)return false;
    return sx_add(c,&sxad_adlib_bnk_header,0,20)&&sx_table(c,&sxad_adlib_bnk_name,names,12,total)&&sx_table(c,&sxad_adlib_bnk_instrument,data,30,count);
}
static bool sxad_bam(sx_context *c)
{
    if(!sxad_tag(c,0,"CBMF",4)||!sx_add(c,&sxad_adlib_bam_header,0,4))return false;
    int64_t at=4;uint16_t labels=1;
    while(at<c->size){uint8_t v;if(!sxad_byte(c,at,&v))return false;const sx_layout *l=&sxad_adlib_bam_command;int64_t width=1;
        if(v<128){unsigned op=v&240,ch=v&15;
            if(!op)return sxad_header(c,l,&at,1)&&at==c->size;
            if(op==16){uint8_t note;if(ch>=9||!sxad_byte(c,at+1,&note)||note>=128)return false;l=&sxad_adlib_bam_note;width=2;}
            else if(op==32){if(ch>=9)return false;}
            else if(op==48){if(ch>=9)return false;l=&sxad_adlib_bam_instrument;width=12;}
            else if(op==80)labels|=(uint16_t)(1U<<ch);
            else if(op==96){if(!(labels&(1U<<ch)))return false;l=&sxad_adlib_bam_jump;width=2;}
            else if(op!=112||ch)return false;
        }if(!sxad_header(c,l,&at,width))return false;
    }return false;
}
static bool sxad_bmf(sx_context *c)
{
    int64_t at=6;uint32_t mask;uint8_t speed;
    if(!sxad_tag(c,0,"BMF1.1",6)||!sx_add(c,&sxad_adlib_bmf_signature,0,6)||!sxad_zraw(c,&at,4096)||!sxad_zraw(c,&at,4096)||!sxad_byte(c,at,&speed)||!speed||!sx_u32(c,at+1,true,&mask)||!sxad_header(c,&sxad_adlib_bmf_settings,&at,5))return false;
    for(unsigned i=0;i<32;i++)if(mask&(UINT32_C(0x80000000)>>i))if(!sxad_header(c,&sxad_adlib_bmf_instrument,&at,24))return false;
    if(!sx_u32(c,at,true,&mask)||!mask||(mask&UINT32_C(0x007fffff))||!sxad_header(c,&sxad_adlib_bmf_stream_flags,&at,4))return false;
    for(unsigned i=0;i<9;i++)if(mask&(UINT32_C(0x80000000)>>i)){
        bool loop=false,ended=false;
        for(unsigned events=0;events<1024&&!ended;events++){
            uint8_t v,q;int64_t size=1;const sx_layout *l=&sxad_adlib_bmf_note_or_control;
            if(!sxad_byte(c,at,&v))return false;
            if(v==254)ended=true;
            else if(v==252){loop=true;size=2;l=&sxad_adlib_bmf_loop;}
            else if(v==125){if(!loop)return false;}
            else if(v&128){
                if(!sxad_byte(c,at+1,&q))return false;
                if(q&128){size=2;l=&sxad_adlib_bmf_note_delay;if(q&64){if(!sxad_byte(c,at+2,&q)||q<32||q>=128)return false;size=3;l=&sxad_adlib_bmf_note_delay_command;}}
                else {if(q<32)return false;size=2;l=&sxad_adlib_bmf_note_command;}
            }
            if(!sxad_header(c,l,&at,size))return false;
        }if(!ended)return false;
    }return at==c->size;
}
static bool sxad_dfm(sx_context *c)
{
    uint8_t major,count;int64_t at=905;uint64_t seen=0;
    if(!sxad_tag(c,0,"DFM\032",4)||!sxad_byte(c,4,&major)||major||!sxad_byte(c,904,&count)||!count||count>64)return false;
    if(!sx_add(c,&sxad_adlib_dfm_header,0,40)||!sx_table(c,&sxad_adlib_dfm_instrument_name,40,12,32)||!sx_table(c,&sxad_adlib_dfm_instrument,424,11,32)||!sx_table(c,&sxad_adlib_dfm_order,776,1,128)||!sx_add(c,&sxad_adlib_dfm_pattern_count,904,1))return false;
    for(unsigned i=0;i<count;i++){
        uint8_t id;if(!sxad_byte(c,at,&id)||id>=count||(seen&(UINT64_C(1)<<id))||!sxad_header(c,&sxad_adlib_dfm_pattern_header,&at,1))return false;seen|=UINT64_C(1)<<id;
        for(unsigned j=0;j<576;j++){uint8_t v;if(!sxad_byte(c,at,&v)||!sxad_header(c,v&128?&sxad_adlib_dfm_note_effect:&sxad_adlib_dfm_note,&at,v&128?2:1))return false;}
    }return at==c->size;
}
static bool sxad_lds(sx_context *c)
{
    uint8_t mode,tempo,len;uint16_t speed,patches,positions;int64_t at=17;
    if(!sxad_byte(c,0,&mode)||mode>2||!sx_u16(c,1,false,&speed)||!speed||!sxad_byte(c,3,&tempo)||!tempo||!sxad_byte(c,4,&len)||!len||!sx_u16(c,15,false,&patches)||!patches||patches>64||!sx_add(c,&sxad_adlib_lds_header,0,17)||!sx_table(c,&sxad_adlib_lds_patch,at,46,patches))return false;
    at+=46U*patches;
    if(!sx_u16(c,at,false,&positions)||!positions||positions>256||!sxad_header(c,&sxad_adlib_lds_position_count,&at,2)||!sx_table(c,&sxad_adlib_lds_position,at,3,9U*positions))return false;
    int64_t position_start=at;at+=27U*positions;
    if(!sxad_header(c,&sxad_adlib_lds_digital_count,&at,2)||at>=c->size||((c->size-at)&1))return false;
    for(unsigned i=0;i<9U*positions;i++){uint16_t off;if(!sx_u16(c,position_start+3U*i,false,&off)||(off&1)||off>=c->size-at)return false;}
    return sx_table(c,&sxad_adlib_lds_pattern_word,at,2,(uint64_t)(c->size-at)/2);
}
static bool sxad_rol(sx_context *c)
{
    uint16_t minor,major,count;uint8_t mode;int64_t at=203;
    if(!sx_u16(c,0,false,&minor)||minor||!sx_u16(c,2,false,&major)||major!=4||!sxad_byte(c,53,&mode)||mode>1||!sx_u16(c,201,false,&count)||count>4096||!sx_add(c,&sxad_adlib_rol_header,0,201)||!sx_add(c,&sxad_adlib_rol_tempo_count,201,2)||!sx_table(c,&sxad_adlib_rol_tempo_event,at,6,count))return false;
    at+=6U*count;
    for(unsigned i=0;i<(mode?9U:11U);i++){
        uint16_t deadline;unsigned total=0;
        if(!sx_u16(c,at+15,false,&deadline)||deadline>=32768||!sxad_header(c,&sxad_adlib_rol_note_header,&at,17))return false;
        int64_t start=at;uint64_t notes=0;
        while(total<deadline){uint16_t note,duration;if(!sx_u16(c,at,false,&note)||note>127||!sx_u16(c,at+2,false,&duration)||!duration||duration>deadline-total)return false;total+=duration;at+=4;notes++;}
        if(!sx_table(c,&sxad_adlib_rol_note_event,start,4,notes))return false;
        for(unsigned j=0;j<3;j++){
            if(!sx_u16(c,at+15,false,&count)||count>4096||!sxad_header(c,&sxad_adlib_rol_event_header,&at,17))return false;
            const sx_layout *l=j==0?&sxad_adlib_rol_instrument_event:j==1?&sxad_adlib_rol_volume_event:&sxad_adlib_rol_pitch_event;int64_t size=j?6:14;
            if(!sx_table(c,l,at,size,count))return false;at+=size*count;
        }
    }return at==c->size;
}
static bool sxad_xsm(sx_context *c)
{
    uint16_t n;if(!sxad_tag(c,0,"ofTAZ!",6)||!sx_u16(c,6,false,&n)||!n||n>3200||c->size!=152+(int64_t)n*9)return false;
    return sx_add(c,&sxad_adlib_xsm_header,0,8)&&sx_table(c,&sxad_adlib_xsm_instrument,8,16,9)&&sx_table(c,&sxad_adlib_xsm_note,152,1,(uint64_t)n*9);
}
static bool sxad_ksm(sx_context *c)
{
    uint16_t count;if(!sx_u16(c,80,false,&count)||!count||c->size!=82+(int64_t)count*4)return false;
    return sx_add(c,&sxad_adlib_ksm_header,0,82)&&sx_table(c,&sxad_adlib_ksm_event,82,4,count);
}
static bool sxad_raw(sx_context *c)
{
    uint16_t clock;int64_t at=10;bool end=false;
    if(!sxad_tag(c,0,"RAWADATA",8)||!sx_u16(c,8,false,&clock)||!clock||!sx_add(c,&sxad_adlib_raw_header,0,10))return false;
    while(at<c->size&&!end){uint8_t b[2];if(!sx_read(c,at,b,2))return false;int64_t width=2;const sx_layout *l=&sxad_adlib_raw_command;
        if(b[0]==255&&b[1]==255)end=true;
        else if(b[1]==2){if(!b[0]){if(!sx_u16(c,at+2,false,&clock)||!clock)return false;width=4;l=&sxad_adlib_raw_timer;}else if(b[0]>2)return false;}
        if(!sxad_header(c,l,&at,width))return false;
    }if(!end)return false;
    for(unsigned tag=26;at<c->size&&tag<=28;tag++){
        uint8_t v;if(!sxad_byte(c,at,&v))return false;if(v!=tag){if(tag==26)return false;continue;}
        if(!sxad_header(c,&sxad_adlib_raw_metadata_tag,&at,1)||!sxad_zraw(c,&at,tag==28?1023:40))return false;
    }return at==c->size;
}
static bool sxad_rad(sx_context *c)
{
    uint8_t v,flags;int64_t at=18;unsigned last=0;uint16_t refs[32];
    if(!sxad_tag(c,0,"RAD by REALiTY!!",16)||!sxad_byte(c,16,&v)||v!=0x10||!sxad_byte(c,17,&flags)||(flags&0x20)||!sx_add(c,&sxad_adlib_rad_header,0,18))return false;
    if((flags&128)&&!sxad_zraw(c,&at,65536))return false;
    for(;;){if(!sxad_byte(c,at,&v))return false;if(!v){if(!sxad_header(c,&sxad_adlib_instrument_end,&at,1))return false;break;}
        if(v>31||v<=last||!sxad_header(c,&sxad_adlib_rad_instrument,&at,12))return false;last=v;
    }
    if(!sxad_byte(c,at,&v)||!v||v>128||!sxad_header(c,&sxad_adlib_rad_order_count,&at,1)||!sx_table(c,&sxad_adlib_rad_order,at,1,v))return false;
    unsigned orders=v;for(unsigned i=0;i<orders;i++){if(!sxad_byte(c,at+i,&v)||((v&128)?(v&127)>=orders:v>=32))return false;}at+=orders;
    if(!sx_table(c,&sxad_adlib_rad_pattern_offset,at,2,32))return false;
    for(unsigned i=0;i<32;i++)if(!sx_u16(c,at+2U*i,false,&refs[i]))return false;at+=64;
    int64_t max_end=0;
    for(unsigned i=0;i<32;i++)if(refs[i]){
        int64_t pos=refs[i],limit=c->size;unsigned previous=0;bool first=true,ended=false;
        if(pos<at)return false;
        for(unsigned j=0;j<32;j++)if(j!=i&&refs[j]){if(refs[j]==refs[i])return false;if(refs[j]>refs[i]&&refs[j]<limit)limit=refs[j];}
        for(unsigned rows=0;rows<64&&!ended;rows++){
            if(pos>=limit||!sxad_byte(c,pos,&v)||(v&127)>=64||(!first&&(v&127)<=previous))return false;
            previous=v&127;first=false;ended=(v&128)!=0;if(!sxad_header(c,&sxad_adlib_rad_row,&pos,1))return false;
            bool channel_end=false;
            for(unsigned channels=0;channels<1024&&!channel_end;channels++){
                uint8_t b[3];if(pos>limit||limit-pos<3||!sx_read(c,pos,b,3)||(b[0]&15)>=9||(b[0]&0x70))return false;
                int64_t size=(b[2]&15)?4:3;channel_end=(b[0]&128)!=0;
                if(size>limit-pos||!sxad_header(c,size==4?&sxad_adlib_rad_effect_event:&sxad_adlib_rad_event,&pos,size))return false;
            }if(!channel_end)return false;
        }if(!ended)return false;if(pos>max_end)max_end=pos;
    }return max_end==c->size;
}
static bool sxad_d00(sx_context *c)
{
    uint8_t h[119];uint16_t table,seq,inst,info;uint16_t order_starts[1024];unsigned order_count=0,max_index=0;
    if(!sx_read(c,0,h,sizeof(h))||xx_rt_memcmp(h,"JCH\x26\x02\x66",6)||h[6]||h[7]!=4||!h[8]||!h[9]||h[10]||xx_data_get_u16(h+117,2,0,false)!=65535)return false;
    table=xx_data_get_u16(h+107,2,0,false);seq=xx_data_get_u16(h+109,2,0,false);inst=xx_data_get_u16(h+111,2,0,false);info=xx_data_get_u16(h+113,2,0,false);
    if(table<119||seq<table+(uint32_t)h[9]*32||inst<=seq||info<inst||info>=c->size||xx_data_get_u16(h+115,2,0,false)!=seq||(info-inst)%16||c->size-info!=2)return false;
    unsigned patches=(info-inst)/16;if(!patches||patches>256)return false;
    if(!sx_add(c,&sxad_adlib_d00_header,0,119)||!sx_table(c,&sxad_adlib_d00_subsong,table,32,h[9])||!sx_table(c,&sxad_adlib_d00_instrument,inst,16,patches)||!sx_add(c,&sxad_adlib_d00_data_info_end,info,2))return false;
    uint16_t marker;if(!sx_u16(c,info,false,&marker)||marker!=65535)return false;
    for(unsigned i=0;i<h[9];i++)for(unsigned j=0;j<9;j++){
        uint16_t start;if(!sx_u16(c,table+32U*i+2U*j,false,&start))return false;if(!start)continue;
        bool seen=false;for(unsigned k=0;k<order_count;k++)if(order_starts[k]==start)seen=true;if(seen)continue;
        if(order_count>=SX_COUNT(order_starts)||start<119||(uint32_t)start+4>table)return false;order_starts[order_count++]=start;
        int64_t pos=start+2;unsigned words=0;bool ended=false;
        while(pos+2<=table){uint16_t v;if(!sx_u16(c,pos,false,&v))return false;pos+=2;words++;
            if(v==65534){ended=true;break;}
            if(v==65535){uint16_t target;if(pos+2>table||!sx_u16(c,pos,false,&target)||target>=words-1)return false;pos+=2;ended=true;break;}
            if(v<0x8000){if(v>=512)return false;if(v>max_index)max_index=v;}else if(v>=0xa000)return false;
        }
        if(!ended||sxad_overlap(c,start,pos-start)!=0||!sx_add(c,&sxad_adlib_d00_order_header,start,2)||!sx_table(c,&sxad_adlib_d00_order_word,start+2,2,(uint64_t)(pos-start-2)/2))return false;
    }
    unsigned n=max_index+1;uint16_t refs[512];uint16_t first=inst;
    if((uint32_t)seq+2U*n>inst||!sx_table(c,&sxad_adlib_d00_sequence_offset,seq,2,n))return false;
    for(unsigned i=0;i<n;i++){if(!sx_u16(c,seq+2U*i,false,&refs[i])||refs[i]<seq+2U*n||refs[i]>=inst)return false;if(refs[i]<first)first=refs[i];}
    if(first!=seq+2U*n)return false;
    for(unsigned i=0;i<n;i++){
        bool seen=false;for(unsigned j=0;j<i;j++)if(refs[j]==refs[i])seen=true;if(seen)continue;
        int64_t end=inst;for(unsigned j=0;j<n;j++)if(refs[j]>refs[i]&&refs[j]<end)end=refs[j];if((end-refs[i])&1)return false;
        uint16_t word=0;for(int64_t pos=refs[i];pos<end;pos+=2){if(!sx_u16(c,pos,false,&word))return false;if(word==65535){if(pos+2!=end)return false;}else if((word>>12)==11||((word>>12)==12&&(word&4095)>=patches))return false;}
        if(word!=65535||sxad_overlap(c,refs[i],end-refs[i])!=0||!sx_table(c,&sxad_adlib_d00_sequence_word,refs[i],2,(uint64_t)(end-refs[i])/2))return false;
    }return true;
}
static bool sxad_jbm(sx_context *c)
{
    uint16_t marker,speed,table,inst,flags,refs[11];uint32_t first=65536,pool=65536;uint8_t used[255]={0};
    if(!sx_u16(c,0,false,&marker)||marker!=2||!sx_u16(c,2,false,&speed)||!speed||!sx_u16(c,4,false,&table)||table!=32||!sx_u16(c,6,false,&inst)||inst<=32||inst>=c->size||(c->size-inst)%16||!sx_u16(c,8,false,&flags)||(flags&~1U))return false;
    uint64_t patches=(uint64_t)(c->size-inst)/16;if(!patches||patches>256)return false;
    for(unsigned i=0;i<11;i++){if(!sx_u16(c,10+2U*i,false,&refs[i]))return false;if(refs[i]){if(refs[i]<table||refs[i]>=inst)return false;if(refs[i]<first)first=refs[i];}}
    if(first<=table||first>=inst||(first-table)%2)return false;unsigned sequences=(first-table)/2;if(!sequences||sequences>255)return false;
    for(unsigned i=0;i<11;i++)if(refs[i]){uint8_t v=0;int64_t at=refs[i];while(at<inst){if(!sxad_byte(c,at++,&v))return false;if(v==255)break;if(v>=sequences)return false;used[v]=1;}if(v!=255)return false;}
    uint16_t sequence_refs[255];
    for(unsigned i=0;i<sequences;i++){if(!sx_u16(c,table+2U*i,false,&sequence_refs[i]))return false;if(used[i]){if(sequence_refs[i]<=first||sequence_refs[i]>=inst)return false;if(sequence_refs[i]<pool)pool=sequence_refs[i];}}
    if(pool>=inst||!sx_add(c,&sxad_adlib_jbm_header,0,32)||!sx_table(c,&sxad_adlib_jbm_sequence_offset,table,2,sequences)||!sx_table(c,&sxad_adlib_jbm_order,first,1,pool-first)||!sx_table(c,&sxad_adlib_jbm_instrument,inst,16,patches))return false;
    /* Verify each sequence index used by a voice points at a physical start. */
    bool found[255]={0};int64_t at=pool;
    while(at<inst){for(unsigned i=0;i<sequences;i++)if(sequence_refs[i]==at)found[i]=true;bool ended=false;
        while(at<inst&&!ended){uint8_t v;if(!sxad_byte(c,at,&v))return false;int64_t size;const sx_layout *l;
            if(v==255){size=1;l=&sxad_adlib_jbm_end;ended=true;}
            else if(v==253){uint8_t id;if(!sxad_byte(c,at+1,&id)||id>=patches)return false;size=2;l=&sxad_adlib_jbm_instrument_select;}
            else {uint8_t volume;if((v&127)>95||!sxad_byte(c,at+1,&volume)||volume>63)return false;size=4;l=&sxad_adlib_jbm_note;}
            if(size>inst-at||!sxad_header(c,l,&at,size))return false;
        }if(!ended)return false;
    }
    for(unsigned i=0;i<sequences;i++)if(used[i]&&!found[i])return false;
    for(unsigned i=0;i<11;i++)if(refs[i]){int64_t pos=refs[i];uint8_t v=0;if(pos>=pool)return false;while(pos<pool){if(!sxad_byte(c,pos++,&v))return false;if(v==255)break;}if(v!=255)return false;}
    return true;
}
/* Fill uninterpreted physical gaps after constructing nonoverlapping records.
 * Sorting a compact interval view avoids quadratic work for sequential events. */
typedef struct sxad_interval {int64_t start,end;} sxad_interval;
static int sxad_compare_interval(const void *a,const void *b)
{
    const sxad_interval *x=a,*y=b;return x->start<y->start?-1:x->start>y->start?1:0;
}
static bool sxad_fill_gaps(sx_context *c)
{
    size_t n=c->count;if(!n||n>100000)return false;
    sxad_interval *ranges=xx_mem_alloc(n*sizeof(*ranges));if(!ranges)return false;
    for(size_t i=0;i<n;i++){ranges[i].start=c->items[i].offset-c->f->base_address;ranges[i].end=ranges[i].start+c->items[i].total_size;}
    xx_rt_qsort(ranges,n,sizeof(*ranges),sxad_compare_interval);int64_t end=0;bool ok=true;
    for(size_t i=0;i<n;i++){
        if(ranges[i].start<end){ok=false;break;}
        if(ranges[i].start>end&&!sx_raw(c,end,ranges[i].start-end)){ok=false;break;}end=ranges[i].end;
    }if(ok&&end<c->size)ok=sx_raw(c,end,c->size-end);xx_mem_free(ranges);return ok;
}
static bool sx_adlib_supports(xx_file_type_t type)
{
    switch(type){
    case XX_FILE_TYPE_ADLIB_RAD:case XX_FILE_TYPE_ADLIB_HSC:case XX_FILE_TYPE_ADLIB_D00:
    case XX_FILE_TYPE_ADLIB_BNK:case XX_FILE_TYPE_ADLIB_BAM:case XX_FILE_TYPE_ADLIB_BMF:
    case XX_FILE_TYPE_ADLIB_DFM:case XX_FILE_TYPE_ADLIB_LDS:case XX_FILE_TYPE_ADLIB_ROL:
    case XX_FILE_TYPE_ADLIB_JBM:case XX_FILE_TYPE_ADLIB_XSM:case XX_FILE_TYPE_KEN_KSM:case XX_FILE_TYPE_RDOS_RAW:return true;
    default:return false;
    }
}
static bool sx_adlib_build(sx_context *c)
{
    bool ok=false;
    switch(c->f->file_type){
    case XX_FILE_TYPE_ADLIB_RAD:ok=sxad_rad(c);break;case XX_FILE_TYPE_ADLIB_HSC:ok=sxad_hsc(c);break;
    case XX_FILE_TYPE_ADLIB_D00:ok=sxad_d00(c);break;case XX_FILE_TYPE_ADLIB_BNK:ok=sxad_bnk(c);break;
    case XX_FILE_TYPE_ADLIB_BAM:ok=sxad_bam(c);break;case XX_FILE_TYPE_ADLIB_BMF:ok=sxad_bmf(c);break;
    case XX_FILE_TYPE_ADLIB_DFM:ok=sxad_dfm(c);break;case XX_FILE_TYPE_ADLIB_LDS:ok=sxad_lds(c);break;
    case XX_FILE_TYPE_ADLIB_ROL:ok=sxad_rol(c);break;case XX_FILE_TYPE_ADLIB_JBM:ok=sxad_jbm(c);break;
    case XX_FILE_TYPE_ADLIB_XSM:ok=sxad_xsm(c);break;case XX_FILE_TYPE_KEN_KSM:ok=sxad_ksm(c);break;
    case XX_FILE_TYPE_RDOS_RAW:ok=sxad_raw(c);break;default:return false;
    }
    return ok&&sxad_fill_gaps(c);
}
