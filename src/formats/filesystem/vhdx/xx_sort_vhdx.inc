/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

/* Equal values are indistinguishable, so any sort gives the same array. */
static int vhdx_compare_values(const void *left, const void *right, void *context)
{
    uint64_t a = *(const uint64_t *)left;
    uint64_t b = *(const uint64_t *)right;
    (void)context;
    return a < b ? -1 : (a > b ? 1 : 0);
}

static void vhdx_sort(uint64_t *values, size_t count)
{
    xx_sort_context(values, count, sizeof(*values), vhdx_compare_values, NULL);
}
