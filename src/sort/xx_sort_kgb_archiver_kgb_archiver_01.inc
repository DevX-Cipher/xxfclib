/* Private sorting implementation from src/formats/kgb_archiver/xx_kgb_archiver.c. */

/* ---- duplicate names ---------------------------------------------------- */

static int kgb_compare_folded(const char *left, const char *right)
{
    for (;; ++left, ++right) {
        char a = kgb_upper(*left), b = kgb_upper(*right);
        if (a != b) return (unsigned char)a < (unsigned char)b ? -1 : 1;
        if (!a) return 0;
    }
}

/* Folded name, then original names before suffixed ones, then index: in a
 * group of equal names the first keeps its name. */
static int kgb_compare_items(const void *left, const void *right)
{
    const kgb_item *a = *(const kgb_item *const *)left;
    const kgb_item *b = *(const kgb_item *const *)right;
    int result = kgb_compare_folded(a->name, b->name);
    if (result) return result;
    if (a->renamed != b->renamed) return a->renamed ? 1 : -1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
