/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical disk image and filesystem metadata. Unimplemented payloads remain raw. */

static const xx_data_struct_field_desc sx_dm_vhdx_file_identifier_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("creator_utf16","uint16[256]",8,512,SX_NONE),
};
static const sx_layout sx_dm_vhdx_file_identifier = {0x60290001U,"vhdx_file_identifier",sx_dm_vhdx_file_identifier_fields,SX_COUNT(sx_dm_vhdx_file_identifier_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vhdx_header_fields[] = {
    SX_FIELD("signature","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("file_write_guid","byte[16]",16,16,SX_ID),
    SX_FIELD("data_write_guid","byte[16]",32,16,SX_ID),
    SX_FIELD("log_guid","byte[16]",48,16,SX_ID),
    SX_FIELD("log_version","uint16",64,2,SX_NONE),
    SX_FIELD("version","uint16",66,2,SX_NONE),
    SX_FIELD("log_length","uint32",68,4,SX_SIZE),
    SX_FIELD("log_offset","uint64",72,8,SX_OFFSET),
    SX_FIELD("reserved","byte[4016]",80,4016,SX_RESERVED),
};
static const sx_layout sx_dm_vhdx_header = {0x60290002U,"vhdx_header",sx_dm_vhdx_header_fields,SX_COUNT(sx_dm_vhdx_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vhdx_region_table_header_fields[] = {
    SX_FIELD("signature","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sx_dm_vhdx_region_table_header = {0x60290003U,"vhdx_region_table_header",sx_dm_vhdx_region_table_header_fields,SX_COUNT(sx_dm_vhdx_region_table_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vhdx_region_table_entry_fields[] = {
    SX_FIELD("guid","byte[16]",0,16,SX_ID),
    SX_FIELD("file_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("length","uint32",24,4,SX_SIZE),
    SX_FIELD("flags","uint32",28,4,SX_FLAGS),
};
static const sx_layout sx_dm_vhdx_region_table_entry = {0x60290004U,"vhdx_region_table_entry",sx_dm_vhdx_region_table_entry_fields,SX_COUNT(sx_dm_vhdx_region_table_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vhdx_metadata_table_header_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("reserved1","uint16",8,2,SX_RESERVED),
    SX_FIELD("entry_count","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("reserved2","byte[20]",12,20,SX_RESERVED),
};
static const sx_layout sx_dm_vhdx_metadata_table_header = {0x60290005U,"vhdx_metadata_table_header",sx_dm_vhdx_metadata_table_header_fields,SX_COUNT(sx_dm_vhdx_metadata_table_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vhdx_metadata_table_entry_fields[] = {
    SX_FIELD("item_id","byte[16]",0,16,SX_ID),
    SX_FIELD("offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("length","uint32",20,4,SX_SIZE),
    SX_FIELD("flags","uint32",24,4,SX_FLAGS),
    SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
};
static const sx_layout sx_dm_vhdx_metadata_table_entry = {0x60290006U,"vhdx_metadata_table_entry",sx_dm_vhdx_metadata_table_entry_fields,SX_COUNT(sx_dm_vhdx_metadata_table_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vhdx_file_parameters_fields[] = {
    SX_FIELD("block_size","uint32",0,4,SX_SIZE),
    SX_FIELD("flags","uint32",4,4,SX_FLAGS),
};
static const sx_layout sx_dm_vhdx_file_parameters = {0x60290007U,"vhdx_file_parameters",sx_dm_vhdx_file_parameters_fields,SX_COUNT(sx_dm_vhdx_file_parameters_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vhdx_disk_size_fields[] = {
    SX_FIELD("virtual_disk_size","uint64",0,8,SX_SIZE),
};
static const sx_layout sx_dm_vhdx_disk_size = {0x60290008U,"vhdx_disk_size",sx_dm_vhdx_disk_size_fields,SX_COUNT(sx_dm_vhdx_disk_size_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vhdx_logical_sector_size_fields[] = {
    SX_FIELD("logical_sector_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sx_dm_vhdx_logical_sector_size = {0x60290009U,"vhdx_logical_sector_size",sx_dm_vhdx_logical_sector_size_fields,SX_COUNT(sx_dm_vhdx_logical_sector_size_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vhdx_physical_sector_size_fields[] = {
    SX_FIELD("physical_sector_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sx_dm_vhdx_physical_sector_size = {0x6029000aU,"vhdx_physical_sector_size",sx_dm_vhdx_physical_sector_size_fields,SX_COUNT(sx_dm_vhdx_physical_sector_size_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vhdx_virtual_disk_id_fields[] = {
    SX_FIELD("virtual_disk_id","byte[16]",0,16,SX_ID),
};
static const sx_layout sx_dm_vhdx_virtual_disk_id = {0x6029000bU,"vhdx_virtual_disk_id",sx_dm_vhdx_virtual_disk_id_fields,SX_COUNT(sx_dm_vhdx_virtual_disk_id_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vhdx_parent_locator_fields[] = {
    SX_FIELD("locator_type","byte[16]",0,16,SX_ID),
    SX_FIELD("reserved","uint16",16,2,SX_RESERVED),
    SX_FIELD("key_value_count","uint16",18,2,SX_COUNT_PROP),
};
static const sx_layout sx_dm_vhdx_parent_locator = {0x6029000cU,"vhdx_parent_locator",sx_dm_vhdx_parent_locator_fields,SX_COUNT(sx_dm_vhdx_parent_locator_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vhdx_parent_locator_entry_fields[] = {
    SX_FIELD("key_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("value_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("key_length","uint16",8,2,SX_SIZE),
    SX_FIELD("value_length","uint16",10,2,SX_SIZE),
};
static const sx_layout sx_dm_vhdx_parent_locator_entry = {0x6029000dU,"vhdx_parent_locator_entry",sx_dm_vhdx_parent_locator_entry_fields,SX_COUNT(sx_dm_vhdx_parent_locator_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vhdx_bat_entry_fields[] = {
    SX_FIELD("file_offset_and_state","uint64",0,8,SX_FLAGS),
};
static const sx_layout sx_dm_vhdx_bat_entry = {0x6029000eU,"vhdx_bat_entry",sx_dm_vhdx_bat_entry_fields,SX_COUNT(sx_dm_vhdx_bat_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vhd_footer_511_fields[] = {
    SX_FIELD("cookie","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("features","uint32",8,4,SX_FLAGS),
    SX_FIELD("file_format_version","uint32",12,4,SX_NONE),
    SX_FIELD("data_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("timestamp","uint32",24,4,SX_TIME),
    SX_FIELD("creator_application","byte[4]",28,4,SX_ID),
    SX_FIELD("creator_version","uint32",32,4,SX_NONE),
    SX_FIELD("creator_host_os","byte[4]",36,4,SX_ID),
    SX_FIELD("original_size","uint64",40,8,SX_SIZE),
    SX_FIELD("current_size","uint64",48,8,SX_SIZE),
    SX_FIELD("cylinders","uint16",56,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint8",58,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",59,1,SX_COUNT_PROP),
    SX_FIELD("disk_type","uint32",60,4,SX_ID),
    SX_FIELD("checksum","uint32",64,4,SX_CHECKSUM),
    SX_FIELD("unique_id","byte[16]",68,16,SX_ID),
    SX_FIELD("saved_state","uint8",84,1,SX_FLAGS),
    SX_FIELD("reserved","byte[426]",85,426,SX_RESERVED),
};
static const sx_layout sx_dm_vhd_footer_511 = {0x6029000fU,"vhd_footer_511",sx_dm_vhd_footer_511_fields,SX_COUNT(sx_dm_vhd_footer_511_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_vhd_footer_512_fields[] = {
    SX_FIELD("cookie","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("features","uint32",8,4,SX_FLAGS),
    SX_FIELD("file_format_version","uint32",12,4,SX_NONE),
    SX_FIELD("data_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("timestamp","uint32",24,4,SX_TIME),
    SX_FIELD("creator_application","byte[4]",28,4,SX_ID),
    SX_FIELD("creator_version","uint32",32,4,SX_NONE),
    SX_FIELD("creator_host_os","byte[4]",36,4,SX_ID),
    SX_FIELD("original_size","uint64",40,8,SX_SIZE),
    SX_FIELD("current_size","uint64",48,8,SX_SIZE),
    SX_FIELD("cylinders","uint16",56,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint8",58,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",59,1,SX_COUNT_PROP),
    SX_FIELD("disk_type","uint32",60,4,SX_ID),
    SX_FIELD("checksum","uint32",64,4,SX_CHECKSUM),
    SX_FIELD("unique_id","byte[16]",68,16,SX_ID),
    SX_FIELD("saved_state","uint8",84,1,SX_FLAGS),
    SX_FIELD("reserved","byte[427]",85,427,SX_RESERVED),
};
static const sx_layout sx_dm_vhd_footer_512 = {0x60290010U,"vhd_footer_512",sx_dm_vhd_footer_512_fields,SX_COUNT(sx_dm_vhd_footer_512_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_vhd_dynamic_header_fields[] = {
    SX_FIELD("cookie","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("data_offset","uint64",8,8,SX_OFFSET),
    SX_FIELD("table_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("header_version","uint32",24,4,SX_NONE),
    SX_FIELD("max_table_entries","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("block_size","uint32",32,4,SX_SIZE),
    SX_FIELD("checksum","uint32",36,4,SX_CHECKSUM),
    SX_FIELD("parent_unique_id","byte[16]",40,16,SX_ID),
    SX_FIELD("parent_timestamp","uint32",56,4,SX_TIME),
    SX_FIELD("reserved","uint32",60,4,SX_RESERVED),
    SX_FIELD("parent_unicode_name","uint16[256]",64,512,SX_NONE),
};
static const sx_layout sx_dm_vhd_dynamic_header = {0x60290011U,"vhd_dynamic_header",sx_dm_vhd_dynamic_header_fields,SX_COUNT(sx_dm_vhd_dynamic_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_vhd_parent_locator_fields[] = {
    SX_FIELD("platform_code","byte[4]",0,4,SX_ID),
    SX_FIELD("platform_data_space","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("platform_data_length","uint32",8,4,SX_SIZE),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
    SX_FIELD("platform_data_offset","uint64",16,8,SX_OFFSET),
};
static const sx_layout sx_dm_vhd_parent_locator = {0x60290012U,"vhd_parent_locator",sx_dm_vhd_parent_locator_fields,SX_COUNT(sx_dm_vhd_parent_locator_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_vhd_bat_entry_fields[] = {
    SX_FIELD("sector_index","uint32",0,4,SX_ID),
};
static const sx_layout sx_dm_vhd_bat_entry = {0x60290013U,"vhd_bat_entry",sx_dm_vhd_bat_entry_fields,SX_COUNT(sx_dm_vhd_bat_entry_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_vmdk_sparse_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_NONE),
    SX_FIELD("flags","uint32",8,4,SX_FLAGS),
    SX_FIELD("capacity_sectors","uint64",12,8,SX_COUNT_PROP),
    SX_FIELD("grain_size_sectors","uint64",20,8,SX_COUNT_PROP),
    SX_FIELD("descriptor_sector","uint64",28,8,SX_ID),
    SX_FIELD("descriptor_size_sectors","uint64",36,8,SX_COUNT_PROP),
    SX_FIELD("grain_table_entry_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("redundant_grain_directory_sector","uint64",48,8,SX_ID),
    SX_FIELD("grain_directory_sector","uint64",56,8,SX_ID),
    SX_FIELD("overhead_sectors","uint64",64,8,SX_COUNT_PROP),
    SX_FIELD("unclean_shutdown","uint8",72,1,SX_FLAGS),
    SX_FIELD("single_end_line_char","uint8",73,1,SX_NONE),
    SX_FIELD("non_end_line_char","uint8",74,1,SX_NONE),
    SX_FIELD("double_end_line_char1","uint8",75,1,SX_NONE),
    SX_FIELD("double_end_line_char2","uint8",76,1,SX_NONE),
    SX_FIELD("compression_algorithm","uint16",77,2,SX_ID),
    SX_FIELD("padding","byte[433]",79,433,SX_RESERVED),
};
static const sx_layout sx_dm_vmdk_sparse_header = {0x60290014U,"vmdk_sparse_header",sx_dm_vmdk_sparse_header_fields,SX_COUNT(sx_dm_vmdk_sparse_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vmdk_grain_directory_entry_fields[] = {
    SX_FIELD("grain_table_sector","uint32",0,4,SX_ID),
};
static const sx_layout sx_dm_vmdk_grain_directory_entry = {0x60290015U,"vmdk_grain_directory_entry",sx_dm_vmdk_grain_directory_entry_fields,SX_COUNT(sx_dm_vmdk_grain_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vmdk_grain_table_entry_fields[] = {
    SX_FIELD("grain_sector","uint32",0,4,SX_ID),
};
static const sx_layout sx_dm_vmdk_grain_table_entry = {0x60290016U,"vmdk_grain_table_entry",sx_dm_vmdk_grain_table_entry_fields,SX_COUNT(sx_dm_vmdk_grain_table_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vmdk_metadata_marker_fields[] = {
    SX_FIELD("sector_count","uint64",0,8,SX_COUNT_PROP),
    SX_FIELD("size","uint32",8,4,SX_SIZE),
    SX_FIELD("type","uint32",12,4,SX_ID),
};
static const sx_layout sx_dm_vmdk_metadata_marker = {0x60290017U,"vmdk_metadata_marker",sx_dm_vmdk_metadata_marker_fields,SX_COUNT(sx_dm_vmdk_metadata_marker_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vdi_preheader_fields[] = {
    SX_FIELD("text","char[64]",0,64,SX_NONE),
    SX_FIELD("signature","uint32",64,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",68,4,SX_NONE),
};
static const sx_layout sx_dm_vdi_preheader = {0x60290018U,"vdi_preheader",sx_dm_vdi_preheader_fields,SX_COUNT(sx_dm_vdi_preheader_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vdi_header_v1_fields[] = {
    SX_FIELD("header_size","uint32",0,4,SX_SIZE),
    SX_FIELD("image_type","uint32",4,4,SX_ID),
    SX_FIELD("flags","uint32",8,4,SX_FLAGS),
    SX_FIELD("description","char[256]",12,256,SX_NONE),
    SX_FIELD("block_map_offset","uint32",268,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",272,4,SX_OFFSET),
    SX_FIELD("cylinders","uint32",276,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",280,4,SX_COUNT_PROP),
    SX_FIELD("sectors","uint32",284,4,SX_COUNT_PROP),
    SX_FIELD("sector_size","uint32",288,4,SX_SIZE),
    SX_FIELD("reserved","uint32",292,4,SX_RESERVED),
    SX_FIELD("disk_size","uint64",296,8,SX_SIZE),
    SX_FIELD("block_size","uint32",304,4,SX_SIZE),
    SX_FIELD("block_extra","uint32",308,4,SX_SIZE),
    SX_FIELD("blocks_in_image","uint32",312,4,SX_COUNT_PROP),
    SX_FIELD("blocks_allocated","uint32",316,4,SX_COUNT_PROP),
    SX_FIELD("uuid_image","byte[16]",320,16,SX_ID),
    SX_FIELD("uuid_modify","byte[16]",336,16,SX_ID),
    SX_FIELD("uuid_linkage","byte[16]",352,16,SX_ID),
    SX_FIELD("uuid_parent_modify","byte[16]",368,16,SX_ID),
};
static const sx_layout sx_dm_vdi_header_v1 = {0x60290019U,"vdi_header_v1",sx_dm_vdi_header_v1_fields,SX_COUNT(sx_dm_vdi_header_v1_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_vdi_block_map_entry_fields[] = {
    SX_FIELD("block_index","uint32",0,4,SX_ID),
};
static const sx_layout sx_dm_vdi_block_map_entry = {0x6029001aU,"vdi_block_map_entry",sx_dm_vdi_block_map_entry_fields,SX_COUNT(sx_dm_vdi_block_map_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_qed_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("cluster_size","uint32",4,4,SX_SIZE),
    SX_FIELD("table_size_clusters","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("header_size_clusters","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("features","uint64",16,8,SX_FLAGS),
    SX_FIELD("compatible_features","uint64",24,8,SX_FLAGS),
    SX_FIELD("autoclear_features","uint64",32,8,SX_FLAGS),
    SX_FIELD("l1_table_offset","uint64",40,8,SX_OFFSET),
    SX_FIELD("image_size","uint64",48,8,SX_SIZE),
    SX_FIELD("backing_filename_offset","uint32",56,4,SX_OFFSET),
    SX_FIELD("backing_filename_size","uint32",60,4,SX_SIZE),
};
static const sx_layout sx_dm_qed_header = {0x6029001bU,"qed_header",sx_dm_qed_header_fields,SX_COUNT(sx_dm_qed_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_qed_l1_entry_fields[] = {
    SX_FIELD("l2_table_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sx_dm_qed_l1_entry = {0x6029001cU,"qed_l1_entry",sx_dm_qed_l1_entry_fields,SX_COUNT(sx_dm_qed_l1_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_qed_l2_entry_fields[] = {
    SX_FIELD("data_cluster_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sx_dm_qed_l2_entry = {0x6029001dU,"qed_l2_entry",sx_dm_qed_l2_entry_fields,SX_COUNT(sx_dm_qed_l2_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_parallels_header_extended_fields[] = {
    SX_FIELD("magic","byte[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("heads","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("cluster_sectors","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("bat_entries","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("sector_count","uint64",36,8,SX_COUNT_PROP),
    SX_FIELD("in_use","uint32",44,4,SX_ID),
    SX_FIELD("data_sector","uint32",48,4,SX_ID),
    SX_FIELD("flags","uint32",52,4,SX_FLAGS),
    SX_FIELD("extension_sector","uint64",56,8,SX_ID),
};
static const sx_layout sx_dm_parallels_header_extended = {0x6029001eU,"parallels_header_extended",sx_dm_parallels_header_extended_fields,SX_COUNT(sx_dm_parallels_header_extended_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_parallels_header_old_fields[] = {
    SX_FIELD("magic","byte[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("heads","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("cluster_sectors","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("bat_entries","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("sector_count","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("reserved_sector_count_high","uint32",40,4,SX_RESERVED),
    SX_FIELD("in_use","uint32",44,4,SX_ID),
    SX_FIELD("data_sector","uint32",48,4,SX_ID),
    SX_FIELD("flags","uint32",52,4,SX_FLAGS),
    SX_FIELD("extension_sector","uint64",56,8,SX_ID),
};
static const sx_layout sx_dm_parallels_header_old = {0x6029001fU,"parallels_header_old",sx_dm_parallels_header_old_fields,SX_COUNT(sx_dm_parallels_header_old_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_parallels_bat_sector_fields[] = {
    SX_FIELD("sector_index","uint32",0,4,SX_ID),
};
static const sx_layout sx_dm_parallels_bat_sector = {0x60290020U,"parallels_bat_sector",sx_dm_parallels_bat_sector_fields,SX_COUNT(sx_dm_parallels_bat_sector_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_parallels_bat_cluster_fields[] = {
    SX_FIELD("cluster_index","uint32",0,4,SX_ID),
};
static const sx_layout sx_dm_parallels_bat_cluster = {0x60290021U,"parallels_bat_cluster",sx_dm_parallels_bat_cluster_fields,SX_COUNT(sx_dm_parallels_bat_cluster_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_chd_header_v1_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("header_length","uint32",8,4,SX_SIZE),
    SX_FIELD("version","uint32",12,4,SX_NONE),
    SX_FIELD("flags","uint32",16,4,SX_FLAGS),
    SX_FIELD("compression","uint32",20,4,SX_ID),
    SX_FIELD("sectors_per_hunk","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("hunk_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("sectors","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("md5","byte[16]",44,16,SX_CHECKSUM),
    SX_FIELD("parent_md5","byte[16]",60,16,SX_CHECKSUM),
};
static const sx_layout sx_dm_chd_header_v1 = {0x60290022U,"chd_header_v1",sx_dm_chd_header_v1_fields,SX_COUNT(sx_dm_chd_header_v1_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_chd_header_v2_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("header_length","uint32",8,4,SX_SIZE),
    SX_FIELD("version","uint32",12,4,SX_NONE),
    SX_FIELD("flags","uint32",16,4,SX_FLAGS),
    SX_FIELD("compression","uint32",20,4,SX_ID),
    SX_FIELD("sectors_per_hunk","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("hunk_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("sectors","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("md5","byte[16]",44,16,SX_CHECKSUM),
    SX_FIELD("parent_md5","byte[16]",60,16,SX_CHECKSUM),
    SX_FIELD("sector_bytes","uint32",76,4,SX_SIZE),
};
static const sx_layout sx_dm_chd_header_v2 = {0x60290023U,"chd_header_v2",sx_dm_chd_header_v2_fields,SX_COUNT(sx_dm_chd_header_v2_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_chd_header_v3_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("header_length","uint32",8,4,SX_SIZE),
    SX_FIELD("version","uint32",12,4,SX_NONE),
    SX_FIELD("flags","uint32",16,4,SX_FLAGS),
    SX_FIELD("compression","uint32",20,4,SX_ID),
    SX_FIELD("hunk_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("logical_bytes","uint64",28,8,SX_SIZE),
    SX_FIELD("metadata_offset","uint64",36,8,SX_OFFSET),
    SX_FIELD("md5","byte[16]",44,16,SX_CHECKSUM),
    SX_FIELD("parent_md5","byte[16]",60,16,SX_CHECKSUM),
    SX_FIELD("hunk_bytes","uint32",76,4,SX_SIZE),
    SX_FIELD("sha1","byte[20]",80,20,SX_CHECKSUM),
    SX_FIELD("parent_sha1","byte[20]",100,20,SX_CHECKSUM),
};
static const sx_layout sx_dm_chd_header_v3 = {0x60290024U,"chd_header_v3",sx_dm_chd_header_v3_fields,SX_COUNT(sx_dm_chd_header_v3_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_chd_header_v4_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("header_length","uint32",8,4,SX_SIZE),
    SX_FIELD("version","uint32",12,4,SX_NONE),
    SX_FIELD("flags","uint32",16,4,SX_FLAGS),
    SX_FIELD("compression","uint32",20,4,SX_ID),
    SX_FIELD("hunk_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("logical_bytes","uint64",28,8,SX_SIZE),
    SX_FIELD("metadata_offset","uint64",36,8,SX_OFFSET),
    SX_FIELD("hunk_bytes","uint32",44,4,SX_SIZE),
    SX_FIELD("sha1","byte[20]",48,20,SX_CHECKSUM),
    SX_FIELD("parent_sha1","byte[20]",68,20,SX_CHECKSUM),
    SX_FIELD("raw_sha1","byte[20]",88,20,SX_CHECKSUM),
};
static const sx_layout sx_dm_chd_header_v4 = {0x60290025U,"chd_header_v4",sx_dm_chd_header_v4_fields,SX_COUNT(sx_dm_chd_header_v4_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_chd_header_v5_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("header_length","uint32",8,4,SX_SIZE),
    SX_FIELD("version","uint32",12,4,SX_NONE),
    SX_FIELD("compressors","uint32[4]",16,16,SX_ID),
    SX_FIELD("logical_bytes","uint64",32,8,SX_SIZE),
    SX_FIELD("map_offset","uint64",40,8,SX_OFFSET),
    SX_FIELD("metadata_offset","uint64",48,8,SX_OFFSET),
    SX_FIELD("hunk_bytes","uint32",56,4,SX_SIZE),
    SX_FIELD("unit_bytes","uint32",60,4,SX_SIZE),
    SX_FIELD("raw_sha1","byte[20]",64,20,SX_CHECKSUM),
    SX_FIELD("sha1","byte[20]",84,20,SX_CHECKSUM),
    SX_FIELD("parent_sha1","byte[20]",104,20,SX_CHECKSUM),
};
static const sx_layout sx_dm_chd_header_v5 = {0x60290026U,"chd_header_v5",sx_dm_chd_header_v5_fields,SX_COUNT(sx_dm_chd_header_v5_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_chd_map_v12_fields[] = {
    SX_FIELD("packed_offset_and_length","uint64",0,8,SX_FLAGS),
};
static const sx_layout sx_dm_chd_map_v12 = {0x60290027U,"chd_map_v12",sx_dm_chd_map_v12_fields,SX_COUNT(sx_dm_chd_map_v12_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_chd_map_v34_fields[] = {
    SX_FIELD("offset_or_reference","uint64",0,8,SX_ID),
    SX_FIELD("crc32","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("length_low","uint16",12,2,SX_NONE),
    SX_FIELD("length_high","uint8",14,1,SX_NONE),
    SX_FIELD("flags","uint8",15,1,SX_FLAGS),
};
static const sx_layout sx_dm_chd_map_v34 = {0x60290028U,"chd_map_v34",sx_dm_chd_map_v34_fields,SX_COUNT(sx_dm_chd_map_v34_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_chd_map_v5_uncompressed_fields[] = {
    SX_FIELD("hunk_index","uint32",0,4,SX_ID),
};
static const sx_layout sx_dm_chd_map_v5_uncompressed = {0x60290029U,"chd_map_v5_uncompressed",sx_dm_chd_map_v5_uncompressed_fields,SX_COUNT(sx_dm_chd_map_v5_uncompressed_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_chd_map_v5_compressed_header_fields[] = {
    SX_FIELD("compressed_length","uint32",0,4,SX_SIZE),
    SX_FIELD("first_data_offset","uint48",4,6,SX_OFFSET),
    SX_FIELD("crc16","uint16",10,2,SX_CHECKSUM),
    SX_FIELD("length_bits","uint8",12,1,SX_NONE),
    SX_FIELD("hunk_bits","uint8",13,1,SX_NONE),
    SX_FIELD("parent_unit_bits","uint8",14,1,SX_NONE),
    SX_FIELD("reserved","uint8",15,1,SX_RESERVED),
};
static const sx_layout sx_dm_chd_map_v5_compressed_header = {0x6029002aU,"chd_map_v5_compressed_header",sx_dm_chd_map_v5_compressed_header_fields,SX_COUNT(sx_dm_chd_map_v5_compressed_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_chd_metadata_header_fields[] = {
    SX_FIELD("tag","byte[4]",0,4,SX_ID),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("length","uint24",5,3,SX_SIZE),
    SX_FIELD("next_offset","uint64",8,8,SX_OFFSET),
};
static const sx_layout sx_dm_chd_metadata_header = {0x6029002bU,"chd_metadata_header",sx_dm_chd_metadata_header_fields,SX_COUNT(sx_dm_chd_metadata_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_udif_trailer_fields[] = {
    SX_FIELD("signature","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_NONE),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("flags","uint32",12,4,SX_FLAGS),
    SX_FIELD("running_data_fork_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("data_fork_offset","uint64",24,8,SX_OFFSET),
    SX_FIELD("data_fork_length","uint64",32,8,SX_SIZE),
    SX_FIELD("resource_fork_offset","uint64",40,8,SX_OFFSET),
    SX_FIELD("resource_fork_length","uint64",48,8,SX_SIZE),
    SX_FIELD("segment_number","uint32",56,4,SX_NONE),
    SX_FIELD("segment_count","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("segment_id","byte[16]",64,16,SX_ID),
    SX_FIELD("data_checksum_type","uint32",80,4,SX_ID),
    SX_FIELD("data_checksum_bits","uint32",84,4,SX_NONE),
    SX_FIELD("data_checksum","uint32[32]",88,128,SX_CHECKSUM),
    SX_FIELD("xml_offset","uint64",216,8,SX_OFFSET),
    SX_FIELD("xml_length","uint64",224,8,SX_SIZE),
    SX_FIELD("reserved1","byte[64]",232,64,SX_RESERVED),
    SX_FIELD("code_signature_offset","uint64",296,8,SX_OFFSET),
    SX_FIELD("code_signature_length","uint64",304,8,SX_SIZE),
    SX_FIELD("reserved2","byte[40]",312,40,SX_RESERVED),
    SX_FIELD("master_checksum_type","uint32",352,4,SX_ID),
    SX_FIELD("master_checksum_bits","uint32",356,4,SX_NONE),
    SX_FIELD("master_checksum","uint32[32]",360,128,SX_CHECKSUM),
    SX_FIELD("image_variant","uint32",488,4,SX_ID),
    SX_FIELD("sector_count","uint64",492,8,SX_COUNT_PROP),
    SX_FIELD("reserved3","byte[12]",500,12,SX_RESERVED),
};
static const sx_layout sx_dm_udif_trailer = {0x6029002cU,"udif_trailer",sx_dm_udif_trailer_fields,SX_COUNT(sx_dm_udif_trailer_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_cloop_header_fields[] = {
    SX_FIELD("preamble","char[128]",0,128,SX_NONE),
    SX_FIELD("block_size","uint32",128,4,SX_SIZE),
    SX_FIELD("block_count","uint32",132,4,SX_COUNT_PROP),
};
static const sx_layout sx_dm_cloop_header = {0x6029002dU,"cloop_header",sx_dm_cloop_header_fields,SX_COUNT(sx_dm_cloop_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_cloop_block_offset_fields[] = {
    SX_FIELD("offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sx_dm_cloop_block_offset = {0x6029002eU,"cloop_block_offset",sx_dm_cloop_block_offset_fields,SX_COUNT(sx_dm_cloop_block_offset_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_encrypted_dmg_v2_header_fields[] = {
    SX_FIELD("signature","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("version","uint32",8,4,SX_NONE),
    SX_FIELD("block_iv_length","uint32",12,4,SX_SIZE),
    SX_FIELD("block_mode","uint32",16,4,SX_ID),
    SX_FIELD("block_algorithm","uint32",20,4,SX_ID),
    SX_FIELD("key_bits","uint32",24,4,SX_NONE),
    SX_FIELD("iv_key_algorithm","uint32",28,4,SX_ID),
    SX_FIELD("iv_key_bits","uint32",32,4,SX_NONE),
    SX_FIELD("uuid","byte[16]",36,16,SX_ID),
    SX_FIELD("block_size","uint32",52,4,SX_SIZE),
    SX_FIELD("plaintext_length","uint64",56,8,SX_SIZE),
    SX_FIELD("data_offset","uint64",64,8,SX_OFFSET),
    SX_FIELD("key_count","uint32",72,4,SX_COUNT_PROP),
};
static const sx_layout sx_dm_encrypted_dmg_v2_header = {0x6029002fU,"encrypted_dmg_v2_header",sx_dm_encrypted_dmg_v2_header_fields,SX_COUNT(sx_dm_encrypted_dmg_v2_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_encrypted_dmg_key_pointer_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("offset","uint64",4,8,SX_OFFSET),
    SX_FIELD("size","uint64",12,8,SX_SIZE),
};
static const sx_layout sx_dm_encrypted_dmg_key_pointer = {0x60290030U,"encrypted_dmg_key_pointer",sx_dm_encrypted_dmg_key_pointer_fields,SX_COUNT(sx_dm_encrypted_dmg_key_pointer_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_encrypted_dmg_v1_trailer_fields[] = {
    SX_FIELD("unknown_prefix","byte[48]",0,48,SX_NONE),
    SX_FIELD("kdf_iterations","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("salt_length","uint32",52,4,SX_SIZE),
    SX_FIELD("salt","byte[48]",56,48,SX_NONE),
    SX_FIELD("unknown1","byte[32]",104,32,SX_NONE),
    SX_FIELD("wrapped_aes_key_length","uint32",136,4,SX_SIZE),
    SX_FIELD("wrapped_aes_key","byte[296]",140,296,SX_NONE),
    SX_FIELD("wrapped_hmac_key_length","uint32",436,4,SX_SIZE),
    SX_FIELD("wrapped_hmac_key","byte[300]",440,300,SX_NONE),
    SX_FIELD("integrity_key_length","uint32",740,4,SX_SIZE),
    SX_FIELD("integrity_key","byte[48]",744,48,SX_NONE),
    SX_FIELD("unknown2","byte[476]",792,476,SX_NONE),
    SX_FIELD("signature","byte[8]",1268,8,SX_SIGNATURE),
};
static const sx_layout sx_dm_encrypted_dmg_v1_trailer = {0x60290031U,"encrypted_dmg_v1_trailer",sx_dm_encrypted_dmg_v1_trailer_fields,SX_COUNT(sx_dm_encrypted_dmg_v1_trailer_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_ubi_erase_counter_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint8",4,1,SX_NONE),
    SX_FIELD("padding1","byte[3]",5,3,SX_RESERVED),
    SX_FIELD("erase_counter","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("vid_header_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",20,4,SX_OFFSET),
    SX_FIELD("image_sequence","uint32",24,4,SX_NONE),
    SX_FIELD("padding2","byte[32]",28,32,SX_RESERVED),
    SX_FIELD("header_crc","uint32",60,4,SX_CHECKSUM),
};
static const sx_layout sx_dm_ubi_erase_counter_header = {0x60290032U,"ubi_erase_counter_header",sx_dm_ubi_erase_counter_header_fields,SX_COUNT(sx_dm_ubi_erase_counter_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_ubi_volume_identifier_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint8",4,1,SX_NONE),
    SX_FIELD("volume_type","uint8",5,1,SX_ID),
    SX_FIELD("copy_flag","uint8",6,1,SX_FLAGS),
    SX_FIELD("compatibility","uint8",7,1,SX_ID),
    SX_FIELD("volume_id","uint32",8,4,SX_ID),
    SX_FIELD("logical_block_number","uint32",12,4,SX_ID),
    SX_FIELD("padding1","byte[4]",16,4,SX_RESERVED),
    SX_FIELD("data_size","uint32",20,4,SX_SIZE),
    SX_FIELD("used_eraseblocks","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("data_padding","uint32",28,4,SX_SIZE),
    SX_FIELD("data_crc","uint32",32,4,SX_CHECKSUM),
    SX_FIELD("padding2","byte[4]",36,4,SX_RESERVED),
    SX_FIELD("sequence_number","uint64",40,8,SX_NONE),
    SX_FIELD("padding3","byte[12]",48,12,SX_RESERVED),
    SX_FIELD("header_crc","uint32",60,4,SX_CHECKSUM),
};
static const sx_layout sx_dm_ubi_volume_identifier_header = {0x60290033U,"ubi_volume_identifier_header",sx_dm_ubi_volume_identifier_header_fields,SX_COUNT(sx_dm_ubi_volume_identifier_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_ubi_volume_table_record_fields[] = {
    SX_FIELD("reserved_pebs","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("alignment","uint32",4,4,SX_SIZE),
    SX_FIELD("data_padding","uint32",8,4,SX_SIZE),
    SX_FIELD("volume_type","uint8",12,1,SX_ID),
    SX_FIELD("update_marker","uint8",13,1,SX_FLAGS),
    SX_FIELD("name_length","uint16",14,2,SX_SIZE),
    SX_FIELD("name","char[128]",16,128,SX_NONE),
    SX_FIELD("flags","uint8",144,1,SX_FLAGS),
    SX_FIELD("padding","byte[23]",145,23,SX_RESERVED),
    SX_FIELD("crc","uint32",168,4,SX_CHECKSUM),
};
static const sx_layout sx_dm_ubi_volume_table_record = {0x60290034U,"ubi_volume_table_record",sx_dm_ubi_volume_table_record_fields,SX_COUNT(sx_dm_ubi_volume_table_record_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_ubifs_common_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
};
static const sx_layout sx_dm_ubifs_common_header = {0x60290035U,"ubifs_common_header",sx_dm_ubifs_common_header_fields,SX_COUNT(sx_dm_ubifs_common_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_ubifs_superblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("padding1","byte[2]",24,2,SX_RESERVED),
    SX_FIELD("key_hash","uint8",26,1,SX_ID),
    SX_FIELD("key_format","uint8",27,1,SX_ID),
    SX_FIELD("flags","uint32",28,4,SX_FLAGS),
    SX_FIELD("min_io_size","uint32",32,4,SX_SIZE),
    SX_FIELD("leb_size","uint32",36,4,SX_SIZE),
    SX_FIELD("leb_count","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("max_leb_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("max_bud_bytes","uint64",48,8,SX_SIZE),
    SX_FIELD("log_lebs","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("lpt_lebs","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("orphan_lebs","uint32",64,4,SX_COUNT_PROP),
    SX_FIELD("journal_head_count","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("fanout","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("lsave_count","uint32",76,4,SX_COUNT_PROP),
    SX_FIELD("format_version","uint32",80,4,SX_NONE),
    SX_FIELD("default_compression","uint16",84,2,SX_ID),
    SX_FIELD("padding2","byte[2]",86,2,SX_RESERVED),
    SX_FIELD("reserve_pool_uid","uint32",88,4,SX_ID),
    SX_FIELD("reserve_pool_gid","uint32",92,4,SX_ID),
    SX_FIELD("reserve_pool_size","uint64",96,8,SX_SIZE),
    SX_FIELD("time_granularity_ns","uint32",104,4,SX_NONE),
    SX_FIELD("uuid","byte[16]",108,16,SX_ID),
    SX_FIELD("ro_compat_version","uint32",124,4,SX_NONE),
    SX_FIELD("hmac","byte[64]",128,64,SX_SIGNATURE),
    SX_FIELD("hmac_well_known_message","byte[64]",192,64,SX_SIGNATURE),
    SX_FIELD("hash_algorithm","uint16",256,2,SX_ID),
    SX_FIELD("master_node_hash","byte[64]",258,64,SX_CHECKSUM),
    SX_FIELD("padding3","byte[3774]",322,3774,SX_RESERVED),
};
static const sx_layout sx_dm_ubifs_superblock = {0x60290036U,"ubifs_superblock",sx_dm_ubifs_superblock_fields,SX_COUNT(sx_dm_ubifs_superblock_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_ubifs_master_node_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("highest_inode_number","uint64",24,8,SX_ID),
    SX_FIELD("commit_number","uint64",32,8,SX_NONE),
    SX_FIELD("flags","uint32",40,4,SX_FLAGS),
    SX_FIELD("log_lnum","uint32",44,4,SX_ID),
    SX_FIELD("root_lnum","uint32",48,4,SX_ID),
    SX_FIELD("root_offset","uint32",52,4,SX_OFFSET),
    SX_FIELD("root_length","uint32",56,4,SX_SIZE),
    SX_FIELD("gc_lnum","uint32",60,4,SX_ID),
    SX_FIELD("index_head_lnum","uint32",64,4,SX_ID),
    SX_FIELD("index_head_offset","uint32",68,4,SX_OFFSET),
    SX_FIELD("index_size","uint64",72,8,SX_SIZE),
    SX_FIELD("total_free","uint64",80,8,SX_SIZE),
    SX_FIELD("total_dirty","uint64",88,8,SX_SIZE),
    SX_FIELD("total_used","uint64",96,8,SX_SIZE),
    SX_FIELD("total_dead","uint64",104,8,SX_SIZE),
    SX_FIELD("total_dark","uint64",112,8,SX_SIZE),
    SX_FIELD("lpt_lnum","uint32",120,4,SX_ID),
    SX_FIELD("lpt_offset","uint32",124,4,SX_OFFSET),
    SX_FIELD("nhead_lnum","uint32",128,4,SX_ID),
    SX_FIELD("nhead_offset","uint32",132,4,SX_OFFSET),
    SX_FIELD("ltab_lnum","uint32",136,4,SX_ID),
    SX_FIELD("ltab_offset","uint32",140,4,SX_OFFSET),
    SX_FIELD("lsave_lnum","uint32",144,4,SX_ID),
    SX_FIELD("lsave_offset","uint32",148,4,SX_OFFSET),
    SX_FIELD("lscan_lnum","uint32",152,4,SX_ID),
    SX_FIELD("empty_lebs","uint32",156,4,SX_COUNT_PROP),
    SX_FIELD("index_lebs","uint32",160,4,SX_COUNT_PROP),
    SX_FIELD("leb_count","uint32",164,4,SX_COUNT_PROP),
    SX_FIELD("root_index_hash","byte[64]",168,64,SX_CHECKSUM),
    SX_FIELD("lpt_hash","byte[64]",232,64,SX_CHECKSUM),
    SX_FIELD("hmac","byte[64]",296,64,SX_SIGNATURE),
    SX_FIELD("padding1","byte[152]",360,152,SX_RESERVED),
};
static const sx_layout sx_dm_ubifs_master_node = {0x60290037U,"ubifs_master_node",sx_dm_ubifs_master_node_fields,SX_COUNT(sx_dm_ubifs_master_node_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_ubifs_index_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("child_count","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("level","uint16",26,2,SX_NONE),
};
static const sx_layout sx_dm_ubifs_index_header = {0x60290038U,"ubifs_index_header",sx_dm_ubifs_index_header_fields,SX_COUNT(sx_dm_ubifs_index_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_ubifs_index_branch_fields[] = {
    SX_FIELD("logical_block_number","uint32",0,4,SX_ID),
    SX_FIELD("offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("length","uint32",8,4,SX_SIZE),
    SX_FIELD("key_inode","uint32",12,4,SX_ID),
    SX_FIELD("key_type_and_value","uint32",16,4,SX_FLAGS),
};
static const sx_layout sx_dm_ubifs_index_branch = {0x60290039U,"ubifs_index_branch",sx_dm_ubifs_index_branch_fields,SX_COUNT(sx_dm_ubifs_index_branch_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_ubifs_inode_node_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("key_inode","uint32",24,4,SX_ID),
    SX_FIELD("key_type_and_value","uint32",28,4,SX_FLAGS),
    SX_FIELD("key_padding","byte[8]",32,8,SX_RESERVED),
    SX_FIELD("creation_sequence_number","uint64",40,8,SX_NONE),
    SX_FIELD("size","uint64",48,8,SX_SIZE),
    SX_FIELD("access_time_seconds","int64",56,8,SX_TIME),
    SX_FIELD("change_time_seconds","int64",64,8,SX_TIME),
    SX_FIELD("modification_time_seconds","int64",72,8,SX_TIME),
    SX_FIELD("access_time_nanoseconds","uint32",80,4,SX_NONE),
    SX_FIELD("change_time_nanoseconds","uint32",84,4,SX_NONE),
    SX_FIELD("modification_time_nanoseconds","uint32",88,4,SX_NONE),
    SX_FIELD("link_count","uint32",92,4,SX_COUNT_PROP),
    SX_FIELD("uid","uint32",96,4,SX_ID),
    SX_FIELD("gid","uint32",100,4,SX_ID),
    SX_FIELD("mode","uint32",104,4,SX_FLAGS),
    SX_FIELD("flags","uint32",108,4,SX_FLAGS),
    SX_FIELD("data_length","uint32",112,4,SX_SIZE),
    SX_FIELD("xattr_count","uint32",116,4,SX_COUNT_PROP),
    SX_FIELD("xattr_size","uint32",120,4,SX_SIZE),
    SX_FIELD("padding1","byte[4]",124,4,SX_RESERVED),
    SX_FIELD("xattr_names_length","uint32",128,4,SX_SIZE),
    SX_FIELD("compression_type","uint16",132,2,SX_ID),
    SX_FIELD("padding2","byte[26]",134,26,SX_RESERVED),
};
static const sx_layout sx_dm_ubifs_inode_node = {0x6029003aU,"ubifs_inode_node",sx_dm_ubifs_inode_node_fields,SX_COUNT(sx_dm_ubifs_inode_node_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_ubifs_directory_entry_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("key_inode","uint32",24,4,SX_ID),
    SX_FIELD("key_type_and_value","uint32",28,4,SX_FLAGS),
    SX_FIELD("key_padding","byte[8]",32,8,SX_RESERVED),
    SX_FIELD("inode_number","uint64",40,8,SX_ID),
    SX_FIELD("padding1","uint8",48,1,SX_RESERVED),
    SX_FIELD("type","uint8",49,1,SX_ID),
    SX_FIELD("name_length","uint16",50,2,SX_SIZE),
    SX_FIELD("cookie","uint32",52,4,SX_ID),
};
static const sx_layout sx_dm_ubifs_directory_entry = {0x6029003bU,"ubifs_directory_entry",sx_dm_ubifs_directory_entry_fields,SX_COUNT(sx_dm_ubifs_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_ubifs_data_node_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("key_inode","uint32",24,4,SX_ID),
    SX_FIELD("key_type_and_value","uint32",28,4,SX_FLAGS),
    SX_FIELD("key_padding","byte[8]",32,8,SX_RESERVED),
    SX_FIELD("uncompressed_size","uint32",40,4,SX_SIZE),
    SX_FIELD("compression_type","uint16",44,2,SX_ID),
    SX_FIELD("compressed_size","uint16",46,2,SX_SIZE),
};
static const sx_layout sx_dm_ubifs_data_node = {0x6029003cU,"ubifs_data_node",sx_dm_ubifs_data_node_fields,SX_COUNT(sx_dm_ubifs_data_node_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_ubifs_padding_node_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("padding_length","uint32",24,4,SX_SIZE),
};
static const sx_layout sx_dm_ubifs_padding_node = {0x6029003dU,"ubifs_padding_node",sx_dm_ubifs_padding_node_fields,SX_COUNT(sx_dm_ubifs_padding_node_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_ubifs_commit_start_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("commit_number","uint64",24,8,SX_NONE),
};
static const sx_layout sx_dm_ubifs_commit_start = {0x6029003eU,"ubifs_commit_start",sx_dm_ubifs_commit_start_fields,SX_COUNT(sx_dm_ubifs_commit_start_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_ubifs_reference_node_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("crc","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("sequence_number","uint64",8,8,SX_NONE),
    SX_FIELD("length","uint32",16,4,SX_SIZE),
    SX_FIELD("node_type","uint8",20,1,SX_ID),
    SX_FIELD("group_type","uint8",21,1,SX_ID),
    SX_FIELD("padding","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("logical_block_number","uint32",24,4,SX_ID),
    SX_FIELD("offset","uint32",28,4,SX_OFFSET),
    SX_FIELD("journal_head","uint32",32,4,SX_ID),
    SX_FIELD("padding1","byte[28]",36,28,SX_RESERVED),
};
static const sx_layout sx_dm_ubifs_reference_node = {0x6029003fU,"ubifs_reference_node",sx_dm_ubifs_reference_node_fields,SX_COUNT(sx_dm_ubifs_reference_node_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_jffs2_common_header_le_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
};
static const sx_layout sx_dm_jffs2_common_header_le = {0x60290040U,"jffs2_common_header_le",sx_dm_jffs2_common_header_le_fields,SX_COUNT(sx_dm_jffs2_common_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_jffs2_directory_entry_le_fields[] = {
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
static const sx_layout sx_dm_jffs2_directory_entry_le = {0x60290041U,"jffs2_directory_entry_le",sx_dm_jffs2_directory_entry_le_fields,SX_COUNT(sx_dm_jffs2_directory_entry_le_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_jffs2_inode_le_fields[] = {
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
static const sx_layout sx_dm_jffs2_inode_le = {0x60290042U,"jffs2_inode_le",sx_dm_jffs2_inode_le_fields,SX_COUNT(sx_dm_jffs2_inode_le_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_jffs2_xattr_le_fields[] = {
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
static const sx_layout sx_dm_jffs2_xattr_le = {0x60290043U,"jffs2_xattr_le",sx_dm_jffs2_xattr_le_fields,SX_COUNT(sx_dm_jffs2_xattr_le_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_jffs2_xref_le_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("inode","uint32",12,4,SX_ID),
    SX_FIELD("xid","uint32",16,4,SX_ID),
    SX_FIELD("sequence_number","uint32",20,4,SX_NONE),
    SX_FIELD("node_crc","uint32",24,4,SX_CHECKSUM),
};
static const sx_layout sx_dm_jffs2_xref_le = {0x60290044U,"jffs2_xref_le",sx_dm_jffs2_xref_le_fields,SX_COUNT(sx_dm_jffs2_xref_le_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_yaffs_object_header_le_fields[] = {
    SX_FIELD("object_type","uint32",0,4,SX_ID),
    SX_FIELD("parent_object_id","uint32",4,4,SX_ID),
    SX_FIELD("obsolete_name_checksum","uint16",8,2,SX_RESERVED),
    SX_FIELD("name","byte[256]",10,256,SX_NONE),
    SX_FIELD("alignment_padding","byte[2]",266,2,SX_RESERVED),
    SX_FIELD("mode","uint32",268,4,SX_FLAGS),
    SX_FIELD("uid","uint32",272,4,SX_ID),
    SX_FIELD("gid","uint32",276,4,SX_ID),
    SX_FIELD("access_time","uint32",280,4,SX_TIME),
    SX_FIELD("modification_time","uint32",284,4,SX_TIME),
    SX_FIELD("change_time","uint32",288,4,SX_TIME),
    SX_FIELD("file_size_low","uint32",292,4,SX_NONE),
    SX_FIELD("equivalent_object_id","int32",296,4,SX_ID),
    SX_FIELD("alias","byte[160]",300,160,SX_NONE),
    SX_FIELD("device_id","uint32",460,4,SX_ID),
    SX_FIELD("wince_change_time_words","uint32[2]",464,8,SX_NONE),
    SX_FIELD("wince_access_time_words","uint32[2]",472,8,SX_NONE),
    SX_FIELD("wince_modification_time_words","uint32[2]",480,8,SX_NONE),
    SX_FIELD("inband_shadowed_object_id","uint32",488,4,SX_ID),
    SX_FIELD("inband_is_shrink","uint32",492,4,SX_FLAGS),
    SX_FIELD("file_size_high","uint32",496,4,SX_NONE),
    SX_FIELD("reserved","uint32",500,4,SX_RESERVED),
    SX_FIELD("shadows_object","int32",504,4,SX_ID),
    SX_FIELD("is_shrink","uint32",508,4,SX_FLAGS),
};
static const sx_layout sx_dm_yaffs_object_header_le = {0x60290045U,"yaffs_object_header_le",sx_dm_yaffs_object_header_le_fields,SX_COUNT(sx_dm_yaffs_object_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_qnx6_superblock_header_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("serial","uint64",8,8,SX_NONE),
    SX_FIELD("creation_time","uint32",16,4,SX_TIME),
    SX_FIELD("access_time","uint32",20,4,SX_TIME),
    SX_FIELD("flags","uint32",24,4,SX_FLAGS),
    SX_FIELD("version1","uint16",28,2,SX_NONE),
    SX_FIELD("version2","uint16",30,2,SX_NONE),
    SX_FIELD("volume_id","byte[16]",32,16,SX_ID),
    SX_FIELD("block_size","uint32",48,4,SX_SIZE),
    SX_FIELD("inode_count","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("free_inodes","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("block_count","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("free_blocks","uint32",64,4,SX_COUNT_PROP),
    SX_FIELD("allocation_group","uint32",68,4,SX_NONE),
};
static const sx_layout sx_dm_qnx6_superblock_header_le = {0x60290046U,"qnx6_superblock_header_le",sx_dm_qnx6_superblock_header_le_fields,SX_COUNT(sx_dm_qnx6_superblock_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_qnx6_root_node_le_fields[] = {
    SX_FIELD("size","uint64",0,8,SX_SIZE),
    SX_FIELD("block_pointers","uint32[16]",8,64,SX_ID),
    SX_FIELD("levels","uint8",72,1,SX_NONE),
    SX_FIELD("mode","uint8",73,1,SX_FLAGS),
    SX_FIELD("spare","byte[6]",74,6,SX_RESERVED),
};
static const sx_layout sx_dm_qnx6_root_node_le = {0x60290047U,"qnx6_root_node_le",sx_dm_qnx6_root_node_le_fields,SX_COUNT(sx_dm_qnx6_root_node_le_fields),SX_LE};

static const xx_data_struct_field_desc sx_dm_jffs2_common_header_be_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
};
static const sx_layout sx_dm_jffs2_common_header_be = {0x60290048U,"jffs2_common_header_be",sx_dm_jffs2_common_header_be_fields,SX_COUNT(sx_dm_jffs2_common_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_jffs2_directory_entry_be_fields[] = {
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
static const sx_layout sx_dm_jffs2_directory_entry_be = {0x60290049U,"jffs2_directory_entry_be",sx_dm_jffs2_directory_entry_be_fields,SX_COUNT(sx_dm_jffs2_directory_entry_be_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_jffs2_inode_be_fields[] = {
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
static const sx_layout sx_dm_jffs2_inode_be = {0x6029004aU,"jffs2_inode_be",sx_dm_jffs2_inode_be_fields,SX_COUNT(sx_dm_jffs2_inode_be_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_jffs2_xattr_be_fields[] = {
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
static const sx_layout sx_dm_jffs2_xattr_be = {0x6029004bU,"jffs2_xattr_be",sx_dm_jffs2_xattr_be_fields,SX_COUNT(sx_dm_jffs2_xattr_be_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_jffs2_xref_be_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("inode","uint32",12,4,SX_ID),
    SX_FIELD("xid","uint32",16,4,SX_ID),
    SX_FIELD("sequence_number","uint32",20,4,SX_NONE),
    SX_FIELD("node_crc","uint32",24,4,SX_CHECKSUM),
};
static const sx_layout sx_dm_jffs2_xref_be = {0x6029004cU,"jffs2_xref_be",sx_dm_jffs2_xref_be_fields,SX_COUNT(sx_dm_jffs2_xref_be_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_yaffs_object_header_be_fields[] = {
    SX_FIELD("object_type","uint32",0,4,SX_ID),
    SX_FIELD("parent_object_id","uint32",4,4,SX_ID),
    SX_FIELD("obsolete_name_checksum","uint16",8,2,SX_RESERVED),
    SX_FIELD("name","byte[256]",10,256,SX_NONE),
    SX_FIELD("alignment_padding","byte[2]",266,2,SX_RESERVED),
    SX_FIELD("mode","uint32",268,4,SX_FLAGS),
    SX_FIELD("uid","uint32",272,4,SX_ID),
    SX_FIELD("gid","uint32",276,4,SX_ID),
    SX_FIELD("access_time","uint32",280,4,SX_TIME),
    SX_FIELD("modification_time","uint32",284,4,SX_TIME),
    SX_FIELD("change_time","uint32",288,4,SX_TIME),
    SX_FIELD("file_size_low","uint32",292,4,SX_NONE),
    SX_FIELD("equivalent_object_id","int32",296,4,SX_ID),
    SX_FIELD("alias","byte[160]",300,160,SX_NONE),
    SX_FIELD("device_id","uint32",460,4,SX_ID),
    SX_FIELD("wince_change_time_words","uint32[2]",464,8,SX_NONE),
    SX_FIELD("wince_access_time_words","uint32[2]",472,8,SX_NONE),
    SX_FIELD("wince_modification_time_words","uint32[2]",480,8,SX_NONE),
    SX_FIELD("inband_shadowed_object_id","uint32",488,4,SX_ID),
    SX_FIELD("inband_is_shrink","uint32",492,4,SX_FLAGS),
    SX_FIELD("file_size_high","uint32",496,4,SX_NONE),
    SX_FIELD("reserved","uint32",500,4,SX_RESERVED),
    SX_FIELD("shadows_object","int32",504,4,SX_ID),
    SX_FIELD("is_shrink","uint32",508,4,SX_FLAGS),
};
static const sx_layout sx_dm_yaffs_object_header_be = {0x6029004dU,"yaffs_object_header_be",sx_dm_yaffs_object_header_be_fields,SX_COUNT(sx_dm_yaffs_object_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_qnx6_superblock_header_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("serial","uint64",8,8,SX_NONE),
    SX_FIELD("creation_time","uint32",16,4,SX_TIME),
    SX_FIELD("access_time","uint32",20,4,SX_TIME),
    SX_FIELD("flags","uint32",24,4,SX_FLAGS),
    SX_FIELD("version1","uint16",28,2,SX_NONE),
    SX_FIELD("version2","uint16",30,2,SX_NONE),
    SX_FIELD("volume_id","byte[16]",32,16,SX_ID),
    SX_FIELD("block_size","uint32",48,4,SX_SIZE),
    SX_FIELD("inode_count","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("free_inodes","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("block_count","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("free_blocks","uint32",64,4,SX_COUNT_PROP),
    SX_FIELD("allocation_group","uint32",68,4,SX_NONE),
};
static const sx_layout sx_dm_qnx6_superblock_header_be = {0x6029004eU,"qnx6_superblock_header_be",sx_dm_qnx6_superblock_header_be_fields,SX_COUNT(sx_dm_qnx6_superblock_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_qnx6_root_node_be_fields[] = {
    SX_FIELD("size","uint64",0,8,SX_SIZE),
    SX_FIELD("block_pointers","uint32[16]",8,64,SX_ID),
    SX_FIELD("levels","uint8",72,1,SX_NONE),
    SX_FIELD("mode","uint8",73,1,SX_FLAGS),
    SX_FIELD("spare","byte[6]",74,6,SX_RESERVED),
};
static const sx_layout sx_dm_qnx6_root_node_be = {0x6029004fU,"qnx6_root_node_be",sx_dm_qnx6_root_node_be_fields,SX_COUNT(sx_dm_qnx6_root_node_be_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_logfs_superblock_fields[] = {
    SX_FIELD("segment_crc","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("segment_padding","uint16",4,2,SX_RESERVED),
    SX_FIELD("segment_type","uint8",6,1,SX_ID),
    SX_FIELD("level","uint8",7,1,SX_NONE),
    SX_FIELD("segment_number","uint32",8,4,SX_ID),
    SX_FIELD("erase_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("global_erase_count","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("magic","uint64",24,8,SX_SIGNATURE),
    SX_FIELD("superblock_crc","uint32",32,4,SX_CHECKSUM),
    SX_FIELD("inode_file_levels","uint8",36,1,SX_NONE),
    SX_FIELD("inode_block_levels","uint8",37,1,SX_NONE),
    SX_FIELD("data_levels","uint8",38,1,SX_NONE),
    SX_FIELD("segment_shift","uint8",39,1,SX_NONE),
    SX_FIELD("block_shift","uint8",40,1,SX_NONE),
    SX_FIELD("write_shift","uint8",41,1,SX_NONE),
    SX_FIELD("padding0","byte[6]",42,6,SX_RESERVED),
    SX_FIELD("filesystem_size","uint64",48,8,SX_SIZE),
    SX_FIELD("segment_size","uint32",56,4,SX_SIZE),
    SX_FIELD("bad_segment_reserve","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("incompatible_features","uint64",64,8,SX_FLAGS),
    SX_FIELD("ro_compatible_features","uint64",72,8,SX_FLAGS),
    SX_FIELD("compatible_features","uint64",80,8,SX_FLAGS),
    SX_FIELD("feature_flags","uint64",88,8,SX_FLAGS),
    SX_FIELD("root_reserve","uint64",96,8,SX_SIZE),
    SX_FIELD("speed_reserve","uint64",104,8,SX_SIZE),
    SX_FIELD("journal_segments","uint32[16]",112,64,SX_ID),
    SX_FIELD("superblock_offsets","uint64[2]",176,16,SX_OFFSET),
    SX_FIELD("padding3","byte[64]",192,64,SX_RESERVED),
};
static const sx_layout sx_dm_logfs_superblock = {0x60290050U,"logfs_superblock",sx_dm_logfs_superblock_fields,SX_COUNT(sx_dm_logfs_superblock_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_apm_driver_descriptor_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("block_size","uint16",2,2,SX_SIZE),
    SX_FIELD("block_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("device_type","uint16",8,2,SX_ID),
    SX_FIELD("device_id","uint16",10,2,SX_ID),
    SX_FIELD("reserved_data","uint32",12,4,SX_RESERVED),
    SX_FIELD("driver_count","uint16",16,2,SX_COUNT_PROP),
};
static const sx_layout sx_dm_apm_driver_descriptor_header = {0x60290051U,"apm_driver_descriptor_header",sx_dm_apm_driver_descriptor_header_fields,SX_COUNT(sx_dm_apm_driver_descriptor_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_apm_driver_descriptor_fields[] = {
    SX_FIELD("driver_block","uint32",0,4,SX_ID),
    SX_FIELD("driver_size_sectors","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("driver_type","uint16",6,2,SX_ID),
};
static const sx_layout sx_dm_apm_driver_descriptor = {0x60290052U,"apm_driver_descriptor",sx_dm_apm_driver_descriptor_fields,SX_COUNT(sx_dm_apm_driver_descriptor_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_apm_partition_entry_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("signature_padding","uint16",2,2,SX_RESERVED),
    SX_FIELD("map_block_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("physical_partition_start_block","uint32",8,4,SX_ID),
    SX_FIELD("partition_block_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("partition_name","char[32]",16,32,SX_NONE),
    SX_FIELD("partition_type","char[32]",48,32,SX_NONE),
    SX_FIELD("logical_data_start_block","uint32",80,4,SX_ID),
    SX_FIELD("data_block_count","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("partition_status","uint32",88,4,SX_FLAGS),
    SX_FIELD("logical_boot_start_block","uint32",92,4,SX_ID),
    SX_FIELD("boot_size","uint32",96,4,SX_SIZE),
    SX_FIELD("boot_load_address","uint32",100,4,SX_ADDRESS),
    SX_FIELD("boot_load_address2","uint32",104,4,SX_ADDRESS),
    SX_FIELD("boot_entry_address","uint32",108,4,SX_ADDRESS),
    SX_FIELD("boot_entry_address2","uint32",112,4,SX_ADDRESS),
    SX_FIELD("boot_checksum","uint32",116,4,SX_CHECKSUM),
    SX_FIELD("processor","char[16]",120,16,SX_NONE),
    SX_FIELD("padding","byte[376]",136,376,SX_RESERVED),
};
static const sx_layout sx_dm_apm_partition_entry = {0x60290053U,"apm_partition_entry",sx_dm_apm_partition_entry_fields,SX_COUNT(sx_dm_apm_partition_entry_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_rdb_rigid_disk_block_fields[] = {
    SX_FIELD("identifier","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("summed_longs","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("checksum","int32",8,4,SX_CHECKSUM),
    SX_FIELD("host_id","uint32",12,4,SX_ID),
    SX_FIELD("block_bytes","uint32",16,4,SX_SIZE),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("bad_block_list","uint32",24,4,SX_ID),
    SX_FIELD("partition_list","uint32",28,4,SX_ID),
    SX_FIELD("filesystem_header_list","uint32",32,4,SX_ID),
    SX_FIELD("drive_init","uint32",36,4,SX_ID),
    SX_FIELD("reserved1","uint32[6]",40,24,SX_RESERVED),
    SX_FIELD("cylinders","uint32",64,4,SX_COUNT_PROP),
    SX_FIELD("sectors","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("interleave","uint32",76,4,SX_NONE),
    SX_FIELD("parking_zone","uint32",80,4,SX_ID),
    SX_FIELD("reserved2","uint32[3]",84,12,SX_RESERVED),
    SX_FIELD("write_precompensation_cylinder","uint32",96,4,SX_ID),
    SX_FIELD("reduced_write_cylinder","uint32",100,4,SX_ID),
    SX_FIELD("step_rate","uint32",104,4,SX_NONE),
    SX_FIELD("reserved3","uint32[5]",108,20,SX_RESERVED),
    SX_FIELD("rdb_blocks_low","uint32",128,4,SX_ID),
    SX_FIELD("rdb_blocks_high","uint32",132,4,SX_ID),
    SX_FIELD("low_cylinder","uint32",136,4,SX_ID),
    SX_FIELD("high_cylinder","uint32",140,4,SX_ID),
    SX_FIELD("cylinder_blocks","uint32",144,4,SX_COUNT_PROP),
    SX_FIELD("autopark_seconds","uint32",148,4,SX_NONE),
    SX_FIELD("highest_rdb_block","uint32",152,4,SX_ID),
    SX_FIELD("reserved4","uint32",156,4,SX_RESERVED),
    SX_FIELD("disk_vendor","char[8]",160,8,SX_NONE),
    SX_FIELD("disk_product","char[16]",168,16,SX_NONE),
    SX_FIELD("disk_revision","char[4]",184,4,SX_NONE),
    SX_FIELD("controller_vendor","char[8]",188,8,SX_NONE),
    SX_FIELD("controller_product","char[16]",196,16,SX_NONE),
    SX_FIELD("controller_revision","char[4]",212,4,SX_NONE),
    SX_FIELD("reserved5","uint32[10]",216,40,SX_RESERVED),
};
static const sx_layout sx_dm_rdb_rigid_disk_block = {0x60290054U,"rdb_rigid_disk_block",sx_dm_rdb_rigid_disk_block_fields,SX_COUNT(sx_dm_rdb_rigid_disk_block_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_rdb_partition_block_fields[] = {
    SX_FIELD("identifier","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("summed_longs","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("checksum","int32",8,4,SX_CHECKSUM),
    SX_FIELD("host_id","uint32",12,4,SX_ID),
    SX_FIELD("next_block","uint32",16,4,SX_ID),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("reserved1","uint32[2]",24,8,SX_RESERVED),
    SX_FIELD("device_flags","uint32",32,4,SX_FLAGS),
    SX_FIELD("drive_name_bcpl","byte[32]",36,32,SX_NONE),
    SX_FIELD("reserved2","uint32[15]",68,60,SX_RESERVED),
    SX_FIELD("environment_table_size","uint32",128,4,SX_COUNT_PROP),
    SX_FIELD("longs_per_sector","uint32",132,4,SX_COUNT_PROP),
    SX_FIELD("sector_origin","uint32",136,4,SX_ID),
    SX_FIELD("surfaces","uint32",140,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_block","uint32",144,4,SX_COUNT_PROP),
    SX_FIELD("blocks_per_track","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("reserved_blocks","uint32",152,4,SX_COUNT_PROP),
    SX_FIELD("preallocated_blocks","uint32",156,4,SX_COUNT_PROP),
    SX_FIELD("interleave","uint32",160,4,SX_NONE),
    SX_FIELD("low_cylinder","uint32",164,4,SX_ID),
    SX_FIELD("high_cylinder","uint32",168,4,SX_ID),
    SX_FIELD("buffer_count","uint32",172,4,SX_COUNT_PROP),
    SX_FIELD("buffer_memory_type","uint32",176,4,SX_FLAGS),
    SX_FIELD("max_transfer","uint32",180,4,SX_SIZE),
    SX_FIELD("address_mask","uint32",184,4,SX_FLAGS),
    SX_FIELD("boot_priority","int32",188,4,SX_NONE),
    SX_FIELD("dos_type","uint32",192,4,SX_ID),
    SX_FIELD("baud","uint32",196,4,SX_NONE),
    SX_FIELD("control","uint32",200,4,SX_FLAGS),
    SX_FIELD("boot_blocks","uint32",204,4,SX_COUNT_PROP),
    SX_FIELD("environment_reserved","uint32[12]",208,48,SX_RESERVED),
};
static const sx_layout sx_dm_rdb_partition_block = {0x60290055U,"rdb_partition_block",sx_dm_rdb_partition_block_fields,SX_COUNT(sx_dm_rdb_partition_block_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_rdb_filesystem_header_fields[] = {
    SX_FIELD("identifier","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("summed_longs","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("checksum","int32",8,4,SX_CHECKSUM),
    SX_FIELD("host_id","uint32",12,4,SX_ID),
    SX_FIELD("next_block","uint32",16,4,SX_ID),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("reserved1","uint32[2]",24,8,SX_RESERVED),
    SX_FIELD("dos_type","uint32",32,4,SX_ID),
    SX_FIELD("version","uint32",36,4,SX_NONE),
    SX_FIELD("patch_flags","uint32",40,4,SX_FLAGS),
    SX_FIELD("type","uint32",44,4,SX_ID),
    SX_FIELD("task","uint32",48,4,SX_POINTER),
    SX_FIELD("lock","uint32",52,4,SX_POINTER),
    SX_FIELD("handler","uint32",56,4,SX_POINTER),
    SX_FIELD("stack_size","uint32",60,4,SX_SIZE),
    SX_FIELD("priority","int32",64,4,SX_NONE),
    SX_FIELD("startup","int32",68,4,SX_POINTER),
    SX_FIELD("segment_list_block","int32",72,4,SX_ID),
    SX_FIELD("global_vector","int32",76,4,SX_NONE),
};
static const sx_layout sx_dm_rdb_filesystem_header = {0x60290056U,"rdb_filesystem_header",sx_dm_rdb_filesystem_header_fields,SX_COUNT(sx_dm_rdb_filesystem_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_rdb_load_segment_header_fields[] = {
    SX_FIELD("identifier","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("summed_longs","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("checksum","int32",8,4,SX_CHECKSUM),
    SX_FIELD("host_id","uint32",12,4,SX_ID),
    SX_FIELD("next_block","uint32",16,4,SX_ID),
};
static const sx_layout sx_dm_rdb_load_segment_header = {0x60290057U,"rdb_load_segment_header",sx_dm_rdb_load_segment_header_fields,SX_COUNT(sx_dm_rdb_load_segment_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_ndif_bcem_header_fields[] = {
    SX_FIELD("major_version","uint16",0,2,SX_NONE),
    SX_FIELD("minor_version","uint16",2,2,SX_NONE),
    SX_FIELD("name_length","uint8",4,1,SX_SIZE),
    SX_FIELD("name","char[63]",5,63,SX_NONE),
    SX_FIELD("sector_count","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("chunk_size_sectors","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("bs_zero_offset","uint32",76,4,SX_OFFSET),
    SX_FIELD("checksum","uint32",80,4,SX_CHECKSUM),
    SX_FIELD("segmented","uint32",84,4,SX_FLAGS),
    SX_FIELD("unknown","byte[8]",88,8,SX_NONE),
    SX_FIELD("reserved","byte[28]",96,28,SX_RESERVED),
    SX_FIELD("chunk_count","uint32",124,4,SX_COUNT_PROP),
};
static const sx_layout sx_dm_ndif_bcem_header = {0x60290058U,"ndif_bcem_header",sx_dm_ndif_bcem_header_fields,SX_COUNT(sx_dm_ndif_bcem_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_ndif_chunk_entry_fields[] = {
    SX_FIELD("first_sector","uint24",0,3,SX_ID),
    SX_FIELD("type","uint8",3,1,SX_ID),
    SX_FIELD("data_fork_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("data_fork_length","uint32",8,4,SX_SIZE),
};
static const sx_layout sx_dm_ndif_chunk_entry = {0x60290059U,"ndif_chunk_entry",sx_dm_ndif_chunk_entry_fields,SX_COUNT(sx_dm_ndif_chunk_entry_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_ndif_resource_fork_header_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("map_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("data_length","uint32",8,4,SX_SIZE),
    SX_FIELD("map_length","uint32",12,4,SX_SIZE),
};
static const sx_layout sx_dm_ndif_resource_fork_header = {0x6029005aU,"ndif_resource_fork_header",sx_dm_ndif_resource_fork_header_fields,SX_COUNT(sx_dm_ndif_resource_fork_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_ndif_resource_map_header_fields[] = {
    SX_FIELD("header_copy","byte[16]",0,16,SX_NONE),
    SX_FIELD("next_resource_map","uint32",16,4,SX_POINTER),
    SX_FIELD("file_reference_number","uint16",20,2,SX_ID),
    SX_FIELD("attributes","uint16",22,2,SX_FLAGS),
    SX_FIELD("type_list_offset","uint16",24,2,SX_OFFSET),
    SX_FIELD("name_list_offset","uint16",26,2,SX_OFFSET),
};
static const sx_layout sx_dm_ndif_resource_map_header = {0x6029005bU,"ndif_resource_map_header",sx_dm_ndif_resource_map_header_fields,SX_COUNT(sx_dm_ndif_resource_map_header_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_ndif_resource_type_fields[] = {
    SX_FIELD("type","byte[4]",0,4,SX_ID),
    SX_FIELD("count_minus_one","uint16",4,2,SX_NONE),
    SX_FIELD("reference_list_offset","uint16",6,2,SX_OFFSET),
};
static const sx_layout sx_dm_ndif_resource_type = {0x6029005cU,"ndif_resource_type",sx_dm_ndif_resource_type_fields,SX_COUNT(sx_dm_ndif_resource_type_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_ndif_resource_reference_fields[] = {
    SX_FIELD("resource_id","int16",0,2,SX_ID),
    SX_FIELD("name_offset","uint16",2,2,SX_OFFSET),
    SX_FIELD("attributes","uint8",4,1,SX_FLAGS),
    SX_FIELD("data_offset","uint24",5,3,SX_OFFSET),
    SX_FIELD("handle","uint32",8,4,SX_POINTER),
};
static const sx_layout sx_dm_ndif_resource_reference = {0x6029005dU,"ndif_resource_reference",sx_dm_ndif_resource_reference_fields,SX_COUNT(sx_dm_ndif_resource_reference_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_ndif_resource_length_fields[] = {
    SX_FIELD("length","uint32",0,4,SX_SIZE),
};
static const sx_layout sx_dm_ndif_resource_length = {0x6029005eU,"ndif_resource_length",sx_dm_ndif_resource_length_fields,SX_COUNT(sx_dm_ndif_resource_length_fields),SX_BE};

static const xx_data_struct_field_desc sx_dm_ndif_resource_type_count_fields[] = {
    SX_FIELD("type_count_minus_one","uint16",0,2,SX_NONE),
};
static const sx_layout sx_dm_ndif_resource_type_count = {0x6029005fU,"ndif_resource_type_count",sx_dm_ndif_resource_type_count_fields,SX_COUNT(sx_dm_ndif_resource_type_count_fields),SX_BE};

static const sx_layout *const sx_diskmeta_layouts[] = {
    &sx_dm_vhdx_file_identifier,
    &sx_dm_vhdx_header,
    &sx_dm_vhdx_region_table_header,
    &sx_dm_vhdx_region_table_entry,
    &sx_dm_vhdx_metadata_table_header,
    &sx_dm_vhdx_metadata_table_entry,
    &sx_dm_vhdx_file_parameters,
    &sx_dm_vhdx_disk_size,
    &sx_dm_vhdx_logical_sector_size,
    &sx_dm_vhdx_physical_sector_size,
    &sx_dm_vhdx_virtual_disk_id,
    &sx_dm_vhdx_parent_locator,
    &sx_dm_vhdx_parent_locator_entry,
    &sx_dm_vhdx_bat_entry,
    &sx_dm_vhd_footer_511,
    &sx_dm_vhd_footer_512,
    &sx_dm_vhd_dynamic_header,
    &sx_dm_vhd_parent_locator,
    &sx_dm_vhd_bat_entry,
    &sx_dm_vmdk_sparse_header,
    &sx_dm_vmdk_grain_directory_entry,
    &sx_dm_vmdk_grain_table_entry,
    &sx_dm_vmdk_metadata_marker,
    &sx_dm_vdi_preheader,
    &sx_dm_vdi_header_v1,
    &sx_dm_vdi_block_map_entry,
    &sx_dm_qed_header,
    &sx_dm_qed_l1_entry,
    &sx_dm_qed_l2_entry,
    &sx_dm_parallels_header_extended,
    &sx_dm_parallels_header_old,
    &sx_dm_parallels_bat_sector,
    &sx_dm_parallels_bat_cluster,
    &sx_dm_chd_header_v1,
    &sx_dm_chd_header_v2,
    &sx_dm_chd_header_v3,
    &sx_dm_chd_header_v4,
    &sx_dm_chd_header_v5,
    &sx_dm_chd_map_v12,
    &sx_dm_chd_map_v34,
    &sx_dm_chd_map_v5_uncompressed,
    &sx_dm_chd_map_v5_compressed_header,
    &sx_dm_chd_metadata_header,
    &sx_dm_udif_trailer,
    &sx_dm_cloop_header,
    &sx_dm_cloop_block_offset,
    &sx_dm_encrypted_dmg_v2_header,
    &sx_dm_encrypted_dmg_key_pointer,
    &sx_dm_encrypted_dmg_v1_trailer,
    &sx_dm_ubi_erase_counter_header,
    &sx_dm_ubi_volume_identifier_header,
    &sx_dm_ubi_volume_table_record,
    &sx_dm_ubifs_common_header,
    &sx_dm_ubifs_superblock,
    &sx_dm_ubifs_master_node,
    &sx_dm_ubifs_index_header,
    &sx_dm_ubifs_index_branch,
    &sx_dm_ubifs_inode_node,
    &sx_dm_ubifs_directory_entry,
    &sx_dm_ubifs_data_node,
    &sx_dm_ubifs_padding_node,
    &sx_dm_ubifs_commit_start,
    &sx_dm_ubifs_reference_node,
    &sx_dm_jffs2_common_header_le,
    &sx_dm_jffs2_directory_entry_le,
    &sx_dm_jffs2_inode_le,
    &sx_dm_jffs2_xattr_le,
    &sx_dm_jffs2_xref_le,
    &sx_dm_yaffs_object_header_le,
    &sx_dm_qnx6_superblock_header_le,
    &sx_dm_qnx6_root_node_le,
    &sx_dm_jffs2_common_header_be,
    &sx_dm_jffs2_directory_entry_be,
    &sx_dm_jffs2_inode_be,
    &sx_dm_jffs2_xattr_be,
    &sx_dm_jffs2_xref_be,
    &sx_dm_yaffs_object_header_be,
    &sx_dm_qnx6_superblock_header_be,
    &sx_dm_qnx6_root_node_be,
    &sx_dm_logfs_superblock,
    &sx_dm_apm_driver_descriptor_header,
    &sx_dm_apm_driver_descriptor,
    &sx_dm_apm_partition_entry,
    &sx_dm_rdb_rigid_disk_block,
    &sx_dm_rdb_partition_block,
    &sx_dm_rdb_filesystem_header,
    &sx_dm_rdb_load_segment_header,
    &sx_dm_ndif_bcem_header,
    &sx_dm_ndif_chunk_entry,
    &sx_dm_ndif_resource_fork_header,
    &sx_dm_ndif_resource_map_header,
    &sx_dm_ndif_resource_type,
    &sx_dm_ndif_resource_reference,
    &sx_dm_ndif_resource_length,
    &sx_dm_ndif_resource_type_count,
};

#include "xxfclib/algo/crc/xx_crc.h"
static bool sx_dm_span(sx_context*c,uint64_t p,uint64_t n){return p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sx_dm_read(sx_context*c,uint64_t p,void*b,size_t n){return sx_dm_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint32_t sx_dm_u32(const void*b,size_t o,bool be){return xx_data_get_u32((const uint8_t*)b+o,4,0,be);}
static uint64_t sx_dm_u64(const void*b,size_t o,bool be){return xx_data_get_u64((const uint8_t*)b+o,8,0,be);}
static uint16_t sx_dm_u16(const void*b,size_t o,bool be){return xx_data_get_u16((const uint8_t*)b+o,2,0,be);}
/* Aliased metadata is shown once. Optional partially overlapping layouts remain
 * raw rather than discarding already authenticated physical headers. */
static bool sx_dm_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t z,uint64_t n){if(!n)return true;if(z>INT64_MAX/n||!sx_dm_span(c,p,z*n))return false;if(c->count>=24000)return true;for(size_t i=0;i<c->count;i++){uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),b=(uint64_t)c->items[i].total_size;if(p<a+b&&a<p+z*n)return true;}return sx_table(c,l,(int64_t)p,(int64_t)z,n);}
static bool sx_dm_add(sx_context*c,const sx_layout*l,uint64_t p,uint64_t z){return sx_dm_put(c,l,p,z,1);}
static bool sx_dm_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t z,uint64_t n){if(n>65536)n=65536;return sx_dm_put(c,l,p,z,n);}
static bool sx_dm_crc(sx_context*c,uint64_t p,uint64_t n,uint32_t want,bool castagnoli,bool complement,bool zero4){uint8_t b[4096];uint32_t crc=0;uint64_t done=0;if(!sx_dm_span(c,p,n)||n>UINT64_C(16777216))return false;while(done<n){size_t z=(size_t)(n-done>sizeof(b)?sizeof(b):n-done);if(!sx_dm_read(c,p+done,b,z))return false;if(zero4&&done==0&&z>=8)xx_rt_memset(b+4,0,4);crc=castagnoli?xx_crc32c_calc(crc,b,z):xx_crc32_calc(crc,b,z);done+=z;}return (complement?~crc:crc)==want;}
static bool sx_dm_vhd(sx_context*c){uint8_t h[576];uint64_t n=(uint64_t)c->size,fs=n%512==511?511:512;if(n<fs||!sx_dm_read(c,n-fs,h,85)||xx_rt_memcmp(h,"conectix",8))return false;const sx_layout*l=fs==511?&sx_dm_vhd_footer_511:&sx_dm_vhd_footer_512;if(!sx_dm_add(c,l,n-fs,fs))return false;unsigned type=sx_dm_u32(h,60,true);uint64_t p=sx_dm_u64(h,16,true);if(type==3||type==4){if(!sx_dm_add(c,&sx_dm_vhd_footer_512,0,512))return false;if(sx_dm_read(c,p,h,576)&&!xx_rt_memcmp(h,"cxsparse",8)&&sx_dm_span(c,p,1024)){if(!sx_dm_add(c,&sx_dm_vhd_dynamic_header,p,576)||!sx_dm_table(c,&sx_dm_vhd_parent_locator,p+576,24,8))return false;uint64_t bat=sx_dm_u64(h,16,true),count=sx_dm_u32(h,28,true);if(sx_dm_span(c,bat,count*4)&&!sx_dm_table(c,&sx_dm_vhd_bat_entry,bat,4,count))return false;}}return true;}
static bool sx_dm_vdi(sx_context*c){uint8_t h[456];if(!sx_dm_read(c,0,h,sizeof(h))||sx_dm_u32(h,64,false)!=0xbeda107f)return false;if(!sx_dm_add(c,&sx_dm_vdi_preheader,0,72)||!sx_dm_add(c,&sx_dm_vdi_header_v1,72,384))return false;uint64_t p=sx_dm_u32(h,340,false),n=sx_dm_u32(h,384,false);return !sx_dm_span(c,p,n*4)||sx_dm_table(c,&sx_dm_vdi_block_map_entry,p,4,n);}
static bool sx_dm_vmdk(sx_context*c){uint8_t h[512];uint64_t header=0;if(!sx_dm_read(c,0,h,512)||xx_rt_memcmp(h,"KDMV",4))return false;if(!sx_dm_add(c,&sx_dm_vmdk_sparse_header,0,512))return false;if(sx_dm_u64(h,56,false)==UINT64_MAX){if(c->size<2048||!sx_dm_read(c,(uint64_t)c->size-1024,h,512)||xx_rt_memcmp(h,"KDMV",4))return true;header=(uint64_t)c->size-1024;if(!sx_dm_add(c,&sx_dm_vmdk_sparse_header,header,512)||!sx_dm_add(c,&sx_dm_vmdk_metadata_marker,header-512,16)||!sx_dm_add(c,&sx_dm_vmdk_metadata_marker,header+512,16))return false;}
 uint64_t cap=sx_dm_u64(h,12,false),grain=sx_dm_u64(h,20,false),gtes=sx_dm_u32(h,44,false);if(!grain||!gtes||cap>UINT64_C(1)<<40)return true;uint64_t grains=cap/grain+(cap%grain!=0),n=grains/gtes+(grains%gtes!=0);if(n>65536)n=65536;
 for(unsigned copy=0;copy<2;copy++){uint64_t sector=sx_dm_u64(h,copy?48:56,false);if(!sector||sector>INT64_MAX/512)continue;uint64_t p=sector*512;if(!sx_dm_span(c,p,n*4))continue;if(!sx_dm_table(c,&sx_dm_vmdk_grain_directory_entry,p,4,n))return false;for(uint64_t i=0;i<n&&c->count<24000;i++){uint32_t v;if(!sx_u32(c,(int64_t)(p+i*4),false,&v))return false;uint64_t q=(uint64_t)v*512,k=gtes;if(k>65536)k=65536;if(v&&q>=512&&sx_dm_span(c,q,k*4)&&!sx_dm_table(c,&sx_dm_vmdk_grain_table_entry,q,4,k))return false;}}return true;}
static bool sx_dm_qed(sx_context*c){uint8_t h[64];if(!sx_dm_read(c,0,h,64)||xx_rt_memcmp(h,"QED\0",4)||!sx_dm_add(c,&sx_dm_qed_header,0,64))return false;uint64_t cs=sx_dm_u32(h,4,false),ts=sx_dm_u32(h,8,false),p=sx_dm_u64(h,40,false);if(cs<4096||cs>67108864||!ts||ts>16)return true;uint64_t n=cs*ts/8;if(n>65536)n=65536;if(!sx_dm_span(c,p,n*8))return true;if(!sx_dm_table(c,&sx_dm_qed_l1_entry,p,8,n))return false;for(uint64_t i=0;i<n&&c->count<24000;i++){uint64_t q;if(!sx_u64(c,(int64_t)(p+i*8),false,&q))return false;if(q>=cs&&q%cs==0&&sx_dm_span(c,q,n*8)&&!sx_dm_table(c,&sx_dm_qed_l2_entry,q,8,n))return false;}return true;}
static bool sx_dm_parallels(sx_context*c){uint8_t h[64];if(!sx_dm_read(c,0,h,64))return false;bool ext=!xx_rt_memcmp(h,"WithouFreSpacExt",16);if(!sx_dm_add(c,ext?&sx_dm_parallels_header_extended:&sx_dm_parallels_header_old,0,64))return false;uint64_t n=sx_dm_u32(h,32,false);return !sx_dm_span(c,64,n*4)||sx_dm_table(c,ext?&sx_dm_parallels_bat_cluster:&sx_dm_parallels_bat_sector,64,4,n);}
static bool sx_dm_chd(sx_context*c){uint8_t h[124];if(!sx_dm_read(c,0,h,16)||xx_rt_memcmp(h,"MComprHD",8))return false;uint32_t v=sx_dm_u32(h,12,true),z=sx_dm_u32(h,8,true);const sx_layout*l=v==1?&sx_dm_chd_header_v1:v==2?&sx_dm_chd_header_v2:v==3?&sx_dm_chd_header_v3:v==4?&sx_dm_chd_header_v4:v==5?&sx_dm_chd_header_v5:NULL;static const uint32_t sizes[]={0,76,80,120,108,124};if(!l||z!=sizes[v]||!sx_dm_read(c,0,h,z)||!sx_dm_add(c,l,0,z))return false;uint64_t map=z,meta=0,count=0;const sx_layout*ml=NULL;unsigned stride=0;
 if(v<=2){count=sx_dm_u32(h,28,true);ml=&sx_dm_chd_map_v12;stride=8;}else if(v<=4){count=sx_dm_u32(h,24,true);meta=sx_dm_u64(h,36,true);ml=&sx_dm_chd_map_v34;stride=16;}else{uint32_t hb=sx_dm_u32(h,56,true);uint64_t logical=sx_dm_u64(h,32,true);map=sx_dm_u64(h,40,true);meta=sx_dm_u64(h,48,true);count=hb?logical/hb+(logical%hb!=0):0;if(sx_dm_u32(h,16,true)){if(sx_dm_span(c,map,16)&&!sx_dm_add(c,&sx_dm_chd_map_v5_compressed_header,map,16))return false;}else{ml=&sx_dm_chd_map_v5_uncompressed;stride=4;}}
 if(ml&&count<=UINT64_MAX/stride&&sx_dm_span(c,map,count*stride)&&!sx_dm_table(c,ml,map,stride,count))return false;
 for(unsigned i=0;meta&&i<4096;i++){if(!sx_dm_read(c,meta,h,16))break;uint32_t len=sx_dm_u32(h,4,true)&0xffffff;uint64_t next=sx_dm_u64(h,8,true);if(!sx_dm_span(c,meta,16+(uint64_t)len))break;size_t before=c->count;if(!sx_dm_add(c,&sx_dm_chd_metadata_header,meta,16))return false;if(c->count==before||next==meta)break;meta=next;}return true;}
static bool sx_dm_cloop(sx_context*c){uint8_t h[136];if(!sx_dm_read(c,0,h,136)||!sx_dm_add(c,&sx_dm_cloop_header,0,136))return false;uint64_t n=(uint64_t)sx_dm_u32(h,132,true)+1;return !sx_dm_span(c,136,n*8)||sx_dm_table(c,&sx_dm_cloop_block_offset,136,8,n);}
static bool sx_dm_encrypted(sx_context*c){uint8_t h[76];if(sx_dm_read(c,0,h,76)&&!xx_rt_memcmp(h,"encrcdsa",8)){if(!sx_dm_add(c,&sx_dm_encrypted_dmg_v2_header,0,76))return false;uint64_t n=sx_dm_u32(h,72,true);return n>32||!sx_dm_span(c,76,n*20)||sx_dm_table(c,&sx_dm_encrypted_dmg_key_pointer,76,20,n);}return c->size>=1276&&sx_dm_add(c,&sx_dm_encrypted_dmg_v1_trailer,(uint64_t)c->size-1276,1276);}
static const uint8_t sx_dm_guid_bat[16] = {0x66, 0x77, 0xC2, 0x2D, 0x23, 0xF6, 0x00, 0x42, 0x9D, 0x64, 0x11, 0x5E, 0x9B, 0xFD, 0x4A, 0x08};
static const uint8_t sx_dm_guid_metadata[16] = {0x06, 0xA2, 0x7C, 0x8B, 0x90, 0x47, 0x9A, 0x4B, 0xB8, 0xFE, 0x57, 0x5F, 0x05, 0x0F, 0x88, 0x6E};
static const uint8_t sx_dm_guid_file_parameters[16] = {0x37, 0x67, 0xA1, 0xCA, 0x36, 0xFA, 0x43, 0x4D, 0xB3, 0xB6, 0x33, 0xF0, 0xAA, 0x44, 0xE7, 0x6B};
static const uint8_t sx_dm_guid_disk_size[16] = {0x24, 0x42, 0xA5, 0x2F, 0x1B, 0xCD, 0x76, 0x48, 0xB2, 0x11, 0x5D, 0xBE, 0xD8, 0x3B, 0xF4, 0xB8};
static const uint8_t sx_dm_guid_disk_id[16] = {0xAB, 0x12, 0xCA, 0xBE, 0xE6, 0xB2, 0x23, 0x45, 0x93, 0xEF, 0xC3, 0x09, 0xE0, 0x00, 0xC7, 0x46};
static const uint8_t sx_dm_guid_logical_sector[16] = {0x1D, 0xBF, 0x41, 0x81, 0x6F, 0xA9, 0x09, 0x47, 0xBA, 0x47, 0xF2, 0x33, 0xA8, 0xFA, 0xAB, 0x5F};
static const uint8_t sx_dm_guid_physical_sector[16] = {0xC7, 0x48, 0xA3, 0xCD, 0x5D, 0x44, 0x71, 0x44, 0x9C, 0xC9, 0xE9, 0x88, 0x52, 0x51, 0xC5, 0x56};
static const uint8_t sx_dm_guid_parent_locator[16] = {0x2D, 0x5F, 0xD3, 0xA8, 0x0B, 0xB3, 0x4D, 0x45, 0xAB, 0xF7, 0xD3, 0xD8, 0x48, 0x34, 0xAB, 0x0C};
static bool sx_dm_vhdx_metadata(sx_context*c,uint64_t p,uint64_t z,uint64_t bat,uint64_t batsz){uint8_t h[32],v[20];if(z<65536||!sx_dm_read(c,p,h,32)||xx_rt_memcmp(h,"metadata",8))return true;uint32_t n=sx_dm_u16(h,10,false);if(n>2047||32+(uint64_t)n*32>z)return true;if(!sx_dm_add(c,&sx_dm_vhdx_metadata_table_header,p,32)||!sx_dm_table(c,&sx_dm_vhdx_metadata_table_entry,p+32,32,n))return false;uint64_t disk=0;uint32_t block=0,logical=0,flags=0;
 for(uint32_t i=0;i<n;i++){if(!sx_dm_read(c,p+32+i*32,h,32))return false;uint64_t o=sx_dm_u32(h,16,false),len=sx_dm_u32(h,20,false);if(o<65536||o>z||len>z-o||!sx_dm_span(c,p+o,len)||(sx_dm_u32(h,24,false)&1))continue;const sx_layout*l=NULL;uint32_t need=0;
  if(!xx_rt_memcmp(h,sx_dm_guid_file_parameters,16)){l=&sx_dm_vhdx_file_parameters;need=8;if(len==8&&sx_dm_read(c,p+o,v,8)){block=sx_dm_u32(v,0,false);flags=sx_dm_u32(v,4,false);}}
  else if(!xx_rt_memcmp(h,sx_dm_guid_disk_size,16)){l=&sx_dm_vhdx_disk_size;need=8;if(len==8&&sx_dm_read(c,p+o,v,8))disk=sx_dm_u64(v,0,false);}
  else if(!xx_rt_memcmp(h,sx_dm_guid_logical_sector,16)){l=&sx_dm_vhdx_logical_sector_size;need=4;if(len==4&&sx_dm_read(c,p+o,v,4))logical=sx_dm_u32(v,0,false);}
  else if(!xx_rt_memcmp(h,sx_dm_guid_physical_sector,16)){l=&sx_dm_vhdx_physical_sector_size;need=4;}
  else if(!xx_rt_memcmp(h,sx_dm_guid_disk_id,16)){l=&sx_dm_vhdx_virtual_disk_id;need=16;}
  else if(!xx_rt_memcmp(h,sx_dm_guid_parent_locator,16)&&len>=20&&sx_dm_read(c,p+o,v,20)){uint32_t cnt=sx_dm_u16(v,18,false);if(20+(uint64_t)cnt*12<=len){if(!sx_dm_add(c,&sx_dm_vhdx_parent_locator,p+o,20)||!sx_dm_table(c,&sx_dm_vhdx_parent_locator_entry,p+o+20,12,cnt))return false;}}
  if(l&&len==need&&!sx_dm_add(c,l,p+o,need))return false;
 }
 if(block>=1048576&&block<=268435456&&(logical==512||logical==4096)&&disk&&disk<=UINT64_C(64)<<40){uint64_t blocks=(disk-1)/block+1,ratio=((uint64_t)logical<<23)/block;uint64_t entries=(flags&2)?((blocks-1)/ratio+1)*(ratio+1):blocks+(blocks-1)/ratio;if(entries<=batsz/8&&sx_dm_span(c,bat,entries*8)&&!sx_dm_table(c,&sx_dm_vhdx_bat_entry,bat,8,entries))return false;}return true;}
static bool sx_dm_vhdx(sx_context*c){uint8_t h[32];if(!sx_dm_read(c,0,h,8)||xx_rt_memcmp(h,"vhdxfile",8)||!sx_dm_add(c,&sx_dm_vhdx_file_identifier,0,520))return false;
 for(unsigned i=1;i<=2;i++){uint64_t p=(uint64_t)i*65536;if(sx_dm_read(c,p,h,8)&&!xx_rt_memcmp(h,"head",4)&&sx_dm_span(c,p,4096)&&!sx_dm_add(c,&sx_dm_vhdx_header,p,4096))return false;}
 for(unsigned copy=3;copy<=4;copy++){uint64_t p=(uint64_t)copy*65536;if(!sx_dm_read(c,p,h,16)||xx_rt_memcmp(h,"regi",4)||!sx_dm_crc(c,p,65536,sx_dm_u32(h,4,false),true,false,true))continue;uint32_t n=sx_dm_u32(h,8,false);if(n>2047)continue;if(!sx_dm_add(c,&sx_dm_vhdx_region_table_header,p,16)||!sx_dm_table(c,&sx_dm_vhdx_region_table_entry,p+16,32,n))return false;uint64_t bat=0,batsz=0,meta=0,metasz=0;
  for(uint32_t i=0;i<n;i++){if(!sx_dm_read(c,p+16+i*32,h,32))return false;uint64_t o=sx_dm_u64(h,16,false),z=sx_dm_u32(h,24,false);if(!sx_dm_span(c,o,z))continue;if(!xx_rt_memcmp(h,sx_dm_guid_bat,16)){bat=o;batsz=z;}if(!xx_rt_memcmp(h,sx_dm_guid_metadata,16)){meta=o;metasz=z;}}
  if(meta&&!sx_dm_vhdx_metadata(c,meta,metasz,bat,batsz))return false;
 }return true;}
static bool sx_dm_ubi_ec(sx_context*c,uint64_t p,uint8_t*h){return sx_dm_read(c,p,h,64)&&!xx_rt_memcmp(h,"UBI#",4)&&sx_dm_u32(h,60,true)==~xx_crc32_calc(0,h,60);}
static bool sx_dm_ubi(sx_context*c){uint8_t h[172];if(!sx_dm_ubi_ec(c,0,h))return false;uint64_t peb=0;
 for(unsigned pass=0;pass<2&&!peb;pass++)for(uint64_t candidate=1024;candidate<=16777216&&candidate<=(uint64_t)c->size;candidate*=2){for(unsigned k=1;k<=64;k++){uint64_t p=candidate*k;if(!sx_dm_span(c,p,64))break;if(sx_dm_ubi_ec(c,p,h)){peb=candidate;break;}if(!pass)break;bool erased=true;for(unsigned j=0;j<64;j++)if(h[j]!=255){erased=false;break;}if(!erased)break;}if(peb)break;}
 if(!peb&&(uint64_t)c->size<=16777216)peb=(uint64_t)c->size;if(!peb)return sx_dm_add(c,&sx_dm_ubi_erase_counter_header,0,64);
 uint64_t count=(uint64_t)c->size/peb;if(count>8192)count=8192;for(uint64_t i=0;i<count&&c->count<24000;i++){uint64_t p=i*peb;if(!sx_dm_ubi_ec(c,p,h))continue;uint64_t vo=sx_dm_u32(h,16,true),data=sx_dm_u32(h,20,true);if(!sx_dm_add(c,&sx_dm_ubi_erase_counter_header,p,64))return false;if(vo<64||vo>peb-64||data<vo+64||data>=peb||!sx_dm_read(c,p+vo,h,64)||xx_rt_memcmp(h,"UBI!",4)||sx_dm_u32(h,60,true)!=~xx_crc32_calc(0,h,60))continue;if(!sx_dm_add(c,&sx_dm_ubi_volume_identifier_header,p+vo,64))return false;
  if(sx_dm_u32(h,8,true)==0x7fffefffU&&sx_dm_u32(h,12,true)<=1){uint64_t available=peb-data,pad=sx_dm_u32(h,28,true);if(pad>available)continue;available-=pad;for(uint64_t j=0;j<128&&(j+1)*172<=available;j++){uint64_t q=p+data+j*172;if(!sx_dm_read(c,q,h,172))return false;if(sx_dm_u32(h,168,true)==~xx_crc32_calc(0,h,168)&&!sx_dm_add(c,&sx_dm_ubi_volume_table_record,q,172))return false;}}
 }return true;}
/* Scan physical UBIFS nodes only; no journal replay or decompressed data.
 * CRC guards a resynchronisation on 8-byte boundaries, within 64 MiB. */
static bool sx_dm_ubifs(sx_context*c){uint8_t h[28];uint64_t limit=(uint64_t)c->size;if(limit>67108864)limit=67108864;for(uint64_t p=0;p+24<=limit&&c->count<24000;){if(!sx_dm_read(c,p,h,24))return false;uint64_t z=sx_dm_u32(h,16,false);if(sx_dm_u32(h,0,false)!=0x06101831||z<24||z>16777216||!sx_dm_span(c,p,z)||!sx_dm_crc(c,p+8,z-8,sx_dm_u32(h,4,false),false,true,false)){p+=8;continue;}const sx_layout*l=&sx_dm_ubifs_common_header;uint64_t n=24;switch(h[20]){case 0:l=&sx_dm_ubifs_inode_node;n=160;break;case 1:l=&sx_dm_ubifs_data_node;n=48;break;case 2:case 3:l=&sx_dm_ubifs_directory_entry;n=56;break;case 5:l=&sx_dm_ubifs_padding_node;n=28;break;case 6:l=&sx_dm_ubifs_superblock;n=4096;break;case 7:l=&sx_dm_ubifs_master_node;n=512;break;case 8:l=&sx_dm_ubifs_reference_node;n=64;break;case 9:l=&sx_dm_ubifs_index_header;n=28;break;case 10:l=&sx_dm_ubifs_commit_start;n=32;break;}if(n>z){l=&sx_dm_ubifs_common_header;n=24;}if(!sx_dm_add(c,l,p,n))return false;if(l==&sx_dm_ubifs_index_header&&sx_dm_read(c,p,h,28)){uint64_t count=sx_dm_u16(h,24,false);if(count<=(z-28)/20&&!sx_dm_table(c,&sx_dm_ubifs_index_branch,p+28,20,count))return false;}p+=(z+7)&~UINT64_C(7);}return c->count!=0;}
static bool sx_dm_jffs(sx_context*c){uint8_t h[12];uint64_t limit=(uint64_t)c->size;if(limit>67108864)limit=67108864;for(uint64_t p=0;p+12<=limit&&c->count<24000;){if(!sx_dm_read(c,p,h,12))return false;bool be=sx_dm_u16(h,0,true)==0x1985;uint64_t z=sx_dm_u32(h,4,be);if(sx_dm_u16(h,0,be)!=0x1985||z<12||!sx_dm_span(c,p,z)||sx_dm_u32(h,8,be)!=(xx_crc32_calc(UINT32_MAX,h,8)^UINT32_MAX)){p+=4;continue;}uint32_t t=sx_dm_u16(h,2,be);const sx_layout*l=be?&sx_dm_jffs2_common_header_be:&sx_dm_jffs2_common_header_le;uint64_t n=12;switch(t|0x2000){case 0xe001:l=be?&sx_dm_jffs2_directory_entry_be:&sx_dm_jffs2_directory_entry_le;n=40;break;case 0xe002:l=be?&sx_dm_jffs2_inode_be:&sx_dm_jffs2_inode_le;n=68;break;case 0xe008:l=be?&sx_dm_jffs2_xattr_be:&sx_dm_jffs2_xattr_le;n=32;break;case 0xe009:l=be?&sx_dm_jffs2_xref_be:&sx_dm_jffs2_xref_le;n=28;break;}if(n>z){l=be?&sx_dm_jffs2_common_header_be:&sx_dm_jffs2_common_header_le;n=12;}if(!sx_dm_add(c,l,p,n))return false;p+=(z+3)&~UINT64_C(3);}return c->count!=0;}
static bool sx_dm_yaffs(sx_context*c){uint8_t h[10];if(!sx_dm_read(c,0,h,10))return false;bool be=sx_dm_u32(h,0,false)>5;return sx_dm_add(c,be?&sx_dm_yaffs_object_header_be:&sx_dm_yaffs_object_header_le,0,512);}
/* Expose physically framed anchors at both native-supported positions.
 * Geometry is rechecked locally; no subclass cast or native constructor is used. */
static bool sx_dm_qnx(sx_context*c){uint8_t h[392];const uint64_t positions[]={8192,0};for(unsigned i=0;i<2;i++){uint64_t p=positions[i];if(!sx_dm_read(c,p,h,sizeof(h)))continue;bool be=sx_dm_u32(h,0,true)==0x68191122;if(sx_dm_u32(h,0,be)!=0x68191122)continue;uint64_t bs=sx_dm_u32(h,48,be),blocks=sx_dm_u32(h,60,be);if(bs<512||bs>65536||(bs&(bs-1))||(p+4096)%bs||!blocks||!sx_dm_u32(h,52,be)||!sx_dm_span(c,p+4096,blocks*bs)||sx_dm_u64(h,72,be)<128||h[144]>4||h[304]>4)continue;if(!sx_dm_add(c,be?&sx_dm_qnx6_superblock_header_be:&sx_dm_qnx6_superblock_header_le,p,72)||!sx_dm_table(c,be?&sx_dm_qnx6_root_node_be:&sx_dm_qnx6_root_node_le,p+72,80,4))return false;}return c->count!=0;}
static bool sx_dm_logfs(sx_context*c){uint64_t pos[2]={0,((uint64_t)c->size&~UINT64_C(4095))};if(pos[1]>=4096)pos[1]-=4096;for(unsigned i=0;i<2;i++){uint8_t h[256];if(i&&pos[i]==0)continue;if(sx_dm_read(c,pos[i],h,256)&&sx_dm_u64(h,24,true)==UINT64_C(0x7a3a8e5cb9d5bf67)&&sx_dm_u32(h,0,true)==~xx_crc32_calc(0,h+4,20)&&sx_dm_u32(h,32,true)==~xx_crc32_calc(0,h+36,220)&&!sx_dm_add(c,&sx_dm_logfs_superblock,pos[i],256))return false;}return c->count!=0;}
static bool sx_dm_apm(sx_context*c){uint8_t h[512];if(!sx_dm_read(c,0,h,18)||sx_dm_u16(h,0,true)!=0x4552||!sx_dm_add(c,&sx_dm_apm_driver_descriptor_header,0,18))return false;uint64_t step=sx_dm_u16(h,2,true),n=sx_dm_u16(h,16,true);if(n<=(512-18)/8&&!sx_dm_table(c,&sx_dm_apm_driver_descriptor,18,8,n))return false;if(step!=512&&step!=1024&&step!=2048&&step!=4096)return true;if(step>512&&sx_dm_read(c,512,h,512)&&sx_dm_u16(h,0,true)==0x504d&&sx_dm_u32(h,8,true)==1)step=512;if(!sx_dm_read(c,step,h,512)||sx_dm_u16(h,0,true)!=0x504d)return true;n=sx_dm_u32(h,4,true);if(n>256)n=256;for(uint64_t i=1;i<=n;i++){uint64_t p=i*step;if(!sx_dm_read(c,p,h,512)||sx_dm_u16(h,0,true)!=0x504d)break;if(!sx_dm_add(c,&sx_dm_apm_partition_entry,p,512))return false;}return true;}
static bool sx_dm_rdb_block(sx_context*c,uint64_t p,uint32_t block,uint8_t*h,size_t z){if(!sx_dm_read(c,p,h,z))return false;uint64_t count=sx_dm_u32(h,4,true);if(count<5||count>block/4||!sx_dm_span(c,p,count*4))return false;uint32_t sum=0;for(uint64_t i=0;i<count;i++){uint32_t word;if(!sx_u32(c,(int64_t)(p+i*4),true,&word))return false;sum+=word;}return sum==0;}
static bool sx_dm_rdb_lseg(sx_context*c,uint32_t block,uint32_t next){for(unsigned i=0;next!=UINT32_MAX&&i<16384&&c->count<24000;i++){uint64_t p=(uint64_t)block*next;uint8_t h[20];if(!sx_dm_rdb_block(c,p,block,h,20)||xx_rt_memcmp(h,"LSEG",4))break;size_t old=c->count;if(!sx_dm_add(c,&sx_dm_rdb_load_segment_header,p,20))return false;if(c->count==old)break;next=sx_dm_u32(h,16,true);}return true;}
static bool sx_dm_rdb(sx_context*c){uint8_t h[256];uint64_t p;uint32_t block=0,part=UINT32_MAX,fs=UINT32_MAX;for(p=0;p<8192;p+=512){if(!sx_dm_read(c,p,h,256))break;if(xx_rt_memcmp(h,"RDSK",4))continue;uint32_t b=sx_dm_u32(h,16,true);if(b<256||b>65536||(b&(b-1))||p%b||!sx_dm_rdb_block(c,p,b,h,256))continue;block=b;part=sx_dm_u32(h,28,true);fs=sx_dm_u32(h,32,true);if(!sx_dm_add(c,&sx_dm_rdb_rigid_disk_block,p,256))return false;break;}if(!block)return false;
 for(unsigned kind=0;kind<2;kind++){uint32_t next=kind?fs:part;for(unsigned i=0;next!=UINT32_MAX&&i<(kind?64U:128U);i++){p=(uint64_t)block*next;uint32_t z=kind?80:256;if(!sx_dm_rdb_block(c,p,block,h,z)||xx_rt_memcmp(h,kind?"FSHD":"PART",4))break;size_t old=c->count;if(!sx_dm_add(c,kind?&sx_dm_rdb_filesystem_header:&sx_dm_rdb_partition_block,p,z))return false;if(c->count==old)break;next=sx_dm_u32(h,16,true);if(kind&&!sx_dm_rdb_lseg(c,block,sx_dm_u32(h,72,true)))return false;}}
 return true;}
static bool sx_dm_ndif(sx_context*c){uint8_t h[128];if(!sx_dm_read(c,0,h,128))return false;uint64_t secondary=0;if(xx_crc16_xmodem_calc(0,h,124)==sx_dm_u16(h,124,true)&&(h[122]>=129||sx_dm_u16(h,124,true)))secondary=sx_dm_u16(h,120,true);uint64_t data=128+((secondary+127)&~UINT64_C(127)),df=sx_dm_u32(h,83,true),rs=data+((df+127)&~UINT64_C(127)),rsize=sx_dm_u32(h,87,true);if(!sx_dm_span(c,rs,rsize)||rsize<16||!sx_dm_read(c,rs,h,16)||!sx_dm_add(c,&sx_dm_ndif_resource_fork_header,rs,16))return false;uint64_t rd=sx_dm_u32(h,0,true),map=sx_dm_u32(h,4,true),dl=sx_dm_u32(h,8,true),ml=sx_dm_u32(h,12,true);if(rd<16||rd>rsize||dl>rsize-rd||map<16||map>rsize||ml>rsize-map||ml<30||!sx_dm_read(c,rs+map,h,28))return true;uint64_t to=sx_dm_u16(h,24,true);if(to<28||to>ml-2)return true;if(!sx_dm_add(c,&sx_dm_ndif_resource_map_header,rs+map,28))return false;uint16_t raw;if(!sx_u16(c,(int64_t)(rs+map+to),true,&raw))return false;uint64_t count=((uint32_t)raw+1)&0xffff;if(count>(ml-to-2)/8)return true;if(!sx_dm_add(c,&sx_dm_ndif_resource_type_count,rs+map+to,2))return false;if(!sx_dm_table(c,&sx_dm_ndif_resource_type,rs+map+to+2,8,count))return false;
 for(uint64_t i=0;i<count&&i<4096;i++){if(!sx_dm_read(c,rs+map+to+2+i*8,h,8))return false;bool bcem=!xx_rt_memcmp(h,"bcem",4);uint64_t nr=(uint64_t)sx_dm_u16(h,4,true)+1,rr=to+sx_dm_u16(h,6,true);if(rr>ml||nr>(ml-rr)/12)continue;if(!sx_dm_table(c,&sx_dm_ndif_resource_reference,rs+map+rr,12,nr))return false;for(uint64_t j=0;j<nr&&j<4096&&c->count<24000;j++){if(!sx_dm_read(c,rs+map+rr+j*12,h,12))return false;uint64_t ro=xx_data_get_u24(h+5,3,0,true);bool match=bcem&&sx_dm_u16(h,0,true)==128;if(ro>dl||dl-ro<4)continue;uint32_t len;uint64_t q=rs+rd+ro;if(!sx_u32(c,(int64_t)q,true,&len))return false;if(len>dl-ro-4)continue;if(!sx_dm_add(c,&sx_dm_ndif_resource_length,q,4))return false;if(match&&len>=128&&sx_dm_read(c,q+4,h,128)){uint64_t n=sx_dm_u32(h,124,true);if(n<=(len-128)/12){if(!sx_dm_add(c,&sx_dm_ndif_bcem_header,q+4,128)||!sx_dm_table(c,&sx_dm_ndif_chunk_entry,q+132,12,n))return false;}}}}
 return true;}
static bool sx_diskmeta_supports(xx_file_type_t t){switch(t){
case XX_FILE_TYPE_VHDX:
case XX_FILE_TYPE_VHDDYNAMIC:
case XX_FILE_TYPE_VMDK:
case XX_FILE_TYPE_VDI:
case XX_FILE_TYPE_QEMU_ENHANCED_DISK:
case XX_FILE_TYPE_PARALLELS_HDD:
case XX_FILE_TYPE_CHD:
case XX_FILE_TYPE_DMG:
case XX_FILE_TYPE_CLOOP:
case XX_FILE_TYPE_UBI:
case XX_FILE_TYPE_UBIFS:
case XX_FILE_TYPE_JFFS2:
case XX_FILE_TYPE_YAFFS:
case XX_FILE_TYPE_QNX6:
case XX_FILE_TYPE_LOGFS:
case XX_FILE_TYPE_APM:
case XX_FILE_TYPE_RDB:
case XX_FILE_TYPE_APPLE_DISK_COPY_6_NDIF_IMAGE:
case XX_FILE_TYPE_ENCRYPTED_APPLE_DISK_IMAGE:
return true;default:return false;}}
static int sx_dm_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sx_dm_finish(sx_context*c){size_t n=c->count;int64_t end=0;if(!n)return false;xx_rt_qsort(c->items,n,sizeof(*c->items),sx_dm_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sx_dm_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_diskmeta_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_VHDX:ok=sx_dm_vhdx(c);break;
case XX_FILE_TYPE_VHDDYNAMIC:ok=sx_dm_vhd(c);break;
case XX_FILE_TYPE_VMDK:ok=sx_dm_vmdk(c);break;
case XX_FILE_TYPE_VDI:ok=sx_dm_vdi(c);break;
case XX_FILE_TYPE_QEMU_ENHANCED_DISK:ok=sx_dm_qed(c);break;
case XX_FILE_TYPE_PARALLELS_HDD:ok=sx_dm_parallels(c);break;
case XX_FILE_TYPE_CHD:ok=sx_dm_chd(c);break;
case XX_FILE_TYPE_DMG:ok=c->size>=512&&sx_dm_add(c,&sx_dm_udif_trailer,(uint64_t)c->size-512,512);break;
case XX_FILE_TYPE_CLOOP:ok=sx_dm_cloop(c);break;
case XX_FILE_TYPE_UBI:ok=sx_dm_ubi(c);break;
case XX_FILE_TYPE_UBIFS:ok=sx_dm_ubifs(c);break;
case XX_FILE_TYPE_JFFS2:ok=sx_dm_jffs(c);break;
case XX_FILE_TYPE_YAFFS:ok=sx_dm_yaffs(c);break;
case XX_FILE_TYPE_QNX6:ok=sx_dm_qnx(c);break;
case XX_FILE_TYPE_LOGFS:ok=sx_dm_logfs(c);break;
case XX_FILE_TYPE_APM:ok=sx_dm_apm(c);break;
case XX_FILE_TYPE_RDB:ok=sx_dm_rdb(c);break;
case XX_FILE_TYPE_APPLE_DISK_COPY_6_NDIF_IMAGE:ok=sx_dm_ndif(c);break;
case XX_FILE_TYPE_ENCRYPTED_APPLE_DISK_IMAGE:ok=sx_dm_encrypted(c);break;
default:break;}return ok&&sx_dm_finish(c);}
static bool sx_diskmeta_comment(xx_data_struct_record*r,uint32_t id){if(!r||!r->name||id<0x60290000U||id>=0x602a0000U)return true;const wchar_t*s=NULL;uint64_t v=(r->value.type==XX_VAR_TYPE_FLOAT||r->value.type==XX_VAR_TYPE_DOUBLE||r->value.type==XX_VAR_TYPE_STRING||r->value.type==XX_VAR_TYPE_BYTES)?0:xx_var_get_u64(&r->value);
 if(!xx_rt_wcscmp(r->name,L"timestamp")&&(id==sx_dm_vhd_footer_511.id||id==sx_dm_vhd_footer_512.id))s=L"Seconds since 2000-01-01 UTC";
 else if(!xx_rt_wcscmp(r->name,L"parent_timestamp"))s=L"Seconds since 2000-01-01 UTC";
 else if(!xx_rt_wcscmp(r->name,L"disk_type"))s=v==2?L"Fixed hard disk":v==3?L"Dynamic hard disk":v==4?L"Differencing hard disk":NULL;
 else if(id==sx_dm_vdi_header_v1.id&&!xx_rt_wcscmp(r->name,L"image_type"))s=v==1?L"Dynamic":v==2?L"Fixed":v==3?L"Undo":v==4?L"Differencing":NULL;
 else if(id==sx_dm_vdi_block_map_entry.id)s=v==UINT32_MAX?L"Unallocated block":v==UINT32_MAX-1?L"Zero block":L"Physical block index in data area; multiply by block_size + block_extra";
 else if(id==sx_dm_vhd_bat_entry.id)s=v==UINT32_MAX?L"Unallocated block":L"File-relative sector index in 512-byte units; points to the block bitmap";
 else if(id==sx_dm_vmdk_grain_directory_entry.id||id==sx_dm_vmdk_grain_table_entry.id)s=L"File-relative index in 512-byte sectors; zero means unallocated";
 else if(id==sx_dm_parallels_bat_sector.id)s=L"File-relative index in 512-byte sectors; zero means unallocated";
 else if(id==sx_dm_parallels_bat_cluster.id)s=L"File-relative index in cluster_sectors*512 bytes; zero means unallocated";
 else if(id==sx_dm_vhdx_bat_entry.id)s=L"Bits0..2: state; bits3..19: reserved; bits20..63: file byte offset (MiB aligned); states0 not present,1 undefined,2 zero,3 unmapped,6 fully present,7 partially present";
 else if(id==sx_dm_chd_map_v12.id)s=L"Packed 64-bit map word: low44 bits file byte offset, high20 bits stored length";
 else if(id==sx_dm_chd_map_v34.id&&!xx_rt_wcscmp(r->name,L"offset_or_reference"))s=L"Meaning depends on flags: file byte offset, self/parent hunk index, or repeated eight-byte literal";
 else if(id==sx_dm_chd_map_v34.id&&!xx_rt_wcscmp(r->name,L"length_low"))s=L"Low16 bits of stored byte length; combined with length_high shifted16";
 else if(id==sx_dm_chd_map_v34.id&&!xx_rt_wcscmp(r->name,L"length_high"))s=L"High8 bits of stored byte length; not a complete byte size";
 else if(id==sx_dm_chd_map_v5_uncompressed.id)s=L"File offset divided by hunk_bytes; zero denotes unallocated/inherited data";
 else if(id==sx_dm_vhd_parent_locator.id&&!xx_rt_wcscmp(r->name,L"platform_data_space"))s=L"Reserved space in 512-byte sectors";
 else if(id==sx_dm_vhdx_metadata_table_entry.id&&!xx_rt_wcscmp(r->name,L"offset"))s=L"Byte offset relative to the containing metadata region; physical stored value is not translated";
 else if(id==sx_dm_vhdx_parent_locator_entry.id&&(!xx_rt_wcscmp(r->name,L"key_offset")||!xx_rt_wcscmp(r->name,L"value_offset")))s=L"Byte offset relative to the parent-locator item";
 else if(!xx_rt_wcscmp(r->name,L"segment_shift")||!xx_rt_wcscmp(r->name,L"block_shift")||!xx_rt_wcscmp(r->name,L"write_shift"))s=L"Base-two logarithm of the byte size; an encoded shift, not a byte count";
 else if(!xx_rt_wcscmp(r->name,L"file_size_low"))s=L"Low32 bits of file size; combine with high word subject to the format's unused-high sentinel";
 else if(!xx_rt_wcscmp(r->name,L"file_size_high"))s=L"High32 bits of file size; 0xFFFFFFFF means unused in legacy YAFFS images";
 else if(!xx_rt_wcscmp(r->name,L"key_type_and_value"))s=L"High3 bits: key kind (0 inode,1 data,2 directory entry,3 xattr); low29 bits: block index or name hash";
 else if(id==sx_dm_ubi_volume_identifier_header.id&&!xx_rt_wcscmp(r->name,L"volume_id"))s=v==0x7fffefff?L"UBI_LAYOUT_VOLUME_ID":NULL;
 else if(!xx_rt_wcscmp(r->name,L"volume_type"))s=v==1?L"Dynamic volume":v==2?L"Static volume":NULL;
 else if(id==sx_dm_ubi_erase_counter_header.id&&(!xx_rt_wcscmp(r->name,L"vid_header_offset")||!xx_rt_wcscmp(r->name,L"data_offset")))s=L"Byte offset relative to the containing physical eraseblock";
 else if(id==sx_dm_rdb_filesystem_header.id&&!xx_rt_wcscmp(r->name,L"startup"))s=L"Signed DeviceNode startup word; applied only when its patch_flags bit is set";
 else if(id==sx_dm_rdb_filesystem_header.id&&!xx_rt_wcscmp(r->name,L"segment_list_block"))s=L"Signed filesystem load-segment block index; -1 terminates the chain";
 else if(id==sx_dm_rdb_filesystem_header.id&&!xx_rt_wcscmp(r->name,L"global_vector"))s=L"Signed BCPL global-vector control word; -1 means no BCPL global vector, 0 requests a private vector";
 else if(id==sx_dm_ndif_resource_type_count.id)s=v==0xffff?L"Empty type list sentinel":L"Encoded resource type count minus one";
 else if(id==sx_dm_ndif_chunk_entry.id&&!xx_rt_wcscmp(r->name,L"data_fork_offset"))s=L"Byte offset relative to the MacBinary data fork";
 else if(id==sx_dm_ndif_chunk_entry.id&&!xx_rt_wcscmp(r->name,L"type"))s=v==0?L"Zero fill":v==2?L"Raw":v==0x83?L"ADC":v==0x80?L"KenCode":v==255?L"Terminator":NULL;
 return !s||xx_data_struct_record_set_comment(r,s);}
