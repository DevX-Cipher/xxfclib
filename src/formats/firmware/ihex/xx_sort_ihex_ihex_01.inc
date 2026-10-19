/* Private sorting implementation from src/formats/firmware/ihex/xx_ihex.c. */

/* Order of block indices by (address, index), used once to find blocks
 * that start at the same address. A total order (indices are unique). An
 * xx_sort_callback; context is the block array. */
static int xx_ihexfmt_compare_order(const void *left, const void *right, void *context)
{
    const xx_ihexfmt_block *blocks = (const xx_ihexfmt_block *)context;
    uint32_t a = *(const uint32_t *)left;
    uint32_t b = *(const uint32_t *)right;
    if (blocks[a].address != blocks[b].address) {
        return blocks[a].address < blocks[b].address ? -1 : 1;
    }
    return a < b ? -1 : (a > b ? 1 : 0);
}
