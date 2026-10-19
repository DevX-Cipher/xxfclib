/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int zp_compare_keys(const void *left, const void *right, void *context)
{
    const zp_name_key *a = (const zp_name_key *)left;
    const zp_name_key *b = (const zp_name_key *)right;
    int order = zp_compare_fold(a->key, b->key, false);
    (void)context;
    if (order != 0) return order;
    return a->item < b->item ? -1 : (a->item > b->item ? 1 : 0);
}
