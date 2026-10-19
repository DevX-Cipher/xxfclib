/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void lzms_heap_sift(uint32_t *a, size_t root, size_t n)
{
    for (;;) {
        size_t child = root * 2U + 1U;
        uint32_t t;
        if (child >= n) return;
        if (child + 1U < n && a[child + 1U] > a[child]) ++child;
        if (a[root] >= a[child]) return;
        t = a[root];
        a[root] = a[child];
        a[child] = t;
        root = child;
    }
}

static void lzms_sort(uint32_t *a, size_t n)
{
    size_t i;
    if (n < 2U) return;
    for (i = n / 2U; i-- > 0U;) lzms_heap_sift(a, i, n);
    for (i = n - 1U; i > 0U; --i) {
        uint32_t t = a[0];
        a[0] = a[i];
        a[i] = t;
        lzms_heap_sift(a, 0U, i);
    }
}
