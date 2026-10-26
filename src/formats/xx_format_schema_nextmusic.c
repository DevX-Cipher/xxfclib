/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical music header and table metadata; compressed and unknown bodies stay raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_nextmusic.h"
static const xx_data_struct_field_desc sxnextm_text_fields[]={
 SX_FIELD("text","char",0,0,SX_NONE),
};
static const sx_layout sxnextm_text={UINT32_C(0x608B0001),"text",sxnextm_text_fields,SX_COUNT(sxnextm_text_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_u8_fields[]={
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
const sx_layout sxnextm_u8={UINT32_C(0x608B0002),"u8",sxnextm_u8_fields,SX_COUNT(sxnextm_u8_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_i8_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
const sx_layout sxnextm_i8={UINT32_C(0x608B0003),"i8",sxnextm_i8_fields,SX_COUNT(sxnextm_i8_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_count16_fields[]={
 SX_FIELD("count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxnextm_count16={UINT32_C(0x608B0004),"count16",sxnextm_count16_fields,SX_COUNT(sxnextm_count16_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_offset16_fields[]={
 SX_FIELD("offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxnextm_offset16={UINT32_C(0x608B0005),"offset16",sxnextm_offset16_fields,SX_COUNT(sxnextm_offset16_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_bytes32_fields[]={
 SX_FIELD("byte_count","uint32",0,4,SX_SIZE),
};
const sx_layout sxnextm_bytes32={UINT32_C(0x608B0006),"bytes32",sxnextm_bytes32_fields,SX_COUNT(sxnextm_bytes32_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_order8_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_ID),
};
const sx_layout sxnextm_order8={UINT32_C(0x608B0008),"order8",sxnextm_order8_fields,SX_COUNT(sxnextm_order8_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ast_header_fields[]={
 SX_FIELD("tempo","uint16",0,2,SX_NONE),
 SX_FIELD("section0_bytes","uint32",2,4,SX_SIZE),
 SX_FIELD("section1_bytes","uint32",6,4,SX_SIZE),
 SX_FIELD("section2_bytes","uint32",10,4,SX_SIZE),
 SX_FIELD("section3_bytes","uint32",14,4,SX_SIZE),
 SX_FIELD("section4_bytes","uint32",18,4,SX_SIZE),
 SX_FIELD("section5_bytes","uint32",22,4,SX_SIZE),
 SX_FIELD("section6_bytes","uint32",26,4,SX_SIZE),
 SX_FIELD("section7_bytes","uint32",30,4,SX_SIZE),
 SX_FIELD("section8_bytes","uint32",34,4,SX_SIZE),
 SX_FIELD("section9_bytes","uint32",38,4,SX_SIZE),
 SX_FIELD("section10_bytes","uint32",42,4,SX_SIZE),
 SX_FIELD("section11_bytes","uint32",46,4,SX_SIZE),
 SX_FIELD("section12_bytes","uint32",50,4,SX_SIZE),
 SX_FIELD("section13_bytes","uint32",54,4,SX_SIZE),
 SX_FIELD("section14_bytes","uint32",58,4,SX_SIZE),
};
const sx_layout sxnextm_ast_header={UINT32_C(0x608B000B),"ast_header",sxnextm_ast_header_fields,SX_COUNT(sxnextm_ast_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_ast_sample_fields[]={
 SX_FIELD("stored_data_pointer","uint32",0,4,SX_NONE),
 SX_FIELD("length_words","uint16",4,2,SX_NONE),
 SX_FIELD("loop_start_words","uint16",6,2,SX_NONE),
 SX_FIELD("loop_length_words","uint16",8,2,SX_NONE),
 SX_FIELD("effect_start","uint16",10,2,SX_NONE),
 SX_FIELD("effect_length","uint16",12,2,SX_NONE),
 SX_FIELD("effect_speed","uint16",14,2,SX_NONE),
 SX_FIELD("effect_mode","uint16",16,2,SX_ID),
 SX_FIELD("effect_increment","int16",18,2,SX_NONE),
 SX_FIELD("effect_position","int32",20,4,SX_NONE),
 SX_FIELD("effect_counter","uint16",24,2,SX_NONE),
 SX_FIELD("already_taken","uint16",26,2,SX_FLAGS),
 SX_FIELD("unknown","bytes",28,4,SX_NONE),
 SX_FIELD("name","char[32]",32,32,SX_NONE),
};
const sx_layout sxnextm_ast_sample={UINT32_C(0x608B0010),"ast_sample",sxnextm_ast_sample_fields,SX_COUNT(sxnextm_ast_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_dss_sample_fields[]={
 SX_FIELD("name","char[30]",0,30,SX_NONE),
 SX_FIELD("start_offset_encoded","uint32",30,4,SX_NONE),
 SX_FIELD("length_words","uint16",34,2,SX_NONE),
 SX_FIELD("loop_start","uint32",36,4,SX_OFFSET),
 SX_FIELD("loop_length_words","uint16",40,2,SX_NONE),
 SX_FIELD("finetune","uint8",42,1,SX_NONE),
 SX_FIELD("volume","uint8",43,1,SX_NONE),
 SX_FIELD("frequency","uint16",44,2,SX_NONE),
};
const sx_layout sxnextm_dss_sample={UINT32_C(0x608B0012),"dss_sample",sxnextm_dss_sample_fields,SX_COUNT(sxnextm_dss_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_instrument_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_NONE),
 SX_FIELD("instrument_index","uint32",32,4,SX_ID),
 SX_FIELD("repeat_start","uint16",36,2,SX_OFFSET),
 SX_FIELD("length_words","uint16",38,2,SX_NONE),
 SX_FIELD("period","uint16",40,2,SX_NONE),
 SX_FIELD("vibrato_delay","uint8",42,1,SX_NONE),
 SX_FIELD("unknown0","uint8",43,1,SX_NONE),
 SX_FIELD("vibrato_speed","int8",44,1,SX_NONE),
 SX_FIELD("vibrato_amplitude","int8",45,1,SX_NONE),
 SX_FIELD("envelope_volume","uint8",46,1,SX_NONE),
 SX_FIELD("attack_speed","uint8",47,1,SX_NONE),
 SX_FIELD("attack_volume","uint8",48,1,SX_NONE),
 SX_FIELD("decay_speed","uint8",49,1,SX_NONE),
 SX_FIELD("decay_volume","uint8",50,1,SX_NONE),
 SX_FIELD("sustain_delay","uint8",51,1,SX_NONE),
 SX_FIELD("release_speed","uint8",52,1,SX_NONE),
 SX_FIELD("release_volume","uint8",53,1,SX_NONE),
 SX_FIELD("arpeggio0","int8",54,1,SX_NONE),
 SX_FIELD("arpeggio1","int8",55,1,SX_NONE),
 SX_FIELD("arpeggio2","int8",56,1,SX_NONE),
 SX_FIELD("arpeggio3","int8",57,1,SX_NONE),
 SX_FIELD("arpeggio4","int8",58,1,SX_NONE),
 SX_FIELD("arpeggio5","int8",59,1,SX_NONE),
 SX_FIELD("arpeggio6","int8",60,1,SX_NONE),
 SX_FIELD("arpeggio7","int8",61,1,SX_NONE),
 SX_FIELD("arpeggio8","int8",62,1,SX_NONE),
 SX_FIELD("arpeggio9","int8",63,1,SX_NONE),
 SX_FIELD("arpeggio10","int8",64,1,SX_NONE),
 SX_FIELD("arpeggio11","int8",65,1,SX_NONE),
 SX_FIELD("arpeggio12","int8",66,1,SX_NONE),
 SX_FIELD("arpeggio13","int8",67,1,SX_NONE),
 SX_FIELD("arpeggio14","int8",68,1,SX_NONE),
 SX_FIELD("arpeggio15","int8",69,1,SX_NONE),
 SX_FIELD("arpeggio_speed","uint8",70,1,SX_NONE),
 SX_FIELD("instrument_type","uint8",71,1,SX_ID),
 SX_FIELD("pulse_rate_min","int8",72,1,SX_NONE),
 SX_FIELD("pulse_rate_plus","int8",73,1,SX_NONE),
 SX_FIELD("pulse_speed","uint8",74,1,SX_NONE),
 SX_FIELD("pulse_start","uint8",75,1,SX_NONE),
 SX_FIELD("pulse_end","uint8",76,1,SX_NONE),
 SX_FIELD("pulse_delay","uint8",77,1,SX_NONE),
 SX_FIELD("synchronization","uint8",78,1,SX_FLAGS),
 SX_FIELD("blend","uint8",79,1,SX_NONE),
 SX_FIELD("blend_delay","uint8",80,1,SX_NONE),
 SX_FIELD("pulse_shot_counter","uint8",81,1,SX_NONE),
 SX_FIELD("blend_shot_counter","uint8",82,1,SX_NONE),
 SX_FIELD("arpeggio_count","uint8",83,1,SX_NONE),
 SX_FIELD("unknown_tail","bytes",84,12,SX_NONE),
};
const sx_layout sxnextm_fred_instrument={UINT32_C(0x608B0016),"fred_instrument",sxnextm_fred_instrument_fields,SX_COUNT(sxnextm_fred_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_dtm_sample_fields[]={
 SX_FIELD("name","char[32]",0,32,SX_NONE),
 SX_FIELD("sample_bytes","uint32",32,4,SX_SIZE),
 SX_FIELD("loop_start","uint32",36,4,SX_OFFSET),
 SX_FIELD("loop_end","uint32",40,4,SX_OFFSET),
 SX_FIELD("c4_sample_rate","uint16",44,2,SX_NONE),
 SX_FIELD("volume","uint8",46,1,SX_NONE),
 SX_FIELD("bits_per_sample","uint8",47,1,SX_NONE),
 SX_FIELD("filename","char[13]",48,13,SX_NONE),
 SX_FIELD("reserved","bytes",61,3,SX_RESERVED),
};
const sx_layout sxnextm_dtm_sample={UINT32_C(0x608B001C),"dtm_sample",sxnextm_dtm_sample_fields,SX_COUNT(sxnextm_dtm_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_pitch_fields[]={
 SX_FIELD("pitch_or_noteoff","uint8",0,1,SX_NONE),
};
const sx_layout sxnextm_dtm_pitch={UINT32_C(0x608B001E),"dtm_pitch",sxnextm_dtm_pitch_fields,SX_COUNT(sxnextm_dtm_pitch_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_volume_fields[]={
 SX_FIELD("volume_plus_one","uint8",0,1,SX_NONE),
};
const sx_layout sxnextm_dtm_volume={UINT32_C(0x608B0020),"dtm_volume",sxnextm_dtm_volume_fields,SX_COUNT(sxnextm_dtm_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_dtm_effect_fields[]={
 SX_FIELD("effect_plus_one","uint8",0,1,SX_ID),
};
const sx_layout sxnextm_dtm_effect={UINT32_C(0x608B0021),"dtm_effect",sxnextm_dtm_effect_fields,SX_COUNT(sxnextm_dtm_effect_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ftm_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("samples","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("measures","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("tempo_timer","uint16",8,2,SX_NONE),
 SX_FIELD("tonality","uint8",10,1,SX_ID),
 SX_FIELD("channel_enable_mask","uint8",11,1,SX_FLAGS),
 SX_FIELD("global_volume","uint8",12,1,SX_NONE),
 SX_FIELD("flags","uint8",13,1,SX_FLAGS),
 SX_FIELD("ticks_per_row","uint8",14,1,SX_NONE),
 SX_FIELD("rows_per_measure","uint8",15,1,SX_COUNT_PROP),
 SX_FIELD("title","char[32]",16,32,SX_NONE),
 SX_FIELD("artist","char[32]",48,32,SX_NONE),
 SX_FIELD("effects","uint8",80,1,SX_COUNT_PROP),
 SX_FIELD("padding","uint8",81,1,SX_RESERVED),
};
const sx_layout sxnextm_ftm_header={UINT32_C(0x608B0024),"ftm_header",sxnextm_ftm_header_fields,SX_COUNT(sxnextm_ftm_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_ftm_script_event_fields[]={
 SX_FIELD("command","uint8",0,1,SX_ID),
 SX_FIELD("argument","uint24",1,3,SX_NONE),
};
const sx_layout sxnextm_ftm_script_event={UINT32_C(0x608B0027),"ftm_script_event",sxnextm_ftm_script_event_fields,SX_COUNT(sxnextm_ftm_script_event_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_eup_event_header_fields[]={
 SX_FIELD("event_bytes","int32",0,4,SX_SIZE),
 SX_FIELD("marker","uint8",4,1,SX_ID),
 SX_FIELD("initial_tempo","uint8",5,1,SX_NONE),
};
const sx_layout sxnextm_eup_event_header={UINT32_C(0x608B0034),"eup_event_header",sxnextm_eup_event_header_fields,SX_COUNT(sxnextm_eup_event_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_syn_header_fields[]={
 SX_FIELD("signature","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("positions","uint16",8,2,SX_COUNT_PROP),
 SX_FIELD("track_rows","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("unknown0","bytes",12,4,SX_NONE),
 SX_FIELD("samples","uint8",16,1,SX_COUNT_PROP),
 SX_FIELD("waveforms","uint8",17,1,SX_COUNT_PROP),
 SX_FIELD("instruments","uint8",18,1,SX_COUNT_PROP),
 SX_FIELD("subsongs","uint8",19,1,SX_COUNT_PROP),
 SX_FIELD("envelope_tables","uint8",20,1,SX_COUNT_PROP),
 SX_FIELD("adsr_tables","uint8",21,1,SX_COUNT_PROP),
 SX_FIELD("noise_length","uint8",22,1,SX_NONE),
 SX_FIELD("unknown1","bytes",23,13,SX_NONE),
 SX_FIELD("title","char[28]",36,28,SX_NONE),
 SX_FIELD("unused_text","char[140]",64,140,SX_NONE),
};
const sx_layout sxnextm_syn_header={UINT32_C(0x608B0035),"syn_header",sxnextm_syn_header_fields,SX_COUNT(sxnextm_syn_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_d00_header_fields[]={
 SX_FIELD("version","uint8",0,1,SX_ID),
 SX_FIELD("speed","uint8",1,1,SX_NONE),
 SX_FIELD("subsongs","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("track_table_offset","uint16",3,2,SX_OFFSET),
 SX_FIELD("sequence_table_offset","uint16",5,2,SX_OFFSET),
 SX_FIELD("instrument_table_offset","uint16",7,2,SX_OFFSET),
 SX_FIELD("information_offset","uint16",9,2,SX_OFFSET),
};
const sx_layout sxnextm_d00_header={UINT32_C(0x608B003B),"d00_header",sxnextm_d00_header_fields,SX_COUNT(sxnextm_d00_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_offset16le_fields[]={
 SX_FIELD("offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxnextm_offset16le={UINT32_C(0x608B003C),"offset16le",sxnextm_offset16le_fields,SX_COUNT(sxnextm_offset16le_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_offset32be_fields[]={
 SX_FIELD("offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxnextm_offset32be={UINT32_C(0x608B003E),"offset32be",sxnextm_offset32be_fields,SX_COUNT(sxnextm_offset32be_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_d00_tracks_fields[]={
 SX_FIELD("channel0_order_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("channel1_order_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("channel2_order_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("channel3_order_offset","uint16",6,2,SX_OFFSET),
 SX_FIELD("channel4_order_offset","uint16",8,2,SX_OFFSET),
 SX_FIELD("channel5_order_offset","uint16",10,2,SX_OFFSET),
 SX_FIELD("channel6_order_offset","uint16",12,2,SX_OFFSET),
 SX_FIELD("channel7_order_offset","uint16",14,2,SX_OFFSET),
 SX_FIELD("channel8_order_offset","uint16",16,2,SX_OFFSET),
 SX_FIELD("channel0_volume","uint8",18,1,SX_NONE),
 SX_FIELD("channel1_volume","uint8",19,1,SX_NONE),
 SX_FIELD("channel2_volume","uint8",20,1,SX_NONE),
 SX_FIELD("channel3_volume","uint8",21,1,SX_NONE),
 SX_FIELD("channel4_volume","uint8",22,1,SX_NONE),
 SX_FIELD("channel5_volume","uint8",23,1,SX_NONE),
 SX_FIELD("channel6_volume","uint8",24,1,SX_NONE),
 SX_FIELD("channel7_volume","uint8",25,1,SX_NONE),
 SX_FIELD("channel8_volume","uint8",26,1,SX_NONE),
 SX_FIELD("unknown","bytes",27,5,SX_NONE),
};
const sx_layout sxnextm_d00_tracks={UINT32_C(0x608B0040),"d00_tracks",sxnextm_d00_tracks_fields,SX_COUNT(sxnextm_d00_tracks_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("title","char[28]",4,28,SX_NONE),
 SX_FIELD("composer","char[28]",32,28,SX_NONE),
 SX_FIELD("marker","uint8",60,1,SX_ID),
 SX_FIELD("file_type","uint8",61,1,SX_ID),
 SX_FIELD("global_setting","uint8",62,1,SX_NONE),
 SX_FIELD("base_refresh_hz","uint8",63,1,SX_NONE),
 SX_FIELD("initial_ticks","uint8",64,1,SX_NONE),
 SX_FIELD("unknown","bytes",65,9,SX_NONE),
 SX_FIELD("order_count","uint8",74,1,SX_COUNT_PROP),
 SX_FIELD("instruments","uint8",75,1,SX_COUNT_PROP),
 SX_FIELD("patterns","uint8",76,1,SX_COUNT_PROP),
 SX_FIELD("packed_pan","bytes",77,5,SX_FLAGS),
};
const sx_layout sxnextm_fmk_header={UINT32_C(0x608B0042),"fmk_header",sxnextm_fmk_header_fields,SX_COUNT(sxnextm_fmk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_track_setting_fields[]={
 SX_FIELD("type_and_opl_channel","uint8",0,1,SX_FLAGS),
};
const sx_layout sxnextm_fmk_track_setting={UINT32_C(0x608B0043),"fmk_track_setting",sxnextm_fmk_track_setting_fields,SX_COUNT(sxnextm_fmk_track_setting_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_pattern_fields[]={
 SX_FIELD("encoded_bytes","uint16",0,2,SX_SIZE),
};
const sx_layout sxnextm_fmk_pattern={UINT32_C(0x608B0045),"fmk_pattern",sxnextm_fmk_pattern_fields,SX_COUNT(sxnextm_fmk_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_fmk_control_fields[]={
 SX_FIELD("track_and_fields","uint8",0,1,SX_FLAGS),
};
const sx_layout sxnextm_fmk_control={UINT32_C(0x608B0046),"fmk_control",sxnextm_fmk_control_fields,SX_COUNT(sxnextm_fmk_control_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_sct_instrument_fields[]={
 SX_FIELD("name","char[16]",0,16,SX_NONE),
 SX_FIELD("command_bytes","uint16",16,2,SX_SIZE),
 SX_FIELD("attack_speed","uint8",18,1,SX_NONE),
 SX_FIELD("attack_increment","uint8",19,1,SX_NONE),
 SX_FIELD("decay_speed","uint8",20,1,SX_NONE),
 SX_FIELD("decay_decrement","uint8",21,1,SX_NONE),
 SX_FIELD("decay_value","uint16",22,2,SX_NONE),
 SX_FIELD("release_speed","uint8",24,1,SX_NONE),
 SX_FIELD("release_decrement","uint8",25,1,SX_NONE),
 SX_FIELD("unused","bytes",26,22,SX_NONE),
};
const sx_layout sxnextm_sct_instrument={UINT32_C(0x608B004D),"sct_instrument",sxnextm_sct_instrument_fields,SX_COUNT(sxnextm_sct_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_sct_sample_fields[]={
 SX_FIELD("name","char[16]",0,16,SX_NONE),
 SX_FIELD("length_words","uint16",16,2,SX_NONE),
 SX_FIELD("loop_start_words","uint16",18,2,SX_NONE),
 SX_FIELD("loop_end_words","uint16",20,2,SX_NONE),
 SX_FIELD("unknown0","bytes",22,20,SX_NONE),
 SX_FIELD("note_transpose","int16",42,2,SX_NONE),
 SX_FIELD("unknown1","bytes",44,16,SX_NONE),
 SX_FIELD("total_record_bytes","uint32",60,4,SX_SIZE),
};
const sx_layout sxnextm_sct_sample={UINT32_C(0x608B004F),"sct_sample",sxnextm_sct_sample_fields,SX_COUNT(sxnextm_sct_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_psf_channels_fields[]={
 SX_FIELD("enabled_channel_mask","uint8",0,1,SX_FLAGS),
};
const sx_layout sxnextm_psf_channels={UINT32_C(0x608B0051),"psf_channels",sxnextm_psf_channels_fields,SX_COUNT(sxnextm_psf_channels_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_vss_song_offset_fields[]={
 SX_FIELD("footer_relative_offset","int32",0,4,SX_OFFSET),
};
const sx_layout sxnextm_vss_song_offset={UINT32_C(0x608B0053),"vss_song_offset",sxnextm_vss_song_offset_fields,SX_COUNT(sxnextm_vss_song_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_vss_data_offset_fields[]={
 SX_FIELD("song_relative_offset","int32",0,4,SX_OFFSET),
};
const sx_layout sxnextm_vss_data_offset={UINT32_C(0x608B0054),"vss_data_offset",sxnextm_vss_data_offset_fields,SX_COUNT(sxnextm_vss_data_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_mle_part_control_fields[]={
 SX_FIELD("fields_present","uint8",0,1,SX_FLAGS),
};
const sx_layout sxnextm_mle_part_control={UINT32_C(0x608B0059),"mle_part_control",sxnextm_mle_part_control_fields,SX_COUNT(sxnextm_mle_part_control_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_mle_sample_fields[]={
 SX_FIELD("decoded_bytes","uint32",0,4,SX_SIZE),
 SX_FIELD("delta_command","uint8",4,1,SX_ID),
 SX_FIELD("unknown0","uint8",5,1,SX_NONE),
 SX_FIELD("title","char[32]",6,32,SX_NONE),
 SX_FIELD("unknown1","uint8",38,1,SX_NONE),
 SX_FIELD("sample_type","uint8",39,1,SX_ID),
 SX_FIELD("stored_sample_pointer","uint32",40,4,SX_POINTER),
 SX_FIELD("length_words","uint16",44,2,SX_NONE),
 SX_FIELD("stored_repeat_pointer","uint32",46,4,SX_POINTER),
 SX_FIELD("repeat_words","uint16",50,2,SX_NONE),
 SX_FIELD("fine_tune","int16",52,2,SX_NONE),
 SX_FIELD("semitone","int16",54,2,SX_NONE),
};
const sx_layout sxnextm_mle_sample={UINT32_C(0x608B005D),"mle_sample",sxnextm_mle_sample_fields,SX_COUNT(sxnextm_mle_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_puma_header_fields[]={
 SX_FIELD("title","char[12]",0,12,SX_NONE),
 SX_FIELD("last_position","uint16",12,2,SX_NONE),
 SX_FIELD("tracks","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("instruments","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("unknown","uint16",18,2,SX_NONE),
 SX_FIELD("sample0_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("sample1_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("sample2_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("sample3_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("sample4_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("sample5_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("sample6_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("sample7_offset","uint32",48,4,SX_OFFSET),
 SX_FIELD("sample8_offset","uint32",52,4,SX_OFFSET),
 SX_FIELD("sample9_offset","uint32",56,4,SX_OFFSET),
 SX_FIELD("sample0_words_plus_one","uint16",60,2,SX_NONE),
 SX_FIELD("sample1_words_plus_one","uint16",62,2,SX_NONE),
 SX_FIELD("sample2_words_plus_one","uint16",64,2,SX_NONE),
 SX_FIELD("sample3_words_plus_one","uint16",66,2,SX_NONE),
 SX_FIELD("sample4_words_plus_one","uint16",68,2,SX_NONE),
 SX_FIELD("sample5_words_plus_one","uint16",70,2,SX_NONE),
 SX_FIELD("sample6_words_plus_one","uint16",72,2,SX_NONE),
 SX_FIELD("sample7_words_plus_one","uint16",74,2,SX_NONE),
 SX_FIELD("sample8_words_plus_one","uint16",76,2,SX_NONE),
 SX_FIELD("sample9_words_plus_one","uint16",78,2,SX_NONE),
};
const sx_layout sxnextm_puma_header={UINT32_C(0x608B005F),"puma_header",sxnextm_puma_header_fields,SX_COUNT(sxnextm_puma_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_ma_relative32_fields[]={
 SX_FIELD("module_relative_offset","int32",0,4,SX_OFFSET),
};
const sx_layout sxnextm_ma_relative32={UINT32_C(0x608B0064),"ma_relative32",sxnextm_ma_relative32_fields,SX_COUNT(sxnextm_ma_relative32_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_ma_track_offset_fields[]={
 SX_FIELD("track_data_relative_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxnextm_ma_track_offset={UINT32_C(0x608B0065),"ma_track_offset",sxnextm_ma_track_offset_fields,SX_COUNT(sxnextm_ma_track_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_ma_subsong_fields[]={
 SX_FIELD("voice0_position_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("voice1_position_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("voice2_position_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("voice3_position_offset","uint16",6,2,SX_OFFSET),
};
const sx_layout sxnextm_ma_subsong={UINT32_C(0x608B0066),"ma_subsong",sxnextm_ma_subsong_fields,SX_COUNT(sxnextm_ma_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_ma_position_fields[]={
 SX_FIELD("track_number","uint8",0,1,SX_ID),
 SX_FIELD("transpose_and_repeat","uint8",1,1,SX_FLAGS),
};
const sx_layout sxnextm_ma_position={UINT32_C(0x608B0067),"ma_position",sxnextm_ma_position_fields,SX_COUNT(sxnextm_ma_position_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ma_sample_fields[]={
 SX_FIELD("sample_info_relative_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("length_words","uint16",4,2,SX_NONE),
 SX_FIELD("loop_length_words","uint16",6,2,SX_NONE),
 SX_FIELD("name","char[16]",8,16,SX_NONE),
};
const sx_layout sxnextm_ma_sample={UINT32_C(0x608B006A),"ma_sample",sxnextm_ma_sample_fields,SX_COUNT(sxnextm_ma_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_final_header_fields[]={
 SX_FIELD("played_song","uint8",0,1,SX_ID),
 SX_FIELD("last_subsong_index","uint8",1,1,SX_ID),
 SX_FIELD("current_tempo","uint8",2,1,SX_NONE),
 SX_FIELD("subsong0_start_tempo","uint8",3,1,SX_NONE),
 SX_FIELD("subsong1_start_tempo","uint8",4,1,SX_NONE),
 SX_FIELD("subsong2_start_tempo","uint8",5,1,SX_NONE),
 SX_FIELD("subsong3_start_tempo","uint8",6,1,SX_NONE),
 SX_FIELD("subsong4_start_tempo","uint8",7,1,SX_NONE),
 SX_FIELD("subsong5_start_tempo","uint8",8,1,SX_NONE),
 SX_FIELD("subsong6_start_tempo","uint8",9,1,SX_NONE),
 SX_FIELD("subsong7_start_tempo","uint8",10,1,SX_NONE),
 SX_FIELD("subsong8_start_tempo","uint8",11,1,SX_NONE),
 SX_FIELD("subsong9_start_tempo","uint8",12,1,SX_NONE),
 SX_FIELD("unknown","uint8",13,1,SX_NONE),
 SX_FIELD("instrument_offset","uint32",14,4,SX_OFFSET),
 SX_FIELD("track_offset","uint32",18,4,SX_OFFSET),
};
const sx_layout sxnextm_fred_final_header={UINT32_C(0x608B006B),"fred_final_header",sxnextm_fred_final_header_fields,SX_COUNT(sxnextm_fred_final_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_final_subsong_fields[]={
 SX_FIELD("voice0_sequence_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("voice1_sequence_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("voice2_sequence_offset","uint16",4,2,SX_OFFSET),
 SX_FIELD("voice3_sequence_offset","uint16",6,2,SX_OFFSET),
};
const sx_layout sxnextm_fred_final_subsong={UINT32_C(0x608B006C),"fred_final_subsong",sxnextm_fred_final_subsong_fields,SX_COUNT(sxnextm_fred_final_subsong_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_final_position_fields[]={
 SX_FIELD("track_offset","int16",0,2,SX_OFFSET),
};
const sx_layout sxnextm_fred_final_position={UINT32_C(0x608B006D),"fred_final_position",sxnextm_fred_final_position_fields,SX_COUNT(sxnextm_fred_final_position_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_final_control_fields[]={
 SX_FIELD("sequence_control","int16",0,2,SX_NONE),
};
const sx_layout sxnextm_fred_final_control={UINT32_C(0x608B006E),"fred_final_control",sxnextm_fred_final_control_fields,SX_COUNT(sxnextm_fred_final_control_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_fred_final_instrument_fields[]={
 SX_FIELD("sample_offset","int32",0,4,SX_OFFSET),
 SX_FIELD("repeat_start","uint16",4,2,SX_OFFSET),
 SX_FIELD("length_words","uint16",6,2,SX_NONE),
 SX_FIELD("period","uint16",8,2,SX_NONE),
 SX_FIELD("vibrato_delay","uint8",10,1,SX_NONE),
 SX_FIELD("unknown0","uint8",11,1,SX_NONE),
 SX_FIELD("vibrato_speed","int8",12,1,SX_NONE),
 SX_FIELD("vibrato_amplitude","int8",13,1,SX_NONE),
 SX_FIELD("envelope_volume","uint8",14,1,SX_NONE),
 SX_FIELD("attack_speed","uint8",15,1,SX_NONE),
 SX_FIELD("attack_volume","uint8",16,1,SX_NONE),
 SX_FIELD("decay_speed","uint8",17,1,SX_NONE),
 SX_FIELD("decay_volume","uint8",18,1,SX_NONE),
 SX_FIELD("sustain_delay","uint8",19,1,SX_NONE),
 SX_FIELD("release_speed","uint8",20,1,SX_NONE),
 SX_FIELD("release_volume","uint8",21,1,SX_NONE),
 SX_FIELD("arpeggio0","int8",22,1,SX_NONE),
 SX_FIELD("arpeggio1","int8",23,1,SX_NONE),
 SX_FIELD("arpeggio2","int8",24,1,SX_NONE),
 SX_FIELD("arpeggio3","int8",25,1,SX_NONE),
 SX_FIELD("arpeggio4","int8",26,1,SX_NONE),
 SX_FIELD("arpeggio5","int8",27,1,SX_NONE),
 SX_FIELD("arpeggio6","int8",28,1,SX_NONE),
 SX_FIELD("arpeggio7","int8",29,1,SX_NONE),
 SX_FIELD("arpeggio8","int8",30,1,SX_NONE),
 SX_FIELD("arpeggio9","int8",31,1,SX_NONE),
 SX_FIELD("arpeggio10","int8",32,1,SX_NONE),
 SX_FIELD("arpeggio11","int8",33,1,SX_NONE),
 SX_FIELD("arpeggio12","int8",34,1,SX_NONE),
 SX_FIELD("arpeggio13","int8",35,1,SX_NONE),
 SX_FIELD("arpeggio14","int8",36,1,SX_NONE),
 SX_FIELD("arpeggio15","int8",37,1,SX_NONE),
 SX_FIELD("arpeggio_speed","uint8",38,1,SX_NONE),
 SX_FIELD("instrument_type","uint8",39,1,SX_ID),
 SX_FIELD("pulse_rate_min","int8",40,1,SX_NONE),
 SX_FIELD("pulse_rate_plus","int8",41,1,SX_NONE),
 SX_FIELD("pulse_speed","uint8",42,1,SX_NONE),
 SX_FIELD("pulse_start","uint8",43,1,SX_NONE),
 SX_FIELD("pulse_end","uint8",44,1,SX_NONE),
 SX_FIELD("pulse_delay","uint8",45,1,SX_NONE),
 SX_FIELD("synchronization","uint8",46,1,SX_FLAGS),
 SX_FIELD("blend","uint8",47,1,SX_NONE),
 SX_FIELD("blend_delay","uint8",48,1,SX_NONE),
 SX_FIELD("pulse_shot_counter","uint8",49,1,SX_NONE),
 SX_FIELD("blend_shot_counter","uint8",50,1,SX_NONE),
 SX_FIELD("arpeggio_count","uint8",51,1,SX_NONE),
 SX_FIELD("unknown_tail","bytes",52,12,SX_NONE),
};
const sx_layout sxnextm_fred_final_instrument={UINT32_C(0x608B006F),"fred_final_instrument",sxnextm_fred_final_instrument_fields,SX_COUNT(sxnextm_fred_final_instrument_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_sid1_base_offset_fields[]={
 SX_FIELD("player_base_relative_offset","int32",0,4,SX_OFFSET),
};
const sx_layout sxnextm_sid1_base_offset={UINT32_C(0x608B0070),"sid1_base_offset",sxnextm_sid1_base_offset_fields,SX_COUNT(sxnextm_sid1_base_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_sid1_song_fields[]={
 SX_FIELD("mix1_source1","uint32",0,4,SX_ID),
 SX_FIELD("mix2_source1","uint32",4,4,SX_ID),
 SX_FIELD("mix1_source2","uint32",8,4,SX_ID),
 SX_FIELD("mix2_source2","uint32",12,4,SX_ID),
 SX_FIELD("mix1_destination","uint32",16,4,SX_ID),
 SX_FIELD("mix2_destination","uint32",20,4,SX_ID),
 SX_FIELD("initial_rows","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("positions_plus_one","uint32",28,4,SX_NONE),
 SX_FIELD("initial_speed","uint32",32,4,SX_NONE),
 SX_FIELD("mix1_speed","uint32",36,4,SX_NONE),
 SX_FIELD("mix2_speed","uint32",40,4,SX_NONE),
};
const sx_layout sxnextm_sid1_song={UINT32_C(0x608B0071),"sid1_song",sxnextm_sid1_song_fields,SX_COUNT(sxnextm_sid1_song_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_mle_tune_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("declared_payload_bytes","uint32",4,4,SX_SIZE),
};
const sx_layout sxnextm_mle_tune_chunk={UINT32_C(0x608B0073),"mle_tune_chunk",sxnextm_mle_tune_chunk_fields,SX_COUNT(sxnextm_mle_tune_chunk_fields),SX_BE};
static const sx_layout *const sx_nextmusic_layouts[]={
 &sxnextm_text,
 &sxnextm_u8,
 &sxnextm_i8,
 &sxnextm_count16,
 &sxnextm_offset16,
 &sxnextm_bytes32,
 &sxnextm_track16,
 &sxnextm_order8,
 &sxnextm_chunk_le,
 &sxnextm_chunk_be,
 &sxnextm_ast_header,
 &sxnextm_ast_banner,
 &sxnextm_ast_module_size,
 &sxnextm_ast_instrument,
 &sxnextm_ast_subsong,
 &sxnextm_ast_sample,
 &sxnextm_dss_header,
 &sxnextm_dss_sample,
 &sxnextm_dss_event,
 &sxnextm_fred_header,
 &sxnextm_fred_track_length,
 &sxnextm_fred_instrument,
 &sxnextm_fred_sample,
 &sxnextm_fred_end,
 &sxnextm_dtm_info,
 &sxnextm_dtm_speed,
 &sxnextm_dtm_pan,
 &sxnextm_dtm_sample,
 &sxnextm_dtm_rows,
 &sxnextm_dtm_pitch,
 &sxnextm_dtm_instrument,
 &sxnextm_dtm_volume,
 &sxnextm_dtm_effect,
 &sxnextm_dtm_argument_high,
 &sxnextm_dtm_argument_low,
 &sxnextm_ftm_header,
 &sxnextm_ftm_sample,
 &sxnextm_ftm_script_header,
 &sxnextm_ftm_script_event,
 &sxnextm_eup_header,
 &sxnextm_eup_track_name,
 &sxnextm_eup_short_name,
 &sxnextm_eup_mute,
 &sxnextm_eup_port,
 &sxnextm_eup_channel,
 &sxnextm_eup_key_bias,
 &sxnextm_eup_transpose,
 &sxnextm_eup_filter,
 &sxnextm_eup_instrument_name,
 &sxnextm_eup_bank_names,
 &sxnextm_eup_application,
 &sxnextm_eup_event_header,
 &sxnextm_syn_header,
 &sxnextm_syn_sample_name,
 &sxnextm_syn_instrument,
 &sxnextm_syn_subsong,
 &sxnextm_syn_position,
 &sxnextm_syn_event,
 &sxnextm_d00_header,
 &sxnextm_offset16le,
 &sxnextm_offset32le,
 &sxnextm_offset32be,
 &sxnextm_d00_end,
 &sxnextm_d00_tracks,
 &sxnextm_d00_speed,
 &sxnextm_fmk_header,
 &sxnextm_fmk_track_setting,
 &sxnextm_fmk_instrument,
 &sxnextm_fmk_pattern,
 &sxnextm_fmk_control,
 &sxnextm_fmk_note,
 &sxnextm_fmk_volume,
 &sxnextm_fmk_effect,
 &sxnextm_sct_header,
 &sxnextm_sct_track,
 &sxnextm_sct_position,
 &sxnextm_sct_instrument,
 &sxnextm_sct_command,
 &sxnextm_sct_sample,
 &sxnextm_psf_header,
 &sxnextm_psf_channels,
 &sxnextm_vss_footer,
 &sxnextm_vss_song_offset,
 &sxnextm_vss_data_offset,
 &sxnextm_mle_magic,
 &sxnextm_mle_tune,
 &sxnextm_mle_sequence,
 &sxnextm_mle_index,
 &sxnextm_mle_part_control,
 &sxnextm_mle_part_note,
 &sxnextm_mle_effect,
 &sxnextm_mle_arpeggio,
 &sxnextm_mle_sample,
 &sxnextm_mle_instrument,
 &sxnextm_puma_header,
 &sxnextm_puma_position,
 &sxnextm_puma_marker,
 &sxnextm_puma_event,
 &sxnextm_puma_command,
 &sxnextm_ma_relative32,
 &sxnextm_ma_track_offset,
 &sxnextm_ma_subsong,
 &sxnextm_ma_position,
 &sxnextm_ma_speed,
 &sxnextm_ma_instrument,
 &sxnextm_ma_sample,
 &sxnextm_fred_final_header,
 &sxnextm_fred_final_subsong,
 &sxnextm_fred_final_position,
 &sxnextm_fred_final_control,
 &sxnextm_fred_final_instrument,
 &sxnextm_sid1_base_offset,
 &sxnextm_sid1_song,
 &sxnextm_sid1_sequence,
 &sxnextm_mle_tune_chunk,
};
bool sxnextm_span(sxnextm_view*v,uint64_t at,uint64_t n,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&v->c->size>=0&&end<=(uint64_t)v->c->size&&at<=end&&n<=end-at;}
bool sxnextm_read(sxnextm_view*v,uint64_t at,void*p,size_t n,uint64_t end)
{return ++v->work<=4000000&&sxnextm_span(v,at,n,end)&&sx_read(v->c,(int64_t)at,p,n);}
static bool sxnextm_word(sxnextm_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!n||n>8||!sxnextm_read(v,at,b,n,end))return false;uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[be?n-i-1:i]<<(8*i);*out=x;return true;}
bool sxnextm_row(sxnextm_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxnextm_span(v,at,z,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)z);}
bool sxnextm_table(sxnextm_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>4000000||count>UINT64_MAX/z||!sxnextm_span(v,at,count*z,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++,at+=z)if(!sxnextm_row(v,l,at,end))return false;return true;}
static int sxnextm_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxnextm_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxnextm_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxnextm_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
bool sxnextm_u(sxnextm_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxnextm_word(v,p,n,false,x,end);}
bool sxnextm_be(sxnextm_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end){return sxnextm_word(v,p,n,true,x,end);}
bool sxnextm_eq(sxnextm_view*v,uint64_t p,const char*s,size_t n,uint64_t end){uint8_t b[64];return n<=sizeof(b)&&sxnextm_read(v,p,b,n,end)&&!xx_rt_memcmp(b,s,n);}
bool sxnextm_text_emit(sxnextm_view*v,uint64_t p,uint64_t n,uint64_t end){if(!sxnextm_span(v,p,n,end))return false;return !n||n>4096||v->c->count>=24000||sx_add(v->c,&sxnextm_text,(int64_t)p,(int64_t)n);}
bool sxnextm_take(sxnextm_view*v,const sx_layout*l,uint64_t*p,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!sxnextm_table(v,l,*p,count,end))return false;*p+=count*z;return true;}
bool sxnextm_skip(sxnextm_view*v,uint64_t*p,uint64_t n,uint64_t end)
{if(!sxnextm_span(v,*p,n,end))return false;*p+=n;return true;}
bool sxnextm_rel32(sxnextm_view*v,uint64_t word,uint64_t base,uint64_t*out,uint64_t end){uint64_t x;if(base>end||!sxnextm_be(v,word,4,&x,end))return false;int64_t d=(x&0x80000000U)?(int64_t)x-INT64_C(0x100000000):(int64_t)x;if(d<0){uint64_t n=(uint64_t)(-d);if(n>base)return false;*out=base-n;}else{if((uint64_t)d>end-base)return false;*out=base+(uint64_t)d;}return *out<=end;}
/* Replay-code operands are used only to locate stored metadata. Instructions
   and executable bodies are not presented as invented container headers. */
bool sxnextm_rel(sxnextm_view*v,uint64_t at,unsigned n,uint64_t base,uint64_t*out,uint64_t e)
{uint64_t x;if(base>e||!n||n>4||!sxnextm_be(v,at,n,&x,e))return false;int64_t delta=(x&(UINT64_C(1)<<(n*8-1)))?(int64_t)x-(INT64_C(1)<<(n*8)):(int64_t)x;if(delta<0){if((uint64_t)(-delta)>base)return false;*out=base-(uint64_t)(-delta);}else{if((uint64_t)delta>e-base)return false;*out=base+(uint64_t)delta;}return true;}
bool sxnextm_find16(sxnextm_view*v,uint64_t*p,uint16_t word,uint64_t stop,uint64_t e)
{uint64_t x;for(;*p<stop;*p+=2){if(!sxnextm_be(v,*p,2,&x,e))return false;if(x==word)return true;}return false;}
static bool sx_nextmusic_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_DIE_MUSIC_KLEPS_ACTIONAMICSSOUNDTOOL:
case XX_FILE_TYPE_DIE_MUSIC_GREATVALLEYPROD_DIGITALSOUNDSTUDIO:
case XX_FILE_TYPE_DIE_MUSIC_BEHAM_DIGITREKKER_DTM:
case XX_FILE_TYPE_DIE_MUSIC_FUJITSU_EUPHONY_EUP:
case XX_FILE_TYPE_DIE_MUSIC_WILENIUS_FMKINGTRACKER:
case XX_FILE_TYPE_DIE_MUSIC_CLERMONTE_FREDEDITOR_PROJECT:
case XX_FILE_TYPE_DIE_MUSIC_MAXON_FACETHEMUSIC:
case XX_FILE_TYPE_DIE_MUSIC_MUSICLINEEDITOR:
case XX_FILE_TYPE_DIE_MUSIC_BRAINTRACEDESIGN_SYNTHESIS:
case XX_FILE_TYPE_DIE_MUSIC_PARTL_VOODOOSUPREMESYNTHESIZER:
case XX_FILE_TYPE_DIE_MUSIC_JCH_EDLIBTRACKER_RAW:
case XX_FILE_TYPE_DIE_MUSIC_MEYRIGNAC_PUMATRACKER:
case XX_FILE_TYPE_DIE_MUSIC_GEHRMANN_SOUNDCONTROL_SCT:
case XX_FILE_TYPE_DIE_MUSIC_URWANI_SOUNDFACTORY_PSF:
case XX_FILE_TYPE_DIE_MUSIC_GIESEN_MUSICASM:
case XX_FILE_TYPE_DIE_MUSIC_CLERMONTE_FREDEDITOR_FINAL:
case XX_FILE_TYPE_DIE_MUSIC_REINIERVANVLIET_SIDMON1:
return true;default:return false;}}
static bool sx_nextmusic_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxnextm_view view={c,0},*v=&view;bool ok=false;
 switch(c->f->file_type){
case XX_FILE_TYPE_DIE_MUSIC_KLEPS_ACTIONAMICSSOUNDTOOL:ok=sx_kleps_actionamicssoundtool_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_GREATVALLEYPROD_DIGITALSOUNDSTUDIO:ok=sx_greatvalleyprod_digitalsoundstudio_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_BEHAM_DIGITREKKER_DTM:ok=sx_beham_digitrekker_dtm_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_FUJITSU_EUPHONY_EUP:ok=sx_fujitsu_euphony_eup_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_WILENIUS_FMKINGTRACKER:ok=sx_wilenius_fmkingtracker_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_CLERMONTE_FREDEDITOR_PROJECT:ok=sx_clermonte_frededitor_project_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_MAXON_FACETHEMUSIC:ok=sx_maxon_facethemusic_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_MUSICLINEEDITOR:ok=sx_musiclineeditor_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_BRAINTRACEDESIGN_SYNTHESIS:ok=sx_braintracedesign_synthesis_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_PARTL_VOODOOSUPREMESYNTHESIZER:ok=sx_partl_voodoosupremesynthesizer_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_JCH_EDLIBTRACKER_RAW:ok=sx_jch_edlibtracker_raw_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_MEYRIGNAC_PUMATRACKER:ok=sx_meyrignac_pumatracker_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_GEHRMANN_SOUNDCONTROL_SCT:ok=sx_gehrmann_soundcontrol_sct_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_URWANI_SOUNDFACTORY_PSF:ok=sx_urwani_soundfactory_psf_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_GIESEN_MUSICASM:ok=sx_giesen_musicasm_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_CLERMONTE_FREDEDITOR_FINAL:ok=sx_clermonte_frededitor_final_build(v);break;
case XX_FILE_TYPE_DIE_MUSIC_REINIERVANVLIET_SIDMON1:ok=sx_reiniervanvliet_sidmon1_build(v);break;
default:break;}
 return ok&&sxnextm_finish(c);}
static bool sxnextm_name(const xx_data_struct_record*r,const wchar_t*s){return !xx_rt_wcscmp(r->name,s);}
static bool sx_nextmusic_comment(xx_data_struct_record*r,uint32_t id)
{if(!r||!r->name||id<UINT32_C(0x608b0001)||id>=UINT32_C(0x608c0000))return true;const wchar_t*s=NULL;
 if(sxnextm_name(r,L"length_words")||sxnextm_name(r,L"loop_start_words")||sxnextm_name(r,L"loop_end_words")||sxnextm_name(r,L"loop_length_words")||sxnextm_name(r,L"repeat_words"))s=L"Stored in two-byte sample words; not a byte count or file offset";
 if(id==sxnextm_ast_header.id&&sxnextm_name(r,L"tempo"))s=L"Initial tempo in beats per minute";
 else if(id==sxnextm_ast_sample.id){if(sxnextm_name(r,L"stored_data_pointer"))s=L"Stored data pointer skipped by the file loader; no physical address domain is inferred";else if(sxnextm_name(r,L"effect_start"))s=L"Effect start in two-byte sample words";else if(sxnextm_name(r,L"effect_length"))s=L"Stored effect length; original player also uses the high byte as the arpeggio-list index";}
 else if(id==sxnextm_dss_sample.id){if(sxnextm_name(r,L"start_offset_encoded"))s=L"Byte offset within this sample's stored data; loader clears bit 0 before use";else if(sxnextm_name(r,L"loop_start"))s=L"Byte offset relative to the sample start after its encoded start offset";else if(sxnextm_name(r,L"frequency"))s=L"Stored sample playback frequency in Hz";}
 else if(id==sxnextm_fred_instrument.id||id==sxnextm_fred_final_instrument.id){if(sxnextm_name(r,L"repeat_start"))s=L"PCM loop start in bytes; 0 and FFFF disable looping; synthesis instruments use their full waveform";else if(sxnextm_name(r,L"instrument_type"))s=L"0 PCM sample; 1 pulse synthesis; 2 blend synthesis; FF unused in compiled form";else if(sxnextm_name(r,L"sample_offset"))s=L"Signed byte offset relative to the compiled player's located offset base; zero denotes synthesis/unused data";else if(sxnextm_name(r,L"period"))s=L"Amiga playback period control; not a frequency in Hz";}
 else if(id==sxnextm_dtm_sample.id){if(sxnextm_name(r,L"loop_start")||sxnextm_name(r,L"loop_end"))s=L"Byte position within this sample's data";else if(sxnextm_name(r,L"c4_sample_rate"))s=L"Sample playback rate for note C4, in Hz";}
 else if(id==sxnextm_dtm_pitch.id)s=L"0 means no note; 1..96 encode C-0..B-7; 128 (80 hex) is note off";
 else if(id==sxnextm_dtm_volume.id)s=L"Zero means no change; other values store volume plus one";
 else if(id==sxnextm_dtm_effect.id)s=L"Zero means no effect; other values store the effect number plus one";
 else if(id==sxnextm_ftm_header.id){if(sxnextm_name(r,L"tempo_timer"))s=L"Amiga CIA timer period; this is not a direct BPM value";else if(sxnextm_name(r,L"flags"))s=L"Bit 0 embedded samples; bit 1 LED/filter state";else if(sxnextm_name(r,L"channel_enable_mask"))s=L"Bits 0..7 enable the corresponding music channels";}
 else if(id==sxnextm_ftm_script_event.id&&sxnextm_name(r,L"argument"))s=L"Big-endian 24-bit script argument; interpretation depends on command";
 else if(id==sxnextm_eup_event_header.id&&sxnextm_name(r,L"initial_tempo"))s=L"Encoded initial tempo; effective beats per minute is stored value plus 30";
 else if(id==sxnextm_syn_header.id&&sxnextm_name(r,L"track_rows"))s=L"Declared track-row count; the retained source loader physically reads this value plus 64 rows";
 else if(id==sxnextm_d00_header.id){if(sxnextm_name(r,L"speed"))s=L"Stored refresh-rate byte; version 0 playback overrides it with 70 Hz";else if(r->property&SX_OFFSET)s=L"Byte offset from the beginning of this raw EdLib image";}
 else if(id==sxnextm_d00_tracks.id){if(r->property&SX_OFFSET)s=L"Byte offset from raw EdLib image start to a speed word followed by sequence operands";else if(!xx_rt_wcsncmp(r->name,L"channel",7))s=L"Volume control: low 7 bits; AdPlug ignores bit 7";}
 else if(id==sxnextm_fmk_header.id){if(sxnextm_name(r,L"packed_pan"))s=L"Packed two-bit panning controls per track";else if(sxnextm_name(r,L"base_refresh_hz"))s=L"Base player update frequency in Hz";else if(sxnextm_name(r,L"initial_ticks"))s=L"Initial ticks per pattern row";}
 else if(id==sxnextm_fmk_track_setting.id)s=L"Low 3 bits track type; high 5 bits OPL channel number";
 else if(id==sxnextm_fmk_pattern.id)s=L"Encoded pattern bytes, excluding this two-byte size word";
 else if(id==sxnextm_fmk_control.id)s=L"Zero ends a row; low 5 bits track; bit 5 note/instrument; bit 6 volume; bit 7 effect/argument";
 else if(id==sxnextm_sct_sample.id&&sxnextm_name(r,L"total_record_bytes"))s=L"Sample record bytes including its 64-byte header";
 else if(id==sxnextm_sct_instrument.id&&sxnextm_name(r,L"command_bytes"))s=L"Bytes of six-byte commands following the 48-byte instrument header";
 else if(id==sxnextm_psf_channels.id)s=L"Bits 0..3 enable the four output channels for this subsong";
 else if(id==sxnextm_vss_song_offset.id)s=L"Signed byte offset relative to the VSS0 footer start";
 else if(id==sxnextm_vss_data_offset.id)s=L"Signed byte offset relative to this subsong's offset-table start";
 else if(id==sxnextm_mle_tune_chunk.id&&sxnextm_name(r,L"declared_payload_bytes"))s=L"Stored declared size; historical versions contain an incorrect value, so the physical extent is calculated from channel sizes";
 else if(id==sxnextm_mle_part_control.id)s=L"FF ends the part; bit 0 note/instrument; bits 1..5 present effect/argument pairs";
 else if(id==sxnextm_mle_sample.id){if(sxnextm_name(r,L"delta_command"))s=L"Escape byte used by the delta-coded sample stream";else if(sxnextm_name(r,L"stored_sample_pointer")||sxnextm_name(r,L"stored_repeat_pointer"))s=L"Legacy stored runtime pointer; not a physical file offset";}
 else if(id==sxnextm_puma_header.id){if(sxnextm_name(r,L"last_position"))s=L"Last zero-based position index; physical table has this value plus one entries";else if(!xx_rt_wcsncmp(r->name,L"sample",6)&&!(r->property&SX_OFFSET))s=L"Encoded sample length: stored value minus one two-byte words; zero denotes absent sample";}
 else if(id==sxnextm_ma_relative32.id)s=L"Signed byte offset relative to the module base located by the replay-code operand";
 else if(id==sxnextm_ma_subsong.id)s=L"Byte offset relative to the module base, pointing to a two-byte position list";
 else if(id==sxnextm_ma_track_offset.id)s=L"Byte offset relative to the separately located track-data block";
 else if(id==sxnextm_ma_position.id){if(sxnextm_name(r,L"track_number"))s=L"Track index; FE and FF terminate a position list";else s=L"High nibble transpose; low nibble shifted by three forms the repeat counter";}
 else if(id==sxnextm_ma_sample.id&&sxnextm_name(r,L"sample_info_relative_offset"))s=L"Signed byte offset relative to the sample-information block; negative values mean no stored PCM";
 else if(id==sxnextm_fred_final_header.id){if(sxnextm_name(r,L"last_subsong_index"))s=L"Last zero-based subsong index; number of subsongs is stored value plus one";else if(r->property&SX_OFFSET)s=L"Byte offset relative to the compiled player's located offset base";}
 else if(id==sxnextm_fred_final_subsong.id)s=L"Byte offset relative to the beginning of the subsong start-offset table";
 else if(id==sxnextm_fred_final_position.id)s=L"Nonnegative byte offset relative to the track-data block";
 else if(id==sxnextm_fred_final_control.id)s=L"Negative sequence-end/restart control word; low 15 bits encode a byte-scaled restart position";
 else if(id==sxnextm_sid1_base_offset.id)s=L"Signed byte offset relative to the located SidMon player data base";
 else if(id==sxnextm_sid1_song.id){if(sxnextm_name(r,L"positions_plus_one"))s=L"Stored position count plus one; physical sequence entry count is this value minus one";else if((r->property&SX_ID)&&!xx_rt_wcsncmp(r->name,L"mix",3))s=L"One-based waveform index used by the mixing effect; not a memory address";}
 return !s||xx_data_struct_record_set_comment(r,s);}
const sx_family sx_nextmusic_family={sx_nextmusic_supports,sx_nextmusic_build,sx_nextmusic_layouts,SX_COUNT(sx_nextmusic_layouts),sx_nextmusic_comment};
