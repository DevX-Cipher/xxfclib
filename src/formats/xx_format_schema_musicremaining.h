/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The musicremaining schema family: what its family unit (xx_format_schema_musicremaining.c)
 * and its formats' data files share. Formats: Velvet Studio Advanced Module System track (.AMS); Chuck Biscuits & Zenic/Heretics' module (.CBA); Alex 'Statix' Evans' Disorder Tracker 2 module (.PLM); Niklas 'pascal' Beisert's MXMplay module (.MXM); Daniel Potter/Digital Infinity's Farandole Composer pattern (.FPT); Daniel Potter/Digital Infinity's Farandole Composer sample (.FSM); Kirill Kolpakov's fMSX/x128 PSG chiptune (.PSG); Kirill Kolpakov's Extended PSG chiptune (.EPSG); Kirill Kolpakov's PSG2 chiptune (.PSG2); Gameboy Ripped Format chiptune (.GBR); WonderSwan R programmatic chiptune (.WSR); DIE MUSIC VSOFT VORTEXPROJECT; Ken Silverman's Digital Music module (.KDM); PSX Alternative!'s Eternal SPU Plugin chiptune (.SPU); ProTracker IFF-wrapped module (.PTM); Atari ST Sound Header module (.SND,.SNDH). */
#ifndef XX_FORMAT_SCHEMA_MUSICREMAINING_H
#define XX_FORMAT_SCHEMA_MUSICREMAINING_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Stream metadata directly: a large ROM/disc payload never becomes a scratch buffer. */
typedef struct sxmr_view {sx_context*c;unsigned work;}sxmr_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxmr_ams2_magic;
extern const sx_layout sxmr_ams2_header;
extern const sx_layout sxmr_ams2_timing20;
extern const sx_layout sxmr_ams2_timing22;
extern const sx_layout sxmr_pascal_text_length;
extern const sx_layout sxmr_ams2_sample_count;
extern const sx_layout sxmr_ams2_note_sample;
extern const sx_layout sxmr_ams2_envelope;
extern const sx_layout sxmr_ams2_envelope_point;
extern const sx_layout sxmr_ams2_instrument;
extern const sx_layout sxmr_ams2_sample;
extern const sx_layout sxmr_ams2_description;
extern const sx_layout sxmr_order16;
extern const sx_layout sxmr_ams2_pattern;
extern const sx_layout sxmr_cba_header;
extern const sx_layout sxmr_pan_position;
extern const sx_layout sxmr_order8;
extern const sx_layout sxmr_cba_sample;
extern const sx_layout sxmr_cba_event;
extern const sx_layout sxmr_plm_header;
extern const sx_layout sxmr_plm_order;
extern const sx_layout sxmr_pattern_offset;
extern const sx_layout sxmr_sample_offset;
extern const sx_layout sxmr_instrument_offset;
extern const sx_layout sxmr_plm_sample;
extern const sx_layout sxmr_plm_pattern;
extern const sx_layout sxmr_plm_event;
extern const sx_layout sxmr_mxm_header;
extern const sx_layout sxmr_mxm_instrument;
extern const sx_layout sxmr_mxm_sample;
extern const sx_layout sxmr_mxm_pattern;
extern const sx_layout sxmr_mxm_event_flags;
extern const sx_layout sxmr_mxm_note;
extern const sx_layout sxmr_mxm_volume;
extern const sx_layout sxmr_mxm_effect;
extern const sx_layout sxmr_gbr_header;
extern const sx_layout sxmr_wsr_footer;
extern const sx_layout sxmr_vtx_header;
extern const sx_layout sxmr_vtx_legacy_header;
extern const sx_layout sxmr_kdm_header;
extern const sx_layout sxmr_kdm_instrument;
extern const sx_layout sxmr_kdm_quantization;
extern const sx_layout sxmr_kdm_volume;
extern const sx_layout sxmr_kdm_time;
extern const sx_layout sxmr_kdm_track;
extern const sx_layout sxmr_kdm_pitch;
extern const sx_layout sxmr_kdm_effect;
extern const sx_layout sxmr_spu_metadata;
extern const sx_layout sxmr_spu_register;
extern const sx_layout sxmr_spu_old_timing;
extern const sx_layout sxmr_spu_new_timing;
extern const sx_layout sxmr_spu_old_event;
extern const sx_layout sxmr_spu_write;
extern const sx_layout sxmr_spu_read;
extern const sx_layout sxmr_spu_transfer;
extern const sx_layout sxmr_spu_dma_read;
extern const sx_layout sxmr_spu_xa;
extern const sx_layout sxmr_spu_tick;
extern const sx_layout sxmr_pt36_header;
extern const sx_layout sxmr_pt36_chunk;
extern const sx_layout sxmr_pt36_info;
extern const sx_layout sxmr_sndh_header;
extern const sx_layout sxmr_sndh_tag;
extern const sx_layout sxmr_sndh_tunes;
extern const sx_layout sxmr_sndh_default;
extern const sx_layout sxmr_sndh_timer;
extern const sx_layout sxmr_sndh_name_offset;
extern const sx_layout sxmr_sndh_frames;
extern const sx_layout sxmr_sndh_seconds;
extern const sx_layout sxmr_psg2_magic;
extern const sx_layout sxmr_psg2_map;
extern const sx_layout sxmr_psg2_reuse;
extern const sx_layout sxmr_psg2_value;
bool sxmr_span(sxmr_view*v,uint64_t at,uint64_t n,uint64_t end);
bool sxmr_read(sxmr_view*v,uint64_t at,void*p,size_t n,uint64_t end);
bool sxmr_row(sxmr_view*v,const sx_layout*l,uint64_t at,uint64_t end);
bool sxmr_table(sxmr_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end);
bool sxmr_u(sxmr_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end);
bool sxmr_be(sxmr_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end);
bool sxmr_eq(sxmr_view*v,uint64_t p,const char*s,size_t n,uint64_t end);
bool sxmr_text_emit(sxmr_view*v,uint64_t p,uint64_t n,uint64_t end);
bool sxmr_string(sxmr_view*v,uint64_t*p,uint64_t end);
bool sxmr_far(sxmr_view*v,bool sample);
bool sxmr_psg(sxmr_view*v,bool extended);

/* Per-format walkers, called by the family's build. */
bool sx_velvetstudio_ams_build(sxmr_view*v);  /* audio/die_music/velvetstudio_ams/xx_velvetstudio_ams_data.c */
bool sx_chuckbiscuits_cba_build(sxmr_view*v);  /* audio/die_music/chuckbiscuits_cba/xx_chuckbiscuits_cba_data.c */
bool sx_statix_disordertracker2_plm_build(sxmr_view*v);  /* audio/die_music/statix_disordertracker2_plm/xx_statix_disordertracker2_plm_data.c */
bool sx_beisert_mxmplay_build(sxmr_view*v);  /* audio/die_music/beisert_mxmplay/xx_beisert_mxmplay_data.c */
bool sx_potter_farandole_fpt_build(sxmr_view*v);  /* audio/die_music/potter_farandole_fpt/xx_potter_farandole_fpt_data.c */
bool sx_potter_farandole_fsm_build(sxmr_view*v);  /* audio/die_music/potter_farandole_fsm/xx_potter_farandole_fsm_data.c */
bool sx_kolpakov_fmsxx128_psg_build(sxmr_view*v);  /* audio/die_music/kolpakov_fmsxx128_psg/xx_kolpakov_fmsxx128_psg_data.c */
bool sx_kolpakov_extended_psg_build(sxmr_view*v);  /* audio/die_music/kolpakov_extended_psg/xx_kolpakov_extended_psg_data.c */
bool sx_kolpakov_psg2_build(sxmr_view*v);  /* audio/die_music/kolpakov_psg2/xx_kolpakov_psg2_data.c */
bool sx_gameboy_rippedformat_build(sxmr_view*v);  /* audio/die_music/gameboy_rippedformat/xx_gameboy_rippedformat_data.c */
bool sx_wonderswanr_wsrf_build(sxmr_view*v);  /* audio/die_music/wonderswanr_wsrf/xx_wonderswanr_wsrf_data.c */
bool sx_vsoft_vortexproject_build(sxmr_view*v);  /* audio/die_music/vsoft_vortexproject/xx_vsoft_vortexproject_data.c */
bool sx_silverman_digitalmusic_kdm_build(sxmr_view*v);  /* audio/die_music/silverman_digitalmusic_kdm/xx_silverman_digitalmusic_kdm_data.c */
bool sx_psxalt_eternalspuplugin_build(sxmr_view*v);  /* audio/die_music/psxalt_eternalspuplugin/xx_psxalt_eternalspuplugin_data.c */
bool sx_protracker_iff_ptm_build(sxmr_view*v);  /* audio/die_music/protracker_iff_ptm/xx_protracker_iff_ptm_data.c */
bool sx_atarist_soundheader_build(sxmr_view*v);  /* audio/die_music/atarist_soundheader/xx_atarist_soundheader_data.c */

#endif
