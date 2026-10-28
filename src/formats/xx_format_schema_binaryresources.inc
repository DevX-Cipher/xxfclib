/* SPDX-License-Identifier: MIT
 * Binary resource and firmware metadata. Scope: docs/data_struct_binaryresources_scope.txt. */
static const xx_data_struct_field_desc sxbrs_ota_bitmap_short_fields[] = {
    SX_FIELD("infofield","uint8",0,1,SX_FLAGS),
    SX_FIELD("width","uint8",1,1,SX_NONE),
    SX_FIELD("height","uint8",2,1,SX_NONE),
    SX_FIELD("depth","uint8",3,1,SX_NONE),
};
static const sx_layout sxbrs_ota_bitmap_short = {UINT32_C(0x603e0001),"ota_bitmap_short",sxbrs_ota_bitmap_short_fields,SX_COUNT(sxbrs_ota_bitmap_short_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_ota_bitmap_extended_fields[] = {
    SX_FIELD("infofield","uint8",0,1,SX_FLAGS),
    SX_FIELD("width","uint16",1,2,SX_NONE),
    SX_FIELD("height","uint16",3,2,SX_NONE),
    SX_FIELD("depth","uint8",5,1,SX_NONE),
};
static const sx_layout sxbrs_ota_bitmap_extended = {UINT32_C(0x603e0002),"ota_bitmap_extended",sxbrs_ota_bitmap_extended_fields,SX_COUNT(sxbrs_ota_bitmap_extended_fields),SX_BE};
static const xx_data_struct_field_desc sxbrs_lp_geometry_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("struct_size","uint32",4,4,SX_SIZE),
    SX_FIELD("checksum","uint8[32]",8,32,SX_CHECKSUM),
    SX_FIELD("metadata_max_size","uint32",40,4,SX_SIZE),
    SX_FIELD("metadata_slot_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("logical_block_size","uint32",48,4,SX_SIZE),
};
static const sx_layout sxbrs_lp_geometry = {UINT32_C(0x603e0003),"lp_geometry",sxbrs_lp_geometry_fields,SX_COUNT(sxbrs_lp_geometry_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_lp_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint16",4,2,SX_NONE),
    SX_FIELD("minor_version","uint16",6,2,SX_NONE),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("header_checksum","uint8[32]",12,32,SX_CHECKSUM),
    SX_FIELD("tables_size","uint32",44,4,SX_SIZE),
    SX_FIELD("tables_checksum","uint8[32]",48,32,SX_CHECKSUM),
    SX_FIELD("partitions_offset","uint32",80,4,SX_OFFSET),
    SX_FIELD("partitions_num_entries","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("partitions_entry_size","uint32",88,4,SX_SIZE),
    SX_FIELD("extents_offset","uint32",92,4,SX_OFFSET),
    SX_FIELD("extents_num_entries","uint32",96,4,SX_COUNT_PROP),
    SX_FIELD("extents_entry_size","uint32",100,4,SX_SIZE),
    SX_FIELD("groups_offset","uint32",104,4,SX_OFFSET),
    SX_FIELD("groups_num_entries","uint32",108,4,SX_COUNT_PROP),
    SX_FIELD("groups_entry_size","uint32",112,4,SX_SIZE),
    SX_FIELD("block_devices_offset","uint32",116,4,SX_OFFSET),
    SX_FIELD("block_devices_num_entries","uint32",120,4,SX_COUNT_PROP),
    SX_FIELD("block_devices_entry_size","uint32",124,4,SX_SIZE),
};
static const sx_layout sxbrs_lp_header = {UINT32_C(0x603e0004),"lp_header",sxbrs_lp_header_fields,SX_COUNT(sxbrs_lp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_lp_header_extended_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint16",4,2,SX_NONE),
    SX_FIELD("minor_version","uint16",6,2,SX_NONE),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("header_checksum","uint8[32]",12,32,SX_CHECKSUM),
    SX_FIELD("tables_size","uint32",44,4,SX_SIZE),
    SX_FIELD("tables_checksum","uint8[32]",48,32,SX_CHECKSUM),
    SX_FIELD("partitions_offset","uint32",80,4,SX_OFFSET),
    SX_FIELD("partitions_num_entries","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("partitions_entry_size","uint32",88,4,SX_SIZE),
    SX_FIELD("extents_offset","uint32",92,4,SX_OFFSET),
    SX_FIELD("extents_num_entries","uint32",96,4,SX_COUNT_PROP),
    SX_FIELD("extents_entry_size","uint32",100,4,SX_SIZE),
    SX_FIELD("groups_offset","uint32",104,4,SX_OFFSET),
    SX_FIELD("groups_num_entries","uint32",108,4,SX_COUNT_PROP),
    SX_FIELD("groups_entry_size","uint32",112,4,SX_SIZE),
    SX_FIELD("block_devices_offset","uint32",116,4,SX_OFFSET),
    SX_FIELD("block_devices_num_entries","uint32",120,4,SX_COUNT_PROP),
    SX_FIELD("block_devices_entry_size","uint32",124,4,SX_SIZE),
    SX_FIELD("flags","uint32",128,4,SX_FLAGS),
    SX_FIELD("reserved","uint8[124]",132,124,SX_RESERVED),
};
static const sx_layout sxbrs_lp_header_extended = {UINT32_C(0x603e0005),"lp_header_extended",sxbrs_lp_header_extended_fields,SX_COUNT(sxbrs_lp_header_extended_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_lp_partition_fields[] = {
    SX_FIELD("name","char[36]",0,36,SX_STRING),
    SX_FIELD("attributes","uint32",36,4,SX_FLAGS),
    SX_FIELD("first_extent_index","uint32",40,4,SX_NONE),
    SX_FIELD("num_extents","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("group_index","uint32",48,4,SX_NONE),
};
static const sx_layout sxbrs_lp_partition = {UINT32_C(0x603e0006),"lp_partition",sxbrs_lp_partition_fields,SX_COUNT(sxbrs_lp_partition_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_lp_extent_fields[] = {
    SX_FIELD("num_sectors","uint64",0,8,SX_COUNT_PROP),
    SX_FIELD("target_type","uint32",8,4,SX_ID),
    SX_FIELD("target_data","uint64",12,8,SX_NONE),
    SX_FIELD("target_source","uint32",20,4,SX_NONE),
};
static const sx_layout sxbrs_lp_extent = {UINT32_C(0x603e0007),"lp_extent",sxbrs_lp_extent_fields,SX_COUNT(sxbrs_lp_extent_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_lp_group_fields[] = {
    SX_FIELD("name","char[36]",0,36,SX_STRING),
    SX_FIELD("flags","uint32",36,4,SX_FLAGS),
    SX_FIELD("maximum_size","uint64",40,8,SX_SIZE),
};
static const sx_layout sxbrs_lp_group = {UINT32_C(0x603e0008),"lp_group",sxbrs_lp_group_fields,SX_COUNT(sxbrs_lp_group_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_lp_block_device_fields[] = {
    SX_FIELD("first_logical_sector","uint64",0,8,SX_NONE),
    SX_FIELD("alignment","uint32",8,4,SX_SIZE),
    SX_FIELD("alignment_offset","uint32",12,4,SX_OFFSET),
    SX_FIELD("size","uint64",16,8,SX_SIZE),
    SX_FIELD("partition_name","char[36]",24,36,SX_STRING),
    SX_FIELD("flags","uint32",60,4,SX_FLAGS),
};
static const sx_layout sxbrs_lp_block_device = {UINT32_C(0x603e0009),"lp_block_device",sxbrs_lp_block_device_fields,SX_COUNT(sxbrs_lp_block_device_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_header_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_NONE),
    SX_FIELD("buffer_size_words","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("start16_words","uint32",8,4,SX_NONE),
    SX_FIELD("start8_words","uint32",12,4,SX_NONE),
};
static const sx_layout sxbrs_dts_header = {UINT32_C(0x603e000a),"dts_header",sxbrs_dts_header_fields,SX_COUNT(sxbrs_dts_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_counts_fields[] = {
    SX_FIELD("num_nodes","int32",0,4,SX_COUNT_PROP),
    SX_FIELD("num_objects","int32",4,4,SX_COUNT_PROP),
    SX_FIELD("num_decals","int32",8,4,SX_COUNT_PROP),
    SX_FIELD("num_subshapes","int32",12,4,SX_COUNT_PROP),
    SX_FIELD("num_ifl_materials","int32",16,4,SX_COUNT_PROP),
    SX_FIELD("num_node_rotations","int32",20,4,SX_COUNT_PROP),
    SX_FIELD("num_node_translations","int32",24,4,SX_COUNT_PROP),
    SX_FIELD("num_node_uniform_scales","int32",28,4,SX_COUNT_PROP),
    SX_FIELD("num_node_aligned_scales","int32",32,4,SX_COUNT_PROP),
    SX_FIELD("num_node_arbitrary_scales","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("num_ground_frames","int32",40,4,SX_COUNT_PROP),
    SX_FIELD("num_object_states","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("num_decal_states","int32",48,4,SX_COUNT_PROP),
    SX_FIELD("num_triggers","int32",52,4,SX_COUNT_PROP),
    SX_FIELD("num_details","int32",56,4,SX_COUNT_PROP),
    SX_FIELD("num_meshes","int32",60,4,SX_COUNT_PROP),
    SX_FIELD("num_names","int32",64,4,SX_COUNT_PROP),
    SX_FIELD("smallest_visible_size","int32",68,4,SX_NONE),
    SX_FIELD("smallest_visible_detail","int32",72,4,SX_NONE),
};
static const sx_layout sxbrs_dts_counts = {UINT32_C(0x603e000b),"dts_counts",sxbrs_dts_counts_fields,SX_COUNT(sxbrs_dts_counts_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_bounds_fields[] = {
    SX_FIELD("radius","float32",0,4,SX_NONE),
    SX_FIELD("tube_radius","float32",4,4,SX_NONE),
    SX_FIELD("center_x","float32",8,4,SX_NONE),
    SX_FIELD("center_y","float32",12,4,SX_NONE),
    SX_FIELD("center_z","float32",16,4,SX_NONE),
    SX_FIELD("min_x","float32",20,4,SX_NONE),
    SX_FIELD("min_y","float32",24,4,SX_NONE),
    SX_FIELD("min_z","float32",28,4,SX_NONE),
    SX_FIELD("max_x","float32",32,4,SX_NONE),
    SX_FIELD("max_y","float32",36,4,SX_NONE),
    SX_FIELD("max_z","float32",40,4,SX_NONE),
};
static const sx_layout sxbrs_dts_bounds = {UINT32_C(0x603e000c),"dts_bounds",sxbrs_dts_bounds_fields,SX_COUNT(sxbrs_dts_bounds_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_node_fields[] = {
    SX_FIELD("name_index","int32",0,4,SX_NONE),
    SX_FIELD("parent_index","int32",4,4,SX_NONE),
    SX_FIELD("first_object_index","int32",8,4,SX_NONE),
    SX_FIELD("first_child_index","int32",12,4,SX_NONE),
    SX_FIELD("next_sibling_index","int32",16,4,SX_NONE),
};
static const sx_layout sxbrs_dts_node = {UINT32_C(0x603e000d),"dts_node",sxbrs_dts_node_fields,SX_COUNT(sxbrs_dts_node_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_subshape_first_fields[] = {
    SX_FIELD("first_node","int32",0,4,SX_NONE),
    SX_FIELD("first_object","int32",4,4,SX_NONE),
    SX_FIELD("first_decal","int32",8,4,SX_NONE),
};
static const sx_layout sxbrs_dts_subshape_first = {UINT32_C(0x603e000e),"dts_subshape_first",sxbrs_dts_subshape_first_fields,SX_COUNT(sxbrs_dts_subshape_first_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_subshape_count_fields[] = {
    SX_FIELD("num_nodes","int32",0,4,SX_COUNT_PROP),
    SX_FIELD("num_objects","int32",4,4,SX_COUNT_PROP),
    SX_FIELD("num_decals","int32",8,4,SX_COUNT_PROP),
};
static const sx_layout sxbrs_dts_subshape_count = {UINT32_C(0x603e000f),"dts_subshape_count",sxbrs_dts_subshape_count_fields,SX_COUNT(sxbrs_dts_subshape_count_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_rotation_fields[] = {
    SX_FIELD("x","int16",0,2,SX_NONE),
    SX_FIELD("y","int16",2,2,SX_NONE),
    SX_FIELD("z","int16",4,2,SX_NONE),
    SX_FIELD("w","int16",6,2,SX_NONE),
};
static const sx_layout sxbrs_dts_rotation = {UINT32_C(0x603e0010),"dts_rotation",sxbrs_dts_rotation_fields,SX_COUNT(sxbrs_dts_rotation_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_translation_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
    SX_FIELD("z","float32",8,4,SX_NONE),
};
static const sx_layout sxbrs_dts_translation = {UINT32_C(0x603e0011),"dts_translation",sxbrs_dts_translation_fields,SX_COUNT(sxbrs_dts_translation_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_guard32_fields[] = {
    SX_FIELD("guard","uint32",0,4,SX_NONE),
};
static const sx_layout sxbrs_dts_guard32 = {UINT32_C(0x603e0012),"dts_guard32",sxbrs_dts_guard32_fields,SX_COUNT(sxbrs_dts_guard32_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_guard16_fields[] = {
    SX_FIELD("guard","uint16",0,2,SX_NONE),
};
static const sx_layout sxbrs_dts_guard16 = {UINT32_C(0x603e0013),"dts_guard16",sxbrs_dts_guard16_fields,SX_COUNT(sxbrs_dts_guard16_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_guard8_fields[] = {
    SX_FIELD("guard","uint8",0,1,SX_NONE),
};
static const sx_layout sxbrs_dts_guard8 = {UINT32_C(0x603e0014),"dts_guard8",sxbrs_dts_guard8_fields,SX_COUNT(sxbrs_dts_guard8_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_name_byte_fields[] = {
    SX_FIELD("character","char[1]",0,1,SX_STRING),
};
static const sx_layout sxbrs_dts_name_byte = {UINT32_C(0x603e0015),"dts_name_byte",sxbrs_dts_name_byte_fields,SX_COUNT(sxbrs_dts_name_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_dts_footer_fields[] = {
    SX_FIELD("sequence_count","int32",0,4,SX_COUNT_PROP),
    SX_FIELD("material_list_version","uint8",4,1,SX_NONE),
    SX_FIELD("material_count","uint32",5,4,SX_COUNT_PROP),
};
static const sx_layout sxbrs_dts_footer = {UINT32_C(0x603e0016),"dts_footer",sxbrs_dts_footer_fields,SX_COUNT(sxbrs_dts_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_vxworks_symbol_le_fields[] = {
    SX_FIELD("name_pointer","uint32",0,4,SX_POINTER),
    SX_FIELD("value","uint32",4,4,SX_ADDRESS),
    SX_FIELD("type","uint32",8,4,SX_FLAGS),
    SX_FIELD("group","uint32",12,4,SX_NONE),
};
static const sx_layout sxbrs_vxworks_symbol_le = {UINT32_C(0x603e0017),"vxworks_symbol_le",sxbrs_vxworks_symbol_le_fields,SX_COUNT(sxbrs_vxworks_symbol_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_vxworks_symbol_be_fields[] = {
    SX_FIELD("name_pointer","uint32",0,4,SX_POINTER),
    SX_FIELD("value","uint32",4,4,SX_ADDRESS),
    SX_FIELD("type","uint32",8,4,SX_FLAGS),
    SX_FIELD("group","uint32",12,4,SX_NONE),
};
static const sx_layout sxbrs_vxworks_symbol_be = {UINT32_C(0x603e0018),"vxworks_symbol_be",sxbrs_vxworks_symbol_be_fields,SX_COUNT(sxbrs_vxworks_symbol_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbrs_mwave_header_fields[] = {
    SX_FIELD("magic","uint8[2]",0,2,SX_SIGNATURE),
    SX_FIELD("dos_time","uint16",2,2,SX_TIME),
    SX_FIELD("dos_date","uint16",4,2,SX_TIME),
    SX_FIELD("constant","uint16",6,2,SX_SIGNATURE),
    SX_FIELD("filename","char[12]",8,12,SX_STRING),
    SX_FIELD("reserved","uint8[3]",20,3,SX_RESERVED),
    SX_FIELD("compress_flags","uint8",23,1,SX_FLAGS),
};
static const sx_layout sxbrs_mwave_header = {UINT32_C(0x603e0019),"mwave_header",sxbrs_mwave_header_fields,SX_COUNT(sxbrs_mwave_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_pcxlib_header_fields[] = {
    SX_FIELD("magic","char[7]",0,7,SX_SIGNATURE),
    SX_FIELD("opaque_7","uint8[115]",7,115,SX_NONE),
};
static const sx_layout sxbrs_pcxlib_header = {UINT32_C(0x603e001a),"pcxlib_header",sxbrs_pcxlib_header_fields,SX_COUNT(sxbrs_pcxlib_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_pcxlib_member_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("filename","char[13]",1,13,SX_STRING),
    SX_FIELD("stored_size","uint32",14,4,SX_SIZE),
    SX_FIELD("opaque_12","uint8[4]",18,4,SX_NONE),
    SX_FIELD("method","uint16",22,2,SX_ID),
    SX_FIELD("opaque_18","uint8[60]",24,60,SX_NONE),
};
static const sx_layout sxbrs_pcxlib_member = {UINT32_C(0x603e001b),"pcxlib_member",sxbrs_pcxlib_member_fields,SX_COUNT(sxbrs_pcxlib_member_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_qnx_startup_prefix_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_NONE),
    SX_FIELD("flags1","uint8",6,1,SX_FLAGS),
    SX_FIELD("flags2","uint8",7,1,SX_FLAGS),
    SX_FIELD("header_size","uint16",8,2,SX_SIZE),
    SX_FIELD("machine","uint16",10,2,SX_ID),
    SX_FIELD("startup_vaddr","uint32",12,4,SX_ADDRESS),
    SX_FIELD("paddr_bias","uint32",16,4,SX_NONE),
    SX_FIELD("image_paddr","uint32",20,4,SX_ADDRESS),
    SX_FIELD("ram_paddr","uint32",24,4,SX_ADDRESS),
    SX_FIELD("ram_size","uint32",28,4,SX_SIZE),
    SX_FIELD("startup_size","uint32",32,4,SX_SIZE),
    SX_FIELD("stored_size","uint32",36,4,SX_SIZE),
    SX_FIELD("imagefs_paddr","uint32",40,4,SX_ADDRESS),
    SX_FIELD("imagefs_size","uint32",44,4,SX_SIZE),
    SX_FIELD("preboot_size","uint16",48,2,SX_OFFSET),
    SX_FIELD("zero0","uint16",50,2,SX_RESERVED),
};
static const sx_layout sxbrs_qnx_startup_prefix = {UINT32_C(0x603e001c),"qnx_startup_prefix",sxbrs_qnx_startup_prefix_fields,SX_COUNT(sxbrs_qnx_startup_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_qnx_startup_header_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_NONE),
    SX_FIELD("flags1","uint8",6,1,SX_FLAGS),
    SX_FIELD("flags2","uint8",7,1,SX_FLAGS),
    SX_FIELD("header_size","uint16",8,2,SX_SIZE),
    SX_FIELD("machine","uint16",10,2,SX_ID),
    SX_FIELD("startup_vaddr","uint32",12,4,SX_ADDRESS),
    SX_FIELD("paddr_bias","uint32",16,4,SX_NONE),
    SX_FIELD("image_paddr","uint32",20,4,SX_ADDRESS),
    SX_FIELD("ram_paddr","uint32",24,4,SX_ADDRESS),
    SX_FIELD("ram_size","uint32",28,4,SX_SIZE),
    SX_FIELD("startup_size","uint32",32,4,SX_SIZE),
    SX_FIELD("stored_size","uint32",36,4,SX_SIZE),
    SX_FIELD("imagefs_paddr","uint32",40,4,SX_ADDRESS),
    SX_FIELD("imagefs_size","uint32",44,4,SX_SIZE),
    SX_FIELD("preboot_size","uint16",48,2,SX_OFFSET),
    SX_FIELD("zero0","uint16",50,2,SX_RESERVED),
    SX_FIELD("zero","uint32[3]",52,12,SX_RESERVED),
    SX_FIELD("info","uint32[48]",64,192,SX_NONE),
};
static const sx_layout sxbrs_qnx_startup_header = {UINT32_C(0x603e001d),"qnx_startup_header",sxbrs_qnx_startup_header_fields,SX_COUNT(sxbrs_qnx_startup_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_qnx_block_fields[] = {
    SX_FIELD("packed_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxbrs_qnx_block = {UINT32_C(0x603e001e),"qnx_block",sxbrs_qnx_block_fields,SX_COUNT(sxbrs_qnx_block_fields),SX_BE};
static const xx_data_struct_field_desc sxbrs_uboot_env_le_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxbrs_uboot_env_le = {UINT32_C(0x603e001f),"uboot_env_le",sxbrs_uboot_env_le_fields,SX_COUNT(sxbrs_uboot_env_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_uboot_redundant_env_le_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
};
static const sx_layout sxbrs_uboot_redundant_env_le = {UINT32_C(0x603e0020),"uboot_redundant_env_le",sxbrs_uboot_redundant_env_le_fields,SX_COUNT(sxbrs_uboot_redundant_env_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_uboot_env_be_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxbrs_uboot_env_be = {UINT32_C(0x603e0021),"uboot_env_be",sxbrs_uboot_env_be_fields,SX_COUNT(sxbrs_uboot_env_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbrs_uboot_redundant_env_be_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
};
static const sx_layout sxbrs_uboot_redundant_env_be = {UINT32_C(0x603e0022),"uboot_redundant_env_be",sxbrs_uboot_redundant_env_be_fields,SX_COUNT(sxbrs_uboot_redundant_env_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbrs_uboot_key_byte_fields[] = {
    SX_FIELD("character","char[1]",0,1,SX_STRING),
};
static const sx_layout sxbrs_uboot_key_byte = {UINT32_C(0x603e0023),"uboot_key_byte",sxbrs_uboot_key_byte_fields,SX_COUNT(sxbrs_uboot_key_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_uboot_value_byte_fields[] = {
    SX_FIELD("character","char[1]",0,1,SX_STRING),
};
static const sx_layout sxbrs_uboot_value_byte = {UINT32_C(0x603e0024),"uboot_value_byte",sxbrs_uboot_value_byte_fields,SX_COUNT(sxbrs_uboot_value_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_uboot_separator_fields[] = {
    SX_FIELD("separator","uint8",0,1,SX_NONE),
};
static const sx_layout sxbrs_uboot_separator = {UINT32_C(0x603e0025),"uboot_separator",sxbrs_uboot_separator_fields,SX_COUNT(sxbrs_uboot_separator_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_uboot_terminator_fields[] = {
    SX_FIELD("terminator","uint8",0,1,SX_NONE),
};
static const sx_layout sxbrs_uboot_terminator = {UINT32_C(0x603e0026),"uboot_terminator",sxbrs_uboot_terminator_fields,SX_COUNT(sxbrs_uboot_terminator_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_fss_header_fields[] = {
    SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
    SX_FIELD("marker_05","uint8",5,1,SX_NONE),
    SX_FIELD("opaque_6","uint8[1]",6,1,SX_NONE),
    SX_FIELD("marker_07","uint8",7,1,SX_NONE),
    SX_FIELD("descriptor_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("record_count","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("opaque_c","uint8[2]",12,2,SX_NONE),
    SX_FIELD("marker_0e","uint16",14,2,SX_SIGNATURE),
};
static const sx_layout sxbrs_fss_header = {UINT32_C(0x603e0027),"fss_header",sxbrs_fss_header_fields,SX_COUNT(sxbrs_fss_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_fss_record_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("kind","uint8",8,1,SX_ID),
    SX_FIELD("name","char[64]",9,64,SX_STRING),
    SX_FIELD("opaque_49","uint8[1]",73,1,SX_NONE),
};
static const sx_layout sxbrs_fss_record = {UINT32_C(0x603e0028),"fss_record",sxbrs_fss_record_fields,SX_COUNT(sxbrs_fss_record_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_fss_end_fields[] = {
    SX_FIELD("file_size","uint32",0,4,SX_SIZE),
    SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
};
static const sx_layout sxbrs_fss_end = {UINT32_C(0x603e0029),"fss_end",sxbrs_fss_end_fields,SX_COUNT(sxbrs_fss_end_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_px_header_fields[] = {
    SX_FIELD("signature","char[30]",0,30,SX_SIGNATURE),
    SX_FIELD("opaque_1e","uint8[4]",30,4,SX_NONE),
    SX_FIELD("version","uint16",34,2,SX_NONE),
    SX_FIELD("opaque_24","uint8[22]",36,22,SX_NONE),
    SX_FIELD("descriptor_count","uint32",58,4,SX_COUNT_PROP),
};
static const sx_layout sxbrs_px_header = {UINT32_C(0x603e002a),"px_header",sxbrs_px_header_fields,SX_COUNT(sxbrs_px_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_px_block_fields[] = {
    SX_FIELD("reserved","uint16",0,2,SX_RESERVED),
    SX_FIELD("kind","uint16",2,2,SX_ID),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
    SX_FIELD("opaque_8","uint8[4]",8,4,SX_NONE),
};
static const sx_layout sxbrs_px_block = {UINT32_C(0x603e002b),"px_block",sxbrs_px_block_fields,SX_COUNT(sxbrs_px_block_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_px_count_fields[] = {
    SX_FIELD("record_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxbrs_px_count = {UINT32_C(0x603e002c),"px_count",sxbrs_px_count_fields,SX_COUNT(sxbrs_px_count_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_px_record_fields[] = {
    SX_FIELD("category","char[32]",0,32,SX_STRING),
    SX_FIELD("payload_size","uint32",32,4,SX_SIZE),
    SX_FIELD("marker","uint8",36,1,SX_NONE),
};
static const sx_layout sxbrs_px_record = {UINT32_C(0x603e002d),"px_record",sxbrs_px_record_fields,SX_COUNT(sxbrs_px_record_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_evd_header_fields[] = {
    SX_FIELD("reserved0","uint32",0,4,SX_RESERVED),
    SX_FIELD("reserved1","uint32",4,4,SX_RESERVED),
    SX_FIELD("marker","uint32",8,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",12,4,SX_NONE),
    SX_FIELD("field_10","uint32",16,4,SX_NONE),
    SX_FIELD("field_14","uint32",20,4,SX_NONE),
};
static const sx_layout sxbrs_evd_header = {UINT32_C(0x603e002e),"evd_header",sxbrs_evd_header_fields,SX_COUNT(sxbrs_evd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_evd_record_fields[] = {
    SX_FIELD("image_type","uint16",0,2,SX_ID),
    SX_FIELD("repeated_image_type","uint16",2,2,SX_ID),
    SX_FIELD("image_id","uint32",4,4,SX_ID),
    SX_FIELD("payload_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxbrs_evd_record = {UINT32_C(0x603e002f),"evd_record",sxbrs_evd_record_fields,SX_COUNT(sxbrs_evd_record_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_sony_image_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("opaque_4","uint8[12]",4,12,SX_NONE),
    SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
    SX_FIELD("payload_size","uint32",20,4,SX_SIZE),
    SX_FIELD("continuation","uint8",24,1,SX_NONE),
    SX_FIELD("field_19","uint8",25,1,SX_NONE),
    SX_FIELD("opaque_1a","uint8[486]",26,486,SX_NONE),
};
static const sx_layout sxbrs_sony_image_header = {UINT32_C(0x603e0030),"sony_image_header",sxbrs_sony_image_header_fields,SX_COUNT(sxbrs_sony_image_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_sony_image_zlib_marker_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxbrs_sony_image_zlib_marker = {UINT32_C(0x603e0031),"sony_image_zlib_marker",sxbrs_sony_image_zlib_marker_fields,SX_COUNT(sxbrs_sony_image_zlib_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_resource_zlib_header_fields[] = {
    SX_FIELD("compression_method_flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("flags","uint8",1,1,SX_FLAGS),
};
static const sx_layout sxbrs_resource_zlib_header = {UINT32_C(0x603e0032),"resource_zlib_header",sxbrs_resource_zlib_header_fields,SX_COUNT(sxbrs_resource_zlib_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_resource_zlib_trailer_fields[] = {
    SX_FIELD("adler32","uint32",0,4,SX_CHECKSUM),
};
static const sx_layout sxbrs_resource_zlib_trailer = {UINT32_C(0x603e0033),"resource_zlib_trailer",sxbrs_resource_zlib_trailer_fields,SX_COUNT(sxbrs_resource_zlib_trailer_fields),SX_BE};
static const sx_layout *const sx_binaryresources_layouts[] = {
    &sxbrs_ota_bitmap_short,
    &sxbrs_ota_bitmap_extended,
    &sxbrs_lp_geometry,
    &sxbrs_lp_header,
    &sxbrs_lp_header_extended,
    &sxbrs_lp_partition,
    &sxbrs_lp_extent,
    &sxbrs_lp_group,
    &sxbrs_lp_block_device,
    &sxbrs_dts_header,
    &sxbrs_dts_counts,
    &sxbrs_dts_bounds,
    &sxbrs_dts_node,
    &sxbrs_dts_subshape_first,
    &sxbrs_dts_subshape_count,
    &sxbrs_dts_rotation,
    &sxbrs_dts_translation,
    &sxbrs_dts_guard32,
    &sxbrs_dts_guard16,
    &sxbrs_dts_guard8,
    &sxbrs_dts_name_byte,
    &sxbrs_dts_footer,
    &sxbrs_vxworks_symbol_le,
    &sxbrs_vxworks_symbol_be,
    &sxbrs_mwave_header,
    &sxbrs_pcxlib_header,
    &sxbrs_pcxlib_member,
    &sxbrs_qnx_startup_prefix,
    &sxbrs_qnx_startup_header,
    &sxbrs_qnx_block,
    &sxbrs_uboot_env_le,
    &sxbrs_uboot_redundant_env_le,
    &sxbrs_uboot_env_be,
    &sxbrs_uboot_redundant_env_be,
    &sxbrs_uboot_key_byte,
    &sxbrs_uboot_value_byte,
    &sxbrs_uboot_separator,
    &sxbrs_uboot_terminator,
    &sxbrs_fss_header,
    &sxbrs_fss_record,
    &sxbrs_fss_end,
    &sxbrs_px_header,
    &sxbrs_px_block,
    &sxbrs_px_count,
    &sxbrs_px_record,
    &sxbrs_evd_header,
    &sxbrs_evd_record,
    &sxbrs_sony_image_header,
    &sxbrs_sony_image_zlib_marker,
    &sxbrs_resource_zlib_header,
    &sxbrs_resource_zlib_trailer,
};
static bool sx_binaryresources_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x603e0000U||id>=0x603f0000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x603e0001U:
        if(!xx_rt_wcscmp(r->name,L"infofield"))text=L"Bit4 selects16-bit dimensions; extension fields are unsupported by the native reader.";
        if(!xx_rt_wcscmp(r->name,L"depth"))text=L"Native monochrome images store1 bit per pixel.";
        break;
    case 0x603e0002U:
        if(!xx_rt_wcscmp(r->name,L"infofield"))text=L"Bit4 selects16-bit big-endian dimensions.";
        if(!xx_rt_wcscmp(r->name,L"depth"))text=L"Native monochrome images store1 bit per pixel.";
        break;
    case 0x603e0003U:
        if(!xx_rt_wcscmp(r->name,L"magic"))text=L"LP_METADATA_GEOMETRY_MAGIC";
        if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"SHA-256 of the geometry with this field zeroed.";
        if(!xx_rt_wcscmp(r->name,L"logical_block_size"))text=L"Alignment in bytes; multiple of512.";
        break;
    case 0x603e0004U:
        if(!xx_rt_wcscmp(r->name,L"magic"))text=L"LP_METADATA_HEADER_MAGIC";
        if(!xx_rt_wcscmp(r->name,L"header_checksum"))text=L"SHA-256 of header_size bytes with this checksum zeroed.";
        if(!xx_rt_wcscmp(r->name,L"tables_checksum"))text=L"SHA-256 of all table bytes.";
        if(!xx_rt_wcscmp(r->name,L"partitions_offset"))text=L"Byte offset from the end of the metadata header.";
        if(!xx_rt_wcscmp(r->name,L"extents_offset"))text=L"Byte offset from the end of the metadata header.";
        if(!xx_rt_wcscmp(r->name,L"groups_offset"))text=L"Byte offset from the end of the metadata header.";
        if(!xx_rt_wcscmp(r->name,L"block_devices_offset"))text=L"Byte offset from the end of the metadata header.";
        break;
    case 0x603e0005U:
        if(!xx_rt_wcscmp(r->name,L"magic"))text=L"LP_METADATA_HEADER_MAGIC";
        if(!xx_rt_wcscmp(r->name,L"header_checksum"))text=L"SHA-256 of header_size bytes with this checksum zeroed.";
        if(!xx_rt_wcscmp(r->name,L"tables_checksum"))text=L"SHA-256 of all table bytes.";
        if(!xx_rt_wcscmp(r->name,L"partitions_offset"))text=L"Byte offset from the end of the metadata header.";
        if(!xx_rt_wcscmp(r->name,L"extents_offset"))text=L"Byte offset from the end of the metadata header.";
        if(!xx_rt_wcscmp(r->name,L"groups_offset"))text=L"Byte offset from the end of the metadata header.";
        if(!xx_rt_wcscmp(r->name,L"block_devices_offset"))text=L"Byte offset from the end of the metadata header.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"LP_HEADER_FLAG_VIRTUAL_AB_DEVICE=1; LP_HEADER_FLAG_OVERLAYS_ACTIVE=2.";
        break;
    case 0x603e0006U:
        if(!xx_rt_wcscmp(r->name,L"attributes"))text=L"LP_PARTITION_ATTR_READONLY=1; SLOT_SUFFIXED=2; UPDATED=4; DISABLED=8.";
        if(!xx_rt_wcscmp(r->name,L"first_extent_index"))text=L"Index in the extent table; not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"group_index"))text=L"Index in the partition-group table.";
        break;
    case 0x603e0007U:
        if(!xx_rt_wcscmp(r->name,L"num_sectors"))text=L"Length in512-byte sectors.";
        if(!xx_rt_wcscmp(r->name,L"target_type"))text=L"LP_TARGET_TYPE_LINEAR=0; LP_TARGET_TYPE_ZERO=1.";
        if(!xx_rt_wcscmp(r->name,L"target_data"))text=L"LINEAR: physical sector number in512-byte units; ZERO: reserved zero.";
        if(!xx_rt_wcscmp(r->name,L"target_source"))text=L"LINEAR: block-device table index; ZERO: reserved zero.";
        break;
    case 0x603e0008U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"LP_GROUP_SLOT_SUFFIXED=1.";
        if(!xx_rt_wcscmp(r->name,L"maximum_size"))text=L"Byte limit; zero means unlimited.";
        break;
    case 0x603e0009U:
        if(!xx_rt_wcscmp(r->name,L"first_logical_sector"))text=L"First usable512-byte sector number.";
        if(!xx_rt_wcscmp(r->name,L"alignment"))text=L"Partition alignment in bytes.";
        if(!xx_rt_wcscmp(r->name,L"alignment_offset"))text=L"Byte alignment adjustment within the parent block device.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"LP_BLOCK_DEVICE_SLOT_SUFFIXED=1.";
        break;
    case 0x603e000aU:
        if(!xx_rt_wcscmp(r->name,L"version"))text=L"Low16 bits are DTS version; high16 bits are exporter version.";
        if(!xx_rt_wcscmp(r->name,L"buffer_size_words"))text=L"Total buffer length in32-bit words.";
        if(!xx_rt_wcscmp(r->name,L"start16_words"))text=L"Start of16-bit buffer, measured in32-bit words from the end of this header.";
        if(!xx_rt_wcscmp(r->name,L"start8_words"))text=L"Start of8-bit buffer, measured in32-bit words from the end of this header.";
        break;
    case 0x603e000dU:
        if(!xx_rt_wcscmp(r->name,L"parent_index"))text=L"-1 means no parent.";
        if(!xx_rt_wcscmp(r->name,L"first_object_index"))text=L"-1 means no object.";
        if(!xx_rt_wcscmp(r->name,L"first_child_index"))text=L"-1 means no child.";
        if(!xx_rt_wcscmp(r->name,L"next_sibling_index"))text=L"-1 means no sibling.";
        break;
    case 0x603e0010U:
        if(!xx_rt_wcscmp(r->name,L"x"))text=L"Quantized quaternion component; original signed16-bit encoding.";
        break;
    case 0x603e0017U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Runtime symbol value; not a physical file offset.";
        if(!xx_rt_wcscmp(r->name,L"type"))text=L"Native recognized symbol classes:0x500 function,0x700 initialized data,0x900 uninitialized data.";
        break;
    case 0x603e0018U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Runtime symbol value; not a physical file offset.";
        if(!xx_rt_wcscmp(r->name,L"type"))text=L"Native recognized symbol classes:0x500 function,0x700 initialized data,0x900 uninitialized data.";
        break;
    case 0x603e0019U:
        if(!xx_rt_wcscmp(r->name,L"magic"))text=L"Unix compress signature1F9D.";
        if(!xx_rt_wcscmp(r->name,L"dos_time"))text=L"Packed DOS time: bits0..4 seconds/2, bits5..10 minutes, bits11..15 hours.";
        if(!xx_rt_wcscmp(r->name,L"dos_date"))text=L"Packed DOS date: bits0..4 day, bits5..8 month, bits9..15 years since1980.";
        if(!xx_rt_wcscmp(r->name,L"constant"))text=L"MWave wrapper constant0x0020.";
        if(!xx_rt_wcscmp(r->name,L"compress_flags"))text=L"Low5 bits:max LZW code width; bit7:block mode; bits5..6 reserved.";
        break;
    case 0x603e001bU:
        if(!xx_rt_wcscmp(r->name,L"method"))text=L"Native defined method0:stored.";
        break;
    case 0x603e001cU:
        if(!xx_rt_wcscmp(r->name,L"signature"))text=L"QNX startup signature0x00FF7EEB.";
        if(!xx_rt_wcscmp(r->name,L"flags1"))text=L"Includes byte order and compression method encoding.";
        if(!xx_rt_wcscmp(r->name,L"machine"))text=L"ELF machine identifier.";
        if(!xx_rt_wcscmp(r->name,L"paddr_bias"))text=L"Bias added to physical addresses to form accessible pointers.";
        if(!xx_rt_wcscmp(r->name,L"imagefs_size"))text=L"Decoded image-filesystem size.";
        if(!xx_rt_wcscmp(r->name,L"preboot_size"))text=L"Bytes from image start to this startup header.";
        break;
    case 0x603e001dU:
        if(!xx_rt_wcscmp(r->name,L"signature"))text=L"QNX startup signature0x00FF7EEB.";
        if(!xx_rt_wcscmp(r->name,L"flags1"))text=L"Includes byte order and compression method encoding.";
        if(!xx_rt_wcscmp(r->name,L"machine"))text=L"ELF machine identifier.";
        if(!xx_rt_wcscmp(r->name,L"paddr_bias"))text=L"Bias added to physical addresses to form accessible pointers.";
        if(!xx_rt_wcscmp(r->name,L"imagefs_size"))text=L"Decoded image-filesystem size.";
        if(!xx_rt_wcscmp(r->name,L"preboot_size"))text=L"Bytes from image start to this startup header.";
        if(!xx_rt_wcscmp(r->name,L"info"))text=L"Startup-info records; their individual grammar remains undecoded.";
        break;
    case 0x603e001eU:
        if(!xx_rt_wcscmp(r->name,L"packed_size"))text=L"Length of the following NRV2B block; zero terminates the chain.";
        break;
    case 0x603e001fU:
        if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC32 of the complete data area, including padding.";
        break;
    case 0x603e0020U:
        if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC32 of the complete data area after flags, including padding.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Redundant-environment active/obsolete flag or serial counter, depending on storage backend.";
        break;
    case 0x603e0021U:
        if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC32 of the complete data area, including padding.";
        break;
    case 0x603e0022U:
        if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC32 of the complete data area after flags, including padding.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Redundant-environment active/obsolete flag or serial counter, depending on storage backend.";
        break;
    case 0x603e0025U:
        if(!xx_rt_wcscmp(r->name,L"separator"))text=L"ASCII equals sign separates key and value.";
        break;
    case 0x603e0026U:
        if(!xx_rt_wcscmp(r->name,L"terminator"))text=L"NUL terminates the variable; a second NUL ends the list.";
        break;
    case 0x603e0027U:
        if(!xx_rt_wcscmp(r->name,L"marker_05"))text=L"Native signature requires1.";
        if(!xx_rt_wcscmp(r->name,L"marker_07"))text=L"Native signature requires1.";
        if(!xx_rt_wcscmp(r->name,L"descriptor_count"))text=L"Includes one implicit descriptor before the stored12-byte descriptor records.";
        if(!xx_rt_wcscmp(r->name,L"marker_0e"))text=L"Native signature requires0xFFFF.";
        break;
    case 0x603e0028U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Data extent is associated with the preceding record name.";
        if(!xx_rt_wcscmp(r->name,L"kind"))text=L"0x10 marks a named resource descriptor.";
        break;
    case 0x603e002bU:
        if(!xx_rt_wcscmp(r->name,L"kind"))text=L"Native named-resource block type1.";
        break;
    case 0x603e002dU:
        if(!xx_rt_wcscmp(r->name,L"marker"))text=L"Native resource record marker1.";
        break;
    case 0x603e002eU:
        if(!xx_rt_wcscmp(r->name,L"marker"))text=L"Native header marker12.";
        if(!xx_rt_wcscmp(r->name,L"field_10"))text=L"Meaning unconfirmed; native reader requires nonzero.";
        if(!xx_rt_wcscmp(r->name,L"field_14"))text=L"Meaning unconfirmed; native reader requires nonzero.";
        break;
    case 0x603e002fU:
        if(!xx_rt_wcscmp(r->name,L"image_type"))text=L"JPEG=1;PNG=2.";
        break;
    case 0x603e0030U:
        if(!xx_rt_wcscmp(r->name,L"magic"))text=L"TCJN";
        if(!xx_rt_wcscmp(r->name,L"payload_size"))text=L"Bytes following this512-byte header.";
        if(!xx_rt_wcscmp(r->name,L"continuation"))text=L"Zero selects the initial volume; continuations need the initial volume.";
        if(!xx_rt_wcscmp(r->name,L"field_19"))text=L"Meaning unconfirmed; native reader accepts0 or1.";
        break;
    case 0x603e0031U:
        if(!xx_rt_wcscmp(r->name,L"magic"))text=L"ZLIB marker before the physical zlib stream.";
        break;
    case 0x603e0032U:
        if(!xx_rt_wcscmp(r->name,L"compression_method_flags"))text=L"CM bits0..3=8:DEFLATE; CINFO bits4..7=window log2 minus8.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"FCHECK bits0..4; FDICT bit5; compression level bits6..7.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}

#include "xxfclib/algo/crc/xx_crc.h"
/* Bounded physical metadata; byte coordinates are always those of the input. */
static uint64_t sxbrs_num(sx_context*c,int64_t at,unsigned width,bool be){uint8_t b[8];if(!width||width>8||!sx_read(c,at,b,width)){c->failed=true;return 0;}uint64_t v=0;for(unsigned i=0;i<width;i++)v|=(uint64_t)b[i]<<(8*(be?width-1-i:i));return v;}
static uint64_t sxbrs_width(const sx_layout*l){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];return(uint64_t)(f->rel_offset+f->size);}
static bool sxbrs_take(sx_context*c,const sx_layout*l,int64_t*at,int64_t end,uint64_t count){uint64_t width=sxbrs_width(l);if(*at<0||end<*at||!width||count>(uint64_t)(end-*at)/width)return false;if(count&&c->count<32000&&!sx_table(c,l,*at,(int64_t)width,count>65536?65536:count))return false;*at+=(int64_t)(count*width);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sxbrs_add(sx_context*c,const sx_layout*l,int64_t at){return sxbrs_take(c,l,&at,c->size,1);}
static bool sxbrs_skip(int64_t*at,int64_t end,uint64_t n){if(*at<0||end<*at||n>(uint64_t)(end-*at))return false;*at+=(int64_t)n;return true;}
#define AL(n,k) do{if(!sxbrs_take(c,&sxbrs_##n,&at,end,(k)))return false;}while(0)
#define SK(n) do{if(!sxbrs_skip(&at,end,(n)))return false;}while(0)
#define N(p,w) sxbrs_num(c,(p),(w),false)
#define B(p,w) sxbrs_num(c,(p),(w),true)
static bool sxbrs_lp(sx_context*c)
{
 if(c->size<12416||N(4096,4)!=0x616c4467U||N(4100,4)!=52||N(12288,4)!=0x414c5030U)return false;
 if(!sxbrs_add(c,&sxbrs_lp_geometry,4096))return false;
 /* The second physical geometry copy is independent; native uses the first. */
 if(N(8192,4)==0x616c4467U&&N(8196,4)==52&&!sxbrs_add(c,&sxbrs_lp_geometry,8192))return false;
 uint64_t header=N(12296,4),bytes=N(12332,4);if(header!=128&&header!=256)return false;
 if(!sxbrs_add(c,header==128?&sxbrs_lp_header:&sxbrs_lp_header_extended,12288))return false;
 int64_t data=12288+(int64_t)header;if(bytes>(uint64_t)(c->size-data))return false;
 const sx_layout*layouts[]={&sxbrs_lp_partition,&sxbrs_lp_extent,&sxbrs_lp_group,&sxbrs_lp_block_device};
 for(unsigned i=0;i<4;i++){
  uint64_t o=N(12368+12*i,4),count=N(12372+12*i,4),stride=N(12376+12*i,4),known=sxbrs_width(layouts[i]);
  if(o>bytes||stride<known||count>(bytes-o)/stride)return false;
  if(stride==known){int64_t at=data+(int64_t)o;if(!sxbrs_take(c,layouts[i],&at,data+(int64_t)bytes,count))return false;}
  else for(uint64_t j=0;j<count&&j<65536&&c->count<32000;j++)if(!sxbrs_add(c,layouts[i],data+(int64_t)(o+j*stride)))return false;
 }
 return !c->failed;
}
static bool sxbrs_dts_guard(sx_context*c,int64_t*a,int64_t ae,int64_t*b,int64_t be,int64_t*d,int64_t de,unsigned guard)
{
 if(N(*a,4)!=guard||N(*b,2)!=guard||N(*d,1)!=guard)return false;
 return sxbrs_take(c,&sxbrs_dts_guard32,a,ae,1)&&sxbrs_take(c,&sxbrs_dts_guard16,b,be,1)&&sxbrs_take(c,&sxbrs_dts_guard8,d,de,1);
}
static bool sxbrs_dts(sx_context*c)
{
 if(c->size<25||(N(0,4)&65535)!=24)return false;uint64_t size=N(4,4),s16=N(8,4),s8=N(12,4);
 if(s16<19||s16>s8||s8>size||size>(uint64_t)(c->size-25)/4)return false;
 int64_t at=16,end=16+(int64_t)s16*4,b=end,be=16+(int64_t)s8*4,d=be,de=16+(int64_t)size*4;
 uint64_t nodes=N(16,4),names=N(80,4);if(!nodes||nodes>256||!names||names>1024)return false;
 if(!sxbrs_add(c,&sxbrs_dts_header,0))return false;AL(dts_counts,1);
 unsigned guard=0;
 if(!sxbrs_dts_guard(c,&at,end,&b,be,&d,de,guard++))return false;AL(dts_bounds,1);
 if(!sxbrs_dts_guard(c,&at,end,&b,be,&d,de,guard++))return false;AL(dts_node,nodes);
 for(unsigned i=2;i<=5;i++)if(!sxbrs_dts_guard(c,&at,end,&b,be,&d,de,guard++))return false;
 AL(dts_subshape_first,1);if(!sxbrs_dts_guard(c,&at,end,&b,be,&d,de,guard++))return false;
 AL(dts_subshape_count,1);if(!sxbrs_dts_guard(c,&at,end,&b,be,&d,de,guard++))return false;
 if(!sxbrs_take(c,&sxbrs_dts_rotation,&b,be,nodes))return false;AL(dts_translation,nodes);
 for(unsigned i=8;i<=15;i++)if(!sxbrs_dts_guard(c,&at,end,&b,be,&d,de,guard++))return false;
 int64_t start=d;for(uint64_t i=0;i<names;i++){unsigned length=0;while(d<de&&N(d++,1)){if(++length>=4096)return false;}if(!length||d>de)return false;}
 int64_t cursor=start;if(!sxbrs_take(c,&sxbrs_dts_name_byte,&cursor,d,(uint64_t)(d-start)))return false;
 if(!sxbrs_dts_guard(c,&at,end,&b,be,&d,de,guard++)||at!=end)return false;
 return sxbrs_add(c,&sxbrs_dts_footer,de);
}
static bool sxbrs_eq(sx_context*c,int64_t at,const char*text,size_t n){uint8_t buf[64];return n<=sizeof(buf)&&sx_read(c,at,buf,n)&&!xx_rt_memcmp(buf,text,n);}
static bool sxbrs_ota(sx_context*c){uint64_t flags=N(0,1),n=(flags&16)?6:4;if(flags&~16U||c->size<(int64_t)n)return false;uint64_t w=N(1,1),h=N(2,1);if(flags&16){w=B(1,2);h=B(3,2);}if(!w||w>8192||!h||h>4095||N(n-1,1)!=1||(w+7)/8*h!=(uint64_t)c->size-n)return false;return sxbrs_add(c,flags&16?&sxbrs_ota_bitmap_extended:&sxbrs_ota_bitmap_short,0);}
static bool sxbrs_pcxlib(sx_context*c){int64_t at=0,end=c->size;if(end<206||!sxbrs_eq(c,0,"pcxLib\0",7))return false;AL(pcxlib_header,1);uint64_t count=0;while(at<end){if(++count>1000000||N(at,1)!=1||N(at+22,2)!=0)return false;uint64_t n=N(at+14,4);AL(pcxlib_member,1);SK(n);}return count>0;}
static bool sxbrs_fss(sx_context*c){int64_t at=0,end=c->size;uint64_t d=N(8,2),n=N(10,2);if(!sxbrs_eq(c,0,"SSBOB\1\0\1",8)||d<2||d>128||n<2||n>128||N(12,2)||N(14,2)!=65535)return false;AL(fss_header,1);SK((d-1)*12);AL(fss_record,n);if(N(at,4)!=(uint64_t)end||N(at+4,4))return false;AL(fss_end,1);return true;}
static bool sxbrs_px(sx_context*c){int64_t at=0,end=c->size;if(!sxbrs_eq(c,0,"Photodex Presenter Stream\x1a\n\r\n\x1a",30)||N(34,2)<1||N(34,2)>5)return false;uint64_t d=N(58,4),blocks=0;AL(px_header,1);SK(d*44);while(at<end){if(++blocks>100000||N(at,2)||N(at+2,2)!=1)return false;uint64_t z=N(at+4,4);AL(px_block,1);if(z<4||z>(uint64_t)(end-at))return false;int64_t blockend=at+(int64_t)z;uint64_t count=N(at,4);if(!count||count>100000)return false;AL(px_count,1);for(uint64_t j=0;j<count;j++){if(blockend-at<37||N(at+36,1)!=1)return false;z=N(at+32,4);AL(px_record,1);if(z>(uint64_t)(blockend-at))return false;SK(z);}if(at!=blockend)return false;}return blocks>0;}
static bool sxbrs_evd(sx_context*c){int64_t at=0,end=c->size;if(N(0,4)||N(4,4)||N(8,4)!=12||(N(12,4)!=1&&N(12,4)!=2)||!N(16,4)||!N(20,4))return false;AL(evd_header,1);unsigned count=0;while(at<end){uint64_t type=N(at,2),z=N(at+8,4);if(++count>100000||(type!=1&&type!=2)||N(at+2,2)!=type||!N(at+4,4)||z<8)return false;AL(evd_record,1);if(type==1?!sxbrs_eq(c,at,"\xff\xd8\xff",3):!sxbrs_eq(c,at,"\x89PNG\r\n\x1a\n",8))return false;SK(z);}return count>0;}
static bool sxbrs_mwave(sx_context*c){if(c->size<=24||!sxbrs_eq(c,0,"\x1f\x9d",2)||N(6,2)!=32||N(20,3))return false;uint64_t flags=N(23,1);if((flags&0x60)||(flags&31)<9||(flags&31)>16)return false;return sxbrs_add(c,&sxbrs_mwave_header,0);}
static bool sxbrs_vxworks(sx_context*c){bool be=N(9,1)==0;uint64_t count=0;while(count<(uint64_t)c->size/16&&count<4000000){int64_t at=(int64_t)(count*16);uint64_t type=sxbrs_num(c,at+8,4,be);if(!sxbrs_num(c,at,4,be)||!sxbrs_num(c,at+4,4,be)||(type!=0x500&&type!=0x700&&type!=0x900))break;count++;if(xx_pd_is_stopped(c->pd))return false;}if(count<250)return false;int64_t at=0;return sxbrs_take(c,be?&sxbrs_vxworks_symbol_be:&sxbrs_vxworks_symbol_le,&at,c->size,count);}
static bool sxbrs_uboot(sx_context*c){
 if(c->size<256||c->size>1048576)return false;uint8_t chunk[4096];uint32_t want=(uint32_t)N(0,4);unsigned prefix=0;bool be=false;
 for(unsigned h=4;h<=5&&!prefix;h++){uint32_t crc=0;for(int64_t at=h;at<c->size;){size_t n=(uint64_t)(c->size-at)>sizeof(chunk)?sizeof(chunk):(size_t)(c->size-at);if(!sx_read(c,at,chunk,n)||xx_pd_is_stopped(c->pd))return false;crc=xx_crc32_calc(crc,chunk,n);at+=(int64_t)n;}if(crc==want){prefix=h;be=false;}else if(crc==(uint32_t)B(0,4)){prefix=h;be=true;}}
 if(!prefix)return false;const sx_layout*header=prefix==4?(be?&sxbrs_uboot_env_be:&sxbrs_uboot_env_le):(be?&sxbrs_uboot_redundant_env_be:&sxbrs_uboot_redundant_env_le);if(!sxbrs_add(c,header,0))return false;
 int64_t at=prefix,end=c->size;unsigned count=0;while(at<end&&N(at,1)){int64_t key=at;while(at<end&&N(at,1)&&N(at,1)!='='){if(at-key>=128)return false;at++;}if(at==key||at==end||N(at,1)!='='||++count>4096)return false;int64_t p=key;if(!sxbrs_take(c,&sxbrs_uboot_key_byte,&p,at,(uint64_t)(at-key)))return false;AL(uboot_separator,1);int64_t value=at;while(at<end&&N(at,1)){if(at-value>=32768)return false;at++;}p=value;if(!sxbrs_take(c,&sxbrs_uboot_value_byte,&p,at,(uint64_t)(at-value)))return false;AL(uboot_terminator,1);}
 if(!count||at>=end)return false;AL(uboot_terminator,1);return !c->failed;
}
static bool sxbrs_qnx(sx_context*c){
 if(!sxbrs_eq(c,0,"\xeb\x4c\x44\x44\x44\x44\0\0\0\0\0\1\0\0\0\0",16))return false;int64_t start=-1,end=c->size;
 for(int64_t p=0;p+52<=end&&p<=65536;p+=4){if(N(p,4)==0xff7eeb&&N(p+48,4)==(uint64_t)p&&N(p+32,4)>0&&N(p+32,4)<=INT32_MAX&&N(p+44,4)>0&&N(p+44,4)<=134217728&&N(p+32,4)<=(uint64_t)(end-p-2)){start=p;break;}if(xx_pd_is_stopped(c->pd))return false;}
 if(start<0)return false;uint64_t declared=N(start+8,2),startup=N(start+32,4);const sx_layout*l=declared>=256&&startup>=256&&end-start>=256?&sxbrs_qnx_startup_header:&sxbrs_qnx_startup_prefix;if(!sxbrs_add(c,l,start))return false;
 int64_t at=start+(int64_t)startup;unsigned blocks=0;for(;;){uint64_t n=B(at,2);AL(qnx_block,1);if(!n)return blocks>0;if(++blocks>1048576)return false;SK(n);}
}
static bool sxbrs_sony(sx_context*c){if(c->size<522||!sxbrs_eq(c,0,"TCJN",4)||N(16,4)||N(20,4)!=(uint64_t)c->size-512||N(24,1)||N(25,1)>1||!sxbrs_eq(c,512,"ZLIB",4))return false;return sxbrs_add(c,&sxbrs_sony_image_header,0)&&sxbrs_add(c,&sxbrs_sony_image_zlib_marker,512)&&sxbrs_add(c,&sxbrs_resource_zlib_header,516)&&sxbrs_add(c,&sxbrs_resource_zlib_trailer,c->size-4);}

static int sxbrs_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
static bool sxbrs_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxbrs_order);
 /* Resources can share physical extents. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxbrs_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}


static bool sx_binaryresources_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_PCXLIB:case XX_FILE_TYPE_TORQUE_DTS:case XX_FILE_TYPE_NOKIA_OTA_BITMAP:case XX_FILE_TYPE_FSS:case XX_FILE_TYPE_PX:case XX_FILE_TYPE_EVD:case XX_FILE_TYPE_QNXBASE:case XX_FILE_TYPE_VXWORKS:case XX_FILE_TYPE_MWAVE:case XX_FILE_TYPE_UBOOT_ENV:case XX_FILE_TYPE_ANDROID_LP:case XX_FILE_TYPE_SONY_IMAGE:return true;default:return false;}}
static bool sx_binaryresources_build(sx_context*c){if(!c||c->size<1||c->size>268435456||xx_pd_is_stopped(c->pd))return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_PCXLIB:ok=sxbrs_pcxlib(c);break;case XX_FILE_TYPE_TORQUE_DTS:ok=sxbrs_dts(c);break;case XX_FILE_TYPE_NOKIA_OTA_BITMAP:ok=sxbrs_ota(c);break;case XX_FILE_TYPE_FSS:ok=sxbrs_fss(c);break;case XX_FILE_TYPE_PX:ok=sxbrs_px(c);break;case XX_FILE_TYPE_EVD:ok=sxbrs_evd(c);break;case XX_FILE_TYPE_QNXBASE:ok=sxbrs_qnx(c);break;case XX_FILE_TYPE_VXWORKS:ok=sxbrs_vxworks(c);break;case XX_FILE_TYPE_MWAVE:ok=sxbrs_mwave(c);break;case XX_FILE_TYPE_UBOOT_ENV:ok=sxbrs_uboot(c);break;case XX_FILE_TYPE_ANDROID_LP:ok=sxbrs_lp(c);break;case XX_FILE_TYPE_SONY_IMAGE:ok=sxbrs_sony(c);break;default:return false;}return ok&&sxbrs_finish(c);}
#undef AL
#undef SK
#undef N
#undef B
