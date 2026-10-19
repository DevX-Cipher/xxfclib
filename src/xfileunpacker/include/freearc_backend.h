/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#ifndef XFILEUNPACKER_FREEARC_BACKEND_H
#define XFILEUNPACKER_FREEARC_BACKEND_H

#include "core.h"

/* Plaintext FreeArc container creation; not the older SEA ARC format. */
int xfu_freearc_create(const xfu_request *request, xx_pd_struct *pd);

#endif
