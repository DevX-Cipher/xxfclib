/* SPDX-License-Identifier: MIT
 * Physical ZX/8-bit tracker metadata. Encoded event streams and PCM stay raw.
 * See docs/data_struct_zxmusic_scope.txt for format-specific limits. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_zxmusic.h"
static const xx_data_struct_field_desc sxzxm_zx_position_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
};
const sx_layout sxzxm_zx_position={UINT32_C(0x608A0001),"zx_position",sxzxm_zx_position_fields,SX_COUNT(sxzxm_zx_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_ornament_step_fields[]={
 SX_FIELD("note_offset","int8",0,1,SX_NONE),
};
const sx_layout sxzxm_zx_ornament_step={UINT32_C(0x608A0002),"zx_ornament_step",sxzxm_zx_ornament_step_fields,SX_COUNT(sxzxm_zx_ornament_step_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_sample_offset_fields[]={
 SX_FIELD("sample_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxzxm_zx_sample_offset={UINT32_C(0x608A0003),"zx_sample_offset",sxzxm_zx_sample_offset_fields,SX_COUNT(sxzxm_zx_sample_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_ornament_offset_fields[]={
 SX_FIELD("ornament_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxzxm_zx_ornament_offset={UINT32_C(0x608A0004),"zx_ornament_offset",sxzxm_zx_ornament_offset_fields,SX_COUNT(sxzxm_zx_ornament_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_sample_address_fields[]={
 SX_FIELD("sample_address","uint16",0,2,SX_ADDRESS),
};
const sx_layout sxzxm_zx_sample_address={UINT32_C(0x608A0005),"zx_sample_address",sxzxm_zx_sample_address_fields,SX_COUNT(sxzxm_zx_sample_address_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_ornament_address_fields[]={
 SX_FIELD("ornament_address","uint16",0,2,SX_ADDRESS),
};
const sx_layout sxzxm_zx_ornament_address={UINT32_C(0x608A0006),"zx_ornament_address",sxzxm_zx_ornament_address_fields,SX_COUNT(sxzxm_zx_ornament_address_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_pattern_channels_fields[]={
 SX_FIELD("channel_a_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("channel_b_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("channel_c_offset","uint16",4,2,SX_OFFSET),
};
const sx_layout sxzxm_zx_pattern_channels={UINT32_C(0x608A0007),"zx_pattern_channels",sxzxm_zx_pattern_channels_fields,SX_COUNT(sxzxm_zx_pattern_channels_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_zx_pattern_addresses_fields[]={
 SX_FIELD("channel_a_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("channel_b_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("channel_c_address","uint16",4,2,SX_ADDRESS),
};
const sx_layout sxzxm_zx_pattern_addresses={UINT32_C(0x608A0008),"zx_pattern_addresses",sxzxm_zx_pattern_addresses_fields,SX_COUNT(sxzxm_zx_pattern_addresses_fields),SX_LE};
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
const sx_layout sxzxm_zx_marker={UINT32_C(0x608A000C),"zx_marker",sxzxm_zx_marker_fields,SX_COUNT(sxzxm_zx_marker_fields),SX_LE};
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
static const xx_data_struct_field_desc sxzxm_globaltracker_position_fields[]={
 SX_FIELD("pattern_table_offset","uint8",0,1,SX_OFFSET),
};
const sx_layout sxzxm_globaltracker_position={UINT32_C(0x608A001F),"globaltracker_position",sxzxm_globaltracker_position_fields,SX_COUNT(sxzxm_globaltracker_position_fields),SX_LE};
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
const sx_layout sxzxm_fasttracker_header={UINT32_C(0x608A0022),"fasttracker_header",sxzxm_fasttracker_header_fields,SX_COUNT(sxzxm_fasttracker_header_fields),SX_LE};
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
const sx_layout sxzxm_prosoundcreator_header={UINT32_C(0x608A0028),"prosoundcreator_header",sxzxm_prosoundcreator_header_fields,SX_COUNT(sxzxm_prosoundcreator_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundcreator_sample_ref_fields[]={
 SX_FIELD("sample_reference","uint16",0,2,SX_OFFSET),
};
const sx_layout sxzxm_prosoundcreator_sample_ref={UINT32_C(0x608A0029),"prosoundcreator_sample_ref",sxzxm_prosoundcreator_sample_ref_fields,SX_COUNT(sxzxm_prosoundcreator_sample_ref_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundcreator_ornament_ref_fields[]={
 SX_FIELD("ornament_reference","uint16",0,2,SX_OFFSET),
};
const sx_layout sxzxm_prosoundcreator_ornament_ref={UINT32_C(0x608A002A),"prosoundcreator_ornament_ref",sxzxm_prosoundcreator_ornament_ref_fields,SX_COUNT(sxzxm_prosoundcreator_ornament_ref_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundcreator_loop_fields[]={
 SX_FIELD("loop_pattern_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxzxm_prosoundcreator_loop={UINT32_C(0x608A002D),"prosoundcreator_loop",sxzxm_prosoundcreator_loop_fields,SX_COUNT(sxzxm_prosoundcreator_loop_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundcreator_sample_line_fields[]={
 SX_FIELD("tone","uint16",0,2,SX_NONE),
 SX_FIELD("addition","int8",2,1,SX_NONE),
 SX_FIELD("level","uint8",3,1,SX_NONE),
 SX_FIELD("flags","uint8",4,1,SX_FLAGS),
 SX_FIELD("padding","uint8",5,1,SX_RESERVED),
};
const sx_layout sxzxm_prosoundcreator_sample_line={UINT32_C(0x608A002E),"prosoundcreator_sample_line",sxzxm_prosoundcreator_sample_line_fields,SX_COUNT(sxzxm_prosoundcreator_sample_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundcreator_ornament_line_fields[]={
 SX_FIELD("loop_noise","uint8",0,1,SX_FLAGS),
 SX_FIELD("note_offset","int8",1,1,SX_NONE),
};
const sx_layout sxzxm_prosoundcreator_ornament_line={UINT32_C(0x608A002F),"prosoundcreator_ornament_line",sxzxm_prosoundcreator_ornament_line_fields,SX_COUNT(sxzxm_prosoundcreator_ornament_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_prosoundmaker_position_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
 SX_FIELD("transposition_or_loop","uint8",1,1,SX_NONE),
};
const sx_layout sxzxm_prosoundmaker_position={UINT32_C(0x608A0031),"prosoundmaker_position",sxzxm_prosoundmaker_position_fields,SX_COUNT(sxzxm_prosoundmaker_position_fields),SX_LE};
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
static const xx_data_struct_field_desc sxzxm_stc_positions_fields[]={
 SX_FIELD("last_position_index","uint8",0,1,SX_NONE),
};
const sx_layout sxzxm_stc_positions={UINT32_C(0x608A0037),"stc_positions",sxzxm_stc_positions_fields,SX_COUNT(sxzxm_stc_positions_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st3_position_fields[]={
 SX_FIELD("transposition","int8",0,1,SX_NONE),
 SX_FIELD("pattern_table_offset","uint8",1,1,SX_OFFSET),
};
const sx_layout sxzxm_st3_position={UINT32_C(0x608A0040),"st3_position",sxzxm_st3_position_fields,SX_COUNT(sxzxm_st3_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st3_sample_fields[]={
 SX_FIELD("loop_index","uint8",0,1,SX_NONE),
 SX_FIELD("loop_length","uint8",1,1,SX_COUNT_PROP),
};
const sx_layout sxzxm_st3_sample={UINT32_C(0x608A0042),"st3_sample",sxzxm_st3_sample_fields,SX_COUNT(sxzxm_st3_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stp_position_fields[]={
 SX_FIELD("pattern_table_offset","uint8",0,1,SX_OFFSET),
 SX_FIELD("transposition","int8",1,1,SX_NONE),
};
const sx_layout sxzxm_stp_position={UINT32_C(0x608A0047),"stp_position",sxzxm_stp_position_fields,SX_COUNT(sxzxm_stp_position_fields),SX_LE};
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
const sx_layout sxzxm_etracker_header={UINT32_C(0x608A004A),"etracker_header",sxzxm_etracker_header_fields,SX_COUNT(sxzxm_etracker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_etracker_pattern_fields[]={
 SX_FIELD("channel_0_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("channel_1_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("channel_2_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("channel_3_offset","uint16",6,2,SX_OFFSET),
 SX_FIELD("channel_4_offset","uint16",8,2,SX_OFFSET),
 SX_FIELD("channel_5_offset","uint16",10,2,SX_OFFSET),
};
const sx_layout sxzxm_etracker_pattern={UINT32_C(0x608A004B),"etracker_pattern",sxzxm_etracker_pattern_fields,SX_COUNT(sxzxm_etracker_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_etracker_sample_offset_fields[]={
 SX_FIELD("sample_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxzxm_etracker_sample_offset={UINT32_C(0x608A004C),"etracker_sample_offset",sxzxm_etracker_sample_offset_fields,SX_COUNT(sxzxm_etracker_sample_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_etracker_ornament_offset_fields[]={
 SX_FIELD("ornament_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxzxm_etracker_ornament_offset={UINT32_C(0x608A004D),"etracker_ornament_offset",sxzxm_etracker_ornament_offset_fields,SX_COUNT(sxzxm_etracker_ornament_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_etracker_position_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
};
const sx_layout sxzxm_etracker_position={UINT32_C(0x608A004E),"etracker_position",sxzxm_etracker_position_fields,SX_COUNT(sxzxm_etracker_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_chiptracker_header_fields[]={
 SX_FIELD("signature","char[5]",0,5,SX_NONE),
 SX_FIELD("version","char[3]",5,3,SX_NONE),
 SX_FIELD("title","char[32]",8,32,SX_NONE),
 SX_FIELD("tempo","uint8",40,1,SX_NONE),
 SX_FIELD("last_position_index","uint8",41,1,SX_NONE),
 SX_FIELD("loop_position","uint8",42,1,SX_NONE),
};
const sx_layout sxzxm_chiptracker_header={UINT32_C(0x608A004F),"chiptracker_header",sxzxm_chiptracker_header_fields,SX_COUNT(sxzxm_chiptracker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_chiptracker_sample_fields[]={
 SX_FIELD("loop_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("byte_length","uint16",2,2,SX_SIZE),
};
const sx_layout sxzxm_chiptracker_sample={UINT32_C(0x608A0050),"chiptracker_sample",sxzxm_chiptracker_sample_fields,SX_COUNT(sxzxm_chiptracker_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_chiptracker_sample_name_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_NONE),
};
const sx_layout sxzxm_chiptracker_sample_name={UINT32_C(0x608A0051),"chiptracker_sample_name",sxzxm_chiptracker_sample_name_fields,SX_COUNT(sxzxm_chiptracker_sample_name_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_dmm_playback_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("loop_position","uint8",1,1,SX_NONE),
 SX_FIELD("padding","uint8",2,1,SX_RESERVED),
 SX_FIELD("last_position_index","uint8",3,1,SX_NONE),
 SX_FIELD("header_sectors","uint8",4,1,SX_NONE),
};
const sx_layout sxzxm_dmm_playback={UINT32_C(0x608A0055),"dmm_playback",sxzxm_dmm_playback_fields,SX_COUNT(sxzxm_dmm_playback_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_sqd_layout_fields[]={
 SX_FIELD("address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("bank","uint8",2,1,SX_ID),
 SX_FIELD("sector_count","uint8",3,1,SX_COUNT_PROP),
};
const sx_layout sxzxm_sqd_layout={UINT32_C(0x608A0059),"sqd_layout",sxzxm_sqd_layout_fields,SX_COUNT(sxzxm_sqd_layout_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_sqd_positions_limit_fields[]={
 SX_FIELD("positions_limit","uint8",0,1,SX_NONE),
};
const sx_layout sxzxm_sqd_positions_limit={UINT32_C(0x608A005C),"sqd_positions_limit",sxzxm_sqd_positions_limit_fields,SX_COUNT(sxzxm_sqd_positions_limit_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_sqd_playback_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("loop_position","uint8",1,1,SX_NONE),
 SX_FIELD("last_position_index","uint8",2,1,SX_NONE),
};
const sx_layout sxzxm_sqd_playback={UINT32_C(0x608A005D),"sqd_playback",sxzxm_sqd_playback_fields,SX_COUNT(sxzxm_sqd_playback_fields),SX_LE};
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
const sx_layout sxzxm_ayst11_header={UINT32_C(0x608A005F),"ayst11_header",sxzxm_ayst11_header_fields,SX_COUNT(sxzxm_ayst11_header_fields),SX_BE};
static const xx_data_struct_field_desc sxzxm_ayst11_song_fields[]={
 SX_FIELD("name_delta","int16",0,2,SX_OFFSET),
 SX_FIELD("data_delta","int16",2,2,SX_OFFSET),
};
const sx_layout sxzxm_ayst11_song={UINT32_C(0x608A0060),"ayst11_song",sxzxm_ayst11_song_fields,SX_COUNT(sxzxm_ayst11_song_fields),SX_BE};
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
const sx_layout sxzxm_st1_sample={UINT32_C(0x608A0062),"st1_sample",sxzxm_st1_sample_fields,SX_COUNT(sxzxm_st1_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st1_song_length_fields[]={
 SX_FIELD("song_length","uint8",0,1,SX_NONE),
};
const sx_layout sxzxm_st1_song_length={UINT32_C(0x608A0064),"st1_song_length",sxzxm_st1_song_length_fields,SX_COUNT(sxzxm_st1_song_length_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st1_ornament_step_fields[]={
 SX_FIELD("encoded_pitch","uint8",0,1,SX_NONE),
};
const sx_layout sxzxm_st1_ornament_step={UINT32_C(0x608A0065),"st1_ornament_step",sxzxm_st1_ornament_step_fields,SX_COUNT(sxzxm_st1_ornament_step_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st1_playback_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("pattern_row_count","uint8",1,1,SX_COUNT_PROP),
};
const sx_layout sxzxm_st1_playback={UINT32_C(0x608A0066),"st1_playback",sxzxm_st1_playback_fields,SX_COUNT(sxzxm_st1_playback_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_rmt_binary_header_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_ID),
 SX_FIELD("load_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("end_address","uint16",4,2,SX_ADDRESS),
};
const sx_layout sxzxm_rmt_binary_header={UINT32_C(0x608A0067),"rmt_binary_header",sxzxm_rmt_binary_header_fields,SX_COUNT(sxzxm_rmt_binary_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_rmt_binary_segment_fields[]={
 SX_FIELD("load_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("end_address","uint16",2,2,SX_ADDRESS),
};
const sx_layout sxzxm_rmt_binary_segment={UINT32_C(0x608A0068),"rmt_binary_segment",sxzxm_rmt_binary_segment_fields,SX_COUNT(sxzxm_rmt_binary_segment_fields),SX_LE};
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
const sx_layout sxzxm_rmt_header={UINT32_C(0x608A0069),"rmt_header",sxzxm_rmt_header_fields,SX_COUNT(sxzxm_rmt_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_rmt_track_low_fields[]={
 SX_FIELD("track_address_low","uint8",0,1,SX_NONE),
};
const sx_layout sxzxm_rmt_track_low={UINT32_C(0x608A006B),"rmt_track_low",sxzxm_rmt_track_low_fields,SX_COUNT(sxzxm_rmt_track_low_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_rmt_track_high_fields[]={
 SX_FIELD("track_address_high","uint8",0,1,SX_NONE),
};
const sx_layout sxzxm_rmt_track_high={UINT32_C(0x608A006C),"rmt_track_high",sxzxm_rmt_track_high_fields,SX_COUNT(sxzxm_rmt_track_high_fields),SX_LE};
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
const sx_layout sxzxm_rmt_instrument={UINT32_C(0x608A006D),"rmt_instrument",sxzxm_rmt_instrument_fields,SX_COUNT(sxzxm_rmt_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_digitalstudio_header_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("position_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("title","char[28]",2,28,SX_NONE),
 SX_FIELD("unknown","bytes",30,70,SX_NONE),
 SX_FIELD("compiled_marker_area","bytes",100,56,SX_NONE),
};
const sx_layout sxzxm_digitalstudio_header={UINT32_C(0x608A006F),"digitalstudio_header",sxzxm_digitalstudio_header_fields,SX_COUNT(sxzxm_digitalstudio_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_digitalstudio_sample_fields[]={
 SX_FIELD("start_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("loop_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("page","uint8",4,1,SX_ID),
 SX_FIELD("index_in_bank","uint8",5,1,SX_NONE),
 SX_FIELD("byte_size","uint16",6,2,SX_SIZE),
 SX_FIELD("name","char[8]",8,8,SX_NONE),
};
const sx_layout sxzxm_digitalstudio_sample={UINT32_C(0x608A0070),"digitalstudio_sample",sxzxm_digitalstudio_sample_fields,SX_COUNT(sxzxm_digitalstudio_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_extremetracker_header_fields[]={
 SX_FIELD("loop_position","uint8",0,1,SX_NONE),
 SX_FIELD("tempo","uint8",1,1,SX_NONE),
 SX_FIELD("position_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("title","char[30]",3,30,SX_NONE),
 SX_FIELD("unknown","uint8",33,1,SX_NONE),
};
const sx_layout sxzxm_extremetracker_header={UINT32_C(0x608A0072),"extremetracker_header",sxzxm_extremetracker_header_fields,SX_COUNT(sxzxm_extremetracker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_extremetracker_memory_fields[]={
 SX_FIELD("rest_blocks","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("page","uint8",1,1,SX_ID),
 SX_FIELD("free_start_block","uint8",2,1,SX_NONE),
 SX_FIELD("sample_count","uint8",3,1,SX_COUNT_PROP),
};
const sx_layout sxzxm_extremetracker_memory={UINT32_C(0x608A0074),"extremetracker_memory",sxzxm_extremetracker_memory_fields,SX_COUNT(sxzxm_extremetracker_memory_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_extremetracker_sample_fields[]={
 SX_FIELD("start_address","uint16",0,2,SX_ADDRESS),
 SX_FIELD("loop_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("page","uint8",4,1,SX_ID),
 SX_FIELD("index_in_page","uint8",5,1,SX_NONE),
 SX_FIELD("block_count","uint8",6,1,SX_COUNT_PROP),
 SX_FIELD("padding","uint8",7,1,SX_NONE),
 SX_FIELD("name","char[8]",8,8,SX_NONE),
};
const sx_layout sxzxm_extremetracker_sample={UINT32_C(0x608A0075),"extremetracker_sample",sxzxm_extremetracker_sample_fields,SX_COUNT(sxzxm_extremetracker_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_extremetracker_event_fields[]={
 SX_FIELD("note_command","uint8",0,1,SX_FLAGS),
 SX_FIELD("sample_parameter","uint8",1,1,SX_FLAGS),
};
const sx_layout sxzxm_extremetracker_event={UINT32_C(0x608A0076),"extremetracker_event",sxzxm_extremetracker_event_fields,SX_COUNT(sxzxm_extremetracker_event_fields),SX_LE};
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
bool sxzxm_span(sx_context*c,uint64_t p,uint64_t n){return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
bool sxzxm_read(sx_context*c,uint64_t p,void*b,size_t n){return sxzxm_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint16_t sxzxm16(const uint8_t*b){return (uint16_t)b[0]|(uint16_t)((uint16_t)b[1]<<8);}
bool sxzxm_u16(sx_context*c,uint64_t p,uint16_t*v){uint8_t b[2];if(!sxzxm_read(c,p,b,2))return false;*v=sxzxm16(b);return true;}
bool sxzxm_u8(sx_context*c,uint64_t p,uint8_t*v){return sxzxm_read(c,p,v,1);}
bool sxzxm_eq(sx_context*c,uint64_t p,const char*s,size_t n){uint8_t b[64];return n<=sizeof(b)&&sxzxm_read(c,p,b,n)&&!xx_rt_memcmp(b,s,n);}
static uint64_t sxzxm_width(const sx_layout*l){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;return (uint64_t)f->rel_offset+(uint64_t)f->size;}
/* Insert only disjoint physical records. Shared pointers are decoded once;
 * conflicting interpretations remain covered by the first authenticated row.
 * Display-budget exhaustion retains earlier metadata and raw remainder. */
bool sxzxm_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){
 uint64_t z=sxzxm_width(l);if(!count)return true;if(!z||count>UINT64_MAX/z||!sxzxm_span(c,p,count*z))return false;
 if(c->count>=SXZXM_LIMIT)return true;
 uint64_t end=p+count*z;
 for(size_t i=0;i<c->count;i++){int64_t rel=c->items[i].offset-c->f->base_address;uint64_t n=(uint64_t)c->items[i].total_size;
  if(rel>=0&&p<(uint64_t)rel+n&&(uint64_t)rel<end)return true;}
 return count==1?sx_add(c,l,(int64_t)p,(int64_t)z):sx_table(c,l,(int64_t)p,(int64_t)z,(int64_t)count);
}
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
bool sxzxm_opt(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){uint64_t z=sxzxm_width(l);return !count||!z||count>UINT64_MAX/z||!sxzxm_span(c,p,count*z)?true:sxzxm_put(c,l,p,count);}
static int sxzxm_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset;}
static bool sxzxm_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxzxm_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end||z<=0||p>c->size||z>c->size-p)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxzxm_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxzxm_lines(sx_context*c,const sx_layout*l,uint64_t p,unsigned count){return sxzxm_opt(c,l,p,count);}
/* Instrument lists carry absolute module offsets unless a caller supplies an
 * explicit relative-table or target-memory base. Never modify stored values. */
bool sxzxm_object(sx_context*c,uint64_t p,unsigned kind){
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
bool sxzxm_pt(sx_context*c,unsigned version){
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
bool sxzxm_asc(sx_context*c,bool v1){
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
 case XX_FILE_TYPE_DIE_MUSIC_ALONECODER_CHIPTRACKER:ok=sx_alonecoder_chiptracker_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_WOLOSZYK_ETRACKER:ok=sx_woloszyk_etracker_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_BZYK_SOUNDTRACKER_AYST11:ok=sx_bzyk_soundtracker_ayst11_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_DEXUS_PROSOUNDMAKER:ok=sx_dexus_prosoundmaker_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_ASC_ADVANCEDSOUNDMASTER_V1:ok=sx_asc_advancedsoundmaster_v1_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_ASC_ADVANCEDSOUNDMASTER_V0:ok=sx_asc_advancedsoundmaster_v0_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_DOCTORMAX_GLOBALTRACKER_GTR:ok=sx_doctormax_globaltracker_gtr_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_GOLDENDISK_PROTRACKER_PT1_CO:ok=sx_goldendisk_protracker_pt1_co_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_GOLDENDISK_PROTRACKER_PT2:ok=sx_goldendisk_protracker_pt2_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_GOLDENDISK_PROTRACKER_PT3:ok=sx_goldendisk_protracker_pt3_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_KVA_PROSOUNDCREATOR:ok=sx_kva_prosoundcreator_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_ORIONSAND_FASTTRACKER_FTC:ok=sx_orionsand_fasttracker_ftc_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_KSA_SOUNDTRACKERPRO_STP:ok=sx_ksa_soundtrackerpro_stp_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_BZYK_SOUNDTRACKER_STC_ZXS:ok=sx_bzyk_soundtracker_stc_zxs_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_STMUSICSTCRECOMPV2_ST3:ok=sx_stmusicstcrecompv2_st3_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_LAVE_DIGITALMUSICMAKER:ok=sx_lave_digitalmusicmaker_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_RASTER_MUSICTRACKER:ok=sx_raster_musictracker_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_SQDIGITALTRACKER:ok=sx_sqdigitaltracker_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_UNDERGROUNDSYSTEMS_DIGITALSTUDIO:ok=sx_undergroundsystems_digitalstudio_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_REDLIMITED_EXTREMETRACKER:ok=sx_redlimited_extremetracker_build(c);break;
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
const sx_family sx_zxmusic_family={sx_zxmusic_supports,sx_zxmusic_build,sx_zxmusic_layouts,SX_COUNT(sx_zxmusic_layouts),sx_zxmusic_comment};
