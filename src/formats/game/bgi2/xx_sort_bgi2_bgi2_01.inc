/* Private sorting implementation from src/formats/game/bgi2/xx_bgi2.c. */

static int bgi2_compare_keys(const void *left, const void *right, void *context)
{
    const bgi2_key *a = (const bgi2_key *)left;
    const bgi2_key *b = (const bgi2_key *)right;
    (void)context;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
