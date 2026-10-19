/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static bool xx_ubifs_leaf_less(const xx_ubifs_leaf *left, const xx_ubifs_leaf *right)
{
    if (left->inum != right->inum) return left->inum < right->inum;
    if (left->type != right->type) return left->type < right->type;
    return left->value < right->value;
}

static void xx_ubifs_sift_down(xx_ubifs_leaf *items, size_t start, size_t count)
{
    size_t root = start;
    while (root * 2U + 1U < count) {
        size_t child = root * 2U + 1U;
        xx_ubifs_leaf swap;
        if (child + 1U < count && xx_ubifs_leaf_less(&items[child], &items[child + 1U])) {
            ++child;
        }
        if (!xx_ubifs_leaf_less(&items[root], &items[child])) return;
        swap = items[root];
        items[root] = items[child];
        items[child] = swap;
        root = child;
    }
}

/* Heapsort again: attacker-sized input, no recursion, no scratch buffer. */
static void xx_ubifs_sort_leaves(xx_ubifs_leaf *items, size_t count)
{
    size_t index;
    if (count < 2U) return;
    for (index = count / 2U; index-- > 0U;) {
        xx_ubifs_sift_down(items, index, count);
    }
    for (index = count; index-- > 1U;) {
        xx_ubifs_leaf swap = items[0];
        items[0] = items[index];
        items[index] = swap;
        xx_ubifs_sift_down(items, 0U, index);
    }
}
