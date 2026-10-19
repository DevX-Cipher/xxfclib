/* Private sorting implementation from src/formats/filesystem/cpm/xx_cpm.c. */

static int cpm_extent_compare(const void *left, const void *right, void *context)
{
    const cpm_extent *x = (const cpm_extent *)left, *y = (const cpm_extent *)right;
    int c;
    (void)context;
    if (x->user != y->user) return x->user < y->user ? -1 : 1;
    c = xx_mem_compare(x->name, y->name, sizeof(x->name));
    if (c) return c;
    return x->group == y->group ? 0 : (x->group < y->group ? -1 : 1);
}
