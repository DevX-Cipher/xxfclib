/* Private sorting implementation from src/formats/ewf2_lx01/xx_ewf2_lx01.c. */

static int lx_compare_keys(const void *left, const void *right)
{
    const lx_key *a = (const lx_key *)left;
    const lx_key *b = (const lx_key *)right;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
