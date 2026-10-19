/* Private sorting implementation from src/formats/archive/ace/xx_ace_dec.c. */

static void ace_sort_range(uint8_t *frequency, uint16_t *symbol, int left, int right)
{
    int lo = left, hi = right;
    uint8_t pivot = frequency[right];
    do {
        while (frequency[lo] > pivot) ++lo;
        while (frequency[hi] < pivot) --hi;
        if (lo <= hi) {
            uint8_t f = frequency[lo];
            uint16_t s = symbol[lo];
            frequency[lo] = frequency[hi];
            symbol[lo] = symbol[hi];
            frequency[hi] = f;
            symbol[hi] = s;
            ++lo;
            --hi;
        }
    } while (lo < hi);
    if (left < hi) {
        if (left < hi - 1) ace_sort_range(frequency, symbol, left, hi);
        else if (frequency[left] < frequency[hi]) {
            uint8_t f = frequency[left];
            uint16_t s = symbol[left];
            frequency[left] = frequency[hi];
            symbol[left] = symbol[hi];
            frequency[hi] = f;
            symbol[hi] = s;
        }
    }
    if (right > lo) {
        if (lo < right - 1) ace_sort_range(frequency, symbol, lo, right);
        else if (frequency[lo] < frequency[right]) {
            uint8_t f = frequency[lo];
            uint16_t s = symbol[lo];
            frequency[lo] = frequency[right];
            symbol[lo] = symbol[right];
            frequency[right] = f;
            symbol[right] = s;
        }
    }
}
