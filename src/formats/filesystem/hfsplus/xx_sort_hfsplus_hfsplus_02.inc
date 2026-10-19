/* Private sorting implementation from src/formats/filesystem/hfsplus/xx_hfsplus.c. */

static int hp_entry_compare(const void *a, const void *b, void *context)
{
    uint32_t x = ((const hp_entry *)a)->id, y = ((const hp_entry *)b)->id;
    (void)context;
    return x == y ? 0 : (x < y ? -1 : 1);
}
static int hp_thread_compare(const void *a, const void *b, void *context)
{
    uint32_t x = ((const hp_thread *)a)->id, y = ((const hp_thread *)b)->id;
    (void)context;
    return x == y ? 0 : (x < y ? -1 : 1);
}
