/* Private sorting implementation from src/formats/compactpro/xx_compactpro.c. */

static int xx_compactpro_range_compare(const void *left, const void *right)
{
    const xx_compactpro_range *a = (const xx_compactpro_range *)left;
    const xx_compactpro_range *b = (const xx_compactpro_range *)right;

    if (a->start != b->start) return a->start < b->start ? -1 : 1;
    if (a->end != b->end) return a->end < b->end ? -1 : 1;
    return 0;
}
