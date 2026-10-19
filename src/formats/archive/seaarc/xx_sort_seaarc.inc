/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int xx_seaarc_compare_names(const char *x, const char *y)
{
    size_t x_length = xx_seaarc_key_length(x);
    size_t y_length = xx_seaarc_key_length(y);
    size_t index;

    for (index = 0U; index < x_length && index < y_length; ++index) {
        unsigned char cx = (unsigned char)xx_seaarc_upper(x[index]);
        unsigned char cy = (unsigned char)xx_seaarc_upper(y[index]);
        if (cx != cy) return cx < cy ? -1 : 1;
    }
    if (x_length != y_length) return x_length < y_length ? -1 : 1;
    return 0;
}

static int xx_seaarc_compare_keys(const void *left, const void *right, void *context)
{
    const xx_seaarc_name_key *a = (const xx_seaarc_name_key *)left;
    const xx_seaarc_name_key *b = (const xx_seaarc_name_key *)right;
    int order = xx_seaarc_compare_names(a->name, b->name);

    (void)context;
    if (order != 0) return order;
    /* Equal names keep archive order, so the first member keeps its name. */
    return a->item < b->item ? -1 : (a->item > b->item ? 1 : 0);
}
