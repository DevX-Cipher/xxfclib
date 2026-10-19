/* Private sorting implementation from src/formats/ej_technologies_install/xx_ej_technologies_install.c. */

/* Case-insensitive order over the names this reader builds: ASCII letters
 * and the Latin-1 letters U+00C0..U+00DE / U+00E0..U+00FE (UTF-8 C3 80..9E
 * and C3 A0..BE, the multiplication and division signs excepted) fold
 * together, as a Windows file system folds them.  A C3 lead byte in one
 * name meets a C3 in the other whenever the names agree so far, so the
 * continuation byte can be folded by looking at the previous byte alone. */
static unsigned ejti_fold(unsigned char c, unsigned char previous)
{
    if (previous == 0xC3U) {
        if (c >= 0x80U && c <= 0x9EU && c != 0x97U) return c + 0x20U;
        return c;
    }
    if (c >= 'A' && c <= 'Z') return c + ('a' - 'A');
    return c;
}

static int ejti_name_icmp(const char *left, const char *right)
{
    const unsigned char *a = (const unsigned char *)left;
    const unsigned char *b = (const unsigned char *)right;
    unsigned char previous = 0U;
    for (;;) {
        unsigned x = ejti_fold(*a, previous);
        unsigned y = ejti_fold(*b, previous);
        if (x != y) return x < y ? -1 : 1;
        if (*a == 0U) return 0;
        previous = *a;
        ++a;
        ++b;
    }
}

static int ejti_compare_keys(const void *left, const void *right)
{
    const ejti_key *a = (const ejti_key *)left;
    const ejti_key *b = (const ejti_key *)right;
    int order = ejti_name_icmp(a->name, b->name);
    if (order != 0) return order;
    return a->item < b->item ? -1 : (a->item > b->item ? 1 : 0);
}
