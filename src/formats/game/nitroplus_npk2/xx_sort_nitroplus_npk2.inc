/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int np_fold_compare(const char *a, const char *b)
{
    for (;;) {
        unsigned char x = (unsigned char)*a++, y = (unsigned char)*b++;
        if (x >= 'A' && x <= 'Z') x = (unsigned char)(x + 'a' - 'A');
        if (y >= 'A' && y <= 'Z') y = (unsigned char)(y + 'a' - 'A');
        if (x != y) return x < y ? -1 : 1;
        if (!x) return 0;
    }
}
static int np_compare_keys(const void *left, const void *right, void *context)
{
    const np_name_key *x = (const np_name_key *)left, *y = (const np_name_key *)right;
    int result = np_fold_compare(x->name, y->name);
    (void)context;
    return result ? result : x->index < y->index ? -1 : x->index > y->index ? 1 : 0;
}
