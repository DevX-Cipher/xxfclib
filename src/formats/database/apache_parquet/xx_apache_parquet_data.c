/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Apache Parquet data structures, moved out of the columnar schema family. */
#include "../../xx_format_schema_columnar.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxq_parquet_file_header_fields[] = {
    SX_FIELD("magic", "char[4]", 0, 4, SX_SIGNATURE),
};
const sx_layout sxq_parquet_file_header = {UINT32_C(0x601F0029),"parquet_file_header",sxq_parquet_file_header_fields,SX_COUNT(sxq_parquet_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxq_parquet_file_trailer_fields[] = {
    SX_FIELD("metadata_length", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("magic", "char[4]", 4, 4, SX_SIGNATURE),
};
const sx_layout sxq_parquet_file_trailer = {UINT32_C(0x601F002A),"parquet_file_trailer",sxq_parquet_file_trailer_fields,SX_COUNT(sxq_parquet_file_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_field_header_fields[] = {
    SX_FIELD("field_delta_and_type", "uint8", 0, 1, SX_ID),
};
const sx_layout sxq_thrift_field_header = {UINT32_C(0x601F002B),"thrift_field_header",sxq_thrift_field_header_fields,SX_COUNT(sxq_thrift_field_header_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_list_header_fields[] = {
    SX_FIELD("count_and_element_type", "uint8", 0, 1, SX_NONE),
};
const sx_layout sxq_thrift_list_header = {UINT32_C(0x601F002C),"thrift_list_header",sxq_thrift_list_header_fields,SX_COUNT(sxq_thrift_list_header_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_map_types_fields[] = {
    SX_FIELD("key_and_value_type", "uint8", 0, 1, SX_ID),
};
const sx_layout sxq_thrift_map_types = {UINT32_C(0x601F002D),"thrift_map_types",sxq_thrift_map_types_fields,SX_COUNT(sxq_thrift_map_types_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_boolean_value_fields[] = {
    SX_FIELD("boolean_type", "uint8", 0, 1, SX_FLAGS),
};
const sx_layout sxq_thrift_boolean_value = {UINT32_C(0x601F002E),"thrift_boolean_value",sxq_thrift_boolean_value_fields,SX_COUNT(sxq_thrift_boolean_value_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_byte_value_fields[] = {
    SX_FIELD("value", "int8", 0, 1, SX_NONE),
};
const sx_layout sxq_thrift_byte_value = {UINT32_C(0x601F002F),"thrift_byte_value",sxq_thrift_byte_value_fields,SX_COUNT(sxq_thrift_byte_value_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_double_bits_fields[] = {
    SX_FIELD("ieee754_binary64_bits", "uint64", 0, 8, SX_NONE),
};
const sx_layout sxq_thrift_double_bits = {UINT32_C(0x601F0030),"thrift_double_bits",sxq_thrift_double_bits_fields,SX_COUNT(sxq_thrift_double_bits_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_size_1_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 1, SX_SIZE),
};
const sx_layout sxq_columnar_varuint_size_1 = {UINT32_C(0x601F0031),"columnar_varuint_size_1",sxq_columnar_varuint_size_1_fields,SX_COUNT(sxq_columnar_varuint_size_1_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_size_2_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 2, SX_SIZE),
};
const sx_layout sxq_columnar_varuint_size_2 = {UINT32_C(0x601F0032),"columnar_varuint_size_2",sxq_columnar_varuint_size_2_fields,SX_COUNT(sxq_columnar_varuint_size_2_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_size_3_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 3, SX_SIZE),
};
const sx_layout sxq_columnar_varuint_size_3 = {UINT32_C(0x601F0033),"columnar_varuint_size_3",sxq_columnar_varuint_size_3_fields,SX_COUNT(sxq_columnar_varuint_size_3_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_size_4_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 4, SX_SIZE),
};
const sx_layout sxq_columnar_varuint_size_4 = {UINT32_C(0x601F0034),"columnar_varuint_size_4",sxq_columnar_varuint_size_4_fields,SX_COUNT(sxq_columnar_varuint_size_4_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_size_5_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 5, SX_SIZE),
};
const sx_layout sxq_columnar_varuint_size_5 = {UINT32_C(0x601F0035),"columnar_varuint_size_5",sxq_columnar_varuint_size_5_fields,SX_COUNT(sxq_columnar_varuint_size_5_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_size_6_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 6, SX_SIZE),
};
const sx_layout sxq_columnar_varuint_size_6 = {UINT32_C(0x601F0036),"columnar_varuint_size_6",sxq_columnar_varuint_size_6_fields,SX_COUNT(sxq_columnar_varuint_size_6_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_size_7_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 7, SX_SIZE),
};
const sx_layout sxq_columnar_varuint_size_7 = {UINT32_C(0x601F0037),"columnar_varuint_size_7",sxq_columnar_varuint_size_7_fields,SX_COUNT(sxq_columnar_varuint_size_7_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_size_8_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 8, SX_SIZE),
};
const sx_layout sxq_columnar_varuint_size_8 = {UINT32_C(0x601F0038),"columnar_varuint_size_8",sxq_columnar_varuint_size_8_fields,SX_COUNT(sxq_columnar_varuint_size_8_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_size_9_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 9, SX_SIZE),
};
const sx_layout sxq_columnar_varuint_size_9 = {UINT32_C(0x601F0039),"columnar_varuint_size_9",sxq_columnar_varuint_size_9_fields,SX_COUNT(sxq_columnar_varuint_size_9_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_size_10_fields[] = {
    SX_FIELD("byte_length", "uleb128_64", 0, 10, SX_SIZE),
};
const sx_layout sxq_columnar_varuint_size_10 = {UINT32_C(0x601F003A),"columnar_varuint_size_10",sxq_columnar_varuint_size_10_fields,SX_COUNT(sxq_columnar_varuint_size_10_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_count_1_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 1, SX_COUNT_PROP),
};
const sx_layout sxq_columnar_varuint_count_1 = {UINT32_C(0x601F003B),"columnar_varuint_count_1",sxq_columnar_varuint_count_1_fields,SX_COUNT(sxq_columnar_varuint_count_1_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_count_2_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 2, SX_COUNT_PROP),
};
const sx_layout sxq_columnar_varuint_count_2 = {UINT32_C(0x601F003C),"columnar_varuint_count_2",sxq_columnar_varuint_count_2_fields,SX_COUNT(sxq_columnar_varuint_count_2_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_count_3_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 3, SX_COUNT_PROP),
};
const sx_layout sxq_columnar_varuint_count_3 = {UINT32_C(0x601F003D),"columnar_varuint_count_3",sxq_columnar_varuint_count_3_fields,SX_COUNT(sxq_columnar_varuint_count_3_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_count_4_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 4, SX_COUNT_PROP),
};
const sx_layout sxq_columnar_varuint_count_4 = {UINT32_C(0x601F003E),"columnar_varuint_count_4",sxq_columnar_varuint_count_4_fields,SX_COUNT(sxq_columnar_varuint_count_4_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_count_5_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 5, SX_COUNT_PROP),
};
const sx_layout sxq_columnar_varuint_count_5 = {UINT32_C(0x601F003F),"columnar_varuint_count_5",sxq_columnar_varuint_count_5_fields,SX_COUNT(sxq_columnar_varuint_count_5_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_count_6_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 6, SX_COUNT_PROP),
};
const sx_layout sxq_columnar_varuint_count_6 = {UINT32_C(0x601F0040),"columnar_varuint_count_6",sxq_columnar_varuint_count_6_fields,SX_COUNT(sxq_columnar_varuint_count_6_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_count_7_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 7, SX_COUNT_PROP),
};
const sx_layout sxq_columnar_varuint_count_7 = {UINT32_C(0x601F0041),"columnar_varuint_count_7",sxq_columnar_varuint_count_7_fields,SX_COUNT(sxq_columnar_varuint_count_7_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_count_8_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 8, SX_COUNT_PROP),
};
const sx_layout sxq_columnar_varuint_count_8 = {UINT32_C(0x601F0042),"columnar_varuint_count_8",sxq_columnar_varuint_count_8_fields,SX_COUNT(sxq_columnar_varuint_count_8_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_count_9_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 9, SX_COUNT_PROP),
};
const sx_layout sxq_columnar_varuint_count_9 = {UINT32_C(0x601F0043),"columnar_varuint_count_9",sxq_columnar_varuint_count_9_fields,SX_COUNT(sxq_columnar_varuint_count_9_fields),SX_LE};
static const xx_data_struct_field_desc sxq_columnar_varuint_count_10_fields[] = {
    SX_FIELD("element_count", "uleb128_64", 0, 10, SX_COUNT_PROP),
};
const sx_layout sxq_columnar_varuint_count_10 = {UINT32_C(0x601F0044),"columnar_varuint_count_10",sxq_columnar_varuint_count_10_fields,SX_COUNT(sxq_columnar_varuint_count_10_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_id_1_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 1, SX_ID),
};
const sx_layout sxq_thrift_i16_id_1 = {UINT32_C(0x601F0045),"thrift_i16_id_1",sxq_thrift_i16_id_1_fields,SX_COUNT(sxq_thrift_i16_id_1_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_id_2_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 2, SX_ID),
};
const sx_layout sxq_thrift_i16_id_2 = {UINT32_C(0x601F0046),"thrift_i16_id_2",sxq_thrift_i16_id_2_fields,SX_COUNT(sxq_thrift_i16_id_2_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_id_3_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 3, SX_ID),
};
const sx_layout sxq_thrift_i16_id_3 = {UINT32_C(0x601F0047),"thrift_i16_id_3",sxq_thrift_i16_id_3_fields,SX_COUNT(sxq_thrift_i16_id_3_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_id_4_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 4, SX_ID),
};
const sx_layout sxq_thrift_i16_id_4 = {UINT32_C(0x601F0048),"thrift_i16_id_4",sxq_thrift_i16_id_4_fields,SX_COUNT(sxq_thrift_i16_id_4_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_id_5_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 5, SX_ID),
};
const sx_layout sxq_thrift_i16_id_5 = {UINT32_C(0x601F0049),"thrift_i16_id_5",sxq_thrift_i16_id_5_fields,SX_COUNT(sxq_thrift_i16_id_5_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_id_6_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 6, SX_ID),
};
const sx_layout sxq_thrift_i16_id_6 = {UINT32_C(0x601F004A),"thrift_i16_id_6",sxq_thrift_i16_id_6_fields,SX_COUNT(sxq_thrift_i16_id_6_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_id_7_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 7, SX_ID),
};
const sx_layout sxq_thrift_i16_id_7 = {UINT32_C(0x601F004B),"thrift_i16_id_7",sxq_thrift_i16_id_7_fields,SX_COUNT(sxq_thrift_i16_id_7_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_id_8_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 8, SX_ID),
};
const sx_layout sxq_thrift_i16_id_8 = {UINT32_C(0x601F004C),"thrift_i16_id_8",sxq_thrift_i16_id_8_fields,SX_COUNT(sxq_thrift_i16_id_8_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_id_9_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 9, SX_ID),
};
const sx_layout sxq_thrift_i16_id_9 = {UINT32_C(0x601F004D),"thrift_i16_id_9",sxq_thrift_i16_id_9_fields,SX_COUNT(sxq_thrift_i16_id_9_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_id_10_fields[] = {
    SX_FIELD("identifier", "zigzag16", 0, 10, SX_ID),
};
const sx_layout sxq_thrift_i16_id_10 = {UINT32_C(0x601F004E),"thrift_i16_id_10",sxq_thrift_i16_id_10_fields,SX_COUNT(sxq_thrift_i16_id_10_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_value_1_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 1, SX_NONE),
};
const sx_layout sxq_thrift_i16_value_1 = {UINT32_C(0x601F004F),"thrift_i16_value_1",sxq_thrift_i16_value_1_fields,SX_COUNT(sxq_thrift_i16_value_1_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_value_2_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 2, SX_NONE),
};
const sx_layout sxq_thrift_i16_value_2 = {UINT32_C(0x601F0050),"thrift_i16_value_2",sxq_thrift_i16_value_2_fields,SX_COUNT(sxq_thrift_i16_value_2_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_value_3_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 3, SX_NONE),
};
const sx_layout sxq_thrift_i16_value_3 = {UINT32_C(0x601F0051),"thrift_i16_value_3",sxq_thrift_i16_value_3_fields,SX_COUNT(sxq_thrift_i16_value_3_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_value_4_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 4, SX_NONE),
};
const sx_layout sxq_thrift_i16_value_4 = {UINT32_C(0x601F0052),"thrift_i16_value_4",sxq_thrift_i16_value_4_fields,SX_COUNT(sxq_thrift_i16_value_4_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_value_5_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 5, SX_NONE),
};
const sx_layout sxq_thrift_i16_value_5 = {UINT32_C(0x601F0053),"thrift_i16_value_5",sxq_thrift_i16_value_5_fields,SX_COUNT(sxq_thrift_i16_value_5_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_value_6_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 6, SX_NONE),
};
const sx_layout sxq_thrift_i16_value_6 = {UINT32_C(0x601F0054),"thrift_i16_value_6",sxq_thrift_i16_value_6_fields,SX_COUNT(sxq_thrift_i16_value_6_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_value_7_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 7, SX_NONE),
};
const sx_layout sxq_thrift_i16_value_7 = {UINT32_C(0x601F0055),"thrift_i16_value_7",sxq_thrift_i16_value_7_fields,SX_COUNT(sxq_thrift_i16_value_7_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_value_8_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 8, SX_NONE),
};
const sx_layout sxq_thrift_i16_value_8 = {UINT32_C(0x601F0056),"thrift_i16_value_8",sxq_thrift_i16_value_8_fields,SX_COUNT(sxq_thrift_i16_value_8_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_value_9_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 9, SX_NONE),
};
const sx_layout sxq_thrift_i16_value_9 = {UINT32_C(0x601F0057),"thrift_i16_value_9",sxq_thrift_i16_value_9_fields,SX_COUNT(sxq_thrift_i16_value_9_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i16_value_10_fields[] = {
    SX_FIELD("value", "zigzag16", 0, 10, SX_NONE),
};
const sx_layout sxq_thrift_i16_value_10 = {UINT32_C(0x601F0058),"thrift_i16_value_10",sxq_thrift_i16_value_10_fields,SX_COUNT(sxq_thrift_i16_value_10_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_id_1_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 1, SX_ID),
};
const sx_layout sxq_thrift_i32_id_1 = {UINT32_C(0x601F0059),"thrift_i32_id_1",sxq_thrift_i32_id_1_fields,SX_COUNT(sxq_thrift_i32_id_1_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_id_2_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 2, SX_ID),
};
const sx_layout sxq_thrift_i32_id_2 = {UINT32_C(0x601F005A),"thrift_i32_id_2",sxq_thrift_i32_id_2_fields,SX_COUNT(sxq_thrift_i32_id_2_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_id_3_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 3, SX_ID),
};
const sx_layout sxq_thrift_i32_id_3 = {UINT32_C(0x601F005B),"thrift_i32_id_3",sxq_thrift_i32_id_3_fields,SX_COUNT(sxq_thrift_i32_id_3_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_id_4_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 4, SX_ID),
};
const sx_layout sxq_thrift_i32_id_4 = {UINT32_C(0x601F005C),"thrift_i32_id_4",sxq_thrift_i32_id_4_fields,SX_COUNT(sxq_thrift_i32_id_4_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_id_5_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 5, SX_ID),
};
const sx_layout sxq_thrift_i32_id_5 = {UINT32_C(0x601F005D),"thrift_i32_id_5",sxq_thrift_i32_id_5_fields,SX_COUNT(sxq_thrift_i32_id_5_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_id_6_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 6, SX_ID),
};
const sx_layout sxq_thrift_i32_id_6 = {UINT32_C(0x601F005E),"thrift_i32_id_6",sxq_thrift_i32_id_6_fields,SX_COUNT(sxq_thrift_i32_id_6_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_id_7_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 7, SX_ID),
};
const sx_layout sxq_thrift_i32_id_7 = {UINT32_C(0x601F005F),"thrift_i32_id_7",sxq_thrift_i32_id_7_fields,SX_COUNT(sxq_thrift_i32_id_7_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_id_8_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 8, SX_ID),
};
const sx_layout sxq_thrift_i32_id_8 = {UINT32_C(0x601F0060),"thrift_i32_id_8",sxq_thrift_i32_id_8_fields,SX_COUNT(sxq_thrift_i32_id_8_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_id_9_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 9, SX_ID),
};
const sx_layout sxq_thrift_i32_id_9 = {UINT32_C(0x601F0061),"thrift_i32_id_9",sxq_thrift_i32_id_9_fields,SX_COUNT(sxq_thrift_i32_id_9_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_id_10_fields[] = {
    SX_FIELD("identifier", "zigzag32", 0, 10, SX_ID),
};
const sx_layout sxq_thrift_i32_id_10 = {UINT32_C(0x601F0062),"thrift_i32_id_10",sxq_thrift_i32_id_10_fields,SX_COUNT(sxq_thrift_i32_id_10_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_value_1_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 1, SX_NONE),
};
const sx_layout sxq_thrift_i32_value_1 = {UINT32_C(0x601F0063),"thrift_i32_value_1",sxq_thrift_i32_value_1_fields,SX_COUNT(sxq_thrift_i32_value_1_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_value_2_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 2, SX_NONE),
};
const sx_layout sxq_thrift_i32_value_2 = {UINT32_C(0x601F0064),"thrift_i32_value_2",sxq_thrift_i32_value_2_fields,SX_COUNT(sxq_thrift_i32_value_2_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_value_3_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 3, SX_NONE),
};
const sx_layout sxq_thrift_i32_value_3 = {UINT32_C(0x601F0065),"thrift_i32_value_3",sxq_thrift_i32_value_3_fields,SX_COUNT(sxq_thrift_i32_value_3_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_value_4_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 4, SX_NONE),
};
const sx_layout sxq_thrift_i32_value_4 = {UINT32_C(0x601F0066),"thrift_i32_value_4",sxq_thrift_i32_value_4_fields,SX_COUNT(sxq_thrift_i32_value_4_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_value_5_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 5, SX_NONE),
};
const sx_layout sxq_thrift_i32_value_5 = {UINT32_C(0x601F0067),"thrift_i32_value_5",sxq_thrift_i32_value_5_fields,SX_COUNT(sxq_thrift_i32_value_5_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_value_6_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 6, SX_NONE),
};
const sx_layout sxq_thrift_i32_value_6 = {UINT32_C(0x601F0068),"thrift_i32_value_6",sxq_thrift_i32_value_6_fields,SX_COUNT(sxq_thrift_i32_value_6_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_value_7_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 7, SX_NONE),
};
const sx_layout sxq_thrift_i32_value_7 = {UINT32_C(0x601F0069),"thrift_i32_value_7",sxq_thrift_i32_value_7_fields,SX_COUNT(sxq_thrift_i32_value_7_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_value_8_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 8, SX_NONE),
};
const sx_layout sxq_thrift_i32_value_8 = {UINT32_C(0x601F006A),"thrift_i32_value_8",sxq_thrift_i32_value_8_fields,SX_COUNT(sxq_thrift_i32_value_8_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_value_9_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 9, SX_NONE),
};
const sx_layout sxq_thrift_i32_value_9 = {UINT32_C(0x601F006B),"thrift_i32_value_9",sxq_thrift_i32_value_9_fields,SX_COUNT(sxq_thrift_i32_value_9_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_value_10_fields[] = {
    SX_FIELD("value", "zigzag32", 0, 10, SX_NONE),
};
const sx_layout sxq_thrift_i32_value_10 = {UINT32_C(0x601F006C),"thrift_i32_value_10",sxq_thrift_i32_value_10_fields,SX_COUNT(sxq_thrift_i32_value_10_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_size_1_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 1, SX_SIZE),
};
const sx_layout sxq_thrift_i32_size_1 = {UINT32_C(0x601F006D),"thrift_i32_size_1",sxq_thrift_i32_size_1_fields,SX_COUNT(sxq_thrift_i32_size_1_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_size_2_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 2, SX_SIZE),
};
const sx_layout sxq_thrift_i32_size_2 = {UINT32_C(0x601F006E),"thrift_i32_size_2",sxq_thrift_i32_size_2_fields,SX_COUNT(sxq_thrift_i32_size_2_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_size_3_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 3, SX_SIZE),
};
const sx_layout sxq_thrift_i32_size_3 = {UINT32_C(0x601F006F),"thrift_i32_size_3",sxq_thrift_i32_size_3_fields,SX_COUNT(sxq_thrift_i32_size_3_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_size_4_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 4, SX_SIZE),
};
const sx_layout sxq_thrift_i32_size_4 = {UINT32_C(0x601F0070),"thrift_i32_size_4",sxq_thrift_i32_size_4_fields,SX_COUNT(sxq_thrift_i32_size_4_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_size_5_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 5, SX_SIZE),
};
const sx_layout sxq_thrift_i32_size_5 = {UINT32_C(0x601F0071),"thrift_i32_size_5",sxq_thrift_i32_size_5_fields,SX_COUNT(sxq_thrift_i32_size_5_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_size_6_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 6, SX_SIZE),
};
const sx_layout sxq_thrift_i32_size_6 = {UINT32_C(0x601F0072),"thrift_i32_size_6",sxq_thrift_i32_size_6_fields,SX_COUNT(sxq_thrift_i32_size_6_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_size_7_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 7, SX_SIZE),
};
const sx_layout sxq_thrift_i32_size_7 = {UINT32_C(0x601F0073),"thrift_i32_size_7",sxq_thrift_i32_size_7_fields,SX_COUNT(sxq_thrift_i32_size_7_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_size_8_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 8, SX_SIZE),
};
const sx_layout sxq_thrift_i32_size_8 = {UINT32_C(0x601F0074),"thrift_i32_size_8",sxq_thrift_i32_size_8_fields,SX_COUNT(sxq_thrift_i32_size_8_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_size_9_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 9, SX_SIZE),
};
const sx_layout sxq_thrift_i32_size_9 = {UINT32_C(0x601F0075),"thrift_i32_size_9",sxq_thrift_i32_size_9_fields,SX_COUNT(sxq_thrift_i32_size_9_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_size_10_fields[] = {
    SX_FIELD("byte_size", "zigzag32", 0, 10, SX_SIZE),
};
const sx_layout sxq_thrift_i32_size_10 = {UINT32_C(0x601F0076),"thrift_i32_size_10",sxq_thrift_i32_size_10_fields,SX_COUNT(sxq_thrift_i32_size_10_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_count_1_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 1, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i32_count_1 = {UINT32_C(0x601F0077),"thrift_i32_count_1",sxq_thrift_i32_count_1_fields,SX_COUNT(sxq_thrift_i32_count_1_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_count_2_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 2, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i32_count_2 = {UINT32_C(0x601F0078),"thrift_i32_count_2",sxq_thrift_i32_count_2_fields,SX_COUNT(sxq_thrift_i32_count_2_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_count_3_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 3, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i32_count_3 = {UINT32_C(0x601F0079),"thrift_i32_count_3",sxq_thrift_i32_count_3_fields,SX_COUNT(sxq_thrift_i32_count_3_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_count_4_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 4, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i32_count_4 = {UINT32_C(0x601F007A),"thrift_i32_count_4",sxq_thrift_i32_count_4_fields,SX_COUNT(sxq_thrift_i32_count_4_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_count_5_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 5, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i32_count_5 = {UINT32_C(0x601F007B),"thrift_i32_count_5",sxq_thrift_i32_count_5_fields,SX_COUNT(sxq_thrift_i32_count_5_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_count_6_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 6, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i32_count_6 = {UINT32_C(0x601F007C),"thrift_i32_count_6",sxq_thrift_i32_count_6_fields,SX_COUNT(sxq_thrift_i32_count_6_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_count_7_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 7, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i32_count_7 = {UINT32_C(0x601F007D),"thrift_i32_count_7",sxq_thrift_i32_count_7_fields,SX_COUNT(sxq_thrift_i32_count_7_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_count_8_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 8, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i32_count_8 = {UINT32_C(0x601F007E),"thrift_i32_count_8",sxq_thrift_i32_count_8_fields,SX_COUNT(sxq_thrift_i32_count_8_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_count_9_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 9, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i32_count_9 = {UINT32_C(0x601F007F),"thrift_i32_count_9",sxq_thrift_i32_count_9_fields,SX_COUNT(sxq_thrift_i32_count_9_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i32_count_10_fields[] = {
    SX_FIELD("element_count", "zigzag32", 0, 10, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i32_count_10 = {UINT32_C(0x601F0080),"thrift_i32_count_10",sxq_thrift_i32_count_10_fields,SX_COUNT(sxq_thrift_i32_count_10_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_value_1_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 1, SX_NONE),
};
const sx_layout sxq_thrift_i64_value_1 = {UINT32_C(0x601F0081),"thrift_i64_value_1",sxq_thrift_i64_value_1_fields,SX_COUNT(sxq_thrift_i64_value_1_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_value_2_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 2, SX_NONE),
};
const sx_layout sxq_thrift_i64_value_2 = {UINT32_C(0x601F0082),"thrift_i64_value_2",sxq_thrift_i64_value_2_fields,SX_COUNT(sxq_thrift_i64_value_2_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_value_3_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 3, SX_NONE),
};
const sx_layout sxq_thrift_i64_value_3 = {UINT32_C(0x601F0083),"thrift_i64_value_3",sxq_thrift_i64_value_3_fields,SX_COUNT(sxq_thrift_i64_value_3_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_value_4_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 4, SX_NONE),
};
const sx_layout sxq_thrift_i64_value_4 = {UINT32_C(0x601F0084),"thrift_i64_value_4",sxq_thrift_i64_value_4_fields,SX_COUNT(sxq_thrift_i64_value_4_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_value_5_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 5, SX_NONE),
};
const sx_layout sxq_thrift_i64_value_5 = {UINT32_C(0x601F0085),"thrift_i64_value_5",sxq_thrift_i64_value_5_fields,SX_COUNT(sxq_thrift_i64_value_5_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_value_6_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 6, SX_NONE),
};
const sx_layout sxq_thrift_i64_value_6 = {UINT32_C(0x601F0086),"thrift_i64_value_6",sxq_thrift_i64_value_6_fields,SX_COUNT(sxq_thrift_i64_value_6_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_value_7_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 7, SX_NONE),
};
const sx_layout sxq_thrift_i64_value_7 = {UINT32_C(0x601F0087),"thrift_i64_value_7",sxq_thrift_i64_value_7_fields,SX_COUNT(sxq_thrift_i64_value_7_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_value_8_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 8, SX_NONE),
};
const sx_layout sxq_thrift_i64_value_8 = {UINT32_C(0x601F0088),"thrift_i64_value_8",sxq_thrift_i64_value_8_fields,SX_COUNT(sxq_thrift_i64_value_8_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_value_9_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 9, SX_NONE),
};
const sx_layout sxq_thrift_i64_value_9 = {UINT32_C(0x601F0089),"thrift_i64_value_9",sxq_thrift_i64_value_9_fields,SX_COUNT(sxq_thrift_i64_value_9_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_value_10_fields[] = {
    SX_FIELD("value", "zigzag64", 0, 10, SX_NONE),
};
const sx_layout sxq_thrift_i64_value_10 = {UINT32_C(0x601F008A),"thrift_i64_value_10",sxq_thrift_i64_value_10_fields,SX_COUNT(sxq_thrift_i64_value_10_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_offset_1_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 1, SX_OFFSET),
};
const sx_layout sxq_thrift_i64_offset_1 = {UINT32_C(0x601F008B),"thrift_i64_offset_1",sxq_thrift_i64_offset_1_fields,SX_COUNT(sxq_thrift_i64_offset_1_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_offset_2_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 2, SX_OFFSET),
};
const sx_layout sxq_thrift_i64_offset_2 = {UINT32_C(0x601F008C),"thrift_i64_offset_2",sxq_thrift_i64_offset_2_fields,SX_COUNT(sxq_thrift_i64_offset_2_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_offset_3_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 3, SX_OFFSET),
};
const sx_layout sxq_thrift_i64_offset_3 = {UINT32_C(0x601F008D),"thrift_i64_offset_3",sxq_thrift_i64_offset_3_fields,SX_COUNT(sxq_thrift_i64_offset_3_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_offset_4_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 4, SX_OFFSET),
};
const sx_layout sxq_thrift_i64_offset_4 = {UINT32_C(0x601F008E),"thrift_i64_offset_4",sxq_thrift_i64_offset_4_fields,SX_COUNT(sxq_thrift_i64_offset_4_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_offset_5_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 5, SX_OFFSET),
};
const sx_layout sxq_thrift_i64_offset_5 = {UINT32_C(0x601F008F),"thrift_i64_offset_5",sxq_thrift_i64_offset_5_fields,SX_COUNT(sxq_thrift_i64_offset_5_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_offset_6_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 6, SX_OFFSET),
};
const sx_layout sxq_thrift_i64_offset_6 = {UINT32_C(0x601F0090),"thrift_i64_offset_6",sxq_thrift_i64_offset_6_fields,SX_COUNT(sxq_thrift_i64_offset_6_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_offset_7_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 7, SX_OFFSET),
};
const sx_layout sxq_thrift_i64_offset_7 = {UINT32_C(0x601F0091),"thrift_i64_offset_7",sxq_thrift_i64_offset_7_fields,SX_COUNT(sxq_thrift_i64_offset_7_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_offset_8_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 8, SX_OFFSET),
};
const sx_layout sxq_thrift_i64_offset_8 = {UINT32_C(0x601F0092),"thrift_i64_offset_8",sxq_thrift_i64_offset_8_fields,SX_COUNT(sxq_thrift_i64_offset_8_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_offset_9_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 9, SX_OFFSET),
};
const sx_layout sxq_thrift_i64_offset_9 = {UINT32_C(0x601F0093),"thrift_i64_offset_9",sxq_thrift_i64_offset_9_fields,SX_COUNT(sxq_thrift_i64_offset_9_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_offset_10_fields[] = {
    SX_FIELD("byte_offset", "zigzag64", 0, 10, SX_OFFSET),
};
const sx_layout sxq_thrift_i64_offset_10 = {UINT32_C(0x601F0094),"thrift_i64_offset_10",sxq_thrift_i64_offset_10_fields,SX_COUNT(sxq_thrift_i64_offset_10_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_size_1_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 1, SX_SIZE),
};
const sx_layout sxq_thrift_i64_size_1 = {UINT32_C(0x601F0095),"thrift_i64_size_1",sxq_thrift_i64_size_1_fields,SX_COUNT(sxq_thrift_i64_size_1_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_size_2_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 2, SX_SIZE),
};
const sx_layout sxq_thrift_i64_size_2 = {UINT32_C(0x601F0096),"thrift_i64_size_2",sxq_thrift_i64_size_2_fields,SX_COUNT(sxq_thrift_i64_size_2_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_size_3_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 3, SX_SIZE),
};
const sx_layout sxq_thrift_i64_size_3 = {UINT32_C(0x601F0097),"thrift_i64_size_3",sxq_thrift_i64_size_3_fields,SX_COUNT(sxq_thrift_i64_size_3_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_size_4_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 4, SX_SIZE),
};
const sx_layout sxq_thrift_i64_size_4 = {UINT32_C(0x601F0098),"thrift_i64_size_4",sxq_thrift_i64_size_4_fields,SX_COUNT(sxq_thrift_i64_size_4_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_size_5_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 5, SX_SIZE),
};
const sx_layout sxq_thrift_i64_size_5 = {UINT32_C(0x601F0099),"thrift_i64_size_5",sxq_thrift_i64_size_5_fields,SX_COUNT(sxq_thrift_i64_size_5_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_size_6_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 6, SX_SIZE),
};
const sx_layout sxq_thrift_i64_size_6 = {UINT32_C(0x601F009A),"thrift_i64_size_6",sxq_thrift_i64_size_6_fields,SX_COUNT(sxq_thrift_i64_size_6_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_size_7_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 7, SX_SIZE),
};
const sx_layout sxq_thrift_i64_size_7 = {UINT32_C(0x601F009B),"thrift_i64_size_7",sxq_thrift_i64_size_7_fields,SX_COUNT(sxq_thrift_i64_size_7_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_size_8_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 8, SX_SIZE),
};
const sx_layout sxq_thrift_i64_size_8 = {UINT32_C(0x601F009C),"thrift_i64_size_8",sxq_thrift_i64_size_8_fields,SX_COUNT(sxq_thrift_i64_size_8_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_size_9_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 9, SX_SIZE),
};
const sx_layout sxq_thrift_i64_size_9 = {UINT32_C(0x601F009D),"thrift_i64_size_9",sxq_thrift_i64_size_9_fields,SX_COUNT(sxq_thrift_i64_size_9_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_size_10_fields[] = {
    SX_FIELD("byte_size", "zigzag64", 0, 10, SX_SIZE),
};
const sx_layout sxq_thrift_i64_size_10 = {UINT32_C(0x601F009E),"thrift_i64_size_10",sxq_thrift_i64_size_10_fields,SX_COUNT(sxq_thrift_i64_size_10_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_count_1_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 1, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i64_count_1 = {UINT32_C(0x601F009F),"thrift_i64_count_1",sxq_thrift_i64_count_1_fields,SX_COUNT(sxq_thrift_i64_count_1_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_count_2_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 2, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i64_count_2 = {UINT32_C(0x601F00A0),"thrift_i64_count_2",sxq_thrift_i64_count_2_fields,SX_COUNT(sxq_thrift_i64_count_2_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_count_3_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 3, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i64_count_3 = {UINT32_C(0x601F00A1),"thrift_i64_count_3",sxq_thrift_i64_count_3_fields,SX_COUNT(sxq_thrift_i64_count_3_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_count_4_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 4, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i64_count_4 = {UINT32_C(0x601F00A2),"thrift_i64_count_4",sxq_thrift_i64_count_4_fields,SX_COUNT(sxq_thrift_i64_count_4_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_count_5_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 5, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i64_count_5 = {UINT32_C(0x601F00A3),"thrift_i64_count_5",sxq_thrift_i64_count_5_fields,SX_COUNT(sxq_thrift_i64_count_5_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_count_6_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 6, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i64_count_6 = {UINT32_C(0x601F00A4),"thrift_i64_count_6",sxq_thrift_i64_count_6_fields,SX_COUNT(sxq_thrift_i64_count_6_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_count_7_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 7, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i64_count_7 = {UINT32_C(0x601F00A5),"thrift_i64_count_7",sxq_thrift_i64_count_7_fields,SX_COUNT(sxq_thrift_i64_count_7_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_count_8_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 8, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i64_count_8 = {UINT32_C(0x601F00A6),"thrift_i64_count_8",sxq_thrift_i64_count_8_fields,SX_COUNT(sxq_thrift_i64_count_8_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_count_9_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 9, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i64_count_9 = {UINT32_C(0x601F00A7),"thrift_i64_count_9",sxq_thrift_i64_count_9_fields,SX_COUNT(sxq_thrift_i64_count_9_fields),SX_LE};
static const xx_data_struct_field_desc sxq_thrift_i64_count_10_fields[] = {
    SX_FIELD("element_count", "zigzag64", 0, 10, SX_COUNT_PROP),
};
const sx_layout sxq_thrift_i64_count_10 = {UINT32_C(0x601F00A8),"thrift_i64_count_10",sxq_thrift_i64_count_10_fields,SX_COUNT(sxq_thrift_i64_count_10_fields),SX_LE};
static const sx_layout *const sxq_columnar_varuint_size_rows[]={&sxq_columnar_varuint_size_1,&sxq_columnar_varuint_size_2,&sxq_columnar_varuint_size_3,&sxq_columnar_varuint_size_4,&sxq_columnar_varuint_size_5,&sxq_columnar_varuint_size_6,&sxq_columnar_varuint_size_7,&sxq_columnar_varuint_size_8,&sxq_columnar_varuint_size_9,&sxq_columnar_varuint_size_10};
static const sx_layout *const sxq_columnar_varuint_count_rows[]={&sxq_columnar_varuint_count_1,&sxq_columnar_varuint_count_2,&sxq_columnar_varuint_count_3,&sxq_columnar_varuint_count_4,&sxq_columnar_varuint_count_5,&sxq_columnar_varuint_count_6,&sxq_columnar_varuint_count_7,&sxq_columnar_varuint_count_8,&sxq_columnar_varuint_count_9,&sxq_columnar_varuint_count_10};
static const sx_layout *const sxq_thrift_i16_id_rows[]={&sxq_thrift_i16_id_1,&sxq_thrift_i16_id_2,&sxq_thrift_i16_id_3,&sxq_thrift_i16_id_4,&sxq_thrift_i16_id_5,&sxq_thrift_i16_id_6,&sxq_thrift_i16_id_7,&sxq_thrift_i16_id_8,&sxq_thrift_i16_id_9,&sxq_thrift_i16_id_10};
static const sx_layout *const sxq_thrift_i16_value_rows[]={&sxq_thrift_i16_value_1,&sxq_thrift_i16_value_2,&sxq_thrift_i16_value_3,&sxq_thrift_i16_value_4,&sxq_thrift_i16_value_5,&sxq_thrift_i16_value_6,&sxq_thrift_i16_value_7,&sxq_thrift_i16_value_8,&sxq_thrift_i16_value_9,&sxq_thrift_i16_value_10};
static const sx_layout *const sxq_thrift_i32_id_rows[]={&sxq_thrift_i32_id_1,&sxq_thrift_i32_id_2,&sxq_thrift_i32_id_3,&sxq_thrift_i32_id_4,&sxq_thrift_i32_id_5,&sxq_thrift_i32_id_6,&sxq_thrift_i32_id_7,&sxq_thrift_i32_id_8,&sxq_thrift_i32_id_9,&sxq_thrift_i32_id_10};
static const sx_layout *const sxq_thrift_i32_value_rows[]={&sxq_thrift_i32_value_1,&sxq_thrift_i32_value_2,&sxq_thrift_i32_value_3,&sxq_thrift_i32_value_4,&sxq_thrift_i32_value_5,&sxq_thrift_i32_value_6,&sxq_thrift_i32_value_7,&sxq_thrift_i32_value_8,&sxq_thrift_i32_value_9,&sxq_thrift_i32_value_10};
static const sx_layout *const sxq_thrift_i32_size_rows[]={&sxq_thrift_i32_size_1,&sxq_thrift_i32_size_2,&sxq_thrift_i32_size_3,&sxq_thrift_i32_size_4,&sxq_thrift_i32_size_5,&sxq_thrift_i32_size_6,&sxq_thrift_i32_size_7,&sxq_thrift_i32_size_8,&sxq_thrift_i32_size_9,&sxq_thrift_i32_size_10};
static const sx_layout *const sxq_thrift_i32_count_rows[]={&sxq_thrift_i32_count_1,&sxq_thrift_i32_count_2,&sxq_thrift_i32_count_3,&sxq_thrift_i32_count_4,&sxq_thrift_i32_count_5,&sxq_thrift_i32_count_6,&sxq_thrift_i32_count_7,&sxq_thrift_i32_count_8,&sxq_thrift_i32_count_9,&sxq_thrift_i32_count_10};
static const sx_layout *const sxq_thrift_i64_value_rows[]={&sxq_thrift_i64_value_1,&sxq_thrift_i64_value_2,&sxq_thrift_i64_value_3,&sxq_thrift_i64_value_4,&sxq_thrift_i64_value_5,&sxq_thrift_i64_value_6,&sxq_thrift_i64_value_7,&sxq_thrift_i64_value_8,&sxq_thrift_i64_value_9,&sxq_thrift_i64_value_10};
static const sx_layout *const sxq_thrift_i64_offset_rows[]={&sxq_thrift_i64_offset_1,&sxq_thrift_i64_offset_2,&sxq_thrift_i64_offset_3,&sxq_thrift_i64_offset_4,&sxq_thrift_i64_offset_5,&sxq_thrift_i64_offset_6,&sxq_thrift_i64_offset_7,&sxq_thrift_i64_offset_8,&sxq_thrift_i64_offset_9,&sxq_thrift_i64_offset_10};
static const sx_layout *const sxq_thrift_i64_size_rows[]={&sxq_thrift_i64_size_1,&sxq_thrift_i64_size_2,&sxq_thrift_i64_size_3,&sxq_thrift_i64_size_4,&sxq_thrift_i64_size_5,&sxq_thrift_i64_size_6,&sxq_thrift_i64_size_7,&sxq_thrift_i64_size_8,&sxq_thrift_i64_size_9,&sxq_thrift_i64_size_10};
static const sx_layout *const sxq_thrift_i64_count_rows[]={&sxq_thrift_i64_count_1,&sxq_thrift_i64_count_2,&sxq_thrift_i64_count_3,&sxq_thrift_i64_count_4,&sxq_thrift_i64_count_5,&sxq_thrift_i64_count_6,&sxq_thrift_i64_count_7,&sxq_thrift_i64_count_8,&sxq_thrift_i64_count_9,&sxq_thrift_i64_count_10};
#define SXQ_RECORD_LIMIT 100000U
/* Compact Thrift records only their wire fields. Logical strings and arrays
 * use explicit length/count framing; payload bytes are left raw. */
static bool sxq_var(sxq_window *w,uint64_t *p,uint64_t *value,unsigned *width){
 uint64_t start=*p,u=0;for(unsigned i=0;i<10;i++){
  if(!sxq_span(w,*p,1))return false;uint8_t b=w->b[(*p)++];if(i==9&&(b&254))return false;u|=(uint64_t)(b&127)<<(7*i);
  if(!(b&128)){*value=u;*width=(unsigned)(*p-start);return true;}
 }return false;
}
static bool sxq_urow(sxq_window *w,uint64_t *p,bool count,uint64_t *out){
 uint64_t at=*p;unsigned width;if(!sxq_var(w,p,out,&width))return false;
 return sxq_wadd(w,count?sxq_columnar_varuint_count_rows[width-1]:sxq_columnar_varuint_size_rows[width-1],at);
}
static bool sxq_zrow(sxq_window *w,uint64_t *p,unsigned type,unsigned role,int64_t *out){
 uint64_t at=*p,u;unsigned width;if(!sxq_var(w,p,&u,&width))return false;int64_t v=(int64_t)(u>>1)^-(int64_t)(u&1);
 const sx_layout *const *rows;
 if(type==4){rows=role==1?sxq_thrift_i16_id_rows:sxq_thrift_i16_value_rows;}
 else if(type==5){rows=role==1?sxq_thrift_i32_id_rows:role==2?sxq_thrift_i32_size_rows:role==3?sxq_thrift_i32_count_rows:sxq_thrift_i32_value_rows;}
 else rows=role==2?sxq_thrift_i64_size_rows:role==3?sxq_thrift_i64_count_rows:role==4?sxq_thrift_i64_offset_rows:sxq_thrift_i64_value_rows;
 *out=v;return sxq_wadd(w,rows[width-1],at);
}
/* Contexts: 0 unknown, 1 FileMetaData, 2 SchemaElement, 3 RowGroup,
 * 4 ColumnChunk, 5 ColumnMetaData, 6 PageHeader, 7 DataPageHeader,
 * 8 DictionaryPageHeader, 9 DataPageHeaderV2. */
static unsigned sxq_child(unsigned kind,unsigned id){
 if(kind==1)return id==2?2:id==4?3:0;
 if(kind==3&&id==1)return 4;if(kind==4&&id==3)return 5;
 if(kind==6)return id==5?7:id==7?8:id==8?9:0;return 0;
}
static unsigned sxq_role(unsigned kind,unsigned id){
 if(kind==1)return id==1?1:id==3?3:0;
 if(kind==2)return id==1||id==3||id==6||id==9?1:id==2?2:id==5?3:0;
 if(kind==3)return id==2||id==6?2:id==3?3:id==5?4:id==7?1:0;
 if(kind==4)return id==2||id==4||id==6?4:id==5||id==7?2:0;
 if(kind==5)return id==1||id==2||id==4?1:id==5?3:id==6||id==7||id==15?2:id==9||id==10||id==11||id==14?4:0;
 if(kind==6)return id==1?1:id==2||id==3?2:0;
 if(kind==7)return id==1?3:id>=2&&id<=4?1:0;
 if(kind==8)return id==1?3:id==2?1:0;
 if(kind==9)return id>=1&&id<=3?3:id==4?1:id==5||id==6?2:0;return 0;
}
static bool sxq_t_struct(sxq_window *w,uint64_t *p,unsigned kind,unsigned depth,int64_t *packed);
static bool sxq_t_value(sxq_window *w,uint64_t *p,unsigned type,unsigned child,unsigned role,unsigned depth,bool in_collection,int64_t *number){
 if(depth>32||++w->work>2000000U)return false;
 if(type==1||type==2){if(!in_collection)return true;if(!sxq_span(w,*p,1)||(w->b[*p]!=1&&w->b[*p]!=2)||!sxq_wadd(w,&sxq_thrift_boolean_value,*p))return false;(*p)++;return true;}
 if(type==3){if(!sxq_wadd(w,&sxq_thrift_byte_value,*p))return false;(*p)++;return true;}
 if(type>=4&&type<=6)return sxq_zrow(w,p,type,role,number);
 if(type==7){if(!sxq_wadd(w,&sxq_thrift_double_bits,*p))return false;*p+=8;return true;}
 if(type==8){uint64_t n;if(!sxq_urow(w,p,false,&n)||!sxq_span(w,*p,n))return false;*p+=n;return true;}
 if(type==9||type==10){
  if(!sxq_span(w,*p,1)||!sxq_wadd(w,&sxq_thrift_list_header,*p))return false;uint8_t b=w->b[(*p)++];uint64_t n=b>>4;if(n==15&&!sxq_urow(w,p,true,&n))return false;
  if(n>65536)return false;for(uint64_t i=0;i<n;i++)if(!sxq_t_value(w,p,b&15,child,role,depth+1,true,number))return false;return true;
 }
 if(type==11){
  uint64_t n;if(!sxq_urow(w,p,true,&n)||n>65536)return false;if(!n)return true;
  if(!sxq_span(w,*p,1)||!sxq_wadd(w,&sxq_thrift_map_types,*p))return false;uint8_t b=w->b[(*p)++];
  for(uint64_t i=0;i<n;i++)if(!sxq_t_value(w,p,b>>4,0,0,depth+1,true,number)||!sxq_t_value(w,p,b&15,0,0,depth+1,true,number))return false;return true;
 }
 if(type==12)return sxq_t_struct(w,p,child,depth+1,NULL);return false;
}
static bool sxq_t_struct(sxq_window *w,uint64_t *p,unsigned kind,unsigned depth,int64_t *packed){
 unsigned last=0;if(depth>32)return false;for(unsigned i=0;i<SXQ_RECORD_LIMIT;i++){
  if(!sxq_span(w,*p,1)||!sxq_wadd(w,&sxq_thrift_field_header,*p))return false;uint8_t b=w->b[(*p)++];if(!b)return true;
  unsigned id=last+(b>>4);if(!(b>>4)){int64_t x;if(!sxq_zrow(w,p,4,1,&x)||x<=0||x>INT16_MAX)return false;id=(unsigned)x;}
  if(id>INT16_MAX)return false;last=id;int64_t number=0;
  if(!sxq_t_value(w,p,b&15,sxq_child(kind,id),sxq_role(kind,id),depth+1,false,&number))return false;
  if(kind==6&&id==3&&packed){if((b&15)!=5||number<0)return false;*packed=number;}
 }return false;
}
static bool sxq_p_pages(sx_context *c,uint64_t at,uint64_t size){
 uint64_t end=at+size;for(unsigned i=0;i<65536&&at<end;i++){
  uint64_t n=end-at;if(n>65536)n=65536;sxq_window w;if(!sxq_window_open(&w,c,at,n))return false;
  uint64_t used=0;int64_t packed=-1;bool ok=sxq_t_struct(&w,&used,6,0,&packed)&&packed>=0&&(uint64_t)packed<=end-at-used;
  xx_mem_free(w.b);if(!ok)return false;at+=used+(uint64_t)packed;
 }return at==end;
}
static bool sxq_parquet(sx_context *c){
 uint8_t b[8];if(c->size<12||!sx_read(c,c->size-8,b,8))return false;uint32_t n=sxq32(b);
 if(!n||n>8U*1024U*1024U||n>(uint64_t)c->size-12||!sxq_add(c,&sxq_parquet_file_header,0)||!sxq_add(c,&sxq_parquet_file_trailer,(uint64_t)c->size-8))return false;
 uint64_t footer=(uint64_t)c->size-8-n;sxq_window w;if(!sxq_window_open(&w,c,footer,n))return false;uint64_t p=0;
 bool ok=sxq_t_struct(&w,&p,1,0,NULL)&&p==n;xx_mem_free(w.b);if(!ok)return false;
 if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return false;
 xx_archive_record_state *state=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!state)return false;
 unsigned count=0;for(;count<65536;count++){
  const xx_archive_record *r=(c->f->get_current_archive_record)(c->f,state);if(!r)break;
  if(r->data_offset<c->f->base_address||r->compressed_size<0){ok=false;break;}
  uint64_t at=(uint64_t)(r->data_offset-c->f->base_address),size=(uint64_t)r->compressed_size;
  if(at==footer&&size==n){}else if(at<4||at>footer||size>footer-at||!sxq_p_pages(c,at,size)){ok=false;break;}
  if(!(c->f->archive_record_move_to_next)(c->f,state,c->pd))break;
 }
 (c->f->free_archive_records_reading)(c->f,state);return ok&&count<65536;
}
bool sx_apache_parquet_build(sx_context*c)
{
 return sxq_parquet(c)&&sxq_finish(c);
}
