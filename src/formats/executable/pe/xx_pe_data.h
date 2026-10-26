/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#ifndef XXFCLIB_PE_DATA_INTERNAL_H
#define XXFCLIB_PE_DATA_INTERNAL_H

#include "xxfclib/formats/xx_format_streams.h"
#include "xxfclib/formats/executable/pe/xx_pe.h"

const StreamDataStructs *xx_pe_get_stream_datastructs(void);
const char *xx_pe_data_struct_id_to_string(Abstractformat *format, uint32_t id);
uint32_t xx_pe_data_struct_string_to_id(Abstractformat *format, const char *name);
xx_data_struct_record_state *xx_pe_create_data_struct_records_reading(Abstractformat *format, const xx_data_struct *ds, xx_pd_struct *pd);

const xx_data_struct *xx_pe_get_current_data_struct(Abstractformat *format, xx_data_struct_state *state);
bool xx_pe_data_struct_move_to_next(Abstractformat *format, xx_data_struct_state *state, xx_pd_struct *pd);
void xx_pe_free_data_structs_reading(Abstractformat *format, xx_data_struct_state *state);
const xx_data_struct_record *xx_pe_get_current_data_struct_record(Abstractformat *format, xx_data_struct_record_state *state);
bool xx_pe_data_struct_record_move_to_next(Abstractformat *format, xx_data_struct_record_state *state, xx_pd_struct *pd);
void xx_pe_free_data_struct_records_reading(Abstractformat *format, xx_data_struct_record_state *state);

/* Internal composition hooks for readers that extend a PE container. */
typedef struct pe_data_stream_s xx_pe_data_stream;
typedef bool (*xx_pe_data_extension)(xx_pe *pe, xx_pe_data_stream *stream, const xx_memory_map *map, xx_pd_struct *pd);
xx_data_struct_state *xx_pe_create_data_structs_reading_extended(Abstractformat *format, xx_pe_data_extension extension, xx_pd_struct *pd);
bool xx_pe_data_append_absolute(xx_pe *pe, xx_pe_data_stream *stream, uint32_t id, int64_t offset, uint64_t entry_size, uint64_t total_size, uint64_t count,
                                xx_data_struct_type_t type);
bool xx_pe_data_append_raw(xx_pe *pe, xx_pe_data_stream *stream, uint32_t id, int64_t offset, uint64_t size);
bool xx_pe_data_rva_range(const xx_pe *pe, const xx_memory_map *map, uint64_t rva, uint64_t size, int64_t *offset);
uint64_t xx_pe_data_cstring_size(const xx_pe *pe, int64_t offset, uint64_t maximum);
xx_data_struct_record_state *xx_pe_data_create_records_with_fields(Abstractformat *format, const xx_data_struct *ds, const xx_data_struct_field_desc *fields,
                                                                   size_t count, xx_pd_struct *pd);

#endif /* XXFCLIB_PE_DATA_INTERNAL_H */
