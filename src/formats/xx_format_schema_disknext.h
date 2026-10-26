/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The disknext schema family: what its family unit (xx_format_schema_disknext.c)
 * and its formats' data files share. Formats: Emt; Cue; Cdrdao Toc; Gdi; Ccd; Ldbst; Msx Cas; Dragon Cas; Zx Hobeta; Blindwrite4; Blindwrite 5 6 Image; Cfd; Dcp Disk; Ecm; Svd; Kryoflux Stream; Fdcopy Cfi; Snatchit Cp2; Simh Disk; Rsdos Fs; Jvc; Jffs2 Old; Squashfs Sqlz. */
#ifndef XX_FORMAT_SCHEMA_DISKNEXT_H
#define XX_FORMAT_SCHEMA_DISKNEXT_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Read text once, bounded by the native descriptor cap. Each scalar retains
 * its original byte span; whitespace, delimiters and encoded payload stay raw. */
typedef struct sxdn_text {sx_context*c;uint8_t*b;size_t n;} sxdn_text;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxdn_emt_header;
extern const sx_layout sxdn_msx_cas_binary_header;
extern const sx_layout sxdn_dragon_cas_block_header;
extern const sx_layout sxdn_dragon_cas_file_header;
extern const sx_layout sxdn_dragon_cas_block_checksum;
extern const sx_layout sxdn_hobeta_header;
extern const sx_layout sxdn_hobeta_code_header;
extern const sx_layout sxdn_rsdos_vdk_header;
extern const sx_layout sxdn_rsdos_granule;
extern const sx_layout sxdn_rsdos_directory_entry;
extern const sx_layout sxdn_dragon_dos_geometry;
extern const sx_layout sxdn_dragon_dos_file;
extern const sx_layout sxdn_dragon_dos_continuation;
extern const sx_layout sxdn_cfd_header;
extern const sx_layout sxdn_cfd_block;
extern const sx_layout sxdn_cfd_repeat;
extern const sx_layout sxdn_dcp_disk_header;
extern const sx_layout sxdn_dcp_rdc_block;
extern const sx_layout sxdn_fdcopy_track;
extern const sx_layout sxdn_fdcopy_token;
extern const sx_layout sxdn_fdcopy_repeat;
extern const sx_layout sxdn_cp2_header;
extern const sx_layout sxdn_cp2_segment_header;
extern const sx_layout sxdn_cp2_track;
extern const sx_layout sxdn_cp2_sector;
extern const sx_layout sxdn_cp2_header_checksum;
extern const sx_layout sxdn_cp2_segment_payload;
extern const sx_layout sxdn_ecm_signature;
extern const sx_layout sxdn_ecm_record_first;
extern const sx_layout sxdn_ecm_record_continuation;
extern const sx_layout sxdn_ecm_edc;
extern const sx_layout sxdn_ecm_mode1_address;
extern const sx_layout sxdn_ecm_mode2_subheader;
extern const sx_layout sxdn_kryoflux_oob;
extern const sx_layout sxdn_kryoflux_eof;
extern const sx_layout sxdn_kryoflux_stream_info;
extern const sx_layout sxdn_kryoflux_stream_end;
extern const sx_layout sxdn_kryoflux_index;
extern const sx_layout sxdn_simh_cpm_directory;
extern const sx_layout sxdn_svd_version;
extern const sx_layout sxdn_svd_sectors;
extern const sx_layout sxdn_svd_cylinders;
extern const sx_layout sxdn_svd_sides;
extern const sx_layout sxdn_svd_sector_size_code;
extern const sx_layout sxdn_svd_write_protect;
extern const sx_layout sxdn_disk_descriptor_string;
extern const sx_layout sxdn_kryoflux_info_text;
extern const sx_layout sxdn_blindwrite4_header;
extern const sx_layout sxdn_blindwrite4_string_size;
extern const sx_layout sxdn_blindwrite4_track_count;
extern const sx_layout sxdn_blindwrite4_extra_prefix;
extern const sx_layout sxdn_blindwrite4_track;
extern const sx_layout sxdn_blindwrite56_signature;
extern const sx_layout sxdn_blindwrite56_disc;
extern const sx_layout sxdn_blindwrite56_inquiry;
extern const sx_layout sxdn_blindwrite56_volume_name;
extern const sx_layout sxdn_blindwrite56_lengths;
extern const sx_layout sxdn_blindwrite56_data_list;
extern const sx_layout sxdn_blindwrite56_data_block;
extern const sx_layout sxdn_blindwrite56_data_tail;
extern const sx_layout sxdn_blindwrite56_session;
extern const sx_layout sxdn_blindwrite56_entry;
extern const sx_layout sxdn_blindwrite56_cd_extra;
extern const sx_layout sxdn_blindwrite56_footer;
extern const sx_layout sxdn_old_jffs2_common_header_le;
extern const sx_layout sxdn_old_jffs2_directory_entry_le;
extern const sx_layout sxdn_old_jffs2_inode_le;
extern const sx_layout sxdn_old_jffs2_xattr_le;
extern const sx_layout sxdn_old_jffs2_xref_le;
extern const sx_layout sxdn_old_jffs2_common_header_be;
extern const sx_layout sxdn_old_jffs2_directory_entry_be;
extern const sx_layout sxdn_old_jffs2_inode_be;
extern const sx_layout sxdn_old_jffs2_xattr_be;
extern const sx_layout sxdn_old_jffs2_xref_be;
extern const sx_layout sxdn_sqlz_squashfs2_superblock_le;
extern const sx_layout sxdn_sqlz_squashfs2_superblock_be;
extern const sx_layout sxdn_sqlz_squashfs3_superblock_le;
extern const sx_layout sxdn_sqlz_squashfs3_superblock_be;
extern const sx_layout sxdn_sqlz_squashfs_metadata_header_le;
extern const sx_layout sxdn_sqlz_squashfs_table_index_le;
extern const sx_layout sxdn_sqlz_squashfs2_fragment_index_le;
extern const sx_layout sxdn_sqlz_squashfs_identity_le;
extern const sx_layout sxdn_sqlz_squashfs_metadata_header_be;
extern const sx_layout sxdn_sqlz_squashfs_table_index_be;
extern const sx_layout sxdn_sqlz_squashfs2_fragment_index_be;
extern const sx_layout sxdn_sqlz_squashfs_identity_be;
extern const sx_layout sxdn_jvc_os9_disk_descriptor;
extern const sx_layout sxdn_jvc_os9_path_options;
extern const sx_layout sxdn_jvc_os9_file_descriptor;
extern const sx_layout sxdn_jvc_os9_segment;
extern const sx_layout sxdn_jvc_os9_directory_entry;
bool sxdn_span(sx_context*c,uint64_t p,uint64_t n);
bool sxdn_read(sx_context*c,uint64_t p,void*b,size_t n);
uint16_t sxdn16(const uint8_t*b,unsigned o);
uint32_t sxdn32(const uint8_t*b,unsigned o);
bool sxdn_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);
bool sxdn_value(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);
bool sxdn_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxdn_jvc_header(sx_context*c,uint64_t h);
bool sxdn_text_value(sxdn_text*t,const sx_layout*l,size_t a,size_t z);
bool sxdn_text_load(sx_context*c,unsigned kind);

/* Per-format walkers, called by the family's build. */
bool sx_emt_build(sx_context *c);  /* filesystem/emt/xx_emt_data.c */
bool sx_cue_build(sx_context *c);  /* filesystem/cue/xx_cue_data.c */
bool sx_cdrdao_toc_build(sx_context *c);  /* filesystem/cdrdao_toc/xx_cdrdao_toc_data.c */
bool sx_gdi_build(sx_context *c);  /* game/gdi/xx_gdi_data.c */
bool sx_ccd_build(sx_context *c);  /* filesystem/ccd/xx_ccd_data.c */
bool sx_ldbst_build(sx_context *c);  /* filesystem/ldbst/xx_ldbst_data.c */
bool sx_msx_cas_build(sx_context *c);  /* filesystem/msx_cas/xx_msx_cas_data.c */
bool sx_dragon_cas_build(sx_context *c);  /* filesystem/dragon_cas/xx_dragon_cas_data.c */
bool sx_zx_hobeta_build(sx_context *c);  /* filesystem/zx_hobeta/xx_zx_hobeta_data.c */
bool sx_blindwrite4_build(sx_context *c);  /* filesystem/blindwrite4/xx_blindwrite4_data.c */
bool sx_blindwrite_5_6_image_build(sx_context *c);  /* filesystem/blindwrite_5_6_image/xx_blindwrite_5_6_image_data.c */
bool sx_cfd_build(sx_context *c);  /* filesystem/cfd/xx_cfd_data.c */
bool sx_dcp_disk_build(sx_context *c);  /* filesystem/dcp_disk/xx_dcp_disk_data.c */
bool sx_ecm_build(sx_context *c);  /* filesystem/ecm/xx_ecm_data.c */
bool sx_svd_build(sx_context *c);  /* filesystem/svd/xx_svd_data.c */
bool sx_kryoflux_stream_build(sx_context *c);  /* filesystem/kryoflux_stream/xx_kryoflux_stream_data.c */
bool sx_fdcopy_cfi_build(sx_context *c);  /* filesystem/fdcopy_cfi/xx_fdcopy_cfi_data.c */
bool sx_snatchit_cp2_build(sx_context *c);  /* filesystem/snatchit_cp2/xx_snatchit_cp2_data.c */
bool sx_simh_disk_build(sx_context *c);  /* filesystem/simh_disk/xx_simh_disk_data.c */
bool sx_rsdos_fs_build(sx_context *c);  /* filesystem/rsdos_fs/xx_rsdos_fs_data.c */
bool sx_jvc_build(sx_context *c);  /* filesystem/jvc/xx_jvc_data.c */
bool sx_jffs2_old_build(sx_context *c);  /* filesystem/jffs2_old/xx_jffs2_old_data.c */
bool sx_squashfs_sqlz_build(sx_context *c);  /* filesystem/squashfs_sqlz/xx_squashfs_sqlz_data.c */

#endif
