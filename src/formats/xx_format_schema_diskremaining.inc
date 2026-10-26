/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical legacy disk image metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_diskremaining_scope.txt. */

static const xx_data_struct_field_desc sxdr_sydex_wb_header_fields[] = {
    SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("last_page_bytes","uint16",2,2,SX_SIZE),
    SX_FIELD("page_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("decoded_text_bytes","uint16",6,2,SX_SIZE),
};
static const sx_layout sxdr_sydex_wb_header = {0x607f0001U,"sydex_wb_header",sxdr_sydex_wb_header_fields,SX_COUNT(sxdr_sydex_wb_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_sydex_image_header_fields[] = {
    SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("track_bytes","uint16",3,2,SX_SIZE),
    SX_FIELD("sectors_per_track","uint8",5,1,SX_COUNT_PROP),
    SX_FIELD("heads","uint8",6,1,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint8",7,1,SX_COUNT_PROP),
    SX_FIELD("stored_cylinders","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("unknown_09","byte[6]",9,6,SX_NONE),
    SX_FIELD("encryption","int16",15,2,SX_NONE),
    SX_FIELD("unknown_11","byte[2]",17,2,SX_NONE),
    SX_FIELD("description_bytes","int16",19,2,SX_SIZE),
    SX_FIELD("description_crc16","uint16",21,2,SX_CHECKSUM),
    SX_FIELD("serial_marker","char[4]",23,4,SX_SIGNATURE),
    SX_FIELD("serial_number","uint32",27,4,SX_ID),
    SX_FIELD("header_crc16","uint16",31,2,SX_CHECKSUM),
};
static const sx_layout sxdr_sydex_image_header = {0x607f0002U,"sydex_image_header",sxdr_sydex_image_header_fields,SX_COUNT(sxdr_sydex_image_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_sydex_track_header_fields[] = {
    SX_FIELD("decoded_crc16","uint16",0,2,SX_CHECKSUM),
    SX_FIELD("signed_packed_length","int16",2,2,SX_NONE),
};
static const sx_layout sxdr_sydex_track_header = {0x607f0003U,"sydex_track_header",sxdr_sydex_track_header_fields,SX_COUNT(sxdr_sydex_track_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_trs80_boot_directory_fields[] = {
    SX_FIELD("directory_track_flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxdr_trs80_boot_directory = {0x607f0004U,"trs80_boot_directory",sxdr_trs80_boot_directory_fields,SX_COUNT(sxdr_trs80_boot_directory_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_trs80_gat_track_fields[] = {
    SX_FIELD("allocated_granules","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxdr_trs80_gat_track = {0x607f0005U,"trs80_gat_track",sxdr_trs80_gat_track_fields,SX_COUNT(sxdr_trs80_gat_track_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_trs80_gat_identity_fields[] = {
    SX_FIELD("disk_name","char[8]",0,8,SX_NONE),
    SX_FIELD("date_text","char[8]",8,8,SX_NONE),
    SX_FIELD("auto_command","char[32]",16,32,SX_NONE),
};
static const sx_layout sxdr_trs80_gat_identity = {0x607f0006U,"trs80_gat_identity",sxdr_trs80_gat_identity_fields,SX_COUNT(sxdr_trs80_gat_identity_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_trs80_hit_fields[] = {
    SX_FIELD("filename_hash","uint8",0,1,SX_CHECKSUM),
};
static const sx_layout sxdr_trs80_hit = {0x607f0007U,"trs80_hit",sxdr_trs80_hit_fields,SX_COUNT(sxdr_trs80_hit_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_trs80_primary_entry_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("month_flags","uint8",1,1,SX_FLAGS),
    SX_FIELD("day_year_flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("last_sector_bytes","uint8",3,1,SX_NONE),
    SX_FIELD("logical_record_length","uint8",4,1,SX_NONE),
    SX_FIELD("name","char[8]",5,8,SX_NONE),
    SX_FIELD("extension","char[3]",13,3,SX_NONE),
    SX_FIELD("update_password_hash","uint16",16,2,SX_CHECKSUM),
    SX_FIELD("access_password_hash","uint16",18,2,SX_CHECKSUM),
    SX_FIELD("allocated_sectors","uint16",20,2,SX_COUNT_PROP),
};
static const sx_layout sxdr_trs80_primary_entry = {0x607f0008U,"trs80_primary_entry",sxdr_trs80_primary_entry_fields,SX_COUNT(sxdr_trs80_primary_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_trs80_extended_entry_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("previous_entry_code","uint8",1,1,SX_ID),
    SX_FIELD("day_year_flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("last_sector_bytes","uint8",3,1,SX_NONE),
    SX_FIELD("logical_record_length","uint8",4,1,SX_NONE),
    SX_FIELD("name","char[8]",5,8,SX_NONE),
    SX_FIELD("extension","char[3]",13,3,SX_NONE),
    SX_FIELD("update_password_hash","uint16",16,2,SX_CHECKSUM),
    SX_FIELD("access_password_hash","uint16",18,2,SX_CHECKSUM),
    SX_FIELD("allocated_sectors","uint16",20,2,SX_COUNT_PROP),
};
static const sx_layout sxdr_trs80_extended_entry = {0x607f0009U,"trs80_extended_entry",sxdr_trs80_extended_entry_fields,SX_COUNT(sxdr_trs80_extended_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_trs80_extent_fields[] = {
    SX_FIELD("start_track","uint8",0,1,SX_NONE),
    SX_FIELD("granule_start_count","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxdr_trs80_extent = {0x607f000aU,"trs80_extent",sxdr_trs80_extent_fields,SX_COUNT(sxdr_trs80_extent_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_trs80_extent_link_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_ID),
    SX_FIELD("next_entry_code","uint8",1,1,SX_ID),
};
static const sx_layout sxdr_trs80_extent_link = {0x607f000bU,"trs80_extent_link",sxdr_trs80_extent_link_fields,SX_COUNT(sxdr_trs80_extent_link_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_savage_header_fields[] = {
    SX_FIELD("header_size_minus_two","uint8",0,1,SX_NONE),
    SX_FIELD("unknown_01","uint8",1,1,SX_NONE),
    SX_FIELD("method","char[5]",2,5,SX_SIGNATURE),
    SX_FIELD("packed_bytes","uint32",7,4,SX_SIZE),
    SX_FIELD("disk_bytes","uint32",11,4,SX_SIZE),
    SX_FIELD("unknown_0f","byte[14]",15,14,SX_NONE),
    SX_FIELD("disk_crc16","uint16",29,2,SX_CHECKSUM),
};
static const sx_layout sxdr_savage_header = {0x607f000cU,"savage_header",sxdr_savage_header_fields,SX_COUNT(sxdr_savage_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_vtr_header_fields[] = {
    SX_FIELD("magic","char[7]",0,7,SX_SIGNATURE),
    SX_FIELD("write_protected","uint8",7,1,SX_FLAGS),
    SX_FIELD("rpm","uint16",8,2,SX_NONE),
    SX_FIELD("cylinders","uint8",10,1,SX_COUNT_PROP),
    SX_FIELD("interface_mode","uint8",11,1,SX_ID),
    SX_FIELD("heads","uint8",12,1,SX_COUNT_PROP),
    SX_FIELD("track_encoding","uint8",13,1,SX_ID),
    SX_FIELD("bitrate_kbps","uint16",14,2,SX_NONE),
    SX_FIELD("track_list_block","uint16",16,2,SX_NONE),
    SX_FIELD("revision","uint8",18,1,SX_ID),
    SX_FIELD("reserved1","byte[100]",19,100,SX_RESERVED),
    SX_FIELD("input_filename","char[128]",119,128,SX_NONE),
    SX_FIELD("reserved2","byte[50]",247,50,SX_RESERVED),
    SX_FIELD("credits","char[73]",297,73,SX_NONE),
};
static const sx_layout sxdr_vtr_header = {0x607f000dU,"vtr_header",sxdr_vtr_header_fields,SX_COUNT(sxdr_vtr_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_vtr_track_entry_fields[] = {
    SX_FIELD("track_block","uint16",0,2,SX_NONE),
    SX_FIELD("combined_track_bytes","uint16",2,2,SX_SIZE),
};
static const sx_layout sxdr_vtr_track_entry = {0x607f000eU,"vtr_track_entry",sxdr_vtr_track_entry_fields,SX_COUNT(sxdr_vtr_track_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_pc99_id_fm_fields[] = {
    SX_FIELD("address_mark","uint8",0,1,SX_ID),
    SX_FIELD("cylinder","uint8",1,1,SX_NONE),
    SX_FIELD("head","uint8",2,1,SX_NONE),
    SX_FIELD("sector","uint8",3,1,SX_NONE),
    SX_FIELD("size_code","uint8",4,1,SX_NONE),
    SX_FIELD("crc16_or_token","uint16be",5,2,SX_CHECKSUM),
};
static const sx_layout sxdr_pc99_id_fm = {0x607f000fU,"pc99_id_fm",sxdr_pc99_id_fm_fields,SX_COUNT(sxdr_pc99_id_fm_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_pc99_id_mfm_fields[] = {
    SX_FIELD("sync","byte[3]",0,3,SX_SIGNATURE),
    SX_FIELD("address_mark","uint8",3,1,SX_ID),
    SX_FIELD("cylinder","uint8",4,1,SX_NONE),
    SX_FIELD("head","uint8",5,1,SX_NONE),
    SX_FIELD("sector","uint8",6,1,SX_NONE),
    SX_FIELD("size_code","uint8",7,1,SX_NONE),
    SX_FIELD("crc16_or_token","uint16be",8,2,SX_CHECKSUM),
};
static const sx_layout sxdr_pc99_id_mfm = {0x607f0010U,"pc99_id_mfm",sxdr_pc99_id_mfm_fields,SX_COUNT(sxdr_pc99_id_mfm_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_pc99_data_fm_fields[] = {
    SX_FIELD("data_mark","uint8",0,1,SX_ID),
};
static const sx_layout sxdr_pc99_data_fm = {0x607f0011U,"pc99_data_fm",sxdr_pc99_data_fm_fields,SX_COUNT(sxdr_pc99_data_fm_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_pc99_data_mfm_fields[] = {
    SX_FIELD("sync","byte[3]",0,3,SX_SIGNATURE),
    SX_FIELD("data_mark","uint8",3,1,SX_ID),
};
static const sx_layout sxdr_pc99_data_mfm = {0x607f0012U,"pc99_data_mfm",sxdr_pc99_data_mfm_fields,SX_COUNT(sxdr_pc99_data_mfm_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_pc99_data_crc_fields[] = {
    SX_FIELD("crc16_or_token","uint16be",0,2,SX_CHECKSUM),
};
static const sx_layout sxdr_pc99_data_crc = {0x607f0013U,"pc99_data_crc",sxdr_pc99_data_crc_fields,SX_COUNT(sxdr_pc99_data_crc_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_apple_gcr_address_fields[] = {
    SX_FIELD("prologue","byte[3]",0,3,SX_SIGNATURE),
    SX_FIELD("volume_4and4","byte[2]",3,2,SX_NONE),
    SX_FIELD("track_4and4","byte[2]",5,2,SX_NONE),
    SX_FIELD("sector_4and4","byte[2]",7,2,SX_NONE),
    SX_FIELD("xor_checksum_4and4","byte[2]",9,2,SX_CHECKSUM),
    SX_FIELD("epilogue","byte[3]",11,3,SX_SIGNATURE),
};
static const sx_layout sxdr_apple_gcr_address = {0x607f0014U,"apple_gcr_address",sxdr_apple_gcr_address_fields,SX_COUNT(sxdr_apple_gcr_address_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_apple_gcr_data_prefix_fields[] = {
    SX_FIELD("prologue","byte[3]",0,3,SX_SIGNATURE),
};
static const sx_layout sxdr_apple_gcr_data_prefix = {0x607f0015U,"apple_gcr_data_prefix",sxdr_apple_gcr_data_prefix_fields,SX_COUNT(sxdr_apple_gcr_data_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_apple_gcr_data_suffix_fields[] = {
    SX_FIELD("translated_xor_checksum","uint8",0,1,SX_CHECKSUM),
    SX_FIELD("epilogue","byte[3]",1,3,SX_SIGNATURE),
};
static const sx_layout sxdr_apple_gcr_data_suffix = {0x607f0016U,"apple_gcr_data_suffix",sxdr_apple_gcr_data_suffix_fields,SX_COUNT(sxdr_apple_gcr_data_suffix_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_gutenberg_link_fields[] = {
    SX_FIELD("previous_track_flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("previous_sector_flags","uint8",1,1,SX_FLAGS),
    SX_FIELD("current_track_flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("current_sector_flags","uint8",3,1,SX_FLAGS),
    SX_FIELD("next_track_flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("next_sector_flags","uint8",5,1,SX_FLAGS),
};
static const sx_layout sxdr_gutenberg_link = {0x607f0017U,"gutenberg_link",sxdr_gutenberg_link_fields,SX_COUNT(sxdr_gutenberg_link_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_gutenberg_volume_fields[] = {
    SX_FIELD("volume_name_high_ascii","byte[9]",0,9,SX_NONE),
    SX_FIELD("carriage_return","uint8",9,1,SX_ID),
};
static const sx_layout sxdr_gutenberg_volume = {0x607f0018U,"gutenberg_volume",sxdr_gutenberg_volume_fields,SX_COUNT(sxdr_gutenberg_volume_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_gutenberg_entry_fields[] = {
    SX_FIELD("name_high_ascii","byte[12]",0,12,SX_NONE),
    SX_FIELD("first_track_flags","uint8",12,1,SX_FLAGS),
    SX_FIELD("first_sector_flags","uint8",13,1,SX_FLAGS),
    SX_FIELD("type_high_ascii","uint8",14,1,SX_ID),
    SX_FIELD("carriage_return","uint8",15,1,SX_ID),
};
static const sx_layout sxdr_gutenberg_entry = {0x607f0019U,"gutenberg_entry",sxdr_gutenberg_entry_fields,SX_COUNT(sxdr_gutenberg_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_cassette_riff_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("riff_bytes","uint32",4,4,SX_SIZE),
    SX_FIELD("form_type","char[4]",8,4,SX_ID),
};
static const sx_layout sxdr_cassette_riff = {0x607f001aU,"cassette_riff",sxdr_cassette_riff_fields,SX_COUNT(sxdr_cassette_riff_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_cassette_chunk_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("data_bytes","uint32",4,4,SX_SIZE),
};
static const sx_layout sxdr_cassette_chunk = {0x607f001bU,"cassette_chunk",sxdr_cassette_chunk_fields,SX_COUNT(sxdr_cassette_chunk_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_cassette_pcm_format_fields[] = {
    SX_FIELD("format_tag","uint16",0,2,SX_ID),
    SX_FIELD("channels","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("sample_rate","uint32",4,4,SX_NONE),
    SX_FIELD("byte_rate","uint32",8,4,SX_NONE),
    SX_FIELD("block_alignment","uint16",12,2,SX_SIZE),
    SX_FIELD("bits_per_sample","uint16",14,2,SX_NONE),
};
static const sx_layout sxdr_cassette_pcm_format = {0x607f001cU,"cassette_pcm_format",sxdr_cassette_pcm_format_fields,SX_COUNT(sxdr_cassette_pcm_format_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_xbox_fatx_header_le_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("volume_id","uint32",4,4,SX_ID),
    SX_FIELD("sectors_per_cluster","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("root_cluster","uint32",12,4,SX_NONE),
};
static const sx_layout sxdr_xbox_fatx_header_le = {0x607f001dU,"xbox_fatx_header_le",sxdr_xbox_fatx_header_le_fields,SX_COUNT(sxdr_xbox_fatx_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_xbox_fatx_header_be_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("volume_id","uint32",4,4,SX_ID),
    SX_FIELD("sectors_per_cluster","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("root_cluster","uint32",12,4,SX_NONE),
};
static const sx_layout sxdr_xbox_fatx_header_be = {0x607f001eU,"xbox_fatx_header_be",sxdr_xbox_fatx_header_be_fields,SX_COUNT(sxdr_xbox_fatx_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxdr_plist_tag_fields[] = {
    SX_FIELD("tag","utf8",0,0,SX_NONE),
};
static const sx_layout sxdr_plist_tag = {0x607f001fU,"plist_tag",sxdr_plist_tag_fields,SX_COUNT(sxdr_plist_tag_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_plist_key_fields[] = {
    SX_FIELD("key","utf8",0,0,SX_NONE),
};
static const sx_layout sxdr_plist_key = {0x607f0020U,"plist_key",sxdr_plist_key_fields,SX_COUNT(sxdr_plist_key_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_plist_string_fields[] = {
    SX_FIELD("value","utf8",0,0,SX_NONE),
};
static const sx_layout sxdr_plist_string = {0x607f0021U,"plist_string",sxdr_plist_string_fields,SX_COUNT(sxdr_plist_string_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_plist_integer_fields[] = {
    SX_FIELD("value","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdr_plist_integer = {0x607f0022U,"plist_integer",sxdr_plist_integer_fields,SX_COUNT(sxdr_plist_integer_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_plist_disk_size_fields[] = {
    SX_FIELD("disk_size","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxdr_plist_disk_size = {0x607f0023U,"plist_disk_size",sxdr_plist_disk_size_fields,SX_COUNT(sxdr_plist_disk_size_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_plist_band_size_fields[] = {
    SX_FIELD("band_size","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxdr_plist_band_size = {0x607f0024U,"plist_band_size",sxdr_plist_band_size_fields,SX_COUNT(sxdr_plist_band_size_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_plist_bundle_version_fields[] = {
    SX_FIELD("bundle_version","ascii_signed",0,0,SX_ID),
};
static const sx_layout sxdr_plist_bundle_version = {0x607f0025U,"plist_bundle_version",sxdr_plist_bundle_version_fields,SX_COUNT(sxdr_plist_bundle_version_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_trs80_gat_lockout_fields[] = {
    SX_FIELD("lockout_flags","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxdr_trs80_gat_lockout = {0x607f0026U,"trs80_gat_lockout",sxdr_trs80_gat_lockout_fields,SX_COUNT(sxdr_trs80_gat_lockout_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_trs80_gat_system_fields[] = {
    SX_FIELD("os_version","uint8",0,1,SX_ID),
    SX_FIELD("cylinders_minus_35","uint8",1,1,SX_NONE),
    SX_FIELD("geometry_flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("master_password_hash","uint16",3,2,SX_CHECKSUM),
};
static const sx_layout sxdr_trs80_gat_system = {0x607f0027U,"trs80_gat_system",sxdr_trs80_gat_system_fields,SX_COUNT(sxdr_trs80_gat_system_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_sydex_description_fields[] = {
    SX_FIELD("description","utf8",0,0,SX_NONE),
};
static const sx_layout sxdr_sydex_description = {0x607f0028U,"sydex_description",sxdr_sydex_description_fields,SX_COUNT(sxdr_sydex_description_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_fei_id_phase0_fields[] = {
    SX_FIELD("sync_bitcells","byte[6]",0,6,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[2]",6,2,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[2]",8,2,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[2]",10,2,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[2]",12,2,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[2]",14,2,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[2]",16,2,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[2]",18,2,SX_CHECKSUM),
};
static const sx_layout sxdr_fei_id_phase0 = {0x607f0029U,"fei_id_phase0",sxdr_fei_id_phase0_fields,SX_COUNT(sxdr_fei_id_phase0_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_fei_id_phase1_fields[] = {
    SX_FIELD("sync_bitcells","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[3]",6,3,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[3]",8,3,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[3]",10,3,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[3]",12,3,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[3]",14,3,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[3]",16,3,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[3]",18,3,SX_CHECKSUM),
};
static const sx_layout sxdr_fei_id_phase1 = {0x607f002aU,"fei_id_phase1",sxdr_fei_id_phase1_fields,SX_COUNT(sxdr_fei_id_phase1_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_fei_id_phase2_fields[] = {
    SX_FIELD("sync_bitcells","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[3]",6,3,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[3]",8,3,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[3]",10,3,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[3]",12,3,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[3]",14,3,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[3]",16,3,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[3]",18,3,SX_CHECKSUM),
};
static const sx_layout sxdr_fei_id_phase2 = {0x607f002bU,"fei_id_phase2",sxdr_fei_id_phase2_fields,SX_COUNT(sxdr_fei_id_phase2_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_fei_id_phase3_fields[] = {
    SX_FIELD("sync_bitcells","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[3]",6,3,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[3]",8,3,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[3]",10,3,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[3]",12,3,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[3]",14,3,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[3]",16,3,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[3]",18,3,SX_CHECKSUM),
};
static const sx_layout sxdr_fei_id_phase3 = {0x607f002cU,"fei_id_phase3",sxdr_fei_id_phase3_fields,SX_COUNT(sxdr_fei_id_phase3_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_fei_id_phase4_fields[] = {
    SX_FIELD("sync_bitcells","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[3]",6,3,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[3]",8,3,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[3]",10,3,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[3]",12,3,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[3]",14,3,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[3]",16,3,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[3]",18,3,SX_CHECKSUM),
};
static const sx_layout sxdr_fei_id_phase4 = {0x607f002dU,"fei_id_phase4",sxdr_fei_id_phase4_fields,SX_COUNT(sxdr_fei_id_phase4_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_fei_id_phase5_fields[] = {
    SX_FIELD("sync_bitcells","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[3]",6,3,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[3]",8,3,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[3]",10,3,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[3]",12,3,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[3]",14,3,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[3]",16,3,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[3]",18,3,SX_CHECKSUM),
};
static const sx_layout sxdr_fei_id_phase5 = {0x607f002eU,"fei_id_phase5",sxdr_fei_id_phase5_fields,SX_COUNT(sxdr_fei_id_phase5_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_fei_id_phase6_fields[] = {
    SX_FIELD("sync_bitcells","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[3]",6,3,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[3]",8,3,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[3]",10,3,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[3]",12,3,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[3]",14,3,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[3]",16,3,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[3]",18,3,SX_CHECKSUM),
};
static const sx_layout sxdr_fei_id_phase6 = {0x607f002fU,"fei_id_phase6",sxdr_fei_id_phase6_fields,SX_COUNT(sxdr_fei_id_phase6_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_fei_id_phase7_fields[] = {
    SX_FIELD("sync_bitcells","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[3]",6,3,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[3]",8,3,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[3]",10,3,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[3]",12,3,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[3]",14,3,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[3]",16,3,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[3]",18,3,SX_CHECKSUM),
};
static const sx_layout sxdr_fei_id_phase7 = {0x607f0030U,"fei_id_phase7",sxdr_fei_id_phase7_fields,SX_COUNT(sxdr_fei_id_phase7_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_ddd_initial_dictionary_fields[] = {
    SX_FIELD("dos_lead","byte[4]",0,4,SX_NONE),
    SX_FIELD("reserved_prefix","msb_bits[0,3]",4,1,SX_RESERVED),
    SX_FIELD("volume_reversed_bits","msb_bits[3,8]",4,2,SX_NONE),
    SX_FIELD("favorite_0_reversed_bits","msb_bits[3,8]",5,2,SX_NONE),
    SX_FIELD("favorite_1_reversed_bits","msb_bits[3,8]",6,2,SX_NONE),
    SX_FIELD("favorite_2_reversed_bits","msb_bits[3,8]",7,2,SX_NONE),
    SX_FIELD("favorite_3_reversed_bits","msb_bits[3,8]",8,2,SX_NONE),
    SX_FIELD("favorite_4_reversed_bits","msb_bits[3,8]",9,2,SX_NONE),
    SX_FIELD("favorite_5_reversed_bits","msb_bits[3,8]",10,2,SX_NONE),
    SX_FIELD("favorite_6_reversed_bits","msb_bits[3,8]",11,2,SX_NONE),
    SX_FIELD("favorite_7_reversed_bits","msb_bits[3,8]",12,2,SX_NONE),
    SX_FIELD("favorite_8_reversed_bits","msb_bits[3,8]",13,2,SX_NONE),
    SX_FIELD("favorite_9_reversed_bits","msb_bits[3,8]",14,2,SX_NONE),
    SX_FIELD("favorite_10_reversed_bits","msb_bits[3,8]",15,2,SX_NONE),
    SX_FIELD("favorite_11_reversed_bits","msb_bits[3,8]",16,2,SX_NONE),
    SX_FIELD("favorite_12_reversed_bits","msb_bits[3,8]",17,2,SX_NONE),
    SX_FIELD("favorite_13_reversed_bits","msb_bits[3,8]",18,2,SX_NONE),
    SX_FIELD("favorite_14_reversed_bits","msb_bits[3,8]",19,2,SX_NONE),
    SX_FIELD("favorite_15_reversed_bits","msb_bits[3,8]",20,2,SX_NONE),
    SX_FIELD("favorite_16_reversed_bits","msb_bits[3,8]",21,2,SX_NONE),
    SX_FIELD("favorite_17_reversed_bits","msb_bits[3,8]",22,2,SX_NONE),
    SX_FIELD("favorite_18_reversed_bits","msb_bits[3,8]",23,2,SX_NONE),
    SX_FIELD("favorite_19_reversed_bits","msb_bits[3,8]",24,2,SX_NONE),
};
static const sx_layout sxdr_ddd_initial_dictionary = {0x607f0031U,"ddd_initial_dictionary",sxdr_ddd_initial_dictionary_fields,SX_COUNT(sxdr_ddd_initial_dictionary_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_speccydos_boot_header_fields[] = {
    SX_FIELD("magic","char[5]",0,5,SX_SIGNATURE),
    SX_FIELD("unknown_05","byte[8]",5,8,SX_NONE),
    SX_FIELD("density","uint8",13,1,SX_ID),
    SX_FIELD("cylinders_and_sides","uint8",14,1,SX_FLAGS),
    SX_FIELD("sectors_per_track","uint8",15,1,SX_COUNT_PROP),
};
static const sx_layout sxdr_speccydos_boot_header = {0x607f0032U,"speccydos_boot_header",sxdr_speccydos_boot_header_fields,SX_COUNT(sxdr_speccydos_boot_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_cassette_pcm_extension_fields[] = {
    SX_FIELD("extension_bytes","uint16",0,2,SX_SIZE),
};
static const sx_layout sxdr_cassette_pcm_extension = {0x607f0033U,"cassette_pcm_extension",sxdr_cassette_pcm_extension_fields,SX_COUNT(sxdr_cassette_pcm_extension_fields),SX_LE};

static const xx_data_struct_field_desc sxdr_xbox_fatx_name_le_fields[] = {
    SX_FIELD("partition_name_utf16","uint16[32]",0,64,SX_NONE),
};
static const sx_layout sxdr_xbox_fatx_name_le = {0x607f0034U,"xbox_fatx_name_le",sxdr_xbox_fatx_name_le_fields,SX_COUNT(sxdr_xbox_fatx_name_le_fields),SX_LE};

static const sx_layout *const sx_diskremaining_layouts[] = {
    &sxdr_sydex_wb_header,
    &sxdr_sydex_image_header,
    &sxdr_sydex_track_header,
    &sxdr_trs80_boot_directory,
    &sxdr_trs80_gat_track,
    &sxdr_trs80_gat_identity,
    &sxdr_trs80_hit,
    &sxdr_trs80_primary_entry,
    &sxdr_trs80_extended_entry,
    &sxdr_trs80_extent,
    &sxdr_trs80_extent_link,
    &sxdr_savage_header,
    &sxdr_vtr_header,
    &sxdr_vtr_track_entry,
    &sxdr_pc99_id_fm,
    &sxdr_pc99_id_mfm,
    &sxdr_pc99_data_fm,
    &sxdr_pc99_data_mfm,
    &sxdr_pc99_data_crc,
    &sxdr_apple_gcr_address,
    &sxdr_apple_gcr_data_prefix,
    &sxdr_apple_gcr_data_suffix,
    &sxdr_gutenberg_link,
    &sxdr_gutenberg_volume,
    &sxdr_gutenberg_entry,
    &sxdr_cassette_riff,
    &sxdr_cassette_chunk,
    &sxdr_cassette_pcm_format,
    &sxdr_xbox_fatx_header_le,
    &sxdr_xbox_fatx_header_be,
    &sxdr_plist_tag,
    &sxdr_plist_key,
    &sxdr_plist_string,
    &sxdr_plist_integer,
    &sxdr_plist_disk_size,
    &sxdr_plist_band_size,
    &sxdr_plist_bundle_version,
    &sxdr_trs80_gat_lockout,
    &sxdr_trs80_gat_system,
    &sxdr_sydex_description,
    &sxdr_fei_id_phase0,
    &sxdr_fei_id_phase1,
    &sxdr_fei_id_phase2,
    &sxdr_fei_id_phase3,
    &sxdr_fei_id_phase4,
    &sxdr_fei_id_phase5,
    &sxdr_fei_id_phase6,
    &sxdr_fei_id_phase7,
    &sxdr_ddd_initial_dictionary,
    &sxdr_speccydos_boot_header,
    &sxdr_cassette_pcm_extension,
    &sxdr_xbox_fatx_name_le,
};

static bool sx_diskremaining_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x607f0000U||id>=0x60800000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    switch(id){
    case 0x607f0001U:
        if(!xx_rt_wcscmp(r->name,L"last_page_bytes"))s=L"Bytes used in the final512-byte page; zero denotes a full page";
        else if(!xx_rt_wcscmp(r->name,L"page_count"))s=L"512-byte pages; the size includes this stage header";
        break;
    case 0x607f0002U:
        if(!xx_rt_wcscmp(r->name,L"encryption"))s=L"Native reader requires zero; nonzero denotes encrypted image";
        else if(!xx_rt_wcscmp(r->name,L"description_bytes"))s=L"Nonnegative byte length immediately after the header";
        else if(!xx_rt_wcscmp(r->name,L"description_crc16"))s=L"CRC16/ARC of description; native reader does not require it";
        else if(!xx_rt_wcscmp(r->name,L"serial_marker"))s=L"SNUM marker in known producers";
        else if(!xx_rt_wcscmp(r->name,L"header_crc16"))s=L"CRC16/ARC over the first31 header bytes";
        break;
    case 0x607f0003U:
        if(!xx_rt_wcscmp(r->name,L"decoded_crc16"))s=L"CRC16/ARC of the reconstructed track";
        else if(!xx_rt_wcscmp(r->name,L"signed_packed_length"))s=L"Positive LZHUF byte length; negative magnitude is RLE byte length";
        break;
    case 0x607f0004U:
        if(!xx_rt_wcscmp(r->name,L"directory_track_flags"))s=L"Low7bits identify the directory track; highbit is preserved";
        break;
    case 0x607f0005U:
        if(!xx_rt_wcscmp(r->name,L"allocated_granules"))s=L"Model I: low two bits represent the two five-sector granules in this track";
        break;
    case 0x607f0006U:
        if(!xx_rt_wcscmp(r->name,L"date_text"))s=L"Stored calendar text, not an integer timestamp";
        else if(!xx_rt_wcscmp(r->name,L"auto_command"))s=L"Physical command bytes; NUL or carriage-return terminates the meaningful text";
        break;
    case 0x607f0007U:
        if(!xx_rt_wcscmp(r->name,L"filename_hash"))s=L"TRSDOS rotate/XOR filename hash; zero marks an unused directory-entry code";
        break;
    case 0x607f0008U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"bit7 extended,bit6 system,bit5 limits/PDS,bit4 active,bit3 invisible,low3 protection";
        else if(!xx_rt_wcscmp(r->name,L"month_flags"))s=L"Low4bits month; remaining bits stored flags";
        else if(!xx_rt_wcscmp(r->name,L"day_year_flags"))s=L"High5bits day; low3bits year relative to1980";
        else if(!xx_rt_wcscmp(r->name,L"last_sector_bytes"))s=L"Zero means full256-byte sector";
        else if(!xx_rt_wcscmp(r->name,L"logical_record_length"))s=L"Zero means256-byte record";
        break;
    case 0x607f0009U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"bit7 extended,bit6 system,bit5 limits/PDS,bit4 active,bit3 invisible,low3 protection";
        else if(!xx_rt_wcscmp(r->name,L"previous_entry_code"))s=L"Previous directory-entry code, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"day_year_flags"))s=L"High5bits day; low3bits year relative to1980";
        else if(!xx_rt_wcscmp(r->name,L"last_sector_bytes"))s=L"Zero means full256-byte sector";
        else if(!xx_rt_wcscmp(r->name,L"logical_record_length"))s=L"Zero means256-byte record";
        break;
    case 0x607f000aU:
        if(!xx_rt_wcscmp(r->name,L"granule_start_count"))s=L"High3bits first granule; low5bits granule count minus one";
        break;
    case 0x607f000bU:
        if(!xx_rt_wcscmp(r->name,L"marker"))s=L"FE marks an extended-directory link";
        else if(!xx_rt_wcscmp(r->name,L"next_entry_code"))s=L"Directory-entry code, not a byte offset";
        break;
    case 0x607f000cU:
        if(!xx_rt_wcscmp(r->name,L"header_size_minus_two"))s=L"Native variant stores29 for a31-byte physical header";
        else if(!xx_rt_wcscmp(r->name,L"unknown_01"))s=L"Not interpreted by the native Savage reader";
        else if(!xx_rt_wcscmp(r->name,L"unknown_0f"))s=L"Native Savage grammar does not interpret these stored bytes";
        else if(!xx_rt_wcscmp(r->name,L"disk_crc16"))s=L"CRC16 of the decoded901120-byte disk";
        break;
    case 0x607f000dU:
        if(!xx_rt_wcscmp(r->name,L"rpm"))s=L"Revolutions per minute";
        else if(!xx_rt_wcscmp(r->name,L"bitrate_kbps"))s=L"Kilobits per second";
        else if(!xx_rt_wcscmp(r->name,L"track_list_block"))s=L"512-byte block number, not an unscaled byte offset";
        break;
    case 0x607f000eU:
        if(!xx_rt_wcscmp(r->name,L"track_block"))s=L"512-byte block number";
        else if(!xx_rt_wcscmp(r->name,L"combined_track_bytes"))s=L"Combined storage for both interleaved sides";
        break;
    case 0x607f000fU:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Sector size128<<code; native requires1";
        else if(!xx_rt_wcscmp(r->name,L"crc16_or_token"))s=L"Stored CRC16 or F7F7 controller-generated-CRC token";
        break;
    case 0x607f0010U:
        if(!xx_rt_wcscmp(r->name,L"size_code"))s=L"Sector size128<<code; native requires1";
        else if(!xx_rt_wcscmp(r->name,L"crc16_or_token"))s=L"Stored CRC16 or F7F7 controller-generated-CRC token";
        break;
    case 0x607f0011U:
        if(!xx_rt_wcscmp(r->name,L"data_mark"))s=L"FB normal or F8 deleted data";
        break;
    case 0x607f0012U:
        if(!xx_rt_wcscmp(r->name,L"data_mark"))s=L"FB normal or F8 deleted data";
        break;
    case 0x607f0013U:
        if(!xx_rt_wcscmp(r->name,L"crc16_or_token"))s=L"Stored CRC16 or F7F7 controller-generated-CRC token";
        break;
    case 0x607f0014U:
        if(!xx_rt_wcscmp(r->name,L"prologue"))s=L"D5AA96 for16sector or D5AAB5 for13sector address framing";
        else if(!xx_rt_wcscmp(r->name,L"volume_4and4"))s=L"Original4-and-4 encoded8-bit volume; decoded=(first<<1|1)&second";
        else if(!xx_rt_wcscmp(r->name,L"track_4and4"))s=L"Original4-and-4 encoded8-bit track";
        else if(!xx_rt_wcscmp(r->name,L"sector_4and4"))s=L"Original4-and-4 encoded8-bit sector";
        else if(!xx_rt_wcscmp(r->name,L"xor_checksum_4and4"))s=L"Original4-and-4 encoding of volume XOR track XOR sector";
        else if(!xx_rt_wcscmp(r->name,L"epilogue"))s=L"Standard DEAAEB epilogue; native authenticates the significant prefix";
        break;
    case 0x607f0015U:
        if(!xx_rt_wcscmp(r->name,L"prologue"))s=L"D5AAAD data framing";
        break;
    case 0x607f0016U:
        if(!xx_rt_wcscmp(r->name,L"translated_xor_checksum"))s=L"Original translated GCR checksum code, not a decoded sample";
        break;
    case 0x607f0017U:
        if(!xx_rt_wcscmp(r->name,L"current_sector_flags"))s=L"bit7 marks first sector;40hex encodes zero in low7bits";
        else if(!xx_rt_wcscmp(r->name,L"next_track_flags"))s=L"bit7 marks end of chain and points back to its firstsector";
        break;
    case 0x607f0018U:
        if(!xx_rt_wcscmp(r->name,L"volume_name_high_ascii"))s=L"High-bit Apple text; trailing spaces padded";
        else if(!xx_rt_wcscmp(r->name,L"carriage_return"))s=L"8Dhex";
        break;
    case 0x607f0019U:
        if(!xx_rt_wcscmp(r->name,L"first_track_flags"))s=L"Low7bits track;40hex encodes zero";
        else if(!xx_rt_wcscmp(r->name,L"first_sector_flags"))s=L"Low7bits sector;40hex encodes zero";
        else if(!xx_rt_wcscmp(r->name,L"type_high_ascii"))s=L"Low7bits space/L/M/P";
        else if(!xx_rt_wcscmp(r->name,L"carriage_return"))s=L"8Dhex";
        break;
    case 0x607f001aU:
        if(!xx_rt_wcscmp(r->name,L"riff_bytes"))s=L"Size excluding the first8 bytes";
        break;
    case 0x607f001bU:
        if(!xx_rt_wcscmp(r->name,L"data_bytes"))s=L"Payload size excluding8-byte header and alignment byte";
        break;
    case 0x607f001cU:
        if(!xx_rt_wcscmp(r->name,L"sample_rate"))s=L"Samples per second";
        else if(!xx_rt_wcscmp(r->name,L"byte_rate"))s=L"Bytes per second";
        break;
    case 0x607f001dU:
        if(!xx_rt_wcscmp(r->name,L"root_cluster"))s=L"Cluster index";
        break;
    case 0x607f001eU:
        if(!xx_rt_wcscmp(r->name,L"root_cluster"))s=L"Cluster index";
        break;
    case 0x607f001fU:
        if(!xx_rt_wcscmp(r->name,L"tag"))s=L"Physical XML tag spelling";
        break;
    case 0x607f0020U:
        if(!xx_rt_wcscmp(r->name,L"key"))s=L"Physical property-list key; entity spelling retained";
        break;
    case 0x607f0021U:
        if(!xx_rt_wcscmp(r->name,L"value"))s=L"Physical string token";
        break;
    case 0x607f0022U:
        if(!xx_rt_wcscmp(r->name,L"value"))s=L"Decimal integer token";
        break;
    case 0x607f0023U:
        if(!xx_rt_wcscmp(r->name,L"disk_size"))s=L"Virtual disk byte length";
        break;
    case 0x607f0024U:
        if(!xx_rt_wcscmp(r->name,L"band_size"))s=L"Bytes per external band file";
        break;
    case 0x607f0025U:
        if(!xx_rt_wcscmp(r->name,L"bundle_version"))s=L"Native supports versions1 and2; the version key may be absent";
        break;
    case 0x607f0026U:
        if(!xx_rt_wcscmp(r->name,L"lockout_flags"))s=L"FF lockedout,FC available in native Model I scope";
        break;
    case 0x607f0027U:
        if(!xx_rt_wcscmp(r->name,L"cylinders_minus_35"))s=L"LDOS interpretation; native geometry is separately validated";
        else if(!xx_rt_wcscmp(r->name,L"geometry_flags"))s=L"LDOS low3bits granules-per-track minus1,bit5 sides,bit6 density";
        break;
    case 0x607f0028U:
        if(!xx_rt_wcscmp(r->name,L"description"))s=L"Physical description bytes; no decompression";
        break;
    case 0x607f0029U:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit0";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit0; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit0; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit0; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit0; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit0; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit0; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit0; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f002aU:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit1";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit1; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit1; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit1; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit1; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit1; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit1; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit1; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f002bU:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit2";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit2; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit2; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit2; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit2; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit2; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit2; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit2; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f002cU:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit3";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit3; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit3; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit3; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit3; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit3; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit3; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit3; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f002dU:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit4";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit4; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit4; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit4; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit4; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit4; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit4; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit4; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f002eU:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit5";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit5; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit5; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit5; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit5; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit5; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit5; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit5; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f002fU:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit6";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit6; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit6; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit6; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit6; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit6; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit6; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit6; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f0030U:
        if(!xx_rt_wcscmp(r->name,L"sync_bitcells"))s=L"Three MFM missing-clock sync words; LSB-first physical bits, startingbit7";
        else if(!xx_rt_wcscmp(r->name,L"address_mark_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit7; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit7; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"head_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit7; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"sector_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit7; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"size_code_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit7; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_high_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit7; boundary bytes may also contain adjacent bits";
        else if(!xx_rt_wcscmp(r->name,L"crc_low_mfm_bitcells"))s=L"Physical16-bit MFM clock/data window begins at LSB-first bit7; boundary bytes may also contain adjacent bits";
        break;
    case 0x607f0031U:
        if(!xx_rt_wcscmp(r->name,L"dos_lead"))s=L"Original DOS load-address/length prefix or DDD Pro marker; no synthesized semantics";
        else if(!xx_rt_wcscmp(r->name,L"reserved_prefix"))s=L"Three zero bits";
        else if(!xx_rt_wcscmp(r->name,L"volume_reversed_bits"))s=L"Stored MSB-positioned bit sequence; reverse these8bits for decoded volume";
        else if(!xx_rt_wcscmp(r->name,L"favorite_0_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_1_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_2_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_3_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_4_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_5_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_6_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_7_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_8_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_9_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_10_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_11_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_12_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_13_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_14_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_15_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_16_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_17_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_18_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        else if(!xx_rt_wcscmp(r->name,L"favorite_19_reversed_bits"))s=L"First-track favorite byte stored least-significant bit first; displayed value retains the MSB-read physical code";
        break;
    case 0x607f0032U:
        if(!xx_rt_wcscmp(r->name,L"density"))s=L"0 MFM at250kbit/s;1 FM at125kbit/s";
        else if(!xx_rt_wcscmp(r->name,L"cylinders_and_sides"))s=L"Low7bits cylinders;highbit selects two sides";
        break;
    case 0x607f0033U:
        if(!xx_rt_wcscmp(r->name,L"extension_bytes"))s=L"Native PCM variant requires zero";
        break;
    case 0x607f0034U:
        if(!xx_rt_wcscmp(r->name,L"partition_name_utf16"))s=L"Original Xbox optional UTF16LE partition name; Xbox360 does not use this header field";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
#define SXDR_LIMIT 24000U
static bool sxdr_span(sx_context*c,uint64_t p,uint64_t n){return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
static bool sxdr_read(sx_context*c,uint64_t p,void*b,size_t n){return sxdr_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint16_t sxdr16(const uint8_t*b,bool be){return be?((uint16_t)b[0]<<8)|b[1]:(uint16_t)b[0]|((uint16_t)b[1]<<8);}
static uint32_t sxdr32(const uint8_t*b,bool be){return be?((uint32_t)b[0]<<24)|((uint32_t)b[1]<<16)|((uint32_t)b[2]<<8)|b[3]:(uint32_t)b[0]|((uint32_t)b[1]<<8)|((uint32_t)b[2]<<16)|((uint32_t)b[3]<<24);}
static bool sxdr_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>UINT64_MAX/z||!sxdr_span(c,p,count*z))return false;if(!count||c->count>=SXDR_LIMIT)return true;return count==1?sx_add(c,l,(int64_t)p,(int64_t)z):sx_table(c,l,(int64_t)p,(int64_t)z,(int64_t)count);}
#define SXDR_ADD(c,n,p) sxdr_put(c,&sxdr_##n,p,1)
static bool sxdr_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){if(!sxdr_span(c,p,n))return false;if(!n||n>16384||c->count>=SXDR_LIMIT)return true;return sx_add(c,l,(int64_t)p,(int64_t)n);}
static int sxdr_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;if(x->offset!=y->offset)return x->offset<y->offset?-1:1;if(x->total_size!=y->total_size)return x->total_size<y->total_size?-1:1;return x->id<y->id?-1:x->id>y->id;}
static bool sxdr_finish(sx_context*c){size_t n=c->count,kept=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxdr_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end)continue;c->items[kept++]=c->items[i];end=p+z;}c->count=kept;n=kept;end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxdr_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static uint16_t sxdr_crc16arc(const uint8_t*b,size_t n){uint16_t v=0;for(size_t i=0;i<n;i++){v^=b[i];for(unsigned j=0;j<8;j++)v=(v&1)?(v>>1)^0xa001:v>>1;}return v;}

static bool sxdr_sydex_header(sx_context*c,uint64_t p,uint8_t*h){if(!sxdr_read(c,p,h,33)||xx_rt_memcmp(h,"SXD",3)||sxdr_crc16arc(h,31)!=sxdr16(h+31,false)||sxdr16(h+15,false)||sxdr16(h+3,false)<128||sxdr16(h+3,false)>32768||!h[5]||!h[6]||!h[7]||!h[8]||h[8]>h[7]||sxdr16(h+19,false)>32767)return false;return true;}
static bool sxdr_sydex(sx_context*c){uint8_t mz[6],wb[10],h[33];uint64_t overlay,stage,p;uint32_t pages,last;
 if(!sxdr_read(c,0,mz,6)||xx_rt_memcmp(mz,"MZ",2)||(pages=sxdr16(mz+4,false))==0||(last=sxdr16(mz+2,false))>=512)return false;overlay=(uint64_t)(pages-1)*512+(last?last:512);if(overlay<64||!sxdr_read(c,overlay,wb,10)||xx_rt_memcmp(wb,"WB",2)||(pages=sxdr16(wb+4,false))==0||(last=sxdr16(wb+2,false))>=512||!sxdr16(wb+6,false)||(sxdr16(wb+8,false)!=0xe4d5U&&sxdr16(wb+8,false)!=0xe5ccU))return false;
 stage=(uint64_t)(pages-1)*512+(last?last:512);p=overlay+stage;if(stage<10||!sxdr_sydex_header(c,p,h)){bool found=false;for(uint64_t i=10;i<=0x20000&&sxdr_span(c,overlay+i,33);i++){uint8_t b;if(!sxdr_read(c,overlay+i,&b,1))return false;if(b=='S'&&sxdr_sydex_header(c,overlay+i,h)){p=overlay+i;found=true;break;}}if(!found)return false;}
 if(!SXDR_ADD(c,sydex_wb_header,overlay)||!SXDR_ADD(c,sydex_image_header,p))return false;uint64_t n=sxdr16(h+19,false),count=(uint64_t)h[6]*h[8];if(!sxdr_span(c,p+33,n))return true;if(!sxdr_text(c,&sxdr_sydex_description,p+33,n))return false;p+=33+n;
 for(uint64_t i=0;i<count;i++){uint8_t q[4];if(!sxdr_read(c,p,q,4))break;int32_t len=(int16_t)sxdr16(q+2,false);if(!len)break;if(!SXDR_ADD(c,sydex_track_header,p))return false;p+=4;uint32_t z=(uint32_t)(len<0?-len:len);if(!sxdr_span(c,p,z))break;p+=z;}return true;}
static bool sxdr_vtr(sx_context*c){uint8_t h[370];if(!sxdr_read(c,0,h,sizeof(h))||xx_rt_memcmp(h,"VTrucco",7)||!h[10]||!h[12]||h[12]>2||h[18]||!SXDR_ADD(c,vtr_header,0))return false;uint64_t table=(uint64_t)sxdr16(h+16,false)*512;if(table<512||!sxdr_span(c,table,(uint64_t)h[10]*4))return true;return sxdr_put(c,&sxdr_vtr_track_entry,table,h[10]);}
static bool sxdr_savage(sx_context*c){uint8_t h[31];return sxdr_read(c,0,h,31)&&h[0]==29&&!xx_rt_memcmp(h+2,"*SVG*",5)&&sxdr32(h+11,false)==901120&&SXDR_ADD(c,savage_header,0);}
static bool sxdr_trs(sx_context*c){uint8_t boot[3],e[32];if(c->size<5120||c->size%2560||c->size>96*2560||!sxdr_read(c,0,boot,3))return false;uint64_t track=boot[2]&127,tracks=c->size/2560,base=track*2560;if(!track||track>=tracks||!sxdr_span(c,base,2560))return false;
 if(!SXDR_ADD(c,trs80_boot_directory,2)||!sxdr_put(c,&sxdr_trs80_gat_track,base,tracks)||!sxdr_put(c,&sxdr_trs80_gat_lockout,base+96,tracks)||!SXDR_ADD(c,trs80_gat_system,base+203)||!SXDR_ADD(c,trs80_gat_identity,base+208)||!sxdr_put(c,&sxdr_trs80_hit,base+256,256))return false;
 for(uint64_t i=0;i<64;i++){uint64_t p=base+512+i*32;if(!sxdr_read(c,p,e,32))return false;if(!(e[0]&16))continue;if(!sxdr_put(c,(e[0]&128)?&sxdr_trs80_extended_entry:&sxdr_trs80_primary_entry,p,1))return false;for(unsigned j=0;j<5;j++){uint8_t a=e[22+j*2];if(a==255)break;if(j==4&&a==254){if(!SXDR_ADD(c,trs80_extent_link,p+30))return false;break;}if(!SXDR_ADD(c,trs80_extent,p+22+j*2))return false;}}return true;}
static bool sxdr_cassette(sx_context*c){uint8_t h[16];if(!sxdr_read(c,0,h,12)||xx_rt_memcmp(h,"RIFF",4)||xx_rt_memcmp(h+8,"WAVE",4)||!SXDR_ADD(c,cassette_riff,0))return false;uint64_t end=8+(uint64_t)sxdr32(h+4,false),p=12;if(end>(uint64_t)c->size)return true;
 while(p<=end&&end-p>=8){if(!sxdr_read(c,p,h,8)||!SXDR_ADD(c,cassette_chunk,p))return false;uint64_t n=sxdr32(h+4,false);p+=8;if(n>end-p)break;if(!xx_rt_memcmp(h,"fmt ",4)&&n>=16){if(!SXDR_ADD(c,cassette_pcm_format,p))return false;if(n==18&&!SXDR_ADD(c,cassette_pcm_extension,p+16))return false;}p+=n;if(n&1){if(p==end)break;p++;}}return true;}
static bool sxdr_xbox(sx_context*c){uint64_t p=UINT64_C(0x130eb0000);uint8_t h[16];if(!sxdr_read(c,p,h,sizeof(h)))return false;bool be=!xx_rt_memcmp(h,"XTAF",4);if(!be&&xx_rt_memcmp(h,"FATX",4))return false;if(!sxdr_put(c,be?&sxdr_xbox_fatx_header_be:&sxdr_xbox_fatx_header_le,p,1))return false;return be||!sxdr_span(c,p+16,64)||SXDR_ADD(c,xbox_fatx_name_le,p+16);}

static uint16_t sxdr_ccitt(const uint8_t*b,size_t n){uint16_t v=0xffffU;for(size_t i=0;i<n;i++){v^=(uint16_t)b[i]<<8;for(unsigned j=0;j<8;j++)v=(uint16_t)((v<<1)^((v&0x8000U)?0x1021U:0));}return v;}
static uint16_t sxdr_mfmword(const uint8_t*b,uint32_t bit){uint16_t v=0;for(unsigned k=0;k<16;k++)v=(uint16_t)((v<<1)|((b[(bit+k)/8]>>((bit+k)%8))&1));return v;}
static uint8_t sxdr_mfmdata(uint16_t v){uint8_t x=0;for(unsigned k=0;k<8;k++)x=(uint8_t)((x<<1)|((v>>(14-k*2))&1));return x;}
static bool sxdr_fei_track(sx_context*c,uint8_t*b,uint64_t p,uint32_t n,uint32_t cyl,uint32_t head,bool emit){
 if(!sxdr_read(c,p,b,n))return false;bool found=false;const sx_layout*phases[]={&sxdr_fei_id_phase0,&sxdr_fei_id_phase1,&sxdr_fei_id_phase2,&sxdr_fei_id_phase3,&sxdr_fei_id_phase4,&sxdr_fei_id_phase5,&sxdr_fei_id_phase6,&sxdr_fei_id_phase7};
 for(uint32_t bit=0;bit+160<=n*8;bit++){if(!(bit&4095)&&xx_pd_is_stopped(c->pd))return false;if(sxdr_mfmword(b,bit)!=0x4489||sxdr_mfmword(b,bit+16)!=0x4489||sxdr_mfmword(b,bit+32)!=0x4489)continue;uint8_t id[10]={0xa1,0xa1,0xa1};for(unsigned j=0;j<7;j++)id[j+3]=sxdr_mfmdata(sxdr_mfmword(b,bit+48+j*16));if(id[3]!=0xfe||!id[6]||id[7]>6||sxdr_ccitt(id,10))continue;if(id[4]!=cyl||id[5]!=head)return false;found=true;if(emit&&!sxdr_put(c,phases[bit%8],p+bit/8,1))return false;}
 return found;}
static bool sxdr_fei(sx_context*c){uint8_t*b=xx_mem_alloc(25000);if(!b)return false;uint32_t bytes=0,tracks=0;bool ok=false;
 for(unsigned pass=0;pass<2;pass++){uint32_t n=pass?12500:25000;if(c->size<=0||c->size%(n*2))continue;uint64_t t=c->size/(n*2);if(t>170||!t)continue;if(sxdr_fei_track(c,b,0,n,0,0,false)&&sxdr_fei_track(c,b,t*n,n,0,1,false)&&sxdr_fei_track(c,b,(t-1)*n,n,(uint32_t)t-1,0,false)&&sxdr_fei_track(c,b,(t*2-1)*n,n,(uint32_t)t-1,1,false)){bytes=n;tracks=(uint32_t)t;break;}}
 if(bytes){ok=true;for(uint32_t i=0;i<tracks*2&&c->count<SXDR_LIMIT;i++){/* Interior tracks need not have decodable sector IDs. */size_t start=c->count;bool z=sxdr_fei_track(c,b,(uint64_t)i*bytes,bytes,i%tracks,i/tracks,true);if(!z&&xx_pd_is_stopped(c->pd)){ok=false;break;}if(!z)c->count=start;}}
 xx_mem_free(b);return ok;}
static bool sxdr_pc_crc(const uint8_t*b,size_t n,const uint8_t*crc){return (crc[0]==0xf7&&crc[1]==0xf7)||sxdr_ccitt(b,n)==sxdr16(crc,true);}
static bool sxdr_pc99(sx_context*c){uint32_t n=0;bool fm=false;if(c->size==40*3253||c->size==80*3253){n=3253;fm=true;}else if(c->size==40*6872||c->size==80*6872)n=6872;else return false;uint8_t*b=xx_mem_alloc(n);if(!b)return false;bool ok=true;
 for(uint32_t tr=0;tr<(uint64_t)c->size/n&&ok;tr++){uint64_t base=(uint64_t)tr*n;if(!sxdr_read(c,base,b,n)){ok=false;break;}uint32_t wanted=fm?9:18,seen=0;for(uint32_t i=0;i+7<n;){if(!(i&255)&&xx_pd_is_stopped(c->pd)){ok=false;break;}if(b[i]!=0xfe||(!fm&&(i<3||b[i-3]!=0xa1||b[i-2]!=0xa1||b[i-1]!=0xa1))){i++;continue;}uint32_t a=fm?i:i-3;if(b[i+1]!=tr%40||b[i+2]!=tr/40||b[i+3]>=wanted||b[i+4]!=1||!sxdr_pc_crc(b+a,i+5-a,b+i+5)){i++;continue;}uint32_t j=i+7;for(;j<n&&j-i<96;j++){if((b[j]==0xfb||b[j]==0xf8)&&(fm||(j>=3&&b[j-3]==0xa1&&b[j-2]==0xa1&&b[j-1]==0xa1)))break;if(b[j]==0xfe)break;}
 if(j>=n||j-i>=96||n-j<259||(b[j]!=0xfb&&b[j]!=0xf8)||(seen&(1U<<b[i+3]))){ok=false;break;}uint32_t data=fm?j:j-3;if(!sxdr_pc_crc(b+data,j+257-data,b+j+257)){ok=false;break;}seen|=1U<<b[i+3];if(!sxdr_put(c,fm?&sxdr_pc99_id_fm:&sxdr_pc99_id_mfm,base+a,1)||!sxdr_put(c,fm?&sxdr_pc99_data_fm:&sxdr_pc99_data_mfm,base+data,1)||!SXDR_ADD(c,pc99_data_crc,base+j+257)){ok=false;break;}i=j+259;}
 if(seen!=(1U<<wanted)-1)ok=false;}
 xx_mem_free(b);return ok;}
static bool sxdr_sdd(sx_context*c){uint8_t h[16];if(!sxdr_read(c,0,h,16)||xx_rt_memcmp(h,"TRKY2",5)||h[13]>1||!(h[14]&127)||!h[15])return false;uint64_t bytes=(uint64_t)(h[14]&127)*((h[14]&128)?2:1)*h[15]*256;if(bytes!=(uint64_t)c->size)return false;return SXDR_ADD(c,speccydos_boot_header,0);}

static uint8_t sxdr_ring(const uint8_t*b,uint32_t n,uint32_t p){return b[p%n];}
static bool sxdr_four(const uint8_t*b,uint32_t n,uint32_t p,uint8_t*v){uint8_t a=sxdr_ring(b,n,p),z=sxdr_ring(b,n,p+1);if((a&0xaa)!=0xaa||(z&0xaa)!=0xaa)return false;*v=(uint8_t)(((a<<1)|1)&z);return true;}
static bool sxdr_gcrcheck(const uint8_t*b,uint32_t n,uint32_t p,unsigned sectors){
 static const uint8_t codes62[64]={0x96,0x97,0x9a,0x9b,0x9d,0x9e,0x9f,0xa6,0xa7,0xab,0xac,0xad,0xae,0xaf,0xb2,0xb3,0xb4,0xb5,0xb6,0xb7,0xb9,0xba,0xbb,0xbc,0xbd,0xbe,0xbf,0xcb,0xcd,0xce,0xcf,0xd3,0xd6,0xd7,0xd9,0xda,0xdb,0xdc,0xdd,0xde,0xdf,0xe5,0xe6,0xe7,0xe9,0xea,0xeb,0xec,0xed,0xee,0xef,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff};
 static const uint8_t codes53[32]={0xab,0xad,0xae,0xaf,0xb5,0xb6,0xb7,0xba,0xbb,0xbd,0xbe,0xbf,0xd6,0xd7,0xda,0xdb,0xdd,0xde,0xdf,0xea,0xeb,0xed,0xee,0xef,0xf5,0xf6,0xf7,0xfa,0xfb,0xfd,0xfe,0xff};
 uint8_t inv[256],sum=0;xx_rt_memset(inv,255,sizeof(inv));for(unsigned i=0;i<(sectors==13?32:64);i++)inv[sectors==13?codes53[i]:codes62[i]]=(uint8_t)i;uint32_t z=sectors==13?410:342;
 for(uint32_t i=0;i<z;i++){uint8_t v=inv[sxdr_ring(b,n,p+i)];if(v==255)return false;sum^=v;}return inv[sxdr_ring(b,n,p+z)]==sum&&sxdr_ring(b,n,p+z+1)==0xde&&sxdr_ring(b,n,p+z+2)==0xaa;}
static bool sxdr_nib(sx_context*c){uint32_t n=0;if(c->size>=35*6656&&c->size<=50*6656&&c->size%6656==0)n=6656;else if(c->size>=35*6384&&c->size<=40*6384&&c->size%6384==0)n=6384;else return false;uint8_t*b=xx_mem_alloc(n);if(!b)return false;bool ok=true;
 for(uint32_t tr=0;tr<(uint64_t)c->size/n&&ok&&c->count<SXDR_LIMIT;tr++){uint64_t base=(uint64_t)tr*n;if(!sxdr_read(c,base,b,n)){ok=false;break;}for(uint32_t i=0;i<n;i++){if(!(i&255)&&xx_pd_is_stopped(c->pd)){ok=false;break;}if(b[i]!=0xd5||sxdr_ring(b,n,i+1)!=0xaa)continue;uint8_t mark=sxdr_ring(b,n,i+2);unsigned sectors=mark==0x96?16:mark==0xb5?13:0;if(!sectors)continue;uint8_t v,t,s,x;if(!sxdr_four(b,n,i+3,&v)||!sxdr_four(b,n,i+5,&t)||!sxdr_four(b,n,i+7,&s)||!sxdr_four(b,n,i+9,&x)||t!=tr||s>=sectors||(uint8_t)(v^t^s)!=x||sxdr_ring(b,n,i+11)!=0xde||sxdr_ring(b,n,i+12)!=0xaa)continue;
 for(uint32_t gap=14;gap<270;gap++){uint32_t p=i+gap;if(sxdr_ring(b,n,p)!=0xd5||sxdr_ring(b,n,p+1)!=0xaa)continue;mark=sxdr_ring(b,n,p+2);if(mark==0x96||mark==0xb5)break;if(mark!=0xad)continue;if(sxdr_gcrcheck(b,n,p+3,sectors)){/* Each emitted structure must itself be contiguous in the source track. */if(i+14<=n&&!SXDR_ADD(c,apple_gcr_address,base+i)){ok=false;break;}uint32_t d=p%n,z=sectors==13?410:342,end=(p+3+z)%n;if(d+3<=n&&!SXDR_ADD(c,apple_gcr_data_prefix,base+d)){ok=false;break;}if(end+4<=n&&!SXDR_ADD(c,apple_gcr_data_suffix,base+end)){ok=false;break;}}break;}
 }}xx_mem_free(b);return ok&&c->count!=0;}
static uint32_t sxdr_gb_index(uint8_t t,uint8_t s){t&=127;s&=127;if(t==64)t=0;if(s==64)s=0;return t<35&&s<16?(uint32_t)t*16+s:560;}
static uint64_t sxdr_gb_offset(uint32_t i,bool po){static const uint8_t skew[16]={0,14,13,12,11,10,9,8,7,6,5,4,3,2,1,15};return (uint64_t)(i/16)*4096+(po?skew[i%16]:i%16)*256;}
static bool sxdr_gb_chain(sx_context*c,uint32_t first,bool po,uint16_t*list,uint32_t*count){uint8_t seen[560]={0},h[6];uint32_t curr=first,prev=560;*count=0;for(unsigned k=0;k<560;k++){if(curr>=560||seen[curr]||!sxdr_read(c,sxdr_gb_offset(curr,po),h,6)||sxdr_gb_index(h[2],h[3])!=curr||((h[3]&128)!=0)!=(k==0)||(k&&sxdr_gb_index(h[0],h[1])!=prev))return false;seen[curr]=1;list[(*count)++]=(uint16_t)curr;uint32_t next=sxdr_gb_index(h[4],h[5]);if(h[4]&128)return next==first;prev=curr;curr=next;}return false;}
static bool sxdr_gutenberg(sx_context*c){if(c->size!=35*4096)return false;uint16_t dirs[560],files[560];uint8_t root[256],d[256];bool any=false;
 for(unsigned order=0;order<2;order++){bool po=order!=0;uint32_t nd=0;if(!sxdr_read(c,sxdr_gb_offset(279,po),root,256)||root[15]!=0x8d||xx_rt_memcmp(root+16,"\xc4\xc9\xd2",3)||!sxdr_gb_chain(c,279,po,dirs,&nd))continue;any=true;
 for(uint32_t i=0;i<nd;i++){uint64_t p=sxdr_gb_offset(dirs[i],po);if(!sxdr_read(c,p,d,256))return false;if(xx_rt_memcmp(d+6,root+6,9)||d[15]!=0x8d)continue;if(!SXDR_ADD(c,gutenberg_link,p)||!SXDR_ADD(c,gutenberg_volume,p+6))return false;
 for(unsigned j=0;j<15;j++){const uint8_t*e=d+16+j*16;if(!e[0]||e[0]==0xa0)continue;uint8_t type=e[14]&127;uint32_t first=sxdr_gb_index(e[12],e[13]),nf=0;if(e[15]!=0x8d||(type!=' '&&type!='L'&&type!='M'&&type!='P')||!sxdr_gb_chain(c,first,po,files,&nf))continue;if(!SXDR_ADD(c,gutenberg_entry,p+16+j*16))return false;for(uint32_t k=0;k<nf;k++)if(!SXDR_ADD(c,gutenberg_link,sxdr_gb_offset(files[k],po)))return false;}}
 }return any;}
static bool sxdr_ddd(sx_context*c){uint8_t h[26];return sxdr_read(c,0,h,sizeof(h))&&!(h[4]&0xe0)&&SXDR_ADD(c,ddd_initial_dictionary,0);}

static bool sxdr_ws(uint8_t x){return x==' '||x=='\t'||x=='\n'||x=='\r';}
static bool sxdr_plist(sx_context*c){if(c->size<64||c->size>65536)return false;size_t n=(size_t)c->size,p=0,depth=0;uint8_t*b=xx_mem_alloc(n);if(!b)return false;bool ok=sxdr_read(c,0,b,n);char stack[68][64],key[40]={0};if(n>=3&&b[0]==0xef&&b[1]==0xbb&&b[2]==0xbf)p=3;
 while(ok&&p<n){if(xx_pd_is_stopped(c->pd)){ok=false;break;}if(b[p]!='<'){size_t a=p;while(p<n&&b[p]!='<')p++;size_t z=p;while(a<z&&sxdr_ws(b[a]))a++;while(z>a&&sxdr_ws(b[z-1]))z--;if(!depth||a==z)continue;const sx_layout*l=NULL;const char*t=stack[depth-1];if(!xx_rt_strcmp(t,"key")){l=&sxdr_plist_key;if(depth==3){size_t len=z-a;key[0]=0;if(len<sizeof(key)){xx_rt_memcpy(key,b+a,len);key[len]=0;}}}else if(!xx_rt_strcmp(t,"string"))l=&sxdr_plist_string;else if(!xx_rt_strcmp(t,"integer")){l=&sxdr_plist_integer;if(depth==3){if(!xx_rt_strcmp(key,"size"))l=&sxdr_plist_disk_size;else if(!xx_rt_strcmp(key,"band-size"))l=&sxdr_plist_band_size;else if(!xx_rt_strcmp(key,"bundle-backingstore-version"))l=&sxdr_plist_bundle_version;}}
 if(l&&!sxdr_text(c,l,a,z-a)){ok=false;break;}continue;}
 size_t a=p++;if(p<n&&(b[p]=='!'||b[p]=='?')){const char*end=b[p]=='?'?"?>":p+2<n&&b[p+1]=='-'&&b[p+2]=='-'?"-->":">";size_t len=xx_rt_strlen(end);while(p+len<=n&&xx_rt_memcmp(b+p,end,len))p++;if(p+len>n){ok=false;break;}p+=len;continue;}
 bool close=p<n&&b[p]=='/';if(close)p++;size_t start=p;while(p<n&&((b[p]>='a'&&b[p]<='z')||(b[p]>='A'&&b[p]<='Z')||(b[p]>='0'&&b[p]<='9')||b[p]=='-'||b[p]=='_'||b[p]=='.'||b[p]==':'))p++;size_t len=p-start;if(!len||len>=64){ok=false;break;}uint8_t quote=0;bool ended=false;for(;p<n;p++){uint8_t x=b[p];if(quote){if(x==quote)quote=0;}else if(x=='\''||x=='"')quote=x;else if(x=='>'){p++;ended=true;break;}else if(x=='<'){break;}}
 if(!ended){ok=false;break;}bool empty=p>=2&&b[p-2]=='/';if(!sxdr_text(c,&sxdr_plist_tag,a,p-a)){ok=false;break;}if(close){if(!depth||xx_rt_strlen(stack[depth-1])!=len||xx_rt_memcmp(stack[depth-1],b+start,len)){ok=false;break;}depth--;}else if(!empty){if(depth>=68){ok=false;break;}xx_rt_memcpy(stack[depth],b+start,len);stack[depth][len]=0;depth++;}}
 xx_mem_free(b);return !xx_pd_is_stopped(c->pd)&&!c->failed&&c->count!=0;}

static bool sx_diskremaining_supports(xx_file_type_t type){switch(type){
case XX_FILE_TYPE_SFX_SYDEX_DISKETTE_IMAGE:case XX_FILE_TYPE_APPLE_SPARSE_BUNDLE:case XX_FILE_TYPE_TRS_80_JV1:case XX_FILE_TYPE_DDD:case XX_FILE_TYPE_FEI:case XX_FILE_TYPE_APPLE_NIB:case XX_FILE_TYPE_TI99_PC99:case XX_FILE_TYPE_VTR_DISK:case XX_FILE_TYPE_SPECCYDOS_SDD:case XX_FILE_TYPE_SAVAGE:case XX_FILE_TYPE_GUTENBERG:case XX_FILE_TYPE_APPLE_CASSETTE:case XX_FILE_TYPE_XBOX360_LAYOUT:return true;default:return false;}}
static bool sx_diskremaining_build(sx_context*c){bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_SFX_SYDEX_DISKETTE_IMAGE:ok=sxdr_sydex(c);break;
case XX_FILE_TYPE_APPLE_SPARSE_BUNDLE:ok=sxdr_plist(c);break;
case XX_FILE_TYPE_TRS_80_JV1:ok=sxdr_trs(c);break;
case XX_FILE_TYPE_DDD:ok=sxdr_ddd(c);break;
case XX_FILE_TYPE_FEI:ok=sxdr_fei(c);break;
case XX_FILE_TYPE_APPLE_NIB:ok=sxdr_nib(c);break;
case XX_FILE_TYPE_TI99_PC99:ok=sxdr_pc99(c);break;
case XX_FILE_TYPE_VTR_DISK:ok=sxdr_vtr(c);break;
case XX_FILE_TYPE_SPECCYDOS_SDD:ok=sxdr_sdd(c);break;
case XX_FILE_TYPE_SAVAGE:ok=sxdr_savage(c);break;
case XX_FILE_TYPE_GUTENBERG:ok=sxdr_gutenberg(c);break;
case XX_FILE_TYPE_APPLE_CASSETTE:ok=sxdr_cassette(c);break;
case XX_FILE_TYPE_XBOX360_LAYOUT:ok=sxdr_xbox(c);break;
default:return false;}
return ok&&c->count&&sxdr_finish(c);}
#undef SXDR_ADD
#undef SXDR_LIMIT

