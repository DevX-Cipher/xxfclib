/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Shared parser internals for the optional data-structure stream.
 */
#ifndef XX_TAR_XZ_DATASTRUCTS_INTERNAL_H
#define XX_TAR_XZ_DATASTRUCTS_INTERNAL_H
#include "xxfclib/formats/archive/tar_xz/xx_tar_xz.h"
#include "../tar_common/xx_tar_common.h"
#include "xxfclib/algo/crc/xx_crc.h"
#include "xxfclib/algo/lzma/xx_lzma.h"
#include "xxfclib/formats/archive/xz/xx_xz.h"
#include "xxfclib/io/xx_io.h"
#include "xxfclib/memory/xx_memory.h"
#include <limits.h>
#include "xxfclib/data/xx_data.h"

xx_tar_common *xx_tar_xz_common(xx_tar_xz *tar_xz, bool create);
bool xx_tar_xz_decode(Abstractformat *outer, xx_io_device *destination, int64_t *compressed_size, xx_pd_struct *pd);

#endif
