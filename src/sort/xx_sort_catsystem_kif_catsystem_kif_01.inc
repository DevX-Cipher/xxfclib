/* Private sorting implementation from src/formats/catsystem_kif/xx_catsystem_kif.c. */

static int ki_fold_compare(const char *a, const char *b)
{
    for (;;) {
        unsigned char x = (unsigned char)*a++, y = (unsigned char)*b++;
        if (x >= 'A' && x <= 'Z') x = (unsigned char)(x + 'a' - 'A');
        if (y >= 'A' && y <= 'Z') y = (unsigned char)(y + 'a' - 'A');
        if (x != y) return x < y ? -1 : 1;
        if (x == 0U) return 0;
    }
}
static int ki_compare_keys(const void *a, const void *b)
{
    const ki_name_key *x = (const ki_name_key *)a;
    const ki_name_key *y = (const ki_name_key *)b;
    int order = ki_fold_compare(x->name, y->name);
    if (order) return order;
    return x->index < y->index ? -1 : x->index > y->index ? 1 : 0;
}
