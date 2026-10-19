/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

/* Ascending by frequency, then node. Nodes are distinct symbols, so this is a
 * total order and xx_sort_context (the same heapsort the model rebuild used
 * before) gives the order the decoder expects. */
static int pax_pair_compare(const void *left, const void *right, void *context)
{
    const pax_pair *a = (const pax_pair *)left;
    const pax_pair *b = (const pax_pair *)right;
    (void)context;
    if (a->frequency != b->frequency) return a->frequency < b->frequency ? -1 : 1;
    return a->node < b->node ? -1 : (a->node > b->node ? 1 : 0);
}
