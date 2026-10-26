/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The pcmusic schema family: what its family unit (xx_format_schema_pcmusic.c)
 * and its formats' data files share. Formats: DIE MUSIC CYBERBRAIN CYBERTRACKER; DIE MUSIC CYBERBRAIN CYBERTRACKER CI; DIE MUSIC DEFY ADLIBTRACKER DTM; DIE MUSIC TAYLOR FMTRACKER; DIE MUSIC XORJS FMTRACKER; DIE MUSIC PACKEN MUAP98 TONESDTA; DIE MUSIC BERO T0AST; DIE MUSIC BERO TOAST INS; DIE MUSIC KAHLIN VICTRACKER; DIE MUSIC KAJAPON PROFESSIONALMD M; DIE MUSIC PACKEN MUAP98 OBJECT; DIE MUSIC SPP BENITRACKERADLIB PIS; DIE MUSIC KANEDA MVSTRACKERSUITE MUS; DIE MUSIC RESOLUTION AXS; DIE MUSIC GNILK BEAVERSWEEPER GTK. */
#ifndef XX_FORMAT_SCHEMA_PCMUSIC_H
#define XX_FORMAT_SCHEMA_PCMUSIC_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxpcm_pc_text;
extern const sx_layout sxpcm_pc_u8_length;
extern const sx_layout sxpcm_pc_pattern_index;
extern const sx_layout sxpcm_pc_pattern_count;
extern const sx_layout sxpcm_pc_order_count;
extern const sx_layout sxpcm_pc_packed_pattern;
extern const sx_layout sxpcm_defy_header;
extern const sx_layout sxpcm_defy_instrument;
extern const sx_layout sxpcm_beni_header;
extern const sx_layout sxpcm_beni_pattern_map;
extern const sx_layout sxpcm_beni_instrument_map;
extern const sx_layout sxpcm_beni_event;
extern const sx_layout sxpcm_beni_instrument;
extern const sx_layout sxpcm_beni_version;
extern const sx_layout sxpcm_taylor_header;
extern const sx_layout sxpcm_taylor_instrument;
extern const sx_layout sxpcm_taylor_counts;
extern const sx_layout sxpcm_taylor_delay;
extern const sx_layout sxpcm_xorjs_header;
extern const sx_layout sxpcm_xorjs_instrument;
extern const sx_layout sxpcm_xorjs_event;
extern const sx_layout sxpcm_victracker_header;
extern const sx_layout sxpcm_victracker_song;
extern const sx_layout sxpcm_victracker_arpeggio;
extern const sx_layout sxpcm_victracker_arpeggio_config;
extern const sx_layout sxpcm_victracker_title;
extern const sx_layout sxpcm_victracker_sound;
extern const sx_layout sxpcm_victracker_sequence_length;
extern const sx_layout sxpcm_victracker_event;
extern const sx_layout sxpcm_pmd_header;
extern const sx_layout sxpcm_pmd_program_pointer;
extern const sx_layout sxpcm_pmd_memo_header;
extern const sx_layout sxpcm_pmd_memo_pointer;
extern const sx_layout sxpcm_victracker_reserved;
extern const sx_layout sxpcm_victracker_sequence;
extern const sx_layout sxpcm_mvs_header;
extern const sx_layout sxpcm_mvs_instrument;
extern const sx_layout sxpcm_mvs_event;
extern const sx_layout sxpcm_axs_form;
extern const sx_layout sxpcm_axs_chunk;
extern const sx_layout sxpcm_axs_settings;
extern const sx_layout sxpcm_axs_sequence;
extern const sx_layout sxpcm_axs_event;
extern const sx_layout sxpcm_beaver_synth_marker;
extern const sx_layout sxpcm_beaver_sample_flags;
extern const sx_layout sxpcm_beaver_sample_length;
extern const sx_layout sxpcm_beaver_sample_loop;
extern const sx_layout sxpcm_beaver_voice_count;
extern const sx_layout sxpcm_beaver_polyphony;
extern const sx_layout sxpcm_beaver_voice_range;
extern const sx_layout sxpcm_beaver_modulator_count;
extern const sx_layout sxpcm_beaver_oscillator_count;
extern const sx_layout sxpcm_beaver_insert_count;
extern const sx_layout sxpcm_beaver_type;
extern const sx_layout sxpcm_beaver_envelope;
extern const sx_layout sxpcm_beaver_lfo;
extern const sx_layout sxpcm_beaver_controller;
extern const sx_layout sxpcm_beaver_oscillator;
extern const sx_layout sxpcm_beaver_filter;
extern const sx_layout sxpcm_beaver_distortion;
extern const sx_layout sxpcm_beaver_delay;
extern const sx_layout sxpcm_beaver_chorus;
extern const sx_layout sxpcm_beaver_voice_modulation;
extern const sx_layout sxpcm_beaver_distortion_enabled;
extern const sx_layout sxpcm_beaver_arpeggio_enabled;
extern const sx_layout sxpcm_beaver_arpeggio_step;
extern const sx_layout sxpcm_beaver_arpeggio_timing;
extern const sx_layout sxpcm_beaver_mixer;
extern const sx_layout sxpcm_beaver_chain;
extern const sx_layout sxpcm_beaver_song_header;
extern const sx_layout sxpcm_beaver_channel_v102;
extern const sx_layout sxpcm_beaver_channel;
extern const sx_layout sxpcm_beaver_position_mask;
extern const sx_layout sxpcm_beaver_position_pattern;
extern const sx_layout sxpcm_beaver_position_transpose;
extern const sx_layout sxpcm_beaver_position_effect;
extern const sx_layout sxpcm_beaver_position_effect_parameter_1;
extern const sx_layout sxpcm_beaver_position_effect_parameter_2;
extern const sx_layout sxpcm_beaver_position_effect_parameter_3;
extern const sx_layout sxpcm_beaver_position_effect_parameter_4;
extern const sx_layout sxpcm_beaver_position_effect_parameter_5;
extern const sx_layout sxpcm_beaver_position_effect_parameter_6;
extern const sx_layout sxpcm_beaver_pattern_v102;
extern const sx_layout sxpcm_beaver_pattern;
extern const sx_layout sxpcm_beaver_pattern_row;
extern const sx_layout sxpcm_beaver_event;
bool sxpcm_span(sx_context*c,uint64_t p,uint64_t n);
bool sxpcm_read(sx_context*c,uint64_t p,void*b,size_t n);
uint16_t sxpcm16(const uint8_t*b);
bool sxpcm_u16(sx_context*c,uint64_t p,uint16_t*v);
bool sxpcm_u8(sx_context*c,uint64_t p,uint8_t*v);
bool sxpcm_eq(sx_context*c,uint64_t p,const char*s,size_t n);
uint64_t sxpcm_width(const sx_layout*l);
bool sxpcm_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count);
bool sxpcm_opt(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count);
bool sxpcm_text(sx_context*c,uint64_t p,uint64_t n);
bool sxpcm_u32(sx_context*c,uint64_t p,uint32_t*v);
bool sxpcm_cyber(sx_context*c,bool instrument);
bool sxpcm_muap(sx_context*c,bool tones);
bool sxpcm_toast(sx_context*c,bool instrument);

/* Per-format walkers, called by the family's build. */
bool sx_cyberbrain_cybertracker_build(sx_context *c);  /* audio/die_music/cyberbrain_cybertracker/xx_cyberbrain_cybertracker_data.c */
bool sx_cyberbrain_cybertracker_ci_build(sx_context *c);  /* audio/die_music/cyberbrain_cybertracker_ci/xx_cyberbrain_cybertracker_ci_data.c */
bool sx_defy_adlibtracker_dtm_build(sx_context *c);  /* audio/die_music/defy_adlibtracker_dtm/xx_defy_adlibtracker_dtm_data.c */
bool sx_taylor_fmtracker_build(sx_context *c);  /* audio/die_music/taylor_fmtracker/xx_taylor_fmtracker_data.c */
bool sx_xorjs_fmtracker_build(sx_context *c);  /* audio/die_music/xorjs_fmtracker/xx_xorjs_fmtracker_data.c */
bool sx_packen_muap98_tonesdta_build(sx_context *c);  /* audio/die_music/packen_muap98_tonesdta/xx_packen_muap98_tonesdta_data.c */
bool sx_bero_t0ast_build(sx_context *c);  /* audio/die_music/bero_t0ast/xx_bero_t0ast_data.c */
bool sx_bero_toast_ins_build(sx_context *c);  /* audio/die_music/bero_toast_ins/xx_bero_toast_ins_data.c */
bool sx_kahlin_victracker_build(sx_context *c);  /* audio/die_music/kahlin_victracker/xx_kahlin_victracker_data.c */
bool sx_kajapon_professionalmd_m_build(sx_context *c);  /* audio/die_music/kajapon_professionalmd_m/xx_kajapon_professionalmd_m_data.c */
bool sx_packen_muap98_object_build(sx_context *c);  /* audio/die_music/packen_muap98_object/xx_packen_muap98_object_data.c */
bool sx_spp_benitrackeradlib_pis_build(sx_context *c);  /* audio/die_music/spp_benitrackeradlib_pis/xx_spp_benitrackeradlib_pis_data.c */
bool sx_kaneda_mvstrackersuite_mus_build(sx_context *c);  /* audio/die_music/kaneda_mvstrackersuite_mus/xx_kaneda_mvstrackersuite_mus_data.c */
bool sx_resolution_axs_build(sx_context *c);  /* audio/die_music/resolution_axs/xx_resolution_axs_data.c */
bool sx_gnilk_beaversweeper_gtk_build(sx_context *c);  /* audio/die_music/gnilk_beaversweeper_gtk/xx_gnilk_beaversweeper_gtk_data.c */

#endif
