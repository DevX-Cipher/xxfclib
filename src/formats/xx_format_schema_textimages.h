/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The textimages schema family: what its family unit (xx_format_schema_textimages.c)
 * and its formats' data files share. Formats: pnm; radiance_hdr; netpbm_pfm; jpeg2000_pgx; mtv_image; gimp_gih; gimp_gpl; gimp_ggr; jasc_palette; iridas_cube_lut; lut_spi1d; lut_spi3d; lut_cinespace_csp; unifont_hex; xpm; x11_xbm. */
#ifndef XX_FORMAT_SCHEMA_TEXTIMAGES_H
#define XX_FORMAT_SCHEMA_TEXTIMAGES_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Bounded physical tokens. Whitespace and unparsed bodies retain raw spans. */
typedef struct sxti_cursor {sx_context*c;uint8_t*b;int64_t n,p;} sxti_cursor;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxti_magic;
extern const sx_layout sxti_tuple_type;
extern const sx_layout sxti_axis_y;
extern const sx_layout sxti_axis_x;
extern const sx_layout sxti_placement;
extern const sx_layout sxti_selection;
extern const sx_layout sxti_color_key;
extern const sx_layout sxti_color_specification;
extern const sx_layout sxti_declaration_name;
extern const sx_layout sxti_define_name;
extern const sx_layout sxti_name;
extern const sx_layout sxti_metadata_text;
extern const sx_layout sxti_brush_name;
extern const sx_layout sxti_width;
extern const sx_layout sxti_height;
extern const sx_layout sxti_depth;
extern const sx_layout sxti_maxval;
extern const sx_layout sxti_color_count;
extern const sx_layout sxti_brush_count;
extern const sx_layout sxti_ncells;
extern const sx_layout sxti_cellwidth;
extern const sx_layout sxti_cellheight;
extern const sx_layout sxti_step;
extern const sx_layout sxti_dim;
extern const sx_layout sxti_cols;
extern const sx_layout sxti_rows;
extern const sx_layout sxti_rank0;
extern const sx_layout sxti_characters_per_pixel;
extern const sx_layout sxti_hotspot_x;
extern const sx_layout sxti_hotspot_y;
extern const sx_layout sxti_declared_bytes;
extern const sx_layout sxti_sample;
extern const sx_layout sxti_unicode_codepoint;
extern const sx_layout sxti_bitmap_byte;
extern const sx_layout sxti_sample_u8;
extern const sx_layout sxti_sample_u16_be;
extern const sx_layout sxti_gih_brush_header;
extern const sx_layout sxti_radiance_scanline_header;
extern const sx_layout sxti_radiance_run;
extern const sx_layout sxti_radiance_literal;
bool sxti_space(uint8_t x);
bool sxti_emit(sxti_cursor*q,const sx_layout*l,int64_t a,int64_t z);
bool sxti_token(sxti_cursor*q,int64_t end,int64_t*a,int64_t*z,bool comments);
bool sxti_value(sxti_cursor*q,const sx_layout*l,int64_t end,uint64_t*out);
bool sxti_line(sxti_cursor*q,int64_t*a,int64_t*end,bool comments);
bool sxti_eq(sxti_cursor*q,int64_t a,int64_t z,const char*s);
bool sxti_table(sxti_cursor*q,const sx_layout*l,int64_t at,int64_t width,uint64_t count);
bool sxti_simple_image(sxti_cursor*q,xx_file_type_t type);
bool sxti_palette(sxti_cursor*q,xx_file_type_t type);
bool sxti_lut(sxti_cursor*q,xx_file_type_t type);
bool sxti_cskip(sxti_cursor*q);

/* Per-format walkers, called by the family's build. */
bool sx_pnm_build(sxti_cursor*q);  /* image/pnm/xx_pnm_data.c */
bool sx_radiance_hdr_build(sxti_cursor*q);  /* image/radiance_hdr/xx_radiance_hdr_data.c */
bool sx_netpbm_pfm_build(sxti_cursor*q,xx_file_type_t type);  /* image/netpbm_pfm/xx_netpbm_pfm_data.c */
bool sx_jpeg2000_pgx_build(sxti_cursor*q,xx_file_type_t type);  /* image/jpeg2000_pgx/xx_jpeg2000_pgx_data.c */
bool sx_mtv_image_build(sxti_cursor*q,xx_file_type_t type);  /* image/mtv_image/xx_mtv_image_data.c */
bool sx_gimp_gih_build(sxti_cursor*q);  /* image/gimp_gih/xx_gimp_gih_data.c */
bool sx_gimp_gpl_build(sxti_cursor*q,xx_file_type_t type);  /* image/gimp_gpl/xx_gimp_gpl_data.c */
bool sx_gimp_ggr_build(sxti_cursor*q,xx_file_type_t type);  /* image/gimp_ggr/xx_gimp_ggr_data.c */
bool sx_jasc_palette_build(sxti_cursor*q,xx_file_type_t type);  /* image/jasc_palette/xx_jasc_palette_data.c */
bool sx_iridas_cube_lut_build(sxti_cursor*q,xx_file_type_t type);  /* image/iridas_cube_lut/xx_iridas_cube_lut_data.c */
bool sx_lut_spi1d_build(sxti_cursor*q,xx_file_type_t type);  /* image/lut_spi1d/xx_lut_spi1d_data.c */
bool sx_lut_spi3d_build(sxti_cursor*q,xx_file_type_t type);  /* image/lut_spi3d/xx_lut_spi3d_data.c */
bool sx_lut_cinespace_csp_build(sxti_cursor*q,xx_file_type_t type);  /* image/lut_cinespace_csp/xx_lut_cinespace_csp_data.c */
bool sx_unifont_hex_build(sxti_cursor*q);  /* font/unifont_hex/xx_unifont_hex_data.c */
bool sx_xpm_build(sxti_cursor*q);  /* image/xpm/xx_xpm_data.c */
bool sx_x11_xbm_build(sxti_cursor*q);  /* image/x11_xbm/xx_x11_xbm_data.c */

#endif
