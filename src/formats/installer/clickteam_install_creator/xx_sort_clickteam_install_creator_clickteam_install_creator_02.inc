/* Private sorting implementation from src/formats/installer/clickteam_install_creator/xx_clickteam_install_creator.c. */

/* An xx_sort_callback over entry indices; context is the entry array. */
static int cic_offset_cmp(const void *left, const void *right, void *context)
{
    const cic_entry *e = (const cic_entry *)context;
    uint32_t x = *(const uint32_t *)left, y = *(const uint32_t *)right;
    if (e[x].offset != e[y].offset) return e[x].offset < e[y].offset ? -1 : 1;
    return x < y ? -1 : (x > y ? 1 : 0);
}
