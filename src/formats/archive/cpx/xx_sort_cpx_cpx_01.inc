/* Private sorting implementation from src/formats/archive/cpx/xx_cpx.c. */

/* A member's extent is the distance to the next payload offset in sorted
 * order, and the record order is not that order. Equal offsets are
 * indistinguishable, so any sort gives the same array. */
static int cpx_compare_offsets(const void *left, const void *right, void *context)
{
    int64_t a = *(const int64_t *)left;
    int64_t b = *(const int64_t *)right;
    (void)context;
    return a < b ? -1 : (a > b ? 1 : 0);
}

static void cpx_sort_offsets(int64_t *values, size_t count)
{
    xx_sort_context(values, count, sizeof(*values), cpx_compare_offsets, NULL);
}
