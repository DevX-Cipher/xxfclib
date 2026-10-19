/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int rz_cmp(const void *a, const void *b, void *context)
{
    const rz_extent *x = (const rz_extent *)a, *y = (const rz_extent *)b;
    (void)context;
    return x->start < y->start ? -1 : x->start > y->start;
}
