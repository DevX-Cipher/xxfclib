/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void xx_lh1_rebuild(xx_lh1_state *state)
{
    int i;
    int j = 0;
    int k;
    for (i = 0; i < XX_LH1_T; ++i) {
        if (state->child[i] >= XX_LH1_T) {
            state->freq[j] = (state->freq[i] + 1) / 2;
            state->child[j++] = state->child[i];
        }
    }
    for (i = 0, k = XX_LH1_N_CHAR; k < XX_LH1_T; i += 2, ++k) {
        int frequency = state->freq[i] + state->freq[i + 1];
        int location = k - 1;
        while (location >= 0 && frequency < state->freq[location]) --location;
        ++location;
        for (j = k; j > location; --j) {
            state->freq[j] = state->freq[j - 1];
            state->child[j] = state->child[j - 1];
        }
        state->freq[location] = frequency;
        state->child[location] = i;
    }
    for (i = 0; i < XX_LH1_T; ++i) {
        k = state->child[i];
        if (k >= XX_LH1_T) state->parent[k] = i;
        else {
            state->parent[k] = i;
            state->parent[k + 1] = i;
        }
    }
}

static void xx_lh1_update(xx_lh1_state *state, int symbol)
{
    int node;
    if (state->freq[XX_LH1_R] == XX_LH1_MAX_FREQ) xx_lh1_rebuild(state);
    node = state->parent[symbol + XX_LH1_T];
    do {
        int frequency = ++state->freq[node];
        int other = node + 1;
        if (frequency > state->freq[other]) {
            int first;
            int second;
            while (frequency > state->freq[other + 1]) ++other;
            state->freq[node] = state->freq[other];
            state->freq[other] = frequency;
            first = state->child[node];
            state->parent[first] = other;
            if (first < XX_LH1_T) state->parent[first + 1] = other;
            second = state->child[other];
            state->child[other] = first;
            state->parent[second] = node;
            if (second < XX_LH1_T) state->parent[second + 1] = node;
            state->child[node] = second;
            node = other;
        }
        node = state->parent[node];
    } while (node != 0);
}
