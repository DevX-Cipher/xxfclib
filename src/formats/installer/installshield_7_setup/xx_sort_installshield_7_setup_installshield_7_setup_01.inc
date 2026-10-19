/* Private sorting implementation from src/formats/installer/installshield_7_setup/xx_installshield_7_setup.c. */

static int is7_compare_keys(const void *left, const void *right, void *context)
{
    const is7_key *a = (const is7_key *)left;
    const is7_key *b = (const is7_key *)right;
    (void)context;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
