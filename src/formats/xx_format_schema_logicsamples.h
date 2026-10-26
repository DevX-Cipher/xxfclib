/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The logicsamples schema family: what its family unit (xx_format_schema_logicsamples.c)
 * and its formats' data files share. Formats: HxC logic analyzer samples. */
#ifndef XX_FORMAT_SCHEMA_LOGICSAMPLES_H
#define XX_FORMAT_SCHEMA_LOGICSAMPLES_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxlogic_logic_signal_sample;

/* Per-format walkers, called by the family's build. */
bool sx_hxc_logic_analyzer_build(sx_context *c);  /* filesystem/hxc_logic_analyzer/xx_hxc_logic_analyzer_data.c */

#endif
