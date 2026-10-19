/* Private sorting implementation from src/formats/cpm/xx_cpm.c. */

static int cpm_extent_compare(const void *a, const void *b)
{
    const cpm_extent *x = (const cpm_extent *)a, *y = (const cpm_extent *)b;
    int c;
    if (x->user != y->user) return x->user < y->user ? -1 : 1;
    c = xx_mem_compare(x->name, y->name, sizeof(x->name));
    if (c) return c;
    return x->group == y->group ? 0 : (x->group < y->group ? -1 : 1);
}
