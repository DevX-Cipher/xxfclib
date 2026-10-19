/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static bool pyi_before(const pyi_member *items, uint32_t left, uint32_t right)
{
    if (items[left].data_offset != items[right].data_offset) return items[left].data_offset < items[right].data_offset;
    return items[left].entry_index < items[right].entry_index;
}

static void pyi_sift(const pyi_member *items, uint32_t *order, size_t root, size_t count)
{
    for (;;) {
        size_t child = root * 2U + 1U;
        uint32_t swap;
        if (child >= count) return;
        if (child + 1U < count && pyi_before(items, order[child], order[child + 1U])) ++child;
        if (!pyi_before(items, order[root], order[child])) return;
        swap = order[root];
        order[root] = order[child];
        order[child] = swap;
        root = child;
    }
}

static bool pyi_mark_overlaps(pyi_stream *stream)
{
    uint32_t *order;
    size_t index, count = stream->count;
    int64_t reach = -1;
    if (count < 2U) return true;
    order = (uint32_t *)xx_mem_alloc(count * sizeof(uint32_t));
    if (!order) return false;
    for (index = 0U; index < count; ++index) order[index] = (uint32_t)index;
    for (index = count / 2U; index-- > 0U;) pyi_sift(stream->items, order, index, count);
    for (index = count - 1U; index > 0U; --index) {
        uint32_t swap = order[0];
        order[0] = order[index];
        order[index] = swap;
        pyi_sift(stream->items, order, 0U, index);
    }
    for (index = 0U; index < count; ++index) {
        pyi_member *member = &stream->items[order[index]];
        int64_t end = member->data_offset + member->packed_size;
        if (member->packed_size == 0) continue;
        if (member->data_offset < reach) member->unsafe = true;
        if (end > reach) reach = end;
    }
    xx_mem_free(order);
    return true;
}
