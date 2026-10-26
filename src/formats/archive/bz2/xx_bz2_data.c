/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#include "xx_bz2_data.h"
#include "xx_bz2_defs.h"
#include "xx_bz2_internal.h"
#include "xxfclib/rt/xx_rt.h"
#include "xxfclib/data/xx_data.h"
#include "xxfclib/io/xx_io.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/strings/xx_string.h"

#include <stdint.h>
#include <wchar.h>

typedef struct xx_bz2_ds_stream_s {
    xx_data_struct items[2];
    size_t count;
} xx_bz2_ds_stream;

typedef struct xx_bz2_record_stream_s {
    const xx_data_struct_field_desc *fields;
    size_t count;
} xx_bz2_record_stream;

typedef struct xx_bz2_ds_name_s {
    xx_bz2_data_struct_id_t id;
    const char *name;
} xx_bz2_ds_name;

static const xx_bz2_ds_name xx_bz2_ds_names[] = {
    {XX_BZ2_DS_UNKNOWN, "UNKNOWN"}, {XX_BZ2_DS_STREAM_HEADER, "STREAM_HEADER"}, {XX_BZ2_DS_COMPRESSED_DATA, "COMPRESSED_DATA"}};

const char *xx_bz2_data_struct_id_to_string(Abstractformat *self, uint32_t id)
{
    (void)self;
    for (size_t i = 0U; i < sizeof(xx_bz2_ds_names) / sizeof(xx_bz2_ds_names[0]); ++i) {
        if ((uint32_t)xx_bz2_ds_names[i].id == id) {
            return xx_bz2_ds_names[i].name;
        }
    }
    return "UNKNOWN";
}

uint32_t xx_bz2_data_struct_string_to_id(Abstractformat *self, const char *name)
{
    (void)self;
    if (name) {
        for (size_t i = 0U; i < sizeof(xx_bz2_ds_names) / sizeof(xx_bz2_ds_names[0]); ++i) {
            if (xx_str_cmp(name, xx_bz2_ds_names[i].name) == 0) {
                return (uint32_t)xx_bz2_ds_names[i].id;
            }
        }
    }
    return (uint32_t)XX_BZ2_DS_UNKNOWN;
}

static void xx_bz2_ds_stream_free(void *pointer)
{
    if (pointer) {
        xx_mem_free(pointer);
    }
}

static void xx_bz2_set_ds(xx_data_struct *item, uint32_t id, int64_t offset, int64_t size, xx_data_struct_type_t type, bool is_mapped)
{
    item->id = id;
    item->offset = offset;
    item->address = is_mapped ? offset : -1;
    item->entry_size = size;
    item->total_size = size;
    item->count = 1U;
    item->type = type;
}

xx_data_struct_state *xx_bz2_create_data_structs_reading(Abstractformat *self, xx_pd_struct *pd)
{
    xx_data_struct_state *state;
    xx_bz2_ds_stream *stream;
    if (!self || !self->device || (!self->base_info_handled && !xx_format_handle_base_info(self, pd)) || !self->is_valid || self->format_size < XX_BZ2_HEADER_SIZE) {
        return NULL;
    }
    state = (xx_data_struct_state *)xx_mem_alloc(sizeof(*state));
    stream = (xx_bz2_ds_stream *)xx_mem_alloc(sizeof(*stream));
    if (!state || !stream) {
        if (state) {
            xx_mem_free(state);
        }
        if (stream) {
            xx_mem_free(stream);
        }
        return NULL;
    }
    xx_data_struct_state_init(state, self);
    xx_mem_zero(stream, sizeof(*stream));
    xx_bz2_set_ds(&stream->items[stream->count++], XX_BZ2_DS_STREAM_HEADER, self->base_address, XX_BZ2_HEADER_SIZE, XX_DATA_STRUCT_TYPE_STRUCT, self->is_mapped);
    xx_bz2_set_ds(&stream->items[stream->count++], XX_BZ2_DS_COMPRESSED_DATA, self->base_address + XX_BZ2_HEADER_SIZE, self->format_size - XX_BZ2_HEADER_SIZE,
                  XX_DATA_STRUCT_TYPE_RAW_DATA, self->is_mapped);
    state->internal_state = stream;
    state->free_internal = xx_bz2_ds_stream_free;
    state->total_structs = (int64_t)stream->count;
    state->current_index = 0;
    state->current_struct = stream->items[0];
    state->has_struct = true;
    return state;
}

const xx_data_struct *xx_bz2_get_current_data_struct(Abstractformat *self, xx_data_struct_state *state)
{
    return self && state && state->format == self && state->has_struct ? &state->current_struct : NULL;
}

bool xx_bz2_data_struct_move_to_next(Abstractformat *self, xx_data_struct_state *state, xx_pd_struct *pd)
{
    xx_bz2_ds_stream *stream;
    int64_t next;
    if (!self || !state || state->format != self || !state->has_struct || !state->internal_state || (pd && xx_pd_is_stopped(pd))) {
        return false;
    }
    stream = (xx_bz2_ds_stream *)state->internal_state;
    next = state->current_index + 1;
    if (next < 0 || (size_t)next >= stream->count) {
        state->has_struct = false;
        return false;
    }
    state->current_index = next;
    state->current_struct = stream->items[next];
    state->has_struct = true;
    return true;
}

void xx_bz2_free_data_structs_reading(Abstractformat *self, xx_data_struct_state *state)
{
    (void)self;
    xx_data_struct_state_free(state);
}

static const xx_data_struct_field_desc xx_bz2_header_fields[] = {{L"magic", L"char[3]", 0, 3, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                 {L"block_size_100k", L"ascii_digit", 3, 1, XX_DATA_STRUCT_RECORD_PROPERTY_COUNT}};

static void xx_bz2_record_stream_free(void *pointer)
{
    if (pointer) {
        xx_mem_free(pointer);
    }
}

static bool xx_bz2_populate_field(xx_io_device *device, const xx_data_struct *parent, const xx_data_struct_field_desc *field, xx_data_struct_record *record)
{
    uint8_t raw[3];
    wchar_t display[64];
    wchar_t unit_comment[64] = {0};
    if (!device || !parent || !field || !record || parent->offset < 0 || field->rel_offset < 0 || parent->offset > INT64_MAX - field->rel_offset ||
        (field->size != 1 && field->size != 3) || !xx_bz2_read_exact_at(device, parent->offset + field->rel_offset, raw, (size_t)field->size)) {
        return false;
    }
    xx_data_struct_record_init(record);
    record->offset = field->rel_offset;
    record->size = field->size;
    record->property = field->property;
    if (field->size == 3) {
        char magic[4];
        magic[0] = (char)raw[0];
        magic[1] = (char)raw[1];
        magic[2] = (char)raw[2];
        magic[3] = '\0';
        if (!xx_var_set_str(&record->value, magic)) {
            xx_data_struct_record_cleanup(record);
            return false;
        }
        display[0] = (wchar_t)raw[0];
        display[1] = (wchar_t)raw[1];
        display[2] = (wchar_t)raw[2];
        display[3] = L'\0';
    } else {
        char ascii_display[sizeof(display) / sizeof(display[0])];
        int display_length;
        size_t display_index;
        if (raw[0] < (uint8_t)'1' || raw[0] > (uint8_t)'9') { xx_data_struct_record_cleanup(record); return false; }
        uint8_t level = (uint8_t)(raw[0] - (uint8_t)'0');
        xx_var_set_u8(&record->value, level);
        display_length = xx_rt_snprintf(ascii_display, sizeof(ascii_display), "%u", (unsigned)level);
        if (display_length < 0 || (size_t)display_length >= sizeof(ascii_display)) {
            xx_data_struct_record_cleanup(record);
            return false;
        }
        for (display_index = 0U; display_index <= (size_t)display_length; ++display_index) {
            display[display_index] = (wchar_t)(unsigned char)ascii_display[display_index];
        }
        display_length = xx_rt_snprintf(ascii_display, sizeof(ascii_display), "%u Bytes maximum block size (%u x 100000)", (unsigned)level * 100000U, (unsigned)level);
        if (display_length < 0 || (size_t)display_length >= sizeof(ascii_display)) { xx_data_struct_record_cleanup(record); return false; }
        for (display_index = 0U; display_index <= (size_t)display_length; ++display_index) unit_comment[display_index] = (wchar_t)(unsigned char)ascii_display[display_index];
    }
    if (!xx_data_struct_record_set_name(record, field->name) || !xx_data_struct_record_set_type(record, field->type) ||
        !xx_data_struct_record_set_raw_bytes(record, device, parent->offset + field->rel_offset, field->size) ||
        !xx_data_struct_record_set_display_value(record, display) ||
        (unit_comment[0] && !xx_data_struct_record_set_comment(record, unit_comment))) {
        xx_data_struct_record_cleanup(record);
        return false;
    }
    return true;
}

xx_data_struct_record_state *xx_bz2_create_data_struct_records_reading(Abstractformat *self, const xx_data_struct *ds, xx_pd_struct *pd)
{
    xx_data_struct_record_state *state;
    xx_bz2_record_stream *stream;
    const size_t count = sizeof(xx_bz2_header_fields) / sizeof(xx_bz2_header_fields[0]);
    (void)pd;
    if (!self || !self->device || !ds || ds->id != (uint32_t)XX_BZ2_DS_STREAM_HEADER || xx_pd_is_stopped(pd) ||
        ds->offset < 0 || ds->total_size < 4 || !xx_io_check(self->device, ds->offset, ds->total_size)) {
        return NULL;
    }
    state = (xx_data_struct_record_state *)xx_mem_alloc(sizeof(*state));
    stream = (xx_bz2_record_stream *)xx_mem_alloc(sizeof(*stream));
    if (!state || !stream) {
        if (state) {
            xx_mem_free(state);
        }
        if (stream) {
            xx_mem_free(stream);
        }
        return NULL;
    }
    xx_data_struct_record_state_init(state, self, ds);
    stream->fields = xx_bz2_header_fields;
    stream->count = count;
    state->internal_state = stream;
    state->free_internal = xx_bz2_record_stream_free;
    state->total_records = (int64_t)count;
    state->current_index = 0;
    if (!xx_bz2_populate_field(self->device, ds, &stream->fields[0], &state->current_record)) {
        xx_data_struct_record_state_free(state);
        return NULL;
    }
    state->has_record = true;
    return state;
}

const xx_data_struct_record *xx_bz2_get_current_data_struct_record(Abstractformat *self, xx_data_struct_record_state *state)
{
    return self && state && state->format == self && state->has_record ? &state->current_record : NULL;
}

bool xx_bz2_data_struct_record_move_to_next(Abstractformat *self, xx_data_struct_record_state *state, xx_pd_struct *pd)
{
    xx_bz2_record_stream *stream;
    int64_t next;
    if (!self || !state || state->format != self || !state->has_record || !state->internal_state || (pd && xx_pd_is_stopped(pd))) {
        return false;
    }
    stream = (xx_bz2_record_stream *)state->internal_state;
    next = state->current_index + 1;
    if (next < 0 || (size_t)next >= stream->count) {
        xx_data_struct_record_cleanup(&state->current_record);
        xx_data_struct_record_init(&state->current_record);
        state->has_record = false;
        return false;
    }
    xx_data_struct_record_cleanup(&state->current_record);
    if (!xx_bz2_populate_field(self->device, &state->parent_struct, &stream->fields[next], &state->current_record)) {
        state->has_record = false;
        return false;
    }
    state->current_index = next;
    state->has_record = true;
    return true;
}

void xx_bz2_free_data_struct_records_reading(Abstractformat *self, xx_data_struct_record_state *state)
{
    (void)self;
    xx_data_struct_record_state_free(state);
}

void xx_bz2_setup_data_struct_callbacks(xx_bz2 *bz2)
{
    if (!bz2) return;
    bz2->format.data_struct_id_to_string = xx_bz2_data_struct_id_to_string;
    bz2->format.data_struct_string_to_id = xx_bz2_data_struct_string_to_id;
    bz2->format.create_data_structs_reading = xx_bz2_create_data_structs_reading;
    bz2->format.get_current_data_struct = xx_bz2_get_current_data_struct;
    bz2->format.data_struct_move_to_next = xx_bz2_data_struct_move_to_next;
    bz2->format.free_data_structs_reading = xx_bz2_free_data_structs_reading;
    bz2->format.create_data_struct_records_reading = xx_bz2_create_data_struct_records_reading;
    bz2->format.get_current_data_struct_record = xx_bz2_get_current_data_struct_record;
    bz2->format.data_struct_record_move_to_next = xx_bz2_data_struct_record_move_to_next;
    bz2->format.free_data_struct_records_reading = xx_bz2_free_data_struct_records_reading;
}
