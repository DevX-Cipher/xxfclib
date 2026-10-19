/* Private sorting implementation from src/formats/installshield_developer/xx_installshield_developer.c. */

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

/* Stable bottom-up merge sort of member indices by folded name; `scratch`
 * holds `count` entries.  O(n log n) comparisons whatever the names are,
 * so crafted names cannot make the dedupe quadratic. */
static void isd_sort_by_name(uint32_t *order, uint32_t *scratch, size_t count, const isd_member *items, const char *names)
{
    size_t width;
    uint32_t *from = order, *to = scratch;
    for (width = 1U; width < count; width *= 2U) {
        size_t start;
        for (start = 0U; start < count; start += 2U * width) {
            size_t middle = start + width < count ? start + width : count;
            size_t end = middle + width < count ? middle + width : count;
            size_t left = start, right = middle, out = start;
            while (left < middle && right < end) {
                if (isd_compare_names(names + items[from[right]].name_at, names + items[from[left]].name_at) < 0) to[out++] = from[right++];
                else to[out++] = from[left++];
            }
            while (left < middle) to[out++] = from[left++];
            while (right < end) to[out++] = from[right++];
        }
        {
            uint32_t *swap = from;
            from = to;
            to = swap;
        }
    }
    if (from != order) {
        size_t index;
        for (index = 0U; index < count; ++index) order[index] = from[index];
    }
}
