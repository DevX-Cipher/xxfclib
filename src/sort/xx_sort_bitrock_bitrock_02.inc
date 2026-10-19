/* Private sorting implementation from src/formats/bitrock/xx_bitrock.c. */

static int br_compare_chunks(const void *x, const void *y)
{
    const br_chunk *a = x, *b = y;
    br_name an = {a->base, 0}, bn = {b->base, 0};
    int r = br_compare_names(&an, &bn);
    return r ? r : a->number < b->number ? -1 : a->number > b->number ? 1 : 0;
}
