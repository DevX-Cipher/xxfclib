/* Private sorting implementation from src/formats/executable/dex/xx_dex.c. */

static int xx_dex_compare_map_items(const void *left, const void *right, void *context)
{
    const xx_dex_map_item *a = (const xx_dex_map_item *)left;
    const xx_dex_map_item *b = (const xx_dex_map_item *)right;
    (void)context;
    if (a->offset < b->offset) return -1;
    if (a->offset > b->offset) return 1;
    if (a->type < b->type) return -1;
    if (a->type > b->type) return 1;
    return 0;
}
