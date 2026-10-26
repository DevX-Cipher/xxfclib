/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical modern filesystem metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_modernfs_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_modernfs.h"
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
bool sxmf_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxmf_read(sx_context*c,uint64_t p,void*b,size_t n){return !xx_pd_is_stopped(c->pd)&&sxmf_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint16_t sxmf16(const uint8_t*b,unsigned o){return o==1?(uint16_t)((uint16_t)b[0]<<8|b[1]):(uint16_t)((uint16_t)b[1]<<8|b[0]);}
uint32_t sxmf32(const uint8_t*b,unsigned o){if(o==2)return (uint32_t)sxmf16(b,0)<<16|sxmf16(b+2,0);return o==1?(uint32_t)sxmf16(b,1)<<16|sxmf16(b+2,1):(uint32_t)sxmf16(b+2,0)<<16|sxmf16(b,0);}
uint64_t sxmf64(const uint8_t*b,unsigned o){return o==1?(uint64_t)sxmf32(b,1)<<32|sxmf32(b+4,1):(uint64_t)sxmf32(b+4,0)<<32|sxmf32(b,0);}
bool sxmf_pow(uint64_t v){return v&&!(v&(v-1));}
bool sxmf_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 if(!n)return true;const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(n>1048576U||n>UINT64_MAX/z||!sxmf_span(c,p,n*z)||xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXMF_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&(uint64_t)(c->items[lo-1].offset-c->f->base_address)+(uint64_t)c->items[lo-1].total_size>p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}return true;
}
#define SXMF_ORDER(l,o) ((o)==1?&sxmf_##l##_be:&sxmf_##l##_le)
#define SXMF_UNIX(l,o) ((o)==2?&sxmf_##l##_pdp:SXMF_ORDER(l,o))
void sxmf_queue_add(sxmf_queue*q,uint64_t p,unsigned kind,unsigned depth){if(!p||depth>32||q->count>=SX_COUNT(q->items))return;for(size_t i=0;i<q->count;i++)if(q->items[i].p==p&&q->items[i].kind==kind)return;q->items[q->count++]=(sxmf_task){p,kind,depth};}
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
static bool sx_modernfs_supports(xx_file_type_t type){switch(type){
 case XX_FILE_TYPE_UFS1:case XX_FILE_TYPE_UFS2:case XX_FILE_TYPE_SUFS:case XX_FILE_TYPE_F2FS:case XX_FILE_TYPE_JFS:case XX_FILE_TYPE_NILFS2:case XX_FILE_TYPE_REISERFS:case XX_FILE_TYPE_AMIGA_SFS:case XX_FILE_TYPE_XFS:case XX_FILE_TYPE_ZFS:case XX_FILE_TYPE_GFS2:case XX_FILE_TYPE_FOSSIL_FS:case XX_FILE_TYPE_HAMMER_FS:case XX_FILE_TYPE_REFS:case XX_FILE_TYPE_VXFS:case XX_FILE_TYPE_VMFS:case XX_FILE_TYPE_HPFS:case XX_FILE_TYPE_EROFS:case XX_FILE_TYPE_CDI_FS:case XX_FILE_TYPE_OPERA_FS:return true;default:return false;}}
static int sxmf_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxmf_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxmf_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_modernfs_build(sx_context*c){bool ok=false;switch(c->f->file_type){
 case XX_FILE_TYPE_UFS1:case XX_FILE_TYPE_UFS2:case XX_FILE_TYPE_SUFS:ok=sxmf_ufs(c);break;
 case XX_FILE_TYPE_F2FS:ok=sx_f2fs_build(c);break;case XX_FILE_TYPE_JFS:ok=sx_jfs_build(c);break;case XX_FILE_TYPE_NILFS2:ok=sx_nilfs2_build(c);break;
 case XX_FILE_TYPE_REISERFS:ok=sx_reiserfs_build(c);break;case XX_FILE_TYPE_AMIGA_SFS:ok=sx_amiga_sfs_build(c);break;case XX_FILE_TYPE_XFS:ok=sx_xfs_build(c);break;case XX_FILE_TYPE_ZFS:ok=sx_zfs_build(c);break;case XX_FILE_TYPE_GFS2:ok=sx_gfs2_build(c);break;case XX_FILE_TYPE_FOSSIL_FS:ok=sx_fossil_fs_build(c);break;case XX_FILE_TYPE_HAMMER_FS:ok=sx_hammer_fs_build(c);break;case XX_FILE_TYPE_REFS:ok=sx_refs_build(c);break;case XX_FILE_TYPE_VXFS:ok=sx_vxfs_build(c);break;case XX_FILE_TYPE_VMFS:ok=sx_vmfs_build(c);break;case XX_FILE_TYPE_HPFS:ok=sx_hpfs_build(c);break;case XX_FILE_TYPE_EROFS:ok=sx_erofs_build(c);break;case XX_FILE_TYPE_CDI_FS:ok=sx_cdi_fs_build(c);break;case XX_FILE_TYPE_OPERA_FS:ok=sx_opera_fs_build(c);break;default:return false;}
 /* A malformed optional pointer may leave a valid bounded header. */
 return (ok||c->count)&&!c->failed&&!xx_pd_is_stopped(c->pd)&&c->count&&sxmf_finish(c);
}
#undef SXMF_ORDER
#undef SXMF_UNIX
#undef SXMF_LIMIT
#undef SXMF_INODES
const sx_family sx_modernfs_family={sx_modernfs_supports,sx_modernfs_build,sx_modernfs_layouts,SX_COUNT(sx_modernfs_layouts),sx_modernfs_comment};
