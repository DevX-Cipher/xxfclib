/* Private sorting implementation from src/formats/archive/ftcomp/xx_ftcomp.c. */

/* -------------------------------------------------------- Huffman build -- */

/* FUN_006630c0, transliterated rather than replaced by a library sort: the
 * order it leaves equal weights in decides the shape of the tree and so the
 * codes, and a stable sort builds a different, wrong table. */
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

/* The post-RLE alphabet uses the same unstable reference sort as the Huffman
 * builder, but its frequency counters are full 32-bit integers. Equal
 * counts must keep the reference ordering: the table's bytes refer to
 * inverted rank positions, so a stable sort silently corrupts the output. */
static void xx_ftcomp_sort_rle(uint16_t *lut, const uint32_t *count)
{
    int32_t stack[66];
    int32_t depth = 2;
    stack[0] = 0;
    stack[1] = 255;
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
                    while (scan < probe && count[lut[scan]] < count[lut[probe]]) ++scan;
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
                    while (count[lut[i]] < count[lut[pivot]]) ++i;
                    while (count[lut[j]] > count[lut[pivot]]) --j;
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
