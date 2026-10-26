/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The opticalfs schema family: what its family unit (xx_format_schema_opticalfs.c)
 * and its formats' data files share. Formats: ISO 9660 (ECMA-119); UDF (ECMA-167); HFS+. */
#ifndef XX_FORMAT_SCHEMA_OPTICALFS_H
#define XX_FORMAT_SCHEMA_OPTICALFS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxo_iso_directory_record;
extern const sx_layout sxo_iso_path_table_l;
extern const sx_layout sxo_iso_path_table_m;
extern const sx_layout sxo_iso_primary_volume_descriptor;
extern const sx_layout sxo_iso_supplementary_volume_descriptor;
extern const sx_layout sxo_iso_boot_record;
extern const sx_layout sxo_iso_volume_partition_descriptor;
extern const sx_layout sxo_iso_volume_descriptor_terminator;
extern const sx_layout sxo_iso_volume_descriptor_header;
extern const sx_layout sxo_udf_volume_recognition_descriptor;
extern const sx_layout sxo_udf_descriptor_tag;
extern const sx_layout sxo_udf_anchor_volume_descriptor;
extern const sx_layout sxo_udf_primary_volume_descriptor;
extern const sx_layout sxo_udf_partition_descriptor;
extern const sx_layout sxo_udf_logical_volume_descriptor;
extern const sx_layout sxo_udf_partition_map_type1;
extern const sx_layout sxo_udf_partition_map_header;
extern const sx_layout sxo_udf_terminating_descriptor;
extern const sx_layout sxo_udf_file_set_descriptor;
extern const sx_layout sxo_udf_file_entry;
extern const sx_layout sxo_udf_extended_file_entry;
extern const sx_layout sxo_udf_file_identifier_descriptor;
extern const sx_layout sxo_udf_short_allocation_descriptor;
extern const sx_layout sxo_udf_long_allocation_descriptor;
extern const sx_layout sxo_udf_extended_allocation_descriptor;
extern const sx_layout sxo_hfsplus_volume_header;
extern const sx_layout sxo_hfsplus_btree_node_descriptor;
extern const sx_layout sxo_hfsplus_btree_header;
extern const sx_layout sxo_hfsplus_btree_record_offset;
extern const sx_layout sxo_hfsplus_catalog_key;
extern const sx_layout sxo_hfsplus_catalog_folder;
extern const sx_layout sxo_hfsplus_catalog_file;
extern const sx_layout sxo_hfsplus_catalog_thread;
uint32_t sxo_u32(const uint8_t *p);
uint16_t sxo_u16(const uint8_t *p);
bool sxo_can(sx_context *c,int64_t at,uint64_t n);
bool sxo_add(sx_context *c,const sx_layout *l,int64_t at,int64_t n);

/* Per-format walkers, called by the family's build. */
bool sx_iso9660_build(sx_context *c);  /* filesystem/iso9660/xx_iso9660_data.c */
bool sx_udf_build(sx_context *c);  /* filesystem/udf/xx_udf_data.c */
bool sx_hfsplus_build(sx_context *c);  /* filesystem/hfsplus/xx_hfsplus_data.c */

#endif
