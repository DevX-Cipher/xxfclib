/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical music header and table metadata; compressed and unknown bodies stay raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_musictail.h"
static const xx_data_struct_field_desc sxmta_text_fields[]={
 SX_FIELD("text","char",0,0,SX_NONE),
};
static const sx_layout sxmta_text={UINT32_C(0x60810001),"text",sxmta_text_fields,SX_COUNT(sxmta_text_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_order8_fields[]={
 SX_FIELD("pattern","uint8",0,1,SX_ID),
};
const sx_layout sxmta_order8={UINT32_C(0x60810004),"order8",sxmta_order8_fields,SX_COUNT(sxmta_order8_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_order16be_fields[]={
 SX_FIELD("pattern","uint16",0,2,SX_ID),
};
const sx_layout sxmta_order16be={UINT32_C(0x60810005),"order16be",sxmta_order16be_fields,SX_COUNT(sxmta_order16be_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_count16be_fields[]={
 SX_FIELD("count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxmta_count16be={UINT32_C(0x60810007),"count16be",sxmta_count16be_fields,SX_COUNT(sxmta_count16be_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_volume8_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
};
const sx_layout sxmta_volume8={UINT32_C(0x60810008),"volume8",sxmta_volume8_fields,SX_COUNT(sxmta_volume8_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_pan16be_fields[]={
 SX_FIELD("pan","uint16",0,2,SX_NONE),
};
const sx_layout sxmta_pan16be={UINT32_C(0x60810009),"pan16be",sxmta_pan16be_fields,SX_COUNT(sxmta_pan16be_fields),SX_BE};
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
static const xx_data_struct_field_desc sxmta_gtk_sample1_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_NONE),
 SX_FIELD("sample_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("loop_start","uint32",36,4,SX_OFFSET),
 SX_FIELD("loop_bytes","uint32",40,4,SX_SIZE),
 SX_FIELD("volume","uint16",44,2,SX_NONE),
 SX_FIELD("finetune","int16",46,2,SX_NONE),
};
const sx_layout sxmta_gtk_sample1={UINT32_C(0x6081000D),"gtk_sample1",sxmta_gtk_sample1_fields,SX_COUNT(sxmta_gtk_sample1_fields),SX_BE};
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
const sx_layout sxmta_gtk_sample2={UINT32_C(0x6081000E),"gtk_sample2",sxmta_gtk_sample2_fields,SX_COUNT(sxmta_gtk_sample2_fields),SX_BE};
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
const sx_layout sxmta_gtk_sample3={UINT32_C(0x6081000F),"gtk_sample3",sxmta_gtk_sample3_fields,SX_COUNT(sxmta_gtk_sample3_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gtk_event5_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("effect","uint8",2,1,SX_ID),
 SX_FIELD("parameter","uint8",3,1,SX_NONE),
 SX_FIELD("volume","uint8",4,1,SX_NONE),
};
const sx_layout sxmta_gtk_event5={UINT32_C(0x60810011),"gtk_event5",sxmta_gtk_event5_fields,SX_COUNT(sxmta_gtk_event5_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_gt2_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("chunk_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxmta_gt2_chunk={UINT32_C(0x60810014),"gt2_chunk",sxmta_gt2_chunk_fields,SX_COUNT(sxmta_gt2_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_pattern_fields[]={
 SX_FIELD("pattern","uint16",0,2,SX_ID),
 SX_FIELD("name","char[16]",2,16,SX_NONE),
 SX_FIELD("coding","uint16",18,2,SX_ID),
 SX_FIELD("rows","uint16",20,2,SX_COUNT_PROP),
 SX_FIELD("tracks","uint16",22,2,SX_COUNT_PROP),
};
const sx_layout sxmta_gt2_pattern={UINT32_C(0x60810016),"gt2_pattern",sxmta_gt2_pattern_fields,SX_COUNT(sxmta_gt2_pattern_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_timing_fields[]={
 SX_FIELD("version","uint16",0,2,SX_ID),
 SX_FIELD("tempo_integer","uint16",2,2,SX_NONE),
 SX_FIELD("tempo_fraction","uint16",4,2,SX_NONE),
 SX_FIELD("speed","uint16",6,2,SX_NONE),
 SX_FIELD("time_signature_numerator","uint16",8,2,SX_NONE),
 SX_FIELD("time_signature_denominator","uint16",10,2,SX_NONE),
};
const sx_layout sxmta_gt2_timing={UINT32_C(0x60810018),"gt2_timing",sxmta_gt2_timing_fields,SX_COUNT(sxmta_gt2_timing_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gt2_period_mode_fields[]={
 SX_FIELD("period_mode","uint16",0,2,SX_ID),
};
const sx_layout sxmta_gt2_period_mode={UINT32_C(0x60810019),"gt2_period_mode",sxmta_gt2_period_mode_fields,SX_COUNT(sxmta_gt2_period_mode_fields),SX_BE};
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
const sx_layout sxmta_gt2_sample1={UINT32_C(0x6081001A),"gt2_sample1",sxmta_gt2_sample1_fields,SX_COUNT(sxmta_gt2_sample1_fields),SX_BE};
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
const sx_layout sxmta_gt2_sample2={UINT32_C(0x6081001B),"gt2_sample2",sxmta_gt2_sample2_fields,SX_COUNT(sxmta_gt2_sample2_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_tcb_header_fields[]={
 SX_FIELD("magic","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("patterns","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("tempo","uint8",12,1,SX_NONE),
 SX_FIELD("unused","uint8",13,1,SX_RESERVED),
 SX_FIELD("orders","bytes",14,128,SX_NONE),
 SX_FIELD("order_count","uint8",142,1,SX_COUNT_PROP),
 SX_FIELD("unused2","uint8",143,1,SX_RESERVED),
};
const sx_layout sxmta_tcb_header={UINT32_C(0x6081001E),"tcb_header",sxmta_tcb_header_fields,SX_COUNT(sxmta_tcb_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_tcb_sample_location_fields[]={
 SX_FIELD("sample_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("sample_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxmta_tcb_sample_location={UINT32_C(0x60810025),"tcb_sample_location",sxmta_tcb_sample_location_fields,SX_COUNT(sxmta_tcb_sample_location_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gmc_sample_fields[]={
 SX_FIELD("sample_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("sample_words","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("zero","uint8",6,1,SX_RESERVED),
 SX_FIELD("volume","uint8",7,1,SX_NONE),
 SX_FIELD("sample_address","uint32",8,4,SX_ADDRESS),
 SX_FIELD("loop_words","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("trimmed_bytes","uint16",14,2,SX_SIZE),
};
const sx_layout sxmta_gmc_sample={UINT32_C(0x60810026),"gmc_sample",sxmta_gmc_sample_fields,SX_COUNT(sxmta_gmc_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_gmc_pattern_offset_fields[]={
 SX_FIELD("pattern_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxmta_gmc_pattern_offset={UINT32_C(0x60810028),"gmc_pattern_offset",sxmta_gmc_pattern_offset_fields,SX_COUNT(sxmta_gmc_pattern_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_kris_track_ref_fields[]={
 SX_FIELD("track","uint8",0,1,SX_ID),
 SX_FIELD("transpose","int8",1,1,SX_NONE),
};
const sx_layout sxmta_kris_track_ref={UINT32_C(0x6081002F),"kris_track_ref",sxmta_kris_track_ref_fields,SX_COUNT(sxmta_kris_track_ref_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_c67_sample_fields[]={
 SX_FIELD("unknown_zero","uint32",0,4,SX_NONE),
 SX_FIELD("sample_bytes","uint32",4,4,SX_SIZE),
 SX_FIELD("loop_start","uint32",8,4,SX_OFFSET),
 SX_FIELD("loop_end","uint32",12,4,SX_OFFSET),
};
const sx_layout sxmta_c67_sample={UINT32_C(0x60810033),"c67_sample",sxmta_c67_sample_fields,SX_COUNT(sxmta_c67_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_c67_pattern_offset_fields[]={
 SX_FIELD("pattern_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxmta_c67_pattern_offset={UINT32_C(0x60810035),"c67_pattern_offset",sxmta_c67_pattern_offset_fields,SX_COUNT(sxmta_c67_pattern_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dsym_sample_flags_fields[]={
 SX_FIELD("name_length_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxmta_dsym_sample_flags={UINT32_C(0x60810038),"dsym_sample_flags",sxmta_dsym_sample_flags_fields,SX_COUNT(sxmta_dsym_sample_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dsym_packing_fields[]={
 SX_FIELD("packing","uint8",0,1,SX_ID),
};
const sx_layout sxmta_dsym_packing={UINT32_C(0x6081003B),"dsym_packing",sxmta_dsym_packing_fields,SX_COUNT(sxmta_dsym_packing_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_sym_value_fields[]={
 SX_FIELD("chunk_id","int32",0,4,SX_ID),
 SX_FIELD("value","uint32",4,4,SX_NONE),
};
const sx_layout sxmta_sym_value={UINT32_C(0x6081003F),"sym_value",sxmta_sym_value_fields,SX_COUNT(sxmta_sym_value_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_sym_count_fields[]={
 SX_FIELD("chunk_id","int32",0,4,SX_ID),
 SX_FIELD("count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxmta_sym_count={UINT32_C(0x60810040),"sym_count",sxmta_sym_count_fields,SX_COUNT(sxmta_sym_count_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_sym_bytes_fields[]={
 SX_FIELD("chunk_id","int32",0,4,SX_ID),
 SX_FIELD("bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxmta_sym_bytes={UINT32_C(0x60810041),"sym_bytes",sxmta_sym_bytes_fields,SX_COUNT(sxmta_sym_bytes_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_sym_empty_sample_fields[]={
 SX_FIELD("chunk_id","int32",0,4,SX_ID),
};
const sx_layout sxmta_sym_empty_sample={UINT32_C(0x60810042),"sym_empty_sample",sxmta_sym_empty_sample_fields,SX_COUNT(sxmta_sym_empty_sample_fields),SX_BE};
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
static const xx_data_struct_field_desc sxmta_galaxy_point5_signed_fields[]={
 SX_FIELD("tick_16x","uint16",0,2,SX_NONE),
 SX_FIELD("value","int16",2,2,SX_NONE),
};
static const sx_layout sxmta_galaxy_point5_signed={UINT32_C(0x60810053),"galaxy_point5_signed",sxmta_galaxy_point5_signed_fields,SX_COUNT(sxmta_galaxy_point5_signed_fields),SX_LE};
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
const sx_layout sxmta_aon_sample={UINT32_C(0x60810057),"aon_sample",sxmta_aon_sample_fields,SX_COUNT(sxmta_aon_sample_fields),SX_BE};
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
const sx_layout sxmta_aon_synth={UINT32_C(0x60810058),"aon_synth",sxmta_aon_synth_fields,SX_COUNT(sxmta_aon_synth_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_dmu_sample_fields[]={
 SX_FIELD("start_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("end_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("loop_start","int32",8,4,SX_OFFSET),
 SX_FIELD("unused","bytes",12,20,SX_NONE),
};
const sx_layout sxmta_dmu_sample={UINT32_C(0x60810060),"dmu_sample",sxmta_dmu_sample_fields,SX_COUNT(sxmta_dmu_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_bp_sample_fields[]={
 SX_FIELD("name","char[24]",0,24,SX_NONE),
 SX_FIELD("sample_words","uint16",24,2,SX_COUNT_PROP),
 SX_FIELD("loop_start","uint16",26,2,SX_OFFSET),
 SX_FIELD("loop_words","uint16",28,2,SX_COUNT_PROP),
 SX_FIELD("volume","uint16",30,2,SX_NONE),
};
const sx_layout sxmta_bp_sample={UINT32_C(0x60810067),"bp_sample",sxmta_bp_sample_fields,SX_COUNT(sxmta_bp_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_fuchs_volume_fields[]={
 SX_FIELD("volume","uint16",0,2,SX_NONE),
};
const sx_layout sxmta_fuchs_volume={UINT32_C(0x6081006E),"fuchs_volume",sxmta_fuchs_volume_fields,SX_COUNT(sxmta_fuchs_volume_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_fuchs_loop_fields[]={
 SX_FIELD("loop_start","uint16",0,2,SX_OFFSET),
};
const sx_layout sxmta_fuchs_loop={UINT32_C(0x6081006F),"fuchs_loop",sxmta_fuchs_loop_fields,SX_COUNT(sxmta_fuchs_loop_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_sid2_track_offset_fields[]={
 SX_FIELD("track_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxmta_sid2_track_offset={UINT32_C(0x60810076),"sid2_track_offset",sxmta_sid2_track_offset_fields,SX_COUNT(sxmta_sid2_track_offset_fields),SX_BE};
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
const sx_layout sxmta_sid2_instrument={UINT32_C(0x60810077),"sid2_instrument",sxmta_sid2_instrument_fields,SX_COUNT(sxmta_sid2_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_med2_loop_start_fields[]={
 SX_FIELD("loop_start","uint16",0,2,SX_OFFSET),
};
const sx_layout sxmta_med2_loop_start={UINT32_C(0x6081007B),"med2_loop_start",sxmta_med2_loop_start_fields,SX_COUNT(sxmta_med2_loop_start_fields),SX_BE};
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
const sx_layout sxmta_is1_header={UINT32_C(0x60810086),"is1_header",sxmta_is1_header_fields,SX_COUNT(sxmta_is1_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is_sample_bytes_fields[]={
 SX_FIELD("sample_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxmta_is_sample_bytes={UINT32_C(0x60810088),"is_sample_bytes",sxmta_is_sample_bytes_fields,SX_COUNT(sxmta_is_sample_bytes_fields),SX_BE};
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
const sx_layout sxmta_is1_instrument={UINT32_C(0x60810089),"is1_instrument",sxmta_is1_instrument_fields,SX_COUNT(sxmta_is1_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is_position_fields[]={
 SX_FIELD("start_track_row","uint16",0,2,SX_NONE),
 SX_FIELD("sound_transpose","int8",2,1,SX_NONE),
 SX_FIELD("note_transpose","int8",3,1,SX_NONE),
};
const sx_layout sxmta_is_position={UINT32_C(0x6081008B),"is_position",sxmta_is_position_fields,SX_COUNT(sxmta_is_position_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is1_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("arpeggio_effect","uint8",2,1,SX_FLAGS),
 SX_FIELD("argument","uint8",3,1,SX_NONE),
};
const sx_layout sxmta_is1_event={UINT32_C(0x6081008C),"is1_event",sxmta_is1_event_fields,SX_COUNT(sxmta_is1_event_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_is_unsigned_value_fields[]={
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
const sx_layout sxmta_is_unsigned_value={UINT32_C(0x6081008D),"is_unsigned_value",sxmta_is_unsigned_value_fields,SX_COUNT(sxmta_is_unsigned_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmta_is2_subsong_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
 SX_FIELD("rows_per_track","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("first_position","uint16",2,2,SX_NONE),
 SX_FIELD("last_position","uint16",4,2,SX_NONE),
 SX_FIELD("restart_position","uint16",6,2,SX_NONE),
 SX_FIELD("frequency_hz","uint16",8,2,SX_NONE),
};
const sx_layout sxmta_is2_subsong={UINT32_C(0x60810091),"is2_subsong",sxmta_is2_subsong_fields,SX_COUNT(sxmta_is2_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is2_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument","uint8",1,1,SX_ID),
 SX_FIELD("transpose_arpeggio_effect","uint8",2,1,SX_FLAGS),
 SX_FIELD("argument","uint8",3,1,SX_NONE),
};
const sx_layout sxmta_is2_event={UINT32_C(0x60810092),"is2_event",sxmta_is2_event_fields,SX_COUNT(sxmta_is2_event_fields),SX_LE};
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
const sx_layout sxmta_is2_sample={UINT32_C(0x60810093),"is2_sample",sxmta_is2_sample_fields,SX_COUNT(sxmta_is2_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxmta_is2_sample_copy_fields[]={
 SX_FIELD("uninterpreted_copy","bytes",0,8,SX_NONE),
};
const sx_layout sxmta_is2_sample_copy={UINT32_C(0x60810095),"is2_sample_copy",sxmta_is2_sample_copy_fields,SX_COUNT(sxmta_is2_sample_copy_fields),SX_LE};
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
const sx_layout sxmta_is2_synth={UINT32_C(0x60810096),"is2_synth",sxmta_is2_synth_fields,SX_COUNT(sxmta_is2_synth_fields),SX_BE};
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
const sx_layout sxmta_is2_arpeggio={UINT32_C(0x60810097),"is2_arpeggio",sxmta_is2_arpeggio_fields,SX_COUNT(sxmta_is2_arpeggio_fields),SX_LE};
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
bool sxmta_span(sxmta_view*v,uint64_t at,uint64_t n,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&v->c->size>=0&&end<=(uint64_t)v->c->size&&at<=end&&n<=end-at;}
bool sxmta_read(sxmta_view*v,uint64_t at,void*p,size_t n,uint64_t end)
{return ++v->work<=4000000&&sxmta_span(v,at,n,end)&&sx_read(v->c,(int64_t)at,p,n);}
static bool sxmta_word(sxmta_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!n||n>8||!sxmta_read(v,at,b,n,end))return false;uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[be?n-i-1:i]<<(8*i);*out=x;return true;}
bool sxmta_row(sxmta_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxmta_span(v,at,z,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)z);}
#define MTA_ROW(l,at,end) sxmta_row(v,&sxmta_##l,(at),(end))
bool sxmta_table(sxmta_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>4000000||count>UINT64_MAX/z||!sxmta_span(v,at,count*z,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++,at+=z)if(!sxmta_row(v,l,at,end))return false;return true;}
static int sxmta_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxmta_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxmta_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxmta_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
bool sxmta_u(sxmta_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxmta_word(v,p,n,false,x,end);}
bool sxmta_be(sxmta_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxmta_word(v,p,n,true,x,end);}
bool sxmta_eq(sxmta_view*v,uint64_t p,const char*s,size_t n,uint64_t end){uint8_t b[64];return n<=sizeof(b)&&sxmta_read(v,p,b,n,end)&&!xx_rt_memcmp(b,s,n);}
bool sxmta_text_emit(sxmta_view*v,uint64_t p,uint64_t n,uint64_t end){if(!sxmta_span(v,p,n,end))return false;return !n||n>4096||v->c->count>=24000||sx_add(v->c,&sxmta_text,(int64_t)p,(int64_t)n);}
bool sxmta_take(sxmta_view*v,const sx_layout*l,uint64_t*p,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!sxmta_table(v,l,*p,count,end))return false;*p+=count*z;return true;}
bool sxmta_skip(sxmta_view*v,uint64_t*p,uint64_t n,uint64_t end)
{if(!sxmta_span(v,*p,n,end))return false;*p+=n;return true;}
#define MTA_TAKE(l,p,n,end) sxmta_take(v,&sxmta_##l,(p),(n),(end))
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
bool sxmta_galaxy(sxmta_view*v,bool packed)
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
case XX_FILE_TYPE_DIE_MUSIC_TWICE_ARTOFNOISE:ok=sx_twice_artofnoise_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_RHINO_DIGITALMUGICIAN:ok=sx_rhino_digitalmugician_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_DUMBO_GRAOUMFTRACKER:ok=sx_dumbo_graoumftracker_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_DUMBO_GRAOUMFTRACKER2:ok=sx_dumbo_graoumftracker2_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_JAZZJR2_GSS_UNP:ok=sx_jazzjr2_gss_unp_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_JAZZJR2_GSS_CO:ok=sx_jazzjr2_gss_co_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_MENG_SYMPHONIE_SYMMOD:ok=sx_meng_symphonie_symmod_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_OREGANDEV_DIGITALSYMPHONY:ok=sx_oregandev_digitalsymphony_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_BETRAYAL_JAMCRACKER:ok=sx_betrayal_jamcracker_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_POSTMA_SOUNDMON_BP:ok=sx_postma_soundmon_bp_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_ANCOOL_TCBTRACKER:ok=sx_ancool_tcbtracker_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_TRAN_CDFM_COMPOSER670:ok=sx_tran_cdfm_composer670_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_CHRONS_UNIMODTRK:ok=sx_chrons_unimodtrk_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_BERGSTEDT_SIMS_INSTEREO1:ok=sx_bergstedt_sims_instereo1_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_BERGSTEDT_SIMS_INSTEREO2:ok=sx_bergstedt_sims_instereo2_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_KINNUNEN_OCTAMED_MED:ok=sx_kinnunen_octamed_med_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_FUCHS_TRACKER:ok=sx_fuchs_tracker_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_TADIC_GAMEMUSICCREATOR:ok=sx_tadic_gamemusiccreator_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_WOMBELL_CHIPTRACKER_KRIS:ok=sx_wombell_chiptracker_kris_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_KLEPS_SIDMON2:ok=sx_kleps_sidmon2_build(v);break;
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
const sx_family sx_musictail_family={sx_musictail_supports,sx_musictail_build,sx_musictail_layouts,SX_COUNT(sx_musictail_layouts),sx_musictail_comment};
