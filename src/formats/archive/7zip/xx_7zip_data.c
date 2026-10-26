/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#include "xx_7zip_data.h"
#include "xx_7zip_defs.h"
#include "xx_7zip_internal.h"
#include "xxfclib/data/xx_data.h"
#include "xxfclib/io/xx_io.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/strings/xx_string.h"

#include <stdint.h>

typedef struct xx_7zip_ds_state_s {
    xx_data_struct *items;
    size_t count;
} xx_7zip_ds_state;

static void xx_7zip_ds_state_free(void *ptr)
{
    xx_7zip_ds_state *internal = (xx_7zip_ds_state *)ptr;
    if (!internal) return;
    if (internal->items) xx_mem_free(internal->items);
    xx_mem_free(internal);
}

const char *xx_7zip_data_struct_id_to_string(Abstractformat *self, uint32_t id)
{
    (void)self;
    switch ((xx_7zip_data_struct_id_t)id) {
        case XX_7ZIP_DS_SIGNATURE_HEADER: return "SIGNATURE_HEADER";
        case XX_7ZIP_DS_PACKED_DATA: return "PACKED_DATA";
        case XX_7ZIP_DS_NEXT_HEADER: return "NEXT_HEADER";
        default: return "UNKNOWN";
    }
}

uint32_t xx_7zip_data_struct_string_to_id(Abstractformat *self, const char *name)
{
    (void)self;
    if (!name) return XX_7ZIP_DS_UNKNOWN;
    if (xx_str_cmp(name, "SIGNATURE_HEADER") == 0) return XX_7ZIP_DS_SIGNATURE_HEADER;
    if (xx_str_cmp(name, "PACKED_DATA") == 0) return XX_7ZIP_DS_PACKED_DATA;
    if (xx_str_cmp(name, "NEXT_HEADER") == 0) return XX_7ZIP_DS_NEXT_HEADER;
    return XX_7ZIP_DS_UNKNOWN;
}

xx_data_struct_state *xx_7zip_create_data_structs_reading(Abstractformat *self, xx_pd_struct *pd)
{
    xx_7zip *archive;
    xx_7zip_private *priv;
    xx_data_struct_state *state = NULL;
    xx_7zip_ds_state *internal = NULL;
    size_t capacity;
    uint64_t i;
    if (!self || !self->device) return NULL;
    if (!self->base_info_handled && !xx_format_handle_base_info(self, pd)) return NULL;
    archive = (xx_7zip *)self;
    priv = (xx_7zip_private *)archive->internal;
    if (!self->is_valid || !priv || priv->streams.num_packs > SIZE_MAX - 2U) return NULL;
    capacity = (size_t)priv->streams.num_packs + 2U;
    state = (xx_data_struct_state *)xx_mem_alloc(sizeof(*state));
    internal = (xx_7zip_ds_state *)xx_mem_calloc(1, sizeof(*internal));
    if (!state || !internal) goto fail;
    xx_data_struct_state_init(state, self);
    internal->items = (xx_data_struct *)xx_mem_calloc(capacity, sizeof(xx_data_struct));
    if (!internal->items) goto fail;
    {
        xx_data_struct *item = &internal->items[internal->count++];
        item->id = XX_7ZIP_DS_SIGNATURE_HEADER;
        item->offset = self->base_address;
        item->address = self->is_mapped ? self->base_address : -1;
        item->entry_size = XX_7ZIP_SIGNATURE_HEADER_SIZE;
        item->total_size = XX_7ZIP_SIGNATURE_HEADER_SIZE;
        item->count = 1;
        item->type = XX_DATA_STRUCT_TYPE_STRUCT;
    }
    for (i = 0; i < priv->streams.num_packs; ++i) {
        int64_t offset;
        uint64_t size;
        xx_data_struct *item;
        if (!xx_7zip_pack_offset(self, &priv->streams, i, &offset, &size) || size > INT64_MAX) goto fail;
        item = &internal->items[internal->count++];
        item->id = XX_7ZIP_DS_PACKED_DATA;
        item->offset = offset;
        item->address = self->is_mapped ? offset : -1;
        item->entry_size = (int64_t)size;
        item->total_size = (int64_t)size;
        item->count = 1;
        item->type = XX_DATA_STRUCT_TYPE_RAW_DATA;
    }
    if (archive->next_header_size != 0U) {
        xx_data_struct *item = &internal->items[internal->count++];
        item->id = XX_7ZIP_DS_NEXT_HEADER;
        item->offset = archive->next_header_offset;
        item->address = self->is_mapped ? archive->next_header_offset : -1;
        item->entry_size = archive->next_header_size <= INT64_MAX ? (int64_t)archive->next_header_size : -1;
        item->total_size = item->entry_size;
        item->count = 1;
        item->type = XX_DATA_STRUCT_TYPE_FOOTER;
    }
    state->internal_state = internal;
    state->free_internal = xx_7zip_ds_state_free;
    state->total_structs = (int64_t)internal->count;
    state->current_index = 0;
    state->current_struct = internal->items[0];
    state->has_struct = true;
    return state;

fail:
    if (internal) xx_7zip_ds_state_free(internal);
    if (state) xx_data_struct_state_free(state);
    return NULL;
}

const xx_data_struct *xx_7zip_get_current_data_struct(Abstractformat *self, xx_data_struct_state *state)
{
    return self && state && state->format == self && state->has_struct ? &state->current_struct : NULL;
}

bool xx_7zip_data_struct_move_to_next(Abstractformat *self, xx_data_struct_state *state, xx_pd_struct *pd)
{
    xx_7zip_ds_state *internal;
    int64_t next;
    if (!self || !self->device || !state || state->format != self || !state->has_struct || !state->internal_state || (pd && xx_pd_is_stopped(pd))) return false;
    internal = (xx_7zip_ds_state *)state->internal_state;
    next = state->current_index + 1;
    if (next < 0 || (size_t)next >= internal->count) {
        state->has_struct = false;
        return false;
    }
    state->current_index = next;
    state->current_struct = internal->items[next];
    state->has_struct = true;
    return true;
}

void xx_7zip_free_data_structs_reading(Abstractformat *self, xx_data_struct_state *state)
{
    (void)self;
    xx_data_struct_state_free(state);
}

static const xx_data_struct_field_desc XX_7ZIP_SIGNATURE_FIELDS[] = {
    {L"signature_part_1", L"uint32", 0, 4, XX_DATA_STRUCT_RECORD_PROPERTY_ID},    {L"signature_part_2", L"uint16", 4, 2, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
    {L"major_version", L"uint8", 6, 1, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},      {L"minor_version", L"uint8", 7, 1, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},
    {L"start_header_crc", L"uint32", 8, 4, XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM},  {L"next_header_offset", L"uint64", 12, 8, XX_DATA_STRUCT_RECORD_PROPERTY_POINTER},
    {L"next_header_size", L"uint64", 20, 8, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE}, {L"next_header_crc", L"uint32", 28, 4, XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM}};

static const xx_data_struct_field_desc XX_7ZIP_NEXT_HEADER_FIELDS[] = {{L"nid", L"uint8", 0, 1, XX_DATA_STRUCT_RECORD_PROPERTY_ID}};

typedef struct xx_7zip_record_state_s {
    const xx_data_struct_field_desc *fields;
    size_t count;
} xx_7zip_record_state;

static void xx_7zip_record_state_free(void *ptr)
{
    if (ptr) xx_mem_free(ptr);
}

xx_data_struct_record_state *xx_7zip_create_data_struct_records_reading(Abstractformat *self, const xx_data_struct *ds, xx_pd_struct *pd)
{
    xx_data_struct_record_state *state;
    xx_7zip_record_state *internal;
    const xx_data_struct_field_desc *fields;
    size_t count;
    if (!self || !self->device || !ds || xx_pd_is_stopped(pd) || ds->offset < 0 || ds->total_size <= 0 ||
        !xx_io_check(self->device, ds->offset, ds->total_size)) return NULL;
    if (ds->id == XX_7ZIP_DS_SIGNATURE_HEADER) {
        fields = XX_7ZIP_SIGNATURE_FIELDS;
        count = sizeof(XX_7ZIP_SIGNATURE_FIELDS) / sizeof(XX_7ZIP_SIGNATURE_FIELDS[0]);
    } else if (ds->id == XX_7ZIP_DS_NEXT_HEADER) {
        fields = XX_7ZIP_NEXT_HEADER_FIELDS;
        count = sizeof(XX_7ZIP_NEXT_HEADER_FIELDS) / sizeof(XX_7ZIP_NEXT_HEADER_FIELDS[0]);
    } else {
        return NULL;
    }
    for (size_t i = 0U; i < count; ++i) {
        if (fields[i].rel_offset > ds->total_size || fields[i].size > ds->total_size - fields[i].rel_offset) return NULL;
    }
    state = (xx_data_struct_record_state *)xx_mem_alloc(sizeof(*state));
    if (!state) return NULL;
    xx_data_struct_record_state_init(state, self, ds);
    internal = (xx_7zip_record_state *)xx_mem_alloc(sizeof(*internal));
    if (!internal) {
        xx_data_struct_record_state_free(state);
        return NULL;
    }
    internal->fields = fields;
    internal->count = count;
    state->internal_state = internal;
    state->free_internal = xx_7zip_record_state_free;
    state->total_records = (int64_t)count;
    state->current_index = 0;
    state->has_record = xx_data_struct_record_populate(&state->current_record, self->device, ds->offset, &fields[0], false);
    if (!state->has_record) {
        xx_data_struct_record_state_free(state);
        return NULL;
    }
    return state;
}

const xx_data_struct_record *xx_7zip_get_current_data_struct_record(Abstractformat *self, xx_data_struct_record_state *state)
{
    return self && state && state->format == self && state->has_record ? &state->current_record : NULL;
}

bool xx_7zip_data_struct_record_move_to_next(Abstractformat *self, xx_data_struct_record_state *state, xx_pd_struct *pd)
{
    xx_7zip_record_state *internal;
    int64_t next;
    if (!self || !self->device || !state || state->format != self || !state->has_record || !state->internal_state || (pd && xx_pd_is_stopped(pd))) return false;
    internal = (xx_7zip_record_state *)state->internal_state;
    next = state->current_index + 1;
    if (next < 0 || (size_t)next >= internal->count) {
        state->has_record = false;
        return false;
    }
    xx_data_struct_record_cleanup(&state->current_record);
    if (!xx_data_struct_record_populate(&state->current_record, self->device, state->parent_struct.offset, &internal->fields[next], false)) {
        state->has_record = false;
        return false;
    }
    state->current_index = next;
    state->has_record = true;
    return true;
}

void xx_7zip_free_data_struct_records_reading(Abstractformat *self, xx_data_struct_record_state *state)
{
    (void)self;
    xx_data_struct_record_state_free(state);
}

void xx_7zip_setup_data_struct_callbacks(xx_7zip *archive)
{
    if (!archive) return;
    archive->format.data_struct_id_to_string = xx_7zip_data_struct_id_to_string;
    archive->format.data_struct_string_to_id = xx_7zip_data_struct_string_to_id;
    archive->format.create_data_structs_reading = xx_7zip_create_data_structs_reading;
    archive->format.get_current_data_struct = xx_7zip_get_current_data_struct;
    archive->format.data_struct_move_to_next = xx_7zip_data_struct_move_to_next;
    archive->format.free_data_structs_reading = xx_7zip_free_data_structs_reading;
    archive->format.create_data_struct_records_reading = xx_7zip_create_data_struct_records_reading;
    archive->format.get_current_data_struct_record = xx_7zip_get_current_data_struct_record;
    archive->format.data_struct_record_move_to_next = xx_7zip_data_struct_record_move_to_next;
    archive->format.free_data_struct_records_reading = xx_7zip_free_data_struct_records_reading;
}
