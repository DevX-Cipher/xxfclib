/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int wpi_compare_spans(const void *left, const void *right)
{
    const wpi_span *a = (const wpi_span *)left;
    const wpi_span *b = (const wpi_span *)right;
    if (a->start != b->start) return a->start < b->start ? -1 : 1;
    return a->end < b->end ? -1 : (a->end > b->end ? 1 : 0);
}
