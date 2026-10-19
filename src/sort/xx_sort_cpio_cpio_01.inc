/* Private sorting implementation from src/formats/cpio/xx_cpio.c. */

/* Inode identity first, so that each inode's carriers are adjacent, then
 * archive order. */
static int cpio_link_compare(const cpio_member *left, size_t left_index, const cpio_member *right, size_t right_index)
{
    if (left->variant != right->variant) return left->variant < right->variant ? -1 : 1;
    if (left->devmajor != right->devmajor) return left->devmajor < right->devmajor ? -1 : 1;
    if (left->devminor != right->devminor) return left->devminor < right->devminor ? -1 : 1;
    if (left->ino != right->ino) return left->ino < right->ino ? -1 : 1;
    return left_index < right_index ? -1 : (left_index > right_index ? 1 : 0);
}

static int cpio_link_order_compare(const void *left, const void *right, void *context)
{
    const cpio_member *items = (const cpio_member *)context;
    size_t a = *(const size_t *)left;
    size_t b = *(const size_t *)right;
    return cpio_link_compare(&items[a], a, &items[b], b);
}
