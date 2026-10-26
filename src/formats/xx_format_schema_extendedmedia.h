/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The extendedmedia schema family: what its family unit (xx_format_schema_extendedmedia.c)
 * and its formats' data files share. Formats: nintendo sdat. */
#ifndef XX_FORMAT_SCHEMA_EXTENDEDMEDIA_H
#define XX_FORMAT_SCHEMA_EXTENDEDMEDIA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxem_nw_block_le;
extern const sx_layout sxem_sdat_header;
extern const sx_layout sxem_nitro_header;
extern const sx_layout sxem_sdat_directory;
extern const sx_layout sxem_sdat_count;
extern const sx_layout sxem_sdat_offset;
extern const sx_layout sxem_sdat_archive_symbol;
extern const sx_layout sxem_sdat_sequence;
extern const sx_layout sxem_sdat_file_reference;
extern const sx_layout sxem_sdat_bank;
extern const sx_layout sxem_sdat_player;
extern const sx_layout sxem_sdat_group_entry;
extern const sx_layout sxem_sdat_stream_player;
extern const sx_layout sxem_sdat_stream;
extern const sx_layout sxem_sdat_fat_entry;
extern const sx_layout sxem_sdat_file_header;
bool sxem_read(sx_context *c,uint64_t at,void *b,size_t n);
bool sxem_add(sx_context *c,const sx_layout *l,uint64_t at,uint64_t n);
bool sxem_table(sx_context *c,const sx_layout *l,uint64_t at,uint64_t stride,uint64_t count);
bool sxem_u32(sx_context *c,uint64_t at,bool be,uint32_t *v);
bool sxem_block(sx_context *c,uint64_t at,uint64_t size,uint64_t total,bool be,const char *magic);

/* Per-format walkers, called by the family's build. */
bool sx_nintendo_sdat_build(sx_context *c);  /* audio/nintendo_sdat/xx_nintendo_sdat_data.c */

#endif
