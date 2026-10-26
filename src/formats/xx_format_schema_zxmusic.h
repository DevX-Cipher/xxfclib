/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The zxmusic schema family: what its family unit (xx_format_schema_zxmusic.c)
 * and its formats' data files share. Formats: Alonecoder Chiptracker; Woloszyk Etracker; Bzyk Soundtracker Ayst11; Dexus Prosoundmaker; Asc Advancedsoundmaster V1; Asc Advancedsoundmaster V0; Doctormax Globaltracker Gtr; Goldendisk Protracker Pt1 Co; Goldendisk Protracker Pt2; Goldendisk Protracker Pt3; Kva Prosoundcreator; Orionsand Fasttracker Ftc; Ksa Soundtrackerpro Stp; Bzyk Soundtracker Stc Zxs; Stmusicstcrecompv2 St3; Lave Digitalmusicmaker; Raster Musictracker; Sqdigitaltracker; Undergroundsystems Digitalstudio; Redlimited Extremetracker. */
#ifndef XX_FORMAT_SCHEMA_ZXMUSIC_H
#define XX_FORMAT_SCHEMA_ZXMUSIC_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxzxm_zx_position;
extern const sx_layout sxzxm_zx_ornament_step;
extern const sx_layout sxzxm_zx_sample_offset;
extern const sx_layout sxzxm_zx_ornament_offset;
extern const sx_layout sxzxm_zx_sample_address;
extern const sx_layout sxzxm_zx_ornament_address;
extern const sx_layout sxzxm_zx_pattern_channels;
extern const sx_layout sxzxm_zx_pattern_addresses;
extern const sx_layout sxzxm_zx_positions_count;
extern const sx_layout sxzxm_zx_marker;
extern const sx_layout sxzxm_zx_text;
extern const sx_layout sxzxm_globaltracker_header;
extern const sx_layout sxzxm_globaltracker_positions;
extern const sx_layout sxzxm_globaltracker_position;
extern const sx_layout sxzxm_fasttracker_header;
extern const sx_layout sxzxm_fasttracker_position;
extern const sx_layout sxzxm_fasttracker_pattern_end;
extern const sx_layout sxzxm_prosoundcreator_header;
extern const sx_layout sxzxm_prosoundcreator_sample_ref;
extern const sx_layout sxzxm_prosoundcreator_ornament_ref;
extern const sx_layout sxzxm_prosoundcreator_position;
extern const sx_layout sxzxm_prosoundcreator_end;
extern const sx_layout sxzxm_prosoundcreator_loop;
extern const sx_layout sxzxm_prosoundcreator_sample_line;
extern const sx_layout sxzxm_prosoundcreator_ornament_line;
extern const sx_layout sxzxm_prosoundmaker_header;
extern const sx_layout sxzxm_prosoundmaker_position;
extern const sx_layout sxzxm_prosoundmaker_pattern;
extern const sx_layout sxzxm_stc_header;
extern const sx_layout sxzxm_stc_positions;
extern const sx_layout sxzxm_stc_position;
extern const sx_layout sxzxm_stc_pattern;
extern const sx_layout sxzxm_stc_sample_prefix;
extern const sx_layout sxzxm_stc_sample_line;
extern const sx_layout sxzxm_stc_sample_loop;
extern const sx_layout sxzxm_stc_ornament_prefix;
extern const sx_layout sxzxm_st3_header;
extern const sx_layout sxzxm_st3_identity;
extern const sx_layout sxzxm_st3_position;
extern const sx_layout sxzxm_st3_object_table;
extern const sx_layout sxzxm_st3_sample;
extern const sx_layout sxzxm_st3_sample_line;
extern const sx_layout sxzxm_stp_header;
extern const sx_layout sxzxm_stp_identity;
extern const sx_layout sxzxm_stp_positions;
extern const sx_layout sxzxm_stp_position;
extern const sx_layout sxzxm_etracker_header;
extern const sx_layout sxzxm_etracker_pattern;
extern const sx_layout sxzxm_etracker_sample_offset;
extern const sx_layout sxzxm_etracker_ornament_offset;
extern const sx_layout sxzxm_etracker_position;
extern const sx_layout sxzxm_chiptracker_header;
extern const sx_layout sxzxm_chiptracker_sample;
extern const sx_layout sxzxm_chiptracker_sample_name;
extern const sx_layout sxzxm_chiptracker_note;
extern const sx_layout sxzxm_chiptracker_parameter;
extern const sx_layout sxzxm_dmm_header;
extern const sx_layout sxzxm_dmm_playback;
extern const sx_layout sxzxm_dmm_mixing;
extern const sx_layout sxzxm_dmm_sample;
extern const sx_layout sxzxm_dmm_event;
extern const sx_layout sxzxm_sqd_layout;
extern const sx_layout sxzxm_sqd_sample;
extern const sx_layout sxzxm_sqd_title;
extern const sx_layout sxzxm_sqd_positions_limit;
extern const sx_layout sxzxm_sqd_playback;
extern const sx_layout sxzxm_sqd_event;
extern const sx_layout sxzxm_ayst11_header;
extern const sx_layout sxzxm_ayst11_song;
extern const sx_layout sxzxm_ayst11_song_data;
extern const sx_layout sxzxm_st1_sample;
extern const sx_layout sxzxm_st1_position;
extern const sx_layout sxzxm_st1_song_length;
extern const sx_layout sxzxm_st1_ornament_step;
extern const sx_layout sxzxm_st1_playback;
extern const sx_layout sxzxm_rmt_binary_header;
extern const sx_layout sxzxm_rmt_binary_segment;
extern const sx_layout sxzxm_rmt_header;
extern const sx_layout sxzxm_rmt_instrument_address;
extern const sx_layout sxzxm_rmt_track_low;
extern const sx_layout sxzxm_rmt_track_high;
extern const sx_layout sxzxm_rmt_instrument;
extern const sx_layout sxzxm_digitalstudio_order;
extern const sx_layout sxzxm_digitalstudio_header;
extern const sx_layout sxzxm_digitalstudio_sample;
extern const sx_layout sxzxm_digitalstudio_event;
extern const sx_layout sxzxm_extremetracker_header;
extern const sx_layout sxzxm_extremetracker_pattern_size;
extern const sx_layout sxzxm_extremetracker_memory;
extern const sx_layout sxzxm_extremetracker_sample;
extern const sx_layout sxzxm_extremetracker_event;
bool sxzxm_span(sx_context*c,uint64_t p,uint64_t n);
bool sxzxm_read(sx_context*c,uint64_t p,void*b,size_t n);
uint16_t sxzxm16(const uint8_t*b);
bool sxzxm_u16(sx_context*c,uint64_t p,uint16_t*v);
bool sxzxm_u8(sx_context*c,uint64_t p,uint8_t*v);
bool sxzxm_eq(sx_context*c,uint64_t p,const char*s,size_t n);
bool sxzxm_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count);
bool sxzxm_opt(sx_context*c,const sx_layout*l,uint64_t p,uint64_t count);
bool sxzxm_object(sx_context*c,uint64_t p,unsigned kind);
bool sxzxm_pt(sx_context*c,unsigned version);
bool sxzxm_asc(sx_context*c,bool v1);

/* Per-format walkers, called by the family's build. */
bool sx_alonecoder_chiptracker_build(sx_context *c);  /* audio/die_music/alonecoder_chiptracker/xx_alonecoder_chiptracker_data.c */
bool sx_woloszyk_etracker_build(sx_context *c);  /* audio/die_music/woloszyk_etracker/xx_woloszyk_etracker_data.c */
bool sx_bzyk_soundtracker_ayst11_build(sx_context *c);  /* audio/die_music/bzyk_soundtracker_ayst11/xx_bzyk_soundtracker_ayst11_data.c */
bool sx_dexus_prosoundmaker_build(sx_context *c);  /* audio/die_music/dexus_prosoundmaker/xx_dexus_prosoundmaker_data.c */
bool sx_asc_advancedsoundmaster_v1_build(sx_context *c);  /* audio/die_music/asc_advancedsoundmaster_v1/xx_asc_advancedsoundmaster_v1_data.c */
bool sx_asc_advancedsoundmaster_v0_build(sx_context *c);  /* audio/die_music/asc_advancedsoundmaster_v0/xx_asc_advancedsoundmaster_v0_data.c */
bool sx_doctormax_globaltracker_gtr_build(sx_context *c);  /* audio/die_music/doctormax_globaltracker_gtr/xx_doctormax_globaltracker_gtr_data.c */
bool sx_goldendisk_protracker_pt1_co_build(sx_context *c);  /* audio/die_music/goldendisk_protracker_pt1_co/xx_goldendisk_protracker_pt1_co_data.c */
bool sx_goldendisk_protracker_pt2_build(sx_context *c);  /* audio/die_music/goldendisk_protracker_pt2/xx_goldendisk_protracker_pt2_data.c */
bool sx_goldendisk_protracker_pt3_build(sx_context *c);  /* audio/die_music/goldendisk_protracker_pt3/xx_goldendisk_protracker_pt3_data.c */
bool sx_kva_prosoundcreator_build(sx_context *c);  /* audio/die_music/kva_prosoundcreator/xx_kva_prosoundcreator_data.c */
bool sx_orionsand_fasttracker_ftc_build(sx_context *c);  /* audio/die_music/orionsand_fasttracker_ftc/xx_orionsand_fasttracker_ftc_data.c */
bool sx_ksa_soundtrackerpro_stp_build(sx_context *c);  /* audio/die_music/ksa_soundtrackerpro_stp/xx_ksa_soundtrackerpro_stp_data.c */
bool sx_bzyk_soundtracker_stc_zxs_build(sx_context *c);  /* audio/die_music/bzyk_soundtracker_stc_zxs/xx_bzyk_soundtracker_stc_zxs_data.c */
bool sx_stmusicstcrecompv2_st3_build(sx_context *c);  /* audio/die_music/stmusicstcrecompv2_st3/xx_stmusicstcrecompv2_st3_data.c */
bool sx_lave_digitalmusicmaker_build(sx_context *c);  /* audio/die_music/lave_digitalmusicmaker/xx_lave_digitalmusicmaker_data.c */
bool sx_raster_musictracker_build(sx_context *c);  /* audio/die_music/raster_musictracker/xx_raster_musictracker_data.c */
bool sx_sqdigitaltracker_build(sx_context *c);  /* audio/die_music/sqdigitaltracker/xx_sqdigitaltracker_data.c */
bool sx_undergroundsystems_digitalstudio_build(sx_context *c);  /* audio/die_music/undergroundsystems_digitalstudio/xx_undergroundsystems_digitalstudio_data.c */
bool sx_redlimited_extremetracker_build(sx_context *c);  /* audio/die_music/redlimited_extremetracker/xx_redlimited_extremetracker_data.c */

#endif
