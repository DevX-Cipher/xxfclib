/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

/* By R number; sectors with equal R keep their order on the track. */
static int nfd_pending_compare(const void *left, const void *right, void *context)
{
    const nfd_pending *a = (const nfd_pending *)left;
    const nfd_pending *b = (const nfd_pending *)right;
    (void)context;
    return a->r < b->r ? -1 : (a->r > b->r ? 1 : 0);
}

static void nfd_flush_track(nfd_pending *pending, uint32_t count, nfd_sector *out, uint32_t *out_count)
{
    uint32_t i;
    /* Stable, as the insertion sort this replaced was, so the order is unchanged. */
    xx_sort_stable_context(pending, count, sizeof(*pending), nfd_pending_compare, NULL);
    if (!out) {
        *out_count += count;
        return;
    }
    for (i = 0U; i < count; ++i) {
        out[*out_count].offset = pending[i].offset;
        out[*out_count].size = pending[i].size;
        ++*out_count;
    }
}
