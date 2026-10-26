/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The classicfs schema family: what its family unit (xx_format_schema_classicfs.c)
 * and its formats' data files share. Formats: minix; QNX4; SGI_EFS; RT11_FS; HP_LIF; ECMA67_FS; LOCUS_FS; AMIGA_PFS; HPOFS; ODS2_FS; UNICOS_FS. */
#ifndef XX_FORMAT_SCHEMA_CLASSICFS_H
#define XX_FORMAT_SCHEMA_CLASSICFS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Follow block pointers only to disclose physical directory records. The
 * pointer blocks themselves are genuine fixed-width metadata tables. */
typedef struct sxcf_map {sx_context*c;uint64_t blocks,unit,pointer_unit,left;unsigned order,pointer,kind,width,visits;uint64_t ancestors[4];} sxcf_map;
typedef struct sxcf_extent_map{uint64_t logical,physical,bytes;}sxcf_extent_map;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxcf_minix1_superblock_le;
extern const sx_layout sxcf_minix1_superblock_be;
extern const sx_layout sxcf_minix2_superblock_le;
extern const sx_layout sxcf_minix2_superblock_be;
extern const sx_layout sxcf_minix3_superblock_le;
extern const sx_layout sxcf_minix3_superblock_be;
extern const sx_layout sxcf_minix1_inode_le;
extern const sx_layout sxcf_minix1_inode_be;
extern const sx_layout sxcf_minix23_inode_le;
extern const sx_layout sxcf_minix23_inode_be;
extern const sx_layout sxcf_classic_block_number32_be;
extern const sx_layout sxcf_qnx4_inode;
extern const sx_layout sxcf_qnx4_link;
extern const sx_layout sxcf_qnx4_extent_block_header;
extern const sx_layout sxcf_qnx4_extent;
extern const sx_layout sxcf_qnx4_extent_block_tail;
extern const sx_layout sxcf_efs_superblock;
extern const sx_layout sxcf_efs_inode_header;
extern const sx_layout sxcf_efs_extent;
extern const sx_layout sxcf_rt11_home_block;
extern const sx_layout sxcf_rt11_directory_segment;
extern const sx_layout sxcf_rt11_directory_entry;
extern const sx_layout sxcf_hp_lif_volume_header;
extern const sx_layout sxcf_hp_lif_directory_entry;
extern const sx_layout sxcf_ecma67_volume_label;
extern const sx_layout sxcf_ecma67_error_map_label;
extern const sx_layout sxcf_ecma67_file_label;
extern const sx_layout sxcf_locus_superblock_prefix_le;
extern const sx_layout sxcf_locus_superblock_prefix_be;
extern const sx_layout sxcf_locus_inode_le;
extern const sx_layout sxcf_locus_inode_be;
extern const sx_layout sxcf_locus_inode_small_le;
extern const sx_layout sxcf_locus_inode_small_be;
extern const sx_layout sxcf_locus_directory_header_le;
extern const sx_layout sxcf_locus_directory_header_be;
extern const sx_layout sxcf_pfs_root_block;
extern const sx_layout sxcf_pfs_root_small_indexes;
extern const sx_layout sxcf_pfs_root_large_indexes;
extern const sx_layout sxcf_pfs_index_header;
extern const sx_layout sxcf_pfs_anode_header;
extern const sx_layout sxcf_pfs_anode;
extern const sx_layout sxcf_pfs_directory_header;
extern const sx_layout sxcf_pfs_directory_entry;
extern const sx_layout sxcf_pfs_extension;
extern const sx_layout sxcf_hpofs_boot_sector;
extern const sx_layout sxcf_hpofs_media_information;
extern const sx_layout sxcf_hpofs_subfile_header;
extern const sx_layout sxcf_hpofs_extent;
extern const sx_layout sxcf_hpofs_directory_node;
extern const sx_layout sxcf_hpofs_directory_record_prefix;
extern const sx_layout sxcf_hpofs_directory_record;
extern const sx_layout sxcf_ods_home_block;
extern const sx_layout sxcf_ods_file_header;
extern const sx_layout sxcf_ods_file_checksum;
extern const sx_layout sxcf_ods_retrieval_pointer0;
extern const sx_layout sxcf_ods_retrieval_pointer1;
extern const sx_layout sxcf_ods_retrieval_pointer2;
extern const sx_layout sxcf_ods_retrieval_pointer3;
extern const sx_layout sxcf_ods_directory_header;
extern const sx_layout sxcf_ods_directory_version;
extern const sx_layout sxcf_unicos_superblock_prefix;
extern const sx_layout sxcf_unicos_partition;
extern const sx_layout sxcf_unicos_superblock_tail;
extern const sx_layout sxcf_unicos_inode_prefix;
extern const sx_layout sxcf_unicos_extent;
extern const sx_layout sxcf_unicos_inode_tail;
extern const sx_layout sxcf_unicos_directory_header;
extern const sx_layout sxcf_hpofs_volume_information;
bool sxcf_span(sx_context*c,uint64_t p,uint64_t n);
bool sxcf_read(sx_context*c,uint64_t p,void*b,size_t n);
uint16_t sxcf16(const uint8_t*b,unsigned o);
uint32_t sxcf32(const uint8_t*b,unsigned o);
uint64_t sxcf64(const uint8_t*b,unsigned o);
uint32_t sxcf24(const uint8_t*b,unsigned o);
bool sxcf_pow(uint64_t v);
bool sxcf_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);
bool sxcf_dir(sx_context*c,uint64_t p,uint64_t n,unsigned kind,unsigned o,unsigned width);
bool sxcf_pointer(sxcf_map*g,uint64_t nr,unsigned depth);

/* Per-format walkers, called by the family's build. */
bool sx_minix_build(sx_context *c);  /* filesystem/minix/xx_minix_data.c */
bool sx_qnx4_build(sx_context *c);  /* filesystem/qnx4/xx_qnx4_data.c */
bool sx_sgi_efs_build(sx_context *c);  /* filesystem/sgi_efs/xx_sgi_efs_data.c */
bool sx_rt11_fs_build(sx_context *c);  /* filesystem/rt11_fs/xx_rt11_fs_data.c */
bool sx_hp_lif_build(sx_context *c);  /* filesystem/hp_lif/xx_hp_lif_data.c */
bool sx_ecma67_fs_build(sx_context *c);  /* filesystem/ecma67_fs/xx_ecma67_fs_data.c */
bool sx_locus_fs_build(sx_context *c);  /* filesystem/locus_fs/xx_locus_fs_data.c */
bool sx_amiga_pfs_build(sx_context *c);  /* filesystem/amiga_pfs/xx_amiga_pfs_data.c */
bool sx_hpofs_build(sx_context *c);  /* filesystem/hpofs/xx_hpofs_data.c */
bool sx_ods2_fs_build(sx_context *c);  /* filesystem/ods2_fs/xx_ods2_fs_data.c */
bool sx_unicos_fs_build(sx_context *c);  /* filesystem/unicos_fs/xx_unicos_fs_data.c */

#endif
