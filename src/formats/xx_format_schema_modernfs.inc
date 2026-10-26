/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical modern filesystem metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_modernfs_scope.txt. */

static const xx_data_struct_field_desc sxmf_refs_volume_header_fields[] = {
    SX_FIELD("jump","byte[3]",0,3,SX_NONE),
    SX_FIELD("signature","char[8]",3,8,SX_SIGNATURE),
    SX_FIELD("zero","byte[5]",11,5,SX_RESERVED),
    SX_FIELD("identifier","uint32",16,4,SX_SIGNATURE),
    SX_FIELD("header_length","uint16",20,2,SX_SIZE),
    SX_FIELD("checksum","uint16",22,2,SX_NONE),
    SX_FIELD("sector_count","uint64",24,8,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector","uint32",32,4,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("major_version","uint8",40,1,SX_ID),
    SX_FIELD("minor_version","uint8",41,1,SX_ID),
    SX_FIELD("unknown_flags","uint16",42,2,SX_NONE),
    SX_FIELD("unknown1","uint32",44,4,SX_NONE),
    SX_FIELD("unknown2","uint64",48,8,SX_NONE),
    SX_FIELD("volume_serial","uint64",56,8,SX_ID),
    SX_FIELD("container_size","uint64",64,8,SX_NONE),
    SX_FIELD("unknown3","byte[440]",72,440,SX_NONE),
};
static const sx_layout sxmf_refs_volume_header = {0x60420001U,"refs_volume_header",sxmf_refs_volume_header_fields,SX_COUNT(sxmf_refs_volume_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_fossil_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_ID),
    SX_FIELD("block_size","uint16",6,2,SX_SIZE),
    SX_FIELD("super_block","uint32",8,4,SX_NONE),
    SX_FIELD("label_block","uint32",12,4,SX_NONE),
    SX_FIELD("data_block","uint32",16,4,SX_NONE),
    SX_FIELD("end_block","uint32",20,4,SX_NONE),
};
static const sx_layout sxmf_fossil_header = {0x60420002U,"fossil_header",sxmf_fossil_header_fields,SX_COUNT(sxmf_fossil_header_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_fossil_superblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_ID),
    SX_FIELD("epoch_low","uint32",6,4,SX_NONE),
    SX_FIELD("epoch_high","uint32",10,4,SX_NONE),
    SX_FIELD("next_qid","uint64",14,8,SX_ID),
    SX_FIELD("active_root_block","int32",22,4,SX_NONE),
    SX_FIELD("next_archive_root_block","int32",26,4,SX_NONE),
    SX_FIELD("current_archive_root_block","int32",30,4,SX_NONE),
    SX_FIELD("last_archive_score","byte[20]",34,20,SX_SIGNATURE),
    SX_FIELD("name","char[128]",54,128,SX_STRING),
};
static const sx_layout sxmf_fossil_superblock = {0x60420003U,"fossil_superblock",sxmf_fossil_superblock_fields,SX_COUNT(sxmf_fossil_superblock_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_fossil_label_fields[] = {
    SX_FIELD("state","uint8",0,1,SX_FLAGS),
    SX_FIELD("type","uint8",1,1,SX_ID),
    SX_FIELD("epoch","uint32",2,4,SX_NONE),
    SX_FIELD("epoch_close","uint32",6,4,SX_NONE),
    SX_FIELD("tag","uint32",10,4,SX_ID),
};
static const sx_layout sxmf_fossil_label = {0x60420004U,"fossil_label",sxmf_fossil_label_fields,SX_COUNT(sxmf_fossil_label_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_jfs_superblock_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("volume_blocks","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("block_size","uint32",16,4,SX_SIZE),
    SX_FIELD("log2_block_size","uint16",20,2,SX_NONE),
    SX_FIELD("log2_block_factor","uint16",22,2,SX_NONE),
    SX_FIELD("physical_block_size","uint32",24,4,SX_SIZE),
    SX_FIELD("log2_physical_block_size","uint16",28,2,SX_NONE),
    SX_FIELD("padding","uint16",30,2,SX_RESERVED),
    SX_FIELD("allocation_group_blocks","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",36,4,SX_FLAGS),
    SX_FIELD("state","uint32",40,4,SX_FLAGS),
    SX_FIELD("compression","uint32",44,4,SX_ID),
    SX_FIELD("secondary_inode_table_blocks","uint24",48,3,SX_COUNT_PROP),
    SX_FIELD("secondary_inode_table_block_high","uint8",51,1,SX_NONE),
    SX_FIELD("secondary_inode_table_block_low","uint32",52,4,SX_NONE),
    SX_FIELD("secondary_inode_map_blocks","uint24",56,3,SX_COUNT_PROP),
    SX_FIELD("secondary_inode_map_block_high","uint8",59,1,SX_NONE),
    SX_FIELD("secondary_inode_map_block_low","uint32",60,4,SX_NONE),
    SX_FIELD("log_device","uint32",64,4,SX_ID),
    SX_FIELD("log_serial","uint32",68,4,SX_NONE),
    SX_FIELD("log_extent_blocks","uint24",72,3,SX_COUNT_PROP),
    SX_FIELD("log_extent_block_high","uint8",75,1,SX_NONE),
    SX_FIELD("log_extent_block_low","uint32",76,4,SX_NONE),
    SX_FIELD("fsck_extent_blocks","uint24",80,3,SX_COUNT_PROP),
    SX_FIELD("fsck_extent_block_high","uint8",83,1,SX_NONE),
    SX_FIELD("fsck_extent_block_low","uint32",84,4,SX_NONE),
    SX_FIELD("update_seconds","uint32",88,4,SX_TIME),
    SX_FIELD("update_nanoseconds","uint32",92,4,SX_NONE),
    SX_FIELD("fsck_log_blocks","uint32",96,4,SX_COUNT_PROP),
    SX_FIELD("fsck_log_index","int8",100,1,SX_NONE),
    SX_FIELD("pack_name","char[11]",101,11,SX_STRING),
    SX_FIELD("extension_blocks","uint64",112,8,SX_COUNT_PROP),
    SX_FIELD("extension_fsck_blocks","uint24",120,3,SX_COUNT_PROP),
    SX_FIELD("extension_fsck_block_high","uint8",123,1,SX_NONE),
    SX_FIELD("extension_fsck_block_low","uint32",124,4,SX_NONE),
    SX_FIELD("extension_log_blocks","uint24",128,3,SX_COUNT_PROP),
    SX_FIELD("extension_log_block_high","uint8",131,1,SX_NONE),
    SX_FIELD("extension_log_block_low","uint32",132,4,SX_NONE),
    SX_FIELD("uuid","byte[16]",136,16,SX_ID),
    SX_FIELD("label","char[16]",152,16,SX_STRING),
    SX_FIELD("log_uuid","byte[16]",168,16,SX_ID),
};
static const sx_layout sxmf_jfs_superblock = {0x60420005U,"jfs_superblock",sxmf_jfs_superblock_fields,SX_COUNT(sxmf_jfs_superblock_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_nilfs2_superblock_fields[] = {
    SX_FIELD("revision","uint32",0,4,SX_ID),
    SX_FIELD("minor_revision","uint16",4,2,SX_ID),
    SX_FIELD("magic","uint16",6,2,SX_SIGNATURE),
    SX_FIELD("checksum_bytes","uint16",8,2,SX_SIZE),
    SX_FIELD("flags","uint16",10,2,SX_FLAGS),
    SX_FIELD("crc_seed","uint32",12,4,SX_NONE),
    SX_FIELD("checksum","uint32",16,4,SX_CHECKSUM),
    SX_FIELD("log_block_size","uint32",20,4,SX_NONE),
    SX_FIELD("segment_count","uint64",24,8,SX_COUNT_PROP),
    SX_FIELD("device_size","uint64",32,8,SX_SIZE),
    SX_FIELD("first_data_block","uint64",40,8,SX_NONE),
    SX_FIELD("blocks_per_segment","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("reserved_segments_percent","uint32",52,4,SX_NONE),
    SX_FIELD("last_checkpoint_number","uint64",56,8,SX_NONE),
    SX_FIELD("last_partial_segment_block","uint64",64,8,SX_NONE),
    SX_FIELD("last_segment_sequence","uint64",72,8,SX_NONE),
    SX_FIELD("free_blocks","uint64",80,8,SX_COUNT_PROP),
    SX_FIELD("creation_time","uint64",88,8,SX_TIME),
    SX_FIELD("mount_time","uint64",96,8,SX_TIME),
    SX_FIELD("write_time","uint64",104,8,SX_TIME),
    SX_FIELD("mount_count","uint16",112,2,SX_COUNT_PROP),
    SX_FIELD("max_mount_count","uint16",114,2,SX_COUNT_PROP),
    SX_FIELD("state","uint16",116,2,SX_FLAGS),
    SX_FIELD("errors","uint16",118,2,SX_ID),
    SX_FIELD("last_check_time","uint64",120,8,SX_TIME),
    SX_FIELD("check_interval","uint32",128,4,SX_NONE),
    SX_FIELD("creator_os","uint32",132,4,SX_ID),
    SX_FIELD("reserved_uid","uint16",136,2,SX_ID),
    SX_FIELD("reserved_gid","uint16",138,2,SX_ID),
    SX_FIELD("first_inode","uint32",140,4,SX_ID),
    SX_FIELD("inode_size","uint16",144,2,SX_SIZE),
    SX_FIELD("dat_entry_size","uint16",146,2,SX_SIZE),
    SX_FIELD("checkpoint_size","uint16",148,2,SX_SIZE),
    SX_FIELD("segment_usage_size","uint16",150,2,SX_SIZE),
    SX_FIELD("uuid","byte[16]",152,16,SX_ID),
    SX_FIELD("volume_name","char[80]",168,80,SX_STRING),
    SX_FIELD("commit_interval","uint32",248,4,SX_NONE),
    SX_FIELD("commit_block_max","uint32",252,4,SX_COUNT_PROP),
    SX_FIELD("feature_compat","uint64",256,8,SX_FLAGS),
    SX_FIELD("feature_ro_compat","uint64",264,8,SX_FLAGS),
    SX_FIELD("feature_incompat","uint64",272,8,SX_FLAGS),
    SX_FIELD("reserved","byte[744]",280,744,SX_RESERVED),
};
static const sx_layout sxmf_nilfs2_superblock = {0x60420006U,"nilfs2_superblock",sxmf_nilfs2_superblock_fields,SX_COUNT(sxmf_nilfs2_superblock_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_nilfs2_inode_fields[] = {
    SX_FIELD("block_count","uint64",0,8,SX_COUNT_PROP),
    SX_FIELD("file_size","uint64",8,8,SX_SIZE),
    SX_FIELD("change_time","uint64",16,8,SX_TIME),
    SX_FIELD("modification_time","uint64",24,8,SX_TIME),
    SX_FIELD("change_nanoseconds","uint32",32,4,SX_NONE),
    SX_FIELD("modification_nanoseconds","uint32",36,4,SX_NONE),
    SX_FIELD("uid","uint32",40,4,SX_ID),
    SX_FIELD("gid","uint32",44,4,SX_ID),
    SX_FIELD("mode","uint16",48,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",50,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",52,4,SX_FLAGS),
    SX_FIELD("block_map","uint64[7]",56,56,SX_NONE),
    SX_FIELD("xattr","uint64",112,8,SX_NONE),
    SX_FIELD("generation","uint32",120,4,SX_NONE),
    SX_FIELD("padding","uint32",124,4,SX_RESERVED),
};
static const sx_layout sxmf_nilfs2_inode = {0x60420007U,"nilfs2_inode",sxmf_nilfs2_inode_fields,SX_COUNT(sxmf_nilfs2_inode_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_nilfs2_super_root_header_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("byte_count","uint16",4,2,SX_SIZE),
    SX_FIELD("flags","uint16",6,2,SX_FLAGS),
    SX_FIELD("non_gc_creation_time","uint64",8,8,SX_TIME),
};
static const sx_layout sxmf_nilfs2_super_root_header = {0x60420008U,"nilfs2_super_root_header",sxmf_nilfs2_super_root_header_fields,SX_COUNT(sxmf_nilfs2_super_root_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_nilfs2_segment_summary_fields[] = {
    SX_FIELD("data_checksum","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("summary_checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("magic","uint32",8,4,SX_SIGNATURE),
    SX_FIELD("summary_bytes","uint16",12,2,SX_SIZE),
    SX_FIELD("flags","uint16",14,2,SX_FLAGS),
    SX_FIELD("sequence","uint64",16,8,SX_NONE),
    SX_FIELD("creation_time","uint64",24,8,SX_TIME),
    SX_FIELD("next_segment_block","uint64",32,8,SX_NONE),
    SX_FIELD("block_count","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("file_info_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("summary_total_bytes","uint32",48,4,SX_SIZE),
    SX_FIELD("padding","uint32",52,4,SX_RESERVED),
    SX_FIELD("checkpoint_number","uint64",56,8,SX_NONE),
};
static const sx_layout sxmf_nilfs2_segment_summary = {0x60420009U,"nilfs2_segment_summary",sxmf_nilfs2_segment_summary_fields,SX_COUNT(sxmf_nilfs2_segment_summary_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_nilfs2_file_info_fields[] = {
    SX_FIELD("inode","uint64",0,8,SX_ID),
    SX_FIELD("checkpoint_number","uint64",8,8,SX_NONE),
    SX_FIELD("block_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("data_block_count","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxmf_nilfs2_file_info = {0x6042000aU,"nilfs2_file_info",sxmf_nilfs2_file_info_fields,SX_COUNT(sxmf_nilfs2_file_info_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_f2fs_superblock_prefix_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint16",4,2,SX_ID),
    SX_FIELD("minor_version","uint16",6,2,SX_ID),
    SX_FIELD("log2_sector_size","uint32",8,4,SX_NONE),
    SX_FIELD("log2_sectors_per_block","uint32",12,4,SX_NONE),
    SX_FIELD("log2_block_size","uint32",16,4,SX_NONE),
    SX_FIELD("log2_blocks_per_segment","uint32",20,4,SX_NONE),
    SX_FIELD("segments_per_section","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("sections_per_zone","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("checksum_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("block_count","uint64",36,8,SX_COUNT_PROP),
    SX_FIELD("section_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("segment_count","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("checkpoint_segments","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("sit_segments","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("nat_segments","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("ssa_segments","uint32",64,4,SX_COUNT_PROP),
    SX_FIELD("main_segments","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("segment0_block","uint32",72,4,SX_NONE),
    SX_FIELD("checkpoint_block","uint32",76,4,SX_NONE),
    SX_FIELD("sit_block","uint32",80,4,SX_NONE),
    SX_FIELD("nat_block","uint32",84,4,SX_NONE),
    SX_FIELD("ssa_block","uint32",88,4,SX_NONE),
    SX_FIELD("main_block","uint32",92,4,SX_NONE),
    SX_FIELD("root_inode","uint32",96,4,SX_ID),
    SX_FIELD("node_inode","uint32",100,4,SX_ID),
    SX_FIELD("meta_inode","uint32",104,4,SX_ID),
    SX_FIELD("uuid","byte[16]",108,16,SX_ID),
    SX_FIELD("volume_name","uint16[512]",124,1024,SX_NONE),
    SX_FIELD("extension_count","uint32",1148,4,SX_COUNT_PROP),
    SX_FIELD("extension_list","byte[512]",1152,512,SX_NONE),
    SX_FIELD("checkpoint_payload_blocks","uint32",1664,4,SX_COUNT_PROP),
    SX_FIELD("version","char[256]",1668,256,SX_STRING),
    SX_FIELD("initial_version","char[256]",1924,256,SX_STRING),
    SX_FIELD("features","uint32",2180,4,SX_FLAGS),
    SX_FIELD("encryption_level","uint8",2184,1,SX_ID),
    SX_FIELD("encryption_salt","byte[16]",2185,16,SX_NONE),
};
static const sx_layout sxmf_f2fs_superblock_prefix = {0x6042000bU,"f2fs_superblock_prefix",sxmf_f2fs_superblock_prefix_fields,SX_COUNT(sxmf_f2fs_superblock_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_f2fs_device_fields[] = {
    SX_FIELD("path","char[64]",0,64,SX_STRING),
    SX_FIELD("total_segments","uint32",64,4,SX_COUNT_PROP),
};
static const sx_layout sxmf_f2fs_device = {0x6042000cU,"f2fs_device",sxmf_f2fs_device_fields,SX_COUNT(sxmf_f2fs_device_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_f2fs_superblock_tail_fields[] = {
    SX_FIELD("quota_inodes","uint32[3]",0,12,SX_ID),
    SX_FIELD("hot_extension_count","uint8",12,1,SX_COUNT_PROP),
    SX_FIELD("encoding","uint16",13,2,SX_ID),
    SX_FIELD("encoding_flags","uint16",15,2,SX_FLAGS),
    SX_FIELD("checkpoint_stop_reasons","byte[32]",17,32,SX_FLAGS),
    SX_FIELD("errors","byte[16]",49,16,SX_FLAGS),
    SX_FIELD("reserved","byte[258]",65,258,SX_RESERVED),
    SX_FIELD("crc","uint32",323,4,SX_CHECKSUM),
};
static const sx_layout sxmf_f2fs_superblock_tail = {0x6042000dU,"f2fs_superblock_tail",sxmf_f2fs_superblock_tail_fields,SX_COUNT(sxmf_f2fs_superblock_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_f2fs_checkpoint_header_fields[] = {
    SX_FIELD("version","uint64",0,8,SX_NONE),
    SX_FIELD("user_blocks","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("valid_blocks","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("reserved_segments","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("overprovision_segments","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("free_segments","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("current_node_segments","uint32[8]",36,32,SX_NONE),
    SX_FIELD("current_node_block_offsets","uint16[8]",68,16,SX_NONE),
    SX_FIELD("current_data_segments","uint32[8]",84,32,SX_NONE),
    SX_FIELD("current_data_block_offsets","uint16[8]",116,16,SX_NONE),
    SX_FIELD("flags","uint32",132,4,SX_FLAGS),
    SX_FIELD("pack_total_blocks","uint32",136,4,SX_COUNT_PROP),
    SX_FIELD("pack_summary_start","uint32",140,4,SX_NONE),
    SX_FIELD("valid_nodes","uint32",144,4,SX_COUNT_PROP),
    SX_FIELD("valid_inodes","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("next_free_node","uint32",152,4,SX_ID),
    SX_FIELD("sit_bitmap_bytes","uint32",156,4,SX_SIZE),
    SX_FIELD("nat_bitmap_bytes","uint32",160,4,SX_SIZE),
    SX_FIELD("checksum_offset","uint32",164,4,SX_OFFSET),
    SX_FIELD("elapsed_time","uint64",168,8,SX_NONE),
    SX_FIELD("allocation_type","uint8[16]",176,16,SX_ID),
};
static const sx_layout sxmf_f2fs_checkpoint_header = {0x6042000eU,"f2fs_checkpoint_header",sxmf_f2fs_checkpoint_header_fields,SX_COUNT(sxmf_f2fs_checkpoint_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_f2fs_nat_entry_fields[] = {
    SX_FIELD("version","uint8",0,1,SX_NONE),
    SX_FIELD("inode","uint32",1,4,SX_ID),
    SX_FIELD("block","uint32",5,4,SX_NONE),
};
static const sx_layout sxmf_f2fs_nat_entry = {0x6042000fU,"f2fs_nat_entry",sxmf_f2fs_nat_entry_fields,SX_COUNT(sxmf_f2fs_nat_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_f2fs_node_footer_fields[] = {
    SX_FIELD("node_id","uint32",0,4,SX_ID),
    SX_FIELD("inode","uint32",4,4,SX_ID),
    SX_FIELD("flags","uint32",8,4,SX_FLAGS),
    SX_FIELD("checkpoint_version","uint64",12,8,SX_NONE),
    SX_FIELD("next_block","uint32",20,4,SX_NONE),
};
static const sx_layout sxmf_f2fs_node_footer = {0x60420010U,"f2fs_node_footer",sxmf_f2fs_node_footer_fields,SX_COUNT(sxmf_f2fs_node_footer_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_reiser35_superblock_fields[] = {
    SX_FIELD("block_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("free_blocks","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("root_block","uint32",8,4,SX_NONE),
    SX_FIELD("journal_first_block","uint32",12,4,SX_NONE),
    SX_FIELD("journal_device","uint32",16,4,SX_ID),
    SX_FIELD("journal_blocks","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("journal_transaction_max","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("journal_magic","uint32",28,4,SX_SIGNATURE),
    SX_FIELD("journal_max_batch","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("journal_max_commit_age","uint32",36,4,SX_NONE),
    SX_FIELD("journal_max_transaction_age","uint32",40,4,SX_NONE),
    SX_FIELD("block_size","uint16",44,2,SX_SIZE),
    SX_FIELD("objectid_max_count","uint16",46,2,SX_COUNT_PROP),
    SX_FIELD("objectid_count","uint16",48,2,SX_COUNT_PROP),
    SX_FIELD("unmount_state","uint16",50,2,SX_ID),
    SX_FIELD("magic","char[10]",52,10,SX_SIGNATURE),
    SX_FIELD("fs_state","uint16",62,2,SX_FLAGS),
    SX_FIELD("hash_function","uint32",64,4,SX_ID),
    SX_FIELD("tree_height","uint16",68,2,SX_COUNT_PROP),
    SX_FIELD("bitmap_block_count","uint16",70,2,SX_COUNT_PROP),
    SX_FIELD("version","uint16",72,2,SX_ID),
    SX_FIELD("reserved_journal_blocks","uint16",74,2,SX_COUNT_PROP),
};
static const sx_layout sxmf_reiser35_superblock = {0x60420011U,"reiser35_superblock",sxmf_reiser35_superblock_fields,SX_COUNT(sxmf_reiser35_superblock_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_reiser36_superblock_fields[] = {
    SX_FIELD("block_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("free_blocks","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("root_block","uint32",8,4,SX_NONE),
    SX_FIELD("journal_first_block","uint32",12,4,SX_NONE),
    SX_FIELD("journal_device","uint32",16,4,SX_ID),
    SX_FIELD("journal_blocks","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("journal_transaction_max","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("journal_magic","uint32",28,4,SX_SIGNATURE),
    SX_FIELD("journal_max_batch","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("journal_max_commit_age","uint32",36,4,SX_NONE),
    SX_FIELD("journal_max_transaction_age","uint32",40,4,SX_NONE),
    SX_FIELD("block_size","uint16",44,2,SX_SIZE),
    SX_FIELD("objectid_max_count","uint16",46,2,SX_COUNT_PROP),
    SX_FIELD("objectid_count","uint16",48,2,SX_COUNT_PROP),
    SX_FIELD("unmount_state","uint16",50,2,SX_ID),
    SX_FIELD("magic","char[10]",52,10,SX_SIGNATURE),
    SX_FIELD("fs_state","uint16",62,2,SX_FLAGS),
    SX_FIELD("hash_function","uint32",64,4,SX_ID),
    SX_FIELD("tree_height","uint16",68,2,SX_COUNT_PROP),
    SX_FIELD("bitmap_block_count","uint16",70,2,SX_COUNT_PROP),
    SX_FIELD("version","uint16",72,2,SX_ID),
    SX_FIELD("reserved_journal_blocks","uint16",74,2,SX_COUNT_PROP),
    SX_FIELD("inode_generation","uint32",76,4,SX_NONE),
    SX_FIELD("flags","uint32",80,4,SX_FLAGS),
    SX_FIELD("uuid","byte[16]",84,16,SX_ID),
    SX_FIELD("label","char[16]",100,16,SX_STRING),
    SX_FIELD("mount_count","uint16",116,2,SX_COUNT_PROP),
    SX_FIELD("max_mount_count","uint16",118,2,SX_COUNT_PROP),
    SX_FIELD("last_check","uint32",120,4,SX_TIME),
    SX_FIELD("check_interval","uint32",124,4,SX_NONE),
    SX_FIELD("reserved","byte[76]",128,76,SX_RESERVED),
};
static const sx_layout sxmf_reiser36_superblock = {0x60420012U,"reiser36_superblock",sxmf_reiser36_superblock_fields,SX_COUNT(sxmf_reiser36_superblock_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_reiser_block_header_fields[] = {
    SX_FIELD("level","uint16",0,2,SX_NONE),
    SX_FIELD("item_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("free_space","uint16",4,2,SX_SIZE),
    SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
    SX_FIELD("right_delimiting_key","byte[16]",8,16,SX_NONE),
};
static const sx_layout sxmf_reiser_block_header = {0x60420013U,"reiser_block_header",sxmf_reiser_block_header_fields,SX_COUNT(sxmf_reiser_block_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_reiser_item_header_fields[] = {
    SX_FIELD("key","byte[16]",0,16,SX_NONE),
    SX_FIELD("free_space_or_entry_count","uint16",16,2,SX_NONE),
    SX_FIELD("item_length","uint16",18,2,SX_SIZE),
    SX_FIELD("item_location","uint16",20,2,SX_OFFSET),
    SX_FIELD("version","uint16",22,2,SX_ID),
};
static const sx_layout sxmf_reiser_item_header = {0x60420014U,"reiser_item_header",sxmf_reiser_item_header_fields,SX_COUNT(sxmf_reiser_item_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_reiser_child_fields[] = {
    SX_FIELD("block","uint32",0,4,SX_NONE),
    SX_FIELD("used_bytes","uint16",4,2,SX_SIZE),
    SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
};
static const sx_layout sxmf_reiser_child = {0x60420015U,"reiser_child",sxmf_reiser_child_fields,SX_COUNT(sxmf_reiser_child_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_sfs_root_block_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("self_block","uint32",8,4,SX_NONE),
    SX_FIELD("version","uint16",12,2,SX_ID),
    SX_FIELD("sequence","uint16",14,2,SX_NONE),
    SX_FIELD("creation_time","uint32",16,4,SX_TIME),
    SX_FIELD("flags","uint8",20,1,SX_FLAGS),
    SX_FIELD("padding1","uint8",21,1,SX_RESERVED),
    SX_FIELD("padding2","uint16",22,2,SX_RESERVED),
    SX_FIELD("reserved1","uint32[2]",24,8,SX_RESERVED),
    SX_FIELD("first_byte","uint64",32,8,SX_OFFSET),
    SX_FIELD("last_byte","uint64",40,8,SX_OFFSET),
    SX_FIELD("total_blocks","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("block_size","uint32",52,4,SX_SIZE),
    SX_FIELD("reserved2","uint32[10]",56,40,SX_RESERVED),
    SX_FIELD("bitmap_block","uint32",96,4,SX_NONE),
    SX_FIELD("admin_space_block","uint32",100,4,SX_NONE),
    SX_FIELD("root_object_block","uint32",104,4,SX_NONE),
    SX_FIELD("extent_tree_block","uint32",108,4,SX_NONE),
    SX_FIELD("object_tree_block","uint32",112,4,SX_NONE),
    SX_FIELD("reserved3","uint32[3]",116,12,SX_RESERVED),
};
static const sx_layout sxmf_sfs_root_block = {0x60420016U,"sfs_root_block",sxmf_sfs_root_block_fields,SX_COUNT(sxmf_sfs_root_block_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_sfs_object_container_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("self_block","uint32",8,4,SX_NONE),
    SX_FIELD("parent_object","uint32",12,4,SX_ID),
    SX_FIELD("next_block","uint32",16,4,SX_NONE),
    SX_FIELD("previous_block","uint32",20,4,SX_NONE),
};
static const sx_layout sxmf_sfs_object_container = {0x60420017U,"sfs_object_container",sxmf_sfs_object_container_fields,SX_COUNT(sxmf_sfs_object_container_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_sfs_btree_header_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("self_block","uint32",8,4,SX_NONE),
    SX_FIELD("node_count","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("leaf","uint8",14,1,SX_ID),
    SX_FIELD("node_size","uint8",15,1,SX_SIZE),
};
static const sx_layout sxmf_sfs_btree_header = {0x60420018U,"sfs_btree_header",sxmf_sfs_btree_header_fields,SX_COUNT(sxmf_sfs_btree_header_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_sfs_extent16_fields[] = {
    SX_FIELD("block","uint32",0,4,SX_NONE),
    SX_FIELD("next_block","uint32",4,4,SX_NONE),
    SX_FIELD("previous_block_or_object","uint32",8,4,SX_NONE),
    SX_FIELD("block_count","uint16",12,2,SX_COUNT_PROP),
};
static const sx_layout sxmf_sfs_extent16 = {0x60420019U,"sfs_extent16",sxmf_sfs_extent16_fields,SX_COUNT(sxmf_sfs_extent16_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_sfs_extent32_fields[] = {
    SX_FIELD("block","uint32",0,4,SX_NONE),
    SX_FIELD("next_block","uint32",4,4,SX_NONE),
    SX_FIELD("previous_block_or_object","uint32",8,4,SX_NONE),
    SX_FIELD("block_count","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxmf_sfs_extent32 = {0x6042001aU,"sfs_extent32",sxmf_sfs_extent32_fields,SX_COUNT(sxmf_sfs_extent32_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_sfs_btree_index_fields[] = {
    SX_FIELD("key","uint32",0,4,SX_NONE),
    SX_FIELD("child_block","uint32",4,4,SX_NONE),
};
static const sx_layout sxmf_sfs_btree_index = {0x6042001bU,"sfs_btree_index",sxmf_sfs_btree_index_fields,SX_COUNT(sxmf_sfs_btree_index_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_opera_disc_label_fields[] = {
    SX_FIELD("record_type","uint8",0,1,SX_ID),
    SX_FIELD("sync","char[5]",1,5,SX_SIGNATURE),
    SX_FIELD("record_version","uint8",6,1,SX_ID),
    SX_FIELD("volume_flags","uint8",7,1,SX_FLAGS),
    SX_FIELD("comment","char[32]",8,32,SX_STRING),
    SX_FIELD("label","char[32]",40,32,SX_STRING),
    SX_FIELD("volume_id","uint32",72,4,SX_ID),
    SX_FIELD("block_size","uint32",76,4,SX_SIZE),
    SX_FIELD("block_count","uint32",80,4,SX_COUNT_PROP),
    SX_FIELD("root_id","uint32",84,4,SX_ID),
    SX_FIELD("root_blocks","uint32",88,4,SX_COUNT_PROP),
    SX_FIELD("root_block_size","uint32",92,4,SX_SIZE),
    SX_FIELD("last_root_avatar_index","uint32",96,4,SX_NONE),
    SX_FIELD("root_avatars","uint32[8]",100,32,SX_NONE),
};
static const sx_layout sxmf_opera_disc_label = {0x6042001cU,"opera_disc_label",sxmf_opera_disc_label_fields,SX_COUNT(sxmf_opera_disc_label_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_opera_directory_header_fields[] = {
    SX_FIELD("next_block","int32",0,4,SX_NONE),
    SX_FIELD("previous_block","int32",4,4,SX_NONE),
    SX_FIELD("flags","uint32",8,4,SX_FLAGS),
    SX_FIELD("first_free","uint32",12,4,SX_OFFSET),
    SX_FIELD("first_used","uint32",16,4,SX_OFFSET),
};
static const sx_layout sxmf_opera_directory_header = {0x6042001dU,"opera_directory_header",sxmf_opera_directory_header_fields,SX_COUNT(sxmf_opera_directory_header_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_opera_directory_record_fields[] = {
    SX_FIELD("flags","uint32",0,4,SX_FLAGS),
    SX_FIELD("id","uint32",4,4,SX_ID),
    SX_FIELD("type","char[4]",8,4,SX_ID),
    SX_FIELD("block_size","uint32",12,4,SX_SIZE),
    SX_FIELD("byte_count","uint32",16,4,SX_SIZE),
    SX_FIELD("block_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("burst_blocks","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("gap_blocks","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("name","char[32]",32,32,SX_STRING),
    SX_FIELD("last_avatar_index","uint32",64,4,SX_NONE),
};
static const sx_layout sxmf_opera_directory_record = {0x6042001eU,"opera_directory_record",sxmf_opera_directory_record_fields,SX_COUNT(sxmf_opera_directory_record_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_opera_avatar_fields[] = {
    SX_FIELD("block","uint32",0,4,SX_NONE),
};
static const sx_layout sxmf_opera_avatar = {0x6042001fU,"opera_avatar",sxmf_opera_avatar_fields,SX_COUNT(sxmf_opera_avatar_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_xfs4_superblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("block_size","uint32",4,4,SX_SIZE),
    SX_FIELD("data_blocks","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("realtime_blocks","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("realtime_extents","uint64",24,8,SX_COUNT_PROP),
    SX_FIELD("uuid","byte[16]",32,16,SX_ID),
    SX_FIELD("log_start_block","uint64",48,8,SX_NONE),
    SX_FIELD("root_inode","uint64",56,8,SX_ID),
    SX_FIELD("realtime_bitmap_inode","uint64",64,8,SX_ID),
    SX_FIELD("realtime_summary_inode","uint64",72,8,SX_ID),
    SX_FIELD("realtime_extent_blocks","uint32",80,4,SX_COUNT_PROP),
    SX_FIELD("allocation_group_blocks","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("allocation_group_count","uint32",88,4,SX_COUNT_PROP),
    SX_FIELD("realtime_bitmap_blocks","uint32",92,4,SX_COUNT_PROP),
    SX_FIELD("log_blocks","uint32",96,4,SX_COUNT_PROP),
    SX_FIELD("version_flags","uint16",100,2,SX_FLAGS),
    SX_FIELD("sector_size","uint16",102,2,SX_SIZE),
    SX_FIELD("inode_size","uint16",104,2,SX_SIZE),
    SX_FIELD("inodes_per_block","uint16",106,2,SX_COUNT_PROP),
    SX_FIELD("label","char[12]",108,12,SX_STRING),
    SX_FIELD("log2_block_size","uint8",120,1,SX_NONE),
    SX_FIELD("log2_sector_size","uint8",121,1,SX_NONE),
    SX_FIELD("log2_inode_size","uint8",122,1,SX_NONE),
    SX_FIELD("log2_inodes_per_block","uint8",123,1,SX_NONE),
    SX_FIELD("log2_ag_blocks","uint8",124,1,SX_NONE),
    SX_FIELD("log2_realtime_extents","uint8",125,1,SX_NONE),
    SX_FIELD("in_progress","uint8",126,1,SX_FLAGS),
    SX_FIELD("max_inode_percent","uint8",127,1,SX_NONE),
    SX_FIELD("inode_count","uint64",128,8,SX_COUNT_PROP),
    SX_FIELD("free_inodes","uint64",136,8,SX_COUNT_PROP),
    SX_FIELD("free_data_blocks","uint64",144,8,SX_COUNT_PROP),
    SX_FIELD("free_realtime_extents","uint64",152,8,SX_COUNT_PROP),
    SX_FIELD("user_quota_inode","uint64",160,8,SX_ID),
    SX_FIELD("group_quota_inode","uint64",168,8,SX_ID),
    SX_FIELD("quota_flags","uint16",176,2,SX_FLAGS),
    SX_FIELD("flags","uint8",178,1,SX_FLAGS),
    SX_FIELD("shared_version","uint8",179,1,SX_ID),
    SX_FIELD("inode_alignment_blocks","uint32",180,4,SX_COUNT_PROP),
    SX_FIELD("stripe_unit_blocks","uint32",184,4,SX_COUNT_PROP),
    SX_FIELD("stripe_width_blocks","uint32",188,4,SX_COUNT_PROP),
    SX_FIELD("log2_directory_blocks","uint8",192,1,SX_NONE),
    SX_FIELD("log2_log_sector_size","uint8",193,1,SX_NONE),
    SX_FIELD("log_sector_size","uint16",194,2,SX_SIZE),
    SX_FIELD("log_stripe_unit","uint32",196,4,SX_SIZE),
    SX_FIELD("features2","uint32",200,4,SX_FLAGS),
    SX_FIELD("bad_features2","uint32",204,4,SX_FLAGS),
};
static const sx_layout sxmf_xfs4_superblock = {0x60420020U,"xfs4_superblock",sxmf_xfs4_superblock_fields,SX_COUNT(sxmf_xfs4_superblock_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_xfs5_superblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("block_size","uint32",4,4,SX_SIZE),
    SX_FIELD("data_blocks","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("realtime_blocks","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("realtime_extents","uint64",24,8,SX_COUNT_PROP),
    SX_FIELD("uuid","byte[16]",32,16,SX_ID),
    SX_FIELD("log_start_block","uint64",48,8,SX_NONE),
    SX_FIELD("root_inode","uint64",56,8,SX_ID),
    SX_FIELD("realtime_bitmap_inode","uint64",64,8,SX_ID),
    SX_FIELD("realtime_summary_inode","uint64",72,8,SX_ID),
    SX_FIELD("realtime_extent_blocks","uint32",80,4,SX_COUNT_PROP),
    SX_FIELD("allocation_group_blocks","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("allocation_group_count","uint32",88,4,SX_COUNT_PROP),
    SX_FIELD("realtime_bitmap_blocks","uint32",92,4,SX_COUNT_PROP),
    SX_FIELD("log_blocks","uint32",96,4,SX_COUNT_PROP),
    SX_FIELD("version_flags","uint16",100,2,SX_FLAGS),
    SX_FIELD("sector_size","uint16",102,2,SX_SIZE),
    SX_FIELD("inode_size","uint16",104,2,SX_SIZE),
    SX_FIELD("inodes_per_block","uint16",106,2,SX_COUNT_PROP),
    SX_FIELD("label","char[12]",108,12,SX_STRING),
    SX_FIELD("log2_block_size","uint8",120,1,SX_NONE),
    SX_FIELD("log2_sector_size","uint8",121,1,SX_NONE),
    SX_FIELD("log2_inode_size","uint8",122,1,SX_NONE),
    SX_FIELD("log2_inodes_per_block","uint8",123,1,SX_NONE),
    SX_FIELD("log2_ag_blocks","uint8",124,1,SX_NONE),
    SX_FIELD("log2_realtime_extents","uint8",125,1,SX_NONE),
    SX_FIELD("in_progress","uint8",126,1,SX_FLAGS),
    SX_FIELD("max_inode_percent","uint8",127,1,SX_NONE),
    SX_FIELD("inode_count","uint64",128,8,SX_COUNT_PROP),
    SX_FIELD("free_inodes","uint64",136,8,SX_COUNT_PROP),
    SX_FIELD("free_data_blocks","uint64",144,8,SX_COUNT_PROP),
    SX_FIELD("free_realtime_extents","uint64",152,8,SX_COUNT_PROP),
    SX_FIELD("user_quota_inode","uint64",160,8,SX_ID),
    SX_FIELD("group_quota_inode","uint64",168,8,SX_ID),
    SX_FIELD("quota_flags","uint16",176,2,SX_FLAGS),
    SX_FIELD("flags","uint8",178,1,SX_FLAGS),
    SX_FIELD("shared_version","uint8",179,1,SX_ID),
    SX_FIELD("inode_alignment_blocks","uint32",180,4,SX_COUNT_PROP),
    SX_FIELD("stripe_unit_blocks","uint32",184,4,SX_COUNT_PROP),
    SX_FIELD("stripe_width_blocks","uint32",188,4,SX_COUNT_PROP),
    SX_FIELD("log2_directory_blocks","uint8",192,1,SX_NONE),
    SX_FIELD("log2_log_sector_size","uint8",193,1,SX_NONE),
    SX_FIELD("log_sector_size","uint16",194,2,SX_SIZE),
    SX_FIELD("log_stripe_unit","uint32",196,4,SX_SIZE),
    SX_FIELD("features2","uint32",200,4,SX_FLAGS),
    SX_FIELD("bad_features2","uint32",204,4,SX_FLAGS),
    SX_FIELD("features_compat","uint32",208,4,SX_FLAGS),
    SX_FIELD("features_ro_compat","uint32",212,4,SX_FLAGS),
    SX_FIELD("features_incompat","uint32",216,4,SX_FLAGS),
    SX_FIELD("features_log_incompat","uint32",220,4,SX_FLAGS),
    SX_FIELD("crc","uint32le",224,4,SX_CHECKSUM),
    SX_FIELD("sparse_inode_alignment_blocks","uint32",228,4,SX_COUNT_PROP),
    SX_FIELD("project_quota_inode","uint64",232,8,SX_ID),
    SX_FIELD("log_sequence","uint64",240,8,SX_NONE),
    SX_FIELD("metadata_uuid","byte[16]",248,16,SX_ID),
    SX_FIELD("metadata_directory_inode","uint64",264,8,SX_ID),
    SX_FIELD("realtime_group_count","uint32",272,4,SX_COUNT_PROP),
    SX_FIELD("realtime_group_extents","uint32",276,4,SX_COUNT_PROP),
    SX_FIELD("realtime_group_block_log","uint8",280,1,SX_NONE),
    SX_FIELD("padding","byte[7]",281,7,SX_RESERVED),
    SX_FIELD("internal_realtime_start_block","uint64",288,8,SX_NONE),
    SX_FIELD("reserved_realtime_blocks","uint64",296,8,SX_COUNT_PROP),
};
static const sx_layout sxmf_xfs5_superblock = {0x60420021U,"xfs5_superblock",sxmf_xfs5_superblock_fields,SX_COUNT(sxmf_xfs5_superblock_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_xfs4_agf_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("sequence","uint32",8,4,SX_NONE),
    SX_FIELD("group_blocks","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("block_tree_root","uint32",16,4,SX_NONE),
    SX_FIELD("count_tree_root","uint32",20,4,SX_NONE),
    SX_FIELD("reverse_map_root","uint32",24,4,SX_NONE),
    SX_FIELD("block_tree_levels","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("count_tree_levels","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("reverse_map_levels","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("free_list_first","uint32",40,4,SX_NONE),
    SX_FIELD("free_list_last","uint32",44,4,SX_NONE),
    SX_FIELD("free_list_count","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("free_blocks","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("longest_free_blocks","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("tree_blocks","uint32",60,4,SX_COUNT_PROP),
};
static const sx_layout sxmf_xfs4_agf = {0x60420022U,"xfs4_agf",sxmf_xfs4_agf_fields,SX_COUNT(sxmf_xfs4_agf_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_xfs5_agf_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("sequence","uint32",8,4,SX_NONE),
    SX_FIELD("group_blocks","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("block_tree_root","uint32",16,4,SX_NONE),
    SX_FIELD("count_tree_root","uint32",20,4,SX_NONE),
    SX_FIELD("reverse_map_root","uint32",24,4,SX_NONE),
    SX_FIELD("block_tree_levels","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("count_tree_levels","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("reverse_map_levels","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("free_list_first","uint32",40,4,SX_NONE),
    SX_FIELD("free_list_last","uint32",44,4,SX_NONE),
    SX_FIELD("free_list_count","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("free_blocks","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("longest_free_blocks","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("tree_blocks","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("uuid","byte[16]",64,16,SX_ID),
    SX_FIELD("reverse_map_blocks","uint32",80,4,SX_COUNT_PROP),
    SX_FIELD("refcount_blocks","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("refcount_root","uint32",88,4,SX_NONE),
    SX_FIELD("refcount_levels","uint32",92,4,SX_COUNT_PROP),
    SX_FIELD("spare","uint64[14]",96,112,SX_RESERVED),
    SX_FIELD("log_sequence","uint64",208,8,SX_NONE),
    SX_FIELD("crc","uint32le",216,4,SX_CHECKSUM),
    SX_FIELD("padding","uint32",220,4,SX_RESERVED),
};
static const sx_layout sxmf_xfs5_agf = {0x60420023U,"xfs5_agf",sxmf_xfs5_agf_fields,SX_COUNT(sxmf_xfs5_agf_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_xfs4_agi_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("sequence","uint32",8,4,SX_NONE),
    SX_FIELD("group_blocks","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("inode_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("inode_tree_root","uint32",20,4,SX_NONE),
    SX_FIELD("inode_tree_levels","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("free_inodes","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("new_inode","uint32",32,4,SX_ID),
    SX_FIELD("last_directory_inode","uint32",36,4,SX_ID),
    SX_FIELD("unlinked_inode_buckets","uint32[64]",40,256,SX_ID),
};
static const sx_layout sxmf_xfs4_agi = {0x60420024U,"xfs4_agi",sxmf_xfs4_agi_fields,SX_COUNT(sxmf_xfs4_agi_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_xfs5_agi_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("sequence","uint32",8,4,SX_NONE),
    SX_FIELD("group_blocks","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("inode_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("inode_tree_root","uint32",20,4,SX_NONE),
    SX_FIELD("inode_tree_levels","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("free_inodes","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("new_inode","uint32",32,4,SX_ID),
    SX_FIELD("last_directory_inode","uint32",36,4,SX_ID),
    SX_FIELD("unlinked_inode_buckets","uint32[64]",40,256,SX_ID),
    SX_FIELD("uuid","byte[16]",296,16,SX_ID),
    SX_FIELD("crc","uint32le",312,4,SX_CHECKSUM),
    SX_FIELD("padding","uint32",316,4,SX_RESERVED),
    SX_FIELD("log_sequence","uint64",320,8,SX_NONE),
    SX_FIELD("free_inode_root","uint32",328,4,SX_NONE),
    SX_FIELD("free_inode_levels","uint32",332,4,SX_COUNT_PROP),
    SX_FIELD("inode_tree_blocks","uint32",336,4,SX_COUNT_PROP),
    SX_FIELD("free_inode_tree_blocks","uint32",340,4,SX_COUNT_PROP),
};
static const sx_layout sxmf_xfs5_agi = {0x60420025U,"xfs5_agi",sxmf_xfs5_agi_fields,SX_COUNT(sxmf_xfs5_agi_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_xfs_inode_v2_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("mode","uint16",2,2,SX_FLAGS),
    SX_FIELD("version","uint8",4,1,SX_ID),
    SX_FIELD("data_format","uint8",5,1,SX_ID),
    SX_FIELD("metatype_or_old_link_count","uint16",6,2,SX_NONE),
    SX_FIELD("uid","uint32",8,4,SX_ID),
    SX_FIELD("gid","uint32",12,4,SX_ID),
    SX_FIELD("link_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("project_id_low","uint16",20,2,SX_NONE),
    SX_FIELD("project_id_high","uint16",22,2,SX_NONE),
    SX_FIELD("extent_count_or_padding","byte[8]",24,8,SX_NONE),
    SX_FIELD("access_timestamp","byte[8]",32,8,SX_NONE),
    SX_FIELD("modification_timestamp","byte[8]",40,8,SX_NONE),
    SX_FIELD("change_timestamp","byte[8]",48,8,SX_NONE),
    SX_FIELD("file_size","uint64",56,8,SX_SIZE),
    SX_FIELD("allocated_blocks","uint64",64,8,SX_COUNT_PROP),
    SX_FIELD("extent_size_blocks","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("data_or_attribute_extents","uint32",76,4,SX_COUNT_PROP),
    SX_FIELD("attribute_extents_or_padding","uint16",80,2,SX_NONE),
    SX_FIELD("attribute_fork_offset_units","uint8",82,1,SX_NONE),
    SX_FIELD("attribute_format","int8",83,1,SX_ID),
    SX_FIELD("dm_event_mask","uint32",84,4,SX_FLAGS),
    SX_FIELD("dm_state","uint16",88,2,SX_FLAGS),
    SX_FIELD("flags","uint16",90,2,SX_FLAGS),
    SX_FIELD("generation","uint32",92,4,SX_NONE),
    SX_FIELD("next_unlinked_inode","uint32",96,4,SX_ID),
};
static const sx_layout sxmf_xfs_inode_v2 = {0x60420026U,"xfs_inode_v2",sxmf_xfs_inode_v2_fields,SX_COUNT(sxmf_xfs_inode_v2_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_xfs_inode_v3_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("mode","uint16",2,2,SX_FLAGS),
    SX_FIELD("version","uint8",4,1,SX_ID),
    SX_FIELD("data_format","uint8",5,1,SX_ID),
    SX_FIELD("metatype_or_old_link_count","uint16",6,2,SX_NONE),
    SX_FIELD("uid","uint32",8,4,SX_ID),
    SX_FIELD("gid","uint32",12,4,SX_ID),
    SX_FIELD("link_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("project_id_low","uint16",20,2,SX_NONE),
    SX_FIELD("project_id_high","uint16",22,2,SX_NONE),
    SX_FIELD("extent_count_or_padding","byte[8]",24,8,SX_NONE),
    SX_FIELD("access_timestamp","byte[8]",32,8,SX_NONE),
    SX_FIELD("modification_timestamp","byte[8]",40,8,SX_NONE),
    SX_FIELD("change_timestamp","byte[8]",48,8,SX_NONE),
    SX_FIELD("file_size","uint64",56,8,SX_SIZE),
    SX_FIELD("allocated_blocks","uint64",64,8,SX_COUNT_PROP),
    SX_FIELD("extent_size_blocks","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("data_or_attribute_extents","uint32",76,4,SX_COUNT_PROP),
    SX_FIELD("attribute_extents_or_padding","uint16",80,2,SX_NONE),
    SX_FIELD("attribute_fork_offset_units","uint8",82,1,SX_NONE),
    SX_FIELD("attribute_format","int8",83,1,SX_ID),
    SX_FIELD("dm_event_mask","uint32",84,4,SX_FLAGS),
    SX_FIELD("dm_state","uint16",88,2,SX_FLAGS),
    SX_FIELD("flags","uint16",90,2,SX_FLAGS),
    SX_FIELD("generation","uint32",92,4,SX_NONE),
    SX_FIELD("next_unlinked_inode","uint32",96,4,SX_ID),
    SX_FIELD("crc","uint32le",100,4,SX_CHECKSUM),
    SX_FIELD("change_count","uint64",104,8,SX_COUNT_PROP),
    SX_FIELD("log_sequence","uint64",112,8,SX_NONE),
    SX_FIELD("flags2","uint64",120,8,SX_FLAGS),
    SX_FIELD("cow_extent_or_used_blocks","uint32",128,4,SX_COUNT_PROP),
    SX_FIELD("padding","byte[12]",132,12,SX_RESERVED),
    SX_FIELD("creation_timestamp","byte[8]",144,8,SX_NONE),
    SX_FIELD("inode","uint64",152,8,SX_ID),
    SX_FIELD("uuid","byte[16]",160,16,SX_ID),
};
static const sx_layout sxmf_xfs_inode_v3 = {0x60420027U,"xfs_inode_v3",sxmf_xfs_inode_v3_fields,SX_COUNT(sxmf_xfs_inode_v3_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_gfs2_superblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("metadata_type","uint32",4,4,SX_ID),
    SX_FIELD("reserved_generation","uint64",8,8,SX_RESERVED),
    SX_FIELD("metadata_format","uint32",16,4,SX_ID),
    SX_FIELD("journal_id","uint32",20,4,SX_ID),
    SX_FIELD("filesystem_format","uint32",24,4,SX_ID),
    SX_FIELD("multihost_format","uint32",28,4,SX_ID),
    SX_FIELD("reserved0","uint32",32,4,SX_RESERVED),
    SX_FIELD("block_size","uint32",36,4,SX_SIZE),
    SX_FIELD("log2_block_size","uint32",40,4,SX_NONE),
    SX_FIELD("reserved1","uint32",44,4,SX_RESERVED),
    SX_FIELD("master_inode","uint64",48,8,SX_ID),
    SX_FIELD("master_block","uint64",56,8,SX_NONE),
    SX_FIELD("reserved2","byte[16]",64,16,SX_RESERVED),
    SX_FIELD("root_inode","uint64",80,8,SX_ID),
    SX_FIELD("root_block","uint64",88,8,SX_NONE),
    SX_FIELD("lock_protocol","char[64]",96,64,SX_STRING),
    SX_FIELD("lock_table","char[64]",160,64,SX_STRING),
    SX_FIELD("reserved3","byte[32]",224,32,SX_RESERVED),
    SX_FIELD("uuid","byte[16]",256,16,SX_ID),
};
static const sx_layout sxmf_gfs2_superblock = {0x60420028U,"gfs2_superblock",sxmf_gfs2_superblock_fields,SX_COUNT(sxmf_gfs2_superblock_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_gfs2_inode_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("metadata_type","uint32",4,4,SX_ID),
    SX_FIELD("reserved_generation","uint64",8,8,SX_RESERVED),
    SX_FIELD("metadata_format","uint32",16,4,SX_ID),
    SX_FIELD("journal_id","uint32",20,4,SX_ID),
    SX_FIELD("inode","uint64",24,8,SX_ID),
    SX_FIELD("self_block","uint64",32,8,SX_NONE),
    SX_FIELD("mode","uint32",40,4,SX_FLAGS),
    SX_FIELD("uid","uint32",44,4,SX_ID),
    SX_FIELD("gid","uint32",48,4,SX_ID),
    SX_FIELD("link_count","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("file_size","uint64",56,8,SX_SIZE),
    SX_FIELD("allocated_blocks","uint64",64,8,SX_COUNT_PROP),
    SX_FIELD("access_time","uint64",72,8,SX_TIME),
    SX_FIELD("modification_time","uint64",80,8,SX_TIME),
    SX_FIELD("change_time","uint64",88,8,SX_TIME),
    SX_FIELD("device_major","uint32",96,4,SX_ID),
    SX_FIELD("device_minor","uint32",100,4,SX_ID),
    SX_FIELD("allocation_goal_meta","uint64",104,8,SX_NONE),
    SX_FIELD("allocation_goal_data","uint64",112,8,SX_NONE),
    SX_FIELD("generation","uint64",120,8,SX_NONE),
    SX_FIELD("flags","uint32",128,4,SX_FLAGS),
    SX_FIELD("payload_format","uint32",132,4,SX_ID),
    SX_FIELD("reserved1","uint16",136,2,SX_RESERVED),
    SX_FIELD("tree_height","uint16",138,2,SX_COUNT_PROP),
    SX_FIELD("reserved2","uint32",140,4,SX_RESERVED),
    SX_FIELD("reserved3","uint16",144,2,SX_RESERVED),
    SX_FIELD("hash_depth","uint16",146,2,SX_NONE),
    SX_FIELD("directory_entries","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("reserved4","byte[16]",152,16,SX_RESERVED),
    SX_FIELD("xattr_block","uint64",168,8,SX_NONE),
    SX_FIELD("access_nanoseconds","uint32",176,4,SX_NONE),
    SX_FIELD("modification_nanoseconds","uint32",180,4,SX_NONE),
    SX_FIELD("change_nanoseconds","uint32",184,4,SX_NONE),
    SX_FIELD("reserved5","byte[44]",188,44,SX_RESERVED),
};
static const sx_layout sxmf_gfs2_inode = {0x60420029U,"gfs2_inode",sxmf_gfs2_inode_fields,SX_COUNT(sxmf_gfs2_inode_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_gfs2_directory_entry_fields[] = {
    SX_FIELD("inode","uint64",0,8,SX_ID),
    SX_FIELD("block","uint64",8,8,SX_NONE),
    SX_FIELD("hash","uint32",16,4,SX_ID),
    SX_FIELD("record_length","uint16",20,2,SX_SIZE),
    SX_FIELD("name_length","uint16",22,2,SX_SIZE),
    SX_FIELD("type","uint16",24,2,SX_ID),
    SX_FIELD("read_ahead_blocks","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[12]",28,12,SX_RESERVED),
};
static const sx_layout sxmf_gfs2_directory_entry = {0x6042002aU,"gfs2_directory_entry",sxmf_gfs2_directory_entry_fields,SX_COUNT(sxmf_gfs2_directory_entry_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_gfs2_leaf_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("metadata_type","uint32",4,4,SX_ID),
    SX_FIELD("reserved_generation","uint64",8,8,SX_RESERVED),
    SX_FIELD("metadata_format","uint32",16,4,SX_ID),
    SX_FIELD("journal_id","uint32",20,4,SX_ID),
    SX_FIELD("depth","uint16",24,2,SX_NONE),
    SX_FIELD("entries","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("format","uint32",28,4,SX_ID),
    SX_FIELD("next_leaf_block","uint64",32,8,SX_NONE),
    SX_FIELD("reserved","byte[64]",40,64,SX_RESERVED),
};
static const sx_layout sxmf_gfs2_leaf = {0x6042002bU,"gfs2_leaf",sxmf_gfs2_leaf_fields,SX_COUNT(sxmf_gfs2_leaf_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_hpfs_superblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("magic2","uint32",4,4,SX_SIGNATURE),
    SX_FIELD("version","uint8",8,1,SX_ID),
    SX_FIELD("functional_version","uint8",9,1,SX_ID),
    SX_FIELD("reserved0","uint16",10,2,SX_RESERVED),
    SX_FIELD("root_fnode_sector","uint32",12,4,SX_NONE),
    SX_FIELD("sector_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("bad_sector_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("bitmap_directory_sector","uint32",24,4,SX_NONE),
    SX_FIELD("reserved1","uint32",28,4,SX_RESERVED),
    SX_FIELD("bad_block_directory_sector","uint32",32,4,SX_NONE),
    SX_FIELD("reserved2","uint32",36,4,SX_RESERVED),
    SX_FIELD("last_check","uint32",40,4,SX_TIME),
    SX_FIELD("last_optimization","uint32",44,4,SX_TIME),
    SX_FIELD("directory_band_sectors","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("directory_band_first_sector","uint32",52,4,SX_NONE),
    SX_FIELD("directory_band_last_sector","uint32",56,4,SX_NONE),
    SX_FIELD("directory_band_bitmap_sector","uint32",60,4,SX_NONE),
    SX_FIELD("unused_volume_name","char[32]",64,32,SX_STRING),
    SX_FIELD("user_id_table_sector","uint32",96,4,SX_NONE),
    SX_FIELD("reserved3","byte[412]",100,412,SX_RESERVED),
};
static const sx_layout sxmf_hpfs_superblock = {0x6042002cU,"hpfs_superblock",sxmf_hpfs_superblock_fields,SX_COUNT(sxmf_hpfs_superblock_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hpfs_spareblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("magic2","uint32",4,4,SX_SIGNATURE),
    SX_FIELD("flags","uint8",8,1,SX_FLAGS),
    SX_FIELD("hpfs386_flags","uint8",9,1,SX_FLAGS),
    SX_FIELD("multimedia_contiguity","uint8",10,1,SX_NONE),
    SX_FIELD("reserved0","uint8",11,1,SX_RESERVED),
    SX_FIELD("hotfix_map_sector","uint32",12,4,SX_NONE),
    SX_FIELD("hotfix_used_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("hotfix_capacity","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("free_spare_dnodes","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("spare_dnode_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("code_page_directory_sector","uint32",32,4,SX_NONE),
    SX_FIELD("code_page_count","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("superblock_crc","uint32",40,4,SX_CHECKSUM),
    SX_FIELD("spareblock_crc","uint32",44,4,SX_CHECKSUM),
    SX_FIELD("reserved1","byte[60]",48,60,SX_RESERVED),
    SX_FIELD("spare_dnode_sectors","uint32[100]",108,400,SX_NONE),
    SX_FIELD("reserved2","uint32",508,4,SX_RESERVED),
};
static const sx_layout sxmf_hpfs_spareblock = {0x6042002dU,"hpfs_spareblock",sxmf_hpfs_spareblock_fields,SX_COUNT(sxmf_hpfs_spareblock_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hpfs_fnode_prefix_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("read_history","uint32[2]",4,8,SX_NONE),
    SX_FIELD("name_length","uint8",12,1,SX_SIZE),
    SX_FIELD("truncated_name","char[15]",13,15,SX_STRING),
    SX_FIELD("parent_fnode_sector","uint32",28,4,SX_NONE),
    SX_FIELD("external_acl_size","uint32",32,4,SX_SIZE),
    SX_FIELD("acl_sector","uint32",36,4,SX_NONE),
    SX_FIELD("inline_acl_size","uint16",40,2,SX_SIZE),
    SX_FIELD("acl_anode","uint8",42,1,SX_FLAGS),
    SX_FIELD("history_bit_count","uint8",43,1,SX_COUNT_PROP),
    SX_FIELD("external_ea_size","uint32",44,4,SX_SIZE),
    SX_FIELD("ea_sector","uint32",48,4,SX_NONE),
    SX_FIELD("inline_ea_size","uint16",52,2,SX_SIZE),
    SX_FIELD("flags","uint16",54,2,SX_FLAGS),
};
static const sx_layout sxmf_hpfs_fnode_prefix = {0x6042002eU,"hpfs_fnode_prefix",sxmf_hpfs_fnode_prefix_fields,SX_COUNT(sxmf_hpfs_fnode_prefix_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hpfs_btree_header_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("reserved","byte[3]",1,3,SX_RESERVED),
    SX_FIELD("free_nodes","uint8",4,1,SX_COUNT_PROP),
    SX_FIELD("used_nodes","uint8",5,1,SX_COUNT_PROP),
    SX_FIELD("first_free","uint16",6,2,SX_OFFSET),
};
static const sx_layout sxmf_hpfs_btree_header = {0x6042002fU,"hpfs_btree_header",sxmf_hpfs_btree_header_fields,SX_COUNT(sxmf_hpfs_btree_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hpfs_extent_fields[] = {
    SX_FIELD("file_sector","uint32",0,4,SX_NONE),
    SX_FIELD("sector_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("disk_sector","uint32",8,4,SX_NONE),
};
static const sx_layout sxmf_hpfs_extent = {0x60420030U,"hpfs_extent",sxmf_hpfs_extent_fields,SX_COUNT(sxmf_hpfs_extent_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hpfs_btree_child_fields[] = {
    SX_FIELD("file_sector_limit","uint32",0,4,SX_NONE),
    SX_FIELD("anode_sector","uint32",4,4,SX_NONE),
};
static const sx_layout sxmf_hpfs_btree_child = {0x60420031U,"hpfs_btree_child",sxmf_hpfs_btree_child_fields,SX_COUNT(sxmf_hpfs_btree_child_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hpfs_fnode_tail_fields[] = {
    SX_FIELD("file_size","uint32",0,4,SX_SIZE),
    SX_FIELD("required_ea_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("user_id","byte[16]",8,16,SX_NONE),
    SX_FIELD("ea_offset","uint16",24,2,SX_OFFSET),
    SX_FIELD("dasd_limit_threshold","uint8",26,1,SX_NONE),
    SX_FIELD("dasd_limit_delta","uint8",27,1,SX_NONE),
    SX_FIELD("dasd_limit","uint32",28,4,SX_NONE),
    SX_FIELD("dasd_usage","uint32",32,4,SX_NONE),
};
static const sx_layout sxmf_hpfs_fnode_tail = {0x60420032U,"hpfs_fnode_tail",sxmf_hpfs_fnode_tail_fields,SX_COUNT(sxmf_hpfs_fnode_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hpfs_anode_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("self_sector","uint32",4,4,SX_NONE),
    SX_FIELD("parent_sector","uint32",8,4,SX_NONE),
};
static const sx_layout sxmf_hpfs_anode_header = {0x60420033U,"hpfs_anode_header",sxmf_hpfs_anode_header_fields,SX_COUNT(sxmf_hpfs_anode_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hpfs_dnode_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("first_free","uint32",4,4,SX_OFFSET),
    SX_FIELD("root_and_activity","uint8",8,1,SX_FLAGS),
    SX_FIELD("activity","byte[3]",9,3,SX_NONE),
    SX_FIELD("parent_sector","uint32",12,4,SX_NONE),
    SX_FIELD("self_sector","uint32",16,4,SX_NONE),
};
static const sx_layout sxmf_hpfs_dnode_header = {0x60420034U,"hpfs_dnode_header",sxmf_hpfs_dnode_header_fields,SX_COUNT(sxmf_hpfs_dnode_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hpfs_directory_entry_fields[] = {
    SX_FIELD("length","uint16",0,2,SX_SIZE),
    SX_FIELD("flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("attributes","uint8",3,1,SX_FLAGS),
    SX_FIELD("fnode_sector","uint32",4,4,SX_NONE),
    SX_FIELD("write_time","uint32",8,4,SX_TIME),
    SX_FIELD("file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("access_time","uint32",16,4,SX_TIME),
    SX_FIELD("creation_time","uint32",20,4,SX_TIME),
    SX_FIELD("ea_size","uint32",24,4,SX_SIZE),
    SX_FIELD("acl_count_bits","uint8",28,1,SX_FLAGS),
    SX_FIELD("code_page_index","uint8",29,1,SX_NONE),
    SX_FIELD("name_length","uint8",30,1,SX_SIZE),
};
static const sx_layout sxmf_hpfs_directory_entry = {0x60420035U,"hpfs_directory_entry",sxmf_hpfs_directory_entry_fields,SX_COUNT(sxmf_hpfs_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hpfs_down_pointer_fields[] = {
    SX_FIELD("dnode_sector","uint32",0,4,SX_NONE),
};
static const sx_layout sxmf_hpfs_down_pointer = {0x60420036U,"hpfs_down_pointer",sxmf_hpfs_down_pointer_fields,SX_COUNT(sxmf_hpfs_down_pointer_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hammer_volume_header_le_fields[] = {
    SX_FIELD("signature","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("boot_begin","int64",8,8,SX_OFFSET),
    SX_FIELD("memory_log_begin","int64",16,8,SX_OFFSET),
    SX_FIELD("buffer_begin","int64",24,8,SX_OFFSET),
    SX_FIELD("buffer_end","int64",32,8,SX_OFFSET),
    SX_FIELD("reserved0","int64",40,8,SX_RESERVED),
    SX_FIELD("filesystem_uuid","byte[16]",48,16,SX_ID),
    SX_FIELD("filesystem_type_uuid","byte[16]",64,16,SX_ID),
    SX_FIELD("label","char[64]",80,64,SX_STRING),
    SX_FIELD("volume_number","int32",144,4,SX_NONE),
    SX_FIELD("volume_count","int32",148,4,SX_COUNT_PROP),
    SX_FIELD("version","uint32",152,4,SX_ID),
    SX_FIELD("crc","uint32",156,4,SX_CHECKSUM),
    SX_FIELD("flags","uint32",160,4,SX_FLAGS),
    SX_FIELD("root_volume_number","uint32",164,4,SX_NONE),
    SX_FIELD("reserved1","uint32[8]",168,32,SX_RESERVED),
    SX_FIELD("bigblock_count","int64",200,8,SX_COUNT_PROP),
    SX_FIELD("free_bigblocks","int64",208,8,SX_COUNT_PROP),
    SX_FIELD("reserved2","int64",216,8,SX_RESERVED),
    SX_FIELD("inode_count","int64",224,8,SX_COUNT_PROP),
    SX_FIELD("reserved3","int64",232,8,SX_RESERVED),
    SX_FIELD("btree_root","uint64",240,8,SX_POINTER),
    SX_FIELD("next_transaction_id","uint64",248,8,SX_NONE),
    SX_FIELD("reserved4","uint64",256,8,SX_RESERVED),
};
static const sx_layout sxmf_hammer_volume_header_le = {0x60420037U,"hammer_volume_header_le",sxmf_hammer_volume_header_le_fields,SX_COUNT(sxmf_hammer_volume_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hammer_volume_header_be_fields[] = {
    SX_FIELD("signature","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("boot_begin","int64",8,8,SX_OFFSET),
    SX_FIELD("memory_log_begin","int64",16,8,SX_OFFSET),
    SX_FIELD("buffer_begin","int64",24,8,SX_OFFSET),
    SX_FIELD("buffer_end","int64",32,8,SX_OFFSET),
    SX_FIELD("reserved0","int64",40,8,SX_RESERVED),
    SX_FIELD("filesystem_uuid","byte[16]",48,16,SX_ID),
    SX_FIELD("filesystem_type_uuid","byte[16]",64,16,SX_ID),
    SX_FIELD("label","char[64]",80,64,SX_STRING),
    SX_FIELD("volume_number","int32",144,4,SX_NONE),
    SX_FIELD("volume_count","int32",148,4,SX_COUNT_PROP),
    SX_FIELD("version","uint32",152,4,SX_ID),
    SX_FIELD("crc","uint32",156,4,SX_CHECKSUM),
    SX_FIELD("flags","uint32",160,4,SX_FLAGS),
    SX_FIELD("root_volume_number","uint32",164,4,SX_NONE),
    SX_FIELD("reserved1","uint32[8]",168,32,SX_RESERVED),
    SX_FIELD("bigblock_count","int64",200,8,SX_COUNT_PROP),
    SX_FIELD("free_bigblocks","int64",208,8,SX_COUNT_PROP),
    SX_FIELD("reserved2","int64",216,8,SX_RESERVED),
    SX_FIELD("inode_count","int64",224,8,SX_COUNT_PROP),
    SX_FIELD("reserved3","int64",232,8,SX_RESERVED),
    SX_FIELD("btree_root","uint64",240,8,SX_POINTER),
    SX_FIELD("next_transaction_id","uint64",248,8,SX_NONE),
    SX_FIELD("reserved4","uint64",256,8,SX_RESERVED),
};
static const sx_layout sxmf_hammer_volume_header_be = {0x60420038U,"hammer_volume_header_be",sxmf_hammer_volume_header_be_fields,SX_COUNT(sxmf_hammer_volume_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_hammer_blockmap_le_fields[] = {
    SX_FIELD("physical_offset","uint64",0,8,SX_POINTER),
    SX_FIELD("first_offset","uint64",8,8,SX_POINTER),
    SX_FIELD("next_offset","uint64",16,8,SX_POINTER),
    SX_FIELD("allocation_offset","uint64",24,8,SX_POINTER),
    SX_FIELD("reserved","uint32",32,4,SX_RESERVED),
    SX_FIELD("crc","uint32",36,4,SX_CHECKSUM),
};
static const sx_layout sxmf_hammer_blockmap_le = {0x60420039U,"hammer_blockmap_le",sxmf_hammer_blockmap_le_fields,SX_COUNT(sxmf_hammer_blockmap_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hammer_blockmap_be_fields[] = {
    SX_FIELD("physical_offset","uint64",0,8,SX_POINTER),
    SX_FIELD("first_offset","uint64",8,8,SX_POINTER),
    SX_FIELD("next_offset","uint64",16,8,SX_POINTER),
    SX_FIELD("allocation_offset","uint64",24,8,SX_POINTER),
    SX_FIELD("reserved","uint32",32,4,SX_RESERVED),
    SX_FIELD("crc","uint32",36,4,SX_CHECKSUM),
};
static const sx_layout sxmf_hammer_blockmap_be = {0x6042003aU,"hammer_blockmap_be",sxmf_hammer_blockmap_be_fields,SX_COUNT(sxmf_hammer_blockmap_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_hammer_undo_pointer_le_fields[] = {
    SX_FIELD("address","uint64",0,8,SX_POINTER),
};
static const sx_layout sxmf_hammer_undo_pointer_le = {0x6042003bU,"hammer_undo_pointer_le",sxmf_hammer_undo_pointer_le_fields,SX_COUNT(sxmf_hammer_undo_pointer_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hammer_undo_pointer_be_fields[] = {
    SX_FIELD("address","uint64",0,8,SX_POINTER),
};
static const sx_layout sxmf_hammer_undo_pointer_be = {0x6042003cU,"hammer_undo_pointer_be",sxmf_hammer_undo_pointer_be_fields,SX_COUNT(sxmf_hammer_undo_pointer_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_zfs_embedded_checksum_le_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("checksum","uint64[4]",8,32,SX_CHECKSUM),
};
static const sx_layout sxmf_zfs_embedded_checksum_le = {0x6042003dU,"zfs_embedded_checksum_le",sxmf_zfs_embedded_checksum_le_fields,SX_COUNT(sxmf_zfs_embedded_checksum_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_zfs_embedded_checksum_be_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("checksum","uint64[4]",8,32,SX_CHECKSUM),
};
static const sx_layout sxmf_zfs_embedded_checksum_be = {0x6042003eU,"zfs_embedded_checksum_be",sxmf_zfs_embedded_checksum_be_fields,SX_COUNT(sxmf_zfs_embedded_checksum_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_zfs_block_pointer_le_fields[] = {
    SX_FIELD("dva0_word0","uint64",0,8,SX_FLAGS),
    SX_FIELD("dva0_word1","uint64",8,8,SX_FLAGS),
    SX_FIELD("dva1_word0","uint64",16,8,SX_FLAGS),
    SX_FIELD("dva1_word1","uint64",24,8,SX_FLAGS),
    SX_FIELD("dva2_word0","uint64",32,8,SX_FLAGS),
    SX_FIELD("dva2_word1","uint64",40,8,SX_FLAGS),
    SX_FIELD("properties","uint64",48,8,SX_FLAGS),
    SX_FIELD("properties2","uint64",56,8,SX_FLAGS),
    SX_FIELD("padding","uint64",64,8,SX_RESERVED),
    SX_FIELD("physical_birth_word","uint64",72,8,SX_NONE),
    SX_FIELD("logical_birth_word","uint64",80,8,SX_NONE),
    SX_FIELD("fill_count","uint64",88,8,SX_COUNT_PROP),
    SX_FIELD("checksum","uint64[4]",96,32,SX_CHECKSUM),
};
static const sx_layout sxmf_zfs_block_pointer_le = {0x6042003fU,"zfs_block_pointer_le",sxmf_zfs_block_pointer_le_fields,SX_COUNT(sxmf_zfs_block_pointer_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_zfs_block_pointer_be_fields[] = {
    SX_FIELD("dva0_word0","uint64",0,8,SX_FLAGS),
    SX_FIELD("dva0_word1","uint64",8,8,SX_FLAGS),
    SX_FIELD("dva1_word0","uint64",16,8,SX_FLAGS),
    SX_FIELD("dva1_word1","uint64",24,8,SX_FLAGS),
    SX_FIELD("dva2_word0","uint64",32,8,SX_FLAGS),
    SX_FIELD("dva2_word1","uint64",40,8,SX_FLAGS),
    SX_FIELD("properties","uint64",48,8,SX_FLAGS),
    SX_FIELD("properties2","uint64",56,8,SX_FLAGS),
    SX_FIELD("padding","uint64",64,8,SX_RESERVED),
    SX_FIELD("physical_birth_word","uint64",72,8,SX_NONE),
    SX_FIELD("logical_birth_word","uint64",80,8,SX_NONE),
    SX_FIELD("fill_count","uint64",88,8,SX_COUNT_PROP),
    SX_FIELD("checksum","uint64[4]",96,32,SX_CHECKSUM),
};
static const sx_layout sxmf_zfs_block_pointer_be = {0x60420040U,"zfs_block_pointer_be",sxmf_zfs_block_pointer_be_fields,SX_COUNT(sxmf_zfs_block_pointer_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_zfs_uberblock_prefix_le_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("version","uint64",8,8,SX_ID),
    SX_FIELD("transaction_group","uint64",16,8,SX_NONE),
    SX_FIELD("guid_sum","uint64",24,8,SX_ID),
    SX_FIELD("timestamp","uint64",32,8,SX_TIME),
};
static const sx_layout sxmf_zfs_uberblock_prefix_le = {0x60420041U,"zfs_uberblock_prefix_le",sxmf_zfs_uberblock_prefix_le_fields,SX_COUNT(sxmf_zfs_uberblock_prefix_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_zfs_uberblock_prefix_be_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("version","uint64",8,8,SX_ID),
    SX_FIELD("transaction_group","uint64",16,8,SX_NONE),
    SX_FIELD("guid_sum","uint64",24,8,SX_ID),
    SX_FIELD("timestamp","uint64",32,8,SX_TIME),
};
static const sx_layout sxmf_zfs_uberblock_prefix_be = {0x60420042U,"zfs_uberblock_prefix_be",sxmf_zfs_uberblock_prefix_be_fields,SX_COUNT(sxmf_zfs_uberblock_prefix_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_zfs_uberblock_tail_le_fields[] = {
    SX_FIELD("software_version","uint64",0,8,SX_ID),
    SX_FIELD("mmp_magic","uint64",8,8,SX_SIGNATURE),
    SX_FIELD("mmp_delay","uint64",16,8,SX_NONE),
    SX_FIELD("mmp_config","uint64",24,8,SX_FLAGS),
    SX_FIELD("checkpoint_transaction_group","uint64",32,8,SX_NONE),
    SX_FIELD("raidz_reflow_info","uint64",40,8,SX_FLAGS),
};
static const sx_layout sxmf_zfs_uberblock_tail_le = {0x60420043U,"zfs_uberblock_tail_le",sxmf_zfs_uberblock_tail_le_fields,SX_COUNT(sxmf_zfs_uberblock_tail_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_zfs_uberblock_tail_be_fields[] = {
    SX_FIELD("software_version","uint64",0,8,SX_ID),
    SX_FIELD("mmp_magic","uint64",8,8,SX_SIGNATURE),
    SX_FIELD("mmp_delay","uint64",16,8,SX_NONE),
    SX_FIELD("mmp_config","uint64",24,8,SX_FLAGS),
    SX_FIELD("checkpoint_transaction_group","uint64",32,8,SX_NONE),
    SX_FIELD("raidz_reflow_info","uint64",40,8,SX_FLAGS),
};
static const sx_layout sxmf_zfs_uberblock_tail_be = {0x60420044U,"zfs_uberblock_tail_be",sxmf_zfs_uberblock_tail_be_fields,SX_COUNT(sxmf_zfs_uberblock_tail_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_erofs_superblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("features_compat","uint32",8,4,SX_FLAGS),
    SX_FIELD("block_size_bits","uint8",12,1,SX_NONE),
    SX_FIELD("extension_slots","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("root_inode","uint16",14,2,SX_ID),
    SX_FIELD("inode_count","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("build_time","uint64",24,8,SX_TIME),
    SX_FIELD("build_nanoseconds","uint32",32,4,SX_NONE),
    SX_FIELD("block_count","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("metadata_block","uint32",40,4,SX_NONE),
    SX_FIELD("xattr_block","uint32",44,4,SX_NONE),
    SX_FIELD("uuid","byte[16]",48,16,SX_ID),
    SX_FIELD("volume_name","char[16]",64,16,SX_STRING),
    SX_FIELD("features_incompat","uint32",80,4,SX_FLAGS),
    SX_FIELD("compression_algorithms_or_lz4_distance","uint16",84,2,SX_NONE),
    SX_FIELD("extra_device_count","uint16",86,2,SX_COUNT_PROP),
    SX_FIELD("device_table_slot","uint16",88,2,SX_NONE),
    SX_FIELD("directory_block_bits","uint8",90,1,SX_NONE),
    SX_FIELD("xattr_prefix_count","uint8",91,1,SX_COUNT_PROP),
    SX_FIELD("xattr_prefix_start","uint32",92,4,SX_NONE),
    SX_FIELD("packed_inode","uint64",96,8,SX_ID),
    SX_FIELD("reserved_or_extension","byte[24]",104,24,SX_NONE),
};
static const sx_layout sxmf_erofs_superblock = {0x60420045U,"erofs_superblock",sxmf_erofs_superblock_fields,SX_COUNT(sxmf_erofs_superblock_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_erofs_inode_compact_fields[] = {
    SX_FIELD("format","uint16",0,2,SX_FLAGS),
    SX_FIELD("xattr_count","uint16",2,2,SX_NONE),
    SX_FIELD("mode","uint16",4,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
    SX_FIELD("block_or_device_or_chunk_info","uint32",16,4,SX_NONE),
    SX_FIELD("inode_number","uint32",20,4,SX_ID),
    SX_FIELD("uid","uint16",24,2,SX_ID),
    SX_FIELD("gid","uint16",26,2,SX_ID),
    SX_FIELD("reserved2","uint32",28,4,SX_RESERVED),
};
static const sx_layout sxmf_erofs_inode_compact = {0x60420046U,"erofs_inode_compact",sxmf_erofs_inode_compact_fields,SX_COUNT(sxmf_erofs_inode_compact_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_erofs_inode_extended_fields[] = {
    SX_FIELD("format","uint16",0,2,SX_FLAGS),
    SX_FIELD("xattr_count","uint16",2,2,SX_NONE),
    SX_FIELD("mode","uint16",4,2,SX_FLAGS),
    SX_FIELD("reserved","uint16",6,2,SX_RESERVED),
    SX_FIELD("file_size","uint64",8,8,SX_SIZE),
    SX_FIELD("block_or_device_or_chunk_info","uint32",16,4,SX_NONE),
    SX_FIELD("inode_number","uint32",20,4,SX_ID),
    SX_FIELD("uid","uint32",24,4,SX_ID),
    SX_FIELD("gid","uint32",28,4,SX_ID),
    SX_FIELD("modification_time","uint64",32,8,SX_TIME),
    SX_FIELD("modification_nanoseconds","uint32",40,4,SX_NONE),
    SX_FIELD("link_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("reserved2","byte[16]",48,16,SX_RESERVED),
};
static const sx_layout sxmf_erofs_inode_extended = {0x60420047U,"erofs_inode_extended",sxmf_erofs_inode_extended_fields,SX_COUNT(sxmf_erofs_inode_extended_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_erofs_directory_entry_fields[] = {
    SX_FIELD("inode_id","uint64",0,8,SX_ID),
    SX_FIELD("name_offset","uint16",8,2,SX_OFFSET),
    SX_FIELD("type","uint8",10,1,SX_ID),
    SX_FIELD("reserved","uint8",11,1,SX_RESERVED),
};
static const sx_layout sxmf_erofs_directory_entry = {0x60420048U,"erofs_directory_entry",sxmf_erofs_directory_entry_fields,SX_COUNT(sxmf_erofs_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_erofs_device_slot_fields[] = {
    SX_FIELD("tag","char[64]",0,64,SX_STRING),
    SX_FIELD("block_count","uint32",64,4,SX_COUNT_PROP),
    SX_FIELD("mapped_block","uint32",68,4,SX_NONE),
    SX_FIELD("reserved","byte[56]",72,56,SX_RESERVED),
};
static const sx_layout sxmf_erofs_device_slot = {0x60420049U,"erofs_device_slot",sxmf_erofs_device_slot_fields,SX_COUNT(sxmf_erofs_device_slot_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_erofs_chunk_block_fields[] = {
    SX_FIELD("block","uint32",0,4,SX_NONE),
};
static const sx_layout sxmf_erofs_chunk_block = {0x6042004aU,"erofs_chunk_block",sxmf_erofs_chunk_block_fields,SX_COUNT(sxmf_erofs_chunk_block_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_ufs1_legacy_superblock_le_fields[] = {
    SX_FIELD("first_field","int32",0,4,SX_NONE),
    SX_FIELD("unused1","int32",4,4,SX_RESERVED),
    SX_FIELD("superblock_fragment","int32",8,4,SX_NONE),
    SX_FIELD("cylinder_block_fragment","int32",12,4,SX_NONE),
    SX_FIELD("inode_block_fragment","int32",16,4,SX_NONE),
    SX_FIELD("data_block_fragment","int32",20,4,SX_NONE),
    SX_FIELD("cylinder_group_offset","int32",24,4,SX_NONE),
    SX_FIELD("cylinder_group_mask","int32",28,4,SX_FLAGS),
    SX_FIELD("old_write_time","int32",32,4,SX_TIME),
    SX_FIELD("old_fragment_count","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("old_data_fragment_count","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("cylinder_group_count","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("block_size","int32",48,4,SX_SIZE),
    SX_FIELD("fragment_size","int32",52,4,SX_SIZE),
    SX_FIELD("fragments_per_block","int32",56,4,SX_COUNT_PROP),
    SX_FIELD("min_free_percent","int32",60,4,SX_NONE),
    SX_FIELD("rotation_delay","int32",64,4,SX_NONE),
    SX_FIELD("revolutions_per_second","int32",68,4,SX_NONE),
    SX_FIELD("block_mask","int32",72,4,SX_FLAGS),
    SX_FIELD("fragment_mask","int32",76,4,SX_FLAGS),
    SX_FIELD("block_shift","int32",80,4,SX_NONE),
    SX_FIELD("fragment_shift","int32",84,4,SX_NONE),
    SX_FIELD("max_contiguous_blocks","int32",88,4,SX_COUNT_PROP),
    SX_FIELD("max_blocks_per_group","int32",92,4,SX_COUNT_PROP),
    SX_FIELD("fragments_shift","int32",96,4,SX_NONE),
    SX_FIELD("filesystem_to_disk_shift","int32",100,4,SX_NONE),
    SX_FIELD("superblock_size","int32",104,4,SX_SIZE),
    SX_FIELD("old_summary_mask","int32",108,4,SX_FLAGS),
    SX_FIELD("old_summary_shift","int32",112,4,SX_NONE),
    SX_FIELD("indirect_entries","int32",116,4,SX_COUNT_PROP),
    SX_FIELD("inodes_per_block","int32",120,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_fragment","int32",124,4,SX_COUNT_PROP),
    SX_FIELD("optimization","int32",128,4,SX_ID),
    SX_FIELD("sectors_per_track_with_spares","int32",132,4,SX_COUNT_PROP),
    SX_FIELD("interleave","int32",136,4,SX_NONE),
    SX_FIELD("track_skew","int32",140,4,SX_NONE),
    SX_FIELD("filesystem_id","int32[2]",144,8,SX_ID),
    SX_FIELD("old_summary_fragment","int32",152,4,SX_NONE),
    SX_FIELD("summary_size","int32",156,4,SX_SIZE),
    SX_FIELD("cylinder_group_size","int32",160,4,SX_SIZE),
    SX_FIELD("old_tracks_per_cylinder","int32",164,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","int32",168,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_cylinder","int32",172,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","int32",176,4,SX_COUNT_PROP),
    SX_FIELD("cylinders_per_group","int32",180,4,SX_COUNT_PROP),
    SX_FIELD("inodes_per_group","int32",184,4,SX_COUNT_PROP),
    SX_FIELD("fragments_per_group","int32",188,4,SX_COUNT_PROP),
    SX_FIELD("old_directory_count","int32",192,4,SX_COUNT_PROP),
    SX_FIELD("old_free_blocks","int32",196,4,SX_COUNT_PROP),
    SX_FIELD("old_free_inodes","int32",200,4,SX_COUNT_PROP),
    SX_FIELD("old_free_fragments","int32",204,4,SX_COUNT_PROP),
    SX_FIELD("modified","int8",208,1,SX_FLAGS),
    SX_FIELD("clean","int8",209,1,SX_FLAGS),
    SX_FIELD("read_only","int8",210,1,SX_FLAGS),
    SX_FIELD("old_flags","uint8",211,1,SX_FLAGS),
    SX_FIELD("mount_name","char[512]",212,512,SX_STRING),
    SX_FIELD("cylinder_rotor","int32",724,4,SX_NONE),
    SX_FIELD("incore_pointer_padding","byte[128]",728,128,SX_NONE),
    SX_FIELD("cylinders_per_rotation","int32",856,4,SX_NONE),
    SX_FIELD("old_rotation_table","int16[128]",860,256,SX_NONE),
    SX_FIELD("snapshot_inodes","int32[20]",1116,80,SX_ID),
    SX_FIELD("average_file_size","int32",1196,4,SX_SIZE),
    SX_FIELD("average_files_per_directory","int32",1200,4,SX_COUNT_PROP),
    SX_FIELD("spare_constants","byte[104]",1204,104,SX_RESERVED),
    SX_FIELD("pending_blocks","int32",1308,4,SX_COUNT_PROP),
    SX_FIELD("pending_inodes","int32",1312,4,SX_COUNT_PROP),
    SX_FIELD("contiguous_summary_count","int32",1316,4,SX_COUNT_PROP),
    SX_FIELD("max_inline_symlink","int32",1320,4,SX_SIZE),
    SX_FIELD("inode_format","int32",1324,4,SX_ID),
    SX_FIELD("max_file_size","uint64",1328,8,SX_SIZE),
    SX_FIELD("block_mask64","int64",1336,8,SX_FLAGS),
    SX_FIELD("fragment_mask64","int64",1344,8,SX_FLAGS),
    SX_FIELD("state","int32",1352,4,SX_FLAGS),
    SX_FIELD("rotation_table_format","int32",1356,4,SX_ID),
    SX_FIELD("rotational_positions","int32",1360,4,SX_COUNT_PROP),
    SX_FIELD("rotation_position_offset","int32",1364,4,SX_OFFSET),
    SX_FIELD("rotation_block_offset","int32",1368,4,SX_OFFSET),
    SX_FIELD("magic","uint32",1372,4,SX_SIGNATURE),
};
static const sx_layout sxmf_ufs1_legacy_superblock_le = {0x6042004bU,"ufs1_legacy_superblock_le",sxmf_ufs1_legacy_superblock_le_fields,SX_COUNT(sxmf_ufs1_legacy_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_ufs1_legacy_superblock_be_fields[] = {
    SX_FIELD("first_field","int32",0,4,SX_NONE),
    SX_FIELD("unused1","int32",4,4,SX_RESERVED),
    SX_FIELD("superblock_fragment","int32",8,4,SX_NONE),
    SX_FIELD("cylinder_block_fragment","int32",12,4,SX_NONE),
    SX_FIELD("inode_block_fragment","int32",16,4,SX_NONE),
    SX_FIELD("data_block_fragment","int32",20,4,SX_NONE),
    SX_FIELD("cylinder_group_offset","int32",24,4,SX_NONE),
    SX_FIELD("cylinder_group_mask","int32",28,4,SX_FLAGS),
    SX_FIELD("old_write_time","int32",32,4,SX_TIME),
    SX_FIELD("old_fragment_count","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("old_data_fragment_count","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("cylinder_group_count","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("block_size","int32",48,4,SX_SIZE),
    SX_FIELD("fragment_size","int32",52,4,SX_SIZE),
    SX_FIELD("fragments_per_block","int32",56,4,SX_COUNT_PROP),
    SX_FIELD("min_free_percent","int32",60,4,SX_NONE),
    SX_FIELD("rotation_delay","int32",64,4,SX_NONE),
    SX_FIELD("revolutions_per_second","int32",68,4,SX_NONE),
    SX_FIELD("block_mask","int32",72,4,SX_FLAGS),
    SX_FIELD("fragment_mask","int32",76,4,SX_FLAGS),
    SX_FIELD("block_shift","int32",80,4,SX_NONE),
    SX_FIELD("fragment_shift","int32",84,4,SX_NONE),
    SX_FIELD("max_contiguous_blocks","int32",88,4,SX_COUNT_PROP),
    SX_FIELD("max_blocks_per_group","int32",92,4,SX_COUNT_PROP),
    SX_FIELD("fragments_shift","int32",96,4,SX_NONE),
    SX_FIELD("filesystem_to_disk_shift","int32",100,4,SX_NONE),
    SX_FIELD("superblock_size","int32",104,4,SX_SIZE),
    SX_FIELD("old_summary_mask","int32",108,4,SX_FLAGS),
    SX_FIELD("old_summary_shift","int32",112,4,SX_NONE),
    SX_FIELD("indirect_entries","int32",116,4,SX_COUNT_PROP),
    SX_FIELD("inodes_per_block","int32",120,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_fragment","int32",124,4,SX_COUNT_PROP),
    SX_FIELD("optimization","int32",128,4,SX_ID),
    SX_FIELD("sectors_per_track_with_spares","int32",132,4,SX_COUNT_PROP),
    SX_FIELD("interleave","int32",136,4,SX_NONE),
    SX_FIELD("track_skew","int32",140,4,SX_NONE),
    SX_FIELD("filesystem_id","int32[2]",144,8,SX_ID),
    SX_FIELD("old_summary_fragment","int32",152,4,SX_NONE),
    SX_FIELD("summary_size","int32",156,4,SX_SIZE),
    SX_FIELD("cylinder_group_size","int32",160,4,SX_SIZE),
    SX_FIELD("old_tracks_per_cylinder","int32",164,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","int32",168,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_cylinder","int32",172,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","int32",176,4,SX_COUNT_PROP),
    SX_FIELD("cylinders_per_group","int32",180,4,SX_COUNT_PROP),
    SX_FIELD("inodes_per_group","int32",184,4,SX_COUNT_PROP),
    SX_FIELD("fragments_per_group","int32",188,4,SX_COUNT_PROP),
    SX_FIELD("old_directory_count","int32",192,4,SX_COUNT_PROP),
    SX_FIELD("old_free_blocks","int32",196,4,SX_COUNT_PROP),
    SX_FIELD("old_free_inodes","int32",200,4,SX_COUNT_PROP),
    SX_FIELD("old_free_fragments","int32",204,4,SX_COUNT_PROP),
    SX_FIELD("modified","int8",208,1,SX_FLAGS),
    SX_FIELD("clean","int8",209,1,SX_FLAGS),
    SX_FIELD("read_only","int8",210,1,SX_FLAGS),
    SX_FIELD("old_flags","uint8",211,1,SX_FLAGS),
    SX_FIELD("mount_name","char[512]",212,512,SX_STRING),
    SX_FIELD("cylinder_rotor","int32",724,4,SX_NONE),
    SX_FIELD("incore_pointer_padding","byte[128]",728,128,SX_NONE),
    SX_FIELD("cylinders_per_rotation","int32",856,4,SX_NONE),
    SX_FIELD("old_rotation_table","int16[128]",860,256,SX_NONE),
    SX_FIELD("snapshot_inodes","int32[20]",1116,80,SX_ID),
    SX_FIELD("average_file_size","int32",1196,4,SX_SIZE),
    SX_FIELD("average_files_per_directory","int32",1200,4,SX_COUNT_PROP),
    SX_FIELD("spare_constants","byte[104]",1204,104,SX_RESERVED),
    SX_FIELD("pending_blocks","int32",1308,4,SX_COUNT_PROP),
    SX_FIELD("pending_inodes","int32",1312,4,SX_COUNT_PROP),
    SX_FIELD("contiguous_summary_count","int32",1316,4,SX_COUNT_PROP),
    SX_FIELD("max_inline_symlink","int32",1320,4,SX_SIZE),
    SX_FIELD("inode_format","int32",1324,4,SX_ID),
    SX_FIELD("max_file_size","uint64",1328,8,SX_SIZE),
    SX_FIELD("block_mask64","int64",1336,8,SX_FLAGS),
    SX_FIELD("fragment_mask64","int64",1344,8,SX_FLAGS),
    SX_FIELD("state","int32",1352,4,SX_FLAGS),
    SX_FIELD("rotation_table_format","int32",1356,4,SX_ID),
    SX_FIELD("rotational_positions","int32",1360,4,SX_COUNT_PROP),
    SX_FIELD("rotation_position_offset","int32",1364,4,SX_OFFSET),
    SX_FIELD("rotation_block_offset","int32",1368,4,SX_OFFSET),
    SX_FIELD("magic","uint32",1372,4,SX_SIGNATURE),
};
static const sx_layout sxmf_ufs1_legacy_superblock_be = {0x6042004cU,"ufs1_legacy_superblock_be",sxmf_ufs1_legacy_superblock_be_fields,SX_COUNT(sxmf_ufs1_legacy_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_ufs_modern_superblock_le_fields[] = {
    SX_FIELD("first_field","int32",0,4,SX_NONE),
    SX_FIELD("unused1","int32",4,4,SX_RESERVED),
    SX_FIELD("superblock_fragment","int32",8,4,SX_NONE),
    SX_FIELD("cylinder_block_fragment","int32",12,4,SX_NONE),
    SX_FIELD("inode_block_fragment","int32",16,4,SX_NONE),
    SX_FIELD("data_block_fragment","int32",20,4,SX_NONE),
    SX_FIELD("cylinder_group_offset","int32",24,4,SX_NONE),
    SX_FIELD("cylinder_group_mask","int32",28,4,SX_FLAGS),
    SX_FIELD("old_write_time","int32",32,4,SX_TIME),
    SX_FIELD("old_fragment_count","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("old_data_fragment_count","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("cylinder_group_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("block_size","int32",48,4,SX_SIZE),
    SX_FIELD("fragment_size","int32",52,4,SX_SIZE),
    SX_FIELD("fragments_per_block","int32",56,4,SX_COUNT_PROP),
    SX_FIELD("min_free_percent","int32",60,4,SX_NONE),
    SX_FIELD("rotation_delay","int32",64,4,SX_NONE),
    SX_FIELD("revolutions_per_second","int32",68,4,SX_NONE),
    SX_FIELD("block_mask","int32",72,4,SX_FLAGS),
    SX_FIELD("fragment_mask","int32",76,4,SX_FLAGS),
    SX_FIELD("block_shift","int32",80,4,SX_NONE),
    SX_FIELD("fragment_shift","int32",84,4,SX_NONE),
    SX_FIELD("max_contiguous_blocks","int32",88,4,SX_COUNT_PROP),
    SX_FIELD("max_blocks_per_group","int32",92,4,SX_COUNT_PROP),
    SX_FIELD("fragments_shift","int32",96,4,SX_NONE),
    SX_FIELD("filesystem_to_disk_shift","int32",100,4,SX_NONE),
    SX_FIELD("superblock_size","int32",104,4,SX_SIZE),
    SX_FIELD("old_summary_mask","int32",108,4,SX_FLAGS),
    SX_FIELD("old_summary_shift","int32",112,4,SX_NONE),
    SX_FIELD("indirect_entries","int32",116,4,SX_COUNT_PROP),
    SX_FIELD("inodes_per_block","uint32",120,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_fragment","int32",124,4,SX_COUNT_PROP),
    SX_FIELD("optimization","int32",128,4,SX_ID),
    SX_FIELD("sectors_per_track_with_spares","int32",132,4,SX_COUNT_PROP),
    SX_FIELD("interleave","int32",136,4,SX_NONE),
    SX_FIELD("track_skew","int32",140,4,SX_NONE),
    SX_FIELD("filesystem_id","int32[2]",144,8,SX_ID),
    SX_FIELD("old_summary_fragment","int32",152,4,SX_NONE),
    SX_FIELD("summary_size","int32",156,4,SX_SIZE),
    SX_FIELD("cylinder_group_size","int32",160,4,SX_SIZE),
    SX_FIELD("old_tracks_per_cylinder","int32",164,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","int32",168,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_cylinder","int32",172,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","int32",176,4,SX_COUNT_PROP),
    SX_FIELD("cylinders_per_group","int32",180,4,SX_COUNT_PROP),
    SX_FIELD("inodes_per_group","uint32",184,4,SX_COUNT_PROP),
    SX_FIELD("fragments_per_group","int32",188,4,SX_COUNT_PROP),
    SX_FIELD("old_directory_count","int32",192,4,SX_COUNT_PROP),
    SX_FIELD("old_free_blocks","int32",196,4,SX_COUNT_PROP),
    SX_FIELD("old_free_inodes","int32",200,4,SX_COUNT_PROP),
    SX_FIELD("old_free_fragments","int32",204,4,SX_COUNT_PROP),
    SX_FIELD("modified","int8",208,1,SX_FLAGS),
    SX_FIELD("clean","int8",209,1,SX_FLAGS),
    SX_FIELD("read_only","int8",210,1,SX_FLAGS),
    SX_FIELD("old_flags","uint8",211,1,SX_FLAGS),
    SX_FIELD("mount_name","char[468]",212,468,SX_STRING),
    SX_FIELD("volume_name","char[32]",680,32,SX_STRING),
    SX_FIELD("system_uid","uint64",712,8,SX_ID),
    SX_FIELD("alignment_padding","int32",720,4,SX_RESERVED),
    SX_FIELD("cylinder_rotor","int32",724,4,SX_NONE),
    SX_FIELD("incore_pointer_padding","byte[128]",728,128,SX_NONE),
    SX_FIELD("old_cylinders_per_rotation","int32",856,4,SX_NONE),
    SX_FIELD("max_block_size","int32",860,4,SX_SIZE),
    SX_FIELD("unreferenced_inodes","int64",864,8,SX_COUNT_PROP),
    SX_FIELD("provider_fragments","int64",872,8,SX_COUNT_PROP),
    SX_FIELD("metadata_fragments","int64",880,8,SX_COUNT_PROP),
    SX_FIELD("saved_max_file_size","uint64",888,8,SX_SIZE),
    SX_FIELD("spare_constants64","int64[12]",896,96,SX_RESERVED),
    SX_FIELD("actual_superblock_offset","int64",992,8,SX_OFFSET),
    SX_FIELD("standard_superblock_offset","int64",1000,8,SX_OFFSET),
    SX_FIELD("directories","int64",1008,8,SX_COUNT_PROP),
    SX_FIELD("free_blocks","int64",1016,8,SX_COUNT_PROP),
    SX_FIELD("free_inodes","int64",1024,8,SX_COUNT_PROP),
    SX_FIELD("free_fragments","int64",1032,8,SX_COUNT_PROP),
    SX_FIELD("free_clusters","int64",1040,8,SX_COUNT_PROP),
    SX_FIELD("summary_spare","int64[3]",1048,24,SX_RESERVED),
    SX_FIELD("write_time","int64",1072,8,SX_TIME),
    SX_FIELD("fragment_count","int64",1080,8,SX_COUNT_PROP),
    SX_FIELD("data_fragment_count","int64",1088,8,SX_COUNT_PROP),
    SX_FIELD("summary_fragment","int64",1096,8,SX_NONE),
    SX_FIELD("pending_blocks","int64",1104,8,SX_COUNT_PROP),
    SX_FIELD("pending_inodes","uint32",1112,4,SX_COUNT_PROP),
    SX_FIELD("snapshot_inodes","uint32[20]",1116,80,SX_ID),
    SX_FIELD("average_file_size","uint32",1196,4,SX_SIZE),
    SX_FIELD("average_files_per_directory","uint32",1200,4,SX_COUNT_PROP),
    SX_FIELD("available_spare","uint32",1204,4,SX_RESERVED),
    SX_FIELD("mount_time","int64",1208,8,SX_TIME),
    SX_FIELD("suj_free_head","int32",1216,4,SX_ID),
    SX_FIELD("spare_constants32","int32[21]",1220,84,SX_RESERVED),
    SX_FIELD("checksum","uint32",1304,4,SX_CHECKSUM),
    SX_FIELD("metadata_checksum_flags","uint32",1308,4,SX_FLAGS),
    SX_FIELD("flags","int32",1312,4,SX_FLAGS),
    SX_FIELD("contiguous_summary_count","int32",1316,4,SX_COUNT_PROP),
    SX_FIELD("max_inline_symlink","int32",1320,4,SX_SIZE),
    SX_FIELD("inode_format","int32",1324,4,SX_ID),
    SX_FIELD("max_file_size","uint64",1328,8,SX_SIZE),
    SX_FIELD("block_mask64","int64",1336,8,SX_FLAGS),
    SX_FIELD("fragment_mask64","int64",1344,8,SX_FLAGS),
    SX_FIELD("state","int32",1352,4,SX_FLAGS),
    SX_FIELD("rotation_table_format","int32",1356,4,SX_ID),
    SX_FIELD("rotational_positions","int32",1360,4,SX_COUNT_PROP),
    SX_FIELD("rotation_position_offset","int32",1364,4,SX_OFFSET),
    SX_FIELD("rotation_block_offset","int32",1368,4,SX_OFFSET),
    SX_FIELD("magic","uint32",1372,4,SX_SIGNATURE),
};
static const sx_layout sxmf_ufs_modern_superblock_le = {0x6042004dU,"ufs_modern_superblock_le",sxmf_ufs_modern_superblock_le_fields,SX_COUNT(sxmf_ufs_modern_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_ufs_modern_superblock_be_fields[] = {
    SX_FIELD("first_field","int32",0,4,SX_NONE),
    SX_FIELD("unused1","int32",4,4,SX_RESERVED),
    SX_FIELD("superblock_fragment","int32",8,4,SX_NONE),
    SX_FIELD("cylinder_block_fragment","int32",12,4,SX_NONE),
    SX_FIELD("inode_block_fragment","int32",16,4,SX_NONE),
    SX_FIELD("data_block_fragment","int32",20,4,SX_NONE),
    SX_FIELD("cylinder_group_offset","int32",24,4,SX_NONE),
    SX_FIELD("cylinder_group_mask","int32",28,4,SX_FLAGS),
    SX_FIELD("old_write_time","int32",32,4,SX_TIME),
    SX_FIELD("old_fragment_count","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("old_data_fragment_count","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("cylinder_group_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("block_size","int32",48,4,SX_SIZE),
    SX_FIELD("fragment_size","int32",52,4,SX_SIZE),
    SX_FIELD("fragments_per_block","int32",56,4,SX_COUNT_PROP),
    SX_FIELD("min_free_percent","int32",60,4,SX_NONE),
    SX_FIELD("rotation_delay","int32",64,4,SX_NONE),
    SX_FIELD("revolutions_per_second","int32",68,4,SX_NONE),
    SX_FIELD("block_mask","int32",72,4,SX_FLAGS),
    SX_FIELD("fragment_mask","int32",76,4,SX_FLAGS),
    SX_FIELD("block_shift","int32",80,4,SX_NONE),
    SX_FIELD("fragment_shift","int32",84,4,SX_NONE),
    SX_FIELD("max_contiguous_blocks","int32",88,4,SX_COUNT_PROP),
    SX_FIELD("max_blocks_per_group","int32",92,4,SX_COUNT_PROP),
    SX_FIELD("fragments_shift","int32",96,4,SX_NONE),
    SX_FIELD("filesystem_to_disk_shift","int32",100,4,SX_NONE),
    SX_FIELD("superblock_size","int32",104,4,SX_SIZE),
    SX_FIELD("old_summary_mask","int32",108,4,SX_FLAGS),
    SX_FIELD("old_summary_shift","int32",112,4,SX_NONE),
    SX_FIELD("indirect_entries","int32",116,4,SX_COUNT_PROP),
    SX_FIELD("inodes_per_block","uint32",120,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_fragment","int32",124,4,SX_COUNT_PROP),
    SX_FIELD("optimization","int32",128,4,SX_ID),
    SX_FIELD("sectors_per_track_with_spares","int32",132,4,SX_COUNT_PROP),
    SX_FIELD("interleave","int32",136,4,SX_NONE),
    SX_FIELD("track_skew","int32",140,4,SX_NONE),
    SX_FIELD("filesystem_id","int32[2]",144,8,SX_ID),
    SX_FIELD("old_summary_fragment","int32",152,4,SX_NONE),
    SX_FIELD("summary_size","int32",156,4,SX_SIZE),
    SX_FIELD("cylinder_group_size","int32",160,4,SX_SIZE),
    SX_FIELD("old_tracks_per_cylinder","int32",164,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","int32",168,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_cylinder","int32",172,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","int32",176,4,SX_COUNT_PROP),
    SX_FIELD("cylinders_per_group","int32",180,4,SX_COUNT_PROP),
    SX_FIELD("inodes_per_group","uint32",184,4,SX_COUNT_PROP),
    SX_FIELD("fragments_per_group","int32",188,4,SX_COUNT_PROP),
    SX_FIELD("old_directory_count","int32",192,4,SX_COUNT_PROP),
    SX_FIELD("old_free_blocks","int32",196,4,SX_COUNT_PROP),
    SX_FIELD("old_free_inodes","int32",200,4,SX_COUNT_PROP),
    SX_FIELD("old_free_fragments","int32",204,4,SX_COUNT_PROP),
    SX_FIELD("modified","int8",208,1,SX_FLAGS),
    SX_FIELD("clean","int8",209,1,SX_FLAGS),
    SX_FIELD("read_only","int8",210,1,SX_FLAGS),
    SX_FIELD("old_flags","uint8",211,1,SX_FLAGS),
    SX_FIELD("mount_name","char[468]",212,468,SX_STRING),
    SX_FIELD("volume_name","char[32]",680,32,SX_STRING),
    SX_FIELD("system_uid","uint64",712,8,SX_ID),
    SX_FIELD("alignment_padding","int32",720,4,SX_RESERVED),
    SX_FIELD("cylinder_rotor","int32",724,4,SX_NONE),
    SX_FIELD("incore_pointer_padding","byte[128]",728,128,SX_NONE),
    SX_FIELD("old_cylinders_per_rotation","int32",856,4,SX_NONE),
    SX_FIELD("max_block_size","int32",860,4,SX_SIZE),
    SX_FIELD("unreferenced_inodes","int64",864,8,SX_COUNT_PROP),
    SX_FIELD("provider_fragments","int64",872,8,SX_COUNT_PROP),
    SX_FIELD("metadata_fragments","int64",880,8,SX_COUNT_PROP),
    SX_FIELD("saved_max_file_size","uint64",888,8,SX_SIZE),
    SX_FIELD("spare_constants64","int64[12]",896,96,SX_RESERVED),
    SX_FIELD("actual_superblock_offset","int64",992,8,SX_OFFSET),
    SX_FIELD("standard_superblock_offset","int64",1000,8,SX_OFFSET),
    SX_FIELD("directories","int64",1008,8,SX_COUNT_PROP),
    SX_FIELD("free_blocks","int64",1016,8,SX_COUNT_PROP),
    SX_FIELD("free_inodes","int64",1024,8,SX_COUNT_PROP),
    SX_FIELD("free_fragments","int64",1032,8,SX_COUNT_PROP),
    SX_FIELD("free_clusters","int64",1040,8,SX_COUNT_PROP),
    SX_FIELD("summary_spare","int64[3]",1048,24,SX_RESERVED),
    SX_FIELD("write_time","int64",1072,8,SX_TIME),
    SX_FIELD("fragment_count","int64",1080,8,SX_COUNT_PROP),
    SX_FIELD("data_fragment_count","int64",1088,8,SX_COUNT_PROP),
    SX_FIELD("summary_fragment","int64",1096,8,SX_NONE),
    SX_FIELD("pending_blocks","int64",1104,8,SX_COUNT_PROP),
    SX_FIELD("pending_inodes","uint32",1112,4,SX_COUNT_PROP),
    SX_FIELD("snapshot_inodes","uint32[20]",1116,80,SX_ID),
    SX_FIELD("average_file_size","uint32",1196,4,SX_SIZE),
    SX_FIELD("average_files_per_directory","uint32",1200,4,SX_COUNT_PROP),
    SX_FIELD("available_spare","uint32",1204,4,SX_RESERVED),
    SX_FIELD("mount_time","int64",1208,8,SX_TIME),
    SX_FIELD("suj_free_head","int32",1216,4,SX_ID),
    SX_FIELD("spare_constants32","int32[21]",1220,84,SX_RESERVED),
    SX_FIELD("checksum","uint32",1304,4,SX_CHECKSUM),
    SX_FIELD("metadata_checksum_flags","uint32",1308,4,SX_FLAGS),
    SX_FIELD("flags","int32",1312,4,SX_FLAGS),
    SX_FIELD("contiguous_summary_count","int32",1316,4,SX_COUNT_PROP),
    SX_FIELD("max_inline_symlink","int32",1320,4,SX_SIZE),
    SX_FIELD("inode_format","int32",1324,4,SX_ID),
    SX_FIELD("max_file_size","uint64",1328,8,SX_SIZE),
    SX_FIELD("block_mask64","int64",1336,8,SX_FLAGS),
    SX_FIELD("fragment_mask64","int64",1344,8,SX_FLAGS),
    SX_FIELD("state","int32",1352,4,SX_FLAGS),
    SX_FIELD("rotation_table_format","int32",1356,4,SX_ID),
    SX_FIELD("rotational_positions","int32",1360,4,SX_COUNT_PROP),
    SX_FIELD("rotation_position_offset","int32",1364,4,SX_OFFSET),
    SX_FIELD("rotation_block_offset","int32",1368,4,SX_OFFSET),
    SX_FIELD("magic","uint32",1372,4,SX_SIGNATURE),
};
static const sx_layout sxmf_ufs_modern_superblock_be = {0x6042004eU,"ufs_modern_superblock_be",sxmf_ufs_modern_superblock_be_fields,SX_COUNT(sxmf_ufs_modern_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_sufs_superblock_le_fields[] = {
    SX_FIELD("link","uint32",0,4,SX_NONE),
    SX_FIELD("rolled","uint32",4,4,SX_FLAGS),
    SX_FIELD("superblock_fragment","int32",8,4,SX_NONE),
    SX_FIELD("cylinder_block_fragment","int32",12,4,SX_NONE),
    SX_FIELD("inode_block_fragment","int32",16,4,SX_NONE),
    SX_FIELD("data_block_fragment","int32",20,4,SX_NONE),
    SX_FIELD("cylinder_group_offset","int32",24,4,SX_NONE),
    SX_FIELD("cylinder_group_mask","int32",28,4,SX_FLAGS),
    SX_FIELD("old_write_time","int32",32,4,SX_TIME),
    SX_FIELD("old_fragment_count","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("old_data_fragment_count","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("cylinder_group_count","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("block_size","int32",48,4,SX_SIZE),
    SX_FIELD("fragment_size","int32",52,4,SX_SIZE),
    SX_FIELD("fragments_per_block","int32",56,4,SX_COUNT_PROP),
    SX_FIELD("min_free_percent","int32",60,4,SX_NONE),
    SX_FIELD("rotation_delay","int32",64,4,SX_NONE),
    SX_FIELD("revolutions_per_second","int32",68,4,SX_NONE),
    SX_FIELD("block_mask","int32",72,4,SX_FLAGS),
    SX_FIELD("fragment_mask","int32",76,4,SX_FLAGS),
    SX_FIELD("block_shift","int32",80,4,SX_NONE),
    SX_FIELD("fragment_shift","int32",84,4,SX_NONE),
    SX_FIELD("max_contiguous_blocks","int32",88,4,SX_COUNT_PROP),
    SX_FIELD("max_blocks_per_group","int32",92,4,SX_COUNT_PROP),
    SX_FIELD("fragments_shift","int32",96,4,SX_NONE),
    SX_FIELD("filesystem_to_disk_shift","int32",100,4,SX_NONE),
    SX_FIELD("superblock_size","int32",104,4,SX_SIZE),
    SX_FIELD("old_summary_mask","int32",108,4,SX_FLAGS),
    SX_FIELD("old_summary_shift","int32",112,4,SX_NONE),
    SX_FIELD("indirect_entries","int32",116,4,SX_COUNT_PROP),
    SX_FIELD("inodes_per_block","int32",120,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_fragment","int32",124,4,SX_COUNT_PROP),
    SX_FIELD("optimization","int32",128,4,SX_ID),
    SX_FIELD("state","int32",132,4,SX_FLAGS),
    SX_FIELD("summary_state","int32",136,4,SX_FLAGS),
    SX_FIELD("track_skew","int32",140,4,SX_NONE),
    SX_FIELD("filesystem_id","int32[2]",144,8,SX_ID),
    SX_FIELD("old_summary_fragment","int32",152,4,SX_NONE),
    SX_FIELD("summary_size","int32",156,4,SX_SIZE),
    SX_FIELD("cylinder_group_size","int32",160,4,SX_SIZE),
    SX_FIELD("old_tracks_per_cylinder","int32",164,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","int32",168,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_cylinder","int32",172,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","int32",176,4,SX_COUNT_PROP),
    SX_FIELD("cylinders_per_group","int32",180,4,SX_COUNT_PROP),
    SX_FIELD("inodes_per_group","int32",184,4,SX_COUNT_PROP),
    SX_FIELD("fragments_per_group","int32",188,4,SX_COUNT_PROP),
    SX_FIELD("old_directory_count","int32",192,4,SX_COUNT_PROP),
    SX_FIELD("old_free_blocks","int32",196,4,SX_COUNT_PROP),
    SX_FIELD("old_free_inodes","int32",200,4,SX_COUNT_PROP),
    SX_FIELD("old_free_fragments","int32",204,4,SX_COUNT_PROP),
    SX_FIELD("modified","int8",208,1,SX_FLAGS),
    SX_FIELD("clean","int8",209,1,SX_FLAGS),
    SX_FIELD("read_only","int8",210,1,SX_FLAGS),
    SX_FIELD("flags","uint8",211,1,SX_FLAGS),
    SX_FIELD("mount_name","char[512]",212,512,SX_STRING),
    SX_FIELD("cylinder_rotor","int32",724,4,SX_NONE),
    SX_FIELD("incore_pointer_padding","byte[128]",728,128,SX_NONE),
    SX_FIELD("cylinders_per_rotation","int32",856,4,SX_NONE),
    SX_FIELD("old_rotation_table","int16[128]",860,256,SX_NONE),
    SX_FIELD("spare_constants","int32[51]",1116,204,SX_RESERVED),
    SX_FIELD("minor_version","int32",1320,4,SX_ID),
    SX_FIELD("log_block","int32",1324,4,SX_NONE),
    SX_FIELD("reclaim","int32",1328,4,SX_FLAGS),
    SX_FIELD("spare_constant","int32",1332,4,SX_RESERVED),
    SX_FIELD("sectors_per_track_with_spares","int32",1336,4,SX_COUNT_PROP),
    SX_FIELD("block_mask64","int64",1340,8,SX_FLAGS),
    SX_FIELD("fragment_mask64","int64",1348,8,SX_FLAGS),
    SX_FIELD("rotation_table_format","int32",1356,4,SX_ID),
    SX_FIELD("rotational_positions","int32",1360,4,SX_COUNT_PROP),
    SX_FIELD("rotation_position_offset","int32",1364,4,SX_OFFSET),
    SX_FIELD("rotation_block_offset","int32",1368,4,SX_OFFSET),
    SX_FIELD("magic","uint32",1372,4,SX_SIGNATURE),
};
static const sx_layout sxmf_sufs_superblock_le = {0x6042004fU,"sufs_superblock_le",sxmf_sufs_superblock_le_fields,SX_COUNT(sxmf_sufs_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_sufs_superblock_be_fields[] = {
    SX_FIELD("link","uint32",0,4,SX_NONE),
    SX_FIELD("rolled","uint32",4,4,SX_FLAGS),
    SX_FIELD("superblock_fragment","int32",8,4,SX_NONE),
    SX_FIELD("cylinder_block_fragment","int32",12,4,SX_NONE),
    SX_FIELD("inode_block_fragment","int32",16,4,SX_NONE),
    SX_FIELD("data_block_fragment","int32",20,4,SX_NONE),
    SX_FIELD("cylinder_group_offset","int32",24,4,SX_NONE),
    SX_FIELD("cylinder_group_mask","int32",28,4,SX_FLAGS),
    SX_FIELD("old_write_time","int32",32,4,SX_TIME),
    SX_FIELD("old_fragment_count","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("old_data_fragment_count","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("cylinder_group_count","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("block_size","int32",48,4,SX_SIZE),
    SX_FIELD("fragment_size","int32",52,4,SX_SIZE),
    SX_FIELD("fragments_per_block","int32",56,4,SX_COUNT_PROP),
    SX_FIELD("min_free_percent","int32",60,4,SX_NONE),
    SX_FIELD("rotation_delay","int32",64,4,SX_NONE),
    SX_FIELD("revolutions_per_second","int32",68,4,SX_NONE),
    SX_FIELD("block_mask","int32",72,4,SX_FLAGS),
    SX_FIELD("fragment_mask","int32",76,4,SX_FLAGS),
    SX_FIELD("block_shift","int32",80,4,SX_NONE),
    SX_FIELD("fragment_shift","int32",84,4,SX_NONE),
    SX_FIELD("max_contiguous_blocks","int32",88,4,SX_COUNT_PROP),
    SX_FIELD("max_blocks_per_group","int32",92,4,SX_COUNT_PROP),
    SX_FIELD("fragments_shift","int32",96,4,SX_NONE),
    SX_FIELD("filesystem_to_disk_shift","int32",100,4,SX_NONE),
    SX_FIELD("superblock_size","int32",104,4,SX_SIZE),
    SX_FIELD("old_summary_mask","int32",108,4,SX_FLAGS),
    SX_FIELD("old_summary_shift","int32",112,4,SX_NONE),
    SX_FIELD("indirect_entries","int32",116,4,SX_COUNT_PROP),
    SX_FIELD("inodes_per_block","int32",120,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_fragment","int32",124,4,SX_COUNT_PROP),
    SX_FIELD("optimization","int32",128,4,SX_ID),
    SX_FIELD("sectors_per_track_with_spares","int32",132,4,SX_COUNT_PROP),
    SX_FIELD("summary_state","int32",136,4,SX_FLAGS),
    SX_FIELD("track_skew","int32",140,4,SX_NONE),
    SX_FIELD("filesystem_id","int32[2]",144,8,SX_ID),
    SX_FIELD("old_summary_fragment","int32",152,4,SX_NONE),
    SX_FIELD("summary_size","int32",156,4,SX_SIZE),
    SX_FIELD("cylinder_group_size","int32",160,4,SX_SIZE),
    SX_FIELD("old_tracks_per_cylinder","int32",164,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","int32",168,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_cylinder","int32",172,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","int32",176,4,SX_COUNT_PROP),
    SX_FIELD("cylinders_per_group","int32",180,4,SX_COUNT_PROP),
    SX_FIELD("inodes_per_group","int32",184,4,SX_COUNT_PROP),
    SX_FIELD("fragments_per_group","int32",188,4,SX_COUNT_PROP),
    SX_FIELD("old_directory_count","int32",192,4,SX_COUNT_PROP),
    SX_FIELD("old_free_blocks","int32",196,4,SX_COUNT_PROP),
    SX_FIELD("old_free_inodes","int32",200,4,SX_COUNT_PROP),
    SX_FIELD("old_free_fragments","int32",204,4,SX_COUNT_PROP),
    SX_FIELD("modified","int8",208,1,SX_FLAGS),
    SX_FIELD("clean","int8",209,1,SX_FLAGS),
    SX_FIELD("read_only","int8",210,1,SX_FLAGS),
    SX_FIELD("flags","uint8",211,1,SX_FLAGS),
    SX_FIELD("mount_name","char[512]",212,512,SX_STRING),
    SX_FIELD("cylinder_rotor","int32",724,4,SX_NONE),
    SX_FIELD("incore_pointer_padding","byte[128]",728,128,SX_NONE),
    SX_FIELD("cylinders_per_rotation","int32",856,4,SX_NONE),
    SX_FIELD("old_rotation_table","int16[128]",860,256,SX_NONE),
    SX_FIELD("spare_constants","int32[51]",1116,204,SX_RESERVED),
    SX_FIELD("minor_version","int32",1320,4,SX_ID),
    SX_FIELD("log_block","int32",1324,4,SX_NONE),
    SX_FIELD("reclaim","int32",1328,4,SX_FLAGS),
    SX_FIELD("spare_constant","int32",1332,4,SX_RESERVED),
    SX_FIELD("state","int32",1336,4,SX_FLAGS),
    SX_FIELD("block_mask64","int64",1340,8,SX_FLAGS),
    SX_FIELD("fragment_mask64","int64",1348,8,SX_FLAGS),
    SX_FIELD("rotation_table_format","int32",1356,4,SX_ID),
    SX_FIELD("rotational_positions","int32",1360,4,SX_COUNT_PROP),
    SX_FIELD("rotation_position_offset","int32",1364,4,SX_OFFSET),
    SX_FIELD("rotation_block_offset","int32",1368,4,SX_OFFSET),
    SX_FIELD("magic","uint32",1372,4,SX_SIGNATURE),
};
static const sx_layout sxmf_sufs_superblock_be = {0x60420050U,"sufs_superblock_be",sxmf_sufs_superblock_be_fields,SX_COUNT(sxmf_sufs_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_ufs_cylinder_group_prefix_le_fields[] = {
    SX_FIELD("old_link","int32",0,4,SX_NONE),
    SX_FIELD("magic","uint32",4,4,SX_SIGNATURE),
    SX_FIELD("old_write_time","int32",8,4,SX_TIME),
    SX_FIELD("cylinder_group_index","uint32",12,4,SX_NONE),
    SX_FIELD("old_cylinder_count","int16",16,2,SX_COUNT_PROP),
    SX_FIELD("old_inode_blocks","int16",18,2,SX_COUNT_PROP),
    SX_FIELD("data_fragments","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("directory_count","int32",24,4,SX_COUNT_PROP),
    SX_FIELD("free_blocks","int32",28,4,SX_COUNT_PROP),
    SX_FIELD("free_inodes","int32",32,4,SX_COUNT_PROP),
    SX_FIELD("free_fragments","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("block_rotor","uint32",40,4,SX_NONE),
    SX_FIELD("fragment_rotor","uint32",44,4,SX_NONE),
    SX_FIELD("inode_rotor","uint32",48,4,SX_NONE),
    SX_FIELD("fragment_summary","uint32[8]",52,32,SX_COUNT_PROP),
    SX_FIELD("old_block_totals_offset","int32",84,4,SX_OFFSET),
    SX_FIELD("old_positions_offset","int32",88,4,SX_OFFSET),
    SX_FIELD("used_inode_map_offset","uint32",92,4,SX_OFFSET),
    SX_FIELD("free_fragment_map_offset","uint32",96,4,SX_OFFSET),
    SX_FIELD("next_free_offset","uint32",100,4,SX_OFFSET),
};
static const sx_layout sxmf_ufs_cylinder_group_prefix_le = {0x60420051U,"ufs_cylinder_group_prefix_le",sxmf_ufs_cylinder_group_prefix_le_fields,SX_COUNT(sxmf_ufs_cylinder_group_prefix_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_ufs_cylinder_group_prefix_be_fields[] = {
    SX_FIELD("old_link","int32",0,4,SX_NONE),
    SX_FIELD("magic","uint32",4,4,SX_SIGNATURE),
    SX_FIELD("old_write_time","int32",8,4,SX_TIME),
    SX_FIELD("cylinder_group_index","uint32",12,4,SX_NONE),
    SX_FIELD("old_cylinder_count","int16",16,2,SX_COUNT_PROP),
    SX_FIELD("old_inode_blocks","int16",18,2,SX_COUNT_PROP),
    SX_FIELD("data_fragments","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("directory_count","int32",24,4,SX_COUNT_PROP),
    SX_FIELD("free_blocks","int32",28,4,SX_COUNT_PROP),
    SX_FIELD("free_inodes","int32",32,4,SX_COUNT_PROP),
    SX_FIELD("free_fragments","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("block_rotor","uint32",40,4,SX_NONE),
    SX_FIELD("fragment_rotor","uint32",44,4,SX_NONE),
    SX_FIELD("inode_rotor","uint32",48,4,SX_NONE),
    SX_FIELD("fragment_summary","uint32[8]",52,32,SX_COUNT_PROP),
    SX_FIELD("old_block_totals_offset","int32",84,4,SX_OFFSET),
    SX_FIELD("old_positions_offset","int32",88,4,SX_OFFSET),
    SX_FIELD("used_inode_map_offset","uint32",92,4,SX_OFFSET),
    SX_FIELD("free_fragment_map_offset","uint32",96,4,SX_OFFSET),
    SX_FIELD("next_free_offset","uint32",100,4,SX_OFFSET),
};
static const sx_layout sxmf_ufs_cylinder_group_prefix_be = {0x60420052U,"ufs_cylinder_group_prefix_be",sxmf_ufs_cylinder_group_prefix_be_fields,SX_COUNT(sxmf_ufs_cylinder_group_prefix_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_ufs_cylinder_group_tail_le_fields[] = {
    SX_FIELD("cluster_summary_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("cluster_map_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("cluster_blocks","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("inode_blocks","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("initialized_inodes","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("unreferenced_inodes","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("reserved","int32",24,4,SX_RESERVED),
    SX_FIELD("checksum","uint32",28,4,SX_CHECKSUM),
    SX_FIELD("write_time","int64",32,8,SX_TIME),
    SX_FIELD("spare","int64[3]",40,24,SX_RESERVED),
};
static const sx_layout sxmf_ufs_cylinder_group_tail_le = {0x60420053U,"ufs_cylinder_group_tail_le",sxmf_ufs_cylinder_group_tail_le_fields,SX_COUNT(sxmf_ufs_cylinder_group_tail_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_ufs_cylinder_group_tail_be_fields[] = {
    SX_FIELD("cluster_summary_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("cluster_map_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("cluster_blocks","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("inode_blocks","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("initialized_inodes","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("unreferenced_inodes","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("reserved","int32",24,4,SX_RESERVED),
    SX_FIELD("checksum","uint32",28,4,SX_CHECKSUM),
    SX_FIELD("write_time","int64",32,8,SX_TIME),
    SX_FIELD("spare","int64[3]",40,24,SX_RESERVED),
};
static const sx_layout sxmf_ufs_cylinder_group_tail_be = {0x60420054U,"ufs_cylinder_group_tail_be",sxmf_ufs_cylinder_group_tail_be_fields,SX_COUNT(sxmf_ufs_cylinder_group_tail_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_ufs1_inode_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("free_link_or_directory_depth","uint32",4,4,SX_NONE),
    SX_FIELD("file_size","uint64",8,8,SX_SIZE),
    SX_FIELD("access_time","uint32",16,4,SX_TIME),
    SX_FIELD("access_nanoseconds","int32",20,4,SX_NONE),
    SX_FIELD("modification_time","uint32",24,4,SX_TIME),
    SX_FIELD("modification_nanoseconds","int32",28,4,SX_NONE),
    SX_FIELD("change_time","uint32",32,4,SX_TIME),
    SX_FIELD("change_nanoseconds","int32",36,4,SX_NONE),
    SX_FIELD("direct_fragments","int32[12]",40,48,SX_NONE),
    SX_FIELD("indirect_fragments","int32[3]",88,12,SX_NONE),
    SX_FIELD("flags","uint32",100,4,SX_FLAGS),
    SX_FIELD("allocated_sectors","uint32",104,4,SX_COUNT_PROP),
    SX_FIELD("generation","uint32",108,4,SX_NONE),
    SX_FIELD("uid","uint32",112,4,SX_ID),
    SX_FIELD("gid","uint32",116,4,SX_ID),
    SX_FIELD("modification_revision","uint64",120,8,SX_NONE),
};
static const sx_layout sxmf_ufs1_inode_le = {0x60420055U,"ufs1_inode_le",sxmf_ufs1_inode_le_fields,SX_COUNT(sxmf_ufs1_inode_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_ufs1_inode_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("free_link_or_directory_depth","uint32",4,4,SX_NONE),
    SX_FIELD("file_size","uint64",8,8,SX_SIZE),
    SX_FIELD("access_time","uint32",16,4,SX_TIME),
    SX_FIELD("access_nanoseconds","int32",20,4,SX_NONE),
    SX_FIELD("modification_time","uint32",24,4,SX_TIME),
    SX_FIELD("modification_nanoseconds","int32",28,4,SX_NONE),
    SX_FIELD("change_time","uint32",32,4,SX_TIME),
    SX_FIELD("change_nanoseconds","int32",36,4,SX_NONE),
    SX_FIELD("direct_fragments","int32[12]",40,48,SX_NONE),
    SX_FIELD("indirect_fragments","int32[3]",88,12,SX_NONE),
    SX_FIELD("flags","uint32",100,4,SX_FLAGS),
    SX_FIELD("allocated_sectors","uint32",104,4,SX_COUNT_PROP),
    SX_FIELD("generation","uint32",108,4,SX_NONE),
    SX_FIELD("uid","uint32",112,4,SX_ID),
    SX_FIELD("gid","uint32",116,4,SX_ID),
    SX_FIELD("modification_revision","uint64",120,8,SX_NONE),
};
static const sx_layout sxmf_ufs1_inode_be = {0x60420056U,"ufs1_inode_be",sxmf_ufs1_inode_be_fields,SX_COUNT(sxmf_ufs1_inode_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_ufs1_symlink_inode_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("free_link_or_directory_depth","uint32",4,4,SX_NONE),
    SX_FIELD("file_size","uint64",8,8,SX_SIZE),
    SX_FIELD("access_time","uint32",16,4,SX_TIME),
    SX_FIELD("access_nanoseconds","int32",20,4,SX_NONE),
    SX_FIELD("modification_time","uint32",24,4,SX_TIME),
    SX_FIELD("modification_nanoseconds","int32",28,4,SX_NONE),
    SX_FIELD("change_time","uint32",32,4,SX_TIME),
    SX_FIELD("change_nanoseconds","int32",36,4,SX_NONE),
    SX_FIELD("inline_symlink","char[60]",40,60,SX_STRING),
    SX_FIELD("flags","uint32",100,4,SX_FLAGS),
    SX_FIELD("allocated_sectors","uint32",104,4,SX_COUNT_PROP),
    SX_FIELD("generation","uint32",108,4,SX_NONE),
    SX_FIELD("uid","uint32",112,4,SX_ID),
    SX_FIELD("gid","uint32",116,4,SX_ID),
    SX_FIELD("modification_revision","uint64",120,8,SX_NONE),
};
static const sx_layout sxmf_ufs1_symlink_inode_le = {0x60420057U,"ufs1_symlink_inode_le",sxmf_ufs1_symlink_inode_le_fields,SX_COUNT(sxmf_ufs1_symlink_inode_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_ufs1_symlink_inode_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("free_link_or_directory_depth","uint32",4,4,SX_NONE),
    SX_FIELD("file_size","uint64",8,8,SX_SIZE),
    SX_FIELD("access_time","uint32",16,4,SX_TIME),
    SX_FIELD("access_nanoseconds","int32",20,4,SX_NONE),
    SX_FIELD("modification_time","uint32",24,4,SX_TIME),
    SX_FIELD("modification_nanoseconds","int32",28,4,SX_NONE),
    SX_FIELD("change_time","uint32",32,4,SX_TIME),
    SX_FIELD("change_nanoseconds","int32",36,4,SX_NONE),
    SX_FIELD("inline_symlink","char[60]",40,60,SX_STRING),
    SX_FIELD("flags","uint32",100,4,SX_FLAGS),
    SX_FIELD("allocated_sectors","uint32",104,4,SX_COUNT_PROP),
    SX_FIELD("generation","uint32",108,4,SX_NONE),
    SX_FIELD("uid","uint32",112,4,SX_ID),
    SX_FIELD("gid","uint32",116,4,SX_ID),
    SX_FIELD("modification_revision","uint64",120,8,SX_NONE),
};
static const sx_layout sxmf_ufs1_symlink_inode_be = {0x60420058U,"ufs1_symlink_inode_be",sxmf_ufs1_symlink_inode_be_fields,SX_COUNT(sxmf_ufs1_symlink_inode_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_ufs2_inode_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("uid","uint32",4,4,SX_ID),
    SX_FIELD("gid","uint32",8,4,SX_ID),
    SX_FIELD("block_size","uint32",12,4,SX_SIZE),
    SX_FIELD("file_size","uint64",16,8,SX_SIZE),
    SX_FIELD("allocated_sectors","uint64",24,8,SX_COUNT_PROP),
    SX_FIELD("access_time","int64",32,8,SX_TIME),
    SX_FIELD("modification_time","int64",40,8,SX_TIME),
    SX_FIELD("change_time","int64",48,8,SX_TIME),
    SX_FIELD("birth_time","int64",56,8,SX_TIME),
    SX_FIELD("modification_nanoseconds","int32",64,4,SX_NONE),
    SX_FIELD("access_nanoseconds","int32",68,4,SX_NONE),
    SX_FIELD("change_nanoseconds","int32",72,4,SX_NONE),
    SX_FIELD("birth_nanoseconds","int32",76,4,SX_NONE),
    SX_FIELD("generation","uint32",80,4,SX_NONE),
    SX_FIELD("kernel_flags","uint32",84,4,SX_FLAGS),
    SX_FIELD("flags","uint32",88,4,SX_FLAGS),
    SX_FIELD("xattr_size","uint32",92,4,SX_SIZE),
    SX_FIELD("xattr_fragments","int64[2]",96,16,SX_NONE),
    SX_FIELD("direct_fragments","int64[12]",112,96,SX_NONE),
    SX_FIELD("indirect_fragments","int64[3]",208,24,SX_NONE),
    SX_FIELD("modification_revision","uint64",232,8,SX_NONE),
    SX_FIELD("free_link_or_directory_depth","uint32",240,4,SX_NONE),
    SX_FIELD("checksum","uint32",244,4,SX_CHECKSUM),
    SX_FIELD("spare","uint32[2]",248,8,SX_RESERVED),
};
static const sx_layout sxmf_ufs2_inode_le = {0x60420059U,"ufs2_inode_le",sxmf_ufs2_inode_le_fields,SX_COUNT(sxmf_ufs2_inode_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_ufs2_inode_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("uid","uint32",4,4,SX_ID),
    SX_FIELD("gid","uint32",8,4,SX_ID),
    SX_FIELD("block_size","uint32",12,4,SX_SIZE),
    SX_FIELD("file_size","uint64",16,8,SX_SIZE),
    SX_FIELD("allocated_sectors","uint64",24,8,SX_COUNT_PROP),
    SX_FIELD("access_time","int64",32,8,SX_TIME),
    SX_FIELD("modification_time","int64",40,8,SX_TIME),
    SX_FIELD("change_time","int64",48,8,SX_TIME),
    SX_FIELD("birth_time","int64",56,8,SX_TIME),
    SX_FIELD("modification_nanoseconds","int32",64,4,SX_NONE),
    SX_FIELD("access_nanoseconds","int32",68,4,SX_NONE),
    SX_FIELD("change_nanoseconds","int32",72,4,SX_NONE),
    SX_FIELD("birth_nanoseconds","int32",76,4,SX_NONE),
    SX_FIELD("generation","uint32",80,4,SX_NONE),
    SX_FIELD("kernel_flags","uint32",84,4,SX_FLAGS),
    SX_FIELD("flags","uint32",88,4,SX_FLAGS),
    SX_FIELD("xattr_size","uint32",92,4,SX_SIZE),
    SX_FIELD("xattr_fragments","int64[2]",96,16,SX_NONE),
    SX_FIELD("direct_fragments","int64[12]",112,96,SX_NONE),
    SX_FIELD("indirect_fragments","int64[3]",208,24,SX_NONE),
    SX_FIELD("modification_revision","uint64",232,8,SX_NONE),
    SX_FIELD("free_link_or_directory_depth","uint32",240,4,SX_NONE),
    SX_FIELD("checksum","uint32",244,4,SX_CHECKSUM),
    SX_FIELD("spare","uint32[2]",248,8,SX_RESERVED),
};
static const sx_layout sxmf_ufs2_inode_be = {0x6042005aU,"ufs2_inode_be",sxmf_ufs2_inode_be_fields,SX_COUNT(sxmf_ufs2_inode_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_ufs2_symlink_inode_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("uid","uint32",4,4,SX_ID),
    SX_FIELD("gid","uint32",8,4,SX_ID),
    SX_FIELD("block_size","uint32",12,4,SX_SIZE),
    SX_FIELD("file_size","uint64",16,8,SX_SIZE),
    SX_FIELD("allocated_sectors","uint64",24,8,SX_COUNT_PROP),
    SX_FIELD("access_time","int64",32,8,SX_TIME),
    SX_FIELD("modification_time","int64",40,8,SX_TIME),
    SX_FIELD("change_time","int64",48,8,SX_TIME),
    SX_FIELD("birth_time","int64",56,8,SX_TIME),
    SX_FIELD("modification_nanoseconds","int32",64,4,SX_NONE),
    SX_FIELD("access_nanoseconds","int32",68,4,SX_NONE),
    SX_FIELD("change_nanoseconds","int32",72,4,SX_NONE),
    SX_FIELD("birth_nanoseconds","int32",76,4,SX_NONE),
    SX_FIELD("generation","uint32",80,4,SX_NONE),
    SX_FIELD("kernel_flags","uint32",84,4,SX_FLAGS),
    SX_FIELD("flags","uint32",88,4,SX_FLAGS),
    SX_FIELD("xattr_size","uint32",92,4,SX_SIZE),
    SX_FIELD("xattr_fragments","int64[2]",96,16,SX_NONE),
    SX_FIELD("inline_symlink","char[120]",112,120,SX_STRING),
    SX_FIELD("modification_revision","uint64",232,8,SX_NONE),
    SX_FIELD("free_link_or_directory_depth","uint32",240,4,SX_NONE),
    SX_FIELD("checksum","uint32",244,4,SX_CHECKSUM),
    SX_FIELD("spare","uint32[2]",248,8,SX_RESERVED),
};
static const sx_layout sxmf_ufs2_symlink_inode_le = {0x6042005bU,"ufs2_symlink_inode_le",sxmf_ufs2_symlink_inode_le_fields,SX_COUNT(sxmf_ufs2_symlink_inode_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_ufs2_symlink_inode_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("uid","uint32",4,4,SX_ID),
    SX_FIELD("gid","uint32",8,4,SX_ID),
    SX_FIELD("block_size","uint32",12,4,SX_SIZE),
    SX_FIELD("file_size","uint64",16,8,SX_SIZE),
    SX_FIELD("allocated_sectors","uint64",24,8,SX_COUNT_PROP),
    SX_FIELD("access_time","int64",32,8,SX_TIME),
    SX_FIELD("modification_time","int64",40,8,SX_TIME),
    SX_FIELD("change_time","int64",48,8,SX_TIME),
    SX_FIELD("birth_time","int64",56,8,SX_TIME),
    SX_FIELD("modification_nanoseconds","int32",64,4,SX_NONE),
    SX_FIELD("access_nanoseconds","int32",68,4,SX_NONE),
    SX_FIELD("change_nanoseconds","int32",72,4,SX_NONE),
    SX_FIELD("birth_nanoseconds","int32",76,4,SX_NONE),
    SX_FIELD("generation","uint32",80,4,SX_NONE),
    SX_FIELD("kernel_flags","uint32",84,4,SX_FLAGS),
    SX_FIELD("flags","uint32",88,4,SX_FLAGS),
    SX_FIELD("xattr_size","uint32",92,4,SX_SIZE),
    SX_FIELD("xattr_fragments","int64[2]",96,16,SX_NONE),
    SX_FIELD("inline_symlink","char[120]",112,120,SX_STRING),
    SX_FIELD("modification_revision","uint64",232,8,SX_NONE),
    SX_FIELD("free_link_or_directory_depth","uint32",240,4,SX_NONE),
    SX_FIELD("checksum","uint32",244,4,SX_CHECKSUM),
    SX_FIELD("spare","uint32[2]",248,8,SX_RESERVED),
};
static const sx_layout sxmf_ufs2_symlink_inode_be = {0x6042005cU,"ufs2_symlink_inode_be",sxmf_ufs2_symlink_inode_be_fields,SX_COUNT(sxmf_ufs2_symlink_inode_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_sufs_inode_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("short_uid","uint16",4,2,SX_ID),
    SX_FIELD("short_gid","uint16",6,2,SX_ID),
    SX_FIELD("file_size","uint64",8,8,SX_SIZE),
    SX_FIELD("access_time","int32",16,4,SX_TIME),
    SX_FIELD("access_microseconds","int32",20,4,SX_NONE),
    SX_FIELD("modification_time","int32",24,4,SX_TIME),
    SX_FIELD("modification_microseconds","int32",28,4,SX_NONE),
    SX_FIELD("change_time","int32",32,4,SX_TIME),
    SX_FIELD("change_microseconds","int32",36,4,SX_NONE),
    SX_FIELD("direct_fragments","int32[12]",40,48,SX_NONE),
    SX_FIELD("indirect_fragments","int32[3]",88,12,SX_NONE),
    SX_FIELD("flags","int32",100,4,SX_FLAGS),
    SX_FIELD("allocated_sectors","int32",104,4,SX_COUNT_PROP),
    SX_FIELD("generation","int32",108,4,SX_NONE),
    SX_FIELD("shadow_inode","int32",112,4,SX_ID),
    SX_FIELD("uid","uint32",116,4,SX_ID),
    SX_FIELD("gid","uint32",120,4,SX_ID),
    SX_FIELD("xattr_directory_inode","uint32",124,4,SX_ID),
};
static const sx_layout sxmf_sufs_inode_le = {0x6042005dU,"sufs_inode_le",sxmf_sufs_inode_le_fields,SX_COUNT(sxmf_sufs_inode_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_sufs_inode_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("short_uid","uint16",4,2,SX_ID),
    SX_FIELD("short_gid","uint16",6,2,SX_ID),
    SX_FIELD("file_size","uint64",8,8,SX_SIZE),
    SX_FIELD("access_time","int32",16,4,SX_TIME),
    SX_FIELD("access_microseconds","int32",20,4,SX_NONE),
    SX_FIELD("modification_time","int32",24,4,SX_TIME),
    SX_FIELD("modification_microseconds","int32",28,4,SX_NONE),
    SX_FIELD("change_time","int32",32,4,SX_TIME),
    SX_FIELD("change_microseconds","int32",36,4,SX_NONE),
    SX_FIELD("direct_fragments","int32[12]",40,48,SX_NONE),
    SX_FIELD("indirect_fragments","int32[3]",88,12,SX_NONE),
    SX_FIELD("flags","int32",100,4,SX_FLAGS),
    SX_FIELD("allocated_sectors","int32",104,4,SX_COUNT_PROP),
    SX_FIELD("generation","int32",108,4,SX_NONE),
    SX_FIELD("shadow_inode","int32",112,4,SX_ID),
    SX_FIELD("uid","uint32",116,4,SX_ID),
    SX_FIELD("gid","uint32",120,4,SX_ID),
    SX_FIELD("xattr_directory_inode","uint32",124,4,SX_ID),
};
static const sx_layout sxmf_sufs_inode_be = {0x6042005eU,"sufs_inode_be",sxmf_sufs_inode_be_fields,SX_COUNT(sxmf_sufs_inode_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_ufs_directory_entry_le_fields[] = {
    SX_FIELD("inode","uint32",0,4,SX_ID),
    SX_FIELD("record_length","uint16",4,2,SX_SIZE),
    SX_FIELD("type","uint8",6,1,SX_ID),
    SX_FIELD("name_length","uint8",7,1,SX_SIZE),
};
static const sx_layout sxmf_ufs_directory_entry_le = {0x6042005fU,"ufs_directory_entry_le",sxmf_ufs_directory_entry_le_fields,SX_COUNT(sxmf_ufs_directory_entry_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_ufs_directory_entry_be_fields[] = {
    SX_FIELD("inode","uint32",0,4,SX_ID),
    SX_FIELD("record_length","uint16",4,2,SX_SIZE),
    SX_FIELD("type","uint8",6,1,SX_ID),
    SX_FIELD("name_length","uint8",7,1,SX_SIZE),
};
static const sx_layout sxmf_ufs_directory_entry_be = {0x60420060U,"ufs_directory_entry_be",sxmf_ufs_directory_entry_be_fields,SX_COUNT(sxmf_ufs_directory_entry_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_sufs_directory_entry_le_fields[] = {
    SX_FIELD("inode","uint32",0,4,SX_ID),
    SX_FIELD("record_length","uint16",4,2,SX_SIZE),
    SX_FIELD("name_length","uint16",6,2,SX_SIZE),
};
static const sx_layout sxmf_sufs_directory_entry_le = {0x60420061U,"sufs_directory_entry_le",sxmf_sufs_directory_entry_le_fields,SX_COUNT(sxmf_sufs_directory_entry_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_sufs_directory_entry_be_fields[] = {
    SX_FIELD("inode","uint32",0,4,SX_ID),
    SX_FIELD("record_length","uint16",4,2,SX_SIZE),
    SX_FIELD("name_length","uint16",6,2,SX_SIZE),
};
static const sx_layout sxmf_sufs_directory_entry_be = {0x60420062U,"sufs_directory_entry_be",sxmf_sufs_directory_entry_be_fields,SX_COUNT(sxmf_sufs_directory_entry_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_ufs_fragment_pointer32_le_fields[] = {
    SX_FIELD("fragment","int32",0,4,SX_NONE),
};
static const sx_layout sxmf_ufs_fragment_pointer32_le = {0x60420063U,"ufs_fragment_pointer32_le",sxmf_ufs_fragment_pointer32_le_fields,SX_COUNT(sxmf_ufs_fragment_pointer32_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_ufs_fragment_pointer32_be_fields[] = {
    SX_FIELD("fragment","int32",0,4,SX_NONE),
};
static const sx_layout sxmf_ufs_fragment_pointer32_be = {0x60420064U,"ufs_fragment_pointer32_be",sxmf_ufs_fragment_pointer32_be_fields,SX_COUNT(sxmf_ufs_fragment_pointer32_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_ufs_fragment_pointer64_le_fields[] = {
    SX_FIELD("fragment","int64",0,8,SX_NONE),
};
static const sx_layout sxmf_ufs_fragment_pointer64_le = {0x60420065U,"ufs_fragment_pointer64_le",sxmf_ufs_fragment_pointer64_le_fields,SX_COUNT(sxmf_ufs_fragment_pointer64_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_ufs_fragment_pointer64_be_fields[] = {
    SX_FIELD("fragment","int64",0,8,SX_NONE),
};
static const sx_layout sxmf_ufs_fragment_pointer64_be = {0x60420066U,"ufs_fragment_pointer64_be",sxmf_ufs_fragment_pointer64_be_fields,SX_COUNT(sxmf_ufs_fragment_pointer64_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_vxfs1_superblock_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("creation_time","uint32",8,4,SX_TIME),
    SX_FIELD("creation_microseconds","uint32",12,4,SX_NONE),
    SX_FIELD("unused0","uint32[2]",16,8,SX_RESERVED),
    SX_FIELD("old_log_start","uint32",24,4,SX_NONE),
    SX_FIELD("old_log_end","uint32",28,4,SX_NONE),
    SX_FIELD("block_size","uint32",32,4,SX_SIZE),
    SX_FIELD("block_count","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("data_block_count","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("old_inode_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("old_allocation_units","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("unused1","uint32",52,4,SX_RESERVED),
    SX_FIELD("old_default_inode_extent_blocks","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("old_inode_list_block_size","uint32",60,4,SX_NONE),
    SX_FIELD("immediate_data_size","uint32",64,4,SX_SIZE),
    SX_FIELD("direct_extent_count","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("first_allocation_unit_block","uint32",72,4,SX_NONE),
    SX_FIELD("extent_map_block","uint32",76,4,SX_NONE),
    SX_FIELD("inode_map_block","uint32",80,4,SX_NONE),
    SX_FIELD("extent_operation_map_block","uint32",84,4,SX_NONE),
    SX_FIELD("inode_list_block","uint32",88,4,SX_NONE),
    SX_FIELD("free_data_block","uint32",92,4,SX_NONE),
    SX_FIELD("first_extent_map_block","uint32",96,4,SX_NONE),
    SX_FIELD("first_inode_map_block","uint32",100,4,SX_NONE),
    SX_FIELD("first_extent_operation_block","uint32",104,4,SX_NONE),
    SX_FIELD("first_inode_list_block","uint32",108,4,SX_NONE),
    SX_FIELD("first_free_data_block","uint32",112,4,SX_NONE),
    SX_FIELD("indirect_entries","uint32",116,4,SX_COUNT_PROP),
    SX_FIELD("allocation_unit_blocks","uint32",120,4,SX_COUNT_PROP),
    SX_FIELD("inode_map_blocks","uint32",124,4,SX_COUNT_PROP),
    SX_FIELD("extent_map_blocks","uint32",128,4,SX_COUNT_PROP),
    SX_FIELD("inode_list_blocks","uint32",132,4,SX_COUNT_PROP),
    SX_FIELD("padding_blocks","uint32",136,4,SX_COUNT_PROP),
    SX_FIELD("data_blocks_per_unit","uint32",140,4,SX_COUNT_PROP),
    SX_FIELD("max_tier","uint32",144,4,SX_NONE),
    SX_FIELD("inodes_per_block","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("old_inodes_per_unit","uint32",152,4,SX_COUNT_PROP),
    SX_FIELD("old_inodes_per_list_block","uint32",156,4,SX_COUNT_PROP),
    SX_FIELD("old_directory_inodes_per_unit","uint32",160,4,SX_COUNT_PROP),
    SX_FIELD("indirect_address_extent_blocks","uint32",164,4,SX_COUNT_PROP),
    SX_FIELD("block_shift","uint32",168,4,SX_NONE),
    SX_FIELD("inode_shift","uint32",172,4,SX_NONE),
    SX_FIELD("block_mask","uint32",176,4,SX_FLAGS),
    SX_FIELD("block_offset_mask","uint32",180,4,SX_FLAGS),
    SX_FIELD("old_inode_mask","uint32",184,4,SX_FLAGS),
    SX_FIELD("checksum","uint32",188,4,SX_CHECKSUM),
    SX_FIELD("free_blocks","uint32",192,4,SX_COUNT_PROP),
    SX_FIELD("free_inodes","uint32",196,4,SX_COUNT_PROP),
    SX_FIELD("free_extents_by_size","uint32[32]",200,128,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",328,4,SX_FLAGS),
    SX_FIELD("modified","uint8",332,1,SX_FLAGS),
    SX_FIELD("clean","uint8",333,1,SX_FLAGS),
    SX_FIELD("unused2","uint16",334,2,SX_RESERVED),
    SX_FIELD("first_log_id","uint32",336,4,SX_ID),
    SX_FIELD("write_time","uint32",340,4,SX_TIME),
    SX_FIELD("write_microseconds","uint32",344,4,SX_NONE),
    SX_FIELD("filesystem_name","char[6]",348,6,SX_STRING),
    SX_FIELD("pack_name","char[6]",354,6,SX_STRING),
    SX_FIELD("log_version","uint32",360,4,SX_ID),
    SX_FIELD("unused3","uint32",364,4,SX_RESERVED),
};
static const sx_layout sxmf_vxfs1_superblock_le = {0x60420067U,"vxfs1_superblock_le",sxmf_vxfs1_superblock_le_fields,SX_COUNT(sxmf_vxfs1_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_vxfs1_superblock_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("creation_time","uint32",8,4,SX_TIME),
    SX_FIELD("creation_microseconds","uint32",12,4,SX_NONE),
    SX_FIELD("unused0","uint32[2]",16,8,SX_RESERVED),
    SX_FIELD("old_log_start","uint32",24,4,SX_NONE),
    SX_FIELD("old_log_end","uint32",28,4,SX_NONE),
    SX_FIELD("block_size","uint32",32,4,SX_SIZE),
    SX_FIELD("block_count","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("data_block_count","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("old_inode_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("old_allocation_units","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("unused1","uint32",52,4,SX_RESERVED),
    SX_FIELD("old_default_inode_extent_blocks","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("old_inode_list_block_size","uint32",60,4,SX_NONE),
    SX_FIELD("immediate_data_size","uint32",64,4,SX_SIZE),
    SX_FIELD("direct_extent_count","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("first_allocation_unit_block","uint32",72,4,SX_NONE),
    SX_FIELD("extent_map_block","uint32",76,4,SX_NONE),
    SX_FIELD("inode_map_block","uint32",80,4,SX_NONE),
    SX_FIELD("extent_operation_map_block","uint32",84,4,SX_NONE),
    SX_FIELD("inode_list_block","uint32",88,4,SX_NONE),
    SX_FIELD("free_data_block","uint32",92,4,SX_NONE),
    SX_FIELD("first_extent_map_block","uint32",96,4,SX_NONE),
    SX_FIELD("first_inode_map_block","uint32",100,4,SX_NONE),
    SX_FIELD("first_extent_operation_block","uint32",104,4,SX_NONE),
    SX_FIELD("first_inode_list_block","uint32",108,4,SX_NONE),
    SX_FIELD("first_free_data_block","uint32",112,4,SX_NONE),
    SX_FIELD("indirect_entries","uint32",116,4,SX_COUNT_PROP),
    SX_FIELD("allocation_unit_blocks","uint32",120,4,SX_COUNT_PROP),
    SX_FIELD("inode_map_blocks","uint32",124,4,SX_COUNT_PROP),
    SX_FIELD("extent_map_blocks","uint32",128,4,SX_COUNT_PROP),
    SX_FIELD("inode_list_blocks","uint32",132,4,SX_COUNT_PROP),
    SX_FIELD("padding_blocks","uint32",136,4,SX_COUNT_PROP),
    SX_FIELD("data_blocks_per_unit","uint32",140,4,SX_COUNT_PROP),
    SX_FIELD("max_tier","uint32",144,4,SX_NONE),
    SX_FIELD("inodes_per_block","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("old_inodes_per_unit","uint32",152,4,SX_COUNT_PROP),
    SX_FIELD("old_inodes_per_list_block","uint32",156,4,SX_COUNT_PROP),
    SX_FIELD("old_directory_inodes_per_unit","uint32",160,4,SX_COUNT_PROP),
    SX_FIELD("indirect_address_extent_blocks","uint32",164,4,SX_COUNT_PROP),
    SX_FIELD("block_shift","uint32",168,4,SX_NONE),
    SX_FIELD("inode_shift","uint32",172,4,SX_NONE),
    SX_FIELD("block_mask","uint32",176,4,SX_FLAGS),
    SX_FIELD("block_offset_mask","uint32",180,4,SX_FLAGS),
    SX_FIELD("old_inode_mask","uint32",184,4,SX_FLAGS),
    SX_FIELD("checksum","uint32",188,4,SX_CHECKSUM),
    SX_FIELD("free_blocks","uint32",192,4,SX_COUNT_PROP),
    SX_FIELD("free_inodes","uint32",196,4,SX_COUNT_PROP),
    SX_FIELD("free_extents_by_size","uint32[32]",200,128,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",328,4,SX_FLAGS),
    SX_FIELD("modified","uint8",332,1,SX_FLAGS),
    SX_FIELD("clean","uint8",333,1,SX_FLAGS),
    SX_FIELD("unused2","uint16",334,2,SX_RESERVED),
    SX_FIELD("first_log_id","uint32",336,4,SX_ID),
    SX_FIELD("write_time","uint32",340,4,SX_TIME),
    SX_FIELD("write_microseconds","uint32",344,4,SX_NONE),
    SX_FIELD("filesystem_name","char[6]",348,6,SX_STRING),
    SX_FIELD("pack_name","char[6]",354,6,SX_STRING),
    SX_FIELD("log_version","uint32",360,4,SX_ID),
    SX_FIELD("unused3","uint32",364,4,SX_RESERVED),
};
static const sx_layout sxmf_vxfs1_superblock_be = {0x60420068U,"vxfs1_superblock_be",sxmf_vxfs1_superblock_be_fields,SX_COUNT(sxmf_vxfs1_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_vxfs2_superblock_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("creation_time","uint32",8,4,SX_TIME),
    SX_FIELD("creation_microseconds","uint32",12,4,SX_NONE),
    SX_FIELD("unused0","uint32[2]",16,8,SX_RESERVED),
    SX_FIELD("old_log_start","uint32",24,4,SX_NONE),
    SX_FIELD("old_log_end","uint32",28,4,SX_NONE),
    SX_FIELD("block_size","uint32",32,4,SX_SIZE),
    SX_FIELD("block_count","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("data_block_count","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("old_inode_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("old_allocation_units","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("unused1","uint32",52,4,SX_RESERVED),
    SX_FIELD("old_default_inode_extent_blocks","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("old_inode_list_block_size","uint32",60,4,SX_NONE),
    SX_FIELD("immediate_data_size","uint32",64,4,SX_SIZE),
    SX_FIELD("direct_extent_count","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("first_allocation_unit_block","uint32",72,4,SX_NONE),
    SX_FIELD("extent_map_block","uint32",76,4,SX_NONE),
    SX_FIELD("inode_map_block","uint32",80,4,SX_NONE),
    SX_FIELD("extent_operation_map_block","uint32",84,4,SX_NONE),
    SX_FIELD("inode_list_block","uint32",88,4,SX_NONE),
    SX_FIELD("free_data_block","uint32",92,4,SX_NONE),
    SX_FIELD("first_extent_map_block","uint32",96,4,SX_NONE),
    SX_FIELD("first_inode_map_block","uint32",100,4,SX_NONE),
    SX_FIELD("first_extent_operation_block","uint32",104,4,SX_NONE),
    SX_FIELD("first_inode_list_block","uint32",108,4,SX_NONE),
    SX_FIELD("first_free_data_block","uint32",112,4,SX_NONE),
    SX_FIELD("indirect_entries","uint32",116,4,SX_COUNT_PROP),
    SX_FIELD("allocation_unit_blocks","uint32",120,4,SX_COUNT_PROP),
    SX_FIELD("inode_map_blocks","uint32",124,4,SX_COUNT_PROP),
    SX_FIELD("extent_map_blocks","uint32",128,4,SX_COUNT_PROP),
    SX_FIELD("inode_list_blocks","uint32",132,4,SX_COUNT_PROP),
    SX_FIELD("padding_blocks","uint32",136,4,SX_COUNT_PROP),
    SX_FIELD("data_blocks_per_unit","uint32",140,4,SX_COUNT_PROP),
    SX_FIELD("max_tier","uint32",144,4,SX_NONE),
    SX_FIELD("inodes_per_block","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("old_inodes_per_unit","uint32",152,4,SX_COUNT_PROP),
    SX_FIELD("old_inodes_per_list_block","uint32",156,4,SX_COUNT_PROP),
    SX_FIELD("old_directory_inodes_per_unit","uint32",160,4,SX_COUNT_PROP),
    SX_FIELD("indirect_address_extent_blocks","uint32",164,4,SX_COUNT_PROP),
    SX_FIELD("block_shift","uint32",168,4,SX_NONE),
    SX_FIELD("inode_shift","uint32",172,4,SX_NONE),
    SX_FIELD("block_mask","uint32",176,4,SX_FLAGS),
    SX_FIELD("block_offset_mask","uint32",180,4,SX_FLAGS),
    SX_FIELD("old_inode_mask","uint32",184,4,SX_FLAGS),
    SX_FIELD("checksum","uint32",188,4,SX_CHECKSUM),
    SX_FIELD("free_blocks","uint32",192,4,SX_COUNT_PROP),
    SX_FIELD("free_inodes","uint32",196,4,SX_COUNT_PROP),
    SX_FIELD("free_extents_by_size","uint32[32]",200,128,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",328,4,SX_FLAGS),
    SX_FIELD("modified","uint8",332,1,SX_FLAGS),
    SX_FIELD("clean","uint8",333,1,SX_FLAGS),
    SX_FIELD("unused2","uint16",334,2,SX_RESERVED),
    SX_FIELD("first_log_id","uint32",336,4,SX_ID),
    SX_FIELD("write_time","uint32",340,4,SX_TIME),
    SX_FIELD("write_microseconds","uint32",344,4,SX_NONE),
    SX_FIELD("filesystem_name","char[6]",348,6,SX_STRING),
    SX_FIELD("pack_name","char[6]",354,6,SX_STRING),
    SX_FIELD("log_version","uint32",360,4,SX_ID),
    SX_FIELD("unused3","uint32",364,4,SX_RESERVED),
    SX_FIELD("object_location_extents","uint32[2]",368,8,SX_NONE),
    SX_FIELD("object_location_extent_blocks","uint32",376,4,SX_COUNT_PROP),
    SX_FIELD("inode_allocation_map_blocks","uint32",380,4,SX_COUNT_PROP),
    SX_FIELD("inode_allocation_unit_blocks","uint32",384,4,SX_COUNT_PROP),
    SX_FIELD("inode_size","uint32",388,4,SX_SIZE),
    SX_FIELD("old_indirect_levels","uint32",392,4,SX_COUNT_PROP),
    SX_FIELD("checksum2","uint32",396,4,SX_CHECKSUM),
};
static const sx_layout sxmf_vxfs2_superblock_le = {0x60420069U,"vxfs2_superblock_le",sxmf_vxfs2_superblock_le_fields,SX_COUNT(sxmf_vxfs2_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_vxfs2_superblock_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("creation_time","uint32",8,4,SX_TIME),
    SX_FIELD("creation_microseconds","uint32",12,4,SX_NONE),
    SX_FIELD("unused0","uint32[2]",16,8,SX_RESERVED),
    SX_FIELD("old_log_start","uint32",24,4,SX_NONE),
    SX_FIELD("old_log_end","uint32",28,4,SX_NONE),
    SX_FIELD("block_size","uint32",32,4,SX_SIZE),
    SX_FIELD("block_count","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("data_block_count","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("old_inode_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("old_allocation_units","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("unused1","uint32",52,4,SX_RESERVED),
    SX_FIELD("old_default_inode_extent_blocks","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("old_inode_list_block_size","uint32",60,4,SX_NONE),
    SX_FIELD("immediate_data_size","uint32",64,4,SX_SIZE),
    SX_FIELD("direct_extent_count","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("first_allocation_unit_block","uint32",72,4,SX_NONE),
    SX_FIELD("extent_map_block","uint32",76,4,SX_NONE),
    SX_FIELD("inode_map_block","uint32",80,4,SX_NONE),
    SX_FIELD("extent_operation_map_block","uint32",84,4,SX_NONE),
    SX_FIELD("inode_list_block","uint32",88,4,SX_NONE),
    SX_FIELD("free_data_block","uint32",92,4,SX_NONE),
    SX_FIELD("first_extent_map_block","uint32",96,4,SX_NONE),
    SX_FIELD("first_inode_map_block","uint32",100,4,SX_NONE),
    SX_FIELD("first_extent_operation_block","uint32",104,4,SX_NONE),
    SX_FIELD("first_inode_list_block","uint32",108,4,SX_NONE),
    SX_FIELD("first_free_data_block","uint32",112,4,SX_NONE),
    SX_FIELD("indirect_entries","uint32",116,4,SX_COUNT_PROP),
    SX_FIELD("allocation_unit_blocks","uint32",120,4,SX_COUNT_PROP),
    SX_FIELD("inode_map_blocks","uint32",124,4,SX_COUNT_PROP),
    SX_FIELD("extent_map_blocks","uint32",128,4,SX_COUNT_PROP),
    SX_FIELD("inode_list_blocks","uint32",132,4,SX_COUNT_PROP),
    SX_FIELD("padding_blocks","uint32",136,4,SX_COUNT_PROP),
    SX_FIELD("data_blocks_per_unit","uint32",140,4,SX_COUNT_PROP),
    SX_FIELD("max_tier","uint32",144,4,SX_NONE),
    SX_FIELD("inodes_per_block","uint32",148,4,SX_COUNT_PROP),
    SX_FIELD("old_inodes_per_unit","uint32",152,4,SX_COUNT_PROP),
    SX_FIELD("old_inodes_per_list_block","uint32",156,4,SX_COUNT_PROP),
    SX_FIELD("old_directory_inodes_per_unit","uint32",160,4,SX_COUNT_PROP),
    SX_FIELD("indirect_address_extent_blocks","uint32",164,4,SX_COUNT_PROP),
    SX_FIELD("block_shift","uint32",168,4,SX_NONE),
    SX_FIELD("inode_shift","uint32",172,4,SX_NONE),
    SX_FIELD("block_mask","uint32",176,4,SX_FLAGS),
    SX_FIELD("block_offset_mask","uint32",180,4,SX_FLAGS),
    SX_FIELD("old_inode_mask","uint32",184,4,SX_FLAGS),
    SX_FIELD("checksum","uint32",188,4,SX_CHECKSUM),
    SX_FIELD("free_blocks","uint32",192,4,SX_COUNT_PROP),
    SX_FIELD("free_inodes","uint32",196,4,SX_COUNT_PROP),
    SX_FIELD("free_extents_by_size","uint32[32]",200,128,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",328,4,SX_FLAGS),
    SX_FIELD("modified","uint8",332,1,SX_FLAGS),
    SX_FIELD("clean","uint8",333,1,SX_FLAGS),
    SX_FIELD("unused2","uint16",334,2,SX_RESERVED),
    SX_FIELD("first_log_id","uint32",336,4,SX_ID),
    SX_FIELD("write_time","uint32",340,4,SX_TIME),
    SX_FIELD("write_microseconds","uint32",344,4,SX_NONE),
    SX_FIELD("filesystem_name","char[6]",348,6,SX_STRING),
    SX_FIELD("pack_name","char[6]",354,6,SX_STRING),
    SX_FIELD("log_version","uint32",360,4,SX_ID),
    SX_FIELD("unused3","uint32",364,4,SX_RESERVED),
    SX_FIELD("object_location_extents","uint32[2]",368,8,SX_NONE),
    SX_FIELD("object_location_extent_blocks","uint32",376,4,SX_COUNT_PROP),
    SX_FIELD("inode_allocation_map_blocks","uint32",380,4,SX_COUNT_PROP),
    SX_FIELD("inode_allocation_unit_blocks","uint32",384,4,SX_COUNT_PROP),
    SX_FIELD("inode_size","uint32",388,4,SX_SIZE),
    SX_FIELD("old_indirect_levels","uint32",392,4,SX_COUNT_PROP),
    SX_FIELD("checksum2","uint32",396,4,SX_CHECKSUM),
};
static const sx_layout sxmf_vxfs2_superblock_be = {0x6042006aU,"vxfs2_superblock_be",sxmf_vxfs2_superblock_be_fields,SX_COUNT(sxmf_vxfs2_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_vmfs_volume_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("unknown0","byte[6]",8,6,SX_NONE),
    SX_FIELD("lun","uint8",14,1,SX_ID),
    SX_FIELD("unknown1","byte[3]",15,3,SX_NONE),
    SX_FIELD("name","char[28]",18,28,SX_STRING),
    SX_FIELD("lun_identity","byte[49]",46,49,SX_NONE),
    SX_FIELD("size_units","uint32",95,4,SX_NONE),
    SX_FIELD("unknown2","byte[31]",99,31,SX_NONE),
    SX_FIELD("uuid","byte[16]",130,16,SX_ID),
    SX_FIELD("creation_time","uint64",146,8,SX_NONE),
    SX_FIELD("modification_time","uint64",154,8,SX_NONE),
};
static const sx_layout sxmf_vmfs_volume_header = {0x6042006bU,"vmfs_volume_header",sxmf_vmfs_volume_header_fields,SX_COUNT(sxmf_vmfs_volume_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_vmfs35_lvm_header_fields[] = {
    SX_FIELD("size","uint64",0,8,SX_SIZE),
    SX_FIELD("blocks","uint64",8,8,SX_NONE),
    SX_FIELD("unknown0","uint32",16,4,SX_NONE),
    SX_FIELD("uuid_string","char[35]",20,35,SX_STRING),
    SX_FIELD("unknown1","byte[29]",55,29,SX_NONE),
    SX_FIELD("uuid","byte[16]",84,16,SX_ID),
    SX_FIELD("unknown2","uint32",100,4,SX_NONE),
    SX_FIELD("creation_time","uint64",104,8,SX_NONE),
    SX_FIELD("unknown3","uint32",112,4,SX_NONE),
    SX_FIELD("segment_count","uint32",116,4,SX_COUNT_PROP),
    SX_FIELD("first_segment","uint32",120,4,SX_NONE),
    SX_FIELD("unknown4","uint32",124,4,SX_NONE),
    SX_FIELD("last_segment","uint32",128,4,SX_NONE),
    SX_FIELD("unknown5","uint32",132,4,SX_NONE),
    SX_FIELD("modification_time","uint64",136,8,SX_NONE),
    SX_FIELD("extent_count","uint32",144,4,SX_COUNT_PROP),
};
static const sx_layout sxmf_vmfs35_lvm_header = {0x6042006cU,"vmfs35_lvm_header",sxmf_vmfs35_lvm_header_fields,SX_COUNT(sxmf_vmfs35_lvm_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_vmfs35_filesystem_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("volume_version","uint32",4,4,SX_ID),
    SX_FIELD("version","uint8",8,1,SX_ID),
    SX_FIELD("uuid","byte[16]",9,16,SX_ID),
    SX_FIELD("mode","uint32",25,4,SX_FLAGS),
    SX_FIELD("label","char[128]",29,128,SX_STRING),
    SX_FIELD("device_block_size","uint32",157,4,SX_SIZE),
    SX_FIELD("block_size","uint64",161,8,SX_SIZE),
    SX_FIELD("creation_time","uint32",169,4,SX_TIME),
    SX_FIELD("unknown3","uint32",173,4,SX_NONE),
    SX_FIELD("lvm_uuid","byte[16]",177,16,SX_ID),
    SX_FIELD("unknown4","byte[16]",193,16,SX_NONE),
    SX_FIELD("fdc_header_size","uint32",209,4,SX_SIZE),
    SX_FIELD("fdc_bitmap_count","uint32",213,4,SX_COUNT_PROP),
    SX_FIELD("subblock_size","uint32",217,4,SX_SIZE),
};
static const sx_layout sxmf_vmfs35_filesystem_header = {0x6042006dU,"vmfs35_filesystem_header",sxmf_vmfs35_filesystem_header_fields,SX_COUNT(sxmf_vmfs35_filesystem_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_vmfs35_bitmap_header_fields[] = {
    SX_FIELD("items_per_entry","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("entries_per_area","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("data_size","uint32",12,4,SX_SIZE),
    SX_FIELD("area_size","uint32",16,4,SX_SIZE),
    SX_FIELD("total_items","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("area_count","uint32",24,4,SX_COUNT_PROP),
};
static const sx_layout sxmf_vmfs35_bitmap_header = {0x6042006eU,"vmfs35_bitmap_header",sxmf_vmfs35_bitmap_header_fields,SX_COUNT(sxmf_vmfs35_bitmap_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_vmfs35_inode_data_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_ID),
    SX_FIELD("id2","uint32",4,4,SX_ID),
    SX_FIELD("link_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("type","uint32",12,4,SX_ID),
    SX_FIELD("flags","uint32",16,4,SX_FLAGS),
    SX_FIELD("file_size","uint64",20,8,SX_SIZE),
    SX_FIELD("block_size","uint64",28,8,SX_SIZE),
    SX_FIELD("block_count","uint64",36,8,SX_COUNT_PROP),
    SX_FIELD("modification_time","uint32",44,4,SX_TIME),
    SX_FIELD("change_time","uint32",48,4,SX_TIME),
    SX_FIELD("access_time","uint32",52,4,SX_TIME),
    SX_FIELD("uid","uint32",56,4,SX_ID),
    SX_FIELD("gid","uint32",60,4,SX_ID),
    SX_FIELD("mode","uint32",64,4,SX_FLAGS),
    SX_FIELD("allocation_format","uint32",68,4,SX_ID),
    SX_FIELD("tbz","uint32",72,4,SX_NONE),
    SX_FIELD("copy_on_write","uint32",76,4,SX_FLAGS),
    SX_FIELD("unknown","byte[432]",80,432,SX_NONE),
};
static const sx_layout sxmf_vmfs35_inode_data = {0x6042006fU,"vmfs35_inode_data",sxmf_vmfs35_inode_data_fields,SX_COUNT(sxmf_vmfs35_inode_data_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_vmfs35_directory_entry_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("block_id","uint32",4,4,SX_ID),
    SX_FIELD("record_id","uint32",8,4,SX_ID),
    SX_FIELD("name","char[128]",12,128,SX_STRING),
};
static const sx_layout sxmf_vmfs35_directory_entry = {0x60420070U,"vmfs35_directory_entry",sxmf_vmfs35_directory_entry_fields,SX_COUNT(sxmf_vmfs35_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_vmfs35_block_id_fields[] = {
    SX_FIELD("block_id","uint32",0,4,SX_FLAGS),
};
static const sx_layout sxmf_vmfs35_block_id = {0x60420071U,"vmfs35_block_id",sxmf_vmfs35_block_id_fields,SX_COUNT(sxmf_vmfs35_block_id_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_reiser4_master_fields[] = {
    SX_FIELD("magic","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("format_plugin","uint16",16,2,SX_ID),
    SX_FIELD("block_size","uint16",18,2,SX_SIZE),
    SX_FIELD("uuid","byte[16]",20,16,SX_ID),
    SX_FIELD("label","char[16]",36,16,SX_STRING),
};
static const sx_layout sxmf_reiser4_master = {0x60420072U,"reiser4_master",sxmf_reiser4_master_fields,SX_COUNT(sxmf_reiser4_master_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_reiser4_format40_superblock_fields[] = {
    SX_FIELD("block_count","uint64",0,8,SX_COUNT_PROP),
    SX_FIELD("free_blocks","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("root_block","uint64",16,8,SX_NONE),
    SX_FIELD("object_id_state","uint64[2]",24,16,SX_NONE),
    SX_FIELD("flush_count","uint64",40,8,SX_COUNT_PROP),
    SX_FIELD("mkfs_id","uint32",48,4,SX_ID),
    SX_FIELD("magic","char[16]",52,16,SX_SIGNATURE),
    SX_FIELD("tree_height","uint16",68,2,SX_COUNT_PROP),
    SX_FIELD("allocation_policy","uint16",70,2,SX_ID),
    SX_FIELD("flags","uint64",72,8,SX_FLAGS),
    SX_FIELD("version","uint32",80,4,SX_ID),
    SX_FIELD("node_plugin","uint32",84,4,SX_ID),
    SX_FIELD("reserved","byte[424]",88,424,SX_RESERVED),
};
static const sx_layout sxmf_reiser4_format40_superblock = {0x60420073U,"reiser4_format40_superblock",sxmf_reiser4_format40_superblock_fields,SX_COUNT(sxmf_reiser4_format40_superblock_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_reiser4_node40_header_fields[] = {
    SX_FIELD("plugin","uint16",0,2,SX_ID),
    SX_FIELD("item_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("free_space","uint16",4,2,SX_SIZE),
    SX_FIELD("free_space_start","uint16",6,2,SX_OFFSET),
    SX_FIELD("magic","uint32",8,4,SX_SIGNATURE),
    SX_FIELD("mkfs_id","uint32",12,4,SX_ID),
    SX_FIELD("flush_id","uint64",16,8,SX_NONE),
    SX_FIELD("flags","uint16",24,2,SX_FLAGS),
    SX_FIELD("level","uint8",26,1,SX_NONE),
    SX_FIELD("padding","uint8",27,1,SX_RESERVED),
};
static const sx_layout sxmf_reiser4_node40_header = {0x60420074U,"reiser4_node40_header",sxmf_reiser4_node40_header_fields,SX_COUNT(sxmf_reiser4_node40_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_reiser4_item_header_large_fields[] = {
    SX_FIELD("locality_and_type","uint64",0,8,SX_FLAGS),
    SX_FIELD("ordering","uint64",8,8,SX_NONE),
    SX_FIELD("object_and_type","uint64",16,8,SX_FLAGS),
    SX_FIELD("offset","uint64",24,8,SX_NONE),
    SX_FIELD("data_offset","uint16",32,2,SX_OFFSET),
    SX_FIELD("flags","uint16",34,2,SX_FLAGS),
    SX_FIELD("plugin","uint16",36,2,SX_ID),
};
static const sx_layout sxmf_reiser4_item_header_large = {0x60420075U,"reiser4_item_header_large",sxmf_reiser4_item_header_large_fields,SX_COUNT(sxmf_reiser4_item_header_large_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_reiser4_child_fields[] = {
    SX_FIELD("block","uint64",0,8,SX_NONE),
};
static const sx_layout sxmf_reiser4_child = {0x60420076U,"reiser4_child",sxmf_reiser4_child_fields,SX_COUNT(sxmf_reiser4_child_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_reiser4_extent_fields[] = {
    SX_FIELD("block","uint64",0,8,SX_NONE),
    SX_FIELD("block_count","uint64",8,8,SX_COUNT_PROP),
};
static const sx_layout sxmf_reiser4_extent = {0x60420077U,"reiser4_extent",sxmf_reiser4_extent_fields,SX_COUNT(sxmf_reiser4_extent_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hammer_node_header_le_fields[] = {
    SX_FIELD("crc","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("reserved0","uint32",4,4,SX_RESERVED),
    SX_FIELD("parent","uint64",8,8,SX_POINTER),
    SX_FIELD("count","int32",16,4,SX_COUNT_PROP),
    SX_FIELD("type","uint8",20,1,SX_ID),
    SX_FIELD("reserved1","uint8",21,1,SX_RESERVED),
    SX_FIELD("reserved2","uint16",22,2,SX_RESERVED),
    SX_FIELD("reserved3","uint64[4]",24,32,SX_RESERVED),
    SX_FIELD("mirror_transaction","uint64",56,8,SX_NONE),
};
static const sx_layout sxmf_hammer_node_header_le = {0x60420078U,"hammer_node_header_le",sxmf_hammer_node_header_le_fields,SX_COUNT(sxmf_hammer_node_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hammer_node_header_be_fields[] = {
    SX_FIELD("crc","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("reserved0","uint32",4,4,SX_RESERVED),
    SX_FIELD("parent","uint64",8,8,SX_POINTER),
    SX_FIELD("count","int32",16,4,SX_COUNT_PROP),
    SX_FIELD("type","uint8",20,1,SX_ID),
    SX_FIELD("reserved1","uint8",21,1,SX_RESERVED),
    SX_FIELD("reserved2","uint16",22,2,SX_RESERVED),
    SX_FIELD("reserved3","uint64[4]",24,32,SX_RESERVED),
    SX_FIELD("mirror_transaction","uint64",56,8,SX_NONE),
};
static const sx_layout sxmf_hammer_node_header_be = {0x60420079U,"hammer_node_header_be",sxmf_hammer_node_header_be_fields,SX_COUNT(sxmf_hammer_node_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_hammer_internal_record_le_fields[] = {
    SX_FIELD("object_id","int64",0,8,SX_ID),
    SX_FIELD("key","int64",8,8,SX_NONE),
    SX_FIELD("create_transaction","uint64",16,8,SX_NONE),
    SX_FIELD("delete_transaction","uint64",24,8,SX_NONE),
    SX_FIELD("record_type","uint16",32,2,SX_ID),
    SX_FIELD("object_type","uint8",34,1,SX_ID),
    SX_FIELD("btree_type","uint8",35,1,SX_ID),
    SX_FIELD("localization","uint32",36,4,SX_FLAGS),
    SX_FIELD("mirror_transaction","uint64",40,8,SX_NONE),
    SX_FIELD("subtree","uint64",48,8,SX_POINTER),
    SX_FIELD("reserved","int32[2]",56,8,SX_RESERVED),
};
static const sx_layout sxmf_hammer_internal_record_le = {0x6042007aU,"hammer_internal_record_le",sxmf_hammer_internal_record_le_fields,SX_COUNT(sxmf_hammer_internal_record_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hammer_internal_record_be_fields[] = {
    SX_FIELD("object_id","int64",0,8,SX_ID),
    SX_FIELD("key","int64",8,8,SX_NONE),
    SX_FIELD("create_transaction","uint64",16,8,SX_NONE),
    SX_FIELD("delete_transaction","uint64",24,8,SX_NONE),
    SX_FIELD("record_type","uint16",32,2,SX_ID),
    SX_FIELD("object_type","uint8",34,1,SX_ID),
    SX_FIELD("btree_type","uint8",35,1,SX_ID),
    SX_FIELD("localization","uint32",36,4,SX_FLAGS),
    SX_FIELD("mirror_transaction","uint64",40,8,SX_NONE),
    SX_FIELD("subtree","uint64",48,8,SX_POINTER),
    SX_FIELD("reserved","int32[2]",56,8,SX_RESERVED),
};
static const sx_layout sxmf_hammer_internal_record_be = {0x6042007bU,"hammer_internal_record_be",sxmf_hammer_internal_record_be_fields,SX_COUNT(sxmf_hammer_internal_record_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_hammer_leaf_record_le_fields[] = {
    SX_FIELD("object_id","int64",0,8,SX_ID),
    SX_FIELD("key","int64",8,8,SX_NONE),
    SX_FIELD("create_transaction","uint64",16,8,SX_NONE),
    SX_FIELD("delete_transaction","uint64",24,8,SX_NONE),
    SX_FIELD("record_type","uint16",32,2,SX_ID),
    SX_FIELD("object_type","uint8",34,1,SX_ID),
    SX_FIELD("btree_type","uint8",35,1,SX_ID),
    SX_FIELD("localization","uint32",36,4,SX_FLAGS),
    SX_FIELD("creation_time","uint32",40,4,SX_TIME),
    SX_FIELD("deletion_time","uint32",44,4,SX_TIME),
    SX_FIELD("data_address","uint64",48,8,SX_POINTER),
    SX_FIELD("data_length","int32",56,4,SX_SIZE),
    SX_FIELD("data_crc","uint32",60,4,SX_CHECKSUM),
};
static const sx_layout sxmf_hammer_leaf_record_le = {0x6042007cU,"hammer_leaf_record_le",sxmf_hammer_leaf_record_le_fields,SX_COUNT(sxmf_hammer_leaf_record_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hammer_leaf_record_be_fields[] = {
    SX_FIELD("object_id","int64",0,8,SX_ID),
    SX_FIELD("key","int64",8,8,SX_NONE),
    SX_FIELD("create_transaction","uint64",16,8,SX_NONE),
    SX_FIELD("delete_transaction","uint64",24,8,SX_NONE),
    SX_FIELD("record_type","uint16",32,2,SX_ID),
    SX_FIELD("object_type","uint8",34,1,SX_ID),
    SX_FIELD("btree_type","uint8",35,1,SX_ID),
    SX_FIELD("localization","uint32",36,4,SX_FLAGS),
    SX_FIELD("creation_time","uint32",40,4,SX_TIME),
    SX_FIELD("deletion_time","uint32",44,4,SX_TIME),
    SX_FIELD("data_address","uint64",48,8,SX_POINTER),
    SX_FIELD("data_length","int32",56,4,SX_SIZE),
    SX_FIELD("data_crc","uint32",60,4,SX_CHECKSUM),
};
static const sx_layout sxmf_hammer_leaf_record_be = {0x6042007dU,"hammer_leaf_record_be",sxmf_hammer_leaf_record_be_fields,SX_COUNT(sxmf_hammer_leaf_record_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_hammer_inode_le_fields[] = {
    SX_FIELD("version","uint16",0,2,SX_ID),
    SX_FIELD("mode","uint16",2,2,SX_FLAGS),
    SX_FIELD("user_flags","uint32",4,4,SX_FLAGS),
    SX_FIELD("device_major","uint32",8,4,SX_ID),
    SX_FIELD("device_minor","uint32",12,4,SX_ID),
    SX_FIELD("change_time","uint64",16,8,SX_TIME),
    SX_FIELD("parent_object","int64",24,8,SX_ID),
    SX_FIELD("uid","byte[16]",32,16,SX_ID),
    SX_FIELD("gid","byte[16]",48,16,SX_ID),
    SX_FIELD("type","uint8",64,1,SX_ID),
    SX_FIELD("capabilities","uint8",65,1,SX_FLAGS),
    SX_FIELD("reserved0","uint16",66,2,SX_RESERVED),
    SX_FIELD("reserved1","uint32",68,4,SX_RESERVED),
    SX_FIELD("link_count","uint64",72,8,SX_COUNT_PROP),
    SX_FIELD("file_size","uint64",80,8,SX_SIZE),
    SX_FIELD("inline_extension","byte[24]",88,24,SX_NONE),
    SX_FIELD("modification_time","uint64",112,8,SX_TIME),
    SX_FIELD("access_time","uint64",120,8,SX_TIME),
};
static const sx_layout sxmf_hammer_inode_le = {0x6042007eU,"hammer_inode_le",sxmf_hammer_inode_le_fields,SX_COUNT(sxmf_hammer_inode_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hammer_inode_be_fields[] = {
    SX_FIELD("version","uint16",0,2,SX_ID),
    SX_FIELD("mode","uint16",2,2,SX_FLAGS),
    SX_FIELD("user_flags","uint32",4,4,SX_FLAGS),
    SX_FIELD("device_major","uint32",8,4,SX_ID),
    SX_FIELD("device_minor","uint32",12,4,SX_ID),
    SX_FIELD("change_time","uint64",16,8,SX_TIME),
    SX_FIELD("parent_object","int64",24,8,SX_ID),
    SX_FIELD("uid","byte[16]",32,16,SX_ID),
    SX_FIELD("gid","byte[16]",48,16,SX_ID),
    SX_FIELD("type","uint8",64,1,SX_ID),
    SX_FIELD("capabilities","uint8",65,1,SX_FLAGS),
    SX_FIELD("reserved0","uint16",66,2,SX_RESERVED),
    SX_FIELD("reserved1","uint32",68,4,SX_RESERVED),
    SX_FIELD("link_count","uint64",72,8,SX_COUNT_PROP),
    SX_FIELD("file_size","uint64",80,8,SX_SIZE),
    SX_FIELD("inline_extension","byte[24]",88,24,SX_NONE),
    SX_FIELD("modification_time","uint64",112,8,SX_TIME),
    SX_FIELD("access_time","uint64",120,8,SX_TIME),
};
static const sx_layout sxmf_hammer_inode_be = {0x6042007fU,"hammer_inode_be",sxmf_hammer_inode_be_fields,SX_COUNT(sxmf_hammer_inode_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_hammer_directory_entry_le_fields[] = {
    SX_FIELD("object_id","int64",0,8,SX_ID),
    SX_FIELD("localization","uint32",8,4,SX_FLAGS),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxmf_hammer_directory_entry_le = {0x60420080U,"hammer_directory_entry_le",sxmf_hammer_directory_entry_le_fields,SX_COUNT(sxmf_hammer_directory_entry_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_hammer_directory_entry_be_fields[] = {
    SX_FIELD("object_id","int64",0,8,SX_ID),
    SX_FIELD("localization","uint32",8,4,SX_FLAGS),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxmf_hammer_directory_entry_be = {0x60420081U,"hammer_directory_entry_be",sxmf_hammer_directory_entry_be_fields,SX_COUNT(sxmf_hammer_directory_entry_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_cdi_volume_descriptor_fields[] = {
    SX_FIELD("record_type","uint8",0,1,SX_ID),
    SX_FIELD("standard_id","char[5]",1,5,SX_SIGNATURE),
    SX_FIELD("version","uint8",6,1,SX_ID),
    SX_FIELD("flags","uint8",7,1,SX_FLAGS),
    SX_FIELD("system_id","char[32]",8,32,SX_STRING),
    SX_FIELD("volume_id","char[32]",40,32,SX_STRING),
    SX_FIELD("reserved0","byte[12]",72,12,SX_RESERVED),
    SX_FIELD("volume_blocks","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("character_set","char[32]",88,32,SX_STRING),
    SX_FIELD("reserved1","uint16",120,2,SX_RESERVED),
    SX_FIELD("album_volume_count","uint16",122,2,SX_COUNT_PROP),
    SX_FIELD("reserved2","uint16",124,2,SX_RESERVED),
    SX_FIELD("album_sequence","uint16",126,2,SX_NONE),
    SX_FIELD("reserved3","uint16",128,2,SX_RESERVED),
    SX_FIELD("logical_block_size","uint16",130,2,SX_SIZE),
    SX_FIELD("reserved4","uint32",132,4,SX_RESERVED),
    SX_FIELD("path_table_size","uint32",136,4,SX_SIZE),
    SX_FIELD("reserved5","byte[8]",140,8,SX_RESERVED),
    SX_FIELD("path_table_block","uint32",148,4,SX_NONE),
    SX_FIELD("reserved6","byte[38]",152,38,SX_RESERVED),
    SX_FIELD("album_id","char[128]",190,128,SX_STRING),
    SX_FIELD("publisher","char[128]",318,128,SX_STRING),
    SX_FIELD("data_preparer","char[128]",446,128,SX_STRING),
    SX_FIELD("application_id","char[128]",574,128,SX_STRING),
    SX_FIELD("copyright_file","char[32]",702,32,SX_STRING),
    SX_FIELD("reserved7","byte[5]",734,5,SX_RESERVED),
    SX_FIELD("abstract_file","char[32]",739,32,SX_STRING),
    SX_FIELD("reserved8","byte[5]",771,5,SX_RESERVED),
    SX_FIELD("bibliography_file","char[32]",776,32,SX_STRING),
    SX_FIELD("reserved9","byte[5]",808,5,SX_RESERVED),
    SX_FIELD("creation_date","char[16]",813,16,SX_NONE),
    SX_FIELD("reserved10","uint8",829,1,SX_RESERVED),
    SX_FIELD("modification_date","char[16]",830,16,SX_NONE),
    SX_FIELD("reserved11","uint8",846,1,SX_RESERVED),
    SX_FIELD("expiration_date","char[16]",847,16,SX_NONE),
    SX_FIELD("reserved12","uint8",863,1,SX_RESERVED),
    SX_FIELD("effective_date","char[16]",864,16,SX_NONE),
    SX_FIELD("reserved13","uint8",880,1,SX_RESERVED),
    SX_FIELD("structure_version","uint8",881,1,SX_ID),
    SX_FIELD("reserved14","uint8",882,1,SX_RESERVED),
    SX_FIELD("application_use","byte[512]",883,512,SX_NONE),
    SX_FIELD("reserved15","byte[653]",1395,653,SX_RESERVED),
};
static const sx_layout sxmf_cdi_volume_descriptor = {0x60420082U,"cdi_volume_descriptor",sxmf_cdi_volume_descriptor_fields,SX_COUNT(sxmf_cdi_volume_descriptor_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_cdi_terminator_fields[] = {
    SX_FIELD("record_type","uint8",0,1,SX_ID),
    SX_FIELD("standard_id","char[5]",1,5,SX_SIGNATURE),
    SX_FIELD("version","uint8",6,1,SX_ID),
    SX_FIELD("reserved","byte[2041]",7,2041,SX_RESERVED),
};
static const sx_layout sxmf_cdi_terminator = {0x60420083U,"cdi_terminator",sxmf_cdi_terminator_fields,SX_COUNT(sxmf_cdi_terminator_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_cdi_path_entry_fields[] = {
    SX_FIELD("name_length","uint8",0,1,SX_SIZE),
    SX_FIELD("extended_attribute_blocks","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("directory_block","uint32",2,4,SX_NONE),
    SX_FIELD("parent_directory_number","uint16",6,2,SX_NONE),
};
static const sx_layout sxmf_cdi_path_entry = {0x60420084U,"cdi_path_entry",sxmf_cdi_path_entry_fields,SX_COUNT(sxmf_cdi_path_entry_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_cdi_directory_entry_fields[] = {
    SX_FIELD("record_length","uint8",0,1,SX_SIZE),
    SX_FIELD("extended_attribute_blocks","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("reserved0","uint32",2,4,SX_RESERVED),
    SX_FIELD("file_block","uint32",6,4,SX_NONE),
    SX_FIELD("reserved1","uint32",10,4,SX_RESERVED),
    SX_FIELD("file_size","uint32",14,4,SX_SIZE),
    SX_FIELD("year_since_1900","uint8",18,1,SX_NONE),
    SX_FIELD("month","uint8",19,1,SX_NONE),
    SX_FIELD("day","uint8",20,1,SX_NONE),
    SX_FIELD("hour","uint8",21,1,SX_NONE),
    SX_FIELD("minute","uint8",22,1,SX_NONE),
    SX_FIELD("second","uint8",23,1,SX_NONE),
    SX_FIELD("reserved2","uint8",24,1,SX_RESERVED),
    SX_FIELD("flags","uint8",25,1,SX_FLAGS),
    SX_FIELD("interleave_unit_sectors","uint8",26,1,SX_COUNT_PROP),
    SX_FIELD("interleave_gap_sectors","uint8",27,1,SX_COUNT_PROP),
    SX_FIELD("reserved3","uint16",28,2,SX_RESERVED),
    SX_FIELD("album_sequence","uint16",30,2,SX_NONE),
    SX_FIELD("name_length","uint8",32,1,SX_SIZE),
};
static const sx_layout sxmf_cdi_directory_entry = {0x60420085U,"cdi_directory_entry",sxmf_cdi_directory_entry_fields,SX_COUNT(sxmf_cdi_directory_entry_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_cdi_directory_attributes_fields[] = {
    SX_FIELD("group_id","uint16",0,2,SX_ID),
    SX_FIELD("user_id","uint16",2,2,SX_ID),
    SX_FIELD("attributes","uint16",4,2,SX_FLAGS),
    SX_FIELD("reserved0","uint16",6,2,SX_RESERVED),
    SX_FIELD("file_number","uint8",8,1,SX_ID),
    SX_FIELD("reserved1","uint8",9,1,SX_RESERVED),
};
static const sx_layout sxmf_cdi_directory_attributes = {0x60420086U,"cdi_directory_attributes",sxmf_cdi_directory_attributes_fields,SX_COUNT(sxmf_cdi_directory_attributes_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_cdi_mode2_sector_header_fields[] = {
    SX_FIELD("sync","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("minute_bcd","uint8",12,1,SX_NONE),
    SX_FIELD("second_bcd","uint8",13,1,SX_NONE),
    SX_FIELD("frame_bcd","uint8",14,1,SX_NONE),
    SX_FIELD("mode","uint8",15,1,SX_ID),
    SX_FIELD("file_number","uint8",16,1,SX_ID),
    SX_FIELD("channel_number","uint8",17,1,SX_ID),
    SX_FIELD("submode","uint8",18,1,SX_FLAGS),
    SX_FIELD("coding_information","uint8",19,1,SX_FLAGS),
    SX_FIELD("repeated_file_number","uint8",20,1,SX_ID),
    SX_FIELD("repeated_channel_number","uint8",21,1,SX_ID),
    SX_FIELD("repeated_submode","uint8",22,1,SX_FLAGS),
    SX_FIELD("repeated_coding_information","uint8",23,1,SX_FLAGS),
};
static const sx_layout sxmf_cdi_mode2_sector_header = {0x60420087U,"cdi_mode2_sector_header",sxmf_cdi_mode2_sector_header_fields,SX_COUNT(sxmf_cdi_mode2_sector_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_cdi_form1_edc_fields[] = {
    SX_FIELD("crc","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxmf_cdi_form1_edc = {0x60420088U,"cdi_form1_edc",sxmf_cdi_form1_edc_fields,SX_COUNT(sxmf_cdi_form1_edc_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_vmfs35_metadata_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("position","uint64",4,8,SX_OFFSET),
    SX_FIELD("heartbeat_position","uint64",12,8,SX_OFFSET),
    SX_FIELD("heartbeat_sequence","uint64",20,8,SX_NONE),
    SX_FIELD("object_sequence","uint64",28,8,SX_NONE),
    SX_FIELD("heartbeat_lock","uint32",36,4,SX_FLAGS),
    SX_FIELD("heartbeat_uuid","byte[16]",40,16,SX_ID),
    SX_FIELD("modification_time","uint64",56,8,SX_NONE),
    SX_FIELD("padding","byte[448]",64,448,SX_NONE),
};
static const sx_layout sxmf_vmfs35_metadata_header = {0x60420089U,"vmfs35_metadata_header",sxmf_vmfs35_metadata_header_fields,SX_COUNT(sxmf_vmfs35_metadata_header_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_sfs_file_object_fields[] = {
    SX_FIELD("owner_uid","uint16",0,2,SX_ID),
    SX_FIELD("owner_gid","uint16",2,2,SX_ID),
    SX_FIELD("object_node","uint32",4,4,SX_ID),
    SX_FIELD("protection","uint32",8,4,SX_FLAGS),
    SX_FIELD("data_block","uint32",12,4,SX_NONE),
    SX_FIELD("file_size","uint32",16,4,SX_SIZE),
    SX_FIELD("modification_time","uint32",20,4,SX_TIME),
    SX_FIELD("type","uint8",24,1,SX_FLAGS),
};
static const sx_layout sxmf_sfs_file_object = {0x6042008aU,"sfs_file_object",sxmf_sfs_file_object_fields,SX_COUNT(sxmf_sfs_file_object_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_sfs_directory_object_fields[] = {
    SX_FIELD("owner_uid","uint16",0,2,SX_ID),
    SX_FIELD("owner_gid","uint16",2,2,SX_ID),
    SX_FIELD("object_node","uint32",4,4,SX_ID),
    SX_FIELD("protection","uint32",8,4,SX_FLAGS),
    SX_FIELD("hash_table_block","uint32",12,4,SX_NONE),
    SX_FIELD("first_directory_block","uint32",16,4,SX_NONE),
    SX_FIELD("modification_time","uint32",20,4,SX_TIME),
    SX_FIELD("type","uint8",24,1,SX_FLAGS),
};
static const sx_layout sxmf_sfs_directory_object = {0x6042008bU,"sfs_directory_object",sxmf_sfs_directory_object_fields,SX_COUNT(sxmf_sfs_directory_object_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_ufs1_legacy_inode_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("old_uid_gid_or_inode","byte[4]",4,4,SX_NONE),
    SX_FIELD("file_size","uint64",8,8,SX_SIZE),
    SX_FIELD("access_time","int32",16,4,SX_TIME),
    SX_FIELD("access_nanoseconds","int32",20,4,SX_NONE),
    SX_FIELD("modification_time","int32",24,4,SX_TIME),
    SX_FIELD("modification_nanoseconds","int32",28,4,SX_NONE),
    SX_FIELD("change_time","int32",32,4,SX_TIME),
    SX_FIELD("change_nanoseconds","int32",36,4,SX_NONE),
    SX_FIELD("direct_fragments","int32[12]",40,48,SX_NONE),
    SX_FIELD("indirect_fragments","int32[3]",88,12,SX_NONE),
    SX_FIELD("flags","uint32",100,4,SX_FLAGS),
    SX_FIELD("allocated_sectors","uint32",104,4,SX_COUNT_PROP),
    SX_FIELD("generation","uint32",108,4,SX_NONE),
    SX_FIELD("uid","uint32",112,4,SX_ID),
    SX_FIELD("gid","uint32",116,4,SX_ID),
    SX_FIELD("spare","int32[2]",120,8,SX_RESERVED),
};
static const sx_layout sxmf_ufs1_legacy_inode_le = {0x6042008cU,"ufs1_legacy_inode_le",sxmf_ufs1_legacy_inode_le_fields,SX_COUNT(sxmf_ufs1_legacy_inode_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_ufs1_legacy_inode_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("old_uid_gid_or_inode","byte[4]",4,4,SX_NONE),
    SX_FIELD("file_size","uint64",8,8,SX_SIZE),
    SX_FIELD("access_time","int32",16,4,SX_TIME),
    SX_FIELD("access_nanoseconds","int32",20,4,SX_NONE),
    SX_FIELD("modification_time","int32",24,4,SX_TIME),
    SX_FIELD("modification_nanoseconds","int32",28,4,SX_NONE),
    SX_FIELD("change_time","int32",32,4,SX_TIME),
    SX_FIELD("change_nanoseconds","int32",36,4,SX_NONE),
    SX_FIELD("direct_fragments","int32[12]",40,48,SX_NONE),
    SX_FIELD("indirect_fragments","int32[3]",88,12,SX_NONE),
    SX_FIELD("flags","uint32",100,4,SX_FLAGS),
    SX_FIELD("allocated_sectors","uint32",104,4,SX_COUNT_PROP),
    SX_FIELD("generation","uint32",108,4,SX_NONE),
    SX_FIELD("uid","uint32",112,4,SX_ID),
    SX_FIELD("gid","uint32",116,4,SX_ID),
    SX_FIELD("spare","int32[2]",120,8,SX_RESERVED),
};
static const sx_layout sxmf_ufs1_legacy_inode_be = {0x6042008dU,"ufs1_legacy_inode_be",sxmf_ufs1_legacy_inode_be_fields,SX_COUNT(sxmf_ufs1_legacy_inode_be_fields),SX_BE};

static const xx_data_struct_field_desc sxmf_ufs1_legacy_symlink_inode_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("old_uid_gid_or_inode","byte[4]",4,4,SX_NONE),
    SX_FIELD("file_size","uint64",8,8,SX_SIZE),
    SX_FIELD("access_time","int32",16,4,SX_TIME),
    SX_FIELD("access_nanoseconds","int32",20,4,SX_NONE),
    SX_FIELD("modification_time","int32",24,4,SX_TIME),
    SX_FIELD("modification_nanoseconds","int32",28,4,SX_NONE),
    SX_FIELD("change_time","int32",32,4,SX_TIME),
    SX_FIELD("change_nanoseconds","int32",36,4,SX_NONE),
    SX_FIELD("inline_symlink","char[60]",40,60,SX_STRING),
    SX_FIELD("flags","uint32",100,4,SX_FLAGS),
    SX_FIELD("allocated_sectors","uint32",104,4,SX_COUNT_PROP),
    SX_FIELD("generation","uint32",108,4,SX_NONE),
    SX_FIELD("uid","uint32",112,4,SX_ID),
    SX_FIELD("gid","uint32",116,4,SX_ID),
    SX_FIELD("spare","int32[2]",120,8,SX_RESERVED),
};
static const sx_layout sxmf_ufs1_legacy_symlink_inode_le = {0x6042008eU,"ufs1_legacy_symlink_inode_le",sxmf_ufs1_legacy_symlink_inode_le_fields,SX_COUNT(sxmf_ufs1_legacy_symlink_inode_le_fields),SX_LE};

static const xx_data_struct_field_desc sxmf_ufs1_legacy_symlink_inode_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("old_uid_gid_or_inode","byte[4]",4,4,SX_NONE),
    SX_FIELD("file_size","uint64",8,8,SX_SIZE),
    SX_FIELD("access_time","int32",16,4,SX_TIME),
    SX_FIELD("access_nanoseconds","int32",20,4,SX_NONE),
    SX_FIELD("modification_time","int32",24,4,SX_TIME),
    SX_FIELD("modification_nanoseconds","int32",28,4,SX_NONE),
    SX_FIELD("change_time","int32",32,4,SX_TIME),
    SX_FIELD("change_nanoseconds","int32",36,4,SX_NONE),
    SX_FIELD("inline_symlink","char[60]",40,60,SX_STRING),
    SX_FIELD("flags","uint32",100,4,SX_FLAGS),
    SX_FIELD("allocated_sectors","uint32",104,4,SX_COUNT_PROP),
    SX_FIELD("generation","uint32",108,4,SX_NONE),
    SX_FIELD("uid","uint32",112,4,SX_ID),
    SX_FIELD("gid","uint32",116,4,SX_ID),
    SX_FIELD("spare","int32[2]",120,8,SX_RESERVED),
};
static const sx_layout sxmf_ufs1_legacy_symlink_inode_be = {0x6042008fU,"ufs1_legacy_symlink_inode_be",sxmf_ufs1_legacy_symlink_inode_be_fields,SX_COUNT(sxmf_ufs1_legacy_symlink_inode_be_fields),SX_BE};

static const sx_layout *const sx_modernfs_layouts[] = {
    &sxmf_refs_volume_header,
    &sxmf_fossil_header,
    &sxmf_fossil_superblock,
    &sxmf_fossil_label,
    &sxmf_jfs_superblock,
    &sxmf_nilfs2_superblock,
    &sxmf_nilfs2_inode,
    &sxmf_nilfs2_super_root_header,
    &sxmf_nilfs2_segment_summary,
    &sxmf_nilfs2_file_info,
    &sxmf_f2fs_superblock_prefix,
    &sxmf_f2fs_device,
    &sxmf_f2fs_superblock_tail,
    &sxmf_f2fs_checkpoint_header,
    &sxmf_f2fs_nat_entry,
    &sxmf_f2fs_node_footer,
    &sxmf_reiser35_superblock,
    &sxmf_reiser36_superblock,
    &sxmf_reiser_block_header,
    &sxmf_reiser_item_header,
    &sxmf_reiser_child,
    &sxmf_sfs_root_block,
    &sxmf_sfs_object_container,
    &sxmf_sfs_btree_header,
    &sxmf_sfs_extent16,
    &sxmf_sfs_extent32,
    &sxmf_sfs_btree_index,
    &sxmf_opera_disc_label,
    &sxmf_opera_directory_header,
    &sxmf_opera_directory_record,
    &sxmf_opera_avatar,
    &sxmf_xfs4_superblock,
    &sxmf_xfs5_superblock,
    &sxmf_xfs4_agf,
    &sxmf_xfs5_agf,
    &sxmf_xfs4_agi,
    &sxmf_xfs5_agi,
    &sxmf_xfs_inode_v2,
    &sxmf_xfs_inode_v3,
    &sxmf_gfs2_superblock,
    &sxmf_gfs2_inode,
    &sxmf_gfs2_directory_entry,
    &sxmf_gfs2_leaf,
    &sxmf_hpfs_superblock,
    &sxmf_hpfs_spareblock,
    &sxmf_hpfs_fnode_prefix,
    &sxmf_hpfs_btree_header,
    &sxmf_hpfs_extent,
    &sxmf_hpfs_btree_child,
    &sxmf_hpfs_fnode_tail,
    &sxmf_hpfs_anode_header,
    &sxmf_hpfs_dnode_header,
    &sxmf_hpfs_directory_entry,
    &sxmf_hpfs_down_pointer,
    &sxmf_hammer_volume_header_le,
    &sxmf_hammer_volume_header_be,
    &sxmf_hammer_blockmap_le,
    &sxmf_hammer_blockmap_be,
    &sxmf_hammer_undo_pointer_le,
    &sxmf_hammer_undo_pointer_be,
    &sxmf_zfs_embedded_checksum_le,
    &sxmf_zfs_embedded_checksum_be,
    &sxmf_zfs_block_pointer_le,
    &sxmf_zfs_block_pointer_be,
    &sxmf_zfs_uberblock_prefix_le,
    &sxmf_zfs_uberblock_prefix_be,
    &sxmf_zfs_uberblock_tail_le,
    &sxmf_zfs_uberblock_tail_be,
    &sxmf_erofs_superblock,
    &sxmf_erofs_inode_compact,
    &sxmf_erofs_inode_extended,
    &sxmf_erofs_directory_entry,
    &sxmf_erofs_device_slot,
    &sxmf_erofs_chunk_block,
    &sxmf_ufs1_legacy_superblock_le,
    &sxmf_ufs1_legacy_superblock_be,
    &sxmf_ufs_modern_superblock_le,
    &sxmf_ufs_modern_superblock_be,
    &sxmf_sufs_superblock_le,
    &sxmf_sufs_superblock_be,
    &sxmf_ufs_cylinder_group_prefix_le,
    &sxmf_ufs_cylinder_group_prefix_be,
    &sxmf_ufs_cylinder_group_tail_le,
    &sxmf_ufs_cylinder_group_tail_be,
    &sxmf_ufs1_inode_le,
    &sxmf_ufs1_inode_be,
    &sxmf_ufs1_symlink_inode_le,
    &sxmf_ufs1_symlink_inode_be,
    &sxmf_ufs2_inode_le,
    &sxmf_ufs2_inode_be,
    &sxmf_ufs2_symlink_inode_le,
    &sxmf_ufs2_symlink_inode_be,
    &sxmf_sufs_inode_le,
    &sxmf_sufs_inode_be,
    &sxmf_ufs_directory_entry_le,
    &sxmf_ufs_directory_entry_be,
    &sxmf_sufs_directory_entry_le,
    &sxmf_sufs_directory_entry_be,
    &sxmf_ufs_fragment_pointer32_le,
    &sxmf_ufs_fragment_pointer32_be,
    &sxmf_ufs_fragment_pointer64_le,
    &sxmf_ufs_fragment_pointer64_be,
    &sxmf_vxfs1_superblock_le,
    &sxmf_vxfs1_superblock_be,
    &sxmf_vxfs2_superblock_le,
    &sxmf_vxfs2_superblock_be,
    &sxmf_vmfs_volume_header,
    &sxmf_vmfs35_lvm_header,
    &sxmf_vmfs35_filesystem_header,
    &sxmf_vmfs35_bitmap_header,
    &sxmf_vmfs35_inode_data,
    &sxmf_vmfs35_directory_entry,
    &sxmf_vmfs35_block_id,
    &sxmf_reiser4_master,
    &sxmf_reiser4_format40_superblock,
    &sxmf_reiser4_node40_header,
    &sxmf_reiser4_item_header_large,
    &sxmf_reiser4_child,
    &sxmf_reiser4_extent,
    &sxmf_hammer_node_header_le,
    &sxmf_hammer_node_header_be,
    &sxmf_hammer_internal_record_le,
    &sxmf_hammer_internal_record_be,
    &sxmf_hammer_leaf_record_le,
    &sxmf_hammer_leaf_record_be,
    &sxmf_hammer_inode_le,
    &sxmf_hammer_inode_be,
    &sxmf_hammer_directory_entry_le,
    &sxmf_hammer_directory_entry_be,
    &sxmf_cdi_volume_descriptor,
    &sxmf_cdi_terminator,
    &sxmf_cdi_path_entry,
    &sxmf_cdi_directory_entry,
    &sxmf_cdi_directory_attributes,
    &sxmf_cdi_mode2_sector_header,
    &sxmf_cdi_form1_edc,
    &sxmf_vmfs35_metadata_header,
    &sxmf_sfs_file_object,
    &sxmf_sfs_directory_object,
    &sxmf_ufs1_legacy_inode_le,
    &sxmf_ufs1_legacy_inode_be,
    &sxmf_ufs1_legacy_symlink_inode_le,
    &sxmf_ufs1_legacy_symlink_inode_be,
};

static bool sx_modernfs_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60420000U||id>=0x60430000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    if(id==0x6042004bU&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 72020U:return xx_data_struct_record_set_comment(r,L"FS_UFS1_MAGIC");
    default:break;}}
    if(id==0x6042004cU&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 72020U:return xx_data_struct_record_set_comment(r,L"FS_UFS1_MAGIC");
    default:break;}}
    if(id==0x6042004dU&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 72020U:return xx_data_struct_record_set_comment(r,L"FS_UFS1_MAGIC");
    case 424935705U:return xx_data_struct_record_set_comment(r,L"FS_UFS2_MAGIC");
    default:break;}}
    if(id==0x6042004eU&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 72020U:return xx_data_struct_record_set_comment(r,L"FS_UFS1_MAGIC");
    case 424935705U:return xx_data_struct_record_set_comment(r,L"FS_UFS2_MAGIC");
    default:break;}}
    if(id==0x6042004fU&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 72020U:return xx_data_struct_record_set_comment(r,L"FS_MAGIC (Solaris UFS)");
    default:break;}}
    if(id==0x60420050U&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 72020U:return xx_data_struct_record_set_comment(r,L"FS_MAGIC (Solaris UFS)");
    default:break;}}
    if(id==0x60420051U&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 590421U:return xx_data_struct_record_set_comment(r,L"CG_MAGIC");
    default:break;}}
    if(id==0x60420052U&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 590421U:return xx_data_struct_record_set_comment(r,L"CG_MAGIC");
    default:break;}}
    if(id==0x6042005fU&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"DT_FIFO");
    case 2U:return xx_data_struct_record_set_comment(r,L"DT_CHR");
    case 4U:return xx_data_struct_record_set_comment(r,L"DT_DIR");
    case 6U:return xx_data_struct_record_set_comment(r,L"DT_BLK");
    case 8U:return xx_data_struct_record_set_comment(r,L"DT_REG");
    case 10U:return xx_data_struct_record_set_comment(r,L"DT_LNK");
    case 12U:return xx_data_struct_record_set_comment(r,L"DT_SOCK");
    case 14U:return xx_data_struct_record_set_comment(r,L"DT_WHT");
    default:break;}}
    if(id==0x60420060U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"DT_FIFO");
    case 2U:return xx_data_struct_record_set_comment(r,L"DT_CHR");
    case 4U:return xx_data_struct_record_set_comment(r,L"DT_DIR");
    case 6U:return xx_data_struct_record_set_comment(r,L"DT_BLK");
    case 8U:return xx_data_struct_record_set_comment(r,L"DT_REG");
    case 10U:return xx_data_struct_record_set_comment(r,L"DT_LNK");
    case 12U:return xx_data_struct_record_set_comment(r,L"DT_SOCK");
    case 14U:return xx_data_struct_record_set_comment(r,L"DT_WHT");
    default:break;}}
    if(id==0x6042000bU&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 4076150800U:return xx_data_struct_record_set_comment(r,L"F2FS_SUPER_MAGIC");
    default:break;}}
    if(id==0x60420006U&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 13364U:return xx_data_struct_record_set_comment(r,L"NILFS_SUPER_MAGIC");
    default:break;}}
    if(id==0x60420009U&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 514849297U:return xx_data_struct_record_set_comment(r,L"NILFS_SEGSUM_MAGIC");
    default:break;}}
    if(id==0x60420002U&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 930524809U:return xx_data_struct_record_set_comment(r,L"Fossil header magic");
    default:break;}}
    if(id==0x60420003U&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 591438769U:return xx_data_struct_record_set_comment(r,L"Fossil superblock magic");
    default:break;}}
    if(id==0x60420011U&&!xx_rt_wcscmp(r->name,L"version")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"ReiserFS 3.5 (old disk format)");
    default:break;}}
    if(id==0x60420012U&&!xx_rt_wcscmp(r->name,L"version")&&integer){switch(value){
    case 2U:return xx_data_struct_record_set_comment(r,L"ReiserFS 3.6 disk format");
    default:break;}}
    if(id==0x60420075U&&!xx_rt_wcscmp(r->name,L"plugin")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"stat40");
    case 2U:return xx_data_struct_record_set_comment(r,L"cde40");
    case 3U:return xx_data_struct_record_set_comment(r,L"nodeptr40");
    case 5U:return xx_data_struct_record_set_comment(r,L"extent40");
    case 6U:return xx_data_struct_record_set_comment(r,L"tail40");
    default:break;}}
    if(id==0x60420016U&&!xx_rt_wcscmp(r->name,L"id")&&integer){switch(value){
    case 1397117696U:return xx_data_struct_record_set_comment(r,L"SFS0");
    case 1397117698U:return xx_data_struct_record_set_comment(r,L"SFS2");
    default:break;}}
    if(id==0x6042002eU&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 4158917294U:return xx_data_struct_record_set_comment(r,L"FNODE_MAGIC");
    default:break;}}
    if(id==0x60420033U&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 937691822U:return xx_data_struct_record_set_comment(r,L"ANODE_MAGIC");
    default:break;}}
    if(id==0x60420034U&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 2011433646U:return xx_data_struct_record_set_comment(r,L"DNODE_MAGIC");
    default:break;}}
    if(id==0x60420078U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 73U:return xx_data_struct_record_set_comment(r,L"HAMMER_BTREE_TYPE_INTERNAL");
    case 76U:return xx_data_struct_record_set_comment(r,L"HAMMER_BTREE_TYPE_LEAF");
    default:break;}}
    if(id==0x60420079U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 73U:return xx_data_struct_record_set_comment(r,L"HAMMER_BTREE_TYPE_INTERNAL");
    case 76U:return xx_data_struct_record_set_comment(r,L"HAMMER_BTREE_TYPE_LEAF");
    default:break;}}
    if(id==0x6042007cU&&!xx_rt_wcscmp(r->name,L"record_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"HAMMER_RECTYPE_INODE");
    case 16U:return xx_data_struct_record_set_comment(r,L"HAMMER_RECTYPE_DATA");
    case 17U:return xx_data_struct_record_set_comment(r,L"HAMMER_RECTYPE_DIRENTRY");
    case 20U:return xx_data_struct_record_set_comment(r,L"HAMMER_RECTYPE_SYMLINK");
    default:break;}}
    if(id==0x6042007dU&&!xx_rt_wcscmp(r->name,L"record_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"HAMMER_RECTYPE_INODE");
    case 16U:return xx_data_struct_record_set_comment(r,L"HAMMER_RECTYPE_DATA");
    case 17U:return xx_data_struct_record_set_comment(r,L"HAMMER_RECTYPE_DIRENTRY");
    case 20U:return xx_data_struct_record_set_comment(r,L"HAMMER_RECTYPE_SYMLINK");
    default:break;}}
    if(id==0x60420041U&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 12235020U:return xx_data_struct_record_set_comment(r,L"UBERBLOCK_MAGIC");
    default:break;}}
    if(id==0x60420042U&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 12235020U:return xx_data_struct_record_set_comment(r,L"UBERBLOCK_MAGIC");
    default:break;}}
    if(id==0x6042003dU&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 148859008194476561U:return xx_data_struct_record_set_comment(r,L"ZEC_MAGIC");
    default:break;}}
    if(id==0x6042003eU&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 148859008194476561U:return xx_data_struct_record_set_comment(r,L"ZEC_MAGIC");
    default:break;}}
    if(id==0x60420045U&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 3774210530U:return xx_data_struct_record_set_comment(r,L"EROFS_SUPER_MAGIC_V1");
    default:break;}}
    if(id==0x60420048U&&!xx_rt_wcscmp(r->name,L"type")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"EROFS_FT_UNKNOWN");
    case 1U:return xx_data_struct_record_set_comment(r,L"EROFS_FT_REG_FILE");
    case 2U:return xx_data_struct_record_set_comment(r,L"EROFS_FT_DIR");
    case 3U:return xx_data_struct_record_set_comment(r,L"EROFS_FT_CHRDEV");
    case 4U:return xx_data_struct_record_set_comment(r,L"EROFS_FT_BLKDEV");
    case 5U:return xx_data_struct_record_set_comment(r,L"EROFS_FT_FIFO");
    case 6U:return xx_data_struct_record_set_comment(r,L"EROFS_FT_SOCK");
    case 7U:return xx_data_struct_record_set_comment(r,L"EROFS_FT_SYMLINK");
    default:break;}}
    if(id==0x6042006bU&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 3221344269U:return xx_data_struct_record_set_comment(r,L"VMFS volume magic");
    default:break;}}
    if(id==0x6042006dU&&!xx_rt_wcscmp(r->name,L"magic")&&integer){switch(value){
    case 799797598U:return xx_data_struct_record_set_comment(r,L"VMFS filesystem magic");
    default:break;}}
    if(id==0x6042006fU&&!xx_rt_wcscmp(r->name,L"allocation_format")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Direct file-block ID array");
    case 4305U:return xx_data_struct_record_set_comment(r,L"Inline inode data");
    default:break;}}
    if(id==0x60420082U&&!xx_rt_wcscmp(r->name,L"record_type")&&integer){switch(value){
    case 1U:return xx_data_struct_record_set_comment(r,L"Primary volume descriptor");
    case 2U:return xx_data_struct_record_set_comment(r,L"Supplementary volume descriptor");
    default:break;}}
    if(id==0x60420083U&&!xx_rt_wcscmp(r->name,L"record_type")&&integer){switch(value){
    case 255U:return xx_data_struct_record_set_comment(r,L"Volume descriptor terminator");
    default:break;}}
    switch(id){
    case 0x60420001U:
        if(!xx_rt_wcscmp(r->name,L"container_size"))s=L"Format-dependent container size, observed starting with ReFS 3.4";
        break;
    case 0x60420002U:
        if(!xx_rt_wcscmp(r->name,L"super_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"label_block"))s=L"Filesystem block number of the label area";
        else if(!xx_rt_wcscmp(r->name,L"data_block"))s=L"Filesystem block number of the data area";
        else if(!xx_rt_wcscmp(r->name,L"end_block"))s=L"First block past the filesystem";
        break;
    case 0x60420003U:
        if(!xx_rt_wcscmp(r->name,L"active_root_block"))s=L"Data-area block number; -1 denotes no block";
        else if(!xx_rt_wcscmp(r->name,L"next_archive_root_block"))s=L"Data-area block number; -1 denotes no block";
        else if(!xx_rt_wcscmp(r->name,L"current_archive_root_block"))s=L"Data-area block number; -1 denotes no block";
        break;
    case 0x60420005U:
        if(!xx_rt_wcscmp(r->name,L"volume_blocks"))s=L"Volume size in hardware/LVM blocks, not aggregate blocks";
        else if(!xx_rt_wcscmp(r->name,L"log2_block_factor"))s=L"log2 aggregate block size divided by hardware block size";
        else if(!xx_rt_wcscmp(r->name,L"secondary_inode_table_block_high"))s=L"High 8 bits of the 40-bit filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"secondary_inode_table_block_low"))s=L"Low 32 bits of the 40-bit filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"secondary_inode_map_block_high"))s=L"High 8 bits of the 40-bit filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"secondary_inode_map_block_low"))s=L"Low 32 bits of the 40-bit filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"log_extent_block_high"))s=L"High 8 bits of the 40-bit filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"log_extent_block_low"))s=L"Low 32 bits of the 40-bit filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"fsck_extent_block_high"))s=L"High 8 bits of the 40-bit filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"fsck_extent_block_low"))s=L"Low 32 bits of the 40-bit filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"update_nanoseconds"))s=L"Nanosecond component of the update time";
        else if(!xx_rt_wcscmp(r->name,L"extension_blocks"))s=L"Extended volume size in hardware/LVM blocks";
        else if(!xx_rt_wcscmp(r->name,L"extension_fsck_block_high"))s=L"High 8 bits of the 40-bit filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"extension_fsck_block_low"))s=L"Low 32 bits of the 40-bit filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"extension_log_block_high"))s=L"High 8 bits of the 40-bit filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"extension_log_block_low"))s=L"Low 32 bits of the 40-bit filesystem block number";
        break;
    case 0x60420006U:
        if(!xx_rt_wcscmp(r->name,L"log_block_size"))s=L"Filesystem block bytes = 1024 << log_block_size";
        else if(!xx_rt_wcscmp(r->name,L"first_data_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"last_partial_segment_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"check_interval"))s=L"Duration in seconds";
        else if(!xx_rt_wcscmp(r->name,L"commit_interval"))s=L"Segment commit interval in seconds";
        break;
    case 0x60420007U:
        if(!xx_rt_wcscmp(r->name,L"block_map"))s=L"Encoded mapping; the first word contains mapping flags";
        break;
    case 0x60420009U:
        if(!xx_rt_wcscmp(r->name,L"next_segment_block"))s=L"Filesystem block number";
        break;
    case 0x6042000bU:
        if(!xx_rt_wcscmp(r->name,L"checksum_offset"))s=L"Byte offset from the beginning of this superblock";
        else if(!xx_rt_wcscmp(r->name,L"segment0_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"checkpoint_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"sit_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"nat_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"ssa_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"main_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"volume_name"))s=L"UTF-16LE volume name";
        else if(!xx_rt_wcscmp(r->name,L"extension_list"))s=L"64 filename extensions, eight bytes each";
        break;
    case 0x6042000eU:
        if(!xx_rt_wcscmp(r->name,L"current_node_block_offsets"))s=L"Block offsets within the corresponding segments";
        else if(!xx_rt_wcscmp(r->name,L"current_data_block_offsets"))s=L"Block offsets within the corresponding segments";
        else if(!xx_rt_wcscmp(r->name,L"pack_summary_start"))s=L"Block offset from checkpoint pack start";
        else if(!xx_rt_wcscmp(r->name,L"checksum_offset"))s=L"Byte offset from the checkpoint block start";
        else if(!xx_rt_wcscmp(r->name,L"elapsed_time"))s=L"Elapsed mount duration in seconds";
        break;
    case 0x6042000fU:
        if(!xx_rt_wcscmp(r->name,L"block"))s=L"Filesystem block number";
        break;
    case 0x60420010U:
        if(!xx_rt_wcscmp(r->name,L"next_block"))s=L"Filesystem block number";
        break;
    case 0x60420011U:
        if(!xx_rt_wcscmp(r->name,L"root_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"journal_first_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"journal_max_commit_age"))s=L"Duration in seconds";
        else if(!xx_rt_wcscmp(r->name,L"journal_max_transaction_age"))s=L"Duration in seconds";
        break;
    case 0x60420012U:
        if(!xx_rt_wcscmp(r->name,L"root_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"journal_first_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"journal_max_commit_age"))s=L"Duration in seconds";
        else if(!xx_rt_wcscmp(r->name,L"journal_max_transaction_age"))s=L"Duration in seconds";
        else if(!xx_rt_wcscmp(r->name,L"check_interval"))s=L"Duration in seconds";
        break;
    case 0x60420013U:
        if(!xx_rt_wcscmp(r->name,L"right_delimiting_key"))s=L"Version-dependent 128-bit ReiserFS key";
        break;
    case 0x60420014U:
        if(!xx_rt_wcscmp(r->name,L"key"))s=L"Version-dependent 128-bit ReiserFS key";
        else if(!xx_rt_wcscmp(r->name,L"free_space_or_entry_count"))s=L"Free space for indirect items, directory entry count for directory items";
        else if(!xx_rt_wcscmp(r->name,L"item_location"))s=L"Byte offset inside this tree block";
        break;
    case 0x60420015U:
        if(!xx_rt_wcscmp(r->name,L"block"))s=L"Filesystem block number";
        break;
    case 0x60420016U:
        if(!xx_rt_wcscmp(r->name,L"self_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since 1978-01-01";
        else if(!xx_rt_wcscmp(r->name,L"first_byte"))s=L"Partition start byte relative to the disk";
        else if(!xx_rt_wcscmp(r->name,L"last_byte"))s=L"First byte after this partition, relative to the disk";
        else if(!xx_rt_wcscmp(r->name,L"bitmap_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"admin_space_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"root_object_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"extent_tree_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"object_tree_block"))s=L"Filesystem block number";
        break;
    case 0x60420019U:
        if(!xx_rt_wcscmp(r->name,L"previous_block_or_object"))s=L"High bit selects object-node ownership";
        break;
    case 0x6042001aU:
        if(!xx_rt_wcscmp(r->name,L"previous_block_or_object"))s=L"High bit selects object-node ownership";
        break;
    case 0x6042001cU:
        if(!xx_rt_wcscmp(r->name,L"last_root_avatar_index"))s=L"Number of root copies minus one";
        else if(!xx_rt_wcscmp(r->name,L"root_avatars"))s=L"Volume block numbers of the root-directory copies";
        break;
    case 0x6042001dU:
        if(!xx_rt_wcscmp(r->name,L"next_block"))s=L"Directory-relative block index; -1 terminates the chain";
        else if(!xx_rt_wcscmp(r->name,L"previous_block"))s=L"Directory-relative block index; -1 denotes the first block";
        else if(!xx_rt_wcscmp(r->name,L"first_free"))s=L"Byte offset within this directory block";
        else if(!xx_rt_wcscmp(r->name,L"first_used"))s=L"Byte offset within this directory block";
        break;
    case 0x6042001eU:
        if(!xx_rt_wcscmp(r->name,L"last_avatar_index"))s=L"Number of physical copies minus one";
        break;
    case 0x6042001fU:
        if(!xx_rt_wcscmp(r->name,L"block"))s=L"Volume block number";
        break;
    case 0x60420020U:
        if(!xx_rt_wcscmp(r->name,L"log_start_block"))s=L"Encoded filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"version_flags"))s=L"Low four bits contain the superblock version";
        else if(!xx_rt_wcscmp(r->name,L"log2_ag_blocks"))s=L"Ceiling of log2 allocation group block count";
        else if(!xx_rt_wcscmp(r->name,L"log_stripe_unit"))s=L"Log stripe unit in bytes";
        else if(!xx_rt_wcscmp(r->name,L"bad_features2"))s=L"Historic duplicate feature word caused by missing alignment";
        break;
    case 0x60420021U:
        if(!xx_rt_wcscmp(r->name,L"log_start_block"))s=L"Encoded filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"version_flags"))s=L"Low four bits contain the superblock version";
        else if(!xx_rt_wcscmp(r->name,L"log2_ag_blocks"))s=L"Ceiling of log2 allocation group block count";
        else if(!xx_rt_wcscmp(r->name,L"log_stripe_unit"))s=L"Log stripe unit in bytes";
        else if(!xx_rt_wcscmp(r->name,L"bad_features2"))s=L"Historic duplicate feature word caused by missing alignment";
        else if(!xx_rt_wcscmp(r->name,L"crc"))s=L"CRC32C is stored little endian within this big-endian header";
        else if(!xx_rt_wcscmp(r->name,L"metadata_directory_inode"))s=L"Defined when the metadata-directory feature is enabled";
        else if(!xx_rt_wcscmp(r->name,L"realtime_group_count"))s=L"Defined when realtime groups are enabled";
        else if(!xx_rt_wcscmp(r->name,L"realtime_group_extents"))s=L"Extents per realtime group";
        else if(!xx_rt_wcscmp(r->name,L"internal_realtime_start_block"))s=L"Filesystem block number; feature dependent";
        else if(!xx_rt_wcscmp(r->name,L"reserved_realtime_blocks"))s=L"Reserved zoned realtime blocks";
        break;
    case 0x60420022U:
        if(!xx_rt_wcscmp(r->name,L"block_tree_root"))s=L"Allocation-group-relative block number";
        else if(!xx_rt_wcscmp(r->name,L"count_tree_root"))s=L"Allocation-group-relative block number";
        else if(!xx_rt_wcscmp(r->name,L"reverse_map_root"))s=L"Allocation-group-relative block number; reserved without RMAPBT";
        else if(!xx_rt_wcscmp(r->name,L"free_list_first"))s=L"Index into the AGFL table";
        else if(!xx_rt_wcscmp(r->name,L"free_list_last"))s=L"Index into the AGFL table";
        break;
    case 0x60420023U:
        if(!xx_rt_wcscmp(r->name,L"block_tree_root"))s=L"Allocation-group-relative block number";
        else if(!xx_rt_wcscmp(r->name,L"count_tree_root"))s=L"Allocation-group-relative block number";
        else if(!xx_rt_wcscmp(r->name,L"reverse_map_root"))s=L"Allocation-group-relative block number; reserved without RMAPBT";
        else if(!xx_rt_wcscmp(r->name,L"free_list_first"))s=L"Index into the AGFL table";
        else if(!xx_rt_wcscmp(r->name,L"free_list_last"))s=L"Index into the AGFL table";
        else if(!xx_rt_wcscmp(r->name,L"refcount_root"))s=L"Allocation-group-relative block number";
        else if(!xx_rt_wcscmp(r->name,L"crc"))s=L"CRC32C stored little endian";
        break;
    case 0x60420024U:
        if(!xx_rt_wcscmp(r->name,L"inode_tree_root"))s=L"Allocation-group-relative block number";
        else if(!xx_rt_wcscmp(r->name,L"new_inode"))s=L"Allocation-group-relative inode number";
        else if(!xx_rt_wcscmp(r->name,L"last_directory_inode"))s=L"Allocation-group-relative inode number";
        break;
    case 0x60420025U:
        if(!xx_rt_wcscmp(r->name,L"inode_tree_root"))s=L"Allocation-group-relative block number";
        else if(!xx_rt_wcscmp(r->name,L"new_inode"))s=L"Allocation-group-relative inode number";
        else if(!xx_rt_wcscmp(r->name,L"last_directory_inode"))s=L"Allocation-group-relative inode number";
        else if(!xx_rt_wcscmp(r->name,L"crc"))s=L"CRC32C stored little endian";
        else if(!xx_rt_wcscmp(r->name,L"free_inode_root"))s=L"Allocation-group-relative block number";
        break;
    case 0x60420026U:
        if(!xx_rt_wcscmp(r->name,L"metatype_or_old_link_count"))s=L"Metadata type for metadata-directory inodes, old link count for version 1";
        else if(!xx_rt_wcscmp(r->name,L"project_id_low"))s=L"Low 16 bits of the project ID";
        else if(!xx_rt_wcscmp(r->name,L"project_id_high"))s=L"High 16 bits of the project ID";
        else if(!xx_rt_wcscmp(r->name,L"extent_count_or_padding"))s=L"NREXT64 extent count, or historical padding and flush counter";
        else if(!xx_rt_wcscmp(r->name,L"access_timestamp"))s=L"Legacy signed seconds and nanoseconds, or BIGTIME encoded nanoseconds";
        else if(!xx_rt_wcscmp(r->name,L"modification_timestamp"))s=L"Legacy signed seconds and nanoseconds, or BIGTIME encoded nanoseconds";
        else if(!xx_rt_wcscmp(r->name,L"change_timestamp"))s=L"Legacy signed seconds and nanoseconds, or BIGTIME encoded nanoseconds";
        else if(!xx_rt_wcscmp(r->name,L"data_or_attribute_extents"))s=L"Attribute extent count if NREXT64 is enabled; otherwise data extents";
        else if(!xx_rt_wcscmp(r->name,L"attribute_extents_or_padding"))s=L"Attribute extent count without NREXT64; otherwise padding";
        else if(!xx_rt_wcscmp(r->name,L"attribute_fork_offset_units"))s=L"Byte offset = value * 8 from literal inode area";
        else if(!xx_rt_wcscmp(r->name,L"next_unlinked_inode"))s=L"Allocation-group-relative inode number";
        break;
    case 0x60420027U:
        if(!xx_rt_wcscmp(r->name,L"metatype_or_old_link_count"))s=L"Metadata type for metadata-directory inodes, old link count for version 1";
        else if(!xx_rt_wcscmp(r->name,L"project_id_low"))s=L"Low 16 bits of the project ID";
        else if(!xx_rt_wcscmp(r->name,L"project_id_high"))s=L"High 16 bits of the project ID";
        else if(!xx_rt_wcscmp(r->name,L"extent_count_or_padding"))s=L"NREXT64 extent count, or historical padding and flush counter";
        else if(!xx_rt_wcscmp(r->name,L"access_timestamp"))s=L"Legacy signed seconds and nanoseconds, or BIGTIME encoded nanoseconds";
        else if(!xx_rt_wcscmp(r->name,L"modification_timestamp"))s=L"Legacy signed seconds and nanoseconds, or BIGTIME encoded nanoseconds";
        else if(!xx_rt_wcscmp(r->name,L"change_timestamp"))s=L"Legacy signed seconds and nanoseconds, or BIGTIME encoded nanoseconds";
        else if(!xx_rt_wcscmp(r->name,L"data_or_attribute_extents"))s=L"Attribute extent count if NREXT64 is enabled; otherwise data extents";
        else if(!xx_rt_wcscmp(r->name,L"attribute_extents_or_padding"))s=L"Attribute extent count without NREXT64; otherwise padding";
        else if(!xx_rt_wcscmp(r->name,L"attribute_fork_offset_units"))s=L"Byte offset = value * 8 from literal inode area";
        else if(!xx_rt_wcscmp(r->name,L"next_unlinked_inode"))s=L"Allocation-group-relative inode number";
        else if(!xx_rt_wcscmp(r->name,L"cow_extent_or_used_blocks"))s=L"CoW extent size in blocks, or used realtime-group blocks for zoned rtrmap inode";
        else if(!xx_rt_wcscmp(r->name,L"creation_timestamp"))s=L"Legacy signed seconds and nanoseconds, or BIGTIME encoded nanoseconds";
        break;
    case 0x60420028U:
        if(!xx_rt_wcscmp(r->name,L"master_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"root_block"))s=L"Filesystem block number";
        break;
    case 0x60420029U:
        if(!xx_rt_wcscmp(r->name,L"self_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"allocation_goal_meta"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"allocation_goal_data"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"hash_depth"))s=L"Number of hash-table address bits";
        else if(!xx_rt_wcscmp(r->name,L"xattr_block"))s=L"Filesystem block number";
        break;
    case 0x6042002aU:
        if(!xx_rt_wcscmp(r->name,L"block"))s=L"Filesystem block number of the inode";
        break;
    case 0x6042002bU:
        if(!xx_rt_wcscmp(r->name,L"next_leaf_block"))s=L"Filesystem block number";
        break;
    case 0x6042002cU:
        if(!xx_rt_wcscmp(r->name,L"root_fnode_sector"))s=L"512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"bitmap_directory_sector"))s=L"512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"bad_block_directory_sector"))s=L"512-byte sector number";
        break;
    case 0x6042002dU:
        if(!xx_rt_wcscmp(r->name,L"superblock_crc"))s=L"Used by HPFS386; reserved by ordinary HPFS";
        else if(!xx_rt_wcscmp(r->name,L"spareblock_crc"))s=L"Used by HPFS386; reserved by ordinary HPFS";
        break;
    case 0x6042002fU:
        if(!xx_rt_wcscmp(r->name,L"first_free"))s=L"Byte offset relative to the B+tree header, with high bit encoded in flags bit 0";
        break;
    case 0x60420030U:
        if(!xx_rt_wcscmp(r->name,L"file_sector"))s=L"Logical 512-byte sector number in the file";
        else if(!xx_rt_wcscmp(r->name,L"disk_sector"))s=L"Volume-relative 512-byte sector number";
        break;
    case 0x60420031U:
        if(!xx_rt_wcscmp(r->name,L"file_sector_limit"))s=L"Exclusive logical sector upper bound";
        break;
    case 0x60420032U:
        if(!xx_rt_wcscmp(r->name,L"ea_offset"))s=L"Byte offset from the fnode start";
        else if(!xx_rt_wcscmp(r->name,L"dasd_limit"))s=L"HPFS386 DASD allocation limit";
        else if(!xx_rt_wcscmp(r->name,L"dasd_usage"))s=L"HPFS386 DASD usage";
        break;
    case 0x60420034U:
        if(!xx_rt_wcscmp(r->name,L"first_free"))s=L"Byte offset from the 2048-byte dnode start";
        else if(!xx_rt_wcscmp(r->name,L"parent_sector"))s=L"Root dnode points to the directory fnode; other dnodes point to a parent dnode";
        break;
    case 0x60420035U:
        if(!xx_rt_wcscmp(r->name,L"acl_count_bits"))s=L"Low three bits contain the ACL count";
        break;
    case 0x60420037U:
        if(!xx_rt_wcscmp(r->name,L"boot_begin"))s=L"Byte offset relative to the volume device";
        else if(!xx_rt_wcscmp(r->name,L"memory_log_begin"))s=L"Byte offset relative to the volume device";
        else if(!xx_rt_wcscmp(r->name,L"buffer_begin"))s=L"Byte offset relative to the volume device";
        else if(!xx_rt_wcscmp(r->name,L"buffer_end"))s=L"First byte after volume buffers";
        else if(!xx_rt_wcscmp(r->name,L"btree_root"))s=L"Encoded zone/volume/offset address, not a direct file offset";
        break;
    case 0x60420038U:
        if(!xx_rt_wcscmp(r->name,L"boot_begin"))s=L"Byte offset relative to the volume device";
        else if(!xx_rt_wcscmp(r->name,L"memory_log_begin"))s=L"Byte offset relative to the volume device";
        else if(!xx_rt_wcscmp(r->name,L"buffer_begin"))s=L"Byte offset relative to the volume device";
        else if(!xx_rt_wcscmp(r->name,L"buffer_end"))s=L"First byte after volume buffers";
        else if(!xx_rt_wcscmp(r->name,L"btree_root"))s=L"Encoded zone/volume/offset address, not a direct file offset";
        break;
    case 0x60420039U:
        if(!xx_rt_wcscmp(r->name,L"physical_offset"))s=L"Encoded HAMMER address";
        else if(!xx_rt_wcscmp(r->name,L"first_offset"))s=L"Encoded HAMMER address";
        else if(!xx_rt_wcscmp(r->name,L"next_offset"))s=L"Encoded HAMMER address";
        else if(!xx_rt_wcscmp(r->name,L"allocation_offset"))s=L"Encoded HAMMER address";
        break;
    case 0x6042003aU:
        if(!xx_rt_wcscmp(r->name,L"physical_offset"))s=L"Encoded HAMMER address";
        else if(!xx_rt_wcscmp(r->name,L"first_offset"))s=L"Encoded HAMMER address";
        else if(!xx_rt_wcscmp(r->name,L"next_offset"))s=L"Encoded HAMMER address";
        else if(!xx_rt_wcscmp(r->name,L"allocation_offset"))s=L"Encoded HAMMER address";
        break;
    case 0x6042003bU:
        if(!xx_rt_wcscmp(r->name,L"address"))s=L"Encoded zone-2 HAMMER address";
        break;
    case 0x6042003cU:
        if(!xx_rt_wcscmp(r->name,L"address"))s=L"Encoded zone-2 HAMMER address";
        break;
    case 0x6042003fU:
        if(!xx_rt_wcscmp(r->name,L"dva0_word0"))s=L"Packed vdev ID and allocation size in 512-byte units";
        else if(!xx_rt_wcscmp(r->name,L"dva0_word1"))s=L"Packed gang flag and offset in 512-byte units";
        else if(!xx_rt_wcscmp(r->name,L"dva1_word0"))s=L"Packed vdev ID and allocation size in 512-byte units";
        else if(!xx_rt_wcscmp(r->name,L"dva1_word1"))s=L"Packed gang flag and offset in 512-byte units";
        else if(!xx_rt_wcscmp(r->name,L"dva2_word0"))s=L"Packed vdev ID and allocation size in 512-byte units";
        else if(!xx_rt_wcscmp(r->name,L"dva2_word1"))s=L"Packed gang flag and offset in 512-byte units";
        else if(!xx_rt_wcscmp(r->name,L"properties"))s=L"Encoded size, compression, checksum type, level, and byte order";
        else if(!xx_rt_wcscmp(r->name,L"properties2"))s=L"Additional properties in recent pools; historically padding";
        else if(!xx_rt_wcscmp(r->name,L"physical_birth_word"))s=L"Encoded physical birth transaction group";
        else if(!xx_rt_wcscmp(r->name,L"logical_birth_word"))s=L"Encoded logical birth transaction group";
        break;
    case 0x60420040U:
        if(!xx_rt_wcscmp(r->name,L"dva0_word0"))s=L"Packed vdev ID and allocation size in 512-byte units";
        else if(!xx_rt_wcscmp(r->name,L"dva0_word1"))s=L"Packed gang flag and offset in 512-byte units";
        else if(!xx_rt_wcscmp(r->name,L"dva1_word0"))s=L"Packed vdev ID and allocation size in 512-byte units";
        else if(!xx_rt_wcscmp(r->name,L"dva1_word1"))s=L"Packed gang flag and offset in 512-byte units";
        else if(!xx_rt_wcscmp(r->name,L"dva2_word0"))s=L"Packed vdev ID and allocation size in 512-byte units";
        else if(!xx_rt_wcscmp(r->name,L"dva2_word1"))s=L"Packed gang flag and offset in 512-byte units";
        else if(!xx_rt_wcscmp(r->name,L"properties"))s=L"Encoded size, compression, checksum type, level, and byte order";
        else if(!xx_rt_wcscmp(r->name,L"properties2"))s=L"Additional properties in recent pools; historically padding";
        else if(!xx_rt_wcscmp(r->name,L"physical_birth_word"))s=L"Encoded physical birth transaction group";
        else if(!xx_rt_wcscmp(r->name,L"logical_birth_word"))s=L"Encoded logical birth transaction group";
        break;
    case 0x60420043U:
        if(!xx_rt_wcscmp(r->name,L"mmp_delay"))s=L"Nanoseconds since last multihost write; zero disables MMP";
        else if(!xx_rt_wcscmp(r->name,L"mmp_config"))s=L"Packed validity, write interval, sequence, and failure intervals";
        else if(!xx_rt_wcscmp(r->name,L"raidz_reflow_info"))s=L"Recent RAID-Z expansion state; reserved in earlier pools";
        break;
    case 0x60420044U:
        if(!xx_rt_wcscmp(r->name,L"mmp_delay"))s=L"Nanoseconds since last multihost write; zero disables MMP";
        else if(!xx_rt_wcscmp(r->name,L"mmp_config"))s=L"Packed validity, write interval, sequence, and failure intervals";
        else if(!xx_rt_wcscmp(r->name,L"raidz_reflow_info"))s=L"Recent RAID-Z expansion state; reserved in earlier pools";
        break;
    case 0x60420045U:
        if(!xx_rt_wcscmp(r->name,L"block_size_bits"))s=L"Filesystem block bytes = 1 << block_size_bits";
        else if(!xx_rt_wcscmp(r->name,L"extension_slots"))s=L"Additional 16-byte superblock slots";
        else if(!xx_rt_wcscmp(r->name,L"metadata_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"xattr_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"compression_algorithms_or_lz4_distance"))s=L"Algorithm mask with COMPR_CFGS; otherwise LZ4 maximum distance";
        else if(!xx_rt_wcscmp(r->name,L"device_table_slot"))s=L"Slot index; byte offset = value * 128";
        else if(!xx_rt_wcscmp(r->name,L"xattr_prefix_start"))s=L"Offset in four-byte units";
        else if(!xx_rt_wcscmp(r->name,L"reserved_or_extension"))s=L"Newer EROFS revisions assign fields here; not interpreted by the native reader";
        break;
    case 0x60420046U:
        if(!xx_rt_wcscmp(r->name,L"format"))s=L"Bit 0 selects extended inode; bits 1..3 select data layout";
        else if(!xx_rt_wcscmp(r->name,L"xattr_count"))s=L"Encoded xattr-body count";
        else if(!xx_rt_wcscmp(r->name,L"block_or_device_or_chunk_info"))s=L"Data block number, encoded device, or chunk-format word according to inode type/layout";
        break;
    case 0x60420047U:
        if(!xx_rt_wcscmp(r->name,L"xattr_count"))s=L"Encoded xattr-body count";
        else if(!xx_rt_wcscmp(r->name,L"block_or_device_or_chunk_info"))s=L"Data block number, encoded device, or chunk-format word according to inode type/layout";
        break;
    case 0x60420048U:
        if(!xx_rt_wcscmp(r->name,L"name_offset"))s=L"Byte offset within the directory block";
        break;
    case 0x60420049U:
        if(!xx_rt_wcscmp(r->name,L"mapped_block"))s=L"Filesystem block number";
        break;
    case 0x6042004aU:
        if(!xx_rt_wcscmp(r->name,L"block"))s=L"Filesystem block number";
        break;
    case 0x6042004bU:
        if(!xx_rt_wcscmp(r->name,L"first_field"))s=L"Historic in-core link word";
        else if(!xx_rt_wcscmp(r->name,L"superblock_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_block_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"inode_block_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"data_block_fragment"))s=L"First data fragment within a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_group_offset"))s=L"Fragment offset used by the legacy cylinder-group placement formula";
        else if(!xx_rt_wcscmp(r->name,L"rotation_delay"))s=L"Milliseconds";
        else if(!xx_rt_wcscmp(r->name,L"filesystem_to_disk_shift"))s=L"Shift converting fragment numbers to 512-byte sector numbers";
        else if(!xx_rt_wcscmp(r->name,L"old_summary_fragment"))s=L"Filesystem fragment number";
        else if(!xx_rt_wcscmp(r->name,L"incore_pointer_padding"))s=L"Historical in-memory pointers; pointer width is host dependent, so retained physically";
        else if(!xx_rt_wcscmp(r->name,L"rotation_position_offset"))s=L"Byte offset from the superblock start";
        else if(!xx_rt_wcscmp(r->name,L"rotation_block_offset"))s=L"Byte offset from the superblock start";
        break;
    case 0x6042004cU:
        if(!xx_rt_wcscmp(r->name,L"first_field"))s=L"Historic in-core link word";
        else if(!xx_rt_wcscmp(r->name,L"superblock_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_block_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"inode_block_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"data_block_fragment"))s=L"First data fragment within a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_group_offset"))s=L"Fragment offset used by the legacy cylinder-group placement formula";
        else if(!xx_rt_wcscmp(r->name,L"rotation_delay"))s=L"Milliseconds";
        else if(!xx_rt_wcscmp(r->name,L"filesystem_to_disk_shift"))s=L"Shift converting fragment numbers to 512-byte sector numbers";
        else if(!xx_rt_wcscmp(r->name,L"old_summary_fragment"))s=L"Filesystem fragment number";
        else if(!xx_rt_wcscmp(r->name,L"incore_pointer_padding"))s=L"Historical in-memory pointers; pointer width is host dependent, so retained physically";
        else if(!xx_rt_wcscmp(r->name,L"rotation_position_offset"))s=L"Byte offset from the superblock start";
        else if(!xx_rt_wcscmp(r->name,L"rotation_block_offset"))s=L"Byte offset from the superblock start";
        break;
    case 0x6042004dU:
        if(!xx_rt_wcscmp(r->name,L"first_field"))s=L"Historic in-core link word";
        else if(!xx_rt_wcscmp(r->name,L"superblock_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_block_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"inode_block_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"data_block_fragment"))s=L"First data fragment within a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_group_offset"))s=L"Fragment offset used by the legacy cylinder-group placement formula";
        else if(!xx_rt_wcscmp(r->name,L"rotation_delay"))s=L"Milliseconds";
        else if(!xx_rt_wcscmp(r->name,L"filesystem_to_disk_shift"))s=L"Shift converting fragment numbers to 512-byte sector numbers";
        else if(!xx_rt_wcscmp(r->name,L"old_summary_fragment"))s=L"Filesystem fragment number";
        else if(!xx_rt_wcscmp(r->name,L"incore_pointer_padding"))s=L"Historical in-memory pointers; pointer width is host dependent, so retained physically";
        else if(!xx_rt_wcscmp(r->name,L"provider_fragments"))s=L"Provider size in filesystem fragments";
        else if(!xx_rt_wcscmp(r->name,L"actual_superblock_offset"))s=L"Byte offset relative to the volume";
        else if(!xx_rt_wcscmp(r->name,L"standard_superblock_offset"))s=L"Byte offset relative to the volume";
        else if(!xx_rt_wcscmp(r->name,L"summary_fragment"))s=L"Filesystem fragment number";
        else if(!xx_rt_wcscmp(r->name,L"rotation_position_offset"))s=L"Byte offset from the superblock start";
        else if(!xx_rt_wcscmp(r->name,L"rotation_block_offset"))s=L"Byte offset from the superblock start";
        break;
    case 0x6042004eU:
        if(!xx_rt_wcscmp(r->name,L"first_field"))s=L"Historic in-core link word";
        else if(!xx_rt_wcscmp(r->name,L"superblock_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_block_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"inode_block_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"data_block_fragment"))s=L"First data fragment within a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_group_offset"))s=L"Fragment offset used by the legacy cylinder-group placement formula";
        else if(!xx_rt_wcscmp(r->name,L"rotation_delay"))s=L"Milliseconds";
        else if(!xx_rt_wcscmp(r->name,L"filesystem_to_disk_shift"))s=L"Shift converting fragment numbers to 512-byte sector numbers";
        else if(!xx_rt_wcscmp(r->name,L"old_summary_fragment"))s=L"Filesystem fragment number";
        else if(!xx_rt_wcscmp(r->name,L"incore_pointer_padding"))s=L"Historical in-memory pointers; pointer width is host dependent, so retained physically";
        else if(!xx_rt_wcscmp(r->name,L"provider_fragments"))s=L"Provider size in filesystem fragments";
        else if(!xx_rt_wcscmp(r->name,L"actual_superblock_offset"))s=L"Byte offset relative to the volume";
        else if(!xx_rt_wcscmp(r->name,L"standard_superblock_offset"))s=L"Byte offset relative to the volume";
        else if(!xx_rt_wcscmp(r->name,L"summary_fragment"))s=L"Filesystem fragment number";
        else if(!xx_rt_wcscmp(r->name,L"rotation_position_offset"))s=L"Byte offset from the superblock start";
        else if(!xx_rt_wcscmp(r->name,L"rotation_block_offset"))s=L"Byte offset from the superblock start";
        break;
    case 0x6042004fU:
        if(!xx_rt_wcscmp(r->name,L"link"))s=L"Historic in-core link word";
        else if(!xx_rt_wcscmp(r->name,L"rolled"))s=L"Logging roll state";
        else if(!xx_rt_wcscmp(r->name,L"superblock_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_block_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"inode_block_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"data_block_fragment"))s=L"First data fragment within a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_group_offset"))s=L"Fragment offset used by the legacy cylinder-group placement formula";
        else if(!xx_rt_wcscmp(r->name,L"rotation_delay"))s=L"Milliseconds";
        else if(!xx_rt_wcscmp(r->name,L"filesystem_to_disk_shift"))s=L"Shift converting fragment numbers to 512-byte sector numbers";
        else if(!xx_rt_wcscmp(r->name,L"old_summary_fragment"))s=L"Filesystem fragment number";
        else if(!xx_rt_wcscmp(r->name,L"log_block"))s=L"Filesystem block number of the embedded log";
        else if(!xx_rt_wcscmp(r->name,L"rotation_position_offset"))s=L"Byte offset from the superblock start";
        else if(!xx_rt_wcscmp(r->name,L"rotation_block_offset"))s=L"Byte offset from the superblock start";
        break;
    case 0x60420050U:
        if(!xx_rt_wcscmp(r->name,L"link"))s=L"Historic in-core link word";
        else if(!xx_rt_wcscmp(r->name,L"rolled"))s=L"Logging roll state";
        else if(!xx_rt_wcscmp(r->name,L"superblock_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_block_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"inode_block_fragment"))s=L"Filesystem fragment number, relative to a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"data_block_fragment"))s=L"First data fragment within a cylinder group";
        else if(!xx_rt_wcscmp(r->name,L"cylinder_group_offset"))s=L"Fragment offset used by the legacy cylinder-group placement formula";
        else if(!xx_rt_wcscmp(r->name,L"rotation_delay"))s=L"Milliseconds";
        else if(!xx_rt_wcscmp(r->name,L"filesystem_to_disk_shift"))s=L"Shift converting fragment numbers to 512-byte sector numbers";
        else if(!xx_rt_wcscmp(r->name,L"old_summary_fragment"))s=L"Filesystem fragment number";
        else if(!xx_rt_wcscmp(r->name,L"log_block"))s=L"Filesystem block number of the embedded log";
        else if(!xx_rt_wcscmp(r->name,L"rotation_position_offset"))s=L"Byte offset from the superblock start";
        else if(!xx_rt_wcscmp(r->name,L"rotation_block_offset"))s=L"Byte offset from the superblock start";
        break;
    case 0x60420051U:
        if(!xx_rt_wcscmp(r->name,L"old_block_totals_offset"))s=L"Byte offset inside this cylinder-group block";
        else if(!xx_rt_wcscmp(r->name,L"old_positions_offset"))s=L"Byte offset inside this cylinder-group block";
        else if(!xx_rt_wcscmp(r->name,L"used_inode_map_offset"))s=L"Byte offset inside this cylinder-group block";
        else if(!xx_rt_wcscmp(r->name,L"free_fragment_map_offset"))s=L"Byte offset inside this cylinder-group block";
        else if(!xx_rt_wcscmp(r->name,L"next_free_offset"))s=L"Byte offset inside this cylinder-group block";
        break;
    case 0x60420052U:
        if(!xx_rt_wcscmp(r->name,L"old_block_totals_offset"))s=L"Byte offset inside this cylinder-group block";
        else if(!xx_rt_wcscmp(r->name,L"old_positions_offset"))s=L"Byte offset inside this cylinder-group block";
        else if(!xx_rt_wcscmp(r->name,L"used_inode_map_offset"))s=L"Byte offset inside this cylinder-group block";
        else if(!xx_rt_wcscmp(r->name,L"free_fragment_map_offset"))s=L"Byte offset inside this cylinder-group block";
        else if(!xx_rt_wcscmp(r->name,L"next_free_offset"))s=L"Byte offset inside this cylinder-group block";
        break;
    case 0x60420053U:
        if(!xx_rt_wcscmp(r->name,L"cluster_summary_offset"))s=L"Byte offset inside the cylinder-group block";
        else if(!xx_rt_wcscmp(r->name,L"cluster_map_offset"))s=L"Byte offset inside the cylinder-group block";
        break;
    case 0x60420054U:
        if(!xx_rt_wcscmp(r->name,L"cluster_summary_offset"))s=L"Byte offset inside the cylinder-group block";
        else if(!xx_rt_wcscmp(r->name,L"cluster_map_offset"))s=L"Byte offset inside the cylinder-group block";
        break;
    case 0x60420055U:
        if(!xx_rt_wcscmp(r->name,L"direct_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"indirect_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"allocated_sectors"))s=L"512-byte sectors";
        break;
    case 0x60420056U:
        if(!xx_rt_wcscmp(r->name,L"direct_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"indirect_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"allocated_sectors"))s=L"512-byte sectors";
        break;
    case 0x60420057U:
        if(!xx_rt_wcscmp(r->name,L"allocated_sectors"))s=L"512-byte sectors";
        break;
    case 0x60420058U:
        if(!xx_rt_wcscmp(r->name,L"allocated_sectors"))s=L"512-byte sectors";
        break;
    case 0x60420059U:
        if(!xx_rt_wcscmp(r->name,L"allocated_sectors"))s=L"512-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"xattr_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"direct_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"indirect_fragments"))s=L"Filesystem fragment numbers";
        break;
    case 0x6042005aU:
        if(!xx_rt_wcscmp(r->name,L"allocated_sectors"))s=L"512-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"xattr_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"direct_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"indirect_fragments"))s=L"Filesystem fragment numbers";
        break;
    case 0x6042005bU:
        if(!xx_rt_wcscmp(r->name,L"allocated_sectors"))s=L"512-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"xattr_fragments"))s=L"Filesystem fragment numbers";
        break;
    case 0x6042005cU:
        if(!xx_rt_wcscmp(r->name,L"allocated_sectors"))s=L"512-byte sectors";
        else if(!xx_rt_wcscmp(r->name,L"xattr_fragments"))s=L"Filesystem fragment numbers";
        break;
    case 0x6042005dU:
        if(!xx_rt_wcscmp(r->name,L"direct_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"indirect_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"allocated_sectors"))s=L"512-byte sectors";
        break;
    case 0x6042005eU:
        if(!xx_rt_wcscmp(r->name,L"direct_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"indirect_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"allocated_sectors"))s=L"512-byte sectors";
        break;
    case 0x60420063U:
        if(!xx_rt_wcscmp(r->name,L"fragment"))s=L"Filesystem fragment number";
        break;
    case 0x60420064U:
        if(!xx_rt_wcscmp(r->name,L"fragment"))s=L"Filesystem fragment number";
        break;
    case 0x60420065U:
        if(!xx_rt_wcscmp(r->name,L"fragment"))s=L"Filesystem fragment number";
        break;
    case 0x60420066U:
        if(!xx_rt_wcscmp(r->name,L"fragment"))s=L"Filesystem fragment number";
        break;
    case 0x60420067U:
        if(!xx_rt_wcscmp(r->name,L"old_log_start"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"old_log_end"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_allocation_unit_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"extent_map_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"inode_map_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"extent_operation_map_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"inode_list_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"free_data_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"first_extent_map_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_inode_map_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_extent_operation_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_inode_list_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_free_data_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"max_tier"))s=L"log2 data blocks per allocation unit";
        break;
    case 0x60420068U:
        if(!xx_rt_wcscmp(r->name,L"old_log_start"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"old_log_end"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_allocation_unit_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"extent_map_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"inode_map_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"extent_operation_map_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"inode_list_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"free_data_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"first_extent_map_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_inode_map_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_extent_operation_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_inode_list_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_free_data_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"max_tier"))s=L"log2 data blocks per allocation unit";
        break;
    case 0x60420069U:
        if(!xx_rt_wcscmp(r->name,L"old_log_start"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"old_log_end"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_allocation_unit_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"extent_map_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"inode_map_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"extent_operation_map_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"inode_list_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"free_data_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"first_extent_map_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_inode_map_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_extent_operation_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_inode_list_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_free_data_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"max_tier"))s=L"log2 data blocks per allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"object_location_extents"))s=L"Filesystem block numbers of primary and replica OLT";
        break;
    case 0x6042006aU:
        if(!xx_rt_wcscmp(r->name,L"old_log_start"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"old_log_end"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_allocation_unit_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"extent_map_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"inode_map_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"extent_operation_map_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"inode_list_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"free_data_block"))s=L"Block offset inside each allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"first_extent_map_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_inode_map_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_extent_operation_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_inode_list_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_free_data_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"max_tier"))s=L"log2 data blocks per allocation unit";
        else if(!xx_rt_wcscmp(r->name,L"object_location_extents"))s=L"Filesystem block numbers of primary and replica OLT";
        break;
    case 0x6042006bU:
        if(!xx_rt_wcscmp(r->name,L"lun_identity"))s=L"Version-dependent LUN identity";
        else if(!xx_rt_wcscmp(r->name,L"size_units"))s=L"Physical volume size divided by 256";
        else if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Stored time word, believed to use microseconds";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Stored time word, believed to use microseconds";
        break;
    case 0x6042006cU:
        if(!xx_rt_wcscmp(r->name,L"blocks"))s=L"Segment count plus extent count, according to vmfs-tools";
        else if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Stored time word, believed to use microseconds";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Stored time word, believed to use microseconds";
        break;
    case 0x60420071U:
        if(!xx_rt_wcscmp(r->name,L"block_id"))s=L"Packed allocation type, flags, and block index";
        break;
    case 0x60420073U:
        if(!xx_rt_wcscmp(r->name,L"root_block"))s=L"Filesystem block number";
        break;
    case 0x60420074U:
        if(!xx_rt_wcscmp(r->name,L"free_space_start"))s=L"Byte offset in this node";
        break;
    case 0x60420075U:
        if(!xx_rt_wcscmp(r->name,L"locality_and_type"))s=L"Low four bits contain key type; upper 60 bits locality";
        else if(!xx_rt_wcscmp(r->name,L"object_and_type"))s=L"Low 60 bits object ID; high bits encode key variant";
        else if(!xx_rt_wcscmp(r->name,L"offset"))s=L"Encoded key offset; meaning depends on the item plugin";
        else if(!xx_rt_wcscmp(r->name,L"data_offset"))s=L"Byte offset inside this node";
        break;
    case 0x60420076U:
        if(!xx_rt_wcscmp(r->name,L"block"))s=L"Filesystem block number";
        break;
    case 0x60420077U:
        if(!xx_rt_wcscmp(r->name,L"block"))s=L"Filesystem block number; zero denotes a sparse extent";
        break;
    case 0x60420078U:
        if(!xx_rt_wcscmp(r->name,L"parent"))s=L"Encoded HAMMER zone/volume/offset address";
        break;
    case 0x60420079U:
        if(!xx_rt_wcscmp(r->name,L"parent"))s=L"Encoded HAMMER zone/volume/offset address";
        break;
    case 0x6042007aU:
        if(!xx_rt_wcscmp(r->name,L"key"))s=L"Index key: logical byte end offset or a directory-name hash, depending on record type";
        else if(!xx_rt_wcscmp(r->name,L"subtree"))s=L"Encoded HAMMER zone/volume/offset address";
        break;
    case 0x6042007bU:
        if(!xx_rt_wcscmp(r->name,L"key"))s=L"Index key: logical byte end offset or a directory-name hash, depending on record type";
        else if(!xx_rt_wcscmp(r->name,L"subtree"))s=L"Encoded HAMMER zone/volume/offset address";
        break;
    case 0x6042007cU:
        if(!xx_rt_wcscmp(r->name,L"key"))s=L"Index key: logical byte end offset or a directory-name hash, depending on record type";
        else if(!xx_rt_wcscmp(r->name,L"data_address"))s=L"Encoded HAMMER zone/volume/offset address";
        break;
    case 0x6042007dU:
        if(!xx_rt_wcscmp(r->name,L"key"))s=L"Index key: logical byte end offset or a directory-name hash, depending on record type";
        else if(!xx_rt_wcscmp(r->name,L"data_address"))s=L"Encoded HAMMER zone/volume/offset address";
        break;
    case 0x6042007eU:
        if(!xx_rt_wcscmp(r->name,L"change_time"))s=L"HAMMER timestamp in microseconds since Unix epoch";
        else if(!xx_rt_wcscmp(r->name,L"inline_extension"))s=L"Inline symlink bytes for a sufficiently short symlink";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"HAMMER timestamp in microseconds since Unix epoch";
        else if(!xx_rt_wcscmp(r->name,L"access_time"))s=L"HAMMER timestamp in microseconds since Unix epoch";
        break;
    case 0x6042007fU:
        if(!xx_rt_wcscmp(r->name,L"change_time"))s=L"HAMMER timestamp in microseconds since Unix epoch";
        else if(!xx_rt_wcscmp(r->name,L"inline_extension"))s=L"Inline symlink bytes for a sufficiently short symlink";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"HAMMER timestamp in microseconds since Unix epoch";
        else if(!xx_rt_wcscmp(r->name,L"access_time"))s=L"HAMMER timestamp in microseconds since Unix epoch";
        break;
    case 0x60420082U:
        if(!xx_rt_wcscmp(r->name,L"path_table_block"))s=L"Logical 2048-byte block number";
        else if(!xx_rt_wcscmp(r->name,L"creation_date"))s=L"ASCII YYYYMMDDhhmmsscc";
        else if(!xx_rt_wcscmp(r->name,L"modification_date"))s=L"ASCII YYYYMMDDhhmmsscc";
        else if(!xx_rt_wcscmp(r->name,L"expiration_date"))s=L"ASCII YYYYMMDDhhmmsscc";
        else if(!xx_rt_wcscmp(r->name,L"effective_date"))s=L"ASCII YYYYMMDDhhmmsscc";
        break;
    case 0x60420084U:
        if(!xx_rt_wcscmp(r->name,L"directory_block"))s=L"Logical 2048-byte block number";
        break;
    case 0x60420085U:
        if(!xx_rt_wcscmp(r->name,L"file_block"))s=L"Logical 2048-byte block number";
        break;
    case 0x60420087U:
        if(!xx_rt_wcscmp(r->name,L"minute_bcd"))s=L"Packed BCD minute of absolute sector position";
        else if(!xx_rt_wcscmp(r->name,L"second_bcd"))s=L"Packed BCD second of absolute sector position";
        else if(!xx_rt_wcscmp(r->name,L"frame_bcd"))s=L"Packed BCD frame of absolute sector position";
        break;
    case 0x60420089U:
        if(!xx_rt_wcscmp(r->name,L"position"))s=L"Byte position within the logical VMFS volume";
        else if(!xx_rt_wcscmp(r->name,L"heartbeat_position"))s=L"Byte position within the logical VMFS volume";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Stored metadata time word; units are not established here";
        break;
    case 0x6042008aU:
        if(!xx_rt_wcscmp(r->name,L"data_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since 1978-01-01";
        break;
    case 0x6042008bU:
        if(!xx_rt_wcscmp(r->name,L"hash_table_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"first_directory_block"))s=L"Filesystem block number";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since 1978-01-01";
        break;
    case 0x6042008cU:
        if(!xx_rt_wcscmp(r->name,L"old_uid_gid_or_inode"))s=L"Legacy union: two 16-bit owner IDs or an in-core inode number";
        else if(!xx_rt_wcscmp(r->name,L"direct_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"indirect_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"allocated_sectors"))s=L"512-byte sectors";
        break;
    case 0x6042008dU:
        if(!xx_rt_wcscmp(r->name,L"old_uid_gid_or_inode"))s=L"Legacy union: two 16-bit owner IDs or an in-core inode number";
        else if(!xx_rt_wcscmp(r->name,L"direct_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"indirect_fragments"))s=L"Filesystem fragment numbers";
        else if(!xx_rt_wcscmp(r->name,L"allocated_sectors"))s=L"512-byte sectors";
        break;
    case 0x6042008eU:
        if(!xx_rt_wcscmp(r->name,L"old_uid_gid_or_inode"))s=L"Legacy union: two 16-bit owner IDs or an in-core inode number";
        else if(!xx_rt_wcscmp(r->name,L"allocated_sectors"))s=L"512-byte sectors";
        break;
    case 0x6042008fU:
        if(!xx_rt_wcscmp(r->name,L"old_uid_gid_or_inode"))s=L"Legacy union: two 16-bit owner IDs or an in-core inode number";
        else if(!xx_rt_wcscmp(r->name,L"allocated_sectors"))s=L"512-byte sectors";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Every coordinate is relative to the borrowed volume base.  No native
 * subclass state, host mounts, or journal replay is required.  Display caps
 * retain validated earlier records; undecoded metadata and payload stay raw. */
#define SXMF_LIMIT 24000U
#define SXMF_INODES 262144U
static bool sxmf_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxmf_read(sx_context*c,uint64_t p,void*b,size_t n){return !xx_pd_is_stopped(c->pd)&&sxmf_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint16_t sxmf16(const uint8_t*b,unsigned o){return o==1?(uint16_t)((uint16_t)b[0]<<8|b[1]):(uint16_t)((uint16_t)b[1]<<8|b[0]);}
static uint32_t sxmf32(const uint8_t*b,unsigned o){if(o==2)return (uint32_t)sxmf16(b,0)<<16|sxmf16(b+2,0);return o==1?(uint32_t)sxmf16(b,1)<<16|sxmf16(b+2,1):(uint32_t)sxmf16(b+2,0)<<16|sxmf16(b,0);}
static uint64_t sxmf64(const uint8_t*b,unsigned o){return o==1?(uint64_t)sxmf32(b,1)<<32|sxmf32(b+4,1):(uint64_t)sxmf32(b+4,0)<<32|sxmf32(b,0);}
static bool sxmf_pow(uint64_t v){return v&&!(v&(v-1));}
static bool sxmf_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 if(!n)return true;const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(n>1048576U||n>UINT64_MAX/z||!sxmf_span(c,p,n*z)||xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXMF_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&(uint64_t)(c->items[lo-1].offset-c->f->base_address)+(uint64_t)c->items[lo-1].total_size>p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}return true;
}
#define SXMF_ADD(c,l,p) sxmf_put(c,&sxmf_##l,p,1)
#define SXMF_TABLE(c,l,p,n) sxmf_put(c,&sxmf_##l,p,n)
#define SXMF_ORDER(l,o) ((o)==1?&sxmf_##l##_be:&sxmf_##l##_le)
#define SXMF_UNIX(l,o) ((o)==2?&sxmf_##l##_pdp:SXMF_ORDER(l,o))
static bool sxmf_f2fs_sb(sx_context*c,uint64_t p){return SXMF_ADD(c,f2fs_superblock_prefix,p)&&SXMF_TABLE(c,f2fs_device,p+2201,8)&&SXMF_ADD(c,f2fs_superblock_tail,p+2745);}
static bool sxmf_f2fs(sx_context*c){
 uint8_t h[128],b[192];if(!sxmf_read(c,1024,h,128)||sxmf32(h,0)!=0xf2f52010U||sxmf32(h+16,0)!=12)return false;
 uint64_t blocks=sxmf64(h+36,0);if(!blocks||blocks>(uint64_t)c->size/4096||!sxmf_f2fs_sb(c,1024))return false;
 if(sxmf_read(c,5120,b,4)&&sxmf32(b,0)==0xf2f52010U&&sxmf_span(c,5120,3072)&&!sxmf_f2fs_sb(c,5120))return false;
 uint64_t cp=sxmf32(h+76,0),nat=sxmf32(h+84,0),seglog=sxmf32(h+20,0);uint32_t root=sxmf32(h+96,0);
 for(unsigned i=0;i<2;i++){uint64_t block=cp;if(i){if(seglog>31)break;block+=UINT64_C(1)<<seglog;}if(block>=blocks||!sxmf_read(c,block*4096,b,192))continue;
  uint64_t total=sxmf32(b+136,0),crc=sxmf32(b+164,0);if(!sxmf64(b,0)||total<2||total>blocks-block||crc<192||crc>4092)continue;
  if(!SXMF_ADD(c,f2fs_checkpoint_header,block*4096))return false;
 }
 if(nat&&nat<blocks&&sxmf32(h+60,0)&&!SXMF_TABLE(c,f2fs_nat_entry,nat*4096,4096/9))return false;
 if(nat&&nat<blocks&&root<4096/9&&sxmf_read(c,nat*4096+(uint64_t)root*9,b,9)){
  uint64_t node=sxmf32(b+5,0);if(node&&node<blocks&&sxmf_read(c,node*4096+4072,b,24)&&sxmf32(b,0)==root&&sxmf32(b+4,0)==root&&!SXMF_ADD(c,f2fs_node_footer,node*4096+4072))return false;
 }
 return true;
}
static bool sxmf_nilfs(sx_context*c){
 uint8_t h[280],b[64];if(!sxmf_read(c,1024,h,280)||sxmf16(h+6,0)!=0x3434||sxmf32(h+20,0)>6||!SXMF_ADD(c,nilfs2_superblock,1024))return false;
 uint64_t bs=UINT64_C(1024)<<sxmf32(h+20,0),blocks=sxmf64(h+32,0)/bs;
 uint64_t last=((uint64_t)c->size>>12);if(last>0){last=(last-1)<<12;if(last!=1024&&sxmf_read(c,last,b,8)&&sxmf16(b+6,0)==0x3434&&sxmf_span(c,last,1024)&&!SXMF_ADD(c,nilfs2_superblock,last))return false;}
 uint64_t block=sxmf64(h+64,0);if(!blocks||block>=blocks||!sxmf_read(c,block*bs,b,64)||sxmf32(b+8,0)!=0x1eaffa11)return true;
 uint64_t count=sxmf32(b+40,0),summary=sxmf32(b+48,0);if(!count||count>blocks-block||sxmf16(b+12,0)<64||summary<64||summary>count*bs||!sxmf_span(c,block*bs,count*bs))return true;
 if(!SXMF_ADD(c,nilfs2_segment_summary,block*bs))return false;
 /* A super-root occupies the last block only when the segment carries SS_SR. */
 if(sxmf16(b+14,0)&4){uint64_t p=(block+count-1)*bs;uint8_t root[16];if(sxmf_read(c,p,root,16)&&sxmf16(root+4,0)>=400&&sxmf16(root+4,0)<=bs){if(!SXMF_ADD(c,nilfs2_super_root_header,p)||!SXMF_TABLE(c,nilfs2_inode,p+16,3))return false;}}
 /* File-info records are separated by variable block-info records. Emit the
  * first complete descriptor; never pretend they form a fixed-width array. */
 if(sxmf32(b+44,0)&&sxmf16(b+12,0)<=summary&&24<=summary-sxmf16(b+12,0)&&!SXMF_ADD(c,nilfs2_file_info,block*bs+sxmf16(b+12,0)))return false;
 return true;
}
static bool sxmf_refs(sx_context*c){uint8_t h[64];if(!sxmf_read(c,0,h,64)||xx_rt_memcmp(h+3,"ReFS\0\0\0\0",8)||xx_rt_memcmp(h+16,"FSRS",4)||!SXMF_ADD(c,refs_volume_header,0))return false;uint64_t bs=sxmf32(h+32,0),n=sxmf64(h+24,0);if(bs>=512&&bs<=65536&&sxmf_pow(bs)&&n&&n<=(uint64_t)c->size/bs){uint64_t p=(n-1)*bs;if(p&&sxmf_read(c,p,h,64)&&!xx_rt_memcmp(h+3,"ReFS\0\0\0\0",8)&&!xx_rt_memcmp(h+16,"FSRS",4)&&!SXMF_ADD(c,refs_volume_header,p))return false;}return true;}
static bool sxmf_fossil(sx_context*c){uint8_t h[24],b[182];if(!sxmf_read(c,131072,h,24)||sxmf32(h,1)!=0x3776ae89U||!SXMF_ADD(c,fossil_header,131072))return false;uint64_t bs=sxmf16(h+6,1),sb=sxmf32(h+8,1),labels=sxmf32(h+12,1),data=sxmf32(h+16,1),end=sxmf32(h+20,1);if(bs<512||!sxmf_pow(bs)||end>(uint64_t)c->size/bs||sb>=end)return true;
 if(sxmf_read(c,sb*bs,b,182)&&sxmf32(b,1)==0x2340a3b1&&!SXMF_ADD(c,fossil_superblock,sb*bs))return false;
 if(labels<data&&data<end){uint64_t slots=bs/14,total=end-data,limit=(data-labels)*slots;if(total>limit)total=limit;if(total>SXMF_INODES)total=SXMF_INODES;for(uint64_t i=0;i<total&&c->count<SXMF_LIMIT;){uint64_t n=total-i;if(n>slots)n=slots;if(!SXMF_TABLE(c,fossil_label,(labels+i/slots)*bs,n))return false;i+=n;}}
 return true;
}
static bool sxmf_jfs(sx_context*c){uint8_t h[4];bool any=false;const uint64_t at[]={32768,61440};for(unsigned i=0;i<2;i++)if(sxmf_read(c,at[i],h,4)&&!xx_rt_memcmp(h,"JFS1",4)&&sxmf_span(c,at[i],184)){if(!SXMF_ADD(c,jfs_superblock,at[i]))return false;any=true;}return any;}
static bool sxmf_vxfs(sx_context*c){uint8_t h[8];if(!sxmf_read(c,1024,h,8))return false;unsigned o=sxmf32(h,0)==0xa501fcf5U?0:sxmf32(h,1)==0xa501fcf5U?1:2;if(o==2)return false;return sxmf_put(c,sxmf32(h+4,o)>=2?SXMF_ORDER(vxfs2_superblock,o):SXMF_ORDER(vxfs1_superblock,o),1024,1);}
static bool sxmf_zfs(sx_context*c){
 /* Embedded label checksum records are physically framed even when no local
  * dataset tree can be decoded. Uberblock slots vary with the device ashift. */
 uint8_t b[216];bool any=false;uint64_t labels[4]={0,262144,UINT64_MAX,UINT64_MAX};if(c->size>=524288){labels[2]=((uint64_t)c->size&~UINT64_C(262143))-524288;labels[3]=labels[2]+262144;}
 for(unsigned i=0;i<4;i++){uint64_t p=labels[i];if(p==UINT64_MAX||!sxmf_span(c,p,262144))continue;bool dup=false;for(unsigned k=0;k<i;k++)if(labels[k]==p)dup=true;if(dup)continue;
  uint64_t ck[3]={p+8192-40,p+16384-40,p+131072-40};for(unsigned k=0;k<3;k++)if(sxmf_read(c,ck[k],b,40)){unsigned o=sxmf64(b,0)==UINT64_C(0x0210da7ab10c7a11)?0:sxmf64(b,1)==UINT64_C(0x0210da7ab10c7a11)?1:2;if(o<2){if(!sxmf_put(c,SXMF_ORDER(zfs_embedded_checksum,o),ck[k],1))return false;any=true;}}
  for(uint64_t q=p+131072;q+1024<=p+262144;q+=1024){if(!sxmf_read(c,q,b,216))break;unsigned o=sxmf64(b,0)==0xbab10cU?0:sxmf64(b,1)==0xbab10cU?1:2;if(o==2)continue;
   if(!sxmf_put(c,SXMF_ORDER(zfs_uberblock_prefix,o),q,1)||!sxmf_put(c,SXMF_ORDER(zfs_block_pointer,o),q+40,1)||!sxmf_put(c,SXMF_ORDER(zfs_uberblock_tail,o),q+168,1))return false;any=true;
   /* Locate the checksum at a supported power-of-two slot boundary. */
   for(uint64_t z=1024;z<=131072&&z<=p+262144-q;z*=2)if(sxmf_read(c,q+z-40,b,40)&&sxmf64(b,o)==UINT64_C(0x0210da7ab10c7a11)){if(!sxmf_put(c,SXMF_ORDER(zfs_embedded_checksum,o),q+z-40,1))return false;break;}
  }
 }
 /* The native recognizer also accepts a checksum in its initial 512-byte
  * probe. Include only the real 40-byte checksum record at that boundary. */
 const uint64_t probe[]={8192,15872,130560,392704};for(unsigned i=0;i<4;i++)if(sxmf_read(c,probe[i]+472,b,40)){unsigned o=sxmf64(b,0)==UINT64_C(0x0210da7ab10c7a11)?0:sxmf64(b,1)==UINT64_C(0x0210da7ab10c7a11)?1:2;if(o<2){if(!sxmf_put(c,SXMF_ORDER(zfs_embedded_checksum,o),probe[i]+472,1))return false;any=true;}}
 return any;
}
/* Optional metadata graph work is separately bounded from volume geometry. */
typedef struct sxmf_task{uint64_t p;unsigned kind,depth;}sxmf_task;
typedef struct sxmf_queue{sxmf_task items[4096];size_t count,index;}sxmf_queue;
static void sxmf_queue_add(sxmf_queue*q,uint64_t p,unsigned kind,unsigned depth){if(!p||depth>32||q->count>=SX_COUNT(q->items))return;for(size_t i=0;i<q->count;i++)if(q->items[i].p==p&&q->items[i].kind==kind)return;q->items[q->count++]=(sxmf_task){p,kind,depth};}
static bool sxmf_hpfs(sx_context*c){
 uint8_t b[2048],sb[512];if(!sxmf_read(c,8192,sb,512)||sxmf32(sb,0)!=0xf995e849U||sxmf32(sb+4,0)!=0xfa53e9c5U||!SXMF_ADD(c,hpfs_superblock,8192))return false;
 if(sxmf_read(c,8704,b,512)&&sxmf32(b,0)==0xf9911849U&&sxmf32(b+4,0)==0xfa5229c5U&&!SXMF_ADD(c,hpfs_spareblock,8704))return false;
 sxmf_queue*q=xx_rt_calloc(1,sizeof(*q));if(!q)return false;sxmf_queue_add(q,(uint64_t)sxmf32(sb+12,0)*512,0,0);bool ok=true;
 while(q->index<q->count&&c->count<SXMF_LIMIT&&!xx_pd_is_stopped(c->pd)){
  sxmf_task t=q->items[q->index++];if(!sxmf_read(c,t.p,b,t.kind==2?2048:512))continue;uint64_t off=0,capacity=0;
  if(t.kind==0){if(sxmf32(b,0)!=0xf7e40aaeU)continue;if(!SXMF_ADD(c,hpfs_fnode_prefix,t.p)||!SXMF_ADD(c,hpfs_btree_header,t.p+56)||!SXMF_ADD(c,hpfs_fnode_tail,t.p+160)){ok=false;break;}off=64;capacity=96;}
  else if(t.kind==1){if(sxmf32(b,0)!=0x37e40aaeU)continue;if(!SXMF_ADD(c,hpfs_anode_header,t.p)||!SXMF_ADD(c,hpfs_btree_header,t.p+12)){ok=false;break;}off=20;capacity=480;}
  else{if(sxmf32(b,0)!=0x77e40aaeU)continue;uint64_t end=sxmf32(b+4,0);if(end<20||end>2048)continue;if(!SXMF_ADD(c,hpfs_dnode_header,t.p)){ok=false;break;}
   for(uint64_t p=20;p+31<=end;){uint64_t z=sxmf16(b+p,0),n=b[p+30];unsigned flags=b[p+2];if(z<31||z>end-p||n>z-31||(flags&4&&z<35+n))break;if(!SXMF_ADD(c,hpfs_directory_entry,t.p+p)){ok=false;break;}if(flags&4){if(!SXMF_ADD(c,hpfs_down_pointer,t.p+p+z-4)){ok=false;break;}sxmf_queue_add(q,(uint64_t)sxmf32(b+p+z-4,0)*512,2,t.depth+1);}if(!(flags&8))sxmf_queue_add(q,(uint64_t)sxmf32(b+p+4,0)*512,0,t.depth+1);p+=z;if(flags&8)break;}if(!ok)break;continue;
  }
  unsigned internal=b[off-8]&0x80,used=b[off-3];uint64_t stride=internal?8:12;if(used>capacity/stride)continue;
  if(!sxmf_put(c,internal?&sxmf_hpfs_btree_child:&sxmf_hpfs_extent,t.p+off,used)){ok=false;break;}
  for(unsigned i=0;i<used;i++){uint8_t*r=b+off+i*stride;if(internal)sxmf_queue_add(q,(uint64_t)sxmf32(r+4,0)*512,1,t.depth+1);else if(t.kind==0&&(sxmf16(b+54,0)&0x100)){uint64_t sector=sxmf32(r+8,0),count=sxmf32(r+4,0);for(uint64_t j=0;j+4<=count&&j<4096;j+=4)sxmf_queue_add(q,(sector+j)*512,2,t.depth+1);}}
 }
 xx_rt_free(q);return ok;
}
static bool sxmf_sfs(sx_context*c){uint8_t h[128];if(!sxmf_read(c,0,h,128))return false;uint32_t magic=sxmf32(h,1);if((magic!=0x53465300U&&magic!=0x53465302U)||!SXMF_ADD(c,sfs_root_block,0))return false;uint64_t bs=sxmf32(h+52,1),blocks=sxmf32(h+48,1);if(bs<512||bs>65536||!sxmf_pow(bs)||!blocks||blocks>(uint64_t)c->size/bs)return true;
 uint8_t*b=xx_rt_malloc((size_t)bs);sxmf_queue*q=xx_rt_calloc(1,sizeof(*q));if(!b||!q){xx_rt_free(b);xx_rt_free(q);return false;}bool ok=true;
 if(sxmf_read(c,(blocks-1)*bs,b,128)&&sxmf32(b,1)==magic&&!SXMF_ADD(c,sfs_root_block,(blocks-1)*bs))ok=false;
 sxmf_queue_add(q,(uint64_t)sxmf32(h+104,1)*bs,0,0);sxmf_queue_add(q,(uint64_t)sxmf32(h+108,1)*bs,1,0);
 while(ok&&q->index<q->count&&c->count<SXMF_LIMIT&&!xx_pd_is_stopped(c->pd)){sxmf_task t=q->items[q->index++];if(t.p/bs>=blocks||!sxmf_read(c,t.p,b,(size_t)bs))continue;
  if(t.kind==0){if(sxmf32(b,1)!=0x4f424a43U||sxmf32(b+8,1)!=t.p/bs)continue;if(!SXMF_ADD(c,sfs_object_container,t.p)){ok=false;break;}sxmf_queue_add(q,(uint64_t)sxmf32(b+16,1)*bs,0,t.depth);
   /* SFS2 has a distinct 27-byte object prefix not interpreted here. */
   if(magic!=0x53465300U)continue;for(uint64_t p=24;p+25<=bs;){if(!sxmf32(b+p+4,1))break;bool dir=(b[p+24]&128)!=0;uint64_t end=p+25;unsigned strings=0;while(end<bs&&strings<2){if(!b[end])strings++;end++;}if(strings!=2)break;if(!sxmf_put(c,dir?&sxmf_sfs_directory_object:&sxmf_sfs_file_object,t.p+p,1)){ok=false;break;}if(dir)sxmf_queue_add(q,(uint64_t)sxmf32(b+p+16,1)*bs,0,t.depth+1);p=(end+1)&~UINT64_C(1);}
  }else{if(sxmf32(b,1)!=0x424e4443U||sxmf32(b+8,1)!=t.p/bs)continue;unsigned n=sxmf16(b+12,1),leaf=b[14],stride=b[15];if(!stride||n>(bs-16)/stride)continue;if(!SXMF_ADD(c,sfs_btree_header,t.p)){ok=false;break;}if(leaf&&stride==(magic==0x53465300U?14:16)){ok=sxmf_put(c,magic==0x53465300U?&sxmf_sfs_extent16:&sxmf_sfs_extent32,t.p+16,n);}else if(!leaf&&stride==8){ok=SXMF_TABLE(c,sfs_btree_index,t.p+16,n);for(unsigned i=0;i<n;i++)sxmf_queue_add(q,(uint64_t)sxmf32(b+20+i*8,1)*bs,1,t.depth+1);}}
 }
 xx_rt_free(b);xx_rt_free(q);return ok;
}
static bool sxmf_reiser(sx_context*c){uint8_t h[512];uint64_t super=65536;bool four=false;if(!sxmf_read(c,super,h,512))return false;four=!xx_rt_memcmp(h,"ReIsEr4",7);if(!four&&xx_rt_memcmp(h+52,"ReIsEr",6)){super=8192;if(!sxmf_read(c,super,h,512)||xx_rt_memcmp(h+52,"ReIsErFs",8))return false;}
 uint64_t bs,blocks,root;if(four){if(!SXMF_ADD(c,reiser4_master,super))return false;bs=sxmf16(h+18,0);if(bs<512||bs>65536||!sxmf_pow(bs)||!sxmf_read(c,super+bs,h,512)||xx_rt_memcmp(h+52,"ReIsEr40FoRmAt",13))return true;if(!SXMF_ADD(c,reiser4_format40_superblock,super+bs))return false;blocks=sxmf64(h,0);root=sxmf64(h+16,0);}
 else{bs=sxmf16(h+44,0);blocks=sxmf32(h,0);root=sxmf32(h+8,0);if(!sxmf_put(c,sxmf16(h+72,0)==2?&sxmf_reiser36_superblock:&sxmf_reiser35_superblock,super,1))return false;}
 if(bs<512||bs>65536||!sxmf_pow(bs)||!blocks||blocks>(uint64_t)c->size/bs)return true;uint8_t*b=xx_rt_malloc((size_t)bs);sxmf_queue*q=xx_rt_calloc(1,sizeof(*q));if(!b||!q){xx_rt_free(b);xx_rt_free(q);return false;}bool ok=true;sxmf_queue_add(q,root*bs,0,0);
 while(ok&&q->index<q->count&&c->count<SXMF_LIMIT&&!xx_pd_is_stopped(c->pd)){sxmf_task t=q->items[q->index++];if(t.p/bs>=blocks||!sxmf_read(c,t.p,b,(size_t)bs))continue;
  if(four){unsigned n=sxmf16(b+2,0);if(sxmf16(b,0)!=0||sxmf32(b+8,0)!=0x52344653U||n>(bs-28)/38)continue;if(!SXMF_ADD(c,reiser4_node40_header,t.p)){ok=false;break;}uint64_t headers=bs-(uint64_t)n*38;for(unsigned i=0;i<n;i++){uint64_t hp=bs-(uint64_t)(i+1)*38,dp=sxmf16(b+hp+32,0),end=i+1<n?sxmf16(b+hp-38+32,0):sxmf16(b+6,0);unsigned plugin=sxmf16(b+hp+36,0);if(dp<28||dp>end||end>headers)continue;if(!SXMF_ADD(c,reiser4_item_header_large,t.p+hp)){ok=false;break;}if(plugin==3&&end-dp==8){if(!SXMF_ADD(c,reiser4_child,t.p+dp)){ok=false;break;}uint64_t child=sxmf64(b+dp,0);if(child<blocks)sxmf_queue_add(q,child*bs,0,t.depth+1);}else if(plugin==5&&(end-dp)%16==0&&!SXMF_TABLE(c,reiser4_extent,t.p+dp,(end-dp)/16)){ok=false;break;}}}
  else{unsigned level=sxmf16(b,0),n=sxmf16(b+2,0);if(!level||level>16||n>(bs-24)/24)continue;if(!SXMF_ADD(c,reiser_block_header,t.p)){ok=false;break;}if(level==1){for(unsigned i=0;i<n;i++){uint64_t p=24+i*24,z=sxmf16(b+p+18,0),at=sxmf16(b+p+20,0);if(at<24+n*24||at>bs||z>bs-at)continue;if(!SXMF_ADD(c,reiser_item_header,t.p+p)){ok=false;break;}}}else{uint64_t p=24+(uint64_t)n*16;if(n+1>(bs-p)/8)continue;if(!SXMF_TABLE(c,reiser_child,t.p+p,n+1)){ok=false;break;}for(unsigned i=0;i<=n;i++){uint64_t child=sxmf32(b+p+i*8,0);if(child<blocks)sxmf_queue_add(q,child*bs,0,t.depth+1);}}}
 }
 xx_rt_free(b);xx_rt_free(q);return ok;
}
static bool sxmf_xfs(sx_context*c){uint8_t sb[512],b[512];if(!sxmf_read(c,0,sb,512)||xx_rt_memcmp(sb,"XFSB",4))return false;unsigned version=sxmf16(sb+100,1)&15;if(version!=4&&version!=5)return false;if(!sxmf_put(c,version==5?&sxmf_xfs5_superblock:&sxmf_xfs4_superblock,0,1))return false;uint64_t bs=sxmf32(sb+4,1),blocks=sxmf64(sb+8,1),agblocks=sxmf32(sb+84,1),ags=sxmf32(sb+88,1),sector=sxmf16(sb+102,1),isize=sxmf16(sb+104,1);if(!sxmf_pow(bs)||bs<512||bs>65536||!blocks||blocks>(uint64_t)c->size/bs||!agblocks||!ags||ags>4096||!sxmf_pow(sector)||sector<512||sector>bs)return true;
 for(uint64_t i=0;i<ags;i++){uint64_t ab=i*agblocks;if(ab>=blocks)break;uint64_t p=ab*bs;if(i&&sxmf_read(c,p,b,304)&&!xx_rt_memcmp(b,"XFSB",4)&&!sxmf_put(c,version==5?&sxmf_xfs5_superblock:&sxmf_xfs4_superblock,p,1))return false;
  if(sxmf_read(c,p+sector,b,224)&&!xx_rt_memcmp(b,"XAGF",4)&&!sxmf_put(c,version==5?&sxmf_xfs5_agf:&sxmf_xfs4_agf,p+sector,1))return false;
  if(sxmf_read(c,p+2*sector,b,344)&&!xx_rt_memcmp(b,"XAGI",4)&&!sxmf_put(c,version==5?&sxmf_xfs5_agi:&sxmf_xfs4_agi,p+2*sector,1))return false;
 }
 unsigned ilog=sb[123],alog=sb[124];uint64_t ino=sxmf64(sb+56,1);if(!sxmf_pow(isize)||isize<256||isize>bs||ilog>8||alog>32||ilog+alog>=63||(UINT64_C(1)<<ilog)!=bs/isize)return true;
 uint64_t ag=ino>>(ilog+alog),block=(ino>>ilog)&((UINT64_C(1)<<alog)-1),slot=ino&((UINT64_C(1)<<ilog)-1);if(ag>=ags||block>=agblocks||ag*agblocks+block>=blocks)return true;uint64_t at=(ag*agblocks+block)*bs+slot*isize;if(sxmf_read(c,at,b,176)&&sxmf16(b,1)==0x494e&&(b[4]==2||b[4]==3))return sxmf_put(c,b[4]==3?&sxmf_xfs_inode_v3:&sxmf_xfs_inode_v2,at,1);return true;
}
static bool sxmf_gfs2_dir(sx_context*c,sxmf_queue*q,uint8_t*b,uint64_t p,uint64_t start,uint64_t end,unsigned depth){for(uint64_t at=start;at+40<=end;){uint64_t z=sxmf16(b+at+20,1),n=sxmf16(b+at+22,1);if(z<40||z>end-at||n>z-40||(z&7))break;if(!SXMF_ADD(c,gfs2_directory_entry,p+at))return false;uint64_t child=sxmf64(b+at+8,1);if(n&&child)sxmf_queue_add(q,child,0,depth+1);at+=z;}return true;}
static bool sxmf_gfs2(sx_context*c){uint8_t h[272];if(!sxmf_read(c,65536,h,272)||sxmf32(h,1)!=0x01161970U||sxmf32(h+4,1)!=1||!SXMF_ADD(c,gfs2_superblock,65536))return false;uint64_t bs=sxmf32(h+36,1);if(!sxmf_pow(bs)||bs<512||bs>65536)return true;uint8_t*b=xx_rt_malloc((size_t)bs);sxmf_queue*q=xx_rt_calloc(1,sizeof(*q));if(!b||!q){xx_rt_free(b);xx_rt_free(q);return false;}bool ok=true;sxmf_queue_add(q,sxmf64(h+56,1),0,0);sxmf_queue_add(q,sxmf64(h+88,1),0,0);
 while(ok&&q->index<q->count&&c->count<SXMF_LIMIT&&!xx_pd_is_stopped(c->pd)){sxmf_task t=q->items[q->index++];if(t.p>=(uint64_t)c->size/bs)continue;uint64_t p=t.p*bs;if(!sxmf_read(c,p,b,(size_t)bs)||sxmf32(b,1)!=0x01161970U)continue;unsigned type=sxmf32(b+4,1);
  if(t.kind==0){if(type!=4||sxmf64(b+32,1)!=t.p)continue;if(!SXMF_ADD(c,gfs2_inode,p)){ok=false;break;}uint64_t size=sxmf64(b+56,1);unsigned mode=sxmf32(b+40,1),height=sxmf16(b+138,1);if((mode&0170000)!=0040000||height)continue;
   if(!(sxmf32(b+128,1)&2)){uint64_t end=size<bs-232?232+size:bs;ok=sxmf_gfs2_dir(c,q,b,p,232,end,t.depth);}else if(size<=bs-232&&!(size&7)){for(uint64_t j=0;j<size;j+=8)sxmf_queue_add(q,sxmf64(b+232+j,1),1,t.depth+1);}
  }else{if(type!=6)continue;if(!SXMF_ADD(c,gfs2_leaf,p)){ok=false;break;}sxmf_queue_add(q,sxmf64(b+32,1),1,t.depth);ok=sxmf_gfs2_dir(c,q,b,p,104,bs,t.depth);}
 }
 xx_rt_free(b);xx_rt_free(q);return ok;
}
static bool sxmf_ufs_dir(sx_context*c,uint64_t p,uint64_t size,uint64_t bs,unsigned order,bool solar){uint8_t h[8];for(uint64_t at=0,visits=0;at+8<=size&&visits++<SXMF_INODES&&c->count<SXMF_LIMIT;){uint64_t limit=bs-at%bs;if(limit>size-at)limit=size-at;if(!sxmf_read(c,p+at,h,8))break;uint64_t n=sxmf16(h+4,order),name=solar?sxmf16(h+6,order):h[7];if(n<8||n>limit||(n&3)||name>n-8)break;if(!sxmf_put(c,solar?SXMF_ORDER(sufs_directory_entry,order):SXMF_ORDER(ufs_directory_entry,order),p+at,1))return false;at+=n;}return true;}
static bool sxmf_ufs(sx_context*c){bool solar=c->f->file_type==XX_FILE_TYPE_SUFS,two=c->f->file_type==XX_FILE_TYPE_UFS2;uint64_t candidates[]={two?65536:8192,262144,0},sbp=0;unsigned order=2;uint8_t h[1376];uint32_t magic=two?0x19540119:0x011954;
 for(unsigned i=0;i<(two?3:1);i++)if(sxmf_read(c,candidates[i],h,sizeof(h))){if(sxmf32(h+1372,0)==magic)order=0;else if(sxmf32(h+1372,1)==magic)order=1;else continue;sbp=candidates[i];break;}if(order==2)return false;
 bool updated=two||(h[211]&0x80);const sx_layout*sl=solar?SXMF_ORDER(sufs_superblock,order):updated?SXMF_ORDER(ufs_modern_superblock,order):SXMF_ORDER(ufs1_legacy_superblock,order);if(!sxmf_put(c,sl,sbp,1))return false;
 uint64_t bs=sxmf32(h+48,order),fs=sxmf32(h+52,order),groups=sxmf32(h+44,order),ipg=sxmf32(h+184,order),fpg=sxmf32(h+188,order),iblk=sxmf32(h+16,order),cblk=sxmf32(h+12,order),sblk=sxmf32(h+8,order),goff=sxmf32(h+24,order),gmask=sxmf32(h+28,order),cgsize=sxmf32(h+160,order),isize=two?256:128;
 if(!sxmf_pow(bs)||bs<4096||bs>65536||!sxmf_pow(fs)||fs<512||fs>bs||!groups||groups>4096||!ipg||ipg>SXMF_INODES||!fpg||cgsize<104||cgsize>bs||iblk>=fpg||cblk>=iblk)return true;uint8_t*cg=xx_rt_malloc((size_t)cgsize);uint8_t ino[256];sxmf_queue*q=xx_rt_calloc(1,sizeof(*q));if(!cg||!q){xx_rt_free(cg);xx_rt_free(q);return false;}bool ok=true;uint64_t visited=0;
 for(uint64_t g=0;g<groups&&visited<SXMF_INODES&&c->count<SXMF_LIMIT;g++){uint64_t start=g*fpg+(two?0:goff*(g&~gmask));if(start>UINT64_MAX-iblk||start+iblk>UINT64_MAX/fs)break;uint64_t ip=(start+iblk)*fs,cp=(start+cblk)*fs,sp=(start+sblk)*fs;
  if(!sxmf_read(c,cp,cg,(size_t)cgsize)||sxmf32(cg+4,order)!=0x90255U||sxmf32(cg+12,order)!=g)continue;if(!sxmf_put(c,SXMF_ORDER(ufs_cylinder_group_prefix,order),cp,1)){ok=false;break;}
  uint64_t bitmap=sxmf32(cg+92,order);if(two&&cgsize>=168&&bitmap>=168&&!sxmf_put(c,SXMF_ORDER(ufs_cylinder_group_tail,order),cp+104,1)){ok=false;break;}
  uint8_t sig[4];if(sp!=sbp&&sxmf_read(c,sp+1372,sig,4)&&sxmf32(sig,order)==magic&&!sxmf_put(c,sl,sp,1)){ok=false;break;}
  if(bitmap>cgsize||(ipg+7)/8>cgsize-bitmap||ipg>UINT64_MAX/isize||!sxmf_span(c,ip,ipg*isize))continue;
  for(uint64_t j=0;j<ipg&&visited++<SXMF_INODES&&c->count<SXMF_LIMIT;j++){if(!(cg[bitmap+j/8]&(1U<<(j&7))))continue;uint64_t at=ip+j*isize;if(!sxmf_read(c,at,ino,(size_t)isize))break;unsigned mode=sxmf16(ino,order),kind=mode&0170000;if(!kind)continue;uint64_t size=sxmf64(ino+(two?16:8),order),sectors=two?sxmf64(ino+24,order):sxmf32(ino+104,order);bool inlink=kind==0120000&&!sectors&&size<=(two?120:60);const sx_layout*l=solar?SXMF_ORDER(sufs_inode,order):two?(inlink?SXMF_ORDER(ufs2_symlink_inode,order):SXMF_ORDER(ufs2_inode,order)):(updated?(inlink?SXMF_ORDER(ufs1_symlink_inode,order):SXMF_ORDER(ufs1_inode,order)):(inlink?SXMF_ORDER(ufs1_legacy_symlink_inode,order):SXMF_ORDER(ufs1_legacy_inode,order)));if(!sxmf_put(c,l,at,1)){ok=false;break;}if(inlink)continue;unsigned po=two?112:40,pw=two?8:4;
   for(unsigned k=0;k<3;k++){uint64_t ptr=two?sxmf64(ino+po+12*pw+k*pw,order):sxmf32(ino+po+12*pw+k*pw,order);if(ptr<(uint64_t)c->size/fs)sxmf_queue_add(q,ptr*fs,k+1,0);}
   if(kind==0040000)for(unsigned k=0;k<12&&(uint64_t)k*bs<size;k++){uint64_t ptr=two?sxmf64(ino+po+k*pw,order):sxmf32(ino+po+k*pw,order),n=size-(uint64_t)k*bs;if(n>bs)n=bs;if(ptr&&ptr<(uint64_t)c->size/fs&&sxmf_span(c,ptr*fs,n)&&!sxmf_ufs_dir(c,ptr*fs,n,512,order,solar)){ok=false;break;}}
  }if(!ok)break;
 }
 uint8_t*b=xx_rt_malloc((size_t)bs);if(!b)ok=false;while(ok&&q->index<q->count&&c->count<SXMF_LIMIT){sxmf_task t=q->items[q->index++];if(!sxmf_read(c,t.p,b,(size_t)bs))continue;unsigned pw=two?8:4;if(!sxmf_put(c,two?SXMF_ORDER(ufs_fragment_pointer64,order):SXMF_ORDER(ufs_fragment_pointer32,order),t.p,bs/pw)){ok=false;break;}if(t.kind>1)for(uint64_t k=0;k<bs/pw;k++){uint64_t ptr=two?sxmf64(b+k*pw,order):sxmf32(b+k*pw,order);if(ptr<(uint64_t)c->size/fs)sxmf_queue_add(q,ptr*fs,t.kind-1,t.depth+1);}}
 xx_rt_free(b);xx_rt_free(cg);xx_rt_free(q);return ok;
}
static bool sxmf_ha_address(uint64_t begin,uint64_t end,uint64_t encoded,uint64_t bytes,uint64_t*out){unsigned zone=(unsigned)(encoded>>60);uint64_t off=encoded&UINT64_C(0xfffffffffffff);if(begin>end||((encoded>>52)&255)||(zone!=2&&zone!=8&&zone!=9&&zone!=10&&zone!=11)||off>end-begin||bytes>end-begin-off)return false;*out=begin+off;return true;}
static bool sxmf_hammer(sx_context*c){uint8_t h[264],b[4096];if(!sxmf_read(c,0,h,264))return false;unsigned o=sxmf64(h,0)==UINT64_C(0xc8414d4dc5523031)?0:sxmf64(h,1)==UINT64_C(0xc8414d4dc5523031)?1:2;if(o==2||!sxmf_put(c,SXMF_ORDER(hammer_volume_header,o),0,1)||!sxmf_put(c,SXMF_ORDER(hammer_blockmap,o),264,16)||!sxmf_put(c,SXMF_ORDER(hammer_undo_pointer,o),904,128))return false;uint64_t begin=sxmf64(h+24,o),end=sxmf64(h+32,o),root;if(begin<8192||begin>=end||end>(uint64_t)c->size||!sxmf_ha_address(begin,end,sxmf64(h+240,o),4096,&root))return true;
 sxmf_queue*q=xx_rt_calloc(1,sizeof(*q));if(!q)return false;bool ok=true;sxmf_queue_add(q,root,0,0);while(ok&&q->index<q->count&&c->count<SXMF_LIMIT){sxmf_task t=q->items[q->index++];if(!sxmf_read(c,t.p,b,4096))continue;unsigned n=sxmf32(b+16,o),kind=b[20];if((kind!='I'&&kind!='L')||n>(kind=='I'?62U:63U))continue;if(!sxmf_put(c,SXMF_ORDER(hammer_node_header,o),t.p,1)||!sxmf_put(c,kind=='I'?SXMF_ORDER(hammer_internal_record,o):SXMF_ORDER(hammer_leaf_record,o),t.p+64,n)){ok=false;break;}
  for(unsigned j=0;j<n;j++){uint8_t*r=b+64+j*64;uint64_t at;if(kind=='I'){if(sxmf_ha_address(begin,end,sxmf64(r+48,o),4096,&at))sxmf_queue_add(q,at,0,t.depth+1);}else{uint64_t nbytes=sxmf32(r+56,o);unsigned type=sxmf16(r+32,o);if(!sxmf_ha_address(begin,end,sxmf64(r+48,o),nbytes,&at))continue;if(type==1&&nbytes==128){if(!sxmf_put(c,SXMF_ORDER(hammer_inode,o),at,1)){ok=false;break;}}else if(type==0x11&&nbytes>=16&&!sxmf_put(c,SXMF_ORDER(hammer_directory_entry,o),at,1)){ok=false;break;}}}
 }xx_rt_free(q);return ok;
}
static bool sxmf_vmfs(sx_context*c){uint8_t h[1024],b[2048];if(!sxmf_read(c,1048576,h,1024)||sxmf32(h,0)!=0xc001d00dU||!SXMF_ADD(c,vmfs_volume_header,1048576)||!SXMF_ADD(c,vmfs35_lvm_header,1049088))return false;const uint64_t base=0x1100000,super=0x1300000;if(!sxmf_read(c,super,h,512)||sxmf32(h,0)!=0x2fabf15eU||(h[8]!=3&&h[8]!=5))return true;if(!SXMF_ADD(c,vmfs35_filesystem_header,super))return false;uint64_t bs=sxmf64(h+161,0);if(!sxmf_pow(bs)||bs<1048576||bs>8388608)return true;uint64_t fdc=base+(0x400000/bs)*bs;if(fdc==base)fdc+=bs;if(!sxmf_read(c,fdc,h,28))return true;uint64_t items=sxmf32(h,0),entries=sxmf32(h+4,0),hdr=sxmf32(h+8,0),data=sxmf32(h+12,0),area=sxmf32(h+16,0),total=sxmf32(h+20,0);if(!items||items>1024||!entries||entries>4096||data!=2048||hdr<28||area<entries*1024+items*entries*data||!total||total>65536)return true;if(!SXMF_ADD(c,vmfs35_bitmap_header,fdc))return false;uint64_t per=items*entries;
 for(uint64_t i=0;i<total&&i<4096&&c->count<SXMF_LIMIT;i++){uint64_t p=fdc+hdr+(i/per)*area+entries*1024+(i%per)*data;if(!sxmf_read(c,p,b,2048)||sxmf32(b,0)!=0x10c00001U)continue;if(!SXMF_ADD(c,vmfs35_metadata_header,p)||!SXMF_ADD(c,vmfs35_inode_data,p+512))return false;uint64_t n=sxmf64(b+532,0);unsigned format=sxmf32(b+580,0),type=sxmf32(b+524,0);
  if(format==4305){if(n>1024)continue;if(type==2&&n%140==0&&!SXMF_TABLE(c,vmfs35_directory_entry,p+1024,n/140))return false;}
  else if(format==1&&!SXMF_TABLE(c,vmfs35_block_id,p+1024,256))return false;
 }return true;
}
static bool sxmf_erofs(sx_context*c){uint8_t h[128],in[64];if(!sxmf_read(c,1024,h,128)||sxmf32(h,0)!=0xe0f5e1e2U||!SXMF_ADD(c,erofs_superblock,1024))return false;unsigned shift=h[12];if(shift<9||shift>16)return true;uint64_t bs=UINT64_C(1)<<shift,meta=(uint64_t)sxmf32(h+40,0)*bs,devices=sxmf16(h+86,0),slots=(uint64_t)sxmf16(h+88,0)*128;if(devices<=256&&sxmf_span(c,slots,devices*128)&&!SXMF_TABLE(c,erofs_device_slot,slots,devices))return false;sxmf_queue*q=xx_rt_calloc(1,sizeof(*q));uint8_t*b=xx_rt_malloc((size_t)bs);if(!q||!b){xx_rt_free(q);xx_rt_free(b);return false;}bool ok=true;uint64_t root=sxmf16(h+14,0);/* Encode NID+1 so the generic work queue can retain NID zero. */sxmf_queue_add(q,root+1,0,0);
 while(ok&&q->index<q->count&&c->count<SXMF_LIMIT){sxmf_task t=q->items[q->index++];uint64_t nid=t.p-1;if(nid>(UINT64_MAX-meta)/32)continue;uint64_t p=meta+nid*32;if(!sxmf_read(c,p,in,32))continue;unsigned format=sxmf16(in,0),layout=(format>>1)&7,iz=(format&1)?64:32,mode=sxmf16(in+4,0);if(format&0xfff0||layout>4||!sxmf_read(c,p,in,iz))continue;if(!sxmf_put(c,iz==64?&sxmf_erofs_inode_extended:&sxmf_erofs_inode_compact,p,1)){ok=false;break;}uint64_t size=iz==64?sxmf64(in+8,0):sxmf32(in+8,0),block=sxmf32(in+16,0);if(sxmf16(in+2,0))continue;
  if(layout==4){if(block<=16){uint64_t chunk=bs<<block,n=size/chunk+(size%chunk!=0);if(n<=SXMF_INODES&&sxmf_span(c,p+iz,n*4)&&!SXMF_TABLE(c,erofs_chunk_block,p+iz,n)){ok=false;break;}}continue;}
  if((mode&0170000)!=0040000||(layout!=0&&layout!=2)||size>UINT64_C(16777216))continue;uint64_t whole=layout==2?size/bs*bs:size;
  for(uint64_t pos=0;pos<size&&ok&&c->count<SXMF_LIMIT;pos+=bs){uint64_t n=size-pos;if(n>bs)n=bs;uint64_t at=pos<whole?block*bs+pos:p+iz+pos-whole;if(!sxmf_read(c,at,b,(size_t)n)||n<12)break;uint64_t first=sxmf16(b+8,0);if(!first||first%12||first>n)break;for(uint64_t j=0;j<first;j+=12){uint64_t no=sxmf16(b+j+8,0),end=j+12<first?sxmf16(b+j+20,0):n;if(no<first||end<no||end>n)break;if(!SXMF_ADD(c,erofs_directory_entry,at+j)){ok=false;break;}uint64_t child=sxmf64(b+j,0);if(child!=UINT64_MAX)sxmf_queue_add(q,child+1,0,t.depth+1);}}
 }
 xx_rt_free(q);xx_rt_free(b);return ok;
}
typedef struct sxmf_op_task{uint64_t avatar,block,blocks,burst,gap;unsigned depth;}sxmf_op_task;
static bool sxmf_opera(sx_context*c){uint8_t h[132];if(!sxmf_read(c,0,h,132)||h[0]!=1||xx_rt_memcmp(h+1,"ZZZZZ",5)||!SXMF_ADD(c,opera_disc_label,0))return false;uint64_t volbs=sxmf32(h+76,1);if(!sxmf_pow(volbs)||volbs<512||volbs>65536)return true;sxmf_op_task*q=xx_rt_calloc(4096,sizeof(*q));uint8_t*b=xx_rt_malloc(65536);if(!q||!b){xx_rt_free(q);xx_rt_free(b);return false;}size_t count=1,index=0;bool ok=true;q[0]=(sxmf_op_task){sxmf32(h+100,1),sxmf32(h+92,1),sxmf32(h+88,1),0,0,0};
 while(ok&&index<count&&c->count<SXMF_LIMIT){sxmf_op_task t=q[index++];if(t.depth>32||!t.blocks||!sxmf_pow(t.block)||t.block<volbs||t.block>65536||(!t.burst&&t.gap))continue;uint64_t logical=0;for(uint64_t visit=0;visit<t.blocks&&visit<4096&&c->count<SXMF_LIMIT;visit++){if(logical>=t.blocks)break;uint64_t physical=logical;if(t.burst)physical+=(logical/t.burst)*t.gap;if(physical>UINT64_MAX/t.block||t.avatar>UINT64_MAX/volbs||physical*t.block>UINT64_MAX-t.avatar*volbs)break;uint64_t p=t.avatar*volbs+physical*t.block;if(!sxmf_read(c,p,b,(size_t)t.block))break;uint64_t first=sxmf32(b+16,1),free=sxmf32(b+12,1),next=sxmf32(b,1);if(first<20||first>free||free>t.block)break;if(!SXMF_ADD(c,opera_directory_header,p)){ok=false;break;}
   for(uint64_t at=first;at+68<=free;){uint64_t last=sxmf32(b+at+64,1),flags=sxmf32(b+at,1);if(last>255||last+1>(free-at-68)/4)break;if(!SXMF_ADD(c,opera_directory_record,p+at)||!SXMF_TABLE(c,opera_avatar,p+at+68,last+1)){ok=false;break;}if((flags&1)&&count<4096){sxmf_op_task child={sxmf32(b+at+68,1),sxmf32(b+at+12,1),sxmf32(b+at+20,1),sxmf32(b+at+24,1),sxmf32(b+at+28,1),t.depth+1};bool seen=false;for(size_t j=0;j<count;j++)if(q[j].avatar==child.avatar)seen=true;if(!seen)q[count++]=child;}at+=68+4*(last+1);if(flags&0xc0000000U)break;}
   if(!ok||next==UINT32_MAX)break;logical=next;
  }
 }xx_rt_free(q);xx_rt_free(b);return ok;
}
static bool sxmf_ci_read(sx_context*c,uint64_t logical,void*out,size_t n,unsigned stride){uint8_t*p=out;while(n){uint64_t block=logical/2048,within=logical%2048,part=2048-within;if(part>n)part=n;if(block>UINT64_MAX/stride||!sxmf_read(c,block*stride+(stride==2352?24:0)+within,p,(size_t)part))return false;p+=part;n-=(size_t)part;logical+=part;}return true;}
static bool sxmf_ci_frame(sx_context*c,uint64_t block,unsigned stride){if(stride!=2352)return true;uint8_t h[24];uint64_t p=block*2352;if(!sxmf_read(c,p,h,24)||h[15]!=2||xx_rt_memcmp(h+16,h+20,4)||(h[18]&0x20))return true;return SXMF_ADD(c,cdi_mode2_sector_header,p)&&SXMF_ADD(c,cdi_form1_edc,p+2072);}
static bool sxmf_ci_row(sx_context*c,const sx_layout*l,uint64_t logical,unsigned stride){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t n=(uint64_t)(f->rel_offset+f->size),block=logical/2048,within=logical%2048;if(stride==2352&&n>2048-within)return true;if(!sxmf_ci_frame(c,block,stride))return false;return sxmf_put(c,l,block*stride+(stride==2352?24:0)+within,1);}
static bool sxmf_cdi(sx_context*c){uint8_t h[2048],b[2048];unsigned stride=2048;if(!sxmf_ci_read(c,16*2048,h,2048,stride)||h[0]!=1||xx_rt_memcmp(h+1,"CD-I ",5)){stride=2352;if(!sxmf_ci_read(c,16*2048,h,2048,stride)||h[0]!=1||xx_rt_memcmp(h+1,"CD-I ",5))return false;}if(!sxmf_ci_row(c,&sxmf_cdi_volume_descriptor,16*2048,stride))return false;uint64_t blocks=sxmf32(h+84,1),path=sxmf32(h+148,1),bytes=sxmf32(h+136,1);if(blocks>(uint64_t)c->size/stride||path>=blocks||bytes>1048576||bytes>(blocks-path)*2048)return true;
 for(uint64_t i=17;i<blocks&&i<80;i++){if(!sxmf_ci_read(c,i*2048,b,2048,stride)||xx_rt_memcmp(b+1,"CD-I ",5)||b[6]!=1)break;if(b[0]==255){if(!sxmf_ci_row(c,&sxmf_cdi_terminator,i*2048,stride))return false;break;}if(b[0]==1&&!sxmf_ci_row(c,&sxmf_cdi_volume_descriptor,i*2048,stride))return false;}
 sxmf_queue*q=xx_rt_calloc(1,sizeof(*q));if(!q)return false;bool ok=true;for(uint64_t p=0;p+8<=bytes&&c->count<SXMF_LIMIT;){uint8_t d[8];if(!sxmf_ci_read(c,path*2048+p,d,8,stride)||!d[0])break;uint64_t z=8+d[0]+(d[0]&1),dir=sxmf32(d+2,1);if(z>bytes-p)break;if(!sxmf_ci_row(c,&sxmf_cdi_path_entry,path*2048+p,stride)){ok=false;break;}if(dir<blocks)sxmf_queue_add(q,dir,0,0);p+=z;}
 while(ok&&q->index<q->count&&c->count<SXMF_LIMIT){uint64_t block=q->items[q->index++].p;if(!sxmf_ci_read(c,block*2048,b,2048,stride)||b[0]<33)continue;uint64_t size=sxmf32(b+14,1);if(size>UINT64_C(16777216)||(size+2047)/2048>blocks-block)continue;for(uint64_t pos=0;pos<size&&c->count<SXMF_LIMIT&&ok;pos+=2048){uint64_t limit=size-pos;if(limit>2048)limit=2048;if(!sxmf_ci_read(c,block*2048+pos,b,(size_t)limit,stride))break;for(uint64_t at=0;at+33<=limit;){uint64_t z=b[at],n=b[at+32],tail=33+n+((n&1)==0);if(!z)break;if(z>limit-at||z<33||tail>z||10>z-tail)break;if(!sxmf_ci_row(c,&sxmf_cdi_directory_entry,block*2048+pos+at,stride)||!sxmf_ci_row(c,&sxmf_cdi_directory_attributes,block*2048+pos+at+tail,stride)){ok=false;break;}at+=z;}}}
 xx_rt_free(q);return ok;
}
static bool sx_modernfs_supports(xx_file_type_t type){switch(type){
 case XX_FILE_TYPE_UFS1:case XX_FILE_TYPE_UFS2:case XX_FILE_TYPE_SUFS:case XX_FILE_TYPE_F2FS:case XX_FILE_TYPE_JFS:case XX_FILE_TYPE_NILFS2:case XX_FILE_TYPE_REISERFS:case XX_FILE_TYPE_AMIGA_SFS:case XX_FILE_TYPE_XFS:case XX_FILE_TYPE_ZFS:case XX_FILE_TYPE_GFS2:case XX_FILE_TYPE_FOSSIL_FS:case XX_FILE_TYPE_HAMMER_FS:case XX_FILE_TYPE_REFS:case XX_FILE_TYPE_VXFS:case XX_FILE_TYPE_VMFS:case XX_FILE_TYPE_HPFS:case XX_FILE_TYPE_EROFS:case XX_FILE_TYPE_CDI_FS:case XX_FILE_TYPE_OPERA_FS:return true;default:return false;}}
static int sxmf_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxmf_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxmf_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_modernfs_build(sx_context*c){bool ok=false;switch(c->f->file_type){
 case XX_FILE_TYPE_UFS1:case XX_FILE_TYPE_UFS2:case XX_FILE_TYPE_SUFS:ok=sxmf_ufs(c);break;
 case XX_FILE_TYPE_F2FS:ok=sxmf_f2fs(c);break;case XX_FILE_TYPE_JFS:ok=sxmf_jfs(c);break;case XX_FILE_TYPE_NILFS2:ok=sxmf_nilfs(c);break;
 case XX_FILE_TYPE_REISERFS:ok=sxmf_reiser(c);break;case XX_FILE_TYPE_AMIGA_SFS:ok=sxmf_sfs(c);break;case XX_FILE_TYPE_XFS:ok=sxmf_xfs(c);break;case XX_FILE_TYPE_ZFS:ok=sxmf_zfs(c);break;case XX_FILE_TYPE_GFS2:ok=sxmf_gfs2(c);break;case XX_FILE_TYPE_FOSSIL_FS:ok=sxmf_fossil(c);break;case XX_FILE_TYPE_HAMMER_FS:ok=sxmf_hammer(c);break;case XX_FILE_TYPE_REFS:ok=sxmf_refs(c);break;case XX_FILE_TYPE_VXFS:ok=sxmf_vxfs(c);break;case XX_FILE_TYPE_VMFS:ok=sxmf_vmfs(c);break;case XX_FILE_TYPE_HPFS:ok=sxmf_hpfs(c);break;case XX_FILE_TYPE_EROFS:ok=sxmf_erofs(c);break;case XX_FILE_TYPE_CDI_FS:ok=sxmf_cdi(c);break;case XX_FILE_TYPE_OPERA_FS:ok=sxmf_opera(c);break;default:return false;}
 /* A malformed optional pointer may leave a valid bounded header. */
 return (ok||c->count)&&!c->failed&&!xx_pd_is_stopped(c->pd)&&c->count&&sxmf_finish(c);
}
#undef SXMF_ADD
#undef SXMF_TABLE
#undef SXMF_ORDER
#undef SXMF_UNIX
#undef SXMF_LIMIT
#undef SXMF_INODES
