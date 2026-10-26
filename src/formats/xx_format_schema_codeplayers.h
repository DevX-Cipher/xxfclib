/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The codeplayers schema family: what its family unit (xx_format_schema_codeplayers.c)
 * and its formats' data files share. Formats: bendaglish_bd; davidwhittaker_dw; walker_activisionpro. */
#ifndef XX_FORMAT_SCHEMA_CODEPLAYERS_H
#define XX_FORMAT_SCHEMA_CODEPLAYERS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Retained loaders authenticate metadata through these bounded instruction
 * forms. Instructions and runtime-only state are never emitted as fields. */
typedef struct{sx_context*c;uint64_t end;size_t code_size;uint8_t code[0x4000];unsigned work;}sxcodeplayers_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxcodeplayers_bd_subsong;
extern const sx_layout sxcodeplayers_bd_track_offset;
extern const sx_layout sxcodeplayers_bd_sample_offset;
extern const sx_layout sxcodeplayers_bd_sample;
extern const sx_layout sxcodeplayers_dw_speed;
extern const sx_layout sxcodeplayers_dw_delay_speed;
extern const sx_layout sxcodeplayers_dw_position_offset;
extern const sx_layout sxcodeplayers_dw_sample32;
extern const sx_layout sxcodeplayers_dw_sample_data;
extern const sx_layout sxcodeplayers_avp_subsong;
extern const sx_layout sxcodeplayers_avp_track_offset;
extern const sx_layout sxcodeplayers_avp_envelope;
extern const sx_layout sxcodeplayers_avp_instrument1;
extern const sx_layout sxcodeplayers_avp_instrument2;
extern const sx_layout sxcodeplayers_avp_instrument3;
extern const sx_layout sxcodeplayers_avp_sample_offset;
extern const sx_layout sxcodeplayers_avp_sample;
bool sxcodeplayers_span(sxcodeplayers_view*v,uint64_t p,uint64_t n);
bool sxcodeplayers_read(sxcodeplayers_view*v,uint64_t p,void*b,size_t n);
uint16_t sxcodeplayers_be16(const uint8_t*b);
bool sxcodeplayers_u(sxcodeplayers_view*v,uint64_t p,unsigned n,uint64_t*out);
bool sxcodeplayers_eq(sxcodeplayers_view*v,size_t p,const char*b,size_t n);
size_t sxcodeplayers_find(sxcodeplayers_view*v,size_t p,size_t end,const char*b,size_t n);
bool sxcodeplayers_ref(sxcodeplayers_view*v,size_t p,uint64_t*out);
bool sxcodeplayers_put(sxcodeplayers_view*v,const sx_layout*l,uint64_t p,uint64_t count);

/* Per-format walkers, called by the family's build. */
bool sx_bendaglish_bd_build(sxcodeplayers_view*v);  /* audio/die_music/bendaglish_bd/xx_bendaglish_bd_data.c */
bool sx_davidwhittaker_dw_build(sxcodeplayers_view*v);  /* audio/die_music/davidwhittaker_dw/xx_davidwhittaker_dw_data.c */
bool sx_walker_activisionpro_build(sxcodeplayers_view*v);  /* audio/die_music/walker_activisionpro/xx_walker_activisionpro_data.c */

#endif
