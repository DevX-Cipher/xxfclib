/* Private sorting implementation from src/formats/game/malie_lib/xx_malie_lib.c. */

static int ml_fold_compare(const char *a, const char *b)
{
    for (;;) {
        unsigned char x = (unsigned char)*a++, y = (unsigned char)*b++;
        if (x >= 'A' && x <= 'Z') x = (unsigned char)(x + 'a' - 'A');
        if (y >= 'A' && y <= 'Z') y = (unsigned char)(y + 'a' - 'A');
        if (x != y) return x < y ? -1 : 1;
        if (x == 0U) return 0;
    }
}
static int ml_compare_keys(const void *a, const void *b, void *context)
{
    const ml_name_key *x = (const ml_name_key *)a;
    const ml_name_key *y = (const ml_name_key *)b;
    int order;
    (void)context;
    order = ml_fold_compare(x->name, y->name);
    if (order) return order;
    return x->index < y->index ? -1 : x->index > y->index ? 1 : 0;
}
