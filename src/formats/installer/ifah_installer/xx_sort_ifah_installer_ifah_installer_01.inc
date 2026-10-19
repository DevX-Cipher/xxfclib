/* Private sorting implementation from src/formats/installer/ifah_installer/xx_ifah_installer.c. */

static int ifah_compare_keys(const void *left, const void *right, void *context)
{
    const ifah_key *a = (const ifah_key *)left;
    const ifah_key *b = (const ifah_key *)right;
    (void)context;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
