/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int wise_span_compare(const void *left, const void *right, void *context)
{
    const wise_span *a = (const wise_span *)left;
    const wise_span *b = (const wise_span *)right;
    (void)context;
    if (a->span != b->span) return a->span < b->span ? -1 : 1;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
