/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

/* Sectors by id. An xx_sort_callback; no context. */
static int udi_sector_compare(const void *left, const void *right, void *context)
{
    const udi_sector *a = (const udi_sector *)left;
    const udi_sector *b = (const udi_sector *)right;
    (void)context;
    return a->id < b->id ? -1 : (a->id > b->id ? 1 : 0);
}
