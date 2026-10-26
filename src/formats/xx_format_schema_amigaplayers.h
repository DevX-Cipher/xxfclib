/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The amigaplayers schema family: what its family unit (xx_format_schema_amigaplayers.c)
 * and its formats' data files share. Formats: Marc Hawlitzeck's A.M. Composer module (.AMC); David 'Talin' Joiner & Joe Pearce's MaxTrax/Music-X module (MXTX.+SMPL.); Altar/Onyx's Onyx Music File (.OMF); Rainbow Arts' Palladix Sound System module (.PLX); Paul van der Valk's Medley Sound Editor module (.MSO); Morten Grouleff's EarAche module (.EA,.EAS); Simon Phipps/Core Design module (.CORE); Paul van der Valk's Future Player module (.FP); Janko Mrsic-Flogel's module (.JMF); Ben Daglish's SID (.BDS); Dave 'Uncle Tom' Lowe module (.DL); F.Sauer & Y.Grolet's Art & Magic module (.AAM); Steve Turner's module (.JPO); Mark Cooksey's module (.MC). */
#ifndef XX_FORMAT_SCHEMA_AMIGAPLAYERS_H
#define XX_FORMAT_SCHEMA_AMIGAPLAYERS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Read physical metadata without buffering whole sample or track payloads. */
typedef struct sxamip_view {sx_context*c;unsigned work;}sxamip_view;

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxamip_count16;
extern const sx_layout sxamip_count32;
extern const sx_layout sxamip_relative32;
extern const sx_layout sxamip_amc_header;
extern const sx_layout sxamip_amc_sample;
extern const sx_layout sxamip_mxtx_header;
extern const sx_layout sxamip_mxtx_event;
extern const sx_layout sxamip_mxtx_sample;
extern const sx_layout sxamip_mxtx_envelope;
extern const sx_layout sxamip_omf_identity;
extern const sx_layout sxamip_omf_position;
extern const sx_layout sxamip_omf_header_tail;
extern const sx_layout sxamip_omf_sample;
extern const sx_layout sxamip_omf_unknown;
extern const sx_layout sxamip_omf_pattern;
extern const sx_layout sxamip_omf_event;
extern const sx_layout sxamip_omf_sample_data;
extern const sx_layout sxamip_plx_header;
extern const sx_layout sxamip_plx_control;
extern const sx_layout sxamip_plx_instrument_offset;
extern const sx_layout sxamip_plx_volume;
extern const sx_layout sxamip_plx_note;
extern const sx_layout sxamip_plx_frequency;
extern const sx_layout sxamip_plx_speed;
extern const sx_layout sxamip_plx_delay;
extern const sx_layout sxamip_plx_instrument;
extern const sx_layout sxamip_mso_header;
extern const sx_layout sxamip_ea_header;
extern const sx_layout sxamip_ea_pattern;
extern const sx_layout sxamip_ea_position;
extern const sx_layout sxamip_ea_sample;
extern const sx_layout sxamip_ea_instrument;
extern const sx_layout sxamip_ea_magic;
extern const sx_layout sxamip_art_table_operand;
extern const sx_layout sxamip_art_limit_operand;
extern const sx_layout sxamip_art_relocation;
extern const sx_layout sxamip_art_marker;
extern const sx_layout sxamip_turner_address;
extern const sx_layout sxamip_turner_subsong;
extern const sx_layout sxamip_turner_sample_table;
extern const sx_layout sxamip_turner_sample_offset;
extern const sx_layout sxamip_turner_sample_length;
extern const sx_layout sxamip_cooksey_displacement;
extern const sx_layout sxamip_cooksey_sample_offset;
extern const sx_layout sxamip_cooksey_sample;
extern const sx_layout sxamip_cooksey_shifted_sample;
bool sxamip_span(sxamip_view*v,uint64_t at,uint64_t n,uint64_t end);
bool sxamip_row(sxamip_view*v,const sx_layout*l,uint64_t at,uint64_t end);
bool sxamip_table(sxamip_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end);
bool sxamip_u(sxamip_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end);
bool sxamip_be(sxamip_view*v,uint64_t p,unsigned n,uint64_t*x,uint64_t end);
bool sxamip_eq(sxamip_view*v,uint64_t p,const char*s,size_t n,uint64_t end);
bool sxamip_take(sxamip_view*v,const sx_layout*l,uint64_t*p,uint64_t count,uint64_t end);
bool sxamip_skip(sxamip_view*v,uint64_t*p,uint64_t n,uint64_t end);
bool sxamip_hunk_metadata(sxamip_view*v,unsigned kind);
bool sxamip_signed16_target(sxamip_view*v,uint64_t at,uint64_t base,uint64_t*out,uint64_t end);

/* Per-format walkers, called by the family's build. */
bool sx_hawlitzeck_amcomposer_build(sxamip_view*v);  /* audio/die_music/hawlitzeck_amcomposer/xx_hawlitzeck_amcomposer_data.c */
bool sx_talin_maxtrax_musicx_build(sxamip_view*v);  /* audio/die_music/talin_maxtrax_musicx/xx_talin_maxtrax_musicx_data.c */
bool sx_altar_onyxmusicfile_build(sxamip_view*v);  /* audio/die_music/altar_onyxmusicfile/xx_altar_onyxmusicfile_data.c */
bool sx_rainbowarts_palladixss_plx_build(sxamip_view*v);  /* audio/die_music/rainbowarts_palladixss_plx/xx_rainbowarts_palladixss_plx_data.c */
bool sx_vdvalk_medleysound_mso_build(sxamip_view*v);  /* audio/die_music/vdvalk_medleysound_mso/xx_vdvalk_medleysound_mso_data.c */
bool sx_grouleff_earache_build(sxamip_view*v);  /* audio/die_music/grouleff_earache/xx_grouleff_earache_data.c */
bool sx_phipps_coredesign_build(sxamip_view*v);  /* audio/die_music/phipps_coredesign/xx_phipps_coredesign_data.c */
bool sx_vdvalk_futureplayer_build(sxamip_view*v);  /* audio/die_music/vdvalk_futureplayer/xx_vdvalk_futureplayer_data.c */
bool sx_jmflogel_build(sxamip_view*v);  /* audio/die_music/jmflogel/xx_jmflogel_data.c */
bool sx_bendaglish_sid_build(sxamip_view*v);  /* audio/die_music/bendaglish_sid/xx_bendaglish_sid_data.c */
bool sx_davelowe_uncleart_build(sxamip_view*v);  /* audio/die_music/davelowe_uncleart/xx_davelowe_uncleart_data.c */
bool sx_sauer_artandmagic_build(sxamip_view*v);  /* audio/die_music/sauer_artandmagic/xx_sauer_artandmagic_data.c */
bool sx_turner_jpo_build(sxamip_view*v);  /* audio/die_music/turner_jpo/xx_turner_jpo_data.c */
bool sx_mark_cooksey_build(sxamip_view*v);  /* audio/die_music/mark_cooksey/xx_mark_cooksey_data.c */

#endif
