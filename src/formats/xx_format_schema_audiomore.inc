/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical audio-container and stream metadata; coded payload stays raw. */
static const xx_data_struct_field_desc sxau_awb_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("offset_width","uint8",5,1,SX_SIZE),
 SX_FIELD("id_width","uint16",6,2,SX_SIZE),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("alignment","uint16",12,2,SX_SIZE),
 SX_FIELD("subkey","uint16",14,2,SX_ID),
};
static const sx_layout sxau_awb_header={UINT32_C(0x602C0001),"awb_header",sxau_awb_header_fields,SX_COUNT(sxau_awb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_awb_id16_fields[]={
 SX_FIELD("entry_id","uint16",0,2,SX_ID),
};
static const sx_layout sxau_awb_id16={UINT32_C(0x602C0002),"awb_id16",sxau_awb_id16_fields,SX_COUNT(sxau_awb_id16_fields),SX_LE};
static const xx_data_struct_field_desc sxau_awb_offset16_fields[]={
 SX_FIELD("entry_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxau_awb_offset16={UINT32_C(0x602C0003),"awb_offset16",sxau_awb_offset16_fields,SX_COUNT(sxau_awb_offset16_fields),SX_LE};
static const xx_data_struct_field_desc sxau_awb_id32_fields[]={
 SX_FIELD("entry_id","uint32",0,4,SX_ID),
};
static const sx_layout sxau_awb_id32={UINT32_C(0x602C0004),"awb_id32",sxau_awb_id32_fields,SX_COUNT(sxau_awb_id32_fields),SX_LE};
static const xx_data_struct_field_desc sxau_awb_offset32_fields[]={
 SX_FIELD("entry_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxau_awb_offset32={UINT32_C(0x602C0005),"awb_offset32",sxau_awb_offset32_fields,SX_COUNT(sxau_awb_offset32_fields),SX_LE};
static const xx_data_struct_field_desc sxau_xwb_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("header_version","uint32",8,4,SX_ID),
};
static const sx_layout sxau_xwb_header={UINT32_C(0x602C0006),"xwb_header",sxau_xwb_header_fields,SX_COUNT(sxau_xwb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_xwb_segment_fields[]={
 SX_FIELD("segment_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("segment_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxau_xwb_segment={UINT32_C(0x602C0007),"xwb_segment",sxau_xwb_segment_fields,SX_COUNT(sxau_xwb_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxau_xwb_bank_data_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("entry_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("bank_name","char[64]",8,64,SX_STRING),
 SX_FIELD("metadata_entry_size","uint32",72,4,SX_SIZE),
 SX_FIELD("name_entry_size","uint32",76,4,SX_SIZE),
 SX_FIELD("alignment","uint32",80,4,SX_SIZE),
 SX_FIELD("compact_format","uint32",84,4,SX_FLAGS),
 SX_FIELD("build_time","uint64",88,8,SX_TIME),
};
static const sx_layout sxau_xwb_bank_data={UINT32_C(0x602C0008),"xwb_bank_data",sxau_xwb_bank_data_fields,SX_COUNT(sxau_xwb_bank_data_fields),SX_LE};
static const xx_data_struct_field_desc sxau_xwb_entry_fields[]={
 SX_FIELD("flags_and_duration","uint32",0,4,SX_FLAGS),
 SX_FIELD("mini_wave_format","uint32",4,4,SX_FLAGS),
 SX_FIELD("play_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("play_length","uint32",12,4,SX_SIZE),
 SX_FIELD("loop_start_samples","uint32",16,4,SX_NONE),
 SX_FIELD("loop_length_samples","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxau_xwb_entry={UINT32_C(0x602C0009),"xwb_entry",sxau_xwb_entry_fields,SX_COUNT(sxau_xwb_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxau_xact_name_fields[]={
 SX_FIELD("name","char[64]",0,64,SX_STRING),
};
static const sx_layout sxau_xact_name={UINT32_C(0x602C000A),"xact_name",sxau_xact_name_fields,SX_COUNT(sxau_xact_name_fields),SX_LE};
static const xx_data_struct_field_desc sxau_xsb_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("content_version","uint16",4,2,SX_ID),
 SX_FIELD("tool_version","uint16",6,2,SX_ID),
 SX_FIELD("crc","uint16",8,2,SX_CHECKSUM),
 SX_FIELD("last_modified","uint64",10,8,SX_TIME),
 SX_FIELD("platform","uint8",18,1,SX_ID),
 SX_FIELD("simple_cues","uint16",19,2,SX_COUNT_PROP),
 SX_FIELD("complex_cues","uint16",21,2,SX_COUNT_PROP),
 SX_FIELD("unknown_17","bytes",23,4,SX_NONE),
 SX_FIELD("wave_banks","uint8",27,1,SX_COUNT_PROP),
 SX_FIELD("sounds","uint16",28,2,SX_COUNT_PROP),
 SX_FIELD("cue_name_bytes","uint16",30,2,SX_SIZE),
 SX_FIELD("unknown_20","bytes",32,2,SX_NONE),
 SX_FIELD("simple_cues_offset","uint32",34,4,SX_OFFSET),
 SX_FIELD("complex_cues_offset","uint32",38,4,SX_OFFSET),
 SX_FIELD("cue_names_offset","uint32",42,4,SX_OFFSET),
 SX_FIELD("unknown_offset","uint32",46,4,SX_OFFSET),
 SX_FIELD("variation_tables_offset","uint32",50,4,SX_OFFSET),
 SX_FIELD("transition_tables_offset","uint32",54,4,SX_OFFSET),
 SX_FIELD("wave_bank_names_offset","uint32",58,4,SX_OFFSET),
 SX_FIELD("cue_name_hash_offset","uint32",62,4,SX_OFFSET),
 SX_FIELD("cue_name_index_offset","uint32",66,4,SX_OFFSET),
 SX_FIELD("sounds_offset","uint32",70,4,SX_OFFSET),
 SX_FIELD("bank_name","char[64]",74,64,SX_STRING),
};
static const sx_layout sxau_xsb_header={UINT32_C(0x602C000B),"xsb_header",sxau_xsb_header_fields,SX_COUNT(sxau_xsb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_xsb_cue_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("sound_offset","uint32",1,4,SX_OFFSET),
};
static const sx_layout sxau_xsb_cue={UINT32_C(0x602C000C),"xsb_cue",sxau_xsb_cue_fields,SX_COUNT(sxau_xsb_cue_fields),SX_LE};
static const xx_data_struct_field_desc sxau_xsb_simple_sound_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("category","uint16",1,2,SX_ID),
 SX_FIELD("volume","uint8",3,1,SX_NONE),
 SX_FIELD("pitch_cents","int16",4,2,SX_NONE),
 SX_FIELD("priority","uint8",6,1,SX_NONE),
 SX_FIELD("sound_length","uint16",7,2,SX_SIZE),
 SX_FIELD("wave_index","uint16",9,2,SX_ID),
 SX_FIELD("wave_bank_index","uint8",11,1,SX_ID),
};
static const sx_layout sxau_xsb_simple_sound={UINT32_C(0x602C000D),"xsb_simple_sound",sxau_xsb_simple_sound_fields,SX_COUNT(sxau_xsb_simple_sound_fields),SX_LE};
static const xx_data_struct_field_desc sxau_ast_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("encoding","uint16",8,2,SX_ID),
 SX_FIELD("bits_per_sample","uint16",10,2,SX_NONE),
 SX_FIELD("channels","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("loop_flag","uint16",14,2,SX_FLAGS),
 SX_FIELD("sample_rate","uint32",16,4,SX_NONE),
 SX_FIELD("sample_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("loop_start_sample","uint32",24,4,SX_NONE),
 SX_FIELD("loop_end_sample","uint32",28,4,SX_NONE),
 SX_FIELD("first_block_size","uint32",32,4,SX_SIZE),
 SX_FIELD("unknown_tail","bytes",36,28,SX_NONE),
};
static const sx_layout sxau_ast_header={UINT32_C(0x602C000E),"ast_header",sxau_ast_header_fields,SX_COUNT(sxau_ast_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_ast_block_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("bytes_per_channel","uint32",4,4,SX_SIZE),
 SX_FIELD("reserved","bytes",8,24,SX_RESERVED),
};
static const sx_layout sxau_ast_block={UINT32_C(0x602C000F),"ast_block",sxau_ast_block_fields,SX_COUNT(sxau_ast_block_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
};
static const sx_layout sxau_hca_header={UINT32_C(0x602C0010),"hca_header",sxau_hca_header_fields,SX_COUNT(sxau_hca_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_format_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("channels","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("sample_rate","uint24",5,3,SX_NONE),
 SX_FIELD("frame_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("encoder_delay_samples","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("encoder_padding_samples","uint16",14,2,SX_COUNT_PROP),
};
static const sx_layout sxau_hca_format={UINT32_C(0x602C0011),"hca_format",sxau_hca_format_fields,SX_COUNT(sxau_hca_format_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_compression_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("frame_size","uint16",4,2,SX_SIZE),
 SX_FIELD("minimum_resolution","uint8",6,1,SX_NONE),
 SX_FIELD("maximum_resolution","uint8",7,1,SX_NONE),
 SX_FIELD("track_count","uint8",8,1,SX_COUNT_PROP),
 SX_FIELD("channel_configuration","uint8",9,1,SX_ID),
 SX_FIELD("total_bands","uint8",10,1,SX_COUNT_PROP),
 SX_FIELD("base_bands","uint8",11,1,SX_COUNT_PROP),
 SX_FIELD("stereo_bands","uint8",12,1,SX_COUNT_PROP),
 SX_FIELD("bands_per_hfr_group","uint8",13,1,SX_COUNT_PROP),
 SX_FIELD("reserved","bytes",14,2,SX_RESERVED),
};
static const sx_layout sxau_hca_compression={UINT32_C(0x602C0012),"hca_compression",sxau_hca_compression_fields,SX_COUNT(sxau_hca_compression_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_ath_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("ath_type","uint16",4,2,SX_ID),
};
static const sx_layout sxau_hca_ath={UINT32_C(0x602C0013),"hca_ath",sxau_hca_ath_fields,SX_COUNT(sxau_hca_ath_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_loop_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("start_frame","uint32",4,4,SX_NONE),
 SX_FIELD("end_frame","uint32",8,4,SX_NONE),
 SX_FIELD("pre_loop_samples","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("post_loop_samples","uint16",14,2,SX_COUNT_PROP),
};
static const sx_layout sxau_hca_loop={UINT32_C(0x602C0014),"hca_loop",sxau_hca_loop_fields,SX_COUNT(sxau_hca_loop_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_cipher_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("cipher_type","uint16",4,2,SX_ID),
};
static const sx_layout sxau_hca_cipher={UINT32_C(0x602C0015),"hca_cipher",sxau_hca_cipher_fields,SX_COUNT(sxau_hca_cipher_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_relative_volume_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("volume","float",4,4,SX_NONE),
};
static const sx_layout sxau_hca_relative_volume={UINT32_C(0x602C0016),"hca_relative_volume",sxau_hca_relative_volume_fields,SX_COUNT(sxau_hca_relative_volume_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_comment_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("comment_length","uint8",4,1,SX_SIZE),
};
static const sx_layout sxau_hca_comment={UINT32_C(0x602C0017),"hca_comment",sxau_hca_comment_fields,SX_COUNT(sxau_hca_comment_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_pad_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
};
static const sx_layout sxau_hca_pad={UINT32_C(0x602C0018),"hca_pad",sxau_hca_pad_fields,SX_COUNT(sxau_hca_pad_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_checksum_fields[]={
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxau_hca_checksum={UINT32_C(0x602C0019),"hca_checksum",sxau_hca_checksum_fields,SX_COUNT(sxau_hca_checksum_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_frame_sync_fields[]={
 SX_FIELD("sync","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sxau_hca_frame_sync={UINT32_C(0x602C001A),"hca_frame_sync",sxau_hca_frame_sync_fields,SX_COUNT(sxau_hca_frame_sync_fields),SX_BE};
static const xx_data_struct_field_desc sxau_iff8svx_form_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("form_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","char[4]",8,4,SX_ID),
};
static const sx_layout sxau_iff8svx_form={UINT32_C(0x602C001B),"iff8svx_form",sxau_iff8svx_form_fields,SX_COUNT(sxau_iff8svx_form_fields),SX_BE};
static const xx_data_struct_field_desc sxau_iff8svx_chunk_fields[]={
 SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxau_iff8svx_chunk={UINT32_C(0x602C001C),"iff8svx_chunk",sxau_iff8svx_chunk_fields,SX_COUNT(sxau_iff8svx_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxau_iff8svx_voice_fields[]={
 SX_FIELD("one_shot_samples","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("repeat_samples","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("samples_per_cycle","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("samples_per_second","uint16",12,2,SX_NONE),
 SX_FIELD("octaves","uint8",14,1,SX_COUNT_PROP),
 SX_FIELD("compression","uint8",15,1,SX_ID),
 SX_FIELD("volume_fixed16_16","uint32",16,4,SX_NONE),
};
static const sx_layout sxau_iff8svx_voice={UINT32_C(0x602C001D),"iff8svx_voice",sxau_iff8svx_voice_fields,SX_COUNT(sxau_iff8svx_voice_fields),SX_BE};
static const xx_data_struct_field_desc sxau_iff8svx_channel_fields[]={
 SX_FIELD("channel_assignment","uint32",0,4,SX_ID),
};
static const sx_layout sxau_iff8svx_channel={UINT32_C(0x602C001E),"iff8svx_channel",sxau_iff8svx_channel_fields,SX_COUNT(sxau_iff8svx_channel_fields),SX_BE};
static const xx_data_struct_field_desc sxau_vgm_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("eof_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("sn76489_clock","uint32",12,4,SX_NONE),
 SX_FIELD("ym2413_clock","uint32",16,4,SX_NONE),
 SX_FIELD("gd3_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("total_samples","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("loop_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("loop_samples","uint32",32,4,SX_COUNT_PROP),
 SX_FIELD("rate","uint32",36,4,SX_NONE),
 SX_FIELD("sn76489_feedback","uint16",40,2,SX_FLAGS),
 SX_FIELD("sn76489_shift_width","uint8",42,1,SX_NONE),
 SX_FIELD("sn76489_flags","uint8",43,1,SX_FLAGS),
 SX_FIELD("ym2612_clock","uint32",44,4,SX_NONE),
 SX_FIELD("ym2151_clock","uint32",48,4,SX_NONE),
 SX_FIELD("data_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("sega_pcm_clock","uint32",56,4,SX_NONE),
 SX_FIELD("sega_pcm_interface","uint32",60,4,SX_FLAGS),
};
static const sx_layout sxau_vgm_header={UINT32_C(0x602C001F),"vgm_header",sxau_vgm_header_fields,SX_COUNT(sxau_vgm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_gd3_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("text_bytes","uint32",8,4,SX_SIZE),
};
static const sx_layout sxau_vgm_gd3={UINT32_C(0x602C0020),"vgm_gd3",sxau_vgm_gd3_fields,SX_COUNT(sxau_vgm_gd3_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_command_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
};
static const sx_layout sxau_vgm_command={UINT32_C(0x602C0021),"vgm_command",sxau_vgm_command_fields,SX_COUNT(sxau_vgm_command_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_register8_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("value","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxau_vgm_register8={UINT32_C(0x602C0022),"vgm_register8",sxau_vgm_register8_fields,SX_COUNT(sxau_vgm_register8_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_register16_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("register","uint8",1,1,SX_ID),
 SX_FIELD("value","uint8",2,1,SX_FLAGS),
};
static const sx_layout sxau_vgm_register16={UINT32_C(0x602C0023),"vgm_register16",sxau_vgm_register16_fields,SX_COUNT(sxau_vgm_register16_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_wait_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("wait_samples","uint16",1,2,SX_COUNT_PROP),
};
static const sx_layout sxau_vgm_wait={UINT32_C(0x602C0024),"vgm_wait",sxau_vgm_wait_fields,SX_COUNT(sxau_vgm_wait_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_data_block_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("compatibility","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("block_type","uint8",2,1,SX_ID),
 SX_FIELD("data_bytes","uint32",3,4,SX_SIZE),
};
static const sx_layout sxau_vgm_data_block={UINT32_C(0x602C0025),"vgm_data_block",sxau_vgm_data_block_fields,SX_COUNT(sxau_vgm_data_block_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_pcm_seek_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("pcm_bank_offset","uint32",1,4,SX_OFFSET),
};
static const sx_layout sxau_vgm_pcm_seek={UINT32_C(0x602C0026),"vgm_pcm_seek",sxau_vgm_pcm_seek_fields,SX_COUNT(sxau_vgm_pcm_seek_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_dac_setup_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("stream_id","uint8",1,1,SX_ID),
 SX_FIELD("chip_type","uint8",2,1,SX_ID),
 SX_FIELD("port","uint8",3,1,SX_ID),
 SX_FIELD("command","uint8",4,1,SX_ID),
};
static const sx_layout sxau_vgm_dac_setup={UINT32_C(0x602C0027),"vgm_dac_setup",sxau_vgm_dac_setup_fields,SX_COUNT(sxau_vgm_dac_setup_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_dac_data_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("stream_id","uint8",1,1,SX_ID),
 SX_FIELD("data_bank","uint8",2,1,SX_ID),
 SX_FIELD("step_size","uint8",3,1,SX_SIZE),
 SX_FIELD("step_base","uint8",4,1,SX_OFFSET),
};
static const sx_layout sxau_vgm_dac_data={UINT32_C(0x602C0028),"vgm_dac_data",sxau_vgm_dac_data_fields,SX_COUNT(sxau_vgm_dac_data_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_dac_frequency_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("stream_id","uint8",1,1,SX_ID),
 SX_FIELD("frequency","uint32",2,4,SX_NONE),
};
static const sx_layout sxau_vgm_dac_frequency={UINT32_C(0x602C0029),"vgm_dac_frequency",sxau_vgm_dac_frequency_fields,SX_COUNT(sxau_vgm_dac_frequency_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_dac_start_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("stream_id","uint8",1,1,SX_ID),
 SX_FIELD("data_start_offset","uint32",2,4,SX_OFFSET),
 SX_FIELD("length_mode","uint8",6,1,SX_FLAGS),
 SX_FIELD("data_length","uint32",7,4,SX_NONE),
};
static const sx_layout sxau_vgm_dac_start={UINT32_C(0x602C002A),"vgm_dac_start",sxau_vgm_dac_start_fields,SX_COUNT(sxau_vgm_dac_start_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_dac_stop_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("stream_id","uint8",1,1,SX_ID),
};
static const sx_layout sxau_vgm_dac_stop={UINT32_C(0x602C002B),"vgm_dac_stop",sxau_vgm_dac_stop_fields,SX_COUNT(sxau_vgm_dac_stop_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vgm_dac_fast_start_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("stream_id","uint8",1,1,SX_ID),
 SX_FIELD("block_id","uint16",2,2,SX_ID),
 SX_FIELD("flags","uint8",4,1,SX_FLAGS),
};
static const sx_layout sxau_vgm_dac_fast_start={UINT32_C(0x602C002C),"vgm_dac_fast_start",sxau_vgm_dac_fast_start_fields,SX_COUNT(sxau_vgm_dac_fast_start_fields),SX_LE};
static const xx_data_struct_field_desc sxau_ac3_sync_info_fields[]={
 SX_FIELD("sync_word","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("crc1","uint16",2,2,SX_CHECKSUM),
 SX_FIELD("sample_rate_and_frame_size_code","uint8",4,1,SX_FLAGS),
 SX_FIELD("bitstream_id_and_mode","uint8",5,1,SX_FLAGS),
};
static const sx_layout sxau_ac3_sync_info={UINT32_C(0x602C002D),"ac3_sync_info",sxau_ac3_sync_info_fields,SX_COUNT(sxau_ac3_sync_info_fields),SX_BE};
static const xx_data_struct_field_desc sxau_ac3_checksum2_fields[]={
 SX_FIELD("crc2","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxau_ac3_checksum2={UINT32_C(0x602C002E),"ac3_checksum2",sxau_ac3_checksum2_fields,SX_COUNT(sxau_ac3_checksum2_fields),SX_BE};
static const xx_data_struct_field_desc sxau_mp3_frame_header_fields[]={
 SX_FIELD("sync_version_layer_protection","uint16",0,2,SX_FLAGS),
 SX_FIELD("bitrate_rate_padding_private","uint8",2,1,SX_FLAGS),
 SX_FIELD("channel_mode_extension_flags","uint8",3,1,SX_FLAGS),
};
static const sx_layout sxau_mp3_frame_header={UINT32_C(0x602C002F),"mp3_frame_header",sxau_mp3_frame_header_fields,SX_COUNT(sxau_mp3_frame_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_id3_header_fields[]={
 SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("major_version","uint8",3,1,SX_ID),
 SX_FIELD("revision","uint8",4,1,SX_ID),
 SX_FIELD("flags","uint8",5,1,SX_FLAGS),
 SX_FIELD("synchsafe_size","bytes",6,4,SX_NONE),
};
static const sx_layout sxau_id3_header={UINT32_C(0x602C0030),"id3_header",sxau_id3_header_fields,SX_COUNT(sxau_id3_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_id3v23_frame_fields[]={
 SX_FIELD("frame_id","char[4]",0,4,SX_ID),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("flags","uint16",8,2,SX_FLAGS),
};
static const sx_layout sxau_id3v23_frame={UINT32_C(0x602C0031),"id3v23_frame",sxau_id3v23_frame_fields,SX_COUNT(sxau_id3v23_frame_fields),SX_BE};
static const xx_data_struct_field_desc sxau_id3v24_frame_fields[]={
 SX_FIELD("frame_id","char[4]",0,4,SX_ID),
 SX_FIELD("synchsafe_size","bytes",4,4,SX_NONE),
 SX_FIELD("flags","uint16",8,2,SX_FLAGS),
};
static const sx_layout sxau_id3v24_frame={UINT32_C(0x602C0032),"id3v24_frame",sxau_id3v24_frame_fields,SX_COUNT(sxau_id3v24_frame_fields),SX_BE};
static const xx_data_struct_field_desc sxau_adts_header_fields[]={
 SX_FIELD("sync_id_layer_protection","uint16",0,2,SX_FLAGS),
 SX_FIELD("profile_sampling_private_channel_high","uint8",2,1,SX_FLAGS),
 SX_FIELD("channel_low_original_home_copyright_length_high","uint8",3,1,SX_FLAGS),
 SX_FIELD("frame_length_middle","uint8",4,1,SX_FLAGS),
 SX_FIELD("length_low_buffer_fullness_high","uint8",5,1,SX_FLAGS),
 SX_FIELD("fullness_low_raw_block_count","uint8",6,1,SX_FLAGS),
};
static const sx_layout sxau_adts_header={UINT32_C(0x602C0033),"adts_header",sxau_adts_header_fields,SX_COUNT(sxau_adts_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_adts_crc_fields[]={
 SX_FIELD("crc","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxau_adts_crc={UINT32_C(0x602C0034),"adts_crc",sxau_adts_crc_fields,SX_COUNT(sxau_adts_crc_fields),SX_BE};
static const xx_data_struct_field_desc sxau_ape_descriptor_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
 SX_FIELD("descriptor_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("header_bytes","uint32",12,4,SX_SIZE),
 SX_FIELD("seek_table_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("wav_header_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("audio_data_bytes_low","uint32",24,4,SX_NONE),
 SX_FIELD("audio_data_bytes_high","uint32",28,4,SX_NONE),
 SX_FIELD("wav_tail_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("md5","bytes",36,16,SX_CHECKSUM),
};
static const sx_layout sxau_ape_descriptor={UINT32_C(0x602C0035),"ape_descriptor",sxau_ape_descriptor_fields,SX_COUNT(sxau_ape_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxau_ape_header_fields[]={
 SX_FIELD("compression_level","uint16",0,2,SX_ID),
 SX_FIELD("format_flags","uint16",2,2,SX_FLAGS),
 SX_FIELD("blocks_per_frame","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("final_frame_blocks","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("total_frames","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("bits_per_sample","uint16",16,2,SX_NONE),
 SX_FIELD("channels","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("sample_rate","uint32",20,4,SX_NONE),
};
static const sx_layout sxau_ape_header={UINT32_C(0x602C0036),"ape_header",sxau_ape_header_fields,SX_COUNT(sxau_ape_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_ape_seek_fields[]={
 SX_FIELD("frame_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxau_ape_seek={UINT32_C(0x602C0037),"ape_seek",sxau_ape_seek_fields,SX_COUNT(sxau_ape_seek_fields),SX_LE};
static const xx_data_struct_field_desc sxau_ape_tag_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("version","uint32",8,4,SX_ID),
 SX_FIELD("tag_bytes","uint32",12,4,SX_SIZE),
 SX_FIELD("item_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("flags","uint32",20,4,SX_FLAGS),
 SX_FIELD("reserved","bytes",24,8,SX_RESERVED),
};
static const sx_layout sxau_ape_tag={UINT32_C(0x602C0038),"ape_tag",sxau_ape_tag_fields,SX_COUNT(sxau_ape_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxau_ape_tag_item_fields[]={
 SX_FIELD("value_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
};
static const sx_layout sxau_ape_tag_item={UINT32_C(0x602C0039),"ape_tag_item",sxau_ape_tag_item_fields,SX_COUNT(sxau_ape_tag_item_fields),SX_LE};
static const xx_data_struct_field_desc sxau_sdif_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("format_version","uint32",8,4,SX_ID),
 SX_FIELD("types_version","uint32",12,4,SX_ID),
};
static const sx_layout sxau_sdif_header={UINT32_C(0x602C003A),"sdif_header",sxau_sdif_header_fields,SX_COUNT(sxau_sdif_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_sdif_frame_fields[]={
 SX_FIELD("frame_type","char[4]",0,4,SX_ID),
 SX_FIELD("frame_data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("time_seconds","double",8,8,SX_NONE),
 SX_FIELD("stream_id","uint32",16,4,SX_ID),
 SX_FIELD("matrix_count","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxau_sdif_frame={UINT32_C(0x602C003B),"sdif_frame",sxau_sdif_frame_fields,SX_COUNT(sxau_sdif_frame_fields),SX_BE};
static const xx_data_struct_field_desc sxau_sdif_matrix_fields[]={
 SX_FIELD("matrix_type","char[4]",0,4,SX_ID),
 SX_FIELD("data_type","uint32",4,4,SX_ID),
 SX_FIELD("rows","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("columns","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxau_sdif_matrix={UINT32_C(0x602C003C),"sdif_matrix",sxau_sdif_matrix_fields,SX_COUNT(sxau_sdif_matrix_fields),SX_BE};
static const xx_data_struct_field_desc sxau_sap_binary_marker_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sxau_sap_binary_marker={UINT32_C(0x602C003D),"sap_binary_marker",sxau_sap_binary_marker_fields,SX_COUNT(sxau_sap_binary_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxau_sap_load_segment_fields[]={
 SX_FIELD("start_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("end_address_inclusive","uint16",2,2,SX_ADDRESS),
};
static const sx_layout sxau_sap_load_segment={UINT32_C(0x602C003E),"sap_load_segment",sxau_sap_load_segment_fields,SX_COUNT(sxau_sap_load_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxau_sc68_header_fields[]={
 SX_FIELD("signature","char[56]",0,56,SX_SIGNATURE),
 SX_FIELD("magic","char[4]",56,4,SX_SIGNATURE),
 SX_FIELD("file_size_from_magic","uint32",60,4,SX_SIZE),
};
static const sx_layout sxau_sc68_header={UINT32_C(0x602C003F),"sc68_header",sxau_sc68_header_fields,SX_COUNT(sxau_sc68_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_sc68_chunk_fields[]={
 SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxau_sc68_chunk={UINT32_C(0x602C0040),"sc68_chunk",sxau_sc68_chunk_fields,SX_COUNT(sxau_sc68_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxau_sc68_default_fields[]={
 SX_FIELD("default_track","uint32",0,4,SX_ID),
};
static const sx_layout sxau_sc68_default={UINT32_C(0x602C0041),"sc68_default",sxau_sc68_default_fields,SX_COUNT(sxau_sc68_default_fields),SX_LE};
static const xx_data_struct_field_desc sxau_sc68_load_address_fields[]={
 SX_FIELD("load_address","uint32",0,4,SX_ADDRESS),
};
static const sx_layout sxau_sc68_load_address={UINT32_C(0x602C0042),"sc68_load_address",sxau_sc68_load_address_fields,SX_COUNT(sxau_sc68_load_address_fields),SX_LE};
static const xx_data_struct_field_desc sxau_sc68_integer_fields[]={
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
static const sx_layout sxau_sc68_integer={UINT32_C(0x602C0043),"sc68_integer",sxau_sc68_integer_fields,SX_COUNT(sxau_sc68_integer_fields),SX_LE};
static const xx_data_struct_field_desc sxau_amiga_ahx_header_fields[]={
 SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("names_offset_low16","uint16",4,2,SX_OFFSET),
 SX_FIELD("flags_and_position_count","uint16",6,2,SX_FLAGS),
 SX_FIELD("restart_position","uint16",8,2,SX_ID),
 SX_FIELD("rows_per_track","uint8",10,1,SX_COUNT_PROP),
 SX_FIELD("maximum_track","uint8",11,1,SX_ID),
 SX_FIELD("instrument_count","uint8",12,1,SX_COUNT_PROP),
 SX_FIELD("subsong_count","uint8",13,1,SX_COUNT_PROP),
};
static const sx_layout sxau_amiga_ahx_header={UINT32_C(0x602C0044),"amiga_ahx_header",sxau_amiga_ahx_header_fields,SX_COUNT(sxau_amiga_ahx_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_amiga_ahx_subsong_fields[]={
 SX_FIELD("start_position","uint16",0,2,SX_ID),
};
static const sx_layout sxau_amiga_ahx_subsong={UINT32_C(0x602C0045),"amiga_ahx_subsong",sxau_amiga_ahx_subsong_fields,SX_COUNT(sxau_amiga_ahx_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxau_amiga_ahx_channel_order_fields[]={
 SX_FIELD("track_index","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
static const sx_layout sxau_amiga_ahx_channel_order={UINT32_C(0x602C0046),"amiga_ahx_channel_order",sxau_amiga_ahx_channel_order_fields,SX_COUNT(sxau_amiga_ahx_channel_order_fields),SX_BE};
static const xx_data_struct_field_desc sxau_amiga_ahx_instrument_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
 SX_FIELD("filter_speed_and_wave_length","uint8",1,1,SX_FLAGS),
 SX_FIELD("attack_frames","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("attack_volume","uint8",3,1,SX_NONE),
 SX_FIELD("decay_frames","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("decay_volume","uint8",5,1,SX_NONE),
 SX_FIELD("sustain_frames","uint8",6,1,SX_COUNT_PROP),
 SX_FIELD("release_frames","uint8",7,1,SX_COUNT_PROP),
 SX_FIELD("release_volume","uint8",8,1,SX_NONE),
 SX_FIELD("unknown_a","bytes",9,12,SX_NONE),
 SX_FIELD("playlist_length","uint8",21,1,SX_COUNT_PROP),
};
static const sx_layout sxau_amiga_ahx_instrument={UINT32_C(0x602C0047),"amiga_ahx_instrument",sxau_amiga_ahx_instrument_fields,SX_COUNT(sxau_amiga_ahx_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxau_amiga_ahx_playlist_fields[]={
 SX_FIELD("effects_and_waveform","uint8",0,1,SX_FLAGS),
 SX_FIELD("note_and_fixed","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect_parameter1","uint8",2,1,SX_NONE),
 SX_FIELD("effect_parameter2","uint8",3,1,SX_NONE),
};
static const sx_layout sxau_amiga_ahx_playlist={UINT32_C(0x602C0048),"amiga_ahx_playlist",sxau_amiga_ahx_playlist_fields,SX_COUNT(sxau_amiga_ahx_playlist_fields),SX_BE};
static const xx_data_struct_field_desc sxau_vab_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("bank_id","uint32",8,4,SX_ID),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
 SX_FIELD("reserved","uint16",16,2,SX_RESERVED),
 SX_FIELD("program_count","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("tone_count","uint16",20,2,SX_COUNT_PROP),
 SX_FIELD("sample_count","uint16",22,2,SX_COUNT_PROP),
 SX_FIELD("master_volume","uint8",24,1,SX_NONE),
 SX_FIELD("master_pan","uint8",25,1,SX_NONE),
 SX_FIELD("bank_attributes1","uint8",26,1,SX_FLAGS),
 SX_FIELD("bank_attributes2","uint8",27,1,SX_FLAGS),
 SX_FIELD("reserved2","uint32",28,4,SX_RESERVED),
};
static const sx_layout sxau_vab_header={UINT32_C(0x602C0049),"vab_header",sxau_vab_header_fields,SX_COUNT(sxau_vab_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vab_program_fields[]={
 SX_FIELD("tone_count","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("master_volume","uint8",1,1,SX_NONE),
 SX_FIELD("priority","uint8",2,1,SX_NONE),
 SX_FIELD("mode","uint8",3,1,SX_FLAGS),
 SX_FIELD("pan","uint8",4,1,SX_NONE),
 SX_FIELD("reserved","bytes",5,11,SX_RESERVED),
};
static const sx_layout sxau_vab_program={UINT32_C(0x602C004A),"vab_program",sxau_vab_program_fields,SX_COUNT(sxau_vab_program_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vab_tone_fields[]={
 SX_FIELD("priority","uint8",0,1,SX_NONE),
 SX_FIELD("mode","uint8",1,1,SX_FLAGS),
 SX_FIELD("volume","uint8",2,1,SX_NONE),
 SX_FIELD("pan","uint8",3,1,SX_NONE),
 SX_FIELD("center_note","uint8",4,1,SX_NONE),
 SX_FIELD("pitch_shift","uint8",5,1,SX_NONE),
 SX_FIELD("minimum_note","uint8",6,1,SX_NONE),
 SX_FIELD("maximum_note","uint8",7,1,SX_NONE),
 SX_FIELD("vibrato_width","uint8",8,1,SX_NONE),
 SX_FIELD("vibrato_time","uint8",9,1,SX_NONE),
 SX_FIELD("portamento_width","uint8",10,1,SX_NONE),
 SX_FIELD("portamento_time","uint8",11,1,SX_NONE),
 SX_FIELD("pitch_bend_min","uint8",12,1,SX_NONE),
 SX_FIELD("pitch_bend_max","uint8",13,1,SX_NONE),
 SX_FIELD("reserved","bytes",14,2,SX_RESERVED),
 SX_FIELD("adsr1","uint16",16,2,SX_FLAGS),
 SX_FIELD("adsr2","uint16",18,2,SX_FLAGS),
 SX_FIELD("program_index","uint16",20,2,SX_ID),
 SX_FIELD("sample_index","uint16",22,2,SX_ID),
 SX_FIELD("reserved2","bytes",24,8,SX_RESERVED),
};
static const sx_layout sxau_vab_tone={UINT32_C(0x602C004B),"vab_tone",sxau_vab_tone_fields,SX_COUNT(sxau_vab_tone_fields),SX_LE};
static const xx_data_struct_field_desc sxau_vab_sample_size_fields[]={
 SX_FIELD("size_in_8byte_units","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxau_vab_sample_size={UINT32_C(0x602C004C),"vab_sample_size",sxau_vab_sample_size_fields,SX_COUNT(sxau_vab_sample_size_fields),SX_LE};
static const xx_data_struct_field_desc sxau_ay_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("file_version","uint8",8,1,SX_ID),
 SX_FIELD("player_version","uint8",9,1,SX_ID),
 SX_FIELD("custom_player_relative","int16",10,2,SX_OFFSET),
 SX_FIELD("author_relative","int16",12,2,SX_OFFSET),
 SX_FIELD("comment_relative","int16",14,2,SX_OFFSET),
 SX_FIELD("track_count_minus_one","uint8",16,1,SX_NONE),
 SX_FIELD("first_track","uint8",17,1,SX_ID),
 SX_FIELD("track_table_relative","int16",18,2,SX_OFFSET),
};
static const sx_layout sxau_ay_header={UINT32_C(0x602C004D),"ay_header",sxau_ay_header_fields,SX_COUNT(sxau_ay_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_ay_track_index_fields[]={
 SX_FIELD("name_relative","int16",0,2,SX_OFFSET),
 SX_FIELD("descriptor_relative","int16",2,2,SX_OFFSET),
};
static const sx_layout sxau_ay_track_index={UINT32_C(0x602C004E),"ay_track_index",sxau_ay_track_index_fields,SX_COUNT(sxau_ay_track_index_fields),SX_BE};
static const xx_data_struct_field_desc sxau_ay_track_fields[]={
 SX_FIELD("channel_a","uint8",0,1,SX_ID),
 SX_FIELD("channel_b","uint8",1,1,SX_ID),
 SX_FIELD("channel_c","uint8",2,1,SX_ID),
 SX_FIELD("noise_channel","uint8",3,1,SX_ID),
 SX_FIELD("duration_frames","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("fade_frames","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("register_hi","uint8",8,1,SX_NONE),
 SX_FIELD("register_lo","uint8",9,1,SX_NONE),
 SX_FIELD("cpu_state_relative","int16",10,2,SX_OFFSET),
 SX_FIELD("block_index_relative","int16",12,2,SX_OFFSET),
};
static const sx_layout sxau_ay_track={UINT32_C(0x602C004F),"ay_track",sxau_ay_track_fields,SX_COUNT(sxau_ay_track_fields),SX_BE};
static const xx_data_struct_field_desc sxau_ay_cpu_state_fields[]={
 SX_FIELD("stack_pointer","uint16",0,2,SX_ADDRESS),
 SX_FIELD("init_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("interrupt_address","uint16",4,2,SX_ADDRESS),
};
static const sx_layout sxau_ay_cpu_state={UINT32_C(0x602C0050),"ay_cpu_state",sxau_ay_cpu_state_fields,SX_COUNT(sxau_ay_cpu_state_fields),SX_BE};
static const xx_data_struct_field_desc sxau_ay_block_fields[]={
 SX_FIELD("load_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("payload_bytes","uint16",2,2,SX_SIZE),
 SX_FIELD("payload_relative","int16",4,2,SX_OFFSET),
};
static const sx_layout sxau_ay_block={UINT32_C(0x602C0051),"ay_block",sxau_ay_block_fields,SX_COUNT(sxau_ay_block_fields),SX_BE};
static const xx_data_struct_field_desc sxau_ay_blocks_end_fields[]={
 SX_FIELD("zero_address","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sxau_ay_blocks_end={UINT32_C(0x602C0052),"ay_blocks_end",sxau_ay_blocks_end_fields,SX_COUNT(sxau_ay_blocks_end_fields),SX_BE};
static const xx_data_struct_field_desc sxau_fsb1_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("sample_count","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("sample_data_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxau_fsb1_header={UINT32_C(0x602C0053),"fsb1_header",sxau_fsb1_header_fields,SX_COUNT(sxau_fsb1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb1_sample_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_STRING),
 SX_FIELD("sample_count","int32",32,4,SX_COUNT_PROP),
 SX_FIELD("stored_bytes","uint32",36,4,SX_SIZE),
 SX_FIELD("sample_rate","int32",40,4,SX_NONE),
 SX_FIELD("opaque_2c","bytes",44,8,SX_NONE),
 SX_FIELD("mode","uint32",52,4,SX_FLAGS),
 SX_FIELD("loop_start_sample","int32",56,4,SX_NONE),
 SX_FIELD("loop_end_sample","int32",60,4,SX_NONE),
};
static const sx_layout sxau_fsb1_sample={UINT32_C(0x602C0054),"fsb1_sample",sxau_fsb1_sample_fields,SX_COUNT(sxau_fsb1_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb2_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("sample_count","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("sample_header_bytes","uint32",8,4,SX_SIZE),
 SX_FIELD("sample_data_bytes","uint32",12,4,SX_SIZE),
};
static const sx_layout sxau_fsb2_header={UINT32_C(0x602C0055),"fsb2_header",sxau_fsb2_header_fields,SX_COUNT(sxau_fsb2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb34_version_fields[]={
 SX_FIELD("version","uint32",0,4,SX_ID),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
};
static const sx_layout sxau_fsb34_version={UINT32_C(0x602C0056),"fsb34_version",sxau_fsb34_version_fields,SX_COUNT(sxau_fsb34_version_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb4_hash_fields[]={
 SX_FIELD("hash","bytes",0,8,SX_CHECKSUM),
 SX_FIELD("guid","bytes",8,16,SX_ID),
};
static const sx_layout sxau_fsb4_hash={UINT32_C(0x602C0057),"fsb4_hash",sxau_fsb4_hash_fields,SX_COUNT(sxau_fsb4_hash_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb_sample_fields[]={
 SX_FIELD("header_size","uint16",0,2,SX_SIZE),
 SX_FIELD("name","char[30]",2,30,SX_STRING),
 SX_FIELD("sample_count","int32",32,4,SX_COUNT_PROP),
 SX_FIELD("stored_bytes","uint32",36,4,SX_SIZE),
 SX_FIELD("loop_start_sample","int32",40,4,SX_NONE),
 SX_FIELD("loop_end_sample","int32",44,4,SX_NONE),
 SX_FIELD("mode","uint32",48,4,SX_FLAGS),
 SX_FIELD("sample_rate","int32",52,4,SX_NONE),
 SX_FIELD("default_volume","uint16",56,2,SX_NONE),
 SX_FIELD("default_pan","int16",58,2,SX_NONE),
 SX_FIELD("default_priority","uint16",60,2,SX_NONE),
 SX_FIELD("channels","uint16",62,2,SX_COUNT_PROP),
};
static const sx_layout sxau_fsb_sample={UINT32_C(0x602C0058),"fsb_sample",sxau_fsb_sample_fields,SX_COUNT(sxau_fsb_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb_sample_basic_fields[]={
 SX_FIELD("sample_count","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("stored_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxau_fsb_sample_basic={UINT32_C(0x602C0059),"fsb_sample_basic",sxau_fsb_sample_basic_fields,SX_COUNT(sxau_fsb_sample_basic_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb5_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("sample_count","int32",8,4,SX_COUNT_PROP),
 SX_FIELD("sample_header_bytes","uint32",12,4,SX_SIZE),
 SX_FIELD("name_table_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("sample_data_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("codec","uint32",24,4,SX_ID),
};
static const sx_layout sxau_fsb5_header={UINT32_C(0x602C005A),"fsb5_header",sxau_fsb5_header_fields,SX_COUNT(sxau_fsb5_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb5_sample_fields[]={
 SX_FIELD("packed_sample_metadata","uint64",0,8,SX_FLAGS),
};
static const sx_layout sxau_fsb5_sample={UINT32_C(0x602C005B),"fsb5_sample",sxau_fsb5_sample_fields,SX_COUNT(sxau_fsb5_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb5_chunk_fields[]={
 SX_FIELD("more_size_type","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxau_fsb5_chunk={UINT32_C(0x602C005C),"fsb5_chunk",sxau_fsb5_chunk_fields,SX_COUNT(sxau_fsb5_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb5_channels_fields[]={
 SX_FIELD("channels","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxau_fsb5_channels={UINT32_C(0x602C005D),"fsb5_channels",sxau_fsb5_channels_fields,SX_COUNT(sxau_fsb5_channels_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb5_frequency_fields[]={
 SX_FIELD("sample_rate","uint32",0,4,SX_NONE),
};
static const sx_layout sxau_fsb5_frequency={UINT32_C(0x602C005E),"fsb5_frequency",sxau_fsb5_frequency_fields,SX_COUNT(sxau_fsb5_frequency_fields),SX_LE};
static const xx_data_struct_field_desc sxau_fsb5_name_offset_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxau_fsb5_name_offset={UINT32_C(0x602C005F),"fsb5_name_offset",sxau_fsb5_name_offset_fields,SX_COUNT(sxau_fsb5_name_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxau_acm_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("sample_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("channels","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("sample_rate","uint16",10,2,SX_NONE),
 SX_FIELD("levels_and_subblocks","uint16",12,2,SX_FLAGS),
};
static const sx_layout sxau_acm_header={UINT32_C(0x602C0060),"acm_header",sxau_acm_header_fields,SX_COUNT(sxau_acm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_cri_ahx_header_fields[]={
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("data_offset_minus_four","uint16",2,2,SX_OFFSET),
 SX_FIELD("encoding","uint8",4,1,SX_ID),
 SX_FIELD("block_size","uint8",5,1,SX_SIZE),
 SX_FIELD("sample_bit_depth","uint8",6,1,SX_NONE),
 SX_FIELD("channels","uint8",7,1,SX_COUNT_PROP),
 SX_FIELD("sample_rate","uint32",8,4,SX_NONE),
 SX_FIELD("sample_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("highpass_frequency","uint16",16,2,SX_NONE),
 SX_FIELD("version","uint8",18,1,SX_ID),
 SX_FIELD("encryption_type","uint8",19,1,SX_ID),
 SX_FIELD("unknown","bytes",20,4,SX_NONE),
};
static const sx_layout sxau_cri_ahx_header={UINT32_C(0x602C0061),"cri_ahx_header",sxau_cri_ahx_header_fields,SX_COUNT(sxau_cri_ahx_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_cri_ahx_copyright_fields[]={
 SX_FIELD("copyright","char[6]",0,6,SX_SIGNATURE),
};
static const sx_layout sxau_cri_ahx_copyright={UINT32_C(0x602C0062),"cri_ahx_copyright",sxau_cri_ahx_copyright_fields,SX_COUNT(sxau_cri_ahx_copyright_fields),SX_BE};
static const xx_data_struct_field_desc sxau_cri_ahx_footer_fields[]={
 SX_FIELD("marker","char[10]",0,10,SX_SIGNATURE),
};
static const sx_layout sxau_cri_ahx_footer={UINT32_C(0x602C0063),"cri_ahx_footer",sxau_cri_ahx_footer_fields,SX_COUNT(sxau_cri_ahx_footer_fields),SX_BE};
static const xx_data_struct_field_desc sxau_dss_header_fields[]={
 SX_FIELD("header_512byte_blocks","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("signature","char[3]",1,3,SX_SIGNATURE),
 SX_FIELD("opaque_metadata","bytes",4,34,SX_NONE),
 SX_FIELD("recording_start","char[12]",38,12,SX_STRING),
 SX_FIELD("recording_end","char[12]",50,12,SX_STRING),
 SX_FIELD("duration_hhmmss","char[6]",62,6,SX_STRING),
};
static const sx_layout sxau_dss_header={UINT32_C(0x602C0064),"dss_header",sxau_dss_header_fields,SX_COUNT(sxau_dss_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_ea_block_le_fields[]={
 SX_FIELD("block_id","char[4]",0,4,SX_ID),
 SX_FIELD("block_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxau_ea_block_le={UINT32_C(0x602C0065),"ea_block_le",sxau_ea_block_le_fields,SX_COUNT(sxau_ea_block_le_fields),SX_LE};
static const xx_data_struct_field_desc sxau_nitro_header_le_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("version","uint16",6,2,SX_ID),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("header_size","uint16",12,2,SX_SIZE),
 SX_FIELD("block_count","uint16",14,2,SX_COUNT_PROP),
};
static const sx_layout sxau_nitro_header_le={UINT32_C(0x602C0066),"nitro_header_le",sxau_nitro_header_le_fields,SX_COUNT(sxau_nitro_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxau_nitro_chunk_le_fields[]={
 SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
 SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxau_nitro_chunk_le={UINT32_C(0x602C0067),"nitro_chunk_le",sxau_nitro_chunk_le_fields,SX_COUNT(sxau_nitro_chunk_le_fields),SX_LE};
static const xx_data_struct_field_desc sxau_nitro_stream_le_fields[]={
 SX_FIELD("encoding","uint8",0,1,SX_ID),
 SX_FIELD("loop_flag","uint8",1,1,SX_FLAGS),
 SX_FIELD("channels","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
 SX_FIELD("sample_rate","uint16",4,2,SX_NONE),
 SX_FIELD("timer","uint16",6,2,SX_NONE),
 SX_FIELD("loop_start_sample","uint32",8,4,SX_NONE),
 SX_FIELD("total_samples","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("data_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("block_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("block_bytes","uint32",24,4,SX_SIZE),
 SX_FIELD("samples_per_block","uint32",28,4,SX_COUNT_PROP),
 SX_FIELD("last_block_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("last_block_samples","uint32",36,4,SX_COUNT_PROP),
};
static const sx_layout sxau_nitro_stream_le={UINT32_C(0x602C0068),"nitro_stream_le",sxau_nitro_stream_le_fields,SX_COUNT(sxau_nitro_stream_le_fields),SX_LE};
static const xx_data_struct_field_desc sxau_paf_header_le_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("sample_byte_order","int32",8,4,SX_ID),
 SX_FIELD("sample_rate","int32",12,4,SX_NONE),
 SX_FIELD("encoding","int32",16,4,SX_ID),
 SX_FIELD("channels","int32",20,4,SX_COUNT_PROP),
 SX_FIELD("source","int32",24,4,SX_ID),
};
static const sx_layout sxau_paf_header_le={UINT32_C(0x602C0069),"paf_header_le",sxau_paf_header_le_fields,SX_COUNT(sxau_paf_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxau_ea_block_be_fields[]={
 SX_FIELD("block_id","char[4]",0,4,SX_ID),
 SX_FIELD("block_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxau_ea_block_be={UINT32_C(0x602C006A),"ea_block_be",sxau_ea_block_be_fields,SX_COUNT(sxau_ea_block_be_fields),SX_BE};
static const xx_data_struct_field_desc sxau_nitro_header_be_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("byte_order","uint16",4,2,SX_ID),
 SX_FIELD("version","uint16",6,2,SX_ID),
 SX_FIELD("file_size","uint32",8,4,SX_SIZE),
 SX_FIELD("header_size","uint16",12,2,SX_SIZE),
 SX_FIELD("block_count","uint16",14,2,SX_COUNT_PROP),
};
static const sx_layout sxau_nitro_header_be={UINT32_C(0x602C006B),"nitro_header_be",sxau_nitro_header_be_fields,SX_COUNT(sxau_nitro_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxau_nitro_chunk_be_fields[]={
 SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
 SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxau_nitro_chunk_be={UINT32_C(0x602C006C),"nitro_chunk_be",sxau_nitro_chunk_be_fields,SX_COUNT(sxau_nitro_chunk_be_fields),SX_BE};
static const xx_data_struct_field_desc sxau_nitro_stream_be_fields[]={
 SX_FIELD("encoding","uint8",0,1,SX_ID),
 SX_FIELD("loop_flag","uint8",1,1,SX_FLAGS),
 SX_FIELD("channels","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
 SX_FIELD("sample_rate","uint16",4,2,SX_NONE),
 SX_FIELD("timer","uint16",6,2,SX_NONE),
 SX_FIELD("loop_start_sample","uint32",8,4,SX_NONE),
 SX_FIELD("total_samples","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("data_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("block_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("block_bytes","uint32",24,4,SX_SIZE),
 SX_FIELD("samples_per_block","uint32",28,4,SX_COUNT_PROP),
 SX_FIELD("last_block_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("last_block_samples","uint32",36,4,SX_COUNT_PROP),
};
static const sx_layout sxau_nitro_stream_be={UINT32_C(0x602C006D),"nitro_stream_be",sxau_nitro_stream_be_fields,SX_COUNT(sxau_nitro_stream_be_fields),SX_BE};
static const xx_data_struct_field_desc sxau_paf_header_be_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
 SX_FIELD("sample_byte_order","int32",8,4,SX_ID),
 SX_FIELD("sample_rate","int32",12,4,SX_NONE),
 SX_FIELD("encoding","int32",16,4,SX_ID),
 SX_FIELD("channels","int32",20,4,SX_COUNT_PROP),
 SX_FIELD("source","int32",24,4,SX_ID),
};
static const sx_layout sxau_paf_header_be={UINT32_C(0x602C006E),"paf_header_be",sxau_paf_header_be_fields,SX_COUNT(sxau_paf_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxau_abylight_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("sample_rate","uint32",8,4,SX_NONE),
 SX_FIELD("unknown_c","bytes",12,4,SX_NONE),
 SX_FIELD("stream_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("unknown_14","bytes",20,4,SX_NONE),
 SX_FIELD("stream_bytes_copy","uint32",24,4,SX_SIZE),
 SX_FIELD("unknown_1c","bytes",28,2,SX_NONE),
};
static const sx_layout sxau_abylight_header={UINT32_C(0x602C006F),"abylight_header",sxau_abylight_header_fields,SX_COUNT(sxau_abylight_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_alp_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_bytes_after_prefix","uint32",4,4,SX_SIZE),
 SX_FIELD("encoding","char[6]",8,6,SX_ID),
 SX_FIELD("unknown","uint8",14,1,SX_NONE),
 SX_FIELD("channels","uint8",15,1,SX_COUNT_PROP),
};
static const sx_layout sxau_alp_header={UINT32_C(0x602C0070),"alp_header",sxau_alp_header_fields,SX_COUNT(sxau_alp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_alp_sample_rate_fields[]={
 SX_FIELD("sample_rate","uint32",0,4,SX_NONE),
};
static const sx_layout sxau_alp_sample_rate={UINT32_C(0x602C0071),"alp_sample_rate",sxau_alp_sample_rate_fields,SX_COUNT(sxau_alp_sample_rate_fields),SX_LE};
static const xx_data_struct_field_desc sxau_pmm_header_fields[]={
 SX_FIELD("magic","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("instrument_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("sample_offset0","uint32",20,4,SX_OFFSET),
 SX_FIELD("sample_offset1","uint32",24,4,SX_OFFSET),
 SX_FIELD("sample_offset2","uint32",28,4,SX_OFFSET),
 SX_FIELD("sample_offset3","uint32",32,4,SX_OFFSET),
 SX_FIELD("sample_offset4","uint32",36,4,SX_OFFSET),
 SX_FIELD("sample_offset5","uint32",40,4,SX_OFFSET),
 SX_FIELD("sample_offset6","uint32",44,4,SX_OFFSET),
 SX_FIELD("sample_offset7","uint32",48,4,SX_OFFSET),
 SX_FIELD("reserved","uint32",52,4,SX_RESERVED),
 SX_FIELD("metadata_magic","char[4]",56,4,SX_SIGNATURE),
 SX_FIELD("unknown_3c","bytes",60,2,SX_NONE),
 SX_FIELD("track_relative_offset","uint16",62,2,SX_OFFSET),
 SX_FIELD("sample_count","uint8",64,1,SX_COUNT_PROP),
};
static const sx_layout sxau_pmm_header={UINT32_C(0x602C0072),"pmm_header",sxau_pmm_header_fields,SX_COUNT(sxau_pmm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxau_pmm_sample_fields[]={
 SX_FIELD("magic","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("pcm_bytes","uint16",6,2,SX_SIZE),
 SX_FIELD("unknown","bytes",8,2,SX_NONE),
};
static const sx_layout sxau_pmm_sample={UINT32_C(0x602C0073),"pmm_sample",sxau_pmm_sample_fields,SX_COUNT(sxau_pmm_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxau_pmm_instrument_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxau_pmm_instrument={UINT32_C(0x602C0074),"pmm_instrument",sxau_pmm_instrument_fields,SX_COUNT(sxau_pmm_instrument_fields),SX_LE};
static const sx_layout *const sx_audiomore_layouts[]={
 &sxau_awb_header,
 &sxau_awb_id16,
 &sxau_awb_offset16,
 &sxau_awb_id32,
 &sxau_awb_offset32,
 &sxau_xwb_header,
 &sxau_xwb_segment,
 &sxau_xwb_bank_data,
 &sxau_xwb_entry,
 &sxau_xact_name,
 &sxau_xsb_header,
 &sxau_xsb_cue,
 &sxau_xsb_simple_sound,
 &sxau_ast_header,
 &sxau_ast_block,
 &sxau_hca_header,
 &sxau_hca_format,
 &sxau_hca_compression,
 &sxau_hca_ath,
 &sxau_hca_loop,
 &sxau_hca_cipher,
 &sxau_hca_relative_volume,
 &sxau_hca_comment,
 &sxau_hca_pad,
 &sxau_hca_checksum,
 &sxau_hca_frame_sync,
 &sxau_iff8svx_form,
 &sxau_iff8svx_chunk,
 &sxau_iff8svx_voice,
 &sxau_iff8svx_channel,
 &sxau_vgm_header,
 &sxau_vgm_gd3,
 &sxau_vgm_command,
 &sxau_vgm_register8,
 &sxau_vgm_register16,
 &sxau_vgm_wait,
 &sxau_vgm_data_block,
 &sxau_vgm_pcm_seek,
 &sxau_vgm_dac_setup,
 &sxau_vgm_dac_data,
 &sxau_vgm_dac_frequency,
 &sxau_vgm_dac_start,
 &sxau_vgm_dac_stop,
 &sxau_vgm_dac_fast_start,
 &sxau_ac3_sync_info,
 &sxau_ac3_checksum2,
 &sxau_mp3_frame_header,
 &sxau_id3_header,
 &sxau_id3v23_frame,
 &sxau_id3v24_frame,
 &sxau_adts_header,
 &sxau_adts_crc,
 &sxau_ape_descriptor,
 &sxau_ape_header,
 &sxau_ape_seek,
 &sxau_ape_tag,
 &sxau_ape_tag_item,
 &sxau_sdif_header,
 &sxau_sdif_frame,
 &sxau_sdif_matrix,
 &sxau_sap_binary_marker,
 &sxau_sap_load_segment,
 &sxau_sc68_header,
 &sxau_sc68_chunk,
 &sxau_sc68_default,
 &sxau_sc68_load_address,
 &sxau_sc68_integer,
 &sxau_amiga_ahx_header,
 &sxau_amiga_ahx_subsong,
 &sxau_amiga_ahx_channel_order,
 &sxau_amiga_ahx_instrument,
 &sxau_amiga_ahx_playlist,
 &sxau_vab_header,
 &sxau_vab_program,
 &sxau_vab_tone,
 &sxau_vab_sample_size,
 &sxau_ay_header,
 &sxau_ay_track_index,
 &sxau_ay_track,
 &sxau_ay_cpu_state,
 &sxau_ay_block,
 &sxau_ay_blocks_end,
 &sxau_fsb1_header,
 &sxau_fsb1_sample,
 &sxau_fsb2_header,
 &sxau_fsb34_version,
 &sxau_fsb4_hash,
 &sxau_fsb_sample,
 &sxau_fsb_sample_basic,
 &sxau_fsb5_header,
 &sxau_fsb5_sample,
 &sxau_fsb5_chunk,
 &sxau_fsb5_channels,
 &sxau_fsb5_frequency,
 &sxau_fsb5_name_offset,
 &sxau_acm_header,
 &sxau_cri_ahx_header,
 &sxau_cri_ahx_copyright,
 &sxau_cri_ahx_footer,
 &sxau_dss_header,
 &sxau_ea_block_le,
 &sxau_nitro_header_le,
 &sxau_nitro_chunk_le,
 &sxau_nitro_stream_le,
 &sxau_paf_header_le,
 &sxau_ea_block_be,
 &sxau_nitro_header_be,
 &sxau_nitro_chunk_be,
 &sxau_nitro_stream_be,
 &sxau_paf_header_be,
 &sxau_abylight_header,
 &sxau_alp_header,
 &sxau_alp_sample_rate,
 &sxau_pmm_header,
 &sxau_pmm_sample,
 &sxau_pmm_instrument,
};
/* Every walker bounds its physical reads independently. Native readers decide
 * validity; compressed samples and unimplemented extensions stay RAW_DATA. */
typedef struct sxau_view {sx_context *c;uint8_t *p;size_t n;unsigned work;}sxau_view;
static bool sx_audiomore_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_CRI_AWB:case XX_FILE_TYPE_MICROSOFT_XWB:case XX_FILE_TYPE_MICROSOFT_XSB:case XX_FILE_TYPE_AUDIO_AST:case XX_FILE_TYPE_AUDIO_HCA:case XX_FILE_TYPE_IFF_8SVX:case XX_FILE_TYPE_VGM_LOG:case XX_FILE_TYPE_AUDIO_DOLBY_AC3:case XX_FILE_TYPE_AUDIO_MPEG_MP3:case XX_FILE_TYPE_AUDIO_AAC_ADTS:case XX_FILE_TYPE_AUDIO_MONKEYS_APE:case XX_FILE_TYPE_IRCAM_SDIF:case XX_FILE_TYPE_ATARI_SAP:case XX_FILE_TYPE_SC68_MUSIC:case XX_FILE_TYPE_AMIGA_AHX:case XX_FILE_TYPE_SONY_VAB:case XX_FILE_TYPE_ZX_AYEMUL:case XX_FILE_TYPE_FMOD_SAMPLE_BANK:case XX_FILE_TYPE_INTERPLAY_ACM:case XX_FILE_TYPE_CRI_AHX:case XX_FILE_TYPE_OLYMPUS_DSS:case XX_FILE_TYPE_EA_EXA:case XX_FILE_TYPE_AUDIO_NITRO_STRM:case XX_FILE_TYPE_ENSONIQ_PAF:case XX_FILE_TYPE_ABYLIGHT_STRM:case XX_FILE_TYPE_LEGO_ALP:case XX_FILE_TYPE_PARSEC_PMM:return true;default:return false;}}
static bool sxau_need(sxau_view *v,size_t at,uint64_t n,size_t end){return !xx_pd_is_stopped(v->c->pd)&&end<=v->n&&at<=end&&n<=end-at;}
static uint16_t sxau_u16(const uint8_t*p,bool be){return xx_data_get_u16(p,2,0,be);}
static uint32_t sxau_u32(const uint8_t*p,bool be){return xx_data_get_u32(p,4,0,be);}
static bool sxau_row(sxau_view *v,const sx_layout*l,size_t at,size_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;size_t n=(size_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxau_need(v,at,n,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)n);}
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_table(sxau_view*v,const sx_layout*l,size_t at,uint64_t count,size_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;size_t z=(size_t)(f->rel_offset+f->size);if(count>4000000||!sxau_need(v,at,count*z,end))return false;for(uint64_t i=0;i<count;i++,at+=z)if(!sxau_row(v,l,at,end))return false;return true;}
static int sxau_order(const void*aa,const void*bb){const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxau_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxau_order);
 /* AY permits shared descriptor ranges. Keep one physical interpretation;
  * never repeat identical source bytes as overlapping structures. */
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxau_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxau_awb(sxau_view*v)
{if(!SA_ROW(awb_header,0,v->n))return false;unsigned ow=v->p[5],iw=sxau_u16(v->p+6,false);uint64_t n=sxau_u32(v->p+8,false);if((ow!=2&&ow!=4)||(iw!=2&&iw!=4)||n>1000000)return false;return sxau_table(v,iw==2?&sxau_awb_id16:&sxau_awb_id32,16,n,v->n)&&sxau_table(v,ow==2?&sxau_awb_offset16:&sxau_awb_offset32,16+(size_t)n*iw,n+1,v->n);}
static bool sxau_xwb(sxau_view*v)
{if(!SA_ROW(xwb_header,0,v->n)||!sxau_table(v,&sxau_xwb_segment,12,5,v->n))return false;size_t bank=sxau_u32(v->p+12,false),meta=sxau_u32(v->p+20,false),names=sxau_u32(v->p+36,false);if(!SA_ROW(xwb_bank_data,bank,v->n))return false;uint32_t n=sxau_u32(v->p+bank+4,false);if(!sxau_table(v,&sxau_xwb_entry,meta,n,v->n))return false;return !sxau_u32(v->p+40,false)||sxau_table(v,&sxau_xact_name,names,n,v->n);}
static bool sxau_xsb(sxau_view*v)
{if(!SA_ROW(xsb_header,0,v->n))return false;return sxau_table(v,&sxau_xsb_cue,sxau_u32(v->p+34,false),sxau_u16(v->p+19,false),v->n)&&sxau_table(v,&sxau_xsb_simple_sound,sxau_u32(v->p+70,false),sxau_u16(v->p+28,false),v->n)&&sxau_table(v,&sxau_xact_name,sxau_u32(v->p+58,false),v->p[27],v->n);}
static bool sxau_ast(sxau_view*v)
{if(!SA_ROW(ast_header,0,v->n))return false;unsigned ch=sxau_u16(v->p+12,true);size_t at=64;if(!ch)return false;while(at<v->n){if(!SA_ROW(ast_block,at,v->n))return false;uint64_t z=(uint64_t)sxau_u32(v->p+at+4,true)*ch;at+=32;if(!z||!sxau_need(v,at,z,v->n))return false;at+=(size_t)z;}return true;}
static bool sxau_hca(sxau_view*v)
{if(!SA_ROW(hca_header,0,v->n))return false;size_t h=sxau_u16(v->p+6,true);if(h<42||!sxau_need(v,0,h,v->n)||!SA_ROW(hca_format,8,h-2)||!SA_ROW(hca_compression,24,h-2)||!SA_ROW(hca_checksum,h-2,h))return false;size_t at=40;
 while(at<h-2){if(!sxau_need(v,at,4,h-2))return false;const uint8_t*p=v->p+at;size_t z=0;const sx_layout*l=NULL;
  if(!xx_rt_memcmp(p,"ath\0",4)){l=&sxau_hca_ath;z=6;}else if(!xx_rt_memcmp(p,"loop",4)){l=&sxau_hca_loop;z=16;}else if(!xx_rt_memcmp(p,"ciph",4)){l=&sxau_hca_cipher;z=6;}else if(!xx_rt_memcmp(p,"rva\0",4)){l=&sxau_hca_relative_volume;z=8;}else if(!xx_rt_memcmp(p,"comm",4)){if(!sxau_need(v,at,5,h-2))return false;l=&sxau_hca_comment;z=5+v->p[at+4];}else if(!xx_rt_memcmp(p,"pad\0",4)){if(!SA_ROW(hca_pad,at,h-2))return false;at=h-2;break;}else return false;
  if(!sxau_need(v,at,z,h-2)||!sxau_row(v,l,at,h-2))return false;at+=z;
 }size_t frames=sxau_u32(v->p+16,true),z=sxau_u16(v->p+28,true);if(z<4||frames>1000000||!sxau_need(v,h,(uint64_t)frames*z,v->n))return false;for(at=h;frames;frames--,at+=z)if(!SA_ROW(hca_frame_sync,at,v->n)||!SA_ROW(hca_checksum,at+z-2,v->n))return false;return at==v->n;}
static bool sxau_iff(sxau_view*v)
{if(!SA_ROW(iff8svx_form,0,v->n))return false;size_t at=12;while(at<v->n){if(!SA_ROW(iff8svx_chunk,at,v->n))return false;uint32_t n=sxau_u32(v->p+at+4,true);size_t data=at+8;if(!sxau_need(v,data,(uint64_t)n+(n&1),v->n))return false;if(!xx_rt_memcmp(v->p+at,"VHDR",4)&&!SA_ROW(iff8svx_voice,data,data+n))return false;if(!xx_rt_memcmp(v->p+at,"CHAN",4)&&!SA_ROW(iff8svx_channel,data,data+n))return false;at=data+n+(n&1);}return true;}
static bool sxau_vgm(sxau_view*v)
{if(!SA_ROW(vgm_header,0,v->n))return false;uint32_t ver=sxau_u32(v->p+8,false),rel=sxau_u32(v->p+52,false);size_t at=ver>=0x150&&rel?52+(size_t)rel:64;size_t gd3=sxau_u32(v->p+20,false);if(gd3){gd3+=20;if(!SA_ROW(vgm_gd3,gd3,v->n)||!sxau_need(v,gd3+12,sxau_u32(v->p+gd3+8,false),v->n))return false;}size_t end=gd3?gd3:v->n;
 if(at<64||at>=end)return false;while(at<end){unsigned op=v->p[at];const sx_layout*l=&sxau_vgm_command;size_t z=1;
  if(op==0x4f||op==0x50){l=&sxau_vgm_register8;z=2;}else if(op>=0x51&&op<=0x5f){l=&sxau_vgm_register16;z=3;}else if(op==0x61){l=&sxau_vgm_wait;z=3;}else if(op==0x67){l=&sxau_vgm_data_block;z=7;}else if(op==0xe0){l=&sxau_vgm_pcm_seek;z=5;}else if(op>=0x90&&op<=0x95){static const sx_layout*const a[]={&sxau_vgm_dac_setup,&sxau_vgm_dac_data,&sxau_vgm_dac_frequency,&sxau_vgm_dac_start,&sxau_vgm_dac_stop,&sxau_vgm_dac_fast_start};static const uint8_t lens[]={5,5,6,11,2,5};l=a[op-0x90];z=lens[op-0x90];}else if(!(op==0x62||op==0x63||op==0x66||(op>=0x70&&op<=0x8f)))return false;
  if(!sxau_row(v,l,at,end))return false;if(op==0x67){uint32_t bytes=sxau_u32(v->p+at+3,false);if(!sxau_need(v,at+7,bytes,end))return false;z+=bytes;}at+=z;if(op==0x66)return at==end;
 }return false;}
static bool sxau_ac3(sxau_view*v)
{static const uint16_t br[]={32,40,48,56,64,80,96,112,128,160,192,224,256,320,384,448,512,576,640},w44[]={69,87,104,121,139,174,208,243,278,348,417,487,557,696,835,975,1114,1253,1393};size_t at=0;while(at<v->n){if(!SA_ROW(ac3_sync_info,at,v->n))return false;unsigned sr=v->p[at+4]>>6,code=v->p[at+4]&63;if(sr>=3||code>=38)return false;size_t z=2*(sr==0?br[code/2]*2:sr==2?br[code/2]*3:w44[code/2]+(code&1));if(!sxau_need(v,at,z,v->n)||!SA_ROW(ac3_checksum2,at+z-2,v->n))return false;at+=z;}return true;}
static uint32_t sxau_syncsafe(const uint8_t*p){return ((uint32_t)p[0]<<21)|((uint32_t)p[1]<<14)|((uint32_t)p[2]<<7)|p[3];}
static bool sxau_mp3(sxau_view*v)
{size_t at=0;if(v->n>=3&&!xx_rt_memcmp(v->p,"ID3",3)){if(!SA_ROW(id3_header,0,v->n))return false;size_t end=10+(size_t)sxau_syncsafe(v->p+6);if(end>v->n)return false;at=10;while(at<end&&v->p[at]){bool v4=v->p[3]==4;if(!sxau_row(v,v4?&sxau_id3v24_frame:&sxau_id3v23_frame,at,end))return false;uint32_t z=v4?sxau_syncsafe(v->p+at+4):sxau_u32(v->p+at+4,true);at+=10;if(!sxau_need(v,at,z,end))return false;at+=z;}at=end;}
 while(at<v->n){static const uint16_t br[]={0,32,40,48,56,64,80,96,112,128,160,192,224,256,320};static const uint32_t rates[]={44100,48000,32000};if(!SA_ROW(mp3_frame_header,at,v->n))return false;unsigned bi=v->p[at+2]>>4,ri=(v->p[at+2]>>2)&3;if(!bi||bi>=15||ri>=3)return false;size_t z=144000U*br[bi]/rates[ri]+((v->p[at+2]>>1)&1);if(!sxau_need(v,at,z,v->n))return false;at+=z;}return true;}
static bool sxau_adts(sxau_view*v,size_t at,size_t end)
{while(at<end){if(!SA_ROW(adts_header,at,end))return false;size_t z=((v->p[at+3]&3)<<11)|(v->p[at+4]<<3)|(v->p[at+5]>>5),h=(v->p[at+1]&1)?7:9;if(z<h||!sxau_need(v,at,z,end))return false;if(h==9&&!SA_ROW(adts_crc,at+7,at+z))return false;at+=z;}return at==end;}
static bool sxau_ape(sxau_view*v)
{if(!SA_ROW(ape_descriptor,0,v->n)||!SA_ROW(ape_header,52,v->n))return false;uint32_t frames=sxau_u32(v->p+64,false);if(!sxau_table(v,&sxau_ape_seek,76,frames,v->n))return false;
 if(v->n>=32&&!xx_rt_memcmp(v->p+v->n-32,"APETAGEX",8)){size_t foot=v->n-32;uint32_t bytes=sxau_u32(v->p+foot+12,false),count=sxau_u32(v->p+foot+16,false),flags=sxau_u32(v->p+foot+20,false);if(bytes<32||bytes>v->n||count>1024||!SA_ROW(ape_tag,foot,v->n))return false;size_t at=v->n-bytes;if(flags&0x80000000U){if(at<32||!SA_ROW(ape_tag,at-32,at))return false;}for(uint32_t i=0;i<count;i++){if(!SA_ROW(ape_tag_item,at,foot))return false;uint32_t z=sxau_u32(v->p+at,false);at+=8;size_t key=0;while(at<foot&&v->p[at]&&key<256){at++;key++;}if(!key||at==foot||v->p[at]||!sxau_need(v,at+1,z,foot))return false;at+=1+z;}if(at!=foot)return false;}return true;}
static bool sxau_sdif(sxau_view*v)
{if(!SA_ROW(sdif_header,0,v->n))return false;size_t at=16;while(at<v->n){if(!SA_ROW(sdif_frame,at,v->n))return false;size_t end=at+8+(size_t)sxau_u32(v->p+at+4,true);if(end<at+24||end>v->n)return false;uint32_t count=sxau_u32(v->p+at+20,true);at+=24;for(uint32_t i=0;i<count;i++){if(!SA_ROW(sdif_matrix,at,end))return false;uint32_t type=sxau_u32(v->p+at+4,true),rows=sxau_u32(v->p+at+8,true),cols=sxau_u32(v->p+at+12,true);unsigned width=type&255;if(width!=1&&width!=2&&width!=4&&width!=8)return false;uint64_t z=(uint64_t)rows*cols;if(z>SIZE_MAX/width)return false;z*=width;at+=16;uint64_t pad=(8-z%8)%8;if(z>SIZE_MAX-pad||!sxau_need(v,at,z+pad,end))return false;at+=(size_t)(z+pad);}if(at!=end)return false;}return true;}
static bool sxau_sap(sxau_view*v)
{size_t at=0;while(at+1<v->n&&at<65536&&!(v->p[at]==255&&v->p[at+1]==255))at++;if(!SA_ROW(sap_binary_marker,at,v->n))return false;at+=2;while(at<v->n){if(!sxau_need(v,at,2,v->n))return false;if(sxau_u16(v->p+at,false)==65535){if(!SA_ROW(sap_binary_marker,at,v->n))return false;at+=2;}if(!SA_ROW(sap_load_segment,at,v->n))return false;uint32_t a=sxau_u16(v->p+at,false),b=sxau_u16(v->p+at+2,false);at+=4;if(b<a||!sxau_need(v,at,b-a+1,v->n))return false;at+=b-a+1;}return true;}
static bool sxau_sc68(sxau_view*v)
{if(!SA_ROW(sc68_header,0,v->n))return false;size_t at=64;while(at<v->n){if(!SA_ROW(sc68_chunk,at,v->n))return false;uint32_t n=sxau_u32(v->p+at+4,false);if(!sxau_need(v,at+8,n,v->n))return false;const uint8_t*p=v->p+at;if(n==4){const sx_layout*l=!xx_rt_memcmp(p,"SCDF",4)?&sxau_sc68_default:!xx_rt_memcmp(p,"SCAT",4)?&sxau_sc68_load_address:(!xx_rt_memcmp(p,"SCD0",4)||!xx_rt_memcmp(p,"SCTI",4)||!xx_rt_memcmp(p,"SCFR",4)||!xx_rt_memcmp(p,"SCFQ",4)||!xx_rt_memcmp(p,"SCLP",4)||!xx_rt_memcmp(p,"SCTY",4))?&sxau_sc68_integer:NULL;if(l&&!sxau_row(v,l,at+8,at+8+n))return false;}at+=8+n;}return true;}
static bool sxau_amiga(sxau_view*v)
{if(!SA_ROW(amiga_ahx_header,0,v->n))return false;size_t at=14,subs=v->p[13],pos=sxau_u16(v->p+6,true)&4095,tracks=v->p[11]+((v->p[6]&128)?0:1),rows=v->p[10],ins=v->p[12];if(!sxau_table(v,&sxau_amiga_ahx_subsong,at,subs,v->n))return false;at+=subs*2;if(!sxau_table(v,&sxau_amiga_ahx_channel_order,at,pos*4,v->n))return false;at+=pos*8;if(!sxau_need(v,at,tracks*rows*3,v->n))return false;at+=tracks*rows*3;for(size_t i=0;i<ins;i++){if(!SA_ROW(amiga_ahx_instrument,at,v->n))return false;unsigned count=v->p[at+21];at+=22;if(!sxau_table(v,&sxau_amiga_ahx_playlist,at,count,v->n))return false;at+=count*4;}return at<=v->n;}
static bool sxau_vab(sxau_view*v)
{if(!SA_ROW(vab_header,0,v->n)||!sxau_table(v,&sxau_vab_program,32,128,v->n))return false;size_t programs=sxau_u16(v->p+18,false),at=2080;if(programs>128||!sxau_table(v,&sxau_vab_tone,at,programs*16,v->n))return false;at+=programs*512;return sxau_table(v,&sxau_vab_sample_size,at,256,v->n);}
static bool sxau_ayptr(sxau_view*v,size_t at,size_t z,size_t*out)
{if(!sxau_need(v,at,2,v->n))return false;int64_t n=(int64_t)at+(int16_t)sxau_u16(v->p+at,true);if(n<20||!sxau_need(v,(size_t)n,z,v->n))return false;*out=(size_t)n;return true;}
static bool sxau_ay(sxau_view*v)
{if(!SA_ROW(ay_header,0,v->n))return false;size_t table;unsigned n=(unsigned)v->p[16]+1;if(!sxau_ayptr(v,18,n*4,&table)||!sxau_table(v,&sxau_ay_track_index,table,n,v->n))return false;for(unsigned i=0;i<n;i++){size_t desc,state,blocks;if(!sxau_ayptr(v,table+i*4+2,14,&desc)||!SA_ROW(ay_track,desc,v->n)||!sxau_ayptr(v,desc+10,6,&state)||!SA_ROW(ay_cpu_state,state,v->n)||!sxau_ayptr(v,desc+12,2,&blocks))return false;unsigned count=0;for(;;){if(!sxau_need(v,blocks,2,v->n))return false;if(!sxau_u16(v->p+blocks,true)){if(!SA_ROW(ay_blocks_end,blocks,v->n))return false;break;}if(count++>=256||!SA_ROW(ay_block,blocks,v->n))return false;blocks+=6;}}return true;}
static bool sxau_fsb(sxau_view*v)
{if(!sxau_need(v,0,16,v->n))return false;unsigned ver=v->p[3]-'0';uint32_t n=sxau_u32(v->p+4,false);if(ver==1)return SA_ROW(fsb1_header,0,v->n)&&sxau_table(v,&sxau_fsb1_sample,16,n,v->n);
 if(ver>=2&&ver<=4){if(!SA_ROW(fsb2_header,0,v->n))return false;size_t h=ver==2?16:ver==3?24:48;if(ver>2&&!SA_ROW(fsb34_version,16,v->n))return false;if(ver==4&&!SA_ROW(fsb4_hash,24,v->n))return false;uint32_t flags=ver>2?sxau_u32(v->p+20,false):0,bytes=sxau_u32(v->p+8,false);if(n>1000000||!sxau_need(v,h,bytes,v->n))return false;size_t at=h,end=h+bytes;
  for(uint32_t i=0;i<n;i++){if(i&&(flags&2)){if(!SA_ROW(fsb_sample_basic,at,end))return false;at+=8;}else{if(!SA_ROW(fsb_sample,at,end))return false;uint16_t z=sxau_u16(v->p+at,false);if(z<64||!sxau_need(v,at,z,end))return false;at+=z;}}return at<=end;
 }if(ver==5){if(!SA_ROW(fsb5_header,0,v->n))return false;unsigned revision=sxau_u32(v->p+4,false);n=sxau_u32(v->p+8,false);size_t h=revision?60:64;uint32_t bytes=sxau_u32(v->p+12,false),names=sxau_u32(v->p+16,false);if(revision>1||n>1000000||!sxau_need(v,h,(uint64_t)bytes+names,v->n))return false;size_t at=h,end=h+bytes;
  for(uint32_t i=0;i<n;i++){if(!SA_ROW(fsb5_sample,at,end))return false;bool more=(v->p[at]&1)!=0;at+=8;while(more){if(!SA_ROW(fsb5_chunk,at,end))return false;uint32_t m=sxau_u32(v->p+at,false),z=(m>>1)&0xffffff,type=m>>25;more=(m&1)!=0;at+=4;if(!sxau_need(v,at,z,end))return false;if(type==1&&z==1&&!SA_ROW(fsb5_channels,at,at+z))return false;if(type==2&&z==4&&!SA_ROW(fsb5_frequency,at,at+z))return false;at+=z;}}
  return !names||sxau_table(v,&sxau_fsb5_name_offset,end,n,end+names);
 }return false;}
static bool sxau_ea_check(sxau_view*v,bool be)
{size_t at=0;unsigned i=0;while(at<v->n){if(++i>4096||!sxau_need(v,at,8,v->n))return false;uint32_t z=sxau_u32(v->p+at+4,be);if(z<8||!sxau_need(v,at,z,v->n))return false;at+=z;}return true;}
static bool sxau_ea(sxau_view*v)
{bool be=false;if(!sxau_ea_check(v,false)){be=true;if(!sxau_ea_check(v,true))return false;}size_t at=0;while(at<v->n){if(!sxau_row(v,be?&sxau_ea_block_be:&sxau_ea_block_le,at,v->n))return false;at+=sxau_u32(v->p+at+4,be);}return true;}
static bool sxau_nitro(sxau_view*v)
{if(!sxau_need(v,0,6,v->n))return false;bool be=v->p[4]==254;if(!sxau_row(v,be?&sxau_nitro_header_be:&sxau_nitro_header_le,0,v->n)||!sxau_row(v,be?&sxau_nitro_chunk_be:&sxau_nitro_chunk_le,16,v->n))return false;size_t n=sxau_u32(v->p+20,be);if(n<48||!sxau_need(v,16,n,v->n)||!sxau_row(v,be?&sxau_nitro_stream_be:&sxau_nitro_stream_le,24,16+n))return false;return sxau_row(v,be?&sxau_nitro_chunk_be:&sxau_nitro_chunk_le,16+n,v->n);}
static bool sxau_pmm(sxau_view*v)
{if(!SA_ROW(pmm_header,0,v->n))return false;unsigned n=v->p[64];if(n>8||!SA_ROW(pmm_instrument,sxau_u32(v->p+16,false),v->n))return false;for(unsigned i=0;i<n;i++)if(!SA_ROW(pmm_sample,sxau_u32(v->p+20+4*i,false),v->n))return false;return true;}
static bool sx_audiomore_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0||c->size>134217728)return false;sxau_view view={c,NULL,(size_t)c->size,0},*v=&view;v->p=(uint8_t*)xx_mem_alloc(v->n);if(!v->p||!sx_read(c,0,v->p,v->n)){if(v->p)xx_mem_free(v->p);return false;}bool ok=false;
 switch(c->f->file_type){case XX_FILE_TYPE_CRI_AWB:ok=sxau_awb(v);break;case XX_FILE_TYPE_MICROSOFT_XWB:ok=sxau_xwb(v);break;case XX_FILE_TYPE_MICROSOFT_XSB:ok=sxau_xsb(v);break;case XX_FILE_TYPE_AUDIO_AST:ok=sxau_ast(v);break;case XX_FILE_TYPE_AUDIO_HCA:ok=sxau_hca(v);break;case XX_FILE_TYPE_IFF_8SVX:ok=sxau_iff(v);break;case XX_FILE_TYPE_VGM_LOG:ok=sxau_vgm(v);break;case XX_FILE_TYPE_AUDIO_DOLBY_AC3:ok=sxau_ac3(v);break;case XX_FILE_TYPE_AUDIO_MPEG_MP3:ok=sxau_mp3(v);break;case XX_FILE_TYPE_AUDIO_AAC_ADTS:ok=sxau_adts(v,0,v->n);break;case XX_FILE_TYPE_AUDIO_MONKEYS_APE:ok=sxau_ape(v);break;case XX_FILE_TYPE_IRCAM_SDIF:ok=sxau_sdif(v);break;case XX_FILE_TYPE_ATARI_SAP:ok=sxau_sap(v);break;case XX_FILE_TYPE_SC68_MUSIC:ok=sxau_sc68(v);break;case XX_FILE_TYPE_AMIGA_AHX:ok=sxau_amiga(v);break;case XX_FILE_TYPE_SONY_VAB:ok=sxau_vab(v);break;case XX_FILE_TYPE_ZX_AYEMUL:ok=sxau_ay(v);break;case XX_FILE_TYPE_FMOD_SAMPLE_BANK:ok=sxau_fsb(v);break;case XX_FILE_TYPE_INTERPLAY_ACM:ok=SA_ROW(acm_header,0,v->n);break;case XX_FILE_TYPE_CRI_AHX:if(SA_ROW(cri_ahx_header,0,v->n)){size_t start=(size_t)sxau_u16(v->p+2,true)+4;ok=start>=24&&SA_ROW(cri_ahx_copyright,start-6,v->n);if(ok&&v->n>=10&&!xx_rt_memcmp(v->p+v->n-10,"AHXE(c)CRI",10))ok=SA_ROW(cri_ahx_footer,v->n-10,v->n);}break;case XX_FILE_TYPE_OLYMPUS_DSS:ok=SA_ROW(dss_header,0,v->n);break;case XX_FILE_TYPE_EA_EXA:ok=sxau_ea(v);break;case XX_FILE_TYPE_AUDIO_NITRO_STRM:ok=sxau_nitro(v);break;case XX_FILE_TYPE_ENSONIQ_PAF:ok=sxau_need(v,0,4,v->n)&&sxau_row(v,v->p[0]==' '?&sxau_paf_header_be:&sxau_paf_header_le,0,v->n);break;case XX_FILE_TYPE_ABYLIGHT_STRM:ok=SA_ROW(abylight_header,0,v->n)&&sxau_adts(v,30,v->n);break;case XX_FILE_TYPE_LEGO_ALP:ok=SA_ROW(alp_header,0,v->n);if(ok&&sxau_u32(v->p+4,false)==12)ok=SA_ROW(alp_sample_rate,16,v->n);break;case XX_FILE_TYPE_PARSEC_PMM:ok=sxau_pmm(v);break;default:break;}
 xx_mem_free(v->p);return ok&&sxau_finish(c);}
#undef SA_ROW
static bool sx_audiomore_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id<(int32_t)UINT32_C(0x602c0000)||id>=(int32_t)UINT32_C(0x602d0000))return true;
 if(id==1613496334&&!xx_rt_wcscmp(r->name,L"encoding")){switch(xx_var_get_u64(&r->value)){
 case 1:return xx_data_struct_record_set_comment(r,L"PCM");
 default:break;}}
 if(id==1613496336&&!xx_rt_wcscmp(r->name,L"version")){switch(xx_var_get_u64(&r->value)){
 case 512:return xx_data_struct_record_set_comment(r,L"HCA2.0");
 default:break;}}
 if(id==1613496341&&!xx_rt_wcscmp(r->name,L"cipher_type")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"HCA_CIPHER_NONE");
 case 1:return xx_data_struct_record_set_comment(r,L"HCA_CIPHER1");
 case 56:return xx_data_struct_record_set_comment(r,L"HCA_CIPHER56");
 default:break;}}
 if(id==1613496339&&!xx_rt_wcscmp(r->name,L"ath_type")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"ATH_DISABLED");
 case 1:return xx_data_struct_record_set_comment(r,L"ATH_ENABLED");
 default:break;}}
 if(id==1613496349&&!xx_rt_wcscmp(r->name,L"compression")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"CMP_NONE");
 case 1:return xx_data_struct_record_set_comment(r,L"CMP_FIBDELTA");
 default:break;}}
 if(id==1613496350&&!xx_rt_wcscmp(r->name,L"channel_assignment")){switch(xx_var_get_u64(&r->value)){
 case 2:return xx_data_struct_record_set_comment(r,L"LEFT");
 case 4:return xx_data_struct_record_set_comment(r,L"RIGHT");
 case 6:return xx_data_struct_record_set_comment(r,L"STEREO");
 default:break;}}
 if(id==1613496374&&!xx_rt_wcscmp(r->name,L"compression_level")){switch(xx_var_get_u64(&r->value)){
 case 1000:return xx_data_struct_record_set_comment(r,L"FAST");
 case 2000:return xx_data_struct_record_set_comment(r,L"NORMAL");
 case 3000:return xx_data_struct_record_set_comment(r,L"HIGH");
 case 4000:return xx_data_struct_record_set_comment(r,L"EXTRA_HIGH");
 case 5000:return xx_data_struct_record_set_comment(r,L"INSANE");
 default:break;}}
 if(id==1613496417&&!xx_rt_wcscmp(r->name,L"encoding")){switch(xx_var_get_u64(&r->value)){
 case 16:return xx_data_struct_record_set_comment(r,L"AHX_LOW_RATE");
 case 17:return xx_data_struct_record_set_comment(r,L"AHX_STANDARD");
 default:break;}}
 if(id==1613496417&&!xx_rt_wcscmp(r->name,L"encryption_type")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"UNENCRYPTED");
 case 8:return xx_data_struct_record_set_comment(r,L"KEY8");
 case 9:return xx_data_struct_record_set_comment(r,L"KEY9");
 default:break;}}
 if(id==1613496424&&!xx_rt_wcscmp(r->name,L"encoding")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"PCM8");
 case 1:return xx_data_struct_record_set_comment(r,L"PCM16");
 case 2:return xx_data_struct_record_set_comment(r,L"IMA_ADPCM");
 default:break;}}
 if(id==1613496425&&!xx_rt_wcscmp(r->name,L"sample_byte_order")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"BIG_ENDIAN");
 case 1:return xx_data_struct_record_set_comment(r,L"LITTLE_ENDIAN");
 default:break;}}
 if(id==1613496425&&!xx_rt_wcscmp(r->name,L"encoding")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"PCM16");
 case 1:return xx_data_struct_record_set_comment(r,L"PACKED_PCM24");
 case 2:return xx_data_struct_record_set_comment(r,L"PCM8");
 default:break;}}
 if(id==1613496425&&!xx_rt_wcscmp(r->name,L"source")){switch(xx_var_get_u64(&r->value)){
 case 1:return xx_data_struct_record_set_comment(r,L"ANALOG_RECORDING");
 case 2:return xx_data_struct_record_set_comment(r,L"DIGITAL_TRANSFER");
 case 3:return xx_data_struct_record_set_comment(r,L"MULTITRACK_MIXDOWN");
 case 5:return xx_data_struct_record_set_comment(r,L"DSP_PROCESSING");
 default:break;}}
 if(id==1613496429&&!xx_rt_wcscmp(r->name,L"encoding")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"PCM8");
 case 1:return xx_data_struct_record_set_comment(r,L"PCM16");
 case 2:return xx_data_struct_record_set_comment(r,L"IMA_ADPCM");
 default:break;}}
 if(id==1613496430&&!xx_rt_wcscmp(r->name,L"sample_byte_order")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"BIG_ENDIAN");
 case 1:return xx_data_struct_record_set_comment(r,L"LITTLE_ENDIAN");
 default:break;}}
 if(id==1613496430&&!xx_rt_wcscmp(r->name,L"encoding")){switch(xx_var_get_u64(&r->value)){
 case 0:return xx_data_struct_record_set_comment(r,L"PCM16");
 case 1:return xx_data_struct_record_set_comment(r,L"PACKED_PCM24");
 case 2:return xx_data_struct_record_set_comment(r,L"PCM8");
 default:break;}}
 if(id==1613496430&&!xx_rt_wcscmp(r->name,L"source")){switch(xx_var_get_u64(&r->value)){
 case 1:return xx_data_struct_record_set_comment(r,L"ANALOG_RECORDING");
 case 2:return xx_data_struct_record_set_comment(r,L"DIGITAL_TRANSFER");
 case 3:return xx_data_struct_record_set_comment(r,L"MULTITRACK_MIXDOWN");
 case 5:return xx_data_struct_record_set_comment(r,L"DSP_PROCESSING");
 default:break;}}
 if(id==1613496321&&!xx_rt_wcscmp(r->name,L"alignment"))return xx_data_struct_record_set_comment(r,L"Byte alignment applied to stored member offsets.");
 if(id==1613496321&&!xx_rt_wcscmp(r->name,L"subkey"))return xx_data_struct_record_set_comment(r,L"CRI AWB subkey; does not imply payload decryption.");
 if(id==1613496328&&!xx_rt_wcscmp(r->name,L"build_time"))return xx_data_struct_record_set_comment(r,L"Windows FILETIME:100 ns intervals since1601-01-01 UTC.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"last_modified"))return xx_data_struct_record_set_comment(r,L"Windows FILETIME:100 ns intervals since1601-01-01 UTC.");
 if(id==1613496329&&!xx_rt_wcscmp(r->name,L"play_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset from the wave-data segment, not from the file start.");
 if(id==1613496329&&!xx_rt_wcscmp(r->name,L"flags_and_duration"))return xx_data_struct_record_set_comment(r,L"Bits0..3:entry flags; bits4..31:decoded duration in samples.");
 if(id==1613496329&&!xx_rt_wcscmp(r->name,L"mini_wave_format"))return xx_data_struct_record_set_comment(r,L"Bits0..1:codec;2..4:channels;5..22:sample rate;23..30:block alignment;31:16-bit PCM flag.");
 if(id==1613496328&&!xx_rt_wcscmp(r->name,L"compact_format"))return xx_data_struct_record_set_comment(r,L"Packed mini-wave format used by compact banks; native supported banks are noncompact.");
 if(id==1613496340&&!xx_rt_wcscmp(r->name,L"start_frame"))return xx_data_struct_record_set_comment(r,L"Zero-based encoded frame index.");
 if(id==1613496340&&!xx_rt_wcscmp(r->name,L"end_frame"))return xx_data_struct_record_set_comment(r,L"Inclusive encoded frame index.");
 if(id==1613496342&&!xx_rt_wcscmp(r->name,L"volume"))return xx_data_struct_record_set_comment(r,L"IEEE754 relative linear volume multiplier.");
 if(id==1613496349&&!xx_rt_wcscmp(r->name,L"volume_fixed16_16"))return xx_data_struct_record_set_comment(r,L"Unsigned16.16 fixed-point volume;65536 means1.0.");
 if(id==1613496347&&!xx_rt_wcscmp(r->name,L"form_bytes"))return xx_data_struct_record_set_comment(r,L"Byte length after the first8 bytes.");
 if(id==1613496348&&!xx_rt_wcscmp(r->name,L"payload_size"))return xx_data_struct_record_set_comment(r,L"Payload bytes; excludes8-byte header and optional odd-byte pad.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"eof_offset"))return xx_data_struct_record_set_comment(r,L"Byte displacement from file byte4; zero has the version-specific absent/default meaning.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"gd3_offset"))return xx_data_struct_record_set_comment(r,L"Byte displacement from file byte20; zero has the version-specific absent/default meaning.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"loop_offset"))return xx_data_struct_record_set_comment(r,L"Byte displacement from file byte28; zero has the version-specific absent/default meaning.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte displacement from file byte52; zero has the version-specific absent/default meaning.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"sn76489_clock"))return xx_data_struct_record_set_comment(r,L"Clock frequency in Hz; high bits may carry chip configuration flags.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"ym2413_clock"))return xx_data_struct_record_set_comment(r,L"Clock frequency in Hz; high bits may carry chip configuration flags.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"ym2612_clock"))return xx_data_struct_record_set_comment(r,L"Clock frequency in Hz; high bits may carry chip configuration flags.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"ym2151_clock"))return xx_data_struct_record_set_comment(r,L"Clock frequency in Hz; high bits may carry chip configuration flags.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"sega_pcm_clock"))return xx_data_struct_record_set_comment(r,L"Clock frequency in Hz; high bits may carry chip configuration flags.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"version"))return xx_data_struct_record_set_comment(r,L"Packed hexadecimal VGM version (for example0x160 means1.60).");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"total_samples"))return xx_data_struct_record_set_comment(r,L"Total duration in44100-Hz sample ticks.");
 if(id==1613496351&&!xx_rt_wcscmp(r->name,L"loop_samples"))return xx_data_struct_record_set_comment(r,L"Loop duration in44100-Hz sample ticks.");
 if(id==1613496356&&!xx_rt_wcscmp(r->name,L"wait_samples"))return xx_data_struct_record_set_comment(r,L"Delay in44100-Hz sample ticks.");
 if(id==1613496358&&!xx_rt_wcscmp(r->name,L"pcm_bank_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset into the concatenated PCM data bank, not a file position.");
 if(id==1613496362&&!xx_rt_wcscmp(r->name,L"data_start_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset into PCM data bank;0xFFFFFFFF continues current position.");
 if(id==1613496362&&!xx_rt_wcscmp(r->name,L"data_length"))return xx_data_struct_record_set_comment(r,L"Length interpretation depends on length_mode (commands, milliseconds, or data remainder).");
 if(id==1613496360&&!xx_rt_wcscmp(r->name,L"step_base"))return xx_data_struct_record_set_comment(r,L"Byte displacement within each PCM step.");
 if(id==1613496360&&!xx_rt_wcscmp(r->name,L"step_size"))return xx_data_struct_record_set_comment(r,L"PCM step size in bytes.");
 if(id==1613496362&&!xx_rt_wcscmp(r->name,L"length_mode"))return xx_data_struct_record_set_comment(r,L"Low2 bits:length mode; bit4:reverse; bit7:loop.");
 if(id==1613496365&&!xx_rt_wcscmp(r->name,L"sample_rate_and_frame_size_code"))return xx_data_struct_record_set_comment(r,L"Bits6..7:sample-rate code; bits0..5:frame-size code, not a byte count.");
 if(id==1613496365&&!xx_rt_wcscmp(r->name,L"bitstream_id_and_mode"))return xx_data_struct_record_set_comment(r,L"Bits3..7:bitstream ID; bits0..2:bitstream mode. Native supports classic AC-3 bsid8.");
 if(id==1613496367&&!xx_rt_wcscmp(r->name,L"sync_version_layer_protection"))return xx_data_struct_record_set_comment(r,L"11-bit sync, MPEG version, layer and protection-absent bit. Native supports MPEG1 LayerIII unprotected frames.");
 if(id==1613496367&&!xx_rt_wcscmp(r->name,L"bitrate_rate_padding_private"))return xx_data_struct_record_set_comment(r,L"Bits4..7:bitrate index;2..3:sample-rate index;1:padding;0:private.");
 if(id==1613496367&&!xx_rt_wcscmp(r->name,L"channel_mode_extension_flags"))return xx_data_struct_record_set_comment(r,L"Bits6..7:channel mode;4..5:mode extension;3:copyright;2:original;0..1:emphasis.");
 if(id==1613496368&&!xx_rt_wcscmp(r->name,L"synchsafe_size"))return xx_data_struct_record_set_comment(r,L"Four7-bit groups, most significant first; decoded tag length excludes10-byte prefix.");
 if(id==1613496370&&!xx_rt_wcscmp(r->name,L"synchsafe_size"))return xx_data_struct_record_set_comment(r,L"Four7-bit groups, most significant first; decoded frame payload byte length.");
 if(id==1613496371&&!xx_rt_wcscmp(r->name,L"sync_id_layer_protection"))return xx_data_struct_record_set_comment(r,L"Bits4..15:sync0xFFF;3:MPEG ID;1..2:layer;0:protection absent.");
 if(id==1613496371&&!xx_rt_wcscmp(r->name,L"profile_sampling_private_channel_high"))return xx_data_struct_record_set_comment(r,L"Bits6..7:profile;2..5:sampling frequency index;1:private;0:channel configuration high bit.");
 if(id==1613496371&&!xx_rt_wcscmp(r->name,L"channel_low_original_home_copyright_length_high"))return xx_data_struct_record_set_comment(r,L"Bits6..7:channel configuration low bits;5:original;4:home;3..2:copyright bits;1..0:frame length high bits.");
 if(id==1613496371&&!xx_rt_wcscmp(r->name,L"frame_length_middle"))return xx_data_struct_record_set_comment(r,L"Middle8 bits of the13-bit total ADTS frame byte length.");
 if(id==1613496371&&!xx_rt_wcscmp(r->name,L"length_low_buffer_fullness_high"))return xx_data_struct_record_set_comment(r,L"Bits5..7:frame length low bits;0..4:buffer fullness high bits.");
 if(id==1613496371&&!xx_rt_wcscmp(r->name,L"fullness_low_raw_block_count"))return xx_data_struct_record_set_comment(r,L"Bits2..7:buffer fullness low bits;0..1:raw data block count minus one.");
 if(id==1613496373&&!xx_rt_wcscmp(r->name,L"audio_data_bytes_low"))return xx_data_struct_record_set_comment(r,L"Low32 bits of encoded audio byte count; native scope requires high word zero.");
 if(id==1613496373&&!xx_rt_wcscmp(r->name,L"audio_data_bytes_high"))return xx_data_struct_record_set_comment(r,L"High32 bits of encoded audio byte count.");
 if(id==1613496373&&!xx_rt_wcscmp(r->name,L"md5"))return xx_data_struct_record_set_comment(r,L"Stored MD5; schema does not recompute or validate decoded audio.");
 if(id==1613496376&&!xx_rt_wcscmp(r->name,L"tag_bytes"))return xx_data_struct_record_set_comment(r,L"Tag byte length including footer, excluding optional32-byte header.");
 if(id==1613496377&&!xx_rt_wcscmp(r->name,L"flags"))return xx_data_struct_record_set_comment(r,L"Bit0:read-only; bits1..2:value type (UTF8,binary,external,reserved).");
 if(id==1613496379&&!xx_rt_wcscmp(r->name,L"frame_data_size"))return xx_data_struct_record_set_comment(r,L"Frame byte length after its first8 bytes.");
 if(id==1613496379&&!xx_rt_wcscmp(r->name,L"time_seconds"))return xx_data_struct_record_set_comment(r,L"IEEE754 seconds from start of stream, not a Unix timestamp.");
 if(id==1613496380&&!xx_rt_wcscmp(r->name,L"data_type"))return xx_data_struct_record_set_comment(r,L"High byte:numeric class (0 floating,1 signed,2 unsigned); low byte:element width in bytes.");
 if(id==1613496383&&!xx_rt_wcscmp(r->name,L"file_size_from_magic"))return xx_data_struct_record_set_comment(r,L"Byte length from the SC68 signature at file byte56.");
 if(id==1613496387&&!xx_rt_wcscmp(r->name,L"value"))return xx_data_struct_record_set_comment(r,L"32-bit value interpreted by the preceding SC68 chunk ID; timing/count/register units vary by tag.");
 if(id==1613496386&&!xx_rt_wcscmp(r->name,L"load_address"))return xx_data_struct_record_set_comment(r,L"68000 memory load address, not a file offset.");
 if(id==1613496388&&!xx_rt_wcscmp(r->name,L"names_offset_low16"))return xx_data_struct_record_set_comment(r,L"Low16 bits of the actual name-table byte offset; large modules wrap modulo65536.");
 if(id==1613496388&&!xx_rt_wcscmp(r->name,L"flags_and_position_count"))return xx_data_struct_record_set_comment(r,L"Low12 bits:position count; high bit:track0 omitted; other high bits encode replay-speed flags.");
 if(id==1613496391&&!xx_rt_wcscmp(r->name,L"filter_speed_and_wave_length"))return xx_data_struct_record_set_comment(r,L"Low3 bits:wave length code; high bits:filter speed.");
 if(id==1613496392&&!xx_rt_wcscmp(r->name,L"effects_and_waveform"))return xx_data_struct_record_set_comment(r,L"Packed playlist effects and waveform selector; source bit pattern preserved.");
 if(id==1613496392&&!xx_rt_wcscmp(r->name,L"note_and_fixed"))return xx_data_struct_record_set_comment(r,L"Low6 bits:note; high bits:fixed-note/effect flags.");
 if(id==1613496396&&!xx_rt_wcscmp(r->name,L"size_in_8byte_units"))return xx_data_struct_record_set_comment(r,L"Encoded sample length in8-byte units; multiply by8 for bytes.");
 if(id==1613496397&&!xx_rt_wcscmp(r->name,L"track_count_minus_one"))return xx_data_struct_record_set_comment(r,L"Number of tracks minus one.");
 if(id==1613496399&&!xx_rt_wcscmp(r->name,L"duration_frames"))return xx_data_struct_record_set_comment(r,L"Duration in50-Hz replay frames.");
 if(id==1613496399&&!xx_rt_wcscmp(r->name,L"fade_frames"))return xx_data_struct_record_set_comment(r,L"Fade duration in50-Hz replay frames.");
 if(id==1613496411&&!xx_rt_wcscmp(r->name,L"packed_sample_metadata"))return xx_data_struct_record_set_comment(r,L"Bit0:more chunks;1..4:rate code;5..6:channel code;7..33:data offset in32-byte units;34..63:sample count.");
 if(id==1613496412&&!xx_rt_wcscmp(r->name,L"more_size_type"))return xx_data_struct_record_set_comment(r,L"Bit0:more chunks;1..24:chunk payload bytes;25..31:chunk type.");
 if(id==1613496415&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the name-table beginning.");
 if(id==1613496416&&!xx_rt_wcscmp(r->name,L"levels_and_subblocks"))return xx_data_struct_record_set_comment(r,L"Low4 bits:transform levels; high12 bits:subblocks.");
 if(id==1613496417&&!xx_rt_wcscmp(r->name,L"data_offset_minus_four"))return xx_data_struct_record_set_comment(r,L"Stored relative offset; add4 to obtain encoded-data byte offset.");
 if(id==1613496420&&!xx_rt_wcscmp(r->name,L"header_512byte_blocks"))return xx_data_struct_record_set_comment(r,L"Header length in512-byte blocks, not bytes.");
 if(id==1613496420&&!xx_rt_wcscmp(r->name,L"recording_start"))return xx_data_struct_record_set_comment(r,L"Twelve ASCII digits:YYMMDDhhmmss; no time zone encoded.");
 if(id==1613496420&&!xx_rt_wcscmp(r->name,L"recording_end"))return xx_data_struct_record_set_comment(r,L"Twelve ASCII digits:YYMMDDhhmmss; no time zone encoded.");
 if(id==1613496420&&!xx_rt_wcscmp(r->name,L"duration_hhmmss"))return xx_data_struct_record_set_comment(r,L"Six ASCII digits:HHMMSS duration.");
 if(id==1613496421&&!xx_rt_wcscmp(r->name,L"block_size"))return xx_data_struct_record_set_comment(r,L"Total block byte length including8-byte prefix.");
 if(id==1613496423&&!xx_rt_wcscmp(r->name,L"chunk_size"))return xx_data_struct_record_set_comment(r,L"Total chunk bytes including8-byte prefix.");
 if(id==1613496424&&!xx_rt_wcscmp(r->name,L"block_bytes"))return xx_data_struct_record_set_comment(r,L"Encoded bytes per channel in each full block.");
 if(id==1613496424&&!xx_rt_wcscmp(r->name,L"last_block_bytes"))return xx_data_struct_record_set_comment(r,L"Encoded bytes per channel in the final block.");
 if(id==1613496424&&!xx_rt_wcscmp(r->name,L"timer"))return xx_data_struct_record_set_comment(r,L"Nintendo hardware playback timer value; not a timestamp.");
 if(id==1613496426&&!xx_rt_wcscmp(r->name,L"block_size"))return xx_data_struct_record_set_comment(r,L"Total block byte length including8-byte prefix.");
 if(id==1613496428&&!xx_rt_wcscmp(r->name,L"chunk_size"))return xx_data_struct_record_set_comment(r,L"Total chunk bytes including8-byte prefix.");
 if(id==1613496429&&!xx_rt_wcscmp(r->name,L"block_bytes"))return xx_data_struct_record_set_comment(r,L"Encoded bytes per channel in each full block.");
 if(id==1613496429&&!xx_rt_wcscmp(r->name,L"last_block_bytes"))return xx_data_struct_record_set_comment(r,L"Encoded bytes per channel in the final block.");
 if(id==1613496429&&!xx_rt_wcscmp(r->name,L"timer"))return xx_data_struct_record_set_comment(r,L"Nintendo hardware playback timer value; not a timestamp.");
 if(id==1613496432&&!xx_rt_wcscmp(r->name,L"header_bytes_after_prefix"))return xx_data_struct_record_set_comment(r,L"Header bytes following the first8 bytes;8 means implicit22050Hz,12 includes sample-rate word.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"track_relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte displacement relative to MDH signature at file byte0x38.");
 if(id==1613496323&&!xx_rt_wcscmp(r->name,L"entry_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496325&&!xx_rt_wcscmp(r->name,L"entry_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496327&&!xx_rt_wcscmp(r->name,L"segment_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496329&&!xx_rt_wcscmp(r->name,L"loop_start_samples"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"unknown_17"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"unknown_20"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"simple_cues_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"complex_cues_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"cue_names_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"unknown_offset"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"variation_tables_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"transition_tables_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"wave_bank_names_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"cue_name_hash_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"cue_name_index_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496331&&!xx_rt_wcscmp(r->name,L"sounds_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496332&&!xx_rt_wcscmp(r->name,L"sound_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496334&&!xx_rt_wcscmp(r->name,L"bits_per_sample"))return xx_data_struct_record_set_comment(r,L"Bits per decoded sample per channel.");
 if(id==1613496334&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496334&&!xx_rt_wcscmp(r->name,L"loop_start_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496334&&!xx_rt_wcscmp(r->name,L"loop_end_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496334&&!xx_rt_wcscmp(r->name,L"unknown_tail"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496337&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496349&&!xx_rt_wcscmp(r->name,L"samples_per_second"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496361&&!xx_rt_wcscmp(r->name,L"frequency"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496374&&!xx_rt_wcscmp(r->name,L"bits_per_sample"))return xx_data_struct_record_set_comment(r,L"Bits per decoded sample per channel.");
 if(id==1613496374&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496375&&!xx_rt_wcscmp(r->name,L"frame_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496382&&!xx_rt_wcscmp(r->name,L"start_address"))return xx_data_struct_record_set_comment(r,L"Target machine memory address, not a file offset.");
 if(id==1613496382&&!xx_rt_wcscmp(r->name,L"end_address_inclusive"))return xx_data_struct_record_set_comment(r,L"Target machine memory address, not a file offset.");
 if(id==1613496391&&!xx_rt_wcscmp(r->name,L"unknown_a"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496397&&!xx_rt_wcscmp(r->name,L"custom_player_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496397&&!xx_rt_wcscmp(r->name,L"author_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496397&&!xx_rt_wcscmp(r->name,L"comment_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496397&&!xx_rt_wcscmp(r->name,L"track_table_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496398&&!xx_rt_wcscmp(r->name,L"name_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496398&&!xx_rt_wcscmp(r->name,L"descriptor_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496399&&!xx_rt_wcscmp(r->name,L"cpu_state_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496399&&!xx_rt_wcscmp(r->name,L"block_index_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496400&&!xx_rt_wcscmp(r->name,L"stack_pointer"))return xx_data_struct_record_set_comment(r,L"Target machine memory address, not a file offset.");
 if(id==1613496400&&!xx_rt_wcscmp(r->name,L"init_address"))return xx_data_struct_record_set_comment(r,L"Target machine memory address, not a file offset.");
 if(id==1613496400&&!xx_rt_wcscmp(r->name,L"interrupt_address"))return xx_data_struct_record_set_comment(r,L"Target machine memory address, not a file offset.");
 if(id==1613496401&&!xx_rt_wcscmp(r->name,L"load_address"))return xx_data_struct_record_set_comment(r,L"Target machine memory address, not a file offset.");
 if(id==1613496401&&!xx_rt_wcscmp(r->name,L"payload_relative"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this pointer word.");
 if(id==1613496404&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496404&&!xx_rt_wcscmp(r->name,L"opaque_2c"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496404&&!xx_rt_wcscmp(r->name,L"loop_start_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496404&&!xx_rt_wcscmp(r->name,L"loop_end_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496408&&!xx_rt_wcscmp(r->name,L"loop_start_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496408&&!xx_rt_wcscmp(r->name,L"loop_end_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496408&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496414&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496416&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496417&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496417&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496420&&!xx_rt_wcscmp(r->name,L"opaque_metadata"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496424&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496424&&!xx_rt_wcscmp(r->name,L"loop_start_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496424&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496425&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496429&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496429&&!xx_rt_wcscmp(r->name,L"loop_start_sample"))return xx_data_struct_record_set_comment(r,L"Decoded sample index, not a byte offset.");
 if(id==1613496429&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496430&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496431&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496431&&!xx_rt_wcscmp(r->name,L"unknown_c"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496431&&!xx_rt_wcscmp(r->name,L"unknown_14"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496431&&!xx_rt_wcscmp(r->name,L"unknown_1c"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496432&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496433&&!xx_rt_wcscmp(r->name,L"sample_rate"))return xx_data_struct_record_set_comment(r,L"Frequency in Hz.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"instrument_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset0"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset1"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset2"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset3"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset4"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset5"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset6"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"sample_offset7"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to this file or bank beginning.");
 if(id==1613496434&&!xx_rt_wcscmp(r->name,L"unknown_3c"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 if(id==1613496435&&!xx_rt_wcscmp(r->name,L"unknown"))return xx_data_struct_record_set_comment(r,L"Uninterpreted physical header bytes; no guessed member semantics.");
 return true;
}
