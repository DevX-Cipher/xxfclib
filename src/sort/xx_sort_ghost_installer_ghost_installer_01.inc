/* Private sorting implementation from src/formats/ghost_installer/xx_ghost_installer.c. */

static int gi_key_compare(const uint8_t *a, const uint8_t *b)
{
    while (*a == *b && *a != 0U) {
        ++a;
        ++b;
    }
    return *a == *b ? 0 : (*a < *b ? -1 : 1);
}

/* Folded name, names the archive carries before renamed ones, then record
 * order: a strict total order, so the sort is deterministic. */
static int gi_member_order(const gi_member *members, const uint8_t *const *keys, size_t left, size_t right)
{
    int names = gi_key_compare(keys[left], keys[right]);
    bool left_renamed = members[left].suffix_length != 0U;
    bool right_renamed = members[right].suffix_length != 0U;
    if (names != 0) return names;
    if (left_renamed != right_renamed) return left_renamed ? 1 : -1;
    return left < right ? -1 : (left > right ? 1 : 0);
}

/* Bottom-up merge sort of member indices by gi_member_order: n log n
 * compares whatever the input; @p scratch holds @p count indices. */
static bool gi_sort(size_t *order, size_t *scratch, size_t count, const gi_member *members, const uint8_t *const *keys, xx_pd_struct *pd)
{
    size_t width;
    size_t index;
    size_t *from = order;
    size_t *to = scratch;
    for (index = 0U; index < count; ++index) order[index] = index;
    for (width = 1U; width<count; width = width> count / 2U ? count : width * 2U) {
        size_t start;
        size_t *swap;
        if (pd && xx_pd_is_stopped(pd)) return false;
        for (start = 0U; start < count; start += 2U * width) {
            size_t middle = start + width < count ? start + width : count;
            size_t end = middle + width < count ? middle + width : count;
            size_t left = start;
            size_t right = middle;
            size_t at = start;
            while (left < middle && right < end) to[at++] = gi_member_order(members, keys, from[left], from[right]) <= 0 ? from[left++] : from[right++];
            while (left < middle) to[at++] = from[left++];
            while (right < end) to[at++] = from[right++];
            if (end == count) break;
        }
        swap = from;
        from = to;
        to = swap;
    }
    if (from != order) xx_mem_copy(order, from, count * sizeof(*order));
    return true;
}
