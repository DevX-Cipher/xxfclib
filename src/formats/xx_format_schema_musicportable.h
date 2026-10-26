/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The musicportable schema family: what its family unit (xx_format_schema_musicportable.c)
 * and its formats' data files share. Formats: Tero 'kometbomb' Lindeman's ProtoTracker module (.SONG); Brain Control's TuneFish module (.TF4); Atari ST module (.SND,.SNDH); Ain/GIGAMIX MGSDRV chiptune (.MGS); ASCII MuSICA chiptune (.BGM,.BGR); J.M.A. Segura/Psycledelics' Psycle Modular Music Creation Studio module (.PSY). */
#ifndef XX_FORMAT_SCHEMA_MUSICPORTABLE_H
#define XX_FORMAT_SCHEMA_MUSICPORTABLE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxportable_proto_section;
extern const sx_layout sxportable_proto_version0;
extern const sx_layout sxportable_proto_version1;
extern const sx_layout sxportable_proto_version17;
extern const sx_layout sxportable_proto_text;
extern const sx_layout sxportable_proto_dimensions;
extern const sx_layout sxportable_proto_sequence_row_count;
extern const sx_layout sxportable_proto_pattern_count;
extern const sx_layout sxportable_proto_macro_count;
extern const sx_layout sxportable_proto_pattern_rows;
extern const sx_layout sxportable_proto_sequence_pattern_index_plane;
extern const sx_layout sxportable_proto_note_effect_plane;
extern const sx_layout sxportable_proto_note_parameter_plane;
extern const sx_layout sxportable_proto_effect_plane;
extern const sx_layout sxportable_proto_effect_parameter_plane;
extern const sx_layout sxportable_tf4_song_header;
extern const sx_layout sxportable_tf4_event_count;
extern const sx_layout sxportable_tf4_tag;
extern const sx_layout sxportable_tf4_instrument;
extern const sx_layout sxportable_tf4_row_delta;
extern const sx_layout sxportable_tf4_note_plane;
extern const sx_layout sxportable_tf4_velocity_plane;
extern const sx_layout sxportable_ice_music_header;
extern const sx_layout sxportable_mgs_identity;
extern const sx_layout sxportable_mgs_identity_single_newline;
extern const sx_layout sxportable_mgs_description;
extern const sx_layout sxportable_mgs_text_end;
extern const sx_layout sxportable_bgm_bsave_header;
extern const sx_layout sxportable_bgm_channel_header;
extern const sx_layout sxportable_bgm_bto_header;
extern const sx_layout sxportable_bgm_encoded_text;
extern const sx_layout sxportable_psy2_header;
extern const sx_layout sxportable_psy2_pattern_header;
extern const sx_layout sxportable_psy2_event;
extern const sx_layout sxportable_psy3_header;
extern const sx_layout sxportable_psy3_chunk;
extern const sx_layout sxportable_psy3_title;
extern const sx_layout sxportable_psy3_author;
extern const sx_layout sxportable_psy3_comment;
extern const sx_layout sxportable_psy3_sequence_name;
extern const sx_layout sxportable_psy3_pattern_name;
extern const sx_layout sxportable_psy3_song_info;
extern const sx_layout sxportable_psy3_track_state;
extern const sx_layout sxportable_psy3_sequence;
extern const sx_layout sxportable_psy3_pattern_index;
extern const sx_layout sxportable_psy3_pattern;
extern const sx_layout sxportable_psy3_compressed_bytes;
bool sxportable_span(sx_context*c,uint64_t p,uint64_t n,uint64_t end);
bool sxportable_read(sx_context*c,uint64_t p,void*b,size_t n,uint64_t end);
bool sxportable_byte(sx_context*c,uint64_t p,uint8_t*b,uint64_t end);
bool sxportable_row(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n,uint64_t end);
bool sxportable_plane(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t n,uint64_t end);
bool sxportable_string(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t end);

/* Per-format walkers, called by the family's build. */
bool sx_kometbomb_prototracker_song_build(sx_context *c);  /* audio/die_music/kometbomb_prototracker_song/xx_kometbomb_prototracker_song_data.c */
bool sx_braincontrol_tunefish_tf4_build(sx_context *c);  /* audio/die_music/braincontrol_tunefish_tf4/xx_braincontrol_tunefish_tf4_data.c */
bool sx_atarist_sndh_build(sx_context *c);  /* audio/die_music/atarist_sndh/xx_atarist_sndh_data.c */
bool sx_gigamix_mgsdrv_build(sx_context *c);  /* audio/die_music/gigamix_mgsdrv/xx_gigamix_mgsdrv_data.c */
bool sx_ascii_musica_bgm_build(sx_context *c);  /* audio/die_music/ascii_musica_bgm/xx_ascii_musica_bgm_data.c */
bool sx_segura_psyclemmcs_build(sx_context *c);  /* audio/die_music/segura_psyclemmcs/xx_segura_psyclemmcs_data.c */

#endif
