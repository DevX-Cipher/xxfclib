/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical disk image and filesystem metadata. Unimplemented payloads remain raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_diskmeta.h"
static const xx_data_struct_field_desc sx_dm_vhdx_metadata_table_entry_fields[] = {
    SX_FIELD("item_id","byte[16]",0,16,SX_ID),
    SX_FIELD("offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("length","uint32",20,4,SX_SIZE),
    SX_FIELD("flags","uint32",24,4,SX_FLAGS),
    SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
};
const sx_layout sx_dm_vhdx_metadata_table_entry = {0x60290006U,"vhdx_metadata_table_entry",sx_dm_vhdx_metadata_table_entry_fields,SX_COUNT(sx_dm_vhdx_metadata_table_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vhdx_parent_locator_entry_fields[] = {
    SX_FIELD("key_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("value_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("key_length","uint16",8,2,SX_SIZE),
    SX_FIELD("value_length","uint16",10,2,SX_SIZE),
};
const sx_layout sx_dm_vhdx_parent_locator_entry = {0x6029000dU,"vhdx_parent_locator_entry",sx_dm_vhdx_parent_locator_entry_fields,SX_COUNT(sx_dm_vhdx_parent_locator_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vhdx_bat_entry_fields[] = {
    SX_FIELD("file_offset_and_state","uint64",0,8,SX_FLAGS),
};
const sx_layout sx_dm_vhdx_bat_entry = {0x6029000eU,"vhdx_bat_entry",sx_dm_vhdx_bat_entry_fields,SX_COUNT(sx_dm_vhdx_bat_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vhd_footer_511_fields[] = {
    SX_FIELD("cookie","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("features","uint32",8,4,SX_FLAGS),
    SX_FIELD("file_format_version","uint32",12,4,SX_NONE),
    SX_FIELD("data_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("timestamp","uint32",24,4,SX_TIME),
    SX_FIELD("creator_application","byte[4]",28,4,SX_ID),
    SX_FIELD("creator_version","uint32",32,4,SX_NONE),
    SX_FIELD("creator_host_os","byte[4]",36,4,SX_ID),
    SX_FIELD("original_size","uint64",40,8,SX_SIZE),
    SX_FIELD("current_size","uint64",48,8,SX_SIZE),
    SX_FIELD("cylinders","uint16",56,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint8",58,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",59,1,SX_COUNT_PROP),
    SX_FIELD("disk_type","uint32",60,4,SX_ID),
    SX_FIELD("checksum","uint32",64,4,SX_CHECKSUM),
    SX_FIELD("unique_id","byte[16]",68,16,SX_ID),
    SX_FIELD("saved_state","uint8",84,1,SX_FLAGS),
    SX_FIELD("reserved","byte[426]",85,426,SX_RESERVED),
};
const sx_layout sx_dm_vhd_footer_511 = {0x6029000fU,"vhd_footer_511",sx_dm_vhd_footer_511_fields,SX_COUNT(sx_dm_vhd_footer_511_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_vhd_footer_512_fields[] = {
    SX_FIELD("cookie","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("features","uint32",8,4,SX_FLAGS),
    SX_FIELD("file_format_version","uint32",12,4,SX_NONE),
    SX_FIELD("data_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("timestamp","uint32",24,4,SX_TIME),
    SX_FIELD("creator_application","byte[4]",28,4,SX_ID),
    SX_FIELD("creator_version","uint32",32,4,SX_NONE),
    SX_FIELD("creator_host_os","byte[4]",36,4,SX_ID),
    SX_FIELD("original_size","uint64",40,8,SX_SIZE),
    SX_FIELD("current_size","uint64",48,8,SX_SIZE),
    SX_FIELD("cylinders","uint16",56,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint8",58,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",59,1,SX_COUNT_PROP),
    SX_FIELD("disk_type","uint32",60,4,SX_ID),
    SX_FIELD("checksum","uint32",64,4,SX_CHECKSUM),
    SX_FIELD("unique_id","byte[16]",68,16,SX_ID),
    SX_FIELD("saved_state","uint8",84,1,SX_FLAGS),
    SX_FIELD("reserved","byte[427]",85,427,SX_RESERVED),
};
const sx_layout sx_dm_vhd_footer_512 = {0x60290010U,"vhd_footer_512",sx_dm_vhd_footer_512_fields,SX_COUNT(sx_dm_vhd_footer_512_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_vhd_parent_locator_fields[] = {
    SX_FIELD("platform_code","byte[4]",0,4,SX_ID),
    SX_FIELD("platform_data_space","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("platform_data_length","uint32",8,4,SX_SIZE),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
    SX_FIELD("platform_data_offset","uint64",16,8,SX_OFFSET),
};
const sx_layout sx_dm_vhd_parent_locator = {0x60290012U,"vhd_parent_locator",sx_dm_vhd_parent_locator_fields,SX_COUNT(sx_dm_vhd_parent_locator_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_vhd_bat_entry_fields[] = {
    SX_FIELD("sector_index","uint32",0,4,SX_ID),
};
const sx_layout sx_dm_vhd_bat_entry = {0x60290013U,"vhd_bat_entry",sx_dm_vhd_bat_entry_fields,SX_COUNT(sx_dm_vhd_bat_entry_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_vmdk_grain_directory_entry_fields[] = {
    SX_FIELD("grain_table_sector","uint32",0,4,SX_ID),
};
const sx_layout sx_dm_vmdk_grain_directory_entry = {0x60290015U,"vmdk_grain_directory_entry",sx_dm_vmdk_grain_directory_entry_fields,SX_COUNT(sx_dm_vmdk_grain_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vmdk_grain_table_entry_fields[] = {
    SX_FIELD("grain_sector","uint32",0,4,SX_ID),
};
const sx_layout sx_dm_vmdk_grain_table_entry = {0x60290016U,"vmdk_grain_table_entry",sx_dm_vmdk_grain_table_entry_fields,SX_COUNT(sx_dm_vmdk_grain_table_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vdi_header_v1_fields[] = {
    SX_FIELD("header_size","uint32",0,4,SX_SIZE),
    SX_FIELD("image_type","uint32",4,4,SX_ID),
    SX_FIELD("flags","uint32",8,4,SX_FLAGS),
    SX_FIELD("description","char[256]",12,256,SX_NONE),
    SX_FIELD("block_map_offset","uint32",268,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",272,4,SX_OFFSET),
    SX_FIELD("cylinders","uint32",276,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",280,4,SX_COUNT_PROP),
    SX_FIELD("sectors","uint32",284,4,SX_COUNT_PROP),
    SX_FIELD("sector_size","uint32",288,4,SX_SIZE),
    SX_FIELD("reserved","uint32",292,4,SX_RESERVED),
    SX_FIELD("disk_size","uint64",296,8,SX_SIZE),
    SX_FIELD("block_size","uint32",304,4,SX_SIZE),
    SX_FIELD("block_extra","uint32",308,4,SX_SIZE),
    SX_FIELD("blocks_in_image","uint32",312,4,SX_COUNT_PROP),
    SX_FIELD("blocks_allocated","uint32",316,4,SX_COUNT_PROP),
    SX_FIELD("uuid_image","byte[16]",320,16,SX_ID),
    SX_FIELD("uuid_modify","byte[16]",336,16,SX_ID),
    SX_FIELD("uuid_linkage","byte[16]",352,16,SX_ID),
    SX_FIELD("uuid_parent_modify","byte[16]",368,16,SX_ID),
};
const sx_layout sx_dm_vdi_header_v1 = {0x60290019U,"vdi_header_v1",sx_dm_vdi_header_v1_fields,SX_COUNT(sx_dm_vdi_header_v1_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vdi_block_map_entry_fields[] = {
    SX_FIELD("block_index","uint32",0,4,SX_ID),
};
const sx_layout sx_dm_vdi_block_map_entry = {0x6029001aU,"vdi_block_map_entry",sx_dm_vdi_block_map_entry_fields,SX_COUNT(sx_dm_vdi_block_map_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_parallels_bat_sector_fields[] = {
    SX_FIELD("sector_index","uint32",0,4,SX_ID),
};
const sx_layout sx_dm_parallels_bat_sector = {0x60290020U,"parallels_bat_sector",sx_dm_parallels_bat_sector_fields,SX_COUNT(sx_dm_parallels_bat_sector_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_parallels_bat_cluster_fields[] = {
    SX_FIELD("cluster_index","uint32",0,4,SX_ID),
};
const sx_layout sx_dm_parallels_bat_cluster = {0x60290021U,"parallels_bat_cluster",sx_dm_parallels_bat_cluster_fields,SX_COUNT(sx_dm_parallels_bat_cluster_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_chd_map_v12_fields[] = {
    SX_FIELD("packed_offset_and_length","uint64",0,8,SX_FLAGS),
};
const sx_layout sx_dm_chd_map_v12 = {0x60290027U,"chd_map_v12",sx_dm_chd_map_v12_fields,SX_COUNT(sx_dm_chd_map_v12_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_chd_map_v34_fields[] = {
    SX_FIELD("offset_or_reference","uint64",0,8,SX_ID),
    SX_FIELD("crc32","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("length_low","uint16",12,2,SX_NONE),
    SX_FIELD("length_high","uint8",14,1,SX_NONE),
    SX_FIELD("flags","uint8",15,1,SX_FLAGS),
};
const sx_layout sx_dm_chd_map_v34 = {0x60290028U,"chd_map_v34",sx_dm_chd_map_v34_fields,SX_COUNT(sx_dm_chd_map_v34_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_chd_map_v5_uncompressed_fields[] = {
    SX_FIELD("hunk_index","uint32",0,4,SX_ID),
};
const sx_layout sx_dm_chd_map_v5_uncompressed = {0x60290029U,"chd_map_v5_uncompressed",sx_dm_chd_map_v5_uncompressed_fields,SX_COUNT(sx_dm_chd_map_v5_uncompressed_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_ubi_erase_counter_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint8",4,1,SX_NONE),
    SX_FIELD("padding1","byte[3]",5,3,SX_RESERVED),
    SX_FIELD("erase_counter","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("vid_header_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",20,4,SX_OFFSET),
    SX_FIELD("image_sequence","uint32",24,4,SX_NONE),
    SX_FIELD("padding2","byte[32]",28,32,SX_RESERVED),
    SX_FIELD("header_crc","uint32",60,4,SX_CHECKSUM),
};
const sx_layout sx_dm_ubi_erase_counter_header = {0x60290032U,"ubi_erase_counter_header",sx_dm_ubi_erase_counter_header_fields,SX_COUNT(sx_dm_ubi_erase_counter_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_ubi_volume_identifier_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint8",4,1,SX_NONE),
    SX_FIELD("volume_type","uint8",5,1,SX_ID),
    SX_FIELD("copy_flag","uint8",6,1,SX_FLAGS),
    SX_FIELD("compatibility","uint8",7,1,SX_ID),
    SX_FIELD("volume_id","uint32",8,4,SX_ID),
    SX_FIELD("logical_block_number","uint32",12,4,SX_ID),
    SX_FIELD("padding1","byte[4]",16,4,SX_RESERVED),
    SX_FIELD("data_size","uint32",20,4,SX_SIZE),
    SX_FIELD("used_eraseblocks","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("data_padding","uint32",28,4,SX_SIZE),
    SX_FIELD("data_crc","uint32",32,4,SX_CHECKSUM),
    SX_FIELD("padding2","byte[4]",36,4,SX_RESERVED),
    SX_FIELD("sequence_number","uint64",40,8,SX_NONE),
    SX_FIELD("padding3","byte[12]",48,12,SX_RESERVED),
    SX_FIELD("header_crc","uint32",60,4,SX_CHECKSUM),
};
const sx_layout sx_dm_ubi_volume_identifier_header = {0x60290033U,"ubi_volume_identifier_header",sx_dm_ubi_volume_identifier_header_fields,SX_COUNT(sx_dm_ubi_volume_identifier_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_rdb_filesystem_header_fields[] = {
    SX_FIELD("identifier","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("summed_longs","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("checksum","int32",8,4,SX_CHECKSUM),
    SX_FIELD("host_id","uint32",12,4,SX_ID),
    SX_FIELD("next_block","uint32",16,4,SX_ID),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("reserved1","uint32[2]",24,8,SX_RESERVED),
    SX_FIELD("dos_type","uint32",32,4,SX_ID),
    SX_FIELD("version","uint32",36,4,SX_NONE),
    SX_FIELD("patch_flags","uint32",40,4,SX_FLAGS),
    SX_FIELD("type","uint32",44,4,SX_ID),
    SX_FIELD("task","uint32",48,4,SX_POINTER),
    SX_FIELD("lock","uint32",52,4,SX_POINTER),
    SX_FIELD("handler","uint32",56,4,SX_POINTER),
    SX_FIELD("stack_size","uint32",60,4,SX_SIZE),
    SX_FIELD("priority","int32",64,4,SX_NONE),
    SX_FIELD("startup","int32",68,4,SX_POINTER),
    SX_FIELD("segment_list_block","int32",72,4,SX_ID),
    SX_FIELD("global_vector","int32",76,4,SX_NONE),
};
const sx_layout sx_dm_rdb_filesystem_header = {0x60290056U,"rdb_filesystem_header",sx_dm_rdb_filesystem_header_fields,SX_COUNT(sx_dm_rdb_filesystem_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_ndif_chunk_entry_fields[] = {
    SX_FIELD("first_sector","uint24",0,3,SX_ID),
    SX_FIELD("type","uint8",3,1,SX_ID),
    SX_FIELD("data_fork_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("data_fork_length","uint32",8,4,SX_SIZE),
};
const sx_layout sx_dm_ndif_chunk_entry = {0x60290059U,"ndif_chunk_entry",sx_dm_ndif_chunk_entry_fields,SX_COUNT(sx_dm_ndif_chunk_entry_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_ndif_resource_type_count_fields[] = {
    SX_FIELD("type_count_minus_one","uint16",0,2,SX_NONE),
};
const sx_layout sx_dm_ndif_resource_type_count = {0x6029005fU,"ndif_resource_type_count",sx_dm_ndif_resource_type_count_fields,SX_COUNT(sx_dm_ndif_resource_type_count_fields),SX_BE};
static const sx_layout *const sx_diskmeta_layouts[] = {
    &sx_dm_vhdx_file_identifier,
    &sx_dm_vhdx_header,
    &sx_dm_vhdx_region_table_header,
    &sx_dm_vhdx_region_table_entry,
    &sx_dm_vhdx_metadata_table_header,
    &sx_dm_vhdx_metadata_table_entry,
    &sx_dm_vhdx_file_parameters,
    &sx_dm_vhdx_disk_size,
    &sx_dm_vhdx_logical_sector_size,
    &sx_dm_vhdx_physical_sector_size,
    &sx_dm_vhdx_virtual_disk_id,
    &sx_dm_vhdx_parent_locator,
    &sx_dm_vhdx_parent_locator_entry,
    &sx_dm_vhdx_bat_entry,
    &sx_dm_vhd_footer_511,
    &sx_dm_vhd_footer_512,
    &sx_dm_vhd_dynamic_header,
    &sx_dm_vhd_parent_locator,
    &sx_dm_vhd_bat_entry,
    &sx_dm_vmdk_sparse_header,
    &sx_dm_vmdk_grain_directory_entry,
    &sx_dm_vmdk_grain_table_entry,
    &sx_dm_vmdk_metadata_marker,
    &sx_dm_vdi_preheader,
    &sx_dm_vdi_header_v1,
    &sx_dm_vdi_block_map_entry,
    &sx_dm_qed_header,
    &sx_dm_qed_l1_entry,
    &sx_dm_qed_l2_entry,
    &sx_dm_parallels_header_extended,
    &sx_dm_parallels_header_old,
    &sx_dm_parallels_bat_sector,
    &sx_dm_parallels_bat_cluster,
    &sx_dm_chd_header_v1,
    &sx_dm_chd_header_v2,
    &sx_dm_chd_header_v3,
    &sx_dm_chd_header_v4,
    &sx_dm_chd_header_v5,
    &sx_dm_chd_map_v12,
    &sx_dm_chd_map_v34,
    &sx_dm_chd_map_v5_uncompressed,
    &sx_dm_chd_map_v5_compressed_header,
    &sx_dm_chd_metadata_header,
    &sx_dm_udif_trailer,
    &sx_dm_cloop_header,
    &sx_dm_cloop_block_offset,
    &sx_dm_encrypted_dmg_v2_header,
    &sx_dm_encrypted_dmg_key_pointer,
    &sx_dm_encrypted_dmg_v1_trailer,
    &sx_dm_ubi_erase_counter_header,
    &sx_dm_ubi_volume_identifier_header,
    &sx_dm_ubi_volume_table_record,
    &sx_dm_ubifs_common_header,
    &sx_dm_ubifs_superblock,
    &sx_dm_ubifs_master_node,
    &sx_dm_ubifs_index_header,
    &sx_dm_ubifs_index_branch,
    &sx_dm_ubifs_inode_node,
    &sx_dm_ubifs_directory_entry,
    &sx_dm_ubifs_data_node,
    &sx_dm_ubifs_padding_node,
    &sx_dm_ubifs_commit_start,
    &sx_dm_ubifs_reference_node,
    &sx_dm_jffs2_common_header_le,
    &sx_dm_jffs2_directory_entry_le,
    &sx_dm_jffs2_inode_le,
    &sx_dm_jffs2_xattr_le,
    &sx_dm_jffs2_xref_le,
    &sx_dm_yaffs_object_header_le,
    &sx_dm_qnx6_superblock_header_le,
    &sx_dm_qnx6_root_node_le,
    &sx_dm_jffs2_common_header_be,
    &sx_dm_jffs2_directory_entry_be,
    &sx_dm_jffs2_inode_be,
    &sx_dm_jffs2_xattr_be,
    &sx_dm_jffs2_xref_be,
    &sx_dm_yaffs_object_header_be,
    &sx_dm_qnx6_superblock_header_be,
    &sx_dm_qnx6_root_node_be,
    &sx_dm_logfs_superblock,
    &sx_dm_apm_driver_descriptor_header,
    &sx_dm_apm_driver_descriptor,
    &sx_dm_apm_partition_entry,
    &sx_dm_rdb_rigid_disk_block,
    &sx_dm_rdb_partition_block,
    &sx_dm_rdb_filesystem_header,
    &sx_dm_rdb_load_segment_header,
    &sx_dm_ndif_bcem_header,
    &sx_dm_ndif_chunk_entry,
    &sx_dm_ndif_resource_fork_header,
    &sx_dm_ndif_resource_map_header,
    &sx_dm_ndif_resource_type,
    &sx_dm_ndif_resource_reference,
    &sx_dm_ndif_resource_length,
    &sx_dm_ndif_resource_type_count,
};
#include "xxfclib/algo/crc/xx_crc.h"
bool sx_dm_span(sx_context*c,uint64_t p,uint64_t n){return p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sx_dm_read(sx_context*c,uint64_t p,void*b,size_t n){return sx_dm_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint32_t sx_dm_u32(const void*b,size_t o,bool be){return xx_data_get_u32((const uint8_t*)b+o,4,0,be);}
uint64_t sx_dm_u64(const void*b,size_t o,bool be){return xx_data_get_u64((const uint8_t*)b+o,8,0,be);}
uint16_t sx_dm_u16(const void*b,size_t o,bool be){return xx_data_get_u16((const uint8_t*)b+o,2,0,be);}
/* Aliased metadata is shown once. Optional partially overlapping layouts remain
 * raw rather than discarding already authenticated physical headers. */
static bool sx_dm_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t z,uint64_t n){if(!n)return true;if(z>INT64_MAX/n||!sx_dm_span(c,p,z*n))return false;if(c->count>=24000)return true;for(size_t i=0;i<c->count;i++){uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),b=(uint64_t)c->items[i].total_size;if(p<a+b&&a<p+z*n)return true;}return sx_table(c,l,(int64_t)p,(int64_t)z,n);}
bool sx_dm_add(sx_context*c,const sx_layout*l,uint64_t p,uint64_t z){return sx_dm_put(c,l,p,z,1);}
bool sx_dm_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t z,uint64_t n){if(n>65536)n=65536;return sx_dm_put(c,l,p,z,n);}
bool sx_dm_crc(sx_context*c,uint64_t p,uint64_t n,uint32_t want,bool castagnoli,bool complement,bool zero4){uint8_t b[4096];uint32_t crc=0;uint64_t done=0;if(!sx_dm_span(c,p,n)||n>UINT64_C(16777216))return false;while(done<n){size_t z=(size_t)(n-done>sizeof(b)?sizeof(b):n-done);if(!sx_dm_read(c,p+done,b,z))return false;if(zero4&&done==0&&z>=8)xx_rt_memset(b+4,0,4);crc=castagnoli?xx_crc32c_calc(crc,b,z):xx_crc32_calc(crc,b,z);done+=z;}return (complement?~crc:crc)==want;}
static bool sx_diskmeta_supports(xx_file_type_t t){switch(t){
case XX_FILE_TYPE_VHDX:
case XX_FILE_TYPE_VHDDYNAMIC:
case XX_FILE_TYPE_VMDK:
case XX_FILE_TYPE_VDI:
case XX_FILE_TYPE_QEMU_ENHANCED_DISK:
case XX_FILE_TYPE_PARALLELS_HDD:
case XX_FILE_TYPE_CHD:
case XX_FILE_TYPE_DMG:
case XX_FILE_TYPE_CLOOP:
case XX_FILE_TYPE_UBI:
case XX_FILE_TYPE_UBIFS:
case XX_FILE_TYPE_JFFS2:
case XX_FILE_TYPE_YAFFS:
case XX_FILE_TYPE_QNX6:
case XX_FILE_TYPE_LOGFS:
case XX_FILE_TYPE_APM:
case XX_FILE_TYPE_RDB:
case XX_FILE_TYPE_APPLE_DISK_COPY_6_NDIF_IMAGE:
case XX_FILE_TYPE_ENCRYPTED_APPLE_DISK_IMAGE:
return true;default:return false;}}
static int sx_dm_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sx_dm_finish(sx_context*c){size_t n=c->count;int64_t end=0;if(!n)return false;xx_rt_qsort(c->items,n,sizeof(*c->items),sx_dm_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sx_dm_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_diskmeta_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_VHDX:ok=sx_vhdx_build(c);break;
case XX_FILE_TYPE_VHDDYNAMIC:ok=sx_vhddynamic_build(c);break;
case XX_FILE_TYPE_VMDK:ok=sx_vmdk_build(c);break;
case XX_FILE_TYPE_VDI:ok=sx_vdi_build(c);break;
case XX_FILE_TYPE_QEMU_ENHANCED_DISK:ok=sx_qemu_enhanced_disk_build(c);break;
case XX_FILE_TYPE_PARALLELS_HDD:ok=sx_parallels_hdd_build(c);break;
case XX_FILE_TYPE_CHD:ok=sx_chd_build(c);break;
case XX_FILE_TYPE_DMG:ok=sx_dmg_build(c);break;
case XX_FILE_TYPE_CLOOP:ok=sx_cloop_build(c);break;
case XX_FILE_TYPE_UBI:ok=sx_ubi_build(c);break;
case XX_FILE_TYPE_UBIFS:ok=sx_ubifs_build(c);break;
case XX_FILE_TYPE_JFFS2:ok=sx_jffs2_build(c);break;
case XX_FILE_TYPE_YAFFS:ok=sx_yaffs_build(c);break;
case XX_FILE_TYPE_QNX6:ok=sx_qnx6_build(c);break;
case XX_FILE_TYPE_LOGFS:ok=sx_logfs_build(c);break;
case XX_FILE_TYPE_APM:ok=sx_apm_build(c);break;
case XX_FILE_TYPE_RDB:ok=sx_rdb_build(c);break;
case XX_FILE_TYPE_APPLE_DISK_COPY_6_NDIF_IMAGE:ok=sx_apple_disk_copy_6_ndif_image_build(c);break;
case XX_FILE_TYPE_ENCRYPTED_APPLE_DISK_IMAGE:ok=sx_encrypted_apple_disk_image_build(c);break;
default:break;}return ok&&sx_dm_finish(c);}
static bool sx_diskmeta_comment(xx_data_struct_record*r,uint32_t id){if(!r||!r->name||id<0x60290000U||id>=0x602a0000U)return true;const wchar_t*s=NULL;uint64_t v=(r->value.type==XX_VAR_TYPE_FLOAT||r->value.type==XX_VAR_TYPE_DOUBLE||r->value.type==XX_VAR_TYPE_STRING||r->value.type==XX_VAR_TYPE_BYTES)?0:xx_var_get_u64(&r->value);
 if(!xx_rt_wcscmp(r->name,L"timestamp")&&(id==sx_dm_vhd_footer_511.id||id==sx_dm_vhd_footer_512.id))s=L"Seconds since 2000-01-01 UTC";
 else if(!xx_rt_wcscmp(r->name,L"parent_timestamp"))s=L"Seconds since 2000-01-01 UTC";
 else if(!xx_rt_wcscmp(r->name,L"disk_type"))s=v==2?L"Fixed hard disk":v==3?L"Dynamic hard disk":v==4?L"Differencing hard disk":NULL;
 else if(id==sx_dm_vdi_header_v1.id&&!xx_rt_wcscmp(r->name,L"image_type"))s=v==1?L"Dynamic":v==2?L"Fixed":v==3?L"Undo":v==4?L"Differencing":NULL;
 else if(id==sx_dm_vdi_block_map_entry.id)s=v==UINT32_MAX?L"Unallocated block":v==UINT32_MAX-1?L"Zero block":L"Physical block index in data area; multiply by block_size + block_extra";
 else if(id==sx_dm_vhd_bat_entry.id)s=v==UINT32_MAX?L"Unallocated block":L"File-relative sector index in 512-byte units; points to the block bitmap";
 else if(id==sx_dm_vmdk_grain_directory_entry.id||id==sx_dm_vmdk_grain_table_entry.id)s=L"File-relative index in 512-byte sectors; zero means unallocated";
 else if(id==sx_dm_parallels_bat_sector.id)s=L"File-relative index in 512-byte sectors; zero means unallocated";
 else if(id==sx_dm_parallels_bat_cluster.id)s=L"File-relative index in cluster_sectors*512 bytes; zero means unallocated";
 else if(id==sx_dm_vhdx_bat_entry.id)s=L"Bits0..2: state; bits3..19: reserved; bits20..63: file byte offset (MiB aligned); states0 not present,1 undefined,2 zero,3 unmapped,6 fully present,7 partially present";
 else if(id==sx_dm_chd_map_v12.id)s=L"Packed 64-bit map word: low44 bits file byte offset, high20 bits stored length";
 else if(id==sx_dm_chd_map_v34.id&&!xx_rt_wcscmp(r->name,L"offset_or_reference"))s=L"Meaning depends on flags: file byte offset, self/parent hunk index, or repeated eight-byte literal";
 else if(id==sx_dm_chd_map_v34.id&&!xx_rt_wcscmp(r->name,L"length_low"))s=L"Low16 bits of stored byte length; combined with length_high shifted16";
 else if(id==sx_dm_chd_map_v34.id&&!xx_rt_wcscmp(r->name,L"length_high"))s=L"High8 bits of stored byte length; not a complete byte size";
 else if(id==sx_dm_chd_map_v5_uncompressed.id)s=L"File offset divided by hunk_bytes; zero denotes unallocated/inherited data";
 else if(id==sx_dm_vhd_parent_locator.id&&!xx_rt_wcscmp(r->name,L"platform_data_space"))s=L"Reserved space in 512-byte sectors";
 else if(id==sx_dm_vhdx_metadata_table_entry.id&&!xx_rt_wcscmp(r->name,L"offset"))s=L"Byte offset relative to the containing metadata region; physical stored value is not translated";
 else if(id==sx_dm_vhdx_parent_locator_entry.id&&(!xx_rt_wcscmp(r->name,L"key_offset")||!xx_rt_wcscmp(r->name,L"value_offset")))s=L"Byte offset relative to the parent-locator item";
 else if(!xx_rt_wcscmp(r->name,L"segment_shift")||!xx_rt_wcscmp(r->name,L"block_shift")||!xx_rt_wcscmp(r->name,L"write_shift"))s=L"Base-two logarithm of the byte size; an encoded shift, not a byte count";
 else if(!xx_rt_wcscmp(r->name,L"file_size_low"))s=L"Low32 bits of file size; combine with high word subject to the format's unused-high sentinel";
 else if(!xx_rt_wcscmp(r->name,L"file_size_high"))s=L"High32 bits of file size; 0xFFFFFFFF means unused in legacy YAFFS images";
 else if(!xx_rt_wcscmp(r->name,L"key_type_and_value"))s=L"High3 bits: key kind (0 inode,1 data,2 directory entry,3 xattr); low29 bits: block index or name hash";
 else if(id==sx_dm_ubi_volume_identifier_header.id&&!xx_rt_wcscmp(r->name,L"volume_id"))s=v==0x7fffefff?L"UBI_LAYOUT_VOLUME_ID":NULL;
 else if(!xx_rt_wcscmp(r->name,L"volume_type"))s=v==1?L"Dynamic volume":v==2?L"Static volume":NULL;
 else if(id==sx_dm_ubi_erase_counter_header.id&&(!xx_rt_wcscmp(r->name,L"vid_header_offset")||!xx_rt_wcscmp(r->name,L"data_offset")))s=L"Byte offset relative to the containing physical eraseblock";
 else if(id==sx_dm_rdb_filesystem_header.id&&!xx_rt_wcscmp(r->name,L"startup"))s=L"Signed DeviceNode startup word; applied only when its patch_flags bit is set";
 else if(id==sx_dm_rdb_filesystem_header.id&&!xx_rt_wcscmp(r->name,L"segment_list_block"))s=L"Signed filesystem load-segment block index; -1 terminates the chain";
 else if(id==sx_dm_rdb_filesystem_header.id&&!xx_rt_wcscmp(r->name,L"global_vector"))s=L"Signed BCPL global-vector control word; -1 means no BCPL global vector, 0 requests a private vector";
 else if(id==sx_dm_ndif_resource_type_count.id)s=v==0xffff?L"Empty type list sentinel":L"Encoded resource type count minus one";
 else if(id==sx_dm_ndif_chunk_entry.id&&!xx_rt_wcscmp(r->name,L"data_fork_offset"))s=L"Byte offset relative to the MacBinary data fork";
 else if(id==sx_dm_ndif_chunk_entry.id&&!xx_rt_wcscmp(r->name,L"type"))s=v==0?L"Zero fill":v==2?L"Raw":v==0x83?L"ADC":v==0x80?L"KenCode":v==255?L"Terminator":NULL;
 return !s||xx_data_struct_record_set_comment(r,s);}
const sx_family sx_diskmeta_family={sx_diskmeta_supports,sx_diskmeta_build,sx_diskmeta_layouts,SX_COUNT(sx_diskmeta_layouts),sx_diskmeta_comment};
