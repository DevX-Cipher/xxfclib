/* Private sorting implementation from src/formats/installer/inno_setup/xx_inno_setup.c. */

static int inno_member_compare(const void *left, const void *right, void *context)
{
    const inno_member *x = (const inno_member *)left;
    const inno_member *y = (const inno_member *)right;
    (void)context;
    if (x->pass != y->pass) return x->pass < y->pass ? -1 : 1;
    return x->loc < y->loc ? -1 : (x->loc > y->loc ? 1 : 0);
}

/* Members in location order, so that the members of a solid chunk are read
 * front to back even when the [Files] entries list them in another order.
 * A location that several entries share is read once per pass: the first
 * reference of every location in the first pass, the second in the next,
 * and so on, so a chunk is decoded (number of references of its most shared
 * location) times, not once per shared entry.  Stable, as the merge sort
 * this replaced was, so the order is unchanged: O(n log n). */
static bool inno_sort_members(inno_ctx *ctx)
{
    uint32_t n = ctx->member_count, i;
    inno_member *a = ctx->members;
    uint32_t *seen;
    if (n < 2U) return true;
    seen = (uint32_t *)xx_mem_calloc(ctx->loc_count ? ctx->loc_count : 1U, sizeof(*seen));
    if (!seen) return false;
    for (i = 0U; i < n; ++i) a[i].pass = a[i].loc < ctx->loc_count ? seen[a[i].loc]++ : 0U;
    xx_mem_free(seen);
    xx_sort_stable_context(a, n, sizeof(*a), inno_member_compare, NULL);
    return true;
}
