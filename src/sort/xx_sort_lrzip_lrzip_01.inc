/* Private sorting implementation from src/formats/lrzip/xx_lrzip.c. */

static int lr_order(const void *a, const void *b)
{
    uint32_t x = ((const lr_block *)a)->at, y = ((const lr_block *)b)->at;
    return x < y ? -1 : x > y ? 1 : 0;
}
