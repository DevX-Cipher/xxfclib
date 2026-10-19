/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#ifndef XFILEUNPACKER_SPLIT_BACKEND_H
#define XFILEUNPACKER_SPLIT_BACKEND_H

#include "core.h"

bool xfu_split_is_first_volume(const char *path);
int xfu_split_run(const xfu_request *request, xx_pd_struct *pd);

#endif
