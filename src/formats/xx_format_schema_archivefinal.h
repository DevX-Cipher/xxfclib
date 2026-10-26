/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archivefinal schema family: what its family unit (xx_format_schema_archivefinal.c)
 * and its formats' data files share. Formats: nix nar; Phar; StuffIt split file; Squeeze1; Squeeze2; SQ; LSPack10; RNCA; BAGF; IXA; bga; DFC; KA; SHRINK_CDAF; SPACK; PCOMPRESS_PACK; MXM_SIMPLEARC; LIF; DN; INSA. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVEFINAL_H
#define XX_FORMAT_SCHEMA_ARCHIVEFINAL_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxaf_nar_string_length;
extern const sx_layout sxaf_phar_manifest_prefix;
extern const sx_layout sxaf_phar_api_version;
extern const sx_layout sxaf_phar_manifest_flags;
extern const sx_layout sxaf_phar_metadata_length;
extern const sx_layout sxaf_phar_name_length;
extern const sx_layout sxaf_phar_file_entry;
extern const sx_layout sxaf_phar_signature_footer;
extern const sx_layout sxaf_stuffit_split_header;
extern const sx_layout sxaf_sq_magic;
extern const sx_layout sxaf_sq_calendar;
extern const sx_layout sxaf_lspack10_member;
extern const sx_layout sxaf_rnca_header;
extern const sx_layout sxaf_rnca_directory_offset;
extern const sx_layout sxaf_rnca_stored_member;
extern const sx_layout sxaf_rnca_compressed_member;
extern const sx_layout sxaf_bagf_header;
extern const sx_layout sxaf_ixa_header;
extern const sx_layout sxaf_ixa_entry;
extern const sx_layout sxaf_bga_member;
extern const sx_layout sxaf_dfc_header;
extern const sx_layout sxaf_dfc_entry;
extern const sx_layout sxaf_ka_header;
extern const sx_layout sxaf_ka_entry;
extern const sx_layout sxaf_cdaf_header;
extern const sx_layout sxaf_cdaf_member;
extern const sx_layout sxaf_cdaf_chunk;
extern const sx_layout sxaf_spack_magic;
extern const sx_layout sxaf_spack_stored_member;
extern const sx_layout sxaf_spack_compressed_member;
extern const sx_layout sxaf_spack_footer;
extern const sx_layout sxaf_pcompress_magic;
extern const sx_layout sxaf_pcompress_member_size;
extern const sx_layout sxaf_pcompress_lh_block;
extern const sx_layout sxaf_mxm_simplearc_member;
extern const sx_layout sxaf_lif_header;
extern const sx_layout sxaf_dn_data_header;
extern const sx_layout sxaf_dn_directory_header;
extern const sx_layout sxaf_dn_end_marker;
extern const sx_layout sxaf_insa_version;
extern const sx_layout sxaf_insa_member;
bool sxaf_span(sx_context*c,uint64_t p,uint64_t n);
bool sxaf_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxaf_uint(const uint8_t*b,unsigned n,bool be);
bool sxaf_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxaf_add(sx_context*c,const sx_layout*l,uint64_t p);
bool sxaf_zstr(sx_context*c,uint64_t*p,uint64_t end,unsigned cap,uint8_t stop);
bool sxaf_squeeze(sx_context*c,bool second);
bool sxaf_table(sx_context*c,const sx_layout*h,const sx_layout*entry,uint64_t off,unsigned width,uint64_t p,uint64_t stride);

/* Per-format walkers, called by the family's build. */
bool sx_nix_nar_build(sx_context *c);  /* archive/nix_nar/xx_nix_nar_data.c */
bool sx_phar_build(sx_context *c);  /* archive/phar/xx_phar_data.c */
bool sx_stuffit_split_file_build(sx_context *c);  /* archive/stuffit_split_file/xx_stuffit_split_file_data.c */
bool sx_squeeze1_build(sx_context *c);  /* archive/squeeze1/xx_squeeze1_data.c */
bool sx_squeeze2_build(sx_context *c);  /* archive/squeeze2/xx_squeeze2_data.c */
bool sx_sq_build(sx_context *c);  /* archive/sq/xx_sq_data.c */
bool sx_lspack10_build(sx_context *c);  /* archive/lspack10/xx_lspack10_data.c */
bool sx_rnca_build(sx_context *c);  /* archive/rnca/xx_rnca_data.c */
bool sx_bagf_build(sx_context *c);  /* archive/bagf/xx_bagf_data.c */
bool sx_ixa_build(sx_context *c);  /* archive/ixa/xx_ixa_data.c */
bool sx_bga_build(sx_context *c);  /* archive/bga/xx_bga_data.c */
bool sx_dfc_build(sx_context *c);  /* archive/dfc/xx_dfc_data.c */
bool sx_ka_build(sx_context *c);  /* archive/ka/xx_ka_data.c */
bool sx_shrink_cdaf_build(sx_context *c);  /* archive/shrink_cdaf/xx_shrink_cdaf_data.c */
bool sx_spack_build(sx_context *c);  /* archive/spack/xx_spack_data.c */
bool sx_pcompress_pack_build(sx_context *c);  /* archive/pcompress_pack/xx_pcompress_pack_data.c */
bool sx_mxm_simplearc_build(sx_context *c);  /* archive/mxm_simplearc/xx_mxm_simplearc_data.c */
bool sx_lif_build(sx_context *c);  /* archive/lif/xx_lif_data.c */
bool sx_dn_build(sx_context *c);  /* archive/dn/xx_dn_data.c */
bool sx_insa_build(sx_context *c);  /* archive/insa/xx_insa_data.c */

#endif
