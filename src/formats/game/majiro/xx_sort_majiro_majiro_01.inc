/* Private sorting implementation from src/formats/game/majiro/xx_majiro.c. */

static int ma_fold_compare(const char *a, const char *b)
{
    for (;;) {
        unsigned char x = (unsigned char)*a++, y = (unsigned char)*b++;
        if (x >= 'A' && x <= 'Z') x = (unsigned char)(x + 'a' - 'A');
        if (y >= 'A' && y <= 'Z') y = (unsigned char)(y + 'a' - 'A');
        if (x != y) return x < y ? -1 : 1;
        if (x == 0U) return 0;
    }
}
static int ma_compare_keys(const void *left, const void *right, void *context)
{
    const ma_name_key *x = (const ma_name_key *)left;
    const ma_name_key *y = (const ma_name_key *)right;
    int order = ma_fold_compare(x->name, y->name);
    (void)context;
    if (order) return order;
    return x->index < y->index ? -1 : x->index > y->index ? 1 : 0;
}
