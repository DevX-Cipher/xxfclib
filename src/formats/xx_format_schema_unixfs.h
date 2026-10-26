/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The unixfs schema family: what its family unit (xx_format_schema_unixfs.c)
 * and its formats' data files share. Formats: ext2/3/4; SquashFS. */
#ifndef XX_FORMAT_SCHEMA_UNIXFS_H
#define XX_FORMAT_SCHEMA_UNIXFS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxuf_ext_dynamic_superblock;
extern const sx_layout sxuf_ext_original_superblock;
extern const sx_layout sxuf_ext_group_descriptor_64;
extern const sx_layout sxuf_ext_group_descriptor_32;
extern const sx_layout sxuf_ext_original_group_descriptor;
extern const sx_layout sxuf_ext_linux_inode;
extern const sx_layout sxuf_ext_other_os_inode;
extern const sx_layout sxuf_ext_inode_extra_2;
extern const sx_layout sxuf_ext_inode_extra_4;
extern const sx_layout sxuf_ext_inode_extra_8;
extern const sx_layout sxuf_ext_inode_extra_12;
extern const sx_layout sxuf_ext_inode_extra_16;
extern const sx_layout sxuf_ext_inode_extra_20;
extern const sx_layout sxuf_ext_inode_extra_24;
extern const sx_layout sxuf_ext_inode_extra_28;
extern const sx_layout sxuf_ext_inode_extra_32;
extern const sx_layout sxuf_squashfs1_superblock_le;
extern const sx_layout sxuf_squashfs1_superblock_be;
extern const sx_layout sxuf_squashfs2_superblock_le;
extern const sx_layout sxuf_squashfs2_superblock_be;
extern const sx_layout sxuf_squashfs3_superblock_le;
extern const sx_layout sxuf_squashfs3_superblock_be;
extern const sx_layout sxuf_squashfs4_superblock_le;
extern const sx_layout sxuf_squashfs4_superblock_be;
extern const sx_layout sxuf_squashfs_metadata_header_le;
extern const sx_layout sxuf_squashfs_table_index_le;
extern const sx_layout sxuf_squashfs2_fragment_index_le;
extern const sx_layout sxuf_squashfs_identity_le;
extern const sx_layout sxuf_squashfs_xattr_table_le;
extern const sx_layout sxuf_squashfs_metadata_header_be;
extern const sx_layout sxuf_squashfs_table_index_be;
extern const sx_layout sxuf_squashfs2_fragment_index_be;
extern const sx_layout sxuf_squashfs_identity_be;
extern const sx_layout sxuf_squashfs_xattr_table_be;
bool sxuf_span(sx_context *c,uint64_t at,uint64_t n);
bool sxuf_read(sx_context *c,uint64_t at,void *b,size_t n);
uint16_t sxuf_16(const uint8_t *p,bool be);
uint32_t sxuf_32(const uint8_t *p,bool be);
bool sxuf_finish(sx_context *c);

/* Per-format walkers, called by the family's build. */
bool sx_ext_build(sx_context *c);  /* filesystem/ext/xx_ext_data.c */
bool sx_squashfs_build(sx_context *c);  /* filesystem/squashfs/xx_squashfs_data.c */

#endif
