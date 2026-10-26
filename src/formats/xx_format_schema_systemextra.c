/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical vintage disk/cassette metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_systemextra_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_systemextra.h"
static const xx_data_struct_field_desc sxse_woz_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("corruption_check","byte[4]",4,4,SX_SIGNATURE),
    SX_FIELD("crc32","uint32",8,4,SX_CHECKSUM),
};
static const sx_layout sxse_woz_header = {0x602f002cU,"woz_header",sxse_woz_header_fields,SX_COUNT(sxse_woz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_disk_chunk_header_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxse_disk_chunk_header = {0x602f002dU,"disk_chunk_header",sxse_disk_chunk_header_fields,SX_COUNT(sxse_disk_chunk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_woz_info_v1_fields[] = {
    SX_FIELD("version","uint8",0,1,SX_NONE),
    SX_FIELD("disk_type","uint8",1,1,SX_ID),
    SX_FIELD("write_protected","uint8",2,1,SX_FLAGS),
    SX_FIELD("synchronized","uint8",3,1,SX_FLAGS),
    SX_FIELD("cleaned","uint8",4,1,SX_FLAGS),
    SX_FIELD("creator","char[32]",5,32,SX_STRING),
    SX_FIELD("reserved","byte[23]",37,23,SX_RESERVED),
};
static const sx_layout sxse_woz_info_v1 = {0x602f002eU,"woz_info_v1",sxse_woz_info_v1_fields,SX_COUNT(sxse_woz_info_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxse_woz_info_v2_fields[] = {
    SX_FIELD("version","uint8",0,1,SX_NONE),
    SX_FIELD("disk_type","uint8",1,1,SX_ID),
    SX_FIELD("write_protected","uint8",2,1,SX_FLAGS),
    SX_FIELD("synchronized","uint8",3,1,SX_FLAGS),
    SX_FIELD("cleaned","uint8",4,1,SX_FLAGS),
    SX_FIELD("creator","char[32]",5,32,SX_STRING),
    SX_FIELD("disk_sides","uint8",37,1,SX_COUNT_PROP),
    SX_FIELD("boot_sector_format","uint8",38,1,SX_ID),
    SX_FIELD("optimal_bit_timing","uint8",39,1,SX_NONE),
    SX_FIELD("compatible_hardware","uint16",40,2,SX_FLAGS),
    SX_FIELD("required_ram_kib","uint16",42,2,SX_NONE),
    SX_FIELD("largest_track_blocks","uint16",44,2,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[14]",46,14,SX_RESERVED),
};
static const sx_layout sxse_woz_info_v2 = {0x602f002fU,"woz_info_v2",sxse_woz_info_v2_fields,SX_COUNT(sxse_woz_info_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxse_woz_info_v3_fields[] = {
    SX_FIELD("version","uint8",0,1,SX_NONE),
    SX_FIELD("disk_type","uint8",1,1,SX_ID),
    SX_FIELD("write_protected","uint8",2,1,SX_FLAGS),
    SX_FIELD("synchronized","uint8",3,1,SX_FLAGS),
    SX_FIELD("cleaned","uint8",4,1,SX_FLAGS),
    SX_FIELD("creator","char[32]",5,32,SX_STRING),
    SX_FIELD("disk_sides","uint8",37,1,SX_COUNT_PROP),
    SX_FIELD("boot_sector_format","uint8",38,1,SX_ID),
    SX_FIELD("optimal_bit_timing","uint8",39,1,SX_NONE),
    SX_FIELD("compatible_hardware","uint16",40,2,SX_FLAGS),
    SX_FIELD("required_ram_kib","uint16",42,2,SX_NONE),
    SX_FIELD("largest_track_blocks","uint16",44,2,SX_COUNT_PROP),
    SX_FIELD("flux_block","uint16",46,2,SX_ID),
    SX_FIELD("largest_flux_track_blocks","uint16",48,2,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[10]",50,10,SX_RESERVED),
};
static const sx_layout sxse_woz_info_v3 = {0x602f0030U,"woz_info_v3",sxse_woz_info_v3_fields,SX_COUNT(sxse_woz_info_v3_fields),SX_LE};
static const xx_data_struct_field_desc sxse_woz_track_map_fields[] = {
    SX_FIELD("track_index","uint8",0,1,SX_ID),
};
static const sx_layout sxse_woz_track_map = {0x602f0031U,"woz_track_map",sxse_woz_track_map_fields,SX_COUNT(sxse_woz_track_map_fields),SX_LE};
static const xx_data_struct_field_desc sxse_woz1_track_metadata_fields[] = {
    SX_FIELD("bytes_used","uint16",0,2,SX_SIZE),
    SX_FIELD("bit_count","uint16",2,2,SX_NONE),
    SX_FIELD("splice_bit_position","uint16",4,2,SX_NONE),
    SX_FIELD("splice_nibble","uint8",6,1,SX_NONE),
    SX_FIELD("splice_bit_count","uint8",7,1,SX_NONE),
    SX_FIELD("reserved","byte[2]",8,2,SX_RESERVED),
};
static const sx_layout sxse_woz1_track_metadata = {0x602f0032U,"woz1_track_metadata",sxse_woz1_track_metadata_fields,SX_COUNT(sxse_woz1_track_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxse_woz2_track_entry_fields[] = {
    SX_FIELD("start_block","uint16",0,2,SX_ID),
    SX_FIELD("block_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("bit_count","uint32",4,4,SX_NONE),
};
static const sx_layout sxse_woz2_track_entry = {0x602f0033U,"woz2_track_entry",sxse_woz2_track_entry_fields,SX_COUNT(sxse_woz2_track_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxse_pzx_version_fields[] = {
    SX_FIELD("major","uint8",0,1,SX_NONE),
    SX_FIELD("minor","uint8",1,1,SX_NONE),
};
static const sx_layout sxse_pzx_version = {0x602f0034U,"pzx_version",sxse_pzx_version_fields,SX_COUNT(sxse_pzx_version_fields),SX_LE};
static const xx_data_struct_field_desc sxse_pzx_data_fields[] = {
    SX_FIELD("bit_count_and_level","uint32",0,4,SX_FLAGS),
    SX_FIELD("tail_ticks","uint16",4,2,SX_NONE),
    SX_FIELD("zero_pulse_count","uint8",6,1,SX_COUNT_PROP),
    SX_FIELD("one_pulse_count","uint8",7,1,SX_COUNT_PROP),
};
static const sx_layout sxse_pzx_data = {0x602f0035U,"pzx_data",sxse_pzx_data_fields,SX_COUNT(sxse_pzx_data_fields),SX_LE};
static const xx_data_struct_field_desc sxse_pzx_pulse_duration_fields[] = {
    SX_FIELD("duration_ticks","uint16",0,2,SX_NONE),
};
static const sx_layout sxse_pzx_pulse_duration = {0x602f0036U,"pzx_pulse_duration",sxse_pzx_pulse_duration_fields,SX_COUNT(sxse_pzx_pulse_duration_fields),SX_LE};
static const xx_data_struct_field_desc sxse_pzx_pause_fields[] = {
    SX_FIELD("ticks_and_level","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxse_pzx_pause = {0x602f0037U,"pzx_pause",sxse_pzx_pause_fields,SX_COUNT(sxse_pzx_pause_fields),SX_LE};
static const xx_data_struct_field_desc sxse_pzx_stop_fields[] = {
    SX_FIELD("flags","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxse_pzx_stop = {0x602f0038U,"pzx_stop",sxse_pzx_stop_fields,SX_COUNT(sxse_pzx_stop_fields),SX_LE};
static const xx_data_struct_field_desc sxse_a2r_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("corruption_check","byte[4]",4,4,SX_SIGNATURE),
};
static const sx_layout sxse_a2r_header = {0x602f0046U,"a2r_header",sxse_a2r_header_fields,SX_COUNT(sxse_a2r_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_a2r_info_v2_fields[] = {
    SX_FIELD("version","uint8",0,1,SX_NONE),
    SX_FIELD("creator","char[32]",1,32,SX_STRING),
    SX_FIELD("drive_type","uint8",33,1,SX_ID),
    SX_FIELD("write_protected","uint8",34,1,SX_FLAGS),
    SX_FIELD("synchronized","uint8",35,1,SX_FLAGS),
};
static const sx_layout sxse_a2r_info_v2 = {0x602f0047U,"a2r_info_v2",sxse_a2r_info_v2_fields,SX_COUNT(sxse_a2r_info_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxse_a2r_info_v3_fields[] = {
    SX_FIELD("version","uint8",0,1,SX_NONE),
    SX_FIELD("creator","char[32]",1,32,SX_STRING),
    SX_FIELD("drive_type","uint8",33,1,SX_ID),
    SX_FIELD("write_protected","uint8",34,1,SX_FLAGS),
    SX_FIELD("synchronized","uint8",35,1,SX_FLAGS),
    SX_FIELD("hard_sector_count","uint8",36,1,SX_COUNT_PROP),
};
static const sx_layout sxse_a2r_info_v3 = {0x602f0048U,"a2r_info_v3",sxse_a2r_info_v3_fields,SX_COUNT(sxse_a2r_info_v3_fields),SX_LE};
static const xx_data_struct_field_desc sxse_a2r2_capture_fields[] = {
    SX_FIELD("location","uint8",0,1,SX_ID),
    SX_FIELD("capture_type","uint8",1,1,SX_ID),
    SX_FIELD("data_size","uint32",2,4,SX_SIZE),
    SX_FIELD("loop_ticks","uint32",6,4,SX_NONE),
};
static const sx_layout sxse_a2r2_capture = {0x602f0049U,"a2r2_capture",sxse_a2r2_capture_fields,SX_COUNT(sxse_a2r2_capture_fields),SX_LE};
static const xx_data_struct_field_desc sxse_a2r_stream_end_fields[] = {
    SX_FIELD("end_marker","uint8",0,1,SX_ID),
};
static const sx_layout sxse_a2r_stream_end = {0x602f004aU,"a2r_stream_end",sxse_a2r_stream_end_fields,SX_COUNT(sxse_a2r_stream_end_fields),SX_LE};
static const xx_data_struct_field_desc sxse_a2r3_capture_chunk_fields[] = {
    SX_FIELD("version","uint8",0,1,SX_NONE),
    SX_FIELD("tick_picoseconds","uint32",1,4,SX_NONE),
    SX_FIELD("reserved","byte[11]",5,11,SX_RESERVED),
};
static const sx_layout sxse_a2r3_capture_chunk = {0x602f004bU,"a2r3_capture_chunk",sxse_a2r3_capture_chunk_fields,SX_COUNT(sxse_a2r3_capture_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxse_a2r3_capture_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_ID),
    SX_FIELD("capture_type","uint8",1,1,SX_ID),
    SX_FIELD("location","uint16",2,2,SX_ID),
    SX_FIELD("index_count","uint8",4,1,SX_COUNT_PROP),
};
static const sx_layout sxse_a2r3_capture = {0x602f004cU,"a2r3_capture",sxse_a2r3_capture_fields,SX_COUNT(sxse_a2r3_capture_fields),SX_LE};
static const xx_data_struct_field_desc sxse_a2r3_solved_track_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_ID),
    SX_FIELD("location","uint16",1,2,SX_ID),
    SX_FIELD("mirror_previous_count","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("mirror_next_count","uint8",4,1,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[6]",5,6,SX_RESERVED),
    SX_FIELD("index_count","uint8",11,1,SX_COUNT_PROP),
};
static const sx_layout sxse_a2r3_solved_track = {0x602f004dU,"a2r3_solved_track",sxse_a2r3_solved_track_fields,SX_COUNT(sxse_a2r3_solved_track_fields),SX_LE};
static const xx_data_struct_field_desc sxse_a2r3_index_time_fields[] = {
    SX_FIELD("index_ticks","uint32",0,4,SX_NONE),
};
static const sx_layout sxse_a2r3_index_time = {0x602f004eU,"a2r3_index_time",sxse_a2r3_index_time_fields,SX_COUNT(sxse_a2r3_index_time_fields),SX_LE};
static const xx_data_struct_field_desc sxse_a2r_capture_size_fields[] = {
    SX_FIELD("data_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxse_a2r_capture_size = {0x602f004fU,"a2r_capture_size",sxse_a2r_capture_size_fields,SX_COUNT(sxse_a2r_capture_size_fields),SX_LE};
static const xx_data_struct_field_desc sxse_hfe_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("format_revision","uint8",8,1,SX_NONE),
    SX_FIELD("cylinder_count","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("side_count","uint8",10,1,SX_COUNT_PROP),
    SX_FIELD("track_encoding","uint8",11,1,SX_ID),
    SX_FIELD("bitrate_kbps","uint16",12,2,SX_NONE),
    SX_FIELD("rpm","uint16",14,2,SX_NONE),
    SX_FIELD("interface_mode","uint8",16,1,SX_ID),
    SX_FIELD("reserved1","uint8",17,1,SX_RESERVED),
    SX_FIELD("track_table_block","uint16",18,2,SX_ID),
    SX_FIELD("write_allowed","uint8",20,1,SX_FLAGS),
    SX_FIELD("single_step","uint8",21,1,SX_FLAGS),
    SX_FIELD("track0_side0_alternate","uint8",22,1,SX_FLAGS),
    SX_FIELD("track0_side0_encoding","uint8",23,1,SX_ID),
    SX_FIELD("track0_side1_alternate","uint8",24,1,SX_FLAGS),
    SX_FIELD("track0_side1_encoding","uint8",25,1,SX_ID),
    SX_FIELD("unused_header_bytes","byte[486]",26,486,SX_NONE),
};
static const sx_layout sxse_hfe_header = {0x602f005eU,"hfe_header",sxse_hfe_header_fields,SX_COUNT(sxse_hfe_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_hfe_track_entry_fields[] = {
    SX_FIELD("data_block","uint16",0,2,SX_ID),
    SX_FIELD("track_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxse_hfe_track_entry = {0x602f005fU,"hfe_track_entry",sxse_hfe_track_entry_fields,SX_COUNT(sxse_hfe_track_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxse_stream_hfe_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("revision","uint32",16,4,SX_NONE),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("reserved_table_end","uint32",24,4,SX_OFFSET),
    SX_FIELD("track_table_offset","uint32",28,4,SX_OFFSET),
    SX_FIELD("first_stream_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("cylinder_count","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("side_count","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("tick_period","uint32",44,4,SX_NONE),
};
static const sx_layout sxse_stream_hfe_header = {0x602f0060U,"stream_hfe_header",sxse_stream_hfe_header_fields,SX_COUNT(sxse_stream_hfe_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_stream_hfe_track_fields[] = {
    SX_FIELD("flags","uint32",0,4,SX_FLAGS),
    SX_FIELD("stream_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("stored_size","uint32",8,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",12,4,SX_SIZE),
    SX_FIELD("opaque_10","byte[4]",16,4,SX_NONE),
    SX_FIELD("pulse_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[8]",24,8,SX_RESERVED),
};
static const sx_layout sxse_stream_hfe_track = {0x602f0061U,"stream_hfe_track",sxse_stream_hfe_track_fields,SX_COUNT(sxse_stream_hfe_track_fields),SX_LE};
static const sx_layout *const sx_systemextra_layouts[] = {
    &sxse_x64_header,
    &sxse_g64_header,
    &sxse_g64_track_offset,
    &sxse_g64_constant_speed,
    &sxse_g64_speed_offset,
    &sxse_g64_track_header,
    &sxse_p64_header,
    &sxse_p64_chunk_header,
    &sxse_p64_halftrack_header,
    &sxse_c64_tap_header,
    &sxse_tzx_header,
    &sxse_tzx_standard_data,
    &sxse_tzx_turbo_data,
    &sxse_tzx_pure_tone,
    &sxse_tzx_pulse_sequence,
    &sxse_tzx_pulse,
    &sxse_tzx_pure_data,
    &sxse_tzx_pause,
    &sxse_tzx_text_header,
    &sxse_tzx_group_end,
    &sxse_tzx_archive_info,
    &sxse_tzx_archive_string,
    &sxse_tzx_custom_info,
    &sxse_cpc_disk_header,
    &sxse_cpc_extended_disk_header,
    &sxse_cpc_track_size,
    &sxse_cpc_track_header,
    &sxse_cpc_sector_standard,
    &sxse_cpc_sector_extended,
    &sxse_cpc_offset_info,
    &sxse_cpc_track_length,
    &sxse_cpc_sector_timing,
    &sxse_msa_header,
    &sxse_msa_track_header,
    &sxse_scp_header,
    &sxse_scp_track_offset,
    &sxse_scp_track_header,
    &sxse_scp_revolution,
    &sxse_scp_extension_header,
    &sxse_scp_write_splices_header,
    &sxse_scp_write_splice,
    &sxse_scp_footer,
    &sxse_scp_string_header,
    &sxse_woz_header,
    &sxse_disk_chunk_header,
    &sxse_woz_info_v1,
    &sxse_woz_info_v2,
    &sxse_woz_info_v3,
    &sxse_woz_track_map,
    &sxse_woz1_track_metadata,
    &sxse_woz2_track_entry,
    &sxse_pzx_version,
    &sxse_pzx_data,
    &sxse_pzx_pulse_duration,
    &sxse_pzx_pause,
    &sxse_pzx_stop,
    &sxse_uef_header,
    &sxse_uef_chunk,
    &sxse_uef_carrier,
    &sxse_uef_carrier_dummy,
    &sxse_uef_gap,
    &sxse_uef_phase,
    &sxse_pc64_header,
    &sxse_atari_cas_description,
    &sxse_atari_cas_baud,
    &sxse_atari_cas_data,
    &sxse_atari_cas_fsk,
    &sxse_oric_tap_header,
    &sxse_vdk_header,
    &sxse_a2r_header,
    &sxse_a2r_info_v2,
    &sxse_a2r_info_v3,
    &sxse_a2r2_capture,
    &sxse_a2r_stream_end,
    &sxse_a2r3_capture_chunk,
    &sxse_a2r3_capture,
    &sxse_a2r3_solved_track,
    &sxse_a2r3_index_time,
    &sxse_a2r_capture_size,
    &sxse_atr_header,
    &sxse_stx_header,
    &sxse_stx_track,
    &sxse_stx_sector,
    &sxse_hxc_mfm_header,
    &sxse_hxc_mfm_track,
    &sxse_ydsk_header,
    &sxse_nfd_header,
    &sxse_nfd_sector_r0,
    &sxse_nfd_sector_r1,
    &sxse_nfd_track_offset,
    &sxse_nfd_additional_info,
    &sxse_nfd_track_header,
    &sxse_nfd_diagnostic,
    &sxse_hfe_header,
    &sxse_hfe_track_entry,
    &sxse_stream_hfe_header,
    &sxse_stream_hfe_track,
};
static bool sx_systemextra_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x602f0000U||id>=0x60300000U)return true;
    const wchar_t *s=NULL;
    uint64_t value=xx_var_get_u64(&r->value);
    if(id==0x602f0001U&&!xx_rt_wcscmp(r->name,L"device_type")){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"1541 disk drive");
    default:break;}}
    if(id==0x602f000aU&&!xx_rt_wcscmp(r->name,L"computer_platform")){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"C64");
    default:break;}}
    if(id==0x602f000aU&&!xx_rt_wcscmp(r->name,L"video_standard")){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"PAL");
    case 1U:return xx_data_struct_record_set_comment(r,L"NTSC");
    case 2U:return xx_data_struct_record_set_comment(r,L"OLD_NTSC");
    case 3U:return xx_data_struct_record_set_comment(r,L"PAL_N");
    default:break;}}
    if(id==0x602f000cU&&!xx_rt_wcscmp(r->name,L"block_id")){switch(value){
    case 16U:return xx_data_struct_record_set_comment(r,L"STANDARD_SPEED_DATA");
    case 17U:return xx_data_struct_record_set_comment(r,L"TURBO_SPEED_DATA");
    case 18U:return xx_data_struct_record_set_comment(r,L"PURE_TONE");
    case 19U:return xx_data_struct_record_set_comment(r,L"PULSE_SEQUENCE");
    case 20U:return xx_data_struct_record_set_comment(r,L"PURE_DATA");
    case 32U:return xx_data_struct_record_set_comment(r,L"PAUSE_OR_STOP");
    case 33U:return xx_data_struct_record_set_comment(r,L"GROUP_START");
    case 34U:return xx_data_struct_record_set_comment(r,L"GROUP_END");
    case 48U:return xx_data_struct_record_set_comment(r,L"TEXT_DESCRIPTION");
    case 50U:return xx_data_struct_record_set_comment(r,L"ARCHIVE_INFO");
    case 53U:return xx_data_struct_record_set_comment(r,L"CUSTOM_INFO");
    default:break;}}
    if(id==0x602f000dU&&!xx_rt_wcscmp(r->name,L"block_id")){switch(value){
    case 16U:return xx_data_struct_record_set_comment(r,L"STANDARD_SPEED_DATA");
    case 17U:return xx_data_struct_record_set_comment(r,L"TURBO_SPEED_DATA");
    case 18U:return xx_data_struct_record_set_comment(r,L"PURE_TONE");
    case 19U:return xx_data_struct_record_set_comment(r,L"PULSE_SEQUENCE");
    case 20U:return xx_data_struct_record_set_comment(r,L"PURE_DATA");
    case 32U:return xx_data_struct_record_set_comment(r,L"PAUSE_OR_STOP");
    case 33U:return xx_data_struct_record_set_comment(r,L"GROUP_START");
    case 34U:return xx_data_struct_record_set_comment(r,L"GROUP_END");
    case 48U:return xx_data_struct_record_set_comment(r,L"TEXT_DESCRIPTION");
    case 50U:return xx_data_struct_record_set_comment(r,L"ARCHIVE_INFO");
    case 53U:return xx_data_struct_record_set_comment(r,L"CUSTOM_INFO");
    default:break;}}
    if(id==0x602f000eU&&!xx_rt_wcscmp(r->name,L"block_id")){switch(value){
    case 16U:return xx_data_struct_record_set_comment(r,L"STANDARD_SPEED_DATA");
    case 17U:return xx_data_struct_record_set_comment(r,L"TURBO_SPEED_DATA");
    case 18U:return xx_data_struct_record_set_comment(r,L"PURE_TONE");
    case 19U:return xx_data_struct_record_set_comment(r,L"PULSE_SEQUENCE");
    case 20U:return xx_data_struct_record_set_comment(r,L"PURE_DATA");
    case 32U:return xx_data_struct_record_set_comment(r,L"PAUSE_OR_STOP");
    case 33U:return xx_data_struct_record_set_comment(r,L"GROUP_START");
    case 34U:return xx_data_struct_record_set_comment(r,L"GROUP_END");
    case 48U:return xx_data_struct_record_set_comment(r,L"TEXT_DESCRIPTION");
    case 50U:return xx_data_struct_record_set_comment(r,L"ARCHIVE_INFO");
    case 53U:return xx_data_struct_record_set_comment(r,L"CUSTOM_INFO");
    default:break;}}
    if(id==0x602f000fU&&!xx_rt_wcscmp(r->name,L"block_id")){switch(value){
    case 16U:return xx_data_struct_record_set_comment(r,L"STANDARD_SPEED_DATA");
    case 17U:return xx_data_struct_record_set_comment(r,L"TURBO_SPEED_DATA");
    case 18U:return xx_data_struct_record_set_comment(r,L"PURE_TONE");
    case 19U:return xx_data_struct_record_set_comment(r,L"PULSE_SEQUENCE");
    case 20U:return xx_data_struct_record_set_comment(r,L"PURE_DATA");
    case 32U:return xx_data_struct_record_set_comment(r,L"PAUSE_OR_STOP");
    case 33U:return xx_data_struct_record_set_comment(r,L"GROUP_START");
    case 34U:return xx_data_struct_record_set_comment(r,L"GROUP_END");
    case 48U:return xx_data_struct_record_set_comment(r,L"TEXT_DESCRIPTION");
    case 50U:return xx_data_struct_record_set_comment(r,L"ARCHIVE_INFO");
    case 53U:return xx_data_struct_record_set_comment(r,L"CUSTOM_INFO");
    default:break;}}
    if(id==0x602f0011U&&!xx_rt_wcscmp(r->name,L"block_id")){switch(value){
    case 16U:return xx_data_struct_record_set_comment(r,L"STANDARD_SPEED_DATA");
    case 17U:return xx_data_struct_record_set_comment(r,L"TURBO_SPEED_DATA");
    case 18U:return xx_data_struct_record_set_comment(r,L"PURE_TONE");
    case 19U:return xx_data_struct_record_set_comment(r,L"PULSE_SEQUENCE");
    case 20U:return xx_data_struct_record_set_comment(r,L"PURE_DATA");
    case 32U:return xx_data_struct_record_set_comment(r,L"PAUSE_OR_STOP");
    case 33U:return xx_data_struct_record_set_comment(r,L"GROUP_START");
    case 34U:return xx_data_struct_record_set_comment(r,L"GROUP_END");
    case 48U:return xx_data_struct_record_set_comment(r,L"TEXT_DESCRIPTION");
    case 50U:return xx_data_struct_record_set_comment(r,L"ARCHIVE_INFO");
    case 53U:return xx_data_struct_record_set_comment(r,L"CUSTOM_INFO");
    default:break;}}
    if(id==0x602f0012U&&!xx_rt_wcscmp(r->name,L"block_id")){switch(value){
    case 16U:return xx_data_struct_record_set_comment(r,L"STANDARD_SPEED_DATA");
    case 17U:return xx_data_struct_record_set_comment(r,L"TURBO_SPEED_DATA");
    case 18U:return xx_data_struct_record_set_comment(r,L"PURE_TONE");
    case 19U:return xx_data_struct_record_set_comment(r,L"PULSE_SEQUENCE");
    case 20U:return xx_data_struct_record_set_comment(r,L"PURE_DATA");
    case 32U:return xx_data_struct_record_set_comment(r,L"PAUSE_OR_STOP");
    case 33U:return xx_data_struct_record_set_comment(r,L"GROUP_START");
    case 34U:return xx_data_struct_record_set_comment(r,L"GROUP_END");
    case 48U:return xx_data_struct_record_set_comment(r,L"TEXT_DESCRIPTION");
    case 50U:return xx_data_struct_record_set_comment(r,L"ARCHIVE_INFO");
    case 53U:return xx_data_struct_record_set_comment(r,L"CUSTOM_INFO");
    default:break;}}
    if(id==0x602f0013U&&!xx_rt_wcscmp(r->name,L"block_id")){switch(value){
    case 16U:return xx_data_struct_record_set_comment(r,L"STANDARD_SPEED_DATA");
    case 17U:return xx_data_struct_record_set_comment(r,L"TURBO_SPEED_DATA");
    case 18U:return xx_data_struct_record_set_comment(r,L"PURE_TONE");
    case 19U:return xx_data_struct_record_set_comment(r,L"PULSE_SEQUENCE");
    case 20U:return xx_data_struct_record_set_comment(r,L"PURE_DATA");
    case 32U:return xx_data_struct_record_set_comment(r,L"PAUSE_OR_STOP");
    case 33U:return xx_data_struct_record_set_comment(r,L"GROUP_START");
    case 34U:return xx_data_struct_record_set_comment(r,L"GROUP_END");
    case 48U:return xx_data_struct_record_set_comment(r,L"TEXT_DESCRIPTION");
    case 50U:return xx_data_struct_record_set_comment(r,L"ARCHIVE_INFO");
    case 53U:return xx_data_struct_record_set_comment(r,L"CUSTOM_INFO");
    default:break;}}
    if(id==0x602f0014U&&!xx_rt_wcscmp(r->name,L"block_id")){switch(value){
    case 16U:return xx_data_struct_record_set_comment(r,L"STANDARD_SPEED_DATA");
    case 17U:return xx_data_struct_record_set_comment(r,L"TURBO_SPEED_DATA");
    case 18U:return xx_data_struct_record_set_comment(r,L"PURE_TONE");
    case 19U:return xx_data_struct_record_set_comment(r,L"PULSE_SEQUENCE");
    case 20U:return xx_data_struct_record_set_comment(r,L"PURE_DATA");
    case 32U:return xx_data_struct_record_set_comment(r,L"PAUSE_OR_STOP");
    case 33U:return xx_data_struct_record_set_comment(r,L"GROUP_START");
    case 34U:return xx_data_struct_record_set_comment(r,L"GROUP_END");
    case 48U:return xx_data_struct_record_set_comment(r,L"TEXT_DESCRIPTION");
    case 50U:return xx_data_struct_record_set_comment(r,L"ARCHIVE_INFO");
    case 53U:return xx_data_struct_record_set_comment(r,L"CUSTOM_INFO");
    default:break;}}
    if(id==0x602f0015U&&!xx_rt_wcscmp(r->name,L"block_id")){switch(value){
    case 16U:return xx_data_struct_record_set_comment(r,L"STANDARD_SPEED_DATA");
    case 17U:return xx_data_struct_record_set_comment(r,L"TURBO_SPEED_DATA");
    case 18U:return xx_data_struct_record_set_comment(r,L"PURE_TONE");
    case 19U:return xx_data_struct_record_set_comment(r,L"PULSE_SEQUENCE");
    case 20U:return xx_data_struct_record_set_comment(r,L"PURE_DATA");
    case 32U:return xx_data_struct_record_set_comment(r,L"PAUSE_OR_STOP");
    case 33U:return xx_data_struct_record_set_comment(r,L"GROUP_START");
    case 34U:return xx_data_struct_record_set_comment(r,L"GROUP_END");
    case 48U:return xx_data_struct_record_set_comment(r,L"TEXT_DESCRIPTION");
    case 50U:return xx_data_struct_record_set_comment(r,L"ARCHIVE_INFO");
    case 53U:return xx_data_struct_record_set_comment(r,L"CUSTOM_INFO");
    default:break;}}
    if(id==0x602f0017U&&!xx_rt_wcscmp(r->name,L"block_id")){switch(value){
    case 16U:return xx_data_struct_record_set_comment(r,L"STANDARD_SPEED_DATA");
    case 17U:return xx_data_struct_record_set_comment(r,L"TURBO_SPEED_DATA");
    case 18U:return xx_data_struct_record_set_comment(r,L"PURE_TONE");
    case 19U:return xx_data_struct_record_set_comment(r,L"PULSE_SEQUENCE");
    case 20U:return xx_data_struct_record_set_comment(r,L"PURE_DATA");
    case 32U:return xx_data_struct_record_set_comment(r,L"PAUSE_OR_STOP");
    case 33U:return xx_data_struct_record_set_comment(r,L"GROUP_START");
    case 34U:return xx_data_struct_record_set_comment(r,L"GROUP_END");
    case 48U:return xx_data_struct_record_set_comment(r,L"TEXT_DESCRIPTION");
    case 50U:return xx_data_struct_record_set_comment(r,L"ARCHIVE_INFO");
    case 53U:return xx_data_struct_record_set_comment(r,L"CUSTOM_INFO");
    default:break;}}
    if(id==0x602f003aU&&!xx_rt_wcscmp(r->name,L"chunk_id")){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"ORIGIN_INFORMATION");
    case 256U:return xx_data_struct_record_set_comment(r,L"IMPLICIT_TAPE_DATA");
    case 272U:return xx_data_struct_record_set_comment(r,L"CARRIER_TONE");
    case 273U:return xx_data_struct_record_set_comment(r,L"CARRIER_WITH_DUMMY_BYTE");
    case 274U:return xx_data_struct_record_set_comment(r,L"INTEGER_GAP");
    case 277U:return xx_data_struct_record_set_comment(r,L"PHASE_CHANGE");
    default:break;}}
    if(id==0x602f002eU&&!xx_rt_wcscmp(r->name,L"disk_type")){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"5.25-inch disk");
    case 2U:return xx_data_struct_record_set_comment(r,L"3.5-inch disk");
    default:break;}}
    if(id==0x602f002fU&&!xx_rt_wcscmp(r->name,L"disk_type")){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"5.25-inch disk");
    case 2U:return xx_data_struct_record_set_comment(r,L"3.5-inch disk");
    default:break;}}
    if(id==0x602f0030U&&!xx_rt_wcscmp(r->name,L"disk_type")){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"5.25-inch disk");
    case 2U:return xx_data_struct_record_set_comment(r,L"3.5-inch disk");
    default:break;}}
    if(id==0x602f002fU&&!xx_rt_wcscmp(r->name,L"boot_sector_format")){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unknown");
    case 1U:return xx_data_struct_record_set_comment(r,L"16-sector");
    case 2U:return xx_data_struct_record_set_comment(r,L"13-sector");
    case 3U:return xx_data_struct_record_set_comment(r,L"Both 13-sector and 16-sector");
    default:break;}}
    if(id==0x602f0030U&&!xx_rt_wcscmp(r->name,L"boot_sector_format")){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Unknown");
    case 1U:return xx_data_struct_record_set_comment(r,L"16-sector");
    case 2U:return xx_data_struct_record_set_comment(r,L"13-sector");
    case 3U:return xx_data_struct_record_set_comment(r,L"Both 13-sector and 16-sector");
    default:break;}}
    if(id==0x602f0049U&&!xx_rt_wcscmp(r->name,L"capture_type")){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"TIMING");
    case 2U:return xx_data_struct_record_set_comment(r,L"BITS");
    case 3U:return xx_data_struct_record_set_comment(r,L"XTIMING");
    default:break;}}
    if(id==0x602f004cU&&!xx_rt_wcscmp(r->name,L"capture_type")){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"TIMING");
    case 2U:return xx_data_struct_record_set_comment(r,L"BITS");
    case 3U:return xx_data_struct_record_set_comment(r,L"XTIMING");
    default:break;}}
    if(id==0x602f005eU&&!xx_rt_wcscmp(r->name,L"track_encoding")){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"ISOIBM_MFM");
    case 1U:return xx_data_struct_record_set_comment(r,L"AMIGA_MFM");
    case 2U:return xx_data_struct_record_set_comment(r,L"ISOIBM_FM");
    case 3U:return xx_data_struct_record_set_comment(r,L"EMU_FM");
    case 255U:return xx_data_struct_record_set_comment(r,L"UNKNOWN_ENCODING");
    default:break;}}
    if(id==0x602f0058U&&!xx_rt_wcscmp(r->name,L"mfm")){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"FM");
    case 1U:return xx_data_struct_record_set_comment(r,L"MFM");
    default:break;}}
    if(id==0x602f0059U&&!xx_rt_wcscmp(r->name,L"mfm")){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"FM");
    case 1U:return xx_data_struct_record_set_comment(r,L"MFM");
    default:break;}}
    switch(id){
    case 0x602f0001U:
        if(!xx_rt_wcscmp(r->name,L"second_side"))s=L"Zero means no second side; one means a second side is present.";
        break;
    case 0x602f0003U:
        if(!xx_rt_wcscmp(r->name,L"track_offset"))s=L"File-relative byte offset of the track-length word; zero means absent.";
        break;
    case 0x602f0004U:
        if(!xx_rt_wcscmp(r->name,L"speed_zone"))s=L"Constant speed zone 0..3; this word is not an offset.";
        break;
    case 0x602f0005U:
        if(!xx_rt_wcscmp(r->name,L"speed_map_offset"))s=L"File-relative byte offset of the packed two-bit speed map.";
        break;
    case 0x602f0007U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit 0 write protection; bit 1 two-sided image.";
        break;
    case 0x602f0009U:
        if(!xx_rt_wcscmp(r->name,L"halftrack_and_side"))s=L"Low 7 bits identify halftrack 2..85; high bit selects the second side.";
        break;
    case 0x602f0010U:
        if(!xx_rt_wcscmp(r->name,L"duration_ticks"))s=L"Duration in ZX Spectrum T-states.";
        break;
    case 0x602f0012U:
        if(!xx_rt_wcscmp(r->name,L"pause_milliseconds"))s=L"Zero means stop the tape.";
        break;
    case 0x602f0018U:
        if(!xx_rt_wcscmp(r->name,L"track_size"))s=L"Standard DSK track size including its 256-byte header.";
        break;
    case 0x602f001aU:
        if(!xx_rt_wcscmp(r->name,L"size_units"))s=L"Track size in 256-byte units; zero means an unformatted track.";
        break;
    case 0x602f001bU:
        if(!xx_rt_wcscmp(r->name,L"sector_size_code"))s=L"Sector byte size=128 shifted left by this code.";
        else if(!xx_rt_wcscmp(r->name,L"gap3_length"))s=L"Number of controller gap bytes on the disk, not bytes allocated in the file.";
        break;
    case 0x602f001cU:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Sector byte size=128 shifted left by this code.";
        break;
    case 0x602f001dU:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Sector byte size=128 shifted left by this code.";
        break;
    case 0x602f001fU:
        if(!xx_rt_wcscmp(r->name,L"track_length"))s=L"Track length in raw controller byte positions, not physical file bytes.";
        break;
    case 0x602f0020U:
        if(!xx_rt_wcscmp(r->name,L"sector_position"))s=L"Sector position within the track; not a file byte offset.";
        break;
    case 0x602f0021U:
        if(!xx_rt_wcscmp(r->name,L"sides_minus_one"))s=L"Encoded head count minus one.";
        break;
    case 0x602f0022U:
        if(!xx_rt_wcscmp(r->name,L"stored_size"))s=L"Equal to sectors_per_track*512 for an uncompressed track; otherwise an E5 RLE stream.";
        break;
    case 0x602f0023U:
        if(!xx_rt_wcscmp(r->name,L"version_bcd"))s=L"High nibble major, low nibble minor version.";
        else if(!xx_rt_wcscmp(r->name,L"flags"))s=L"INDEXED=0x01,96TPI=0x02,360RPM=0x04,NORMALIZED=0x08,READWRITE=0x10,FOOTER=0x20,EXTENDED_MODE=0x40,NON_SCP_CREATOR=0x80.";
        else if(!xx_rt_wcscmp(r->name,L"bitcell_width"))s=L"Zero encodes 16-bit flux timing samples.";
        else if(!xx_rt_wcscmp(r->name,L"heads"))s=L"0=both heads,1=head0 only,2=head1 only.";
        else if(!xx_rt_wcscmp(r->name,L"resolution_multiplier"))s=L"Capture resolution in 25 ns units, multiplied by this value plus one.";
        break;
    case 0x602f0024U:
        if(!xx_rt_wcscmp(r->name,L"track_offset"))s=L"File-relative track header byte offset; zero means absent.";
        break;
    case 0x602f0026U:
        if(!xx_rt_wcscmp(r->name,L"index_duration"))s=L"Index-to-index duration in 25 ns units.";
        else if(!xx_rt_wcscmp(r->name,L"sample_count"))s=L"Number of 16-bit flux timing words, not bytes.";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Byte offset relative to this track header.";
        break;
    case 0x602f0029U:
        if(!xx_rt_wcscmp(r->name,L"write_splice"))s=L"Write-splice position in SCP ticks (25 ns); zero is used for unused tracks.";
        break;
    case 0x602f002aU:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Signed seconds since 1970-01-01 UTC.";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Signed seconds since 1970-01-01 UTC.";
        break;
    case 0x602f002bU:
        if(!xx_rt_wcscmp(r->name,L"string_size"))s=L"UTF-8 byte length excluding the length word and terminating zero.";
        break;
    case 0x602f002fU:
        if(!xx_rt_wcscmp(r->name,L"optimal_bit_timing"))s=L"Encoded 125 ns units.";
        else if(!xx_rt_wcscmp(r->name,L"required_ram_kib"))s=L"Required memory in KiB; zero means unknown.";
        else if(!xx_rt_wcscmp(r->name,L"largest_track_blocks"))s=L"Count of 512-byte blocks.";
        break;
    case 0x602f0030U:
        if(!xx_rt_wcscmp(r->name,L"optimal_bit_timing"))s=L"Encoded 125 ns units.";
        else if(!xx_rt_wcscmp(r->name,L"required_ram_kib"))s=L"Required memory in KiB; zero means unknown.";
        else if(!xx_rt_wcscmp(r->name,L"largest_track_blocks"))s=L"Count of 512-byte blocks.";
        else if(!xx_rt_wcscmp(r->name,L"flux_block"))s=L"File-relative 512-byte block index of the FLUX chunk header.";
        else if(!xx_rt_wcscmp(r->name,L"largest_flux_track_blocks"))s=L"Count of 512-byte blocks.";
        break;
    case 0x602f0031U:
        if(!xx_rt_wcscmp(r->name,L"track_index"))s=L"0xff means no associated track.";
        break;
    case 0x602f0032U:
        if(!xx_rt_wcscmp(r->name,L"bit_count"))s=L"Number of valid bit cells; not a byte count.";
        else if(!xx_rt_wcscmp(r->name,L"splice_bit_position"))s=L"Bit position;0xffff means no splice information.";
        break;
    case 0x602f0033U:
        if(!xx_rt_wcscmp(r->name,L"start_block"))s=L"File-relative 512-byte block index.";
        else if(!xx_rt_wcscmp(r->name,L"block_count"))s=L"Number of 512-byte blocks.";
        else if(!xx_rt_wcscmp(r->name,L"bit_count"))s=L"Valid bit count; for a FLUX-mapped track this word is the valid flux-byte count.";
        break;
    case 0x602f0035U:
        if(!xx_rt_wcscmp(r->name,L"bit_count_and_level"))s=L"Low 31 bits hold data bit count; high bit gives starting pulse level.";
        break;
    case 0x602f0036U:
        if(!xx_rt_wcscmp(r->name,L"duration_ticks"))s=L"Spectrum T-state ticks for the selected bit waveform.";
        break;
    case 0x602f0037U:
        if(!xx_rt_wcscmp(r->name,L"ticks_and_level"))s=L"Low 31 bits duration in T-states; high bit starting pulse level.";
        break;
    case 0x602f0038U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit 0: stop in48K mode only.";
        break;
    case 0x602f003bU:
        if(!xx_rt_wcscmp(r->name,L"cycles"))s=L"Carrier duration in cycles of the 2400 Hz high tone.";
        break;
    case 0x602f003dU:
        if(!xx_rt_wcscmp(r->name,L"duration_cycles"))s=L"Gap duration in 1200 Hz units.";
        break;
    case 0x602f003eU:
        if(!xx_rt_wcscmp(r->name,L"degrees"))s=L"Phase change in degrees.";
        break;
    case 0x602f003fU:
        if(!xx_rt_wcscmp(r->name,L"petscii_name"))s=L"Commodore PETSCII filename, not ASCII.";
        else if(!xx_rt_wcscmp(r->name,L"record_size"))s=L"Zero means a non-REL file; otherwise fixed record size in bytes.";
        break;
    case 0x602f0040U:
        if(!xx_rt_wcscmp(r->name,L"reserved"))s=L"Reserved zero";
        break;
    case 0x602f0041U:
        if(!xx_rt_wcscmp(r->name,L"baud_rate"))s=L"Bits per second";
        break;
    case 0x602f0042U:
        if(!xx_rt_wcscmp(r->name,L"gap_milliseconds"))s=L"Gap before data in milliseconds";
        break;
    case 0x602f0043U:
        if(!xx_rt_wcscmp(r->name,L"gap_milliseconds"))s=L"Gap before flux pulses in milliseconds";
        break;
    case 0x602f0044U:
        if(!xx_rt_wcscmp(r->name,L"file_type"))s=L"0=BASIC,0x80=machine code.";
        else if(!xx_rt_wcscmp(r->name,L"autostart"))s=L"0=no autorun,0x80=machine code autorun,0xc7=BASIC autorun.";
        else if(!xx_rt_wcscmp(r->name,L"end_address"))s=L"Inclusive destination address.";
        break;
    case 0x602f0045U:
        if(!xx_rt_wcscmp(r->name,L"compression_and_name_length"))s=L"Low 3 bits compression; high 5 bits filename length in bytes.";
        break;
    case 0x602f0049U:
        if(!xx_rt_wcscmp(r->name,L"loop_ticks"))s=L"Capture duration before repetition in 125 ns timing ticks.";
        break;
    case 0x602f004bU:
        if(!xx_rt_wcscmp(r->name,L"tick_picoseconds"))s=L"Capture timing resolution in picoseconds.";
        break;
    case 0x602f004eU:
        if(!xx_rt_wcscmp(r->name,L"index_ticks"))s=L"Absolute index timing relative to capture start, measured in the enclosing chunk tick period.";
        break;
    case 0x602f0050U:
        if(!xx_rt_wcscmp(r->name,L"paragraph_count_low"))s=L"Low 16 bits of the image length in 16-byte units.";
        else if(!xx_rt_wcscmp(r->name,L"paragraph_count_high"))s=L"High 16 bits of the image length in 16-byte units.";
        else if(!xx_rt_wcscmp(r->name,L"unused_header_bytes"))s=L"Native supported variant requires these optional extension bytes to be zero.";
        break;
    case 0x602f0052U:
        if(!xx_rt_wcscmp(r->name,L"track_length"))s=L"Track length in controller bytes, not physical file bytes.";
        else if(!xx_rt_wcscmp(r->name,L"track_and_side"))s=L"Low 7 bits cylinder, high bit side.";
        break;
    case 0x602f0053U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Byte offset relative to the track data area after descriptors/fuzzy mask.";
        else if(!xx_rt_wcscmp(r->name,L"bit_position"))s=L"Sector position in bit cells.";
        else if(!xx_rt_wcscmp(r->name,L"read_time"))s=L"Controller timing value; not a wall-clock timestamp.";
        else if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Sector byte size=128 shifted left by this code.";
        break;
    case 0x602f0056U:
        if(!xx_rt_wcscmp(r->name,L"logical_sectors_per_track"))s=L"Number of 128-byte logical sectors.";
        else if(!xx_rt_wcscmp(r->name,L"block_shift"))s=L"Allocation block size=128 shifted left by this value.";
        else if(!xx_rt_wcscmp(r->name,L"maximum_block_number"))s=L"Encoded allocation block count minus one.";
        else if(!xx_rt_wcscmp(r->name,L"maximum_directory_entry"))s=L"Encoded directory-entry count minus one.";
        else if(!xx_rt_wcscmp(r->name,L"check_vector_size"))s=L"Directory check-vector entry count; high bit has fixed-media meaning.";
        else if(!xx_rt_wcscmp(r->name,L"sector_shift"))s=L"Physical sector size=128 shifted left by this value.";
        break;
    case 0x602f0058U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Sector size=128 shifted left by this code.";
        break;
    case 0x602f0059U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Sector size=128 shifted left by this code.";
        break;
    case 0x602f005aU:
        if(!xx_rt_wcscmp(r->name,L"track_offset"))s=L"File-relative byte offset of the track header; zero means absent.";
        break;
    case 0x602f005bU:
        if(!xx_rt_wcscmp(r->name,L"additional_info"))s=L"Stored additional-info word; the native reader does not interpret its bits.";
        break;
    case 0x602f005dU:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Nominal sector byte size=128 shifted left by this code.";
        break;
    case 0x602f005eU:
        if(!xx_rt_wcscmp(r->name,L"track_table_block"))s=L"File-relative 512-byte block index of the track table.";
        else if(!xx_rt_wcscmp(r->name,L"write_allowed"))s=L"0=write protected,0xff=unprotected.";
        else if(!xx_rt_wcscmp(r->name,L"single_step"))s=L"0=double step,0xff=single step.";
        else if(!xx_rt_wcscmp(r->name,L"track0_side0_alternate"))s=L"Zero selects the corresponding alternate encoding;0xff uses the global encoding.";
        else if(!xx_rt_wcscmp(r->name,L"track0_side1_alternate"))s=L"Zero selects the corresponding alternate encoding;0xff uses the global encoding.";
        else if(!xx_rt_wcscmp(r->name,L"unused_header_bytes"))s=L"Unused bytes, conventionally0xff.";
        break;
    case 0x602f005fU:
        if(!xx_rt_wcscmp(r->name,L"data_block"))s=L"File-relative 512-byte block index.";
        else if(!xx_rt_wcscmp(r->name,L"track_size"))s=L"Byte length including the two interleaved sides.";
        break;
    case 0x602f0060U:
        if(!xx_rt_wcscmp(r->name,L"tick_period"))s=L"Encoded native clock-period value; no conversion is applied.";
        break;
    case 0x602f0061U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"Bit 0 means raw LZ4 block.";
        else if(!xx_rt_wcscmp(r->name,L"opaque_10"))s=L"Observed native value 5000000; semantic unit not established.";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* No decoded sectors or synthesized metadata: every descriptor names bytes in
 * the original device. Display budgets leave the omitted physical bytes raw. */
bool sxse_span(sx_context*c,uint64_t p,uint64_t n){return p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxse_read(sx_context*c,uint64_t p,void*b,size_t n){return sxse_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint16_t sxse_u16(const void*b,unsigned p,bool be){return xx_data_get_u16((const uint8_t*)b+p,2,0,be);}
uint32_t sxse_u32(const void*b,unsigned p,bool be){return xx_data_get_u32((const uint8_t*)b+p,4,0,be);}
bool sxse_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t z,uint64_t n){
 if(!n)return true;if(!z||n>INT64_MAX/z||!sxse_span(c,p,z*n))return false;
 if(c->count>=24000)return true;
 for(size_t i=0;i<c->count;i++){uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),b=(uint64_t)c->items[i].total_size;if(p<a+b&&a<p+z*n)return true;}
 return sx_table(c,l,(int64_t)p,(int64_t)z,n);
}
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
#define SXSE_TABLE(c,l,p,z,n) sxse_put(c,&sxse_##l,p,z,n)
bool sxse_chunks(sx_context*c,bool woz,bool a2r){uint8_t h[20],b[16];uint64_t p=woz?12:a2r?8:0,end=(uint64_t)c->size;unsigned version=0;
 if(woz||a2r){if(!sxse_read(c,0,h,(size_t)p))return false;version=h[3]-'0';if(!sxse_put(c,woz?&sxse_woz_header:&sxse_a2r_header,0,p,1))return false;}
 for(unsigned visit=0;p<end&&visit<65536;visit++){if(!sxse_read(c,p,h,8))return false;uint64_t z=sxse_u32(h,4,false),q=p+8;if(!sxse_span(c,q,z)||!SXSE_ADD(c,disk_chunk_header,p,8))return false;
 if(woz){if(!xx_rt_memcmp(h,"INFO",4)){if(z!=60||!sxse_read(c,q,b,1)||b[0]<1||b[0]>3||!sxse_put(c,b[0]==1?&sxse_woz_info_v1:b[0]==2?&sxse_woz_info_v2:&sxse_woz_info_v3,q,60,1))return false;}else if(!xx_rt_memcmp(h,"TMAP",4)||!xx_rt_memcmp(h,"FLUX",4)){if(z!=160||!SXSE_TABLE(c,woz_track_map,q,1,160))return false;}else if(!xx_rt_memcmp(h,"TRKS",4)){if(version==1){if(z%6656)return false;for(uint64_t i=0;i<z/6656;i++)if(!SXSE_ADD(c,woz1_track_metadata,q+i*6656+6646,10))return false;}else{if(z<1280||!SXSE_TABLE(c,woz2_track_entry,q,8,160))return false;}}}
 else if(a2r){if(!xx_rt_memcmp(h,"INFO",4)){if(z!=(version==2?36U:37U)||!sxse_put(c,version==2?&sxse_a2r_info_v2:&sxse_a2r_info_v3,q,z,1))return false;}else if(!xx_rt_memcmp(h,"STRM",4)&&version==2){uint64_t t=q,limit=q+z;for(unsigned k=0;t<limit&&k<65536;k++){if(!sxse_read(c,t,b,1))return false;if(b[0]==255){if(!SXSE_ADD(c,a2r_stream_end,t,1))return false;t++;break;}if(limit-t<10||!sxse_read(c,t,b,10))return false;uint64_t n=sxse_u32(b,2,false);if(n>limit-t-10||!SXSE_ADD(c,a2r2_capture,t,10))return false;t+=10+n;}if(t!=limit)return false;}
 else if((!xx_rt_memcmp(h,"RWCP",4)||!xx_rt_memcmp(h,"SLVD",4))&&version==3){bool solved=!xx_rt_memcmp(h,"SLVD",4);if(z<16||!SXSE_ADD(c,a2r3_capture_chunk,q,16))return false;uint64_t t=q+16,limit=q+z;for(unsigned k=0;t<limit&&k<65536;k++){if(!sxse_read(c,t,b,1))return false;if(b[0]=='X'){if(!SXSE_ADD(c,a2r_stream_end,t,1))return false;t++;break;}unsigned hs=solved?12:5;if(limit-t<hs||!sxse_read(c,t,b,hs))return false;unsigned n=b[solved?11:4];if((uint64_t)hs+4*n+4>limit-t||!sxse_put(c,solved?&sxse_a2r3_solved_track:&sxse_a2r3_capture,t,hs,1)||!SXSE_TABLE(c,a2r3_index_time,t+hs,4,n))return false;t+=hs+4*n;uint32_t len;if(!sx_u32(c,(int64_t)t,false,&len)||len>limit-t-4||!SXSE_ADD(c,a2r_capture_size,t,4))return false;t+=4+(uint64_t)len;}if(t!=limit)return false;}}
 else{if(!xx_rt_memcmp(h,"PZXT",4)){if(z<2||!SXSE_ADD(c,pzx_version,q,2))return false;}else if(!xx_rt_memcmp(h,"DATA",4)){if(z<8||!sxse_read(c,q,b,8)||8+2*((unsigned)b[6]+b[7])>z||!SXSE_ADD(c,pzx_data,q,8)||!SXSE_TABLE(c,pzx_pulse_duration,q+8,2,(unsigned)b[6]+b[7]))return false;}else if(!xx_rt_memcmp(h,"PAUS",4)){if(z!=4||!SXSE_ADD(c,pzx_pause,q,4))return false;}else if(!xx_rt_memcmp(h,"STOP",4)){if(z!=2||!SXSE_ADD(c,pzx_stop,q,2))return false;}}
 p=q+z;}return p==end;}
bool sxse_hfe(sx_context*c,bool stream){uint8_t b[48];if(!sxse_read(c,0,b,stream?48:26))return false;if(stream){uint64_t n=(uint64_t)sxse_u32(b,36,false)*sxse_u32(b,40,false),p=sxse_u32(b,28,false);return n<=512&&p>=48&&SXSE_ADD(c,stream_hfe_header,0,48)&&SXSE_TABLE(c,stream_hfe_track,p,32,n);}uint64_t p=(uint64_t)sxse_u16(b,18,false)*512;return b[9]&&p>=512&&SXSE_ADD(c,hfe_header,0,512)&&SXSE_TABLE(c,hfe_track_entry,p,4,b[9]);}
static int sxse_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxse_finish(sx_context*c){size_t n=c->count;int64_t end=0;if(!n)return false;xx_rt_qsort(c->items,n,sizeof(*c->items),sxse_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxse_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_systemextra_supports(xx_file_type_t t){switch(t){
case XX_FILE_TYPE_VICE_X64:
case XX_FILE_TYPE_COMMODORE_G64:
case XX_FILE_TYPE_COMMODORE_P64:
case XX_FILE_TYPE_COMMODORE_TAP:
case XX_FILE_TYPE_ZX_SPECTRUM_TZX:
case XX_FILE_TYPE_AMSTRAD_CPC_DSK:
case XX_FILE_TYPE_ATARI_ST_MSA:
case XX_FILE_TYPE_SUPERCARD_SCP:
case XX_FILE_TYPE_APPLE_WOZ:
case XX_FILE_TYPE_ZX_SPECTRUM_PZX:
case XX_FILE_TYPE_ACORN_UEF:
case XX_FILE_TYPE_COMMODORE_PC64:
case XX_FILE_TYPE_ATARI_CAS:
case XX_FILE_TYPE_ORIC_TAP:
case XX_FILE_TYPE_DRAGON_VDK:
case XX_FILE_TYPE_APPLE_A2R:
case XX_FILE_TYPE_ATARI_ATR:
case XX_FILE_TYPE_ATARI_PASTI_STX:
case XX_FILE_TYPE_HXC_MFM:
case XX_FILE_TYPE_YAZE_YDSK:
case XX_FILE_TYPE_T98_NEXT_NFD:
case XX_FILE_TYPE_HFE:
case XX_FILE_TYPE_HXC_STREAM_HFE:
case XX_FILE_TYPE_HXC_HFE_EXTENDED:
case XX_FILE_TYPE_HXC_HFE_HDDD_A2_VARIANT:
case XX_FILE_TYPE_HXC_HFE_V3:
return true;default:return false;}}
static bool sx_systemextra_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_VICE_X64:ok=sx_vice_x64_build(c);break;
case XX_FILE_TYPE_COMMODORE_G64:ok=sx_commodore_g64_build(c);break;
case XX_FILE_TYPE_COMMODORE_P64:ok=sx_commodore_p64_build(c);break;
case XX_FILE_TYPE_COMMODORE_TAP:ok=sx_commodore_tap_build(c);break;
case XX_FILE_TYPE_ZX_SPECTRUM_TZX:ok=sx_zx_spectrum_tzx_build(c);break;
case XX_FILE_TYPE_AMSTRAD_CPC_DSK:ok=sx_amstrad_cpc_dsk_build(c);break;
case XX_FILE_TYPE_ATARI_ST_MSA:ok=sx_atari_st_msa_build(c);break;
case XX_FILE_TYPE_SUPERCARD_SCP:ok=sx_supercard_scp_build(c);break;
case XX_FILE_TYPE_APPLE_WOZ:ok=sx_apple_woz_build(c);break;
case XX_FILE_TYPE_ZX_SPECTRUM_PZX:ok=sx_zx_spectrum_pzx_build(c);break;
case XX_FILE_TYPE_ACORN_UEF:ok=sx_acorn_uef_build(c);break;
case XX_FILE_TYPE_COMMODORE_PC64:ok=sx_commodore_pc64_build(c);break;
case XX_FILE_TYPE_ATARI_CAS:ok=sx_atari_cas_build(c);break;
case XX_FILE_TYPE_ORIC_TAP:ok=sx_oric_tap_build(c);break;
case XX_FILE_TYPE_DRAGON_VDK:ok=sx_dragon_vdk_build(c);break;
case XX_FILE_TYPE_APPLE_A2R:ok=sx_apple_a2r_build(c);break;
case XX_FILE_TYPE_ATARI_ATR:ok=sx_atari_atr_build(c);break;
case XX_FILE_TYPE_ATARI_PASTI_STX:ok=sx_atari_pasti_stx_build(c);break;
case XX_FILE_TYPE_HXC_MFM:ok=sx_hxc_mfm_build(c);break;
case XX_FILE_TYPE_YAZE_YDSK:ok=sx_yaze_ydsk_build(c);break;
case XX_FILE_TYPE_T98_NEXT_NFD:ok=sx_t98_next_nfd_build(c);break;
case XX_FILE_TYPE_HFE:ok=sx_hfe_build(c);break;
case XX_FILE_TYPE_HXC_STREAM_HFE:ok=sx_hxc_stream_hfe_build(c);break;
case XX_FILE_TYPE_HXC_HFE_EXTENDED:ok=sx_hxc_hfe_extended_build(c);break;
case XX_FILE_TYPE_HXC_HFE_HDDD_A2_VARIANT:ok=sx_hxc_hfe_hddd_a2_variant_build(c);break;
case XX_FILE_TYPE_HXC_HFE_V3:ok=sx_hxc_hfe_v3_build(c);break;
default:break;}return ok&&sxse_finish(c);}
#undef SXSE_ADD
#undef SXSE_TABLE
const sx_family sx_systemextra_family={sx_systemextra_supports,sx_systemextra_build,sx_systemextra_layouts,SX_COUNT(sx_systemextra_layouts),sx_systemextra_comment};
