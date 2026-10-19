/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int xx_tar_name_order_compare(const void *left, const void *right, void *context)
{
    char *const *names = (char *const *)context;
    size_t a = *(const size_t *)left;
    size_t b = *(const size_t *)right;
    int order = xx_rt_strcmp(names[a], names[b]);
    if (order != 0) return order;
    return a < b ? -1 : (a > b ? 1 : 0);
}
