/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT */
#ifndef XX_FORMAT_SCHEMA_H
#define XX_FORMAT_SCHEMA_H
#include "xxfclib/formats/xx_format.h"
#include "xxfclib/formats/xx_format_streams.h"
/* Return a concrete bounded schema when this format has a provider. */
const StreamDataStructs *xx_format_schema_get_stream_datastructs(Abstractformat *format);
/* Source compatibility for white-box callers; format objects are not mutated. */
static inline void xx_format_schema_attach(Abstractformat *format)
{
    (void)xx_format_schema_get_stream_datastructs(format);
}
#endif
