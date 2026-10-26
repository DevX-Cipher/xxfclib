/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical legacy disk image metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_disktail_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_disktail.h"
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
const sx_layout sxdt_cpm_extent8 = {0x607a000bU,"cpm_extent8",sxdt_cpm_extent8_fields,SX_COUNT(sxdt_cpm_extent8_fields),SX_LE};
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
static const xx_data_struct_field_desc sxdt_cpm_deleted_entry_fields[] = {
    SX_FIELD("status","uint8",0,1,SX_ID),
    SX_FIELD("erased_contents","byte[31]",1,31,SX_NONE),
};
const sx_layout sxdt_cpm_deleted_entry = {0x607a0039U,"cpm_deleted_entry",sxdt_cpm_deleted_entry_fields,SX_COUNT(sxdt_cpm_deleted_entry_fields),SX_LE};
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
static const xx_data_struct_field_desc sxdt_hxc_xml_text_fields[] = {
    SX_FIELD("text","utf8",0,0,SX_NONE),
};
static const sx_layout sxdt_hxc_xml_text = {0x607a0077U,"hxc_xml_text",sxdt_hxc_xml_text_fields,SX_COUNT(sxdt_hxc_xml_text_fields),SX_LE};
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
bool sxdt_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxdt_read(sx_context*c,uint64_t p,void*b,size_t n){return !xx_pd_is_stopped(c->pd)&&sxdt_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint16_t sxdt16(const uint8_t*b,unsigned o){return o==1?(uint16_t)((uint16_t)b[0]<<8|b[1]):(uint16_t)((uint16_t)b[1]<<8|b[0]);}
uint32_t sxdt32(const uint8_t*b,unsigned o){if(o==2)return (uint32_t)sxdt16(b,0)<<16|sxdt16(b+2,0);return o==1?(uint32_t)sxdt16(b,1)<<16|sxdt16(b+2,1):(uint32_t)sxdt16(b+2,0)<<16|sxdt16(b,0);}
bool sxdt_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 if(!n)return true;const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(!z||n>1048576U||n>UINT64_MAX/z||!sxdt_span(c,p,n*z)||xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXDT_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&(uint64_t)(c->items[lo-1].offset-c->f->base_address)+(uint64_t)c->items[lo-1].total_size>p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}return true;
}
bool sxdt_value(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){if(!n)return true;if(!sxdt_span(c,p,n)||xx_pd_is_stopped(c->pd))return false;const xx_data_struct_field_desc*last=l->fields+l->field_count-1;uint64_t limit=sx_variable_field_limit(last->type);if(n<=(uint64_t)last->rel_offset||n-(uint64_t)last->rel_offset>limit||n>16384||c->count>=SXDT_LIMIT)return true;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<c->f->base_address+(int64_t)p)lo=m+1;else hi=m;}if(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>c->f->base_address+(int64_t)p)return true;if(lo<c->count&&c->items[lo].offset<c->f->base_address+(int64_t)(p+n))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
static int sxdt_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
bool sxdt_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+z>end)end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxdt_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif
static uint64_t sxdt_avphysical(sxdt_view*v,uint64_t p){return v->base+(v->split?((p/256)*512+(v->split-1)*256+p%256):p);}
static bool sxdt_avspan(sxdt_view*v,uint64_t p,uint64_t n){return p<=v->size&&n<=v->size-p;}
static bool sxdt_avread(sxdt_view*v,uint64_t p,void*out,size_t n){uint8_t*b=out;if(!sxdt_avspan(v,p,n))return false;while(n){size_t z=256-p%256;if(z>n)z=n;if(!sxdt_read(v->c,sxdt_avphysical(v,p),b,z))return false;p+=z;b+=z;n-=z;}return true;}
static bool sxdt_avput(sxdt_view*v,const sx_layout*l,uint64_t p,uint64_t n){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||n>UINT64_MAX/z||!sxdt_avspan(v,p,z*n))return false;for(uint64_t i=0;i<n;i++){uint64_t a=p+i*z,physical=sxdt_avphysical(v,a);bool contiguous=true;for(uint64_t q=0;q<z;){if(sxdt_avphysical(v,a+q)!=physical+q){contiguous=false;break;}uint64_t take=256-(a+q)%256;if(take>z-q)take=z-q;q+=take;}if(contiguous&&!sxdt_put(v->c,l,physical,1))return false;}return true;}
#define SXDT_AV_ADD(c,l,p) sxdt_avput(c,&sxdt_mapped_##l,p,1)
#define SXDT_AV_TABLE(c,l,p,n) sxdt_avput(c,&sxdt_mapped_##l,p,n)
static uint64_t sxdt_av_apple_pos(uint64_t p,bool dos){static const uint8_t map[16]={0,14,13,12,11,10,9,8,7,6,5,4,3,2,1,15};return dos?(p/4096)*4096+(uint64_t)map[(p/256)%16]*256+p%256:p;}
static bool sxdt_av_apple_read(sxdt_view*c,uint64_t p,void*out,size_t n,bool dos){uint8_t*b=out;while(n){size_t z=256-p%256;if(z>n)z=n;if(!sxdt_avread(c,sxdt_av_apple_pos(p,dos),b,z))return false;p+=z;b+=z;n-=z;}return true;}
static bool sxdt_av_apple_put(sxdt_view*c,const sx_layout*l,uint64_t p,bool dos){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t n=f->rel_offset+f->size,at=sxdt_av_apple_pos(p,dos);for(uint64_t q=0;q<n;){uint64_t z=256-(p+q)%256;if(sxdt_av_apple_pos(p+q,dos)!=at+q)return true;q+=z;}return sxdt_avput(c,l,at,1);}
bool sxdt_av_pascal(sxdt_view*c){uint8_t h[26];bool dos=false;if(!sxdt_avread(c,1024,h,26))return false;unsigned count=sxdt16(h+16,0),blocks=sxdt16(h+14,0);if(sxdt16(h+2,0)!=6||h[6]==0||h[6]>7||count>77||blocks<6||blocks>(uint64_t)c->size/512){dos=true;if(c->size<143360||!sxdt_av_apple_read(c,1024,h,26,true))return false;count=sxdt16(h+16,0);blocks=sxdt16(h+14,0);if(sxdt16(h+2,0)!=6||h[6]==0||h[6]>7||count>77||blocks!=280)return false;}
 if(!sxdt_av_apple_put(c,&sxdt_mapped_pascal_volume_header,1024,dos))return false;for(unsigned i=0;i<count;i++)if(!sxdt_av_apple_put(c,&sxdt_mapped_pascal_file_entry,1024+(uint64_t)(i+1)*26,dos))return false;return true;}
bool sxdt_av_pd_header(const uint8_t*h){return !sxdt16(h,0)&&(h[4]>>4)==15&&(h[4]&15)&&h[35]==39&&h[36]==13&&sxdt16(h+41,0)>=5;}
bool sxdt_av_prodos(sxdt_view*c){uint8_t h[512];bool dos=false;if(!sxdt_avread(c,1024,h,512))return false;if(!sxdt_av_pd_header(h)){dos=true;if(c->size<143360||!sxdt_av_apple_read(c,1024,h,512,true)||!sxdt_av_pd_header(h))return false;}
 uint32_t blocks=sxdt16(h+41,0);if(blocks>(uint64_t)c->size/512)return false;uint8_t*seen=xx_rt_calloc(blocks,1);uint16_t*queue=xx_rt_calloc(blocks,sizeof(*queue));if(!seen||!queue){xx_rt_free(seen);xx_rt_free(queue);return false;}size_t n=1,i=0;queue[0]=2;seen[2]=1;bool ok=true;
 while(i<n&&c->c->count<SXDT_LIMIT&&!xx_pd_is_stopped(c->c->pd)){uint32_t b=queue[i++];uint64_t p=(uint64_t)b*512;if(!sxdt_av_apple_read(c,p,h,512,dos))break;if(!sxdt_av_apple_put(c,&sxdt_mapped_prodos_directory_links,p,dos)){ok=false;break;}unsigned next=sxdt16(h+2,0);if(next>=3&&next<blocks&&!seen[next]){seen[next]=1;queue[n++]=(uint16_t)next;}
  for(unsigned j=0;j<13;j++){uint8_t*e=h+4+j*39;unsigned t=e[0]>>4;uint64_t at=p+4+j*39;const sx_layout*l=t==15?&sxdt_mapped_prodos_volume_header:t==14?&sxdt_mapped_prodos_subdirectory_header:t?&sxdt_mapped_prodos_file_entry:NULL;if(!l)continue;if(!sxdt_av_apple_put(c,l,at,dos)){ok=false;break;}unsigned key=sxdt16(e+17,0);if(t==13&&key>=3&&key<blocks&&!seen[key]){seen[key]=1;queue[n++]=(uint16_t)key;}if((t==2||t==3)&&key<blocks&&key>=3){if(!sxdt_av_apple_put(c,&sxdt_mapped_prodos_index_low,(uint64_t)key*512,dos)||!sxdt_av_apple_put(c,&sxdt_mapped_prodos_index_high,(uint64_t)key*512+256,dos)){ok=false;break;}}if(t==5&&key>=3&&key<blocks){if(!sxdt_av_apple_put(c,&sxdt_mapped_prodos_fork_descriptor,(uint64_t)key*512,dos)||!sxdt_av_apple_put(c,&sxdt_mapped_prodos_fork_descriptor,(uint64_t)key*512+256,dos)){ok=false;break;}}}
 }xx_rt_free(seen);xx_rt_free(queue);return ok;}
bool sxdt_av_apple_dos(sxdt_view*c,unsigned spt){uint64_t vp=(uint64_t)17*spt*256;uint8_t v[256],b[256];bool remap=false;if(!sxdt_avread(c,vp,v,256))return false;
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
bool sxdt_av_hfs(sxdt_view*c){uint8_t h[162];if(!sxdt_avread(c,1024,h,162)||sxdt16(h,1)!=0x4244||!SXDT_AV_ADD(c,hfs_master_directory,1024))return false;uint64_t bs=sxdt32(h+20,1),base=(uint64_t)sxdt16(h+28,1)*512;if(bs<512||bs>16777216||bs%512||!sxdt_avspan(c,base,(uint64_t)sxdt16(h+18,1)*bs))return true;return sxdt_av_hfs_tree(c,h+134,base,bs,sxdt32(h+130,1),false)&&sxdt_av_hfs_tree(c,h+150,base,bs,sxdt32(h+146,1),true);}
bool sxdt_dos800(sx_context*c){if(c->size!=819200)return false;for(unsigned i=0;i<2;i++){sxdt_view v={c,c->f->file_type==XX_FILE_TYPE_OZDOS?0:(uint64_t)i*409600,409600,c->f->file_type==XX_FILE_TYPE_OZDOS?i+1:0};if(!sxdt_av_apple_dos(&v,32))return false;}return true;}
bool sxdt_child(sx_context*c,uint64_t p,uint64_t n){uint8_t b[512];sxdt_view v={c,p,n,0};if(!sxdt_avread(&v,1024,b,512))return false;if(sxdt_av_pd_header(b))return sxdt_av_prodos(&v);if(b[0]=='B'&&b[1]=='D')return sxdt_av_hfs(&v);if(!sxdt16(b,0)&&sxdt16(b+2,0)==6)return sxdt_av_pascal(&v);return false;}
bool sxdt_space(uint8_t b){return b==32||b==9||b==10||b==13;}
bool sxdt_eq(const uint8_t*b,size_t n,const char*s){return xx_rt_strlen(s)==n&&!xx_rt_memcmp(b,s,n);}
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
bool sxdt_xml(sx_context*c,uint64_t base,uint64_t length,bool hxc){if(!length||length>(hxc?2097152U:16777216U)||!sxdt_span(c,base,length))return false;uint8_t*b=xx_rt_malloc((size_t)length);if(!b)return false;bool ok=sxdt_read(c,base,b,(size_t)length);size_t pos=0,depth=0,start[64],names[64],n=(size_t)length;while(ok&&pos<n&&c->count<SXDT_LIMIT&&!xx_pd_is_stopped(c->pd)){if(b[pos]!='<'){size_t a=pos;while(pos<n&&b[pos]!='<')pos++;if(depth)ok=sxdt_xml_value(c,b,base,a,pos-a,b+start[depth-1],names[depth-1],hxc);continue;}size_t a=pos;if(n-pos>=4&&!xx_rt_memcmp(b+pos,"<!--",4)){pos+=4;while(pos+3<=n&&xx_rt_memcmp(b+pos,"-->",3))pos++;if(pos+3>n)break;pos+=3;continue;}if(n-pos>=9&&!xx_rt_memcmp(b+pos,"<![CDATA[",9)){pos+=9;size_t text=pos;while(pos+3<=n&&xx_rt_memcmp(b+pos,"]]>",3))pos++;if(pos+3>n)break;if(depth)ok=sxdt_xml_value(c,b,base,text,pos-text,b+start[depth-1],names[depth-1],hxc);pos+=3;continue;}if(pos+1<n&&(b[pos+1]=='?'||b[pos+1]=='!')){uint8_t quote=0;pos+=2;while(pos<n){uint8_t x=b[pos++];if(quote){if(x==quote)quote=0;}else if(x=='\''||x=='"')quote=x;else if(x=='>')break;}continue;}pos++;bool closing=pos<n&&b[pos]=='/';if(closing)pos++;while(pos<n&&sxdt_space(b[pos]))pos++;size_t tag=pos;while(pos<n&&!sxdt_space(b[pos])&&b[pos]!='>'&&b[pos]!='/')pos++;size_t tn=pos-tag;if(!tn)break;ok=sxdt_value(c,hxc?&sxdt_hxc_xml_tag:&sxdt_xva_xml_tag,base+tag,tn);bool self=false;while(ok&&pos<n&&b[pos]!='>'){while(pos<n&&sxdt_space(b[pos]))pos++;if(pos==n||b[pos]=='>')break;if(b[pos]=='/'){self=true;pos++;continue;}size_t key=pos;while(pos<n&&!sxdt_space(b[pos])&&b[pos]!='='&&b[pos]!='>'&&b[pos]!='/')pos++;size_t kn=pos-key;while(pos<n&&sxdt_space(b[pos]))pos++;if(!kn||pos>=n||b[pos]!='=')break;pos++;while(pos<n&&sxdt_space(b[pos]))pos++;if(pos>=n||(b[pos]!='\''&&b[pos]!='"'))break;uint8_t quote=b[pos++];size_t value=pos;while(pos<n&&b[pos]!=quote)pos++;if(pos>=n)break;if(hxc){ok=sxdt_value(c,&sxdt_hxc_xml_attribute_name,base+key,kn)&&sxdt_xml_value(c,b,base,value,pos-value,b+key,kn,true);}pos++;}if(pos>=n||b[pos]!='>')break;pos++;if(closing){if(depth)depth--;}else if(!self){if(depth>=64)break;start[depth]=tag;names[depth]=tn;depth++;}(void)a;}xx_rt_free(b);return ok&&!xx_pd_is_stopped(c->pd);}
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
static bool sx_disktail_build(sx_context*c){
if(c->f->file_type==XX_FILE_TYPE_APPLE_RDOS)return sx_apple_rdos_build(c);
if(c->f->file_type==XX_FILE_TYPE_AMDOS)return sx_amdos_build(c);
if(c->f->file_type==XX_FILE_TYPE_OZDOS)return sx_ozdos_build(c);
if(c->f->file_type==XX_FILE_TYPE_UNIDOS)return sx_unidos_build(c);
if(c->f->file_type==XX_FILE_TYPE_CFFA)return sx_cffa_build(c);
if(c->f->file_type==XX_FILE_TYPE_APPLE_DOS_HYBRID)return sx_apple_dos_hybrid_build(c);
if(c->f->file_type==XX_FILE_TYPE_DOS_MASTER)return sx_dos_master_build(c);
if(c->f->file_type==XX_FILE_TYPE_MAC_TS)return sx_mac_ts_build(c);
if(c->f->file_type==XX_FILE_TYPE_PASCAL_PROFILE_MANAGER)return sx_pascal_profile_manager_build(c);
if(c->f->file_type==XX_FILE_TYPE_LISA_FS)return sx_lisa_fs_build(c);
if(c->f->file_type==XX_FILE_TYPE_ACT_APRICOT_PC_XI_RAW)return sx_act_apricot_pc_xi_raw_build(c);
if(c->f->file_type==XX_FILE_TYPE_BONDWELL_2_DISK)return sx_bondwell_2_disk_build(c);
if(c->f->file_type==XX_FILE_TYPE_ACORN_ATOM_DISK)return sx_acorn_atom_disk_build(c);
if(c->f->file_type==XX_FILE_TYPE_CASIO_FZ_1_DISK)return sx_casio_fz_1_disk_build(c);
#if SX_ALIAS_READER_FACTORY && defined(CPM)
if(c->f->file_type==XX_FILE_TYPE_CPM)return sx_cpm_build(c);
#endif
if(c->f->file_type==XX_FILE_TYPE_XVA)return sx_xva_build(c);
if(c->f->file_type==XX_FILE_TYPE_MGT)return sx_mgt_build(c);
if(c->f->file_type==XX_FILE_TYPE_RAWCD)return sx_rawcd_build(c);
if(c->f->file_type==XX_FILE_TYPE_SOLAR_FS)return sx_solar_fs_build(c);
if(c->f->file_type==XX_FILE_TYPE_PLAN9_PARTITIONS)return sx_plan9_partitions_build(c);
if(c->f->file_type==XX_FILE_TYPE_HXC_XML_DISK_LAYOUT)return sx_hxc_xml_disk_layout_build(c);
return false;}
const sx_family sx_disktail_family={sx_disktail_supports,sx_disktail_build,sx_disktail_layouts,SX_COUNT(sx_disktail_layouts),sx_disktail_comment};
