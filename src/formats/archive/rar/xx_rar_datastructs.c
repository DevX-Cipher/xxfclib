/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#include "xxfclib/formats/xx_format_streams.h"
#include "xx_rar_datastructs_internal.h"



typedef struct xx_rar_ds_name_s {
    xx_rar_data_struct_id_t id;
    const char *name;
} xx_rar_ds_name;

static const xx_rar_ds_name g_xx_rar_ds_names[] = {
    {XX_RAR_DS_UNKNOWN, "UNKNOWN"},         {XX_RAR_DS_SIGNATURE, "SIGNATURE"},           {XX_RAR_DS_MAIN_HEADER, "MAIN_HEADER"},
    {XX_RAR_DS_FILE_HEADER, "FILE_HEADER"}, {XX_RAR_DS_SERVICE_HEADER, "SERVICE_HEADER"}, {XX_RAR_DS_ENCRYPTION_HEADER, "ENCRYPTION_HEADER"},
    {XX_RAR_DS_END_HEADER, "END_HEADER"},   {XX_RAR_DS_OTHER_HEADER, "OTHER_HEADER"},     {XX_RAR_DS_DATA, "DATA"}};

const char *xx_rar_data_struct_id_to_string(Abstractformat *self, uint32_t id)
{
    (void)self;
    for (size_t i = 0; i < sizeof(g_xx_rar_ds_names) / sizeof(g_xx_rar_ds_names[0]); ++i) {
        if ((uint32_t)g_xx_rar_ds_names[i].id == id) {
            return g_xx_rar_ds_names[i].name;
        }
    }
    return "UNKNOWN";
}

uint32_t xx_rar_data_struct_string_to_id(Abstractformat *self, const char *name)
{
    (void)self;
    if (!name) {
        return XX_RAR_DS_UNKNOWN;
    }
    for (size_t i = 0; i < sizeof(g_xx_rar_ds_names) / sizeof(g_xx_rar_ds_names[0]); ++i) {
        if (xx_str_cmp(name, g_xx_rar_ds_names[i].name) == 0) {
            return (uint32_t)g_xx_rar_ds_names[i].id;
        }
    }
    return XX_RAR_DS_UNKNOWN;
}

typedef struct xx_rar_ds_state_s {
    xx_data_struct *items;
    size_t count;
    size_t capacity;
} xx_rar_ds_state;

static void xx_rar_ds_state_free(void *pointer)
{
    xx_rar_ds_state *state = (xx_rar_ds_state *)pointer;
    if (state) {
        xx_mem_free(state->items);
        xx_mem_free(state);
    }
}

static bool xx_rar_ds_append(xx_rar_ds_state *state, uint32_t id, int64_t offset, int64_t address, int64_t entry_size, int64_t total_size, xx_data_struct_type_t type)
{
    xx_data_struct *resized;
    xx_data_struct *item;
    size_t new_capacity;
    if (!state || offset < 0 || entry_size < 0 || total_size < 0) {
        return false;
    }
    if (state->count == state->capacity) {
        new_capacity = state->capacity == 0 ? 16U : state->capacity * 2U;
        if (new_capacity < state->capacity || new_capacity > SIZE_MAX / sizeof(*state->items)) {
            return false;
        }
        resized = (xx_data_struct *)xx_mem_realloc(state->items, new_capacity * sizeof(*state->items));
        if (!resized) {
            return false;
        }
        state->items = resized;
        state->capacity = new_capacity;
    }
    item = &state->items[state->count++];
    item->id = id;
    item->offset = offset;
    item->address = address;
    item->entry_size = entry_size;
    item->total_size = total_size;
    item->count = 1;
    item->type = type;
    return true;
}

static xx_rar_data_struct_id_t xx_rar_block_ds_id(const xx_rar_block *block)
{
    if (!block) {
        return XX_RAR_DS_UNKNOWN;
    }
    if (block->version == XX_RAR_VERSION_4) {
        switch (block->type) {
            case XX_RAR4_HEADER_MAIN: return XX_RAR_DS_MAIN_HEADER;
            case XX_RAR4_HEADER_FILE: return XX_RAR_DS_FILE_HEADER;
            case XX_RAR4_HEADER_SERVICE: return XX_RAR_DS_SERVICE_HEADER;
            case XX_RAR4_HEADER_END: return XX_RAR_DS_END_HEADER;
            default: return XX_RAR_DS_OTHER_HEADER;
        }
    }
    switch (block->type) {
        case XX_RAR5_HEADER_MAIN: return XX_RAR_DS_MAIN_HEADER;
        case XX_RAR5_HEADER_FILE: return XX_RAR_DS_FILE_HEADER;
        case XX_RAR5_HEADER_SERVICE: return XX_RAR_DS_SERVICE_HEADER;
        case XX_RAR5_HEADER_CRYPT: return XX_RAR_DS_ENCRYPTION_HEADER;
        case XX_RAR5_HEADER_END: return XX_RAR_DS_END_HEADER;
        default: return XX_RAR_DS_OTHER_HEADER;
    }
}

xx_data_struct_state *xx_rar_create_data_structs_reading(Abstractformat *self, xx_pd_struct *pd)
{
    xx_data_struct_state *state;
    xx_rar_ds_state *rar_state;
    xx_rar *rar;
    int64_t offset;
    int64_t scan_end;
    int64_t device_size;

    if (!xx_format_handle_split_format(self, pd) || !self->device || (!self->base_info_handled && !xx_format_handle_base_info(self, pd)) || !self->is_valid) {
        return NULL;
    }
    rar = (xx_rar *)self;
    device_size = xx_io_total_size(self->device);
    scan_end = self->base_address + self->format_size;
    state = (xx_data_struct_state *)xx_mem_alloc(sizeof(*state));
    rar_state = (xx_rar_ds_state *)xx_mem_calloc(1, sizeof(*rar_state));
    if (!state || !rar_state) {
        xx_mem_free(state);
        xx_mem_free(rar_state);
        return NULL;
    }
    xx_data_struct_state_init(state, self);

    if (rar->signature_offset > self->base_address &&
        !xx_rar_ds_append(rar_state, XX_DATA_STRUCT_ID_RAW_DATA, self->base_address, self->is_mapped ? self->base_address : -1,
                          rar->signature_offset - self->base_address, rar->signature_offset - self->base_address, XX_DATA_STRUCT_TYPE_RAW_DATA)) {
        goto error;
    }
    {
        int64_t signature_size = rar->version == XX_RAR_VERSION_4 ? XX_RAR4_SIGNATURE_SIZE : XX_RAR5_SIGNATURE_SIZE;
        if (!xx_rar_ds_append(rar_state, XX_RAR_DS_SIGNATURE, rar->signature_offset, self->is_mapped ? rar->signature_offset : -1, signature_size, signature_size,
                              XX_DATA_STRUCT_TYPE_STRUCT)) {
            goto error;
        }
    }

    offset = rar->first_header_offset;
    while (offset < scan_end) {
        xx_rar_block block;
        xx_rar_data_struct_id_t id;
        xx_data_struct_type_t type;
        bool encrypted_tail = false;
        if (!xx_rar_parse_block(self->device, device_size, rar->version, offset, &block)) {
            goto error;
        }
        id = xx_rar_block_ds_id(&block);
        type = id == XX_RAR_DS_END_HEADER ? XX_DATA_STRUCT_TYPE_FOOTER : XX_DATA_STRUCT_TYPE_STRUCT;
        if (!xx_rar_ds_append(rar_state, id, block.offset, self->is_mapped ? block.offset : -1, block.header_size, block.header_size, type)) {
            goto error;
        }
        if (block.data_size > 0 && !xx_rar_ds_append(rar_state, XX_RAR_DS_DATA, block.data_offset, self->is_mapped ? block.data_offset : -1, block.data_size,
                                                     block.data_size, XX_DATA_STRUCT_TYPE_RAW_DATA)) {
            goto error;
        }
        encrypted_tail = (rar->version == XX_RAR_VERSION_4 && block.type == XX_RAR4_HEADER_MAIN && (block.flags & XX_RAR4_MAIN_FLAG_PASSWORD) != 0) ||
                         (rar->version == XX_RAR_VERSION_5 && block.type == XX_RAR5_HEADER_CRYPT);
        offset = block.next_offset;
        if (encrypted_tail) {
            if (offset < scan_end && !xx_rar_ds_append(rar_state, XX_DATA_STRUCT_ID_RAW_DATA, offset, self->is_mapped ? offset : -1, scan_end - offset, scan_end - offset,
                                                       XX_DATA_STRUCT_TYPE_RAW_DATA)) {
                goto error;
            }
            break;
        }
        if (id == XX_RAR_DS_END_HEADER) {
            break;
        }
    }

    state->internal_state = rar_state;
    state->free_internal = xx_rar_ds_state_free;
    state->total_structs = (int64_t)rar_state->count;
    if (rar_state->count != 0) {
        state->current_struct = rar_state->items[0];
        state->current_index = 0;
        state->has_struct = true;
    }
    return state;

error:
    xx_rar_ds_state_free(rar_state);
    xx_data_struct_state_free(state);
    return NULL;
}

const xx_data_struct *xx_rar_get_current_data_struct(Abstractformat *self, xx_data_struct_state *state)
{
    return self && state && state->format == self && state->has_struct ? &state->current_struct : NULL;
}

bool xx_rar_data_struct_move_to_next(Abstractformat *self, xx_data_struct_state *state, xx_pd_struct *pd)
{
    xx_rar_ds_state *rar_state;
    int64_t next;
    if (!self || !self->device || !state || state->format != self || !state->has_struct || !state->internal_state || (pd && xx_pd_is_stopped(pd))) {
        return false;
    }
    rar_state = (xx_rar_ds_state *)state->internal_state;
    next = state->current_index + 1;
    if (next < 0 || (size_t)next >= rar_state->count) {
        state->has_struct = false;
        return false;
    }
    state->current_struct = rar_state->items[next];
    state->current_index = next;
    state->has_struct = true;
    return true;
}

void xx_rar_free_data_structs_reading(Abstractformat *self, xx_data_struct_state *state)
{
    (void)self;
    xx_data_struct_state_free(state);
}

/* ========================================================================= */
/* --- Data structure field streaming                                     --- */
/* ========================================================================= */

static const xx_data_struct_field_desc g_xx_rar4_signature_fields[] = {{L"magic", L"uint32", 0, 4, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                       {L"magic_tail", L"uint16", 4, 2, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                       {L"version", L"uint8", 6, 1, XX_DATA_STRUCT_RECORD_PROPERTY_ID}};

static const xx_data_struct_field_desc g_xx_rar5_signature_fields[] = {{L"magic", L"uint32", 0, 4, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                       {L"magic_tail", L"uint16", 4, 2, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                       {L"version", L"uint8", 6, 1, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                       {L"reserved", L"uint8", 7, 1, XX_DATA_STRUCT_RECORD_PROPERTY_RESERVED}};

static const xx_data_struct_field_desc g_xx_rar4_base_fields[] = {{L"header_crc", L"uint16", 0, 2, XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM},
                                                                  {L"header_type", L"uint8", 2, 1, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                  {L"header_flags", L"uint16", 3, 2, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS},
                                                                  {L"header_size", L"uint16", 5, 2, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE}};

static const xx_data_struct_field_desc g_xx_rar4_file_fields[] = {
    {L"header_crc", L"uint16", 0, 2, XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM},        {L"header_type", L"uint8", 2, 1, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
    {L"header_flags", L"uint16", 3, 2, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS},   {L"header_size", L"uint16", 5, 2, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},
    {L"packed_size", L"uint32", 7, 4, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},     {L"unpacked_size", L"uint32", 11, 4, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},
    {L"host_os", L"uint8", 15, 1, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},         {L"file_crc", L"uint32", 16, 4, XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM},
    {L"file_time", L"uint32", 20, 4, XX_DATA_STRUCT_RECORD_PROPERTY_TIMESTAMP}, {L"unpack_version", L"uint8", 24, 1, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},
    {L"method", L"uint8", 25, 1, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},          {L"name_size", L"uint16", 26, 2, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},
    {L"attributes", L"uint32", 28, 4, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS}};

typedef struct xx_rar_value_desc_s {
    const wchar_t *name;
    const wchar_t *type;
    int64_t relative_offset;
    int64_t size;
    xx_data_struct_record_property_t property;
    uint64_t value;
} xx_rar_value_desc;

typedef struct xx_rar_record_state_s {
    const xx_data_struct_field_desc *fixed_fields;
    size_t fixed_count;
    xx_rar_value_desc values[6];
    size_t value_count;
    bool dynamic_values;
} xx_rar_record_state;

static void xx_rar_record_state_free(void *pointer)
{
    xx_mem_free(pointer);
}

static bool xx_rar_record_populate_dynamic(xx_io_device *device, int64_t parent_offset, xx_data_struct_record *record, const xx_rar_value_desc *field)
{
    char ascii_display[64];
    wchar_t display[64];
    int display_length;
    size_t display_index;
    if (!device || !record || !field || parent_offset < 0 || field->relative_offset < 0 || parent_offset > INT64_MAX - field->relative_offset) {
        return false;
    }
    if (!xx_data_struct_record_set_name(record, field->name) || !xx_data_struct_record_set_type(record, field->type)) {
        xx_data_struct_record_cleanup(record);
        return false;
    }
    record->offset = field->relative_offset;
    record->size = field->size;
    record->property = field->property;
    xx_var_set_u64(&record->value, field->value);
    if ((field->property & (XX_DATA_STRUCT_RECORD_PROPERTY_ID | XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS | XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM)) != 0) {
        display_length = xx_rt_snprintf(ascii_display, sizeof(ascii_display), "0x%llX", (unsigned long long)field->value);
    } else {
        display_length = xx_rt_snprintf(ascii_display, sizeof(ascii_display), "%llu", (unsigned long long)field->value);
    }
    if (display_length < 0 || (size_t)display_length >= sizeof(ascii_display)) {
        xx_data_struct_record_cleanup(record);
        return false;
    }
    for (display_index = 0U; display_index <= (size_t)display_length; ++display_index) {
        display[display_index] = (wchar_t)(unsigned char)ascii_display[display_index];
    }
    if (!xx_data_struct_record_set_display_value(record, display) ||
        (xx_rt_wcscmp(field->type, L"vint") == 0
             ? !xx_data_struct_record_set_raw_bytes(record, device, parent_offset + field->relative_offset, field->size)
             : !xx_data_struct_record_set_raw_uint(record, field->value, field->size))) {
        xx_data_struct_record_cleanup(record);
        return false;
    }
    return true;
}

static bool xx_rar_record_populate_current(Abstractformat *self, xx_data_struct_record_state *state, xx_rar_record_state *rar_state, size_t index)
{
    if (rar_state->dynamic_values) {
        return index < rar_state->value_count &&
               xx_rar_record_populate_dynamic(self->device, state->parent_struct.offset, &state->current_record, &rar_state->values[index]);
    }
    return index < rar_state->fixed_count &&
           xx_data_struct_record_populate(&state->current_record, self->device, state->parent_struct.offset, &rar_state->fixed_fields[index], false);
}

static void xx_rar_value_add(xx_rar_record_state *state, const wchar_t *name, const wchar_t *type, int64_t offset, int64_t size,
                             xx_data_struct_record_property_t property, uint64_t value)
{
    xx_rar_value_desc *field;
    if (!state || state->value_count >= sizeof(state->values) / sizeof(state->values[0])) {
        return;
    }
    field = &state->values[state->value_count++];
    field->name = name;
    field->type = type;
    field->relative_offset = offset;
    field->size = size;
    field->property = property;
    field->value = value;
}

xx_data_struct_record_state *xx_rar_create_data_struct_records_reading(Abstractformat *self, const xx_data_struct *data_struct, xx_pd_struct *pd)
{
    xx_data_struct_record_state *state;
    xx_rar_record_state *rar_state;
    xx_rar *rar;
    if (!xx_format_handle_split_format(self, pd) || !self->device || !data_struct || data_struct->type == XX_DATA_STRUCT_TYPE_RAW_DATA) {
        return NULL;
    }
    rar = (xx_rar *)self;
    state = (xx_data_struct_record_state *)xx_mem_alloc(sizeof(*state));
    rar_state = (xx_rar_record_state *)xx_mem_calloc(1, sizeof(*rar_state));
    if (!state || !rar_state) {
        xx_mem_free(state);
        xx_mem_free(rar_state);
        return NULL;
    }
    xx_data_struct_record_state_init(state, self, data_struct);

    if (data_struct->id == XX_RAR_DS_SIGNATURE) {
        if (rar->version == XX_RAR_VERSION_4) {
            rar_state->fixed_fields = g_xx_rar4_signature_fields;
            rar_state->fixed_count = sizeof(g_xx_rar4_signature_fields) / sizeof(g_xx_rar4_signature_fields[0]);
        } else {
            rar_state->fixed_fields = g_xx_rar5_signature_fields;
            rar_state->fixed_count = sizeof(g_xx_rar5_signature_fields) / sizeof(g_xx_rar5_signature_fields[0]);
        }
    } else if (rar->version == XX_RAR_VERSION_4) {
        if (data_struct->id == XX_RAR_DS_FILE_HEADER || data_struct->id == XX_RAR_DS_SERVICE_HEADER) {
            rar_state->fixed_fields = g_xx_rar4_file_fields;
            rar_state->fixed_count = sizeof(g_xx_rar4_file_fields) / sizeof(g_xx_rar4_file_fields[0]);
        } else {
            rar_state->fixed_fields = g_xx_rar4_base_fields;
            rar_state->fixed_count = sizeof(g_xx_rar4_base_fields) / sizeof(g_xx_rar4_base_fields[0]);
        }
    } else {
        xx_rar_block block;
        uint64_t header_data_size;
        int64_t device_size = xx_io_total_size(self->device);
        if (!xx_rar_parse_block(self->device, device_size, rar->version, data_struct->offset, &block)) {
            xx_rar_record_state_free(rar_state);
            xx_data_struct_record_state_free(state);
            return NULL;
        }
        header_data_size = (uint64_t)(block.header_size - 4 - block.header_size_width);
        rar_state->dynamic_values = true;
        xx_rar_value_add(rar_state, L"header_crc", L"uint32", 0, 4, XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM, xx_io_get_u32(self->device, block.offset, false));
        xx_rar_value_add(rar_state, L"header_size", L"vint", block.header_size_rel, block.header_size_width, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE, header_data_size);
        xx_rar_value_add(rar_state, L"header_type", L"vint", block.type_rel, block.type_width, XX_DATA_STRUCT_RECORD_PROPERTY_ID, block.type);
        xx_rar_value_add(rar_state, L"header_flags", L"vint", block.flags_rel, block.flags_width, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS, block.flags);
        if (block.extra_size_rel >= 0) {
            xx_rar_value_add(rar_state, L"extra_area_size", L"vint", block.extra_size_rel, block.extra_size_width, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE, block.extra_size);
        }
        if (block.data_size_rel >= 0) {
            xx_rar_value_add(rar_state, L"data_size", L"vint", block.data_size_rel, block.data_size_width, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE,
                             (uint64_t)block.data_size);
        }
    }

    if ((!rar_state->dynamic_values && rar_state->fixed_count == 0) || (rar_state->dynamic_values && rar_state->value_count == 0)) {
        xx_rar_record_state_free(rar_state);
        xx_data_struct_record_state_free(state);
        return NULL;
    }
    state->internal_state = rar_state;
    state->free_internal = xx_rar_record_state_free;
    state->total_records = (int64_t)(rar_state->dynamic_values ? rar_state->value_count : rar_state->fixed_count);
    if (!xx_rar_record_populate_current(self, state, rar_state, 0)) {
        xx_data_struct_record_state_free(state);
        return NULL;
    }
    state->current_index = 0;
    state->has_record = true;
    return state;
}

const xx_data_struct_record *xx_rar_get_current_data_struct_record(Abstractformat *self, xx_data_struct_record_state *state)
{
    return self && state && state->format == self && state->has_record ? &state->current_record : NULL;
}

bool xx_rar_data_struct_record_move_to_next(Abstractformat *self, xx_data_struct_record_state *state, xx_pd_struct *pd)
{
    xx_rar_record_state *rar_state;
    int64_t next;
    if (!self || !self->device || !state || state->format != self || !state->has_record || !state->internal_state || (pd && xx_pd_is_stopped(pd))) {
        return false;
    }
    rar_state = (xx_rar_record_state *)state->internal_state;
    next = state->current_index + 1;
    if (next < 0 || next >= state->total_records) {
        state->has_record = false;
        return false;
    }
    xx_data_struct_record_cleanup(&state->current_record);
    if (!xx_rar_record_populate_current(self, state, rar_state, (size_t)next)) {
        state->has_record = false;
        return false;
    }
    state->current_index = next;
    state->has_record = true;
    return true;
}

void xx_rar_free_data_struct_records_reading(Abstractformat *self, xx_data_struct_record_state *state)
{
    (void)self;
    xx_data_struct_record_state_free(state);
}

const StreamDataStructs *xx_rar_get_stream_datastructs(void)
{
    static const StreamDataStructs stream = {
        .data_struct_id_to_string = xx_rar_data_struct_id_to_string,
        .data_struct_string_to_id = xx_rar_data_struct_string_to_id,
        .create_data_structs_reading = xx_rar_create_data_structs_reading,
        .get_current_data_struct = xx_rar_get_current_data_struct,
        .data_struct_move_to_next = xx_rar_data_struct_move_to_next,
        .free_data_structs_reading = xx_rar_free_data_structs_reading,
        .create_data_struct_records_reading = xx_rar_create_data_struct_records_reading,
        .get_current_data_struct_record = xx_rar_get_current_data_struct_record,
        .data_struct_record_move_to_next = xx_rar_data_struct_record_move_to_next,
        .free_data_struct_records_reading = xx_rar_free_data_struct_records_reading,
    };
    return &stream;
}
