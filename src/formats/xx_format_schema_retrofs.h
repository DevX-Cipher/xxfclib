/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The retrofs schema family: what its family unit (xx_format_schema_retrofs.c)
 * and its formats' data files share. Formats: AODOS; ADF; PRODOS; APPLE PASCAL; MFS; HFS; ADFS; ACORN DFS; ATARI DOS2; TI99 DSK; OS9 RBF; APPLE DOS33; APPLE DOS32; APPLE DOS33 32; CBM D64; CBM D71; CBM D81; CBM D67; CBM D8X; CBM D90. */
#ifndef XX_FORMAT_SCHEMA_RETROFS_H
#define XX_FORMAT_SCHEMA_RETROFS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxrfs_aodos_directory_entry;
extern const sx_layout sxrfs_prodos_directory_links;
extern const sx_layout sxrfs_prodos_volume_header;
extern const sx_layout sxrfs_prodos_subdirectory_header;
extern const sx_layout sxrfs_prodos_file_entry;
extern const sx_layout sxrfs_prodos_fork_descriptor;
extern const sx_layout sxrfs_prodos_index_low;
extern const sx_layout sxrfs_prodos_index_high;
extern const sx_layout sxrfs_pascal_volume_header;
extern const sx_layout sxrfs_pascal_file_entry;
extern const sx_layout sxrfs_mfs_master_directory;
extern const sx_layout sxrfs_mfs_allocation_pair;
extern const sx_layout sxrfs_mfs_file_entry;
extern const sx_layout sxrfs_adfs_map0;
extern const sx_layout sxrfs_adfs_map1;
extern const sx_layout sxrfs_adfs_directory_start;
extern const sx_layout sxrfs_adfs_directory_entry;
extern const sx_layout sxrfs_acorn_dfs_title;
extern const sx_layout sxrfs_acorn_dfs_name;
extern const sx_layout sxrfs_acorn_dfs_catalog_header;
extern const sx_layout sxrfs_acorn_dfs_file_metadata;
extern const sx_layout sxrfs_atari_atr_header;
extern const sx_layout sxrfs_atari_dos2_vtoc;
extern const sx_layout sxrfs_atari_dos2_directory_entry;
extern const sx_layout sxrfs_atari_dos2_sector_trailer;
extern const sx_layout sxrfs_ti99_vib;
extern const sx_layout sxrfs_ti99_directory_pointer;
extern const sx_layout sxrfs_ti99_file_descriptor;
extern const sx_layout sxrfs_ti99_cluster;
extern const sx_layout sxrfs_os9_disk_descriptor;
extern const sx_layout sxrfs_os9_path_options;
extern const sx_layout sxrfs_os9_file_descriptor;
extern const sx_layout sxrfs_os9_segment;
extern const sx_layout sxrfs_os9_directory_entry;
extern const sx_layout sxrfs_adf_boot_header;
extern const sx_layout sxrfs_adf_root_block;
extern const sx_layout sxrfs_adf_block_prefix;
extern const sx_layout sxrfs_adf_block_pointer;
extern const sx_layout sxrfs_adf_classic_entry_tail;
extern const sx_layout sxrfs_adf_bitmap_block;
extern const sx_layout sxrfs_hfs_master_directory;
extern const sx_layout sxrfs_hfs_btree_node;
extern const sx_layout sxrfs_hfs_btree_header;
extern const sx_layout sxrfs_hfs_node_record_offset;
extern const sx_layout sxrfs_hfs_catalog_key_prefix;
extern const sx_layout sxrfs_hfs_extents_key;
extern const sx_layout sxrfs_hfs_extent;
extern const sx_layout sxrfs_hfs_btree_child;
extern const sx_layout sxrfs_hfs_catalog_folder;
extern const sx_layout sxrfs_hfs_catalog_file;
extern const sx_layout sxrfs_hfs_catalog_thread;
extern const sx_layout sxrfs_atari_dos25_extended_vtoc;
extern const sx_layout sxrfs_adfs_directory_tail;
bool sxrfs_span(sx_context*c,uint64_t p,uint64_t n);
bool sxrfs_read(sx_context*c,uint64_t p,void*b,size_t n);
uint16_t sxrfs16(const uint8_t*b,unsigned o);
uint32_t sxrfs32(const uint8_t*b,unsigned o);
bool sxrfs_pow(uint64_t v);
bool sxrfs_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);
uint32_t sxrfs24(const uint8_t*b,bool be);
bool sxrfs_apple_read(sx_context*c,uint64_t p,void*out,size_t n,bool dos);
bool sxrfs_apple_put(sx_context*c,const sx_layout*l,uint64_t p,bool dos);
bool sxrfs_apple_dos(sx_context*c);
bool sxrfs_cbm(sx_context*c);

/* Per-format walkers, called by the family's build. */
bool sx_aodos_build(sx_context *c);  /* filesystem/aodos/xx_aodos_data.c */
bool sx_adf_build(sx_context *c);  /* filesystem/adf/xx_adf_data.c */
bool sx_prodos_build(sx_context *c);  /* filesystem/prodos/xx_prodos_data.c */
bool sx_apple_pascal_build(sx_context *c);  /* filesystem/apple_pascal/xx_apple_pascal_data.c */
bool sx_mfs_build(sx_context *c);  /* filesystem/mfs/xx_mfs_data.c */
bool sx_hfs_build(sx_context *c);  /* filesystem/hfs/xx_hfs_data.c */
bool sx_acorn_adfs_build(sx_context *c);  /* filesystem/acorn_adfs/xx_acorn_adfs_data.c */
bool sx_acorn_dfs_build(sx_context *c);  /* filesystem/acorn_dfs/xx_acorn_dfs_data.c */
bool sx_atari_dos2_build(sx_context *c);  /* filesystem/atari_dos2/xx_atari_dos2_data.c */
bool sx_ti99_dsk_build(sx_context *c);  /* filesystem/ti99_dsk/xx_ti99_dsk_data.c */
bool sx_os9_rbf_build(sx_context *c);  /* filesystem/os9_rbf/xx_os9_rbf_data.c */
bool sx_apple_dos33_build(sx_context *c);  /* filesystem/apple_dos33/xx_apple_dos33_data.c */
bool sx_apple_dos32_build(sx_context *c);  /* filesystem/apple_dos32/xx_apple_dos32_data.c */
bool sx_apple_dos33_32_build(sx_context *c);  /* filesystem/apple_dos33_32/xx_apple_dos33_32_data.c */
bool sx_cbm_d64_build(sx_context *c);  /* filesystem/cbm_d64/xx_cbm_d64_data.c */
bool sx_cbm_d71_build(sx_context *c);  /* filesystem/cbm_d71/xx_cbm_d71_data.c */
bool sx_cbm_d81_build(sx_context *c);  /* filesystem/cbm_d81/xx_cbm_d81_data.c */
bool sx_cbm_d67_build(sx_context *c);  /* filesystem/cbm_d67/xx_cbm_d67_data.c */
bool sx_cbm_d8x_build(sx_context *c);  /* filesystem/cbm_d8x/xx_cbm_d8x_data.c */
bool sx_cbm_d90_build(sx_context *c);  /* filesystem/cbm_d90/xx_cbm_d90_data.c */

#endif
