/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int xv_chunk_compare(const void *a, const void *b)
{
    uint64_t x = ((const xv_chunk *)a)->physical, y = ((const xv_chunk *)b)->physical;
    return x < y ? -1 : x > y ? 1 : 0;
}
