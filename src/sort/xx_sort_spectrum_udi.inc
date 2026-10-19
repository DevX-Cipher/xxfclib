/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

    /* Insertion sort by id (<= 256 entries, ids unique). */
    for (index = 1U; index < work->count; ++index) {
        udi_sector key = work->sectors[index];
        uint32_t at = index;
        while (at > 0U && work->sectors[at - 1U].id > key.id) {
            work->sectors[at] = work->sectors[at - 1U];
            --at;
        }
        work->sectors[at] = key;
    }