/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int wise_offset_compare(const void *left, const void *right, void *context)
{
    int64_t a = *(const int64_t *)left, b = *(const int64_t *)right;
    (void)context;
    return a < b ? -1 : (a > b ? 1 : 0);
}
