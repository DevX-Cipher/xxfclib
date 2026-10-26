/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#include "xx_xz_data.h"
#include "xx_xz_defs.h"
#include "xx_xz_internal.h"
#include "xxfclib/rt/xx_rt.h"
#include "../../../algo/lzma/xx_lzma_stream_internal.h"
#include "xxfclib/data/xx_data.h"
#include "xxfclib/io/xx_io.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/strings/xx_string.h"

#include <stdint.h>
#include <wchar.h>

typedef struct xx_xz_ds_stream_s {
    xx_data_struct *items;
    size_t count;
} xx_xz_ds_stream;

typedef struct xx_xz_dynamic_member_s {
    xx_data_struct_field_desc field;
    wchar_t name[64];
    bool is_vli;
    uint64_t value;
} xx_xz_dynamic_member;

typedef struct xx_xz_record_stream_s {
    const xx_data_struct_field_desc *fields;
    xx_data_struct_field_desc check;
    size_t count;
    uint32_t variable_kind;
    uint8_t *encoded;
    size_t encoded_size;
    uint64_t index_records;
    size_t index_count_size, index_cursor;
    size_t padding_offset, padding_size;
    xx_xz_dynamic_member members[20];
} xx_xz_record_stream;

typedef struct xx_xz_ds_name_s {
    xx_xz_data_struct_id_t id;
    const char *name;
} xx_xz_ds_name;

static const xx_xz_ds_name g_xx_xz_ds_names[] = {
    {XX_XZ_DS_UNKNOWN, "UNKNOWN"},       {XX_XZ_DS_STREAM_HEADER, "STREAM_HEADER"}, {XX_XZ_DS_BLOCK_HEADER, "BLOCK_HEADER"},
    {XX_XZ_DS_BLOCK_DATA, "BLOCK_DATA"}, {XX_XZ_DS_BLOCK_PADDING, "BLOCK_PADDING"}, {XX_XZ_DS_BLOCK_CHECK, "BLOCK_CHECK"},
    {XX_XZ_DS_INDEX, "INDEX"},           {XX_XZ_DS_STREAM_FOOTER, "STREAM_FOOTER"}, {XX_XZ_DS_STREAM_PADDING, "STREAM_PADDING"}};

const char *xx_xz_data_struct_id_to_string(Abstractformat *self, uint32_t id)
{
    (void)self;
    for (size_t i = 0U; i < sizeof(g_xx_xz_ds_names) / sizeof(g_xx_xz_ds_names[0]); ++i) {
        if ((uint32_t)g_xx_xz_ds_names[i].id == id) return g_xx_xz_ds_names[i].name;
    }
    return "UNKNOWN";
}

uint32_t xx_xz_data_struct_string_to_id(Abstractformat *self, const char *name)
{
    (void)self;
    if (name) {
        for (size_t i = 0U; i < sizeof(g_xx_xz_ds_names) / sizeof(g_xx_xz_ds_names[0]); ++i) {
            if (xx_str_cmp(name, g_xx_xz_ds_names[i].name) == 0) return (uint32_t)g_xx_xz_ds_names[i].id;
        }
    }
    return (uint32_t)XX_XZ_DS_UNKNOWN;
}

static void xx_xz_ds_stream_free(void *pointer)
{
    xx_xz_ds_stream *stream = (xx_xz_ds_stream *)pointer;
    if (!stream) return;
    if (stream->items) xx_mem_free(stream->items);
    xx_mem_free(stream);
}

static void xx_xz_set_ds(xx_data_struct *item, uint32_t id, int64_t offset, int64_t size, xx_data_struct_type_t type, bool is_mapped)
{
    item->id = id;
    item->offset = offset;
    item->address = is_mapped ? offset : -1;
    item->entry_size = size;
    item->total_size = size;
    item->count = 1U;
    item->type = type;
}

xx_data_struct_state *xx_xz_create_data_structs_reading(Abstractformat *self, xx_pd_struct *pd)
{
    xx_xz_private *priv;
    xx_data_struct_state *state;
    xx_xz_ds_stream *stream;
    size_t capacity;
    if (!self || !self->device || (!self->base_info_handled && !xx_format_handle_base_info(self, pd)) || !(priv = (xx_xz_private *)((xx_xz *)self)->internal) ||
        priv->stream_count > (SIZE_MAX - priv->block_count * 4U) / 4U) {
        return NULL;
    }
    capacity = priv->stream_count * 4U + priv->block_count * 4U;
    if (capacity > SIZE_MAX / sizeof(xx_data_struct)) return NULL;
    state = (xx_data_struct_state *)xx_mem_alloc(sizeof(*state));
    stream = (xx_xz_ds_stream *)xx_mem_calloc(1U, sizeof(*stream));
    if (!state || !stream) {
        if (state) xx_mem_free(state);
        if (stream) xx_mem_free(stream);
        return NULL;
    }
    xx_data_struct_state_init(state, self);
    stream->items = (xx_data_struct *)xx_mem_alloc((capacity ? capacity : 1U) * sizeof(*stream->items));
    if (!stream->items) {
        xx_mem_free(stream);
        xx_data_struct_state_free(state);
        return NULL;
    }
    for (size_t s = 0U; s < priv->stream_count; ++s) {
        const xx_xz_stream *xz_stream = &priv->streams[s];
        xx_xz_set_ds(&stream->items[stream->count++], XX_XZ_DS_STREAM_HEADER, xz_stream->header_offset, XX_XZ_STREAM_HEADER_SIZE, XX_DATA_STRUCT_TYPE_STRUCT,
                     self->is_mapped);
        for (size_t b = 0U; b < xz_stream->block_count; ++b) {
            const xx_xz_block *block = &priv->blocks[xz_stream->first_block + b];
            xx_xz_set_ds(&stream->items[stream->count++], XX_XZ_DS_BLOCK_HEADER, block->header_offset, block->header_size, XX_DATA_STRUCT_TYPE_STRUCT, self->is_mapped);
            if (block->compressed_size != 0) {
                xx_xz_set_ds(&stream->items[stream->count++], XX_XZ_DS_BLOCK_DATA, block->data_offset, block->compressed_size, XX_DATA_STRUCT_TYPE_RAW_DATA,
                             self->is_mapped);
            }
            if (block->padding_size != 0) {
                xx_xz_set_ds(&stream->items[stream->count++], XX_XZ_DS_BLOCK_PADDING, block->padding_offset, block->padding_size, XX_DATA_STRUCT_TYPE_RAW_DATA,
                             self->is_mapped);
            }
            if (block->check_size != 0) {
                xx_xz_set_ds(&stream->items[stream->count++], XX_XZ_DS_BLOCK_CHECK, block->check_offset, block->check_size, XX_DATA_STRUCT_TYPE_STRUCT, self->is_mapped);
            }
        }
        xx_xz_set_ds(&stream->items[stream->count++], XX_XZ_DS_INDEX, xz_stream->index_offset, xz_stream->index_size, XX_DATA_STRUCT_TYPE_STRUCT, self->is_mapped);
        xx_xz_set_ds(&stream->items[stream->count++], XX_XZ_DS_STREAM_FOOTER, xz_stream->footer_offset, XX_XZ_STREAM_FOOTER_SIZE, XX_DATA_STRUCT_TYPE_FOOTER,
                     self->is_mapped);
        if (xz_stream->padding_size != 0) {
            xx_xz_set_ds(&stream->items[stream->count++], XX_XZ_DS_STREAM_PADDING, xz_stream->padding_offset, xz_stream->padding_size, XX_DATA_STRUCT_TYPE_RAW_DATA,
                         self->is_mapped);
        }
    }
    state->internal_state = stream;
    state->free_internal = xx_xz_ds_stream_free;
    state->total_structs = (int64_t)stream->count;
    state->current_index = 0;
    state->has_struct = stream->count != 0U;
    if (state->has_struct) state->current_struct = stream->items[0];
    return state;
}

const xx_data_struct *xx_xz_get_current_data_struct(Abstractformat *self, xx_data_struct_state *state)
{
    return self && state && state->format == self && state->has_struct ? &state->current_struct : NULL;
}

bool xx_xz_data_struct_move_to_next(Abstractformat *self, xx_data_struct_state *state, xx_pd_struct *pd)
{
    xx_xz_ds_stream *stream;
    int64_t next;
    if (!self || !state || state->format != self || !state->has_struct || !state->internal_state || (pd && xx_pd_is_stopped(pd))) return false;
    stream = (xx_xz_ds_stream *)state->internal_state;
    next = state->current_index + 1;
    if (next < 0 || (size_t)next >= stream->count) {
        state->has_struct = false;
        return false;
    }
    state->current_index = next;
    state->current_struct = stream->items[next];
    return true;
}

void xx_xz_free_data_structs_reading(Abstractformat *self, xx_data_struct_state *state)
{
    (void)self;
    xx_data_struct_state_free(state);
}

static const xx_data_struct_field_desc g_xz_stream_header_fields[] = {{L"magic", L"uint8[6]", 0, 6, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                      {L"stream_flags", L"uint16", 6, 2, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS},
                                                                      {L"header_crc32", L"uint32", 8, 4, XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM}};

static const xx_data_struct_field_desc g_xz_footer_fields[] = {{L"footer_crc32", L"uint32", 0, 4, XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM},
                                                               {L"backward_size", L"uint32", 4, 4, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},
                                                               {L"stream_flags", L"uint16", 8, 2, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS},
                                                               {L"magic", L"uint16", 10, 2, XX_DATA_STRUCT_RECORD_PROPERTY_ID}};

static void xx_xz_record_stream_free(void *pointer)
{
    xx_xz_record_stream *stream = (xx_xz_record_stream *)pointer;
    if (!stream) return;
    xx_mem_free(stream->encoded);
    xx_mem_free(stream);
}

static void xx_xz_member_name(wchar_t name[64], const char *prefix, uint64_t index, const char *member)
{
    char ascii[64];
    size_t i;
    xx_rt_snprintf(ascii, sizeof(ascii), "%s[%llu].%s", prefix, (unsigned long long)index, member);
    for (i = 0; i < sizeof(ascii); ++i) {
        name[i] = (wchar_t)(unsigned char)ascii[i];
        if (!ascii[i]) break;
    }
    name[63] = L'\0';
}

static bool xx_xz_member_add(xx_xz_record_stream *stream, const wchar_t *name, const wchar_t *type, size_t offset, size_t size,
                             xx_data_struct_record_property_t property, bool vli, uint64_t value)
{
    xx_xz_dynamic_member *member;
    if (!stream || stream->count >= sizeof(stream->members) / sizeof(stream->members[0]) || !name || !type || !size ||
        offset > stream->encoded_size || size > stream->encoded_size - offset) return false;
    member = &stream->members[stream->count++];
    xx_mem_zero(member, sizeof(*member));
    for (size_t i = 0; i < sizeof(member->name) / sizeof(member->name[0]) - 1 && name[i]; ++i) member->name[i] = name[i];
    member->field.name = member->name;
    member->field.type = type;
    member->field.rel_offset = (int64_t)offset;
    member->field.size = (int64_t)size;
    member->field.property = property;
    member->is_vli = vli;
    member->value = value;
    return true;
}

static bool xx_xz_member_vli(xx_xz_record_stream *stream, size_t limit, size_t *cursor, const wchar_t *name,
                             xx_data_struct_record_property_t property, uint64_t *value)
{
    size_t begin = *cursor;
    uint64_t decoded;
    if (!xx_xz_vli(stream->encoded, limit, cursor, &decoded) ||
        !xx_xz_member_add(stream, name, L"vli", begin, *cursor - begin, property, true, decoded)) return false;
    if (value) *value = decoded;
    return true;
}

static bool xx_xz_prepare_variable_members(Abstractformat *self, const xx_data_struct *ds, xx_xz_record_stream *stream, xx_pd_struct *pd)
{
    size_t limit, cursor;
    uint32_t crc;
    if (ds->id == XX_XZ_DS_INDEX) {
        if (ds->total_size < 8 || ds->total_size > XX_XZ_MAX_INDEX_SIZE || (ds->total_size & 3) != 0) return false;
    } else if (ds->total_size < 8 || ds->total_size > 1024 || (ds->total_size & 3) != 0) return false;
    if ((uint64_t)ds->total_size > SIZE_MAX) return false;
    stream->encoded_size = (size_t)ds->total_size;
    stream->encoded = (uint8_t *)xx_mem_alloc(stream->encoded_size);
    if (!stream->encoded || !xx_lzma_stream_read_exact_at(self->device, ds->offset, stream->encoded, stream->encoded_size, pd)) return false;
    limit = stream->encoded_size - 4U;
    if (!xx_xz_crc32_cancellable(stream->encoded, limit, pd, &crc) ||
        xx_data_get_u32(stream->encoded, stream->encoded_size, limit, false) != crc) return false;
    if (ds->id == XX_XZ_DS_INDEX) {
        uint64_t count, value;
        if (stream->encoded[0] != 0) return false;
        cursor = 1;
        if (!xx_xz_vli(stream->encoded, limit, &cursor, &count) || count > XX_XZ_MAX_BLOCKS || count > (SIZE_MAX - 4U) / 2U) return false;
        stream->index_records = count;
        stream->index_count_size = cursor - 1U;
        for (uint64_t i = 0; i < count; ++i) {
            if (xx_pd_is_stopped(pd) || !xx_xz_vli(stream->encoded, limit, &cursor, &value) || value == 0 ||
                !xx_xz_vli(stream->encoded, limit, &cursor, &value)) return false;
        }
        stream->padding_offset = cursor;
        stream->padding_size = (4U - (cursor & 3U)) & 3U;
        if (cursor + stream->padding_size != limit) return false;
        while (cursor < limit) if (stream->encoded[cursor++] != 0) return false;
        /* Retain only the encoded Index and a cursor, rather than allocating
         * two large field/name objects for every block in a million-block
         * archive. Values are decoded lazily in physical record order. */
        stream->count = 3U + (size_t)count * 2U + (stream->padding_size != 0U ? 1U : 0U);
        stream->index_cursor = 1U + stream->index_count_size;
        stream->variable_kind = XX_XZ_DS_INDEX;
        return true;
    }
    if (stream->encoded[0] == 0 || ((size_t)stream->encoded[0] + 1U) * 4U != stream->encoded_size || (stream->encoded[1] & 0x3cU)) return false;
    if (!xx_xz_member_add(stream, L"header_size", L"uint8", 0, 1, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE, false, 0) ||
        !xx_xz_member_add(stream, L"block_flags", L"uint8", 1, 1, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS, false, 0)) return false;
    cursor = 2U;
    if ((stream->encoded[1] & 0x40U) && !xx_xz_member_vli(stream, limit, &cursor, L"compressed_size", XX_DATA_STRUCT_RECORD_PROPERTY_SIZE, NULL)) return false;
    if ((stream->encoded[1] & 0x80U) && !xx_xz_member_vli(stream, limit, &cursor, L"uncompressed_size", XX_DATA_STRUCT_RECORD_PROPERTY_SIZE, NULL)) return false;
    for (unsigned i = 0; i <= (stream->encoded[1] & 3U); ++i) {
        uint64_t properties;
        wchar_t name[64];
        if (xx_pd_is_stopped(pd)) return false;
        xx_xz_member_name(name, "filters", i, "id");
        if (!xx_xz_member_vli(stream, limit, &cursor, name, XX_DATA_STRUCT_RECORD_PROPERTY_ID, NULL)) return false;
        xx_xz_member_name(name, "filters", i, "properties_size");
        if (!xx_xz_member_vli(stream, limit, &cursor, name, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE, &properties) ||
            properties > XX_XZ_MAX_FILTER_PROPERTIES || properties > limit - cursor) return false;
        if (properties) {
            xx_xz_member_name(name, "filters", i, "properties");
            if (!xx_xz_member_add(stream, name, L"uint8[]", cursor, (size_t)properties, XX_DATA_STRUCT_RECORD_PROPERTY_NONE, false, 0)) return false;
            cursor += (size_t)properties;
        }
    }
    if (cursor < limit && !xx_xz_member_add(stream, L"header_padding", L"uint8[]", cursor, limit - cursor,
                                           XX_DATA_STRUCT_RECORD_PROPERTY_RESERVED, false, 0)) return false;
    while (cursor < limit) if (stream->encoded[cursor++] != 0) return false;
    if (!xx_xz_member_add(stream, L"header_crc32", L"uint32", limit, 4, XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM, false, 0)) return false;
    stream->variable_kind = XX_XZ_DS_BLOCK_HEADER;
    return true;
}

static bool xx_xz_populate_vli(Abstractformat *self, const xx_data_struct *parent, const xx_data_struct_field_desc *field, uint64_t value,
                               xx_data_struct_record *record)
{
    char ascii[96];
    wchar_t wide[96];
    size_t i;
    xx_data_struct_record_init(record);
    record->offset = field->rel_offset;
    record->size = field->size;
    record->property = field->property;
    xx_var_set_u64(&record->value, value);
    if (field->property & XX_DATA_STRUCT_RECORD_PROPERTY_ID) xx_rt_snprintf(ascii, sizeof(ascii), "0x%llX", (unsigned long long)value);
    else xx_rt_snprintf(ascii, sizeof(ascii), "%llu", (unsigned long long)value);
    for (i = 0; i < sizeof(ascii); ++i) { wide[i] = (wchar_t)(unsigned char)ascii[i]; if (!ascii[i]) break; }
    if (!xx_data_struct_record_set_name(record, field->name) || !xx_data_struct_record_set_type(record, L"vli") ||
        !xx_data_struct_record_set_raw_bytes(record, self->device, parent->offset + field->rel_offset, field->size) ||
        !xx_data_struct_record_set_display_value(record, wide)) goto fail;
    if (field->property & XX_DATA_STRUCT_RECORD_PROPERTY_SIZE) {
        if (!xx_str_bytes_count_to_string(value, 1024U, ascii, sizeof(ascii))) goto fail;
        for (i = 0; i < sizeof(ascii); ++i) { wide[i] = (wchar_t)(unsigned char)ascii[i]; if (!ascii[i]) break; }
        if (!xx_data_struct_record_set_comment(record, wide)) goto fail;
    } else if (field->property & XX_DATA_STRUCT_RECORD_PROPERTY_ID) {
        const wchar_t *symbol = NULL;
        switch (value) {
            case 0x03: symbol = L"LZMA_FILTER_DELTA"; break;
            case 0x04: symbol = L"LZMA_FILTER_X86"; break;
            case 0x05: symbol = L"LZMA_FILTER_POWERPC"; break;
            case 0x06: symbol = L"LZMA_FILTER_IA64"; break;
            case 0x07: symbol = L"LZMA_FILTER_ARM"; break;
            case 0x08: symbol = L"LZMA_FILTER_ARMTHUMB"; break;
            case 0x09: symbol = L"LZMA_FILTER_SPARC"; break;
            case 0x0a: symbol = L"LZMA_FILTER_ARM64"; break;
            case 0x0b: symbol = L"LZMA_FILTER_RISCV"; break;
            case 0x21: symbol = L"LZMA_FILTER_LZMA2"; break;
        }
        if (symbol && !xx_data_struct_record_set_comment(record, symbol)) goto fail;
    }
    return true;
fail:
    xx_data_struct_record_cleanup(record);
    return false;
}

static bool xx_xz_load_member(Abstractformat *self, const xx_data_struct *parent, xx_xz_record_stream *stream, size_t index,
                              xx_data_struct_record *record)
{
    xx_data_struct_field_desc field;
    uint64_t value = 0;
    bool vli = false;
    wchar_t name[64];
    if (!stream || index >= stream->count) return false;
    if (stream->variable_kind == XX_XZ_DS_BLOCK_HEADER) {
        field = stream->members[index].field;
        vli = stream->members[index].is_vli;
        value = stream->members[index].value;
    } else if (stream->variable_kind == XX_XZ_DS_INDEX) {
        size_t pairs_end = 2U + (size_t)stream->index_records * 2U;
        xx_mem_zero(&field, sizeof(field));
        if (index == 0) {
            field.name = L"indicator"; field.type = L"uint8"; field.size = 1; field.property = XX_DATA_STRUCT_RECORD_PROPERTY_ID;
        } else if (index == 1) {
            field.name = L"record_count"; field.type = L"vli"; field.rel_offset = 1; field.size = (int64_t)stream->index_count_size;
            field.property = XX_DATA_STRUCT_RECORD_PROPERTY_COUNT;
            vli = true; value = stream->index_records;
        } else if (index < pairs_end) {
            size_t begin = stream->index_cursor;
            if (!xx_xz_vli(stream->encoded, stream->encoded_size - 4U, &stream->index_cursor, &value)) return false;
            xx_xz_member_name(name, "records", (index - 2U) / 2U, (index & 1U) ? "uncompressed_size" : "unpadded_size");
            field.name = name; field.type = L"vli"; field.rel_offset = (int64_t)begin; field.size = (int64_t)(stream->index_cursor - begin);
            field.property = XX_DATA_STRUCT_RECORD_PROPERTY_SIZE; vli = true;
        } else if (stream->padding_size && index == pairs_end) {
            field.name = L"index_padding"; field.type = L"uint8[]"; field.rel_offset = (int64_t)stream->padding_offset;
            field.size = (int64_t)stream->padding_size; field.property = XX_DATA_STRUCT_RECORD_PROPERTY_RESERVED;
        } else {
            field.name = L"index_crc32"; field.type = L"uint32"; field.rel_offset = (int64_t)stream->encoded_size - 4;
            field.size = 4; field.property = XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM;
        }
    } else field = stream->fields[index];
    if (field.rel_offset < 0 || field.size <= 0 || field.rel_offset > parent->total_size || field.size > parent->total_size - field.rel_offset) return false;
    if (vli) return xx_xz_populate_vli(self, parent, &field, value, record);
    if (!xx_data_struct_record_populate(record, self->device, parent->offset, &field, false)) return false;
    {
        char ascii[160];
        wchar_t wide[160];
        bool have_comment = false;
        value = xx_var_get_u64(&record->value);
        if ((parent->id == XX_XZ_DS_BLOCK_HEADER && xx_rt_wcscmp(field.name, L"header_size") == 0) ||
            (parent->id == XX_XZ_DS_STREAM_FOOTER && xx_rt_wcscmp(field.name, L"backward_size") == 0)) {
            char size_text[96];
            if (!xx_str_bytes_count_to_string((value + 1U) * 4U, 1024U, size_text, sizeof(size_text))) goto fail;
            xx_rt_snprintf(ascii, sizeof(ascii), "%s: %s", parent->id == XX_XZ_DS_BLOCK_HEADER ? "Header size" : "Index size", size_text);
            have_comment = true;
        } else if (parent->id == XX_XZ_DS_BLOCK_HEADER && xx_rt_wcscmp(field.name, L"block_flags") == 0) {
            xx_rt_snprintf(ascii, sizeof(ascii), "FilterCount=%u%s%s", (unsigned)(value & 3U) + 1U,
                           value & 0x40U ? "|CompressedSizePresent" : "", value & 0x80U ? "|UncompressedSizePresent" : "");
            have_comment = true;
        } else if (xx_rt_wcscmp(field.name, L"stream_flags") == 0) {
            const char *check = NULL;
            switch ((value >> 8) & 15U) {
                case 0: check = "LZMA_CHECK_NONE"; break;
                case 1: check = "LZMA_CHECK_CRC32"; break;
                case 4: check = "LZMA_CHECK_CRC64"; break;
                case 10: check = "LZMA_CHECK_SHA256"; break;
            }
            if (check) {
                xx_rt_snprintf(ascii, sizeof(ascii), "%s", check);
                have_comment = true;
            }
        }
        if (have_comment) {
            for (size_t i = 0; i < sizeof(ascii); ++i) { wide[i] = (wchar_t)(unsigned char)ascii[i]; if (!ascii[i]) break; }
            if (!xx_data_struct_record_set_comment(record, wide)) goto fail;
        }
    }
    return true;
fail:
    xx_data_struct_record_cleanup(record);
    return false;
}

xx_data_struct_record_state *xx_xz_create_data_struct_records_reading(Abstractformat *self, const xx_data_struct *ds, xx_pd_struct *pd)
{
    xx_data_struct_record_state *state;
    xx_xz_record_stream *stream;
    const xx_data_struct_field_desc *fields = NULL;
    size_t count = 0;
    if (!self || !self->device || !ds || xx_pd_is_stopped(pd) || ds->offset < 0 || ds->total_size <= 0 ||
        !xx_io_check(self->device, ds->offset, ds->total_size)) return NULL;
    if (ds->id == XX_XZ_DS_STREAM_HEADER) {
        fields = g_xz_stream_header_fields; count = sizeof(g_xz_stream_header_fields) / sizeof(g_xz_stream_header_fields[0]);
    } else if (ds->id == XX_XZ_DS_STREAM_FOOTER) {
        fields = g_xz_footer_fields; count = sizeof(g_xz_footer_fields) / sizeof(g_xz_footer_fields[0]);
    } else if (ds->id == XX_XZ_DS_BLOCK_CHECK) count = 1;
    else if (ds->id != XX_XZ_DS_BLOCK_HEADER && ds->id != XX_XZ_DS_INDEX) return NULL;
    for (size_t i = 0; fields && i < count; ++i) {
        if (fields[i].rel_offset > ds->total_size || fields[i].size > ds->total_size - fields[i].rel_offset) return NULL;
    }
    state = (xx_data_struct_record_state *)xx_mem_alloc(sizeof(*state));
    stream = (xx_xz_record_stream *)xx_mem_alloc(sizeof(*stream));
    if (!state || !stream) { xx_mem_free(state); xx_mem_free(stream); return NULL; }
    xx_data_struct_record_state_init(state, self, ds);
    xx_mem_zero(stream, sizeof(*stream));
    stream->fields = fields; stream->count = count;
    state->internal_state = stream; state->free_internal = xx_xz_record_stream_free;
    if (ds->id == XX_XZ_DS_INDEX || ds->id == XX_XZ_DS_BLOCK_HEADER) {
        if (!xx_xz_prepare_variable_members(self, ds, stream, pd)) { xx_data_struct_record_state_free(state); return NULL; }
    } else if (ds->id == XX_XZ_DS_BLOCK_CHECK) {
        stream->check.name = L"check"; stream->check.type = L"uint8[]";
        stream->check.size = ds->total_size; stream->check.property = XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM;
        stream->fields = &stream->check;
    }
    state->total_records = (int64_t)stream->count;
    if (!xx_xz_load_member(self, ds, stream, 0, &state->current_record)) { xx_data_struct_record_state_free(state); return NULL; }
    state->has_record = true; state->current_index = 0;
    return state;
}

const xx_data_struct_record *xx_xz_get_current_data_struct_record(Abstractformat *self, xx_data_struct_record_state *state)
{
    return self && state && state->format == self && state->has_record ? &state->current_record : NULL;
}

bool xx_xz_data_struct_record_move_to_next(Abstractformat *self, xx_data_struct_record_state *state, xx_pd_struct *pd)
{
    xx_xz_record_stream *stream;
    int64_t next;
    if (!self || !state || state->format != self || !state->has_record || !state->internal_state || xx_pd_is_stopped(pd)) return false;
    stream = (xx_xz_record_stream *)state->internal_state;
    next = state->current_index + 1;
    if (next < 0 || (uint64_t)next >= stream->count) { state->has_record = false; return false; }
    xx_data_struct_record_cleanup(&state->current_record);
    if (!xx_xz_load_member(self, &state->parent_struct, stream, (size_t)next, &state->current_record)) { state->has_record = false; return false; }
    state->current_index = next;
    return true;
}

void xx_xz_free_data_struct_records_reading(Abstractformat *self, xx_data_struct_record_state *state)
{
    (void)self;
    xx_data_struct_record_state_free(state);
}

void xx_xz_setup_data_struct_callbacks(xx_xz *xz)
{
    if (!xz) return;
    xz->format.data_struct_id_to_string = xx_xz_data_struct_id_to_string;
    xz->format.data_struct_string_to_id = xx_xz_data_struct_string_to_id;
    xz->format.create_data_structs_reading = xx_xz_create_data_structs_reading;
    xz->format.get_current_data_struct = xx_xz_get_current_data_struct;
    xz->format.data_struct_move_to_next = xx_xz_data_struct_move_to_next;
    xz->format.free_data_structs_reading = xx_xz_free_data_structs_reading;
    xz->format.create_data_struct_records_reading = xx_xz_create_data_struct_records_reading;
    xz->format.get_current_data_struct_record = xx_xz_get_current_data_struct_record;
    xz->format.data_struct_record_move_to_next = xx_xz_data_struct_record_move_to_next;
    xz->format.free_data_struct_records_reading = xx_xz_free_data_struct_records_reading;
}
