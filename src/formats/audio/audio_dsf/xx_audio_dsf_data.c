/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AUDIO_DSF data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_dsf_header_fields[] = {
    SX_FIELD("chunk_id", "char[4]", 0, 4, SX_STRING),
    SX_FIELD("chunk_size", "uint64", 4, 8, SX_SIZE),
    SX_FIELD("file_size", "uint64", 12, 8, SX_SIZE),
    SX_FIELD("metadata_offset", "uint64", 20, 8, SX_OFFSET),
};
const sx_layout sx_st_dsf_header = {0x60080013U, "dsf_header", sx_st_dsf_header_fields, SX_COUNT(sx_st_dsf_header_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_dsf_format_fields[] = {
    SX_FIELD("chunk_id", "char[4]", 0, 4, SX_STRING),
    SX_FIELD("chunk_size", "uint64", 4, 8, SX_SIZE),
    SX_FIELD("format_version", "uint32", 12, 4, SX_NONE),
    SX_FIELD("format_id", "uint32", 16, 4, SX_ID),
    SX_FIELD("channel_type", "uint32", 20, 4, SX_ID),
    SX_FIELD("channel_count", "uint32", 24, 4, SX_COUNT_PROP),
    SX_FIELD("sample_rate", "uint32", 28, 4, SX_NONE),
    SX_FIELD("bits_per_sample", "uint32", 32, 4, SX_NONE),
    SX_FIELD("sample_count", "uint64", 36, 8, SX_COUNT_PROP),
    SX_FIELD("block_size_per_channel", "uint32", 44, 4, SX_SIZE),
    SX_FIELD("reserved", "uint32", 48, 4, SX_RESERVED),
};
const sx_layout sx_st_dsf_format = {0x60080014U, "dsf_format", sx_st_dsf_format_fields, SX_COUNT(sx_st_dsf_format_fields), SX_LE};
static const xx_data_struct_field_desc sx_st_dsf_data_fields[] = {
    SX_FIELD("chunk_id", "char[4]", 0, 4, SX_STRING),
    SX_FIELD("chunk_size", "uint64", 4, 8, SX_SIZE),
};
const sx_layout sx_st_dsf_data = {0x60080015U, "dsf_data", sx_st_dsf_data_fields, SX_COUNT(sx_st_dsf_data_fields), SX_LE};
bool sx_audio_dsf_build(sx_context*c)
{
    bool ok=false;
    ok=sx_add(c,&sx_st_dsf_header,0,28)&&sx_add(c,&sx_st_dsf_format,28,52)&&sx_add(c,&sx_st_dsf_data,80,12);
    return ok&&sx_st_finish(c);
}
