/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#include "xx_bzip2_internal.h"
#include "xxfclib/rt/xx_rt.h"

/* length is capped at BZ2_MAX_BLOCK_SIZE, so the four-array scratch size
 * computed below cannot overflow size_t. */
_Static_assert((size_t)BZ2_MAX_BLOCK_SIZE <= SIZE_MAX / (4U * sizeof(uint32_t)), "bzip2 BWT scratch size overflows size_t");

/* Sort circular suffixes by doubling the compared prefix. Each round is a
 * stable counting sort of integer classes, rather than repeatedly comparing
 * circular byte strings. The shifted-order array becomes the new class array
 * after sorting, keeping scratch storage to four uint32_t arrays.
 *
 * If doubling does not split any class, each class has a unique continuation
 * class at that prefix distance. All later doubling rounds therefore leave
 * the partition unchanged: tied rotations are identical for their complete
 * length. This permits early termination for periodic input, not just when
 * every rotation becomes unique.
 */
#include "xx_sort_algo_bzip2_bzip2_bwt.inc"
