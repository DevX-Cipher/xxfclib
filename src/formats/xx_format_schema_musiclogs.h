/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The musiclogs schema family: what its family unit (xx_format_schema_musiclogs.c)
 * and its formats' data files share. Formats: MIDI 2.0 Clip; Compute! Sidplayer MUS; YM2151 register log (CYM). */
#ifndef XX_FORMAT_SCHEMA_MUSICLOGS_H
#define XX_FORMAT_SCHEMA_MUSICLOGS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxlog_midi_clip_header;
extern const sx_layout sxlog_midi_ump_utility;
extern const sx_layout sxlog_midi_ump_system;
extern const sx_layout sxlog_midi_ump_midi1_note;
extern const sx_layout sxlog_midi_ump_midi1_channel;
extern const sx_layout sxlog_midi_ump_midi2_note;
extern const sx_layout sxlog_midi_ump_midi2_channel;
extern const sx_layout sxlog_midi_ump_sysex7;
extern const sx_layout sxlog_midi_ump_data128;
extern const sx_layout sxlog_midi_ump_flex;
extern const sx_layout sxlog_midi_ump_stream;
extern const sx_layout sxlog_sidplayer_header;
extern const sx_layout sxlog_sidplayer_command;
extern const sx_layout sxlog_sidplayer_halt;
extern const sx_layout sxlog_sidplayer_description;
extern const sx_layout sxlog_cym_register_write;
extern const sx_layout sxlog_cym_frame_wait;

/* Per-format walkers, called by the family's build. */
bool sx_clip_midi2_build(sx_context *c);  /* audio/die_music/clip_midi2/xx_clip_midi2_data.c */
bool sx_compute_sidplayer_mus_build(sx_context *c);  /* audio/die_music/compute_sidplayer_mus/xx_compute_sidplayer_mus_data.c */
bool sx_ym2151opmreglog_cym_build(sx_context *c);  /* audio/die_music/ym2151opmreglog_cym/xx_ym2151opmreglog_cym_data.c */

#endif
