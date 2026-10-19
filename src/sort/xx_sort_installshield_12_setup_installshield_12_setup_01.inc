/* Private sorting implementation from src/formats/installshield_12_setup/xx_installshield_12_setup.c. */

/* How Windows compares names, made conservative: ASCII letters fold to
 * upper case, U+0131 and U+017F fold to the ASCII letters they upper-case
 * to, and every other non-ASCII character is treated as possibly equal to
 * any other.  Two names that could open the same file therefore always
 * compare equal here; the price is an occasional needless rename. */
static uint32_t is12_fold(uint32_t c)
{
    if (c < 0x80U) return (c >= 'a' && c <= 'z') ? c - 0x20U : c;
    if (c == 0x131U) return 'I';
    if (c == 0x17FU) return 'S';
    return IS12_FOLD_ANY;
}

static int is12_name_compare(const char *left, const char *right)
{
    size_t a = 0U, b = 0U;
    while (left[a] && right[b]) {
        uint32_t x = is12_fold(is12_utf8_next(left, &a));
        uint32_t y = is12_fold(is12_utf8_next(right, &b));
        if (x != y) return x < y ? -1 : 1;
    }
    if (left[a]) return 1;
    if (right[b]) return -1;
    return 0;
}

/* Folded name first, record number second, so the earliest record of a
 * group of equal names sorts first and keeps its name. */
static bool is12_order_less(const is12_stream *stream, uint32_t left, uint32_t right)
{
    int compared = is12_name_compare(stream->items[left].name, stream->items[right].name);
    return compared < 0 || (compared == 0 && left < right);
}

static void is12_sift_down(const is12_stream *stream, uint32_t *order, size_t root, size_t count)
{
    for (;;) {
        size_t child = root * 2U + 1U;
        uint32_t swap;
        if (child >= count) return;
        if (child + 1U < count && is12_order_less(stream, order[child], order[child + 1U])) ++child;
        if (!is12_order_less(stream, order[root], order[child])) return;
        swap = order[root];
        order[root] = order[child];
        order[child] = swap;
        root = child;
    }
}

/* Heap sort: O(n log n) whatever names a hostile file carries. */
static void is12_sort(const is12_stream *stream, uint32_t *order)
{
    size_t count = stream->count;
    size_t index;
    for (index = 0U; index < count; ++index) order[index] = (uint32_t)index;
    if (count < 2U) return;
    for (index = count / 2U; index > 0U; --index) is12_sift_down(stream, order, index - 1U, count);
    for (index = count - 1U; index > 0U; --index) {
        uint32_t swap = order[0];
        order[0] = order[index];
        order[index] = swap;
        is12_sift_down(stream, order, 0U, index);
    }
}
