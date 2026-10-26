/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Shared parser internals for the optional data-structure stream.
 */
#ifndef XX_TAR_LZ4_DATASTRUCTS_INTERNAL_H
#define XX_TAR_LZ4_DATASTRUCTS_INTERNAL_H
#include "xxfclib/formats/archive/tar_lz4/xx_tar_lz4.h"
#include "../tar_common/xx_tar_common.h"
#include "xxfclib/algo/lz4/xx_lz4.h"
#include "xxfclib/io/xx_io.h"
#include "xxfclib/memory/xx_memory.h"
#include <limits.h>
#include "xxfclib/data/xx_data.h"

xx_tar_common *xx_tar_lz4_common(xx_tar_lz4 *tar_lz4, bool create);
bool xx_tar_lz4_decode(Abstractformat *outer, xx_io_device *destination, int64_t *compressed_size, xx_pd_struct *pd);

#endif
