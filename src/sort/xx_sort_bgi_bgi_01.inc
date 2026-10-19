/* Private sorting implementation from src/formats/bgi/xx_bgi.c. */

static int bgi_compare_keys(const void *left, const void *right)
{
    const bgi_key *a = (const bgi_key *)left;
    const bgi_key *b = (const bgi_key *)right;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
