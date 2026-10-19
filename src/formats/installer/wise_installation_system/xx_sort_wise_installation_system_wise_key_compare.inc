/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int wise_key_compare(const void *left, const void *right, void *context)
{
    const wise_dedupe *d = (const wise_dedupe *)context;
    uint32_t a = *(const uint32_t *)left, b = *(const uint32_t *)right;
    if (d->hash[a] != d->hash[b]) return d->hash[a] < d->hash[b] ? -1 : 1;
    if (d->points[a] != d->points[b]) return d->points[a] < d->points[b] ? -1 : 1;
    return a < b ? -1 : (a > b ? 1 : 0);
}

/* (folded name, index): the fallback for a run of equal keys that holds
 * more than WISE_DEDUPE_REPS different names. */
static int wise_run_compare(const void *left, const void *right, void *context)
{
    const wise_dedupe *d = (const wise_dedupe *)context;
    uint32_t a = *(const uint32_t *)left, b = *(const uint32_t *)right;
    int order = wise_name_order(d->items[a].name, d->items[b].name);
    if (order != 0) return order;
    return a < b ? -1 : (a > b ? 1 : 0);
}
