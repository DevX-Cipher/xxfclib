/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

/* Order of member indices by (data offset, entry index); a total order, as
 * entry indices are unique. An xx_sort_callback; context is the member array. */
static int pyi_compare_order(const void *left, const void *right, void *context)
{
    const pyi_member *items = (const pyi_member *)context;
    const pyi_member *a = &items[*(const uint32_t *)left];
    const pyi_member *b = &items[*(const uint32_t *)right];
    if (a->data_offset != b->data_offset) return a->data_offset < b->data_offset ? -1 : 1;
    return a->entry_index < b->entry_index ? -1 : (a->entry_index > b->entry_index ? 1 : 0);
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
    xx_sort_context(order, count, sizeof(*order), pyi_compare_order, stream->items);
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
