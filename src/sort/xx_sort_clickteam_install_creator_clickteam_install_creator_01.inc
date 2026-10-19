/* Private sorting implementation from src/formats/clickteam_install_creator/xx_clickteam_install_creator.c. */

/* Orders entry indices by folded name, then by index. */
static int cic_key_cmp(const void *context, uint32_t x, uint32_t y)
{
    char *const *keys = (char *const *)context;
    const uint8_t *a = (const uint8_t *)keys[x], *b = (const uint8_t *)keys[y];
    while (*a && *a == *b) {
        ++a;
        ++b;
    }
    if (*a != *b) return *a < *b ? -1 : 1;
    return x < y ? -1 : (x > y ? 1 : 0);
}

/* Bottom-up merge sort of indices: O(n log n) comparisons whatever the
 * input is.  n <= CIC_MAX_FILES. */
static void cic_sort(uint32_t *index, uint32_t *tmp, uint32_t n, int (*cmp)(const void *, uint32_t, uint32_t), const void *context)
{
    uint32_t width, lo;
    uint32_t *src = index, *dst = tmp, *swap;
    for (width = 1U; width < n; width *= 2U) {
        for (lo = 0U; lo < n; lo += 2U * width) {
            uint32_t mid = n - lo > width ? lo + width : n;
            uint32_t hi = n - mid > width ? mid + width : n;
            uint32_t i = lo, j = mid, k = lo;
            while (i < mid && j < hi) dst[k++] = cmp(context, src[i], src[j]) <= 0 ? src[i++] : src[j++];
            while (i < mid) dst[k++] = src[i++];
            while (j < hi) dst[k++] = src[j++];
        }
        swap = src;
        src = dst;
        dst = swap;
    }
    if (src != index) xx_rt_memcpy(index, src, (size_t)n * sizeof(uint32_t));
}
