/* Private sorting implementation from src/formats/archive/microfox_put/xx_microfox_put.c. */

/* The case folding Windows file systems apply, restricted to what code page
 * 437 can spell: ASCII letters and the eight accented pairs, plus sigma. */
static uint8_t put_fold(uint8_t byte)
{
    if (byte >= (uint8_t)'a' && byte <= (uint8_t)'z') {
        return (uint8_t)(byte - 0x20U);
    }
    switch (byte) {
        case 0x81U: return 0x9AU; /* u umlaut */
        case 0x82U: return 0x90U; /* e acute */
        case 0x84U: return 0x8EU; /* a umlaut */
        case 0x86U: return 0x8FU; /* a ring */
        case 0x87U: return 0x80U; /* c cedilla */
        case 0x91U: return 0x92U; /* ae */
        case 0x94U: return 0x99U; /* o umlaut */
        case 0xA4U: return 0xA5U; /* n tilde */
        case 0xE5U: return 0xE4U; /* sigma */
        default: return byte;
    }
}

static int put_name_compare(const uint8_t *left, const uint8_t *right)
{
    for (;;) {
        uint8_t a = put_fold(*left++);
        uint8_t b = put_fold(*right++);

        if (a != b) return a < b ? -1 : 1;
        if (a == 0U) return 0;
    }
}

/* Order by folded name, then members still carrying their stored name before
 * renamed ones, then by member index. The first member of a group of equal
 * names is the one that keeps its name: an original name wins over one this
 * reader made up, and among originals the earliest member wins. Elements are
 * member indices; context is the put_stream. The index decides last, so this
 * is a total order and any sort gives the same result. */
static int put_order_compare(const void *left, const void *right, void *context)
{
    const put_stream *stream = (const put_stream *)context;
    size_t a = *(const size_t *)left;
    size_t b = *(const size_t *)right;
    const put_member *first = &stream->items[a];
    const put_member *second = &stream->items[b];
    int order = put_name_compare(first->raw, second->raw);

    if (order != 0) return order;
    if ((first->orig != NULL) != (second->orig != NULL)) {
        return first->orig == NULL ? -1 : 1;
    }
    return a < b ? -1 : (a > b ? 1 : 0);
}

/* Heapsort: O(n log n) whatever the names, so a crafted archive cannot make
 * this quadratic. */
static void put_sort(const put_stream *stream, size_t *order, size_t count)
{
    size_t index;

    for (index = 0U; index < count; ++index) order[index] = index;
    xx_sort_context(order, count, sizeof(*order), put_order_compare, (void *)stream);
}
