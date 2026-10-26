/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The chipmusic schema family: what its family unit (xx_format_schema_chipmusic.c)
 * and its formats' data files share. Formats: Shiru's 1tracker module (.1TM); DIE MUSIC FUXOFT AYLANGUAGE FXM; R.Schrijvers & M.Delorme's MoonBlaster for MoonSound FM module (.MFM); R.Schrijvers & M.Delorme's MoonBlaster for MoonSound Wave module (.MWM+.MWK); R.Schrijvers & M.Delorme's MoonBlaster Wave for MoonSound wave kit (.MWK); Federation Against Commodore's FAC Soundtracker module (.MUS); Oliver 'BSC' Mayer's Amstrad CPC Soundtrakker 128K module (.128); Julien 'Targhan' Nevo's STarKos module (.SKS); Julien 'Targhan' Nevo's STarKos module (.BIN); Marcin 'Jaskier' Lewandowski's Theta Music Composer (.TM2); DIE MUSIC FUXOFT AYAMADEUS; R.Schrijvers & M.Delorme's MoonBlaster module (.MBM); Stanislav 'KSA' Kuzin's Sound Tracker Pro module (.STF,.F); DIE MUSIC KOUDELKA SCALEXQJETATRACKER; Marcin 'Jaskier' Lewandowski's Theta Music Composer module (.TMC,.TM4,.TM8); Michel 'Bananmos' Iwaniec/Nerds 'R' Us Nerd Tracker 2 module (.NED). */
#ifndef XX_FORMAT_SCHEMA_CHIPMUSIC_H
#define XX_FORMAT_SCHEMA_CHIPMUSIC_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxchip_chip_text;
extern const sx_layout sxchip_chip_fxm_header;
extern const sx_layout sxchip_chip_fxm_channels;
extern const sx_layout sxchip_chip_ay_amadeus_header;
extern const sx_layout sxchip_chip_ay_song;
extern const sx_layout sxchip_chip_ay_amadeus_address;
extern const sx_layout sxchip_chip_stf_volume;
extern const sx_layout sxchip_chip_stf_noise;
extern const sx_layout sxchip_chip_stf_tone;
extern const sx_layout sxchip_chip_stf_sample_loop;
extern const sx_layout sxchip_chip_stf_position;
extern const sx_layout sxchip_chip_stf_positions_end;
extern const sx_layout sxchip_chip_stf_ornament;
extern const sx_layout sxchip_chip_note_step;
extern const sx_layout sxchip_chip_stf_settings;
extern const sx_layout sxchip_chip_stf_pattern_length;
extern const sx_layout sxchip_chip_stf_song;
extern const sx_layout sxchip_chip_stf_event;
extern const sx_layout sxchip_chip_sqt_header;
extern const sx_layout sxchip_chip_sqt_sample_reference;
extern const sx_layout sxchip_chip_sqt_ornament_reference;
extern const sx_layout sxchip_chip_sqt_pattern_reference;
extern const sx_layout sxchip_chip_sqt_position;
extern const sx_layout sxchip_chip_sqt_loop;
extern const sx_layout sxchip_chip_sqt_sample_line;
extern const sx_layout sxchip_chip_ned10_header;
extern const sx_layout sxchip_chip_ned10_instrument;
extern const sx_layout sxchip_chip_ned_order;
extern const sx_layout sxchip_chip_ned10_pattern;
extern const sx_layout sxchip_chip_ned20_header;
extern const sx_layout sxchip_chip_ned20_data;
extern const sx_layout sxchip_chip_ned20_instrument;
extern const sx_layout sxchip_chip_ned20_dpcm_instrument;
extern const sx_layout sxchip_chip_ned20_order;
extern const sx_layout sxchip_chip_ned20_pattern;
extern const sx_layout sxchip_chip_ned_sample_instrument;
extern const sx_layout sxchip_chip_ned_sample;
extern const sx_layout sxchip_chip_amsdos_header;
extern const sx_layout sxchip_chip_bsc128_volume;
extern const sx_layout sxchip_chip_bsc128_noise;
extern const sx_layout sxchip_chip_bsc128_tone;
extern const sx_layout sxchip_chip_bsc128_loop;
extern const sx_layout sxchip_chip_bsc128_position;
extern const sx_layout sxchip_chip_bsc128_name;
extern const sx_layout sxchip_chip_bsc128_settings;
extern const sx_layout sxchip_chip_bsc128_event;
extern const sx_layout sxchip_chip_sks_header;
extern const sx_layout sxchip_chip_sks_position;
extern const sx_layout sxchip_chip_sks_end;
extern const sx_layout sxchip_chip_sks_instrument;
extern const sx_layout sxchip_chip_sks_special;
extern const sx_layout sxchip_chip_sks_track;
extern const sx_layout sxchip_chip_starkos_binary_header;
extern const sx_layout sxchip_chip_mbm_edit_marker;
extern const sx_layout sxchip_chip_mbm_header;
extern const sx_layout sxchip_chip_moon_position;
extern const sx_layout sxchip_chip_mbm_pattern_pointer;
extern const sx_layout sxchip_chip_mwk_header;
extern const sx_layout sxchip_chip_mwk_patch;
extern const sx_layout sxchip_chip_mwk_name;
extern const sx_layout sxchip_chip_mwk_ram_tone;
extern const sx_layout sxchip_chip_mwk_rom_tone;
extern const sx_layout sxchip_chip_msx_bload;
extern const sx_layout sxchip_chip_fac_footer;
extern const sx_layout sxchip_chip_fac_pro_footer;
extern const sx_layout sxchip_chip_fac_row;
extern const sx_layout sxchip_chip_1tracker_section;
extern const sx_layout sxchip_chip_1tracker_key;
extern const sx_layout sxchip_chip_1tracker_engine;
extern const sx_layout sxchip_chip_1tracker_title;
extern const sx_layout sxchip_chip_1tracker_author;
extern const sx_layout sxchip_chip_1tracker_speed;
extern const sx_layout sxchip_chip_1tracker_loop_start;
extern const sx_layout sxchip_chip_1tracker_loop_end;
extern const sx_layout sxchip_chip_1tracker_measure;
extern const sx_layout sxchip_chip_1tracker_pattern_format;
bool sxchip_span(sx_context*c,uint64_t p,uint64_t n);
bool sxchip_read(sx_context*c,uint64_t p,void*b,size_t n);
uint16_t sxchip16(const uint8_t*b);
bool sxchip_u16(sx_context*c,uint64_t p,uint16_t*v);
bool sxchip_u8(sx_context*c,uint64_t p,uint8_t*v);
bool sxchip_eq(sx_context*c,uint64_t p,const char*s,size_t n);
bool sxchip_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count);
bool sxchip_opt(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count);
bool sxchip_tmc(sx_context*c,bool v2);
bool sxchip_moon(sx_context*c,bool wave);

/* Per-format walkers, called by the family's build. */
bool sx_shiru_1tracker_build(sx_context *c);  /* audio/die_music/shiru_1tracker/xx_shiru_1tracker_data.c */
bool sx_fuxoft_aylanguage_fxm_build(sx_context *c);  /* audio/die_music/fuxoft_aylanguage_fxm/xx_fuxoft_aylanguage_fxm_data.c */
bool sx_moonblaster_fm_build(sx_context *c);  /* audio/die_music/moonblaster_fm/xx_moonblaster_fm_data.c */
bool sx_moonblaster_wave_build(sx_context *c);  /* audio/die_music/moonblaster_wave/xx_moonblaster_wave_data.c */
bool sx_moonblaster_wave_mwk_build(sx_context *c);  /* audio/die_music/moonblaster_wave_mwk/xx_moonblaster_wave_mwk_data.c */
bool sx_msx_facsoundtracker_mus_build(sx_context *c);  /* audio/die_music/msx_facsoundtracker_mus/xx_msx_facsoundtracker_mus_data.c */
bool sx_bsc_amstradcpc_soundtrakker128k_build(sx_context *c);  /* audio/die_music/bsc_amstradcpc_soundtrakker128k/xx_bsc_amstradcpc_soundtrakker128k_data.c */
bool sx_targhan_starkos_sks_build(sx_context *c);  /* audio/die_music/targhan_starkos_sks/xx_targhan_starkos_sks_data.c */
bool sx_targhan_starkos_bin_build(sx_context *c);  /* audio/die_music/targhan_starkos_bin/xx_targhan_starkos_bin_data.c */
bool sx_jaskier_thetamusiccomposer_tm2_build(sx_context *c);  /* audio/die_music/jaskier_thetamusiccomposer_tm2/xx_jaskier_thetamusiccomposer_tm2_data.c */
bool sx_fuxoft_ayamadeus_build(sx_context *c);  /* audio/die_music/fuxoft_ayamadeus/xx_fuxoft_ayamadeus_data.c */
bool sx_schrijvers_moonblaster_mbm_build(sx_context *c);  /* audio/die_music/schrijvers_moonblaster_mbm/xx_schrijvers_moonblaster_mbm_data.c */
bool sx_ksa_soundtrackerpro_stf_project_co_build(sx_context *c);  /* audio/die_music/ksa_soundtrackerpro_stf_project_co/xx_ksa_soundtrackerpro_stf_project_co_data.c */
bool sx_koudelka_scalexqjetatracker_build(sx_context *c);  /* audio/die_music/koudelka_scalexqjetatracker/xx_koudelka_scalexqjetatracker_data.c */
bool sx_jaskier_thetamusiccomposer_tmc_build(sx_context *c);  /* audio/die_music/jaskier_thetamusiccomposer_tmc/xx_jaskier_thetamusiccomposer_tmc_data.c */
bool sx_nerdsrus_nerdtracker2_ned_build(sx_context *c);  /* audio/die_music/nerdsrus_nerdtracker2_ned/xx_nerdsrus_nerdtracker2_ned_data.c */

#endif
