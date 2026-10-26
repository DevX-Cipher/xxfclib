/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#ifndef XX_PE_RESOURCES_INTERNAL_H
#define XX_PE_RESOURCES_INTERNAL_H

#include "xx_pe_stream_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <limits.h>

#define PE_RESOURCE_DEPTH 32U
#define PE_RESOURCE_BUDGET UINT64_C(1000000)
#define PE_METADATA_TEXT_LIMIT UINT32_C(1048576)

typedef struct pe_resource_frame {
    uint32_t relative;
    uint32_t count;
    uint32_t next;
    uint32_t selected_id;
    char *selected_name;
} pe_resource_frame;

typedef struct pe_resource_cursor {
    Abstractformat *format;
    uint32_t root_rva;
    uint32_t directory_size;
    pe_resource_frame frames[PE_RESOURCE_DEPTH];
    uint32_t depth;
    uint64_t budget;
    bool finished;
} pe_resource_cursor;

/* Metadata also traverses the resource tree when the public resources module
 * is disabled. Keep the traversal's record ownership private to this helper. */
static inline void pe_resource_record_cleanup(xx_resource_record *record)
{
    if (!record) return;
    xx_mem_free(record->type_name);
    xx_mem_free(record->name);
    xx_mem_free(record->language_name);
    xx_mem_zero(record, sizeof(*record));
    record->type_id = record->name_id = record->language_id = UINT32_MAX;
    record->offset = -1;
}

static inline void pe_resource_state_free(xx_resource_state *state)
{
    if (!state) return;
    pe_resource_record_cleanup(&state->current_record);
    if (state->free_internal && state->internal_state) state->free_internal(state->internal_state);
    xx_mem_free(state);
}

static inline bool pe_stream_fail(xx_pd_struct *pd, const char *message)
{
    xx_pd_set_error(pd, XXFC_ERR_IO, message);
    return false;
}

static inline bool pe_stream_allocation_failed(xx_pd_struct *pd, const char *message)
{
    xx_pd_set_error(pd, XXFC_ERR_OUT_OF_MEMORY, message);
    return false;
}

static inline bool pe_stream_cancelled(xx_pd_struct *pd)
{
    if (!xx_pd_is_stopped(pd)) return false;
    xx_pd_set_error(pd, XXFC_ERR_GENERIC, "PE streaming cancelled");
    return true;
}

static inline bool pe_read_u16(Abstractformat *format, int64_t offset, uint16_t *value, xx_pd_struct *pd)
{
    uint8_t bytes[2];
    if (!xx_pe_stream_read(format, offset, bytes, sizeof(bytes), pd)) return false;
    *value = (uint16_t)((uint16_t)bytes[0] | ((uint16_t)bytes[1] << 8));
    return true;
}

static inline bool pe_read_u32(Abstractformat *format, int64_t offset, uint32_t *value, xx_pd_struct *pd)
{
    uint8_t bytes[4];
    if (!xx_pe_stream_read(format, offset, bytes, sizeof(bytes), pd)) return false;
    *value = (uint32_t)bytes[0] | ((uint32_t)bytes[1] << 8) | ((uint32_t)bytes[2] << 16) | ((uint32_t)bytes[3] << 24);
    return true;
}

/* Resource and VERSIONINFO strings are UTF-16 on every host. Invalid isolated
 * surrogates use U+FFFD, without depending on the host wchar_t representation. */
static inline char *pe_utf16(Abstractformat *format, int64_t offset, uint32_t units, bool trim_zeroes, xx_pd_struct *pd)
{
    char *result;
    uint8_t *input;
    size_t used = 0U;
    uint32_t index;
    if (units > PE_METADATA_TEXT_LIMIT / 2U) {
        pe_stream_fail(pd, "PE UTF-16 string exceeds streaming limit");
        return NULL;
    }
    input = (uint8_t *)xx_mem_alloc((size_t)units * 2U + 1U);
    if (!input) {
        pe_stream_allocation_failed(pd, "Cannot allocate PE UTF-16 input");
        return NULL;
    }
    if (units && !xx_pe_stream_read(format, offset, input, (size_t)units * 2U, pd)) {
        xx_mem_free(input);
        return NULL;
    }
    if (trim_zeroes) {
        while (units && !input[(size_t)(units - 1U) * 2U] && !input[(size_t)(units - 1U) * 2U + 1U]) --units;
    }
    result = (char *)xx_mem_alloc((size_t)units * 3U + 1U);
    if (!result) {
        xx_mem_free(input);
        pe_stream_allocation_failed(pd, "Cannot allocate PE string");
        return NULL;
    }
    for (index = 0U; index < units; ++index) {
        uint16_t first = (uint16_t)((uint16_t)input[(size_t)index * 2U] | ((uint16_t)input[(size_t)index * 2U + 1U] << 8));
        uint32_t code;
        if (!(index & 255U) && pe_stream_cancelled(pd)) {
            xx_mem_free(input);
            xx_mem_free(result);
            return NULL;
        }
        code = first;
        if (first >= 0xd800U && first <= 0xdbffU) {
            uint16_t second = 0U;
            if (index + 1U < units) second = (uint16_t)((uint16_t)input[(size_t)(index + 1U) * 2U] | ((uint16_t)input[(size_t)(index + 1U) * 2U + 1U] << 8));
            if (second >= 0xdc00U && second <= 0xdfffU) {
                code = UINT32_C(0x10000) + (((uint32_t)first - 0xd800U) << 10) + second - 0xdc00U;
                ++index;
            } else code = UINT32_C(0xfffd);
        } else if (first >= 0xdc00U && first <= 0xdfffU) code = UINT32_C(0xfffd);
        if (code < 0x80U) result[used++] = (char)code;
        else if (code < 0x800U) {
            result[used++] = (char)(0xc0U | (code >> 6));
            result[used++] = (char)(0x80U | (code & 0x3fU));
        } else if (code < 0x10000U) {
            result[used++] = (char)(0xe0U | (code >> 12));
            result[used++] = (char)(0x80U | ((code >> 6) & 0x3fU));
            result[used++] = (char)(0x80U | (code & 0x3fU));
        } else {
            result[used++] = (char)(0xf0U | (code >> 18));
            result[used++] = (char)(0x80U | ((code >> 12) & 0x3fU));
            result[used++] = (char)(0x80U | ((code >> 6) & 0x3fU));
            result[used++] = (char)(0x80U | (code & 0x3fU));
        }
    }
    result[used] = '\0';
    xx_mem_free(input);
    return result;
}

static inline bool pe_resource_range(pe_resource_cursor *cursor, uint64_t relative, uint64_t size, int64_t *offset, xx_pd_struct *pd)
{
    if (relative > cursor->directory_size || size > (uint64_t)cursor->directory_size - relative || (uint64_t)cursor->root_rva + relative > UINT32_MAX)
        return pe_stream_fail(pd, "Malformed PE resource directory range");
    return xx_pe_stream_rva(cursor->format, (uint64_t)cursor->root_rva + relative, size, offset, pd);
}

static inline bool pe_resource_push(pe_resource_cursor *cursor, uint32_t relative, xx_pd_struct *pd)
{
    int64_t offset;
    uint16_t named;
    uint16_t ids;
    uint32_t index;
    pe_resource_frame *frame;
    if (cursor->depth >= PE_RESOURCE_DEPTH) return pe_stream_fail(pd, "PE resource directory depth limit exceeded");
    for (index = 0U; index < cursor->depth; ++index)
        if (cursor->frames[index].relative == relative) return pe_stream_fail(pd, "Cyclic PE resource directory");
    if (!pe_resource_range(cursor, relative, 16U, &offset, pd) || !pe_read_u16(cursor->format, offset + 12, &named, pd) ||
        !pe_read_u16(cursor->format, offset + 14, &ids, pd))
        return false;
    if (((uint32_t)named + ids) && !pe_resource_range(cursor, (uint64_t)relative + 16U, ((uint64_t)named + ids) * 8U, &offset, pd)) return false;
    frame = &cursor->frames[cursor->depth++];
    xx_mem_zero(frame, sizeof(*frame));
    frame->relative = relative;
    frame->count = (uint32_t)named + ids;
    frame->selected_id = UINT32_MAX;
    return true;
}

static inline bool pe_resource_name(pe_resource_cursor *cursor, pe_resource_frame *frame, uint32_t identifier, xx_pd_struct *pd)
{
    int64_t offset;
    uint16_t units;
    if (frame->selected_name) xx_mem_free(frame->selected_name);
    frame->selected_name = NULL;
    frame->selected_id = identifier;
    if (!(identifier & UINT32_C(0x80000000))) return true;
    frame->selected_id = UINT32_MAX;
    identifier &= UINT32_C(0x7fffffff);
    if (!pe_resource_range(cursor, identifier, 2U, &offset, pd) || !pe_read_u16(cursor->format, offset, &units, pd)) return false;
    if (!units) {
        frame->selected_name = xx_str_dup("");
        if (!frame->selected_name) return pe_stream_allocation_failed(pd, "Cannot allocate PE resource name");
    } else {
        if (!pe_resource_range(cursor, (uint64_t)identifier + 2U, (uint64_t)units * 2U, &offset, pd)) return false;
        frame->selected_name = pe_utf16(cursor->format, offset, units, false, pd);
    }
    return frame->selected_name != NULL;
}

static inline void pe_resource_cursor_free(void *pointer)
{
    pe_resource_cursor *cursor = (pe_resource_cursor *)pointer;
    uint32_t index;
    if (!cursor) return;
    for (index = 0U; index < cursor->depth; ++index)
        if (cursor->frames[index].selected_name) xx_mem_free(cursor->frames[index].selected_name);
    xx_mem_free(cursor);
}

static inline bool pe_resource_next(xx_resource_state *state, xx_pd_struct *pd)
{
    pe_resource_cursor *cursor = (pe_resource_cursor *)state->internal_state;
    pe_resource_record_cleanup(&state->current_record);
    state->has_record = false;
    if (state->failed || cursor->finished) return false;
    while (cursor->depth) {
        pe_resource_frame *frame = &cursor->frames[cursor->depth - 1U];
        int64_t entry;
        uint32_t identifier;
        uint32_t child;
        uint32_t data_rva;
        uint32_t data_size;
        uint32_t code_page;
        uint32_t index;
        if (pe_stream_cancelled(pd)) goto fail;
        if (frame->next == frame->count) {
            if (frame->selected_name) xx_mem_free(frame->selected_name);
            frame->selected_name = NULL;
            --cursor->depth;
            continue;
        }
        if (!cursor->budget--) {
            pe_stream_fail(pd, "PE resource traversal budget exceeded");
            goto fail;
        }
        if (!pe_resource_range(cursor, (uint64_t)frame->relative + 16U + (uint64_t)frame->next++ * 8U, 8U, &entry, pd) ||
            !pe_read_u32(cursor->format, entry, &identifier, pd) || !pe_read_u32(cursor->format, entry + 4, &child, pd) ||
            !pe_resource_name(cursor, frame, identifier, pd))
            goto fail;
        if (child & UINT32_C(0x80000000)) {
            if (!pe_resource_push(cursor, child & UINT32_C(0x7fffffff), pd)) goto fail;
            continue;
        }
        if (!pe_resource_range(cursor, child, 16U, &entry, pd) || !pe_read_u32(cursor->format, entry, &data_rva, pd) ||
            !pe_read_u32(cursor->format, entry + 4, &data_size, pd) || !pe_read_u32(cursor->format, entry + 8, &code_page, pd))
            goto fail;
        if (data_size) {
            if (!xx_pe_stream_rva(cursor->format, data_rva, data_size, &state->current_record.offset, pd)) goto fail;
        } else state->current_record.offset = -1;
        state->current_record.size = data_size;
        state->current_record.code_page = code_page;
        state->current_record.type_id = UINT32_MAX;
        state->current_record.name_id = UINT32_MAX;
        state->current_record.language_id = UINT32_MAX;
        for (index = 0U; index < cursor->depth && index < 3U; ++index) {
            uint32_t *id = index == 0U ? &state->current_record.type_id : index == 1U ? &state->current_record.name_id : &state->current_record.language_id;
            char **name = index == 0U ? &state->current_record.type_name : index == 1U ? &state->current_record.name : &state->current_record.language_name;
            *id = cursor->frames[index].selected_id;
            if (cursor->frames[index].selected_name) {
                *name = xx_str_dup(cursor->frames[index].selected_name);
                if (!*name) {
                    pe_stream_allocation_failed(pd, "Cannot allocate PE resource name");
                    goto fail;
                }
            }
        }
        ++state->current_index;
        state->has_record = true;
        return true;
    }
    cursor->finished = true;
    state->total_records = state->current_index + 1;
    return false;
fail:
    pe_resource_record_cleanup(&state->current_record);
    state->failed = true;
    cursor->finished = true;
    return false;
}

static inline xx_resource_state *pe_resource_stream_create(Abstractformat *format, xx_pd_struct *pd)
{
    xx_pe *pe = (xx_pe *)format;
    xx_resource_state *state;
    pe_resource_cursor *cursor;
    if (!xx_pe_stream_prepare(format, pd)) return NULL;
    state = (xx_resource_state *)xx_mem_calloc(1U, sizeof(*state));
    cursor = (pe_resource_cursor *)xx_mem_calloc(1U, sizeof(*cursor));
    if (!state || !cursor) {
        if (state) xx_mem_free(state);
        if (cursor) xx_mem_free(cursor);
        pe_stream_allocation_failed(pd, "Cannot allocate PE resource cursor");
        return NULL;
    }
    state->format = format;
    state->current_index = -1;
    state->total_records = -1;
    state->internal_state = cursor;
    state->free_internal = pe_resource_cursor_free;
    cursor->format = format;
    cursor->root_rva = pe->data_directory_rva[2];
    cursor->directory_size = pe->data_directory_size[2];
    cursor->budget = PE_RESOURCE_BUDGET;
    if (!cursor->root_rva && !cursor->directory_size) {
        cursor->finished = true;
        state->total_records = 0;
        return state;
    }
    if (!cursor->root_rva || cursor->directory_size < 16U) {
        pe_stream_fail(pd, "Malformed PE resource directory");
        pe_resource_state_free(state);
        return NULL;
    }
    if (!pe_resource_push(cursor, 0U, pd)) {
        pe_resource_state_free(state);
        return NULL;
    }
    if (!pe_resource_next(state, pd) && state->failed) {
        pe_resource_state_free(state);
        return NULL;
    }
    return state;
}

static inline const xx_resource_record *pe_resource_stream_current(Abstractformat *format, xx_resource_state *state)
{
    return state && state->format == format && state->has_record ? &state->current_record : NULL;
}

static inline bool pe_resource_stream_next(Abstractformat *format, xx_resource_state *state, xx_pd_struct *pd)
{
    if (!state || state->format != format || !state->internal_state) return false;
    return pe_resource_next(state, pd);
}

static inline void pe_resource_stream_free(Abstractformat *format, xx_resource_state *state)
{
    (void)format;
    pe_resource_state_free(state);
}

#endif
