/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int xzp_compare(const void *left, const void *right, void *context)
{
    uint64_t a = *(const uint64_t *)left, b = *(const uint64_t *)right;
    (void)context;
    return a < b ? -1 : (a > b ? 1 : 0);
}

static void xzp_sort(uint64_t *a, size_t n)
{
    xx_sort_context(a, n, sizeof(*a), xzp_compare, NULL);
}
