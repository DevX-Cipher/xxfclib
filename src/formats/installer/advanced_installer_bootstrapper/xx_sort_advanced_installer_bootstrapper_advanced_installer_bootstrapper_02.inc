/* Private sorting implementation from src/formats/installer/advanced_installer_bootstrapper/xx_advanced_installer_bootstrapper.c. */

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

/* Sort an index array of `items`; `compare` is an xx_sort_callback over
 * size_t indices whose context is `items`. */
static void aib_sort(size_t *order, size_t count, const aib_member *items, xx_sort_callback compare)
{
    size_t index;
    for (index = 0U; index < count; ++index) order[index] = index;
    xx_sort_context(order, count, sizeof(*order), compare, (void *)items);
}

/* Members tied on offset and size are interchangeable for the overlap check,
 * the only user of this order. */
static int aib_compare_by_offset(const void *left, const void *right, void *context)
{
    const aib_member *items = (const aib_member *)context;
    const aib_member *a = &items[*(const size_t *)left];
    const aib_member *b = &items[*(const size_t *)right];
    if (a->data_offset != b->data_offset) return a->data_offset < b->data_offset ? -1 : 1;
    if (a->size != b->size) return a->size < b->size ? -1 : 1;
    return 0;
}

static int aib_compare_by_name(const void *left, const void *right, void *context)
{
    const aib_member *items = (const aib_member *)context;
    const aib_member *a = &items[*(const size_t *)left];
    const aib_member *b = &items[*(const size_t *)right];
    int order = aib_name_compare(a->name, b->name);
    if (order != 0) return order;
    return a->slot < b->slot ? -1 : (a->slot > b->slot ? 1 : 0);
}
