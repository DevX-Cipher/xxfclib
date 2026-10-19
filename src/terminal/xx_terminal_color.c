/* Copyright (c) 2024-2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * C port of XOptions::hexToGlobalColor/printConsole. Keep the upstream
 * palette ordering (nearest-color ties), ANSI codes and Windows attributes.
 */
#include "xxfclib/terminal/xx_terminal.h"

typedef struct terminal_color {
    uint32_t rgb;
    unsigned int ansi, native;
} terminal_color;

static const terminal_color palette[] = {
    {0x000000, 30, 0}, {0xffffff, 37, 7}, {0x808080, 90, 15}, {0xa0a0a4, 90, 8},
    {0xff0000, 31, 4}, {0x00ff00, 32, 2}, {0x0000ff, 34, 1}, {0x00ffff, 36, 3},
    {0xff00ff, 35, 5}, {0xffff00, 33, 6}, {0x800000, 91, 12}, {0x008000, 92, 10},
    {0x000080, 94, 9}, {0x008080, 96, 11}, {0x800080, 95, 13}, {0x808000, 93, 14}
};

static const terminal_color *nearest_color(uint32_t rgb)
{
    const terminal_color *best = &palette[0];
    unsigned int distance = UINT32_MAX;
    size_t i;
    if (rgb == UINT32_MAX) return NULL;
    for (i = 0; i < sizeof(palette) / sizeof(palette[0]); ++i) {
        int r = (int)((rgb >> 16) & 255) - (int)((palette[i].rgb >> 16) & 255);
        int g = (int)((rgb >> 8) & 255) - (int)((palette[i].rgb >> 8) & 255);
        int b = (int)(rgb & 255) - (int)(palette[i].rgb & 255);
        unsigned int d = (unsigned int)(r * r + g * g + b * b);
        if (d < distance) { distance = d; best = &palette[i]; }
    }
    return best;
}

static size_t append_code(char *text, size_t offset, unsigned int code)
{
    if (code >= 100) text[offset++] = '1';
    text[offset++] = (char)('0' + (code / 10) % 10);
    text[offset++] = (char)('0' + code % 10);
    return offset;
}

xxfc_status_t xx_terminal_write_color(const xx_terminal_state *state,
    const char *text, size_t size, uint32_t foreground, uint32_t background)
{
    const terminal_color *fg, *bg;
    xxfc_status_t status, restored;
    if (!state || (!text && size)) return XXFC_ERR_NULL_PARAM;
    if ((foreground != UINT32_MAX && foreground > 0xffffff) ||
        (background != UINT32_MAX && background > 0xffffff)) return XXFC_ERR_INVALID_ARG;
    if (!size || !state->valid || state->type == XX_TERMINAL_TYPE_NONE || !xx_is_color_output_enabled() ||
        (foreground == UINT32_MAX && background == UINT32_MAX))
        return xx_terminal_write(state, text, size);
    fg = nearest_color(foreground);
    bg = nearest_color(background);
    if (state->type == XX_TERMINAL_TYPE_ANSI) {
        char escape[12] = {'\033', '['};
        size_t length = append_code(escape, 2, fg ? fg->ansi : 39);
        escape[length++] = ';';
        length = append_code(escape, length, bg ? bg->ansi + 10 : 49);
        escape[length++] = 'm';
        status = xx_terminal_write(state, escape, length);
        if (status == XXFC_OK) status = xx_terminal_write(state, text, size);
        restored = xx_terminal_write(state, "\033[0m", 4);
        return status != XXFC_OK ? status : restored;
    }
    if (state->type == XX_TERMINAL_TYPE_WINDOWS) {
        uint16_t saved, attributes;
        if (!xx_terminal_get_attributes(state, &saved)) return xx_terminal_write(state, text, size);
        attributes = saved;
        if (fg) attributes = (uint16_t)((attributes & ~0x0fU) | fg->native);
        if (bg) attributes = (uint16_t)((attributes & ~0xf0U) | (bg->native << 4));
        if (!xx_terminal_set_attributes(state, attributes)) return xx_terminal_write(state, text, size);
        status = xx_terminal_write(state, text, size);
        restored = xx_terminal_set_attributes(state, saved) ? XXFC_OK : XXFC_ERR_IO;
        return status != XXFC_OK ? status : restored;
    }
    return xx_terminal_write(state, text, size);
}
