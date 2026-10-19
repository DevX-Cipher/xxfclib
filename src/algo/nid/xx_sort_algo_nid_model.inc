/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void nid_update(nid_model *model, int32_t position)
{
    uint16_t symbol = model->symbol_at[position];
    uint16_t new_weight;
    int32_t i;

    /* Deliberate: the reference bumps the running total and rescales BEFORE
     * adding the step to the symbol's own weight, so the rescaled symbol
     * weight then receives a full, unhalved step. */
    model->total = (uint16_t)(model->total + NID_WEIGHT_STEP);
    if ((uint32_t)model->total > NID_WEIGHT_LIMIT) nid_rescale(model, (uint32_t)NID_WEIGHT_STEP);

    model->weight[position + 1] = (uint16_t)(model->weight[position + 1] + NID_WEIGHT_STEP);
    new_weight = model->weight[position + 1];

    i = position;
    while ((i >= 1) && (new_weight > model->weight[i])) {
        model->symbol_at[i] = model->symbol_at[i - 1];
        model->weight[i + 1] = model->weight[i];
        model->position_of[model->symbol_at[i - 1]] = (uint16_t)i;
        --i;
    }

    if (position != i) {
        model->weight[i + 1] = new_weight;
        model->symbol_at[i] = symbol;
        model->position_of[symbol] = (uint16_t)i;
    }
}
