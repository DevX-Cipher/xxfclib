/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void hzl_reconstruct(hzl_state *state)
{
    int32_t i;
    int32_t j;
    int32_t n;
    j = 0;
    for (i = 0; i < HZL_T; ++i) {
        if (state->child[i] >= HZL_T) {
            state->frequency[j] = (state->frequency[i] + 1) / 2;
            state->child[j] = state->child[i];
            ++j;
        }
    }
    i = 0;
    j = HZL_N_CHAR;
    for (; j < HZL_T; i += 2, ++j) {
        int32_t sum = state->frequency[i] + state->frequency[i + 1];
        int32_t k = j - 1;
        int32_t m;
        while ((k > 0) && (sum < state->frequency[k])) --k;
        /* The "k > 0" stop plus this compensating ++k is the classic LZHUF
         * insertion point search; it is load-bearing, do not "simplify". */
        if (sum >= state->frequency[k]) ++k;
        for (m = j; m > k; --m) {
            state->frequency[m] = state->frequency[m - 1];
            state->child[m] = state->child[m - 1];
        }
        state->frequency[k] = sum;
        state->child[k] = i;
    }
    for (n = 0; n < HZL_T; ++n) {
        int32_t k = state->child[n];
        state->parent[k] = n;
        if (k < HZL_T) state->parent[k + 1] = n;
    }
}

static bool hzl_update(hzl_state *state, int32_t character)
{
    int32_t c;
    if (state->frequency[HZL_R] == HZL_MAX_FREQ) hzl_reconstruct(state);
    c = state->parent[character + HZL_T];
    do {
        int32_t k;
        int32_t l;
        if ((c < 0) || (c >= HZL_T)) return false;
        k = ++state->frequency[c];
        l = c + 1;
        if (k > state->frequency[l]) {
            /* frequency[HZL_T] is the 0xffff sentinel, so this walk always
             * terminates at or before HZL_T on a sane tree; the bound is
             * defensive only. */
            while ((l < HZL_T) && (k > state->frequency[l])) ++l;
            if (k > state->frequency[l]) return false;
            --l;
            if ((l < 0) || (l >= HZL_T)) return false;
            {
                int32_t i = state->child[c];
                int32_t j;
                state->frequency[c] = state->frequency[l];
                state->frequency[l] = k;
                if ((i < 0) || (i >= HZL_T + HZL_N_CHAR)) return false;
                state->parent[i] = l;
                if (i < HZL_T) state->parent[i + 1] = l;
                j = state->child[l];
                state->child[l] = i;
                if ((j < 0) || (j >= HZL_T + HZL_N_CHAR)) return false;
                state->parent[j] = c;
                if (j < HZL_T) state->parent[j + 1] = c;
                state->child[c] = j;
                c = l;
            }
        }
        c = state->parent[c];
    } while (c != 0);
    return true;
}
