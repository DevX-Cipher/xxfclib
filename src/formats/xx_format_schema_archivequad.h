/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The archivequad schema family: what its family unit (xx_format_schema_archivequad.c)
 * and its formats' data files share. Formats: QUAD. */
#ifndef XX_FORMAT_SCHEMA_ARCHIVEQUAD_H
#define XX_FORMAT_SCHEMA_ARCHIVEQUAD_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxquad_header;

/* Per-format walkers, called by the family's build. */
bool sx_quad_build(sx_context *c);  /* archive/quad/xx_quad_data.c */

#endif
