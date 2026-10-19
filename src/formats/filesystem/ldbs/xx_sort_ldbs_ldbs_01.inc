/* Private sorting implementation from src/formats/filesystem/ldbs/xx_ldbs.c. */

static int ldbs_track_cmp(const void *left, const void *right, void *context)
{
    const ldbs_track *x = (const ldbs_track *)left, *y = (const ldbs_track *)right;
    uint32_t kx = (uint32_t)x->cyl * 2U + x->head;
    uint32_t ky = (uint32_t)y->cyl * 2U + y->head;
    (void)context;
    return kx < ky ? -1 : kx > ky ? 1 : 0;
}
static int ldbs_sector_cmp(const void *left, const void *right, void *context)
{
    const ldbs_sector *x = (const ldbs_sector *)left, *y = (const ldbs_sector *)right;
    (void)context;
    return x->id < y->id ? -1 : x->id > y->id ? 1 : 0;
}
