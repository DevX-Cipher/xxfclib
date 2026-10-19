/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int ug_name_cmp(const void *a, const void *b, void *context)
{
    (void)context;
    return xx_str_icmp(*(const char *const *)a, *(const char *const *)b);
}
