/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int32_t xx_wpk_compare(const xx_wpk_entry *table, int32_t left, int32_t right)
{
    return table[left].length - table[right].length;
}

static void xx_wpk_swap(xx_wpk_entry *table, int32_t left, int32_t right)
{
    xx_wpk_entry entry;

    entry = table[left];
    table[left] = table[right];
    table[right] = entry;
}

/* Reference sorter A: a simple quicksort over an explicit stack.  The point of
 * this function is its tie-break order inside a run of equal lengths, so
 * nothing here may be rewritten, simplified or replaced by a library sort. */
static void xx_wpk_sort_a(xx_wpk_entry *table, int32_t count, int32_t *stack_base, int32_t *stack_count)
{
    int32_t sp = 0;
    int32_t base = 0;
    int32_t cnt = count;

    for (;;) {
        bool again = true;

        while (again) {
            again = false;

            if (cnt > 1) {
                if (cnt == 2) {
                    if (xx_wpk_compare(table, base, base + 1) > 0) {
                        xx_wpk_swap(table, base, base + 1);
                    }
                } else {
                    int32_t index = 1;
                    int32_t less = 0;
                    int32_t equal_edge = 0;

                    xx_wpk_swap(table, base, base + (cnt >> 1));

                    while (index < cnt) {
                        const int32_t result = xx_wpk_compare(table, base + index, base);
                        if (result < 1) {
                            less++;
                            if (index != less) {
                                xx_wpk_swap(table, base + index, base + less);
                            }
                        }
                        if (result != 0) {
                            equal_edge = less;
                        }
                        index++;
                    }

                    if ((less != (cnt - 1)) || (equal_edge != 0)) {
                        if (less != 0) {
                            xx_wpk_swap(table, base + less, base);
                        }
                        cnt = cnt - less - 1;
                        index = (less == equal_edge) ? less : (equal_edge + 1);

                        if (sp == XX_WPK_SORT_STACK_A) {
                            return;
                        }

                        if (index < cnt) {
                            stack_base[sp] = base + less + 1;
                            stack_count[sp] = cnt;
                            cnt = index;
                        } else {
                            stack_base[sp] = base;
                            stack_count[sp] = index;
                            base = base + less + 1;
                        }

                        sp++;
                        again = true;
                    }
                }
            }
        }

        if (sp == 0) {
            return;
        }
        sp--;
        base = stack_base[sp];
        cnt = stack_count[sp];
    }
}
