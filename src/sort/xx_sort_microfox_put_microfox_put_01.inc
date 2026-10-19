/* Private sorting implementation from src/formats/microfox_put/xx_microfox_put.c. */

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
 * reader made up, and among originals the earliest member wins. */
static bool put_order_less(const put_stream *stream, size_t a, size_t b)
{
    const put_member *left = &stream->items[a];
    const put_member *right = &stream->items[b];
    int order = put_name_compare(left->raw, right->raw);

    if (order != 0) return order < 0;
    if ((left->orig != NULL) != (right->orig != NULL)) {
        return left->orig == NULL;
    }
    return a < b;
}

static void put_sift_down(const put_stream *stream, size_t *order, size_t root, size_t size)
{
    for (;;) {
        size_t child = root * 2U + 1U;
        size_t swap;

        if (child >= size) return;
        if (child + 1U < size && put_order_less(stream, order[child], order[child + 1U])) {
            ++child;
        }
        if (!put_order_less(stream, order[root], order[child])) return;
        swap = order[root];
        order[root] = order[child];
        order[child] = swap;
        root = child;
    }
}

/* Heapsort: O(n log n) whatever the names, so a crafted archive cannot make
 * this quadratic. */
static void put_sort(const put_stream *stream, size_t *order, size_t count)
{
    size_t index;

    for (index = 0U; index < count; ++index) order[index] = index;
    if (count < 2U) return;
    for (index = count / 2U; index-- > 0U;) {
        put_sift_down(stream, order, index, count);
    }
    for (index = count - 1U; index > 0U; --index) {
        size_t swap = order[0];
        order[0] = order[index];
        order[index] = swap;
        put_sift_down(stream, order, 0U, index);
    }
}
