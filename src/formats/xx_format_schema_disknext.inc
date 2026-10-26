#include "xxfclib/algo/crc/xx_crc.h"
/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical legacy disk image metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_disknext_scope.txt. */

static const xx_data_struct_field_desc sxdn_emt_header_fields[] = {
    SX_FIELD("marker","byte[3]",0,3,SX_SIGNATURE),
    SX_FIELD("producer_ebcdic","byte[4]",3,4,SX_NONE),
    SX_FIELD("version_digits_ebcdic","byte[6]",7,6,SX_NONE),
    SX_FIELD("text_ebcdic","byte[51]",13,51,SX_NONE),
    SX_FIELD("product_banner_ebcdic","byte[16]",64,16,SX_NONE),
    SX_FIELD("unknown","byte[8]",80,8,SX_NONE),
    SX_FIELD("marker_1","uint8",88,1,SX_SIGNATURE),
    SX_FIELD("unknown2","byte[3]",89,3,SX_NONE),
    SX_FIELD("marker_2","uint32",92,4,SX_SIGNATURE),
};
static const sx_layout sxdn_emt_header = {0x60780001U,"emt_header",sxdn_emt_header_fields,SX_COUNT(sxdn_emt_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_msx_cas_binary_header_fields[] = {
    SX_FIELD("marker","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("binary_file_marker","byte[10]",8,10,SX_SIGNATURE),
    SX_FIELD("filename","char[6]",18,6,SX_NONE),
    SX_FIELD("data_marker","byte[8]",24,8,SX_SIGNATURE),
    SX_FIELD("load_address","uint16",32,2,SX_ADDRESS),
    SX_FIELD("inclusive_end_address","uint16",34,2,SX_ADDRESS),
    SX_FIELD("execution_address","uint16",36,2,SX_ADDRESS),
};
static const sx_layout sxdn_msx_cas_binary_header = {0x60780002U,"msx_cas_binary_header",sxdn_msx_cas_binary_header_fields,SX_COUNT(sxdn_msx_cas_binary_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_dragon_cas_block_header_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("block_type","uint8",1,1,SX_ID),
    SX_FIELD("payload_size","uint8",2,1,SX_SIZE),
};
static const sx_layout sxdn_dragon_cas_block_header = {0x60780003U,"dragon_cas_block_header",sxdn_dragon_cas_block_header_fields,SX_COUNT(sxdn_dragon_cas_block_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_dragon_cas_file_header_fields[] = {
    SX_FIELD("filename","char[8]",0,8,SX_NONE),
    SX_FIELD("file_type","uint8",8,1,SX_ID),
    SX_FIELD("ascii_flag","uint8",9,1,SX_FLAGS),
    SX_FIELD("gap_flag","uint8",10,1,SX_FLAGS),
    SX_FIELD("execution_address","uint16",11,2,SX_ADDRESS),
    SX_FIELD("load_address","uint16",13,2,SX_ADDRESS),
};
static const sx_layout sxdn_dragon_cas_file_header = {0x60780004U,"dragon_cas_file_header",sxdn_dragon_cas_file_header_fields,SX_COUNT(sxdn_dragon_cas_file_header_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_dragon_cas_block_checksum_fields[] = {
    SX_FIELD("checksum","uint8",0,1,SX_CHECKSUM),
};
static const sx_layout sxdn_dragon_cas_block_checksum = {0x60780005U,"dragon_cas_block_checksum",sxdn_dragon_cas_block_checksum_fields,SX_COUNT(sxdn_dragon_cas_block_checksum_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_hobeta_header_fields[] = {
    SX_FIELD("filename","char[8]",0,8,SX_NONE),
    SX_FIELD("file_type","char[1]",8,1,SX_ID),
    SX_FIELD("start_or_parameter","uint16",9,2,SX_NONE),
    SX_FIELD("logical_size","uint16",11,2,SX_SIZE),
    SX_FIELD("reserved","uint8",13,1,SX_NONE),
    SX_FIELD("stored_sector_count","uint8",14,1,SX_COUNT_PROP),
    SX_FIELD("header_checksum","uint16",15,2,SX_CHECKSUM),
};
static const sx_layout sxdn_hobeta_header = {0x60780006U,"hobeta_header",sxdn_hobeta_header_fields,SX_COUNT(sxdn_hobeta_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_hobeta_code_header_fields[] = {
    SX_FIELD("filename","char[8]",0,8,SX_NONE),
    SX_FIELD("file_type","char[1]",8,1,SX_ID),
    SX_FIELD("load_address","uint16",9,2,SX_ADDRESS),
    SX_FIELD("logical_size","uint16",11,2,SX_SIZE),
    SX_FIELD("reserved","uint8",13,1,SX_NONE),
    SX_FIELD("stored_sector_count","uint8",14,1,SX_COUNT_PROP),
    SX_FIELD("header_checksum","uint16",15,2,SX_CHECKSUM),
};
static const sx_layout sxdn_hobeta_code_header = {0x60780007U,"hobeta_code_header",sxdn_hobeta_code_header_fields,SX_COUNT(sxdn_hobeta_code_header_fields),SX_LE};

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

static const xx_data_struct_field_desc sxdn_rsdos_vdk_header_fields[] = {
    SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("header_size","uint16",2,2,SX_SIZE),
    SX_FIELD("version","uint8",4,1,SX_ID),
    SX_FIELD("minimum_version","uint8",5,1,SX_ID),
    SX_FIELD("source_id","uint8",6,1,SX_ID),
    SX_FIELD("source_version","uint8",7,1,SX_ID),
    SX_FIELD("cylinders","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("sides","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("flags","uint8",10,1,SX_FLAGS),
    SX_FIELD("compression_and_name_length","uint8",11,1,SX_NONE),
};
static const sx_layout sxdn_rsdos_vdk_header = {0x6078000dU,"rsdos_vdk_header",sxdn_rsdos_vdk_header_fields,SX_COUNT(sxdn_rsdos_vdk_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_rsdos_granule_fields[] = {
    SX_FIELD("next_or_terminal","uint8",0,1,SX_NONE),
};
static const sx_layout sxdn_rsdos_granule = {0x6078000eU,"rsdos_granule",sxdn_rsdos_granule_fields,SX_COUNT(sxdn_rsdos_granule_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_rsdos_directory_entry_fields[] = {
    SX_FIELD("filename","char[8]",0,8,SX_NONE),
    SX_FIELD("extension","char[3]",8,3,SX_NONE),
    SX_FIELD("file_type","uint8",11,1,SX_ID),
    SX_FIELD("ascii_flag","uint8",12,1,SX_FLAGS),
    SX_FIELD("first_granule","uint8",13,1,SX_NONE),
    SX_FIELD("last_sector_bytes","uint16",14,2,SX_SIZE),
    SX_FIELD("reserved","byte[16]",16,16,SX_NONE),
};
static const sx_layout sxdn_rsdos_directory_entry = {0x6078000fU,"rsdos_directory_entry",sxdn_rsdos_directory_entry_fields,SX_COUNT(sxdn_rsdos_directory_entry_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_dragon_dos_geometry_fields[] = {
    SX_FIELD("cylinders","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_cylinder","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("cylinders_complement","uint8",2,1,SX_NONE),
    SX_FIELD("sectors_complement","uint8",3,1,SX_NONE),
};
static const sx_layout sxdn_dragon_dos_geometry = {0x60780010U,"dragon_dos_geometry",sxdn_dragon_dos_geometry_fields,SX_COUNT(sxdn_dragon_dos_geometry_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_dragon_dos_file_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("filename","char[8]",1,8,SX_NONE),
    SX_FIELD("extension","char[3]",9,3,SX_NONE),
    SX_FIELD("extent_1_sector","uint16be",12,2,SX_NONE),
    SX_FIELD("extent_1_sectors","uint8",14,1,SX_COUNT_PROP),
    SX_FIELD("extent_2_sector","uint16be",15,2,SX_NONE),
    SX_FIELD("extent_2_sectors","uint8",17,1,SX_COUNT_PROP),
    SX_FIELD("extent_3_sector","uint16be",18,2,SX_NONE),
    SX_FIELD("extent_3_sectors","uint8",20,1,SX_COUNT_PROP),
    SX_FIELD("extent_4_sector","uint16be",21,2,SX_NONE),
    SX_FIELD("extent_4_sectors","uint8",23,1,SX_COUNT_PROP),
    SX_FIELD("next_or_last_bytes","uint8",24,1,SX_NONE),
};
static const sx_layout sxdn_dragon_dos_file = {0x60780011U,"dragon_dos_file",sxdn_dragon_dos_file_fields,SX_COUNT(sxdn_dragon_dos_file_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_dragon_dos_continuation_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("extent_1_sector","uint16be",1,2,SX_NONE),
    SX_FIELD("extent_1_sectors","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("extent_2_sector","uint16be",4,2,SX_NONE),
    SX_FIELD("extent_2_sectors","uint8",6,1,SX_COUNT_PROP),
    SX_FIELD("extent_3_sector","uint16be",7,2,SX_NONE),
    SX_FIELD("extent_3_sectors","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("extent_4_sector","uint16be",10,2,SX_NONE),
    SX_FIELD("extent_4_sectors","uint8",12,1,SX_COUNT_PROP),
    SX_FIELD("extent_5_sector","uint16be",13,2,SX_NONE),
    SX_FIELD("extent_5_sectors","uint8",15,1,SX_COUNT_PROP),
    SX_FIELD("extent_6_sector","uint16be",16,2,SX_NONE),
    SX_FIELD("extent_6_sectors","uint8",18,1,SX_COUNT_PROP),
    SX_FIELD("extent_7_sector","uint16be",19,2,SX_NONE),
    SX_FIELD("extent_7_sectors","uint8",21,1,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[2]",22,2,SX_NONE),
    SX_FIELD("next_or_last_bytes","uint8",24,1,SX_NONE),
};
static const sx_layout sxdn_dragon_dos_continuation = {0x60780012U,"dragon_dos_continuation",sxdn_dragon_dos_continuation_fields,SX_COUNT(sxdn_dragon_dos_continuation_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_cfd_header_fields[] = {
    SX_FIELD("reserved0","uint32",0,4,SX_NONE),
    SX_FIELD("reserved1","uint16",4,2,SX_NONE),
    SX_FIELD("reserved2","uint8",6,1,SX_NONE),
    SX_FIELD("sector_size","uint16",7,2,SX_SIZE),
    SX_FIELD("unknown0","byte[3]",9,3,SX_NONE),
    SX_FIELD("format_marker","uint8",12,1,SX_ID),
    SX_FIELD("unknown1","byte[2]",13,2,SX_NONE),
    SX_FIELD("total_sectors","uint16",15,2,SX_COUNT_PROP),
    SX_FIELD("unknown2","byte[5]",17,5,SX_NONE),
    SX_FIELD("head_count","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("reserved3","uint16",24,2,SX_NONE),
    SX_FIELD("flags","uint16",26,2,SX_FLAGS),
    SX_FIELD("unknown3","byte[4]",28,4,SX_NONE),
};
static const sx_layout sxdn_cfd_header = {0x60780013U,"cfd_header",sxdn_cfd_header_fields,SX_COUNT(sxdn_cfd_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_cfd_block_fields[] = {
    SX_FIELD("total_block_size","uint16",0,2,SX_SIZE),
    SX_FIELD("index_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxdn_cfd_block = {0x60780014U,"cfd_block",sxdn_cfd_block_fields,SX_COUNT(sxdn_cfd_block_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_cfd_repeat_fields[] = {
    SX_FIELD("last_literal_offset","uint16",0,2,SX_OFFSET),
    SX_FIELD("repeat_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxdn_cfd_repeat = {0x60780015U,"cfd_repeat",sxdn_cfd_repeat_fields,SX_COUNT(sxdn_cfd_repeat_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_dcp_disk_header_fields[] = {
    SX_FIELD("sectors_per_track","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("unknown","byte[82]",6,82,SX_NONE),
    SX_FIELD("format_value","uint8",88,1,SX_NONE),
    SX_FIELD("unknown2","uint8",89,1,SX_NONE),
    SX_FIELD("compression","uint16",90,2,SX_ID),
    SX_FIELD("signature","char[4]",92,4,SX_SIGNATURE),
};
static const sx_layout sxdn_dcp_disk_header = {0x60780016U,"dcp_disk_header",sxdn_dcp_disk_header_fields,SX_COUNT(sxdn_dcp_disk_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_dcp_rdc_block_fields[] = {
    SX_FIELD("size_or_stored_length","int16",0,2,SX_NONE),
};
static const sx_layout sxdn_dcp_rdc_block = {0x60780017U,"dcp_rdc_block",sxdn_dcp_rdc_block_fields,SX_COUNT(sxdn_dcp_rdc_block_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_fdcopy_track_fields[] = {
    SX_FIELD("compressed_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxdn_fdcopy_track = {0x60780018U,"fdcopy_track",sxdn_fdcopy_track_fields,SX_COUNT(sxdn_fdcopy_track_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_fdcopy_token_fields[] = {
    SX_FIELD("count_and_repeat","uint16",0,2,SX_NONE),
};
static const sx_layout sxdn_fdcopy_token = {0x60780019U,"fdcopy_token",sxdn_fdcopy_token_fields,SX_COUNT(sxdn_fdcopy_token_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_fdcopy_repeat_fields[] = {
    SX_FIELD("repeated_byte","uint8",0,1,SX_NONE),
};
static const sx_layout sxdn_fdcopy_repeat = {0x6078001aU,"fdcopy_repeat",sxdn_fdcopy_repeat_fields,SX_COUNT(sxdn_fdcopy_repeat_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_cp2_header_fields[] = {
    SX_FIELD("producer","char[16]",0,16,SX_NONE),
    SX_FIELD("release_label","char[8]",16,8,SX_NONE),
    SX_FIELD("version","char[4]",24,4,SX_ID),
    SX_FIELD("suffix","char[2]",28,2,SX_SIGNATURE),
};
static const sx_layout sxdn_cp2_header = {0x6078001bU,"cp2_header",sxdn_cp2_header_fields,SX_COUNT(sxdn_cp2_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_cp2_segment_header_fields[] = {
    SX_FIELD("track_headers_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxdn_cp2_segment_header = {0x6078001cU,"cp2_segment_header",sxdn_cp2_segment_header_fields,SX_COUNT(sxdn_cp2_segment_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_cp2_track_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_NONE),
    SX_FIELD("head","uint8",1,1,SX_NONE),
    SX_FIELD("sector_count","uint8",2,1,SX_COUNT_PROP),
};
static const sx_layout sxdn_cp2_track = {0x6078001dU,"cp2_track",sxdn_cp2_track_fields,SX_COUNT(sxdn_cp2_track_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_cp2_sector_fields[] = {
    SX_FIELD("status","byte[4]",0,4,SX_NONE),
    SX_FIELD("cylinder","uint8",4,1,SX_NONE),
    SX_FIELD("head","uint8",5,1,SX_NONE),
    SX_FIELD("sector_id","uint8",6,1,SX_ID),
    SX_FIELD("sector_size_code","uint8",7,1,SX_NONE),
    SX_FIELD("biased_payload_offset","uint16",8,2,SX_OFFSET),
    SX_FIELD("unknown","byte[6]",10,6,SX_NONE),
};
static const sx_layout sxdn_cp2_sector = {0x6078001eU,"cp2_sector",sxdn_cp2_sector_fields,SX_COUNT(sxdn_cp2_sector_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_cp2_header_checksum_fields[] = {
    SX_FIELD("checksum","uint8",0,1,SX_CHECKSUM),
};
static const sx_layout sxdn_cp2_header_checksum = {0x6078001fU,"cp2_header_checksum",sxdn_cp2_header_checksum_fields,SX_COUNT(sxdn_cp2_header_checksum_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_cp2_segment_payload_fields[] = {
    SX_FIELD("payload_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxdn_cp2_segment_payload = {0x60780020U,"cp2_segment_payload",sxdn_cp2_segment_payload_fields,SX_COUNT(sxdn_cp2_segment_payload_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_ecm_signature_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxdn_ecm_signature = {0x60780021U,"ecm_signature",sxdn_ecm_signature_fields,SX_COUNT(sxdn_ecm_signature_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_ecm_record_first_fields[] = {
    SX_FIELD("type_count_continue","uint8",0,1,SX_NONE),
};
static const sx_layout sxdn_ecm_record_first = {0x60780022U,"ecm_record_first",sxdn_ecm_record_first_fields,SX_COUNT(sxdn_ecm_record_first_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_ecm_record_continuation_fields[] = {
    SX_FIELD("count_continue","uint8",0,1,SX_NONE),
};
static const sx_layout sxdn_ecm_record_continuation = {0x60780023U,"ecm_record_continuation",sxdn_ecm_record_continuation_fields,SX_COUNT(sxdn_ecm_record_continuation_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_ecm_edc_fields[] = {
    SX_FIELD("reconstructed_edc","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sxdn_ecm_edc = {0x60780024U,"ecm_edc",sxdn_ecm_edc_fields,SX_COUNT(sxdn_ecm_edc_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_ecm_mode1_address_fields[] = {
    SX_FIELD("minute_bcd","uint8",0,1,SX_NONE),
    SX_FIELD("second_bcd","uint8",1,1,SX_NONE),
    SX_FIELD("frame_bcd","uint8",2,1,SX_NONE),
};
static const sx_layout sxdn_ecm_mode1_address = {0x60780025U,"ecm_mode1_address",sxdn_ecm_mode1_address_fields,SX_COUNT(sxdn_ecm_mode1_address_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_ecm_mode2_subheader_fields[] = {
    SX_FIELD("file_number","uint8",0,1,SX_ID),
    SX_FIELD("channel_number","uint8",1,1,SX_ID),
    SX_FIELD("submode","uint8",2,1,SX_FLAGS),
    SX_FIELD("coding_information","uint8",3,1,SX_FLAGS),
};
static const sx_layout sxdn_ecm_mode2_subheader = {0x60780026U,"ecm_mode2_subheader",sxdn_ecm_mode2_subheader_fields,SX_COUNT(sxdn_ecm_mode2_subheader_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_kryoflux_oob_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("block_type","uint8",1,1,SX_ID),
    SX_FIELD("payload_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxdn_kryoflux_oob = {0x60780027U,"kryoflux_oob",sxdn_kryoflux_oob_fields,SX_COUNT(sxdn_kryoflux_oob_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_kryoflux_eof_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("block_type","uint8",1,1,SX_ID),
    SX_FIELD("eof_sentinel","uint16",2,2,SX_SIGNATURE),
};
static const sx_layout sxdn_kryoflux_eof = {0x60780028U,"kryoflux_eof",sxdn_kryoflux_eof_fields,SX_COUNT(sxdn_kryoflux_eof_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_kryoflux_stream_info_fields[] = {
    SX_FIELD("stream_position","uint32",0,4,SX_NONE),
    SX_FIELD("transfer_time","uint32",4,4,SX_NONE),
};
static const sx_layout sxdn_kryoflux_stream_info = {0x60780029U,"kryoflux_stream_info",sxdn_kryoflux_stream_info_fields,SX_COUNT(sxdn_kryoflux_stream_info_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_kryoflux_stream_end_fields[] = {
    SX_FIELD("stream_position","uint32",0,4,SX_NONE),
    SX_FIELD("result","uint32",4,4,SX_ID),
};
static const sx_layout sxdn_kryoflux_stream_end = {0x6078002aU,"kryoflux_stream_end",sxdn_kryoflux_stream_end_fields,SX_COUNT(sxdn_kryoflux_stream_end_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_kryoflux_index_fields[] = {
    SX_FIELD("stream_position","uint32",0,4,SX_NONE),
    SX_FIELD("timer","uint32",4,4,SX_NONE),
    SX_FIELD("system_clock","uint32",8,4,SX_NONE),
};
static const sx_layout sxdn_kryoflux_index = {0x6078002bU,"kryoflux_index",sxdn_kryoflux_index_fields,SX_COUNT(sxdn_kryoflux_index_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_simh_cpm_directory_fields[] = {
    SX_FIELD("user_or_status","uint8",0,1,SX_NONE),
    SX_FIELD("filename_and_flags","byte[8]",1,8,SX_NONE),
    SX_FIELD("extension_and_flags","byte[3]",9,3,SX_FLAGS),
    SX_FIELD("extent_low","uint8",12,1,SX_NONE),
    SX_FIELD("reserved","uint8",13,1,SX_NONE),
    SX_FIELD("extent_high","uint8",14,1,SX_NONE),
    SX_FIELD("record_count","uint8",15,1,SX_COUNT_PROP),
    SX_FIELD("allocation_blocks","uint16[8]",16,16,SX_NONE),
};
static const sx_layout sxdn_simh_cpm_directory = {0x6078002cU,"simh_cpm_directory",sxdn_simh_cpm_directory_fields,SX_COUNT(sxdn_simh_cpm_directory_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_svd_version_fields[] = {
    SX_FIELD("value","utf8",0,0,SX_NONE),
};
static const sx_layout sxdn_svd_version = {0x6078002dU,"svd_version",sxdn_svd_version_fields,SX_COUNT(sxdn_svd_version_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_svd_sectors_fields[] = {
    SX_FIELD("value","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_svd_sectors = {0x6078002eU,"svd_sectors",sxdn_svd_sectors_fields,SX_COUNT(sxdn_svd_sectors_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_svd_cylinders_fields[] = {
    SX_FIELD("value","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_svd_cylinders = {0x6078002fU,"svd_cylinders",sxdn_svd_cylinders_fields,SX_COUNT(sxdn_svd_cylinders_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_svd_sides_fields[] = {
    SX_FIELD("value","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdn_svd_sides = {0x60780030U,"svd_sides",sxdn_svd_sides_fields,SX_COUNT(sxdn_svd_sides_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_svd_sector_size_code_fields[] = {
    SX_FIELD("value","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdn_svd_sector_size_code = {0x60780031U,"svd_sector_size_code",sxdn_svd_sector_size_code_fields,SX_COUNT(sxdn_svd_sector_size_code_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_svd_write_protect_fields[] = {
    SX_FIELD("value","ascii_signed",0,0,SX_FLAGS),
};
static const sx_layout sxdn_svd_write_protect = {0x60780032U,"svd_write_protect",sxdn_svd_write_protect_fields,SX_COUNT(sxdn_svd_write_protect_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_disk_descriptor_keyword_fields[] = {
    SX_FIELD("value","utf8",0,0,SX_NONE),
};
static const sx_layout sxdn_disk_descriptor_keyword = {0x60780033U,"disk_descriptor_keyword",sxdn_disk_descriptor_keyword_fields,SX_COUNT(sxdn_disk_descriptor_keyword_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_disk_descriptor_string_fields[] = {
    SX_FIELD("value","utf8",0,0,SX_STRING),
};
static const sx_layout sxdn_disk_descriptor_string = {0x60780034U,"disk_descriptor_string",sxdn_disk_descriptor_string_fields,SX_COUNT(sxdn_disk_descriptor_string_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_kryoflux_info_text_fields[] = {
    SX_FIELD("value","utf8",0,0,SX_STRING),
};
static const sx_layout sxdn_kryoflux_info_text = {0x60780035U,"kryoflux_info_text",sxdn_kryoflux_info_text_fields,SX_COUNT(sxdn_kryoflux_info_text_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite4_header_fields[] = {
    SX_FIELD("signature","char[19]",0,19,SX_SIGNATURE),
    SX_FIELD("unknown","uint32",19,4,SX_NONE),
    SX_FIELD("timestamp_encoded","uint64",23,8,SX_NONE),
};
static const sx_layout sxdn_blindwrite4_header = {0x60780036U,"blindwrite4_header",sxdn_blindwrite4_header_fields,SX_COUNT(sxdn_blindwrite4_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite4_string_size_fields[] = {
    SX_FIELD("string_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxdn_blindwrite4_string_size = {0x60780037U,"blindwrite4_string_size",sxdn_blindwrite4_string_size_fields,SX_COUNT(sxdn_blindwrite4_string_size_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite4_track_count_fields[] = {
    SX_FIELD("track_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxdn_blindwrite4_track_count = {0x60780038U,"blindwrite4_track_count",sxdn_blindwrite4_track_count_fields,SX_COUNT(sxdn_blindwrite4_track_count_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite4_extra_prefix_fields[] = {
    SX_FIELD("unknown","byte[4]",0,4,SX_NONE),
    SX_FIELD("payload_size","uint8",4,1,SX_SIZE),
};
static const sx_layout sxdn_blindwrite4_extra_prefix = {0x60780039U,"blindwrite4_extra_prefix",sxdn_blindwrite4_extra_prefix_fields,SX_COUNT(sxdn_blindwrite4_extra_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite4_track_fields[] = {
    SX_FIELD("external_file_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("subchannel","uint8",4,1,SX_FLAGS),
    SX_FIELD("unknown0","byte[3]",5,3,SX_NONE),
    SX_FIELD("unknown1","uint32",8,4,SX_NONE),
    SX_FIELD("unknown2","uint8",12,1,SX_NONE),
    SX_FIELD("session_number","uint8",13,1,SX_NONE),
    SX_FIELD("unknown3","uint8",14,1,SX_NONE),
    SX_FIELD("adr_control","uint8",15,1,SX_FLAGS),
    SX_FIELD("unknown4","uint8",16,1,SX_NONE),
    SX_FIELD("mode","uint8",17,1,SX_ID),
    SX_FIELD("unknown5","uint8",18,1,SX_NONE),
    SX_FIELD("point","uint8",19,1,SX_ID),
    SX_FIELD("unknown6","uint32[2]",20,8,SX_NONE),
    SX_FIELD("sector_adjustment","uint32",28,4,SX_NONE),
    SX_FIELD("unknown7","uint32",32,4,SX_NONE),
    SX_FIELD("unknown8","uint16",36,2,SX_NONE),
    SX_FIELD("end_sector","uint32",38,4,SX_NONE),
    SX_FIELD("unknown9","uint8",42,1,SX_NONE),
    SX_FIELD("pregap_sector","int32",43,4,SX_NONE),
    SX_FIELD("start_sector","int32",47,4,SX_NONE),
    SX_FIELD("unknown10","uint32[2]",51,8,SX_NONE),
};
static const sx_layout sxdn_blindwrite4_track = {0x6078003aU,"blindwrite4_track",sxdn_blindwrite4_track_fields,SX_COUNT(sxdn_blindwrite4_track_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite56_signature_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
};
static const sx_layout sxdn_blindwrite56_signature = {0x6078003bU,"blindwrite56_signature",sxdn_blindwrite56_signature_fields,SX_COUNT(sxdn_blindwrite56_signature_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite56_disc_fields[] = {
    SX_FIELD("unknown0","uint32[8]",0,32,SX_NONE),
    SX_FIELD("disc_type","uint16",32,2,SX_ID),
    SX_FIELD("session_count","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("unknown1","uint32[3]",36,12,SX_NONE),
    SX_FIELD("mcn_valid","uint8",48,1,SX_FLAGS),
    SX_FIELD("media_catalog_number","char[13]",49,13,SX_NONE),
    SX_FIELD("unknown2","uint16",62,2,SX_NONE),
    SX_FIELD("unknown3","uint32[4]",64,16,SX_NONE),
    SX_FIELD("pma_size","uint16",80,2,SX_SIZE),
    SX_FIELD("atip_size","uint16",82,2,SX_SIZE),
    SX_FIELD("cd_text_size","uint16",84,2,SX_SIZE),
    SX_FIELD("cd_info_size","uint16",86,2,SX_SIZE),
    SX_FIELD("bca_size","uint32",88,4,SX_SIZE),
    SX_FIELD("unknown4","uint32[3]",92,12,SX_NONE),
    SX_FIELD("dvd_structures_size","uint32",104,4,SX_SIZE),
    SX_FIELD("dvd_info_size","uint32",108,4,SX_SIZE),
};
static const sx_layout sxdn_blindwrite56_disc = {0x6078003cU,"blindwrite56_disc",sxdn_blindwrite56_disc_fields,SX_COUNT(sxdn_blindwrite56_disc_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite56_inquiry_fields[] = {
    SX_FIELD("vendor","char[8]",0,8,SX_NONE),
    SX_FIELD("product","char[16]",8,16,SX_NONE),
    SX_FIELD("revision","char[4]",24,4,SX_ID),
    SX_FIELD("vendor_specific","byte[20]",28,20,SX_NONE),
};
static const sx_layout sxdn_blindwrite56_inquiry = {0x6078003dU,"blindwrite56_inquiry",sxdn_blindwrite56_inquiry_fields,SX_COUNT(sxdn_blindwrite56_inquiry_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite56_volume_name_fields[] = {
    SX_FIELD("volume_identifier","char[32]",0,32,SX_NONE),
};
static const sx_layout sxdn_blindwrite56_volume_name = {0x6078003eU,"blindwrite56_volume_name",sxdn_blindwrite56_volume_name_fields,SX_COUNT(sxdn_blindwrite56_volume_name_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite56_lengths_fields[] = {
    SX_FIELD("mode_page_2a_size","uint32",0,4,SX_SIZE),
    SX_FIELD("unknown_block_size","uint32",4,4,SX_SIZE),
    SX_FIELD("data_blocks_size","uint32",8,4,SX_SIZE),
    SX_FIELD("sessions_size","uint32",12,4,SX_SIZE),
    SX_FIELD("dpm_size","uint32",16,4,SX_SIZE),
};
static const sx_layout sxdn_blindwrite56_lengths = {0x6078003fU,"blindwrite56_lengths",sxdn_blindwrite56_lengths_fields,SX_COUNT(sxdn_blindwrite56_lengths_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite56_data_list_fields[] = {
    SX_FIELD("block_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("drive_path_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxdn_blindwrite56_data_list = {0x60780040U,"blindwrite56_data_list",sxdn_blindwrite56_data_list_fields,SX_COUNT(sxdn_blindwrite56_data_list_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite56_data_block_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_FLAGS),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
    SX_FIELD("unknown0","uint32[4]",8,16,SX_NONE),
    SX_FIELD("external_file_offset","uint32",24,4,SX_OFFSET),
    SX_FIELD("unknown1","uint32[3]",28,12,SX_NONE),
    SX_FIELD("start_sector","int32",40,4,SX_NONE),
    SX_FIELD("sector_count","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("filename_size","uint32",48,4,SX_SIZE),
};
static const sx_layout sxdn_blindwrite56_data_block = {0x60780041U,"blindwrite56_data_block",sxdn_blindwrite56_data_block_fields,SX_COUNT(sxdn_blindwrite56_data_block_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite56_data_tail_fields[] = {
    SX_FIELD("unknown","uint32",0,4,SX_NONE),
};
static const sx_layout sxdn_blindwrite56_data_tail = {0x60780042U,"blindwrite56_data_tail",sxdn_blindwrite56_data_tail_fields,SX_COUNT(sxdn_blindwrite56_data_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite56_session_fields[] = {
    SX_FIELD("session_number","uint16",0,2,SX_NONE),
    SX_FIELD("entry_count","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("unknown","uint8",3,1,SX_NONE),
    SX_FIELD("start_sector","int32",4,4,SX_NONE),
    SX_FIELD("end_sector","int32",8,4,SX_NONE),
    SX_FIELD("first_track","uint16",12,2,SX_NONE),
    SX_FIELD("last_track","uint16",14,2,SX_NONE),
};
static const sx_layout sxdn_blindwrite56_session = {0x60780043U,"blindwrite56_session",sxdn_blindwrite56_session_fields,SX_COUNT(sxdn_blindwrite56_session_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite56_entry_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
    SX_FIELD("unknown0","byte[3]",1,3,SX_NONE),
    SX_FIELD("unknown1","uint32",4,4,SX_NONE),
    SX_FIELD("subchannel","uint8",8,1,SX_ID),
    SX_FIELD("unknown2","uint8",9,1,SX_NONE),
    SX_FIELD("control","uint8",10,1,SX_FLAGS),
    SX_FIELD("adr","uint8",11,1,SX_ID),
    SX_FIELD("point","uint8",12,1,SX_ID),
    SX_FIELD("track_number","uint8",13,1,SX_NONE),
    SX_FIELD("minute","uint8",14,1,SX_NONE),
    SX_FIELD("second","uint8",15,1,SX_NONE),
    SX_FIELD("frame","uint8",16,1,SX_NONE),
    SX_FIELD("zero","uint8",17,1,SX_NONE),
    SX_FIELD("pminute","uint8",18,1,SX_NONE),
    SX_FIELD("psecond","uint8",19,1,SX_NONE),
    SX_FIELD("pframe","uint8",20,1,SX_NONE),
    SX_FIELD("unknown3","uint8",21,1,SX_NONE),
    SX_FIELD("pregap_sector_count","uint32",22,4,SX_COUNT_PROP),
    SX_FIELD("unknown4","uint32[4]",26,16,SX_NONE),
    SX_FIELD("first_sector","int32",42,4,SX_NONE),
    SX_FIELD("sector_count","int32",46,4,SX_COUNT_PROP),
    SX_FIELD("unknown5","uint32[2]",50,8,SX_NONE),
    SX_FIELD("session","uint32",58,4,SX_NONE),
    SX_FIELD("unknown6","uint16",62,2,SX_NONE),
};
static const sx_layout sxdn_blindwrite56_entry = {0x60780044U,"blindwrite56_entry",sxdn_blindwrite56_entry_fields,SX_COUNT(sxdn_blindwrite56_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite56_cd_extra_fields[] = {
    SX_FIELD("producer_data","byte[8]",0,8,SX_NONE),
};
static const sx_layout sxdn_blindwrite56_cd_extra = {0x60780045U,"blindwrite56_cd_extra",sxdn_blindwrite56_cd_extra_fields,SX_COUNT(sxdn_blindwrite56_cd_extra_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_blindwrite56_footer_fields[] = {
    SX_FIELD("descriptor_size","uint32",0,4,SX_SIZE),
    SX_FIELD("signature","char[16]",4,16,SX_SIGNATURE),
};
static const sx_layout sxdn_blindwrite56_footer = {0x60780046U,"blindwrite56_footer",sxdn_blindwrite56_footer_fields,SX_COUNT(sxdn_blindwrite56_footer_fields),SX_LE};

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

static const xx_data_struct_field_desc sxdn_old_jffs2_common_header_le_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
};
static const sx_layout sxdn_old_jffs2_common_header_le = {0x6078004aU,"old_jffs2_common_header_le",sxdn_old_jffs2_common_header_le_fields,SX_COUNT(sxdn_old_jffs2_common_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_old_jffs2_directory_entry_le_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("parent_inode","uint32",12,4,SX_ID),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("inode","uint32",20,4,SX_ID),
    SX_FIELD("modification_time","uint32",24,4,SX_TIME),
    SX_FIELD("name_size","uint8",28,1,SX_SIZE),
    SX_FIELD("type","uint8",29,1,SX_ID),
    SX_FIELD("unused","byte[2]",30,2,SX_RESERVED),
    SX_FIELD("node_crc","uint32",32,4,SX_CHECKSUM),
    SX_FIELD("name_crc","uint32",36,4,SX_CHECKSUM),
};
static const sx_layout sxdn_old_jffs2_directory_entry_le = {0x6078004bU,"old_jffs2_directory_entry_le",sxdn_old_jffs2_directory_entry_le_fields,SX_COUNT(sxdn_old_jffs2_directory_entry_le_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_old_jffs2_inode_le_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("inode","uint32",12,4,SX_ID),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("mode","uint32",20,4,SX_FLAGS),
    SX_FIELD("uid","uint16",24,2,SX_ID),
    SX_FIELD("gid","uint16",26,2,SX_ID),
    SX_FIELD("file_size","uint32",28,4,SX_SIZE),
    SX_FIELD("access_time","uint32",32,4,SX_TIME),
    SX_FIELD("modification_time","uint32",36,4,SX_TIME),
    SX_FIELD("change_time","uint32",40,4,SX_TIME),
    SX_FIELD("file_offset","uint32",44,4,SX_OFFSET),
    SX_FIELD("compressed_size","uint32",48,4,SX_SIZE),
    SX_FIELD("decompressed_size","uint32",52,4,SX_SIZE),
    SX_FIELD("compression","uint8",56,1,SX_ID),
    SX_FIELD("user_compression","uint8",57,1,SX_ID),
    SX_FIELD("flags","uint16",58,2,SX_FLAGS),
    SX_FIELD("data_crc","uint32",60,4,SX_CHECKSUM),
    SX_FIELD("node_crc","uint32",64,4,SX_CHECKSUM),
};
static const sx_layout sxdn_old_jffs2_inode_le = {0x6078004cU,"old_jffs2_inode_le",sxdn_old_jffs2_inode_le_fields,SX_COUNT(sxdn_old_jffs2_inode_le_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_old_jffs2_xattr_le_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("xid","uint32",12,4,SX_ID),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("prefix","uint8",20,1,SX_ID),
    SX_FIELD("name_length","uint8",21,1,SX_SIZE),
    SX_FIELD("value_length","uint16",22,2,SX_SIZE),
    SX_FIELD("data_crc","uint32",24,4,SX_CHECKSUM),
    SX_FIELD("node_crc","uint32",28,4,SX_CHECKSUM),
};
static const sx_layout sxdn_old_jffs2_xattr_le = {0x6078004dU,"old_jffs2_xattr_le",sxdn_old_jffs2_xattr_le_fields,SX_COUNT(sxdn_old_jffs2_xattr_le_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_old_jffs2_xref_le_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("inode","uint32",12,4,SX_ID),
    SX_FIELD("xid","uint32",16,4,SX_ID),
    SX_FIELD("sequence_number","uint32",20,4,SX_NONE),
    SX_FIELD("node_crc","uint32",24,4,SX_CHECKSUM),
};
static const sx_layout sxdn_old_jffs2_xref_le = {0x6078004eU,"old_jffs2_xref_le",sxdn_old_jffs2_xref_le_fields,SX_COUNT(sxdn_old_jffs2_xref_le_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_old_jffs2_common_header_be_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
};
static const sx_layout sxdn_old_jffs2_common_header_be = {0x6078004fU,"old_jffs2_common_header_be",sxdn_old_jffs2_common_header_be_fields,SX_COUNT(sxdn_old_jffs2_common_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_old_jffs2_directory_entry_be_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("parent_inode","uint32",12,4,SX_ID),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("inode","uint32",20,4,SX_ID),
    SX_FIELD("modification_time","uint32",24,4,SX_TIME),
    SX_FIELD("name_size","uint8",28,1,SX_SIZE),
    SX_FIELD("type","uint8",29,1,SX_ID),
    SX_FIELD("unused","byte[2]",30,2,SX_RESERVED),
    SX_FIELD("node_crc","uint32",32,4,SX_CHECKSUM),
    SX_FIELD("name_crc","uint32",36,4,SX_CHECKSUM),
};
static const sx_layout sxdn_old_jffs2_directory_entry_be = {0x60780050U,"old_jffs2_directory_entry_be",sxdn_old_jffs2_directory_entry_be_fields,SX_COUNT(sxdn_old_jffs2_directory_entry_be_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_old_jffs2_inode_be_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("inode","uint32",12,4,SX_ID),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("mode","uint32",20,4,SX_FLAGS),
    SX_FIELD("uid","uint16",24,2,SX_ID),
    SX_FIELD("gid","uint16",26,2,SX_ID),
    SX_FIELD("file_size","uint32",28,4,SX_SIZE),
    SX_FIELD("access_time","uint32",32,4,SX_TIME),
    SX_FIELD("modification_time","uint32",36,4,SX_TIME),
    SX_FIELD("change_time","uint32",40,4,SX_TIME),
    SX_FIELD("file_offset","uint32",44,4,SX_OFFSET),
    SX_FIELD("compressed_size","uint32",48,4,SX_SIZE),
    SX_FIELD("decompressed_size","uint32",52,4,SX_SIZE),
    SX_FIELD("compression","uint8",56,1,SX_ID),
    SX_FIELD("user_compression","uint8",57,1,SX_ID),
    SX_FIELD("flags","uint16",58,2,SX_FLAGS),
    SX_FIELD("data_crc","uint32",60,4,SX_CHECKSUM),
    SX_FIELD("node_crc","uint32",64,4,SX_CHECKSUM),
};
static const sx_layout sxdn_old_jffs2_inode_be = {0x60780051U,"old_jffs2_inode_be",sxdn_old_jffs2_inode_be_fields,SX_COUNT(sxdn_old_jffs2_inode_be_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_old_jffs2_xattr_be_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("xid","uint32",12,4,SX_ID),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("prefix","uint8",20,1,SX_ID),
    SX_FIELD("name_length","uint8",21,1,SX_SIZE),
    SX_FIELD("value_length","uint16",22,2,SX_SIZE),
    SX_FIELD("data_crc","uint32",24,4,SX_CHECKSUM),
    SX_FIELD("node_crc","uint32",28,4,SX_CHECKSUM),
};
static const sx_layout sxdn_old_jffs2_xattr_be = {0x60780052U,"old_jffs2_xattr_be",sxdn_old_jffs2_xattr_be_fields,SX_COUNT(sxdn_old_jffs2_xattr_be_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_old_jffs2_xref_be_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("inode","uint32",12,4,SX_ID),
    SX_FIELD("xid","uint32",16,4,SX_ID),
    SX_FIELD("sequence_number","uint32",20,4,SX_NONE),
    SX_FIELD("node_crc","uint32",24,4,SX_CHECKSUM),
};
static const sx_layout sxdn_old_jffs2_xref_be = {0x60780053U,"old_jffs2_xref_be",sxdn_old_jffs2_xref_be_fields,SX_COUNT(sxdn_old_jffs2_xref_be_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_sqlz_squashfs2_superblock_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("inode_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("bytes_used_legacy","uint32",8,4,SX_SIZE),
    SX_FIELD("uid_table_offset_legacy","uint32",12,4,SX_OFFSET),
    SX_FIELD("gid_table_offset_legacy","uint32",16,4,SX_OFFSET),
    SX_FIELD("inode_table_offset_legacy","uint32",20,4,SX_OFFSET),
    SX_FIELD("directory_table_offset_legacy","uint32",24,4,SX_OFFSET),
    SX_FIELD("major","uint16",28,2,SX_NONE),
    SX_FIELD("minor","uint16",30,2,SX_NONE),
    SX_FIELD("block_size_legacy","uint16",32,2,SX_SIZE),
    SX_FIELD("block_log","uint16",34,2,SX_NONE),
    SX_FIELD("flags","uint8",36,1,SX_FLAGS),
    SX_FIELD("uid_count","uint8",37,1,SX_COUNT_PROP),
    SX_FIELD("gid_count","uint8",38,1,SX_COUNT_PROP),
    SX_FIELD("creation_time","int32",39,4,SX_TIME),
    SX_FIELD("root_inode_reference","uint64",43,8,SX_FLAGS),
    SX_FIELD("block_size","uint32",51,4,SX_SIZE),
    SX_FIELD("fragment_count","uint32",55,4,SX_COUNT_PROP),
    SX_FIELD("fragment_index_offset_legacy","uint32",59,4,SX_OFFSET),
};
static const sx_layout sxdn_sqlz_squashfs2_superblock_le = {0x60780054U,"sqlz_squashfs2_superblock_le",sxdn_sqlz_squashfs2_superblock_le_fields,SX_COUNT(sxdn_sqlz_squashfs2_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_sqlz_squashfs2_superblock_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("inode_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("bytes_used_legacy","uint32",8,4,SX_SIZE),
    SX_FIELD("uid_table_offset_legacy","uint32",12,4,SX_OFFSET),
    SX_FIELD("gid_table_offset_legacy","uint32",16,4,SX_OFFSET),
    SX_FIELD("inode_table_offset_legacy","uint32",20,4,SX_OFFSET),
    SX_FIELD("directory_table_offset_legacy","uint32",24,4,SX_OFFSET),
    SX_FIELD("major","uint16",28,2,SX_NONE),
    SX_FIELD("minor","uint16",30,2,SX_NONE),
    SX_FIELD("block_size_legacy","uint16",32,2,SX_SIZE),
    SX_FIELD("block_log","uint16",34,2,SX_NONE),
    SX_FIELD("flags","uint8",36,1,SX_FLAGS),
    SX_FIELD("uid_count","uint8",37,1,SX_COUNT_PROP),
    SX_FIELD("gid_count","uint8",38,1,SX_COUNT_PROP),
    SX_FIELD("creation_time","int32",39,4,SX_TIME),
    SX_FIELD("root_inode_reference","uint64",43,8,SX_FLAGS),
    SX_FIELD("block_size","uint32",51,4,SX_SIZE),
    SX_FIELD("fragment_count","uint32",55,4,SX_COUNT_PROP),
    SX_FIELD("fragment_index_offset_legacy","uint32",59,4,SX_OFFSET),
};
static const sx_layout sxdn_sqlz_squashfs2_superblock_be = {0x60780055U,"sqlz_squashfs2_superblock_be",sxdn_sqlz_squashfs2_superblock_be_fields,SX_COUNT(sxdn_sqlz_squashfs2_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_sqlz_squashfs3_superblock_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("inode_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("bytes_used_legacy","uint32",8,4,SX_SIZE),
    SX_FIELD("uid_table_offset_legacy","uint32",12,4,SX_OFFSET),
    SX_FIELD("gid_table_offset_legacy","uint32",16,4,SX_OFFSET),
    SX_FIELD("inode_table_offset_legacy","uint32",20,4,SX_OFFSET),
    SX_FIELD("directory_table_offset_legacy","uint32",24,4,SX_OFFSET),
    SX_FIELD("major","uint16",28,2,SX_NONE),
    SX_FIELD("minor","uint16",30,2,SX_NONE),
    SX_FIELD("block_size_legacy","uint16",32,2,SX_SIZE),
    SX_FIELD("block_log","uint16",34,2,SX_NONE),
    SX_FIELD("flags","uint8",36,1,SX_FLAGS),
    SX_FIELD("uid_count","uint8",37,1,SX_COUNT_PROP),
    SX_FIELD("gid_count","uint8",38,1,SX_COUNT_PROP),
    SX_FIELD("creation_time","int32",39,4,SX_TIME),
    SX_FIELD("root_inode_reference","uint64",43,8,SX_FLAGS),
    SX_FIELD("block_size","uint32",51,4,SX_SIZE),
    SX_FIELD("fragment_count","uint32",55,4,SX_COUNT_PROP),
    SX_FIELD("fragment_index_offset_legacy","uint32",59,4,SX_OFFSET),
    SX_FIELD("bytes_used","uint64",63,8,SX_SIZE),
    SX_FIELD("uid_table_offset","uint64",71,8,SX_OFFSET),
    SX_FIELD("gid_table_offset","uint64",79,8,SX_OFFSET),
    SX_FIELD("inode_table_offset","uint64",87,8,SX_OFFSET),
    SX_FIELD("directory_table_offset","uint64",95,8,SX_OFFSET),
    SX_FIELD("fragment_index_offset","uint64",103,8,SX_OFFSET),
    SX_FIELD("lookup_index_offset","uint64",111,8,SX_OFFSET),
};
static const sx_layout sxdn_sqlz_squashfs3_superblock_le = {0x60780056U,"sqlz_squashfs3_superblock_le",sxdn_sqlz_squashfs3_superblock_le_fields,SX_COUNT(sxdn_sqlz_squashfs3_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_sqlz_squashfs3_superblock_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("inode_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("bytes_used_legacy","uint32",8,4,SX_SIZE),
    SX_FIELD("uid_table_offset_legacy","uint32",12,4,SX_OFFSET),
    SX_FIELD("gid_table_offset_legacy","uint32",16,4,SX_OFFSET),
    SX_FIELD("inode_table_offset_legacy","uint32",20,4,SX_OFFSET),
    SX_FIELD("directory_table_offset_legacy","uint32",24,4,SX_OFFSET),
    SX_FIELD("major","uint16",28,2,SX_NONE),
    SX_FIELD("minor","uint16",30,2,SX_NONE),
    SX_FIELD("block_size_legacy","uint16",32,2,SX_SIZE),
    SX_FIELD("block_log","uint16",34,2,SX_NONE),
    SX_FIELD("flags","uint8",36,1,SX_FLAGS),
    SX_FIELD("uid_count","uint8",37,1,SX_COUNT_PROP),
    SX_FIELD("gid_count","uint8",38,1,SX_COUNT_PROP),
    SX_FIELD("creation_time","int32",39,4,SX_TIME),
    SX_FIELD("root_inode_reference","uint64",43,8,SX_FLAGS),
    SX_FIELD("block_size","uint32",51,4,SX_SIZE),
    SX_FIELD("fragment_count","uint32",55,4,SX_COUNT_PROP),
    SX_FIELD("fragment_index_offset_legacy","uint32",59,4,SX_OFFSET),
    SX_FIELD("bytes_used","uint64",63,8,SX_SIZE),
    SX_FIELD("uid_table_offset","uint64",71,8,SX_OFFSET),
    SX_FIELD("gid_table_offset","uint64",79,8,SX_OFFSET),
    SX_FIELD("inode_table_offset","uint64",87,8,SX_OFFSET),
    SX_FIELD("directory_table_offset","uint64",95,8,SX_OFFSET),
    SX_FIELD("fragment_index_offset","uint64",103,8,SX_OFFSET),
    SX_FIELD("lookup_index_offset","uint64",111,8,SX_OFFSET),
};
static const sx_layout sxdn_sqlz_squashfs3_superblock_be = {0x60780057U,"sqlz_squashfs3_superblock_be",sxdn_sqlz_squashfs3_superblock_be_fields,SX_COUNT(sxdn_sqlz_squashfs3_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_sqlz_squashfs_metadata_header_le_fields[] = {
    SX_FIELD("size_and_stored_flag","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxdn_sqlz_squashfs_metadata_header_le = {0x60780058U,"sqlz_squashfs_metadata_header_le",sxdn_sqlz_squashfs_metadata_header_le_fields,SX_COUNT(sxdn_sqlz_squashfs_metadata_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_sqlz_squashfs_table_index_le_fields[] = {
    SX_FIELD("metadata_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxdn_sqlz_squashfs_table_index_le = {0x60780059U,"sqlz_squashfs_table_index_le",sxdn_sqlz_squashfs_table_index_le_fields,SX_COUNT(sxdn_sqlz_squashfs_table_index_le_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_sqlz_squashfs2_fragment_index_le_fields[] = {
    SX_FIELD("metadata_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxdn_sqlz_squashfs2_fragment_index_le = {0x6078005aU,"sqlz_squashfs2_fragment_index_le",sxdn_sqlz_squashfs2_fragment_index_le_fields,SX_COUNT(sxdn_sqlz_squashfs2_fragment_index_le_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_sqlz_squashfs_identity_le_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_ID),
};
static const sx_layout sxdn_sqlz_squashfs_identity_le = {0x6078005bU,"sqlz_squashfs_identity_le",sxdn_sqlz_squashfs_identity_le_fields,SX_COUNT(sxdn_sqlz_squashfs_identity_le_fields),SX_LE};

static const xx_data_struct_field_desc sxdn_sqlz_squashfs_metadata_header_be_fields[] = {
    SX_FIELD("size_and_stored_flag","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxdn_sqlz_squashfs_metadata_header_be = {0x6078005cU,"sqlz_squashfs_metadata_header_be",sxdn_sqlz_squashfs_metadata_header_be_fields,SX_COUNT(sxdn_sqlz_squashfs_metadata_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_sqlz_squashfs_table_index_be_fields[] = {
    SX_FIELD("metadata_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxdn_sqlz_squashfs_table_index_be = {0x6078005dU,"sqlz_squashfs_table_index_be",sxdn_sqlz_squashfs_table_index_be_fields,SX_COUNT(sxdn_sqlz_squashfs_table_index_be_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_sqlz_squashfs2_fragment_index_be_fields[] = {
    SX_FIELD("metadata_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxdn_sqlz_squashfs2_fragment_index_be = {0x6078005eU,"sqlz_squashfs2_fragment_index_be",sxdn_sqlz_squashfs2_fragment_index_be_fields,SX_COUNT(sxdn_sqlz_squashfs2_fragment_index_be_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_sqlz_squashfs_identity_be_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_ID),
};
static const sx_layout sxdn_sqlz_squashfs_identity_be = {0x6078005fU,"sqlz_squashfs_identity_be",sxdn_sqlz_squashfs_identity_be_fields,SX_COUNT(sxdn_sqlz_squashfs_identity_be_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_jvc_os9_disk_descriptor_fields[] = {
    SX_FIELD("total_sectors","uint24",0,3,SX_COUNT_PROP),
    SX_FIELD("track_sector_count","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("bitmap_bytes","uint16",4,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("root_fd_sector","uint24",8,3,SX_NONE),
    SX_FIELD("owner","uint16",11,2,SX_ID),
    SX_FIELD("attributes","uint8",13,1,SX_FLAGS),
    SX_FIELD("disk_id","uint16",14,2,SX_ID),
    SX_FIELD("format","uint8",16,1,SX_FLAGS),
    SX_FIELD("sectors_per_track","uint16",17,2,SX_COUNT_PROP),
    SX_FIELD("reserved19","byte[2]",19,2,SX_RESERVED),
    SX_FIELD("bootstrap_sector","uint24",21,3,SX_NONE),
    SX_FIELD("bootstrap_bytes","uint16",24,2,SX_SIZE),
    SX_FIELD("creation_ymdhm","byte[5]",26,5,SX_NONE),
    SX_FIELD("volume_name","byte[32]",31,32,SX_NONE),
};
static const sx_layout sxdn_jvc_os9_disk_descriptor = {0x60780060U,"jvc_os9_disk_descriptor",sxdn_jvc_os9_disk_descriptor_fields,SX_COUNT(sxdn_jvc_os9_disk_descriptor_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_jvc_os9_path_options_fields[] = {
    SX_FIELD("device_class","uint8",0,1,SX_ID),
    SX_FIELD("drive","uint8",1,1,SX_NONE),
    SX_FIELD("step_rate","uint8",2,1,SX_NONE),
    SX_FIELD("device_type","uint8",3,1,SX_FLAGS),
    SX_FIELD("density","uint8",4,1,SX_FLAGS),
    SX_FIELD("cylinders","uint16",5,2,SX_COUNT_PROP),
    SX_FIELD("sides","uint8",7,1,SX_COUNT_PROP),
    SX_FIELD("verify_disable","uint8",8,1,SX_FLAGS),
    SX_FIELD("sectors_per_track","uint16",9,2,SX_COUNT_PROP),
    SX_FIELD("track0_sectors","uint16",11,2,SX_COUNT_PROP),
    SX_FIELD("interleave","uint8",13,1,SX_NONE),
    SX_FIELD("segment_allocation_size","uint8",14,1,SX_NONE),
    SX_FIELD("dma_mode","uint8",15,1,SX_FLAGS),
    SX_FIELD("record_extension","uint16",16,2,SX_NONE),
    SX_FIELD("sector_track_offsets","uint8",18,1,SX_NONE),
    SX_FIELD("file_attributes","uint8",19,1,SX_FLAGS),
    SX_FIELD("file_descriptor_sector","uint24",20,3,SX_NONE),
    SX_FIELD("directory_descriptor_sector","uint24",23,3,SX_NONE),
    SX_FIELD("directory_entry_offset","uint32",26,4,SX_OFFSET),
    SX_FIELD("device_table_address","uint16",30,2,SX_ADDRESS),
};
static const sx_layout sxdn_jvc_os9_path_options = {0x60780061U,"jvc_os9_path_options",sxdn_jvc_os9_path_options_fields,SX_COUNT(sxdn_jvc_os9_path_options_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_jvc_os9_file_descriptor_fields[] = {
    SX_FIELD("attributes","uint8",0,1,SX_FLAGS),
    SX_FIELD("owner","uint16",1,2,SX_ID),
    SX_FIELD("modification_ymdhm","byte[5]",3,5,SX_NONE),
    SX_FIELD("link_count","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("byte_size","uint32",9,4,SX_SIZE),
    SX_FIELD("creation_ymd","byte[3]",13,3,SX_NONE),
};
static const sx_layout sxdn_jvc_os9_file_descriptor = {0x60780062U,"jvc_os9_file_descriptor",sxdn_jvc_os9_file_descriptor_fields,SX_COUNT(sxdn_jvc_os9_file_descriptor_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_jvc_os9_segment_fields[] = {
    SX_FIELD("first_sector","uint24",0,3,SX_NONE),
    SX_FIELD("sector_count","uint16",3,2,SX_COUNT_PROP),
};
static const sx_layout sxdn_jvc_os9_segment = {0x60780063U,"jvc_os9_segment",sxdn_jvc_os9_segment_fields,SX_COUNT(sxdn_jvc_os9_segment_fields),SX_BE};

static const xx_data_struct_field_desc sxdn_jvc_os9_directory_entry_fields[] = {
    SX_FIELD("name","byte[29]",0,29,SX_NONE),
    SX_FIELD("file_descriptor_sector","uint24",29,3,SX_NONE),
};
static const sx_layout sxdn_jvc_os9_directory_entry = {0x60780064U,"jvc_os9_directory_entry",sxdn_jvc_os9_directory_entry_fields,SX_COUNT(sxdn_jvc_os9_directory_entry_fields),SX_BE};

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
static bool sxdn_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxdn_read(sx_context*c,uint64_t p,void*b,size_t n){return !xx_pd_is_stopped(c->pd)&&sxdn_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint16_t sxdn16(const uint8_t*b,unsigned o){return o==1?(uint16_t)((uint16_t)b[0]<<8|b[1]):(uint16_t)((uint16_t)b[1]<<8|b[0]);}
static uint32_t sxdn32(const uint8_t*b,unsigned o){if(o==2)return (uint32_t)sxdn16(b,0)<<16|sxdn16(b+2,0);return o==1?(uint32_t)sxdn16(b,1)<<16|sxdn16(b+2,1):(uint32_t)sxdn16(b+2,0)<<16|sxdn16(b,0);}
static bool sxdn_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
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
#define SXDN_TABLE(c,l,p,n) sxdn_put(c,&sxdn_##l,p,n)

static bool sxdn_value(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){if(!n)return true;if(!sxdn_span(c,p,n)||xx_pd_is_stopped(c->pd))return false;const xx_data_struct_field_desc*last=l->fields+l->field_count-1;uint64_t limit=sx_variable_field_limit(last->type);if(n<=(uint64_t)last->rel_offset||n-(uint64_t)last->rel_offset>limit||n>16384||c->count>=SXDN_LIMIT)return true;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<c->f->base_address+(int64_t)p)lo=m+1;else hi=m;}if(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>c->f->base_address+(int64_t)p)return true;if(lo<c->count&&c->items[lo].offset<c->f->base_address+(int64_t)(p+n))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
static bool sxdn_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxdn_read(c,p,b,n))return false;*v=0;for(unsigned i=0;i<n;i++)*v|=(uint64_t)b[i]<<(8*(be?n-i-1:i));return true;}
static bool sxdn_msx(sx_context*c){uint64_t p=0;for(unsigned i=0;i<1024&&p<(uint64_t)c->size&&c->count<SXDN_LIMIT;i++){uint8_t h[38];if(!sxdn_read(c,p,h,38))break;uint64_t start=sxdn16(h+32,0),end=sxdn16(h+34,0);if(end<start||!SXDN_ADD(c,msx_cas_binary_header,p)||!sxdn_span(c,p+38,end-start+1))break;p+=38+end-start+1;uint8_t b;while(p<(uint64_t)c->size&&sxdn_read(c,p,&b,1)&&b==0)p++;}return c->count!=0;}
static bool sxdn_dragon(sx_context*c){uint64_t p=0;for(unsigned i=0;i<4096&&p<(uint64_t)c->size&&c->count<SXDN_LIMIT;i++){uint8_t h[3];while(p<(uint64_t)c->size&&sxdn_read(c,p,h,1)&&h[0]==0x55)p++;if(!sxdn_read(c,p,h,3)||h[0]!=0x3c||!sxdn_span(c,p,4+(uint64_t)h[2]))break;if(!SXDN_ADD(c,dragon_cas_block_header,p)||!SXDN_ADD(c,dragon_cas_block_checksum,p+3+h[2]))return false;if(!h[1]&&h[2]==15&&!SXDN_ADD(c,dragon_cas_file_header,p+3))return false;p+=4+h[2];}return c->count!=0;}
static bool sxdn_hobeta(sx_context*c){uint8_t h[17];return sxdn_read(c,0,h,17)&&sxdn_put(c,h[8]=='C'?&sxdn_hobeta_code_header:&sxdn_hobeta_header,0,1);}
static bool sxdn_cfd(sx_context*c){uint8_t h[32];if(!sxdn_read(c,0,h,32)||!SXDN_ADD(c,cfd_header,0))return false;if(sxdn16(h+26,0)&0x800)return true;for(uint64_t p=32;p<(uint64_t)c->size&&c->count<SXDN_LIMIT;){if(!sxdn_read(c,p,h,4))break;uint64_t z=sxdn16(h,0),n=sxdn16(h+2,0);if(z<4||n<2||n>z-2||(n-2)%4||!sxdn_span(c,p,z))break;if(!SXDN_ADD(c,cfd_block,p)||!SXDN_TABLE(c,cfd_repeat,p+4,(n-2)/4))return false;p+=z;}return true;}
static bool sxdn_dcp(sx_context*c){uint8_t h[96];if(!sxdn_read(c,0,h,96)||!SXDN_ADD(c,dcp_disk_header,0))return false;if(!sxdn16(h+90,0))return true;for(uint64_t p=512;p<(uint64_t)c->size&&c->count<SXDN_LIMIT;){if(!sxdn_read(c,p,h,2)||!SXDN_ADD(c,dcp_rdc_block,p))break;uint64_t v=sxdn16(h,0),n=(v&0x8000)?65536-v:v;p+=2;if(!v||!sxdn_span(c,p,n))break;p+=n;}return true;}
static bool sxdn_cfi(sx_context*c){uint8_t h[2];uint64_t p=0;for(unsigned track=0;track<256&&p<(uint64_t)c->size&&c->count<SXDN_LIMIT;track++){if(!sxdn_read(c,p,h,2)||!SXDN_ADD(c,fdcopy_track,p))break;uint64_t z=sxdn16(h,0),q=p+2;if(!sxdn_span(c,q,z))break;uint64_t end=q+z;while(q<end&&c->count<SXDN_LIMIT){if(end-q<2||!sxdn_read(c,q,h,2))break;uint64_t v=sxdn16(h,0),n=v&0x7fff;if(!n||!SXDN_ADD(c,fdcopy_token,q))return true;q+=2;if(v&0x8000){if(q>=end||!SXDN_ADD(c,fdcopy_repeat,q))return true;q++;}else{if(n>end-q)return true;q+=n;}}p=end;}return c->count!=0;}
static bool sxdn_cp2(sx_context*c){uint8_t h[3];if(!SXDN_ADD(c,cp2_header,0))return false;for(uint64_t p=30;p<(uint64_t)c->size&&c->count<SXDN_LIMIT;){if(!sxdn_read(c,p,h,2))break;uint64_t z=sxdn16(h,0);if(z<388||(z-1)%387||z>387*32+1||!sxdn_span(c,p,4+z)||!SXDN_ADD(c,cp2_segment_header,p))break;for(uint64_t i=0;i<(z-1)/387;i++){uint64_t a=p+2+i*387;if(!sxdn_read(c,a,h,3)||h[2]>24||!SXDN_ADD(c,cp2_track,a)||!SXDN_TABLE(c,cp2_sector,a+3,h[2]))return false;}if(!SXDN_ADD(c,cp2_header_checksum,p+1+z)||!SXDN_ADD(c,cp2_segment_payload,p+2+z)||!sxdn_read(c,p+2+z,h,2))return false;uint64_t n=sxdn16(h,0);p+=4+z;if(!sxdn_span(c,p,n))break;p+=n;}return true;}
static bool sxdn_ecm(sx_context*c){if(!SXDN_ADD(c,ecm_signature,0))return false;uint64_t p=4;for(unsigned work=0;work<1000000&&p<(uint64_t)c->size&&c->count<SXDN_LIMIT;work++){uint8_t b;if(!sxdn_read(c,p,&b,1)||!SXDN_ADD(c,ecm_record_first,p++))break;unsigned type=b&3,bits=5;uint64_t v=(b&0x7c)>>2;while(b&0x80){if(bits>33||!sxdn_read(c,p,&b,1)||!SXDN_ADD(c,ecm_record_continuation,p++))return true;v|=(uint64_t)(b&127)<<bits;bits+=7;}if(v>UINT32_MAX)return true;if(v==UINT32_MAX)return sxdn_span(c,p,4)?SXDN_ADD(c,ecm_edc,p):true;static const unsigned sizes[]={1,2051,2052,2328};uint64_t n=v+1;if(n>((uint64_t)c->size-p)/sizes[type])return true;if(type)for(uint64_t i=0;i<n&&c->count<SXDN_LIMIT;i++)if(!sxdn_put(c,type==1?&sxdn_ecm_mode1_address:&sxdn_ecm_mode2_subheader,p+i*sizes[type],1))return false;p+=n*sizes[type];}return true;}
static bool sxdn_kryo(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size&&c->count<SXDN_LIMIT){uint8_t b[4];if(!sxdn_read(c,p,b,1))break;if(b[0]!=13){uint64_t n=b[0]<8||b[0]==9?2:b[0]==10||b[0]==12?3:1;if(!sxdn_span(c,p,n))break;p+=n;continue;}if(!sxdn_read(c,p,b,4))break;uint64_t z=sxdn16(b+2,0);if(b[1]==13)return SXDN_ADD(c,kryoflux_eof,p);if(!sxdn_span(c,p+4,z)||!SXDN_ADD(c,kryoflux_oob,p))break;p+=4;if(b[1]==1&&z>=8){if(!SXDN_ADD(c,kryoflux_stream_info,p))return false;}else if(b[1]==2&&z>=12){if(!SXDN_ADD(c,kryoflux_index,p))return false;}else if(b[1]==3&&z>=8){if(!SXDN_ADD(c,kryoflux_stream_end,p))return false;}else if(b[1]==4&&!sxdn_value(c,&sxdn_kryoflux_info_text,p,z))return false;p+=z;}return c->count!=0;}
static bool sxdn_simh(sx_context*c){for(unsigned sector=192;sector<256;sector++)if(!SXDN_TABLE(c,simh_cpm_directory,(uint64_t)sector*137+3,4))return false;return true;}
static bool sxdn_bw4_string(sx_context*c,uint64_t*p){uint64_t n;if(!sxdn_word(c,*p,4,false,&n)||!sxdn_span(c,*p+4,n)||!SXDN_ADD(c,blindwrite4_string_size,*p))return false;*p+=4;if(!sxdn_value(c,&sxdn_disk_descriptor_string,*p,n))return false;*p+=n;return true;}
static bool sxdn_bw4(sx_context*c){uint64_t p=31,n;uint8_t b[5];if(!SXDN_ADD(c,blindwrite4_header,0))return false;for(unsigned i=0;i<3;i++)if(!sxdn_bw4_string(c,&p))return true;if(!sxdn_word(c,p,4,false,&n)||!SXDN_ADD(c,blindwrite4_track_count,p)||n>256)return true;p+=4;for(unsigned i=0;i<2;i++)if(!sxdn_bw4_string(c,&p))return true;if(!sxdn_read(c,p,b,5)||!SXDN_ADD(c,blindwrite4_extra_prefix,p)||!sxdn_span(c,p+5,b[4]))return true;p+=5+b[4];for(uint64_t i=0;i<n&&c->count<SXDN_LIMIT;i++){if(!sxdn_bw4_string(c,&p)||!SXDN_ADD(c,blindwrite4_track,p))return true;p+=59;for(unsigned j=0;j<15;j++)if(!sxdn_bw4_string(c,&p))return true;}return true;}
static bool sxdn_bw56(sx_context*c){uint8_t d[112],lengths[20],b[64];uint64_t p=260;if(!sxdn_read(c,16,d,112)||!sxdn_read(c,240,lengths,20)||!SXDN_ADD(c,blindwrite56_signature,0)||!SXDN_ADD(c,blindwrite56_disc,16)||!SXDN_ADD(c,blindwrite56_inquiry,160)||!SXDN_ADD(c,blindwrite56_volume_name,208)||!SXDN_ADD(c,blindwrite56_lengths,240))return false;unsigned type=sxdn16(d+32,0),sessions=sxdn16(d+34,0);uint64_t skips[]={sxdn32(lengths,0),sxdn32(lengths+4,0),sxdn16(d+80,0),sxdn16(d+82,0),sxdn16(d+84,0),sxdn32(d+88,0),sxdn32(d+104,0),type>=8&&type<=10?sxdn16(d+86,0):sxdn32(d+108,0)};for(unsigned i=0;i<SX_COUNT(skips);i++){if(!sxdn_span(c,p,skips[i]))return true;p+=skips[i];}if(!sxdn_read(c,p,b,8)||!SXDN_ADD(c,blindwrite56_data_list,p))return true;uint64_t n=sxdn32(b,0),path=sxdn32(b+4,0);p+=8;if(n>65536||!sxdn_span(c,p,path))return true;p+=path;for(uint64_t i=0;i<n&&c->count<SXDN_LIMIT;i++){if(!sxdn_read(c,p,b,52)||!SXDN_ADD(c,blindwrite56_data_block,p))return true;uint64_t z=sxdn32(b+48,0);p+=52;if(!sxdn_span(c,p,z+4))return true;p+=z;if(!SXDN_ADD(c,blindwrite56_data_tail,p))return false;p+=4;}if(sessions>256)return true;for(unsigned i=0;i<sessions&&c->count<SXDN_LIMIT;i++){if(!sxdn_read(c,p,b,16)||!SXDN_ADD(c,blindwrite56_session,p))return true;n=b[2];p+=16;for(uint64_t j=0;j<n;j++){if(!sxdn_read(c,p,b,64)||!SXDN_ADD(c,blindwrite56_entry,p))return true;p+=64;if(b[0]>=1&&b[0]<=5){if(!SXDN_ADD(c,blindwrite56_cd_extra,p))return true;p+=8;}}}n=sxdn32(lengths+16,0);if(!sxdn_span(c,p,n+20))return true;p+=n;return SXDN_ADD(c,blindwrite56_footer,p);}
static bool sxdn_jvc_header(sx_context*c,uint64_t h){static const sx_layout*const a[]={&sxdn_jvc_header_1,&sxdn_jvc_header_2,&sxdn_jvc_header_3,&sxdn_jvc_header_4,&sxdn_jvc_header_5};return !h||sxdn_put(c,a[h>5?4:h-1],0,1);}
static bool sxdn_rsdos(sx_context*c){uint64_t h=(uint64_t)c->size%256,heads=1,declared_tracks=0;uint8_t b[12];if(h){if(!sxdn_read(c,0,b,h<12?h:12))return false;if(h>=12&&b[0]=='d'&&b[1]=='k'&&sxdn16(b+2,0)==h){heads=b[9];declared_tracks=b[8];if(!SXDN_ADD(c,rsdos_vdk_header,0))return false;}else{heads=h>1?b[1]:1;if(!sxdn_jvc_header(c,h))return false;}}if(heads<1||heads>2)return c->count!=0;uint64_t tracks=((uint64_t)c->size-h)/(heads*18*256),n=(declared_tracks?declared_tracks:tracks)>1?((declared_tracks?declared_tracks:tracks)-1)*2:0;if(n>255)n=255;if(n<68)n=68;uint64_t p=h+(17*heads*18+1)*256;if(!sxdn_span(c,p,256+72*32))return c->count!=0;return SXDN_TABLE(c,rsdos_granule,p,n)&&SXDN_TABLE(c,rsdos_directory_entry,p+256,72);}
static uint32_t sxdn24(const uint8_t*b){return (uint32_t)b[0]<<16|(uint32_t)b[1]<<8|b[2];}
static bool sxdn_os9(sx_context*c,uint64_t base){uint8_t b[256];if(!sxdn_read(c,base,b,256))return false;uint64_t total=sxdn24(b),root=sxdn24(b+8);if(!total||root>=total||!sxdn_span(c,base,total*256)||!SXDN_ADD(c,jvc_os9_disk_descriptor,base)||!SXDN_ADD(c,jvc_os9_path_options,base+63))return false;uint32_t queue[1024];size_t n=1;queue[0]=(uint32_t)root;for(size_t i=0;i<n&&c->count<SXDN_LIMIT;i++){uint64_t p=base+(uint64_t)queue[i]*256;if(!sxdn_read(c,p,b,256)||!SXDN_ADD(c,jvc_os9_file_descriptor,p))return false;unsigned segments=0;for(unsigned j=0;j<48;j++){uint64_t lsn=sxdn24(b+16+j*5),cnt=sxdn16(b+19+j*5,1);if(!lsn||!cnt)break;if(lsn>=total||cnt>total-lsn)break;segments++;}if(!SXDN_TABLE(c,jvc_os9_segment,p+16,segments))return false;if(!(b[0]&128))continue;uint64_t remaining=sxdn32(b+9,1);if(remaining>4*1024*1024)continue;for(unsigned j=0;j<segments&&remaining&&c->count<SXDN_LIMIT;j++){uint64_t lsn=sxdn24(b+16+j*5),cnt=sxdn16(b+19+j*5,1),bytes=cnt*256;if(bytes>remaining)bytes=remaining;uint64_t at=base+lsn*256;if(!SXDN_TABLE(c,jvc_os9_directory_entry,at,bytes/32))return false;for(uint64_t off=0;off+32<=bytes&&n<1024;off+=32){uint8_t e[32];if(!sxdn_read(c,at+off,e,32))return false;uint32_t fd=sxdn24(e+29);if(!e[0]||!fd||fd>=total)continue;bool seen=false;for(size_t k=0;k<n;k++)if(queue[k]==fd){seen=true;break;}if(!seen)queue[n++]=fd;}remaining-=bytes;}}return true;}
static bool sxdn_jvc(sx_context*c){uint64_t h=(uint64_t)c->size%256;if(h>5||!sxdn_jvc_header(c,h))return false;uint8_t b[256];uint64_t total,root;if(sxdn_read(c,h,b,256)&&(total=sxdn24(b))&&total<=((uint64_t)c->size-h)/256&&(root=sxdn24(b+8))&&root<total){uint8_t fd[16];if(sxdn_read(c,h+root*256,fd,16)&&(fd[0]&128))return sxdn_os9(c,h);}for(unsigned heads=1;heads<=2;heads++){uint64_t p=h+20*18*heads*256;if(!sxdn_read(c,p,b,256)||b[253]!=18*heads||(uint8_t)~b[252]!=b[254]||(uint8_t)~b[253]!=b[255]||!b[252])continue;if(!SXDN_ADD(c,dragon_dos_geometry,p+252))return false;for(unsigned s=2;s<18;s++){for(unsigned i=0;i<10;i++){uint64_t at=p+(uint64_t)s*256+i*25;uint8_t flag;if(!sxdn_read(c,at,&flag,1))return false;if(flag&8)return true;if(!sxdn_put(c,flag&1?&sxdn_dragon_dos_continuation:&sxdn_dragon_dos_file,at,1))return false;}}return true;}return c->count!=0;}
#define DN_PAIR(n,be) ((be)?&sxdn_##n##_be:&sxdn_##n##_le)
static bool sxdn_oldjffs(sx_context*c){uint8_t h[12];uint64_t end=(uint64_t)c->size;if(end>67108864)end=67108864;for(uint64_t p=0;p+12<=end&&c->count<SXDN_LIMIT;){if(!sxdn_read(c,p,h,12))return false;bool be=sxdn16(h,1)==0x1984;uint64_t n=sxdn32(h+4,be);if(sxdn16(h,be)!=0x1984||n<12||!sxdn_span(c,p,n)||sxdn32(h+8,be)!=(xx_crc32_calc(UINT32_MAX,h,8)^UINT32_MAX)){p+=4;continue;}const sx_layout*l=DN_PAIR(old_jffs2_common_header,be);unsigned z=12;switch(sxdn16(h+2,be)|0x2000){case 0xe001:l=DN_PAIR(old_jffs2_directory_entry,be);z=40;break;case 0xe002:l=DN_PAIR(old_jffs2_inode,be);z=68;break;case 0xe008:l=DN_PAIR(old_jffs2_xattr,be);z=32;break;case 0xe009:l=DN_PAIR(old_jffs2_xref,be);z=28;break;}if(z>n)l=DN_PAIR(old_jffs2_common_header,be);if(!sxdn_put(c,l,p,1))return false;p+=(n+3)&~UINT64_C(3);}return c->count!=0;}
static bool sxdn_sqlz_meta(sx_context*c,uint64_t p,uint64_t end,bool be,unsigned*budget){while(p<end&&*budget){uint8_t b[2];if(end-p<2||!sxdn_read(c,p,b,2))break;uint64_t n=sxdn16(b,be)&32767;if(!n||n>8192||n>end-p-2)break;if(!sxdn_put(c,DN_PAIR(sqlz_squashfs_metadata_header,be),p,1))return false;p+=2+n;(*budget)--;}return true;}
static bool sxdn_sqlz_index(sx_context*c,uint64_t p,uint64_t count,unsigned width,unsigned header,bool be,unsigned*budget){if(!count||count>4096||p<header||!sxdn_span(c,p,count*width))return true;if(!sxdn_put(c,width==4?DN_PAIR(sqlz_squashfs2_fragment_index,be):DN_PAIR(sqlz_squashfs_table_index,be),p,count))return false;for(uint64_t i=0;i<count&&*budget;i++){uint64_t at;if(!sxdn_word(c,p+i*width,width,be,&at))return false;if(at>=header&&at<p&&!sxdn_sqlz_meta(c,at,p,be,budget))return false;}return true;}
static bool sxdn_sqlz(sx_context*c){uint8_t h[119];if(!sxdn_read(c,0,h,63))return false;bool be=!xx_rt_memcmp(h,"sqlz",4);if(!be&&xx_rt_memcmp(h,"zlqs",4))return false;unsigned v=sxdn16(h+28,be),header=v==2?63:119;if(v!=2&&v!=3)return false;if(v==3&&!sxdn_read(c,0,h,119))return false;if(!sxdn_put(c,v==2?DN_PAIR(sqlz_squashfs2_superblock,be):DN_PAIR(sqlz_squashfs3_superblock,be),0,1))return false;uint64_t size,inode,dir,frag,lookup=UINT64_MAX,uid,gid;if(v==2){size=sxdn32(h+8,be);uid=sxdn32(h+12,be);gid=sxdn32(h+16,be);inode=sxdn32(h+20,be);dir=sxdn32(h+24,be);frag=sxdn32(h+59,be);}else{size=xx_data_get_u64(h,119,63,be);uid=xx_data_get_u64(h,119,71,be);gid=xx_data_get_u64(h,119,79,be);inode=xx_data_get_u64(h,119,87,be);dir=xx_data_get_u64(h,119,95,be);frag=xx_data_get_u64(h,119,103,be);lookup=xx_data_get_u64(h,119,111,be);}if(size<header||size>(uint64_t)c->size)size=(uint64_t)c->size;unsigned budget=4096;uint64_t fragments=sxdn32(h+55,be),ninode=sxdn32(h+4,be);if(!sxdn_sqlz_index(c,frag,(fragments*(v==2?8:16)+8191)/8192,v==2?4:8,header,be,&budget))return false;if(v==3&&!sxdn_sqlz_index(c,lookup,(ninode*8+8191)/8192,8,header,be,&budget))return false;uint64_t starts[]={uid,gid};for(unsigned i=0;i<2;i++)if(h[37+i]&&starts[i]>=header&&sxdn_span(c,starts[i],(uint64_t)h[37+i]*4)&&!sxdn_put(c,DN_PAIR(sqlz_squashfs_identity,be),starts[i],h[37+i]))return false;if(inode>=header&&inode<dir&&dir<=size&&!sxdn_sqlz_meta(c,inode,dir,be,&budget))return false;if(dir>=header&&dir<size){uint64_t end=size,refs[]={frag,lookup,uid,gid};for(unsigned i=0;i<4;i++)if(refs[i]>dir&&refs[i]<end)end=refs[i];if(!sxdn_sqlz_meta(c,dir,end,be,&budget))return false;}return true;}
/* Read text once, bounded by the native descriptor cap. Each scalar retains
 * its original byte span; whitespace, delimiters and encoded payload stay raw. */
typedef struct sxdn_text {sx_context*c;uint8_t*b;size_t n;} sxdn_text;
static bool sxdn_blank(uint8_t b){return b==' '||b=='\t'||b=='\r';}
static bool sxdn_eq(const uint8_t*b,size_t n,const char*s){size_t k=xx_rt_strlen(s);if(n!=k)return false;for(size_t i=0;i<n;i++){uint8_t a=b[i],c=(uint8_t)s[i];if(a>='a'&&a<='z')a-=32;if(c>='a'&&c<='z')c-=32;if(a!=c)return false;}return true;}
static bool sxdn_text_value(sxdn_text*t,const sx_layout*l,size_t a,size_t z){while(a<z&&sxdn_blank(t->b[a]))a++;while(z>a&&sxdn_blank(t->b[z-1]))z--;const xx_data_struct_field_desc*last=l->fields+l->field_count-1;
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
static bool sxdn_text_load(sx_context*c,unsigned kind){if(c->size<=0||c->size>8*1024*1024)return false;uint8_t*b=xx_mem_alloc((size_t)c->size);if(!b)return false;bool ok=sxdn_read(c,0,b,(size_t)c->size);sxdn_text t={c,b,(size_t)c->size};if(ok)ok=kind<3?sxdn_text_sheet(&t,kind):sxdn_text_ini(&t,kind==3?0:1);xx_mem_free(b);return ok&&c->count!=0;}
static bool sxdn_svd(sx_context*c){uint8_t b[512];size_t n=(uint64_t)c->size<sizeof(b)?(size_t)c->size:sizeof(b);if(!sxdn_read(c,0,b,n))return false;sxdn_text t={c,b,n};static const sx_layout*const fields[]={&sxdn_svd_version,&sxdn_svd_sectors,&sxdn_svd_cylinders,&sxdn_svd_sides,&sxdn_svd_sector_size_code,&sxdn_svd_write_protect};size_t p=0;unsigned count=b[0]=='2'?6:3;for(unsigned i=0;i<count;i++){size_t a=p;while(p<n&&b[p]!='\n')p++;if(p==n)return c->count!=0;if(!sxdn_text_value(&t,fields[i],a,p))return false;p++;}return true;}
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
case XX_FILE_TYPE_EMT:ok=SXDN_ADD(c,emt_header,0);break;
case XX_FILE_TYPE_CUE:ok=sxdn_text_load(c,0);break;case XX_FILE_TYPE_CDRDAO_TOC:ok=sxdn_text_load(c,1);break;case XX_FILE_TYPE_GDI:ok=sxdn_text_load(c,2);break;case XX_FILE_TYPE_CCD:ok=sxdn_text_load(c,3);break;case XX_FILE_TYPE_LDBST:ok=sxdn_text_load(c,4);break;
case XX_FILE_TYPE_MSX_CAS:ok=sxdn_msx(c);break;case XX_FILE_TYPE_DRAGON_CAS:ok=sxdn_dragon(c);break;case XX_FILE_TYPE_ZX_HOBETA:ok=sxdn_hobeta(c);break;
case XX_FILE_TYPE_BLINDWRITE4:ok=sxdn_bw4(c);break;case XX_FILE_TYPE_BLINDWRITE_5_6_IMAGE:ok=sxdn_bw56(c);break;case XX_FILE_TYPE_CFD:ok=sxdn_cfd(c);break;case XX_FILE_TYPE_DCP_DISK:ok=sxdn_dcp(c);break;case XX_FILE_TYPE_ECM:ok=sxdn_ecm(c);break;case XX_FILE_TYPE_SVD:ok=sxdn_svd(c);break;case XX_FILE_TYPE_KRYOFLUX_STREAM:ok=sxdn_kryo(c);break;case XX_FILE_TYPE_FDCOPY_CFI:ok=sxdn_cfi(c);break;case XX_FILE_TYPE_SNATCHIT_CP2:ok=sxdn_cp2(c);break;case XX_FILE_TYPE_SIMH_DISK:ok=sxdn_simh(c);break;case XX_FILE_TYPE_RSDOS_FS:ok=sxdn_rsdos(c);break;case XX_FILE_TYPE_JVC:ok=sxdn_jvc(c);break;case XX_FILE_TYPE_JFFS2_OLD:ok=sxdn_oldjffs(c);break;case XX_FILE_TYPE_SQUASHFS_SQLZ:ok=sxdn_sqlz(c);break;
#if SX_ALIAS_READER_FACTORY
case XX_FILE_TYPE_PSA_DISK:return sxdn_psa(c);
#endif
default:return false;}return ok&&c->count&&sxdn_finish(c);}
#undef DN_PAIR
#undef SXDN_ADD
#undef SXDN_TABLE
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
