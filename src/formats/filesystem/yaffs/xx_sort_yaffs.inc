/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

/* Chunk offsets are unique (one chunk per scanned page), so this is a total
 * order. */
static int xx_yaffs_chunk_compare(const void *left, const void *right, void *context)
{
    const xx_yaffs_data_chunk *a = (const xx_yaffs_data_chunk *)left;
    const xx_yaffs_data_chunk *b = (const xx_yaffs_data_chunk *)right;
    (void)context;
    if (a->object_id != b->object_id) {
        return a->object_id < b->object_id ? -1 : 1;
    }
    if (a->chunk_id != b->chunk_id) {
        return a->chunk_id < b->chunk_id ? -1 : 1;
    }
    return a->offset < b->offset ? -1 : (a->offset > b->offset ? 1 : 0);
}

static void xx_yaffs_sort_chunks(xx_yaffs_data_chunk *items, size_t count)
{
    xx_sort_context(items, count, sizeof(*items), xx_yaffs_chunk_compare, NULL);
}
