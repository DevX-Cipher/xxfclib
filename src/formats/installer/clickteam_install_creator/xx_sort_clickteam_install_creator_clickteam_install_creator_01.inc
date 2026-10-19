/* Private sorting implementation from src/formats/installer/clickteam_install_creator/xx_clickteam_install_creator.c. */

/* Orders entry indices by folded name, then by index. An xx_sort_callback;
 * context is the array of folded keys. */
static int cic_key_cmp(const void *left, const void *right, void *context)
{
    char *const *keys = (char *const *)context;
    uint32_t x = *(const uint32_t *)left, y = *(const uint32_t *)right;
    const uint8_t *a = (const uint8_t *)keys[x], *b = (const uint8_t *)keys[y];
    while (*a && *a == *b) {
        ++a;
        ++b;
    }
    if (*a != *b) return *a < *b ? -1 : 1;
    return x < y ? -1 : (x > y ? 1 : 0);
}
