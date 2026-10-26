/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archiveend schema family: what its family unit (xx_format_schema_archiveend.c)
 * and its formats' data files share. Formats: SDS_SFX; LHPAK_SFX; LHSFX; S_OMNI; pmarc sfx; SFX VMS DCX; SFX NSS; CopyQMOverlay; DCLMultiStream; diet_compression; BOO; sfx arcv2; sfx imp; sfx cazip; sfx starkit; sfx tgcf; sfx spis; Atari LARC PFX; SFX embedded archive; SFX RSFX. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVEEND_H
#define XX_FORMAT_SCHEMA_ARCHIVEEND_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxaend_archiveend_comment;
extern const sx_layout sxaend_sds_sfx_member;
extern const sx_layout sxaend_lhpak_sfx_position;
extern const sx_layout sxaend_lhpak_sfx_member;
extern const sx_layout sxaend_lhpak_sfx_block;
extern const sx_layout sxaend_lhsfx_control;
extern const sx_layout sxaend_lhsfx_member;
extern const sx_layout sxaend_omni_mode;
extern const sx_layout sxaend_omni_comment_size;
extern const sx_layout sxaend_omni_name_size;
extern const sx_layout sxaend_omni_data_size;
extern const sx_layout sxaend_omni_member_tail;
extern const sx_layout sxaend_omni_lh_block;
extern const sx_layout sxaend_diet_data_v100;
extern const sx_layout sxaend_diet_data_v102;
extern const sx_layout sxaend_diet_data_v144;
extern const sx_layout sxaend_diet_data_lengths;
extern const sx_layout sxaend_dclraw_stream;
extern const sx_layout sxaend_copyqm_tx_header;
extern const sx_layout sxaend_copyqm_tx_leaf;
extern const sx_layout sxaend_copyqm_tx_branch;
extern const sx_layout sxaend_copyqm_tx_screen6;
extern const sx_layout sxaend_copyqm_tx_screen8;
extern const sx_layout sxaend_copyqm_tx_geometry;
extern const sx_layout sxaend_copyqm_tx_line;
extern const sx_layout sxaend_nss_member;
extern const sx_layout sxaend_dcx_ftsv_header;
extern const sx_layout sxaend_dcx_ftsv_table;
extern const sx_layout sxaend_dcx_ftsv_context;
extern const sx_layout sxaend_dcx_ftsv_leaf_bitmap;
extern const sx_layout sxaend_dcx_ftsv_nodes;
extern const sx_layout sxaend_dcx_ftsv_map;
extern const sx_layout sxaend_dcx_ftsv_first_frame;
extern const sx_layout sxaend_dcx_ftsv_second_group;
extern const sx_layout sxaend_dcx_ftsv_frame;
extern const sx_layout sxaend_dcx_ftsv_group_start;
extern const sx_layout sxaend_dcx_ftsv_group_end;
extern const sx_layout sxaend_pmarc_member;
extern const sx_layout sxaend_pmarc_crc;
extern const sx_layout sxaend_pmarc_end;
extern const sx_layout sxaend_boo_name;
extern const sx_layout sxaend_boo_encoded_line;
extern const sx_layout sxaend_pfx_gemdos_header;
extern const sx_layout sxaend_localzip_softpaq_table;
extern const sx_layout sxaend_rsfx_rar_signature;
extern const sx_layout sxaend_rsfx_rar_block;
extern const sx_layout sxaend_rsfx_rar_main;
extern const sx_layout sxaend_rsfx_rar_file;
extern const sx_layout sxaend_rsfx_rar_service_size;
bool sxaend_span(sx_context*c,uint64_t p,uint64_t n);
bool sxaend_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxaend_uint(const uint8_t*b,unsigned n,bool be);
bool sxaend_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxaend_add(sx_context*c,const sx_layout*l,uint64_t p);
bool sxaend_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases);
bool sxaend_name(sx_context*c,uint64_t p,uint64_t n);
bool sxaend_first_source(sx_context*c,uint64_t*at,uint64_t*size);
bool sxaend_carrier_records(sx_context*c);

/* Per-format walkers, called by the family's build. */
bool sx_sds_sfx_build(sx_context *c);  /* archive/sds_sfx/xx_sds_sfx_data.c */
bool sx_lhpak_sfx_build(sx_context *c);  /* archive/lhpak_sfx/xx_lhpak_sfx_data.c */
bool sx_lhsfx_build(sx_context *c);  /* archive/lhsfx/xx_lhsfx_data.c */
bool sx_s_omni_build(sx_context *c);  /* archive/s_omni/xx_s_omni_data.c */
bool sx_pmarc_sfx_build(sx_context *c);  /* archive/pmarc_sfx/xx_pmarc_sfx_data.c */
bool sx_sfx_vms_dcx_build(sx_context *c);  /* archive/sfx_vms_dcx/xx_sfx_vms_dcx_data.c */
bool sx_sfx_nss_build(sx_context *c);  /* archive/sfx_nss/xx_sfx_nss_data.c */
bool sx_copyqmexe_build(sx_context *c);  /* executable/copyqmexe/xx_copyqmexe_data.c */
bool sx_dclraw_build(sx_context *c);  /* archive/dclraw/xx_dclraw_data.c */
bool sx_diet_compression_build(sx_context *c);  /* archive/diet_compression/xx_diet_compression_data.c */
bool sx_boo_build(sx_context *c);  /* archive/boo/xx_boo_data.c */
bool sx_sfx_arcv2_build(sx_context *c);  /* archive/sfx_arcv2/xx_sfx_arcv2_data.c */
bool sx_sfx_imp_build(sx_context *c);  /* archive/sfx_imp/xx_sfx_imp_data.c */
bool sx_sfx_cazip_build(sx_context *c);  /* archive/sfx_cazip/xx_sfx_cazip_data.c */
bool sx_sfx_starkit_build(sx_context *c);  /* archive/sfx_starkit/xx_sfx_starkit_data.c */
bool sx_sfx_tgcf_build(sx_context *c);  /* archive/sfx_tgcf/xx_sfx_tgcf_data.c */
bool sx_sfx_spis_build(sx_context *c);  /* archive/sfx_spis/xx_sfx_spis_data.c */
bool sx_larc_pfx_build(sx_context *c);  /* archive/larc_pfx/xx_larc_pfx_data.c */
bool sx_sfx_localzip_build(sx_context *c);  /* archive/sfx_localzip/xx_sfx_localzip_data.c */
bool sx_sfx_rsfx_build(sx_context *c);  /* archive/sfx_rsfx/xx_sfx_rsfx_data.c */

#endif
