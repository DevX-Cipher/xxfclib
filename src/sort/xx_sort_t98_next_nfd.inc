/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void nfd_flush_track(nfd_pending *pending, uint32_t count, nfd_sector *out, uint32_t *out_count)
{
    uint32_t i, j;
    for (i = 1U; i < count; ++i) {
        nfd_pending key = pending[i];
        j = i;
        while (j > 0U && pending[j - 1U].r > key.r) {
            pending[j] = pending[j - 1U];
            --j;
        }
        pending[j] = key;
    }
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
