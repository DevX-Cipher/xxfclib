/* Private sorting implementation from src/formats/ifah_installer/xx_ifah_installer.c. */

static int ifah_compare_keys(const void *left, const void *right)
{
    const ifah_key *a = (const ifah_key *)left;
    const ifah_key *b = (const ifah_key *)right;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
