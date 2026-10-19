/* Private sorting implementation from src/formats/ar/xx_ar.c. */

/* Order of two extraction paths under the fold above. With prefix_only,
 * returns 0 as soon as y is used up (x starts with y). */
static int xx_ar_compare_fold(const char *x, const char *y, bool prefix_only)
{
    const unsigned char *a = (const unsigned char *)x;
    const unsigned char *b = (const unsigned char *)y;
    for (;;) {
        uint32_t ua = xx_ar_fold_next(&a);
        uint32_t ub = xx_ar_fold_next(&b);
        if (prefix_only && ub == 0U) {
            return 0;
        }
        if (ua != ub) {
            return ua < ub ? -1 : 1;
        }
        if (ua == 0U) {
            return 0;
        }
    }
}

static int xx_ar_compare_keys(const void *left, const void *right)
{
    const xx_ar_name_key *a = (const xx_ar_name_key *)left;
    const xx_ar_name_key *b = (const xx_ar_name_key *)right;
    int order = xx_ar_compare_fold(a->key, b->key, false);
    if (order != 0) {
        return order;
    }
    /* Equal names keep archive order, so the first member keeps its name. */
    return a->item < b->item ? -1 : (a->item > b->item ? 1 : 0);
}
