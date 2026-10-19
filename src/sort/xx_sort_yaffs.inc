/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static bool xx_yaffs_chunk_less(const xx_yaffs_data_chunk *left, const xx_yaffs_data_chunk *right)
{
    if (left->object_id != right->object_id) {
        return left->object_id < right->object_id;
    }
    if (left->chunk_id != right->chunk_id) {
        return left->chunk_id < right->chunk_id;
    }
    return left->offset < right->offset;
}

static void xx_yaffs_sift_down(xx_yaffs_data_chunk *items, size_t root, size_t count)
{
    while (root * 2U + 1U < count) {
        size_t child = root * 2U + 1U;
        xx_yaffs_data_chunk temporary;
        if (child + 1U < count && xx_yaffs_chunk_less(&items[child], &items[child + 1U])) {
            ++child;
        }
        if (!xx_yaffs_chunk_less(&items[root], &items[child])) return;
        temporary = items[root];
        items[root] = items[child];
        items[child] = temporary;
        root = child;
    }
}

static void xx_yaffs_sort_chunks(xx_yaffs_data_chunk *items, size_t count)
{
    size_t index;
    if (count < 2U) return;
    for (index = count / 2U; index-- > 0U;) {
        xx_yaffs_sift_down(items, index, count);
    }
    for (index = count; index-- > 1U;) {
        xx_yaffs_data_chunk temporary = items[0];
        items[0] = items[index];
        items[index] = temporary;
        xx_yaffs_sift_down(items, 0U, index);
    }
}
