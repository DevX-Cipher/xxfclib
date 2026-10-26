#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#include "xx_format_schema_disknext.h"
/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical legacy disk image metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_disknext_scope.txt. */
static const xx_data_struct_field_desc sxdn_jvc_header_1_fields[] = {
    SX_FIELD("sectors_per_track","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxdn_jvc_header_1 = {0x60780008U,"jvc_header_1",sxdn_jvc_header_1_fields,SX_COUNT(sxdn_jvc_header_1_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_jvc_header_2_fields[] = {
    SX_FIELD("sectors_per_track","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("sides","uint8",1,1,SX_COUNT_PROP),
};
static const sx_layout sxdn_jvc_header_2 = {0x60780009U,"jvc_header_2",sxdn_jvc_header_2_fields,SX_COUNT(sxdn_jvc_header_2_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_jvc_header_3_fields[] = {
    SX_FIELD("sectors_per_track","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("sides","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("sector_size_code","uint8",2,1,SX_NONE),
};
static const sx_layout sxdn_jvc_header_3 = {0x6078000aU,"jvc_header_3",sxdn_jvc_header_3_fields,SX_COUNT(sxdn_jvc_header_3_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_jvc_header_4_fields[] = {
    SX_FIELD("sectors_per_track","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("sides","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("sector_size_code","uint8",2,1,SX_NONE),
    SX_FIELD("first_sector_id","uint8",3,1,SX_ID),
};
static const sx_layout sxdn_jvc_header_4 = {0x6078000bU,"jvc_header_4",sxdn_jvc_header_4_fields,SX_COUNT(sxdn_jvc_header_4_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_jvc_header_5_fields[] = {
    SX_FIELD("sectors_per_track","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("sides","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("sector_size_code","uint8",2,1,SX_NONE),
    SX_FIELD("first_sector_id","uint8",3,1,SX_ID),
    SX_FIELD("sector_attribute_flag","uint8",4,1,SX_FLAGS),
};
static const sx_layout sxdn_jvc_header_5 = {0x6078000cU,"jvc_header_5",sxdn_jvc_header_5_fields,SX_COUNT(sxdn_jvc_header_5_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_disk_descriptor_keyword_fields[] = {
    SX_FIELD("value","utf8",0,0,SX_NONE),
};
static const sx_layout sxdn_disk_descriptor_keyword = {0x60780033U,"disk_descriptor_keyword",sxdn_disk_descriptor_keyword_fields,SX_COUNT(sxdn_disk_descriptor_keyword_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_disk_descriptor_string_fields[] = {
    SX_FIELD("value","utf8",0,0,SX_STRING),
};
const sx_layout sxdn_disk_descriptor_string = {0x60780034U,"disk_descriptor_string",sxdn_disk_descriptor_string_fields,SX_COUNT(sxdn_disk_descriptor_string_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_psa_disk_header_fields[] = {
    SX_FIELD("signature","char[21]",0,21,SX_SIGNATURE),
    SX_FIELD("variant","uint8",21,1,SX_ID),
    SX_FIELD("unknown0","byte[8]",22,8,SX_NONE),
    SX_FIELD("sector_count","uint32",30,4,SX_COUNT_PROP),
    SX_FIELD("unknown1","byte[50]",34,50,SX_NONE),
};
static const sx_layout sxdn_psa_disk_header = {0x60780047U,"psa_disk_header",sxdn_psa_disk_header_fields,SX_COUNT(sxdn_psa_disk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_psa_fat_bpb_fields[] = {
    SX_FIELD("jump","byte[3]",0,3,SX_NONE),
    SX_FIELD("oem_name","char[8]",3,8,SX_NONE),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sectors","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",16,1,SX_COUNT_PROP),
    SX_FIELD("root_entry_count","uint16",17,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors_16","uint16",19,2,SX_COUNT_PROP),
    SX_FIELD("media","uint8",21,1,SX_ID),
    SX_FIELD("sectors_per_fat","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sectors","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("total_sectors_32","uint32",32,4,SX_COUNT_PROP),
};
static const sx_layout sxdn_psa_fat_bpb = {0x60780048U,"psa_fat_bpb",sxdn_psa_fat_bpb_fields,SX_COUNT(sxdn_psa_fat_bpb_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_psa_fat1216_extension_fields[] = {
    SX_FIELD("drive_number","uint8",0,1,SX_ID),
    SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
    SX_FIELD("extended_signature","uint8",2,1,SX_SIGNATURE),
    SX_FIELD("volume_serial","uint32",3,4,SX_ID),
    SX_FIELD("volume_label","char[11]",7,11,SX_NONE),
    SX_FIELD("filesystem_label","char[8]",18,8,SX_NONE),
};
static const sx_layout sxdn_psa_fat1216_extension = {0x60780049U,"psa_fat1216_extension",sxdn_psa_fat1216_extension_fields,SX_COUNT(sxdn_psa_fat1216_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_gdi_track_count_fields[] = {
    SX_FIELD("track_count","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_gdi_track_count = {0x60780065U,"gdi_track_count",sxdn_gdi_track_count_fields,SX_COUNT(sxdn_gdi_track_count_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_gdi_track_number_fields[] = {
    SX_FIELD("track_number","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_gdi_track_number = {0x60780066U,"gdi_track_number",sxdn_gdi_track_number_fields,SX_COUNT(sxdn_gdi_track_number_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_gdi_lba_fields[] = {
    SX_FIELD("lba","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_gdi_lba = {0x60780067U,"gdi_lba",sxdn_gdi_lba_fields,SX_COUNT(sxdn_gdi_lba_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_gdi_control_fields[] = {
    SX_FIELD("control","ascii_signed",0,0,SX_FLAGS),
};
static const sx_layout sxdn_gdi_control = {0x60780068U,"gdi_control",sxdn_gdi_control_fields,SX_COUNT(sxdn_gdi_control_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_gdi_sector_size_fields[] = {
    SX_FIELD("sector_size","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxdn_gdi_sector_size = {0x60780069U,"gdi_sector_size",sxdn_gdi_sector_size_fields,SX_COUNT(sxdn_gdi_sector_size_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_gdi_filename_fields[] = {
    SX_FIELD("filename","utf8",0,0,SX_STRING),
};
static const sx_layout sxdn_gdi_filename = {0x6078006aU,"gdi_filename",sxdn_gdi_filename_fields,SX_COUNT(sxdn_gdi_filename_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_gdi_file_offset_fields[] = {
    SX_FIELD("file_offset","ascii_signed",0,0,SX_OFFSET),
};
static const sx_layout sxdn_gdi_file_offset = {0x6078006bU,"gdi_file_offset",sxdn_gdi_file_offset_fields,SX_COUNT(sxdn_gdi_file_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_cue_track_number_fields[] = {
    SX_FIELD("track_number","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_cue_track_number = {0x6078006cU,"cue_track_number",sxdn_cue_track_number_fields,SX_COUNT(sxdn_cue_track_number_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_cue_index_number_fields[] = {
    SX_FIELD("index_number","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_cue_index_number = {0x6078006dU,"cue_index_number",sxdn_cue_index_number_fields,SX_COUNT(sxdn_cue_index_number_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_cue_position_fields[] = {
    SX_FIELD("msf_position","utf8",0,0,SX_NONE),
};
static const sx_layout sxdn_cue_position = {0x6078006eU,"cue_position",sxdn_cue_position_fields,SX_COUNT(sxdn_cue_position_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_cue_file_fields[] = {
    SX_FIELD("filename","utf8",0,0,SX_STRING),
};
static const sx_layout sxdn_cue_file = {0x6078006fU,"cue_file",sxdn_cue_file_fields,SX_COUNT(sxdn_cue_file_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_cue_mode_fields[] = {
    SX_FIELD("mode","utf8",0,0,SX_ID),
};
static const sx_layout sxdn_cue_mode = {0x60780070U,"cue_mode",sxdn_cue_mode_fields,SX_COUNT(sxdn_cue_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_cue_file_type_fields[] = {
    SX_FIELD("file_type","utf8",0,0,SX_ID),
};
static const sx_layout sxdn_cue_file_type = {0x60780071U,"cue_file_type",sxdn_cue_file_type_fields,SX_COUNT(sxdn_cue_file_type_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_trail_bytes_fields[] = {
    SX_FIELD("trail_bytes","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxdn_ldbst_trail_bytes = {0x60780072U,"ldbst_trail_bytes",sxdn_ldbst_trail_bytes_fields,SX_COUNT(sxdn_ldbst_trail_bytes_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_toc_start_fields[] = {
    SX_FIELD("start_position","utf8",0,0,SX_NONE),
};
static const sx_layout sxdn_toc_start = {0x60780073U,"toc_start",sxdn_toc_start_fields,SX_COUNT(sxdn_toc_start_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_toc_length_fields[] = {
    SX_FIELD("length","utf8",0,0,SX_NONE),
};
static const sx_layout sxdn_toc_length = {0x60780074U,"toc_length",sxdn_toc_length_fields,SX_COUNT(sxdn_toc_length_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_toc_filename_fields[] = {
    SX_FIELD("filename","utf8",0,0,SX_STRING),
};
static const sx_layout sxdn_toc_filename = {0x60780075U,"toc_filename",sxdn_toc_filename_fields,SX_COUNT(sxdn_toc_filename_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_psa_fat32_extension_fields[] = {
    SX_FIELD("sectors_per_fat_32","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("extended_flags","uint16",4,2,SX_FLAGS),
    SX_FIELD("version","uint16",6,2,SX_ID),
    SX_FIELD("root_directory_cluster","uint32",8,4,SX_NONE),
    SX_FIELD("fsinfo_sector","uint16",12,2,SX_NONE),
    SX_FIELD("backup_boot_sector","uint16",14,2,SX_NONE),
    SX_FIELD("reserved","byte[12]",16,12,SX_RESERVED),
    SX_FIELD("drive_number","uint8",28,1,SX_ID),
    SX_FIELD("reserved2","uint8",29,1,SX_RESERVED),
    SX_FIELD("extended_signature","uint8",30,1,SX_SIGNATURE),
    SX_FIELD("volume_serial","uint32",31,4,SX_ID),
    SX_FIELD("volume_label","char[11]",35,11,SX_NONE),
    SX_FIELD("filesystem_label","char[8]",46,8,SX_NONE),
};
static const sx_layout sxdn_psa_fat32_extension = {0x60780076U,"psa_fat32_extension",sxdn_psa_fat32_extension_fields,SX_COUNT(sxdn_psa_fat32_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_version_fields[] = {
    SX_FIELD("version","ascii_signed",0,0,SX_ID),
};
static const sx_layout sxdn_ccd_version = {0x60780077U,"ccd_version",sxdn_ccd_version_fields,SX_COUNT(sxdn_ccd_version_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_version_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("version","ascii_hex",2,0,SX_ID),
};
static const sx_layout sxdn_ccd_version_hex = {0x60780078U,"ccd_version_hex",sxdn_ccd_version_hex_fields,SX_COUNT(sxdn_ccd_version_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_toc_entries_fields[] = {
    SX_FIELD("toc_entries","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_ccd_toc_entries = {0x60780079U,"ccd_toc_entries",sxdn_ccd_toc_entries_fields,SX_COUNT(sxdn_ccd_toc_entries_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_toc_entries_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("toc_entries","ascii_hex",2,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_ccd_toc_entries_hex = {0x6078007aU,"ccd_toc_entries_hex",sxdn_ccd_toc_entries_hex_fields,SX_COUNT(sxdn_ccd_toc_entries_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_sessions_fields[] = {
    SX_FIELD("sessions","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_ccd_sessions = {0x6078007bU,"ccd_sessions",sxdn_ccd_sessions_fields,SX_COUNT(sxdn_ccd_sessions_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_sessions_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("sessions","ascii_hex",2,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_ccd_sessions_hex = {0x6078007cU,"ccd_sessions_hex",sxdn_ccd_sessions_hex_fields,SX_COUNT(sxdn_ccd_sessions_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_data_tracks_scrambled_fields[] = {
    SX_FIELD("data_tracks_scrambled","ascii_signed",0,0,SX_FLAGS),
};
static const sx_layout sxdn_ccd_data_tracks_scrambled = {0x6078007dU,"ccd_data_tracks_scrambled",sxdn_ccd_data_tracks_scrambled_fields,SX_COUNT(sxdn_ccd_data_tracks_scrambled_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_data_tracks_scrambled_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("data_tracks_scrambled","ascii_hex",2,0,SX_FLAGS),
};
static const sx_layout sxdn_ccd_data_tracks_scrambled_hex = {0x6078007eU,"ccd_data_tracks_scrambled_hex",sxdn_ccd_data_tracks_scrambled_hex_fields,SX_COUNT(sxdn_ccd_data_tracks_scrambled_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_cd_text_length_fields[] = {
    SX_FIELD("cd_text_length","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxdn_ccd_cd_text_length = {0x6078007fU,"ccd_cd_text_length",sxdn_ccd_cd_text_length_fields,SX_COUNT(sxdn_ccd_cd_text_length_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_cd_text_length_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("cd_text_length","ascii_hex",2,0,SX_SIZE),
};
static const sx_layout sxdn_ccd_cd_text_length_hex = {0x60780080U,"ccd_cd_text_length_hex",sxdn_ccd_cd_text_length_hex_fields,SX_COUNT(sxdn_ccd_cd_text_length_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_pregap_mode_fields[] = {
    SX_FIELD("pregap_mode","ascii_signed",0,0,SX_ID),
};
static const sx_layout sxdn_ccd_pregap_mode = {0x60780081U,"ccd_pregap_mode",sxdn_ccd_pregap_mode_fields,SX_COUNT(sxdn_ccd_pregap_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_pregap_mode_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("pregap_mode","ascii_hex",2,0,SX_ID),
};
static const sx_layout sxdn_ccd_pregap_mode_hex = {0x60780082U,"ccd_pregap_mode_hex",sxdn_ccd_pregap_mode_hex_fields,SX_COUNT(sxdn_ccd_pregap_mode_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_pregap_subchannel_fields[] = {
    SX_FIELD("pregap_subchannel","ascii_signed",0,0,SX_FLAGS),
};
static const sx_layout sxdn_ccd_pregap_subchannel = {0x60780083U,"ccd_pregap_subchannel",sxdn_ccd_pregap_subchannel_fields,SX_COUNT(sxdn_ccd_pregap_subchannel_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_pregap_subchannel_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("pregap_subchannel","ascii_hex",2,0,SX_FLAGS),
};
static const sx_layout sxdn_ccd_pregap_subchannel_hex = {0x60780084U,"ccd_pregap_subchannel_hex",sxdn_ccd_pregap_subchannel_hex_fields,SX_COUNT(sxdn_ccd_pregap_subchannel_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_session_fields[] = {
    SX_FIELD("session","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ccd_session = {0x60780085U,"ccd_session",sxdn_ccd_session_fields,SX_COUNT(sxdn_ccd_session_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_session_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("session","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ccd_session_hex = {0x60780086U,"ccd_session_hex",sxdn_ccd_session_hex_fields,SX_COUNT(sxdn_ccd_session_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_point_fields[] = {
    SX_FIELD("point","ascii_signed",0,0,SX_ID),
};
static const sx_layout sxdn_ccd_point = {0x60780087U,"ccd_point",sxdn_ccd_point_fields,SX_COUNT(sxdn_ccd_point_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_point_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("point","ascii_hex",2,0,SX_ID),
};
static const sx_layout sxdn_ccd_point_hex = {0x60780088U,"ccd_point_hex",sxdn_ccd_point_hex_fields,SX_COUNT(sxdn_ccd_point_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_adr_fields[] = {
    SX_FIELD("adr","ascii_signed",0,0,SX_ID),
};
static const sx_layout sxdn_ccd_adr = {0x60780089U,"ccd_adr",sxdn_ccd_adr_fields,SX_COUNT(sxdn_ccd_adr_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_adr_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("adr","ascii_hex",2,0,SX_ID),
};
static const sx_layout sxdn_ccd_adr_hex = {0x6078008aU,"ccd_adr_hex",sxdn_ccd_adr_hex_fields,SX_COUNT(sxdn_ccd_adr_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_control_fields[] = {
    SX_FIELD("control","ascii_signed",0,0,SX_FLAGS),
};
static const sx_layout sxdn_ccd_control = {0x6078008bU,"ccd_control",sxdn_ccd_control_fields,SX_COUNT(sxdn_ccd_control_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_control_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("control","ascii_hex",2,0,SX_FLAGS),
};
static const sx_layout sxdn_ccd_control_hex = {0x6078008cU,"ccd_control_hex",sxdn_ccd_control_hex_fields,SX_COUNT(sxdn_ccd_control_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_track_number_fields[] = {
    SX_FIELD("track_number","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ccd_track_number = {0x6078008dU,"ccd_track_number",sxdn_ccd_track_number_fields,SX_COUNT(sxdn_ccd_track_number_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_track_number_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("track_number","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ccd_track_number_hex = {0x6078008eU,"ccd_track_number_hex",sxdn_ccd_track_number_hex_fields,SX_COUNT(sxdn_ccd_track_number_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_absolute_minute_fields[] = {
    SX_FIELD("absolute_minute","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ccd_absolute_minute = {0x6078008fU,"ccd_absolute_minute",sxdn_ccd_absolute_minute_fields,SX_COUNT(sxdn_ccd_absolute_minute_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_absolute_minute_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("absolute_minute","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ccd_absolute_minute_hex = {0x60780090U,"ccd_absolute_minute_hex",sxdn_ccd_absolute_minute_hex_fields,SX_COUNT(sxdn_ccd_absolute_minute_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_absolute_second_fields[] = {
    SX_FIELD("absolute_second","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ccd_absolute_second = {0x60780091U,"ccd_absolute_second",sxdn_ccd_absolute_second_fields,SX_COUNT(sxdn_ccd_absolute_second_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_absolute_second_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("absolute_second","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ccd_absolute_second_hex = {0x60780092U,"ccd_absolute_second_hex",sxdn_ccd_absolute_second_hex_fields,SX_COUNT(sxdn_ccd_absolute_second_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_absolute_frame_fields[] = {
    SX_FIELD("absolute_frame","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ccd_absolute_frame = {0x60780093U,"ccd_absolute_frame",sxdn_ccd_absolute_frame_fields,SX_COUNT(sxdn_ccd_absolute_frame_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_absolute_frame_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("absolute_frame","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ccd_absolute_frame_hex = {0x60780094U,"ccd_absolute_frame_hex",sxdn_ccd_absolute_frame_hex_fields,SX_COUNT(sxdn_ccd_absolute_frame_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_absolute_lba_fields[] = {
    SX_FIELD("absolute_lba","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ccd_absolute_lba = {0x60780095U,"ccd_absolute_lba",sxdn_ccd_absolute_lba_fields,SX_COUNT(sxdn_ccd_absolute_lba_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_absolute_lba_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("absolute_lba","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ccd_absolute_lba_hex = {0x60780096U,"ccd_absolute_lba_hex",sxdn_ccd_absolute_lba_hex_fields,SX_COUNT(sxdn_ccd_absolute_lba_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_zero_fields[] = {
    SX_FIELD("zero","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ccd_zero = {0x60780097U,"ccd_zero",sxdn_ccd_zero_fields,SX_COUNT(sxdn_ccd_zero_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_zero_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("zero","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ccd_zero_hex = {0x60780098U,"ccd_zero_hex",sxdn_ccd_zero_hex_fields,SX_COUNT(sxdn_ccd_zero_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_pminute_fields[] = {
    SX_FIELD("pminute","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ccd_pminute = {0x60780099U,"ccd_pminute",sxdn_ccd_pminute_fields,SX_COUNT(sxdn_ccd_pminute_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_pminute_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("pminute","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ccd_pminute_hex = {0x6078009aU,"ccd_pminute_hex",sxdn_ccd_pminute_hex_fields,SX_COUNT(sxdn_ccd_pminute_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_psecond_fields[] = {
    SX_FIELD("psecond","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ccd_psecond = {0x6078009bU,"ccd_psecond",sxdn_ccd_psecond_fields,SX_COUNT(sxdn_ccd_psecond_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_psecond_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("psecond","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ccd_psecond_hex = {0x6078009cU,"ccd_psecond_hex",sxdn_ccd_psecond_hex_fields,SX_COUNT(sxdn_ccd_psecond_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_pframe_fields[] = {
    SX_FIELD("pframe","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ccd_pframe = {0x6078009dU,"ccd_pframe",sxdn_ccd_pframe_fields,SX_COUNT(sxdn_ccd_pframe_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_pframe_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("pframe","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ccd_pframe_hex = {0x6078009eU,"ccd_pframe_hex",sxdn_ccd_pframe_hex_fields,SX_COUNT(sxdn_ccd_pframe_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_plba_fields[] = {
    SX_FIELD("plba","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ccd_plba = {0x6078009fU,"ccd_plba",sxdn_ccd_plba_fields,SX_COUNT(sxdn_ccd_plba_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_plba_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("plba","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ccd_plba_hex = {0x607800a0U,"ccd_plba_hex",sxdn_ccd_plba_hex_fields,SX_COUNT(sxdn_ccd_plba_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_mode_fields[] = {
    SX_FIELD("mode","ascii_signed",0,0,SX_ID),
};
static const sx_layout sxdn_ccd_mode = {0x607800a1U,"ccd_mode",sxdn_ccd_mode_fields,SX_COUNT(sxdn_ccd_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_mode_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("mode","ascii_hex",2,0,SX_ID),
};
static const sx_layout sxdn_ccd_mode_hex = {0x607800a2U,"ccd_mode_hex",sxdn_ccd_mode_hex_fields,SX_COUNT(sxdn_ccd_mode_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_index1_fields[] = {
    SX_FIELD("index1","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ccd_index1 = {0x607800a3U,"ccd_index1",sxdn_ccd_index1_fields,SX_COUNT(sxdn_ccd_index1_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ccd_index1_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("index1","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ccd_index1_hex = {0x607800a4U,"ccd_index1_hex",sxdn_ccd_index1_hex_fields,SX_COUNT(sxdn_ccd_index1_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_cylinder_fields[] = {
    SX_FIELD("cylinder","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_cylinder = {0x607800a5U,"ldbst_cylinder",sxdn_ldbst_cylinder_fields,SX_COUNT(sxdn_ldbst_cylinder_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_cylinder_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("cylinder","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_cylinder_hex = {0x607800a6U,"ldbst_cylinder_hex",sxdn_ldbst_cylinder_hex_fields,SX_COUNT(sxdn_ldbst_cylinder_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_head_fields[] = {
    SX_FIELD("head","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_head = {0x607800a7U,"ldbst_head",sxdn_ldbst_head_fields,SX_COUNT(sxdn_ldbst_head_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_head_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("head","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_head_hex = {0x607800a8U,"ldbst_head_hex",sxdn_ldbst_head_hex_fields,SX_COUNT(sxdn_ldbst_head_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_data_rate_fields[] = {
    SX_FIELD("data_rate","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_data_rate = {0x607800a9U,"ldbst_data_rate",sxdn_ldbst_data_rate_fields,SX_COUNT(sxdn_ldbst_data_rate_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_data_rate_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("data_rate","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_data_rate_hex = {0x607800aaU,"ldbst_data_rate_hex",sxdn_ldbst_data_rate_hex_fields,SX_COUNT(sxdn_ldbst_data_rate_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_gap3_fields[] = {
    SX_FIELD("gap3","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_gap3 = {0x607800abU,"ldbst_gap3",sxdn_ldbst_gap3_fields,SX_COUNT(sxdn_ldbst_gap3_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_gap3_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("gap3","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_gap3_hex = {0x607800acU,"ldbst_gap3_hex",sxdn_ldbst_gap3_hex_fields,SX_COUNT(sxdn_ldbst_gap3_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_filler_fields[] = {
    SX_FIELD("filler","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_filler = {0x607800adU,"ldbst_filler",sxdn_ldbst_filler_fields,SX_COUNT(sxdn_ldbst_filler_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_filler_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("filler","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_filler_hex = {0x607800aeU,"ldbst_filler_hex",sxdn_ldbst_filler_hex_fields,SX_COUNT(sxdn_ldbst_filler_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_total_length_fields[] = {
    SX_FIELD("total_length","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxdn_ldbst_total_length = {0x607800afU,"ldbst_total_length",sxdn_ldbst_total_length_fields,SX_COUNT(sxdn_ldbst_total_length_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_total_length_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("total_length","ascii_hex",2,0,SX_SIZE),
};
static const sx_layout sxdn_ldbst_total_length_hex = {0x607800b0U,"ldbst_total_length_hex",sxdn_ldbst_total_length_hex_fields,SX_COUNT(sxdn_ldbst_total_length_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_cylinders_fields[] = {
    SX_FIELD("cylinders","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_ldbst_cylinders = {0x607800b1U,"ldbst_cylinders",sxdn_ldbst_cylinders_fields,SX_COUNT(sxdn_ldbst_cylinders_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_cylinders_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("cylinders","ascii_hex",2,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_ldbst_cylinders_hex = {0x607800b2U,"ldbst_cylinders_hex",sxdn_ldbst_cylinders_hex_fields,SX_COUNT(sxdn_ldbst_cylinders_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_heads_fields[] = {
    SX_FIELD("heads","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_ldbst_heads = {0x607800b3U,"ldbst_heads",sxdn_ldbst_heads_fields,SX_COUNT(sxdn_ldbst_heads_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_heads_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("heads","ascii_hex",2,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_ldbst_heads_hex = {0x607800b4U,"ldbst_heads_hex",sxdn_ldbst_heads_hex_fields,SX_COUNT(sxdn_ldbst_heads_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_sectors_fields[] = {
    SX_FIELD("sectors","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_ldbst_sectors = {0x607800b5U,"ldbst_sectors",sxdn_ldbst_sectors_fields,SX_COUNT(sxdn_ldbst_sectors_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_sectors_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("sectors","ascii_hex",2,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_ldbst_sectors_hex = {0x607800b6U,"ldbst_sectors_hex",sxdn_ldbst_sectors_hex_fields,SX_COUNT(sxdn_ldbst_sectors_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_sector_base_fields[] = {
    SX_FIELD("sector_base","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_sector_base = {0x607800b7U,"ldbst_sector_base",sxdn_ldbst_sector_base_fields,SX_COUNT(sxdn_ldbst_sector_base_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_sector_base_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("sector_base","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_sector_base_hex = {0x607800b8U,"ldbst_sector_base_hex",sxdn_ldbst_sector_base_hex_fields,SX_COUNT(sxdn_ldbst_sector_base_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_sector_size_fields[] = {
    SX_FIELD("sector_size","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxdn_ldbst_sector_size = {0x607800b9U,"ldbst_sector_size",sxdn_ldbst_sector_size_fields,SX_COUNT(sxdn_ldbst_sector_size_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_sector_size_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("sector_size","ascii_hex",2,0,SX_SIZE),
};
static const sx_layout sxdn_ldbst_sector_size_hex = {0x607800baU,"ldbst_sector_size_hex",sxdn_ldbst_sector_size_hex_fields,SX_COUNT(sxdn_ldbst_sector_size_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_id_cylinder_fields[] = {
    SX_FIELD("id_cylinder","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_id_cylinder = {0x607800bbU,"ldbst_id_cylinder",sxdn_ldbst_id_cylinder_fields,SX_COUNT(sxdn_ldbst_id_cylinder_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_id_cylinder_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("id_cylinder","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_id_cylinder_hex = {0x607800bcU,"ldbst_id_cylinder_hex",sxdn_ldbst_id_cylinder_hex_fields,SX_COUNT(sxdn_ldbst_id_cylinder_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_id_head_fields[] = {
    SX_FIELD("id_head","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_id_head = {0x607800bdU,"ldbst_id_head",sxdn_ldbst_id_head_fields,SX_COUNT(sxdn_ldbst_id_head_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_id_head_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("id_head","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_id_head_hex = {0x607800beU,"ldbst_id_head_hex",sxdn_ldbst_id_head_hex_fields,SX_COUNT(sxdn_ldbst_id_head_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_id_sector_fields[] = {
    SX_FIELD("id_sector","ascii_signed",0,0,SX_ID),
};
static const sx_layout sxdn_ldbst_id_sector = {0x607800bfU,"ldbst_id_sector",sxdn_ldbst_id_sector_fields,SX_COUNT(sxdn_ldbst_id_sector_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_id_sector_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("id_sector","ascii_hex",2,0,SX_ID),
};
static const sx_layout sxdn_ldbst_id_sector_hex = {0x607800c0U,"ldbst_id_sector_hex",sxdn_ldbst_id_sector_hex_fields,SX_COUNT(sxdn_ldbst_id_sector_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_sector_size_code_fields[] = {
    SX_FIELD("sector_size_code","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_sector_size_code = {0x607800c1U,"ldbst_sector_size_code",sxdn_ldbst_sector_size_code_fields,SX_COUNT(sxdn_ldbst_sector_size_code_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_sector_size_code_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("sector_size_code","ascii_hex",2,0,SX_NONE),
};
static const sx_layout sxdn_ldbst_sector_size_code_hex = {0x607800c2U,"ldbst_sector_size_code_hex",sxdn_ldbst_sector_size_code_hex_fields,SX_COUNT(sxdn_ldbst_sector_size_code_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_status1_fields[] = {
    SX_FIELD("status1","ascii_signed",0,0,SX_FLAGS),
};
static const sx_layout sxdn_ldbst_status1 = {0x607800c3U,"ldbst_status1",sxdn_ldbst_status1_fields,SX_COUNT(sxdn_ldbst_status1_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_status1_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("status1","ascii_hex",2,0,SX_FLAGS),
};
static const sx_layout sxdn_ldbst_status1_hex = {0x607800c4U,"ldbst_status1_hex",sxdn_ldbst_status1_hex_fields,SX_COUNT(sxdn_ldbst_status1_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_status2_fields[] = {
    SX_FIELD("status2","ascii_signed",0,0,SX_FLAGS),
};
static const sx_layout sxdn_ldbst_status2 = {0x607800c5U,"ldbst_status2",sxdn_ldbst_status2_fields,SX_COUNT(sxdn_ldbst_status2_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_status2_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("status2","ascii_hex",2,0,SX_FLAGS),
};
static const sx_layout sxdn_ldbst_status2_hex = {0x607800c6U,"ldbst_status2_hex",sxdn_ldbst_status2_hex_fields,SX_COUNT(sxdn_ldbst_status2_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_copies_fields[] = {
    SX_FIELD("copies","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_ldbst_copies = {0x607800c7U,"ldbst_copies",sxdn_ldbst_copies_fields,SX_COUNT(sxdn_ldbst_copies_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_copies_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("copies","ascii_hex",2,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_ldbst_copies_hex = {0x607800c8U,"ldbst_copies_hex",sxdn_ldbst_copies_hex_fields,SX_COUNT(sxdn_ldbst_copies_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_data_length_fields[] = {
    SX_FIELD("data_length","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxdn_ldbst_data_length = {0x607800c9U,"ldbst_data_length",sxdn_ldbst_data_length_fields,SX_COUNT(sxdn_ldbst_data_length_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_data_length_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("data_length","ascii_hex",2,0,SX_SIZE),
};
static const sx_layout sxdn_ldbst_data_length_hex = {0x607800caU,"ldbst_data_length_hex",sxdn_ldbst_data_length_hex_fields,SX_COUNT(sxdn_ldbst_data_length_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_trail_bytes_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("trail_bytes","ascii_hex",2,0,SX_SIZE),
};
static const sx_layout sxdn_ldbst_trail_bytes_hex = {0x607800cbU,"ldbst_trail_bytes_hex",sxdn_ldbst_trail_bytes_hex_fields,SX_COUNT(sxdn_ldbst_trail_bytes_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_track_relative_offset_fields[] = {
    SX_FIELD("track_relative_offset","ascii_signed",0,0,SX_OFFSET),
};
static const sx_layout sxdn_ldbst_track_relative_offset = {0x607800ccU,"ldbst_track_relative_offset",sxdn_ldbst_track_relative_offset_fields,SX_COUNT(sxdn_ldbst_track_relative_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_track_relative_offset_hex_fields[] = {
    SX_FIELD("radix_prefix","char[2]",0,2,SX_NONE),
    SX_FIELD("track_relative_offset","ascii_hex",2,0,SX_OFFSET),
};
static const sx_layout sxdn_ldbst_track_relative_offset_hex = {0x607800cdU,"ldbst_track_relative_offset_hex",sxdn_ldbst_track_relative_offset_hex_fields,SX_COUNT(sxdn_ldbst_track_relative_offset_hex_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_version_fields[] = {
    SX_FIELD("version","utf8",0,0,SX_ID),
};
static const sx_layout sxdn_ldbst_version = {0x607800ceU,"ldbst_version",sxdn_ldbst_version_fields,SX_COUNT(sxdn_ldbst_version_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_sidedness_fields[] = {
    SX_FIELD("sidedness","utf8",0,0,SX_ID),
};
static const sx_layout sxdn_ldbst_sidedness = {0x607800cfU,"ldbst_sidedness",sxdn_ldbst_sidedness_fields,SX_COUNT(sxdn_ldbst_sidedness_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_complement_fields[] = {
    SX_FIELD("complement","utf8",0,0,SX_FLAGS),
};
static const sx_layout sxdn_ldbst_complement = {0x607800d0U,"ldbst_complement",sxdn_ldbst_complement_fields,SX_COUNT(sxdn_ldbst_complement_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_ldbst_recording_mode_fields[] = {
    SX_FIELD("recording_mode","utf8",0,0,SX_ID),
};
static const sx_layout sxdn_ldbst_recording_mode = {0x607800d1U,"ldbst_recording_mode",sxdn_ldbst_recording_mode_fields,SX_COUNT(sxdn_ldbst_recording_mode_fields),SX_LE};
static const sx_layout *const sx_disknext_layouts[] = {
    &sxdn_emt_header,
    &sxdn_msx_cas_binary_header,
    &sxdn_dragon_cas_block_header,
    &sxdn_dragon_cas_file_header,
    &sxdn_dragon_cas_block_checksum,
    &sxdn_hobeta_header,
    &sxdn_hobeta_code_header,
    &sxdn_jvc_header_1,
    &sxdn_jvc_header_2,
    &sxdn_jvc_header_3,
    &sxdn_jvc_header_4,
    &sxdn_jvc_header_5,
    &sxdn_rsdos_vdk_header,
    &sxdn_rsdos_granule,
    &sxdn_rsdos_directory_entry,
    &sxdn_dragon_dos_geometry,
    &sxdn_dragon_dos_file,
    &sxdn_dragon_dos_continuation,
    &sxdn_cfd_header,
    &sxdn_cfd_block,
    &sxdn_cfd_repeat,
    &sxdn_dcp_disk_header,
    &sxdn_dcp_rdc_block,
    &sxdn_fdcopy_track,
    &sxdn_fdcopy_token,
    &sxdn_fdcopy_repeat,
    &sxdn_cp2_header,
    &sxdn_cp2_segment_header,
    &sxdn_cp2_track,
    &sxdn_cp2_sector,
    &sxdn_cp2_header_checksum,
    &sxdn_cp2_segment_payload,
    &sxdn_ecm_signature,
    &sxdn_ecm_record_first,
    &sxdn_ecm_record_continuation,
    &sxdn_ecm_edc,
    &sxdn_ecm_mode1_address,
    &sxdn_ecm_mode2_subheader,
    &sxdn_kryoflux_oob,
    &sxdn_kryoflux_eof,
    &sxdn_kryoflux_stream_info,
    &sxdn_kryoflux_stream_end,
    &sxdn_kryoflux_index,
    &sxdn_simh_cpm_directory,
    &sxdn_svd_version,
    &sxdn_svd_sectors,
    &sxdn_svd_cylinders,
    &sxdn_svd_sides,
    &sxdn_svd_sector_size_code,
    &sxdn_svd_write_protect,
    &sxdn_disk_descriptor_keyword,
    &sxdn_disk_descriptor_string,
    &sxdn_kryoflux_info_text,
    &sxdn_blindwrite4_header,
    &sxdn_blindwrite4_string_size,
    &sxdn_blindwrite4_track_count,
    &sxdn_blindwrite4_extra_prefix,
    &sxdn_blindwrite4_track,
    &sxdn_blindwrite56_signature,
    &sxdn_blindwrite56_disc,
    &sxdn_blindwrite56_inquiry,
    &sxdn_blindwrite56_volume_name,
    &sxdn_blindwrite56_lengths,
    &sxdn_blindwrite56_data_list,
    &sxdn_blindwrite56_data_block,
    &sxdn_blindwrite56_data_tail,
    &sxdn_blindwrite56_session,
    &sxdn_blindwrite56_entry,
    &sxdn_blindwrite56_cd_extra,
    &sxdn_blindwrite56_footer,
    &sxdn_psa_disk_header,
    &sxdn_psa_fat_bpb,
    &sxdn_psa_fat1216_extension,
    &sxdn_old_jffs2_common_header_le,
    &sxdn_old_jffs2_directory_entry_le,
    &sxdn_old_jffs2_inode_le,
    &sxdn_old_jffs2_xattr_le,
    &sxdn_old_jffs2_xref_le,
    &sxdn_old_jffs2_common_header_be,
    &sxdn_old_jffs2_directory_entry_be,
    &sxdn_old_jffs2_inode_be,
    &sxdn_old_jffs2_xattr_be,
    &sxdn_old_jffs2_xref_be,
    &sxdn_sqlz_squashfs2_superblock_le,
    &sxdn_sqlz_squashfs2_superblock_be,
    &sxdn_sqlz_squashfs3_superblock_le,
    &sxdn_sqlz_squashfs3_superblock_be,
    &sxdn_sqlz_squashfs_metadata_header_le,
    &sxdn_sqlz_squashfs_table_index_le,
    &sxdn_sqlz_squashfs2_fragment_index_le,
    &sxdn_sqlz_squashfs_identity_le,
    &sxdn_sqlz_squashfs_metadata_header_be,
    &sxdn_sqlz_squashfs_table_index_be,
    &sxdn_sqlz_squashfs2_fragment_index_be,
    &sxdn_sqlz_squashfs_identity_be,
    &sxdn_jvc_os9_disk_descriptor,
    &sxdn_jvc_os9_path_options,
    &sxdn_jvc_os9_file_descriptor,
    &sxdn_jvc_os9_segment,
    &sxdn_jvc_os9_directory_entry,
    &sxdn_gdi_track_count,
    &sxdn_gdi_track_number,
    &sxdn_gdi_lba,
    &sxdn_gdi_control,
    &sxdn_gdi_sector_size,
    &sxdn_gdi_filename,
    &sxdn_gdi_file_offset,
    &sxdn_cue_track_number,
    &sxdn_cue_index_number,
    &sxdn_cue_position,
    &sxdn_cue_file,
    &sxdn_cue_mode,
    &sxdn_cue_file_type,
    &sxdn_ldbst_trail_bytes,
    &sxdn_toc_start,
    &sxdn_toc_length,
    &sxdn_toc_filename,
    &sxdn_psa_fat32_extension,
    &sxdn_ccd_version,
    &sxdn_ccd_version_hex,
    &sxdn_ccd_toc_entries,
    &sxdn_ccd_toc_entries_hex,
    &sxdn_ccd_sessions,
    &sxdn_ccd_sessions_hex,
    &sxdn_ccd_data_tracks_scrambled,
    &sxdn_ccd_data_tracks_scrambled_hex,
    &sxdn_ccd_cd_text_length,
    &sxdn_ccd_cd_text_length_hex,
    &sxdn_ccd_pregap_mode,
    &sxdn_ccd_pregap_mode_hex,
    &sxdn_ccd_pregap_subchannel,
    &sxdn_ccd_pregap_subchannel_hex,
    &sxdn_ccd_session,
    &sxdn_ccd_session_hex,
    &sxdn_ccd_point,
    &sxdn_ccd_point_hex,
    &sxdn_ccd_adr,
    &sxdn_ccd_adr_hex,
    &sxdn_ccd_control,
    &sxdn_ccd_control_hex,
    &sxdn_ccd_track_number,
    &sxdn_ccd_track_number_hex,
    &sxdn_ccd_absolute_minute,
    &sxdn_ccd_absolute_minute_hex,
    &sxdn_ccd_absolute_second,
    &sxdn_ccd_absolute_second_hex,
    &sxdn_ccd_absolute_frame,
    &sxdn_ccd_absolute_frame_hex,
    &sxdn_ccd_absolute_lba,
    &sxdn_ccd_absolute_lba_hex,
    &sxdn_ccd_zero,
    &sxdn_ccd_zero_hex,
    &sxdn_ccd_pminute,
    &sxdn_ccd_pminute_hex,
    &sxdn_ccd_psecond,
    &sxdn_ccd_psecond_hex,
    &sxdn_ccd_pframe,
    &sxdn_ccd_pframe_hex,
    &sxdn_ccd_plba,
    &sxdn_ccd_plba_hex,
    &sxdn_ccd_mode,
    &sxdn_ccd_mode_hex,
    &sxdn_ccd_index1,
    &sxdn_ccd_index1_hex,
    &sxdn_ldbst_cylinder,
    &sxdn_ldbst_cylinder_hex,
    &sxdn_ldbst_head,
    &sxdn_ldbst_head_hex,
    &sxdn_ldbst_data_rate,
    &sxdn_ldbst_data_rate_hex,
    &sxdn_ldbst_gap3,
    &sxdn_ldbst_gap3_hex,
    &sxdn_ldbst_filler,
    &sxdn_ldbst_filler_hex,
    &sxdn_ldbst_total_length,
    &sxdn_ldbst_total_length_hex,
    &sxdn_ldbst_cylinders,
    &sxdn_ldbst_cylinders_hex,
    &sxdn_ldbst_heads,
    &sxdn_ldbst_heads_hex,
    &sxdn_ldbst_sectors,
    &sxdn_ldbst_sectors_hex,
    &sxdn_ldbst_sector_base,
    &sxdn_ldbst_sector_base_hex,
    &sxdn_ldbst_sector_size,
    &sxdn_ldbst_sector_size_hex,
    &sxdn_ldbst_id_cylinder,
    &sxdn_ldbst_id_cylinder_hex,
    &sxdn_ldbst_id_head,
    &sxdn_ldbst_id_head_hex,
    &sxdn_ldbst_id_sector,
    &sxdn_ldbst_id_sector_hex,
    &sxdn_ldbst_sector_size_code,
    &sxdn_ldbst_sector_size_code_hex,
    &sxdn_ldbst_status1,
    &sxdn_ldbst_status1_hex,
    &sxdn_ldbst_status2,
    &sxdn_ldbst_status2_hex,
    &sxdn_ldbst_copies,
    &sxdn_ldbst_copies_hex,
    &sxdn_ldbst_data_length,
    &sxdn_ldbst_data_length_hex,
    &sxdn_ldbst_trail_bytes_hex,
    &sxdn_ldbst_track_relative_offset,
    &sxdn_ldbst_track_relative_offset_hex,
    &sxdn_ldbst_version,
    &sxdn_ldbst_sidedness,
    &sxdn_ldbst_complement,
    &sxdn_ldbst_recording_mode,
};
typedef struct sxdn_flag {uint64_t mask;const wchar_t*name;} sxdn_flag;
static bool sxdn_flags(xx_data_struct_record*r,uint64_t value,const sxdn_flag*bits,size_t n){
 wchar_t out[1024];size_t used=0;uint64_t known=0;
 for(size_t i=0;i<n;i++){known|=bits[i].mask;if(!(value&bits[i].mask))continue;const wchar_t*p=bits[i].name;size_t z=xx_rt_wcslen(p);if(z+used+24>=SX_COUNT(out))return false;if(used)out[used++]=L'|';while(*p)out[used++]=*p++;}
 uint64_t unknown=value&~known;if(unknown){if(used)out[used++]=L'|';out[used++]=L'0';out[used++]=L'x';bool start=false;for(int shift=60;shift>=0;shift-=4){unsigned d=(unsigned)((unknown>>shift)&15);if(d||start||!shift){out[used++]=L"0123456789ABCDEF"[d];start=true;}}}
 if(!used)out[used++]=L'0';out[used]=0;return xx_data_struct_record_set_comment(r,out);
}
static bool sx_disknext_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60780000U||id>=0x60790000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    if(id==0x60780076U&&!xx_rt_wcscmp(r->name,L"extended_flags")&&integer){static const sxdn_flag bits[]={{128U,L"FAT_MIRRORING_DISABLED"}};return sxdn_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x6078000fU&&!xx_rt_wcscmp(r->name,L"ascii_flag")&&integer){static const sxdn_flag bits[]={{255U,L"ASCII"}};return sxdn_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60780011U&&!xx_rt_wcscmp(r->name,L"flags")&&integer){static const sxdn_flag bits[]={{1U,L"CONTINUATION"},{2U,L"PROTECTED"},{8U,L"END_OF_DIRECTORY"},{32U,L"HAS_NEXT_ENTRY"},{128U,L"DELETED"}};return sxdn_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60780003U&&!xx_rt_wcscmp(r->name,L"block_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"FILENAME");
    case 1U:return xx_data_struct_record_set_comment(r,L"DATA");
    case 255U:return xx_data_struct_record_set_comment(r,L"END");
    default:break;}}
    if(id==0x60780004U&&!xx_rt_wcscmp(r->name,L"file_type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"BASIC");
    case 1U:return xx_data_struct_record_set_comment(r,L"DATA");
    case 2U:return xx_data_struct_record_set_comment(r,L"MACHINE_CODE");
    default:break;}}
    if(id==0x60780016U&&!xx_rt_wcscmp(r->name,L"compression")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"STORED");
    case 1U:return xx_data_struct_record_set_comment(r,L"RDC");
    default:break;}}
    if(id==0x60780027U&&!xx_rt_wcscmp(r->name,L"block_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"STREAM_INFO");
    case 2U:return xx_data_struct_record_set_comment(r,L"INDEX");
    case 3U:return xx_data_struct_record_set_comment(r,L"STREAM_END");
    case 4U:return xx_data_struct_record_set_comment(r,L"DEVICE_INFO");
    default:break;}}
    if(id==0x60780044U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"NON_TRACK");
    case 1U:return xx_data_struct_record_set_comment(r,L"AUDIO");
    case 2U:return xx_data_struct_record_set_comment(r,L"MODE1");
    case 3U:return xx_data_struct_record_set_comment(r,L"MODE2");
    case 4U:return xx_data_struct_record_set_comment(r,L"MODE2_FORM1");
    case 5U:return xx_data_struct_record_set_comment(r,L"MODE2_FORM2");
    case 6U:return xx_data_struct_record_set_comment(r,L"DVD");
    default:break;}}
    switch(id){
    case 0x60780001U:
        if(!xx_rt_wcscmp(r->name,L"producer_ebcdic"))s=L"EBCDIC EMT producer identifier; physical bytes preserved";
        else if(!xx_rt_wcscmp(r->name,L"version_digits_ebcdic"))s=L"Stored EBCDIC version digits";
        else if(!xx_rt_wcscmp(r->name,L"text_ebcdic"))s=L"Producer text/padding; EBCDIC bytes preserved";
        else if(!xx_rt_wcscmp(r->name,L"product_banner_ebcdic"))s=L"EBCDIC product/version banner";
        break;
    case 0x60780002U:
        if(!xx_rt_wcscmp(r->name,L"execution_address"))s=L"Zero means no supplied execution entry";
        break;
    case 0x60780003U:
        if(!xx_rt_wcscmp(r->name,L"block_type"))s=L"0=filename,1=data,255=end";
        break;
    case 0x60780004U:
        if(!xx_rt_wcscmp(r->name,L"file_type"))s=L"0=BASIC,1=data,2=machine code";
        break;
    case 0x60780005U:
        if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"Low8bits of type+length+payload sum";
        break;
    case 0x60780006U:
        if(!xx_rt_wcscmp(r->name,L"file_type"))s=L"B=BASIC,C=code,D=array";
        else if(!xx_rt_wcscmp(r->name,L"start_or_parameter"))s=L"C:load address; B/D:format-specific parameter";
        else if(!xx_rt_wcscmp(r->name,L"stored_sector_count"))s=L"Number of256-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"header_checksum"))s=L"105+257*sum(first15bytes), reduced to16bits";
        break;
    case 0x60780007U:
        if(!xx_rt_wcscmp(r->name,L"stored_sector_count"))s=L"Number of256-byte sectors";
        break;
    case 0x6078000aU:
        if(!xx_rt_wcscmp(r->name,L"sector_size_code"))s=L"Stored code:128<<code bytes";
        break;
    case 0x6078000bU:
        if(!xx_rt_wcscmp(r->name,L"sector_size_code"))s=L"Stored code:128<<code bytes";
        break;
    case 0x6078000cU:
        if(!xx_rt_wcscmp(r->name,L"sector_size_code"))s=L"Stored code:128<<code bytes";
        break;
    case 0x6078000dU:
        if(!xx_rt_wcscmp(r->name,L"compression_and_name_length"))s=L"Low3bits=compression; remaining bits are producer-defined";
        break;
    case 0x6078000eU:
        if(!xx_rt_wcscmp(r->name,L"next_or_terminal"))s=L"255=free;192..201=terminal sectors used; otherwise next granule index";
        break;
    case 0x6078000fU:
        if(!xx_rt_wcscmp(r->name,L"last_sector_bytes"))s=L"Zero denotes a full256-byte last sector";
        break;
    case 0x60780011U:
        if(!xx_rt_wcscmp(r->name,L"extent_1_sector"))s=L"256-byte logical sector number";
        else if(!xx_rt_wcscmp(r->name,L"extent_2_sector"))s=L"256-byte logical sector number";
        else if(!xx_rt_wcscmp(r->name,L"extent_3_sector"))s=L"256-byte logical sector number";
        else if(!xx_rt_wcscmp(r->name,L"extent_4_sector"))s=L"256-byte logical sector number";
        else if(!xx_rt_wcscmp(r->name,L"next_or_last_bytes"))s=L"Continued flag:next directory index; otherwise last-sector bytes with0=256";
        break;
    case 0x60780012U:
        if(!xx_rt_wcscmp(r->name,L"extent_1_sector"))s=L"256-byte logical sector number";
        else if(!xx_rt_wcscmp(r->name,L"extent_2_sector"))s=L"256-byte logical sector number";
        else if(!xx_rt_wcscmp(r->name,L"extent_3_sector"))s=L"256-byte logical sector number";
        else if(!xx_rt_wcscmp(r->name,L"extent_4_sector"))s=L"256-byte logical sector number";
        else if(!xx_rt_wcscmp(r->name,L"extent_5_sector"))s=L"256-byte logical sector number";
        else if(!xx_rt_wcscmp(r->name,L"extent_6_sector"))s=L"256-byte logical sector number";
        else if(!xx_rt_wcscmp(r->name,L"extent_7_sector"))s=L"256-byte logical sector number";
        break;
    case 0x60780013U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"0x0800=uncompressed remainder";
        break;
    case 0x60780014U:
        if(!xx_rt_wcscmp(r->name,L"total_block_size"))s=L"Includes this2-byte length word";
        else if(!xx_rt_wcscmp(r->name,L"index_size"))s=L"From this index-size word, including its2bytes";
        break;
    case 0x60780015U:
        if(!xx_rt_wcscmp(r->name,L"last_literal_offset"))s=L"Relative to block after total-length word; inclusive literal end";
        else if(!xx_rt_wcscmp(r->name,L"repeat_count"))s=L"Additional copies of preceding byte";
        break;
    case 0x60780016U:
        if(!xx_rt_wcscmp(r->name,L"format_value"))s=L"Native accepts4..32; exact unit unestablished";
        else if(!xx_rt_wcscmp(r->name,L"compression"))s=L"0=stored,1=RDC block stream";
        break;
    case 0x60780017U:
        if(!xx_rt_wcscmp(r->name,L"size_or_stored_length"))s=L"Negative=stored bytes after negation; positive=compressed bytes; zero=end";
        break;
    case 0x60780019U:
        if(!xx_rt_wcscmp(r->name,L"count_and_repeat"))s=L"Low15bits=byte count; highbit=set for repeated byte, clear for literal run";
        break;
    case 0x6078001cU:
        if(!xx_rt_wcscmp(r->name,L"track_headers_size"))s=L"387-byte track descriptors plus1byte checksum";
        break;
    case 0x6078001eU:
        if(!xx_rt_wcscmp(r->name,L"status"))s=L"Native supports healthy zero status only";
        else if(!xx_rt_wcscmp(r->name,L"sector_size_code"))s=L"128<<code bytes";
        else if(!xx_rt_wcscmp(r->name,L"biased_payload_offset"))s=L"Stored offset includes0x16ad bias; relative to following segment data after subtractingbias";
        break;
    case 0x6078001fU:
        if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"Sum of387-byte descriptors modulo256";
        break;
    case 0x60780022U:
        if(!xx_rt_wcscmp(r->name,L"type_count_continue"))s=L"Low2bits=sector type; bits2..6=low5count-minus-one bits; bit7=continuation";
        break;
    case 0x60780023U:
        if(!xx_rt_wcscmp(r->name,L"count_continue"))s=L"Low7bits extend count; highbit=continuation";
        break;
    case 0x60780024U:
        if(!xx_rt_wcscmp(r->name,L"reconstructed_edc"))s=L"ECMA-130 EDC over reconstructed complete output";
        break;
    case 0x60780027U:
        if(!xx_rt_wcscmp(r->name,L"payload_size"))s=L"EOF type13 uses0x0d0d sentinel with no payload";
        break;
    case 0x60780028U:
        if(!xx_rt_wcscmp(r->name,L"eof_sentinel"))s=L"0x0d0d; no payload";
        break;
    case 0x60780029U:
        if(!xx_rt_wcscmp(r->name,L"stream_position"))s=L"In-stream bytes only; excludes OOB blocks, not a physical file offset";
        else if(!xx_rt_wcscmp(r->name,L"transfer_time"))s=L"USB transfer timing counter in device ticks";
        break;
    case 0x6078002aU:
        if(!xx_rt_wcscmp(r->name,L"stream_position"))s=L"In-stream bytes only; excludes OOB blocks";
        break;
    case 0x6078002bU:
        if(!xx_rt_wcscmp(r->name,L"stream_position"))s=L"Position in flux-byte stream with OOB bytes excluded";
        else if(!xx_rt_wcscmp(r->name,L"timer"))s=L"Index timer counter; device clock units";
        else if(!xx_rt_wcscmp(r->name,L"system_clock"))s=L"Device system-clock counter; not a byte address";
        break;
    case 0x6078002cU:
        if(!xx_rt_wcscmp(r->name,L"user_or_status"))s=L"CP/M user0..15;0xe5=deleted";
        else if(!xx_rt_wcscmp(r->name,L"filename_and_flags"))s=L"High bits retained; remaining7bits are filename characters";
        else if(!xx_rt_wcscmp(r->name,L"extension_and_flags"))s=L"Extension high bits hold read-only/system/archive flags";
        else if(!xx_rt_wcscmp(r->name,L"record_count"))s=L"128-byte records in this extent";
        else if(!xx_rt_wcscmp(r->name,L"allocation_blocks"))s=L"Fixed SIMH CP/M allocation uses16-bit block indices";
        break;
    case 0x6078002dU:
        if(!xx_rt_wcscmp(r->name,L"value"))s=L"Producer version token";
        break;
    case 0x6078002eU:
        if(!xx_rt_wcscmp(r->name,L"value"))s=L"Stored256-byte blocks per track";
        break;
    case 0x60780031U:
        if(!xx_rt_wcscmp(r->name,L"value"))s=L"Encoded sector-size selector; stored blocks are always256bytes";
        break;
    case 0x60780033U:
        if(!xx_rt_wcscmp(r->name,L"value"))s=L"Physical grammar token";
        break;
    case 0x60780034U:
        if(!xx_rt_wcscmp(r->name,L"value"))s=L"Original quoted/raw text, not decoded data";
        break;
    case 0x60780035U:
        if(!xx_rt_wcscmp(r->name,L"value"))s=L"Original device name/value text";
        break;
    case 0x60780036U:
        if(!xx_rt_wcscmp(r->name,L"timestamp_encoded"))s=L"Producer timestamp; epoch and encoding not established";
        break;
    case 0x6078003aU:
        if(!xx_rt_wcscmp(r->name,L"external_file_offset"))s=L"Byte offset into external data file";
        else if(!xx_rt_wcscmp(r->name,L"sector_adjustment"))s=L"Sector-unit bias used to resolve external file position";
        else if(!xx_rt_wcscmp(r->name,L"end_sector"))s=L"Exclusive logical sector end";
        break;
    case 0x6078003cU:
        if(!xx_rt_wcscmp(r->name,L"disc_type"))s=L"MMC profile code";
        break;
    case 0x60780040U:
        if(!xx_rt_wcscmp(r->name,L"drive_path_size"))s=L"Bytes of following UTF16 path";
        break;
    case 0x60780041U:
        if(!xx_rt_wcscmp(r->name,L"type"))s=L"0x8000=audio";
        else if(!xx_rt_wcscmp(r->name,L"external_file_offset"))s=L"Byte offset into named external data file";
        else if(!xx_rt_wcscmp(r->name,L"filename_size"))s=L"Bytes of following UTF16LE filename";
        break;
    case 0x60780044U:
        if(!xx_rt_wcscmp(r->name,L"type"))s=L"0=non-track,1=audio,2=mode1,3=mode2,4=form1,5=form2,6=DVD";
        break;
    case 0x60780047U:
        if(!xx_rt_wcscmp(r->name,L"variant"))s=L"Native accepts values0..3; producer meaning unestablished";
        else if(!xx_rt_wcscmp(r->name,L"sector_count"))s=L"512-byte sectors in the following FAT image";
        break;
    case 0x60780054U:
        if(!xx_rt_wcscmp(r->name,L"block_log"))s=L"Base 2 block-size exponent, not a byte count.";
        else if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))s=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case 0x60780055U:
        if(!xx_rt_wcscmp(r->name,L"block_log"))s=L"Base 2 block-size exponent, not a byte count.";
        else if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))s=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case 0x60780056U:
        if(!xx_rt_wcscmp(r->name,L"block_log"))s=L"Base 2 block-size exponent, not a byte count.";
        else if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))s=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case 0x60780057U:
        if(!xx_rt_wcscmp(r->name,L"block_log"))s=L"Base 2 block-size exponent, not a byte count.";
        else if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))s=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case 0x60780058U:
        if(!xx_rt_wcscmp(r->name,L"size_and_stored_flag"))s=L"Low 15 bits: encoded payload byte length; bit 15: uncompressed payload. Not a plain size field.";
        break;
    case 0x60780059U:
        if(!xx_rt_wcscmp(r->name,L"metadata_offset"))s=L"Absolute byte offset of a metadata block from the filesystem image start.";
        break;
    case 0x6078005cU:
        if(!xx_rt_wcscmp(r->name,L"size_and_stored_flag"))s=L"Low 15 bits: encoded payload byte length; bit 15: uncompressed payload. Not a plain size field.";
        break;
    case 0x6078005dU:
        if(!xx_rt_wcscmp(r->name,L"metadata_offset"))s=L"Absolute byte offset of a metadata block from the filesystem image start.";
        break;
    case 0x60780060U:
        if(!xx_rt_wcscmp(r->name,L"root_fd_sector"))s=L"256-byte logical sector number";
        else if(!xx_rt_wcscmp(r->name,L"creation_ymdhm"))s=L"Calendar bytes, year relative1900";
        else if(!xx_rt_wcscmp(r->name,L"volume_name"))s=L"Last character has bit7 set";
        break;
    case 0x60780061U:
        if(!xx_rt_wcscmp(r->name,L"segment_allocation_size"))s=L"Sector allocation increment";
        else if(!xx_rt_wcscmp(r->name,L"record_extension"))s=L"Path extension for record locking";
        else if(!xx_rt_wcscmp(r->name,L"directory_entry_offset"))s=L"Byte position relative to the current directory, not a memory pointer";
        break;
    case 0x60780062U:
        if(!xx_rt_wcscmp(r->name,L"modification_ymdhm"))s=L"Calendar bytes, year relative1900";
        else if(!xx_rt_wcscmp(r->name,L"creation_ymd"))s=L"Calendar bytes, year relative1900";
        break;
    case 0x60780063U:
        if(!xx_rt_wcscmp(r->name,L"first_sector"))s=L"256-byte logical sector number";
        break;
    case 0x60780064U:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Last character has bit7 set";
        else if(!xx_rt_wcscmp(r->name,L"file_descriptor_sector"))s=L"256-byte logical sector number";
        break;
    case 0x60780067U:
        if(!xx_rt_wcscmp(r->name,L"lba"))s=L"Logical sectors, not a physical byte offset";
        break;
    case 0x6078006aU:
        if(!xx_rt_wcscmp(r->name,L"filename"))s=L"Physical quoted/unquoted filename";
        break;
    case 0x6078006bU:
        if(!xx_rt_wcscmp(r->name,L"file_offset"))s=L"Byte offset in external track file";
        break;
    case 0x6078006eU:
        if(!xx_rt_wcscmp(r->name,L"msf_position"))s=L"Minute:second:frame;75frames per second";
        break;
    case 0x6078006fU:
        if(!xx_rt_wcscmp(r->name,L"filename"))s=L"External file; original quoting preserved";
        break;
    case 0x60780072U:
        if(!xx_rt_wcscmp(r->name,L"trail_bytes"))s=L"Decoded trailing bytes";
        break;
    case 0x60780073U:
        if(!xx_rt_wcscmp(r->name,L"start_position"))s=L"Minute:second:frame in external file; optional leading# denotes sample-unit count";
        break;
    case 0x60780074U:
        if(!xx_rt_wcscmp(r->name,L"length"))s=L"Stored MSF or sample-unit length";
        break;
    case 0x60780075U:
        if(!xx_rt_wcscmp(r->name,L"filename"))s=L"External file; original quoting preserved";
        break;
    case 0x60780078U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x6078007aU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x6078007cU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x6078007eU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x60780080U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x60780081U:
        if(!xx_rt_wcscmp(r->name,L"pregap_mode"))s=L"Track mode for pregap";
        break;
    case 0x60780082U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        else if(!xx_rt_wcscmp(r->name,L"pregap_mode"))s=L"Track mode for pregap";
        break;
    case 0x60780083U:
        if(!xx_rt_wcscmp(r->name,L"pregap_subchannel"))s=L"Pregap subchannel encoding selector";
        break;
    case 0x60780084U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        else if(!xx_rt_wcscmp(r->name,L"pregap_subchannel"))s=L"Pregap subchannel encoding selector";
        break;
    case 0x60780086U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x60780088U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x6078008aU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x6078008cU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x6078008eU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x60780090U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x60780092U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x60780094U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x60780095U:
        if(!xx_rt_wcscmp(r->name,L"absolute_lba"))s=L"Sector unit, not a byte offset";
        break;
    case 0x60780096U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        else if(!xx_rt_wcscmp(r->name,L"absolute_lba"))s=L"Sector unit, not a byte offset";
        break;
    case 0x60780098U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x6078009aU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x6078009cU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x6078009eU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x6078009fU:
        if(!xx_rt_wcscmp(r->name,L"plba"))s=L"Sector unit, not a byte offset";
        break;
    case 0x607800a0U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        else if(!xx_rt_wcscmp(r->name,L"plba"))s=L"Sector unit, not a byte offset";
        break;
    case 0x607800a2U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x607800a3U:
        if(!xx_rt_wcscmp(r->name,L"index1"))s=L"Sector position";
        break;
    case 0x607800a4U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        else if(!xx_rt_wcscmp(r->name,L"index1"))s=L"Sector position";
        break;
    case 0x607800a6U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x607800a8U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x607800a9U:
        if(!xx_rt_wcscmp(r->name,L"data_rate"))s=L"Producer data-rate selector";
        break;
    case 0x607800aaU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        else if(!xx_rt_wcscmp(r->name,L"data_rate"))s=L"Producer data-rate selector";
        break;
    case 0x607800abU:
        if(!xx_rt_wcscmp(r->name,L"gap3"))s=L"Controller gap bytes";
        break;
    case 0x607800acU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        else if(!xx_rt_wcscmp(r->name,L"gap3"))s=L"Controller gap bytes";
        break;
    case 0x607800adU:
        if(!xx_rt_wcscmp(r->name,L"filler"))s=L"Stored byte value";
        break;
    case 0x607800aeU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        else if(!xx_rt_wcscmp(r->name,L"filler"))s=L"Stored byte value";
        break;
    case 0x607800afU:
        if(!xx_rt_wcscmp(r->name,L"total_length"))s=L"Reconstructed track byte count";
        break;
    case 0x607800b0U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        else if(!xx_rt_wcscmp(r->name,L"total_length"))s=L"Reconstructed track byte count";
        break;
    case 0x607800b2U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x607800b4U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x607800b6U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x607800b8U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x607800baU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x607800bcU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x607800beU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x607800c0U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x607800c1U:
        if(!xx_rt_wcscmp(r->name,L"sector_size_code"))s=L"128<<code bytes";
        break;
    case 0x607800c2U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        else if(!xx_rt_wcscmp(r->name,L"sector_size_code"))s=L"128<<code bytes";
        break;
    case 0x607800c4U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x607800c6U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x607800c8U:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        break;
    case 0x607800c9U:
        if(!xx_rt_wcscmp(r->name,L"data_length"))s=L"Decoded sector bytes";
        break;
    case 0x607800caU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        else if(!xx_rt_wcscmp(r->name,L"data_length"))s=L"Decoded sector bytes";
        break;
    case 0x607800cbU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        else if(!xx_rt_wcscmp(r->name,L"trail_bytes"))s=L"Decoded trailing bytes";
        break;
    case 0x607800ccU:
        if(!xx_rt_wcscmp(r->name,L"track_relative_offset"))s=L"Byte position within reconstructed track, not source-file position";
        break;
    case 0x607800cdU:
        if(!xx_rt_wcscmp(r->name,L"radix_prefix"))s=L"Stored0xprefix";
        else if(!xx_rt_wcscmp(r->name,L"track_relative_offset"))s=L"Byte position within reconstructed track, not source-file position";
        break;
    case 0x607800ceU:
        if(!xx_rt_wcscmp(r->name,L"version"))s=L"LDBST revision as stored; no numeric rescaling";
        break;
    case 0x607800cfU:
        if(!xx_rt_wcscmp(r->name,L"sidedness"))s=L"Alt means alternating sides";
        break;
    case 0x607800d0U:
        if(!xx_rt_wcscmp(r->name,L"complement"))s=L"N means bytes are not complemented";
        break;
    case 0x607800d1U:
        if(!xx_rt_wcscmp(r->name,L"recording_mode"))s=L"FM, MFM or Unknown recording mode";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Every coordinate is relative to the borrowed image base.  No native
 * subclass state, host mounts, or journal replay is required.  Display caps
 * retain validated earlier records; undecoded metadata and payload stay raw. */
#define SXDN_LIMIT 24000U
bool sxdn_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxdn_read(sx_context*c,uint64_t p,void*b,size_t n){return !xx_pd_is_stopped(c->pd)&&sxdn_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint16_t sxdn16(const uint8_t*b,unsigned o){return o==1?(uint16_t)((uint16_t)b[0]<<8|b[1]):(uint16_t)((uint16_t)b[1]<<8|b[0]);}
uint32_t sxdn32(const uint8_t*b,unsigned o){if(o==2)return (uint32_t)sxdn16(b,0)<<16|sxdn16(b+2,0);return o==1?(uint32_t)sxdn16(b,1)<<16|sxdn16(b+2,1):(uint32_t)sxdn16(b+2,0)<<16|sxdn16(b,0);}
bool sxdn_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 if(!n)return true;const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(!z||n>1048576U||n>UINT64_MAX/z||!sxdn_span(c,p,n*z)||xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXDN_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&(uint64_t)(c->items[lo-1].offset-c->f->base_address)+(uint64_t)c->items[lo-1].total_size>p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}return true;
}
#define SXDN_ADD(c,l,p) sxdn_put(c,&sxdn_##l,p,1)
bool sxdn_value(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){if(!n)return true;if(!sxdn_span(c,p,n)||xx_pd_is_stopped(c->pd))return false;const xx_data_struct_field_desc*last=l->fields+l->field_count-1;uint64_t limit=sx_variable_field_limit(last->type);if(n<=(uint64_t)last->rel_offset||n-(uint64_t)last->rel_offset>limit||n>16384||c->count>=SXDN_LIMIT)return true;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<c->f->base_address+(int64_t)p)lo=m+1;else hi=m;}if(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>c->f->base_address+(int64_t)p)return true;if(lo<c->count&&c->items[lo].offset<c->f->base_address+(int64_t)(p+n))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
bool sxdn_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxdn_read(c,p,b,n))return false;*v=0;for(unsigned i=0;i<n;i++)*v|=(uint64_t)b[i]<<(8*(be?n-i-1:i));return true;}
bool sxdn_jvc_header(sx_context*c,uint64_t h){static const sx_layout*const a[]={&sxdn_jvc_header_1,&sxdn_jvc_header_2,&sxdn_jvc_header_3,&sxdn_jvc_header_4,&sxdn_jvc_header_5};return !h||sxdn_put(c,a[h>5?4:h-1],0,1);}
static bool sxdn_blank(uint8_t b){return b==' '||b=='\t'||b=='\r';}
static bool sxdn_eq(const uint8_t*b,size_t n,const char*s){size_t k=xx_rt_strlen(s);if(n!=k)return false;for(size_t i=0;i<n;i++){uint8_t a=b[i],c=(uint8_t)s[i];if(a>='a'&&a<='z')a-=32;if(c>='a'&&c<='z')c-=32;if(a!=c)return false;}return true;}
bool sxdn_text_value(sxdn_text*t,const sx_layout*l,size_t a,size_t z){while(a<z&&sxdn_blank(t->b[a]))a++;while(z>a&&sxdn_blank(t->b[z-1]))z--;const xx_data_struct_field_desc*last=l->fields+l->field_count-1;
 if(!xx_rt_wcscmp(last->type,L"ascii_signed")||!xx_rt_wcscmp(last->type,L"ascii_hex")){
  size_t i=a+(size_t)last->rel_offset;bool hex_=!xx_rt_wcscmp(last->type,L"ascii_hex"),negative=false;uint64_t value=0,limit=UINT64_MAX;
  if(!hex_&&i<z&&(t->b[i]=='-'||t->b[i]=='+')){negative=t->b[i]=='-';i++;}if(!hex_)limit=negative?UINT64_C(0x8000000000000000):INT64_MAX;
  bool valid=i<z;for(;i<z&&valid;i++){unsigned b=t->b[i],digit=b>='0'&&b<='9'?b-'0':hex_&&b>='A'&&b<='F'?b-'A'+10:hex_&&b>='a'&&b<='f'?b-'a'+10:255,base=hex_?16:10;if(digit>=base||value>(limit-digit)/base)valid=false;else value=value*base+digit;}
  if(!valid)l=&sxdn_disk_descriptor_string;
 }
 return sxdn_value(t->c,l,a,z-a);}
static bool sxdn_token(sxdn_text*t,size_t*p,size_t end,size_t*a,size_t*z){while(*p<end&&sxdn_blank(t->b[*p]))(*p)++;if(*p==end)return false;*a=*p;if(t->b[*p]=='"'){(*p)++;while(*p<end&&t->b[*p]!='"')(*p)++;if(*p<end)(*p)++;}else while(*p<end&&!sxdn_blank(t->b[*p]))(*p)++;*z=*p;return true;}
static const sx_layout*sxdn_text_key(unsigned family,const uint8_t*key,size_t keylen,bool hex_);
static bool sxdn_text_ini(sxdn_text*t,unsigned family){bool payload=false;for(size_t p=0;p<t->n&&t->c->count<SXDN_LIMIT;){size_t end=p;while(end<t->n&&t->b[end]!='\n')end++;size_t a=p;p=end<t->n?end+1:end;while(a<end&&sxdn_blank(t->b[a]))a++;while(end>a&&sxdn_blank(t->b[end-1]))end--;if(a==end||t->b[a]=='#'||t->b[a]==';')continue;if(payload){for(size_t i=a;i<end;i++)if(t->b[i]=='}'){payload=false;break;}continue;}if(t->b[a]=='['){if(!sxdn_text_value(t,&sxdn_disk_descriptor_keyword,a,end))return false;continue;}size_t keyend=a;while(keyend<end&&t->b[keyend]!='=')keyend++;if(keyend==end)continue;size_t trim=keyend;while(trim>a&&sxdn_blank(t->b[trim-1]))trim--;if(!sxdn_text_value(t,&sxdn_disk_descriptor_keyword,a,trim))return false;size_t v=keyend+1;while(v<end&&sxdn_blank(t->b[v]))v++;if(family==1&&v<end&&t->b[v]=='{'){payload=true;for(size_t i=v;i<end;i++)if(t->b[i]=='}')payload=false;continue;}size_t z=v;while(z<end&&t->b[z]!=';'&&t->b[z]!='#')z++;while(z>v&&sxdn_blank(t->b[z-1]))z--;bool hex_=z-v>=2&&t->b[v]=='0'&&(t->b[v+1]=='x'||t->b[v+1]=='X');const sx_layout*l=sxdn_text_key(family,t->b+a,trim-a,hex_);if(!l)l=&sxdn_disk_descriptor_string;if(!sxdn_text_value(t,l,v,z))return false;}return true;}
static bool sxdn_text_sheet(sxdn_text*t,unsigned kind){unsigned row=0;for(size_t p=0;p<t->n&&t->c->count<SXDN_LIMIT;){size_t end=p;while(end<t->n&&t->b[end]!='\n')end++;size_t q=p;p=end<t->n?end+1:end;while(q<end&&sxdn_blank(t->b[q]))q++;if(q==end||t->b[q]==';'||(q+1<end&&t->b[q]=='/'&&t->b[q+1]=='/'))continue;size_t a,z;if(!sxdn_token(t,&q,end,&a,&z))continue;if(kind==2){if(!row){if(!sxdn_text_value(t,&sxdn_gdi_track_count,a,z))return false;row++;continue;}static const sx_layout*const fields[]={&sxdn_gdi_track_number,&sxdn_gdi_lba,&sxdn_gdi_control,&sxdn_gdi_sector_size,&sxdn_gdi_filename,&sxdn_gdi_file_offset};for(unsigned i=0;i<6;i++){if(i&&!sxdn_token(t,&q,end,&a,&z))break;if(!sxdn_text_value(t,fields[i],a,z))return false;}row++;continue;}size_t key=a,keylen=z-a;if(!sxdn_text_value(t,&sxdn_disk_descriptor_keyword,a,z))return false;if(kind==0&&sxdn_eq(t->b+key,keylen,"REM")){if(!sxdn_text_value(t,&sxdn_disk_descriptor_string,q,end))return false;continue;}unsigned arg=0;while(sxdn_token(t,&q,end,&a,&z)){const sx_layout*l=&sxdn_disk_descriptor_string;if(kind==0){if(sxdn_eq(t->b+key,keylen,"FILE"))l=arg?&sxdn_cue_file_type:&sxdn_cue_file;else if(sxdn_eq(t->b+key,keylen,"TRACK"))l=arg?&sxdn_cue_mode:&sxdn_cue_track_number;else if(sxdn_eq(t->b+key,keylen,"INDEX"))l=arg?&sxdn_cue_position:&sxdn_cue_index_number;else if(sxdn_eq(t->b+key,keylen,"PREGAP")||sxdn_eq(t->b+key,keylen,"POSTGAP"))l=&sxdn_cue_position;}else{if(sxdn_eq(t->b+key,keylen,"TRACK"))l=&sxdn_cue_mode;else if(sxdn_eq(t->b+key,keylen,"DATAFILE")||sxdn_eq(t->b+key,keylen,"AUDIOFILE"))l=!arg?&sxdn_toc_filename:arg==1&&sxdn_eq(t->b+key,keylen,"AUDIOFILE")?&sxdn_toc_start:&sxdn_toc_length;}if(!sxdn_text_value(t,l,a,z))return false;arg++;}row++;}return true;}
bool sxdn_text_load(sx_context*c,unsigned kind){if(c->size<=0||c->size>8*1024*1024)return false;uint8_t*b=xx_mem_alloc((size_t)c->size);if(!b)return false;bool ok=sxdn_read(c,0,b,(size_t)c->size);sxdn_text t={c,b,(size_t)c->size};if(ok)ok=kind<3?sxdn_text_sheet(&t,kind):sxdn_text_ini(&t,kind==3?0:1);xx_mem_free(b);return ok&&c->count!=0;}
static int sxdn_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxdn_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address;if(at<0||c->items[i].total_size<0||at>c->size||c->items[i].total_size>c->size-at)return false;if(at>end&&!sx_raw(c,end,at-end))return false;int64_t next=at+c->items[i].total_size;if(next>end)end=next;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxdn_order);return !xx_pd_is_stopped(c->pd);}
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
static bool sxdn_psa(sx_context*c){int64_t base,size;if(!xx_psa_disk_get_container_span(c->f,&base,&size))return false;Abstractformat view=*c->f;Abstractformat*prior=c->f;int64_t oldsize=c->size;view.base_address=base;c->f=&view;c->size=size;uint8_t b[36];bool ok=SXDN_ADD(c,psa_disk_header,0)&&sxdn_read(c,84,b,36)&&SXDN_ADD(c,psa_fat_bpb,84);if(ok)ok=sxdn_put(c,sxdn16(b+22,0)?&sxdn_psa_fat1216_extension:&sxdn_psa_fat32_extension,120,1);if(ok)ok=sxdn_finish(c);c->f=prior;c->size=oldsize;return ok;}
#endif
static bool sx_disknext_supports(xx_file_type_t t){switch(t){
case XX_FILE_TYPE_EMT:case XX_FILE_TYPE_CUE:case XX_FILE_TYPE_CCD:case XX_FILE_TYPE_CDRDAO_TOC:case XX_FILE_TYPE_GDI:case XX_FILE_TYPE_MSX_CAS:case XX_FILE_TYPE_DRAGON_CAS:case XX_FILE_TYPE_ZX_HOBETA:case XX_FILE_TYPE_BLINDWRITE4:case XX_FILE_TYPE_BLINDWRITE_5_6_IMAGE:case XX_FILE_TYPE_CFD:case XX_FILE_TYPE_DCP_DISK:case XX_FILE_TYPE_ECM:case XX_FILE_TYPE_SVD:case XX_FILE_TYPE_KRYOFLUX_STREAM:case XX_FILE_TYPE_FDCOPY_CFI:case XX_FILE_TYPE_SNATCHIT_CP2:case XX_FILE_TYPE_SIMH_DISK:case XX_FILE_TYPE_LDBST:case XX_FILE_TYPE_RSDOS_FS:case XX_FILE_TYPE_JVC:case XX_FILE_TYPE_JFFS2_OLD:case XX_FILE_TYPE_SQUASHFS_SQLZ:return true;
#if SX_ALIAS_READER_FACTORY
case XX_FILE_TYPE_PSA_DISK:return true;
#endif
default:return false;}}
static bool sx_disknext_build(sx_context*c){if(!c||!c->f||xx_pd_is_stopped(c->pd)||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_EMT:ok=sx_emt_build(c);break;
case XX_FILE_TYPE_CUE:ok=sx_cue_build(c);break;case XX_FILE_TYPE_CDRDAO_TOC:ok=sx_cdrdao_toc_build(c);break;case XX_FILE_TYPE_GDI:ok=sx_gdi_build(c);break;case XX_FILE_TYPE_CCD:ok=sx_ccd_build(c);break;case XX_FILE_TYPE_LDBST:ok=sx_ldbst_build(c);break;
case XX_FILE_TYPE_MSX_CAS:ok=sx_msx_cas_build(c);break;case XX_FILE_TYPE_DRAGON_CAS:ok=sx_dragon_cas_build(c);break;case XX_FILE_TYPE_ZX_HOBETA:ok=sx_zx_hobeta_build(c);break;
case XX_FILE_TYPE_BLINDWRITE4:ok=sx_blindwrite4_build(c);break;case XX_FILE_TYPE_BLINDWRITE_5_6_IMAGE:ok=sx_blindwrite_5_6_image_build(c);break;case XX_FILE_TYPE_CFD:ok=sx_cfd_build(c);break;case XX_FILE_TYPE_DCP_DISK:ok=sx_dcp_disk_build(c);break;case XX_FILE_TYPE_ECM:ok=sx_ecm_build(c);break;case XX_FILE_TYPE_SVD:ok=sx_svd_build(c);break;case XX_FILE_TYPE_KRYOFLUX_STREAM:ok=sx_kryoflux_stream_build(c);break;case XX_FILE_TYPE_FDCOPY_CFI:ok=sx_fdcopy_cfi_build(c);break;case XX_FILE_TYPE_SNATCHIT_CP2:ok=sx_snatchit_cp2_build(c);break;case XX_FILE_TYPE_SIMH_DISK:ok=sx_simh_disk_build(c);break;case XX_FILE_TYPE_RSDOS_FS:ok=sx_rsdos_fs_build(c);break;case XX_FILE_TYPE_JVC:ok=sx_jvc_build(c);break;case XX_FILE_TYPE_JFFS2_OLD:ok=sx_jffs2_old_build(c);break;case XX_FILE_TYPE_SQUASHFS_SQLZ:ok=sx_squashfs_sqlz_build(c);break;
#if SX_ALIAS_READER_FACTORY
case XX_FILE_TYPE_PSA_DISK:return sxdn_psa(c);
#endif
default:return false;}return ok&&c->count&&sxdn_finish(c);}
#undef SXDN_ADD
#undef SXDN_LIMIT
static const sx_layout*sxdn_text_key(unsigned family,const uint8_t*key,size_t keylen,bool hex_){
if(family==0){
if(sxdn_eq(key,keylen,"Version"))return hex_?&sxdn_ccd_version_hex:&sxdn_ccd_version;
if(sxdn_eq(key,keylen,"TocEntries"))return hex_?&sxdn_ccd_toc_entries_hex:&sxdn_ccd_toc_entries;
if(sxdn_eq(key,keylen,"Sessions"))return hex_?&sxdn_ccd_sessions_hex:&sxdn_ccd_sessions;
if(sxdn_eq(key,keylen,"DataTracksScrambled"))return hex_?&sxdn_ccd_data_tracks_scrambled_hex:&sxdn_ccd_data_tracks_scrambled;
if(sxdn_eq(key,keylen,"CDTextLength"))return hex_?&sxdn_ccd_cd_text_length_hex:&sxdn_ccd_cd_text_length;
if(sxdn_eq(key,keylen,"PreGapMode"))return hex_?&sxdn_ccd_pregap_mode_hex:&sxdn_ccd_pregap_mode;
if(sxdn_eq(key,keylen,"PreGapSubC"))return hex_?&sxdn_ccd_pregap_subchannel_hex:&sxdn_ccd_pregap_subchannel;
if(sxdn_eq(key,keylen,"Session"))return hex_?&sxdn_ccd_session_hex:&sxdn_ccd_session;
if(sxdn_eq(key,keylen,"Point"))return hex_?&sxdn_ccd_point_hex:&sxdn_ccd_point;
if(sxdn_eq(key,keylen,"ADR"))return hex_?&sxdn_ccd_adr_hex:&sxdn_ccd_adr;
if(sxdn_eq(key,keylen,"Control"))return hex_?&sxdn_ccd_control_hex:&sxdn_ccd_control;
if(sxdn_eq(key,keylen,"TrackNo"))return hex_?&sxdn_ccd_track_number_hex:&sxdn_ccd_track_number;
if(sxdn_eq(key,keylen,"AMin"))return hex_?&sxdn_ccd_absolute_minute_hex:&sxdn_ccd_absolute_minute;
if(sxdn_eq(key,keylen,"ASec"))return hex_?&sxdn_ccd_absolute_second_hex:&sxdn_ccd_absolute_second;
if(sxdn_eq(key,keylen,"AFrame"))return hex_?&sxdn_ccd_absolute_frame_hex:&sxdn_ccd_absolute_frame;
if(sxdn_eq(key,keylen,"ALBA"))return hex_?&sxdn_ccd_absolute_lba_hex:&sxdn_ccd_absolute_lba;
if(sxdn_eq(key,keylen,"Zero"))return hex_?&sxdn_ccd_zero_hex:&sxdn_ccd_zero;
if(sxdn_eq(key,keylen,"PMin"))return hex_?&sxdn_ccd_pminute_hex:&sxdn_ccd_pminute;
if(sxdn_eq(key,keylen,"PSec"))return hex_?&sxdn_ccd_psecond_hex:&sxdn_ccd_psecond;
if(sxdn_eq(key,keylen,"PFrame"))return hex_?&sxdn_ccd_pframe_hex:&sxdn_ccd_pframe;
if(sxdn_eq(key,keylen,"PLBA"))return hex_?&sxdn_ccd_plba_hex:&sxdn_ccd_plba;
if(sxdn_eq(key,keylen,"MODE"))return hex_?&sxdn_ccd_mode_hex:&sxdn_ccd_mode;
if(sxdn_eq(key,keylen,"INDEX 1"))return hex_?&sxdn_ccd_index1_hex:&sxdn_ccd_index1;
}
else if(family==1){
if(sxdn_eq(key,keylen,"Cylinder"))return hex_?&sxdn_ldbst_cylinder_hex:&sxdn_ldbst_cylinder;
if(sxdn_eq(key,keylen,"Head"))return hex_?&sxdn_ldbst_head_hex:&sxdn_ldbst_head;
if(sxdn_eq(key,keylen,"DataRate"))return hex_?&sxdn_ldbst_data_rate_hex:&sxdn_ldbst_data_rate;
if(sxdn_eq(key,keylen,"GAP3"))return hex_?&sxdn_ldbst_gap3_hex:&sxdn_ldbst_gap3;
if(sxdn_eq(key,keylen,"Filler"))return hex_?&sxdn_ldbst_filler_hex:&sxdn_ldbst_filler;
if(sxdn_eq(key,keylen,"TotalLength"))return hex_?&sxdn_ldbst_total_length_hex:&sxdn_ldbst_total_length;
if(sxdn_eq(key,keylen,"Cylinders"))return hex_?&sxdn_ldbst_cylinders_hex:&sxdn_ldbst_cylinders;
if(sxdn_eq(key,keylen,"Heads"))return hex_?&sxdn_ldbst_heads_hex:&sxdn_ldbst_heads;
if(sxdn_eq(key,keylen,"Sectors"))return hex_?&sxdn_ldbst_sectors_hex:&sxdn_ldbst_sectors;
if(sxdn_eq(key,keylen,"SecBase"))return hex_?&sxdn_ldbst_sector_base_hex:&sxdn_ldbst_sector_base;
if(sxdn_eq(key,keylen,"SecSize"))return hex_?&sxdn_ldbst_sector_size_hex:&sxdn_ldbst_sector_size;
if(sxdn_eq(key,keylen,"ID.Cylinder"))return hex_?&sxdn_ldbst_id_cylinder_hex:&sxdn_ldbst_id_cylinder;
if(sxdn_eq(key,keylen,"ID.Head"))return hex_?&sxdn_ldbst_id_head_hex:&sxdn_ldbst_id_head;
if(sxdn_eq(key,keylen,"ID.Sector"))return hex_?&sxdn_ldbst_id_sector_hex:&sxdn_ldbst_id_sector;
if(sxdn_eq(key,keylen,"ID.PSH"))return hex_?&sxdn_ldbst_sector_size_code_hex:&sxdn_ldbst_sector_size_code;
if(sxdn_eq(key,keylen,"Status1"))return hex_?&sxdn_ldbst_status1_hex:&sxdn_ldbst_status1;
if(sxdn_eq(key,keylen,"Status2"))return hex_?&sxdn_ldbst_status2_hex:&sxdn_ldbst_status2;
if(sxdn_eq(key,keylen,"Copies"))return hex_?&sxdn_ldbst_copies_hex:&sxdn_ldbst_copies;
if(sxdn_eq(key,keylen,"DataLen"))return hex_?&sxdn_ldbst_data_length_hex:&sxdn_ldbst_data_length;
if(sxdn_eq(key,keylen,"TrailBytes"))return hex_?&sxdn_ldbst_trail_bytes_hex:&sxdn_ldbst_trail_bytes;
if(sxdn_eq(key,keylen,"Offset"))return hex_?&sxdn_ldbst_track_relative_offset_hex:&sxdn_ldbst_track_relative_offset;
}
if(family==1){
if(sxdn_eq(key,keylen,"Version"))return &sxdn_ldbst_version;
if(sxdn_eq(key,keylen,"Sides"))return &sxdn_ldbst_sidedness;
if(sxdn_eq(key,keylen,"Sidedness"))return &sxdn_ldbst_sidedness;
if(sxdn_eq(key,keylen,"Complement"))return &sxdn_ldbst_complement;
if(sxdn_eq(key,keylen,"RecMode"))return &sxdn_ldbst_recording_mode;
}
return NULL;}
const sx_family sx_disknext_family={sx_disknext_supports,sx_disknext_build,sx_disknext_layouts,SX_COUNT(sx_disknext_layouts),sx_disknext_comment};
