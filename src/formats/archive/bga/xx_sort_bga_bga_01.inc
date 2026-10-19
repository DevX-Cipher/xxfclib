/* Private sorting implementation from src/formats/archive/bga/xx_bga.c. */

static int bga_compare_keys(const void *left, const void *right, void *context)
{
    const bga_key *a = (const bga_key *)left;
    const bga_key *b = (const bga_key *)right;
    (void)context;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
