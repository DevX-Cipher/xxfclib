/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The modvariants schema family: what its family unit (xx_format_schema_modvariants.c)
 * and its formats' data files share. Formats: azatoth_phapacker; digitalillusionscreativeent_di; obi_soundtracker_stk; southern_magneticfieldspacker. */
#ifndef XX_FORMAT_SCHEMA_MODVARIANTS_H
#define XX_FORMAT_SCHEMA_MODVARIANTS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Stored big-endian MOD variants. Native identity is a prerequisite, and all
 * physical spans below are checked again before being declared. */
typedef struct sxmodv_view {sx_context*c;uint64_t end;unsigned work;}sxmodv_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxmodv_di_header;
extern const sx_layout sxmodv_mod_compact_sample;
extern const sx_layout sxmodv_di_pattern_offset;
extern const sx_layout sxmodv_mod_order;
extern const sx_layout sxmodv_di_orders_end;
extern const sx_layout sxmodv_di_blank;
extern const sx_layout sxmodv_di_event;
extern const sx_layout sxmodv_di_event_value;
extern const sx_layout sxmodv_pha_sample;
extern const sx_layout sxmodv_pha_control;
extern const sx_layout sxmodv_pha_pattern_offset;
extern const sx_layout sxmodv_soundtracker_title;
extern const sx_layout sxmodv_soundtracker_sample;
extern const sx_layout sxmodv_soundtracker_controls;
extern const sx_layout sxmodv_soundtracker_cell;
extern const sx_layout sxmodv_mfp_controls;
extern const sx_layout sxmodv_mfp_counts;
extern const sx_layout sxmodv_mfp_channels;
bool sxmodv_span(sxmodv_view*v,uint64_t p,uint64_t n);
bool sxmodv_word(sxmodv_view*v,uint64_t p,unsigned n,uint64_t*x);
bool sxmodv_row(sxmodv_view*v,const sx_layout*l,uint64_t p);

/* Per-format walkers, called by the family's build. */
bool sx_azatoth_phapacker_build(sxmodv_view*v);  /* audio/die_music/azatoth_phapacker/xx_azatoth_phapacker_data.c */
bool sx_digitalillusionscreativeent_di_build(sxmodv_view*v);  /* audio/die_music/digitalillusionscreativeent_di/xx_digitalillusionscreativeent_di_data.c */
bool sx_obi_soundtracker_stk_build(sxmodv_view*v);  /* audio/die_music/obi_soundtracker_stk/xx_obi_soundtracker_stk_data.c */
bool sx_southern_magneticfieldspacker_build(sxmodv_view*v);  /* audio/die_music/southern_magneticfieldspacker/xx_southern_magneticfieldspacker_data.c */

#endif
