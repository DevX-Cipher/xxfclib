/* Private sorting implementation from src/formats/game/cpk/xx_cpk.c. */

static int cpk_compare_keys(const void *left, const void *right, void *context)
{
    const cpk_key *a = (const cpk_key *)left;
    const cpk_key *b = (const cpk_key *)right;
    (void)context;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
