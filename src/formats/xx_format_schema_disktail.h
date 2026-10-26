/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The disktail schema family: what its family unit (xx_format_schema_disktail.c)
 * and its formats' data files share. Formats: APPLE_RDOS; AMDOS; OZDOS; UNIDOS; CFFA; APPLE_DOS_HYBRID; DOS_MASTER; MAC_TS; PASCAL_PROFILE_MANAGER; LISA_FS; ACT_APRICOT_PC_XI_RAW; BONDWELL_2_DISK; ACORN_ATOM_DISK; CASIO_FZ_1_DISK; CPM; XVA; MGT; RAWCD; SOLAR_FS; PLAN9_PARTITIONS; HXC_XML_DISK_LAYOUT. */
#ifndef XX_FORMAT_SCHEMA_DISKTAIL_H
#define XX_FORMAT_SCHEMA_DISKTAIL_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* A view maps logical child coordinates to the original physical device.
 * It never changes the borrowed format or record owner. OzDOS splits each
 * 512-byte physical sector into independent 256-byte logical sectors. */
typedef struct sxdt_view {sx_context*c;uint64_t base,size;unsigned split;} sxdt_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxdt_rdos_catalog_entry;
extern const sx_layout sxdt_mac_ts_driver_descriptor;
extern const sx_layout sxdt_mac_ts_map_header;
extern const sx_layout sxdt_mac_ts_partition;
extern const sx_layout sxdt_ppm_header;
extern const sx_layout sxdt_ppm_volume_entry;
extern const sx_layout sxdt_ppm_volume_description;
extern const sx_layout sxdt_ppm_cached_volume_name;
extern const sx_layout sxdt_apricot_label_prefix;
extern const sx_layout sxdt_apricot_bpb;
extern const sx_layout sxdt_cpm_extent8;
extern const sx_layout sxdt_cpm_extent16;
extern const sx_layout sxdt_atom_catalog_name_header;
extern const sx_layout sxdt_atom_catalog_info_header;
extern const sx_layout sxdt_atom_catalog_name;
extern const sx_layout sxdt_atom_catalog_info;
extern const sx_layout sxdt_casio_disk_header;
extern const sx_layout sxdt_casio_allocation_byte;
extern const sx_layout sxdt_casio_directory_entry;
extern const sx_layout sxdt_casio_file_extent;
extern const sx_layout sxdt_casio_file_counts;
extern const sx_layout sxdt_rawcd_sector_header;
extern const sx_layout sxdt_rawcd_xa_subheader;
extern const sx_layout sxdt_rawcd_edc;
extern const sx_layout sxdt_mgt_directory_core;
extern const sx_layout sxdt_mgt_sector_link;
extern const sx_layout sxdt_cpm3_volume_label;
extern const sx_layout sxdt_cpm3_timestamp_status;
extern const sx_layout sxdt_cpm3_timestamp_record;
extern const sx_layout sxdt_cpm3_timestamp_tail;
extern const sx_layout sxdt_cpm_deleted_entry;
extern const sx_layout sxdt_mgt_compatibility_tail;
extern const sx_layout sxdt_mgt_disk_label;
extern const sx_layout sxdt_mgt_sam_tail;
extern const sx_layout sxdt_mgt_dos_file_header;
extern const sx_layout sxdt_xva_tar_v7;
extern const sx_layout sxdt_xva_tar_ustar;
extern const sx_layout sxdt_xva_sha1_text;
extern const sx_layout sxdt_xva_xxhash_text;
extern const sx_layout sxdt_plan9_keyword;
extern const sx_layout sxdt_plan9_name;
extern const sx_layout sxdt_plan9_first_sector;
extern const sx_layout sxdt_plan9_end_sector;
extern const sx_layout sxdt_mgt_legacy_tail;
extern const sx_layout sxdt_solar_volume_identity;
extern const sx_layout sxdt_lisa_dc42_header;
extern const sx_layout sxdt_lisa_microfloppy_loader;
extern const sx_layout sxdt_lisa_microfloppy_tag;
extern const sx_layout sxdt_lisa_mddf;
extern const sx_layout sxdt_lisa_sfile_entry;
extern const sx_layout sxdt_lisa_hint_entry;
extern const sx_layout sxdt_lisa_filemap_header;
extern const sx_layout sxdt_lisa_filemap_extent;
extern const sx_layout sxdt_lisa_flat_catalog_entry;
extern const sx_layout sxdt_lisa_btree_key;
extern const sx_layout sxdt_lisa_btree_directory;
extern const sx_layout sxdt_lisa_btree_object;
extern const sx_layout sxdt_lisa_btree_thread;
extern const sx_layout sxdt_lisa_btree_footer;
extern const sx_layout sxdt_lisa_btree_offset;
extern const sx_layout sxdt_lisa_btree_child;
extern const sx_layout sxdt_apricot_fat12_pair;
extern const sx_layout sxdt_apricot_directory_entry;
bool sxdt_span(sx_context*c,uint64_t p,uint64_t n);
bool sxdt_read(sx_context*c,uint64_t p,void*b,size_t n);
uint16_t sxdt16(const uint8_t*b,unsigned o);
uint32_t sxdt32(const uint8_t*b,unsigned o);
bool sxdt_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);
bool sxdt_value(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);
bool sxdt_finish(sx_context*c);
bool sxdt_av_pascal(sxdt_view*c);
bool sxdt_av_pd_header(const uint8_t*h);
bool sxdt_av_prodos(sxdt_view*c);
bool sxdt_av_apple_dos(sxdt_view*c,unsigned spt);
bool sxdt_av_hfs(sxdt_view*c);
bool sxdt_dos800(sx_context*c);
bool sxdt_child(sx_context*c,uint64_t p,uint64_t n);
bool sxdt_space(uint8_t b);
bool sxdt_eq(const uint8_t*b,size_t n,const char*s);
bool sxdt_xml(sx_context*c,uint64_t base,uint64_t length,bool hxc);

/* Per-format walkers, called by the family's build. */
bool sx_apple_rdos_build(sx_context *c);  /* filesystem/apple_rdos/xx_apple_rdos_data.c */
bool sx_amdos_build(sx_context *c);  /* filesystem/amdos/xx_amdos_data.c */
bool sx_ozdos_build(sx_context *c);  /* filesystem/ozdos/xx_ozdos_data.c */
bool sx_unidos_build(sx_context *c);  /* filesystem/unidos/xx_unidos_data.c */
bool sx_cffa_build(sx_context *c);  /* filesystem/cffa/xx_cffa_data.c */
bool sx_apple_dos_hybrid_build(sx_context *c);  /* filesystem/apple_dos_hybrid/xx_apple_dos_hybrid_data.c */
bool sx_dos_master_build(sx_context *c);  /* filesystem/dos_master/xx_dos_master_data.c */
bool sx_mac_ts_build(sx_context *c);  /* filesystem/mac_ts/xx_mac_ts_data.c */
bool sx_pascal_profile_manager_build(sx_context *c);  /* filesystem/pascal_profile_manager/xx_pascal_profile_manager_data.c */
bool sx_lisa_fs_build(sx_context *c);  /* filesystem/lisa_fs/xx_lisa_fs_data.c */
bool sx_act_apricot_pc_xi_raw_build(sx_context *c);  /* filesystem/act_apricot_pc_xi_raw/xx_act_apricot_pc_xi_raw_data.c */
bool sx_bondwell_2_disk_build(sx_context *c);  /* filesystem/bondwell_2_disk/xx_bondwell_2_disk_data.c */
bool sx_acorn_atom_disk_build(sx_context *c);  /* filesystem/acorn_atom_disk/xx_acorn_atom_disk_data.c */
bool sx_casio_fz_1_disk_build(sx_context *c);  /* filesystem/casio_fz_1_disk/xx_casio_fz_1_disk_data.c */
bool sx_cpm_build(sx_context *c);  /* filesystem/cpm/xx_cpm_data.c */
bool sx_xva_build(sx_context *c);  /* filesystem/xva/xx_xva_data.c */
bool sx_mgt_build(sx_context *c);  /* filesystem/mgt/xx_mgt_data.c */
bool sx_rawcd_build(sx_context *c);  /* filesystem/rawcd/xx_rawcd_data.c */
bool sx_solar_fs_build(sx_context *c);  /* filesystem/solar_fs/xx_solar_fs_data.c */
bool sx_plan9_partitions_build(sx_context *c);  /* filesystem/plan9_partitions/xx_plan9_partitions_data.c */
bool sx_hxc_xml_disk_layout_build(sx_context *c);  /* filesystem/hxc_xml_disk_layout/xx_hxc_xml_disk_layout_data.c */

#endif
