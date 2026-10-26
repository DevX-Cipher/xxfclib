/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The musicnext schema family: what its family unit (xx_format_schema_musicnext.c)
 * and its formats' data files share. Formats: subz3ro's AdLib Tracker II module (.A2M); subz3ro's AdLib Tracker II module (.A2T); idSoft's DOOM music module (.MUS); Extended MIDI chiptune (.XMI,.C55,.PCS); Konami's KSS chiptune (.KSS); Sega Genesis/Mega Drive YM2612 chiptune (.GYM); Sega Genesis/Mega Drive YM2612 (OPN2) chiptune (.GYM); Amaya 'Pixel' Daisuke's Organya/ORG Maker module (.ORG); Amaya 'Pixel' Daisuke's pxtone tune (.PTTUNE); Amaya 'Pixel' Daisuke's pxtone project (.PTCOP); Amaya 'Pixel' Daisuke's pxtone Noise instrument (.PTNOISE); Amaya 'Pixel' Daisuke's pxtone Voice instrument (.PTVOICE); Lasse 'Faust' Oorni's GoatTracker module (.SNG); Lasse 'Faust' Oorni's GoatTracker 2 Instrument (.INS); IRIS & Up Rough's Hively Tracker module (.HVL); Trixter's MONOTONE module (.MON); Riven the Mage's Exotic AdLib module (.XAD); Konami's X68k Music Data eXtended module (.MDX); Konami's MXDRV external PCM resource (.PDX); Carlos Hasan's Digital Audio Sound Interface Kit module (.DSM); Carlos Hasan's Digital Sound Interface Kit module (.DSM); The Loom Syndicate's Dynamic Studio module (.DSM); Superions' Future Composer module (.FC,.FC13,.SMOD); Superions' Future Composer module (.FC,.FC14); Bent 'SHOGUN' Nielsen's Delta Music module (.DM); Bent 'SHOGUN' Nielsen's Delta Music 2 module (.DM2); SIMPLEMUSICALSCORE_SMUS. */
#ifndef XX_FORMAT_SCHEMA_MUSICNEXT_H
#define XX_FORMAT_SCHEMA_MUSICNEXT_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Stream metadata directly: a large ROM/disc payload never becomes a scratch buffer. */
typedef struct sxmn_view {sx_context*c;unsigned work;}sxmn_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxmn_mus_header;
extern const sx_layout sxmn_mus_instrument;
extern const sx_layout sxmn_kss_header;
extern const sx_layout sxmn_kss_extended;
extern const sx_layout sxmn_org_header;
extern const sx_layout sxmn_org_instrument;
extern const sx_layout sxmn_org_position;
extern const sx_layout sxmn_org_note;
extern const sx_layout sxmn_org_length;
extern const sx_layout sxmn_org_volume;
extern const sx_layout sxmn_org_pan;
extern const sx_layout sxmn_pxt_voice_header;
extern const sx_layout sxmn_pxt_noise_header;
extern const sx_layout sxmn_pxt_noise_samples1;
extern const sx_layout sxmn_pxt_noise_samples2;
extern const sx_layout sxmn_pxt_noise_samples3;
extern const sx_layout sxmn_pxt_noise_samples4;
extern const sx_layout sxmn_pxt_noise_samples5;
extern const sx_layout sxmn_pxt_noise_units;
extern const sx_layout sxmn_monotone_header;
extern const sx_layout sxmn_monotone_order;
extern const sx_layout sxmn_monotone_cell;
extern const sx_layout sxmn_xad_header;
extern const sx_layout sxmn_mdx_title_byte;
extern const sx_layout sxmn_mdx_title_end;
extern const sx_layout sxmn_mdx_pdx_byte;
extern const sx_layout sxmn_mdx_voice_offset;
extern const sx_layout sxmn_mdx_track_offset;
extern const sx_layout sxmn_pdx_entry;
extern const sx_layout sxmn_dsm_riff;
extern const sx_layout sxmn_dsm_chunk;
extern const sx_layout sxmn_dsm_song;
extern const sx_layout sxmn_dsm_order;
extern const sx_layout sxmn_dsm_sample;
extern const sx_layout sxmn_dynamic_header;
extern const sx_layout sxmn_dynamic_pan;
extern const sx_layout sxmn_dynamic_track_name;
extern const sx_layout sxmn_dynamic_sample;
extern const sx_layout sxmn_dynamic_event;
extern const sx_layout sxmn_hvl_header;
extern const sx_layout sxmn_hvl_subsong;
extern const sx_layout sxmn_hvl_position;
extern const sx_layout sxmn_hvl_empty_event;
extern const sx_layout sxmn_hvl_event;
extern const sx_layout sxmn_hvl_instrument;
extern const sx_layout sxmn_hvl_playlist;
extern const sx_layout sxmn_hvl_name_byte;
extern const sx_layout sxmn_dsm1_header;
extern const sx_layout sxmn_dsm1_instrument_paragraph;
extern const sx_layout sxmn_dsm1_pattern_paragraph;
extern const sx_layout sxmn_dsm1_instrument;
extern const sx_layout sxmn_dsm1_pattern;
extern const sx_layout sxmn_d1_header;
extern const sx_layout sxmn_d1_track;
extern const sx_layout sxmn_d1_control;
extern const sx_layout sxmn_d1_pattern;
extern const sx_layout sxmn_d1_instrument;
extern const sx_layout sxmn_d1_synth_entry;
extern const sx_layout sxmn_d2_marker;
extern const sx_layout sxmn_d2_arpeggio;
extern const sx_layout sxmn_d2_track_header;
extern const sx_layout sxmn_d2_track;
extern const sx_layout sxmn_d2_pattern_size;
extern const sx_layout sxmn_d2_pattern;
extern const sx_layout sxmn_d2_instrument_offset;
extern const sx_layout sxmn_d2_instrument;
bool sxmn_span(sxmn_view*v,uint64_t at,uint64_t n,uint64_t end);
bool sxmn_read(sxmn_view*v,uint64_t at,void*p,size_t n,uint64_t end);
bool sxmn_word(sxmn_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end);
bool sxmn_row(sxmn_view*v,const sx_layout*l,uint64_t at,uint64_t end);
bool sxmn_table(sxmn_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end);
bool sxmn_cstring(sxmn_view*v,uint64_t*p,uint64_t end,uint64_t max);
bool sxmn_magic(sxmn_view*v,uint64_t at,const char*s,size_t n,uint64_t end);
bool sxmn_a2(sxmn_view*v,bool tiny);
bool sxmn_iff(sxmn_view*v,uint64_t at,uint64_t end,unsigned depth,bool smus);
bool sxmn_gym(sxmn_view*v,bool header);
bool sxmn_pxt(sxmn_view*v);
bool sxmn_goat(sxmn_view*v,bool instrument);
bool sxmn_fc(sxmn_view*v,bool v14);

/* Per-format walkers, called by the family's build. */
bool sx_subz3ro_adlibtracker2_a2m_build(sxmn_view*v);  /* audio/die_music/subz3ro_adlibtracker2_a2m/xx_subz3ro_adlibtracker2_a2m_data.c */
bool sx_subz3ro_adlibtracker2_tiny_build(sxmn_view*v);  /* audio/die_music/subz3ro_adlibtracker2_tiny/xx_subz3ro_adlibtracker2_tiny_data.c */
bool sx_idsoft_doom_mus_build(sxmn_view*v);  /* audio/die_music/idsoft_doom_mus/xx_idsoft_doom_mus_data.c */
bool sx_extendedmidi_xmi_build(sx_context*c,sxmn_view*v);  /* audio/die_music/extendedmidi_xmi/xx_extendedmidi_xmi_data.c */
bool sx_konami_kss_build(sxmn_view*v);  /* audio/die_music/konami_kss/xx_konami_kss_data.c */
bool sx_gensmd_ym2612_gym_build(sxmn_view*v);  /* audio/die_music/gensmd_ym2612_gym/xx_gensmd_ym2612_gym_data.c */
bool sx_ym2612reglog_gym_build(sxmn_view*v);  /* audio/die_music/ym2612reglog_gym/xx_ym2612reglog_gym_data.c */
bool sx_pixel_organya_build(sxmn_view*v);  /* audio/die_music/pixel_organya/xx_pixel_organya_data.c */
bool sx_pixel_pxtone_pttune_build(sxmn_view*v);  /* audio/die_music/pixel_pxtone_pttune/xx_pixel_pxtone_pttune_data.c */
bool sx_pixel_pxtone_ptcop_build(sxmn_view*v);  /* audio/die_music/pixel_pxtone_ptcop/xx_pixel_pxtone_ptcop_data.c */
bool sx_pixel_pxtone_ptnoise_build(sxmn_view*v);  /* audio/die_music/pixel_pxtone_ptnoise/xx_pixel_pxtone_ptnoise_data.c */
bool sx_pixel_pxtone_ptvoice_build(sxmn_view*v);  /* audio/die_music/pixel_pxtone_ptvoice/xx_pixel_pxtone_ptvoice_data.c */
bool sx_faust_goattracker_sng_build(sxmn_view*v);  /* audio/die_music/faust_goattracker_sng/xx_faust_goattracker_sng_data.c */
bool sx_faust_goattracker2_ins_build(sxmn_view*v);  /* audio/die_music/faust_goattracker2_ins/xx_faust_goattracker2_ins_data.c */
bool sx_iris_hivelytracker_build(sxmn_view*v);  /* audio/die_music/iris_hivelytracker/xx_iris_hivelytracker_data.c */
bool sx_trixter_monotone_build(sxmn_view*v);  /* audio/die_music/trixter_monotone/xx_trixter_monotone_data.c */
bool sx_riven_exoticadlib_xad_build(sx_context*c,sxmn_view*v);  /* audio/die_music/riven_exoticadlib_xad/xx_riven_exoticadlib_xad_data.c */
bool sx_konami_musicdataextended_mdx_build(sxmn_view*v);  /* audio/die_music/konami_musicdataextended_mdx/xx_konami_musicdataextended_mdx_data.c */
bool sx_konami_mxdrv_pcm_build(sxmn_view*v);  /* audio/die_music/konami_mxdrv_pcm/xx_konami_mxdrv_pcm_data.c */
bool sx_hasan_dasik_dsm_build(sxmn_view*v);  /* audio/die_music/hasan_dasik_dsm/xx_hasan_dasik_dsm_data.c */
bool sx_hasan_dsik_dsm_build(sxmn_view*v);  /* audio/die_music/hasan_dsik_dsm/xx_hasan_dsik_dsm_data.c */
bool sx_theloomsyndicate_dynamicstudio_dsm_build(sxmn_view*v);  /* audio/die_music/theloomsyndicate_dynamicstudio_dsm/xx_theloomsyndicate_dynamicstudio_dsm_data.c */
bool sx_superions_futurecomposer_fc13_build(sxmn_view*v);  /* audio/die_music/superions_futurecomposer_fc13/xx_superions_futurecomposer_fc13_data.c */
bool sx_superions_futurecomposer_fc14_build(sxmn_view*v);  /* audio/die_music/superions_futurecomposer_fc14/xx_superions_futurecomposer_fc14_data.c */
bool sx_shogun_deltamusic1_build(sxmn_view*v);  /* audio/die_music/shogun_deltamusic1/xx_shogun_deltamusic1_data.c */
bool sx_shogun_deltamusic2_build(sxmn_view*v);  /* audio/die_music/shogun_deltamusic2/xx_shogun_deltamusic2_data.c */
bool sx_simplemusicalscore_smus_build(sx_context*c,sxmn_view*v);  /* audio/die_music/simplemusicalscore_smus/xx_simplemusicalscore_smus_data.c */

#endif
