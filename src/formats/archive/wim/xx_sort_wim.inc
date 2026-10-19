/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

/* Blob indices by hash, then index. An xx_sort_callback; context is the
 * wim_model. */
static int wim_blob_cmp(const void *left, const void *right, void *context)
{
    const wim_model *m = (const wim_model *)context;
    uint32_t a = *(const uint32_t *)left, b = *(const uint32_t *)right;
    int c = xx_rt_memcmp(m->blobs[a].hash, m->blobs[b].hash, WIM_HASH_SIZE);
    if (c != 0) return c;
    return a < b ? -1 : (a > b ? 1 : 0);
}

static bool wim_sort_blobs(wim_model *m)
{
    size_t n = 0U, i, kept;
    m->sorted = (uint32_t *)xx_mem_alloc((m->blob_count + 1U) * sizeof(uint32_t));
    if (!m->sorted) return false;
    for (i = 0U; i < m->blob_count; ++i) {
        const wim_blob *b = &m->blobs[i];
        if ((uint32_t)i == m->xml_blob || (b->flags & WIM_RES_METADATA) != 0U || wim_is_zero_hash(b->hash)) continue;
        m->sorted[n++] = (uint32_t)i;
    }
    /* Stable, as the merge sort this replaced was, so the order is unchanged. */
    xx_sort_stable_context(m->sorted, n, sizeof(*m->sorted), wim_blob_cmp, m);
    for (i = 0U, kept = 0U; i < n; ++i) {
        if (kept != 0U && xx_rt_memcmp(m->blobs[m->sorted[kept - 1U]].hash, m->blobs[m->sorted[i]].hash, WIM_HASH_SIZE) == 0) continue;
        m->sorted[kept++] = m->sorted[i];
    }
    m->sorted_count = kept;
    return true;
}
