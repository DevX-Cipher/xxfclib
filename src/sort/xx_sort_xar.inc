/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int xx_xar_id_compare(const void *left, const void *right)
{
    const xx_xar_id *a = (const xx_xar_id *)left;
    const xx_xar_id *b = (const xx_xar_id *)right;
    return a->id < b->id ? -1 : a->id > b->id ? 1 : a->index < b->index ? -1 : a->index > b->index ? 1 : 0;
}
