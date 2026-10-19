/* Private sorting implementation from src/formats/ibm_zpak_installer/xx_ibm_zpak_installer.c. */

static bool zpi_less(const zpi_member *a, const zpi_member *b)
{
    int order = zpi_name_compare(a->name, b->name);
    if (order != 0) return order < 0;
    return a->record < b->record;
}

/* Shell sort of an index array by folded name, then record number. */
static void zpi_sort(size_t *order, size_t count, const zpi_member *items)
{
    size_t gap = 1U;
    size_t index;
    for (index = 0U; index < count; ++index) order[index] = index;
    while (gap < count / 3U) gap = gap * 3U + 1U;
    for (; gap > 0U; gap /= 3U) {
        for (index = gap; index < count; ++index) {
            size_t value = order[index];
            size_t slot = index;
            while (slot >= gap && zpi_less(&items[value], &items[order[slot - gap]])) {
                order[slot] = order[slot - gap];
                slot -= gap;
            }
            order[slot] = value;
        }
    }
}
