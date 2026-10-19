/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int jv3_compare(const void *left, const void *right, void *context)
{
    const jv3_sector *a = (const jv3_sector *)left;
    const jv3_sector *b = (const jv3_sector *)right;
    (void)context;
    if (a->cylinder != b->cylinder) return a->cylinder < b->cylinder ? -1 : 1;
    if (a->side != b->side) return a->side < b->side ? -1 : 1;
    if (a->id != b->id) return a->id < b->id ? -1 : 1;
    return a->order < b->order ? -1 : (a->order > b->order ? 1 : 0);
}

/* Bounded O(n log n) for any input; keys are unique thanks to `order`, so
 * the result is deterministic. */
static void jv3_sort(jv3_sector *items, size_t count)
{
    xx_sort_context(items, count, sizeof(*items), jv3_compare, NULL);
}
