/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

/* Ascending uint32_t keys. An xx_sort_callback; no context. */
static int lzms_key_compare(const void *left, const void *right, void *context)
{
    uint32_t a = *(const uint32_t *)left, b = *(const uint32_t *)right;
    (void)context;
    return a < b ? -1 : (a > b ? 1 : 0);
}

/* Equal keys are identical values, so any sort gives the order the heapsort
 * this replaced gave. */
static void lzms_sort(uint32_t *a, size_t n)
{
    xx_sort_context(a, n, sizeof(*a), lzms_key_compare, NULL);
}
