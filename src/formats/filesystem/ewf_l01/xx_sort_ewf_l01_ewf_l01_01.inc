/* Private sorting implementation from src/formats/filesystem/ewf_l01/xx_ewf_l01.c. */

static int l01_compare_keys(const void *left, const void *right, void *context)
{
    const l01_key *a = (const l01_key *)left;
    const l01_key *b = (const l01_key *)right;
    (void)context;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
