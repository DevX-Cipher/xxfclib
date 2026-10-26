/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The modernfs schema family: what its family unit (xx_format_schema_modernfs.c)
 * and its formats' data files share. Formats: F2FS; JFS; NILFS2; REISERFS; AMIGA SFS; XFS; ZFS; GFS2; FOSSIL FS; HAMMER FS; REFS; VXFS; VMFS; HPFS; EROFS; CDI FS; OPERA FS. */
#ifndef XX_FORMAT_SCHEMA_MODERNFS_H
#define XX_FORMAT_SCHEMA_MODERNFS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Optional metadata graph work is separately bounded from volume geometry. */
typedef struct sxmf_task{uint64_t p;unsigned kind,depth;}sxmf_task;
typedef struct sxmf_queue{sxmf_task items[4096];size_t count,index;}sxmf_queue;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxmf_refs_volume_header;
extern const sx_layout sxmf_fossil_header;
extern const sx_layout sxmf_fossil_superblock;
extern const sx_layout sxmf_fossil_label;
extern const sx_layout sxmf_jfs_superblock;
extern const sx_layout sxmf_nilfs2_superblock;
extern const sx_layout sxmf_nilfs2_inode;
extern const sx_layout sxmf_nilfs2_super_root_header;
extern const sx_layout sxmf_nilfs2_segment_summary;
extern const sx_layout sxmf_nilfs2_file_info;
extern const sx_layout sxmf_f2fs_superblock_prefix;
extern const sx_layout sxmf_f2fs_device;
extern const sx_layout sxmf_f2fs_superblock_tail;
extern const sx_layout sxmf_f2fs_checkpoint_header;
extern const sx_layout sxmf_f2fs_nat_entry;
extern const sx_layout sxmf_f2fs_node_footer;
extern const sx_layout sxmf_reiser35_superblock;
extern const sx_layout sxmf_reiser36_superblock;
extern const sx_layout sxmf_reiser_block_header;
extern const sx_layout sxmf_reiser_item_header;
extern const sx_layout sxmf_reiser_child;
extern const sx_layout sxmf_sfs_root_block;
extern const sx_layout sxmf_sfs_object_container;
extern const sx_layout sxmf_sfs_btree_header;
extern const sx_layout sxmf_sfs_extent16;
extern const sx_layout sxmf_sfs_extent32;
extern const sx_layout sxmf_sfs_btree_index;
extern const sx_layout sxmf_opera_disc_label;
extern const sx_layout sxmf_opera_directory_header;
extern const sx_layout sxmf_opera_directory_record;
extern const sx_layout sxmf_opera_avatar;
extern const sx_layout sxmf_xfs4_superblock;
extern const sx_layout sxmf_xfs5_superblock;
extern const sx_layout sxmf_xfs4_agf;
extern const sx_layout sxmf_xfs5_agf;
extern const sx_layout sxmf_xfs4_agi;
extern const sx_layout sxmf_xfs5_agi;
extern const sx_layout sxmf_xfs_inode_v2;
extern const sx_layout sxmf_xfs_inode_v3;
extern const sx_layout sxmf_gfs2_superblock;
extern const sx_layout sxmf_gfs2_inode;
extern const sx_layout sxmf_gfs2_directory_entry;
extern const sx_layout sxmf_gfs2_leaf;
extern const sx_layout sxmf_hpfs_superblock;
extern const sx_layout sxmf_hpfs_spareblock;
extern const sx_layout sxmf_hpfs_fnode_prefix;
extern const sx_layout sxmf_hpfs_btree_header;
extern const sx_layout sxmf_hpfs_extent;
extern const sx_layout sxmf_hpfs_btree_child;
extern const sx_layout sxmf_hpfs_fnode_tail;
extern const sx_layout sxmf_hpfs_anode_header;
extern const sx_layout sxmf_hpfs_dnode_header;
extern const sx_layout sxmf_hpfs_directory_entry;
extern const sx_layout sxmf_hpfs_down_pointer;
extern const sx_layout sxmf_hammer_volume_header_le;
extern const sx_layout sxmf_hammer_volume_header_be;
extern const sx_layout sxmf_hammer_blockmap_le;
extern const sx_layout sxmf_hammer_blockmap_be;
extern const sx_layout sxmf_hammer_undo_pointer_le;
extern const sx_layout sxmf_hammer_undo_pointer_be;
extern const sx_layout sxmf_zfs_embedded_checksum_le;
extern const sx_layout sxmf_zfs_embedded_checksum_be;
extern const sx_layout sxmf_zfs_block_pointer_le;
extern const sx_layout sxmf_zfs_block_pointer_be;
extern const sx_layout sxmf_zfs_uberblock_prefix_le;
extern const sx_layout sxmf_zfs_uberblock_prefix_be;
extern const sx_layout sxmf_zfs_uberblock_tail_le;
extern const sx_layout sxmf_zfs_uberblock_tail_be;
extern const sx_layout sxmf_erofs_superblock;
extern const sx_layout sxmf_erofs_inode_compact;
extern const sx_layout sxmf_erofs_inode_extended;
extern const sx_layout sxmf_erofs_directory_entry;
extern const sx_layout sxmf_erofs_device_slot;
extern const sx_layout sxmf_erofs_chunk_block;
extern const sx_layout sxmf_vxfs1_superblock_le;
extern const sx_layout sxmf_vxfs1_superblock_be;
extern const sx_layout sxmf_vxfs2_superblock_le;
extern const sx_layout sxmf_vxfs2_superblock_be;
extern const sx_layout sxmf_vmfs_volume_header;
extern const sx_layout sxmf_vmfs35_lvm_header;
extern const sx_layout sxmf_vmfs35_filesystem_header;
extern const sx_layout sxmf_vmfs35_bitmap_header;
extern const sx_layout sxmf_vmfs35_inode_data;
extern const sx_layout sxmf_vmfs35_directory_entry;
extern const sx_layout sxmf_vmfs35_block_id;
extern const sx_layout sxmf_reiser4_master;
extern const sx_layout sxmf_reiser4_format40_superblock;
extern const sx_layout sxmf_reiser4_node40_header;
extern const sx_layout sxmf_reiser4_item_header_large;
extern const sx_layout sxmf_reiser4_child;
extern const sx_layout sxmf_reiser4_extent;
extern const sx_layout sxmf_hammer_node_header_le;
extern const sx_layout sxmf_hammer_node_header_be;
extern const sx_layout sxmf_hammer_internal_record_le;
extern const sx_layout sxmf_hammer_internal_record_be;
extern const sx_layout sxmf_hammer_leaf_record_le;
extern const sx_layout sxmf_hammer_leaf_record_be;
extern const sx_layout sxmf_hammer_inode_le;
extern const sx_layout sxmf_hammer_inode_be;
extern const sx_layout sxmf_hammer_directory_entry_le;
extern const sx_layout sxmf_hammer_directory_entry_be;
extern const sx_layout sxmf_cdi_volume_descriptor;
extern const sx_layout sxmf_cdi_terminator;
extern const sx_layout sxmf_cdi_path_entry;
extern const sx_layout sxmf_cdi_directory_entry;
extern const sx_layout sxmf_cdi_directory_attributes;
extern const sx_layout sxmf_cdi_mode2_sector_header;
extern const sx_layout sxmf_cdi_form1_edc;
extern const sx_layout sxmf_vmfs35_metadata_header;
extern const sx_layout sxmf_sfs_file_object;
extern const sx_layout sxmf_sfs_directory_object;
bool sxmf_span(sx_context*c,uint64_t p,uint64_t n);
bool sxmf_read(sx_context*c,uint64_t p,void*b,size_t n);
uint16_t sxmf16(const uint8_t*b,unsigned o);
uint32_t sxmf32(const uint8_t*b,unsigned o);
uint64_t sxmf64(const uint8_t*b,unsigned o);
bool sxmf_pow(uint64_t v);
bool sxmf_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);
void sxmf_queue_add(sxmf_queue*q,uint64_t p,unsigned kind,unsigned depth);

/* Per-format walkers, called by the family's build. */
bool sx_f2fs_build(sx_context *c);  /* filesystem/f2fs/xx_f2fs_data.c */
bool sx_jfs_build(sx_context *c);  /* filesystem/jfs/xx_jfs_data.c */
bool sx_nilfs2_build(sx_context *c);  /* filesystem/nilfs2/xx_nilfs2_data.c */
bool sx_reiserfs_build(sx_context *c);  /* filesystem/reiserfs/xx_reiserfs_data.c */
bool sx_amiga_sfs_build(sx_context *c);  /* filesystem/amiga_sfs/xx_amiga_sfs_data.c */
bool sx_xfs_build(sx_context *c);  /* filesystem/xfs/xx_xfs_data.c */
bool sx_zfs_build(sx_context *c);  /* filesystem/zfs/xx_zfs_data.c */
bool sx_gfs2_build(sx_context *c);  /* filesystem/gfs2/xx_gfs2_data.c */
bool sx_fossil_fs_build(sx_context *c);  /* filesystem/fossil_fs/xx_fossil_fs_data.c */
bool sx_hammer_fs_build(sx_context *c);  /* filesystem/hammer_fs/xx_hammer_fs_data.c */
bool sx_refs_build(sx_context *c);  /* filesystem/refs/xx_refs_data.c */
bool sx_vxfs_build(sx_context *c);  /* filesystem/vxfs/xx_vxfs_data.c */
bool sx_vmfs_build(sx_context *c);  /* filesystem/vmfs/xx_vmfs_data.c */
bool sx_hpfs_build(sx_context *c);  /* filesystem/hpfs/xx_hpfs_data.c */
bool sx_erofs_build(sx_context *c);  /* filesystem/erofs/xx_erofs_data.c */
bool sx_cdi_fs_build(sx_context *c);  /* filesystem/cdi_fs/xx_cdi_fs_data.c */
bool sx_opera_fs_build(sx_context *c);  /* filesystem/opera_fs/xx_opera_fs_data.c */

#endif
