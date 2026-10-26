/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The gameremaining schema family: what its family unit (xx_format_schema_gameremaining.c)
 * and its formats' data files share. Formats: Bruns, RPG Maker MV, YCG, Unreal PAK, Fallout DAT, LiveMaker GAL and Smile game packs. */
#ifndef XX_FORMAT_SCHEMA_GAMEREMAINING_H
#define XX_FORMAT_SCHEMA_GAMEREMAINING_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxgr_bruns_een_header;
extern const sx_layout sxgr_rpgmv_header;
extern const sx_layout sxgr_smile_game_header;
extern const sx_layout sxgr_ycg_header;
extern const sx_layout sxgr_fallout2_footer;
extern const sx_layout sxgr_fallout2_directory;
extern const sx_layout sxgr_fallout2_name_length;
extern const sx_layout sxgr_game_name_length;
extern const sx_layout sxgr_game_name;
extern const sx_layout sxgr_fallout2_entry;
extern const sx_layout sxgr_unreal_pak_footer_v1;
extern const sx_layout sxgr_unreal_pak_footer_v4;
extern const sx_layout sxgr_unreal_pak_footer_v7;
extern const sx_layout sxgr_unreal_pak_string_length;
extern const sx_layout sxgr_unreal_pak_string;
extern const sx_layout sxgr_unreal_pak_directory_count;
extern const sx_layout sxgr_unreal_pak_entry_v1;
extern const sx_layout sxgr_unreal_pak_entry_v2;
extern const sx_layout sxgr_unreal_pak_block_count;
extern const sx_layout sxgr_unreal_pak_block;
extern const sx_layout sxgr_unreal_pak_entry_flags;
extern const sx_layout sxgr_gal_envelope;
extern const sx_layout sxgr_gal_header;
extern const sx_layout sxgr_gal_frame;
extern const sx_layout sxgr_gal_palette_entry;
extern const sx_layout sxgr_gal_layer;
extern const sx_layout sxgr_gal_layer_lock;
extern const sx_layout sxgr_gal_layer_size;
extern const sx_layout sxgr_gal_alpha_size;

/* Per-format walkers, called by the family's build. */
bool sx_ue2_games_build(sx_context *c);  /* game/ue2_games/xx_ue2_games_data.c */

#endif
