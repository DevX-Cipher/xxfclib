/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical sampler-bank metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_samplebanks_scope.txt. */

static const xx_data_struct_field_desc sxsb_emaxutil_marker_fields[] = {
    SX_FIELD("producer_marker","char[39]",0,39,SX_SIGNATURE),
};
static const sx_layout sxsb_emaxutil_marker = {0x603a0001U,"emaxutil_marker",sxsb_emaxutil_marker_fields,SX_COUNT(sxsb_emaxutil_marker_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_emax_bank_header_fields[] = {
    SX_FIELD("preset_addresses","uint16[100]",0,200,SX_ADDRESS),
    SX_FIELD("allocation_address","uint16",200,2,SX_ADDRESS),
    SX_FIELD("unknown_0ca","uint16",202,2,SX_NONE),
    SX_FIELD("unknown_0cc","uint32",204,4,SX_NONE),
    SX_FIELD("selected_preset","uint32",208,4,SX_NONE),
    SX_FIELD("sequence_addresses","uint32[51]",212,204,SX_ADDRESS),
    SX_FIELD("lowest_sample_entry_address","uint32",416,4,SX_ADDRESS),
    SX_FIELD("highest_sample_entry_address","uint32",420,4,SX_ADDRESS),
    SX_FIELD("sample_memory_bytes_used","uint32",424,4,SX_SIZE),
};
static const sx_layout sxsb_emax_bank_header = {0x603a0002U,"emax_bank_header",sxsb_emax_bank_header_fields,SX_COUNT(sxsb_emax_bank_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_emax_preset_header_fields[] = {
    SX_FIELD("name","char[12]",0,12,SX_NONE),
    SX_FIELD("opaque_preset_parameters","byte[23]",12,23,SX_NONE),
    SX_FIELD("key_area_count","uint8",35,1,SX_COUNT_PROP),
    SX_FIELD("key_area_map","uint8[88]",36,88,SX_NONE),
};
static const sx_layout sxsb_emax_preset_header = {0x603a0003U,"emax_preset_header",sxsb_emax_preset_header_fields,SX_COUNT(sxsb_emax_preset_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_emax_key_area_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("velocity_crossfade_encoded","uint8",1,1,SX_NONE),
    SX_FIELD("primary_voice","uint8",2,1,SX_NONE),
    SX_FIELD("secondary_voice","uint8",3,1,SX_NONE),
};
static const sx_layout sxsb_emax_key_area = {0x603a0004U,"emax_key_area",sxsb_emax_key_area_fields,SX_COUNT(sxsb_emax_key_area_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_emax_voice_fields[] = {
    SX_FIELD("amplitude_envelope_and_lfo_rate","uint32",0,4,SX_FLAGS),
    SX_FIELD("lfo_tuning_and_velocity","uint32",4,4,SX_FLAGS),
    SX_FIELD("level_velocity_and_chorus","uint32",8,4,SX_FLAGS),
    SX_FIELD("original_key","uint8",12,1,SX_NONE),
    SX_FIELD("sample_index","uint8",13,1,SX_NONE),
    SX_FIELD("opaque_0e","byte[2]",14,2,SX_NONE),
    SX_FIELD("filter_cutoff_encoded","uint8",16,1,SX_FLAGS),
    SX_FIELD("filter_q_encoded","uint8",17,1,SX_FLAGS),
    SX_FIELD("filter_envelope_amount_encoded","uint8",18,1,SX_FLAGS),
    SX_FIELD("opaque_13","uint8",19,1,SX_NONE),
    SX_FIELD("filter_envelope_and_flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("keyboard_tracking_and_pan","uint8",24,1,SX_FLAGS),
    SX_FIELD("lfo_filter_encoded","uint8",25,1,SX_FLAGS),
    SX_FIELD("delay_attenuation_chorus","uint16",26,2,SX_FLAGS),
    SX_FIELD("opaque_1c","byte[4]",28,4,SX_NONE),
};
static const sx_layout sxsb_emax_voice = {0x603a0005U,"emax_voice",sxsb_emax_voice_fields,SX_COUNT(sxsb_emax_voice_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_emax_sample_entry_fields[] = {
    SX_FIELD("unused_00","uint32",0,4,SX_NONE),
    SX_FIELD("sample_start","uint32",4,4,SX_ADDRESS),
    SX_FIELD("sample_end","uint32",8,4,SX_ADDRESS),
    SX_FIELD("sustain_loop_start","uint32",12,4,SX_ADDRESS),
    SX_FIELD("sustain_loop_end","uint32",16,4,SX_ADDRESS),
    SX_FIELD("release_loop_start","uint32",20,4,SX_ADDRESS),
    SX_FIELD("release_loop_end","uint32",24,4,SX_ADDRESS),
    SX_FIELD("flags","uint8",28,1,SX_FLAGS),
    SX_FIELD("sample_rate_index","uint8",29,1,SX_ID),
    SX_FIELD("unused_1e","uint16",30,2,SX_NONE),
};
static const sx_layout sxsb_emax_sample_entry = {0x603a0006U,"emax_sample_entry",sxsb_emax_sample_entry_fields,SX_COUNT(sxsb_emax_sample_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_emulator2_selected_name_fields[] = {
    SX_FIELD("selected_name","char[12]",0,12,SX_NONE),
};
static const sx_layout sxsb_emulator2_selected_name = {0x603a0007U,"emulator2_selected_name",sxsb_emulator2_selected_name_fields,SX_COUNT(sxsb_emulator2_selected_name_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_emulator2_keymaps_fields[] = {
    SX_FIELD("primary_voice_number","uint8[61]",0,61,SX_NONE),
    SX_FIELD("primary_voice_identifier","uint8[61]",61,61,SX_ID),
    SX_FIELD("primary_transpose","uint8[61]",122,61,SX_NONE),
    SX_FIELD("opaque_map_3","byte[61]",183,61,SX_NONE),
    SX_FIELD("opaque_map_4","byte[61]",244,61,SX_NONE),
    SX_FIELD("opaque_map_5","byte[61]",305,61,SX_NONE),
    SX_FIELD("opaque_map_6","byte[61]",366,61,SX_NONE),
    SX_FIELD("opaque_map_7","byte[61]",427,61,SX_NONE),
    SX_FIELD("opaque_map_8","byte[61]",488,61,SX_NONE),
    SX_FIELD("opaque_map_9","byte[61]",549,61,SX_NONE),
    SX_FIELD("opaque_map_10","byte[61]",610,61,SX_NONE),
};
static const sx_layout sxsb_emulator2_keymaps = {0x603a0008U,"emulator2_keymaps",sxsb_emulator2_keymaps_fields,SX_COUNT(sxsb_emulator2_keymaps_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_emulator2_preset_header_fields[] = {
    SX_FIELD("encoded_header","byte[8]",0,8,SX_NONE),
    SX_FIELD("header_flags","uint8",8,1,SX_FLAGS),
    SX_FIELD("name","char[12]",9,12,SX_NONE),
    SX_FIELD("opaque_parameters","byte[14]",21,14,SX_NONE),
};
static const sx_layout sxsb_emulator2_preset_header = {0x603a0009U,"emulator2_preset_header",sxsb_emulator2_preset_header_fields,SX_COUNT(sxsb_emulator2_preset_header_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_emulator2_selection_fields[] = {
    SX_FIELD("selected_preset","uint8",0,1,SX_NONE),
    SX_FIELD("voice_identifiers","uint8[100]",1,100,SX_ID),
};
static const sx_layout sxsb_emulator2_selection = {0x603a000aU,"emulator2_selection",sxsb_emulator2_selection_fields,SX_COUNT(sxsb_emulator2_selection_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_emulator2_preset_length_fields[] = {
    SX_FIELD("record_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxsb_emulator2_preset_length = {0x603a000bU,"emulator2_preset_length",sxsb_emulator2_preset_length_fields,SX_COUNT(sxsb_emulator2_preset_length_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_emulator2_key_range_fields[] = {
    SX_FIELD("mode_and_key_count","uint8",0,1,SX_FLAGS),
    SX_FIELD("opaque_01","uint8",1,1,SX_NONE),
    SX_FIELD("voice_number","uint8",2,1,SX_NONE),
    SX_FIELD("transpose","uint8",3,1,SX_NONE),
    SX_FIELD("level_encoded","uint8",4,1,SX_NONE),
};
static const sx_layout sxsb_emulator2_key_range = {0x603a000cU,"emulator2_key_range",sxsb_emulator2_key_range_fields,SX_COUNT(sxsb_emulator2_key_range_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_emulator2_secondary_voice_fields[] = {
    SX_FIELD("voice_number","uint8",0,1,SX_NONE),
    SX_FIELD("transpose","uint8",1,1,SX_NONE),
    SX_FIELD("level_encoded","uint8",2,1,SX_NONE),
};
static const sx_layout sxsb_emulator2_secondary_voice = {0x603a000dU,"emulator2_secondary_voice",sxsb_emulator2_secondary_voice_fields,SX_COUNT(sxsb_emulator2_secondary_voice_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_emulator2_key_range_end_fields[] = {
    SX_FIELD("end_marker","byte[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxsb_emulator2_key_range_end = {0x603a000eU,"emulator2_key_range_end",sxsb_emulator2_key_range_end_fields,SX_COUNT(sxsb_emulator2_key_range_end_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_emulator2_voice_fields[] = {
    SX_FIELD("tag","byte[2]",0,2,SX_SIGNATURE),
    SX_FIELD("playback_start_minus_one","uint24",2,3,SX_ADDRESS),
    SX_FIELD("opaque_05","uint8",5,1,SX_NONE),
    SX_FIELD("preloop_negative_counter","uint24",6,3,SX_NONE),
    SX_FIELD("opaque_09","uint8",9,1,SX_NONE),
    SX_FIELD("loop_start_minus_one","uint24",10,3,SX_ADDRESS),
    SX_FIELD("opaque_0d","uint8",13,1,SX_NONE),
    SX_FIELD("loop_negative_counter","uint24",14,3,SX_NONE),
    SX_FIELD("opaque_11","byte[2]",17,2,SX_NONE),
    SX_FIELD("loop_negative_counter_copy","uint24",19,3,SX_NONE),
    SX_FIELD("opaque_16","byte[4]",22,4,SX_NONE),
    SX_FIELD("fine_tune","int8",26,1,SX_NONE),
    SX_FIELD("velocity_attack","uint8",27,1,SX_FLAGS),
    SX_FIELD("lfo_delay_encoded","uint8",28,1,SX_NONE),
    SX_FIELD("lfo_rate_encoded","uint8",29,1,SX_NONE),
    SX_FIELD("opaque_1e","uint8",30,1,SX_NONE),
    SX_FIELD("filter_keyboard_tracking","uint8",31,1,SX_FLAGS),
    SX_FIELD("opaque_20","byte[2]",32,2,SX_NONE),
    SX_FIELD("self_pointer_22","uint16",34,2,SX_ADDRESS),
    SX_FIELD("opaque_24","uint8",36,1,SX_NONE),
    SX_FIELD("filter_envelope_amount_encoded","uint8",37,1,SX_NONE),
    SX_FIELD("self_pointer_26","uint16",38,2,SX_ADDRESS),
    SX_FIELD("lfo_pitch_table_address","uint16",40,2,SX_ADDRESS),
    SX_FIELD("lfo_filter_table_address","uint16",42,2,SX_ADDRESS),
    SX_FIELD("lfo_level_table_address","uint16",44,2,SX_ADDRESS),
    SX_FIELD("filter_sustain_encoded","uint8",46,1,SX_NONE),
    SX_FIELD("filter_flags","uint8",47,1,SX_FLAGS),
    SX_FIELD("cutoff_velocity_table","uint8[16]",48,16,SX_NONE),
    SX_FIELD("level_velocity_table","uint8[16]",64,16,SX_NONE),
    SX_FIELD("filter_attack_passes","uint8[16]",80,16,SX_NONE),
    SX_FIELD("filter_attack_increment","uint8[16]",96,16,SX_NONE),
    SX_FIELD("amplitude_attack_passes","uint8[16]",112,16,SX_NONE),
    SX_FIELD("amplitude_attack_increment","uint8[16]",128,16,SX_NONE),
    SX_FIELD("filter_decay_passes","uint8",144,1,SX_NONE),
    SX_FIELD("opaque_91","uint8",145,1,SX_NONE),
    SX_FIELD("filter_decay_negative_increment","uint8",146,1,SX_NONE),
    SX_FIELD("filter_envelope_amount_copy","uint8",147,1,SX_NONE),
    SX_FIELD("opaque_94","byte[10]",148,10,SX_NONE),
    SX_FIELD("filter_release_passes","uint8",158,1,SX_NONE),
    SX_FIELD("opaque_9f","uint8",159,1,SX_NONE),
    SX_FIELD("filter_release_negative_increment","uint8",160,1,SX_NONE),
    SX_FIELD("opaque_a1","byte[4]",161,4,SX_NONE),
    SX_FIELD("amplitude_decay_passes","uint8",165,1,SX_NONE),
    SX_FIELD("opaque_a6","uint8",166,1,SX_NONE),
    SX_FIELD("amplitude_decay_negative_increment","uint8",167,1,SX_NONE),
    SX_FIELD("opaque_a8","uint8",168,1,SX_NONE),
    SX_FIELD("amplitude_sustain_encoded","uint8",169,1,SX_NONE),
    SX_FIELD("opaque_aa","byte[9]",170,9,SX_NONE),
    SX_FIELD("amplitude_release_passes","uint8",179,1,SX_NONE),
    SX_FIELD("opaque_b4","uint8",180,1,SX_NONE),
    SX_FIELD("amplitude_release_negative_increment","uint8",181,1,SX_NONE),
    SX_FIELD("opaque_b6","byte[4]",182,4,SX_NONE),
    SX_FIELD("name","char[12]",186,12,SX_NONE),
    SX_FIELD("flags","uint8",198,1,SX_FLAGS),
    SX_FIELD("region_offset","uint24",199,3,SX_OFFSET),
    SX_FIELD("slot_frames","uint24",202,3,SX_COUNT_PROP),
    SX_FIELD("loop_offset","uint24",205,3,SX_OFFSET),
    SX_FIELD("loop_frames","uint24",208,3,SX_COUNT_PROP),
    SX_FIELD("playback_offset","uint24",211,3,SX_OFFSET),
    SX_FIELD("playback_frames_with_padding","uint24",214,3,SX_COUNT_PROP),
    SX_FIELD("opaque_d9","byte[23]",217,23,SX_NONE),
    SX_FIELD("q_velocity_table","uint8[16]",240,16,SX_NONE),
};
static const sx_layout sxsb_emulator2_voice = {0x603a000fU,"emulator2_voice",sxsb_emulator2_voice_fields,SX_COUNT(sxsb_emulator2_voice_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_casio_fz_bank_fields[] = {
    SX_FIELD("area_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("high_key","uint8[64]",2,64,SX_NONE),
    SX_FIELD("low_key","uint8[64]",66,64,SX_NONE),
    SX_FIELD("high_velocity","uint8[64]",130,64,SX_NONE),
    SX_FIELD("low_velocity","uint8[64]",194,64,SX_NONE),
    SX_FIELD("original_key","uint8[64]",258,64,SX_NONE),
    SX_FIELD("midi_channel","uint8[64]",322,64,SX_NONE),
    SX_FIELD("generator_mask","uint8[64]",386,64,SX_FLAGS),
    SX_FIELD("volume","uint8[64]",450,64,SX_NONE),
    SX_FIELD("voice_number","uint16[64]",514,128,SX_NONE),
    SX_FIELD("name","char[12]",642,12,SX_NONE),
    SX_FIELD("name_padding","byte[2]",654,2,SX_RESERVED),
};
static const sx_layout sxsb_casio_fz_bank = {0x603a0010U,"casio_fz_bank",sxsb_casio_fz_bank_fields,SX_COUNT(sxsb_casio_fz_bank_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_casio_fz_voice_fields[] = {
    SX_FIELD("wave_start","uint32",0,4,SX_ADDRESS),
    SX_FIELD("wave_end","uint32",4,4,SX_ADDRESS),
    SX_FIELD("generator_start","uint32",8,4,SX_ADDRESS),
    SX_FIELD("generator_end","uint32",12,4,SX_ADDRESS),
    SX_FIELD("sounding_mode","uint16",16,2,SX_FLAGS),
    SX_FIELD("sustain_loop","uint8",18,1,SX_NONE),
    SX_FIELD("end_loop","uint8",19,1,SX_NONE),
    SX_FIELD("loop_start_encoded","uint32[8]",20,32,SX_FLAGS),
    SX_FIELD("loop_end_encoded","uint32[8]",52,32,SX_FLAGS),
    SX_FIELD("loop_crossfade_encoded","uint16[8]",84,16,SX_NONE),
    SX_FIELD("loop_time_encoded","uint16[8]",100,16,SX_NONE),
    SX_FIELD("pitch_detune","int16",116,2,SX_NONE),
    SX_FIELD("filter_offset","uint8",118,1,SX_NONE),
    SX_FIELD("filter_q_offset","uint8",119,1,SX_NONE),
    SX_FIELD("amplitude_sustain_point","uint8",120,1,SX_NONE),
    SX_FIELD("amplitude_end_point","uint8",121,1,SX_NONE),
    SX_FIELD("amplitude_rate","uint8[8]",122,8,SX_FLAGS),
    SX_FIELD("amplitude_stop","uint8[8]",130,8,SX_NONE),
    SX_FIELD("filter_sustain_point","uint8",138,1,SX_NONE),
    SX_FIELD("filter_end_point","uint8",139,1,SX_NONE),
    SX_FIELD("filter_rate","uint8[8]",140,8,SX_FLAGS),
    SX_FIELD("filter_stop","uint8[8]",148,8,SX_NONE),
    SX_FIELD("lfo_delay_encoded","uint16",156,2,SX_NONE),
    SX_FIELD("lfo_waveform","uint8",158,1,SX_FLAGS),
    SX_FIELD("lfo_attack","uint8",159,1,SX_NONE),
    SX_FIELD("lfo_rate_encoded","uint8",160,1,SX_NONE),
    SX_FIELD("lfo_pitch_depth","uint8",161,1,SX_NONE),
    SX_FIELD("lfo_amplitude_depth","uint8",162,1,SX_NONE),
    SX_FIELD("lfo_filter_depth","uint8",163,1,SX_NONE),
    SX_FIELD("lfo_q_depth","uint8",164,1,SX_NONE),
    SX_FIELD("velocity_q_follow","int8",165,1,SX_NONE),
    SX_FIELD("amplitude_keyboard_follow","int8",166,1,SX_NONE),
    SX_FIELD("amplitude_note_rate_scale","int8",167,1,SX_NONE),
    SX_FIELD("filter_keyboard_follow","int8",168,1,SX_NONE),
    SX_FIELD("filter_note_rate_scale","int8",169,1,SX_NONE),
    SX_FIELD("velocity_amplitude_follow","int8",170,1,SX_NONE),
    SX_FIELD("velocity_amplitude_rate_scale","int8",171,1,SX_NONE),
    SX_FIELD("velocity_filter_follow","int8",172,1,SX_NONE),
    SX_FIELD("velocity_filter_rate_scale","int8",173,1,SX_NONE),
    SX_FIELD("high_key","uint8",174,1,SX_NONE),
    SX_FIELD("low_key","uint8",175,1,SX_NONE),
    SX_FIELD("original_key","uint8",176,1,SX_NONE),
    SX_FIELD("sample_rate_code","uint8",177,1,SX_ID),
    SX_FIELD("name","char[12]",178,12,SX_NONE),
    SX_FIELD("name_padding","byte[2]",190,2,SX_RESERVED),
};
static const sx_layout sxsb_casio_fz_voice = {0x603a0011U,"casio_fz_voice",sxsb_casio_fz_voice_fields,SX_COUNT(sxsb_casio_fz_voice_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_casio_fz_effect_fields[] = {
    SX_FIELD("pitch_bend_depth","uint8",0,1,SX_NONE),
    SX_FIELD("unused_master_volume","uint8",1,1,SX_NONE),
    SX_FIELD("unused_sustain_switch","uint8",2,1,SX_NONE),
    SX_FIELD("modulation_lfo_pitch","uint8",3,1,SX_NONE),
    SX_FIELD("modulation_lfo_amplitude","uint8",4,1,SX_NONE),
    SX_FIELD("modulation_lfo_filter","uint8",5,1,SX_NONE),
    SX_FIELD("modulation_lfo_q","uint8",6,1,SX_NONE),
    SX_FIELD("modulation_filter","uint8",7,1,SX_NONE),
    SX_FIELD("modulation_amplitude","uint8",8,1,SX_NONE),
    SX_FIELD("modulation_q","uint8",9,1,SX_NONE),
    SX_FIELD("foot_lfo_pitch","uint8",10,1,SX_NONE),
    SX_FIELD("foot_lfo_amplitude","uint8",11,1,SX_NONE),
    SX_FIELD("foot_lfo_filter","uint8",12,1,SX_NONE),
    SX_FIELD("foot_lfo_q","uint8",13,1,SX_NONE),
    SX_FIELD("foot_amplitude","uint8",14,1,SX_NONE),
    SX_FIELD("foot_filter","uint8",15,1,SX_NONE),
    SX_FIELD("foot_q","uint8",16,1,SX_NONE),
    SX_FIELD("aftertouch_lfo_pitch","uint8",17,1,SX_NONE),
    SX_FIELD("aftertouch_lfo_amplitude","uint8",18,1,SX_NONE),
    SX_FIELD("aftertouch_lfo_filter","uint8",19,1,SX_NONE),
    SX_FIELD("aftertouch_lfo_q","uint8",20,1,SX_NONE),
    SX_FIELD("aftertouch_amplitude","uint8",21,1,SX_NONE),
    SX_FIELD("aftertouch_filter","uint8",22,1,SX_NONE),
    SX_FIELD("aftertouch_q","uint8",23,1,SX_NONE),
};
static const sx_layout sxsb_casio_fz_effect = {0x603a0012U,"casio_fz_effect",sxsb_casio_fz_effect_fields,SX_COUNT(sxsb_casio_fz_effect_fields),SX_LE};

static const xx_data_struct_field_desc sxsb_casio_fzf_dump_workspace_fields[] = {
    SX_FIELD("opaque_00","byte[5]",0,5,SX_NONE),
    SX_FIELD("dump_type","uint8",5,1,SX_ID),
    SX_FIELD("opaque_06","uint8",6,1,SX_NONE),
    SX_FIELD("bank_count","uint8",7,1,SX_COUNT_PROP),
    SX_FIELD("voice_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("content_blocks","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("waveform_blocks","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("opaque_0e","byte[10]",14,10,SX_NONE),
};
static const sx_layout sxsb_casio_fzf_dump_workspace = {0x603a0013U,"casio_fzf_dump_workspace",sxsb_casio_fzf_dump_workspace_fields,SX_COUNT(sxsb_casio_fzf_dump_workspace_fields),SX_LE};

static const sx_layout *const sx_samplebanks_layouts[] = {
    &sxsb_emaxutil_marker,
    &sxsb_emax_bank_header,
    &sxsb_emax_preset_header,
    &sxsb_emax_key_area,
    &sxsb_emax_voice,
    &sxsb_emax_sample_entry,
    &sxsb_emulator2_selected_name,
    &sxsb_emulator2_keymaps,
    &sxsb_emulator2_preset_header,
    &sxsb_emulator2_selection,
    &sxsb_emulator2_preset_length,
    &sxsb_emulator2_key_range,
    &sxsb_emulator2_secondary_voice,
    &sxsb_emulator2_key_range_end,
    &sxsb_emulator2_voice,
    &sxsb_casio_fz_bank,
    &sxsb_casio_fz_voice,
    &sxsb_casio_fz_effect,
    &sxsb_casio_fzf_dump_workspace,
};

static bool sx_samplebanks_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x603a0000U||id>=0x603b0000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;
    if(id==0x603a0006U&&!xx_rt_wcscmp(r->name,L"sample_rate_index")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"10000 Hz");
    case 1U:return xx_data_struct_record_set_comment(r,L"15625 Hz");
    case 2U:return xx_data_struct_record_set_comment(r,L"20000 Hz");
    case 3U:return xx_data_struct_record_set_comment(r,L"22050 Hz");
    case 4U:return xx_data_struct_record_set_comment(r,L"27778 Hz");
    case 5U:return xx_data_struct_record_set_comment(r,L"31250 Hz");
    case 6U:return xx_data_struct_record_set_comment(r,L"41667 Hz");
    case 7U:return xx_data_struct_record_set_comment(r,L"44100 Hz");
    default:break;}}
    if(id==0x603a0011U&&!xx_rt_wcscmp(r->name,L"sounding_mode")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"NO SOUND");
    case 471U:return xx_data_struct_record_set_comment(r,L"NORMAL");
    case 4125U:return xx_data_struct_record_set_comment(r,L"REVERSE");
    case 8212U:return xx_data_struct_record_set_comment(r,L"CUE");
    case 19U:return xx_data_struct_record_set_comment(r,L"SYNTHESIZED");
    default:break;}}
    if(id==0x603a0011U&&!xx_rt_wcscmp(r->name,L"sample_rate_code")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"36000 Hz");
    case 1U:return xx_data_struct_record_set_comment(r,L"18000 Hz");
    case 2U:return xx_data_struct_record_set_comment(r,L"9000 Hz");
    default:break;}}
    if(id==0x603a0013U&&!xx_rt_wcscmp(r->name,L"dump_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"FULL DUMP");
    case 2U:return xx_data_struct_record_set_comment(r,L"BANK DUMP");
    default:break;}}
    switch(id){
    case 0x603a0001U:
        if(!xx_rt_wcscmp(r->name,L"producer_marker"))s=L"Constant emaxutil producer marker; the date text is not a per-file modification time.";
        break;
    case 0x603a0002U:
        if(!xx_rt_wcscmp(r->name,L"preset_addresses"))s=L"Little-endian CPU addresses into parameter memory mapped at 0x8000. Unused slots may contain stale addresses; this is not a contiguous record table.";
        else if(!xx_rt_wcscmp(r->name,L"allocation_address"))s=L"First free byte in parameter memory, expressed as a CPU address.";
        else if(!xx_rt_wcscmp(r->name,L"selected_preset"))s=L"Selected preset slot, not a preset count; all 100 pointer slots are independent.";
        else if(!xx_rt_wcscmp(r->name,L"sequence_addresses"))s=L"Sample-memory addresses; 0x80000 denotes an unused Emax I sequence slot.";
        else if(!xx_rt_wcscmp(r->name,L"lowest_sample_entry_address"))s=L"CPU address of the lowest sample-directory entry. Entries grow downwards from 0xF000.";
        else if(!xx_rt_wcscmp(r->name,L"highest_sample_entry_address"))s=L"CPU address, normally 0xEFE0.";
        break;
    case 0x603a0003U:
        if(!xx_rt_wcscmp(r->name,L"opaque_preset_parameters"))s=L"Stored preset parameters; their individual semantics are not decoded.";
        else if(!xx_rt_wcscmp(r->name,L"key_area_map"))s=L"Key 0 is MIDI note 21. Entries index the key-area table; 0xFF is silent.";
        break;
    case 0x603a0004U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit 4 enables the secondary voice.";
        else if(!xx_rt_wcscmp(r->name,L"velocity_crossfade_encoded"))s=L"Stored velocity crossfade/switch parameter; its encoding is not decoded.";
        else if(!xx_rt_wcscmp(r->name,L"primary_voice"))s=L"Zero-based index in this preset's voice records.";
        else if(!xx_rt_wcscmp(r->name,L"secondary_voice"))s=L"Zero-based voice index; 0xFF denotes no secondary voice.";
        break;
    case 0x603a0005U:
        if(!xx_rt_wcscmp(r->name,L"amplitude_envelope_and_lfo_rate"))s=L"Little-endian packed bits: attack 0..4, hold 5..9, decay 10..14, sustain 15..19, release 20..24, LFO rate 25..31.";
        else if(!xx_rt_wcscmp(r->name,L"lfo_tuning_and_velocity"))s=L"Local bits: LFO delay 0..5, variation 6..10, pitch depth 11..14, signed tuning 15..19, velocity cutoff 20..23, velocity filter attack 24..27; upper 4 bits undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"level_velocity_and_chorus"))s=L"Local bits: LFO volume 0..3, velocity level 4..7, velocity amplitude attack 12..15, chorus amount 24..28; other bits undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"original_key"))s=L"MIDI note 21 plus this value.";
        else if(!xx_rt_wcscmp(r->name,L"sample_index"))s=L"Zero-based sample number, counted downwards from the top of the sample directory.";
        else if(!xx_rt_wcscmp(r->name,L"filter_cutoff_encoded"))s=L"Low 7 bits encode filter cutoff; high bit is undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"filter_q_encoded"))s=L"Low 7 bits encode filter Q; high bit is undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"filter_envelope_amount_encoded"))s=L"Low 7 bits form a signed filter-envelope amount; high bit is undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"filter_envelope_and_flags"))s=L"Local bits: attack 0..4, hold 5..9, decay 10..14, sustain 15..19, release 20..24, velocity Q 25..28, non-transpose 31; bits 29..30 undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"keyboard_tracking_and_pan"))s=L"Low nibble is filter keyboard tracking; high nibble is pan (1 right, 8 centre, 15 left).";
        else if(!xx_rt_wcscmp(r->name,L"lfo_filter_encoded"))s=L"High nibble is LFO-to-filter depth; low nibble undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"delay_attenuation_chorus"))s=L"Low 6 bits are voice delay; bits 6..10 attenuation, bit 11 chorus enabled; upper bits undecoded.";
        break;
    case 0x603a0006U:
        if(!xx_rt_wcscmp(r->name,L"unused_00"))s=L"Unused stored word, potentially stale memory.";
        else if(!xx_rt_wcscmp(r->name,L"sample_start"))s=L"Address in Emax I sample memory; one stored byte per sample frame.";
        else if(!xx_rt_wcscmp(r->name,L"sample_end"))s=L"Address in Emax I sample memory.";
        else if(!xx_rt_wcscmp(r->name,L"sustain_loop_start"))s=L"Sample-memory address; loop fields may be stale when looping is disabled.";
        else if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit 0 enables looping; bit 1 uses the sustain loop in release. Other bits remain undecoded.";
        break;
    case 0x603a0007U:
        if(!xx_rt_wcscmp(r->name,L"selected_name"))s=L"Stored display-name workspace; may be blank.";
        break;
    case 0x603a0008U:
        if(!xx_rt_wcscmp(r->name,L"primary_voice_number"))s=L"Expanded selected-preset voice numbers, one per keyboard key.";
        else if(!xx_rt_wcscmp(r->name,L"primary_voice_identifier"))s=L"Voice memory-page identifiers; 0x9B identifies the first 256-byte voice slot.";
        else if(!xx_rt_wcscmp(r->name,L"primary_transpose"))s=L"Stored semitone transposition; 0x10 is recorded pitch.";
        break;
    case 0x603a0009U:
        if(!xx_rt_wcscmp(r->name,L"encoded_header"))s=L"Stored preset-header values; individual semantics are undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"header_flags"))s=L"High bit identifies a preset record.";
        else if(!xx_rt_wcscmp(r->name,L"name"))s=L"Display name; some producers use Mac Roman bytes or control characters.";
        break;
    case 0x603a000aU:
        if(!xx_rt_wcscmp(r->name,L"voice_identifiers"))s=L"Voice-number lookup; 0 is unused, 0x9B is the first voice-slot identifier.";
        break;
    case 0x603a000bU:
        if(!xx_rt_wcscmp(r->name,L"record_size"))s=L"Byte size of the following preset, including its final next-record-size word; zero ends the chain.";
        break;
    case 0x603a000cU:
        if(!xx_rt_wcscmp(r->name,L"mode_and_key_count"))s=L"High 2 bits: 1 silent, 2 primary voice, 3 dual voice; low 6 bits are the number of keys.";
        else if(!xx_rt_wcscmp(r->name,L"voice_number"))s=L"One-based voice number; zero is silent.";
        else if(!xx_rt_wcscmp(r->name,L"transpose"))s=L"0x10 denotes recorded pitch.";
        break;
    case 0x603a000dU:
        if(!xx_rt_wcscmp(r->name,L"voice_number"))s=L"One-based secondary voice number; zero is silent.";
        break;
    case 0x603a000eU:
        if(!xx_rt_wcscmp(r->name,L"end_marker"))s=L"Stored key-range terminator, normally 00 3D 00 00.";
        break;
    case 0x603a000fU:
        if(!xx_rt_wcscmp(r->name,L"playback_start_minus_one"))s=L"Encoded playback counter, stored address minus one; may be stale when flag 0x10 is set.";
        else if(!xx_rt_wcscmp(r->name,L"preloop_negative_counter"))s=L"0x500000 minus the pre-loop frame count; this is not a byte size.";
        else if(!xx_rt_wcscmp(r->name,L"loop_start_minus_one"))s=L"Encoded loop-start address minus one; may be stale.";
        else if(!xx_rt_wcscmp(r->name,L"loop_negative_counter"))s=L"Counter base (0x500000 or 0x600000) minus loop frames.";
        else if(!xx_rt_wcscmp(r->name,L"fine_tune"))s=L"Signed units of 1/64 semitone.";
        else if(!xx_rt_wcscmp(r->name,L"velocity_attack"))s=L"High nibble controls velocity-to-VCA attack, low nibble velocity-to-VCF attack.";
        else if(!xx_rt_wcscmp(r->name,L"lfo_delay_encoded"))s=L"Delay is (stored value minus one) times 10 milliseconds.";
        else if(!xx_rt_wcscmp(r->name,L"lfo_rate_encoded"))s=L"Encoded LFO-rate value, not Hertz.";
        else if(!xx_rt_wcscmp(r->name,L"filter_keyboard_tracking"))s=L"High nibble controls keyboard tracking; 8 is one octave per octave.";
        else if(!xx_rt_wcscmp(r->name,L"self_pointer_22"))s=L"Sampler CPU address into this voice record, not a file offset.";
        else if(!xx_rt_wcscmp(r->name,L"lfo_pitch_table_address"))s=L"Pointer into the sampler operating system's LFO-depth tables.";
        else if(!xx_rt_wcscmp(r->name,L"filter_flags"))s=L"Bit 7 inverts the filter envelope; other bits remain undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"cutoff_velocity_table"))s=L"Encoded cutoff per velocity zone; entry 0 is the highest velocity.";
        else if(!xx_rt_wcscmp(r->name,L"filter_attack_passes"))s=L"Stored envelope counter passes, not timestamps or byte sizes.";
        else if(!xx_rt_wcscmp(r->name,L"flags"))s=L"0x04 loop enabled; 0x10 counter block stale; 0x08 changes loop counter base to 0x600000. Other bits undecoded.";
        else if(!xx_rt_wcscmp(r->name,L"region_offset"))s=L"Bank-relative sample region; one encoded byte per frame.";
        else if(!xx_rt_wcscmp(r->name,L"slot_frames"))s=L"Sample frames including padding; one encoded byte per frame.";
        else if(!xx_rt_wcscmp(r->name,L"loop_offset"))s=L"Bank-relative sample-loop start.";
        else if(!xx_rt_wcscmp(r->name,L"playback_offset"))s=L"Bank-relative sample-playback start.";
        break;
    case 0x603a0010U:
        if(!xx_rt_wcscmp(r->name,L"area_count"))s=L"Number of keyboard/velocity split areas, at most 64.";
        else if(!xx_rt_wcscmp(r->name,L"midi_channel"))s=L"Zero-based MIDI channel per area.";
        else if(!xx_rt_wcscmp(r->name,L"generator_mask"))s=L"Bits 0..7 enable sound generators 1..8.";
        else if(!xx_rt_wcscmp(r->name,L"voice_number"))s=L"Stored zero-based voice numbers, not the internal-memory pointers used by the running sampler.";
        break;
    case 0x603a0011U:
        if(!xx_rt_wcscmp(r->name,L"wave_start"))s=L"PCM memory word address, two bytes per sample; not a file offset.";
        else if(!xx_rt_wcscmp(r->name,L"sounding_mode"))s=L"Packed generator mode; 0 is silent, 0x101D reverse, 0x2014 cue.";
        else if(!xx_rt_wcscmp(r->name,L"sustain_loop"))s=L"Loop index, 0..8; encoded end/sustain control.";
        else if(!xx_rt_wcscmp(r->name,L"loop_start_encoded"))s=L"Low address bits plus high-byte loop-fine encoding; these packed words are not plain file offsets.";
        else if(!xx_rt_wcscmp(r->name,L"loop_end_encoded"))s=L"Word address with jump-loop flag in bit 31.";
        else if(!xx_rt_wcscmp(r->name,L"loop_time_encoded"))s=L"Encoded duration or repeat count; units depend on loop mode.";
        else if(!xx_rt_wcscmp(r->name,L"pitch_detune"))s=L"Signed pitch in 1/256 semitone units.";
        else if(!xx_rt_wcscmp(r->name,L"amplitude_rate"))s=L"Sign-magnitude envelope rate: bit 7 is decreasing, low 7 bits are the absolute rate.";
        else if(!xx_rt_wcscmp(r->name,L"filter_rate"))s=L"Sign-magnitude envelope rate: bit 7 is decreasing, low 7 bits are the absolute rate.";
        else if(!xx_rt_wcscmp(r->name,L"lfo_delay_encoded"))s=L"Units of 2 milliseconds.";
        else if(!xx_rt_wcscmp(r->name,L"lfo_waveform"))s=L"Low 7 bits select waveform 0..5; bit 7 enables phase synchronization.";
        break;
    case 0x603a0012U:
        if(!xx_rt_wcscmp(r->name,L"pitch_bend_depth"))s=L"Units of 1/8 semitone.";
        break;
    case 0x603a0013U:
        if(!xx_rt_wcscmp(r->name,L"dump_type"))s=L"HxC bare-dump type: 0 full, 2 bank.";
        else if(!xx_rt_wcscmp(r->name,L"opaque_06"))s=L"The native reader requires zero here.";
        else if(!xx_rt_wcscmp(r->name,L"voice_count"))s=L"Stored little-endian counter; current native wrapper validation uses its low byte and permits at most 64 voices.";
        else if(!xx_rt_wcscmp(r->name,L"content_blocks"))s=L"Total content length in 1024-byte blocks in fzdump files; retained as stored.";
        else if(!xx_rt_wcscmp(r->name,L"waveform_blocks"))s=L"Number of 1024-byte waveform blocks; not a byte count.";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Physical bank records. Optional damaged/stale heap pointers remain raw.
 * Bounds are independent of the native subclass and constructor. */
#define SXSB_LIMIT 24000U
static bool sxsb_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxsb_read(sx_context*c,uint64_t p,void*b,size_t n){return sxsb_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint32_t sxsb16(const uint8_t*b){return (uint32_t)b[0]|(uint32_t)b[1]<<8;}
static uint32_t sxsb24(const uint8_t*b){return sxsb16(b)|(uint32_t)b[2]<<16;}
static uint32_t sxsb32(const uint8_t*b){return sxsb24(b)|(uint32_t)b[3]<<24;}
static bool sxsb_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 const xx_data_struct_field_desc*f=l->fields+l->field_count-1;
 uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(!n)return true;
 if(n>1048576U||n>(uint64_t)INT64_MAX/z||!sxsb_span(c,p,n*z)||xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXSB_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&c->items[lo-1].offset-c->f->base_address+c->items[lo-1].total_size>(int64_t)p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}
 return true;
}
#define SXSB_ADD(c,l,p) sxsb_put(c,&sxsb_##l,p,1)
#define SXSB_TABLE(c,l,p,n) sxsb_put(c,&sxsb_##l,p,n)
static bool sxsb_emax(sx_context*c){
 uint8_t h[428],p[124],a[4],v[32];const uint64_t origin=39;
 if(c->size!=552999||!sxsb_read(c,origin,h,sizeof(h))||!SXSB_ADD(c,emaxutil_marker,0)||!SXSB_ADD(c,emax_bank_header,origin))return false;
 uint32_t low=sxsb32(h+416),high=sxsb32(h+420);
 if(low<0x81ac||low>0xf000||high!=0xefe0||(0xf000-low)%32)return true;
 uint64_t directory=low-0x8000,samples=(0xf000-low)/32;
 if(samples&&!SXSB_TABLE(c,emax_sample_entry,origin+directory,samples))return false;
 for(unsigned slot=0;slot<100;slot++){
  uint32_t at=sxsb16(h+slot*2);if(at<0x81ac||at>=low)continue;
  uint64_t off=at-0x8000;if(directory-off<124||!sxsb_read(c,origin+off,p,124))continue;
  bool valid=true,nonblank=false;for(unsigned i=0;i<12;i++){if(p[i]<32||p[i]>126)valid=false;if(p[i]!=32)nonblank=true;}
  unsigned areas=p[35],voices=0;if(!valid||!nonblank||!areas||areas>88||directory-off<124+(uint64_t)areas*4)continue;
  for(unsigned i=0;i<88;i++)if(p[36+i]!=255&&p[36+i]>=areas)valid=false;
  if(!valid)continue;
  for(unsigned i=0;i<areas;i++){
   if(!sxsb_read(c,origin+off+124+4*i,a,4))return false;
   if(a[2]==255){valid=false;break;}if((unsigned)a[2]+1>voices)voices=(unsigned)a[2]+1;
   if(a[0]&16){if(a[3]==255){valid=false;break;}if((unsigned)a[3]+1>voices)voices=(unsigned)a[3]+1;}
  }
  uint64_t vo=off+124+4*areas,end=vo+(uint64_t)voices*32;
  if(!valid||end>directory)continue;
  for(unsigned i=0;i<voices;i++){if(!sxsb_read(c,origin+vo+i*32,v,32))return false;if(v[12]>=88||v[13]>=samples){valid=false;break;}}
  if(!valid)continue;
  /* Repeated and overlapping stale pointer slots do not create overlapping rows. */
  bool overlap=false;for(size_t i=0;i<c->count;i++){uint64_t x=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(x<origin+end&&origin+off<x+z){overlap=true;break;}}
  if(overlap)continue;
  if(!SXSB_ADD(c,emax_preset_header,origin+off)||!SXSB_TABLE(c,emax_key_area,origin+off+124,areas)||!SXSB_TABLE(c,emax_voice,origin+vo,voices))return false;
 }
 return true;
}
/* Validate a complete optional preset before committing any part of it. */
static bool sxsb_eii_preset(sx_context*c,uint64_t p,uint16_t n,uint64_t limit,bool emit){
 uint8_t b[35],r[8];if(n<41||p>limit||n>limit-p||!sxsb_read(c,p,b,35)||!(b[8]&128))return false;
 for(unsigned i=0;i<8;i++)if(b[i]>15)return false;
 uint64_t q=p+35,end=p+n-2;unsigned keys=0;
 while(q<end){
  if(end-q<4||!sxsb_read(c,q,r,4))return false;
  unsigned mode=r[0]>>6,count=r[0]&63;
  if(!mode){if(end-q!=4||r[0]||r[1]!=61||r[2]||r[3])return false;return !emit||(SXSB_ADD(c,emulator2_key_range_end,q)&&SXSB_ADD(c,emulator2_preset_length,end));}
  unsigned width=mode==3?8:5;if(!count||keys+count>61||end-q<width||!sxsb_read(c,q,r,width))return false;
  if(r[2]>100||(mode==3&&r[5]>100))return false;
  if(emit&&(!SXSB_ADD(c,emulator2_key_range,q)||(mode==3&&!SXSB_ADD(c,emulator2_secondary_voice,q+5))))return false;
  keys+=count;q+=width;
 }
 return false;
}
static bool sxsb_eii(sx_context*c){
 if(c->size!=487424||!SXSB_ADD(c,emulator2_selected_name,0)||!SXSB_ADD(c,emulator2_keymaps,12)||!SXSB_ADD(c,emulator2_preset_header,0x2ab)||!SXSB_ADD(c,emulator2_selection,0x2ce))return false;
 uint64_t p=0x500,limit=0x76a00;unsigned voices=0,presets=0;uint8_t b[256];
 while(p<limit){
  if(limit-p<2||!sxsb_read(c,p,b,2))break;
  if(b[0]==4&&b[1]==3){
   if(voices>=100||limit-p<256||!sxsb_read(c,p,b,256))break;
   /* The two independent self-pointer pages authenticate an aligned voice slot.
    * No arbitrary scan through sample bytes is performed. */
   unsigned page=(unsigned)((p+0x9600)>>8);uint64_t data=sxsb24(b+199),frames=sxsb24(b+202);
   if(page>255||b[35]!=page||b[39]!=page||data<p+256||data>0x76a00||frames>0x76a00-data)break;
   if(!SXSB_ADD(c,emulator2_voice,p))return false;
   if(data<limit)limit=data;
   voices++;p+=256;continue;
  }
  uint16_t n=(uint16_t)sxsb16(b);uint64_t q=p+2;
  if(presets>=100||!sxsb_eii_preset(c,q,n,limit,false))break;
  if(!SXSB_ADD(c,emulator2_preset_length,p))return false;
  while(presets<100&&sxsb_eii_preset(c,q,n,limit,false)){
   if(!SXSB_ADD(c,emulator2_preset_header,q)||!sxsb_eii_preset(c,q,n,limit,true))return false;
   uint8_t len[2];if(!sxsb_read(c,q+n-2,len,2))return false;q+=n;n=(uint16_t)sxsb16(len);presets++;if(!n)break;
  }
  p=(q+255)&~UINT64_C(255);
 }
 return true;
}
static bool sxsb_casio(sx_context*c){
 uint8_t h[24],b[656],v[192];if(c->size<3072||(c->size&1023)||!sxsb_read(c,1000,h,24))return false;
 uint32_t banks=1,voices=0,wave=sxsb16(h+12);bool declared=h[7]||h[8]||wave,referenced[64]={false};
 if(declared){banks=h[7];voices=h[8];if((h[5]!=0&&h[5]!=2)||h[6]||!banks||banks>8||!voices||voices>64||!wave||(h[5]==2&&banks!=1)||(uint64_t)(banks+(voices+3)/4+wave)*1024!=(uint64_t)c->size)return false;}
 for(uint32_t k=0;k<banks;k++){
  if(!sxsb_read(c,(uint64_t)k*1024,b,656))return false;uint32_t areas=sxsb16(b);if(!areas||areas>64)return false;
  for(uint32_t i=0;i<areas;i++){uint32_t id=sxsb16(b+514+2*i);if(id>=(declared?voices:64))return false;referenced[id]=true;if(!declared&&id+1>voices)voices=id+1;}
 }
 uint64_t audio=(uint64_t)(banks+(voices+3)/4)*1024;if(audio>=(uint64_t)c->size)return false;
 for(uint32_t k=0;k<banks;k++)if(!SXSB_ADD(c,casio_fz_bank,(uint64_t)k*1024))return false;
 if(declared&&(!SXSB_ADD(c,casio_fzf_dump_workspace,1000)||(!h[5]&&!SXSB_ADD(c,casio_fz_effect,960))))return false;
 for(uint32_t i=0;i<voices;i++)if(declared||referenced[i]){
  uint64_t p=(uint64_t)banks*1024+i*256;if(!sxsb_read(c,p,v,192))return false;
  uint32_t a=sxsb32(v),z=sxsb32(v+4),g=sxsb32(v+8),e=sxsb32(v+12);
  if(a>g||g>e||e>z||z>((uint64_t)c->size-audio)/2)continue;
  if(!SXSB_ADD(c,casio_fz_voice,p))return false;
 }
 return true;
}
static int sxsb_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxsb_finish(sx_context*c){size_t n=c->count;int64_t end=0;if(!n)return false;xx_rt_qsort(c->items,n,sizeof(*c->items),sxsb_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxsb_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_samplebanks_supports(xx_file_type_t t){return t==XX_FILE_TYPE_EMAX_DISK||t==XX_FILE_TYPE_EMULATORII_EII||t==XX_FILE_TYPE_CASIO_FZF;}
static bool sx_samplebanks_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_EMAX_DISK:ok=sxsb_emax(c);break;case XX_FILE_TYPE_EMULATORII_EII:ok=sxsb_eii(c);break;case XX_FILE_TYPE_CASIO_FZF:ok=sxsb_casio(c);break;default:break;}return ok&&sxsb_finish(c);}
#undef SXSB_ADD
#undef SXSB_TABLE
#undef SXSB_LIMIT
