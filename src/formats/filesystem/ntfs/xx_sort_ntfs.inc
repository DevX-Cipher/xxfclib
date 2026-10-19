/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int xx_ntfs_compare_names(const void *left, const void *right, void *context)
{
    const char *const *a = (const char *const *)left;
    const char *const *b = (const char *const *)right;
    (void)context;
    return xx_rt_strcmp(*a, *b);
}
