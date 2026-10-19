/* Private sorting implementation from src/formats/finstall/xx_finstall.c. */

static int fi_compare_folded(const char *a, const char *b)
{
    for (;;) {
        uint32_t x = fi_fold_next(&a), y = fi_fold_next(&b);
        if (x != y) return x < y ? -1 : 1;
        if (x == 0U) return 0;
    }
}
