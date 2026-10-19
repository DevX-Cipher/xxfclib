/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void xx_wpk_sort_b(xx_wpk_entry *table, int32_t count, int32_t *stack_base, int32_t *stack_count)
{
    int32_t sp = 0;
    int32_t base = 0;
    int32_t cnt = count;

    for (;;) {
        int32_t mid;
        int32_t pa;
        int32_t pb;
        int32_t pc;
        int32_t pd;
        int32_t end;
        int32_t span;
        int32_t left;
        int32_t right;
        int32_t i;

        while (cnt < 2) {
            if (sp == 0) {
                return;
            }
            sp--;
            base = stack_base[sp];
            cnt = stack_count[sp];
        }

        if (cnt < 0x10) {
            int32_t gap = 3;

            while (gap > 0) {
                int32_t k = base;

                for (;;) {
                    int32_t j;
                    k += gap;
                    j = k;
                    if (k >= (base + cnt)) {
                        break;
                    }
                    while ((j > base) && (xx_wpk_compare(table, j - gap, j) > 0)) {
                        xx_wpk_swap(table, j, j - gap);
                        j -= gap;
                    }
                }

                gap -= 2;
            }

            if (sp == 0) {
                return;
            }
            sp--;
            base = stack_base[sp];
            cnt = stack_count[sp];
            continue;
        }

        mid = base + (cnt >> 1);

        if (cnt > 0x1D) {
            int32_t hi = base + cnt - 1;
            int32_t lo = base;

            if (cnt > 0x2A) {
                const int32_t step = cnt >> 3;
                lo = xx_wpk_med3(table, base, base + step, base + step * 2);
                mid = xx_wpk_med3(table, mid - step, mid, mid + step);
                hi = xx_wpk_med3(table, hi - step * 2, hi - step, hi);
            }

            mid = xx_wpk_med3(table, lo, mid, hi);
        }

        pc = base + cnt - 1;
        pa = base;
        pb = base;
        pd = pc;

        for (;;) {
            int32_t keep;

            while (pb <= pd) {
                const int32_t result = xx_wpk_compare(table, pb, mid);
                if (result > 0) {
                    break;
                }
                if (result == 0) {
                    keep = pb;
                    if (mid != pa) {
                        keep = mid;
                        if (mid == pb) {
                            keep = pa;
                        }
                    }
                    xx_wpk_swap(table, pa, pb);
                    pa++;
                    mid = keep;
                }
                pb++;
            }

            while (pb <= pd) {
                const int32_t result = xx_wpk_compare(table, pd, mid);
                if (result < 0) {
                    break;
                }
                if (result == 0) {
                    keep = pc;
                    if (mid != pd) {
                        keep = mid;
                        if (mid == pc) {
                            keep = pd;
                        }
                    }
                    xx_wpk_swap(table, pd, pc);
                    pc--;
                    mid = keep;
                }
                pd--;
            }

            if (pd < pb) {
                break;
            }

            keep = pd;
            if (mid != pb) {
                keep = mid;
                if (mid == pd) {
                    keep = pb;
                }
            }
            mid = keep;
            xx_wpk_swap(table, pb, pd);
            pb++;
            pd--;
        }

        end = base + cnt;
        span = (pa - base) < (pb - pa) ? (pa - base) : (pb - pa);
        for (i = 0; i < span; i++) {
            xx_wpk_swap(table, base + i, (pb - span) + i);
        }
        span = (pc - pd) < ((end - pc) - 1) ? (pc - pd) : ((end - pc) - 1);
        for (i = 0; i < span; i++) {
            xx_wpk_swap(table, pb + i, (end - span) + i);
        }

        left = pb - pa;
        right = pc - pd;

        if (sp == XX_WPK_SORT_STACK_B) {
            return;
        }

        if (right < left) {
            if (left < 2) {
                if (sp == 0) {
                    return;
                }
                sp--;
                base = stack_base[sp];
                cnt = stack_count[sp];
                continue;
            }
            stack_base[sp] = base;
            stack_count[sp] = left;
            base = end - right;
            cnt = right;
        } else {
            stack_base[sp] = end - right;
            stack_count[sp] = right;
            cnt = left;
        }

        sp++;
    }
}

static int xx_wpk_length_compare(const void *left, const void *right, void *context)
{
    const xx_wpk_entry *a = (const xx_wpk_entry *)left;
    const xx_wpk_entry *b = (const xx_wpk_entry *)right;

    (void)context;
    return (a->length < b->length) ? -1 : ((a->length > b->length) ? 1 : 0);
}

/* Stable sort by length, i.e. it keeps a run of equal lengths in the order
 * it was transmitted.  Kept only so a caller can probe all three orders; no
 * archive of the reference corpus wants it.  Any stable sort gives the same
 * order as the insertion sort this replaced. */
static void xx_wpk_sort_stable(xx_wpk_entry *table, int32_t count)
{
    if (count < 2) {
        return;
    }
    xx_sort_stable_context(table, (size_t)count, sizeof(*table), xx_wpk_length_compare, NULL);
}
