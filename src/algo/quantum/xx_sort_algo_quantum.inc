/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its format types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void q_model_reorder(q_model *m)
{
    uint16_t frequencies[Q_MAX_MODEL];
    unsigned i, j;
    for (i = 0; i < m->count; ++i) frequencies[i] = (uint16_t)(((m->cumulative[i] - m->cumulative[i + 1]) + 1U) >> 1U);
    /* Quantum swaps at each comparison.  Picking one maximum per slot yields
     * the same weights but a different order for equal-weight symbols. */
    for (i = 0; i + 1U < m->count; ++i) {
        for (j = i + 1U; j < m->count; ++j) {
            if (frequencies[i] < frequencies[j]) {
                uint16_t weight = frequencies[i];
                uint16_t symbol = m->symbols[i];
                frequencies[i] = frequencies[j];
                frequencies[j] = weight;
                m->symbols[i] = m->symbols[j];
                m->symbols[j] = symbol;
            }
        }
    }
    m->cumulative[m->count] = 0;
    for (i = m->count; i-- > 0;) m->cumulative[i] = (uint16_t)(m->cumulative[i + 1] + frequencies[i]);
    m->reorder_after = 50;
}
