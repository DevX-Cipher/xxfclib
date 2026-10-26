/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Shared parser internals for the optional data-structure stream.
 */
#ifndef XX_TAR_GZ_DATASTRUCTS_INTERNAL_H
#define XX_TAR_GZ_DATASTRUCTS_INTERNAL_H
#include "xxfclib/formats/archive/tar_gz/xx_tar_gz.h"
#include "../tar_common/xx_tar_common.h"
#include "xxfclib/algo/deflate/xx_deflate.h"
#include "xxfclib/formats/archive/gz/xx_gz.h"
#include "xxfclib/memory/xx_memory.h"
#include <limits.h>
#include "xxfclib/data/xx_data.h"

xx_tar_common *xx_tar_gz_common(xx_tar_gz *tar_gz);
bool xx_tar_gz_decode(Abstractformat *outer, xx_io_device *destination, int64_t *compressed_size, xx_pd_struct *pd);

#endif
