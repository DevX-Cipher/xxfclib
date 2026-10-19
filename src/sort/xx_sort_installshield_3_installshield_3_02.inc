/* Private sorting implementation from src/formats/installshield_3/xx_installshield_3.c. */

/* Comparison key: ASCII case folded, every non-ASCII byte one class, so
 * names that any file system could treat as equal compare equal. */
static int is3_key_compare(const char *a, const char *b)
{
    for (;; ++a, ++b) {
        uint8_t x = (uint8_t)*a, y = (uint8_t)*b;
        if (x >= 0x80U) x = 0x80U;
        if (y >= 0x80U) y = 0x80U;
        x = is3_fold(x);
        y = is3_fold(y);
        if (x != y) return x < y ? -1 : 1;
        if (x == 0U) return 0;
    }
}

static int is3_member_compare(const void *left, const void *right)
{
    const is3_member *a = *(const is3_member *const *)left;
    const is3_member *b = *(const is3_member *const *)right;
    int result = is3_key_compare(a->name, b->name);
    if (result) return result;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
