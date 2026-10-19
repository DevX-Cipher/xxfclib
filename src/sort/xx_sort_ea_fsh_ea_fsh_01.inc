/* Private sorting implementation from src/formats/ea_fsh/xx_ea_fsh.c. */

/* Heapsort of member indices by (data_offset, index). */
static bool xx_ea_fsh_less(const xx_ea_fsh_member *m, uint32_t a, uint32_t b)
{
    return m[a].data_offset < m[b].data_offset || (m[a].data_offset == m[b].data_offset && m[a].index < m[b].index);
}

static void xx_ea_fsh_sift(const xx_ea_fsh_member *m, uint32_t *order, size_t root, size_t n)
{
    for (;;) {
        size_t child = root * 2U + 1U;
        uint32_t t;
        if (child >= n) return;
        if (child + 1U < n && xx_ea_fsh_less(m, order[child], order[child + 1U])) {
            ++child;
        }
        if (!xx_ea_fsh_less(m, order[root], order[child])) return;
        t = order[root];
        order[root] = order[child];
        order[child] = t;
        root = child;
    }
}

static void xx_ea_fsh_sort(const xx_ea_fsh_member *m, uint32_t *order, size_t n)
{
    size_t i;

    if (n < 2U) return;
    for (i = n / 2U; i > 0U; --i) xx_ea_fsh_sift(m, order, i - 1U, n);
    for (i = n - 1U; i > 0U; --i) {
        uint32_t t = order[0];
        order[0] = order[i];
        order[i] = t;
        xx_ea_fsh_sift(m, order, 0U, i);
    }
}
