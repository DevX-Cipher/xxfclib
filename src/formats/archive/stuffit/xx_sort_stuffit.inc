/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int sit_compare_names(const void *left, const void *right, void *context)
{
    const sit_name_key *a = (const sit_name_key *)left;
    const sit_name_key *b = (const sit_name_key *)right;
    int order;
    (void)context;
    order = sit_name_order(a->name, b->name);
    if (order != 0) return order;
    return a->item < b->item ? -1 : (a->item > b->item ? 1 : 0);
}
