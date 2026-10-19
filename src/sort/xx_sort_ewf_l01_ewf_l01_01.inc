/* Private sorting implementation from src/formats/ewf_l01/xx_ewf_l01.c. */

static int l01_compare_keys(const void *left, const void *right)
{
    const l01_key *a = (const l01_key *)left;
    const l01_key *b = (const l01_key *)right;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
