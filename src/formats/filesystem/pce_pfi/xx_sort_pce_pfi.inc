/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int pfi_compare_u32(const void *left, const void *right, void *context)
{
    uint32_t a = *(const uint32_t *)left, b = *(const uint32_t *)right;
    (void)context;
    return a < b ? -1 : a > b ? 1 : 0;
}
