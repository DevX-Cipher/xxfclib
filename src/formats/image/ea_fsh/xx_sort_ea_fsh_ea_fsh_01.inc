/* Private sorting implementation from src/formats/image/ea_fsh/xx_ea_fsh.c. */

/* Member indices by (data_offset, index); index is unique, so this is a
 * total order. An xx_sort_callback; context is the member array. */
static int xx_ea_fsh_compare(const void *left, const void *right, void *context)
{
    const xx_ea_fsh_member *m = (const xx_ea_fsh_member *)context;
    const xx_ea_fsh_member *x = &m[*(const uint32_t *)left];
    const xx_ea_fsh_member *y = &m[*(const uint32_t *)right];
    if (x->data_offset != y->data_offset) return x->data_offset < y->data_offset ? -1 : 1;
    return x->index < y->index ? -1 : (x->index > y->index ? 1 : 0);
}

static void xx_ea_fsh_sort(const xx_ea_fsh_member *m, uint32_t *order, size_t n)
{
    xx_sort_context(order, n, sizeof(*order), xx_ea_fsh_compare, (void *)m);
}
