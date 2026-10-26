/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Shared parser internals for the optional data-structure stream.
 */
#ifndef XX_TAR_BZ2_DATASTRUCTS_INTERNAL_H
#define XX_TAR_BZ2_DATASTRUCTS_INTERNAL_H
#include "xxfclib/formats/archive/tar_bz2/xx_tar_bz2.h"
#include "xxfclib/algo/bzip2/xx_bzip2.h"
#include "xxfclib/formats/archive/bz2/xx_bz2.h"
#include "xxfclib/memory/xx_memory.h"
#include "xx_tar_common.h"
#include <limits.h>

xx_tar_common *xx_tar_bz2_common(Abstractformat *self);
bool xx_tar_bz2_decode(Abstractformat *outer, xx_io_device *destination, int64_t *compressed_size, xx_pd_struct *pd);

#endif
