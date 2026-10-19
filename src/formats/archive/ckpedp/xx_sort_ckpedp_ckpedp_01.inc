/* Private sorting implementation from src/formats/archive/ckpedp/xx_ckpedp.c. */

static int ce_compare_ranges(const void *left, const void *right, void *context)
{
    const ce_range *a = (const ce_range *)left;
    const ce_range *b = (const ce_range *)right;
    (void)context;
    return a->start < b->start ? -1 : a->start > b->start ? 1 : 0;
}
