/* Private sorting implementation from src/formats/ckpedp/xx_ckpedp.c. */

static int ce_compare_ranges(const void *left, const void *right)
{
    const ce_range *a = (const ce_range *)left;
    const ce_range *b = (const ce_range *)right;
    return a->start < b->start ? -1 : a->start > b->start ? 1 : 0;
}
