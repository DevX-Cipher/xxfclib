/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int32_t xx_wpk_med3(xx_wpk_entry *table, int32_t a, int32_t b, int32_t c)
{
    int32_t result = xx_wpk_compare(table, a, b);

    if (result < 1) {
        result = xx_wpk_compare(table, a, c);
        if (result < 0) {
            a = b;
            if (xx_wpk_compare(table, b, c) > 0) {
                a = c;
            }
        }
    } else {
        result = xx_wpk_compare(table, a, c);
        if (result > 0) {
            a = c;
            if (xx_wpk_compare(table, b, c) > 0) {
                a = b;
            }
        }
    }

    return a;
}
