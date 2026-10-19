/* Private sorting implementation from src/formats/installer/bitrock/xx_bitrock.c. */

static int br_compare_names(const void *left, const void *right, void *context)
{
    const char *a = ((const br_name *)left)->name, *b = ((const br_name *)right)->name;
    (void)context;
    while (*a && *b) {
        unsigned p = xx_rt_ascii_tolower((unsigned char)*a++), q = xx_rt_ascii_tolower((unsigned char)*b++);
        if (p != q) return p < q ? -1 : 1;
    }
    return *a ? 1 : *b ? -1 : 0;
}
