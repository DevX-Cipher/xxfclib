/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The pcedisks schema family: what its family unit (xx_format_schema_pcedisks.c)
 * and its formats' data files share. Formats: PCE PFDC (v0, v1, v2); PCE PBI. */
#ifndef XX_FORMAT_SCHEMA_PCEDISKS_H
#define XX_FORMAT_SCHEMA_PCEDISKS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sx_pc_pfdc_legacy_header;
extern const sx_layout sx_pc_pfdc_v2_header;
extern const sx_layout sx_pc_pfdc_v0_sector;
extern const sx_layout sx_pc_pfdc_v1_sector;
extern const sx_layout sx_pc_pfdc_v2_sector;
extern const sx_layout sx_pc_pfdc_v2_chunk;
extern const sx_layout sx_pc_pce_chunk_crc;
extern const sx_layout sx_pc_pfdc_file_crc;
extern const sx_layout sx_pc_pce_fill_byte;
extern const sx_layout sx_pc_pbi_header;
extern const sx_layout sx_pc_pbi_l1_entry;
extern const sx_layout sx_pc_pbi_l2_entry;
extern const sx_layout sx_pc_pbi_l2_fill;
bool sx_pc_span(sx_context *c,uint64_t at,uint64_t n);

/* Per-format walkers, called by the family's build. */
bool sx_pce_pfdc_build(sx_context *c);  /* filesystem/pce_pfdc/xx_pce_pfdc_data.c */
bool sx_pce_pbi_build(sx_context *c);  /* filesystem/pce_pbi/xx_pce_pbi_data.c */

#endif
