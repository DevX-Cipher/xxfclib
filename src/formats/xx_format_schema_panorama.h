/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The panorama schema family: what its family unit (xx_format_schema_panorama.c)
 * and its formats' data files share. Formats: Panorama. */
#ifndef XX_FORMAT_SCHEMA_PANORAMA_H
#define XX_FORMAT_SCHEMA_PANORAMA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxpano_signature;
extern const sx_layout sxpano_base_header;
extern const sx_layout sxpano_main_header;
extern const sx_layout sxpano_file_header;
extern const sx_layout sxpano_large_sizes;
extern const sx_layout sxpano_file_name;
extern const sx_layout sxpano_salt;
extern const sx_layout sxpano_long_block_size;
extern const sx_layout sxpano_end_data_crc;
extern const sx_layout sxpano_end_volume;
extern const sx_layout sxpano_comment_header;
extern const sx_layout sxpano_old_service_header;
extern const sx_layout sxpano_recovery_header;

/* Per-format walkers, called by the family's build. */
bool sx_panorama_schema_build(sx_context *c);  /* archive/panorama/xx_panorama_data.c */

#endif
