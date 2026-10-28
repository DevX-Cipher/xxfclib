/* SPDX-License-Identifier: MIT
 * Bounded physical music project records; decoded payloads remain raw. */
static const xx_data_struct_field_desc sxmp_famistudio_file_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("format_version","int32",4,4,SX_NONE),
 SX_FIELD("uncompressed_size","int32",8,4,SX_SIZE),
};
static const sx_layout sxmp_famistudio_file_header={0x607b0001U,"famistudio_file_header",sxmp_famistudio_file_header_fields,SX_COUNT(sxmp_famistudio_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_file_header_fields[]={
 SX_FIELD("signature","char[18]",0,18,SX_SIGNATURE),
 SX_FIELD("format_version","uint32",18,4,SX_NONE),
};
static const sx_layout sxmp_famitracker_file_header={0x607b0002U,"famitracker_file_header",sxmp_famitracker_file_header_fields,SX_COUNT(sxmp_famitracker_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_block_header_fields[]={
 SX_FIELD("block_id","char[16]",0,16,SX_ID),
 SX_FIELD("block_version","int32",16,4,SX_NONE),
 SX_FIELD("block_size","int32",20,4,SX_SIZE),
};
static const sx_layout sxmp_famitracker_block_header={0x607b0003U,"famitracker_block_header",sxmp_famitracker_block_header_fields,SX_COUNT(sxmp_famitracker_block_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_end_fields[]={
 SX_FIELD("end_marker","char[3]",0,3,SX_SIGNATURE),
};
static const sx_layout sxmp_famitracker_end={0x607b0004U,"famitracker_end",sxmp_famitracker_end_fields,SX_COUNT(sxmp_famitracker_end_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_info_fields[]={
 SX_FIELD("song_name","char[32]",0,32,SX_STRING),
 SX_FIELD("artist","char[32]",32,32,SX_STRING),
 SX_FIELD("copyright","char[32]",64,32,SX_STRING),
};
static const sx_layout sxmp_famitracker_info={0x607b0005U,"famitracker_info",sxmp_famitracker_info_fields,SX_COUNT(sxmp_famitracker_info_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v1_fields[]={
 SX_FIELD("initial_speed","int32",0,4,SX_NONE),
 SX_FIELD("channel_count","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",8,4,SX_ID),
 SX_FIELD("engine_speed","int32",12,4,SX_NONE),
};
static const sx_layout sxmp_famitracker_parameters_v1={0x607b0006U,"famitracker_parameters_v1",sxmp_famitracker_parameters_v1_fields,SX_COUNT(sxmp_famitracker_parameters_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v2_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("engine_speed","int32",9,4,SX_NONE),
};
static const sx_layout sxmp_famitracker_parameters_v2={0x607b0007U,"famitracker_parameters_v2",sxmp_famitracker_parameters_v2_fields,SX_COUNT(sxmp_famitracker_parameters_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v3_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("engine_speed","int32",9,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",13,4,SX_ID),
};
static const sx_layout sxmp_famitracker_parameters_v3={0x607b0008U,"famitracker_parameters_v3",sxmp_famitracker_parameters_v3_fields,SX_COUNT(sxmp_famitracker_parameters_v3_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v4_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("engine_speed","int32",9,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",13,4,SX_ID),
 SX_FIELD("first_highlight","int32",17,4,SX_NONE),
 SX_FIELD("second_highlight","int32",21,4,SX_NONE),
};
static const sx_layout sxmp_famitracker_parameters_v4={0x607b0009U,"famitracker_parameters_v4",sxmp_famitracker_parameters_v4_fields,SX_COUNT(sxmp_famitracker_parameters_v4_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v5_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("engine_speed","int32",9,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",13,4,SX_ID),
 SX_FIELD("first_highlight","int32",17,4,SX_NONE),
 SX_FIELD("second_highlight","int32",21,4,SX_NONE),
};
static const sx_layout sxmp_famitracker_parameters_v5={0x607b000aU,"famitracker_parameters_v5",sxmp_famitracker_parameters_v5_fields,SX_COUNT(sxmp_famitracker_parameters_v5_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v5_n163_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("engine_speed","int32",9,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",13,4,SX_ID),
 SX_FIELD("first_highlight","int32",17,4,SX_NONE),
 SX_FIELD("second_highlight","int32",21,4,SX_NONE),
 SX_FIELD("namco_channel_count","int32",25,4,SX_COUNT_PROP),
};
static const sx_layout sxmp_famitracker_parameters_v5_n163={0x607b000bU,"famitracker_parameters_v5_n163",sxmp_famitracker_parameters_v5_n163_fields,SX_COUNT(sxmp_famitracker_parameters_v5_n163_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v6_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("engine_speed","int32",9,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",13,4,SX_ID),
 SX_FIELD("first_highlight","int32",17,4,SX_NONE),
 SX_FIELD("second_highlight","int32",21,4,SX_NONE),
 SX_FIELD("speed_split_point","int32",25,4,SX_NONE),
};
static const sx_layout sxmp_famitracker_parameters_v6={0x607b000cU,"famitracker_parameters_v6",sxmp_famitracker_parameters_v6_fields,SX_COUNT(sxmp_famitracker_parameters_v6_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v6_n163_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("engine_speed","int32",9,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",13,4,SX_ID),
 SX_FIELD("first_highlight","int32",17,4,SX_NONE),
 SX_FIELD("second_highlight","int32",21,4,SX_NONE),
 SX_FIELD("namco_channel_count","int32",25,4,SX_COUNT_PROP),
 SX_FIELD("speed_split_point","int32",29,4,SX_NONE),
};
static const sx_layout sxmp_famitracker_parameters_v6_n163={0x607b000dU,"famitracker_parameters_v6_n163",sxmp_famitracker_parameters_v6_n163_fields,SX_COUNT(sxmp_famitracker_parameters_v6_n163_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v7_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("playback_rate_type","int32",9,4,SX_ID),
 SX_FIELD("playback_rate","int32",13,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",17,4,SX_ID),
 SX_FIELD("speed_split_point","int32",21,4,SX_NONE),
};
static const sx_layout sxmp_famitracker_parameters_v7={0x607b000eU,"famitracker_parameters_v7",sxmp_famitracker_parameters_v7_fields,SX_COUNT(sxmp_famitracker_parameters_v7_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v7_n163_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("playback_rate_type","int32",9,4,SX_ID),
 SX_FIELD("playback_rate","int32",13,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",17,4,SX_ID),
 SX_FIELD("namco_channel_count","int32",21,4,SX_COUNT_PROP),
 SX_FIELD("speed_split_point","int32",25,4,SX_NONE),
};
static const sx_layout sxmp_famitracker_parameters_v7_n163={0x607b000fU,"famitracker_parameters_v7_n163",sxmp_famitracker_parameters_v7_n163_fields,SX_COUNT(sxmp_famitracker_parameters_v7_n163_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v8_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("playback_rate_type","int32",9,4,SX_ID),
 SX_FIELD("playback_rate","int32",13,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",17,4,SX_ID),
 SX_FIELD("speed_split_point","int32",21,4,SX_NONE),
 SX_FIELD("detune_semitone","int8",25,1,SX_NONE),
 SX_FIELD("detune_cent","int8",26,1,SX_NONE),
};
static const sx_layout sxmp_famitracker_parameters_v8={0x607b0010U,"famitracker_parameters_v8",sxmp_famitracker_parameters_v8_fields,SX_COUNT(sxmp_famitracker_parameters_v8_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v8_n163_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("playback_rate_type","int32",9,4,SX_ID),
 SX_FIELD("playback_rate","int32",13,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",17,4,SX_ID),
 SX_FIELD("namco_channel_count","int32",21,4,SX_COUNT_PROP),
 SX_FIELD("speed_split_point","int32",25,4,SX_NONE),
 SX_FIELD("detune_semitone","int8",29,1,SX_NONE),
 SX_FIELD("detune_cent","int8",30,1,SX_NONE),
};
static const sx_layout sxmp_famitracker_parameters_v8_n163={0x607b0011U,"famitracker_parameters_v8_n163",sxmp_famitracker_parameters_v8_n163_fields,SX_COUNT(sxmp_famitracker_parameters_v8_n163_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v9_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("playback_rate_type","int32",9,4,SX_ID),
 SX_FIELD("playback_rate","int32",13,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",17,4,SX_ID),
 SX_FIELD("hardware_sweep_reset","int32",21,4,SX_FLAGS),
 SX_FIELD("speed_split_point","int32",25,4,SX_NONE),
};
static const sx_layout sxmp_famitracker_parameters_v9={0x607b0012U,"famitracker_parameters_v9",sxmp_famitracker_parameters_v9_fields,SX_COUNT(sxmp_famitracker_parameters_v9_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_parameters_v9_n163_fields[]={
 SX_FIELD("expansion_chips","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_count","int32",1,4,SX_COUNT_PROP),
 SX_FIELD("machine","int32",5,4,SX_ID),
 SX_FIELD("playback_rate_type","int32",9,4,SX_ID),
 SX_FIELD("playback_rate","int32",13,4,SX_NONE),
 SX_FIELD("vibrato_style","int32",17,4,SX_ID),
 SX_FIELD("hardware_sweep_reset","int32",21,4,SX_FLAGS),
 SX_FIELD("namco_channel_count","int32",25,4,SX_COUNT_PROP),
 SX_FIELD("speed_split_point","int32",29,4,SX_NONE),
};
static const sx_layout sxmp_famitracker_parameters_v9_n163={0x607b0013U,"famitracker_parameters_v9_n163",sxmp_famitracker_parameters_v9_n163_fields,SX_COUNT(sxmp_famitracker_parameters_v9_n163_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_track_count_fields[]={
 SX_FIELD("tracks_minus_one","uint8",0,1,SX_NONE),
};
static const sx_layout sxmp_famitracker_track_count={0x607b0014U,"famitracker_track_count",sxmp_famitracker_track_count_fields,SX_COUNT(sxmp_famitracker_track_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_channel_type_fields[]={
 SX_FIELD("channel_type","uint8",0,1,SX_ID),
};
static const sx_layout sxmp_famitracker_channel_type={0x607b0015U,"famitracker_channel_type",sxmp_famitracker_channel_type_fields,SX_COUNT(sxmp_famitracker_channel_type_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_famitracker_effect_columns_fields[]={
 SX_FIELD("effect_columns_minus_one","uint8",0,1,SX_NONE),
};
static const sx_layout sxmp_famitracker_effect_columns={0x607b0016U,"famitracker_effect_columns",sxmp_famitracker_effect_columns_fields,SX_COUNT(sxmp_famitracker_effect_columns_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_music_project_text_fields[]={
 SX_FIELD("text","utf8",0,0,SX_STRING),
};
static const sx_layout sxmp_music_project_text={0x607b0017U,"music_project_text",sxmp_music_project_text_fields,SX_COUNT(sxmp_music_project_text_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_music_project_name_fields[]={
 SX_FIELD("name","utf8",0,0,SX_STRING),
};
static const sx_layout sxmp_music_project_name={0x607b0018U,"music_project_name",sxmp_music_project_name_fields,SX_COUNT(sxmp_music_project_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_music_project_author_fields[]={
 SX_FIELD("author","utf8",0,0,SX_STRING),
};
static const sx_layout sxmp_music_project_author={0x607b0019U,"music_project_author",sxmp_music_project_author_fields,SX_COUNT(sxmp_music_project_author_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_music_project_string_terminator_fields[]={
 SX_FIELD("nul_terminator","uint8",0,1,SX_ID),
};
static const sx_layout sxmp_music_project_string_terminator={0x607b001aU,"music_project_string_terminator",sxmp_music_project_string_terminator_fields,SX_COUNT(sxmp_music_project_string_terminator_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_renoise_legacy_text_fields[]={
 SX_FIELD("text","char",0,0,SX_STRING),
};
static const sx_layout sxmp_renoise_legacy_text={0x607b001bU,"renoise_legacy_text",sxmp_renoise_legacy_text_fields,SX_COUNT(sxmp_renoise_legacy_text_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_music_project_xml_element_fields[]={
 SX_FIELD("element_name","utf8",0,0,SX_STRING),
};
static const sx_layout sxmp_music_project_xml_element={0x607b001cU,"music_project_xml_element",sxmp_music_project_xml_element_fields,SX_COUNT(sxmp_music_project_xml_element_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_music_project_xml_attribute_fields[]={
 SX_FIELD("attribute_name","utf8",0,0,SX_STRING),
};
static const sx_layout sxmp_music_project_xml_attribute={0x607b001dU,"music_project_xml_attribute",sxmp_music_project_xml_attribute_fields,SX_COUNT(sxmp_music_project_xml_attribute_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_music_project_xml_value_fields[]={
 SX_FIELD("attribute_value","utf8",0,0,SX_STRING),
};
static const sx_layout sxmp_music_project_xml_value={0x607b001eU,"music_project_xml_value",sxmp_music_project_xml_value_fields,SX_COUNT(sxmp_music_project_xml_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_music_project_xml_version_fields[]={
 SX_FIELD("document_version","ascii_decimal",0,0,SX_NONE),
};
static const sx_layout sxmp_music_project_xml_version={0x607b001fU,"music_project_xml_version",sxmp_music_project_xml_version_fields,SX_COUNT(sxmp_music_project_xml_version_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_module_header_fields[]={
 SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("format_version","uint16",16,2,SX_NONE),
 SX_FIELD("reserved","uint16",18,2,SX_RESERVED),
 SX_FIELD("song_info_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("reserved_tail","uint8[8]",24,8,SX_RESERVED),
};
static const sx_layout sxmp_furnace_module_header={0x607b0020U,"furnace_module_header",sxmp_furnace_module_header_fields,SX_COUNT(sxmp_furnace_module_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_instrument_header_fields[]={
 SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("format_version","uint16",16,2,SX_NONE),
 SX_FIELD("reserved","uint16",18,2,SX_RESERVED),
 SX_FIELD("instrument_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("wavetable_count","uint16",24,2,SX_COUNT_PROP),
 SX_FIELD("sample_count","uint16",26,2,SX_COUNT_PROP),
 SX_FIELD("reserved_tail","uint32",28,4,SX_RESERVED),
};
static const sx_layout sxmp_furnace_instrument_header={0x607b0021U,"furnace_instrument_header",sxmp_furnace_instrument_header_fields,SX_COUNT(sxmp_furnace_instrument_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_wavetable_header_fields[]={
 SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("format_version","uint16",16,2,SX_NONE),
 SX_FIELD("reserved","uint16",18,2,SX_RESERVED),
};
static const sx_layout sxmp_furnace_wavetable_header={0x607b0022U,"furnace_wavetable_header",sxmp_furnace_wavetable_header_fields,SX_COUNT(sxmp_furnace_wavetable_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_block_header_fields[]={
 SX_FIELD("block_id","char[4]",0,4,SX_ID),
 SX_FIELD("block_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxmp_furnace_block_header={0x607b0023U,"furnace_block_header",sxmp_furnace_block_header_fields,SX_COUNT(sxmp_furnace_block_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_file_pointer_fields[]={
 SX_FIELD("file_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxmp_furnace_file_pointer={0x607b0024U,"furnace_file_pointer",sxmp_furnace_file_pointer_fields,SX_COUNT(sxmp_furnace_file_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_wave_dimensions_fields[]={
 SX_FIELD("width","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("minimum_value","int32",4,4,SX_NONE),
 SX_FIELD("maximum_value","int32",8,4,SX_NONE),
};
static const sx_layout sxmp_furnace_wave_dimensions={0x607b0025U,"furnace_wave_dimensions",sxmp_furnace_wave_dimensions_fields,SX_COUNT(sxmp_furnace_wave_dimensions_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_wave_value_fields[]={
 SX_FIELD("amplitude","int32",0,4,SX_NONE),
};
static const sx_layout sxmp_furnace_wave_value={0x607b0026U,"furnace_wave_value",sxmp_furnace_wave_value_fields,SX_COUNT(sxmp_furnace_wave_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_instrument_prefix_fields[]={
 SX_FIELD("format_version","uint16",0,2,SX_NONE),
 SX_FIELD("instrument_type","uint8",2,1,SX_ID),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
};
static const sx_layout sxmp_furnace_instrument_prefix={0x607b0027U,"furnace_instrument_prefix",sxmp_furnace_instrument_prefix_fields,SX_COUNT(sxmp_furnace_instrument_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_info_prefix_fields[]={
 SX_FIELD("time_base","uint8",0,1,SX_NONE),
 SX_FIELD("speed_one","uint8",1,1,SX_NONE),
 SX_FIELD("speed_two","uint8",2,1,SX_NONE),
 SX_FIELD("initial_arpeggio_time","uint8",3,1,SX_NONE),
 SX_FIELD("ticks_per_second","float",4,4,SX_NONE),
 SX_FIELD("pattern_length","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("orders_length","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("highlight_a","uint8",12,1,SX_NONE),
 SX_FIELD("highlight_b","uint8",13,1,SX_NONE),
 SX_FIELD("instrument_count","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("wavetable_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("sample_count","uint16",18,2,SX_COUNT_PROP),
 SX_FIELD("pattern_count","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxmp_furnace_info_prefix={0x607b0028U,"furnace_info_prefix",sxmp_furnace_info_prefix_fields,SX_COUNT(sxmp_furnace_info_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_chip_id_fields[]={
 SX_FIELD("chip_id","uint8",0,1,SX_ID),
};
static const sx_layout sxmp_furnace_chip_id={0x607b0029U,"furnace_chip_id",sxmp_furnace_chip_id_fields,SX_COUNT(sxmp_furnace_chip_id_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_chip_volume_fields[]={
 SX_FIELD("volume_64","int8",0,1,SX_NONE),
};
static const sx_layout sxmp_furnace_chip_volume={0x607b002aU,"furnace_chip_volume",sxmp_furnace_chip_volume_fields,SX_COUNT(sxmp_furnace_chip_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_chip_pan_fields[]={
 SX_FIELD("panning","int8",0,1,SX_NONE),
};
static const sx_layout sxmp_furnace_chip_pan={0x607b002bU,"furnace_chip_pan",sxmp_furnace_chip_pan_fields,SX_COUNT(sxmp_furnace_chip_pan_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_chip_flags_fields[]={
 SX_FIELD("chip_flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxmp_furnace_chip_flags={0x607b002cU,"furnace_chip_flags",sxmp_furnace_chip_flags_fields,SX_COUNT(sxmp_furnace_chip_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_tuning_fields[]={
 SX_FIELD("a4_tuning_hz","float",0,4,SX_NONE),
};
static const sx_layout sxmp_furnace_tuning={0x607b002dU,"furnace_tuning",sxmp_furnace_tuning_fields,SX_COUNT(sxmp_furnace_tuning_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_inf2_tuning_fields[]={
 SX_FIELD("a4_tuning_hz","float",0,4,SX_NONE),
 SX_FIELD("automatic_system_name","uint8",4,1,SX_FLAGS),
 SX_FIELD("master_volume","float",5,4,SX_NONE),
 SX_FIELD("channel_count","uint16",9,2,SX_COUNT_PROP),
 SX_FIELD("chip_count","uint16",11,2,SX_COUNT_PROP),
};
static const sx_layout sxmp_furnace_inf2_tuning={0x607b002eU,"furnace_inf2_tuning",sxmp_furnace_inf2_tuning_fields,SX_COUNT(sxmp_furnace_inf2_tuning_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_inf2_chip_fields[]={
 SX_FIELD("chip_id","uint16",0,2,SX_ID),
 SX_FIELD("channel_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("volume","float",4,4,SX_NONE),
 SX_FIELD("panning","float",8,4,SX_NONE),
 SX_FIELD("front_rear_balance","float",12,4,SX_NONE),
};
static const sx_layout sxmp_furnace_inf2_chip={0x607b002fU,"furnace_inf2_chip",sxmp_furnace_inf2_chip_fields,SX_COUNT(sxmp_furnace_inf2_chip_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_patchbay_count_fields[]={
 SX_FIELD("connection_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmp_furnace_patchbay_count={0x607b0030U,"furnace_patchbay_count",sxmp_furnace_patchbay_count_fields,SX_COUNT(sxmp_furnace_patchbay_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_patchbay_connection_fields[]={
 SX_FIELD("connection","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxmp_furnace_patchbay_connection={0x607b0031U,"furnace_patchbay_connection",sxmp_furnace_patchbay_connection_fields,SX_COUNT(sxmp_furnace_patchbay_connection_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_patchbay_auto_fields[]={
 SX_FIELD("automatic_patchbay","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxmp_furnace_patchbay_auto={0x607b0032U,"furnace_patchbay_auto",sxmp_furnace_patchbay_auto_fields,SX_COUNT(sxmp_furnace_patchbay_auto_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_element_fields[]={
 SX_FIELD("element_type","uint8",0,1,SX_ID),
 SX_FIELD("element_count","uint32",1,4,SX_COUNT_PROP),
};
static const sx_layout sxmp_furnace_element={0x607b0033U,"furnace_element",sxmp_furnace_element_fields,SX_COUNT(sxmp_furnace_element_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_element_end_fields[]={
 SX_FIELD("end_marker","uint8",0,1,SX_ID),
};
static const sx_layout sxmp_furnace_element_end={0x607b0034U,"furnace_element_end",sxmp_furnace_element_end_fields,SX_COUNT(sxmp_furnace_element_end_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_header_fields[]={
 SX_FIELD("signature","char[7]",0,7,SX_SIGNATURE),
 SX_FIELD("version","char[5]",7,5,SX_STRING),
};
static const sx_layout sxmp_beepola_header={0x607b0035U,"beepola_header",sxmp_beepola_header_fields,SX_COUNT(sxmp_beepola_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_section_fields[]={
 SX_FIELD("section_name","utf8",0,0,SX_STRING),
};
static const sx_layout sxmp_beepola_section={0x607b0036U,"beepola_section",sxmp_beepola_section_fields,SX_COUNT(sxmp_beepola_section_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_property_fields[]={
 SX_FIELD("property_name","utf8",0,0,SX_STRING),
};
static const sx_layout sxmp_beepola_property={0x607b0037U,"beepola_property",sxmp_beepola_property_fields,SX_COUNT(sxmp_beepola_property_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_property_value_fields[]={
 SX_FIELD("property_value","utf8",0,0,SX_STRING),
};
static const sx_layout sxmp_beepola_property_value={0x607b0038U,"beepola_property_value",sxmp_beepola_property_value_fields,SX_COUNT(sxmp_beepola_property_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_count_fields[]={
 SX_FIELD("count","ascii_decimal",0,0,SX_COUNT_PROP),
};
static const sx_layout sxmp_beepola_count={0x607b0039U,"beepola_count",sxmp_beepola_count_fields,SX_COUNT(sxmp_beepola_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_loop_index_fields[]={
 SX_FIELD("loop_start","ascii_decimal",0,0,SX_NONE),
};
static const sx_layout sxmp_beepola_loop_index={0x607b003aU,"beepola_loop_index",sxmp_beepola_loop_index_fields,SX_COUNT(sxmp_beepola_loop_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_order_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
};
static const sx_layout sxmp_beepola_order={0x607b003bU,"beepola_order",sxmp_beepola_order_fields,SX_COUNT(sxmp_beepola_order_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_pattern_header_fields[]={
 SX_FIELD("row_count","int32",0,4,SX_COUNT_PROP),
 SX_FIELD("tempo","int32",4,4,SX_NONE),
};
static const sx_layout sxmp_beepola_pattern_header={0x607b003cU,"beepola_pattern_header",sxmp_beepola_pattern_header_fields,SX_COUNT(sxmp_beepola_pattern_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_phaser_instrument_fields[]={
 SX_FIELD("multiple","uint8",0,1,SX_NONE),
 SX_FIELD("detune","int32",1,4,SX_NONE),
 SX_FIELD("phase","uint8",5,1,SX_NONE),
};
static const sx_layout sxmp_beepola_phaser_instrument={0x607b003dU,"beepola_phaser_instrument",sxmp_beepola_phaser_instrument_fields,SX_COUNT(sxmp_beepola_phaser_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_renoise_legacy_header_fields[]={
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version_text","char[4]",3,4,SX_STRING),
};
static const sx_layout sxmp_renoise_legacy_header={0x607b003eU,"renoise_legacy_header",sxmp_renoise_legacy_header_fields,SX_COUNT(sxmp_renoise_legacy_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_renoise_legacy_chunk_header_fields[]={
 SX_FIELD("start_marker","char[20]",0,20,SX_SIGNATURE),
 SX_FIELD("chunk_type","char[20]",20,20,SX_ID),
};
static const sx_layout sxmp_renoise_legacy_chunk_header={0x607b003fU,"renoise_legacy_chunk_header",sxmp_renoise_legacy_chunk_header_fields,SX_COUNT(sxmp_renoise_legacy_chunk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_renoise_legacy_info_v0_fields[]={
 SX_FIELD("song_name","char[20]",0,20,SX_STRING),
 SX_FIELD("author","char[20]",20,20,SX_STRING),
 SX_FIELD("style","char[20]",40,20,SX_STRING),
};
static const sx_layout sxmp_renoise_legacy_info_v0={0x607b0040U,"renoise_legacy_info_v0",sxmp_renoise_legacy_info_v0_fields,SX_COUNT(sxmp_renoise_legacy_info_v0_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_renoise_legacy_string_length_fields[]={
 SX_FIELD("text_length","uint32",0,4,SX_SIZE),
};
static const sx_layout sxmp_renoise_legacy_string_length={0x607b0041U,"renoise_legacy_string_length",sxmp_renoise_legacy_string_length_fields,SX_COUNT(sxmp_renoise_legacy_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_row_count_fields[]={
 SX_FIELD("row_count","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmp_beepola_row_count={0x607b0042U,"beepola_row_count",sxmp_beepola_row_count_fields,SX_COUNT(sxmp_beepola_row_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_one_note_fields[]={
 SX_FIELD("channel_one_note","uint8",0,1,SX_NONE),
};
static const sx_layout sxmp_beepola_channel_one_note={0x607b0043U,"beepola_channel_one_note",sxmp_beepola_channel_one_note_fields,SX_COUNT(sxmp_beepola_channel_one_note_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_two_note_fields[]={
 SX_FIELD("channel_two_note","uint8",0,1,SX_NONE),
};
static const sx_layout sxmp_beepola_channel_two_note={0x607b0044U,"beepola_channel_two_note",sxmp_beepola_channel_two_note_fields,SX_COUNT(sxmp_beepola_channel_two_note_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_drum_fields[]={
 SX_FIELD("drum","uint8",0,1,SX_NONE),
};
static const sx_layout sxmp_beepola_drum={0x607b0045U,"beepola_drum",sxmp_beepola_drum_fields,SX_COUNT(sxmp_beepola_drum_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_one_sustain_fields[]={
 SX_FIELD("channel_one_sustain","uint8",0,1,SX_NONE),
};
static const sx_layout sxmp_beepola_channel_one_sustain={0x607b0046U,"beepola_channel_one_sustain",sxmp_beepola_channel_one_sustain_fields,SX_COUNT(sxmp_beepola_channel_one_sustain_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_two_sustain_fields[]={
 SX_FIELD("channel_two_sustain","uint8",0,1,SX_NONE),
};
static const sx_layout sxmp_beepola_channel_two_sustain={0x607b0047U,"beepola_channel_two_sustain",sxmp_beepola_channel_two_sustain_fields,SX_COUNT(sxmp_beepola_channel_two_sustain_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_one_warp_fields[]={
 SX_FIELD("channel_one_warp","uint8",0,1,SX_NONE),
};
static const sx_layout sxmp_beepola_channel_one_warp={0x607b0048U,"beepola_channel_one_warp",sxmp_beepola_channel_one_warp_fields,SX_COUNT(sxmp_beepola_channel_one_warp_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_two_warp_fields[]={
 SX_FIELD("channel_two_warp","uint8",0,1,SX_NONE),
};
static const sx_layout sxmp_beepola_channel_two_warp={0x607b0049U,"beepola_channel_two_warp",sxmp_beepola_channel_two_warp_fields,SX_COUNT(sxmp_beepola_channel_two_warp_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_ornament_value_fields[]={
 SX_FIELD("ornament_value","uint8",0,1,SX_NONE),
};
static const sx_layout sxmp_beepola_ornament_value={0x607b004aU,"beepola_ornament_value",sxmp_beepola_ornament_value_fields,SX_COUNT(sxmp_beepola_ornament_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_one_glissando_fields[]={
 SX_FIELD("channel_one_glissando","uint16",0,2,SX_NONE),
};
static const sx_layout sxmp_beepola_channel_one_glissando={0x607b004bU,"beepola_channel_one_glissando",sxmp_beepola_channel_one_glissando_fields,SX_COUNT(sxmp_beepola_channel_one_glissando_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_two_glissando_fields[]={
 SX_FIELD("channel_two_glissando","uint16",0,2,SX_NONE),
};
static const sx_layout sxmp_beepola_channel_two_glissando={0x607b004cU,"beepola_channel_two_glissando",sxmp_beepola_channel_two_glissando_fields,SX_COUNT(sxmp_beepola_channel_two_glissando_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_one_skew_fields[]={
 SX_FIELD("channel_one_skew","uint16",0,2,SX_NONE),
};
static const sx_layout sxmp_beepola_channel_one_skew={0x607b004dU,"beepola_channel_one_skew",sxmp_beepola_channel_one_skew_fields,SX_COUNT(sxmp_beepola_channel_one_skew_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_two_skew_fields[]={
 SX_FIELD("channel_two_skew","uint16",0,2,SX_NONE),
};
static const sx_layout sxmp_beepola_channel_two_skew={0x607b004eU,"beepola_channel_two_skew",sxmp_beepola_channel_two_skew_fields,SX_COUNT(sxmp_beepola_channel_two_skew_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_one_skew_xor_fields[]={
 SX_FIELD("channel_one_skew_xor","uint16",0,2,SX_NONE),
};
static const sx_layout sxmp_beepola_channel_one_skew_xor={0x607b004fU,"beepola_channel_one_skew_xor",sxmp_beepola_channel_one_skew_xor_fields,SX_COUNT(sxmp_beepola_channel_one_skew_xor_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_two_skew_xor_fields[]={
 SX_FIELD("channel_two_skew_xor","uint16",0,2,SX_NONE),
};
static const sx_layout sxmp_beepola_channel_two_skew_xor={0x607b0050U,"beepola_channel_two_skew_xor",sxmp_beepola_channel_two_skew_xor_fields,SX_COUNT(sxmp_beepola_channel_two_skew_xor_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_one_arpeggio_fields[]={
 SX_FIELD("channel_one_arpeggio","uint16",0,2,SX_NONE),
};
static const sx_layout sxmp_beepola_channel_one_arpeggio={0x607b0051U,"beepola_channel_one_arpeggio",sxmp_beepola_channel_one_arpeggio_fields,SX_COUNT(sxmp_beepola_channel_one_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_channel_two_arpeggio_fields[]={
 SX_FIELD("channel_two_arpeggio","uint16",0,2,SX_NONE),
};
static const sx_layout sxmp_beepola_channel_two_arpeggio={0x607b0052U,"beepola_channel_two_arpeggio",sxmp_beepola_channel_two_arpeggio_fields,SX_COUNT(sxmp_beepola_channel_two_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_beepola_ornament_length_fields[]={
 SX_FIELD("length","int32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxmp_beepola_ornament_length={0x607b0053U,"beepola_ornament_length",sxmp_beepola_ornament_length_fields,SX_COUNT(sxmp_beepola_ornament_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_compatibility_prefix_fields[]={
 SX_FIELD("limit_slides","uint8",0,1,SX_FLAGS),
 SX_FIELD("linear_pitch","uint8",1,1,SX_FLAGS),
 SX_FIELD("loop_modality","uint8",2,1,SX_FLAGS),
 SX_FIELD("proper_noise_layout","uint8",3,1,SX_FLAGS),
 SX_FIELD("wave_duty_is_volume","uint8",4,1,SX_FLAGS),
 SX_FIELD("reset_macro_on_portamento","uint8",5,1,SX_FLAGS),
 SX_FIELD("legacy_volume_slides","uint8",6,1,SX_FLAGS),
 SX_FIELD("compatible_arpeggio","uint8",7,1,SX_FLAGS),
 SX_FIELD("note_off_resets_slides","uint8",8,1,SX_FLAGS),
 SX_FIELD("target_resets_slides","uint8",9,1,SX_FLAGS),
 SX_FIELD("arpeggio_inhibits_portamento","uint8",10,1,SX_FLAGS),
 SX_FIELD("wack_algorithm_macro","uint8",11,1,SX_FLAGS),
 SX_FIELD("broken_shortcut_slides","uint8",12,1,SX_FLAGS),
 SX_FIELD("ignore_duplicate_slides","uint8",13,1,SX_FLAGS),
 SX_FIELD("stop_portamento_on_note_off","uint8",14,1,SX_FLAGS),
 SX_FIELD("continuous_vibrato","uint8",15,1,SX_FLAGS),
 SX_FIELD("broken_dac_mode","uint8",16,1,SX_FLAGS),
 SX_FIELD("one_tick_cut","uint8",17,1,SX_FLAGS),
 SX_FIELD("instrument_change_during_portamento","uint8",18,1,SX_FLAGS),
 SX_FIELD("reset_note_base_on_arpeggio_stop","uint8",19,1,SX_FLAGS),
};
static const sx_layout sxmp_furnace_compatibility_prefix={0x607b0054U,"furnace_compatibility_prefix",sxmp_furnace_compatibility_prefix_fields,SX_COUNT(sxmp_furnace_compatibility_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_compatibility_reserved_fields[]={
 SX_FIELD("legacy_compatibility_bytes","uint8[20]",0,20,SX_NONE),
};
static const sx_layout sxmp_furnace_compatibility_reserved={0x607b0055U,"furnace_compatibility_reserved",sxmp_furnace_compatibility_reserved_fields,SX_COUNT(sxmp_furnace_compatibility_reserved_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_chip_reserved_fields[]={
 SX_FIELD("reserved","uint8",0,1,SX_RESERVED),
};
static const sx_layout sxmp_furnace_chip_reserved={0x607b0056U,"furnace_chip_reserved",sxmp_furnace_chip_reserved_fields,SX_COUNT(sxmp_furnace_chip_reserved_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_new_instrument_prefix_fields[]={
 SX_FIELD("format_version","uint16",0,2,SX_NONE),
 SX_FIELD("instrument_type","uint16",2,2,SX_ID),
};
static const sx_layout sxmp_furnace_new_instrument_prefix={0x607b0057U,"furnace_new_instrument_prefix",sxmp_furnace_new_instrument_prefix_fields,SX_COUNT(sxmp_furnace_new_instrument_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_instrument_feature_fields[]={
 SX_FIELD("feature_code","char[2]",0,2,SX_ID),
 SX_FIELD("feature_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxmp_furnace_instrument_feature={0x607b0058U,"furnace_instrument_feature",sxmp_furnace_instrument_feature_fields,SX_COUNT(sxmp_furnace_instrument_feature_fields),SX_LE};
static const xx_data_struct_field_desc sxmp_furnace_instrument_end_fields[]={
 SX_FIELD("end_marker","char[2]",0,2,SX_ID),
};
static const sx_layout sxmp_furnace_instrument_end={0x607b0059U,"furnace_instrument_end",sxmp_furnace_instrument_end_fields,SX_COUNT(sxmp_furnace_instrument_end_fields),SX_LE};
static const sx_layout*const sx_musicprojects_layouts[]={&sxmp_famistudio_file_header,&sxmp_famitracker_file_header,&sxmp_famitracker_block_header,&sxmp_famitracker_end,&sxmp_famitracker_info,&sxmp_famitracker_parameters_v1,&sxmp_famitracker_parameters_v2,&sxmp_famitracker_parameters_v3,&sxmp_famitracker_parameters_v4,&sxmp_famitracker_parameters_v5,&sxmp_famitracker_parameters_v5_n163,&sxmp_famitracker_parameters_v6,&sxmp_famitracker_parameters_v6_n163,&sxmp_famitracker_parameters_v7,&sxmp_famitracker_parameters_v7_n163,&sxmp_famitracker_parameters_v8,&sxmp_famitracker_parameters_v8_n163,&sxmp_famitracker_parameters_v9,&sxmp_famitracker_parameters_v9_n163,&sxmp_famitracker_track_count,&sxmp_famitracker_channel_type,&sxmp_famitracker_effect_columns,&sxmp_music_project_text,&sxmp_music_project_name,&sxmp_music_project_author,&sxmp_music_project_string_terminator,&sxmp_renoise_legacy_text,&sxmp_music_project_xml_element,&sxmp_music_project_xml_attribute,&sxmp_music_project_xml_value,&sxmp_music_project_xml_version,&sxmp_furnace_module_header,&sxmp_furnace_instrument_header,&sxmp_furnace_wavetable_header,&sxmp_furnace_block_header,&sxmp_furnace_file_pointer,&sxmp_furnace_wave_dimensions,&sxmp_furnace_wave_value,&sxmp_furnace_instrument_prefix,&sxmp_furnace_info_prefix,&sxmp_furnace_chip_id,&sxmp_furnace_chip_volume,&sxmp_furnace_chip_pan,&sxmp_furnace_chip_flags,&sxmp_furnace_tuning,&sxmp_furnace_inf2_tuning,&sxmp_furnace_inf2_chip,&sxmp_furnace_patchbay_count,&sxmp_furnace_patchbay_connection,&sxmp_furnace_patchbay_auto,&sxmp_furnace_element,&sxmp_furnace_element_end,&sxmp_beepola_header,&sxmp_beepola_section,&sxmp_beepola_property,&sxmp_beepola_property_value,&sxmp_beepola_count,&sxmp_beepola_loop_index,&sxmp_beepola_order,&sxmp_beepola_pattern_header,&sxmp_beepola_phaser_instrument,&sxmp_renoise_legacy_header,&sxmp_renoise_legacy_chunk_header,&sxmp_renoise_legacy_info_v0,&sxmp_renoise_legacy_string_length,&sxmp_beepola_row_count,&sxmp_beepola_channel_one_note,&sxmp_beepola_channel_two_note,&sxmp_beepola_drum,&sxmp_beepola_channel_one_sustain,&sxmp_beepola_channel_two_sustain,&sxmp_beepola_channel_one_warp,&sxmp_beepola_channel_two_warp,&sxmp_beepola_ornament_value,&sxmp_beepola_channel_one_glissando,&sxmp_beepola_channel_two_glissando,&sxmp_beepola_channel_one_skew,&sxmp_beepola_channel_two_skew,&sxmp_beepola_channel_one_skew_xor,&sxmp_beepola_channel_two_skew_xor,&sxmp_beepola_channel_one_arpeggio,&sxmp_beepola_channel_two_arpeggio,&sxmp_beepola_ornament_length,&sxmp_furnace_compatibility_prefix,&sxmp_furnace_compatibility_reserved,&sxmp_furnace_chip_reserved,&sxmp_furnace_new_instrument_prefix,&sxmp_furnace_instrument_feature,&sxmp_furnace_instrument_end};
static bool sx_musicprojects_comment(xx_data_struct_record*r,uint32_t id)
{if(!r||!r->name||id<0x607b0000U||id>=0x607c0000U)return true;
 if(!xx_rt_wcscmp(r->name,L"file_offset")||!xx_rt_wcscmp(r->name,L"song_info_offset")||!xx_rt_wcscmp(r->name,L"instrument_offset"))return xx_data_struct_record_set_comment(r,L"Physical byte offset from the start of this Furnace file; zero means absent where permitted.");
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))return xx_data_struct_record_set_comment(r,L"Signed stored size of the raw-DEFLATE decoded project. Decoded members have no physical source offsets.");
 if(!xx_rt_wcscmp(r->name,L"tracks_minus_one")||!xx_rt_wcscmp(r->name,L"effect_columns_minus_one"))return xx_data_struct_record_set_comment(r,L"Stored count minus one; add one to obtain the logical count.");
 if(!xx_rt_wcscmp(r->name,L"legacy_compatibility_bytes"))return xx_data_struct_record_set_comment(r,L"Twenty compatibility/reserved bytes with version-dependent meaning; historical variants are preserved uninterpreted.");
 if(!xx_rt_wcscmp(r->name,L"format_version"))return xx_data_struct_record_set_comment(r,L"Stored file or block revision; it is not necessarily the application release number.");
 if(!xx_rt_wcscmp(r->name,L"volume_64"))return xx_data_struct_record_set_comment(r,L"Signed legacy chip volume; 64 corresponds to 1.0.");
 if(!xx_rt_wcscmp(r->name,L"panning")&&r->value.type!=XX_VAR_TYPE_FLOAT&&r->value.type!=XX_VAR_TYPE_DOUBLE)return xx_data_struct_record_set_comment(r,L"Signed legacy chip pan: -128 is left and +127 is right.");
 if(!xx_rt_wcscmp(r->name,L"connection"))return xx_data_struct_record_set_comment(r,L"Patchbay source is the upper 16 bits; destination is the lower 16 bits.");
 if(!xx_rt_wcscmp(r->name,L"ornament_value"))return xx_data_struct_record_set_comment(r,L"Earlier ornament bytes are stored with bit 7 clear; the final byte preserves bit 7.");
 if(!xx_rt_wcscmp(r->name,L"maximum_value"))return xx_data_struct_record_set_comment(r,L"Stored signed maximum; Furnace clamps values greater than 255 while loading the wave.");
 if(!xx_rt_wcscmp(r->name,L"minimum_value"))return xx_data_struct_record_set_comment(r,L"Stored signed value; expected zero. Furnace clamps nonzero values while loading the wave.");
 if(!xx_rt_wcscmp(r->name,L"document_version"))return xx_data_struct_record_set_comment(r,L"Literal XML document revision, parsed from the stored doc_version attribute; entities are not expanded.");
 return true;}

/* Physical metadata uses bounded reads; compressed and unknown blocks stay raw. */
typedef struct sxmp_view {sx_context*c;uint64_t work;} sxmp_view;
static bool sxmp_span(sxmp_view*v,uint64_t at,uint64_t z,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&end<=(uint64_t)v->c->size&&at<=end&&z<=end-at;}
static bool sxmp_read(sxmp_view*v,uint64_t at,void*b,size_t z,uint64_t end)
{return ++v->work<=4000000&&sxmp_span(v,at,z,end)&&sx_read(v->c,(int64_t)at,b,z);}
static bool sxmp_u(sxmp_view*v,uint64_t at,unsigned z,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!z||z>8||!sxmp_read(v,at,b,z,end))return false;*out=0;for(unsigned i=0;i<z;i++)*out|=(uint64_t)b[i]<<(8*i);return true;}
static bool sxmp_eq(sxmp_view*v,uint64_t at,const char*s,size_t z,uint64_t end)
{uint8_t b[64];return z<=sizeof(b)&&sxmp_read(v,at,b,z,end)&&!xx_rt_memcmp(b,s,z);}
static bool sxmp_emit(sxmp_view*v,const sx_layout*l,uint64_t at,uint64_t z,uint64_t end)
{if(!sxmp_span(v,at,z,end))return false;if(!z||v->c->count>=24000)return true;if(!l->fields[0].size&&z>(uint64_t)sx_variable_field_limit(l->fields[0].type))return true;return sx_add(v->c,l,(int64_t)at,(int64_t)z);}
static bool sxmp_row(sxmp_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;return sxmp_emit(v,l,at,(uint64_t)(f->rel_offset+f->size),end);}
static bool sxmp_table(sxmp_view*v,const sx_layout*l,uint64_t at,uint64_t n,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||n>4000000||n>UINT64_MAX/z||!sxmp_span(v,at,n*z,end))return false;for(uint64_t i=0;i<n&&v->c->count<24000;i++,at+=z)if(!sxmp_row(v,l,at,end))return false;return true;}
static bool sxmp_string(sxmp_view*v,const sx_layout*l,uint64_t*p,uint64_t end)
{uint64_t at=*p,b;while(*p<end&&*p-at<1048576){if(!sxmp_u(v,*p,1,&b,end))return false;(*p)++;if(!b)return sxmp_emit(v,l,at,*p-at-1,end)&&sxmp_row(v,&sxmp_music_project_string_terminator,*p-1,end);}return false;}
static int sxmp_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxmp_finish(sx_context*c)
{size_t n=c->count,k=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxmp_order);for(size_t i=0;i<n;i++){int64_t a=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(a<end)continue;c->items[k++]=c->items[i];end=a+z;}c->count=k;n=k;end=0;for(size_t i=0;i<n;i++){int64_t a=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(a>end&&!sx_raw(c,end,a-end))return false;end=a+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxmp_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
#define MP_ROW(name,at,end) sxmp_row(v,&sxmp_##name,(at),(end))

static bool sxmp_famistudio(sxmp_view*v)
{uint64_t e=v->c->size,version,z;return MP_ROW(famistudio_file_header,0,e)&&sxmp_u(v,4,4,&version,e)&&version>0&&version<=INT32_MAX&&sxmp_u(v,8,4,&z,e)&&z<=INT32_MAX;}
static const sx_layout*sxmp_ftm_params(unsigned version,bool n163)
{switch(version){case 1:return &sxmp_famitracker_parameters_v1;case 2:return &sxmp_famitracker_parameters_v2;case 3:return &sxmp_famitracker_parameters_v3;case 4:return &sxmp_famitracker_parameters_v4;case 5:return n163?&sxmp_famitracker_parameters_v5_n163:&sxmp_famitracker_parameters_v5;case 6:return n163?&sxmp_famitracker_parameters_v6_n163:&sxmp_famitracker_parameters_v6;case 7:return n163?&sxmp_famitracker_parameters_v7_n163:&sxmp_famitracker_parameters_v7;case 8:return n163?&sxmp_famitracker_parameters_v8_n163:&sxmp_famitracker_parameters_v8;case 9:return n163?&sxmp_famitracker_parameters_v9_n163:&sxmp_famitracker_parameters_v9;default:return NULL;}}
static bool sxmp_famitracker(sxmp_view*v)
{uint64_t e=v->c->size,p=22,channels=0;if(!MP_ROW(famitracker_file_header,0,e))return false;
 while(p<e&&v->c->count<24000){if(sxmp_eq(v,p,"END",3,e))return MP_ROW(famitracker_end,p,e);uint64_t z,version;if(!MP_ROW(famitracker_block_header,p,e)||!sxmp_u(v,p+16,4,&version,e)||!sxmp_u(v,p+20,4,&z,e)||version>INT32_MAX||z>INT32_MAX||!sxmp_span(v,p+24,z,e))return false;uint64_t a=p+24,end=a+z;
  if(sxmp_eq(v,p,"PARAMS\0",7,e)){uint64_t chips=0;const sx_layout*l;if(version!=1&&!sxmp_u(v,a,1,&chips,end))return false;if(!sxmp_u(v,a+(version==1?4:1),4,&channels,end)||!channels||channels>256)return false;l=sxmp_ftm_params((unsigned)version,channels!=5&&(chips&16)!=0);if(l&&!sxmp_row(v,l,a,end))return false;}
  else if(sxmp_eq(v,p,"INFO\0",5,e)){if(version==1&&!MP_ROW(famitracker_info,a,end))return false;}
  else if(sxmp_eq(v,p,"HEADER\0",7,e)&&version>=1&&version<=3){uint64_t tracks=1;if(version>=2){if(!MP_ROW(famitracker_track_count,a,end)||!sxmp_u(v,a,1,&tracks,end))return false;tracks++;a++;}if(version>=3)for(uint64_t i=0;i<tracks;i++)if(!sxmp_string(v,&sxmp_music_project_name,&a,end))return false;if(channels)for(uint64_t i=0;i<channels;i++){if(!MP_ROW(famitracker_channel_type,a,end)||!sxmp_table(v,&sxmp_famitracker_effect_columns,a+1,tracks,end))return false;a+=tracks+1;}}
  p=end;
 }return true;}
static bool sxmp_furnace_block(sxmp_view*v,uint64_t at,uint64_t end,unsigned file_version,unsigned depth);
static bool sxmp_furnace_pointers(sxmp_view*v,uint64_t at,uint64_t count,uint64_t end,unsigned file_version,unsigned depth,bool follow)
{if(!sxmp_table(v,&sxmp_furnace_file_pointer,at,count,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++){uint64_t p;if(!sxmp_u(v,at+4*i,4,&p,end))return false;if(p&&!sxmp_span(v,p,8,v->c->size))return false;if(p&&follow&&!sxmp_furnace_block(v,p,v->c->size,file_version,depth+1))return false;}return true;}
static bool sxmp_furnace_block(sxmp_view*v,uint64_t at,uint64_t end,unsigned file_version,unsigned depth)
{uint64_t z,p=at+8;if(depth>3||!MP_ROW(furnace_block_header,at,end)||!sxmp_u(v,at+4,4,&z,end))return false;if(z||file_version>=100){if(!sxmp_span(v,p,z,end))return false;end=p+z;}
 if(sxmp_eq(v,at,"WAVE",4,end)){uint64_t width;if(!sxmp_string(v,&sxmp_music_project_name,&p,end)||!MP_ROW(furnace_wave_dimensions,p,end)||!sxmp_u(v,p,4,&width,end)||width>INT32_MAX)return false;return sxmp_table(v,&sxmp_furnace_wave_value,p+12,width,end);}
 if(sxmp_eq(v,at,"INST",4,end)){if(!MP_ROW(furnace_instrument_prefix,p,end))return false;p+=4;return sxmp_string(v,&sxmp_music_project_name,&p,end);}
 if(sxmp_eq(v,at,"INS2",4,end)){if(!MP_ROW(furnace_new_instrument_prefix,p,end))return false;p+=4;while(p<end&&v->c->count<24000){if(sxmp_eq(v,p,"EN",2,end))return MP_ROW(furnace_instrument_end,p,end);uint64_t n;if(!MP_ROW(furnace_instrument_feature,p,end)||!sxmp_u(v,p+2,2,&n,end)||!sxmp_span(v,p+4,n,end))return false;if(sxmp_eq(v,p,"NA",2,end)){uint64_t name=p+4;if(!sxmp_string(v,&sxmp_music_project_name,&name,p+4+n))return false;}p+=4+n;}return true;}
 if(sxmp_eq(v,at,"INFO",4,end)){uint64_t instruments,waves,samples,patterns;if(!MP_ROW(furnace_info_prefix,p,end)||!sxmp_u(v,p+14,2,&instruments,end)||!sxmp_u(v,p+16,2,&waves,end)||!sxmp_u(v,p+18,2,&samples,end)||!sxmp_u(v,p+20,4,&patterns,end))return false;p+=24;
  if(!sxmp_table(v,&sxmp_furnace_chip_id,p,32,end)||!sxmp_table(v,file_version>=135?&sxmp_furnace_chip_reserved:&sxmp_furnace_chip_volume,p+32,32,end)||!sxmp_table(v,file_version>=135?&sxmp_furnace_chip_reserved:&sxmp_furnace_chip_pan,p+64,32,end))return false;p+=96;
  if(file_version>=119){if(!sxmp_furnace_pointers(v,p,32,end,file_version,depth,false))return false;}else if(!sxmp_table(v,&sxmp_furnace_chip_flags,p,32,end))return false;p+=128;
  if(!sxmp_string(v,&sxmp_music_project_name,&p,end)||!sxmp_string(v,&sxmp_music_project_author,&p,end)||!MP_ROW(furnace_tuning,p,end))return false;p+=4;
  /* The initial compatibility bytes have version-dependent semantics. Unknown
   * historical subsets stay uninterpreted instead of receiving modern labels. */
  if(!sxmp_row(v,file_version>=69?&sxmp_furnace_compatibility_prefix:&sxmp_furnace_compatibility_reserved,p,end))return false;p+=20;
  uint64_t total=instruments+waves+samples+patterns;return sxmp_furnace_pointers(v,p,total,end,file_version,depth,false);}
 if(sxmp_eq(v,at,"INF2",4,end)){for(unsigned i=0;i<8;i++)if(!sxmp_string(v,i==1?&sxmp_music_project_author:&sxmp_music_project_name,&p,end))return false;uint64_t chips,connections;if(!MP_ROW(furnace_inf2_tuning,p,end)||!sxmp_u(v,p+11,2,&chips,end))return false;p+=13;if(!sxmp_table(v,&sxmp_furnace_inf2_chip,p,chips,end))return false;p+=16*chips;if(!MP_ROW(furnace_patchbay_count,p,end)||!sxmp_u(v,p,4,&connections,end))return false;p+=4;if(!sxmp_table(v,&sxmp_furnace_patchbay_connection,p,connections,end))return false;p+=connections*4;if(!MP_ROW(furnace_patchbay_auto,p,end))return false;p++;
  while(p<end&&v->c->count<24000){uint64_t type,count;if(!sxmp_u(v,p,1,&type,end))return false;if(!type)return MP_ROW(furnace_element_end,p,end);if(!MP_ROW(furnace_element,p,end)||!sxmp_u(v,p+1,4,&count,end))return false;p+=5;if(!sxmp_furnace_pointers(v,p,count,end,file_version,depth,false))return false;p+=4*count;}return true;}
 return true;}
static bool sxmp_furnace(sxmp_view*v,unsigned kind)
{uint64_t e=v->c->size,version,at,count,waves,samples;if(!sxmp_u(v,16,2,&version,e))return false;
 if(kind==2)return MP_ROW(furnace_wavetable_header,0,e)&&sxmp_furnace_block(v,20,e,(unsigned)version,0);
 if(!sxmp_row(v,kind==1?&sxmp_furnace_instrument_header:&sxmp_furnace_module_header,0,e)||!sxmp_u(v,20,4,&at,e)||at<32)return false;
 if(kind==1){if(!sxmp_u(v,24,2,&waves,e)||!sxmp_u(v,26,2,&samples,e))return false;count=waves+samples;if(!sxmp_furnace_pointers(v,32,count,e,(unsigned)version,0,false)||at<32+4*count)return false;}
 return sxmp_furnace_block(v,at,e,(unsigned)version,0);}
static bool sxmp_renoise_legacy(sxmp_view*v)
{uint64_t e=v->c->size,p=49;if(!MP_ROW(renoise_legacy_header,0,e)||!MP_ROW(renoise_legacy_chunk_header,9,e))return false;
 if(sxmp_eq(v,29,"Header V00         \0",20,e))return MP_ROW(renoise_legacy_info_v0,p,e);
 if(sxmp_eq(v,29,"Header V01         \0",20,e)||sxmp_eq(v,29,"Header V02         \0",20,e)){for(unsigned i=0;i<3;i++){uint64_t z;if(!MP_ROW(renoise_legacy_string_length,p,e)||!sxmp_u(v,p,4,&z,e)||!sxmp_emit(v,&sxmp_renoise_legacy_text,p+4,z,e))return false;p+=4+z;}}
 return true;}
static bool sxmp_beep_token(sxmp_view*v,uint64_t*p,uint64_t end,uint64_t*a,uint64_t*z)
{*a=*p;uint64_t b;while(*p<end&&*p-*a<1048576){if(!sxmp_u(v,*p,1,&b,end))return false;(*p)++;if(!b){*z=*p-*a-1;return true;}}return false;}
static bool sxmp_beep_prop(sxmp_view*v,uint64_t*p,uint64_t end,const char*key,const sx_layout*value,uint64_t*number)
{uint64_t a,z,k=xx_rt_strlen(key),at,c,n=0;if(!sxmp_beep_token(v,p,end,&a,&z)||z<=k||!sxmp_eq(v,a,key,(size_t)k,end)||!sxmp_u(v,a+k,1,&c,end)||c!='=')return false;at=a+k+1;if(!sxmp_emit(v,&sxmp_beepola_property,a,k,end)||!sxmp_emit(v,value,at,z-k-1,end))return false;
 if(number){if(z-k-1<1||z-k-1>10)return false;for(uint64_t i=at;i<a+z;i++){if(!sxmp_u(v,i,1,&c,end)||c<'0'||c>'9'||n>(UINT32_MAX-(c-'0'))/10)return false;n=n*10+c-'0';}*number=n;}return true;}
static bool sxmp_beepola(sxmp_view*v)
{uint64_t e=v->c->size,p=12,a,z;if(!MP_ROW(beepola_header,0,e)||!sxmp_eq(v,7,"0001\0",5,e))return false;
 while(p<e&&v->c->count<24000){if(!sxmp_beep_token(v,&p,e,&a,&z)||!sxmp_emit(v,&sxmp_beepola_section,a,z,e))return false;
  if(z==4&&sxmp_eq(v,a,":END",4,e))continue;
  if(z==5&&sxmp_eq(v,a,":INFO",5,e)){while(p<e){uint64_t b,n;if(!sxmp_beep_token(v,&p,e,&b,&n))return false;if(n==4&&sxmp_eq(v,b,":END",4,e)){if(!sxmp_emit(v,&sxmp_beepola_section,b,n,e))return false;break;}uint64_t k=0,c;while(k<n){if(!sxmp_u(v,b+k,1,&c,e))return false;if(c=='=')break;k++;}if(k==n)return false;if(!sxmp_emit(v,&sxmp_beepola_property,b,k,e)||!sxmp_emit(v,&sxmp_beepola_property_value,b+k+1,n-k-1,e))return false;}continue;}
  if(z==7&&sxmp_eq(v,a,":LAYOUT",7,e)){uint64_t loop,n;if(!sxmp_beep_prop(v,&p,e,"LoopStart",&sxmp_beepola_loop_index,&loop)||!sxmp_beep_prop(v,&p,e,"Length",&sxmp_beepola_count,&n)||n>256||loop>n||!sxmp_table(v,&sxmp_beepola_order,p,n,e))return false;p+=n;continue;}
  if(z==8&&sxmp_eq(v,a,":P1INSTR",8,e)){uint64_t n;if(!sxmp_beep_prop(v,&p,e,"Length",&sxmp_beepola_count,&n)||n>256||!sxmp_table(v,&sxmp_beepola_phaser_instrument,p,n,e))return false;p+=n*6;continue;}
  if(z==13&&sxmp_eq(v,a,":SVGORNAMENTS",13,e)){uint64_t n;if(!sxmp_beep_prop(v,&p,e,"OrnamentCount",&sxmp_beepola_count,&n)||n>256)return false;for(uint64_t i=0;i<n;i++){uint64_t rows;if(!MP_ROW(beepola_ornament_length,p,e)||!sxmp_u(v,p,4,&rows,e)||rows>256||!sxmp_table(v,&sxmp_beepola_ornament_value,p+4,rows,e))return false;p+=4+rows;}continue;}
  unsigned mode=z==12&&sxmp_eq(v,a,":PATTERNDATA",12,e)?1:z==15&&sxmp_eq(v,a,":SVGPATTERNDATA",15,e)?2:z==12&&sxmp_eq(v,a,":SVGWARPDATA",12,e)?3:0;
  if(!mode)return true;/* Unknown sections have no known length: preserve tail. */
  uint64_t count;if(!sxmp_beep_prop(v,&p,e,"PatternCount",&sxmp_beepola_count,&count)||count>256)return false;
  const sx_layout*plain[]={&sxmp_beepola_channel_one_note,&sxmp_beepola_channel_two_note,&sxmp_beepola_drum,&sxmp_beepola_channel_one_sustain,&sxmp_beepola_channel_two_sustain};
  const sx_layout*svg[]={&sxmp_beepola_channel_one_glissando,&sxmp_beepola_channel_two_glissando,&sxmp_beepola_channel_one_skew,&sxmp_beepola_channel_two_skew,&sxmp_beepola_channel_one_skew_xor,&sxmp_beepola_channel_two_skew_xor,&sxmp_beepola_channel_one_arpeggio,&sxmp_beepola_channel_two_arpeggio};
  const sx_layout*warp[]={&sxmp_beepola_channel_one_warp,&sxmp_beepola_channel_two_warp};
  for(uint64_t i=0;i<count;i++){uint64_t rows;if(mode==1&&!sxmp_beep_prop(v,&p,e,"PatternName",&sxmp_music_project_name,NULL))return false;if(!sxmp_u(v,p,4,&rows,e)||rows>256||!sxmp_row(v,mode==1?&sxmp_beepola_pattern_header:&sxmp_beepola_row_count,p,e))return false;p+=mode==1?8:4;unsigned cols=mode==1?5:mode==2?8:2,width=mode==2?2:1;const sx_layout**fields=mode==1?plain:mode==2?svg:warp;for(unsigned j=0;j<cols;j++){if(!sxmp_table(v,fields[j],p,rows,e))return false;p+=rows*width;}}
 }return true;}
static bool sxmp_xml_space(unsigned c){return c==' '||c=='\t'||c=='\n'||c=='\r';}
static bool sxmp_xml_name(unsigned c){return (c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')||c=='_'||c=='-'||c==':'||c=='.'||c>=128;}
static bool sxmp_xml(sxmp_view*v)
{/* This is a physical lexical view, not an XML entity resolver. */
 uint64_t e=(uint64_t)v->c->size,n=e>16777216?16777216:e,p=0;uint8_t*b=xx_mem_alloc((size_t)n);if(!b||!sxmp_read(v,0,b,(size_t)n,e)){xx_mem_free(b);return false;}bool ok=true,any=false;
 while(p<n&&v->c->count<24000&&!xx_pd_is_stopped(v->c->pd)){if(b[p]!='<'){uint64_t a=p;while(p<n&&b[p]!='<')p++;while(a<p&&sxmp_xml_space(b[a]))a++;uint64_t z=p-a;while(z&&sxmp_xml_space(b[a+z-1]))z--;if(z&&!sxmp_emit(v,&sxmp_music_project_text,a,z,e)){ok=false;break;}continue;}
  if(p+4<=n&&!xx_rt_memcmp(b+p,"<!--",4)){p+=4;while(p+3<=n&&xx_rt_memcmp(b+p,"-->",3))p++;if(p+3>n)break;p+=3;continue;}
  if(p+9<=n&&!xx_rt_memcmp(b+p,"<![CDATA[",9)){uint64_t a=p+9;p=a;while(p+3<=n&&xx_rt_memcmp(b+p,"]]>",3))p++;if(p+3>n)break;if(!sxmp_emit(v,&sxmp_music_project_text,a,p-a,e)){ok=false;break;}p+=3;continue;}
  if(p+2<=n&&b[p+1]=='!')break;/* Declarations/DTDs and remaining text stay raw. */
  p++;if(p<n&&(b[p]=='/'||b[p]=='?'))p++;uint64_t a=p;while(p<n&&sxmp_xml_name(b[p]))p++;if(p==a)break;if(!sxmp_emit(v,&sxmp_music_project_xml_element,a,p-a,e)){ok=false;break;}any=true;
  while(p<n){while(p<n&&sxmp_xml_space(b[p]))p++;if(p==n)break;if(b[p]=='>'){p++;break;}if((b[p]=='/'||b[p]=='?')&&p+1<n&&b[p+1]=='>'){p+=2;break;}
   a=p;while(p<n&&sxmp_xml_name(b[p]))p++;uint64_t z=p-a;if(!z){p=n;break;}while(p<n&&sxmp_xml_space(b[p]))p++;if(p==n||b[p++]!='='){p=n;break;}while(p<n&&sxmp_xml_space(b[p]))p++;if(p==n||(b[p]!='"'&&b[p]!='\'')){p=n;break;}uint8_t quote=b[p++];uint64_t value=p;while(p<n&&b[p]!=quote)p++;if(p==n)break;
   const sx_layout*l=&sxmp_music_project_xml_value;bool numeric=(z==11&&!xx_rt_memcmp(b+a,"doc_version",11));for(uint64_t k=value;k<p&&numeric;k++)if(b[k]<'0'||b[k]>'9')numeric=false;if(numeric&&p>value&&p-value<=20)l=&sxmp_music_project_xml_version;
   if(!sxmp_emit(v,&sxmp_music_project_xml_attribute,a,z,e)||!sxmp_emit(v,l,value,p-value,e)){ok=false;p=n;break;}p++;
  }
 }xx_mem_free(b);return ok&&any&&!xx_pd_is_stopped(v->c->pd);}

static bool sx_musicprojects_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_DIE_MUSIC_NEVO_ARKOSTRACKER2:case XX_FILE_TYPE_DIE_MUSIC_SHIRU_BEEPOLA:case XX_FILE_TYPE_DIE_MUSIC_BLEUBLEU_FAMISTUDIO:case XX_FILE_TYPE_DIE_MUSIC_LISS_FAMITRACKER_FTM:case XX_FILE_TYPE_DIE_MUSIC_TILDEARROW_FURNACETRACKER:case XX_FILE_TYPE_DIE_MUSIC_TILDEARROW_FURNACETRACKER_FUI:case XX_FILE_TYPE_DIE_MUSIC_TILDEARROW_FURNACETRACKER_FUW:case XX_FILE_TYPE_DIE_MUSIC_MULLER_RENOISE_RNS0:case XX_FILE_TYPE_DIE_MUSIC_MULLER_RENOISE_XRDP:case XX_FILE_TYPE_DIE_MUSIC_MULLER_RENOISE_XRNO:case XX_FILE_TYPE_DIE_MUSIC_MULLER_RENOISE_XRNT_UNP:case XX_FILE_TYPE_DIE_MUSIC_MULLER_RENOISE_XRNZ:return true;default:return false;}}
static bool sx_musicprojects_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxmp_view view={c,0},*v=&view;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_DIE_MUSIC_NEVO_ARKOSTRACKER2:ok=sxmp_xml(v);break;case XX_FILE_TYPE_DIE_MUSIC_SHIRU_BEEPOLA:ok=sxmp_beepola(v);break;case XX_FILE_TYPE_DIE_MUSIC_BLEUBLEU_FAMISTUDIO:ok=sxmp_famistudio(v);break;case XX_FILE_TYPE_DIE_MUSIC_LISS_FAMITRACKER_FTM:ok=sxmp_famitracker(v);break;case XX_FILE_TYPE_DIE_MUSIC_TILDEARROW_FURNACETRACKER:ok=sxmp_furnace(v,0);break;case XX_FILE_TYPE_DIE_MUSIC_TILDEARROW_FURNACETRACKER_FUI:ok=sxmp_furnace(v,1);break;case XX_FILE_TYPE_DIE_MUSIC_TILDEARROW_FURNACETRACKER_FUW:ok=sxmp_furnace(v,2);break;case XX_FILE_TYPE_DIE_MUSIC_MULLER_RENOISE_RNS0:ok=sxmp_renoise_legacy(v);break;case XX_FILE_TYPE_DIE_MUSIC_MULLER_RENOISE_XRDP:ok=sxmp_xml(v);break;case XX_FILE_TYPE_DIE_MUSIC_MULLER_RENOISE_XRNO:ok=sxmp_xml(v);break;case XX_FILE_TYPE_DIE_MUSIC_MULLER_RENOISE_XRNT_UNP:ok=sxmp_xml(v);break;case XX_FILE_TYPE_DIE_MUSIC_MULLER_RENOISE_XRNZ:ok=sxmp_xml(v);break;default:break;}return ok&&sxmp_finish(c);}
#undef MP_ROW
