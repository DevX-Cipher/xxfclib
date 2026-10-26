/* SPDX-License-Identifier: MIT
 * Tracker module metadata. Scope: docs/data_struct_trackerextra_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxtx_count_u8le_fields[] = {
    SX_FIELD("count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxtx_count_u8le = {UINT32_C(0x60340001),"count_u8le",sxtx_count_u8le_fields,SX_COUNT(sxtx_count_u8le_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_length_u8le_fields[] = {
    SX_FIELD("length","uint8",0,1,SX_SIZE),
};
static const sx_layout sxtx_length_u8le = {UINT32_C(0x60340002),"length_u8le",sxtx_length_u8le_fields,SX_COUNT(sxtx_length_u8le_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_order_u8le_fields[] = {
    SX_FIELD("order","uint8",0,1,SX_ID),
};
static const sx_layout sxtx_order_u8le = {UINT32_C(0x60340003),"order_u8le",sxtx_order_u8le_fields,SX_COUNT(sxtx_order_u8le_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_count_u16le_fields[] = {
    SX_FIELD("count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxtx_count_u16le = {UINT32_C(0x60340004),"count_u16le",sxtx_count_u16le_fields,SX_COUNT(sxtx_count_u16le_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_length_u16le_fields[] = {
    SX_FIELD("length","uint16",0,2,SX_SIZE),
};
static const sx_layout sxtx_length_u16le = {UINT32_C(0x60340005),"length_u16le",sxtx_length_u16le_fields,SX_COUNT(sxtx_length_u16le_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_order_u16le_fields[] = {
    SX_FIELD("order","uint16",0,2,SX_ID),
};
static const sx_layout sxtx_order_u16le = {UINT32_C(0x60340006),"order_u16le",sxtx_order_u16le_fields,SX_COUNT(sxtx_order_u16le_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_count_u16be_fields[] = {
    SX_FIELD("count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxtx_count_u16be = {UINT32_C(0x60340007),"count_u16be",sxtx_count_u16be_fields,SX_COUNT(sxtx_count_u16be_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_order_u16be_fields[] = {
    SX_FIELD("order","uint16",0,2,SX_ID),
};
static const sx_layout sxtx_order_u16be = {UINT32_C(0x60340009),"order_u16be",sxtx_order_u16be_fields,SX_COUNT(sxtx_order_u16be_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_count_u32le_fields[] = {
    SX_FIELD("count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxtx_count_u32le = {UINT32_C(0x6034000a),"count_u32le",sxtx_count_u32le_fields,SX_COUNT(sxtx_count_u32le_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_length_u32le_fields[] = {
    SX_FIELD("length","uint32",0,4,SX_SIZE),
};
static const sx_layout sxtx_length_u32le = {UINT32_C(0x6034000b),"length_u32le",sxtx_length_u32le_fields,SX_COUNT(sxtx_length_u32le_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_paragraph_u16_fields[] = {
    SX_FIELD("paragraph_index","uint16",0,2,SX_NONE),
};
static const sx_layout sxtx_paragraph_u16 = {UINT32_C(0x60340010),"paragraph_u16",sxtx_paragraph_u16_fields,SX_COUNT(sxtx_paragraph_u16_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_offset_u32_fields[] = {
    SX_FIELD("file_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxtx_offset_u32 = {UINT32_C(0x60340011),"offset_u32",sxtx_offset_u32_fields,SX_COUNT(sxtx_offset_u32_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_pan_u8_fields[] = {
    SX_FIELD("pan","uint8",0,1,SX_NONE),
};
static const sx_layout sxtx_pan_u8 = {UINT32_C(0x60340012),"pan_u8",sxtx_pan_u8_fields,SX_COUNT(sxtx_pan_u8_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_volume_u8_fields[] = {
    SX_FIELD("volume","uint8",0,1,SX_NONE),
};
static const sx_layout sxtx_volume_u8 = {UINT32_C(0x60340013),"volume_u8",sxtx_volume_u8_fields,SX_COUNT(sxtx_volume_u8_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_chunk_le_fields[] = {
    SX_FIELD("id","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxtx_chunk_le = {UINT32_C(0x60340014),"chunk_le",sxtx_chunk_le_fields,SX_COUNT(sxtx_chunk_le_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_chunk_be_fields[] = {
    SX_FIELD("id","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxtx_chunk_be = {UINT32_C(0x60340015),"chunk_be",sxtx_chunk_be_fields,SX_COUNT(sxtx_chunk_be_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_stm_header_fields[] = {
    SX_FIELD("title","char[20]",0,20,SX_STRING),
    SX_FIELD("tracker","char[8]",20,8,SX_SIGNATURE),
    SX_FIELD("eof_marker","uint8",28,1,SX_SIGNATURE),
    SX_FIELD("file_type","uint8",29,1,SX_ID),
    SX_FIELD("version_major","uint8",30,1,SX_ID),
    SX_FIELD("version_minor","uint8",31,1,SX_ID),
    SX_FIELD("tempo","uint8",32,1,SX_NONE),
    SX_FIELD("patterns","uint8",33,1,SX_COUNT_PROP),
    SX_FIELD("global_volume","uint8",34,1,SX_NONE),
    SX_FIELD("reserved","uint8[13]",35,13,SX_RESERVED),
};
static const sx_layout sxtx_stm_header = {UINT32_C(0x60340016),"stm_header",sxtx_stm_header_fields,SX_COUNT(sxtx_stm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_stm_sample_fields[] = {
    SX_FIELD("filename","char[13]",0,13,SX_STRING),
    SX_FIELD("disk_id","uint8",13,1,SX_ID),
    SX_FIELD("data_paragraph","uint16",14,2,SX_NONE),
    SX_FIELD("sample_bytes","uint16",16,2,SX_SIZE),
    SX_FIELD("loop_start","uint16",18,2,SX_OFFSET),
    SX_FIELD("loop_end","uint16",20,2,SX_OFFSET),
    SX_FIELD("volume","uint8",22,1,SX_NONE),
    SX_FIELD("reserved_byte","uint8",23,1,SX_RESERVED),
    SX_FIELD("sample_rate","uint16",24,2,SX_NONE),
    SX_FIELD("reserved_dword","uint32",26,4,SX_RESERVED),
    SX_FIELD("length_paragraphs","uint16",30,2,SX_NONE),
};
static const sx_layout sxtx_stm_sample = {UINT32_C(0x60340017),"stm_sample",sxtx_stm_sample_fields,SX_COUNT(sxtx_stm_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_stm_event_fields[] = {
    SX_FIELD("note","uint8",0,1,SX_ID),
    SX_FIELD("instrument_volume","uint8",1,1,SX_FLAGS),
    SX_FIELD("volume_effect","uint8",2,1,SX_FLAGS),
    SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxtx_stm_event = {UINT32_C(0x60340018),"stm_event",sxtx_stm_event_fields,SX_COUNT(sxtx_stm_event_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_stm_short_event_fields[] = {
    SX_FIELD("note","uint8",0,1,SX_ID),
};
static const sx_layout sxtx_stm_short_event = {UINT32_C(0x60340019),"stm_short_event",sxtx_stm_short_event_fields,SX_COUNT(sxtx_stm_short_event_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_c669_header_fields[] = {
    SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("message","char[108]",2,108,SX_STRING),
    SX_FIELD("samples","uint8",110,1,SX_COUNT_PROP),
    SX_FIELD("patterns","uint8",111,1,SX_COUNT_PROP),
    SX_FIELD("restart_order","uint8",112,1,SX_NONE),
};
static const sx_layout sxtx_c669_header = {UINT32_C(0x6034001a),"c669_header",sxtx_c669_header_fields,SX_COUNT(sxtx_c669_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_c669_speed_fields[] = {
    SX_FIELD("speed","uint8",0,1,SX_NONE),
};
static const sx_layout sxtx_c669_speed = {UINT32_C(0x6034001b),"c669_speed",sxtx_c669_speed_fields,SX_COUNT(sxtx_c669_speed_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_c669_last_row_fields[] = {
    SX_FIELD("last_row","uint8",0,1,SX_NONE),
};
static const sx_layout sxtx_c669_last_row = {UINT32_C(0x6034001c),"c669_last_row",sxtx_c669_last_row_fields,SX_COUNT(sxtx_c669_last_row_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_c669_sample_fields[] = {
    SX_FIELD("filename","char[13]",0,13,SX_STRING),
    SX_FIELD("sample_bytes","uint32",13,4,SX_SIZE),
    SX_FIELD("loop_start","uint32",17,4,SX_OFFSET),
    SX_FIELD("loop_end","uint32",21,4,SX_OFFSET),
};
static const sx_layout sxtx_c669_sample = {UINT32_C(0x6034001d),"c669_sample",sxtx_c669_sample_fields,SX_COUNT(sxtx_c669_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_c669_event_fields[] = {
    SX_FIELD("note_instrument","uint8",0,1,SX_FLAGS),
    SX_FIELD("instrument_volume","uint8",1,1,SX_FLAGS),
    SX_FIELD("effect_parameter","uint8",2,1,SX_FLAGS),
};
static const sx_layout sxtx_c669_event = {UINT32_C(0x6034001e),"c669_event",sxtx_c669_event_fields,SX_COUNT(sxtx_c669_event_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_liq_header_fields[] = {
    SX_FIELD("magic","char[14]",0,14,SX_SIGNATURE),
    SX_FIELD("title","char[30]",14,30,SX_STRING),
    SX_FIELD("author","char[20]",44,20,SX_STRING),
    SX_FIELD("eof_marker","uint8",64,1,SX_SIGNATURE),
    SX_FIELD("tracker","char[20]",65,20,SX_STRING),
    SX_FIELD("version","uint16",85,2,SX_ID),
    SX_FIELD("speed","uint16",87,2,SX_NONE),
    SX_FIELD("bpm","uint16",89,2,SX_NONE),
    SX_FIELD("low_period","uint16",91,2,SX_NONE),
    SX_FIELD("high_period","uint16",93,2,SX_NONE),
    SX_FIELD("channels","uint16",95,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",97,4,SX_FLAGS),
    SX_FIELD("patterns","uint16",101,2,SX_COUNT_PROP),
    SX_FIELD("instruments","uint16",103,2,SX_COUNT_PROP),
    SX_FIELD("orders","uint16",105,2,SX_COUNT_PROP),
    SX_FIELD("header_size","uint16",107,2,SX_SIZE),
};
static const sx_layout sxtx_liq_header = {UINT32_C(0x6034001f),"liq_header",sxtx_liq_header_fields,SX_COUNT(sxtx_liq_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_liq_pattern_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("name","char[30]",4,30,SX_STRING),
    SX_FIELD("rows","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("packed_size","uint32",36,4,SX_SIZE),
    SX_FIELD("reserved","uint32",40,4,SX_RESERVED),
};
static const sx_layout sxtx_liq_pattern = {UINT32_C(0x60340020),"liq_pattern",sxtx_liq_pattern_fields,SX_COUNT(sxtx_liq_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_liq_empty_instrument_fields[] = {
    SX_FIELD("marker","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxtx_liq_empty_instrument = {UINT32_C(0x60340021),"liq_empty_instrument",sxtx_liq_empty_instrument_fields,SX_COUNT(sxtx_liq_empty_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_liq_sample_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_ID),
    SX_FIELD("name","char[30]",6,30,SX_STRING),
    SX_FIELD("editor","char[20]",36,20,SX_STRING),
    SX_FIELD("author","char[20]",56,20,SX_STRING),
    SX_FIELD("hardware_id","uint8",76,1,SX_ID),
    SX_FIELD("sample_bytes","uint32",77,4,SX_SIZE),
    SX_FIELD("loop_start","uint32",81,4,SX_OFFSET),
    SX_FIELD("loop_end","uint32",85,4,SX_OFFSET),
    SX_FIELD("sample_rate","uint32",89,4,SX_NONE),
    SX_FIELD("volume","uint8",93,1,SX_NONE),
    SX_FIELD("flags","uint8",94,1,SX_FLAGS),
    SX_FIELD("pan","uint8",95,1,SX_NONE),
    SX_FIELD("midi_instrument","uint8",96,1,SX_ID),
    SX_FIELD("global_volume","uint8",97,1,SX_NONE),
    SX_FIELD("chord","uint8",98,1,SX_ID),
    SX_FIELD("header_size","uint16",99,2,SX_SIZE),
    SX_FIELD("compression","uint16",101,2,SX_ID),
    SX_FIELD("crc","uint32",103,4,SX_CHECKSUM),
    SX_FIELD("midi_channel","uint8",107,1,SX_ID),
    SX_FIELD("loop_type","int8",108,1,SX_ID),
    SX_FIELD("reserved","uint8[10]",109,10,SX_RESERVED),
    SX_FIELD("filename","char[25]",119,25,SX_STRING),
};
static const sx_layout sxtx_liq_sample = {UINT32_C(0x60340022),"liq_sample",sxtx_liq_sample_fields,SX_COUNT(sxtx_liq_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_dmf_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint8",4,1,SX_ID),
    SX_FIELD("tracker","char[8]",5,8,SX_STRING),
    SX_FIELD("title","char[30]",13,30,SX_STRING),
    SX_FIELD("composer","char[20]",43,20,SX_STRING),
    SX_FIELD("creation_day","uint8",63,1,SX_NONE),
    SX_FIELD("creation_month","uint8",64,1,SX_NONE),
    SX_FIELD("creation_year","uint8",65,1,SX_NONE),
};
static const sx_layout sxtx_dmf_header = {UINT32_C(0x60340023),"dmf_header",sxtx_dmf_header_fields,SX_COUNT(sxtx_dmf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_dmf_sequence_fields[] = {
    SX_FIELD("loop_start_order","uint16",0,2,SX_NONE),
    SX_FIELD("loop_end_order","uint16",2,2,SX_NONE),
};
static const sx_layout sxtx_dmf_sequence = {UINT32_C(0x60340024),"dmf_sequence",sxtx_dmf_sequence_fields,SX_COUNT(sxtx_dmf_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_dmf_patterns_fields[] = {
    SX_FIELD("patterns","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("channels","uint8",2,1,SX_COUNT_PROP),
};
static const sx_layout sxtx_dmf_patterns = {UINT32_C(0x60340025),"dmf_patterns",sxtx_dmf_patterns_fields,SX_COUNT(sxtx_dmf_patterns_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_dmf_pattern_fields[] = {
    SX_FIELD("channels","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("beat","uint8",1,1,SX_FLAGS),
    SX_FIELD("rows","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxtx_dmf_pattern = {UINT32_C(0x60340026),"dmf_pattern",sxtx_dmf_pattern_fields,SX_COUNT(sxtx_dmf_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_dmf_sample_fields[] = {
    SX_FIELD("sample_bytes","uint32",0,4,SX_SIZE),
    SX_FIELD("loop_start","uint32",4,4,SX_OFFSET),
    SX_FIELD("loop_end","uint32",8,4,SX_OFFSET),
    SX_FIELD("sample_rate","uint16",12,2,SX_NONE),
    SX_FIELD("volume","uint8",14,1,SX_NONE),
    SX_FIELD("flags","uint8",15,1,SX_FLAGS),
    SX_FIELD("library_filename","char[8]",16,8,SX_STRING),
    SX_FIELD("filler_or_crc","uint8[6]",24,6,SX_NONE),
};
static const sx_layout sxtx_dmf_sample = {UINT32_C(0x60340027),"dmf_sample",sxtx_dmf_sample_fields,SX_COUNT(sxtx_dmf_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_dmf_end_fields[] = {
    SX_FIELD("marker","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxtx_dmf_end = {UINT32_C(0x60340028),"dmf_end",sxtx_dmf_end_fields,SX_COUNT(sxtx_dmf_end_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_ptm_header_fields[] = {
    SX_FIELD("title","char[28]",0,28,SX_STRING),
    SX_FIELD("eof_marker","uint8",28,1,SX_SIGNATURE),
    SX_FIELD("version_minor","uint8",29,1,SX_ID),
    SX_FIELD("version_major","uint8",30,1,SX_ID),
    SX_FIELD("reserved1","uint8",31,1,SX_RESERVED),
    SX_FIELD("orders","uint16",32,2,SX_COUNT_PROP),
    SX_FIELD("samples","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("patterns","uint16",36,2,SX_COUNT_PROP),
    SX_FIELD("channels","uint16",38,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint16",40,2,SX_FLAGS),
    SX_FIELD("reserved2","uint8[2]",42,2,SX_RESERVED),
    SX_FIELD("magic","char[4]",44,4,SX_SIGNATURE),
    SX_FIELD("reserved3","uint8[16]",48,16,SX_RESERVED),
};
static const sx_layout sxtx_ptm_header = {UINT32_C(0x60340029),"ptm_header",sxtx_ptm_header_fields,SX_COUNT(sxtx_ptm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_ptm_sample_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("filename","char[12]",1,12,SX_STRING),
    SX_FIELD("volume","uint8",13,1,SX_NONE),
    SX_FIELD("sample_rate","uint16",14,2,SX_NONE),
    SX_FIELD("memory_segment","uint16",16,2,SX_NONE),
    SX_FIELD("data_offset","uint32",18,4,SX_OFFSET),
    SX_FIELD("sample_bytes","uint32",22,4,SX_SIZE),
    SX_FIELD("loop_start","uint32",26,4,SX_OFFSET),
    SX_FIELD("loop_end","uint32",30,4,SX_OFFSET),
    SX_FIELD("gus_state","uint8[14]",34,14,SX_NONE),
    SX_FIELD("name","char[28]",48,28,SX_STRING),
    SX_FIELD("magic","char[4]",76,4,SX_SIGNATURE),
};
static const sx_layout sxtx_ptm_sample = {UINT32_C(0x6034002a),"ptm_sample",sxtx_ptm_sample_fields,SX_COUNT(sxtx_ptm_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_ams_header_fields[] = {
    SX_FIELD("magic","char[7]",0,7,SX_SIGNATURE),
    SX_FIELD("version_minor","uint8",7,1,SX_ID),
    SX_FIELD("version_major","uint8",8,1,SX_ID),
    SX_FIELD("channel_config","uint8",9,1,SX_FLAGS),
    SX_FIELD("samples","uint8",10,1,SX_COUNT_PROP),
    SX_FIELD("patterns","uint16",11,2,SX_COUNT_PROP),
    SX_FIELD("orders","uint16",13,2,SX_COUNT_PROP),
    SX_FIELD("midi_channels","uint8",15,1,SX_COUNT_PROP),
    SX_FIELD("extra_size","uint16",16,2,SX_SIZE),
};
static const sx_layout sxtx_ams_header = {UINT32_C(0x6034002b),"ams_header",sxtx_ams_header_fields,SX_COUNT(sxtx_ams_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_ams_sample_fields[] = {
    SX_FIELD("sample_frames","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("loop_start_frame","uint32",4,4,SX_NONE),
    SX_FIELD("loop_end_frame","uint32",8,4,SX_NONE),
    SX_FIELD("pan_finetune","uint8",12,1,SX_FLAGS),
    SX_FIELD("sample_rate","uint16",13,2,SX_NONE),
    SX_FIELD("volume","uint8",15,1,SX_NONE),
    SX_FIELD("flags","uint8",16,1,SX_FLAGS),
};
static const sx_layout sxtx_ams_sample = {UINT32_C(0x6034002c),"ams_sample",sxtx_ams_sample_fields,SX_COUNT(sxtx_ams_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_emod_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("form_size","uint32",4,4,SX_SIZE),
    SX_FIELD("form_type","char[4]",8,4,SX_ID),
};
static const sx_layout sxtx_emod_header = {UINT32_C(0x6034002d),"emod_header",sxtx_emod_header_fields,SX_COUNT(sxtx_emod_header_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_emod_info_fields[] = {
    SX_FIELD("version","uint16",0,2,SX_ID),
    SX_FIELD("title","char[20]",2,20,SX_STRING),
    SX_FIELD("composer","char[20]",22,20,SX_STRING),
    SX_FIELD("bpm","uint8",42,1,SX_NONE),
    SX_FIELD("samples","uint8",43,1,SX_COUNT_PROP),
};
static const sx_layout sxtx_emod_info = {UINT32_C(0x6034002e),"emod_info",sxtx_emod_info_fields,SX_COUNT(sxtx_emod_info_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_emod_sample_fields[] = {
    SX_FIELD("number","uint8",0,1,SX_ID),
    SX_FIELD("volume","uint8",1,1,SX_NONE),
    SX_FIELD("length_words","uint16",2,2,SX_NONE),
    SX_FIELD("name","char[20]",4,20,SX_STRING),
    SX_FIELD("flags","uint8",24,1,SX_FLAGS),
    SX_FIELD("finetune","uint8",25,1,SX_FLAGS),
    SX_FIELD("loop_start_words","uint16",26,2,SX_NONE),
    SX_FIELD("loop_length_words","uint16",28,2,SX_NONE),
    SX_FIELD("memory_pointer","uint32",30,4,SX_ADDRESS),
};
static const sx_layout sxtx_emod_sample = {UINT32_C(0x6034002f),"emod_sample",sxtx_emod_sample_fields,SX_COUNT(sxtx_emod_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_emod_pattern_count_fields[] = {
    SX_FIELD("padding","uint8",0,1,SX_RESERVED),
    SX_FIELD("patterns","uint8",1,1,SX_COUNT_PROP),
};
static const sx_layout sxtx_emod_pattern_count = {UINT32_C(0x60340030),"emod_pattern_count",sxtx_emod_pattern_count_fields,SX_COUNT(sxtx_emod_pattern_count_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_emod_pattern_fields[] = {
    SX_FIELD("pattern_id","uint8",0,1,SX_ID),
    SX_FIELD("rows_minus_one","uint8",1,1,SX_NONE),
    SX_FIELD("name","char[20]",2,20,SX_STRING),
    SX_FIELD("memory_pointer","uint32",22,4,SX_ADDRESS),
};
static const sx_layout sxtx_emod_pattern = {UINT32_C(0x60340031),"emod_pattern",sxtx_emod_pattern_fields,SX_COUNT(sxtx_emod_pattern_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_emod_event_fields[] = {
    SX_FIELD("instrument","uint8",0,1,SX_ID),
    SX_FIELD("note","uint8",1,1,SX_ID),
    SX_FIELD("effect","uint8",2,1,SX_ID),
    SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxtx_emod_event = {UINT32_C(0x60340032),"emod_event",sxtx_emod_event_fields,SX_COUNT(sxtx_emod_event_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_mt2_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("user_id","uint32",4,4,SX_ID),
    SX_FIELD("version","uint16",8,2,SX_ID),
    SX_FIELD("tracker","char[32]",10,32,SX_STRING),
    SX_FIELD("title","char[64]",42,64,SX_STRING),
    SX_FIELD("orders","uint16",106,2,SX_COUNT_PROP),
    SX_FIELD("restart_order","uint16",108,2,SX_NONE),
    SX_FIELD("patterns","uint16",110,2,SX_COUNT_PROP),
    SX_FIELD("channels","uint16",112,2,SX_COUNT_PROP),
    SX_FIELD("samples_per_tick","uint16",114,2,SX_NONE),
    SX_FIELD("ticks_per_line","uint8",116,1,SX_NONE),
    SX_FIELD("lines_per_beat","uint8",117,1,SX_NONE),
    SX_FIELD("flags","uint32",118,4,SX_FLAGS),
    SX_FIELD("instruments","uint16",122,2,SX_COUNT_PROP),
    SX_FIELD("samples","uint16",124,2,SX_COUNT_PROP),
};
static const sx_layout sxtx_mt2_header = {UINT32_C(0x60340033),"mt2_header",sxtx_mt2_header_fields,SX_COUNT(sxtx_mt2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_mt2_drum_size_fields[] = {
    SX_FIELD("drum_data_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxtx_mt2_drum_size = {UINT32_C(0x60340034),"mt2_drum_size",sxtx_mt2_drum_size_fields,SX_COUNT(sxtx_mt2_drum_size_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_mt2_extra_size_fields[] = {
    SX_FIELD("extra_data_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxtx_mt2_extra_size = {UINT32_C(0x60340035),"mt2_extra_size",sxtx_mt2_extra_size_fields,SX_COUNT(sxtx_mt2_extra_size_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_mt2_pattern_fields[] = {
    SX_FIELD("rows","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("data_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxtx_mt2_pattern = {UINT32_C(0x60340036),"mt2_pattern",sxtx_mt2_pattern_fields,SX_COUNT(sxtx_mt2_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_mt2_event_fields[] = {
    SX_FIELD("note","uint8",0,1,SX_ID),
    SX_FIELD("instrument","uint8",1,1,SX_ID),
    SX_FIELD("volume","uint8",2,1,SX_NONE),
    SX_FIELD("pan","uint8",3,1,SX_NONE),
    SX_FIELD("effect","uint8",4,1,SX_ID),
    SX_FIELD("parameter1","uint8",5,1,SX_NONE),
    SX_FIELD("parameter2","uint8",6,1,SX_NONE),
};
static const sx_layout sxtx_mt2_event = {UINT32_C(0x60340037),"mt2_event",sxtx_mt2_event_fields,SX_COUNT(sxtx_mt2_event_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_mt2_slot_fields[] = {
    SX_FIELD("name","char[32]",0,32,SX_STRING),
    SX_FIELD("data_size","uint32",32,4,SX_SIZE),
};
static const sx_layout sxtx_mt2_slot = {UINT32_C(0x60340038),"mt2_slot",sxtx_mt2_slot_fields,SX_COUNT(sxtx_mt2_slot_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_psm_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("container_size","uint32",4,4,SX_SIZE),
    SX_FIELD("container_type","char[4]",8,4,SX_ID),
};
static const sx_layout sxtx_psm_header = {UINT32_C(0x60340039),"psm_header",sxtx_psm_header_fields,SX_COUNT(sxtx_psm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_psm_format_fields[] = {
    SX_FIELD("song_type","char[8]",0,8,SX_ID),
};
static const sx_layout sxtx_psm_format = {UINT32_C(0x6034003a),"psm_format",sxtx_psm_format_fields,SX_COUNT(sxtx_psm_format_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_psm_pattern_fields[] = {
    SX_FIELD("chunk_data_size","uint32",0,4,SX_SIZE),
    SX_FIELD("pattern_id","char[4]",4,4,SX_ID),
    SX_FIELD("rows","uint16",8,2,SX_COUNT_PROP),
};
static const sx_layout sxtx_psm_pattern = {UINT32_C(0x6034003b),"psm_pattern",sxtx_psm_pattern_fields,SX_COUNT(sxtx_psm_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_psm_song_fields[] = {
    SX_FIELD("song_type","char[9]",0,9,SX_ID),
    SX_FIELD("compression","uint8",9,1,SX_ID),
    SX_FIELD("channels","uint8",10,1,SX_COUNT_PROP),
};
static const sx_layout sxtx_psm_song = {UINT32_C(0x6034003c),"psm_song",sxtx_psm_song_fields,SX_COUNT(sxtx_psm_song_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_psm_sample_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("filename","char[8]",1,8,SX_STRING),
    SX_FIELD("sample_id","char[4]",9,4,SX_ID),
    SX_FIELD("name","char[33]",13,33,SX_STRING),
    SX_FIELD("unknown1","uint8[6]",46,6,SX_NONE),
    SX_FIELD("sample_number","uint16",52,2,SX_ID),
    SX_FIELD("sample_bytes","uint32",54,4,SX_SIZE),
    SX_FIELD("loop_start","uint32",58,4,SX_OFFSET),
    SX_FIELD("loop_end","uint32",62,4,SX_OFFSET),
    SX_FIELD("unknown3","uint8",66,1,SX_NONE),
    SX_FIELD("finetune","uint8",67,1,SX_NONE),
    SX_FIELD("volume","uint8",68,1,SX_NONE),
    SX_FIELD("unknown4","uint32",69,4,SX_NONE),
    SX_FIELD("sample_rate","uint32",73,4,SX_NONE),
    SX_FIELD("padding","uint8[19]",77,19,SX_RESERVED),
};
static const sx_layout sxtx_psm_sample = {UINT32_C(0x6034003d),"psm_sample",sxtx_psm_sample_fields,SX_COUNT(sxtx_psm_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_psm_date_fields[] = {
    SX_FIELD("date","char[6]",0,6,SX_STRING),
};
static const sx_layout sxtx_psm_date = {UINT32_C(0x6034003e),"psm_date",sxtx_psm_date_fields,SX_COUNT(sxtx_psm_date_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_psm_opcode_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
};
static const sx_layout sxtx_psm_opcode = {UINT32_C(0x6034003f),"psm_opcode",sxtx_psm_opcode_fields,SX_COUNT(sxtx_psm_opcode_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_psm_play_fields[] = {
    SX_FIELD("pattern_id","char[4]",0,4,SX_ID),
};
static const sx_layout sxtx_psm_play = {UINT32_C(0x60340040),"psm_play",sxtx_psm_play_fields,SX_COUNT(sxtx_psm_play_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_psm_range_fields[] = {
    SX_FIELD("range_operand0","uint16",0,2,SX_NONE),
    SX_FIELD("range_operand1","uint16",2,2,SX_NONE),
};
static const sx_layout sxtx_psm_range = {UINT32_C(0x60340041),"psm_range",sxtx_psm_range_fields,SX_COUNT(sxtx_psm_range_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_psm_jump_loop_fields[] = {
    SX_FIELD("line","uint16",0,2,SX_NONE),
    SX_FIELD("unknown","uint8",2,1,SX_NONE),
};
static const sx_layout sxtx_psm_jump_loop = {UINT32_C(0x60340042),"psm_jump_loop",sxtx_psm_jump_loop_fields,SX_COUNT(sxtx_psm_jump_loop_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_psm_jump_fields[] = {
    SX_FIELD("line","uint16",0,2,SX_NONE),
};
static const sx_layout sxtx_psm_jump = {UINT32_C(0x60340043),"psm_jump",sxtx_psm_jump_fields,SX_COUNT(sxtx_psm_jump_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_psm_channel_value_fields[] = {
    SX_FIELD("channel","uint8",0,1,SX_ID),
    SX_FIELD("value","uint8",1,1,SX_NONE),
};
static const sx_layout sxtx_psm_channel_value = {UINT32_C(0x60340044),"psm_channel_value",sxtx_psm_channel_value_fields,SX_COUNT(sxtx_psm_channel_value_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_psm_value_fields[] = {
    SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sxtx_psm_value = {UINT32_C(0x60340045),"psm_value",sxtx_psm_value_fields,SX_COUNT(sxtx_psm_value_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_psm_sample_map_fields[] = {
    SX_FIELD("sample_map","uint8[6]",0,6,SX_NONE),
};
static const sx_layout sxtx_psm_sample_map = {UINT32_C(0x60340046),"psm_sample_map",sxtx_psm_sample_map_fields,SX_COUNT(sxtx_psm_sample_map_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_psm_panning_fields[] = {
    SX_FIELD("channel","uint8",0,1,SX_ID),
    SX_FIELD("pan","uint8",1,1,SX_NONE),
    SX_FIELD("mode","uint8",2,1,SX_ID),
};
static const sx_layout sxtx_psm_panning = {UINT32_C(0x60340047),"psm_panning",sxtx_psm_panning_fields,SX_COUNT(sxtx_psm_panning_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_dtt_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("title","char[64]",4,64,SX_STRING),
    SX_FIELD("author","char[64]",68,64,SX_STRING),
    SX_FIELD("flags","uint32",132,4,SX_FLAGS),
    SX_FIELD("channels","uint32",136,4,SX_COUNT_PROP),
    SX_FIELD("orders","uint32",140,4,SX_COUNT_PROP),
    SX_FIELD("channel_panning","uint8[8]",144,8,SX_NONE),
    SX_FIELD("speed","uint32",152,4,SX_NONE),
    SX_FIELD("restart_order","uint32",156,4,SX_NONE),
    SX_FIELD("patterns","uint32",160,4,SX_COUNT_PROP),
    SX_FIELD("samples","uint32",164,4,SX_COUNT_PROP),
};
static const sx_layout sxtx_dtt_header = {UINT32_C(0x60340048),"dtt_header",sxtx_dtt_header_fields,SX_COUNT(sxtx_dtt_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_dtt_sample_fields[] = {
    SX_FIELD("base_note","uint8",0,1,SX_ID),
    SX_FIELD("volume","uint8",1,1,SX_NONE),
    SX_FIELD("reserved","uint16",2,2,SX_RESERVED),
    SX_FIELD("tuning_value","uint32",4,4,SX_NONE),
    SX_FIELD("sustain_start","uint32",8,4,SX_OFFSET),
    SX_FIELD("sustain_bytes","uint32",12,4,SX_SIZE),
    SX_FIELD("loop_start","uint32",16,4,SX_OFFSET),
    SX_FIELD("loop_bytes","uint32",20,4,SX_SIZE),
    SX_FIELD("sample_bytes","uint32",24,4,SX_SIZE),
    SX_FIELD("name","char[32]",28,32,SX_STRING),
    SX_FIELD("data_offset","uint32",60,4,SX_OFFSET),
};
static const sx_layout sxtx_dtt_sample = {UINT32_C(0x60340049),"dtt_sample",sxtx_dtt_sample_fields,SX_COUNT(sxtx_dtt_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_dtt_event_fields[] = {
    SX_FIELD("packed_event","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxtx_dtt_event = {UINT32_C(0x6034004a),"dtt_event",sxtx_dtt_event_fields,SX_COUNT(sxtx_dtt_event_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_dtt_event_extra_fields[] = {
    SX_FIELD("packed_parameters","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxtx_dtt_event_extra = {UINT32_C(0x6034004b),"dtt_event_extra",sxtx_dtt_event_extra_fields,SX_COUNT(sxtx_dtt_event_extra_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_stx_header_fields[] = {
    SX_FIELD("title","char[20]",0,20,SX_STRING),
    SX_FIELD("tracker","char[8]",20,8,SX_SIGNATURE),
    SX_FIELD("pattern0_size","uint16",28,2,SX_SIZE),
    SX_FIELD("unknown1","uint16",30,2,SX_NONE),
    SX_FIELD("pattern_table_paragraph","uint16",32,2,SX_NONE),
    SX_FIELD("instrument_table_paragraph","uint16",34,2,SX_NONE),
    SX_FIELD("channel_table_paragraph","uint16",36,2,SX_NONE),
    SX_FIELD("unknown2","uint16",38,2,SX_NONE),
    SX_FIELD("unknown3","uint16",40,2,SX_NONE),
    SX_FIELD("global_volume","uint8",42,1,SX_NONE),
    SX_FIELD("tempo","uint8",43,1,SX_NONE),
    SX_FIELD("unknown4","uint16",44,2,SX_NONE),
    SX_FIELD("unknown5","uint16",46,2,SX_NONE),
    SX_FIELD("patterns","uint16",48,2,SX_COUNT_PROP),
    SX_FIELD("instruments","uint16",50,2,SX_COUNT_PROP),
    SX_FIELD("orders","uint16",52,2,SX_COUNT_PROP),
    SX_FIELD("unknown6","uint16",54,2,SX_NONE),
    SX_FIELD("unknown7","uint16",56,2,SX_NONE),
    SX_FIELD("unknown8","uint16",58,2,SX_NONE),
    SX_FIELD("magic","char[4]",60,4,SX_SIGNATURE),
};
static const sx_layout sxtx_stx_header = {UINT32_C(0x6034004c),"stx_header",sxtx_stx_header_fields,SX_COUNT(sxtx_stx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_stx_sample_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
    SX_FIELD("filename","char[13]",1,13,SX_STRING),
    SX_FIELD("data_paragraph","uint16",14,2,SX_NONE),
    SX_FIELD("sample_bytes","uint32",16,4,SX_SIZE),
    SX_FIELD("loop_start","uint32",20,4,SX_OFFSET),
    SX_FIELD("loop_end","uint32",24,4,SX_OFFSET),
    SX_FIELD("volume","uint8",28,1,SX_NONE),
    SX_FIELD("reserved1","uint8",29,1,SX_RESERVED),
    SX_FIELD("packing","uint8",30,1,SX_ID),
    SX_FIELD("flags","uint8",31,1,SX_FLAGS),
    SX_FIELD("sample_rate","uint16",32,2,SX_NONE),
    SX_FIELD("reserved2","uint16",34,2,SX_RESERVED),
    SX_FIELD("reserved3","uint8[4]",36,4,SX_RESERVED),
    SX_FIELD("gus_pointer","uint16",40,2,SX_NONE),
    SX_FIELD("sb_pointer","uint16",42,2,SX_NONE),
    SX_FIELD("sb_index","uint32",44,4,SX_NONE),
    SX_FIELD("name","char[28]",48,28,SX_STRING),
    SX_FIELD("magic","char[4]",76,4,SX_SIGNATURE),
};
static const sx_layout sxtx_stx_sample = {UINT32_C(0x6034004d),"stx_sample",sxtx_stx_sample_fields,SX_COUNT(sxtx_stx_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_stx_order_fields[] = {
    SX_FIELD("pattern","uint8",0,1,SX_ID),
    SX_FIELD("unknown","uint8[4]",1,4,SX_NONE),
};
static const sx_layout sxtx_stx_order = {UINT32_C(0x6034004e),"stx_order",sxtx_stx_order_fields,SX_COUNT(sxtx_stx_order_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_stx_channels_fields[] = {
    SX_FIELD("channels","uint8[32]",0,32,SX_NONE),
};
static const sx_layout sxtx_stx_channels = {UINT32_C(0x6034004f),"stx_channels",sxtx_stx_channels_fields,SX_COUNT(sxtx_stx_channels_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_dtm_info_fields[] = {
    SX_FIELD("module_type","uint16",0,2,SX_ID),
    SX_FIELD("stereo_mode","uint8",2,1,SX_ID),
    SX_FIELD("bit_depth","uint8",3,1,SX_NONE),
    SX_FIELD("reserved","uint16",4,2,SX_RESERVED),
    SX_FIELD("speed","uint16",6,2,SX_NONE),
    SX_FIELD("tempo","uint16",8,2,SX_NONE),
    SX_FIELD("forced_sample_rate","uint32",10,4,SX_NONE),
};
static const sx_layout sxtx_dtm_info = {UINT32_C(0x60340050),"dtm_info",sxtx_dtm_info_fields,SX_COUNT(sxtx_dtm_info_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_dtm_sequence_fields[] = {
    SX_FIELD("orders","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("restart_order","uint16",2,2,SX_NONE),
    SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
};
static const sx_layout sxtx_dtm_sequence = {UINT32_C(0x60340051),"dtm_sequence",sxtx_dtm_sequence_fields,SX_COUNT(sxtx_dtm_sequence_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_dtm_pattern_info_fields[] = {
    SX_FIELD("channels","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("patterns","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("event_format","uint32",4,4,SX_ID),
};
static const sx_layout sxtx_dtm_pattern_info = {UINT32_C(0x60340052),"dtm_pattern_info",sxtx_dtm_pattern_info_fields,SX_COUNT(sxtx_dtm_pattern_info_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_dtm_sample_fields[] = {
    SX_FIELD("internal_value","uint32",0,4,SX_NONE),
    SX_FIELD("sample_bytes","uint32",4,4,SX_SIZE),
    SX_FIELD("finetune","uint8",8,1,SX_FLAGS),
    SX_FIELD("volume","uint8",9,1,SX_NONE),
    SX_FIELD("loop_start","uint32",10,4,SX_OFFSET),
    SX_FIELD("loop_bytes","uint32",14,4,SX_SIZE),
    SX_FIELD("name","char[22]",18,22,SX_STRING),
    SX_FIELD("stereo","uint8",40,1,SX_FLAGS),
    SX_FIELD("bit_depth","uint8",41,1,SX_NONE),
    SX_FIELD("transpose","uint16",42,2,SX_NONE),
    SX_FIELD("unknown","uint16",44,2,SX_NONE),
    SX_FIELD("sample_rate","uint32",46,4,SX_NONE),
};
static const sx_layout sxtx_dtm_sample = {UINT32_C(0x60340053),"dtm_sample",sxtx_dtm_sample_fields,SX_COUNT(sxtx_dtm_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_dtm_pattern_fields[] = {
    SX_FIELD("sentinel","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("pattern_id","uint16",4,2,SX_ID),
    SX_FIELD("rows","uint16",6,2,SX_COUNT_PROP),
};
static const sx_layout sxtx_dtm_pattern = {UINT32_C(0x60340054),"dtm_pattern",sxtx_dtm_pattern_fields,SX_COUNT(sxtx_dtm_pattern_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_mod_event_fields[] = {
    SX_FIELD("instrument_period_high","uint8",0,1,SX_FLAGS),
    SX_FIELD("period_low","uint8",1,1,SX_NONE),
    SX_FIELD("instrument_effect","uint8",2,1,SX_FLAGS),
    SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxtx_mod_event = {UINT32_C(0x60340055),"mod_event",sxtx_mod_event_fields,SX_COUNT(sxtx_mod_event_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_dtm_event_fields[] = {
    SX_FIELD("note","uint8",0,1,SX_ID),
    SX_FIELD("volume_instrument","uint8",1,1,SX_FLAGS),
    SX_FIELD("instrument_effect","uint8",2,1,SX_FLAGS),
    SX_FIELD("parameter","uint8",3,1,SX_NONE),
};
static const sx_layout sxtx_dtm_event = {UINT32_C(0x60340056),"dtm_event",sxtx_dtm_event_fields,SX_COUNT(sxtx_dtm_event_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_funk_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("tracker_info","uint8[4]",4,4,SX_NONE),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("format_id","char[4]",12,4,SX_ID),
    SX_FIELD("restart_order","uint8",16,1,SX_NONE),
};
static const sx_layout sxtx_funk_header = {UINT32_C(0x60340057),"funk_header",sxtx_funk_header_fields,SX_COUNT(sxtx_funk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_funk_sample_fields[] = {
    SX_FIELD("name","char[19]",0,19,SX_STRING),
    SX_FIELD("loop_start","uint32",19,4,SX_OFFSET),
    SX_FIELD("sample_bytes","uint32",23,4,SX_SIZE),
    SX_FIELD("volume","uint8",27,1,SX_NONE),
    SX_FIELD("pan","uint8",28,1,SX_NONE),
    SX_FIELD("shifter","uint8",29,1,SX_FLAGS),
    SX_FIELD("waveform","uint8",30,1,SX_FLAGS),
    SX_FIELD("retrigger","uint8",31,1,SX_FLAGS),
};
static const sx_layout sxtx_funk_sample = {UINT32_C(0x60340058),"funk_sample",sxtx_funk_sample_fields,SX_COUNT(sxtx_funk_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_funk_event_fields[] = {
    SX_FIELD("note_instrument","uint8",0,1,SX_FLAGS),
    SX_FIELD("instrument_effect","uint8",1,1,SX_FLAGS),
    SX_FIELD("parameter","uint8",2,1,SX_NONE),
};
static const sx_layout sxtx_funk_event = {UINT32_C(0x60340059),"funk_event",sxtx_funk_event_fields,SX_COUNT(sxtx_funk_event_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_musx_name_fields[] = {
    SX_FIELD("name","char[32]",0,32,SX_STRING),
};
static const sx_layout sxtx_musx_name = {UINT32_C(0x6034005a),"musx_name",sxtx_musx_name_fields,SX_COUNT(sxtx_musx_name_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_musx_tracker_fields[] = {
    SX_FIELD("year_low_bcd","uint8",0,1,SX_NONE),
    SX_FIELD("year_high_bcd","uint8",1,1,SX_NONE),
    SX_FIELD("month_bcd","uint8",2,1,SX_NONE),
    SX_FIELD("day_bcd","uint8",3,1,SX_NONE),
};
static const sx_layout sxtx_musx_tracker = {UINT32_C(0x6034005b),"musx_tracker",sxtx_musx_tracker_fields,SX_COUNT(sxtx_musx_tracker_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_musx_volume_fields[] = {
    SX_FIELD("volume","uint32",0,4,SX_NONE),
};
static const sx_layout sxtx_musx_volume = {UINT32_C(0x6034005c),"musx_volume",sxtx_musx_volume_fields,SX_COUNT(sxtx_musx_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_musx_loop_offset_fields[] = {
    SX_FIELD("loop_start","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxtx_musx_loop_offset = {UINT32_C(0x6034005d),"musx_loop_offset",sxtx_musx_loop_offset_fields,SX_COUNT(sxtx_musx_loop_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_musx_event_fields[] = {
    SX_FIELD("parameter","uint8",0,1,SX_NONE),
    SX_FIELD("effect","uint8",1,1,SX_ID),
    SX_FIELD("instrument","uint8",2,1,SX_ID),
    SX_FIELD("note","uint8",3,1,SX_ID),
};
static const sx_layout sxtx_musx_event = {UINT32_C(0x6034005e),"musx_event",sxtx_musx_event_fields,SX_COUNT(sxtx_musx_event_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_coco_header_fields[] = {
    SX_FIELD("channel_flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("title","char[20]",1,20,SX_STRING),
    SX_FIELD("instruments","uint8",21,1,SX_COUNT_PROP),
    SX_FIELD("orders","uint8",22,1,SX_COUNT_PROP),
    SX_FIELD("patterns","uint8",23,1,SX_COUNT_PROP),
    SX_FIELD("orders_offset","uint32",24,4,SX_OFFSET),
    SX_FIELD("patterns_offset","uint32",28,4,SX_OFFSET),
};
static const sx_layout sxtx_coco_header = {UINT32_C(0x6034005f),"coco_header",sxtx_coco_header_fields,SX_COUNT(sxtx_coco_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_coco_sample_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("sample_bytes","uint32",4,4,SX_SIZE),
    SX_FIELD("inverse_volume","uint32",8,4,SX_NONE),
    SX_FIELD("loop_start","uint32",12,4,SX_OFFSET),
    SX_FIELD("loop_length_plus_one","uint32",16,4,SX_SIZE),
    SX_FIELD("name","char[11]",20,11,SX_STRING),
    SX_FIELD("unused","uint8",31,1,SX_RESERVED),
};
static const sx_layout sxtx_coco_sample = {UINT32_C(0x60340060),"coco_sample",sxtx_coco_sample_fields,SX_COUNT(sxtx_coco_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_rtm_object_fields[] = {
    SX_FIELD("object_type","char[4]",0,4,SX_ID),
    SX_FIELD("space","uint8",4,1,SX_SIGNATURE),
    SX_FIELD("name","char[32]",5,32,SX_STRING),
    SX_FIELD("eof_marker","uint8",37,1,SX_SIGNATURE),
    SX_FIELD("version","uint16",38,2,SX_ID),
    SX_FIELD("object_size","uint16",40,2,SX_SIZE),
};
static const sx_layout sxtx_rtm_object = {UINT32_C(0x60340061),"rtm_object",sxtx_rtm_object_fields,SX_COUNT(sxtx_rtm_object_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_rtm_song_fields[] = {
    SX_FIELD("software","char[20]",0,20,SX_STRING),
    SX_FIELD("composer","char[32]",20,32,SX_STRING),
    SX_FIELD("flags","uint16",52,2,SX_FLAGS),
    SX_FIELD("channels","uint8",54,1,SX_COUNT_PROP),
    SX_FIELD("instruments","uint8",55,1,SX_COUNT_PROP),
    SX_FIELD("orders","uint16",56,2,SX_COUNT_PROP),
    SX_FIELD("patterns","uint16",58,2,SX_COUNT_PROP),
    SX_FIELD("speed","uint8",60,1,SX_NONE),
    SX_FIELD("tempo","uint8",61,1,SX_NONE),
};
static const sx_layout sxtx_rtm_song = {UINT32_C(0x60340062),"rtm_song",sxtx_rtm_song_fields,SX_COUNT(sxtx_rtm_song_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_rtm_pan_fields[] = {
    SX_FIELD("panning","int8",0,1,SX_NONE),
};
static const sx_layout sxtx_rtm_pan = {UINT32_C(0x60340063),"rtm_pan",sxtx_rtm_pan_fields,SX_COUNT(sxtx_rtm_pan_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_rtm_extra_size_fields[] = {
    SX_FIELD("extra_data_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxtx_rtm_extra_size = {UINT32_C(0x60340064),"rtm_extra_size",sxtx_rtm_extra_size_fields,SX_COUNT(sxtx_rtm_extra_size_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_rtm_original_name_fields[] = {
    SX_FIELD("original_name","char[32]",0,32,SX_STRING),
};
static const sx_layout sxtx_rtm_original_name = {UINT32_C(0x60340065),"rtm_original_name",sxtx_rtm_original_name_fields,SX_COUNT(sxtx_rtm_original_name_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_rtm_pattern_fields[] = {
    SX_FIELD("flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("tracks","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("rows","uint16",3,2,SX_COUNT_PROP),
    SX_FIELD("packed_size","uint32",5,4,SX_SIZE),
};
static const sx_layout sxtx_rtm_pattern = {UINT32_C(0x60340066),"rtm_pattern",sxtx_rtm_pattern_fields,SX_COUNT(sxtx_rtm_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_rtm_instrument_fields[] = {
    SX_FIELD("samples","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("flags","uint16",1,2,SX_FLAGS),
};
static const sx_layout sxtx_rtm_instrument = {UINT32_C(0x60340067),"rtm_instrument",sxtx_rtm_instrument_fields,SX_COUNT(sxtx_rtm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_rtm_keymap_fields[] = {
    SX_FIELD("sample_index","uint8",0,1,SX_ID),
};
static const sx_layout sxtx_rtm_keymap = {UINT32_C(0x60340068),"rtm_keymap",sxtx_rtm_keymap_fields,SX_COUNT(sxtx_rtm_keymap_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_rtm_envelope_point_fields[] = {
    SX_FIELD("tick","uint32",0,4,SX_NONE),
    SX_FIELD("value","int32",4,4,SX_NONE),
};
static const sx_layout sxtx_rtm_envelope_point = {UINT32_C(0x60340069),"rtm_envelope_point",sxtx_rtm_envelope_point_fields,SX_COUNT(sxtx_rtm_envelope_point_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_rtm_envelope_tail_fields[] = {
    SX_FIELD("sustain_point","uint8",0,1,SX_NONE),
    SX_FIELD("loop_start_point","uint8",1,1,SX_NONE),
    SX_FIELD("loop_end_point","uint8",2,1,SX_NONE),
    SX_FIELD("flags","uint16",3,2,SX_FLAGS),
};
static const sx_layout sxtx_rtm_envelope_tail = {UINT32_C(0x6034006a),"rtm_envelope_tail",sxtx_rtm_envelope_tail_fields,SX_COUNT(sxtx_rtm_envelope_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_rtm_instrument_tail_fields[] = {
    SX_FIELD("vibrato_type","uint8",0,1,SX_ID),
    SX_FIELD("vibrato_sweep","uint8",1,1,SX_NONE),
    SX_FIELD("vibrato_depth","uint8",2,1,SX_NONE),
    SX_FIELD("vibrato_rate","uint8",3,1,SX_NONE),
    SX_FIELD("fadeout","uint16",4,2,SX_NONE),
    SX_FIELD("midi_port","uint8",6,1,SX_ID),
    SX_FIELD("midi_channel","uint8",7,1,SX_ID),
    SX_FIELD("midi_program","uint8",8,1,SX_ID),
    SX_FIELD("midi_enabled","uint8",9,1,SX_FLAGS),
};
static const sx_layout sxtx_rtm_instrument_tail = {UINT32_C(0x6034006b),"rtm_instrument_tail",sxtx_rtm_instrument_tail_fields,SX_COUNT(sxtx_rtm_instrument_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_rtm_instrument_v112_fields[] = {
    SX_FIELD("midi_transpose","int8",0,1,SX_NONE),
    SX_FIELD("midi_bender_range","uint8",1,1,SX_NONE),
    SX_FIELD("midi_base_volume","uint8",2,1,SX_NONE),
    SX_FIELD("midi_use_velocity","uint8",3,1,SX_FLAGS),
};
static const sx_layout sxtx_rtm_instrument_v112 = {UINT32_C(0x6034006c),"rtm_instrument_v112",sxtx_rtm_instrument_v112_fields,SX_COUNT(sxtx_rtm_instrument_v112_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_rtm_sample_fields[] = {
    SX_FIELD("flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("base_volume","uint8",2,1,SX_NONE),
    SX_FIELD("default_volume","uint8",3,1,SX_NONE),
    SX_FIELD("sample_bytes","uint32",4,4,SX_SIZE),
    SX_FIELD("loop_type","uint8",8,1,SX_ID),
    SX_FIELD("reserved","uint8[3]",9,3,SX_RESERVED),
    SX_FIELD("loop_start","uint32",12,4,SX_OFFSET),
    SX_FIELD("loop_end","uint32",16,4,SX_OFFSET),
    SX_FIELD("sample_rate","uint32",20,4,SX_NONE),
    SX_FIELD("base_note","uint8",24,1,SX_ID),
    SX_FIELD("panning","int8",25,1,SX_NONE),
};
static const sx_layout sxtx_rtm_sample = {UINT32_C(0x6034006d),"rtm_sample",sxtx_rtm_sample_fields,SX_COUNT(sxtx_rtm_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_mgt_header_fields[] = {
    SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("version","uint8",3,1,SX_ID),
    SX_FIELD("marker","uint8[4]",4,4,SX_SIGNATURE),
    SX_FIELD("channels","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("songs","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("orders","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("patterns","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("tracks","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("instruments","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("reserved1","uint16",20,2,SX_RESERVED),
    SX_FIELD("reserved2","uint32",22,4,SX_RESERVED),
    SX_FIELD("song_offset","uint32",26,4,SX_OFFSET),
    SX_FIELD("sequence_offset","uint32",30,4,SX_OFFSET),
    SX_FIELD("instrument_offset","uint32",34,4,SX_OFFSET),
    SX_FIELD("pattern_offset","uint32",38,4,SX_OFFSET),
    SX_FIELD("track_table_offset","uint32",42,4,SX_OFFSET),
    SX_FIELD("sample_offset","uint32",46,4,SX_OFFSET),
    SX_FIELD("sample_data_size","uint32",50,4,SX_SIZE),
    SX_FIELD("unpacked_track_size","uint32",54,4,SX_SIZE),
};
static const sx_layout sxtx_mgt_header = {UINT32_C(0x6034006e),"mgt_header",sxtx_mgt_header_fields,SX_COUNT(sxtx_mgt_header_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_mgt_song_fields[] = {
    SX_FIELD("title","char[32]",0,32,SX_STRING),
    SX_FIELD("sequence_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("orders","uint16",36,2,SX_COUNT_PROP),
    SX_FIELD("restart_order","uint16",38,2,SX_NONE),
    SX_FIELD("bpm","uint8",40,1,SX_NONE),
    SX_FIELD("speed","uint8",41,1,SX_NONE),
    SX_FIELD("global_volume","uint16",42,2,SX_NONE),
    SX_FIELD("master_left","uint8",44,1,SX_NONE),
    SX_FIELD("master_right","uint8",45,1,SX_NONE),
};
static const sx_layout sxtx_mgt_song = {UINT32_C(0x6034006f),"mgt_song",sxtx_mgt_song_fields,SX_COUNT(sxtx_mgt_song_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_mgt_pan_fields[] = {
    SX_FIELD("panning","uint16",0,2,SX_NONE),
};
static const sx_layout sxtx_mgt_pan = {UINT32_C(0x60340070),"mgt_pan",sxtx_mgt_pan_fields,SX_COUNT(sxtx_mgt_pan_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_mgt_offset_fields[] = {
    SX_FIELD("file_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxtx_mgt_offset = {UINT32_C(0x60340071),"mgt_offset",sxtx_mgt_offset_fields,SX_COUNT(sxtx_mgt_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_mgt_sample_fields[] = {
    SX_FIELD("name","char[32]",0,32,SX_STRING),
    SX_FIELD("data_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("sample_bytes","uint32",36,4,SX_SIZE),
    SX_FIELD("loop_start","uint32",40,4,SX_OFFSET),
    SX_FIELD("loop_bytes","uint32",44,4,SX_SIZE),
    SX_FIELD("unknown1","uint32",48,4,SX_NONE),
    SX_FIELD("unknown2","uint32",52,4,SX_NONE),
    SX_FIELD("sample_rate","uint32",56,4,SX_NONE),
    SX_FIELD("volume","uint16",60,2,SX_NONE),
    SX_FIELD("volume_left","uint8",62,1,SX_NONE),
    SX_FIELD("volume_right","uint8",63,1,SX_NONE),
    SX_FIELD("flags","uint8",64,1,SX_FLAGS),
    SX_FIELD("finetune","uint8",65,1,SX_NONE),
    SX_FIELD("unused","uint8",66,1,SX_RESERVED),
    SX_FIELD("unknown3","uint8",67,1,SX_NONE),
    SX_FIELD("unknown4","uint8",68,1,SX_NONE),
    SX_FIELD("unknown5","uint8",69,1,SX_NONE),
    SX_FIELD("unknown6","uint16",70,2,SX_NONE),
    SX_FIELD("unknown7","uint32",72,4,SX_NONE),
    SX_FIELD("unknown8","uint32",76,4,SX_NONE),
};
static const sx_layout sxtx_mgt_sample = {UINT32_C(0x60340072),"mgt_sample",sxtx_mgt_sample_fields,SX_COUNT(sxtx_mgt_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_abk_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("bank_type","uint16",4,2,SX_ID),
    SX_FIELD("memory_type","uint16",6,2,SX_FLAGS),
    SX_FIELD("bank_size_flags","uint32",8,4,SX_FLAGS),
    SX_FIELD("bank_name","char[8]",12,8,SX_STRING),
    SX_FIELD("instruments_offset","uint32",20,4,SX_OFFSET),
    SX_FIELD("songs_offset","uint32",24,4,SX_OFFSET),
    SX_FIELD("patterns_offset","uint32",28,4,SX_OFFSET),
};
static const sx_layout sxtx_abk_header = {UINT32_C(0x60340073),"abk_header",sxtx_abk_header_fields,SX_COUNT(sxtx_abk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_abk_sample_fields[] = {
    SX_FIELD("sample_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("repeat_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("length_words","uint16",8,2,SX_NONE),
    SX_FIELD("repeat_end_words","uint16",10,2,SX_NONE),
    SX_FIELD("volume","uint16",12,2,SX_NONE),
    SX_FIELD("extended_length_words","uint16",14,2,SX_NONE),
    SX_FIELD("name","char[16]",16,16,SX_STRING),
};
static const sx_layout sxtx_abk_sample = {UINT32_C(0x60340074),"abk_sample",sxtx_abk_sample_fields,SX_COUNT(sxtx_abk_sample_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_abk_song_index_fields[] = {
    SX_FIELD("songs","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("song_offset","uint32",2,4,SX_OFFSET),
};
static const sx_layout sxtx_abk_song_index = {UINT32_C(0x60340075),"abk_song_index",sxtx_abk_song_index_fields,SX_COUNT(sxtx_abk_song_index_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_abk_song_fields[] = {
    SX_FIELD("playlist0","uint16",0,2,SX_OFFSET),
    SX_FIELD("playlist1","uint16",2,2,SX_OFFSET),
    SX_FIELD("playlist2","uint16",4,2,SX_OFFSET),
    SX_FIELD("playlist3","uint16",6,2,SX_OFFSET),
    SX_FIELD("tempo","uint16",8,2,SX_NONE),
    SX_FIELD("unused","uint16",10,2,SX_NONE),
    SX_FIELD("title","char[16]",12,16,SX_STRING),
};
static const sx_layout sxtx_abk_song = {UINT32_C(0x60340076),"abk_song",sxtx_abk_song_fields,SX_COUNT(sxtx_abk_song_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_abk_pattern_offset_fields[] = {
    SX_FIELD("track_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxtx_abk_pattern_offset = {UINT32_C(0x60340077),"abk_pattern_offset",sxtx_abk_pattern_offset_fields,SX_COUNT(sxtx_abk_pattern_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxtx_mad_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxtx_mad_header = {UINT32_C(0x60340078),"mad_header",sxtx_mad_header_fields,SX_COUNT(sxtx_mad_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_mad_instrument_fields[] = {
    SX_FIELD("name","char[8]",0,8,SX_STRING),
    SX_FIELD("opl_parameters","uint8[12]",8,12,SX_NONE),
};
static const sx_layout sxtx_mad_instrument = {UINT32_C(0x60340079),"mad_instrument",sxtx_mad_instrument_fields,SX_COUNT(sxtx_mad_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_mad_song_fields[] = {
    SX_FIELD("reserved","uint8",0,1,SX_RESERVED),
    SX_FIELD("orders","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("patterns","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("timer","uint8",3,1,SX_NONE),
};
static const sx_layout sxtx_mad_song = {UINT32_C(0x6034007a),"mad_song",sxtx_mad_song_fields,SX_COUNT(sxtx_mad_song_fields),SX_LE};
static const xx_data_struct_field_desc sxtx_mad_event_fields[] = {
    SX_FIELD("note","uint8",0,1,SX_ID),
};
static const sx_layout sxtx_mad_event = {UINT32_C(0x6034007b),"mad_event",sxtx_mad_event_fields,SX_COUNT(sxtx_mad_event_fields),SX_LE};
static const sx_layout *const sx_trackerextra_layouts[] = {
    &sxtx_count_u8le,
    &sxtx_length_u8le,
    &sxtx_order_u8le,
    &sxtx_count_u16le,
    &sxtx_length_u16le,
    &sxtx_order_u16le,
    &sxtx_count_u16be,
    &sxtx_order_u16be,
    &sxtx_count_u32le,
    &sxtx_length_u32le,
    &sxtx_paragraph_u16,
    &sxtx_offset_u32,
    &sxtx_pan_u8,
    &sxtx_volume_u8,
    &sxtx_chunk_le,
    &sxtx_chunk_be,
    &sxtx_stm_header,
    &sxtx_stm_sample,
    &sxtx_stm_event,
    &sxtx_stm_short_event,
    &sxtx_c669_header,
    &sxtx_c669_speed,
    &sxtx_c669_last_row,
    &sxtx_c669_sample,
    &sxtx_c669_event,
    &sxtx_liq_header,
    &sxtx_liq_pattern,
    &sxtx_liq_empty_instrument,
    &sxtx_liq_sample,
    &sxtx_dmf_header,
    &sxtx_dmf_sequence,
    &sxtx_dmf_patterns,
    &sxtx_dmf_pattern,
    &sxtx_dmf_sample,
    &sxtx_dmf_end,
    &sxtx_ptm_header,
    &sxtx_ptm_sample,
    &sxtx_ams_header,
    &sxtx_ams_sample,
    &sxtx_emod_header,
    &sxtx_emod_info,
    &sxtx_emod_sample,
    &sxtx_emod_pattern_count,
    &sxtx_emod_pattern,
    &sxtx_emod_event,
    &sxtx_mt2_header,
    &sxtx_mt2_drum_size,
    &sxtx_mt2_extra_size,
    &sxtx_mt2_pattern,
    &sxtx_mt2_event,
    &sxtx_mt2_slot,
    &sxtx_psm_header,
    &sxtx_psm_format,
    &sxtx_psm_pattern,
    &sxtx_psm_song,
    &sxtx_psm_sample,
    &sxtx_psm_date,
    &sxtx_psm_opcode,
    &sxtx_psm_play,
    &sxtx_psm_range,
    &sxtx_psm_jump_loop,
    &sxtx_psm_jump,
    &sxtx_psm_channel_value,
    &sxtx_psm_value,
    &sxtx_psm_sample_map,
    &sxtx_psm_panning,
    &sxtx_dtt_header,
    &sxtx_dtt_sample,
    &sxtx_dtt_event,
    &sxtx_dtt_event_extra,
    &sxtx_stx_header,
    &sxtx_stx_sample,
    &sxtx_stx_order,
    &sxtx_stx_channels,
    &sxtx_dtm_info,
    &sxtx_dtm_sequence,
    &sxtx_dtm_pattern_info,
    &sxtx_dtm_sample,
    &sxtx_dtm_pattern,
    &sxtx_mod_event,
    &sxtx_dtm_event,
    &sxtx_funk_header,
    &sxtx_funk_sample,
    &sxtx_funk_event,
    &sxtx_musx_name,
    &sxtx_musx_tracker,
    &sxtx_musx_volume,
    &sxtx_musx_loop_offset,
    &sxtx_musx_event,
    &sxtx_coco_header,
    &sxtx_coco_sample,
    &sxtx_rtm_object,
    &sxtx_rtm_song,
    &sxtx_rtm_pan,
    &sxtx_rtm_extra_size,
    &sxtx_rtm_original_name,
    &sxtx_rtm_pattern,
    &sxtx_rtm_instrument,
    &sxtx_rtm_keymap,
    &sxtx_rtm_envelope_point,
    &sxtx_rtm_envelope_tail,
    &sxtx_rtm_instrument_tail,
    &sxtx_rtm_instrument_v112,
    &sxtx_rtm_sample,
    &sxtx_mgt_header,
    &sxtx_mgt_song,
    &sxtx_mgt_pan,
    &sxtx_mgt_offset,
    &sxtx_mgt_sample,
    &sxtx_abk_header,
    &sxtx_abk_sample,
    &sxtx_abk_song_index,
    &sxtx_abk_song,
    &sxtx_abk_pattern_offset,
    &sxtx_mad_header,
    &sxtx_mad_instrument,
    &sxtx_mad_song,
    &sxtx_mad_event,
};
static bool sx_trackerextra_static_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60340000U||id>=0x60350000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x60340010U:
        if(!xx_rt_wcscmp(r->name,L"paragraph_index"))text=L"16-byte paragraph units; file byte offset is this value multiplied by16.";
        break;
    case 0x60340012U:
        if(!xx_rt_wcscmp(r->name,L"pan"))text=L"Native tracker panning units; not a byte offset.";
        break;
    case 0x60340016U:
        if(!xx_rt_wcscmp(r->name,L"file_type"))text=L"1=song,2=module; native reader accepts modules.";
        break;
    case 0x60340017U:
        if(!xx_rt_wcscmp(r->name,L"data_paragraph"))text=L"16-byte paragraph units; file byte offset=value*16.";
        if(!xx_rt_wcscmp(r->name,L"loop_start"))text=L"Byte position within the sample.";
        if(!xx_rt_wcscmp(r->name,L"loop_end"))text=L"Byte position within the sample;65535 disables looping.";
        if(!xx_rt_wcscmp(r->name,L"length_paragraphs"))text=L"Length measured in16-byte paragraphs.";
        break;
    case 0x60340018U:
        if(!xx_rt_wcscmp(r->name,L"instrument_volume"))text=L"Bits3..7:instrument;bits0..2:low volume bits.";
        if(!xx_rt_wcscmp(r->name,L"volume_effect"))text=L"High nibble:remaining volume bits;low nibble:effect.";
        break;
    case 0x60340019U:
        if(!xx_rt_wcscmp(r->name,L"note"))text=L"251/252=empty,253=note cut; compact one-byte event.";
        break;
    case 0x6034001cU:
        if(!xx_rt_wcscmp(r->name,L"last_row"))text=L"Last played row index; not a byte offset.";
        break;
    case 0x6034001dU:
        if(!xx_rt_wcscmp(r->name,L"loop_end"))text=L"Values>=0xfffff disable looping.";
        break;
    case 0x6034001eU:
        if(!xx_rt_wcscmp(r->name,L"note_instrument"))text=L"Bits2..7:note;bits0..1:high sample bits.";
        if(!xx_rt_wcscmp(r->name,L"instrument_volume"))text=L"High nibble:low sample bits;low nibble:volume.";
        if(!xx_rt_wcscmp(r->name,L"effect_parameter"))text=L"High nibble:effect;low nibble:parameter.";
        break;
    case 0x6034001fU:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit0:cut notes at period limit;bit1:Scream Tracker compatibility.";
        break;
    case 0x60340022U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit0:16-bit PCM;bit1:stereo;bit2:signed PCM.";
        if(!xx_rt_wcscmp(r->name,L"loop_type"))text=L"0 or-1:normal;1:ping pong.";
        break;
    case 0x60340026U:
        if(!xx_rt_wcscmp(r->name,L"beat"))text=L"High nibble:rows per beat;low nibble:reserved.";
        break;
    case 0x60340027U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit0:loop;bit1:16-bit;bits2..3:compression.";
        break;
    case 0x6034002aU:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bits0..1:sample type,1=PCM;bit2:loop;bit3:ping pong;bit4:16-bit.";
        if(!xx_rt_wcscmp(r->name,L"memory_segment"))text=L"Internal player segment; not a file offset.";
        break;
    case 0x6034002bU:
        if(!xx_rt_wcscmp(r->name,L"channel_config"))text=L"Low5bits store channel count minus1.";
        break;
    case 0x6034002cU:
        if(!xx_rt_wcscmp(r->name,L"pan_finetune"))text=L"High nibble:panning;low nibble:signed finetune.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit2:legacy16-bit;bit7:16-bit;bits0..1:packed method(native stored subset).";
        break;
    case 0x6034002fU:
        if(!xx_rt_wcscmp(r->name,L"length_words"))text=L"16-bit word count;sample byte size=value*2.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit0:loop.";
        if(!xx_rt_wcscmp(r->name,L"finetune"))text=L"Low nibble encodes signed finetune.";
        if(!xx_rt_wcscmp(r->name,L"memory_pointer"))text=L"Stored player pointer; physical samples are in the8SMP chunk.";
        break;
    case 0x60340031U:
        if(!xx_rt_wcscmp(r->name,L"memory_pointer"))text=L"Stored player pointer; physical patterns are in the PATT chunk.";
        break;
    case 0x60340033U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit0:packed patterns;bit1:automation;bit3:drums automation;bit4:master automation.";
        break;
    case 0x60340039U:
        if(!xx_rt_wcscmp(r->name,L"container_size"))text=L"File length minus12.";
        break;
    case 0x6034003dU:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit7:loop enabled.";
        if(!xx_rt_wcscmp(r->name,L"loop_end"))text=L"0xffffffff denotes end of sample.";
        break;
    case 0x60340041U:
        if(!xx_rt_wcscmp(r->name,L"range_operand0"))text=L"Native reader stores two16-bit operands for this unfinished playlist command.";
        break;
    case 0x60340047U:
        if(!xx_rt_wcscmp(r->name,L"mode"))text=L"0=normal,2=surround,4=center.";
        break;
    case 0x60340049U:
        if(!xx_rt_wcscmp(r->name,L"tuning_value"))text=L"Period/tuning field; units are not established by the reference reader.";
        break;
    case 0x6034004aU:
        if(!xx_rt_wcscmp(r->name,L"packed_event"))text=L"Bits0..5:instrument,6..11:note,12..16:effect;bits17..21 select an extra parameter word.";
        break;
    case 0x6034004bU:
        if(!xx_rt_wcscmp(r->name,L"packed_parameters"))text=L"Low byte:first effect parameter;next byte:second parameter.";
        break;
    case 0x6034004cU:
        if(!xx_rt_wcscmp(r->name,L"pattern_table_paragraph"))text=L"File byte position=value*16.";
        if(!xx_rt_wcscmp(r->name,L"instrument_table_paragraph"))text=L"File byte position=value*16.";
        if(!xx_rt_wcscmp(r->name,L"channel_table_paragraph"))text=L"File byte position=value*16.";
        break;
    case 0x6034004dU:
        if(!xx_rt_wcscmp(r->name,L"data_paragraph"))text=L"File byte position=value*16.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit0:loop;other sample modes unsupported by native reader.";
        break;
    case 0x60340052U:
        if(!xx_rt_wcscmp(r->name,L"event_format"))text=L"0=ProTracker events;0x322e3034=Digital Tracker2.04 events.";
        break;
    case 0x60340053U:
        if(!xx_rt_wcscmp(r->name,L"finetune"))text=L"Low nibble encodes signed finetune-8..7.";
        break;
    case 0x60340056U:
        if(!xx_rt_wcscmp(r->name,L"volume_instrument"))text=L"Bits2..7:volume;bits0..1:high instrument bits.";
        if(!xx_rt_wcscmp(r->name,L"instrument_effect"))text=L"High nibble:low instrument bits;low nibble:effect.";
        break;
    case 0x60340058U:
        if(!xx_rt_wcscmp(r->name,L"loop_start"))text=L"0xffffffff disables looping.";
        break;
    case 0x6034005bU:
        if(!xx_rt_wcscmp(r->name,L"year_low_bcd"))text=L"Packed BCD:year modulo100.";
        if(!xx_rt_wcscmp(r->name,L"year_high_bcd"))text=L"Packed BCD:century.";
        if(!xx_rt_wcscmp(r->name,L"month_bcd"))text=L"Packed BCD month.";
        if(!xx_rt_wcscmp(r->name,L"day_bcd"))text=L"Packed BCD day.";
        break;
    case 0x6034005fU:
        if(!xx_rt_wcscmp(r->name,L"channel_flags"))text=L"Bit7:format marker;low6bits:channel count.";
        break;
    case 0x60340062U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit0:linear slides;bit1:track names.";
        break;
    case 0x60340067U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit0:default pan;bit1:mute samples.";
        break;
    case 0x6034006aU:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit0:enabled;bit1:sustain;bit2:loop.";
        break;
    case 0x6034006dU:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit1:16-bit;bit2:delta coded.";
        if(!xx_rt_wcscmp(r->name,L"loop_type"))text=L"0=none,1=forward,2=ping pong.";
        break;
    case 0x60340072U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit0:loop;bit1:bidirectional.";
        break;
    case 0x60340073U:
        if(!xx_rt_wcscmp(r->name,L"bank_size_flags"))text=L"Low31bits:bank size excluding12-byte prefix;high bit:flag.";
        if(!xx_rt_wcscmp(r->name,L"instruments_offset"))text=L"Relative to byte20 of this file.";
        if(!xx_rt_wcscmp(r->name,L"songs_offset"))text=L"Relative to byte20 of this file.";
        if(!xx_rt_wcscmp(r->name,L"patterns_offset"))text=L"Relative to byte20 of this file.";
        break;
    case 0x60340074U:
        if(!xx_rt_wcscmp(r->name,L"sample_offset"))text=L"Relative to instrument section.";
        if(!xx_rt_wcscmp(r->name,L"repeat_offset"))text=L"Stored repeat position;reference byte loop start=2*(repeat_offset-sample_offset),clamped at zero.";
        if(!xx_rt_wcscmp(r->name,L"length_words"))text=L"16-bit words;byte count=value*2.";
        break;
    case 0x60340075U:
        if(!xx_rt_wcscmp(r->name,L"song_offset"))text=L"Relative to song-index section.";
        break;
    case 0x60340076U:
        if(!xx_rt_wcscmp(r->name,L"playlist0"))text=L"Relative to the beginning of this song record.";
        if(!xx_rt_wcscmp(r->name,L"playlist1"))text=L"Relative to the beginning of this song record.";
        if(!xx_rt_wcscmp(r->name,L"playlist2"))text=L"Relative to the beginning of this song record.";
        if(!xx_rt_wcscmp(r->name,L"playlist3"))text=L"Relative to the beginning of this song record.";
        break;
    case 0x60340077U:
        if(!xx_rt_wcscmp(r->name,L"track_offset"))text=L"Relative to pattern-index section.";
        break;
    case 0x60340079U:
        if(!xx_rt_wcscmp(r->name,L"opl_parameters"))text=L"Physical OPL instrument parameter block;no register writes are executed.";
        break;
    case 0x6034007bU:
        if(!xx_rt_wcscmp(r->name,L"note"))text=L"0..96=note,254=pattern break,255=release note.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}

static bool sx_trackerextra_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id<0x60340000U||id>=0x60350000U)return true;
 if(!sx_trackerextra_static_comment(r,id))return false;
 if(xx_var_get_type(&r->value)==XX_VAR_TYPE_FLOAT||xx_var_get_type(&r->value)==XX_VAR_TYPE_DOUBLE||xx_var_get_type(&r->value)==XX_VAR_TYPE_STRING||xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES)return true;
 uint64_t v=xx_var_get_u64(&r->value);const wchar_t*text=NULL;
 if(id==sxtx_stm_short_event.id)text=v==251||v==252?L"EMPTY_NOTE":v==253?L"NOTE_CUT":NULL;
 if(id==sxtx_stm_header.id&&!xx_rt_wcscmp(r->name,L"file_type"))text=v==1?L"STM_SONG":v==2?L"STM_MODULE":NULL;
 if(id==sxtx_mad_event.id)text=v==254?L"PATTERN_BREAK":v==255?L"NOTE_RELEASE":NULL;
 if(id==sxtx_psm_opcode.id)switch(v){case 0:text=L"OPLH_END";break;case 1:text=L"OPLH_PLAY_ORDER";break;case 2:text=L"OPLH_PLAY_RANGE";break;case 3:text=L"OPLH_JUMP_LOOP";break;case 4:text=L"OPLH_JUMP_LINE";break;case 5:text=L"OPLH_CHANNEL_FLIP";break;case 6:text=L"OPLH_TRANSPOSE";break;case 7:text=L"OPLH_DEFAULT_SPEED";break;case 8:text=L"OPLH_DEFAULT_TEMPO";break;case 12:text=L"OPLH_SAMPLE_MAP";break;case 13:text=L"OPLH_CHANNEL_PANNING";break;case 14:text=L"OPLH_CHANNEL_VOLUME";break;default:break;}
 if(id==sxtx_dtm_pattern_info.id&&!xx_rt_wcscmp(r->name,L"event_format"))text=v==0?L"PROTRACKER_EVENTS":v==0x322e3034?L"DIGITAL_TRACKER_2_04_EVENTS":NULL;
 return !text||xx_data_struct_record_set_comment(r,text);
}

/* Native component boundaries are retained; encoded streams and samples stay raw. */
static uint32_t sxtx_num(sx_context*c,int64_t at,unsigned width,bool be){uint8_t b[4];if(!width||width>4||!sx_read(c,at,b,width)){c->failed=true;return 0;}uint32_t v=0;for(unsigned i=0;i<width;i++)v|=(uint32_t)b[i]<<(8*(be?width-1-i:i));return v;}
static bool sxtx_take(sx_context*c,const sx_layout*l,int64_t*at,int64_t end,uint64_t count){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t width=(uint64_t)(f->rel_offset+f->size);if(*at<0||end<*at||!width||count>(uint64_t)(end-*at)/width)return false;if(count&&c->count<32000&&!sx_table(c,l,*at,(int64_t)width,count))return false;*at+=(int64_t)(count*width);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxtx_skip(int64_t*at,int64_t end,uint64_t n){if(*at<0||end<*at||n>(uint64_t)(end-*at))return false;*at+=(int64_t)n;return true;}
static bool sxtx_eq(const char*a,const char*b){return !xx_rt_strcmp(a,b);}
static bool sxtx_prefix(const char*a,const char*b){return !xx_rt_strncmp(a,b,xx_rt_strlen(b));}
static bool sxtx_suffix(const char*a,const char*b){size_t x=xx_rt_strlen(a),y=xx_rt_strlen(b);return x>=y&&!xx_rt_strcmp(a+x-y,b);}
static bool sxtx_tag(sx_context*c,int64_t at,const char*t){uint8_t b[4];return sx_read(c,at,b,4)&&!xx_rt_memcmp(b,t,4);}
static int sxtx_dtm_mode(sx_context*c){int64_t at=0;for(unsigned i=0;i<65536&&at<c->size;i++){if(!sx_range(c,at,8))return -1;uint32_t n=sxtx_num(c,at+4,4,true);if(!sx_range(c,at+8,n))return -1;if(sxtx_tag(c,at,"PATT")){if(n!=8)return -1;return sxtx_num(c,at+12,4,true)?1:0;}at+=8+(int64_t)n;}return -1;}
#define TX(n,k) do{if(!sxtx_take(c,&sxtx_##n,&at,end,(k)))return false;}while(0)
#define SK(n) do{if(!sxtx_skip(&at,end,(n)))return false;}while(0)
#define N(p,w) sxtx_num(c,(p),(w),false)
#define B(p,w) sxtx_num(c,(p),(w),true)
#define EQ(n) sxtx_eq(name,(n))
static bool sxtx_psm_oplh(sx_context*c,int64_t at,int64_t end){TX(count_u16le,1);for(unsigned ops=0;at<end&&ops<4096;ops++){unsigned op=N(at,1);TX(psm_opcode,1);switch(op){case 0:return at==end;case 1:TX(psm_play,1);break;case 2:TX(psm_range,1);break;case 3:TX(psm_jump_loop,1);break;case 4:TX(psm_jump,1);break;case 5:case 14:TX(psm_channel_value,1);break;case 6:case 7:case 8:TX(psm_value,1);break;case 12:TX(psm_sample_map,1);break;case 13:TX(psm_panning,1);break;default:return false;}}return at==end;}
static bool sxtx_component(sx_context*c,const char*name,int64_t at,int64_t size)
{
 int64_t end=at+size;uint32_t n,m,k;switch(c->f->file_type){
 case XX_FILE_TYPE_TRACKER_STM:
  if(EQ("stm-descriptor.bin")){TX(stm_header,1);TX(stm_sample,31);TX(order_u8le,128);}
  else if(sxtx_prefix(name,"pattern-")){while(at<end){n=N(at,1);if(n>=251&&n<=253){TX(stm_short_event,1);}else{TX(stm_event,1);}}}break;
 case XX_FILE_TYPE_TRACKER_669:
  if(EQ("669-descriptor.bin")){TX(c669_header,1);TX(order_u8le,128);TX(c669_speed,128);TX(c669_last_row,128);}
  else if(sxtx_suffix(name,"-descriptor.bin")){TX(c669_sample,1);}
  else if(sxtx_prefix(name,"pattern-")){if(size%3)return false;TX(c669_event,size/3);}break;
 case XX_FILE_TYPE_TRACKER_LIQUID:
  if(EQ("headers-orders.bin")){n=N(95,2);m=N(105,2);TX(liq_header,1);TX(pan_u8,n);TX(volume_u8,n);TX(order_u8le,m);}
  else if(EQ("encoded-pattern.bin")){TX(liq_pattern,1);}
  else if(EQ("empty-instrument.bin")){TX(liq_empty_instrument,1);}
  else if(EQ("sample-header.bin")){TX(liq_sample,1);}break;
 case XX_FILE_TYPE_TRACKER_DMF:
  if(EQ("header.bin")){TX(dmf_header,1);}
  else if(EQ("ENDE.bin")){TX(dmf_end,1);}
  else {TX(chunk_le,1);
   if(EQ("SEQU.bin")){TX(dmf_sequence,1);if((end-at)%2)return false;TX(order_u16le,(end-at)/2);}
   else if(EQ("PATT.bin")){n=N(at,2);TX(dmf_patterns,1);for(uint32_t i=0;i<n;i++){m=N(at+4,4);TX(dmf_pattern,1);SK(m);}if(at!=end)return false;}
   else if(EQ("SMPI.bin")){n=N(at,1);TX(count_u8le,1);for(uint32_t i=0;i<n;i++){m=N(at,1);TX(length_u8le,1);SK(m);TX(dmf_sample,1);}if(at!=end)return false;}
   else if(EQ("SMPD.bin")){while(at<end){n=N(at,4);TX(length_u32le,1);SK(n);}}
  }break;
 case XX_FILE_TYPE_TRACKER_PTM:
  if(EQ("headers.bin")){n=N(34,2);TX(ptm_header,1);TX(pan_u8,32);TX(order_u8le,256);TX(paragraph_u16,128);TX(ptm_sample,n);if(at!=end)return false;}break;
 case XX_FILE_TYPE_TRACKER_AMS:
  if(EQ("headers-text-orders.bin")){n=N(10,1);m=N(11,2);k=N(13,2);uint32_t ch=(N(9,1)&31)+1,extra=N(16,2);TX(ams_header,1);SK(extra);TX(ams_sample,n);for(uint32_t i=0;i<1+n+ch+m;i++){uint32_t z=N(at,1);TX(length_u8le,1);SK(z);}n=N(at,2);TX(length_u16le,1);SK(n);TX(order_u16le,k);if(at!=end)return false;}
  else if(EQ("encoded-pattern.bin")){TX(length_u32le,1);}break;
 case XX_FILE_TYPE_TRACKER_EMOD:
  if(EQ("header.bin")){TX(emod_header,1);}
  else {TX(chunk_be,1);
   if(EQ("EMIC.bin")){n=N(at+43,1);TX(emod_info,1);TX(emod_sample,n);n=N(at+1,1);TX(emod_pattern_count,1);TX(emod_pattern,n);n=N(at,1);TX(count_u8le,1);TX(order_u8le,n);if(at!=end)return false;}
   else if(EQ("PATT.bin")){if((end-at)%4)return false;TX(emod_event,(end-at)/4);}
  }break;
 case XX_FILE_TYPE_TRACKER_MT2:
  if(EQ("headers-orders.bin")){TX(mt2_header,1);TX(order_u8le,256);TX(mt2_drum_size,1);TX(mt2_extra_size,1);if(at!=end)return false;}
  else if(EQ("pattern.bin")){n=N(at+2,4);TX(mt2_pattern,1);if(n%7)return false;TX(mt2_event,n/7);}
  else if(EQ("empty-instrument-sample-slots.bin")){TX(mt2_slot,511);if(at!=end)return false;}break;
 case XX_FILE_TYPE_TRACKER_PSM:
  if(EQ("descriptor.bin")){TX(psm_header,1);}
  else {TX(chunk_le,1);
   if(EQ("chunk-SDFT.bin")){TX(psm_format,1);}
   else if(EQ("chunk-DSMP.bin")){TX(psm_sample,1);}
   else if(EQ("chunk-PBOD.bin")){TX(psm_pattern,1);while(at<end){n=N(at,2);if(n<2)return false;TX(length_u16le,1);SK(n-2);}}
   else if(EQ("chunk-SONG.bin")){TX(psm_song,1);for(unsigned i=0;at<end&&i<16;i++){n=N(at+4,4);bool oplh=sxtx_tag(c,at,"OPLH"),date=sxtx_tag(c,at,"DATE");TX(chunk_le,1);if(n>(uint64_t)(end-at))return false;if(oplh&&!sxtx_psm_oplh(c,at,at+n))return false;if(date){int64_t save=end;end=at+n;TX(psm_date,1);end=save;}else SK(n);}if(at!=end)return false;}
  }break;
 case XX_FILE_TYPE_TRACKER_DTT:
  if(EQ("module-index.bin")){n=N(140,4);m=N(160,4);k=N(164,4);TX(dtt_header,1);TX(order_u8le,n);SK((-n)&3);TX(offset_u32,m);TX(count_u8le,m);SK((-m)&3);TX(dtt_sample,k);if(at!=end)return false;}
  else if(sxtx_prefix(name,"pattern-")){while(at<end){n=N(at,4);TX(dtt_event,1);if(n&(31U<<17)){TX(dtt_event_extra,1);}}}break;
 case XX_FILE_TYPE_TRACKER_STX:
  if(EQ("descriptor.stx")){TX(stx_header,1);}
  else if(EQ("pattern-index.stx")||EQ("instrument-index.stx")){if(size%2)return false;TX(paragraph_u16,size/2);}
  else if(EQ("channels-orders.stx")){TX(stx_channels,1);if((end-at)%5)return false;TX(stx_order,(end-at)/5);}
  else if(EQ("instrument.stx")){TX(stx_sample,1);}break;
 case XX_FILE_TYPE_TRACKER_DTM:
  {bool head=sxtx_tag(c,at,"D.T."),seq=sxtx_tag(c,at,"S.Q."),pat=sxtx_tag(c,at,"PATT"),ins=sxtx_tag(c,at,"INST"),dapt=sxtx_tag(c,at,"DAPT"),dait=sxtx_tag(c,at,"DAIT");TX(chunk_be,1);
   if(head){TX(dtm_info,1);}
   else if(seq){n=B(at,2);TX(dtm_sequence,1);TX(order_u8le,n);}
   else if(pat){TX(dtm_pattern_info,1);}
   else if(ins){n=B(at,2);TX(count_u16be,1);TX(dtm_sample,n);}
   else if(dapt){TX(dtm_pattern,1);int mode=sxtx_dtm_mode(c);if(mode<0||(end-at)%4)return false;if(mode){TX(dtm_event,(end-at)/4);}else{TX(mod_event,(end-at)/4);}}
   else if(dait){TX(order_u16be,1);}
  }break;
 case XX_FILE_TYPE_TRACKER_FUNK:
  if(EQ("descriptor.fnk")){TX(funk_header,1);}
  else if(EQ("orders.fnk")){TX(order_u8le,size);}
  else if(EQ("pattern-breaks.fnk")){TX(c669_last_row,size);}
  else if(EQ("instruments.fnk")){TX(funk_sample,64);}
  else if(EQ("pattern.fnk")){if(size%3)return false;TX(funk_event,size/3);}break;
 case XX_FILE_TYPE_TRACKER_ARCHIMEDES:
  if(EQ("sample.vidc"))break;
  {bool count=sxtx_tag(c,at,"MVOX")||sxtx_tag(c,at,"MLEN")||sxtx_tag(c,at,"PNUM"),plen=sxtx_tag(c,at,"PLEN"),seq=sxtx_tag(c,at,"SEQU"),names=sxtx_tag(c,at,"MNAM")||sxtx_tag(c,at,"ANAM"),info=sxtx_tag(c,at,"TINF"),pan=sxtx_tag(c,at,"STER"),pat=sxtx_tag(c,at,"PATT");TX(chunk_le,1);
   if(count){TX(count_u32le,1);}else if(plen){TX(count_u8le,64);}else if(seq){TX(order_u8le,128);}else if(names){TX(musx_name,1);}else if(info){TX(musx_tracker,1);}else if(pan){TX(pan_u8,8);}else if(pat){if((end-at)%4)return false;TX(musx_event,(end-at)/4);}
   else if(EQ("sample-descriptor.musx")){n=N(at+4,4);TX(chunk_le,1);SK(n);TX(chunk_le,1);TX(musx_volume,1);TX(chunk_le,1);TX(length_u32le,1);TX(chunk_le,1);TX(musx_loop_offset,1);TX(chunk_le,1);TX(length_u32le,1);TX(chunk_le,1);if(at!=end)return false;}
  }break;
 case XX_FILE_TYPE_TRACKER_COCONIZER:
  if(EQ("descriptor.coco")){TX(coco_header,1);}else if(EQ("instruments.coco")){if(size%32)return false;TX(coco_sample,size/32);}else if(EQ("orders.coco")){TX(order_u8le,size);}else if(EQ("pattern.coco")){if(size%4)return false;TX(musx_event,size/4);}break;
 case XX_FILE_TYPE_TRACKER_REAL:
  if(EQ("extra-data.rtm")){n=N(98,2);TX(order_u16le,n);}
  else {n=N(at+40,2);TX(rtm_object,1);
   if(EQ("descriptor.rtm")){TX(rtm_song,1);TX(rtm_pan,32);TX(rtm_extra_size,1);if(n==130){TX(rtm_original_name,1);}}
   else if(EQ("pattern-object.rtm")){TX(rtm_pattern,1);}
   else if(EQ("instrument-object.rtm")){TX(rtm_instrument,1);TX(rtm_keymap,120);for(unsigned i=0;i<2;i++){TX(count_u8le,1);TX(rtm_envelope_point,12);TX(rtm_envelope_tail,1);}TX(rtm_instrument_tail,1);if(n==341){TX(rtm_instrument_v112,1);}if(at!=end)return false;}
   else if(EQ("sample-object.rtm")){TX(rtm_sample,1);}
  }break;
 case XX_FILE_TYPE_TRACKER_MEGATRACKER:
  if(EQ("descriptor.mgt")){TX(mgt_header,1);}else if(EQ("song.mgt")){n=B(8,2);TX(mgt_song,1);TX(mgt_pan,n);}else if(EQ("orders.mgt")){if(size%2)return false;TX(order_u16be,size/2);}else if(EQ("instruments.mgt")){if(size%80)return false;TX(mgt_sample,size/80);}else if(EQ("pattern-map.mgt")){n=B(8,2);while(at<end){TX(count_u16be,1);TX(order_u16be,n);}}else if(EQ("track-offsets.mgt")){if(size%4)return false;TX(mgt_offset,size/4);}else if(EQ("track.mgt")){TX(count_u16be,1);}break;
 case XX_FILE_TYPE_AMOS_MUSIC_BANK:
  if(EQ("descriptor.abk")){TX(abk_header,1);}else if(EQ("instruments.abk")){n=B(at,2);TX(count_u16be,1);TX(abk_sample,n);}else if(EQ("song-index.abk")){TX(abk_song_index,1);}else if(EQ("song.abk")){TX(abk_song,1);}else if(EQ("playlist.abk")){if(size%2)return false;TX(order_u16be,size/2);}else if(EQ("pattern-index.abk")){n=B(at,2);TX(count_u16be,1);TX(abk_pattern_offset,n*4);}break;
 case XX_FILE_TYPE_MAD_TRACKER:
  if(EQ("descriptor.mad")){TX(mad_header,1);}else if(EQ("instrument.mad")){TX(mad_instrument,1);}else if(EQ("song-info.mad")){TX(mad_song,1);}else if(EQ("pattern.mad")){TX(mad_event,size);}else if(EQ("orders.mad")){TX(order_u8le,size);}break;
 default:return false;
 }return !c->failed&&!xx_pd_is_stopped(c->pd);
}
#undef TX
#undef SK
#undef N
#undef B
#undef EQ

static int sxtx_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
static bool sxtx_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxtx_order);
 /* Native trackers can share tracks/playlists. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxtx_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}

static bool sx_trackerextra_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_TRACKER_STM:case XX_FILE_TYPE_TRACKER_669:case XX_FILE_TYPE_TRACKER_LIQUID:case XX_FILE_TYPE_TRACKER_DMF:case XX_FILE_TYPE_TRACKER_PTM:case XX_FILE_TYPE_TRACKER_AMS:case XX_FILE_TYPE_TRACKER_EMOD:case XX_FILE_TYPE_TRACKER_MT2:case XX_FILE_TYPE_TRACKER_PSM:case XX_FILE_TYPE_TRACKER_DTT:case XX_FILE_TYPE_TRACKER_STX:case XX_FILE_TYPE_TRACKER_DTM:case XX_FILE_TYPE_TRACKER_FUNK:case XX_FILE_TYPE_TRACKER_ARCHIMEDES:case XX_FILE_TYPE_TRACKER_COCONIZER:case XX_FILE_TYPE_TRACKER_REAL:case XX_FILE_TYPE_TRACKER_MEGATRACKER:case XX_FILE_TYPE_AMOS_MUSIC_BANK:case XX_FILE_TYPE_MAD_TRACKER:return true;default:return false;}}
static bool sx_trackerextra_build(sx_context*c)
{
 if(!c||c->size<1||c->size>268435456||!c->f->create_archive_records_reading)return false;
 xx_archive_record_state*s=xx_format_create_archive_records_reading(c->f,NULL,c->pd);if(!s)return false;bool ok=true;uint64_t walked=0;
 while(ok&&s->has_record){const xx_archive_record*r=xx_format_get_current_archive_record(c->f,s);const char*name=r?xx_archive_record_get_original_name(r):NULL;
  if(++walked>65536||xx_pd_is_stopped(c->pd)||!r||!name||xx_rt_strlen(name)<5||name[4]!='-'||r->data_offset<c->f->base_address||r->compressed_size<0){ok=false;break;}
  int64_t at=r->data_offset-c->f->base_address,n=r->compressed_size;
  if(!sx_range(c,at,(uint64_t)n)||!sxtx_component(c,name+5,at,n)){ok=false;break;}
  if(!xx_format_archive_record_move_to_next(c->f,s,c->pd))break;
 }
 if(walked!=(uint64_t)s->total_records||xx_pd_is_stopped(c->pd))ok=false;
 xx_format_free_archive_records_reading(c->f,s);return ok&&c->count>0&&sxtx_finish(c);
}

const sx_family sx_trackerextra_family={sx_trackerextra_supports,sx_trackerextra_build,sx_trackerextra_layouts,SX_COUNT(sx_trackerextra_layouts),sx_trackerextra_comment};
