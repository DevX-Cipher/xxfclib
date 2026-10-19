/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int pdf_string_compare(const void *a, const void *b, void *context)
{
    (void)context;
    return xx_rt_strcmp(*(const char *const *)a, *(const char *const *)b);
}
