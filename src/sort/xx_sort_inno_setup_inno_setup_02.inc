/* Private sorting implementation from src/formats/inno_setup/xx_inno_setup.c. */

static bool inno_member_before(const inno_member *x, const inno_member *y)
{
    return x->pass != y->pass ? x->pass < y->pass : x->loc < y->loc;
}

/* Members in location order, so that the members of a solid chunk are read
 * front to back even when the [Files] entries list them in another order.
 * A location that several entries share is read once per pass: the first
 * reference of every location in the first pass, the second in the next,
 * and so on, so a chunk is decoded (number of references of its most shared
 * location) times, not once per shared entry.  Stable merge sort through a
 * temporary array: O(n log n). */
static bool inno_sort_members(inno_ctx *ctx)
{
    uint32_t n = ctx->member_count, width, i;
    inno_member *a = ctx->members, *b, *tmp;
    uint32_t *seen;
    bool sorted = true;
    if (n < 2U) return true;
    seen = (uint32_t *)xx_mem_calloc(ctx->loc_count ? ctx->loc_count : 1U, sizeof(*seen));
    if (!seen) return false;
    for (i = 0U; i < n; ++i) a[i].pass = a[i].loc < ctx->loc_count ? seen[a[i].loc]++ : 0U;
    xx_mem_free(seen);
    for (i = 1U; i < n; ++i)
        if (inno_member_before(&a[i], &a[i - 1U])) sorted = false;
    if (sorted) return true;
    b = (inno_member *)xx_mem_alloc((size_t)n * sizeof(*b));
    if (!b) return false;
    for (width = 1U; width<n; width = width> n / 2U ? n : width * 2U) {
        uint32_t lo;
        for (lo = 0U; lo<n; lo = lo + 2U * width> n || lo + 2U * width < lo ? n : lo + 2U * width) {
            uint32_t mid = n - lo < width ? n : lo + width;
            uint32_t hi = n - mid < width ? n : mid + width, p = lo, q = mid, o = lo;
            while (p < mid && q < hi) b[o++] = inno_member_before(&a[q], &a[p]) ? a[q++] : a[p++];
            while (p < mid) b[o++] = a[p++];
            while (q < hi) b[o++] = a[q++];
        }
        tmp = a;
        a = b;
        b = tmp;
    }
    if (a != ctx->members) {
        xx_rt_memcpy(ctx->members, a, (size_t)n * sizeof(*a));
        xx_mem_free(a);
    } else {
        xx_mem_free(b);
    }
    return true;
}
