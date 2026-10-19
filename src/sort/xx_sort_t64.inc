/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int t64_compare_order(const void *left, const void *right)
{
    const t64_order *a = (const t64_order *)left;
    const t64_order *b = (const t64_order *)right;
    if (a->offset != b->offset) return a->offset < b->offset ? -1 : 1;
    return a->item < b->item ? -1 : (a->item > b->item ? 1 : 0);
}

static int t64_compare_keys(const void *left, const void *right)
{
    const t64_name_key *a = (const t64_name_key *)left;
    const t64_name_key *b = (const t64_name_key *)right;
    int order = xx_str_cmp(a->key, b->key);
    if (order != 0) return order;
    return a->item < b->item ? -1 : (a->item > b->item ? 1 : 0);
}
