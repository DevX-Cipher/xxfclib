/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The vintagefilesystems schema family: what its family unit (xx_format_schema_vintagefilesystems.c)
 * and its formats' data files share. Formats: Thomson FD (BASIC-DOS); NorthStar NSI. */
#ifndef XX_FORMAT_SCHEMA_VINTAGEFILESYSTEMS_H
#define XX_FORMAT_SCHEMA_VINTAGEFILESYSTEMS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxvintage_thomson_volume_header;
extern const sx_layout sxvintage_thomson_fat_prefix;
extern const sx_layout sxvintage_thomson_fat_entry;
extern const sx_layout sxvintage_thomson_directory_entry;
extern const sx_layout sxvintage_thomson_directory_state;
extern const sx_layout sxvintage_northstar_directory_entry;
extern const sx_layout sxvintage_northstar_executable_entry;
bool sxvintage_finish(sx_context*c);

/* Per-format walkers, called by the family's build. */
bool sx_thomson_fd_build(sx_context *c);  /* filesystem/thomson_fd/xx_thomson_fd_data.c */
bool sx_northstar_nsi_build(sx_context *c);  /* filesystem/northstar_nsi/xx_northstar_nsi_data.c */

#endif
