/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The firmwaretail schema family: what its family unit (xx_format_schema_firmwaretail.c)
 * and its formats' data files share. Formats: eCos kernel. */
#ifndef XX_FORMAT_SCHEMA_FIRMWARETAIL_H
#define XX_FORMAT_SCHEMA_FIRMWARETAIL_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxftl_ecos_exception_prefix_le;
extern const sx_layout sxftl_ecos_exception_prefix_le_nop;
extern const sx_layout sxftl_ecos_exception_prefix_be;
extern const sx_layout sxftl_ecos_exception_prefix_be_nop;

/* Per-format walkers, called by the family's build. */
bool sx_ecos_build(sx_context *c);  /* firmware/ecos/xx_ecos_data.c */

#endif
