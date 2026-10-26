/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archiveframes schema family: what its family unit (xx_format_schema_archiveframes.c)
 * and its formats' data files share. Formats: "LZ" single-file containers (XLZHCXP); NewWave LZWD packed files; MI10 crunched block chains; PAKLEO (.PLL) archives; Zcmp compressed files (the Solaris "compressed file" wrapper); ZTC (Zortech C / Symantec C++ distribution) archives; GTU OS/2 distribution kits (*.csd, *.001, *.002); JBF archives (headerless DOS LZHUF archiver); IMP archives (Technelysium's IMP archiver); IrwinPac installation files (*.DL_, *.EX_ and friends); KolibriOS kpack ("KPCK") containers; LIM archives; QDA archives; RID archives (OS2YOU / LANTERM / TERM2 / DRIVERS packages, 1998-99); Tivoli Filepack Block (.PKT) containers; Wintersoft "**++" archives; WPK; CMS XEDIT PACK / COPYFILE PACK containers; ZIE; Clay archives (*.cmz). */
#ifndef XX_FORMAT_SCHEMA_ARCHIVEFRAMES_H
#define XX_FORMAT_SCHEMA_ARCHIVEFRAMES_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxafr_lzhcxp_header;
extern const sx_layout sxafr_lzhcxp_block_size;
extern const sx_layout sxafr_lzwd_header;
extern const sx_layout sxafr_mi10_member;
extern const sx_layout sxafr_mi10_prefix;
extern const sx_layout sxafr_pakleo_header;
extern const sx_layout sxafr_pakleo_member;
extern const sx_layout sxafr_zcmp_header;
extern const sx_layout sxafr_zcmp_seek_word;
extern const sx_layout sxafr_ztc_header;
extern const sx_layout sxafr_ztc_member;
extern const sx_layout sxafr_ztc_check;
extern const sx_layout sxafr_ztc_page_sum;
extern const sx_layout sxafr_gtu_header;
extern const sx_layout sxafr_gtu_record;
extern const sx_layout sxafr_gtu_terminator;
extern const sx_layout sxafr_gtu_info;
extern const sx_layout sxafr_gtu_frame;
extern const sx_layout sxafr_jbf_member;
extern const sx_layout sxafr_jbf_count;
extern const sx_layout sxafr_imp_header;
extern const sx_layout sxafr_imp_directory_block;
extern const sx_layout sxafr_irwinpac_header;
extern const sx_layout sxafr_irwinpac_block;
extern const sx_layout sxafr_kpack_header;
extern const sx_layout sxafr_kpack_filter;
extern const sx_layout sxafr_lim_header;
extern const sx_layout sxafr_lim_chunk;
extern const sx_layout sxafr_lim_member;
extern const sx_layout sxafr_qda_header;
extern const sx_layout sxafr_qda_member;
extern const sx_layout sxafr_rid_member;
extern const sx_layout sxafr_rid_block;
extern const sx_layout sxafr_tivoli_header;
extern const sx_layout sxafr_tivoli_block;
extern const sx_layout sxafr_tivoli_digest;
extern const sx_layout sxafr_wintersoft_header;
extern const sx_layout sxafr_wintersoft_member;
extern const sx_layout sxafr_wpk_header;
extern const sx_layout sxafr_wpk_member;
extern const sx_layout sxafr_xeditpack_header;
extern const sx_layout sxafr_zie_header;
extern const sx_layout sxafr_clay_member;
extern const sx_layout sxafr_archiveframes_dcl;
extern const sx_layout sxafr_clay_prefix;
bool sxafr_span(sx_context*c,uint64_t p,uint64_t n);
bool sxafr_read(sx_context*c,uint64_t p,void*b,size_t n);
uint64_t sxafr_uint(const uint8_t*b,unsigned n,bool be);
bool sxafr_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v);
bool sxafr_add(sx_context*c,const sx_layout*l,uint64_t p);

/* Per-format walkers, called by the family's build. */
bool sx_lzhcxp_build(sx_context *c);  /* archive/lzhcxp/xx_lzhcxp_data.c */
bool sx_lzwd_build(sx_context *c);  /* archive/lzwd/xx_lzwd_data.c */
bool sx_mi10_build(sx_context *c);  /* archive/mi10/xx_mi10_data.c */
bool sx_pakleo_build(sx_context *c);  /* archive/pakleo/xx_pakleo_data.c */
bool sx_zcmp_build(sx_context *c);  /* archive/zcmp/xx_zcmp_data.c */
bool sx_ztc_build(sx_context *c);  /* archive/ztc/xx_ztc_data.c */
bool sx_gtu_build(sx_context *c);  /* installer/gtu/xx_gtu_data.c */
bool sx_jbf_build(sx_context *c);  /* archive/jbf/xx_jbf_data.c */
bool sx_imp_build(sx_context *c);  /* archive/imp/xx_imp_data.c */
bool sx_irwinpac_build(sx_context *c);  /* installer/irwinpac/xx_irwinpac_data.c */
bool sx_kolibrikpack_build(sx_context *c);  /* archive/kolibrikpack/xx_kolibrikpack_data.c */
bool sx_lim_build(sx_context *c);  /* archive/lim/xx_lim_data.c */
bool sx_qda_build(sx_context *c);  /* archive/qda/xx_qda_data.c */
bool sx_rid_build(sx_context *c);  /* installer/rid/xx_rid_data.c */
bool sx_tivoli_build(sx_context *c);  /* installer/tivoli/xx_tivoli_data.c */
bool sx_wintersoft_build(sx_context *c);  /* archive/wintersoft/xx_wintersoft_data.c */
bool sx_wpk_build(sx_context *c);  /* installer/wpk/xx_wpk_data.c */
bool sx_xeditpack_build(sx_context *c);  /* archive/xeditpack/xx_xeditpack_data.c */
bool sx_zie_build(sx_context *c);  /* archive/zie/xx_zie_data.c */
bool sx_claylz_build(sx_context *c);  /* archive/claylz/xx_claylz_data.c */

#endif
