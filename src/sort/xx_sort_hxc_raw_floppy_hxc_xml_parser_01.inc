/* Private sorting implementation from src/formats/hxc_raw_floppy/xx_hxc_xml_parser.h. */

static int hx_sector_order(const void *a, const void *b)
{
    const hx_sector *x = (const hx_sector *)a, *y = (const hx_sector *)b;
    return x->id < y->id ? -1 : x->id > y->id ? 1 : 0;
}
