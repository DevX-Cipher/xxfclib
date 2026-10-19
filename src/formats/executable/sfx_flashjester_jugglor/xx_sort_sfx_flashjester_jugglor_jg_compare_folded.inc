/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int jg_compare_folded(const char *a, const char *b)
{
    for (;; ++a, ++b) {
        uint8_t x = jg_upper((uint8_t)*a), y = jg_upper((uint8_t)*b);
        if (x != y) return x < y ? -1 : 1;
        if (x == 0U) return 0;
    }
}
