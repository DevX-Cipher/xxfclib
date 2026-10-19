/* Private sorting implementation from src/formats/installer/installshield_issetupstream/xx_installshield_issetupstream.c. */

static int iss_compare_keys(const void *left, const void *right, void *context)
{
    const iss_key *a = (const iss_key *)left;
    const iss_key *b = (const iss_key *)right;
    (void)context;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
