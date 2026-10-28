/* SPDX-License-Identifier: MIT
 * Physical ZX/8-bit tracker metadata. Encoded event streams and PCM stay raw.
 * See docs/data_struct_zxmusic_scope.txt for format-specific limits. */
static const xx_data_struct_field_desc sxzxm_zx_position_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
};
static const sx_layout sxzxm_zx_position={UINT32_C(0x608A0001),"zx_position",sxzxm_zx_position_fields,SX_COUNT(sxzxm_zx_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_ornament_step_fields[]={
 SX_FIELD("note_offset","int8",0,1,SX_NONE),
};
static const sx_layout sxzxm_zx_ornament_step={UINT32_C(0x608A0002),"zx_ornament_step",sxzxm_zx_ornament_step_fields,SX_COUNT(sxzxm_zx_ornament_step_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_sample_offset_fields[]={
 SX_FIELD("sample_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxzxm_zx_sample_offset={UINT32_C(0x608A0003),"zx_sample_offset",sxzxm_zx_sample_offset_fields,SX_COUNT(sxzxm_zx_sample_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_ornament_offset_fields[]={
 SX_FIELD("ornament_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxzxm_zx_ornament_offset={UINT32_C(0x608A0004),"zx_ornament_offset",sxzxm_zx_ornament_offset_fields,SX_COUNT(sxzxm_zx_ornament_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_sample_address_fields[]={
 SX_FIELD("sample_address","uint16",0,2,SX_ADDRESS),
};
static const sx_layout sxzxm_zx_sample_address={UINT32_C(0x608A0005),"zx_sample_address",sxzxm_zx_sample_address_fields,SX_COUNT(sxzxm_zx_sample_address_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_ornament_address_fields[]={
 SX_FIELD("ornament_address","uint16",0,2,SX_ADDRESS),
};
static const sx_layout sxzxm_zx_ornament_address={UINT32_C(0x608A0006),"zx_ornament_address",sxzxm_zx_ornament_address_fields,SX_COUNT(sxzxm_zx_ornament_address_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_pattern_channels_fields[]={
 SX_FIELD("channel_a_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("channel_b_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("channel_c_offset","uint16",4,2,SX_OFFSET),
};
static const sx_layout sxzxm_zx_pattern_channels={UINT32_C(0x608A0007),"zx_pattern_channels",sxzxm_zx_pattern_channels_fields,SX_COUNT(sxzxm_zx_pattern_channels_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_pattern_addresses_fields[]={
 SX_FIELD("channel_a_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("channel_b_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("channel_c_address","uint16",4,2,SX_ADDRESS),
};
static const sx_layout sxzxm_zx_pattern_addresses={UINT32_C(0x608A0008),"zx_pattern_addresses",sxzxm_zx_pattern_addresses_fields,SX_COUNT(sxzxm_zx_pattern_addresses_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_positions_count_fields[]={
 SX_FIELD("position_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxzxm_zx_positions_count={UINT32_C(0x608A0009),"zx_positions_count",sxzxm_zx_positions_count_fields,SX_COUNT(sxzxm_zx_positions_count_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_object_size_loop_fields[]={
 SX_FIELD("line_count","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("loop_index","uint8",1,1,SX_NONE),
};
static const sx_layout sxzxm_zx_object_size_loop={UINT32_C(0x608A000A),"zx_object_size_loop",sxzxm_zx_object_size_loop_fields,SX_COUNT(sxzxm_zx_object_size_loop_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_object_loop_size_fields[]={
 SX_FIELD("loop_index","uint8",0,1,SX_NONE),
 SX_FIELD("line_count","uint8",1,1,SX_COUNT_PROP),
};
static const sx_layout sxzxm_zx_object_loop_size={UINT32_C(0x608A000B),"zx_object_loop_size",sxzxm_zx_object_loop_size_fields,SX_COUNT(sxzxm_zx_object_loop_size_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_marker_fields[]={
 SX_FIELD("marker","uint8",0,1,SX_ID),
};
static const sx_layout sxzxm_zx_marker={UINT32_C(0x608A000C),"zx_marker",sxzxm_zx_marker_fields,SX_COUNT(sxzxm_zx_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_text_fields[]={
 SX_FIELD("text","char",0,0,SX_NONE),
};
static const sx_layout sxzxm_zx_text={UINT32_C(0x608A000D),"zx_text",sxzxm_zx_text_fields,SX_COUNT(sxzxm_zx_text_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_pt1_header_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("position_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("loop_position","uint8",2,1,SX_NONE),
 SX_FIELD("sample_00_offset","uint16",3,2,SX_OFFSET),
 SX_FIELD("sample_01_offset","uint16",5,2,SX_OFFSET),
 SX_FIELD("sample_02_offset","uint16",7,2,SX_OFFSET),
 SX_FIELD("sample_03_offset","uint16",9,2,SX_OFFSET),
 SX_FIELD("sample_04_offset","uint16",11,2,SX_OFFSET),
 SX_FIELD("sample_05_offset","uint16",13,2,SX_OFFSET),
 SX_FIELD("sample_06_offset","uint16",15,2,SX_OFFSET),
 SX_FIELD("sample_07_offset","uint16",17,2,SX_OFFSET),
 SX_FIELD("sample_08_offset","uint16",19,2,SX_OFFSET),
 SX_FIELD("sample_09_offset","uint16",21,2,SX_OFFSET),
 SX_FIELD("sample_10_offset","uint16",23,2,SX_OFFSET),
 SX_FIELD("sample_11_offset","uint16",25,2,SX_OFFSET),
 SX_FIELD("sample_12_offset","uint16",27,2,SX_OFFSET),
 SX_FIELD("sample_13_offset","uint16",29,2,SX_OFFSET),
 SX_FIELD("sample_14_offset","uint16",31,2,SX_OFFSET),
 SX_FIELD("sample_15_offset","uint16",33,2,SX_OFFSET),
 SX_FIELD("ornament_00_offset","uint16",35,2,SX_OFFSET),
 SX_FIELD("ornament_01_offset","uint16",37,2,SX_OFFSET),
 SX_FIELD("ornament_02_offset","uint16",39,2,SX_OFFSET),
 SX_FIELD("ornament_03_offset","uint16",41,2,SX_OFFSET),
 SX_FIELD("ornament_04_offset","uint16",43,2,SX_OFFSET),
 SX_FIELD("ornament_05_offset","uint16",45,2,SX_OFFSET),
 SX_FIELD("ornament_06_offset","uint16",47,2,SX_OFFSET),
 SX_FIELD("ornament_07_offset","uint16",49,2,SX_OFFSET),
 SX_FIELD("ornament_08_offset","uint16",51,2,SX_OFFSET),
 SX_FIELD("ornament_09_offset","uint16",53,2,SX_OFFSET),
 SX_FIELD("ornament_10_offset","uint16",55,2,SX_OFFSET),
 SX_FIELD("ornament_11_offset","uint16",57,2,SX_OFFSET),
 SX_FIELD("ornament_12_offset","uint16",59,2,SX_OFFSET),
 SX_FIELD("ornament_13_offset","uint16",61,2,SX_OFFSET),
 SX_FIELD("ornament_14_offset","uint16",63,2,SX_OFFSET),
 SX_FIELD("ornament_15_offset","uint16",65,2,SX_OFFSET),
 SX_FIELD("patterns_offset","uint16",67,2,SX_OFFSET),
 SX_FIELD("title","char[30]",69,30,SX_NONE),
};
static const sx_layout sxzxm_pt1_header={UINT32_C(0x608A000E),"pt1_header",sxzxm_pt1_header_fields,SX_COUNT(sxzxm_pt1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_pt2_header_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("position_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("loop_position","uint8",2,1,SX_NONE),
 SX_FIELD("sample_00_offset","uint16",3,2,SX_OFFSET),
 SX_FIELD("sample_01_offset","uint16",5,2,SX_OFFSET),
 SX_FIELD("sample_02_offset","uint16",7,2,SX_OFFSET),
 SX_FIELD("sample_03_offset","uint16",9,2,SX_OFFSET),
 SX_FIELD("sample_04_offset","uint16",11,2,SX_OFFSET),
 SX_FIELD("sample_05_offset","uint16",13,2,SX_OFFSET),
 SX_FIELD("sample_06_offset","uint16",15,2,SX_OFFSET),
 SX_FIELD("sample_07_offset","uint16",17,2,SX_OFFSET),
 SX_FIELD("sample_08_offset","uint16",19,2,SX_OFFSET),
 SX_FIELD("sample_09_offset","uint16",21,2,SX_OFFSET),
 SX_FIELD("sample_10_offset","uint16",23,2,SX_OFFSET),
 SX_FIELD("sample_11_offset","uint16",25,2,SX_OFFSET),
 SX_FIELD("sample_12_offset","uint16",27,2,SX_OFFSET),
 SX_FIELD("sample_13_offset","uint16",29,2,SX_OFFSET),
 SX_FIELD("sample_14_offset","uint16",31,2,SX_OFFSET),
 SX_FIELD("sample_15_offset","uint16",33,2,SX_OFFSET),
 SX_FIELD("sample_16_offset","uint16",35,2,SX_OFFSET),
 SX_FIELD("sample_17_offset","uint16",37,2,SX_OFFSET),
 SX_FIELD("sample_18_offset","uint16",39,2,SX_OFFSET),
 SX_FIELD("sample_19_offset","uint16",41,2,SX_OFFSET),
 SX_FIELD("sample_20_offset","uint16",43,2,SX_OFFSET),
 SX_FIELD("sample_21_offset","uint16",45,2,SX_OFFSET),
 SX_FIELD("sample_22_offset","uint16",47,2,SX_OFFSET),
 SX_FIELD("sample_23_offset","uint16",49,2,SX_OFFSET),
 SX_FIELD("sample_24_offset","uint16",51,2,SX_OFFSET),
 SX_FIELD("sample_25_offset","uint16",53,2,SX_OFFSET),
 SX_FIELD("sample_26_offset","uint16",55,2,SX_OFFSET),
 SX_FIELD("sample_27_offset","uint16",57,2,SX_OFFSET),
 SX_FIELD("sample_28_offset","uint16",59,2,SX_OFFSET),
 SX_FIELD("sample_29_offset","uint16",61,2,SX_OFFSET),
 SX_FIELD("sample_30_offset","uint16",63,2,SX_OFFSET),
 SX_FIELD("sample_31_offset","uint16",65,2,SX_OFFSET),
 SX_FIELD("ornament_00_offset","uint16",67,2,SX_OFFSET),
 SX_FIELD("ornament_01_offset","uint16",69,2,SX_OFFSET),
 SX_FIELD("ornament_02_offset","uint16",71,2,SX_OFFSET),
 SX_FIELD("ornament_03_offset","uint16",73,2,SX_OFFSET),
 SX_FIELD("ornament_04_offset","uint16",75,2,SX_OFFSET),
 SX_FIELD("ornament_05_offset","uint16",77,2,SX_OFFSET),
 SX_FIELD("ornament_06_offset","uint16",79,2,SX_OFFSET),
 SX_FIELD("ornament_07_offset","uint16",81,2,SX_OFFSET),
 SX_FIELD("ornament_08_offset","uint16",83,2,SX_OFFSET),
 SX_FIELD("ornament_09_offset","uint16",85,2,SX_OFFSET),
 SX_FIELD("ornament_10_offset","uint16",87,2,SX_OFFSET),
 SX_FIELD("ornament_11_offset","uint16",89,2,SX_OFFSET),
 SX_FIELD("ornament_12_offset","uint16",91,2,SX_OFFSET),
 SX_FIELD("ornament_13_offset","uint16",93,2,SX_OFFSET),
 SX_FIELD("ornament_14_offset","uint16",95,2,SX_OFFSET),
 SX_FIELD("ornament_15_offset","uint16",97,2,SX_OFFSET),
 SX_FIELD("patterns_offset","uint16",99,2,SX_OFFSET),
 SX_FIELD("title","char[30]",101,30,SX_NONE),
};
static const sx_layout sxzxm_pt2_header={UINT32_C(0x608A000F),"pt2_header",sxzxm_pt2_header_fields,SX_COUNT(sxzxm_pt2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_pt1_sample_line_fields[]={
 SX_FIELD("volume_vibrato_high","uint8",0,1,SX_FLAGS),
 SX_FIELD("noise_flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("vibrato_low","uint8",2,1,SX_NONE),
};
static const sx_layout sxzxm_pt1_sample_line={UINT32_C(0x608A0010),"pt1_sample_line",sxzxm_pt1_sample_line_fields,SX_COUNT(sxzxm_pt1_sample_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_pt2_sample_line_fields[]={
 SX_FIELD("noise_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("volume_vibrato_high","uint8",1,1,SX_FLAGS),
 SX_FIELD("vibrato_low","uint8",2,1,SX_NONE),
};
static const sx_layout sxzxm_pt2_sample_line={UINT32_C(0x608A0011),"pt2_sample_line",sxzxm_pt2_sample_line_fields,SX_COUNT(sxzxm_pt2_sample_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_pt3_header_fields[]={
 SX_FIELD("identifier","char[13]",0,13,SX_NONE),
 SX_FIELD("subversion","char[1]",13,1,SX_NONE),
 SX_FIELD("description","char[16]",14,16,SX_NONE),
 SX_FIELD("title","char[32]",30,32,SX_NONE),
 SX_FIELD("author_separator","char[4]",62,4,SX_NONE),
 SX_FIELD("author","char[32]",66,32,SX_NONE),
 SX_FIELD("mode","uint8",98,1,SX_ID),
 SX_FIELD("frequency_table","uint8",99,1,SX_ID),
 SX_FIELD("tempo","uint8",100,1,SX_NONE),
 SX_FIELD("position_count","uint8",101,1,SX_COUNT_PROP),
 SX_FIELD("loop_position","uint8",102,1,SX_NONE),
 SX_FIELD("patterns_offset","uint16",103,2,SX_OFFSET),
 SX_FIELD("sample_00_offset","uint16",105,2,SX_OFFSET),
 SX_FIELD("sample_01_offset","uint16",107,2,SX_OFFSET),
 SX_FIELD("sample_02_offset","uint16",109,2,SX_OFFSET),
 SX_FIELD("sample_03_offset","uint16",111,2,SX_OFFSET),
 SX_FIELD("sample_04_offset","uint16",113,2,SX_OFFSET),
 SX_FIELD("sample_05_offset","uint16",115,2,SX_OFFSET),
 SX_FIELD("sample_06_offset","uint16",117,2,SX_OFFSET),
 SX_FIELD("sample_07_offset","uint16",119,2,SX_OFFSET),
 SX_FIELD("sample_08_offset","uint16",121,2,SX_OFFSET),
 SX_FIELD("sample_09_offset","uint16",123,2,SX_OFFSET),
 SX_FIELD("sample_10_offset","uint16",125,2,SX_OFFSET),
 SX_FIELD("sample_11_offset","uint16",127,2,SX_OFFSET),
 SX_FIELD("sample_12_offset","uint16",129,2,SX_OFFSET),
 SX_FIELD("sample_13_offset","uint16",131,2,SX_OFFSET),
 SX_FIELD("sample_14_offset","uint16",133,2,SX_OFFSET),
 SX_FIELD("sample_15_offset","uint16",135,2,SX_OFFSET),
 SX_FIELD("sample_16_offset","uint16",137,2,SX_OFFSET),
 SX_FIELD("sample_17_offset","uint16",139,2,SX_OFFSET),
 SX_FIELD("sample_18_offset","uint16",141,2,SX_OFFSET),
 SX_FIELD("sample_19_offset","uint16",143,2,SX_OFFSET),
 SX_FIELD("sample_20_offset","uint16",145,2,SX_OFFSET),
 SX_FIELD("sample_21_offset","uint16",147,2,SX_OFFSET),
 SX_FIELD("sample_22_offset","uint16",149,2,SX_OFFSET),
 SX_FIELD("sample_23_offset","uint16",151,2,SX_OFFSET),
 SX_FIELD("sample_24_offset","uint16",153,2,SX_OFFSET),
 SX_FIELD("sample_25_offset","uint16",155,2,SX_OFFSET),
 SX_FIELD("sample_26_offset","uint16",157,2,SX_OFFSET),
 SX_FIELD("sample_27_offset","uint16",159,2,SX_OFFSET),
 SX_FIELD("sample_28_offset","uint16",161,2,SX_OFFSET),
 SX_FIELD("sample_29_offset","uint16",163,2,SX_OFFSET),
 SX_FIELD("sample_30_offset","uint16",165,2,SX_OFFSET),
 SX_FIELD("sample_31_offset","uint16",167,2,SX_OFFSET),
 SX_FIELD("ornament_00_offset","uint16",169,2,SX_OFFSET),
 SX_FIELD("ornament_01_offset","uint16",171,2,SX_OFFSET),
 SX_FIELD("ornament_02_offset","uint16",173,2,SX_OFFSET),
 SX_FIELD("ornament_03_offset","uint16",175,2,SX_OFFSET),
 SX_FIELD("ornament_04_offset","uint16",177,2,SX_OFFSET),
 SX_FIELD("ornament_05_offset","uint16",179,2,SX_OFFSET),
 SX_FIELD("ornament_06_offset","uint16",181,2,SX_OFFSET),
 SX_FIELD("ornament_07_offset","uint16",183,2,SX_OFFSET),
 SX_FIELD("ornament_08_offset","uint16",185,2,SX_OFFSET),
 SX_FIELD("ornament_09_offset","uint16",187,2,SX_OFFSET),
 SX_FIELD("ornament_10_offset","uint16",189,2,SX_OFFSET),
 SX_FIELD("ornament_11_offset","uint16",191,2,SX_OFFSET),
 SX_FIELD("ornament_12_offset","uint16",193,2,SX_OFFSET),
 SX_FIELD("ornament_13_offset","uint16",195,2,SX_OFFSET),
 SX_FIELD("ornament_14_offset","uint16",197,2,SX_OFFSET),
 SX_FIELD("ornament_15_offset","uint16",199,2,SX_OFFSET),
};
static const sx_layout sxzxm_pt3_header={UINT32_C(0x608A0012),"pt3_header",sxzxm_pt3_header_fields,SX_COUNT(sxzxm_pt3_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_pt3_position_fields[]={
 SX_FIELD("pattern_reference","uint8",0,1,SX_NONE),
};
static const sx_layout sxzxm_pt3_position={UINT32_C(0x608A0013),"pt3_position",sxzxm_pt3_position_fields,SX_COUNT(sxzxm_pt3_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_pt3_sample_line_fields[]={
 SX_FIELD("volume_slide_envelope","uint8",0,1,SX_FLAGS),
 SX_FIELD("level_keepers","uint8",1,1,SX_FLAGS),
 SX_FIELD("tone_offset","int16",2,2,SX_NONE),
};
static const sx_layout sxzxm_pt3_sample_line={UINT32_C(0x608A0014),"pt3_sample_line",sxzxm_pt3_sample_line_fields,SX_COUNT(sxzxm_pt3_sample_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_asc0_header_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("patterns_offset","uint16",1,2,SX_OFFSET),
 SX_FIELD("samples_offset","uint16",3,2,SX_OFFSET),
 SX_FIELD("ornaments_offset","uint16",5,2,SX_OFFSET),
 SX_FIELD("position_count","uint8",7,1,SX_COUNT_PROP),
};
static const sx_layout sxzxm_asc0_header={UINT32_C(0x608A0015),"asc0_header",sxzxm_asc0_header_fields,SX_COUNT(sxzxm_asc0_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_asc1_header_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("loop_position","uint8",1,1,SX_NONE),
 SX_FIELD("patterns_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("samples_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("ornaments_offset","uint16",6,2,SX_OFFSET),
 SX_FIELD("position_count","uint8",8,1,SX_COUNT_PROP),
};
static const sx_layout sxzxm_asc1_header={UINT32_C(0x608A0016),"asc1_header",sxzxm_asc1_header_fields,SX_COUNT(sxzxm_asc1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_asc_identity_fields[]={
 SX_FIELD("identifier","char[19]",0,19,SX_NONE),
 SX_FIELD("title","char[20]",19,20,SX_NONE),
 SX_FIELD("author_separator","char[4]",39,4,SX_NONE),
 SX_FIELD("author","char[20]",43,20,SX_NONE),
};
static const sx_layout sxzxm_asc_identity={UINT32_C(0x608A0017),"asc_identity",sxzxm_asc_identity_fields,SX_COUNT(sxzxm_asc_identity_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_asc_pattern_channels_fields[]={
 SX_FIELD("channel_a_relative_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("channel_b_relative_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("channel_c_relative_offset","uint16",4,2,SX_OFFSET),
};
static const sx_layout sxzxm_asc_pattern_channels={UINT32_C(0x608A0018),"asc_pattern_channels",sxzxm_asc_pattern_channels_fields,SX_COUNT(sxzxm_asc_pattern_channels_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_asc_sample_offset_fields[]={
 SX_FIELD("sample_relative_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxzxm_asc_sample_offset={UINT32_C(0x608A0019),"asc_sample_offset",sxzxm_asc_sample_offset_fields,SX_COUNT(sxzxm_asc_sample_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_asc_ornament_offset_fields[]={
 SX_FIELD("ornament_relative_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxzxm_asc_ornament_offset={UINT32_C(0x608A001A),"asc_ornament_offset",sxzxm_asc_ornament_offset_fields,SX_COUNT(sxzxm_asc_ornament_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_asc_sample_line_fields[]={
 SX_FIELD("loop_addition","uint8",0,1,SX_FLAGS),
 SX_FIELD("tone_deviation","int8",1,1,SX_NONE),
 SX_FIELD("level_masks","uint8",2,1,SX_FLAGS),
};
static const sx_layout sxzxm_asc_sample_line={UINT32_C(0x608A001B),"asc_sample_line",sxzxm_asc_sample_line_fields,SX_COUNT(sxzxm_asc_sample_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_asc_ornament_line_fields[]={
 SX_FIELD("loop_noise_offset","uint8",0,1,SX_FLAGS),
 SX_FIELD("note_offset","int8",1,1,SX_NONE),
};
static const sx_layout sxzxm_asc_ornament_line={UINT32_C(0x608A001C),"asc_ornament_line",sxzxm_asc_ornament_line_fields,SX_COUNT(sxzxm_asc_ornament_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_globaltracker_header_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("identifier","bytes",1,3,SX_NONE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("load_address","uint16",5,2,SX_ADDRESS),
 SX_FIELD("title","char[32]",7,32,SX_NONE),
};
static const sx_layout sxzxm_globaltracker_header={UINT32_C(0x608A001D),"globaltracker_header",sxzxm_globaltracker_header_fields,SX_COUNT(sxzxm_globaltracker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_globaltracker_positions_fields[]={
 SX_FIELD("position_count","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("loop_position","uint8",1,1,SX_NONE),
};
static const sx_layout sxzxm_globaltracker_positions={UINT32_C(0x608A001E),"globaltracker_positions",sxzxm_globaltracker_positions_fields,SX_COUNT(sxzxm_globaltracker_positions_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_globaltracker_position_fields[]={
 SX_FIELD("pattern_table_offset","uint8",0,1,SX_OFFSET),
};
static const sx_layout sxzxm_globaltracker_position={UINT32_C(0x608A001F),"globaltracker_position",sxzxm_globaltracker_position_fields,SX_COUNT(sxzxm_globaltracker_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_globaltracker_sample_fields[]={
 SX_FIELD("loop_byte_offset","uint8",0,1,SX_OFFSET),
 SX_FIELD("encoded_byte_size","uint8",1,1,SX_NONE),
};
static const sx_layout sxzxm_globaltracker_sample={UINT32_C(0x608A0020),"globaltracker_sample",sxzxm_globaltracker_sample_fields,SX_COUNT(sxzxm_globaltracker_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_globaltracker_sample_line_fields[]={
 SX_FIELD("level","uint8",0,1,SX_NONE),
 SX_FIELD("noise_flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("tone_deviation_bits","uint16",2,2,SX_NONE),
};
static const sx_layout sxzxm_globaltracker_sample_line={UINT32_C(0x608A0021),"globaltracker_sample_line",sxzxm_globaltracker_sample_line_fields,SX_COUNT(sxzxm_globaltracker_sample_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_fasttracker_header_fields[]={
 SX_FIELD("identifier","char[8]",0,8,SX_NONE),
 SX_FIELD("title","char[42]",8,42,SX_NONE),
 SX_FIELD("frequency_table","uint8",50,1,SX_ID),
 SX_FIELD("editor","char[18]",51,18,SX_NONE),
 SX_FIELD("tempo","uint8",69,1,SX_NONE),
 SX_FIELD("loop_position","uint8",70,1,SX_NONE),
 SX_FIELD("reserved_1","bytes",71,4,SX_RESERVED),
 SX_FIELD("patterns_offset","uint16",75,2,SX_OFFSET),
 SX_FIELD("reserved_2","bytes",77,5,SX_RESERVED),
};
static const sx_layout sxzxm_fasttracker_header={UINT32_C(0x608A0022),"fasttracker_header",sxzxm_fasttracker_header_fields,SX_COUNT(sxzxm_fasttracker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_fasttracker_position_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
 SX_FIELD("transposition","int8",1,1,SX_NONE),
};
static const sx_layout sxzxm_fasttracker_position={UINT32_C(0x608A0023),"fasttracker_position",sxzxm_fasttracker_position_fields,SX_COUNT(sxzxm_fasttracker_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_fasttracker_object_fields[]={
 SX_FIELD("last_line_index","uint8",0,1,SX_NONE),
 SX_FIELD("loop_index","uint8",1,1,SX_NONE),
 SX_FIELD("last_loop_line_index","uint8",2,1,SX_NONE),
};
static const sx_layout sxzxm_fasttracker_object={UINT32_C(0x608A0024),"fasttracker_object",sxzxm_fasttracker_object_fields,SX_COUNT(sxzxm_fasttracker_object_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_fasttracker_sample_line_fields[]={
 SX_FIELD("noise_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("tone_low","uint8",1,1,SX_NONE),
 SX_FIELD("tone_high_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("level_flags","uint8",3,1,SX_FLAGS),
 SX_FIELD("envelope_addition","int8",4,1,SX_NONE),
};
static const sx_layout sxzxm_fasttracker_sample_line={UINT32_C(0x608A0025),"fasttracker_sample_line",sxzxm_fasttracker_sample_line_fields,SX_COUNT(sxzxm_fasttracker_sample_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_fasttracker_ornament_line_fields[]={
 SX_FIELD("noise_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("note_addition","int8",1,1,SX_NONE),
};
static const sx_layout sxzxm_fasttracker_ornament_line={UINT32_C(0x608A0026),"fasttracker_ornament_line",sxzxm_fasttracker_ornament_line_fields,SX_COUNT(sxzxm_fasttracker_ornament_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_fasttracker_pattern_end_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_ID),
};
static const sx_layout sxzxm_fasttracker_pattern_end={UINT32_C(0x608A0027),"fasttracker_pattern_end",sxzxm_fasttracker_pattern_end_fields,SX_COUNT(sxzxm_fasttracker_pattern_end_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundcreator_header_fields[]={
 SX_FIELD("identifier","char[5]",0,5,SX_NONE),
 SX_FIELD("version","char[4]",5,4,SX_NONE),
 SX_FIELD("description","char[16]",9,16,SX_NONE),
 SX_FIELD("title","char[20]",25,20,SX_NONE),
 SX_FIELD("author_separator","char[4]",45,4,SX_NONE),
 SX_FIELD("author","char[20]",49,20,SX_NONE),
 SX_FIELD("samples_start","uint16",69,2,SX_OFFSET),
 SX_FIELD("positions_offset","uint16",71,2,SX_OFFSET),
 SX_FIELD("tempo","uint8",73,1,SX_NONE),
 SX_FIELD("ornaments_table_offset","uint16",74,2,SX_OFFSET),
};
static const sx_layout sxzxm_prosoundcreator_header={UINT32_C(0x608A0028),"prosoundcreator_header",sxzxm_prosoundcreator_header_fields,SX_COUNT(sxzxm_prosoundcreator_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundcreator_sample_ref_fields[]={
 SX_FIELD("sample_reference","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxzxm_prosoundcreator_sample_ref={UINT32_C(0x608A0029),"prosoundcreator_sample_ref",sxzxm_prosoundcreator_sample_ref_fields,SX_COUNT(sxzxm_prosoundcreator_sample_ref_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundcreator_ornament_ref_fields[]={
 SX_FIELD("ornament_reference","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxzxm_prosoundcreator_ornament_ref={UINT32_C(0x608A002A),"prosoundcreator_ornament_ref",sxzxm_prosoundcreator_ornament_ref_fields,SX_COUNT(sxzxm_prosoundcreator_ornament_ref_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundcreator_position_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
 SX_FIELD("line_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("channel_a_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("channel_b_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("channel_c_offset","uint16",6,2,SX_OFFSET),
};
static const sx_layout sxzxm_prosoundcreator_position={UINT32_C(0x608A002B),"prosoundcreator_position",sxzxm_prosoundcreator_position_fields,SX_COUNT(sxzxm_prosoundcreator_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundcreator_end_fields[]={
 SX_FIELD("loop_position","uint8",0,1,SX_NONE),
 SX_FIELD("marker","uint8",1,1,SX_ID),
};
static const sx_layout sxzxm_prosoundcreator_end={UINT32_C(0x608A002C),"prosoundcreator_end",sxzxm_prosoundcreator_end_fields,SX_COUNT(sxzxm_prosoundcreator_end_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundcreator_loop_fields[]={
 SX_FIELD("loop_pattern_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxzxm_prosoundcreator_loop={UINT32_C(0x608A002D),"prosoundcreator_loop",sxzxm_prosoundcreator_loop_fields,SX_COUNT(sxzxm_prosoundcreator_loop_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundcreator_sample_line_fields[]={
 SX_FIELD("tone","uint16",0,2,SX_NONE),
 SX_FIELD("addition","int8",2,1,SX_NONE),
 SX_FIELD("level","uint8",3,1,SX_NONE),
 SX_FIELD("flags","uint8",4,1,SX_FLAGS),
 SX_FIELD("padding","uint8",5,1,SX_RESERVED),
};
static const sx_layout sxzxm_prosoundcreator_sample_line={UINT32_C(0x608A002E),"prosoundcreator_sample_line",sxzxm_prosoundcreator_sample_line_fields,SX_COUNT(sxzxm_prosoundcreator_sample_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundcreator_ornament_line_fields[]={
 SX_FIELD("loop_noise","uint8",0,1,SX_FLAGS),
 SX_FIELD("note_offset","int8",1,1,SX_NONE),
};
static const sx_layout sxzxm_prosoundcreator_ornament_line={UINT32_C(0x608A002F),"prosoundcreator_ornament_line",sxzxm_prosoundcreator_ornament_line_fields,SX_COUNT(sxzxm_prosoundcreator_ornament_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundmaker_header_fields[]={
 SX_FIELD("positions_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("samples_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("ornaments_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("patterns_offset","uint16",6,2,SX_OFFSET),
};
static const sx_layout sxzxm_prosoundmaker_header={UINT32_C(0x608A0030),"prosoundmaker_header",sxzxm_prosoundmaker_header_fields,SX_COUNT(sxzxm_prosoundmaker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundmaker_position_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
 SX_FIELD("transposition_or_loop","uint8",1,1,SX_NONE),
};
static const sx_layout sxzxm_prosoundmaker_position={UINT32_C(0x608A0031),"prosoundmaker_position",sxzxm_prosoundmaker_position_fields,SX_COUNT(sxzxm_prosoundmaker_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundmaker_pattern_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("channel_a_offset","uint16",1,2,SX_OFFSET),
 SX_FIELD("channel_b_offset","uint16",3,2,SX_OFFSET),
 SX_FIELD("channel_c_offset","uint16",5,2,SX_OFFSET),
};
static const sx_layout sxzxm_prosoundmaker_pattern={UINT32_C(0x608A0032),"prosoundmaker_pattern",sxzxm_prosoundmaker_pattern_fields,SX_COUNT(sxzxm_prosoundmaker_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundmaker_sample_fields[]={
 SX_FIELD("size_volume_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("loop_repeat_flags","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxzxm_prosoundmaker_sample={UINT32_C(0x608A0033),"prosoundmaker_sample",sxzxm_prosoundmaker_sample_fields,SX_COUNT(sxzxm_prosoundmaker_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundmaker_sample_line_fields[]={
 SX_FIELD("level_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("noise_shift_high","uint8",1,1,SX_FLAGS),
 SX_FIELD("shift_low","uint8",2,1,SX_NONE),
};
static const sx_layout sxzxm_prosoundmaker_sample_line={UINT32_C(0x608A0034),"prosoundmaker_sample_line",sxzxm_prosoundmaker_sample_line_fields,SX_COUNT(sxzxm_prosoundmaker_sample_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundmaker_ornament_fields[]={
 SX_FIELD("last_line_index","uint8",0,1,SX_NONE),
 SX_FIELD("loop_flags","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxzxm_prosoundmaker_ornament={UINT32_C(0x608A0035),"prosoundmaker_ornament",sxzxm_prosoundmaker_ornament_fields,SX_COUNT(sxzxm_prosoundmaker_ornament_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stc_header_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("positions_offset","uint16",1,2,SX_OFFSET),
 SX_FIELD("ornaments_offset","uint16",3,2,SX_OFFSET),
 SX_FIELD("patterns_offset","uint16",5,2,SX_OFFSET),
 SX_FIELD("identifier","char[18]",7,18,SX_NONE),
 SX_FIELD("declared_size","uint16",25,2,SX_SIZE),
};
static const sx_layout sxzxm_stc_header={UINT32_C(0x608A0036),"stc_header",sxzxm_stc_header_fields,SX_COUNT(sxzxm_stc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stc_positions_fields[]={
 SX_FIELD("last_position_index","uint8",0,1,SX_NONE),
};
static const sx_layout sxzxm_stc_positions={UINT32_C(0x608A0037),"stc_positions",sxzxm_stc_positions_fields,SX_COUNT(sxzxm_stc_positions_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stc_position_fields[]={
 SX_FIELD("pattern_number","uint8",0,1,SX_NONE),
 SX_FIELD("transposition","int8",1,1,SX_NONE),
};
static const sx_layout sxzxm_stc_position={UINT32_C(0x608A0038),"stc_position",sxzxm_stc_position_fields,SX_COUNT(sxzxm_stc_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stc_pattern_fields[]={
 SX_FIELD("pattern_number","uint8",0,1,SX_NONE),
 SX_FIELD("channel_a_offset","uint16",1,2,SX_OFFSET),
 SX_FIELD("channel_b_offset","uint16",3,2,SX_OFFSET),
 SX_FIELD("channel_c_offset","uint16",5,2,SX_OFFSET),
};
static const sx_layout sxzxm_stc_pattern={UINT32_C(0x608A0039),"stc_pattern",sxzxm_stc_pattern_fields,SX_COUNT(sxzxm_stc_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stc_sample_prefix_fields[]={
 SX_FIELD("sample_number","uint8",0,1,SX_NONE),
};
static const sx_layout sxzxm_stc_sample_prefix={UINT32_C(0x608A003A),"stc_sample_prefix",sxzxm_stc_sample_prefix_fields,SX_COUNT(sxzxm_stc_sample_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stc_sample_line_fields[]={
 SX_FIELD("effect_high_volume","uint8",0,1,SX_FLAGS),
 SX_FIELD("noise_masks","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect_low","uint8",2,1,SX_NONE),
};
static const sx_layout sxzxm_stc_sample_line={UINT32_C(0x608A003B),"stc_sample_line",sxzxm_stc_sample_line_fields,SX_COUNT(sxzxm_stc_sample_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stc_sample_loop_fields[]={
 SX_FIELD("loop_index","uint8",0,1,SX_NONE),
 SX_FIELD("loop_length","uint8",1,1,SX_COUNT_PROP),
};
static const sx_layout sxzxm_stc_sample_loop={UINT32_C(0x608A003C),"stc_sample_loop",sxzxm_stc_sample_loop_fields,SX_COUNT(sxzxm_stc_sample_loop_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stc_ornament_prefix_fields[]={
 SX_FIELD("ornament_number","uint8",0,1,SX_NONE),
};
static const sx_layout sxzxm_stc_ornament_prefix={UINT32_C(0x608A003D),"stc_ornament_prefix",sxzxm_stc_ornament_prefix_fields,SX_COUNT(sxzxm_stc_ornament_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st3_header_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("positions_offset","uint16",1,2,SX_OFFSET),
 SX_FIELD("samples_offset","uint16",3,2,SX_OFFSET),
 SX_FIELD("ornaments_offset","uint16",5,2,SX_OFFSET),
 SX_FIELD("patterns_offset","uint16",7,2,SX_OFFSET),
};
static const sx_layout sxzxm_st3_header={UINT32_C(0x608A003E),"st3_header",sxzxm_st3_header_fields,SX_COUNT(sxzxm_st3_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st3_identity_fields[]={
 SX_FIELD("identifier","char[28]",0,28,SX_NONE),
 SX_FIELD("title","char[27]",28,27,SX_NONE),
};
static const sx_layout sxzxm_st3_identity={UINT32_C(0x608A003F),"st3_identity",sxzxm_st3_identity_fields,SX_COUNT(sxzxm_st3_identity_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st3_position_fields[]={
 SX_FIELD("transposition","int8",0,1,SX_NONE),
 SX_FIELD("pattern_table_offset","uint8",1,1,SX_OFFSET),
};
static const sx_layout sxzxm_st3_position={UINT32_C(0x608A0040),"st3_position",sxzxm_st3_position_fields,SX_COUNT(sxzxm_st3_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st3_object_table_fields[]={
 SX_FIELD("object_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxzxm_st3_object_table={UINT32_C(0x608A0041),"st3_object_table",sxzxm_st3_object_table_fields,SX_COUNT(sxzxm_st3_object_table_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st3_sample_fields[]={
 SX_FIELD("loop_index","uint8",0,1,SX_NONE),
 SX_FIELD("loop_length","uint8",1,1,SX_COUNT_PROP),
};
static const sx_layout sxzxm_st3_sample={UINT32_C(0x608A0042),"st3_sample",sxzxm_st3_sample_fields,SX_COUNT(sxzxm_st3_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st3_sample_line_fields[]={
 SX_FIELD("vibrato","int16",0,2,SX_NONE),
 SX_FIELD("level_mask","uint8",2,1,SX_FLAGS),
 SX_FIELD("noise","uint8",3,1,SX_NONE),
};
static const sx_layout sxzxm_st3_sample_line={UINT32_C(0x608A0043),"st3_sample_line",sxzxm_st3_sample_line_fields,SX_COUNT(sxzxm_st3_sample_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stp_header_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("positions_offset","uint16",1,2,SX_OFFSET),
 SX_FIELD("patterns_offset","uint16",3,2,SX_OFFSET),
 SX_FIELD("ornaments_offset","uint16",5,2,SX_OFFSET),
 SX_FIELD("samples_offset","uint16",7,2,SX_OFFSET),
 SX_FIELD("fixes_count","uint8",9,1,SX_COUNT_PROP),
};
static const sx_layout sxzxm_stp_header={UINT32_C(0x608A0044),"stp_header",sxzxm_stp_header_fields,SX_COUNT(sxzxm_stp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stp_identity_fields[]={
 SX_FIELD("identifier","char[28]",0,28,SX_NONE),
 SX_FIELD("title","char[25]",28,25,SX_NONE),
};
static const sx_layout sxzxm_stp_identity={UINT32_C(0x608A0045),"stp_identity",sxzxm_stp_identity_fields,SX_COUNT(sxzxm_stp_identity_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stp_positions_fields[]={
 SX_FIELD("position_count","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("loop_position","uint8",1,1,SX_NONE),
};
static const sx_layout sxzxm_stp_positions={UINT32_C(0x608A0046),"stp_positions",sxzxm_stp_positions_fields,SX_COUNT(sxzxm_stp_positions_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stp_position_fields[]={
 SX_FIELD("pattern_table_offset","uint8",0,1,SX_OFFSET),
 SX_FIELD("transposition","int8",1,1,SX_NONE),
};
static const sx_layout sxzxm_stp_position={UINT32_C(0x608A0047),"stp_position",sxzxm_stp_position_fields,SX_COUNT(sxzxm_stp_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stp_object_fields[]={
 SX_FIELD("loop_index","int8",0,1,SX_NONE),
 SX_FIELD("line_count","int8",1,1,SX_COUNT_PROP),
};
static const sx_layout sxzxm_stp_object={UINT32_C(0x608A0048),"stp_object",sxzxm_stp_object_fields,SX_COUNT(sxzxm_stp_object_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stp_sample_line_fields[]={
 SX_FIELD("level_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("noise_flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("vibrato","int16",2,2,SX_NONE),
};
static const sx_layout sxzxm_stp_sample_line={UINT32_C(0x608A0049),"stp_sample_line",sxzxm_stp_sample_line_fields,SX_COUNT(sxzxm_stp_sample_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_etracker_header_fields[]={
 SX_FIELD("positions_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("patterns_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("samples_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("ornaments_offset","uint16",6,2,SX_OFFSET),
 SX_FIELD("volume_decode_table_offset","uint16",8,2,SX_OFFSET),
 SX_FIELD("identifier","char[20]",10,20,SX_NONE),
};
static const sx_layout sxzxm_etracker_header={UINT32_C(0x608A004A),"etracker_header",sxzxm_etracker_header_fields,SX_COUNT(sxzxm_etracker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_etracker_pattern_fields[]={
 SX_FIELD("channel_0_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("channel_1_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("channel_2_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("channel_3_offset","uint16",6,2,SX_OFFSET),
 SX_FIELD("channel_4_offset","uint16",8,2,SX_OFFSET),
 SX_FIELD("channel_5_offset","uint16",10,2,SX_OFFSET),
};
static const sx_layout sxzxm_etracker_pattern={UINT32_C(0x608A004B),"etracker_pattern",sxzxm_etracker_pattern_fields,SX_COUNT(sxzxm_etracker_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_etracker_sample_offset_fields[]={
 SX_FIELD("sample_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxzxm_etracker_sample_offset={UINT32_C(0x608A004C),"etracker_sample_offset",sxzxm_etracker_sample_offset_fields,SX_COUNT(sxzxm_etracker_sample_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_etracker_ornament_offset_fields[]={
 SX_FIELD("ornament_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxzxm_etracker_ornament_offset={UINT32_C(0x608A004D),"etracker_ornament_offset",sxzxm_etracker_ornament_offset_fields,SX_COUNT(sxzxm_etracker_ornament_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_etracker_position_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
};
static const sx_layout sxzxm_etracker_position={UINT32_C(0x608A004E),"etracker_position",sxzxm_etracker_position_fields,SX_COUNT(sxzxm_etracker_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_chiptracker_header_fields[]={
 SX_FIELD("signature","char[5]",0,5,SX_NONE),
 SX_FIELD("version","char[3]",5,3,SX_NONE),
 SX_FIELD("title","char[32]",8,32,SX_NONE),
 SX_FIELD("tempo","uint8",40,1,SX_NONE),
 SX_FIELD("last_position_index","uint8",41,1,SX_NONE),
 SX_FIELD("loop_position","uint8",42,1,SX_NONE),
};
static const sx_layout sxzxm_chiptracker_header={UINT32_C(0x608A004F),"chiptracker_header",sxzxm_chiptracker_header_fields,SX_COUNT(sxzxm_chiptracker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_chiptracker_sample_fields[]={
 SX_FIELD("loop_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("byte_length","uint16",2,2,SX_SIZE),
};
static const sx_layout sxzxm_chiptracker_sample={UINT32_C(0x608A0050),"chiptracker_sample",sxzxm_chiptracker_sample_fields,SX_COUNT(sxzxm_chiptracker_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_chiptracker_sample_name_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_NONE),
};
static const sx_layout sxzxm_chiptracker_sample_name={UINT32_C(0x608A0051),"chiptracker_sample_name",sxzxm_chiptracker_sample_name_fields,SX_COUNT(sxzxm_chiptracker_sample_name_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_chiptracker_note_fields[]={
 SX_FIELD("note_command","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxzxm_chiptracker_note={UINT32_C(0x608A0052),"chiptracker_note",sxzxm_chiptracker_note_fields,SX_COUNT(sxzxm_chiptracker_note_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_chiptracker_parameter_fields[]={
 SX_FIELD("sample_parameter","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxzxm_chiptracker_parameter={UINT32_C(0x608A0053),"chiptracker_parameter",sxzxm_chiptracker_parameter_fields,SX_COUNT(sxzxm_chiptracker_parameter_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_dmm_header_fields[]={
 SX_FIELD("bank_0_end_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("bank_1_end_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("bank_2_end_address","uint16",4,2,SX_ADDRESS),
 SX_FIELD("bank_3_end_address","uint16",6,2,SX_ADDRESS),
 SX_FIELD("bank_4_end_address","uint16",8,2,SX_ADDRESS),
 SX_FIELD("bank_5_end_address","uint16",10,2,SX_ADDRESS),
 SX_FIELD("pattern_line_count","uint8",12,1,SX_COUNT_PROP),
 SX_FIELD("padding","uint8",13,1,SX_RESERVED),
};
static const sx_layout sxzxm_dmm_header={UINT32_C(0x608A0054),"dmm_header",sxzxm_dmm_header_fields,SX_COUNT(sxzxm_dmm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_dmm_playback_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("loop_position","uint8",1,1,SX_NONE),
 SX_FIELD("padding","uint8",2,1,SX_RESERVED),
 SX_FIELD("last_position_index","uint8",3,1,SX_NONE),
 SX_FIELD("header_sectors","uint8",4,1,SX_NONE),
};
static const sx_layout sxzxm_dmm_playback={UINT32_C(0x608A0055),"dmm_playback",sxzxm_dmm_playback_fields,SX_COUNT(sxzxm_dmm_playback_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_dmm_mixing_fields[]={
 SX_FIELD("note_command","uint8",0,1,SX_FLAGS),
 SX_FIELD("sample_parameter","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect","uint8",2,1,SX_NONE),
 SX_FIELD("period","uint8",3,1,SX_NONE),
};
static const sx_layout sxzxm_dmm_mixing={UINT32_C(0x608A0056),"dmm_mixing",sxzxm_dmm_mixing_fields,SX_COUNT(sxzxm_dmm_mixing_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_dmm_sample_fields[]={
 SX_FIELD("name","char[9]",0,9,SX_NONE),
 SX_FIELD("start_address","uint16",9,2,SX_ADDRESS),
 SX_FIELD("bank","uint8",11,1,SX_ID),
 SX_FIELD("limit_address","uint16",12,2,SX_ADDRESS),
 SX_FIELD("loop_address","uint16",14,2,SX_ADDRESS),
};
static const sx_layout sxzxm_dmm_sample={UINT32_C(0x608A0057),"dmm_sample",sxzxm_dmm_sample_fields,SX_COUNT(sxzxm_dmm_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_dmm_event_fields[]={
 SX_FIELD("note_command","uint8",0,1,SX_FLAGS),
 SX_FIELD("sample_parameter","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect","uint8",2,1,SX_NONE),
};
static const sx_layout sxzxm_dmm_event={UINT32_C(0x608A0058),"dmm_event",sxzxm_dmm_event_fields,SX_COUNT(sxzxm_dmm_event_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_sqd_layout_fields[]={
 SX_FIELD("address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("bank","uint8",2,1,SX_ID),
 SX_FIELD("sector_count","uint8",3,1,SX_COUNT_PROP),
};
static const sx_layout sxzxm_sqd_layout={UINT32_C(0x608A0059),"sqd_layout",sxzxm_sqd_layout_fields,SX_COUNT(sxzxm_sqd_layout_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_sqd_sample_fields[]={
 SX_FIELD("start_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("loop_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("is_looped","uint8",4,1,SX_FLAGS),
 SX_FIELD("bank","uint8",5,1,SX_ID),
 SX_FIELD("padding","bytes",6,2,SX_RESERVED),
};
static const sx_layout sxzxm_sqd_sample={UINT32_C(0x608A005A),"sqd_sample",sxzxm_sqd_sample_fields,SX_COUNT(sxzxm_sqd_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_sqd_title_fields[]={
 SX_FIELD("title","char[32]",0,32,SX_NONE),
};
static const sx_layout sxzxm_sqd_title={UINT32_C(0x608A005B),"sqd_title",sxzxm_sqd_title_fields,SX_COUNT(sxzxm_sqd_title_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_sqd_positions_limit_fields[]={
 SX_FIELD("positions_limit","uint8",0,1,SX_NONE),
};
static const sx_layout sxzxm_sqd_positions_limit={UINT32_C(0x608A005C),"sqd_positions_limit",sxzxm_sqd_positions_limit_fields,SX_COUNT(sxzxm_sqd_positions_limit_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_sqd_playback_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("loop_position","uint8",1,1,SX_NONE),
 SX_FIELD("last_position_index","uint8",2,1,SX_NONE),
};
static const sx_layout sxzxm_sqd_playback={UINT32_C(0x608A005D),"sqd_playback",sxzxm_sqd_playback_fields,SX_COUNT(sxzxm_sqd_playback_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_sqd_event_fields[]={
 SX_FIELD("note_command","uint8",0,1,SX_FLAGS),
 SX_FIELD("sample_volume","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxzxm_sqd_event={UINT32_C(0x608A005E),"sqd_event",sxzxm_sqd_event_fields,SX_COUNT(sxzxm_sqd_event_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_ayst11_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_NONE),
 SX_FIELD("subtype","char[4]",4,4,SX_NONE),
 SX_FIELD("file_version","uint8",8,1,SX_ID),
 SX_FIELD("player_version","uint8",9,1,SX_ID),
 SX_FIELD("special_player_delta","int16",10,2,SX_OFFSET),
 SX_FIELD("author_delta","int16",12,2,SX_OFFSET),
 SX_FIELD("miscellaneous_delta","int16",14,2,SX_OFFSET),
 SX_FIELD("last_song_index","uint8",16,1,SX_NONE),
 SX_FIELD("first_song_index","uint8",17,1,SX_NONE),
 SX_FIELD("songs_delta","int16",18,2,SX_OFFSET),
};
static const sx_layout sxzxm_ayst11_header={UINT32_C(0x608A005F),"ayst11_header",sxzxm_ayst11_header_fields,SX_COUNT(sxzxm_ayst11_header_fields),SX_BE};
static const xx_data_struct_field_desc sxzxm_ayst11_song_fields[]={
 SX_FIELD("name_delta","int16",0,2,SX_OFFSET),
 SX_FIELD("data_delta","int16",2,2,SX_OFFSET),
};
static const sx_layout sxzxm_ayst11_song={UINT32_C(0x608A0060),"ayst11_song",sxzxm_ayst11_song_fields,SX_COUNT(sxzxm_ayst11_song_fields),SX_BE};
static const xx_data_struct_field_desc sxzxm_ayst11_song_data_fields[]={
 SX_FIELD("channel_a","uint8",0,1,SX_ID),
 SX_FIELD("channel_b","uint8",1,1,SX_ID),
 SX_FIELD("channel_c","uint8",2,1,SX_ID),
 SX_FIELD("noise_channel","uint8",3,1,SX_ID),
 SX_FIELD("opaque","bytes",4,4,SX_NONE),
};
static const sx_layout sxzxm_ayst11_song_data={UINT32_C(0x608A0061),"ayst11_song_data",sxzxm_ayst11_song_data_fields,SX_COUNT(sxzxm_ayst11_song_data_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st1_sample_fields[]={
 SX_FIELD("volume_00","uint8",0,1,SX_NONE),
 SX_FIELD("volume_01","uint8",1,1,SX_NONE),
 SX_FIELD("volume_02","uint8",2,1,SX_NONE),
 SX_FIELD("volume_03","uint8",3,1,SX_NONE),
 SX_FIELD("volume_04","uint8",4,1,SX_NONE),
 SX_FIELD("volume_05","uint8",5,1,SX_NONE),
 SX_FIELD("volume_06","uint8",6,1,SX_NONE),
 SX_FIELD("volume_07","uint8",7,1,SX_NONE),
 SX_FIELD("volume_08","uint8",8,1,SX_NONE),
 SX_FIELD("volume_09","uint8",9,1,SX_NONE),
 SX_FIELD("volume_10","uint8",10,1,SX_NONE),
 SX_FIELD("volume_11","uint8",11,1,SX_NONE),
 SX_FIELD("volume_12","uint8",12,1,SX_NONE),
 SX_FIELD("volume_13","uint8",13,1,SX_NONE),
 SX_FIELD("volume_14","uint8",14,1,SX_NONE),
 SX_FIELD("volume_15","uint8",15,1,SX_NONE),
 SX_FIELD("volume_16","uint8",16,1,SX_NONE),
 SX_FIELD("volume_17","uint8",17,1,SX_NONE),
 SX_FIELD("volume_18","uint8",18,1,SX_NONE),
 SX_FIELD("volume_19","uint8",19,1,SX_NONE),
 SX_FIELD("volume_20","uint8",20,1,SX_NONE),
 SX_FIELD("volume_21","uint8",21,1,SX_NONE),
 SX_FIELD("volume_22","uint8",22,1,SX_NONE),
 SX_FIELD("volume_23","uint8",23,1,SX_NONE),
 SX_FIELD("volume_24","uint8",24,1,SX_NONE),
 SX_FIELD("volume_25","uint8",25,1,SX_NONE),
 SX_FIELD("volume_26","uint8",26,1,SX_NONE),
 SX_FIELD("volume_27","uint8",27,1,SX_NONE),
 SX_FIELD("volume_28","uint8",28,1,SX_NONE),
 SX_FIELD("volume_29","uint8",29,1,SX_NONE),
 SX_FIELD("volume_30","uint8",30,1,SX_NONE),
 SX_FIELD("volume_31","uint8",31,1,SX_NONE),
 SX_FIELD("noise_00","uint8",32,1,SX_NONE),
 SX_FIELD("noise_01","uint8",33,1,SX_NONE),
 SX_FIELD("noise_02","uint8",34,1,SX_NONE),
 SX_FIELD("noise_03","uint8",35,1,SX_NONE),
 SX_FIELD("noise_04","uint8",36,1,SX_NONE),
 SX_FIELD("noise_05","uint8",37,1,SX_NONE),
 SX_FIELD("noise_06","uint8",38,1,SX_NONE),
 SX_FIELD("noise_07","uint8",39,1,SX_NONE),
 SX_FIELD("noise_08","uint8",40,1,SX_NONE),
 SX_FIELD("noise_09","uint8",41,1,SX_NONE),
 SX_FIELD("noise_10","uint8",42,1,SX_NONE),
 SX_FIELD("noise_11","uint8",43,1,SX_NONE),
 SX_FIELD("noise_12","uint8",44,1,SX_NONE),
 SX_FIELD("noise_13","uint8",45,1,SX_NONE),
 SX_FIELD("noise_14","uint8",46,1,SX_NONE),
 SX_FIELD("noise_15","uint8",47,1,SX_NONE),
 SX_FIELD("noise_16","uint8",48,1,SX_NONE),
 SX_FIELD("noise_17","uint8",49,1,SX_NONE),
 SX_FIELD("noise_18","uint8",50,1,SX_NONE),
 SX_FIELD("noise_19","uint8",51,1,SX_NONE),
 SX_FIELD("noise_20","uint8",52,1,SX_NONE),
 SX_FIELD("noise_21","uint8",53,1,SX_NONE),
 SX_FIELD("noise_22","uint8",54,1,SX_NONE),
 SX_FIELD("noise_23","uint8",55,1,SX_NONE),
 SX_FIELD("noise_24","uint8",56,1,SX_NONE),
 SX_FIELD("noise_25","uint8",57,1,SX_NONE),
 SX_FIELD("noise_26","uint8",58,1,SX_NONE),
 SX_FIELD("noise_27","uint8",59,1,SX_NONE),
 SX_FIELD("noise_28","uint8",60,1,SX_NONE),
 SX_FIELD("noise_29","uint8",61,1,SX_NONE),
 SX_FIELD("noise_30","uint8",62,1,SX_NONE),
 SX_FIELD("noise_31","uint8",63,1,SX_NONE),
 SX_FIELD("effect_00","uint16",64,2,SX_NONE),
 SX_FIELD("effect_01","uint16",66,2,SX_NONE),
 SX_FIELD("effect_02","uint16",68,2,SX_NONE),
 SX_FIELD("effect_03","uint16",70,2,SX_NONE),
 SX_FIELD("effect_04","uint16",72,2,SX_NONE),
 SX_FIELD("effect_05","uint16",74,2,SX_NONE),
 SX_FIELD("effect_06","uint16",76,2,SX_NONE),
 SX_FIELD("effect_07","uint16",78,2,SX_NONE),
 SX_FIELD("effect_08","uint16",80,2,SX_NONE),
 SX_FIELD("effect_09","uint16",82,2,SX_NONE),
 SX_FIELD("effect_10","uint16",84,2,SX_NONE),
 SX_FIELD("effect_11","uint16",86,2,SX_NONE),
 SX_FIELD("effect_12","uint16",88,2,SX_NONE),
 SX_FIELD("effect_13","uint16",90,2,SX_NONE),
 SX_FIELD("effect_14","uint16",92,2,SX_NONE),
 SX_FIELD("effect_15","uint16",94,2,SX_NONE),
 SX_FIELD("effect_16","uint16",96,2,SX_NONE),
 SX_FIELD("effect_17","uint16",98,2,SX_NONE),
 SX_FIELD("effect_18","uint16",100,2,SX_NONE),
 SX_FIELD("effect_19","uint16",102,2,SX_NONE),
 SX_FIELD("effect_20","uint16",104,2,SX_NONE),
 SX_FIELD("effect_21","uint16",106,2,SX_NONE),
 SX_FIELD("effect_22","uint16",108,2,SX_NONE),
 SX_FIELD("effect_23","uint16",110,2,SX_NONE),
 SX_FIELD("effect_24","uint16",112,2,SX_NONE),
 SX_FIELD("effect_25","uint16",114,2,SX_NONE),
 SX_FIELD("effect_26","uint16",116,2,SX_NONE),
 SX_FIELD("effect_27","uint16",118,2,SX_NONE),
 SX_FIELD("effect_28","uint16",120,2,SX_NONE),
 SX_FIELD("effect_29","uint16",122,2,SX_NONE),
 SX_FIELD("effect_30","uint16",124,2,SX_NONE),
 SX_FIELD("effect_31","uint16",126,2,SX_NONE),
 SX_FIELD("loop_index","uint8",128,1,SX_NONE),
 SX_FIELD("loop_length","uint8",129,1,SX_COUNT_PROP),
};
static const sx_layout sxzxm_st1_sample={UINT32_C(0x608A0062),"st1_sample",sxzxm_st1_sample_fields,SX_COUNT(sxzxm_st1_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st1_position_fields[]={
 SX_FIELD("pattern_number","uint8",0,1,SX_NONE),
 SX_FIELD("transposition","int8",1,1,SX_NONE),
};
static const sx_layout sxzxm_st1_position={UINT32_C(0x608A0063),"st1_position",sxzxm_st1_position_fields,SX_COUNT(sxzxm_st1_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st1_song_length_fields[]={
 SX_FIELD("song_length","uint8",0,1,SX_NONE),
};
static const sx_layout sxzxm_st1_song_length={UINT32_C(0x608A0064),"st1_song_length",sxzxm_st1_song_length_fields,SX_COUNT(sxzxm_st1_song_length_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st1_ornament_step_fields[]={
 SX_FIELD("encoded_pitch","uint8",0,1,SX_NONE),
};
static const sx_layout sxzxm_st1_ornament_step={UINT32_C(0x608A0065),"st1_ornament_step",sxzxm_st1_ornament_step_fields,SX_COUNT(sxzxm_st1_ornament_step_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st1_playback_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("pattern_row_count","uint8",1,1,SX_COUNT_PROP),
};
static const sx_layout sxzxm_st1_playback={UINT32_C(0x608A0066),"st1_playback",sxzxm_st1_playback_fields,SX_COUNT(sxzxm_st1_playback_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_rmt_binary_header_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_ID),
 SX_FIELD("load_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("end_address","uint16",4,2,SX_ADDRESS),
};
static const sx_layout sxzxm_rmt_binary_header={UINT32_C(0x608A0067),"rmt_binary_header",sxzxm_rmt_binary_header_fields,SX_COUNT(sxzxm_rmt_binary_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_rmt_binary_segment_fields[]={
 SX_FIELD("load_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("end_address","uint16",2,2,SX_ADDRESS),
};
static const sx_layout sxzxm_rmt_binary_segment={UINT32_C(0x608A0068),"rmt_binary_segment",sxzxm_rmt_binary_segment_fields,SX_COUNT(sxzxm_rmt_binary_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_rmt_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_NONE),
 SX_FIELD("encoded_track_length","uint8",4,1,SX_NONE),
 SX_FIELD("song_speed","uint8",5,1,SX_NONE),
 SX_FIELD("player_frequency","uint8",6,1,SX_NONE),
 SX_FIELD("version","uint8",7,1,SX_ID),
 SX_FIELD("instruments_address","uint16",8,2,SX_ADDRESS),
 SX_FIELD("tracks_low_address","uint16",10,2,SX_ADDRESS),
 SX_FIELD("tracks_high_address","uint16",12,2,SX_ADDRESS),
 SX_FIELD("song_address","uint16",14,2,SX_ADDRESS),
};
static const sx_layout sxzxm_rmt_header={UINT32_C(0x608A0069),"rmt_header",sxzxm_rmt_header_fields,SX_COUNT(sxzxm_rmt_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_rmt_instrument_address_fields[]={
 SX_FIELD("instrument_address","uint16",0,2,SX_ADDRESS),
};
static const sx_layout sxzxm_rmt_instrument_address={UINT32_C(0x608A006A),"rmt_instrument_address",sxzxm_rmt_instrument_address_fields,SX_COUNT(sxzxm_rmt_instrument_address_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_rmt_track_low_fields[]={
 SX_FIELD("track_address_low","uint8",0,1,SX_NONE),
};
static const sx_layout sxzxm_rmt_track_low={UINT32_C(0x608A006B),"rmt_track_low",sxzxm_rmt_track_low_fields,SX_COUNT(sxzxm_rmt_track_low_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_rmt_track_high_fields[]={
 SX_FIELD("track_address_high","uint8",0,1,SX_NONE),
};
static const sx_layout sxzxm_rmt_track_high={UINT32_C(0x608A006C),"rmt_track_high",sxzxm_rmt_track_high_fields,SX_COUNT(sxzxm_rmt_track_high_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_rmt_instrument_fields[]={
 SX_FIELD("note_table_end","uint8",0,1,SX_OFFSET),
 SX_FIELD("note_table_loop","uint8",1,1,SX_OFFSET),
 SX_FIELD("envelope_end","uint8",2,1,SX_OFFSET),
 SX_FIELD("envelope_loop","uint8",3,1,SX_OFFSET),
 SX_FIELD("table_speed_flags","uint8",4,1,SX_FLAGS),
 SX_FIELD("audctl","uint8",5,1,SX_FLAGS),
 SX_FIELD("volume_slide","uint8",6,1,SX_NONE),
 SX_FIELD("minimum_volume_flags","uint8",7,1,SX_FLAGS),
 SX_FIELD("modulation_delay","uint8",8,1,SX_NONE),
 SX_FIELD("vibrato","uint8",9,1,SX_ID),
 SX_FIELD("frequency_shift","uint8",10,1,SX_NONE),
 SX_FIELD("unused","uint8",11,1,SX_RESERVED),
};
static const sx_layout sxzxm_rmt_instrument={UINT32_C(0x608A006D),"rmt_instrument",sxzxm_rmt_instrument_fields,SX_COUNT(sxzxm_rmt_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_digitalstudio_order_fields[]={
 SX_FIELD("loop_position","uint8",0,1,SX_NONE),
};
static const sx_layout sxzxm_digitalstudio_order={UINT32_C(0x608A006E),"digitalstudio_order",sxzxm_digitalstudio_order_fields,SX_COUNT(sxzxm_digitalstudio_order_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_digitalstudio_header_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("position_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("title","char[28]",2,28,SX_NONE),
 SX_FIELD("unknown","bytes",30,70,SX_NONE),
 SX_FIELD("compiled_marker_area","bytes",100,56,SX_NONE),
};
static const sx_layout sxzxm_digitalstudio_header={UINT32_C(0x608A006F),"digitalstudio_header",sxzxm_digitalstudio_header_fields,SX_COUNT(sxzxm_digitalstudio_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_digitalstudio_sample_fields[]={
 SX_FIELD("start_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("loop_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("page","uint8",4,1,SX_ID),
 SX_FIELD("index_in_bank","uint8",5,1,SX_NONE),
 SX_FIELD("byte_size","uint16",6,2,SX_SIZE),
 SX_FIELD("name","char[8]",8,8,SX_NONE),
};
static const sx_layout sxzxm_digitalstudio_sample={UINT32_C(0x608A0070),"digitalstudio_sample",sxzxm_digitalstudio_sample_fields,SX_COUNT(sxzxm_digitalstudio_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_digitalstudio_event_fields[]={
 SX_FIELD("note_or_command","uint8",0,1,SX_ID),
 SX_FIELD("sample_or_parameter","uint8",1,1,SX_NONE),
};
static const sx_layout sxzxm_digitalstudio_event={UINT32_C(0x608A0071),"digitalstudio_event",sxzxm_digitalstudio_event_fields,SX_COUNT(sxzxm_digitalstudio_event_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_extremetracker_header_fields[]={
 SX_FIELD("loop_position","uint8",0,1,SX_NONE),
 SX_FIELD("tempo","uint8",1,1,SX_NONE),
 SX_FIELD("position_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("title","char[30]",3,30,SX_NONE),
 SX_FIELD("unknown","uint8",33,1,SX_NONE),
};
static const sx_layout sxzxm_extremetracker_header={UINT32_C(0x608A0072),"extremetracker_header",sxzxm_extremetracker_header_fields,SX_COUNT(sxzxm_extremetracker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_extremetracker_pattern_size_fields[]={
 SX_FIELD("row_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxzxm_extremetracker_pattern_size={UINT32_C(0x608A0073),"extremetracker_pattern_size",sxzxm_extremetracker_pattern_size_fields,SX_COUNT(sxzxm_extremetracker_pattern_size_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_extremetracker_memory_fields[]={
 SX_FIELD("rest_blocks","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("page","uint8",1,1,SX_ID),
 SX_FIELD("free_start_block","uint8",2,1,SX_NONE),
 SX_FIELD("sample_count","uint8",3,1,SX_COUNT_PROP),
};
static const sx_layout sxzxm_extremetracker_memory={UINT32_C(0x608A0074),"extremetracker_memory",sxzxm_extremetracker_memory_fields,SX_COUNT(sxzxm_extremetracker_memory_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_extremetracker_sample_fields[]={
 SX_FIELD("start_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("loop_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("page","uint8",4,1,SX_ID),
 SX_FIELD("index_in_page","uint8",5,1,SX_NONE),
 SX_FIELD("block_count","uint8",6,1,SX_COUNT_PROP),
 SX_FIELD("padding","uint8",7,1,SX_NONE),
 SX_FIELD("name","char[8]",8,8,SX_NONE),
};
static const sx_layout sxzxm_extremetracker_sample={UINT32_C(0x608A0075),"extremetracker_sample",sxzxm_extremetracker_sample_fields,SX_COUNT(sxzxm_extremetracker_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_extremetracker_event_fields[]={
 SX_FIELD("note_command","uint8",0,1,SX_FLAGS),
 SX_FIELD("sample_parameter","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxzxm_extremetracker_event={UINT32_C(0x608A0076),"extremetracker_event",sxzxm_extremetracker_event_fields,SX_COUNT(sxzxm_extremetracker_event_fields),SX_LE};
static const sx_layout *const sx_zxmusic_layouts[]={
 &sxzxm_zx_position,
 &sxzxm_zx_ornament_step,
 &sxzxm_zx_sample_offset,
 &sxzxm_zx_ornament_offset,
 &sxzxm_zx_sample_address,
 &sxzxm_zx_ornament_address,
 &sxzxm_zx_pattern_channels,
 &sxzxm_zx_pattern_addresses,
 &sxzxm_zx_positions_count,
 &sxzxm_zx_object_size_loop,
 &sxzxm_zx_object_loop_size,
 &sxzxm_zx_marker,
 &sxzxm_zx_text,
 &sxzxm_pt1_header,
 &sxzxm_pt2_header,
 &sxzxm_pt1_sample_line,
 &sxzxm_pt2_sample_line,
 &sxzxm_pt3_header,
 &sxzxm_pt3_position,
 &sxzxm_pt3_sample_line,
 &sxzxm_asc0_header,
 &sxzxm_asc1_header,
 &sxzxm_asc_identity,
 &sxzxm_asc_pattern_channels,
 &sxzxm_asc_sample_offset,
 &sxzxm_asc_ornament_offset,
 &sxzxm_asc_sample_line,
 &sxzxm_asc_ornament_line,
 &sxzxm_globaltracker_header,
 &sxzxm_globaltracker_positions,
 &sxzxm_globaltracker_position,
 &sxzxm_globaltracker_sample,
 &sxzxm_globaltracker_sample_line,
 &sxzxm_fasttracker_header,
 &sxzxm_fasttracker_position,
 &sxzxm_fasttracker_object,
 &sxzxm_fasttracker_sample_line,
 &sxzxm_fasttracker_ornament_line,
 &sxzxm_fasttracker_pattern_end,
 &sxzxm_prosoundcreator_header,
 &sxzxm_prosoundcreator_sample_ref,
 &sxzxm_prosoundcreator_ornament_ref,
 &sxzxm_prosoundcreator_position,
 &sxzxm_prosoundcreator_end,
 &sxzxm_prosoundcreator_loop,
 &sxzxm_prosoundcreator_sample_line,
 &sxzxm_prosoundcreator_ornament_line,
 &sxzxm_prosoundmaker_header,
 &sxzxm_prosoundmaker_position,
 &sxzxm_prosoundmaker_pattern,
 &sxzxm_prosoundmaker_sample,
 &sxzxm_prosoundmaker_sample_line,
 &sxzxm_prosoundmaker_ornament,
 &sxzxm_stc_header,
 &sxzxm_stc_positions,
 &sxzxm_stc_position,
 &sxzxm_stc_pattern,
 &sxzxm_stc_sample_prefix,
 &sxzxm_stc_sample_line,
 &sxzxm_stc_sample_loop,
 &sxzxm_stc_ornament_prefix,
 &sxzxm_st3_header,
 &sxzxm_st3_identity,
 &sxzxm_st3_position,
 &sxzxm_st3_object_table,
 &sxzxm_st3_sample,
 &sxzxm_st3_sample_line,
 &sxzxm_stp_header,
 &sxzxm_stp_identity,
 &sxzxm_stp_positions,
 &sxzxm_stp_position,
 &sxzxm_stp_object,
 &sxzxm_stp_sample_line,
 &sxzxm_etracker_header,
 &sxzxm_etracker_pattern,
 &sxzxm_etracker_sample_offset,
 &sxzxm_etracker_ornament_offset,
 &sxzxm_etracker_position,
 &sxzxm_chiptracker_header,
 &sxzxm_chiptracker_sample,
 &sxzxm_chiptracker_sample_name,
 &sxzxm_chiptracker_note,
 &sxzxm_chiptracker_parameter,
 &sxzxm_dmm_header,
 &sxzxm_dmm_playback,
 &sxzxm_dmm_mixing,
 &sxzxm_dmm_sample,
 &sxzxm_dmm_event,
 &sxzxm_sqd_layout,
 &sxzxm_sqd_sample,
 &sxzxm_sqd_title,
 &sxzxm_sqd_positions_limit,
 &sxzxm_sqd_playback,
 &sxzxm_sqd_event,
 &sxzxm_ayst11_header,
 &sxzxm_ayst11_song,
 &sxzxm_ayst11_song_data,
 &sxzxm_st1_sample,
 &sxzxm_st1_position,
 &sxzxm_st1_song_length,
 &sxzxm_st1_ornament_step,
 &sxzxm_st1_playback,
 &sxzxm_rmt_binary_header,
 &sxzxm_rmt_binary_segment,
 &sxzxm_rmt_header,
 &sxzxm_rmt_instrument_address,
 &sxzxm_rmt_track_low,
 &sxzxm_rmt_track_high,
 &sxzxm_rmt_instrument,
 &sxzxm_digitalstudio_order,
 &sxzxm_digitalstudio_header,
 &sxzxm_digitalstudio_sample,
 &sxzxm_digitalstudio_event,
 &sxzxm_extremetracker_header,
 &sxzxm_extremetracker_pattern_size,
 &sxzxm_extremetracker_memory,
 &sxzxm_extremetracker_sample,
 &sxzxm_extremetracker_event,
};
#define SXZXM_LIMIT 24000U
static bool sxzxm_span(sx_context*c,uint64_t p,uint64_t n){return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
static bool sxzxm_read(sx_context*c,uint64_t p,void*b,size_t n){return sxzxm_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint16_t sxzxm16(const uint8_t*b){return (uint16_t)b[0]|(uint16_t)((uint16_t)b[1]<<8);}
static bool sxzxm_u16(sx_context*c,uint64_t p,uint16_t*v){uint8_t b[2];if(!sxzxm_read(c,p,b,2))return false;*v=sxzxm16(b);return true;}
static bool sxzxm_u8(sx_context*c,uint64_t p,uint8_t*v){return sxzxm_read(c,p,v,1);}
static bool sxzxm_eq(sx_context*c,uint64_t p,const char*s,size_t n){uint8_t b[64];return n<=sizeof(b)&&sxzxm_read(c,p,b,n)&&!xx_rt_memcmp(b,s,n);}
static uint64_t sxzxm_width(const sx_layout*l){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;return (uint64_t)f->rel_offset+(uint64_t)f->size;}
/* Insert only disjoint physical records. Shared pointers are decoded once;
 * conflicting interpretations remain covered by the first authenticated row.
 * Display-budget exhaustion retains earlier metadata and raw remainder. */
static bool sxzxm_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){
 uint64_t z=sxzxm_width(l);if(!count)return true;if(!z||count>UINT64_MAX/z||!sxzxm_span(c,p,count*z))return false;
 if(c->count>=SXZXM_LIMIT)return true;
 uint64_t end=p+count*z;
 for(size_t i=0;i<c->count;i++){int64_t rel=c->items[i].offset-c->f->base_address;uint64_t n=(uint64_t)c->items[i].total_size;
  if(rel>=0&&p<(uint64_t)rel+n&&(uint64_t)rel<end)return true;}
 return count==1?sx_add(c,l,(int64_t)p,(int64_t)z):sx_table(c,l,(int64_t)p,(int64_t)z,(int64_t)count);
}
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
static bool sxzxm_opt(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){uint64_t z=sxzxm_width(l);return !count||!z||count>UINT64_MAX/z||!sxzxm_span(c,p,count*z)?true:sxzxm_put(c,l,p,count);}
static int sxzxm_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset;}
static bool sxzxm_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxzxm_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end||z<=0||p>c->size||z>c->size-p)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxzxm_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
/* Strings have dynamic physical width but share a genuine string-field layout. */
static bool sxzxm_string(sx_context*c,uint64_t p){uint8_t ch;uint64_t n=0;while(n<4096&&sxzxm_u8(c,p+n,&ch)){n++;if(!ch){if(c->count>=SXZXM_LIMIT)return true;for(size_t i=0;i<c->count;i++){uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<a+z&&a<p+n)return true;}return sx_add(c,&sxzxm_zx_text,(int64_t)p,(int64_t)n);}}return true;}
static bool sxzxm_lines(sx_context*c,const sx_layout*l,uint64_t p,unsigned count){return sxzxm_opt(c,l,p,count);}
/* Instrument lists carry absolute module offsets unless a caller supplies an
 * explicit relative-table or target-memory base. Never modify stored values. */
static bool sxzxm_object(sx_context*c,uint64_t p,unsigned kind){
 uint8_t h[3];if(!p||!sxzxm_read(c,p,h,kind==6?3:2))return true;
 const sx_layout*head=&sxzxm_zx_object_size_loop,*line=&sxzxm_pt1_sample_line;unsigned count=h[0];
 switch(kind){
 case 0:count=count>85?85:count;break; /* PT1 */
 case 1:line=&sxzxm_pt2_sample_line;count=count>85?85:count;break;
 case 2:head=&sxzxm_zx_object_loop_size;line=&sxzxm_pt3_sample_line;count=h[1]>64?64:h[1];break;
 case 3:line=&sxzxm_zx_ornament_step;break; /* size,loop */
 case 4:head=&sxzxm_zx_object_loop_size;line=&sxzxm_zx_ornament_step;count=h[1];break;
 case 5:head=&sxzxm_globaltracker_sample;line=&sxzxm_globaltracker_sample_line;count=(h[1]?h[1]:256)/4;break;
 case 6:head=&sxzxm_fasttracker_object;line=&sxzxm_fasttracker_sample_line;count=(unsigned)h[0]+1;break;
 case 7:if(!sxzxm_read(c,p,h,3))return true;head=&sxzxm_fasttracker_object;line=&sxzxm_fasttracker_ornament_line;count=(unsigned)h[0]+1;break;
 case 8:head=&sxzxm_prosoundmaker_sample;line=&sxzxm_prosoundmaker_sample_line;count=(h[0]&31)+1;break;
 case 9:head=&sxzxm_prosoundmaker_ornament;line=&sxzxm_zx_ornament_step;count=(unsigned)h[0]+1;break;
 case 10:head=&sxzxm_stp_object;line=&sxzxm_stp_sample_line;count=h[1]<128?h[1]:0;if(count>64)count=64;break;
 case 11:head=&sxzxm_stp_object;line=&sxzxm_zx_ornament_step;count=h[1]<128?h[1]:0;break;
 }
 return sxzxm_put(c,head,p,1)&&sxzxm_lines(c,line,p+sxzxm_width(head),count);
}
static bool sxzxm_pt(sx_context*c,unsigned version){
 unsigned hs=version==1?99:version==2?131:201,sc=version==1?16:32,sp=version==3?105:3,op=sp+2*sc,pp=version==3?103:op+32;
 const sx_layout*header=version==1?&sxzxm_pt1_header:version==2?&sxzxm_pt2_header:&sxzxm_pt3_header;
 if(!sxzxm_put(c,header,0,1))return false;
 uint16_t pt;if(!sxzxm_u16(c,pp,&pt))return true;unsigned patterns=0,n=0;uint8_t value;
 for(;n<256&&sxzxm_u8(c,hs+n,&value);n++){
  if(value==255){if(!SXZXM_ADD(c,zx_marker,hs+n))return false;break;}
  if(version==3&&value%3)break;unsigned pat=version==3?value/3:value;if(pat>=(version==3?85U:32U))break;if(pat+1>patterns)patterns=pat+1;
 }
 if(!sxzxm_opt(c,version==3?&sxzxm_pt3_position:&sxzxm_zx_position,hs,n)||!sxzxm_opt(c,&sxzxm_zx_pattern_channels,pt,patterns))return false;
 for(unsigned i=0;i<sc;i++){uint16_t p;if(!sxzxm_u16(c,sp+2*i,&p))break;if(p>=hs&&!sxzxm_object(c,p,version-1))return false;}
 for(unsigned i=0;i<16;i++){uint16_t p;if(!sxzxm_u16(c,op+2*i,&p))break;if(p<hs)continue;if(version==1){if(!sxzxm_opt(c,&sxzxm_zx_ornament_step,p,64))return false;}else if(!sxzxm_object(c,p,version==2?3:4))return false;}
 return true;
}
static bool sxzxm_asc(sx_context*c,bool v1){
 uint8_t h[9];unsigned hs=v1?9:8;if(!sxzxm_read(c,0,h,hs)||!sxzxm_put(c,v1?&sxzxm_asc1_header:&sxzxm_asc0_header,0,1))return false;
 unsigned pp=sxzxm16(h+1+v1),sp=sxzxm16(h+3+v1),op=sxzxm16(h+5+v1),n=h[hs-1],patterns=0;uint8_t b;
 if(!sxzxm_opt(c,&sxzxm_zx_position,hs,n))return false;
 for(unsigned i=0;i<n;i++){if(!sxzxm_u8(c,hs+i,&b)||b>=32)break;if((unsigned)b+1>patterns)patterns=b+1;}
 if(sxzxm_eq(c,hs+n,"ASM COMPILATION OF ",19)&&!sxzxm_opt(c,&sxzxm_asc_identity,hs+n,1))return false;
 if(!sxzxm_opt(c,&sxzxm_asc_pattern_channels,pp,patterns)||!sxzxm_opt(c,&sxzxm_asc_sample_offset,sp,32)||!sxzxm_opt(c,&sxzxm_asc_ornament_offset,op,32))return false;
 for(unsigned k=0;k<2;k++){unsigned tab=k?op:sp,width=k?2:3,max=k?30:150;const sx_layout*l=k?&sxzxm_asc_ornament_line:&sxzxm_asc_sample_line;
  for(unsigned i=0;i<32;i++){uint16_t rel;if(!sxzxm_u16(c,tab+2*i,&rel))break;if(rel<64)continue;uint64_t p=(uint64_t)tab+rel;unsigned j=0;for(;j<max;j++){if(!sxzxm_span(c,p+(uint64_t)j*width,width)||!sxzxm_u8(c,p+(uint64_t)j*width,&b))break;if(b&32){j++;break;}}if(!sxzxm_opt(c,l,p,j))return false;}}
 return true;
}
static bool sxzxm_global(sx_context*c){
 uint16_t base;if(!SXZXM_ADD(c,globaltracker_header,0)||!sxzxm_u16(c,5,&base))return false;
 if(!sxzxm_opt(c,&sxzxm_zx_sample_address,39,15)||!sxzxm_opt(c,&sxzxm_zx_ornament_address,69,16)||!sxzxm_opt(c,&sxzxm_zx_pattern_addresses,101,32)||!sxzxm_opt(c,&sxzxm_globaltracker_positions,293,1))return false;
 uint8_t n;if(sxzxm_u8(c,293,&n)&&!sxzxm_opt(c,&sxzxm_globaltracker_position,295,n))return false;
 for(unsigned k=0;k<2;k++)for(unsigned i=0;i<(k?16:15);i++){uint16_t p;if(!sxzxm_u16(c,(k?69:39)+2*i,&p))break;if(p>=base&&p-base>=295&&!sxzxm_object(c,p-base,k?4:5))return false;}
 return true;
}
static bool sxzxm_fast(sx_context*c){
 uint16_t pt;if(!SXZXM_ADD(c,fasttracker_header,0)||!sxzxm_u16(c,75,&pt))return false;
 if(!sxzxm_opt(c,&sxzxm_zx_sample_address,82,32)||!sxzxm_opt(c,&sxzxm_zx_ornament_address,146,33))return false;
 uint8_t b;unsigned n=0;for(;n<255&&sxzxm_u8(c,212+2U*n,&b)&&b<128;n++){}if(!sxzxm_opt(c,&sxzxm_fasttracker_position,212,n))return false;if(sxzxm_u8(c,212+2U*n,&b)&&b==255&&!SXZXM_ADD(c,zx_marker,212+2U*n))return false;
 uint16_t first=0,end;unsigned count=0;bool terminated=false;for(;count<32;count++){if(!sxzxm_u16(c,(uint64_t)pt+6U*count,&end))break;if(end==65535){terminated=true;break;}if(!first&&end)first=end;}
 if(!sxzxm_opt(c,&sxzxm_zx_pattern_addresses,pt,count))return false;
 uint64_t after=(uint64_t)pt+6U*count+2;if(!terminated||first<after)return true;
 if(!SXZXM_ADD(c,fasttracker_pattern_end,after-2))return false;uint64_t base=first-after;
 for(unsigned k=0;k<2;k++)for(unsigned i=0;i<(k?33:32);i++){uint16_t p;if(!sxzxm_u16(c,(k?146:82)+2U*i,&p))break;if(p>=base&&p-base>=after&&!sxzxm_object(c,p-base,k?7:6))return false;}
 return true;
}
static bool sxzxm_psc(sx_context*c){
 uint8_t h[76];if(!sxzxm_read(c,0,h,76)||!SXZXM_ADD(c,prosoundcreator_header,0))return false;
 unsigned samples=sxzxm16(h+69),pos=sxzxm16(h+71),orn=sxzxm16(h+74);if(orn<76||samples<orn)return true;
 unsigned sc=(orn-76)/2,oc=(samples-orn)/2;if(sc>32)sc=32;if(oc>32)oc=32;
 if(!sxzxm_opt(c,&sxzxm_prosoundcreator_sample_ref,76,sc)||!sxzxm_opt(c,&sxzxm_prosoundcreator_ornament_ref,orn,oc))return false;
 /* Confirm the known writer variant by the first physical sample: its
  * pointer targets SamplesStart+1, after the unused index byte. */
 uint16_t first;bool relative=false,known=false;if(sxzxm_u16(c,76,&first)){if((uint64_t)first+76==(uint64_t)samples+1)relative=known=true;else if(first==(unsigned)samples+1)known=true;}
 if(known)for(unsigned k=0;k<2;k++){unsigned tab=k?orn:76,count=k?oc:sc,width=k?2:6,max=32;const sx_layout*l=k?&sxzxm_prosoundcreator_ornament_line:&sxzxm_prosoundcreator_sample_line;
  for(unsigned i=0;i<count;i++){uint16_t ref;if(!sxzxm_u16(c,tab+2U*i,&ref))break;uint64_t p=(uint64_t)ref+(relative?tab:0);uint8_t f;unsigned n=0;if(p<=samples)continue;for(;n<max;n++){if(!sxzxm_span(c,p+(uint64_t)n*width,width)||!sxzxm_u8(c,p+(uint64_t)n*width+(k?0:4),&f))break;if(!(f&32)){n++;break;}}if(!sxzxm_opt(c,l,p,n))return false;}}
 for(unsigned i=0;i<256;i++){uint64_t p=(uint64_t)pos+8U*i;uint8_t b;if(!sxzxm_u8(c,p+1,&b))break;if(b==255){if(!sxzxm_opt(c,&sxzxm_prosoundcreator_end,p,1)||!sxzxm_opt(c,&sxzxm_prosoundcreator_loop,p+2,1))return false;break;}if(!sxzxm_span(c,p,8))break;if(!SXZXM_ADD(c,prosoundcreator_position,p))return false;}
 return true;
}
static bool sxzxm_psm(sx_context*c){
 uint8_t h[8];if(!sxzxm_read(c,0,h,8)||!SXZXM_ADD(c,prosoundmaker_header,0))return false;unsigned pos=sxzxm16(h),sp=sxzxm16(h+2),op=sxzxm16(h+4),pt=sxzxm16(h+6),patterns=0,n=0;uint8_t v;
 for(;n<256;n++){if(!sxzxm_span(c,(uint64_t)pos+2U*n,2)||!sxzxm_u8(c,(uint64_t)pos+2U*n,&v))break;if(v==255){n++;break;}if(v>=32)break;if((unsigned)v+1>patterns)patterns=v+1;}
 if(!sxzxm_opt(c,&sxzxm_prosoundmaker_position,pos,n)||!sxzxm_opt(c,&sxzxm_prosoundmaker_pattern,pt,patterns))return false;
 uint16_t first;unsigned sc=0,oc=0;
 if(sxzxm_u16(c,sp,&first)&&first>=sp&&(first-sp)%2==0)sc=(first-sp)/2;
 if(op!=pt&&sxzxm_u16(c,op,&first)&&first>=op&&(first-op)%2==0)oc=(first-op)/2;
 if(sc>32)sc=0;if(oc>16)oc=0;
 for(unsigned k=0;k<2;k++){unsigned tab=k?op:sp,count=k?oc:sc;if(!sxzxm_opt(c,k?&sxzxm_zx_ornament_offset:&sxzxm_zx_sample_offset,tab,count))return false;for(unsigned i=0;i<count;i++){uint16_t p;if(!sxzxm_u16(c,tab+2U*i,&p))break;if(p>=8&&!sxzxm_object(c,p,k?9:8))return false;}}
 return true;
}
static bool sxzxm_stc(sx_context*c){
 uint8_t h[27],n;if(!sxzxm_read(c,0,h,27)||!SXZXM_ADD(c,stc_header,0))return false;unsigned pos=sxzxm16(h+1),orn=sxzxm16(h+3),pat=sxzxm16(h+5);
 if(sxzxm_u8(c,pos,&n)&&(!SXZXM_ADD(c,stc_positions,pos)||!sxzxm_opt(c,&sxzxm_stc_position,pos+1U,(unsigned)n+1)))return false;
 unsigned before=pos;if(orn>=27&&orn<before)before=orn;if(pat>=27&&pat<before)before=pat;
 if(before>=27){unsigned sc=(before-27)/99;if(sc>16)sc=16;for(unsigned i=0;i<sc;i++){uint64_t p=27+99U*i;if(!SXZXM_ADD(c,stc_sample_prefix,p)||!sxzxm_opt(c,&sxzxm_stc_sample_line,p+1,32)||!SXZXM_ADD(c,stc_sample_loop,p+97))return false;}}
 if(pat>=orn){unsigned oc=(pat-orn)/33;if(oc>16)oc=16;for(unsigned i=0;i<oc;i++){uint64_t p=(uint64_t)orn+33U*i;if(!sxzxm_span(c,p,33))break;if(!SXZXM_ADD(c,stc_ornament_prefix,p)||!sxzxm_opt(c,&sxzxm_zx_ornament_step,p+1,32))return false;}}
 for(unsigned i=0;i<32;i++){uint64_t p=(uint64_t)pat+7U*i;if(!sxzxm_u8(c,p,&n))break;if(n==255){if(!SXZXM_ADD(c,zx_marker,p))return false;break;}if(!sxzxm_span(c,p,7))break;if(!SXZXM_ADD(c,stc_pattern,p))return false;}
 return true;
}
static bool sxzxm_st3(sx_context*c){
 uint8_t h[9],n;if(!sxzxm_read(c,0,h,9)||!SXZXM_ADD(c,st3_header,0))return false;unsigned pos=sxzxm16(h+1),sp=sxzxm16(h+3),op=sxzxm16(h+5),pt=sxzxm16(h+7),patterns=0;
 bool id=sxzxm_eq(c,9,"KSA SOFTWARE COMPILATION OF ",28);
 if(id&&!sxzxm_opt(c,&sxzxm_st3_identity,9,1))return false;
 uint16_t first;unsigned origin=id?64:9,base=0;bool have_base=sxzxm_u16(c,(uint64_t)sp+1,&first)&&first>=origin;if(have_base)base=first-origin;
 if(sxzxm_u8(c,pos,&n)){if(!SXZXM_ADD(c,zx_positions_count,pos)||!sxzxm_opt(c,&sxzxm_st3_position,pos+1U,n))return false;for(unsigned i=0;i<n;i++){uint8_t v;if(!sxzxm_u8(c,(uint64_t)pos+2+2U*i,&v)||v%6||v/6U>=32)break;if(v/6U+1>patterns)patterns=v/6U+1;}}
 if(!sxzxm_opt(c,&sxzxm_zx_pattern_channels,pt,patterns))return false;
 for(unsigned k=0;k<2;k++){unsigned tab=k?op:sp;if(!sxzxm_u8(c,tab,&n)||n>16)continue;if(!SXZXM_ADD(c,st3_object_table,tab)||!sxzxm_opt(c,base?(k?&sxzxm_zx_ornament_address:&sxzxm_zx_sample_address):(k?&sxzxm_zx_ornament_offset:&sxzxm_zx_sample_offset),tab+1U,n))return false;
  for(unsigned i=0;i<n;i++){uint16_t p;if(!sxzxm_u16(c,(uint64_t)tab+1+2U*i,&p))break;if(!have_base||p<base||p-base<origin)continue;p=(uint16_t)(p-base);if(k){if(!sxzxm_opt(c,&sxzxm_zx_ornament_step,p,32))return false;}else if(sxzxm_span(c,p,2)&&(!SXZXM_ADD(c,st3_sample,p)||!sxzxm_opt(c,&sxzxm_st3_sample_line,p+2U,32)))return false;}}
 return true;
}
static bool sxzxm_stp(sx_context*c){
 uint8_t h[10],n;if(!sxzxm_read(c,0,h,10)||!SXZXM_ADD(c,stp_header,0))return false;unsigned pos=sxzxm16(h+1),pt=sxzxm16(h+3),op=sxzxm16(h+5),sp=sxzxm16(h+7),patterns=0;
 if(sxzxm_eq(c,10,"KSA SOFTWARE COMPILATION OF ",28)&&!sxzxm_opt(c,&sxzxm_stp_identity,10,1))return false;
 if(sxzxm_u8(c,pos,&n)){if(!sxzxm_opt(c,&sxzxm_stp_positions,pos,1)||!sxzxm_opt(c,&sxzxm_stp_position,pos+2U,n))return false;for(unsigned i=0;i<n;i++){uint8_t v;if(!sxzxm_u8(c,(uint64_t)pos+2+2U*i,&v)||v%6||v/6U>=32)break;if(v/6U+1>patterns)patterns=v/6U+1;}}
 if(!sxzxm_opt(c,&sxzxm_zx_pattern_channels,pt,patterns))return false;
 for(unsigned k=0;k<2;k++){unsigned tab=k?op:sp,count=k?16:15;if(!sxzxm_opt(c,k?&sxzxm_zx_ornament_offset:&sxzxm_zx_sample_offset,tab,count))return false;for(unsigned i=0;i<count;i++){uint16_t p;if(!sxzxm_u16(c,(uint64_t)tab+2U*i,&p))break;if(p>=10&&!sxzxm_object(c,p,k?11:10))return false;}}
 return true;
}
static bool sxzxm_etracker(sx_context*c){
 uint64_t base=0;if((sxzxm_eq(c,0,"\x21\xb3\x84",3)||sxzxm_eq(c,0,"\x21\xb3\x04",3))&&sxzxm_eq(c,0x4bd,"ETracker (C) BY ESI.",19))base=0x4b3;
 uint8_t h[30],v;if(!sxzxm_read(c,base,h,30)||!sxzxm_put(c,&sxzxm_etracker_header,base,1))return false;
 unsigned pos=sxzxm16(h),pt=sxzxm16(h+2),sp=sxzxm16(h+4),op=sxzxm16(h+6),vol=sxzxm16(h+8),patterns=0,n=0;
 for(;n<1024&&sxzxm_u8(c,base+pos+n,&v);n++){if(v==255){n++;break;}if(v<96){if(v%3)break;if(v/3U+1>patterns)patterns=v/3U+1;}}
 if(!sxzxm_opt(c,&sxzxm_etracker_position,base+pos,n)||!sxzxm_opt(c,&sxzxm_etracker_pattern,base+pt,patterns))return false;
 unsigned sc=op>=sp?(op-sp)/2:0,oc=vol>=op?(vol-op)/2:0;if(sc>32)sc=32;if(oc>32)oc=32;
 return sxzxm_opt(c,&sxzxm_etracker_sample_offset,base+sp,sc)&&sxzxm_opt(c,&sxzxm_etracker_ornament_offset,base+op,oc);
}
static bool sxzxm_chip(sx_context*c){
 uint8_t n,v;if(!SXZXM_ADD(c,chiptracker_header,0))return false;
 if(!sxzxm_opt(c,&sxzxm_chiptracker_sample,43,16)||!sxzxm_opt(c,&sxzxm_chiptracker_sample_name,128,16)||!sxzxm_opt(c,&sxzxm_zx_position,256,256))return false;
 unsigned patterns=0;if(sxzxm_u8(c,41,&n))for(unsigned i=0;i<=(unsigned)n;i++){if(!sxzxm_u8(c,256+i,&v)||v>=31)break;if((unsigned)v+1>patterns)patterns=v+1;}
 for(unsigned i=0;i<patterns;i++){uint64_t p=512+512U*i;if(!sxzxm_opt(c,&sxzxm_chiptracker_note,p,256)||!sxzxm_opt(c,&sxzxm_chiptracker_parameter,p+256,256))return false;}return true;
}
static bool sxzxm_dmm(sx_context*c){
 uint8_t rows;if(!SXZXM_ADD(c,dmm_header,0))return false;
 if(!sxzxm_opt(c,&sxzxm_zx_position,14,50)||!sxzxm_opt(c,&sxzxm_dmm_playback,64,1)||!sxzxm_opt(c,&sxzxm_dmm_mixing,69,5)||!sxzxm_opt(c,&sxzxm_dmm_sample,90,16))return false;
 if(sxzxm_u8(c,12,&rows)&&(rows==24||rows==32||rows==48||rows==64))for(unsigned i=0;i<24;i++)if(!sxzxm_opt(c,&sxzxm_dmm_event,350+(uint64_t)i*rows*9,(unsigned)rows*3))return false;
 return true;
}
static bool sxzxm_sqd(sx_context*c){
 if(!sxzxm_span(c,0,1024))return false;
 if(!sxzxm_put(c,&sxzxm_sqd_layout,192,8)||!SXZXM_ADD(c,sqd_title,256)||!sxzxm_put(c,&sxzxm_sqd_sample,288,16)||!sxzxm_put(c,&sxzxm_zx_position,416,100)||!SXZXM_ADD(c,sqd_positions_limit,516)||!SXZXM_ADD(c,sqd_playback,528)||!sxzxm_put(c,&sxzxm_chiptracker_sample_name,768,16))return false;
 for(unsigned i=0;i<32;i++)if(!sxzxm_opt(c,&sxzxm_sqd_event,1024+512U*i,256))return false;return true;
}
static bool sxzxm_ds(sx_context*c){
 if(!SXZXM_ADD(c,digitalstudio_order,0))return false;
 if(!sxzxm_opt(c,&sxzxm_zx_position,1,99)||!sxzxm_opt(c,&sxzxm_digitalstudio_header,100,1)||!sxzxm_opt(c,&sxzxm_digitalstudio_sample,256,16))return false;
 /* Both variants define exactly32 physical pattern objects here. The
  * compiled variant's additional0x1000 bytes do not become invented events. */
 for(unsigned i=0;i<32;i++)if(!sxzxm_opt(c,&sxzxm_digitalstudio_event,0x4200+384U*i,192))return false;return true;
}
static bool sxzxm_et(sx_context*c){
 if(!SXZXM_ADD(c,extremetracker_header,0))return false;
 if(!sxzxm_opt(c,&sxzxm_zx_position,34,100)||!sxzxm_opt(c,&sxzxm_extremetracker_pattern_size,134,32)||!sxzxm_opt(c,&sxzxm_extremetracker_memory,168,5)||!sxzxm_opt(c,&sxzxm_extremetracker_sample,256,16))return false;
 for(unsigned i=0;i<32;i++)if(!sxzxm_opt(c,&sxzxm_extremetracker_event,512+512U*i,256))return false;return true;
}
static bool sxzxm_delta(sx_context*c,uint64_t at,uint64_t*out){uint8_t b[2];if(!sxzxm_read(c,at,b,2))return false;unsigned u=(unsigned)b[0]*256U+b[1];int64_t d=u<32768?u:(int64_t)u-65536;if(d<0&&(uint64_t)(-d)>at)return false;if(d>=0&&at>UINT64_MAX-(uint64_t)d)return false;*out=d<0?at-(uint64_t)(-d):at+(uint64_t)d;return sxzxm_span(c,*out,0);}
static bool sxzxm_st1(sx_context*c,uint64_t p){
 if(!sxzxm_span(c,p,3009))return true;
 if(!sxzxm_put(c,&sxzxm_st1_sample,p,15)||!sxzxm_put(c,&sxzxm_st1_position,p+1950,256)||!SXZXM_ADD(c,st1_song_length,p+2462)||!sxzxm_put(c,&sxzxm_st1_ornament_step,p+2463,544)||!SXZXM_ADD(c,st1_playback,p+3007))return false;
 /* The AY song has no physical end pointer. Pattern bytecode and any following
  * songs remain raw rather than inferring their count from the container tail. */
 return true;
}
static bool sxzxm_ayst(sx_context*c){
 if(!SXZXM_ADD(c,ayst11_header,0))return false;uint8_t last;uint64_t p;
 for(unsigned at=12;at<=14;at+=2)if(sxzxm_delta(c,at,&p)&&!sxzxm_string(c,p))return false;
 if(!sxzxm_u8(c,16,&last)||!sxzxm_delta(c,18,&p)||!sxzxm_span(c,p,4U*((unsigned)last+1)))return true;
 if(!sxzxm_put(c,&sxzxm_ayst11_song,p,(unsigned)last+1))return false;
 for(unsigned i=0;i<=(unsigned)last;i++){uint64_t name,data,at=p+4U*i;if(sxzxm_delta(c,at,&name)&&!sxzxm_string(c,name))return false;if(sxzxm_delta(c,at+2,&data)&&sxzxm_span(c,data,8)){if(!SXZXM_ADD(c,ayst11_song_data,data)||!sxzxm_st1(c,data+8))return false;}}
 return true;
}
static bool sxzxm_rmt(sx_context*c){
 uint8_t b[6],h[16];if(!sxzxm_read(c,0,b,6)||!SXZXM_ADD(c,rmt_binary_header,0))return false;
 unsigned load=sxzxm16(b+2),end=sxzxm16(b+4);if(end<load||!sxzxm_span(c,6,(unsigned)end-load+1)||!sxzxm_read(c,6,h,16))return true;
 if(!sxzxm_eq(c,6,"RMT",3)||(h[3]!='4'&&h[3]!='8'))return true;
 if(!SXZXM_ADD(c,rmt_header,6))return false;unsigned ip=sxzxm16(h+8),lo=sxzxm16(h+10),hi=sxzxm16(h+12),song=sxzxm16(h+14);uint64_t segment_end=7U+end-load;
 if(ip>=load+16U&&lo>=ip&&hi>=lo&&song>=hi&&song<=end+1U){
  unsigned ic=(lo-ip)/2,tc=hi-lo;if(ic>256)ic=256;if(tc>256)tc=256;uint64_t it=6U+ip-load;
  if(!sxzxm_opt(c,&sxzxm_rmt_instrument_address,it,ic)||!sxzxm_opt(c,&sxzxm_rmt_track_low,6U+lo-load,tc)||!sxzxm_opt(c,&sxzxm_rmt_track_high,6U+hi-load,song-hi<tc?song-hi:tc))return false;
  for(unsigned i=0;i<ic;i++){uint16_t address;if(!sxzxm_u16(c,it+2U*i,&address))break;if(address<load+16U||address>end)continue;uint64_t p=6U+address-load;uint8_t ih[12];if(p>segment_end||12>segment_end-p||!sxzxm_read(c,p,ih,12))continue;
   if(!SXZXM_ADD(c,rmt_instrument,p))return false;

  }
 }
 uint64_t p=segment_end;for(unsigned i=0;i<256&&sxzxm_span(c,p,4);i++){uint8_t sh[4];if(!sxzxm_read(c,p,sh,4))break;unsigned a=sxzxm16(sh),z=sxzxm16(sh+2);if(a==65535){if(!sxzxm_span(c,p+2,4))break;p+=2;if(!sxzxm_read(c,p,sh,4))break;a=sxzxm16(sh);z=sxzxm16(sh+2);}if(z<a||!sxzxm_span(c,p+4,z-a+1U))break;if(!SXZXM_ADD(c,rmt_binary_segment,p))return false;p+=4U+z-a+1U;}
 return true;
}
static bool sx_zxmusic_supports(xx_file_type_t type){switch(type){
 case XX_FILE_TYPE_DIE_MUSIC_ALONECODER_CHIPTRACKER:
 case XX_FILE_TYPE_DIE_MUSIC_WOLOSZYK_ETRACKER:
 case XX_FILE_TYPE_DIE_MUSIC_BZYK_SOUNDTRACKER_AYST11:
 case XX_FILE_TYPE_DIE_MUSIC_DEXUS_PROSOUNDMAKER:
 case XX_FILE_TYPE_DIE_MUSIC_ASC_ADVANCEDSOUNDMASTER_V1:
 case XX_FILE_TYPE_DIE_MUSIC_ASC_ADVANCEDSOUNDMASTER_V0:
 case XX_FILE_TYPE_DIE_MUSIC_DOCTORMAX_GLOBALTRACKER_GTR:
 case XX_FILE_TYPE_DIE_MUSIC_GOLDENDISK_PROTRACKER_PT1_CO:
 case XX_FILE_TYPE_DIE_MUSIC_GOLDENDISK_PROTRACKER_PT2:
 case XX_FILE_TYPE_DIE_MUSIC_GOLDENDISK_PROTRACKER_PT3:
 case XX_FILE_TYPE_DIE_MUSIC_KVA_PROSOUNDCREATOR:
 case XX_FILE_TYPE_DIE_MUSIC_ORIONSAND_FASTTRACKER_FTC:
 case XX_FILE_TYPE_DIE_MUSIC_KSA_SOUNDTRACKERPRO_STP:
 case XX_FILE_TYPE_DIE_MUSIC_BZYK_SOUNDTRACKER_STC_ZXS:
 case XX_FILE_TYPE_DIE_MUSIC_STMUSICSTCRECOMPV2_ST3:
 case XX_FILE_TYPE_DIE_MUSIC_LAVE_DIGITALMUSICMAKER:
 case XX_FILE_TYPE_DIE_MUSIC_RASTER_MUSICTRACKER:
 case XX_FILE_TYPE_DIE_MUSIC_SQDIGITALTRACKER:
 case XX_FILE_TYPE_DIE_MUSIC_UNDERGROUNDSYSTEMS_DIGITALSTUDIO:
 case XX_FILE_TYPE_DIE_MUSIC_REDLIMITED_EXTREMETRACKER:
 return true;default:return false;}}
static bool sx_zxmusic_build(sx_context*c){
 if(!c||!c->f||!sx_zxmusic_supports(c->f->file_type)||!xx_format_handle_base_info(c->f,c->pd)||!c->f->is_valid)return false;
 bool ok=false;switch(c->f->file_type){
 case XX_FILE_TYPE_DIE_MUSIC_ALONECODER_CHIPTRACKER:ok=sxzxm_chip(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_WOLOSZYK_ETRACKER:ok=sxzxm_etracker(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_BZYK_SOUNDTRACKER_AYST11:ok=sxzxm_ayst(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_DEXUS_PROSOUNDMAKER:ok=sxzxm_psm(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_ASC_ADVANCEDSOUNDMASTER_V1:ok=sxzxm_asc(c,true);break;
 case XX_FILE_TYPE_DIE_MUSIC_ASC_ADVANCEDSOUNDMASTER_V0:ok=sxzxm_asc(c,false);break;
 case XX_FILE_TYPE_DIE_MUSIC_DOCTORMAX_GLOBALTRACKER_GTR:ok=sxzxm_global(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_GOLDENDISK_PROTRACKER_PT1_CO:ok=sxzxm_pt(c,1);break;
 case XX_FILE_TYPE_DIE_MUSIC_GOLDENDISK_PROTRACKER_PT2:ok=sxzxm_pt(c,2);break;
 case XX_FILE_TYPE_DIE_MUSIC_GOLDENDISK_PROTRACKER_PT3:ok=sxzxm_pt(c,3);break;
 case XX_FILE_TYPE_DIE_MUSIC_KVA_PROSOUNDCREATOR:ok=sxzxm_psc(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_ORIONSAND_FASTTRACKER_FTC:ok=sxzxm_fast(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_KSA_SOUNDTRACKERPRO_STP:ok=sxzxm_stp(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_BZYK_SOUNDTRACKER_STC_ZXS:ok=sxzxm_stc(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_STMUSICSTCRECOMPV2_ST3:ok=sxzxm_st3(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_LAVE_DIGITALMUSICMAKER:ok=sxzxm_dmm(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_RASTER_MUSICTRACKER:ok=sxzxm_rmt(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_SQDIGITALTRACKER:ok=sxzxm_sqd(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_UNDERGROUNDSYSTEMS_DIGITALSTUDIO:ok=sxzxm_ds(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_REDLIMITED_EXTREMETRACKER:ok=sxzxm_et(c);break;
 default:break;}return ok&&c->count>0&&sxzxm_finish(c);
}
static bool sx_zxmusic_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x608a0000U||id>=0x608b0000U)return true;
 if(id==sxzxm_pt1_header.id&&!xx_rt_wcscmp(r->name,L"tempo"))return xx_data_struct_record_set_comment(r,L"Playback delay in ticks per pattern row.");
 if(id==sxzxm_pt2_header.id&&!xx_rt_wcscmp(r->name,L"tempo"))return xx_data_struct_record_set_comment(r,L"Playback delay in ticks per pattern row.");
 if(id==sxzxm_pt1_sample_line.id&&!xx_rt_wcscmp(r->name,L"volume_vibrato_high"))return xx_data_struct_record_set_comment(r,L"High nibble holds the high 4 bits of the 12-bit tone deviation; low nibble is volume.");
 if(id==sxzxm_pt1_sample_line.id&&!xx_rt_wcscmp(r->name,L"noise_flags"))return xx_data_struct_record_set_comment(r,L"Bits7/6 disable noise/tone; bit5 selects positive tone deviation; low5 bits are noise period.");
 if(id==sxzxm_pt2_sample_line.id&&!xx_rt_wcscmp(r->name,L"noise_flags"))return xx_data_struct_record_set_comment(r,L"High5 bits are noise period; bit2 selects positive tone deviation; bits1/0 disable tone/noise.");
 if(id==sxzxm_pt2_sample_line.id&&!xx_rt_wcscmp(r->name,L"volume_vibrato_high"))return xx_data_struct_record_set_comment(r,L"High nibble is volume; low nibble is high4 bits of tone deviation.");
 if(id==sxzxm_pt3_header.id&&!xx_rt_wcscmp(r->name,L"mode"))return xx_data_struct_record_set_comment(r,L"Stored playback/TurboSound mode byte; it is not a channel count.");
 if(id==sxzxm_pt3_header.id&&!xx_rt_wcscmp(r->name,L"frequency_table"))return xx_data_struct_record_set_comment(r,L"0=ProTracker3.3,1=SoundTracker,2=ASM/PSC,3=RealSound,4=natural tuning; other values are variant-specific.");
 if(id==sxzxm_pt3_position.id&&!xx_rt_wcscmp(r->name,L"pattern_reference"))return xx_data_struct_record_set_comment(r,L"Stored pattern index multiplied by3; 0xFF terminates the position list.");
 if(id==sxzxm_pt3_sample_line.id&&!xx_rt_wcscmp(r->name,L"tone_offset"))return xx_data_struct_record_set_comment(r,L"Signed tone-period offset.");
 if(id==sxzxm_asc_pattern_channels.id&&!xx_rt_wcscmp(r->name,L"channel_a_relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the pattern-pointer table start.");
 if(id==sxzxm_asc_pattern_channels.id&&!xx_rt_wcscmp(r->name,L"channel_b_relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the pattern-pointer table start.");
 if(id==sxzxm_asc_pattern_channels.id&&!xx_rt_wcscmp(r->name,L"channel_c_relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the pattern-pointer table start.");
 if(id==sxzxm_asc_sample_offset.id&&!xx_rt_wcscmp(r->name,L"sample_relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the sample-pointer table start.");
 if(id==sxzxm_asc_ornament_offset.id&&!xx_rt_wcscmp(r->name,L"ornament_relative_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the ornament-pointer table start.");
 if(id==sxzxm_asc_sample_line.id&&!xx_rt_wcscmp(r->name,L"loop_addition"))return xx_data_struct_record_set_comment(r,L"Bits7/6/5 mark loop begin/loop end/finish; low5 bits hold a signed5-bit increment.");
 if(id==sxzxm_asc_ornament_line.id&&!xx_rt_wcscmp(r->name,L"loop_noise_offset"))return xx_data_struct_record_set_comment(r,L"Bits7/6/5 mark loop begin/loop end/finish; low5 bits hold a signed5-bit noise offset.");
 if(id==sxzxm_globaltracker_position.id&&!xx_rt_wcscmp(r->name,L"pattern_table_offset"))return xx_data_struct_record_set_comment(r,L"Stored byte offset into the6-byte pattern-pointer table (pattern index multiplied by6).");
 if(id==sxzxm_globaltracker_sample.id&&!xx_rt_wcscmp(r->name,L"encoded_byte_size"))return xx_data_struct_record_set_comment(r,L"Number of physical sample-line bytes; zero encodes256 bytes, each line is4 bytes.");
 if(id==sxzxm_globaltracker_sample.id&&!xx_rt_wcscmp(r->name,L"loop_byte_offset"))return xx_data_struct_record_set_comment(r,L"Loop offset in bytes from sample-line data, divisible by4.");
 if(id==sxzxm_globaltracker_sample_line.id&&!xx_rt_wcscmp(r->name,L"tone_deviation_bits"))return xx_data_struct_record_set_comment(r,L"Stored16-bit tone-deviation word; consumed modulo16 bits by the AY player.");
 if(id==sxzxm_fasttracker_header.id&&!xx_rt_wcscmp(r->name,L"frequency_table"))return xx_data_struct_record_set_comment(r,L"0x3B=ProTracker2,1=SoundTracker,2=FastTracker note table.");
 if(id==sxzxm_fasttracker_object.id&&!xx_rt_wcscmp(r->name,L"last_line_index"))return xx_data_struct_record_set_comment(r,L"Count minus one; physical line count is stored value+1.");
 if(id==sxzxm_fasttracker_object.id&&!xx_rt_wcscmp(r->name,L"last_loop_line_index"))return xx_data_struct_record_set_comment(r,L"Inclusive final line of loop; loop limit is stored value+1.");
 if(id==sxzxm_prosoundcreator_header.id&&!xx_rt_wcscmp(r->name,L"samples_start"))return xx_data_struct_record_set_comment(r,L"Offset of the unused index byte before the first sample; sample pointer targets the following data.");
 if(id==sxzxm_prosoundcreator_sample_ref.id&&!xx_rt_wcscmp(r->name,L"sample_reference"))return xx_data_struct_record_set_comment(r,L"Stored reference: absolute module offset in old variants, relative to sample-pointer table at76 in new variants.");
 if(id==sxzxm_prosoundcreator_ornament_ref.id&&!xx_rt_wcscmp(r->name,L"ornament_reference"))return xx_data_struct_record_set_comment(r,L"Stored reference: absolute module offset in old variants, relative to ornament-pointer table in new variants.");
 if(id==sxzxm_prosoundcreator_loop.id&&!xx_rt_wcscmp(r->name,L"loop_pattern_offset"))return xx_data_struct_record_set_comment(r,L"Module-relative byte offset of the loop position record, stored after the FF end marker.");
 if(id==sxzxm_prosoundcreator_sample_line.id&&!xx_rt_wcscmp(r->name,L"flags"))return xx_data_struct_record_set_comment(r,L"Loop begin/end/finish are active-low bits7/6/5; bit4 disables envelope, bit3 masks noise, bits2/1 volume down/up, bit0 masks tone.");
 if(id==sxzxm_prosoundcreator_ornament_line.id&&!xx_rt_wcscmp(r->name,L"loop_noise"))return xx_data_struct_record_set_comment(r,L"Loop begin/end/finish are active-low bits7/6/5; low5 bits hold noise offset.");
 if(id==sxzxm_prosoundmaker_position.id&&!xx_rt_wcscmp(r->name,L"transposition_or_loop"))return xx_data_struct_record_set_comment(r,L"Signed transposition for normal pattern entries; loop target encoding when pattern marker is0xFF.");
 if(id==sxzxm_prosoundmaker_sample.id&&!xx_rt_wcscmp(r->name,L"size_volume_flags"))return xx_data_struct_record_set_comment(r,L"Low5 bits encode line count minus1; high3 bits encode signed volume change.");
 if(id==sxzxm_prosoundmaker_sample.id&&!xx_rt_wcscmp(r->name,L"loop_repeat_flags"))return xx_data_struct_record_set_comment(r,L"Low5 bits are loop index; high3 bits are repeat count.");
 if(id==sxzxm_prosoundmaker_ornament.id&&!xx_rt_wcscmp(r->name,L"last_line_index"))return xx_data_struct_record_set_comment(r,L"Physical line count is stored value+1.");
 if(id==sxzxm_prosoundmaker_ornament.id&&!xx_rt_wcscmp(r->name,L"loop_flags"))return xx_data_struct_record_set_comment(r,L"Bit7 enables a loop; low5 bits select loop index.");
 if(id==sxzxm_stc_positions.id&&!xx_rt_wcscmp(r->name,L"last_position_index"))return xx_data_struct_record_set_comment(r,L"Number of stored2-byte position entries minus1.");
 if(id==sxzxm_st3_position.id&&!xx_rt_wcscmp(r->name,L"pattern_table_offset"))return xx_data_struct_record_set_comment(r,L"Stored byte offset into the6-byte pattern-pointer table.");
 if(id==sxzxm_st3_sample.id&&!xx_rt_wcscmp(r->name,L"loop_length"))return xx_data_struct_record_set_comment(r,L"Number of sample lines in the loop; playback adds loop_index and clamps the resulting end to 32 lines.");
 if(id==sxzxm_stp_position.id&&!xx_rt_wcscmp(r->name,L"pattern_table_offset"))return xx_data_struct_record_set_comment(r,L"Stored byte offset into the6-byte pattern-pointer table.");
 if(id==sxzxm_stp_object.id&&!xx_rt_wcscmp(r->name,L"loop_index"))return xx_data_struct_record_set_comment(r,L"Negative loop means no repeat (loop at logical end).");
 if(id==sxzxm_stp_object.id&&!xx_rt_wcscmp(r->name,L"line_count"))return xx_data_struct_record_set_comment(r,L"Negative value represents an empty object; nonnegative count is bounded to source bytes.");
 if(id==sxzxm_etracker_header.id&&!xx_rt_wcscmp(r->name,L"positions_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded ETracker module header; the optional player wrapper is outside this origin.");
 if(id==sxzxm_etracker_header.id&&!xx_rt_wcscmp(r->name,L"patterns_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded ETracker module header; the optional player wrapper is outside this origin.");
 if(id==sxzxm_etracker_header.id&&!xx_rt_wcscmp(r->name,L"samples_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded ETracker module header; the optional player wrapper is outside this origin.");
 if(id==sxzxm_etracker_header.id&&!xx_rt_wcscmp(r->name,L"ornaments_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded ETracker module header; the optional player wrapper is outside this origin.");
 if(id==sxzxm_etracker_header.id&&!xx_rt_wcscmp(r->name,L"volume_decode_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded ETracker module header; the optional player wrapper is outside this origin.");
 if(id==sxzxm_etracker_pattern.id&&!xx_rt_wcscmp(r->name,L"channel_0_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded ETracker module header; the optional player wrapper is outside this origin.");
 if(id==sxzxm_etracker_pattern.id&&!xx_rt_wcscmp(r->name,L"channel_1_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded ETracker module header; the optional player wrapper is outside this origin.");
 if(id==sxzxm_etracker_pattern.id&&!xx_rt_wcscmp(r->name,L"channel_2_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded ETracker module header; the optional player wrapper is outside this origin.");
 if(id==sxzxm_etracker_pattern.id&&!xx_rt_wcscmp(r->name,L"channel_3_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded ETracker module header; the optional player wrapper is outside this origin.");
 if(id==sxzxm_etracker_pattern.id&&!xx_rt_wcscmp(r->name,L"channel_4_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded ETracker module header; the optional player wrapper is outside this origin.");
 if(id==sxzxm_etracker_pattern.id&&!xx_rt_wcscmp(r->name,L"channel_5_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded ETracker module header; the optional player wrapper is outside this origin.");
 if(id==sxzxm_etracker_sample_offset.id&&!xx_rt_wcscmp(r->name,L"sample_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded ETracker module header; the optional player wrapper is outside this origin.");
 if(id==sxzxm_etracker_ornament_offset.id&&!xx_rt_wcscmp(r->name,L"ornament_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded ETracker module header; the optional player wrapper is outside this origin.");
 if(id==sxzxm_etracker_position.id&&!xx_rt_wcscmp(r->name,L"opcode"))return xx_data_struct_record_set_comment(r,L"0xFF=end,0xFE=loop marker,0x60..0xFD=transposition; smaller multiples of3 encode pattern index.");
 if(id==sxzxm_chiptracker_header.id&&!xx_rt_wcscmp(r->name,L"last_position_index"))return xx_data_struct_record_set_comment(r,L"Number of positions minus one; physical order table contains256 stored slots.");
 if(id==sxzxm_chiptracker_sample.id&&!xx_rt_wcscmp(r->name,L"loop_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset from this sample data start; length marks no repeat.");
 if(id==sxzxm_dmm_playback.id&&!xx_rt_wcscmp(r->name,L"last_position_index"))return xx_data_struct_record_set_comment(r,L"Position list length minus one.");
 if(id==sxzxm_dmm_playback.id&&!xx_rt_wcscmp(r->name,L"header_sectors"))return xx_data_struct_record_set_comment(r,L"Stored size of the pattern/header area in256-byte sectors; sample-bank data starts after this area.");
 if(id==sxzxm_sqd_layout.id&&!xx_rt_wcscmp(r->name,L"sector_count"))return xx_data_struct_record_set_comment(r,L"Number of256-byte sectors in this stored sample-bank layout.");
 if(id==sxzxm_sqd_positions_limit.id&&!xx_rt_wcscmp(r->name,L"positions_limit"))return xx_data_struct_record_set_comment(r,L"Stored edit/playback position limit; retained without treating it as the number of physically stored slots.");
 if(id==sxzxm_sqd_playback.id&&!xx_rt_wcscmp(r->name,L"last_position_index"))return xx_data_struct_record_set_comment(r,L"Inclusive final position index; physical order table contains100 slots.");
 if(id==sxzxm_ayst11_header.id&&!xx_rt_wcscmp(r->name,L"special_player_delta"))return xx_data_struct_record_set_comment(r,L"Signed big-endian byte displacement relative to the start of this pointer field.");
 if(id==sxzxm_ayst11_header.id&&!xx_rt_wcscmp(r->name,L"author_delta"))return xx_data_struct_record_set_comment(r,L"Signed big-endian byte displacement relative to the start of this pointer field.");
 if(id==sxzxm_ayst11_header.id&&!xx_rt_wcscmp(r->name,L"miscellaneous_delta"))return xx_data_struct_record_set_comment(r,L"Signed big-endian byte displacement relative to the start of this pointer field.");
 if(id==sxzxm_ayst11_header.id&&!xx_rt_wcscmp(r->name,L"songs_delta"))return xx_data_struct_record_set_comment(r,L"Signed big-endian byte displacement relative to the start of this pointer field.");
 if(id==sxzxm_ayst11_header.id&&!xx_rt_wcscmp(r->name,L"last_song_index"))return xx_data_struct_record_set_comment(r,L"Number of songs minus one.");
 if(id==sxzxm_ayst11_header.id&&!xx_rt_wcscmp(r->name,L"first_song_index"))return xx_data_struct_record_set_comment(r,L"Zero-based initial song index.");
 if(id==sxzxm_ayst11_song.id&&!xx_rt_wcscmp(r->name,L"name_delta"))return xx_data_struct_record_set_comment(r,L"Signed big-endian byte displacement relative to the start of this pointer field.");
 if(id==sxzxm_ayst11_song.id&&!xx_rt_wcscmp(r->name,L"data_delta"))return xx_data_struct_record_set_comment(r,L"Signed big-endian byte displacement relative to the start of this pointer field.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_00"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_01"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_02"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_03"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_04"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_05"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_06"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_07"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_08"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_09"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_10"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_11"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_12"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_13"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_14"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_15"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_16"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_17"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_18"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_19"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_20"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_21"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_22"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_23"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_24"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_25"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_26"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_27"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_28"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_29"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_30"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_sample.id&&!xx_rt_wcscmp(r->name,L"effect_31"))return xx_data_struct_record_set_comment(r,L"Packed tone-deviation magnitude and sign bit; retained as the original16-bit word.");
 if(id==sxzxm_st1_song_length.id&&!xx_rt_wcscmp(r->name,L"song_length"))return xx_data_struct_record_set_comment(r,L"Stored final position index; playback consumes value+1 position entries.");
 if(id==sxzxm_st1_ornament_step.id&&!xx_rt_wcscmp(r->name,L"encoded_pitch"))return xx_data_struct_record_set_comment(r,L"Original pitch byte; Ramsoft documentation describes negative values as one's complement, while later players use signed8-bit interpretation. Raw encoding is retained.");
 if(id==sxzxm_st1_playback.id&&!xx_rt_wcscmp(r->name,L"pattern_row_count"))return xx_data_struct_record_set_comment(r,L"Stored row count used by the player when a requested pattern is unavailable; not the number of physical pattern records.");
 if(id==sxzxm_rmt_binary_header.id&&!xx_rt_wcscmp(r->name,L"end_address"))return xx_data_struct_record_set_comment(r,L"Inclusive final Atari memory address of the physical segment.");
 if(id==sxzxm_rmt_binary_segment.id&&!xx_rt_wcscmp(r->name,L"end_address"))return xx_data_struct_record_set_comment(r,L"Inclusive final Atari memory address of the physical segment.");
 if(id==sxzxm_rmt_header.id&&!xx_rt_wcscmp(r->name,L"encoded_track_length"))return xx_data_struct_record_set_comment(r,L"Track length in rows; zero encodes256 rows.");
 if(id==sxzxm_rmt_header.id&&!xx_rt_wcscmp(r->name,L"player_frequency"))return xx_data_struct_record_set_comment(r,L"Player update multiplier relative to video frame frequency; not a frequency in Hz.");
 if(id==sxzxm_rmt_track_low.id&&!xx_rt_wcscmp(r->name,L"track_address_low"))return xx_data_struct_record_set_comment(r,L"Low byte of a track pointer; pair with matching entry in high-byte table.");
 if(id==sxzxm_rmt_track_high.id&&!xx_rt_wcscmp(r->name,L"track_address_high"))return xx_data_struct_record_set_comment(r,L"High byte of a track pointer; pair with matching entry in low-byte table.");
 if(id==sxzxm_rmt_instrument.id&&!xx_rt_wcscmp(r->name,L"note_table_end"))return xx_data_struct_record_set_comment(r,L"Byte offset within this instrument definition, as stored by Raster Music Tracker.");
 if(id==sxzxm_rmt_instrument.id&&!xx_rt_wcscmp(r->name,L"note_table_loop"))return xx_data_struct_record_set_comment(r,L"Byte offset within this instrument definition, as stored by Raster Music Tracker.");
 if(id==sxzxm_rmt_instrument.id&&!xx_rt_wcscmp(r->name,L"envelope_end"))return xx_data_struct_record_set_comment(r,L"Byte offset within this instrument definition, as stored by Raster Music Tracker.");
 if(id==sxzxm_rmt_instrument.id&&!xx_rt_wcscmp(r->name,L"envelope_loop"))return xx_data_struct_record_set_comment(r,L"Byte offset within this instrument definition, as stored by Raster Music Tracker.");
 if(id==sxzxm_digitalstudio_header.id&&!xx_rt_wcscmp(r->name,L"compiled_marker_area"))return xx_data_struct_record_set_comment(r,L"Any nonzero byte selects the compiled memory-bank variant; the region is not required to be zero in compiled modules.");
 if(id==sxzxm_digitalstudio_sample.id&&!xx_rt_wcscmp(r->name,L"page"))return xx_data_struct_record_set_comment(r,L"Spectrum bank/register value; low3 bits choose the physical sample bank. Samples below0xC000 may span two banks.");
 if(id==sxzxm_extremetracker_header.id&&!xx_rt_wcscmp(r->name,L"position_count"))return xx_data_struct_record_set_comment(r,L"Active order count; the original player treats stored zero as one position.");
 if(id==sxzxm_extremetracker_memory.id&&!xx_rt_wcscmp(r->name,L"rest_blocks"))return xx_data_struct_record_set_comment(r,L"Remaining allocation blocks as stored; no byte-size conversion is inferred from this table.");
 if(id==sxzxm_extremetracker_memory.id&&!xx_rt_wcscmp(r->name,L"free_start_block"))return xx_data_struct_record_set_comment(r,L"Stored allocation block index, not a physical file offset.");
 if(id==sxzxm_extremetracker_sample.id&&!xx_rt_wcscmp(r->name,L"block_count"))return xx_data_struct_record_set_comment(r,L"Count of256-byte sample blocks.");
 if(id==sxzxm_extremetracker_sample.id&&!xx_rt_wcscmp(r->name,L"loop_address"))return xx_data_struct_record_set_comment(r,L"Stored target-machine memory address, not a sample-relative byte offset.");
 if(id==sxzxm_extremetracker_event.id&&!xx_rt_wcscmp(r->name,L"sample_parameter"))return xx_data_struct_record_set_comment(r,L"Low nibble is sample number; high nibble is command argument. Glissando uses a format-specific sign encoding, not signed4-bit two's complement.");
 if(r->property&SX_OFFSET)return xx_data_struct_record_set_comment(r,L"Stored byte offset relative to the module start, unless the enclosing structure specifies another origin.");
 if(r->property&SX_ADDRESS)return xx_data_struct_record_set_comment(r,L"Encoded target-machine memory address; the field source-file offset is shown separately.");
 return true;
}
