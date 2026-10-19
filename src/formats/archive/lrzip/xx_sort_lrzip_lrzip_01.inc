/* Private sorting implementation from src/formats/archive/lrzip/xx_lrzip.c. */

static int lr_order(const void *a, const void *b, void *context)
{
    uint32_t x = ((const lr_block *)a)->at, y = ((const lr_block *)b)->at;
    (void)context;
    return x < y ? -1 : x > y ? 1 : 0;
}
