/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int sf_compare_names(const char *left, const char *right)
{
    const uint8_t *a = (const uint8_t *)left;
    const uint8_t *b = (const uint8_t *)right;
    size_t index = 0U;
    for (;;) {
        uint32_t x = a[index] ? sf_fold(a, index) : 0U;
        uint32_t y = b[index] ? sf_fold(b, index) : 0U;
        if (x != y) return x < y ? -1 : 1;
        if (x == 0U) return 0;
        ++index;
    }
}

static int sf_compare_keys(const void *left, const void *right, void *context)
{
    const sf_key *a = (const sf_key *)left;
    const sf_key *b = (const sf_key *)right;
    int result = sf_compare_names(a->name, b->name);
    (void)context;
    if (result != 0) return result;
    return a->index < b->index ? -1 : (a->index > b->index ? 1 : 0);
}
