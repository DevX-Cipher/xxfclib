/* Private sorting implementation from src/formats/hfsplus/xx_hfsplus.c. */

static int hp_name_compare(const hp_name *a, const hp_name *b, bool binary)
{
    size_t i = 0U, j = 0U;
    if (binary) {
        size_t n = a->length < b->length ? a->length : b->length, k;
        for (k = 0U; k < n; ++k)
            if (a->text[k] != b->text[k]) return a->text[k] < b->text[k] ? -1 : 1;
        return a->length == b->length ? 0 : (a->length < b->length ? -1 : 1);
    }
    for (;;) {
        uint16_t x = 0U, y = 0U;
        bool end_x, end_y;
        while (i < a->length) {
            x = hp_fold(a->text[i++]);
            if (x) break;
        }
        while (j < b->length) {
            y = hp_fold(b->text[j++]);
            if (y) break;
        }
        end_x = x == 0U;
        end_y = y == 0U;
        if (end_x || end_y) return end_x == end_y ? 0 : (end_x ? -1 : 1);
        if (x != y) return x < y ? -1 : 1;
    }
}
static int hp_key_compare(const hp_key *a, const hp_key *b, unsigned type, bool binary)
{
    if (a->id != b->id) return a->id < b->id ? -1 : 1;
    if (type != 1U) {
        if (a->fork != b->fork) return a->fork < b->fork ? -1 : 1;
        return a->block == b->block ? 0 : (a->block < b->block ? -1 : 1);
    }
    return hp_name_compare(&a->name, &b->name, binary);
}
