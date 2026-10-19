/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

/* Elements are section indices; context is the xx_pe. */
static int xx_pe_compare_section_indices(const void *left, const void *right, void *context)
{
    const xx_pe *pe = (const xx_pe *)context;
    uint16_t left_index = *(const uint16_t *)left;
    uint16_t right_index = *(const uint16_t *)right;
    uint32_t a = pe->sections[left_index].virtual_address;
    uint32_t b = pe->sections[right_index].virtual_address;
    if (a != b) return a < b ? -1 : 1;
    return left_index < right_index ? -1 : (left_index > right_index ? 1 : 0);
}

static uint16_t *xx_pe_get_sorted_section_indices(const xx_pe *pe)
{
    uint16_t *indices;
    size_t i;
    if (!pe || !pe->number_of_sections || !pe->sections) return NULL;
    indices = (uint16_t *)xx_mem_alloc((size_t)pe->number_of_sections * sizeof(*indices));
    if (!indices) return NULL;
    for (i = 0U; i < pe->number_of_sections; ++i) {
        indices[i] = (uint16_t)i;
    }
    /* The index tie-break keeps sections at the same address in table order. */
    xx_sort_context(indices, pe->number_of_sections, sizeof(*indices), xx_pe_compare_section_indices, (void *)pe);
    return indices;
}
