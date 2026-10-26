/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The musicfurther schema family: what its family unit (xx_format_schema_musicfurther.c)
 * and its formats' data files share. Formats: Amadeus Voxon Flash Tracker. */
#ifndef XX_FORMAT_SCHEMA_MUSICFURTHER_H
#define XX_FORMAT_SCHEMA_MUSICFURTHER_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sxfurther_fls_header;
extern const sx_layout sxfurther_fls_pattern_addresses;
extern const sx_layout sxfurther_fls_ornament_address;
extern const sx_layout sxfurther_fls_sample_descriptor;
extern const sx_layout sxfurther_fls_delay;
extern const sx_layout sxfurther_fls_order;
extern const sx_layout sxfurther_fls_orders_end;
extern const sx_layout sxfurther_fls_ornament_step;
extern const sx_layout sxfurther_fls_sample_tick;

/* Per-format walkers, called by the family's build. */
bool sx_amadeusvoxon_flashtracker_build(sx_context *c);  /* audio/die_music/amadeusvoxon_flashtracker/xx_amadeusvoxon_flashtracker_data.c */

#endif
