/* Private sorting implementation from src/formats/ihex/xx_ihex.c. */

/* Heap sort of block indices by (address, index), used once to find blocks
 * that start at the same address. */
static bool xx_ihexfmt_index_less(const xx_ihexfmt_block *blocks, uint32_t a, uint32_t b)
{
    if (blocks[a].address != blocks[b].address) {
        return blocks[a].address < blocks[b].address;
    }
    return a < b;
}

static void xx_ihexfmt_sift_down(const xx_ihexfmt_block *blocks, uint32_t *order, size_t root, size_t count)
{
    for (;;) {
        size_t child = root * 2U + 1U;
        uint32_t swap;
        if (child >= count) return;
        if (child + 1U < count && xx_ihexfmt_index_less(blocks, order[child], order[child + 1U])) {
            ++child;
        }
        if (!xx_ihexfmt_index_less(blocks, order[root], order[child])) return;
        swap = order[root];
        order[root] = order[child];
        order[child] = swap;
        root = child;
    }
}
