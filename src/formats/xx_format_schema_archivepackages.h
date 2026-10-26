/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archivepackages schema family: what its family unit (xx_format_schema_archivepackages.c)
 * and its formats' data files share. Formats: KPCK; LingvoArc; LZ4Demo; VMSSaveset; SSM; SPK; WRZL; QIP2; TWRX; BeOSPackage; VMSPCSI; VMSDB; MLB_FT; Oberon; Solitaire Deluxe; CPOINT; RDC compressed stream; kgb_archiver; TAR NEXTSTEP; BFF. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVEPACKAGES_H
#define XX_FORMAT_SCHEMA_ARCHIVEPACKAGES_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxap_kpck_header;
extern const sx_layout sxap_kpck_filter;
extern const sx_layout sxap_lingvo_header;
extern const sx_layout sxap_lingvo_index_v1;
extern const sx_layout sxap_lingvo_member_v1;
extern const sx_layout sxap_lingvo_index_v2;
extern const sx_layout sxap_lingvo_member_v2;
extern const sx_layout sxap_finear_header;
extern const sx_layout sxap_lingvo_stream_header;
extern const sx_layout sxap_lingvo_code_length;
extern const sx_layout sxap_legacy_lz4_magic;
extern const sx_layout sxap_legacy_lz4_block;
extern const sx_layout sxap_legacy_lz4_skip;
extern const sx_layout sxap_ssm_header;
extern const sx_layout sxap_spark_prefix;
extern const sx_layout sxap_spark_original_size;
extern const sx_layout sxap_spark_riscos;
extern const sx_layout sxap_spark_end;
extern const sx_layout sxap_wrzl_header;
extern const sx_layout sxap_wrzl_block_size;
extern const sx_layout sxap_wrzl_mode;
extern const sx_layout sxap_wrzl_control;
extern const sx_layout sxap_qip_header;
extern const sx_layout sxap_qip_index;
extern const sx_layout sxap_qip_member_v1;
extern const sx_layout sxap_qip_member_v2;
extern const sx_layout sxap_twrx_header;
extern const sx_layout sxap_twrx_deflate;
extern const sx_layout sxap_beospkg_header;
extern const sx_layout sxap_beospkg_tag;
extern const sx_layout sxap_beospkg_value32;
extern const sx_layout sxap_beospkg_value64;
extern const sx_layout sxap_beospkg_offset64;
extern const sx_layout sxap_beospkg_size64;
extern const sx_layout sxap_beospkg_length;
extern const sx_layout sxap_beospkg_chunk;
extern const sx_layout sxap_cpoint_setup;
extern const sx_layout sxap_cpoint_file;
extern const sx_layout sxap_cpoint_footer;
extern const sx_layout sxap_mlbft_header;
extern const sx_layout sxap_mlbft_member;
extern const sx_layout sxap_oberon_member;
extern const sx_layout sxap_oberon_szdd;
extern const sx_layout sxap_solitaire_header;
extern const sx_layout sxap_solitaire_member;
extern const sx_layout sxap_rdc_block;
extern const sx_layout sxap_kgb2_header;
extern const sx_layout sxap_kgb2_member;
extern const sx_layout sxap_kgb2_encryption;
extern const sx_layout sxap_tar_nextstep_header;
extern const sx_layout sxap_bff_volume;
extern const sx_layout sxap_bff_legacy;
extern const sx_layout sxap_bff_member;
extern const sx_layout sxap_bff_compact;
extern const sx_layout sxap_bff_security_sizes;
extern const sx_layout sxap_bff_terminator;
extern const sx_layout sxap_archivepackages_name;
extern const sx_layout sxap_vms_backup_block;
extern const sx_layout sxap_vms_backup_record;
extern const sx_layout sxap_vms_backup_file_version;
extern const sx_layout sxap_vms_backup_attribute;
extern const sx_layout sxap_vms_backup_fid;
extern const sx_layout sxap_vms_backup_characteristics;
extern const sx_layout sxap_vms_backup_date;
extern const sx_layout sxap_vms_backup_fat;
extern const sx_layout sxap_vmspcsi_header;
extern const sx_layout sxap_vmspcsi_table;
extern const sx_layout sxap_vmspcsi_context;
extern const sx_layout sxap_vmspcsi_bitmap;
extern const sx_layout sxap_vmspcsi_node;
extern const sx_layout sxap_vmspcsi_context_map;
extern const sx_layout sxap_vmspcsi_record;
extern const sx_layout sxap_vmsdb_prefix;
extern const sx_layout sxap_vmsdb_short;
extern const sx_layout sxap_vmsdb_indefinite;
extern const sx_layout sxap_vmsdb_long1;
extern const sx_layout sxap_vmsdb_long2;
extern const sx_layout sxap_vmsdb_attributes;
bool sxap_span(sx_context*c,uint64_t p,uint64_t n);
bool sxap_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxap_uint(const uint8_t*b,unsigned n,bool be);
bool sxap_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxap_add(sx_context*c,const sx_layout*l,uint64_t p);
bool sxap_text(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,bool aliases);
bool sxap_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n);
bool sxap_dcl(sx_context*c,uint64_t p,uint64_t n);

/* Per-format walkers, called by the family's build. */
bool sx_kpck_build(sx_context *c);  /* archive/kpck/xx_kpck_data.c */
bool sx_lingvoarc_build(sx_context *c);  /* archive/lingvoarc/xx_lingvoarc_data.c */
bool sx_lz4demo_build(sx_context *c);  /* archive/lz4demo/xx_lz4demo_data.c */
bool sx_vmssaveset_build(sx_context *c);  /* archive/vmssaveset/xx_vmssaveset_data.c */
bool sx_ssm_build(sx_context *c);  /* archive/ssm/xx_ssm_data.c */
bool sx_spk_build(sx_context *c);  /* archive/spk/xx_spk_data.c */
bool sx_wrzl_build(sx_context *c);  /* archive/wrzl/xx_wrzl_data.c */
bool sx_qip2_build(sx_context *c);  /* installer/qip2/xx_qip2_data.c */
bool sx_twrx_build(sx_context *c);  /* installer/twrx/xx_twrx_data.c */
bool sx_beospkg_build(sx_context *c);  /* installer/beospkg/xx_beospkg_data.c */
bool sx_vmspcsi_build(sx_context *c);  /* installer/vmspcsi/xx_vmspcsi_data.c */
bool sx_vmsdb_build(sx_context *c);  /* installer/vmsdb/xx_vmsdb_data.c */
bool sx_mlb_ft_build(sx_context *c);  /* archive/mlb_ft/xx_mlb_ft_data.c */
bool sx_oberon_build(sx_context *c);  /* installer/oberon/xx_oberon_data.c */
bool sx_solitaire_deluxe_build(sx_context *c);  /* installer/solitaire_deluxe/xx_solitaire_deluxe_data.c */
bool sx_cpoint_build(sx_context *c);  /* installer/cpoint/xx_cpoint_data.c */
bool sx_rdc_build(sx_context *c);  /* archive/rdc/xx_rdc_data.c */
bool sx_kgb_archiver_build(sx_context *c);  /* archive/kgb_archiver/xx_kgb_archiver_data.c */
bool sx_tar_nextstep_build(sx_context *c);  /* archive/tar_nextstep/xx_tar_nextstep_data.c */
bool sx_aixbff_build(sx_context *c);  /* installer/aixbff/xx_aixbff_data.c */

#endif
