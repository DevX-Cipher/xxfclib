/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void rsvk_model_update(rsvk_model *model, int32_t index)
{
    int32_t i;
    if (model->max_frequency <= model->cumulative[0]) {
        int32_t running = 0;
        for (i = model->symbols; i >= 0; --i) {
            model->frequency[i] = (model->frequency[i] + 1) / 2;
            model->cumulative[i] = running;
            running += model->frequency[i];
        }
    }
    i = index;
    while ((i > 0) && (model->frequency[i] == model->frequency[i - 1])) --i;
    if (i < index) {
        const int32_t char_at_i = model->index_to_char[i];
        const int32_t char_at_n = model->index_to_char[index];
        model->index_to_char[i] = char_at_n;
        model->index_to_char[index] = char_at_i;
        model->char_to_index[char_at_i] = index;
        model->char_to_index[char_at_n] = i;
    }
    model->frequency[i] += model->increment;
    while (i > 0) {
        --i;
        model->cumulative[i] += model->increment;
    }
}
