/* Private sorting implementation from src/formats/installer/installshield_developer/xx_installshield_developer.c. */

/* ---- member names ------------------------------------------------------ */

/* Fold a raw name byte the way a case-insensitive Windows volume compares
 * it: ASCII and the Windows-1252 letter pairs, with the undefined bytes
 * folded onto the '_' they decode to. */
static uint8_t isd_fold(uint8_t c)
{
    if (c >= 'A' && c <= 'Z') return (uint8_t)(c + 0x20U);
    if (c == 0x8AU || c == 0x8CU || c == 0x8EU) return (uint8_t)(c + 0x10U);
    if (c == 0x9FU) return 0xFFU;
    if (c >= 0xC0U && c <= 0xDEU && c != 0xD7U) return (uint8_t)(c + 0x20U);
    if (c == 0x81U || c == 0x8DU || c == 0x8FU || c == 0x90U || c == 0x9DU) return (uint8_t)'_';
    return c;
}

/* Three-way comparison of two names under isd_fold. */
static int isd_compare_names(const char *left, const char *right)
{
    for (;;) {
        uint8_t a, b;
        if (*left == *right) {
            /* Equal bytes fold equally: skip the fold on common prefixes. */
            if (*left == 0) return 0;
            ++left;
            ++right;
            continue;
        }
        a = isd_fold((uint8_t)*left);
        b = isd_fold((uint8_t)*right);
        if (a != b) return a < b ? -1 : 1;
        if (a == 0U) return 0;
        ++left;
        ++right;
    }
}

/* Context of isd_compare_order: the members and their name pool. */
typedef struct isd_order_context {
    const isd_member *items;
    const char *names;
} isd_order_context;

/* Member indices by folded name, then index: a total order. An
 * xx_sort_callback; context is an isd_order_context. */
static int isd_compare_order(const void *left, const void *right, void *context)
{
    const isd_order_context *order = (const isd_order_context *)context;
    uint32_t a = *(const uint32_t *)left;
    uint32_t b = *(const uint32_t *)right;
    int names = isd_compare_names(order->names + order->items[a].name_at, order->names + order->items[b].name_at);
    if (names != 0) return names;
    return a < b ? -1 : (a > b ? 1 : 0);
}

/* Member indices sorted by folded name. The caller passes them in index
 * order, so ordering equal names by index is the order of the stable merge
 * sort this replaced. The order is total, so the allocation-free heapsort
 * gives it with O(n log n) comparisons whatever the names are, so crafted
 * names cannot make the dedupe quadratic. */
static void isd_sort_by_name(uint32_t *order, size_t count, const isd_member *items, const char *names)
{
    isd_order_context context;
    context.items = items;
    context.names = names;
    xx_sort_context(order, count, sizeof(*order), isd_compare_order, &context);
}
