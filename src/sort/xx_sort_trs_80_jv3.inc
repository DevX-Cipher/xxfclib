/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static bool jv3_less(const jv3_sector *a, const jv3_sector *b)
{
    if (a->cylinder != b->cylinder) return a->cylinder < b->cylinder;
    if (a->side != b->side) return a->side < b->side;
    if (a->id != b->id) return a->id < b->id;
    return a->order < b->order;
}

static void jv3_sift(jv3_sector *items, size_t root, size_t count)
{
    for (;;) {
        size_t child = root * 2U + 1U;
        jv3_sector swap;
        if (child >= count) return;
        if (child + 1U < count && jv3_less(&items[child], &items[child + 1U])) ++child;
        if (!jv3_less(&items[root], &items[child])) return;
        swap = items[root];
        items[root] = items[child];
        items[child] = swap;
        root = child;
    }
}

/* Heap sort: bounded O(n log n) for any input; keys are unique thanks to
 * `order`, so the result is deterministic. */
static void jv3_sort(jv3_sector *items, size_t count)
{
    size_t index;
    if (count < 2U) return;
    for (index = count / 2U; index > 0U; --index) jv3_sift(items, index - 1U, count);
    for (index = count - 1U; index > 0U; --index) {
        jv3_sector swap = items[0];
        items[0] = items[index];
        items[index] = swap;
        jv3_sift(items, 0U, index);
    }
}
