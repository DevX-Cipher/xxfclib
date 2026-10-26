/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The musicwire schema family: what its family unit (xx_format_schema_musicwire.c)
 * and its formats' data files share. Formats: Oskari Tammelin's Jeskola Buzz module (.BMX); Instrument bank for Adlib Visual Composer (STANDARD.BNK); Leonardo 'Delek' Demartino's DeFleMask module (.DMF); Tero 'kometbomb' Lindeman's Klystrack/Klystron module (.KT); Tero 'kometbomb' Lindeman's Klystrack instrument (.KI); Tero 'kometbomb' Lindeman's Klystrack effects (.KF?); Lucas Arts Adlib chiptune (.LAA); B. Birney's PlayerPro module (.MAD); MO3 MOD module (.MO3); SuBZeR0's MPU-401 Trakker Adlib module (.MTK); DIE MUSIC HELLSTROM SBSTUDIO PAC; Bluemoon's Sound Club for Windows module (.SN2); Alexander 'NightRadio' Zolotov's SunVox module (.SUNVOX); Shiru's TFM Music Maker tune (.TFD); Shiru's TFM Music Maker module (.TFE); Shiru's VGM Music Maker module (.VGE); Westwood ADL module (.ADL); Sierra SCI Sound Adlib chiptune (.SND). */
#ifndef XX_FORMAT_SCHEMA_MUSICWIRE_H
#define XX_FORMAT_SCHEMA_MUSICWIRE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Read physical metadata without buffering whole sample or track payloads. */
typedef struct sxmw_view {sx_context*c;unsigned work;}sxmw_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxmw_pascal_text_length;
extern const sx_layout sxmw_count16;
extern const sx_layout sxmw_order8;
extern const sx_layout sxmw_order16;
extern const sx_layout sxmw_order32;
extern const sx_layout sxmw_chunk_le;
extern const sx_layout sxmw_bmx_header;
extern const sx_layout sxmw_bmx_section;
extern const sx_layout sxmw_bmx_connection;
extern const sx_layout sxmw_bmx_sequences;
extern const sx_layout sxmw_bmx_sequence;
extern const sx_layout sxmw_bmx_wave_data;
extern const sx_layout sxmw_bmx_wave_bytes;
extern const sx_layout sxmw_bnk_header;
extern const sx_layout sxmw_bnk_name;
extern const sx_layout sxmw_bnk_instrument;
extern const sx_layout sxmw_bnk_operator;
extern const sx_layout sxmw_bnk_waveforms;
extern const sx_layout sxmw_mo3_header;
extern const sx_layout sxmw_mo3_packed_length;
extern const sx_layout sxmw_mtk_header;
extern const sx_layout sxmw_madg_header;
extern const sx_layout sxmw_madg_instrument;
extern const sx_layout sxmw_madg_orders;
extern const sx_layout sxmw_madg_pattern;
extern const sx_layout sxmw_madg_event;
extern const sx_layout sxmw_pac_header;
extern const sx_layout sxmw_pac_info;
extern const sx_layout sxmw_pac_song;
extern const sx_layout sxmw_pac_pan;
extern const sx_layout sxmw_pac_sound;
extern const sx_layout sxmw_pac_event;
extern const sx_layout sxmw_dmf_header;
extern const sx_layout sxmw_dmf_timing;
extern const sx_layout sxmw_dmf_instrument_count;
extern const sx_layout sxmw_dmf_instrument_mode;
extern const sx_layout sxmw_dmf_fm;
extern const sx_layout sxmw_dmf_operator;
extern const sx_layout sxmw_tfd_header;
extern const sx_layout sxmw_tfd_command;
extern const sx_layout sxmw_tfd_skip;
extern const sx_layout sxmw_tfd_write;
extern const sx_layout sxmw_tfm_rle_header;
extern const sx_layout sxmw_vge_header;
extern const sx_layout sxmw_laa_header;
extern const sx_layout sxmw_laa_chunk;
extern const sx_layout sxmw_laa_mdhd;
extern const sx_layout sxmw_midi_header;
extern const sx_layout sxmw_laa_old_header;
extern const sx_layout sxmw_laa_old_instrument;
extern const sx_layout sxmw_sci0_header;
extern const sx_layout sxmw_sci0_channel;
extern const sx_layout sxmw_sci1_header;
extern const sx_layout sxmw_sci1_track;
extern const sx_layout sxmw_sci1_section_end;
extern const sx_layout sxmw_adl_program8;
extern const sx_layout sxmw_adl_program16;
extern const sx_layout sxmw_adl_program_offset;
extern const sx_layout sxmw_adl_instrument_offset;
extern const sx_layout sxmw_sn2_header;
extern const sx_layout sxmw_sn2_chunk;
extern const sx_layout sxmw_sunvox_header;
extern const sx_layout sxmw_sv_version;
extern const sx_layout sxmw_sv_base_version;
extern const sx_layout sxmw_sv_tempo;
extern const sx_layout sxmw_sv_ticks_per_line;
extern const sx_layout sxmw_sv_time_grid;
extern const sx_layout sxmw_sv_time_grid2;
extern const sx_layout sxmw_sv_global_volume;
extern const sx_layout sxmw_sv_module_scale;
extern const sx_layout sxmw_sv_module_zoom;
extern const sx_layout sxmw_sv_module_x;
extern const sx_layout sxmw_sv_module_y;
extern const sx_layout sxmw_sv_layer_mask;
extern const sx_layout sxmw_sv_current_layer;
extern const sx_layout sxmw_sv_timeline_position;
extern const sx_layout sxmw_sv_restart_position;
extern const sx_layout sxmw_sv_selected_module;
extern const sx_layout sxmw_sv_last_generator;
extern const sx_layout sxmw_sv_tracks;
extern const sx_layout sxmw_sv_lines;
extern const sx_layout sxmw_sv_source_pattern;
extern const sx_layout sxmw_sv_flags;
extern const sx_layout sxmw_sv_x;
extern const sx_layout sxmw_sv_y;
extern const sx_layout sxmw_sv_finetune;
extern const sx_layout sxmw_sv_relative_note;
extern const sx_layout sxmw_sv_layer;
extern const sx_layout sxmw_sv_scale;
extern const sx_layout sxmw_sv_midi_in;
extern const sx_layout sxmw_sv_midi_channel;
extern const sx_layout sxmw_sv_midi_bank;
extern const sx_layout sxmw_sv_midi_program;
extern const sx_layout sxmw_sv_link_module;
extern const sx_layout sxmw_sv_controller_value;
extern const sx_layout sxmw_sv_chunk_number;
extern const sx_layout sxmw_sv_chunk_capacity;
extern const sx_layout sxmw_sv_chunk_format;
extern const sx_layout sxmw_sv_sample_rate;
extern const sx_layout sxmw_sv_color;
extern const sx_layout sxmw_sv_note;
bool sxmw_span(sxmw_view*v,uint64_t at,uint64_t n,uint64_t end);
bool sxmw_read(sxmw_view*v,uint64_t at,void*p,size_t n,uint64_t end);
bool sxmw_row(sxmw_view*v,const sx_layout*l,uint64_t at,uint64_t end);
bool sxmw_table(sxmw_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end);
bool sxmw_u(sxmw_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end);
bool sxmw_be(sxmw_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end);
bool sxmw_eq(sxmw_view*v,uint64_t p,const char*s,size_t n,uint64_t end);
bool sxmw_text_emit(sxmw_view*v,uint64_t p,uint64_t n,uint64_t end);
bool sxmw_take(sxmw_view*v,const sx_layout*l,uint64_t*p,uint64_t count,uint64_t end);
bool sxmw_skip(sxmw_view*v,uint64_t*p,uint64_t n,uint64_t end);
bool sxmw_cstring(sxmw_view*v,uint64_t*p,uint64_t end,uint64_t cap);
bool sxmw_rle(sxmw_view*v,uint64_t p,uint64_t end);
bool sxmw_kly(sxmw_view*v,unsigned kind);

/* Per-format walkers, called by the family's build. */
bool sx_tammelin_jeskolabuzz_bmx_build(sxmw_view*v);  /* audio/die_music/tammelin_jeskolabuzz_bmx/xx_tammelin_jeskolabuzz_bmx_data.c */
bool sx_adlibvisualcomposer_standardbnk_build(sxmw_view*v);  /* audio/die_music/adlibvisualcomposer_standardbnk/xx_adlibvisualcomposer_standardbnk_data.c */
bool sx_delek_deflemask_build(sxmw_view*v);  /* audio/die_music/delek_deflemask/xx_delek_deflemask_data.c */
bool sx_kometbomb_klystrack_build(sxmw_view*v);  /* audio/die_music/kometbomb_klystrack/xx_kometbomb_klystrack_data.c */
bool sx_kometbomb_klystrack_ki_build(sxmw_view*v);  /* audio/die_music/kometbomb_klystrack_ki/xx_kometbomb_klystrack_ki_data.c */
bool sx_kometbomb_klystrack_fx_build(sxmw_view*v);  /* audio/die_music/kometbomb_klystrack_fx/xx_kometbomb_klystrack_fx_data.c */
bool sx_lucasarts_adlib_build(sxmw_view*v);  /* audio/die_music/lucasarts_adlib/xx_lucasarts_adlib_data.c */
bool sx_birney_playerpro_mad_build(sxmw_view*v);  /* audio/die_music/birney_playerpro_mad/xx_birney_playerpro_mad_data.c */
bool sx_bassmod_mo3_build(sxmw_view*v);  /* audio/die_music/bassmod_mo3/xx_bassmod_mo3_data.c */
bool sx_subzer0_mpu401trakker_mtk_build(sxmw_view*v);  /* audio/die_music/subzer0_mpu401trakker_mtk/xx_subzer0_mpu401trakker_mtk_data.c */
bool sx_hellstrom_sbstudio_pac_build(sxmw_view*v);  /* audio/die_music/hellstrom_sbstudio_pac/xx_hellstrom_sbstudio_pac_data.c */
bool sx_bluemoon_soundclub_sn2_build(sxmw_view*v);  /* audio/die_music/bluemoon_soundclub_sn2/xx_bluemoon_soundclub_sn2_data.c */
bool sx_nightradio_sunvox_build(sxmw_view*v);  /* audio/die_music/nightradio_sunvox/xx_nightradio_sunvox_data.c */
bool sx_shiru_tfmd_build(sxmw_view*v);  /* audio/die_music/shiru_tfmd/xx_shiru_tfmd_data.c */
bool sx_shiru_tfmv2_build(sxmw_view*v);  /* audio/die_music/shiru_tfmv2/xx_shiru_tfmv2_data.c */
bool sx_shiru_vge_build(sxmw_view*v);  /* audio/die_music/shiru_vge/xx_shiru_vge_data.c */
bool sx_westwood_adl_build(sxmw_view*v);  /* audio/die_music/westwood_adl/xx_westwood_adl_data.c */
bool sx_sierra_scisound_build(sxmw_view*v);  /* audio/die_music/sierra_scisound/xx_sierra_scisound_data.c */

#endif
