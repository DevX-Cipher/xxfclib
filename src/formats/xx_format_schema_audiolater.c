/* SPDX-License-Identifier: MIT
 * Additional audio metadata. Scope: docs/data_struct_audiolater_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_audiolater.h"
static const xx_data_struct_field_desc sxaul_amd_header_fields[] = {
    SX_FIELD("title","char[24]",0,24,SX_STRING),
    SX_FIELD("author","char[24]",24,24,SX_STRING),
};
static const sx_layout sxaul_amd_header = {UINT32_C(0x60380001),"amd_header",sxaul_amd_header_fields,SX_COUNT(sxaul_amd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_amd_instrument_fields[] = {
    SX_FIELD("name","char[23]",0,23,SX_STRING),
    SX_FIELD("opl_parameter0","uint8",23,1,SX_FLAGS),
    SX_FIELD("opl_parameter1","uint8",24,1,SX_FLAGS),
    SX_FIELD("opl_parameter2","uint8",25,1,SX_FLAGS),
    SX_FIELD("opl_parameter3","uint8",26,1,SX_FLAGS),
    SX_FIELD("opl_parameter4","uint8",27,1,SX_FLAGS),
    SX_FIELD("opl_parameter5","uint8",28,1,SX_FLAGS),
    SX_FIELD("opl_parameter6","uint8",29,1,SX_FLAGS),
    SX_FIELD("opl_parameter7","uint8",30,1,SX_FLAGS),
    SX_FIELD("opl_parameter8","uint8",31,1,SX_FLAGS),
    SX_FIELD("opl_parameter9","uint8",32,1,SX_FLAGS),
    SX_FIELD("opl_parameter10","uint8",33,1,SX_FLAGS),
};
static const sx_layout sxaul_amd_instrument = {UINT32_C(0x60380002),"amd_instrument",sxaul_amd_instrument_fields,SX_COUNT(sxaul_amd_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_amd_orders_fields[] = {
    SX_FIELD("order_count","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("pattern_count_minus_one","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("orders","uint8[128]",2,128,SX_ID),
    SX_FIELD("magic","uint8[9]",130,9,SX_SIGNATURE),
    SX_FIELD("version","uint8",139,1,SX_ID),
};
static const sx_layout sxaul_amd_orders = {UINT32_C(0x60380003),"amd_orders",sxaul_amd_orders_fields,SX_COUNT(sxaul_amd_orders_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_amd_event_fields[] = {
    SX_FIELD("decimal_parameter","uint8",0,1,SX_NONE),
    SX_FIELD("instrument_effect","uint8",1,1,SX_FLAGS),
    SX_FIELD("note_instrument","uint8",2,1,SX_FLAGS),
};
static const sx_layout sxaul_amd_event = {UINT32_C(0x60380004),"amd_event",sxaul_amd_event_fields,SX_COUNT(sxaul_amd_event_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_amd_empty_run_fields[] = {
    SX_FIELD("empty_row_run","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxaul_amd_empty_run = {UINT32_C(0x60380005),"amd_empty_run",sxaul_amd_empty_run_fields,SX_COUNT(sxaul_amd_empty_run_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_track_u16_fields[] = {
    SX_FIELD("track_index","uint16",0,2,SX_ID),
};
static const sx_layout sxaul_track_u16 = {UINT32_C(0x60380006),"track_u16",sxaul_track_u16_fields,SX_COUNT(sxaul_track_u16_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_count_u16_fields[] = {
    SX_FIELD("count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxaul_count_u16 = {UINT32_C(0x60380007),"count_u16",sxaul_count_u16_fields,SX_COUNT(sxaul_count_u16_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_order_u8_fields[] = {
    SX_FIELD("order","uint8",0,1,SX_ID),
};
static const sx_layout sxaul_order_u8 = {UINT32_C(0x60380008),"order_u8",sxaul_order_u8_fields,SX_COUNT(sxaul_order_u8_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_mkj_header_fields[] = {
    SX_FIELD("magic","char[6]",0,6,SX_SIGNATURE),
    SX_FIELD("version","float32",6,4,SX_NONE),
    SX_FIELD("channels","uint16",10,2,SX_COUNT_PROP),
};
static const sx_layout sxaul_mkj_header = {UINT32_C(0x60380009),"mkj_header",sxaul_mkj_header_fields,SX_COUNT(sxaul_mkj_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_mkj_instrument_fields[] = {
    SX_FIELD("opl_parameter0","uint16",0,2,SX_FLAGS),
    SX_FIELD("opl_parameter1","uint16",2,2,SX_FLAGS),
    SX_FIELD("opl_parameter2","uint16",4,2,SX_FLAGS),
    SX_FIELD("opl_parameter3","uint16",6,2,SX_FLAGS),
    SX_FIELD("opl_parameter4","uint16",8,2,SX_FLAGS),
    SX_FIELD("opl_parameter5","uint16",10,2,SX_FLAGS),
    SX_FIELD("opl_parameter6","uint16",12,2,SX_FLAGS),
    SX_FIELD("opl_parameter7","uint16",14,2,SX_FLAGS),
};
static const sx_layout sxaul_mkj_instrument = {UINT32_C(0x6038000a),"mkj_instrument",sxaul_mkj_instrument_fields,SX_COUNT(sxaul_mkj_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_mkj_channel_enabled_fields[] = {
    SX_FIELD("enabled","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxaul_mkj_channel_enabled = {UINT32_C(0x6038000b),"mkj_channel_enabled",sxaul_mkj_channel_enabled_fields,SX_COUNT(sxaul_mkj_channel_enabled_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_mkj_event_fields[] = {
    SX_FIELD("event","int16",0,2,SX_NONE),
};
static const sx_layout sxaul_mkj_event = {UINT32_C(0x6038000c),"mkj_event",sxaul_mkj_event_fields,SX_COUNT(sxaul_mkj_event_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sa2_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint8",4,1,SX_ID),
};
static const sx_layout sxaul_sa2_header = {UINT32_C(0x6038000d),"sa2_header",sxaul_sa2_header_fields,SX_COUNT(sxaul_sa2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sa2_instrument_fields[] = {
    SX_FIELD("opl_parameter0","uint8",0,1,SX_FLAGS),
    SX_FIELD("opl_parameter1","uint8",1,1,SX_FLAGS),
    SX_FIELD("opl_parameter2","uint8",2,1,SX_FLAGS),
    SX_FIELD("opl_parameter3","uint8",3,1,SX_FLAGS),
    SX_FIELD("opl_parameter4","uint8",4,1,SX_FLAGS),
    SX_FIELD("opl_parameter5","uint8",5,1,SX_FLAGS),
    SX_FIELD("opl_parameter6","uint8",6,1,SX_FLAGS),
    SX_FIELD("opl_parameter7","uint8",7,1,SX_FLAGS),
    SX_FIELD("opl_parameter8","uint8",8,1,SX_FLAGS),
    SX_FIELD("opl_parameter9","uint8",9,1,SX_FLAGS),
    SX_FIELD("opl_parameter10","uint8",10,1,SX_FLAGS),
    SX_FIELD("arpeggio_start","uint8",11,1,SX_ID),
    SX_FIELD("arpeggio_speed","uint8",12,1,SX_NONE),
    SX_FIELD("arpeggio_position","uint8",13,1,SX_ID),
    SX_FIELD("arpeggio_speed_counter","uint8",14,1,SX_NONE),
};
static const sx_layout sxaul_sa2_instrument = {UINT32_C(0x6038000e),"sa2_instrument",sxaul_sa2_instrument_fields,SX_COUNT(sxaul_sa2_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sa2_name_fields[] = {
    SX_FIELD("name","char[17]",0,17,SX_STRING),
};
static const sx_layout sxaul_sa2_name = {UINT32_C(0x6038000f),"sa2_name",sxaul_sa2_name_fields,SX_COUNT(sxaul_sa2_name_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sa2_names_padding_fields[] = {
    SX_FIELD("padding","uint8[3]",0,3,SX_RESERVED),
};
static const sx_layout sxaul_sa2_names_padding = {UINT32_C(0x60380010),"sa2_names_padding",sxaul_sa2_names_padding_fields,SX_COUNT(sxaul_sa2_names_padding_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sa2_song_fields[] = {
    SX_FIELD("patterns","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("orders","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("restart_order","uint8",3,1,SX_ID),
    SX_FIELD("bpm","uint16",4,2,SX_NONE),
};
static const sx_layout sxaul_sa2_song = {UINT32_C(0x60380011),"sa2_song",sxaul_sa2_song_fields,SX_COUNT(sxaul_sa2_song_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sa2_arpeggio_fields[] = {
    SX_FIELD("arpeggio","uint8",0,1,SX_NONE),
};
static const sx_layout sxaul_sa2_arpeggio = {UINT32_C(0x60380012),"sa2_arpeggio",sxaul_sa2_arpeggio_fields,SX_COUNT(sxaul_sa2_arpeggio_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sa2_arpcommand_fields[] = {
    SX_FIELD("command","uint8",0,1,SX_ID),
};
static const sx_layout sxaul_sa2_arpcommand = {UINT32_C(0x60380013),"sa2_arpcommand",sxaul_sa2_arpcommand_fields,SX_COUNT(sxaul_sa2_arpcommand_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sa2_track_fields[] = {
    SX_FIELD("track","uint8",0,1,SX_ID),
};
static const sx_layout sxaul_sa2_track = {UINT32_C(0x60380014),"sa2_track",sxaul_sa2_track_fields,SX_COUNT(sxaul_sa2_track_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sa2_channels_fields[] = {
    SX_FIELD("active_channels","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxaul_sa2_channels = {UINT32_C(0x60380015),"sa2_channels",sxaul_sa2_channels_fields,SX_COUNT(sxaul_sa2_channels_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sa2_event_fields[] = {
    SX_FIELD("note_instrument","uint8",0,1,SX_FLAGS),
    SX_FIELD("instrument_effect","uint8",1,1,SX_FLAGS),
    SX_FIELD("parameter","uint8",2,1,SX_FLAGS),
};
static const sx_layout sxaul_sa2_event = {UINT32_C(0x60380016),"sa2_event",sxaul_sa2_event_fields,SX_COUNT(sxaul_sa2_event_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_fmc_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("title","char[21]",4,21,SX_STRING),
    SX_FIELD("channels","uint8",25,1,SX_COUNT_PROP),
};
static const sx_layout sxaul_fmc_header = {UINT32_C(0x60380017),"fmc_header",sxaul_fmc_header_fields,SX_COUNT(sxaul_fmc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_fmc_order_padding_fields[] = {
    SX_FIELD("reserved","uint8[2]",0,2,SX_RESERVED),
};
static const sx_layout sxaul_fmc_order_padding = {UINT32_C(0x60380018),"fmc_order_padding",sxaul_fmc_order_padding_fields,SX_COUNT(sxaul_fmc_order_padding_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_fmc_instrument_fields[] = {
    SX_FIELD("synthesis","uint8",0,1,SX_ID),
    SX_FIELD("feedback","uint8",1,1,SX_NONE),
    SX_FIELD("modulator_attack","uint8",2,1,SX_NONE),
    SX_FIELD("modulator_decay","uint8",3,1,SX_NONE),
    SX_FIELD("modulator_sustain","uint8",4,1,SX_NONE),
    SX_FIELD("modulator_release","uint8",5,1,SX_NONE),
    SX_FIELD("modulator_volume","uint8",6,1,SX_NONE),
    SX_FIELD("modulator_key_scale_level","uint8",7,1,SX_NONE),
    SX_FIELD("modulator_frequency_multiple","uint8",8,1,SX_NONE),
    SX_FIELD("modulator_waveform","uint8",9,1,SX_NONE),
    SX_FIELD("modulator_sustain_sound","uint8",10,1,SX_NONE),
    SX_FIELD("modulator_key_scale_rate","uint8",11,1,SX_NONE),
    SX_FIELD("modulator_vibrato","uint8",12,1,SX_NONE),
    SX_FIELD("modulator_tremolo","uint8",13,1,SX_NONE),
    SX_FIELD("carrier_attack","uint8",14,1,SX_NONE),
    SX_FIELD("carrier_decay","uint8",15,1,SX_NONE),
    SX_FIELD("carrier_sustain","uint8",16,1,SX_NONE),
    SX_FIELD("carrier_release","uint8",17,1,SX_NONE),
    SX_FIELD("carrier_volume","uint8",18,1,SX_NONE),
    SX_FIELD("carrier_key_scale_level","uint8",19,1,SX_NONE),
    SX_FIELD("carrier_frequency_multiple","uint8",20,1,SX_NONE),
    SX_FIELD("carrier_waveform","uint8",21,1,SX_NONE),
    SX_FIELD("carrier_sustain_sound","uint8",22,1,SX_NONE),
    SX_FIELD("carrier_key_scale_rate","uint8",23,1,SX_NONE),
    SX_FIELD("carrier_vibrato","uint8",24,1,SX_NONE),
    SX_FIELD("carrier_tremolo","uint8",25,1,SX_NONE),
    SX_FIELD("pitch_shift","int8",26,1,SX_NONE),
    SX_FIELD("name","char[21]",27,21,SX_STRING),
};
static const sx_layout sxaul_fmc_instrument = {UINT32_C(0x60380019),"fmc_instrument",sxaul_fmc_instrument_fields,SX_COUNT(sxaul_fmc_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_fmc_event_fields[] = {
    SX_FIELD("note_instrument","uint8",0,1,SX_FLAGS),
    SX_FIELD("instrument_effect","uint8",1,1,SX_FLAGS),
    SX_FIELD("parameter","uint8",2,1,SX_FLAGS),
};
static const sx_layout sxaul_fmc_event = {UINT32_C(0x6038001a),"fmc_event",sxaul_fmc_event_fields,SX_COUNT(sxaul_fmc_event_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_rix_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("rhythm_mode","uint8",2,1,SX_FLAGS),
    SX_FIELD("unknown3","uint8[5]",3,5,SX_NONE),
    SX_FIELD("instrument_offset","uint16",8,2,SX_OFFSET),
    SX_FIELD("unknown10","uint8[2]",10,2,SX_NONE),
    SX_FIELD("music_offset","uint16",12,2,SX_OFFSET),
    SX_FIELD("unknown14","uint8[6]",14,6,SX_NONE),
};
static const sx_layout sxaul_rix_header = {UINT32_C(0x6038001b),"rix_header",sxaul_rix_header_fields,SX_COUNT(sxaul_rix_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_rix_instrument_fields[] = {
    SX_FIELD("modulator_parameter0","uint16",0,2,SX_NONE),
    SX_FIELD("modulator_parameter1","uint16",2,2,SX_NONE),
    SX_FIELD("modulator_parameter2","uint16",4,2,SX_NONE),
    SX_FIELD("modulator_parameter3","uint16",6,2,SX_NONE),
    SX_FIELD("modulator_parameter4","uint16",8,2,SX_NONE),
    SX_FIELD("modulator_parameter5","uint16",10,2,SX_NONE),
    SX_FIELD("modulator_parameter6","uint16",12,2,SX_NONE),
    SX_FIELD("modulator_parameter7","uint16",14,2,SX_NONE),
    SX_FIELD("modulator_parameter8","uint16",16,2,SX_NONE),
    SX_FIELD("modulator_parameter9","uint16",18,2,SX_NONE),
    SX_FIELD("modulator_parameter10","uint16",20,2,SX_NONE),
    SX_FIELD("modulator_parameter11","uint16",22,2,SX_NONE),
    SX_FIELD("modulator_parameter12","uint16",24,2,SX_NONE),
    SX_FIELD("carrier_parameter0","uint16",26,2,SX_NONE),
    SX_FIELD("carrier_parameter1","uint16",28,2,SX_NONE),
    SX_FIELD("carrier_parameter2","uint16",30,2,SX_NONE),
    SX_FIELD("carrier_parameter3","uint16",32,2,SX_NONE),
    SX_FIELD("carrier_parameter4","uint16",34,2,SX_NONE),
    SX_FIELD("carrier_parameter5","uint16",36,2,SX_NONE),
    SX_FIELD("carrier_parameter6","uint16",38,2,SX_NONE),
    SX_FIELD("carrier_parameter7","uint16",40,2,SX_NONE),
    SX_FIELD("carrier_parameter8","uint16",42,2,SX_NONE),
    SX_FIELD("carrier_parameter9","uint16",44,2,SX_NONE),
    SX_FIELD("carrier_parameter10","uint16",46,2,SX_NONE),
    SX_FIELD("carrier_parameter11","uint16",48,2,SX_NONE),
    SX_FIELD("carrier_parameter12","uint16",50,2,SX_NONE),
    SX_FIELD("modulator_flag","uint16",52,2,SX_FLAGS),
    SX_FIELD("carrier_flag","uint16",54,2,SX_FLAGS),
    SX_FIELD("unknown_tail","uint8[8]",56,8,SX_NONE),
};
static const sx_layout sxaul_rix_instrument = {UINT32_C(0x6038001c),"rix_instrument",sxaul_rix_instrument_fields,SX_COUNT(sxaul_rix_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_rix_event_fields[] = {
    SX_FIELD("operand","uint8",0,1,SX_NONE),
    SX_FIELD("opcode","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxaul_rix_event = {UINT32_C(0x6038001d),"rix_event",sxaul_rix_event_fields,SX_COUNT(sxaul_rix_event_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sop_header_fields[] = {
    SX_FIELD("magic","char[7]",0,7,SX_SIGNATURE),
    SX_FIELD("version","uint24",7,3,SX_ID),
    SX_FIELD("filename","char[13]",10,13,SX_STRING),
    SX_FIELD("title","char[31]",23,31,SX_STRING),
    SX_FIELD("rhythm_mode","uint8",54,1,SX_FLAGS),
    SX_FIELD("reserved55","uint8",55,1,SX_RESERVED),
    SX_FIELD("ticks_per_beat","uint8",56,1,SX_NONE),
    SX_FIELD("reserved57","uint8",57,1,SX_RESERVED),
    SX_FIELD("beats_per_measure","uint8",58,1,SX_NONE),
    SX_FIELD("basic_tempo","uint8",59,1,SX_NONE),
    SX_FIELD("comment","char[13]",60,13,SX_STRING),
    SX_FIELD("tracks","uint8",73,1,SX_COUNT_PROP),
    SX_FIELD("instruments","uint8",74,1,SX_COUNT_PROP),
    SX_FIELD("reserved75","uint8",75,1,SX_RESERVED),
};
static const sx_layout sxaul_sop_header = {UINT32_C(0x6038001e),"sop_header",sxaul_sop_header_fields,SX_COUNT(sxaul_sop_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sop_channel_mode_fields[] = {
    SX_FIELD("mode","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxaul_sop_channel_mode = {UINT32_C(0x6038001f),"sop_channel_mode",sxaul_sop_channel_mode_fields,SX_COUNT(sxaul_sop_channel_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sop_instrument_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
    SX_FIELD("filename","char[8]",1,8,SX_STRING),
    SX_FIELD("name","char[19]",9,19,SX_STRING),
};
static const sx_layout sxaul_sop_instrument = {UINT32_C(0x60380020),"sop_instrument",sxaul_sop_instrument_fields,SX_COUNT(sxaul_sop_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sop_opl2_fields[] = {
    SX_FIELD("opl_parameter0","uint8",0,1,SX_FLAGS),
    SX_FIELD("opl_parameter1","uint8",1,1,SX_FLAGS),
    SX_FIELD("opl_parameter2","uint8",2,1,SX_FLAGS),
    SX_FIELD("opl_parameter3","uint8",3,1,SX_FLAGS),
    SX_FIELD("opl_parameter4","uint8",4,1,SX_FLAGS),
    SX_FIELD("opl_parameter5","uint8",5,1,SX_FLAGS),
    SX_FIELD("opl_parameter6","uint8",6,1,SX_FLAGS),
    SX_FIELD("opl_parameter7","uint8",7,1,SX_FLAGS),
    SX_FIELD("opl_parameter8","uint8",8,1,SX_FLAGS),
    SX_FIELD("opl_parameter9","uint8",9,1,SX_FLAGS),
    SX_FIELD("opl_parameter10","uint8",10,1,SX_FLAGS),
};
static const sx_layout sxaul_sop_opl2 = {UINT32_C(0x60380021),"sop_opl2",sxaul_sop_opl2_fields,SX_COUNT(sxaul_sop_opl2_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sop_opl4_fields[] = {
    SX_FIELD("opl_parameter0","uint8",0,1,SX_FLAGS),
    SX_FIELD("opl_parameter1","uint8",1,1,SX_FLAGS),
    SX_FIELD("opl_parameter2","uint8",2,1,SX_FLAGS),
    SX_FIELD("opl_parameter3","uint8",3,1,SX_FLAGS),
    SX_FIELD("opl_parameter4","uint8",4,1,SX_FLAGS),
    SX_FIELD("opl_parameter5","uint8",5,1,SX_FLAGS),
    SX_FIELD("opl_parameter6","uint8",6,1,SX_FLAGS),
    SX_FIELD("opl_parameter7","uint8",7,1,SX_FLAGS),
    SX_FIELD("opl_parameter8","uint8",8,1,SX_FLAGS),
    SX_FIELD("opl_parameter9","uint8",9,1,SX_FLAGS),
    SX_FIELD("opl_parameter10","uint8",10,1,SX_FLAGS),
    SX_FIELD("opl_parameter11","uint8",11,1,SX_FLAGS),
    SX_FIELD("opl_parameter12","uint8",12,1,SX_FLAGS),
    SX_FIELD("opl_parameter13","uint8",13,1,SX_FLAGS),
    SX_FIELD("opl_parameter14","uint8",14,1,SX_FLAGS),
    SX_FIELD("opl_parameter15","uint8",15,1,SX_FLAGS),
    SX_FIELD("opl_parameter16","uint8",16,1,SX_FLAGS),
    SX_FIELD("opl_parameter17","uint8",17,1,SX_FLAGS),
    SX_FIELD("opl_parameter18","uint8",18,1,SX_FLAGS),
    SX_FIELD("opl_parameter19","uint8",19,1,SX_FLAGS),
    SX_FIELD("opl_parameter20","uint8",20,1,SX_FLAGS),
    SX_FIELD("opl_parameter21","uint8",21,1,SX_FLAGS),
};
static const sx_layout sxaul_sop_opl4 = {UINT32_C(0x60380022),"sop_opl4",sxaul_sop_opl4_fields,SX_COUNT(sxaul_sop_opl4_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sop_sample_fields[] = {
    SX_FIELD("value1","uint16",0,2,SX_NONE),
    SX_FIELD("value2","uint16",2,2,SX_NONE),
    SX_FIELD("sample_bytes","uint16",4,2,SX_SIZE),
    SX_FIELD("value4","uint16",6,2,SX_NONE),
    SX_FIELD("base_frequency","uint16",8,2,SX_NONE),
    SX_FIELD("value6","uint16",10,2,SX_NONE),
    SX_FIELD("value7","uint16",12,2,SX_NONE),
    SX_FIELD("value8","uint8",14,1,SX_NONE),
    SX_FIELD("value9","uint16",15,2,SX_NONE),
    SX_FIELD("value10","uint16",17,2,SX_NONE),
};
static const sx_layout sxaul_sop_sample = {UINT32_C(0x60380023),"sop_sample",sxaul_sop_sample_fields,SX_COUNT(sxaul_sop_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sop_track_fields[] = {
    SX_FIELD("events","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("data_bytes","uint32",2,4,SX_SIZE),
};
static const sx_layout sxaul_sop_track = {UINT32_C(0x60380024),"sop_track",sxaul_sop_track_fields,SX_COUNT(sxaul_sop_track_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sop_event_fields[] = {
    SX_FIELD("delta_ticks","uint16",0,2,SX_NONE),
    SX_FIELD("type","uint8",2,1,SX_ID),
    SX_FIELD("value","uint8",3,1,SX_NONE),
};
static const sx_layout sxaul_sop_event = {UINT32_C(0x60380025),"sop_event",sxaul_sop_event_fields,SX_COUNT(sxaul_sop_event_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sop_duration_fields[] = {
    SX_FIELD("duration_ticks","uint16",0,2,SX_NONE),
};
static const sx_layout sxaul_sop_duration = {UINT32_C(0x60380026),"sop_duration",sxaul_sop_duration_fields,SX_COUNT(sxaul_sop_duration_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_cff_header_fields[] = {
    SX_FIELD("magic","uint8[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version","uint8",16,1,SX_ID),
    SX_FIELD("payload_bytes","uint16",17,2,SX_SIZE),
    SX_FIELD("packed","uint8",19,1,SX_FLAGS),
    SX_FIELD("reserved","uint8[12]",20,12,SX_RESERVED),
};
static const sx_layout sxaul_cff_header = {UINT32_C(0x60380027),"cff_header",sxaul_cff_header_fields,SX_COUNT(sxaul_cff_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_cff_instrument_fields[] = {
    SX_FIELD("opl_parameter0","uint8",0,1,SX_FLAGS),
    SX_FIELD("opl_parameter1","uint8",1,1,SX_FLAGS),
    SX_FIELD("opl_parameter2","uint8",2,1,SX_FLAGS),
    SX_FIELD("opl_parameter3","uint8",3,1,SX_FLAGS),
    SX_FIELD("opl_parameter4","uint8",4,1,SX_FLAGS),
    SX_FIELD("opl_parameter5","uint8",5,1,SX_FLAGS),
    SX_FIELD("opl_parameter6","uint8",6,1,SX_FLAGS),
    SX_FIELD("opl_parameter7","uint8",7,1,SX_FLAGS),
    SX_FIELD("opl_parameter8","uint8",8,1,SX_FLAGS),
    SX_FIELD("opl_parameter9","uint8",9,1,SX_FLAGS),
    SX_FIELD("opl_parameter10","uint8",10,1,SX_FLAGS),
    SX_FIELD("opl_parameter11","uint8",11,1,SX_FLAGS),
    SX_FIELD("name","char[20]",12,20,SX_STRING),
};
static const sx_layout sxaul_cff_instrument = {UINT32_C(0x60380028),"cff_instrument",sxaul_cff_instrument_fields,SX_COUNT(sxaul_cff_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_cff_song_fields[] = {
    SX_FIELD("patterns","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("marker","char[31]",1,31,SX_SIGNATURE),
    SX_FIELD("author","char[20]",32,20,SX_STRING),
    SX_FIELD("title","char[20]",52,20,SX_STRING),
};
static const sx_layout sxaul_cff_song = {UINT32_C(0x60380029),"cff_song",sxaul_cff_song_fields,SX_COUNT(sxaul_cff_song_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_cff_order_tail_fields[] = {
    SX_FIELD("unknown","uint8",0,1,SX_NONE),
};
static const sx_layout sxaul_cff_order_tail = {UINT32_C(0x6038002a),"cff_order_tail",sxaul_cff_order_tail_fields,SX_COUNT(sxaul_cff_order_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_cff_event_fields[] = {
    SX_FIELD("note","uint8",0,1,SX_ID),
    SX_FIELD("effect","uint8",1,1,SX_ID),
    SX_FIELD("parameter","uint8",2,1,SX_NONE),
};
static const sx_layout sxaul_cff_event = {UINT32_C(0x6038002b),"cff_event",sxaul_cff_event_fields,SX_COUNT(sxaul_cff_event_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_msc_header_fields[] = {
    SX_FIELD("magic","uint8[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version","uint16",16,2,SX_ID),
    SX_FIELD("description","char[64]",18,64,SX_STRING),
    SX_FIELD("timer_divisor","uint16",82,2,SX_NONE),
    SX_FIELD("block_count","uint16",84,2,SX_COUNT_PROP),
    SX_FIELD("decoded_block_capacity","uint16",86,2,SX_SIZE),
};
static const sx_layout sxaul_msc_header = {UINT32_C(0x6038002c),"msc_header",sxaul_msc_header_fields,SX_COUNT(sxaul_msc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_msc_block_fields[] = {
    SX_FIELD("encoded_bytes","uint16",0,2,SX_SIZE),
};
static const sx_layout sxaul_msc_block = {UINT32_C(0x6038002d),"msc_block",sxaul_msc_block_fields,SX_COUNT(sxaul_msc_block_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_ims_header_fields[] = {
    SX_FIELD("major_version","uint8",0,1,SX_ID),
    SX_FIELD("minor_version","uint8",1,1,SX_ID),
    SX_FIELD("tune_id","uint32",2,4,SX_ID),
    SX_FIELD("name","char[30]",6,30,SX_STRING),
    SX_FIELD("ticks_per_beat","uint8",36,1,SX_NONE),
    SX_FIELD("beats_per_measure","uint8",37,1,SX_NONE),
    SX_FIELD("total_ticks","uint32",38,4,SX_NONE),
    SX_FIELD("data_bytes","uint32",42,4,SX_SIZE),
    SX_FIELD("commands","uint32",46,4,SX_COUNT_PROP),
    SX_FIELD("reserved50","uint8[8]",50,8,SX_RESERVED),
    SX_FIELD("sound_mode","uint8",58,1,SX_ID),
    SX_FIELD("pitch_bend_range","uint8",59,1,SX_NONE),
    SX_FIELD("basic_tempo","uint16",60,2,SX_NONE),
    SX_FIELD("reserved62","uint8[8]",62,8,SX_RESERVED),
};
static const sx_layout sxaul_ims_header = {UINT32_C(0x6038002e),"ims_header",sxaul_ims_header_fields,SX_COUNT(sxaul_ims_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_ims_timbres_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxaul_ims_timbres = {UINT32_C(0x6038002f),"ims_timbres",sxaul_ims_timbres_fields,SX_COUNT(sxaul_ims_timbres_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_ims_timbre_fields[] = {
    SX_FIELD("name","char[9]",0,9,SX_STRING),
};
static const sx_layout sxaul_ims_timbre = {UINT32_C(0x60380030),"ims_timbre",sxaul_ims_timbre_fields,SX_COUNT(sxaul_ims_timbre_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_mtr_header_fields[] = {
    SX_FIELD("magic","char[10]",0,10,SX_SIGNATURE),
    SX_FIELD("channels_minus_one","ascii_hex[2]",10,2,SX_COUNT_PROP),
    SX_FIELD("separator12","char[1]",12,1,SX_RESERVED),
    SX_FIELD("digital_channels","ascii_hex[2]",13,2,SX_COUNT_PROP),
    SX_FIELD("separator15","char[1]",15,1,SX_RESERVED),
    SX_FIELD("patterns_minus_one","ascii_hex[2]",16,2,SX_COUNT_PROP),
    SX_FIELD("separator18","char[1]",18,1,SX_RESERVED),
    SX_FIELD("orders_minus_one","ascii_hex[2]",19,2,SX_COUNT_PROP),
    SX_FIELD("separator21","char[1]",21,1,SX_RESERVED),
    SX_FIELD("instruments","ascii_hex[2]",22,2,SX_COUNT_PROP),
    SX_FIELD("separator24","char[1]",24,1,SX_RESERVED),
    SX_FIELD("restart_order","ascii_hex[2]",25,2,SX_ID),
    SX_FIELD("separator27","char[1]",27,1,SX_RESERVED),
    SX_FIELD("timer_divisor","ascii_hex[4]",28,4,SX_NONE),
    SX_FIELD("separator32","char[1]",32,1,SX_RESERVED),
    SX_FIELD("payload_bytes","ascii_hex[8]",33,8,SX_SIZE),
    SX_FIELD("padding","char[8]",41,8,SX_RESERVED),
    SX_FIELD("terminator","uint8",49,1,SX_SIGNATURE),
    SX_FIELD("title","char[20]",50,20,SX_STRING),
};
static const sx_layout sxaul_mtr_header = {UINT32_C(0x60380031),"mtr_header",sxaul_mtr_header_fields,SX_COUNT(sxaul_mtr_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_mtr_instrument_fields[] = {
    SX_FIELD("name","char[20]",0,20,SX_STRING),
    SX_FIELD("instrument_type","uint8",20,1,SX_ID),
    SX_FIELD("opl_parameter0","uint8",21,1,SX_FLAGS),
    SX_FIELD("opl_parameter1","uint8",22,1,SX_FLAGS),
    SX_FIELD("opl_parameter2","uint8",23,1,SX_FLAGS),
    SX_FIELD("opl_parameter3","uint8",24,1,SX_FLAGS),
    SX_FIELD("opl_parameter4","uint8",25,1,SX_FLAGS),
    SX_FIELD("opl_parameter5","uint8",26,1,SX_FLAGS),
    SX_FIELD("opl_parameter6","uint8",27,1,SX_FLAGS),
    SX_FIELD("opl_parameter7","uint8",28,1,SX_FLAGS),
    SX_FIELD("opl_parameter8","uint8",29,1,SX_FLAGS),
    SX_FIELD("opl_parameter9","uint8",30,1,SX_FLAGS),
    SX_FIELD("opl_parameter10","uint8",31,1,SX_FLAGS),
    SX_FIELD("opl_parameter11","uint8",32,1,SX_FLAGS),
    SX_FIELD("unused","uint8[31]",33,31,SX_RESERVED),
};
static const sx_layout sxaul_mtr_instrument = {UINT32_C(0x60380032),"mtr_instrument",sxaul_mtr_instrument_fields,SX_COUNT(sxaul_mtr_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_mtr_event_fields[] = {
    SX_FIELD("note","uint8",0,1,SX_FLAGS),
    SX_FIELD("instrument","uint8",1,1,SX_FLAGS),
    SX_FIELD("effect","uint8",2,1,SX_ID),
    SX_FIELD("value","uint8",3,1,SX_NONE),
};
static const sx_layout sxaul_mtr_event = {UINT32_C(0x60380033),"mtr_event",sxaul_mtr_event_fields,SX_COUNT(sxaul_mtr_event_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_mtr_producer_fields[] = {
    SX_FIELD("producer","char[11]",0,11,SX_STRING),
};
static const sx_layout sxaul_mtr_producer = {UINT32_C(0x60380034),"mtr_producer",sxaul_mtr_producer_fields,SX_COUNT(sxaul_mtr_producer_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_parsec_driver_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("interface_version","uint16",4,2,SX_ID),
    SX_FIELD("entry_points","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("format_revision","uint16",8,2,SX_ID),
    SX_FIELD("footer_offset","uint16",10,2,SX_OFFSET),
    SX_FIELD("embedded_magic","char[4]",12,4,SX_SIGNATURE),
    SX_FIELD("flags","uint16",16,2,SX_FLAGS),
    SX_FIELD("reserved","uint8[6]",18,6,SX_RESERVED),
};
static const sx_layout sxaul_parsec_driver_header = {UINT32_C(0x60380035),"parsec_driver_header",sxaul_parsec_driver_header_fields,SX_COUNT(sxaul_parsec_driver_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_palladix_driver_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_ID),
    SX_FIELD("entry_points","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("interfaces","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("footer_offset","uint16",10,2,SX_OFFSET),
    SX_FIELD("module_magic","char[4]",12,4,SX_SIGNATURE),
    SX_FIELD("reserved","uint16[4]",16,8,SX_RESERVED),
};
static const sx_layout sxaul_palladix_driver_header = {UINT32_C(0x60380036),"palladix_driver_header",sxaul_palladix_driver_header_fields,SX_COUNT(sxaul_palladix_driver_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_driver_entry_fields[] = {
    SX_FIELD("entry_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxaul_driver_entry = {UINT32_C(0x60380037),"driver_entry",sxaul_driver_entry_fields,SX_COUNT(sxaul_driver_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_driver_footer_fields[] = {
    SX_FIELD("signature","char[20]",0,20,SX_SIGNATURE),
};
static const sx_layout sxaul_driver_footer = {UINT32_C(0x60380038),"driver_footer",sxaul_driver_footer_fields,SX_COUNT(sxaul_driver_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pma_header_fields[] = {
    SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("mode","uint8",3,1,SX_ID),
    SX_FIELD("speed_scale","uint8",4,1,SX_NONE),
    SX_FIELD("speed","uint16",5,2,SX_NONE),
};
static const sx_layout sxaul_pma_header = {UINT32_C(0x60380039),"pma_header",sxaul_pma_header_fields,SX_COUNT(sxaul_pma_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pma_channel_fields[] = {
    SX_FIELD("channel_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxaul_pma_channel = {UINT32_C(0x6038003a),"pma_channel",sxaul_pma_channel_fields,SX_COUNT(sxaul_pma_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pma_flags_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxaul_pma_flags = {UINT32_C(0x6038003b),"pma_flags",sxaul_pma_flags_fields,SX_COUNT(sxaul_pma_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pma_instrument_fields[] = {
    SX_FIELD("instrument_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxaul_pma_instrument = {UINT32_C(0x6038003c),"pma_instrument",sxaul_pma_instrument_fields,SX_COUNT(sxaul_pma_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pma_byte_fields[] = {
    SX_FIELD("operand","uint8",0,1,SX_NONE),
};
static const sx_layout sxaul_pma_byte = {UINT32_C(0x6038003d),"pma_byte",sxaul_pma_byte_fields,SX_COUNT(sxaul_pma_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pma_word_fields[] = {
    SX_FIELD("operand","uint16",0,2,SX_NONE),
};
static const sx_layout sxaul_pma_word = {UINT32_C(0x6038003e),"pma_word",sxaul_pma_word_fields,SX_COUNT(sxaul_pma_word_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_mdh_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("reserved","uint16",4,2,SX_RESERVED),
    SX_FIELD("track_offset","uint16",6,2,SX_OFFSET),
    SX_FIELD("active_records","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("reserved9","uint8",9,1,SX_RESERVED),
};
static const sx_layout sxaul_mdh_header = {UINT32_C(0x6038003f),"mdh_header",sxaul_mdh_header_fields,SX_COUNT(sxaul_mdh_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_mdh_record_fields[] = {
    SX_FIELD("reserved0","uint8",0,1,SX_RESERVED),
    SX_FIELD("code","uint16",1,2,SX_ID),
    SX_FIELD("reserved3","uint8",3,1,SX_RESERVED),
    SX_FIELD("levels","uint8[4]",4,4,SX_NONE),
};
static const sx_layout sxaul_mdh_record = {UINT32_C(0x60380040),"mdh_record",sxaul_mdh_record_fields,SX_COUNT(sxaul_mdh_record_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_mdh_end_fields[] = {
    SX_FIELD("terminator","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sxaul_mdh_end = {UINT32_C(0x60380041),"mdh_end",sxaul_mdh_end_fields,SX_COUNT(sxaul_mdh_end_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_sm8_header_fields[] = {
    SX_FIELD("magic","char[6]",0,6,SX_SIGNATURE),
    SX_FIELD("pcm_bytes","uint16",6,2,SX_SIZE),
    SX_FIELD("pit_divisor","uint16",8,2,SX_NONE),
};
static const sx_layout sxaul_sm8_header = {UINT32_C(0x60380042),"sm8_header",sxaul_sm8_header_fields,SX_COUNT(sxaul_sm8_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_header_fields[] = {
    SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("version","ascii_decimal[1]",3,1,SX_ID),
    SX_FIELD("newline","char[1]",4,1,SX_RESERVED),
};
static const sx_layout sxaul_pvf_header = {UINT32_C(0x60380043),"pvf_header",sxaul_pvf_header_fields,SX_COUNT(sxaul_pvf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels1_fields[] = {
    SX_FIELD("channels","ascii_decimal[1]",0,1,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels1 = {UINT32_C(0x60380044),"pvf_channels1",sxaul_pvf_channels1_fields,SX_COUNT(sxaul_pvf_channels1_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits1_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[1]",0,1,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits1 = {UINT32_C(0x60380045),"pvf_sample_bits1",sxaul_pvf_sample_bits1_fields,SX_COUNT(sxaul_pvf_sample_bits1_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels2_fields[] = {
    SX_FIELD("channels","ascii_decimal[2]",0,2,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels2 = {UINT32_C(0x60380046),"pvf_channels2",sxaul_pvf_channels2_fields,SX_COUNT(sxaul_pvf_channels2_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits2_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[2]",0,2,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits2 = {UINT32_C(0x60380047),"pvf_sample_bits2",sxaul_pvf_sample_bits2_fields,SX_COUNT(sxaul_pvf_sample_bits2_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels3_fields[] = {
    SX_FIELD("channels","ascii_decimal[3]",0,3,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels3 = {UINT32_C(0x60380048),"pvf_channels3",sxaul_pvf_channels3_fields,SX_COUNT(sxaul_pvf_channels3_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits3_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[3]",0,3,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits3 = {UINT32_C(0x60380049),"pvf_sample_bits3",sxaul_pvf_sample_bits3_fields,SX_COUNT(sxaul_pvf_sample_bits3_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels4_fields[] = {
    SX_FIELD("channels","ascii_decimal[4]",0,4,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels4 = {UINT32_C(0x6038004a),"pvf_channels4",sxaul_pvf_channels4_fields,SX_COUNT(sxaul_pvf_channels4_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate4_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[4]",0,4,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate4 = {UINT32_C(0x6038004b),"pvf_sample_rate4",sxaul_pvf_sample_rate4_fields,SX_COUNT(sxaul_pvf_sample_rate4_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits4_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[4]",0,4,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits4 = {UINT32_C(0x6038004c),"pvf_sample_bits4",sxaul_pvf_sample_bits4_fields,SX_COUNT(sxaul_pvf_sample_bits4_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels5_fields[] = {
    SX_FIELD("channels","ascii_decimal[5]",0,5,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels5 = {UINT32_C(0x6038004d),"pvf_channels5",sxaul_pvf_channels5_fields,SX_COUNT(sxaul_pvf_channels5_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate5_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[5]",0,5,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate5 = {UINT32_C(0x6038004e),"pvf_sample_rate5",sxaul_pvf_sample_rate5_fields,SX_COUNT(sxaul_pvf_sample_rate5_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits5_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[5]",0,5,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits5 = {UINT32_C(0x6038004f),"pvf_sample_bits5",sxaul_pvf_sample_bits5_fields,SX_COUNT(sxaul_pvf_sample_bits5_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels6_fields[] = {
    SX_FIELD("channels","ascii_decimal[6]",0,6,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels6 = {UINT32_C(0x60380050),"pvf_channels6",sxaul_pvf_channels6_fields,SX_COUNT(sxaul_pvf_channels6_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate6_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[6]",0,6,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate6 = {UINT32_C(0x60380051),"pvf_sample_rate6",sxaul_pvf_sample_rate6_fields,SX_COUNT(sxaul_pvf_sample_rate6_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits6_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[6]",0,6,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits6 = {UINT32_C(0x60380052),"pvf_sample_bits6",sxaul_pvf_sample_bits6_fields,SX_COUNT(sxaul_pvf_sample_bits6_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels7_fields[] = {
    SX_FIELD("channels","ascii_decimal[7]",0,7,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels7 = {UINT32_C(0x60380053),"pvf_channels7",sxaul_pvf_channels7_fields,SX_COUNT(sxaul_pvf_channels7_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate7_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[7]",0,7,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate7 = {UINT32_C(0x60380054),"pvf_sample_rate7",sxaul_pvf_sample_rate7_fields,SX_COUNT(sxaul_pvf_sample_rate7_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits7_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[7]",0,7,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits7 = {UINT32_C(0x60380055),"pvf_sample_bits7",sxaul_pvf_sample_bits7_fields,SX_COUNT(sxaul_pvf_sample_bits7_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels8_fields[] = {
    SX_FIELD("channels","ascii_decimal[8]",0,8,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels8 = {UINT32_C(0x60380056),"pvf_channels8",sxaul_pvf_channels8_fields,SX_COUNT(sxaul_pvf_channels8_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate8_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[8]",0,8,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate8 = {UINT32_C(0x60380057),"pvf_sample_rate8",sxaul_pvf_sample_rate8_fields,SX_COUNT(sxaul_pvf_sample_rate8_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits8_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[8]",0,8,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits8 = {UINT32_C(0x60380058),"pvf_sample_bits8",sxaul_pvf_sample_bits8_fields,SX_COUNT(sxaul_pvf_sample_bits8_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels9_fields[] = {
    SX_FIELD("channels","ascii_decimal[9]",0,9,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels9 = {UINT32_C(0x60380059),"pvf_channels9",sxaul_pvf_channels9_fields,SX_COUNT(sxaul_pvf_channels9_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate9_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[9]",0,9,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate9 = {UINT32_C(0x6038005a),"pvf_sample_rate9",sxaul_pvf_sample_rate9_fields,SX_COUNT(sxaul_pvf_sample_rate9_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits9_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[9]",0,9,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits9 = {UINT32_C(0x6038005b),"pvf_sample_bits9",sxaul_pvf_sample_bits9_fields,SX_COUNT(sxaul_pvf_sample_bits9_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels10_fields[] = {
    SX_FIELD("channels","ascii_decimal[10]",0,10,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels10 = {UINT32_C(0x6038005c),"pvf_channels10",sxaul_pvf_channels10_fields,SX_COUNT(sxaul_pvf_channels10_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate10_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[10]",0,10,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate10 = {UINT32_C(0x6038005d),"pvf_sample_rate10",sxaul_pvf_sample_rate10_fields,SX_COUNT(sxaul_pvf_sample_rate10_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits10_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[10]",0,10,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits10 = {UINT32_C(0x6038005e),"pvf_sample_bits10",sxaul_pvf_sample_bits10_fields,SX_COUNT(sxaul_pvf_sample_bits10_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels11_fields[] = {
    SX_FIELD("channels","ascii_decimal[11]",0,11,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels11 = {UINT32_C(0x6038005f),"pvf_channels11",sxaul_pvf_channels11_fields,SX_COUNT(sxaul_pvf_channels11_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate11_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[11]",0,11,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate11 = {UINT32_C(0x60380060),"pvf_sample_rate11",sxaul_pvf_sample_rate11_fields,SX_COUNT(sxaul_pvf_sample_rate11_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits11_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[11]",0,11,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits11 = {UINT32_C(0x60380061),"pvf_sample_bits11",sxaul_pvf_sample_bits11_fields,SX_COUNT(sxaul_pvf_sample_bits11_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels12_fields[] = {
    SX_FIELD("channels","ascii_decimal[12]",0,12,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels12 = {UINT32_C(0x60380062),"pvf_channels12",sxaul_pvf_channels12_fields,SX_COUNT(sxaul_pvf_channels12_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate12_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[12]",0,12,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate12 = {UINT32_C(0x60380063),"pvf_sample_rate12",sxaul_pvf_sample_rate12_fields,SX_COUNT(sxaul_pvf_sample_rate12_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits12_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[12]",0,12,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits12 = {UINT32_C(0x60380064),"pvf_sample_bits12",sxaul_pvf_sample_bits12_fields,SX_COUNT(sxaul_pvf_sample_bits12_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels13_fields[] = {
    SX_FIELD("channels","ascii_decimal[13]",0,13,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels13 = {UINT32_C(0x60380065),"pvf_channels13",sxaul_pvf_channels13_fields,SX_COUNT(sxaul_pvf_channels13_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate13_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[13]",0,13,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate13 = {UINT32_C(0x60380066),"pvf_sample_rate13",sxaul_pvf_sample_rate13_fields,SX_COUNT(sxaul_pvf_sample_rate13_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits13_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[13]",0,13,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits13 = {UINT32_C(0x60380067),"pvf_sample_bits13",sxaul_pvf_sample_bits13_fields,SX_COUNT(sxaul_pvf_sample_bits13_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels14_fields[] = {
    SX_FIELD("channels","ascii_decimal[14]",0,14,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels14 = {UINT32_C(0x60380068),"pvf_channels14",sxaul_pvf_channels14_fields,SX_COUNT(sxaul_pvf_channels14_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate14_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[14]",0,14,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate14 = {UINT32_C(0x60380069),"pvf_sample_rate14",sxaul_pvf_sample_rate14_fields,SX_COUNT(sxaul_pvf_sample_rate14_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits14_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[14]",0,14,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits14 = {UINT32_C(0x6038006a),"pvf_sample_bits14",sxaul_pvf_sample_bits14_fields,SX_COUNT(sxaul_pvf_sample_bits14_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels15_fields[] = {
    SX_FIELD("channels","ascii_decimal[15]",0,15,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels15 = {UINT32_C(0x6038006b),"pvf_channels15",sxaul_pvf_channels15_fields,SX_COUNT(sxaul_pvf_channels15_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate15_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[15]",0,15,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate15 = {UINT32_C(0x6038006c),"pvf_sample_rate15",sxaul_pvf_sample_rate15_fields,SX_COUNT(sxaul_pvf_sample_rate15_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits15_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[15]",0,15,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits15 = {UINT32_C(0x6038006d),"pvf_sample_bits15",sxaul_pvf_sample_bits15_fields,SX_COUNT(sxaul_pvf_sample_bits15_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels16_fields[] = {
    SX_FIELD("channels","ascii_decimal[16]",0,16,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels16 = {UINT32_C(0x6038006e),"pvf_channels16",sxaul_pvf_channels16_fields,SX_COUNT(sxaul_pvf_channels16_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate16_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[16]",0,16,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate16 = {UINT32_C(0x6038006f),"pvf_sample_rate16",sxaul_pvf_sample_rate16_fields,SX_COUNT(sxaul_pvf_sample_rate16_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits16_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[16]",0,16,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits16 = {UINT32_C(0x60380070),"pvf_sample_bits16",sxaul_pvf_sample_bits16_fields,SX_COUNT(sxaul_pvf_sample_bits16_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels17_fields[] = {
    SX_FIELD("channels","ascii_decimal[17]",0,17,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels17 = {UINT32_C(0x60380071),"pvf_channels17",sxaul_pvf_channels17_fields,SX_COUNT(sxaul_pvf_channels17_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate17_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[17]",0,17,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate17 = {UINT32_C(0x60380072),"pvf_sample_rate17",sxaul_pvf_sample_rate17_fields,SX_COUNT(sxaul_pvf_sample_rate17_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits17_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[17]",0,17,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits17 = {UINT32_C(0x60380073),"pvf_sample_bits17",sxaul_pvf_sample_bits17_fields,SX_COUNT(sxaul_pvf_sample_bits17_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels18_fields[] = {
    SX_FIELD("channels","ascii_decimal[18]",0,18,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels18 = {UINT32_C(0x60380074),"pvf_channels18",sxaul_pvf_channels18_fields,SX_COUNT(sxaul_pvf_channels18_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate18_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[18]",0,18,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate18 = {UINT32_C(0x60380075),"pvf_sample_rate18",sxaul_pvf_sample_rate18_fields,SX_COUNT(sxaul_pvf_sample_rate18_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits18_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[18]",0,18,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits18 = {UINT32_C(0x60380076),"pvf_sample_bits18",sxaul_pvf_sample_bits18_fields,SX_COUNT(sxaul_pvf_sample_bits18_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels19_fields[] = {
    SX_FIELD("channels","ascii_decimal[19]",0,19,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels19 = {UINT32_C(0x60380077),"pvf_channels19",sxaul_pvf_channels19_fields,SX_COUNT(sxaul_pvf_channels19_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate19_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[19]",0,19,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate19 = {UINT32_C(0x60380078),"pvf_sample_rate19",sxaul_pvf_sample_rate19_fields,SX_COUNT(sxaul_pvf_sample_rate19_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits19_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[19]",0,19,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits19 = {UINT32_C(0x60380079),"pvf_sample_bits19",sxaul_pvf_sample_bits19_fields,SX_COUNT(sxaul_pvf_sample_bits19_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels20_fields[] = {
    SX_FIELD("channels","ascii_decimal[20]",0,20,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels20 = {UINT32_C(0x6038007a),"pvf_channels20",sxaul_pvf_channels20_fields,SX_COUNT(sxaul_pvf_channels20_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate20_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[20]",0,20,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate20 = {UINT32_C(0x6038007b),"pvf_sample_rate20",sxaul_pvf_sample_rate20_fields,SX_COUNT(sxaul_pvf_sample_rate20_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits20_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[20]",0,20,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits20 = {UINT32_C(0x6038007c),"pvf_sample_bits20",sxaul_pvf_sample_bits20_fields,SX_COUNT(sxaul_pvf_sample_bits20_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels21_fields[] = {
    SX_FIELD("channels","ascii_decimal[21]",0,21,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels21 = {UINT32_C(0x6038007d),"pvf_channels21",sxaul_pvf_channels21_fields,SX_COUNT(sxaul_pvf_channels21_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate21_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[21]",0,21,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate21 = {UINT32_C(0x6038007e),"pvf_sample_rate21",sxaul_pvf_sample_rate21_fields,SX_COUNT(sxaul_pvf_sample_rate21_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits21_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[21]",0,21,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits21 = {UINT32_C(0x6038007f),"pvf_sample_bits21",sxaul_pvf_sample_bits21_fields,SX_COUNT(sxaul_pvf_sample_bits21_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels22_fields[] = {
    SX_FIELD("channels","ascii_decimal[22]",0,22,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels22 = {UINT32_C(0x60380080),"pvf_channels22",sxaul_pvf_channels22_fields,SX_COUNT(sxaul_pvf_channels22_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate22_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[22]",0,22,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate22 = {UINT32_C(0x60380081),"pvf_sample_rate22",sxaul_pvf_sample_rate22_fields,SX_COUNT(sxaul_pvf_sample_rate22_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits22_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[22]",0,22,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits22 = {UINT32_C(0x60380082),"pvf_sample_bits22",sxaul_pvf_sample_bits22_fields,SX_COUNT(sxaul_pvf_sample_bits22_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels23_fields[] = {
    SX_FIELD("channels","ascii_decimal[23]",0,23,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels23 = {UINT32_C(0x60380083),"pvf_channels23",sxaul_pvf_channels23_fields,SX_COUNT(sxaul_pvf_channels23_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate23_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[23]",0,23,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate23 = {UINT32_C(0x60380084),"pvf_sample_rate23",sxaul_pvf_sample_rate23_fields,SX_COUNT(sxaul_pvf_sample_rate23_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits23_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[23]",0,23,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits23 = {UINT32_C(0x60380085),"pvf_sample_bits23",sxaul_pvf_sample_bits23_fields,SX_COUNT(sxaul_pvf_sample_bits23_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_channels24_fields[] = {
    SX_FIELD("channels","ascii_decimal[24]",0,24,SX_COUNT_PROP),
};
static const sx_layout sxaul_pvf_channels24 = {UINT32_C(0x60380086),"pvf_channels24",sxaul_pvf_channels24_fields,SX_COUNT(sxaul_pvf_channels24_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_rate24_fields[] = {
    SX_FIELD("sample_rate","ascii_decimal[24]",0,24,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_rate24 = {UINT32_C(0x60380087),"pvf_sample_rate24",sxaul_pvf_sample_rate24_fields,SX_COUNT(sxaul_pvf_sample_rate24_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_pvf_sample_bits24_fields[] = {
    SX_FIELD("sample_bits","ascii_decimal[24]",0,24,SX_NONE),
};
static const sx_layout sxaul_pvf_sample_bits24 = {UINT32_C(0x60380088),"pvf_sample_bits24",sxaul_pvf_sample_bits24_fields,SX_COUNT(sxaul_pvf_sample_bits24_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_swa_header_fields[] = {
    SX_FIELD("header_bytes","uint32",0,4,SX_SIZE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("sample_rate","uint32",8,4,SX_NONE),
    SX_FIELD("unknown12","uint8[24]",12,24,SX_NONE),
    SX_FIELD("marker","char[5]",36,5,SX_SIGNATURE),
};
static const sx_layout sxaul_swa_header = {UINT32_C(0x60380089),"swa_header",sxaul_swa_header_fields,SX_COUNT(sxaul_swa_header_fields),SX_BE};
static const xx_data_struct_field_desc sxaul_swa_frame_fields[] = {
    SX_FIELD("mpeg_header","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxaul_swa_frame = {UINT32_C(0x6038008a),"swa_frame",sxaul_swa_frame_fields,SX_COUNT(sxaul_swa_frame_fields),SX_BE};
static const xx_data_struct_field_desc sxaul_hmi_header_fields[] = {
    SX_FIELD("magic","char[18]",0,18,SX_SIGNATURE),
    SX_FIELD("opaque_12","uint8[194]",18,194,SX_NONE),
    SX_FIELD("beats_per_minute","uint8",212,1,SX_NONE),
    SX_FIELD("opaque_d5","uint8[15]",213,15,SX_NONE),
    SX_FIELD("track_count","uint8",228,1,SX_COUNT_PROP),
    SX_FIELD("opaque_e5","uint8[141]",229,141,SX_NONE),
};
static const sx_layout sxaul_hmi_header = {UINT32_C(0x6038008b),"hmi_header",sxaul_hmi_header_fields,SX_COUNT(sxaul_hmi_header_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_hmi_track_offset_fields[] = {
    SX_FIELD("track_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxaul_hmi_track_offset = {UINT32_C(0x6038008c),"hmi_track_offset",sxaul_hmi_track_offset_fields,SX_COUNT(sxaul_hmi_track_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxaul_hmi_track_fields[] = {
    SX_FIELD("magic","char[13]",0,13,SX_SIGNATURE),
    SX_FIELD("opaque_d","uint8[74]",13,74,SX_NONE),
    SX_FIELD("header_bytes","uint32",87,4,SX_SIZE),
};
static const sx_layout sxaul_hmi_track = {UINT32_C(0x6038008d),"hmi_track",sxaul_hmi_track_fields,SX_COUNT(sxaul_hmi_track_fields),SX_LE};
static const sx_layout *const sx_audiolater_layouts[] = {
    &sxaul_amd_header,
    &sxaul_amd_instrument,
    &sxaul_amd_orders,
    &sxaul_amd_event,
    &sxaul_amd_empty_run,
    &sxaul_track_u16,
    &sxaul_count_u16,
    &sxaul_order_u8,
    &sxaul_mkj_header,
    &sxaul_mkj_instrument,
    &sxaul_mkj_channel_enabled,
    &sxaul_mkj_event,
    &sxaul_sa2_header,
    &sxaul_sa2_instrument,
    &sxaul_sa2_name,
    &sxaul_sa2_names_padding,
    &sxaul_sa2_song,
    &sxaul_sa2_arpeggio,
    &sxaul_sa2_arpcommand,
    &sxaul_sa2_track,
    &sxaul_sa2_channels,
    &sxaul_sa2_event,
    &sxaul_fmc_header,
    &sxaul_fmc_order_padding,
    &sxaul_fmc_instrument,
    &sxaul_fmc_event,
    &sxaul_rix_header,
    &sxaul_rix_instrument,
    &sxaul_rix_event,
    &sxaul_sop_header,
    &sxaul_sop_channel_mode,
    &sxaul_sop_instrument,
    &sxaul_sop_opl2,
    &sxaul_sop_opl4,
    &sxaul_sop_sample,
    &sxaul_sop_track,
    &sxaul_sop_event,
    &sxaul_sop_duration,
    &sxaul_cff_header,
    &sxaul_cff_instrument,
    &sxaul_cff_song,
    &sxaul_cff_order_tail,
    &sxaul_cff_event,
    &sxaul_msc_header,
    &sxaul_msc_block,
    &sxaul_ims_header,
    &sxaul_ims_timbres,
    &sxaul_ims_timbre,
    &sxaul_mtr_header,
    &sxaul_mtr_instrument,
    &sxaul_mtr_event,
    &sxaul_mtr_producer,
    &sxaul_parsec_driver_header,
    &sxaul_palladix_driver_header,
    &sxaul_driver_entry,
    &sxaul_driver_footer,
    &sxaul_pma_header,
    &sxaul_pma_channel,
    &sxaul_pma_flags,
    &sxaul_pma_instrument,
    &sxaul_pma_byte,
    &sxaul_pma_word,
    &sxaul_mdh_header,
    &sxaul_mdh_record,
    &sxaul_mdh_end,
    &sxaul_sm8_header,
    &sxaul_pvf_header,
    &sxaul_pvf_channels1,
    &sxaul_pvf_sample_bits1,
    &sxaul_pvf_channels2,
    &sxaul_pvf_sample_bits2,
    &sxaul_pvf_channels3,
    &sxaul_pvf_sample_bits3,
    &sxaul_pvf_channels4,
    &sxaul_pvf_sample_rate4,
    &sxaul_pvf_sample_bits4,
    &sxaul_pvf_channels5,
    &sxaul_pvf_sample_rate5,
    &sxaul_pvf_sample_bits5,
    &sxaul_pvf_channels6,
    &sxaul_pvf_sample_rate6,
    &sxaul_pvf_sample_bits6,
    &sxaul_pvf_channels7,
    &sxaul_pvf_sample_rate7,
    &sxaul_pvf_sample_bits7,
    &sxaul_pvf_channels8,
    &sxaul_pvf_sample_rate8,
    &sxaul_pvf_sample_bits8,
    &sxaul_pvf_channels9,
    &sxaul_pvf_sample_rate9,
    &sxaul_pvf_sample_bits9,
    &sxaul_pvf_channels10,
    &sxaul_pvf_sample_rate10,
    &sxaul_pvf_sample_bits10,
    &sxaul_pvf_channels11,
    &sxaul_pvf_sample_rate11,
    &sxaul_pvf_sample_bits11,
    &sxaul_pvf_channels12,
    &sxaul_pvf_sample_rate12,
    &sxaul_pvf_sample_bits12,
    &sxaul_pvf_channels13,
    &sxaul_pvf_sample_rate13,
    &sxaul_pvf_sample_bits13,
    &sxaul_pvf_channels14,
    &sxaul_pvf_sample_rate14,
    &sxaul_pvf_sample_bits14,
    &sxaul_pvf_channels15,
    &sxaul_pvf_sample_rate15,
    &sxaul_pvf_sample_bits15,
    &sxaul_pvf_channels16,
    &sxaul_pvf_sample_rate16,
    &sxaul_pvf_sample_bits16,
    &sxaul_pvf_channels17,
    &sxaul_pvf_sample_rate17,
    &sxaul_pvf_sample_bits17,
    &sxaul_pvf_channels18,
    &sxaul_pvf_sample_rate18,
    &sxaul_pvf_sample_bits18,
    &sxaul_pvf_channels19,
    &sxaul_pvf_sample_rate19,
    &sxaul_pvf_sample_bits19,
    &sxaul_pvf_channels20,
    &sxaul_pvf_sample_rate20,
    &sxaul_pvf_sample_bits20,
    &sxaul_pvf_channels21,
    &sxaul_pvf_sample_rate21,
    &sxaul_pvf_sample_bits21,
    &sxaul_pvf_channels22,
    &sxaul_pvf_sample_rate22,
    &sxaul_pvf_sample_bits22,
    &sxaul_pvf_channels23,
    &sxaul_pvf_sample_rate23,
    &sxaul_pvf_sample_bits23,
    &sxaul_pvf_channels24,
    &sxaul_pvf_sample_rate24,
    &sxaul_pvf_sample_bits24,
    &sxaul_swa_header,
    &sxaul_swa_frame,
    &sxaul_hmi_header,
    &sxaul_hmi_track_offset,
    &sxaul_hmi_track,
    &sxaul_sfark_header,
    &sxaul_sfark_name_byte,
    &sxaul_sfark_text,
    &sxaul_sfpack_header,
    &sxaul_sfpack_chunk,
    &sxaul_sfpack_skip,
    &sxaul_sfpack_table,
    &sxaul_sfpack_offset,
    &sxaul_ap4_table,
    &sxaul_ap4_entry,
};
static bool sx_audiolater_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60380000U||id>=0x60390000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x60380002U:
        if(!xx_rt_wcscmp(r->name,L"opl_parameter0"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter1"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter2"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter3"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter4"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter5"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter6"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter7"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter8"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter9"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter10"))text=L"Stored OPL parameter byte; preserve physical register order.";
        break;
    case 0x60380003U:
        if(!xx_rt_wcscmp(r->name,L"pattern_count_minus_one"))text=L"Stored count minus one.";
        if(!xx_rt_wcscmp(r->name,L"version"))text=L"0x10=unpacked patterns;0x11=packed tracks.";
        break;
    case 0x60380004U:
        if(!xx_rt_wcscmp(r->name,L"decimal_parameter"))text=L"Low7 bits hold a decimal effect parameter.";
        if(!xx_rt_wcscmp(r->name,L"instrument_effect"))text=L"High nibble:low instrument bits;low nibble:effect.";
        if(!xx_rt_wcscmp(r->name,L"note_instrument"))text=L"Bit0:high instrument bit;bits1..3:octave;bits4..7:note.";
        break;
    case 0x60380005U:
        if(!xx_rt_wcscmp(r->name,L"empty_row_run"))text=L"Bit7 marks a run;low7 bits give its row count.";
        break;
    case 0x60380009U:
        if(!xx_rt_wcscmp(r->name,L"version"))text=L"Native reader currently accepts1.0.";
        break;
    case 0x6038000aU:
        if(!xx_rt_wcscmp(r->name,L"opl_parameter0"))text=L"Stored16-bit word;native values restricted to8 bits.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter1"))text=L"Stored16-bit word;native values restricted to8 bits.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter2"))text=L"Stored16-bit word;native values restricted to8 bits.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter3"))text=L"Stored16-bit word;native values restricted to8 bits.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter4"))text=L"Stored16-bit word;native values restricted to8 bits.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter5"))text=L"Stored16-bit word;native values restricted to8 bits.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter6"))text=L"Stored16-bit word;native values restricted to8 bits.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter7"))text=L"Stored16-bit word;native values restricted to8 bits.";
        break;
    case 0x6038000dU:
        if(!xx_rt_wcscmp(r->name,L"version"))text=L"Native reader accepts version9.";
        break;
    case 0x6038000eU:
        if(!xx_rt_wcscmp(r->name,L"opl_parameter0"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter1"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter2"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter3"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter4"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter5"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter6"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter7"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter8"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter9"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter10"))text=L"Stored OPL parameter byte; preserve physical register order.";
        break;
    case 0x60380016U:
        if(!xx_rt_wcscmp(r->name,L"note_instrument"))text=L"Bits1..7:note;bit0:high instrument bit.";
        if(!xx_rt_wcscmp(r->name,L"instrument_effect"))text=L"High nibble:low instrument bits;low nibble:effect.";
        if(!xx_rt_wcscmp(r->name,L"parameter"))text=L"Two effect-parameter nibbles.";
        break;
    case 0x6038001aU:
        if(!xx_rt_wcscmp(r->name,L"note_instrument"))text=L"Bits0..6:note;bit7:high instrument bit.";
        if(!xx_rt_wcscmp(r->name,L"instrument_effect"))text=L"High nibble:low instrument bits;low nibble:effect.";
        if(!xx_rt_wcscmp(r->name,L"parameter"))text=L"Two effect-parameter nibbles.";
        break;
    case 0x6038001dU:
        if(!xx_rt_wcscmp(r->name,L"opcode"))text=L"High<0x80:delay word;0x80:stop;0x90..0xc0:command,low nibble channel.";
        break;
    case 0x6038001fU:
        if(!xx_rt_wcscmp(r->name,L"mode"))text=L"Low7 bits:channel mode;bit7 retains stored flag.";
        break;
    case 0x60380020U:
        if(!xx_rt_wcscmp(r->name,L"type"))text=L"0=4OP,1=2OP,6..10=percussion,11=sample,12=empty.";
        break;
    case 0x60380021U:
        if(!xx_rt_wcscmp(r->name,L"opl_parameter0"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter1"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter2"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter3"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter4"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter5"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter6"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter7"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter8"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter9"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter10"))text=L"Stored OPL parameter byte; preserve physical register order.";
        break;
    case 0x60380022U:
        if(!xx_rt_wcscmp(r->name,L"opl_parameter0"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter1"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter2"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter3"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter4"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter5"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter6"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter7"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter8"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter9"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter10"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter11"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter12"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter13"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter14"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter15"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter16"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter17"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter18"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter19"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter20"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter21"))text=L"Stored OPL parameter byte; preserve physical register order.";
        break;
    case 0x60380028U:
        if(!xx_rt_wcscmp(r->name,L"opl_parameter0"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter1"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter2"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter3"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter4"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter5"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter6"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter7"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter8"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter9"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter10"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter11"))text=L"Stored OPL parameter byte; preserve physical register order.";
        break;
    case 0x6038002bU:
        if(!xx_rt_wcscmp(r->name,L"effect"))text=L"ASCII effect letter or zero.";
        break;
    case 0x60380031U:
        if(!xx_rt_wcscmp(r->name,L"channels_minus_one"))text=L"Stored count minus one.";
        if(!xx_rt_wcscmp(r->name,L"patterns_minus_one"))text=L"Stored count minus one.";
        if(!xx_rt_wcscmp(r->name,L"orders_minus_one"))text=L"Stored count minus one.";
        if(!xx_rt_wcscmp(r->name,L"payload_bytes"))text=L"Stored byte size after the50-byte prefix.";
        break;
    case 0x60380032U:
        if(!xx_rt_wcscmp(r->name,L"instrument_type"))text=L"0/1/2;2 selects the OPL bank.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter0"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter1"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter2"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter3"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter4"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter5"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter6"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter7"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter8"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter9"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter10"))text=L"Stored OPL parameter byte; preserve physical register order.";
        if(!xx_rt_wcscmp(r->name,L"opl_parameter11"))text=L"Stored OPL parameter byte; preserve physical register order.";
        break;
    case 0x60380033U:
        if(!xx_rt_wcscmp(r->name,L"note"))text=L"Low nibble:note;high nibble:octave.";
        if(!xx_rt_wcscmp(r->name,L"instrument"))text=L"Low6 bits:instrument.";
        break;
    case 0x6038003aU:
        if(!xx_rt_wcscmp(r->name,L"channel_offset"))text=L"Zero means the channel is inactive; nonzero offsets are relative to the file base.";
        break;
    case 0x6038003bU:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Zero ends channel;0x80 is a delay-only event;other bits select operands.";
        break;
    case 0x60380042U:
        if(!xx_rt_wcscmp(r->name,L"pit_divisor"))text=L"Original PIT clock divisor; samples are unsigned 8-bit mono PCM.";
        break;
    case 0x60380043U:
        if(!xx_rt_wcscmp(r->name,L"version"))text=L"1=binary big-endian PCM;2=ASCII decimal samples.";
        break;
    case 0x60380089U:
        if(!xx_rt_wcscmp(r->name,L"header_bytes"))text=L"Measured from byte4; MPEG payload starts at header_bytes+4.";
        break;
    case 0x6038008aU:
        if(!xx_rt_wcscmp(r->name,L"mpeg_header"))text=L"Stored MPEG LayerIII frame header; compressed frame payload remains raw.";
        break;
    case 0x6038008dU:
        if(!xx_rt_wcscmp(r->name,L"header_bytes"))text=L"Track-relative event-data offset; opaque header extension remains raw.";
        break;
    case 0x6038008eU:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit0=notes present;bit1=license present.";
        if(!xx_rt_wcscmp(r->name,L"compressed_bytes"))text=L"Informational stored value.";
        if(!xx_rt_wcscmp(r->name,L"header_checksum"))text=L"Adler32 seed0 over header and NUL filename, with checksum bytes zeroed.";
        if(!xx_rt_wcscmp(r->name,L"method"))text=L"4=fast,5=standard,6=LPC8,7=LPC128.";
        if(!xx_rt_wcscmp(r->name,L"audio_start"))text=L"Offset in the decoded SoundFont, not this physical file.";
        if(!xx_rt_wcscmp(r->name,L"post_audio_start"))text=L"Offset in the decoded SoundFont, not this physical file.";
        break;
    case 0x60380091U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit0=notes,bit1=license,bit2=encryption.";
        if(!xx_rt_wcscmp(r->name,L"declared_sf2_bytes"))text=L"Advisory output size; decoder measures actual output.";
        break;
    case 0x60380092U:
        if(!xx_rt_wcscmp(r->name,L"chunk_bytes"))text=L"Bytes after this length field, including tag and output length.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}
/* Native component boundaries are retained; encoded streams and samples stay raw. */
uint32_t sxaul_num(sx_context*c,int64_t at,unsigned width,bool be){uint8_t b[4];if(!width||width>4||!sx_read(c,at,b,width)){c->failed=true;return 0;}uint32_t v=0;for(unsigned i=0;i<width;i++)v|=(uint32_t)b[i]<<(8*(be?width-1-i:i));return v;}
bool sxaul_take(sx_context*c,const sx_layout*l,int64_t*at,int64_t end,uint64_t count){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t width=(uint64_t)(f->rel_offset+f->size);if(*at<0||end<*at||!width||count>(uint64_t)(end-*at)/width)return false;if(count&&c->count<32000&&!sx_table(c,l,*at,(int64_t)width,count>65536?65536:count))return false;*at+=(int64_t)(count*width);return !c->failed&&!xx_pd_is_stopped(c->pd);}
bool sxaul_skip(int64_t*at,int64_t end,uint64_t n){if(*at<0||end<*at||n>(uint64_t)(end-*at))return false;*at+=(int64_t)n;return true;}
static bool sxaul_eq(const char*a,const char*b){return !xx_rt_strcmp(a,b);}
static bool sxaul_prefix(const char*a,const char*b){return !xx_rt_strncmp(a,b,xx_rt_strlen(b));}
#define AL(n,k) do{if(!sxaul_take(c,&sxaul_##n,&at,end,(k)))return false;}while(0)
#define SK(n) do{if(!sxaul_skip(&at,end,(n)))return false;}while(0)
#define N(p,w) sxaul_num(c,(p),(w),false)
#define B(p,w) sxaul_num(c,(p),(w),true)
#define EQ(n) sxaul_eq(name,(n))
static const sx_layout *const sxaul_pvf_numbers[3][24]={
 {&sxaul_pvf_channels1,&sxaul_pvf_channels2,&sxaul_pvf_channels3,&sxaul_pvf_channels4,&sxaul_pvf_channels5,&sxaul_pvf_channels6,&sxaul_pvf_channels7,&sxaul_pvf_channels8,&sxaul_pvf_channels9,&sxaul_pvf_channels10,&sxaul_pvf_channels11,&sxaul_pvf_channels12,&sxaul_pvf_channels13,&sxaul_pvf_channels14,&sxaul_pvf_channels15,&sxaul_pvf_channels16,&sxaul_pvf_channels17,&sxaul_pvf_channels18,&sxaul_pvf_channels19,&sxaul_pvf_channels20,&sxaul_pvf_channels21,&sxaul_pvf_channels22,&sxaul_pvf_channels23,&sxaul_pvf_channels24},
 {NULL,NULL,NULL,&sxaul_pvf_sample_rate4,&sxaul_pvf_sample_rate5,&sxaul_pvf_sample_rate6,&sxaul_pvf_sample_rate7,&sxaul_pvf_sample_rate8,&sxaul_pvf_sample_rate9,&sxaul_pvf_sample_rate10,&sxaul_pvf_sample_rate11,&sxaul_pvf_sample_rate12,&sxaul_pvf_sample_rate13,&sxaul_pvf_sample_rate14,&sxaul_pvf_sample_rate15,&sxaul_pvf_sample_rate16,&sxaul_pvf_sample_rate17,&sxaul_pvf_sample_rate18,&sxaul_pvf_sample_rate19,&sxaul_pvf_sample_rate20,&sxaul_pvf_sample_rate21,&sxaul_pvf_sample_rate22,&sxaul_pvf_sample_rate23,&sxaul_pvf_sample_rate24},
 {&sxaul_pvf_sample_bits1,&sxaul_pvf_sample_bits2,&sxaul_pvf_sample_bits3,&sxaul_pvf_sample_bits4,&sxaul_pvf_sample_bits5,&sxaul_pvf_sample_bits6,&sxaul_pvf_sample_bits7,&sxaul_pvf_sample_bits8,&sxaul_pvf_sample_bits9,&sxaul_pvf_sample_bits10,&sxaul_pvf_sample_bits11,&sxaul_pvf_sample_bits12,&sxaul_pvf_sample_bits13,&sxaul_pvf_sample_bits14,&sxaul_pvf_sample_bits15,&sxaul_pvf_sample_bits16,&sxaul_pvf_sample_bits17,&sxaul_pvf_sample_bits18,&sxaul_pvf_sample_bits19,&sxaul_pvf_sample_bits20,&sxaul_pvf_sample_bits21,&sxaul_pvf_sample_bits22,&sxaul_pvf_sample_bits23,&sxaul_pvf_sample_bits24},
};
static bool sxaul_component(sx_context*c,const char*name,int64_t at,int64_t size)
{
 int64_t end=at+size;uint32_t n;switch(c->f->file_type){
 case XX_FILE_TYPE_ADLIB_AMD:
  if(EQ("descriptor.amd")){AL(amd_header,1);}
  else if(EQ("instruments.amd")){AL(amd_instrument,26);}
  else if(EQ("orders.amd")){AL(amd_orders,1);}
  else if(EQ("pattern.amd")){AL(amd_event,size/3);}
  else if(EQ("track-map.amd")){AL(track_u16,(size-2)/2);AL(count_u16,1);}
  else if(EQ("track.amd")){AL(track_u16,1);while(at<end){n=N(at,1);if(n&128){AL(amd_empty_run,1);}else{AL(amd_event,1);}}}break;
 case XX_FILE_TYPE_ADLIB_MKJ:
  if(EQ("descriptor.mkj")){AL(mkj_header,1);}else if(EQ("instrument.mkj")){AL(mkj_instrument,1);}
  else if(EQ("channel-table.mkj")){AL(count_u16,1);AL(mkj_channel_enabled,(size-2)/2);}
  else if(EQ("event-grid.mkj")){AL(mkj_event,size/2);}break;
 case XX_FILE_TYPE_ADLIB_SA2:
  if(EQ("descriptor.sa2")){AL(sa2_header,1);}else if(EQ("instrument.sa2")){AL(sa2_instrument,1);}
  else if(EQ("instrument-names.sa2")){AL(sa2_name,29);AL(sa2_names_padding,1);}
  else if(EQ("orders.sa2")){AL(order_u8,128);}else if(EQ("song-info.sa2")){AL(sa2_song,1);}
  else if(EQ("arpeggios.sa2")){AL(sa2_arpeggio,256);AL(sa2_arpcommand,256);}
  else if(EQ("track-map.sa2")){AL(sa2_track,576);}else if(EQ("active-channels.sa2")){AL(sa2_channels,1);}
  else if(EQ("track.sa2")){AL(sa2_event,size/3);}break;
 case XX_FILE_TYPE_FAUST_FMC:
  if(EQ("descriptor.fmc")){AL(fmc_header,1);}else if(EQ("orders.fmc")){AL(order_u8,256);AL(fmc_order_padding,1);}
  else if(EQ("instrument.fmc")){AL(fmc_instrument,1);}else if(EQ("pattern.fmc")){AL(fmc_event,size/3);}break;
 case XX_FILE_TYPE_SOFTSTAR_RIX:
  if(EQ("descriptor.rix")){AL(rix_header,1);}else if(EQ("instrument.rix")){AL(rix_instrument,1);}
  else if(EQ("event-stream.rix")){AL(rix_event,size/2);}break;
 case XX_FILE_TYPE_ADLIB_SOP:
  if(EQ("descriptor.sop")){AL(sop_header,1);}else if(EQ("channel-modes.sop")){AL(sop_channel_mode,size);}
  else if(EQ("instrument.sop")){n=N(at,1);AL(sop_instrument,1);if(!n){AL(sop_opl4,1);}else if(n==11){AL(sop_sample,1);}else if(n!=12){AL(sop_opl2,1);}}
  else if(EQ("control-track.sop")||EQ("event-track.sop")){AL(sop_track,1);while(at<end){n=N(at+2,1);AL(sop_event,1);if(n==2){AL(sop_duration,1);}}}break;
 case XX_FILE_TYPE_CUDFM_CFF:
  if(EQ("descriptor.cff")){AL(cff_header,1);}else if(EQ("instrument.cff")){AL(cff_instrument,1);}
  else if(EQ("song-info.cff")){AL(cff_song,1);}else if(EQ("orders.cff")){AL(order_u8,64);AL(cff_order_tail,1);}
  else if(EQ("pattern.cff")){AL(cff_event,size/3);}break;
 case XX_FILE_TYPE_CERES_MSC:
  if(EQ("descriptor.msc")){AL(msc_header,1);}else if(EQ("encoded-commands.msc")){AL(msc_block,1);}break;
 case XX_FILE_TYPE_IMPLAY_MUSIC:
  if(EQ("descriptor.ims")){AL(ims_header,1);}else if(EQ("timbre-names.ims")){n=N(at+2,2);AL(ims_timbres,1);AL(ims_timbre,n);}break;
 case XX_FILE_TYPE_ADLIB_MTR:
  if(EQ("descriptor.mtr")){AL(mtr_header,1);}else if(EQ("orders.mtr")){AL(order_u8,size);}
  else if(EQ("instrument.mtr")){AL(mtr_instrument,1);}else if(EQ("pattern.mtr")){AL(mtr_event,size/4);}
  else if(EQ("producer-tag.mtr")){AL(mtr_producer,1);}break;
 case XX_FILE_TYPE_PARSEC_DTC:case XX_FILE_TYPE_PARSEC_DMA:
  if(EQ("header.bin")){AL(parsec_driver_header,1);}else if(EQ("entry-points.bin")){AL(driver_entry,size/2);}else if(EQ("footer.bin")){AL(driver_footer,1);}break;
 case XX_FILE_TYPE_PALLADIX_MUS:case XX_FILE_TYPE_PALLADIX_SND:
  if(EQ("header.bin")){AL(palladix_driver_header,1);}else if(EQ("entry-points.bin")){AL(driver_entry,size/2);}else if(EQ("footer.bin")){AL(driver_footer,1);}break;
 case XX_FILE_TYPE_PALLADIX_PMA:
  if(EQ("control.bin")){AL(pma_header,1);}else if(EQ("channel-table.bin")){AL(pma_channel,9);}
  else if(EQ("program.bin")){for(unsigned ch=0;ch<9;ch++){at=N(7+2*ch,2);if(!at)continue;for(unsigned e=0;at<end&&e<65536&&c->count<31000;e++){
    n=N(at,1);AL(pma_flags,1);if(!n)break;if(n==128){AL(pma_byte,1);continue;}
    if(n&1){AL(pma_instrument,1);}if(n&2){AL(pma_byte,1);}if(n&8){AL(pma_byte,1);}
    if(n&16){AL(pma_word,1);}if(n&64){AL(pma_word,1);}AL(pma_byte,1);
  }}}break;
 case XX_FILE_TYPE_MDH:
  if(EQ("control.bin")){AL(mdh_header,1);}else if(EQ("record-table.bin")){AL(mdh_record,8);}else if(EQ("track.bin")){at=end-2;AL(mdh_end,1);}break;
 case XX_FILE_TYPE_SM8:if(EQ("header.bin")){AL(sm8_header,1);}break;
 case XX_FILE_TYPE_AUDIO_PVF:
  if(EQ("header.txt")){AL(pvf_header,1);for(unsigned i=0;i<3;i++){while(at<end&&(N(at,1)==' '||N(at,1)=='\t'||N(at,1)=='\r'))at++;int64_t start=at;while(at<end&&N(at,1)>='0'&&N(at,1)<='9')at++;size_t width=(size_t)(at-start);if(width&&width<=24){int64_t cursor=start;if(!sxaul_take(c,sxaul_pvf_numbers[i][width-1],&cursor,at,1))return false;}}}break;
 case XX_FILE_TYPE_AUDIO_SHOCKWAVE_SWA:
  if(EQ("header.bin")){AL(swa_header,1);}else if(EQ("audio.mp3")){static const uint16_t rates[4][3]={{11025,12000,8000},{0,0,0},{22050,24000,16000},{44100,48000,32000}};static const uint16_t br[2][16]={{0,8,16,24,32,40,48,56,64,80,96,112,128,144,160,0},{0,32,40,48,56,64,80,96,112,128,160,192,224,256,320,0}};
   while(at<end&&c->count<31000){uint32_t h=B(at,4),v=(h>>19)&3,r=(h>>10)&3,bi=(h>>12)&15;if(v==1||r==3||!bi||bi==15)break;uint32_t length=(v==3?144000U:72000U)*br[v==3][bi]/rates[v][r]+((h>>9)&1);AL(swa_frame,1);if(length<4||length-4>(uint64_t)(end-at))break;SK(length-4);}}break;
 case XX_FILE_TYPE_HMI_MIDI:
  if(EQ("song-header.bin")){n=N(228,1);AL(hmi_header,1);AL(hmi_track_offset,n);}else if(sxaul_prefix(name,"track-")){AL(hmi_track,1);}break;
 default:return false;
 }return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static int sxaul_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
bool sxaul_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxaul_order);
 /* Native trackers can share tracks/playlists. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxaul_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sx_audiolater_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_AP4:case XX_FILE_TYPE_SFPACK:case XX_FILE_TYPE_ADLIB_AMD:case XX_FILE_TYPE_ADLIB_MKJ:case XX_FILE_TYPE_ADLIB_SA2:case XX_FILE_TYPE_FAUST_FMC:case XX_FILE_TYPE_SOFTSTAR_RIX:case XX_FILE_TYPE_ADLIB_SOP:case XX_FILE_TYPE_CUDFM_CFF:case XX_FILE_TYPE_CERES_MSC:case XX_FILE_TYPE_IMPLAY_MUSIC:case XX_FILE_TYPE_ADLIB_MTR:case XX_FILE_TYPE_SFARK_COMPRESSED_SOUNDFONT:case XX_FILE_TYPE_AUDIO_PVF:case XX_FILE_TYPE_AUDIO_SHOCKWAVE_SWA:case XX_FILE_TYPE_HMI_MIDI:case XX_FILE_TYPE_PARSEC_DTC:case XX_FILE_TYPE_PARSEC_DMA:case XX_FILE_TYPE_PALLADIX_MUS:case XX_FILE_TYPE_PALLADIX_SND:case XX_FILE_TYPE_PALLADIX_PMA:case XX_FILE_TYPE_MDH:case XX_FILE_TYPE_SM8:return true;default:return false;}}
static bool sx_audiolater_build(sx_context*c)
{
 if(!c||c->size<1||c->size>268435456)return false;
 if(c->f->file_type==XX_FILE_TYPE_SFARK_COMPRESSED_SOUNDFONT)return sx_sfark_compressed_soundfont_build(c);
 if(c->f->file_type==XX_FILE_TYPE_SFPACK)return sx_sfpack_build(c);
 if(c->f->file_type==XX_FILE_TYPE_AP4)return sx_ap4_build(c);
 if(!c->f->create_archive_records_reading)return false;
 xx_archive_record_state*s=xx_format_create_archive_records_reading(c->f,NULL,c->pd);if(!s)return false;bool ok=true;uint64_t walked=0;
 while(ok&&s->has_record){const xx_archive_record*r=xx_format_get_current_archive_record(c->f,s);const char*name=r?xx_archive_record_get_original_name(r):NULL;
  if(++walked>65536||xx_pd_is_stopped(c->pd)||!r||!name||r->data_offset<c->f->base_address||r->compressed_size<0){ok=false;break;}
  int64_t at=r->data_offset-c->f->base_address,n=r->compressed_size;
  if(!sx_range(c,at,(uint64_t)n)||!sxaul_component(c,xx_rt_strlen(name)>=5&&name[4]=='-'?name+5:name,at,n)){ok=false;break;}
  if(!xx_format_archive_record_move_to_next(c->f,s,c->pd))break;
 }
 if(walked!=(uint64_t)s->total_records||xx_pd_is_stopped(c->pd))ok=false;
 xx_format_free_archive_records_reading(c->f,s);return ok&&c->count>0&&sxaul_finish(c);
}
#undef AL
#undef SK
#undef N
#undef B
#undef EQ
const sx_family sx_audiolater_family={sx_audiolater_supports,sx_audiolater_build,sx_audiolater_layouts,SX_COUNT(sx_audiolater_layouts),sx_audiolater_comment};
