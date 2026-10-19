/* Private sorting implementation from src/formats/installer/installshield_12_setup/xx_installshield_12_setup.c. */

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
 * group of equal names sorts first and keeps its name. The record number
 * is unique, so this is a total order. An xx_sort_callback; context is the
 * is12_stream. */
static int is12_order_compare(const void *left, const void *right, void *context)
{
    const is12_stream *stream = (const is12_stream *)context;
    uint32_t x = *(const uint32_t *)left;
    uint32_t y = *(const uint32_t *)right;
    int compared = is12_name_compare(stream->items[x].name, stream->items[y].name);
    if (compared != 0) return compared;
    return x < y ? -1 : (x > y ? 1 : 0);
}

/* O(n log n) whatever names a hostile file carries. */
static void is12_sort(const is12_stream *stream, uint32_t *order)
{
    size_t count = stream->count;
    size_t index;
    for (index = 0U; index < count; ++index) order[index] = (uint32_t)index;
    xx_sort_context(order, count, sizeof(*order), is12_order_compare, (void *)stream);
}
