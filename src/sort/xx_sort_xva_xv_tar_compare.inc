/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int xv_tar_compare(const void *a, const void *b)
{
    return strcmp(((const xv_tar *)a)->name, ((const xv_tar *)b)->name);
}
