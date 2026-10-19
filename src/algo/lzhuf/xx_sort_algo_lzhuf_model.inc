/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void xx_lzhuf_reconstruct(xx_lzhuf_state *state)
{
    int i;
    int j;
    int n;

    j = 0;
    for (i = 0; i < state->t; ++i) {
        if (state->son[i] >= state->t) {
            state->freq[j] = (uint16_t)((state->freq[i] + 1) >> 1);
            state->son[j] = state->son[i];
            ++j;
        }
    }

    i = 0;
    j = state->n_char;
    while (j < state->t) {
        int k;
        uint16_t freq = (uint16_t)(state->freq[i] + state->freq[i + 1]);
        state->freq[j] = freq;

        k = j - 1;
        /* The frequencies below j are already sorted, so this walk always
         * stops; the k >= 0 bound only matters for a tree corrupted by a bad
         * stream, where the original would index off the front of the array. */
        while ((k >= 0) && (freq < state->freq[k])) --k;
        ++k;

        for (n = j; n > k; --n) {
            state->freq[n] = state->freq[n - 1];
            state->son[n] = state->son[n - 1];
        }

        state->freq[k] = freq;
        state->son[k] = i;

        i += 2;
        ++j;
    }

    for (n = 0; n < state->t; ++n) {
        int k = state->son[n];
        if (k < state->t) {
            state->prnt[k] = n;
            state->prnt[k + 1] = n;
        } else {
            state->prnt[k] = n;
        }
    }
}

static void xx_lzhuf_update(xx_lzhuf_state *state, int symbol)
{
    int c;

    if ((int)state->freq[state->r] == state->max_freq) {
        /* Some embedders simply stop re-weighting from here instead of halving
         * and rebuilding. Neither is reached by the current corpora, but they
         * are not interchangeable. */
        if (!state->reconstruct) return;
        xx_lzhuf_reconstruct(state);
    }

    c = state->prnt[symbol + state->t];

    do {
        uint16_t freq;
        int l;

        state->freq[c] = (uint16_t)(state->freq[c] + 1);
        freq = state->freq[c];
        l = c + 1;

        if (state->freq[l] < freq) {
            /* freq[T] is the 0xFFFF sentinel that stops this walk, so l may
             * legitimately reach T - one past the last node - before the
             * decrement below pulls it back into range. */
            int i;
            int j;

            l = c + 2;
            while ((l <= state->t) && (state->freq[l] < freq)) ++l;
            --l;
            if ((l < 0) || (l >= state->t)) return;

            state->freq[c] = state->freq[l];
            state->freq[l] = freq;

            i = state->son[c];
            state->prnt[i] = l;
            if (i < state->t) state->prnt[i + 1] = l;

            j = state->son[l];
            state->son[l] = i;
            state->prnt[j] = c;
            if (j < state->t) state->prnt[j + 1] = c;

            state->son[c] = j;
            c = l;
        }

        c = state->prnt[c];
    } while (c != 0);
}
