/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical filesystem metadata; see docs/data_struct_filesystems_scope.txt.
 * Encoded payloads and unwalked trees remain raw. */

static const xx_data_struct_field_desc sx_fs_fat_bpb_fields[] = {
    SX_FIELD("jump_boot","byte[3]",0,3,SX_NONE),
    SX_FIELD("oem_name","char[8]",3,8,SX_STRING),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sector_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",16,1,SX_COUNT_PROP),
    SX_FIELD("root_entry_count","uint16",17,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors_16","uint16",19,2,SX_COUNT_PROP),
    SX_FIELD("media_descriptor","uint8",21,1,SX_ID),
    SX_FIELD("sectors_per_fat_16","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sector_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("total_sectors_32","uint32",32,4,SX_COUNT_PROP),
};
static const sx_layout sx_fs_fat_bpb = {0x60100001U,"fat_bpb",sx_fs_fat_bpb_fields,SX_COUNT(sx_fs_fat_bpb_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_fat16_boot_sector_fields[] = {
    SX_FIELD("jump_boot","byte[3]",0,3,SX_NONE),
    SX_FIELD("oem_name","char[8]",3,8,SX_STRING),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sector_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",16,1,SX_COUNT_PROP),
    SX_FIELD("root_entry_count","uint16",17,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors_16","uint16",19,2,SX_COUNT_PROP),
    SX_FIELD("media_descriptor","uint8",21,1,SX_ID),
    SX_FIELD("sectors_per_fat_16","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sector_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("total_sectors_32","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("drive_number","uint8",36,1,SX_ID),
    SX_FIELD("state_flags","uint8",37,1,SX_FLAGS),
    SX_FIELD("extended_boot_signature","uint8",38,1,SX_SIGNATURE),
    SX_FIELD("volume_serial","uint32",39,4,SX_ID),
    SX_FIELD("volume_label","char[11]",43,11,SX_STRING),
    SX_FIELD("filesystem_type","char[8]",54,8,SX_STRING),
    SX_FIELD("boot_code","byte[448]",62,448,SX_NONE),
    SX_FIELD("boot_signature","uint16",510,2,SX_SIGNATURE),
};
static const sx_layout sx_fs_fat16_boot_sector = {0x60100002U,"fat16_boot_sector",sx_fs_fat16_boot_sector_fields,SX_COUNT(sx_fs_fat16_boot_sector_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_fat32_boot_sector_fields[] = {
    SX_FIELD("jump_boot","byte[3]",0,3,SX_NONE),
    SX_FIELD("oem_name","char[8]",3,8,SX_STRING),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sector_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",16,1,SX_COUNT_PROP),
    SX_FIELD("root_entry_count","uint16",17,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors_16","uint16",19,2,SX_COUNT_PROP),
    SX_FIELD("media_descriptor","uint8",21,1,SX_ID),
    SX_FIELD("sectors_per_fat_16","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sector_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("total_sectors_32","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_fat_32","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("extended_flags","uint16",40,2,SX_FLAGS),
    SX_FIELD("filesystem_version","uint16",42,2,SX_ID),
    SX_FIELD("root_cluster","uint32",44,4,SX_ID),
    SX_FIELD("fsinfo_sector","uint16",48,2,SX_OFFSET),
    SX_FIELD("backup_boot_sector","uint16",50,2,SX_OFFSET),
    SX_FIELD("reserved","byte[12]",52,12,SX_RESERVED),
    SX_FIELD("drive_number","uint8",64,1,SX_ID),
    SX_FIELD("state_flags","uint8",65,1,SX_FLAGS),
    SX_FIELD("extended_boot_signature","uint8",66,1,SX_SIGNATURE),
    SX_FIELD("volume_serial","uint32",67,4,SX_ID),
    SX_FIELD("volume_label","char[11]",71,11,SX_STRING),
    SX_FIELD("filesystem_type","char[8]",82,8,SX_STRING),
    SX_FIELD("boot_code","byte[420]",90,420,SX_NONE),
    SX_FIELD("boot_signature","uint16",510,2,SX_SIGNATURE),
};
static const sx_layout sx_fs_fat32_boot_sector = {0x60100003U,"fat32_boot_sector",sx_fs_fat32_boot_sector_fields,SX_COUNT(sx_fs_fat32_boot_sector_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_fat32_fsinfo_fields[] = {
    SX_FIELD("lead_signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("reserved1","byte[480]",4,480,SX_RESERVED),
    SX_FIELD("structure_signature","uint32",484,4,SX_SIGNATURE),
    SX_FIELD("free_cluster_count","uint32",488,4,SX_COUNT_PROP),
    SX_FIELD("next_free_cluster","uint32",492,4,SX_ID),
    SX_FIELD("reserved2","byte[12]",496,12,SX_RESERVED),
    SX_FIELD("trail_signature","uint32",508,4,SX_SIGNATURE),
};
static const sx_layout sx_fs_fat32_fsinfo = {0x60100004U,"fat32_fsinfo",sx_fs_fat32_fsinfo_fields,SX_COUNT(sx_fs_fat32_fsinfo_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_fat32_directory_entry_fields[] = {
    SX_FIELD("short_name","char[11]",0,11,SX_STRING),
    SX_FIELD("attributes","uint8",11,1,SX_FLAGS),
    SX_FIELD("case_flags","uint8",12,1,SX_FLAGS),
    SX_FIELD("creation_centiseconds","uint8",13,1,SX_NONE),
    SX_FIELD("creation_time","uint16",14,2,SX_NONE),
    SX_FIELD("creation_date","uint16",16,2,SX_NONE),
    SX_FIELD("access_date","uint16",18,2,SX_NONE),
    SX_FIELD("first_cluster_high","uint16",20,2,SX_ID),
    SX_FIELD("modification_time","uint16",22,2,SX_NONE),
    SX_FIELD("modification_date","uint16",24,2,SX_NONE),
    SX_FIELD("first_cluster_low","uint16",26,2,SX_ID),
    SX_FIELD("file_size","uint32",28,4,SX_SIZE),
};
static const sx_layout sx_fs_fat32_directory_entry = {0x60100005U,"fat32_directory_entry",sx_fs_fat32_directory_entry_fields,SX_COUNT(sx_fs_fat32_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_fat16_directory_entry_fields[] = {
    SX_FIELD("short_name","char[11]",0,11,SX_STRING),
    SX_FIELD("attributes","uint8",11,1,SX_FLAGS),
    SX_FIELD("case_flags","uint8",12,1,SX_FLAGS),
    SX_FIELD("creation_centiseconds","uint8",13,1,SX_NONE),
    SX_FIELD("creation_time","uint16",14,2,SX_NONE),
    SX_FIELD("creation_date","uint16",16,2,SX_NONE),
    SX_FIELD("access_date","uint16",18,2,SX_NONE),
    SX_FIELD("reserved_cluster_high","uint16",20,2,SX_RESERVED),
    SX_FIELD("modification_time","uint16",22,2,SX_NONE),
    SX_FIELD("modification_date","uint16",24,2,SX_NONE),
    SX_FIELD("first_cluster_low","uint16",26,2,SX_ID),
    SX_FIELD("file_size","uint32",28,4,SX_SIZE),
};
static const sx_layout sx_fs_fat16_directory_entry = {0x60100006U,"fat16_directory_entry",sx_fs_fat16_directory_entry_fields,SX_COUNT(sx_fs_fat16_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_fat_long_name_entry_fields[] = {
    SX_FIELD("sequence_flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("name_part1","uint16[5]",1,10,SX_STRING),
    SX_FIELD("attributes","uint8",11,1,SX_FLAGS),
    SX_FIELD("entry_type","uint8",12,1,SX_ID),
    SX_FIELD("short_name_checksum","uint8",13,1,SX_CHECKSUM),
    SX_FIELD("name_part2","uint16[6]",14,12,SX_STRING),
    SX_FIELD("reserved_cluster","uint16",26,2,SX_RESERVED),
    SX_FIELD("name_part3","uint16[2]",28,4,SX_STRING),
};
static const sx_layout sx_fs_fat_long_name_entry = {0x60100007U,"fat_long_name_entry",sx_fs_fat_long_name_entry_fields,SX_COUNT(sx_fs_fat_long_name_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_fat16_entry_fields[] = {
    SX_FIELD("cluster_link","uint16",0,2,SX_ID),
};
static const sx_layout sx_fs_fat16_entry = {0x60100008U,"fat16_entry",sx_fs_fat16_entry_fields,SX_COUNT(sx_fs_fat16_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_fat32_entry_fields[] = {
    SX_FIELD("cluster_link_flags","uint32",0,4,SX_FLAGS),
};
static const sx_layout sx_fs_fat32_entry = {0x60100009U,"fat32_entry",sx_fs_fat32_entry_fields,SX_COUNT(sx_fs_fat32_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_boot_signature_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
};
static const sx_layout sx_fs_boot_signature = {0x6010000aU,"boot_signature",sx_fs_boot_signature_fields,SX_COUNT(sx_fs_boot_signature_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_exfat_boot_sector_fields[] = {
    SX_FIELD("jump_boot","byte[3]",0,3,SX_NONE),
    SX_FIELD("filesystem_name","char[8]",3,8,SX_SIGNATURE),
    SX_FIELD("must_be_zero","byte[53]",11,53,SX_RESERVED),
    SX_FIELD("partition_sector_offset","uint64",64,8,SX_OFFSET),
    SX_FIELD("volume_sector_count","uint64",72,8,SX_COUNT_PROP),
    SX_FIELD("fat_sector_offset","uint32",80,4,SX_OFFSET),
    SX_FIELD("fat_sector_count","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("cluster_heap_sector_offset","uint32",88,4,SX_OFFSET),
    SX_FIELD("cluster_count","uint32",92,4,SX_COUNT_PROP),
    SX_FIELD("root_cluster","uint32",96,4,SX_ID),
    SX_FIELD("volume_serial","uint32",100,4,SX_ID),
    SX_FIELD("filesystem_revision","uint16",104,2,SX_ID),
    SX_FIELD("volume_flags","uint16",106,2,SX_FLAGS),
    SX_FIELD("bytes_per_sector_shift","uint8",108,1,SX_NONE),
    SX_FIELD("sectors_per_cluster_shift","uint8",109,1,SX_NONE),
    SX_FIELD("fat_count","uint8",110,1,SX_COUNT_PROP),
    SX_FIELD("drive_select","uint8",111,1,SX_ID),
    SX_FIELD("percent_in_use","uint8",112,1,SX_NONE),
    SX_FIELD("reserved","byte[7]",113,7,SX_RESERVED),
    SX_FIELD("boot_code","byte[390]",120,390,SX_NONE),
    SX_FIELD("boot_signature","uint16",510,2,SX_SIGNATURE),
};
static const sx_layout sx_fs_exfat_boot_sector = {0x6010000bU,"exfat_boot_sector",sx_fs_exfat_boot_sector_fields,SX_COUNT(sx_fs_exfat_boot_sector_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_exfat_extended_boot_signature_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
static const sx_layout sx_fs_exfat_extended_boot_signature = {0x6010000cU,"exfat_extended_boot_signature",sx_fs_exfat_extended_boot_signature_fields,SX_COUNT(sx_fs_exfat_extended_boot_signature_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_exfat_boot_checksum_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sx_fs_exfat_boot_checksum = {0x6010000dU,"exfat_boot_checksum",sx_fs_exfat_boot_checksum_fields,SX_COUNT(sx_fs_exfat_boot_checksum_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_exfat_bitmap_entry_fields[] = {
    SX_FIELD("entry_type","uint8",0,1,SX_ID),
    SX_FIELD("bitmap_flags","uint8",1,1,SX_FLAGS),
    SX_FIELD("reserved","byte[18]",2,18,SX_RESERVED),
    SX_FIELD("first_cluster","uint32",20,4,SX_ID),
    SX_FIELD("data_length","uint64",24,8,SX_SIZE),
};
static const sx_layout sx_fs_exfat_bitmap_entry = {0x6010000eU,"exfat_bitmap_entry",sx_fs_exfat_bitmap_entry_fields,SX_COUNT(sx_fs_exfat_bitmap_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_exfat_upcase_entry_fields[] = {
    SX_FIELD("entry_type","uint8",0,1,SX_ID),
    SX_FIELD("reserved1","byte[3]",1,3,SX_RESERVED),
    SX_FIELD("table_checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("reserved2","byte[12]",8,12,SX_RESERVED),
    SX_FIELD("first_cluster","uint32",20,4,SX_ID),
    SX_FIELD("data_length","uint64",24,8,SX_SIZE),
};
static const sx_layout sx_fs_exfat_upcase_entry = {0x6010000fU,"exfat_upcase_entry",sx_fs_exfat_upcase_entry_fields,SX_COUNT(sx_fs_exfat_upcase_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_exfat_volume_label_entry_fields[] = {
    SX_FIELD("entry_type","uint8",0,1,SX_ID),
    SX_FIELD("character_count","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("volume_label","uint16[11]",2,22,SX_STRING),
    SX_FIELD("reserved","byte[8]",24,8,SX_RESERVED),
};
static const sx_layout sx_fs_exfat_volume_label_entry = {0x60100010U,"exfat_volume_label_entry",sx_fs_exfat_volume_label_entry_fields,SX_COUNT(sx_fs_exfat_volume_label_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_exfat_file_entry_fields[] = {
    SX_FIELD("entry_type","uint8",0,1,SX_ID),
    SX_FIELD("secondary_count","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("set_checksum","uint16",2,2,SX_CHECKSUM),
    SX_FIELD("file_attributes","uint16",4,2,SX_FLAGS),
    SX_FIELD("reserved1","uint16",6,2,SX_RESERVED),
    SX_FIELD("creation_timestamp","uint32",8,4,SX_NONE),
    SX_FIELD("modification_timestamp","uint32",12,4,SX_NONE),
    SX_FIELD("access_timestamp","uint32",16,4,SX_NONE),
    SX_FIELD("creation_centiseconds","uint8",20,1,SX_NONE),
    SX_FIELD("modification_centiseconds","uint8",21,1,SX_NONE),
    SX_FIELD("creation_utc_offset","uint8",22,1,SX_NONE),
    SX_FIELD("modification_utc_offset","uint8",23,1,SX_NONE),
    SX_FIELD("access_utc_offset","uint8",24,1,SX_NONE),
    SX_FIELD("reserved2","byte[7]",25,7,SX_RESERVED),
};
static const sx_layout sx_fs_exfat_file_entry = {0x60100011U,"exfat_file_entry",sx_fs_exfat_file_entry_fields,SX_COUNT(sx_fs_exfat_file_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_exfat_stream_entry_fields[] = {
    SX_FIELD("entry_type","uint8",0,1,SX_ID),
    SX_FIELD("general_secondary_flags","uint8",1,1,SX_FLAGS),
    SX_FIELD("reserved1","uint8",2,1,SX_RESERVED),
    SX_FIELD("name_length","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("name_hash","uint16",4,2,SX_ID),
    SX_FIELD("reserved2","uint16",6,2,SX_RESERVED),
    SX_FIELD("valid_data_length","uint64",8,8,SX_SIZE),
    SX_FIELD("reserved3","uint32",16,4,SX_RESERVED),
    SX_FIELD("first_cluster","uint32",20,4,SX_ID),
    SX_FIELD("data_length","uint64",24,8,SX_SIZE),
};
static const sx_layout sx_fs_exfat_stream_entry = {0x60100012U,"exfat_stream_entry",sx_fs_exfat_stream_entry_fields,SX_COUNT(sx_fs_exfat_stream_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_exfat_name_entry_fields[] = {
    SX_FIELD("entry_type","uint8",0,1,SX_ID),
    SX_FIELD("general_secondary_flags","uint8",1,1,SX_FLAGS),
    SX_FIELD("filename","uint16[15]",2,30,SX_STRING),
};
static const sx_layout sx_fs_exfat_name_entry = {0x60100013U,"exfat_name_entry",sx_fs_exfat_name_entry_fields,SX_COUNT(sx_fs_exfat_name_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_exfat_fat_entry_fields[] = {
    SX_FIELD("cluster_link","uint32",0,4,SX_ID),
};
static const sx_layout sx_fs_exfat_fat_entry = {0x60100014U,"exfat_fat_entry",sx_fs_exfat_fat_entry_fields,SX_COUNT(sx_fs_exfat_fat_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_ntfs_boot_sector_fields[] = {
    SX_FIELD("jump_boot","byte[3]",0,3,SX_NONE),
    SX_FIELD("system_id","char[8]",3,8,SX_SIGNATURE),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("unused1","byte[7]",14,7,SX_RESERVED),
    SX_FIELD("media_type","uint8",21,1,SX_ID),
    SX_FIELD("unused2","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("sectors_per_track","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sector_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("unused3","byte[4]",32,4,SX_RESERVED),
    SX_FIELD("bios_drive_number","uint8",36,1,SX_ID),
    SX_FIELD("unused4","uint8",37,1,SX_RESERVED),
    SX_FIELD("extended_signature","uint8",38,1,SX_SIGNATURE),
    SX_FIELD("unused5","uint8",39,1,SX_RESERVED),
    SX_FIELD("sector_count","uint64",40,8,SX_COUNT_PROP),
    SX_FIELD("mft_cluster","uint64",48,8,SX_ID),
    SX_FIELD("mft_mirror_cluster","uint64",56,8,SX_ID),
    SX_FIELD("record_size_encoding","int8",64,1,SX_NONE),
    SX_FIELD("unused6","byte[3]",65,3,SX_RESERVED),
    SX_FIELD("index_size_encoding","int8",68,1,SX_NONE),
    SX_FIELD("unused7","byte[3]",69,3,SX_RESERVED),
    SX_FIELD("volume_serial","uint64",72,8,SX_ID),
    SX_FIELD("checksum","uint32",80,4,SX_CHECKSUM),
    SX_FIELD("boot_code","byte[426]",84,426,SX_NONE),
    SX_FIELD("boot_signature","uint16",510,2,SX_SIGNATURE),
};
static const sx_layout sx_fs_ntfs_boot_sector = {0x60100015U,"ntfs_boot_sector",sx_fs_ntfs_boot_sector_fields,SX_COUNT(sx_fs_ntfs_boot_sector_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_ntfs_file_record_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("update_sequence_offset","uint16",4,2,SX_OFFSET),
    SX_FIELD("update_sequence_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("log_sequence_number","uint64",8,8,SX_ID),
    SX_FIELD("sequence_number","uint16",16,2,SX_ID),
    SX_FIELD("hard_link_count","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("first_attribute_offset","uint16",20,2,SX_OFFSET),
    SX_FIELD("flags","uint16",22,2,SX_FLAGS),
    SX_FIELD("bytes_in_use","uint32",24,4,SX_SIZE),
    SX_FIELD("bytes_allocated","uint32",28,4,SX_SIZE),
    SX_FIELD("base_file_reference","uint64",32,8,SX_ID),
    SX_FIELD("next_attribute_id","uint16",40,2,SX_ID),
    SX_FIELD("reserved","uint16",42,2,SX_RESERVED),
    SX_FIELD("record_number","uint32",44,4,SX_ID),
};
static const sx_layout sx_fs_ntfs_file_record_header = {0x60100016U,"ntfs_file_record_header",sx_fs_ntfs_file_record_header_fields,SX_COUNT(sx_fs_ntfs_file_record_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_ntfs_update_sequence_fields[] = {
    SX_FIELD("sequence_value","uint16",0,2,SX_ID),
};
static const sx_layout sx_fs_ntfs_update_sequence = {0x60100017U,"ntfs_update_sequence",sx_fs_ntfs_update_sequence_fields,SX_COUNT(sx_fs_ntfs_update_sequence_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_ntfs_attribute_common_fields[] = {
    SX_FIELD("attribute_type","uint32",0,4,SX_ID),
    SX_FIELD("record_length","uint32",4,4,SX_SIZE),
    SX_FIELD("nonresident","uint8",8,1,SX_ID),
    SX_FIELD("name_length","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("name_offset","uint16",10,2,SX_OFFSET),
    SX_FIELD("flags","uint16",12,2,SX_FLAGS),
    SX_FIELD("attribute_id","uint16",14,2,SX_ID),
};
static const sx_layout sx_fs_ntfs_attribute_common = {0x60100018U,"ntfs_attribute_common",sx_fs_ntfs_attribute_common_fields,SX_COUNT(sx_fs_ntfs_attribute_common_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_ntfs_attribute_resident_fields[] = {
    SX_FIELD("value_length","uint32",0,4,SX_SIZE),
    SX_FIELD("value_offset","uint16",4,2,SX_OFFSET),
    SX_FIELD("resident_flags","uint8",6,1,SX_FLAGS),
    SX_FIELD("reserved","uint8",7,1,SX_RESERVED),
};
static const sx_layout sx_fs_ntfs_attribute_resident = {0x60100019U,"ntfs_attribute_resident",sx_fs_ntfs_attribute_resident_fields,SX_COUNT(sx_fs_ntfs_attribute_resident_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_ntfs_attribute_nonresident_fields[] = {
    SX_FIELD("lowest_vcn","uint64",0,8,SX_ID),
    SX_FIELD("highest_vcn","uint64",8,8,SX_ID),
    SX_FIELD("mapping_pairs_offset","uint16",16,2,SX_OFFSET),
    SX_FIELD("compression_unit_shift","uint8",18,1,SX_NONE),
    SX_FIELD("reserved","byte[5]",19,5,SX_RESERVED),
    SX_FIELD("allocated_length","uint64",24,8,SX_SIZE),
    SX_FIELD("file_length","uint64",32,8,SX_SIZE),
    SX_FIELD("valid_data_length","uint64",40,8,SX_SIZE),
};
static const sx_layout sx_fs_ntfs_attribute_nonresident = {0x6010001aU,"ntfs_attribute_nonresident",sx_fs_ntfs_attribute_nonresident_fields,SX_COUNT(sx_fs_ntfs_attribute_nonresident_fields),SX_LE};

static const xx_data_struct_field_desc sx_fs_ntfs_attribute_end_fields[] = {
    SX_FIELD("attribute_type","uint32",0,4,SX_ID),
};
static const sx_layout sx_fs_ntfs_attribute_end = {0x6010001bU,"ntfs_attribute_end",sx_fs_ntfs_attribute_end_fields,SX_COUNT(sx_fs_ntfs_attribute_end_fields),SX_LE};

static const sx_layout *const sx_filesystems_layouts[] = {
    &sx_fs_fat_bpb,
    &sx_fs_fat16_boot_sector,
    &sx_fs_fat32_boot_sector,
    &sx_fs_fat32_fsinfo,
    &sx_fs_fat32_directory_entry,
    &sx_fs_fat16_directory_entry,
    &sx_fs_fat_long_name_entry,
    &sx_fs_fat16_entry,
    &sx_fs_fat32_entry,
    &sx_fs_boot_signature,
    &sx_fs_exfat_boot_sector,
    &sx_fs_exfat_extended_boot_signature,
    &sx_fs_exfat_boot_checksum,
    &sx_fs_exfat_bitmap_entry,
    &sx_fs_exfat_upcase_entry,
    &sx_fs_exfat_volume_label_entry,
    &sx_fs_exfat_file_entry,
    &sx_fs_exfat_stream_entry,
    &sx_fs_exfat_name_entry,
    &sx_fs_exfat_fat_entry,
    &sx_fs_ntfs_boot_sector,
    &sx_fs_ntfs_file_record_header,
    &sx_fs_ntfs_update_sequence,
    &sx_fs_ntfs_attribute_common,
    &sx_fs_ntfs_attribute_resident,
    &sx_fs_ntfs_attribute_nonresident,
    &sx_fs_ntfs_attribute_end,
};

static bool sx_filesystems_supports(xx_file_type_t type)
{
    return type==XX_FILE_TYPE_FAT||type==XX_FILE_TYPE_EXFAT||type==XX_FILE_TYPE_NTFS;
}
static uint64_t sx_fs_limit(const sx_context *c)
{
    return c->f->format_size>0&&c->f->format_size<=c->size?(uint64_t)c->f->format_size:(uint64_t)c->size;
}
static bool sx_fs_fits(const sx_context *c,uint64_t o,uint64_t n)
{
    uint64_t size=sx_fs_limit(c);return o<=size&&n<=size-o;
}
static bool sx_fs_free(const sx_context *c,uint64_t o,uint64_t n)
{
    if(!sx_fs_fits(c,o,n)||c->count>=20000)return false;
    for(size_t i=0;i<c->count;i++) {
        uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;
        if(o<a+z&&a<o+n)return false;
    }
    return true;
}
/* A conflicting optional pointer is left raw. Required headers use sx_add. */
static bool sx_fs_emit(sx_context *c,const sx_layout *l,uint64_t o,uint64_t n,uint64_t count)
{
    if(!count)return true;
    if(!n||n>INT64_MAX/count)return false;
    return !sx_fs_free(c,o,n*count)||sx_table(c,l,(int64_t)o,(int64_t)n,count);
}
static void sx_fs_sort(sx_context *c)
{
    for(size_t gap=c->count/2;gap;gap/=2)for(size_t i=gap;i<c->count;i++) {
        xx_data_struct d=c->items[i];size_t j=i;
        while(j>=gap&&c->items[j-gap].offset>d.offset){c->items[j]=c->items[j-gap];j-=gap;}
        c->items[j]=d;
    }
}
static bool sx_fs_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;sx_fs_sort(c);
    for(size_t i=0;i<n;i++) {
        int64_t off=c->items[i].offset-c->f->base_address;
        if(off<end)return false;
        if(off>end&&!sx_raw(c,end,off-end))return false;
        end=off+c->items[i].total_size;
    }
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;
    sx_fs_sort(c);return !c->failed;
}
static bool sx_fs_fat_directory(sx_context *c,uint64_t off,uint64_t slots,bool fat32,bool *ended)
{
    if(slots>8192)slots=8192;
    for(uint64_t i=0;i<slots;i++) {
        uint8_t b[32];uint64_t at=off+i*32;
        /* Native FAT deliberately accepts cylinder-truncated disk copies. */
        if(!sx_fs_fits(c,at,32)){*ended=true;return true;}
        if(!sx_read(c,(int64_t)at,b,32))return false;
        if(!b[0]){*ended=true;break;}
        const sx_layout *l=b[11]==0x0f?&sx_fs_fat_long_name_entry:fat32?&sx_fs_fat32_directory_entry:&sx_fs_fat16_directory_entry;
        if(!sx_fs_emit(c,l,at,32,1))return false;
    }
    return true;
}
static bool sx_fs_fat(sx_context *c)
{
    uint8_t b[512];uint64_t total,fat,root_sectors,data_start,clusters,root,heap;
    if(!sx_read(c,0,b,sizeof(b)))return false;
    uint32_t sector=xx_data_get_u16(b,sizeof(b),11,false),spc=b[13],reserved=xx_data_get_u16(b,sizeof(b),14,false),fats=b[16],entries=xx_data_get_u16(b,sizeof(b),17,false);
    if((sector!=512&&sector!=1024&&sector!=2048&&sector!=4096)||!spc||(spc&(spc-1))||spc>128||!fats||fats>2)return false;
    /* Native foreign BPBs can encode zero reserved sectors, meaning one. */
    if(!reserved)reserved=1;
    total=xx_data_get_u16(b,sizeof(b),19,false);if(!total)total=xx_data_get_u32(b,sizeof(b),32,false);
    fat=xx_data_get_u16(b,sizeof(b),22,false);if(!fat)fat=xx_data_get_u32(b,sizeof(b),36,false);
    root_sectors=((uint64_t)entries*32+sector-1)/sector;data_start=reserved+fat*fats+root_sectors;
    if(!fat||total<=data_start)return false;
    clusters=(total-data_start)/spc;bool fat32=clusters>=65525;
    if(fat32) {
        if(!sx_add(c,&sx_fs_fat32_boot_sector,0,512))return false;
        uint32_t info=xx_data_get_u16(b,sizeof(b),48,false),backup=xx_data_get_u16(b,sizeof(b),50,false);
        if(info&&info<reserved&&sx_fs_fits(c,(uint64_t)info*sector,512)) {
            uint8_t h[512];if(!sx_read(c,(int64_t)info*sector,h,sizeof(h)))return false;
            if(xx_data_get_u32(h,512,0,false)==0x41615252&&xx_data_get_u32(h,512,484,false)==0x61417272&&xx_data_get_u32(h,512,508,false)==0xaa550000)
                if(!sx_fs_emit(c,&sx_fs_fat32_fsinfo,(uint64_t)info*sector,512,1))return false;
        }
        if(backup&&backup<reserved&&sx_fs_fits(c,(uint64_t)backup*sector,512)) {
            uint8_t h[512];if(!sx_read(c,(int64_t)backup*sector,h,sizeof(h)))return false;
            /* Only a matching BPB is a safely identified backup boot sector. */
            if(!xx_rt_memcmp(h+11,b+11,79)&&h[510]==0x55&&h[511]==0xaa)
                if(!sx_fs_emit(c,&sx_fs_fat32_boot_sector,(uint64_t)backup*sector,512,1))return false;
        }
    } else if(b[38]==0x29) {
        if(!sx_add(c,&sx_fs_fat16_boot_sector,0,512))return false;
    } else if(!sx_add(c,&sx_fs_fat_bpb,0,36)||!sx_add(c,&sx_fs_boot_signature,510,2))return false;
    if(clusters>=4085)for(uint32_t i=0;i<fats;i++) {
        uint64_t count=fat*sector/(fat32?4:2);if(count>8192)count=8192;
        if(!sx_fs_emit(c,fat32?&sx_fs_fat32_entry:&sx_fs_fat16_entry,(reserved+fat*i)*sector,fat32?4:2,count))return false;
    }
    root=(reserved+fat*fats)*sector;heap=data_start*sector;bool ended=false;
    if(!fat32)return sx_fs_fat_directory(c,root,entries,false,&ended);
    uint32_t flags=xx_data_get_u16(b,sizeof(b),40,false),active=(flags&0x80U)?flags&15U:0;
    if(active>=fats)return false;
    uint32_t cluster=xx_data_get_u32(b,sizeof(b),44,false)&0x0fffffff,visited[64];size_t seen=0;
    while(cluster>=2&&cluster<clusters+2&&seen<SX_COUNT(visited)&&!ended) {
        for(size_t i=0;i<seen;i++)if(visited[i]==cluster)return true;
        visited[seen++]=cluster;uint64_t at=heap+(uint64_t)(cluster-2)*sector*spc;
        if(!sx_fs_fat_directory(c,at,(uint64_t)sector*spc/32,true,&ended))return false;
        if(ended)break;
        uint32_t next;uint64_t link=((uint64_t)reserved+fat*active)*sector+(uint64_t)cluster*4;
        if(!sx_fs_fits(c,link,4)||!sx_u32(c,(int64_t)link,false,&next))return false;
        cluster=next&0x0fffffff;
    }
    return true;
}
static bool sx_fs_exfat_boot_valid(sx_context *c,uint64_t at,uint32_t sector,uint8_t *b)
{
    if(!sx_fs_fits(c,at,(uint64_t)sector*12)||!sx_read(c,(int64_t)at,b,512))return false;
    if(xx_rt_memcmp(b+3,"EXFAT   ",8)||b[108]<9||b[108]>12||(1U<<b[108])!=sector||b[109]>25-b[108]||b[510]!=0x55||b[511]!=0xaa)return false;
    uint32_t sum=0;uint8_t buffer[4096];
    for(uint32_t i=0;i<12;i++) {
        if(!sx_read(c,(int64_t)(at+(uint64_t)i*sector),buffer,sector))return false;
        if(i<11)for(uint32_t j=0;j<sector;j++) {
            if(i==0&&(j==106||j==107||j==112))continue;
            sum=((sum>>1)|(sum<<31))+buffer[j];
        }
        else for(uint32_t j=0;j<sector;j+=4)if(xx_data_get_u32(buffer,sector,j,false)!=sum)return false;
        if(i>=1&&i<=8&&xx_data_get_u32(buffer,sector,sector-4,false)!=0xaa550000)return false;
    }
    return true;
}
static bool sx_fs_exfat_directory(sx_context *c,uint64_t at,uint64_t slots,bool *ended)
{
    if(slots>8192)slots=8192;
    for(uint64_t j=0;j<slots;j++) {
        uint8_t type;if(!sx_fs_fits(c,at+j*32,32)||!sx_read(c,(int64_t)(at+j*32),&type,1))return false;
        if(!type){*ended=true;break;}
        const sx_layout *l=NULL;
        switch(type) {
        case 0x81:l=&sx_fs_exfat_bitmap_entry;break;case 0x82:l=&sx_fs_exfat_upcase_entry;break;
        case 0x83:l=&sx_fs_exfat_volume_label_entry;break;case 0x85:l=&sx_fs_exfat_file_entry;break;
        case 0xc0:l=&sx_fs_exfat_stream_entry;break;case 0xc1:l=&sx_fs_exfat_name_entry;break;default:break;
        }
        if(l&&!sx_fs_emit(c,l,at+j*32,32,1))return false;
    }
    return true;
}
static bool sx_fs_exfat(sx_context *c)
{
    uint8_t b[512],h[512];uint32_t sector=0;bool primary=false;
    for(uint32_t s=512;s<=4096;s*=2)if(sx_fs_exfat_boot_valid(c,0,s,b)){sector=s;primary=true;break;}
    if(!sector)for(uint32_t s=512;s<=4096;s*=2)if(sx_fs_exfat_boot_valid(c,(uint64_t)s*12,s,b)&&b[110]==1){sector=s;break;}
    if(!sector)return false;
    for(unsigned copy=0;copy<2;copy++) {
        uint64_t at=(uint64_t)copy*12*sector;
        if(!sx_fs_exfat_boot_valid(c,at,sector,h))continue;
        if(!sx_fs_emit(c,&sx_fs_exfat_boot_sector,at,512,1))return false;
        for(unsigned i=1;i<=8;i++)if(!sx_fs_emit(c,&sx_fs_exfat_extended_boot_signature,at+(uint64_t)(i+1)*sector-4,4,1))return false;
        if(!sx_fs_emit(c,&sx_fs_exfat_boot_checksum,at+(uint64_t)11*sector,4,sector/4))return false;
    }
    uint32_t fat=xx_data_get_u32(b,512,80,false),fatlen=xx_data_get_u32(b,512,84,false),heap=xx_data_get_u32(b,512,88,false),clusters=xx_data_get_u32(b,512,92,false),cluster=xx_data_get_u32(b,512,96,false);
    uint64_t cluster_bytes=(uint64_t)sector<<b[109];uint32_t active=primary?(xx_data_get_u16(b,512,106,false)&1):0;
    if(!fatlen||!clusters||b[110]<1||b[110]>2||active>=b[110])return false;
    for(unsigned i=0;i<b[110];i++) {
        uint64_t count=(uint64_t)fatlen*sector/4;if(count>8192)count=8192;
        if(!sx_fs_emit(c,&sx_fs_exfat_fat_entry,((uint64_t)fat+(uint64_t)fatlen*i)*sector,4,count))return false;
    }
    uint32_t visited[64];size_t seen=0;bool ended=false;
    while(cluster>=2&&cluster-2<clusters&&seen<SX_COUNT(visited)&&!ended) {
        for(size_t i=0;i<seen;i++)if(visited[i]==cluster)return true;
        visited[seen++]=cluster;uint64_t at=(uint64_t)heap*sector+(uint64_t)(cluster-2)*cluster_bytes;
        if(!sx_fs_exfat_directory(c,at,cluster_bytes/32,&ended))return false;
        if(ended)break;
        uint64_t link=((uint64_t)fat+(uint64_t)fatlen*active)*sector+(uint64_t)cluster*4;
        if(!sx_fs_fits(c,link,4)||!sx_u32(c,(int64_t)link,false,&cluster))return false;
    }
    return true;
}
/* USA protection replaces the last word of each sector. Never label a logical
 * field crossing that word as if its fixed-up value were physically present. */
static bool sx_fs_ntfs_unprotected(uint64_t o,uint64_t n,uint32_t sector)
{
    if(!n)return false;
    uint64_t tail=(o/sector+1)*sector-2;
    return o<tail&&n<=tail-o;
}
static bool sx_fs_ntfs_record(sx_context *c,uint64_t at,uint64_t bytes,uint32_t sector,bool prefix_only)
{
    uint8_t h[48];
    if(!sx_fs_fits(c,at,bytes)||!sx_read(c,(int64_t)at,h,sizeof(h))||xx_rt_memcmp(h,"FILE",4))return true;
    uint64_t used=xx_data_get_u32(h,48,24,false),off=xx_data_get_u16(h,48,20,false),usa=xx_data_get_u16(h,48,4,false),count=xx_data_get_u16(h,48,6,false);
    if(used>bytes||off<48||off>used||usa<48||usa>bytes||count>(bytes-usa)/2)return true;
    if(!sx_fs_emit(c,&sx_fs_ntfs_file_record_header,at,48,1))return false;
    /* The public entry offset identifies only the first mapped fragment. */
    if(prefix_only)return true;
    if(sx_fs_ntfs_unprotected(usa,count*2,sector)&&!sx_fs_emit(c,&sx_fs_ntfs_update_sequence,at+usa,2,count))return false;
    for(unsigned index=0;index<256&&off+4<=used;index++) {
        uint8_t a[24];uint32_t type;
        if(!sx_u32(c,(int64_t)(at+off),false,&type))return false;
        if(type==UINT32_MAX) {
            if(sx_fs_ntfs_unprotected(off,4,sector)&&!sx_fs_emit(c,&sx_fs_ntfs_attribute_end,at+off,4,1))return false;
            break;
        }
        if(off+24>used||!sx_fs_ntfs_unprotected(off,24,sector))break;
        if(!sx_read(c,(int64_t)(at+off),a,sizeof(a)))return false;
        uint32_t n=xx_data_get_u32(a,24,4,false);uint64_t head=a[8]?64:24;
        if(a[8]>1||n<head||n>used-off||(n&7))break;
        if(!sx_fs_emit(c,&sx_fs_ntfs_attribute_common,at+off,16,1))return false;
        if(sx_fs_ntfs_unprotected(off+16,head-16,sector))
            if(!sx_fs_emit(c,a[8]?&sx_fs_ntfs_attribute_nonresident:&sx_fs_ntfs_attribute_resident,at+off+16,head-16,1))return false;
        off+=n;
    }
    return true;
}
static bool sx_fs_ntfs(sx_context *c)
{
    uint8_t b[512];if(!sx_read(c,0,b,sizeof(b))||!sx_add(c,&sx_fs_ntfs_boot_sector,0,512))return false;
    uint32_t sector=xx_data_get_u16(b,512,11,false),spc=b[13];int encoded=(int)(int8_t)b[64];
    if((sector!=512&&sector!=1024&&sector!=2048&&sector!=4096)||!spc||spc>128)return false;
    uint64_t cluster=(uint64_t)sector*spc,record=0,mft=xx_data_get_u64(b,512,48,false),mirror=xx_data_get_u64(b,512,56,false);
    if(encoded<0&&encoded>=-16)record=UINT64_C(1)<<(unsigned)-encoded;
    else if(encoded>0)record=(uint64_t)encoded*cluster;
    if(record<sector||record>65536||record%sector)return false;
    if(mft<=sx_fs_limit(c)/cluster&&!sx_fs_ntfs_record(c,mft*cluster,record,sector,false))return false;
    if(mirror&&mirror<=sx_fs_limit(c)/cluster&&!sx_fs_ntfs_record(c,mirror*cluster,record,sector,false))return false;
    /* Native archive entries expose original physical MFT offsets. No file
     * contents are decoded here, and fragmented record bodies remain raw. */
    xx_archive_record_state *s=xx_format_create_archive_records_reading(c->f,NULL,c->pd);
    if(s) {
        unsigned n=0;
        do {
            const xx_archive_record *r=xx_format_get_current_archive_record(c->f,s);if(!r)break;
            if(r->header_offset>=c->f->base_address&&!sx_fs_ntfs_record(c,(uint64_t)(r->header_offset-c->f->base_address),record,sector,true)) {
                xx_format_free_archive_records_reading(c->f,s);return false;
            }
        }while(++n<4096&&xx_format_archive_record_move_to_next(c->f,s,c->pd));
        xx_format_free_archive_records_reading(c->f,s);
    }
    return !xx_pd_is_stopped(c->pd);
}
static bool sx_filesystems_build(sx_context *c)
{
    if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
    bool ok=false;
    switch(c->f->file_type) {
    case XX_FILE_TYPE_FAT:ok=sx_fs_fat(c);break;
    case XX_FILE_TYPE_EXFAT:ok=sx_fs_exfat(c);break;
    case XX_FILE_TYPE_NTFS:ok=sx_fs_ntfs(c);break;
    default:break;
    }
    return ok&&sx_fs_finish(c);
}
typedef struct sx_fs_flag {uint64_t mask;const wchar_t *name;} sx_fs_flag;
static bool sx_fs_flags(xx_data_struct_record *r,const sx_fs_flag *flags,size_t count)
{
    wchar_t out[256];size_t used=0;uint64_t value=xx_var_get_u64(&r->value),known=0;
    for(size_t i=0;i<count;i++) {
        known|=flags[i].mask;if(!(value&flags[i].mask))continue;
        if(used+32>=SX_COUNT(out))return false;
        if(used)out[used++]=L'|';
        const wchar_t *p=flags[i].name;while(*p&&used+24<SX_COUNT(out))out[used++]=*p++;
        if(*p)return false;
    }
    uint64_t unknown=value&~known;
    if(unknown) {
        if(used)out[used++]=L'|';out[used++]=L'0';out[used++]=L'x';
        bool started=false;
        for(int shift=60;shift>=0;shift-=4) {unsigned digit=(unsigned)((unknown>>shift)&15);if(digit||started||!shift){out[used++]=L"0123456789ABCDEF"[digit];started=true;}}
    }
    if(!used)out[used++]=L'0';out[used]=0;
    return xx_data_struct_record_set_comment(r,out);
}
static bool sx_filesystems_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60100000U||id>=0x60110000U)return true;
    const wchar_t *n=r->name,*text=NULL;
    if(!xx_rt_wcscmp(n,L"attributes")||!xx_rt_wcscmp(n,L"file_attributes")) {
        static const sx_fs_flag e[]={{1,L"READ_ONLY"},{2,L"HIDDEN"},{4,L"SYSTEM"},{16,L"DIRECTORY"},{32,L"ARCHIVE"}};
        if(id==sx_fs_exfat_file_entry.id)return sx_fs_flags(r,e,SX_COUNT(e));
        static const sx_fs_flag f[]={{1,L"READ_ONLY"},{2,L"HIDDEN"},{4,L"SYSTEM"},{8,L"VOLUME_LABEL"},{16,L"DIRECTORY"},{32,L"ARCHIVE"}};
        if(id==sx_fs_fat_long_name_entry.id&&xx_var_get_u64(&r->value)==15)return xx_data_struct_record_set_comment(r,L"ATTR_LONG_NAME");
        return sx_fs_flags(r,f,SX_COUNT(f));
    }
    if(!xx_rt_wcscmp(n,L"volume_flags")) {
        static const sx_fs_flag f[]={{1,L"ACTIVE_FAT"},{2,L"VOLUME_DIRTY"},{4,L"MEDIA_FAILURE"},{8,L"CLEAR_TO_ZERO"}};
        return sx_fs_flags(r,f,SX_COUNT(f));
    }
    if(!xx_rt_wcscmp(n,L"flags")&&id==sx_fs_ntfs_file_record_header.id) {
        static const sx_fs_flag f[]={{1,L"IN_USE"},{2,L"DIRECTORY"}};
        return sx_fs_flags(r,f,SX_COUNT(f));
    }
    if(!xx_rt_wcscmp(n,L"flags")&&id==sx_fs_ntfs_attribute_common.id) {
        static const sx_fs_flag f[]={{1,L"COMPRESSED"},{0x4000,L"ENCRYPTED"},{0x8000,L"SPARSE"}};
        return sx_fs_flags(r,f,SX_COUNT(f));
    }
    if(!xx_rt_wcscmp(n,L"fsinfo_sector")||!xx_rt_wcscmp(n,L"backup_boot_sector")||!xx_rt_wcscmp(n,L"partition_sector_offset")||!xx_rt_wcscmp(n,L"fat_sector_offset")||!xx_rt_wcscmp(n,L"cluster_heap_sector_offset"))text=L"Offset in logical sectors; multiply by the volume sector size for bytes";
    else if(!xx_rt_wcscmp(n,L"value_offset")||!xx_rt_wcscmp(n,L"mapping_pairs_offset")||!xx_rt_wcscmp(n,L"name_offset"))text=L"Byte offset relative to the start of the complete attribute";
    else if(!xx_rt_wcscmp(n,L"bytes_per_sector_shift"))text=L"Encoded exponent: sector bytes = 1 << value";
    else if(!xx_rt_wcscmp(n,L"sectors_per_cluster_shift"))text=L"Encoded exponent: sectors per cluster = 1 << value";
    else if(!xx_rt_wcscmp(n,L"record_size_encoding")||!xx_rt_wcscmp(n,L"index_size_encoding"))text=L"Positive: cluster count; negative: byte size = 1 << -value";
    else if(!xx_rt_wcscmp(n,L"creation_centiseconds")||!xx_rt_wcscmp(n,L"modification_centiseconds"))text=L"Encoded 10-millisecond increment in the range 0..199";
    else if(!xx_rt_wcscmp(n,L"creation_time")||!xx_rt_wcscmp(n,L"modification_time"))text=L"DOS packed time: hour[15:11], minute[10:5], seconds/2[4:0]";
    else if(!xx_rt_wcscmp(n,L"creation_date")||!xx_rt_wcscmp(n,L"modification_date")||!xx_rt_wcscmp(n,L"access_date"))text=L"DOS packed date: year since 1980[15:9], month[8:5], day[4:0]";
    else if(!xx_rt_wcscmp(n,L"creation_timestamp")||!xx_rt_wcscmp(n,L"modification_timestamp")||!xx_rt_wcscmp(n,L"access_timestamp"))text=L"Packed date in the high word and DOS time in the low word";
    else if(!xx_rt_wcscmp(n,L"creation_utc_offset")||!xx_rt_wcscmp(n,L"modification_utc_offset")||!xx_rt_wcscmp(n,L"access_utc_offset"))text=L"Bit 7 marks validity; signed 7-bit offset in 15-minute units";
    else if(!xx_rt_wcscmp(n,L"compression_unit_shift"))text=L"Compression-unit cluster count is 1 << value; zero means uncompressed";
    else if(!xx_rt_wcscmp(n,L"volume_flags"))text=L"ACTIVE_FAT=0x1, VOLUME_DIRTY=0x2, MEDIA_FAILURE=0x4, CLEAR_TO_ZERO=0x8";
    else if(!xx_rt_wcscmp(n,L"extended_flags"))text=L"Bit 7 disables FAT mirroring; low four bits select the active FAT";
    else if(!xx_rt_wcscmp(n,L"attributes")||!xx_rt_wcscmp(n,L"file_attributes"))text=L"READ_ONLY=0x01, HIDDEN=0x02, SYSTEM=0x04, VOLUME_LABEL=0x08, DIRECTORY=0x10, ARCHIVE=0x20";
    else if(!xx_rt_wcscmp(n,L"general_secondary_flags"))text=L"ALLOCATION_POSSIBLE=0x01, NO_FAT_CHAIN=0x02";
    else if(!xx_rt_wcscmp(n,L"sequence_flags"))text=L"Low five bits: long-name sequence; LAST_LONG_ENTRY=0x40";
    else if(!xx_rt_wcscmp(n,L"case_flags"))text=L"LOWERCASE_BASENAME=0x08, LOWERCASE_EXTENSION=0x10";
    else if(!xx_rt_wcscmp(n,L"state_flags"))text=L"DIRTY=0x01; other bits are implementation-specific";
    else if(!xx_rt_wcscmp(n,L"cluster_link_flags"))text=L"Low 28 bits are a cluster link; high four bits are reserved";
    else if(!xx_rt_wcscmp(n,L"free_cluster_count")||!xx_rt_wcscmp(n,L"next_free_cluster"))text=L"0xFFFFFFFF means unknown";
    else if(!xx_rt_wcscmp(n,L"percent_in_use"))text=L"Percentage 0..100; 0xFF means unknown";
    else if(!xx_rt_wcscmp(n,L"first_cluster")||!xx_rt_wcscmp(n,L"root_cluster")||!xx_rt_wcscmp(n,L"mft_cluster")||!xx_rt_wcscmp(n,L"mft_mirror_cluster"))text=L"Logical cluster number; not a byte offset";
    else if(!xx_rt_wcscmp(n,L"entry_type")) {
        switch(xx_var_get_u64(&r->value)) {
        case 0x81:text=L"ALLOCATION_BITMAP";break;case 0x82:text=L"UPCASE_TABLE";break;case 0x83:text=L"VOLUME_LABEL";break;
        case 0x85:text=L"FILE";break;case 0xc0:text=L"STREAM_EXTENSION";break;case 0xc1:text=L"FILE_NAME";break;default:break;
        }
    } else if(!xx_rt_wcscmp(n,L"attribute_type")) {
        switch(xx_var_get_u64(&r->value)) {
        case 0x10:text=L"$STANDARD_INFORMATION";break;case 0x20:text=L"$ATTRIBUTE_LIST";break;case 0x30:text=L"$FILE_NAME";break;case 0x40:text=L"$OBJECT_ID";break;
        case 0x50:text=L"$SECURITY_DESCRIPTOR";break;case 0x60:text=L"$VOLUME_NAME";break;case 0x70:text=L"$VOLUME_INFORMATION";break;case 0x80:text=L"$DATA";break;
        case 0x90:text=L"$INDEX_ROOT";break;case 0xa0:text=L"$INDEX_ALLOCATION";break;case 0xb0:text=L"$BITMAP";break;case 0xc0:text=L"$REPARSE_POINT";break;
        case 0xd0:text=L"$EA_INFORMATION";break;case 0xe0:text=L"$EA";break;case 0x100:text=L"$LOGGED_UTILITY_STREAM";break;case UINT32_MAX:text=L"ATTRIBUTE_END";break;default:break;
        }
    }
    return !text||xx_data_struct_record_set_comment(r,text);
}
