/* Private sorting implementation from src/formats/finstall/xx_finstall.c. */

static int fi_compare_keys(const void *left, const void *right)
{
    const fi_key *a = (const fi_key *)left, *b = (const fi_key *)right;
    int order = fi_compare_folded(a->name, b->name);
    if (order != 0) return order;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
