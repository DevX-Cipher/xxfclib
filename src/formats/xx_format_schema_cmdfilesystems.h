/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The cmdfilesystems schema family: what its family unit (xx_format_schema_cmdfilesystems.c)
 * and its formats' data files share. Formats: CMD FD (D1M/D2M/D4M). */
#ifndef XX_FORMAT_SCHEMA_CMDFILESYSTEMS_H
#define XX_FORMAT_SCHEMA_CMDFILESYSTEMS_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxcmdfs_cmd_fd_system_header;
extern const sx_layout sxcmdfs_cmd_fd_partition_sector_link;
extern const sx_layout sxcmdfs_cmd_fd_first_partition;
extern const sx_layout sxcmdfs_cmd_fd_partition;
extern const sx_layout sxcmdfs_cmd_native_header;
extern const sx_layout sxcmdfs_cmd_native_bam_header;

/* Per-format walkers, called by the family's build. */
bool sx_cmd_fd_build(sx_context *c);  /* filesystem/cmd_fd/xx_cmd_fd_data.c */

#endif
