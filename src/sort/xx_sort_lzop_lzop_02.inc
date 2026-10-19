/* Private sorting implementation from src/formats/lzop/xx_lzop.c. */

static void xx_lzopfmt_key_insert(xx_lzopfmt_key *keys, size_t *used, uint8_t *data, size_t length)
{
    size_t slot = 0U;
    (void)xx_lzopfmt_key_find(keys, *used, data, length, &slot);
    if (slot < *used) {
        xx_rt_memmove(&keys[slot + 1U], &keys[slot], (*used - slot) * sizeof(*keys));
    }
    keys[slot].data = data;
    keys[slot].length = length;
    ++*used;
}
