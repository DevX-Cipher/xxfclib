/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The cowfs schema family: what its family unit (xx_format_schema_cowfs.c)
 * and its formats' data files share. Formats: APFS; Btrfs. */
#ifndef XX_FORMAT_SCHEMA_COWFS_H
#define XX_FORMAT_SCHEMA_COWFS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxc_apfs_object_header;
extern const sx_layout sxc_apfs_container_header;
extern const sx_layout sxc_apfs_file_system_oid;
extern const sx_layout sxc_apfs_container_counter;
extern const sx_layout sxc_apfs_container_tail;
extern const sx_layout sxc_apfs_checkpoint_map;
extern const sx_layout sxc_apfs_checkpoint_mapping;
extern const sx_layout sxc_apfs_object_map;
extern const sx_layout sxc_apfs_btree_node;
extern const sx_layout sxc_apfs_btree_info;
extern const sx_layout sxc_apfs_btree_kvoff;
extern const sx_layout sxc_apfs_btree_kvloc;
extern const sx_layout sxc_apfs_omap_key;
extern const sx_layout sxc_apfs_omap_value;
extern const sx_layout sxc_apfs_btree_child;
extern const sx_layout sxc_apfs_volume_header;
extern const sx_layout sxc_apfs_modified_by;
extern const sx_layout sxc_apfs_volume_name;
extern const sx_layout sxc_apfs_volume_tail;
extern const sx_layout sxc_btrfs_superblock_header;
extern const sx_layout sxc_btrfs_device_item;
extern const sx_layout sxc_btrfs_superblock_tail;
extern const sx_layout sxc_btrfs_root_backup;
extern const sx_layout sxc_btrfs_superblock_padding;
extern const sx_layout sxc_btrfs_disk_key;
extern const sx_layout sxc_btrfs_chunk;
extern const sx_layout sxc_btrfs_stripe;
extern const sx_layout sxc_btrfs_tree_header;
extern const sx_layout sxc_btrfs_leaf_item;
extern const sx_layout sxc_btrfs_key_pointer;
uint16_t sxc_u16(const uint8_t *p);
uint32_t sxc_u32(const uint8_t *p);
uint64_t sxc_u64(const uint8_t *p);
bool sxc_can(sx_context *c,int64_t at,uint64_t n);
bool sxc_add(sx_context *c,const sx_layout *l,int64_t at,int64_t n);
bool sxc_table(sx_context *c,const sx_layout *l,int64_t at,int64_t entry,uint64_t count);

/* Per-format walkers, called by the family's build. */
bool sx_apfs_build(sx_context *c);  /* filesystem/apfs/xx_apfs_data.c */
bool sx_btrfs_build(sx_context *c);  /* filesystem/btrfs/xx_btrfs_data.c */

#endif
