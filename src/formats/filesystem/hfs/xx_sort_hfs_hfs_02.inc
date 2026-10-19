/* Private sorting implementation from src/formats/filesystem/hfs/xx_hfs.c. */

static int hfs_entry_compare(const void *left, const void *right, void *context)
{
    uint32_t x = ((const hfs_entry *)left)->id, y = ((const hfs_entry *)right)->id;
    (void)context;
    return x == y ? 0 : (x < y ? -1 : 1);
}
static int hfs_thread_compare(const void *left, const void *right, void *context)
{
    uint32_t x = ((const hfs_thread *)left)->id, y = ((const hfs_thread *)right)->id;
    (void)context;
    return x == y ? 0 : (x < y ? -1 : 1);
}
