/* Private sorting implementation from src/formats/installer/ibm_zpak_installer/xx_ibm_zpak_installer.c. */

/* Elements are indices into the zpi_member array passed as context. */
static int zpi_compare(const void *left, const void *right, void *context)
{
    const zpi_member *items = (const zpi_member *)context;
    const zpi_member *a = &items[*(const size_t *)left];
    const zpi_member *b = &items[*(const size_t *)right];
    int order = zpi_name_compare(a->name, b->name);
    if (order != 0) return order;
    return a->record < b->record ? -1 : (a->record > b->record ? 1 : 0);
}

/* Sort of an index array by folded name, then record number. Record numbers
 * are unique, so the order is total and the algorithm does not matter. */
static void zpi_sort(size_t *order, size_t count, const zpi_member *items)
{
    size_t index;
    for (index = 0U; index < count; ++index) order[index] = index;
    xx_sort_context(order, count, sizeof(*order), zpi_compare, (void *)items);
}
