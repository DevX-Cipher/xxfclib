/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The schema as die_engine.cmake lists it. The engine's link closure has no
 * reader factory or canonical readers, so the paths that delegate to them are
 * compiled out. Defining the profile here rather than on the target keeps it
 * with the source list for every consumer of XXFC_DIE_ENGINE_SOURCES.
 *
 * This file lives outside src/formats on purpose: the full library and
 * xxformats.cmake glob src/formats for xx_*.c, and a second copy of the
 * schema there would define xx_format_schema_attach twice.
 */
#define XXFC_PROFILE_DIE_ENGINE
/* The unity file gathers the engine and every family unit into this one
 * translation unit, so die_engine.cmake lists a single schema source. */
#include "../formats/xx_format_schema_unity.inc"
