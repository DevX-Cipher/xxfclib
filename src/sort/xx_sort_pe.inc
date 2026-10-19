/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static uint16_t *xx_pe_get_sorted_section_indices(const xx_pe *pe)
{
    uint16_t *indices;
    size_t i;
    if (!pe || !pe->number_of_sections || !pe->sections) return NULL;
    indices = (uint16_t *)xx_mem_alloc((size_t)pe->number_of_sections * sizeof(*indices));
    if (!indices) return NULL;
    for (i = 0U; i < pe->number_of_sections; ++i) {
        uint16_t key = (uint16_t)i;
        size_t j = i;
        while (j > 0U && pe->sections[indices[j - 1U]].virtual_address > pe->sections[key].virtual_address) {
            indices[j] = indices[j - 1U];
            --j;
        }
        indices[j] = key;
    }
    return indices;
}
