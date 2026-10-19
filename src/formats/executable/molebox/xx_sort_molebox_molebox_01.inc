/* Private sorting implementation from src/formats/executable/molebox/xx_molebox.c. */

static int mb_compare(const void *a, const void *b, void *context)
{
    const char *x = ((const mb_sort_name *)a)->name, *y = ((const mb_sort_name *)b)->name;
    (void)context;
    while (*x && *y) {
        int c = xx_rt_ascii_tolower((unsigned char)*x++), d = xx_rt_ascii_tolower((unsigned char)*y++);
        if (c != d) return c < d ? -1 : 1;
    }
    return *x ? 1 : *y ? -1 : 0;
}
