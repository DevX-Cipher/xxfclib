/* Private sorting implementation from src/formats/installer/ghost_installer/xx_ghost_installer.c. */

static int gi_key_compare(const uint8_t *a, const uint8_t *b)
{
    while (*a == *b && *a != 0U) {
        ++a;
        ++b;
    }
    return *a == *b ? 0 : (*a < *b ? -1 : 1);
}

/* Context of gi_member_order: the members and their folded keys. */
typedef struct gi_order_context {
    const gi_member *members;
    const uint8_t *const *keys;
} gi_order_context;

/* Sort order of two member indices: folded name, names the archive carries
 * before renamed ones, then record order: a strict total order, so the sort
 * is deterministic. An xx_sort_callback; context is a gi_order_context. */
static int gi_member_order(const void *left, const void *right, void *context)
{
    const gi_order_context *order = (const gi_order_context *)context;
    size_t a = *(const size_t *)left;
    size_t b = *(const size_t *)right;
    int names = gi_key_compare(order->keys[a], order->keys[b]);
    bool left_renamed = order->members[a].suffix_length != 0U;
    bool right_renamed = order->members[b].suffix_length != 0U;
    if (names != 0) return names;
    if (left_renamed != right_renamed) return left_renamed ? 1 : -1;
    return a < b ? -1 : (a > b ? 1 : 0);
}

/* Member indices sorted by gi_member_order. The order is total, so the
 * allocation-free heapsort gives the order the merge sort did, and crafted
 * names cannot make it quadratic. */
static bool gi_sort(size_t *order, size_t count, const gi_member *members, const uint8_t *const *keys, xx_pd_struct *pd)
{
    gi_order_context context;
    size_t index;
    for (index = 0U; index < count; ++index) order[index] = index;
    if (count > 1U && pd && xx_pd_is_stopped(pd)) return false;
    context.members = members;
    context.keys = keys;
    xx_sort_context(order, count, sizeof(*order), gi_member_order, &context);
    return true;
}
