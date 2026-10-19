/* Private sorting implementation from src/formats/installshield_7_setup2/xx_installshield_7_setup2.c. */

static int is7b_compare_keys(const void *left, const void *right)
{
    const is7b_key *a = (const is7b_key *)left;
    const is7b_key *b = (const is7b_key *)right;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
