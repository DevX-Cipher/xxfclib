/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_binarylater_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_binarylater.h"
static const xx_data_struct_field_desc sxbl_wire_uint8_le_fields[] = {
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sxbl_wire_uint8_le = {UINT32_C(0x60350001),"wire_uint8_le",sxbl_wire_uint8_le_fields,SX_COUNT(sxbl_wire_uint8_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_int8_le_fields[] = {
 SX_FIELD("value","int8",0,1,SX_NONE),
};
static const sx_layout sxbl_wire_int8_le = {UINT32_C(0x60350002),"wire_int8_le",sxbl_wire_int8_le_fields,SX_COUNT(sxbl_wire_int8_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_uint16_le_fields[] = {
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
static const sx_layout sxbl_wire_uint16_le = {UINT32_C(0x60350003),"wire_uint16_le",sxbl_wire_uint16_le_fields,SX_COUNT(sxbl_wire_uint16_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_int16_le_fields[] = {
 SX_FIELD("value","int16",0,2,SX_NONE),
};
static const sx_layout sxbl_wire_int16_le = {UINT32_C(0x60350004),"wire_int16_le",sxbl_wire_int16_le_fields,SX_COUNT(sxbl_wire_int16_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_uint24_le_fields[] = {
 SX_FIELD("value","uint24",0,3,SX_NONE),
};
static const sx_layout sxbl_wire_uint24_le = {UINT32_C(0x60350005),"wire_uint24_le",sxbl_wire_uint24_le_fields,SX_COUNT(sxbl_wire_uint24_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_int24_le_fields[] = {
 SX_FIELD("value","int24",0,3,SX_NONE),
};
static const sx_layout sxbl_wire_int24_le = {UINT32_C(0x60350006),"wire_int24_le",sxbl_wire_int24_le_fields,SX_COUNT(sxbl_wire_int24_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_uint32_le_fields[] = {
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
static const sx_layout sxbl_wire_uint32_le = {UINT32_C(0x60350007),"wire_uint32_le",sxbl_wire_uint32_le_fields,SX_COUNT(sxbl_wire_uint32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_int32_le_fields[] = {
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxbl_wire_int32_le = {UINT32_C(0x60350008),"wire_int32_le",sxbl_wire_int32_le_fields,SX_COUNT(sxbl_wire_int32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_uint40_le_fields[] = {
 SX_FIELD("value","uint40",0,5,SX_NONE),
};
static const sx_layout sxbl_wire_uint40_le = {UINT32_C(0x60350009),"wire_uint40_le",sxbl_wire_uint40_le_fields,SX_COUNT(sxbl_wire_uint40_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_int40_le_fields[] = {
 SX_FIELD("value","int40",0,5,SX_NONE),
};
static const sx_layout sxbl_wire_int40_le = {UINT32_C(0x6035000a),"wire_int40_le",sxbl_wire_int40_le_fields,SX_COUNT(sxbl_wire_int40_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_uint48_le_fields[] = {
 SX_FIELD("value","uint48",0,6,SX_NONE),
};
static const sx_layout sxbl_wire_uint48_le = {UINT32_C(0x6035000b),"wire_uint48_le",sxbl_wire_uint48_le_fields,SX_COUNT(sxbl_wire_uint48_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_int48_le_fields[] = {
 SX_FIELD("value","int48",0,6,SX_NONE),
};
static const sx_layout sxbl_wire_int48_le = {UINT32_C(0x6035000c),"wire_int48_le",sxbl_wire_int48_le_fields,SX_COUNT(sxbl_wire_int48_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_uint56_le_fields[] = {
 SX_FIELD("value","uint56",0,7,SX_NONE),
};
static const sx_layout sxbl_wire_uint56_le = {UINT32_C(0x6035000d),"wire_uint56_le",sxbl_wire_uint56_le_fields,SX_COUNT(sxbl_wire_uint56_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_int56_le_fields[] = {
 SX_FIELD("value","int56",0,7,SX_NONE),
};
static const sx_layout sxbl_wire_int56_le = {UINT32_C(0x6035000e),"wire_int56_le",sxbl_wire_int56_le_fields,SX_COUNT(sxbl_wire_int56_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_uint64_le_fields[] = {
 SX_FIELD("value","uint64",0,8,SX_NONE),
};
static const sx_layout sxbl_wire_uint64_le = {UINT32_C(0x6035000f),"wire_uint64_le",sxbl_wire_uint64_le_fields,SX_COUNT(sxbl_wire_uint64_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_int64_le_fields[] = {
 SX_FIELD("value","int64",0,8,SX_NONE),
};
static const sx_layout sxbl_wire_int64_le = {UINT32_C(0x60350010),"wire_int64_le",sxbl_wire_int64_le_fields,SX_COUNT(sxbl_wire_int64_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_float32_le_fields[] = {
 SX_FIELD("value","float32",0,4,SX_NONE),
};
static const sx_layout sxbl_wire_float32_le = {UINT32_C(0x60350011),"wire_float32_le",sxbl_wire_float32_le_fields,SX_COUNT(sxbl_wire_float32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_float64_le_fields[] = {
 SX_FIELD("value","float64",0,8,SX_NONE),
};
static const sx_layout sxbl_wire_float64_le = {UINT32_C(0x60350012),"wire_float64_le",sxbl_wire_float64_le_fields,SX_COUNT(sxbl_wire_float64_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_byte_size1_le_fields[] = {
 SX_FIELD("byte_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size1_le = {UINT32_C(0x60350013),"wire_byte_size1_le",sxbl_wire_byte_size1_le_fields,SX_COUNT(sxbl_wire_byte_size1_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_item_count1_le_fields[] = {
 SX_FIELD("item_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count1_le = {UINT32_C(0x60350014),"wire_item_count1_le",sxbl_wire_item_count1_le_fields,SX_COUNT(sxbl_wire_item_count1_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_byte_size2_le_fields[] = {
 SX_FIELD("byte_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size2_le = {UINT32_C(0x60350015),"wire_byte_size2_le",sxbl_wire_byte_size2_le_fields,SX_COUNT(sxbl_wire_byte_size2_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_item_count2_le_fields[] = {
 SX_FIELD("item_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count2_le = {UINT32_C(0x60350016),"wire_item_count2_le",sxbl_wire_item_count2_le_fields,SX_COUNT(sxbl_wire_item_count2_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_byte_size4_le_fields[] = {
 SX_FIELD("byte_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size4_le = {UINT32_C(0x60350017),"wire_byte_size4_le",sxbl_wire_byte_size4_le_fields,SX_COUNT(sxbl_wire_byte_size4_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_item_count4_le_fields[] = {
 SX_FIELD("item_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count4_le = {UINT32_C(0x60350018),"wire_item_count4_le",sxbl_wire_item_count4_le_fields,SX_COUNT(sxbl_wire_item_count4_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_byte_size8_le_fields[] = {
 SX_FIELD("byte_size","uint64",0,8,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size8_le = {UINT32_C(0x60350019),"wire_byte_size8_le",sxbl_wire_byte_size8_le_fields,SX_COUNT(sxbl_wire_byte_size8_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_item_count8_le_fields[] = {
 SX_FIELD("item_count","uint64",0,8,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count8_le = {UINT32_C(0x6035001a),"wire_item_count8_le",sxbl_wire_item_count8_le_fields,SX_COUNT(sxbl_wire_item_count8_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_uint8_be_fields[] = {
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
static const sx_layout sxbl_wire_uint8_be = {UINT32_C(0x6035001b),"wire_uint8_be",sxbl_wire_uint8_be_fields,SX_COUNT(sxbl_wire_uint8_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_int8_be_fields[] = {
 SX_FIELD("value","int8",0,1,SX_NONE),
};
static const sx_layout sxbl_wire_int8_be = {UINT32_C(0x6035001c),"wire_int8_be",sxbl_wire_int8_be_fields,SX_COUNT(sxbl_wire_int8_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_uint16_be_fields[] = {
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
static const sx_layout sxbl_wire_uint16_be = {UINT32_C(0x6035001d),"wire_uint16_be",sxbl_wire_uint16_be_fields,SX_COUNT(sxbl_wire_uint16_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_int16_be_fields[] = {
 SX_FIELD("value","int16",0,2,SX_NONE),
};
static const sx_layout sxbl_wire_int16_be = {UINT32_C(0x6035001e),"wire_int16_be",sxbl_wire_int16_be_fields,SX_COUNT(sxbl_wire_int16_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_uint24_be_fields[] = {
 SX_FIELD("value","uint24",0,3,SX_NONE),
};
static const sx_layout sxbl_wire_uint24_be = {UINT32_C(0x6035001f),"wire_uint24_be",sxbl_wire_uint24_be_fields,SX_COUNT(sxbl_wire_uint24_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_int24_be_fields[] = {
 SX_FIELD("value","int24",0,3,SX_NONE),
};
static const sx_layout sxbl_wire_int24_be = {UINT32_C(0x60350020),"wire_int24_be",sxbl_wire_int24_be_fields,SX_COUNT(sxbl_wire_int24_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_uint32_be_fields[] = {
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
static const sx_layout sxbl_wire_uint32_be = {UINT32_C(0x60350021),"wire_uint32_be",sxbl_wire_uint32_be_fields,SX_COUNT(sxbl_wire_uint32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_int32_be_fields[] = {
 SX_FIELD("value","int32",0,4,SX_NONE),
};
static const sx_layout sxbl_wire_int32_be = {UINT32_C(0x60350022),"wire_int32_be",sxbl_wire_int32_be_fields,SX_COUNT(sxbl_wire_int32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_uint40_be_fields[] = {
 SX_FIELD("value","uint40",0,5,SX_NONE),
};
static const sx_layout sxbl_wire_uint40_be = {UINT32_C(0x60350023),"wire_uint40_be",sxbl_wire_uint40_be_fields,SX_COUNT(sxbl_wire_uint40_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_int40_be_fields[] = {
 SX_FIELD("value","int40",0,5,SX_NONE),
};
static const sx_layout sxbl_wire_int40_be = {UINT32_C(0x60350024),"wire_int40_be",sxbl_wire_int40_be_fields,SX_COUNT(sxbl_wire_int40_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_uint48_be_fields[] = {
 SX_FIELD("value","uint48",0,6,SX_NONE),
};
static const sx_layout sxbl_wire_uint48_be = {UINT32_C(0x60350025),"wire_uint48_be",sxbl_wire_uint48_be_fields,SX_COUNT(sxbl_wire_uint48_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_int48_be_fields[] = {
 SX_FIELD("value","int48",0,6,SX_NONE),
};
static const sx_layout sxbl_wire_int48_be = {UINT32_C(0x60350026),"wire_int48_be",sxbl_wire_int48_be_fields,SX_COUNT(sxbl_wire_int48_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_uint56_be_fields[] = {
 SX_FIELD("value","uint56",0,7,SX_NONE),
};
static const sx_layout sxbl_wire_uint56_be = {UINT32_C(0x60350027),"wire_uint56_be",sxbl_wire_uint56_be_fields,SX_COUNT(sxbl_wire_uint56_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_int56_be_fields[] = {
 SX_FIELD("value","int56",0,7,SX_NONE),
};
static const sx_layout sxbl_wire_int56_be = {UINT32_C(0x60350028),"wire_int56_be",sxbl_wire_int56_be_fields,SX_COUNT(sxbl_wire_int56_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_uint64_be_fields[] = {
 SX_FIELD("value","uint64",0,8,SX_NONE),
};
static const sx_layout sxbl_wire_uint64_be = {UINT32_C(0x60350029),"wire_uint64_be",sxbl_wire_uint64_be_fields,SX_COUNT(sxbl_wire_uint64_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_int64_be_fields[] = {
 SX_FIELD("value","int64",0,8,SX_NONE),
};
static const sx_layout sxbl_wire_int64_be = {UINT32_C(0x6035002a),"wire_int64_be",sxbl_wire_int64_be_fields,SX_COUNT(sxbl_wire_int64_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_float32_be_fields[] = {
 SX_FIELD("value","float32",0,4,SX_NONE),
};
static const sx_layout sxbl_wire_float32_be = {UINT32_C(0x6035002b),"wire_float32_be",sxbl_wire_float32_be_fields,SX_COUNT(sxbl_wire_float32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_float64_be_fields[] = {
 SX_FIELD("value","float64",0,8,SX_NONE),
};
static const sx_layout sxbl_wire_float64_be = {UINT32_C(0x6035002c),"wire_float64_be",sxbl_wire_float64_be_fields,SX_COUNT(sxbl_wire_float64_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_byte_size1_be_fields[] = {
 SX_FIELD("byte_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size1_be = {UINT32_C(0x6035002d),"wire_byte_size1_be",sxbl_wire_byte_size1_be_fields,SX_COUNT(sxbl_wire_byte_size1_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_item_count1_be_fields[] = {
 SX_FIELD("item_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count1_be = {UINT32_C(0x6035002e),"wire_item_count1_be",sxbl_wire_item_count1_be_fields,SX_COUNT(sxbl_wire_item_count1_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_byte_size2_be_fields[] = {
 SX_FIELD("byte_size","uint16",0,2,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size2_be = {UINT32_C(0x6035002f),"wire_byte_size2_be",sxbl_wire_byte_size2_be_fields,SX_COUNT(sxbl_wire_byte_size2_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_item_count2_be_fields[] = {
 SX_FIELD("item_count","uint16",0,2,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count2_be = {UINT32_C(0x60350030),"wire_item_count2_be",sxbl_wire_item_count2_be_fields,SX_COUNT(sxbl_wire_item_count2_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_byte_size4_be_fields[] = {
 SX_FIELD("byte_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size4_be = {UINT32_C(0x60350031),"wire_byte_size4_be",sxbl_wire_byte_size4_be_fields,SX_COUNT(sxbl_wire_byte_size4_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_item_count4_be_fields[] = {
 SX_FIELD("item_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count4_be = {UINT32_C(0x60350032),"wire_item_count4_be",sxbl_wire_item_count4_be_fields,SX_COUNT(sxbl_wire_item_count4_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_byte_size8_be_fields[] = {
 SX_FIELD("byte_size","uint64",0,8,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size8_be = {UINT32_C(0x60350033),"wire_byte_size8_be",sxbl_wire_byte_size8_be_fields,SX_COUNT(sxbl_wire_byte_size8_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_item_count8_be_fields[] = {
 SX_FIELD("item_count","uint64",0,8,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count8_be = {UINT32_C(0x60350034),"wire_item_count8_be",sxbl_wire_item_count8_be_fields,SX_COUNT(sxbl_wire_item_count8_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_wire_byte_size_var1_fields[] = {
 SX_FIELD("byte_size","zigzag64",0,1,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size_var1 = {UINT32_C(0x60350042),"wire_byte_size_var1",sxbl_wire_byte_size_var1_fields,SX_COUNT(sxbl_wire_byte_size_var1_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_item_count_var1_fields[] = {
 SX_FIELD("item_count","zigzag64",0,1,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count_var1 = {UINT32_C(0x60350043),"wire_item_count_var1",sxbl_wire_item_count_var1_fields,SX_COUNT(sxbl_wire_item_count_var1_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_integer_var1_fields[] = {
 SX_FIELD("integer","zigzag64",0,1,SX_NONE),
};
static const sx_layout sxbl_wire_integer_var1 = {UINT32_C(0x60350044),"wire_integer_var1",sxbl_wire_integer_var1_fields,SX_COUNT(sxbl_wire_integer_var1_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_sequence_var1_fields[] = {
 SX_FIELD("sequence","uleb128_64",0,1,SX_ID),
};
static const sx_layout sxbl_wire_sequence_var1 = {UINT32_C(0x60350045),"wire_sequence_var1",sxbl_wire_sequence_var1_fields,SX_COUNT(sxbl_wire_sequence_var1_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_size_var1_fields[] = {
 SX_FIELD("unsigned_size","uleb128_64",0,1,SX_SIZE),
};
static const sx_layout sxbl_wire_unsigned_size_var1 = {UINT32_C(0x60350046),"wire_unsigned_size_var1",sxbl_wire_unsigned_size_var1_fields,SX_COUNT(sxbl_wire_unsigned_size_var1_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_count_var1_fields[] = {
 SX_FIELD("unsigned_count","uleb128_64",0,1,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_unsigned_count_var1 = {UINT32_C(0x60350047),"wire_unsigned_count_var1",sxbl_wire_unsigned_count_var1_fields,SX_COUNT(sxbl_wire_unsigned_count_var1_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_field_id_var1_fields[] = {
 SX_FIELD("field_id","zigzag16",0,1,SX_ID),
};
static const sx_layout sxbl_wire_field_id_var1 = {UINT32_C(0x60350048),"wire_field_id_var1",sxbl_wire_field_id_var1_fields,SX_COUNT(sxbl_wire_field_id_var1_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_byte_size_var2_fields[] = {
 SX_FIELD("byte_size","zigzag64",0,2,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size_var2 = {UINT32_C(0x60350049),"wire_byte_size_var2",sxbl_wire_byte_size_var2_fields,SX_COUNT(sxbl_wire_byte_size_var2_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_item_count_var2_fields[] = {
 SX_FIELD("item_count","zigzag64",0,2,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count_var2 = {UINT32_C(0x6035004a),"wire_item_count_var2",sxbl_wire_item_count_var2_fields,SX_COUNT(sxbl_wire_item_count_var2_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_integer_var2_fields[] = {
 SX_FIELD("integer","zigzag64",0,2,SX_NONE),
};
static const sx_layout sxbl_wire_integer_var2 = {UINT32_C(0x6035004b),"wire_integer_var2",sxbl_wire_integer_var2_fields,SX_COUNT(sxbl_wire_integer_var2_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_sequence_var2_fields[] = {
 SX_FIELD("sequence","uleb128_64",0,2,SX_ID),
};
static const sx_layout sxbl_wire_sequence_var2 = {UINT32_C(0x6035004c),"wire_sequence_var2",sxbl_wire_sequence_var2_fields,SX_COUNT(sxbl_wire_sequence_var2_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_size_var2_fields[] = {
 SX_FIELD("unsigned_size","uleb128_64",0,2,SX_SIZE),
};
static const sx_layout sxbl_wire_unsigned_size_var2 = {UINT32_C(0x6035004d),"wire_unsigned_size_var2",sxbl_wire_unsigned_size_var2_fields,SX_COUNT(sxbl_wire_unsigned_size_var2_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_count_var2_fields[] = {
 SX_FIELD("unsigned_count","uleb128_64",0,2,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_unsigned_count_var2 = {UINT32_C(0x6035004e),"wire_unsigned_count_var2",sxbl_wire_unsigned_count_var2_fields,SX_COUNT(sxbl_wire_unsigned_count_var2_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_field_id_var2_fields[] = {
 SX_FIELD("field_id","zigzag16",0,2,SX_ID),
};
static const sx_layout sxbl_wire_field_id_var2 = {UINT32_C(0x6035004f),"wire_field_id_var2",sxbl_wire_field_id_var2_fields,SX_COUNT(sxbl_wire_field_id_var2_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_byte_size_var3_fields[] = {
 SX_FIELD("byte_size","zigzag64",0,3,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size_var3 = {UINT32_C(0x60350050),"wire_byte_size_var3",sxbl_wire_byte_size_var3_fields,SX_COUNT(sxbl_wire_byte_size_var3_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_item_count_var3_fields[] = {
 SX_FIELD("item_count","zigzag64",0,3,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count_var3 = {UINT32_C(0x60350051),"wire_item_count_var3",sxbl_wire_item_count_var3_fields,SX_COUNT(sxbl_wire_item_count_var3_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_integer_var3_fields[] = {
 SX_FIELD("integer","zigzag64",0,3,SX_NONE),
};
static const sx_layout sxbl_wire_integer_var3 = {UINT32_C(0x60350052),"wire_integer_var3",sxbl_wire_integer_var3_fields,SX_COUNT(sxbl_wire_integer_var3_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_sequence_var3_fields[] = {
 SX_FIELD("sequence","uleb128_64",0,3,SX_ID),
};
static const sx_layout sxbl_wire_sequence_var3 = {UINT32_C(0x60350053),"wire_sequence_var3",sxbl_wire_sequence_var3_fields,SX_COUNT(sxbl_wire_sequence_var3_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_size_var3_fields[] = {
 SX_FIELD("unsigned_size","uleb128_64",0,3,SX_SIZE),
};
static const sx_layout sxbl_wire_unsigned_size_var3 = {UINT32_C(0x60350054),"wire_unsigned_size_var3",sxbl_wire_unsigned_size_var3_fields,SX_COUNT(sxbl_wire_unsigned_size_var3_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_count_var3_fields[] = {
 SX_FIELD("unsigned_count","uleb128_64",0,3,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_unsigned_count_var3 = {UINT32_C(0x60350055),"wire_unsigned_count_var3",sxbl_wire_unsigned_count_var3_fields,SX_COUNT(sxbl_wire_unsigned_count_var3_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_field_id_var3_fields[] = {
 SX_FIELD("field_id","zigzag16",0,3,SX_ID),
};
static const sx_layout sxbl_wire_field_id_var3 = {UINT32_C(0x60350056),"wire_field_id_var3",sxbl_wire_field_id_var3_fields,SX_COUNT(sxbl_wire_field_id_var3_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_byte_size_var4_fields[] = {
 SX_FIELD("byte_size","zigzag64",0,4,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size_var4 = {UINT32_C(0x60350057),"wire_byte_size_var4",sxbl_wire_byte_size_var4_fields,SX_COUNT(sxbl_wire_byte_size_var4_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_item_count_var4_fields[] = {
 SX_FIELD("item_count","zigzag64",0,4,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count_var4 = {UINT32_C(0x60350058),"wire_item_count_var4",sxbl_wire_item_count_var4_fields,SX_COUNT(sxbl_wire_item_count_var4_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_integer_var4_fields[] = {
 SX_FIELD("integer","zigzag64",0,4,SX_NONE),
};
static const sx_layout sxbl_wire_integer_var4 = {UINT32_C(0x60350059),"wire_integer_var4",sxbl_wire_integer_var4_fields,SX_COUNT(sxbl_wire_integer_var4_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_sequence_var4_fields[] = {
 SX_FIELD("sequence","uleb128_64",0,4,SX_ID),
};
static const sx_layout sxbl_wire_sequence_var4 = {UINT32_C(0x6035005a),"wire_sequence_var4",sxbl_wire_sequence_var4_fields,SX_COUNT(sxbl_wire_sequence_var4_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_size_var4_fields[] = {
 SX_FIELD("unsigned_size","uleb128_64",0,4,SX_SIZE),
};
static const sx_layout sxbl_wire_unsigned_size_var4 = {UINT32_C(0x6035005b),"wire_unsigned_size_var4",sxbl_wire_unsigned_size_var4_fields,SX_COUNT(sxbl_wire_unsigned_size_var4_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_count_var4_fields[] = {
 SX_FIELD("unsigned_count","uleb128_64",0,4,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_unsigned_count_var4 = {UINT32_C(0x6035005c),"wire_unsigned_count_var4",sxbl_wire_unsigned_count_var4_fields,SX_COUNT(sxbl_wire_unsigned_count_var4_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_field_id_var4_fields[] = {
 SX_FIELD("field_id","zigzag16",0,4,SX_ID),
};
static const sx_layout sxbl_wire_field_id_var4 = {UINT32_C(0x6035005d),"wire_field_id_var4",sxbl_wire_field_id_var4_fields,SX_COUNT(sxbl_wire_field_id_var4_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_byte_size_var5_fields[] = {
 SX_FIELD("byte_size","zigzag64",0,5,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size_var5 = {UINT32_C(0x6035005e),"wire_byte_size_var5",sxbl_wire_byte_size_var5_fields,SX_COUNT(sxbl_wire_byte_size_var5_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_item_count_var5_fields[] = {
 SX_FIELD("item_count","zigzag64",0,5,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count_var5 = {UINT32_C(0x6035005f),"wire_item_count_var5",sxbl_wire_item_count_var5_fields,SX_COUNT(sxbl_wire_item_count_var5_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_integer_var5_fields[] = {
 SX_FIELD("integer","zigzag64",0,5,SX_NONE),
};
static const sx_layout sxbl_wire_integer_var5 = {UINT32_C(0x60350060),"wire_integer_var5",sxbl_wire_integer_var5_fields,SX_COUNT(sxbl_wire_integer_var5_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_sequence_var5_fields[] = {
 SX_FIELD("sequence","uleb128_64",0,5,SX_ID),
};
static const sx_layout sxbl_wire_sequence_var5 = {UINT32_C(0x60350061),"wire_sequence_var5",sxbl_wire_sequence_var5_fields,SX_COUNT(sxbl_wire_sequence_var5_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_size_var5_fields[] = {
 SX_FIELD("unsigned_size","uleb128_64",0,5,SX_SIZE),
};
static const sx_layout sxbl_wire_unsigned_size_var5 = {UINT32_C(0x60350062),"wire_unsigned_size_var5",sxbl_wire_unsigned_size_var5_fields,SX_COUNT(sxbl_wire_unsigned_size_var5_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_count_var5_fields[] = {
 SX_FIELD("unsigned_count","uleb128_64",0,5,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_unsigned_count_var5 = {UINT32_C(0x60350063),"wire_unsigned_count_var5",sxbl_wire_unsigned_count_var5_fields,SX_COUNT(sxbl_wire_unsigned_count_var5_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_field_id_var5_fields[] = {
 SX_FIELD("field_id","zigzag16",0,5,SX_ID),
};
static const sx_layout sxbl_wire_field_id_var5 = {UINT32_C(0x60350064),"wire_field_id_var5",sxbl_wire_field_id_var5_fields,SX_COUNT(sxbl_wire_field_id_var5_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_byte_size_var6_fields[] = {
 SX_FIELD("byte_size","zigzag64",0,6,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size_var6 = {UINT32_C(0x60350065),"wire_byte_size_var6",sxbl_wire_byte_size_var6_fields,SX_COUNT(sxbl_wire_byte_size_var6_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_item_count_var6_fields[] = {
 SX_FIELD("item_count","zigzag64",0,6,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count_var6 = {UINT32_C(0x60350066),"wire_item_count_var6",sxbl_wire_item_count_var6_fields,SX_COUNT(sxbl_wire_item_count_var6_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_integer_var6_fields[] = {
 SX_FIELD("integer","zigzag64",0,6,SX_NONE),
};
static const sx_layout sxbl_wire_integer_var6 = {UINT32_C(0x60350067),"wire_integer_var6",sxbl_wire_integer_var6_fields,SX_COUNT(sxbl_wire_integer_var6_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_sequence_var6_fields[] = {
 SX_FIELD("sequence","uleb128_64",0,6,SX_ID),
};
static const sx_layout sxbl_wire_sequence_var6 = {UINT32_C(0x60350068),"wire_sequence_var6",sxbl_wire_sequence_var6_fields,SX_COUNT(sxbl_wire_sequence_var6_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_size_var6_fields[] = {
 SX_FIELD("unsigned_size","uleb128_64",0,6,SX_SIZE),
};
static const sx_layout sxbl_wire_unsigned_size_var6 = {UINT32_C(0x60350069),"wire_unsigned_size_var6",sxbl_wire_unsigned_size_var6_fields,SX_COUNT(sxbl_wire_unsigned_size_var6_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_count_var6_fields[] = {
 SX_FIELD("unsigned_count","uleb128_64",0,6,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_unsigned_count_var6 = {UINT32_C(0x6035006a),"wire_unsigned_count_var6",sxbl_wire_unsigned_count_var6_fields,SX_COUNT(sxbl_wire_unsigned_count_var6_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_field_id_var6_fields[] = {
 SX_FIELD("field_id","zigzag16",0,6,SX_ID),
};
static const sx_layout sxbl_wire_field_id_var6 = {UINT32_C(0x6035006b),"wire_field_id_var6",sxbl_wire_field_id_var6_fields,SX_COUNT(sxbl_wire_field_id_var6_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_byte_size_var7_fields[] = {
 SX_FIELD("byte_size","zigzag64",0,7,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size_var7 = {UINT32_C(0x6035006c),"wire_byte_size_var7",sxbl_wire_byte_size_var7_fields,SX_COUNT(sxbl_wire_byte_size_var7_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_item_count_var7_fields[] = {
 SX_FIELD("item_count","zigzag64",0,7,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count_var7 = {UINT32_C(0x6035006d),"wire_item_count_var7",sxbl_wire_item_count_var7_fields,SX_COUNT(sxbl_wire_item_count_var7_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_integer_var7_fields[] = {
 SX_FIELD("integer","zigzag64",0,7,SX_NONE),
};
static const sx_layout sxbl_wire_integer_var7 = {UINT32_C(0x6035006e),"wire_integer_var7",sxbl_wire_integer_var7_fields,SX_COUNT(sxbl_wire_integer_var7_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_sequence_var7_fields[] = {
 SX_FIELD("sequence","uleb128_64",0,7,SX_ID),
};
static const sx_layout sxbl_wire_sequence_var7 = {UINT32_C(0x6035006f),"wire_sequence_var7",sxbl_wire_sequence_var7_fields,SX_COUNT(sxbl_wire_sequence_var7_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_size_var7_fields[] = {
 SX_FIELD("unsigned_size","uleb128_64",0,7,SX_SIZE),
};
static const sx_layout sxbl_wire_unsigned_size_var7 = {UINT32_C(0x60350070),"wire_unsigned_size_var7",sxbl_wire_unsigned_size_var7_fields,SX_COUNT(sxbl_wire_unsigned_size_var7_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_count_var7_fields[] = {
 SX_FIELD("unsigned_count","uleb128_64",0,7,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_unsigned_count_var7 = {UINT32_C(0x60350071),"wire_unsigned_count_var7",sxbl_wire_unsigned_count_var7_fields,SX_COUNT(sxbl_wire_unsigned_count_var7_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_field_id_var7_fields[] = {
 SX_FIELD("field_id","zigzag16",0,7,SX_ID),
};
static const sx_layout sxbl_wire_field_id_var7 = {UINT32_C(0x60350072),"wire_field_id_var7",sxbl_wire_field_id_var7_fields,SX_COUNT(sxbl_wire_field_id_var7_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_byte_size_var8_fields[] = {
 SX_FIELD("byte_size","zigzag64",0,8,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size_var8 = {UINT32_C(0x60350073),"wire_byte_size_var8",sxbl_wire_byte_size_var8_fields,SX_COUNT(sxbl_wire_byte_size_var8_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_item_count_var8_fields[] = {
 SX_FIELD("item_count","zigzag64",0,8,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count_var8 = {UINT32_C(0x60350074),"wire_item_count_var8",sxbl_wire_item_count_var8_fields,SX_COUNT(sxbl_wire_item_count_var8_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_integer_var8_fields[] = {
 SX_FIELD("integer","zigzag64",0,8,SX_NONE),
};
static const sx_layout sxbl_wire_integer_var8 = {UINT32_C(0x60350075),"wire_integer_var8",sxbl_wire_integer_var8_fields,SX_COUNT(sxbl_wire_integer_var8_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_sequence_var8_fields[] = {
 SX_FIELD("sequence","uleb128_64",0,8,SX_ID),
};
static const sx_layout sxbl_wire_sequence_var8 = {UINT32_C(0x60350076),"wire_sequence_var8",sxbl_wire_sequence_var8_fields,SX_COUNT(sxbl_wire_sequence_var8_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_size_var8_fields[] = {
 SX_FIELD("unsigned_size","uleb128_64",0,8,SX_SIZE),
};
static const sx_layout sxbl_wire_unsigned_size_var8 = {UINT32_C(0x60350077),"wire_unsigned_size_var8",sxbl_wire_unsigned_size_var8_fields,SX_COUNT(sxbl_wire_unsigned_size_var8_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_count_var8_fields[] = {
 SX_FIELD("unsigned_count","uleb128_64",0,8,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_unsigned_count_var8 = {UINT32_C(0x60350078),"wire_unsigned_count_var8",sxbl_wire_unsigned_count_var8_fields,SX_COUNT(sxbl_wire_unsigned_count_var8_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_field_id_var8_fields[] = {
 SX_FIELD("field_id","zigzag16",0,8,SX_ID),
};
static const sx_layout sxbl_wire_field_id_var8 = {UINT32_C(0x60350079),"wire_field_id_var8",sxbl_wire_field_id_var8_fields,SX_COUNT(sxbl_wire_field_id_var8_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_byte_size_var9_fields[] = {
 SX_FIELD("byte_size","zigzag64",0,9,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size_var9 = {UINT32_C(0x6035007a),"wire_byte_size_var9",sxbl_wire_byte_size_var9_fields,SX_COUNT(sxbl_wire_byte_size_var9_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_item_count_var9_fields[] = {
 SX_FIELD("item_count","zigzag64",0,9,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count_var9 = {UINT32_C(0x6035007b),"wire_item_count_var9",sxbl_wire_item_count_var9_fields,SX_COUNT(sxbl_wire_item_count_var9_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_integer_var9_fields[] = {
 SX_FIELD("integer","zigzag64",0,9,SX_NONE),
};
static const sx_layout sxbl_wire_integer_var9 = {UINT32_C(0x6035007c),"wire_integer_var9",sxbl_wire_integer_var9_fields,SX_COUNT(sxbl_wire_integer_var9_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_sequence_var9_fields[] = {
 SX_FIELD("sequence","uleb128_64",0,9,SX_ID),
};
static const sx_layout sxbl_wire_sequence_var9 = {UINT32_C(0x6035007d),"wire_sequence_var9",sxbl_wire_sequence_var9_fields,SX_COUNT(sxbl_wire_sequence_var9_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_size_var9_fields[] = {
 SX_FIELD("unsigned_size","uleb128_64",0,9,SX_SIZE),
};
static const sx_layout sxbl_wire_unsigned_size_var9 = {UINT32_C(0x6035007e),"wire_unsigned_size_var9",sxbl_wire_unsigned_size_var9_fields,SX_COUNT(sxbl_wire_unsigned_size_var9_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_count_var9_fields[] = {
 SX_FIELD("unsigned_count","uleb128_64",0,9,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_unsigned_count_var9 = {UINT32_C(0x6035007f),"wire_unsigned_count_var9",sxbl_wire_unsigned_count_var9_fields,SX_COUNT(sxbl_wire_unsigned_count_var9_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_field_id_var9_fields[] = {
 SX_FIELD("field_id","zigzag16",0,9,SX_ID),
};
static const sx_layout sxbl_wire_field_id_var9 = {UINT32_C(0x60350080),"wire_field_id_var9",sxbl_wire_field_id_var9_fields,SX_COUNT(sxbl_wire_field_id_var9_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_byte_size_var10_fields[] = {
 SX_FIELD("byte_size","zigzag64",0,10,SX_SIZE),
};
static const sx_layout sxbl_wire_byte_size_var10 = {UINT32_C(0x60350081),"wire_byte_size_var10",sxbl_wire_byte_size_var10_fields,SX_COUNT(sxbl_wire_byte_size_var10_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_item_count_var10_fields[] = {
 SX_FIELD("item_count","zigzag64",0,10,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_item_count_var10 = {UINT32_C(0x60350082),"wire_item_count_var10",sxbl_wire_item_count_var10_fields,SX_COUNT(sxbl_wire_item_count_var10_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_integer_var10_fields[] = {
 SX_FIELD("integer","zigzag64",0,10,SX_NONE),
};
static const sx_layout sxbl_wire_integer_var10 = {UINT32_C(0x60350083),"wire_integer_var10",sxbl_wire_integer_var10_fields,SX_COUNT(sxbl_wire_integer_var10_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_sequence_var10_fields[] = {
 SX_FIELD("sequence","uleb128_64",0,10,SX_ID),
};
static const sx_layout sxbl_wire_sequence_var10 = {UINT32_C(0x60350084),"wire_sequence_var10",sxbl_wire_sequence_var10_fields,SX_COUNT(sxbl_wire_sequence_var10_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_size_var10_fields[] = {
 SX_FIELD("unsigned_size","uleb128_64",0,10,SX_SIZE),
};
static const sx_layout sxbl_wire_unsigned_size_var10 = {UINT32_C(0x60350085),"wire_unsigned_size_var10",sxbl_wire_unsigned_size_var10_fields,SX_COUNT(sxbl_wire_unsigned_size_var10_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_unsigned_count_var10_fields[] = {
 SX_FIELD("unsigned_count","uleb128_64",0,10,SX_COUNT_PROP),
};
static const sx_layout sxbl_wire_unsigned_count_var10 = {UINT32_C(0x60350086),"wire_unsigned_count_var10",sxbl_wire_unsigned_count_var10_fields,SX_COUNT(sxbl_wire_unsigned_count_var10_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_wire_field_id_var10_fields[] = {
 SX_FIELD("field_id","zigzag16",0,10,SX_ID),
};
static const sx_layout sxbl_wire_field_id_var10 = {UINT32_C(0x60350087),"wire_field_id_var10",sxbl_wire_field_id_var10_fields,SX_COUNT(sxbl_wire_field_id_var10_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_der_header_short_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_FLAGS),
 SX_FIELD("content_size","uint8",1,1,SX_SIZE),
};
static const sx_layout sxbl_der_header_short = {UINT32_C(0x603500e8),"der_header_short",sxbl_der_header_short_fields,SX_COUNT(sxbl_der_header_short_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_der_header_long1_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_FLAGS),
 SX_FIELD("length_form","uint8",1,1,SX_FLAGS),
 SX_FIELD("content_size","uint8",2,1,SX_SIZE),
};
static const sx_layout sxbl_der_header_long1 = {UINT32_C(0x603500e9),"der_header_long1",sxbl_der_header_long1_fields,SX_COUNT(sxbl_der_header_long1_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_der_header_long2_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_FLAGS),
 SX_FIELD("length_form","uint8",1,1,SX_FLAGS),
 SX_FIELD("content_size","uint16",2,2,SX_SIZE),
};
static const sx_layout sxbl_der_header_long2 = {UINT32_C(0x603500ea),"der_header_long2",sxbl_der_header_long2_fields,SX_COUNT(sxbl_der_header_long2_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_der_header_long3_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_FLAGS),
 SX_FIELD("length_form","uint8",1,1,SX_FLAGS),
 SX_FIELD("content_size","uint24",2,3,SX_SIZE),
};
static const sx_layout sxbl_der_header_long3 = {UINT32_C(0x603500eb),"der_header_long3",sxbl_der_header_long3_fields,SX_COUNT(sxbl_der_header_long3_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_der_header_long4_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_FLAGS),
 SX_FIELD("length_form","uint8",1,1,SX_FLAGS),
 SX_FIELD("content_size","uint32",2,4,SX_SIZE),
};
static const sx_layout sxbl_der_header_long4 = {UINT32_C(0x603500ec),"der_header_long4",sxbl_der_header_long4_fields,SX_COUNT(sxbl_der_header_long4_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_der_unused_bits_fields[] = {
 SX_FIELD("unused_bits","uint8",0,1,SX_NONE),
};
static const sx_layout sxbl_der_unused_bits = {UINT32_C(0x603500ed),"der_unused_bits",sxbl_der_unused_bits_fields,SX_COUNT(sxbl_der_unused_bits_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_der_boolean_fields[] = {
 SX_FIELD("encoded_boolean","uint8",0,1,SX_NONE),
};
static const sx_layout sxbl_der_boolean = {UINT32_C(0x603500ee),"der_boolean",sxbl_der_boolean_fields,SX_COUNT(sxbl_der_boolean_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_der_utc_time_fields[] = {
 SX_FIELD("utc_time","char[13]",0,13,SX_STRING),
};
static const sx_layout sxbl_der_utc_time = {UINT32_C(0x603500ef),"der_utc_time",sxbl_der_utc_time_fields,SX_COUNT(sxbl_der_utc_time_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_der_generalized_time_fields[] = {
 SX_FIELD("generalized_time","char[15]",0,15,SX_STRING),
};
static const sx_layout sxbl_der_generalized_time = {UINT32_C(0x603500f0),"der_generalized_time",sxbl_der_generalized_time_fields,SX_COUNT(sxbl_der_generalized_time_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_openssh_key_magic_fields[] = {
 SX_FIELD("magic","char[15]",0,15,SX_SIGNATURE),
};
static const sx_layout sxbl_openssh_key_magic = {UINT32_C(0x603500f1),"openssh_key_magic",sxbl_openssh_key_magic_fields,SX_COUNT(sxbl_openssh_key_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ssh_string_size_fields[] = {
 SX_FIELD("byte_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxbl_ssh_string_size = {UINT32_C(0x603500f2),"ssh_string_size",sxbl_ssh_string_size_fields,SX_COUNT(sxbl_ssh_string_size_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ssh_key_count_fields[] = {
 SX_FIELD("key_count","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sxbl_ssh_key_count = {UINT32_C(0x603500f3),"ssh_key_count",sxbl_ssh_key_count_fields,SX_COUNT(sxbl_ssh_key_count_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ssh_checkints_fields[] = {
 SX_FIELD("checkint1","uint32",0,4,SX_NONE),
 SX_FIELD("checkint2","uint32",4,4,SX_NONE),
};
static const sx_layout sxbl_ssh_checkints = {UINT32_C(0x603500f4),"ssh_checkints",sxbl_ssh_checkints_fields,SX_COUNT(sxbl_ssh_checkints_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ssh_certificate_serial_fields[] = {
 SX_FIELD("serial","uint64",0,8,SX_ID),
 SX_FIELD("certificate_type","uint32",8,4,SX_ID),
};
static const sx_layout sxbl_ssh_certificate_serial = {UINT32_C(0x603500f5),"ssh_certificate_serial",sxbl_ssh_certificate_serial_fields,SX_COUNT(sxbl_ssh_certificate_serial_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ssh_certificate_validity_fields[] = {
 SX_FIELD("valid_after","uint64",0,8,SX_NONE),
 SX_FIELD("valid_before","uint64",8,8,SX_NONE),
};
static const sx_layout sxbl_ssh_certificate_validity = {UINT32_C(0x603500f6),"ssh_certificate_validity",sxbl_ssh_certificate_validity_fields,SX_COUNT(sxbl_ssh_certificate_validity_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ssh_padding_fields[] = {
 SX_FIELD("padding_byte","uint8",0,1,SX_NONE),
};
static const sx_layout sxbl_ssh_padding = {UINT32_C(0x603500f7),"ssh_padding",sxbl_ssh_padding_fields,SX_COUNT(sxbl_ssh_padding_fields),SX_LE};
/* A type's N is its physical width, independent of the decoded integer width. */
static bool sxbl_ion_integer_comment(xx_data_struct_record*r){
 bool sign=false;size_t prefix=0,n=0;const uint8_t*b;uint64_t v=0;unsigned width=0;
 if(!r||!r->type)return false;
 if(!xx_rt_wcsncmp(r->type,L"ion_varuint[",12))prefix=12;
 else if(!xx_rt_wcsncmp(r->type,L"ion_varint[",11)){prefix=11;sign=true;}else return true;
 size_t at=prefix;for(;r->type[at]>=L'0'&&r->type[at]<=L'9';at++){if(width>10)return false;width=width*10+(unsigned)(r->type[at]-L'0');}
 if(at==prefix||r->type[at]!=L']'||r->type[at+1]||!width||width>10||r->size!=(int64_t)width)return false;
 b=xx_var_get_bytes(&r->value,&n);if(!b||n!=width)return false;bool negative=sign&&(b[0]&64)!=0;
 for(size_t i=0;i<n;i++){
  unsigned bits=b[i]&(sign&&!i?63:127);
  if(((b[i]&128)!=0)!=(i+1==n)||v>(UINT64_MAX-bits)/128)return xx_data_struct_record_set_comment(r,L"Invalid or overflowing Ion variable integer; encoded bytes preserved");
  v=v*128+bits;
 }
 if(sign&&v>(negative?UINT64_C(0x8000000000000000):INT64_MAX))return xx_data_struct_record_set_comment(r,L"Ion signed magnitude exceeds int64; encoded bytes preserved");
 char a[48];wchar_t out[48];int len;
 if(sign){int64_t value=negative?(v==UINT64_C(0x8000000000000000)?INT64_MIN:-(int64_t)v):(int64_t)v;xx_var_set_i64(&r->value,value);len=negative&&!v?xx_rt_snprintf(a,sizeof(a),"-0"):xx_rt_snprintf(a,sizeof(a),"%lld",(long long)value);}
 else{bool hex=(r->property&(SX_ID|SX_FLAGS|SX_SIGNATURE|SX_CHECKSUM|SX_OFFSET|SX_POINTER|SX_ADDRESS))!=0;xx_var_set_u64(&r->value,v);len=xx_rt_snprintf(a,sizeof(a),hex?"0x%llX":"%llu",(unsigned long long)v);}
 if(len<0||len>=(int)sizeof(a))return false;for(int i=0;i<=len;i++)out[i]=(unsigned char)a[i];
 return xx_data_struct_record_set_display_value(r,out)&&xx_data_struct_record_set_comment(r,sign?(negative&&!v?L"Ion VarInt negative zero; physical sign bit retained.":L"Decoded Ion VarInt: sign-magnitude, MSB-first seven-bit groups; final-byte high bit set."):L"Decoded Ion VarUInt: MSB-first seven-bit groups; final-byte high bit set.");
}
static const sx_layout *const sx_binarylater_layouts[] = {
 &sxbl_wire_uint8_le,
 &sxbl_wire_int8_le,
 &sxbl_wire_uint16_le,
 &sxbl_wire_int16_le,
 &sxbl_wire_uint24_le,
 &sxbl_wire_int24_le,
 &sxbl_wire_uint32_le,
 &sxbl_wire_int32_le,
 &sxbl_wire_uint40_le,
 &sxbl_wire_int40_le,
 &sxbl_wire_uint48_le,
 &sxbl_wire_int48_le,
 &sxbl_wire_uint56_le,
 &sxbl_wire_int56_le,
 &sxbl_wire_uint64_le,
 &sxbl_wire_int64_le,
 &sxbl_wire_float32_le,
 &sxbl_wire_float64_le,
 &sxbl_wire_byte_size1_le,
 &sxbl_wire_item_count1_le,
 &sxbl_wire_byte_size2_le,
 &sxbl_wire_item_count2_le,
 &sxbl_wire_byte_size4_le,
 &sxbl_wire_item_count4_le,
 &sxbl_wire_byte_size8_le,
 &sxbl_wire_item_count8_le,
 &sxbl_wire_uint8_be,
 &sxbl_wire_int8_be,
 &sxbl_wire_uint16_be,
 &sxbl_wire_int16_be,
 &sxbl_wire_uint24_be,
 &sxbl_wire_int24_be,
 &sxbl_wire_uint32_be,
 &sxbl_wire_int32_be,
 &sxbl_wire_uint40_be,
 &sxbl_wire_int40_be,
 &sxbl_wire_uint48_be,
 &sxbl_wire_int48_be,
 &sxbl_wire_uint56_be,
 &sxbl_wire_int56_be,
 &sxbl_wire_uint64_be,
 &sxbl_wire_int64_be,
 &sxbl_wire_float32_be,
 &sxbl_wire_float64_be,
 &sxbl_wire_byte_size1_be,
 &sxbl_wire_item_count1_be,
 &sxbl_wire_byte_size2_be,
 &sxbl_wire_item_count2_be,
 &sxbl_wire_byte_size4_be,
 &sxbl_wire_item_count4_be,
 &sxbl_wire_byte_size8_be,
 &sxbl_wire_item_count8_be,
 &sxbl_bson_tag,
 &sxbl_cbor_tag,
 &sxbl_msgpack_tag,
 &sxbl_ubjson_tag,
 &sxbl_etf_tag,
 &sxbl_ion_tag,
 &sxbl_thrift_field_tag,
 &sxbl_thrift_collection_tag,
 &sxbl_thrift_map_tag,
 &sxbl_pickle_tag,
 &sxbl_marshal_tag,
 &sxbl_java_tag,
 &sxbl_rlp_tag,
 &sxbl_wire_byte_size_var1,
 &sxbl_wire_item_count_var1,
 &sxbl_wire_integer_var1,
 &sxbl_wire_sequence_var1,
 &sxbl_wire_unsigned_size_var1,
 &sxbl_wire_unsigned_count_var1,
 &sxbl_wire_field_id_var1,
 &sxbl_wire_byte_size_var2,
 &sxbl_wire_item_count_var2,
 &sxbl_wire_integer_var2,
 &sxbl_wire_sequence_var2,
 &sxbl_wire_unsigned_size_var2,
 &sxbl_wire_unsigned_count_var2,
 &sxbl_wire_field_id_var2,
 &sxbl_wire_byte_size_var3,
 &sxbl_wire_item_count_var3,
 &sxbl_wire_integer_var3,
 &sxbl_wire_sequence_var3,
 &sxbl_wire_unsigned_size_var3,
 &sxbl_wire_unsigned_count_var3,
 &sxbl_wire_field_id_var3,
 &sxbl_wire_byte_size_var4,
 &sxbl_wire_item_count_var4,
 &sxbl_wire_integer_var4,
 &sxbl_wire_sequence_var4,
 &sxbl_wire_unsigned_size_var4,
 &sxbl_wire_unsigned_count_var4,
 &sxbl_wire_field_id_var4,
 &sxbl_wire_byte_size_var5,
 &sxbl_wire_item_count_var5,
 &sxbl_wire_integer_var5,
 &sxbl_wire_sequence_var5,
 &sxbl_wire_unsigned_size_var5,
 &sxbl_wire_unsigned_count_var5,
 &sxbl_wire_field_id_var5,
 &sxbl_wire_byte_size_var6,
 &sxbl_wire_item_count_var6,
 &sxbl_wire_integer_var6,
 &sxbl_wire_sequence_var6,
 &sxbl_wire_unsigned_size_var6,
 &sxbl_wire_unsigned_count_var6,
 &sxbl_wire_field_id_var6,
 &sxbl_wire_byte_size_var7,
 &sxbl_wire_item_count_var7,
 &sxbl_wire_integer_var7,
 &sxbl_wire_sequence_var7,
 &sxbl_wire_unsigned_size_var7,
 &sxbl_wire_unsigned_count_var7,
 &sxbl_wire_field_id_var7,
 &sxbl_wire_byte_size_var8,
 &sxbl_wire_item_count_var8,
 &sxbl_wire_integer_var8,
 &sxbl_wire_sequence_var8,
 &sxbl_wire_unsigned_size_var8,
 &sxbl_wire_unsigned_count_var8,
 &sxbl_wire_field_id_var8,
 &sxbl_wire_byte_size_var9,
 &sxbl_wire_item_count_var9,
 &sxbl_wire_integer_var9,
 &sxbl_wire_sequence_var9,
 &sxbl_wire_unsigned_size_var9,
 &sxbl_wire_unsigned_count_var9,
 &sxbl_wire_field_id_var9,
 &sxbl_wire_byte_size_var10,
 &sxbl_wire_item_count_var10,
 &sxbl_wire_integer_var10,
 &sxbl_wire_sequence_var10,
 &sxbl_wire_unsigned_size_var10,
 &sxbl_wire_unsigned_count_var10,
 &sxbl_wire_field_id_var10,
 &sxbl_bson_document_size,
 &sxbl_bson_string_size,
 &sxbl_bson_terminator,
 &sxbl_bson_binary_header,
 &sxbl_bson_object_id,
 &sxbl_bson_timestamp,
 &sxbl_bson_decimal128,
 &sxbl_bson_bool,
 &sxbl_bson_code_scope_size,
 &sxbl_bson_datetime,
 &sxbl_cbor_self_describe,
 &sxbl_cbor_half_float,
 &sxbl_msgpack_extension_type,
 &sxbl_msgpack_timestamp64,
 &sxbl_msgpack_timestamp96,
 &sxbl_ubjson_optimized_type,
 &sxbl_etf_version,
 &sxbl_etf_big_sign,
 &sxbl_etf_bit_count,
 &sxbl_etf_old_float,
 &sxbl_etf_pid_old,
 &sxbl_etf_pid_new,
 &sxbl_etf_port_old,
 &sxbl_etf_port_new,
 &sxbl_etf_port_v4,
 &sxbl_etf_reference_id,
 &sxbl_etf_creation1,
 &sxbl_etf_creation4,
 &sxbl_ion_version,
 &sxbl_ion_length1,
 &sxbl_ion_field_id1,
 &sxbl_ion_annotation_length1,
 &sxbl_ion_annotation_id1,
 &sxbl_ion_decimal_exponent1,
 &sxbl_ion_length2,
 &sxbl_ion_field_id2,
 &sxbl_ion_annotation_length2,
 &sxbl_ion_annotation_id2,
 &sxbl_ion_decimal_exponent2,
 &sxbl_ion_length3,
 &sxbl_ion_field_id3,
 &sxbl_ion_annotation_length3,
 &sxbl_ion_annotation_id3,
 &sxbl_ion_decimal_exponent3,
 &sxbl_ion_length4,
 &sxbl_ion_field_id4,
 &sxbl_ion_annotation_length4,
 &sxbl_ion_annotation_id4,
 &sxbl_ion_decimal_exponent4,
 &sxbl_ion_length5,
 &sxbl_ion_field_id5,
 &sxbl_ion_annotation_length5,
 &sxbl_ion_annotation_id5,
 &sxbl_ion_decimal_exponent5,
 &sxbl_ion_length6,
 &sxbl_ion_field_id6,
 &sxbl_ion_annotation_length6,
 &sxbl_ion_annotation_id6,
 &sxbl_ion_decimal_exponent6,
 &sxbl_ion_length7,
 &sxbl_ion_field_id7,
 &sxbl_ion_annotation_length7,
 &sxbl_ion_annotation_id7,
 &sxbl_ion_decimal_exponent7,
 &sxbl_ion_length8,
 &sxbl_ion_field_id8,
 &sxbl_ion_annotation_length8,
 &sxbl_ion_annotation_id8,
 &sxbl_ion_decimal_exponent8,
 &sxbl_ion_length9,
 &sxbl_ion_field_id9,
 &sxbl_ion_annotation_length9,
 &sxbl_ion_annotation_id9,
 &sxbl_ion_decimal_exponent9,
 &sxbl_ion_length10,
 &sxbl_ion_field_id10,
 &sxbl_ion_annotation_length10,
 &sxbl_ion_annotation_id10,
 &sxbl_ion_decimal_exponent10,
 &sxbl_thrift_message,
 &sxbl_thrift_uuid,
 &sxbl_pickle_protocol,
 &sxbl_pickle_frame_size,
 &sxbl_pickle_memo1,
 &sxbl_pickle_memo4,
 &sxbl_pickle_signed_length,
 &sxbl_marshal_signed_count,
 &sxbl_marshal_long_digit,
 &sxbl_marshal_reference,
 &sxbl_marshal_count,
 &sxbl_marshal_string_size,
 &sxbl_marshal_complex,
 &sxbl_java_stream,
 &sxbl_java_handle,
 &sxbl_java_array_count,
 &sxbl_java_class_fields,
 &sxbl_der_header_short,
 &sxbl_der_header_long1,
 &sxbl_der_header_long2,
 &sxbl_der_header_long3,
 &sxbl_der_header_long4,
 &sxbl_der_unused_bits,
 &sxbl_der_boolean,
 &sxbl_der_utc_time,
 &sxbl_der_generalized_time,
 &sxbl_openssh_key_magic,
 &sxbl_ssh_string_size,
 &sxbl_ssh_key_count,
 &sxbl_ssh_checkints,
 &sxbl_ssh_certificate_serial,
 &sxbl_ssh_certificate_validity,
 &sxbl_ssh_padding,
 &sxbl_avro_magic,
 &sxbl_avro_sync,
 &sxbl_bson_legacy_binary_size,
 &sxbl_msgpack_timestamp32,
 &sxbl_ion_negative_magnitude1,
 &sxbl_rlp_payload_size1,
 &sxbl_ion_negative_magnitude2,
 &sxbl_rlp_payload_size2,
 &sxbl_ion_negative_magnitude3,
 &sxbl_rlp_payload_size3,
 &sxbl_ion_negative_magnitude4,
 &sxbl_rlp_payload_size4,
 &sxbl_ion_negative_magnitude5,
 &sxbl_rlp_payload_size5,
 &sxbl_ion_negative_magnitude6,
 &sxbl_rlp_payload_size6,
 &sxbl_ion_negative_magnitude7,
 &sxbl_rlp_payload_size7,
 &sxbl_ion_negative_magnitude8,
 &sxbl_rlp_payload_size8,
 &sxbl_cbor_negative_argument1,
 &sxbl_ubjson_byte_size1,
 &sxbl_ubjson_item_count1,
 &sxbl_cbor_negative_argument2,
 &sxbl_ubjson_byte_size2,
 &sxbl_ubjson_item_count2,
 &sxbl_cbor_negative_argument4,
 &sxbl_ubjson_byte_size4,
 &sxbl_ubjson_item_count4,
 &sxbl_cbor_negative_argument8,
 &sxbl_ubjson_byte_size8,
 &sxbl_ubjson_item_count8,
 &sxbl_etf_reference_old,
 &sxbl_rlp_literal,
};
static bool sx_binarylater_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60350000U||id>=0x60360000U)return true;
 if(!xx_rt_wcsncmp(r->type,L"ion_varuint[",12)||!xx_rt_wcsncmp(r->type,L"ion_varint[",11))return sxbl_ion_integer_comment(r);
 const wchar_t*text=NULL;switch(id){
 case 0x60350036U: {static const wchar_t *const major[]={L"CBOR unsigned integer; low5 bits hold the inline value or argument-width selector.",L"CBOR negative integer; logical value=-1-argument; low5 bits select inline argument or width.",L"CBOR byte string; low5 bits hold inline byte length or length-width selector.",L"CBOR UTF8 string; low5 bits hold inline byte length or length-width selector.",L"CBOR array; low5 bits hold inline item count or count-width selector.",L"CBOR map; low5 bits hold inline pair count or count-width selector.",L"CBOR semantic tag; low5 bits hold inline tag number or argument-width selector.",L"CBOR simple value or IEEE754 float; low5 bits select the representation."};text=major[(xx_var_get_u64(&r->value)>>5)&7];}break;
 case 0x60350037U: {uint64_t v=xx_var_get_u64(&r->value);if(v<128)text=L"MessagePack positive fixint; this byte is the unsigned value.";else if(v>=224)text=L"MessagePack negative fixint; signed value=byte-256.";else if(v<144)text=L"MessagePack fixmap; low4 bits are key/value pair count.";else if(v<160)text=L"MessagePack fixarray; low4 bits are element count.";else if(v<192)text=L"MessagePack fixstr; low5 bits are UTF8 byte length.";else {static const wchar_t *const names[]={L"nil",L"reserved",L"false",L"true",L"bin8",L"bin16",L"bin32",L"ext8",L"ext16",L"ext32",L"float32",L"float64",L"uint8",L"uint16",L"uint32",L"uint64",L"int8",L"int16",L"int32",L"int64",L"fixext1",L"fixext2",L"fixext4",L"fixext8",L"fixext16",L"str8",L"str16",L"str32",L"array16",L"array32",L"map16",L"map32"};text=names[v-192];}}break;
 case 0x6035003aU: {static const wchar_t *const kind[]={L"Ion NOP padding; low nibble determines encoded payload length.",L"Ion bool:0=false,1=true,15=null.bool.",L"Ion nonnegative integer; low nibble determines magnitude byte length.",L"Ion negative integer; low nibble determines magnitude byte length.",L"Ion float; payload width0,4 or8;15=null.float.",L"Ion decimal; exponent VarInt followed by signed-magnitude coefficient bytes.",L"Ion timestamp (outside native supported subset).",L"Ion symbol ID.",L"Ion UTF8 string.",L"Ion character large object.",L"Ion binary large object.",L"Ion list.",L"Ion S-expression.",L"Ion struct; fields carry MSB VarUInt symbol IDs.",L"Ion annotation wrapper.",L"Reserved Ion type."};text=kind[(xx_var_get_u64(&r->value)>>4)&15];}break;
 case 0x6035003bU: {static const wchar_t *const names[]={L"STOP",L"BOOLEAN_TRUE",L"BOOLEAN_FALSE",L"BYTE",L"I16 ZigZag",L"I32 ZigZag",L"I64 ZigZag",L"DOUBLE",L"BINARY",L"LIST",L"SET",L"MAP",L"STRUCT",L"UUID",L"reserved",L"reserved"};text=names[xx_var_get_u64(&r->value)&15];}break;
 case 0x6035003cU: text=L"Thrift collection: low4 bits element type; high4 bits count,15 means following VarUInt count.";break;
 case 0x6035003dU: text=L"Thrift map: high4 bits key type; low4 bits value type.";break;
 case 0x60350041U: {uint64_t v=xx_var_get_u64(&r->value);text=v<184?L"RLP string prefix; byte length=prefix-0x80.":v<192?L"RLP long string; following length-of-length=prefix-0xb7.":v<248?L"RLP list prefix; payload byte length=prefix-0xc0.":L"RLP long list; following length-of-length=prefix-0xf7.";}break;
 case 0x603500e8U: if(!xx_rt_wcscmp(r->name,L"tag")){switch(xx_var_get_u64(&r->value)){case 1:text=L"BOOLEAN";break;case 2:text=L"INTEGER";break;case 3:text=L"BIT STRING";break;case 4:text=L"OCTET STRING";break;case 5:text=L"NULL";break;case 6:text=L"OBJECT IDENTIFIER";break;case 10:text=L"ENUMERATED";break;case 12:text=L"UTF8String";break;case 19:text=L"PrintableString";break;case 22:text=L"IA5String";break;case 23:text=L"UTCTime";break;case 24:text=L"GeneralizedTime";break;case 48:text=L"SEQUENCE (constructed)";break;case 49:text=L"SET (constructed)";break;default:text=L"Tag class=high2 bits;bit5=constructed;low5 bits=tag number.";break;}}else if(!xx_rt_wcscmp(r->name,L"length_form"))text=L"High bit marks long form; low7 bits give following length-byte width.";break;
 case 0x603500e9U: if(!xx_rt_wcscmp(r->name,L"tag")){switch(xx_var_get_u64(&r->value)){case 1:text=L"BOOLEAN";break;case 2:text=L"INTEGER";break;case 3:text=L"BIT STRING";break;case 4:text=L"OCTET STRING";break;case 5:text=L"NULL";break;case 6:text=L"OBJECT IDENTIFIER";break;case 10:text=L"ENUMERATED";break;case 12:text=L"UTF8String";break;case 19:text=L"PrintableString";break;case 22:text=L"IA5String";break;case 23:text=L"UTCTime";break;case 24:text=L"GeneralizedTime";break;case 48:text=L"SEQUENCE (constructed)";break;case 49:text=L"SET (constructed)";break;default:text=L"Tag class=high2 bits;bit5=constructed;low5 bits=tag number.";break;}}else if(!xx_rt_wcscmp(r->name,L"length_form"))text=L"High bit marks long form; low7 bits give following length-byte width.";break;
 case 0x603500eaU: if(!xx_rt_wcscmp(r->name,L"tag")){switch(xx_var_get_u64(&r->value)){case 1:text=L"BOOLEAN";break;case 2:text=L"INTEGER";break;case 3:text=L"BIT STRING";break;case 4:text=L"OCTET STRING";break;case 5:text=L"NULL";break;case 6:text=L"OBJECT IDENTIFIER";break;case 10:text=L"ENUMERATED";break;case 12:text=L"UTF8String";break;case 19:text=L"PrintableString";break;case 22:text=L"IA5String";break;case 23:text=L"UTCTime";break;case 24:text=L"GeneralizedTime";break;case 48:text=L"SEQUENCE (constructed)";break;case 49:text=L"SET (constructed)";break;default:text=L"Tag class=high2 bits;bit5=constructed;low5 bits=tag number.";break;}}else if(!xx_rt_wcscmp(r->name,L"length_form"))text=L"High bit marks long form; low7 bits give following length-byte width.";break;
 case 0x603500ebU: if(!xx_rt_wcscmp(r->name,L"tag")){switch(xx_var_get_u64(&r->value)){case 1:text=L"BOOLEAN";break;case 2:text=L"INTEGER";break;case 3:text=L"BIT STRING";break;case 4:text=L"OCTET STRING";break;case 5:text=L"NULL";break;case 6:text=L"OBJECT IDENTIFIER";break;case 10:text=L"ENUMERATED";break;case 12:text=L"UTF8String";break;case 19:text=L"PrintableString";break;case 22:text=L"IA5String";break;case 23:text=L"UTCTime";break;case 24:text=L"GeneralizedTime";break;case 48:text=L"SEQUENCE (constructed)";break;case 49:text=L"SET (constructed)";break;default:text=L"Tag class=high2 bits;bit5=constructed;low5 bits=tag number.";break;}}else if(!xx_rt_wcscmp(r->name,L"length_form"))text=L"High bit marks long form; low7 bits give following length-byte width.";break;
 case 0x603500ecU: if(!xx_rt_wcscmp(r->name,L"tag")){switch(xx_var_get_u64(&r->value)){case 1:text=L"BOOLEAN";break;case 2:text=L"INTEGER";break;case 3:text=L"BIT STRING";break;case 4:text=L"OCTET STRING";break;case 5:text=L"NULL";break;case 6:text=L"OBJECT IDENTIFIER";break;case 10:text=L"ENUMERATED";break;case 12:text=L"UTF8String";break;case 19:text=L"PrintableString";break;case 22:text=L"IA5String";break;case 23:text=L"UTCTime";break;case 24:text=L"GeneralizedTime";break;case 48:text=L"SEQUENCE (constructed)";break;case 49:text=L"SET (constructed)";break;default:text=L"Tag class=high2 bits;bit5=constructed;low5 bits=tag number.";break;}}else if(!xx_rt_wcscmp(r->name,L"length_form"))text=L"High bit marks long form; low7 bits give following length-byte width.";break;
 case 0x60350035U: switch(xx_var_get_u64(&r->value)) {
 case 1:text=L"BSON double";break;
 case 2:text=L"BSON UTF8 string";break;
 case 3:text=L"BSON embedded document";break;
 case 4:text=L"BSON array";break;
 case 5:text=L"BSON binary";break;
 case 6:text=L"BSON undefined";break;
 case 7:text=L"BSON ObjectID";break;
 case 8:text=L"BSON boolean";break;
 case 9:text=L"BSON UTC datetime";break;
 case 10:text=L"BSON null";break;
 case 11:text=L"BSON regex";break;
 case 12:text=L"BSON DBPointer";break;
 case 13:text=L"BSON JavaScript";break;
 case 14:text=L"BSON symbol";break;
 case 15:text=L"BSON code with scope";break;
 case 16:text=L"BSON int32";break;
 case 17:text=L"BSON timestamp";break;
 case 18:text=L"BSON int64";break;
 case 19:text=L"BSON decimal128";break;
 case 127:text=L"BSON max key";break;
 case 255:text=L"BSON min key";break;
 default:text=L"Unknown or unsupported physical type marker";break;}break;
 case 0x60350038U: switch(xx_var_get_u64(&r->value)) {
 case 90:text=L"null";break;
 case 78:text=L"no-op";break;
 case 84:text=L"true";break;
 case 70:text=L"false";break;
 case 105:text=L"int8";break;
 case 85:text=L"uint8";break;
 case 73:text=L"int16";break;
 case 108:text=L"int32";break;
 case 76:text=L"int64";break;
 case 100:text=L"float32";break;
 case 68:text=L"float64";break;
 case 67:text=L"char";break;
 case 83:text=L"UTF8 string";break;
 case 72:text=L"high-precision number text";break;
 case 91:text=L"array start";break;
 case 93:text=L"array end";break;
 case 123:text=L"object start";break;
 case 125:text=L"object end";break;
 case 36:text=L"optimized type prefix";break;
 case 35:text=L"counted container prefix";break;
 default:text=L"Unknown or unsupported physical type marker";break;}break;
 case 0x60350039U: switch(xx_var_get_u64(&r->value)) {
 case 70:text=L"NEW_FLOAT_EXT";break;
 case 77:text=L"BIT_BINARY_EXT";break;
 case 88:text=L"NEW_PID_EXT";break;
 case 89:text=L"NEW_PORT_EXT";break;
 case 90:text=L"NEWER_REFERENCE_EXT";break;
 case 97:text=L"SMALL_INTEGER_EXT";break;
 case 98:text=L"INTEGER_EXT";break;
 case 99:text=L"FLOAT_EXT";break;
 case 100:text=L"ATOM_EXT";break;
 case 101:text=L"REFERENCE_EXT";break;
 case 102:text=L"PORT_EXT";break;
 case 103:text=L"PID_EXT";break;
 case 104:text=L"SMALL_TUPLE_EXT";break;
 case 105:text=L"LARGE_TUPLE_EXT";break;
 case 106:text=L"NIL_EXT";break;
 case 107:text=L"STRING_EXT";break;
 case 108:text=L"LIST_EXT";break;
 case 109:text=L"BINARY_EXT";break;
 case 110:text=L"SMALL_BIG_EXT";break;
 case 111:text=L"LARGE_BIG_EXT";break;
 case 114:text=L"NEW_REFERENCE_EXT";break;
 case 115:text=L"SMALL_ATOM_EXT";break;
 case 116:text=L"MAP_EXT";break;
 case 118:text=L"ATOM_UTF8_EXT";break;
 case 119:text=L"SMALL_ATOM_UTF8_EXT";break;
 case 120:text=L"V4_PORT_EXT";break;
 default:text=L"Unknown or unsupported physical type marker";break;}break;
 case 0x6035003eU: switch(xx_var_get_u64(&r->value)) {
 case 74:text=L"BININT";break;
 case 75:text=L"BININT1";break;
 case 77:text=L"BININT2";break;
 case 71:text=L"BINFLOAT";break;
 case 85:text=L"SHORT_BINSTRING";break;
 case 84:text=L"BINSTRING";break;
 case 66:text=L"BINBYTES";break;
 case 67:text=L"SHORT_BINBYTES";break;
 case 88:text=L"BINUNICODE";break;
 case 113:text=L"BINPUT";break;
 case 104:text=L"BINGET";break;
 case 114:text=L"LONG_BINPUT";break;
 case 106:text=L"LONG_BINGET";break;
 case 78:text=L"NONE";break;
 case 93:text=L"EMPTY_LIST";break;
 case 125:text=L"EMPTY_DICT";break;
 case 41:text=L"EMPTY_TUPLE";break;
 case 40:text=L"MARK";break;
 case 48:text=L"POP";break;
 case 49:text=L"POP_MARK";break;
 case 50:text=L"DUP";break;
 case 116:text=L"TUPLE";break;
 case 108:text=L"LIST";break;
 case 100:text=L"DICT";break;
 case 101:text=L"APPENDS";break;
 case 117:text=L"SETITEMS";break;
 case 97:text=L"APPEND";break;
 case 115:text=L"SETITEM";break;
 case 46:text=L"STOP";break;
 case 136:text=L"NEWTRUE";break;
 case 137:text=L"NEWFALSE";break;
 case 138:text=L"LONG1";break;
 case 139:text=L"LONG4";break;
 case 140:text=L"SHORT_BINUNICODE";break;
 case 141:text=L"BINUNICODE8";break;
 case 142:text=L"BINBYTES8";break;
 case 143:text=L"EMPTY_SET";break;
 case 144:text=L"ADDITEMS";break;
 case 145:text=L"FROZENSET";break;
 case 148:text=L"MEMOIZE";break;
 case 149:text=L"FRAME";break;
 case 150:text=L"BYTEARRAY8";break;
 case 133:text=L"TUPLE1";break;
 case 134:text=L"TUPLE2";break;
 case 135:text=L"TUPLE3";break;
 default:text=L"Unknown or unsupported physical type marker";break;}break;
 case 0x6035003fU: switch(xx_var_get_u64(&r->value) &127) {
 case 78:text=L"None (high bit registers a reference when set)";break;
 case 70:text=L"False (high bit registers a reference when set)";break;
 case 84:text=L"True (high bit registers a reference when set)";break;
 case 46:text=L"Ellipsis (high bit registers a reference when set)";break;
 case 48:text=L"NULL dictionary terminator (high bit registers a reference when set)";break;
 case 105:text=L"int32 (high bit registers a reference when set)";break;
 case 73:text=L"legacy int64 (high bit registers a reference when set)";break;
 case 103:text=L"binary float64 (high bit registers a reference when set)";break;
 case 121:text=L"binary complex (high bit registers a reference when set)";break;
 case 108:text=L"15-bit-limb integer (high bit registers a reference when set)";break;
 case 114:text=L"reference (high bit registers a reference when set)";break;
 case 115:text=L"bytes (high bit registers a reference when set)";break;
 case 116:text=L"interned string (high bit registers a reference when set)";break;
 case 117:text=L"Unicode string (high bit registers a reference when set)";break;
 case 97:text=L"ASCII string (high bit registers a reference when set)";break;
 case 65:text=L"interned ASCII (high bit registers a reference when set)";break;
 case 122:text=L"short ASCII (high bit registers a reference when set)";break;
 case 90:text=L"short interned ASCII (high bit registers a reference when set)";break;
 case 40:text=L"tuple (high bit registers a reference when set)";break;
 case 41:text=L"small tuple (high bit registers a reference when set)";break;
 case 91:text=L"list (high bit registers a reference when set)";break;
 case 123:text=L"dictionary (high bit registers a reference when set)";break;
 case 60:text=L"set (high bit registers a reference when set)";break;
 case 62:text=L"frozenset (high bit registers a reference when set)";break;
 default:text=L"Unknown or unsupported physical type marker";break;}break;
 case 0x60350040U: switch(xx_var_get_u64(&r->value)) {
 case 112:text=L"TC_NULL";break;
 case 113:text=L"TC_REFERENCE";break;
 case 114:text=L"TC_CLASSDESC";break;
 case 116:text=L"TC_STRING";break;
 case 117:text=L"TC_ARRAY";break;
 case 120:text=L"TC_ENDBLOCKDATA";break;
 case 124:text=L"TC_LONGSTRING";break;
 default:text=L"Unknown or unsupported physical type marker";break;}break;
 case 0x60350088U:
 if(!xx_rt_wcscmp(r->name,L"document_size"))text=L"Includes the four-byte length and final zero terminator.";
 break;
 case 0x60350089U:
 if(!xx_rt_wcscmp(r->name,L"string_size"))text=L"UTF8 byte count including its zero terminator.";
 break;
 case 0x6035008eU:
 if(!xx_rt_wcscmp(r->name,L"encoded_decimal"))text=L"IEEE754 decimal128 stored little-endian; encoded bits retained.";
 break;
 case 0x60350093U:
 if(!xx_rt_wcscmp(r->name,L"ieee754_binary16_bits"))text=L"Encoded half-precision IEEE754 bits.";
 break;
 case 0x60350094U:
 if(!xx_rt_wcscmp(r->name,L"extension_type"))text=L"-1 is the timestamp extension.";
 break;
 case 0x60350095U:
 if(!xx_rt_wcscmp(r->name,L"nanoseconds_and_seconds"))text=L"High30bits nanoseconds, low34bits seconds since Unix epoch.";
 break;
 case 0x60350099U:
 if(!xx_rt_wcscmp(r->name,L"sign"))text=L"0 positive,1 negative; following magnitude digits are little-endian base256.";
 break;
 case 0x6035009aU:
 if(!xx_rt_wcscmp(r->name,L"last_byte_bits"))text=L"Significant bits in the final binary byte,1..8.";
 break;
 case 0x603500d7U:
 if(!xx_rt_wcscmp(r->name,L"version_and_message_type"))text=L"Low5bits protocol version, high3bits message type.";
 break;
 case 0x603500deU:
 if(!xx_rt_wcscmp(r->name,L"signed_digit_count"))text=L"Absolute value is the number of15-bit limbs; sign is the integer sign.";
 break;
 case 0x603500dfU:
 if(!xx_rt_wcscmp(r->name,L"magnitude_digit"))text=L"Little-endian15-bit limb, least-significant limb first.";
 break;
 case 0x603500e5U:
 if(!xx_rt_wcscmp(r->name,L"wire_handle"))text=L"Handle values start at0x7e0000; not a byte address.";
 break;
 case 0x603500edU:
 if(!xx_rt_wcscmp(r->name,L"unused_bits"))text=L"Unused low bits in final BIT STRING byte,0..7.";
 break;
 case 0x603500eeU:
 if(!xx_rt_wcscmp(r->name,L"encoded_boolean"))text=L"DER false=0,true=255.";
 break;
 case 0x603500f6U:
 if(!xx_rt_wcscmp(r->name,L"valid_after"))text=L"Seconds since Unix epoch.";
 if(!xx_rt_wcscmp(r->name,L"valid_before"))text=L"Seconds since Unix epoch;UINT64_MAX means forever.";
 break;
 case 0x603500f7U:
 if(!xx_rt_wcscmp(r->name,L"padding_byte"))text=L"Sequential padding bytes1,2,...; no implicit bytes are represented.";
 break;
 case 0x603500faU:
 if(!xx_rt_wcscmp(r->name,L"binary_size"))text=L"Legacy subtype2 inner data byte count; excludes this length field.";
 break;
 case 0x603500fcU:
 if(!xx_rt_wcscmp(r->name,L"absolute_magnitude"))text=L"Negative Ion integer: the logical value is the negative of this unsigned magnitude.";
 break;
 case 0x603500feU:
 if(!xx_rt_wcscmp(r->name,L"absolute_magnitude"))text=L"Negative Ion integer: the logical value is the negative of this unsigned magnitude.";
 break;
 case 0x60350100U:
 if(!xx_rt_wcscmp(r->name,L"absolute_magnitude"))text=L"Negative Ion integer: the logical value is the negative of this unsigned magnitude.";
 break;
 case 0x60350102U:
 if(!xx_rt_wcscmp(r->name,L"absolute_magnitude"))text=L"Negative Ion integer: the logical value is the negative of this unsigned magnitude.";
 break;
 case 0x60350104U:
 if(!xx_rt_wcscmp(r->name,L"absolute_magnitude"))text=L"Negative Ion integer: the logical value is the negative of this unsigned magnitude.";
 break;
 case 0x60350106U:
 if(!xx_rt_wcscmp(r->name,L"absolute_magnitude"))text=L"Negative Ion integer: the logical value is the negative of this unsigned magnitude.";
 break;
 case 0x60350108U:
 if(!xx_rt_wcscmp(r->name,L"absolute_magnitude"))text=L"Negative Ion integer: the logical value is the negative of this unsigned magnitude.";
 break;
 case 0x6035010aU:
 if(!xx_rt_wcscmp(r->name,L"absolute_magnitude"))text=L"Negative Ion integer: the logical value is the negative of this unsigned magnitude.";
 break;
 case 0x6035010cU:
 if(!xx_rt_wcscmp(r->name,L"encoded_argument"))text=L"CBOR negative integer logical value is -1 minus this unsigned argument.";
 break;
 case 0x6035010fU:
 if(!xx_rt_wcscmp(r->name,L"encoded_argument"))text=L"CBOR negative integer logical value is -1 minus this unsigned argument.";
 break;
 case 0x60350112U:
 if(!xx_rt_wcscmp(r->name,L"encoded_argument"))text=L"CBOR negative integer logical value is -1 minus this unsigned argument.";
 break;
 case 0x60350115U:
 if(!xx_rt_wcscmp(r->name,L"encoded_argument"))text=L"CBOR negative integer logical value is -1 minus this unsigned argument.";
 break;
 case 0x60350119U:
 if(!xx_rt_wcscmp(r->name,L"literal_byte"))text=L"RLP single-byte string0x00..0x7f; this byte is the payload itself.";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXBL_LIMIT 20000U
static bool sxbl_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
static bool sxbl_read(sx_context*c,uint64_t p,void*b,size_t n){return sxbl_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxbl_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
bool sxbl_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxbl_read(c,p,b,n))return false;*v=sxbl_uint(b,n,be);return true;}
bool sxbl_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];int64_t n=f->rel_offset+f->size;return c->count<SXBL_LIMIT&&sxbl_span(c,p,(uint64_t)n)&&sx_add(c,l,(int64_t)p,n);}
bool sxbl_emit(sx_context*c,uint64_t*p,uint64_t end,const sx_layout*l){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(*p>end||n>end-*p||!sxbl_add(c,l,*p))return false;*p+=n;return true;}
bool sxbl_skip(sx_context*c,uint64_t*p,uint64_t end,uint64_t n){if(*p>end||n>end-*p||!sxbl_span(c,*p,n))return false;*p+=n;return true;}
bool sxbl_byte(sx_context*c,uint64_t p,uint8_t*v){return sxbl_read(c,p,v,1);}
bool sxbl_numeric(sx_context*c,uint64_t*p,uint64_t end,unsigned z,bool sign,bool be){
 const sx_layout*const leu[]={&sxbl_wire_uint8_le,&sxbl_wire_uint16_le,&sxbl_wire_uint24_le,&sxbl_wire_uint32_le,&sxbl_wire_uint40_le,&sxbl_wire_uint48_le,&sxbl_wire_uint56_le,&sxbl_wire_uint64_le};
 const sx_layout*const les[]={&sxbl_wire_int8_le,&sxbl_wire_int16_le,&sxbl_wire_int24_le,&sxbl_wire_int32_le,&sxbl_wire_int40_le,&sxbl_wire_int48_le,&sxbl_wire_int56_le,&sxbl_wire_int64_le};
 const sx_layout*const beu[]={&sxbl_wire_uint8_be,&sxbl_wire_uint16_be,&sxbl_wire_uint24_be,&sxbl_wire_uint32_be,&sxbl_wire_uint40_be,&sxbl_wire_uint48_be,&sxbl_wire_uint56_be,&sxbl_wire_uint64_be};
 const sx_layout*const bes[]={&sxbl_wire_int8_be,&sxbl_wire_int16_be,&sxbl_wire_int24_be,&sxbl_wire_int32_be,&sxbl_wire_int40_be,&sxbl_wire_int48_be,&sxbl_wire_int56_be,&sxbl_wire_int64_be};
 return z&&z<=8&&sxbl_emit(c,p,end,(be?(sign?bes:beu):(sign?les:leu))[z-1]);}
bool sxbl_float(sx_context*c,uint64_t*p,uint64_t end,unsigned z,bool be){return(z==4||z==8)&&sxbl_emit(c,p,end,be?(z==4?&sxbl_wire_float32_be:&sxbl_wire_float64_be):(z==4?&sxbl_wire_float32_le:&sxbl_wire_float64_le));}
bool sxbl_length(sx_context*c,uint64_t*p,uint64_t end,unsigned z,bool be,bool count,uint64_t*v){const sx_layout*const le[]={&sxbl_wire_byte_size1_le,&sxbl_wire_byte_size2_le,&sxbl_wire_byte_size4_le,&sxbl_wire_byte_size8_le,&sxbl_wire_item_count1_le,&sxbl_wire_item_count2_le,&sxbl_wire_item_count4_le,&sxbl_wire_item_count8_le};const sx_layout*const big[]={&sxbl_wire_byte_size1_be,&sxbl_wire_byte_size2_be,&sxbl_wire_byte_size4_be,&sxbl_wire_byte_size8_be,&sxbl_wire_item_count1_be,&sxbl_wire_item_count2_be,&sxbl_wire_item_count4_be,&sxbl_wire_item_count8_be};unsigned k=z==1?0:z==2?1:z==4?2:z==8?3:8;return k<4&&sxbl_word(c,*p,z,be,v)&&sxbl_emit(c,p,end,(be?big:le)[k+(count?4:0)]);}
bool sxbl_string(sx_context*c,uint64_t*p,uint64_t end,unsigned z,bool be){uint64_t n;return sxbl_length(c,p,end,z,be,false,&n)&&sxbl_skip(c,p,end,n);}
static bool sxbl_der(sx_context*c,uint64_t*p,uint64_t end,unsigned depth){uint8_t b[2];if(depth>32||!sxbl_read(c,*p,b,2)||*p>end||end-*p<2)return false;unsigned z=b[1]&128?b[1]&127:0;uint64_t n=b[1];const sx_layout*const longh[]={&sxbl_der_header_long1,&sxbl_der_header_long2,&sxbl_der_header_long3,&sxbl_der_header_long4};if(b[1]&128){if(!z||z>4||!sxbl_word(c,*p+2,z,true,&n))return false;}if(n>end-*p-2||z>end-*p-2-n)return false;uint64_t stop=*p+2+z+n;if(!sxbl_emit(c,p,stop,z?longh[z-1]:&sxbl_der_header_short))return false;
 if(b[0]&32){while(*p<stop){size_t keep=c->count;uint64_t before=*p;if(!sxbl_der(c,p,stop,depth+1)){c->count=keep;*p=stop;return true;}if(*p<=before)return false;}return true;}if(b[0]==1&&n==1)return sxbl_emit(c,p,stop,&sxbl_der_boolean);if((b[0]==2||b[0]==10)&&n&&n<=8)return sxbl_numeric(c,p,stop,(unsigned)n,true,true);if(b[0]==3&&n){if(!sxbl_emit(c,p,stop,&sxbl_der_unused_bits))return false;}else if(b[0]==23&&n==13)return sxbl_emit(c,p,stop,&sxbl_der_utc_time);else if(b[0]==24&&n==15)return sxbl_emit(c,p,stop,&sxbl_der_generalized_time);*p=stop;return true;}
bool sxbl_var(sx_context*c,uint64_t*p,uint64_t end,unsigned role,uint64_t*out){
 const sx_layout*const v0[]={&sxbl_wire_byte_size_var1,&sxbl_wire_byte_size_var2,&sxbl_wire_byte_size_var3,&sxbl_wire_byte_size_var4,&sxbl_wire_byte_size_var5,&sxbl_wire_byte_size_var6,&sxbl_wire_byte_size_var7,&sxbl_wire_byte_size_var8,&sxbl_wire_byte_size_var9,&sxbl_wire_byte_size_var10};
 const sx_layout*const v1[]={&sxbl_wire_item_count_var1,&sxbl_wire_item_count_var2,&sxbl_wire_item_count_var3,&sxbl_wire_item_count_var4,&sxbl_wire_item_count_var5,&sxbl_wire_item_count_var6,&sxbl_wire_item_count_var7,&sxbl_wire_item_count_var8,&sxbl_wire_item_count_var9,&sxbl_wire_item_count_var10};
 const sx_layout*const v2[]={&sxbl_wire_integer_var1,&sxbl_wire_integer_var2,&sxbl_wire_integer_var3,&sxbl_wire_integer_var4,&sxbl_wire_integer_var5,&sxbl_wire_integer_var6,&sxbl_wire_integer_var7,&sxbl_wire_integer_var8,&sxbl_wire_integer_var9,&sxbl_wire_integer_var10};
 const sx_layout*const v3[]={&sxbl_wire_sequence_var1,&sxbl_wire_sequence_var2,&sxbl_wire_sequence_var3,&sxbl_wire_sequence_var4,&sxbl_wire_sequence_var5,&sxbl_wire_sequence_var6,&sxbl_wire_sequence_var7,&sxbl_wire_sequence_var8,&sxbl_wire_sequence_var9,&sxbl_wire_sequence_var10};
 const sx_layout*const v4[]={&sxbl_wire_unsigned_size_var1,&sxbl_wire_unsigned_size_var2,&sxbl_wire_unsigned_size_var3,&sxbl_wire_unsigned_size_var4,&sxbl_wire_unsigned_size_var5,&sxbl_wire_unsigned_size_var6,&sxbl_wire_unsigned_size_var7,&sxbl_wire_unsigned_size_var8,&sxbl_wire_unsigned_size_var9,&sxbl_wire_unsigned_size_var10};
 const sx_layout*const v5[]={&sxbl_wire_unsigned_count_var1,&sxbl_wire_unsigned_count_var2,&sxbl_wire_unsigned_count_var3,&sxbl_wire_unsigned_count_var4,&sxbl_wire_unsigned_count_var5,&sxbl_wire_unsigned_count_var6,&sxbl_wire_unsigned_count_var7,&sxbl_wire_unsigned_count_var8,&sxbl_wire_unsigned_count_var9,&sxbl_wire_unsigned_count_var10};
 const sx_layout*const v6[]={&sxbl_wire_field_id_var1,&sxbl_wire_field_id_var2,&sxbl_wire_field_id_var3,&sxbl_wire_field_id_var4,&sxbl_wire_field_id_var5,&sxbl_wire_field_id_var6,&sxbl_wire_field_id_var7,&sxbl_wire_field_id_var8,&sxbl_wire_field_id_var9,&sxbl_wire_field_id_var10};
 const sx_layout*const *arrays[]={v0,v1,v2,v3,v4,v5,v6};if(role>6)return false;uint64_t at=*p,v=0;unsigned n=0;uint8_t b;do{if(*p>=end||n==10||!sxbl_byte(c,(*p)++,&b)||(n==9&&(b&127)>1))return false;v|=(uint64_t)(b&127)<<(7*n++);}while(b&128);if(!sxbl_add(c,arrays[role][n-1],at))return false;*out=v;return true;}
static bool sxbl_ssh_string(sx_context*c,uint64_t*p,uint64_t end,uint64_t*start,uint64_t*n){if(!sxbl_word(c,*p,4,true,n)||!sxbl_emit(c,p,end,&sxbl_ssh_string_size))return false;*start=*p;return sxbl_skip(c,p,end,*n);}
static bool sxbl_ssh_list(sx_context*c,uint64_t p,uint64_t end){for(unsigned i=0;p<end&&i<512;i++){uint64_t at,n;if(!sxbl_ssh_string(c,&p,end,&at,&n))return false;}return p==end;}
bool sxbl_ssh(sx_context*c,bool cert){uint64_t p=0,end=(uint64_t)c->size,at,n,priv,lim;
 if(!cert){if(!sxbl_emit(c,&p,end,&sxbl_openssh_key_magic))return false;for(unsigned i=0;i<3;i++)if(!sxbl_ssh_string(c,&p,end,&at,&n))return false;if(!sxbl_emit(c,&p,end,&sxbl_ssh_key_count)||!sxbl_ssh_string(c,&p,end,&at,&n)||!sxbl_ssh_list(c,at,at+n)||!sxbl_ssh_string(c,&p,end,&priv,&n))return false;lim=priv+n;if(!sxbl_emit(c,&priv,lim,&sxbl_ssh_checkints))return false;for(unsigned i=0;i<4;i++)if(!sxbl_ssh_string(c,&priv,lim,&at,&n))return false;while(priv<lim)if(!sxbl_emit(c,&priv,lim,&sxbl_ssh_padding))return false;return p==end;}
 for(unsigned i=0;i<3;i++)if(!sxbl_ssh_string(c,&p,end,&at,&n))return false;if(!sxbl_emit(c,&p,end,&sxbl_ssh_certificate_serial)||!sxbl_ssh_string(c,&p,end,&at,&n)||!sxbl_ssh_string(c,&p,end,&at,&n)||!sxbl_ssh_list(c,at,at+n)||!sxbl_emit(c,&p,end,&sxbl_ssh_certificate_validity))return false;for(unsigned i=0;i<2;i++)if(!sxbl_ssh_string(c,&p,end,&at,&n)||!sxbl_ssh_list(c,at,at+n))return false;if(!sxbl_ssh_string(c,&p,end,&at,&n))return false;for(unsigned i=0;i<2;i++)if(!sxbl_ssh_string(c,&p,end,&at,&n)||!sxbl_ssh_list(c,at,at+n))return false;return p==end;}
static int sxbl_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxbl_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxbl_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+c->items[i].total_size>end)end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxbl_order);return !c->failed;}
static bool sx_binarylater_supports(xx_file_type_t t){switch(t){
case XX_FILE_TYPE_MONGODB_BSON:
case XX_FILE_TYPE_CBOR:
case XX_FILE_TYPE_PYTHON_PICKLE:
case XX_FILE_TYPE_MSGPACK:
case XX_FILE_TYPE_UBJSON:
case XX_FILE_TYPE_ERLANG_EXTERNAL_TERM:
case XX_FILE_TYPE_AMAZON_ION_BINARY:
case XX_FILE_TYPE_THRIFT_COMPACT:
case XX_FILE_TYPE_JAVA_SERIALIZATION:
case XX_FILE_TYPE_PYTHON_MARSHAL:
case XX_FILE_TYPE_DER:
case XX_FILE_TYPE_X509_CERTIFICATE:
case XX_FILE_TYPE_PKCS10_CSR:
case XX_FILE_TYPE_PKCS12_PFX:
case XX_FILE_TYPE_PKCS7_CMS:
case XX_FILE_TYPE_X509_CRL:
case XX_FILE_TYPE_OCSP_RESPONSE:
case XX_FILE_TYPE_PKCS8_PRIVATE_KEY:
case XX_FILE_TYPE_OPENSSH_PRIVATE_KEY:
case XX_FILE_TYPE_OPENSSH_CERTIFICATE:
case XX_FILE_TYPE_ETHEREUM_RLP:
case XX_FILE_TYPE_AVRO_OBJECT:
return true;default:return false;}}
static bool sx_binarylater_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;uint64_t p=0,end=(uint64_t)c->size;bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_MONGODB_BSON:ok=sx_mongodb_bson_build(c);break;
case XX_FILE_TYPE_CBOR:ok=sx_cbor_build(c);break;
case XX_FILE_TYPE_MSGPACK:ok=sx_msgpack_build(c);break;
case XX_FILE_TYPE_UBJSON:ok=sx_ubjson_build(c);break;
case XX_FILE_TYPE_ERLANG_EXTERNAL_TERM:ok=sx_erlang_external_term_build(c);break;
case XX_FILE_TYPE_AMAZON_ION_BINARY:ok=sx_amazon_ion_binary_build(c);break;
case XX_FILE_TYPE_THRIFT_COMPACT:ok=sx_thrift_compact_build(c);break;
case XX_FILE_TYPE_PYTHON_MARSHAL:ok=sx_python_marshal_build(c);break;
case XX_FILE_TYPE_PYTHON_PICKLE:ok=sx_python_pickle_build(c);break;
case XX_FILE_TYPE_JAVA_SERIALIZATION:ok=sx_java_serialization_build(c);break;
case XX_FILE_TYPE_OPENSSH_PRIVATE_KEY:ok=sx_openssh_private_key_build(c);break;
case XX_FILE_TYPE_OPENSSH_CERTIFICATE:ok=sx_openssh_certificate_build(c);break;
case XX_FILE_TYPE_ETHEREUM_RLP:ok=sx_ethereum_rlp_build(c);break;
case XX_FILE_TYPE_AVRO_OBJECT:ok=sx_avro_object_build(c);break;
case XX_FILE_TYPE_DER:case XX_FILE_TYPE_X509_CERTIFICATE:case XX_FILE_TYPE_PKCS10_CSR:case XX_FILE_TYPE_PKCS12_PFX:case XX_FILE_TYPE_PKCS7_CMS:case XX_FILE_TYPE_X509_CRL:case XX_FILE_TYPE_OCSP_RESPONSE:case XX_FILE_TYPE_PKCS8_PRIVATE_KEY:ok=sxbl_der(c,&p,end,0);break;
default:break;}
/* Preserve already framed physical metadata when optional or capped tails are opaque. */
(void)ok;return c->count&&sxbl_finish(c);}
const sx_family sx_binarylater_family={sx_binarylater_supports,sx_binarylater_build,sx_binarylater_layouts,SX_COUNT(sx_binarylater_layouts),sx_binarylater_comment};
