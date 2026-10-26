/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The package schema family: what its family unit (xx_format_schema_package.c)
 * and its formats' data files share. Formats: ARJ; ACE; ALZ; HA; ZOO; LHA; zlib; XAR; RPM package; Microsoft CHM; TNEF; WIM; UNIX COMPRESS; UNIX PACK; snappy framed; Mozilla MAR; Chromium DataPack; XPAK; tex dvi. */
#ifndef XX_FORMAT_SCHEMA_PACKAGE_H
#define XX_FORMAT_SCHEMA_PACKAGE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sx_p_arj_prefix;
extern const sx_layout sx_p_arj_main;
extern const sx_layout sx_p_arj_file;
extern const sx_layout sx_p_crc32;
extern const sx_layout sx_p_crc16;
extern const sx_layout sx_p_length16;
extern const sx_layout sx_p_ace_main;
extern const sx_layout sx_p_ace_generic;
extern const sx_layout sx_p_ace_file32;
extern const sx_layout sx_p_ace_file64;
extern const sx_layout sx_p_alz_header;
extern const sx_layout sx_p_alz_file;
extern const sx_layout sx_p_alz_sizes1;
extern const sx_layout sx_p_alz_sizes2;
extern const sx_layout sx_p_alz_sizes3;
extern const sx_layout sx_p_alz_sizes4;
extern const sx_layout sx_p_alz_sizes5;
extern const sx_layout sx_p_alz_sizes6;
extern const sx_layout sx_p_alz_sizes7;
extern const sx_layout sx_p_alz_sizes8;
extern const sx_layout sx_p_ha_header;
extern const sx_layout sx_p_ha_file;
extern const sx_layout sx_p_ha_machine;
extern const sx_layout sx_p_zoo_header;
extern const sx_layout sx_p_zoo_directory;
extern const sx_layout sx_p_zoo_variable;
extern const sx_layout sx_p_lha_level0;
extern const sx_layout sx_p_lha_level1;
extern const sx_layout sx_p_lha_level2;
extern const sx_layout sx_p_lha_level3;
extern const sx_layout sx_p_lha_extension2;
extern const sx_layout sx_p_lha_extension4;
extern const sx_layout sx_p_lha_os;
extern const sx_layout sx_p_length32;
extern const sx_layout sx_p_zlib_header;
extern const sx_layout sx_p_zlib_dictionary;
extern const sx_layout sx_p_zlib_trailer;
extern const sx_layout sx_p_xar_header;
extern const sx_layout sx_p_rpm_lead;
extern const sx_layout sx_p_rpm_header;
extern const sx_layout sx_p_rpm_index;
extern const sx_layout sx_p_chm_itsf2;
extern const sx_layout sx_p_chm_itsf3;
extern const sx_layout sx_p_chm_itsp;
extern const sx_layout sx_p_chm_pmgl;
extern const sx_layout sx_p_chm_pmgi;
extern const sx_layout sx_p_chm_section0;
extern const sx_layout sx_p_tnef_header;
extern const sx_layout sx_p_tnef_attribute;
extern const sx_layout sx_p_tnef_checksum;
extern const sx_layout sx_p_wim_header;
extern const sx_layout sx_p_wim_resource;
extern const sx_layout sx_p_wim_boot;
extern const sx_layout sx_p_wim_blob;
extern const sx_layout sx_p_unix_compress_header;
extern const sx_layout sx_p_unix_pack_header;
extern const sx_layout sx_p_unix_pack_old_header;
extern const sx_layout sx_p_snappy_chunk;
extern const sx_layout sx_p_snappy_crc;
extern const sx_layout sx_p_mar_header;
extern const sx_layout sx_p_mar_index;
extern const sx_layout sx_p_mar_entry;
extern const sx_layout sx_p_pak_header4;
extern const sx_layout sx_p_pak_header5;
extern const sx_layout sx_p_pak_resource;
extern const sx_layout sx_p_pak_alias;
extern const sx_layout sx_p_xpak_header;
extern const sx_layout sx_p_xpak_codec;
extern const sx_layout sx_p_dvi_preamble;
extern const sx_layout sx_p_dvi_postamble;
extern const sx_layout sx_p_dvi_post_post;
extern const sx_layout sx_p_zoo_attributes;
extern const sx_layout sx_p_lha_unix_mode;
extern const sx_layout sx_p_lha_sizes64;
extern const sx_layout sx_p_mar_signed_header;
extern const sx_layout sx_p_mar_signature;
extern const sx_layout sx_p_mar_sections;
extern const sx_layout sx_p_mar_section;
extern const sx_layout sx_p_pack_tree;
extern const sx_layout sx_p_pack_level;
extern const sx_layout sx_p_pack_literal;
extern const sx_layout sx_p_dvi_page;
extern const sx_layout sx_p_pack_old_tree;
extern const sx_layout sx_p_pack_old_node;
extern const sx_layout sx_p_pack_old_wide_node;
bool sx_p_span(sx_context *c,uint64_t off,uint64_t size);
bool sx_p_sig(sx_context *c,int64_t off,const char *sig,size_t n);
bool sx_p_byte(sx_context *c,int64_t off,uint8_t *v);
bool sx_p_uint(sx_context *c,int64_t off,unsigned n,uint64_t *v);
bool sx_p_zstring(sx_context *c,int64_t *off,int64_t end);

/* Per-format walkers, called by the family's build. */
bool sx_arj_build(sx_context *c);  /* archive/arj/xx_arj_data.c */
bool sx_ace_build(sx_context *c);  /* archive/ace/xx_ace_data.c */
bool sx_alz_build(sx_context *c);  /* archive/alz/xx_alz_data.c */
bool sx_ha_build(sx_context *c);  /* archive/ha/xx_ha_data.c */
bool sx_zoo_build(sx_context *c);  /* archive/zoo/xx_zoo_data.c */
bool sx_lha_build(sx_context *c);  /* archive/lha/xx_lha_data.c */
bool sx_zlib_build(sx_context *c);  /* archive/zlib/xx_zlib_data.c */
bool sx_xar_build(sx_context *c);  /* archive/xar/xx_xar_data.c */
bool sx_rpm_build(sx_context *c);  /* installer/rpm/xx_rpm_data.c */
bool sx_chm_build(sx_context *c);  /* document/chm/xx_chm_data.c */
bool sx_tnef_build(sx_context *c);  /* document/tnef/xx_tnef_data.c */
bool sx_wim_build(sx_context *c);  /* archive/wim/xx_wim_data.c */
bool sx_unixcompress_build(sx_context *c);  /* archive/unixcompress/xx_unixcompress_data.c */
bool sx_unixpack_build(sx_context *c);  /* archive/unixpack/xx_unixpack_data.c */
bool sx_snappy_framed_build(sx_context *c);  /* archive/snappy_framed/xx_snappy_framed_data.c */
bool sx_mozilla_mar_build(sx_context *c);  /* installer/mozilla_mar/xx_mozilla_mar_data.c */
bool sx_chromium_pak_build(sx_context *c);  /* archive/chromium_pak/xx_chromium_pak_data.c */
bool sx_xpak_build(sx_context *c);  /* archive/xpak/xx_xpak_data.c */
bool sx_tex_dvi_build(sx_context *c);  /* document/tex_dvi/xx_tex_dvi_data.c */

#endif
