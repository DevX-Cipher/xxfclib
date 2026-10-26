/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The cfefirmware schema family: what its family unit (xx_format_schema_cfefirmware.c)
 * and its formats' data files share. Formats: Broadcom CFE. */
#ifndef XX_FORMAT_SCHEMA_CFEFIRMWARE_H
#define XX_FORMAT_SCHEMA_CFEFIRMWARE_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxcfefw_header;

/* Per-format walkers, called by the family's build. */
bool sx_cfe_build(sx_context *c);  /* firmware/cfe/xx_cfe_data.c */

#endif
