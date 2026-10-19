/* Private sorting implementation from src/formats/filesystem/hxc_raw_floppy/xx_hxc_xml_parser.h. */

static int hx_sector_order(const void *left, const void *right, void *context)
{
    const hx_sector *x = (const hx_sector *)left, *y = (const hx_sector *)right;
    (void)context;
    return x->id < y->id ? -1 : x->id > y->id ? 1 : 0;
}
