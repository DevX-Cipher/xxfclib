/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static bool pax_pair_less(const pax_pair *a, const pax_pair *b)
{
    return a->frequency < b->frequency || (a->frequency == b->frequency && a->node < b->node);
}

static void pax_heap_sift(pax_pair *items, int32_t start, int32_t count)
{
    int32_t root = start;
    for (;;) {
        int32_t child = root * 2 + 1;
        int32_t swap = root;
        pax_pair temp;
        if (child >= count) break;
        if (pax_pair_less(&items[swap], &items[child])) swap = child;
        if (child + 1 < count && pax_pair_less(&items[swap], &items[child + 1])) swap = child + 1;
        if (swap == root) break;
        temp = items[root];
        items[root] = items[swap];
        items[swap] = temp;
        root = swap;
    }
}

/* Ascending heap sort: the model rebuild runs often enough that a quadratic
 * sort over a 2048-symbol alphabet would dominate the decode. */
static void pax_sort(pax_pair *items, int32_t count)
{
    int32_t index;
    if (!items || count < 2) return;
    for (index = count / 2 - 1; index >= 0; --index) pax_heap_sift(items, index, count);
    for (index = count - 1; index > 0; --index) {
        pax_pair temp = items[0];
        items[0] = items[index];
        items[index] = temp;
        pax_heap_sift(items, 0, index);
    }
}
