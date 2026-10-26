/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The fontbinary schema family: what its family unit (xx_format_schema_fontbinary.c)
 * and its formats' data files share. Formats: nintendo bfnt; nintendo bcfnt; font windows fnt; font gem fnt; tex tfm; tex pk; tex gf; tex vf. */
#ifndef XX_FORMAT_SCHEMA_FONTBINARY_H
#define XX_FORMAT_SCHEMA_FONTBINARY_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxfb_windows_fnt2_header;
extern const sx_layout sxfb_windows_fnt3_header;
extern const sx_layout sxfb_windows_fnt2_glyph;
extern const sx_layout sxfb_windows_fnt3_glyph;
extern const sx_layout sxfb_gem_font_header_le;
extern const sx_layout sxfb_gem_glyph_bit_position_le;
extern const sx_layout sxfb_gem_font_header_be;
extern const sx_layout sxfb_gem_glyph_bit_position_be;
extern const sx_layout sxfb_gem_horizontal_offsets;
extern const sx_layout sxfb_tfm_counts;
extern const sx_layout sxfb_tfm_header;
extern const sx_layout sxfb_tfm_coding_scheme;
extern const sx_layout sxfb_tfm_family;
extern const sx_layout sxfb_tfm_face;
extern const sx_layout sxfb_tfm_character;
extern const sx_layout sxfb_tfm_width;
extern const sx_layout sxfb_tfm_height;
extern const sx_layout sxfb_tfm_depth;
extern const sx_layout sxfb_tfm_italic;
extern const sx_layout sxfb_tfm_kern;
extern const sx_layout sxfb_tfm_parameter;
extern const sx_layout sxfb_tfm_ligature_kern;
extern const sx_layout sxfb_tfm_extensible_recipe;
extern const sx_layout sxfb_pk_metrics;
extern const sx_layout sxfb_pk_short_glyph;
extern const sx_layout sxfb_pk_extended_glyph;
extern const sx_layout sxfb_pk_long_glyph;
extern const sx_layout sxfb_tex_opcode;
extern const sx_layout sxfb_tex_numeric_special;
extern const sx_layout sxfb_gf_boc;
extern const sx_layout sxfb_gf_boc1;
extern const sx_layout sxfb_gf_paint1;
extern const sx_layout sxfb_gf_skip1;
extern const sx_layout sxfb_gf_paint2;
extern const sx_layout sxfb_gf_skip2;
extern const sx_layout sxfb_gf_paint3;
extern const sx_layout sxfb_gf_skip3;
extern const sx_layout sxfb_gf_post;
extern const sx_layout sxfb_gf_char_loc;
extern const sx_layout sxfb_gf_char_loc0;
extern const sx_layout sxfb_gf_postpost;
extern const sx_layout sxfb_vf_metrics;
extern const sx_layout sxfb_vf_font_definition1;
extern const sx_layout sxfb_vf_font_definition2;
extern const sx_layout sxfb_vf_font_definition3;
extern const sx_layout sxfb_vf_font_definition4;
extern const sx_layout sxfb_vf_short_packet;
extern const sx_layout sxfb_vf_long_packet;
bool sxfb_span(sx_context *c,uint64_t p,uint64_t n);
bool sxfb_read(sx_context *c,uint64_t p,void *b,size_t n);
uint16_t sxfb16(const uint8_t *b,bool be);
uint32_t sxfb32(const uint8_t *b,bool be);
bool sxfb_add(sx_context *c,const sx_layout *l,uint64_t p);
bool sxfb_nintendo(sx_context *c,bool be);
bool sxfb_special(sx_context *c,uint64_t *p,unsigned width);
bool sxfb_preamble(sx_context *c,unsigned id,uint64_t *p);

/* Per-format walkers, called by the family's build. */
bool sx_nintendo_bfnt_build(sx_context *c);  /* font/nintendo_bfnt/xx_nintendo_bfnt_data.c */
bool sx_nintendo_bcfnt_build(sx_context *c);  /* font/nintendo_bcfnt/xx_nintendo_bcfnt_data.c */
bool sx_font_windows_fnt_build(sx_context *c);  /* font/font_windows_fnt/xx_font_windows_fnt_data.c */
bool sx_font_gem_fnt_build(sx_context *c);  /* font/font_gem_fnt/xx_font_gem_fnt_data.c */
bool sx_tex_tfm_build(sx_context *c);  /* font/tex_tfm/xx_tex_tfm_data.c */
bool sx_tex_pk_build(sx_context *c);  /* font/tex_pk/xx_tex_pk_data.c */
bool sx_tex_gf_build(sx_context *c);  /* font/tex_gf/xx_tex_gf_data.c */
bool sx_tex_vf_build(sx_context *c);  /* font/tex_vf/xx_tex_vf_data.c */

#endif
