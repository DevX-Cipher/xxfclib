/* Private sorting implementation from src/formats/livemaker/xx_livemaker.c. */

static int lm_compare_keys(const void *left, const void *right)
{
    const lm_key *a = (const lm_key *)left;
    const lm_key *b = (const lm_key *)right;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
