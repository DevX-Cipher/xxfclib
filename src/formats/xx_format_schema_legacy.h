/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The legacy schema family: what its family unit (xx_format_schema_legacy.c)
 * and its formats' data files share. Formats: MS-COMPRESS (SZDD/SZ); WII LZ77; ASH0; LZV1; ORACLE SQUEEZE; SOFTRONICS; GAS HUFF; HUF; LZDIET; LZPIS2; RNC; GNU gettext MO / Qt QM; ATARIST; PEF; ARTIPACK; ARCFS. */
#ifndef XX_FORMAT_SCHEMA_LEGACY_H
#define XX_FORMAT_SCHEMA_LEGACY_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxl_szdd_header;
extern const sx_layout sxl_sz_header;
extern const sx_layout sxl_imd5_header;
extern const sx_layout sxl_wii_lz77_tag;
extern const sx_layout sxl_wii_lz77_header;
extern const sx_layout sxl_wii_lz77_extended_size;
extern const sx_layout sxl_ash0_header;
extern const sx_layout sxl_lzv1_header;
extern const sx_layout sxl_oracle_squeeze_header;
extern const sx_layout sxl_squeeze_tree_header;
extern const sx_layout sxl_squeeze_tree_node;
extern const sx_layout sxl_softronics_header;
extern const sx_layout sxl_softronics_metadata;
extern const sx_layout sxl_gas_huff_header;
extern const sx_layout sxl_huf_header;
extern const sx_layout sxl_huf_symbol;
extern const sx_layout sxl_huf_directory;
extern const sx_layout sxl_lzdiet_header;
extern const sx_layout sxl_lzdiet_chunk;
extern const sx_layout sxl_lzdiet_table_end;
extern const sx_layout sxl_lzpis2_header;
extern const sx_layout sxl_lzpis2_chunk;
extern const sx_layout sxl_bullfrog_tag;
extern const sx_layout sxl_rnc_header;
extern const sx_layout sxl_mo_header_le;
extern const sx_layout sxl_mo_string_le;
extern const sx_layout sxl_mo_hash_le;
extern const sx_layout sxl_mo_header_be;
extern const sx_layout sxl_mo_string_be;
extern const sx_layout sxl_mo_hash_be;
extern const sx_layout sxl_qm_header;
extern const sx_layout sxl_qm_block;
extern const sx_layout sxl_qm_hash;
extern const sx_layout sxl_qm_message_field;
extern const sx_layout sxl_qm_message_end;
extern const sx_layout sxl_qm_message_obsolete;
extern const sx_layout sxl_atarist_header;
extern const sx_layout sxl_atarist_symbol;
extern const sx_layout sxl_pef_header;
extern const sx_layout sxl_pef_section;
extern const sx_layout sxl_pef_loader;
extern const sx_layout sxl_artipack_header;
extern const sx_layout sxl_artipack_directory;
extern const sx_layout sxl_artipack_size;
extern const sx_layout sxl_arcfs_header;
extern const sx_layout sxl_arcfs_directory;
bool sxl_span(sx_context *c,uint64_t o,uint64_t n);
bool sxl_sig(sx_context *c,int64_t o,const char *s,size_t n);
bool sxl_byte(sx_context *c,int64_t o,uint8_t *v);
bool sxl_name(sx_context *c,int64_t off,int64_t limit,int64_t *next);

/* Per-format walkers, called by the family's build. */
bool sx_mscompress_build(sx_context *c);  /* archive/mscompress/xx_mscompress_data.c */
bool sx_wiilz77_build(sx_context *c);  /* archive/wiilz77/xx_wiilz77_data.c */
bool sx_ash0_build(sx_context *c);  /* archive/ash0/xx_ash0_data.c */
bool sx_lzv1_build(sx_context *c);  /* archive/lzv1/xx_lzv1_data.c */
bool sx_oraclesqueeze_build(sx_context *c);  /* archive/oraclesqueeze/xx_oraclesqueeze_data.c */
bool sx_softronics_build(sx_context *c);  /* archive/softronics/xx_softronics_data.c */
bool sx_gashuff_build(sx_context *c);  /* archive/gashuff/xx_gashuff_data.c */
bool sx_huf_build(sx_context *c);  /* archive/huf/xx_huf_data.c */
bool sx_lzdiet_build(sx_context *c);  /* archive/lzdiet/xx_lzdiet_data.c */
bool sx_lzpis2_build(sx_context *c);  /* archive/lzpis2/xx_lzpis2_data.c */
bool sx_rnc_build(sx_context *c);  /* archive/rnc/xx_rnc_data.c */
bool sx_ue2_documents_schema_build(sx_context *c);  /* document/ue2_documents/xx_ue2_documents_schema_data.c */
bool sx_atarist_build(sx_context *c);  /* executable/atarist/xx_atarist_data.c */
bool sx_pef_build(sx_context *c);  /* executable/pef/xx_pef_data.c */
bool sx_artipack_build(sx_context *c);  /* archive/artipack/xx_artipack_data.c */
bool sx_arcfs_build(sx_context *c);  /* archive/arcfs/xx_arcfs_data.c */

#endif
