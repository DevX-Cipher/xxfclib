/* Private sorting implementation from src/formats/jffs2/xx_jffs2.c. */

/* ---------------------------------------------------------- ordering --- */

/* A byte-wise heapsort. The library is CRT-free, so qsort() is unavailable;
 * heapsort is chosen over an insertion sort because a large image can carry
 * hundreds of thousands of nodes and over a merge sort because it needs no
 * second array. The caller supplies scratch space for one element. */
static void xx_jffs2_sift(uint8_t *base, size_t count, size_t size, size_t root, int (*compare)(const void *, const void *), uint8_t *scratch)
{
    for (;;) {
        size_t child = root * 2U + 1U;
        size_t largest = root;
        if (child >= count) break;
        if (compare(base + child * size, base + largest * size) > 0) {
            largest = child;
        }
        if (child + 1U < count && compare(base + (child + 1U) * size, base + largest * size) > 0) {
            largest = child + 1U;
        }
        if (largest == root) break;
        xx_mem_copy(scratch, base + root * size, size);
        xx_mem_copy(base + root * size, base + largest * size, size);
        xx_mem_copy(base + largest * size, scratch, size);
        root = largest;
    }
}

static void xx_jffs2_sort(void *base, size_t count, size_t size, int (*compare)(const void *, const void *), uint8_t *scratch)
{
    uint8_t *bytes = (uint8_t *)base;
    size_t index;
    if (!bytes || !compare || !scratch || count < 2U) return;
    for (index = count / 2U; index-- > 0U;) {
        xx_jffs2_sift(bytes, count, size, index, compare, scratch);
    }
    for (index = count; index-- > 1U;) {
        xx_mem_copy(scratch, bytes, size);
        xx_mem_copy(bytes, bytes + index * size, size);
        xx_mem_copy(bytes + index * size, scratch, size);
        xx_jffs2_sift(bytes, index, size, 0U, compare, scratch);
    }
}

/* Dirents are ordered by parent, then name, then version, so that the run
 * for one name within one directory is contiguous and its last element is
 * the winning revision. */
static int xx_jffs2_dirent_compare(const void *left, const void *right)
{
    const xx_jffs2_dirent *a = (const xx_jffs2_dirent *)left;
    const xx_jffs2_dirent *b = (const xx_jffs2_dirent *)right;
    int order;
    if (a->pino != b->pino) return a->pino < b->pino ? -1 : 1;
    order = xx_str_cmp(a->name, b->name);
    if (order != 0) return order;
    if (a->version != b->version) return a->version < b->version ? -1 : 1;
    return 0;
}

/* Fragments are ordered by inode, then version: replaying one inode's run
 * front to back is exactly the log replay the format specifies. */
static int xx_jffs2_fragment_compare(const void *left, const void *right)
{
    const xx_jffs2_fragment *a = (const xx_jffs2_fragment *)left;
    const xx_jffs2_fragment *b = (const xx_jffs2_fragment *)right;
    if (a->ino != b->ino) return a->ino < b->ino ? -1 : 1;
    if (a->version != b->version) return a->version < b->version ? -1 : 1;
    if (a->data_offset != b->data_offset) {
        return a->data_offset < b->data_offset ? -1 : 1;
    }
    return 0;
}
