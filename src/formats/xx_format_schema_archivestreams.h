/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archivestreams schema family: what its family unit (xx_format_schema_archivestreams.c)
 * and its formats' data files share. Formats: SQZE compressed archive; CSQ compressed data; Zoot v1 notes; RDFZ compressed image; ASD compressed stream; Fox SQZ compressed archive; LDS compressed stream; WebExe M2E container; PMA; LHF; ECMPACKED; CHIEFLZ; IBMPACK; CAZIP; TPWM; MRNZ; EDC; WinLink; FTCOMP; CPM_CRUNCH. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVESTREAMS_H
#define XX_FORMAT_SCHEMA_ARCHIVESTREAMS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxas_sqze_header;
extern const sx_layout sxas_csq_header;
extern const sx_layout sxas_csq_entry;
extern const sx_layout sxas_zoot1_header;
extern const sx_layout sxas_zoot1_entry137;
extern const sx_layout sxas_zoot1_entry235;
extern const sx_layout sxas_rdfz_header;
extern const sx_layout sxas_rdfz_count;
extern const sx_layout sxas_rdfz_entry;
extern const sx_layout sxas_rdfz_member_size;
extern const sx_layout sxas_asd_header;
extern const sx_layout sxas_asd_name_length;
extern const sx_layout sxas_asd_entry;
extern const sx_layout sxas_fox_sqz_header;
extern const sx_layout sxas_fox_sqz_member;
extern const sx_layout sxas_fox_sqz_end;
extern const sx_layout sxas_lds_header;
extern const sx_layout sxas_lds_count;
extern const sx_layout sxas_lds_entry;
extern const sx_layout sxas_webexe_header;
extern const sx_layout sxas_webexe_zip_local;
extern const sx_layout sxas_webexe_zip_central;
extern const sx_layout sxas_webexe_zip_end;
extern const sx_layout sxas_pma_header;
extern const sx_layout sxas_pma_crc16;
extern const sx_layout sxas_lhf_header;
extern const sx_layout sxas_lhf_entry;
extern const sx_layout sxas_ecmpacked_header;
extern const sx_layout sxas_chieflz_prefix;
extern const sx_layout sxas_chieflz_name_size;
extern const sx_layout sxas_chieflz_method;
extern const sx_layout sxas_cazip_header;
extern const sx_layout sxas_cazip_dcl_prefix;
extern const sx_layout sxas_tpwm_header;
extern const sx_layout sxas_mrnz_header;
extern const sx_layout sxas_edc_header;
extern const sx_layout sxas_winlink_header;
extern const sx_layout sxas_crunch_magic;
extern const sx_layout sxas_crunch_parameters;
bool sxas_span(sx_context*c,uint64_t p,uint64_t n);
bool sxas_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxas_uint(const uint8_t*b,unsigned n,bool be);
bool sxas_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxas_add(sx_context*c,const sx_layout*l,uint64_t p);
bool sxas_ibm(sx_context*c,bool ft);

/* Per-format walkers, called by the family's build. */
bool sx_sqze_build(sx_context *c);  /* archive/sqze/xx_sqze_data.c */
bool sx_csq_build(sx_context *c);  /* archive/csq/xx_csq_data.c */
bool sx_zoot1_build(sx_context *c);  /* archive/zoot1/xx_zoot1_data.c */
bool sx_rdfz_build(sx_context *c);  /* archive/rdfz/xx_rdfz_data.c */
bool sx_asd_build(sx_context *c);  /* archive/asd/xx_asd_data.c */
bool sx_fox_sqz_build(sx_context *c);  /* archive/fox_sqz/xx_fox_sqz_data.c */
bool sx_lds_build(sx_context *c);  /* archive/lds/xx_lds_data.c */
bool sx_webexe_build(sx_context *c);  /* archive/webexe/xx_webexe_data.c */
bool sx_pma_build(sx_context *c);  /* archive/pma/xx_pma_data.c */
bool sx_lhf_build(sx_context *c);  /* archive/lhf/xx_lhf_data.c */
bool sx_ecmpacked_build(sx_context *c);  /* archive/ecmpacked/xx_ecmpacked_data.c */
bool sx_chieflz_build(sx_context *c);  /* archive/chieflz/xx_chieflz_data.c */
bool sx_ibmpack_build(sx_context *c);  /* archive/ibmpack/xx_ibmpack_data.c */
bool sx_cazip_build(sx_context *c);  /* archive/cazip/xx_cazip_data.c */
bool sx_tpwm_build(sx_context *c);  /* archive/tpwm/xx_tpwm_data.c */
bool sx_mrnz_build(sx_context *c);  /* archive/mrnz/xx_mrnz_data.c */
bool sx_edc_build(sx_context *c);  /* archive/edc/xx_edc_data.c */
bool sx_winlink_build(sx_context *c);  /* archive/winlink/xx_winlink_data.c */
bool sx_ftcomp_build(sx_context *c);  /* archive/ftcomp/xx_ftcomp_data.c */
bool sx_cpm_crunch_build(sx_context *c);  /* archive/cpm_crunch/xx_cpm_crunch_data.c */

#endif
