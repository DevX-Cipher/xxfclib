/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int pdf_entry_compare(const void *a, const void *b, void *context)
{
    const pdf_entry *x = (const pdf_entry *)a, *y = (const pdf_entry *)b;
    (void)context;
    if (x->id != y->id) return x->id < y->id ? -1 : 1;
    return x->rank < y->rank ? -1 : x->rank > y->rank ? 1 : 0;
}
