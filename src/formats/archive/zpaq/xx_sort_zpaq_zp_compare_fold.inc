/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int zp_compare_fold(const char *x, const char *y, bool prefix_only)
{
    const unsigned char *a = (const unsigned char *)x;
    const unsigned char *b = (const unsigned char *)y;
    for (;;) {
        uint32_t ua = zp_fold_next(&a), ub = zp_fold_next(&b);
        if (prefix_only && ub == 0U) return 0;
        if (ua != ub) return ua < ub ? -1 : 1;
        if (ua == 0U) return 0;
    }
}
