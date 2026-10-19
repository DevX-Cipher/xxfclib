/* Private sorting implementation from src/formats/clickteam_install_creator/xx_clickteam_install_creator.c. */

static int cic_offset_cmp(const void *context, uint32_t x, uint32_t y)
{
    const cic_entry *e = (const cic_entry *)context;
    if (e[x].offset != e[y].offset) return e[x].offset < e[y].offset ? -1 : 1;
    return x < y ? -1 : (x > y ? 1 : 0);
}
