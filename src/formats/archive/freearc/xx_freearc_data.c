/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FREEARC data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_freearc_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("flags","uint16",4,2,SX_FLAGS),
 SX_FIELD("version","uint16",6,2,SX_NONE),
};
const sx_layout sxan_freearc_header = {UINT32_C(0x6077006c),"freearc_header",sxan_freearc_header_fields,SX_COUNT(sxan_freearc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_magic_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxan_freearc_magic = {UINT32_C(0x6077006d),"freearc_magic",sxan_freearc_magic_fields,SX_COUNT(sxan_freearc_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_crc_fields[] = {
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxan_freearc_crc = {UINT32_C(0x6077006e),"freearc_crc",sxan_freearc_crc_fields,SX_COUNT(sxan_freearc_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_time_fields[] = {
 SX_FIELD("modification_time","uint32",0,4,SX_TIME),
};
const sx_layout sxan_freearc_time = {UINT32_C(0x6077006f),"freearc_time",sxan_freearc_time_fields,SX_COUNT(sxan_freearc_time_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_folder_fields[] = {
 SX_FIELD("is_folder","uint8",0,1,SX_NONE),
};
const sx_layout sxan_freearc_folder = {UINT32_C(0x60770070),"freearc_folder",sxan_freearc_folder_fields,SX_COUNT(sxan_freearc_folder_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_method_fields[] = {
 SX_FIELD("method","char",0,0,SX_NONE),
};
const sx_layout sxan_freearc_method = {UINT32_C(0x60770071),"freearc_method",sxan_freearc_method_fields,SX_COUNT(sxan_freearc_method_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type1_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,1,SX_NONE),
};
const sx_layout sxan_freearc_type1 = {UINT32_C(0x60770072),"freearc_type1",sxan_freearc_type1_fields,SX_COUNT(sxan_freearc_type1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count1_fields[] = {
 SX_FIELD("count","freearc_uint",0,1,SX_COUNT_PROP),
};
const sx_layout sxan_freearc_count1 = {UINT32_C(0x60770073),"freearc_count1",sxan_freearc_count1_fields,SX_COUNT(sxan_freearc_count1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset1_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,1,SX_OFFSET),
};
const sx_layout sxan_freearc_offset1 = {UINT32_C(0x60770074),"freearc_offset1",sxan_freearc_offset1_fields,SX_COUNT(sxan_freearc_offset1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size1_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,1,SX_SIZE),
};
const sx_layout sxan_freearc_size1 = {UINT32_C(0x60770075),"freearc_size1",sxan_freearc_size1_fields,SX_COUNT(sxan_freearc_size1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed1_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,1,SX_SIZE),
};
const sx_layout sxan_freearc_packed1 = {UINT32_C(0x60770076),"freearc_packed1",sxan_freearc_packed1_fields,SX_COUNT(sxan_freearc_packed1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index1_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,1,SX_NONE),
};
const sx_layout sxan_freearc_index1 = {UINT32_C(0x60770077),"freearc_index1",sxan_freearc_index1_fields,SX_COUNT(sxan_freearc_index1_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type2_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,2,SX_NONE),
};
const sx_layout sxan_freearc_type2 = {UINT32_C(0x60770078),"freearc_type2",sxan_freearc_type2_fields,SX_COUNT(sxan_freearc_type2_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count2_fields[] = {
 SX_FIELD("count","freearc_uint",0,2,SX_COUNT_PROP),
};
const sx_layout sxan_freearc_count2 = {UINT32_C(0x60770079),"freearc_count2",sxan_freearc_count2_fields,SX_COUNT(sxan_freearc_count2_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset2_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,2,SX_OFFSET),
};
const sx_layout sxan_freearc_offset2 = {UINT32_C(0x6077007a),"freearc_offset2",sxan_freearc_offset2_fields,SX_COUNT(sxan_freearc_offset2_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size2_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,2,SX_SIZE),
};
const sx_layout sxan_freearc_size2 = {UINT32_C(0x6077007b),"freearc_size2",sxan_freearc_size2_fields,SX_COUNT(sxan_freearc_size2_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed2_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,2,SX_SIZE),
};
const sx_layout sxan_freearc_packed2 = {UINT32_C(0x6077007c),"freearc_packed2",sxan_freearc_packed2_fields,SX_COUNT(sxan_freearc_packed2_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index2_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,2,SX_NONE),
};
const sx_layout sxan_freearc_index2 = {UINT32_C(0x6077007d),"freearc_index2",sxan_freearc_index2_fields,SX_COUNT(sxan_freearc_index2_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type3_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,3,SX_NONE),
};
const sx_layout sxan_freearc_type3 = {UINT32_C(0x6077007e),"freearc_type3",sxan_freearc_type3_fields,SX_COUNT(sxan_freearc_type3_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count3_fields[] = {
 SX_FIELD("count","freearc_uint",0,3,SX_COUNT_PROP),
};
const sx_layout sxan_freearc_count3 = {UINT32_C(0x6077007f),"freearc_count3",sxan_freearc_count3_fields,SX_COUNT(sxan_freearc_count3_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset3_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,3,SX_OFFSET),
};
const sx_layout sxan_freearc_offset3 = {UINT32_C(0x60770080),"freearc_offset3",sxan_freearc_offset3_fields,SX_COUNT(sxan_freearc_offset3_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size3_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,3,SX_SIZE),
};
const sx_layout sxan_freearc_size3 = {UINT32_C(0x60770081),"freearc_size3",sxan_freearc_size3_fields,SX_COUNT(sxan_freearc_size3_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed3_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,3,SX_SIZE),
};
const sx_layout sxan_freearc_packed3 = {UINT32_C(0x60770082),"freearc_packed3",sxan_freearc_packed3_fields,SX_COUNT(sxan_freearc_packed3_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index3_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,3,SX_NONE),
};
const sx_layout sxan_freearc_index3 = {UINT32_C(0x60770083),"freearc_index3",sxan_freearc_index3_fields,SX_COUNT(sxan_freearc_index3_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type4_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,4,SX_NONE),
};
const sx_layout sxan_freearc_type4 = {UINT32_C(0x60770084),"freearc_type4",sxan_freearc_type4_fields,SX_COUNT(sxan_freearc_type4_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count4_fields[] = {
 SX_FIELD("count","freearc_uint",0,4,SX_COUNT_PROP),
};
const sx_layout sxan_freearc_count4 = {UINT32_C(0x60770085),"freearc_count4",sxan_freearc_count4_fields,SX_COUNT(sxan_freearc_count4_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset4_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,4,SX_OFFSET),
};
const sx_layout sxan_freearc_offset4 = {UINT32_C(0x60770086),"freearc_offset4",sxan_freearc_offset4_fields,SX_COUNT(sxan_freearc_offset4_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size4_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,4,SX_SIZE),
};
const sx_layout sxan_freearc_size4 = {UINT32_C(0x60770087),"freearc_size4",sxan_freearc_size4_fields,SX_COUNT(sxan_freearc_size4_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed4_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,4,SX_SIZE),
};
const sx_layout sxan_freearc_packed4 = {UINT32_C(0x60770088),"freearc_packed4",sxan_freearc_packed4_fields,SX_COUNT(sxan_freearc_packed4_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index4_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,4,SX_NONE),
};
const sx_layout sxan_freearc_index4 = {UINT32_C(0x60770089),"freearc_index4",sxan_freearc_index4_fields,SX_COUNT(sxan_freearc_index4_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type5_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,5,SX_NONE),
};
const sx_layout sxan_freearc_type5 = {UINT32_C(0x6077008a),"freearc_type5",sxan_freearc_type5_fields,SX_COUNT(sxan_freearc_type5_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count5_fields[] = {
 SX_FIELD("count","freearc_uint",0,5,SX_COUNT_PROP),
};
const sx_layout sxan_freearc_count5 = {UINT32_C(0x6077008b),"freearc_count5",sxan_freearc_count5_fields,SX_COUNT(sxan_freearc_count5_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset5_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,5,SX_OFFSET),
};
const sx_layout sxan_freearc_offset5 = {UINT32_C(0x6077008c),"freearc_offset5",sxan_freearc_offset5_fields,SX_COUNT(sxan_freearc_offset5_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size5_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,5,SX_SIZE),
};
const sx_layout sxan_freearc_size5 = {UINT32_C(0x6077008d),"freearc_size5",sxan_freearc_size5_fields,SX_COUNT(sxan_freearc_size5_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed5_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,5,SX_SIZE),
};
const sx_layout sxan_freearc_packed5 = {UINT32_C(0x6077008e),"freearc_packed5",sxan_freearc_packed5_fields,SX_COUNT(sxan_freearc_packed5_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index5_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,5,SX_NONE),
};
const sx_layout sxan_freearc_index5 = {UINT32_C(0x6077008f),"freearc_index5",sxan_freearc_index5_fields,SX_COUNT(sxan_freearc_index5_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type6_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,6,SX_NONE),
};
const sx_layout sxan_freearc_type6 = {UINT32_C(0x60770090),"freearc_type6",sxan_freearc_type6_fields,SX_COUNT(sxan_freearc_type6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count6_fields[] = {
 SX_FIELD("count","freearc_uint",0,6,SX_COUNT_PROP),
};
const sx_layout sxan_freearc_count6 = {UINT32_C(0x60770091),"freearc_count6",sxan_freearc_count6_fields,SX_COUNT(sxan_freearc_count6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset6_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,6,SX_OFFSET),
};
const sx_layout sxan_freearc_offset6 = {UINT32_C(0x60770092),"freearc_offset6",sxan_freearc_offset6_fields,SX_COUNT(sxan_freearc_offset6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size6_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,6,SX_SIZE),
};
const sx_layout sxan_freearc_size6 = {UINT32_C(0x60770093),"freearc_size6",sxan_freearc_size6_fields,SX_COUNT(sxan_freearc_size6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed6_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,6,SX_SIZE),
};
const sx_layout sxan_freearc_packed6 = {UINT32_C(0x60770094),"freearc_packed6",sxan_freearc_packed6_fields,SX_COUNT(sxan_freearc_packed6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index6_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,6,SX_NONE),
};
const sx_layout sxan_freearc_index6 = {UINT32_C(0x60770095),"freearc_index6",sxan_freearc_index6_fields,SX_COUNT(sxan_freearc_index6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type7_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,7,SX_NONE),
};
const sx_layout sxan_freearc_type7 = {UINT32_C(0x60770096),"freearc_type7",sxan_freearc_type7_fields,SX_COUNT(sxan_freearc_type7_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count7_fields[] = {
 SX_FIELD("count","freearc_uint",0,7,SX_COUNT_PROP),
};
const sx_layout sxan_freearc_count7 = {UINT32_C(0x60770097),"freearc_count7",sxan_freearc_count7_fields,SX_COUNT(sxan_freearc_count7_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset7_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,7,SX_OFFSET),
};
const sx_layout sxan_freearc_offset7 = {UINT32_C(0x60770098),"freearc_offset7",sxan_freearc_offset7_fields,SX_COUNT(sxan_freearc_offset7_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size7_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,7,SX_SIZE),
};
const sx_layout sxan_freearc_size7 = {UINT32_C(0x60770099),"freearc_size7",sxan_freearc_size7_fields,SX_COUNT(sxan_freearc_size7_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed7_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,7,SX_SIZE),
};
const sx_layout sxan_freearc_packed7 = {UINT32_C(0x6077009a),"freearc_packed7",sxan_freearc_packed7_fields,SX_COUNT(sxan_freearc_packed7_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index7_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,7,SX_NONE),
};
const sx_layout sxan_freearc_index7 = {UINT32_C(0x6077009b),"freearc_index7",sxan_freearc_index7_fields,SX_COUNT(sxan_freearc_index7_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type8_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,8,SX_NONE),
};
const sx_layout sxan_freearc_type8 = {UINT32_C(0x6077009c),"freearc_type8",sxan_freearc_type8_fields,SX_COUNT(sxan_freearc_type8_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count8_fields[] = {
 SX_FIELD("count","freearc_uint",0,8,SX_COUNT_PROP),
};
const sx_layout sxan_freearc_count8 = {UINT32_C(0x6077009d),"freearc_count8",sxan_freearc_count8_fields,SX_COUNT(sxan_freearc_count8_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset8_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,8,SX_OFFSET),
};
const sx_layout sxan_freearc_offset8 = {UINT32_C(0x6077009e),"freearc_offset8",sxan_freearc_offset8_fields,SX_COUNT(sxan_freearc_offset8_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size8_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,8,SX_SIZE),
};
const sx_layout sxan_freearc_size8 = {UINT32_C(0x6077009f),"freearc_size8",sxan_freearc_size8_fields,SX_COUNT(sxan_freearc_size8_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed8_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,8,SX_SIZE),
};
const sx_layout sxan_freearc_packed8 = {UINT32_C(0x607700a0),"freearc_packed8",sxan_freearc_packed8_fields,SX_COUNT(sxan_freearc_packed8_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index8_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,8,SX_NONE),
};
const sx_layout sxan_freearc_index8 = {UINT32_C(0x607700a1),"freearc_index8",sxan_freearc_index8_fields,SX_COUNT(sxan_freearc_index8_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_type9_fields[] = {
 SX_FIELD("block_type","freearc_uint",0,9,SX_NONE),
};
const sx_layout sxan_freearc_type9 = {UINT32_C(0x607700a2),"freearc_type9",sxan_freearc_type9_fields,SX_COUNT(sxan_freearc_type9_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_count9_fields[] = {
 SX_FIELD("count","freearc_uint",0,9,SX_COUNT_PROP),
};
const sx_layout sxan_freearc_count9 = {UINT32_C(0x607700a3),"freearc_count9",sxan_freearc_count9_fields,SX_COUNT(sxan_freearc_count9_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_offset9_fields[] = {
 SX_FIELD("relative_offset","freearc_uint",0,9,SX_OFFSET),
};
const sx_layout sxan_freearc_offset9 = {UINT32_C(0x607700a4),"freearc_offset9",sxan_freearc_offset9_fields,SX_COUNT(sxan_freearc_offset9_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_size9_fields[] = {
 SX_FIELD("uncompressed_size","freearc_uint",0,9,SX_SIZE),
};
const sx_layout sxan_freearc_size9 = {UINT32_C(0x607700a5),"freearc_size9",sxan_freearc_size9_fields,SX_COUNT(sxan_freearc_size9_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_packed9_fields[] = {
 SX_FIELD("compressed_size","freearc_uint",0,9,SX_SIZE),
};
const sx_layout sxan_freearc_packed9 = {UINT32_C(0x607700a6),"freearc_packed9",sxan_freearc_packed9_fields,SX_COUNT(sxan_freearc_packed9_fields),SX_LE};
static const xx_data_struct_field_desc sxan_freearc_index9_fields[] = {
 SX_FIELD("directory_index","freearc_uint",0,9,SX_NONE),
};
const sx_layout sxan_freearc_index9 = {UINT32_C(0x607700a7),"freearc_index9",sxan_freearc_index9_fields,SX_COUNT(sxan_freearc_index9_fields),SX_LE};
#define SXAN_LIMIT 20000U
static const sx_layout*const sxan_fa_type[9]={&sxan_freearc_type1,&sxan_freearc_type2,&sxan_freearc_type3,&sxan_freearc_type4,&sxan_freearc_type5,&sxan_freearc_type6,&sxan_freearc_type7,&sxan_freearc_type8,&sxan_freearc_type9};
static const sx_layout*const sxan_fa_count[9]={&sxan_freearc_count1,&sxan_freearc_count2,&sxan_freearc_count3,&sxan_freearc_count4,&sxan_freearc_count5,&sxan_freearc_count6,&sxan_freearc_count7,&sxan_freearc_count8,&sxan_freearc_count9};
static const sx_layout*const sxan_fa_offset[9]={&sxan_freearc_offset1,&sxan_freearc_offset2,&sxan_freearc_offset3,&sxan_freearc_offset4,&sxan_freearc_offset5,&sxan_freearc_offset6,&sxan_freearc_offset7,&sxan_freearc_offset8,&sxan_freearc_offset9};
static const sx_layout*const sxan_fa_size[9]={&sxan_freearc_size1,&sxan_freearc_size2,&sxan_freearc_size3,&sxan_freearc_size4,&sxan_freearc_size5,&sxan_freearc_size6,&sxan_freearc_size7,&sxan_freearc_size8,&sxan_freearc_size9};
static const sx_layout*const sxan_fa_packed[9]={&sxan_freearc_packed1,&sxan_freearc_packed2,&sxan_freearc_packed3,&sxan_freearc_packed4,&sxan_freearc_packed5,&sxan_freearc_packed6,&sxan_freearc_packed7,&sxan_freearc_packed8,&sxan_freearc_packed9};
static const sx_layout*const sxan_fa_index[9]={&sxan_freearc_index1,&sxan_freearc_index2,&sxan_freearc_index3,&sxan_freearc_index4,&sxan_freearc_index5,&sxan_freearc_index6,&sxan_freearc_index7,&sxan_freearc_index8,&sxan_freearc_index9};
static bool sxan_fa_num(sx_context*c,uint64_t*p,uint64_t end,uint64_t*v,const sx_layout*const*layouts,bool emit){uint8_t b[9];if(*p>=end||!sxan_read(c,*p,b,1))return false;unsigned extra=0;while(extra<8&&(b[0]&(1U<<extra)))extra++;unsigned width=extra+1;if(width>end-*p||!sxan_read(c,*p,b,width))return false;*v=0;if(extra==8){for(unsigned i=0;i<8;i++)*v|=(uint64_t)b[i+1]<<(8*i);}else{for(unsigned i=0;i<width;i++)*v|=(uint64_t)b[i]<<(8*i);*v>>=width;}if(*v>INT64_MAX|| (emit&&!sxan_add(c,layouts[width-1],*p)))return false;*p+=width;return true;}
static bool sxan_crc32(sx_context*c,uint64_t p,uint64_t n,uint64_t*out){uint8_t b[1024];uint32_t v=UINT32_MAX;if(!sxan_span(c,p,n))return false;while(n){size_t take=n<sizeof(b)?(size_t)n:sizeof(b);if(xx_pd_is_stopped(c->pd)||!sxan_read(c,p,b,take))return false;for(size_t i=0;i<take;i++){v^=b[i];for(unsigned k=0;k<8;k++)v=(v>>1)^(0xedb88320U&(0U-(v&1)));}p+=take;n-=take;}*out=~v;return true;}
typedef struct sxan_fa_desc{uint64_t type,packed,plain,start,end,crc;bool stored;}sxan_fa_desc;
static bool sxan_fa_string(sx_context*c,uint64_t*p,uint64_t end,const sx_layout*l,bool emit,bool*stored){uint64_t n;uint8_t b[8];if(!sxan_zlen(c,*p,end,&n))return false;if(stored)*stored=n==8&&sxan_read(c,*p,b,8)&&!xx_rt_memcmp(b,"storing\0",8);if(emit&&!sxan_text(c,l,*p,n,false))return false;*p+=n;return true;}
static bool sxan_fa_descriptor(sx_context*c,uint64_t at,sxan_fa_desc*d,bool emit){uint8_t b[4];uint64_t p=at+4,own,actual;if(!sxan_read(c,at,b,4)||xx_rt_memcmp(b,"ArC\1",4)||!sxan_fa_num(c,&p,(uint64_t)c->size,&d->type,sxan_fa_type,false)||!sxan_fa_string(c,&p,(uint64_t)c->size,&sxan_freearc_method,false,&d->stored)||p-at>1040||!sxan_fa_num(c,&p,(uint64_t)c->size,&d->plain,sxan_fa_size,false)||!sxan_fa_num(c,&p,(uint64_t)c->size,&d->packed,sxan_fa_packed,false)||!sxan_word(c,p,4,false,&d->crc)||!sxan_word(c,p+4,4,false,&own)||d->packed>at||!sxan_crc32(c,at,p+4-at,&actual)||own!=actual)return false;d->start=at-d->packed;d->end=p+8;if(emit){uint64_t v;p=at+4;if(!sxan_add(c,&sxan_freearc_magic,at)||!sxan_fa_num(c,&p,d->end,&v,sxan_fa_type,true)||!sxan_fa_string(c,&p,d->end,&sxan_freearc_method,true,NULL)||!sxan_fa_num(c,&p,d->end,&v,sxan_fa_size,true)||!sxan_fa_num(c,&p,d->end,&v,sxan_fa_packed,true)||!sxan_add(c,&sxan_freearc_crc,p)||!sxan_add(c,&sxan_freearc_crc,p+4))return false;}return true;}
static bool sxan_fa_directory(sx_context*c,uint64_t p,uint64_t z){uint64_t end=p+z,blocks,files=0,dirs,v;if(!sxan_span(c,p,z)||!sxan_fa_num(c,&p,end,&blocks,sxan_fa_count,true)||blocks>SXAN_LIMIT)return false;for(uint64_t i=0;i<blocks;i++){if(!sxan_fa_num(c,&p,end,&v,sxan_fa_count,true)||v>SXAN_LIMIT-files)return false;files+=v;}for(uint64_t i=0;i<blocks;i++)if(!sxan_fa_string(c,&p,end,&sxan_freearc_method,true,NULL))return false;for(uint64_t i=0;i<blocks;i++)if(!sxan_fa_num(c,&p,end,&v,sxan_fa_offset,true))return false;for(uint64_t i=0;i<blocks;i++)if(!sxan_fa_num(c,&p,end,&v,sxan_fa_packed,true))return false;if(!sxan_fa_num(c,&p,end,&dirs,sxan_fa_count,true)||dirs>SXAN_LIMIT)return false;for(uint64_t i=0;i<dirs+files;i++)if(!sxan_fa_string(c,&p,end,&sxan_archivenext_name,true,NULL))return false;for(uint64_t i=0;i<files;i++)if(!sxan_fa_num(c,&p,end,&v,sxan_fa_index,true))return false;for(uint64_t i=0;i<files;i++)if(!sxan_fa_num(c,&p,end,&v,sxan_fa_size,true))return false;if(files>(end-p)/4||!sxan_table(c,&sxan_freearc_time,p,4,files))return false;p+=4*files;if(files>end-p||!sxan_table(c,&sxan_freearc_folder,p,1,files))return false;p+=files;if(files>(end-p)/4||!sxan_table(c,&sxan_freearc_crc,p,4,files))return false;return true;}
static bool sxan_freearc(sx_context*c){sxan_fa_desc header,footer;if(!sxan_add(c,&sxan_freearc_header,0))return false;if(sxan_fa_descriptor(c,8,&header,false)&&header.type==1&&!sxan_fa_descriptor(c,8,&header,true))return false;uint64_t size=(uint64_t)c->size,low=size>4096?size-4096:0,at=size>=4?size-4:0;bool found=false;if(size<4)return true;for(;;){if(sxan_fa_descriptor(c,at,&footer,false)&&footer.type==4){found=true;break;}if(at==low)break;at--;}if(!found)return true;if(!sxan_fa_descriptor(c,at,&footer,true))return false;uint64_t actual;if(!footer.stored||footer.packed!=footer.plain||!sxan_crc32(c,footer.start,footer.packed,&actual)||actual!=footer.crc)return true;uint64_t p=footer.start,end=footer.start+footer.packed,n;if(!sxan_fa_num(c,&p,end,&n,sxan_fa_count,true)||n>SXAN_LIMIT)return false;for(uint64_t i=0;i<n;i++){uint64_t type,dist,plain,packed,crc;bool stored;if(!sxan_fa_num(c,&p,end,&type,sxan_fa_type,true)||!sxan_fa_string(c,&p,end,&sxan_freearc_method,true,&stored)||!sxan_fa_num(c,&p,end,&dist,sxan_fa_offset,true)||!sxan_fa_num(c,&p,end,&plain,sxan_fa_size,true)||!sxan_fa_num(c,&p,end,&packed,sxan_fa_packed,true)||!sxan_word(c,p,4,false,&crc)||!sxan_add(c,&sxan_freearc_crc,p))return false;p+=4;if(dist>footer.start||packed>dist)continue;uint64_t start=footer.start-dist; sxan_fa_desc d;if(sxan_fa_descriptor(c,start+packed,&d,false)&&d.type==type&&d.start==start&&d.packed==packed&&d.plain==plain&&d.crc==crc&&!sxan_fa_descriptor(c,start+packed,&d,true))return false;if(type==3&&stored&&packed==plain&&sxan_crc32(c,start,packed,&actual)&&actual==crc&&!sxan_fa_directory(c,start,packed))return false;}return true;}
bool sx_freearc_build(sx_context*c)
{
bool ok=false;
ok=sxan_freearc(c);
(void)ok;return c->count&&sxan_finish(c);
}
