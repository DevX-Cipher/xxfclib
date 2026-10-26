/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The amigamore schema family: what its family unit (xx_format_schema_amigamore.c)
 * and its formats' data files share. Formats: pink_pretracker_prt; richardjoseph_rjp_sng; thomashermann_thm; ronklaren_rk; robhubbard_rh; schmidt_suntronic; wallybeben; jeroentel. */
#ifndef XX_FORMAT_SCHEMA_AMIGAMORE_H
#define XX_FORMAT_SCHEMA_AMIGAMORE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Read physical metadata without buffering whole sample or track payloads. */
typedef struct sxamore_view {sx_context*c;unsigned work;}sxamore_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxamore_text;
extern const sx_layout sxamore_nul;
extern const sx_layout sxamore_original_address;
extern const sx_layout sxamore_signed_displacement;
extern const sx_layout sxamore_end_word;
extern const sx_layout sxamore_prt_header;
extern const sx_layout sxamore_prt_header30;
extern const sx_layout sxamore_prt_generation_order;
extern const sx_layout sxamore_prt_subsong_count;
extern const sx_layout sxamore_prt_subsong;
extern const sx_layout sxamore_prt_position;
extern const sx_layout sxamore_prt_pattern;
extern const sx_layout sxamore_prt_instrument_pattern;
extern const sx_layout sxamore_prt_instrument;
extern const sx_layout sxamore_prt_wave;
extern const sx_layout sxamore_thm_header;
extern const sx_layout sxamore_thm_order;
extern const sx_layout sxamore_thm_sample;
extern const sx_layout sxamore_rh_sample_count;
extern const sx_layout sxamore_rh_sample;
extern const sx_layout sxamore_rh_subsong;
extern const sx_layout sxamore_jt_subsong;
extern const sx_layout sxamore_jt_sample;
extern const sx_layout sxamore_wb_subsong;
extern const sx_layout sxamore_wb_count;
extern const sx_layout sxamore_sun_initial_channels;
extern const sx_layout sxamore_rk_hunk_header;
extern const sx_layout sxamore_rk_jump;
extern const sx_layout sxamore_rk_selector;
extern const sx_layout sxamore_rk_subsong;
extern const sx_layout sxamore_rk_position;
extern const sx_layout sxamore_rk_position_end;
extern const sx_layout sxamore_rk_cia_write;
extern const sx_layout sxamore_rk_vector_write;
extern const sx_layout sxamore_rjp_header;
extern const sx_layout sxamore_rjp_section;
extern const sx_layout sxamore_rjp_sample;
extern const sx_layout sxamore_rjp_subsong;
extern const sx_layout sxamore_rjp_position_offset;
extern const sx_layout sxamore_rjp_step_offset;
extern const sx_layout sxamore_rk_index_extension;
extern const sx_layout sxamore_sun_end;
bool sxamore_span(sxamore_view*v,uint64_t at,uint64_t n,uint64_t end);
bool sxamore_row(sxamore_view*v,const sx_layout*l,uint64_t at,uint64_t end);
bool sxamore_table(sxamore_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end);
bool sxamore_be(sxamore_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end);
bool sxamore_eq(sxamore_view*v,uint64_t p,const char*s,size_t n,uint64_t end);
bool sxamore_take(sxamore_view*v,const sx_layout*l,uint64_t*p,uint64_t count,uint64_t end);
bool sxamore_signed16(sxamore_view*v,uint64_t at,uint64_t base,uint64_t*out,uint64_t end);
bool sxamore_find(sxamore_view*v,uint64_t*at,uint64_t end,uint64_t pattern,unsigned width,unsigned step);
bool sxamore_map(uint64_t address,uint64_t origin,uint64_t end,uint64_t*out);

/* Per-format walkers, called by the family's build. */
bool sx_pink_pretracker_prt_build(sxamore_view*v);  /* audio/die_music/pink_pretracker_prt/xx_pink_pretracker_prt_data.c */
bool sx_richardjoseph_rjp_sng_build(sxamore_view*v);  /* audio/die_music/richardjoseph_rjp_sng/xx_richardjoseph_rjp_sng_data.c */
bool sx_thomashermann_thm_build(sxamore_view*v);  /* audio/die_music/thomashermann_thm/xx_thomashermann_thm_data.c */
bool sx_ronklaren_rk_build(sxamore_view*v);  /* audio/die_music/ronklaren_rk/xx_ronklaren_rk_data.c */
bool sx_robhubbard_rh_build(sxamore_view*v);  /* audio/die_music/robhubbard_rh/xx_robhubbard_rh_data.c */
bool sx_schmidt_suntronic_build(sxamore_view*v);  /* audio/die_music/schmidt_suntronic/xx_schmidt_suntronic_data.c */
bool sx_wallybeben_build(sxamore_view*v);  /* audio/die_music/wallybeben/xx_wallybeben_data.c */
bool sx_jeroentel_build(sxamore_view*v);  /* audio/die_music/jeroentel/xx_jeroentel_data.c */

#endif
