/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int sx_fork_compare(const void *left, const void *right)
{
    const sx_fork *a = *(const sx_fork *const *)left;
    const sx_fork *b = *(const sx_fork *const *)right;
    if (a->index != b->index) return a->index < b->index ? -1 : 1;
    return a->sequence < b->sequence ? -1 : (a->sequence > b->sequence ? 1 : 0);
}
