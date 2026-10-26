/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ext2/3/4 data structures, moved out of the unixfs schema family. */
#include "../../xx_format_schema_unixfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

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
const sx_layout sxuf_ext_dynamic_superblock = {UINT32_C(0x60110001),"ext_dynamic_superblock",sxuf_ext_dynamic_superblock_fields,SX_COUNT(sxuf_ext_dynamic_superblock_fields),SX_LE};
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
const sx_layout sxuf_ext_original_superblock = {UINT32_C(0x60110002),"ext_original_superblock",sxuf_ext_original_superblock_fields,SX_COUNT(sxuf_ext_original_superblock_fields),SX_LE};
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
const sx_layout sxuf_ext_group_descriptor_64 = {UINT32_C(0x60110003),"ext_group_descriptor_64",sxuf_ext_group_descriptor_64_fields,SX_COUNT(sxuf_ext_group_descriptor_64_fields),SX_LE};
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
const sx_layout sxuf_ext_group_descriptor_32 = {UINT32_C(0x60110004),"ext_group_descriptor_32",sxuf_ext_group_descriptor_32_fields,SX_COUNT(sxuf_ext_group_descriptor_32_fields),SX_LE};
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
const sx_layout sxuf_ext_original_group_descriptor = {UINT32_C(0x60110005),"ext_original_group_descriptor",sxuf_ext_original_group_descriptor_fields,SX_COUNT(sxuf_ext_original_group_descriptor_fields),SX_LE};
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
const sx_layout sxuf_ext_linux_inode = {UINT32_C(0x60110006),"ext_linux_inode",sxuf_ext_linux_inode_fields,SX_COUNT(sxuf_ext_linux_inode_fields),SX_LE};
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
const sx_layout sxuf_ext_other_os_inode = {UINT32_C(0x60110007),"ext_other_os_inode",sxuf_ext_other_os_inode_fields,SX_COUNT(sxuf_ext_other_os_inode_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_2_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxuf_ext_inode_extra_2 = {UINT32_C(0x60110008),"ext_inode_extra_2",sxuf_ext_inode_extra_2_fields,SX_COUNT(sxuf_ext_inode_extra_2_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_4_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
    SX_FIELD("checksum_high","uint16",2,2,SX_CHECKSUM),
};
const sx_layout sxuf_ext_inode_extra_4 = {UINT32_C(0x60110009),"ext_inode_extra_4",sxuf_ext_inode_extra_4_fields,SX_COUNT(sxuf_ext_inode_extra_4_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_8_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
    SX_FIELD("checksum_high","uint16",2,2,SX_CHECKSUM),
    SX_FIELD("ctime_extra","uint32",4,4,SX_FLAGS),
};
const sx_layout sxuf_ext_inode_extra_8 = {UINT32_C(0x6011000a),"ext_inode_extra_8",sxuf_ext_inode_extra_8_fields,SX_COUNT(sxuf_ext_inode_extra_8_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_12_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
    SX_FIELD("checksum_high","uint16",2,2,SX_CHECKSUM),
    SX_FIELD("ctime_extra","uint32",4,4,SX_FLAGS),
    SX_FIELD("mtime_extra","uint32",8,4,SX_FLAGS),
};
const sx_layout sxuf_ext_inode_extra_12 = {UINT32_C(0x6011000b),"ext_inode_extra_12",sxuf_ext_inode_extra_12_fields,SX_COUNT(sxuf_ext_inode_extra_12_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_16_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
    SX_FIELD("checksum_high","uint16",2,2,SX_CHECKSUM),
    SX_FIELD("ctime_extra","uint32",4,4,SX_FLAGS),
    SX_FIELD("mtime_extra","uint32",8,4,SX_FLAGS),
    SX_FIELD("atime_extra","uint32",12,4,SX_FLAGS),
};
const sx_layout sxuf_ext_inode_extra_16 = {UINT32_C(0x6011000c),"ext_inode_extra_16",sxuf_ext_inode_extra_16_fields,SX_COUNT(sxuf_ext_inode_extra_16_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_20_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
    SX_FIELD("checksum_high","uint16",2,2,SX_CHECKSUM),
    SX_FIELD("ctime_extra","uint32",4,4,SX_FLAGS),
    SX_FIELD("mtime_extra","uint32",8,4,SX_FLAGS),
    SX_FIELD("atime_extra","uint32",12,4,SX_FLAGS),
    SX_FIELD("creation_time_low","int32",16,4,SX_NONE),
};
const sx_layout sxuf_ext_inode_extra_20 = {UINT32_C(0x6011000d),"ext_inode_extra_20",sxuf_ext_inode_extra_20_fields,SX_COUNT(sxuf_ext_inode_extra_20_fields),SX_LE};
static const xx_data_struct_field_desc sxuf_ext_inode_extra_24_fields[] = {
    SX_FIELD("extra_size","uint16",0,2,SX_SIZE),
    SX_FIELD("checksum_high","uint16",2,2,SX_CHECKSUM),
    SX_FIELD("ctime_extra","uint32",4,4,SX_FLAGS),
    SX_FIELD("mtime_extra","uint32",8,4,SX_FLAGS),
    SX_FIELD("atime_extra","uint32",12,4,SX_FLAGS),
    SX_FIELD("creation_time_low","int32",16,4,SX_NONE),
    SX_FIELD("creation_time_extra","uint32",20,4,SX_FLAGS),
};
const sx_layout sxuf_ext_inode_extra_24 = {UINT32_C(0x6011000e),"ext_inode_extra_24",sxuf_ext_inode_extra_24_fields,SX_COUNT(sxuf_ext_inode_extra_24_fields),SX_LE};
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
const sx_layout sxuf_ext_inode_extra_28 = {UINT32_C(0x6011000f),"ext_inode_extra_28",sxuf_ext_inode_extra_28_fields,SX_COUNT(sxuf_ext_inode_extra_28_fields),SX_LE};
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
const sx_layout sxuf_ext_inode_extra_32 = {UINT32_C(0x60110010),"ext_inode_extra_32",sxuf_ext_inode_extra_32_fields,SX_COUNT(sxuf_ext_inode_extra_32_fields),SX_LE};
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
bool sx_ext_build(sx_context*c)
{
return sxuf_ext(c)&&sxuf_finish(c);
}
