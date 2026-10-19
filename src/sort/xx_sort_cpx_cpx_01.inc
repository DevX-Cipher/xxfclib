/* Private sorting implementation from src/formats/cpx/xx_cpx.c. */

/* Heapsort: a member's extent is the distance to the next payload offset in
 * sorted order, and the record order is not that order. */
static void cpx_sift(int64_t *values, size_t start, size_t count)
{
    size_t root = start;
    for (;;) {
        size_t child = root * 2U + 1U;
        size_t swap = root;
        if (child >= count) break;
        if (values[swap] < values[child]) swap = child;
        if (child + 1U < count && values[swap] < values[child + 1U]) swap = child + 1U;
        if (swap == root) break;
        {
            int64_t temporary = values[root];
            values[root] = values[swap];
            values[swap] = temporary;
        }
        root = swap;
    }
}

static void cpx_sort_offsets(int64_t *values, size_t count)
{
    size_t index;
    if (count < 2U) return;
    for (index = count / 2U; index-- > 0U;) cpx_sift(values, index, count);
    for (index = count; index-- > 1U;) {
        int64_t temporary = values[0];
        values[0] = values[index];
        values[index] = temporary;
        cpx_sift(values, 0U, index);
    }
}
