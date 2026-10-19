/* Private sorting implementation from src/formats/filesystem/jffs2/xx_jffs2.c. */

/* ---------------------------------------------------------- ordering --- */

/* Both arrays are sorted with xx_sort_context, the same in-place heapsort
 * (same comparisons and swaps) as the byte-wise one it replaced, so equal
 * elements end up exactly where they did before. */

/* Dirents are ordered by parent, then name, then version, so that the run
 * for one name within one directory is contiguous and its last element is
 * the winning revision. */
static int xx_jffs2_dirent_compare(const void *left, const void *right, void *context)
{
    const xx_jffs2_dirent *a = (const xx_jffs2_dirent *)left;
    const xx_jffs2_dirent *b = (const xx_jffs2_dirent *)right;
    int order;
    (void)context;
    if (a->pino != b->pino) return a->pino < b->pino ? -1 : 1;
    order = xx_str_cmp(a->name, b->name);
    if (order != 0) return order;
    if (a->version != b->version) return a->version < b->version ? -1 : 1;
    return 0;
}

/* Fragments are ordered by inode, then version: replaying one inode's run
 * front to back is exactly the log replay the format specifies. */
static int xx_jffs2_fragment_compare(const void *left, const void *right, void *context)
{
    const xx_jffs2_fragment *a = (const xx_jffs2_fragment *)left;
    const xx_jffs2_fragment *b = (const xx_jffs2_fragment *)right;
    (void)context;
    if (a->ino != b->ino) return a->ino < b->ino ? -1 : 1;
    if (a->version != b->version) return a->version < b->version ? -1 : 1;
    if (a->data_offset != b->data_offset) {
        return a->data_offset < b->data_offset ? -1 : 1;
    }
    return 0;
}
