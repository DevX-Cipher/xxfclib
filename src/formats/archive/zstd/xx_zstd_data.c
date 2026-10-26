/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Zstandard data structures, moved out of the archive schema family. */
#include "../../xx_format_schema_archive.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_a_zstd_frame_header_000_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
};
const sx_layout sx_a_zstd_frame_header_000 = { UINT32_C(0x60040017), "zstd_frame_header_000", sx_a_zstd_frame_header_000_fields, SX_COUNT(sx_a_zstd_frame_header_000_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_001_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("frame_content_size_encoded", "uint16", 6, 2, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_001 = { UINT32_C(0x60040018), "zstd_frame_header_001", sx_a_zstd_frame_header_001_fields, SX_COUNT(sx_a_zstd_frame_header_001_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_002_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("frame_content_size", "uint32", 6, 4, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_002 = { UINT32_C(0x60040019), "zstd_frame_header_002", sx_a_zstd_frame_header_002_fields, SX_COUNT(sx_a_zstd_frame_header_002_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_003_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("frame_content_size", "uint64", 6, 8, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_003 = { UINT32_C(0x6004001A), "zstd_frame_header_003", sx_a_zstd_frame_header_003_fields, SX_COUNT(sx_a_zstd_frame_header_003_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_010_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 6, 1, SX_ID),
};
const sx_layout sx_a_zstd_frame_header_010 = { UINT32_C(0x6004001B), "zstd_frame_header_010", sx_a_zstd_frame_header_010_fields, SX_COUNT(sx_a_zstd_frame_header_010_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_011_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 6, 1, SX_ID),
    SX_FIELD("frame_content_size_encoded", "uint16", 7, 2, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_011 = { UINT32_C(0x6004001C), "zstd_frame_header_011", sx_a_zstd_frame_header_011_fields, SX_COUNT(sx_a_zstd_frame_header_011_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_012_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 6, 1, SX_ID),
    SX_FIELD("frame_content_size", "uint32", 7, 4, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_012 = { UINT32_C(0x6004001D), "zstd_frame_header_012", sx_a_zstd_frame_header_012_fields, SX_COUNT(sx_a_zstd_frame_header_012_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_013_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 6, 1, SX_ID),
    SX_FIELD("frame_content_size", "uint64", 7, 8, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_013 = { UINT32_C(0x6004001E), "zstd_frame_header_013", sx_a_zstd_frame_header_013_fields, SX_COUNT(sx_a_zstd_frame_header_013_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_020_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 6, 2, SX_ID),
};
const sx_layout sx_a_zstd_frame_header_020 = { UINT32_C(0x6004001F), "zstd_frame_header_020", sx_a_zstd_frame_header_020_fields, SX_COUNT(sx_a_zstd_frame_header_020_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_021_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 6, 2, SX_ID),
    SX_FIELD("frame_content_size_encoded", "uint16", 8, 2, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_021 = { UINT32_C(0x60040020), "zstd_frame_header_021", sx_a_zstd_frame_header_021_fields, SX_COUNT(sx_a_zstd_frame_header_021_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_022_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 6, 2, SX_ID),
    SX_FIELD("frame_content_size", "uint32", 8, 4, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_022 = { UINT32_C(0x60040021), "zstd_frame_header_022", sx_a_zstd_frame_header_022_fields, SX_COUNT(sx_a_zstd_frame_header_022_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_023_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 6, 2, SX_ID),
    SX_FIELD("frame_content_size", "uint64", 8, 8, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_023 = { UINT32_C(0x60040022), "zstd_frame_header_023", sx_a_zstd_frame_header_023_fields, SX_COUNT(sx_a_zstd_frame_header_023_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_030_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 6, 4, SX_ID),
};
const sx_layout sx_a_zstd_frame_header_030 = { UINT32_C(0x60040023), "zstd_frame_header_030", sx_a_zstd_frame_header_030_fields, SX_COUNT(sx_a_zstd_frame_header_030_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_031_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 6, 4, SX_ID),
    SX_FIELD("frame_content_size_encoded", "uint16", 10, 2, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_031 = { UINT32_C(0x60040024), "zstd_frame_header_031", sx_a_zstd_frame_header_031_fields, SX_COUNT(sx_a_zstd_frame_header_031_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_032_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 6, 4, SX_ID),
    SX_FIELD("frame_content_size", "uint32", 10, 4, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_032 = { UINT32_C(0x60040025), "zstd_frame_header_032", sx_a_zstd_frame_header_032_fields, SX_COUNT(sx_a_zstd_frame_header_032_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_033_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("window_descriptor", "uint8", 5, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 6, 4, SX_ID),
    SX_FIELD("frame_content_size", "uint64", 10, 8, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_033 = { UINT32_C(0x60040026), "zstd_frame_header_033", sx_a_zstd_frame_header_033_fields, SX_COUNT(sx_a_zstd_frame_header_033_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_100_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("frame_content_size", "uint8", 5, 1, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_100 = { UINT32_C(0x60040027), "zstd_frame_header_100", sx_a_zstd_frame_header_100_fields, SX_COUNT(sx_a_zstd_frame_header_100_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_101_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("frame_content_size_encoded", "uint16", 5, 2, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_101 = { UINT32_C(0x60040028), "zstd_frame_header_101", sx_a_zstd_frame_header_101_fields, SX_COUNT(sx_a_zstd_frame_header_101_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_102_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("frame_content_size", "uint32", 5, 4, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_102 = { UINT32_C(0x60040029), "zstd_frame_header_102", sx_a_zstd_frame_header_102_fields, SX_COUNT(sx_a_zstd_frame_header_102_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_103_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("frame_content_size", "uint64", 5, 8, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_103 = { UINT32_C(0x6004002A), "zstd_frame_header_103", sx_a_zstd_frame_header_103_fields, SX_COUNT(sx_a_zstd_frame_header_103_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_110_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 5, 1, SX_ID),
    SX_FIELD("frame_content_size", "uint8", 6, 1, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_110 = { UINT32_C(0x6004002B), "zstd_frame_header_110", sx_a_zstd_frame_header_110_fields, SX_COUNT(sx_a_zstd_frame_header_110_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_111_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 5, 1, SX_ID),
    SX_FIELD("frame_content_size_encoded", "uint16", 6, 2, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_111 = { UINT32_C(0x6004002C), "zstd_frame_header_111", sx_a_zstd_frame_header_111_fields, SX_COUNT(sx_a_zstd_frame_header_111_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_112_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 5, 1, SX_ID),
    SX_FIELD("frame_content_size", "uint32", 6, 4, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_112 = { UINT32_C(0x6004002D), "zstd_frame_header_112", sx_a_zstd_frame_header_112_fields, SX_COUNT(sx_a_zstd_frame_header_112_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_113_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint8", 5, 1, SX_ID),
    SX_FIELD("frame_content_size", "uint64", 6, 8, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_113 = { UINT32_C(0x6004002E), "zstd_frame_header_113", sx_a_zstd_frame_header_113_fields, SX_COUNT(sx_a_zstd_frame_header_113_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_120_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 5, 2, SX_ID),
    SX_FIELD("frame_content_size", "uint8", 7, 1, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_120 = { UINT32_C(0x6004002F), "zstd_frame_header_120", sx_a_zstd_frame_header_120_fields, SX_COUNT(sx_a_zstd_frame_header_120_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_121_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 5, 2, SX_ID),
    SX_FIELD("frame_content_size_encoded", "uint16", 7, 2, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_121 = { UINT32_C(0x60040030), "zstd_frame_header_121", sx_a_zstd_frame_header_121_fields, SX_COUNT(sx_a_zstd_frame_header_121_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_122_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 5, 2, SX_ID),
    SX_FIELD("frame_content_size", "uint32", 7, 4, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_122 = { UINT32_C(0x60040031), "zstd_frame_header_122", sx_a_zstd_frame_header_122_fields, SX_COUNT(sx_a_zstd_frame_header_122_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_123_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint16", 5, 2, SX_ID),
    SX_FIELD("frame_content_size", "uint64", 7, 8, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_123 = { UINT32_C(0x60040032), "zstd_frame_header_123", sx_a_zstd_frame_header_123_fields, SX_COUNT(sx_a_zstd_frame_header_123_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_130_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 5, 4, SX_ID),
    SX_FIELD("frame_content_size", "uint8", 9, 1, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_130 = { UINT32_C(0x60040033), "zstd_frame_header_130", sx_a_zstd_frame_header_130_fields, SX_COUNT(sx_a_zstd_frame_header_130_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_131_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 5, 4, SX_ID),
    SX_FIELD("frame_content_size_encoded", "uint16", 9, 2, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_131 = { UINT32_C(0x60040034), "zstd_frame_header_131", sx_a_zstd_frame_header_131_fields, SX_COUNT(sx_a_zstd_frame_header_131_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_132_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 5, 4, SX_ID),
    SX_FIELD("frame_content_size", "uint32", 9, 4, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_132 = { UINT32_C(0x60040035), "zstd_frame_header_132", sx_a_zstd_frame_header_132_fields, SX_COUNT(sx_a_zstd_frame_header_132_fields), SX_LE };
static const xx_data_struct_field_desc sx_a_zstd_frame_header_133_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("frame_header_descriptor", "uint8", 4, 1, SX_FLAGS),
    SX_FIELD("dictionary_id", "uint32", 5, 4, SX_ID),
    SX_FIELD("frame_content_size", "uint64", 9, 8, SX_SIZE),
};
const sx_layout sx_a_zstd_frame_header_133 = { UINT32_C(0x60040036), "zstd_frame_header_133", sx_a_zstd_frame_header_133_fields, SX_COUNT(sx_a_zstd_frame_header_133_fields), SX_LE };
static bool sx_a_zstd(sx_context *c)
{
    static const sx_layout *const variants[2][4][4]={
        {
            {&sx_a_zstd_frame_header_000,&sx_a_zstd_frame_header_001,&sx_a_zstd_frame_header_002,&sx_a_zstd_frame_header_003},
            {&sx_a_zstd_frame_header_010,&sx_a_zstd_frame_header_011,&sx_a_zstd_frame_header_012,&sx_a_zstd_frame_header_013},
            {&sx_a_zstd_frame_header_020,&sx_a_zstd_frame_header_021,&sx_a_zstd_frame_header_022,&sx_a_zstd_frame_header_023},
            {&sx_a_zstd_frame_header_030,&sx_a_zstd_frame_header_031,&sx_a_zstd_frame_header_032,&sx_a_zstd_frame_header_033},
        },
        {
            {&sx_a_zstd_frame_header_100,&sx_a_zstd_frame_header_101,&sx_a_zstd_frame_header_102,&sx_a_zstd_frame_header_103},
            {&sx_a_zstd_frame_header_110,&sx_a_zstd_frame_header_111,&sx_a_zstd_frame_header_112,&sx_a_zstd_frame_header_113},
            {&sx_a_zstd_frame_header_120,&sx_a_zstd_frame_header_121,&sx_a_zstd_frame_header_122,&sx_a_zstd_frame_header_123},
            {&sx_a_zstd_frame_header_130,&sx_a_zstd_frame_header_131,&sx_a_zstd_frame_header_132,&sx_a_zstd_frame_header_133},
        },
    };
    int64_t at=0;
    while(at<c->size){
        uint32_t magic;uint8_t d;
        if(!sx_u32(c,at,false,&magic))return false;
        if((magic&0xfffffff0U)==0x184d2a50U){if(!sx_a_skippable(c,&at))return false;continue;}
        if(magic!=0xfd2fb528U||!sx_read(c,at+4,&d,1)||(d&0x18))return false;
        unsigned single=(d>>5)&1,dict=d&3,content=d>>6;
        static const unsigned dictsize[]={0,1,2,4};
        unsigned cs=content==0?single:content==1?2:content==2?4:8;
        int64_t size=5+!single+dictsize[dict]+cs;
        if(!sx_add(c,variants[single][dict][content],at,size))return false;at+=size;
        for(;;){
            uint8_t h[3];uint32_t block,kind,packed;
            if(!sx_read(c,at,h,3)||!sx_add(c,&sx_a_zstd_block_header,at,3))return false;
            block=xx_data_get_u24(h,3,0,false);kind=(block>>1)&3;packed=kind==1?1:block>>3;
            if(kind==3||(block>>3)>131072)return false;
            at+=3;if(!sx_a_raw_advance(c,&at,packed))return false;
            if(block&1)break;
        }
        if(d&4){if(!sx_add(c,&sx_a_checksum_le,at,4))return false;at+=4;}
    }
    return true;
}
bool sx_zstd_build(sx_context*c)
{
    return sx_a_zstd(c);
}
