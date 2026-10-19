/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int xx_ubi_leb_compare(const void *left, const void *right, void *context)
{
    const xx_ubi_leb *a = (const xx_ubi_leb *)left;
    const xx_ubi_leb *b = (const xx_ubi_leb *)right;
    (void)context;
    if (a->lnum != b->lnum) return a->lnum < b->lnum ? -1 : 1;
    return a->sqnum < b->sqnum ? -1 : (a->sqnum > b->sqnum ? 1 : 0);
}

/* Heapsort: the block list is attacker-sized, so an O(n log n) in-place sort
 * with no recursion and no scratch allocation is the safe choice.
 * xx_sort_context is that heapsort, with the same comparisons and swaps, so
 * copies with an equal lnum and sqnum keep their former relative order. */
static void xx_ubi_sort_lebs(xx_ubi_leb *items, size_t count)
{
    xx_sort_context(items, count, sizeof(*items), xx_ubi_leb_compare, NULL);
}
