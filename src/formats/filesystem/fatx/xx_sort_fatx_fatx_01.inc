/* Private sorting implementation from src/formats/filesystem/fatx/xx_fatx.c. */

static int fx_compare_names(const void *left, const void *right, void *context)
{
    const char *a = *(const char *const *)left;
    const char *b = *(const char *const *)right;
    (void)context;
    while (*a && *b) {
        unsigned char x = (unsigned char)*a++, y = (unsigned char)*b++;
        if (x >= 'A' && x <= 'Z') x = (unsigned char)(x + 'a' - 'A');
        if (y >= 'A' && y <= 'Z') y = (unsigned char)(y + 'a' - 'A');
        if (x != y) return x < y ? -1 : 1;
    }
    return *a ? 1 : *b ? -1 : 0;
}
