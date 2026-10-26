/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The image schema family: what its family unit (xx_format_schema_image.c)
 * and its formats' data files share. Formats: png; bmp; gif; ico; qoi; jpeg; tiff. */
#ifndef XX_FORMAT_SCHEMA_IMAGE_H
#define XX_FORMAT_SCHEMA_IMAGE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

typedef struct sxi_cursor {
    sx_context *context;
    int64_t start;
    size_t valid;
    uint8_t bytes[4096];
} sxi_cursor;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxi_png_signature;
extern const sx_layout sxi_png_chunk;
extern const sx_layout sxi_png_crc;
extern const sx_layout sxi_png_ihdr;
extern const sx_layout sxi_png_actl;
extern const sx_layout sxi_png_fctl;
extern const sx_layout sxi_png_fdat;
extern const sx_layout sxi_rgb;
extern const sx_layout sxi_png_phys;
extern const sx_layout sxi_png_gama;
extern const sx_layout sxi_png_chrm;
extern const sx_layout sxi_png_srgb;
extern const sx_layout sxi_png_time;
extern const sx_layout sxi_bmp_file;
extern const sx_layout sxi_bmp_core;
extern const sx_layout sxi_bmp_info;
extern const sx_layout sxi_bmp_v4;
extern const sx_layout sxi_bmp_v5;
extern const sx_layout sxi_bmp_rgbtriple;
extern const sx_layout sxi_bmp_rgbquad;
extern const sx_layout sxi_bmp_masks;
extern const sx_layout sxi_bmp_alpha_masks;
extern const sx_layout sxi_gif_header;
extern const sx_layout sxi_gif_screen;
extern const sx_layout sxi_gif_image;
extern const sx_layout sxi_gif_extension;
extern const sx_layout sxi_gif_graphic;
extern const sx_layout sxi_gif_application;
extern const sx_layout sxi_gif_text;
extern const sx_layout sxi_gif_subblock;
extern const sx_layout sxi_gif_lzw;
extern const sx_layout sxi_gif_trailer;
extern const sx_layout sxi_ico_header;
extern const sx_layout sxi_ico_entry;
extern const sx_layout sxi_cur_entry;
extern const sx_layout sxi_qoi_header;
extern const sx_layout sxi_qoi_end;
extern const sx_layout sxi_jpeg_marker;
extern const sx_layout sxi_jpeg_segment;
extern const sx_layout sxi_jpeg_frame;
extern const sx_layout sxi_jpeg_component;
extern const sx_layout sxi_jpeg_scan;
extern const sx_layout sxi_jpeg_scan_component;
extern const sx_layout sxi_jpeg_scan_tail;
extern const sx_layout sxi_jpeg_dri;
extern const sx_layout sxi_jpeg_jfif;
extern const sx_layout sxi_jpeg_dqt8;
extern const sx_layout sxi_jpeg_dqt16;
extern const sx_layout sxi_jpeg_dht;
extern const xx_data_struct_field_desc sxi_tiff_header_le_fields[3];
extern const sx_layout sxi_tiff_header_le;
extern const sx_layout sxi_tiff_header_be;
extern const sx_layout sxi_bigtiff_header_le;
extern const sx_layout sxi_bigtiff_header_be;
extern const sx_layout sxi_tiff_count_le;
extern const sx_layout sxi_tiff_count_be;
extern const sx_layout sxi_bigtiff_count_le;
extern const sx_layout sxi_bigtiff_count_be;
extern const sx_layout sxi_tiff_next_le;
extern const sx_layout sxi_tiff_next_be;
extern const sx_layout sxi_bigtiff_next_le;
extern const sx_layout sxi_bigtiff_next_be;
extern const sx_layout sxi_tiff_entry_inline_le;
extern const sx_layout sxi_tiff_entry_inline_be;
extern const sx_layout sxi_tiff_entry_offset_le;
extern const sx_layout sxi_tiff_entry_offset_be;
extern const sx_layout sxi_bigtiff_entry_inline_le;
extern const sx_layout sxi_bigtiff_entry_inline_be;
extern const sx_layout sxi_bigtiff_entry_offset_le;
extern const sx_layout sxi_bigtiff_entry_offset_be;
bool sx_image_range(const sx_context *c, int64_t at, uint64_t n);
bool sxi_byte(sxi_cursor *cursor, int64_t at, uint8_t *value);

/* Per-format walkers, called by the family's build. */
bool sx_png_build(sx_context *c);  /* image/png/xx_png_data.c */
bool sx_bmp_build(sx_context *c);  /* image/bmp/xx_bmp_data.c */
bool sx_gif_build(sx_context *c);  /* image/gif/xx_gif_data.c */
bool sx_ico_build(sx_context *c);  /* image/ico/xx_ico_data.c */
bool sx_qoi_build(sx_context *c);  /* image/qoi/xx_qoi_data.c */
bool sx_jpeg_build(sx_context *c);  /* image/jpeg/xx_jpeg_data.c */
bool sx_tiff_build(sx_context *c);  /* image/tiff/xx_tiff_data.c */

#endif
