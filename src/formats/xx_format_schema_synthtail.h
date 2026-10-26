/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The synthtail schema family: what its family unit (xx_format_schema_synthtail.c)
 * and its formats' data files share. Formats: TwinTeam TwinTrackPlayer DMO; Farbrausch V2 Synthesizer. */
#ifndef XX_FORMAT_SCHEMA_SYNTHTAIL_H
#define XX_FORMAT_SCHEMA_SYNTHTAIL_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxsynt_v2m_header;
extern const sx_layout sxsynt_v2m_time_delta_low_plane;
extern const sx_layout sxsynt_v2m_time_delta_middle_plane;
extern const sx_layout sxsynt_v2m_time_delta_high_plane;
extern const sx_layout sxsynt_v2m_time_signature_numerator_plane;
extern const sx_layout sxsynt_v2m_time_signature_denominator_plane;
extern const sx_layout sxsynt_v2m_timing_tpq_plane;
extern const sx_layout sxsynt_v2m_note_delta_plane;
extern const sx_layout sxsynt_v2m_velocity_delta_plane;
extern const sx_layout sxsynt_v2m_program_delta_plane;
extern const sx_layout sxsynt_v2m_pitch_lsb_delta_plane;
extern const sx_layout sxsynt_v2m_pitch_msb_delta_plane;
extern const sx_layout sxsynt_v2m_controller_delta_plane;
extern const sx_layout sxsynt_v2m_tempo;
extern const sx_layout sxsynt_v2m_note_count;
extern const sx_layout sxsynt_v2m_program_count;
extern const sx_layout sxsynt_v2m_pitch_count;
extern const sx_layout sxsynt_v2m_controller_count;
extern const sx_layout sxsynt_v2m_globals_length;
extern const sx_layout sxsynt_v2m_patchmap_length;
extern const sx_layout sxsynt_v2m_speech_length;
extern const sx_layout sxsynt_v2m_speech_count;
extern const sx_layout sxsynt_v2m_speech_offset;
extern const sx_layout sxsynt_dmo_cipher_header;

/* Per-format walkers, called by the family's build. */
bool sx_twinteam_twintrackplayer_dmo_build(sx_context *c);  /* audio/die_music/twinteam_twintrackplayer_dmo/xx_twinteam_twintrackplayer_dmo_data.c */
bool sx_farbrausch_v2synthesizer_build(sx_context *c);  /* audio/die_music/farbrausch_v2synthesizer/xx_farbrausch_v2synthesizer_data.c */

#endif
