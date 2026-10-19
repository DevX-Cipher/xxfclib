/* Private sorting implementation from src/formats/hfs/xx_hfs.c. */

static int hfs_entry_compare(const void *a, const void *b)
{
    uint32_t x = ((const hfs_entry *)a)->id, y = ((const hfs_entry *)b)->id;
    return x == y ? 0 : (x < y ? -1 : 1);
}
static int hfs_thread_compare(const void *a, const void *b)
{
    uint32_t x = ((const hfs_thread *)a)->id, y = ((const hfs_thread *)b)->id;
    return x == y ? 0 : (x < y ? -1 : 1);
}
