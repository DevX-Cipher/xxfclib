/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The nextmusic schema family: what its family unit (xx_format_schema_nextmusic.c)
 * and its formats' data files share. Formats: kleps_actionamicssoundtool; greatvalleyprod_digitalsoundstudio; beham_digitrekker_dtm; fujitsu_euphony_eup; wilenius_fmkingtracker; clermonte_frededitor_project; maxon_facethemusic; musiclineeditor; braintracedesign_synthesis; partl_voodoosupremesynthesizer; jch_edlibtracker_raw; meyrignac_pumatracker; gehrmann_soundcontrol_sct; urwani_soundfactory_psf; giesen_musicasm; clermonte_frededitor_final; reiniervanvliet_sidmon1. */
#ifndef XX_FORMAT_SCHEMA_NEXTMUSIC_H
#define XX_FORMAT_SCHEMA_NEXTMUSIC_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Read physical metadata without buffering whole sample or track payloads. */
typedef struct sxnextm_view {sx_context*c;unsigned work;}sxnextm_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxnextm_u8;
extern const sx_layout sxnextm_i8;
extern const sx_layout sxnextm_count16;
extern const sx_layout sxnextm_offset16;
extern const sx_layout sxnextm_bytes32;
extern const sx_layout sxnextm_track16;
extern const sx_layout sxnextm_order8;
extern const sx_layout sxnextm_chunk_le;
extern const sx_layout sxnextm_chunk_be;
extern const sx_layout sxnextm_ast_header;
extern const sx_layout sxnextm_ast_banner;
extern const sx_layout sxnextm_ast_module_size;
extern const sx_layout sxnextm_ast_instrument;
extern const sx_layout sxnextm_ast_subsong;
extern const sx_layout sxnextm_ast_sample;
extern const sx_layout sxnextm_dss_header;
extern const sx_layout sxnextm_dss_sample;
extern const sx_layout sxnextm_dss_event;
extern const sx_layout sxnextm_fred_header;
extern const sx_layout sxnextm_fred_track_length;
extern const sx_layout sxnextm_fred_instrument;
extern const sx_layout sxnextm_fred_sample;
extern const sx_layout sxnextm_fred_end;
extern const sx_layout sxnextm_dtm_info;
extern const sx_layout sxnextm_dtm_speed;
extern const sx_layout sxnextm_dtm_pan;
extern const sx_layout sxnextm_dtm_sample;
extern const sx_layout sxnextm_dtm_rows;
extern const sx_layout sxnextm_dtm_pitch;
extern const sx_layout sxnextm_dtm_instrument;
extern const sx_layout sxnextm_dtm_volume;
extern const sx_layout sxnextm_dtm_effect;
extern const sx_layout sxnextm_dtm_argument_high;
extern const sx_layout sxnextm_dtm_argument_low;
extern const sx_layout sxnextm_ftm_header;
extern const sx_layout sxnextm_ftm_sample;
extern const sx_layout sxnextm_ftm_script_header;
extern const sx_layout sxnextm_ftm_script_event;
extern const sx_layout sxnextm_eup_header;
extern const sx_layout sxnextm_eup_track_name;
extern const sx_layout sxnextm_eup_short_name;
extern const sx_layout sxnextm_eup_mute;
extern const sx_layout sxnextm_eup_port;
extern const sx_layout sxnextm_eup_channel;
extern const sx_layout sxnextm_eup_key_bias;
extern const sx_layout sxnextm_eup_transpose;
extern const sx_layout sxnextm_eup_filter;
extern const sx_layout sxnextm_eup_instrument_name;
extern const sx_layout sxnextm_eup_bank_names;
extern const sx_layout sxnextm_eup_application;
extern const sx_layout sxnextm_eup_event_header;
extern const sx_layout sxnextm_syn_header;
extern const sx_layout sxnextm_syn_sample_name;
extern const sx_layout sxnextm_syn_instrument;
extern const sx_layout sxnextm_syn_subsong;
extern const sx_layout sxnextm_syn_position;
extern const sx_layout sxnextm_syn_event;
extern const sx_layout sxnextm_d00_header;
extern const sx_layout sxnextm_offset16le;
extern const sx_layout sxnextm_offset32le;
extern const sx_layout sxnextm_offset32be;
extern const sx_layout sxnextm_d00_end;
extern const sx_layout sxnextm_d00_tracks;
extern const sx_layout sxnextm_d00_speed;
extern const sx_layout sxnextm_fmk_header;
extern const sx_layout sxnextm_fmk_track_setting;
extern const sx_layout sxnextm_fmk_instrument;
extern const sx_layout sxnextm_fmk_pattern;
extern const sx_layout sxnextm_fmk_control;
extern const sx_layout sxnextm_fmk_note;
extern const sx_layout sxnextm_fmk_volume;
extern const sx_layout sxnextm_fmk_effect;
extern const sx_layout sxnextm_sct_header;
extern const sx_layout sxnextm_sct_track;
extern const sx_layout sxnextm_sct_position;
extern const sx_layout sxnextm_sct_instrument;
extern const sx_layout sxnextm_sct_command;
extern const sx_layout sxnextm_sct_sample;
extern const sx_layout sxnextm_psf_header;
extern const sx_layout sxnextm_psf_channels;
extern const sx_layout sxnextm_vss_footer;
extern const sx_layout sxnextm_vss_song_offset;
extern const sx_layout sxnextm_vss_data_offset;
extern const sx_layout sxnextm_mle_magic;
extern const sx_layout sxnextm_mle_tune;
extern const sx_layout sxnextm_mle_sequence;
extern const sx_layout sxnextm_mle_index;
extern const sx_layout sxnextm_mle_part_control;
extern const sx_layout sxnextm_mle_part_note;
extern const sx_layout sxnextm_mle_effect;
extern const sx_layout sxnextm_mle_arpeggio;
extern const sx_layout sxnextm_mle_sample;
extern const sx_layout sxnextm_mle_instrument;
extern const sx_layout sxnextm_puma_header;
extern const sx_layout sxnextm_puma_position;
extern const sx_layout sxnextm_puma_marker;
extern const sx_layout sxnextm_puma_event;
extern const sx_layout sxnextm_puma_command;
extern const sx_layout sxnextm_ma_relative32;
extern const sx_layout sxnextm_ma_track_offset;
extern const sx_layout sxnextm_ma_subsong;
extern const sx_layout sxnextm_ma_position;
extern const sx_layout sxnextm_ma_speed;
extern const sx_layout sxnextm_ma_instrument;
extern const sx_layout sxnextm_ma_sample;
extern const sx_layout sxnextm_fred_final_header;
extern const sx_layout sxnextm_fred_final_subsong;
extern const sx_layout sxnextm_fred_final_position;
extern const sx_layout sxnextm_fred_final_control;
extern const sx_layout sxnextm_fred_final_instrument;
extern const sx_layout sxnextm_sid1_base_offset;
extern const sx_layout sxnextm_sid1_song;
extern const sx_layout sxnextm_sid1_sequence;
extern const sx_layout sxnextm_mle_tune_chunk;
bool sxnextm_span(sxnextm_view*v,uint64_t at,uint64_t n,uint64_t end);
bool sxnextm_read(sxnextm_view*v,uint64_t at,void*p,size_t n,uint64_t end);
bool sxnextm_row(sxnextm_view*v,const sx_layout*l,uint64_t at,uint64_t end);
bool sxnextm_table(sxnextm_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end);
bool sxnextm_u(sxnextm_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end);
bool sxnextm_be(sxnextm_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end);
bool sxnextm_eq(sxnextm_view*v,uint64_t p,const char*s,size_t n,uint64_t end);
bool sxnextm_text_emit(sxnextm_view*v,uint64_t p,uint64_t n,uint64_t end);
bool sxnextm_take(sxnextm_view*v,const sx_layout*l,uint64_t*p,uint64_t count,uint64_t end);
bool sxnextm_skip(sxnextm_view*v,uint64_t*p,uint64_t n,uint64_t end);
bool sxnextm_rel32(sxnextm_view*v,uint64_t word,uint64_t base,uint64_t*out,uint64_t end);
bool sxnextm_rel(sxnextm_view*v,uint64_t at,unsigned n,uint64_t base,uint64_t*out,uint64_t e);
bool sxnextm_find16(sxnextm_view*v,uint64_t*p,uint16_t word,uint64_t stop,uint64_t e);

/* Per-format walkers, called by the family's build. */
bool sx_kleps_actionamicssoundtool_build(sxnextm_view*v);  /* audio/die_music/kleps_actionamicssoundtool/xx_kleps_actionamicssoundtool_data.c */
bool sx_greatvalleyprod_digitalsoundstudio_build(sxnextm_view*v);  /* audio/die_music/greatvalleyprod_digitalsoundstudio/xx_greatvalleyprod_digitalsoundstudio_data.c */
bool sx_beham_digitrekker_dtm_build(sxnextm_view*v);  /* audio/die_music/beham_digitrekker_dtm/xx_beham_digitrekker_dtm_data.c */
bool sx_fujitsu_euphony_eup_build(sxnextm_view*v);  /* audio/die_music/fujitsu_euphony_eup/xx_fujitsu_euphony_eup_data.c */
bool sx_wilenius_fmkingtracker_build(sxnextm_view*v);  /* audio/die_music/wilenius_fmkingtracker/xx_wilenius_fmkingtracker_data.c */
bool sx_clermonte_frededitor_project_build(sxnextm_view*v);  /* audio/die_music/clermonte_frededitor_project/xx_clermonte_frededitor_project_data.c */
bool sx_maxon_facethemusic_build(sxnextm_view*v);  /* audio/die_music/maxon_facethemusic/xx_maxon_facethemusic_data.c */
bool sx_musiclineeditor_build(sxnextm_view*v);  /* audio/die_music/musiclineeditor/xx_musiclineeditor_data.c */
bool sx_braintracedesign_synthesis_build(sxnextm_view*v);  /* audio/die_music/braintracedesign_synthesis/xx_braintracedesign_synthesis_data.c */
bool sx_partl_voodoosupremesynthesizer_build(sxnextm_view*v);  /* audio/die_music/partl_voodoosupremesynthesizer/xx_partl_voodoosupremesynthesizer_data.c */
bool sx_jch_edlibtracker_raw_build(sxnextm_view*v);  /* audio/die_music/jch_edlibtracker_raw/xx_jch_edlibtracker_raw_data.c */
bool sx_meyrignac_pumatracker_build(sxnextm_view*v);  /* audio/die_music/meyrignac_pumatracker/xx_meyrignac_pumatracker_data.c */
bool sx_gehrmann_soundcontrol_sct_build(sxnextm_view*v);  /* audio/die_music/gehrmann_soundcontrol_sct/xx_gehrmann_soundcontrol_sct_data.c */
bool sx_urwani_soundfactory_psf_build(sxnextm_view*v);  /* audio/die_music/urwani_soundfactory_psf/xx_urwani_soundfactory_psf_data.c */
bool sx_giesen_musicasm_build(sxnextm_view*v);  /* audio/die_music/giesen_musicasm/xx_giesen_musicasm_data.c */
bool sx_clermonte_frededitor_final_build(sxnextm_view*v);  /* audio/die_music/clermonte_frededitor_final/xx_clermonte_frededitor_final_data.c */
bool sx_reiniervanvliet_sidmon1_build(sxnextm_view*v);  /* audio/die_music/reiniervanvliet_sidmon1/xx_reiniervanvliet_sidmon1_data.c */

#endif
