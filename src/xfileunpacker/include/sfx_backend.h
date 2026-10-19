/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#ifndef XFILEUNPACKER_SFX_BACKEND_H
#define XFILEUNPACKER_SFX_BACKEND_H

#include "core.h"

/* Explicit, extraction-only Windows 7-Zip SFX; never inferred from .exe. */
int xfu_sfx_create(const xfu_request *request, xx_pd_struct *pd);

#endif
