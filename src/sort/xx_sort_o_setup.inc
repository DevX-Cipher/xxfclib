/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int os_compare_folded(const char *left, const char *right)
{
    for (;; ++left, ++right) {
        uint8_t a = (uint8_t)*left, b = (uint8_t)*right;
        if (a >= (uint8_t)'A' && a <= (uint8_t)'Z') a = (uint8_t)(a - (uint8_t)'A' + (uint8_t)'a');
        if (b >= (uint8_t)'A' && b <= (uint8_t)'Z') b = (uint8_t)(b - (uint8_t)'A' + (uint8_t)'a');
        if (a != b) return a < b ? -1 : 1;
        if (a == 0U) return 0;
    }
}

static int os_compare_items(const void *left, const void *right)
{
    const os_item *a = *(const os_item *const *)left;
    const os_item *b = *(const os_item *const *)right;
    int order = os_compare_folded(a->name, b->name);
    if (order != 0) return order;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
