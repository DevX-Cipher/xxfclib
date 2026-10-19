/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#ifndef XFILEUNPACKER_FREEARC_SFX_BACKEND_H
#define XFILEUNPACKER_FREEARC_SFX_BACKEND_H
#include "core.h"
#include <xxfclib/io/xx_io.h>
/* Explicit extraction-only Windows SFX with an unmodified FreeArc payload. */
int xfu_freearc_sfx_create(const xfu_request *request, xx_pd_struct *pd);
/* Checked XFU PE-overlay locator; preserves the input cursor, -1 if absent. */
int64_t xfu_freearc_sfx_payload_offset(xx_io_device *source);
#endif
