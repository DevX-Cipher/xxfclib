/* Private sorting implementation from src/formats/hfsplus/xx_hfsplus.c. */

static int hp_entry_compare(const void *a, const void *b)
{
    uint32_t x = ((const hp_entry *)a)->id, y = ((const hp_entry *)b)->id;
    return x == y ? 0 : (x < y ? -1 : 1);
}
static int hp_thread_compare(const void *a, const void *b)
{
    uint32_t x = ((const hp_thread *)a)->id, y = ((const hp_thread *)b)->id;
    return x == y ? 0 : (x < y ? -1 : 1);
}
