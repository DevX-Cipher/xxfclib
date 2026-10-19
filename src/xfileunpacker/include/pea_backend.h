/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#ifndef XFILEUNPACKER_PEA_BACKEND_H
#define XFILEUNPACKER_PEA_BACKEND_H

#include "core.h"

/* Plaintext PEA 1.x, stored or independently zlib-compressed blocks. */
int xfu_pea_create(const xfu_request *request, xx_pd_struct *pd);

#endif
