/* Private sorting implementation from src/formats/dxa/xx_dxa.c. */

static int dxa_compare_keys(const void *left, const void *right)
{
    const dxa_key *a = (const dxa_key *)left;
    const dxa_key *b = (const dxa_key *)right;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
