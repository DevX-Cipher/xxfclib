/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical classic filesystem metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_classicfs_scope.txt. */

static const xx_data_struct_field_desc sxcf_minix1_superblock_le_fields[] = {
    SX_FIELD("inode_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("zone_count_16","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("inode_bitmap_blocks","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("zone_bitmap_blocks","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("first_data_zone","uint16",8,2,SX_NONE),
    SX_FIELD("log_zone_size","uint16",10,2,SX_NONE),
    SX_FIELD("max_file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("magic","uint16",16,2,SX_SIGNATURE),
    SX_FIELD("state","uint16",18,2,SX_FLAGS),
};
static const sx_layout sxcf_minix1_superblock_le = {0x603d0001U,"minix1_superblock_le",sxcf_minix1_superblock_le_fields,SX_COUNT(sxcf_minix1_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_minix1_superblock_be_fields[] = {
    SX_FIELD("inode_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("zone_count_16","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("inode_bitmap_blocks","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("zone_bitmap_blocks","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("first_data_zone","uint16",8,2,SX_NONE),
    SX_FIELD("log_zone_size","uint16",10,2,SX_NONE),
    SX_FIELD("max_file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("magic","uint16",16,2,SX_SIGNATURE),
    SX_FIELD("state","uint16",18,2,SX_FLAGS),
};
static const sx_layout sxcf_minix1_superblock_be = {0x603d0002U,"minix1_superblock_be",sxcf_minix1_superblock_be_fields,SX_COUNT(sxcf_minix1_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_minix2_superblock_le_fields[] = {
    SX_FIELD("inode_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("zone_count_16","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("inode_bitmap_blocks","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("zone_bitmap_blocks","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("first_data_zone","uint16",8,2,SX_NONE),
    SX_FIELD("log_zone_size","uint16",10,2,SX_NONE),
    SX_FIELD("max_file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("magic","uint16",16,2,SX_SIGNATURE),
    SX_FIELD("state","uint16",18,2,SX_FLAGS),
    SX_FIELD("zone_count","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxcf_minix2_superblock_le = {0x603d0003U,"minix2_superblock_le",sxcf_minix2_superblock_le_fields,SX_COUNT(sxcf_minix2_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_minix2_superblock_be_fields[] = {
    SX_FIELD("inode_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("zone_count_16","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("inode_bitmap_blocks","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("zone_bitmap_blocks","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("first_data_zone","uint16",8,2,SX_NONE),
    SX_FIELD("log_zone_size","uint16",10,2,SX_NONE),
    SX_FIELD("max_file_size","uint32",12,4,SX_SIZE),
    SX_FIELD("magic","uint16",16,2,SX_SIGNATURE),
    SX_FIELD("state","uint16",18,2,SX_FLAGS),
    SX_FIELD("zone_count","uint32",20,4,SX_COUNT_PROP),
};
static const sx_layout sxcf_minix2_superblock_be = {0x603d0004U,"minix2_superblock_be",sxcf_minix2_superblock_be_fields,SX_COUNT(sxcf_minix2_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_minix3_superblock_le_fields[] = {
    SX_FIELD("inode_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("padding0","uint16",4,2,SX_RESERVED),
    SX_FIELD("inode_bitmap_blocks","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("zone_bitmap_blocks","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("first_data_zone","uint16",10,2,SX_NONE),
    SX_FIELD("log_zone_size","uint16",12,2,SX_NONE),
    SX_FIELD("padding1","uint16",14,2,SX_RESERVED),
    SX_FIELD("max_file_size","uint32",16,4,SX_SIZE),
    SX_FIELD("zone_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("magic","uint16",24,2,SX_SIGNATURE),
    SX_FIELD("padding2","uint16",26,2,SX_RESERVED),
    SX_FIELD("block_size","uint16",28,2,SX_SIZE),
    SX_FIELD("disk_version","uint8",30,1,SX_ID),
};
static const sx_layout sxcf_minix3_superblock_le = {0x603d0005U,"minix3_superblock_le",sxcf_minix3_superblock_le_fields,SX_COUNT(sxcf_minix3_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_minix3_superblock_be_fields[] = {
    SX_FIELD("inode_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("padding0","uint16",4,2,SX_RESERVED),
    SX_FIELD("inode_bitmap_blocks","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("zone_bitmap_blocks","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("first_data_zone","uint16",10,2,SX_NONE),
    SX_FIELD("log_zone_size","uint16",12,2,SX_NONE),
    SX_FIELD("padding1","uint16",14,2,SX_RESERVED),
    SX_FIELD("max_file_size","uint32",16,4,SX_SIZE),
    SX_FIELD("zone_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("magic","uint16",24,2,SX_SIGNATURE),
    SX_FIELD("padding2","uint16",26,2,SX_RESERVED),
    SX_FIELD("block_size","uint16",28,2,SX_SIZE),
    SX_FIELD("disk_version","uint8",30,1,SX_ID),
};
static const sx_layout sxcf_minix3_superblock_be = {0x603d0006U,"minix3_superblock_be",sxcf_minix3_superblock_be_fields,SX_COUNT(sxcf_minix3_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_minix1_inode_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("user_id","uint16",2,2,SX_ID),
    SX_FIELD("file_size","uint32",4,4,SX_SIZE),
    SX_FIELD("modification_time","uint32",8,4,SX_TIME),
    SX_FIELD("group_id","uint8",12,1,SX_ID),
    SX_FIELD("link_count","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("zone_numbers","uint16[9]",14,18,SX_NONE),
};
static const sx_layout sxcf_minix1_inode_le = {0x603d0007U,"minix1_inode_le",sxcf_minix1_inode_le_fields,SX_COUNT(sxcf_minix1_inode_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_minix1_inode_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("user_id","uint16",2,2,SX_ID),
    SX_FIELD("file_size","uint32",4,4,SX_SIZE),
    SX_FIELD("modification_time","uint32",8,4,SX_TIME),
    SX_FIELD("group_id","uint8",12,1,SX_ID),
    SX_FIELD("link_count","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("zone_numbers","uint16[9]",14,18,SX_NONE),
};
static const sx_layout sxcf_minix1_inode_be = {0x603d0008U,"minix1_inode_be",sxcf_minix1_inode_be_fields,SX_COUNT(sxcf_minix1_inode_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_minix23_inode_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","uint16",4,2,SX_ID),
    SX_FIELD("group_id","uint16",6,2,SX_ID),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("access_time","uint32",12,4,SX_TIME),
    SX_FIELD("modification_time","uint32",16,4,SX_TIME),
    SX_FIELD("inode_change_time","uint32",20,4,SX_TIME),
    SX_FIELD("zone_numbers","uint32[10]",24,40,SX_NONE),
};
static const sx_layout sxcf_minix23_inode_le = {0x603d0009U,"minix23_inode_le",sxcf_minix23_inode_le_fields,SX_COUNT(sxcf_minix23_inode_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_minix23_inode_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","uint16",4,2,SX_ID),
    SX_FIELD("group_id","uint16",6,2,SX_ID),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("access_time","uint32",12,4,SX_TIME),
    SX_FIELD("modification_time","uint32",16,4,SX_TIME),
    SX_FIELD("inode_change_time","uint32",20,4,SX_TIME),
    SX_FIELD("zone_numbers","uint32[10]",24,40,SX_NONE),
};
static const sx_layout sxcf_minix23_inode_be = {0x603d000aU,"minix23_inode_be",sxcf_minix23_inode_be_fields,SX_COUNT(sxcf_minix23_inode_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_minix_directory_14_le_fields[] = {
    SX_FIELD("inode_number","uint16",0,2,SX_NONE),
    SX_FIELD("name","char[14]",2,14,SX_NONE),
};
static const sx_layout sxcf_minix_directory_14_le = {0x603d000bU,"minix_directory_14_le",sxcf_minix_directory_14_le_fields,SX_COUNT(sxcf_minix_directory_14_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_minix_directory_14_be_fields[] = {
    SX_FIELD("inode_number","uint16",0,2,SX_NONE),
    SX_FIELD("name","char[14]",2,14,SX_NONE),
};
static const sx_layout sxcf_minix_directory_14_be = {0x603d000cU,"minix_directory_14_be",sxcf_minix_directory_14_be_fields,SX_COUNT(sxcf_minix_directory_14_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_minix_directory_30_le_fields[] = {
    SX_FIELD("inode_number","uint16",0,2,SX_NONE),
    SX_FIELD("name","char[30]",2,30,SX_NONE),
};
static const sx_layout sxcf_minix_directory_30_le = {0x603d000dU,"minix_directory_30_le",sxcf_minix_directory_30_le_fields,SX_COUNT(sxcf_minix_directory_30_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_minix_directory_30_be_fields[] = {
    SX_FIELD("inode_number","uint16",0,2,SX_NONE),
    SX_FIELD("name","char[30]",2,30,SX_NONE),
};
static const sx_layout sxcf_minix_directory_30_be = {0x603d000eU,"minix_directory_30_be",sxcf_minix_directory_30_be_fields,SX_COUNT(sxcf_minix_directory_30_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_minix3_directory_le_fields[] = {
    SX_FIELD("inode_number","uint32",0,4,SX_NONE),
    SX_FIELD("name","char[60]",4,60,SX_NONE),
};
static const sx_layout sxcf_minix3_directory_le = {0x603d000fU,"minix3_directory_le",sxcf_minix3_directory_le_fields,SX_COUNT(sxcf_minix3_directory_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_minix3_directory_be_fields[] = {
    SX_FIELD("inode_number","uint32",0,4,SX_NONE),
    SX_FIELD("name","char[60]",4,60,SX_NONE),
};
static const sx_layout sxcf_minix3_directory_be = {0x603d0010U,"minix3_directory_be",sxcf_minix3_directory_be_fields,SX_COUNT(sxcf_minix3_directory_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_classic_block_number16_le_fields[] = {
    SX_FIELD("block_number","uint16",0,2,SX_NONE),
};
static const sx_layout sxcf_classic_block_number16_le = {0x603d0011U,"classic_block_number16_le",sxcf_classic_block_number16_le_fields,SX_COUNT(sxcf_classic_block_number16_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_classic_block_number16_be_fields[] = {
    SX_FIELD("block_number","uint16",0,2,SX_NONE),
};
static const sx_layout sxcf_classic_block_number16_be = {0x603d0012U,"classic_block_number16_be",sxcf_classic_block_number16_be_fields,SX_COUNT(sxcf_classic_block_number16_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_classic_block_number32_le_fields[] = {
    SX_FIELD("block_number","uint32",0,4,SX_NONE),
};
static const sx_layout sxcf_classic_block_number32_le = {0x603d0013U,"classic_block_number32_le",sxcf_classic_block_number32_le_fields,SX_COUNT(sxcf_classic_block_number32_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_classic_block_number32_be_fields[] = {
    SX_FIELD("block_number","uint32",0,4,SX_NONE),
};
static const sx_layout sxcf_classic_block_number32_be = {0x603d0014U,"classic_block_number32_be",sxcf_classic_block_number32_be_fields,SX_COUNT(sxcf_classic_block_number32_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_classic_block_number_pdp_fields[] = {
    SX_FIELD("block_number","uint32_pdp",0,4,SX_NONE),
};
static const sx_layout sxcf_classic_block_number_pdp = {0x603d0015U,"classic_block_number_pdp",sxcf_classic_block_number_pdp_fields,SX_COUNT(sxcf_classic_block_number_pdp_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_v7_superblock_le_fields[] = {
    SX_FIELD("first_data_block","uint16",0,2,SX_NONE),
    SX_FIELD("block_count","uint32",2,4,SX_COUNT_PROP),
    SX_FIELD("free_block_cache_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("free_block_cache","uint32[50]",8,200,SX_NONE),
    SX_FIELD("free_inode_cache_count","uint16",208,2,SX_COUNT_PROP),
    SX_FIELD("free_inode_cache","uint16[100]",210,200,SX_NONE),
    SX_FIELD("free_block_lock","uint8",410,1,SX_FLAGS),
    SX_FIELD("inode_cache_lock","uint8",411,1,SX_FLAGS),
    SX_FIELD("modified","uint8",412,1,SX_FLAGS),
    SX_FIELD("read_only","uint8",413,1,SX_FLAGS),
    SX_FIELD("last_update","uint32",414,4,SX_TIME),
    SX_FIELD("free_block_count","uint32",418,4,SX_COUNT_PROP),
    SX_FIELD("free_inode_count","uint16",422,2,SX_COUNT_PROP),
    SX_FIELD("interleave_m","uint16",424,2,SX_NONE),
    SX_FIELD("interleave_n","uint16",426,2,SX_NONE),
    SX_FIELD("volume_name","char[6]",428,6,SX_NONE),
    SX_FIELD("pack_name","char[6]",434,6,SX_NONE),
};
static const sx_layout sxcf_v7_superblock_le = {0x603d0016U,"v7_superblock_le",sxcf_v7_superblock_le_fields,SX_COUNT(sxcf_v7_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_v7_superblock_be_fields[] = {
    SX_FIELD("first_data_block","uint16",0,2,SX_NONE),
    SX_FIELD("block_count","uint32",2,4,SX_COUNT_PROP),
    SX_FIELD("free_block_cache_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("free_block_cache","uint32[50]",8,200,SX_NONE),
    SX_FIELD("free_inode_cache_count","uint16",208,2,SX_COUNT_PROP),
    SX_FIELD("free_inode_cache","uint16[100]",210,200,SX_NONE),
    SX_FIELD("free_block_lock","uint8",410,1,SX_FLAGS),
    SX_FIELD("inode_cache_lock","uint8",411,1,SX_FLAGS),
    SX_FIELD("modified","uint8",412,1,SX_FLAGS),
    SX_FIELD("read_only","uint8",413,1,SX_FLAGS),
    SX_FIELD("last_update","uint32",414,4,SX_TIME),
    SX_FIELD("free_block_count","uint32",418,4,SX_COUNT_PROP),
    SX_FIELD("free_inode_count","uint16",422,2,SX_COUNT_PROP),
    SX_FIELD("interleave_m","uint16",424,2,SX_NONE),
    SX_FIELD("interleave_n","uint16",426,2,SX_NONE),
    SX_FIELD("volume_name","char[6]",428,6,SX_NONE),
    SX_FIELD("pack_name","char[6]",434,6,SX_NONE),
};
static const sx_layout sxcf_v7_superblock_be = {0x603d0017U,"v7_superblock_be",sxcf_v7_superblock_be_fields,SX_COUNT(sxcf_v7_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_v7_superblock_pdp_fields[] = {
    SX_FIELD("first_data_block","uint16",0,2,SX_NONE),
    SX_FIELD("block_count","uint32_pdp",2,4,SX_COUNT_PROP),
    SX_FIELD("free_block_cache_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("free_block_00","uint32_pdp",8,4,SX_NONE),
    SX_FIELD("free_block_01","uint32_pdp",12,4,SX_NONE),
    SX_FIELD("free_block_02","uint32_pdp",16,4,SX_NONE),
    SX_FIELD("free_block_03","uint32_pdp",20,4,SX_NONE),
    SX_FIELD("free_block_04","uint32_pdp",24,4,SX_NONE),
    SX_FIELD("free_block_05","uint32_pdp",28,4,SX_NONE),
    SX_FIELD("free_block_06","uint32_pdp",32,4,SX_NONE),
    SX_FIELD("free_block_07","uint32_pdp",36,4,SX_NONE),
    SX_FIELD("free_block_08","uint32_pdp",40,4,SX_NONE),
    SX_FIELD("free_block_09","uint32_pdp",44,4,SX_NONE),
    SX_FIELD("free_block_10","uint32_pdp",48,4,SX_NONE),
    SX_FIELD("free_block_11","uint32_pdp",52,4,SX_NONE),
    SX_FIELD("free_block_12","uint32_pdp",56,4,SX_NONE),
    SX_FIELD("free_block_13","uint32_pdp",60,4,SX_NONE),
    SX_FIELD("free_block_14","uint32_pdp",64,4,SX_NONE),
    SX_FIELD("free_block_15","uint32_pdp",68,4,SX_NONE),
    SX_FIELD("free_block_16","uint32_pdp",72,4,SX_NONE),
    SX_FIELD("free_block_17","uint32_pdp",76,4,SX_NONE),
    SX_FIELD("free_block_18","uint32_pdp",80,4,SX_NONE),
    SX_FIELD("free_block_19","uint32_pdp",84,4,SX_NONE),
    SX_FIELD("free_block_20","uint32_pdp",88,4,SX_NONE),
    SX_FIELD("free_block_21","uint32_pdp",92,4,SX_NONE),
    SX_FIELD("free_block_22","uint32_pdp",96,4,SX_NONE),
    SX_FIELD("free_block_23","uint32_pdp",100,4,SX_NONE),
    SX_FIELD("free_block_24","uint32_pdp",104,4,SX_NONE),
    SX_FIELD("free_block_25","uint32_pdp",108,4,SX_NONE),
    SX_FIELD("free_block_26","uint32_pdp",112,4,SX_NONE),
    SX_FIELD("free_block_27","uint32_pdp",116,4,SX_NONE),
    SX_FIELD("free_block_28","uint32_pdp",120,4,SX_NONE),
    SX_FIELD("free_block_29","uint32_pdp",124,4,SX_NONE),
    SX_FIELD("free_block_30","uint32_pdp",128,4,SX_NONE),
    SX_FIELD("free_block_31","uint32_pdp",132,4,SX_NONE),
    SX_FIELD("free_block_32","uint32_pdp",136,4,SX_NONE),
    SX_FIELD("free_block_33","uint32_pdp",140,4,SX_NONE),
    SX_FIELD("free_block_34","uint32_pdp",144,4,SX_NONE),
    SX_FIELD("free_block_35","uint32_pdp",148,4,SX_NONE),
    SX_FIELD("free_block_36","uint32_pdp",152,4,SX_NONE),
    SX_FIELD("free_block_37","uint32_pdp",156,4,SX_NONE),
    SX_FIELD("free_block_38","uint32_pdp",160,4,SX_NONE),
    SX_FIELD("free_block_39","uint32_pdp",164,4,SX_NONE),
    SX_FIELD("free_block_40","uint32_pdp",168,4,SX_NONE),
    SX_FIELD("free_block_41","uint32_pdp",172,4,SX_NONE),
    SX_FIELD("free_block_42","uint32_pdp",176,4,SX_NONE),
    SX_FIELD("free_block_43","uint32_pdp",180,4,SX_NONE),
    SX_FIELD("free_block_44","uint32_pdp",184,4,SX_NONE),
    SX_FIELD("free_block_45","uint32_pdp",188,4,SX_NONE),
    SX_FIELD("free_block_46","uint32_pdp",192,4,SX_NONE),
    SX_FIELD("free_block_47","uint32_pdp",196,4,SX_NONE),
    SX_FIELD("free_block_48","uint32_pdp",200,4,SX_NONE),
    SX_FIELD("free_block_49","uint32_pdp",204,4,SX_NONE),
    SX_FIELD("free_inode_cache_count","uint16",208,2,SX_COUNT_PROP),
    SX_FIELD("free_inode_cache","uint16[100]",210,200,SX_NONE),
    SX_FIELD("free_block_lock","uint8",410,1,SX_FLAGS),
    SX_FIELD("inode_cache_lock","uint8",411,1,SX_FLAGS),
    SX_FIELD("modified","uint8",412,1,SX_FLAGS),
    SX_FIELD("read_only","uint8",413,1,SX_FLAGS),
    SX_FIELD("last_update","uint32_pdp",414,4,SX_TIME),
    SX_FIELD("free_block_count","uint32_pdp",418,4,SX_COUNT_PROP),
    SX_FIELD("free_inode_count","uint16",422,2,SX_COUNT_PROP),
    SX_FIELD("interleave_m","uint16",424,2,SX_NONE),
    SX_FIELD("interleave_n","uint16",426,2,SX_NONE),
    SX_FIELD("volume_name","char[6]",428,6,SX_NONE),
    SX_FIELD("pack_name","char[6]",434,6,SX_NONE),
};
static const sx_layout sxcf_v7_superblock_pdp = {0x603d0018U,"v7_superblock_pdp",sxcf_v7_superblock_pdp_fields,SX_COUNT(sxcf_v7_superblock_pdp_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_coherent_superblock_pdp_fields[] = {
    SX_FIELD("first_data_block","uint16",0,2,SX_NONE),
    SX_FIELD("block_count","uint32_pdp",2,4,SX_COUNT_PROP),
    SX_FIELD("free_block_cache_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("free_block_00","uint32_pdp",8,4,SX_NONE),
    SX_FIELD("free_block_01","uint32_pdp",12,4,SX_NONE),
    SX_FIELD("free_block_02","uint32_pdp",16,4,SX_NONE),
    SX_FIELD("free_block_03","uint32_pdp",20,4,SX_NONE),
    SX_FIELD("free_block_04","uint32_pdp",24,4,SX_NONE),
    SX_FIELD("free_block_05","uint32_pdp",28,4,SX_NONE),
    SX_FIELD("free_block_06","uint32_pdp",32,4,SX_NONE),
    SX_FIELD("free_block_07","uint32_pdp",36,4,SX_NONE),
    SX_FIELD("free_block_08","uint32_pdp",40,4,SX_NONE),
    SX_FIELD("free_block_09","uint32_pdp",44,4,SX_NONE),
    SX_FIELD("free_block_10","uint32_pdp",48,4,SX_NONE),
    SX_FIELD("free_block_11","uint32_pdp",52,4,SX_NONE),
    SX_FIELD("free_block_12","uint32_pdp",56,4,SX_NONE),
    SX_FIELD("free_block_13","uint32_pdp",60,4,SX_NONE),
    SX_FIELD("free_block_14","uint32_pdp",64,4,SX_NONE),
    SX_FIELD("free_block_15","uint32_pdp",68,4,SX_NONE),
    SX_FIELD("free_block_16","uint32_pdp",72,4,SX_NONE),
    SX_FIELD("free_block_17","uint32_pdp",76,4,SX_NONE),
    SX_FIELD("free_block_18","uint32_pdp",80,4,SX_NONE),
    SX_FIELD("free_block_19","uint32_pdp",84,4,SX_NONE),
    SX_FIELD("free_block_20","uint32_pdp",88,4,SX_NONE),
    SX_FIELD("free_block_21","uint32_pdp",92,4,SX_NONE),
    SX_FIELD("free_block_22","uint32_pdp",96,4,SX_NONE),
    SX_FIELD("free_block_23","uint32_pdp",100,4,SX_NONE),
    SX_FIELD("free_block_24","uint32_pdp",104,4,SX_NONE),
    SX_FIELD("free_block_25","uint32_pdp",108,4,SX_NONE),
    SX_FIELD("free_block_26","uint32_pdp",112,4,SX_NONE),
    SX_FIELD("free_block_27","uint32_pdp",116,4,SX_NONE),
    SX_FIELD("free_block_28","uint32_pdp",120,4,SX_NONE),
    SX_FIELD("free_block_29","uint32_pdp",124,4,SX_NONE),
    SX_FIELD("free_block_30","uint32_pdp",128,4,SX_NONE),
    SX_FIELD("free_block_31","uint32_pdp",132,4,SX_NONE),
    SX_FIELD("free_block_32","uint32_pdp",136,4,SX_NONE),
    SX_FIELD("free_block_33","uint32_pdp",140,4,SX_NONE),
    SX_FIELD("free_block_34","uint32_pdp",144,4,SX_NONE),
    SX_FIELD("free_block_35","uint32_pdp",148,4,SX_NONE),
    SX_FIELD("free_block_36","uint32_pdp",152,4,SX_NONE),
    SX_FIELD("free_block_37","uint32_pdp",156,4,SX_NONE),
    SX_FIELD("free_block_38","uint32_pdp",160,4,SX_NONE),
    SX_FIELD("free_block_39","uint32_pdp",164,4,SX_NONE),
    SX_FIELD("free_block_40","uint32_pdp",168,4,SX_NONE),
    SX_FIELD("free_block_41","uint32_pdp",172,4,SX_NONE),
    SX_FIELD("free_block_42","uint32_pdp",176,4,SX_NONE),
    SX_FIELD("free_block_43","uint32_pdp",180,4,SX_NONE),
    SX_FIELD("free_block_44","uint32_pdp",184,4,SX_NONE),
    SX_FIELD("free_block_45","uint32_pdp",188,4,SX_NONE),
    SX_FIELD("free_block_46","uint32_pdp",192,4,SX_NONE),
    SX_FIELD("free_block_47","uint32_pdp",196,4,SX_NONE),
    SX_FIELD("free_block_48","uint32_pdp",200,4,SX_NONE),
    SX_FIELD("free_block_49","uint32_pdp",204,4,SX_NONE),
    SX_FIELD("free_block_50","uint32_pdp",208,4,SX_NONE),
    SX_FIELD("free_block_51","uint32_pdp",212,4,SX_NONE),
    SX_FIELD("free_block_52","uint32_pdp",216,4,SX_NONE),
    SX_FIELD("free_block_53","uint32_pdp",220,4,SX_NONE),
    SX_FIELD("free_block_54","uint32_pdp",224,4,SX_NONE),
    SX_FIELD("free_block_55","uint32_pdp",228,4,SX_NONE),
    SX_FIELD("free_block_56","uint32_pdp",232,4,SX_NONE),
    SX_FIELD("free_block_57","uint32_pdp",236,4,SX_NONE),
    SX_FIELD("free_block_58","uint32_pdp",240,4,SX_NONE),
    SX_FIELD("free_block_59","uint32_pdp",244,4,SX_NONE),
    SX_FIELD("free_block_60","uint32_pdp",248,4,SX_NONE),
    SX_FIELD("free_block_61","uint32_pdp",252,4,SX_NONE),
    SX_FIELD("free_block_62","uint32_pdp",256,4,SX_NONE),
    SX_FIELD("free_block_63","uint32_pdp",260,4,SX_NONE),
    SX_FIELD("free_inode_cache_count","uint16",264,2,SX_COUNT_PROP),
    SX_FIELD("free_inode_cache","uint16[100]",266,200,SX_NONE),
    SX_FIELD("free_block_lock","uint8",466,1,SX_FLAGS),
    SX_FIELD("inode_cache_lock","uint8",467,1,SX_FLAGS),
    SX_FIELD("modified","uint8",468,1,SX_FLAGS),
    SX_FIELD("read_only","uint8",469,1,SX_FLAGS),
    SX_FIELD("last_update","uint32_pdp",470,4,SX_TIME),
    SX_FIELD("free_block_count","uint32_pdp",474,4,SX_COUNT_PROP),
    SX_FIELD("free_inode_count","uint16",478,2,SX_COUNT_PROP),
    SX_FIELD("interleave_m","uint16",480,2,SX_NONE),
    SX_FIELD("interleave_n","uint16",482,2,SX_NONE),
    SX_FIELD("volume_name","char[6]",484,6,SX_NONE),
    SX_FIELD("pack_name","char[6]",490,6,SX_NONE),
    SX_FIELD("unique_unused","uint32_pdp",496,4,SX_RESERVED),
};
static const sx_layout sxcf_coherent_superblock_pdp = {0x603d0019U,"coherent_superblock_pdp",sxcf_coherent_superblock_pdp_fields,SX_COUNT(sxcf_coherent_superblock_pdp_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_sysv2_superblock_le_fields[] = {
    SX_FIELD("first_data_block","uint16",0,2,SX_NONE),
    SX_FIELD("block_count","uint32",2,4,SX_COUNT_PROP),
    SX_FIELD("free_block_cache_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("free_block_cache","uint32[50]",8,200,SX_NONE),
    SX_FIELD("free_inode_cache_count","uint16",208,2,SX_COUNT_PROP),
    SX_FIELD("free_inode_cache","uint16[100]",210,200,SX_NONE),
    SX_FIELD("free_block_lock","uint8",410,1,SX_FLAGS),
    SX_FIELD("inode_cache_lock","uint8",411,1,SX_FLAGS),
    SX_FIELD("modified","uint8",412,1,SX_FLAGS),
    SX_FIELD("read_only","uint8",413,1,SX_FLAGS),
    SX_FIELD("last_update","uint32",414,4,SX_TIME),
    SX_FIELD("device_information","uint16[4]",418,8,SX_NONE),
    SX_FIELD("free_block_count","uint32",426,4,SX_COUNT_PROP),
    SX_FIELD("free_inode_count","uint16",430,2,SX_COUNT_PROP),
    SX_FIELD("volume_name","char[6]",432,6,SX_NONE),
    SX_FIELD("pack_name","char[6]",438,6,SX_NONE),
    SX_FIELD("reserved","byte[56]",444,56,SX_RESERVED),
    SX_FIELD("state","uint32",500,4,SX_FLAGS),
    SX_FIELD("magic","uint32",504,4,SX_SIGNATURE),
    SX_FIELD("block_size_type","uint32",508,4,SX_ID),
};
static const sx_layout sxcf_sysv2_superblock_le = {0x603d001aU,"sysv2_superblock_le",sxcf_sysv2_superblock_le_fields,SX_COUNT(sxcf_sysv2_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_sysv2_superblock_be_fields[] = {
    SX_FIELD("first_data_block","uint16",0,2,SX_NONE),
    SX_FIELD("block_count","uint32",2,4,SX_COUNT_PROP),
    SX_FIELD("free_block_cache_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("free_block_cache","uint32[50]",8,200,SX_NONE),
    SX_FIELD("free_inode_cache_count","uint16",208,2,SX_COUNT_PROP),
    SX_FIELD("free_inode_cache","uint16[100]",210,200,SX_NONE),
    SX_FIELD("free_block_lock","uint8",410,1,SX_FLAGS),
    SX_FIELD("inode_cache_lock","uint8",411,1,SX_FLAGS),
    SX_FIELD("modified","uint8",412,1,SX_FLAGS),
    SX_FIELD("read_only","uint8",413,1,SX_FLAGS),
    SX_FIELD("last_update","uint32",414,4,SX_TIME),
    SX_FIELD("device_information","uint16[4]",418,8,SX_NONE),
    SX_FIELD("free_block_count","uint32",426,4,SX_COUNT_PROP),
    SX_FIELD("free_inode_count","uint16",430,2,SX_COUNT_PROP),
    SX_FIELD("volume_name","char[6]",432,6,SX_NONE),
    SX_FIELD("pack_name","char[6]",438,6,SX_NONE),
    SX_FIELD("reserved","byte[56]",444,56,SX_RESERVED),
    SX_FIELD("state","uint32",500,4,SX_FLAGS),
    SX_FIELD("magic","uint32",504,4,SX_SIGNATURE),
    SX_FIELD("block_size_type","uint32",508,4,SX_ID),
};
static const sx_layout sxcf_sysv2_superblock_be = {0x603d001bU,"sysv2_superblock_be",sxcf_sysv2_superblock_be_fields,SX_COUNT(sxcf_sysv2_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_sysv4_superblock_le_fields[] = {
    SX_FIELD("first_data_block","uint16",0,2,SX_NONE),
    SX_FIELD("padding0","uint16",2,2,SX_RESERVED),
    SX_FIELD("block_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("free_block_cache_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("padding1","uint16",10,2,SX_RESERVED),
    SX_FIELD("free_block_cache","uint32[50]",12,200,SX_NONE),
    SX_FIELD("free_inode_cache_count","uint16",212,2,SX_COUNT_PROP),
    SX_FIELD("padding2","uint16",214,2,SX_RESERVED),
    SX_FIELD("free_inode_cache","uint16[100]",216,200,SX_NONE),
    SX_FIELD("free_block_lock","uint8",416,1,SX_FLAGS),
    SX_FIELD("inode_cache_lock","uint8",417,1,SX_FLAGS),
    SX_FIELD("modified","uint8",418,1,SX_FLAGS),
    SX_FIELD("read_only","uint8",419,1,SX_FLAGS),
    SX_FIELD("last_update","uint32",420,4,SX_TIME),
    SX_FIELD("device_information","uint16[4]",424,8,SX_NONE),
    SX_FIELD("free_block_count","uint32",432,4,SX_COUNT_PROP),
    SX_FIELD("free_inode_count","uint16",436,2,SX_COUNT_PROP),
    SX_FIELD("padding3","uint16",438,2,SX_RESERVED),
    SX_FIELD("volume_name","char[6]",440,6,SX_NONE),
    SX_FIELD("pack_name","char[6]",446,6,SX_NONE),
    SX_FIELD("reserved","byte[48]",452,48,SX_RESERVED),
    SX_FIELD("state","uint32",500,4,SX_FLAGS),
    SX_FIELD("magic","uint32",504,4,SX_SIGNATURE),
    SX_FIELD("block_size_type","uint32",508,4,SX_ID),
};
static const sx_layout sxcf_sysv4_superblock_le = {0x603d001cU,"sysv4_superblock_le",sxcf_sysv4_superblock_le_fields,SX_COUNT(sxcf_sysv4_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_sysv4_superblock_be_fields[] = {
    SX_FIELD("first_data_block","uint16",0,2,SX_NONE),
    SX_FIELD("padding0","uint16",2,2,SX_RESERVED),
    SX_FIELD("block_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("free_block_cache_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("padding1","uint16",10,2,SX_RESERVED),
    SX_FIELD("free_block_cache","uint32[50]",12,200,SX_NONE),
    SX_FIELD("free_inode_cache_count","uint16",212,2,SX_COUNT_PROP),
    SX_FIELD("padding2","uint16",214,2,SX_RESERVED),
    SX_FIELD("free_inode_cache","uint16[100]",216,200,SX_NONE),
    SX_FIELD("free_block_lock","uint8",416,1,SX_FLAGS),
    SX_FIELD("inode_cache_lock","uint8",417,1,SX_FLAGS),
    SX_FIELD("modified","uint8",418,1,SX_FLAGS),
    SX_FIELD("read_only","uint8",419,1,SX_FLAGS),
    SX_FIELD("last_update","uint32",420,4,SX_TIME),
    SX_FIELD("device_information","uint16[4]",424,8,SX_NONE),
    SX_FIELD("free_block_count","uint32",432,4,SX_COUNT_PROP),
    SX_FIELD("free_inode_count","uint16",436,2,SX_COUNT_PROP),
    SX_FIELD("padding3","uint16",438,2,SX_RESERVED),
    SX_FIELD("volume_name","char[6]",440,6,SX_NONE),
    SX_FIELD("pack_name","char[6]",446,6,SX_NONE),
    SX_FIELD("reserved","byte[48]",452,48,SX_RESERVED),
    SX_FIELD("state","uint32",500,4,SX_FLAGS),
    SX_FIELD("magic","uint32",504,4,SX_SIGNATURE),
    SX_FIELD("block_size_type","uint32",508,4,SX_ID),
};
static const sx_layout sxcf_sysv4_superblock_be = {0x603d001dU,"sysv4_superblock_be",sxcf_sysv4_superblock_be_fields,SX_COUNT(sxcf_sysv4_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_xenix_superblock_le_fields[] = {
    SX_FIELD("first_data_block","uint16",0,2,SX_NONE),
    SX_FIELD("block_count","uint32",2,4,SX_COUNT_PROP),
    SX_FIELD("free_block_cache_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("free_block_cache","uint32[100]",8,400,SX_NONE),
    SX_FIELD("free_inode_cache_count","uint16",408,2,SX_COUNT_PROP),
    SX_FIELD("free_inode_cache","uint16[100]",410,200,SX_NONE),
    SX_FIELD("free_block_lock","uint8",610,1,SX_FLAGS),
    SX_FIELD("inode_cache_lock","uint8",611,1,SX_FLAGS),
    SX_FIELD("modified","uint8",612,1,SX_FLAGS),
    SX_FIELD("read_only","uint8",613,1,SX_FLAGS),
    SX_FIELD("last_update","uint32",614,4,SX_TIME),
    SX_FIELD("free_block_count","uint32",618,4,SX_COUNT_PROP),
    SX_FIELD("free_inode_count","uint16",622,2,SX_COUNT_PROP),
    SX_FIELD("device_information","uint16[4]",624,8,SX_NONE),
    SX_FIELD("volume_name","char[6]",632,6,SX_NONE),
    SX_FIELD("pack_name","char[6]",638,6,SX_NONE),
    SX_FIELD("clean","uint8",644,1,SX_FLAGS),
    SX_FIELD("reserved","byte[371]",645,371,SX_RESERVED),
    SX_FIELD("magic","uint32",1016,4,SX_SIGNATURE),
    SX_FIELD("block_size_type","uint32",1020,4,SX_ID),
};
static const sx_layout sxcf_xenix_superblock_le = {0x603d001eU,"xenix_superblock_le",sxcf_xenix_superblock_le_fields,SX_COUNT(sxcf_xenix_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_xenix_superblock_be_fields[] = {
    SX_FIELD("first_data_block","uint16",0,2,SX_NONE),
    SX_FIELD("block_count","uint32",2,4,SX_COUNT_PROP),
    SX_FIELD("free_block_cache_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("free_block_cache","uint32[100]",8,400,SX_NONE),
    SX_FIELD("free_inode_cache_count","uint16",408,2,SX_COUNT_PROP),
    SX_FIELD("free_inode_cache","uint16[100]",410,200,SX_NONE),
    SX_FIELD("free_block_lock","uint8",610,1,SX_FLAGS),
    SX_FIELD("inode_cache_lock","uint8",611,1,SX_FLAGS),
    SX_FIELD("modified","uint8",612,1,SX_FLAGS),
    SX_FIELD("read_only","uint8",613,1,SX_FLAGS),
    SX_FIELD("last_update","uint32",614,4,SX_TIME),
    SX_FIELD("free_block_count","uint32",618,4,SX_COUNT_PROP),
    SX_FIELD("free_inode_count","uint16",622,2,SX_COUNT_PROP),
    SX_FIELD("device_information","uint16[4]",624,8,SX_NONE),
    SX_FIELD("volume_name","char[6]",632,6,SX_NONE),
    SX_FIELD("pack_name","char[6]",638,6,SX_NONE),
    SX_FIELD("clean","uint8",644,1,SX_FLAGS),
    SX_FIELD("reserved","byte[371]",645,371,SX_RESERVED),
    SX_FIELD("magic","uint32",1016,4,SX_SIGNATURE),
    SX_FIELD("block_size_type","uint32",1020,4,SX_ID),
};
static const sx_layout sxcf_xenix_superblock_be = {0x603d001fU,"xenix_superblock_be",sxcf_xenix_superblock_be_fields,SX_COUNT(sxcf_xenix_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_unix_inode_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","uint16",4,2,SX_ID),
    SX_FIELD("group_id","uint16",6,2,SX_ID),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("block_numbers","uint24[13]",12,39,SX_NONE),
    SX_FIELD("generation","uint8",51,1,SX_NONE),
    SX_FIELD("access_time","uint32",52,4,SX_TIME),
    SX_FIELD("modification_time","uint32",56,4,SX_TIME),
    SX_FIELD("inode_change_time","uint32",60,4,SX_TIME),
};
static const sx_layout sxcf_unix_inode_le = {0x603d0020U,"unix_inode_le",sxcf_unix_inode_le_fields,SX_COUNT(sxcf_unix_inode_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_unix_inode_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","uint16",4,2,SX_ID),
    SX_FIELD("group_id","uint16",6,2,SX_ID),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("block_numbers","uint24[13]",12,39,SX_NONE),
    SX_FIELD("generation","uint8",51,1,SX_NONE),
    SX_FIELD("access_time","uint32",52,4,SX_TIME),
    SX_FIELD("modification_time","uint32",56,4,SX_TIME),
    SX_FIELD("inode_change_time","uint32",60,4,SX_TIME),
};
static const sx_layout sxcf_unix_inode_be = {0x603d0021U,"unix_inode_be",sxcf_unix_inode_be_fields,SX_COUNT(sxcf_unix_inode_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_unix_inode_pdp_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","uint16",4,2,SX_ID),
    SX_FIELD("group_id","uint16",6,2,SX_ID),
    SX_FIELD("file_size","uint32_pdp",8,4,SX_SIZE),
    SX_FIELD("block_00_high","uint8",12,1,SX_NONE),
    SX_FIELD("block_00_low","uint16",13,2,SX_NONE),
    SX_FIELD("block_01_high","uint8",15,1,SX_NONE),
    SX_FIELD("block_01_low","uint16",16,2,SX_NONE),
    SX_FIELD("block_02_high","uint8",18,1,SX_NONE),
    SX_FIELD("block_02_low","uint16",19,2,SX_NONE),
    SX_FIELD("block_03_high","uint8",21,1,SX_NONE),
    SX_FIELD("block_03_low","uint16",22,2,SX_NONE),
    SX_FIELD("block_04_high","uint8",24,1,SX_NONE),
    SX_FIELD("block_04_low","uint16",25,2,SX_NONE),
    SX_FIELD("block_05_high","uint8",27,1,SX_NONE),
    SX_FIELD("block_05_low","uint16",28,2,SX_NONE),
    SX_FIELD("block_06_high","uint8",30,1,SX_NONE),
    SX_FIELD("block_06_low","uint16",31,2,SX_NONE),
    SX_FIELD("block_07_high","uint8",33,1,SX_NONE),
    SX_FIELD("block_07_low","uint16",34,2,SX_NONE),
    SX_FIELD("block_08_high","uint8",36,1,SX_NONE),
    SX_FIELD("block_08_low","uint16",37,2,SX_NONE),
    SX_FIELD("block_09_high","uint8",39,1,SX_NONE),
    SX_FIELD("block_09_low","uint16",40,2,SX_NONE),
    SX_FIELD("block_10_high","uint8",42,1,SX_NONE),
    SX_FIELD("block_10_low","uint16",43,2,SX_NONE),
    SX_FIELD("block_11_high","uint8",45,1,SX_NONE),
    SX_FIELD("block_11_low","uint16",46,2,SX_NONE),
    SX_FIELD("block_12_high","uint8",48,1,SX_NONE),
    SX_FIELD("block_12_low","uint16",49,2,SX_NONE),
    SX_FIELD("generation","uint8",51,1,SX_NONE),
    SX_FIELD("access_time","uint32_pdp",52,4,SX_TIME),
    SX_FIELD("modification_time","uint32_pdp",56,4,SX_TIME),
    SX_FIELD("inode_change_time","uint32_pdp",60,4,SX_TIME),
};
static const sx_layout sxcf_unix_inode_pdp = {0x603d0022U,"unix_inode_pdp",sxcf_unix_inode_pdp_fields,SX_COUNT(sxcf_unix_inode_pdp_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_unix_directory_le_fields[] = {
    SX_FIELD("inode_number","uint16",0,2,SX_NONE),
    SX_FIELD("name","char[14]",2,14,SX_NONE),
};
static const sx_layout sxcf_unix_directory_le = {0x603d0023U,"unix_directory_le",sxcf_unix_directory_le_fields,SX_COUNT(sxcf_unix_directory_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_unix_directory_be_fields[] = {
    SX_FIELD("inode_number","uint16",0,2,SX_NONE),
    SX_FIELD("name","char[14]",2,14,SX_NONE),
};
static const sx_layout sxcf_unix_directory_be = {0x603d0024U,"unix_directory_be",sxcf_unix_directory_be_fields,SX_COUNT(sxcf_unix_directory_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_linux_ext_superblock_fields[] = {
    SX_FIELD("inode_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("block_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("first_free_block","uint32",8,4,SX_NONE),
    SX_FIELD("free_block_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("first_free_inode","uint32",16,4,SX_NONE),
    SX_FIELD("free_inode_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("first_data_block","uint32",24,4,SX_NONE),
    SX_FIELD("log_zone_size","uint32",28,4,SX_NONE),
    SX_FIELD("max_file_size","uint32",32,4,SX_SIZE),
    SX_FIELD("reserved","uint32[5]",36,20,SX_RESERVED),
    SX_FIELD("magic","uint16",56,2,SX_SIGNATURE),
    SX_FIELD("padding","uint16",58,2,SX_RESERVED),
};
static const sx_layout sxcf_linux_ext_superblock = {0x603d0025U,"linux_ext_superblock",sxcf_linux_ext_superblock_fields,SX_COUNT(sxcf_linux_ext_superblock_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_linux_ext_inode_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("user_id","uint16",2,2,SX_ID),
    SX_FIELD("file_size","uint32",4,4,SX_SIZE),
    SX_FIELD("modification_time","uint32",8,4,SX_TIME),
    SX_FIELD("group_id","uint8",12,1,SX_ID),
    SX_FIELD("link_count","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("reserved","uint16",14,2,SX_RESERVED),
    SX_FIELD("block_numbers","uint32[12]",16,48,SX_NONE),
};
static const sx_layout sxcf_linux_ext_inode = {0x603d0026U,"linux_ext_inode",sxcf_linux_ext_inode_fields,SX_COUNT(sxcf_linux_ext_inode_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_linux_ext_directory_header_fields[] = {
    SX_FIELD("inode_number","uint32",0,4,SX_NONE),
    SX_FIELD("record_size","uint16",4,2,SX_SIZE),
    SX_FIELD("name_size","uint16",6,2,SX_SIZE),
};
static const sx_layout sxcf_linux_ext_directory_header = {0x603d0027U,"linux_ext_directory_header",sxcf_linux_ext_directory_header_fields,SX_COUNT(sxcf_linux_ext_directory_header_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_xia_superblock_fields[] = {
    SX_FIELD("zone_size","uint32",0,4,SX_SIZE),
    SX_FIELD("zone_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("inode_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("data_zone_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("inode_bitmap_zones","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("zone_bitmap_zones","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("first_data_zone","uint32",24,4,SX_NONE),
    SX_FIELD("zone_shift","uint32",28,4,SX_NONE),
    SX_FIELD("max_file_size","uint32",32,4,SX_SIZE),
    SX_FIELD("reserved","uint32[4]",36,16,SX_RESERVED),
    SX_FIELD("first_kernel_zone","uint32",52,4,SX_NONE),
    SX_FIELD("kernel_zone_count","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("magic","uint32",60,4,SX_SIGNATURE),
};
static const sx_layout sxcf_xia_superblock = {0x603d0028U,"xia_superblock",sxcf_xia_superblock_fields,SX_COUNT(sxcf_xia_superblock_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_xia_inode_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","uint16",4,2,SX_ID),
    SX_FIELD("group_id","uint16",6,2,SX_ID),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("inode_change_time","uint32",12,4,SX_TIME),
    SX_FIELD("access_time","uint32",16,4,SX_TIME),
    SX_FIELD("modification_time","uint32",20,4,SX_TIME),
    SX_FIELD("encoded_zone_numbers","uint32[10]",24,40,SX_FLAGS),
};
static const sx_layout sxcf_xia_inode = {0x603d0029U,"xia_inode",sxcf_xia_inode_fields,SX_COUNT(sxcf_xia_inode_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_xia_directory_header_fields[] = {
    SX_FIELD("inode_number","uint32",0,4,SX_NONE),
    SX_FIELD("record_size","uint16",4,2,SX_SIZE),
    SX_FIELD("name_size","uint8",6,1,SX_SIZE),
};
static const sx_layout sxcf_xia_directory_header = {0x603d002aU,"xia_directory_header",sxcf_xia_directory_header_fields,SX_COUNT(sxcf_xia_directory_header_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_unix_bfs_superblock_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("data_start","uint32",4,4,SX_OFFSET),
    SX_FIELD("data_end","uint32",8,4,SX_OFFSET),
    SX_FIELD("compaction_from","uint32",12,4,SX_NONE),
    SX_FIELD("compaction_to","uint32",16,4,SX_NONE),
    SX_FIELD("backup_from","int32",20,4,SX_NONE),
    SX_FIELD("backup_to","int32",24,4,SX_NONE),
    SX_FIELD("filesystem_name","char[6]",28,6,SX_NONE),
    SX_FIELD("volume_name","char[6]",34,6,SX_NONE),
    SX_FIELD("padding","byte[472]",40,472,SX_RESERVED),
};
static const sx_layout sxcf_unix_bfs_superblock = {0x603d002bU,"unix_bfs_superblock",sxcf_unix_bfs_superblock_fields,SX_COUNT(sxcf_unix_bfs_superblock_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_unix_bfs_inode_fields[] = {
    SX_FIELD("inode_number","uint16",0,2,SX_NONE),
    SX_FIELD("unused","uint16",2,2,SX_RESERVED),
    SX_FIELD("start_block","uint32",4,4,SX_NONE),
    SX_FIELD("end_block","uint32",8,4,SX_NONE),
    SX_FIELD("end_offset","uint32",12,4,SX_OFFSET),
    SX_FIELD("vnode_type","uint32",16,4,SX_ID),
    SX_FIELD("mode","uint32",20,4,SX_FLAGS),
    SX_FIELD("user_id","uint32",24,4,SX_ID),
    SX_FIELD("group_id","uint32",28,4,SX_ID),
    SX_FIELD("link_count","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("access_time","uint32",36,4,SX_TIME),
    SX_FIELD("modification_time","uint32",40,4,SX_TIME),
    SX_FIELD("inode_change_time","uint32",44,4,SX_TIME),
    SX_FIELD("padding","byte[16]",48,16,SX_RESERVED),
};
static const sx_layout sxcf_unix_bfs_inode = {0x603d002cU,"unix_bfs_inode",sxcf_unix_bfs_inode_fields,SX_COUNT(sxcf_unix_bfs_inode_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_qnx4_inode_fields[] = {
    SX_FIELD("name","char[16]",0,16,SX_NONE),
    SX_FIELD("file_size","uint32",16,4,SX_SIZE),
    SX_FIELD("first_extent_block","uint32",20,4,SX_NONE),
    SX_FIELD("first_extent_blocks","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("extent_block","uint32",28,4,SX_NONE),
    SX_FIELD("creation_time","uint32",32,4,SX_TIME),
    SX_FIELD("modification_time","uint32",36,4,SX_TIME),
    SX_FIELD("access_time","uint32",40,4,SX_TIME),
    SX_FIELD("inode_change_time","uint32",44,4,SX_TIME),
    SX_FIELD("extent_count","uint16",48,2,SX_COUNT_PROP),
    SX_FIELD("mode","uint16",50,2,SX_FLAGS),
    SX_FIELD("user_id","uint16",52,2,SX_ID),
    SX_FIELD("group_id","uint16",54,2,SX_ID),
    SX_FIELD("link_count","uint16",56,2,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[4]",58,4,SX_RESERVED),
    SX_FIELD("type","uint8",62,1,SX_ID),
    SX_FIELD("status","uint8",63,1,SX_FLAGS),
};
static const sx_layout sxcf_qnx4_inode = {0x603d002dU,"qnx4_inode",sxcf_qnx4_inode_fields,SX_COUNT(sxcf_qnx4_inode_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_qnx4_link_fields[] = {
    SX_FIELD("name","char[48]",0,48,SX_NONE),
    SX_FIELD("inode_block","uint32",48,4,SX_NONE),
    SX_FIELD("inode_index","uint8",52,1,SX_NONE),
    SX_FIELD("reserved","byte[10]",53,10,SX_RESERVED),
    SX_FIELD("status","uint8",63,1,SX_FLAGS),
};
static const sx_layout sxcf_qnx4_link = {0x603d002eU,"qnx4_link",sxcf_qnx4_link_fields,SX_COUNT(sxcf_qnx4_link_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_qnx4_extent_block_header_fields[] = {
    SX_FIELD("next_block","uint32",0,4,SX_NONE),
    SX_FIELD("previous_block","uint32",4,4,SX_NONE),
    SX_FIELD("extent_count","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[3]",9,3,SX_RESERVED),
    SX_FIELD("block_count","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxcf_qnx4_extent_block_header = {0x603d002fU,"qnx4_extent_block_header",sxcf_qnx4_extent_block_header_fields,SX_COUNT(sxcf_qnx4_extent_block_header_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_qnx4_extent_fields[] = {
    SX_FIELD("first_block","uint32",0,4,SX_NONE),
    SX_FIELD("block_count","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sxcf_qnx4_extent = {0x603d0030U,"qnx4_extent",sxcf_qnx4_extent_fields,SX_COUNT(sxcf_qnx4_extent_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_qnx4_extent_block_tail_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("first_block","uint32",8,4,SX_NONE),
    SX_FIELD("block_count","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sxcf_qnx4_extent_block_tail = {0x603d0031U,"qnx4_extent_block_tail",sxcf_qnx4_extent_block_tail_fields,SX_COUNT(sxcf_qnx4_extent_block_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_efs_superblock_fields[] = {
    SX_FIELD("block_count","int32",0,4,SX_COUNT_PROP),
    SX_FIELD("first_cylinder_group","int32",4,4,SX_NONE),
    SX_FIELD("cylinder_group_blocks","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("inode_blocks_per_group","int16",12,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","int16",14,2,SX_COUNT_PROP),
    SX_FIELD("heads","int16",16,2,SX_COUNT_PROP),
    SX_FIELD("cylinder_group_count","int16",18,2,SX_COUNT_PROP),
    SX_FIELD("dirty","int16",20,2,SX_FLAGS),
    SX_FIELD("padding","int16",22,2,SX_RESERVED),
    SX_FIELD("last_update","int32",24,4,SX_TIME),
    SX_FIELD("magic","uint32",28,4,SX_SIGNATURE),
    SX_FIELD("volume_name","char[6]",32,6,SX_NONE),
    SX_FIELD("pack_name","char[6]",38,6,SX_NONE),
    SX_FIELD("bitmap_size","int32",44,4,SX_SIZE),
    SX_FIELD("free_blocks","int32",48,4,SX_COUNT_PROP),
    SX_FIELD("free_inodes","int32",52,4,SX_COUNT_PROP),
    SX_FIELD("bitmap_block","int32",56,4,SX_NONE),
    SX_FIELD("replicated_superblock","int32",60,4,SX_NONE),
    SX_FIELD("last_allocated_inode","int32",64,4,SX_NONE),
    SX_FIELD("reserved","byte[20]",68,20,SX_RESERVED),
    SX_FIELD("checksum","uint32",88,4,SX_CHECKSUM),
};
static const sx_layout sxcf_efs_superblock = {0x603d0032U,"efs_superblock",sxcf_efs_superblock_fields,SX_COUNT(sxcf_efs_superblock_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_efs_inode_header_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","uint16",4,2,SX_ID),
    SX_FIELD("group_id","uint16",6,2,SX_ID),
    SX_FIELD("file_size","int32",8,4,SX_SIZE),
    SX_FIELD("access_time","int32",12,4,SX_TIME),
    SX_FIELD("modification_time","int32",16,4,SX_TIME),
    SX_FIELD("inode_change_time","int32",20,4,SX_TIME),
    SX_FIELD("generation","uint32",24,4,SX_NONE),
    SX_FIELD("extent_count","int16",28,2,SX_COUNT_PROP),
    SX_FIELD("version","uint8",30,1,SX_ID),
    SX_FIELD("spare","uint8",31,1,SX_RESERVED),
};
static const sx_layout sxcf_efs_inode_header = {0x603d0033U,"efs_inode_header",sxcf_efs_inode_header_fields,SX_COUNT(sxcf_efs_inode_header_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_efs_extent_fields[] = {
    SX_FIELD("magic","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("first_block","uint24",1,3,SX_NONE),
    SX_FIELD("block_count","uint8",4,1,SX_COUNT_PROP),
    SX_FIELD("logical_block","uint24",5,3,SX_NONE),
};
static const sx_layout sxcf_efs_extent = {0x603d0034U,"efs_extent",sxcf_efs_extent_fields,SX_COUNT(sxcf_efs_extent_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_efs_directory_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("first_free_word","uint8",2,1,SX_NONE),
    SX_FIELD("slot_count","uint8",3,1,SX_COUNT_PROP),
};
static const sx_layout sxcf_efs_directory_header = {0x603d0035U,"efs_directory_header",sxcf_efs_directory_header_fields,SX_COUNT(sxcf_efs_directory_header_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_efs_directory_entry_fields[] = {
    SX_FIELD("inode_number","uint32",0,4,SX_NONE),
    SX_FIELD("name_size","uint8",4,1,SX_SIZE),
};
static const sx_layout sxcf_efs_directory_entry = {0x603d0036U,"efs_directory_entry",sxcf_efs_directory_entry_fields,SX_COUNT(sxcf_efs_directory_entry_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_rt11_home_block_fields[] = {
    SX_FIELD("bad_block_table","byte[130]",0,130,SX_NONE),
    SX_FIELD("reserved0","byte[2]",130,2,SX_RESERVED),
    SX_FIELD("initialization_area","byte[38]",132,38,SX_NONE),
    SX_FIELD("backup_information","byte[18]",170,18,SX_NONE),
    SX_FIELD("reserved1","byte[260]",188,260,SX_RESERVED),
    SX_FIELD("reserved_words","byte[4]",448,4,SX_RESERVED),
    SX_FIELD("reserved2","byte[14]",452,14,SX_RESERVED),
    SX_FIELD("cluster_blocks","uint16",466,2,SX_COUNT_PROP),
    SX_FIELD("first_directory_segment","uint16",468,2,SX_NONE),
    SX_FIELD("system_version_rad50","uint16",470,2,SX_NONE),
    SX_FIELD("volume_name","char[12]",472,12,SX_NONE),
    SX_FIELD("owner_name","char[12]",484,12,SX_NONE),
    SX_FIELD("format_identifier","char[12]",496,12,SX_SIGNATURE),
    SX_FIELD("reserved3","uint16",508,2,SX_RESERVED),
    SX_FIELD("checksum","uint16",510,2,SX_CHECKSUM),
};
static const sx_layout sxcf_rt11_home_block = {0x603d0037U,"rt11_home_block",sxcf_rt11_home_block_fields,SX_COUNT(sxcf_rt11_home_block_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_rt11_directory_segment_fields[] = {
    SX_FIELD("total_segments","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("next_segment","uint16",2,2,SX_NONE),
    SX_FIELD("highest_segment","uint16",4,2,SX_NONE),
    SX_FIELD("extra_bytes_per_entry","uint16",6,2,SX_SIZE),
    SX_FIELD("first_data_block","uint16",8,2,SX_NONE),
};
static const sx_layout sxcf_rt11_directory_segment = {0x603d0038U,"rt11_directory_segment",sxcf_rt11_directory_segment_fields,SX_COUNT(sxcf_rt11_directory_segment_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_rt11_directory_entry_fields[] = {
    SX_FIELD("status","uint16",0,2,SX_FLAGS),
    SX_FIELD("filename_rad50_1","uint16",2,2,SX_NONE),
    SX_FIELD("filename_rad50_2","uint16",4,2,SX_NONE),
    SX_FIELD("extension_rad50","uint16",6,2,SX_NONE),
    SX_FIELD("length_blocks","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("job_channel","uint16",10,2,SX_FLAGS),
    SX_FIELD("creation_date_encoded","uint16",12,2,SX_NONE),
};
static const sx_layout sxcf_rt11_directory_entry = {0x603d0039U,"rt11_directory_entry",sxcf_rt11_directory_entry_fields,SX_COUNT(sxcf_rt11_directory_entry_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_hp_lif_volume_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("label","char[6]",2,6,SX_NONE),
    SX_FIELD("directory_block","uint32",8,4,SX_NONE),
    SX_FIELD("lif_identifier","uint16",12,2,SX_ID),
    SX_FIELD("reserved0","uint16",14,2,SX_RESERVED),
    SX_FIELD("directory_blocks","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("version","uint16",20,2,SX_ID),
    SX_FIELD("reserved1","uint16",22,2,SX_RESERVED),
    SX_FIELD("tracks","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("creation_date_bcd","byte[6]",36,6,SX_NONE),
};
static const sx_layout sxcf_hp_lif_volume_header = {0x603d003aU,"hp_lif_volume_header",sxcf_hp_lif_volume_header_fields,SX_COUNT(sxcf_hp_lif_volume_header_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_hp_lif_directory_entry_fields[] = {
    SX_FIELD("name","char[10]",0,10,SX_NONE),
    SX_FIELD("type","uint16",10,2,SX_ID),
    SX_FIELD("first_block","uint32",12,4,SX_NONE),
    SX_FIELD("block_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("creation_date_bcd","byte[6]",20,6,SX_NONE),
    SX_FIELD("volume_number","uint16",26,2,SX_FLAGS),
    SX_FIELD("implementation_defined","uint32",28,4,SX_NONE),
};
static const sx_layout sxcf_hp_lif_directory_entry = {0x603d003bU,"hp_lif_directory_entry",sxcf_hp_lif_directory_entry_fields,SX_COUNT(sxcf_hp_lif_directory_entry_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_ecma67_volume_label_fields[] = {
    SX_FIELD("identifier","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("label_number","uint8",3,1,SX_ID),
    SX_FIELD("volume_identifier","char[6]",4,6,SX_NONE),
    SX_FIELD("accessibility","uint8",10,1,SX_ID),
    SX_FIELD("reserved0","byte[26]",11,26,SX_RESERVED),
    SX_FIELD("owner","char[14]",37,14,SX_NONE),
    SX_FIELD("reserved1","byte[20]",51,20,SX_RESERVED),
    SX_FIELD("surface","uint8",71,1,SX_ID),
    SX_FIELD("reserved2","byte[3]",72,3,SX_RESERVED),
    SX_FIELD("record_length_code","uint8",75,1,SX_ID),
    SX_FIELD("reserved3","byte[2]",76,2,SX_RESERVED),
    SX_FIELD("file_label_allocation","uint8",78,1,SX_ID),
    SX_FIELD("standard_version","uint8",79,1,SX_ID),
    SX_FIELD("reserved4","byte[48]",80,48,SX_RESERVED),
};
static const sx_layout sxcf_ecma67_volume_label = {0x603d003cU,"ecma67_volume_label",sxcf_ecma67_volume_label_fields,SX_COUNT(sxcf_ecma67_volume_label_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_ecma67_error_map_label_fields[] = {
    SX_FIELD("identifier","char[5]",0,5,SX_SIGNATURE),
    SX_FIELD("reserved0","uint8",5,1,SX_RESERVED),
    SX_FIELD("defective_cylinder_1","char[3]",6,3,SX_NONE),
    SX_FIELD("reserved1","uint8",9,1,SX_RESERVED),
    SX_FIELD("defective_cylinder_2","char[3]",10,3,SX_NONE),
    SX_FIELD("reserved2","byte[115]",13,115,SX_RESERVED),
};
static const sx_layout sxcf_ecma67_error_map_label = {0x603d003dU,"ecma67_error_map_label",sxcf_ecma67_error_map_label_fields,SX_COUNT(sxcf_ecma67_error_map_label_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_ecma67_file_label_fields[] = {
    SX_FIELD("identifier","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("label_number","uint8",3,1,SX_ID),
    SX_FIELD("reserved0","uint8",4,1,SX_RESERVED),
    SX_FIELD("filename","char[17]",5,17,SX_NONE),
    SX_FIELD("block_length_decimal","char[5]",22,5,SX_NONE),
    SX_FIELD("reserved1","uint8",27,1,SX_RESERVED),
    SX_FIELD("first_extent_chs","char[5]",28,5,SX_NONE),
    SX_FIELD("reserved2","uint8",33,1,SX_RESERVED),
    SX_FIELD("last_extent_chs","char[5]",34,5,SX_NONE),
    SX_FIELD("record_format","uint8",39,1,SX_ID),
    SX_FIELD("bypass_indicator","uint8",40,1,SX_ID),
    SX_FIELD("accessibility","uint8",41,1,SX_ID),
    SX_FIELD("write_protect","uint8",42,1,SX_ID),
    SX_FIELD("interchange_type","uint8",43,1,SX_ID),
    SX_FIELD("multi_volume","uint8",44,1,SX_ID),
    SX_FIELD("section_number_decimal","char[2]",45,2,SX_NONE),
    SX_FIELD("creation_date","char[6]",47,6,SX_NONE),
    SX_FIELD("record_length_decimal","char[4]",53,4,SX_NONE),
    SX_FIELD("unused_tail_decimal","char[5]",57,5,SX_NONE),
    SX_FIELD("record_attribute","uint8",62,1,SX_ID),
    SX_FIELD("file_organization","uint8",63,1,SX_ID),
    SX_FIELD("reserved3","byte[2]",64,2,SX_RESERVED),
    SX_FIELD("expiration_date","char[6]",66,6,SX_NONE),
    SX_FIELD("verify_copy","uint8",72,1,SX_ID),
    SX_FIELD("reserved4","uint8",73,1,SX_RESERVED),
    SX_FIELD("end_of_data_chs","char[5]",74,5,SX_NONE),
    SX_FIELD("reserved5","byte[49]",79,49,SX_RESERVED),
};
static const sx_layout sxcf_ecma67_file_label = {0x603d003eU,"ecma67_file_label",sxcf_ecma67_file_label_fields,SX_COUNT(sxcf_ecma67_file_label_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_locus_superblock_prefix_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("global_filesystem","int32",4,4,SX_ID),
    SX_FIELD("block_count","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("commit_low_water","int32",12,4,SX_NONE),
    SX_FIELD("commit_high_water","int32",16,4,SX_NONE),
    SX_FIELD("oldest_commit","int32",20,4,SX_NONE),
    SX_FIELD("storage_mask","int32",24,4,SX_FLAGS),
    SX_FIELD("last_update","int32",28,4,SX_TIME),
    SX_FIELD("free_block_count","int32",32,4,SX_COUNT_PROP),
    SX_FIELD("inode_table_blocks","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("free_block_cache_count","int16",40,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint16",42,2,SX_FLAGS),
    SX_FIELD("free_inode_count","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("last_inode_search","int32",48,4,SX_NONE),
    SX_FIELD("estimated_prior_free_inodes","int32",52,4,SX_COUNT_PROP),
    SX_FIELD("pack_number","int16",56,2,SX_NONE),
    SX_FIELD("free_inode_cache_count","int16",58,2,SX_COUNT_PROP),
    SX_FIELD("device_information","int16[4]",60,8,SX_NONE),
    SX_FIELD("block_lock","uint8",68,1,SX_FLAGS),
    SX_FIELD("inode_lock","uint8",69,1,SX_FLAGS),
    SX_FIELD("modified","uint8",70,1,SX_FLAGS),
    SX_FIELD("version","uint8",71,1,SX_ID),
    SX_FIELD("mount_name","char[32]",72,32,SX_NONE),
    SX_FIELD("pack_name","char[8]",104,8,SX_NONE),
};
static const sx_layout sxcf_locus_superblock_prefix_le = {0x603d003fU,"locus_superblock_prefix_le",sxcf_locus_superblock_prefix_le_fields,SX_COUNT(sxcf_locus_superblock_prefix_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_locus_superblock_prefix_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("global_filesystem","int32",4,4,SX_ID),
    SX_FIELD("block_count","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("commit_low_water","int32",12,4,SX_NONE),
    SX_FIELD("commit_high_water","int32",16,4,SX_NONE),
    SX_FIELD("oldest_commit","int32",20,4,SX_NONE),
    SX_FIELD("storage_mask","int32",24,4,SX_FLAGS),
    SX_FIELD("last_update","int32",28,4,SX_TIME),
    SX_FIELD("free_block_count","int32",32,4,SX_COUNT_PROP),
    SX_FIELD("inode_table_blocks","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("free_block_cache_count","int16",40,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint16",42,2,SX_FLAGS),
    SX_FIELD("free_inode_count","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("last_inode_search","int32",48,4,SX_NONE),
    SX_FIELD("estimated_prior_free_inodes","int32",52,4,SX_COUNT_PROP),
    SX_FIELD("pack_number","int16",56,2,SX_NONE),
    SX_FIELD("free_inode_cache_count","int16",58,2,SX_COUNT_PROP),
    SX_FIELD("device_information","int16[4]",60,8,SX_NONE),
    SX_FIELD("block_lock","uint8",68,1,SX_FLAGS),
    SX_FIELD("inode_lock","uint8",69,1,SX_FLAGS),
    SX_FIELD("modified","uint8",70,1,SX_FLAGS),
    SX_FIELD("version","uint8",71,1,SX_ID),
    SX_FIELD("mount_name","char[32]",72,32,SX_NONE),
    SX_FIELD("pack_name","char[8]",104,8,SX_NONE),
};
static const sx_layout sxcf_locus_superblock_prefix_be = {0x603d0040U,"locus_superblock_prefix_be",sxcf_locus_superblock_prefix_be_fields,SX_COUNT(sxcf_locus_superblock_prefix_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_locus_inode_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","int16",4,2,SX_ID),
    SX_FIELD("group_id","int16",6,2,SX_ID),
    SX_FIELD("unique_identifier","int32",8,4,SX_ID),
    SX_FIELD("reserved0","int16",12,2,SX_RESERVED),
    SX_FIELD("flags","uint16",14,2,SX_FLAGS),
    SX_FIELD("file_size","int32",16,4,SX_SIZE),
    SX_FIELD("modification_time","int32",20,4,SX_TIME),
    SX_FIELD("access_time","int32",24,4,SX_TIME),
    SX_FIELD("inode_change_time","int32",28,4,SX_TIME),
    SX_FIELD("commit_count","int32",32,4,SX_NONE),
    SX_FIELD("storage_mask","int32",36,4,SX_FLAGS),
    SX_FIELD("version","int32",40,4,SX_NONE),
    SX_FIELD("allocated_blocks","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("reserved1","byte[28]",48,28,SX_RESERVED),
    SX_FIELD("block_numbers","int32[13]",76,52,SX_NONE),
};
static const sx_layout sxcf_locus_inode_le = {0x603d0041U,"locus_inode_le",sxcf_locus_inode_le_fields,SX_COUNT(sxcf_locus_inode_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_locus_inode_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","int16",4,2,SX_ID),
    SX_FIELD("group_id","int16",6,2,SX_ID),
    SX_FIELD("unique_identifier","int32",8,4,SX_ID),
    SX_FIELD("reserved0","int16",12,2,SX_RESERVED),
    SX_FIELD("flags","uint16",14,2,SX_FLAGS),
    SX_FIELD("file_size","int32",16,4,SX_SIZE),
    SX_FIELD("modification_time","int32",20,4,SX_TIME),
    SX_FIELD("access_time","int32",24,4,SX_TIME),
    SX_FIELD("inode_change_time","int32",28,4,SX_TIME),
    SX_FIELD("commit_count","int32",32,4,SX_NONE),
    SX_FIELD("storage_mask","int32",36,4,SX_FLAGS),
    SX_FIELD("version","int32",40,4,SX_NONE),
    SX_FIELD("allocated_blocks","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("reserved1","byte[28]",48,28,SX_RESERVED),
    SX_FIELD("block_numbers","int32[13]",76,52,SX_NONE),
};
static const sx_layout sxcf_locus_inode_be = {0x603d0042U,"locus_inode_be",sxcf_locus_inode_be_fields,SX_COUNT(sxcf_locus_inode_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_locus_inode_small_le_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","int16",4,2,SX_ID),
    SX_FIELD("group_id","int16",6,2,SX_ID),
    SX_FIELD("unique_identifier","int32",8,4,SX_ID),
    SX_FIELD("reserved0","int16",12,2,SX_RESERVED),
    SX_FIELD("flags","uint16",14,2,SX_FLAGS),
    SX_FIELD("file_size","int32",16,4,SX_SIZE),
    SX_FIELD("modification_time","int32",20,4,SX_TIME),
    SX_FIELD("access_time","int32",24,4,SX_TIME),
    SX_FIELD("inode_change_time","int32",28,4,SX_TIME),
    SX_FIELD("commit_count","int32",32,4,SX_NONE),
    SX_FIELD("storage_mask","int32",36,4,SX_FLAGS),
    SX_FIELD("version","int32",40,4,SX_NONE),
    SX_FIELD("allocated_blocks","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("reserved1","byte[27]",48,27,SX_RESERVED),
    SX_FIELD("small_block_flags","uint8",75,1,SX_FLAGS),
    SX_FIELD("block_numbers","int32[13]",76,52,SX_NONE),
};
static const sx_layout sxcf_locus_inode_small_le = {0x603d0043U,"locus_inode_small_le",sxcf_locus_inode_small_le_fields,SX_COUNT(sxcf_locus_inode_small_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_locus_inode_small_be_fields[] = {
    SX_FIELD("mode","uint16",0,2,SX_FLAGS),
    SX_FIELD("link_count","int16",2,2,SX_COUNT_PROP),
    SX_FIELD("user_id","int16",4,2,SX_ID),
    SX_FIELD("group_id","int16",6,2,SX_ID),
    SX_FIELD("unique_identifier","int32",8,4,SX_ID),
    SX_FIELD("reserved0","int16",12,2,SX_RESERVED),
    SX_FIELD("flags","uint16",14,2,SX_FLAGS),
    SX_FIELD("file_size","int32",16,4,SX_SIZE),
    SX_FIELD("modification_time","int32",20,4,SX_TIME),
    SX_FIELD("access_time","int32",24,4,SX_TIME),
    SX_FIELD("inode_change_time","int32",28,4,SX_TIME),
    SX_FIELD("commit_count","int32",32,4,SX_NONE),
    SX_FIELD("storage_mask","int32",36,4,SX_FLAGS),
    SX_FIELD("version","int32",40,4,SX_NONE),
    SX_FIELD("allocated_blocks","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("reserved1","byte[27]",48,27,SX_RESERVED),
    SX_FIELD("small_block_flags","uint8",75,1,SX_FLAGS),
    SX_FIELD("block_numbers","int32[13]",76,52,SX_NONE),
};
static const sx_layout sxcf_locus_inode_small_be = {0x603d0044U,"locus_inode_small_be",sxcf_locus_inode_small_be_fields,SX_COUNT(sxcf_locus_inode_small_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_locus_directory_header_le_fields[] = {
    SX_FIELD("inode_number","int32",0,4,SX_NONE),
    SX_FIELD("record_size","uint16",4,2,SX_SIZE),
    SX_FIELD("name_size","uint16",6,2,SX_SIZE),
};
static const sx_layout sxcf_locus_directory_header_le = {0x603d0045U,"locus_directory_header_le",sxcf_locus_directory_header_le_fields,SX_COUNT(sxcf_locus_directory_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_locus_directory_header_be_fields[] = {
    SX_FIELD("inode_number","int32",0,4,SX_NONE),
    SX_FIELD("record_size","uint16",4,2,SX_SIZE),
    SX_FIELD("name_size","uint16",6,2,SX_SIZE),
};
static const sx_layout sxcf_locus_directory_header_be = {0x603d0046U,"locus_directory_header_be",sxcf_locus_directory_header_be_fields,SX_COUNT(sxcf_locus_directory_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_pfs_root_block_fields[] = {
    SX_FIELD("disk_type","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("options","uint32",4,4,SX_FLAGS),
    SX_FIELD("datestamp","uint32",8,4,SX_NONE),
    SX_FIELD("creation_day","uint16",12,2,SX_NONE),
    SX_FIELD("creation_minute","uint16",14,2,SX_NONE),
    SX_FIELD("creation_tick","uint16",16,2,SX_NONE),
    SX_FIELD("protection","uint16",18,2,SX_FLAGS),
    SX_FIELD("name_size","uint8",20,1,SX_SIZE),
    SX_FIELD("name","char[31]",21,31,SX_NONE),
    SX_FIELD("last_reserved_block","uint32",52,4,SX_NONE),
    SX_FIELD("first_reserved_block","uint32",56,4,SX_NONE),
    SX_FIELD("free_reserved_blocks","uint32",60,4,SX_COUNT_PROP),
    SX_FIELD("reserved_block_size","uint16",64,2,SX_SIZE),
    SX_FIELD("root_block_sectors","uint16",66,2,SX_COUNT_PROP),
    SX_FIELD("free_blocks","uint32",68,4,SX_COUNT_PROP),
    SX_FIELD("minimum_free_blocks","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("allocation_word","uint32",76,4,SX_NONE),
    SX_FIELD("deleted_directory_block","uint32",80,4,SX_NONE),
    SX_FIELD("sector_count","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("extension_block","uint32",88,4,SX_NONE),
    SX_FIELD("unused","uint32",92,4,SX_RESERVED),
};
static const sx_layout sxcf_pfs_root_block = {0x603d0047U,"pfs_root_block",sxcf_pfs_root_block_fields,SX_COUNT(sxcf_pfs_root_block_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_pfs_root_small_indexes_fields[] = {
    SX_FIELD("bitmap_index_blocks","uint32[5]",0,20,SX_NONE),
    SX_FIELD("anode_index_blocks","uint32[99]",20,396,SX_NONE),
};
static const sx_layout sxcf_pfs_root_small_indexes = {0x603d0048U,"pfs_root_small_indexes",sxcf_pfs_root_small_indexes_fields,SX_COUNT(sxcf_pfs_root_small_indexes_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_pfs_root_large_indexes_fields[] = {
    SX_FIELD("bitmap_index_blocks","uint32[104]",0,416,SX_NONE),
};
static const sx_layout sxcf_pfs_root_large_indexes = {0x603d0049U,"pfs_root_large_indexes",sxcf_pfs_root_large_indexes_fields,SX_COUNT(sxcf_pfs_root_large_indexes_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_pfs_index_header_fields[] = {
    SX_FIELD("identifier","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("reserved","uint16",2,2,SX_RESERVED),
    SX_FIELD("datestamp","uint32",4,4,SX_NONE),
    SX_FIELD("sequence_number","uint32",8,4,SX_NONE),
};
static const sx_layout sxcf_pfs_index_header = {0x603d004aU,"pfs_index_header",sxcf_pfs_index_header_fields,SX_COUNT(sxcf_pfs_index_header_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_pfs_anode_header_fields[] = {
    SX_FIELD("identifier","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("reserved0","uint16",2,2,SX_RESERVED),
    SX_FIELD("datestamp","uint32",4,4,SX_NONE),
    SX_FIELD("sequence_number","uint32",8,4,SX_NONE),
    SX_FIELD("reserved1","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxcf_pfs_anode_header = {0x603d004bU,"pfs_anode_header",sxcf_pfs_anode_header_fields,SX_COUNT(sxcf_pfs_anode_header_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_pfs_anode_fields[] = {
    SX_FIELD("sector_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("first_sector","uint32",4,4,SX_NONE),
    SX_FIELD("next_anode","uint32",8,4,SX_NONE),
};
static const sx_layout sxcf_pfs_anode = {0x603d004cU,"pfs_anode",sxcf_pfs_anode_fields,SX_COUNT(sxcf_pfs_anode_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_pfs_directory_header_fields[] = {
    SX_FIELD("identifier","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("reserved0","uint16",2,2,SX_RESERVED),
    SX_FIELD("datestamp","uint32",4,4,SX_NONE),
    SX_FIELD("reserved1","byte[4]",8,4,SX_RESERVED),
    SX_FIELD("anode_number","uint32",12,4,SX_NONE),
    SX_FIELD("parent_anode","uint32",16,4,SX_NONE),
};
static const sx_layout sxcf_pfs_directory_header = {0x603d004dU,"pfs_directory_header",sxcf_pfs_directory_header_fields,SX_COUNT(sxcf_pfs_directory_header_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_pfs_directory_entry_fields[] = {
    SX_FIELD("record_size","uint8",0,1,SX_SIZE),
    SX_FIELD("type","int8",1,1,SX_ID),
    SX_FIELD("anode_number","uint32",2,4,SX_NONE),
    SX_FIELD("file_size_low","uint32",6,4,SX_NONE),
    SX_FIELD("creation_day","uint16",10,2,SX_NONE),
    SX_FIELD("creation_minute","uint16",12,2,SX_NONE),
    SX_FIELD("creation_tick","uint16",14,2,SX_NONE),
    SX_FIELD("protection","uint8",16,1,SX_FLAGS),
    SX_FIELD("name_size","uint8",17,1,SX_SIZE),
};
static const sx_layout sxcf_pfs_directory_entry = {0x603d004eU,"pfs_directory_entry",sxcf_pfs_directory_entry_fields,SX_COUNT(sxcf_pfs_directory_entry_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_pfs_extension_fields[] = {
    SX_FIELD("identifier","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("reserved0","uint16",2,2,SX_RESERVED),
    SX_FIELD("options","uint32",4,4,SX_FLAGS),
    SX_FIELD("datestamp","uint32",8,4,SX_NONE),
    SX_FIELD("version","uint32",12,4,SX_ID),
    SX_FIELD("root_date_components","uint16[3]",16,6,SX_NONE),
    SX_FIELD("volume_date_components","uint16[3]",22,6,SX_NONE),
    SX_FIELD("postponed_operation","uint32",28,4,SX_ID),
    SX_FIELD("postponed_arguments","uint32[3]",32,12,SX_NONE),
    SX_FIELD("reserved_allocation_cursor","uint32",44,4,SX_NONE),
    SX_FIELD("allocation_bit","uint16",48,2,SX_NONE),
    SX_FIELD("current_anode_sequence","uint16",50,2,SX_NONE),
    SX_FIELD("deleted_directory_cursor","uint16",52,2,SX_NONE),
    SX_FIELD("deleted_directory_size","uint16",54,2,SX_COUNT_PROP),
    SX_FIELD("filename_size","uint16",56,2,SX_SIZE),
    SX_FIELD("reserved1","byte[6]",58,6,SX_RESERVED),
    SX_FIELD("super_indexes","uint32[16]",64,64,SX_NONE),
    SX_FIELD("deleted_user_id","uint16",128,2,SX_ID),
    SX_FIELD("deleted_group_id","uint16",130,2,SX_ID),
    SX_FIELD("deleted_protection","uint32",132,4,SX_FLAGS),
    SX_FIELD("deleted_creation_date","uint16[3]",136,6,SX_NONE),
    SX_FIELD("reserved2","uint16",142,2,SX_RESERVED),
    SX_FIELD("deleted_directory_blocks","uint32[32]",144,128,SX_NONE),
};
static const sx_layout sxcf_pfs_extension = {0x603d004fU,"pfs_extension",sxcf_pfs_extension_fields,SX_COUNT(sxcf_pfs_extension_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_hpofs_boot_sector_fields[] = {
    SX_FIELD("jump","byte[3]",0,3,SX_NONE),
    SX_FIELD("oem_name","char[8]",3,8,SX_NONE),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
    SX_FIELD("sectors_per_allocation_unit","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sectors","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",16,1,SX_COUNT_PROP),
    SX_FIELD("root_entry_compatibility","uint16",17,2,SX_NONE),
    SX_FIELD("sector_count_16","uint16",19,2,SX_COUNT_PROP),
    SX_FIELD("media_descriptor","uint8",21,1,SX_ID),
    SX_FIELD("sectors_per_fat","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sectors","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("sector_count_32","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("drive_number","uint8",36,1,SX_ID),
    SX_FIELD("reserved0","uint8",37,1,SX_RESERVED),
    SX_FIELD("extended_signature","uint8",38,1,SX_SIGNATURE),
    SX_FIELD("serial_number","uint32",39,4,SX_ID),
    SX_FIELD("volume_label","char[11]",43,11,SX_NONE),
    SX_FIELD("filesystem_identifier","char[8]",54,8,SX_SIGNATURE),
    SX_FIELD("boot_code","byte[442]",62,442,SX_NONE),
    SX_FIELD("marker","uint16",504,2,SX_SIGNATURE),
    SX_FIELD("reserved1","uint16",506,2,SX_RESERVED),
    SX_FIELD("version","uint16",508,2,SX_ID),
    SX_FIELD("boot_signature","uint16",510,2,SX_SIGNATURE),
};
static const sx_layout sxcf_hpofs_boot_sector = {0x603d0050U,"hpofs_boot_sector",sxcf_hpofs_boot_sector_fields,SX_COUNT(sxcf_hpofs_boot_sector_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_hpofs_media_information_fields[] = {
    SX_FIELD("identifier","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("volume_label","char[32]",8,32,SX_NONE),
    SX_FIELD("comment_codepage_data","byte[160]",40,160,SX_NONE),
    SX_FIELD("serial_number","uint32",200,4,SX_ID),
    SX_FIELD("format_major","uint16",204,2,SX_ID),
    SX_FIELD("format_minor","uint16",206,2,SX_ID),
    SX_FIELD("codepage_type","uint16",208,2,SX_ID),
    SX_FIELD("codepage","uint16",210,2,SX_ID),
    SX_FIELD("sector_count","uint32",212,4,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector","uint16",216,2,SX_SIZE),
    SX_FIELD("bytes_per_sector_copy","uint16",218,2,SX_SIZE),
    SX_FIELD("reserved0","uint32",220,4,SX_RESERVED),
    SX_FIELD("sectors_per_band","uint32",224,4,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector_32","uint32",228,4,SX_SIZE),
    SX_FIELD("opaque_e8","byte[8]",232,8,SX_NONE),
    SX_FIELD("revision_high","uint16",240,2,SX_NONE),
    SX_FIELD("revision_low","uint16",242,2,SX_NONE),
    SX_FIELD("opaque_f4","byte[8]",244,8,SX_NONE),
};
static const sx_layout sxcf_hpofs_media_information = {0x603d0051U,"hpofs_media_information",sxcf_hpofs_media_information_fields,SX_COUNT(sxcf_hpofs_media_information_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_hpofs_subfile_header_fields[] = {
    SX_FIELD("identifier","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("opaque_04","byte[12]",4,12,SX_NONE),
    SX_FIELD("extent_count","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("opaque_12","byte[14]",18,14,SX_NONE),
};
static const sx_layout sxcf_hpofs_subfile_header = {0x603d0052U,"hpofs_subfile_header",sxcf_hpofs_subfile_header_fields,SX_COUNT(sxcf_hpofs_subfile_header_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_hpofs_extent_fields[] = {
    SX_FIELD("sector_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("opaque_02","uint16",2,2,SX_NONE),
    SX_FIELD("first_sector","uint32",4,4,SX_NONE),
};
static const sx_layout sxcf_hpofs_extent = {0x603d0053U,"hpofs_extent",sxcf_hpofs_extent_fields,SX_COUNT(sxcf_hpofs_extent_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_hpofs_directory_node_fields[] = {
    SX_FIELD("identifier","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("opaque_04","byte[16]",4,16,SX_NONE),
    SX_FIELD("level","uint16",20,2,SX_NONE),
    SX_FIELD("codepage_type","uint16",22,2,SX_ID),
    SX_FIELD("separator","uint16",24,2,SX_NONE),
    SX_FIELD("reserved0","uint16",26,2,SX_RESERVED),
    SX_FIELD("opaque_1c","byte[8]",28,8,SX_NONE),
};
static const sx_layout sxcf_hpofs_directory_node = {0x603d0054U,"hpofs_directory_node",sxcf_hpofs_directory_node_fields,SX_COUNT(sxcf_hpofs_directory_node_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_hpofs_directory_record_prefix_fields[] = {
    SX_FIELD("key_size","uint16",0,2,SX_SIZE),
    SX_FIELD("record_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxcf_hpofs_directory_record_prefix = {0x603d0055U,"hpofs_directory_record_prefix",sxcf_hpofs_directory_record_prefix_fields,SX_COUNT(sxcf_hpofs_directory_record_prefix_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_hpofs_directory_record_fields[] = {
    SX_FIELD("record_identifier","uint32",0,4,SX_ID),
    SX_FIELD("record_identifier_copy","uint32",4,4,SX_ID),
    SX_FIELD("opaque_08","byte[4]",8,4,SX_NONE),
    SX_FIELD("record_type","uint8",12,1,SX_ID),
    SX_FIELD("opaque_0d","uint8",13,1,SX_NONE),
    SX_FIELD("attributes","uint8",14,1,SX_FLAGS),
    SX_FIELD("opaque_0f","byte[49]",15,49,SX_NONE),
    SX_FIELD("inline_extent_sectors","uint16",64,2,SX_COUNT_PROP),
    SX_FIELD("opaque_42","uint16",66,2,SX_NONE),
    SX_FIELD("inline_extent_first_sector","uint32",68,4,SX_NONE),
    SX_FIELD("opaque_48","byte[4]",72,4,SX_NONE),
    SX_FIELD("extent_list_sector","uint32",76,4,SX_NONE),
    SX_FIELD("opaque_50","byte[8]",80,8,SX_NONE),
    SX_FIELD("file_size","uint32",88,4,SX_SIZE),
};
static const sx_layout sxcf_hpofs_directory_record = {0x603d0056U,"hpofs_directory_record",sxcf_hpofs_directory_record_fields,SX_COUNT(sxcf_hpofs_directory_record_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_ods_home_block_fields[] = {
    SX_FIELD("home_lbn","uint32",0,4,SX_NONE),
    SX_FIELD("alternate_home_lbn","uint32",4,4,SX_NONE),
    SX_FIELD("alternate_index_lbn","uint32",8,4,SX_NONE),
    SX_FIELD("structure_level","uint16",12,2,SX_ID),
    SX_FIELD("cluster_blocks","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("home_vbn","uint16",16,2,SX_NONE),
    SX_FIELD("alternate_home_vbn","uint16",18,2,SX_NONE),
    SX_FIELD("alternate_index_vbn","uint16",20,2,SX_NONE),
    SX_FIELD("index_bitmap_vbn","uint16",22,2,SX_NONE),
    SX_FIELD("index_bitmap_lbn","uint32",24,4,SX_NONE),
    SX_FIELD("maximum_files","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("index_bitmap_blocks","uint16",32,2,SX_COUNT_PROP),
    SX_FIELD("reserved_files","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("device_type","uint16",36,2,SX_ID),
    SX_FIELD("relative_volume","uint16",38,2,SX_NONE),
    SX_FIELD("volume_count","uint16",40,2,SX_COUNT_PROP),
    SX_FIELD("characteristics","uint16",42,2,SX_FLAGS),
    SX_FIELD("owner_uic","uint32",44,4,SX_ID),
    SX_FIELD("security_mask","uint32",48,4,SX_FLAGS),
    SX_FIELD("protection","uint16",52,2,SX_FLAGS),
    SX_FIELD("default_file_protection","uint16",54,2,SX_FLAGS),
    SX_FIELD("default_record_protection","uint16",56,2,SX_FLAGS),
    SX_FIELD("checksum1","uint16",58,2,SX_CHECKSUM),
    SX_FIELD("creation_time","uint64",60,8,SX_TIME),
    SX_FIELD("window_size","uint8",68,1,SX_COUNT_PROP),
    SX_FIELD("directory_cache_limit","uint8",69,1,SX_COUNT_PROP),
    SX_FIELD("default_allocation_blocks","uint16",70,2,SX_COUNT_PROP),
    SX_FIELD("minimum_retention","uint64",72,8,SX_NONE),
    SX_FIELD("maximum_retention","uint64",80,8,SX_NONE),
    SX_FIELD("revision_time","uint64",88,8,SX_TIME),
    SX_FIELD("minimum_security_class","byte[20]",96,20,SX_NONE),
    SX_FIELD("maximum_security_class","byte[20]",116,20,SX_NONE),
    SX_FIELD("file_lookup_number","uint16",136,2,SX_NONE),
    SX_FIELD("file_lookup_sequence","uint16",138,2,SX_NONE),
    SX_FIELD("file_lookup_relative_volume","uint8",140,1,SX_NONE),
    SX_FIELD("file_lookup_number_high","uint8",141,1,SX_NONE),
    SX_FIELD("lowest_structure_level","uint16",142,2,SX_ID),
    SX_FIELD("highest_structure_level","uint16",144,2,SX_ID),
    SX_FIELD("copy_time","uint64",146,8,SX_TIME),
    SX_FIELD("reserved0","byte[302]",154,302,SX_RESERVED),
    SX_FIELD("serial_number","uint32",456,4,SX_ID),
    SX_FIELD("volume_set_name","char[12]",460,12,SX_NONE),
    SX_FIELD("volume_name","char[12]",472,12,SX_NONE),
    SX_FIELD("owner_name","char[12]",484,12,SX_NONE),
    SX_FIELD("format_identifier","char[12]",496,12,SX_SIGNATURE),
    SX_FIELD("reserved1","uint16",508,2,SX_RESERVED),
    SX_FIELD("checksum2","uint16",510,2,SX_CHECKSUM),
};
static const sx_layout sxcf_ods_home_block = {0x603d0057U,"ods_home_block",sxcf_ods_home_block_fields,SX_COUNT(sxcf_ods_home_block_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_ods_file_header_fields[] = {
    SX_FIELD("identification_word_offset","uint8",0,1,SX_NONE),
    SX_FIELD("map_word_offset","uint8",1,1,SX_NONE),
    SX_FIELD("access_control_word_offset","uint8",2,1,SX_NONE),
    SX_FIELD("reserved_word_offset","uint8",3,1,SX_NONE),
    SX_FIELD("segment_number","uint16",4,2,SX_NONE),
    SX_FIELD("structure_level","uint16",6,2,SX_ID),
    SX_FIELD("file_number_low","uint16",8,2,SX_NONE),
    SX_FIELD("file_sequence","uint16",10,2,SX_NONE),
    SX_FIELD("file_relative_volume","uint8",12,1,SX_NONE),
    SX_FIELD("file_number_high","uint8",13,1,SX_NONE),
    SX_FIELD("extension_number_low","uint16",14,2,SX_NONE),
    SX_FIELD("extension_sequence","uint16",16,2,SX_NONE),
    SX_FIELD("extension_relative_volume","uint8",18,1,SX_NONE),
    SX_FIELD("extension_number_high","uint8",19,1,SX_NONE),
    SX_FIELD("record_type_organization","uint8",20,1,SX_FLAGS),
    SX_FIELD("record_attributes","uint8",21,1,SX_FLAGS),
    SX_FIELD("record_size","uint16",22,2,SX_SIZE),
    SX_FIELD("allocated_block_high","uint16",24,2,SX_NONE),
    SX_FIELD("allocated_block_low","uint16",26,2,SX_NONE),
    SX_FIELD("eof_block_high","uint16",28,2,SX_NONE),
    SX_FIELD("eof_block_low","uint16",30,2,SX_NONE),
    SX_FIELD("first_free_byte","uint16",32,2,SX_OFFSET),
    SX_FIELD("bucket_blocks","uint8",34,1,SX_COUNT_PROP),
    SX_FIELD("fixed_control_size","uint8",35,1,SX_SIZE),
    SX_FIELD("maximum_record_size","uint16",36,2,SX_SIZE),
    SX_FIELD("default_extend_blocks","uint16",38,2,SX_COUNT_PROP),
    SX_FIELD("global_buffer_count_16","uint16",40,2,SX_COUNT_PROP),
    SX_FIELD("record_attribute_flags","uint8",42,1,SX_FLAGS),
    SX_FIELD("reserved0","uint8",43,1,SX_RESERVED),
    SX_FIELD("global_buffer_count_32","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("reserved1","uint16",48,2,SX_RESERVED),
    SX_FIELD("version_limit","uint16",50,2,SX_COUNT_PROP),
    SX_FIELD("characteristics","uint32",52,4,SX_FLAGS),
    SX_FIELD("record_protection","uint16",56,2,SX_FLAGS),
    SX_FIELD("mapping_words","uint8",58,1,SX_COUNT_PROP),
    SX_FIELD("access_mode","uint8",59,1,SX_ID),
    SX_FIELD("owner_member","uint16",60,2,SX_ID),
    SX_FIELD("owner_group","uint16",62,2,SX_ID),
    SX_FIELD("protection","uint16",64,2,SX_FLAGS),
    SX_FIELD("backlink_number_low","uint16",66,2,SX_NONE),
    SX_FIELD("backlink_sequence","uint16",68,2,SX_NONE),
    SX_FIELD("backlink_relative_volume","uint8",70,1,SX_NONE),
    SX_FIELD("backlink_number_high","uint8",71,1,SX_NONE),
    SX_FIELD("journal_flags","uint8",72,1,SX_FLAGS),
    SX_FIELD("recovery_unit_active","uint8",73,1,SX_FLAGS),
    SX_FIELD("link_count","uint16",74,2,SX_COUNT_PROP),
    SX_FIELD("highwater_block","uint32",76,4,SX_NONE),
};
static const sx_layout sxcf_ods_file_header = {0x603d0058U,"ods_file_header",sxcf_ods_file_header_fields,SX_COUNT(sxcf_ods_file_header_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_ods_file_checksum_fields[] = {
    SX_FIELD("checksum","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxcf_ods_file_checksum = {0x603d0059U,"ods_file_checksum",sxcf_ods_file_checksum_fields,SX_COUNT(sxcf_ods_file_checksum_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_ods_retrieval_pointer0_fields[] = {
    SX_FIELD("placement_word","uint16",0,2,SX_FLAGS),
};
static const sx_layout sxcf_ods_retrieval_pointer0 = {0x603d005aU,"ods_retrieval_pointer0",sxcf_ods_retrieval_pointer0_fields,SX_COUNT(sxcf_ods_retrieval_pointer0_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_ods_retrieval_pointer1_fields[] = {
    SX_FIELD("blocks_minus_one","uint8",0,1,SX_NONE),
    SX_FIELD("format_and_lbn_high","uint8",1,1,SX_FLAGS),
    SX_FIELD("lbn_low","uint16",2,2,SX_NONE),
};
static const sx_layout sxcf_ods_retrieval_pointer1 = {0x603d005bU,"ods_retrieval_pointer1",sxcf_ods_retrieval_pointer1_fields,SX_COUNT(sxcf_ods_retrieval_pointer1_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_ods_retrieval_pointer2_fields[] = {
    SX_FIELD("format_and_blocks_minus_one","uint16",0,2,SX_FLAGS),
    SX_FIELD("first_lbn","uint32",2,4,SX_NONE),
};
static const sx_layout sxcf_ods_retrieval_pointer2 = {0x603d005cU,"ods_retrieval_pointer2",sxcf_ods_retrieval_pointer2_fields,SX_COUNT(sxcf_ods_retrieval_pointer2_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_ods_retrieval_pointer3_fields[] = {
    SX_FIELD("format_and_count_high","uint16",0,2,SX_FLAGS),
    SX_FIELD("count_low","uint16",2,2,SX_NONE),
    SX_FIELD("first_lbn","uint32",4,4,SX_NONE),
};
static const sx_layout sxcf_ods_retrieval_pointer3 = {0x603d005dU,"ods_retrieval_pointer3",sxcf_ods_retrieval_pointer3_fields,SX_COUNT(sxcf_ods_retrieval_pointer3_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_ods_directory_header_fields[] = {
    SX_FIELD("following_record_size","uint16",0,2,SX_SIZE),
    SX_FIELD("version_limit","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("flags_and_name_encoding","uint8",4,1,SX_FLAGS),
    SX_FIELD("name_size","uint8",5,1,SX_SIZE),
};
static const sx_layout sxcf_ods_directory_header = {0x603d005eU,"ods_directory_header",sxcf_ods_directory_header_fields,SX_COUNT(sxcf_ods_directory_header_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_ods_directory_version_fields[] = {
    SX_FIELD("version","uint16",0,2,SX_NONE),
    SX_FIELD("file_number_low","uint16",2,2,SX_NONE),
    SX_FIELD("file_sequence","uint16",4,2,SX_NONE),
    SX_FIELD("relative_volume","uint8",6,1,SX_NONE),
    SX_FIELD("file_number_high","uint8",7,1,SX_NONE),
};
static const sx_layout sxcf_ods_directory_version = {0x603d005fU,"ods_directory_version",sxcf_ods_directory_version_fields,SX_COUNT(sxcf_ods_directory_version_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_unicos_superblock_prefix_fields[] = {
    SX_FIELD("magic","uint64",0,8,SX_SIGNATURE),
    SX_FIELD("filesystem_name","char[8]",8,8,SX_NONE),
    SX_FIELD("pack_name","char[8]",16,8,SX_NONE),
    SX_FIELD("device","int64",24,8,SX_ID),
    SX_FIELD("block_count","int64",32,8,SX_COUNT_PROP),
    SX_FIELD("inode_count","int64",40,8,SX_COUNT_PROP),
    SX_FIELD("big_file_threshold","int64",48,8,SX_SIZE),
    SX_FIELD("big_file_minimum_blocks","int64",56,8,SX_COUNT_PROP),
    SX_FIELD("secure_label","uint64",64,8,SX_SIGNATURE),
    SX_FIELD("maximum_security_level","int64",72,8,SX_NONE),
    SX_FIELD("minimum_security_level","int64",80,8,SX_NONE),
    SX_FIELD("valid_security_compartments","int64",88,8,SX_FLAGS),
    SX_FIELD("last_update","int64",96,8,SX_TIME),
    SX_FIELD("dynamic_block","int64",104,8,SX_NONE),
    SX_FIELD("root_inode","int64",112,8,SX_NONE),
    SX_FIELD("filesystem_error","int64",120,8,SX_ID),
    SX_FIELD("first_map_block","int64",128,8,SX_NONE),
    SX_FIELD("last_map_block","int64",136,8,SX_NONE),
    SX_FIELD("superblock_copies","int64",144,8,SX_COUNT_PROP),
    SX_FIELD("partition_count","int64",152,8,SX_COUNT_PROP),
    SX_FIELD("inode_block_ratio","int64",160,8,SX_NONE),
    SX_FIELD("shared_filesystem_extent","int64",168,8,SX_NONE),
    SX_FIELD("flags","int64",176,8,SX_FLAGS),
};
static const sx_layout sxcf_unicos_superblock_prefix = {0x603d0060U,"unicos_superblock_prefix",sxcf_unicos_superblock_prefix_fields,SX_COUNT(sxcf_unicos_superblock_prefix_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_unicos_partition_fields[] = {
    SX_FIELD("device_name","int64",0,8,SX_ID),
    SX_FIELD("first_block","uint32",8,4,SX_NONE),
    SX_FIELD("block_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("region0_reserved","uint16",16,2,SX_RESERVED),
    SX_FIELD("region0_blocks","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("region0_first_block","uint32",20,4,SX_NONE),
    SX_FIELD("region1_reserved","uint16",24,2,SX_RESERVED),
    SX_FIELD("region1_blocks","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("region1_first_block","uint32",28,4,SX_NONE),
    SX_FIELD("region2_reserved","uint16",32,2,SX_RESERVED),
    SX_FIELD("region2_blocks","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("region2_first_block","uint32",36,4,SX_NONE),
    SX_FIELD("region3_reserved","uint16",40,2,SX_RESERVED),
    SX_FIELD("region3_blocks","uint16",42,2,SX_COUNT_PROP),
    SX_FIELD("region3_first_block","uint32",44,4,SX_NONE),
};
static const sx_layout sxcf_unicos_partition = {0x603d0061U,"unicos_partition",sxcf_unicos_partition_fields,SX_COUNT(sxcf_unicos_partition_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_unicos_superblock_tail_fields[] = {
    SX_FIELD("io_unit","int64",0,8,SX_NONE),
    SX_FIELD("inode_reservation_blocks_minus_one","int64",8,8,SX_NONE),
    SX_FIELD("primary_partitions","int64",16,8,SX_FLAGS),
    SX_FIELD("primary_block_words_minus_one","int64",24,8,SX_NONE),
    SX_FIELD("primary_blocks","int64",32,8,SX_COUNT_PROP),
    SX_FIELD("secondary_partitions","int64",40,8,SX_FLAGS),
    SX_FIELD("secondary_block_words_minus_one","int64",48,8,SX_NONE),
    SX_FIELD("secondary_blocks","int64",56,8,SX_COUNT_PROP),
    SX_FIELD("filesystem_data_partitions","int64",64,8,SX_FLAGS),
    SX_FIELD("root_directory_partitions","int64",72,8,SX_FLAGS),
    SX_FIELD("no_user_data_partitions","int64",80,8,SX_FLAGS),
    SX_FIELD("semaphore_count","int64",88,8,SX_COUNT_PROP),
    SX_FIELD("active_primary_partitions","int64",96,8,SX_FLAGS),
    SX_FIELD("arbiter_identifier","int64",104,8,SX_ID),
    SX_FIELD("reserved","byte[728]",112,728,SX_RESERVED),
};
static const sx_layout sxcf_unicos_superblock_tail = {0x603d0062U,"unicos_superblock_tail",sxcf_unicos_superblock_tail_fields,SX_COUNT(sxcf_unicos_superblock_tail_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_unicos_inode_prefix_fields[] = {
    SX_FIELD("mode_encoded","uint32",0,4,SX_FLAGS),
    SX_FIELD("links_encoded","uint32",4,4,SX_FLAGS),
    SX_FIELD("opaque_08","byte[16]",8,16,SX_NONE),
    SX_FIELD("file_size","uint64",24,8,SX_SIZE),
    SX_FIELD("opaque_20","byte[49]",32,49,SX_NONE),
    SX_FIELD("allocation_device_flags","uint8",81,1,SX_FLAGS),
    SX_FIELD("opaque_52","byte[6]",82,6,SX_NONE),
    SX_FIELD("allocation_type_flags","uint8",88,1,SX_FLAGS),
    SX_FIELD("opaque_59","byte[39]",89,39,SX_NONE),
};
static const sx_layout sxcf_unicos_inode_prefix = {0x603d0063U,"unicos_inode_prefix",sxcf_unicos_inode_prefix_fields,SX_COUNT(sxcf_unicos_inode_prefix_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_unicos_extent_fields[] = {
    SX_FIELD("blocks_encoded","uint32",0,4,SX_FLAGS),
    SX_FIELD("first_block","uint32",4,4,SX_NONE),
};
static const sx_layout sxcf_unicos_extent = {0x603d0064U,"unicos_extent",sxcf_unicos_extent_fields,SX_COUNT(sxcf_unicos_extent_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_unicos_inode_tail_fields[] = {
    SX_FIELD("opaque_c0","byte[46]",0,46,SX_NONE),
    SX_FIELD("external_device","uint16",46,2,SX_NONE),
    SX_FIELD("opaque_f0","byte[16]",48,16,SX_NONE),
};
static const sx_layout sxcf_unicos_inode_tail = {0x603d0065U,"unicos_inode_tail",sxcf_unicos_inode_tail_fields,SX_COUNT(sxcf_unicos_inode_tail_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_unicos_directory_header_fields[] = {
    SX_FIELD("inode_number","uint64",0,8,SX_NONE),
    SX_FIELD("opaque_08","byte[8]",8,8,SX_NONE),
    SX_FIELD("record_and_name_lengths","uint64",16,8,SX_FLAGS),
};
static const sx_layout sxcf_unicos_directory_header = {0x603d0066U,"unicos_directory_header",sxcf_unicos_directory_header_fields,SX_COUNT(sxcf_unicos_directory_header_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_beos_superblock_le_fields[] = {
    SX_FIELD("name","char[32]",0,32,SX_NONE),
    SX_FIELD("magic1","uint32",32,4,SX_SIGNATURE),
    SX_FIELD("byte_order","uint32",36,4,SX_ID),
    SX_FIELD("block_size","uint32",40,4,SX_SIZE),
    SX_FIELD("block_shift","uint32",44,4,SX_NONE),
    SX_FIELD("block_count","int64",48,8,SX_COUNT_PROP),
    SX_FIELD("used_blocks","int64",56,8,SX_COUNT_PROP),
    SX_FIELD("inode_size","int32",64,4,SX_SIZE),
    SX_FIELD("magic2","uint32",68,4,SX_SIGNATURE),
    SX_FIELD("blocks_per_allocation_group","int32",72,4,SX_COUNT_PROP),
    SX_FIELD("allocation_group_shift","int32",76,4,SX_NONE),
    SX_FIELD("allocation_groups","int32",80,4,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",84,4,SX_FLAGS),
    SX_FIELD("log_group","int32",88,4,SX_NONE),
    SX_FIELD("log_start_block","uint16",92,2,SX_NONE),
    SX_FIELD("log_block_count","uint16",94,2,SX_COUNT_PROP),
    SX_FIELD("log_start","int64",96,8,SX_NONE),
    SX_FIELD("log_end","int64",104,8,SX_NONE),
    SX_FIELD("magic3","uint32",112,4,SX_SIGNATURE),
    SX_FIELD("root_group","int32",116,4,SX_NONE),
    SX_FIELD("root_start_block","uint16",120,2,SX_NONE),
    SX_FIELD("root_block_count","uint16",122,2,SX_COUNT_PROP),
    SX_FIELD("indices_group","int32",124,4,SX_NONE),
    SX_FIELD("indices_start_block","uint16",128,2,SX_NONE),
    SX_FIELD("indices_block_count","uint16",130,2,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[32]",132,32,SX_RESERVED),
    SX_FIELD("boot_padding","byte[348]",164,348,SX_NONE),
};
static const sx_layout sxcf_beos_superblock_le = {0x603d0067U,"beos_superblock_le",sxcf_beos_superblock_le_fields,SX_COUNT(sxcf_beos_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_beos_superblock_be_fields[] = {
    SX_FIELD("name","char[32]",0,32,SX_NONE),
    SX_FIELD("magic1","uint32",32,4,SX_SIGNATURE),
    SX_FIELD("byte_order","uint32",36,4,SX_ID),
    SX_FIELD("block_size","uint32",40,4,SX_SIZE),
    SX_FIELD("block_shift","uint32",44,4,SX_NONE),
    SX_FIELD("block_count","int64",48,8,SX_COUNT_PROP),
    SX_FIELD("used_blocks","int64",56,8,SX_COUNT_PROP),
    SX_FIELD("inode_size","int32",64,4,SX_SIZE),
    SX_FIELD("magic2","uint32",68,4,SX_SIGNATURE),
    SX_FIELD("blocks_per_allocation_group","int32",72,4,SX_COUNT_PROP),
    SX_FIELD("allocation_group_shift","int32",76,4,SX_NONE),
    SX_FIELD("allocation_groups","int32",80,4,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",84,4,SX_FLAGS),
    SX_FIELD("log_group","int32",88,4,SX_NONE),
    SX_FIELD("log_start_block","uint16",92,2,SX_NONE),
    SX_FIELD("log_block_count","uint16",94,2,SX_COUNT_PROP),
    SX_FIELD("log_start","int64",96,8,SX_NONE),
    SX_FIELD("log_end","int64",104,8,SX_NONE),
    SX_FIELD("magic3","uint32",112,4,SX_SIGNATURE),
    SX_FIELD("root_group","int32",116,4,SX_NONE),
    SX_FIELD("root_start_block","uint16",120,2,SX_NONE),
    SX_FIELD("root_block_count","uint16",122,2,SX_COUNT_PROP),
    SX_FIELD("indices_group","int32",124,4,SX_NONE),
    SX_FIELD("indices_start_block","uint16",128,2,SX_NONE),
    SX_FIELD("indices_block_count","uint16",130,2,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[32]",132,32,SX_RESERVED),
    SX_FIELD("boot_padding","byte[348]",164,348,SX_NONE),
};
static const sx_layout sxcf_beos_superblock_be = {0x603d0068U,"beos_superblock_be",sxcf_beos_superblock_be_fields,SX_COUNT(sxcf_beos_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_beos_inode_header_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("self_group","int32",4,4,SX_NONE),
    SX_FIELD("self_start_block","uint16",8,2,SX_NONE),
    SX_FIELD("self_blocks","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("user_id","int32",12,4,SX_ID),
    SX_FIELD("group_id","int32",16,4,SX_ID),
    SX_FIELD("mode","int32",20,4,SX_FLAGS),
    SX_FIELD("flags","int32",24,4,SX_FLAGS),
    SX_FIELD("creation_time_encoded","int64",28,8,SX_NONE),
    SX_FIELD("modification_time_encoded","int64",36,8,SX_NONE),
    SX_FIELD("parent_group","int32",44,4,SX_NONE),
    SX_FIELD("parent_start_block","uint16",48,2,SX_NONE),
    SX_FIELD("parent_blocks","uint16",50,2,SX_COUNT_PROP),
    SX_FIELD("attributes_group","int32",52,4,SX_NONE),
    SX_FIELD("attributes_start_block","uint16",56,2,SX_NONE),
    SX_FIELD("attributes_blocks","uint16",58,2,SX_COUNT_PROP),
    SX_FIELD("attribute_type","uint32",60,4,SX_ID),
    SX_FIELD("inode_size","int32",64,4,SX_SIZE),
    SX_FIELD("etc","uint32",68,4,SX_NONE),
};
static const sx_layout sxcf_beos_inode_header_le = {0x603d0069U,"beos_inode_header_le",sxcf_beos_inode_header_le_fields,SX_COUNT(sxcf_beos_inode_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_beos_inode_header_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("self_group","int32",4,4,SX_NONE),
    SX_FIELD("self_start_block","uint16",8,2,SX_NONE),
    SX_FIELD("self_blocks","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("user_id","int32",12,4,SX_ID),
    SX_FIELD("group_id","int32",16,4,SX_ID),
    SX_FIELD("mode","int32",20,4,SX_FLAGS),
    SX_FIELD("flags","int32",24,4,SX_FLAGS),
    SX_FIELD("creation_time_encoded","int64",28,8,SX_NONE),
    SX_FIELD("modification_time_encoded","int64",36,8,SX_NONE),
    SX_FIELD("parent_group","int32",44,4,SX_NONE),
    SX_FIELD("parent_start_block","uint16",48,2,SX_NONE),
    SX_FIELD("parent_blocks","uint16",50,2,SX_COUNT_PROP),
    SX_FIELD("attributes_group","int32",52,4,SX_NONE),
    SX_FIELD("attributes_start_block","uint16",56,2,SX_NONE),
    SX_FIELD("attributes_blocks","uint16",58,2,SX_COUNT_PROP),
    SX_FIELD("attribute_type","uint32",60,4,SX_ID),
    SX_FIELD("inode_size","int32",64,4,SX_SIZE),
    SX_FIELD("etc","uint32",68,4,SX_NONE),
};
static const sx_layout sxcf_beos_inode_header_be = {0x603d006aU,"beos_inode_header_be",sxcf_beos_inode_header_be_fields,SX_COUNT(sxcf_beos_inode_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_atheos_superblock_le_fields[] = {
    SX_FIELD("name","char[32]",0,32,SX_NONE),
    SX_FIELD("magic1","uint32",32,4,SX_SIGNATURE),
    SX_FIELD("byte_order","uint32",36,4,SX_ID),
    SX_FIELD("block_size","uint32",40,4,SX_SIZE),
    SX_FIELD("block_shift","uint32",44,4,SX_NONE),
    SX_FIELD("block_count","int64",48,8,SX_COUNT_PROP),
    SX_FIELD("used_blocks","int64",56,8,SX_COUNT_PROP),
    SX_FIELD("inode_size","int32",64,4,SX_SIZE),
    SX_FIELD("magic2","uint32",68,4,SX_SIGNATURE),
    SX_FIELD("blocks_per_allocation_group","int32",72,4,SX_COUNT_PROP),
    SX_FIELD("allocation_group_shift","int32",76,4,SX_NONE),
    SX_FIELD("allocation_groups","int32",80,4,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",84,4,SX_FLAGS),
    SX_FIELD("log_group","int32",88,4,SX_NONE),
    SX_FIELD("log_start_block","uint16",92,2,SX_NONE),
    SX_FIELD("log_block_count","uint16",94,2,SX_COUNT_PROP),
    SX_FIELD("log_start","int64",96,8,SX_NONE),
    SX_FIELD("valid_log_blocks","int32",104,4,SX_COUNT_PROP),
    SX_FIELD("log_size","int32",108,4,SX_COUNT_PROP),
    SX_FIELD("magic3","uint32",112,4,SX_SIGNATURE),
    SX_FIELD("root_group","int32",116,4,SX_NONE),
    SX_FIELD("root_start_block","uint16",120,2,SX_NONE),
    SX_FIELD("root_block_count","uint16",122,2,SX_COUNT_PROP),
    SX_FIELD("deleted_group","int32",124,4,SX_NONE),
    SX_FIELD("deleted_start_block","uint16",128,2,SX_NONE),
    SX_FIELD("deleted_block_count","uint16",130,2,SX_COUNT_PROP),
    SX_FIELD("indices_group","int32",132,4,SX_NONE),
    SX_FIELD("indices_start_block","uint16",136,2,SX_NONE),
    SX_FIELD("indices_block_count","uint16",138,2,SX_COUNT_PROP),
    SX_FIELD("boot_size","int32",140,4,SX_SIZE),
};
static const sx_layout sxcf_atheos_superblock_le = {0x603d006bU,"atheos_superblock_le",sxcf_atheos_superblock_le_fields,SX_COUNT(sxcf_atheos_superblock_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_atheos_superblock_be_fields[] = {
    SX_FIELD("name","char[32]",0,32,SX_NONE),
    SX_FIELD("magic1","uint32",32,4,SX_SIGNATURE),
    SX_FIELD("byte_order","uint32",36,4,SX_ID),
    SX_FIELD("block_size","uint32",40,4,SX_SIZE),
    SX_FIELD("block_shift","uint32",44,4,SX_NONE),
    SX_FIELD("block_count","int64",48,8,SX_COUNT_PROP),
    SX_FIELD("used_blocks","int64",56,8,SX_COUNT_PROP),
    SX_FIELD("inode_size","int32",64,4,SX_SIZE),
    SX_FIELD("magic2","uint32",68,4,SX_SIGNATURE),
    SX_FIELD("blocks_per_allocation_group","int32",72,4,SX_COUNT_PROP),
    SX_FIELD("allocation_group_shift","int32",76,4,SX_NONE),
    SX_FIELD("allocation_groups","int32",80,4,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",84,4,SX_FLAGS),
    SX_FIELD("log_group","int32",88,4,SX_NONE),
    SX_FIELD("log_start_block","uint16",92,2,SX_NONE),
    SX_FIELD("log_block_count","uint16",94,2,SX_COUNT_PROP),
    SX_FIELD("log_start","int64",96,8,SX_NONE),
    SX_FIELD("valid_log_blocks","int32",104,4,SX_COUNT_PROP),
    SX_FIELD("log_size","int32",108,4,SX_COUNT_PROP),
    SX_FIELD("magic3","uint32",112,4,SX_SIGNATURE),
    SX_FIELD("root_group","int32",116,4,SX_NONE),
    SX_FIELD("root_start_block","uint16",120,2,SX_NONE),
    SX_FIELD("root_block_count","uint16",122,2,SX_COUNT_PROP),
    SX_FIELD("deleted_group","int32",124,4,SX_NONE),
    SX_FIELD("deleted_start_block","uint16",128,2,SX_NONE),
    SX_FIELD("deleted_block_count","uint16",130,2,SX_COUNT_PROP),
    SX_FIELD("indices_group","int32",132,4,SX_NONE),
    SX_FIELD("indices_start_block","uint16",136,2,SX_NONE),
    SX_FIELD("indices_block_count","uint16",138,2,SX_COUNT_PROP),
    SX_FIELD("boot_size","int32",140,4,SX_SIZE),
};
static const sx_layout sxcf_atheos_superblock_be = {0x603d006cU,"atheos_superblock_be",sxcf_atheos_superblock_be_fields,SX_COUNT(sxcf_atheos_superblock_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_atheos_inode_header_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("self_group","int32",4,4,SX_NONE),
    SX_FIELD("self_start_block","uint16",8,2,SX_NONE),
    SX_FIELD("self_blocks","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("user_id","int32",12,4,SX_ID),
    SX_FIELD("group_id","int32",16,4,SX_ID),
    SX_FIELD("mode","int32",20,4,SX_FLAGS),
    SX_FIELD("flags","int32",24,4,SX_FLAGS),
    SX_FIELD("link_count","int32",28,4,SX_COUNT_PROP),
    SX_FIELD("creation_time_encoded","int64",32,8,SX_NONE),
    SX_FIELD("modification_time_encoded","int64",40,8,SX_NONE),
    SX_FIELD("parent_group","int32",48,4,SX_NONE),
    SX_FIELD("parent_start_block","uint16",52,2,SX_NONE),
    SX_FIELD("parent_blocks","uint16",54,2,SX_COUNT_PROP),
    SX_FIELD("attributes_group","int32",56,4,SX_NONE),
    SX_FIELD("attributes_start_block","uint16",60,2,SX_NONE),
    SX_FIELD("attributes_blocks","uint16",62,2,SX_COUNT_PROP),
    SX_FIELD("attribute_type","uint32",64,4,SX_ID),
    SX_FIELD("inode_size","int32",68,4,SX_SIZE),
    SX_FIELD("stored_vnode_pointer","int64",72,8,SX_POINTER),
};
static const sx_layout sxcf_atheos_inode_header_le = {0x603d006dU,"atheos_inode_header_le",sxcf_atheos_inode_header_le_fields,SX_COUNT(sxcf_atheos_inode_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_atheos_inode_header_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("self_group","int32",4,4,SX_NONE),
    SX_FIELD("self_start_block","uint16",8,2,SX_NONE),
    SX_FIELD("self_blocks","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("user_id","int32",12,4,SX_ID),
    SX_FIELD("group_id","int32",16,4,SX_ID),
    SX_FIELD("mode","int32",20,4,SX_FLAGS),
    SX_FIELD("flags","int32",24,4,SX_FLAGS),
    SX_FIELD("link_count","int32",28,4,SX_COUNT_PROP),
    SX_FIELD("creation_time_encoded","int64",32,8,SX_NONE),
    SX_FIELD("modification_time_encoded","int64",40,8,SX_NONE),
    SX_FIELD("parent_group","int32",48,4,SX_NONE),
    SX_FIELD("parent_start_block","uint16",52,2,SX_NONE),
    SX_FIELD("parent_blocks","uint16",54,2,SX_COUNT_PROP),
    SX_FIELD("attributes_group","int32",56,4,SX_NONE),
    SX_FIELD("attributes_start_block","uint16",60,2,SX_NONE),
    SX_FIELD("attributes_blocks","uint16",62,2,SX_COUNT_PROP),
    SX_FIELD("attribute_type","uint32",64,4,SX_ID),
    SX_FIELD("inode_size","int32",68,4,SX_SIZE),
    SX_FIELD("stored_vnode_pointer","int64",72,8,SX_POINTER),
};
static const sx_layout sxcf_atheos_inode_header_be = {0x603d006eU,"atheos_inode_header_be",sxcf_atheos_inode_header_be_fields,SX_COUNT(sxcf_atheos_inode_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_bfs_block_run_le_fields[] = {
    SX_FIELD("allocation_group","int32",0,4,SX_NONE),
    SX_FIELD("first_block","uint16",4,2,SX_NONE),
    SX_FIELD("block_count","uint16",6,2,SX_COUNT_PROP),
};
static const sx_layout sxcf_bfs_block_run_le = {0x603d006fU,"bfs_block_run_le",sxcf_bfs_block_run_le_fields,SX_COUNT(sxcf_bfs_block_run_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_bfs_block_run_be_fields[] = {
    SX_FIELD("allocation_group","int32",0,4,SX_NONE),
    SX_FIELD("first_block","uint16",4,2,SX_NONE),
    SX_FIELD("block_count","uint16",6,2,SX_COUNT_PROP),
};
static const sx_layout sxcf_bfs_block_run_be = {0x603d0070U,"bfs_block_run_be",sxcf_bfs_block_run_be_fields,SX_COUNT(sxcf_bfs_block_run_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_bfs_stream_tail_le_fields[] = {
    SX_FIELD("maximum_direct_range","int64",0,8,SX_SIZE),
    SX_FIELD("indirect_group","int32",8,4,SX_NONE),
    SX_FIELD("indirect_start","uint16",12,2,SX_NONE),
    SX_FIELD("indirect_blocks","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("maximum_indirect_range","int64",16,8,SX_SIZE),
    SX_FIELD("double_indirect_group","int32",24,4,SX_NONE),
    SX_FIELD("double_indirect_start","uint16",28,2,SX_NONE),
    SX_FIELD("double_indirect_blocks","uint16",30,2,SX_COUNT_PROP),
    SX_FIELD("maximum_double_indirect_range","int64",32,8,SX_SIZE),
    SX_FIELD("file_size","int64",40,8,SX_SIZE),
};
static const sx_layout sxcf_bfs_stream_tail_le = {0x603d0071U,"bfs_stream_tail_le",sxcf_bfs_stream_tail_le_fields,SX_COUNT(sxcf_bfs_stream_tail_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_bfs_stream_tail_be_fields[] = {
    SX_FIELD("maximum_direct_range","int64",0,8,SX_SIZE),
    SX_FIELD("indirect_group","int32",8,4,SX_NONE),
    SX_FIELD("indirect_start","uint16",12,2,SX_NONE),
    SX_FIELD("indirect_blocks","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("maximum_indirect_range","int64",16,8,SX_SIZE),
    SX_FIELD("double_indirect_group","int32",24,4,SX_NONE),
    SX_FIELD("double_indirect_start","uint16",28,2,SX_NONE),
    SX_FIELD("double_indirect_blocks","uint16",30,2,SX_COUNT_PROP),
    SX_FIELD("maximum_double_indirect_range","int64",32,8,SX_SIZE),
    SX_FIELD("file_size","int64",40,8,SX_SIZE),
};
static const sx_layout sxcf_bfs_stream_tail_be = {0x603d0072U,"bfs_stream_tail_be",sxcf_bfs_stream_tail_be_fields,SX_COUNT(sxcf_bfs_stream_tail_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_beos_inode_tail_le_fields[] = {
    SX_FIELD("status_change_or_reserved","int64",0,8,SX_NONE),
    SX_FIELD("padding","byte[8]",8,8,SX_RESERVED),
};
static const sx_layout sxcf_beos_inode_tail_le = {0x603d0073U,"beos_inode_tail_le",sxcf_beos_inode_tail_le_fields,SX_COUNT(sxcf_beos_inode_tail_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_beos_inode_tail_be_fields[] = {
    SX_FIELD("status_change_or_reserved","int64",0,8,SX_NONE),
    SX_FIELD("padding","byte[8]",8,8,SX_RESERVED),
};
static const sx_layout sxcf_beos_inode_tail_be = {0x603d0074U,"beos_inode_tail_be",sxcf_beos_inode_tail_be_fields,SX_COUNT(sxcf_beos_inode_tail_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_bfs_small_data_header_le_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("name_size","uint16",4,2,SX_SIZE),
    SX_FIELD("data_size","uint16",6,2,SX_SIZE),
};
static const sx_layout sxcf_bfs_small_data_header_le = {0x603d0075U,"bfs_small_data_header_le",sxcf_bfs_small_data_header_le_fields,SX_COUNT(sxcf_bfs_small_data_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_bfs_small_data_header_be_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("name_size","uint16",4,2,SX_SIZE),
    SX_FIELD("data_size","uint16",6,2,SX_SIZE),
};
static const sx_layout sxcf_bfs_small_data_header_be = {0x603d0076U,"bfs_small_data_header_be",sxcf_bfs_small_data_header_be_fields,SX_COUNT(sxcf_bfs_small_data_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_beos_btree_header_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("node_size","uint32",4,4,SX_SIZE),
    SX_FIELD("maximum_depth","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("data_type","uint32",12,4,SX_ID),
    SX_FIELD("root_node","int64",16,8,SX_OFFSET),
    SX_FIELD("free_node","int64",24,8,SX_OFFSET),
    SX_FIELD("maximum_size","int64",32,8,SX_SIZE),
};
static const sx_layout sxcf_beos_btree_header_le = {0x603d0077U,"beos_btree_header_le",sxcf_beos_btree_header_le_fields,SX_COUNT(sxcf_beos_btree_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_beos_btree_header_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("node_size","uint32",4,4,SX_SIZE),
    SX_FIELD("maximum_depth","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("data_type","uint32",12,4,SX_ID),
    SX_FIELD("root_node","int64",16,8,SX_OFFSET),
    SX_FIELD("free_node","int64",24,8,SX_OFFSET),
    SX_FIELD("maximum_size","int64",32,8,SX_SIZE),
};
static const sx_layout sxcf_beos_btree_header_be = {0x603d0078U,"beos_btree_header_be",sxcf_beos_btree_header_be_fields,SX_COUNT(sxcf_beos_btree_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_atheos_btree_header_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("root_node","int64",4,8,SX_OFFSET),
    SX_FIELD("depth","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("last_node","int64",16,8,SX_OFFSET),
    SX_FIELD("first_free_node","int64",24,8,SX_OFFSET),
};
static const sx_layout sxcf_atheos_btree_header_le = {0x603d0079U,"atheos_btree_header_le",sxcf_atheos_btree_header_le_fields,SX_COUNT(sxcf_atheos_btree_header_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_atheos_btree_header_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("root_node","int64",4,8,SX_OFFSET),
    SX_FIELD("depth","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("last_node","int64",16,8,SX_OFFSET),
    SX_FIELD("first_free_node","int64",24,8,SX_OFFSET),
};
static const sx_layout sxcf_atheos_btree_header_be = {0x603d007aU,"atheos_btree_header_be",sxcf_atheos_btree_header_be_fields,SX_COUNT(sxcf_atheos_btree_header_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_beos_btree_node_le_fields[] = {
    SX_FIELD("left_node","int64",0,8,SX_OFFSET),
    SX_FIELD("right_node","int64",8,8,SX_OFFSET),
    SX_FIELD("overflow_node","int64",16,8,SX_OFFSET),
    SX_FIELD("key_count","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("key_data_size","uint16",26,2,SX_SIZE),
};
static const sx_layout sxcf_beos_btree_node_le = {0x603d007bU,"beos_btree_node_le",sxcf_beos_btree_node_le_fields,SX_COUNT(sxcf_beos_btree_node_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_beos_btree_node_be_fields[] = {
    SX_FIELD("left_node","int64",0,8,SX_OFFSET),
    SX_FIELD("right_node","int64",8,8,SX_OFFSET),
    SX_FIELD("overflow_node","int64",16,8,SX_OFFSET),
    SX_FIELD("key_count","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("key_data_size","uint16",26,2,SX_SIZE),
};
static const sx_layout sxcf_beos_btree_node_be = {0x603d007cU,"beos_btree_node_be",sxcf_beos_btree_node_be_fields,SX_COUNT(sxcf_beos_btree_node_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_atheos_btree_node_le_fields[] = {
    SX_FIELD("left_node","int64",0,8,SX_OFFSET),
    SX_FIELD("right_node","int64",8,8,SX_OFFSET),
    SX_FIELD("overflow_node","int64",16,8,SX_OFFSET),
    SX_FIELD("key_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("key_data_size","uint32",28,4,SX_SIZE),
};
static const sx_layout sxcf_atheos_btree_node_le = {0x603d007dU,"atheos_btree_node_le",sxcf_atheos_btree_node_le_fields,SX_COUNT(sxcf_atheos_btree_node_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_atheos_btree_node_be_fields[] = {
    SX_FIELD("left_node","int64",0,8,SX_OFFSET),
    SX_FIELD("right_node","int64",8,8,SX_OFFSET),
    SX_FIELD("overflow_node","int64",16,8,SX_OFFSET),
    SX_FIELD("key_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("key_data_size","uint32",28,4,SX_SIZE),
};
static const sx_layout sxcf_atheos_btree_node_be = {0x603d007eU,"atheos_btree_node_be",sxcf_atheos_btree_node_be_fields,SX_COUNT(sxcf_atheos_btree_node_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_hpofs_volume_information_fields[] = {
    SX_FIELD("identifier","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("record_version1","uint32",8,4,SX_ID),
    SX_FIELD("record_version2","uint32",12,4,SX_ID),
    SX_FIELD("directory_intent_counter","uint32",16,4,SX_NONE),
    SX_FIELD("directory_update_counter","uint32",20,4,SX_NONE),
};
static const sx_layout sxcf_hpofs_volume_information = {0x603d007fU,"hpofs_volume_information",sxcf_hpofs_volume_information_fields,SX_COUNT(sxcf_hpofs_volume_information_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_bfs_btree_key_end_le_fields[] = {
    SX_FIELD("end_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxcf_bfs_btree_key_end_le = {0x603d0080U,"bfs_btree_key_end_le",sxcf_bfs_btree_key_end_le_fields,SX_COUNT(sxcf_bfs_btree_key_end_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_bfs_btree_key_end_be_fields[] = {
    SX_FIELD("end_offset","uint16",0,2,SX_OFFSET),
};
static const sx_layout sxcf_bfs_btree_key_end_be = {0x603d0081U,"bfs_btree_key_end_be",sxcf_bfs_btree_key_end_be_fields,SX_COUNT(sxcf_bfs_btree_key_end_be_fields),SX_BE};

static const xx_data_struct_field_desc sxcf_bfs_btree_value_le_fields[] = {
    SX_FIELD("inode_or_node","uint64",0,8,SX_NONE),
};
static const sx_layout sxcf_bfs_btree_value_le = {0x603d0082U,"bfs_btree_value_le",sxcf_bfs_btree_value_le_fields,SX_COUNT(sxcf_bfs_btree_value_le_fields),SX_LE};

static const xx_data_struct_field_desc sxcf_bfs_btree_value_be_fields[] = {
    SX_FIELD("inode_or_node","uint64",0,8,SX_NONE),
};
static const sx_layout sxcf_bfs_btree_value_be = {0x603d0083U,"bfs_btree_value_be",sxcf_bfs_btree_value_be_fields,SX_COUNT(sxcf_bfs_btree_value_be_fields),SX_BE};

static const sx_layout *const sx_classicfs_layouts[] = {
    &sxcf_minix1_superblock_le,
    &sxcf_minix1_superblock_be,
    &sxcf_minix2_superblock_le,
    &sxcf_minix2_superblock_be,
    &sxcf_minix3_superblock_le,
    &sxcf_minix3_superblock_be,
    &sxcf_minix1_inode_le,
    &sxcf_minix1_inode_be,
    &sxcf_minix23_inode_le,
    &sxcf_minix23_inode_be,
    &sxcf_minix_directory_14_le,
    &sxcf_minix_directory_14_be,
    &sxcf_minix_directory_30_le,
    &sxcf_minix_directory_30_be,
    &sxcf_minix3_directory_le,
    &sxcf_minix3_directory_be,
    &sxcf_classic_block_number16_le,
    &sxcf_classic_block_number16_be,
    &sxcf_classic_block_number32_le,
    &sxcf_classic_block_number32_be,
    &sxcf_classic_block_number_pdp,
    &sxcf_v7_superblock_le,
    &sxcf_v7_superblock_be,
    &sxcf_v7_superblock_pdp,
    &sxcf_coherent_superblock_pdp,
    &sxcf_sysv2_superblock_le,
    &sxcf_sysv2_superblock_be,
    &sxcf_sysv4_superblock_le,
    &sxcf_sysv4_superblock_be,
    &sxcf_xenix_superblock_le,
    &sxcf_xenix_superblock_be,
    &sxcf_unix_inode_le,
    &sxcf_unix_inode_be,
    &sxcf_unix_inode_pdp,
    &sxcf_unix_directory_le,
    &sxcf_unix_directory_be,
    &sxcf_linux_ext_superblock,
    &sxcf_linux_ext_inode,
    &sxcf_linux_ext_directory_header,
    &sxcf_xia_superblock,
    &sxcf_xia_inode,
    &sxcf_xia_directory_header,
    &sxcf_unix_bfs_superblock,
    &sxcf_unix_bfs_inode,
    &sxcf_qnx4_inode,
    &sxcf_qnx4_link,
    &sxcf_qnx4_extent_block_header,
    &sxcf_qnx4_extent,
    &sxcf_qnx4_extent_block_tail,
    &sxcf_efs_superblock,
    &sxcf_efs_inode_header,
    &sxcf_efs_extent,
    &sxcf_efs_directory_header,
    &sxcf_efs_directory_entry,
    &sxcf_rt11_home_block,
    &sxcf_rt11_directory_segment,
    &sxcf_rt11_directory_entry,
    &sxcf_hp_lif_volume_header,
    &sxcf_hp_lif_directory_entry,
    &sxcf_ecma67_volume_label,
    &sxcf_ecma67_error_map_label,
    &sxcf_ecma67_file_label,
    &sxcf_locus_superblock_prefix_le,
    &sxcf_locus_superblock_prefix_be,
    &sxcf_locus_inode_le,
    &sxcf_locus_inode_be,
    &sxcf_locus_inode_small_le,
    &sxcf_locus_inode_small_be,
    &sxcf_locus_directory_header_le,
    &sxcf_locus_directory_header_be,
    &sxcf_pfs_root_block,
    &sxcf_pfs_root_small_indexes,
    &sxcf_pfs_root_large_indexes,
    &sxcf_pfs_index_header,
    &sxcf_pfs_anode_header,
    &sxcf_pfs_anode,
    &sxcf_pfs_directory_header,
    &sxcf_pfs_directory_entry,
    &sxcf_pfs_extension,
    &sxcf_hpofs_boot_sector,
    &sxcf_hpofs_media_information,
    &sxcf_hpofs_subfile_header,
    &sxcf_hpofs_extent,
    &sxcf_hpofs_directory_node,
    &sxcf_hpofs_directory_record_prefix,
    &sxcf_hpofs_directory_record,
    &sxcf_ods_home_block,
    &sxcf_ods_file_header,
    &sxcf_ods_file_checksum,
    &sxcf_ods_retrieval_pointer0,
    &sxcf_ods_retrieval_pointer1,
    &sxcf_ods_retrieval_pointer2,
    &sxcf_ods_retrieval_pointer3,
    &sxcf_ods_directory_header,
    &sxcf_ods_directory_version,
    &sxcf_unicos_superblock_prefix,
    &sxcf_unicos_partition,
    &sxcf_unicos_superblock_tail,
    &sxcf_unicos_inode_prefix,
    &sxcf_unicos_extent,
    &sxcf_unicos_inode_tail,
    &sxcf_unicos_directory_header,
    &sxcf_beos_superblock_le,
    &sxcf_beos_superblock_be,
    &sxcf_beos_inode_header_le,
    &sxcf_beos_inode_header_be,
    &sxcf_atheos_superblock_le,
    &sxcf_atheos_superblock_be,
    &sxcf_atheos_inode_header_le,
    &sxcf_atheos_inode_header_be,
    &sxcf_bfs_block_run_le,
    &sxcf_bfs_block_run_be,
    &sxcf_bfs_stream_tail_le,
    &sxcf_bfs_stream_tail_be,
    &sxcf_beos_inode_tail_le,
    &sxcf_beos_inode_tail_be,
    &sxcf_bfs_small_data_header_le,
    &sxcf_bfs_small_data_header_be,
    &sxcf_beos_btree_header_le,
    &sxcf_beos_btree_header_be,
    &sxcf_atheos_btree_header_le,
    &sxcf_atheos_btree_header_be,
    &sxcf_beos_btree_node_le,
    &sxcf_beos_btree_node_be,
    &sxcf_atheos_btree_node_le,
    &sxcf_atheos_btree_node_be,
    &sxcf_hpofs_volume_information,
    &sxcf_bfs_btree_key_end_le,
    &sxcf_bfs_btree_key_end_be,
    &sxcf_bfs_btree_value_le,
    &sxcf_bfs_btree_value_be,
};

static bool sx_classicfs_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x603d0000U||id>=0x603e0000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    switch(id){
    case 0x603d0001U:
        if(!xx_rt_wcscmp(r->name,L"zone_count_16"))s=L"MINIX v1 zone count; superseded by the 32-bit count in v2.";
        else if(!xx_rt_wcscmp(r->name,L"first_data_zone"))s=L"Zone number; multiply by the zone byte size to obtain a volume offset.";
        else if(!xx_rt_wcscmp(r->name,L"log_zone_size"))s=L"Zone size is block_size shifted left by this value.";
        else if(!xx_rt_wcscmp(r->name,L"state"))s=L"1: clean filesystem; 2: filesystem has errors.";
        break;
    case 0x603d0002U:
        if(!xx_rt_wcscmp(r->name,L"zone_count_16"))s=L"MINIX v1 zone count; superseded by the 32-bit count in v2.";
        else if(!xx_rt_wcscmp(r->name,L"first_data_zone"))s=L"Zone number; multiply by the zone byte size to obtain a volume offset.";
        else if(!xx_rt_wcscmp(r->name,L"log_zone_size"))s=L"Zone size is block_size shifted left by this value.";
        else if(!xx_rt_wcscmp(r->name,L"state"))s=L"1: clean filesystem; 2: filesystem has errors.";
        break;
    case 0x603d0003U:
        if(!xx_rt_wcscmp(r->name,L"zone_count_16"))s=L"MINIX v1 zone count; superseded by the 32-bit count in v2.";
        else if(!xx_rt_wcscmp(r->name,L"first_data_zone"))s=L"Zone number; multiply by the zone byte size to obtain a volume offset.";
        else if(!xx_rt_wcscmp(r->name,L"log_zone_size"))s=L"Zone size is block_size shifted left by this value.";
        else if(!xx_rt_wcscmp(r->name,L"state"))s=L"1: clean filesystem; 2: filesystem has errors.";
        break;
    case 0x603d0004U:
        if(!xx_rt_wcscmp(r->name,L"zone_count_16"))s=L"MINIX v1 zone count; superseded by the 32-bit count in v2.";
        else if(!xx_rt_wcscmp(r->name,L"first_data_zone"))s=L"Zone number; multiply by the zone byte size to obtain a volume offset.";
        else if(!xx_rt_wcscmp(r->name,L"log_zone_size"))s=L"Zone size is block_size shifted left by this value.";
        else if(!xx_rt_wcscmp(r->name,L"state"))s=L"1: clean filesystem; 2: filesystem has errors.";
        break;
    case 0x603d0005U:
        if(!xx_rt_wcscmp(r->name,L"first_data_zone"))s=L"Zone number, not a byte offset.";
        else if(!xx_rt_wcscmp(r->name,L"log_zone_size"))s=L"Zone size is block_size shifted left by this value.";
        break;
    case 0x603d0006U:
        if(!xx_rt_wcscmp(r->name,L"first_data_zone"))s=L"Zone number, not a byte offset.";
        else if(!xx_rt_wcscmp(r->name,L"log_zone_size"))s=L"Zone size is block_size shifted left by this value.";
        break;
    case 0x603d0007U:
        if(!xx_rt_wcscmp(r->name,L"mode"))s=L"Unix file type and permissions.";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since the Unix epoch.";
        else if(!xx_rt_wcscmp(r->name,L"zone_numbers"))s=L"Seven direct zones, then single and double indirect zones; zero represents a sparse hole.";
        break;
    case 0x603d0008U:
        if(!xx_rt_wcscmp(r->name,L"mode"))s=L"Unix file type and permissions.";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since the Unix epoch.";
        else if(!xx_rt_wcscmp(r->name,L"zone_numbers"))s=L"Seven direct zones, then single and double indirect zones; zero represents a sparse hole.";
        break;
    case 0x603d0009U:
        if(!xx_rt_wcscmp(r->name,L"zone_numbers"))s=L"Seven direct zones, then single, double and triple indirect zones.";
        break;
    case 0x603d000aU:
        if(!xx_rt_wcscmp(r->name,L"zone_numbers"))s=L"Seven direct zones, then single, double and triple indirect zones.";
        break;
    case 0x603d0011U:
        if(!xx_rt_wcscmp(r->name,L"block_number"))s=L"Filesystem block/zone number; not a byte offset.";
        break;
    case 0x603d0012U:
        if(!xx_rt_wcscmp(r->name,L"block_number"))s=L"Filesystem block/zone number; not a byte offset.";
        break;
    case 0x603d0013U:
        if(!xx_rt_wcscmp(r->name,L"block_number"))s=L"Filesystem block/zone number; not a byte offset.";
        break;
    case 0x603d0014U:
        if(!xx_rt_wcscmp(r->name,L"block_number"))s=L"Filesystem block/zone number; not a byte offset.";
        break;
    case 0x603d0015U:
        if(!xx_rt_wcscmp(r->name,L"block_number"))s=L"PDP-endian filesystem block number; high little-endian halfword precedes low little-endian halfword.";
        break;
    case 0x603d0016U:
        if(!xx_rt_wcscmp(r->name,L"first_data_block"))s=L"First data block number; earlier blocks contain the inode table.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_cache"))s=L"Cached free block numbers, not byte offsets.";
        else if(!xx_rt_wcscmp(r->name,L"last_update"))s=L"Unix epoch seconds; PDP variants store the high little-endian halfword first.";
        break;
    case 0x603d0017U:
        if(!xx_rt_wcscmp(r->name,L"first_data_block"))s=L"First data block number; earlier blocks contain the inode table.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_cache"))s=L"Cached free block numbers, not byte offsets.";
        else if(!xx_rt_wcscmp(r->name,L"last_update"))s=L"Unix epoch seconds; PDP variants store the high little-endian halfword first.";
        break;
    case 0x603d0018U:
        if(!xx_rt_wcscmp(r->name,L"first_data_block"))s=L"First data block number; earlier blocks contain the inode table.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_00"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_01"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_02"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_03"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_04"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_05"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_06"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_07"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_08"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_09"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_10"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_11"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_12"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_13"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_14"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_15"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_16"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_17"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_18"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_19"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_20"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_21"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_22"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_23"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_24"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_25"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_26"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_27"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_28"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_29"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_30"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_31"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_32"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_33"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_34"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_35"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_36"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_37"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_38"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_39"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_40"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_41"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_42"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_43"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_44"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_45"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_46"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_47"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_48"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_49"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"last_update"))s=L"Unix epoch seconds; PDP variants store the high little-endian halfword first.";
        break;
    case 0x603d0019U:
        if(!xx_rt_wcscmp(r->name,L"first_data_block"))s=L"First data block number; earlier blocks contain the inode table.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_00"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_01"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_02"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_03"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_04"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_05"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_06"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_07"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_08"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_09"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_10"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_11"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_12"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_13"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_14"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_15"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_16"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_17"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_18"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_19"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_20"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_21"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_22"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_23"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_24"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_25"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_26"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_27"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_28"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_29"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_30"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_31"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_32"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_33"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_34"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_35"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_36"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_37"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_38"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_39"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_40"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_41"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_42"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_43"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_44"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_45"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_46"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_47"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_48"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_49"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_50"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_51"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_52"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_53"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_54"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_55"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_56"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_57"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_58"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_59"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_60"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_61"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_62"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_63"))s=L"Cached free block number in PDP byte order.";
        else if(!xx_rt_wcscmp(r->name,L"last_update"))s=L"Unix epoch seconds; PDP variants store the high little-endian halfword first.";
        break;
    case 0x603d001aU:
        if(!xx_rt_wcscmp(r->name,L"first_data_block"))s=L"First data block number; earlier blocks contain the inode table.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_cache"))s=L"Cached free block numbers, not byte offsets.";
        else if(!xx_rt_wcscmp(r->name,L"last_update"))s=L"Unix epoch seconds; PDP variants store the high little-endian halfword first.";
        else if(!xx_rt_wcscmp(r->name,L"state"))s=L"Clean-state encoding depends on System V release.";
        else if(!xx_rt_wcscmp(r->name,L"block_size_type"))s=L"1: 512 bytes; 2: 1024 bytes; 3: 2048 bytes.";
        break;
    case 0x603d001bU:
        if(!xx_rt_wcscmp(r->name,L"first_data_block"))s=L"First data block number; earlier blocks contain the inode table.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_cache"))s=L"Cached free block numbers, not byte offsets.";
        else if(!xx_rt_wcscmp(r->name,L"last_update"))s=L"Unix epoch seconds; PDP variants store the high little-endian halfword first.";
        else if(!xx_rt_wcscmp(r->name,L"state"))s=L"Clean-state encoding depends on System V release.";
        else if(!xx_rt_wcscmp(r->name,L"block_size_type"))s=L"1: 512 bytes; 2: 1024 bytes; 3: 2048 bytes.";
        break;
    case 0x603d001cU:
        if(!xx_rt_wcscmp(r->name,L"first_data_block"))s=L"First data block number; earlier blocks contain the inode table.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_cache"))s=L"Cached free block numbers, not byte offsets.";
        else if(!xx_rt_wcscmp(r->name,L"last_update"))s=L"Unix epoch seconds; PDP variants store the high little-endian halfword first.";
        else if(!xx_rt_wcscmp(r->name,L"state"))s=L"Clean-state encoding depends on System V release.";
        else if(!xx_rt_wcscmp(r->name,L"block_size_type"))s=L"1: 512 bytes; 2: 1024 bytes; 3: 2048 bytes.";
        break;
    case 0x603d001dU:
        if(!xx_rt_wcscmp(r->name,L"first_data_block"))s=L"First data block number; earlier blocks contain the inode table.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_cache"))s=L"Cached free block numbers, not byte offsets.";
        else if(!xx_rt_wcscmp(r->name,L"last_update"))s=L"Unix epoch seconds; PDP variants store the high little-endian halfword first.";
        else if(!xx_rt_wcscmp(r->name,L"state"))s=L"Clean-state encoding depends on System V release.";
        else if(!xx_rt_wcscmp(r->name,L"block_size_type"))s=L"1: 512 bytes; 2: 1024 bytes; 3: 2048 bytes.";
        break;
    case 0x603d001eU:
        if(!xx_rt_wcscmp(r->name,L"first_data_block"))s=L"First data block number; earlier blocks contain the inode table.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_cache"))s=L"Cached free block numbers, not byte offsets.";
        else if(!xx_rt_wcscmp(r->name,L"last_update"))s=L"Unix epoch seconds; PDP variants store the high little-endian halfword first.";
        else if(!xx_rt_wcscmp(r->name,L"clean"))s=L"0x46 indicates a cleanly unmounted filesystem.";
        else if(!xx_rt_wcscmp(r->name,L"block_size_type"))s=L"Block size is 256 shifted left by this value (1..3).";
        break;
    case 0x603d001fU:
        if(!xx_rt_wcscmp(r->name,L"first_data_block"))s=L"First data block number; earlier blocks contain the inode table.";
        else if(!xx_rt_wcscmp(r->name,L"free_block_cache"))s=L"Cached free block numbers, not byte offsets.";
        else if(!xx_rt_wcscmp(r->name,L"last_update"))s=L"Unix epoch seconds; PDP variants store the high little-endian halfword first.";
        else if(!xx_rt_wcscmp(r->name,L"clean"))s=L"0x46 indicates a cleanly unmounted filesystem.";
        else if(!xx_rt_wcscmp(r->name,L"block_size_type"))s=L"Block size is 256 shifted left by this value (1..3).";
        break;
    case 0x603d0020U:
        if(!xx_rt_wcscmp(r->name,L"mode"))s=L"Unix file type and permissions.";
        else if(!xx_rt_wcscmp(r->name,L"block_numbers"))s=L"Ten direct blocks, followed by single, double and triple indirect blocks.";
        else if(!xx_rt_wcscmp(r->name,L"access_time"))s=L"Unix epoch seconds.";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Unix epoch seconds.";
        else if(!xx_rt_wcscmp(r->name,L"inode_change_time"))s=L"Unix epoch seconds.";
        break;
    case 0x603d0021U:
        if(!xx_rt_wcscmp(r->name,L"mode"))s=L"Unix file type and permissions.";
        else if(!xx_rt_wcscmp(r->name,L"block_numbers"))s=L"Ten direct blocks, followed by single, double and triple indirect blocks.";
        else if(!xx_rt_wcscmp(r->name,L"access_time"))s=L"Unix epoch seconds.";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Unix epoch seconds.";
        else if(!xx_rt_wcscmp(r->name,L"inode_change_time"))s=L"Unix epoch seconds.";
        break;
    case 0x603d0022U:
        if(!xx_rt_wcscmp(r->name,L"mode"))s=L"Unix file type and permissions.";
        else if(!xx_rt_wcscmp(r->name,L"block_00_high"))s=L"High 8 bits of a packed 24-bit PDP block number.";
        else if(!xx_rt_wcscmp(r->name,L"block_00_low"))s=L"Low 16 bits, stored little-endian; not a complete block number alone.";
        else if(!xx_rt_wcscmp(r->name,L"block_01_high"))s=L"High 8 bits of a packed 24-bit PDP block number.";
        else if(!xx_rt_wcscmp(r->name,L"block_01_low"))s=L"Low 16 bits, stored little-endian; not a complete block number alone.";
        else if(!xx_rt_wcscmp(r->name,L"block_02_high"))s=L"High 8 bits of a packed 24-bit PDP block number.";
        else if(!xx_rt_wcscmp(r->name,L"block_02_low"))s=L"Low 16 bits, stored little-endian; not a complete block number alone.";
        else if(!xx_rt_wcscmp(r->name,L"block_03_high"))s=L"High 8 bits of a packed 24-bit PDP block number.";
        else if(!xx_rt_wcscmp(r->name,L"block_03_low"))s=L"Low 16 bits, stored little-endian; not a complete block number alone.";
        else if(!xx_rt_wcscmp(r->name,L"block_04_high"))s=L"High 8 bits of a packed 24-bit PDP block number.";
        else if(!xx_rt_wcscmp(r->name,L"block_04_low"))s=L"Low 16 bits, stored little-endian; not a complete block number alone.";
        else if(!xx_rt_wcscmp(r->name,L"block_05_high"))s=L"High 8 bits of a packed 24-bit PDP block number.";
        else if(!xx_rt_wcscmp(r->name,L"block_05_low"))s=L"Low 16 bits, stored little-endian; not a complete block number alone.";
        else if(!xx_rt_wcscmp(r->name,L"block_06_high"))s=L"High 8 bits of a packed 24-bit PDP block number.";
        else if(!xx_rt_wcscmp(r->name,L"block_06_low"))s=L"Low 16 bits, stored little-endian; not a complete block number alone.";
        else if(!xx_rt_wcscmp(r->name,L"block_07_high"))s=L"High 8 bits of a packed 24-bit PDP block number.";
        else if(!xx_rt_wcscmp(r->name,L"block_07_low"))s=L"Low 16 bits, stored little-endian; not a complete block number alone.";
        else if(!xx_rt_wcscmp(r->name,L"block_08_high"))s=L"High 8 bits of a packed 24-bit PDP block number.";
        else if(!xx_rt_wcscmp(r->name,L"block_08_low"))s=L"Low 16 bits, stored little-endian; not a complete block number alone.";
        else if(!xx_rt_wcscmp(r->name,L"block_09_high"))s=L"High 8 bits of a packed 24-bit PDP block number.";
        else if(!xx_rt_wcscmp(r->name,L"block_09_low"))s=L"Low 16 bits, stored little-endian; not a complete block number alone.";
        else if(!xx_rt_wcscmp(r->name,L"block_10_high"))s=L"High 8 bits of a packed 24-bit PDP block number.";
        else if(!xx_rt_wcscmp(r->name,L"block_10_low"))s=L"Low 16 bits, stored little-endian; not a complete block number alone.";
        else if(!xx_rt_wcscmp(r->name,L"block_11_high"))s=L"High 8 bits of a packed 24-bit PDP block number.";
        else if(!xx_rt_wcscmp(r->name,L"block_11_low"))s=L"Low 16 bits, stored little-endian; not a complete block number alone.";
        else if(!xx_rt_wcscmp(r->name,L"block_12_high"))s=L"High 8 bits of a packed 24-bit PDP block number.";
        else if(!xx_rt_wcscmp(r->name,L"block_12_low"))s=L"Low 16 bits, stored little-endian; not a complete block number alone.";
        else if(!xx_rt_wcscmp(r->name,L"access_time"))s=L"Unix epoch seconds.";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Unix epoch seconds.";
        else if(!xx_rt_wcscmp(r->name,L"inode_change_time"))s=L"Unix epoch seconds.";
        break;
    case 0x603d0025U:
        if(!xx_rt_wcscmp(r->name,L"first_free_block"))s=L"Head of the free-block chain, in filesystem blocks.";
        else if(!xx_rt_wcscmp(r->name,L"log_zone_size"))s=L"Native reader supports zero, i.e. 1024-byte zones.";
        break;
    case 0x603d0026U:
        if(!xx_rt_wcscmp(r->name,L"block_numbers"))s=L"Nine direct blocks, then single, double and triple indirect block numbers.";
        break;
    case 0x603d0028U:
        if(!xx_rt_wcscmp(r->name,L"zone_shift"))s=L"Zone byte size is 1024 shifted left by this value.";
        break;
    case 0x603d0029U:
        if(!xx_rt_wcscmp(r->name,L"encoded_zone_numbers"))s=L"Low 24 bits of each word hold a zone number. Upper bytes encode allocated-block accounting; these are not plain offsets.";
        break;
    case 0x603d002bU:
        if(!xx_rt_wcscmp(r->name,L"data_start"))s=L"Volume-relative byte offset of the first data block.";
        else if(!xx_rt_wcscmp(r->name,L"data_end"))s=L"Inclusive volume-relative byte offset of the last data byte.";
        else if(!xx_rt_wcscmp(r->name,L"compaction_from"))s=L"Block-number recovery state; 0xFFFFFFFF means inactive.";
        break;
    case 0x603d002cU:
        if(!xx_rt_wcscmp(r->name,L"end_offset"))s=L"Inclusive volume-relative byte offset of the file's last byte.";
        else if(!xx_rt_wcscmp(r->name,L"vnode_type"))s=L"1: regular file; 2: directory.";
        break;
    case 0x603d002dU:
        if(!xx_rt_wcscmp(r->name,L"first_extent_block"))s=L"One-based 512-byte block number.";
        else if(!xx_rt_wcscmp(r->name,L"extent_block"))s=L"One-based block number of the first extended-extent block.";
        else if(!xx_rt_wcscmp(r->name,L"status"))s=L"0x01 used; 0x02 modified; 0x04 busy; 0x08 link; 0x10 inode; 0x20 clean.";
        break;
    case 0x603d002eU:
        if(!xx_rt_wcscmp(r->name,L"inode_block"))s=L"One-based physical block number containing the target inode.";
        else if(!xx_rt_wcscmp(r->name,L"inode_index"))s=L"Zero-based slot within an eight-inode block.";
        break;
    case 0x603d0030U:
        if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"One-based 512-byte block number.";
        break;
    case 0x603d0032U:
        if(!xx_rt_wcscmp(r->name,L"block_count"))s=L"Number of 512-byte basic blocks.";
        else if(!xx_rt_wcscmp(r->name,L"first_cylinder_group"))s=L"Basic-block number.";
        break;
    case 0x603d0034U:
        if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"512-byte basic-block number.";
        else if(!xx_rt_wcscmp(r->name,L"logical_block"))s=L"Logical block position within the file, not a byte offset.";
        break;
    case 0x603d0035U:
        if(!xx_rt_wcscmp(r->name,L"first_free_word"))s=L"Word position, two bytes per word.";
        break;
    case 0x603d0037U:
        if(!xx_rt_wcscmp(r->name,L"first_directory_segment"))s=L"512-byte block number.";
        else if(!xx_rt_wcscmp(r->name,L"system_version_rad50"))s=L"RAD50-encoded version text, not an integer version.";
        break;
    case 0x603d0038U:
        if(!xx_rt_wcscmp(r->name,L"next_segment"))s=L"One-based segment index; zero ends the chain.";
        else if(!xx_rt_wcscmp(r->name,L"first_data_block"))s=L"512-byte block number.";
        break;
    case 0x603d0039U:
        if(!xx_rt_wcscmp(r->name,L"status"))s=L"0x0100 tentative; 0x0200 empty; 0x0400 permanent; 0x0800 end; 0x0010 prefix block.";
        else if(!xx_rt_wcscmp(r->name,L"filename_rad50_1"))s=L"Three characters encoded in RAD50.";
        else if(!xx_rt_wcscmp(r->name,L"length_blocks"))s=L"Number of 512-byte blocks.";
        else if(!xx_rt_wcscmp(r->name,L"job_channel"))s=L"Low byte job number; high byte channel number.";
        else if(!xx_rt_wcscmp(r->name,L"creation_date_encoded"))s=L"Packed RT-11 date; not a Unix timestamp.";
        break;
    case 0x603d003aU:
        if(!xx_rt_wcscmp(r->name,L"directory_block"))s=L"Directory location in 256-byte sectors.";
        else if(!xx_rt_wcscmp(r->name,L"creation_date_bcd"))s=L"Six BCD calendar components, not a scalar timestamp.";
        break;
    case 0x603d003bU:
        if(!xx_rt_wcscmp(r->name,L"type"))s=L"0xFFFF ends the directory; other values identify LIF file types.";
        else if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"256-byte sector number.";
        else if(!xx_rt_wcscmp(r->name,L"volume_number"))s=L"Volume number and last-volume flag.";
        else if(!xx_rt_wcscmp(r->name,L"implementation_defined"))s=L"Type-dependent implementation field.";
        break;
    case 0x603d003cU:
        if(!xx_rt_wcscmp(r->name,L"surface"))s=L"Space or '1': one surface; 'M': two surfaces.";
        else if(!xx_rt_wcscmp(r->name,L"record_length_code"))s=L"'1' selects the supported 128/256-byte sector geometry.";
        else if(!xx_rt_wcscmp(r->name,L"file_label_allocation"))s=L"'1' permits the extended label area on a two-sided medium.";
        break;
    case 0x603d003dU:
        if(!xx_rt_wcscmp(r->name,L"defective_cylinder_1"))s=L"Decimal encoded cylinder/side address; blank means absent.";
        break;
    case 0x603d003eU:
        if(!xx_rt_wcscmp(r->name,L"block_length_decimal"))s=L"Five decimal characters; blank encodes 256 bytes.";
        else if(!xx_rt_wcscmp(r->name,L"first_extent_chs"))s=L"Two decimal cylinder digits, side digit, two sector digits.";
        else if(!xx_rt_wcscmp(r->name,L"creation_date"))s=L"Encoded calendar date, not a scalar timestamp.";
        else if(!xx_rt_wcscmp(r->name,L"unused_tail_decimal"))s=L"Decimal count of unused bytes in the final block.";
        break;
    case 0x603d003fU:
        if(!xx_rt_wcscmp(r->name,L"version"))s=L"1: 4096-byte blocks and 512-byte inode slots; 2: 1024-byte blocks and 128-byte inode slots.";
        break;
    case 0x603d0040U:
        if(!xx_rt_wcscmp(r->name,L"version"))s=L"1: 4096-byte blocks and 512-byte inode slots; 2: 1024-byte blocks and 128-byte inode slots.";
        break;
    case 0x603d0041U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"0x02 data-valid; 0x10 inode-valid; 0x40 variable-length directory records; 0x80 symbolic link.";
        else if(!xx_rt_wcscmp(r->name,L"block_numbers"))s=L"Ten direct blocks, followed by single, double and triple indirect blocks.";
        break;
    case 0x603d0042U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"0x02 data-valid; 0x10 inode-valid; 0x40 variable-length directory records; 0x80 symbolic link.";
        else if(!xx_rt_wcscmp(r->name,L"block_numbers"))s=L"Ten direct blocks, followed by single, double and triple indirect blocks.";
        break;
    case 0x603d0043U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"0x02 data-valid; 0x10 inode-valid; 0x40 variable-length directory records; 0x80 symbolic link.";
        else if(!xx_rt_wcscmp(r->name,L"small_block_flags"))s=L"Bit 0 selects inline data at inode byte 128.";
        else if(!xx_rt_wcscmp(r->name,L"block_numbers"))s=L"Ten direct blocks, followed by single, double and triple indirect blocks.";
        break;
    case 0x603d0044U:
        if(!xx_rt_wcscmp(r->name,L"flags"))s=L"0x02 data-valid; 0x10 inode-valid; 0x40 variable-length directory records; 0x80 symbolic link.";
        else if(!xx_rt_wcscmp(r->name,L"small_block_flags"))s=L"Bit 0 selects inline data at inode byte 128.";
        else if(!xx_rt_wcscmp(r->name,L"block_numbers"))s=L"Ten direct blocks, followed by single, double and triple indirect blocks.";
        break;
    case 0x603d0047U:
        if(!xx_rt_wcscmp(r->name,L"datestamp"))s=L"Filesystem change sequence, not a Unix timestamp.";
        else if(!xx_rt_wcscmp(r->name,L"creation_day"))s=L"Days since 1978-01-01; one component of the Amiga date.";
        else if(!xx_rt_wcscmp(r->name,L"creation_minute"))s=L"Minutes since midnight.";
        else if(!xx_rt_wcscmp(r->name,L"creation_tick"))s=L"Ticks since the minute began, 50 ticks per second.";
        else if(!xx_rt_wcscmp(r->name,L"allocation_word"))s=L"Bitmap word index used as the allocation cursor.";
        break;
    case 0x603d004aU:
        if(!xx_rt_wcscmp(r->name,L"datestamp"))s=L"Filesystem change sequence.";
        break;
    case 0x603d004eU:
        if(!xx_rt_wcscmp(r->name,L"type"))s=L"2 directory, -3 regular file, 3 rolled file, -4 hard link.";
        else if(!xx_rt_wcscmp(r->name,L"file_size_low"))s=L"Low 32 bits; optional extended fields may supply the high 16 bits.";
        break;
    case 0x603d004fU:
        if(!xx_rt_wcscmp(r->name,L"root_date_components"))s=L"Days since 1978-01-01, minutes, 1/50-second ticks.";
        break;
    case 0x603d0051U:
        if(!xx_rt_wcscmp(r->name,L"revision_high"))s=L"High word of the stored format revision.";
        break;
    case 0x603d0054U:
        if(!xx_rt_wcscmp(r->name,L"level"))s=L"Zero for a DATA leaf; positive for an INDX node.";
        break;
    case 0x603d0056U:
        if(!xx_rt_wcscmp(r->name,L"record_type"))s=L"0x20 live, 0x60 deleted.";
        else if(!xx_rt_wcscmp(r->name,L"attributes"))s=L"Bit 4 identifies a directory.";
        break;
    case 0x603d0057U:
        if(!xx_rt_wcscmp(r->name,L"home_lbn"))s=L"Logical block numbers use 512-byte blocks.";
        else if(!xx_rt_wcscmp(r->name,L"structure_level"))s=L"High byte 2 or 5 is the filesystem level; low byte is revision.";
        else if(!xx_rt_wcscmp(r->name,L"home_vbn"))s=L"Virtual block number within the file.";
        else if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"VMS 100-nanosecond ticks since 1858-11-17.";
        else if(!xx_rt_wcscmp(r->name,L"minimum_retention"))s=L"VMS interval-time encoding; not an absolute timestamp.";
        else if(!xx_rt_wcscmp(r->name,L"revision_time"))s=L"VMS 100-nanosecond ticks since 1858-11-17.";
        else if(!xx_rt_wcscmp(r->name,L"copy_time"))s=L"VMS 100-nanosecond ticks since 1858-11-17.";
        break;
    case 0x603d0058U:
        if(!xx_rt_wcscmp(r->name,L"identification_word_offset"))s=L"Offset in 16-bit words from the file header, not a byte offset.";
        else if(!xx_rt_wcscmp(r->name,L"record_type_organization"))s=L"Low nibble record type, high nibble file organization.";
        else if(!xx_rt_wcscmp(r->name,L"allocated_block_high"))s=L"High 16 bits of allocated virtual block count; not a complete count alone.";
        else if(!xx_rt_wcscmp(r->name,L"eof_block_high"))s=L"High 16 bits of one-based EOF virtual block number.";
        else if(!xx_rt_wcscmp(r->name,L"first_free_byte"))s=L"Byte position within the EOF block, not a volume offset.";
        else if(!xx_rt_wcscmp(r->name,L"mapping_words"))s=L"Count of 16-bit words, not bytes.";
        break;
    case 0x603d005aU:
        if(!xx_rt_wcscmp(r->name,L"placement_word"))s=L"Top two bits 0; remaining bits are placement-control data.";
        break;
    case 0x603d005bU:
        if(!xx_rt_wcscmp(r->name,L"blocks_minus_one"))s=L"Encoded extent block count minus one.";
        else if(!xx_rt_wcscmp(r->name,L"format_and_lbn_high"))s=L"Top two bits 1; lower six bits are high LBN bits.";
        break;
    case 0x603d005cU:
        if(!xx_rt_wcscmp(r->name,L"format_and_blocks_minus_one"))s=L"Top two bits 2; low 14 bits are extent count minus one.";
        break;
    case 0x603d005dU:
        if(!xx_rt_wcscmp(r->name,L"format_and_count_high"))s=L"Top two bits 3; low 14 bits are high bits of extent count minus one.";
        break;
    case 0x603d005eU:
        if(!xx_rt_wcscmp(r->name,L"following_record_size"))s=L"Byte length after this size word.";
        else if(!xx_rt_wcscmp(r->name,L"flags_and_name_encoding"))s=L"Bits 3..5 name encoding; low bits flags.";
        break;
    case 0x603d0060U:
        if(!xx_rt_wcscmp(r->name,L"block_count"))s=L"Filesystem blocks contain 4096 bytes (512 Cray words).";
        else if(!xx_rt_wcscmp(r->name,L"root_inode"))s=L"Packed partition, region and relative inode number.";
        break;
    case 0x603d0061U:
        if(!xx_rt_wcscmp(r->name,L"device_name"))s=L"Packed device name.";
        break;
    case 0x603d0062U:
        if(!xx_rt_wcscmp(r->name,L"io_unit"))s=L"Physical I/O unit encoding; preserve stored units.";
        else if(!xx_rt_wcscmp(r->name,L"inode_reservation_blocks_minus_one"))s=L"Number of inode reservation allocation units minus one.";
        else if(!xx_rt_wcscmp(r->name,L"primary_block_words_minus_one"))s=L"Primary allocation unit is (value + 1) times 512 Cray words.";
        else if(!xx_rt_wcscmp(r->name,L"secondary_block_words_minus_one"))s=L"Secondary allocation unit is (value + 1) times 512 Cray words.";
        break;
    case 0x603d0063U:
        if(!xx_rt_wcscmp(r->name,L"mode_encoded"))s=L"Low 24 bits contain Unix mode; high byte is retained encoded.";
        else if(!xx_rt_wcscmp(r->name,L"links_encoded"))s=L"Low 17 bits contain link count; remaining bits retained encoded.";
        else if(!xx_rt_wcscmp(r->name,L"allocation_device_flags"))s=L"Native reader supports low five bits zero (local-device allocation).";
        else if(!xx_rt_wcscmp(r->name,L"allocation_type_flags"))s=L"Low nibble 1 selects direct extents supported by the native reader.";
        break;
    case 0x603d0064U:
        if(!xx_rt_wcscmp(r->name,L"blocks_encoded"))s=L"Low 31 bits are a block count; high bit marks an unsupported allocation variant.";
        break;
    case 0x603d0065U:
        if(!xx_rt_wcscmp(r->name,L"external_device"))s=L"Native reader requires zero.";
        break;
    case 0x603d0066U:
        if(!xx_rt_wcscmp(r->name,L"record_and_name_lengths"))s=L"Bits 10..31: record byte size; bits 0..9: name byte length; upper bits retained encoded.";
        break;
    case 0x603d0067U:
        if(!xx_rt_wcscmp(r->name,L"block_shift"))s=L"Base-two logarithm of block byte size.";
        else if(!xx_rt_wcscmp(r->name,L"allocation_group_shift"))s=L"Base-two logarithm of allocation-group block count.";
        else if(!xx_rt_wcscmp(r->name,L"log_start_block"))s=L"Start block within allocation group.";
        else if(!xx_rt_wcscmp(r->name,L"log_start"))s=L"Journal block position; not a byte offset.";
        else if(!xx_rt_wcscmp(r->name,L"log_end"))s=L"Journal block position.";
        else if(!xx_rt_wcscmp(r->name,L"root_start_block"))s=L"Block index within its allocation group.";
        else if(!xx_rt_wcscmp(r->name,L"indices_start_block"))s=L"Block index within its allocation group.";
        else if(!xx_rt_wcscmp(r->name,L"boot_padding"))s=L"Remaining superblock/boot-block bytes.";
        break;
    case 0x603d0068U:
        if(!xx_rt_wcscmp(r->name,L"block_shift"))s=L"Base-two logarithm of block byte size.";
        else if(!xx_rt_wcscmp(r->name,L"allocation_group_shift"))s=L"Base-two logarithm of allocation-group block count.";
        else if(!xx_rt_wcscmp(r->name,L"log_start_block"))s=L"Start block within allocation group.";
        else if(!xx_rt_wcscmp(r->name,L"log_start"))s=L"Journal block position; not a byte offset.";
        else if(!xx_rt_wcscmp(r->name,L"log_end"))s=L"Journal block position.";
        else if(!xx_rt_wcscmp(r->name,L"root_start_block"))s=L"Block index within its allocation group.";
        else if(!xx_rt_wcscmp(r->name,L"indices_start_block"))s=L"Block index within its allocation group.";
        else if(!xx_rt_wcscmp(r->name,L"boot_padding"))s=L"Remaining superblock/boot-block bytes.";
        break;
    case 0x603d0069U:
        if(!xx_rt_wcscmp(r->name,L"creation_time_encoded"))s=L"High 48 bits hold Unix seconds; low 16 bits contain subsecond/unique bits.";
        else if(!xx_rt_wcscmp(r->name,L"modification_time_encoded"))s=L"High 48 bits hold Unix seconds; low 16 bits contain subsecond/unique bits.";
        else if(!xx_rt_wcscmp(r->name,L"etc"))s=L"Implementation-dependent stored word.";
        break;
    case 0x603d006aU:
        if(!xx_rt_wcscmp(r->name,L"creation_time_encoded"))s=L"High 48 bits hold Unix seconds; low 16 bits contain subsecond/unique bits.";
        else if(!xx_rt_wcscmp(r->name,L"modification_time_encoded"))s=L"High 48 bits hold Unix seconds; low 16 bits contain subsecond/unique bits.";
        else if(!xx_rt_wcscmp(r->name,L"etc"))s=L"Implementation-dependent stored word.";
        break;
    case 0x603d006bU:
        if(!xx_rt_wcscmp(r->name,L"block_shift"))s=L"Base-two logarithm of block byte size.";
        else if(!xx_rt_wcscmp(r->name,L"allocation_group_shift"))s=L"Base-two logarithm of allocation-group block count.";
        else if(!xx_rt_wcscmp(r->name,L"log_start_block"))s=L"Start block within allocation group.";
        else if(!xx_rt_wcscmp(r->name,L"log_start"))s=L"Journal block position; not a byte offset.";
        else if(!xx_rt_wcscmp(r->name,L"log_size"))s=L"Log blocks.";
        else if(!xx_rt_wcscmp(r->name,L"root_start_block"))s=L"Block index within its allocation group.";
        else if(!xx_rt_wcscmp(r->name,L"deleted_start_block"))s=L"Block index within its allocation group.";
        else if(!xx_rt_wcscmp(r->name,L"indices_start_block"))s=L"Block index within its allocation group.";
        break;
    case 0x603d006cU:
        if(!xx_rt_wcscmp(r->name,L"block_shift"))s=L"Base-two logarithm of block byte size.";
        else if(!xx_rt_wcscmp(r->name,L"allocation_group_shift"))s=L"Base-two logarithm of allocation-group block count.";
        else if(!xx_rt_wcscmp(r->name,L"log_start_block"))s=L"Start block within allocation group.";
        else if(!xx_rt_wcscmp(r->name,L"log_start"))s=L"Journal block position; not a byte offset.";
        else if(!xx_rt_wcscmp(r->name,L"log_size"))s=L"Log blocks.";
        else if(!xx_rt_wcscmp(r->name,L"root_start_block"))s=L"Block index within its allocation group.";
        else if(!xx_rt_wcscmp(r->name,L"deleted_start_block"))s=L"Block index within its allocation group.";
        else if(!xx_rt_wcscmp(r->name,L"indices_start_block"))s=L"Block index within its allocation group.";
        break;
    case 0x603d006dU:
        if(!xx_rt_wcscmp(r->name,L"creation_time_encoded"))s=L"Microseconds since Unix epoch.";
        else if(!xx_rt_wcscmp(r->name,L"modification_time_encoded"))s=L"Microseconds since Unix epoch.";
        else if(!xx_rt_wcscmp(r->name,L"stored_vnode_pointer"))s=L"Stored in-memory pointer slot; has no portable on-disk meaning.";
        break;
    case 0x603d006eU:
        if(!xx_rt_wcscmp(r->name,L"creation_time_encoded"))s=L"Microseconds since Unix epoch.";
        else if(!xx_rt_wcscmp(r->name,L"modification_time_encoded"))s=L"Microseconds since Unix epoch.";
        else if(!xx_rt_wcscmp(r->name,L"stored_vnode_pointer"))s=L"Stored in-memory pointer slot; has no portable on-disk meaning.";
        break;
    case 0x603d006fU:
        if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"Start block within the allocation group.";
        break;
    case 0x603d0070U:
        if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"Start block within the allocation group.";
        break;
    case 0x603d0071U:
        if(!xx_rt_wcscmp(r->name,L"maximum_direct_range"))s=L"Logical byte range covered by direct block runs.";
        break;
    case 0x603d0072U:
        if(!xx_rt_wcscmp(r->name,L"maximum_direct_range"))s=L"Logical byte range covered by direct block runs.";
        break;
    case 0x603d0073U:
        if(!xx_rt_wcscmp(r->name,L"status_change_or_reserved"))s=L"Haiku status-change time encoding; this word was reserved in older BeOS inodes. Not decoded as Unix seconds.";
        break;
    case 0x603d0074U:
        if(!xx_rt_wcscmp(r->name,L"status_change_or_reserved"))s=L"Haiku status-change time encoding; this word was reserved in older BeOS inodes. Not decoded as Unix seconds.";
        break;
    case 0x603d0077U:
        if(!xx_rt_wcscmp(r->name,L"root_node"))s=L"Logical byte offset within the directory data stream.";
        else if(!xx_rt_wcscmp(r->name,L"free_node"))s=L"Logical byte offset; -1 denotes no free node.";
        break;
    case 0x603d0078U:
        if(!xx_rt_wcscmp(r->name,L"root_node"))s=L"Logical byte offset within the directory data stream.";
        else if(!xx_rt_wcscmp(r->name,L"free_node"))s=L"Logical byte offset; -1 denotes no free node.";
        break;
    case 0x603d0079U:
        if(!xx_rt_wcscmp(r->name,L"root_node"))s=L"Logical byte offset within the directory data stream.";
        else if(!xx_rt_wcscmp(r->name,L"last_node"))s=L"Logical byte offset within the directory stream.";
        else if(!xx_rt_wcscmp(r->name,L"first_free_node"))s=L"Logical byte offset; -1 denotes none.";
        break;
    case 0x603d007aU:
        if(!xx_rt_wcscmp(r->name,L"root_node"))s=L"Logical byte offset within the directory data stream.";
        else if(!xx_rt_wcscmp(r->name,L"last_node"))s=L"Logical byte offset within the directory stream.";
        else if(!xx_rt_wcscmp(r->name,L"first_free_node"))s=L"Logical byte offset; -1 denotes none.";
        break;
    case 0x603d007bU:
        if(!xx_rt_wcscmp(r->name,L"left_node"))s=L"Logical byte offset within the directory stream; -1 means none.";
        break;
    case 0x603d007cU:
        if(!xx_rt_wcscmp(r->name,L"left_node"))s=L"Logical byte offset within the directory stream; -1 means none.";
        break;
    case 0x603d007dU:
        if(!xx_rt_wcscmp(r->name,L"left_node"))s=L"Logical byte offset within the directory stream; -1 means none.";
        break;
    case 0x603d007eU:
        if(!xx_rt_wcscmp(r->name,L"left_node"))s=L"Logical byte offset within the directory stream; -1 means none.";
        break;
    case 0x603d0080U:
        if(!xx_rt_wcscmp(r->name,L"end_offset"))s=L"Cumulative byte position in the node key-data area.";
        break;
    case 0x603d0081U:
        if(!xx_rt_wcscmp(r->name,L"end_offset"))s=L"Cumulative byte position in the node key-data area.";
        break;
    case 0x603d0082U:
        if(!xx_rt_wcscmp(r->name,L"inode_or_node"))s=L"Leaf: inode block number; internal node: logical byte offset in the directory stream.";
        break;
    case 0x603d0083U:
        if(!xx_rt_wcscmp(r->name,L"inode_or_node"))s=L"Leaf: inode block number; internal node: logical byte offset in the directory stream.";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Every coordinate is relative to the borrowed volume base.  No native
 * subclass state, host mounts, or journal replay is required.  Display caps
 * retain validated earlier records; undecoded metadata and payload stay raw. */
#define SXCF_LIMIT 24000U
#define SXCF_INODES 262144U
static bool sxcf_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxcf_read(sx_context*c,uint64_t p,void*b,size_t n){return !xx_pd_is_stopped(c->pd)&&sxcf_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint16_t sxcf16(const uint8_t*b,unsigned o){return o==1?(uint16_t)((uint16_t)b[0]<<8|b[1]):(uint16_t)((uint16_t)b[1]<<8|b[0]);}
static uint32_t sxcf32(const uint8_t*b,unsigned o){if(o==2)return (uint32_t)sxcf16(b,0)<<16|sxcf16(b+2,0);return o==1?(uint32_t)sxcf16(b,1)<<16|sxcf16(b+2,1):(uint32_t)sxcf16(b+2,0)<<16|sxcf16(b,0);}
static uint64_t sxcf64(const uint8_t*b,unsigned o){return o==1?(uint64_t)sxcf32(b,1)<<32|sxcf32(b+4,1):(uint64_t)sxcf32(b+4,0)<<32|sxcf32(b,0);}
static uint32_t sxcf24(const uint8_t*b,unsigned o){return o==2?(uint32_t)b[0]<<16|sxcf16(b+1,0):o==1?(uint32_t)b[0]<<16|(uint32_t)b[1]<<8|b[2]:(uint32_t)b[2]<<16|(uint32_t)b[1]<<8|b[0];}
static bool sxcf_pow(uint64_t v){return v&&!(v&(v-1));}
static bool sxcf_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 if(!n)return true;const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(n>1048576U||n>UINT64_MAX/z||!sxcf_span(c,p,n*z)||xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXCF_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&(uint64_t)(c->items[lo-1].offset-c->f->base_address)+(uint64_t)c->items[lo-1].total_size>p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}return true;
}
#define SXCF_ADD(c,l,p) sxcf_put(c,&sxcf_##l,p,1)
#define SXCF_TABLE(c,l,p,n) sxcf_put(c,&sxcf_##l,p,n)
#define SXCF_ORDER(l,o) ((o)==1?&sxcf_##l##_be:&sxcf_##l##_le)
#define SXCF_UNIX(l,o) ((o)==2?&sxcf_##l##_pdp:SXCF_ORDER(l,o))
/* Directory entry prefixes and fixed slots are emitted only inside the
 * physical blocks authenticated by an allocated directory inode. */
static bool sxcf_dir(sx_context*c,uint64_t p,uint64_t n,unsigned kind,unsigned o,unsigned width){
 uint8_t b[512];if(!sxcf_span(c,p,n))return false;
 if(kind==0)return sxcf_put(c,SXCF_ORDER(unix_directory,o),p,n/16);
 if(kind==1)return sxcf_put(c,width==64?SXCF_ORDER(minix3_directory,o):width==16?SXCF_ORDER(minix_directory_14,o):SXCF_ORDER(minix_directory_30,o),p,n/width);
 if(kind==2||kind==3){uint64_t q=0;unsigned head=kind==2?8:7;
  while(q+head<=n&&c->count<SXCF_LIMIT){if(!sxcf_read(c,p+q,b,head))return false;unsigned z=sxcf16(b+4,0),len=kind==2?sxcf16(b+6,0):b[6];if(z<head||z>n-q||len>z-head)break;if(!sxcf_put(c,kind==2?&sxcf_linux_ext_directory_header:&sxcf_xia_directory_header,p+q,1))return false;q+=z;}return true;
 }
 if(kind==4){for(uint64_t q=0;q+64<=n&&c->count<SXCF_LIMIT;q+=64){if(!sxcf_read(c,p+q,b,64))return false;if(!(b[63]&9))continue;if(!sxcf_put(c,(b[63]&8)?&sxcf_qnx4_link:&sxcf_qnx4_inode,p+q,1))return false;}return true;}
 if(kind==5){for(uint64_t q=0;q+512<=n&&c->count<SXCF_LIMIT;q+=512){if(!sxcf_read(c,p+q,b,512))return false;if(sxcf16(b,1)!=0xbeef||b[3]>255)break;if(!SXCF_ADD(c,efs_directory_header,p+q))return false;for(unsigned i=0;i<b[3]&&4+i<512;i++){unsigned at=(unsigned)b[4+i]*2;if(at<4+b[3]||at>507||b[at+4]>512-at-5)continue;if(!SXCF_ADD(c,efs_directory_entry,p+q+at))return false;}}return true;}
 return true;
}
/* Follow block pointers only to disclose physical directory records. The
 * pointer blocks themselves are genuine fixed-width metadata tables. */
typedef struct sxcf_map {sx_context*c;uint64_t blocks,unit,pointer_unit,left;unsigned order,pointer,kind,width,visits;uint64_t ancestors[4];} sxcf_map;
static bool sxcf_pointer(sxcf_map*g,uint64_t nr,unsigned depth){
 if(!g->left)return true;if(++g->visits>4096||g->c->count>=SXCF_LIMIT){g->left=0;return true;}
 if(!nr){uint64_t capacity=g->unit;for(unsigned i=0;i<depth;i++){uint64_t slots=g->pointer_unit/g->pointer;if(capacity>UINT64_MAX/slots){capacity=UINT64_MAX;break;}capacity*=slots;}g->left-=g->left<capacity?g->left:capacity;return true;}
 if(nr>=g->blocks||depth>3)return false;uint64_t p=nr*g->unit;if(!sxcf_span(g->c,p,depth?g->pointer_unit:g->unit))return false;
 if(!depth){uint64_t n=g->left<g->unit?g->left:g->unit;if(!sxcf_dir(g->c,p,n,g->kind,g->order,g->width))return false;g->left-=n;return true;}
 for(unsigned i=depth;i<4;i++)if(g->ancestors[i]==nr)return false;g->ancestors[depth]=nr;
 const sx_layout*l=g->pointer==2?SXCF_ORDER(classic_block_number16,g->order):g->order==2?&sxcf_classic_block_number_pdp:SXCF_ORDER(classic_block_number32,g->order);
 if(!sxcf_put(g->c,l,p,g->pointer_unit/g->pointer))return false;
 for(uint64_t i=0;i<g->pointer_unit/g->pointer&&g->left;i++){uint8_t b[4];if(!sxcf_read(g->c,p+i*g->pointer,b,g->pointer))return false;uint32_t ptr=g->pointer==2?sxcf16(b,g->order):sxcf32(b,g->order);if(g->kind==3)ptr&=0xffffff;if(!sxcf_pointer(g,ptr,depth-1))return false;}
 g->ancestors[depth]=0;return true;
}
static bool sxcf_minix(sx_context*c){
 uint8_t h[32],b[64];if(!sxcf_read(c,1024,h,32))return false;unsigned o=0,v=0,names=0;uint32_t imap,zmap,first,shift,bs=1024,ninodes,zones;
 for(o=0;o<2;o++){uint16_t m=sxcf16(h+16,o);if(m==0x137f||m==0x138f||m==0x2468||m==0x2478){v=(m==0x137f||m==0x138f)?1:2;names=(m==0x137f||m==0x2468)?14:30;break;}if(sxcf16(h+24,o)==0x4d5a){v=3;names=60;break;}}
 if(!v)return false;
 if(v<3){ninodes=sxcf16(h,o);imap=sxcf16(h+4,o);zmap=sxcf16(h+6,o);first=sxcf16(h+8,o);shift=sxcf16(h+10,o);zones=v==1?sxcf16(h+2,o):sxcf32(h+20,o);if(sxcf16(h+18,o)>3)return false;}
 else{ninodes=sxcf32(h,o);imap=sxcf16(h+6,o);zmap=sxcf16(h+8,o);first=sxcf16(h+10,o);shift=sxcf16(h+12,o);zones=sxcf32(h+20,o);bs=sxcf16(h+28,o);if(bs<1024||bs>32768||!sxcf_pow(bs))return false;}
 unsigned isize=v==1?32:64;uint64_t table=(2+(uint64_t)imap+zmap)*bs,blocks=((uint64_t)ninodes*isize+bs-1)/bs;
 if(!ninodes||!imap||!zmap||!zones||shift>4||first>=zones||first!=((2+(uint64_t)imap+zmap+blocks+((UINT64_C(1)<<shift)-1))>>shift)||!sxcf_span(c,0,(uint64_t)zones*(bs<<shift))||!sxcf_span(c,table,(uint64_t)ninodes*isize))return false;
 if(!sxcf_put(c,v==1?SXCF_ORDER(minix1_superblock,o):v==2?SXCF_ORDER(minix2_superblock,o):SXCF_ORDER(minix3_superblock,o),1024,1)||!sxcf_put(c,v==1?SXCF_ORDER(minix1_inode,o):SXCF_ORDER(minix23_inode,o),table,ninodes<SXCF_INODES?ninodes:SXCF_INODES))return false;
 for(uint32_t i=0;i<ninodes&&i<SXCF_INODES&&c->count<SXCF_LIMIT;i++){if(!sxcf_read(c,table+(uint64_t)i*isize,b,isize))return false;if((sxcf16(b,o)&0xf000)!=0x4000)continue;
  sxcf_map g={c,zones,(uint64_t)bs<<shift,bs,sxcf32(b+(v==1?4:8),o),o,v==1?2U:4U,1,names+(v==3?4:2),0,{0}};
  unsigned off=v==1?14:24,ptrs=v==1?9:10;for(unsigned k=0;k<ptrs&&g.left;k++){uint32_t ptr=v==1?sxcf16(b+off+k*2,o):sxcf32(b+off+k*4,o);if(!sxcf_pointer(&g,ptr,k<7?0:k-6))break;}
 }
 return true;
}
static bool sxcf_classic(sx_context*c){
 uint8_t h[1024],b[128];unsigned o=0,kind=0;uint64_t sb=0,bs=512,blocks=0,table=1024,nodes=0,first=0;const sx_layout*super=NULL;xx_file_type_t type=c->f->file_type;
 if(type==XX_FILE_TYPE_LINUX_EXT){sb=1024;if(!sxcf_read(c,sb,h,60)||sxcf16(h+56,0)!=0x137d)return false;bs=1024;blocks=sxcf32(h+4,0);nodes=sxcf32(h,0);first=sxcf32(h+24,0);table=2048;kind=2;super=&sxcf_linux_ext_superblock;if(sxcf32(h+28,0))return false;}
 else if(type==XX_FILE_TYPE_XIA_FS){if(!sxcf_read(c,512,h,64)||sxcf32(h+60,0)!=0x012fd16d)return false;sb=512;bs=sxcf32(h,0);blocks=sxcf32(h+4,0);nodes=sxcf32(h+8,0);first=sxcf32(h+24,0);if(bs<1024||bs>4096||!sxcf_pow(bs)||sxcf32(h+28,0)>2||bs!=(1024U<<sxcf32(h+28,0)))return false;table=(1+(uint64_t)sxcf32(h+16,0)+sxcf32(h+20,0))*bs;kind=3;super=&sxcf_xia_superblock;}
 else if(type==XX_FILE_TYPE_UNIX_BFS){if(!sxcf_read(c,0,h,512)||sxcf32(h,0)!=0x1badface)return false;uint64_t start=sxcf32(h+4,0),end=sxcf32(h+8,0);if(start<512||(start&511)||(end&511)!=511||end<start)return false;first=start/512;blocks=(end+1)/512;table=512;nodes=(start-512)/64;kind=6;super=&sxcf_unix_bfs_superblock;}
 else{
  bool found=false;for(sb=0;sb<=15*512;sb+=512){if(!sxcf_read(c,sb,h,1024))continue;
   if(type==XX_FILE_TYPE_COHERENT_FS){if((!xx_rt_memcmp(h+484,"noname",6)&&!xx_rt_memcmp(h+490,"nopack",6))||(!xx_rt_memcmp(h+484,"xxxxx",5)&&!xx_rt_memcmp(h+490,"xxxxx",5))){o=2;super=&sxcf_coherent_superblock_pdp;found=true;break;}}
   else if(type==XX_FILE_TYPE_UNIX_V7){if(!sxcf_read(c,1088,b,64))continue;for(o=0;o<3;o++){blocks=sxcf32(h+2,o);first=sxcf16(h,o);uint32_t n=sxcf32(b+8,o);if(blocks&&blocks<=0xffffff&&first>=3&&first<blocks&&blocks<=(uint64_t)c->size/512&&sxcf16(h+6,o)<=50&&sxcf16(h+208,o)<=100&&(sxcf16(b,o)&0xf000)==0x4000&&sxcf16(b+2,o)&&n>=32&&n<=16384&&!(n&15)){super=SXCF_UNIX(v7_superblock,o);found=true;break;}}if(found)break;}
   else{unsigned m=type==XX_FILE_TYPE_XENIX_FS?1016:504;uint32_t magic=type==XX_FILE_TYPE_XENIX_FS?0x002b5544:0xfd187e20;
    if(type==XX_FILE_TYPE_SYSV_FS&&sxcf32(h+m,0)!=magic&&sxcf32(h+m,1)!=magic)m=1016;
    for(o=0;o<2;o++)if(sxcf32(h+m,o)==magic)break;if(o==2)continue;
    if(type==XX_FILE_TYPE_SYSV_FS&&m==1016){sb+=512;xx_rt_memmove(h,h+512,512);m=504;}
    unsigned t=sxcf32(h+m+4,o);if(t<1||t>3)return false;bs=256U<<t;first=sxcf16(h,o);blocks=sxcf32(h+2,o);
    if(type==XX_FILE_TYPE_SYSV_FS){uint64_t aligned=sxcf32(h+4,o);bool a=first>=2&&first<aligned,p=first>=2&&first<blocks;
     bool use_a=a&&(!p||sxcf32(h+420,o)>=315532800U);if(use_a)blocks=aligned;super=use_a?SXCF_ORDER(sysv4_superblock,o):SXCF_ORDER(sysv2_superblock,o);
    }else super=SXCF_ORDER(xenix_superblock,o);found=true;break;
   }
  }
  if(!found)return false;if(type==XX_FILE_TYPE_COHERENT_FS||type==XX_FILE_TYPE_UNIX_V7){blocks=sxcf32(h+2,o);first=sxcf16(h,o);}table=2*bs;if(first<2)return false;nodes=(first-2)*(bs/64);
 }
 if(!sxcf_put(c,super,sb,1))return false;
 /* Identity may be valid even when unused tail blocks are absent. Keep the
  * physical superblock and inspect only a completely present inode table. */
 if(!blocks||!nodes||first<2||first>=blocks||!sxcf_span(c,table,nodes*64)||table+nodes*64>first*bs)return true;
 const sx_layout*il=kind==2?&sxcf_linux_ext_inode:kind==3?&sxcf_xia_inode:kind==6?&sxcf_unix_bfs_inode:SXCF_UNIX(unix_inode,o);
 if(!sxcf_put(c,il,table,nodes<SXCF_INODES?nodes:SXCF_INODES))return false;
 for(uint64_t i=0;i<nodes&&i<SXCF_INODES&&c->count<SXCF_LIMIT;i++){if(!sxcf_read(c,table+i*64,b,64))return false;
  if(kind==6){if(sxcf32(b+16,0)!=2)continue;uint64_t start=sxcf32(b+4,0),end=sxcf32(b+12,0);if(start&&start<blocks&&end>=start*512&&end<(uint64_t)c->size&&!sxcf_dir(c,start*512,end+1-start*512,0,0,16))return false;continue;}
  if((sxcf16(b,o)&0xf000)!=0x4000)continue;sxcf_map g={c,blocks,bs,bs,sxcf32(b+(kind==2?4:8),o),o,4,kind,16,0,{0}};
  unsigned direct=kind==2?9:kind==3?8:10,total=kind==3?10:kind==2?12:13;
  for(unsigned k=0;k<total&&g.left;k++){uint32_t nr=kind==2?sxcf32(b+16+4*k,0):kind==3?sxcf32(b+24+4*k,0)&0xffffff:sxcf24(b+12+3*k,o);if(!sxcf_pointer(&g,nr,k<direct?0:k-direct+1))break;}
 }
 return true;
}
static bool sxcf_qnx_inode(sx_context*c,uint64_t at,uint64_t blocks,unsigned depth,unsigned*visits);
static bool sxcf_qnx_extent(sx_context*c,uint32_t block,uint32_t count,uint64_t*left,bool dir,uint64_t blocks,unsigned depth,unsigned*visits){
 if(!*left)return true;if(!block||block-1>=blocks||count>blocks-(block-1))return false;uint64_t p=(uint64_t)(block-1)*512,n=(uint64_t)count*512;if(n>*left)n=*left;
 if(dir){for(uint64_t q=0;q+64<=n&&*visits<4096&&c->count<SXCF_LIMIT;q+=64){uint8_t b[64];if(!sxcf_read(c,p+q,b,64))return false;if(!(b[63]&9))continue;
  if((b[0]=='.'&&!b[1])||(b[0]=='.'&&b[1]=='.'&&!b[2]))continue;
  if(b[63]&8){if(!SXCF_ADD(c,qnx4_link,p+q))return false;uint32_t nr=sxcf32(b+48,0);if(nr&&nr<=blocks&&b[52]<8&&!sxcf_qnx_inode(c,(uint64_t)(nr-1)*512+(uint64_t)b[52]*64,blocks,depth+1,visits))return false;}
  else if(!sxcf_qnx_inode(c,p+q,blocks,depth+1,visits))return false;
 }}*left-=n;return true;
}
static bool sxcf_qnx_inode(sx_context*c,uint64_t at,uint64_t blocks,unsigned depth,unsigned*visits){
 uint8_t b[512];if(depth>24||++*visits>4096||c->count>=SXCF_LIMIT)return true;if(!sxcf_read(c,at,b,64))return false;if(!(b[63]&1))return true;
 if(!SXCF_ADD(c,qnx4_inode,at))return false;uint64_t left=sxcf32(b+16,0);bool dir=(sxcf16(b+50,0)&0xf000)==0x4000;uint32_t next=sxcf32(b+28,0);
 if(!sxcf_qnx_extent(c,sxcf32(b+20,0),sxcf32(b+24,0),&left,dir,blocks,depth,visits))return true;
 for(unsigned k=0;left&&next&&k<4096&&c->count<SXCF_LIMIT;k++){
  if(next>blocks||!sxcf_read(c,(uint64_t)(next-1)*512,b,512)||b[8]>60)break;uint64_t p=(uint64_t)(next-1)*512;uint32_t following=sxcf32(b,0);
  if(!SXCF_ADD(c,qnx4_extent_block_header,p)||!SXCF_TABLE(c,qnx4_extent,p+16,60)||!SXCF_ADD(c,qnx4_extent_block_tail,p+496))return false;
  for(unsigned i=0;i<b[8]&&left;i++)if(!sxcf_qnx_extent(c,sxcf32(b+16+8*i,0),sxcf32(b+20+8*i,0),&left,dir,blocks,depth,visits))return true;
  if(following==next)break;next=following;
 }return true;
}
static bool sxcf_qnx(sx_context*c){uint8_t b[256];if(!sxcf_read(c,512,b,256)||b[0]!='/'||b[1]||(sxcf16(b+50,0)&0xf000)!=0x4000)return false;if(!SXCF_TABLE(c,qnx4_inode,512,4))return false;unsigned visits=0;return sxcf_qnx_inode(c,512,(uint64_t)c->size/512,0,&visits);}
static bool sxcf_efs(sx_context*c){
 uint8_t h[92],b[128];if(!sxcf_read(c,512,h,92)||(sxcf32(h+28,1)!=0x72959&&sxcf32(h+28,1)!=0x7295a))return false;
 uint64_t blocks=sxcf32(h,1),first=sxcf32(h+4,1),group=sxcf32(h+8,1),ib=sxcf16(h+12,1),groups=sxcf16(h+18,1);
 if(!blocks||!group||!ib||!groups||ib>=group||first>=blocks||groups>(blocks-first)/group||!sxcf_span(c,0,blocks*512)||!SXCF_ADD(c,efs_superblock,512))return false;
 unsigned visits=0;for(uint64_t cg=0;cg<groups&&visits<SXCF_INODES&&c->count<SXCF_LIMIT;cg++)for(uint64_t i=0;i<ib*4&&visits<SXCF_INODES&&c->count<SXCF_LIMIT;i++,visits++){
  uint64_t p=(first+cg*group)*512+i*128;if(!sxcf_read(c,p,b,128)||!SXCF_ADD(c,efs_inode_header,p))return false;unsigned mode=sxcf16(b,1)&0xf000,count=sxcf16(b+28,1);uint64_t size=sxcf32(b+8,1);
  if(mode!=0x4000&&mode!=0x8000&&mode!=0xa000)continue;
  if(count<=12){if(!SXCF_TABLE(c,efs_extent,p+32,count))return false;if(mode==0x4000)for(unsigned k=0;k<count;k++){uint8_t*e=b+32+8*k;uint64_t at=sxcf24(e+1,1),n=e[4],logical=sxcf24(e+5,1)*512;if(e[0]||at>=blocks||n>blocks-at||logical>=size)continue;n*=512;if(n>size-logical)n=size-logical;if(!sxcf_dir(c,at*512,n,5,1,0))return false;}}
  else{/* Extent-array blocks are physically addressed by the inode extents.
         * Only complete bounded arrays are disclosed, without reconstructing files. */
   unsigned indirect=sxcf24(b+37,1);if(!indirect||indirect>12)continue;if(!SXCF_TABLE(c,efs_extent,p+32,indirect))return false;uint64_t remaining=count;
   for(unsigned k=0;k<indirect&&remaining;k++){uint8_t*e=b+32+8*k;uint64_t at=sxcf24(e+1,1),n=e[4];if(e[0]||at>=blocks||n>blocks-at)break;uint64_t slots=n*64;if(slots>remaining)slots=remaining;if(!SXCF_TABLE(c,efs_extent,at*512,slots))return false;remaining-=slots;}
  }
 }return true;
}
static bool sxcf_rt11(sx_context*c){
 uint8_t h[512],b[1024];if(!sxcf_read(c,512,h,512)||xx_rt_memcmp(h+496,"DECRT11A    ",12)||!SXCF_ADD(c,rt11_home_block,512))return false;
 uint32_t first=sxcf16(h+468,0),nr=1,seen=0;for(unsigned step=0;nr&&step<31;step++){
  if(nr>31||(seen&(UINT32_C(1)<<(nr-1))))break;seen|=UINT32_C(1)<<(nr-1);uint64_t p=((uint64_t)first+(nr-1)*2)*512;
  if(!sxcf_read(c,p,b,1024))break;unsigned max=sxcf16(b,0),next=sxcf16(b+2,0),extra=sxcf16(b+6,0);if(!max||max>31||nr>max||extra>1000||(extra&1)||sxcf16(b+4,0)>max)break;
  if(!SXCF_ADD(c,rt11_directory_segment,p))return false;
  for(unsigned q=10;q+14+extra<=1024;q+=14+extra){if(!SXCF_ADD(c,rt11_directory_entry,p+q))return false;if(sxcf16(b+q,0)&0x0800)break;}nr=next;
 }return true;
}
static bool sxcf_lif(sx_context*c){uint8_t h[42],b[32];if(!sxcf_read(c,0,h,42)||sxcf16(h,1)!=0x8000)return false;uint64_t p=(uint64_t)sxcf32(h+8,1)*256,n=(uint64_t)sxcf32(h+16,1)*256;if(!p||!n||!sxcf_span(c,p,n)||!SXCF_ADD(c,hp_lif_volume_header,0))return false;for(uint64_t q=0;q+32<=n&&c->count<SXCF_LIMIT;q+=32){if(!sxcf_read(c,p+q,b,32)||!SXCF_ADD(c,hp_lif_directory_entry,p+q))return false;if(sxcf16(b+10,1)==65535)break;}return true;}
static bool sxcf_ecma(sx_context*c){uint8_t h[128],b[128];if(!sxcf_read(c,768,h,128)||xx_rt_memcmp(h,"VOL",3)||h[75]!='1'||!SXCF_ADD(c,ecma67_volume_label,768))return false;if(sxcf_read(c,512,b,128)&&!xx_rt_memcmp(b,"ERMAP",5)&&!SXCF_ADD(c,ecma67_error_map_label,512))return false;unsigned end=h[71]=='M'&&h[78]=='1'?32:16;for(unsigned n=7;n<end;n++){uint64_t p=n<16?(uint64_t)n*128:2048+(uint64_t)(n-16)*256;if(!sxcf_read(c,p,b,128))break;if(!xx_rt_memcmp(b,"HDR",3)&&(b[3]==1||b[3]=='1')&&!SXCF_ADD(c,ecma67_file_label,p))return false;}return true;}
static bool sxcf_locus(sx_context*c){
 uint8_t h[128],b[128];uint64_t sb;unsigned o=0;bool found=false;
 for(sb=0;sb<=4096;sb+=512){if(!sxcf_read(c,sb,h,128))continue;for(o=0;o<2;o++){uint32_t m=sxcf32(h,o);if(m==0xffeeddcc||m==0xffeeddcd){found=true;break;}}if(found)break;}
 if(!found||(h[71]!=1&&h[71]!=2))return false;uint64_t bs=h[71]==1?4096:1024,blocks=sxcf32(h+8,o),ib=sxcf32(h+36,o),isize=h[71]==1?512:128;
 if(!sxcf_put(c,SXCF_ORDER(locus_superblock_prefix,o),sb,1))return false;
 if(blocks<2||!ib||ib>blocks-2||!sxcf_span(c,2*bs,ib*bs))return true;
 uint64_t nodes=ib*(bs/isize);if(nodes>SXCF_INODES)nodes=SXCF_INODES;
 for(uint64_t i=0;i<nodes&&c->count<SXCF_LIMIT;i++){uint64_t p=2*bs+i*isize;if(!sxcf_read(c,p,b,128)||!sxcf_put(c,h[71]==1?SXCF_ORDER(locus_inode_small,o):SXCF_ORDER(locus_inode,o),p,1))return false;
  unsigned flags=sxcf16(b+14,o);if((sxcf16(b,o)&0xf000)!=0x4000||(flags&0x13)!=0x12)continue;uint64_t left=sxcf32(b+16,o);if(h[71]==1&&(b[75]&1)){uint64_t n=left<384?left:384;if(!(flags&0x40)&&!sxcf_dir(c,p+128,n,0,o,16))return false;continue;}
  for(unsigned k=0;k<10&&left;k++){uint64_t nr=sxcf32(b+76+4*k,o),n=left<bs?left:bs;if(nr>=blocks)break;if(nr){if(!(flags&0x40)){if(!sxcf_dir(c,nr*bs,n,0,o,16))return false;}else for(uint64_t q=0;q+8<=n&&c->count<SXCF_LIMIT;){uint8_t e[8];if(!sxcf_read(c,nr*bs+q,e,8))return false;unsigned z=sxcf16(e+4,o),names=sxcf16(e+6,o);if(z<8||(z&3)||z>n-q||names>z-8)break;if(!sxcf_put(c,SXCF_ORDER(locus_directory_header,o),nr*bs+q,1))return false;q+=z;}}left-=n;}
 }return true;
}
typedef struct sxcf_pfs_state{sx_context*c;uint32_t first,last,unit,options,extension;unsigned visits;uint8_t root[512];}sxcf_pfs_state;
static bool sxcf_pfs_block(sxcf_pfs_state*g,uint32_t nr,uint8_t*b){return nr>=g->first&&nr<=g->last&&g->unit/512<=g->last-nr+1&&sxcf_read(g->c,(uint64_t)nr*512,b,g->unit);}
static bool sxcf_pfs_lookup_anode(sxcf_pfs_state*g,uint32_t nr,uint32_t*count,uint32_t*block,uint32_t*next){
 uint8_t b[4096];uint32_t per=(g->unit-16)/12,ip=(g->unit-12)/4,seq=(g->options&2)?nr>>16:nr/per,slot=(g->options&2)?nr&65535:nr%per,which=seq/ip,idx=seq%ip,addr;
 if(slot>=per||++g->visits>4096)return false;
 if(g->options&128){unsigned super=which/ip;if(super>=16||!sxcf_pfs_block(g,g->extension,b)||sxcf16(b,1)!=0x4558)return false;if(!SXCF_ADD(g->c,pfs_extension,(uint64_t)g->extension*512))return false;addr=sxcf32(b+64+super*4,1);
  if(!sxcf_pfs_block(g,addr,b)||sxcf16(b,1)!=0x5342||sxcf32(b+8,1)!=super)return false;if(!SXCF_ADD(g->c,pfs_index_header,(uint64_t)addr*512)||!sxcf_put(g->c,&sxcf_classic_block_number32_be,(uint64_t)addr*512+12,ip))return false;addr=sxcf32(b+12+(which%ip)*4,1);
 }else{if(which>=99)return false;addr=sxcf32(g->root+116+which*4,1);}
 if(!sxcf_pfs_block(g,addr,b)||sxcf16(b,1)!=0x4942||sxcf32(b+8,1)!=which)return false;if(!SXCF_ADD(g->c,pfs_index_header,(uint64_t)addr*512)||!sxcf_put(g->c,&sxcf_classic_block_number32_be,(uint64_t)addr*512+12,ip))return false;addr=sxcf32(b+12+idx*4,1);
 if(!sxcf_pfs_block(g,addr,b)||sxcf16(b,1)!=0x4142||sxcf32(b+8,1)!=seq)return false;if(!SXCF_ADD(g->c,pfs_anode_header,(uint64_t)addr*512)||!SXCF_TABLE(g->c,pfs_anode,(uint64_t)addr*512+16,per))return false;
 *count=sxcf32(b+16+12*slot,1);*block=sxcf32(b+20+12*slot,1);*next=sxcf32(b+24+12*slot,1);return true;
}
static bool sxcf_pfs_dir(sxcf_pfs_state*g,uint32_t nr,unsigned depth){
 if(depth>24)return true;uint8_t b[4096];while(nr&&g->visits<4096&&g->c->count<SXCF_LIMIT){uint32_t count,block,next;if(!sxcf_pfs_lookup_anode(g,nr,&count,&block,&next)||!count||count>262144||!sxcf_span(g->c,(uint64_t)block*512,(uint64_t)count*512))break;
  for(uint32_t j=0;j+g->unit/512<=count&&g->c->count<SXCF_LIMIT;j+=g->unit/512){uint64_t p=((uint64_t)block+j)*512;if(!sxcf_read(g->c,p,b,g->unit)||sxcf16(b,1)!=0x4442)break;if(!SXCF_ADD(g->c,pfs_directory_header,p))return false;
   for(unsigned at=20;at<g->unit;){unsigned z=b[at];if(!z)break;if(z<20||(z&1)||z>g->unit-at||!b[at+17]||19U+b[at+17]>z||19U+b[at+17]+b[at+18+b[at+17]]>z)break;
    if(!SXCF_ADD(g->c,pfs_directory_entry,p+at))return false;if(b[at+1]==2&&!sxcf_pfs_dir(g,sxcf32(b+at+2,1),depth+1))return false;at+=z;
   }
  }if(next==nr)break;nr=next;
 }return true;
}
static bool sxcf_pfs(sx_context*c){sxcf_pfs_state g;xx_rt_memset(&g,0,sizeof(g));g.c=c;if(!sxcf_read(c,1024,g.root,512))return false;uint32_t m=sxcf32(g.root,1);if(m!=0x41465301&&m!=0x50465301&&m!=0x50465302&&m!=0x6d754146&&m!=0x6d755046)return false;g.options=sxcf32(g.root+4,1);g.first=sxcf32(g.root+56,1);g.last=sxcf32(g.root+52,1);g.unit=sxcf16(g.root+64,1);g.extension=sxcf32(g.root+88,1);if(g.first>g.last||g.last>=(uint64_t)c->size/512||g.unit<512||g.unit>4096||!sxcf_pow(g.unit)||!SXCF_ADD(c,pfs_root_block,1024)||!sxcf_put(c,(g.options&128)?&sxcf_pfs_root_large_indexes:&sxcf_pfs_root_small_indexes,1120,1))return false;return sxcf_pfs_dir(&g,5,0);}
static bool sxcf_hpofs_node(sx_context*c,uint64_t p,uint64_t n){
 uint8_t h[92];if(n<36||!sxcf_read(c,p,h,36)||(xx_rt_memcmp(h,"INDX",4)&&xx_rt_memcmp(h,"DATA",4)))return true;if(!SXCF_ADD(c,hpofs_directory_node,p))return false;if(sxcf16(h+20,1))return true;
 for(uint64_t q=36;q+4<=n&&c->count<SXCF_LIMIT;){if(!sxcf_read(c,p+q,h,4))return false;unsigned key=sxcf16(h,1),rec=sxcf16(h+2,1);if(!key)break;if(key<5||key>1028||rec<92||(uint64_t)key+rec+4>n-q)break;if(!SXCF_ADD(c,hpofs_directory_record_prefix,p+q)||!SXCF_ADD(c,hpofs_directory_record,p+q+4+key))return false;q+=4+key+rec;}return true;
}
static bool sxcf_hpofs(sx_context*c){
 uint8_t b[4096],r[8];if(!sxcf_read(c,0,b,512)||(xx_rt_memcmp(b+54,"HPOFS\0\0\0",8)&&xx_rt_memcmp(b+54,"HPOFS   ",8)))return false;uint64_t bs=sxcf16(b+11,0),blocks=sxcf32(b+32,0);if(!blocks)blocks=sxcf16(b+19,0);if(bs<512||bs>4096||!sxcf_pow(bs)||!sxcf_span(c,0,blocks*bs)||!SXCF_ADD(c,hpofs_boot_sector,0))return false;
 if(sxcf_read(c,13*bs,b,252)&&!xx_rt_memcmp(b,"MEDINFO ",8)&&!SXCF_ADD(c,hpofs_media_information,13*bs))return false;
 if(sxcf_read(c,14*bs,b,24)&&!xx_rt_memcmp(b,"VOLINFO ",8)&&!SXCF_ADD(c,hpofs_volume_information,14*bs))return false;
 if(!sxcf_read(c,6*bs,b,92)||sxcf32(b,1)!=3)return true;uint32_t nr=sxcf32(b+76,1);if(!nr||nr>=blocks||!sxcf_read(c,(uint64_t)nr*bs,b,(size_t)bs)||xx_rt_memcmp(b,"SUBF",4))return true;unsigned count=sxcf16(b+16,1);if(count>(bs-32)/8)return true;
 if(!SXCF_ADD(c,hpofs_subfile_header,(uint64_t)nr*bs)||!SXCF_TABLE(c,hpofs_extent,(uint64_t)nr*bs+32,count))return false;
 /* Native directory runs can include gaps; only the declared extents are
  * traversed here. Optional gap leaves and file SUBF chains remain raw. */
 for(unsigned i=0;i<count&&c->count<SXCF_LIMIT;i++){xx_rt_memcpy(r,b+32+8*i,8);uint64_t first=sxcf32(r+4,1),n=sxcf16(r,1);if(first==UINT32_MAX)break;if(!n||first>=blocks||n>blocks-first||n>262144)continue;for(uint64_t j=0;j+4<=n&&c->count<SXCF_LIMIT;j+=4)if(!sxcf_hpofs_node(c,(first+j)*bs,bs*4))return false;}return true;
}
static uint16_t sxcf_ods_sum(const uint8_t*b,size_t n){uint16_t sum=0;for(size_t i=0;i<n;i+=2)sum=(uint16_t)(sum+sxcf16(b+i,0));return sum;}
typedef struct sxcf_extent_map{uint64_t logical,physical,bytes;}sxcf_extent_map;
static unsigned sxcf_ods_map(sx_context*c,const uint8_t*h,uint64_t at,sxcf_extent_map*m,unsigned cap,bool emit){
 unsigned q=h[1]*2,end=q+h[58]*2,count=0;uint64_t logical=0;if(q<80||end>510||q>end)return 0;
 while(q+2<=end){uint16_t w=sxcf16(h+q,0);unsigned format=w>>14,z=format==0?2:format==1?4:format==2?6:8;if(z>end-q)return 0;
  const sx_layout*l=format==0?&sxcf_ods_retrieval_pointer0:format==1?&sxcf_ods_retrieval_pointer1:format==2?&sxcf_ods_retrieval_pointer2:&sxcf_ods_retrieval_pointer3;
  if(emit&&!sxcf_put(c,l,at+q,1))return 0;
  if(format){uint64_t n=format==1?(w&255)+1U:format==2?(w&0x3fff)+1U:(((uint64_t)(w&0x3fff)<<16)|sxcf16(h+q+2,0))+1U;uint64_t block=format==1?((uint32_t)(w&0x3f00)<<8)|sxcf16(h+q+2,0):sxcf32(h+q+(format==2?2:4),0);if(n>UINT64_MAX/512||!sxcf_span(c,block*512,n*512)||count>=cap)return count;m[count++]=(sxcf_extent_map){logical,block*512,n*512};logical+=n*512;}
  q+=z;
 }return count;
}
static bool sxcf_ods_header_ok(const uint8_t*h){return sxcf_ods_sum(h,510)==sxcf16(h+510,0)&&(sxcf16(h+6,0)>>8==2||sxcf16(h+6,0)>>8==5)&&h[0]>=40&&h[0]<=h[1]&&h[1]<=h[2]&&h[2]<=h[3]&&h[3]<=255&&(unsigned)h[1]+h[58]<=h[2];}
static bool sxcf_ods_dir(sx_context*c,uint64_t p,uint64_t bytes){uint8_t h[6];for(uint64_t q=0;q+6<=bytes&&c->count<SXCF_LIMIT;){if(!sxcf_read(c,p+q,h,6))return false;unsigned n=sxcf16(h,0),names=h[5];if(!n||n==65535){q=((q/512)+1)*512;continue;}unsigned values=6+((names+1)&~1U);if(n<14||(n&1)||n+2>bytes-q||n+2>512-q%512||values+8>n+2||(n+2-values)%8)break;if(!SXCF_ADD(c,ods_directory_header,p+q)||!SXCF_TABLE(c,ods_directory_version,p+q+values,(n+2-values)/8))return false;q+=n+2;}return true;}
static bool sxcf_ods(sx_context*c){
 uint8_t h[512],b[512];sxcf_extent_map index[215],map[215];if(!sxcf_read(c,512,h,512)||(!(!xx_rt_memcmp(h+496,"DECFILE11A  ",12)||!xx_rt_memcmp(h+496,"DECFILE11B  ",12)))||sxcf_ods_sum(h,58)!=sxcf16(h+58,0)||sxcf_ods_sum(h,510)!=sxcf16(h+510,0)||!SXCF_ADD(c,ods_home_block,512))return false;
 uint64_t first=(uint64_t)sxcf32(h+24,0)+sxcf16(h+32,0),vbn=(uint64_t)sxcf16(h+22,0)+sxcf16(h+32,0),max=sxcf32(h+28,0);if(!vbn||!max||!sxcf_read(c,first*512,b,512)||!sxcf_ods_header_ok(b))return true;
 unsigned ni=sxcf_ods_map(c,b,first*512,index,215,false);if(!ni)return true;if(max>SXCF_INODES)max=SXCF_INODES;
 for(uint64_t id=1;id<=max&&c->count<SXCF_LIMIT;id++){uint64_t logical=(vbn+id-2)*512,p=UINT64_MAX;for(unsigned k=0;k<ni;k++)if(logical>=index[k].logical&&logical-index[k].logical<=index[k].bytes&&512<=index[k].bytes-(logical-index[k].logical)){p=index[k].physical+logical-index[k].logical;break;}if(p==UINT64_MAX)continue;if(!sxcf_read(c,p,b,512))return false;if(!sxcf_ods_header_ok(b)||((uint32_t)sxcf16(b+8,0)|(uint32_t)b[13]<<16)!=id)continue;
  if(!SXCF_ADD(c,ods_file_header,p)||!SXCF_ADD(c,ods_file_checksum,p+510))return false;unsigned nm=sxcf_ods_map(c,b,p,map,215,true);
  if(sxcf32(b+52,0)&0x2000){uint64_t end=(uint32_t)sxcf16(b+28,0)<<16|sxcf16(b+30,0),size=end?(end-1)*512+sxcf16(b+32,0):0;for(unsigned k=0;k<nm;k++){if(map[k].logical>=size)break;uint64_t n=map[k].bytes;if(n>size-map[k].logical)n=size-map[k].logical;if(!sxcf_ods_dir(c,map[k].physical,n))return false;}}
 }return true;
}
static bool sxcf_unicos(sx_context*c){
 uint8_t h[4096],b[256],d[24];uint64_t sb=0;if(!sxcf_read(c,0,h,4096)||sxcf64(h,1)!=UINT64_C(0x6e6331667331636e)){sb=4096;if(!sxcf_read(c,sb,h,4096)||sxcf64(h,1)!=UINT64_C(0x6e6331667331636e))return false;}
 uint64_t blocks=sxcf64(h+32,1),a=sxcf64(h+3264,1),v=sxcf64(h+3280,1);if(!blocks||a>15||v>15||sxcf64(h+152,1)!=1)return false;
 if(!SXCF_ADD(c,unicos_superblock_prefix,sb)||!SXCF_TABLE(c,unicos_partition,sb+184,64)||!SXCF_ADD(c,unicos_superblock_tail,sb+3256))return false;unsigned visits=0;
 for(unsigned region=0;region<4;region++){uint64_t first=sxcf32(h+204+region*8,1),count=sxcf16(h+202+region*8,1),bitmap=(a+1)*(v+1);if(!count||first>=blocks||count>blocks-first||bitmap>=count)continue;
  for(uint64_t i=0;i<(count-bitmap)*16&&visits<SXCF_INODES&&c->count<SXCF_LIMIT;i++,visits++){uint64_t p=(first+bitmap)*4096+i*256;if(!sxcf_read(c,p,b,256))break;if(!sxcf32(b,1))continue;if(!SXCF_ADD(c,unicos_inode_prefix,p)||!SXCF_TABLE(c,unicos_extent,p+128,8)||!SXCF_ADD(c,unicos_inode_tail,p+192))return false;
   if((sxcf32(b,1)&0xf000)!=0x4000||(b[88]&15)!=1)continue;uint64_t left=sxcf64(b+24,1);
   for(unsigned k=0;k<8&&left&&c->count<SXCF_LIMIT;k++){uint64_t n=sxcf32(b+128+8*k,1),at=sxcf32(b+132+8*k,1);if(!n||(n&0x80000000)||at>=blocks||n>blocks-at)break;n*=4096;if(n>left)n=left;
    for(uint64_t q=0;q+24<=n&&c->count<SXCF_LIMIT;){if(!sxcf_read(c,at*4096+q,d,24))return false;uint64_t word=sxcf64(d+16,1),z=(word>>10)&0x3fffff,names=word&1023;if(z<24||(z&7)||z>n-q||z>4096-q%4096||names>z-24)break;if(!SXCF_ADD(c,unicos_directory_header,at*4096+q))return false;q+=z;}left-=n;
   }
  }
 }return true;
}
typedef struct sxcf_bfs_state{sx_context*c;uint64_t blocks,bs;unsigned order,shift,visits;bool afs;}sxcf_bfs_state;
static bool sxcf_bfs_run(sxcf_bfs_state*g,const uint8_t*b,uint64_t*p,uint64_t*n){uint64_t group=sxcf32(b,g->order),start=sxcf16(b+4,g->order),count=sxcf16(b+6,g->order);if(group>INT32_MAX||g->shift>31||group>(UINT64_MAX>>g->shift))return false;uint64_t block=(group<<g->shift)+start;if(block>=g->blocks||count>g->blocks-block)return false;*p=block*g->bs;*n=count*g->bs;return true;}
static bool sxcf_mapped(const sxcf_extent_map*m,unsigned count,uint64_t logical,uint64_t bytes,uint64_t*p){for(unsigned i=0;i<count;i++)if(logical>=m[i].logical&&logical-m[i].logical<=m[i].bytes&&bytes<=m[i].bytes-(logical-m[i].logical)){*p=m[i].physical+logical-m[i].logical;return true;}return false;}
static bool sxcf_bfs_inode(sxcf_bfs_state*g,uint64_t p,unsigned depth){
 sx_context*c=g->c;uint8_t b[256],h[40],node[32],value[8];if(depth>24||++g->visits>4096||c->count>=SXCF_LIMIT)return true;
 unsigned head=g->afs?80:72;if(!sxcf_read(c,p,b,head+144))return false;uint32_t magic=sxcf32(b,g->order);if(magic!=(g->afs?0x64358428U:0x3bbe0ad9U))return true;
 if(!sxcf_put(c,g->afs?SXCF_ORDER(atheos_inode_header,g->order):SXCF_ORDER(beos_inode_header,g->order),p,1))return false;
 unsigned mode=sxcf32(b+20,g->order)&0xf000,flags=sxcf32(b+24,g->order);if(mode==0xa000&&!(flags&0x40))return true;
 if(!sxcf_put(c,SXCF_ORDER(bfs_block_run,g->order),p+head,12)||!sxcf_put(c,SXCF_ORDER(bfs_stream_tail,g->order),p+head+96,1))return false;
 if(!g->afs&&sxcf_span(c,p+216,16)&&!sxcf_put(c,SXCF_ORDER(beos_inode_tail,g->order),p+216,1))return false;
 if(!g->afs){uint64_t inode_size=sxcf32(b+64,g->order);if(inode_size>=232&&inode_size<=g->bs&&sxcf_span(c,p,inode_size))for(uint64_t q=232;q+8<=inode_size&&c->count<SXCF_LIMIT;){uint8_t attr[8];if(!sxcf_read(c,p+q,attr,8))break;uint64_t names=sxcf16(attr+4,g->order),bytes=sxcf16(attr+6,g->order),step=12+names+bytes;if(!names||step>inode_size-q)break;if(!sxcf_put(c,SXCF_ORDER(bfs_small_data_header,g->order),p+q,1))return false;q+=step;}}
 if(mode!=0x4000)return true;sxcf_extent_map m[12];unsigned count=0;uint64_t logical=0,size=sxcf64(b+head+136,g->order);
 for(unsigned i=0;i<12;i++){uint64_t at,n;if(!sxcf_bfs_run(g,b+head+8*i,&at,&n))break;if(n){m[count++]=(sxcf_extent_map){logical,at,n};logical+=n;}}
 unsigned hs=g->afs?32:40,nh=g->afs?32:28;uint64_t at;if(size<hs||!sxcf_mapped(m,count,0,hs,&at)||!sxcf_read(c,at,h,hs))return true;
 if(!sxcf_put(c,g->afs?SXCF_ORDER(atheos_btree_header,g->order):SXCF_ORDER(beos_btree_header,g->order),at,1))return false;
 uint64_t root=sxcf64(h+(g->afs?4:16),g->order);uint32_t levels=sxcf32(h+(g->afs?12:8),g->order);if(!levels||levels>32)return true;
 struct{uint64_t offset;unsigned level;} pending[256];uint64_t seen[512];unsigned top=1,used=0;pending[0].offset=root;pending[0].level=levels;
 while(top&&used<512&&c->count<SXCF_LIMIT){top--;uint64_t off=pending[top].offset;unsigned level=pending[top].level;bool duplicate=false;for(unsigned i=0;i<used;i++)if(seen[i]==off)duplicate=true;if(duplicate||off>size||nh>size-off||!sxcf_mapped(m,count,off,nh,&at)||!sxcf_read(c,at,node,nh))continue;seen[used++]=off;
  uint64_t keys=g->afs?sxcf32(node+24,g->order):sxcf16(node+24,g->order),names=g->afs?sxcf32(node+28,g->order):sxcf16(node+26,g->order),align=g->afs?4:8,idx=(nh+names+align-1)&~(align-1),bytes=idx+keys*10;
  if(keys>8192||names>65535||bytes>size-off||!sxcf_mapped(m,count,off,bytes,&at))continue;
  if(!sxcf_put(c,g->afs?SXCF_ORDER(atheos_btree_node,g->order):SXCF_ORDER(beos_btree_node,g->order),at,1)||!sxcf_put(c,SXCF_ORDER(bfs_btree_key_end,g->order),at+idx,keys)||!sxcf_put(c,SXCF_ORDER(bfs_btree_value,g->order),at+idx+keys*2,keys))return false;
  for(uint64_t i=0;i<keys&&c->count<SXCF_LIMIT;i++){if(!sxcf_read(c,at+idx+keys*2+i*8,value,8))return false;uint64_t nr=sxcf64(value,g->order);if(level>1){if(top<256){pending[top].offset=nr;pending[top++].level=level-1;}}else if(nr<g->blocks&&!sxcf_bfs_inode(g,nr*g->bs,depth+1))return false;}
  uint64_t link=sxcf64(node+(level>1?16:8),g->order);if(link!=UINT64_MAX&&top<256){pending[top].offset=link;pending[top++].level=level>1?level-1:1;}
 }return true;
}
static bool sxcf_bfs(sx_context*c){
 uint8_t b[512];bool afs=c->f->file_type==XX_FILE_TYPE_ATHEOS_FS,found=false;unsigned o=0;uint64_t p=0;
 for(unsigned i=0;i<(afs?1U:3U);i++){p=afs?1024:(uint64_t)i*512;if(!sxcf_read(c,p,b,512))continue;for(o=0;o<2;o++)if(sxcf32(b+32,o)==(afs?0x41465331U:0x42465331U)&&sxcf32(b+68,o)==0xdd121031U&&sxcf32(b+112,o)==0x15b6830eU){found=true;break;}if(found)break;}
 if(!found)return false;uint64_t bs=sxcf32(b+40,o),blocks=sxcf64(b+48,o);unsigned shift=sxcf32(b+76,o);if(bs<512||bs>65536||!sxcf_pow(bs)||!blocks||blocks>(uint64_t)c->size/bs||shift>31)return false;
 if(!sxcf_put(c,afs?SXCF_ORDER(atheos_superblock,o):SXCF_ORDER(beos_superblock,o),p,1))return false;sxcf_bfs_state g={c,blocks,bs,o,shift,0,afs};uint64_t at,n;if(!sxcf_bfs_run(&g,b+116,&at,&n)||n<bs)return true;return sxcf_bfs_inode(&g,at,0);
}
static int sxcf_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxcf_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxcf_order);return !c->failed;}
static bool sx_classicfs_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_MINIX:case XX_FILE_TYPE_LINUX_EXT:case XX_FILE_TYPE_XIA_FS:case XX_FILE_TYPE_QNX4:case XX_FILE_TYPE_SGI_EFS:case XX_FILE_TYPE_UNIX_BFS:case XX_FILE_TYPE_COHERENT_FS:case XX_FILE_TYPE_UNIX_V7:case XX_FILE_TYPE_SYSV_FS:case XX_FILE_TYPE_XENIX_FS:case XX_FILE_TYPE_RT11_FS:case XX_FILE_TYPE_ECMA67_FS:case XX_FILE_TYPE_HP_LIF:case XX_FILE_TYPE_LOCUS_FS:case XX_FILE_TYPE_UNICOS_FS:case XX_FILE_TYPE_ODS2_FS:case XX_FILE_TYPE_HPOFS:case XX_FILE_TYPE_AMIGA_PFS:case XX_FILE_TYPE_BEOS_FS:case XX_FILE_TYPE_ATHEOS_FS:return true;default:return false;}}
static bool sx_classicfs_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){
 case XX_FILE_TYPE_MINIX:ok=sxcf_minix(c);break;
 case XX_FILE_TYPE_LINUX_EXT:case XX_FILE_TYPE_XIA_FS:case XX_FILE_TYPE_UNIX_BFS:case XX_FILE_TYPE_COHERENT_FS:case XX_FILE_TYPE_UNIX_V7:case XX_FILE_TYPE_SYSV_FS:case XX_FILE_TYPE_XENIX_FS:ok=sxcf_classic(c);break;
 case XX_FILE_TYPE_QNX4:ok=sxcf_qnx(c);break;case XX_FILE_TYPE_SGI_EFS:ok=sxcf_efs(c);break;
 case XX_FILE_TYPE_RT11_FS:ok=sxcf_rt11(c);break;case XX_FILE_TYPE_HP_LIF:ok=sxcf_lif(c);break;case XX_FILE_TYPE_ECMA67_FS:ok=sxcf_ecma(c);break;case XX_FILE_TYPE_LOCUS_FS:ok=sxcf_locus(c);break;case XX_FILE_TYPE_AMIGA_PFS:ok=sxcf_pfs(c);break;case XX_FILE_TYPE_HPOFS:ok=sxcf_hpofs(c);break;case XX_FILE_TYPE_ODS2_FS:ok=sxcf_ods(c);break;case XX_FILE_TYPE_UNICOS_FS:ok=sxcf_unicos(c);break;case XX_FILE_TYPE_BEOS_FS:case XX_FILE_TYPE_ATHEOS_FS:ok=sxcf_bfs(c);break;default:break;}
 return ok&&c->count&&sxcf_finish(c);
}
