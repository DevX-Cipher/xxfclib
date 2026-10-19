/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static bool xx_ubi_leb_less(const xx_ubi_leb *left, const xx_ubi_leb *right)
{
    if (left->lnum != right->lnum) return left->lnum < right->lnum;
    return left->sqnum < right->sqnum;
}

/* Heapsort: the block list is attacker-sized, so an O(n log n) in-place sort
 * with no recursion and no scratch allocation is the safe choice. */
static void xx_ubi_sift_down(xx_ubi_leb *items, size_t start, size_t count)
{
    size_t root = start;
    while (root * 2U + 1U < count) {
        size_t child = root * 2U + 1U;
        xx_ubi_leb swap;
        if (child + 1U < count && xx_ubi_leb_less(&items[child], &items[child + 1U])) {
            ++child;
        }
        if (!xx_ubi_leb_less(&items[root], &items[child])) return;
        swap = items[root];
        items[root] = items[child];
        items[child] = swap;
        root = child;
    }
}

static void xx_ubi_sort_lebs(xx_ubi_leb *items, size_t count)
{
    size_t index;
    if (count < 2U) return;
    for (index = count / 2U; index-- > 0U;) {
        xx_ubi_sift_down(items, index, count);
    }
    for (index = count; index-- > 1U;) {
        xx_ubi_leb swap = items[0];
        items[0] = items[index];
        items[index] = swap;
        xx_ubi_sift_down(items, 0U, index);
    }
}
