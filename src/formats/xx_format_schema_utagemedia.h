/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The utagemedia schema family: what its family unit (xx_format_schema_utagemedia.c)
 * and its formats' data files share. Formats: Utage media (modified-XOR). */
#ifndef XX_FORMAT_SCHEMA_UTAGEMEDIA_H
#define XX_FORMAT_SCHEMA_UTAGEMEDIA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxutg_png_signature;
extern const sx_layout sxutg_png_chunk;
extern const sx_layout sxutg_png_ihdr;
extern const sx_layout sxutg_png_crc;
extern const sx_layout sxutg_bmp_file;
extern const sx_layout sxutg_bmp_core;
extern const sx_layout sxutg_bmp_info;
extern const sx_layout sxutg_jpeg_marker;
extern const sx_layout sxutg_jpeg_segment;
extern const sx_layout sxutg_jpeg_frame;
extern const sx_layout sxutg_jpeg_frame_component;
extern const sx_layout sxutg_jpeg_scan;
extern const sx_layout sxutg_jpeg_scan_component;
extern const sx_layout sxutg_jpeg_scan_parameters;
extern const sx_layout sxutg_riff_webp;
extern const sx_layout sxutg_riff_chunk;
extern const sx_layout sxutg_webp_vp8x;
extern const sx_layout sxutg_webp_vp8l;
extern const sx_layout sxutg_webp_vp8;
extern const sx_layout sxutg_ogg_page;
extern const sx_layout sxutg_ogg_lacing;
extern const sx_layout sxutg_isobmff_box;
extern const sx_layout sxutg_isobmff_large_box;
extern const sx_layout sxutg_isobmff_ftyp;
extern const sx_layout sxutg_isobmff_brand;
extern const sx_layout sxutg_isobmff_uuid;

/* Per-format walkers, called by the family's build. */
bool sx_utage_media_build(sx_context *c);  /* game/ue2_games/xx_utage_media_data.c */

#endif
