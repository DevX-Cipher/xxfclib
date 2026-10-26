/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * tiff data structures, moved out of the image schema family. */
#include "../../xx_format_schema_image.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

const sx_layout sxi_tiff_header_be = { UINT32_C(0x60010033), "TIFF_HEADER_BE", sxi_tiff_header_le_fields, SX_COUNT(sxi_tiff_header_le_fields), SX_BE };
static const xx_data_struct_field_desc sxi_bigtiff_header_le_fields[] = {
    SX_FIELD("byte_order", "char[2]", 0, 2, SX_ID),
    SX_FIELD("version", "uint16", 2, 2, SX_ID),
    SX_FIELD("offset_size", "uint16", 4, 2, SX_SIZE),
    SX_FIELD("reserved", "uint16", 6, 2, SX_RESERVED),
    SX_FIELD("first_ifd_offset", "uint64", 8, 8, SX_OFFSET),
};
const sx_layout sxi_bigtiff_header_le = { UINT32_C(0x60010034), "BIGTIFF_HEADER_LE", sxi_bigtiff_header_le_fields, SX_COUNT(sxi_bigtiff_header_le_fields), SX_LE };
const sx_layout sxi_bigtiff_header_be = { UINT32_C(0x60010035), "BIGTIFF_HEADER_BE", sxi_bigtiff_header_le_fields, SX_COUNT(sxi_bigtiff_header_le_fields), SX_BE };
static const xx_data_struct_field_desc sxi_tiff_count_le_fields[] = {
    SX_FIELD("entry_count", "uint16", 0, 2, SX_COUNT_PROP),
};
const sx_layout sxi_tiff_count_le = { UINT32_C(0x60010036), "TIFF_IFD_COUNT_LE", sxi_tiff_count_le_fields, SX_COUNT(sxi_tiff_count_le_fields), SX_LE };
const sx_layout sxi_tiff_count_be = { UINT32_C(0x60010037), "TIFF_IFD_COUNT_BE", sxi_tiff_count_le_fields, SX_COUNT(sxi_tiff_count_le_fields), SX_BE };
static const xx_data_struct_field_desc sxi_bigtiff_count_le_fields[] = {
    SX_FIELD("entry_count", "uint64", 0, 8, SX_COUNT_PROP),
};
const sx_layout sxi_bigtiff_count_le = { UINT32_C(0x60010038), "BIGTIFF_IFD_COUNT_LE", sxi_bigtiff_count_le_fields, SX_COUNT(sxi_bigtiff_count_le_fields), SX_LE };
const sx_layout sxi_bigtiff_count_be = { UINT32_C(0x60010039), "BIGTIFF_IFD_COUNT_BE", sxi_bigtiff_count_le_fields, SX_COUNT(sxi_bigtiff_count_le_fields), SX_BE };
static const xx_data_struct_field_desc sxi_tiff_next_le_fields[] = {
    SX_FIELD("next_ifd_offset", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxi_tiff_next_le = { UINT32_C(0x6001003A), "TIFF_NEXT_IFD_LE", sxi_tiff_next_le_fields, SX_COUNT(sxi_tiff_next_le_fields), SX_LE };
const sx_layout sxi_tiff_next_be = { UINT32_C(0x6001003B), "TIFF_NEXT_IFD_BE", sxi_tiff_next_le_fields, SX_COUNT(sxi_tiff_next_le_fields), SX_BE };
static const xx_data_struct_field_desc sxi_bigtiff_next_le_fields[] = {
    SX_FIELD("next_ifd_offset", "uint64", 0, 8, SX_OFFSET),
};
const sx_layout sxi_bigtiff_next_le = { UINT32_C(0x6001003C), "BIGTIFF_NEXT_IFD_LE", sxi_bigtiff_next_le_fields, SX_COUNT(sxi_bigtiff_next_le_fields), SX_LE };
const sx_layout sxi_bigtiff_next_be = { UINT32_C(0x6001003D), "BIGTIFF_NEXT_IFD_BE", sxi_bigtiff_next_le_fields, SX_COUNT(sxi_bigtiff_next_le_fields), SX_BE };
static const xx_data_struct_field_desc sxi_tiff_entry_inline_le_fields[] = {
    SX_FIELD("tag", "uint16", 0, 2, SX_ID),
    SX_FIELD("field_type", "uint16", 2, 2, SX_ID),
    SX_FIELD("count", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("inline_value", "uint8[4]", 8, 4, SX_NONE),
};
const sx_layout sxi_tiff_entry_inline_le = { UINT32_C(0x6001003E), "TIFF_IFD_ENTRY_INLINE_LE", sxi_tiff_entry_inline_le_fields, SX_COUNT(sxi_tiff_entry_inline_le_fields), SX_LE };
const sx_layout sxi_tiff_entry_inline_be = { UINT32_C(0x6001003F), "TIFF_IFD_ENTRY_INLINE_BE", sxi_tiff_entry_inline_le_fields, SX_COUNT(sxi_tiff_entry_inline_le_fields), SX_BE };
static const xx_data_struct_field_desc sxi_tiff_entry_offset_le_fields[] = {
    SX_FIELD("tag", "uint16", 0, 2, SX_ID),
    SX_FIELD("field_type", "uint16", 2, 2, SX_ID),
    SX_FIELD("count", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("value_offset", "uint32", 8, 4, SX_OFFSET),
};
const sx_layout sxi_tiff_entry_offset_le = { UINT32_C(0x60010040), "TIFF_IFD_ENTRY_OFFSET_LE", sxi_tiff_entry_offset_le_fields, SX_COUNT(sxi_tiff_entry_offset_le_fields), SX_LE };
const sx_layout sxi_tiff_entry_offset_be = { UINT32_C(0x60010041), "TIFF_IFD_ENTRY_OFFSET_BE", sxi_tiff_entry_offset_le_fields, SX_COUNT(sxi_tiff_entry_offset_le_fields), SX_BE };
static const xx_data_struct_field_desc sxi_bigtiff_entry_inline_le_fields[] = {
    SX_FIELD("tag", "uint16", 0, 2, SX_ID),
    SX_FIELD("field_type", "uint16", 2, 2, SX_ID),
    SX_FIELD("count", "uint64", 4, 8, SX_COUNT_PROP),
    SX_FIELD("inline_value", "uint8[8]", 12, 8, SX_NONE),
};
const sx_layout sxi_bigtiff_entry_inline_le = { UINT32_C(0x60010042), "BIGTIFF_IFD_ENTRY_INLINE_LE", sxi_bigtiff_entry_inline_le_fields, SX_COUNT(sxi_bigtiff_entry_inline_le_fields), SX_LE };
const sx_layout sxi_bigtiff_entry_inline_be = { UINT32_C(0x60010043), "BIGTIFF_IFD_ENTRY_INLINE_BE", sxi_bigtiff_entry_inline_le_fields, SX_COUNT(sxi_bigtiff_entry_inline_le_fields), SX_BE };
static const xx_data_struct_field_desc sxi_bigtiff_entry_offset_le_fields[] = {
    SX_FIELD("tag", "uint16", 0, 2, SX_ID),
    SX_FIELD("field_type", "uint16", 2, 2, SX_ID),
    SX_FIELD("count", "uint64", 4, 8, SX_COUNT_PROP),
    SX_FIELD("value_offset", "uint64", 12, 8, SX_OFFSET),
};
const sx_layout sxi_bigtiff_entry_offset_le = { UINT32_C(0x60010044), "BIGTIFF_IFD_ENTRY_OFFSET_LE", sxi_bigtiff_entry_offset_le_fields, SX_COUNT(sxi_bigtiff_entry_offset_le_fields), SX_LE };
const sx_layout sxi_bigtiff_entry_offset_be = { UINT32_C(0x60010045), "BIGTIFF_IFD_ENTRY_OFFSET_BE", sxi_bigtiff_entry_offset_le_fields, SX_COUNT(sxi_bigtiff_entry_offset_le_fields), SX_BE };
static unsigned sx_image_tiff_width(uint16_t type)
{
    static const unsigned widths[19] = {0, 1, 1, 2, 4, 8, 1, 1, 2, 4, 8, 4, 8, 4, 0, 0, 8, 8, 8};
    return type < SX_COUNT(widths) ? widths[type] : 0;
}
static bool sx_image_tiff_queue(uint64_t *queue, size_t *count, uint64_t offset, const sx_context *c, bool big)
{
    size_t i;
    if (!offset) return true;
    if (*count >= 1024 || offset < (big ? 16U : 8U) || offset >= (uint64_t)c->size) return false;
    for (i = 0; i < *count; ++i) if (queue[i] == offset) return false;
    queue[(*count)++] = offset;
    return true;
}
static bool sx_image_tiff(sx_context *c)
{
    uint8_t magic[2];
    uint16_t version, value16;
    uint32_t value32;
    uint64_t queue[1024], first;
    size_t count = 0, index = 0;
    bool be, big;
    const sx_layout *header, *counter, *next_layout, *inline_entry, *offset_entry;
    if (!sx_read(c, 0, magic, 2) || ((magic[0] != 'I' || magic[1] != 'I') && (magic[0] != 'M' || magic[1] != 'M'))) return false;
    be = magic[0] == 'M';
    if (!sx_u16(c, 2, be, &version) || (version != 42 && version != 43)) return false;
    big = version == 43;
    if (big) {
        if (!sx_u16(c, 4, be, &value16) || value16 != 8 || !sx_u16(c, 6, be, &value16) || value16 || !sx_u64(c, 8, be, &first)) return false;
        header = be ? &sxi_bigtiff_header_be : &sxi_bigtiff_header_le;
        counter = be ? &sxi_bigtiff_count_be : &sxi_bigtiff_count_le;
        next_layout = be ? &sxi_bigtiff_next_be : &sxi_bigtiff_next_le;
        inline_entry = be ? &sxi_bigtiff_entry_inline_be : &sxi_bigtiff_entry_inline_le;
        offset_entry = be ? &sxi_bigtiff_entry_offset_be : &sxi_bigtiff_entry_offset_le;
    } else {
        if (!sx_u32(c, 4, be, &value32)) return false;
        first = value32;
        header = be ? &sxi_tiff_header_be : &sxi_tiff_header_le;
        counter = be ? &sxi_tiff_count_be : &sxi_tiff_count_le;
        next_layout = be ? &sxi_tiff_next_be : &sxi_tiff_next_le;
        inline_entry = be ? &sxi_tiff_entry_inline_be : &sxi_tiff_entry_inline_le;
        offset_entry = be ? &sxi_tiff_entry_offset_be : &sxi_tiff_entry_offset_le;
    }
    if (!sx_add(c, header, 0, big ? 16 : 8) || !first || !sx_image_tiff_queue(queue, &count, first, c, big)) return false;
    while (index < count) {
        uint64_t n, i, next;
        unsigned count_size = big ? 8 : 2, entry_size = big ? 20 : 12, next_size = big ? 8 : 4;
        int64_t at = (int64_t)queue[index++], table;
        if (big) { if (!sx_u64(c, at, be, &n)) return false; }
        else { if (!sx_u16(c, at, be, &value16)) return false; n = value16; }
        if (n > 65536 || !sx_image_range(c, at, count_size + n * entry_size + next_size) || !sx_add(c, counter, at, count_size)) return false;
        table = at + count_size;
        for (i = 0; i < n; ++i) {
            int64_t p = table + (int64_t)i * entry_size, data;
            uint16_t tag, type;
            uint64_t elements, bytes, offset;
            unsigned width;
            if (!sx_u16(c, p, be, &tag) || !sx_u16(c, p + 2, be, &type) || !(width = sx_image_tiff_width(type)) || (!big && type >= 16)) return false;
            if (big) { if (!sx_u64(c, p + 4, be, &elements)) return false; }
            else { if (!sx_u32(c, p + 4, be, &value32)) return false; elements = value32; }
            if (elements > (uint64_t)INT64_MAX / width) return false;
            bytes = elements * width;
            data = p + (big ? 12 : 8);
            if (bytes > next_size) {
                if (big) { if (!sx_u64(c, data, be, &offset)) return false; }
                else { if (!sx_u32(c, data, be, &value32)) return false; offset = value32; }
                if (offset > INT64_MAX || !sx_image_range(c, (int64_t)offset, bytes) || !sx_add(c, offset_entry, p, entry_size) || !sx_raw(c, (int64_t)offset, (int64_t)bytes)) return false;
                data = (int64_t)offset;
            } else if (!sx_add(c, inline_entry, p, entry_size)) return false;
            /* TIFF SubIFDs and EXIF/GPS/interoperability directory pointers
             * use the same physical directory syntax. */
            if (tag == 330 || tag == 34665 || tag == 34853 || tag == 40965) {
                uint64_t j;
                if (elements > 1024 || (type != 4 && type != 13 && type != 16 && type != 18)) return false;
                for (j = 0; j < elements; ++j) {
                    int64_t pos = data + (int64_t)j * width;
                    if (width == 8) { if (!sx_u64(c, pos, be, &offset)) return false; }
                    else { if (!sx_u32(c, pos, be, &value32)) return false; offset = value32; }
                    if (!sx_image_tiff_queue(queue, &count, offset, c, big)) return false;
                }
            }
        }
        at = table + (int64_t)n * entry_size;
        if (big) { if (!sx_u64(c, at, be, &next)) return false; }
        else { if (!sx_u32(c, at, be, &value32)) return false; next = value32; }
        if (!sx_add(c, next_layout, at, next_size) || !sx_image_tiff_queue(queue, &count, next, c, big)) return false;
    }
    return true;
}
bool sx_tiff_build(sx_context*c)
{
    return sx_image_tiff(c);
}
