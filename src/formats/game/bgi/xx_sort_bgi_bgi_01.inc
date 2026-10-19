/* Private sorting implementation from src/formats/game/bgi/xx_bgi.c. */

static int bgi_compare_keys(const void *left, const void *right, void *context)
{
    const bgi_key *a = (const bgi_key *)left;
    const bgi_key *b = (const bgi_key *)right;
    (void)context;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
