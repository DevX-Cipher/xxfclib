/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical classic filesystem metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_retrofs_scope.txt. */

static const xx_data_struct_field_desc sxrfs_aodos_directory_entry_fields[] = {
    SX_FIELD("status_and_folder_ids","uint16",0,2,SX_FLAGS),
    SX_FIELD("name_koi8r","byte[14]",2,14,SX_NONE),
    SX_FIELD("first_block","uint16",16,2,SX_NONE),
    SX_FIELD("block_count","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("load_address","uint16",20,2,SX_ADDRESS),
    SX_FIELD("byte_size","uint16",22,2,SX_SIZE),
};
static const sx_layout sxrfs_aodos_directory_entry = {0x60650001U,"aodos_directory_entry",sxrfs_aodos_directory_entry_fields,SX_COUNT(sxrfs_aodos_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_prodos_directory_links_fields[] = {
    SX_FIELD("previous_block","uint16",0,2,SX_NONE),
    SX_FIELD("next_block","uint16",2,2,SX_NONE),
};
static const sx_layout sxrfs_prodos_directory_links = {0x60650002U,"prodos_directory_links",sxrfs_prodos_directory_links_fields,SX_COUNT(sxrfs_prodos_directory_links_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_prodos_volume_header_fields[] = {
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
static const sx_layout sxrfs_prodos_volume_header = {0x60650003U,"prodos_volume_header",sxrfs_prodos_volume_header_fields,SX_COUNT(sxrfs_prodos_volume_header_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_prodos_subdirectory_header_fields[] = {
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
static const sx_layout sxrfs_prodos_subdirectory_header = {0x60650004U,"prodos_subdirectory_header",sxrfs_prodos_subdirectory_header_fields,SX_COUNT(sxrfs_prodos_subdirectory_header_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_prodos_file_entry_fields[] = {
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
static const sx_layout sxrfs_prodos_file_entry = {0x60650005U,"prodos_file_entry",sxrfs_prodos_file_entry_fields,SX_COUNT(sxrfs_prodos_file_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_prodos_fork_descriptor_fields[] = {
    SX_FIELD("storage_type","uint8",0,1,SX_ID),
    SX_FIELD("key_block","uint16",1,2,SX_NONE),
    SX_FIELD("blocks_used","uint16",3,2,SX_COUNT_PROP),
    SX_FIELD("eof","uint24",5,3,SX_SIZE),
};
static const sx_layout sxrfs_prodos_fork_descriptor = {0x60650006U,"prodos_fork_descriptor",sxrfs_prodos_fork_descriptor_fields,SX_COUNT(sxrfs_prodos_fork_descriptor_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_prodos_index_low_fields[] = {
    SX_FIELD("block_number_low_bytes","byte[256]",0,256,SX_NONE),
};
static const sx_layout sxrfs_prodos_index_low = {0x60650007U,"prodos_index_low",sxrfs_prodos_index_low_fields,SX_COUNT(sxrfs_prodos_index_low_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_prodos_index_high_fields[] = {
    SX_FIELD("block_number_high_bytes","byte[256]",0,256,SX_NONE),
};
static const sx_layout sxrfs_prodos_index_high = {0x60650008U,"prodos_index_high",sxrfs_prodos_index_high_fields,SX_COUNT(sxrfs_prodos_index_high_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_pascal_volume_header_fields[] = {
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
static const sx_layout sxrfs_pascal_volume_header = {0x60650009U,"pascal_volume_header",sxrfs_pascal_volume_header_fields,SX_COUNT(sxrfs_pascal_volume_header_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_pascal_file_entry_fields[] = {
    SX_FIELD("first_block","uint16",0,2,SX_NONE),
    SX_FIELD("end_block","uint16",2,2,SX_NONE),
    SX_FIELD("kind_and_flags","uint16",4,2,SX_FLAGS),
    SX_FIELD("name_length","uint8",6,1,SX_SIZE),
    SX_FIELD("name","char[15]",7,15,SX_NONE),
    SX_FIELD("last_block_bytes","uint16",22,2,SX_SIZE),
    SX_FIELD("modification_date","uint16",24,2,SX_NONE),
};
static const sx_layout sxrfs_pascal_file_entry = {0x6065000aU,"pascal_file_entry",sxrfs_pascal_file_entry_fields,SX_COUNT(sxrfs_pascal_file_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_apple_dos_vtoc_fields[] = {
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
static const sx_layout sxrfs_apple_dos_vtoc = {0x6065000bU,"apple_dos_vtoc",sxrfs_apple_dos_vtoc_fields,SX_COUNT(sxrfs_apple_dos_vtoc_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_apple_dos_bitmap_fields[] = {
    SX_FIELD("free_sector_bits","byte[4]",0,4,SX_FLAGS),
};
static const sx_layout sxrfs_apple_dos_bitmap = {0x6065000cU,"apple_dos_bitmap",sxrfs_apple_dos_bitmap_fields,SX_COUNT(sxrfs_apple_dos_bitmap_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_apple_dos_catalog_header_fields[] = {
    SX_FIELD("unused0","uint8",0,1,SX_RESERVED),
    SX_FIELD("next_track","uint8",1,1,SX_NONE),
    SX_FIELD("next_sector","uint8",2,1,SX_NONE),
    SX_FIELD("unused3","byte[8]",3,8,SX_RESERVED),
};
static const sx_layout sxrfs_apple_dos_catalog_header = {0x6065000dU,"apple_dos_catalog_header",sxrfs_apple_dos_catalog_header_fields,SX_COUNT(sxrfs_apple_dos_catalog_header_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_apple_dos_file_entry_fields[] = {
    SX_FIELD("ts_list_track","uint8",0,1,SX_NONE),
    SX_FIELD("ts_list_sector","uint8",1,1,SX_NONE),
    SX_FIELD("file_type_and_lock","uint8",2,1,SX_FLAGS),
    SX_FIELD("high_bit_name","byte[30]",3,30,SX_NONE),
    SX_FIELD("sector_count","uint16",33,2,SX_COUNT_PROP),
};
static const sx_layout sxrfs_apple_dos_file_entry = {0x6065000eU,"apple_dos_file_entry",sxrfs_apple_dos_file_entry_fields,SX_COUNT(sxrfs_apple_dos_file_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_apple_dos_ts_header_fields[] = {
    SX_FIELD("unused0","uint8",0,1,SX_RESERVED),
    SX_FIELD("next_track","uint8",1,1,SX_NONE),
    SX_FIELD("next_sector","uint8",2,1,SX_NONE),
    SX_FIELD("unused3","byte[2]",3,2,SX_RESERVED),
    SX_FIELD("first_file_sector_index","uint16",5,2,SX_NONE),
    SX_FIELD("unused7","byte[5]",7,5,SX_RESERVED),
};
static const sx_layout sxrfs_apple_dos_ts_header = {0x6065000fU,"apple_dos_ts_header",sxrfs_apple_dos_ts_header_fields,SX_COUNT(sxrfs_apple_dos_ts_header_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_apple_dos_ts_pair_fields[] = {
    SX_FIELD("track","uint8",0,1,SX_NONE),
    SX_FIELD("sector","uint8",1,1,SX_NONE),
};
static const sx_layout sxrfs_apple_dos_ts_pair = {0x60650010U,"apple_dos_ts_pair",sxrfs_apple_dos_ts_pair_fields,SX_COUNT(sxrfs_apple_dos_ts_pair_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_mfs_master_directory_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("creation_time","uint32",2,4,SX_TIME),
    SX_FIELD("modification_time","uint32",6,4,SX_TIME),
    SX_FIELD("attributes","uint16",10,2,SX_FLAGS),
    SX_FIELD("file_count","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("directory_start_sector","uint16",14,2,SX_NONE),
    SX_FIELD("directory_sector_count","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("allocation_block_count","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("allocation_block_size","uint32",20,4,SX_SIZE),
    SX_FIELD("clump_size","uint32",24,4,SX_SIZE),
    SX_FIELD("allocation_start_sector","uint16",28,2,SX_NONE),
    SX_FIELD("next_file_id","uint32",30,4,SX_ID),
    SX_FIELD("free_blocks","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("volume_name_length","uint8",36,1,SX_SIZE),
    SX_FIELD("volume_name_macroman","byte[27]",37,27,SX_NONE),
};
static const sx_layout sxrfs_mfs_master_directory = {0x60650011U,"mfs_master_directory",sxrfs_mfs_master_directory_fields,SX_COUNT(sxrfs_mfs_master_directory_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_mfs_allocation_pair_fields[] = {
    SX_FIELD("two_packed_12bit_links","uint24",0,3,SX_NONE),
};
static const sx_layout sxrfs_mfs_allocation_pair = {0x60650012U,"mfs_allocation_pair",sxrfs_mfs_allocation_pair_fields,SX_COUNT(sxrfs_mfs_allocation_pair_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_mfs_file_entry_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("version","uint8",1,1,SX_ID),
    SX_FIELD("finder_type","uint32",2,4,SX_ID),
    SX_FIELD("finder_creator","uint32",6,4,SX_ID),
    SX_FIELD("finder_flags","uint16",10,2,SX_FLAGS),
    SX_FIELD("finder_vertical","int16",12,2,SX_NONE),
    SX_FIELD("finder_horizontal","int16",14,2,SX_NONE),
    SX_FIELD("finder_folder","int16",16,2,SX_NONE),
    SX_FIELD("file_id","uint32",18,4,SX_ID),
    SX_FIELD("data_first_block","uint16",22,2,SX_NONE),
    SX_FIELD("data_logical_size","uint32",24,4,SX_SIZE),
    SX_FIELD("data_physical_size","uint32",28,4,SX_SIZE),
    SX_FIELD("resource_first_block","uint16",32,2,SX_NONE),
    SX_FIELD("resource_logical_size","uint32",34,4,SX_SIZE),
    SX_FIELD("resource_physical_size","uint32",38,4,SX_SIZE),
    SX_FIELD("creation_time","uint32",42,4,SX_TIME),
    SX_FIELD("modification_time","uint32",46,4,SX_TIME),
    SX_FIELD("name_length","uint8",50,1,SX_SIZE),
};
static const sx_layout sxrfs_mfs_file_entry = {0x60650013U,"mfs_file_entry",sxrfs_mfs_file_entry_fields,SX_COUNT(sxrfs_mfs_file_entry_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_adfs_map0_fields[] = {
    SX_FIELD("free_start_sector_triplets","byte[246]",0,246,SX_NONE),
    SX_FIELD("reserved246","uint8",246,1,SX_RESERVED),
    SX_FIELD("disk_name_even_characters","byte[5]",247,5,SX_NONE),
    SX_FIELD("total_sectors","uint24",252,3,SX_COUNT_PROP),
    SX_FIELD("checksum","uint8",255,1,SX_CHECKSUM),
};
static const sx_layout sxrfs_adfs_map0 = {0x60650014U,"adfs_map0",sxrfs_adfs_map0_fields,SX_COUNT(sxrfs_adfs_map0_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_adfs_map1_fields[] = {
    SX_FIELD("free_length_sector_triplets","byte[246]",0,246,SX_NONE),
    SX_FIELD("disk_name_odd_characters","byte[5]",246,5,SX_NONE),
    SX_FIELD("disk_identifier","uint16",251,2,SX_ID),
    SX_FIELD("boot_option","uint8",253,1,SX_ID),
    SX_FIELD("free_list_bytes","uint8",254,1,SX_SIZE),
    SX_FIELD("checksum","uint8",255,1,SX_CHECKSUM),
};
static const sx_layout sxrfs_adfs_map1 = {0x60650015U,"adfs_map1",sxrfs_adfs_map1_fields,SX_COUNT(sxrfs_adfs_map1_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_adfs_directory_start_fields[] = {
    SX_FIELD("sequence","uint8",0,1,SX_NONE),
    SX_FIELD("signature","char[4]",1,4,SX_SIGNATURE),
};
static const sx_layout sxrfs_adfs_directory_start = {0x60650016U,"adfs_directory_start",sxrfs_adfs_directory_start_fields,SX_COUNT(sxrfs_adfs_directory_start_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_adfs_directory_entry_fields[] = {
    SX_FIELD("name_and_attributes","byte[10]",0,10,SX_FLAGS),
    SX_FIELD("load_address","uint32",10,4,SX_ADDRESS),
    SX_FIELD("execution_address","uint32",14,4,SX_ADDRESS),
    SX_FIELD("byte_size","uint32",18,4,SX_SIZE),
    SX_FIELD("first_sector","uint24",22,3,SX_NONE),
    SX_FIELD("sequence","uint8",25,1,SX_NONE),
};
static const sx_layout sxrfs_adfs_directory_entry = {0x60650017U,"adfs_directory_entry",sxrfs_adfs_directory_entry_fields,SX_COUNT(sxrfs_adfs_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_acorn_dfs_title_fields[] = {
    SX_FIELD("disk_title_first","byte[8]",0,8,SX_NONE),
};
static const sx_layout sxrfs_acorn_dfs_title = {0x60650018U,"acorn_dfs_title",sxrfs_acorn_dfs_title_fields,SX_COUNT(sxrfs_acorn_dfs_title_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_acorn_dfs_name_fields[] = {
    SX_FIELD("name","byte[7]",0,7,SX_NONE),
    SX_FIELD("directory_and_locked","uint8",7,1,SX_FLAGS),
};
static const sx_layout sxrfs_acorn_dfs_name = {0x60650019U,"acorn_dfs_name",sxrfs_acorn_dfs_name_fields,SX_COUNT(sxrfs_acorn_dfs_name_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_acorn_dfs_catalog_header_fields[] = {
    SX_FIELD("disk_title_last","byte[4]",0,4,SX_NONE),
    SX_FIELD("write_cycle","uint8",4,1,SX_NONE),
    SX_FIELD("file_entry_bytes","uint8",5,1,SX_SIZE),
    SX_FIELD("boot_and_sector_high","uint8",6,1,SX_FLAGS),
    SX_FIELD("total_sector_low","uint8",7,1,SX_NONE),
};
static const sx_layout sxrfs_acorn_dfs_catalog_header = {0x6065001aU,"acorn_dfs_catalog_header",sxrfs_acorn_dfs_catalog_header_fields,SX_COUNT(sxrfs_acorn_dfs_catalog_header_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_acorn_dfs_file_metadata_fields[] = {
    SX_FIELD("load_address_low","uint16",0,2,SX_ID),
    SX_FIELD("execution_address_low","uint16",2,2,SX_ID),
    SX_FIELD("length_low","uint16",4,2,SX_NONE),
    SX_FIELD("packed_high","uint8",6,1,SX_FLAGS),
    SX_FIELD("start_sector_low","uint8",7,1,SX_NONE),
};
static const sx_layout sxrfs_acorn_dfs_file_metadata = {0x6065001bU,"acorn_dfs_file_metadata",sxrfs_acorn_dfs_file_metadata_fields,SX_COUNT(sxrfs_acorn_dfs_file_metadata_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_atari_atr_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("paragraphs_low","uint16",2,2,SX_NONE),
    SX_FIELD("sector_size","uint16",4,2,SX_SIZE),
    SX_FIELD("paragraphs_high","uint8",6,1,SX_NONE),
    SX_FIELD("reserved","byte[8]",7,8,SX_RESERVED),
    SX_FIELD("flags","uint8",15,1,SX_FLAGS),
};
static const sx_layout sxrfs_atari_atr_header = {0x6065001cU,"atari_atr_header",sxrfs_atari_atr_header_fields,SX_COUNT(sxrfs_atari_atr_header_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_atari_dos2_vtoc_fields[] = {
    SX_FIELD("dos_code","uint8",0,1,SX_ID),
    SX_FIELD("total_available_sectors","uint16",1,2,SX_COUNT_PROP),
    SX_FIELD("free_sectors","uint16",3,2,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[5]",5,5,SX_RESERVED),
    SX_FIELD("free_sector_bitmap","byte[90]",10,90,SX_FLAGS),
};
static const sx_layout sxrfs_atari_dos2_vtoc = {0x6065001dU,"atari_dos2_vtoc",sxrfs_atari_dos2_vtoc_fields,SX_COUNT(sxrfs_atari_dos2_vtoc_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_atari_dos2_directory_entry_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("sector_count","uint16",1,2,SX_COUNT_PROP),
    SX_FIELD("first_sector","uint16",3,2,SX_NONE),
    SX_FIELD("name","byte[8]",5,8,SX_NONE),
    SX_FIELD("extension","byte[3]",13,3,SX_NONE),
};
static const sx_layout sxrfs_atari_dos2_directory_entry = {0x6065001eU,"atari_dos2_directory_entry",sxrfs_atari_dos2_directory_entry_fields,SX_COUNT(sxrfs_atari_dos2_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_atari_dos2_sector_trailer_fields[] = {
    SX_FIELD("file_index_and_next_high","uint8",0,1,SX_FLAGS),
    SX_FIELD("next_sector_low","uint8",1,1,SX_NONE),
    SX_FIELD("used_bytes","uint8",2,1,SX_SIZE),
};
static const sx_layout sxrfs_atari_dos2_sector_trailer = {0x6065001fU,"atari_dos2_sector_trailer",sxrfs_atari_dos2_sector_trailer_fields,SX_COUNT(sxrfs_atari_dos2_sector_trailer_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_ti99_vib_fields[] = {
    SX_FIELD("volume_name","char[10]",0,10,SX_NONE),
    SX_FIELD("sector_count","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",12,1,SX_COUNT_PROP),
    SX_FIELD("signature","char[3]",13,3,SX_SIGNATURE),
    SX_FIELD("protection","uint8",16,1,SX_FLAGS),
    SX_FIELD("tracks_per_side","uint8",17,1,SX_COUNT_PROP),
    SX_FIELD("side_count","uint8",18,1,SX_COUNT_PROP),
    SX_FIELD("density","uint8",19,1,SX_ID),
    SX_FIELD("reserved","byte[36]",20,36,SX_RESERVED),
    SX_FIELD("allocation_bitmap","byte[200]",56,200,SX_FLAGS),
};
static const sx_layout sxrfs_ti99_vib = {0x60650020U,"ti99_vib",sxrfs_ti99_vib_fields,SX_COUNT(sxrfs_ti99_vib_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_ti99_directory_pointer_fields[] = {
    SX_FIELD("file_descriptor_sector","uint16",0,2,SX_NONE),
};
static const sx_layout sxrfs_ti99_directory_pointer = {0x60650021U,"ti99_directory_pointer",sxrfs_ti99_directory_pointer_fields,SX_COUNT(sxrfs_ti99_directory_pointer_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_ti99_file_descriptor_fields[] = {
    SX_FIELD("name","char[10]",0,10,SX_NONE),
    SX_FIELD("reserved10","byte[2]",10,2,SX_RESERVED),
    SX_FIELD("flags","uint8",12,1,SX_FLAGS),
    SX_FIELD("records_per_sector","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("sector_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("last_sector_bytes","uint8",16,1,SX_NONE),
    SX_FIELD("record_length","uint8",17,1,SX_SIZE),
    SX_FIELD("record_count","uint16le",18,2,SX_COUNT_PROP),
    SX_FIELD("reserved20","byte[8]",20,8,SX_RESERVED),
};
static const sx_layout sxrfs_ti99_file_descriptor = {0x60650022U,"ti99_file_descriptor",sxrfs_ti99_file_descriptor_fields,SX_COUNT(sxrfs_ti99_file_descriptor_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_ti99_cluster_fields[] = {
    SX_FIELD("packed_sector_and_end","byte[3]",0,3,SX_NONE),
};
static const sx_layout sxrfs_ti99_cluster = {0x60650023U,"ti99_cluster",sxrfs_ti99_cluster_fields,SX_COUNT(sxrfs_ti99_cluster_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_os9_disk_descriptor_fields[] = {
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
static const sx_layout sxrfs_os9_disk_descriptor = {0x60650024U,"os9_disk_descriptor",sxrfs_os9_disk_descriptor_fields,SX_COUNT(sxrfs_os9_disk_descriptor_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_os9_path_options_fields[] = {
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
static const sx_layout sxrfs_os9_path_options = {0x60650025U,"os9_path_options",sxrfs_os9_path_options_fields,SX_COUNT(sxrfs_os9_path_options_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_os9_file_descriptor_fields[] = {
    SX_FIELD("attributes","uint8",0,1,SX_FLAGS),
    SX_FIELD("owner","uint16",1,2,SX_ID),
    SX_FIELD("modification_ymdhm","byte[5]",3,5,SX_NONE),
    SX_FIELD("link_count","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("byte_size","uint32",9,4,SX_SIZE),
    SX_FIELD("creation_ymd","byte[3]",13,3,SX_NONE),
};
static const sx_layout sxrfs_os9_file_descriptor = {0x60650026U,"os9_file_descriptor",sxrfs_os9_file_descriptor_fields,SX_COUNT(sxrfs_os9_file_descriptor_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_os9_segment_fields[] = {
    SX_FIELD("first_sector","uint24",0,3,SX_NONE),
    SX_FIELD("sector_count","uint16",3,2,SX_COUNT_PROP),
};
static const sx_layout sxrfs_os9_segment = {0x60650027U,"os9_segment",sxrfs_os9_segment_fields,SX_COUNT(sxrfs_os9_segment_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_os9_directory_entry_fields[] = {
    SX_FIELD("name","byte[29]",0,29,SX_NONE),
    SX_FIELD("file_descriptor_sector","uint24",29,3,SX_NONE),
};
static const sx_layout sxrfs_os9_directory_entry = {0x60650028U,"os9_directory_entry",sxrfs_os9_directory_entry_fields,SX_COUNT(sxrfs_os9_directory_entry_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_cbm_sector_link_fields[] = {
    SX_FIELD("next_track","uint8",0,1,SX_NONE),
    SX_FIELD("next_sector_or_last_byte","uint8",1,1,SX_NONE),
};
static const sx_layout sxrfs_cbm_sector_link = {0x60650029U,"cbm_sector_link",sxrfs_cbm_sector_link_fields,SX_COUNT(sxrfs_cbm_sector_link_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_cbm_directory_entry_fields[] = {
    SX_FIELD("file_type_flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("first_track","uint8",1,1,SX_NONE),
    SX_FIELD("first_sector","uint8",2,1,SX_NONE),
    SX_FIELD("name_petscii","byte[16]",3,16,SX_NONE),
    SX_FIELD("rel_side_track","uint8",19,1,SX_NONE),
    SX_FIELD("rel_side_sector","uint8",20,1,SX_NONE),
    SX_FIELD("record_length","uint8",21,1,SX_SIZE),
    SX_FIELD("reserved","byte[6]",22,6,SX_RESERVED),
    SX_FIELD("block_count","uint16",28,2,SX_COUNT_PROP),
};
static const sx_layout sxrfs_cbm_directory_entry = {0x6065002aU,"cbm_directory_entry",sxrfs_cbm_directory_entry_fields,SX_COUNT(sxrfs_cbm_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_cbm_d64_bam_header_fields[] = {
    SX_FIELD("directory_track","uint8",0,1,SX_NONE),
    SX_FIELD("directory_sector","uint8",1,1,SX_NONE),
    SX_FIELD("dos_version","uint8",2,1,SX_ID),
    SX_FIELD("double_sided_flag","uint8",3,1,SX_FLAGS),
};
static const sx_layout sxrfs_cbm_d64_bam_header = {0x6065002bU,"cbm_d64_bam_header",sxrfs_cbm_d64_bam_header_fields,SX_COUNT(sxrfs_cbm_d64_bam_header_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_cbm_bam_entry3_fields[] = {
    SX_FIELD("free_count","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("free_sector_bits","byte[3]",1,3,SX_FLAGS),
};
static const sx_layout sxrfs_cbm_bam_entry3 = {0x6065002cU,"cbm_bam_entry3",sxrfs_cbm_bam_entry3_fields,SX_COUNT(sxrfs_cbm_bam_entry3_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_cbm_bam_entry4_fields[] = {
    SX_FIELD("free_count","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("free_sector_bits","byte[4]",1,4,SX_FLAGS),
};
static const sx_layout sxrfs_cbm_bam_entry4 = {0x6065002dU,"cbm_bam_entry4",sxrfs_cbm_bam_entry4_fields,SX_COUNT(sxrfs_cbm_bam_entry4_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_cbm_bam_entry5_fields[] = {
    SX_FIELD("free_count","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("free_sector_bits","byte[5]",1,5,SX_FLAGS),
};
static const sx_layout sxrfs_cbm_bam_entry5 = {0x6065002eU,"cbm_bam_entry5",sxrfs_cbm_bam_entry5_fields,SX_COUNT(sxrfs_cbm_bam_entry5_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_cbm_bitmap3_fields[] = {
    SX_FIELD("free_sector_bits","byte[3]",0,3,SX_FLAGS),
};
static const sx_layout sxrfs_cbm_bitmap3 = {0x6065002fU,"cbm_bitmap3",sxrfs_cbm_bitmap3_fields,SX_COUNT(sxrfs_cbm_bitmap3_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_cbm_free_count_fields[] = {
    SX_FIELD("free_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxrfs_cbm_free_count = {0x60650030U,"cbm_free_count",sxrfs_cbm_free_count_fields,SX_COUNT(sxrfs_cbm_free_count_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_cbm_d64_disk_identity_fields[] = {
    SX_FIELD("disk_name_petscii","byte[16]",0,16,SX_NONE),
    SX_FIELD("padding","byte[2]",16,2,SX_RESERVED),
    SX_FIELD("disk_id","byte[2]",18,2,SX_ID),
    SX_FIELD("padding164","uint8",20,1,SX_RESERVED),
    SX_FIELD("dos_type","byte[2]",21,2,SX_ID),
    SX_FIELD("padding167","byte[4]",23,4,SX_RESERVED),
};
static const sx_layout sxrfs_cbm_d64_disk_identity = {0x60650031U,"cbm_d64_disk_identity",sxrfs_cbm_d64_disk_identity_fields,SX_COUNT(sxrfs_cbm_d64_disk_identity_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_cbm_d81_header_fields[] = {
    SX_FIELD("directory_track","uint8",0,1,SX_NONE),
    SX_FIELD("directory_sector","uint8",1,1,SX_NONE),
    SX_FIELD("dos_version","uint8",2,1,SX_ID),
    SX_FIELD("reserved3","uint8",3,1,SX_RESERVED),
    SX_FIELD("disk_name_petscii","byte[16]",4,16,SX_NONE),
    SX_FIELD("padding20","byte[2]",20,2,SX_RESERVED),
    SX_FIELD("disk_id","byte[2]",22,2,SX_ID),
    SX_FIELD("padding24","uint8",24,1,SX_RESERVED),
    SX_FIELD("dos_type","byte[2]",25,2,SX_ID),
};
static const sx_layout sxrfs_cbm_d81_header = {0x60650032U,"cbm_d81_header",sxrfs_cbm_d81_header_fields,SX_COUNT(sxrfs_cbm_d81_header_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_cbm_d81_bam_header_fields[] = {
    SX_FIELD("next_track","uint8",0,1,SX_NONE),
    SX_FIELD("next_sector","uint8",1,1,SX_NONE),
    SX_FIELD("dos_version","uint8",2,1,SX_ID),
    SX_FIELD("version_complement","uint8",3,1,SX_NONE),
    SX_FIELD("disk_id","byte[2]",4,2,SX_ID),
    SX_FIELD("io_flags","uint8",6,1,SX_FLAGS),
    SX_FIELD("autoboot","uint8",7,1,SX_FLAGS),
    SX_FIELD("reserved","byte[8]",8,8,SX_RESERVED),
};
static const sx_layout sxrfs_cbm_d81_bam_header = {0x60650033U,"cbm_d81_bam_header",sxrfs_cbm_d81_bam_header_fields,SX_COUNT(sxrfs_cbm_d81_bam_header_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_cbm_d8x_header_fields[] = {
    SX_FIELD("bam_track","uint8",0,1,SX_NONE),
    SX_FIELD("bam_sector","uint8",1,1,SX_NONE),
    SX_FIELD("dos_version","uint8",2,1,SX_ID),
    SX_FIELD("reserved3","byte[3]",3,3,SX_RESERVED),
    SX_FIELD("disk_name_petscii","byte[16]",6,16,SX_NONE),
    SX_FIELD("padding22","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("disk_id","byte[2]",24,2,SX_ID),
    SX_FIELD("padding26","uint8",26,1,SX_RESERVED),
    SX_FIELD("dos_type","byte[2]",27,2,SX_ID),
};
static const sx_layout sxrfs_cbm_d8x_header = {0x60650034U,"cbm_d8x_header",sxrfs_cbm_d8x_header_fields,SX_COUNT(sxrfs_cbm_d8x_header_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_cbm_d8x_bam_header_fields[] = {
    SX_FIELD("next_track","uint8",0,1,SX_NONE),
    SX_FIELD("next_sector","uint8",1,1,SX_NONE),
    SX_FIELD("dos_version","uint8",2,1,SX_ID),
    SX_FIELD("reserved3","uint8",3,1,SX_RESERVED),
    SX_FIELD("first_track","uint8",4,1,SX_NONE),
    SX_FIELD("end_track","uint8",5,1,SX_NONE),
};
static const sx_layout sxrfs_cbm_d8x_bam_header = {0x60650035U,"cbm_d8x_bam_header",sxrfs_cbm_d8x_bam_header_fields,SX_COUNT(sxrfs_cbm_d8x_bam_header_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_cbm_d90_config_fields[] = {
    SX_FIELD("bad_sector_track","uint8",0,1,SX_NONE),
    SX_FIELD("bad_sector_number","uint8",1,1,SX_NONE),
    SX_FIELD("reserved2","uint8",2,1,SX_RESERVED),
    SX_FIELD("reserved3","uint8",3,1,SX_RESERVED),
    SX_FIELD("directory_track","uint8",4,1,SX_NONE),
    SX_FIELD("directory_sector","uint8",5,1,SX_NONE),
    SX_FIELD("header_track","uint8",6,1,SX_NONE),
    SX_FIELD("header_sector","uint8",7,1,SX_NONE),
    SX_FIELD("bam_track","uint8",8,1,SX_NONE),
    SX_FIELD("bam_sector","uint8",9,1,SX_NONE),
    SX_FIELD("disk_id","byte[2]",10,2,SX_ID),
};
static const sx_layout sxrfs_cbm_d90_config = {0x60650036U,"cbm_d90_config",sxrfs_cbm_d90_config_fields,SX_COUNT(sxrfs_cbm_d90_config_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_cbm_d90_header_fields[] = {
    SX_FIELD("directory_track","uint8",0,1,SX_NONE),
    SX_FIELD("directory_sector","uint8",1,1,SX_NONE),
    SX_FIELD("reserved2","byte[4]",2,4,SX_RESERVED),
    SX_FIELD("disk_name_petscii","byte[16]",6,16,SX_NONE),
    SX_FIELD("padding22","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("disk_id","byte[2]",24,2,SX_ID),
    SX_FIELD("padding26","uint8",26,1,SX_RESERVED),
    SX_FIELD("dos_type","byte[2]",27,2,SX_ID),
};
static const sx_layout sxrfs_cbm_d90_header = {0x60650037U,"cbm_d90_header",sxrfs_cbm_d90_header_fields,SX_COUNT(sxrfs_cbm_d90_header_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_cbm_d90_bam_header_fields[] = {
    SX_FIELD("next_track","uint8",0,1,SX_NONE),
    SX_FIELD("next_sector","uint8",1,1,SX_NONE),
    SX_FIELD("previous_track","uint8",2,1,SX_NONE),
    SX_FIELD("previous_sector","uint8",3,1,SX_NONE),
    SX_FIELD("first_track","uint8",4,1,SX_NONE),
    SX_FIELD("end_track","uint8",5,1,SX_NONE),
    SX_FIELD("reserved6","byte[10]",6,10,SX_RESERVED),
};
static const sx_layout sxrfs_cbm_d90_bam_header = {0x60650038U,"cbm_d90_bam_header",sxrfs_cbm_d90_bam_header_fields,SX_COUNT(sxrfs_cbm_d90_bam_header_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_adf_boot_header_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("dos_flags","uint8",3,1,SX_FLAGS),
    SX_FIELD("boot_checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("root_block","uint32",8,4,SX_NONE),
};
static const sx_layout sxrfs_adf_boot_header = {0x60650039U,"adf_boot_header",sxrfs_adf_boot_header_fields,SX_COUNT(sxrfs_adf_boot_header_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_adf_root_block_fields[] = {
    SX_FIELD("block_type","int32",0,4,SX_ID),
    SX_FIELD("header_key","uint32",4,4,SX_NONE),
    SX_FIELD("high_sequence","uint32",8,4,SX_NONE),
    SX_FIELD("hash_table_size","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("first_data","uint32",16,4,SX_NONE),
    SX_FIELD("checksum","uint32",20,4,SX_CHECKSUM),
    SX_FIELD("hash_block_numbers","uint32[72]",24,288,SX_NONE),
    SX_FIELD("bitmap_valid","int32",312,4,SX_FLAGS),
    SX_FIELD("bitmap_blocks","uint32[25]",316,100,SX_NONE),
    SX_FIELD("bitmap_extension_block","uint32",416,4,SX_NONE),
    SX_FIELD("modification_days","uint32",420,4,SX_NONE),
    SX_FIELD("modification_minutes","uint32",424,4,SX_NONE),
    SX_FIELD("modification_ticks","uint32",428,4,SX_NONE),
    SX_FIELD("volume_name_length","uint8",432,1,SX_SIZE),
    SX_FIELD("volume_name","byte[31]",433,31,SX_NONE),
    SX_FIELD("reserved464","byte[8]",464,8,SX_RESERVED),
    SX_FIELD("volume_modification_days","uint32",472,4,SX_NONE),
    SX_FIELD("volume_modification_minutes","uint32",476,4,SX_NONE),
    SX_FIELD("volume_modification_ticks","uint32",480,4,SX_NONE),
    SX_FIELD("creation_days","uint32",484,4,SX_NONE),
    SX_FIELD("creation_minutes","uint32",488,4,SX_NONE),
    SX_FIELD("creation_ticks","uint32",492,4,SX_NONE),
    SX_FIELD("reserved496","uint32",496,4,SX_RESERVED),
    SX_FIELD("reserved500","uint32",500,4,SX_RESERVED),
    SX_FIELD("directory_cache_block","uint32",504,4,SX_NONE),
    SX_FIELD("secondary_type","int32",508,4,SX_ID),
};
static const sx_layout sxrfs_adf_root_block = {0x6065003aU,"adf_root_block",sxrfs_adf_root_block_fields,SX_COUNT(sxrfs_adf_root_block_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_adf_block_prefix_fields[] = {
    SX_FIELD("block_type","int32",0,4,SX_ID),
    SX_FIELD("header_key","uint32",4,4,SX_NONE),
    SX_FIELD("high_sequence","uint32",8,4,SX_NONE),
    SX_FIELD("data_size_or_table_size","uint32",12,4,SX_NONE),
    SX_FIELD("first_or_next_data_block","uint32",16,4,SX_NONE),
    SX_FIELD("checksum","uint32",20,4,SX_CHECKSUM),
};
static const sx_layout sxrfs_adf_block_prefix = {0x6065003bU,"adf_block_prefix",sxrfs_adf_block_prefix_fields,SX_COUNT(sxrfs_adf_block_prefix_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_adf_block_pointer_fields[] = {
    SX_FIELD("block_number","uint32",0,4,SX_NONE),
};
static const sx_layout sxrfs_adf_block_pointer = {0x6065003cU,"adf_block_pointer",sxrfs_adf_block_pointer_fields,SX_COUNT(sxrfs_adf_block_pointer_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_adf_classic_entry_tail_fields[] = {
    SX_FIELD("reserved312","uint32",0,4,SX_RESERVED),
    SX_FIELD("owner_uid","uint16",4,2,SX_ID),
    SX_FIELD("owner_gid","uint16",6,2,SX_ID),
    SX_FIELD("protection","uint32",8,4,SX_FLAGS),
    SX_FIELD("byte_size","uint32",12,4,SX_SIZE),
    SX_FIELD("comment_length","uint8",16,1,SX_SIZE),
    SX_FIELD("comment","byte[79]",17,79,SX_NONE),
    SX_FIELD("reserved408","byte[12]",96,12,SX_RESERVED),
    SX_FIELD("modification_days","uint32",108,4,SX_NONE),
    SX_FIELD("modification_minutes","uint32",112,4,SX_NONE),
    SX_FIELD("modification_ticks","uint32",116,4,SX_NONE),
    SX_FIELD("name_length","uint8",120,1,SX_SIZE),
    SX_FIELD("name","byte[31]",121,31,SX_NONE),
    SX_FIELD("reserved464","byte[4]",152,4,SX_RESERVED),
    SX_FIELD("real_entry_block","uint32",156,4,SX_NONE),
    SX_FIELD("next_link_block","uint32",160,4,SX_NONE),
    SX_FIELD("reserved476","byte[20]",164,20,SX_RESERVED),
    SX_FIELD("hash_chain","uint32",184,4,SX_NONE),
    SX_FIELD("parent_block","uint32",188,4,SX_NONE),
    SX_FIELD("extension_block","uint32",192,4,SX_NONE),
    SX_FIELD("secondary_type","int32",196,4,SX_ID),
};
static const sx_layout sxrfs_adf_classic_entry_tail = {0x6065003dU,"adf_classic_entry_tail",sxrfs_adf_classic_entry_tail_fields,SX_COUNT(sxrfs_adf_classic_entry_tail_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_adf_bitmap_block_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("free_block_bits","uint32[127]",4,508,SX_FLAGS),
};
static const sx_layout sxrfs_adf_bitmap_block = {0x6065003eU,"adf_bitmap_block",sxrfs_adf_bitmap_block_fields,SX_COUNT(sxrfs_adf_bitmap_block_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_hfs_master_directory_fields[] = {
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
static const sx_layout sxrfs_hfs_master_directory = {0x6065003fU,"hfs_master_directory",sxrfs_hfs_master_directory_fields,SX_COUNT(sxrfs_hfs_master_directory_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_hfs_btree_node_fields[] = {
    SX_FIELD("forward_link","uint32",0,4,SX_NONE),
    SX_FIELD("backward_link","uint32",4,4,SX_NONE),
    SX_FIELD("kind","int8",8,1,SX_ID),
    SX_FIELD("height","uint8",9,1,SX_NONE),
    SX_FIELD("record_count","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("reserved","uint16",12,2,SX_RESERVED),
};
static const sx_layout sxrfs_hfs_btree_node = {0x60650040U,"hfs_btree_node",sxrfs_hfs_btree_node_fields,SX_COUNT(sxrfs_hfs_btree_node_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_hfs_btree_header_fields[] = {
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
static const sx_layout sxrfs_hfs_btree_header = {0x60650041U,"hfs_btree_header",sxrfs_hfs_btree_header_fields,SX_COUNT(sxrfs_hfs_btree_header_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_hfs_node_record_offset_fields[] = {
    SX_FIELD("record_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxrfs_hfs_node_record_offset = {0x60650042U,"hfs_node_record_offset",sxrfs_hfs_node_record_offset_fields,SX_COUNT(sxrfs_hfs_node_record_offset_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_hfs_catalog_key_prefix_fields[] = {
    SX_FIELD("key_length","uint8",0,1,SX_SIZE),
    SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
    SX_FIELD("parent_catalog_id","uint32",2,4,SX_ID),
    SX_FIELD("name_length","uint8",6,1,SX_SIZE),
};
static const sx_layout sxrfs_hfs_catalog_key_prefix = {0x60650043U,"hfs_catalog_key_prefix",sxrfs_hfs_catalog_key_prefix_fields,SX_COUNT(sxrfs_hfs_catalog_key_prefix_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_hfs_extents_key_fields[] = {
    SX_FIELD("key_length","uint8",0,1,SX_SIZE),
    SX_FIELD("fork_type","uint8",1,1,SX_ID),
    SX_FIELD("file_id","uint32",2,4,SX_ID),
    SX_FIELD("first_allocation_block","uint16",6,2,SX_NONE),
};
static const sx_layout sxrfs_hfs_extents_key = {0x60650044U,"hfs_extents_key",sxrfs_hfs_extents_key_fields,SX_COUNT(sxrfs_hfs_extents_key_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_hfs_extent_fields[] = {
    SX_FIELD("first_allocation_block","uint16",0,2,SX_NONE),
    SX_FIELD("block_count","uint16",2,2,SX_COUNT_PROP),
};
static const sx_layout sxrfs_hfs_extent = {0x60650045U,"hfs_extent",sxrfs_hfs_extent_fields,SX_COUNT(sxrfs_hfs_extent_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_hfs_btree_child_fields[] = {
    SX_FIELD("child_node","uint32",0,4,SX_NONE),
};
static const sx_layout sxrfs_hfs_btree_child = {0x60650046U,"hfs_btree_child",sxrfs_hfs_btree_child_fields,SX_COUNT(sxrfs_hfs_btree_child_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_hfs_catalog_folder_fields[] = {
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
static const sx_layout sxrfs_hfs_catalog_folder = {0x60650047U,"hfs_catalog_folder",sxrfs_hfs_catalog_folder_fields,SX_COUNT(sxrfs_hfs_catalog_folder_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_hfs_catalog_file_fields[] = {
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
static const sx_layout sxrfs_hfs_catalog_file = {0x60650048U,"hfs_catalog_file",sxrfs_hfs_catalog_file_fields,SX_COUNT(sxrfs_hfs_catalog_file_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_hfs_catalog_thread_fields[] = {
    SX_FIELD("record_type","int16",0,2,SX_ID),
    SX_FIELD("reserved","int32[2]",2,8,SX_RESERVED),
    SX_FIELD("parent_catalog_id","uint32",10,4,SX_ID),
    SX_FIELD("name_length","uint8",14,1,SX_SIZE),
    SX_FIELD("name_macroman","byte[31]",15,31,SX_NONE),
};
static const sx_layout sxrfs_hfs_catalog_thread = {0x60650049U,"hfs_catalog_thread",sxrfs_hfs_catalog_thread_fields,SX_COUNT(sxrfs_hfs_catalog_thread_fields),SX_BE};

static const xx_data_struct_field_desc sxrfs_atari_dos25_extended_vtoc_fields[] = {
    SX_FIELD("primary_bitmap_mirror","byte[84]",0,84,SX_FLAGS),
    SX_FIELD("extended_free_bitmap","byte[38]",84,38,SX_FLAGS),
    SX_FIELD("extended_free_sectors","uint16",122,2,SX_COUNT_PROP),
};
static const sx_layout sxrfs_atari_dos25_extended_vtoc = {0x6065004aU,"atari_dos25_extended_vtoc",sxrfs_atari_dos25_extended_vtoc_fields,SX_COUNT(sxrfs_atari_dos25_extended_vtoc_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_apple_dos_bitmap16_fields[] = {
    SX_FIELD("free_sector_bits","byte[2]",0,2,SX_FLAGS),
};
static const sx_layout sxrfs_apple_dos_bitmap16 = {0x6065004bU,"apple_dos_bitmap16",sxrfs_apple_dos_bitmap16_fields,SX_COUNT(sxrfs_apple_dos_bitmap16_fields),SX_LE};

static const xx_data_struct_field_desc sxrfs_adfs_directory_tail_fields[] = {
    SX_FIELD("terminator","uint8",0,1,SX_RESERVED),
    SX_FIELD("directory_name","byte[10]",1,10,SX_NONE),
    SX_FIELD("parent_sector","uint24",11,3,SX_NONE),
    SX_FIELD("title","byte[19]",14,19,SX_NONE),
    SX_FIELD("reserved","byte[14]",33,14,SX_RESERVED),
    SX_FIELD("sequence","uint8",47,1,SX_NONE),
    SX_FIELD("signature","char[4]",48,4,SX_SIGNATURE),
    SX_FIELD("reserved_last","uint8",52,1,SX_RESERVED),
};
static const sx_layout sxrfs_adfs_directory_tail = {0x6065004cU,"adfs_directory_tail",sxrfs_adfs_directory_tail_fields,SX_COUNT(sxrfs_adfs_directory_tail_fields),SX_LE};

static const sx_layout *const sx_retrofs_layouts[] = {
    &sxrfs_aodos_directory_entry,
    &sxrfs_prodos_directory_links,
    &sxrfs_prodos_volume_header,
    &sxrfs_prodos_subdirectory_header,
    &sxrfs_prodos_file_entry,
    &sxrfs_prodos_fork_descriptor,
    &sxrfs_prodos_index_low,
    &sxrfs_prodos_index_high,
    &sxrfs_pascal_volume_header,
    &sxrfs_pascal_file_entry,
    &sxrfs_apple_dos_vtoc,
    &sxrfs_apple_dos_bitmap,
    &sxrfs_apple_dos_catalog_header,
    &sxrfs_apple_dos_file_entry,
    &sxrfs_apple_dos_ts_header,
    &sxrfs_apple_dos_ts_pair,
    &sxrfs_mfs_master_directory,
    &sxrfs_mfs_allocation_pair,
    &sxrfs_mfs_file_entry,
    &sxrfs_adfs_map0,
    &sxrfs_adfs_map1,
    &sxrfs_adfs_directory_start,
    &sxrfs_adfs_directory_entry,
    &sxrfs_acorn_dfs_title,
    &sxrfs_acorn_dfs_name,
    &sxrfs_acorn_dfs_catalog_header,
    &sxrfs_acorn_dfs_file_metadata,
    &sxrfs_atari_atr_header,
    &sxrfs_atari_dos2_vtoc,
    &sxrfs_atari_dos2_directory_entry,
    &sxrfs_atari_dos2_sector_trailer,
    &sxrfs_ti99_vib,
    &sxrfs_ti99_directory_pointer,
    &sxrfs_ti99_file_descriptor,
    &sxrfs_ti99_cluster,
    &sxrfs_os9_disk_descriptor,
    &sxrfs_os9_path_options,
    &sxrfs_os9_file_descriptor,
    &sxrfs_os9_segment,
    &sxrfs_os9_directory_entry,
    &sxrfs_cbm_sector_link,
    &sxrfs_cbm_directory_entry,
    &sxrfs_cbm_d64_bam_header,
    &sxrfs_cbm_bam_entry3,
    &sxrfs_cbm_bam_entry4,
    &sxrfs_cbm_bam_entry5,
    &sxrfs_cbm_bitmap3,
    &sxrfs_cbm_free_count,
    &sxrfs_cbm_d64_disk_identity,
    &sxrfs_cbm_d81_header,
    &sxrfs_cbm_d81_bam_header,
    &sxrfs_cbm_d8x_header,
    &sxrfs_cbm_d8x_bam_header,
    &sxrfs_cbm_d90_config,
    &sxrfs_cbm_d90_header,
    &sxrfs_cbm_d90_bam_header,
    &sxrfs_adf_boot_header,
    &sxrfs_adf_root_block,
    &sxrfs_adf_block_prefix,
    &sxrfs_adf_block_pointer,
    &sxrfs_adf_classic_entry_tail,
    &sxrfs_adf_bitmap_block,
    &sxrfs_hfs_master_directory,
    &sxrfs_hfs_btree_node,
    &sxrfs_hfs_btree_header,
    &sxrfs_hfs_node_record_offset,
    &sxrfs_hfs_catalog_key_prefix,
    &sxrfs_hfs_extents_key,
    &sxrfs_hfs_extent,
    &sxrfs_hfs_btree_child,
    &sxrfs_hfs_catalog_folder,
    &sxrfs_hfs_catalog_file,
    &sxrfs_hfs_catalog_thread,
    &sxrfs_atari_dos25_extended_vtoc,
    &sxrfs_apple_dos_bitmap16,
    &sxrfs_adfs_directory_tail,
};

typedef struct sxrfs_flag {uint64_t mask;const wchar_t*name;} sxrfs_flag;
static bool sxrfs_flags(xx_data_struct_record*r,uint64_t value,const sxrfs_flag*bits,size_t n){
 wchar_t out[1024];size_t used=0;uint64_t known=0;
 for(size_t i=0;i<n;i++){known|=bits[i].mask;if(!(value&bits[i].mask))continue;const wchar_t*p=bits[i].name;size_t z=xx_rt_wcslen(p);if(z+used+24>=SX_COUNT(out))return false;if(used)out[used++]=L'|';while(*p)out[used++]=*p++;}
 uint64_t unknown=value&~known;if(unknown){if(used)out[used++]=L'|';out[used++]=L'0';out[used++]=L'x';bool start=false;for(int shift=60;shift>=0;shift-=4){unsigned d=(unsigned)((unknown>>shift)&15);if(d||start||!shift){out[used++]=L"0123456789ABCDEF"[d];start=true;}}}
 if(!used)out[used++]=L'0';out[used]=0;return xx_data_struct_record_set_comment(r,out);
}

static bool sx_retrofs_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60650000U||id>=0x60660000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    if(id==0x6065002aU&&!xx_rt_wcscmp(r->name,L"file_type_flags")&&integer){static const sxrfs_flag bits[]={{64U,L"Locked"},{128U,L"Closed"}};return sxrfs_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60650005U&&!xx_rt_wcscmp(r->name,L"access")&&integer){static const sxrfs_flag bits[]={{1U,L"Read"},{2U,L"Write"},{4U,L"Invisible"},{32U,L"Backup"},{64U,L"Rename"},{128U,L"Destroy"}};return sxrfs_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x6065003fU&&!xx_rt_wcscmp(r->name,L"attributes")&&integer){static const sxrfs_flag bits[]={{128U,L"Hardware locked"},{256U,L"Unmounted cleanly"},{512U,L"Bad blocks spared"},{1024U,L"No cache required"},{32768U,L"Software locked"}};return sxrfs_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60650026U&&!xx_rt_wcscmp(r->name,L"attributes")&&integer){static const sxrfs_flag bits[]={{1U,L"Owner read"},{2U,L"Owner write"},{4U,L"Owner execute"},{8U,L"Public read"},{16U,L"Public write"},{32U,L"Public execute"},{64U,L"Shareable"},{128U,L"Directory"}};return sxrfs_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60650040U&&!xx_rt_wcscmp(r->name,L"kind")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Index node");
    case 1U:return xx_data_struct_record_set_comment(r,L"Header node");
    case 2U:return xx_data_struct_record_set_comment(r,L"Map node");
    default:break;}}
    if(id==0x60650047U&&!xx_rt_wcscmp(r->name,L"record_type")&&integer){switch(value){
    case 256U:return xx_data_struct_record_set_comment(r,L"Folder record");
    default:break;}}
    if(id==0x60650048U&&!xx_rt_wcscmp(r->name,L"record_type")&&integer){switch(value){
    case 512U:return xx_data_struct_record_set_comment(r,L"File record");
    default:break;}}
    if(id==0x60650049U&&!xx_rt_wcscmp(r->name,L"record_type")&&integer){switch(value){
    case 768U:return xx_data_struct_record_set_comment(r,L"Folder thread");
    case 1024U:return xx_data_struct_record_set_comment(r,L"File thread");
    default:break;}}
    switch(id){
    case 0x60650001U:
        if(!xx_rt_wcscmp(r->name,L"status_and_folder_ids"))s=L"Low byte status/folder ID; high byte parent folder in AO-DOS variant";
        else if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"512-byte logical block number";
        break;
    case 0x60650002U:
        if(!xx_rt_wcscmp(r->name,L"previous_block"))s=L"512-byte logical block number; zero terminates";
        else if(!xx_rt_wcscmp(r->name,L"next_block"))s=L"512-byte logical block number; zero terminates";
        break;
    case 0x60650003U:
        if(!xx_rt_wcscmp(r->name,L"modification_packed"))s=L"Packed ProDOS date/time; GS/OS extension";
        else if(!xx_rt_wcscmp(r->name,L"creation_packed"))s=L"Packed date/time words, not Unix seconds";
        else if(!xx_rt_wcscmp(r->name,L"bitmap_block"))s=L"512-byte logical block number";
        break;
    case 0x60650004U:
        if(!xx_rt_wcscmp(r->name,L"creation_packed"))s=L"Packed ProDOS date/time words";
        else if(!xx_rt_wcscmp(r->name,L"parent_block"))s=L"512-byte logical block number";
        else if(!xx_rt_wcscmp(r->name,L"parent_entry_number"))s=L"One-based directory slot index";
        break;
    case 0x60650005U:
        if(!xx_rt_wcscmp(r->name,L"key_block"))s=L"512-byte logical block number";
        else if(!xx_rt_wcscmp(r->name,L"creation_packed"))s=L"Packed ProDOS date/time words";
        else if(!xx_rt_wcscmp(r->name,L"version_and_case"))s=L"Version/minimum-version bytes or lowercase flag union";
        else if(!xx_rt_wcscmp(r->name,L"modification_packed"))s=L"Packed ProDOS date/time words";
        else if(!xx_rt_wcscmp(r->name,L"header_block"))s=L"512-byte logical directory header block";
        break;
    case 0x60650006U:
        if(!xx_rt_wcscmp(r->name,L"key_block"))s=L"512-byte logical block number";
        break;
    case 0x60650007U:
        if(!xx_rt_wcscmp(r->name,L"block_number_low_bytes"))s=L"Low bytes of 256 block numbers; high bytes are a separate plane";
        break;
    case 0x60650008U:
        if(!xx_rt_wcscmp(r->name,L"block_number_high_bytes"))s=L"High bytes of 256 block numbers; low bytes are a separate plane";
        break;
    case 0x60650009U:
        if(!xx_rt_wcscmp(r->name,L"directory_end_block"))s=L"Exclusive 512-byte logical block number";
        else if(!xx_rt_wcscmp(r->name,L"last_access_time"))s=L"UCSD Pascal access-time word";
        else if(!xx_rt_wcscmp(r->name,L"last_set_date"))s=L"Packed month/day/year date";
        break;
    case 0x6065000aU:
        if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"512-byte logical block number";
        else if(!xx_rt_wcscmp(r->name,L"end_block"))s=L"Exclusive 512-byte logical block number";
        else if(!xx_rt_wcscmp(r->name,L"modification_date"))s=L"Packed month/day/year date";
        break;
    case 0x6065000bU:
        if(!xx_rt_wcscmp(r->name,L"allocation_direction"))s=L"Signed track allocation direction";
        break;
    case 0x6065000cU:
        if(!xx_rt_wcscmp(r->name,L"free_sector_bits"))s=L"Track free-sector bitmap in DOS on-disk bit order";
        break;
    case 0x6065000eU:
        if(!xx_rt_wcscmp(r->name,L"ts_list_track"))s=L"0 deleted/unused; FF deleted in DOS3.3";
        else if(!xx_rt_wcscmp(r->name,L"high_bit_name"))s=L"Apple DOS characters with bit7 set";
        break;
    case 0x60650011U:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since 1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since 1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"directory_start_sector"))s=L"512-byte physical sector number";
        else if(!xx_rt_wcscmp(r->name,L"allocation_start_sector"))s=L"512-byte physical sector number";
        break;
    case 0x60650012U:
        if(!xx_rt_wcscmp(r->name,L"two_packed_12bit_links"))s=L"First chain link in high12 bits; second in low12 bits; 0 free,1 terminal";
        break;
    case 0x60650013U:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since 1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since 1904-01-01";
        break;
    case 0x60650014U:
        if(!xx_rt_wcscmp(r->name,L"free_start_sector_triplets"))s=L"82 little-endian 24-bit sector numbers";
        break;
    case 0x60650015U:
        if(!xx_rt_wcscmp(r->name,L"free_length_sector_triplets"))s=L"82 little-endian 24-bit sector counts";
        break;
    case 0x60650017U:
        if(!xx_rt_wcscmp(r->name,L"name_and_attributes"))s=L"Bit7 of name bytes encodes access attributes";
        else if(!xx_rt_wcscmp(r->name,L"load_address"))s=L"Load address or encoded timestamp/filetype union";
        else if(!xx_rt_wcscmp(r->name,L"execution_address"))s=L"Execution address or encoded timestamp union";
        else if(!xx_rt_wcscmp(r->name,L"first_sector"))s=L"256-byte logical sector number";
        break;
    case 0x60650019U:
        if(!xx_rt_wcscmp(r->name,L"directory_and_locked"))s=L"Low7 ASCII directory, bit7 locked";
        break;
    case 0x6065001aU:
        if(!xx_rt_wcscmp(r->name,L"file_entry_bytes"))s=L"Number of files multiplied by8";
        else if(!xx_rt_wcscmp(r->name,L"boot_and_sector_high"))s=L"Boot bits4..5; high2 total-sector bits0..1";
        else if(!xx_rt_wcscmp(r->name,L"total_sector_low"))s=L"Low byte of10-bit sector count";
        break;
    case 0x6065001bU:
        if(!xx_rt_wcscmp(r->name,L"load_address_low"))s=L"Low16 bits; high2 bits in packed_high";
        else if(!xx_rt_wcscmp(r->name,L"execution_address_low"))s=L"Low16 bits; high2 bits in packed_high";
        else if(!xx_rt_wcscmp(r->name,L"length_low"))s=L"Low16 bits of18-bit byte length";
        else if(!xx_rt_wcscmp(r->name,L"packed_high"))s=L"High2 bits: start0..1,load2..3,length4..5,execution6..7";
        else if(!xx_rt_wcscmp(r->name,L"start_sector_low"))s=L"Low8 bits of10-bit sector number";
        break;
    case 0x6065001cU:
        if(!xx_rt_wcscmp(r->name,L"paragraphs_low"))s=L"Low16 bits of data size in16-byte paragraphs";
        else if(!xx_rt_wcscmp(r->name,L"paragraphs_high"))s=L"High8 bits of24-bit paragraph count";
        break;
    case 0x6065001eU:
        if(!xx_rt_wcscmp(r->name,L"first_sector"))s=L"One-based sector number";
        break;
    case 0x6065001fU:
        if(!xx_rt_wcscmp(r->name,L"file_index_and_next_high"))s=L"High6 bits directory slot; low2 high sector bits";
        break;
    case 0x60650021U:
        if(!xx_rt_wcscmp(r->name,L"file_descriptor_sector"))s=L"256-byte logical sector number; zero terminates";
        break;
    case 0x60650022U:
        if(!xx_rt_wcscmp(r->name,L"last_sector_bytes"))s=L"0 means256; otherwise byte count";
        else if(!xx_rt_wcscmp(r->name,L"record_count"))s=L"Little endian even though other FDR words are big endian";
        break;
    case 0x60650023U:
        if(!xx_rt_wcscmp(r->name,L"packed_sector_and_end"))s=L"Two12-bit values: physical start sector and inclusive file-sector index";
        break;
    case 0x60650024U:
        if(!xx_rt_wcscmp(r->name,L"root_fd_sector"))s=L"256-byte logical sector number";
        else if(!xx_rt_wcscmp(r->name,L"creation_ymdhm"))s=L"Calendar bytes, year relative1900";
        else if(!xx_rt_wcscmp(r->name,L"volume_name"))s=L"Last character has bit7 set";
        break;
    case 0x60650025U:
        if(!xx_rt_wcscmp(r->name,L"segment_allocation_size"))s=L"Sector allocation increment";
        else if(!xx_rt_wcscmp(r->name,L"record_extension"))s=L"Path extension for record locking";
        else if(!xx_rt_wcscmp(r->name,L"directory_entry_offset"))s=L"Byte position relative to the current directory, not a memory pointer";
        break;
    case 0x60650026U:
        if(!xx_rt_wcscmp(r->name,L"modification_ymdhm"))s=L"Calendar bytes, year relative1900";
        else if(!xx_rt_wcscmp(r->name,L"creation_ymd"))s=L"Calendar bytes, year relative1900";
        break;
    case 0x60650027U:
        if(!xx_rt_wcscmp(r->name,L"first_sector"))s=L"256-byte logical sector number";
        break;
    case 0x60650028U:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Last character has bit7 set";
        else if(!xx_rt_wcscmp(r->name,L"file_descriptor_sector"))s=L"256-byte logical sector number";
        break;
    case 0x60650029U:
        if(!xx_rt_wcscmp(r->name,L"next_track"))s=L"0 marks terminal sector";
        else if(!xx_rt_wcscmp(r->name,L"next_sector_or_last_byte"))s=L"Sector number when next_track nonzero; terminal final-byte index otherwise";
        break;
    case 0x6065002aU:
        if(!xx_rt_wcscmp(r->name,L"file_type_flags"))s=L"Low3 type, bit6 locked, bit7 closed";
        break;
    case 0x6065002cU:
        if(!xx_rt_wcscmp(r->name,L"free_sector_bits"))s=L"Least significant bit selects first sector";
        break;
    case 0x6065002dU:
        if(!xx_rt_wcscmp(r->name,L"free_sector_bits"))s=L"Least significant bit selects first sector";
        break;
    case 0x6065002eU:
        if(!xx_rt_wcscmp(r->name,L"free_sector_bits"))s=L"Least significant bit selects first sector";
        break;
    case 0x6065002fU:
        if(!xx_rt_wcscmp(r->name,L"free_sector_bits"))s=L"Least significant bit selects first sector";
        break;
    case 0x60650035U:
        if(!xx_rt_wcscmp(r->name,L"end_track"))s=L"Exclusive track index";
        break;
    case 0x60650038U:
        if(!xx_rt_wcscmp(r->name,L"end_track"))s=L"Exclusive cylinder index";
        break;
    case 0x60650039U:
        if(!xx_rt_wcscmp(r->name,L"dos_flags"))s=L"Bit0 FFS, bit1 international, bit2 directory-cache/long-name variant";
        else if(!xx_rt_wcscmp(r->name,L"root_block"))s=L"512-byte logical block hint; native reader validates candidate root";
        break;
    case 0x6065003aU:
        if(!xx_rt_wcscmp(r->name,L"hash_block_numbers"))s=L"512-byte logical block numbers";
        else if(!xx_rt_wcscmp(r->name,L"bitmap_blocks"))s=L"512-byte logical block numbers";
        else if(!xx_rt_wcscmp(r->name,L"modification_days"))s=L"Days since1978-01-01; combine with minutes/ticks";
        else if(!xx_rt_wcscmp(r->name,L"modification_ticks"))s=L"50Hz ticks";
        else if(!xx_rt_wcscmp(r->name,L"volume_modification_ticks"))s=L"50Hz ticks";
        else if(!xx_rt_wcscmp(r->name,L"creation_ticks"))s=L"50Hz ticks";
        break;
    case 0x6065003bU:
        if(!xx_rt_wcscmp(r->name,L"data_size_or_table_size"))s=L"Variant-dependent word: byte count in OFS data, table size in headers";
        break;
    case 0x6065003cU:
        if(!xx_rt_wcscmp(r->name,L"block_number"))s=L"512-byte logical block number";
        break;
    case 0x6065003dU:
        if(!xx_rt_wcscmp(r->name,L"modification_days"))s=L"Days since1978-01-01";
        else if(!xx_rt_wcscmp(r->name,L"modification_ticks"))s=L"50Hz ticks";
        break;
    case 0x6065003eU:
        if(!xx_rt_wcscmp(r->name,L"free_block_bits"))s=L"Bit0 is first block in each32-bit group, starting volume block2";
        break;
    case 0x6065003fU:
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
    case 0x60650040U:
        if(!xx_rt_wcscmp(r->name,L"forward_link"))s=L"B-tree node number";
        else if(!xx_rt_wcscmp(r->name,L"backward_link"))s=L"B-tree node number";
        break;
    case 0x60650042U:
        if(!xx_rt_wcscmp(r->name,L"record_offset"))s=L"Byte offset from B-tree node start; stored in reverse order at node end";
        break;
    case 0x60650046U:
        if(!xx_rt_wcscmp(r->name,L"child_node"))s=L"B-tree node number";
        break;
    case 0x60650047U:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"backup_time"))s=L"Seconds since1904-01-01";
        break;
    case 0x60650048U:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"backup_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"data_initial_extents"))s=L"Three allocation block/count pairs";
        else if(!xx_rt_wcscmp(r->name,L"resource_initial_extents"))s=L"Three allocation block/count pairs";
        break;
    case 0x6065004bU:
        if(!xx_rt_wcscmp(r->name,L"free_sector_bits"))s=L"Basis108 80-track free-sector bitmap in on-disk bit order";
        break;
    case 0x6065004cU:
        if(!xx_rt_wcscmp(r->name,L"parent_sector"))s=L"256-byte logical sector number";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Every coordinate is relative to the borrowed volume base.  No native
 * subclass state, host mounts, or journal replay is required.  Display caps
 * retain validated earlier records; undecoded metadata and payload stay raw. */
#define SXRFS_LIMIT 24000U
static bool sxrfs_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxrfs_read(sx_context*c,uint64_t p,void*b,size_t n){return !xx_pd_is_stopped(c->pd)&&sxrfs_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint16_t sxrfs16(const uint8_t*b,unsigned o){return o==1?(uint16_t)((uint16_t)b[0]<<8|b[1]):(uint16_t)((uint16_t)b[1]<<8|b[0]);}
static uint32_t sxrfs32(const uint8_t*b,unsigned o){if(o==2)return (uint32_t)sxrfs16(b,0)<<16|sxrfs16(b+2,0);return o==1?(uint32_t)sxrfs16(b,1)<<16|sxrfs16(b+2,1):(uint32_t)sxrfs16(b+2,0)<<16|sxrfs16(b,0);}
static bool sxrfs_pow(uint64_t v){return v&&!(v&(v-1));}
static bool sxrfs_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 if(!n)return true;const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(n>1048576U||n>UINT64_MAX/z||!sxrfs_span(c,p,n*z)||xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXRFS_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&(uint64_t)(c->items[lo-1].offset-c->f->base_address)+(uint64_t)c->items[lo-1].total_size>p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}return true;
}
#define SXRFS_ADD(c,l,p) sxrfs_put(c,&sxrfs_##l,p,1)
#define SXRFS_TABLE(c,l,p,n) sxrfs_put(c,&sxrfs_##l,p,n)
#define SXRFS_ORDER(l,o) ((o)==1?&sxrfs_##l##_be:&sxrfs_##l##_le)
static uint32_t sxrfs24(const uint8_t*b,bool be){return be?((uint32_t)b[0]<<16|(uint32_t)b[1]<<8|b[2]):((uint32_t)b[2]<<16|(uint32_t)b[1]<<8|b[0]);}
/* Apple sector-order mapping. A record crossing a remapped sector boundary is
 * omitted unless its physical bytes really remain adjacent. */
static uint64_t sxrfs_apple_pos(uint64_t p,bool dos){static const uint8_t map[16]={0,14,13,12,11,10,9,8,7,6,5,4,3,2,1,15};return dos?(p/4096)*4096+(uint64_t)map[(p/256)%16]*256+p%256:p;}
static bool sxrfs_apple_read(sx_context*c,uint64_t p,void*out,size_t n,bool dos){uint8_t*b=out;while(n){size_t z=256-p%256;if(z>n)z=n;if(!sxrfs_read(c,sxrfs_apple_pos(p,dos),b,z))return false;p+=z;b+=z;n-=z;}return true;}
static bool sxrfs_apple_put(sx_context*c,const sx_layout*l,uint64_t p,bool dos){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t n=f->rel_offset+f->size,at=sxrfs_apple_pos(p,dos);for(uint64_t q=0;q<n;){uint64_t z=256-(p+q)%256;if(sxrfs_apple_pos(p+q,dos)!=at+q)return true;q+=z;}return sxrfs_put(c,l,at,1);}
static bool sxrfs_pascal(sx_context*c){uint8_t h[26];bool dos=false;if(!sxrfs_read(c,1024,h,26))return false;unsigned count=sxrfs16(h+16,0),blocks=sxrfs16(h+14,0);if(sxrfs16(h+2,0)!=6||h[6]==0||h[6]>7||count>77||blocks<6||blocks>(uint64_t)c->size/512){dos=true;if(c->size<143360||!sxrfs_apple_read(c,1024,h,26,true))return false;count=sxrfs16(h+16,0);blocks=sxrfs16(h+14,0);if(sxrfs16(h+2,0)!=6||h[6]==0||h[6]>7||count>77||blocks!=280)return false;}
 if(!sxrfs_apple_put(c,&sxrfs_pascal_volume_header,1024,dos))return false;for(unsigned i=0;i<count;i++)if(!sxrfs_apple_put(c,&sxrfs_pascal_file_entry,1024+(uint64_t)(i+1)*26,dos))return false;return true;}
static bool sxrfs_pd_header(const uint8_t*h){return !sxrfs16(h,0)&&(h[4]>>4)==15&&(h[4]&15)&&h[35]==39&&h[36]==13&&sxrfs16(h+41,0)>=5;}
static bool sxrfs_prodos(sx_context*c){uint8_t h[512];bool dos=false;if(!sxrfs_read(c,1024,h,512))return false;if(!sxrfs_pd_header(h)){dos=true;if(c->size<143360||!sxrfs_apple_read(c,1024,h,512,true)||!sxrfs_pd_header(h))return false;}
 uint32_t blocks=sxrfs16(h+41,0);uint8_t*seen=xx_rt_calloc(blocks,1);uint16_t*queue=xx_rt_calloc(blocks,sizeof(*queue));if(!seen||!queue){xx_rt_free(seen);xx_rt_free(queue);return false;}size_t n=1,i=0;queue[0]=2;seen[2]=1;bool ok=true;
 while(i<n&&c->count<SXRFS_LIMIT&&!xx_pd_is_stopped(c->pd)){uint32_t b=queue[i++];uint64_t p=(uint64_t)b*512;if(!sxrfs_apple_read(c,p,h,512,dos))break;if(!sxrfs_apple_put(c,&sxrfs_prodos_directory_links,p,dos)){ok=false;break;}unsigned next=sxrfs16(h+2,0);if(next>=3&&next<blocks&&!seen[next]){seen[next]=1;queue[n++]=(uint16_t)next;}
  for(unsigned j=0;j<13;j++){uint8_t*e=h+4+j*39;unsigned t=e[0]>>4;uint64_t at=p+4+j*39;const sx_layout*l=t==15?&sxrfs_prodos_volume_header:t==14?&sxrfs_prodos_subdirectory_header:t?&sxrfs_prodos_file_entry:NULL;if(!l)continue;if(!sxrfs_apple_put(c,l,at,dos)){ok=false;break;}unsigned key=sxrfs16(e+17,0);if(t==13&&key>=3&&key<blocks&&!seen[key]){seen[key]=1;queue[n++]=(uint16_t)key;}if((t==2||t==3)&&key<blocks&&key>=3){if(!sxrfs_apple_put(c,&sxrfs_prodos_index_low,(uint64_t)key*512,dos)||!sxrfs_apple_put(c,&sxrfs_prodos_index_high,(uint64_t)key*512+256,dos)){ok=false;break;}}if(t==5&&key>=3&&key<blocks){if(!sxrfs_apple_put(c,&sxrfs_prodos_fork_descriptor,(uint64_t)key*512,dos)||!sxrfs_apple_put(c,&sxrfs_prodos_fork_descriptor,(uint64_t)key*512+256,dos)){ok=false;break;}}}
 }xx_rt_free(seen);xx_rt_free(queue);return ok;}
static bool sxrfs_dos_catalog_contains(sx_context*c,const uint8_t*v,bool remap,uint64_t physical){uint8_t seen[1280]={0},h[3];unsigned t=v[1],s=v[2];for(unsigned i=0;i<1280&&t;i++){if(t>=v[52]||s>=16)break;unsigned ix=t*16+s;if(seen[ix])break;seen[ix]=1;uint64_t p=(uint64_t)ix*256;if(sxrfs_apple_pos(p,remap)==physical)return true;if(!sxrfs_apple_read(c,p,h,3,remap))break;t=h[1];s=h[2];}return false;}
static bool sxrfs_dos_authenticated_order(sx_context*c,const uint8_t*v,bool fallback){
 if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->free_archive_records_reading)return fallback;
 xx_archive_record_state*s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return fallback;const xx_archive_record*r=(c->f->get_current_archive_record)(c->f,s);if(r&&r->header_offset>=c->f->base_address&&r->header_size==35){uint64_t p=(uint64_t)(r->header_offset-c->f->base_address);p-=p%256;bool a=sxrfs_dos_catalog_contains(c,v,false,p),b=sxrfs_dos_catalog_contains(c,v,true,p);if(a!=b)fallback=b;}(c->f->free_archive_records_reading)(c->f,s);return fallback;
}
static bool sxrfs_apple_dos(sx_context*c){unsigned spt=c->f->file_type==XX_FILE_TYPE_APPLE_DOS32?13:c->f->file_type==XX_FILE_TYPE_APPLE_DOS33_32?32:16;uint64_t vp=(uint64_t)17*spt*256;uint8_t v[256],b[256];bool remap=false;if(!sxrfs_read(c,vp,v,256))return false;
 if(v[53]!=spt||v[52]<18||v[52]>80||sxrfs16(v+54,0)!=256||v[39]!=122){if(spt!=16||!sxrfs_apple_read(c,vp,v,256,true)||v[53]!=16||v[52]<18||v[52]>80||sxrfs16(v+54,0)!=256||v[39]!=122)return false;remap=true;}
 if(spt==16)remap=sxrfs_dos_authenticated_order(c,v,remap);unsigned tracks=v[52];if((uint64_t)tracks*spt*256>(uint64_t)c->size||!sxrfs_apple_put(c,&sxrfs_apple_dos_vtoc,vp,remap))return false;for(unsigned j=0;j<tracks;j++)if(!sxrfs_apple_put(c,tracks>50?&sxrfs_apple_dos_bitmap16:&sxrfs_apple_dos_bitmap,vp+56+j*(tracks>50?2:4),remap))return false;
 uint8_t seen[2560]={0};unsigned t=v[1],s=v[2];for(unsigned walk=0;walk<2560&&t&&c->count<SXRFS_LIMIT;walk++){if(t>=tracks||s>=spt)break;unsigned index=t*spt+s;if(seen[index])break;seen[index]=1;uint64_t p=(uint64_t)index*256;if(!sxrfs_apple_read(c,p,b,256,remap))break;if(!sxrfs_apple_put(c,&sxrfs_apple_dos_catalog_header,p,remap))return false;unsigned nextt=b[1],nexts=b[2];
  for(unsigned j=0;j<7;j++){uint8_t*e=b+11+j*35;if(!e[0]||e[0]==255)continue;if(!sxrfs_apple_put(c,&sxrfs_apple_dos_file_entry,p+11+j*35,remap))return false;unsigned ft=e[0],fs=e[1];for(unsigned k=0;k<2560&&ft;k++){if(ft>=tracks||fs>=spt)break;unsigned ix=ft*spt+fs;if(seen[ix])break;seen[ix]=1;uint64_t at=(uint64_t)ix*256;uint8_t ts[12];if(!sxrfs_apple_read(c,at,ts,12,remap))break;if(!sxrfs_apple_put(c,&sxrfs_apple_dos_ts_header,at,remap))return false;for(unsigned a=0;a<122;a++)if(!sxrfs_apple_put(c,&sxrfs_apple_dos_ts_pair,at+12+a*2,remap))return false;ft=ts[1];fs=ts[2];}}
  t=nextt;s=nexts;
 }return true;}
static bool sxrfs_mfs(sx_context*c){uint8_t h[64],b[512];if(!sxrfs_read(c,1024,h,64)||sxrfs16(h,1)!=0xd2d7||!SXRFS_ADD(c,mfs_master_directory,1024))return false;unsigned units=sxrfs16(h+18,1),start=sxrfs16(h+14,1),sectors=sxrfs16(h+16,1);if(units&&units<=640&&!SXRFS_TABLE(c,mfs_allocation_pair,1088,(units+1)/2))return false;if(!sectors||sectors>32768||!sxrfs_span(c,(uint64_t)start*512,(uint64_t)sectors*512))return true;
 for(unsigned i=0;i<sectors&&c->count<SXRFS_LIMIT;i++){uint64_t p=(uint64_t)(start+i)*512;if(!sxrfs_read(c,p,b,512))break;for(unsigned q=0;q+51<=512;){if(!(b[q]&0x80))break;unsigned len=b[q+50],z=(51+len+1)&~1U;if(!len||z>512-q)break;if(!SXRFS_ADD(c,mfs_file_entry,p+q))return false;q+=z;}}return true;}
static bool sxrfs_aodos(sx_context*c){uint8_t e[24];if(c->size<10752)return false;for(unsigned i=0;i<413&&c->count<SXRFS_LIMIT;i++){uint64_t p=320+(uint64_t)i*24;if(!sxrfs_read(c,p,e,24))break;bool empty=true;for(unsigned j=2;j<16;j++)if(e[j]&&e[j]!=0xf6)empty=false;if(empty)break;if(!SXRFS_ADD(c,aodos_directory_entry,p))return false;}return c->count!=0;}
static bool sxrfs_adfs(sx_context*c){uint8_t h[256];if(!sxrfs_read(c,0,h,256)||h[246])return false;unsigned n=sxrfs24(h+252,false);if(n!=640&&n!=1280&&n!=2560)return false;if(!sxrfs_span(c,0,(uint64_t)n*256)||!SXRFS_ADD(c,adfs_map0,0)||!SXRFS_ADD(c,adfs_map1,256)||!SXRFS_ADD(c,adfs_directory_start,512)||!SXRFS_ADD(c,adfs_directory_tail,512+1227))return false;
 /* Archive callbacks return authenticated physical entry coordinates for both
  * linear and interleaved L images. Each interleaved physical run is
  * 16 sectors (4 KiB); only entries crossing such a run remain raw. */
 if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return true;
 xx_archive_record_state*s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return true;bool ok=true;for(unsigned i=0;i<24000&&!xx_pd_is_stopped(c->pd);i++){const xx_archive_record*r=(c->f->get_current_archive_record)(c->f,s);if(!r)break;if(r->header_offset>=c->f->base_address&&r->header_size==26){uint64_t p=(uint64_t)(r->header_offset-c->f->base_address);if((n!=2560||p%4096+26<=4096)&&sxrfs_span(c,p,26)&&!SXRFS_ADD(c,adfs_directory_entry,p)){ok=false;break;}}if(!(c->f->archive_record_move_to_next)(c->f,s,c->pd))break;}(c->f->free_archive_records_reading)(c->f,s);return ok;}
static bool sxrfs_dfs(sx_context*c){uint8_t h[8];unsigned sides=1;if(sxrfs_read(c,256,h,8)){uint64_t sectors=((h[6]&3)<<8)|h[7],extent=c->f->format_size>0?(uint64_t)c->f->format_size:(uint64_t)c->size;if((sectors==400||sectors==800)&&extent==sectors*512)sides=2;}for(unsigned side=0;side<sides;side++){uint64_t base=side*2560;if(!sxrfs_read(c,base+256,h,8))break;unsigned n=h[5]/8,sectors=((h[6]&3)<<8)|h[7];if(h[5]%8||n>31||(sectors!=400&&sectors!=800)||!sxrfs_span(c,base+256,256))continue;if(!SXRFS_ADD(c,acorn_dfs_title,base)||!SXRFS_ADD(c,acorn_dfs_catalog_header,base+256)||!SXRFS_TABLE(c,acorn_dfs_name,base+8,n)||!SXRFS_TABLE(c,acorn_dfs_file_metadata,base+264,n))return false;}return c->count!=0;}
static uint64_t sxrfs_atari_pos(unsigned s,unsigned z){return 16+(s<=3?(uint64_t)(s-1)*128:384+(uint64_t)(s-4)*z);}
static bool sxrfs_atari(sx_context*c){uint8_t h[16],b[128];if(!sxrfs_read(c,0,h,16)||sxrfs16(h,0)!=0x296)return false;unsigned z=sxrfs16(h+4,0);uint64_t bytes=((uint64_t)sxrfs16(h+2,0)|((uint64_t)h[6]<<16))*16;if((z!=128&&z!=256)||!sxrfs_span(c,16,bytes)||!SXRFS_ADD(c,atari_atr_header,0)||!SXRFS_ADD(c,atari_dos2_vtoc,sxrfs_atari_pos(360,z)))return false;if(bytes==133120&&!SXRFS_ADD(c,atari_dos25_extended_vtoc,sxrfs_atari_pos(1024,z)))return false;
 for(unsigned d=361;d<=368;d++){uint64_t p=sxrfs_atari_pos(d,z);if(!sxrfs_read(c,p,b,128))break;for(unsigned j=0;j<8;j++){const uint8_t*e=b+j*16;if(!(e[0]&0x40)||e[0]&0x80)continue;if(!SXRFS_ADD(c,atari_dos2_directory_entry,p+j*16))return false;unsigned sector=sxrfs16(e+3,0),count=sxrfs16(e+1,0);for(unsigned k=0;k<count&&k<1040&&sector; k++){if(sector>1040)break;uint64_t at=sxrfs_atari_pos(sector,z)+(sector<=3?128:z)-3;uint8_t tail[3];if(!sxrfs_read(c,at,tail,3))break;if(!SXRFS_ADD(c,atari_dos2_sector_trailer,at))return false;sector=((tail[0]&3)<<8)|tail[1];}}}return true;}
static bool sxrfs_ti(sx_context*c){uint8_t b[256];if(!sxrfs_read(c,0,b,256)||xx_rt_memcmp(b+13,"DSK",3)||!SXRFS_ADD(c,ti99_vib,0)||!SXRFS_TABLE(c,ti99_directory_pointer,256,128)||!sxrfs_read(c,256,b,256))return false;unsigned sectors=(unsigned)((uint64_t)c->size/256);for(unsigned i=0;i<128&&c->count<SXRFS_LIMIT;i++){unsigned n=sxrfs16(b+i*2,1);if(!n)break;if(n<2||n>=sectors)continue;if(!SXRFS_ADD(c,ti99_file_descriptor,(uint64_t)n*256)||!SXRFS_TABLE(c,ti99_cluster,(uint64_t)n*256+28,76))return false;}return true;}
static unsigned sxrfs_cb_spt(xx_file_type_t type,unsigned track){if(type==XX_FILE_TYPE_CBM_D81)return 40;if(type==XX_FILE_TYPE_CBM_D90)return 192;if(type==XX_FILE_TYPE_CBM_D8X){track=(track-1)%77+1;return track<=39?29:track<=53?27:track<=64?25:23;}track=(track-1)%35+1;return track<=17?21:track<=24?(type==XX_FILE_TYPE_CBM_D67?20:19):track<=30?18:17;}
static uint64_t sxrfs_cb_pos(xx_file_type_t type,unsigned track,unsigned sector,unsigned heads){if(type==XX_FILE_TYPE_CBM_D90)return track<153&&sector<heads*32?((uint64_t)track*heads*32+sector)*256:UINT64_MAX;unsigned max=type==XX_FILE_TYPE_CBM_D81?80:type==XX_FILE_TYPE_CBM_D71?70:type==XX_FILE_TYPE_CBM_D8X?154:40;if(!track||track>max||sector>=sxrfs_cb_spt(type,track))return UINT64_MAX;uint64_t n=sector;for(unsigned i=1;i<track;i++)n+=sxrfs_cb_spt(type,i);return n*256;}
static bool sxrfs_cbm(sx_context*c){xx_file_type_t type=c->f->file_type;unsigned heads=c->f->format_size==5013504?4:6,track=18,sector=1;uint8_t h[256];uint64_t base=sxrfs_cb_pos(type,18,0,heads);
 if(type==XX_FILE_TYPE_CBM_D81){base=sxrfs_cb_pos(type,40,0,heads);if(!sxrfs_read(c,base,h,256)||h[2]!='D'||!SXRFS_ADD(c,cbm_d81_header,base))return false;track=h[0];sector=h[1];for(unsigned i=1;i<=2;i++)if(!SXRFS_ADD(c,cbm_d81_bam_header,base+i*256)||!SXRFS_TABLE(c,cbm_bam_entry5,base+i*256+16,40))return false;
 }else if(type==XX_FILE_TYPE_CBM_D8X){base=sxrfs_cb_pos(type,39,0,heads);if(!sxrfs_read(c,base,h,256)||h[2]!='C'||!SXRFS_ADD(c,cbm_d8x_header,base))return false;track=39;sector=1;unsigned bt=h[0],bs=h[1];for(unsigned j=0;j<4&&bt==38;j++){uint64_t at=sxrfs_cb_pos(type,bt,bs,heads);if(!sxrfs_read(c,at,h,256)||h[2]!='C'||h[5]<=h[4]||h[5]-h[4]>50)break;if(!SXRFS_ADD(c,cbm_d8x_bam_header,at)||!SXRFS_TABLE(c,cbm_bam_entry4,at+6,h[5]-h[4]))return false;bt=h[0];bs=h[1];}
 }else if(type==XX_FILE_TYPE_CBM_D90){if(!sxrfs_read(c,0,h,12)||h[4]!=76||h[5]!=10||h[6]!=76||h[7]!=20||!SXRFS_ADD(c,cbm_d90_config,0))return false;/* Geometry can be inferred from the authenticated physical header. */if(!sxrfs_read(c,sxrfs_cb_pos(type,76,20,heads),h,29)||h[27]!='3'||h[28]!='A'){heads=4;if(!sxrfs_read(c,sxrfs_cb_pos(type,76,20,4),h,29)||h[27]!='3'||h[28]!='A')return true;}base=sxrfs_cb_pos(type,76,20,heads);if(!SXRFS_ADD(c,cbm_d90_header,base))return false;track=76;sector=10;unsigned bt=1,bs=0;for(unsigned j=0;j<20&&bt!=255;j++){uint64_t p=sxrfs_cb_pos(type,bt,bs,heads);if(!sxrfs_read(c,p,h,256)||h[5]<=h[4]||(h[5]-h[4])*heads>48)break;if(!SXRFS_ADD(c,cbm_d90_bam_header,p)||!SXRFS_TABLE(c,cbm_bam_entry4,p+16,(h[5]-h[4])*heads))return false;bt=h[0];bs=h[1];}
 }else{if(!sxrfs_read(c,base,h,256)||h[0]!=18||h[1]!=1||!SXRFS_ADD(c,cbm_d64_bam_header,base)||!SXRFS_TABLE(c,cbm_bam_entry3,base+4,35)||!SXRFS_ADD(c,cbm_d64_disk_identity,base+144))return false;track=h[0];sector=h[1];if(type==XX_FILE_TYPE_CBM_D71){if(!SXRFS_TABLE(c,cbm_free_count,base+221,35)||!SXRFS_TABLE(c,cbm_bitmap3,sxrfs_cb_pos(type,53,0,heads),35))return false;}}
 uint64_t visited[4096];size_t seen=0;for(unsigned k=0;k<4096&&track&&c->count<SXRFS_LIMIT;k++){uint64_t p=sxrfs_cb_pos(type,track,sector,heads);bool repeat=false;for(size_t j=0;j<seen;j++)if(visited[j]==p)repeat=true;if(repeat||!sxrfs_read(c,p,h,256))break;visited[seen++]=p;if(!SXRFS_ADD(c,cbm_sector_link,p))return false;unsigned nextt=h[0],nexts=h[1];for(unsigned j=0;j<8;j++){uint8_t*e=h+2+j*32;if(!(e[0]&7))continue;if(!SXRFS_ADD(c,cbm_directory_entry,p+2+j*32))return false;unsigned ft=e[1],fs=e[2],blocks=sxrfs16(e+28,0);for(unsigned a=0;a<blocks&&a<32768&&ft&&c->count<SXRFS_LIMIT;a++){uint64_t at=sxrfs_cb_pos(type,ft,fs,heads);uint8_t link[2];if(!sxrfs_read(c,at,link,2))break;if(!SXRFS_ADD(c,cbm_sector_link,at))return false;ft=link[0];fs=link[1];}}track=nextt;sector=nexts;}return true;}
static bool sxrfs_adf_sum(const uint8_t*b){uint32_t sum=0;for(unsigned i=0;i<512;i+=4)sum+=sxrfs32(b+i,1);return sum==0;}
static bool sxrfs_adf(sx_context*c){uint8_t b[512],boot[4];if(!sxrfs_read(c,0,boot,4))return false;unsigned blocks=(unsigned)((uint64_t)c->size/512);if(blocks<4||blocks>0x2000000)return false;bool marked=!xx_rt_memcmp(boot,"DOS",3)&&boot[3]<=7;if(!marked&&(boot[0]||boot[1]||boot[2]||boot[3]||(blocks!=1760&&blocks!=3520)))return false;unsigned roots[3]={(blocks+1)/2,880,1760},root=0;for(unsigned i=0;i<3;i++){if(roots[i]>=blocks||!sxrfs_read(c,(uint64_t)roots[i]*512,b,512))continue;if(sxrfs32(b,1)==2&&!sxrfs32(b+4,1)&&sxrfs32(b+12,1)==72&&sxrfs32(b+508,1)==1&&sxrfs_adf_sum(b)){root=roots[i];break;}}if(!root)return false;if(marked&&!SXRFS_ADD(c,adf_boot_header,0))return false;if(!SXRFS_ADD(c,adf_root_block,(uint64_t)root*512))return false;
 for(unsigned i=0;i<25;i++){unsigned bm=sxrfs32(b+316+i*4,1);uint8_t bitmap[512];if(bm>=2&&bm<blocks&&sxrfs_read(c,(uint64_t)bm*512,bitmap,512)&&sxrfs_adf_sum(bitmap)&&!SXRFS_ADD(c,adf_bitmap_block,(uint64_t)bm*512))return false;}
 uint32_t*q=xx_rt_calloc(24000,sizeof(*q));uint8_t*seen=xx_rt_calloc((blocks+7)/8,1);if(!q||!seen){xx_rt_free(q);xx_rt_free(seen);return false;}size_t n=0,i=0;for(unsigned j=0;j<72;j++){unsigned v=sxrfs32(b+24+j*4,1);if(v>=2&&v<blocks&&n<24000&&!(seen[v/8]&(1U<<(v%8)))){seen[v/8]|=1U<<(v%8);q[n++]=v;}}bool ok=true;
 while(i<n&&c->count<SXRFS_LIMIT){unsigned block=q[i++];uint64_t p=(uint64_t)block*512;if(!sxrfs_read(c,p,b,512)||sxrfs32(b,1)!=2||!sxrfs_adf_sum(b))continue;int32_t type=(int32_t)sxrfs32(b+508,1);if(!SXRFS_ADD(c,adf_block_prefix,p)){ok=false;break;}if(boot[3]<6&&!SXRFS_ADD(c,adf_classic_entry_tail,p+312)){ok=false;break;}if(type==2||type==-3){if(!SXRFS_TABLE(c,adf_block_pointer,p+24,72)){ok=false;break;}}
  for(unsigned j=0;j<(type==2?73:1);j++){unsigned v=sxrfs32(b+(j==0?496:24+(j-1)*4),1);if(v>=2&&v<blocks&&n<24000&&!(seen[v/8]&(1U<<(v%8)))){seen[v/8]|=1U<<(v%8);q[n++]=v;}}
 }xx_rt_free(q);xx_rt_free(seen);return ok;}
static bool sxrfs_os9(sx_context*c){uint8_t h[256];if(!sxrfs_read(c,0,h,256))return false;uint32_t sectors=sxrfs24(h,true),root=sxrfs24(h+8,true),cluster=sxrfs16(h+6,1);if(sectors<8||sectors>(uint64_t)c->size/256||root>=sectors||!cluster||cluster>32||!sxrfs_pow(cluster)||!SXRFS_ADD(c,os9_disk_descriptor,0)||!SXRFS_ADD(c,os9_path_options,63))return false;
 uint32_t*q=xx_rt_calloc(4096,sizeof(*q));if(!q)return false;size_t n=1,i=0;q[0]=root;bool ok=true;while(i<n&&c->count<SXRFS_LIMIT){uint32_t fd=q[i++];uint64_t p=(uint64_t)fd*256;if(!sxrfs_read(c,p,h,256))continue;if(!SXRFS_ADD(c,os9_file_descriptor,p)||!SXRFS_TABLE(c,os9_segment,p+16,48)){ok=false;break;}if(!(h[0]&0x80))continue;uint64_t remain=sxrfs32(h+9,1);for(unsigned seg=0;seg<48&&remain&&ok;seg++){uint32_t start=sxrfs24(h+16+seg*5,true),count=sxrfs16(h+19+seg*5,1);if(!count||start>=sectors||count>sectors-start)break;uint64_t bytes=(uint64_t)count*256;if(bytes>remain)bytes=remain;remain-=bytes;if(bytes>16777216)break;for(uint64_t off=0;off+32<=bytes&&c->count<SXRFS_LIMIT;off+=32){uint8_t e[32];uint64_t at=(uint64_t)start*256+off;if(!sxrfs_read(c,at,e,32)){ok=false;break;}if(!e[0])continue;if(!SXRFS_ADD(c,os9_directory_entry,at)){ok=false;break;}uint32_t child=sxrfs24(e+29,true);bool found=false;for(size_t j=0;j<n;j++)if(q[j]==child)found=true;if(child>0&&child<sectors&&!found&&n<4096)q[n++]=child;}}}xx_rt_free(q);return ok;}
/* Only initial physical extents are mapped here. Overflow/reconstructed forks
 * remain raw, as do node records crossing a noncontiguous extent boundary. */
static bool sxrfs_hfs_pos(const uint8_t*extent,uint64_t base,uint64_t bs,uint64_t logical,uint64_t n,uint64_t*out){for(unsigned i=0;i<3;i++){uint64_t first=sxrfs16(extent+i*4,1),z=(uint64_t)sxrfs16(extent+i*4+2,1)*bs;if(logical>=z){logical-=z;continue;}if(n>z-logical)return false;*out=base+first*bs+logical;return true;}return false;}
static bool sxrfs_hfs_tree(sx_context*c,const uint8_t*extent,uint64_t base,uint64_t bs,uint64_t size,bool catalog){uint64_t p;uint8_t h[120];if(size<512||!sxrfs_hfs_pos(extent,base,bs,0,120,&p)||!sxrfs_read(c,p,h,120)||h[8]!=1)return true;unsigned node=sxrfs16(h+32,1);uint32_t total=sxrfs32(h+36,1);if(node<512||node>32768||!sxrfs_pow(node)||!total||total>size/node)return true;uint8_t*b=xx_rt_malloc(node);if(!b)return false;bool ok=true;uint8_t bitmap[256];if(!sxrfs_hfs_pos(extent,base,bs,248,256,&p)||!sxrfs_read(c,p,bitmap,256)){xx_rt_free(b);return true;}
 for(uint32_t i=0;i<total&&i<2048&&c->count<SXRFS_LIMIT;i++){if(!(bitmap[i/8]&(0x80U>>(i%8))))continue;if(!sxrfs_hfs_pos(extent,base,bs,(uint64_t)i*node,node,&p)||!sxrfs_read(c,p,b,node))continue;int kind=(int8_t)b[8];unsigned n=sxrfs16(b+10,1);if(n>(node-14)/2-1||(kind!=-1&&kind!=0&&kind!=1&&kind!=2))continue;if(!SXRFS_ADD(c,hfs_btree_node,p)||!SXRFS_TABLE(c,hfs_node_record_offset,p+node-(n+1)*2,n+1)){ok=false;break;}
  for(unsigned j=0;j<n&&ok;j++){unsigned a=sxrfs16(b+node-2*(j+1),1),z=sxrfs16(b+node-2*(j+2),1);if(a<14||z<a||z>node-(n+1)*2)continue;if(kind==1){if(j==0&&z-a>=106&&!SXRFS_ADD(c,hfs_btree_header,p+a))ok=false;continue;}if(kind==2||z-a<2)continue;unsigned key=b[a];unsigned data=a+((key+2)&~1U);if(data>z)continue;if(catalog){if(key<6||b[a+6]>31||b[a+6]>key-6)continue;if(!SXRFS_ADD(c,hfs_catalog_key_prefix,p+a)){ok=false;break;}}else{if(key!=7||!SXRFS_ADD(c,hfs_extents_key,p+a)){ok=false;break;}}
   if(kind==0){if(z-data>=4&&!SXRFS_ADD(c,hfs_btree_child,p+data))ok=false;}else if(!catalog){if(z-data>=12&&!SXRFS_TABLE(c,hfs_extent,p+data,3))ok=false;}else if(z-data>=2){int type=(int16_t)sxrfs16(b+data,1);const sx_layout*l=type==0x100?&sxrfs_hfs_catalog_folder:type==0x200?&sxrfs_hfs_catalog_file:(type==0x300||type==0x400)?&sxrfs_hfs_catalog_thread:NULL;if(l){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;if((uint64_t)(f->rel_offset+f->size)<=z-data&&!sxrfs_put(c,l,p+data,1))ok=false;}}
  }
 }xx_rt_free(b);return ok;}
static bool sxrfs_hfs(sx_context*c){uint8_t h[162];if(!sxrfs_read(c,1024,h,162)||sxrfs16(h,1)!=0x4244||!SXRFS_ADD(c,hfs_master_directory,1024))return false;uint64_t bs=sxrfs32(h+20,1),base=(uint64_t)sxrfs16(h+28,1)*512;if(bs<512||bs>16777216||bs%512||!sxrfs_span(c,base,(uint64_t)sxrfs16(h+18,1)*bs))return true;return sxrfs_hfs_tree(c,h+134,base,bs,sxrfs32(h+130,1),false)&&sxrfs_hfs_tree(c,h+150,base,bs,sxrfs32(h+146,1),true);}
static int sxrfs_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxrfs_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+z>end)end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxrfs_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_retrofs_supports(xx_file_type_t t){switch(t){
case XX_FILE_TYPE_AODOS:case XX_FILE_TYPE_ADF:case XX_FILE_TYPE_PRODOS:case XX_FILE_TYPE_APPLE_PASCAL:case XX_FILE_TYPE_MFS:case XX_FILE_TYPE_HFS:case XX_FILE_TYPE_ADFS:case XX_FILE_TYPE_ACORN_DFS:case XX_FILE_TYPE_ATARI_DOS2:case XX_FILE_TYPE_TI99_DSK:case XX_FILE_TYPE_OS9_RBF:case XX_FILE_TYPE_APPLE_DOS33:case XX_FILE_TYPE_APPLE_DOS32:case XX_FILE_TYPE_APPLE_DOS33_32:case XX_FILE_TYPE_CBM_D64:case XX_FILE_TYPE_CBM_D71:case XX_FILE_TYPE_CBM_D81:case XX_FILE_TYPE_CBM_D67:case XX_FILE_TYPE_CBM_D8X:case XX_FILE_TYPE_CBM_D90:return true;default:return false;}}
static bool sx_retrofs_build(sx_context*c){bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_AODOS:ok=sxrfs_aodos(c);break;
case XX_FILE_TYPE_ADF:ok=sxrfs_adf(c);break;
case XX_FILE_TYPE_PRODOS:ok=sxrfs_prodos(c);break;
case XX_FILE_TYPE_APPLE_PASCAL:ok=sxrfs_pascal(c);break;
case XX_FILE_TYPE_MFS:ok=sxrfs_mfs(c);break;
case XX_FILE_TYPE_HFS:ok=sxrfs_hfs(c);break;
case XX_FILE_TYPE_ADFS:ok=sxrfs_adfs(c);break;
case XX_FILE_TYPE_ACORN_DFS:ok=sxrfs_dfs(c);break;
case XX_FILE_TYPE_ATARI_DOS2:ok=sxrfs_atari(c);break;
case XX_FILE_TYPE_TI99_DSK:ok=sxrfs_ti(c);break;
case XX_FILE_TYPE_OS9_RBF:ok=sxrfs_os9(c);break;
case XX_FILE_TYPE_APPLE_DOS33:ok=sxrfs_apple_dos(c);break;
case XX_FILE_TYPE_APPLE_DOS32:ok=sxrfs_apple_dos(c);break;
case XX_FILE_TYPE_APPLE_DOS33_32:ok=sxrfs_apple_dos(c);break;
case XX_FILE_TYPE_CBM_D64:ok=sxrfs_cbm(c);break;
case XX_FILE_TYPE_CBM_D71:ok=sxrfs_cbm(c);break;
case XX_FILE_TYPE_CBM_D81:ok=sxrfs_cbm(c);break;
case XX_FILE_TYPE_CBM_D67:ok=sxrfs_cbm(c);break;
case XX_FILE_TYPE_CBM_D8X:ok=sxrfs_cbm(c);break;
case XX_FILE_TYPE_CBM_D90:ok=sxrfs_cbm(c);break;
default:return false;}return (ok||c->count)&&c->count&&!c->failed&&!xx_pd_is_stopped(c->pd)&&sxrfs_finish(c);}

#undef SXRFS_ADD
#undef SXRFS_TABLE
#undef SXRFS_ORDER
#undef SXRFS_LIMIT
