/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The diskmeta schema family: what its family unit (xx_format_schema_diskmeta.c)
 * and its formats' data files share. Formats: VHDX; VHDDynamic; VMDK; vdi; qemu enhanced disk; parallels hdd; MAME CHD; DMG; cloop / geom_uzip; UBI; UBIFS; JFFS2; YAFFS; QNX6; LogFS; Apple Partition Map; Amiga Rigid Disk Block (RDB) hard disk; Apple Disk Copy 6 NDIF image; Encrypted Apple disk image. */
#ifndef XX_FORMAT_SCHEMA_DISKMETA_H
#define XX_FORMAT_SCHEMA_DISKMETA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sx_dm_vhdx_file_identifier;
extern const sx_layout sx_dm_vhdx_header;
extern const sx_layout sx_dm_vhdx_region_table_header;
extern const sx_layout sx_dm_vhdx_region_table_entry;
extern const sx_layout sx_dm_vhdx_metadata_table_header;
extern const sx_layout sx_dm_vhdx_metadata_table_entry;
extern const sx_layout sx_dm_vhdx_file_parameters;
extern const sx_layout sx_dm_vhdx_disk_size;
extern const sx_layout sx_dm_vhdx_logical_sector_size;
extern const sx_layout sx_dm_vhdx_physical_sector_size;
extern const sx_layout sx_dm_vhdx_virtual_disk_id;
extern const sx_layout sx_dm_vhdx_parent_locator;
extern const sx_layout sx_dm_vhdx_parent_locator_entry;
extern const sx_layout sx_dm_vhdx_bat_entry;
extern const sx_layout sx_dm_vhd_footer_511;
extern const sx_layout sx_dm_vhd_footer_512;
extern const sx_layout sx_dm_vhd_dynamic_header;
extern const sx_layout sx_dm_vhd_parent_locator;
extern const sx_layout sx_dm_vhd_bat_entry;
extern const sx_layout sx_dm_vmdk_sparse_header;
extern const sx_layout sx_dm_vmdk_grain_directory_entry;
extern const sx_layout sx_dm_vmdk_grain_table_entry;
extern const sx_layout sx_dm_vmdk_metadata_marker;
extern const sx_layout sx_dm_vdi_preheader;
extern const sx_layout sx_dm_vdi_header_v1;
extern const sx_layout sx_dm_vdi_block_map_entry;
extern const sx_layout sx_dm_qed_header;
extern const sx_layout sx_dm_qed_l1_entry;
extern const sx_layout sx_dm_qed_l2_entry;
extern const sx_layout sx_dm_parallels_header_extended;
extern const sx_layout sx_dm_parallels_header_old;
extern const sx_layout sx_dm_parallels_bat_sector;
extern const sx_layout sx_dm_parallels_bat_cluster;
extern const sx_layout sx_dm_chd_header_v1;
extern const sx_layout sx_dm_chd_header_v2;
extern const sx_layout sx_dm_chd_header_v3;
extern const sx_layout sx_dm_chd_header_v4;
extern const sx_layout sx_dm_chd_header_v5;
extern const sx_layout sx_dm_chd_map_v12;
extern const sx_layout sx_dm_chd_map_v34;
extern const sx_layout sx_dm_chd_map_v5_uncompressed;
extern const sx_layout sx_dm_chd_map_v5_compressed_header;
extern const sx_layout sx_dm_chd_metadata_header;
extern const sx_layout sx_dm_udif_trailer;
extern const sx_layout sx_dm_cloop_header;
extern const sx_layout sx_dm_cloop_block_offset;
extern const sx_layout sx_dm_encrypted_dmg_v2_header;
extern const sx_layout sx_dm_encrypted_dmg_key_pointer;
extern const sx_layout sx_dm_encrypted_dmg_v1_trailer;
extern const sx_layout sx_dm_ubi_erase_counter_header;
extern const sx_layout sx_dm_ubi_volume_identifier_header;
extern const sx_layout sx_dm_ubi_volume_table_record;
extern const sx_layout sx_dm_ubifs_common_header;
extern const sx_layout sx_dm_ubifs_superblock;
extern const sx_layout sx_dm_ubifs_master_node;
extern const sx_layout sx_dm_ubifs_index_header;
extern const sx_layout sx_dm_ubifs_index_branch;
extern const sx_layout sx_dm_ubifs_inode_node;
extern const sx_layout sx_dm_ubifs_directory_entry;
extern const sx_layout sx_dm_ubifs_data_node;
extern const sx_layout sx_dm_ubifs_padding_node;
extern const sx_layout sx_dm_ubifs_commit_start;
extern const sx_layout sx_dm_ubifs_reference_node;
extern const sx_layout sx_dm_jffs2_common_header_le;
extern const sx_layout sx_dm_jffs2_directory_entry_le;
extern const sx_layout sx_dm_jffs2_inode_le;
extern const sx_layout sx_dm_jffs2_xattr_le;
extern const sx_layout sx_dm_jffs2_xref_le;
extern const sx_layout sx_dm_yaffs_object_header_le;
extern const sx_layout sx_dm_qnx6_superblock_header_le;
extern const sx_layout sx_dm_qnx6_root_node_le;
extern const sx_layout sx_dm_jffs2_common_header_be;
extern const sx_layout sx_dm_jffs2_directory_entry_be;
extern const sx_layout sx_dm_jffs2_inode_be;
extern const sx_layout sx_dm_jffs2_xattr_be;
extern const sx_layout sx_dm_jffs2_xref_be;
extern const sx_layout sx_dm_yaffs_object_header_be;
extern const sx_layout sx_dm_qnx6_superblock_header_be;
extern const sx_layout sx_dm_qnx6_root_node_be;
extern const sx_layout sx_dm_logfs_superblock;
extern const sx_layout sx_dm_apm_driver_descriptor_header;
extern const sx_layout sx_dm_apm_driver_descriptor;
extern const sx_layout sx_dm_apm_partition_entry;
extern const sx_layout sx_dm_rdb_rigid_disk_block;
extern const sx_layout sx_dm_rdb_partition_block;
extern const sx_layout sx_dm_rdb_filesystem_header;
extern const sx_layout sx_dm_rdb_load_segment_header;
extern const sx_layout sx_dm_ndif_bcem_header;
extern const sx_layout sx_dm_ndif_chunk_entry;
extern const sx_layout sx_dm_ndif_resource_fork_header;
extern const sx_layout sx_dm_ndif_resource_map_header;
extern const sx_layout sx_dm_ndif_resource_type;
extern const sx_layout sx_dm_ndif_resource_reference;
extern const sx_layout sx_dm_ndif_resource_length;
extern const sx_layout sx_dm_ndif_resource_type_count;
bool sx_dm_span(sx_context*c,uint64_t p,uint64_t n);
bool sx_dm_read(sx_context*c,uint64_t p,void*b,size_t n);
uint32_t sx_dm_u32(const void*b,size_t o,bool be);
uint64_t sx_dm_u64(const void*b,size_t o,bool be);
uint16_t sx_dm_u16(const void*b,size_t o,bool be);
bool sx_dm_add(sx_context*c,const sx_layout*l,uint64_t p,uint64_t z);
bool sx_dm_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t z,uint64_t n);
bool sx_dm_crc(sx_context*c,uint64_t p,uint64_t n,uint32_t want,bool castagnoli,bool complement,bool zero4);

/* Per-format walkers, called by the family's build. */
bool sx_vhdx_build(sx_context *c);  /* filesystem/vhdx/xx_vhdx_data.c */
bool sx_vhddynamic_build(sx_context *c);  /* filesystem/vhddynamic/xx_vhddynamic_data.c */
bool sx_vmdk_build(sx_context *c);  /* filesystem/vmdk/xx_vmdk_data.c */
bool sx_vdi_build(sx_context *c);  /* filesystem/vdi/xx_vdi_data.c */
bool sx_qemu_enhanced_disk_build(sx_context *c);  /* filesystem/qemu_enhanced_disk/xx_qemu_enhanced_disk_data.c */
bool sx_parallels_hdd_build(sx_context *c);  /* filesystem/parallels_hdd/xx_parallels_hdd_data.c */
bool sx_chd_build(sx_context *c);  /* filesystem/chd/xx_chd_data.c */
bool sx_dmg_build(sx_context *c);  /* filesystem/dmg/xx_dmg_data.c */
bool sx_cloop_build(sx_context *c);  /* filesystem/cloop/xx_cloop_data.c */
bool sx_ubi_build(sx_context *c);  /* filesystem/ubi/xx_ubi_data.c */
bool sx_ubifs_build(sx_context *c);  /* filesystem/ubifs/xx_ubifs_data.c */
bool sx_jffs2_build(sx_context *c);  /* filesystem/jffs2/xx_jffs2_data.c */
bool sx_yaffs_build(sx_context *c);  /* filesystem/yaffs/xx_yaffs_data.c */
bool sx_qnx6_build(sx_context *c);  /* filesystem/qnx6/xx_qnx6_data.c */
bool sx_logfs_build(sx_context *c);  /* filesystem/logfs/xx_logfs_data.c */
bool sx_apm_build(sx_context *c);  /* filesystem/apm/xx_apm_data.c */
bool sx_rdb_build(sx_context *c);  /* filesystem/rdb/xx_rdb_data.c */
bool sx_apple_disk_copy_6_ndif_image_build(sx_context *c);  /* filesystem/apple_disk_copy_6_ndif_image/xx_apple_disk_copy_6_ndif_image_data.c */
bool sx_encrypted_apple_disk_image_build(sx_context *c);  /* filesystem/encrypted_apple_disk_image/xx_encrypted_apple_disk_image_data.c */

#endif
