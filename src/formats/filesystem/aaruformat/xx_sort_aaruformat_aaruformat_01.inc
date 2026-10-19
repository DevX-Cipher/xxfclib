/* Private sorting implementation from src/formats/filesystem/aaruformat/xx_aaruformat.c. */

static int af_compare_block(const void *a, const void *b, void *context)
{
    const af_block *x = (const af_block *)a, *y = (const af_block *)b;
    (void)context;
    return x->offset < y->offset ? -1 : x->offset > y->offset ? 1 : 0;
}
