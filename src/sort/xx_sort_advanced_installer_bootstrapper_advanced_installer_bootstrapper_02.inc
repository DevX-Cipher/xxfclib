/* Private sorting implementation from src/formats/advanced_installer_bootstrapper/xx_advanced_installer_bootstrapper.c. */

static int aib_name_compare(const char *left, const char *right)
{
    const uint8_t *a = (const uint8_t *)left;
    const uint8_t *b = (const uint8_t *)right;
    for (;;) {
        uint8_t x = aib_fold(*a++);
        uint8_t y = aib_fold(*b++);
        if (x != y) return x < y ? -1 : 1;
        if (x == 0U) return 0;
    }
}

/* Shell sort of an index array; `less` decides the order. */
static void aib_sort(size_t *order, size_t count, const aib_member *items, bool (*less)(const aib_member *, const aib_member *))
{
    size_t gap = 1U;
    size_t index;
    for (index = 0U; index < count; ++index) order[index] = index;
    while (gap < count / 3U) gap = gap * 3U + 1U;
    for (; gap > 0U; gap /= 3U) {
        for (index = gap; index < count; ++index) {
            size_t value = order[index];
            size_t slot = index;
            while (slot >= gap && less(&items[value], &items[order[slot - gap]])) {
                order[slot] = order[slot - gap];
                slot -= gap;
            }
            order[slot] = value;
        }
    }
}

static bool aib_less_by_offset(const aib_member *a, const aib_member *b)
{
    if (a->data_offset != b->data_offset) return a->data_offset < b->data_offset;
    return a->size < b->size;
}

static bool aib_less_by_name(const aib_member *a, const aib_member *b)
{
    int order = aib_name_compare(a->name, b->name);
    if (order != 0) return order < 0;
    return a->slot < b->slot;
}
