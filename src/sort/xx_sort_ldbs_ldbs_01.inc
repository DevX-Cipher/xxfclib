/* Private sorting implementation from src/formats/ldbs/xx_ldbs.c. */

static int ldbs_track_cmp(const void *a, const void *b)
{
    const ldbs_track *x = (const ldbs_track *)a, *y = (const ldbs_track *)b;
    uint32_t kx = (uint32_t)x->cyl * 2U + x->head;
    uint32_t ky = (uint32_t)y->cyl * 2U + y->head;
    return kx < ky ? -1 : kx > ky ? 1 : 0;
}
static int ldbs_sector_cmp(const void *a, const void *b)
{
    const ldbs_sector *x = (const ldbs_sector *)a, *y = (const ldbs_sector *)b;
    return x->id < y->id ? -1 : x->id > y->id ? 1 : 0;
}
