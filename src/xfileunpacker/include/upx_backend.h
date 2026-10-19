/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#ifndef XFILEUNPACKER_UPX_BACKEND_H
#define XFILEUNPACKER_UPX_BACKEND_H
#include "core.h"

/* One executable, LZMA compression, level 1..9. No input is ever executed. */
int xfu_upx_create(const xfu_request *request, xx_pd_struct *pd);
#endif
