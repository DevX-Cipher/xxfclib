/* Private sorting implementation from src/formats/common/xx_carrier_helpers.h. */

static void carrier_sift(carrier_extent *r, size_t n, size_t p)
{
    while (p < n / 2) {
        size_t c = p * 2 + 1;
        carrier_extent t;
        if (c + 1 < n && r[c + 1].lo > r[c].lo) ++c;
        if (r[p].lo >= r[c].lo) break;
        t = r[p];
        r[p] = r[c];
        r[c] = t;
        p = c;
    }
}
