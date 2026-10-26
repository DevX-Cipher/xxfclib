/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archivetails schema family: what its family unit (xx_format_schema_archivetails.c)
 * and its formats' data files share. Formats: ZXZip; SAF; SLS; NID; GAMOS; FPAK; FINEAR; GST; GPF pack; PSDC; EDI LZSS; LZK00; Compaq LZH; LIFKD; PSN; MCC; XLAS; MDCD; BVRP. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVETAILS_H
#define XX_FORMAT_SCHEMA_ARCHIVETAILS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

#define SXAT_LIMIT 20000U

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxat_zxzip_header;
extern const sx_layout sxat_zxzip_member;
extern const sx_layout sxat_saf_banner29;
extern const sx_layout sxat_saf_banner47;
extern const sx_layout sxat_saf_member;
extern const sx_layout sxat_saf_chunk;
extern const sx_layout sxat_sls_header;
extern const sx_layout sxat_nid_header;
extern const sx_layout sxat_nid_member;
extern const sx_layout sxat_nid_block;
extern const sx_layout sxat_gamos_header;
extern const sx_layout sxat_gamos_member;
extern const sx_layout sxat_fpak_header;
extern const sx_layout sxat_fpac_header;
extern const sx_layout sxat_fpak_segment;
extern const sx_layout sxat_finear_header;
extern const sx_layout sxat_gst_member;
extern const sx_layout sxat_gpfpack_header;
extern const sx_layout sxat_gpfpack_block;
extern const sx_layout sxat_psdc_header;
extern const sx_layout sxat_edi_header;
extern const sx_layout sxat_edi_name;
extern const sx_layout sxat_edi_size;
extern const sx_layout sxat_lzk_header;
extern const sx_layout sxat_lzk_literal;
extern const sx_layout sxat_lzk_match;
extern const sx_layout sxat_compaqlzh_header;
extern const sx_layout sxat_lifkd_member;
extern const sx_layout sxat_psn_header;
extern const sx_layout sxat_mcc_member;
extern const sx_layout sxat_xlas_header;
extern const sx_layout sxat_xlas_member;
extern const sx_layout sxat_mdcd_member;
extern const sx_layout sxat_mdcd_path;
extern const sx_layout sxat_bvrp_header;
extern const sx_layout sxat_bvrp_member;
bool sxat_span(sx_context*c,uint64_t p,uint64_t n);
bool sxat_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxat_uint(const uint8_t*b,unsigned n,bool be);
bool sxat_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxat_add(sx_context*c,const sx_layout*l,uint64_t p);
bool sxat_dcl(sx_context*c,uint64_t p,uint64_t n);
bool sxat_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t width,uint64_t n);
bool sxat_hex(sx_context*c,uint64_t p,unsigned n,uint64_t*v);

/* Per-format walkers, called by the family's build. */
bool sx_zxzip_build(sx_context *c);  /* archive/zxzip/xx_zxzip_data.c */
bool sx_saf_build(sx_context *c);  /* archive/saf/xx_saf_data.c */
bool sx_sls_build(sx_context *c);  /* archive/sls/xx_sls_data.c */
bool sx_nid_build(sx_context *c);  /* installer/nid/xx_nid_data.c */
bool sx_gamos_build(sx_context *c);  /* archive/gamos/xx_gamos_data.c */
bool sx_fpak_build(sx_context *c);  /* installer/fpak/xx_fpak_data.c */
bool sx_finear_build(sx_context *c);  /* archive/finear/xx_finear_data.c */
bool sx_gst_build(sx_context *c);  /* installer/gst/xx_gst_data.c */
bool sx_gpfpack_build(sx_context *c);  /* archive/gpfpack/xx_gpfpack_data.c */
bool sx_psdc_build(sx_context *c);  /* archive/psdc/xx_psdc_data.c */
bool sx_edilzss_build(sx_context *c);  /* archive/edilzss/xx_edilzss_data.c */
bool sx_lzk00_build(sx_context *c);  /* archive/lzk00/xx_lzk00_data.c */
bool sx_compaqlzh_build(sx_context *c);  /* archive/compaqlzh/xx_compaqlzh_data.c */
bool sx_lifkd_build(sx_context *c);  /* installer/lifkd/xx_lifkd_data.c */
bool sx_psn_build(sx_context *c);  /* archive/psn/xx_psn_data.c */
bool sx_mcc_build(sx_context *c);  /* archive/mcc/xx_mcc_data.c */
bool sx_xlas_build(sx_context *c);  /* archive/xlas/xx_xlas_data.c */
bool sx_mdcd_build(sx_context *c);  /* archive/mdcd/xx_mdcd_data.c */
bool sx_bvrp_build(sx_context *c);  /* archive/bvrp/xx_bvrp_data.c */

#endif
