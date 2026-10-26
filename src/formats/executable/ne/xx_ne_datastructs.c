/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#include "xxfclib/formats/xx_format_streams.h"
#include "xx_ne_datastructs_internal.h"

typedef struct xx_ne_data_stream_s {
    xx_data_struct *items;
    size_t count;
} xx_ne_data_stream;

typedef struct xx_ne_record_stream_s {
    const xx_data_struct_field_desc *fields;
    size_t count;
} xx_ne_record_stream;

static const char *xx_ne_data_struct_id_to_string(Abstractformat *format, uint32_t id)
{
    (void)format;
    switch (id) {
        case XX_NE_DATA_STRUCT_DOS_HEADER: return "IMAGE_DOS_HEADER";
        case XX_NE_DATA_STRUCT_HEADER: return "IMAGE_OS2_HEADER";
        case XX_NE_DATA_STRUCT_SEGMENT_TABLE: return "NE_SEGMENT_TABLE";
        case XX_NE_DATA_STRUCT_RESOURCE_TABLE: return "NE_RESOURCE_TABLE";
        case XX_NE_DATA_STRUCT_ENTRY_TABLE: return "NE_ENTRY_TABLE";
        case XX_NE_DATA_STRUCT_NONRESIDENT_NAME_TABLE: return "NE_NONRESIDENT_NAME_TABLE";
        case XX_DATA_STRUCT_ID_RAW_DATA: return "RAW_DATA";
        default: return "UNKNOWN";
    }
}

static uint32_t xx_ne_data_struct_string_to_id(Abstractformat *format, const char *name)
{
    uint32_t id;
    (void)format;
    if (!name) return XX_NE_DATA_STRUCT_UNKNOWN;
    for (id = XX_NE_DATA_STRUCT_DOS_HEADER; id <= XX_NE_DATA_STRUCT_NONRESIDENT_NAME_TABLE; ++id) {
        if (xx_rt_strcmp(name, xx_ne_data_struct_id_to_string(format, id)) == 0) return id;
    }
    return xx_rt_strcmp(name, "RAW_DATA") == 0 ? XX_DATA_STRUCT_ID_RAW_DATA : XX_NE_DATA_STRUCT_UNKNOWN;
}

static void xx_ne_data_stream_free(void *pointer)
{
    xx_ne_data_stream *stream = (xx_ne_data_stream *)pointer;
    if (!stream) return;
    if (stream->items) xx_mem_free(stream->items);
    xx_mem_free(stream);
}

static bool xx_ne_data_stream_set(xx_data_struct_state *state, size_t index)
{
    xx_ne_data_stream *stream;
    if (!state || !(stream = (xx_ne_data_stream *)state->internal_state) || index >= stream->count) return false;
    state->current_struct = stream->items[index];
    state->current_index = (int64_t)index;
    state->has_struct = true;
    return true;
}

static bool xx_ne_append_data_struct(const Abstractformat *format, xx_ne_data_stream *stream, uint32_t id, int64_t offset, int64_t entry_size, uint64_t count,
                                     xx_data_struct_type_t type)
{
    xx_data_struct *item;
    int64_t total;
    int64_t total_size;
    if (!stream || !stream->items || stream->count >= 8U || entry_size < 0 || count > (uint64_t)INT64_MAX ||
        (count != 0U && (uint64_t)entry_size > (uint64_t)INT64_MAX / count))
        return false;
    total_size = entry_size * (int64_t)count;
    total = format && format->device ? xx_io_total_size(format->device) : -1;
    if (!format || format->base_address < 0 || total < format->base_address || offset < format->base_address || offset > total || total_size > total - offset)
        return false;
    item = &stream->items[stream->count++];
    xx_mem_zero(item, sizeof(*item));
    item->id = id;
    item->offset = offset;
    item->address = -1;
    item->entry_size = entry_size;
    item->count = count;
    item->total_size = total_size;
    item->type = type;
    return true;
}

static xx_data_struct_state *xx_ne_create_data_structs_reading(Abstractformat *format, xx_pd_struct *pd)
{
    xx_ne *ne = (xx_ne *)format;
    xx_data_struct_state *state;
    xx_ne_data_stream *stream;
    uint64_t ne_base;
    if (!format || (!format->base_info_handled && !xx_ne_handle_base_info(format, pd))) return NULL;
    state = (xx_data_struct_state *)xx_mem_alloc(sizeof(*state));
    stream = (xx_ne_data_stream *)xx_mem_alloc(sizeof(*stream));
    if (!state || !stream) {
        if (state) xx_mem_free(state);
        if (stream) xx_mem_free(stream);
        return NULL;
    }
    xx_mem_zero(stream, sizeof(*stream));
    stream->items = (xx_data_struct *)xx_mem_alloc(8U * sizeof(*stream->items));
    if (!stream->items) {
        xx_mem_free(stream);
        xx_mem_free(state);
        return NULL;
    }
    ne_base = (uint64_t)format->base_address + ne->ne_offset;
    (void)xx_ne_append_data_struct(format, stream, XX_NE_DATA_STRUCT_DOS_HEADER, format->base_address, 64, 1, XX_DATA_STRUCT_TYPE_STRUCT);
    (void)xx_ne_append_data_struct(format, stream, XX_NE_DATA_STRUCT_HEADER, (int64_t)ne_base, 64, 1, XX_DATA_STRUCT_TYPE_STRUCT);
    if (ne->parsed_segment_count != 0U)
        (void)xx_ne_append_data_struct(format, stream, XX_NE_DATA_STRUCT_SEGMENT_TABLE, (int64_t)(ne_base + ne->segment_table_offset), 8,
                                       ne->parsed_segment_count,
                                       XX_DATA_STRUCT_TYPE_ENTRY);
    if (ne->parsed_entry_table_size != 0U)
        (void)xx_ne_append_data_struct(format, stream, XX_NE_DATA_STRUCT_ENTRY_TABLE, (int64_t)(ne_base + ne->entry_table_offset), ne->parsed_entry_table_size, 1,
                                       XX_DATA_STRUCT_TYPE_RAW_DATA);
    if (ne->parsed_resource_table_size != 0U)
        (void)xx_ne_append_data_struct(format, stream, XX_NE_DATA_STRUCT_RESOURCE_TABLE, (int64_t)(ne_base + ne->resource_table_offset),
                                       ne->parsed_resource_table_size, 1, XX_DATA_STRUCT_TYPE_RAW_DATA);
    if (ne->parsed_nonresident_name_table_size != 0U)
        (void)xx_ne_append_data_struct(format, stream, XX_NE_DATA_STRUCT_NONRESIDENT_NAME_TABLE, format->base_address + ne->nonresident_name_table_offset,
                                       ne->parsed_nonresident_name_table_size, 1, XX_DATA_STRUCT_TYPE_RAW_DATA);
    if (format->overlay_size > 0)
        (void)xx_ne_append_data_struct(format, stream, XX_DATA_STRUCT_ID_RAW_DATA, format->overlay_offset, format->overlay_size, 1, XX_DATA_STRUCT_TYPE_RAW_DATA);

    xx_data_struct_state_init(state, format);
    state->internal_state = stream;
    state->free_internal = xx_ne_data_stream_free;
    state->total_structs = (int64_t)stream->count;
    if (!xx_ne_data_stream_set(state, 0U)) {
        xx_data_struct_state_free(state);
        return NULL;
    }
    return state;
}

static const xx_data_struct *xx_ne_get_current_data_struct(Abstractformat *format, xx_data_struct_state *state)
{
    return format && state && state->format == format && state->has_struct ? &state->current_struct : NULL;
}

static bool xx_ne_data_struct_move_to_next(Abstractformat *format, xx_data_struct_state *state, xx_pd_struct *pd)
{
    (void)pd;
    if (!format || !state || state->format != format || state->current_index < 0) return false;
    if (!xx_ne_data_stream_set(state, (size_t)state->current_index + 1U)) {
        state->has_struct = false;
        return false;
    }
    return true;
}

static void xx_ne_free_data_structs_reading(Abstractformat *format, xx_data_struct_state *state)
{
    (void)format;
    xx_data_struct_state_free(state);
}

static const xx_data_struct_field_desc xx_ne_dos_fields[] = {
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

static const xx_data_struct_field_desc xx_ne_header_fields[] = {{L"ne_magic", L"uint16", 0x00, 2, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                {L"ne_ver", L"uint8", 0x02, 1, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},
                                                                {L"ne_rev", L"uint8", 0x03, 1, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},
                                                                {L"ne_enttab", L"uint16", 0x04, 2, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
                                                                {L"ne_cbenttab", L"uint16", 0x06, 2, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},
                                                                {L"ne_crc", L"uint32", 0x08, 4, XX_DATA_STRUCT_RECORD_PROPERTY_CHECKSUM},
                                                                {L"ne_flags", L"uint16", 0x0c, 2, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS},
                                                                {L"ne_autodata", L"uint16", 0x0e, 2, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                {L"ne_heap", L"uint16", 0x10, 2, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},
                                                                {L"ne_stack", L"uint16", 0x12, 2, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},
                                                                {L"ne_csip", L"uint32", 0x14, 4, XX_DATA_STRUCT_RECORD_PROPERTY_VIRTUAL_ADDRESS},
                                                                {L"ne_sssp", L"uint32", 0x18, 4, XX_DATA_STRUCT_RECORD_PROPERTY_VIRTUAL_ADDRESS},
                                                                {L"ne_cseg", L"uint16", 0x1c, 2, XX_DATA_STRUCT_RECORD_PROPERTY_COUNT},
                                                                {L"ne_cmod", L"uint16", 0x1e, 2, XX_DATA_STRUCT_RECORD_PROPERTY_COUNT},
                                                                {L"ne_cbnrestab", L"uint16", 0x20, 2, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},
                                                                {L"ne_segtab", L"uint16", 0x22, 2, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
                                                                {L"ne_rsrctab", L"uint16", 0x24, 2, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
                                                                {L"ne_restab", L"uint16", 0x26, 2, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
                                                                {L"ne_modtab", L"uint16", 0x28, 2, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
                                                                {L"ne_imptab", L"uint16", 0x2a, 2, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
                                                                {L"ne_nrestab", L"uint32", 0x2c, 4, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
                                                                {L"ne_cmovent", L"uint16", 0x30, 2, XX_DATA_STRUCT_RECORD_PROPERTY_COUNT},
                                                                {L"ne_align", L"uint16", 0x32, 2, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},
                                                                {L"ne_cres", L"uint16", 0x34, 2, XX_DATA_STRUCT_RECORD_PROPERTY_COUNT},
                                                                {L"ne_exetyp", L"uint8", 0x36, 1, XX_DATA_STRUCT_RECORD_PROPERTY_ID},
                                                                {L"ne_flagsothers", L"uint8", 0x37, 1, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS},
                                                                {L"ne_pretthunks", L"uint16", 0x38, 2, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
                                                                {L"ne_psegrefbytes", L"uint16", 0x3a, 2, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
                                                                {L"ne_swaparea", L"uint16", 0x3c, 2, XX_DATA_STRUCT_RECORD_PROPERTY_NONE},
                                                                {L"ne_expver", L"uint16", 0x3e, 2, XX_DATA_STRUCT_RECORD_PROPERTY_NONE}};

static const xx_data_struct_field_desc xx_ne_segment_fields[] = {{L"FileOffset", L"uint16", 0, 2, XX_DATA_STRUCT_RECORD_PROPERTY_OFFSET},
                                                                 {L"FileSize", L"uint16", 2, 2, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE},
                                                                 {L"Flags", L"uint16", 4, 2, XX_DATA_STRUCT_RECORD_PROPERTY_FLAGS},
                                                                 {L"MinimumAllocation", L"uint16", 6, 2, XX_DATA_STRUCT_RECORD_PROPERTY_SIZE}};

static void xx_ne_record_stream_free(void *pointer)
{
    if (pointer) xx_mem_free(pointer);
}

static bool xx_ne_populate_record(Abstractformat *format, xx_data_struct_record_state *state, size_t index)
{
    xx_ne_record_stream *stream;
    if (!format || !format->device || !state || !(stream = (xx_ne_record_stream *)state->internal_state) || index >= stream->count) return false;
    const xx_data_struct_field_desc *field = &stream->fields[index];
    if (!xx_data_struct_record_populate(&state->current_record, format->device, state->parent_struct.offset, field, false)) return false;
    const wchar_t *comment = NULL;
    if (state->parent_struct.id == XX_NE_DATA_STRUCT_DOS_HEADER) {
        if (field->rel_offset == 2) comment = L"Bytes in final 512-byte page; 0 means 512";
        else if (field->rel_offset == 4) comment = L"512-byte pages";
        else if (field->rel_offset == 8 || field->rel_offset == 10 || field->rel_offset == 12) comment = L"16-byte paragraphs";
    } else if (state->parent_struct.id == XX_NE_DATA_STRUCT_HEADER && field->rel_offset == 0x32) {
        comment = L"Logical-sector alignment shift count";
    } else if (state->parent_struct.id == XX_NE_DATA_STRUCT_SEGMENT_TABLE) {
        if (field->rel_offset == 0) comment = L"Logical sectors; scale by 2^ne_align";
        else if ((field->rel_offset == 2 || field->rel_offset == 6) && xx_var_get_u64(&state->current_record.value) == 0)
            comment = L"65536 Bytes (encoded as 0)";
    }
    return !comment || xx_data_struct_record_set_comment(&state->current_record, comment);
}

static xx_data_struct_record_state *xx_ne_create_data_struct_records_reading(Abstractformat *format, const xx_data_struct *data_struct, xx_pd_struct *pd)
{
    const xx_data_struct_field_desc *fields = NULL;
    size_t count = 0U;
    xx_data_struct_record_state *state;
    xx_ne_record_stream *stream;
    (void)pd;
    if (!format || !data_struct || data_struct->type == XX_DATA_STRUCT_TYPE_RAW_DATA) return NULL;
    switch (data_struct->id) {
        case XX_NE_DATA_STRUCT_DOS_HEADER:
            fields = xx_ne_dos_fields;
            count = sizeof(xx_ne_dos_fields) / sizeof(xx_ne_dos_fields[0]);
            break;
        case XX_NE_DATA_STRUCT_HEADER:
            fields = xx_ne_header_fields;
            count = sizeof(xx_ne_header_fields) / sizeof(xx_ne_header_fields[0]);
            break;
        case XX_NE_DATA_STRUCT_SEGMENT_TABLE:
            fields = xx_ne_segment_fields;
            count = sizeof(xx_ne_segment_fields) / sizeof(xx_ne_segment_fields[0]);
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
    stream = (xx_ne_record_stream *)xx_mem_alloc(sizeof(*stream));
    if (!state || !stream) {
        if (state) xx_mem_free(state);
        if (stream) xx_mem_free(stream);
        return NULL;
    }
    xx_data_struct_record_state_init(state, format, data_struct);
    stream->fields = fields;
    stream->count = count;
    state->internal_state = stream;
    state->free_internal = xx_ne_record_stream_free;
    state->total_records = (int64_t)count;
    if (!xx_ne_populate_record(format, state, 0U)) {
        xx_data_struct_record_state_free(state);
        return NULL;
    }
    state->current_index = 0;
    state->has_record = true;
    return state;
}

static const xx_data_struct_record *xx_ne_get_current_data_struct_record(Abstractformat *format, xx_data_struct_record_state *state)
{
    return format && state && state->format == format && state->has_record ? &state->current_record : NULL;
}

static bool xx_ne_data_struct_record_move_to_next(Abstractformat *format, xx_data_struct_record_state *state, xx_pd_struct *pd)
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
    if (!xx_ne_populate_record(format, state, next)) {
        state->has_record = false;
        return false;
    }
    state->current_index = (int64_t)next;
    state->has_record = true;
    return true;
}

static void xx_ne_free_data_struct_records_reading(Abstractformat *format, xx_data_struct_record_state *state)
{
    (void)format;
    xx_data_struct_record_state_free(state);
}


const StreamDataStructs *xx_ne_get_stream_datastructs(void)
{
    static const StreamDataStructs stream = {
        .data_struct_id_to_string = xx_ne_data_struct_id_to_string,
        .data_struct_string_to_id = xx_ne_data_struct_string_to_id,
        .create_data_structs_reading = xx_ne_create_data_structs_reading,
        .get_current_data_struct = xx_ne_get_current_data_struct,
        .data_struct_move_to_next = xx_ne_data_struct_move_to_next,
        .free_data_structs_reading = xx_ne_free_data_structs_reading,
        .create_data_struct_records_reading = xx_ne_create_data_struct_records_reading,
        .get_current_data_struct_record = xx_ne_get_current_data_struct_record,
        .data_struct_record_move_to_next = xx_ne_data_struct_record_move_to_next,
        .free_data_struct_records_reading = xx_ne_free_data_struct_records_reading,
    };
    return &stream;
}
