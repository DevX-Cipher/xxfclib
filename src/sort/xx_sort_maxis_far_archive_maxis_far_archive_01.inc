/* Private sorting implementation from src/formats/maxis_far_archive/xx_maxis_far_archive.c. */

static int far_compare_keys(const void *left, const void *right)
{
    const far_key *a = (const far_key *)left;
    const far_key *b = (const far_key *)right;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
