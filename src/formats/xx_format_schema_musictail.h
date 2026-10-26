/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The musictail schema family: what its family unit (xx_format_schema_musictail.c)
 * and its formats' data files share. Formats: Bastian 'Twice' Spiegel's Art of Noise/Chorus module (.AON); Reinier 'Rhino' van Vliet's Digital Mugician module (.DMU,.MUG); Laurent 'Dumbo' de Soras's Graoumf Tracker module (.GTK); Laurent 'Dumbo' de Soras's Graoumf Tracker 2 module (.GT2); Jazz Jackrabbit 2/Galaxy Sound System module (.J2B); Jazz Jackrabbit 2 container (.J2B)/Galaxy Sound System module; Patrick Meng's Symphonie module (.SYMMOD); Oregan Developments' Digital Symphony module (.DSYM); Gemmel & Xag/Betrayal's JamCracker/Pro module (.JAM,.JC); Brian Postma's SoundMon module (.BP); Anders 'AN Cool' Nilsson's TCB Tracker module (.TCB); Thomas 'Tran' Pytel's CDFM/Composer 670 module (.C67); Otto Chrons/libmikmod UNIMOD/UNITRK module (.UNI); Hans Bergstedt's Sound Invasion Music System/In Stereo! module (.IS); Hans Bergstedt's Sound Invasion Music System/In Stereo! module (.IS20); Teijo Kinnunen's OctaMED module (.MED); Andreas Fuchs's FuchsTracker module (.FUCHS); Andreas Tadic's Game Music Creator module (.GMC); Krister Wombell's ChipTracker module (.KRIS,.MOD); Michael Kleps's SIDMon II MIDI module (.SID2). */
#ifndef XX_FORMAT_SCHEMA_MUSICTAIL_H
#define XX_FORMAT_SCHEMA_MUSICTAIL_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Read physical metadata without buffering whole sample or track payloads. */
typedef struct sxmta_view {sx_context*c;unsigned work;}sxmta_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxmta_pascal_text_length;
extern const sx_layout sxmta_text_length16;
extern const sx_layout sxmta_order8;
extern const sx_layout sxmta_order16be;
extern const sx_layout sxmta_order16le;
extern const sx_layout sxmta_count16be;
extern const sx_layout sxmta_volume8;
extern const sx_layout sxmta_pan16be;
extern const sx_layout sxmta_gtk_header;
extern const sx_layout sxmta_gtk_sample1;
extern const sx_layout sxmta_gtk_sample2;
extern const sx_layout sxmta_gtk_sample3;
extern const sx_layout sxmta_gtk_event4;
extern const sx_layout sxmta_gtk_event5;
extern const sx_layout sxmta_gt2_header_new;
extern const sx_layout sxmta_gt2_header_old;
extern const sx_layout sxmta_gt2_chunk;
extern const sx_layout sxmta_gt2_song;
extern const sx_layout sxmta_gt2_pattern;
extern const sx_layout sxmta_gt2_track_name;
extern const sx_layout sxmta_gt2_timing;
extern const sx_layout sxmta_gt2_period_mode;
extern const sx_layout sxmta_gt2_sample1;
extern const sx_layout sxmta_gt2_sample2;
extern const sx_layout sxmta_gt2_instrument;
extern const sx_layout sxmta_gt2_note_map;
extern const sx_layout sxmta_tcb_header;
extern const sx_layout sxmta_tcb_amiga_flag;
extern const sx_layout sxmta_tcb_instrument_name;
extern const sx_layout sxmta_tcb_special;
extern const sx_layout sxmta_tcb_event;
extern const sx_layout sxmta_tcb_sample_area;
extern const sx_layout sxmta_tcb_sample_properties;
extern const sx_layout sxmta_tcb_sample_location;
extern const sx_layout sxmta_gmc_sample;
extern const sx_layout sxmta_gmc_orders;
extern const sx_layout sxmta_gmc_pattern_offset;
extern const sx_layout sxmta_gmc_event;
extern const sx_layout sxmta_fuchs_event;
extern const sx_layout sxmta_kris_title;
extern const sx_layout sxmta_kris_sample;
extern const sx_layout sxmta_kris_synth;
extern const sx_layout sxmta_kris_header;
extern const sx_layout sxmta_kris_track_ref;
extern const sx_layout sxmta_kris_event;
extern const sx_layout sxmta_c67_header;
extern const sx_layout sxmta_c67_name;
extern const sx_layout sxmta_c67_sample;
extern const sx_layout sxmta_c67_fm_instrument;
extern const sx_layout sxmta_c67_pattern_offset;
extern const sx_layout sxmta_c67_pattern_bytes;
extern const sx_layout sxmta_dsym_header;
extern const sx_layout sxmta_dsym_sample_flags;
extern const sx_layout sxmta_dsym_sample_words;
extern const sx_layout sxmta_dsym_commands;
extern const sx_layout sxmta_dsym_packing;
extern const sx_layout sxmta_dsym_sample;
extern const sx_layout sxmta_dsym_event;
extern const sx_layout sxmta_sym_header;
extern const sx_layout sxmta_sym_value;
extern const sx_layout sxmta_sym_count;
extern const sx_layout sxmta_sym_bytes;
extern const sx_layout sxmta_sym_empty_sample;
extern const sx_layout sxmta_gt2_volume;
extern const sx_layout sxmta_aon_arpeggio;
extern const sx_layout sxmta_aon_header;
extern const sx_layout sxmta_aon_chunk;
extern const sx_layout sxmta_aon_info;
extern const sx_layout sxmta_aon_sample;
extern const sx_layout sxmta_aon_synth;
extern const sx_layout sxmta_aon_event;
extern const sx_layout sxmta_aon_wave_length;
extern const sx_layout sxmta_aon_instrument_name;
extern const sx_layout sxmta_dmu_header;
extern const sx_layout sxmta_dmu_subsong;
extern const sx_layout sxmta_dmu_sequence;
extern const sx_layout sxmta_dmu_instrument;
extern const sx_layout sxmta_dmu_sample;
extern const sx_layout sxmta_dmu_event;
extern const sx_layout sxmta_jam_header;
extern const sx_layout sxmta_jam_sample;
extern const sx_layout sxmta_jam_pattern;
extern const sx_layout sxmta_jam_event;
extern const sx_layout sxmta_bp_header;
extern const sx_layout sxmta_bp_sample;
extern const sx_layout sxmta_bp_synth1;
extern const sx_layout sxmta_bp_synth2;
extern const sx_layout sxmta_bp_step;
extern const sx_layout sxmta_bp_event;
extern const sx_layout sxmta_fuchs_header;
extern const sx_layout sxmta_fuchs_sample_bytes;
extern const sx_layout sxmta_fuchs_volume;
extern const sx_layout sxmta_fuchs_loop;
extern const sx_layout sxmta_fuchs_order_count;
extern const sx_layout sxmta_fuchs_pattern_chunk;
extern const sx_layout sxmta_fuchs_samples_marker;
extern const sx_layout sxmta_sid2_header;
extern const sx_layout sxmta_sid2_track_number;
extern const sx_layout sxmta_sid2_transpose;
extern const sx_layout sxmta_sid2_track_offset;
extern const sx_layout sxmta_sid2_instrument;
extern const sx_layout sxmta_sid2_sample;
extern const sx_layout sxmta_med2_header;
extern const sx_layout sxmta_med2_name;
extern const sx_layout sxmta_med2_loop_start;
extern const sx_layout sxmta_med2_loop_bytes;
extern const sx_layout sxmta_med2_song;
extern const sx_layout sxmta_med2_pattern_header;
extern const sx_layout sxmta_med2_event;
extern const sx_layout sxmta_uni4_header;
extern const sx_layout sxmta_uni5_header;
extern const sx_layout sxmta_uni6_header;
extern const sx_layout sxmta_apun_header;
extern const sx_layout sxmta_uni_bpm_limit;
extern const sx_layout sxmta_uni_sample;
extern const sx_layout sxmta_is1_header;
extern const sx_layout sxmta_is1_sample_info;
extern const sx_layout sxmta_is_sample_bytes;
extern const sx_layout sxmta_is1_instrument;
extern const sx_layout sxmta_is1_subsong;
extern const sx_layout sxmta_is_position;
extern const sx_layout sxmta_is1_event;
extern const sx_layout sxmta_is_unsigned_value;
extern const sx_layout sxmta_is_signed_value;
extern const sx_layout sxmta_is2_header;
extern const sx_layout sxmta_is2_section;
extern const sx_layout sxmta_is2_subsong;
extern const sx_layout sxmta_is2_event;
extern const sx_layout sxmta_is2_sample;
extern const sx_layout sxmta_is2_sample_name;
extern const sx_layout sxmta_is2_sample_copy;
extern const sx_layout sxmta_is2_synth;
extern const sx_layout sxmta_is2_arpeggio;
bool sxmta_span(sxmta_view*v,uint64_t at,uint64_t n,uint64_t end);
bool sxmta_read(sxmta_view*v,uint64_t at,void*p,size_t n,uint64_t end);
bool sxmta_row(sxmta_view*v,const sx_layout*l,uint64_t at,uint64_t end);
bool sxmta_table(sxmta_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end);
bool sxmta_u(sxmta_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end);
bool sxmta_be(sxmta_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end);
bool sxmta_eq(sxmta_view*v,uint64_t p,const char*s,size_t n,uint64_t end);
bool sxmta_text_emit(sxmta_view*v,uint64_t p,uint64_t n,uint64_t end);
bool sxmta_take(sxmta_view*v,const sx_layout*l,uint64_t*p,uint64_t count,uint64_t end);
bool sxmta_skip(sxmta_view*v,uint64_t*p,uint64_t n,uint64_t end);
bool sxmta_galaxy(sxmta_view*v,bool packed);

/* Per-format walkers, called by the family's build. */
bool sx_twice_artofnoise_build(sxmta_view*v);  /* audio/die_music/twice_artofnoise/xx_twice_artofnoise_data.c */
bool sx_rhino_digitalmugician_build(sxmta_view*v);  /* audio/die_music/rhino_digitalmugician/xx_rhino_digitalmugician_data.c */
bool sx_dumbo_graoumftracker_build(sxmta_view*v);  /* audio/die_music/dumbo_graoumftracker/xx_dumbo_graoumftracker_data.c */
bool sx_dumbo_graoumftracker2_build(sxmta_view*v);  /* audio/die_music/dumbo_graoumftracker2/xx_dumbo_graoumftracker2_data.c */
bool sx_jazzjr2_gss_unp_build(sxmta_view*v);  /* audio/die_music/jazzjr2_gss_unp/xx_jazzjr2_gss_unp_data.c */
bool sx_jazzjr2_gss_co_build(sxmta_view*v);  /* audio/die_music/jazzjr2_gss_co/xx_jazzjr2_gss_co_data.c */
bool sx_meng_symphonie_symmod_build(sxmta_view*v);  /* audio/die_music/meng_symphonie_symmod/xx_meng_symphonie_symmod_data.c */
bool sx_oregandev_digitalsymphony_build(sxmta_view*v);  /* audio/die_music/oregandev_digitalsymphony/xx_oregandev_digitalsymphony_data.c */
bool sx_betrayal_jamcracker_build(sxmta_view*v);  /* audio/die_music/betrayal_jamcracker/xx_betrayal_jamcracker_data.c */
bool sx_postma_soundmon_bp_build(sxmta_view*v);  /* audio/die_music/postma_soundmon_bp/xx_postma_soundmon_bp_data.c */
bool sx_ancool_tcbtracker_build(sxmta_view*v);  /* audio/die_music/ancool_tcbtracker/xx_ancool_tcbtracker_data.c */
bool sx_tran_cdfm_composer670_build(sxmta_view*v);  /* audio/die_music/tran_cdfm_composer670/xx_tran_cdfm_composer670_data.c */
bool sx_chrons_unimodtrk_build(sxmta_view*v);  /* audio/die_music/chrons_unimodtrk/xx_chrons_unimodtrk_data.c */
bool sx_bergstedt_sims_instereo1_build(sxmta_view*v);  /* audio/die_music/bergstedt_sims_instereo1/xx_bergstedt_sims_instereo1_data.c */
bool sx_bergstedt_sims_instereo2_build(sxmta_view*v);  /* audio/die_music/bergstedt_sims_instereo2/xx_bergstedt_sims_instereo2_data.c */
bool sx_kinnunen_octamed_med_build(sxmta_view*v);  /* audio/die_music/kinnunen_octamed_med/xx_kinnunen_octamed_med_data.c */
bool sx_fuchs_tracker_build(sxmta_view*v);  /* audio/die_music/fuchs_tracker/xx_fuchs_tracker_data.c */
bool sx_tadic_gamemusiccreator_build(sxmta_view*v);  /* audio/die_music/tadic_gamemusiccreator/xx_tadic_gamemusiccreator_data.c */
bool sx_wombell_chiptracker_kris_build(sxmta_view*v);  /* audio/die_music/wombell_chiptracker_kris/xx_wombell_chiptracker_kris_data.c */
bool sx_kleps_sidmon2_build(sxmta_view*v);  /* audio/die_music/kleps_sidmon2/xx_kleps_sidmon2_data.c */

#endif
