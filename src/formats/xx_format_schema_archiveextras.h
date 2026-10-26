/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archiveextras schema family: what its family unit (xx_format_schema_archiveextras.c)
 * and its formats' data files share. Formats: SEAARC; BSN; ARQ; GXL; RTA; SQZ; SQX; HAP; Microsoft KWAJ stream; ChArc archive; SWAG; ZPAK; ASYMETRIX; DiskExpress; AIN; AMIGALZX. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVEEXTRAS_H
#define XX_FORMAT_SCHEMA_ARCHIVEEXTRAS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxae_arc_member_old;
extern const sx_layout sxae_arc_member;
extern const sx_layout sxae_arc_end;
extern const sx_layout sxae_bsn_header;
extern const sx_layout sxae_bsn_member_prefix;
extern const sx_layout sxae_bsn_member_sizes;
extern const sx_layout sxae_bsn_end;
extern const sx_layout sxae_arq_container;
extern const sx_layout sxae_arq_member_prefix;
extern const sx_layout sxae_arq_member_tail;
extern const sx_layout sxae_gxl_header;
extern const sx_layout sxae_gxl_member;
extern const sx_layout sxae_rta_header;
extern const sx_layout sxae_rta_string_size;
extern const sx_layout sxae_rta_member;
extern const sx_layout sxae_rta_codec_header;
extern const sx_layout sxae_rta_end;
extern const sx_layout sxae_sqz_header;
extern const sx_layout sxae_sqz_member;
extern const sx_layout sxae_sqz_block;
extern const sx_layout sxae_sqz_block4;
extern const sx_layout sxae_sqz_comment;
extern const sx_layout sxae_sqz_end;
extern const sx_layout sxae_sqx_main;
extern const sx_layout sxae_sqx_record;
extern const sx_layout sxae_sqx_file32;
extern const sx_layout sxae_sqx_file64;
extern const sx_layout sxae_hap_header;
extern const sx_layout sxae_hap_member;
extern const sx_layout sxae_kwaj_header;
extern const sx_layout sxae_kwaj_unpacked_size;
extern const sx_layout sxae_kwaj_unknown;
extern const sx_layout sxae_kwaj_extension_size;
extern const sx_layout sxae_kwaj_mszip_block;
extern const sx_layout sxae_kwaj_mszip_end;
extern const sx_layout sxae_chz_file;
extern const sx_layout sxae_chz_directory;
extern const sx_layout sxae_chz_directory_end;
extern const sx_layout sxae_swag_member;
extern const sx_layout sxae_swag_member_crc;
extern const sx_layout sxae_swag_footer;
extern const sx_layout sxae_zpak_header;
extern const sx_layout sxae_zpak_member;
extern const sx_layout sxae_zpak_chunk_marker;
extern const sx_layout sxae_zpak_chunk;
extern const sx_layout sxae_asymetrix_header;
extern const sx_layout sxae_asymetrix_member;
extern const sx_layout sxae_asymetrix_block;
extern const sx_layout sxae_diskexpress_header;
extern const sx_layout sxae_diskexpress_track;
extern const sx_layout sxae_ain_header;
extern const sx_layout sxae_amigalzx_header;
extern const sx_layout sxae_amigalzx_member;
uint16_t sxae16(const uint8_t *b);
uint32_t sxae32(const uint8_t *b);
bool sxae_bound(sx_context *c,int64_t o,uint64_t n);
bool sxae_data(sx_context *c,int64_t o,uint64_t n);
bool sxae_add(sx_context *c,const sx_layout *l,int64_t o);

/* Per-format walkers, called by the family's build. */
bool sx_seaarc_build(sx_context *c);  /* archive/seaarc/xx_seaarc_data.c */
bool sx_bsn_build(sx_context *c);  /* archive/bsn/xx_bsn_data.c */
bool sx_arq_build(sx_context *c);  /* archive/arq/xx_arq_data.c */
bool sx_gxl_build(sx_context *c);  /* image/gxl/xx_gxl_data.c */
bool sx_rta_build(sx_context *c);  /* installer/rta/xx_rta_data.c */
bool sx_sqz_build(sx_context *c);  /* archive/sqz/xx_sqz_data.c */
bool sx_sqx_build(sx_context *c);  /* archive/sqx/xx_sqx_data.c */
bool sx_hap_build(sx_context *c);  /* archive/hap/xx_hap_data.c */
bool sx_kwaj_build(sx_context *c);  /* archive/kwaj/xx_kwaj_data.c */
bool sx_chz_build(sx_context *c);  /* archive/chz/xx_chz_data.c */
bool sx_swag_build(sx_context *c);  /* archive/swag/xx_swag_data.c */
bool sx_zpak_build(sx_context *c);  /* archive/zpak/xx_zpak_data.c */
bool sx_asymetrix_build(sx_context *c);  /* installer/asymetrix/xx_asymetrix_data.c */
bool sx_diskexpress_build(sx_context *c);  /* filesystem/diskexpress/xx_diskexpress_data.c */
bool sx_ain_build(sx_context *c);  /* archive/ain/xx_ain_data.c */
bool sx_amigalzx_build(sx_context *c);  /* archive/amigalzx/xx_amigalzx_data.c */

#endif
