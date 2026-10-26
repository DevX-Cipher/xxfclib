/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical APFS and Btrfs metadata. */
static const xx_data_struct_field_desc sxc_apfs_object_header_fields[] = {
    SX_FIELD("checksum", "uint64", 0, 8, SX_CHECKSUM),
    SX_FIELD("object_id", "uint64", 8, 8, SX_ID),
    SX_FIELD("transaction_id", "uint64", 16, 8, SX_ID),
    SX_FIELD("object_type", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("object_subtype", "uint32", 28, 4, SX_ID),
};
static const sx_layout sxc_apfs_object_header = {UINT32_C(0x60180001),"apfs_object_header",sxc_apfs_object_header_fields,SX_COUNT(sxc_apfs_object_header_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_container_header_fields[] = {
    SX_FIELD("checksum", "uint64", 0, 8, SX_CHECKSUM),
    SX_FIELD("object_id", "uint64", 8, 8, SX_ID),
    SX_FIELD("transaction_id", "uint64", 16, 8, SX_ID),
    SX_FIELD("object_type", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("object_subtype", "uint32", 28, 4, SX_ID),
    SX_FIELD("magic", "char[4]", 32, 4, SX_SIGNATURE),
    SX_FIELD("block_size", "uint32", 36, 4, SX_SIZE),
    SX_FIELD("block_count", "uint64", 40, 8, SX_COUNT_PROP),
    SX_FIELD("features", "uint64", 48, 8, SX_FLAGS),
    SX_FIELD("readonly_compatible_features", "uint64", 56, 8, SX_FLAGS),
    SX_FIELD("incompatible_features", "uint64", 64, 8, SX_FLAGS),
    SX_FIELD("uuid", "uint8[16]", 72, 16, SX_NONE),
    SX_FIELD("next_object_id", "uint64", 88, 8, SX_ID),
    SX_FIELD("next_transaction_id", "uint64", 96, 8, SX_ID),
    SX_FIELD("checkpoint_descriptor_blocks_flags", "uint32", 104, 4, SX_FLAGS),
    SX_FIELD("checkpoint_data_blocks_flags", "uint32", 108, 4, SX_FLAGS),
    SX_FIELD("checkpoint_descriptor_base", "int64", 112, 8, SX_NONE),
    SX_FIELD("checkpoint_data_base", "int64", 120, 8, SX_NONE),
    SX_FIELD("checkpoint_descriptor_next", "uint32", 128, 4, SX_NONE),
    SX_FIELD("checkpoint_data_next", "uint32", 132, 4, SX_NONE),
    SX_FIELD("checkpoint_descriptor_index", "uint32", 136, 4, SX_NONE),
    SX_FIELD("checkpoint_descriptor_length_blocks", "uint32", 140, 4, SX_COUNT_PROP),
    SX_FIELD("checkpoint_data_index", "uint32", 144, 4, SX_NONE),
    SX_FIELD("checkpoint_data_length_blocks", "uint32", 148, 4, SX_COUNT_PROP),
    SX_FIELD("spaceman_oid", "uint64", 152, 8, SX_ID),
    SX_FIELD("omap_oid", "uint64", 160, 8, SX_ID),
    SX_FIELD("reaper_oid", "uint64", 168, 8, SX_ID),
    SX_FIELD("test_type", "uint32", 176, 4, SX_ID),
    SX_FIELD("maximum_file_systems", "uint32", 180, 4, SX_COUNT_PROP),
};
static const sx_layout sxc_apfs_container_header = {UINT32_C(0x60180002),"apfs_container_header",sxc_apfs_container_header_fields,SX_COUNT(sxc_apfs_container_header_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_file_system_oid_fields[] = {
    SX_FIELD("file_system_oid", "uint64", 0, 8, SX_ID),
};
static const sx_layout sxc_apfs_file_system_oid = {UINT32_C(0x60180003),"apfs_file_system_oid",sxc_apfs_file_system_oid_fields,SX_COUNT(sxc_apfs_file_system_oid_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_container_counter_fields[] = {
    SX_FIELD("counter", "uint64", 0, 8, SX_COUNT_PROP),
};
static const sx_layout sxc_apfs_container_counter = {UINT32_C(0x60180004),"apfs_container_counter",sxc_apfs_container_counter_fields,SX_COUNT(sxc_apfs_container_counter_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_container_tail_fields[] = {
    SX_FIELD("blocked_out_start_block", "int64", 0, 8, SX_NONE),
    SX_FIELD("blocked_out_block_count", "uint64", 8, 8, SX_COUNT_PROP),
    SX_FIELD("evict_mapping_tree_oid", "uint64", 16, 8, SX_ID),
    SX_FIELD("flags", "uint64", 24, 8, SX_FLAGS),
    SX_FIELD("efi_jumpstart_block", "int64", 32, 8, SX_NONE),
    SX_FIELD("fusion_uuid", "uint8[16]", 40, 16, SX_NONE),
    SX_FIELD("keylocker_start_block", "int64", 56, 8, SX_NONE),
    SX_FIELD("keylocker_block_count", "uint64", 64, 8, SX_COUNT_PROP),
    SX_FIELD("ephemeral_info0", "uint64", 72, 8, SX_NONE),
    SX_FIELD("ephemeral_info1", "uint64", 80, 8, SX_NONE),
    SX_FIELD("ephemeral_info2", "uint64", 88, 8, SX_NONE),
    SX_FIELD("ephemeral_info3", "uint64", 96, 8, SX_NONE),
    SX_FIELD("test_oid", "uint64", 104, 8, SX_ID),
    SX_FIELD("fusion_middle_tree_oid", "uint64", 112, 8, SX_ID),
    SX_FIELD("fusion_writeback_cache_oid", "uint64", 120, 8, SX_ID),
    SX_FIELD("fusion_writeback_start_block", "int64", 128, 8, SX_NONE),
    SX_FIELD("fusion_writeback_block_count", "uint64", 136, 8, SX_COUNT_PROP),
    SX_FIELD("newest_mounted_version", "uint64", 144, 8, SX_ID),
    SX_FIELD("media_keybag_start_block", "int64", 152, 8, SX_NONE),
    SX_FIELD("media_keybag_block_count", "uint64", 160, 8, SX_COUNT_PROP),
};
static const sx_layout sxc_apfs_container_tail = {UINT32_C(0x60180005),"apfs_container_tail",sxc_apfs_container_tail_fields,SX_COUNT(sxc_apfs_container_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_checkpoint_map_fields[] = {
    SX_FIELD("checksum", "uint64", 0, 8, SX_CHECKSUM),
    SX_FIELD("object_id", "uint64", 8, 8, SX_ID),
    SX_FIELD("transaction_id", "uint64", 16, 8, SX_ID),
    SX_FIELD("object_type", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("object_subtype", "uint32", 28, 4, SX_ID),
    SX_FIELD("flags", "uint32", 32, 4, SX_FLAGS),
    SX_FIELD("mapping_count", "uint32", 36, 4, SX_COUNT_PROP),
};
static const sx_layout sxc_apfs_checkpoint_map = {UINT32_C(0x60180006),"apfs_checkpoint_map",sxc_apfs_checkpoint_map_fields,SX_COUNT(sxc_apfs_checkpoint_map_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_checkpoint_mapping_fields[] = {
    SX_FIELD("object_type", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("object_subtype", "uint32", 4, 4, SX_ID),
    SX_FIELD("object_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("padding", "uint32", 12, 4, SX_RESERVED),
    SX_FIELD("file_system_oid", "uint64", 16, 8, SX_ID),
    SX_FIELD("object_id", "uint64", 24, 8, SX_ID),
    SX_FIELD("physical_block", "uint64", 32, 8, SX_NONE),
};
static const sx_layout sxc_apfs_checkpoint_mapping = {UINT32_C(0x60180007),"apfs_checkpoint_mapping",sxc_apfs_checkpoint_mapping_fields,SX_COUNT(sxc_apfs_checkpoint_mapping_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_object_map_fields[] = {
    SX_FIELD("checksum", "uint64", 0, 8, SX_CHECKSUM),
    SX_FIELD("object_id", "uint64", 8, 8, SX_ID),
    SX_FIELD("transaction_id", "uint64", 16, 8, SX_ID),
    SX_FIELD("object_type", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("object_subtype", "uint32", 28, 4, SX_ID),
    SX_FIELD("flags", "uint32", 32, 4, SX_FLAGS),
    SX_FIELD("snapshot_count", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("tree_type", "uint32", 40, 4, SX_FLAGS),
    SX_FIELD("snapshot_tree_type", "uint32", 44, 4, SX_FLAGS),
    SX_FIELD("tree_oid", "uint64", 48, 8, SX_ID),
    SX_FIELD("snapshot_tree_oid", "uint64", 56, 8, SX_ID),
    SX_FIELD("most_recent_snapshot_xid", "uint64", 64, 8, SX_ID),
    SX_FIELD("pending_revert_min_xid", "uint64", 72, 8, SX_ID),
    SX_FIELD("pending_revert_max_xid", "uint64", 80, 8, SX_ID),
};
static const sx_layout sxc_apfs_object_map = {UINT32_C(0x60180008),"apfs_object_map",sxc_apfs_object_map_fields,SX_COUNT(sxc_apfs_object_map_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_btree_node_fields[] = {
    SX_FIELD("checksum", "uint64", 0, 8, SX_CHECKSUM),
    SX_FIELD("object_id", "uint64", 8, 8, SX_ID),
    SX_FIELD("transaction_id", "uint64", 16, 8, SX_ID),
    SX_FIELD("object_type", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("object_subtype", "uint32", 28, 4, SX_ID),
    SX_FIELD("flags", "uint16", 32, 2, SX_FLAGS),
    SX_FIELD("level", "uint16", 34, 2, SX_NONE),
    SX_FIELD("key_count", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("table_space_offset", "uint16", 40, 2, SX_OFFSET),
    SX_FIELD("table_space_length", "uint16", 42, 2, SX_SIZE),
    SX_FIELD("free_space_offset", "uint16", 44, 2, SX_OFFSET),
    SX_FIELD("free_space_length", "uint16", 46, 2, SX_SIZE),
    SX_FIELD("key_free_list_offset", "uint16", 48, 2, SX_OFFSET),
    SX_FIELD("key_free_list_length", "uint16", 50, 2, SX_SIZE),
    SX_FIELD("value_free_list_offset", "uint16", 52, 2, SX_OFFSET),
    SX_FIELD("value_free_list_length", "uint16", 54, 2, SX_SIZE),
};
static const sx_layout sxc_apfs_btree_node = {UINT32_C(0x60180009),"apfs_btree_node",sxc_apfs_btree_node_fields,SX_COUNT(sxc_apfs_btree_node_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_btree_info_fields[] = {
    SX_FIELD("flags", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("node_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("key_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("value_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("longest_key", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("longest_value", "uint32", 20, 4, SX_SIZE),
    SX_FIELD("key_count", "uint64", 24, 8, SX_COUNT_PROP),
    SX_FIELD("node_count", "uint64", 32, 8, SX_COUNT_PROP),
};
static const sx_layout sxc_apfs_btree_info = {UINT32_C(0x6018000A),"apfs_btree_info",sxc_apfs_btree_info_fields,SX_COUNT(sxc_apfs_btree_info_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_btree_kvoff_fields[] = {
    SX_FIELD("key_offset", "uint16", 0, 2, SX_OFFSET),
    SX_FIELD("value_offset", "uint16", 2, 2, SX_OFFSET),
};
static const sx_layout sxc_apfs_btree_kvoff = {UINT32_C(0x6018000B),"apfs_btree_kvoff",sxc_apfs_btree_kvoff_fields,SX_COUNT(sxc_apfs_btree_kvoff_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_btree_kvloc_fields[] = {
    SX_FIELD("key_offset", "uint16", 0, 2, SX_OFFSET),
    SX_FIELD("key_length", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("value_offset", "uint16", 4, 2, SX_OFFSET),
    SX_FIELD("value_length", "uint16", 6, 2, SX_SIZE),
};
static const sx_layout sxc_apfs_btree_kvloc = {UINT32_C(0x6018000C),"apfs_btree_kvloc",sxc_apfs_btree_kvloc_fields,SX_COUNT(sxc_apfs_btree_kvloc_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_omap_key_fields[] = {
    SX_FIELD("object_id", "uint64", 0, 8, SX_ID),
    SX_FIELD("transaction_id", "uint64", 8, 8, SX_ID),
};
static const sx_layout sxc_apfs_omap_key = {UINT32_C(0x6018000D),"apfs_omap_key",sxc_apfs_omap_key_fields,SX_COUNT(sxc_apfs_omap_key_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_omap_value_fields[] = {
    SX_FIELD("flags", "uint32", 0, 4, SX_FLAGS),
    SX_FIELD("size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("physical_block", "int64", 8, 8, SX_NONE),
};
static const sx_layout sxc_apfs_omap_value = {UINT32_C(0x6018000E),"apfs_omap_value",sxc_apfs_omap_value_fields,SX_COUNT(sxc_apfs_omap_value_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_btree_child_fields[] = {
    SX_FIELD("child_oid", "uint64", 0, 8, SX_ID),
};
static const sx_layout sxc_apfs_btree_child = {UINT32_C(0x6018000F),"apfs_btree_child",sxc_apfs_btree_child_fields,SX_COUNT(sxc_apfs_btree_child_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_volume_header_fields[] = {
    SX_FIELD("checksum", "uint64", 0, 8, SX_CHECKSUM),
    SX_FIELD("object_id", "uint64", 8, 8, SX_ID),
    SX_FIELD("transaction_id", "uint64", 16, 8, SX_ID),
    SX_FIELD("object_type", "uint32", 24, 4, SX_FLAGS),
    SX_FIELD("object_subtype", "uint32", 28, 4, SX_ID),
    SX_FIELD("magic", "char[4]", 32, 4, SX_SIGNATURE),
    SX_FIELD("filesystem_index", "uint32", 36, 4, SX_NONE),
    SX_FIELD("features", "uint64", 40, 8, SX_FLAGS),
    SX_FIELD("readonly_compatible_features", "uint64", 48, 8, SX_FLAGS),
    SX_FIELD("incompatible_features", "uint64", 56, 8, SX_FLAGS),
    SX_FIELD("unmount_time", "uint64", 64, 8, SX_TIME),
    SX_FIELD("reserve_block_count", "uint64", 72, 8, SX_COUNT_PROP),
    SX_FIELD("quota_block_count", "uint64", 80, 8, SX_COUNT_PROP),
    SX_FIELD("allocated_block_count", "uint64", 88, 8, SX_COUNT_PROP),
    SX_FIELD("crypto_major_version", "uint16", 96, 2, SX_ID),
    SX_FIELD("crypto_minor_version", "uint16", 98, 2, SX_ID),
    SX_FIELD("crypto_flags", "uint32", 100, 4, SX_FLAGS),
    SX_FIELD("crypto_protection_class", "uint32", 104, 4, SX_ID),
    SX_FIELD("crypto_key_os_version", "uint32", 108, 4, SX_ID),
    SX_FIELD("crypto_key_revision", "uint16", 112, 2, SX_ID),
    SX_FIELD("crypto_unused", "uint16", 114, 2, SX_RESERVED),
    SX_FIELD("root_tree_type", "uint32", 116, 4, SX_FLAGS),
    SX_FIELD("extentref_tree_type", "uint32", 120, 4, SX_FLAGS),
    SX_FIELD("snapshot_metadata_tree_type", "uint32", 124, 4, SX_FLAGS),
    SX_FIELD("omap_oid", "uint64", 128, 8, SX_ID),
    SX_FIELD("root_tree_oid", "uint64", 136, 8, SX_ID),
    SX_FIELD("extentref_tree_oid", "uint64", 144, 8, SX_ID),
    SX_FIELD("snapshot_metadata_tree_oid", "uint64", 152, 8, SX_ID),
    SX_FIELD("revert_to_xid", "uint64", 160, 8, SX_ID),
    SX_FIELD("revert_to_superblock_oid", "uint64", 168, 8, SX_ID),
    SX_FIELD("next_object_id", "uint64", 176, 8, SX_ID),
    SX_FIELD("file_count", "uint64", 184, 8, SX_COUNT_PROP),
    SX_FIELD("directory_count", "uint64", 192, 8, SX_COUNT_PROP),
    SX_FIELD("symlink_count", "uint64", 200, 8, SX_COUNT_PROP),
    SX_FIELD("other_object_count", "uint64", 208, 8, SX_COUNT_PROP),
    SX_FIELD("snapshot_count", "uint64", 216, 8, SX_COUNT_PROP),
    SX_FIELD("total_blocks_allocated", "uint64", 224, 8, SX_COUNT_PROP),
    SX_FIELD("total_blocks_freed", "uint64", 232, 8, SX_COUNT_PROP),
    SX_FIELD("volume_uuid", "uint8[16]", 240, 16, SX_NONE),
    SX_FIELD("last_modified_time", "uint64", 256, 8, SX_TIME),
    SX_FIELD("filesystem_flags", "uint64", 264, 8, SX_FLAGS),
};
static const sx_layout sxc_apfs_volume_header = {UINT32_C(0x60180010),"apfs_volume_header",sxc_apfs_volume_header_fields,SX_COUNT(sxc_apfs_volume_header_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_modified_by_fields[] = {
    SX_FIELD("identifier", "char[32]", 0, 32, SX_STRING),
    SX_FIELD("timestamp", "uint64", 32, 8, SX_TIME),
    SX_FIELD("last_transaction_id", "uint64", 40, 8, SX_ID),
};
static const sx_layout sxc_apfs_modified_by = {UINT32_C(0x60180011),"apfs_modified_by",sxc_apfs_modified_by_fields,SX_COUNT(sxc_apfs_modified_by_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_volume_name_fields[] = {
    SX_FIELD("volume_name", "char[256]", 0, 256, SX_STRING),
};
static const sx_layout sxc_apfs_volume_name = {UINT32_C(0x60180012),"apfs_volume_name",sxc_apfs_volume_name_fields,SX_COUNT(sxc_apfs_volume_name_fields),SX_LE};

static const xx_data_struct_field_desc sxc_apfs_volume_tail_fields[] = {
    SX_FIELD("next_document_id", "uint32", 0, 4, SX_ID),
    SX_FIELD("role", "uint16", 4, 2, SX_FLAGS),
    SX_FIELD("reserved", "uint16", 6, 2, SX_RESERVED),
    SX_FIELD("root_to_xid", "uint64", 8, 8, SX_ID),
    SX_FIELD("er_state_oid", "uint64", 16, 8, SX_ID),
    SX_FIELD("cloneinfo_id_epoch", "uint64", 24, 8, SX_NONE),
    SX_FIELD("cloneinfo_xid", "uint64", 32, 8, SX_ID),
    SX_FIELD("snapshot_metadata_extended_oid", "uint64", 40, 8, SX_ID),
    SX_FIELD("volume_group_id", "uint8[16]", 48, 16, SX_NONE),
    SX_FIELD("integrity_metadata_oid", "uint64", 64, 8, SX_ID),
    SX_FIELD("file_extent_tree_oid", "uint64", 72, 8, SX_ID),
    SX_FIELD("file_extent_tree_type", "uint32", 80, 4, SX_FLAGS),
    SX_FIELD("reserved_type", "uint32", 84, 4, SX_RESERVED),
    SX_FIELD("reserved_oid", "uint64", 88, 8, SX_RESERVED),
};
static const sx_layout sxc_apfs_volume_tail = {UINT32_C(0x60180013),"apfs_volume_tail",sxc_apfs_volume_tail_fields,SX_COUNT(sxc_apfs_volume_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxc_btrfs_superblock_header_fields[] = {
    SX_FIELD("checksum", "uint8[32]", 0, 32, SX_CHECKSUM),
    SX_FIELD("fsid", "uint8[16]", 32, 16, SX_NONE),
    SX_FIELD("physical_offset", "uint64", 48, 8, SX_OFFSET),
    SX_FIELD("flags", "uint64", 56, 8, SX_FLAGS),
    SX_FIELD("magic", "char[8]", 64, 8, SX_SIGNATURE),
    SX_FIELD("generation", "uint64", 72, 8, SX_NONE),
    SX_FIELD("root_logical_address", "uint64", 80, 8, SX_ADDRESS),
    SX_FIELD("chunk_root_logical_address", "uint64", 88, 8, SX_ADDRESS),
    SX_FIELD("log_root_logical_address", "uint64", 96, 8, SX_ADDRESS),
    SX_FIELD("unused_log_root_transid", "uint64", 104, 8, SX_RESERVED),
    SX_FIELD("total_bytes", "uint64", 112, 8, SX_SIZE),
    SX_FIELD("bytes_used", "uint64", 120, 8, SX_SIZE),
    SX_FIELD("root_directory_object_id", "uint64", 128, 8, SX_ID),
    SX_FIELD("device_count", "uint64", 136, 8, SX_COUNT_PROP),
    SX_FIELD("sector_size", "uint32", 144, 4, SX_SIZE),
    SX_FIELD("node_size", "uint32", 148, 4, SX_SIZE),
    SX_FIELD("unused_leaf_size", "uint32", 152, 4, SX_RESERVED),
    SX_FIELD("stripe_size", "uint32", 156, 4, SX_SIZE),
    SX_FIELD("system_chunk_array_size", "uint32", 160, 4, SX_SIZE),
    SX_FIELD("chunk_root_generation", "uint64", 164, 8, SX_NONE),
    SX_FIELD("compatible_flags", "uint64", 172, 8, SX_FLAGS),
    SX_FIELD("readonly_compatible_flags", "uint64", 180, 8, SX_FLAGS),
    SX_FIELD("incompatible_flags", "uint64", 188, 8, SX_FLAGS),
    SX_FIELD("checksum_type", "uint16", 196, 2, SX_ID),
    SX_FIELD("root_level", "uint8", 198, 1, SX_NONE),
    SX_FIELD("chunk_root_level", "uint8", 199, 1, SX_NONE),
    SX_FIELD("log_root_level", "uint8", 200, 1, SX_NONE),
};
static const sx_layout sxc_btrfs_superblock_header = {UINT32_C(0x60180014),"btrfs_superblock_header",sxc_btrfs_superblock_header_fields,SX_COUNT(sxc_btrfs_superblock_header_fields),SX_LE};

static const xx_data_struct_field_desc sxc_btrfs_device_item_fields[] = {
    SX_FIELD("device_id", "uint64", 0, 8, SX_ID),
    SX_FIELD("total_bytes", "uint64", 8, 8, SX_SIZE),
    SX_FIELD("bytes_used", "uint64", 16, 8, SX_SIZE),
    SX_FIELD("io_alignment", "uint32", 24, 4, SX_SIZE),
    SX_FIELD("io_width", "uint32", 28, 4, SX_SIZE),
    SX_FIELD("sector_size", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("type", "uint64", 36, 8, SX_FLAGS),
    SX_FIELD("generation", "uint64", 44, 8, SX_NONE),
    SX_FIELD("start_offset", "uint64", 52, 8, SX_OFFSET),
    SX_FIELD("device_group", "uint32", 60, 4, SX_NONE),
    SX_FIELD("seek_speed", "uint8", 64, 1, SX_NONE),
    SX_FIELD("bandwidth", "uint8", 65, 1, SX_NONE),
    SX_FIELD("device_uuid", "uint8[16]", 66, 16, SX_NONE),
    SX_FIELD("filesystem_uuid", "uint8[16]", 82, 16, SX_NONE),
};
static const sx_layout sxc_btrfs_device_item = {UINT32_C(0x60180015),"btrfs_device_item",sxc_btrfs_device_item_fields,SX_COUNT(sxc_btrfs_device_item_fields),SX_LE};

static const xx_data_struct_field_desc sxc_btrfs_superblock_tail_fields[] = {
    SX_FIELD("label", "char[256]", 0, 256, SX_STRING),
    SX_FIELD("cache_generation", "uint64", 256, 8, SX_NONE),
    SX_FIELD("uuid_tree_generation", "uint64", 264, 8, SX_NONE),
    SX_FIELD("metadata_uuid", "uint8[16]", 272, 16, SX_NONE),
    SX_FIELD("global_root_count", "uint64", 288, 8, SX_COUNT_PROP),
    SX_FIELD("remap_root_logical_address", "uint64", 296, 8, SX_ADDRESS),
    SX_FIELD("remap_root_generation", "uint64", 304, 8, SX_NONE),
    SX_FIELD("remap_root_level", "uint8", 312, 1, SX_NONE),
    SX_FIELD("reserved", "bytes", 313, 199, SX_RESERVED),
};
static const sx_layout sxc_btrfs_superblock_tail = {UINT32_C(0x60180016),"btrfs_superblock_tail",sxc_btrfs_superblock_tail_fields,SX_COUNT(sxc_btrfs_superblock_tail_fields),SX_LE};

static const xx_data_struct_field_desc sxc_btrfs_root_backup_fields[] = {
    SX_FIELD("tree_root_logical_address", "uint64", 0, 8, SX_ADDRESS),
    SX_FIELD("tree_root_generation", "uint64", 8, 8, SX_NONE),
    SX_FIELD("chunk_root_logical_address", "uint64", 16, 8, SX_ADDRESS),
    SX_FIELD("chunk_root_generation", "uint64", 24, 8, SX_NONE),
    SX_FIELD("extent_root_logical_address", "uint64", 32, 8, SX_ADDRESS),
    SX_FIELD("extent_root_generation", "uint64", 40, 8, SX_NONE),
    SX_FIELD("filesystem_root_logical_address", "uint64", 48, 8, SX_ADDRESS),
    SX_FIELD("filesystem_root_generation", "uint64", 56, 8, SX_NONE),
    SX_FIELD("device_root_logical_address", "uint64", 64, 8, SX_ADDRESS),
    SX_FIELD("device_root_generation", "uint64", 72, 8, SX_NONE),
    SX_FIELD("checksum_root_logical_address", "uint64", 80, 8, SX_ADDRESS),
    SX_FIELD("checksum_root_generation", "uint64", 88, 8, SX_NONE),
    SX_FIELD("total_bytes", "uint64", 96, 8, SX_SIZE),
    SX_FIELD("bytes_used", "uint64", 104, 8, SX_SIZE),
    SX_FIELD("device_count", "uint64", 112, 8, SX_COUNT_PROP),
    SX_FIELD("reserved64_0", "uint64", 120, 8, SX_RESERVED),
    SX_FIELD("reserved64_1", "uint64", 128, 8, SX_RESERVED),
    SX_FIELD("reserved64_2", "uint64", 136, 8, SX_RESERVED),
    SX_FIELD("reserved64_3", "uint64", 144, 8, SX_RESERVED),
    SX_FIELD("tree_root_level", "uint8", 152, 1, SX_NONE),
    SX_FIELD("chunk_root_level", "uint8", 153, 1, SX_NONE),
    SX_FIELD("extent_root_level", "uint8", 154, 1, SX_NONE),
    SX_FIELD("filesystem_root_level", "uint8", 155, 1, SX_NONE),
    SX_FIELD("device_root_level", "uint8", 156, 1, SX_NONE),
    SX_FIELD("checksum_root_level", "uint8", 157, 1, SX_NONE),
    SX_FIELD("reserved8", "uint8[10]", 158, 10, SX_RESERVED),
};
static const sx_layout sxc_btrfs_root_backup = {UINT32_C(0x60180017),"btrfs_root_backup",sxc_btrfs_root_backup_fields,SX_COUNT(sxc_btrfs_root_backup_fields),SX_LE};

static const xx_data_struct_field_desc sxc_btrfs_superblock_padding_fields[] = {
    SX_FIELD("padding", "bytes", 0, 565, SX_RESERVED),
};
static const sx_layout sxc_btrfs_superblock_padding = {UINT32_C(0x60180018),"btrfs_superblock_padding",sxc_btrfs_superblock_padding_fields,SX_COUNT(sxc_btrfs_superblock_padding_fields),SX_LE};

static const xx_data_struct_field_desc sxc_btrfs_disk_key_fields[] = {
    SX_FIELD("object_id", "uint64", 0, 8, SX_ID),
    SX_FIELD("type", "uint8", 8, 1, SX_ID),
    SX_FIELD("offset", "uint64", 9, 8, SX_NONE),
};
static const sx_layout sxc_btrfs_disk_key = {UINT32_C(0x60180019),"btrfs_disk_key",sxc_btrfs_disk_key_fields,SX_COUNT(sxc_btrfs_disk_key_fields),SX_LE};

static const xx_data_struct_field_desc sxc_btrfs_chunk_fields[] = {
    SX_FIELD("length", "uint64", 0, 8, SX_SIZE),
    SX_FIELD("owner_object_id", "uint64", 8, 8, SX_ID),
    SX_FIELD("stripe_length", "uint64", 16, 8, SX_SIZE),
    SX_FIELD("type", "uint64", 24, 8, SX_FLAGS),
    SX_FIELD("io_alignment", "uint32", 32, 4, SX_SIZE),
    SX_FIELD("io_width", "uint32", 36, 4, SX_SIZE),
    SX_FIELD("sector_size", "uint32", 40, 4, SX_SIZE),
    SX_FIELD("stripe_count", "uint16", 44, 2, SX_COUNT_PROP),
    SX_FIELD("sub_stripe_count", "uint16", 46, 2, SX_COUNT_PROP),
};
static const sx_layout sxc_btrfs_chunk = {UINT32_C(0x6018001A),"btrfs_chunk",sxc_btrfs_chunk_fields,SX_COUNT(sxc_btrfs_chunk_fields),SX_LE};

static const xx_data_struct_field_desc sxc_btrfs_stripe_fields[] = {
    SX_FIELD("device_id", "uint64", 0, 8, SX_ID),
    SX_FIELD("physical_offset", "uint64", 8, 8, SX_OFFSET),
    SX_FIELD("device_uuid", "uint8[16]", 16, 16, SX_NONE),
};
static const sx_layout sxc_btrfs_stripe = {UINT32_C(0x6018001B),"btrfs_stripe",sxc_btrfs_stripe_fields,SX_COUNT(sxc_btrfs_stripe_fields),SX_LE};

static const xx_data_struct_field_desc sxc_btrfs_tree_header_fields[] = {
    SX_FIELD("checksum", "uint8[32]", 0, 32, SX_CHECKSUM),
    SX_FIELD("fsid", "uint8[16]", 32, 16, SX_NONE),
    SX_FIELD("logical_address", "uint64", 48, 8, SX_ADDRESS),
    SX_FIELD("flags", "uint64", 56, 8, SX_FLAGS),
    SX_FIELD("chunk_tree_uuid", "uint8[16]", 64, 16, SX_NONE),
    SX_FIELD("generation", "uint64", 80, 8, SX_NONE),
    SX_FIELD("owner_object_id", "uint64", 88, 8, SX_ID),
    SX_FIELD("item_count", "uint32", 96, 4, SX_COUNT_PROP),
    SX_FIELD("level", "uint8", 100, 1, SX_NONE),
};
static const sx_layout sxc_btrfs_tree_header = {UINT32_C(0x6018001C),"btrfs_tree_header",sxc_btrfs_tree_header_fields,SX_COUNT(sxc_btrfs_tree_header_fields),SX_LE};

static const xx_data_struct_field_desc sxc_btrfs_leaf_item_fields[] = {
    SX_FIELD("key_object_id", "uint64", 0, 8, SX_ID),
    SX_FIELD("key_type", "uint8", 8, 1, SX_ID),
    SX_FIELD("key_offset", "uint64", 9, 8, SX_NONE),
    SX_FIELD("data_offset", "uint32", 17, 4, SX_OFFSET),
    SX_FIELD("data_size", "uint32", 21, 4, SX_SIZE),
};
static const sx_layout sxc_btrfs_leaf_item = {UINT32_C(0x6018001D),"btrfs_leaf_item",sxc_btrfs_leaf_item_fields,SX_COUNT(sxc_btrfs_leaf_item_fields),SX_LE};

static const xx_data_struct_field_desc sxc_btrfs_key_pointer_fields[] = {
    SX_FIELD("key_object_id", "uint64", 0, 8, SX_ID),
    SX_FIELD("key_type", "uint8", 8, 1, SX_ID),
    SX_FIELD("key_offset", "uint64", 9, 8, SX_NONE),
    SX_FIELD("child_logical_address", "uint64", 17, 8, SX_ADDRESS),
    SX_FIELD("generation", "uint64", 25, 8, SX_NONE),
};
static const sx_layout sxc_btrfs_key_pointer = {UINT32_C(0x6018001E),"btrfs_key_pointer",sxc_btrfs_key_pointer_fields,SX_COUNT(sxc_btrfs_key_pointer_fields),SX_LE};

static const sx_layout *const sx_cowfs_layouts[] = {
    &sxc_apfs_object_header,
    &sxc_apfs_container_header,
    &sxc_apfs_file_system_oid,
    &sxc_apfs_container_counter,
    &sxc_apfs_container_tail,
    &sxc_apfs_checkpoint_map,
    &sxc_apfs_checkpoint_mapping,
    &sxc_apfs_object_map,
    &sxc_apfs_btree_node,
    &sxc_apfs_btree_info,
    &sxc_apfs_btree_kvoff,
    &sxc_apfs_btree_kvloc,
    &sxc_apfs_omap_key,
    &sxc_apfs_omap_value,
    &sxc_apfs_btree_child,
    &sxc_apfs_volume_header,
    &sxc_apfs_modified_by,
    &sxc_apfs_volume_name,
    &sxc_apfs_volume_tail,
    &sxc_btrfs_superblock_header,
    &sxc_btrfs_device_item,
    &sxc_btrfs_superblock_tail,
    &sxc_btrfs_root_backup,
    &sxc_btrfs_superblock_padding,
    &sxc_btrfs_disk_key,
    &sxc_btrfs_chunk,
    &sxc_btrfs_stripe,
    &sxc_btrfs_tree_header,
    &sxc_btrfs_leaf_item,
    &sxc_btrfs_key_pointer,
};

#include "xxfclib/formats/filesystem/apfs/xx_apfs.h"
#include "xxfclib/formats/filesystem/btrfs/xx_btrfs.h"
static bool sx_cowfs_supports(xx_file_type_t t){return t==XX_FILE_TYPE_APFS||t==XX_FILE_TYPE_BTRFS;}
static uint16_t sxc_u16(const uint8_t *p){return xx_data_get_u16(p,2,0,false);}
static uint32_t sxc_u32(const uint8_t *p){return xx_data_get_u32(p,4,0,false);}
static uint64_t sxc_u64(const uint8_t *p){return xx_data_get_u64(p,8,0,false);}
static bool sxc_can(sx_context *c,int64_t at,uint64_t n){return at>=0&&at<=c->size&&n<=(uint64_t)(c->size-at)&&!xx_pd_is_stopped(c->pd);}
static bool sxc_add(sx_context *c,const sx_layout *l,int64_t at,int64_t n)
{
    if(n<=0||!sxc_can(c,at,(uint64_t)n)||at>INT64_MAX-c->f->base_address)return false;
    for(size_t i=0;i<c->count;i++)if(c->items[i].offset==c->f->base_address+at&&c->items[i].id==l->id&&c->items[i].total_size==n)return true;
    return sx_add(c,l,at,n);
}
static bool sxc_table(sx_context *c,const sx_layout *l,int64_t at,int64_t entry,uint64_t count)
{
    if(!count)return true;if(entry<=0||count>(uint64_t)INT64_MAX/(uint64_t)entry)return false;int64_t size=(int64_t)count*entry;
    if(!sxc_can(c,at,(uint64_t)size)||at>INT64_MAX-c->f->base_address)return false;
    for(size_t i=0;i<c->count;i++)if(c->items[i].offset==c->f->base_address+at&&c->items[i].id==l->id&&c->items[i].total_size==size&&c->items[i].entry_size==entry&&c->items[i].count==count)return true;
    return sx_table(c,l,at,entry,count);
}
static int sxc_order(const void *left,const void *right)
{
    const xx_data_struct *a=left,*b=right;return a->offset<b->offset?-1:a->offset>b->offset?1:0;
}
static bool sxc_finish(sx_context *c)
{
    size_t count=c->count;int64_t end=0;
    xx_rt_qsort(c->items,count,sizeof(*c->items),sxc_order);
    for(size_t i=0;i<count;i++){int64_t at=c->items[i].offset-c->f->base_address,n=c->items[i].total_size;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+n;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;
    xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxc_order);
    return !c->failed;
}
/* Local checks avoid introducing a codec or native-reader link dependency in
 * minimal/bytecode profiles. Each algorithm checks the physical object bytes. */
static uint64_t sxc_fletcher(const uint8_t *p,uint32_t n)
{
    const uint64_t mod=UINT64_C(0xffffffff);uint64_t a=0,b=0;
    for(uint32_t i=8;i<n;i+=4){a=(a+sxc_u32(p+i))%mod;b=(b+a)%mod;}
    uint64_t lo=mod-(a+b)%mod,hi=mod-(a+lo)%mod;return lo|(hi<<32);
}
static uint32_t sxc_crc32c(const uint8_t *p,uint32_t n)
{
    uint32_t crc=UINT32_MAX;for(uint32_t i=0;i<n;i++){crc^=p[i];for(unsigned j=0;j<8;j++)crc=(crc>>1)^((crc&1)?UINT32_C(0x82f63b78):0);}return ~crc;
}
static bool sxc_apfs_object(sx_context *c,uint64_t block,uint32_t unit,uint8_t *b,int64_t *at)
{
    if(!unit||block>(uint64_t)INT64_MAX/unit)return false;*at=(int64_t)(block*unit);
    return sxc_can(c,*at,unit)&&sx_read(c,*at,b,unit)&&sxc_u64(b)==sxc_fletcher(b,unit);
}
static bool sxc_apfs_container(sx_context *c,int64_t at,const uint8_t *b,uint32_t unit)
{
    if(unit<184||xx_rt_memcmp(b+32,"NXSB",4)||(sxc_u32(b+24)&65535)!=1||sxc_u32(b+36)!=unit||!sxc_u64(b+40)||!sxc_u32(b+180)||sxc_u32(b+180)>100)return false;
    if(!sxc_add(c,&sxc_apfs_container_header,at,184))return false;
    uint32_t slots=(unit-184)/8;if(slots>100)slots=100;
    if(slots&&!sxc_table(c,&sxc_apfs_file_system_oid,at+184,8,slots))return false;
    if(unit>=984){uint32_t counters=(unit-984)/8;if(counters>32)counters=32;if(counters&&!sxc_table(c,&sxc_apfs_container_counter,at+984,8,counters))return false;}
    if(unit>=1408&&!sxc_add(c,&sxc_apfs_container_tail,at+1240,168))return false;
    return true;
}
typedef struct sxc_apfs_work {uint64_t block;uint32_t key_size,value_size;unsigned depth;} sxc_apfs_work;
static bool sxc_apfs_tree(sx_context *c,uint64_t root,uint32_t unit)
{
    uint8_t *b=xx_mem_alloc(unit);sxc_apfs_work *queue=xx_mem_alloc(4096*sizeof(*queue));size_t count=1;bool ok=false;
    if(!b||!queue)goto done;queue[0]=(sxc_apfs_work){root,0,0,0};
    for(size_t q=0;q<count;q++){
        if(xx_pd_is_stopped(c->pd))goto done;if(queue[q].depth>64)goto done;int64_t at;
        if(!sxc_apfs_object(c,queue[q].block,unit,b,&at))continue;
        uint32_t type=sxc_u32(b+24)&65535;if((type!=2&&type!=3)||sxc_u32(b+28)!=11)continue;
        uint16_t flags=sxc_u16(b+32);uint32_t n=sxc_u32(b+36),toc=56U+sxc_u16(b+40),len=sxc_u16(b+42),end=unit-((flags&1)?40:0),entry=(flags&4)?4:8;
        uint32_t key_size=queue[q].key_size,value_size=queue[q].value_size;if(flags&1){key_size=sxc_u32(b+end+8);value_size=sxc_u32(b+end+12);}
        if(toc>end||len>end-toc||n>len/entry||((flags&4)&&(!key_size||key_size>unit)))continue;
        uint32_t key_base=toc+len;bool good=true;
        for(uint32_t i=0;i<n;i++){
            const uint8_t *p=b+toc+i*entry;uint32_t ko=sxc_u16(p),kl=(flags&4)?key_size:sxc_u16(p+2),vo=sxc_u16(p+((flags&4)?2:4)),vl=(flags&4)?((flags&2)?value_size:8):sxc_u16(p+6);
            if(ko>end-key_base||kl>end-key_base-ko||vo>end||vl>vo||end-vo<key_base+ko+kl){good=false;break;}
        }if(!good)continue;
        if(!sxc_add(c,&sxc_apfs_btree_node,at,56))goto done;
        if(n&&!sxc_table(c,(flags&4)?&sxc_apfs_btree_kvoff:&sxc_apfs_btree_kvloc,at+toc,entry,n))goto done;
        if((flags&1)&&!sxc_add(c,&sxc_apfs_btree_info,at+end,40))goto done;
        for(uint32_t i=0;i<n;i++){
            const uint8_t *p=b+toc+i*entry;uint32_t ko=sxc_u16(p),kl=(flags&4)?key_size:sxc_u16(p+2),vo=sxc_u16(p+((flags&4)?2:4)),vl=(flags&4)?((flags&2)?value_size:8):sxc_u16(p+6),value=end-vo;
            if(kl==16&&!sxc_add(c,&sxc_apfs_omap_key,at+key_base+ko,16))goto done;
            if(flags&2){if(vl==16&&!sxc_add(c,&sxc_apfs_omap_value,at+value,16))goto done;}
            else if(vl>=8){
                if(!sxc_add(c,&sxc_apfs_btree_child,at+value,8))goto done;uint64_t child=sxc_u64(b+value);bool seen=false;for(size_t j=0;j<count;j++)if(queue[j].block==child)seen=true;
                if(!seen){if(count>=4096)goto done;queue[count++]=(sxc_apfs_work){child,key_size,value_size,queue[q].depth+1};}
            }
        }
    }ok=true;
done:xx_mem_free(queue);xx_mem_free(b);return ok;
}
static bool sxc_apfs_omap(sx_context *c,uint64_t block,uint32_t unit)
{
    if(!block)return true;uint8_t b[88];int64_t at;if(block>(uint64_t)INT64_MAX/unit)return true;at=(int64_t)(block*unit);
    uint8_t *full=xx_mem_alloc(unit);if(!full)return false;bool valid=sxc_apfs_object(c,block,unit,full,&at)&&(sxc_u32(full+24)&65535)==11;
    if(valid)xx_rt_memcpy(b,full,88);xx_mem_free(full);if(!valid)return !c->failed&&!xx_pd_is_stopped(c->pd);
    return sxc_add(c,&sxc_apfs_object_map,at,88)&&sxc_apfs_tree(c,sxc_u64(b+48),unit);
}
static bool sxc_apfs_build(sx_context *c)
{
    const xx_apfs *f=(const xx_apfs *)c->f;uint32_t unit=f->block_size;uint8_t *b=xx_mem_alloc(unit);bool ok=false;int64_t at;uint64_t base;uint32_t count;
    if(!b||unit<512||unit>65536||(unit&(unit-1)))goto done;
    if(!sxc_apfs_object(c,0,unit,b,&at)||!sxc_apfs_container(c,at,b,unit))goto done;
    base=sxc_u64(b+112);count=sxc_u32(b+104);
    /* The initial descriptor range is frozen before scanning checkpoints. */
    if(!(count&UINT32_C(0x80000000))&&count<=8192&&base&&base<=INT64_MAX){
        for(uint32_t i=0;i<count;i++){
            if(xx_pd_is_stopped(c->pd))goto done;if(base>UINT64_MAX-i)break;if(!sxc_apfs_object(c,base+i,unit,b,&at))continue;uint32_t type=sxc_u32(b+24)&65535;
            if(type==1){size_t saved=c->count;if(!sxc_apfs_container(c,at,b,unit)){if(c->failed)goto done;c->count=saved;}}
            else if(type==12){uint32_t n=sxc_u32(b+36);if(n>(unit-40)/40)continue;if(!sxc_add(c,&sxc_apfs_checkpoint_map,at,40)||(n&&!sxc_table(c,&sxc_apfs_checkpoint_mapping,at+40,40,n)))goto done;}
            else if(type!=2&&type!=3&&type!=11&&type!=13){if(!sxc_add(c,&sxc_apfs_object_header,at,32))goto done;}
        }
    }
    if(!sxc_apfs_omap(c,f->omap_oid,unit))goto done;
    for(uint32_t i=0;i<f->volume_count&&i<100;i++){
        const xx_apfs_volume_info *v=&f->volumes[i];if(!v->superblock_valid||v->block<0)continue;
        if(!sxc_apfs_object(c,(uint64_t)v->block,unit,b,&at)||(sxc_u32(b+24)&65535)!=13||xx_rt_memcmp(b+32,"APSB",4))continue;
        if(!sxc_add(c,&sxc_apfs_volume_header,at,272))goto done;
        uint32_t records=(unit-272)/48;if(records>9)records=9;if(records&&!sxc_table(c,&sxc_apfs_modified_by,at+272,48,records))goto done;
        if(unit>=960&&!sxc_add(c,&sxc_apfs_volume_name,at+704,256))goto done;
        if(unit>=1056&&!sxc_add(c,&sxc_apfs_volume_tail,at+960,96))goto done;
        if(!sxc_apfs_omap(c,v->omap_oid,unit))goto done;
    }ok=true;
done:xx_mem_free(b);return ok;
}
typedef struct sxc_bt_mapping {uint64_t logical,length,physical;} sxc_bt_mapping;
typedef struct sxc_bt_maps {sxc_bt_mapping rows[128];size_t count;} sxc_bt_maps;
static bool sxc_bt_chunk(sx_context *c,int64_t at,const uint8_t *p,uint32_t available,uint64_t logical,uint64_t device,sxc_bt_maps *maps)
{
    if(available<48)return false;uint16_t n=sxc_u16(p+44);if(!n||n>(available-48)/32)return false;
    if(!sxc_add(c,&sxc_btrfs_chunk,at,48)||!sxc_table(c,&sxc_btrfs_stripe,at+48,32,n))return false;
    uint64_t length=sxc_u64(p);if(maps&&length&&logical<=UINT64_MAX-length&&!(sxc_u64(p+24)&(8|64|128|256))){
        for(uint16_t i=0;i<n;i++)if(sxc_u64(p+48+i*32)==device){
            size_t row=0;while(row<maps->count&&maps->rows[row].logical!=logical)row++;
            if(row==maps->count){if(row>=128)return false;maps->count++;}
            maps->rows[row]=(sxc_bt_mapping){logical,length,sxc_u64(p+56+i*32)};break;
        }
    }return true;
}
static bool sxc_bt_physical(sx_context *c,const sxc_bt_maps *maps,uint64_t logical,uint32_t size,int64_t *at)
{
    for(size_t i=0;i<maps->count;i++){
        const sxc_bt_mapping *m=&maps->rows[i];if(logical<m->logical||logical-m->logical>=m->length)continue;uint64_t delta=logical-m->logical;
        if(size>m->length-delta||m->physical>UINT64_MAX-delta||m->physical+delta>INT64_MAX)return false;*at=(int64_t)(m->physical+delta);return sxc_can(c,*at,size);
    }return false;
}
static bool sxc_bt_super_valid(sx_context *c,int64_t at,uint8_t b[4096])
{
    if(!sxc_can(c,at,4096)||!sx_read(c,at,b,4096)||xx_rt_memcmp(b+64,"_BHRfS_M",8)||sxc_u64(b+48)!=(uint64_t)at)return false;
    uint32_t unit=sxc_u32(b+144),node=sxc_u32(b+148);
    if(node<4096||node>65536||(node&(node-1))||unit<512||unit>node||(unit&(unit-1))||sxc_u32(b+160)>2048||!sxc_u64(b+136)||b[198]>64||b[199]>64)return false;
    return sxc_u16(b+196)!=0||sxc_u32(b)==sxc_crc32c(b+32,4064);
}
static bool sxc_bt_super(sx_context *c,int64_t at,const uint8_t b[4096],sxc_bt_maps *maps)
{
    if(!sxc_add(c,&sxc_btrfs_superblock_header,at,201)||!sxc_add(c,&sxc_btrfs_device_item,at+201,98)||!sxc_add(c,&sxc_btrfs_superblock_tail,at+299,512)||!sxc_table(c,&sxc_btrfs_root_backup,at+2859,168,4)||!sxc_add(c,&sxc_btrfs_superblock_padding,at+3531,565))return false;
    uint32_t bytes=sxc_u32(b+160),pos=811,end=811+bytes;
    while(end-pos>=65){const uint8_t *p=b+pos;uint16_t n=sxc_u16(p+17+44);if(p[8]!=228||sxc_u64(p)!=256||!n||n>(end-pos-65)/32)break;
        if(!sxc_add(c,&sxc_btrfs_disk_key,at+pos,17)||!sxc_bt_chunk(c,at+pos+17,p+17,end-pos-17,sxc_u64(p+9),sxc_u64(b+201),maps))return false;pos+=65U+(uint32_t)n*32;
    }return true;
}
typedef struct sxc_bt_work {uint64_t logical;unsigned depth;} sxc_bt_work;
static bool sxc_bt_tree(sx_context *c,const xx_btrfs *f,sxc_bt_maps *maps)
{
    uint32_t unit=f->node_size;uint8_t *b=xx_mem_alloc(unit);sxc_bt_work *queue=xx_mem_alloc(4096*sizeof(*queue));size_t count=0;bool ok=false;
    if(!b||!queue)goto done;
    uint64_t roots[]={f->chunk_root,f->root_tree,f->fs_tree_root};size_t q=0;
    /* Complete the chunk-tree mapping pass before scheduling other roots. */
    for(unsigned phase=0;phase<2;phase++){
    for(unsigned i=phase?1:0;i<(phase?3:1);i++)if(roots[i]){bool seen=false;for(size_t j=0;j<count;j++)if(queue[j].logical==roots[i])seen=true;if(!seen){if(count>=4096)goto done;queue[count++]=(sxc_bt_work){roots[i],0};}}
    for(;q<count;q++){
        if(xx_pd_is_stopped(c->pd)||queue[q].depth>64)goto done;int64_t at;uint64_t logical=queue[q].logical;
        if(!sxc_bt_physical(c,maps,logical,unit,&at)||!sx_read(c,at,b,unit))continue;
        if(sxc_u32(b)!=sxc_crc32c(b+32,unit-32)||sxc_u64(b+48)!=logical||(xx_rt_memcmp(b+32,f->fsid,16)&&xx_rt_memcmp(b+32,f->metadata_uuid,16)))continue;
        uint32_t n=sxc_u32(b+96),entry=b[100]?33:25;if(b[100]>64||n>(unit-101)/entry)continue;
        bool good=true;for(uint32_t i=0;i<n&&!b[100];i++){const uint8_t *p=b+101+i*25;uint32_t pos=sxc_u32(p+17),size=sxc_u32(p+21);if(pos>unit-101||size>unit-101-pos||pos<n*25){good=false;break;}}if(!good)continue;
        if(!sxc_add(c,&sxc_btrfs_tree_header,at,101)||(n&&!sxc_table(c,b[100]?&sxc_btrfs_key_pointer:&sxc_btrfs_leaf_item,at+101,entry,n)))goto done;
        for(uint32_t i=0;i<n;i++){
            const uint8_t *p=b+101+i*entry;
            if(b[100]){uint64_t child=sxc_u64(p+17);bool seen=false;for(size_t j=0;j<count;j++)if(queue[j].logical==child)seen=true;if(!seen){if(count>=4096)goto done;queue[count++]=(sxc_bt_work){child,queue[q].depth+1};}}
            else if(p[8]==228&&sxc_u64(p)==256){uint32_t pos=101+sxc_u32(p+17),size=sxc_u32(p+21);if(size>=48){uint16_t stripes=sxc_u16(b+pos+44);if(stripes&&stripes<=(size-48)/32&&!sxc_bt_chunk(c,at+pos,b+pos,size,sxc_u64(p+9),f->devid,maps))goto done;}}
        }
    }}ok=true;
done:xx_mem_free(queue);xx_mem_free(b);return ok;
}
static bool sxc_btrfs_build(sx_context *c)
{
    const xx_btrfs *f=(const xx_btrfs *)c->f;int64_t at=f->super_offset-c->f->base_address;uint8_t b[4096];sxc_bt_maps maps;xx_rt_memset(&maps,0,sizeof(maps));
    if(!sxc_bt_super_valid(c,at,b)||!sxc_bt_super(c,at,b,&maps))return false;
    const int64_t mirrors[]={INT64_C(0x10000),INT64_C(0x4000000),INT64_C(0x4000000000)};
    for(unsigned i=0;i<3;i++)if(mirrors[i]!=at&&sxc_bt_super_valid(c,mirrors[i],b)&&!xx_rt_memcmp(b+32,f->fsid,16)&&!sxc_bt_super(c,mirrors[i],b,NULL))return false;
    return f->csum_type!=0||sxc_bt_tree(c,f,&maps);
}
static bool sx_cowfs_build(sx_context *c)
{
    if(!c->f->handle_base_info||!xx_format_handle_base_info(c->f,c->pd)||!c->f->is_valid)return false;
    bool ok=c->f->file_type==XX_FILE_TYPE_APFS?sxc_apfs_build(c):c->f->file_type==XX_FILE_TYPE_BTRFS?sxc_btrfs_build(c):false;
    return ok&&c->count&&sxc_finish(c);
}
static bool sxc_has(const wchar_t *s,const wchar_t *p){size_t n=xx_rt_wcslen(p);for(;*s;s++)if(!xx_rt_wcsncmp(s,p,n))return true;return false;}
static bool sx_cowfs_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<UINT32_C(0x60180000)||id>=UINT32_C(0x60190000))return true;
    const wchar_t *n=r->name,*text=NULL;uint64_t v=xx_var_get_u64(&r->value);
    if(id<sxc_btrfs_superblock_header.id){
        if(!xx_rt_wcscmp(n,L"checksum"))text=L"Fletcher-64 over the remaining bytes of this physical APFS block";
        if(sxc_has(n,L"_block")||sxc_has(n,L"_blocks")||sxc_has(n,L"_base")||!xx_rt_wcscmp(n,L"block_count"))text=L"Container block units; byte position or length = value * container block size";
        if(sxc_has(n,L"blocks_flags"))text=L"Low 31 bits: block count; high bit: descriptor/data area is represented by a tree";
        if(sxc_has(n,L"_time")||!xx_rt_wcscmp(n,L"timestamp"))text=L"Nanoseconds since 1970-01-01 UTC";
        if(!xx_rt_wcscmp(n,L"object_type"))text=(v&65535)==1?L"OBJECT_TYPE_NX_SUPERBLOCK (low 16 bits); upper bits are object flags":(v&65535)==2?L"OBJECT_TYPE_BTREE":(v&65535)==3?L"OBJECT_TYPE_BTREE_NODE":(v&65535)==5?L"OBJECT_TYPE_SPACEMAN":(v&65535)==11?L"OBJECT_TYPE_OMAP":(v&65535)==12?L"OBJECT_TYPE_CHECKPOINT_MAP":(v&65535)==13?L"OBJECT_TYPE_FS":NULL;
        if(!xx_rt_wcscmp(n,L"omap_oid")||!xx_rt_wcscmp(n,L"tree_oid"))text=L"Physical object identifier: container block number";
        if(!xx_rt_wcscmp(n,L"key_offset"))text=L"Byte offset from the start of the B-tree key area";
        if(!xx_rt_wcscmp(n,L"value_offset"))text=L"Positive byte distance backwards from the end of the B-tree value area";
        if(id==sxc_apfs_btree_node.id&&!xx_rt_wcscmp(n,L"flags"))text=L"Bits: 0 root, 1 leaf, 2 fixed key/value size, 3 hashed, 4 noheader";
        if(id==sxc_apfs_omap_value.id&&!xx_rt_wcscmp(n,L"flags"))text=L"Bits: 0 deleted, 1 saved, 2 encrypted, 3 noheader, 4 crypto generation";
    }else{
        if(!xx_rt_wcscmp(n,L"checksum"))text=L"Checksum of bytes after this 32-byte field; algorithm selected by the superblock checksum_type";
        if(sxc_has(n,L"logical_address"))text=L"Btrfs logical byte address; translate through the chunk map before seeking on a device";
        if(!xx_rt_wcscmp(n,L"checksum_type"))text=v==0?L"BTRFS_CSUM_TYPE_CRC32 (CRC32C)":v==1?L"BTRFS_CSUM_TYPE_XXHASH":v==2?L"BTRFS_CSUM_TYPE_SHA256":v==3?L"BTRFS_CSUM_TYPE_BLAKE2":NULL;
        if(!xx_rt_wcscmp(n,L"data_offset"))text=L"Byte offset from the end of the 101-byte tree header";
        if(!xx_rt_wcscmp(n,L"offset")||!xx_rt_wcscmp(n,L"key_offset"))text=L"Key-dependent value: object-specific offset, logical address, hash or identifier";
        if((id==sxc_btrfs_disk_key.id||id==sxc_btrfs_leaf_item.id||id==sxc_btrfs_key_pointer.id)&&(sxc_has(n,L"type")))text=v==228?L"BTRFS_CHUNK_ITEM_KEY":v==132?L"BTRFS_ROOT_ITEM_KEY":v==1?L"BTRFS_INODE_ITEM_KEY":v==84?L"BTRFS_DIR_ITEM_KEY":v==108?L"BTRFS_EXTENT_DATA_KEY":NULL;
        if(id==sxc_btrfs_chunk.id&&!xx_rt_wcscmp(n,L"type"))text=L"Bits: 0 DATA, 1 SYSTEM, 2 METADATA, 3 RAID0, 4 RAID1, 5 DUP, 6 RAID10, 7 RAID5, 8 RAID6, 9 RAID1C3, 10 RAID1C4";
    }
    return !text||xx_data_struct_record_set_comment(r,text);
}
