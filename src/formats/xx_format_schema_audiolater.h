/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The audiolater schema family: what its family unit (xx_format_schema_audiolater.c)
 * and its formats' data files share. Formats: sfArk v2 compressed SoundFont; SFPack (.sfpack); AP4 audio packages. */
#ifndef XX_FORMAT_SCHEMA_AUDIOLATER_H
#define XX_FORMAT_SCHEMA_AUDIOLATER_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxaul_sfark_header;
extern const sx_layout sxaul_sfark_name_byte;
extern const sx_layout sxaul_sfark_text;
extern const sx_layout sxaul_sfpack_header;
extern const sx_layout sxaul_sfpack_chunk;
extern const sx_layout sxaul_sfpack_skip;
extern const sx_layout sxaul_sfpack_table;
extern const sx_layout sxaul_sfpack_offset;
extern const sx_layout sxaul_ap4_table;
extern const sx_layout sxaul_ap4_entry;
uint32_t sxaul_num(sx_context*c,int64_t at,unsigned width,bool be);
bool sxaul_take(sx_context*c,const sx_layout*l,int64_t*at,int64_t end,uint64_t count);
bool sxaul_skip(int64_t*at,int64_t end,uint64_t n);
bool sxaul_finish(sx_context *c);

/* Per-format walkers, called by the family's build. */
bool sx_sfark_compressed_soundfont_build(sx_context *c);  /* audio/sfark_compressed_soundfont/xx_sfark_compressed_soundfont_data.c */
bool sx_sfpack_build(sx_context *c);  /* audio/sfpack/xx_sfpack_data.c */
bool sx_ap4_build(sx_context *c);  /* audio/ap4/xx_ap4_data.c */

#endif
