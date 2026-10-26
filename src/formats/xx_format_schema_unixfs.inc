/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical EXT/SquashFS layouts; docs/data_struct_unixfs_scope.txt describes limits. */
static const xx_data_struct_field_desc sxuf_ext_dynamic_superblock_fields[] = {
    SX_FIELD("inodes_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("blocks_count_lo","uint32",4,4,SX_NONE),
    SX_FIELD("r_blocks_count_lo","uint32",8,4,SX_NONE),
    SX_FIELD("free_blocks_count_lo","uint32",12,4,SX_NONE),
    SX_FIELD("free_inodes_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("first_data_block","uint32",20,4,SX_ID),
    SX_FIELD("log_block_size","uint32",24,4,SX_NONE),
    SX_FIELD("log_cluster_or_fragment_size","int32",28,4,SX_NONE),
    SX_FIELD("blocks_per_group","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("clusters_or_fragments_per_group","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("inodes_per_group","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("mtime","uint32",44,4,SX_NONE),
    SX_FIELD("wtime","uint32",48,4,SX_NONE),
    SX_FIELD("mnt_count","uint16",52,2,SX_COUNT_PROP),
    SX_FIELD("max_mnt_count","int16",54,2,SX_NONE),
    SX_FIELD("magic","uint16",56,2,SX_SIGNATURE),
    SX_FIELD("state","uint16",58,2,SX_FLAGS),
    SX_FIELD("errors","uint16",60,2,SX_NONE),
    SX_FIELD("minor_rev_level","uint16",62,2,SX_NONE),
    SX_FIELD("lastcheck","uint32",64,4,SX_NONE),
    SX_FIELD("checkinterval","uint32",68,4,SX_NONE),
    SX_FIELD("creator_os","uint32",72,4,SX_ID),
    SX_FIELD("rev_level","uint32",76,4,SX_NONE),
    SX_FIELD("def_resuid","uint16",80,2,SX_NONE),
    SX_FIELD("def_resgid","uint16",82,2,SX_NONE),
    SX_FIELD("first_ino","uint32",84,4,SX_ID),
    SX_FIELD("inode_size","uint16",88,2,SX_SIZE),
    SX_FIELD("block_group_nr","uint16",90,2,SX_ID),
    SX_FIELD("feature_compat","uint32",92,4,SX_FLAGS),
    SX_FIELD("feature_incompat","uint32",96,4,SX_FLAGS),
    SX_FIELD("feature_ro_compat","uint32",100,4,SX_FLAGS),
    SX_FIELD("uuid","uint8[16]",104,16,SX_NONE),
    SX_FIELD("volume_name","char[16]",120,16,SX_STRING),
    SX_FIELD("last_mounted","char[64]",136,64,SX_STRING),
    SX_FIELD("algorithm_usage_bitmap","uint32",200,4,SX_FLAGS),
    SX_FIELD("prealloc_blocks","uint8",204,1,SX_COUNT_PROP),
    SX_FIELD("prealloc_dir_blocks","uint8",205,1,SX_COUNT_PROP),
    SX_FIELD("reserved_gdt_blocks","uint16",206,2,SX_COUNT_PROP),
    SX_FIELD("journal_uuid","uint8[16]",208,16,SX_NONE),
    SX_FIELD("journal_inum","uint32",224,4,SX_ID),
    SX_FIELD("journal_dev","uint32",228,4,SX_ID),
    SX_FIELD("last_orphan","uint32",232,4,SX_ID),
    SX_FIELD("hash_seed","uint32[4]",236,16,SX_NONE),
    SX_FIELD("def_hash_version","uint8",252,1,SX_NONE),
    SX_FIELD("jnl_backup_type","uint8",253,1,SX_NONE),
    SX_FIELD("desc_size","uint16",254,2,SX_SIZE),
    SX_FIELD("default_mount_opts","uint32",256,4,SX_FLAGS),
    SX_FIELD("first_meta_bg","uint32",260,4,SX_ID),
    SX_FIELD("mkfs_time","uint32",264,4,SX_NONE),
    SX_FIELD("jnl_blocks","uint32[17]",268,68,SX_NONE),
    SX_FIELD("blocks_count_hi","uint32",336,4,SX_NONE),
    SX_FIELD("r_blocks_count_hi","uint32",340,4,SX_NONE),
    SX_FIELD("free_blocks_count_hi","uint32",344,4,SX_NONE),
    SX_FIELD("min_extra_isize","uint16",348,2,SX_SIZE),
    SX_FIELD("want_extra_isize","uint16",350,2,SX_SIZE),
    SX_FIELD("flags","uint32",352,4,SX_FLAGS),
    SX_FIELD("raid_stride","uint16",356,2,SX_NONE),
    SX_FIELD("mmp_update_interval","uint16",358,2,SX_NONE),
    SX_FIELD("mmp_block","uint64",360,8,SX_ID),
    SX_FIELD("raid_stripe_width","uint32",368,4,SX_NONE),
    SX_FIELD("log_groups_per_flex","uint8",372,1,SX_NONE),
    SX_FIELD("checksum_type","uint8",373,1,SX_NONE),
    SX_FIELD("encryption_level","uint8",374,1,SX_NONE),
    SX_FIELD("reserved_pad","uint8",375,1,SX_RESERVED),
    SX_FIELD("kbytes_written","uint64",376,8,SX_NONE),
    SX_FIELD("snapshot_inum","uint32",384,4,SX_ID),
    SX_FIELD("snapshot_id","uint32",388,4,SX_ID),
    SX_FIELD("snapshot_r_blocks_count","uint64",392,8,SX_COUNT_PROP),
    SX_FIELD("snapshot_list","uint32",400,4,SX_ID),
    SX_FIELD("error_count","uint32",404,4,SX_COUNT_PROP),
    SX_FIELD("first_error_time","uint32",408,4,SX_NONE),
    SX_FIELD("first_error_ino","uint32",412,4,SX_ID),
    SX_FIELD("first_error_block","uint64",416,8,SX_ID),
    SX_FIELD("first_error_func","char[32]",424,32,SX_STRING),
    SX_FIELD("first_error_line","uint32",456,4,SX_NONE),
    SX_FIELD("last_error_time","uint32",460,4,SX_NONE),
    SX_FIELD("last_error_ino","uint32",464,4,SX_ID),
    SX_FIELD("last_error_line","uint32",468,4,SX_NONE),
    SX_FIELD("last_error_block","uint64",472,8,SX_ID),
    SX_FIELD("last_error_func","char[32]",480,32,SX_STRING),
    SX_FIELD("mount_opts","char[64]",512,64,SX_STRING),
    SX_FIELD("usr_quota_inum","uint32",576,4,SX_ID),
    SX_FIELD("grp_quota_inum","uint32",580,4,SX_ID),
    SX_FIELD("overhead_clusters","uint32",584,4,SX_COUNT_PROP),
    SX_FIELD("backup_bgs","uint32[2]",588,8,SX_ID),
    SX_FIELD("encrypt_algos","uint8[4]",596,4,SX_NONE),
    SX_FIELD("encrypt_pw_salt","uint8[16]",600,16,SX_NONE),
    SX_FIELD("lpf_ino","uint32",616,4,SX_ID),
    SX_FIELD("prj_quota_inum","uint32",620,4,SX_ID),
    SX_FIELD("checksum_seed","uint32",624,4,SX_NONE),
    SX_FIELD("wtime_hi","uint8",628,1,SX_NONE),
    SX_FIELD("mtime_hi","uint8",629,1,SX_NONE),
    SX_FIELD("mkfs_time_hi","uint8",630,1,SX_NONE),
    SX_FIELD("lastcheck_hi","uint8",631,1,SX_NONE),
    SX_FIELD("first_error_time_hi","uint8",632,1,SX_NONE),
    SX_FIELD("last_error_time_hi","uint8",633,1,SX_NONE),
    SX_FIELD("first_error_errcode","uint8",634,1,SX_NONE),
    SX_FIELD("last_error_errcode","uint8",635,1,SX_NONE),
    SX_FIELD("encoding","uint16",636,2,SX_NONE),
    SX_FIELD("encoding_flags","uint16",638,2,SX_FLAGS),
    SX_FIELD("orphan_file_inum","uint32",640,4,SX_ID),
    SX_FIELD("def_resuid_hi","uint16",644,2,SX_NONE),
    SX_FIELD("def_resgid_hi","uint16",646,2,SX_NONE),
    SX_FIELD("reserved","uint32[93]",648,372,SX_RESERVED),
    SX_FIELD("checksum","uint32",1020,4,SX_CHECKSUM),
};
static const sx_layout sxuf_ext_dynamic_superblock = {UINT32_C(0x60110001),"ext_dynamic_superblock",sxuf_ext_dynamic_superblock_fields,SX_COUNT(sxuf_ext_dynamic_superblock_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_original_superblock_fields[] = {
    SX_FIELD("inodes_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("blocks_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("r_blocks_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("free_blocks_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("free_inodes_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("first_data_block","uint32",20,4,SX_ID),
    SX_FIELD("log_block_size","uint32",24,4,SX_NONE),
    SX_FIELD("log_fragment_size","int32",28,4,SX_NONE),
    SX_FIELD("blocks_per_group","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("fragments_per_group","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("inodes_per_group","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("mtime","uint32",44,4,SX_TIME),
    SX_FIELD("wtime","uint32",48,4,SX_TIME),
    SX_FIELD("mnt_count","uint16",52,2,SX_COUNT_PROP),
    SX_FIELD("max_mnt_count","int16",54,2,SX_NONE),
    SX_FIELD("magic","uint16",56,2,SX_SIGNATURE),
    SX_FIELD("state","uint16",58,2,SX_FLAGS),
    SX_FIELD("errors","uint16",60,2,SX_NONE),
    SX_FIELD("minor_rev_level","uint16",62,2,SX_NONE),
    SX_FIELD("lastcheck","uint32",64,4,SX_TIME),
    SX_FIELD("checkinterval","uint32",68,4,SX_NONE),
    SX_FIELD("creator_os","uint32",72,4,SX_ID),
    SX_FIELD("rev_level","uint32",76,4,SX_NONE),
    SX_FIELD("def_resuid","uint16",80,2,SX_NONE),
    SX_FIELD("def_resgid","uint16",82,2,SX_NONE),
};
static const sx_layout sxuf_ext_original_superblock = {UINT32_C(0x60110002),"ext_original_superblock",sxuf_ext_original_superblock_fields,SX_COUNT(sxuf_ext_original_superblock_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_group_descriptor_64_fields[] = {
    SX_FIELD("block_bitmap_lo","uint32",0,4,SX_ID),
    SX_FIELD("inode_bitmap_lo","uint32",4,4,SX_ID),
    SX_FIELD("inode_table_lo","uint32",8,4,SX_ID),
    SX_FIELD("free_blocks_count_lo","uint16",12,2,SX_NONE),
    SX_FIELD("free_inodes_count_lo","uint16",14,2,SX_NONE),
    SX_FIELD("used_dirs_count_lo","uint16",16,2,SX_NONE),
    SX_FIELD("flags","uint16",18,2,SX_FLAGS),
    SX_FIELD("exclude_bitmap_lo","uint32",20,4,SX_ID),
    SX_FIELD("block_bitmap_csum_lo","uint16",24,2,SX_NONE),
    SX_FIELD("inode_bitmap_csum_lo","uint16",26,2,SX_NONE),
    SX_FIELD("itable_unused_lo","uint16",28,2,SX_NONE),
    SX_FIELD("checksum","uint16",30,2,SX_CHECKSUM),
    SX_FIELD("block_bitmap_hi","uint32",32,4,SX_ID),
    SX_FIELD("inode_bitmap_hi","uint32",36,4,SX_ID),
    SX_FIELD("inode_table_hi","uint32",40,4,SX_ID),
    SX_FIELD("free_blocks_count_hi","uint16",44,2,SX_NONE),
    SX_FIELD("free_inodes_count_hi","uint16",46,2,SX_NONE),
    SX_FIELD("used_dirs_count_hi","uint16",48,2,SX_NONE),
    SX_FIELD("itable_unused_hi","uint16",50,2,SX_NONE),
    SX_FIELD("exclude_bitmap_hi","uint32",52,4,SX_ID),
    SX_FIELD("block_bitmap_csum_hi","uint16",56,2,SX_NONE),
    SX_FIELD("inode_bitmap_csum_hi","uint16",58,2,SX_NONE),
    SX_FIELD("reserved","uint32",60,4,SX_RESERVED),
};
static const sx_layout sxuf_ext_group_descriptor_64 = {UINT32_C(0x60110003),"ext_group_descriptor_64",sxuf_ext_group_descriptor_64_fields,SX_COUNT(sxuf_ext_group_descriptor_64_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_group_descriptor_32_fields[] = {
    SX_FIELD("block_bitmap","uint32",0,4,SX_ID),
    SX_FIELD("inode_bitmap","uint32",4,4,SX_ID),
    SX_FIELD("inode_table","uint32",8,4,SX_ID),
    SX_FIELD("free_blocks_count","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("free_inodes_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("used_dirs_count","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint16",18,2,SX_FLAGS),
    SX_FIELD("exclude_bitmap","uint32",20,4,SX_ID),
    SX_FIELD("block_bitmap_csum","uint16",24,2,SX_NONE),
    SX_FIELD("inode_bitmap_csum","uint16",26,2,SX_NONE),
    SX_FIELD("itable_unused","uint16",28,2,SX_COUNT_PROP),
    SX_FIELD("checksum","uint16",30,2,SX_CHECKSUM),
};
static const sx_layout sxuf_ext_group_descriptor_32 = {UINT32_C(0x60110004),"ext_group_descriptor_32",sxuf_ext_group_descriptor_32_fields,SX_COUNT(sxuf_ext_group_descriptor_32_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_original_group_descriptor_fields[] = {
    SX_FIELD("block_bitmap","uint32",0,4,SX_ID),
    SX_FIELD("inode_bitmap","uint32",4,4,SX_ID),
    SX_FIELD("inode_table","uint32",8,4,SX_ID),
    SX_FIELD("free_blocks_count","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("free_inodes_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("used_dirs_count","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("padding","uint16",18,2,SX_RESERVED),
    SX_FIELD("reserved","uint32[3]",20,12,SX_RESERVED),
};
static const sx_layout sxuf_ext_original_group_descriptor = {UINT32_C(0x60110005),"ext_original_group_descriptor",sxuf_ext_original_group_descriptor_fields,SX_COUNT(sxuf_ext_original_group_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_linux_inode_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("uid_low","uint16",2,2,SX_NONE),
    SX_FIELD("size_low","uint32",4,4,SX_NONE),
    SX_FIELD("atime_low","int32",8,4,SX_NONE),
    SX_FIELD("ctime_low","int32",12,4,SX_NONE),
    SX_FIELD("mtime_low","int32",16,4,SX_NONE),
    SX_FIELD("deletion_time_or_next_orphan","uint32",20,4,SX_NONE),
    SX_FIELD("gid_low","uint16",24,2,SX_NONE),
    SX_FIELD("links_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("blocks_low","uint32",28,4,SX_NONE),
    SX_FIELD("flags","uint32",32,4,SX_FLAGS),
    SX_FIELD("version_low_or_reserved","uint32",36,4,SX_NONE),
    SX_FIELD("block_map_or_inline_data","uint8[60]",40,60,SX_NONE),
    SX_FIELD("generation","uint32",100,4,SX_NONE),
    SX_FIELD("file_acl_block_low","uint32",104,4,SX_ID),
    SX_FIELD("size_high_or_dir_acl","uint32",108,4,SX_NONE),
    SX_FIELD("obsolete_fragment_block","uint32",112,4,SX_ID),
    SX_FIELD("blocks_high_or_fragment_bytes","uint16",116,2,SX_NONE),
    SX_FIELD("file_acl_block_high_or_reserved","uint16",118,2,SX_ID),
    SX_FIELD("uid_high","uint16",120,2,SX_NONE),
    SX_FIELD("gid_high","uint16",122,2,SX_NONE),
    SX_FIELD("checksum_low_or_reserved","uint16",124,2,SX_NONE),
    SX_FIELD("reserved","uint16",126,2,SX_RESERVED),
};
static const sx_layout sxuf_ext_linux_inode = {UINT32_C(0x60110006),"ext_linux_inode",sxuf_ext_linux_inode_fields,SX_COUNT(sxuf_ext_linux_inode_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_other_os_inode_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("uid_low","uint16",2,2,SX_NONE),
    SX_FIELD("size_low","uint32",4,4,SX_NONE),
    SX_FIELD("atime_low","int32",8,4,SX_NONE),
    SX_FIELD("ctime_low","int32",12,4,SX_NONE),
    SX_FIELD("mtime_low","int32",16,4,SX_NONE),
    SX_FIELD("deletion_time_or_next_orphan","uint32",20,4,SX_NONE),
    SX_FIELD("gid_low","uint16",24,2,SX_NONE),
    SX_FIELD("links_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("blocks_low","uint32",28,4,SX_NONE),
    SX_FIELD("flags","uint32",32,4,SX_FLAGS),
    SX_FIELD("os_dependent1","uint8[4]",36,4,SX_NONE),
    SX_FIELD("block_map_or_inline_data","uint8[60]",40,60,SX_NONE),
    SX_FIELD("generation","uint32",100,4,SX_NONE),
    SX_FIELD("file_acl_block_low","uint32",104,4,SX_ID),
    SX_FIELD("size_high_or_dir_acl","uint32",108,4,SX_NONE),
    SX_FIELD("obsolete_fragment_block","uint32",112,4,SX_ID),
    SX_FIELD("os_dependent2","uint8[12]",116,12,SX_NONE),
};
static const sx_layout sxuf_ext_other_os_inode = {UINT32_C(0x60110007),"ext_other_os_inode",sxuf_ext_other_os_inode_fields,SX_COUNT(sxuf_ext_other_os_inode_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_2_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxuf_ext_inode_extra_2 = {UINT32_C(0x60110008),"ext_inode_extra_2",sxuf_ext_inode_extra_2_fields,SX_COUNT(sxuf_ext_inode_extra_2_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_4_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
    SX_FIELD("checksum_high","uint16",2,2,SX_CHECKSUM),
};
static const sx_layout sxuf_ext_inode_extra_4 = {UINT32_C(0x60110009),"ext_inode_extra_4",sxuf_ext_inode_extra_4_fields,SX_COUNT(sxuf_ext_inode_extra_4_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_8_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
    SX_FIELD("checksum_high","uint16",2,2,SX_CHECKSUM),
    SX_FIELD("ctime_extra","uint32",4,4,SX_FLAGS),
};
static const sx_layout sxuf_ext_inode_extra_8 = {UINT32_C(0x6011000a),"ext_inode_extra_8",sxuf_ext_inode_extra_8_fields,SX_COUNT(sxuf_ext_inode_extra_8_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_12_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
    SX_FIELD("checksum_high","uint16",2,2,SX_CHECKSUM),
    SX_FIELD("ctime_extra","uint32",4,4,SX_FLAGS),
    SX_FIELD("mtime_extra","uint32",8,4,SX_FLAGS),
};
static const sx_layout sxuf_ext_inode_extra_12 = {UINT32_C(0x6011000b),"ext_inode_extra_12",sxuf_ext_inode_extra_12_fields,SX_COUNT(sxuf_ext_inode_extra_12_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_16_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
    SX_FIELD("checksum_high","uint16",2,2,SX_CHECKSUM),
    SX_FIELD("ctime_extra","uint32",4,4,SX_FLAGS),
    SX_FIELD("mtime_extra","uint32",8,4,SX_FLAGS),
    SX_FIELD("atime_extra","uint32",12,4,SX_FLAGS),
};
static const sx_layout sxuf_ext_inode_extra_16 = {UINT32_C(0x6011000c),"ext_inode_extra_16",sxuf_ext_inode_extra_16_fields,SX_COUNT(sxuf_ext_inode_extra_16_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_20_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
    SX_FIELD("checksum_high","uint16",2,2,SX_CHECKSUM),
    SX_FIELD("ctime_extra","uint32",4,4,SX_FLAGS),
    SX_FIELD("mtime_extra","uint32",8,4,SX_FLAGS),
    SX_FIELD("atime_extra","uint32",12,4,SX_FLAGS),
    SX_FIELD("creation_time_low","int32",16,4,SX_NONE),
};
static const sx_layout sxuf_ext_inode_extra_20 = {UINT32_C(0x6011000d),"ext_inode_extra_20",sxuf_ext_inode_extra_20_fields,SX_COUNT(sxuf_ext_inode_extra_20_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_24_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
    SX_FIELD("checksum_high","uint16",2,2,SX_CHECKSUM),
    SX_FIELD("ctime_extra","uint32",4,4,SX_FLAGS),
    SX_FIELD("mtime_extra","uint32",8,4,SX_FLAGS),
    SX_FIELD("atime_extra","uint32",12,4,SX_FLAGS),
    SX_FIELD("creation_time_low","int32",16,4,SX_NONE),
    SX_FIELD("creation_time_extra","uint32",20,4,SX_FLAGS),
};
static const sx_layout sxuf_ext_inode_extra_24 = {UINT32_C(0x6011000e),"ext_inode_extra_24",sxuf_ext_inode_extra_24_fields,SX_COUNT(sxuf_ext_inode_extra_24_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_28_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
    SX_FIELD("checksum_high","uint16",2,2,SX_CHECKSUM),
    SX_FIELD("ctime_extra","uint32",4,4,SX_FLAGS),
    SX_FIELD("mtime_extra","uint32",8,4,SX_FLAGS),
    SX_FIELD("atime_extra","uint32",12,4,SX_FLAGS),
    SX_FIELD("creation_time_low","int32",16,4,SX_NONE),
    SX_FIELD("creation_time_extra","uint32",20,4,SX_FLAGS),
    SX_FIELD("version_high","uint32",24,4,SX_NONE),
};
static const sx_layout sxuf_ext_inode_extra_28 = {UINT32_C(0x6011000f),"ext_inode_extra_28",sxuf_ext_inode_extra_28_fields,SX_COUNT(sxuf_ext_inode_extra_28_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_32_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
    SX_FIELD("checksum_high","uint16",2,2,SX_CHECKSUM),
    SX_FIELD("ctime_extra","uint32",4,4,SX_FLAGS),
    SX_FIELD("mtime_extra","uint32",8,4,SX_FLAGS),
    SX_FIELD("atime_extra","uint32",12,4,SX_FLAGS),
    SX_FIELD("creation_time_low","int32",16,4,SX_NONE),
    SX_FIELD("creation_time_extra","uint32",20,4,SX_FLAGS),
    SX_FIELD("version_high","uint32",24,4,SX_NONE),
    SX_FIELD("project_id","uint32",28,4,SX_ID),
};
static const sx_layout sxuf_ext_inode_extra_32 = {UINT32_C(0x60110010),"ext_inode_extra_32",sxuf_ext_inode_extra_32_fields,SX_COUNT(sxuf_ext_inode_extra_32_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs1_superblock_le_fields[] = {
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
};
static const sx_layout sxuf_squashfs1_superblock_le = {UINT32_C(0x60110011),"squashfs1_superblock_le",sxuf_squashfs1_superblock_le_fields,SX_COUNT(sxuf_squashfs1_superblock_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs1_superblock_be_fields[] = {
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
};
static const sx_layout sxuf_squashfs1_superblock_be = {UINT32_C(0x60110012),"squashfs1_superblock_be",sxuf_squashfs1_superblock_be_fields,SX_COUNT(sxuf_squashfs1_superblock_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs2_superblock_le_fields[] = {
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
static const sx_layout sxuf_squashfs2_superblock_le = {UINT32_C(0x60110013),"squashfs2_superblock_le",sxuf_squashfs2_superblock_le_fields,SX_COUNT(sxuf_squashfs2_superblock_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs2_superblock_be_fields[] = {
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
static const sx_layout sxuf_squashfs2_superblock_be = {UINT32_C(0x60110014),"squashfs2_superblock_be",sxuf_squashfs2_superblock_be_fields,SX_COUNT(sxuf_squashfs2_superblock_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs3_superblock_le_fields[] = {
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
static const sx_layout sxuf_squashfs3_superblock_le = {UINT32_C(0x60110015),"squashfs3_superblock_le",sxuf_squashfs3_superblock_le_fields,SX_COUNT(sxuf_squashfs3_superblock_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs3_superblock_be_fields[] = {
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
static const sx_layout sxuf_squashfs3_superblock_be = {UINT32_C(0x60110016),"squashfs3_superblock_be",sxuf_squashfs3_superblock_be_fields,SX_COUNT(sxuf_squashfs3_superblock_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs4_superblock_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("inode_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("creation_time","uint32",8,4,SX_TIME),
    SX_FIELD("block_size","uint32",12,4,SX_SIZE),
    SX_FIELD("fragment_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("compression","uint16",20,2,SX_ID),
    SX_FIELD("block_log","uint16",22,2,SX_NONE),
    SX_FIELD("flags","uint16",24,2,SX_FLAGS),
    SX_FIELD("id_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("major","uint16",28,2,SX_NONE),
    SX_FIELD("minor","uint16",30,2,SX_NONE),
    SX_FIELD("root_inode_reference","uint64",32,8,SX_FLAGS),
    SX_FIELD("bytes_used","uint64",40,8,SX_SIZE),
    SX_FIELD("id_index_offset","uint64",48,8,SX_OFFSET),
    SX_FIELD("xattr_index_offset","uint64",56,8,SX_OFFSET),
    SX_FIELD("inode_table_offset","uint64",64,8,SX_OFFSET),
    SX_FIELD("directory_table_offset","uint64",72,8,SX_OFFSET),
    SX_FIELD("fragment_index_offset","uint64",80,8,SX_OFFSET),
    SX_FIELD("lookup_index_offset","uint64",88,8,SX_OFFSET),
};
static const sx_layout sxuf_squashfs4_superblock_le = {UINT32_C(0x60110017),"squashfs4_superblock_le",sxuf_squashfs4_superblock_le_fields,SX_COUNT(sxuf_squashfs4_superblock_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs4_superblock_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("inode_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("creation_time","uint32",8,4,SX_TIME),
    SX_FIELD("block_size","uint32",12,4,SX_SIZE),
    SX_FIELD("fragment_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("compression","uint16",20,2,SX_ID),
    SX_FIELD("block_log","uint16",22,2,SX_NONE),
    SX_FIELD("flags","uint16",24,2,SX_FLAGS),
    SX_FIELD("id_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("major","uint16",28,2,SX_NONE),
    SX_FIELD("minor","uint16",30,2,SX_NONE),
    SX_FIELD("root_inode_reference","uint64",32,8,SX_FLAGS),
    SX_FIELD("bytes_used","uint64",40,8,SX_SIZE),
    SX_FIELD("id_index_offset","uint64",48,8,SX_OFFSET),
    SX_FIELD("xattr_index_offset","uint64",56,8,SX_OFFSET),
    SX_FIELD("inode_table_offset","uint64",64,8,SX_OFFSET),
    SX_FIELD("directory_table_offset","uint64",72,8,SX_OFFSET),
    SX_FIELD("fragment_index_offset","uint64",80,8,SX_OFFSET),
    SX_FIELD("lookup_index_offset","uint64",88,8,SX_OFFSET),
};
static const sx_layout sxuf_squashfs4_superblock_be = {UINT32_C(0x60110018),"squashfs4_superblock_be",sxuf_squashfs4_superblock_be_fields,SX_COUNT(sxuf_squashfs4_superblock_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs_metadata_header_le_fields[] = {
    SX_FIELD("size_and_stored_flag","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxuf_squashfs_metadata_header_le = {UINT32_C(0x60110019),"squashfs_metadata_header_le",sxuf_squashfs_metadata_header_le_fields,SX_COUNT(sxuf_squashfs_metadata_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs_table_index_le_fields[] = {
    SX_FIELD("metadata_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxuf_squashfs_table_index_le = {UINT32_C(0x6011001a),"squashfs_table_index_le",sxuf_squashfs_table_index_le_fields,SX_COUNT(sxuf_squashfs_table_index_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs2_fragment_index_le_fields[] = {
    SX_FIELD("metadata_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxuf_squashfs2_fragment_index_le = {UINT32_C(0x6011001b),"squashfs2_fragment_index_le",sxuf_squashfs2_fragment_index_le_fields,SX_COUNT(sxuf_squashfs2_fragment_index_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs_identity_le_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_ID),
};
static const sx_layout sxuf_squashfs_identity_le = {UINT32_C(0x6011001c),"squashfs_identity_le",sxuf_squashfs_identity_le_fields,SX_COUNT(sxuf_squashfs_identity_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs_xattr_table_le_fields[] = {
    SX_FIELD("xattr_table_offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("xattr_id_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxuf_squashfs_xattr_table_le = {UINT32_C(0x6011001d),"squashfs_xattr_table_le",sxuf_squashfs_xattr_table_le_fields,SX_COUNT(sxuf_squashfs_xattr_table_le_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_squashfs_metadata_header_be_fields[] = {
    SX_FIELD("size_and_stored_flag","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxuf_squashfs_metadata_header_be = {UINT32_C(0x6011001e),"squashfs_metadata_header_be",sxuf_squashfs_metadata_header_be_fields,SX_COUNT(sxuf_squashfs_metadata_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs_table_index_be_fields[] = {
    SX_FIELD("metadata_offset","uint64",0,8,SX_OFFSET),
};
static const sx_layout sxuf_squashfs_table_index_be = {UINT32_C(0x6011001f),"squashfs_table_index_be",sxuf_squashfs_table_index_be_fields,SX_COUNT(sxuf_squashfs_table_index_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs2_fragment_index_be_fields[] = {
    SX_FIELD("metadata_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxuf_squashfs2_fragment_index_be = {UINT32_C(0x60110020),"squashfs2_fragment_index_be",sxuf_squashfs2_fragment_index_be_fields,SX_COUNT(sxuf_squashfs2_fragment_index_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs_identity_be_fields[] = {
    SX_FIELD("id","uint32",0,4,SX_ID),
};
static const sx_layout sxuf_squashfs_identity_be = {UINT32_C(0x60110021),"squashfs_identity_be",sxuf_squashfs_identity_be_fields,SX_COUNT(sxuf_squashfs_identity_be_fields),SX_BE};
static const xx_data_struct_field_desc sxuf_squashfs_xattr_table_be_fields[] = {
    SX_FIELD("xattr_table_offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("xattr_id_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxuf_squashfs_xattr_table_be = {UINT32_C(0x60110022),"squashfs_xattr_table_be",sxuf_squashfs_xattr_table_be_fields,SX_COUNT(sxuf_squashfs_xattr_table_be_fields),SX_BE};
static const sx_layout *const sx_unixfs_layouts[] = {
    &sxuf_ext_dynamic_superblock,
    &sxuf_ext_original_superblock,
    &sxuf_ext_group_descriptor_64,
    &sxuf_ext_group_descriptor_32,
    &sxuf_ext_original_group_descriptor,
    &sxuf_ext_linux_inode,
    &sxuf_ext_other_os_inode,
    &sxuf_ext_inode_extra_2,
    &sxuf_ext_inode_extra_4,
    &sxuf_ext_inode_extra_8,
    &sxuf_ext_inode_extra_12,
    &sxuf_ext_inode_extra_16,
    &sxuf_ext_inode_extra_20,
    &sxuf_ext_inode_extra_24,
    &sxuf_ext_inode_extra_28,
    &sxuf_ext_inode_extra_32,
    &sxuf_squashfs1_superblock_le,
    &sxuf_squashfs1_superblock_be,
    &sxuf_squashfs2_superblock_le,
    &sxuf_squashfs2_superblock_be,
    &sxuf_squashfs3_superblock_le,
    &sxuf_squashfs3_superblock_be,
    &sxuf_squashfs4_superblock_le,
    &sxuf_squashfs4_superblock_be,
    &sxuf_squashfs_metadata_header_le,
    &sxuf_squashfs_table_index_le,
    &sxuf_squashfs2_fragment_index_le,
    &sxuf_squashfs_identity_le,
    &sxuf_squashfs_xattr_table_le,
    &sxuf_squashfs_metadata_header_be,
    &sxuf_squashfs_table_index_be,
    &sxuf_squashfs2_fragment_index_be,
    &sxuf_squashfs_identity_be,
    &sxuf_squashfs_xattr_table_be,
};
static bool sx_unixfs_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<UINT32_C(0x60110000)||id>=UINT32_C(0x60120000))return true;
    const wchar_t *comment=NULL;switch(id){
    case UINT32_C(0x60110001):
        if(!xx_rt_wcscmp(r->name,L"blocks_count_lo"))comment=L"Physical low/high 32-bit part of a block count; combine the paired words when the 64BIT feature is enabled.";
        if(!xx_rt_wcscmp(r->name,L"r_blocks_count_lo"))comment=L"Physical low/high 32-bit part of a block count; combine the paired words when the 64BIT feature is enabled.";
        if(!xx_rt_wcscmp(r->name,L"free_blocks_count_lo"))comment=L"Physical low/high 32-bit part of a block count; combine the paired words when the 64BIT feature is enabled.";
        if(!xx_rt_wcscmp(r->name,L"first_data_block"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"log_block_size"))comment=L"Block size in bytes is 1024 shifted left by this exponent.";
        if(!xx_rt_wcscmp(r->name,L"log_cluster_or_fragment_size"))comment=L"Signed exponent relative to 1024 bytes: allocation clusters with BIGALLOC, legacy fragments otherwise; not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"clusters_or_fragments_per_group"))comment=L"Allocation clusters per group with BIGALLOC, legacy fragments otherwise.";
        if(!xx_rt_wcscmp(r->name,L"mtime"))comment=L"Low 32 bits of Unix seconds; combine with the corresponding high 8-bit field.";
        if(!xx_rt_wcscmp(r->name,L"wtime"))comment=L"Low 32 bits of Unix seconds; combine with the corresponding high 8-bit field.";
        if(!xx_rt_wcscmp(r->name,L"max_mnt_count"))comment=L"Signed mount-count limit; -1 disables mount-count checks.";
        if(!xx_rt_wcscmp(r->name,L"lastcheck"))comment=L"Low 32 bits of Unix seconds; combine with the corresponding high 8-bit field.";
        if(!xx_rt_wcscmp(r->name,L"checkinterval"))comment=L"Duration in seconds, not a timestamp.";
        if(!xx_rt_wcscmp(r->name,L"mkfs_time"))comment=L"Low 32 bits of Unix seconds; combine with the corresponding high 8-bit field.";
        if(!xx_rt_wcscmp(r->name,L"blocks_count_hi"))comment=L"Physical low/high 32-bit part of a block count; combine the paired words when the 64BIT feature is enabled.";
        if(!xx_rt_wcscmp(r->name,L"r_blocks_count_hi"))comment=L"Physical low/high 32-bit part of a block count; combine the paired words when the 64BIT feature is enabled.";
        if(!xx_rt_wcscmp(r->name,L"free_blocks_count_hi"))comment=L"Physical low/high 32-bit part of a block count; combine the paired words when the 64BIT feature is enabled.";
        if(!xx_rt_wcscmp(r->name,L"raid_stride"))comment=L"Filesystem block units, not bytes.";
        if(!xx_rt_wcscmp(r->name,L"mmp_update_interval"))comment=L"Duration in seconds, not a timestamp.";
        if(!xx_rt_wcscmp(r->name,L"mmp_block"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"raid_stripe_width"))comment=L"Filesystem block units, not bytes.";
        if(!xx_rt_wcscmp(r->name,L"log_groups_per_flex"))comment=L"Encoded logarithm/shift; not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"kbytes_written"))comment=L"Lifetime written quantity in KiB, not bytes.";
        if(!xx_rt_wcscmp(r->name,L"first_error_time"))comment=L"Low 32 bits of Unix seconds; combine with the corresponding high 8-bit field.";
        if(!xx_rt_wcscmp(r->name,L"first_error_block"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"last_error_time"))comment=L"Low 32 bits of Unix seconds; combine with the corresponding high 8-bit field.";
        if(!xx_rt_wcscmp(r->name,L"last_error_block"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"wtime_hi"))comment=L"High 8 bits of a 40-bit Unix timestamp; this byte is not a complete timestamp.";
        if(!xx_rt_wcscmp(r->name,L"mtime_hi"))comment=L"High 8 bits of a 40-bit Unix timestamp; this byte is not a complete timestamp.";
        if(!xx_rt_wcscmp(r->name,L"mkfs_time_hi"))comment=L"High 8 bits of a 40-bit Unix timestamp; this byte is not a complete timestamp.";
        if(!xx_rt_wcscmp(r->name,L"lastcheck_hi"))comment=L"High 8 bits of a 40-bit Unix timestamp; this byte is not a complete timestamp.";
        if(!xx_rt_wcscmp(r->name,L"first_error_time_hi"))comment=L"High 8 bits of a 40-bit Unix timestamp; this byte is not a complete timestamp.";
        if(!xx_rt_wcscmp(r->name,L"last_error_time_hi"))comment=L"High 8 bits of a 40-bit Unix timestamp; this byte is not a complete timestamp.";
        break;
    case UINT32_C(0x60110002):
        if(!xx_rt_wcscmp(r->name,L"first_data_block"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"log_block_size"))comment=L"Block size in bytes is 1024 shifted left by this exponent.";
        if(!xx_rt_wcscmp(r->name,L"log_fragment_size"))comment=L"Signed fragment-size exponent relative to 1024 bytes; not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"fragments_per_group"))comment=L"Fragments per block group.";
        if(!xx_rt_wcscmp(r->name,L"mtime"))comment=L"Unix timestamp in seconds.";
        if(!xx_rt_wcscmp(r->name,L"wtime"))comment=L"Unix timestamp in seconds.";
        if(!xx_rt_wcscmp(r->name,L"max_mnt_count"))comment=L"Signed mount-count limit; -1 disables mount-count checks.";
        if(!xx_rt_wcscmp(r->name,L"lastcheck"))comment=L"Unix timestamp in seconds.";
        if(!xx_rt_wcscmp(r->name,L"checkinterval"))comment=L"Duration in seconds, not a timestamp.";
        break;
    case UINT32_C(0x60110003):
        if(!xx_rt_wcscmp(r->name,L"block_bitmap_lo"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_bitmap_lo"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_table_lo"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"free_blocks_count_lo"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"free_inodes_count_lo"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"used_dirs_count_lo"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"flags"))comment=L"EXT 4 group descriptor flags; this word is padding in older EXT 2 layouts.";
        if(!xx_rt_wcscmp(r->name,L"exclude_bitmap_lo"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"block_bitmap_csum_lo"))comment=L"Physical checksum part when METADATA_CSUM is enabled; reserved in older layouts.";
        if(!xx_rt_wcscmp(r->name,L"inode_bitmap_csum_lo"))comment=L"Physical checksum part when METADATA_CSUM is enabled; reserved in older layouts.";
        if(!xx_rt_wcscmp(r->name,L"itable_unused_lo"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"checksum"))comment=L"Group descriptor checksum when GDT_CSUM or METADATA_CSUM is enabled; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"block_bitmap_hi"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_bitmap_hi"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_table_hi"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"free_blocks_count_hi"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"free_inodes_count_hi"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"used_dirs_count_hi"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"itable_unused_hi"))comment=L"Low/high 16-bit half of a count; combine the paired halves.";
        if(!xx_rt_wcscmp(r->name,L"exclude_bitmap_hi"))comment=L"Low/high 32-bit half of a filesystem block number, not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"block_bitmap_csum_hi"))comment=L"Physical checksum part when METADATA_CSUM is enabled; reserved in older layouts.";
        if(!xx_rt_wcscmp(r->name,L"inode_bitmap_csum_hi"))comment=L"Physical checksum part when METADATA_CSUM is enabled; reserved in older layouts.";
        break;
    case UINT32_C(0x60110004):
        if(!xx_rt_wcscmp(r->name,L"block_bitmap"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_bitmap"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_table"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"flags"))comment=L"EXT 4 group descriptor flags; this word is padding in older EXT 2 layouts.";
        if(!xx_rt_wcscmp(r->name,L"exclude_bitmap"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"block_bitmap_csum"))comment=L"Physical checksum part when METADATA_CSUM is enabled; reserved in older layouts.";
        if(!xx_rt_wcscmp(r->name,L"inode_bitmap_csum"))comment=L"Physical checksum part when METADATA_CSUM is enabled; reserved in older layouts.";
        if(!xx_rt_wcscmp(r->name,L"checksum"))comment=L"Group descriptor checksum when GDT_CSUM or METADATA_CSUM is enabled; reserved otherwise.";
        break;
    case UINT32_C(0x60110005):
        if(!xx_rt_wcscmp(r->name,L"block_bitmap"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_bitmap"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"inode_table"))comment=L"Filesystem block number; multiply by block size for a byte offset.";
        break;
    case UINT32_C(0x60110006):
        if(!xx_rt_wcscmp(r->name,L"size_low"))comment=L"Low 32 bits of file size in bytes; combine size_high for regular files.";
        if(!xx_rt_wcscmp(r->name,L"atime_low"))comment=L"Signed low 32-bit Unix seconds; extended inode epoch bits may extend this value.";
        if(!xx_rt_wcscmp(r->name,L"ctime_low"))comment=L"Signed low 32-bit Unix seconds; extended inode epoch bits may extend this value.";
        if(!xx_rt_wcscmp(r->name,L"mtime_low"))comment=L"Signed low 32-bit Unix seconds; extended inode epoch bits may extend this value.";
        if(!xx_rt_wcscmp(r->name,L"deletion_time_or_next_orphan"))comment=L"Unix deletion time for a deleted inode; next orphan inode number while linked in the legacy orphan chain.";
        if(!xx_rt_wcscmp(r->name,L"blocks_low"))comment=L"Low 32 bits of allocated block count; units are 512-byte sectors unless HUGE_FILE flags select filesystem blocks.";
        if(!xx_rt_wcscmp(r->name,L"version_low_or_reserved"))comment=L"Low 32-bit inode version in EXT 4; reserved OS-dependent word in legacy Linux EXT 2/3.";
        if(!xx_rt_wcscmp(r->name,L"block_map_or_inline_data"))comment=L"Union of block-number map, extent-tree root, inline data or fast symlink bytes; interpretation depends on mode/features/flags.";
        if(!xx_rt_wcscmp(r->name,L"file_acl_block_low"))comment=L"Low 32 bits of the extended-attribute block number.";
        if(!xx_rt_wcscmp(r->name,L"size_high_or_dir_acl"))comment=L"High file-size word for regular files; legacy directory ACL field for other inode kinds.";
        if(!xx_rt_wcscmp(r->name,L"blocks_high_or_fragment_bytes"))comment=L"High 16-bit block count with HUGE_FILE; legacy EXT 2 Linux fragment number and size bytes otherwise.";
        if(!xx_rt_wcscmp(r->name,L"file_acl_block_high_or_reserved"))comment=L"High 16-bit extended-attribute block number with 64BIT; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"uid_high"))comment=L"High 16 bits of the Linux owner UID.";
        if(!xx_rt_wcscmp(r->name,L"gid_high"))comment=L"High 16 bits of the Linux group ID.";
        if(!xx_rt_wcscmp(r->name,L"checksum_low_or_reserved"))comment=L"Low 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        break;
    case UINT32_C(0x60110007):
        if(!xx_rt_wcscmp(r->name,L"size_low"))comment=L"Low 32 bits of file size in bytes; combine size_high for regular files.";
        if(!xx_rt_wcscmp(r->name,L"atime_low"))comment=L"Signed low 32-bit Unix seconds; extended inode epoch bits may extend this value.";
        if(!xx_rt_wcscmp(r->name,L"ctime_low"))comment=L"Signed low 32-bit Unix seconds; extended inode epoch bits may extend this value.";
        if(!xx_rt_wcscmp(r->name,L"mtime_low"))comment=L"Signed low 32-bit Unix seconds; extended inode epoch bits may extend this value.";
        if(!xx_rt_wcscmp(r->name,L"deletion_time_or_next_orphan"))comment=L"Unix deletion time for a deleted inode; next orphan inode number while linked in the legacy orphan chain.";
        if(!xx_rt_wcscmp(r->name,L"blocks_low"))comment=L"Low 32 bits of allocated block count; units are 512-byte sectors unless HUGE_FILE flags select filesystem blocks.";
        if(!xx_rt_wcscmp(r->name,L"block_map_or_inline_data"))comment=L"Union of block-number map, extent-tree root, inline data or fast symlink bytes; interpretation depends on mode/features/flags.";
        if(!xx_rt_wcscmp(r->name,L"file_acl_block_low"))comment=L"Low 32 bits of the extended-attribute block number.";
        if(!xx_rt_wcscmp(r->name,L"size_high_or_dir_acl"))comment=L"High file-size word for regular files; legacy directory ACL field for other inode kinds.";
        break;
    case UINT32_C(0x60110009):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        break;
    case UINT32_C(0x6011000a):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"ctime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        break;
    case UINT32_C(0x6011000b):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"ctime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"mtime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        break;
    case UINT32_C(0x6011000c):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"ctime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"mtime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"atime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        break;
    case UINT32_C(0x6011000d):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"ctime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"mtime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"atime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"creation_time_low"))comment=L"Signed low 32-bit Unix seconds; combine epoch bits from creation_time_extra.";
        break;
    case UINT32_C(0x6011000e):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"ctime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"mtime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"atime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"creation_time_low"))comment=L"Signed low 32-bit Unix seconds; combine epoch bits from creation_time_extra.";
        if(!xx_rt_wcscmp(r->name,L"creation_time_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        break;
    case UINT32_C(0x6011000f):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"ctime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"mtime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"atime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"creation_time_low"))comment=L"Signed low 32-bit Unix seconds; combine epoch bits from creation_time_extra.";
        if(!xx_rt_wcscmp(r->name,L"creation_time_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        break;
    case UINT32_C(0x60110010):
        if(!xx_rt_wcscmp(r->name,L"checksum_high"))comment=L"High 16 bits of inode checksum with METADATA_CSUM; reserved otherwise.";
        if(!xx_rt_wcscmp(r->name,L"ctime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"mtime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"atime_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        if(!xx_rt_wcscmp(r->name,L"creation_time_low"))comment=L"Signed low 32-bit Unix seconds; combine epoch bits from creation_time_extra.";
        if(!xx_rt_wcscmp(r->name,L"creation_time_extra"))comment=L"Bits 0..1 extend the signed seconds field; bits 2..31 encode nanoseconds.";
        break;
    case UINT32_C(0x60110011):
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110012):
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110013):
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110014):
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110015):
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110016):
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110017):
        if(!xx_rt_wcscmp(r->name,L"compression"))comment=L"1=ZLIB,2=LZMA,3=LZO,4=XZ,5=LZ 4,6=ZSTD.";
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110018):
        if(!xx_rt_wcscmp(r->name,L"compression"))comment=L"1=ZLIB,2=LZMA,3=LZO,4=XZ,5=LZ 4,6=ZSTD.";
        if(!xx_rt_wcscmp(r->name,L"block_log"))comment=L"Base 2 block-size exponent, not a byte count.";
        if(!xx_rt_wcscmp(r->name,L"root_inode_reference"))comment=L"High 48 bits: byte offset of metadata block within inode table; low 16 bits: decoded offset within that block.";
        break;
    case UINT32_C(0x60110019):
        if(!xx_rt_wcscmp(r->name,L"size_and_stored_flag"))comment=L"Low 15 bits: encoded payload byte length; bit 15: uncompressed payload. Not a plain size field.";
        break;
    case UINT32_C(0x6011001a):
        if(!xx_rt_wcscmp(r->name,L"metadata_offset"))comment=L"Absolute byte offset of a metadata block from the filesystem image start.";
        break;
    case UINT32_C(0x6011001e):
        if(!xx_rt_wcscmp(r->name,L"size_and_stored_flag"))comment=L"Low 15 bits: encoded payload byte length; bit 15: uncompressed payload. Not a plain size field.";
        break;
    case UINT32_C(0x6011001f):
        if(!xx_rt_wcscmp(r->name,L"metadata_offset"))comment=L"Absolute byte offset of a metadata block from the filesystem image start.";
        break;
    default:break;}
    return !comment||xx_data_struct_record_set_comment(r,comment);
}

/* Physical metadata only. No filesystem mount, decompression, journal replay,
 * reader factory or synthesized decoded-offset mapping is used. */
#define UF_PAIR(n,be) ((be)?&sxuf_##n##_be:&sxuf_##n##_le)
static bool sxuf_span(sx_context *c,uint64_t at,uint64_t n){return c->size>=0&&at<=(uint64_t)c->size&&n<=(uint64_t)c->size-at;}
static bool sxuf_read(sx_context *c,uint64_t at,void *b,size_t n){return sxuf_span(c,at,n)&&sx_read(c,(int64_t)at,b,n);}
static uint16_t sxuf_16(const uint8_t *p,bool be){return xx_data_get_u16(p,2,0,be);}
static uint32_t sxuf_32(const uint8_t *p,bool be){return xx_data_get_u32(p,4,0,be);}
static uint64_t sxuf_64(const uint8_t *p,bool be){return xx_data_get_u64(p,8,0,be);}
static bool sxuf_power(uint32_t x){return x&&!(x&(x-1));}
static bool sxuf_power_of(uint32_t x,uint32_t b){if(!x)return false;while(x%b==0)x/=b;return x==1;}
typedef struct sxuf_range {uint64_t at,end;} sxuf_range;
/* Claim whole optional tables before exposing any of their fields. Invalid or
 * overlapping optional metadata is left raw; a readable superblock survives. */
static bool sxuf_claim(sx_context *c,sxuf_range *ranges,size_t *n,uint64_t at,uint64_t size)
{
    if(!size||*n>=8192||!sxuf_span(c,at,size))return false;
    for(size_t i=0;i<*n;i++)if(at<ranges[i].end&&ranges[i].at<at+size)return false;
    ranges[*n].at=at;ranges[*n].end=at+size;(*n)++;return true;
}
static bool sxuf_ext(sx_context *c)
{
    uint8_t h[1024],d[64],inode[160];uint32_t revision,bs,shift,first,bpg,ipg,ninodes,isize,ds,incompat=0,compat=0,ro=0,groups,os;uint64_t blocks;
    if(!sxuf_read(c,1024,h,sizeof(h))||sxuf_16(h+56,false)!=0xef53)return false;
    revision=sxuf_32(h+76,false);if(revision>1)return false;
    if(!sx_add(c,revision?&sxuf_ext_dynamic_superblock:&sxuf_ext_original_superblock,1024,revision?1024:84))return false;
    shift=sxuf_32(h+24,false);if(shift>6)return true;bs=1024U<<shift;first=sxuf_32(h+20,false);blocks=sxuf_32(h+4,false);bpg=sxuf_32(h+32,false);ipg=sxuf_32(h+40,false);ninodes=sxuf_32(h,false);os=sxuf_32(h+72,false);
    isize=revision?sxuf_16(h+88,false):128;ds=32;
    if(revision){compat=sxuf_32(h+92,false);incompat=sxuf_32(h+96,false);ro=sxuf_32(h+100,false);if(incompat&128){blocks|=(uint64_t)sxuf_32(h+336,false)<<32;ds=sxuf_16(h+254,false);}}
    if(first!=(bs==1024?1U:0U)||!bpg||bpg>bs*8U||!ipg||ipg>bs*8U||!ninodes||blocks<=first||blocks>(uint64_t)c->size/bs||!sxuf_power(isize)||isize<128||isize>bs||!sxuf_power(ds)||ds<32||ds>bs||((incompat&128)&&ds<64))return true;
    uint64_t ng=(blocks-first+bpg-1)/bpg;if(!ng||ng>1048576||(uint64_t)ipg*ng<ninodes)return true;groups=(uint32_t)ng;
    sxuf_range *ranges=xx_mem_alloc(8192*sizeof(*ranges));if(!ranges)return false;size_t nr=0;bool ok=sxuf_claim(c,ranges,&nr,1024,1024);uint32_t budget=4096,dpb=bs/ds;
    for(uint32_t g=0;ok&&g<groups&&g<4096;g++){
        uint32_t gi=g/dpb;uint64_t block=(uint64_t)first+1+gi;
        if((incompat&16)&&gi>=sxuf_32(h+260,false)){
            uint32_t fg=gi*dpb;bool has=fg==0;
            if(!has){if(compat&512)has=fg==sxuf_32(h+588,false)||fg==sxuf_32(h+592,false);else has=fg==1||!(ro&1)||((fg&1)&&(sxuf_power_of(fg,3)||sxuf_power_of(fg,5)||sxuf_power_of(fg,7)));}
            block=(uint64_t)first+(uint64_t)fg*bpg+(has?1:0);
        }
        if(block>=blocks)continue;uint64_t at=block*bs+(uint64_t)(g%dpb)*ds;
        if(!sxuf_claim(c,ranges,&nr,at,ds)||!sxuf_read(c,at,d,ds<64?32:64))continue;
        if(!sx_add(c,!revision?&sxuf_ext_original_group_descriptor:ds>=64?&sxuf_ext_group_descriptor_64:&sxuf_ext_group_descriptor_32,(int64_t)at,ds>=64?64:32)){ok=false;break;}
        uint64_t table=sxuf_32(d+8,false);if(ds>=64)table|=(uint64_t)sxuf_32(d+40,false)<<32;
        uint64_t base_inode=(uint64_t)g*ipg,count=base_inode<ninodes?ninodes-base_inode:0;if(count>ipg)count=ipg;if(count>budget)count=budget;
        if(!count||!table||table>=blocks||!sxuf_claim(c,ranges,&nr,table*bs,count*isize))continue;budget-=(uint32_t)count;
        for(uint64_t i=0;ok&&i<count;i++){
            uint64_t pos=table*bs+i*isize;
            if(!sxuf_read(c,pos,inode,isize>=160?160:isize)){ok=false;break;}
            ok=sx_add(c,os==0?&sxuf_ext_linux_inode:&sxuf_ext_other_os_inode,(int64_t)pos,128);
            if(ok&&os==0&&isize>128){uint16_t extra=sxuf_16(inode+128,false);unsigned width=2;if(extra>=4&&extra<=isize-128)width=extra<32?extra&~3U:32;
                const sx_layout *l=&sxuf_ext_inode_extra_2;
                switch(width){case 4:l=&sxuf_ext_inode_extra_4;break;case 8:l=&sxuf_ext_inode_extra_8;break;case 12:l=&sxuf_ext_inode_extra_12;break;case 16:l=&sxuf_ext_inode_extra_16;break;case 20:l=&sxuf_ext_inode_extra_20;break;case 24:l=&sxuf_ext_inode_extra_24;break;case 28:l=&sxuf_ext_inode_extra_28;break;case 32:l=&sxuf_ext_inode_extra_32;break;default:width=2;break;}
                ok=sx_add(c,l,(int64_t)pos+128,width);
            }
        }
    }xx_mem_free(ranges);return ok;
}
/* Metadata payload may be compressed. Only its physical2-byte header is
 * structured; decoded inode/directory bytes never acquire fake file offsets. */
static bool sxuf_meta(sx_context *c,uint64_t at,uint64_t limit,bool be,unsigned *budget)
{
    while(*budget&&at<limit){uint8_t b[2];if(limit-at<2||!sxuf_read(c,at,b,2))break;uint16_t v=sxuf_16(b,be);uint32_t n=v&32767;if(!n||n>8192||n>limit-at-2)break;
        bool duplicate=false,overlap=false;for(size_t i=0;i<c->count;i++){uint64_t p=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p==at&&z==2&&c->items[i].id==UF_PAIR(squashfs_metadata_header,be)->id){duplicate=true;break;}if(at<p+z&&p<at+2+n){overlap=true;break;}}
        if(overlap)break;if(!duplicate&&(!sx_add(c,UF_PAIR(squashfs_metadata_header,be),(int64_t)at,2)||!sx_raw(c,(int64_t)at+2,n)))return false;(*budget)--;at+=2+n;
    }return true;
}
static bool sxuf_sq_index(sx_context *c,uint64_t at,uint64_t count,unsigned width,unsigned header,bool be,unsigned *budget)
{
    if(!count||count>4096||at==UINT64_MAX||!sxuf_span(c,at,count*width))return true;
    for(size_t i=0;i<c->count;i++){uint64_t p=(uint64_t)(c->items[i].offset-c->f->base_address);if(at<p+(uint64_t)c->items[i].total_size&&p<at+count*width)return true;}
    if(!sx_table(c,width==4?UF_PAIR(squashfs2_fragment_index,be):UF_PAIR(squashfs_table_index,be),(int64_t)at,width,count))return false;
    for(uint64_t i=0;i<count&&*budget;i++){uint8_t b[8];if(!sxuf_read(c,at+i*width,b,width))return false;uint64_t p=width==4?sxuf_32(b,be):sxuf_64(b,be);if(p>=header&&p<at&&!sxuf_meta(c,p,at,be,budget))return false;}return true;
}
static bool sxuf_squash(sx_context *c)
{
    uint8_t h[128];if(!sxuf_read(c,0,h,sizeof(h)))return false;uint32_t m=sxuf_32(h,false);bool be=m==0x68737173||m==0x68737174;
    if(!be&&m!=0x73717368&&m!=0x74717368&&m!=0x71736873&&m!=0x68191122)return false;
    unsigned v=sxuf_16(h+28,be);const sx_layout *l;uint64_t size,inodes,dirs,frag,lookup,uid,gid;uint32_t fragments,ninode,nu,ng;unsigned header;
    if(v==1){l=UF_PAIR(squashfs1_superblock,be);header=51;}else if(v==2){l=UF_PAIR(squashfs2_superblock,be);header=63;}else if(v==3){l=UF_PAIR(squashfs3_superblock,be);header=119;}else if(v==4){l=UF_PAIR(squashfs4_superblock,be);header=96;}else return false;
    if(!sx_add(c,l,0,header))return false;ninode=sxuf_32(h+4,be);lookup=UINT64_MAX;gid=UINT64_MAX;ng=0;
    if(v==4){size=sxuf_64(h+40,be);inodes=sxuf_64(h+64,be);dirs=sxuf_64(h+72,be);frag=sxuf_64(h+80,be);lookup=sxuf_64(h+88,be);uid=sxuf_64(h+48,be);nu=sxuf_16(h+26,be);fragments=sxuf_32(h+16,be);}
    else if(v==3){size=sxuf_64(h+63,be);inodes=sxuf_64(h+87,be);dirs=sxuf_64(h+95,be);frag=sxuf_64(h+103,be);lookup=sxuf_64(h+111,be);uid=sxuf_64(h+71,be);gid=sxuf_64(h+79,be);nu=h[37];ng=h[38];fragments=sxuf_32(h+55,be);}
    else {size=sxuf_32(h+8,be);inodes=sxuf_32(h+20,be);dirs=sxuf_32(h+24,be);frag=v==2?sxuf_32(h+59,be):UINT64_MAX;uid=sxuf_32(h+12,be);gid=sxuf_32(h+16,be);nu=h[37];ng=h[38];fragments=v==2?sxuf_32(h+55,be):0;}
    if(size<header||size>(uint64_t)c->size)size=(uint64_t)c->size;unsigned budget=4096;
    /* Indexed metadata and plain identity tables are processed first so a
     * linear metadata scan cannot mistake their bytes for framing. */
    if(!sxuf_sq_index(c,frag,((uint64_t)fragments*(v==2?8:16)+8191)/8192,v==2?4:8,header,be,&budget))return false;
    if(v>=3&&!sxuf_sq_index(c,lookup,((uint64_t)ninode*8+8191)/8192,8,header,be,&budget))return false;
    if(v==4){if(!sxuf_sq_index(c,uid,((uint64_t)nu*4+8191)/8192,8,header,be,&budget))return false;uint64_t x=sxuf_64(h+56,be);if(x>=header&&sxuf_span(c,x,16)){
        bool overlap=false;for(size_t i=0;i<c->count;i++){uint64_t p=(uint64_t)(c->items[i].offset-c->f->base_address);if(x<p+(uint64_t)c->items[i].total_size&&p<x+16)overlap=true;}
        if(!overlap&&!sx_add(c,UF_PAIR(squashfs_xattr_table,be),(int64_t)x,16))return false;
    }}else{
        uint64_t starts[2]={uid,gid};uint32_t counts[2]={nu,ng};for(unsigned k=0;k<2;k++)if(counts[k]&&starts[k]>=header&&sxuf_span(c,starts[k],(uint64_t)counts[k]*4)){
            bool overlap=false;for(size_t i=0;i<c->count;i++){uint64_t p=(uint64_t)(c->items[i].offset-c->f->base_address);if(starts[k]<p+(uint64_t)c->items[i].total_size&&p<starts[k]+(uint64_t)counts[k]*4)overlap=true;}
            if(!overlap&&!sx_table(c,UF_PAIR(squashfs_identity,be),(int64_t)starts[k],4,counts[k]))return false;
        }
    }
    if(inodes>=header&&inodes<dirs&&dirs<=size&&!sxuf_meta(c,inodes,dirs,be,&budget))return false;
    if(dirs>=header&&dirs<size){uint64_t limit=size,refs[4]={frag,lookup,uid,gid};for(unsigned i=0;i<4;i++)if(refs[i]>dirs&&refs[i]<limit)limit=refs[i];if(!sxuf_meta(c,dirs,limit,be,&budget))return false;}
    return true;
}
static int sxuf_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxuf_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxuf_order);
    for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+c->items[i].total_size;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxuf_order);return !c->failed;
}
static bool sx_unixfs_supports(xx_file_type_t t){return t==XX_FILE_TYPE_EXT||t==XX_FILE_TYPE_SQUASHFS;}
static bool sx_unixfs_build(sx_context *c){return (c->f->file_type==XX_FILE_TYPE_EXT?sxuf_ext(c):c->f->file_type==XX_FILE_TYPE_SQUASHFS?sxuf_squash(c):false)&&sxuf_finish(c);}
#undef UF_PAIR
