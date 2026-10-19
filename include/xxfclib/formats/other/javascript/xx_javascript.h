/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT */
#ifndef XX_JAVASCRIPT_H
#define XX_JAVASCRIPT_H

#include "xxfclib/xxfc_defs.h"
#include "xxfclib/data/xx_pd.h"
#include "xxfclib/io/xx_io.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Apply DIE's JavaScript minified/compiled heuristic to a byte range.
 * The scan is streaming, stops at the first NUL like Binary.getString(), and
 * does not allocate a whole-file string or retained-code segments. */
XXFC_API bool xx_javascript_is_minified(xx_io_device *device, int64_t offset, int64_t size, xx_pd_struct *pd);

#ifdef __cplusplus
}
#endif

#endif
