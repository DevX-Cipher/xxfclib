/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The diskremaining schema family: what its family unit (xx_format_schema_diskremaining.c)
 * and its formats' data files share. Formats: Sydex diskette image; Apple sparse bundle; TRS-80 JV1; ddd; fei; apple nib; ti99 pc99; vtr disk; speccydos sdd; SAVAGE; Gutenberg filesystem; Apple II cassette WAV; Xbox 360 disk layout. */
#ifndef XX_FORMAT_SCHEMA_DISKREMAINING_H
#define XX_FORMAT_SCHEMA_DISKREMAINING_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxdr_sydex_wb_header;
extern const sx_layout sxdr_sydex_image_header;
extern const sx_layout sxdr_sydex_track_header;
extern const sx_layout sxdr_trs80_boot_directory;
extern const sx_layout sxdr_trs80_gat_track;
extern const sx_layout sxdr_trs80_gat_identity;
extern const sx_layout sxdr_trs80_hit;
extern const sx_layout sxdr_trs80_primary_entry;
extern const sx_layout sxdr_trs80_extended_entry;
extern const sx_layout sxdr_trs80_extent;
extern const sx_layout sxdr_trs80_extent_link;
extern const sx_layout sxdr_savage_header;
extern const sx_layout sxdr_vtr_header;
extern const sx_layout sxdr_vtr_track_entry;
extern const sx_layout sxdr_pc99_id_fm;
extern const sx_layout sxdr_pc99_id_mfm;
extern const sx_layout sxdr_pc99_data_fm;
extern const sx_layout sxdr_pc99_data_mfm;
extern const sx_layout sxdr_pc99_data_crc;
extern const sx_layout sxdr_apple_gcr_address;
extern const sx_layout sxdr_apple_gcr_data_prefix;
extern const sx_layout sxdr_apple_gcr_data_suffix;
extern const sx_layout sxdr_gutenberg_link;
extern const sx_layout sxdr_gutenberg_volume;
extern const sx_layout sxdr_gutenberg_entry;
extern const sx_layout sxdr_cassette_riff;
extern const sx_layout sxdr_cassette_chunk;
extern const sx_layout sxdr_cassette_pcm_format;
extern const sx_layout sxdr_xbox_fatx_header_le;
extern const sx_layout sxdr_xbox_fatx_header_be;
extern const sx_layout sxdr_plist_tag;
extern const sx_layout sxdr_plist_key;
extern const sx_layout sxdr_plist_string;
extern const sx_layout sxdr_plist_integer;
extern const sx_layout sxdr_plist_disk_size;
extern const sx_layout sxdr_plist_band_size;
extern const sx_layout sxdr_plist_bundle_version;
extern const sx_layout sxdr_trs80_gat_lockout;
extern const sx_layout sxdr_trs80_gat_system;
extern const sx_layout sxdr_sydex_description;
extern const sx_layout sxdr_fei_id_phase0;
extern const sx_layout sxdr_fei_id_phase1;
extern const sx_layout sxdr_fei_id_phase2;
extern const sx_layout sxdr_fei_id_phase3;
extern const sx_layout sxdr_fei_id_phase4;
extern const sx_layout sxdr_fei_id_phase5;
extern const sx_layout sxdr_fei_id_phase6;
extern const sx_layout sxdr_fei_id_phase7;
extern const sx_layout sxdr_ddd_initial_dictionary;
extern const sx_layout sxdr_speccydos_boot_header;
extern const sx_layout sxdr_cassette_pcm_extension;
extern const sx_layout sxdr_xbox_fatx_name_le;
bool sxdr_span(sx_context*c,uint64_t p,uint64_t n);
bool sxdr_read(sx_context*c,uint64_t p,void*b,size_t n);
uint16_t sxdr16(const uint8_t*b,bool be);
uint32_t sxdr32(const uint8_t*b,bool be);
bool sxdr_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count);
bool sxdr_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n);
uint16_t sxdr_ccitt(const uint8_t*b,size_t n);

/* Per-format walkers, called by the family's build. */
bool sx_sfx_sydex_diskette_image_build(sx_context *c);  /* filesystem/sfx_sydex_diskette_image/xx_sfx_sydex_diskette_image_data.c */
bool sx_apple_sparse_bundle_build(sx_context *c);  /* filesystem/apple_sparse_bundle/xx_apple_sparse_bundle_data.c */
bool sx_trs_80_jv1_build(sx_context *c);  /* filesystem/trs_80_jv1/xx_trs_80_jv1_data.c */
bool sx_ddd_build(sx_context *c);  /* filesystem/ddd/xx_ddd_data.c */
bool sx_fei_build(sx_context *c);  /* filesystem/fei/xx_fei_data.c */
bool sx_apple_nib_build(sx_context *c);  /* filesystem/apple_nib/xx_apple_nib_data.c */
bool sx_ti99_pc99_build(sx_context *c);  /* filesystem/ti99_pc99/xx_ti99_pc99_data.c */
bool sx_vtr_disk_build(sx_context *c);  /* filesystem/vtr_disk/xx_vtr_disk_data.c */
bool sx_speccydos_sdd_build(sx_context *c);  /* filesystem/speccydos_sdd/xx_speccydos_sdd_data.c */
bool sx_savage_build(sx_context *c);  /* filesystem/savage/xx_savage_data.c */
bool sx_gutenberg_build(sx_context *c);  /* filesystem/gutenberg/xx_gutenberg_data.c */
bool sx_apple_cassette_build(sx_context *c);  /* filesystem/apple_cassette/xx_apple_cassette_data.c */
bool sx_xbox360_layout_build(sx_context *c);  /* filesystem/xbox360_layout/xx_xbox360_layout_data.c */

#endif
