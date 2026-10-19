/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void xzp_sift(uint64_t *a, size_t start, size_t n)
{
    size_t root = start;
    for (;;) {
        size_t child = root * 2U + 1U, top = root;
        if (child >= n) return;
        if (a[child] > a[top]) top = child;
        if (child + 1U < n && a[child + 1U] > a[top]) top = child + 1U;
        if (top == root) return;
        {
            uint64_t t = a[root];
            a[root] = a[top];
            a[top] = t;
        }
        root = top;
    }
}

static void xzp_sort(uint64_t *a, size_t n)
{
    size_t i;
    if (n < 2U) return;
    for (i = n / 2U; i-- > 0U;) xzp_sift(a, i, n);
    for (i = n - 1U; i > 0U; --i) {
        uint64_t t = a[0];
        a[0] = a[i];
        a[i] = t;
        xzp_sift(a, 0U, i);
    }
}
