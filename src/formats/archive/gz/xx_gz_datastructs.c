/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#include "xxfclib/formats/xx_format_streams.h"
#include "xx_gz_datastructs_internal.h"

typedef struct xx_gz_ds_stream_s {
    xx_data_struct *items;
    size_t count;
} xx_gz_ds_stream;

typedef struct xx_gz_record_stream_s {
    const xx_data_struct_field_desc *fields;
    xx_data_struct_field_desc dynamic_fields[4];
    size_t count;
} xx_gz_record_stream;

typedef struct xx_gz_ds_name_s {
    xx_gz_data_struct_id_t id;
    const char *name;
} xx_gz_ds_name;

static const xx_gz_ds_name g_xx_gz_ds_names[] = {
    {XX_GZ_DS_UNKNOWN, "UNKNOWN"}, {XX_GZ_DS_MEMBER_HEADER, "MEMBER_HEADER"}, {XX_GZ_DS_EXTRA_FIELD, "EXTRA_FIELD"},         {XX_GZ_DS_ORIGINAL_NAME, "ORIGINAL_NAME"},
    {XX_GZ_DS_COMMENT, "COMMENT"}, {XX_GZ_DS_HEADER_CRC16, "HEADER_CRC16"},   {XX_GZ_DS_COMPRESSED_DATA, "COMPRESSED_DATA"}, {XX_GZ_DS_TRAILER, "TRAILER"}, {XX_GZ_DS_EXTRA_SUBFIELD, "EXTRA_SUBFIELD"}};

const char *xx_gz_data_struct_id_to_string(Abstractformat *self, uint32_t id)
{
    (void)self;
    for (size_t i = 0; i < sizeof(g_xx_gz_ds_names) / sizeof(g_xx_gz_ds_names[0]); ++i) {
        if ((uint32_t)g_xx_gz_ds_names[i].id == id) return g_xx_gz_ds_names[i].name;
    }
    return "UNKNOWN";
}

uint32_t xx_gz_data_struct_string_to_id(Abstractformat *self, const char *name)
{
    (void)self;
    if (name) {
        for (size_t i = 0; i < sizeof(g_xx_gz_ds_names) / sizeof(g_xx_gz_ds_names[0]); ++i) {
            if (xx_str_cmp(name, g_xx_gz_ds_names[i].name) == 0) return (uint32_t)g_xx_gz_ds_names[i].id;
        }
    }
    return XX_GZ_DS_UNKNOWN;
}

static void xx_gz_ds_stream_free(void *pointer)
{
    xx_gz_ds_stream *stream = (xx_gz_ds_stream *)pointer;
    if (!stream) return;
    if (stream->items) xx_mem_free(stream->items);
    xx_mem_free(stream);
}

static void xx_gz_set_ds(xx_data_struct *item, uint32_t id, int64_t offset, int64_t size, xx_data_struct_type_t type, bool is_mapped)
{
    item->id = id;
    item->offset = offset;
    item->address = is_mapped ? offset : -1;
    item->entry_size = size;
    item->total_size = size;
    item->count = 1U;
    item->type = type;
}

xx_data_struct_state *xx_gz_create_data_structs_reading(Abstractformat *self, xx_pd_struct *pd)
{
    xx_gz_private *priv;
    xx_data_struct_state *state;
    xx_gz_ds_stream *stream;
    size_t capacity;
    if (!self || !self->device || (!self->base_info_handled && !xx_format_handle_base_info(self, pd)) || !(priv = (xx_gz_private *)((xx_gz *)self)->internal) ||
        priv->count > SIZE_MAX / 7U) {
        return NULL;
    }
    capacity = priv->count * 7U;
    /* At most one descriptor per four-byte subfield plus a raw malformed tail. */
    for (size_t i = 0; i < priv->count; ++i) {
        uint64_t extra = priv->members[i].extra_size > 2 ? (uint64_t)(priv->members[i].extra_size - 2) / 4U + 1U : 0U;
        if (extra > SIZE_MAX - capacity) return NULL;
        capacity += (size_t)extra;
    }
    if (capacity > SIZE_MAX / sizeof(xx_data_struct)) return NULL;
    state = (xx_data_struct_state *)xx_mem_alloc(sizeof(*state));
    stream = (xx_gz_ds_stream *)xx_mem_calloc(1U, sizeof(*stream));
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
    for (size_t i = 0; i < priv->count; ++i) {
        const xx_gz_member *m = &priv->members[i];
        if (xx_pd_is_stopped(pd)) {
            xx_gz_ds_stream_free(stream);
            xx_data_struct_state_free(state);
            return NULL;
        }
        xx_gz_set_ds(&stream->items[stream->count++], XX_GZ_DS_MEMBER_HEADER, m->header_offset, XX_GZ_HEADER_SIZE, XX_DATA_STRUCT_TYPE_STRUCT, self->is_mapped);
        if (m->extra_offset >= 0) {
            xx_gz_set_ds(&stream->items[stream->count++], XX_GZ_DS_EXTRA_FIELD, m->extra_offset, m->extra_size, XX_DATA_STRUCT_TYPE_STRUCT, self->is_mapped);
            int64_t cursor = m->extra_offset + 2, end = m->extra_offset + m->extra_size;
            while (cursor < end) {
                uint8_t subfield[4];
                int64_t size = 0;
                if (xx_pd_is_stopped(pd) || (end - cursor >= 4 && !xx_io_read_at(self->device, cursor, subfield, sizeof(subfield)))) {
                    xx_gz_ds_stream_free(stream);
                    xx_data_struct_state_free(state);
                    return NULL;
                }
                if (end - cursor >= 4) size = 4 + xx_data_get_u16(subfield, sizeof(subfield), 2, false);
                if (size < 4 || size > end - cursor) {
                    xx_gz_set_ds(&stream->items[stream->count++], XX_DATA_STRUCT_ID_RAW_DATA, cursor, end - cursor,
                                 XX_DATA_STRUCT_TYPE_RAW_DATA, self->is_mapped);
                    break;
                }
                xx_gz_set_ds(&stream->items[stream->count++], XX_GZ_DS_EXTRA_SUBFIELD, cursor, size,
                             XX_DATA_STRUCT_TYPE_STRUCT, self->is_mapped);
                cursor += size;
            }
        }
        if (m->name_offset >= 0) {
            xx_gz_set_ds(&stream->items[stream->count++], XX_GZ_DS_ORIGINAL_NAME, m->name_offset, m->name_size, XX_DATA_STRUCT_TYPE_STRUCT, self->is_mapped);
        }
        if (m->comment_offset >= 0) {
            xx_gz_set_ds(&stream->items[stream->count++], XX_GZ_DS_COMMENT, m->comment_offset, m->comment_size, XX_DATA_STRUCT_TYPE_STRUCT, self->is_mapped);
        }
        if (m->header_crc_offset >= 0) {
            xx_gz_set_ds(&stream->items[stream->count++], XX_GZ_DS_HEADER_CRC16, m->header_crc_offset, 2, XX_DATA_STRUCT_TYPE_STRUCT, self->is_mapped);
        }
        xx_gz_set_ds(&stream->items[stream->count++], XX_GZ_DS_COMPRESSED_DATA, m->data_offset, m->compressed_size, XX_DATA_STRUCT_TYPE_RAW_DATA, self->is_mapped);
        xx_gz_set_ds(&stream->items[stream->count++], XX_GZ_DS_TRAILER, m->trailer_offset, XX_GZ_TRAILER_SIZE, XX_DATA_STRUCT_TYPE_FOOTER, self->is_mapped);
    }
    state->internal_state = stream;
    state->free_internal = xx_gz_ds_stream_free;
    state->total_structs = (int64_t)stream->count;
    state->current_index = 0;
    state->has_struct = stream->count != 0U;
    if (state->has_struct) state->current_struct = stream->items[0];
    return state;
}

const xx_data_struct *xx_gz_get_current_data_struct(Abstractformat *self, xx_data_struct_state *state)
{
    return self && state && state->format == self && state->has_struct ? &state->current_struct : NULL;
}

bool xx_gz_data_struct_move_to_next(Abstractformat *self, xx_data_struct_state *state, xx_pd_struct *pd)
{
    xx_gz_ds_stream *stream;
    int64_t next;
    if (!self || !state || state->format != self || !state->has_struct || !state->internal_state || (pd && xx_pd_is_stopped(pd))) {
        return false;
    }
    stream = (xx_gz_ds_stream *)state->internal_state;
    next = state->current_index + 1;
    if (next < 0 || (size_t)next >= stream->count) {
        state->has_struct = false;
        return false;
    }
    state->current_index = next;
    state->current_struct = stream->items[next];
    return true;
}

void xx_gz_free_data_structs_reading(Abstractformat *self, xx_data_struct_state *state)
{
    (void)self;
    xx_data_struct_state_free(state);
}

static const xx_data_struct_field_desc g_xx_gz_header_fields[] = {{L"id1", L"uint8", 0, 1, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                  {L"id2", L"uint8", 1, 1, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                  {L"compression_method", L"uint8", 2, 1, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},
                                                                  {L"flags", L"uint8", 3, 1, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS},
                                                                  {L"modification_time", L"uint32", 4, 4, XX_DATA_STRUCT_RECORD_PROPERTY_TIMESTAMP},
                                                                  {L"extra_flags", L"uint8", 8, 1, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS},
                                                                  {L"operating_system", L"uint8", 9, 1, XX_DATA_STRUCT_RECORD_PROPERTY_NONE}};

static const xx_data_struct_field_desc g_xx_gz_trailer_fields[] = {{L"crc32", L"uint32", 0, 4, XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM},
                                                                   {L"input_size", L"uint32", 4, 4, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE}};

static const xx_data_struct_field_desc g_xx_gz_hcrc_fields[] = {{L"header_crc16", L"uint16", 0, 2, XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM}};

static void xx_gz_record_stream_free(void *pointer)
{
    if (pointer) xx_mem_free(pointer);
}

xx_data_struct_record_state *xx_gz_create_data_struct_records_reading(Abstractformat *self, const xx_data_struct *ds, xx_pd_struct *pd)
{
    xx_data_struct_record_state *state;
    xx_gz_record_stream *stream;
    const xx_data_struct_field_desc *fields = NULL;
    xx_data_struct_field_desc dynamic[4];
    size_t count = 0;
    int64_t minimum = 0;
    if (!self || !self->device || !ds || xx_pd_is_stopped(pd) || ds->offset < 0 || ds->total_size < 0 ||
        !xx_io_check(self->device, ds->offset, ds->total_size)) return NULL;
    if (ds->id == XX_GZ_DS_MEMBER_HEADER) {
        fields = g_xx_gz_header_fields;
        count = sizeof(g_xx_gz_header_fields) / sizeof(g_xx_gz_header_fields[0]);
    } else if (ds->id == XX_GZ_DS_TRAILER) {
        fields = g_xx_gz_trailer_fields;
        count = sizeof(g_xx_gz_trailer_fields) / sizeof(g_xx_gz_trailer_fields[0]);
    } else if (ds->id == XX_GZ_DS_HEADER_CRC16) {
        fields = g_xx_gz_hcrc_fields;
        count = sizeof(g_xx_gz_hcrc_fields) / sizeof(g_xx_gz_hcrc_fields[0]);
    } else if (ds->id == XX_GZ_DS_EXTRA_FIELD || ds->id == XX_GZ_DS_EXTRA_SUBFIELD) {
        uint8_t header[4];
        minimum = ds->id == XX_GZ_DS_EXTRA_FIELD ? 2 : 4;
        if (ds->total_size < minimum || !xx_io_read_at(self->device, ds->offset, header, (size_t)minimum)) return NULL;
        uint16_t size = xx_data_get_u16(header, (size_t)minimum, minimum - 2, false);
        if (size != ds->total_size - minimum) return NULL;
        if (minimum == 4) {
            dynamic[count++] = (xx_data_struct_field_desc){L"si1", L"uint8", 0, 1, XX_DATA_STRUCT_RECORD_PROPERTY_ID};
            dynamic[count++] = (xx_data_struct_field_desc){L"si2", L"uint8", 1, 1, XX_DATA_STRUCT_RECORD_PROPERTY_ID};
        }
        dynamic[count++] = (xx_data_struct_field_desc){minimum == 2 ? L"xlen" : L"len", L"uint16", minimum - 2, 2, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE};
        if (size) dynamic[count++] = (xx_data_struct_field_desc){L"data", L"bytes", minimum, size, XX_DATA_STRUCT_RECORD_PROPERTY_NONE};
    } else if (ds->id == XX_GZ_DS_ORIGINAL_NAME || ds->id == XX_GZ_DS_COMMENT) {
        uint8_t last;
        if (!ds->total_size || !xx_io_read_at(self->device, ds->offset + ds->total_size - 1, &last, 1) || last) return NULL;
        dynamic[count++] = (xx_data_struct_field_desc){ds->id == XX_GZ_DS_ORIGINAL_NAME ? L"original_name" : L"comment",
                                                   L"char[]", 0, ds->total_size, XX_DATA_STRUCT_RECORD_PROPERTY_STRING};
    } else {
        return NULL;
    }
    if (fields) {
        for (size_t i = 0; i < count; ++i) {
            if (fields[i].rel_offset < 0 || fields[i].size <= 0 || fields[i].rel_offset > ds->total_size ||
                fields[i].size > ds->total_size - fields[i].rel_offset) return NULL;
        }
    }
    state = (xx_data_struct_record_state *)xx_mem_alloc(sizeof(*state));
    stream = (xx_gz_record_stream *)xx_mem_alloc(sizeof(*stream));
    if (!state || !stream) {
        if (state) xx_mem_free(state);
        if (stream) xx_mem_free(stream);
        return NULL;
    }
    xx_data_struct_record_state_init(state, self, ds);
    if (!fields) {
        for (size_t i = 0; i < count; ++i) stream->dynamic_fields[i] = dynamic[i];
        fields = stream->dynamic_fields;
    }
    stream->fields = fields;
    stream->count = count;
    state->internal_state = stream;
    state->free_internal = xx_gz_record_stream_free;
    state->total_records = (int64_t)count;
    if (!count || !xx_data_struct_record_populate(&state->current_record, self->device, ds->offset, &fields[0], false)) {
        xx_data_struct_record_state_free(state);
        return NULL;
    }
    state->has_record = true;
    state->current_index = 0;
    return state;
}

const xx_data_struct_record *xx_gz_get_current_data_struct_record(Abstractformat *self, xx_data_struct_record_state *state)
{
    return self && state && state->format == self && state->has_record ? &state->current_record : NULL;
}

bool xx_gz_data_struct_record_move_to_next(Abstractformat *self, xx_data_struct_record_state *state, xx_pd_struct *pd)
{
    xx_gz_record_stream *stream;
    int64_t next;
    if (!self || !state || state->format != self || !state->has_record || !state->internal_state || (pd && xx_pd_is_stopped(pd))) {
        return false;
    }
    stream = (xx_gz_record_stream *)state->internal_state;
    next = state->current_index + 1;
    if (next < 0 || (size_t)next >= stream->count) {
        state->has_record = false;
        return false;
    }
    xx_data_struct_record_cleanup(&state->current_record);
    if (!xx_data_struct_record_populate(&state->current_record, self->device, state->parent_struct.offset, &stream->fields[next], false)) {
        state->has_record = false;
        return false;
    }
    state->current_index = next;
    return true;
}

void xx_gz_free_data_struct_records_reading(Abstractformat *self, xx_data_struct_record_state *state)
{
    (void)self;
    xx_data_struct_record_state_free(state);
}


const StreamDataStructs *xx_gz_get_stream_datastructs(void)
{
    static const StreamDataStructs stream = {
        .data_struct_id_to_string = xx_gz_data_struct_id_to_string,
        .data_struct_string_to_id = xx_gz_data_struct_string_to_id,
        .create_data_structs_reading = xx_gz_create_data_structs_reading,
        .get_current_data_struct = xx_gz_get_current_data_struct,
        .data_struct_move_to_next = xx_gz_data_struct_move_to_next,
        .free_data_structs_reading = xx_gz_free_data_structs_reading,
        .create_data_struct_records_reading = xx_gz_create_data_struct_records_reading,
        .get_current_data_struct_record = xx_gz_get_current_data_struct_record,
        .data_struct_record_move_to_next = xx_gz_data_struct_record_move_to_next,
        .free_data_struct_records_reading = xx_gz_free_data_struct_records_reading,
    };
    return &stream;
}
