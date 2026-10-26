/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical legacy disk image metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_disktail_scope.txt. */

static const xx_data_struct_field_desc sxdt_rdos_catalog_entry_fields[] = {
    SX_FIELD("filename","byte[24]",0,24,SX_NONE),
    SX_FIELD("file_type","uint8",24,1,SX_ID),
    SX_FIELD("sectors_used","uint8",25,1,SX_COUNT_PROP),
    SX_FIELD("load_address","uint16",26,2,SX_ADDRESS),
    SX_FIELD("file_size","uint16",28,2,SX_SIZE),
    SX_FIELD("first_logical_sector","uint16",30,2,SX_NONE),
};
static const sx_layout sxdt_rdos_catalog_entry = {0x607a0001U,"rdos_catalog_entry",sxdt_rdos_catalog_entry_fields,SX_COUNT(sxdt_rdos_catalog_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mac_ts_driver_descriptor_fields[] = {
    SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("block_size","uint16",2,2,SX_SIZE),
    SX_FIELD("block_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("device_type","uint16",8,2,SX_ID),
    SX_FIELD("device_id","uint16",10,2,SX_ID),
    SX_FIELD("driver_data","uint32",12,4,SX_NONE),
    SX_FIELD("driver_count","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("driver_start_block","uint32",18,4,SX_NONE),
    SX_FIELD("driver_size_blocks","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("driver_os_type","uint16",24,2,SX_ID),
};
static const sx_layout sxdt_mac_ts_driver_descriptor = {0x607a0002U,"mac_ts_driver_descriptor",sxdt_mac_ts_driver_descriptor_fields,SX_COUNT(sxdt_mac_ts_driver_descriptor_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_mac_ts_map_header_fields[] = {
    SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
};
static const sx_layout sxdt_mac_ts_map_header = {0x607a0003U,"mac_ts_map_header",sxdt_mac_ts_map_header_fields,SX_COUNT(sxdt_mac_ts_map_header_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_mac_ts_partition_fields[] = {
    SX_FIELD("start_block","uint32",0,4,SX_NONE),
    SX_FIELD("block_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("filesystem_id","char[4]",8,4,SX_ID),
};
static const sx_layout sxdt_mac_ts_partition = {0x607a0004U,"mac_ts_partition",sxdt_mac_ts_partition_fields,SX_COUNT(sxdt_mac_ts_partition_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_ppm_header_fields[] = {
    SX_FIELD("area_blocks","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("volume_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("signature_length","uint8",4,1,SX_SIZE),
    SX_FIELD("signature","char[3]",5,3,SX_SIGNATURE),
    SX_FIELD("unused","byte[8]",8,8,SX_NONE),
};
static const sx_layout sxdt_ppm_header = {0x607a0005U,"ppm_header",sxdt_ppm_header_fields,SX_COUNT(sxdt_ppm_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_ppm_volume_entry_fields[] = {
    SX_FIELD("absolute_start_block","uint16",0,2,SX_NONE),
    SX_FIELD("block_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("default_unit","uint8",4,1,SX_ID),
    SX_FIELD("write_protection","uint8",5,1,SX_FLAGS),
    SX_FIELD("old_driver_address","uint16",6,2,SX_ADDRESS),
};
static const sx_layout sxdt_ppm_volume_entry = {0x607a0006U,"ppm_volume_entry",sxdt_ppm_volume_entry_fields,SX_COUNT(sxdt_ppm_volume_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_ppm_volume_description_fields[] = {
    SX_FIELD("length","uint8",0,1,SX_SIZE),
    SX_FIELD("description","char[15]",1,15,SX_NONE),
};
static const sx_layout sxdt_ppm_volume_description = {0x607a0007U,"ppm_volume_description",sxdt_ppm_volume_description_fields,SX_COUNT(sxdt_ppm_volume_description_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_ppm_cached_volume_name_fields[] = {
    SX_FIELD("length","uint8",0,1,SX_SIZE),
    SX_FIELD("name","char[7]",1,7,SX_NONE),
};
static const sx_layout sxdt_ppm_cached_volume_name = {0x607a0008U,"ppm_cached_volume_name",sxdt_ppm_cached_volume_name_fields,SX_COUNT(sxdt_ppm_cached_volume_name_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_apricot_label_prefix_fields[] = {
    SX_FIELD("version","char[8]",0,8,SX_NONE),
    SX_FIELD("unknown","byte[6]",8,6,SX_NONE),
    SX_FIELD("sector_size","uint16",14,2,SX_SIZE),
    SX_FIELD("sectors_per_track","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",18,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint8",22,1,SX_COUNT_PROP),
};
static const sx_layout sxdt_apricot_label_prefix = {0x607a0009U,"apricot_label_prefix",sxdt_apricot_label_prefix_fields,SX_COUNT(sxdt_apricot_label_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_apricot_bpb_fields[] = {
    SX_FIELD("bytes_per_sector","uint16",0,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sectors","uint16",3,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",5,1,SX_COUNT_PROP),
    SX_FIELD("root_directory_entries","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("media_descriptor","uint8",10,1,SX_ID),
    SX_FIELD("sectors_per_fat","uint16",11,2,SX_COUNT_PROP),
};
static const sx_layout sxdt_apricot_bpb = {0x607a000aU,"apricot_bpb",sxdt_apricot_bpb_fields,SX_COUNT(sxdt_apricot_bpb_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_cpm_extent8_fields[] = {
    SX_FIELD("user_or_status","uint8",0,1,SX_ID),
    SX_FIELD("filename_and_attributes","byte[8]",1,8,SX_NONE),
    SX_FIELD("extension_and_attributes","byte[3]",9,3,SX_NONE),
    SX_FIELD("extent_low","uint8",12,1,SX_NONE),
    SX_FIELD("s1","uint8",13,1,SX_NONE),
    SX_FIELD("extent_high","uint8",14,1,SX_NONE),
    SX_FIELD("record_count","uint8",15,1,SX_COUNT_PROP),
    SX_FIELD("allocation_blocks","uint8[16]",16,16,SX_NONE),
};
static const sx_layout sxdt_cpm_extent8 = {0x607a000bU,"cpm_extent8",sxdt_cpm_extent8_fields,SX_COUNT(sxdt_cpm_extent8_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_cpm_extent16_fields[] = {
    SX_FIELD("user_or_status","uint8",0,1,SX_ID),
    SX_FIELD("filename_and_attributes","byte[8]",1,8,SX_NONE),
    SX_FIELD("extension_and_attributes","byte[3]",9,3,SX_NONE),
    SX_FIELD("extent_low","uint8",12,1,SX_NONE),
    SX_FIELD("s1","uint8",13,1,SX_NONE),
    SX_FIELD("extent_high","uint8",14,1,SX_NONE),
    SX_FIELD("record_count","uint8",15,1,SX_COUNT_PROP),
    SX_FIELD("allocation_blocks","uint16[8]",16,16,SX_NONE),
};
static const sx_layout sxdt_cpm_extent16 = {0x607a000cU,"cpm_extent16",sxdt_cpm_extent16_fields,SX_COUNT(sxdt_cpm_extent16_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_atom_catalog_name_header_fields[] = {
    SX_FIELD("title_part1","char[8]",0,8,SX_NONE),
};
static const sx_layout sxdt_atom_catalog_name_header = {0x607a000dU,"atom_catalog_name_header",sxdt_atom_catalog_name_header_fields,SX_COUNT(sxdt_atom_catalog_name_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_atom_catalog_info_header_fields[] = {
    SX_FIELD("title_part2","char[4]",0,4,SX_NONE),
    SX_FIELD("write_cycle","uint8",4,1,SX_NONE),
    SX_FIELD("file_count_times8","uint8",5,1,SX_NONE),
    SX_FIELD("disk_size_high_and_boot","uint8",6,1,SX_FLAGS),
    SX_FIELD("disk_sectors_low","uint8",7,1,SX_NONE),
};
static const sx_layout sxdt_atom_catalog_info_header = {0x607a000eU,"atom_catalog_info_header",sxdt_atom_catalog_info_header_fields,SX_COUNT(sxdt_atom_catalog_info_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_atom_catalog_name_fields[] = {
    SX_FIELD("filename","char[7]",0,7,SX_NONE),
    SX_FIELD("directory_and_lock","uint8",7,1,SX_FLAGS),
};
static const sx_layout sxdt_atom_catalog_name = {0x607a000fU,"atom_catalog_name",sxdt_atom_catalog_name_fields,SX_COUNT(sxdt_atom_catalog_name_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_atom_catalog_info_fields[] = {
    SX_FIELD("load_address_low","uint16",0,2,SX_NONE),
    SX_FIELD("execution_address_low","uint16",2,2,SX_NONE),
    SX_FIELD("file_length_low","uint16",4,2,SX_NONE),
    SX_FIELD("high_bits","uint8",6,1,SX_FLAGS),
    SX_FIELD("start_sector_low","uint8",7,1,SX_NONE),
};
static const sx_layout sxdt_atom_catalog_info = {0x607a0010U,"atom_catalog_info",sxdt_atom_catalog_info_fields,SX_COUNT(sxdt_atom_catalog_info_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_casio_disk_header_fields[] = {
    SX_FIELD("disk_name","char[12]",0,12,SX_NONE),
    SX_FIELD("signature","byte[4]",12,4,SX_SIGNATURE),
    SX_FIELD("password","char[12]",16,12,SX_NONE),
    SX_FIELD("reserved","byte[4]",28,4,SX_RESERVED),
};
static const sx_layout sxdt_casio_disk_header = {0x607a0011U,"casio_disk_header",sxdt_casio_disk_header_fields,SX_COUNT(sxdt_casio_disk_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_casio_allocation_byte_fields[] = {
    SX_FIELD("sector_bitmap","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxdt_casio_allocation_byte = {0x607a0012U,"casio_allocation_byte",sxdt_casio_allocation_byte_fields,SX_COUNT(sxdt_casio_allocation_byte_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_casio_directory_entry_fields[] = {
    SX_FIELD("filename","char[12]",0,12,SX_NONE),
    SX_FIELD("content_type","uint8",12,1,SX_ID),
    SX_FIELD("continuation","uint8",13,1,SX_FLAGS),
    SX_FIELD("head_sector","uint16",14,2,SX_NONE),
};
static const sx_layout sxdt_casio_directory_entry = {0x607a0013U,"casio_directory_entry",sxdt_casio_directory_entry_fields,SX_COUNT(sxdt_casio_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_casio_file_extent_fields[] = {
    SX_FIELD("start_sector","uint16",0,2,SX_NONE),
    SX_FIELD("end_sector","uint16",2,2,SX_NONE),
};
static const sx_layout sxdt_casio_file_extent = {0x607a0014U,"casio_file_extent",sxdt_casio_file_extent_fields,SX_COUNT(sxdt_casio_file_extent_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_casio_file_counts_fields[] = {
    SX_FIELD("bank_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("voice_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("wave_block_count","uint16",4,2,SX_COUNT_PROP),
};
static const sx_layout sxdt_casio_file_counts = {0x607a0015U,"casio_file_counts",sxdt_casio_file_counts_fields,SX_COUNT(sxdt_casio_file_counts_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_rawcd_sector_header_fields[] = {
    SX_FIELD("sync","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("minute_bcd","uint8",12,1,SX_NONE),
    SX_FIELD("second_bcd","uint8",13,1,SX_NONE),
    SX_FIELD("frame_bcd","uint8",14,1,SX_NONE),
    SX_FIELD("mode","uint8",15,1,SX_ID),
};
static const sx_layout sxdt_rawcd_sector_header = {0x607a0016U,"rawcd_sector_header",sxdt_rawcd_sector_header_fields,SX_COUNT(sxdt_rawcd_sector_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_rawcd_xa_subheader_fields[] = {
    SX_FIELD("file_number","uint8",0,1,SX_ID),
    SX_FIELD("channel_number","uint8",1,1,SX_ID),
    SX_FIELD("submode","uint8",2,1,SX_FLAGS),
    SX_FIELD("coding_information","uint8",3,1,SX_FLAGS),
    SX_FIELD("file_number_copy","uint8",4,1,SX_ID),
    SX_FIELD("channel_number_copy","uint8",5,1,SX_ID),
    SX_FIELD("submode_copy","uint8",6,1,SX_FLAGS),
    SX_FIELD("coding_information_copy","uint8",7,1,SX_FLAGS),
};
static const sx_layout sxdt_rawcd_xa_subheader = {0x607a0017U,"rawcd_xa_subheader",sxdt_rawcd_xa_subheader_fields,SX_COUNT(sxdt_rawcd_xa_subheader_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_rawcd_edc_fields[] = {
    SX_FIELD("edc","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxdt_rawcd_edc = {0x607a0018U,"rawcd_edc",sxdt_rawcd_edc_fields,SX_COUNT(sxdt_rawcd_edc_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mgt_directory_core_fields[] = {
    SX_FIELD("type_and_flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("filename","char[10]",1,10,SX_NONE),
    SX_FIELD("sectors_used","uint16be",11,2,SX_COUNT_PROP),
    SX_FIELD("first_track_and_side","uint8",13,1,SX_NONE),
    SX_FIELD("first_sector","uint8",14,1,SX_NONE),
    SX_FIELD("allocation_bitmap","byte[195]",15,195,SX_NONE),
};
static const sx_layout sxdt_mgt_directory_core = {0x607a0019U,"mgt_directory_core",sxdt_mgt_directory_core_fields,SX_COUNT(sxdt_mgt_directory_core_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mgt_sector_link_fields[] = {
    SX_FIELD("next_track_and_side","uint8",0,1,SX_NONE),
    SX_FIELD("next_sector","uint8",1,1,SX_NONE),
};
static const sx_layout sxdt_mgt_sector_link = {0x607a001aU,"mgt_sector_link",sxdt_mgt_sector_link_fields,SX_COUNT(sxdt_mgt_sector_link_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_prodos_directory_links_fields[] = {
    SX_FIELD("previous_block","uint16",0,2,SX_NONE),
    SX_FIELD("next_block","uint16",2,2,SX_NONE),
};
static const sx_layout sxdt_mapped_prodos_directory_links = {0x607a001bU,"mapped_prodos_directory_links",sxdt_mapped_prodos_directory_links_fields,SX_COUNT(sxdt_mapped_prodos_directory_links_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_prodos_volume_header_fields[] = {
    SX_FIELD("storage_and_name_length","uint8",0,1,SX_FLAGS),
    SX_FIELD("volume_name","char[15]",1,15,SX_NONE),
    SX_FIELD("reserved","byte[2]",16,2,SX_RESERVED),
    SX_FIELD("modification_packed","uint32",18,4,SX_NONE),
    SX_FIELD("lowercase_flags","uint16",22,2,SX_FLAGS),
    SX_FIELD("creation_packed","uint32",24,4,SX_NONE),
    SX_FIELD("version","uint8",28,1,SX_ID),
    SX_FIELD("minimum_version","uint8",29,1,SX_ID),
    SX_FIELD("access","uint8",30,1,SX_FLAGS),
    SX_FIELD("entry_length","uint8",31,1,SX_SIZE),
    SX_FIELD("entries_per_block","uint8",32,1,SX_COUNT_PROP),
    SX_FIELD("active_entries","uint16",33,2,SX_COUNT_PROP),
    SX_FIELD("bitmap_block","uint16",35,2,SX_NONE),
    SX_FIELD("total_blocks","uint16",37,2,SX_COUNT_PROP),
};
static const sx_layout sxdt_mapped_prodos_volume_header = {0x607a001cU,"mapped_prodos_volume_header",sxdt_mapped_prodos_volume_header_fields,SX_COUNT(sxdt_mapped_prodos_volume_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_prodos_subdirectory_header_fields[] = {
    SX_FIELD("storage_and_name_length","uint8",0,1,SX_FLAGS),
    SX_FIELD("directory_name","char[15]",1,15,SX_NONE),
    SX_FIELD("reserved_75","uint8",16,1,SX_RESERVED),
    SX_FIELD("reserved","byte[7]",17,7,SX_RESERVED),
    SX_FIELD("creation_packed","uint32",24,4,SX_NONE),
    SX_FIELD("version","uint8",28,1,SX_ID),
    SX_FIELD("minimum_version","uint8",29,1,SX_ID),
    SX_FIELD("access","uint8",30,1,SX_FLAGS),
    SX_FIELD("entry_length","uint8",31,1,SX_SIZE),
    SX_FIELD("entries_per_block","uint8",32,1,SX_COUNT_PROP),
    SX_FIELD("active_entries","uint16",33,2,SX_COUNT_PROP),
    SX_FIELD("parent_block","uint16",35,2,SX_NONE),
    SX_FIELD("parent_entry_number","uint8",37,1,SX_NONE),
    SX_FIELD("parent_entry_length","uint8",38,1,SX_SIZE),
};
static const sx_layout sxdt_mapped_prodos_subdirectory_header = {0x607a001dU,"mapped_prodos_subdirectory_header",sxdt_mapped_prodos_subdirectory_header_fields,SX_COUNT(sxdt_mapped_prodos_subdirectory_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_prodos_file_entry_fields[] = {
    SX_FIELD("storage_and_name_length","uint8",0,1,SX_FLAGS),
    SX_FIELD("name","char[15]",1,15,SX_NONE),
    SX_FIELD("file_type","uint8",16,1,SX_ID),
    SX_FIELD("key_block","uint16",17,2,SX_NONE),
    SX_FIELD("blocks_used","uint16",19,2,SX_COUNT_PROP),
    SX_FIELD("eof","uint24",21,3,SX_SIZE),
    SX_FIELD("creation_packed","uint32",24,4,SX_NONE),
    SX_FIELD("version_and_case","uint16",28,2,SX_FLAGS),
    SX_FIELD("access","uint8",30,1,SX_FLAGS),
    SX_FIELD("auxiliary_type","uint16",31,2,SX_ID),
    SX_FIELD("modification_packed","uint32",33,4,SX_NONE),
    SX_FIELD("header_block","uint16",37,2,SX_NONE),
};
static const sx_layout sxdt_mapped_prodos_file_entry = {0x607a001eU,"mapped_prodos_file_entry",sxdt_mapped_prodos_file_entry_fields,SX_COUNT(sxdt_mapped_prodos_file_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_prodos_fork_descriptor_fields[] = {
    SX_FIELD("storage_type","uint8",0,1,SX_ID),
    SX_FIELD("key_block","uint16",1,2,SX_NONE),
    SX_FIELD("blocks_used","uint16",3,2,SX_COUNT_PROP),
    SX_FIELD("eof","uint24",5,3,SX_SIZE),
};
static const sx_layout sxdt_mapped_prodos_fork_descriptor = {0x607a001fU,"mapped_prodos_fork_descriptor",sxdt_mapped_prodos_fork_descriptor_fields,SX_COUNT(sxdt_mapped_prodos_fork_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_prodos_index_low_fields[] = {
    SX_FIELD("block_number_low_bytes","byte[256]",0,256,SX_NONE),
};
static const sx_layout sxdt_mapped_prodos_index_low = {0x607a0020U,"mapped_prodos_index_low",sxdt_mapped_prodos_index_low_fields,SX_COUNT(sxdt_mapped_prodos_index_low_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_prodos_index_high_fields[] = {
    SX_FIELD("block_number_high_bytes","byte[256]",0,256,SX_NONE),
};
static const sx_layout sxdt_mapped_prodos_index_high = {0x607a0021U,"mapped_prodos_index_high",sxdt_mapped_prodos_index_high_fields,SX_COUNT(sxdt_mapped_prodos_index_high_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_pascal_volume_header_fields[] = {
    SX_FIELD("first_block","uint16",0,2,SX_NONE),
    SX_FIELD("directory_end_block","uint16",2,2,SX_NONE),
    SX_FIELD("file_type","uint16",4,2,SX_ID),
    SX_FIELD("name_length","uint8",6,1,SX_SIZE),
    SX_FIELD("volume_name","char[7]",7,7,SX_NONE),
    SX_FIELD("total_blocks","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("file_count","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("last_access_time","uint16",18,2,SX_NONE),
    SX_FIELD("last_set_date","uint16",20,2,SX_NONE),
    SX_FIELD("reserved","byte[4]",22,4,SX_RESERVED),
};
static const sx_layout sxdt_mapped_pascal_volume_header = {0x607a0022U,"mapped_pascal_volume_header",sxdt_mapped_pascal_volume_header_fields,SX_COUNT(sxdt_mapped_pascal_volume_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_pascal_file_entry_fields[] = {
    SX_FIELD("first_block","uint16",0,2,SX_NONE),
    SX_FIELD("end_block","uint16",2,2,SX_NONE),
    SX_FIELD("kind_and_flags","uint16",4,2,SX_FLAGS),
    SX_FIELD("name_length","uint8",6,1,SX_SIZE),
    SX_FIELD("name","char[15]",7,15,SX_NONE),
    SX_FIELD("last_block_bytes","uint16",22,2,SX_SIZE),
    SX_FIELD("modification_date","uint16",24,2,SX_NONE),
};
static const sx_layout sxdt_mapped_pascal_file_entry = {0x607a0023U,"mapped_pascal_file_entry",sxdt_mapped_pascal_file_entry_fields,SX_COUNT(sxdt_mapped_pascal_file_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_apple_dos_vtoc_fields[] = {
    SX_FIELD("unused0","uint8",0,1,SX_RESERVED),
    SX_FIELD("catalog_track","uint8",1,1,SX_NONE),
    SX_FIELD("catalog_sector","uint8",2,1,SX_NONE),
    SX_FIELD("dos_release","uint8",3,1,SX_ID),
    SX_FIELD("unused4","byte[2]",4,2,SX_RESERVED),
    SX_FIELD("volume_number","uint8",6,1,SX_ID),
    SX_FIELD("unused7","byte[32]",7,32,SX_RESERVED),
    SX_FIELD("maximum_ts_pairs","uint8",39,1,SX_COUNT_PROP),
    SX_FIELD("unused40","byte[8]",40,8,SX_RESERVED),
    SX_FIELD("last_allocated_track","uint8",48,1,SX_NONE),
    SX_FIELD("allocation_direction","int8",49,1,SX_NONE),
    SX_FIELD("unused50","byte[2]",50,2,SX_RESERVED),
    SX_FIELD("track_count","uint8",52,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",53,1,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector","uint16",54,2,SX_SIZE),
};
static const sx_layout sxdt_mapped_apple_dos_vtoc = {0x607a0024U,"mapped_apple_dos_vtoc",sxdt_mapped_apple_dos_vtoc_fields,SX_COUNT(sxdt_mapped_apple_dos_vtoc_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_apple_dos_bitmap_fields[] = {
    SX_FIELD("free_sector_bits","byte[4]",0,4,SX_FLAGS),
};
static const sx_layout sxdt_mapped_apple_dos_bitmap = {0x607a0025U,"mapped_apple_dos_bitmap",sxdt_mapped_apple_dos_bitmap_fields,SX_COUNT(sxdt_mapped_apple_dos_bitmap_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_apple_dos_catalog_header_fields[] = {
    SX_FIELD("unused0","uint8",0,1,SX_RESERVED),
    SX_FIELD("next_track","uint8",1,1,SX_NONE),
    SX_FIELD("next_sector","uint8",2,1,SX_NONE),
    SX_FIELD("unused3","byte[8]",3,8,SX_RESERVED),
};
static const sx_layout sxdt_mapped_apple_dos_catalog_header = {0x607a0026U,"mapped_apple_dos_catalog_header",sxdt_mapped_apple_dos_catalog_header_fields,SX_COUNT(sxdt_mapped_apple_dos_catalog_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_apple_dos_file_entry_fields[] = {
    SX_FIELD("ts_list_track","uint8",0,1,SX_NONE),
    SX_FIELD("ts_list_sector","uint8",1,1,SX_NONE),
    SX_FIELD("file_type_and_lock","uint8",2,1,SX_FLAGS),
    SX_FIELD("high_bit_name","byte[30]",3,30,SX_NONE),
    SX_FIELD("sector_count","uint16",33,2,SX_COUNT_PROP),
};
static const sx_layout sxdt_mapped_apple_dos_file_entry = {0x607a0027U,"mapped_apple_dos_file_entry",sxdt_mapped_apple_dos_file_entry_fields,SX_COUNT(sxdt_mapped_apple_dos_file_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_apple_dos_ts_header_fields[] = {
    SX_FIELD("unused0","uint8",0,1,SX_RESERVED),
    SX_FIELD("next_track","uint8",1,1,SX_NONE),
    SX_FIELD("next_sector","uint8",2,1,SX_NONE),
    SX_FIELD("unused3","byte[2]",3,2,SX_RESERVED),
    SX_FIELD("first_file_sector_index","uint16",5,2,SX_NONE),
    SX_FIELD("unused7","byte[5]",7,5,SX_RESERVED),
};
static const sx_layout sxdt_mapped_apple_dos_ts_header = {0x607a0028U,"mapped_apple_dos_ts_header",sxdt_mapped_apple_dos_ts_header_fields,SX_COUNT(sxdt_mapped_apple_dos_ts_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_apple_dos_ts_pair_fields[] = {
    SX_FIELD("track","uint8",0,1,SX_NONE),
    SX_FIELD("sector","uint8",1,1,SX_NONE),
};
static const sx_layout sxdt_mapped_apple_dos_ts_pair = {0x607a0029U,"mapped_apple_dos_ts_pair",sxdt_mapped_apple_dos_ts_pair_fields,SX_COUNT(sxdt_mapped_apple_dos_ts_pair_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mapped_hfs_master_directory_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("creation_time","uint32",2,4,SX_TIME),
    SX_FIELD("modification_time","uint32",6,4,SX_TIME),
    SX_FIELD("attributes","uint16",10,2,SX_FLAGS),
    SX_FIELD("root_file_count","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("bitmap_start_sector","uint16",14,2,SX_NONE),
    SX_FIELD("allocation_search_pointer","uint16",16,2,SX_NONE),
    SX_FIELD("allocation_block_count","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("allocation_block_size","uint32",20,4,SX_SIZE),
    SX_FIELD("clump_size","uint32",24,4,SX_SIZE),
    SX_FIELD("allocation_start_sector","uint16",28,2,SX_NONE),
    SX_FIELD("next_catalog_id","uint32",30,4,SX_ID),
    SX_FIELD("free_blocks","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("volume_name_length","uint8",36,1,SX_SIZE),
    SX_FIELD("volume_name_macroman","byte[27]",37,27,SX_NONE),
    SX_FIELD("backup_time","uint32",64,4,SX_TIME),
    SX_FIELD("backup_sequence","uint16",68,2,SX_NONE),
    SX_FIELD("write_count","uint32",70,4,SX_COUNT_PROP),
    SX_FIELD("extents_clump_size","uint32",74,4,SX_SIZE),
    SX_FIELD("catalog_clump_size","uint32",78,4,SX_SIZE),
    SX_FIELD("root_directory_count","uint16",82,2,SX_COUNT_PROP),
    SX_FIELD("file_count","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("directory_count","uint32",88,4,SX_COUNT_PROP),
    SX_FIELD("finder_info","uint32[8]",92,32,SX_NONE),
    SX_FIELD("volume_cache_or_embedded_signature","uint16",124,2,SX_NONE),
    SX_FIELD("bitmap_cache_or_embedded_start","uint16",126,2,SX_NONE),
    SX_FIELD("control_cache_or_embedded_count","uint16",128,2,SX_NONE),
    SX_FIELD("extents_file_size","uint32",130,4,SX_SIZE),
    SX_FIELD("extents_file_initial_extents","uint16[6]",134,12,SX_NONE),
    SX_FIELD("catalog_file_size","uint32",146,4,SX_SIZE),
    SX_FIELD("catalog_file_initial_extents","uint16[6]",150,12,SX_NONE),
};
static const sx_layout sxdt_mapped_hfs_master_directory = {0x607a002aU,"mapped_hfs_master_directory",sxdt_mapped_hfs_master_directory_fields,SX_COUNT(sxdt_mapped_hfs_master_directory_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_mapped_hfs_btree_node_fields[] = {
    SX_FIELD("forward_link","uint32",0,4,SX_NONE),
    SX_FIELD("backward_link","uint32",4,4,SX_NONE),
    SX_FIELD("kind","int8",8,1,SX_ID),
    SX_FIELD("height","uint8",9,1,SX_NONE),
    SX_FIELD("record_count","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("reserved","uint16",12,2,SX_RESERVED),
};
static const sx_layout sxdt_mapped_hfs_btree_node = {0x607a002bU,"mapped_hfs_btree_node",sxdt_mapped_hfs_btree_node_fields,SX_COUNT(sxdt_mapped_hfs_btree_node_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_mapped_hfs_btree_header_fields[] = {
    SX_FIELD("tree_depth","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("root_node","uint32",2,4,SX_NONE),
    SX_FIELD("leaf_records","uint32",6,4,SX_COUNT_PROP),
    SX_FIELD("first_leaf_node","uint32",10,4,SX_NONE),
    SX_FIELD("last_leaf_node","uint32",14,4,SX_NONE),
    SX_FIELD("node_size","uint16",18,2,SX_SIZE),
    SX_FIELD("maximum_key_length","uint16",20,2,SX_SIZE),
    SX_FIELD("total_nodes","uint32",22,4,SX_COUNT_PROP),
    SX_FIELD("free_nodes","uint32",26,4,SX_COUNT_PROP),
    SX_FIELD("reserved16","uint16",30,2,SX_RESERVED),
    SX_FIELD("clump_size","uint32",32,4,SX_SIZE),
    SX_FIELD("tree_type","uint8",36,1,SX_ID),
    SX_FIELD("key_compare_type","uint8",37,1,SX_ID),
    SX_FIELD("attributes","uint32",38,4,SX_FLAGS),
    SX_FIELD("reserved32","uint32[16]",42,64,SX_RESERVED),
};
static const sx_layout sxdt_mapped_hfs_btree_header = {0x607a002cU,"mapped_hfs_btree_header",sxdt_mapped_hfs_btree_header_fields,SX_COUNT(sxdt_mapped_hfs_btree_header_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_mapped_hfs_node_record_offset_fields[] = {
    SX_FIELD("record_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxdt_mapped_hfs_node_record_offset = {0x607a002dU,"mapped_hfs_node_record_offset",sxdt_mapped_hfs_node_record_offset_fields,SX_COUNT(sxdt_mapped_hfs_node_record_offset_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_mapped_hfs_catalog_key_prefix_fields[] = {
    SX_FIELD("key_length","uint8",0,1,SX_SIZE),
    SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
    SX_FIELD("parent_catalog_id","uint32",2,4,SX_ID),
    SX_FIELD("name_length","uint8",6,1,SX_SIZE),
};
static const sx_layout sxdt_mapped_hfs_catalog_key_prefix = {0x607a002eU,"mapped_hfs_catalog_key_prefix",sxdt_mapped_hfs_catalog_key_prefix_fields,SX_COUNT(sxdt_mapped_hfs_catalog_key_prefix_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_mapped_hfs_extents_key_fields[] = {
    SX_FIELD("key_length","uint8",0,1,SX_SIZE),
    SX_FIELD("fork_type","uint8",1,1,SX_ID),
    SX_FIELD("file_id","uint32",2,4,SX_ID),
    SX_FIELD("first_allocation_block","uint16",6,2,SX_NONE),
};
static const sx_layout sxdt_mapped_hfs_extents_key = {0x607a002fU,"mapped_hfs_extents_key",sxdt_mapped_hfs_extents_key_fields,SX_COUNT(sxdt_mapped_hfs_extents_key_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_mapped_hfs_extent_fields[] = {
    SX_FIELD("first_allocation_block","uint16",0,2,SX_NONE),
    SX_FIELD("block_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxdt_mapped_hfs_extent = {0x607a0030U,"mapped_hfs_extent",sxdt_mapped_hfs_extent_fields,SX_COUNT(sxdt_mapped_hfs_extent_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_mapped_hfs_btree_child_fields[] = {
    SX_FIELD("child_node","uint32",0,4,SX_NONE),
};
static const sx_layout sxdt_mapped_hfs_btree_child = {0x607a0031U,"mapped_hfs_btree_child",sxdt_mapped_hfs_btree_child_fields,SX_COUNT(sxdt_mapped_hfs_btree_child_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_mapped_hfs_catalog_folder_fields[] = {
    SX_FIELD("record_type","int16",0,2,SX_ID),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("valence","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("folder_id","uint32",6,4,SX_ID),
    SX_FIELD("creation_time","uint32",10,4,SX_TIME),
    SX_FIELD("modification_time","uint32",14,4,SX_TIME),
    SX_FIELD("backup_time","uint32",18,4,SX_TIME),
    SX_FIELD("finder_folder_info","byte[16]",22,16,SX_NONE),
    SX_FIELD("finder_extended_info","byte[16]",38,16,SX_NONE),
    SX_FIELD("reserved","uint32[4]",54,16,SX_RESERVED),
};
static const sx_layout sxdt_mapped_hfs_catalog_folder = {0x607a0032U,"mapped_hfs_catalog_folder",sxdt_mapped_hfs_catalog_folder_fields,SX_COUNT(sxdt_mapped_hfs_catalog_folder_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_mapped_hfs_catalog_file_fields[] = {
    SX_FIELD("record_type","int16",0,2,SX_ID),
    SX_FIELD("flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("file_type","int8",3,1,SX_ID),
    SX_FIELD("finder_type","uint32",4,4,SX_ID),
    SX_FIELD("finder_creator","uint32",8,4,SX_ID),
    SX_FIELD("finder_flags","uint16",12,2,SX_FLAGS),
    SX_FIELD("finder_vertical","int16",14,2,SX_NONE),
    SX_FIELD("finder_horizontal","int16",16,2,SX_NONE),
    SX_FIELD("finder_folder","int16",18,2,SX_NONE),
    SX_FIELD("file_id","uint32",20,4,SX_ID),
    SX_FIELD("data_start_block","uint16",24,2,SX_NONE),
    SX_FIELD("data_logical_size","int32",26,4,SX_SIZE),
    SX_FIELD("data_physical_size","int32",30,4,SX_SIZE),
    SX_FIELD("resource_start_block","uint16",34,2,SX_NONE),
    SX_FIELD("resource_logical_size","int32",36,4,SX_SIZE),
    SX_FIELD("resource_physical_size","int32",40,4,SX_SIZE),
    SX_FIELD("creation_time","uint32",44,4,SX_TIME),
    SX_FIELD("modification_time","uint32",48,4,SX_TIME),
    SX_FIELD("backup_time","uint32",52,4,SX_TIME),
    SX_FIELD("finder_extended_info","byte[16]",56,16,SX_NONE),
    SX_FIELD("clump_size","uint16",72,2,SX_SIZE),
    SX_FIELD("data_initial_extents","uint16[6]",74,12,SX_NONE),
    SX_FIELD("resource_initial_extents","uint16[6]",86,12,SX_NONE),
    SX_FIELD("reserved","uint32",98,4,SX_RESERVED),
};
static const sx_layout sxdt_mapped_hfs_catalog_file = {0x607a0033U,"mapped_hfs_catalog_file",sxdt_mapped_hfs_catalog_file_fields,SX_COUNT(sxdt_mapped_hfs_catalog_file_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_mapped_hfs_catalog_thread_fields[] = {
    SX_FIELD("record_type","int16",0,2,SX_ID),
    SX_FIELD("reserved","int32[2]",2,8,SX_RESERVED),
    SX_FIELD("parent_catalog_id","uint32",10,4,SX_ID),
    SX_FIELD("name_length","uint8",14,1,SX_SIZE),
    SX_FIELD("name_macroman","byte[31]",15,31,SX_NONE),
};
static const sx_layout sxdt_mapped_hfs_catalog_thread = {0x607a0034U,"mapped_hfs_catalog_thread",sxdt_mapped_hfs_catalog_thread_fields,SX_COUNT(sxdt_mapped_hfs_catalog_thread_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_cpm3_volume_label_fields[] = {
    SX_FIELD("status","uint8",0,1,SX_ID),
    SX_FIELD("label","char[11]",1,11,SX_NONE),
    SX_FIELD("flags","uint8",12,1,SX_FLAGS),
    SX_FIELD("password_and_reserved","byte[11]",13,11,SX_NONE),
    SX_FIELD("creation_days","uint16",24,2,SX_NONE),
    SX_FIELD("creation_hour_bcd","uint8",26,1,SX_NONE),
    SX_FIELD("creation_minute_bcd","uint8",27,1,SX_NONE),
    SX_FIELD("modification_days","uint16",28,2,SX_NONE),
    SX_FIELD("modification_hour_bcd","uint8",30,1,SX_NONE),
    SX_FIELD("modification_minute_bcd","uint8",31,1,SX_NONE),
};
static const sx_layout sxdt_cpm3_volume_label = {0x607a0035U,"cpm3_volume_label",sxdt_cpm3_volume_label_fields,SX_COUNT(sxdt_cpm3_volume_label_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_cpm3_timestamp_status_fields[] = {
    SX_FIELD("status","uint8",0,1,SX_ID),
};
static const sx_layout sxdt_cpm3_timestamp_status = {0x607a0036U,"cpm3_timestamp_status",sxdt_cpm3_timestamp_status_fields,SX_COUNT(sxdt_cpm3_timestamp_status_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_cpm3_timestamp_record_fields[] = {
    SX_FIELD("first_stamp_days","uint16",0,2,SX_NONE),
    SX_FIELD("first_stamp_hour_bcd","uint8",2,1,SX_NONE),
    SX_FIELD("first_stamp_minute_bcd","uint8",3,1,SX_NONE),
    SX_FIELD("modification_days","uint16",4,2,SX_NONE),
    SX_FIELD("modification_hour_bcd","uint8",6,1,SX_NONE),
    SX_FIELD("modification_minute_bcd","uint8",7,1,SX_NONE),
    SX_FIELD("password_mode","uint8",8,1,SX_FLAGS),
    SX_FIELD("reserved","uint8",9,1,SX_RESERVED),
};
static const sx_layout sxdt_cpm3_timestamp_record = {0x607a0037U,"cpm3_timestamp_record",sxdt_cpm3_timestamp_record_fields,SX_COUNT(sxdt_cpm3_timestamp_record_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_cpm3_timestamp_tail_fields[] = {
    SX_FIELD("reserved","uint8",0,1,SX_RESERVED),
};
static const sx_layout sxdt_cpm3_timestamp_tail = {0x607a0038U,"cpm3_timestamp_tail",sxdt_cpm3_timestamp_tail_fields,SX_COUNT(sxdt_cpm3_timestamp_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_cpm_deleted_entry_fields[] = {
    SX_FIELD("status","uint8",0,1,SX_ID),
    SX_FIELD("erased_contents","byte[31]",1,31,SX_NONE),
};
static const sx_layout sxdt_cpm_deleted_entry = {0x607a0039U,"cpm_deleted_entry",sxdt_cpm_deleted_entry_fields,SX_COUNT(sxdt_cpm_deleted_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mgt_compatibility_tail_fields[] = {
    SX_FIELD("legacy_header","byte[10]",0,10,SX_NONE),
};
static const sx_layout sxdt_mgt_compatibility_tail = {0x607a003aU,"mgt_compatibility_tail",sxdt_mgt_compatibility_tail_fields,SX_COUNT(sxdt_mgt_compatibility_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mgt_disk_label_fields[] = {
    SX_FIELD("disk_label","char[10]",0,10,SX_NONE),
};
static const sx_layout sxdt_mgt_disk_label = {0x607a003bU,"mgt_disk_label",sxdt_mgt_disk_label_fields,SX_COUNT(sxdt_mgt_disk_label_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mgt_sam_tail_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("file_type_information","byte[11]",1,11,SX_NONE),
    SX_FIELD("reserved1","byte[4]",12,4,SX_RESERVED),
    SX_FIELD("start_page","uint8",16,1,SX_NONE),
    SX_FIELD("start_offset","uint16",17,2,SX_NONE),
    SX_FIELD("length_pages","uint8",19,1,SX_COUNT_PROP),
    SX_FIELD("length_remainder","uint16",20,2,SX_NONE),
    SX_FIELD("execution_page","uint8",22,1,SX_NONE),
    SX_FIELD("execution_offset_or_line","uint16",23,2,SX_NONE),
    SX_FIELD("save_day","uint8",25,1,SX_NONE),
    SX_FIELD("save_month","uint8",26,1,SX_NONE),
    SX_FIELD("save_year","uint8",27,1,SX_NONE),
    SX_FIELD("save_hour","uint8",28,1,SX_NONE),
    SX_FIELD("save_minute","uint8",29,1,SX_NONE),
    SX_FIELD("directory_tag","uint8",30,1,SX_ID),
    SX_FIELD("reserved2","uint8",31,1,SX_RESERVED),
    SX_FIELD("disk_identifier","uint16be",32,2,SX_ID),
    SX_FIELD("parent_directory_tag","uint8",34,1,SX_ID),
    SX_FIELD("extra_directory_tracks","uint8",35,1,SX_COUNT_PROP),
};
static const sx_layout sxdt_mgt_sam_tail = {0x607a003cU,"mgt_sam_tail",sxdt_mgt_sam_tail_fields,SX_COUNT(sxdt_mgt_sam_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mgt_dos_file_header_fields[] = {
    SX_FIELD("file_type","uint8",0,1,SX_ID),
    SX_FIELD("length_remainder","uint16",1,2,SX_NONE),
    SX_FIELD("start_offset","uint16",3,2,SX_NONE),
    SX_FIELD("parameter","uint16",5,2,SX_NONE),
    SX_FIELD("length_pages","uint8",7,1,SX_COUNT_PROP),
    SX_FIELD("start_page","uint8",8,1,SX_NONE),
};
static const sx_layout sxdt_mgt_dos_file_header = {0x607a003dU,"mgt_dos_file_header",sxdt_mgt_dos_file_header_fields,SX_COUNT(sxdt_mgt_dos_file_header_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_xva_tar_v7_fields[] = {
    SX_FIELD("name","char[100]",0,100,SX_NONE),
    SX_FIELD("mode","ascii_cpio_octal[8]",100,8,SX_FLAGS),
    SX_FIELD("uid","ascii_cpio_octal[8]",108,8,SX_ID),
    SX_FIELD("gid","ascii_cpio_octal[8]",116,8,SX_ID),
    SX_FIELD("data_size","ascii_cpio_octal[12]",124,12,SX_SIZE),
    SX_FIELD("modification_time","ascii_cpio_octal[12]",136,12,SX_TIME),
    SX_FIELD("checksum","ascii_cpio_octal[8]",148,8,SX_CHECKSUM),
    SX_FIELD("type_flag","char[1]",156,1,SX_ID),
    SX_FIELD("link_name","char[100]",157,100,SX_NONE),
    SX_FIELD("padding","byte[255]",257,255,SX_RESERVED),
};
static const sx_layout sxdt_xva_tar_v7 = {0x607a003eU,"xva_tar_v7",sxdt_xva_tar_v7_fields,SX_COUNT(sxdt_xva_tar_v7_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_xva_tar_ustar_fields[] = {
    SX_FIELD("name","char[100]",0,100,SX_NONE),
    SX_FIELD("mode","ascii_cpio_octal[8]",100,8,SX_FLAGS),
    SX_FIELD("uid","ascii_cpio_octal[8]",108,8,SX_ID),
    SX_FIELD("gid","ascii_cpio_octal[8]",116,8,SX_ID),
    SX_FIELD("data_size","ascii_cpio_octal[12]",124,12,SX_SIZE),
    SX_FIELD("modification_time","ascii_cpio_octal[12]",136,12,SX_TIME),
    SX_FIELD("checksum","ascii_cpio_octal[8]",148,8,SX_CHECKSUM),
    SX_FIELD("type_flag","char[1]",156,1,SX_ID),
    SX_FIELD("link_name","char[100]",157,100,SX_NONE),
    SX_FIELD("magic","char[6]",257,6,SX_SIGNATURE),
    SX_FIELD("version","char[2]",263,2,SX_ID),
    SX_FIELD("user_name","char[32]",265,32,SX_NONE),
    SX_FIELD("group_name","char[32]",297,32,SX_NONE),
    SX_FIELD("device_major","ascii_cpio_octal[8]",329,8,SX_ID),
    SX_FIELD("device_minor","ascii_cpio_octal[8]",337,8,SX_ID),
    SX_FIELD("prefix","char[155]",345,155,SX_NONE),
    SX_FIELD("padding","byte[12]",500,12,SX_RESERVED),
};
static const sx_layout sxdt_xva_tar_ustar = {0x607a003fU,"xva_tar_ustar",sxdt_xva_tar_ustar_fields,SX_COUNT(sxdt_xva_tar_ustar_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_xva_sha1_text_fields[] = {
    SX_FIELD("sha1","char[40]",0,40,SX_CHECKSUM),
};
static const sx_layout sxdt_xva_sha1_text = {0x607a0040U,"xva_sha1_text",sxdt_xva_sha1_text_fields,SX_COUNT(sxdt_xva_sha1_text_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_xva_xxhash_text_fields[] = {
    SX_FIELD("xxh64","char[16]",0,16,SX_CHECKSUM),
};
static const sx_layout sxdt_xva_xxhash_text = {0x607a0041U,"xva_xxhash_text",sxdt_xva_xxhash_text_fields,SX_COUNT(sxdt_xva_xxhash_text_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_plan9_keyword_fields[] = {
    SX_FIELD("keyword","utf8",0,0,SX_ID),
};
static const sx_layout sxdt_plan9_keyword = {0x607a0042U,"plan9_keyword",sxdt_plan9_keyword_fields,SX_COUNT(sxdt_plan9_keyword_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_plan9_name_fields[] = {
    SX_FIELD("name","utf8",0,0,SX_NONE),
};
static const sx_layout sxdt_plan9_name = {0x607a0043U,"plan9_name",sxdt_plan9_name_fields,SX_COUNT(sxdt_plan9_name_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_plan9_first_sector_fields[] = {
    SX_FIELD("first_sector","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdt_plan9_first_sector = {0x607a0044U,"plan9_first_sector",sxdt_plan9_first_sector_fields,SX_COUNT(sxdt_plan9_first_sector_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_plan9_end_sector_fields[] = {
    SX_FIELD("exclusive_end_sector","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdt_plan9_end_sector = {0x607a0045U,"plan9_end_sector",sxdt_plan9_end_sector_fields,SX_COUNT(sxdt_plan9_end_sector_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_xva_xml_tag_fields[] = {
    SX_FIELD("tag","utf8",0,0,SX_NONE),
};
static const sx_layout sxdt_xva_xml_tag = {0x607a0046U,"xva_xml_tag",sxdt_xva_xml_tag_fields,SX_COUNT(sxdt_xva_xml_tag_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_xva_xml_member_name_fields[] = {
    SX_FIELD("member_name","utf8",0,0,SX_NONE),
};
static const sx_layout sxdt_xva_xml_member_name = {0x607a0047U,"xva_xml_member_name",sxdt_xva_xml_member_name_fields,SX_COUNT(sxdt_xva_xml_member_name_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_xva_xml_value_fields[] = {
    SX_FIELD("value","utf8",0,0,SX_NONE),
};
static const sx_layout sxdt_xva_xml_value = {0x607a0048U,"xva_xml_value",sxdt_xva_xml_value_fields,SX_COUNT(sxdt_xva_xml_value_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_xml_tag_fields[] = {
    SX_FIELD("tag","utf8",0,0,SX_NONE),
};
static const sx_layout sxdt_hxc_xml_tag = {0x607a0049U,"hxc_xml_tag",sxdt_hxc_xml_tag_fields,SX_COUNT(sxdt_hxc_xml_tag_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_xml_attribute_name_fields[] = {
    SX_FIELD("attribute","utf8",0,0,SX_NONE),
};
static const sx_layout sxdt_hxc_xml_attribute_name = {0x607a004aU,"hxc_xml_attribute_name",sxdt_hxc_xml_attribute_name_fields,SX_COUNT(sxdt_hxc_xml_attribute_name_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_disk_layout_name_fields[] = {
    SX_FIELD("disk_layout_name","utf8",0,0,SX_NONE),
};
static const sx_layout sxdt_hxc_disk_layout_name = {0x607a004bU,"hxc_disk_layout_name",sxdt_hxc_disk_layout_name_fields,SX_COUNT(sxdt_hxc_disk_layout_name_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_sector_data_fields[] = {
    SX_FIELD("sector_data","utf8",0,0,SX_NONE),
};
static const sx_layout sxdt_hxc_sector_data = {0x607a004cU,"hxc_sector_data",sxdt_hxc_sector_data_fields,SX_COUNT(sxdt_hxc_sector_data_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_file_size_fields[] = {
    SX_FIELD("file_size","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxdt_hxc_file_size = {0x607a004dU,"hxc_file_size",sxdt_hxc_file_size_fields,SX_COUNT(sxdt_hxc_file_size_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_file_size_hex_fields[] = {
    SX_FIELD("file_size","ascii_hex",0,0,SX_SIZE),
};
static const sx_layout sxdt_hxc_file_size_hex = {0x607a004eU,"hxc_file_size_hex",sxdt_hxc_file_size_hex_fields,SX_COUNT(sxdt_hxc_file_size_hex_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_number_of_track_fields[] = {
    SX_FIELD("number_of_track","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdt_hxc_number_of_track = {0x607a004fU,"hxc_number_of_track",sxdt_hxc_number_of_track_fields,SX_COUNT(sxdt_hxc_number_of_track_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_number_of_track_hex_fields[] = {
    SX_FIELD("number_of_track","ascii_hex",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdt_hxc_number_of_track_hex = {0x607a0050U,"hxc_number_of_track_hex",sxdt_hxc_number_of_track_hex_fields,SX_COUNT(sxdt_hxc_number_of_track_hex_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_number_of_side_fields[] = {
    SX_FIELD("number_of_side","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdt_hxc_number_of_side = {0x607a0051U,"hxc_number_of_side",sxdt_hxc_number_of_side_fields,SX_COUNT(sxdt_hxc_number_of_side_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_number_of_side_hex_fields[] = {
    SX_FIELD("number_of_side","ascii_hex",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdt_hxc_number_of_side_hex = {0x607a0052U,"hxc_number_of_side_hex",sxdt_hxc_number_of_side_hex_fields,SX_COUNT(sxdt_hxc_number_of_side_hex_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_sector_per_track_fields[] = {
    SX_FIELD("sector_per_track","ascii_signed",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdt_hxc_sector_per_track = {0x607a0053U,"hxc_sector_per_track",sxdt_hxc_sector_per_track_fields,SX_COUNT(sxdt_hxc_sector_per_track_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_sector_per_track_hex_fields[] = {
    SX_FIELD("sector_per_track","ascii_hex",0,0,SX_COUNT_PROP),
};
static const sx_layout sxdt_hxc_sector_per_track_hex = {0x607a0054U,"hxc_sector_per_track_hex",sxdt_hxc_sector_per_track_hex_fields,SX_COUNT(sxdt_hxc_sector_per_track_hex_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_sector_size_fields[] = {
    SX_FIELD("sector_size","ascii_signed",0,0,SX_SIZE),
};
static const sx_layout sxdt_hxc_sector_size = {0x607a0055U,"hxc_sector_size",sxdt_hxc_sector_size_fields,SX_COUNT(sxdt_hxc_sector_size_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_sector_size_hex_fields[] = {
    SX_FIELD("sector_size","ascii_hex",0,0,SX_SIZE),
};
static const sx_layout sxdt_hxc_sector_size_hex = {0x607a0056U,"hxc_sector_size_hex",sxdt_hxc_sector_size_hex_fields,SX_COUNT(sxdt_hxc_sector_size_hex_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_start_sector_id_fields[] = {
    SX_FIELD("start_sector_id","ascii_signed",0,0,SX_ID),
};
static const sx_layout sxdt_hxc_start_sector_id = {0x607a0057U,"hxc_start_sector_id",sxdt_hxc_start_sector_id_fields,SX_COUNT(sxdt_hxc_start_sector_id_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_start_sector_id_hex_fields[] = {
    SX_FIELD("start_sector_id","ascii_hex",0,0,SX_ID),
};
static const sx_layout sxdt_hxc_start_sector_id_hex = {0x607a0058U,"hxc_start_sector_id_hex",sxdt_hxc_start_sector_id_hex_fields,SX_COUNT(sxdt_hxc_start_sector_id_hex_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_formatvalue_fields[] = {
    SX_FIELD("formatvalue","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdt_hxc_formatvalue = {0x607a0059U,"hxc_formatvalue",sxdt_hxc_formatvalue_fields,SX_COUNT(sxdt_hxc_formatvalue_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_formatvalue_hex_fields[] = {
    SX_FIELD("formatvalue","ascii_hex",0,0,SX_NONE),
};
static const sx_layout sxdt_hxc_formatvalue_hex = {0x607a005aU,"hxc_formatvalue_hex",sxdt_hxc_formatvalue_hex_fields,SX_COUNT(sxdt_hxc_formatvalue_hex_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_data_fill_fields[] = {
    SX_FIELD("data_fill","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdt_hxc_data_fill = {0x607a005bU,"hxc_data_fill",sxdt_hxc_data_fill_fields,SX_COUNT(sxdt_hxc_data_fill_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_data_fill_hex_fields[] = {
    SX_FIELD("data_fill","ascii_hex",0,0,SX_NONE),
};
static const sx_layout sxdt_hxc_data_fill_hex = {0x607a005cU,"hxc_data_fill_hex",sxdt_hxc_data_fill_hex_fields,SX_COUNT(sxdt_hxc_data_fill_hex_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_data_offset_fields[] = {
    SX_FIELD("data_offset","ascii_signed",0,0,SX_OFFSET),
};
static const sx_layout sxdt_hxc_data_offset = {0x607a005dU,"hxc_data_offset",sxdt_hxc_data_offset_fields,SX_COUNT(sxdt_hxc_data_offset_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_data_offset_hex_fields[] = {
    SX_FIELD("data_offset","ascii_hex",0,0,SX_OFFSET),
};
static const sx_layout sxdt_hxc_data_offset_hex = {0x607a005eU,"hxc_data_offset_hex",sxdt_hxc_data_offset_hex_fields,SX_COUNT(sxdt_hxc_data_offset_hex_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_sector_id_fields[] = {
    SX_FIELD("sector_id","ascii_signed",0,0,SX_ID),
};
static const sx_layout sxdt_hxc_sector_id = {0x607a005fU,"hxc_sector_id",sxdt_hxc_sector_id_fields,SX_COUNT(sxdt_hxc_sector_id_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_sector_id_hex_fields[] = {
    SX_FIELD("sector_id","ascii_hex",0,0,SX_ID),
};
static const sx_layout sxdt_hxc_sector_id_hex = {0x607a0060U,"hxc_sector_id_hex",sxdt_hxc_sector_id_hex_fields,SX_COUNT(sxdt_hxc_sector_id_hex_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_track_number_fields[] = {
    SX_FIELD("track_number","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdt_hxc_track_number = {0x607a0061U,"hxc_track_number",sxdt_hxc_track_number_fields,SX_COUNT(sxdt_hxc_track_number_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_track_number_hex_fields[] = {
    SX_FIELD("track_number","ascii_hex",0,0,SX_NONE),
};
static const sx_layout sxdt_hxc_track_number_hex = {0x607a0062U,"hxc_track_number_hex",sxdt_hxc_track_number_hex_fields,SX_COUNT(sxdt_hxc_track_number_hex_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_side_number_fields[] = {
    SX_FIELD("side_number","ascii_signed",0,0,SX_NONE),
};
static const sx_layout sxdt_hxc_side_number = {0x607a0063U,"hxc_side_number",sxdt_hxc_side_number_fields,SX_COUNT(sxdt_hxc_side_number_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_hxc_side_number_hex_fields[] = {
    SX_FIELD("side_number","ascii_hex",0,0,SX_NONE),
};
static const sx_layout sxdt_hxc_side_number_hex = {0x607a0064U,"hxc_side_number_hex",sxdt_hxc_side_number_hex_fields,SX_COUNT(sxdt_hxc_side_number_hex_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_mgt_legacy_tail_fields[] = {
    SX_FIELD("type_specific_storage","byte[36]",0,36,SX_NONE),
};
static const sx_layout sxdt_mgt_legacy_tail = {0x607a0065U,"mgt_legacy_tail",sxdt_mgt_legacy_tail_fields,SX_COUNT(sxdt_mgt_legacy_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_solar_volume_identity_fields[] = {
    SX_FIELD("boot_prefix","byte[11]",0,11,SX_NONE),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
    SX_FIELD("unknown13","byte[5]",13,5,SX_NONE),
    SX_FIELD("total_sectors","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("unknown20","byte[17]",20,17,SX_NONE),
    SX_FIELD("extended_signature","uint8",37,1,SX_SIGNATURE),
    SX_FIELD("unknown38","byte[4]",38,4,SX_NONE),
    SX_FIELD("volume_label","char[11]",42,11,SX_NONE),
    SX_FIELD("filesystem_signature","char[8]",53,8,SX_SIGNATURE),
};
static const sx_layout sxdt_solar_volume_identity = {0x607a0066U,"solar_volume_identity",sxdt_solar_volume_identity_fields,SX_COUNT(sxdt_solar_volume_identity_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_lisa_dc42_header_fields[] = {
    SX_FIELD("name_length","uint8",0,1,SX_SIZE),
    SX_FIELD("name","char[63]",1,63,SX_NONE),
    SX_FIELD("data_size","uint32",64,4,SX_SIZE),
    SX_FIELD("tag_size","uint32",68,4,SX_SIZE),
    SX_FIELD("data_checksum","uint32",72,4,SX_CHECKSUM),
    SX_FIELD("tag_checksum","uint32",76,4,SX_CHECKSUM),
    SX_FIELD("encoding","uint8",80,1,SX_ID),
    SX_FIELD("format","uint8",81,1,SX_ID),
    SX_FIELD("magic","uint16",82,2,SX_SIGNATURE),
};
static const sx_layout sxdt_lisa_dc42_header = {0x607a0067U,"lisa_dc42_header",sxdt_lisa_dc42_header_fields,SX_COUNT(sxdt_lisa_dc42_header_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_lisa_microfloppy_loader_fields[] = {
    SX_FIELD("jump_instruction","byte[4]",0,4,SX_NONE),
    SX_FIELD("boot_id","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("loader_version","uint16",6,2,SX_ID),
    SX_FIELD("global_data_size","int16",8,2,SX_SIZE),
    SX_FIELD("code_size","int16",10,2,SX_SIZE),
    SX_FIELD("entry_offset","int16",12,2,SX_OFFSET),
    SX_FIELD("mddf_block","int16",14,2,SX_NONE),
};
static const sx_layout sxdt_lisa_microfloppy_loader = {0x607a0068U,"lisa_microfloppy_loader",sxdt_lisa_microfloppy_loader_fields,SX_COUNT(sxdt_lisa_microfloppy_loader_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_lisa_microfloppy_tag_fields[] = {
    SX_FIELD("version","int16",0,2,SX_NONE),
    SX_FIELD("volume_id","int16",2,2,SX_ID),
    SX_FIELD("file_id","int16",4,2,SX_ID),
    SX_FIELD("relative_page","int16",6,2,SX_NONE),
    SX_FIELD("forward_link_and_used_high","uint16",8,2,SX_NONE),
    SX_FIELD("backward_link_and_used_low","uint16",10,2,SX_NONE),
};
static const sx_layout sxdt_lisa_microfloppy_tag = {0x607a0069U,"lisa_microfloppy_tag",sxdt_lisa_microfloppy_tag_fields,SX_COUNT(sxdt_lisa_microfloppy_tag_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_lisa_mddf_fields[] = {
    SX_FIELD("filesystem_version","int16",0,2,SX_ID),
    SX_FIELD("volume_id","uint32[2]",2,8,SX_ID),
    SX_FIELD("volume_number","int16",10,2,SX_NONE),
    SX_FIELD("volume_name_pascal","char[33]",12,33,SX_NONE),
    SX_FIELD("padc1","byte[1]",45,1,SX_NONE),
    SX_FIELD("password","char[33]",46,33,SX_NONE),
    SX_FIELD("padc2","byte[1]",79,1,SX_NONE),
    SX_FIELD("init_machine_id","int32",80,4,SX_NONE),
    SX_FIELD("master_machine_id","int32",84,4,SX_NONE),
    SX_FIELD("creation_time","uint32",88,4,SX_TIME),
    SX_FIELD("copy_creation_time","uint32",92,4,SX_TIME),
    SX_FIELD("copy_time","uint32",96,4,SX_TIME),
    SX_FIELD("scavenge_time","uint32",100,4,SX_TIME),
    SX_FIELD("copy_thread","int32",104,4,SX_NONE),
    SX_FIELD("firstblock","int32",108,4,SX_NONE),
    SX_FIELD("lastblock","int32",112,4,SX_NONE),
    SX_FIELD("lastfspage","int32",116,4,SX_NONE),
    SX_FIELD("block_count","int32",120,4,SX_COUNT_PROP),
    SX_FIELD("block_size","int16",124,2,SX_SIZE),
    SX_FIELD("data_size","int16",126,2,SX_SIZE),
    SX_FIELD("cluster_size","int16",128,2,SX_NONE),
    SX_FIELD("mddf_page","int32",130,4,SX_NONE),
    SX_FIELD("mddf_size","int16",134,2,SX_SIZE),
    SX_FIELD("bitmap_addr","int32",136,4,SX_NONE),
    SX_FIELD("bitmap_size","int32",140,4,SX_NONE),
    SX_FIELD("bitmap_bytes","int16",144,2,SX_SIZE),
    SX_FIELD("bitmap_pages","int16",146,2,SX_COUNT_PROP),
    SX_FIELD("slist_addr","int32",148,4,SX_NONE),
    SX_FIELD("slist_entries_per_block","int16",152,2,SX_COUNT_PROP),
    SX_FIELD("slist_block_count","int16",154,2,SX_COUNT_PROP),
    SX_FIELD("first_file","int16",156,2,SX_ID),
    SX_FIELD("empty_file","int16",158,2,SX_ID),
    SX_FIELD("maximum_files","int16",160,2,SX_COUNT_PROP),
    SX_FIELD("hint_size","int16",162,2,SX_SIZE),
    SX_FIELD("leader_offset","int16",164,2,SX_OFFSET),
    SX_FIELD("leader_pages","int16",166,2,SX_COUNT_PROP),
    SX_FIELD("flabel_offset","int16",168,2,SX_OFFSET),
    SX_FIELD("unusedi1","int16",170,2,SX_NONE),
    SX_FIELD("map_offset","int16",172,2,SX_OFFSET),
    SX_FIELD("map_size","int16",174,2,SX_NONE),
    SX_FIELD("file_count","int16",176,2,SX_COUNT_PROP),
    SX_FIELD("freestart","int32",178,4,SX_NONE),
    SX_FIELD("unusedl1","int32",182,4,SX_NONE),
    SX_FIELD("free_page_count","int32",186,4,SX_COUNT_PROP),
    SX_FIELD("rootsnum","int16",190,2,SX_ID),
    SX_FIELD("rootmaxentries","int16",192,2,SX_COUNT_PROP),
    SX_FIELD("mountinfo","int8",194,1,SX_ID),
    SX_FIELD("mountinfo_pad","int8",195,1,SX_NONE),
    SX_FIELD("overmount_stamp","uint32[2]",196,8,SX_ID),
    SX_FIELD("pmem_id","int32",204,4,SX_NONE),
    SX_FIELD("pmem","int16[32]",208,64,SX_NONE),
    SX_FIELD("vol_scavenged","int16",272,2,SX_FLAGS),
    SX_FIELD("tbt_copied","int16",274,2,SX_FLAGS),
    SX_FIELD("smallmap_offset","int16",276,2,SX_OFFSET),
    SX_FIELD("hentry_offset","int16",278,2,SX_OFFSET),
    SX_FIELD("backup_volid","uint32[2]",280,8,SX_ID),
    SX_FIELD("file_label_size","int16",288,2,SX_SIZE),
    SX_FIELD("fs_overhead","int16",290,2,SX_COUNT_PROP),
    SX_FIELD("result_scavenge","int16",292,2,SX_NONE),
    SX_FIELD("boot_code","int16",294,2,SX_NONE),
    SX_FIELD("boot_environ","int16",296,2,SX_NONE),
    SX_FIELD("oem_id","int32",298,4,SX_NONE),
    SX_FIELD("root_page","int32",302,4,SX_NONE),
    SX_FIELD("tree_depth","int16",306,2,SX_NONE),
    SX_FIELD("node_id","int16",308,2,SX_NONE),
    SX_FIELD("vol_seq_no","int16",310,2,SX_NONE),
    SX_FIELD("volume_mounted","int16",312,2,SX_FLAGS),
};
static const sx_layout sxdt_lisa_mddf = {0x607a006aU,"lisa_mddf",sxdt_lisa_mddf_fields,SX_COUNT(sxdt_lisa_mddf_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_lisa_sfile_entry_fields[] = {
    SX_FIELD("hintaddr","int32",0,4,SX_NONE),
    SX_FIELD("fileaddr","int32",4,4,SX_NONE),
    SX_FIELD("filesize","int32",8,4,SX_SIZE),
    SX_FIELD("version","int16",12,2,SX_NONE),
};
static const sx_layout sxdt_lisa_sfile_entry = {0x607a006bU,"lisa_sfile_entry",sxdt_lisa_sfile_entry_fields,SX_COUNT(sxdt_lisa_sfile_entry_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_lisa_hint_entry_fields[] = {
    SX_FIELD("name","char[33]",0,33,SX_NONE),
    SX_FIELD("name_pad","byte[1]",33,1,SX_NONE),
    SX_FIELD("UID","uint32[2]",34,8,SX_ID),
    SX_FIELD("version","int16",42,2,SX_NONE),
    SX_FIELD("ftype","int8",44,1,SX_ID),
    SX_FIELD("ftype_pad","int8",45,1,SX_NONE),
    SX_FIELD("date_created","uint32",46,4,SX_TIME),
    SX_FIELD("date_accessed","uint32",50,4,SX_TIME),
    SX_FIELD("date_modified","uint32",54,4,SX_TIME),
    SX_FIELD("date_backup","uint32",58,4,SX_TIME),
    SX_FIELD("date_scavenged","uint32",62,4,SX_TIME),
    SX_FIELD("machine_id","int32",66,4,SX_NONE),
    SX_FIELD("killed","int8",70,1,SX_FLAGS),
    SX_FIELD("safety_on","int8",71,1,SX_FLAGS),
    SX_FIELD("protected","int8",72,1,SX_FLAGS),
    SX_FIELD("master","int8",73,1,SX_FLAGS),
    SX_FIELD("close_by_OS","int8",74,1,SX_FLAGS),
    SX_FIELD("file_open","int8",75,1,SX_FLAGS),
    SX_FIELD("result_scavenge","int16",76,2,SX_NONE),
    SX_FIELD("unusedi1","int16",78,2,SX_NONE),
    SX_FIELD("system_type","int16",80,2,SX_NONE),
    SX_FIELD("user_type","int16",82,2,SX_NONE),
    SX_FIELD("user_subtype","int16",84,2,SX_NONE),
    SX_FIELD("build_info","int16[4]",86,8,SX_NONE),
    SX_FIELD("file_portion","int16",94,2,SX_NONE),
    SX_FIELD("password","char[9]",96,9,SX_NONE),
    SX_FIELD("password_pad","char[3]",105,3,SX_NONE),
    SX_FIELD("parent_id","int16",108,2,SX_ID),
    SX_FIELD("filesystem_overhead","int16",110,2,SX_NONE),
};
static const sx_layout sxdt_lisa_hint_entry = {0x607a006cU,"lisa_hint_entry",sxdt_lisa_hint_entry_fields,SX_COUNT(sxdt_lisa_hint_entry_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_lisa_filemap_header_fields[] = {
    SX_FIELD("block_count","int32",0,4,SX_COUNT_PROP),
    SX_FIELD("maximum_entries","int16",4,2,SX_COUNT_PROP),
    SX_FIELD("extent_count","int16",6,2,SX_COUNT_PROP),
};
static const sx_layout sxdt_lisa_filemap_header = {0x607a006dU,"lisa_filemap_header",sxdt_lisa_filemap_header_fields,SX_COUNT(sxdt_lisa_filemap_header_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_lisa_filemap_extent_fields[] = {
    SX_FIELD("first_page","int32",0,4,SX_NONE),
    SX_FIELD("page_count","int16",4,2,SX_COUNT_PROP),
};
static const sx_layout sxdt_lisa_filemap_extent = {0x607a006eU,"lisa_filemap_extent",sxdt_lisa_filemap_extent_fields,SX_COUNT(sxdt_lisa_filemap_extent_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_lisa_flat_catalog_entry_fields[] = {
    SX_FIELD("name","char[33]",0,33,SX_NONE),
    SX_FIELD("name_pad","byte[1]",33,1,SX_NONE),
    SX_FIELD("cetype","int8",34,1,SX_ID),
    SX_FIELD("cetype_pad","int8",35,1,SX_NONE),
    SX_FIELD("file_id","int16",36,2,SX_ID),
    SX_FIELD("attributes","int32",38,4,SX_NONE),
    SX_FIELD("readpage","int32",42,4,SX_NONE),
    SX_FIELD("readoffset","int16",46,2,SX_OFFSET),
    SX_FIELD("writepage","int32",48,4,SX_NONE),
    SX_FIELD("writeoffset","int16",52,2,SX_OFFSET),
};
static const sx_layout sxdt_lisa_flat_catalog_entry = {0x607a006fU,"lisa_flat_catalog_entry",sxdt_lisa_flat_catalog_entry_fields,SX_COUNT(sxdt_lisa_flat_catalog_entry_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_lisa_btree_key_fields[] = {
    SX_FIELD("key_length","uint8",0,1,SX_SIZE),
    SX_FIELD("parent_id","int16",1,2,SX_ID),
    SX_FIELD("name","char[33]",3,33,SX_NONE),
    SX_FIELD("entry_type","int8",36,1,SX_ID),
    SX_FIELD("stored_padding","int8",37,1,SX_NONE),
};
static const sx_layout sxdt_lisa_btree_key = {0x607a0070U,"lisa_btree_key",sxdt_lisa_btree_key_fields,SX_COUNT(sxdt_lisa_btree_key_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_lisa_btree_directory_fields[] = {
    SX_FIELD("directory_id","int16",0,2,SX_ID),
    SX_FIELD("creation_time","uint32",2,4,SX_TIME),
    SX_FIELD("unused","int32",6,4,SX_NONE),
};
static const sx_layout sxdt_lisa_btree_directory = {0x607a0071U,"lisa_btree_directory",sxdt_lisa_btree_directory_fields,SX_COUNT(sxdt_lisa_btree_directory_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_lisa_btree_object_fields[] = {
    SX_FIELD("file_id","int16",0,2,SX_ID),
    SX_FIELD("creation_time","uint32",2,4,SX_TIME),
    SX_FIELD("modification_time","uint32",6,4,SX_TIME),
    SX_FIELD("logical_size","int32",10,4,SX_SIZE),
    SX_FIELD("physical_size","int32",14,4,SX_SIZE),
    SX_FIELD("filesystem_overhead","int16",18,2,SX_COUNT_PROP),
    SX_FIELD("flags","int16",20,2,SX_FLAGS),
    SX_FIELD("unused","int32",22,4,SX_NONE),
};
static const sx_layout sxdt_lisa_btree_object = {0x607a0072U,"lisa_btree_object",sxdt_lisa_btree_object_fields,SX_COUNT(sxdt_lisa_btree_object_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_lisa_btree_thread_fields[] = {
    SX_FIELD("parent_id","int16",0,2,SX_ID),
    SX_FIELD("name","char[33]",2,33,SX_NONE),
    SX_FIELD("stored_padding","byte[1]",35,1,SX_NONE),
    SX_FIELD("unused","int32",36,4,SX_NONE),
};
static const sx_layout sxdt_lisa_btree_thread = {0x607a0073U,"lisa_btree_thread",sxdt_lisa_btree_thread_fields,SX_COUNT(sxdt_lisa_btree_thread_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_lisa_btree_footer_fields[] = {
    SX_FIELD("record_count","int16",0,2,SX_COUNT_PROP),
    SX_FIELD("previous_node","int32",2,4,SX_NONE),
    SX_FIELD("next_node","int32",6,4,SX_NONE),
    SX_FIELD("kind","int8",10,1,SX_ID),
    SX_FIELD("checksum","int8",11,1,SX_CHECKSUM),
};
static const sx_layout sxdt_lisa_btree_footer = {0x607a0074U,"lisa_btree_footer",sxdt_lisa_btree_footer_fields,SX_COUNT(sxdt_lisa_btree_footer_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_lisa_btree_offset_fields[] = {
    SX_FIELD("record_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxdt_lisa_btree_offset = {0x607a0075U,"lisa_btree_offset",sxdt_lisa_btree_offset_fields,SX_COUNT(sxdt_lisa_btree_offset_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_lisa_btree_child_fields[] = {
    SX_FIELD("child_page","int32",0,4,SX_NONE),
};
static const sx_layout sxdt_lisa_btree_child = {0x607a0076U,"lisa_btree_child",sxdt_lisa_btree_child_fields,SX_COUNT(sxdt_lisa_btree_child_fields),SX_BE};

static const xx_data_struct_field_desc sxdt_hxc_xml_text_fields[] = {
    SX_FIELD("text","utf8",0,0,SX_NONE),
};
static const sx_layout sxdt_hxc_xml_text = {0x607a0077U,"hxc_xml_text",sxdt_hxc_xml_text_fields,SX_COUNT(sxdt_hxc_xml_text_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_apricot_fat12_pair_fields[] = {
    SX_FIELD("packed_cluster_links","uint24",0,3,SX_NONE),
};
static const sx_layout sxdt_apricot_fat12_pair = {0x607a0078U,"apricot_fat12_pair",sxdt_apricot_fat12_pair_fields,SX_COUNT(sxdt_apricot_fat12_pair_fields),SX_LE};

static const xx_data_struct_field_desc sxdt_apricot_directory_entry_fields[] = {
    SX_FIELD("filename","char[8]",0,8,SX_NONE),
    SX_FIELD("extension","char[3]",8,3,SX_NONE),
    SX_FIELD("attributes","uint8",11,1,SX_FLAGS),
    SX_FIELD("reserved_legacy","byte[10]",12,10,SX_NONE),
    SX_FIELD("modification_time_packed","uint16",22,2,SX_NONE),
    SX_FIELD("modification_date_packed","uint16",24,2,SX_NONE),
    SX_FIELD("first_cluster","uint16",26,2,SX_NONE),
    SX_FIELD("file_size","uint32",28,4,SX_SIZE),
};
static const sx_layout sxdt_apricot_directory_entry = {0x607a0079U,"apricot_directory_entry",sxdt_apricot_directory_entry_fields,SX_COUNT(sxdt_apricot_directory_entry_fields),SX_LE};

static const sx_layout *const sx_disktail_layouts[] = {
    &sxdt_rdos_catalog_entry,
    &sxdt_mac_ts_driver_descriptor,
    &sxdt_mac_ts_map_header,
    &sxdt_mac_ts_partition,
    &sxdt_ppm_header,
    &sxdt_ppm_volume_entry,
    &sxdt_ppm_volume_description,
    &sxdt_ppm_cached_volume_name,
    &sxdt_apricot_label_prefix,
    &sxdt_apricot_bpb,
    &sxdt_cpm_extent8,
    &sxdt_cpm_extent16,
    &sxdt_atom_catalog_name_header,
    &sxdt_atom_catalog_info_header,
    &sxdt_atom_catalog_name,
    &sxdt_atom_catalog_info,
    &sxdt_casio_disk_header,
    &sxdt_casio_allocation_byte,
    &sxdt_casio_directory_entry,
    &sxdt_casio_file_extent,
    &sxdt_casio_file_counts,
    &sxdt_rawcd_sector_header,
    &sxdt_rawcd_xa_subheader,
    &sxdt_rawcd_edc,
    &sxdt_mgt_directory_core,
    &sxdt_mgt_sector_link,
    &sxdt_mapped_prodos_directory_links,
    &sxdt_mapped_prodos_volume_header,
    &sxdt_mapped_prodos_subdirectory_header,
    &sxdt_mapped_prodos_file_entry,
    &sxdt_mapped_prodos_fork_descriptor,
    &sxdt_mapped_prodos_index_low,
    &sxdt_mapped_prodos_index_high,
    &sxdt_mapped_pascal_volume_header,
    &sxdt_mapped_pascal_file_entry,
    &sxdt_mapped_apple_dos_vtoc,
    &sxdt_mapped_apple_dos_bitmap,
    &sxdt_mapped_apple_dos_catalog_header,
    &sxdt_mapped_apple_dos_file_entry,
    &sxdt_mapped_apple_dos_ts_header,
    &sxdt_mapped_apple_dos_ts_pair,
    &sxdt_mapped_hfs_master_directory,
    &sxdt_mapped_hfs_btree_node,
    &sxdt_mapped_hfs_btree_header,
    &sxdt_mapped_hfs_node_record_offset,
    &sxdt_mapped_hfs_catalog_key_prefix,
    &sxdt_mapped_hfs_extents_key,
    &sxdt_mapped_hfs_extent,
    &sxdt_mapped_hfs_btree_child,
    &sxdt_mapped_hfs_catalog_folder,
    &sxdt_mapped_hfs_catalog_file,
    &sxdt_mapped_hfs_catalog_thread,
    &sxdt_cpm3_volume_label,
    &sxdt_cpm3_timestamp_status,
    &sxdt_cpm3_timestamp_record,
    &sxdt_cpm3_timestamp_tail,
    &sxdt_cpm_deleted_entry,
    &sxdt_mgt_compatibility_tail,
    &sxdt_mgt_disk_label,
    &sxdt_mgt_sam_tail,
    &sxdt_mgt_dos_file_header,
    &sxdt_xva_tar_v7,
    &sxdt_xva_tar_ustar,
    &sxdt_xva_sha1_text,
    &sxdt_xva_xxhash_text,
    &sxdt_plan9_keyword,
    &sxdt_plan9_name,
    &sxdt_plan9_first_sector,
    &sxdt_plan9_end_sector,
    &sxdt_xva_xml_tag,
    &sxdt_xva_xml_member_name,
    &sxdt_xva_xml_value,
    &sxdt_hxc_xml_tag,
    &sxdt_hxc_xml_attribute_name,
    &sxdt_hxc_disk_layout_name,
    &sxdt_hxc_sector_data,
    &sxdt_hxc_file_size,
    &sxdt_hxc_file_size_hex,
    &sxdt_hxc_number_of_track,
    &sxdt_hxc_number_of_track_hex,
    &sxdt_hxc_number_of_side,
    &sxdt_hxc_number_of_side_hex,
    &sxdt_hxc_sector_per_track,
    &sxdt_hxc_sector_per_track_hex,
    &sxdt_hxc_sector_size,
    &sxdt_hxc_sector_size_hex,
    &sxdt_hxc_start_sector_id,
    &sxdt_hxc_start_sector_id_hex,
    &sxdt_hxc_formatvalue,
    &sxdt_hxc_formatvalue_hex,
    &sxdt_hxc_data_fill,
    &sxdt_hxc_data_fill_hex,
    &sxdt_hxc_data_offset,
    &sxdt_hxc_data_offset_hex,
    &sxdt_hxc_sector_id,
    &sxdt_hxc_sector_id_hex,
    &sxdt_hxc_track_number,
    &sxdt_hxc_track_number_hex,
    &sxdt_hxc_side_number,
    &sxdt_hxc_side_number_hex,
    &sxdt_mgt_legacy_tail,
    &sxdt_solar_volume_identity,
    &sxdt_lisa_dc42_header,
    &sxdt_lisa_microfloppy_loader,
    &sxdt_lisa_microfloppy_tag,
    &sxdt_lisa_mddf,
    &sxdt_lisa_sfile_entry,
    &sxdt_lisa_hint_entry,
    &sxdt_lisa_filemap_header,
    &sxdt_lisa_filemap_extent,
    &sxdt_lisa_flat_catalog_entry,
    &sxdt_lisa_btree_key,
    &sxdt_lisa_btree_directory,
    &sxdt_lisa_btree_object,
    &sxdt_lisa_btree_thread,
    &sxdt_lisa_btree_footer,
    &sxdt_lisa_btree_offset,
    &sxdt_lisa_btree_child,
    &sxdt_hxc_xml_text,
    &sxdt_apricot_fat12_pair,
    &sxdt_apricot_directory_entry,
};

static bool sx_disktail_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x607a0000U||id>=0x607b0000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    switch(id){
    case 0x607a0001U:
        if(!xx_rt_wcscmp(r->name,L"filename"))s=L"High-bit ASCII filename, space padded";
        else if(!xx_rt_wcscmp(r->name,L"file_type"))s=L"High-bit ASCII A,B,T,S; space marks deleted entries";
        else if(!xx_rt_wcscmp(r->name,L"sectors_used"))s=L"Number of 256-byte logical sectors";
        else if(!xx_rt_wcscmp(r->name,L"load_address"))s=L"Meaningful for binary files; unused for Applesoft/text";
        else if(!xx_rt_wcscmp(r->name,L"file_size"))s=L"Text file length is rounded to sectors";
        else if(!xx_rt_wcscmp(r->name,L"first_logical_sector"))s=L"Logical sector index, not a byte offset";
        break;
    case 0x607a0002U:
        if(!xx_rt_wcscmp(r->name,L"driver_start_block"))s=L"Block number in the parent disk";
        else if(!xx_rt_wcscmp(r->name,L"driver_size_blocks"))s=L"Driver length in 512-byte blocks";
        break;
    case 0x607a0004U:
        if(!xx_rt_wcscmp(r->name,L"start_block"))s=L"Physical block number, not a byte offset";
        break;
    case 0x607a0006U:
        if(!xx_rt_wcscmp(r->name,L"absolute_start_block"))s=L"512-byte block number from the ProDOS disk start, not the PPM area";
        else if(!xx_rt_wcscmp(r->name,L"write_protection"))s=L"High bit enables write protection";
        break;
    case 0x607a000bU:
        if(!xx_rt_wcscmp(r->name,L"user_or_status"))s=L"0..15=user;229=deleted; CP/M3 metadata uses other status bytes";
        else if(!xx_rt_wcscmp(r->name,L"filename_and_attributes"))s=L"7-bit filename; high bits F1..F4 are flags";
        else if(!xx_rt_wcscmp(r->name,L"extension_and_attributes"))s=L"7-bit extension; high bits are read-only/system/archive";
        else if(!xx_rt_wcscmp(r->name,L"extent_low"))s=L"Low5 bits of the logical extent number";
        else if(!xx_rt_wcscmp(r->name,L"s1"))s=L"Reserved unless caller explicitly selected last-record-used semantics";
        else if(!xx_rt_wcscmp(r->name,L"extent_high"))s=L"High extent number bits; range depends on CP/M version";
        else if(!xx_rt_wcscmp(r->name,L"record_count"))s=L"128-byte records in the final logical extent";
        else if(!xx_rt_wcscmp(r->name,L"allocation_blocks"))s=L"Allocation block numbers, not byte offsets";
        break;
    case 0x607a000cU:
        if(!xx_rt_wcscmp(r->name,L"filename_and_attributes"))s=L"7-bit filename with encoded flags";
        else if(!xx_rt_wcscmp(r->name,L"extension_and_attributes"))s=L"7-bit extension with encoded flags";
        else if(!xx_rt_wcscmp(r->name,L"extent_low"))s=L"Low5 bits of logical extent";
        else if(!xx_rt_wcscmp(r->name,L"s1"))s=L"Caller-dependent final-record byte count or reserved";
        else if(!xx_rt_wcscmp(r->name,L"record_count"))s=L"128-byte records";
        else if(!xx_rt_wcscmp(r->name,L"allocation_blocks"))s=L"Little-endian allocation block numbers";
        break;
    case 0x607a000eU:
        if(!xx_rt_wcscmp(r->name,L"file_count_times8"))s=L"Stored byte is the directory entry count multiplied by8";
        else if(!xx_rt_wcscmp(r->name,L"disk_size_high_and_boot"))s=L"Bits0..1=sector count high bits; bits4..5=boot option";
        else if(!xx_rt_wcscmp(r->name,L"disk_sectors_low"))s=L"Low8 bits of total256-byte sector count";
        break;
    case 0x607a000fU:
        if(!xx_rt_wcscmp(r->name,L"directory_and_lock"))s=L"Low7bits directory qualifier, bit7 locked";
        break;
    case 0x607a0010U:
        if(!xx_rt_wcscmp(r->name,L"load_address_low"))s=L"Low16bits of encoded address; Atom native scope requires high bits zero";
        else if(!xx_rt_wcscmp(r->name,L"execution_address_low"))s=L"Low16bits of encoded address";
        else if(!xx_rt_wcscmp(r->name,L"file_length_low"))s=L"Low16bits of byte length";
        else if(!xx_rt_wcscmp(r->name,L"high_bits"))s=L"Start-sector high2, load high2, length high2, execution high2";
        else if(!xx_rt_wcscmp(r->name,L"start_sector_low"))s=L"Low8bits of256-byte sector index";
        break;
    case 0x607a0012U:
        if(!xx_rt_wcscmp(r->name,L"sector_bitmap"))s=L"One LSB-first bit per1024-byte physical sector";
        break;
    case 0x607a0013U:
        if(!xx_rt_wcscmp(r->name,L"content_type"))s=L"0=full,1=voice,2=bank,3=effect,4=sequence,5=expanded program";
        else if(!xx_rt_wcscmp(r->name,L"continuation"))s=L"0=first disk,1=continuation disk";
        else if(!xx_rt_wcscmp(r->name,L"head_sector"))s=L"1024-byte physical sector index";
        break;
    case 0x607a0014U:
        if(!xx_rt_wcscmp(r->name,L"start_sector"))s=L"Inclusive1024-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"end_sector"))s=L"Inclusive1024-byte sector number";
        break;
    case 0x607a0016U:
        if(!xx_rt_wcscmp(r->name,L"minute_bcd"))s=L"Packed BCD minute";
        else if(!xx_rt_wcscmp(r->name,L"second_bcd"))s=L"Packed BCD second";
        else if(!xx_rt_wcscmp(r->name,L"frame_bcd"))s=L"Packed BCD frame,75frames/second";
        break;
    case 0x607a0018U:
        if(!xx_rt_wcscmp(r->name,L"edc"))s=L"Stored sector error-detection CRC";
        break;
    case 0x607a0019U:
        if(!xx_rt_wcscmp(r->name,L"type_and_flags"))s=L"Low6bits file type,bit6 protection,bit7 hidden";
        else if(!xx_rt_wcscmp(r->name,L"sectors_used"))s=L"512-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"first_track_and_side"))s=L"Bit7 selects side1; remaining bits are cylinder";
        else if(!xx_rt_wcscmp(r->name,L"first_sector"))s=L"Sector IDs1..10";
        else if(!xx_rt_wcscmp(r->name,L"allocation_bitmap"))s=L"LSB-first bits map data sectors beginning at side0 track4";
        break;
    case 0x607a001aU:
        if(!xx_rt_wcscmp(r->name,L"next_sector"))s=L"Both bytes zero terminate the chain";
        break;
    case 0x607a001bU:
        if(!xx_rt_wcscmp(r->name,L"previous_block"))s=L"512-byte logical block number; zero terminates";
        else if(!xx_rt_wcscmp(r->name,L"next_block"))s=L"512-byte logical block number; zero terminates";
        break;
    case 0x607a001cU:
        if(!xx_rt_wcscmp(r->name,L"modification_packed"))s=L"Packed ProDOS date/time; GS/OS extension";
        else if(!xx_rt_wcscmp(r->name,L"creation_packed"))s=L"Packed date/time words, not Unix seconds";
        else if(!xx_rt_wcscmp(r->name,L"bitmap_block"))s=L"512-byte logical block number";
        break;
    case 0x607a001dU:
        if(!xx_rt_wcscmp(r->name,L"creation_packed"))s=L"Packed ProDOS date/time words";
        else if(!xx_rt_wcscmp(r->name,L"parent_block"))s=L"512-byte logical block number";
        else if(!xx_rt_wcscmp(r->name,L"parent_entry_number"))s=L"One-based directory slot index";
        break;
    case 0x607a001eU:
        if(!xx_rt_wcscmp(r->name,L"key_block"))s=L"512-byte logical block number";
        else if(!xx_rt_wcscmp(r->name,L"creation_packed"))s=L"Packed ProDOS date/time words";
        else if(!xx_rt_wcscmp(r->name,L"version_and_case"))s=L"Version/minimum-version bytes or lowercase flag union";
        else if(!xx_rt_wcscmp(r->name,L"modification_packed"))s=L"Packed ProDOS date/time words";
        else if(!xx_rt_wcscmp(r->name,L"header_block"))s=L"512-byte logical directory header block";
        break;
    case 0x607a001fU:
        if(!xx_rt_wcscmp(r->name,L"key_block"))s=L"512-byte logical block number";
        break;
    case 0x607a0020U:
        if(!xx_rt_wcscmp(r->name,L"block_number_low_bytes"))s=L"Low bytes of 256 block numbers; high bytes are a separate plane";
        break;
    case 0x607a0021U:
        if(!xx_rt_wcscmp(r->name,L"block_number_high_bytes"))s=L"High bytes of 256 block numbers; low bytes are a separate plane";
        break;
    case 0x607a0022U:
        if(!xx_rt_wcscmp(r->name,L"directory_end_block"))s=L"Exclusive 512-byte logical block number";
        else if(!xx_rt_wcscmp(r->name,L"last_access_time"))s=L"UCSD Pascal access-time word";
        else if(!xx_rt_wcscmp(r->name,L"last_set_date"))s=L"Packed month/day/year date";
        break;
    case 0x607a0023U:
        if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"512-byte logical block number";
        else if(!xx_rt_wcscmp(r->name,L"end_block"))s=L"Exclusive 512-byte logical block number";
        else if(!xx_rt_wcscmp(r->name,L"modification_date"))s=L"Packed month/day/year date";
        break;
    case 0x607a0024U:
        if(!xx_rt_wcscmp(r->name,L"allocation_direction"))s=L"Signed track allocation direction";
        break;
    case 0x607a0025U:
        if(!xx_rt_wcscmp(r->name,L"free_sector_bits"))s=L"Track free-sector bitmap in DOS on-disk bit order";
        break;
    case 0x607a0027U:
        if(!xx_rt_wcscmp(r->name,L"ts_list_track"))s=L"0 deleted/unused; FF deleted in DOS3.3";
        else if(!xx_rt_wcscmp(r->name,L"high_bit_name"))s=L"Apple DOS characters with bit7 set";
        break;
    case 0x607a002aU:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"bitmap_start_sector"))s=L"512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"allocation_search_pointer"))s=L"Allocation-block index";
        else if(!xx_rt_wcscmp(r->name,L"allocation_start_sector"))s=L"512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"backup_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"volume_cache_or_embedded_signature"))s=L"Classic drVCSize cache-size word; HFS+ wrapper uses drEmbedSigWord";
        else if(!xx_rt_wcscmp(r->name,L"bitmap_cache_or_embedded_start"))s=L"Classic drVBMCSize cache-size word; HFS+ wrapper uses embedded allocation-block start";
        else if(!xx_rt_wcscmp(r->name,L"control_cache_or_embedded_count"))s=L"Classic drCtlCSize cache-size word; HFS+ wrapper uses embedded allocation-block count";
        else if(!xx_rt_wcscmp(r->name,L"extents_file_initial_extents"))s=L"Three (start allocation block,count) pairs";
        else if(!xx_rt_wcscmp(r->name,L"catalog_file_initial_extents"))s=L"Three (start allocation block,count) pairs";
        break;
    case 0x607a002bU:
        if(!xx_rt_wcscmp(r->name,L"forward_link"))s=L"B-tree node number";
        else if(!xx_rt_wcscmp(r->name,L"backward_link"))s=L"B-tree node number";
        break;
    case 0x607a002dU:
        if(!xx_rt_wcscmp(r->name,L"record_offset"))s=L"Byte offset from B-tree node start; stored in reverse order at node end";
        break;
    case 0x607a0031U:
        if(!xx_rt_wcscmp(r->name,L"child_node"))s=L"B-tree node number";
        break;
    case 0x607a0032U:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"backup_time"))s=L"Seconds since1904-01-01";
        break;
    case 0x607a0033U:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"backup_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"data_initial_extents"))s=L"Three allocation block/count pairs";
        else if(!xx_rt_wcscmp(r->name,L"resource_initial_extents"))s=L"Three allocation block/count pairs";
        break;
    case 0x607a0035U:
        if(!xx_rt_wcscmp(r->name,L"status"))s=L"32 identifies the CP/M3 volume label";
        else if(!xx_rt_wcscmp(r->name,L"password_and_reserved"))s=L"Native reader excludes password-enabled variants";
        else if(!xx_rt_wcscmp(r->name,L"creation_days"))s=L"Days since1978-01-01, not a Unix timestamp";
        else if(!xx_rt_wcscmp(r->name,L"modification_days"))s=L"Days since1978-01-01";
        break;
    case 0x607a0036U:
        if(!xx_rt_wcscmp(r->name,L"status"))s=L"33 identifies the timestamp directory entry";
        break;
    case 0x607a0037U:
        if(!xx_rt_wcscmp(r->name,L"first_stamp_days"))s=L"Creation/access day count selected by volume flags";
        else if(!xx_rt_wcscmp(r->name,L"password_mode"))s=L"Native requires zero for active entries";
        break;
    case 0x607a0039U:
        if(!xx_rt_wcscmp(r->name,L"status"))s=L"229 marks an erased slot";
        else if(!xx_rt_wcscmp(r->name,L"erased_contents"))s=L"No live filename/allocation semantics are inferred";
        break;
    case 0x607a003aU:
        if(!xx_rt_wcscmp(r->name,L"legacy_header"))s=L"Legacy +D/DISCiPLE information; variant-specific stored bytes";
        break;
    case 0x607a003bU:
        if(!xx_rt_wcscmp(r->name,L"disk_label"))s=L"First directory entry only; bit7 of first byte may be ignored";
        break;
    case 0x607a003cU:
        if(!xx_rt_wcscmp(r->name,L"file_type_information"))s=L"Interpretation depends on the SAM file type; primary SAM manual assigns bytes221..231";
        else if(!xx_rt_wcscmp(r->name,L"start_page"))s=L"Low5bits select the16KiB page";
        else if(!xx_rt_wcscmp(r->name,L"start_offset"))s=L"Offset within paged address window, not a source offset";
        else if(!xx_rt_wcscmp(r->name,L"length_pages"))s=L"16KiB units";
        else if(!xx_rt_wcscmp(r->name,L"length_remainder"))s=L"Low14bits are remaining bytes";
        else if(!xx_rt_wcscmp(r->name,L"execution_page"))s=L"255 means no execution entry";
        else if(!xx_rt_wcscmp(r->name,L"execution_offset_or_line"))s=L"CODE window offset or BASIC auto-run line";
        else if(!xx_rt_wcscmp(r->name,L"save_day"))s=L"255 means unstamped";
        else if(!xx_rt_wcscmp(r->name,L"save_year"))s=L"Stored calendar year byte; epoch remains producer-defined";
        else if(!xx_rt_wcscmp(r->name,L"disk_identifier"))s=L"Disk identifier in the first directory entry";
        else if(!xx_rt_wcscmp(r->name,L"extra_directory_tracks"))s=L"First directory entry; added to the initial4 tracks";
        break;
    case 0x607a003dU:
        if(!xx_rt_wcscmp(r->name,L"length_remainder"))s=L"SAM length modulo16KiB; legacy variants use full16-bit length";
        else if(!xx_rt_wcscmp(r->name,L"start_offset"))s=L"Stored paged-window address or type-specific parameter";
        else if(!xx_rt_wcscmp(r->name,L"parameter"))s=L"Execution/autostart parameter depends on file type";
        else if(!xx_rt_wcscmp(r->name,L"length_pages"))s=L"SAM only:16KiB units";
        else if(!xx_rt_wcscmp(r->name,L"start_page"))s=L"SAM only:encoded starting page";
        break;
    case 0x607a0040U:
        if(!xx_rt_wcscmp(r->name,L"sha1"))s=L"Hexadecimal SHA1 digest of stored chunk bytes, not format magic";
        break;
    case 0x607a0041U:
        if(!xx_rt_wcscmp(r->name,L"xxh64"))s=L"Hexadecimal seed-zero XXH64 digest of stored chunk bytes";
        break;
    case 0x607a0042U:
        if(!xx_rt_wcscmp(r->name,L"keyword"))s=L"Partition record introducer";
        break;
    case 0x607a0043U:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Physical partition label";
        break;
    case 0x607a0044U:
        if(!xx_rt_wcscmp(r->name,L"first_sector"))s=L"512-byte sector number";
        break;
    case 0x607a0045U:
        if(!xx_rt_wcscmp(r->name,L"exclusive_end_sector"))s=L"Exclusive512-byte sector boundary";
        break;
    case 0x607a0046U:
        if(!xx_rt_wcscmp(r->name,L"tag"))s=L"Physical XML tag spelling";
        break;
    case 0x607a0047U:
        if(!xx_rt_wcscmp(r->name,L"member_name"))s=L"XML-RPC member name; entities preserved";
        break;
    case 0x607a0048U:
        if(!xx_rt_wcscmp(r->name,L"value"))s=L"XML-RPC value; physical bytes preserved";
        break;
    case 0x607a0049U:
        if(!xx_rt_wcscmp(r->name,L"tag"))s=L"Physical HxC descriptor tag spelling";
        break;
    case 0x607a004aU:
        if(!xx_rt_wcscmp(r->name,L"attribute"))s=L"Physical attribute name";
        break;
    case 0x607a004bU:
        if(!xx_rt_wcscmp(r->name,L"disk_layout_name"))s=L"Physical label, entities preserved";
        break;
    case 0x607a004cU:
        if(!xx_rt_wcscmp(r->name,L"sector_data"))s=L"Physical hexadecimal text, not decoded bytes";
        break;
    case 0x607a004dU:
        if(!xx_rt_wcscmp(r->name,L"file_size"))s=L"Stored HxC numeric value";
        break;
    case 0x607a004eU:
        if(!xx_rt_wcscmp(r->name,L"file_size"))s=L"Stored HxC numeric value; hexadecimal digits after0x prefix";
        break;
    case 0x607a004fU:
        if(!xx_rt_wcscmp(r->name,L"number_of_track"))s=L"Stored HxC numeric value";
        break;
    case 0x607a0050U:
        if(!xx_rt_wcscmp(r->name,L"number_of_track"))s=L"Stored HxC numeric value; hexadecimal digits after0x prefix";
        break;
    case 0x607a0051U:
        if(!xx_rt_wcscmp(r->name,L"number_of_side"))s=L"Stored HxC numeric value";
        break;
    case 0x607a0052U:
        if(!xx_rt_wcscmp(r->name,L"number_of_side"))s=L"Stored HxC numeric value; hexadecimal digits after0x prefix";
        break;
    case 0x607a0053U:
        if(!xx_rt_wcscmp(r->name,L"sector_per_track"))s=L"Stored HxC numeric value";
        break;
    case 0x607a0054U:
        if(!xx_rt_wcscmp(r->name,L"sector_per_track"))s=L"Stored HxC numeric value; hexadecimal digits after0x prefix";
        break;
    case 0x607a0055U:
        if(!xx_rt_wcscmp(r->name,L"sector_size"))s=L"Stored HxC numeric value";
        break;
    case 0x607a0056U:
        if(!xx_rt_wcscmp(r->name,L"sector_size"))s=L"Stored HxC numeric value; hexadecimal digits after0x prefix";
        break;
    case 0x607a0057U:
        if(!xx_rt_wcscmp(r->name,L"start_sector_id"))s=L"Stored HxC numeric value";
        break;
    case 0x607a0058U:
        if(!xx_rt_wcscmp(r->name,L"start_sector_id"))s=L"Stored HxC numeric value; hexadecimal digits after0x prefix";
        break;
    case 0x607a0059U:
        if(!xx_rt_wcscmp(r->name,L"formatvalue"))s=L"Stored HxC numeric value";
        break;
    case 0x607a005aU:
        if(!xx_rt_wcscmp(r->name,L"formatvalue"))s=L"Stored HxC numeric value; hexadecimal digits after0x prefix";
        break;
    case 0x607a005bU:
        if(!xx_rt_wcscmp(r->name,L"data_fill"))s=L"Stored HxC numeric value";
        break;
    case 0x607a005cU:
        if(!xx_rt_wcscmp(r->name,L"data_fill"))s=L"Stored HxC numeric value; hexadecimal digits after0x prefix";
        break;
    case 0x607a005dU:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Stored HxC numeric value; byte position in external raw image";
        break;
    case 0x607a005eU:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Stored HxC numeric value; byte position in external raw image; hexadecimal digits after0x prefix";
        break;
    case 0x607a005fU:
        if(!xx_rt_wcscmp(r->name,L"sector_id"))s=L"Stored HxC numeric value";
        break;
    case 0x607a0060U:
        if(!xx_rt_wcscmp(r->name,L"sector_id"))s=L"Stored HxC numeric value; hexadecimal digits after0x prefix";
        break;
    case 0x607a0061U:
        if(!xx_rt_wcscmp(r->name,L"track_number"))s=L"Stored HxC numeric value";
        break;
    case 0x607a0062U:
        if(!xx_rt_wcscmp(r->name,L"track_number"))s=L"Stored HxC numeric value; hexadecimal digits after0x prefix";
        break;
    case 0x607a0063U:
        if(!xx_rt_wcscmp(r->name,L"side_number"))s=L"Stored HxC numeric value";
        break;
    case 0x607a0064U:
        if(!xx_rt_wcscmp(r->name,L"side_number"))s=L"Stored HxC numeric value; hexadecimal digits after0x prefix";
        break;
    case 0x607a0065U:
        if(!xx_rt_wcscmp(r->name,L"type_specific_storage"))s=L"Snapshot registers or DOS-specific data; SAM tail semantics are not imposed on legacy types";
        break;
    case 0x607a0068U:
        if(!xx_rt_wcscmp(r->name,L"entry_offset"))s=L"Relative to loaded loader code; not an offset in this image";
        else if(!xx_rt_wcscmp(r->name,L"mddf_block"))s=L"Absolute512-byte data block number";
        break;
    case 0x607a0069U:
        if(!xx_rt_wcscmp(r->name,L"file_id"))s=L"Negative ID identifies a file hint/map page";
        else if(!xx_rt_wcscmp(r->name,L"relative_page"))s=L"Page index within the logical file";
        else if(!xx_rt_wcscmp(r->name,L"forward_link_and_used_high"))s=L"Low11bits MDDF-relative next page (2047 terminates); high5bits upper used-byte count";
        else if(!xx_rt_wcscmp(r->name,L"backward_link_and_used_low"))s=L"Low11bits previous page; high5bits lower used-byte count";
        break;
    case 0x607a006aU:
        if(!xx_rt_wcscmp(r->name,L"volume_id"))s=L"Two stored32-bit identifier words";
        else if(!xx_rt_wcscmp(r->name,L"volume_name_pascal"))s=L"Length-prefixed Pascal string retained with its length byte";
        else if(!xx_rt_wcscmp(r->name,L"padc1"))s=L"Stored padding or unused word; not required to be zero";
        else if(!xx_rt_wcscmp(r->name,L"password"))s=L"Length-prefixed Pascal string retained with its length byte";
        else if(!xx_rt_wcscmp(r->name,L"padc2"))s=L"Stored padding or unused word; not required to be zero";
        else if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since1901-01-01";
        else if(!xx_rt_wcscmp(r->name,L"copy_creation_time"))s=L"Seconds since1901-01-01";
        else if(!xx_rt_wcscmp(r->name,L"copy_time"))s=L"Seconds since1901-01-01";
        else if(!xx_rt_wcscmp(r->name,L"scavenge_time"))s=L"Seconds since1901-01-01";
        else if(!xx_rt_wcscmp(r->name,L"copy_thread"))s=L"Copy-chain identifier; not a physical source offset";
        else if(!xx_rt_wcscmp(r->name,L"firstblock"))s=L"Absolute512-byte block number, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"lastblock"))s=L"Absolute512-byte block number, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"lastfspage"))s=L"512-byte page number relative to the MDDF, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"mddf_page"))s=L"512-byte page number relative to the MDDF, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"bitmap_addr"))s=L"512-byte page number relative to the MDDF, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"bitmap_size"))s=L"Stored metadata size parameter; its unit is not established by the retained reader source";
        else if(!xx_rt_wcscmp(r->name,L"slist_addr"))s=L"512-byte page number relative to the MDDF, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"leader_offset"))s=L"Byte displacement in the referenced logical metadata structure";
        else if(!xx_rt_wcscmp(r->name,L"flabel_offset"))s=L"Byte displacement in the referenced logical metadata structure";
        else if(!xx_rt_wcscmp(r->name,L"unusedi1"))s=L"Stored padding or unused word; not required to be zero";
        else if(!xx_rt_wcscmp(r->name,L"map_offset"))s=L"Byte displacement in the referenced logical metadata structure";
        else if(!xx_rt_wcscmp(r->name,L"map_size"))s=L"Stored metadata size parameter; its unit is not established by the retained reader source";
        else if(!xx_rt_wcscmp(r->name,L"unusedl1"))s=L"Stored padding or unused word; not required to be zero";
        else if(!xx_rt_wcscmp(r->name,L"mountinfo_pad"))s=L"Stored padding or unused word; not required to be zero";
        else if(!xx_rt_wcscmp(r->name,L"overmount_stamp"))s=L"Two stored32-bit identifier words";
        else if(!xx_rt_wcscmp(r->name,L"smallmap_offset"))s=L"Byte displacement in the referenced logical metadata structure";
        else if(!xx_rt_wcscmp(r->name,L"hentry_offset"))s=L"Byte displacement in the referenced logical metadata structure";
        else if(!xx_rt_wcscmp(r->name,L"backup_volid"))s=L"Two stored32-bit identifier words";
        else if(!xx_rt_wcscmp(r->name,L"root_page"))s=L"512-byte page number relative to the MDDF, not a byte offset";
        break;
    case 0x607a006bU:
        if(!xx_rt_wcscmp(r->name,L"hintaddr"))s=L"512-byte page number relative to the MDDF, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"fileaddr"))s=L"512-byte page number relative to the MDDF, not a byte offset";
        break;
    case 0x607a006cU:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Length-prefixed Pascal string retained with its length byte";
        else if(!xx_rt_wcscmp(r->name,L"name_pad"))s=L"Stored padding or unused word; not required to be zero";
        else if(!xx_rt_wcscmp(r->name,L"UID"))s=L"Two stored32-bit identifier words";
        else if(!xx_rt_wcscmp(r->name,L"ftype_pad"))s=L"Stored padding or unused word; not required to be zero";
        else if(!xx_rt_wcscmp(r->name,L"date_created"))s=L"Seconds since1901-01-01";
        else if(!xx_rt_wcscmp(r->name,L"date_accessed"))s=L"Seconds since1901-01-01";
        else if(!xx_rt_wcscmp(r->name,L"date_modified"))s=L"Seconds since1901-01-01";
        else if(!xx_rt_wcscmp(r->name,L"date_backup"))s=L"Seconds since1901-01-01";
        else if(!xx_rt_wcscmp(r->name,L"date_scavenged"))s=L"Seconds since1901-01-01";
        else if(!xx_rt_wcscmp(r->name,L"unusedi1"))s=L"Stored padding or unused word; not required to be zero";
        else if(!xx_rt_wcscmp(r->name,L"password"))s=L"Length-prefixed Pascal string retained with its length byte";
        else if(!xx_rt_wcscmp(r->name,L"password_pad"))s=L"Stored padding or unused word; not required to be zero";
        break;
    case 0x607a006eU:
        if(!xx_rt_wcscmp(r->name,L"first_page"))s=L"MDDF-relative512-byte page number in the native microfloppy variant";
        break;
    case 0x607a006fU:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Length-prefixed Pascal string retained with its length byte";
        else if(!xx_rt_wcscmp(r->name,L"name_pad"))s=L"Stored padding or unused word; not required to be zero";
        else if(!xx_rt_wcscmp(r->name,L"cetype_pad"))s=L"Stored padding or unused word; not required to be zero";
        else if(!xx_rt_wcscmp(r->name,L"readpage"))s=L"512-byte page number relative to the MDDF, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"readoffset"))s=L"Byte displacement in the referenced logical metadata structure";
        else if(!xx_rt_wcscmp(r->name,L"writepage"))s=L"512-byte page number relative to the MDDF, not a byte offset";
        else if(!xx_rt_wcscmp(r->name,L"writeoffset"))s=L"Byte displacement in the referenced logical metadata structure";
        break;
    case 0x607a0071U:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since1901-01-01";
        break;
    case 0x607a0072U:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since1901-01-01";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since1901-01-01";
        else if(!xx_rt_wcscmp(r->name,L"filesystem_overhead"))s=L"512-byte pages";
        break;
    case 0x607a0074U:
        if(!xx_rt_wcscmp(r->name,L"previous_node"))s=L"MDDF-relative page number";
        else if(!xx_rt_wcscmp(r->name,L"next_node"))s=L"MDDF-relative page number";
        else if(!xx_rt_wcscmp(r->name,L"kind"))s=L"0=leaf,1=index";
        else if(!xx_rt_wcscmp(r->name,L"checksum"))s=L"Stored Lisa node checksum byte; the retained reader does not document its algorithm";
        break;
    case 0x607a0075U:
        if(!xx_rt_wcscmp(r->name,L"record_offset"))s=L"Byte displacement within the2048-byte logical catalog node";
        break;
    case 0x607a0076U:
        if(!xx_rt_wcscmp(r->name,L"child_page"))s=L"MDDF-relative page number";
        break;
    case 0x607a0077U:
        if(!xx_rt_wcscmp(r->name,L"text"))s=L"Physical XML text, including entity spelling; no decoded numeric value is invented";
        break;
    case 0x607a0078U:
        if(!xx_rt_wcscmp(r->name,L"packed_cluster_links"))s=L"Two little-endian12-bit FAT cluster successors; not byte offsets";
        break;
    case 0x607a0079U:
        if(!xx_rt_wcscmp(r->name,L"reserved_legacy"))s=L"Original DOS2 reserved bytes; later VFAT/NT extensions are not inferred";
        else if(!xx_rt_wcscmp(r->name,L"modification_time_packed"))s=L"DOS packed time:hour5/minute6/two-second5";
        else if(!xx_rt_wcscmp(r->name,L"modification_date_packed"))s=L"DOS packed date:year since1980/month/day";
        else if(!xx_rt_wcscmp(r->name,L"first_cluster"))s=L"FAT12 allocation cluster number";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Every coordinate is relative to the borrowed image base.  No native
 * subclass state, host mounts, or journal replay is required.  Display caps
 * retain validated earlier records; undecoded metadata and payload stay raw. */
#define SXDT_LIMIT 24000U
static bool sxdt_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxdt_read(sx_context*c,uint64_t p,void*b,size_t n){return !xx_pd_is_stopped(c->pd)&&sxdt_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint16_t sxdt16(const uint8_t*b,unsigned o){return o==1?(uint16_t)((uint16_t)b[0]<<8|b[1]):(uint16_t)((uint16_t)b[1]<<8|b[0]);}
static uint32_t sxdt32(const uint8_t*b,unsigned o){if(o==2)return (uint32_t)sxdt16(b,0)<<16|sxdt16(b+2,0);return o==1?(uint32_t)sxdt16(b,1)<<16|sxdt16(b+2,1):(uint32_t)sxdt16(b+2,0)<<16|sxdt16(b,0);}
static bool sxdt_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 if(!n)return true;const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(!z||n>1048576U||n>UINT64_MAX/z||!sxdt_span(c,p,n*z)||xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXDT_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&(uint64_t)(c->items[lo-1].offset-c->f->base_address)+(uint64_t)c->items[lo-1].total_size>p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}return true;
}
#define SXDT_ADD(c,l,p) sxdt_put(c,&sxdt_##l,p,1)
#define SXDT_TABLE(c,l,p,n) sxdt_put(c,&sxdt_##l,p,n)

static bool sxdt_value(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){if(!n)return true;if(!sxdt_span(c,p,n)||xx_pd_is_stopped(c->pd))return false;const xx_data_struct_field_desc*last=l->fields+l->field_count-1;uint64_t limit=sx_variable_field_limit(last->type);if(n<=(uint64_t)last->rel_offset||n-(uint64_t)last->rel_offset>limit||n>16384||c->count>=SXDT_LIMIT)return true;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<c->f->base_address+(int64_t)p)lo=m+1;else hi=m;}if(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>c->f->base_address+(int64_t)p)return true;if(lo<c->count&&c->items[lo].offset<c->f->base_address+(int64_t)(p+n))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}

static bool sxdt_rdos(sx_context*c){uint64_t sectors=c->size==116480?13:16;if(c->size!=116480&&c->size!=143360)return false;/* All supported native profiles share these88 physical slots. Explicit profiles may override a canonical label, so the RDOS33-only final40 slots remain raw. */return SXDT_TABLE(c,rdos_catalog_entry,sectors*256,88);}
static bool sxdt_atom(sx_context*c){uint8_t h[8];if(c->size!=102400||!sxdt_read(c,256,h,8)||h[5]%8||h[5]>248)return false;return SXDT_ADD(c,atom_catalog_name_header,0)&&SXDT_ADD(c,atom_catalog_info_header,256)&&SXDT_TABLE(c,atom_catalog_name,8,h[5]/8)&&SXDT_TABLE(c,atom_catalog_info,264,h[5]/8);}
static bool sxdt_apricot(sx_context*c){uint8_t b[13];if(!sxdt_read(c,80,b,13)||sxdt16(b,0)!=512||!SXDT_ADD(c,apricot_label_prefix,0)||!SXDT_ADD(c,apricot_bpb,80))return false;unsigned reserved=sxdt16(b+3,0),fats=b[5],fatsectors=sxdt16(b+11,0),entries=sxdt16(b+6,0);if(!reserved||!fats||fats>2||!fatsectors||fatsectors>16||entries>1024)return true;for(unsigned i=0;i<fats;i++){uint64_t p=(uint64_t)(reserved+i*fatsectors)*512;if(sxdt_span(c,p,(uint64_t)fatsectors*512)&&!SXDT_TABLE(c,apricot_fat12_pair,p,fatsectors*512/3))return false;}uint64_t root=(uint64_t)(reserved+fats*fatsectors)*512;for(unsigned i=0;i<entries;i++){uint8_t e[32];uint64_t p=root+i*32;if(!sxdt_read(c,p,e,32)||!e[0])break;if(e[0]!=229&&(e[11]&63)!=15&&!SXDT_ADD(c,apricot_directory_entry,p))return false;}/* Native archive header extents authenticate subdirectory entries as well. */if(c->f->create_archive_records_reading&&c->f->get_current_archive_record&&c->f->archive_record_move_to_next&&c->f->free_archive_records_reading){xx_archive_record_state*state=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(state){bool ok=true;for(unsigned i=0;i<24000&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(c->f->get_current_archive_record)(c->f,state);if(!r)break;if(r->header_offset>=c->f->base_address&&r->header_size==32){uint64_t p=(uint64_t)(r->header_offset-c->f->base_address);if(sxdt_span(c,p,32)&&!SXDT_ADD(c,apricot_directory_entry,p)){ok=false;break;}}if(!(c->f->archive_record_move_to_next)(c->f,state,c->pd))break;}(c->f->free_archive_records_reading)(c->f,state);if(!ok)return false;}}return true;}
static bool sxdt_casio(sx_context*c){uint8_t d[1024],h[1024];if(c->size!=1310720||!sxdt_read(c,1024,d,1024)||!SXDT_ADD(c,casio_disk_header,0)||!SXDT_TABLE(c,casio_allocation_byte,128,768)||!SXDT_TABLE(c,casio_directory_entry,1024,64))return false;for(unsigned i=0;i<64;i++){const uint8_t*e=d+i*16;unsigned sector=sxdt16(e+14,0);if(!e[0]||e[12]>5||e[13]>1||sector<2||sector>=1280)continue;bool valid=true;for(unsigned j=0;j<12&&e[j];j++)if(e[j]<32||e[j]==127)valid=false;uint64_t p=(uint64_t)sector*1024;if(!valid||!sxdt_read(c,p,h,sizeof(h)))continue;if(e[12]!=4&&(sxdt16(h+1018,0)>8||sxdt16(h+1020,0)>64))continue;uint8_t seen[160]={0};unsigned n=0;bool any=false;for(;n<64;n++){unsigned a=sxdt16(h+n*4,0),b=sxdt16(h+n*4+2,0);if(!a&&!b){n++;break;}if(a<2||a>b||b>=1280){valid=false;break;}any=true;for(unsigned k=a;k<=b;k++){if(seen[k/8]&(1U<<(k%8)))valid=false;seen[k/8]|=(uint8_t)(1U<<(k%8));}}if(!valid||!any||(sxdt16(h,0)!=sector&&(seen[sector/8]&(1U<<(sector%8)))))continue;if(!SXDT_TABLE(c,casio_file_extent,p,n)||!SXDT_ADD(c,casio_file_counts,p+1018))return false;}return true;}
static bool sxdt_ts(sx_context*c){uint8_t h[26];if(!sxdt_read(c,0,h,26)||sxdt16(h,1)!=0x4552||sxdt16(h+2,1)!=512||!SXDT_ADD(c,mac_ts_driver_descriptor,0)||!sxdt_read(c,512,h,2)||sxdt16(h,1)!=0x5453||!SXDT_ADD(c,mac_ts_map_header,512))return false;for(unsigned i=0;i<42;i++){uint64_t p=514+i*12;if(!sxdt_read(c,p,h,12)||!SXDT_ADD(c,mac_ts_partition,p))return false;if(!sxdt32(h,1))break;}return true;}
static int sxdt_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxdt_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+z>end)end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxdt_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
static bool sxdt_cpm(sx_context*c){
 if(c->f->create_archive_records_reading!=xx_cpm_create_archive_records_reading||c->f->free_archive_records_reading!=xx_cpm_free_archive_records_reading)return false;
 xx_archive_record_state*s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return false;
 xx_cpm_directory_slot slot;bool ok=xx_cpm_get_directory_slot(c->f,s,0,&slot);uint32_t count=ok?slot.entry_count:0;
 for(uint32_t i=0;ok&&i<count&&c->count<SXDT_LIMIT;i++){
  if(xx_pd_is_stopped(c->pd)||!xx_cpm_get_directory_slot(c->f,s,i,&slot)||slot.offset<c->f->base_address){ok=false;break;}
  uint64_t p=(uint64_t)(slot.offset-c->f->base_address);uint8_t b[32];if(!sxdt_read(c,p,b,32)){ok=false;break;}
  if(b[0]==229)ok=SXDT_ADD(c,cpm_deleted_entry,p);
  else if(slot.version==XX_CPM_VERSION_3&&b[0]==32)ok=SXDT_ADD(c,cpm3_volume_label,p);
  else if(slot.version==XX_CPM_VERSION_3&&b[0]==33)ok=SXDT_ADD(c,cpm3_timestamp_status,p)&&SXDT_TABLE(c,cpm3_timestamp_record,p+1,3)&&SXDT_ADD(c,cpm3_timestamp_tail,p+31);
  else ok=sxdt_put(c,slot.allocation_pointer_size==1?&sxdt_cpm_extent8:&sxdt_cpm_extent16,p,1);
 }
 (c->f->free_archive_records_reading)(c->f,s);return ok&&c->count!=0;
}
#endif
static int sxdt_cd_frames(const uint8_t*b){static const uint8_t sync[]={0,255,255,255,255,255,255,255,255,255,255,0};if(xx_rt_memcmp(b,sync,12))return -1;unsigned n[3];for(unsigned i=0;i<3;i++){unsigned v=b[12+i];if((v&15)>9||(v>>4)>9)return -1;n[i]=(v>>4)*10+(v&15);}if(n[1]>=60||n[2]>=75)return -1;return(int)(n[0]*4500+n[1]*75+n[2]);}
static bool sxdt_cd_descriptor(sx_context*c,uint64_t p){uint8_t b[7];return sxdt_read(c,p,b,7)&&(b[0]<=3||b[0]==255)&&b[6]==1&&(!xx_rt_memcmp(b+1,"CD001",5)||!xx_rt_memcmp(b+1,"CD-I ",5));}
static bool sxdt_rawcd(sx_context*c){
 uint8_t first[24],b[24];unsigned stride=0,data=0;bool synced=false;static const unsigned sizes[]={2352,2448,2368};
 if(!sxdt_read(c,0,first,24))return false;int frames=sxdt_cd_frames(first);
 if(frames>=0&&(first[15]==1||first[15]==2))for(unsigned i=0;i<SX_COUNT(sizes);i++)if(sxdt_read(c,sizes[i],b,24)&&sxdt_cd_frames(b)==frames+1&&b[15]<=2){stride=sizes[i];data=first[15]==1?16:24;synced=true;break;}
 if(!stride){static const unsigned z[]={2336,2352,2352,2448,2448},d[]={8,16,24,16,24};for(unsigned i=0;i<SX_COUNT(z);i++){if((uint64_t)c->size%z[i]||!sxdt_cd_descriptor(c,(uint64_t)z[i]*16+d[i])||!sxdt_cd_descriptor(c,(uint64_t)z[i]*17+d[i]))continue;if(i){if(!sxdt_read(c,(uint64_t)z[i]*16,b,24)||sxdt_cd_frames(b)<0||b[15]!=(d[i]==16?1:2))continue;}stride=z[i];data=d[i];synced=i!=0;break;}}
 if(!stride)return false;uint64_t sectors=(uint64_t)c->size/stride;if(sectors>1000000)sectors=1000000;
 for(uint64_t i=0;i<sectors&&c->count<SXDT_LIMIT;i++){
  uint64_t p=i*stride;if(!sxdt_read(c,p,b,24))break;unsigned mode=2,xa=0;
  if(synced){if(sxdt_cd_frames(b)<0)continue;mode=b[15]&3;if(mode>2)continue;if(!SXDT_ADD(c,rawcd_sector_header,p))return false;xa=16;}
  if(mode==1){if(!SXDT_ADD(c,rawcd_edc,p+2064))return false;}
  else if(mode==2){if(xx_rt_memcmp(b+xa,b+xa+4,4))continue;if(!SXDT_ADD(c,rawcd_xa_subheader,p+xa)||!SXDT_ADD(c,rawcd_edc,p+xa+8+((b[xa+2]&32)?2324:2048)))return false;}
 }
 (void)data;return c->count!=0;
}

/* A view maps logical child coordinates to the original physical device.
 * It never changes the borrowed format or record owner. OzDOS splits each
 * 512-byte physical sector into independent 256-byte logical sectors. */
typedef struct sxdt_view {sx_context*c;uint64_t base,size;unsigned split;} sxdt_view;
static uint64_t sxdt_avphysical(sxdt_view*v,uint64_t p){return v->base+(v->split?((p/256)*512+(v->split-1)*256+p%256):p);}
static bool sxdt_avspan(sxdt_view*v,uint64_t p,uint64_t n){return p<=v->size&&n<=v->size-p;}
static bool sxdt_avread(sxdt_view*v,uint64_t p,void*out,size_t n){uint8_t*b=out;if(!sxdt_avspan(v,p,n))return false;while(n){size_t z=256-p%256;if(z>n)z=n;if(!sxdt_read(v->c,sxdt_avphysical(v,p),b,z))return false;p+=z;b+=z;n-=z;}return true;}
static bool sxdt_avput(sxdt_view*v,const sx_layout*l,uint64_t p,uint64_t n){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||n>UINT64_MAX/z||!sxdt_avspan(v,p,z*n))return false;for(uint64_t i=0;i<n;i++){uint64_t a=p+i*z,physical=sxdt_avphysical(v,a);bool contiguous=true;for(uint64_t q=0;q<z;){if(sxdt_avphysical(v,a+q)!=physical+q){contiguous=false;break;}uint64_t take=256-(a+q)%256;if(take>z-q)take=z-q;q+=take;}if(contiguous&&!sxdt_put(v->c,l,physical,1))return false;}return true;}
#define SXDT_AV_ADD(c,l,p) sxdt_avput(c,&sxdt_mapped_##l,p,1)
#define SXDT_AV_TABLE(c,l,p,n) sxdt_avput(c,&sxdt_mapped_##l,p,n)
static uint64_t sxdt_av_apple_pos(uint64_t p,bool dos){static const uint8_t map[16]={0,14,13,12,11,10,9,8,7,6,5,4,3,2,1,15};return dos?(p/4096)*4096+(uint64_t)map[(p/256)%16]*256+p%256:p;}
static bool sxdt_av_apple_read(sxdt_view*c,uint64_t p,void*out,size_t n,bool dos){uint8_t*b=out;while(n){size_t z=256-p%256;if(z>n)z=n;if(!sxdt_avread(c,sxdt_av_apple_pos(p,dos),b,z))return false;p+=z;b+=z;n-=z;}return true;}
static bool sxdt_av_apple_put(sxdt_view*c,const sx_layout*l,uint64_t p,bool dos){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t n=f->rel_offset+f->size,at=sxdt_av_apple_pos(p,dos);for(uint64_t q=0;q<n;){uint64_t z=256-(p+q)%256;if(sxdt_av_apple_pos(p+q,dos)!=at+q)return true;q+=z;}return sxdt_avput(c,l,at,1);}
static bool sxdt_av_pascal(sxdt_view*c){uint8_t h[26];bool dos=false;if(!sxdt_avread(c,1024,h,26))return false;unsigned count=sxdt16(h+16,0),blocks=sxdt16(h+14,0);if(sxdt16(h+2,0)!=6||h[6]==0||h[6]>7||count>77||blocks<6||blocks>(uint64_t)c->size/512){dos=true;if(c->size<143360||!sxdt_av_apple_read(c,1024,h,26,true))return false;count=sxdt16(h+16,0);blocks=sxdt16(h+14,0);if(sxdt16(h+2,0)!=6||h[6]==0||h[6]>7||count>77||blocks!=280)return false;}
 if(!sxdt_av_apple_put(c,&sxdt_mapped_pascal_volume_header,1024,dos))return false;for(unsigned i=0;i<count;i++)if(!sxdt_av_apple_put(c,&sxdt_mapped_pascal_file_entry,1024+(uint64_t)(i+1)*26,dos))return false;return true;}
static bool sxdt_av_pd_header(const uint8_t*h){return !sxdt16(h,0)&&(h[4]>>4)==15&&(h[4]&15)&&h[35]==39&&h[36]==13&&sxdt16(h+41,0)>=5;}
static bool sxdt_av_prodos(sxdt_view*c){uint8_t h[512];bool dos=false;if(!sxdt_avread(c,1024,h,512))return false;if(!sxdt_av_pd_header(h)){dos=true;if(c->size<143360||!sxdt_av_apple_read(c,1024,h,512,true)||!sxdt_av_pd_header(h))return false;}
 uint32_t blocks=sxdt16(h+41,0);if(blocks>(uint64_t)c->size/512)return false;uint8_t*seen=xx_rt_calloc(blocks,1);uint16_t*queue=xx_rt_calloc(blocks,sizeof(*queue));if(!seen||!queue){xx_rt_free(seen);xx_rt_free(queue);return false;}size_t n=1,i=0;queue[0]=2;seen[2]=1;bool ok=true;
 while(i<n&&c->c->count<SXDT_LIMIT&&!xx_pd_is_stopped(c->c->pd)){uint32_t b=queue[i++];uint64_t p=(uint64_t)b*512;if(!sxdt_av_apple_read(c,p,h,512,dos))break;if(!sxdt_av_apple_put(c,&sxdt_mapped_prodos_directory_links,p,dos)){ok=false;break;}unsigned next=sxdt16(h+2,0);if(next>=3&&next<blocks&&!seen[next]){seen[next]=1;queue[n++]=(uint16_t)next;}
  for(unsigned j=0;j<13;j++){uint8_t*e=h+4+j*39;unsigned t=e[0]>>4;uint64_t at=p+4+j*39;const sx_layout*l=t==15?&sxdt_mapped_prodos_volume_header:t==14?&sxdt_mapped_prodos_subdirectory_header:t?&sxdt_mapped_prodos_file_entry:NULL;if(!l)continue;if(!sxdt_av_apple_put(c,l,at,dos)){ok=false;break;}unsigned key=sxdt16(e+17,0);if(t==13&&key>=3&&key<blocks&&!seen[key]){seen[key]=1;queue[n++]=(uint16_t)key;}if((t==2||t==3)&&key<blocks&&key>=3){if(!sxdt_av_apple_put(c,&sxdt_mapped_prodos_index_low,(uint64_t)key*512,dos)||!sxdt_av_apple_put(c,&sxdt_mapped_prodos_index_high,(uint64_t)key*512+256,dos)){ok=false;break;}}if(t==5&&key>=3&&key<blocks){if(!sxdt_av_apple_put(c,&sxdt_mapped_prodos_fork_descriptor,(uint64_t)key*512,dos)||!sxdt_av_apple_put(c,&sxdt_mapped_prodos_fork_descriptor,(uint64_t)key*512+256,dos)){ok=false;break;}}}
 }xx_rt_free(seen);xx_rt_free(queue);return ok;}

static bool sxdt_av_apple_dos(sxdt_view*c,unsigned spt){uint64_t vp=(uint64_t)17*spt*256;uint8_t v[256],b[256];bool remap=false;if(!sxdt_avread(c,vp,v,256))return false;
 if(v[53]!=spt||v[52]<18||v[52]>80||sxdt16(v+54,0)!=256||v[39]!=122){if(spt!=16||!sxdt_av_apple_read(c,vp,v,256,true)||v[53]!=16||v[52]<18||v[52]>80||sxdt16(v+54,0)!=256||v[39]!=122)return false;remap=true;}
 unsigned tracks=v[52];if((uint64_t)tracks*spt*256>(uint64_t)c->size||!sxdt_av_apple_put(c,&sxdt_mapped_apple_dos_vtoc,vp,remap))return false;for(unsigned j=0;j<tracks;j++)if(!sxdt_av_apple_put(c,&sxdt_mapped_apple_dos_bitmap,vp+56+j*4,remap))return false;
 uint8_t seen[2560]={0};unsigned t=v[1],s=v[2];for(unsigned walk=0;walk<2560&&t&&c->c->count<SXDT_LIMIT;walk++){if(t>=tracks||s>=spt)break;unsigned index=t*spt+s;if(seen[index])break;seen[index]=1;uint64_t p=(uint64_t)index*256;if(!sxdt_av_apple_read(c,p,b,256,remap))break;if(!sxdt_av_apple_put(c,&sxdt_mapped_apple_dos_catalog_header,p,remap))return false;unsigned nextt=b[1],nexts=b[2];
  for(unsigned j=0;j<7;j++){uint8_t*e=b+11+j*35;if(!e[0]||e[0]==255)continue;if(!sxdt_av_apple_put(c,&sxdt_mapped_apple_dos_file_entry,p+11+j*35,remap))return false;unsigned ft=e[0],fs=e[1];for(unsigned k=0;k<2560&&ft;k++){if(ft>=tracks||fs>=spt)break;unsigned ix=ft*spt+fs;if(seen[ix])break;seen[ix]=1;uint64_t at=(uint64_t)ix*256;uint8_t ts[12];if(!sxdt_av_apple_read(c,at,ts,12,remap))break;if(!sxdt_av_apple_put(c,&sxdt_mapped_apple_dos_ts_header,at,remap))return false;for(unsigned a=0;a<122;a++)if(!sxdt_av_apple_put(c,&sxdt_mapped_apple_dos_ts_pair,at+12+a*2,remap))return false;ft=ts[1];fs=ts[2];}}
  t=nextt;s=nexts;
 }return true;}

static bool sxdt_av_hfs_pos(const uint8_t*extent,uint64_t base,uint64_t bs,uint64_t logical,uint64_t n,uint64_t*out){for(unsigned i=0;i<3;i++){uint64_t first=sxdt16(extent+i*4,1),z=(uint64_t)sxdt16(extent+i*4+2,1)*bs;if(logical>=z){logical-=z;continue;}if(n>z-logical)return false;*out=base+first*bs+logical;return true;}return false;}
static bool sxdt_av_hfs_tree(sxdt_view*c,const uint8_t*extent,uint64_t base,uint64_t bs,uint64_t size,bool catalog){uint64_t p;uint8_t h[120];if(size<512||!sxdt_av_hfs_pos(extent,base,bs,0,120,&p)||!sxdt_avread(c,p,h,120)||h[8]!=1)return true;unsigned node=sxdt16(h+32,1);uint32_t total=sxdt32(h+36,1);if(node<512||node>32768||!(node&&(node&(node-1))==0)||!total||total>size/node)return true;uint8_t*b=xx_rt_malloc(node);if(!b)return false;bool ok=true;uint8_t bitmap[256];if(!sxdt_av_hfs_pos(extent,base,bs,248,256,&p)||!sxdt_avread(c,p,bitmap,256)){xx_rt_free(b);return true;}
 for(uint32_t i=0;i<total&&i<2048&&c->c->count<SXDT_LIMIT;i++){if(!(bitmap[i/8]&(0x80U>>(i%8))))continue;if(!sxdt_av_hfs_pos(extent,base,bs,(uint64_t)i*node,node,&p)||!sxdt_avread(c,p,b,node))continue;int kind=(int8_t)b[8];unsigned n=sxdt16(b+10,1);if(n>(node-14)/2-1||(kind!=-1&&kind!=0&&kind!=1&&kind!=2))continue;if(!SXDT_AV_ADD(c,hfs_btree_node,p)||!SXDT_AV_TABLE(c,hfs_node_record_offset,p+node-(n+1)*2,n+1)){ok=false;break;}
  for(unsigned j=0;j<n&&ok;j++){unsigned a=sxdt16(b+node-2*(j+1),1),z=sxdt16(b+node-2*(j+2),1);if(a<14||z<a||z>node-(n+1)*2)continue;if(kind==1){if(j==0&&z-a>=106&&!SXDT_AV_ADD(c,hfs_btree_header,p+a))ok=false;continue;}if(kind==2||z-a<2)continue;unsigned key=b[a];unsigned data=a+((key+2)&~1U);if(data>z)continue;if(catalog){if(key<6||b[a+6]>31||b[a+6]>key-6)continue;if(!SXDT_AV_ADD(c,hfs_catalog_key_prefix,p+a)){ok=false;break;}}else{if(key!=7||!SXDT_AV_ADD(c,hfs_extents_key,p+a)){ok=false;break;}}
   if(kind==0){if(z-data>=4&&!SXDT_AV_ADD(c,hfs_btree_child,p+data))ok=false;}else if(!catalog){if(z-data>=12&&!SXDT_AV_TABLE(c,hfs_extent,p+data,3))ok=false;}else if(z-data>=2){int type=(int16_t)sxdt16(b+data,1);const sx_layout*l=type==0x100?&sxdt_mapped_hfs_catalog_folder:type==0x200?&sxdt_mapped_hfs_catalog_file:(type==0x300||type==0x400)?&sxdt_mapped_hfs_catalog_thread:NULL;if(l){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;if((uint64_t)(f->rel_offset+f->size)<=z-data&&!sxdt_avput(c,l,p+data,1))ok=false;}}
  }
 }xx_rt_free(b);return ok;}
static bool sxdt_av_hfs(sxdt_view*c){uint8_t h[162];if(!sxdt_avread(c,1024,h,162)||sxdt16(h,1)!=0x4244||!SXDT_AV_ADD(c,hfs_master_directory,1024))return false;uint64_t bs=sxdt32(h+20,1),base=(uint64_t)sxdt16(h+28,1)*512;if(bs<512||bs>16777216||bs%512||!sxdt_avspan(c,base,(uint64_t)sxdt16(h+18,1)*bs))return true;return sxdt_av_hfs_tree(c,h+134,base,bs,sxdt32(h+130,1),false)&&sxdt_av_hfs_tree(c,h+150,base,bs,sxdt32(h+146,1),true);}

static bool sxdt_dos800(sx_context*c){if(c->size!=819200)return false;for(unsigned i=0;i<2;i++){sxdt_view v={c,c->f->file_type==XX_FILE_TYPE_OZDOS?0:(uint64_t)i*409600,409600,c->f->file_type==XX_FILE_TYPE_OZDOS?i+1:0};if(!sxdt_av_apple_dos(&v,32))return false;}return true;}
static bool sxdt_child(sx_context*c,uint64_t p,uint64_t n){uint8_t b[512];sxdt_view v={c,p,n,0};if(!sxdt_avread(&v,1024,b,512))return false;if(sxdt_av_pd_header(b))return sxdt_av_prodos(&v);if(b[0]=='B'&&b[1]=='D')return sxdt_av_hfs(&v);if(!sxdt16(b,0)&&sxdt16(b+2,0)==6)return sxdt_av_pascal(&v);return false;}
static bool sxdt_ts_children(sx_context*c){uint8_t h[12];if(!sxdt_ts(c))return false;for(unsigned i=0;i<42;i++){if(!sxdt_read(c,514+i*12,h,12))return false;uint64_t p=(uint64_t)sxdt32(h,1)*512,n=(uint64_t)sxdt32(h+4,1)*512;if(!p)break;if(n&&sxdt_span(c,p,n)&&!sxdt_child(c,p,n))return false;}return true;}
static bool sxdt_cffa(sx_context*c){const uint64_t slot=33554432;uint64_t slots=(uint64_t)c->size/slot;if((uint64_t)c->size%slot==slot-512)slots++;/* Profile6 has two 1GiB tails; infer only this exact authenticated size. */bool six=(uint64_t)c->size==4*slot+2*UINT64_C(1073741824)||(uint64_t)c->size==4*slot+2*UINT64_C(1073741824)-512;if(six)slots=6;if(slots!=4&&slots!=8&&!six)return false;uint64_t p=0;for(uint64_t i=0;i<slots;i++){uint64_t n=six&&i>=4?UINT64_C(1073741824):slot;if(n>(uint64_t)c->size-p)n=(uint64_t)c->size-p;uint8_t b[512];if(!sxdt_read(c,p+1024,b,512))return false;if(sxdt_av_pd_header(b)||(b[0]=='B'&&b[1]=='D')){if(!sxdt_child(c,p,n))return false;}p+=n;}return c->count!=0;}
static bool sxdt_ppm(sx_context*c){sxdt_view v={c,0,(uint64_t)c->size,0};uint8_t h[512],seen[8192]={0};if(!sxdt_av_prodos(&v))return false;unsigned block=2;uint64_t area=0;for(unsigned walk=0;block&&walk<65536;walk++){if(block>=65536||(seen[block/8]&(1U<<(block%8)))||!sxdt_read(c,(uint64_t)block*512,h,512))break;seen[block/8]|=(uint8_t)(1U<<(block%8));for(unsigned i=block==2?1:0;i<13;i++){uint8_t*e=h+4+i*39;if((e[0]>>4)==4&&(e[0]&15)==11&&!xx_rt_memcmp(e+1,"PASCAL.AREA",11)&&e[16]==239)area=(uint64_t)sxdt16(e+17,0)*512;}block=sxdt16(h+2,0);}if(!area||!sxdt_read(c,area,h,16)||xx_rt_memcmp(h+4,"\003PPM",4))return false;unsigned count=sxdt16(h+2,0);if(!count||count>31||!SXDT_ADD(c,ppm_header,area)||!SXDT_TABLE(c,ppm_volume_entry,area+16,count)||!SXDT_TABLE(c,ppm_volume_description,area+256,32)||!SXDT_TABLE(c,ppm_cached_volume_name,area+768,32))return false;for(unsigned i=0;i<count;i++){if(!sxdt_read(c,area+16+i*8,h,8))return false;uint64_t p=(uint64_t)sxdt16(h,0)*512,n=(uint64_t)sxdt16(h+2,0)*512;if(!sxdt_span(c,p,n))return false;sxdt_view child={c,p,n,0};if(!sxdt_av_pascal(&child))return false;}return true;}
static bool sxdt_hybrid(sx_context*c){sxdt_view v={c,0,(uint64_t)c->size,0};if(c->size!=143360||!sxdt_av_apple_dos(&v,16))return false;uint8_t h[512];for(unsigned i=0;i<2;i++){if(!sxdt_read(c,i?2816:1024,h,512))return false;if(sxdt_av_pd_header(h))return sxdt_av_prodos(&v);if(!sxdt16(h,0)&&sxdt16(h+2,0)==6&&h[6]>=1&&h[6]<=7)return sxdt_av_pascal(&v);if(!i&&h[0]=='B'&&h[1]=='D')return sxdt_av_hfs(&v);}/* The alternate CP/M view has caller-selected skew; its virtual directory is not guessed here. */return true;}
static bool sxdt_master(sx_context*c){/* Only real parent ProDOS metadata is exposed. The native configured profile
 determines embedded DOS sizes; no subclass state is read or guessed here. */sxdt_view v={c,0,(uint64_t)c->size,0};return sxdt_av_prodos(&v);}

static bool sxdt_bw_name(const uint8_t*b,unsigned n,bool required){bool padding=false;for(unsigned i=0;i<n;i++){unsigned x=b[i]&127;if(x==32){if(!i&&required)return false;padding=true;}else if(padding||x<33||x>126||x=='.'||x==','||x==';'||x==':'||x=='='||x=='?'||x=='*'||x=='<'||x=='>'||x=='['||x==']')return false;}return true;}
static bool sxdt_bw_entries(const uint8_t*b,unsigned first,unsigned end,unsigned minimum,unsigned blocks,uint8_t*used){for(unsigned i=first;i<end;i++){const uint8_t*e=b+i*32;if(e[0]==229)continue;if(e[0]>15||!sxdt_bw_name(e+1,8,true)||!sxdt_bw_name(e+9,3,false)||e[12]>31||e[13]>128||e[14]>15||e[15]>128)return false;unsigned need=(((e[12]&1)*128+e[15])+15)/16;for(unsigned j=0;j<16;j++){unsigned k=e[16+j];if(!k)continue;if(j>=need||k<minimum||k>=blocks||(used[k/8]&(1U<<(k%8))))return false;used[k/8]|=(uint8_t)(1U<<(k%8));}}return true;}
static bool sxdt_bondwell(sx_context*c){unsigned spt=c->size==348160?17:c->size==368640?18:0;if(!spt)return false;uint64_t p=2U*spt*256;uint8_t dir[4096],used[32]={0};unsigned blocks=78*spt*256/2048,n=64;if(!sxdt_read(c,p,dir,sizeof(dir))||!sxdt_bw_entries(dir,0,64,1,blocks,used))return false;if(!(used[0]&2)&&sxdt_bw_entries(dir,64,128,2,blocks,used))n=128;for(unsigned i=0;i<n;i++)if(!sxdt_put(c,dir[i*32]==229?&sxdt_cpm_deleted_entry:&sxdt_cpm_extent8,p+i*32,1))return false;return true;}
static bool sxdt_mgt_position(unsigned track,unsigned sector,uint64_t*out){if(sector<1||sector>10||(track&127)>=80)return false;*out=((uint64_t)(track&127)*2+(track>>7))*5120+(sector-1)*512;return true;}
static bool sxdt_mgt_entry(sx_context*c,uint64_t p,bool first){uint8_t e[256];if(!sxdt_read(c,p,e,sizeof(e)))return false;unsigned type=e[0]&63;if(!SXDT_ADD(c,mgt_directory_core,p)||!sxdt_put(c,first&&type>=16?&sxdt_mgt_disk_label:&sxdt_mgt_compatibility_tail,p+210,1)||!sxdt_put(c,type>=16&&type<=31?&sxdt_mgt_sam_tail:&sxdt_mgt_legacy_tail,p+220,1))return false;if(!type||type==21)return true;unsigned count=sxdt16(e+11,1),t=e[13],s=e[14];if(count>1560)return true;uint8_t seen[195]={0};for(unsigned i=0;i<count&&c->count<SXDT_LIMIT;i++){uint64_t at;if(!sxdt_mgt_position(t,s,&at)||(!(t&128)&&t<4))break;unsigned bit=((t&127)+((t&128)?80:0)-4)*10+s-1;if(bit>=1560||!(e[15+bit/8]&(1U<<(bit%8)))||(seen[bit/8]&(1U<<(bit%8))))break;seen[bit/8]|=(uint8_t)(1U<<(bit%8));if(!i&&((type>=1&&type<=4)||type==7||(type>=16&&type<=20))&&!SXDT_ADD(c,mgt_dos_file_header,at))return false;if(!SXDT_ADD(c,mgt_sector_link,at+510))return false;uint8_t link[2];if(!sxdt_read(c,at+510,link,2))break;t=link[0];s=link[1];if(!t&&!s)break;}return true;}
static bool sxdt_mgt(sx_context*c){if(c->size<819200)return false;uint8_t used[195]={0},first[256],e[256];if(!sxdt_read(c,0,first,256))return false;for(unsigned t=0;t<4;t++)for(unsigned j=0;j<20;j++){uint64_t p=(uint64_t)t*10240+j*256;if(!sxdt_read(c,p,e,256)||!sxdt_mgt_entry(c,p,t==0&&j==0))return false;if((e[0]&63)&&(e[0]&63)!=21)for(unsigned k=0;k<195;k++)used[k]|=e[15+k];}unsigned extra=first[255],type=first[0]&63;if(extra<1||extra>35||type==5||type==9)return true;for(unsigned bit=1;bit<extra*10;bit++)if(used[bit/8]&(1U<<(bit%8)))return true;for(unsigned t=4;t<4+extra;t++)for(unsigned s=1;s<=10;s++){if(t==4&&s==1&&(used[0]&1))continue;uint64_t p;if(!sxdt_mgt_position(t,s,&p))return false;if(!sxdt_mgt_entry(c,p,false)||!sxdt_mgt_entry(c,p+256,false))return false;}return true;}
static bool sxdt_solar(sx_context*c){uint8_t b[61];return sxdt_read(c,0,b,61)&&b[37]==41&&!xx_rt_memcmp(b+53,"SOL_FS  ",8)&&SXDT_ADD(c,solar_volume_identity,0);}

typedef struct sxdt_lisa {sx_context*c;uint64_t data,tags;uint32_t blocks,base,version;} sxdt_lisa_view;
static bool sxdt_lisa_page(sxdt_lisa_view*l,uint32_t page,uint64_t*p){if(page>=l->blocks-l->base)return false;*p=84+(uint64_t)(l->base+page)*512;return sxdt_span(l->c,*p,512);}
static bool sxdt_lisa_tag(sxdt_lisa_view*l,uint32_t page,uint8_t*t){return page<l->blocks-l->base&&sxdt_read(l->c,l->tags+(uint64_t)(l->base+page)*12,t,12);}
static bool sxdt_lisa_filemap(sxdt_lisa_view*l,unsigned id,const uint8_t*sr){uint32_t page=sxdt32(sr,1),size=sxdt32(sr+8,1);uint64_t p;uint8_t tag[12],h[512],mddf[280];if(!sxdt_lisa_page(l,page,&p)||!sxdt_lisa_tag(l,page,tag)||(int16_t)sxdt16(tag+4,1)!=-(int32_t)id||sxdt16(tag+6,1)||!sxdt_read(l->c,p,h,512))return true;
 uint64_t m=84+(uint64_t)l->base*512;if(sxdt_read(l->c,m,mddf,280)){unsigned hint=sxdt16(mddf+278,1);if(hint<=512-112&&!SXDT_ADD(l->c,lisa_hint_entry,p+hint))return false;}
 unsigned map=128,max=41;if(l->version==14){uint32_t next=sxdt16(tag+8,1)&2047;uint8_t nt[12];if(next==2047||!sxdt_lisa_page(l,next,&p)||!sxdt_lisa_tag(l,next,nt)||(int16_t)sxdt16(nt+4,1)!=-(int32_t)id||(sxdt16(nt+10,1)&2047)!=page||!sxdt_read(l->c,p,h,512))return true;map=0;max=84;}
 if(!SXDT_ADD(l->c,lisa_filemap_header,p+map))return false;/* The native microfloppy reader fixes the physical map position and accepts a zero-terminated list. The serialized header additionally limits live entries: never promote unused nonzero slots beyond its count to metadata. Relocated/multipage map variants are outside this physical view. */unsigned capacity=sxdt16(h+map+4,1),declared=sxdt16(h+map+6,1),count=0;if(!capacity||capacity>max||declared>capacity)return true;for(;count<declared;count++){uint8_t*e=h+map+8+count*6;unsigned n=sxdt16(e+4,1);uint32_t start=sxdt32(e,1);if(!n)break;if(start>=l->blocks-l->base||n>l->blocks-l->base-start)break;}if(!SXDT_TABLE(l->c,lisa_filemap_extent,p+map+8,count))return false;
 if(id==4&&l->version!=17){/* Flat catalog bytes are exposed only if the complete54-byte record is physically contiguous in this extent. */uint64_t logical=0;for(unsigned i=0;i<count;i++){const uint8_t*e=h+map+8+i*6;uint32_t start=sxdt32(e,1),n=sxdt16(e+4,1);uint64_t at;if(!n||!sxdt_lisa_page(l,start,&at)||n>l->blocks-l->base-start)break;uint64_t bytes=(uint64_t)n*512;if(logical>=size)break;if(bytes>size-logical)bytes=size-logical;uint64_t q=logical%54?54-logical%54:0;for(;q+54<=bytes&&l->c->count<SXDT_LIMIT;q+=54)if(!SXDT_ADD(l->c,lisa_flat_catalog_entry,at+q))return false;logical+=bytes;}}
 return true;}
static bool sxdt_lisa_node_put(sxdt_lisa_view*l,const uint64_t*pages,const sx_layout*layout,unsigned at,unsigned n){const xx_data_struct_field_desc*f=layout->fields+layout->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||at>=2048||n>(2048-at)/z)return false;for(unsigned i=0;i<n;i++){uint64_t a=at+(uint64_t)i*z,p=pages[a/512]+a%512;bool contiguous=true;for(uint64_t q=0;q<z;){if(pages[(a+q)/512]+(a+q)%512!=p+q){contiguous=false;break;}uint64_t take=512-(a+q)%512;if(take>z-q)take=z-q;q+=take;}if(contiguous&&!sxdt_put(l->c,layout,p,1))return false;}return true;}
static bool sxdt_lisa_tree(sxdt_lisa_view*l,uint32_t root){uint32_t limit=l->blocks-l->base;uint8_t*seen=xx_rt_calloc(limit,1);uint32_t*q=xx_rt_calloc(limit,sizeof(*q));if(!seen||!q){xx_rt_free(seen);xx_rt_free(q);return false;}unsigned head=0,tail=0;bool ok=true;if(root<limit){seen[root]=1;q[tail++]=root;}while(head<tail&&l->c->count<SXDT_LIMIT&&!xx_pd_is_stopped(l->c->pd)){uint32_t start=q[head++],page=start,prior=UINT32_MAX;uint64_t pages[4];uint8_t node[2048],tag[12];bool valid=true;for(unsigned i=0;i<4;i++){if(!sxdt_lisa_page(l,page,&pages[i])||!sxdt_lisa_tag(l,page,tag)||sxdt16(tag+4,1)!=4||(i&&(sxdt16(tag+10,1)&2047)!=prior)||!sxdt_read(l->c,pages[i],node+i*512,512)){valid=false;break;}prior=page;page=sxdt16(tag+8,1)&2047;}if(!valid)continue;unsigned count=sxdt16(node+2036,1),kind=node[2046];if(count>128||kind>1)continue;if(!sxdt_lisa_node_put(l,pages,&sxdt_lisa_btree_footer,2036,1)||!sxdt_lisa_node_put(l,pages,&sxdt_lisa_btree_offset,2036-count*2,count)){ok=false;break;}uint32_t next=sxdt32(node+2042,1);if(next&&next<limit&&!seen[next]){seen[next]=1;q[tail++]=next;}if(kind){uint32_t child=sxdt32(node,1);if(child<limit&&!seen[child]){seen[child]=1;q[tail++]=child;}if(!sxdt_lisa_node_put(l,pages,&sxdt_lisa_btree_child,0,1)){ok=false;break;}}
 for(unsigned i=0;i<count;i++){unsigned at=sxdt16(node+2034-i*2,1)+(kind?4:0),end=2036-count*2;if(at>end||end-at<38||node[at]!=36)continue;unsigned type=node[at+36],len=type==1?48:(type>=2&&type<=5)?64:type==8?78:38;if(len>end-at)continue;if(!sxdt_lisa_node_put(l,pages,&sxdt_lisa_btree_key,at,1)){ok=false;break;}const sx_layout*row=type==1?&sxdt_lisa_btree_directory:(type>=2&&type<=5)?&sxdt_lisa_btree_object:type==8?&sxdt_lisa_btree_thread:NULL;if(row&&!sxdt_lisa_node_put(l,pages,row,at+38,1)){ok=false;break;}}if(!ok)break;
 }xx_rt_free(seen);xx_rt_free(q);return ok;}
static bool sxdt_lisa(sx_context*c){uint8_t h[84],boot[16],m[314];if(!sxdt_read(c,0,h,84)||h[0]>63||sxdt16(h+82,1)!=256)return false;sxdt_lisa_view l={c,sxdt32(h+64,1),0,0,0,0};if(!l.data||l.data%512||l.data/512>1000000)return false;l.blocks=(uint32_t)(l.data/512);l.tags=84+l.data;if(sxdt32(h+68,1)!=(uint64_t)l.blocks*12||!sxdt_span(c,l.tags,(uint64_t)l.blocks*12)||!sxdt_read(c,84,boot,16)||sxdt16(boot+4,1)!=43690||sxdt16(boot+6,1)!=2128)return false;l.base=sxdt16(boot+14,1);if(l.base>=l.blocks||!sxdt_read(c,84+(uint64_t)l.base*512,m,sizeof(m)))return false;l.version=sxdt16(m,1);if((l.version!=14&&l.version!=15&&l.version!=17)||sxdt16(m+126,1)!=512||!SXDT_ADD(c,lisa_dc42_header,0)||!SXDT_ADD(c,lisa_microfloppy_loader,84)||!SXDT_TABLE(c,lisa_microfloppy_tag,l.tags,l.blocks)||!SXDT_ADD(c,lisa_mddf,84+(uint64_t)l.base*512))return false;unsigned packing=sxdt16(m+152,1),blocks=sxdt16(m+154,1),files=sxdt16(m+160,1);uint32_t slist=sxdt32(m+148,1);if(!packing||packing>36||!files||files>32766||files>packing*blocks||slist>=l.blocks-l.base||blocks>l.blocks-l.base-slist)return true;
 for(unsigned b=0,id=0;b<blocks&&id<files&&c->count<SXDT_LIMIT;b++){uint64_t p;uint8_t t[12];if(!sxdt_lisa_page(&l,slist+b,&p)||!sxdt_lisa_tag(&l,slist+b,t)||sxdt16(t+4,1)!=3)break;unsigned n=files-id;if(n>packing)n=packing;if(!SXDT_TABLE(c,lisa_sfile_entry,p,n))return false;for(unsigned i=0;i<n;i++,id++){uint8_t sr[14];if(id<4)continue;if(!sxdt_read(c,p+i*14,sr,14)||!sxdt_lisa_filemap(&l,id,sr))return false;}}
 return l.version!=17||sxdt_lisa_tree(&l,sxdt32(m+302,1));}

static bool sxdt_space(uint8_t b){return b==32||b==9||b==10||b==13;}
static bool sxdt_eq(const uint8_t*b,size_t n,const char*s){return xx_rt_strlen(s)==n&&!xx_rt_memcmp(b,s,n);}
static const sx_layout*sxdt_hxc_number(const uint8_t*b,size_t n,bool hex){
 if(sxdt_eq(b,n,"file_size"))return hex?&sxdt_hxc_file_size_hex:&sxdt_hxc_file_size;
 if(sxdt_eq(b,n,"number_of_track"))return hex?&sxdt_hxc_number_of_track_hex:&sxdt_hxc_number_of_track;
 if(sxdt_eq(b,n,"number_of_side"))return hex?&sxdt_hxc_number_of_side_hex:&sxdt_hxc_number_of_side;
 if(sxdt_eq(b,n,"sector_per_track"))return hex?&sxdt_hxc_sector_per_track_hex:&sxdt_hxc_sector_per_track;
 if(sxdt_eq(b,n,"sector_size"))return hex?&sxdt_hxc_sector_size_hex:&sxdt_hxc_sector_size;
 if(sxdt_eq(b,n,"start_sector_id"))return hex?&sxdt_hxc_start_sector_id_hex:&sxdt_hxc_start_sector_id;
 if(sxdt_eq(b,n,"formatvalue"))return hex?&sxdt_hxc_formatvalue_hex:&sxdt_hxc_formatvalue;
 if(sxdt_eq(b,n,"data_fill"))return hex?&sxdt_hxc_data_fill_hex:&sxdt_hxc_data_fill;
 if(sxdt_eq(b,n,"data_offset"))return hex?&sxdt_hxc_data_offset_hex:&sxdt_hxc_data_offset;
 if(sxdt_eq(b,n,"sector_id"))return hex?&sxdt_hxc_sector_id_hex:&sxdt_hxc_sector_id;
 if(sxdt_eq(b,n,"track_number"))return hex?&sxdt_hxc_track_number_hex:&sxdt_hxc_track_number;
 if(sxdt_eq(b,n,"side_number"))return hex?&sxdt_hxc_side_number_hex:&sxdt_hxc_side_number;
 return NULL;
}
static bool sxdt_xml_value(sx_context*c,const uint8_t*all,uint64_t base,size_t at,size_t n,const uint8_t*tag,size_t tn,bool hxc){while(n&&sxdt_space(all[at])){at++;n--;}while(n&&sxdt_space(all[at+n-1]))n--;if(!n)return true;const sx_layout*l=NULL;bool hex=n>2&&all[at]=='0'&&(all[at+1]=='x'||all[at+1]=='X');if(hxc){if(sxdt_eq(tag,tn,"disk_layout_name"))l=&sxdt_hxc_disk_layout_name;else if(sxdt_eq(tag,tn,"sector_data"))l=&sxdt_hxc_sector_data;else l=sxdt_hxc_number(tag,tn,hex);if(l&&l!=&sxdt_hxc_disk_layout_name&&l!=&sxdt_hxc_sector_data){bool numeric=true;for(size_t i=hex?2:0;i<n;i++){uint8_t x=all[at+i];if((x<'0'||x>'9')&&!(hex&&((x>='a'&&x<='f')||(x>='A'&&x<='F')))&&!(i==0&&(x=='+'||x=='-')))numeric=false;}if(!numeric)l=NULL;else if(hex){at+=2;n-=2;}}if(!l)l=&sxdt_hxc_xml_text;}else l=sxdt_eq(tag,tn,"name")?&sxdt_xva_xml_member_name:&sxdt_xva_xml_value;return sxdt_value(c,l,base+at,n);}
static bool sxdt_xml(sx_context*c,uint64_t base,uint64_t length,bool hxc){if(!length||length>(hxc?2097152U:16777216U)||!sxdt_span(c,base,length))return false;uint8_t*b=xx_rt_malloc((size_t)length);if(!b)return false;bool ok=sxdt_read(c,base,b,(size_t)length);size_t pos=0,depth=0,start[64],names[64],n=(size_t)length;while(ok&&pos<n&&c->count<SXDT_LIMIT&&!xx_pd_is_stopped(c->pd)){if(b[pos]!='<'){size_t a=pos;while(pos<n&&b[pos]!='<')pos++;if(depth)ok=sxdt_xml_value(c,b,base,a,pos-a,b+start[depth-1],names[depth-1],hxc);continue;}size_t a=pos;if(n-pos>=4&&!xx_rt_memcmp(b+pos,"<!--",4)){pos+=4;while(pos+3<=n&&xx_rt_memcmp(b+pos,"-->",3))pos++;if(pos+3>n)break;pos+=3;continue;}if(n-pos>=9&&!xx_rt_memcmp(b+pos,"<![CDATA[",9)){pos+=9;size_t text=pos;while(pos+3<=n&&xx_rt_memcmp(b+pos,"]]>",3))pos++;if(pos+3>n)break;if(depth)ok=sxdt_xml_value(c,b,base,text,pos-text,b+start[depth-1],names[depth-1],hxc);pos+=3;continue;}if(pos+1<n&&(b[pos+1]=='?'||b[pos+1]=='!')){uint8_t quote=0;pos+=2;while(pos<n){uint8_t x=b[pos++];if(quote){if(x==quote)quote=0;}else if(x=='\''||x=='"')quote=x;else if(x=='>')break;}continue;}pos++;bool closing=pos<n&&b[pos]=='/';if(closing)pos++;while(pos<n&&sxdt_space(b[pos]))pos++;size_t tag=pos;while(pos<n&&!sxdt_space(b[pos])&&b[pos]!='>'&&b[pos]!='/')pos++;size_t tn=pos-tag;if(!tn)break;ok=sxdt_value(c,hxc?&sxdt_hxc_xml_tag:&sxdt_xva_xml_tag,base+tag,tn);bool self=false;while(ok&&pos<n&&b[pos]!='>'){while(pos<n&&sxdt_space(b[pos]))pos++;if(pos==n||b[pos]=='>')break;if(b[pos]=='/'){self=true;pos++;continue;}size_t key=pos;while(pos<n&&!sxdt_space(b[pos])&&b[pos]!='='&&b[pos]!='>'&&b[pos]!='/')pos++;size_t kn=pos-key;while(pos<n&&sxdt_space(b[pos]))pos++;if(!kn||pos>=n||b[pos]!='=')break;pos++;while(pos<n&&sxdt_space(b[pos]))pos++;if(pos>=n||(b[pos]!='\''&&b[pos]!='"'))break;uint8_t quote=b[pos++];size_t value=pos;while(pos<n&&b[pos]!=quote)pos++;if(pos>=n)break;if(hxc){ok=sxdt_value(c,&sxdt_hxc_xml_attribute_name,base+key,kn)&&sxdt_xml_value(c,b,base,value,pos-value,b+key,kn,true);}pos++;}if(pos>=n||b[pos]!='>')break;pos++;if(closing){if(depth)depth--;}else if(!self){if(depth>=64)break;start[depth]=tag;names[depth]=tn;depth++;}(void)a;}xx_rt_free(b);return ok&&!xx_pd_is_stopped(c->pd);}
static bool sxdt_tar_octal(const uint8_t*b,unsigned n,uint64_t*out){uint64_t v=0;bool digits=false,tail=false;for(unsigned i=0;i<n;i++){unsigned x=b[i];if(x==0||x==32){if(digits)tail=true;continue;}if(tail||x<'0'||x>'7'||v>(UINT64_MAX-(x-'0'))/8)return false;v=v*8+x-'0';digits=true;}*out=v;return true;}
static bool sxdt_xva(sx_context*c){uint64_t p=0;uint8_t h[512];for(unsigned visited=0;visited<1000000&&sxdt_span(c,p,512)&&c->count<SXDT_LIMIT;visited++){if(!sxdt_read(c,p,h,512))return false;bool zero=true;for(unsigned i=0;i<512;i++)if(h[i])zero=false;if(zero)break;uint64_t size;if(!sxdt_tar_octal(h+124,12,&size)||!sxdt_span(c,p+512,size))break;bool ustar=!xx_rt_memcmp(h+257,"ustar",5);if(!sxdt_put(c,ustar?&sxdt_xva_tar_ustar:&sxdt_xva_tar_v7,p,1))return false;size_t namelen=0;while(namelen<100&&h[namelen])namelen++;if(sxdt_eq(h,namelen,"ova.xml")){if(!sxdt_xml(c,p+512,size,false))return false;}else if((namelen>=9&&!xx_rt_memcmp(h+namelen-9,".checksum",9))||(namelen>=7&&!xx_rt_memcmp(h+namelen-7,".xxhash",7))){if(size==40&&!SXDT_ADD(c,xva_sha1_text,p+512))return false;if(size==16&&!SXDT_ADD(c,xva_xxhash_text,p+512))return false;}uint64_t padded=(size+511)&~UINT64_C(511);if(size>UINT64_MAX-511||padded>(uint64_t)c->size-p-512)break;p+=512+padded;}return c->count!=0;}
static bool sxdt_plan9(sx_context*c){uint8_t b[512];if(!sxdt_read(c,512,b,512)||xx_rt_memcmp(b,"part ",5))return false;/* Native reserves finalbyte for a string terminator. */size_t p=0,n=511;while(p<n&&b[p]&&c->count<SXDT_LIMIT){size_t end=p;while(end<n&&b[end]&&b[end]!='\n')end++;size_t word[4],len[4],k=0;while(p<end&&k<4){while(p<end&&sxdt_space(b[p]))p++;word[k]=p;while(p<end&&!sxdt_space(b[p]))p++;len[k]=p-word[k];k++;}if(k==4&&sxdt_eq(b+word[0],len[0],"part")){if(!sxdt_value(c,&sxdt_plan9_keyword,512+word[0],len[0])||!sxdt_value(c,&sxdt_plan9_name,512+word[1],len[1])||!sxdt_value(c,&sxdt_plan9_first_sector,512+word[2],len[2])||!sxdt_value(c,&sxdt_plan9_end_sector,512+word[3],len[3]))return false;}p=end+1;}return c->count!=0;}

static bool sx_disktail_supports(xx_file_type_t type){switch(type){
case XX_FILE_TYPE_APPLE_RDOS:
case XX_FILE_TYPE_AMDOS:
case XX_FILE_TYPE_OZDOS:
case XX_FILE_TYPE_UNIDOS:
case XX_FILE_TYPE_CFFA:
case XX_FILE_TYPE_APPLE_DOS_HYBRID:
case XX_FILE_TYPE_DOS_MASTER:
case XX_FILE_TYPE_MAC_TS:
case XX_FILE_TYPE_PASCAL_PROFILE_MANAGER:
case XX_FILE_TYPE_LISA_FS:
case XX_FILE_TYPE_ACT_APRICOT_PC_XI_RAW:
case XX_FILE_TYPE_BONDWELL_2_DISK:
case XX_FILE_TYPE_ACORN_ATOM_DISK:
case XX_FILE_TYPE_CASIO_FZ_1_DISK:
#if SX_ALIAS_READER_FACTORY && defined(CPM)
case XX_FILE_TYPE_CPM:
#endif
case XX_FILE_TYPE_XVA:
case XX_FILE_TYPE_MGT:
case XX_FILE_TYPE_RAWCD:
case XX_FILE_TYPE_SOLAR_FS:
case XX_FILE_TYPE_PLAN9_PARTITIONS:
case XX_FILE_TYPE_HXC_XML_DISK_LAYOUT:
return true;default:return false;}}
static bool sx_disktail_build(sx_context*c){bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_APPLE_RDOS:ok=sxdt_rdos(c);break;
case XX_FILE_TYPE_AMDOS:ok=sxdt_dos800(c);break;
case XX_FILE_TYPE_OZDOS:ok=sxdt_dos800(c);break;
case XX_FILE_TYPE_UNIDOS:ok=sxdt_dos800(c);break;
case XX_FILE_TYPE_CFFA:ok=sxdt_cffa(c);break;
case XX_FILE_TYPE_APPLE_DOS_HYBRID:ok=sxdt_hybrid(c);break;
case XX_FILE_TYPE_DOS_MASTER:ok=sxdt_master(c);break;
case XX_FILE_TYPE_MAC_TS:ok=sxdt_ts_children(c);break;
case XX_FILE_TYPE_PASCAL_PROFILE_MANAGER:ok=sxdt_ppm(c);break;
case XX_FILE_TYPE_LISA_FS:ok=sxdt_lisa(c);break;
case XX_FILE_TYPE_ACT_APRICOT_PC_XI_RAW:ok=sxdt_apricot(c);break;
case XX_FILE_TYPE_BONDWELL_2_DISK:ok=sxdt_bondwell(c);break;
case XX_FILE_TYPE_ACORN_ATOM_DISK:ok=sxdt_atom(c);break;
case XX_FILE_TYPE_CASIO_FZ_1_DISK:ok=sxdt_casio(c);break;
#if SX_ALIAS_READER_FACTORY && defined(CPM)
case XX_FILE_TYPE_CPM:ok=sxdt_cpm(c);break;
#endif
case XX_FILE_TYPE_XVA:ok=sxdt_xva(c);break;
case XX_FILE_TYPE_MGT:ok=sxdt_mgt(c);break;
case XX_FILE_TYPE_RAWCD:ok=sxdt_rawcd(c);break;
case XX_FILE_TYPE_SOLAR_FS:ok=sxdt_solar(c);break;
case XX_FILE_TYPE_PLAN9_PARTITIONS:ok=sxdt_plan9(c);break;
case XX_FILE_TYPE_HXC_XML_DISK_LAYOUT:ok=sxdt_xml(c,0,(uint64_t)c->size,true);break;
default:break;}return ok&&c->count&&sxdt_finish(c);}

