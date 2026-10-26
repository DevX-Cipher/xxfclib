/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#include "xx_ar_data.h"
#include "xx_ar_defs.h"
#include "xx_ar_internal.h"
#include "xxfclib/rt/xx_rt.h"
#include "xxfclib/data/xx_data.h"
#include "xxfclib/io/xx_io.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/strings/xx_string.h"

#include <stdint.h>
#include <wchar.h>

typedef struct xx_ar_ds_stream_s {
    xx_data_struct *items;
    size_t count;
} xx_ar_ds_stream;

typedef struct xx_ar_record_stream_s {
    const xx_data_struct_field_desc *fields;
    size_t count;
} xx_ar_record_stream;

typedef struct xx_ar_ds_name_s {
    xx_ar_data_struct_id_t id;
    const char *name;
} xx_ar_ds_name;

static const xx_ar_ds_name xx_ar_ds_names[] = {{XX_AR_DS_UNKNOWN, "UNKNOWN"},
                                               {XX_AR_DS_GLOBAL_HEADER, "GLOBAL_HEADER"},
                                               {XX_AR_DS_MEMBER_HEADER, "MEMBER_HEADER"},
                                               {XX_AR_DS_BSD_EXTENDED_NAME, "BSD_EXTENDED_NAME"},
                                               {XX_AR_DS_DATA, "DATA"},
                                               {XX_AR_DS_PADDING, "PADDING"}};

const char *xx_ar_data_struct_id_to_string(Abstractformat *self, uint32_t id)
{
    (void)self;
    for (size_t i = 0; i < sizeof(xx_ar_ds_names) / sizeof(xx_ar_ds_names[0]); ++i) {
        if ((uint32_t)xx_ar_ds_names[i].id == id) {
            return xx_ar_ds_names[i].name;
        }
    }
    return "UNKNOWN";
}

uint32_t xx_ar_data_struct_string_to_id(Abstractformat *self, const char *name)
{
    (void)self;
    if (name) {
        for (size_t i = 0; i < sizeof(xx_ar_ds_names) / sizeof(xx_ar_ds_names[0]); ++i) {
            if (xx_str_cmp(name, xx_ar_ds_names[i].name) == 0) {
                return (uint32_t)xx_ar_ds_names[i].id;
            }
        }
    }
    return (uint32_t)XX_AR_DS_UNKNOWN;
}

static void xx_ar_ds_stream_free(void *pointer)
{
    xx_ar_ds_stream *stream = (xx_ar_ds_stream *)pointer;
    if (stream) {
        if (stream->items) xx_mem_free(stream->items);
        xx_mem_free(stream);
    }
}

static void xx_ar_set_ds(xx_data_struct *item, uint32_t id, int64_t offset, int64_t size, xx_data_struct_type_t type, bool is_mapped)
{
    item->id = id;
    item->offset = offset;
    item->address = is_mapped ? offset : -1;
    item->entry_size = size;
    item->total_size = size;
    item->count = 1U;
    item->type = type;
}

xx_data_struct_state *xx_ar_create_data_structs_reading(Abstractformat *self, xx_pd_struct *pd)
{
    xx_data_struct_state *state;
    xx_ar_ds_stream *stream;
    xx_ar_members members;
    size_t capacity;
    if (!self || !self->device || (!self->base_info_handled && !xx_format_handle_base_info(self, pd)) || !xx_ar_parse_archive(self, &members, XX_AR_PARSE_MEMBERS, pd)) {
        return NULL;
    }
    if (members.count > (SIZE_MAX - 1U) / 4U) {
        xx_ar_members_cleanup(&members);
        return NULL;
    }
    capacity = 1U + members.count * 4U;
    if (capacity > SIZE_MAX / sizeof(*stream->items)) {
        xx_ar_members_cleanup(&members);
        return NULL;
    }
    state = (xx_data_struct_state *)xx_mem_alloc(sizeof(*state));
    stream = (xx_ar_ds_stream *)xx_mem_alloc(sizeof(*stream));
    if (!state || !stream) {
        if (state) xx_mem_free(state);
        if (stream) xx_mem_free(stream);
        xx_ar_members_cleanup(&members);
        return NULL;
    }
    xx_data_struct_state_init(state, self);
    xx_mem_zero(stream, sizeof(*stream));
    stream->items = (xx_data_struct *)xx_mem_alloc(capacity * sizeof(xx_data_struct));
    if (!stream->items) {
        xx_mem_free(stream);
        xx_data_struct_state_free(state);
        xx_ar_members_cleanup(&members);
        return NULL;
    }
    xx_ar_set_ds(&stream->items[stream->count++], XX_AR_DS_GLOBAL_HEADER, self->base_address, XX_AR_MAGIC_SIZE, XX_DATA_STRUCT_TYPE_STRUCT, self->is_mapped);
    for (size_t i = 0; i < members.count; ++i) {
        const xx_ar_member *member = &members.items[i];
        xx_ar_set_ds(&stream->items[stream->count++], XX_AR_DS_MEMBER_HEADER, member->header_offset, XX_AR_MEMBER_HEADER_SIZE, XX_DATA_STRUCT_TYPE_STRUCT,
                     self->is_mapped);
        if (member->name_prefix_size != 0U) {
            xx_ar_set_ds(&stream->items[stream->count++], XX_AR_DS_BSD_EXTENDED_NAME, member->stored_data_offset, (int64_t)member->name_prefix_size,
                         XX_DATA_STRUCT_TYPE_RAW_DATA, self->is_mapped);
        }
        if (member->data_size != 0) {
            xx_ar_set_ds(&stream->items[stream->count++], XX_AR_DS_DATA, member->data_offset, member->data_size, XX_DATA_STRUCT_TYPE_RAW_DATA, self->is_mapped);
        }
        if ((member->stored_size & 1) != 0) {
            xx_ar_set_ds(&stream->items[stream->count++], XX_AR_DS_PADDING, member->stored_data_offset + member->stored_size, 1, XX_DATA_STRUCT_TYPE_RAW_DATA,
                         self->is_mapped);
        }
    }
    xx_ar_members_cleanup(&members);
    state->internal_state = stream;
    state->free_internal = xx_ar_ds_stream_free;
    state->total_structs = (int64_t)stream->count;
    state->current_index = 0;
    state->has_struct = stream->count != 0U;
    if (state->has_struct) {
        state->current_struct = stream->items[0];
    }
    return state;
}

const xx_data_struct *xx_ar_get_current_data_struct(Abstractformat *self, xx_data_struct_state *state)
{
    return self && state && state->format == self && state->has_struct ? &state->current_struct : NULL;
}

bool xx_ar_data_struct_move_to_next(Abstractformat *self, xx_data_struct_state *state, xx_pd_struct *pd)
{
    xx_ar_ds_stream *stream;
    int64_t next;
    if (!self || !self->device || !state || state->format != self || !state->has_struct || !state->internal_state || (pd && xx_pd_is_stopped(pd))) {
        return false;
    }
    stream = (xx_ar_ds_stream *)state->internal_state;
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

void xx_ar_free_data_structs_reading(Abstractformat *self, xx_data_struct_state *state)
{
    (void)self;
    xx_data_struct_state_free(state);
}

static const xx_data_struct_field_desc xx_ar_global_fields[] = {{L"magic", L"char[8]", 0, 8, XX_DATA_STRUCT_RECORD_PROPERTY_ID}};

static const xx_data_struct_field_desc xx_ar_member_fields[] = {
    {L"name", L"char[16]", 0, 16, XX_DATA_STRUCT_RECORD_PROPERTY_STRING},  {L"timestamp", L"char[12]", 16, 12, XX_DATA_STRUCT_RECORD_PROPERTY_TIMESTAMP},
    {L"owner_id", L"char[6]", 28, 6, XX_DATA_STRUCT_RECORD_PROPERTY_NONE}, {L"group_id", L"char[6]", 34, 6, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},
    {L"mode", L"char[8]", 40, 8, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS},    {L"size", L"char[10]", 48, 10, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},
    {L"trailer", L"char[2]", 58, 2, XX_DATA_STRUCT_RECORD_PROPERTY_ID}};

static void xx_ar_record_stream_free(void *pointer)
{
    if (pointer) xx_mem_free(pointer);
}

static bool xx_ar_populate_field(xx_io_device *device, const xx_data_struct *parent, const xx_data_struct_field_desc *field, xx_data_struct_record *record)
{
    char *text;
    wchar_t *display;
    size_t length;
    int64_t total_size;
    if (!device || !parent || !field || !record || field->size < 0 || (uint64_t)field->size > (uint64_t)(SIZE_MAX - 1U)) {
        return false;
    }
    total_size = xx_io_total_size(device);
    if (parent->offset < 0 || field->rel_offset < 0 || parent->offset > INT64_MAX - field->rel_offset || parent->offset + field->rel_offset > total_size ||
        field->size > total_size - (parent->offset + field->rel_offset)) {
        return false;
    }
    length = (size_t)field->size;
    text = (char *)xx_mem_alloc(length + 1U);
    if (!text || !xx_ar_read_exact_at(device, parent->offset + field->rel_offset, text, length)) {
        if (text) xx_mem_free(text);
        return false;
    }
    while (length > 0U && (text[length - 1U] == ' ' || text[length - 1U] == '\0')) {
        --length;
    }
    text[length] = '\0';
    display = xx_str_utf8_to_unicode(text);
    if (!display) {
        xx_mem_free(text);
        return false;
    }
    xx_data_struct_record_init(record);
    record->offset = field->rel_offset;
    record->size = field->size;
    record->property = field->property;
    if (!xx_var_set_str(&record->value, text) || !xx_data_struct_record_set_name(record, field->name) || !xx_data_struct_record_set_type(record, field->type) ||
        !xx_data_struct_record_set_raw_bytes(record, device, parent->offset + field->rel_offset, field->size) ||
        !xx_data_struct_record_set_display_value(record, display)) {
        xx_str_wfree(display);
        xx_mem_free(text);
        xx_data_struct_record_cleanup(record);
        return false;
    }
    xx_str_wfree(display);
    xx_mem_free(text);
    return true;
}

xx_data_struct_record_state *xx_ar_create_data_struct_records_reading(Abstractformat *self, const xx_data_struct *ds, xx_pd_struct *pd)
{
    xx_data_struct_record_state *state;
    xx_ar_record_stream *stream;
    const xx_data_struct_field_desc *fields;
    size_t count;
    (void)pd;
    if (!self || !self->device || !ds) {
        return NULL;
    }
    if (ds->id == (uint32_t)XX_AR_DS_GLOBAL_HEADER) {
        fields = xx_ar_global_fields;
        count = sizeof(xx_ar_global_fields) / sizeof(xx_ar_global_fields[0]);
    } else if (ds->id == (uint32_t)XX_AR_DS_MEMBER_HEADER) {
        fields = xx_ar_member_fields;
        count = sizeof(xx_ar_member_fields) / sizeof(xx_ar_member_fields[0]);
    } else {
        return NULL;
    }
    state = (xx_data_struct_record_state *)xx_mem_alloc(sizeof(*state));
    stream = (xx_ar_record_stream *)xx_mem_alloc(sizeof(*stream));
    if (!state || !stream) {
        if (state) xx_mem_free(state);
        if (stream) xx_mem_free(stream);
        return NULL;
    }
    xx_data_struct_record_state_init(state, self, ds);
    stream->fields = fields;
    stream->count = count;
    state->internal_state = stream;
    state->free_internal = xx_ar_record_stream_free;
    state->total_records = (int64_t)count;
    if (count != 0U && xx_ar_populate_field(self->device, ds, &fields[0], &state->current_record)) {
        state->has_record = true;
        state->current_index = 0;
    }
    return state;
}

const xx_data_struct_record *xx_ar_get_current_data_struct_record(Abstractformat *self, xx_data_struct_record_state *state)
{
    return self && state && state->format == self && state->has_record ? &state->current_record : NULL;
}

bool xx_ar_data_struct_record_move_to_next(Abstractformat *self, xx_data_struct_record_state *state, xx_pd_struct *pd)
{
    xx_ar_record_stream *stream;
    int64_t next;
    if (!self || !self->device || !state || state->format != self || !state->has_record || !state->internal_state || (pd && xx_pd_is_stopped(pd))) {
        return false;
    }
    stream = (xx_ar_record_stream *)state->internal_state;
    next = state->current_index + 1;
    if (next < 0 || (size_t)next >= stream->count) {
        state->has_record = false;
        return false;
    }
    xx_data_struct_record_cleanup(&state->current_record);
    if (!xx_ar_populate_field(self->device, &state->parent_struct, &stream->fields[next], &state->current_record)) {
        state->has_record = false;
        return false;
    }
    state->current_index = next;
    state->has_record = true;
    return true;
}

void xx_ar_free_data_struct_records_reading(Abstractformat *self, xx_data_struct_record_state *state)
{
    (void)self;
    xx_data_struct_record_state_free(state);
}

void xx_ar_setup_data_struct_callbacks(xx_ar *ar)
{
    if (!ar) return;
    ar->format.data_struct_id_to_string = xx_ar_data_struct_id_to_string;
    ar->format.data_struct_string_to_id = xx_ar_data_struct_string_to_id;
    ar->format.create_data_structs_reading = xx_ar_create_data_structs_reading;
    ar->format.get_current_data_struct = xx_ar_get_current_data_struct;
    ar->format.data_struct_move_to_next = xx_ar_data_struct_move_to_next;
    ar->format.free_data_structs_reading = xx_ar_free_data_structs_reading;
    ar->format.create_data_struct_records_reading = xx_ar_create_data_struct_records_reading;
    ar->format.get_current_data_struct_record = xx_ar_get_current_data_struct_record;
    ar->format.data_struct_record_move_to_next = xx_ar_data_struct_record_move_to_next;
    ar->format.free_data_struct_records_reading = xx_ar_free_data_struct_records_reading;
}
