/* SPDX-License-Identifier: MIT
 * Physical AY/CPC/MSX/Pokey tracker metadata. Encoded event streams and PCM stay raw.
 * See docs/data_struct_chipmusic_scope.txt for format-specific limits. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_chipmusic.h"
static const xx_data_struct_field_desc sxchip_chip_ay_amadeus_header_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("file_version","uint8",8,1,SX_ID),
 SX_FIELD("player_version","uint8",9,1,SX_ID),
 SX_FIELD("special_player_delta","int16",10,2,SX_OFFSET),
 SX_FIELD("author_delta","int16",12,2,SX_OFFSET),
 SX_FIELD("comment_delta","int16",14,2,SX_OFFSET),
 SX_FIELD("last_song_index","uint8",16,1,SX_NONE),
 SX_FIELD("first_song_index","uint8",17,1,SX_NONE),
 SX_FIELD("songs_delta","int16",18,2,SX_OFFSET),
};
const sx_layout sxchip_chip_ay_amadeus_header={UINT32_C(0x608F0004),"chip_ay_amadeus_header",sxchip_chip_ay_amadeus_header_fields,SX_COUNT(sxchip_chip_ay_amadeus_header_fields),SX_BE};
static const xx_data_struct_field_desc sxchip_chip_ay_song_fields[]={
 SX_FIELD("name_delta","int16",0,2,SX_OFFSET),
 SX_FIELD("data_delta","int16",2,2,SX_OFFSET),
};
const sx_layout sxchip_chip_ay_song={UINT32_C(0x608F0005),"chip_ay_song",sxchip_chip_ay_song_fields,SX_COUNT(sxchip_chip_ay_song_fields),SX_BE};
static const xx_data_struct_field_desc sxchip_chip_stf_noise_fields[]={
 SX_FIELD("noise_masks","uint8",0,1,SX_FLAGS),
};
const sx_layout sxchip_chip_stf_noise={UINT32_C(0x608F0008),"chip_stf_noise",sxchip_chip_stf_noise_fields,SX_COUNT(sxchip_chip_stf_noise_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_stf_tone_fields[]={
 SX_FIELD("tone_deviation_bits","uint16",0,2,SX_NONE),
};
const sx_layout sxchip_chip_stf_tone={UINT32_C(0x608F0009),"chip_stf_tone",sxchip_chip_stf_tone_fields,SX_COUNT(sxchip_chip_stf_tone_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_stf_sample_loop_fields[]={
 SX_FIELD("loop_start","uint8",0,1,SX_NONE),
 SX_FIELD("loop_length","uint8",1,1,SX_COUNT_PROP),
};
const sx_layout sxchip_chip_stf_sample_loop={UINT32_C(0x608F000A),"chip_stf_sample_loop",sxchip_chip_stf_sample_loop_fields,SX_COUNT(sxchip_chip_stf_sample_loop_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_stf_positions_end_fields[]={
 SX_FIELD("last_position_index","uint8",0,1,SX_NONE),
};
const sx_layout sxchip_chip_stf_positions_end={UINT32_C(0x608F000C),"chip_stf_positions_end",sxchip_chip_stf_positions_end_fields,SX_COUNT(sxchip_chip_stf_positions_end_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_stf_ornament_fields[]={
 SX_FIELD("loop_index","uint8",0,1,SX_NONE),
 SX_FIELD("last_line_index","uint8",1,1,SX_NONE),
};
const sx_layout sxchip_chip_stf_ornament={UINT32_C(0x608F000D),"chip_stf_ornament",sxchip_chip_stf_ornament_fields,SX_COUNT(sxchip_chip_stf_ornament_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_note_step_fields[]={
 SX_FIELD("note_delta","int8",0,1,SX_NONE),
};
const sx_layout sxchip_chip_note_step={UINT32_C(0x608F000E),"chip_note_step",sxchip_chip_note_step_fields,SX_COUNT(sxchip_chip_note_step_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_stf_event_fields[]={
 SX_FIELD("note","uint8",0,1,SX_NONE),
 SX_FIELD("instrument_command","uint8",1,1,SX_FLAGS),
 SX_FIELD("parameter","uint8",2,1,SX_NONE),
};
const sx_layout sxchip_chip_stf_event={UINT32_C(0x608F0012),"chip_stf_event",sxchip_chip_stf_event_fields,SX_COUNT(sxchip_chip_stf_event_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_sqt_header_fields[]={
 SX_FIELD("declared_size","uint16",0,2,SX_SIZE),
 SX_FIELD("samples_reference","uint16",2,2,SX_ADDRESS),
 SX_FIELD("ornaments_reference","uint16",4,2,SX_ADDRESS),
 SX_FIELD("patterns_reference","uint16",6,2,SX_ADDRESS),
 SX_FIELD("positions_reference","uint16",8,2,SX_ADDRESS),
 SX_FIELD("loop_reference","uint16",10,2,SX_ADDRESS),
};
const sx_layout sxchip_chip_sqt_header={UINT32_C(0x608F0013),"chip_sqt_header",sxchip_chip_sqt_header_fields,SX_COUNT(sxchip_chip_sqt_header_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_sqt_position_fields[]={
 SX_FIELD("channel_c_pattern_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("channel_c_transposition_level","uint8",1,1,SX_FLAGS),
 SX_FIELD("channel_b_pattern_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("channel_b_transposition_level","uint8",3,1,SX_FLAGS),
 SX_FIELD("channel_a_pattern_flags","uint8",4,1,SX_FLAGS),
 SX_FIELD("channel_a_transposition_level","uint8",5,1,SX_FLAGS),
 SX_FIELD("tempo","uint8",6,1,SX_NONE),
};
const sx_layout sxchip_chip_sqt_position={UINT32_C(0x608F0017),"chip_sqt_position",sxchip_chip_sqt_position_fields,SX_COUNT(sxchip_chip_sqt_position_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_sqt_sample_line_fields[]={
 SX_FIELD("volume_noise","uint8",0,1,SX_FLAGS),
 SX_FIELD("noise_masks_delta_high","uint8",1,1,SX_FLAGS),
 SX_FIELD("delta_low","uint8",2,1,SX_NONE),
};
const sx_layout sxchip_chip_sqt_sample_line={UINT32_C(0x608F0019),"chip_sqt_sample_line",sxchip_chip_sqt_sample_line_fields,SX_COUNT(sxchip_chip_sqt_sample_line_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_ned20_dpcm_instrument_fields[]={
 SX_FIELD("register_map","bytes",0,17,SX_NONE),
};
const sx_layout sxchip_chip_ned20_dpcm_instrument={UINT32_C(0x608F0021),"chip_ned20_dpcm_instrument",sxchip_chip_ned20_dpcm_instrument_fields,SX_COUNT(sxchip_chip_ned20_dpcm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_ned20_pattern_fields[]={
 SX_FIELD("pattern_offset_flags","uint16",0,2,SX_FLAGS),
};
const sx_layout sxchip_chip_ned20_pattern={UINT32_C(0x608F0023),"chip_ned20_pattern",sxchip_chip_ned20_pattern_fields,SX_COUNT(sxchip_chip_ned20_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_ned_sample_fields[]={
 SX_FIELD("name","char[12]",0,12,SX_NONE),
 SX_FIELD("sample_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("initial_amplitude","uint8",16,1,SX_NONE),
 SX_FIELD("loop_amplitude","uint8",17,1,SX_NONE),
 SX_FIELD("encoded_length","uint8",18,1,SX_NONE),
 SX_FIELD("encoded_loop_start","uint8",19,1,SX_NONE),
 SX_FIELD("loop_flags","uint8",20,1,SX_FLAGS),
};
const sx_layout sxchip_chip_ned_sample={UINT32_C(0x608F0025),"chip_ned_sample",sxchip_chip_ned_sample_fields,SX_COUNT(sxchip_chip_ned_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_amsdos_header_fields[]={
 SX_FIELD("user_number","uint8",0,1,SX_NONE),
 SX_FIELD("file_name","char[8]",1,8,SX_NONE),
 SX_FIELD("extension","char[3]",9,3,SX_NONE),
 SX_FIELD("zero_bytes","bytes",12,4,SX_RESERVED),
 SX_FIELD("block_number","uint8",16,1,SX_NONE),
 SX_FIELD("last_block_flag","uint8",17,1,SX_FLAGS),
 SX_FIELD("file_type","uint8",18,1,SX_FLAGS),
 SX_FIELD("data_length","uint16",19,2,SX_SIZE),
 SX_FIELD("load_address","uint16",21,2,SX_ADDRESS),
 SX_FIELD("first_block_flag","uint8",23,1,SX_FLAGS),
 SX_FIELD("logical_length","uint16",24,2,SX_SIZE),
 SX_FIELD("entry_address","uint16",26,2,SX_ADDRESS),
 SX_FIELD("unallocated","bytes",28,36,SX_NONE),
 SX_FIELD("real_length","uint24",64,3,SX_SIZE),
 SX_FIELD("checksum","uint16",67,2,SX_CHECKSUM),
 SX_FIELD("undefined","bytes",69,59,SX_NONE),
};
const sx_layout sxchip_chip_amsdos_header={UINT32_C(0x608F0026),"chip_amsdos_header",sxchip_chip_amsdos_header_fields,SX_COUNT(sxchip_chip_amsdos_header_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_bsc128_volume_fields[]={
 SX_FIELD("volume_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxchip_chip_bsc128_volume={UINT32_C(0x608F0027),"chip_bsc128_volume",sxchip_chip_bsc128_volume_fields,SX_COUNT(sxchip_chip_bsc128_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_bsc128_noise_fields[]={
 SX_FIELD("noise_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxchip_chip_bsc128_noise={UINT32_C(0x608F0028),"chip_bsc128_noise",sxchip_chip_bsc128_noise_fields,SX_COUNT(sxchip_chip_bsc128_noise_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_bsc128_tone_fields[]={
 SX_FIELD("tone_deviation","int16",0,2,SX_NONE),
};
const sx_layout sxchip_chip_bsc128_tone={UINT32_C(0x608F0029),"chip_bsc128_tone",sxchip_chip_bsc128_tone_fields,SX_COUNT(sxchip_chip_bsc128_tone_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_bsc128_loop_fields[]={
 SX_FIELD("repeat_position_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("repeat_length_flags","uint8",1,1,SX_FLAGS),
};
const sx_layout sxchip_chip_bsc128_loop={UINT32_C(0x608F002A),"chip_bsc128_loop",sxchip_chip_bsc128_loop_fields,SX_COUNT(sxchip_chip_bsc128_loop_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_bsc128_settings_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("loop_position","uint8",1,1,SX_NONE),
 SX_FIELD("pattern_row_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("song_transposition","int8",3,1,SX_NONE),
 SX_FIELD("position_count","uint8",4,1,SX_COUNT_PROP),
};
const sx_layout sxchip_chip_bsc128_settings={UINT32_C(0x608F002D),"chip_bsc128_settings",sxchip_chip_bsc128_settings_fields,SX_COUNT(sxchip_chip_bsc128_settings_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_bsc128_event_fields[]={
 SX_FIELD("note_octave","uint8",0,1,SX_FLAGS),
 SX_FIELD("instrument_effect","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect_parameter","uint8",2,1,SX_NONE),
};
const sx_layout sxchip_chip_bsc128_event={UINT32_C(0x608F002E),"chip_bsc128_event",sxchip_chip_bsc128_event_fields,SX_COUNT(sxchip_chip_bsc128_event_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_sks_header_fields[]={
 SX_FIELD("signature","char[10]",0,10,SX_SIGNATURE),
 SX_FIELD("author","char[10]",10,10,SX_NONE),
 SX_FIELD("comment","char[32]",20,32,SX_NONE),
 SX_FIELD("sample_channel","uint8",52,1,SX_ID),
 SX_FIELD("loop_last_position","uint8",53,1,SX_NONE),
 SX_FIELD("loop_first_position","uint8",54,1,SX_NONE),
 SX_FIELD("transposition","int8",55,1,SX_NONE),
 SX_FIELD("initial_speed","uint8",56,1,SX_NONE),
 SX_FIELD("replay_frequency_code","uint8",57,1,SX_ID),
 SX_FIELD("last_position_index","uint8",58,1,SX_NONE),
 SX_FIELD("unknown","bytes",59,1,SX_NONE),
};
const sx_layout sxchip_chip_sks_header={UINT32_C(0x608F002F),"chip_sks_header",sxchip_chip_sks_header_fields,SX_COUNT(sxchip_chip_sks_header_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_sks_position_fields[]={
 SX_FIELD("channel_a_track_low","uint8",0,1,SX_NONE),
 SX_FIELD("channel_a_transpose_track_high","uint8",1,1,SX_FLAGS),
 SX_FIELD("channel_b_track_low","uint8",2,1,SX_NONE),
 SX_FIELD("channel_b_transpose_track_high","uint8",3,1,SX_FLAGS),
 SX_FIELD("channel_c_track_low","uint8",4,1,SX_NONE),
 SX_FIELD("channel_c_transpose_track_high","uint8",5,1,SX_FLAGS),
 SX_FIELD("last_row_index","uint8",6,1,SX_NONE),
 SX_FIELD("special_track","uint8",7,1,SX_NONE),
};
const sx_layout sxchip_chip_sks_position={UINT32_C(0x608F0030),"chip_sks_position",sxchip_chip_sks_position_fields,SX_COUNT(sxchip_chip_sks_position_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_sks_instrument_fields[]={
 SX_FIELD("instrument_number","uint16",0,2,SX_NONE),
 SX_FIELD("record_size","uint16",2,2,SX_SIZE),
 SX_FIELD("loop_relative_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("speed_modifier","uint8",6,1,SX_NONE),
 SX_FIELD("retrigger_flag","uint8",7,1,SX_FLAGS),
 SX_FIELD("last_line_index","uint8",8,1,SX_NONE),
 SX_FIELD("loop_line_index","uint8",9,1,SX_NONE),
 SX_FIELD("loop_flag","uint8",10,1,SX_FLAGS),
 SX_FIELD("name","char[8]",11,8,SX_NONE),
};
const sx_layout sxchip_chip_sks_instrument={UINT32_C(0x608F0032),"chip_sks_instrument",sxchip_chip_sks_instrument_fields,SX_COUNT(sxchip_chip_sks_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_sks_special_fields[]={
 SX_FIELD("track_number","uint16",0,2,SX_NONE),
 SX_FIELD("record_size","uint8",2,1,SX_SIZE),
};
const sx_layout sxchip_chip_sks_special={UINT32_C(0x608F0033),"chip_sks_special",sxchip_chip_sks_special_fields,SX_COUNT(sxchip_chip_sks_special_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_sks_track_fields[]={
 SX_FIELD("track_number","uint16",0,2,SX_NONE),
 SX_FIELD("record_size","uint16",2,2,SX_SIZE),
};
const sx_layout sxchip_chip_sks_track={UINT32_C(0x608F0034),"chip_sks_track",sxchip_chip_sks_track_fields,SX_COUNT(sxchip_chip_sks_track_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_starkos_binary_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("load_address","uint16",4,2,SX_ADDRESS),
 SX_FIELD("sample_channel","uint8",6,1,SX_ID),
 SX_FIELD("replay_frequency","uint16",7,2,SX_NONE),
};
const sx_layout sxchip_chip_starkos_binary_header={UINT32_C(0x608F0035),"chip_starkos_binary_header",sxchip_chip_starkos_binary_header_fields,SX_COUNT(sxchip_chip_starkos_binary_header_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_atari_segment_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_ID),
 SX_FIELD("load_address","uint16",2,2,SX_ADDRESS),
 SX_FIELD("inclusive_end_address","uint16",4,2,SX_ADDRESS),
};
static const sx_layout sxchip_chip_atari_segment={UINT32_C(0x608F0036),"chip_atari_segment",sxchip_chip_atari_segment_fields,SX_COUNT(sxchip_chip_atari_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_tmc_header_fields[]={
 SX_FIELD("title","char[30]",0,30,SX_NONE),
 SX_FIELD("tempo_minus_one","uint8",30,1,SX_NONE),
 SX_FIELD("player_calls_per_frame","uint8",31,1,SX_COUNT_PROP),
};
static const sx_layout sxchip_chip_tmc_header={UINT32_C(0x608F0037),"chip_tmc_header",sxchip_chip_tmc_header_fields,SX_COUNT(sxchip_chip_tmc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_tm2_header_fields[]={
 SX_FIELD("identifier","bytes",0,23,SX_SIGNATURE),
 SX_FIELD("memory_data_size","uint16",23,2,SX_SIZE),
 SX_FIELD("output_mode","uint8",25,1,SX_ID),
 SX_FIELD("main_channels_1_4_chip","uint8",26,1,SX_ID),
 SX_FIELD("main_channels_5_8_chip","uint8",27,1,SX_ID),
 SX_FIELD("extra_channels_1_4_chip","uint8",28,1,SX_ID),
 SX_FIELD("extra_channels_5_8_chip","uint8",29,1,SX_ID),
 SX_FIELD("tempo_minus_one","uint8",30,1,SX_NONE),
 SX_FIELD("player_calls_per_frame","uint8",31,1,SX_COUNT_PROP),
};
static const sx_layout sxchip_chip_tm2_header={UINT32_C(0x608F0038),"chip_tm2_header",sxchip_chip_tm2_header_fields,SX_COUNT(sxchip_chip_tm2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_tm2_title_fields[]={
 SX_FIELD("title_row_1","char[32]",0,32,SX_NONE),
 SX_FIELD("title_row_2","char[32]",32,32,SX_NONE),
 SX_FIELD("title_row_3","char[32]",64,32,SX_NONE),
};
static const sx_layout sxchip_chip_tm2_title={UINT32_C(0x608F0039),"chip_tm2_title",sxchip_chip_tm2_title_fields,SX_COUNT(sxchip_chip_tm2_title_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_address_low_fields[]={
 SX_FIELD("address_low","uint8",0,1,SX_NONE),
};
static const sx_layout sxchip_chip_address_low={UINT32_C(0x608F003A),"chip_address_low",sxchip_chip_address_low_fields,SX_COUNT(sxchip_chip_address_low_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_address_high_fields[]={
 SX_FIELD("address_high","uint8",0,1,SX_NONE),
};
static const sx_layout sxchip_chip_address_high={UINT32_C(0x608F003B),"chip_address_high",sxchip_chip_address_high_fields,SX_COUNT(sxchip_chip_address_high_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_tmc_position_fields[]={
 SX_FIELD("channel_8_transposition","uint8",0,1,SX_NONE),
 SX_FIELD("channel_8_pattern","uint8",1,1,SX_NONE),
 SX_FIELD("channel_7_transposition","uint8",2,1,SX_NONE),
 SX_FIELD("channel_7_pattern","uint8",3,1,SX_NONE),
 SX_FIELD("channel_6_transposition","uint8",4,1,SX_NONE),
 SX_FIELD("channel_6_pattern","uint8",5,1,SX_NONE),
 SX_FIELD("channel_5_transposition","uint8",6,1,SX_NONE),
 SX_FIELD("channel_5_pattern","uint8",7,1,SX_NONE),
 SX_FIELD("channel_4_transposition","uint8",8,1,SX_NONE),
 SX_FIELD("channel_4_pattern","uint8",9,1,SX_NONE),
 SX_FIELD("channel_3_transposition","uint8",10,1,SX_NONE),
 SX_FIELD("channel_3_pattern","uint8",11,1,SX_NONE),
 SX_FIELD("channel_2_transposition","uint8",12,1,SX_NONE),
 SX_FIELD("channel_2_pattern","uint8",13,1,SX_NONE),
 SX_FIELD("channel_1_transposition","uint8",14,1,SX_NONE),
 SX_FIELD("channel_1_pattern","uint8",15,1,SX_NONE),
};
static const sx_layout sxchip_chip_tmc_position={UINT32_C(0x608F003C),"chip_tmc_position",sxchip_chip_tmc_position_fields,SX_COUNT(sxchip_chip_tmc_position_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_tm2_position_fields[]={
 SX_FIELD("channel_8_transposition","uint8",0,1,SX_NONE),
 SX_FIELD("channel_8_pattern","uint8",1,1,SX_NONE),
 SX_FIELD("channel_7_transposition","uint8",2,1,SX_NONE),
 SX_FIELD("channel_7_pattern","uint8",3,1,SX_NONE),
 SX_FIELD("channel_6_transposition","uint8",4,1,SX_NONE),
 SX_FIELD("channel_6_pattern","uint8",5,1,SX_NONE),
 SX_FIELD("channel_5_transposition","uint8",6,1,SX_NONE),
 SX_FIELD("channel_5_pattern","uint8",7,1,SX_NONE),
 SX_FIELD("channel_4_transposition","uint8",8,1,SX_NONE),
 SX_FIELD("channel_4_pattern","uint8",9,1,SX_NONE),
 SX_FIELD("channel_3_transposition","uint8",10,1,SX_NONE),
 SX_FIELD("channel_3_pattern","uint8",11,1,SX_NONE),
 SX_FIELD("channel_2_transposition","uint8",12,1,SX_NONE),
 SX_FIELD("channel_2_pattern","uint8",13,1,SX_NONE),
 SX_FIELD("channel_1_transposition","uint8",14,1,SX_NONE),
 SX_FIELD("channel_1_pattern","uint8",15,1,SX_NONE),
 SX_FIELD("row_count_or_control","uint8",16,1,SX_NONE),
};
static const sx_layout sxchip_chip_tm2_position={UINT32_C(0x608F003D),"chip_tm2_position",sxchip_chip_tm2_position_fields,SX_COUNT(sxchip_chip_tm2_position_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_tmc_envelope_fields[]={
 SX_FIELD("distortion_main_volume","uint8",0,1,SX_FLAGS),
 SX_FIELD("accent_extra_volume","uint8",1,1,SX_FLAGS),
 SX_FIELD("accent_parameter","uint8",2,1,SX_NONE),
};
static const sx_layout sxchip_chip_tmc_envelope={UINT32_C(0x608F003E),"chip_tmc_envelope",sxchip_chip_tmc_envelope_fields,SX_COUNT(sxchip_chip_tmc_envelope_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_tmc_arpeggio_fields[]={
 SX_FIELD("encoded_note_transposition","uint8",0,1,SX_NONE),
};
static const sx_layout sxchip_chip_tmc_arpeggio={UINT32_C(0x608F003F),"chip_tmc_arpeggio",sxchip_chip_tmc_arpeggio_fields,SX_COUNT(sxchip_chip_tmc_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_tmc_parameters_fields[]={
 SX_FIELD("filter_tone","uint8",0,1,SX_NONE),
 SX_FIELD("primary_audctl","uint8",1,1,SX_FLAGS),
 SX_FIELD("alternate_audctl","uint8",2,1,SX_FLAGS),
 SX_FIELD("main_decay_ticks","uint8",3,1,SX_NONE),
 SX_FIELD("extra_decay_ticks","uint8",4,1,SX_NONE),
 SX_FIELD("effect_parameter","uint8",5,1,SX_FLAGS),
 SX_FIELD("effect_delay","uint8",6,1,SX_NONE),
 SX_FIELD("frequency_table_rate","uint8",7,1,SX_FLAGS),
 SX_FIELD("arpeggio_flags","uint8",8,1,SX_FLAGS),
};
static const sx_layout sxchip_chip_tmc_parameters={UINT32_C(0x608F0040),"chip_tmc_parameters",sxchip_chip_tmc_parameters_fields,SX_COUNT(sxchip_chip_tmc_parameters_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_tm2_envelope_header_fields[]={
 SX_FIELD("envelope_byte_size","uint8",0,1,SX_SIZE),
 SX_FIELD("loop_byte_offset","uint8",1,1,SX_OFFSET),
};
static const sx_layout sxchip_chip_tm2_envelope_header={UINT32_C(0x608F0041),"chip_tm2_envelope_header",sxchip_chip_tm2_envelope_header_fields,SX_COUNT(sxchip_chip_tm2_envelope_header_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_moon_signature_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("revision","uint8",4,1,SX_NONE),
 SX_FIELD("mode","uint8",5,1,SX_ID),
};
static const sx_layout sxchip_chip_moon_signature={UINT32_C(0x608F0042),"chip_moon_signature",sxchip_chip_moon_signature_fields,SX_COUNT(sxchip_chip_moon_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_mbm_header_fields[]={
 SX_FIELD("song_last_position","uint8",0,1,SX_NONE),
 SX_FIELD("identifier","uint16",1,2,SX_ID),
 SX_FIELD("audio_voice_registers","uint8[144]",3,144,SX_NONE),
 SX_FIELD("audio_instrument_list","uint8[16]",147,16,SX_NONE),
 SX_FIELD("music_instrument_volume_pairs","uint8[32]",163,32,SX_NONE),
 SX_FIELD("channel_chip_set","uint8[10]",195,10,SX_FLAGS),
 SX_FIELD("tempo","uint8",205,1,SX_NONE),
 SX_FIELD("sustain","uint8",206,1,SX_NONE),
 SX_FIELD("track_name","char[41]",207,41,SX_NONE),
 SX_FIELD("start_audio_instruments","uint8[9]",248,9,SX_NONE),
 SX_FIELD("start_music_instruments","uint8[9]",257,9,SX_NONE),
 SX_FIELD("original_instrument_registers","uint8[48]",266,48,SX_NONE),
 SX_FIELD("original_instrument_programs","uint8[6]",314,6,SX_NONE),
 SX_FIELD("sample_kit_name","char[8]",320,8,SX_NONE),
 SX_FIELD("drum_setup_music_psg","uint8[15]",328,15,SX_NONE),
 SX_FIELD("drum_volumes_music","uint8[3]",343,3,SX_NONE),
 SX_FIELD("drum_frequency_words","uint16[9]",346,18,SX_NONE),
 SX_FIELD("unused","bytes",364,2,SX_NONE),
 SX_FIELD("start_reverb","uint8[9]",366,9,SX_NONE),
 SX_FIELD("loop_position","uint8",375,1,SX_NONE),
};
const sx_layout sxchip_chip_mbm_header={UINT32_C(0x608F0044),"chip_mbm_header",sxchip_chip_mbm_header_fields,SX_COUNT(sxchip_chip_mbm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_mfm_header_fields[]={
 SX_FIELD("song_last_position","uint8",0,1,SX_NONE),
 SX_FIELD("loop_position","uint8",1,1,SX_NONE),
 SX_FIELD("fm_2op_voice_registers","uint8[264]",2,264,SX_NONE),
 SX_FIELD("fm_4op_voice_registers","uint8[264]",266,264,SX_NONE),
 SX_FIELD("fm_stereo","uint8[18]",530,18,SX_NONE),
 SX_FIELD("stereo","uint8[6]",548,6,SX_NONE),
 SX_FIELD("tempo","uint8",554,1,SX_NONE),
 SX_FIELD("hz_equalizer","uint8",555,1,SX_NONE),
 SX_FIELD("modulation_depth","uint8",556,1,SX_NONE),
 SX_FIELD("fm_detune","int8[18]",557,18,SX_NONE),
 SX_FIELD("wave_detune","int8[6]",575,6,SX_NONE),
 SX_FIELD("four_operator_channel_count","uint8",581,1,SX_COUNT_PROP),
 SX_FIELD("modulation","int8[48]",582,48,SX_NONE),
 SX_FIELD("fm_start_voices","uint8[18]",630,18,SX_NONE),
 SX_FIELD("start_waves","uint8[6]",648,6,SX_NONE),
 SX_FIELD("wave_numbers","uint8[32]",654,32,SX_NONE),
 SX_FIELD("wave_volumes","uint8[32]",686,32,SX_NONE),
 SX_FIELD("song_name","char[50]",718,50,SX_NONE),
 SX_FIELD("fm_voice_banks","uint8[36]",768,36,SX_NONE),
 SX_FIELD("wave_kit_name","char[8]",804,8,SX_NONE),
};
static const sx_layout sxchip_chip_mfm_header={UINT32_C(0x608F0045),"chip_mfm_header",sxchip_chip_mfm_header_fields,SX_COUNT(sxchip_chip_mfm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_mwm_header_fields[]={
 SX_FIELD("song_last_position","uint8",0,1,SX_NONE),
 SX_FIELD("loop_position","uint8",1,1,SX_NONE),
 SX_FIELD("stereo","uint8[24]",2,24,SX_NONE),
 SX_FIELD("tempo","uint8",26,1,SX_NONE),
 SX_FIELD("base_frequency","uint8",27,1,SX_NONE),
 SX_FIELD("detune","int8[24]",28,24,SX_NONE),
 SX_FIELD("modulation","int8[48]",52,48,SX_NONE),
 SX_FIELD("start_waves","uint8[24]",100,24,SX_NONE),
 SX_FIELD("wave_numbers","uint8[48]",124,48,SX_NONE),
 SX_FIELD("wave_volumes","uint8[48]",172,48,SX_NONE),
 SX_FIELD("song_name","char[50]",220,50,SX_NONE),
 SX_FIELD("wave_kit_name","char[8]",270,8,SX_NONE),
};
static const sx_layout sxchip_chip_mwm_header={UINT32_C(0x608F0046),"chip_mwm_header",sxchip_chip_mwm_header_fields,SX_COUNT(sxchip_chip_mwm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_moon_position_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
};
const sx_layout sxchip_chip_moon_position={UINT32_C(0x608F0047),"chip_moon_position",sxchip_chip_moon_position_fields,SX_COUNT(sxchip_chip_moon_position_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_mbm_pattern_pointer_fields[]={
 SX_FIELD("pattern_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxchip_chip_mbm_pattern_pointer={UINT32_C(0x608F0048),"chip_mbm_pattern_pointer",sxchip_chip_mbm_pattern_pointer_fields,SX_COUNT(sxchip_chip_mbm_pattern_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_moon_segment_pointer_fields[]={
 SX_FIELD("segment_and_offset","uint16",0,2,SX_ID),
};
static const sx_layout sxchip_chip_moon_segment_pointer={UINT32_C(0x608F0049),"chip_moon_segment_pointer",sxchip_chip_moon_segment_pointer_fields,SX_COUNT(sxchip_chip_moon_segment_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_moon_pattern_segment_fields[]={
 SX_FIELD("encoded_size","uint16",0,2,SX_SIZE),
 SX_FIELD("pattern_count","uint8",2,1,SX_COUNT_PROP),
};
static const sx_layout sxchip_chip_moon_pattern_segment={UINT32_C(0x608F004A),"chip_moon_pattern_segment",sxchip_chip_moon_pattern_segment_fields,SX_COUNT(sxchip_chip_moon_pattern_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_mwm_xlfo_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("extra_lfo","uint8[18]",4,18,SX_NONE),
};
static const sx_layout sxchip_chip_mwm_xlfo={UINT32_C(0x608F004B),"chip_mwm_xlfo",sxchip_chip_mwm_xlfo_fields,SX_COUNT(sxchip_chip_mwm_xlfo_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_mwk_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("revision","uint8",4,1,SX_NONE),
 SX_FIELD("mode","uint8",5,1,SX_ID),
 SX_FIELD("total_sample_size","uint24",6,3,SX_SIZE),
 SX_FIELD("wave_count","uint8",9,1,SX_COUNT_PROP),
 SX_FIELD("own_tone_info","uint8[64]",10,64,SX_FLAGS),
};
const sx_layout sxchip_chip_mwk_header={UINT32_C(0x608F004C),"chip_mwk_header",sxchip_chip_mwk_header_fields,SX_COUNT(sxchip_chip_mwk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_mwk_patch_fields[]={
 SX_FIELD("transpose","uint8",0,1,SX_NONE),
 SX_FIELD("part0_next_patch_note","uint8",1,1,SX_NONE),
 SX_FIELD("part0_tone","uint8",2,1,SX_NONE),
 SX_FIELD("part0_tone_note","uint8",3,1,SX_NONE),
 SX_FIELD("part1_next_patch_note","uint8",4,1,SX_NONE),
 SX_FIELD("part1_tone","uint8",5,1,SX_NONE),
 SX_FIELD("part1_tone_note","uint8",6,1,SX_NONE),
 SX_FIELD("part2_next_patch_note","uint8",7,1,SX_NONE),
 SX_FIELD("part2_tone","uint8",8,1,SX_NONE),
 SX_FIELD("part2_tone_note","uint8",9,1,SX_NONE),
 SX_FIELD("part3_next_patch_note","uint8",10,1,SX_NONE),
 SX_FIELD("part3_tone","uint8",11,1,SX_NONE),
 SX_FIELD("part3_tone_note","uint8",12,1,SX_NONE),
 SX_FIELD("part4_next_patch_note","uint8",13,1,SX_NONE),
 SX_FIELD("part4_tone","uint8",14,1,SX_NONE),
 SX_FIELD("part4_tone_note","uint8",15,1,SX_NONE),
 SX_FIELD("part5_next_patch_note","uint8",16,1,SX_NONE),
 SX_FIELD("part5_tone","uint8",17,1,SX_NONE),
 SX_FIELD("part5_tone_note","uint8",18,1,SX_NONE),
 SX_FIELD("part6_next_patch_note","uint8",19,1,SX_NONE),
 SX_FIELD("part6_tone","uint8",20,1,SX_NONE),
 SX_FIELD("part6_tone_note","uint8",21,1,SX_NONE),
 SX_FIELD("part7_next_patch_note","uint8",22,1,SX_NONE),
 SX_FIELD("part7_tone","uint8",23,1,SX_NONE),
 SX_FIELD("part7_tone_note","uint8",24,1,SX_NONE),
};
const sx_layout sxchip_chip_mwk_patch={UINT32_C(0x608F004D),"chip_mwk_patch",sxchip_chip_mwk_patch_fields,SX_COUNT(sxchip_chip_mwk_patch_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_mwk_ram_tone_fields[]={
 SX_FIELD("unused","bytes",0,2,SX_NONE),
 SX_FIELD("loop_address","uint16be",2,2,SX_ADDRESS),
 SX_FIELD("hardware_end","uint16be",4,2,SX_ID),
 SX_FIELD("lfo_vibrato","uint8",6,1,SX_FLAGS),
 SX_FIELD("attack_decay1","uint8",7,1,SX_FLAGS),
 SX_FIELD("decay_level_decay2","uint8",8,1,SX_FLAGS),
 SX_FIELD("rate_correction_release","uint8",9,1,SX_FLAGS),
 SX_FIELD("amplitude_modulation","uint8",10,1,SX_FLAGS),
 SX_FIELD("sample_length","uint16",11,2,SX_SIZE),
};
const sx_layout sxchip_chip_mwk_ram_tone={UINT32_C(0x608F004F),"chip_mwk_ram_tone",sxchip_chip_mwk_ram_tone_fields,SX_COUNT(sxchip_chip_mwk_ram_tone_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_mwk_rom_tone_fields[]={
 SX_FIELD("unused","bytes",0,2,SX_NONE),
 SX_FIELD("loop_address","uint16be",2,2,SX_ADDRESS),
 SX_FIELD("hardware_end","uint16be",4,2,SX_ID),
 SX_FIELD("lfo_vibrato","uint8",6,1,SX_FLAGS),
 SX_FIELD("attack_decay1","uint8",7,1,SX_FLAGS),
 SX_FIELD("decay_level_decay2","uint8",8,1,SX_FLAGS),
 SX_FIELD("rate_correction_release","uint8",9,1,SX_FLAGS),
 SX_FIELD("amplitude_modulation","uint8",10,1,SX_FLAGS),
 SX_FIELD("unused_rom_byte","uint8",11,1,SX_NONE),
 SX_FIELD("rom_address_high","uint8",12,1,SX_ID),
};
const sx_layout sxchip_chip_mwk_rom_tone={UINT32_C(0x608F0050),"chip_mwk_rom_tone",sxchip_chip_mwk_rom_tone_fields,SX_COUNT(sxchip_chip_mwk_rom_tone_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_fac_footer_fields[]={
 SX_FIELD("audio_voice_registers","uint8[99]",0,99,SX_NONE),
 SX_FIELD("audio_instrument_list","uint8[9]",99,9,SX_NONE),
 SX_FIELD("music_original_registers","uint8[8]",108,8,SX_NONE),
 SX_FIELD("music_instrument_volumes","uint8[6]",116,6,SX_NONE),
 SX_FIELD("midi_drum_or_unused","uint8[8]",122,8,SX_NONE),
 SX_FIELD("wait_frames","uint16",130,2,SX_NONE),
 SX_FIELD("sample_kit_name","char[8]",132,8,SX_NONE),
 SX_FIELD("version","uint8",140,1,SX_NONE),
 SX_FIELD("original_voice_number","uint8",141,1,SX_NONE),
 SX_FIELD("user_id","uint8",142,1,SX_NONE),
 SX_FIELD("extension","bytes",143,23,SX_NONE),
 SX_FIELD("title","char[40]",166,40,SX_NONE),
 SX_FIELD("sustain","uint8",206,1,SX_NONE),
 SX_FIELD("composer","char[40]",207,40,SX_NONE),
 SX_FIELD("device","uint8",247,1,SX_ID),
 SX_FIELD("last_track","uint8",248,1,SX_NONE),
 SX_FIELD("extra","bytes",249,7,SX_NONE),
};
const sx_layout sxchip_chip_fac_footer={UINT32_C(0x608F0052),"chip_fac_footer",sxchip_chip_fac_footer_fields,SX_COUNT(sxchip_chip_fac_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_fac_pro_footer_fields[]={
 SX_FIELD("audio_voice_registers","uint8[99]",0,99,SX_NONE),
 SX_FIELD("audio_instrument_list","uint8[9]",99,9,SX_NONE),
 SX_FIELD("music_original_registers","uint8[8]",108,8,SX_NONE),
 SX_FIELD("music_instrument_volumes","uint8[6]",116,6,SX_NONE),
 SX_FIELD("midi_drum_or_unused","uint8[8]",122,8,SX_NONE),
 SX_FIELD("wait_frames","uint16",130,2,SX_NONE),
 SX_FIELD("sample_kit_name","char[8]",132,8,SX_NONE),
 SX_FIELD("version","uint8",140,1,SX_NONE),
 SX_FIELD("original_voice_number","uint8",141,1,SX_NONE),
 SX_FIELD("user_id","uint8",142,1,SX_NONE),
 SX_FIELD("midi_register_numbers","uint8[9]",143,9,SX_NONE),
 SX_FIELD("midi_channel_enable","uint8[9]",152,9,SX_FLAGS),
 SX_FIELD("midi_transpose_packed","uint8[5]",161,5,SX_FLAGS),
 SX_FIELD("title","char[35]",166,35,SX_NONE),
 SX_FIELD("midi_velocity_first","uint8[5]",201,5,SX_NONE),
 SX_FIELD("sustain","uint8",206,1,SX_NONE),
 SX_FIELD("composer","char[35]",207,35,SX_NONE),
 SX_FIELD("midi_velocity_last","uint8[5]",242,5,SX_NONE),
 SX_FIELD("device","uint8",247,1,SX_ID),
 SX_FIELD("last_track","uint8",248,1,SX_NONE),
 SX_FIELD("midi_drum_ids","uint8[7]",249,7,SX_NONE),
};
const sx_layout sxchip_chip_fac_pro_footer={UINT32_C(0x608F0053),"chip_fac_pro_footer",sxchip_chip_fac_pro_footer_fields,SX_COUNT(sxchip_chip_fac_pro_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_fac_row_fields[]={
 SX_FIELD("fm_channel_1","uint8",0,1,SX_ID),
 SX_FIELD("fm_channel_2","uint8",1,1,SX_ID),
 SX_FIELD("fm_channel_3","uint8",2,1,SX_ID),
 SX_FIELD("fm_channel_4","uint8",3,1,SX_ID),
 SX_FIELD("fm_channel_5","uint8",4,1,SX_ID),
 SX_FIELD("fm_channel_6","uint8",5,1,SX_ID),
 SX_FIELD("fm_channel_7","uint8",6,1,SX_ID),
 SX_FIELD("fm_channel_8","uint8",7,1,SX_ID),
 SX_FIELD("fm_channel_9","uint8",8,1,SX_ID),
 SX_FIELD("drum_frequency","uint8",9,1,SX_NONE),
 SX_FIELD("drum_volume","uint8",10,1,SX_NONE),
 SX_FIELD("drums_packed","uint8",11,1,SX_FLAGS),
};
const sx_layout sxchip_chip_fac_row={UINT32_C(0x608F0054),"chip_fac_row",sxchip_chip_fac_row_fields,SX_COUNT(sxchip_chip_fac_row_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_1tracker_speed_fields[]={
 SX_FIELD("speed","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxchip_chip_1tracker_speed={UINT32_C(0x608F005A),"chip_1tracker_speed",sxchip_chip_1tracker_speed_fields,SX_COUNT(sxchip_chip_1tracker_speed_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_1tracker_loop_start_fields[]={
 SX_FIELD("loop_start","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxchip_chip_1tracker_loop_start={UINT32_C(0x608F005B),"chip_1tracker_loop_start",sxchip_chip_1tracker_loop_start_fields,SX_COUNT(sxchip_chip_1tracker_loop_start_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_1tracker_loop_end_fields[]={
 SX_FIELD("loop_end","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxchip_chip_1tracker_loop_end={UINT32_C(0x608F005C),"chip_1tracker_loop_end",sxchip_chip_1tracker_loop_end_fields,SX_COUNT(sxchip_chip_1tracker_loop_end_fields),SX_LE};
static const xx_data_struct_field_desc sxchip_chip_1tracker_pattern_format_fields[]={
 SX_FIELD("pattern_format","char",0,0,SX_NONE),
};
const sx_layout sxchip_chip_1tracker_pattern_format={UINT32_C(0x608F005E),"chip_1tracker_pattern_format",sxchip_chip_1tracker_pattern_format_fields,SX_COUNT(sxchip_chip_1tracker_pattern_format_fields),SX_LE};
static const sx_layout *const sx_chipmusic_layouts[]={
 &sxchip_chip_text,
 &sxchip_chip_fxm_header,
 &sxchip_chip_fxm_channels,
 &sxchip_chip_ay_amadeus_header,
 &sxchip_chip_ay_song,
 &sxchip_chip_ay_amadeus_address,
 &sxchip_chip_stf_volume,
 &sxchip_chip_stf_noise,
 &sxchip_chip_stf_tone,
 &sxchip_chip_stf_sample_loop,
 &sxchip_chip_stf_position,
 &sxchip_chip_stf_positions_end,
 &sxchip_chip_stf_ornament,
 &sxchip_chip_note_step,
 &sxchip_chip_stf_settings,
 &sxchip_chip_stf_pattern_length,
 &sxchip_chip_stf_song,
 &sxchip_chip_stf_event,
 &sxchip_chip_sqt_header,
 &sxchip_chip_sqt_sample_reference,
 &sxchip_chip_sqt_ornament_reference,
 &sxchip_chip_sqt_pattern_reference,
 &sxchip_chip_sqt_position,
 &sxchip_chip_sqt_loop,
 &sxchip_chip_sqt_sample_line,
 &sxchip_chip_ned10_header,
 &sxchip_chip_ned10_instrument,
 &sxchip_chip_ned_order,
 &sxchip_chip_ned10_pattern,
 &sxchip_chip_ned20_header,
 &sxchip_chip_ned20_data,
 &sxchip_chip_ned20_instrument,
 &sxchip_chip_ned20_dpcm_instrument,
 &sxchip_chip_ned20_order,
 &sxchip_chip_ned20_pattern,
 &sxchip_chip_ned_sample_instrument,
 &sxchip_chip_ned_sample,
 &sxchip_chip_amsdos_header,
 &sxchip_chip_bsc128_volume,
 &sxchip_chip_bsc128_noise,
 &sxchip_chip_bsc128_tone,
 &sxchip_chip_bsc128_loop,
 &sxchip_chip_bsc128_position,
 &sxchip_chip_bsc128_name,
 &sxchip_chip_bsc128_settings,
 &sxchip_chip_bsc128_event,
 &sxchip_chip_sks_header,
 &sxchip_chip_sks_position,
 &sxchip_chip_sks_end,
 &sxchip_chip_sks_instrument,
 &sxchip_chip_sks_special,
 &sxchip_chip_sks_track,
 &sxchip_chip_starkos_binary_header,
 &sxchip_chip_atari_segment,
 &sxchip_chip_tmc_header,
 &sxchip_chip_tm2_header,
 &sxchip_chip_tm2_title,
 &sxchip_chip_address_low,
 &sxchip_chip_address_high,
 &sxchip_chip_tmc_position,
 &sxchip_chip_tm2_position,
 &sxchip_chip_tmc_envelope,
 &sxchip_chip_tmc_arpeggio,
 &sxchip_chip_tmc_parameters,
 &sxchip_chip_tm2_envelope_header,
 &sxchip_chip_moon_signature,
 &sxchip_chip_mbm_edit_marker,
 &sxchip_chip_mbm_header,
 &sxchip_chip_mfm_header,
 &sxchip_chip_mwm_header,
 &sxchip_chip_moon_position,
 &sxchip_chip_mbm_pattern_pointer,
 &sxchip_chip_moon_segment_pointer,
 &sxchip_chip_moon_pattern_segment,
 &sxchip_chip_mwm_xlfo,
 &sxchip_chip_mwk_header,
 &sxchip_chip_mwk_patch,
 &sxchip_chip_mwk_name,
 &sxchip_chip_mwk_ram_tone,
 &sxchip_chip_mwk_rom_tone,
 &sxchip_chip_msx_bload,
 &sxchip_chip_fac_footer,
 &sxchip_chip_fac_pro_footer,
 &sxchip_chip_fac_row,
 &sxchip_chip_1tracker_section,
 &sxchip_chip_1tracker_key,
 &sxchip_chip_1tracker_engine,
 &sxchip_chip_1tracker_title,
 &sxchip_chip_1tracker_author,
 &sxchip_chip_1tracker_speed,
 &sxchip_chip_1tracker_loop_start,
 &sxchip_chip_1tracker_loop_end,
 &sxchip_chip_1tracker_measure,
 &sxchip_chip_1tracker_pattern_format,
};
#define SXCHIP_LIMIT 24000U
bool sxchip_span(sx_context*c,uint64_t p,uint64_t n){return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
bool sxchip_read(sx_context*c,uint64_t p,void*b,size_t n){return sxchip_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint16_t sxchip16(const uint8_t*b){return (uint16_t)b[0]|(uint16_t)((uint16_t)b[1]<<8);}
bool sxchip_u16(sx_context*c,uint64_t p,uint16_t*v){uint8_t b[2];if(!sxchip_read(c,p,b,2))return false;*v=sxchip16(b);return true;}
bool sxchip_u8(sx_context*c,uint64_t p,uint8_t*v){return sxchip_read(c,p,v,1);}
bool sxchip_eq(sx_context*c,uint64_t p,const char*s,size_t n){uint8_t b[64];return n<=sizeof(b)&&sxchip_read(c,p,b,n)&&!xx_rt_memcmp(b,s,n);}
static uint64_t sxchip_width(const sx_layout*l){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;return (uint64_t)f->rel_offset+(uint64_t)f->size;}
/* Insert only disjoint physical records. Shared pointers are decoded once;
 * conflicting interpretations remain covered by the first authenticated row.
 * Display-budget exhaustion retains earlier metadata and raw remainder. */
bool sxchip_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){
 uint64_t z=sxchip_width(l);if(!count)return true;if(!z||count>UINT64_MAX/z||!sxchip_span(c,p,count*z))return false;
 if(c->count>=SXCHIP_LIMIT)return true;
 uint64_t end=p+count*z;
 for(size_t i=0;i<c->count;i++){int64_t rel=c->items[i].offset-c->f->base_address;uint64_t n=(uint64_t)c->items[i].total_size;
  if(rel>=0&&p<(uint64_t)rel+n&&(uint64_t)rel<end)return true;}
 return count==1?sx_add(c,l,(int64_t)p,(int64_t)z):sx_table(c,l,(int64_t)p,(int64_t)z,(int64_t)count);
}
#define SXCHIP_ADD(c,n,p) sxchip_put(c,&sxchip_##n,p,1)
bool sxchip_opt(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){uint64_t z=sxchip_width(l);return !count||!z||count>UINT64_MAX/z||!sxchip_span(c,p,count*z)?true:sxchip_put(c,l,p,count);}
static int sxchip_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset;}
static bool sxchip_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxchip_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end||z<=0||p>c->size||z>c->size-p)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxchip_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxchip_lines(sx_context*c,const sx_layout*l,uint64_t p,unsigned count){return sxchip_opt(c,l,p,count);}
bool sxchip_tmc(sx_context*c,bool v2){
 uint8_t x[6];if(!sxchip_read(c,0,x,6)||sxchip16(x)!=65535)return false;
 uint16_t load=sxchip16(x+2),end=sxchip16(x+4);if(end<load)return false;
 uint64_t limit=(uint64_t)end-load+7;if(limit>(uint64_t)c->size)limit=(uint64_t)c->size;
 unsigned ins=v2?128:64,pat=v2?256:128;uint64_t song=v2?902:422;
 if(limit<song)return false;
 if(!SXCHIP_ADD(c,chip_atari_segment,0)||!sxchip_put(c,v2?&sxchip_chip_tm2_header:&sxchip_chip_tmc_header,6,1))return false;
 if(v2&&!SXCHIP_ADD(c,chip_tm2_title,38))return false;
 uint64_t il=v2?134:38,ih=v2?774:102,pl=v2?262:166,ph=v2?518:294;
 if(!sxchip_put(c,&sxchip_chip_address_low,il,ins)||!sxchip_put(c,&sxchip_chip_address_high,ih,ins)||!sxchip_put(c,&sxchip_chip_address_low,pl,pat)||!sxchip_put(c,&sxchip_chip_address_high,ph,pat))return false;
 uint64_t boundary=limit;uint16_t addresses[128];
 for(unsigned i=0;i<ins;i++){uint8_t lo,hi;if(!sxchip_u8(c,il+i,&lo)||!sxchip_u8(c,ih+i,&hi))return false;addresses[i]=(uint16_t)lo|((uint16_t)hi<<8);
  if(addresses[i]>=load){uint64_t p=(uint64_t)addresses[i]-load+6;if(p>=song&&p<boundary)boundary=p;}}
 for(unsigned i=0;i<pat;i++){uint8_t lo,hi;if(!sxchip_u8(c,pl+i,&lo)||!sxchip_u8(c,ph+i,&hi))return false;uint16_t a=(uint16_t)lo|((uint16_t)hi<<8);
  if(a>=load){uint64_t p=(uint64_t)a-load+6;if(p>=song&&p<boundary)boundary=p;}}
 unsigned stride=v2?17:16;uint64_t n=(boundary-song)/stride;if(n>4096)n=4096;
 if(!sxchip_put(c,v2?&sxchip_chip_tm2_position:&sxchip_chip_tmc_position,song,n))return false;
 for(unsigned i=0;i<ins;i++){uint16_t a=addresses[i];if(!a||a<load)continue;uint64_t p=(uint64_t)a-load+6;
  if(p<song||p>=limit)continue;
  if(v2){uint8_t size;if(limit-p<19||!sxchip_u8(c,p+8,&size)||size>limit-p-19)continue;
   if(!sxchip_put(c,&sxchip_chip_tmc_arpeggio,p,8)||!SXCHIP_ADD(c,chip_tm2_envelope_header,p+8)||!SXCHIP_ADD(c,chip_tmc_parameters,p+10)||!sxchip_put(c,&sxchip_chip_tmc_envelope,p+19,size/3))return false;
  }else{if(limit-p<80)continue;
   if(!sxchip_put(c,&sxchip_chip_tmc_envelope,p,21)||!sxchip_put(c,&sxchip_chip_tmc_arpeggio,p+63,8)||!SXCHIP_ADD(c,chip_tmc_parameters,p+71))return false;
  }
 }
 return true;
}
bool sxchip_moon(sx_context*c,bool wave){
 uint8_t sig[6],h[812],orders[220];if(!sxchip_read(c,0,sig,6)||xx_rt_memcmp(sig,"MBMS\x10",5))return true;
 bool edit=wave?sig[5]==7:sig[5]==0,raw=!wave&&sig[5]==2;
 if(!(edit||raw||(wave?sig[5]==8:sig[5]==1)))return true;
 if(!SXCHIP_ADD(c,chip_moon_signature,0))return false;
 uint64_t hp=6+(edit||raw?220:0),hs=wave?278:812;
 if(!sxchip_read(c,hp,h,(size_t)hs))return true;
 if(!sxchip_put(c,wave?&sxchip_chip_mwm_header:&sxchip_chip_mfm_header,hp,1))return false;
 unsigned active=(unsigned)h[0]+1U,count=edit||raw?220:active;
 uint64_t op=edit||raw?6:hp+hs,p=hp+hs+(edit||raw?0:count);
 if(count>220||active>count||!sxchip_read(c,op,orders,count))return true;
 if(!sxchip_put(c,&sxchip_chip_moon_position,op,count))return false;
 if(raw)return true; /* two 16KiB raw pattern blocks have no physical segment headers */
 unsigned high=0;for(unsigned i=0;i<active;i++)if(orders[i]>high)high=orders[i];
 unsigned pointers=!wave&&edit?80:high+1;
 if(pointers>80||!sxchip_span(c,p,(uint64_t)pointers*2))return true;
 if(!sxchip_put(c,&sxchip_chip_moon_segment_pointer,p,pointers))return false;p+=(uint64_t)pointers*2;
 /* The loader reads the next header after each of up to three segments. */
 for(unsigned seg=0;seg<=3;seg++){
  uint8_t b[3];if(!sxchip_read(c,p,b,3))return true;
  if(!SXCHIP_ADD(c,chip_moon_pattern_segment,p))return false;p+=3;
  if(!b[2]||seg==3)break;
  uint16_t z=sxchip16(b);if(!sxchip_span(c,p,z))return true;p+=z;
 }
 if(wave&&sxchip_eq(c,p,"XLFO",4))return sxchip_opt(c,&sxchip_chip_mwm_xlfo,p,1);
 return true;
}
static bool sx_chipmusic_supports(xx_file_type_t type){switch(type){
 case XX_FILE_TYPE_DIE_MUSIC_SHIRU_1TRACKER:
 case XX_FILE_TYPE_DIE_MUSIC_FUXOFT_AYLANGUAGE_FXM:
 case XX_FILE_TYPE_DIE_MUSIC_MOONBLASTER_FM:
 case XX_FILE_TYPE_DIE_MUSIC_MOONBLASTER_WAVE:
 case XX_FILE_TYPE_DIE_MUSIC_MOONBLASTER_WAVE_MWK:
 case XX_FILE_TYPE_DIE_MUSIC_MSX_FACSOUNDTRACKER_MUS:
 case XX_FILE_TYPE_DIE_MUSIC_BSC_AMSTRADCPC_SOUNDTRAKKER128K:
 case XX_FILE_TYPE_DIE_MUSIC_TARGHAN_STARKOS_SKS:
 case XX_FILE_TYPE_DIE_MUSIC_TARGHAN_STARKOS_BIN:
 case XX_FILE_TYPE_DIE_MUSIC_JASKIER_THETAMUSICCOMPOSER_TM2:
 case XX_FILE_TYPE_DIE_MUSIC_FUXOFT_AYAMADEUS:
 case XX_FILE_TYPE_DIE_MUSIC_SCHRIJVERS_MOONBLASTER_MBM:
 case XX_FILE_TYPE_DIE_MUSIC_KSA_SOUNDTRACKERPRO_STF_PROJECT_CO:
 case XX_FILE_TYPE_DIE_MUSIC_KOUDELKA_SCALEXQJETATRACKER:
 case XX_FILE_TYPE_DIE_MUSIC_JASKIER_THETAMUSICCOMPOSER_TMC:
 case XX_FILE_TYPE_DIE_MUSIC_NERDSRUS_NERDTRACKER2_NED:
 return true;default:return false;}}
static bool sx_chipmusic_build(sx_context*c){
 if(!c||!c->f||!sx_chipmusic_supports(c->f->file_type)||!xx_format_handle_base_info(c->f,c->pd)||!c->f->is_valid)return false;
 bool ok=false;switch(c->f->file_type){
 case XX_FILE_TYPE_DIE_MUSIC_SHIRU_1TRACKER:ok=sx_shiru_1tracker_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_FUXOFT_AYLANGUAGE_FXM:ok=sx_fuxoft_aylanguage_fxm_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_MOONBLASTER_FM:ok=sx_moonblaster_fm_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_MOONBLASTER_WAVE:ok=sx_moonblaster_wave_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_MOONBLASTER_WAVE_MWK:ok=sx_moonblaster_wave_mwk_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_MSX_FACSOUNDTRACKER_MUS:ok=sx_msx_facsoundtracker_mus_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_BSC_AMSTRADCPC_SOUNDTRAKKER128K:ok=sx_bsc_amstradcpc_soundtrakker128k_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_TARGHAN_STARKOS_SKS:ok=sx_targhan_starkos_sks_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_TARGHAN_STARKOS_BIN:ok=sx_targhan_starkos_bin_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_JASKIER_THETAMUSICCOMPOSER_TM2:ok=sx_jaskier_thetamusiccomposer_tm2_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_FUXOFT_AYAMADEUS:ok=sx_fuxoft_ayamadeus_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_SCHRIJVERS_MOONBLASTER_MBM:ok=sx_schrijvers_moonblaster_mbm_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_KSA_SOUNDTRACKERPRO_STF_PROJECT_CO:ok=sx_ksa_soundtrackerpro_stf_project_co_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_KOUDELKA_SCALEXQJETATRACKER:ok=sx_koudelka_scalexqjetatracker_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_JASKIER_THETAMUSICCOMPOSER_TMC:ok=sx_jaskier_thetamusiccomposer_tmc_build(c);break;
 case XX_FILE_TYPE_DIE_MUSIC_NERDSRUS_NERDTRACKER2_NED:ok=sx_nerdsrus_nerdtracker2_ned_build(c);break;
 default:break;}return ok&&c->count>0&&sxchip_finish(c);
}
static bool sx_chipmusic_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x608f0000U||id>=0x60900000U)return true;
 if(id==sxchip_chip_ay_amadeus_header.id&&!xx_rt_wcscmp(r->name,L"special_player_delta"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this field; zero can denote an absent optional reference.");
 if(id==sxchip_chip_ay_amadeus_header.id&&!xx_rt_wcscmp(r->name,L"author_delta"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this field; zero can denote an absent optional reference.");
 if(id==sxchip_chip_ay_amadeus_header.id&&!xx_rt_wcscmp(r->name,L"comment_delta"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this field; zero can denote an absent optional reference.");
 if(id==sxchip_chip_ay_amadeus_header.id&&!xx_rt_wcscmp(r->name,L"songs_delta"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this field; zero can denote an absent optional reference.");
 if(id==sxchip_chip_ay_song.id&&!xx_rt_wcscmp(r->name,L"name_delta"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this field.");
 if(id==sxchip_chip_ay_song.id&&!xx_rt_wcscmp(r->name,L"data_delta"))return xx_data_struct_record_set_comment(r,L"Signed byte displacement from the beginning of this field.");
 if(id==sxchip_chip_ay_amadeus_header.id&&!xx_rt_wcscmp(r->name,L"last_song_index"))return xx_data_struct_record_set_comment(r,L"Song table count minus one.");
 if(id==sxchip_chip_stf_noise.id&&!xx_rt_wcscmp(r->name,L"noise_masks"))return xx_data_struct_record_set_comment(r,L"Low5 bits are noise period; bits7/6 disable noise/tone; stored bit5 is retained.");
 if(id==sxchip_chip_stf_tone.id&&!xx_rt_wcscmp(r->name,L"tone_deviation_bits"))return xx_data_struct_record_set_comment(r,L"Low12 bits are magnitude; bit12 encodes the sign. This is not two-complement signed16.");
 if(id==sxchip_chip_stf_sample_loop.id&&!xx_rt_wcscmp(r->name,L"loop_start"))return xx_data_struct_record_set_comment(r,L"One-based sample-loop start; zero disables the loop.");
 if(id==sxchip_chip_stf_positions_end.id&&!xx_rt_wcscmp(r->name,L"last_position_index"))return xx_data_struct_record_set_comment(r,L"Number of active entries minus one within the fixed256-entry position table.");
 if(id==sxchip_chip_stf_ornament.id&&!xx_rt_wcscmp(r->name,L"last_line_index"))return xx_data_struct_record_set_comment(r,L"Inclusive last active line within the30-byte signed-step plane.");
 if(id==sxchip_chip_stf_event.id&&!xx_rt_wcscmp(r->name,L"instrument_command"))return xx_data_struct_record_set_comment(r,L"High nibble selects the instrument; low nibble holds the effect command. Stored values are not converted.");
 if(id==sxchip_chip_sqt_header.id&&!xx_rt_wcscmp(r->name,L"samples_reference"))return xx_data_struct_record_set_comment(r,L"Stored target-memory reference. File offset is reference-(samples_reference-10); pointer tables are one-based.");
 if(id==sxchip_chip_sqt_header.id&&!xx_rt_wcscmp(r->name,L"ornaments_reference"))return xx_data_struct_record_set_comment(r,L"Stored target-memory reference. File offset is reference-(samples_reference-10); pointer tables are one-based.");
 if(id==sxchip_chip_sqt_header.id&&!xx_rt_wcscmp(r->name,L"patterns_reference"))return xx_data_struct_record_set_comment(r,L"Stored target-memory reference. File offset is reference-(samples_reference-10); pointer tables are one-based.");
 if(id==sxchip_chip_sqt_header.id&&!xx_rt_wcscmp(r->name,L"positions_reference"))return xx_data_struct_record_set_comment(r,L"Stored target-memory reference. File offset is reference-(samples_reference-10); pointer tables are one-based.");
 if(id==sxchip_chip_sqt_header.id&&!xx_rt_wcscmp(r->name,L"loop_reference"))return xx_data_struct_record_set_comment(r,L"Stored target-memory reference. File offset is reference-(samples_reference-10); pointer tables are one-based.");
 if(id==sxchip_chip_sqt_position.id&&!xx_rt_wcscmp(r->name,L"channel_a_pattern_flags"))return xx_data_struct_record_set_comment(r,L"Low7 bits are a one-based pattern index; bit7 enables effects; zero pattern ends the position list.");
 if(id==sxchip_chip_sqt_position.id&&!xx_rt_wcscmp(r->name,L"channel_a_transposition_level"))return xx_data_struct_record_set_comment(r,L"Low nibble is attenuation; high nibble encodes signed transposition (0..8, then -1..-7).");
 if(id==sxchip_chip_sqt_position.id&&!xx_rt_wcscmp(r->name,L"channel_b_pattern_flags"))return xx_data_struct_record_set_comment(r,L"Low7 bits are a one-based pattern index; bit7 enables effects; zero pattern ends the position list.");
 if(id==sxchip_chip_sqt_position.id&&!xx_rt_wcscmp(r->name,L"channel_b_transposition_level"))return xx_data_struct_record_set_comment(r,L"Low nibble is attenuation; high nibble encodes signed transposition (0..8, then -1..-7).");
 if(id==sxchip_chip_sqt_position.id&&!xx_rt_wcscmp(r->name,L"channel_c_pattern_flags"))return xx_data_struct_record_set_comment(r,L"Low7 bits are a one-based pattern index; bit7 enables effects; zero pattern ends the position list.");
 if(id==sxchip_chip_sqt_position.id&&!xx_rt_wcscmp(r->name,L"channel_c_transposition_level"))return xx_data_struct_record_set_comment(r,L"Low nibble is attenuation; high nibble encodes signed transposition (0..8, then -1..-7).");
 if(id==sxchip_chip_sqt_sample_line.id&&!xx_rt_wcscmp(r->name,L"noise_masks_delta_high"))return xx_data_struct_record_set_comment(r,L"Bit7 is noise bit0; bits6/5 enable tone/noise; bit4 selects positive deviation; low4 bits are deviation magnitude bits8..11.");
 if(id==sxchip_chip_ned20_dpcm_instrument.id&&!xx_rt_wcscmp(r->name,L"register_map"))return xx_data_struct_record_set_comment(r,L"Stored17-byte packed DPCM register/note mapping; not PCM data.");
 if(id==sxchip_chip_ned20_pattern.id&&!xx_rt_wcscmp(r->name,L"pattern_offset_flags"))return xx_data_struct_record_set_comment(r,L"Low15 bits are a byte offset: version0x20 uses InfoHeader.header_size as origin; version0x21 uses the sequence-data header after the NTSC sample chunk. Bit15 is masked by the retained loader; zero denotes an absent pattern.");
 if(id==sxchip_chip_ned_sample.id&&!xx_rt_wcscmp(r->name,L"sample_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset in the following NTSC sample-data block;0xFFFFFFFF denotes no sample.");
 if(id==sxchip_chip_ned_sample.id&&!xx_rt_wcscmp(r->name,L"encoded_length"))return xx_data_struct_record_set_comment(r,L"NES DPCM length-register encoding; decoded byte length is16*value+1.");
 if(id==sxchip_chip_ned_sample.id&&!xx_rt_wcscmp(r->name,L"encoded_loop_start"))return xx_data_struct_record_set_comment(r,L"Stored loop-start unit consumed by the DPCM player; retained without an unsupported byte-coordinate conversion.");
 if(id==sxchip_chip_amsdos_header.id&&!xx_rt_wcscmp(r->name,L"checksum"))return xx_data_struct_record_set_comment(r,L"16-bit unsigned sum of physical bytes0..66. Native music recognition may retain files with a bad checksum.");
 if(id==sxchip_chip_amsdos_header.id&&!xx_rt_wcscmp(r->name,L"file_type"))return xx_data_struct_record_set_comment(r,L"Bit0 protection; bits1..3 contents (0 BASIC,1 binary,2 screen,3 ASCII); high nibble version.");
 if(id==sxchip_chip_bsc128_volume.id&&!xx_rt_wcscmp(r->name,L"volume_flags"))return xx_data_struct_record_set_comment(r,L"Bit7 marks an inactive volume step; low4 bits are volume.");
 if(id==sxchip_chip_bsc128_noise.id&&!xx_rt_wcscmp(r->name,L"noise_flags"))return xx_data_struct_record_set_comment(r,L"Bit7 marks an inactive step; low5 bits are noise period.");
 if(id==sxchip_chip_bsc128_tone.id&&!xx_rt_wcscmp(r->name,L"tone_deviation"))return xx_data_struct_record_set_comment(r,L"Signed AY tone-period deviation; no frequency-Hz conversion.");
 if(id==sxchip_chip_bsc128_loop.id&&!xx_rt_wcscmp(r->name,L"repeat_position_flags"))return xx_data_struct_record_set_comment(r,L"Low5 bits select repeat position; bits7/6 are stored volume/frequency mode flags.");
 if(id==sxchip_chip_bsc128_loop.id&&!xx_rt_wcscmp(r->name,L"repeat_length_flags"))return xx_data_struct_record_set_comment(r,L"Low5 bits hold repeat length; other stored bits are retained.");
 if(id==sxchip_chip_bsc128_settings.id&&!xx_rt_wcscmp(r->name,L"tempo"))return xx_data_struct_record_set_comment(r,L"50Hz player ticks per pattern row.");
 if(id==sxchip_chip_bsc128_event.id&&!xx_rt_wcscmp(r->name,L"note_octave"))return xx_data_struct_record_set_comment(r,L"High nibble is note code; low nibble is octave+1;0xD0 resets the channel.");
 if(id==sxchip_chip_bsc128_event.id&&!xx_rt_wcscmp(r->name,L"instrument_effect"))return xx_data_struct_record_set_comment(r,L"High nibble selects instrument; low nibble is an effect opcode.");
 if(id==sxchip_chip_sks_header.id&&!xx_rt_wcscmp(r->name,L"last_position_index"))return xx_data_struct_record_set_comment(r,L"Number of eight-byte position entries minus one. The following byte is unspecified by the retained reversing notes; nonzero variants are left raw after the header.");
 if(id==sxchip_chip_sks_header.id&&!xx_rt_wcscmp(r->name,L"replay_frequency_code"))return xx_data_struct_record_set_comment(r,L"0=13Hz,1=25Hz,2=50Hz,3=100Hz,4=150Hz,5=300Hz.");
 if(id==sxchip_chip_sks_position.id&&!xx_rt_wcscmp(r->name,L"channel_a_transpose_track_high"))return xx_data_struct_record_set_comment(r,L"Bit0 is pattern-number bit8; upper7 bits encode signed transposition.");
 if(id==sxchip_chip_sks_position.id&&!xx_rt_wcscmp(r->name,L"channel_b_transpose_track_high"))return xx_data_struct_record_set_comment(r,L"Bit0 is pattern-number bit8; upper7 bits encode signed transposition.");
 if(id==sxchip_chip_sks_position.id&&!xx_rt_wcscmp(r->name,L"channel_c_transpose_track_high"))return xx_data_struct_record_set_comment(r,L"Bit0 is pattern-number bit8; upper7 bits encode signed transposition.");
 if(id==sxchip_chip_sks_position.id&&!xx_rt_wcscmp(r->name,L"last_row_index"))return xx_data_struct_record_set_comment(r,L"Number of pattern rows minus one.");
 if(id==sxchip_chip_sks_instrument.id&&!xx_rt_wcscmp(r->name,L"record_size"))return xx_data_struct_record_set_comment(r,L"Byte length begins at the record_size field, excluding the preceding instrument number.");
 if(id==sxchip_chip_sks_instrument.id&&!xx_rt_wcscmp(r->name,L"loop_relative_offset"))return xx_data_struct_record_set_comment(r,L"Stored relative loop reference from the instrument representation; no file-absolute conversion is applied.");
 if(id==sxchip_chip_sks_instrument.id&&!xx_rt_wcscmp(r->name,L"last_line_index"))return xx_data_struct_record_set_comment(r,L"Number of instrument lines minus one. Packed line commands remain raw.");
 if(id==sxchip_chip_sks_special.id&&!xx_rt_wcscmp(r->name,L"record_size"))return xx_data_struct_record_set_comment(r,L"Byte length starts at this size field and excludes the preceding two-byte track number.");
 if(id==sxchip_chip_sks_track.id&&!xx_rt_wcscmp(r->name,L"record_size"))return xx_data_struct_record_set_comment(r,L"Byte length starts at this size field and excludes the preceding two-byte track number.");
 if(id==sxchip_chip_starkos_binary_header.id&&!xx_rt_wcscmp(r->name,L"replay_frequency"))return xx_data_struct_record_set_comment(r,L"Player calls per second (13,25,50,100,150 or300Hz).");
 if(id==sxchip_chip_atari_segment.id&&!xx_rt_wcscmp(r->name,L"inclusive_end_address"))return xx_data_struct_record_set_comment(r,L"Inclusive target-memory end address; stored payload length is end-load+1.");
 if(id==sxchip_chip_tmc_header.id&&!xx_rt_wcscmp(r->name,L"tempo_minus_one"))return xx_data_struct_record_set_comment(r,L"Maintained ASAP player uses stored value+1 frame ticks per pattern row.");
 if(id==sxchip_chip_tm2_header.id&&!xx_rt_wcscmp(r->name,L"tempo_minus_one"))return xx_data_struct_record_set_comment(r,L"Maintained ASAP player uses stored value+1 player calls per pattern row.");
 if(id==sxchip_chip_tm2_header.id&&!xx_rt_wcscmp(r->name,L"output_mode"))return xx_data_struct_record_set_comment(r,L"0 mono;1..63 stereo;64..127 RMT stereo;128..255 quadro.");
 if(id==sxchip_chip_tm2_title.id&&!xx_rt_wcscmp(r->name,L"title_row_1"))return xx_data_struct_record_set_comment(r,L"Stored ATASCII row, including the first/last side-frame bytes; bytes are preserved without transcoding.");
 if(id==sxchip_chip_tm2_title.id&&!xx_rt_wcscmp(r->name,L"title_row_2"))return xx_data_struct_record_set_comment(r,L"Stored ATASCII row, including the first/last side-frame bytes; bytes are preserved without transcoding.");
 if(id==sxchip_chip_tm2_title.id&&!xx_rt_wcscmp(r->name,L"title_row_3"))return xx_data_struct_record_set_comment(r,L"Stored ATASCII row, including the first/last side-frame bytes; bytes are preserved without transcoding.");
 if(id==sxchip_chip_address_low.id&&!xx_rt_wcscmp(r->name,L"address_low"))return xx_data_struct_record_set_comment(r,L"Low8 bits of a split target-memory address; the corresponding high-byte plane is separate.");
 if(id==sxchip_chip_address_high.id&&!xx_rt_wcscmp(r->name,L"address_high"))return xx_data_struct_record_set_comment(r,L"High8 bits of a split target-memory address; this component is not a complete address.");
 if(id==sxchip_chip_tmc_position.id&&!xx_rt_wcscmp(r->name,L"channel_8_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tmc_position.id&&!xx_rt_wcscmp(r->name,L"channel_7_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tmc_position.id&&!xx_rt_wcscmp(r->name,L"channel_6_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tmc_position.id&&!xx_rt_wcscmp(r->name,L"channel_5_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tmc_position.id&&!xx_rt_wcscmp(r->name,L"channel_4_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tmc_position.id&&!xx_rt_wcscmp(r->name,L"channel_3_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tmc_position.id&&!xx_rt_wcscmp(r->name,L"channel_2_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tmc_position.id&&!xx_rt_wcscmp(r->name,L"channel_1_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tm2_position.id&&!xx_rt_wcscmp(r->name,L"channel_8_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tm2_position.id&&!xx_rt_wcscmp(r->name,L"channel_7_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tm2_position.id&&!xx_rt_wcscmp(r->name,L"channel_6_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tm2_position.id&&!xx_rt_wcscmp(r->name,L"channel_5_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tm2_position.id&&!xx_rt_wcscmp(r->name,L"channel_4_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tm2_position.id&&!xx_rt_wcscmp(r->name,L"channel_3_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tm2_position.id&&!xx_rt_wcscmp(r->name,L"channel_2_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tm2_position.id&&!xx_rt_wcscmp(r->name,L"channel_1_transposition"))return xx_data_struct_record_set_comment(r,L"Encoded note transposition byte consumed in target-player arithmetic; stored value is retained.");
 if(id==sxchip_chip_tmc_position.id&&!xx_rt_wcscmp(r->name,L"channel_1_pattern"))return xx_data_struct_record_set_comment(r,L"High bit denotes a song-control/end position; an all-FF row is the normal terminator.");
 if(id==sxchip_chip_tm2_position.id&&!xx_rt_wcscmp(r->name,L"row_count_or_control"))return xx_data_struct_record_set_comment(r,L"1..64 pattern rows;0 ends song;128..255 jumps using the preceding channel1 pattern byte as target index.");
 if(id==sxchip_chip_tmc_parameters.id&&!xx_rt_wcscmp(r->name,L"frequency_table_rate"))return xx_data_struct_record_set_comment(r,L"High2 bits select frequency table; low6 bits encode effect-update interval minus one.");
 if(id==sxchip_chip_tmc_parameters.id&&!xx_rt_wcscmp(r->name,L"arpeggio_flags"))return xx_data_struct_record_set_comment(r,L"Low4 bits encode step interval minus one; bits4..6 encode arpeggio last index; bit7 enables a forward/backward cycle.");
 if(id==sxchip_chip_tm2_envelope_header.id&&!xx_rt_wcscmp(r->name,L"loop_byte_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset into the following three-byte envelope-step data, not a step index.");
 if(id==sxchip_chip_tmc_envelope.id&&!xx_rt_wcscmp(r->name,L"distortion_main_volume"))return xx_data_struct_record_set_comment(r,L"High nibble is POKEY distortion; low nibble is main envelope volume.");
 if(id==sxchip_chip_tmc_envelope.id&&!xx_rt_wcscmp(r->name,L"accent_extra_volume"))return xx_data_struct_record_set_comment(r,L"High nibble selects accent/AUDCTL behavior; low nibble is extra envelope volume.");
 if(id==sxchip_chip_mbm_header.id&&!xx_rt_wcscmp(r->name,L"song_last_position"))return xx_data_struct_record_set_comment(r,L"Inclusive last position index; playback uses this stored value plus one positions.");
 if(id==sxchip_chip_mbm_header.id&&!xx_rt_wcscmp(r->name,L"tempo"))return xx_data_struct_record_set_comment(r,L"Stored player timing/control value; not an asserted beats-per-minute value.");
 if(id==sxchip_chip_mfm_header.id&&!xx_rt_wcscmp(r->name,L"song_last_position"))return xx_data_struct_record_set_comment(r,L"Inclusive last position index; playback uses this stored value plus one positions.");
 if(id==sxchip_chip_mfm_header.id&&!xx_rt_wcscmp(r->name,L"tempo"))return xx_data_struct_record_set_comment(r,L"Stored player timing/control value; not an asserted beats-per-minute value.");
 if(id==sxchip_chip_mwm_header.id&&!xx_rt_wcscmp(r->name,L"song_last_position"))return xx_data_struct_record_set_comment(r,L"Inclusive last position index; playback uses this stored value plus one positions.");
 if(id==sxchip_chip_mwm_header.id&&!xx_rt_wcscmp(r->name,L"tempo"))return xx_data_struct_record_set_comment(r,L"Stored player timing/control value; not an asserted beats-per-minute value.");
 if(id==sxchip_chip_mbm_header.id&&!xx_rt_wcscmp(r->name,L"drum_frequency_words"))return xx_data_struct_record_set_comment(r,L"Nine little-endian stored chip frequency words, arranged as three groups of three; not file addresses.");
 if(id==sxchip_chip_mbm_header.id&&!xx_rt_wcscmp(r->name,L"unused"))return xx_data_struct_record_set_comment(r,L"Two stored bytes unused by the retained loader; preserved without inferred semantics.");
 if(id==sxchip_chip_mbm_pattern_pointer.id&&!xx_rt_wcscmp(r->name,L"pattern_offset"))return xx_data_struct_record_set_comment(r,L"Stored module offset before the edit marker; edit-mode physical origin is one byte after file start. Pattern bytecode remains raw.");
 if(id==sxchip_chip_moon_segment_pointer.id&&!xx_rt_wcscmp(r->name,L"segment_and_offset"))return xx_data_struct_record_set_comment(r,L"Packed runtime reference: high two bits select a loaded segment, low fourteen bits are its byte offset. This is not an absolute file offset.");
 if(id==sxchip_chip_moon_pattern_segment.id&&!xx_rt_wcscmp(r->name,L"encoded_size"))return xx_data_struct_record_set_comment(r,L"Number of following encoded pattern bytes in this physical segment; a zero pattern count terminates the segment sequence.");
 if(id==sxchip_chip_mwk_header.id&&!xx_rt_wcscmp(r->name,L"own_tone_info"))return xx_data_struct_record_set_comment(r,L"64 tone-slot flag bytes: bit0 selects a physical tone record, bit5 suppresses embedded PCM, high bits carry chip sample/address encoding.");
 if(id==sxchip_chip_mwk_header.id&&!xx_rt_wcscmp(r->name,L"total_sample_size"))return xx_data_struct_record_set_comment(r,L"Stored three-byte sample-data size from the kit header; individual embedded lengths are checked against the physical file.");
 if(id==sxchip_chip_mwk_patch.id&&!xx_rt_wcscmp(r->name,L"transpose"))return xx_data_struct_record_set_comment(r,L"Stored one-byte boolean from the packed Z80 OWN_PATCH structure; eight three-byte note/tone parts follow.");
 if(id==sxchip_chip_mwk_ram_tone.id&&!xx_rt_wcscmp(r->name,L"loop_address"))return xx_data_struct_record_set_comment(r,L"Big-endian OPL4 loop address within the tone; target sample-memory coordinate, not a physical file offset.");
 if(id==sxchip_chip_mwk_ram_tone.id&&!xx_rt_wcscmp(r->name,L"hardware_end"))return xx_data_struct_record_set_comment(r,L"Big-endian OPL4 hardware end-address encoding; not an unencoded byte size or a physical file offset.");
 if(id==sxchip_chip_mwk_rom_tone.id&&!xx_rt_wcscmp(r->name,L"loop_address"))return xx_data_struct_record_set_comment(r,L"Big-endian OPL4 loop address within the tone; target sample-memory coordinate, not a physical file offset.");
 if(id==sxchip_chip_mwk_rom_tone.id&&!xx_rt_wcscmp(r->name,L"hardware_end"))return xx_data_struct_record_set_comment(r,L"Big-endian OPL4 hardware end-address encoding; not an unencoded byte size or a physical file offset.");
 if(id==sxchip_chip_mwk_rom_tone.id&&!xx_rt_wcscmp(r->name,L"rom_address_high"))return xx_data_struct_record_set_comment(r,L"Stored high address/format component used for a ROM-backed tone; bit5 in own_tone_info means no embedded sample payload.");
 if(id==sxchip_chip_fac_footer.id&&!xx_rt_wcscmp(r->name,L"wait_frames"))return xx_data_struct_record_set_comment(r,L"Stored frame-wait count (normally1..25); the editor tempo level is26 minus this value. Not BPM.");
 if(id==sxchip_chip_fac_footer.id&&!xx_rt_wcscmp(r->name,L"last_track"))return xx_data_struct_record_set_comment(r,L"Inclusive last track index0..83; each physical unencrypted track has16 twelve-byte rows.");
 if(id==sxchip_chip_fac_footer.id&&!xx_rt_wcscmp(r->name,L"device"))return xx_data_struct_record_set_comment(r,L"Version-dependent device selector: version2 zero meansMSX-AUDIO, while Pro zero meansMSX-MUSIC; the opposite chip is selected by nonzero.");
 if(id==sxchip_chip_fac_footer.id&&!xx_rt_wcscmp(r->name,L"version"))return xx_data_struct_record_set_comment(r,L"Stored tracker version byte:2 is version2,3 is Pro; original version1 did not reliably stamp this byte.");
 if(id==sxchip_chip_fac_pro_footer.id&&!xx_rt_wcscmp(r->name,L"wait_frames"))return xx_data_struct_record_set_comment(r,L"Stored frame-wait count (normally1..25); the editor tempo level is26 minus this value. Not BPM.");
 if(id==sxchip_chip_fac_pro_footer.id&&!xx_rt_wcscmp(r->name,L"last_track"))return xx_data_struct_record_set_comment(r,L"Inclusive last track index0..83; each physical unencrypted track has16 twelve-byte rows.");
 if(id==sxchip_chip_fac_pro_footer.id&&!xx_rt_wcscmp(r->name,L"device"))return xx_data_struct_record_set_comment(r,L"Version-dependent device selector: version2 zero meansMSX-AUDIO, while Pro zero meansMSX-MUSIC; the opposite chip is selected by nonzero.");
 if(id==sxchip_chip_fac_pro_footer.id&&!xx_rt_wcscmp(r->name,L"version"))return xx_data_struct_record_set_comment(r,L"Stored tracker version byte:2 is version2,3 is Pro; original version1 did not reliably stamp this byte.");
 if(id==sxchip_chip_fac_row.id&&!xx_rt_wcscmp(r->name,L"drums_packed"))return xx_data_struct_record_set_comment(r,L"Stored packed drum-event bits; physical rows are emitted only for unencrypted version1/2 pattern data.");
 if(id==sxchip_chip_1tracker_speed.id&&!xx_rt_wcscmp(r->name,L"speed"))return xx_data_struct_record_set_comment(r,L"Stored tracker speed setting; timing is interpreted by the named engine, not asserted BPM.");
 if(id==sxchip_chip_1tracker_loop_start.id&&!xx_rt_wcscmp(r->name,L"loop_start"))return xx_data_struct_record_set_comment(r,L"Stored song-row loop start index; not a physical file offset.");
 if(id==sxchip_chip_1tracker_loop_end.id&&!xx_rt_wcscmp(r->name,L"loop_end"))return xx_data_struct_record_set_comment(r,L"Stored song-row loop end index; not a physical file offset.");
 if(id==sxchip_chip_1tracker_pattern_format.id&&!xx_rt_wcscmp(r->name,L"pattern_format"))return xx_data_struct_record_set_comment(r,L"Stored engine pattern-format description. Engine-specific instrument/song events remain raw.");
 if(r->property&SX_OFFSET)return xx_data_struct_record_set_comment(r,L"Stored byte offset relative to the module start, unless the enclosing structure specifies another origin.");
 if(r->property&SX_ADDRESS)return xx_data_struct_record_set_comment(r,L"Encoded target-machine memory address; the field source-file offset is shown separately.");
 return true;
}
const sx_family sx_chipmusic_family={sx_chipmusic_supports,sx_chipmusic_build,sx_chipmusic_layouts,SX_COUNT(sx_chipmusic_layouts),sx_chipmusic_comment};
