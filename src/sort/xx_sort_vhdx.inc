/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void vhdx_sift(uint64_t *values, size_t root, size_t count)
{
    for (;;) {
        size_t child = root * 2U + 1U;
        uint64_t swap;
        if (child >= count) return;
        if (child + 1U < count && values[child] < values[child + 1U]) ++child;
        if (values[root] >= values[child]) return;
        swap = values[root];
        values[root] = values[child];
        values[child] = swap;
        root = child;
    }
}

static void vhdx_sort(uint64_t *values, size_t count)
{
    size_t index, end;
    if (count < 2U) return;
    for (index = count / 2U; index-- > 0U;) vhdx_sift(values, index, count);
    for (end = count - 1U; end > 0U; --end) {
        uint64_t swap = values[0];
        values[0] = values[end];
        values[end] = swap;
        vhdx_sift(values, 0U, end);
    }
}
