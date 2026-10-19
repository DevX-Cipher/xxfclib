/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void sls_reconstruct(sls_state *state)
{
    int32_t i;
    int32_t j;
    int32_t n;
    j = 0;
    for (i = 0; i < SLS_T; ++i) {
        if (state->child[i] >= SLS_T) {
            state->frequency[j] = (state->frequency[i] + 1U) / 2U;
            state->child[j] = state->child[i];
            ++j;
        }
    }
    i = 0;
    for (j = SLS_N_CHAR; j < SLS_T; ++j) {
        uint32_t sum = state->frequency[i] + state->frequency[i + 1];
        int32_t k = j - 1;
        int32_t n2;
        /* The reference's insertion search has no lower bound and then always
         * increments: the halved leaf frequencies are sorted ascending and are
         * all >= 1, so sum >= 2 >= frequency[0] and the walk can never run off
         * the front.  Kept exactly as the reference spells it. */
        while (sum < state->frequency[k]) --k;
        ++k;
        for (n2 = j; n2 > k; --n2) {
            state->frequency[n2] = state->frequency[n2 - 1];
            state->child[n2] = state->child[n2 - 1];
        }
        state->frequency[k] = sum;
        state->child[k] = i;
        i += 2;
    }
    for (n = 0; n < SLS_T; ++n) {
        int32_t k = state->child[n];
        state->parent[k] = n;
        if (k < SLS_T) state->parent[k + 1] = n;
    }
}

static bool sls_update(sls_state *state, int32_t character)
{
    int32_t c;
    if (state->frequency[SLS_R] == SLS_MAX_FREQ) sls_reconstruct(state);
    c = state->parent[character + SLS_T];
    do {
        uint32_t k;
        if ((c < 0) || (c >= SLS_T)) return false; /* defensive only */
        ++state->frequency[c];
        k = state->frequency[c];
        if (k > state->frequency[c + 1]) {
            int32_t l = c + 2;
            int32_t i;
            int32_t j;
            /* frequency[T] is the 0xffff sentinel and k <= MAX_FREQ (0x8000),
             * so this walk always stops at or before T on a sane tree; the
             * bound is defensive. */
            while ((l <= SLS_T) && (k > state->frequency[l])) ++l;
            if ((l > SLS_T) || (k > state->frequency[l])) return false;
            --l;
            if ((l < 0) || (l >= SLS_T)) return false;
            state->frequency[c] = state->frequency[l];
            state->frequency[l] = k;
            i = state->child[c];
            if ((i < 0) || (i >= SLS_T + SLS_N_CHAR)) return false;
            state->parent[i] = l;
            if (i < SLS_T) state->parent[i + 1] = l;
            j = state->child[l];
            if ((j < 0) || (j >= SLS_T + SLS_N_CHAR)) return false;
            state->child[l] = i;
            state->parent[j] = c;
            if (j < SLS_T) state->parent[j + 1] = c;
            state->child[c] = j;
            c = l;
        }
        c = state->parent[c];
    } while (c != 0);
    return true;
}
