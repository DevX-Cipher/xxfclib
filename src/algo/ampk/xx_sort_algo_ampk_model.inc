/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void ampk_lzari_update(ampk_lzari *state, int symbol)
{
    int index;
    if (state->symbol_cumulative[0] >= AMPK_MAX_CUM) {
        uint32_t accumulated = 0U;
        for (index = (int)AMPK_LZARI_NCHAR; index > 0; --index) {
            state->symbol_cumulative[index] = accumulated;
            state->symbol_frequency[index] = (state->symbol_frequency[index] + 1U) >> 1U;
            accumulated += state->symbol_frequency[index];
        }
        state->symbol_cumulative[0] = accumulated;
    }
    index = symbol;
    while (index > 0 && state->symbol_frequency[index] == state->symbol_frequency[index - 1]) --index;
    if (index < symbol) {
        int first = state->symbol_to_char[index];
        int second = state->symbol_to_char[symbol];
        state->symbol_to_char[index] = second;
        state->symbol_to_char[symbol] = first;
        state->char_to_symbol[first] = symbol;
        state->char_to_symbol[second] = index;
    }
    ++state->symbol_frequency[index];
    for (--index; index >= 0; --index) ++state->symbol_cumulative[index];
}
