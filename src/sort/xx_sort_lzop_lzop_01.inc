/* Private sorting implementation from src/formats/lzop/xx_lzop.c. */

static int xx_lzopfmt_key_compare(const xx_lzopfmt_key *key, const uint8_t *data, size_t length)
{
    size_t common = key->length < length ? key->length : length;
    int order = common != 0U ? xx_rt_memcmp(key->data, data, common) : 0;
    if (order != 0) return order;
    if (key->length == length) return 0;
    return key->length < length ? -1 : 1;
}

/* Binary search of the sorted key set; *slot receives the insert position. */
static bool xx_lzopfmt_key_find(const xx_lzopfmt_key *keys, size_t count, const uint8_t *data, size_t length, size_t *slot)
{
    size_t low = 0U;
    size_t high = count;
    while (low < high) {
        size_t middle = low + (high - low) / 2U;
        int order = xx_lzopfmt_key_compare(&keys[middle], data, length);
        if (order == 0) {
            *slot = middle;
            return true;
        }
        if (order < 0) {
            low = middle + 1U;
        } else {
            high = middle;
        }
    }
    *slot = low;
    return false;
}
