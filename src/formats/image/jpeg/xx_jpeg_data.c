/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * jpeg data structures, moved out of the image schema family. */
#include "../../xx_format_schema_image.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxi_jpeg_segment_fields[] = {
    SX_FIELD("marker", "uint16", 0, 2, SX_ID),
    SX_FIELD("segment_length", "uint16", 2, 2, SX_SIZE),
};
const sx_layout sxi_jpeg_segment = { UINT32_C(0x60010027), "JPEG_SEGMENT_HEADER", sxi_jpeg_segment_fields, SX_COUNT(sxi_jpeg_segment_fields), SX_BE };
static const xx_data_struct_field_desc sxi_jpeg_frame_fields[] = {
    SX_FIELD("marker", "uint16", 0, 2, SX_ID),
    SX_FIELD("frame_header_length", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("sample_precision", "uint8", 4, 1, SX_NONE),
    SX_FIELD("number_of_lines", "uint16", 5, 2, SX_NONE),
    SX_FIELD("samples_per_line", "uint16", 7, 2, SX_NONE),
    SX_FIELD("number_of_components", "uint8", 9, 1, SX_COUNT_PROP),
};
const sx_layout sxi_jpeg_frame = { UINT32_C(0x60010028), "JPEG_FRAME_HEADER", sxi_jpeg_frame_fields, SX_COUNT(sxi_jpeg_frame_fields), SX_BE };
static const xx_data_struct_field_desc sxi_jpeg_component_fields[] = {
    SX_FIELD("component_identifier", "uint8", 0, 1, SX_ID),
    SX_FIELD("sampling_factors", "uint8", 1, 1, SX_FLAGS),
    SX_FIELD("quantization_table_selector", "uint8", 2, 1, SX_ID),
};
const sx_layout sxi_jpeg_component = { UINT32_C(0x60010029), "JPEG_FRAME_COMPONENT", sxi_jpeg_component_fields, SX_COUNT(sxi_jpeg_component_fields), SX_BE };
static const xx_data_struct_field_desc sxi_jpeg_scan_fields[] = {
    SX_FIELD("marker", "uint16", 0, 2, SX_ID),
    SX_FIELD("scan_header_length", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("number_of_components", "uint8", 4, 1, SX_COUNT_PROP),
};
const sx_layout sxi_jpeg_scan = { UINT32_C(0x6001002A), "JPEG_SCAN_HEADER", sxi_jpeg_scan_fields, SX_COUNT(sxi_jpeg_scan_fields), SX_BE };
static const xx_data_struct_field_desc sxi_jpeg_scan_component_fields[] = {
    SX_FIELD("component_selector", "uint8", 0, 1, SX_ID),
    SX_FIELD("entropy_coding_table_selectors", "uint8", 1, 1, SX_FLAGS),
};
const sx_layout sxi_jpeg_scan_component = { UINT32_C(0x6001002B), "JPEG_SCAN_COMPONENT", sxi_jpeg_scan_component_fields, SX_COUNT(sxi_jpeg_scan_component_fields), SX_BE };
static const xx_data_struct_field_desc sxi_jpeg_scan_tail_fields[] = {
    SX_FIELD("spectral_selection_start", "uint8", 0, 1, SX_NONE),
    SX_FIELD("spectral_selection_end", "uint8", 1, 1, SX_NONE),
    SX_FIELD("successive_approximation", "uint8", 2, 1, SX_FLAGS),
};
const sx_layout sxi_jpeg_scan_tail = { UINT32_C(0x6001002C), "JPEG_SCAN_PARAMETERS", sxi_jpeg_scan_tail_fields, SX_COUNT(sxi_jpeg_scan_tail_fields), SX_BE };
static const xx_data_struct_field_desc sxi_jpeg_dri_fields[] = {
    SX_FIELD("marker", "uint16", 0, 2, SX_ID),
    SX_FIELD("segment_length", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("restart_interval", "uint16", 4, 2, SX_COUNT_PROP),
};
const sx_layout sxi_jpeg_dri = { UINT32_C(0x6001002D), "JPEG_RESTART_INTERVAL", sxi_jpeg_dri_fields, SX_COUNT(sxi_jpeg_dri_fields), SX_BE };
static const xx_data_struct_field_desc sxi_jpeg_jfif_fields[] = {
    SX_FIELD("marker", "uint16", 0, 2, SX_ID),
    SX_FIELD("segment_length", "uint16", 2, 2, SX_SIZE),
    SX_FIELD("identifier", "char[5]", 4, 5, SX_SIGNATURE),
    SX_FIELD("version_major", "uint8", 9, 1, SX_NONE),
    SX_FIELD("version_minor", "uint8", 10, 1, SX_NONE),
    SX_FIELD("density_units", "uint8", 11, 1, SX_ID),
    SX_FIELD("x_density", "uint16", 12, 2, SX_NONE),
    SX_FIELD("y_density", "uint16", 14, 2, SX_NONE),
    SX_FIELD("x_thumbnail", "uint8", 16, 1, SX_NONE),
    SX_FIELD("y_thumbnail", "uint8", 17, 1, SX_NONE),
};
const sx_layout sxi_jpeg_jfif = { UINT32_C(0x6001002E), "JPEG_JFIF_APP0", sxi_jpeg_jfif_fields, SX_COUNT(sxi_jpeg_jfif_fields), SX_BE };
static const xx_data_struct_field_desc sxi_jpeg_dqt8_fields[] = {
    SX_FIELD("precision_and_identifier", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("quantization_values", "uint8[64]", 1, 64, SX_NONE),
};
const sx_layout sxi_jpeg_dqt8 = { UINT32_C(0x6001002F), "JPEG_QUANTIZATION_TABLE8", sxi_jpeg_dqt8_fields, SX_COUNT(sxi_jpeg_dqt8_fields), SX_BE };
static const xx_data_struct_field_desc sxi_jpeg_dqt16_fields[] = {
    SX_FIELD("precision_and_identifier", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("quantization_values", "uint16[64]", 1, 128, SX_NONE),
};
const sx_layout sxi_jpeg_dqt16 = { UINT32_C(0x60010030), "JPEG_QUANTIZATION_TABLE16", sxi_jpeg_dqt16_fields, SX_COUNT(sxi_jpeg_dqt16_fields), SX_BE };
static bool sx_image_jpeg(sx_context *c)
{
    uint8_t h[18];
    int64_t at = 0;
    unsigned markers = 0;
    sxi_cursor cursor = {c, -1, 0, {0}};
    if (!sx_read(c, 0, h, 2) || h[0] != 0xff || h[1] != 0xd8) return false;
    while (++markers <= 100000U) {
        uint8_t marker;
        uint16_t length;
        int64_t end;
        if (!sx_read(c, at, h, 2) || h[0] != 0xff || !h[1]) return false;
        if (h[1] == 0xff) {
            /* Fill bytes are physical bytes, not an extra marker. */
            if (!sx_raw(c, at, 1)) return false;
            ++at;
            continue;
        }
        marker = h[1];
        if (marker == 0x01 || (marker >= 0xd0 && marker <= 0xd9)) {
            if (!sx_add(c, &sxi_jpeg_marker, at, 2)) return false;
            if (marker == 0xd9) return true;
            at += 2;
            continue;
        }
        if (!sx_u16(c, at + 2, true, &length) || length < 2 || !sx_image_range(c, at, (uint64_t)length + 2)) return false;
        end = at + length + 2;
        if (marker >= 0xc0 && marker <= 0xcf && marker != 0xc4 && marker != 0xc8 && marker != 0xcc) {
            unsigned n;
            if (length < 8 || !sx_read(c, at + 9, h, 1)) return false;
            n = h[0];
            if (!n || length != 8U + 3U * n || !sx_add(c, &sxi_jpeg_frame, at, 10) || !sx_table(c, &sxi_jpeg_component, at + 10, 3, n)) return false;
        } else if (marker == 0xda) {
            unsigned n;
            if (length < 6 || !sx_read(c, at + 4, h, 1)) return false;
            n = h[0];
            if (!n || length != 6U + 2U * n || !sx_add(c, &sxi_jpeg_scan, at, 5) ||
                !sx_table(c, &sxi_jpeg_scan_component, at + 5, 2, n) || !sx_add(c, &sxi_jpeg_scan_tail, at + 5 + (int64_t)n * 2, 3)) return false;
        } else if (marker == 0xdd) {
            if (length != 4 || !sx_add(c, &sxi_jpeg_dri, at, 6)) return false;
        } else if (marker == 0xe0 && length >= 16 && sx_read(c, at + 4, h, 5) && !xx_rt_memcmp(h, "JFIF\0", 5)) {
            if (!sx_add(c, &sxi_jpeg_jfif, at, 18) || !sx_raw(c, at + 18, length - 16)) return false;
        } else if (marker == 0xdb || marker == 0xc4) {
            int64_t p = at + 4;
            if (!sx_add(c, &sxi_jpeg_segment, at, 4)) return false;
            while (p < end) {
                if (marker == 0xdb) {
                    unsigned n;
                    if (!sx_read(c, p, h, 1) || (h[0] >> 4) > 1 || (h[0] & 15) > 3) return false;
                    n = (h[0] >> 4) ? 129 : 65;
                    if (n > (uint64_t)(end - p) || !sx_add(c, n == 129 ? &sxi_jpeg_dqt16 : &sxi_jpeg_dqt8, p, n)) return false;
                    p += n;
                } else {
                    unsigned n = 0, i;
                    if (end - p < 17 || !sx_read(c, p, h, 17) || (h[0] >> 4) > 1 || (h[0] & 15) > 3) return false;
                    for (i = 1; i <= 16; ++i) n += h[i];
                    if (n > 256 || n > (uint64_t)(end - p - 17) || !sx_add(c, &sxi_jpeg_dht, p, 17) || !sx_raw(c, p + 17, n)) return false;
                    p += (int64_t)n + 17;
                }
            }
        } else if (!sx_add(c, &sxi_jpeg_segment, at, 4) || !sx_raw(c, at + 4, length - 2)) return false;
        at = end;
        if (marker == 0xda) {
            int64_t start = at;
            /* Entropy-coded bytes contain FF00 stuffing and restart markers.
             * Emit restart markers separately without decoding sample data. */
            for (;;) {
                if (!sxi_byte(&cursor, at, h)) return false;
                if (h[0] != 0xff) { ++at; continue; }
                if (!sxi_byte(&cursor, at + 1, h + 1)) return false;
                if (h[1] == 0) { at += 2; continue; }
                if (h[1] >= 0xd0 && h[1] <= 0xd7) {
                    if (!sx_raw(c, start, at - start) || !sx_add(c, &sxi_jpeg_marker, at, 2)) return false;
                    at += 2;
                    start = at;
                    continue;
                }
                if (!sx_raw(c, start, at - start)) return false;
                break;
            }
        }
    }
    return false;
}
bool sx_jpeg_build(sx_context*c)
{
    return sx_image_jpeg(c);
}
