/* Private sorting implementation from src/formats/installer/bitrock/xx_bitrock.c. */

static int br_compare_chunks(const void *left, const void *right, void *context)
{
    const br_chunk *a = left, *b = right;
    br_name an = {a->base, 0}, bn = {b->base, 0};
    int r = br_compare_names(&an, &bn, context);
    return r ? r : a->number < b->number ? -1 : a->number > b->number ? 1 : 0;
}
