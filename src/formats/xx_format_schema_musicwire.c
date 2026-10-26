/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical music header and table metadata; compressed and unknown bodies stay raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_musicwire.h"
static const xx_data_struct_field_desc sxmw_text_fields[]={
 SX_FIELD("text","char",0,0,SX_NONE),
};
static const sx_layout sxmw_text={UINT32_C(0x60870001),"text",sxmw_text_fields,SX_COUNT(sxmw_text_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_nul_fields[]={
 SX_FIELD("terminator","uint8",0,1,SX_RESERVED),
};
static const sx_layout sxmw_nul={UINT32_C(0x60870002),"nul",sxmw_nul_fields,SX_COUNT(sxmw_nul_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_pascal_text_length_fields[]={
 SX_FIELD("text_bytes","uint8",0,1,SX_SIZE),
};
const sx_layout sxmw_pascal_text_length={UINT32_C(0x60870003),"pascal_text_length",sxmw_pascal_text_length_fields,SX_COUNT(sxmw_pascal_text_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_chunk_le_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("payload_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxmw_chunk_le={UINT32_C(0x60870008),"chunk_le",sxmw_chunk_le_fields,SX_COUNT(sxmw_chunk_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_bmx_connection_fields[]={
 SX_FIELD("source_machine","uint16",0,2,SX_ID),
 SX_FIELD("destination_machine","uint16",2,2,SX_ID),
 SX_FIELD("amplitude","uint16",4,2,SX_NONE),
 SX_FIELD("pan","uint16",6,2,SX_NONE),
};
const sx_layout sxmw_bmx_connection={UINT32_C(0x6087000B),"bmx_connection",sxmw_bmx_connection_fields,SX_COUNT(sxmw_bmx_connection_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_bmx_sequences_fields[]={
 SX_FIELD("song_end_tick","uint32",0,4,SX_NONE),
 SX_FIELD("loop_start_tick","uint32",4,4,SX_NONE),
 SX_FIELD("loop_end_tick","uint32",8,4,SX_NONE),
 SX_FIELD("sequence_count","uint16",12,2,SX_COUNT_PROP),
};
const sx_layout sxmw_bmx_sequences={UINT32_C(0x6087000C),"bmx_sequences",sxmw_bmx_sequences_fields,SX_COUNT(sxmw_bmx_sequences_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_bnk_instrument_fields[]={
 SX_FIELD("mode","uint8",0,1,SX_ID),
 SX_FIELD("percussion_voice","uint8",1,1,SX_ID),
};
const sx_layout sxmw_bnk_instrument={UINT32_C(0x60870012),"bnk_instrument",sxmw_bnk_instrument_fields,SX_COUNT(sxmw_bnk_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_mtk_header_fields[]={
 SX_FIELD("magic","bytes",0,18,SX_SIGNATURE),
 SX_FIELD("crc","uint16",18,2,SX_CHECKSUM),
 SX_FIELD("decoded_bytes","uint16",20,2,SX_SIZE),
};
const sx_layout sxmw_mtk_header={UINT32_C(0x60870017),"mtk_header",sxmw_mtk_header_fields,SX_COUNT(sxmw_mtk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_madg_instrument_fields[]={
 SX_FIELD("filename","char[32]",0,32,SX_NONE),
 SX_FIELD("sample_bytes","int32",32,4,SX_SIZE),
 SX_FIELD("finetune","uint8",36,1,SX_NONE),
 SX_FIELD("volume","uint8",37,1,SX_NONE),
 SX_FIELD("compression_code","int16",38,2,SX_ID),
 SX_FIELD("base_frequency","int16",40,2,SX_NONE),
 SX_FIELD("amplitude_bits","uint8",42,1,SX_NONE),
 SX_FIELD("padding","uint8",43,1,SX_RESERVED),
 SX_FIELD("loop_start","int32",44,4,SX_OFFSET),
 SX_FIELD("loop_bytes","int32",48,4,SX_SIZE),
};
const sx_layout sxmw_madg_instrument={UINT32_C(0x60870019),"madg_instrument",sxmw_madg_instrument_fields,SX_COUNT(sxmw_madg_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxmw_pac_sound_fields[]={
 SX_FIELD("sound_index","uint16",0,2,SX_ID),
 SX_FIELD("reserved","uint16",2,2,SX_RESERVED),
 SX_FIELD("finetune","uint8",4,1,SX_NONE),
 SX_FIELD("volume","uint16",5,2,SX_NONE),
 SX_FIELD("sound_type","uint16",7,2,SX_FLAGS),
 SX_FIELD("loop_start","uint32",9,4,SX_OFFSET),
 SX_FIELD("loop_end","uint32",13,4,SX_OFFSET),
 SX_FIELD("packing","uint8",17,1,SX_FLAGS),
};
const sx_layout sxmw_pac_sound={UINT32_C(0x60870021),"pac_sound",sxmw_pac_sound_fields,SX_COUNT(sxmw_pac_sound_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_dmf_timing_fields[]={
 SX_FIELD("highlight_a","uint8",0,1,SX_NONE),
 SX_FIELD("highlight_b","uint8",1,1,SX_NONE),
 SX_FIELD("time_base","uint8",2,1,SX_NONE),
 SX_FIELD("tick_time1","uint8",3,1,SX_NONE),
 SX_FIELD("tick_time2","uint8",4,1,SX_NONE),
 SX_FIELD("frames_mode","uint8",5,1,SX_ID),
 SX_FIELD("custom_hz_enabled","uint8",6,1,SX_FLAGS),
 SX_FIELD("custom_hz_ascii","char[3]",7,3,SX_NONE),
 SX_FIELD("rows_per_pattern","uint32",10,4,SX_COUNT_PROP),
 SX_FIELD("matrix_rows","uint8",14,1,SX_COUNT_PROP),
};
const sx_layout sxmw_dmf_timing={UINT32_C(0x60870024),"dmf_timing",sxmw_dmf_timing_fields,SX_COUNT(sxmw_dmf_timing_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_dmf_instrument_mode_fields[]={
 SX_FIELD("mode","uint8",0,1,SX_ID),
};
const sx_layout sxmw_dmf_instrument_mode={UINT32_C(0x60870026),"dmf_instrument_mode",sxmw_dmf_instrument_mode_fields,SX_COUNT(sxmw_dmf_instrument_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_tfd_command_fields[]={
 SX_FIELD("command","uint8",0,1,SX_ID),
};
const sx_layout sxmw_tfd_command={UINT32_C(0x6087002A),"tfd_command",sxmw_tfd_command_fields,SX_COUNT(sxmw_tfd_command_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_tfd_skip_fields[]={
 SX_FIELD("command","uint8",0,1,SX_ID),
 SX_FIELD("frames","uint8",1,1,SX_COUNT_PROP),
};
const sx_layout sxmw_tfd_skip={UINT32_C(0x6087002B),"tfd_skip",sxmw_tfd_skip_fields,SX_COUNT(sxmw_tfd_skip_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_rle_literal_fields[]={
 SX_FIELD("literal","uint8",0,1,SX_NONE),
};
static const sx_layout sxmw_rle_literal={UINT32_C(0x6087002E),"rle_literal",sxmw_rle_literal_fields,SX_COUNT(sxmw_rle_literal_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_rle_marker_fields[]={
 SX_FIELD("marker","uint8",0,1,SX_ID),
};
static const sx_layout sxmw_rle_marker={UINT32_C(0x6087002F),"rle_marker",sxmw_rle_marker_fields,SX_COUNT(sxmw_rle_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_rle_count_part_fields[]={
 SX_FIELD("count_part","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxmw_rle_count_part={UINT32_C(0x60870030),"rle_count_part",sxmw_rle_count_part_fields,SX_COUNT(sxmw_rle_count_part_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sci1_track_fields[]={
 SX_FIELD("track_type","uint8",0,1,SX_ID),
 SX_FIELD("track_offset","uint16",1,2,SX_OFFSET),
 SX_FIELD("unknown","bytes",3,2,SX_NONE),
 SX_FIELD("section_marker","uint8",5,1,SX_ID),
};
const sx_layout sxmw_sci1_track={UINT32_C(0x6087003B),"sci1_track",sxmw_sci1_track_fields,SX_COUNT(sxmw_sci1_track_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_adl_program_offset_fields[]={
 SX_FIELD("program_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxmw_adl_program_offset={UINT32_C(0x6087003F),"adl_program_offset",sxmw_adl_program_offset_fields,SX_COUNT(sxmw_adl_program_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_adl_instrument_offset_fields[]={
 SX_FIELD("instrument_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxmw_adl_instrument_offset={UINT32_C(0x60870040),"adl_instrument_offset",sxmw_adl_instrument_offset_fields,SX_COUNT(sxmw_adl_instrument_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sn2_header_fields[]={
 SX_FIELD("magic","bytes",0,3,SX_SIGNATURE),
 SX_FIELD("payload_bytes","uint32",3,4,SX_SIZE),
 SX_FIELD("unknown_a","uint32",7,4,SX_NONE),
 SX_FIELD("unknown_b","uint32",11,4,SX_NONE),
 SX_FIELD("loop_order","uint32",15,4,SX_NONE),
 SX_FIELD("tempo_control","uint32",19,4,SX_NONE),
 SX_FIELD("ticks_per_beat","uint32",23,4,SX_NONE),
 SX_FIELD("beats_per_measure","uint32",27,4,SX_NONE),
};
const sx_layout sxmw_sn2_header={UINT32_C(0x60870041),"sn2_header",sxmw_sn2_header_fields,SX_COUNT(sxmw_sn2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_tempo_fields[]={
 SX_FIELD("tempo","uint32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_tempo={UINT32_C(0x60870046),"sv_tempo",sxmw_sv_tempo_fields,SX_COUNT(sxmw_sv_tempo_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_time_grid_fields[]={
 SX_FIELD("time_grid","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmw_sv_time_grid={UINT32_C(0x60870048),"sv_time_grid",sxmw_sv_time_grid_fields,SX_COUNT(sxmw_sv_time_grid_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_time_grid2_fields[]={
 SX_FIELD("time_grid2","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmw_sv_time_grid2={UINT32_C(0x60870049),"sv_time_grid2",sxmw_sv_time_grid2_fields,SX_COUNT(sxmw_sv_time_grid2_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_timeline_position_fields[]={
 SX_FIELD("timeline_position","int32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_timeline_position={UINT32_C(0x60870051),"sv_timeline_position",sxmw_sv_timeline_position_fields,SX_COUNT(sxmw_sv_timeline_position_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_restart_position_fields[]={
 SX_FIELD("restart_position","int32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_restart_position={UINT32_C(0x60870052),"sv_restart_position",sxmw_sv_restart_position_fields,SX_COUNT(sxmw_sv_restart_position_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_link_module_fields[]={
 SX_FIELD("link_module","int32",0,4,SX_ID),
};
const sx_layout sxmw_sv_link_module={UINT32_C(0x60870063),"sv_link_module",sxmw_sv_link_module_fields,SX_COUNT(sxmw_sv_link_module_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_chunk_capacity_fields[]={
 SX_FIELD("chunk_capacity","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmw_sv_chunk_capacity={UINT32_C(0x60870066),"sv_chunk_capacity",sxmw_sv_chunk_capacity_fields,SX_COUNT(sxmw_sv_chunk_capacity_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_sv_sample_rate_fields[]={
 SX_FIELD("sample_rate","uint32",0,4,SX_NONE),
};
const sx_layout sxmw_sv_sample_rate={UINT32_C(0x60870068),"sv_sample_rate",sxmw_sv_sample_rate_fields,SX_COUNT(sxmw_sv_sample_rate_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_header_fields[]={
 SX_FIELD("magic","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("version","uint8",8,1,SX_ID),
};
static const sx_layout sxmw_kly_header={UINT32_C(0x6087006B),"kly_header",sxmw_kly_header_fields,SX_COUNT(sxmw_kly_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_channels_fields[]={
 SX_FIELD("channels","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxmw_kly_channels={UINT32_C(0x6087006C),"kly_channels",sxmw_kly_channels_fields,SX_COUNT(sxmw_kly_channels_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_time_signature_fields[]={
 SX_FIELD("time_signature","uint16",0,2,SX_NONE),
};
static const sx_layout sxmw_kly_time_signature={UINT32_C(0x6087006D),"kly_time_signature",sxmw_kly_time_signature_fields,SX_COUNT(sxmw_kly_time_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_sequence_step_fields[]={
 SX_FIELD("sequence_step","uint16",0,2,SX_NONE),
};
static const sx_layout sxmw_kly_sequence_step={UINT32_C(0x6087006E),"kly_sequence_step",sxmw_kly_sequence_step_fields,SX_COUNT(sxmw_kly_sequence_step_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_counts_fields[]={
 SX_FIELD("instruments","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("patterns","uint16",1,2,SX_COUNT_PROP),
};
static const sx_layout sxmw_kly_counts={UINT32_C(0x6087006F),"kly_counts",sxmw_kly_counts_fields,SX_COUNT(sxmw_kly_counts_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_sequence_count_fields[]={
 SX_FIELD("sequences","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmw_kly_sequence_count={UINT32_C(0x60870070),"kly_sequence_count",sxmw_kly_sequence_count_fields,SX_COUNT(sxmw_kly_sequence_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_length_fields[]={
 SX_FIELD("song_length","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("loop_position","uint16",2,2,SX_NONE),
};
static const sx_layout sxmw_kly_length={UINT32_C(0x60870071),"kly_length",sxmw_kly_length_fields,SX_COUNT(sxmw_kly_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_volume_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
};
static const sx_layout sxmw_kly_volume={UINT32_C(0x60870072),"kly_volume",sxmw_kly_volume_fields,SX_COUNT(sxmw_kly_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_pan_fields[]={
 SX_FIELD("pan","int8",0,1,SX_NONE),
};
static const sx_layout sxmw_kly_pan={UINT32_C(0x60870073),"kly_pan",sxmw_kly_pan_fields,SX_COUNT(sxmw_kly_pan_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_timing_fields[]={
 SX_FIELD("speed","uint8",0,1,SX_NONE),
 SX_FIELD("alternate_speed","uint8",1,1,SX_NONE),
 SX_FIELD("tick_rate","uint8",2,1,SX_NONE),
};
static const sx_layout sxmw_kly_timing={UINT32_C(0x60870074),"kly_timing",sxmw_kly_timing_fields,SX_COUNT(sxmw_kly_timing_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_flags_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxmw_kly_flags={UINT32_C(0x60870075),"kly_flags",sxmw_kly_flags_fields,SX_COUNT(sxmw_kly_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_multiplex_fields[]={
 SX_FIELD("multiplex_period","uint8",0,1,SX_NONE),
};
static const sx_layout sxmw_kly_multiplex={UINT32_C(0x60870076),"kly_multiplex",sxmw_kly_multiplex_fields,SX_COUNT(sxmw_kly_multiplex_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_pitch_fields[]={
 SX_FIELD("pitch_inaccuracy","uint8",0,1,SX_NONE),
};
static const sx_layout sxmw_kly_pitch={UINT32_C(0x60870077),"kly_pitch",sxmw_kly_pitch_fields,SX_COUNT(sxmw_kly_pitch_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_fx_count_fields[]={
 SX_FIELD("effects","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxmw_kly_fx_count={UINT32_C(0x60870078),"kly_fx_count",sxmw_kly_fx_count_fields,SX_COUNT(sxmw_kly_fx_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_fx_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("bit_drop","uint8",4,1,SX_NONE),
 SX_FIELD("chorus_rate","uint8",5,1,SX_NONE),
 SX_FIELD("chorus_min_delay","uint8",6,1,SX_NONE),
 SX_FIELD("chorus_max_delay","uint8",7,1,SX_NONE),
 SX_FIELD("chorus_separation","uint8",8,1,SX_NONE),
};
static const sx_layout sxmw_kly_fx={UINT32_C(0x60870079),"kly_fx",sxmw_kly_fx_fields,SX_COUNT(sxmw_kly_fx_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_spread_fields[]={
 SX_FIELD("stereo_spread","uint8",0,1,SX_NONE),
};
static const sx_layout sxmw_kly_spread={UINT32_C(0x6087007A),"kly_spread",sxmw_kly_spread_fields,SX_COUNT(sxmw_kly_spread_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_padding_fields[]={
 SX_FIELD("padding","uint8",0,1,SX_RESERVED),
};
static const sx_layout sxmw_kly_padding={UINT32_C(0x6087007B),"kly_padding",sxmw_kly_padding_fields,SX_COUNT(sxmw_kly_padding_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_tap_old_fields[]={
 SX_FIELD("delay","uint16",0,2,SX_NONE),
 SX_FIELD("gain","int16",2,2,SX_NONE),
};
static const sx_layout sxmw_kly_tap_old={UINT32_C(0x6087007C),"kly_tap_old",sxmw_kly_tap_old_fields,SX_COUNT(sxmw_kly_tap_old_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_tap_fields[]={
 SX_FIELD("delay","uint16",0,2,SX_NONE),
 SX_FIELD("gain","int16",2,2,SX_NONE),
 SX_FIELD("pan","uint8",4,1,SX_NONE),
 SX_FIELD("flags","uint8",5,1,SX_FLAGS),
};
static const sx_layout sxmw_kly_tap={UINT32_C(0x6087007D),"kly_tap",sxmw_kly_tap_fields,SX_COUNT(sxmw_kly_tap_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_downsample_fields[]={
 SX_FIELD("downsample","uint8",0,1,SX_NONE),
};
static const sx_layout sxmw_kly_downsample={UINT32_C(0x6087007E),"kly_downsample",sxmw_kly_downsample_fields,SX_COUNT(sxmw_kly_downsample_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_gain_fields[]={
 SX_FIELD("gain","uint8",0,1,SX_NONE),
};
static const sx_layout sxmw_kly_gain={UINT32_C(0x6087007F),"kly_gain",sxmw_kly_gain_fields,SX_COUNT(sxmw_kly_gain_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_legacy_tap_fields[]={
 SX_FIELD("gain","int32",0,4,SX_NONE),
 SX_FIELD("delay","int32",4,4,SX_NONE),
};
static const sx_layout sxmw_kly_legacy_tap={UINT32_C(0x60870080),"kly_legacy_tap",sxmw_kly_legacy_tap_fields,SX_COUNT(sxmw_kly_legacy_tap_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_instrument_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("oscillator_flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("attack","uint8",8,1,SX_NONE),
 SX_FIELD("decay","uint8",9,1,SX_NONE),
 SX_FIELD("sustain","uint8",10,1,SX_NONE),
 SX_FIELD("release","uint8",11,1,SX_NONE),
 SX_FIELD("sync_source","uint8",12,1,SX_ID),
 SX_FIELD("ring_mod_source","uint8",13,1,SX_ID),
 SX_FIELD("pulse_width","uint16",14,2,SX_NONE),
 SX_FIELD("volume","uint8",16,1,SX_NONE),
 SX_FIELD("program_steps","uint8",17,1,SX_COUNT_PROP),
};
static const sx_layout sxmw_kly_instrument={UINT32_C(0x60870081),"kly_instrument",sxmw_kly_instrument_fields,SX_COUNT(sxmw_kly_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_program_fields[]={
 SX_FIELD("command","uint16",0,2,SX_ID),
};
static const sx_layout sxmw_kly_program={UINT32_C(0x60870082),"kly_program",sxmw_kly_program_fields,SX_COUNT(sxmw_kly_program_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_instrument_control_fields[]={
 SX_FIELD("program_period","uint8",0,1,SX_NONE),
 SX_FIELD("vibrato_speed","uint8",1,1,SX_NONE),
 SX_FIELD("vibrato_depth","uint8",2,1,SX_NONE),
 SX_FIELD("pwm_speed","uint8",3,1,SX_NONE),
 SX_FIELD("pwm_depth","uint8",4,1,SX_NONE),
 SX_FIELD("slide_speed","uint8",5,1,SX_NONE),
 SX_FIELD("base_note","uint8",6,1,SX_NONE),
};
static const sx_layout sxmw_kly_instrument_control={UINT32_C(0x60870083),"kly_instrument_control",sxmw_kly_instrument_control_fields,SX_COUNT(sxmw_kly_instrument_control_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_finetune_fields[]={
 SX_FIELD("finetune","int8",0,1,SX_NONE),
};
static const sx_layout sxmw_kly_finetune={UINT32_C(0x60870084),"kly_finetune",sxmw_kly_finetune_fields,SX_COUNT(sxmw_kly_finetune_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_filter_fields[]={
 SX_FIELD("cutoff","uint16",0,2,SX_NONE),
 SX_FIELD("resonance","uint8",2,1,SX_NONE),
 SX_FIELD("type","uint8",3,1,SX_ID),
};
static const sx_layout sxmw_kly_filter={UINT32_C(0x60870085),"kly_filter",sxmw_kly_filter_fields,SX_COUNT(sxmw_kly_filter_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_buzz_fields[]={
 SX_FIELD("envelope_shape","uint8",0,1,SX_FLAGS),
 SX_FIELD("buzz_offset","int16",1,2,SX_NONE),
};
static const sx_layout sxmw_kly_buzz={UINT32_C(0x60870086),"kly_buzz",sxmw_kly_buzz_fields,SX_COUNT(sxmw_kly_buzz_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_fx_bus_fields[]={
 SX_FIELD("fx_bus","uint8",0,1,SX_ID),
};
static const sx_layout sxmw_kly_fx_bus={UINT32_C(0x60870087),"kly_fx_bus",sxmw_kly_fx_bus_fields,SX_COUNT(sxmw_kly_fx_bus_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_shapes_fields[]={
 SX_FIELD("vibrato_shape","uint8",0,1,SX_ID),
 SX_FIELD("vibrato_delay","uint8",1,1,SX_NONE),
 SX_FIELD("pwm_shape","uint8",2,1,SX_ID),
};
static const sx_layout sxmw_kly_shapes={UINT32_C(0x60870088),"kly_shapes",sxmw_kly_shapes_fields,SX_COUNT(sxmw_kly_shapes_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_lfsr_fields[]={
 SX_FIELD("lfsr_type","uint8",0,1,SX_ID),
};
static const sx_layout sxmw_kly_lfsr={UINT32_C(0x60870089),"kly_lfsr",sxmw_kly_lfsr_fields,SX_COUNT(sxmw_kly_lfsr_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_wave_index_fields[]={
 SX_FIELD("wave_index","uint8",0,1,SX_ID),
};
static const sx_layout sxmw_kly_wave_index={UINT32_C(0x6087008A),"kly_wave_index",sxmw_kly_wave_index_fields,SX_COUNT(sxmw_kly_wave_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_fm_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("modulation","uint8",4,1,SX_NONE),
 SX_FIELD("feedback","uint8",5,1,SX_NONE),
 SX_FIELD("harmonic","uint8",6,1,SX_NONE),
 SX_FIELD("attack","uint8",7,1,SX_NONE),
 SX_FIELD("decay","uint8",8,1,SX_NONE),
 SX_FIELD("sustain","uint8",9,1,SX_NONE),
 SX_FIELD("release","uint8",10,1,SX_NONE),
};
static const sx_layout sxmw_kly_fm={UINT32_C(0x6087008B),"kly_fm",sxmw_kly_fm_fields,SX_COUNT(sxmw_kly_fm_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_fm_attack_fields[]={
 SX_FIELD("attack_start","uint8",0,1,SX_NONE),
};
static const sx_layout sxmw_kly_fm_attack={UINT32_C(0x6087008C),"kly_fm_attack",sxmw_kly_fm_attack_fields,SX_COUNT(sxmw_kly_fm_attack_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_fm_wave_fields[]={
 SX_FIELD("wave_index","uint8",0,1,SX_ID),
};
static const sx_layout sxmw_kly_fm_wave={UINT32_C(0x6087008D),"kly_fm_wave",sxmw_kly_fm_wave_fields,SX_COUNT(sxmw_kly_fm_wave_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_sequence_fields[]={
 SX_FIELD("position","uint16",0,2,SX_NONE),
 SX_FIELD("pattern","uint16",2,2,SX_ID),
 SX_FIELD("note_offset","int8",4,1,SX_NONE),
};
static const sx_layout sxmw_kly_sequence={UINT32_C(0x6087008E),"kly_sequence",sxmw_kly_sequence_fields,SX_COUNT(sxmw_kly_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_sequence_old_fields[]={
 SX_FIELD("position","uint16",0,2,SX_NONE),
 SX_FIELD("pattern","uint16",2,2,SX_ID),
 SX_FIELD("note_offset","int8",4,1,SX_NONE),
 SX_FIELD("padding","uint8",5,1,SX_RESERVED),
};
static const sx_layout sxmw_kly_sequence_old={UINT32_C(0x6087008F),"kly_sequence_old",sxmw_kly_sequence_old_fields,SX_COUNT(sxmw_kly_sequence_old_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_pattern_fields[]={
 SX_FIELD("rows","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxmw_kly_pattern={UINT32_C(0x60870090),"kly_pattern",sxmw_kly_pattern_fields,SX_COUNT(sxmw_kly_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_kly_color_fields[]={
 SX_FIELD("color","uint8",0,1,SX_ID),
};
static const sx_layout sxmw_kly_color={UINT32_C(0x60870091),"kly_color",sxmw_kly_color_fields,SX_COUNT(sxmw_kly_color_fields),SX_LE};
static const sx_layout *const sx_musicwire_layouts[]={
 &sxmw_text,
 &sxmw_nul,
 &sxmw_pascal_text_length,
 &sxmw_count16,
 &sxmw_order8,
 &sxmw_order16,
 &sxmw_order32,
 &sxmw_chunk_le,
 &sxmw_bmx_header,
 &sxmw_bmx_section,
 &sxmw_bmx_connection,
 &sxmw_bmx_sequences,
 &sxmw_bmx_sequence,
 &sxmw_bmx_wave_data,
 &sxmw_bmx_wave_bytes,
 &sxmw_bnk_header,
 &sxmw_bnk_name,
 &sxmw_bnk_instrument,
 &sxmw_bnk_operator,
 &sxmw_bnk_waveforms,
 &sxmw_mo3_header,
 &sxmw_mo3_packed_length,
 &sxmw_mtk_header,
 &sxmw_madg_header,
 &sxmw_madg_instrument,
 &sxmw_madg_orders,
 &sxmw_madg_pattern,
 &sxmw_madg_event,
 &sxmw_pac_header,
 &sxmw_pac_info,
 &sxmw_pac_song,
 &sxmw_pac_pan,
 &sxmw_pac_sound,
 &sxmw_pac_event,
 &sxmw_dmf_header,
 &sxmw_dmf_timing,
 &sxmw_dmf_instrument_count,
 &sxmw_dmf_instrument_mode,
 &sxmw_dmf_fm,
 &sxmw_dmf_operator,
 &sxmw_tfd_header,
 &sxmw_tfd_command,
 &sxmw_tfd_skip,
 &sxmw_tfd_write,
 &sxmw_tfm_rle_header,
 &sxmw_rle_literal,
 &sxmw_rle_marker,
 &sxmw_rle_count_part,
 &sxmw_vge_header,
 &sxmw_laa_header,
 &sxmw_laa_chunk,
 &sxmw_laa_mdhd,
 &sxmw_midi_header,
 &sxmw_laa_old_header,
 &sxmw_laa_old_instrument,
 &sxmw_sci0_header,
 &sxmw_sci0_channel,
 &sxmw_sci1_header,
 &sxmw_sci1_track,
 &sxmw_sci1_section_end,
 &sxmw_adl_program8,
 &sxmw_adl_program16,
 &sxmw_adl_program_offset,
 &sxmw_adl_instrument_offset,
 &sxmw_sn2_header,
 &sxmw_sn2_chunk,
 &sxmw_sunvox_header,
 &sxmw_sv_version,
 &sxmw_sv_base_version,
 &sxmw_sv_tempo,
 &sxmw_sv_ticks_per_line,
 &sxmw_sv_time_grid,
 &sxmw_sv_time_grid2,
 &sxmw_sv_global_volume,
 &sxmw_sv_module_scale,
 &sxmw_sv_module_zoom,
 &sxmw_sv_module_x,
 &sxmw_sv_module_y,
 &sxmw_sv_layer_mask,
 &sxmw_sv_current_layer,
 &sxmw_sv_timeline_position,
 &sxmw_sv_restart_position,
 &sxmw_sv_selected_module,
 &sxmw_sv_last_generator,
 &sxmw_sv_tracks,
 &sxmw_sv_lines,
 &sxmw_sv_source_pattern,
 &sxmw_sv_flags,
 &sxmw_sv_x,
 &sxmw_sv_y,
 &sxmw_sv_finetune,
 &sxmw_sv_relative_note,
 &sxmw_sv_layer,
 &sxmw_sv_scale,
 &sxmw_sv_midi_in,
 &sxmw_sv_midi_channel,
 &sxmw_sv_midi_bank,
 &sxmw_sv_midi_program,
 &sxmw_sv_link_module,
 &sxmw_sv_controller_value,
 &sxmw_sv_chunk_number,
 &sxmw_sv_chunk_capacity,
 &sxmw_sv_chunk_format,
 &sxmw_sv_sample_rate,
 &sxmw_sv_color,
 &sxmw_sv_note,
 &sxmw_kly_header,
 &sxmw_kly_channels,
 &sxmw_kly_time_signature,
 &sxmw_kly_sequence_step,
 &sxmw_kly_counts,
 &sxmw_kly_sequence_count,
 &sxmw_kly_length,
 &sxmw_kly_volume,
 &sxmw_kly_pan,
 &sxmw_kly_timing,
 &sxmw_kly_flags,
 &sxmw_kly_multiplex,
 &sxmw_kly_pitch,
 &sxmw_kly_fx_count,
 &sxmw_kly_fx,
 &sxmw_kly_spread,
 &sxmw_kly_padding,
 &sxmw_kly_tap_old,
 &sxmw_kly_tap,
 &sxmw_kly_downsample,
 &sxmw_kly_gain,
 &sxmw_kly_legacy_tap,
 &sxmw_kly_instrument,
 &sxmw_kly_program,
 &sxmw_kly_instrument_control,
 &sxmw_kly_finetune,
 &sxmw_kly_filter,
 &sxmw_kly_buzz,
 &sxmw_kly_fx_bus,
 &sxmw_kly_shapes,
 &sxmw_kly_lfsr,
 &sxmw_kly_wave_index,
 &sxmw_kly_fm,
 &sxmw_kly_fm_attack,
 &sxmw_kly_fm_wave,
 &sxmw_kly_sequence,
 &sxmw_kly_sequence_old,
 &sxmw_kly_pattern,
 &sxmw_kly_color,
};
bool sxmw_span(sxmw_view*v,uint64_t at,uint64_t n,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&v->c->size>=0&&end<=(uint64_t)v->c->size&&at<=end&&n<=end-at;}
bool sxmw_read(sxmw_view*v,uint64_t at,void*p,size_t n,uint64_t end)
{return ++v->work<=4000000&&sxmw_span(v,at,n,end)&&sx_read(v->c,(int64_t)at,p,n);}
static bool sxmw_word(sxmw_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!n||n>8||!sxmw_read(v,at,b,n,end))return false;uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[be?n-i-1:i]<<(8*i);*out=x;return true;}
bool sxmw_row(sxmw_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxmw_span(v,at,z,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)z);}
#define MW_ROW(l,at,end) sxmw_row(v,&sxmw_##l,(at),(end))
bool sxmw_table(sxmw_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>4000000||count>UINT64_MAX/z||!sxmw_span(v,at,count*z,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++,at+=z)if(!sxmw_row(v,l,at,end))return false;return true;}
static int sxmw_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxmw_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxmw_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxmw_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
bool sxmw_u(sxmw_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxmw_word(v,p,n,false,x,end);}
bool sxmw_be(sxmw_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxmw_word(v,p,n,true,x,end);}
bool sxmw_eq(sxmw_view*v,uint64_t p,const char*s,size_t n,uint64_t end){uint8_t b[64];return n<=sizeof(b)&&sxmw_read(v,p,b,n,end)&&!xx_rt_memcmp(b,s,n);}
bool sxmw_text_emit(sxmw_view*v,uint64_t p,uint64_t n,uint64_t end){if(!sxmw_span(v,p,n,end))return false;return !n||n>4096||v->c->count>=24000||sx_add(v->c,&sxmw_text,(int64_t)p,(int64_t)n);}
bool sxmw_take(sxmw_view*v,const sx_layout*l,uint64_t*p,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!sxmw_table(v,l,*p,count,end))return false;*p+=count*z;return true;}
bool sxmw_skip(sxmw_view*v,uint64_t*p,uint64_t n,uint64_t end)
{if(!sxmw_span(v,*p,n,end))return false;*p+=n;return true;}
#define MW_TAKE(l,p,n,end) sxmw_take(v,&sxmw_##l,(p),(n),(end))
/* Every emitted span is physical. Decoded tables/PCM and unsupported variants stay raw. */
bool sxmw_cstring(sxmw_view*v,uint64_t*p,uint64_t end,uint64_t cap)
{uint64_t start=*p,x;while(*p<end&&*p-start<cap){if(!sxmw_u(v,*p,1,&x,end))return false;if(!x){if(!sxmw_text_emit(v,start,*p-start,end)||!MW_ROW(nul,*p,end))return false;(*p)++;return true;}(*p)++;}return false;}
/* Bounded physical RLE token walk. Its integer stores bit7=last, not ULEB continuation.
 * It records encoded digits and never maps decoded music fields to source offsets. */
bool sxmw_rle(sxmw_view*v,uint64_t p,uint64_t end)
{uint64_t x,y,n,decoded=0;bool prior=false;while(p<end){if(!sxmw_u(v,p,1,&x,end))return false;if(x!=128){if(!MW_TAKE(rle_literal,&p,1,end))return false;prior=true;decoded++;}
 else{if(!MW_TAKE(rle_marker,&p,1,end))return false;n=0;unsigned shift=0;for(;;){if(!sxmw_u(v,p,1,&y,end)||shift>28||(shift==28&&(y&127)>15)||!MW_TAKE(rle_count_part,&p,1,end))return false;n|=(y&127)<<shift;if(y&128)break;shift+=7;}
  if(n){if(!prior||n<2)return false;decoded+=n-1;}else decoded++;}
 if(decoded>UINT64_C(0x10000000))return false;
 }return true;}
static bool sxmw_kly_name(sxmw_view*v,uint64_t*p,uint64_t end,unsigned ver,unsigned threshold,unsigned fallback,unsigned cap)
{uint64_t n=fallback;if(ver>=threshold){if(!sxmw_u(v,*p,1,&n,end)||!MW_TAKE(pascal_text_length,p,1,end))return false;}if(n>cap)n=cap;if(!sxmw_text_emit(v,*p,n,end))return false;*p+=n;return true;}
static bool sxmw_load_kly_fx(sxmw_view*v,uint64_t*p,uint64_t end,unsigned ver)
{return (ver<22||sxmw_kly_name(v,p,end,ver,22,0,33))&&MW_TAKE(kly_fx,p,1,end)&&(ver>=27||MW_TAKE(kly_spread,p,1,end))&&(ver>=21||MW_TAKE(kly_padding,p,1,end))&&sxmw_take(v,ver>=27?&sxmw_kly_tap:&sxmw_kly_tap_old,p,ver>=27?16:8,end)&&MW_TAKE(kly_downsample,p,1,end)&&(ver<19||MW_TAKE(kly_gain,p,1,end));}
static bool sxmw_kly_inst(sxmw_view*v,uint64_t*p,uint64_t end,unsigned ver)
{uint64_t n;
 return sxmw_u(v,*p+17,1,&n,end)&&MW_TAKE(kly_instrument,p,1,end)&&MW_TAKE(kly_program,p,n,end)&&MW_TAKE(kly_instrument_control,p,1,end)&&(ver<20||MW_TAKE(kly_finetune,p,1,end))&&sxmw_kly_name(v,p,end,ver,11,16,33)&&(ver<1||MW_TAKE(kly_filter,p,1,end))&&(ver<7||MW_TAKE(kly_buzz,p,1,end))&&(ver<10||MW_TAKE(kly_fx_bus,p,1,end))&&(ver<11||MW_TAKE(kly_shapes,p,1,end))&&(ver<18||MW_TAKE(kly_lfsr,p,1,end))&&(ver<12||MW_TAKE(kly_wave_index,p,1,end))&&(ver<23||(MW_TAKE(kly_fm,p,1,end)&&(ver<25||MW_TAKE(kly_fm_attack,p,1,end))&&MW_TAKE(kly_fm_wave,p,1,end)));}
bool sxmw_kly(sxmw_view*v,unsigned kind)
{uint64_t end=v->c->size,p=9,ver,ch,n,ni,np,flags=0,seq[64];const char*magic=kind==0?"cyd!song":kind==1?"cyd!inst":"cyd!efex";
 if(!sxmw_eq(v,0,magic,8,end)||!sxmw_u(v,8,1,&ver,end)||ver>27||!MW_ROW(kly_header,0,end))return false;
 if(kind==1)return sxmw_kly_inst(v,&p,end,(unsigned)ver);if(kind==2)return sxmw_load_kly_fx(v,&p,end,(unsigned)ver);
 ch=ver>3?4:3;if(ver>=6){if(!sxmw_u(v,p,1,&ch,end)||!ch||ch>64||!MW_TAKE(kly_channels,&p,1,end))return false;}
 if(!MW_TAKE(kly_time_signature,&p,1,end)||(ver>=17&&!MW_TAKE(kly_sequence_step,&p,1,end))||!sxmw_u(v,p,1,&ni,end)||!sxmw_u(v,p+1,2,&np,end)||!MW_TAKE(kly_counts,&p,1,end))return false;
 for(uint64_t i=0;i<ch;i++){if(!sxmw_u(v,p,2,&seq[i],end)||!MW_TAKE(kly_sequence_count,&p,1,end))return false;}
 if(!MW_TAKE(kly_length,&p,1,end)||(ver>=12&&!MW_TAKE(kly_volume,&p,1,end))||!MW_TAKE(kly_timing,&p,1,end))return false;
 if(ver>2){if(!sxmw_u(v,p,4,&flags,end)||!MW_TAKE(kly_flags,&p,1,end))return false;}
 if((ver>=9&&!MW_TAKE(kly_multiplex,&p,1,end))||(ver>=16&&!MW_TAKE(kly_pitch,&p,1,end))||(ver>=5&&!sxmw_kly_name(v,&p,end,(unsigned)ver,11,17,65)))return false;
 n=flags&1?1:0;if(ver>=10){if(!sxmw_u(v,p,1,&n,end)||!MW_TAKE(kly_fx_count,&p,1,end))return false;}
 if(ver<10){if(n&&!MW_TAKE(kly_legacy_tap,&p,8,end))return false;}
 else for(uint64_t i=0;i<n;i++)if(!sxmw_load_kly_fx(v,&p,end,(unsigned)ver))return false;
 if(ver>=13&&(!MW_TAKE(kly_volume,&p,ch,end)||!MW_TAKE(kly_pan,&p,ch,end)))return false;
 for(uint64_t i=0;i<ni;i++)if(!sxmw_kly_inst(v,&p,end,(unsigned)ver))return false;
 for(uint64_t i=0;i<ch;i++)if(!sxmw_take(v,ver>=8?&sxmw_kly_sequence:&sxmw_kly_sequence_old,&p,seq[i],end))return false;
 /* Packed event columns need their own grammar; show first real pattern header,
  * preserving the full encoded pattern/wavetable suffix without invented positions. */
 if(np&&(!MW_TAKE(kly_pattern,&p,1,end)||(ver>=24&&!MW_TAKE(kly_color,&p,1,end))))return false;return true;}
static bool sx_musicwire_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_DIE_MUSIC_TAMMELIN_JESKOLABUZZ_BMX:
case XX_FILE_TYPE_DIE_MUSIC_ADLIBVISUALCOMPOSER_STANDARDBNK:
case XX_FILE_TYPE_DIE_MUSIC_DELEK_DEFLEMASK:
case XX_FILE_TYPE_DIE_MUSIC_KOMETBOMB_KLYSTRACK:
case XX_FILE_TYPE_DIE_MUSIC_KOMETBOMB_KLYSTRACK_KI:
case XX_FILE_TYPE_DIE_MUSIC_KOMETBOMB_KLYSTRACK_FX:
case XX_FILE_TYPE_DIE_MUSIC_LUCASARTS_ADLIB:
case XX_FILE_TYPE_DIE_MUSIC_BIRNEY_PLAYERPRO_MAD:
case XX_FILE_TYPE_DIE_MUSIC_BASSMOD_MO3:
case XX_FILE_TYPE_DIE_MUSIC_SUBZER0_MPU401TRAKKER_MTK:
case XX_FILE_TYPE_DIE_MUSIC_HELLSTROM_SBSTUDIO_PAC:
case XX_FILE_TYPE_DIE_MUSIC_BLUEMOON_SOUNDCLUB_SN2:
case XX_FILE_TYPE_DIE_MUSIC_NIGHTRADIO_SUNVOX:
case XX_FILE_TYPE_DIE_MUSIC_SHIRU_TFMD:
case XX_FILE_TYPE_DIE_MUSIC_SHIRU_TFMV2:
case XX_FILE_TYPE_DIE_MUSIC_SHIRU_VGE:
case XX_FILE_TYPE_DIE_MUSIC_WESTWOOD_ADL:
case XX_FILE_TYPE_DIE_MUSIC_SIERRA_SCISOUND:
return true;default:return false;}}
static bool sx_musicwire_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxmw_view view={c,0},*v=&view;bool ok=false;
 switch(c->f->file_type){
case XX_FILE_TYPE_DIE_MUSIC_TAMMELIN_JESKOLABUZZ_BMX:ok=sx_tammelin_jeskolabuzz_bmx_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_ADLIBVISUALCOMPOSER_STANDARDBNK:ok=sx_adlibvisualcomposer_standardbnk_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_DELEK_DEFLEMASK:ok=sx_delek_deflemask_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_KOMETBOMB_KLYSTRACK:ok=sx_kometbomb_klystrack_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_KOMETBOMB_KLYSTRACK_KI:ok=sx_kometbomb_klystrack_ki_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_KOMETBOMB_KLYSTRACK_FX:ok=sx_kometbomb_klystrack_fx_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_LUCASARTS_ADLIB:ok=sx_lucasarts_adlib_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_BIRNEY_PLAYERPRO_MAD:ok=sx_birney_playerpro_mad_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_BASSMOD_MO3:ok=sx_bassmod_mo3_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_SUBZER0_MPU401TRAKKER_MTK:ok=sx_subzer0_mpu401trakker_mtk_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_HELLSTROM_SBSTUDIO_PAC:ok=sx_hellstrom_sbstudio_pac_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_BLUEMOON_SOUNDCLUB_SN2:ok=sx_bluemoon_soundclub_sn2_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_NIGHTRADIO_SUNVOX:ok=sx_nightradio_sunvox_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_SHIRU_TFMD:ok=sx_shiru_tfmd_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_SHIRU_TFMV2:ok=sx_shiru_tfmv2_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_SHIRU_VGE:ok=sx_shiru_vge_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_WESTWOOD_ADL:ok=sx_westwood_adl_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_SIERRA_SCISOUND:ok=sx_sierra_scisound_build(v);break;
default:break;}
 return ok&&sxmw_finish(c);}
#undef MW_ROW
#undef MW_TAKE
static bool sx_musicwire_comment(xx_data_struct_record*r,uint32_t id)
{if(!r||!r->name||id<UINT32_C(0x60870001)||id>=UINT32_C(0x60880000))return true;
 const wchar_t*s=NULL;
 if(id==sxmw_adl_program_offset.id||id==sxmw_adl_instrument_offset.id)s=L"Byte offset relative to the sound-data table base (120, 250 or 500 according to variant); zero/FFFF are absent";
 else if(id==sxmw_sci1_track.id&&!xx_rt_wcscmp(r->name,L"track_offset"))s=L"Stored byte offset; AdPlug track stream starts at this value plus 4 bytes from file start";
 else if(id==sxmw_bmx_connection.id&&!xx_rt_wcscmp(r->name,L"amplitude"))s=L"Fixed-point connection amplitude; 0x4000 is unity";
 else if(id==sxmw_bmx_connection.id&&!xx_rt_wcscmp(r->name,L"pan"))s=L"0x0000 left, 0x4000 center, 0x8000 right";
 else if(id==sxmw_bmx_sequences.id)s=L"Timeline positions in Buzz ticks; these are not wall-clock times";
 else if(id==sxmw_bnk_instrument.id&&!xx_rt_wcscmp(r->name,L"mode"))s=L"0 melodic; 1 percussive";
 else if(id==sxmw_mtk_header.id&&!xx_rt_wcscmp(r->name,L"crc"))s=L"Stored CRC word; the retained AdPlug loader does not verify its algorithm";
 else if(id==sxmw_dmf_timing.id&&!xx_rt_wcscmp(r->name,L"time_base"))s=L"Encoded tick multiplier; effective time base is stored value plus one";
 else if(id==sxmw_dmf_timing.id&&!xx_rt_wcscmp(r->name,L"frames_mode"))s=L"0 PAL 50 Hz; 1 NTSC 60 Hz; custom rate may override";
 else if(id==sxmw_dmf_instrument_mode.id)s=L"0 standard chip-specific macros; 1 FM operator parameters";
 else if(id==sxmw_rle_count_part.id)s=L"Seven count bits; bit 7 marks the last digit. Zero count emits literal 0x80; otherwise append count minus one copies of prior literal";
 else if(id==sxmw_rle_marker.id)s=L"RLE marker 0x80; count digits follow in the physical encoded stream";
 else if(id==sxmw_tfd_command.id||id==sxmw_tfd_skip.id){if(!xx_rt_wcscmp(r->name,L"command")){xx_var_type_t t=xx_var_get_type(&r->value);if(t<XX_VAR_TYPE_INT8||t>XX_VAR_TYPE_UINT64)return true;uint64_t x=xx_var_get_u64(&r->value);switch(x){case 0xff:s=L"END_FRAME";break;case 0xfe:s=L"SKIP_FRAMES";break;case 0xfd:s=L"SELECT_SECOND_CHIP";break;case 0xfc:s=L"SELECT_FIRST_CHIP";break;case 0xfb:s=L"END_MUSIC";break;case 0xfa:s=L"SET_LOOP";break;}}}
 else if(id==sxmw_kly_time_signature.id)s=L"Low byte numerator; high byte denominator";
 else if(id==sxmw_kly_timing.id)s=!xx_rt_wcscmp(r->name,L"tick_rate")?L"Player tick frequency in Hz":L"Ticks per pattern step";
 else if(id==sxmw_kly_tap.id||id==sxmw_kly_tap_old.id){if(!xx_rt_wcscmp(r->name,L"gain"))s=L"Signed logarithmic reverb gain control";else if(!xx_rt_wcscmp(r->name,L"delay"))s=L"Reverb delay in milliseconds";}
 else if(id==sxmw_kly_finetune.id)s=L"Signed fine-pitch adjustment";
 else if(id==sxmw_sv_chunk_capacity.id)s=L"Allocated module-chunk slots; at least one more than the maximum CHNM index";
 else if(id==sxmw_sv_time_grid.id)s=L"Timeline lines per beat";
 else if(id==sxmw_sv_time_grid2.id)s=L"Beats per measure";
 else if(id==sxmw_sv_tempo.id)s=L"Beats per minute";
 else if(id==sxmw_sv_sample_rate.id)s=L"Sample rate in Hz";
 else if(id==sxmw_sv_timeline_position.id||id==sxmw_sv_restart_position.id)s=L"Timeline line position; not a wall-clock timestamp";
 else if(id==sxmw_sv_link_module.id)s=L"Module index; -1 means no linked module";
 else if(id==sxmw_madg_instrument.id){if(!xx_rt_wcscmp(r->name,L"loop_start"))s=L"Byte offset within this instrument's decoded sample data";else if(!xx_rt_wcscmp(r->name,L"base_frequency"))s=L"Raw signed legacy frequency field; original source describes simple/double/quadruple modes and derives playback frequency from finetune instead";}
 else if(id==sxmw_pac_sound.id&&(!xx_rt_wcscmp(r->name,L"loop_start")||!xx_rt_wcscmp(r->name,L"loop_end")))s=L"Byte position within sound sample data";
 else if(id==sxmw_sn2_header.id&&!xx_rt_wcscmp(r->name,L"tempo_control"))s=L"SoundClub tempo control value, not a direct BPM measurement";
 return !s||xx_data_struct_record_set_comment(r,s);}
const sx_family sx_musicwire_family={sx_musicwire_supports,sx_musicwire_build,sx_musicwire_layouts,SX_COUNT(sx_musicwire_layouts),sx_musicwire_comment};
