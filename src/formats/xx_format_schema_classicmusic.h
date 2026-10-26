/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The classicmusic schema family: what its family unit (xx_format_schema_classicmusic.c)
 * and its formats' data files share. Formats: Jochen 'Mad Max' Hippel's module (.HIP7,.S7G); Jochen 'Mad Max' Hippel's module (.HIPC); Jochen 'Mad Max' Hippel's Atari ST module (.HST,.SOC,.SOG); Jess D. 'Razmo' Skov-Nielsen's Kefrens Sound Machine module (.KSM); DIE MUSIC HULSBECK THEFINALMUSICSYSTEMEXTENDED. */
#ifndef XX_FORMAT_SCHEMA_CLASSICMUSIC_H
#define XX_FORMAT_SCHEMA_CLASSICMUSIC_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxcmus_kefrens_header;
extern const sx_layout sxcmus_kefrens_sample;
extern const sx_layout sxcmus_kefrens_order;
extern const sx_layout sxcmus_kefrens_end;
extern const sx_layout sxcmus_kefrens_cell;
extern const sx_layout sxcmus_tfmx_tfhd;
extern const sx_layout sxcmus_tfmx_mod_wrapper;
extern const sx_layout sxcmus_tfmx_prefix;
extern const sx_layout sxcmus_tfmx_comment;
extern const sx_layout sxcmus_tfmx_song_start;
extern const sx_layout sxcmus_tfmx_song_end;
extern const sx_layout sxcmus_tfmx_song_tempo;
extern const sx_layout sxcmus_tfmx_track_mute;
extern const sx_layout sxcmus_tfmx_tables_be;
extern const sx_layout sxcmus_tfmx_tables_le;
extern const sx_layout sxcmus_tfmx_pointer;
extern const sx_layout sxcmus_tfmx_track_channel;
extern const sx_layout sxcmus_tfmx_track_command;
extern const sx_layout sxcmus_tfmx_mod_tag;
bool sxcmus_span(sx_context*c,uint64_t p,uint64_t n);
bool sxcmus_read(sx_context*c,uint64_t p,void*b,size_t n);
bool sxcmus_eq(sx_context*c,uint64_t p,const char*s,size_t n);
bool sxcmus_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count);
uint32_t sxcmus_be32(const uint8_t*b);
bool sxcmus_word(sx_context*c,uint64_t p,uint16_t*v);
bool sxcmus_hippel(sx_context*c,unsigned kind);

/* Per-format walkers, called by the family's build. */
bool sx_hippel_7_build(sx_context *c);  /* audio/die_music/hippel_7/xx_hippel_7_data.c */
bool sx_hippel_co_build(sx_context *c);  /* audio/die_music/hippel_co/xx_hippel_co_data.c */
bool sx_hippel_st_build(sx_context *c);  /* audio/die_music/hippel_st/xx_hippel_st_data.c */
bool sx_razmo_kefrenssoundmachine_build(sx_context *c);  /* audio/die_music/razmo_kefrenssoundmachine/xx_razmo_kefrenssoundmachine_data.c */
bool sx_hulsbeck_thefinalmusicsystemextended_build(sx_context *c);  /* audio/die_music/hulsbeck_thefinalmusicsystemextended/xx_hulsbeck_thefinalmusicsystemextended_data.c */

#endif
