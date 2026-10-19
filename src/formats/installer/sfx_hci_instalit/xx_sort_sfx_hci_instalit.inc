/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

/* Ascending unsigned values. An xx_sort_callback; no context. */
static int sh_unsigned_compare(const void *left, const void *right, void *context)
{
    unsigned a = *(const unsigned *)left, b = *(const unsigned *)right;
    (void)context;
    return a < b ? -1 : (a > b ? 1 : 0);
}
