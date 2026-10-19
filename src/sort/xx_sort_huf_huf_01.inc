/* Private sorting implementation from src/formats/huf/xx_huf.c. */

static int xx_huf_compare_offsets(const void *left, const void *right)
{
    int64_t a = *(const int64_t *)left;
    int64_t b = *(const int64_t *)right;
    return (a > b) - (a < b);
}
