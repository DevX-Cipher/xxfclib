/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical music header and table metadata; compressed and unknown bodies stay raw. */
static const xx_data_struct_field_desc sxmn_a2m_header_fields[]={
 SX_FIELD("magic","char[10]",0,10,SX_SIGNATURE),
 SX_FIELD("crc32","uint32",10,4,SX_CHECKSUM),
 SX_FIELD("version","uint8",14,1,SX_ID),
 SX_FIELD("patterns","uint8",15,1,SX_COUNT_PROP),
};
static const sx_layout sxmn_a2m_header={UINT32_C(0x60760001),"a2m_header",sxmn_a2m_header_fields,SX_COUNT(sxmn_a2m_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_a2t_header_fields[]={
 SX_FIELD("magic","char[15]",0,15,SX_SIGNATURE),
 SX_FIELD("crc32","uint32",15,4,SX_CHECKSUM),
 SX_FIELD("version","uint8",19,1,SX_ID),
 SX_FIELD("patterns","uint8",20,1,SX_COUNT_PROP),
 SX_FIELD("tempo","uint8",21,1,SX_NONE),
 SX_FIELD("speed","uint8",22,1,SX_NONE),
};
static const sx_layout sxmn_a2t_header={UINT32_C(0x60760002),"a2t_header",sxmn_a2t_header_fields,SX_COUNT(sxmn_a2t_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_a2t_flags_fields[]={
 SX_FIELD("common_flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxmn_a2t_flags={UINT32_C(0x60760003),"a2t_flags",sxmn_a2t_flags_fields,SX_COUNT(sxmn_a2t_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_a2t_timing_fields[]={
 SX_FIELD("common_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("pattern_rows","uint16",1,2,SX_COUNT_PROP),
 SX_FIELD("tracks","uint8",3,1,SX_COUNT_PROP),
 SX_FIELD("macro_speedup","uint16",4,2,SX_NONE),
};
static const sx_layout sxmn_a2t_timing={UINT32_C(0x60760004),"a2t_timing",sxmn_a2t_timing_fields,SX_COUNT(sxmn_a2t_timing_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_a2t_locks_fields[]={
 SX_FIELD("four_operator_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel0_lock_flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("channel1_lock_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("channel2_lock_flags","uint8",3,1,SX_FLAGS),
 SX_FIELD("channel3_lock_flags","uint8",4,1,SX_FLAGS),
 SX_FIELD("channel4_lock_flags","uint8",5,1,SX_FLAGS),
 SX_FIELD("channel5_lock_flags","uint8",6,1,SX_FLAGS),
 SX_FIELD("channel6_lock_flags","uint8",7,1,SX_FLAGS),
 SX_FIELD("channel7_lock_flags","uint8",8,1,SX_FLAGS),
 SX_FIELD("channel8_lock_flags","uint8",9,1,SX_FLAGS),
 SX_FIELD("channel9_lock_flags","uint8",10,1,SX_FLAGS),
 SX_FIELD("channel10_lock_flags","uint8",11,1,SX_FLAGS),
 SX_FIELD("channel11_lock_flags","uint8",12,1,SX_FLAGS),
 SX_FIELD("channel12_lock_flags","uint8",13,1,SX_FLAGS),
 SX_FIELD("channel13_lock_flags","uint8",14,1,SX_FLAGS),
 SX_FIELD("channel14_lock_flags","uint8",15,1,SX_FLAGS),
 SX_FIELD("channel15_lock_flags","uint8",16,1,SX_FLAGS),
 SX_FIELD("channel16_lock_flags","uint8",17,1,SX_FLAGS),
 SX_FIELD("channel17_lock_flags","uint8",18,1,SX_FLAGS),
 SX_FIELD("channel18_lock_flags","uint8",19,1,SX_FLAGS),
 SX_FIELD("channel19_lock_flags","uint8",20,1,SX_FLAGS),
};
static const sx_layout sxmn_a2t_locks={UINT32_C(0x60760005),"a2t_locks",sxmn_a2t_locks_fields,SX_COUNT(sxmn_a2t_locks_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_packed_length16_fields[]={
 SX_FIELD("packed_bytes","uint16",0,2,SX_SIZE),
};
static const sx_layout sxmn_packed_length16={UINT32_C(0x60760006),"packed_length16",sxmn_packed_length16_fields,SX_COUNT(sxmn_packed_length16_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_packed_length32_fields[]={
 SX_FIELD("packed_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxmn_packed_length32={UINT32_C(0x60760007),"packed_length32",sxmn_packed_length32_fields,SX_COUNT(sxmn_packed_length32_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_mus_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("score_bytes","uint16",4,2,SX_SIZE),
 SX_FIELD("score_offset","uint16",6,2,SX_OFFSET),
 SX_FIELD("primary_channels","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("secondary_channels","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("instruments","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("reserved","uint16",14,2,SX_RESERVED),
};
static const sx_layout sxmn_mus_header={UINT32_C(0x60760008),"mus_header",sxmn_mus_header_fields,SX_COUNT(sxmn_mus_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_mus_instrument_fields[]={
 SX_FIELD("instrument","uint16",0,2,SX_ID),
};
static const sx_layout sxmn_mus_instrument={UINT32_C(0x60760009),"mus_instrument",sxmn_mus_instrument_fields,SX_COUNT(sxmn_mus_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_iff_form_fields[]={
 SX_FIELD("id","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","char[4]",8,4,SX_ID),
};
static const sx_layout sxmn_iff_form={UINT32_C(0x6076000A),"iff_form",sxmn_iff_form_fields,SX_COUNT(sxmn_iff_form_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_iff_chunk_fields[]={
 SX_FIELD("id","char[4]",0,4,SX_ID),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmn_iff_chunk={UINT32_C(0x6076000B),"iff_chunk",sxmn_iff_chunk_fields,SX_COUNT(sxmn_iff_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_xmi_info_fields[]={
 SX_FIELD("sequences","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmn_xmi_info={UINT32_C(0x6076000C),"xmi_info",sxmn_xmi_info_fields,SX_COUNT(sxmn_xmi_info_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_xmi_timb_fields[]={
 SX_FIELD("timbres","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmn_xmi_timb={UINT32_C(0x6076000D),"xmi_timb",sxmn_xmi_timb_fields,SX_COUNT(sxmn_xmi_timb_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_xmi_timbre_fields[]={
 SX_FIELD("program","uint8",0,1,SX_ID),
 SX_FIELD("bank","uint8",1,1,SX_ID),
};
static const sx_layout sxmn_xmi_timbre={UINT32_C(0x6076000E),"xmi_timbre",sxmn_xmi_timbre_fields,SX_COUNT(sxmn_xmi_timbre_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_xmi_rbrn_fields[]={
 SX_FIELD("branches","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmn_xmi_rbrn={UINT32_C(0x6076000F),"xmi_rbrn",sxmn_xmi_rbrn_fields,SX_COUNT(sxmn_xmi_rbrn_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_xmi_branch_fields[]={
 SX_FIELD("branch_id","uint16",0,2,SX_ID),
 SX_FIELD("event_offset","uint32",2,4,SX_OFFSET),
};
static const sx_layout sxmn_xmi_branch={UINT32_C(0x60760010),"xmi_branch",sxmn_xmi_branch_fields,SX_COUNT(sxmn_xmi_branch_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_kss_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("load_address","uint16",4,2,SX_ADDRESS),
 SX_FIELD("load_bytes","uint16",6,2,SX_SIZE),
 SX_FIELD("init_address","uint16",8,2,SX_ADDRESS),
 SX_FIELD("play_address","uint16",10,2,SX_ADDRESS),
 SX_FIELD("first_bank","uint8",12,1,SX_ID),
 SX_FIELD("bank_mode","uint8",13,1,SX_FLAGS),
 SX_FIELD("extra_header_bytes","uint8",14,1,SX_SIZE),
 SX_FIELD("device_flags","uint8",15,1,SX_FLAGS),
};
static const sx_layout sxmn_kss_header={UINT32_C(0x60760011),"kss_header",sxmn_kss_header_fields,SX_COUNT(sxmn_kss_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_kss_extended_fields[]={
 SX_FIELD("data_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("reserved","bytes",4,4,SX_RESERVED),
 SX_FIELD("first_track","uint16",8,2,SX_ID),
 SX_FIELD("last_track","uint16",10,2,SX_ID),
 SX_FIELD("psg_volume","uint8",12,1,SX_NONE),
 SX_FIELD("scc_volume","uint8",13,1,SX_NONE),
 SX_FIELD("msx_music_volume","uint8",14,1,SX_NONE),
 SX_FIELD("msx_audio_volume","uint8",15,1,SX_NONE),
};
static const sx_layout sxmn_kss_extended={UINT32_C(0x60760012),"kss_extended",sxmn_kss_extended_fields,SX_COUNT(sxmn_kss_extended_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_gym_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("song","char[32]",4,32,SX_STRING),
 SX_FIELD("game","char[32]",36,32,SX_STRING),
 SX_FIELD("copyright","char[32]",68,32,SX_STRING),
 SX_FIELD("emulator","char[32]",100,32,SX_STRING),
 SX_FIELD("dumper","char[32]",132,32,SX_STRING),
 SX_FIELD("comment","char[256]",164,256,SX_STRING),
 SX_FIELD("loop_start_frame","uint32",420,4,SX_NONE),
 SX_FIELD("uncompressed_data_bytes","uint32",424,4,SX_SIZE),
};
static const sx_layout sxmn_gym_header={UINT32_C(0x60760013),"gym_header",sxmn_gym_header_fields,SX_COUNT(sxmn_gym_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_gym_frame_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
};
static const sx_layout sxmn_gym_frame={UINT32_C(0x60760014),"gym_frame",sxmn_gym_frame_fields,SX_COUNT(sxmn_gym_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_gym_ym_write_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("register","uint8",1,1,SX_ID),
 SX_FIELD("value","uint8",2,1,SX_NONE),
};
static const sx_layout sxmn_gym_ym_write={UINT32_C(0x60760015),"gym_ym_write",sxmn_gym_ym_write_fields,SX_COUNT(sxmn_gym_ym_write_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_gym_psg_write_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("value","uint8",1,1,SX_NONE),
};
static const sx_layout sxmn_gym_psg_write={UINT32_C(0x60760016),"gym_psg_write",sxmn_gym_psg_write_fields,SX_COUNT(sxmn_gym_psg_write_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_org_header_fields[]={
 SX_FIELD("magic","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("tick_milliseconds","uint16",6,2,SX_NONE),
 SX_FIELD("beats_per_measure","uint8",8,1,SX_NONE),
 SX_FIELD("steps_per_beat","uint8",9,1,SX_NONE),
 SX_FIELD("loop_start","int32",10,4,SX_NONE),
 SX_FIELD("loop_end","int32",14,4,SX_NONE),
};
static const sx_layout sxmn_org_header={UINT32_C(0x60760017),"org_header",sxmn_org_header_fields,SX_COUNT(sxmn_org_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_org_instrument_fields[]={
 SX_FIELD("tuning","uint16",0,2,SX_NONE),
 SX_FIELD("instrument","uint8",2,1,SX_ID),
 SX_FIELD("pi","uint8",3,1,SX_FLAGS),
 SX_FIELD("notes","uint16",4,2,SX_COUNT_PROP),
};
static const sx_layout sxmn_org_instrument={UINT32_C(0x60760018),"org_instrument",sxmn_org_instrument_fields,SX_COUNT(sxmn_org_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_org_position_fields[]={
 SX_FIELD("position","int32",0,4,SX_NONE),
};
static const sx_layout sxmn_org_position={UINT32_C(0x60760019),"org_position",sxmn_org_position_fields,SX_COUNT(sxmn_org_position_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_org_note_fields[]={
 SX_FIELD("note","uint8",0,1,SX_ID),
};
static const sx_layout sxmn_org_note={UINT32_C(0x6076001A),"org_note",sxmn_org_note_fields,SX_COUNT(sxmn_org_note_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_org_length_fields[]={
 SX_FIELD("length","uint8",0,1,SX_NONE),
};
static const sx_layout sxmn_org_length={UINT32_C(0x6076001B),"org_length",sxmn_org_length_fields,SX_COUNT(sxmn_org_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_org_volume_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
};
static const sx_layout sxmn_org_volume={UINT32_C(0x6076001C),"org_volume",sxmn_org_volume_fields,SX_COUNT(sxmn_org_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_org_pan_fields[]={
 SX_FIELD("pan","uint8",0,1,SX_NONE),
};
static const sx_layout sxmn_org_pan={UINT32_C(0x6076001D),"org_pan",sxmn_org_pan_fields,SX_COUNT(sxmn_org_pan_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_header_fields[]={
 SX_FIELD("magic","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("editor_version","uint16",16,2,SX_ID),
 SX_FIELD("reserved","uint16",18,2,SX_RESERVED),
};
static const sx_layout sxmn_pxt_header={UINT32_C(0x6076001E),"pxt_header",sxmn_pxt_header_fields,SX_COUNT(sxmn_pxt_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_chunk_fields[]={
 SX_FIELD("id","char[8]",0,8,SX_ID),
 SX_FIELD("payload_bytes","int32",8,4,SX_SIZE),
};
static const sx_layout sxmn_pxt_chunk={UINT32_C(0x6076001F),"pxt_chunk",sxmn_pxt_chunk_fields,SX_COUNT(sxmn_pxt_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_master_fields[]={
 SX_FIELD("beat_clock","int16",0,2,SX_NONE),
 SX_FIELD("beat_count","int8",2,1,SX_NONE),
 SX_FIELD("tempo","float",3,4,SX_NONE),
 SX_FIELD("repeat_clock","int32",7,4,SX_NONE),
 SX_FIELD("last_clock","int32",11,4,SX_NONE),
};
static const sx_layout sxmn_pxt_master={UINT32_C(0x60760020),"pxt_master",sxmn_pxt_master_fields,SX_COUNT(sxmn_pxt_master_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_unit_count_fields[]={
 SX_FIELD("units","int16",0,2,SX_COUNT_PROP),
 SX_FIELD("reserved","int16",2,2,SX_RESERVED),
};
static const sx_layout sxmn_pxt_unit_count={UINT32_C(0x60760021),"pxt_unit_count",sxmn_pxt_unit_count_fields,SX_COUNT(sxmn_pxt_unit_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_voice_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("version","int32",8,4,SX_ID),
 SX_FIELD("payload_bytes","int32",12,4,SX_SIZE),
};
static const sx_layout sxmn_pxt_voice_header={UINT32_C(0x60760022),"pxt_voice_header",sxmn_pxt_voice_header_fields,SX_COUNT(sxmn_pxt_voice_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_noise_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("version","uint32",8,4,SX_ID),
};
static const sx_layout sxmn_pxt_noise_header={UINT32_C(0x60760023),"pxt_noise_header",sxmn_pxt_noise_header_fields,SX_COUNT(sxmn_pxt_noise_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_noise_samples1_fields[]={
 SX_FIELD("samples_44100hz","uleb128_64",0,1,SX_COUNT_PROP),
};
static const sx_layout sxmn_pxt_noise_samples1={UINT32_C(0x60760024),"pxt_noise_samples1",sxmn_pxt_noise_samples1_fields,SX_COUNT(sxmn_pxt_noise_samples1_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_noise_samples2_fields[]={
 SX_FIELD("samples_44100hz","uleb128_64",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmn_pxt_noise_samples2={UINT32_C(0x60760025),"pxt_noise_samples2",sxmn_pxt_noise_samples2_fields,SX_COUNT(sxmn_pxt_noise_samples2_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_noise_samples3_fields[]={
 SX_FIELD("samples_44100hz","uleb128_64",0,3,SX_COUNT_PROP),
};
static const sx_layout sxmn_pxt_noise_samples3={UINT32_C(0x60760026),"pxt_noise_samples3",sxmn_pxt_noise_samples3_fields,SX_COUNT(sxmn_pxt_noise_samples3_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_noise_samples4_fields[]={
 SX_FIELD("samples_44100hz","uleb128_64",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmn_pxt_noise_samples4={UINT32_C(0x60760027),"pxt_noise_samples4",sxmn_pxt_noise_samples4_fields,SX_COUNT(sxmn_pxt_noise_samples4_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_noise_samples5_fields[]={
 SX_FIELD("samples_44100hz","uleb128_64",0,5,SX_COUNT_PROP),
};
static const sx_layout sxmn_pxt_noise_samples5={UINT32_C(0x60760028),"pxt_noise_samples5",sxmn_pxt_noise_samples5_fields,SX_COUNT(sxmn_pxt_noise_samples5_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_noise_units_fields[]={
 SX_FIELD("units","int8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxmn_pxt_noise_units={UINT32_C(0x60760029),"pxt_noise_units",sxmn_pxt_noise_units_fields,SX_COUNT(sxmn_pxt_noise_units_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_monotone_header_fields[]={
 SX_FIELD("signature_length","uint8",0,1,SX_SIZE),
 SX_FIELD("magic","char[8]",1,8,SX_SIGNATURE),
 SX_FIELD("title_length","uint8",9,1,SX_SIZE),
 SX_FIELD("title","char[40]",10,40,SX_STRING),
 SX_FIELD("comment_length","uint8",50,1,SX_SIZE),
 SX_FIELD("comment","char[40]",51,40,SX_STRING),
 SX_FIELD("version","uint8",91,1,SX_ID),
 SX_FIELD("patterns","uint8",92,1,SX_COUNT_PROP),
 SX_FIELD("tracks","uint8",93,1,SX_COUNT_PROP),
 SX_FIELD("cell_bytes","uint8",94,1,SX_SIZE),
};
static const sx_layout sxmn_monotone_header={UINT32_C(0x6076002A),"monotone_header",sxmn_monotone_header_fields,SX_COUNT(sxmn_monotone_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_monotone_order_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
};
static const sx_layout sxmn_monotone_order={UINT32_C(0x6076002B),"monotone_order",sxmn_monotone_order_fields,SX_COUNT(sxmn_monotone_order_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_monotone_cell_fields[]={
 SX_FIELD("packed_note_effect","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxmn_monotone_cell={UINT32_C(0x6076002C),"monotone_cell",sxmn_monotone_cell_fields,SX_COUNT(sxmn_monotone_cell_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_xad_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("title","char[36]",4,36,SX_STRING),
 SX_FIELD("author","char[36]",40,36,SX_STRING),
 SX_FIELD("player_format","uint16",76,2,SX_ID),
 SX_FIELD("speed","uint8",78,1,SX_NONE),
 SX_FIELD("reserved","uint8",79,1,SX_RESERVED),
};
static const sx_layout sxmn_xad_header={UINT32_C(0x6076002D),"xad_header",sxmn_xad_header_fields,SX_COUNT(sxmn_xad_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_mdx_title_byte_fields[]={
 SX_FIELD("title_byte","char[1]",0,1,SX_STRING),
};
static const sx_layout sxmn_mdx_title_byte={UINT32_C(0x6076002E),"mdx_title_byte",sxmn_mdx_title_byte_fields,SX_COUNT(sxmn_mdx_title_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_mdx_title_end_fields[]={
 SX_FIELD("terminator","bytes",0,3,SX_SIGNATURE),
};
static const sx_layout sxmn_mdx_title_end={UINT32_C(0x6076002F),"mdx_title_end",sxmn_mdx_title_end_fields,SX_COUNT(sxmn_mdx_title_end_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_mdx_pdx_byte_fields[]={
 SX_FIELD("bank_name_byte","char[1]",0,1,SX_STRING),
};
static const sx_layout sxmn_mdx_pdx_byte={UINT32_C(0x60760030),"mdx_pdx_byte",sxmn_mdx_pdx_byte_fields,SX_COUNT(sxmn_mdx_pdx_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_mdx_voice_offset_fields[]={
 SX_FIELD("voice_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxmn_mdx_voice_offset={UINT32_C(0x60760031),"mdx_voice_offset",sxmn_mdx_voice_offset_fields,SX_COUNT(sxmn_mdx_voice_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_mdx_track_offset_fields[]={
 SX_FIELD("track_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxmn_mdx_track_offset={UINT32_C(0x60760032),"mdx_track_offset",sxmn_mdx_track_offset_fields,SX_COUNT(sxmn_mdx_track_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_pdx_entry_fields[]={
 SX_FIELD("sample_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("sample_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmn_pdx_entry={UINT32_C(0x60760033),"pdx_entry",sxmn_pdx_entry_fields,SX_COUNT(sxmn_pdx_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_dsm_riff_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("form","char[4]",8,4,SX_ID),
};
static const sx_layout sxmn_dsm_riff={UINT32_C(0x60760034),"dsm_riff",sxmn_dsm_riff_fields,SX_COUNT(sxmn_dsm_riff_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dsm_chunk_fields[]={
 SX_FIELD("id","char[4]",0,4,SX_ID),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmn_dsm_chunk={UINT32_C(0x60760035),"dsm_chunk",sxmn_dsm_chunk_fields,SX_COUNT(sxmn_dsm_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dsm_song_fields[]={
 SX_FIELD("name","char[28]",0,28,SX_STRING),
 SX_FIELD("version","uint16",28,2,SX_ID),
 SX_FIELD("flags","uint16",30,2,SX_FLAGS),
 SX_FIELD("current_order","uint16",32,2,SX_ID),
 SX_FIELD("restart_order","uint16",34,2,SX_ID),
 SX_FIELD("orders","uint16",36,2,SX_COUNT_PROP),
 SX_FIELD("samples","uint16",38,2,SX_COUNT_PROP),
 SX_FIELD("patterns","uint16",40,2,SX_COUNT_PROP),
 SX_FIELD("channels","uint16",42,2,SX_COUNT_PROP),
 SX_FIELD("global_volume","uint8",44,1,SX_NONE),
 SX_FIELD("master_volume","uint8",45,1,SX_NONE),
 SX_FIELD("speed","uint8",46,1,SX_NONE),
 SX_FIELD("tempo","uint8",47,1,SX_NONE),
 SX_FIELD("channel0_pan","uint8",48,1,SX_NONE),
 SX_FIELD("channel1_pan","uint8",49,1,SX_NONE),
 SX_FIELD("channel2_pan","uint8",50,1,SX_NONE),
 SX_FIELD("channel3_pan","uint8",51,1,SX_NONE),
 SX_FIELD("channel4_pan","uint8",52,1,SX_NONE),
 SX_FIELD("channel5_pan","uint8",53,1,SX_NONE),
 SX_FIELD("channel6_pan","uint8",54,1,SX_NONE),
 SX_FIELD("channel7_pan","uint8",55,1,SX_NONE),
 SX_FIELD("channel8_pan","uint8",56,1,SX_NONE),
 SX_FIELD("channel9_pan","uint8",57,1,SX_NONE),
 SX_FIELD("channel10_pan","uint8",58,1,SX_NONE),
 SX_FIELD("channel11_pan","uint8",59,1,SX_NONE),
 SX_FIELD("channel12_pan","uint8",60,1,SX_NONE),
 SX_FIELD("channel13_pan","uint8",61,1,SX_NONE),
 SX_FIELD("channel14_pan","uint8",62,1,SX_NONE),
 SX_FIELD("channel15_pan","uint8",63,1,SX_NONE),
};
static const sx_layout sxmn_dsm_song={UINT32_C(0x60760036),"dsm_song",sxmn_dsm_song_fields,SX_COUNT(sxmn_dsm_song_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dsm_order_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
};
static const sx_layout sxmn_dsm_order={UINT32_C(0x60760037),"dsm_order",sxmn_dsm_order_fields,SX_COUNT(sxmn_dsm_order_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dsm_sample_fields[]={
 SX_FIELD("filename","char[13]",0,13,SX_STRING),
 SX_FIELD("flags","uint16",13,2,SX_FLAGS),
 SX_FIELD("volume","uint8",15,1,SX_NONE),
 SX_FIELD("sample_frames","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("loop_start_frame","uint32",20,4,SX_NONE),
 SX_FIELD("loop_end_frame","uint32",24,4,SX_NONE),
 SX_FIELD("runtime_data_pointer","uint32",28,4,SX_POINTER),
 SX_FIELD("sample_rate","uint32",32,4,SX_NONE),
 SX_FIELD("name","char[28]",36,28,SX_STRING),
};
static const sx_layout sxmn_dsm_sample={UINT32_C(0x60760038),"dsm_sample",sxmn_dsm_sample_fields,SX_COUNT(sxmn_dsm_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dynamic_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("title","char[20]",5,20,SX_STRING),
 SX_FIELD("artist","char[20]",25,20,SX_STRING),
 SX_FIELD("channels","uint8",45,1,SX_COUNT_PROP),
 SX_FIELD("samples","uint8",46,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint8",47,1,SX_COUNT_PROP),
 SX_FIELD("packing","uint8",48,1,SX_FLAGS),
 SX_FIELD("global_volume","uint8",49,1,SX_NONE),
 SX_FIELD("padding","bytes",50,14,SX_NONE),
};
static const sx_layout sxmn_dynamic_header={UINT32_C(0x60760039),"dynamic_header",sxmn_dynamic_header_fields,SX_COUNT(sxmn_dynamic_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dynamic_pan_fields[]={
 SX_FIELD("pan","uint8",0,1,SX_NONE),
};
static const sx_layout sxmn_dynamic_pan={UINT32_C(0x6076003A),"dynamic_pan",sxmn_dynamic_pan_fields,SX_COUNT(sxmn_dynamic_pan_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dynamic_track_name_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_STRING),
};
static const sx_layout sxmn_dynamic_track_name={UINT32_C(0x6076003B),"dynamic_track_name",sxmn_dynamic_track_name_fields,SX_COUNT(sxmn_dynamic_track_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dynamic_sample_fields[]={
 SX_FIELD("name","char[22]",0,22,SX_STRING),
 SX_FIELD("type","uint8",22,1,SX_ID),
 SX_FIELD("sample_frames","uint16",23,2,SX_COUNT_PROP),
 SX_FIELD("finetune","uint8",25,1,SX_NONE),
 SX_FIELD("volume","uint8",26,1,SX_NONE),
 SX_FIELD("loop_start_frame","uint16",27,2,SX_NONE),
 SX_FIELD("loop_frames","uint16",29,2,SX_COUNT_PROP),
 SX_FIELD("padding","uint8",31,1,SX_NONE),
};
static const sx_layout sxmn_dynamic_sample={UINT32_C(0x6076003C),"dynamic_sample",sxmn_dynamic_sample_fields,SX_COUNT(sxmn_dynamic_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dynamic_event_fields[]={
 SX_FIELD("instrument","uint8",0,1,SX_ID),
 SX_FIELD("packed_note","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxmn_dynamic_event={UINT32_C(0x6076003D),"dynamic_event",sxmn_dynamic_event_fields,SX_COUNT(sxmn_dynamic_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_smus_header_fields[]={
 SX_FIELD("tempo_128ths","uint16",0,2,SX_NONE),
 SX_FIELD("volume","uint8",2,1,SX_NONE),
 SX_FIELD("tracks","uint8",3,1,SX_COUNT_PROP),
};
static const sx_layout sxmn_smus_header={UINT32_C(0x6076003E),"smus_header",sxmn_smus_header_fields,SX_COUNT(sxmn_smus_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_smus_instrument_fields[]={
 SX_FIELD("register","uint8",0,1,SX_ID),
 SX_FIELD("type","uint8",1,1,SX_ID),
 SX_FIELD("data1","uint8",2,1,SX_NONE),
 SX_FIELD("data2","uint8",3,1,SX_NONE),
};
static const sx_layout sxmn_smus_instrument={UINT32_C(0x6076003F),"smus_instrument",sxmn_smus_instrument_fields,SX_COUNT(sxmn_smus_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_smus_event_fields[]={
 SX_FIELD("decision","uint8",0,1,SX_ID),
 SX_FIELD("data","uint8",1,1,SX_NONE),
};
static const sx_layout sxmn_smus_event={UINT32_C(0x60760040),"smus_event",sxmn_smus_event_fields,SX_COUNT(sxmn_smus_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_hvl_header_fields[]={
 SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("names_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("position_flags","uint16",6,2,SX_FLAGS),
 SX_FIELD("channel_restart_flags","uint16",8,2,SX_FLAGS),
 SX_FIELD("track_rows","uint8",10,1,SX_COUNT_PROP),
 SX_FIELD("last_track","uint8",11,1,SX_ID),
 SX_FIELD("instruments","uint8",12,1,SX_COUNT_PROP),
 SX_FIELD("subsongs","uint8",13,1,SX_COUNT_PROP),
 SX_FIELD("mixing_gain_percent","uint8",14,1,SX_NONE),
 SX_FIELD("stereo","uint8",15,1,SX_ID),
};
static const sx_layout sxmn_hvl_header={UINT32_C(0x60760041),"hvl_header",sxmn_hvl_header_fields,SX_COUNT(sxmn_hvl_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_hvl_subsong_fields[]={
 SX_FIELD("position","uint16",0,2,SX_ID),
};
static const sx_layout sxmn_hvl_subsong={UINT32_C(0x60760042),"hvl_subsong",sxmn_hvl_subsong_fields,SX_COUNT(sxmn_hvl_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_hvl_position_fields[]={
 SX_FIELD("track","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
static const sx_layout sxmn_hvl_position={UINT32_C(0x60760043),"hvl_position",sxmn_hvl_position_fields,SX_COUNT(sxmn_hvl_position_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_hvl_empty_event_fields[]={
 SX_FIELD("empty_marker","uint8",0,1,SX_ID),
};
static const sx_layout sxmn_hvl_empty_event={UINT32_C(0x60760044),"hvl_empty_event",sxmn_hvl_empty_event_fields,SX_COUNT(sxmn_hvl_empty_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_hvl_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_ID),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("effects","uint8",2,1,SX_FLAGS),
 SX_FIELD("first_parameter","uint8",3,1,SX_NONE),
 SX_FIELD("second_parameter","uint8",4,1,SX_NONE),
};
static const sx_layout sxmn_hvl_event={UINT32_C(0x60760045),"hvl_event",sxmn_hvl_event_fields,SX_COUNT(sxmn_hvl_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_hvl_instrument_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
 SX_FIELD("filter_wave_flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("attack_frames","uint8",2,1,SX_NONE),
 SX_FIELD("attack_volume","uint8",3,1,SX_NONE),
 SX_FIELD("decay_frames","uint8",4,1,SX_NONE),
 SX_FIELD("decay_volume","uint8",5,1,SX_NONE),
 SX_FIELD("sustain_frames","uint8",6,1,SX_NONE),
 SX_FIELD("release_frames","uint8",7,1,SX_NONE),
 SX_FIELD("release_volume","uint8",8,1,SX_NONE),
 SX_FIELD("unused","bytes",9,3,SX_NONE),
 SX_FIELD("filter_lower_flags","uint8",12,1,SX_FLAGS),
 SX_FIELD("vibrato_delay","uint8",13,1,SX_NONE),
 SX_FIELD("release_vibrato_flags","uint8",14,1,SX_FLAGS),
 SX_FIELD("vibrato_speed","uint8",15,1,SX_NONE),
 SX_FIELD("square_lower","uint8",16,1,SX_NONE),
 SX_FIELD("square_upper","uint8",17,1,SX_NONE),
 SX_FIELD("square_speed","uint8",18,1,SX_NONE),
 SX_FIELD("filter_upper_flags","uint8",19,1,SX_FLAGS),
 SX_FIELD("playlist_speed","uint8",20,1,SX_NONE),
 SX_FIELD("playlist_entries","uint8",21,1,SX_COUNT_PROP),
};
static const sx_layout sxmn_hvl_instrument={UINT32_C(0x60760046),"hvl_instrument",sxmn_hvl_instrument_fields,SX_COUNT(sxmn_hvl_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_hvl_playlist_fields[]={
 SX_FIELD("effect_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("effect_wave_flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("note_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("first_parameter","uint8",3,1,SX_NONE),
 SX_FIELD("second_parameter","uint8",4,1,SX_NONE),
};
static const sx_layout sxmn_hvl_playlist={UINT32_C(0x60760047),"hvl_playlist",sxmn_hvl_playlist_fields,SX_COUNT(sxmn_hvl_playlist_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_hvl_name_byte_fields[]={
 SX_FIELD("name_byte","char[1]",0,1,SX_STRING),
};
static const sx_layout sxmn_hvl_name_byte={UINT32_C(0x60760048),"hvl_name_byte",sxmn_hvl_name_byte_fields,SX_COUNT(sxmn_hvl_name_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_goat_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("title","char[32]",4,32,SX_STRING),
 SX_FIELD("author","char[32]",36,32,SX_STRING),
 SX_FIELD("copyright","char[32]",68,32,SX_STRING),
 SX_FIELD("songs","uint8",100,1,SX_COUNT_PROP),
};
static const sx_layout sxmn_goat_header={UINT32_C(0x60760049),"goat_header",sxmn_goat_header_fields,SX_COUNT(sxmn_goat_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_goat_magic_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxmn_goat_magic={UINT32_C(0x6076004A),"goat_magic",sxmn_goat_magic_fields,SX_COUNT(sxmn_goat_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_goat_order_length_fields[]={
 SX_FIELD("last_order_index","uint8",0,1,SX_ID),
};
static const sx_layout sxmn_goat_order_length={UINT32_C(0x6076004B),"goat_order_length",sxmn_goat_order_length_fields,SX_COUNT(sxmn_goat_order_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_goat_order_fields[]={
 SX_FIELD("pattern_or_command","uint8",0,1,SX_ID),
};
static const sx_layout sxmn_goat_order={UINT32_C(0x6076004C),"goat_order",sxmn_goat_order_fields,SX_COUNT(sxmn_goat_order_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_goat_instrument_count_fields[]={
 SX_FIELD("instruments","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxmn_goat_instrument_count={UINT32_C(0x6076004D),"goat_instrument_count",sxmn_goat_instrument_count_fields,SX_COUNT(sxmn_goat_instrument_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_goat_instrument3_fields[]={
 SX_FIELD("attack_decay","uint8",0,1,SX_FLAGS),
 SX_FIELD("sustain_release","uint8",1,1,SX_FLAGS),
 SX_FIELD("wave_table_index","uint8",2,1,SX_ID),
 SX_FIELD("pulse_table_index","uint8",3,1,SX_ID),
 SX_FIELD("filter_table_index","uint8",4,1,SX_ID),
 SX_FIELD("speed_table_index","uint8",5,1,SX_ID),
 SX_FIELD("vibrato_delay","uint8",6,1,SX_NONE),
 SX_FIELD("gate_timer","uint8",7,1,SX_FLAGS),
 SX_FIELD("first_wave","uint8",8,1,SX_FLAGS),
 SX_FIELD("name","char[16]",9,16,SX_STRING),
};
static const sx_layout sxmn_goat_instrument3={UINT32_C(0x6076004E),"goat_instrument3",sxmn_goat_instrument3_fields,SX_COUNT(sxmn_goat_instrument3_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_goat_instrument2_fields[]={
 SX_FIELD("attack_decay","uint8",0,1,SX_FLAGS),
 SX_FIELD("sustain_release","uint8",1,1,SX_FLAGS),
 SX_FIELD("wave_table_index","uint8",2,1,SX_ID),
 SX_FIELD("pulse_table_index","uint8",3,1,SX_ID),
 SX_FIELD("filter_table_index","uint8",4,1,SX_ID),
 SX_FIELD("vibrato_delay","uint8",5,1,SX_NONE),
 SX_FIELD("vibrato_parameter","uint8",6,1,SX_NONE),
 SX_FIELD("gate_timer","uint8",7,1,SX_FLAGS),
 SX_FIELD("first_wave","uint8",8,1,SX_FLAGS),
 SX_FIELD("name","char[16]",9,16,SX_STRING),
};
static const sx_layout sxmn_goat_instrument2={UINT32_C(0x6076004F),"goat_instrument2",sxmn_goat_instrument2_fields,SX_COUNT(sxmn_goat_instrument2_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_goat_table_count_fields[]={
 SX_FIELD("entries","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxmn_goat_table_count={UINT32_C(0x60760050),"goat_table_count",sxmn_goat_table_count_fields,SX_COUNT(sxmn_goat_table_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_goat_table_left_fields[]={
 SX_FIELD("left","uint8",0,1,SX_NONE),
};
static const sx_layout sxmn_goat_table_left={UINT32_C(0x60760051),"goat_table_left",sxmn_goat_table_left_fields,SX_COUNT(sxmn_goat_table_left_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_goat_table_right_fields[]={
 SX_FIELD("right","uint8",0,1,SX_NONE),
};
static const sx_layout sxmn_goat_table_right={UINT32_C(0x60760052),"goat_table_right",sxmn_goat_table_right_fields,SX_COUNT(sxmn_goat_table_right_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_goat_pattern_count_fields[]={
 SX_FIELD("patterns","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxmn_goat_pattern_count={UINT32_C(0x60760053),"goat_pattern_count",sxmn_goat_pattern_count_fields,SX_COUNT(sxmn_goat_pattern_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_goat_pattern_rows_fields[]={
 SX_FIELD("rows","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxmn_goat_pattern_rows={UINT32_C(0x60760054),"goat_pattern_rows",sxmn_goat_pattern_rows_fields,SX_COUNT(sxmn_goat_pattern_rows_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_goat_event_fields[]={
 SX_FIELD("note_or_end","uint8",0,1,SX_ID),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxmn_goat_event={UINT32_C(0x60760055),"goat_event",sxmn_goat_event_fields,SX_COUNT(sxmn_goat_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dsm1_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("name","char[28]",4,28,SX_STRING),
 SX_FIELD("unknown32","bytes",32,4,SX_NONE),
 SX_FIELD("eof_marker","uint8",36,1,SX_SIGNATURE),
 SX_FIELD("channels","uint8",37,1,SX_COUNT_PROP),
 SX_FIELD("orders","uint8",38,1,SX_COUNT_PROP),
 SX_FIELD("instruments","uint8",39,1,SX_COUNT_PROP),
 SX_FIELD("patterns","uint8",40,1,SX_COUNT_PROP),
 SX_FIELD("speed","uint8",41,1,SX_NONE),
 SX_FIELD("tempo","uint8",42,1,SX_NONE),
 SX_FIELD("global_volume","uint8",43,1,SX_NONE),
 SX_FIELD("unknown44","bytes",44,4,SX_NONE),
};
static const sx_layout sxmn_dsm1_header={UINT32_C(0x60760056),"dsm1_header",sxmn_dsm1_header_fields,SX_COUNT(sxmn_dsm1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dsm1_instrument_paragraph_fields[]={
 SX_FIELD("instrument_paragraph","uint16",0,2,SX_NONE),
};
static const sx_layout sxmn_dsm1_instrument_paragraph={UINT32_C(0x60760057),"dsm1_instrument_paragraph",sxmn_dsm1_instrument_paragraph_fields,SX_COUNT(sxmn_dsm1_instrument_paragraph_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dsm1_pattern_paragraph_fields[]={
 SX_FIELD("pattern_paragraph","uint16",0,2,SX_NONE),
};
static const sx_layout sxmn_dsm1_pattern_paragraph={UINT32_C(0x60760058),"dsm1_pattern_paragraph",sxmn_dsm1_pattern_paragraph_fields,SX_COUNT(sxmn_dsm1_pattern_paragraph_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dsm1_instrument_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("name","char[30]",4,30,SX_STRING),
 SX_FIELD("name_terminator","uint8",34,1,SX_NONE),
 SX_FIELD("sample_paragraph_high","uint8",35,1,SX_NONE),
 SX_FIELD("sample_paragraph_low","uint16",36,2,SX_NONE),
 SX_FIELD("sample_bytes","uint16",38,2,SX_SIZE),
 SX_FIELD("loop_start","uint16",40,2,SX_OFFSET),
 SX_FIELD("loop_end","uint16",42,2,SX_OFFSET),
 SX_FIELD("sample_rate","uint16",44,2,SX_NONE),
 SX_FIELD("volume","uint8",46,1,SX_NONE),
 SX_FIELD("unknown47","bytes",47,17,SX_NONE),
};
static const sx_layout sxmn_dsm1_instrument={UINT32_C(0x60760059),"dsm1_instrument",sxmn_dsm1_instrument_fields,SX_COUNT(sxmn_dsm1_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_dsm1_pattern_fields[]={
 SX_FIELD("packed_bytes","uint16",0,2,SX_SIZE),
};
static const sx_layout sxmn_dsm1_pattern={UINT32_C(0x6076005A),"dsm1_pattern",sxmn_dsm1_pattern_fields,SX_COUNT(sxmn_dsm1_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_fc13_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("sequence_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("patterns_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("patterns_bytes","uint32",12,4,SX_SIZE),
 SX_FIELD("frequency_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("frequency_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("volume_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("volume_bytes","uint32",28,4,SX_SIZE),
 SX_FIELD("samples_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("samples_bytes","uint32",36,4,SX_SIZE),
};
static const sx_layout sxmn_fc13_header={UINT32_C(0x6076005B),"fc13_header",sxmn_fc13_header_fields,SX_COUNT(sxmn_fc13_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_fc14_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("sequence_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("patterns_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("patterns_bytes","uint32",12,4,SX_SIZE),
 SX_FIELD("frequency_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("frequency_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("volume_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("volume_bytes","uint32",28,4,SX_SIZE),
 SX_FIELD("samples_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("wave_table_offset","uint32",36,4,SX_OFFSET),
};
static const sx_layout sxmn_fc14_header={UINT32_C(0x6076005C),"fc14_header",sxmn_fc14_header_fields,SX_COUNT(sxmn_fc14_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_fc_sample_fields[]={
 SX_FIELD("length_words","uint16",0,2,SX_NONE),
 SX_FIELD("loop_start_bytes","uint16",2,2,SX_OFFSET),
 SX_FIELD("loop_words","uint16",4,2,SX_NONE),
};
static const sx_layout sxmn_fc_sample={UINT32_C(0x6076005D),"fc_sample",sxmn_fc_sample_fields,SX_COUNT(sxmn_fc_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_fc_wave_length_fields[]={
 SX_FIELD("length_words","uint8",0,1,SX_NONE),
};
static const sx_layout sxmn_fc_wave_length={UINT32_C(0x6076005E),"fc_wave_length",sxmn_fc_wave_length_fields,SX_COUNT(sxmn_fc_wave_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_fc_sequence_fields[]={
 SX_FIELD("channel0_pattern","uint8",0,1,SX_ID),
 SX_FIELD("channel0_note_transpose","int8",1,1,SX_NONE),
 SX_FIELD("channel0_instrument_transpose","int8",2,1,SX_NONE),
 SX_FIELD("channel1_pattern","uint8",3,1,SX_ID),
 SX_FIELD("channel1_note_transpose","int8",4,1,SX_NONE),
 SX_FIELD("channel1_instrument_transpose","int8",5,1,SX_NONE),
 SX_FIELD("channel2_pattern","uint8",6,1,SX_ID),
 SX_FIELD("channel2_note_transpose","int8",7,1,SX_NONE),
 SX_FIELD("channel2_instrument_transpose","int8",8,1,SX_NONE),
 SX_FIELD("channel3_pattern","uint8",9,1,SX_ID),
 SX_FIELD("channel3_note_transpose","int8",10,1,SX_NONE),
 SX_FIELD("channel3_instrument_transpose","int8",11,1,SX_NONE),
 SX_FIELD("speed","uint8",12,1,SX_NONE),
};
static const sx_layout sxmn_fc_sequence={UINT32_C(0x6076005F),"fc_sequence",sxmn_fc_sequence_fields,SX_COUNT(sxmn_fc_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_fc_pattern_row_fields[]={
 SX_FIELD("note","uint8",0,1,SX_ID),
 SX_FIELD("instrument_info","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxmn_fc_pattern_row={UINT32_C(0x60760060),"fc_pattern_row",sxmn_fc_pattern_row_fields,SX_COUNT(sxmn_fc_pattern_row_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_d1_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("track0_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("track1_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("track2_bytes","uint32",12,4,SX_SIZE),
 SX_FIELD("track3_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("patterns_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("instrument0_bytes","uint32",24,4,SX_SIZE),
 SX_FIELD("instrument1_bytes","uint32",28,4,SX_SIZE),
 SX_FIELD("instrument2_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("instrument3_bytes","uint32",36,4,SX_SIZE),
 SX_FIELD("instrument4_bytes","uint32",40,4,SX_SIZE),
 SX_FIELD("instrument5_bytes","uint32",44,4,SX_SIZE),
 SX_FIELD("instrument6_bytes","uint32",48,4,SX_SIZE),
 SX_FIELD("instrument7_bytes","uint32",52,4,SX_SIZE),
 SX_FIELD("instrument8_bytes","uint32",56,4,SX_SIZE),
 SX_FIELD("instrument9_bytes","uint32",60,4,SX_SIZE),
 SX_FIELD("instrument10_bytes","uint32",64,4,SX_SIZE),
 SX_FIELD("instrument11_bytes","uint32",68,4,SX_SIZE),
 SX_FIELD("instrument12_bytes","uint32",72,4,SX_SIZE),
 SX_FIELD("instrument13_bytes","uint32",76,4,SX_SIZE),
 SX_FIELD("instrument14_bytes","uint32",80,4,SX_SIZE),
 SX_FIELD("instrument15_bytes","uint32",84,4,SX_SIZE),
 SX_FIELD("instrument16_bytes","uint32",88,4,SX_SIZE),
 SX_FIELD("instrument17_bytes","uint32",92,4,SX_SIZE),
 SX_FIELD("instrument18_bytes","uint32",96,4,SX_SIZE),
 SX_FIELD("instrument19_bytes","uint32",100,4,SX_SIZE),
};
static const sx_layout sxmn_d1_header={UINT32_C(0x60760061),"d1_header",sxmn_d1_header_fields,SX_COUNT(sxmn_d1_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_d1_track_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
static const sx_layout sxmn_d1_track={UINT32_C(0x60760062),"d1_track",sxmn_d1_track_fields,SX_COUNT(sxmn_d1_track_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_d1_control_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_ID),
 SX_FIELD("restart_word","uint16",2,2,SX_NONE),
};
static const sx_layout sxmn_d1_control={UINT32_C(0x60760063),"d1_control",sxmn_d1_control_fields,SX_COUNT(sxmn_d1_control_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_d1_pattern_fields[]={
 SX_FIELD("sample","uint8",0,1,SX_ID),
 SX_FIELD("note","uint8",1,1,SX_ID),
 SX_FIELD("effect_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxmn_d1_pattern={UINT32_C(0x60760064),"d1_pattern",sxmn_d1_pattern_fields,SX_COUNT(sxmn_d1_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_d1_instrument_fields[]={
 SX_FIELD("attack_step","uint8",0,1,SX_NONE),
 SX_FIELD("attack_delay","uint8",1,1,SX_NONE),
 SX_FIELD("decay_step","uint8",2,1,SX_NONE),
 SX_FIELD("decay_delay","uint8",3,1,SX_NONE),
 SX_FIELD("sustain","uint16",4,2,SX_NONE),
 SX_FIELD("release_step","uint8",6,1,SX_NONE),
 SX_FIELD("release_delay","uint8",7,1,SX_NONE),
 SX_FIELD("volume","uint8",8,1,SX_NONE),
 SX_FIELD("vibrato_wait","uint8",9,1,SX_NONE),
 SX_FIELD("vibrato_step","uint8",10,1,SX_NONE),
 SX_FIELD("vibrato_length","uint8",11,1,SX_NONE),
 SX_FIELD("pitch_bend","int8",12,1,SX_NONE),
 SX_FIELD("portamento","uint8",13,1,SX_NONE),
 SX_FIELD("sampled","uint8",14,1,SX_FLAGS),
 SX_FIELD("table_delay","uint8",15,1,SX_NONE),
 SX_FIELD("arpeggio0","int8",16,1,SX_NONE),
 SX_FIELD("arpeggio1","int8",17,1,SX_NONE),
 SX_FIELD("arpeggio2","int8",18,1,SX_NONE),
 SX_FIELD("arpeggio3","int8",19,1,SX_NONE),
 SX_FIELD("arpeggio4","int8",20,1,SX_NONE),
 SX_FIELD("arpeggio5","int8",21,1,SX_NONE),
 SX_FIELD("arpeggio6","int8",22,1,SX_NONE),
 SX_FIELD("arpeggio7","int8",23,1,SX_NONE),
 SX_FIELD("sample_bytes","uint16",24,2,SX_SIZE),
 SX_FIELD("loop_start_bytes","uint16",26,2,SX_OFFSET),
 SX_FIELD("repeat_words","uint16",28,2,SX_NONE),
};
static const sx_layout sxmn_d1_instrument={UINT32_C(0x60760065),"d1_instrument",sxmn_d1_instrument_fields,SX_COUNT(sxmn_d1_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_d1_synth_entry_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
static const sx_layout sxmn_d1_synth_entry={UINT32_C(0x60760066),"d1_synth_entry",sxmn_d1_synth_entry_fields,SX_COUNT(sxmn_d1_synth_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_d2_marker_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxmn_d2_marker={UINT32_C(0x60760067),"d2_marker",sxmn_d2_marker_fields,SX_COUNT(sxmn_d2_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_d2_arpeggio_fields[]={
 SX_FIELD("semitones","int8",0,1,SX_NONE),
};
static const sx_layout sxmn_d2_arpeggio={UINT32_C(0x60760068),"d2_arpeggio",sxmn_d2_arpeggio_fields,SX_COUNT(sxmn_d2_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_d2_track_header_fields[]={
 SX_FIELD("restart_bytes","uint16",0,2,SX_OFFSET),
 SX_FIELD("track_bytes","uint16",2,2,SX_SIZE),
};
static const sx_layout sxmn_d2_track_header={UINT32_C(0x60760069),"d2_track_header",sxmn_d2_track_header_fields,SX_COUNT(sxmn_d2_track_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_d2_track_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
static const sx_layout sxmn_d2_track={UINT32_C(0x6076006A),"d2_track",sxmn_d2_track_fields,SX_COUNT(sxmn_d2_track_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_d2_pattern_size_fields[]={
 SX_FIELD("patterns_bytes","uint32",0,4,SX_SIZE),
};
static const sx_layout sxmn_d2_pattern_size={UINT32_C(0x6076006B),"d2_pattern_size",sxmn_d2_pattern_size_fields,SX_COUNT(sxmn_d2_pattern_size_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_d2_pattern_fields[]={
 SX_FIELD("note","uint8",0,1,SX_ID),
 SX_FIELD("sample","uint8",1,1,SX_ID),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxmn_d2_pattern={UINT32_C(0x6076006C),"d2_pattern",sxmn_d2_pattern_fields,SX_COUNT(sxmn_d2_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_d2_instrument_offset_fields[]={
 SX_FIELD("instrument_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxmn_d2_instrument_offset={UINT32_C(0x6076006D),"d2_instrument_offset",sxmn_d2_instrument_offset_fields,SX_COUNT(sxmn_d2_instrument_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxmn_d2_instrument_fields[]={
 SX_FIELD("length_words","uint16",0,2,SX_NONE),
 SX_FIELD("loop_start_bytes","uint16",2,2,SX_OFFSET),
 SX_FIELD("repeat_words","uint16",4,2,SX_NONE),
 SX_FIELD("volume0","uint8",6,1,SX_NONE),
 SX_FIELD("volume1","uint8",7,1,SX_NONE),
 SX_FIELD("volume2","uint8",8,1,SX_NONE),
 SX_FIELD("volume3","uint8",9,1,SX_NONE),
 SX_FIELD("volume4","uint8",10,1,SX_NONE),
 SX_FIELD("volume5","uint8",11,1,SX_NONE),
 SX_FIELD("volume6","uint8",12,1,SX_NONE),
 SX_FIELD("volume7","uint8",13,1,SX_NONE),
 SX_FIELD("volume8","uint8",14,1,SX_NONE),
 SX_FIELD("volume9","uint8",15,1,SX_NONE),
 SX_FIELD("volume10","uint8",16,1,SX_NONE),
 SX_FIELD("volume11","uint8",17,1,SX_NONE),
 SX_FIELD("volume12","uint8",18,1,SX_NONE),
 SX_FIELD("volume13","uint8",19,1,SX_NONE),
 SX_FIELD("volume14","uint8",20,1,SX_NONE),
 SX_FIELD("vibrato0","uint8",21,1,SX_NONE),
 SX_FIELD("vibrato1","uint8",22,1,SX_NONE),
 SX_FIELD("vibrato2","uint8",23,1,SX_NONE),
 SX_FIELD("vibrato3","uint8",24,1,SX_NONE),
 SX_FIELD("vibrato4","uint8",25,1,SX_NONE),
 SX_FIELD("vibrato5","uint8",26,1,SX_NONE),
 SX_FIELD("vibrato6","uint8",27,1,SX_NONE),
 SX_FIELD("vibrato7","uint8",28,1,SX_NONE),
 SX_FIELD("vibrato8","uint8",29,1,SX_NONE),
 SX_FIELD("vibrato9","uint8",30,1,SX_NONE),
 SX_FIELD("vibrato10","uint8",31,1,SX_NONE),
 SX_FIELD("vibrato11","uint8",32,1,SX_NONE),
 SX_FIELD("vibrato12","uint8",33,1,SX_NONE),
 SX_FIELD("vibrato13","uint8",34,1,SX_NONE),
 SX_FIELD("vibrato14","uint8",35,1,SX_NONE),
 SX_FIELD("pitch_bend","uint16",36,2,SX_NONE),
 SX_FIELD("synth_selector","int8",38,1,SX_NONE),
 SX_FIELD("sample_index","uint8",39,1,SX_ID),
 SX_FIELD("table0","uint8",40,1,SX_NONE),
 SX_FIELD("table1","uint8",41,1,SX_NONE),
 SX_FIELD("table2","uint8",42,1,SX_NONE),
 SX_FIELD("table3","uint8",43,1,SX_NONE),
 SX_FIELD("table4","uint8",44,1,SX_NONE),
 SX_FIELD("table5","uint8",45,1,SX_NONE),
 SX_FIELD("table6","uint8",46,1,SX_NONE),
 SX_FIELD("table7","uint8",47,1,SX_NONE),
 SX_FIELD("table8","uint8",48,1,SX_NONE),
 SX_FIELD("table9","uint8",49,1,SX_NONE),
 SX_FIELD("table10","uint8",50,1,SX_NONE),
 SX_FIELD("table11","uint8",51,1,SX_NONE),
 SX_FIELD("table12","uint8",52,1,SX_NONE),
 SX_FIELD("table13","uint8",53,1,SX_NONE),
 SX_FIELD("table14","uint8",54,1,SX_NONE),
 SX_FIELD("table15","uint8",55,1,SX_NONE),
 SX_FIELD("table16","uint8",56,1,SX_NONE),
 SX_FIELD("table17","uint8",57,1,SX_NONE),
 SX_FIELD("table18","uint8",58,1,SX_NONE),
 SX_FIELD("table19","uint8",59,1,SX_NONE),
 SX_FIELD("table20","uint8",60,1,SX_NONE),
 SX_FIELD("table21","uint8",61,1,SX_NONE),
 SX_FIELD("table22","uint8",62,1,SX_NONE),
 SX_FIELD("table23","uint8",63,1,SX_NONE),
 SX_FIELD("table24","uint8",64,1,SX_NONE),
 SX_FIELD("table25","uint8",65,1,SX_NONE),
 SX_FIELD("table26","uint8",66,1,SX_NONE),
 SX_FIELD("table27","uint8",67,1,SX_NONE),
 SX_FIELD("table28","uint8",68,1,SX_NONE),
 SX_FIELD("table29","uint8",69,1,SX_NONE),
 SX_FIELD("table30","uint8",70,1,SX_NONE),
 SX_FIELD("table31","uint8",71,1,SX_NONE),
 SX_FIELD("table32","uint8",72,1,SX_NONE),
 SX_FIELD("table33","uint8",73,1,SX_NONE),
 SX_FIELD("table34","uint8",74,1,SX_NONE),
 SX_FIELD("table35","uint8",75,1,SX_NONE),
 SX_FIELD("table36","uint8",76,1,SX_NONE),
 SX_FIELD("table37","uint8",77,1,SX_NONE),
 SX_FIELD("table38","uint8",78,1,SX_NONE),
 SX_FIELD("table39","uint8",79,1,SX_NONE),
 SX_FIELD("table40","uint8",80,1,SX_NONE),
 SX_FIELD("table41","uint8",81,1,SX_NONE),
 SX_FIELD("table42","uint8",82,1,SX_NONE),
 SX_FIELD("table43","uint8",83,1,SX_NONE),
 SX_FIELD("table44","uint8",84,1,SX_NONE),
 SX_FIELD("table45","uint8",85,1,SX_NONE),
 SX_FIELD("table46","uint8",86,1,SX_NONE),
 SX_FIELD("table47","uint8",87,1,SX_NONE),
};
static const sx_layout sxmn_d2_instrument={UINT32_C(0x6076006E),"d2_instrument",sxmn_d2_instrument_fields,SX_COUNT(sxmn_d2_instrument_fields),SX_BE};
static const sx_layout *const sx_musicnext_layouts[]={
 &sxmn_a2m_header,
 &sxmn_a2t_header,
 &sxmn_a2t_flags,
 &sxmn_a2t_timing,
 &sxmn_a2t_locks,
 &sxmn_packed_length16,
 &sxmn_packed_length32,
 &sxmn_mus_header,
 &sxmn_mus_instrument,
 &sxmn_iff_form,
 &sxmn_iff_chunk,
 &sxmn_xmi_info,
 &sxmn_xmi_timb,
 &sxmn_xmi_timbre,
 &sxmn_xmi_rbrn,
 &sxmn_xmi_branch,
 &sxmn_kss_header,
 &sxmn_kss_extended,
 &sxmn_gym_header,
 &sxmn_gym_frame,
 &sxmn_gym_ym_write,
 &sxmn_gym_psg_write,
 &sxmn_org_header,
 &sxmn_org_instrument,
 &sxmn_org_position,
 &sxmn_org_note,
 &sxmn_org_length,
 &sxmn_org_volume,
 &sxmn_org_pan,
 &sxmn_pxt_header,
 &sxmn_pxt_chunk,
 &sxmn_pxt_master,
 &sxmn_pxt_unit_count,
 &sxmn_pxt_voice_header,
 &sxmn_pxt_noise_header,
 &sxmn_pxt_noise_samples1,
 &sxmn_pxt_noise_samples2,
 &sxmn_pxt_noise_samples3,
 &sxmn_pxt_noise_samples4,
 &sxmn_pxt_noise_samples5,
 &sxmn_pxt_noise_units,
 &sxmn_monotone_header,
 &sxmn_monotone_order,
 &sxmn_monotone_cell,
 &sxmn_xad_header,
 &sxmn_mdx_title_byte,
 &sxmn_mdx_title_end,
 &sxmn_mdx_pdx_byte,
 &sxmn_mdx_voice_offset,
 &sxmn_mdx_track_offset,
 &sxmn_pdx_entry,
 &sxmn_dsm_riff,
 &sxmn_dsm_chunk,
 &sxmn_dsm_song,
 &sxmn_dsm_order,
 &sxmn_dsm_sample,
 &sxmn_dynamic_header,
 &sxmn_dynamic_pan,
 &sxmn_dynamic_track_name,
 &sxmn_dynamic_sample,
 &sxmn_dynamic_event,
 &sxmn_smus_header,
 &sxmn_smus_instrument,
 &sxmn_smus_event,
 &sxmn_hvl_header,
 &sxmn_hvl_subsong,
 &sxmn_hvl_position,
 &sxmn_hvl_empty_event,
 &sxmn_hvl_event,
 &sxmn_hvl_instrument,
 &sxmn_hvl_playlist,
 &sxmn_hvl_name_byte,
 &sxmn_goat_header,
 &sxmn_goat_magic,
 &sxmn_goat_order_length,
 &sxmn_goat_order,
 &sxmn_goat_instrument_count,
 &sxmn_goat_instrument3,
 &sxmn_goat_instrument2,
 &sxmn_goat_table_count,
 &sxmn_goat_table_left,
 &sxmn_goat_table_right,
 &sxmn_goat_pattern_count,
 &sxmn_goat_pattern_rows,
 &sxmn_goat_event,
 &sxmn_dsm1_header,
 &sxmn_dsm1_instrument_paragraph,
 &sxmn_dsm1_pattern_paragraph,
 &sxmn_dsm1_instrument,
 &sxmn_dsm1_pattern,
 &sxmn_fc13_header,
 &sxmn_fc14_header,
 &sxmn_fc_sample,
 &sxmn_fc_wave_length,
 &sxmn_fc_sequence,
 &sxmn_fc_pattern_row,
 &sxmn_d1_header,
 &sxmn_d1_track,
 &sxmn_d1_control,
 &sxmn_d1_pattern,
 &sxmn_d1_instrument,
 &sxmn_d1_synth_entry,
 &sxmn_d2_marker,
 &sxmn_d2_arpeggio,
 &sxmn_d2_track_header,
 &sxmn_d2_track,
 &sxmn_d2_pattern_size,
 &sxmn_d2_pattern,
 &sxmn_d2_instrument_offset,
 &sxmn_d2_instrument,
};
/* Stream metadata directly: a large ROM/disc payload never becomes a scratch buffer. */
typedef struct sxmn_view {sx_context*c;unsigned work;}sxmn_view;
static bool sxmn_span(sxmn_view*v,uint64_t at,uint64_t n,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&v->c->size>=0&&end<=(uint64_t)v->c->size&&at<=end&&n<=end-at;}
static bool sxmn_read(sxmn_view*v,uint64_t at,void*p,size_t n,uint64_t end)
{return sxmn_span(v,at,n,end)&&sx_read(v->c,(int64_t)at,p,n);}
static bool sxmn_word(sxmn_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!n||n>8||!sxmn_read(v,at,b,n,end))return false;uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[be?n-i-1:i]<<(8*i);*out=x;return true;}
static bool sxmn_row(sxmn_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxmn_span(v,at,z,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)z);}
#define MN_ROW(l,at,end) sxmn_row(v,&sxmn_##l,(at),(end))
static bool sxmn_table(sxmn_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>4000000||count>UINT64_MAX/z||!sxmn_span(v,at,count*z,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++,at+=z)if(!sxmn_row(v,l,at,end))return false;return true;}
static int sxmn_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxmn_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxmn_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxmn_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxmn_cstring(sxmn_view*v,uint64_t*p,uint64_t end,uint64_t max)
{uint64_t start=*p,c;while(*p<end&&*p-start<max){if(++v->work>4000000||!sxmn_word(v,*p,1,false,&c,end))return false;(*p)++;if(!c)return true;}return false;}
static bool sxmn_magic(sxmn_view*v,uint64_t at,const char*s,size_t n,uint64_t end)
{uint8_t b[32];return n<=sizeof(b)&&sxmn_read(v,at,b,n,end)&&!xx_rt_memcmp(b,s,n);}
static bool sxmn_a2(sxmn_view*v,bool tiny)
{uint64_t end=v->c->size,version,n,at,width,count,payload;if(!sxmn_word(v,tiny?19:14,1,false,&version,end)||version<1||version>14||!sxmn_row(v,tiny?&sxmn_a2t_header:&sxmn_a2m_header,0,end))return false;
 at=tiny?23:16;width=version<9?2:4;if(tiny){count=version<5?6:version<9?10:version<11?20:21;if(version>=5&&version<9){if(!MN_ROW(a2t_flags,at,end))return false;at++;}else if(version>=9){if(!MN_ROW(a2t_timing,at,end))return false;at+=6;if(version>=10){if(!MN_ROW(a2t_locks,at,end))return false;at+=21;}}}else count=version<5?5:version<9?9:17;
 if(!sxmn_table(v,width==2?&sxmn_packed_length16:&sxmn_packed_length32,at,count,end))return false;payload=at+count*width;
 /* Length table is physical for every version. Unused historical slots may contain rubbish; only active blocks bound payloads. */
 if(!sxmn_word(v,tiny?20:15,1,false,&n,end)||!n||n>128)return false;uint64_t active=(n+(version<5?15:7))/(version<5?16:8)+(tiny?(version<9?2:version<11?4:5):1);if(active>count)active=count;
 for(uint64_t i=0;i<active;i++){uint64_t z;if(!sxmn_word(v,at+i*width,width,false,&z,end)||!sxmn_span(v,payload,z,end))return false;payload+=z;}return true;}
static bool sxmn_mus(sxmn_view*v)
{uint64_t e=v->c->size,n,at,z;return MN_ROW(mus_header,0,e)&&sxmn_word(v,12,2,false,&n,e)&&sxmn_table(v,&sxmn_mus_instrument,16,n,e)&&sxmn_word(v,6,2,false,&at,e)&&sxmn_word(v,4,2,false,&z,e)&&at>=16+n*2&&sxmn_span(v,at,z,e);}
static bool sxmn_iff(sxmn_view*v,uint64_t at,uint64_t end,unsigned depth,bool smus)
{if(depth>12)return false;while(at<end){uint8_t id[4];uint64_t z;if(++v->work>4000000||!sxmn_read(v,at,id,4,end)||!sxmn_word(v,at+4,4,true,&z,end)||!sxmn_span(v,at+8,z,end))return false;uint64_t data=at+8,limit=data+z;
 if(!xx_rt_memcmp(id,"FORM",4)||!xx_rt_memcmp(id,"CAT ",4)||!xx_rt_memcmp(id,"LIST",4)){if(z<4||!MN_ROW(iff_form,at,end)||!sxmn_iff(v,data+4,limit,depth+1,smus))return false;}
 else {if(!MN_ROW(iff_chunk,at,end))return false;if(smus){if(!xx_rt_memcmp(id,"SHDR",4)){if(!MN_ROW(smus_header,data,limit))return false;}else if(!xx_rt_memcmp(id,"INS1",4)){if(!MN_ROW(smus_instrument,data,limit))return false;}else if(!xx_rt_memcmp(id,"TRAK",4)){if(z%2||!sxmn_table(v,&sxmn_smus_event,data,z/2,limit))return false;}}
 else if(!xx_rt_memcmp(id,"INFO",4)){if(!MN_ROW(xmi_info,data,limit))return false;}else if(!xx_rt_memcmp(id,"TIMB",4)||!xx_rt_memcmp(id,"RBRN",4)){uint64_t n;bool timb=id[0]=='T';if(!sxmn_row(v,timb?&sxmn_xmi_timb:&sxmn_xmi_rbrn,data,limit)||!sxmn_word(v,data,2,false,&n,limit)||!sxmn_table(v,timb?&sxmn_xmi_timbre:&sxmn_xmi_branch,data+2,n,limit))return false;}}
 if(z&1){if(!sxmn_span(v,limit,1,end))return false;limit++;}at=limit;}return at==end;}
static bool sxmn_kss(sxmn_view*v)
{uint64_t end=v->c->size,extra,z,bank;if(!MN_ROW(kss_header,0,end)||!sxmn_word(v,14,1,false,&extra,end)||!sxmn_word(v,6,2,false,&z,end)||!sxmn_word(v,13,1,false,&bank,end)||!sxmn_span(v,16,extra,end)||!sxmn_span(v,16+extra,z,end))return false;if(extra>=16&&!MN_ROW(kss_extended,16,end))return false;uint64_t banksize=(bank&128)?8192:16384;return sxmn_span(v,16+extra+z,(bank&127)*banksize,end);}
static bool sxmn_gym(sxmn_view*v,bool header)
{uint64_t end=v->c->size,at=0,packed=0;if(header){if(!MN_ROW(gym_header,0,end)||!sxmn_word(v,424,4,false,&packed,end))return false;at=428;if(packed)return true;}while(at<end){uint64_t op;if(!sxmn_word(v,at,1,false,&op,end)||op>3)return false;const sx_layout*l=op==0?&sxmn_gym_frame:op==3?&sxmn_gym_psg_write:&sxmn_gym_ym_write;if(!sxmn_row(v,l,at,end))return false;at+=op==0?1:op==3?2:3;}return true;}
static bool sxmn_org(sxmn_view*v)
{uint64_t end=v->c->size,at=114;if(!MN_ROW(org_header,0,end)||!sxmn_table(v,&sxmn_org_instrument,18,16,end))return false;for(unsigned i=0;i<16;i++){uint64_t n;if(!sxmn_word(v,22+6*i,2,false,&n,end)||!sxmn_table(v,&sxmn_org_position,at,n,end))return false;at+=n*4;const sx_layout*fields[]={&sxmn_org_note,&sxmn_org_length,&sxmn_org_volume,&sxmn_org_pan};for(unsigned j=0;j<4;j++){if(!sxmn_table(v,fields[j],at,n,end))return false;at+=n;}}return true;}
static bool sxmn_pxt(sxmn_view*v)
{uint64_t end=v->c->size,at=20;if(!sxmn_magic(v,0,"PTTUNE--20071119",16,end)&&!sxmn_magic(v,0,"PTCOLLAGE-071119",16,end))return false;
 if(!MN_ROW(pxt_header,0,end))return false;
 while(at<end){uint8_t id[8];uint64_t z;if(!MN_ROW(pxt_chunk,at,end)||!sxmn_read(v,at,id,8,end)||!sxmn_word(v,at+8,4,false,&z,end)||z>INT32_MAX||!sxmn_span(v,at+12,z,end))return false;uint64_t p=at+12,limit=p+z;if(!xx_rt_memcmp(id,"MasterV5",8)){if(z!=15||!MN_ROW(pxt_master,p,limit))return false;}else if(!xx_rt_memcmp(id,"num UNIT",8)){if(z!=4)return false;/* producer struct is two signed16 words; see explicit layout */if(!MN_ROW(pxt_unit_count,p,limit))return false;}at=limit;if(!xx_rt_memcmp(id,"pxtoneND",8))return true;}return false;}
static bool sxmn_ptvoice(sxmn_view*v)
{uint64_t end=v->c->size,z;return MN_ROW(pxt_voice_header,0,end)&&sxmn_word(v,12,4,false,&z,end)&&z<=INT32_MAX&&sxmn_span(v,16,z,end);}
static bool sxmn_noise(sxmn_view*v)
{uint64_t end=v->c->size,at=12,b=0,value=0;if(!MN_ROW(pxt_noise_header,0,end))return false;unsigned width=0;do{if(width==5||!sxmn_word(v,at+width,1,false,&b,end)||(width==4&&(b&240)))return false;value|=(b&127)<<(7*width);width++;}while(b&128);if(value>INT32_MAX)return false;const sx_layout*ls[]={&sxmn_pxt_noise_samples1,&sxmn_pxt_noise_samples2,&sxmn_pxt_noise_samples3,&sxmn_pxt_noise_samples4,&sxmn_pxt_noise_samples5};if(!sxmn_row(v,ls[width-1],at,end)||!MN_ROW(pxt_noise_units,at+width,end)||!sxmn_word(v,at+width,1,false,&b,end)||b>4)return false;return true;}
static bool sxmn_monotone(sxmn_view*v)
{uint64_t end=v->c->size,p,t,z;if(!MN_ROW(monotone_header,0,end)||!sxmn_table(v,&sxmn_monotone_order,95,256,end)||!sxmn_word(v,92,1,false,&p,end)||!sxmn_word(v,93,1,false,&t,end)||!sxmn_word(v,94,1,false,&z,end)||!p||!t||t>16||!z)return false;uint64_t count=p*t*64;if(!sxmn_span(v,351,count*z,end))return false;return z!=2||sxmn_table(v,&sxmn_monotone_cell,351,count,end);}
static bool sxmn_mdx(sxmn_view*v)
{uint64_t end=v->c->size,at=0,start,b,base,first;while(at<end&&!sxmn_magic(v,at,"\r\n\032",3,end)){if(at>65536||++v->work>4000000)return false;at++;}if(!sxmn_table(v,&sxmn_mdx_title_byte,0,at,end)||!MN_ROW(mdx_title_end,at,end))return false;at+=3;start=at;if(!sxmn_cstring(v,&at,end,65536)||!sxmn_table(v,&sxmn_mdx_pdx_byte,start,at-start,end))return false;base=at;if(!MN_ROW(mdx_voice_offset,base,end)||!sxmn_word(v,base+2,2,true,&first,end)||!sxmn_word(v,base+first,1,false,&b,end))return false;unsigned tracks=b==0xe8?16:9;uint64_t voice;if(!sxmn_word(v,base,2,true,&voice,end)||!sxmn_span(v,base,voice,end)||!sxmn_table(v,&sxmn_mdx_track_offset,base+2,tracks,end))return false;for(unsigned i=0;i<tracks;i++){uint64_t rel;if(!sxmn_word(v,base+2+2*i,2,true,&rel,end)||rel<2+2*tracks||!sxmn_span(v,base+rel,1,end))return false;}return true;}
static bool sxmn_pdx(sxmn_view*v)
{uint64_t end=v->c->size,at=0,data=end;while(at<data){uint64_t off,z;if(!MN_ROW(pdx_entry,at,data)||!sxmn_word(v,at,4,true,&off,end)||!sxmn_word(v,at+4,4,true,&z,end))return false;if(off){if(off<at+8||!sxmn_span(v,off,z,end))return false;if(off<data)data=off;}at+=8;if(++v->work>4000000)return false;}return at==data;}
static bool sxmn_hvl(sxmn_view*v)
{uint64_t end=v->c->size,flags,pos,channels,subs,rows,last,ins,at,names;if(!MN_ROW(hvl_header,0,end)||!sxmn_word(v,4,2,true,&names,end)||!sxmn_word(v,6,2,true,&flags,end)||!sxmn_word(v,8,1,false,&channels,end)||!sxmn_word(v,10,1,false,&rows,end)||!sxmn_word(v,11,1,false,&last,end)||!sxmn_word(v,12,1,false,&ins,end)||!sxmn_word(v,13,1,false,&subs,end))return false;pos=flags&4095;channels=(channels>>2)+4;if(!pos||channels>16||!rows||rows>64||ins>63||!sxmn_table(v,&sxmn_hvl_subsong,16,subs,end)||!sxmn_table(v,&sxmn_hvl_position,16+subs*2,pos*channels,end))return false;at=16+subs*2+pos*channels*2;for(uint64_t t=(flags&0x8000)?1:0;t<=last;t++)for(uint64_t r=0;r<rows;r++){uint64_t b;if(!sxmn_word(v,at,1,false,&b,end)||!sxmn_row(v,b==63?&sxmn_hvl_empty_event:&sxmn_hvl_event,at,end))return false;at+=b==63?1:5;}for(uint64_t i=0;i<ins;i++){uint64_t n;if(!MN_ROW(hvl_instrument,at,end)||!sxmn_word(v,at+21,1,false,&n,end)||!sxmn_table(v,&sxmn_hvl_playlist,at+22,n,end))return false;at+=22+n*5;}if(names<at||names>end)return false;at=names;for(uint64_t i=0;i<=ins;i++){uint64_t start=at;if(!sxmn_cstring(v,&at,end,65536)||!sxmn_table(v,&sxmn_hvl_name_byte,start,at-start,end))return false;}return true;}
static bool sxmn_goat_tables(sxmn_view*v,uint64_t*at,uint64_t end,unsigned count)
{for(unsigned i=0;i<count;i++){uint64_t n;if(!MN_ROW(goat_table_count,*at,end)||!sxmn_word(v,*at,1,false,&n,end))return false;(*at)++;if(!sxmn_table(v,&sxmn_goat_table_left,*at,n,end)||!sxmn_table(v,&sxmn_goat_table_right,*at+n,n,end))return false;*at+=2*n;}return true;}
static bool sxmn_goat(sxmn_view*v,bool instrument)
{uint64_t end=v->c->size,at,n,version;if(!sxmn_word(v,3,1,false,&version,end))return false;
 if(instrument){at=4;if(!MN_ROW(goat_magic,0,end)||!MN_ROW(goat_instrument3,at,end))return false;at+=25;return sxmn_goat_tables(v,&at,end,4);}
 if(!MN_ROW(goat_header,0,end)||!sxmn_word(v,100,1,false,&n,end)||n>32)return false;at=101;for(uint64_t i=0;i<n*3;i++){uint64_t z;if(!MN_ROW(goat_order_length,at,end)||!sxmn_word(v,at,1,false,&z,end)||!sxmn_table(v,&sxmn_goat_order,at+1,z+1,end))return false;at+=z+2;}if(version=='!')return true;
 if(!MN_ROW(goat_instrument_count,at,end)||!sxmn_word(v,at,1,false,&n,end))return false;at++;if(!sxmn_table(v,version=='2'?&sxmn_goat_instrument2:&sxmn_goat_instrument3,at,n,end))return false;at+=25*n;if(!sxmn_goat_tables(v,&at,end,version=='2'?3:4)||!MN_ROW(goat_pattern_count,at,end)||!sxmn_word(v,at,1,false,&n,end))return false;at++;for(uint64_t i=0;i<n;i++){uint64_t z;if(!MN_ROW(goat_pattern_rows,at,end)||!sxmn_word(v,at,1,false,&z,end)||!sxmn_table(v,&sxmn_goat_event,at+1,z,end))return false;at+=1+4*z;}return true;}
static bool sxmn_dsm1(sxmn_view*v)
{uint64_t end=v->c->size,ins,patterns;if(!MN_ROW(dsm1_header,0,end)||!sxmn_word(v,39,1,false,&ins,end)||!sxmn_word(v,40,1,false,&patterns,end)||!sxmn_table(v,&sxmn_dsm_order,48,128,end)||!sxmn_table(v,&sxmn_dsm1_instrument_paragraph,176,ins,end)||!sxmn_table(v,&sxmn_dsm1_pattern_paragraph,176+2*ins,patterns,end))return false;
 for(uint64_t i=0;i<ins;i++){uint64_t para,at,hi,lo,z;if(!sxmn_word(v,176+2*i,2,false,&para,end))return false;if(!para)continue;at=para*16;if(!MN_ROW(dsm1_instrument,at,end)||!sxmn_word(v,at+35,1,false,&hi,end)||!sxmn_word(v,at+36,2,false,&lo,end)||!sxmn_word(v,at+38,2,false,&z,end)||!sxmn_span(v,((hi<<16)|lo)*16,z,end))return false;}
 for(uint64_t i=0;i<patterns;i++){uint64_t para,z;if(!sxmn_word(v,176+2*ins+2*i,2,false,&para,end))return false;if(!para)continue;uint64_t at=para*16;if(!MN_ROW(dsm1_pattern,at,end)||!sxmn_word(v,at,2,false,&z,end)||!sxmn_span(v,at+2,z,end))return false;}return true;}
static bool sxmn_dsmriff(sxmn_view*v)
{uint64_t end=v->c->size,at=12,size;if(!MN_ROW(dsm_riff,0,end)||!sxmn_word(v,4,4,false,&size,end)||!sxmn_span(v,8,size,end))return false;end=8+size;while(at<end){uint64_t z;uint8_t id[4];if(!MN_ROW(dsm_chunk,at,end)||!sxmn_word(v,at+4,4,false,&z,end)||!sxmn_read(v,at,id,4,end)||!sxmn_span(v,at+8,z,end))return false;uint64_t p=at+8,limit=p+z;if(!xx_rt_memcmp(id,"SONG",4)){if(!MN_ROW(dsm_song,p,limit)||!sxmn_table(v,&sxmn_dsm_order,p+64,128,limit))return false;}else if(!xx_rt_memcmp(id,"INST",4)){if(!MN_ROW(dsm_sample,p,limit))return false;}at=limit;/* DSIK chunk writer stores no RIFF padding. */}return true;}
static bool sxmn_dynamic(sxmn_view*v)
{uint64_t end=v->c->size,chn,smp,ord,at,n=0;if(!MN_ROW(dynamic_header,0,end)||!sxmn_word(v,45,1,false,&chn,end)||!sxmn_word(v,46,1,false,&smp,end)||!sxmn_word(v,47,1,false,&ord,end)||!chn||chn>16||!smp||!ord||!sxmn_table(v,&sxmn_dynamic_pan,64,chn,end)||!sxmn_table(v,&sxmn_dsm_order,64+chn,ord,end))return false;for(uint64_t i=0;i<ord;i++){uint64_t x;if(!sxmn_word(v,64+chn+i,1,false,&x,end))return false;if(x>=n)n=x+1;}at=64+chn+ord;if(!sxmn_table(v,&sxmn_dynamic_track_name,at,n*chn,end))return false;at+=n*chn*8;if(!sxmn_table(v,&sxmn_dynamic_sample,at,smp,end))return false;uint64_t samples=at;at+=smp*32;if(!sxmn_table(v,&sxmn_dynamic_event,at,n*chn*64,end))return false;at+=n*chn*64*4;for(uint64_t i=0;i<smp;i++){uint64_t z,t;if(!sxmn_word(v,samples+i*32+22,1,false,&t,end)||!sxmn_word(v,samples+i*32+23,2,false,&z,end))return false;if(t==16)z*=2;if(!sxmn_span(v,at,z,end))return false;at+=z;}return true;}
static bool sxmn_fc(sxmn_view*v,bool v14)
{uint64_t end=v->c->size,header=v14?180:100,sequence;if(!sxmn_row(v,v14?&sxmn_fc14_header:&sxmn_fc13_header,0,end)||!sxmn_table(v,&sxmn_fc_sample,40,10,end)||!sxmn_word(v,4,4,true,&sequence,end))return false;if(v14&&!sxmn_table(v,&sxmn_fc_wave_length,100,80,end))return false;if(!sequence){uint64_t pat;if(!sxmn_word(v,8,4,true,&pat,end)||pat<header)return false;sequence=pat-header;}if(!sxmn_span(v,header,sequence,end)||!sxmn_table(v,&sxmn_fc_sequence,header,sequence/13,end))return false;
 for(unsigned i=0;i<3;i++){uint64_t at,z;if(!sxmn_word(v,8+i*8,4,true,&at,end)||!sxmn_word(v,12+i*8,4,true,&z,end)||!sxmn_span(v,at,z,end))return false;if(!i&&(z%2||!sxmn_table(v,&sxmn_fc_pattern_row,at,z/2,end)))return false;}
 /* Sample packs and waveform bodies stay raw; every referenced outer location is still bounded. */
 uint64_t at;if(!sxmn_word(v,32,4,true,&at,end)||!sxmn_span(v,at,0,end))return false;uint64_t extra;if(!sxmn_word(v,36,4,true,&extra,end))return false;return v14?sxmn_span(v,extra,0,end):sxmn_span(v,at,extra,end);}
static bool sxmn_d1(sxmn_view*v)
{uint64_t end=v->c->size,at=104,lengths[25];if(!MN_ROW(d1_header,0,end))return false;for(unsigned i=0;i<25;i++)if(!sxmn_word(v,4+4*i,4,true,&lengths[i],end))return false;for(unsigned i=0;i<4;i++){uint64_t limit;if(lengths[i]<4||lengths[i]%2||!sxmn_span(v,at,lengths[i],end))return false;limit=at+lengths[i];while(at<limit){uint64_t code;if(!sxmn_word(v,at,2,true,&code,limit))return false;if(code==65535||at==limit-4){if(!MN_ROW(d1_control,at,limit))return false;at+=4;}else{if(!MN_ROW(d1_track,at,limit))return false;at+=2;}}}if(lengths[4]%4||!sxmn_table(v,&sxmn_d1_pattern,at,lengths[4]/4,end))return false;at+=lengths[4];for(unsigned i=5;i<25;i++){uint64_t z=lengths[i],sampled;if(!z)continue;if(!sxmn_span(v,at,z,end)||!MN_ROW(d1_instrument,at,at+z)||!sxmn_word(v,at+14,1,false,&sampled,end))return false;if(!sampled&&!sxmn_table(v,&sxmn_d1_synth_entry,at+30,48,at+z))return false;at+=z;}return true;}
static bool sxmn_d2(sxmn_view*v)
{uint64_t end=v->c->size,at=4058,total=0;if(!MN_ROW(d2_marker,3014,end)||!sxmn_table(v,&sxmn_d2_arpeggio,3018,1024,end)||!sxmn_table(v,&sxmn_d2_track_header,4042,4,end))return false;for(unsigned i=0;i<4;i++){uint64_t z;if(!sxmn_word(v,4044+4*i,2,true,&z,end)||z%2)return false;total+=z;}if(!sxmn_table(v,&sxmn_d2_track,at,total/2,end))return false;at+=total;uint64_t z;if(!MN_ROW(d2_pattern_size,at,end)||!sxmn_word(v,at,4,true,&z,end)||z%4||!sxmn_table(v,&sxmn_d2_pattern,at+4,z/4,end))return false;at+=4+z;if(!sxmn_table(v,&sxmn_d2_instrument_offset,at,128,end))return false;uint64_t base=at+256,sentinel,seen[129]={0};unsigned n=1;if(!sxmn_word(v,at+254,2,true,&sentinel,end))return false;for(unsigned i=0;i<128;i++){uint64_t rel;if(!sxmn_word(v,at+2*i,2,true,&rel,end))return false;if(rel==sentinel)continue;bool found=false;for(unsigned j=0;j<n;j++)if(seen[j]==rel)found=true;if(!found)seen[n++]=rel;}for(unsigned i=0;i<n;i++)if(!MN_ROW(d2_instrument,base+seen[i],end))return false;return true;}

static bool sx_musicnext_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_DIE_MUSIC_SUBZ3RO_ADLIBTRACKER2_A2M:
case XX_FILE_TYPE_DIE_MUSIC_SUBZ3RO_ADLIBTRACKER2_TINY:
case XX_FILE_TYPE_DIE_MUSIC_IDSOFT_DOOM_MUS:
case XX_FILE_TYPE_DIE_MUSIC_EXTENDEDMIDI_XMI:
case XX_FILE_TYPE_DIE_MUSIC_KONAMI_KSS:
case XX_FILE_TYPE_DIE_MUSIC_GENSMD_YM2612_GYM:
case XX_FILE_TYPE_DIE_MUSIC_YM2612REGLOG_GYM:
case XX_FILE_TYPE_DIE_MUSIC_PIXEL_ORGANYA:
case XX_FILE_TYPE_DIE_MUSIC_PIXEL_PXTONE_PTTUNE:
case XX_FILE_TYPE_DIE_MUSIC_PIXEL_PXTONE_PTCOP:
case XX_FILE_TYPE_DIE_MUSIC_PIXEL_PXTONE_PTNOISE:
case XX_FILE_TYPE_DIE_MUSIC_PIXEL_PXTONE_PTVOICE:
case XX_FILE_TYPE_DIE_MUSIC_FAUST_GOATTRACKER_SNG:
case XX_FILE_TYPE_DIE_MUSIC_FAUST_GOATTRACKER2_INS:
case XX_FILE_TYPE_DIE_MUSIC_IRIS_HIVELYTRACKER:
case XX_FILE_TYPE_DIE_MUSIC_TRIXTER_MONOTONE:
case XX_FILE_TYPE_DIE_MUSIC_RIVEN_EXOTICADLIB_XAD:
case XX_FILE_TYPE_DIE_MUSIC_KONAMI_MUSICDATAEXTENDED_MDX:
case XX_FILE_TYPE_DIE_MUSIC_KONAMI_MXDRV_PCM:
case XX_FILE_TYPE_DIE_MUSIC_HASAN_DASIK_DSM:
case XX_FILE_TYPE_DIE_MUSIC_HASAN_DSIK_DSM:
case XX_FILE_TYPE_DIE_MUSIC_THELOOMSYNDICATE_DYNAMICSTUDIO_DSM:
case XX_FILE_TYPE_DIE_MUSIC_SUPERIONS_FUTURECOMPOSER_FC13:
case XX_FILE_TYPE_DIE_MUSIC_SUPERIONS_FUTURECOMPOSER_FC14:
case XX_FILE_TYPE_DIE_MUSIC_SHOGUN_DELTAMUSIC1:
case XX_FILE_TYPE_DIE_MUSIC_SHOGUN_DELTAMUSIC2:
case XX_FILE_TYPE_DIE_MUSIC_SIMPLEMUSICALSCORE_SMUS:
return true;default:return false;}}
static bool sx_musicnext_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxmn_view view={c,0},*v=&view;bool ok=false;
 switch(c->f->file_type){
case XX_FILE_TYPE_DIE_MUSIC_SUBZ3RO_ADLIBTRACKER2_A2M:ok=sxmn_a2(v,false);break;
case XX_FILE_TYPE_DIE_MUSIC_SUBZ3RO_ADLIBTRACKER2_TINY:ok=sxmn_a2(v,true);break;
case XX_FILE_TYPE_DIE_MUSIC_IDSOFT_DOOM_MUS:ok=sxmn_mus(v);break;
case XX_FILE_TYPE_DIE_MUSIC_EXTENDEDMIDI_XMI:ok=sxmn_iff(v,0,(uint64_t)c->size,0,false);break;
case XX_FILE_TYPE_DIE_MUSIC_KONAMI_KSS:ok=sxmn_kss(v);break;
case XX_FILE_TYPE_DIE_MUSIC_GENSMD_YM2612_GYM:ok=sxmn_gym(v,true);break;
case XX_FILE_TYPE_DIE_MUSIC_YM2612REGLOG_GYM:ok=sxmn_gym(v,false);break;
case XX_FILE_TYPE_DIE_MUSIC_PIXEL_ORGANYA:ok=sxmn_org(v);break;
case XX_FILE_TYPE_DIE_MUSIC_PIXEL_PXTONE_PTTUNE:ok=sxmn_pxt(v);break;
case XX_FILE_TYPE_DIE_MUSIC_PIXEL_PXTONE_PTCOP:ok=sxmn_pxt(v);break;
case XX_FILE_TYPE_DIE_MUSIC_PIXEL_PXTONE_PTNOISE:ok=sxmn_noise(v);break;
case XX_FILE_TYPE_DIE_MUSIC_PIXEL_PXTONE_PTVOICE:ok=sxmn_ptvoice(v);break;
case XX_FILE_TYPE_DIE_MUSIC_FAUST_GOATTRACKER_SNG:ok=sxmn_goat(v,false);break;
case XX_FILE_TYPE_DIE_MUSIC_FAUST_GOATTRACKER2_INS:ok=sxmn_goat(v,true);break;
case XX_FILE_TYPE_DIE_MUSIC_IRIS_HIVELYTRACKER:ok=sxmn_hvl(v);break;
case XX_FILE_TYPE_DIE_MUSIC_TRIXTER_MONOTONE:ok=sxmn_monotone(v);break;
case XX_FILE_TYPE_DIE_MUSIC_RIVEN_EXOTICADLIB_XAD:ok=sxmn_row(v,&sxmn_xad_header,0,(uint64_t)c->size);break;
case XX_FILE_TYPE_DIE_MUSIC_KONAMI_MUSICDATAEXTENDED_MDX:ok=sxmn_mdx(v);break;
case XX_FILE_TYPE_DIE_MUSIC_KONAMI_MXDRV_PCM:ok=sxmn_pdx(v);break;
case XX_FILE_TYPE_DIE_MUSIC_HASAN_DASIK_DSM:ok=sxmn_dsm1(v);break;
case XX_FILE_TYPE_DIE_MUSIC_HASAN_DSIK_DSM:ok=sxmn_dsmriff(v);break;
case XX_FILE_TYPE_DIE_MUSIC_THELOOMSYNDICATE_DYNAMICSTUDIO_DSM:ok=sxmn_dynamic(v);break;
case XX_FILE_TYPE_DIE_MUSIC_SUPERIONS_FUTURECOMPOSER_FC13:ok=sxmn_fc(v,false);break;
case XX_FILE_TYPE_DIE_MUSIC_SUPERIONS_FUTURECOMPOSER_FC14:ok=sxmn_fc(v,true);break;
case XX_FILE_TYPE_DIE_MUSIC_SHOGUN_DELTAMUSIC1:ok=sxmn_d1(v);break;
case XX_FILE_TYPE_DIE_MUSIC_SHOGUN_DELTAMUSIC2:ok=sxmn_d2(v);break;
case XX_FILE_TYPE_DIE_MUSIC_SIMPLEMUSICALSCORE_SMUS:ok=sxmn_iff(v,0,(uint64_t)c->size,0,true);break;
default:break;}
 return ok&&sxmn_finish(c);}
#undef MN_ROW
static bool sx_musicnext_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id<UINT32_C(0x60760000)||id>=UINT32_C(0x60770000))return true;
 const wchar_t*note=NULL;bool numeric=xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64;
 if(r->property&SX_OFFSET)note=L"Stored byte offset; relative base is specific to the containing structure";
 else if(r->property&(SX_ADDRESS|SX_POINTER))note=L"Stored runtime memory address, not a file offset";
 if(!xx_rt_wcscmp(r->name,L"tempo_128ths"))note=L"Tempo in 1/128 quarter notes per minute";
 if(id==sxmn_gym_header.id&&!xx_rt_wcscmp(r->name,L"loop_start_frame"))note=L"1/60-second frame index; zero disables looping";
 if(!xx_rt_wcscmp(r->name,L"uncompressed_data_bytes"))note=L"Zero means uncompressed; nonzero records the uncompressed data size in GYMX";
 if(!xx_rt_wcscmp(r->name,L"length_words")||!xx_rt_wcscmp(r->name,L"loop_words")||!xx_rt_wcscmp(r->name,L"repeat_words"))note=L"Stored count of 16-bit words; multiply by two for bytes";
 if(!xx_rt_wcscmp(r->name,L"instrument_paragraph")||!xx_rt_wcscmp(r->name,L"pattern_paragraph")||!xx_rt_wcscmp(r->name,L"sample_paragraph_high")||!xx_rt_wcscmp(r->name,L"sample_paragraph_low"))note=L"Encoded 16-byte paragraph coordinate; not a byte offset";
 if(!xx_rt_wcscmp(r->name,L"voice_offset")||!xx_rt_wcscmp(r->name,L"track_offset"))note=L"Byte offset relative to MDX offset-table start, after the bank-name terminator";
 if(!xx_rt_wcscmp(r->name,L"event_offset"))note=L"Byte offset relative to the XMI EVNT chunk data";
 if(id==sxmn_d2_instrument_offset.id)note=L"Byte offset relative to the end of the 128-entry instrument-offset table";
 if(!xx_rt_wcscmp(r->name,L"restart_bytes"))note=L"Byte position in this channel's two-byte track-entry list";
 if(!xx_rt_wcscmp(r->name,L"runtime_data_pointer"))note=L"Saved playback pointer; not a physical sample-data offset";
 if(!xx_rt_wcscmp(r->name,L"tick_milliseconds"))note=L"Milliseconds per Organya timeline step";
 if((id==sxmn_org_header.id&&(!xx_rt_wcscmp(r->name,L"loop_start")||!xx_rt_wcscmp(r->name,L"loop_end")))||id==sxmn_org_position.id)note=L"Organya timeline step index, not bytes or a wall-clock timestamp";
 if(!xx_rt_wcscmp(r->name,L"samples_44100hz"))note=L"Sample count at 44100 Hz; physical unsigned variable-length encoding";
 if(!xx_rt_wcscmp(r->name,L"last_order_index"))note=L"Following order byte count is stored value plus one";
 if(id==sxmn_d1_control.id&&!xx_rt_wcscmp(r->name,L"restart_word"))note=L"Stored track-sequencer restart/control value; not a physical byte offset";
 if(id==sxmn_d1_instrument.id&&!xx_rt_wcscmp(r->name,L"sampled"))note=L"Zero selects synthesized waveform; nonzero selects sampled audio";
 if(id==sxmn_d2_instrument.id&&!xx_rt_wcscmp(r->name,L"synth_selector"))note=L"Negative selects sampled sound; nonnegative selects synthesized waveform";
 if(!xx_rt_wcscmp(r->name,L"loop_start_bytes")||(id==sxmn_dsm1_instrument.id&&(!xx_rt_wcscmp(r->name,L"loop_start")||!xx_rt_wcscmp(r->name,L"loop_end"))))note=L"Byte offset relative to this sample's data";
 if(id==sxmn_org_instrument.id&&!xx_rt_wcscmp(r->name,L"tuning"))note=L"Frequency adjustment: 1000 is the neutral tuning value";
 if(id==sxmn_monotone_cell.id)note=L"Bits 15..9 note, bits 8..6 effect, bits 5..0 effect data; little-endian word";
 if(id==sxmn_kss_header.id&&!xx_rt_wcscmp(r->name,L"bank_mode"))note=L"Bit 7 selects 8 KiB banks (otherwise 16 KiB); low seven bits are the bank count";
 if(id==sxmn_hvl_header.id&&!xx_rt_wcscmp(r->name,L"position_flags"))note=L"Low 12 bits: position count; bits 14..13: speed multiplier minus one; bit 15: track zero omitted";
 if(id==sxmn_hvl_header.id&&!xx_rt_wcscmp(r->name,L"channel_restart_flags"))note=L"High six bits: channel count minus four; low ten bits: restart position";
 if(id==sxmn_pxt_master.id&&!xx_rt_wcscmp(r->name,L"tempo"))note=L"Quarter-note beats per minute";
 if(id==sxmn_pxt_master.id&&(!xx_rt_wcscmp(r->name,L"repeat_clock")||!xx_rt_wcscmp(r->name,L"last_clock")))note=L"Pxtone timeline clock count; tune files use reduced clock resolution";
 if(id==sxmn_dsm_sample.id&&!xx_rt_wcscmp(r->name,L"flags"))note=L"0x01 loop; 0x02 signed PCM; 0x04 16-bit PCM; 0x40 delta PCM";
 if(id==sxmn_dynamic_sample.id&&!xx_rt_wcscmp(r->name,L"finetune"))note=L"MOD finetune nibble, interpreted as a signed value from -8 through 7";
 if(numeric&&(id==sxmn_a2m_header.id||id==sxmn_a2t_header.id)&&!xx_rt_wcscmp(r->name,L"version")){
  uint64_t x=xx_var_get_u64(&r->value);note=x==1||x==5?L"SixPack":x==2||x==6?L"LZW":x==3||x==7?L"LZSS":x==4||x==8?L"Stored":x>=9&&x<=11?L"aPLib":x>=12&&x<=14?L"LZH":L"Unknown compression version";}
 if(numeric&&(id==sxmn_gym_frame.id||id==sxmn_gym_ym_write.id||id==sxmn_gym_psg_write.id)&&!xx_rt_wcscmp(r->name,L"opcode")){
  uint64_t x=xx_var_get_u64(&r->value);note=x==0?L"Wait one 1/60-second frame":x==1?L"YM2612 port 0 register write":x==2?L"YM2612 port 1 register write":x==3?L"SN76489 PSG write":L"Unknown opcode";}
 if(numeric&&id==sxmn_xad_header.id&&!xx_rt_wcscmp(r->name,L"player_format")){
  uint64_t x=xx_var_get_u64(&r->value);note=x==1?L"HYP":x==2?L"PSI":x==3?L"FLASH":x==4?L"BMF":x==5?L"RAT":x==6?L"HYBRID":L"Unknown XAD player";}
 if(id==sxmn_mus_header.id&&!xx_rt_wcscmp(r->name,L"score_offset"))note=L"Byte offset from the beginning of the MUS file";
 if(id==sxmn_pdx_entry.id&&!xx_rt_wcscmp(r->name,L"sample_offset"))note=L"Byte offset from the beginning of the PDX file";
 if((id==sxmn_fc13_header.id||id==sxmn_fc14_header.id)&&(r->property&SX_OFFSET))note=L"Byte offset from the beginning of the Future Composer file";
 if(id==sxmn_hvl_header.id&&!xx_rt_wcscmp(r->name,L"names_offset"))note=L"Byte offset from the beginning of the Hively file";
 if(numeric&&id==sxmn_smus_instrument.id&&!xx_rt_wcscmp(r->name,L"type")){uint64_t x=xx_var_get_u64(&r->value);note=x==0?L"INS1_Name: instrument name; data1/data2 ignored":x==1?L"INS1_MIDI: data1 channel, data2 preset":L"Unknown instrument reference type";}
 if(numeric&&id==sxmn_smus_event.id&&!xx_rt_wcscmp(r->name,L"decision")){uint64_t x=xx_var_get_u64(&r->value);note=x<=127?L"Note pitch; data encodes duration/tie/chord":x==128?L"SID_Rest":x==129?L"SID_Instrument":x==130?L"SID_TimeSig":x==131?L"SID_KeySig":x==132?L"SID_Dynamic":x==133?L"SID_MIDI_Chnl":x==134?L"SID_MIDI_Preset":x==135?L"SID_Clef":x==136?L"SID_Tempo":x==255?L"SID_Mark":L"Reserved or extended SMUS event";}
 if((id==sxmn_dsm_sample.id||id==sxmn_dynamic_sample.id)&&(!xx_rt_wcscmp(r->name,L"loop_start_frame")||!xx_rt_wcscmp(r->name,L"loop_end_frame")))note=L"Sample-frame position within this instrument, not a GYM timeline frame or file offset";
 if(note&&!xx_data_struct_record_set_comment(r,note))return false;
 return true;
}
