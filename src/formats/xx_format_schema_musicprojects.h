/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The musicprojects schema family: what its family unit (xx_format_schema_musicprojects.c)
 * and its formats' data files share. Formats: nevo_arkostracker2; shiru_beepola; bleubleu_famistudio; liss_famitracker_ftm; tildearrow_furnacetracker; tildearrow_furnacetracker_fui; tildearrow_furnacetracker_fuw; muller_renoise_rns0; muller_renoise_xrdp; muller_renoise_xrno; muller_renoise_xrnt_unp; muller_renoise_xrnz. */
#ifndef XX_FORMAT_SCHEMA_MUSICPROJECTS_H
#define XX_FORMAT_SCHEMA_MUSICPROJECTS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Physical metadata uses bounded reads; compressed and unknown blocks stay raw. */
typedef struct sxmp_view {sx_context*c;uint64_t work;} sxmp_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxmp_famistudio_file_header;
extern const sx_layout sxmp_famitracker_file_header;
extern const sx_layout sxmp_famitracker_block_header;
extern const sx_layout sxmp_famitracker_end;
extern const sx_layout sxmp_famitracker_info;
extern const sx_layout sxmp_famitracker_parameters_v1;
extern const sx_layout sxmp_famitracker_parameters_v2;
extern const sx_layout sxmp_famitracker_parameters_v3;
extern const sx_layout sxmp_famitracker_parameters_v4;
extern const sx_layout sxmp_famitracker_parameters_v5;
extern const sx_layout sxmp_famitracker_parameters_v5_n163;
extern const sx_layout sxmp_famitracker_parameters_v6;
extern const sx_layout sxmp_famitracker_parameters_v6_n163;
extern const sx_layout sxmp_famitracker_parameters_v7;
extern const sx_layout sxmp_famitracker_parameters_v7_n163;
extern const sx_layout sxmp_famitracker_parameters_v8;
extern const sx_layout sxmp_famitracker_parameters_v8_n163;
extern const sx_layout sxmp_famitracker_parameters_v9;
extern const sx_layout sxmp_famitracker_parameters_v9_n163;
extern const sx_layout sxmp_famitracker_track_count;
extern const sx_layout sxmp_famitracker_channel_type;
extern const sx_layout sxmp_famitracker_effect_columns;
extern const sx_layout sxmp_music_project_name;
extern const sx_layout sxmp_renoise_legacy_text;
extern const sx_layout sxmp_beepola_header;
extern const sx_layout sxmp_beepola_section;
extern const sx_layout sxmp_beepola_property;
extern const sx_layout sxmp_beepola_property_value;
extern const sx_layout sxmp_beepola_count;
extern const sx_layout sxmp_beepola_loop_index;
extern const sx_layout sxmp_beepola_order;
extern const sx_layout sxmp_beepola_pattern_header;
extern const sx_layout sxmp_beepola_phaser_instrument;
extern const sx_layout sxmp_renoise_legacy_header;
extern const sx_layout sxmp_renoise_legacy_chunk_header;
extern const sx_layout sxmp_renoise_legacy_info_v0;
extern const sx_layout sxmp_renoise_legacy_string_length;
extern const sx_layout sxmp_beepola_row_count;
extern const sx_layout sxmp_beepola_channel_one_note;
extern const sx_layout sxmp_beepola_channel_two_note;
extern const sx_layout sxmp_beepola_drum;
extern const sx_layout sxmp_beepola_channel_one_sustain;
extern const sx_layout sxmp_beepola_channel_two_sustain;
extern const sx_layout sxmp_beepola_channel_one_warp;
extern const sx_layout sxmp_beepola_channel_two_warp;
extern const sx_layout sxmp_beepola_ornament_value;
extern const sx_layout sxmp_beepola_channel_one_glissando;
extern const sx_layout sxmp_beepola_channel_two_glissando;
extern const sx_layout sxmp_beepola_channel_one_skew;
extern const sx_layout sxmp_beepola_channel_two_skew;
extern const sx_layout sxmp_beepola_channel_one_skew_xor;
extern const sx_layout sxmp_beepola_channel_two_skew_xor;
extern const sx_layout sxmp_beepola_channel_one_arpeggio;
extern const sx_layout sxmp_beepola_channel_two_arpeggio;
extern const sx_layout sxmp_beepola_ornament_length;
bool sxmp_span(sxmp_view*v,uint64_t at,uint64_t z,uint64_t end);
bool sxmp_u(sxmp_view*v,uint64_t at,unsigned z,uint64_t*out,uint64_t end);
bool sxmp_eq(sxmp_view*v,uint64_t at,const char*s,size_t z,uint64_t end);
bool sxmp_emit(sxmp_view*v,const sx_layout*l,uint64_t at,uint64_t z,uint64_t end);
bool sxmp_row(sxmp_view*v,const sx_layout*l,uint64_t at,uint64_t end);
bool sxmp_table(sxmp_view*v,const sx_layout*l,uint64_t at,uint64_t n,uint64_t end);
bool sxmp_string(sxmp_view*v,const sx_layout*l,uint64_t*p,uint64_t end);
bool sxmp_furnace(sxmp_view*v,unsigned kind);
bool sxmp_xml(sxmp_view*v);

/* Per-format walkers, called by the family's build. */
bool sx_nevo_arkostracker2_build(sxmp_view*v);  /* audio/die_music/nevo_arkostracker2/xx_nevo_arkostracker2_data.c */
bool sx_shiru_beepola_build(sxmp_view*v);  /* audio/die_music/shiru_beepola/xx_shiru_beepola_data.c */
bool sx_bleubleu_famistudio_build(sxmp_view*v);  /* audio/die_music/bleubleu_famistudio/xx_bleubleu_famistudio_data.c */
bool sx_liss_famitracker_ftm_build(sxmp_view*v);  /* audio/die_music/liss_famitracker_ftm/xx_liss_famitracker_ftm_data.c */
bool sx_tildearrow_furnacetracker_build(sxmp_view*v);  /* audio/die_music/tildearrow_furnacetracker/xx_tildearrow_furnacetracker_data.c */
bool sx_tildearrow_furnacetracker_fui_build(sxmp_view*v);  /* audio/die_music/tildearrow_furnacetracker_fui/xx_tildearrow_furnacetracker_fui_data.c */
bool sx_tildearrow_furnacetracker_fuw_build(sxmp_view*v);  /* audio/die_music/tildearrow_furnacetracker_fuw/xx_tildearrow_furnacetracker_fuw_data.c */
bool sx_muller_renoise_rns0_build(sxmp_view*v);  /* audio/die_music/muller_renoise_rns0/xx_muller_renoise_rns0_data.c */
bool sx_muller_renoise_xrdp_build(sxmp_view*v);  /* audio/die_music/muller_renoise_xrdp/xx_muller_renoise_xrdp_data.c */
bool sx_muller_renoise_xrno_build(sxmp_view*v);  /* audio/die_music/muller_renoise_xrno/xx_muller_renoise_xrno_data.c */
bool sx_muller_renoise_xrnt_unp_build(sxmp_view*v);  /* audio/die_music/muller_renoise_xrnt_unp/xx_muller_renoise_xrnt_unp_data.c */
bool sx_muller_renoise_xrnz_build(sxmp_view*v);  /* audio/die_music/muller_renoise_xrnz/xx_muller_renoise_xrnz_data.c */

#endif
