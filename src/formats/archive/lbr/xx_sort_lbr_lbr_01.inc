/* Private sorting implementation from src/formats/archive/lbr/xx_lbr.c. */

static int lbr_compare_extents(const void *left, const void *right, void *context)
{
    const lbr_extent *a = (const lbr_extent *)left;
    const lbr_extent *b = (const lbr_extent *)right;
    (void)context;
    return a->start < b->start ? -1 : (a->start > b->start ? 1 : 0);
}

static int lbr_compare_keys(const void *left, const void *right, void *context)
{
    const lbr_name_key *a = (const lbr_name_key *)left;
    const lbr_name_key *b = (const lbr_name_key *)right;
    int order = xx_str_cmp(a->key, b->key);
    (void)context;
    if (order != 0) return order;
    return a->item < b->item ? -1 : (a->item > b->item ? 1 : 0);
}
