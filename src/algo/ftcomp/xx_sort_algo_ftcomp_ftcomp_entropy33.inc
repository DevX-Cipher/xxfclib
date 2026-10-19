/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void xx_ftcomp_sort(uint16_t *lut, const uint16_t *node, int32_t low, int32_t high)
{
    int32_t stack[66];
    int32_t depth = 2;
    stack[0] = low;
    stack[1] = high;
    while (depth != 0) {
        int32_t right = stack[depth - 1];
        int32_t left;
        depth -= 2;
        left = stack[depth];
        for (;;) {
            int32_t a = left, b = right, keep = right, next;
            if (b - a < 0x11) {
                int32_t probe = a;
                for (;;) {
                    int32_t hold = probe;
                    int32_t scan = a;
                    probe = hold + 1;
                    next = b;
                    if (probe > b) break;
                    while (scan < probe && node[lut[scan]] < node[lut[probe]]) ++scan;
                    if (scan <= hold) {
                        int32_t k = hold;
                        for (;;) {
                            uint16_t swap = lut[k];
                            lut[k] = lut[k + 1];
                            lut[k + 1] = swap;
                            --k;
                            if (k == scan - 1) break;
                        }
                    }
                }
            } else {
                int32_t pivot = (a + b) >> 1, i = a, j = b;
                for (;;) {
                    while (node[lut[i]] < node[lut[pivot]]) ++i;
                    while (node[lut[j]] > node[lut[pivot]]) --j;
                    if (i <= j) {
                        uint16_t swap = lut[i];
                        int32_t moved = j;
                        lut[i] = lut[j];
                        lut[j] = swap;
                        if (pivot != i) {
                            moved = pivot;
                            if (pivot == j) moved = i;
                        }
                        ++i;
                        --j;
                        pivot = moved;
                    }
                    if (i > j) break;
                }
                if (j - a < b - i) {
                    keep = j;
                    next = a;
                    if (i < b && depth + 2 <= 64) {
                        stack[depth] = i;
                        stack[depth + 1] = b;
                        depth += 2;
                    }
                } else {
                    next = i;
                    if (a < j && depth + 2 <= 64) {
                        stack[depth] = a;
                        stack[depth + 1] = j;
                        depth += 2;
                    }
                }
            }
            left = next;
            right = keep;
            if (left >= right) break;
        }
    }
}
