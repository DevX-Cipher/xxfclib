/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static int erisa_model_increase(erisa_model *model, int index)
{
    uint16_t occured = ++model->table[index].occured;
    int16_t symbol = model->table[index].symbol;
    while (--index >= 0) {
        if (model->table[index].occured >= occured) break;
        model->table[index + 1] = model->table[index];
    }
    ++index;
    model->table[index].occured = occured;
    model->table[index].symbol = symbol;
    if (++model->total >= ERISA_TOTAL_LIMIT) erisa_model_half(model);
    return index;
}
