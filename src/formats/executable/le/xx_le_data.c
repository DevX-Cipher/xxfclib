/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#include "xx_le_data.h"
#include "xx_le_defs.h"
#include "xx_linear_internal.h"
#include "xxfclib/rt/xx_rt.h"
#include "xxfclib/data/xx_data.h"
#include "xxfclib/io/xx_io.h"
#include "xxfclib/memory/xx_memory.h"

#include <stdint.h>

typedef struct xx_linear_data_stream_s {
    xx_data_struct *items;
    size_t count;
} xx_linear_data_stream;

typedef struct xx_linear_record_stream_s {
    const xx_data_struct_field_desc *fields;
    size_t count;
} xx_linear_record_stream;

static const char *xx_linear_data_struct_id_to_string(Abstractformat *format, uint32_t id)
{
    (void)format;
    switch (id) {
        case XX_LINEAR_DATA_STRUCT_DOS_HEADER: return "IMAGE_DOS_HEADER";
        case XX_LINEAR_DATA_STRUCT_HEADER: return "LINEAR_EXECUTABLE_HEADER";
        case XX_LINEAR_DATA_STRUCT_OBJECT_TABLE: return "LINEAR_OBJECT_TABLE";
        case XX_LINEAR_DATA_STRUCT_PAGE_MAP: return "LINEAR_PAGE_MAP";
        case XX_LINEAR_DATA_STRUCT_RESOURCE_TABLE: return "LINEAR_RESOURCE_TABLE";
        case XX_LINEAR_DATA_STRUCT_NONRESIDENT_NAME_TABLE: return "NONRESIDENT_NAME_TABLE";
        case XX_LINEAR_DATA_STRUCT_DEBUG_DATA: return "DEBUG_DATA";
        case XX_DATA_STRUCT_ID_RAW_DATA: return "RAW_DATA";
        default: return "UNKNOWN";
    }
}

static uint32_t xx_linear_data_struct_string_to_id(Abstractformat *format, const char *name)
{
    uint32_t id;
    if (!name) return XX_LINEAR_DATA_STRUCT_UNKNOWN;
    for (id = XX_LINEAR_DATA_STRUCT_DOS_HEADER; id <= XX_LINEAR_DATA_STRUCT_DEBUG_DATA; ++id)
        if (xx_rt_strcmp(name, xx_linear_data_struct_id_to_string(format, id)) == 0) return id;
    return xx_rt_strcmp(name, "RAW_DATA") == 0 ? XX_DATA_STRUCT_ID_RAW_DATA : XX_LINEAR_DATA_STRUCT_UNKNOWN;
}

static void xx_linear_data_stream_free(void *pointer)
{
    xx_linear_data_stream *stream = (xx_linear_data_stream *)pointer;
    if (!stream) return;
    if (stream->items) xx_mem_free(stream->items);
    xx_mem_free(stream);
}

static bool xx_linear_data_stream_set(xx_data_struct_state *state, size_t index)
{
    xx_linear_data_stream *stream;
    if (!state || !(stream = (xx_linear_data_stream *)state->internal_state) || index >= stream->count) return false;
    state->current_struct = stream->items[index];
    state->current_index = (int64_t)index;
    state->has_struct = true;
    return true;
}

static bool xx_linear_append_data_struct(xx_linear_data_stream *stream, uint32_t id, int64_t offset, int64_t entry_size, uint64_t count, xx_data_struct_type_t type)
{
    xx_data_struct *item;
    if (!stream || !stream->items || stream->count >= 9U || entry_size < 0 || count > (uint64_t)INT64_MAX ||
        (count != 0U && (uint64_t)entry_size > (uint64_t)INT64_MAX / count))
        return false;
    item = &stream->items[stream->count++];
    xx_mem_zero(item, sizeof(*item));
    item->id = id;
    item->offset = offset;
    item->address = -1;
    item->entry_size = entry_size;
    item->count = count;
    item->total_size = entry_size * (int64_t)count;
    item->type = type;
    return true;
}

static xx_data_struct_state *xx_linear_create_data_structs_reading(Abstractformat *format, xx_pd_struct *pd)
{
    xx_linear_executable *linear = (xx_linear_executable *)format;
    xx_data_struct_state *state;
    xx_linear_data_stream *stream;
    int64_t header;
    int64_t page_record_size;
    if (!format || (!format->base_info_handled && !xx_linear_handle_impl(format, pd, linear->expected_signature))) return NULL;
    state = (xx_data_struct_state *)xx_mem_alloc(sizeof(*state));
    stream = (xx_linear_data_stream *)xx_mem_alloc(sizeof(*stream));
    if (!state || !stream) {
        if (state) xx_mem_free(state);
        if (stream) xx_mem_free(stream);
        return NULL;
    }
    xx_mem_zero(stream, sizeof(*stream));
    stream->items = (xx_data_struct *)xx_mem_alloc(9U * sizeof(*stream->items));
    if (!stream->items) {
        xx_mem_free(stream);
        xx_mem_free(state);
        return NULL;
    }
    header = format->base_address + linear->linear_offset;
    page_record_size = linear->signature == XX_LE_SIGNATURE ? 4 : 8;
    if (linear->linear_offset != 0U)
        (void)xx_linear_append_data_struct(stream, XX_LINEAR_DATA_STRUCT_DOS_HEADER, format->base_address, 64, 1, XX_DATA_STRUCT_TYPE_STRUCT);
    (void)xx_linear_append_data_struct(stream, XX_LINEAR_DATA_STRUCT_HEADER, header, XX_LINEAR_HEADER_CORE_SIZE, 1, XX_DATA_STRUCT_TYPE_STRUCT);
    if (linear->object_count != 0U)
        (void)xx_linear_append_data_struct(stream, XX_LINEAR_DATA_STRUCT_OBJECT_TABLE, header + linear->object_table_offset, XX_LINEAR_OBJECT_SIZE, linear->object_count,
                                           XX_DATA_STRUCT_TYPE_ENTRY);
    if (linear->module_page_count != 0U)
        (void)xx_linear_append_data_struct(stream, XX_LINEAR_DATA_STRUCT_PAGE_MAP, header + linear->object_page_map_offset, page_record_size, linear->module_page_count,
                                           XX_DATA_STRUCT_TYPE_ENTRY);
    if (linear->resource_count != 0U)
        (void)xx_linear_append_data_struct(stream, XX_LINEAR_DATA_STRUCT_RESOURCE_TABLE, header + linear->resource_table_offset, XX_LINEAR_RESOURCE_RECORD_SIZE,
                                           linear->resource_count, XX_DATA_STRUCT_TYPE_ENTRY);
    if (linear->nonresident_name_table_size != 0U)
        (void)xx_linear_append_data_struct(stream, XX_LINEAR_DATA_STRUCT_NONRESIDENT_NAME_TABLE, format->base_address + linear->nonresident_name_table_offset,
                                           linear->nonresident_name_table_size, 1, XX_DATA_STRUCT_TYPE_RAW_DATA);
    if (linear->debug_info_size != 0U)
        (void)xx_linear_append_data_struct(stream, XX_LINEAR_DATA_STRUCT_DEBUG_DATA, format->base_address + linear->debug_info_offset, linear->debug_info_size, 1,
                                           XX_DATA_STRUCT_TYPE_RAW_DATA);
    if (format->overlay_size > 0)
        (void)xx_linear_append_data_struct(stream, XX_DATA_STRUCT_ID_RAW_DATA, format->overlay_offset, format->overlay_size, 1, XX_DATA_STRUCT_TYPE_RAW_DATA);
    xx_data_struct_state_init(state, format);
    state->internal_state = stream;
    state->free_internal = xx_linear_data_stream_free;
    state->total_structs = (int64_t)stream->count;
    if (!xx_linear_data_stream_set(state, 0U)) {
        xx_data_struct_state_free(state);
        return NULL;
    }
    return state;
}

static const xx_data_struct *xx_linear_get_current_data_struct(Abstractformat *format, xx_data_struct_state *state)
{
    return format && state && state->format == format && state->has_struct ? &state->current_struct : NULL;
}

static bool xx_linear_data_struct_move_to_next(Abstractformat *format, xx_data_struct_state *state, xx_pd_struct *pd)
{
    (void)pd;
    if (!format || !state || state->format != format || state->current_index < 0) return false;
    if (!xx_linear_data_stream_set(state, (size_t)state->current_index + 1U)) {
        state->has_struct = false;
        return false;
    }
    return true;
}

static void xx_linear_free_data_structs_reading(Abstractformat *format, xx_data_struct_state *state)
{
    (void)format;
    xx_data_struct_state_free(state);
}

static const xx_data_struct_field_desc xx_linear_dos_fields[] = {
    {L"e_magic", L"uint16", 0, 2, XX_DATA_STRUCT_RECORD_PROPERTY_SIGNATURE},  {L"e_cblp", L"uint16", 2, 2, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},
    {L"e_cp", L"uint16", 4, 2, XX_DATA_STRUCT_RECORD_PROPERTY_COUNT},         {L"e_crlc", L"uint16", 6, 2, XX_DATA_STRUCT_RECORD_PROPERTY_COUNT},
    {L"e_cparhdr", L"uint16", 8, 2, XX_DATA_STRUCT_RECORD_PROPERTY_COUNT},     {L"e_minalloc", L"uint16", 10, 2, XX_DATA_STRUCT_RECORD_PROPERTY_COUNT},
    {L"e_maxalloc", L"uint16", 12, 2, XX_DATA_STRUCT_RECORD_PROPERTY_COUNT},   {L"e_ss", L"uint16", 14, 2, XX_DATA_STRUCT_RECORD_PROPERTY_VIRTUAL_ADDRESS},
    {L"e_sp", L"uint16", 16, 2, XX_DATA_STRUCT_RECORD_PROPERTY_VIRTUAL_ADDRESS},         {L"e_csum", L"uint16", 18, 2, XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM},
    {L"e_ip", L"uint16", 20, 2, XX_DATA_STRUCT_RECORD_PROPERTY_VIRTUAL_ADDRESS},         {L"e_cs", L"uint16", 22, 2, XX_DATA_STRUCT_RECORD_PROPERTY_VIRTUAL_ADDRESS},
    {L"e_lfarlc", L"uint16", 24, 2, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},   {L"e_ovno", L"uint16", 26, 2, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
    {L"e_res", L"uint16[4]", 28, 8, XX_DATA_STRUCT_RECORD_PROPERTY_RESERVED}, {L"e_oemid", L"uint16", 36, 2, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
    {L"e_oeminfo", L"uint16", 38, 2, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},    {L"e_res2", L"uint16[10]", 40, 20, XX_DATA_STRUCT_RECORD_PROPERTY_RESERVED},
    {L"e_lfanew", L"uint32", 60, 4, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET}};

static const xx_data_struct_field_desc xx_linear_header_fields[] = {
    {L"e32_magic", L"uint16", 0x00, 2, XX_DATA_STRUCT_RECORD_PROPERTY_ID},        {L"e32_border", L"uint8", 0x02, 1, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},
    {L"e32_worder", L"uint8", 0x03, 1, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},      {L"e32_cpu", L"uint16", 0x08, 2, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
    {L"e32_os", L"uint16", 0x0a, 2, XX_DATA_STRUCT_RECORD_PROPERTY_ID},           {L"e32_ver", L"uint32", 0x0c, 4, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},
    {L"e32_mflags", L"uint32", 0x10, 4, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS},    {L"e32_mpages", L"uint32", 0x14, 4, XX_DATA_STRUCT_RECORD_PROPERTY_COUNT},
    {L"e32_startobj", L"uint32", 0x18, 4, XX_DATA_STRUCT_RECORD_PROPERTY_ID},     {L"e32_eip", L"uint32", 0x1c, 4, XX_DATA_STRUCT_RECORD_PROPERTY_VIRTUAL_ADDRESS},
    {L"e32_stackobj", L"uint32", 0x20, 4, XX_DATA_STRUCT_RECORD_PROPERTY_ID},     {L"e32_esp", L"uint32", 0x24, 4, XX_DATA_STRUCT_RECORD_PROPERTY_VIRTUAL_ADDRESS},
    {L"e32_pagesize", L"uint32", 0x28, 4, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},   {L"e32_lastpagesize", L"uint32", 0x2c, 4, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},
    {L"e32_fixupsize", L"uint32", 0x30, 4, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},  {L"e32_ldrsize", L"uint32", 0x38, 4, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},
    {L"e32_objtab", L"uint32", 0x40, 4, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},   {L"e32_objcnt", L"uint32", 0x44, 4, XX_DATA_STRUCT_RECORD_PROPERTY_COUNT},
    {L"e32_objmap", L"uint32", 0x48, 4, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},   {L"e32_rsrctab", L"uint32", 0x50, 4, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
    {L"e32_rsrccnt", L"uint32", 0x54, 4, XX_DATA_STRUCT_RECORD_PROPERTY_COUNT},   {L"e32_enttab", L"uint32", 0x5c, 4, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
    {L"e32_impmod", L"uint32", 0x70, 4, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},   {L"e32_impmodcnt", L"uint32", 0x74, 4, XX_DATA_STRUCT_RECORD_PROPERTY_COUNT},
    {L"e32_datapage", L"uint32", 0x80, 4, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET}, {L"e32_nrestab", L"uint32", 0x88, 4, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
    {L"e32_cbnrestab", L"uint32", 0x8c, 4, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},  {L"e32_debuginfo", L"uint32", 0x98, 4, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
    {L"e32_debuglen", L"uint32", 0x9c, 4, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE}};

static const xx_data_struct_field_desc xx_linear_object_fields[] = {
    {L"o32_size", L"uint32", 0, 4, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},      {L"o32_base", L"uint32", 4, 4, XX_DATA_STRUCT_RECORD_PROPERTY_VIRTUAL_ADDRESS},
    {L"o32_flags", L"uint32", 8, 4, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS},    {L"o32_pagemap", L"uint32", 12, 4, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
    {L"o32_mapsize", L"uint32", 16, 4, XX_DATA_STRUCT_RECORD_PROPERTY_COUNT}, {L"o32_reserved", L"uint32", 20, 4, XX_DATA_STRUCT_RECORD_PROPERTY_RESERVED}};

static const xx_data_struct_field_desc xx_le_page_fields[] = {{L"o16_pagenum_hi", L"uint8", 0, 1, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
                                                              {L"o16_pagenum_mid", L"uint8", 1, 1, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
                                                              {L"o16_pagenum_lo", L"uint8", 2, 1, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
                                                              {L"o16_pageflags", L"uint8", 3, 1, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS}};

static const xx_data_struct_field_desc xx_lx_page_fields[] = {{L"o32_pagedataoffset", L"uint32", 0, 4, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
                                                              {L"o32_pagesize", L"uint16", 4, 2, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},
                                                              {L"o32_pageflags", L"uint16", 6, 2, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS}};

static const xx_data_struct_field_desc xx_linear_resource_fields[] = {{L"type", L"uint16", 0, 2, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                      {L"name", L"uint16", 2, 2, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                      {L"size", L"uint32", 4, 4, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},
                                                                      {L"object", L"uint16", 8, 2, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                      {L"offset", L"uint32", 10, 4, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET}};

static void xx_linear_record_stream_free(void *pointer)
{
    if (pointer) xx_mem_free(pointer);
}

static bool xx_linear_populate_record(Abstractformat *format, xx_data_struct_record_state *state, size_t index)
{
    xx_linear_record_stream *stream;
    if (!format || !format->device || !state || !(stream = (xx_linear_record_stream *)state->internal_state) || index >= stream->count) return false;
    xx_data_struct_field_desc field = stream->fields[index];
    const xx_linear_executable *linear = (const xx_linear_executable *)format;
    bool lx = linear->signature == XX_LX_SIGNATURE || linear->expected_signature == XX_LX_SIGNATURE;
    const wchar_t *comment = NULL;
    if (lx && state->parent_struct.id == XX_LINEAR_DATA_STRUCT_HEADER && field.rel_offset == 0x2c) {
        field.name = L"e32_pageshift";
        field.property = XX_DATA_STRUCT_RECORD_PROPERTY_NONE;
        comment = L"Left-shift count for page data offsets";
    }
    if (!xx_data_struct_record_populate(&state->current_record, format->device, state->parent_struct.offset, &field, false)) return false;
    if (state->parent_struct.id == XX_LINEAR_DATA_STRUCT_DOS_HEADER) {
        if (field.rel_offset == 2) comment = L"Bytes in final 512-byte page; 0 means 512";
        else if (field.rel_offset == 4) comment = L"512-byte pages";
        else if (field.rel_offset == 8 || field.rel_offset == 10 || field.rel_offset == 12) comment = L"16-byte paragraphs";
    } else if ((!lx && state->parent_struct.id == XX_LINEAR_DATA_STRUCT_HEADER && field.rel_offset == 0x2c) ||
               (lx && state->parent_struct.id == XX_LINEAR_DATA_STRUCT_PAGE_MAP && field.rel_offset == 4)) {
        if (xx_var_get_u64(&state->current_record.value) == 0) comment = L"0 means the header page size";
    }
    return !comment || xx_data_struct_record_set_comment(&state->current_record, comment);
}

static xx_data_struct_record_state *xx_linear_create_data_struct_records_reading(Abstractformat *format, const xx_data_struct *data_struct, xx_pd_struct *pd)
{
    const xx_data_struct_field_desc *fields = NULL;
    size_t count = 0U;
    xx_data_struct_record_state *state;
    xx_linear_record_stream *stream;
    xx_linear_executable *linear = (xx_linear_executable *)format;
    (void)pd;
    if (!format || !data_struct || data_struct->type == XX_DATA_STRUCT_TYPE_RAW_DATA) return NULL;
    switch (data_struct->id) {
        case XX_LINEAR_DATA_STRUCT_DOS_HEADER:
            fields = xx_linear_dos_fields;
            count = sizeof(xx_linear_dos_fields) / sizeof(xx_linear_dos_fields[0]);
            break;
        case XX_LINEAR_DATA_STRUCT_HEADER:
            fields = xx_linear_header_fields;
            count = sizeof(xx_linear_header_fields) / sizeof(xx_linear_header_fields[0]);
            break;
        case XX_LINEAR_DATA_STRUCT_OBJECT_TABLE:
            fields = xx_linear_object_fields;
            count = sizeof(xx_linear_object_fields) / sizeof(xx_linear_object_fields[0]);
            break;
        case XX_LINEAR_DATA_STRUCT_PAGE_MAP:
            if (linear->signature == XX_LE_SIGNATURE) {
                fields = xx_le_page_fields;
                count = sizeof(xx_le_page_fields) / sizeof(xx_le_page_fields[0]);
            } else {
                fields = xx_lx_page_fields;
                count = sizeof(xx_lx_page_fields) / sizeof(xx_lx_page_fields[0]);
            }
            break;
        case XX_LINEAR_DATA_STRUCT_RESOURCE_TABLE:
            fields = xx_linear_resource_fields;
            count = sizeof(xx_linear_resource_fields) / sizeof(xx_linear_resource_fields[0]);
            break;
        default: return NULL;
    }
    if (!format->device || xx_pd_is_stopped(pd) || data_struct->offset < 0 || data_struct->total_size < 0 ||
        !xx_io_check(format->device, data_struct->offset, data_struct->total_size)) return NULL;
    for (size_t i = 0; i < count; ++i) {
        if (fields[i].rel_offset < 0 || fields[i].size <= 0 || fields[i].rel_offset > data_struct->total_size ||
            fields[i].size > data_struct->total_size - fields[i].rel_offset) return NULL;
    }
    state = (xx_data_struct_record_state *)xx_mem_alloc(sizeof(*state));
    stream = (xx_linear_record_stream *)xx_mem_alloc(sizeof(*stream));
    if (!state || !stream) {
        if (state) xx_mem_free(state);
        if (stream) xx_mem_free(stream);
        return NULL;
    }
    xx_data_struct_record_state_init(state, format, data_struct);
    stream->fields = fields;
    stream->count = count;
    state->internal_state = stream;
    state->free_internal = xx_linear_record_stream_free;
    state->total_records = (int64_t)count;
    if (!xx_linear_populate_record(format, state, 0U)) {
        xx_data_struct_record_state_free(state);
        return NULL;
    }
    state->current_index = 0;
    state->has_record = true;
    return state;
}

static const xx_data_struct_record *xx_linear_get_current_data_struct_record(Abstractformat *format, xx_data_struct_record_state *state)
{
    return format && state && state->format == format && state->has_record ? &state->current_record : NULL;
}

static bool xx_linear_data_struct_record_move_to_next(Abstractformat *format, xx_data_struct_record_state *state, xx_pd_struct *pd)
{
    size_t next;
    (void)pd;
    if (!format || !state || state->format != format || state->current_index < 0) return false;
    next = (size_t)state->current_index + 1U;
    if (next >= (size_t)state->total_records) {
        state->has_record = false;
        return false;
    }
    xx_data_struct_record_cleanup(&state->current_record);
    if (!xx_linear_populate_record(format, state, next)) {
        state->has_record = false;
        return false;
    }
    state->current_index = (int64_t)next;
    state->has_record = true;
    return true;
}

static void xx_linear_free_data_struct_records_reading(Abstractformat *format, xx_data_struct_record_state *state)
{
    (void)format;
    xx_data_struct_record_state_free(state);
}

void xx_le_setup_data_struct_callbacks(xx_linear_executable *linear)
{
    if (!linear) return;
    linear->format.data_struct_id_to_string = xx_linear_data_struct_id_to_string;
    linear->format.data_struct_string_to_id = xx_linear_data_struct_string_to_id;
    linear->format.create_data_structs_reading = xx_linear_create_data_structs_reading;
    linear->format.get_current_data_struct = xx_linear_get_current_data_struct;
    linear->format.data_struct_move_to_next = xx_linear_data_struct_move_to_next;
    linear->format.free_data_structs_reading = xx_linear_free_data_structs_reading;
    linear->format.create_data_struct_records_reading = xx_linear_create_data_struct_records_reading;
    linear->format.get_current_data_struct_record = xx_linear_get_current_data_struct_record;
    linear->format.data_struct_record_move_to_next = xx_linear_data_struct_record_move_to_next;
    linear->format.free_data_struct_records_reading = xx_linear_free_data_struct_records_reading;
}
