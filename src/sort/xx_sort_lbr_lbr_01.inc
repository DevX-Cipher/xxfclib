/* Private sorting implementation from src/formats/lbr/xx_lbr.c. */

static int lbr_compare_extents(const void *left, const void *right)
{
    const lbr_extent *a = (const lbr_extent *)left;
    const lbr_extent *b = (const lbr_extent *)right;
    return a->start < b->start ? -1 : (a->start > b->start ? 1 : 0);
}

static int lbr_compare_keys(const void *left, const void *right)
{
    const lbr_name_key *a = (const lbr_name_key *)left;
    const lbr_name_key *b = (const lbr_name_key *)right;
    int order = xx_str_cmp(a->key, b->key);
    if (order != 0) return order;
    return a->item < b->item ? -1 : (a->item > b->item ? 1 : 0);
}
