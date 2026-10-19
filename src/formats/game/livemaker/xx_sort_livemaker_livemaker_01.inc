/* Private sorting implementation from src/formats/game/livemaker/xx_livemaker.c. */

static int lm_compare_keys(const void *left, const void *right, void *context)
{
    const lm_key *a = (const lm_key *)left;
    const lm_key *b = (const lm_key *)right;
    (void)context;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
