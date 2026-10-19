/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int dm_compare_records(const void *left, const void *right, void *context)
{
    const dm_slot *files = (const dm_slot *)context;
    uint32_t a = *(const uint32_t *)left, b = *(const uint32_t *)right;
    if (files[a].record != files[b].record) return files[a].record < files[b].record ? -1 : 1;
    return a < b ? -1 : (a > b ? 1 : 0);
}
