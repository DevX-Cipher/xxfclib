/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * matroska data structures, moved out of the videotail schema family. */
#include "../../xx_format_schema_videotail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvt_ebml_id1_fields[] = {
 SX_FIELD("element_id","uint8",0,1,SX_ID),
};
const sx_layout sxvt_ebml_id1 = {UINT32_C(0x60390046),"ebml_id1",sxvt_ebml_id1_fields,SX_COUNT(sxvt_ebml_id1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_id2_fields[] = {
 SX_FIELD("element_id","uint16",0,2,SX_ID),
};
const sx_layout sxvt_ebml_id2 = {UINT32_C(0x60390047),"ebml_id2",sxvt_ebml_id2_fields,SX_COUNT(sxvt_ebml_id2_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_id3_fields[] = {
 SX_FIELD("element_id","uint24",0,3,SX_ID),
};
const sx_layout sxvt_ebml_id3 = {UINT32_C(0x60390048),"ebml_id3",sxvt_ebml_id3_fields,SX_COUNT(sxvt_ebml_id3_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_id4_fields[] = {
 SX_FIELD("element_id","uint32",0,4,SX_ID),
};
const sx_layout sxvt_ebml_id4 = {UINT32_C(0x60390049),"ebml_id4",sxvt_ebml_id4_fields,SX_COUNT(sxvt_ebml_id4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size1_fields[] = {
 SX_FIELD("encoded_size","uint8",0,1,SX_NONE),
};
const sx_layout sxvt_ebml_size1 = {UINT32_C(0x6039004a),"ebml_size1",sxvt_ebml_size1_fields,SX_COUNT(sxvt_ebml_size1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track1_fields[] = {
 SX_FIELD("encoded_track","uint8",0,1,SX_NONE),
};
const sx_layout sxvt_matroska_track1 = {UINT32_C(0x6039004b),"matroska_track1",sxvt_matroska_track1_fields,SX_COUNT(sxvt_matroska_track1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size1_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint8",0,1,SX_NONE),
};
const sx_layout sxvt_matroska_lace_size1 = {UINT32_C(0x6039004c),"matroska_lace_size1",sxvt_matroska_lace_size1_fields,SX_COUNT(sxvt_matroska_lace_size1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta1_fields[] = {
 SX_FIELD("encoded_size_delta","uint8",0,1,SX_NONE),
};
const sx_layout sxvt_matroska_lace_delta1 = {UINT32_C(0x6039004d),"matroska_lace_delta1",sxvt_matroska_lace_delta1_fields,SX_COUNT(sxvt_matroska_lace_delta1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint1_fields[] = {
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
const sx_layout sxvt_matroska_uint1 = {UINT32_C(0x6039004e),"matroska_uint1",sxvt_matroska_uint1_fields,SX_COUNT(sxvt_matroska_uint1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset1_fields[] = {
 SX_FIELD("relative_offset","uint8",0,1,SX_OFFSET),
};
const sx_layout sxvt_matroska_offset1 = {UINT32_C(0x6039004f),"matroska_offset1",sxvt_matroska_offset1_fields,SX_COUNT(sxvt_matroska_offset1_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size2_fields[] = {
 SX_FIELD("encoded_size","uint16",0,2,SX_NONE),
};
const sx_layout sxvt_ebml_size2 = {UINT32_C(0x60390050),"ebml_size2",sxvt_ebml_size2_fields,SX_COUNT(sxvt_ebml_size2_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track2_fields[] = {
 SX_FIELD("encoded_track","uint16",0,2,SX_NONE),
};
const sx_layout sxvt_matroska_track2 = {UINT32_C(0x60390051),"matroska_track2",sxvt_matroska_track2_fields,SX_COUNT(sxvt_matroska_track2_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size2_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint16",0,2,SX_NONE),
};
const sx_layout sxvt_matroska_lace_size2 = {UINT32_C(0x60390052),"matroska_lace_size2",sxvt_matroska_lace_size2_fields,SX_COUNT(sxvt_matroska_lace_size2_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta2_fields[] = {
 SX_FIELD("encoded_size_delta","uint16",0,2,SX_NONE),
};
const sx_layout sxvt_matroska_lace_delta2 = {UINT32_C(0x60390053),"matroska_lace_delta2",sxvt_matroska_lace_delta2_fields,SX_COUNT(sxvt_matroska_lace_delta2_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint2_fields[] = {
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
const sx_layout sxvt_matroska_uint2 = {UINT32_C(0x60390054),"matroska_uint2",sxvt_matroska_uint2_fields,SX_COUNT(sxvt_matroska_uint2_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset2_fields[] = {
 SX_FIELD("relative_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxvt_matroska_offset2 = {UINT32_C(0x60390055),"matroska_offset2",sxvt_matroska_offset2_fields,SX_COUNT(sxvt_matroska_offset2_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size3_fields[] = {
 SX_FIELD("encoded_size","uint24",0,3,SX_NONE),
};
const sx_layout sxvt_ebml_size3 = {UINT32_C(0x60390056),"ebml_size3",sxvt_ebml_size3_fields,SX_COUNT(sxvt_ebml_size3_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track3_fields[] = {
 SX_FIELD("encoded_track","uint24",0,3,SX_NONE),
};
const sx_layout sxvt_matroska_track3 = {UINT32_C(0x60390057),"matroska_track3",sxvt_matroska_track3_fields,SX_COUNT(sxvt_matroska_track3_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size3_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint24",0,3,SX_NONE),
};
const sx_layout sxvt_matroska_lace_size3 = {UINT32_C(0x60390058),"matroska_lace_size3",sxvt_matroska_lace_size3_fields,SX_COUNT(sxvt_matroska_lace_size3_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta3_fields[] = {
 SX_FIELD("encoded_size_delta","uint24",0,3,SX_NONE),
};
const sx_layout sxvt_matroska_lace_delta3 = {UINT32_C(0x60390059),"matroska_lace_delta3",sxvt_matroska_lace_delta3_fields,SX_COUNT(sxvt_matroska_lace_delta3_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint3_fields[] = {
 SX_FIELD("value","uint24",0,3,SX_NONE),
};
const sx_layout sxvt_matroska_uint3 = {UINT32_C(0x6039005a),"matroska_uint3",sxvt_matroska_uint3_fields,SX_COUNT(sxvt_matroska_uint3_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset3_fields[] = {
 SX_FIELD("relative_offset","uint24",0,3,SX_OFFSET),
};
const sx_layout sxvt_matroska_offset3 = {UINT32_C(0x6039005b),"matroska_offset3",sxvt_matroska_offset3_fields,SX_COUNT(sxvt_matroska_offset3_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size4_fields[] = {
 SX_FIELD("encoded_size","uint32",0,4,SX_NONE),
};
const sx_layout sxvt_ebml_size4 = {UINT32_C(0x6039005c),"ebml_size4",sxvt_ebml_size4_fields,SX_COUNT(sxvt_ebml_size4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track4_fields[] = {
 SX_FIELD("encoded_track","uint32",0,4,SX_NONE),
};
const sx_layout sxvt_matroska_track4 = {UINT32_C(0x6039005d),"matroska_track4",sxvt_matroska_track4_fields,SX_COUNT(sxvt_matroska_track4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size4_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint32",0,4,SX_NONE),
};
const sx_layout sxvt_matroska_lace_size4 = {UINT32_C(0x6039005e),"matroska_lace_size4",sxvt_matroska_lace_size4_fields,SX_COUNT(sxvt_matroska_lace_size4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta4_fields[] = {
 SX_FIELD("encoded_size_delta","uint32",0,4,SX_NONE),
};
const sx_layout sxvt_matroska_lace_delta4 = {UINT32_C(0x6039005f),"matroska_lace_delta4",sxvt_matroska_lace_delta4_fields,SX_COUNT(sxvt_matroska_lace_delta4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint4_fields[] = {
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
const sx_layout sxvt_matroska_uint4 = {UINT32_C(0x60390060),"matroska_uint4",sxvt_matroska_uint4_fields,SX_COUNT(sxvt_matroska_uint4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset4_fields[] = {
 SX_FIELD("relative_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxvt_matroska_offset4 = {UINT32_C(0x60390061),"matroska_offset4",sxvt_matroska_offset4_fields,SX_COUNT(sxvt_matroska_offset4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size5_fields[] = {
 SX_FIELD("encoded_size","uint40",0,5,SX_NONE),
};
const sx_layout sxvt_ebml_size5 = {UINT32_C(0x60390062),"ebml_size5",sxvt_ebml_size5_fields,SX_COUNT(sxvt_ebml_size5_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track5_fields[] = {
 SX_FIELD("encoded_track","uint40",0,5,SX_NONE),
};
const sx_layout sxvt_matroska_track5 = {UINT32_C(0x60390063),"matroska_track5",sxvt_matroska_track5_fields,SX_COUNT(sxvt_matroska_track5_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size5_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint40",0,5,SX_NONE),
};
const sx_layout sxvt_matroska_lace_size5 = {UINT32_C(0x60390064),"matroska_lace_size5",sxvt_matroska_lace_size5_fields,SX_COUNT(sxvt_matroska_lace_size5_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta5_fields[] = {
 SX_FIELD("encoded_size_delta","uint40",0,5,SX_NONE),
};
const sx_layout sxvt_matroska_lace_delta5 = {UINT32_C(0x60390065),"matroska_lace_delta5",sxvt_matroska_lace_delta5_fields,SX_COUNT(sxvt_matroska_lace_delta5_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint5_fields[] = {
 SX_FIELD("value","uint40",0,5,SX_NONE),
};
const sx_layout sxvt_matroska_uint5 = {UINT32_C(0x60390066),"matroska_uint5",sxvt_matroska_uint5_fields,SX_COUNT(sxvt_matroska_uint5_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset5_fields[] = {
 SX_FIELD("relative_offset","uint40",0,5,SX_OFFSET),
};
const sx_layout sxvt_matroska_offset5 = {UINT32_C(0x60390067),"matroska_offset5",sxvt_matroska_offset5_fields,SX_COUNT(sxvt_matroska_offset5_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size6_fields[] = {
 SX_FIELD("encoded_size","uint48",0,6,SX_NONE),
};
const sx_layout sxvt_ebml_size6 = {UINT32_C(0x60390068),"ebml_size6",sxvt_ebml_size6_fields,SX_COUNT(sxvt_ebml_size6_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track6_fields[] = {
 SX_FIELD("encoded_track","uint48",0,6,SX_NONE),
};
const sx_layout sxvt_matroska_track6 = {UINT32_C(0x60390069),"matroska_track6",sxvt_matroska_track6_fields,SX_COUNT(sxvt_matroska_track6_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size6_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint48",0,6,SX_NONE),
};
const sx_layout sxvt_matroska_lace_size6 = {UINT32_C(0x6039006a),"matroska_lace_size6",sxvt_matroska_lace_size6_fields,SX_COUNT(sxvt_matroska_lace_size6_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta6_fields[] = {
 SX_FIELD("encoded_size_delta","uint48",0,6,SX_NONE),
};
const sx_layout sxvt_matroska_lace_delta6 = {UINT32_C(0x6039006b),"matroska_lace_delta6",sxvt_matroska_lace_delta6_fields,SX_COUNT(sxvt_matroska_lace_delta6_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint6_fields[] = {
 SX_FIELD("value","uint48",0,6,SX_NONE),
};
const sx_layout sxvt_matroska_uint6 = {UINT32_C(0x6039006c),"matroska_uint6",sxvt_matroska_uint6_fields,SX_COUNT(sxvt_matroska_uint6_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset6_fields[] = {
 SX_FIELD("relative_offset","uint48",0,6,SX_OFFSET),
};
const sx_layout sxvt_matroska_offset6 = {UINT32_C(0x6039006d),"matroska_offset6",sxvt_matroska_offset6_fields,SX_COUNT(sxvt_matroska_offset6_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size7_fields[] = {
 SX_FIELD("encoded_size","uint56",0,7,SX_NONE),
};
const sx_layout sxvt_ebml_size7 = {UINT32_C(0x6039006e),"ebml_size7",sxvt_ebml_size7_fields,SX_COUNT(sxvt_ebml_size7_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track7_fields[] = {
 SX_FIELD("encoded_track","uint56",0,7,SX_NONE),
};
const sx_layout sxvt_matroska_track7 = {UINT32_C(0x6039006f),"matroska_track7",sxvt_matroska_track7_fields,SX_COUNT(sxvt_matroska_track7_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size7_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint56",0,7,SX_NONE),
};
const sx_layout sxvt_matroska_lace_size7 = {UINT32_C(0x60390070),"matroska_lace_size7",sxvt_matroska_lace_size7_fields,SX_COUNT(sxvt_matroska_lace_size7_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta7_fields[] = {
 SX_FIELD("encoded_size_delta","uint56",0,7,SX_NONE),
};
const sx_layout sxvt_matroska_lace_delta7 = {UINT32_C(0x60390071),"matroska_lace_delta7",sxvt_matroska_lace_delta7_fields,SX_COUNT(sxvt_matroska_lace_delta7_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint7_fields[] = {
 SX_FIELD("value","uint56",0,7,SX_NONE),
};
const sx_layout sxvt_matroska_uint7 = {UINT32_C(0x60390072),"matroska_uint7",sxvt_matroska_uint7_fields,SX_COUNT(sxvt_matroska_uint7_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset7_fields[] = {
 SX_FIELD("relative_offset","uint56",0,7,SX_OFFSET),
};
const sx_layout sxvt_matroska_offset7 = {UINT32_C(0x60390073),"matroska_offset7",sxvt_matroska_offset7_fields,SX_COUNT(sxvt_matroska_offset7_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_ebml_size8_fields[] = {
 SX_FIELD("encoded_size","uint64",0,8,SX_NONE),
};
const sx_layout sxvt_ebml_size8 = {UINT32_C(0x60390074),"ebml_size8",sxvt_ebml_size8_fields,SX_COUNT(sxvt_ebml_size8_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_track8_fields[] = {
 SX_FIELD("encoded_track","uint64",0,8,SX_NONE),
};
const sx_layout sxvt_matroska_track8 = {UINT32_C(0x60390075),"matroska_track8",sxvt_matroska_track8_fields,SX_COUNT(sxvt_matroska_track8_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_size8_fields[] = {
 SX_FIELD("encoded_first_frame_size","uint64",0,8,SX_NONE),
};
const sx_layout sxvt_matroska_lace_size8 = {UINT32_C(0x60390076),"matroska_lace_size8",sxvt_matroska_lace_size8_fields,SX_COUNT(sxvt_matroska_lace_size8_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_delta8_fields[] = {
 SX_FIELD("encoded_size_delta","uint64",0,8,SX_NONE),
};
const sx_layout sxvt_matroska_lace_delta8 = {UINT32_C(0x60390077),"matroska_lace_delta8",sxvt_matroska_lace_delta8_fields,SX_COUNT(sxvt_matroska_lace_delta8_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_uint8_fields[] = {
 SX_FIELD("value","uint64",0,8,SX_NONE),
};
const sx_layout sxvt_matroska_uint8 = {UINT32_C(0x60390078),"matroska_uint8",sxvt_matroska_uint8_fields,SX_COUNT(sxvt_matroska_uint8_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_offset8_fields[] = {
 SX_FIELD("relative_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxvt_matroska_offset8 = {UINT32_C(0x60390079),"matroska_offset8",sxvt_matroska_offset8_fields,SX_COUNT(sxvt_matroska_offset8_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_date_fields[] = {
 SX_FIELD("nanoseconds_since_2001","int64",0,8,SX_NONE),
};
const sx_layout sxvt_matroska_date = {UINT32_C(0x6039007a),"matroska_date",sxvt_matroska_date_fields,SX_COUNT(sxvt_matroska_date_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_float4_fields[] = {
 SX_FIELD("value","float32",0,4,SX_NONE),
};
const sx_layout sxvt_matroska_float4 = {UINT32_C(0x6039007b),"matroska_float4",sxvt_matroska_float4_fields,SX_COUNT(sxvt_matroska_float4_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_float8_fields[] = {
 SX_FIELD("value","float64",0,8,SX_NONE),
};
const sx_layout sxvt_matroska_float8 = {UINT32_C(0x6039007c),"matroska_float8",sxvt_matroska_float8_fields,SX_COUNT(sxvt_matroska_float8_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_crc32_fields[] = {
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxvt_matroska_crc32 = {UINT32_C(0x6039007d),"matroska_crc32",sxvt_matroska_crc32_fields,SX_COUNT(sxvt_matroska_crc32_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_matroska_block_fields[] = {
 SX_FIELD("relative_timestamp","int16",0,2,SX_NONE),
 SX_FIELD("flags","uint8",2,1,SX_FLAGS),
};
const sx_layout sxvt_matroska_block = {UINT32_C(0x6039007e),"matroska_block",sxvt_matroska_block_fields,SX_COUNT(sxvt_matroska_block_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_matroska_lace_count_fields[] = {
 SX_FIELD("frame_count_minus_one","uint8",0,1,SX_NONE),
};
const sx_layout sxvt_matroska_lace_count = {UINT32_C(0x6039007f),"matroska_lace_count",sxvt_matroska_lace_count_fields,SX_COUNT(sxvt_matroska_lace_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_matroska_xiph_size_fields[] = {
 SX_FIELD("size_part","uint8",0,1,SX_NONE),
};
const sx_layout sxvt_matroska_xiph_size = {UINT32_C(0x60390080),"matroska_xiph_size",sxvt_matroska_xiph_size_fields,SX_COUNT(sxvt_matroska_xiph_size_fields),SX_LE};
#define SXVT_LIMIT 20000U
static bool sxvt_vint(sx_context*c,uint64_t*p,uint64_t end,bool id,uint64_t*v,unsigned*w){uint8_t b[8];if(*p>=end||!sxvt_byte(c,*p,b)||!b[0])return false;unsigned z=1;uint8_t mask=128;while(!(b[0]&mask)){z++;mask>>=1;}if(z>(id?4U:8U)||z>end-*p||!sxvt_read(c,*p,b,z))return false;*v=id?b[0]:b[0]&((unsigned)mask-1U);for(unsigned i=1;i<z;i++)*v=(*v<<8)|b[i];*p+=z;*w=z;return true;}
static const sx_layout*const sxvt_ebml_ids[]={&sxvt_ebml_id1,&sxvt_ebml_id2,&sxvt_ebml_id3,&sxvt_ebml_id4};
static const sx_layout*const sxvt_sizes[]={&sxvt_ebml_size1,&sxvt_ebml_size2,&sxvt_ebml_size3,&sxvt_ebml_size4,&sxvt_ebml_size5,&sxvt_ebml_size6,&sxvt_ebml_size7,&sxvt_ebml_size8};
static const sx_layout*const sxvt_tracks[]={&sxvt_matroska_track1,&sxvt_matroska_track2,&sxvt_matroska_track3,&sxvt_matroska_track4,&sxvt_matroska_track5,&sxvt_matroska_track6,&sxvt_matroska_track7,&sxvt_matroska_track8};
static const sx_layout*const sxvt_laces[]={&sxvt_matroska_lace_size1,&sxvt_matroska_lace_size2,&sxvt_matroska_lace_size3,&sxvt_matroska_lace_size4,&sxvt_matroska_lace_size5,&sxvt_matroska_lace_size6,&sxvt_matroska_lace_size7,&sxvt_matroska_lace_size8};
static const sx_layout*const sxvt_deltas[]={&sxvt_matroska_lace_delta1,&sxvt_matroska_lace_delta2,&sxvt_matroska_lace_delta3,&sxvt_matroska_lace_delta4,&sxvt_matroska_lace_delta5,&sxvt_matroska_lace_delta6,&sxvt_matroska_lace_delta7,&sxvt_matroska_lace_delta8};
static const sx_layout*const sxvt_uints[]={&sxvt_matroska_uint1,&sxvt_matroska_uint2,&sxvt_matroska_uint3,&sxvt_matroska_uint4,&sxvt_matroska_uint5,&sxvt_matroska_uint6,&sxvt_matroska_uint7,&sxvt_matroska_uint8};
static const sx_layout*const sxvt_offsets[]={&sxvt_matroska_offset1,&sxvt_matroska_offset2,&sxvt_matroska_offset3,&sxvt_matroska_offset4,&sxvt_matroska_offset5,&sxvt_matroska_offset6,&sxvt_matroska_offset7,&sxvt_matroska_offset8};
static bool sxvt_mkblock(sx_context*c,uint64_t p,uint64_t end){uint64_t v,start=p;unsigned z;uint8_t b;if(!sxvt_vint(c,&p,end,false,&v,&z)||!sxvt_add(c,sxvt_tracks[z-1],start)||end-p<3||!sxvt_byte(c,p+2,&b)||!sxvt_add(c,&sxvt_matroska_block,p))return false;p+=3;unsigned lace=(b>>1)&3;if(lace){if(p==end||!sxvt_byte(c,p,&b)||!sxvt_add(c,&sxvt_matroska_lace_count,p))return false;p++;unsigned count=(unsigned)b+1;if(lace==1){for(unsigned i=1;i<count;i++){do{if(p==end||!sxvt_byte(c,p,&b)||!sxvt_add(c,&sxvt_matroska_xiph_size,p++))return false;}while(b==255);}}else if(lace==3){for(unsigned i=1;i<count;i++){start=p;if(!sxvt_vint(c,&p,end,false,&v,&z)||!sxvt_add(c,i==1?sxvt_laces[z-1]:sxvt_deltas[z-1],start))return false;}}}return true;}
static bool sxvt_mkmaster(uint64_t id){switch(id){case 0x1A45DFA3:case 0x18538067:case 0x1549A966:case 0x1654AE6B:case 0xAE:case 0x1F43B675:case 0xA0:case 0xE0:case 0xE1:case 0x6D80:case 0x6240:case 0x5034:case 0x5035:case 0x1043A770:case 0x45B9:case 0xB6:case 0x80:case 0x1254C367:case 0x7373:case 0x63C0:case 0x67C8:case 0x1941A469:case 0x61A7:case 0x114D9B74:case 0x4DBB:case 0x1C53BB6B:case 0xBB:case 0xB7:return true;default:return false;}}
static unsigned sxvt_mkkind(uint64_t id){switch(id){case 0x42F7:case 0x4286:case 0x42F2:case 0x42F3:case 0x4287:case 0x4285:case 0x2AD7B1:case 0xD7:case 0x73C5:case 0x83:case 0xB9:case 0x88:case 0x55AA:case 0x9C:case 0x6DE7:case 0x6DF8:case 0x23E383:case 0xB0:case 0xBA:case 0x54B0:case 0x54BA:case 0x54B2:case 0x9F:case 0x6264:case 0xE7:case 0xF7:case 0x5378:case 0xB3:case 0x9B:return 1;
 case 0x53AC:case 0xF1:case 0xA7:case 0xF0:return 2;
 case 0x4489:case 0xB5:case 0x78B5:case 0x23314F:return 3;
 case 0x4461:return 4;case 0xBF:return 5;default:return 0;}}
static bool sxvt_mk(sx_context*c,uint64_t p,uint64_t end,unsigned depth,uint64_t parent){if(depth>24)return false;while(p<end&&c->count<SXVT_LIMIT){uint64_t id,n,a=p;unsigned iz,sz;if(!sxvt_vint(c,&p,end,true,&id,&iz))return false;uint64_t b=p;if(!sxvt_vint(c,&p,end,false,&n,&sz))return false;bool unknown=n==((UINT64_C(1)<<(7*sz))-1);if(unknown){if(id!=0x18538067)return false;n=end-p;}if(n>end-p)return false;uint64_t stop=p+n;if(!sxvt_add(c,sxvt_ebml_ids[iz-1],a)||!sxvt_add(c,sxvt_sizes[sz-1],b))return false;
 if(sxvt_mkmaster(id)){(void)sxvt_mk(c,p,stop,depth+1,id);}else if((id==0xA3&&parent==0x1F43B675)||(id==0xA1&&parent==0xA0)){(void)sxvt_mkblock(c,p,stop);}else{unsigned kind=sxvt_mkkind(id);const sx_layout*l=NULL;if((kind==1||kind==2)&&n&&n<=8)l=(kind==1?sxvt_uints:sxvt_offsets)[n-1];else if(kind==3&&(n==4||n==8))l=n==4?&sxvt_matroska_float4:&sxvt_matroska_float8;else if(kind==4&&n==8)l=&sxvt_matroska_date;else if(kind==5&&n==4)l=&sxvt_matroska_crc32;if(l&&!sxvt_add(c,l,p))return false;}p=stop;}return p==end;}
bool sx_matroska_build(sx_context*c)
{
 return sxvt_mk(c,0,(uint64_t)c->size,0,0);
}
