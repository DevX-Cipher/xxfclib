/* Private sorting implementation from src/formats/filesystem/jffs2_old/xx_jffs2_old.c. */

/* ---------------------------------------------------------- ordering --- */

/* Both arrays are sorted with xx_sort_context, an allocation-free heapsort
 * that makes the same comparisons and swaps as the byte-wise heapsort this
 * reader used before, so elements that compare equal end up as they did. */

/* Dirents are ordered by parent, then name, then version, so that the run
 * for one name within one directory is contiguous and its last element is
 * the winning revision. */
static int xx_jffs2_old_dirent_compare(const void *left, const void *right, void *context)
{
    const xx_jffs2_old_dirent *a = (const xx_jffs2_old_dirent *)left;
    const xx_jffs2_old_dirent *b = (const xx_jffs2_old_dirent *)right;
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
static int xx_jffs2_old_fragment_compare(const void *left, const void *right, void *context)
{
    const xx_jffs2_old_fragment *a = (const xx_jffs2_old_fragment *)left;
    const xx_jffs2_old_fragment *b = (const xx_jffs2_old_fragment *)right;
    (void)context;
    if (a->ino != b->ino) return a->ino < b->ino ? -1 : 1;
    if (a->version != b->version) return a->version < b->version ? -1 : 1;
    if (a->data_offset != b->data_offset) {
        return a->data_offset < b->data_offset ? -1 : 1;
    }
    return 0;
}
