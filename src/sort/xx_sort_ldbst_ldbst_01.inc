/* Private sorting implementation from src/formats/ldbst/xx_ldbst.c. */

static int ldbst_track_cmp(const void *a, const void *b)
{
    const ldbst_track *x = (const ldbst_track *)a, *y = (const ldbst_track *)b;
    uint32_t kx = (uint32_t)x->cyl * 2U + x->head;
    uint32_t ky = (uint32_t)y->cyl * 2U + y->head;
    return kx < ky ? -1 : kx > ky ? 1 : 0;
}
static int ldbst_sector_cmp(const void *a, const void *b)
{
    const ldbst_sector *x = (const ldbst_sector *)a;
    const ldbst_sector *y = (const ldbst_sector *)b;
    return x->id < y->id ? -1 : x->id > y->id ? 1 : 0;
}
