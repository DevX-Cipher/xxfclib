/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Starkit data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_starkit_header_fields[] = {
 SX_FIELD("magic","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("file_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxbx_starkit_header = {UINT32_C(0x603000b6),"starkit_header",sxbx_starkit_header_fields,SX_COUNT(sxbx_starkit_header_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_starkit_commit_fields[] = {
 SX_FIELD("commit_tag","uint32",0,4,SX_FLAGS),
 SX_FIELD("footer_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("root_size_and_tag","uint32",8,4,SX_FLAGS),
 SX_FIELD("root_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sxbx_starkit_commit = {UINT32_C(0x603000b7),"starkit_commit",sxbx_starkit_commit_fields,SX_COUNT(sxbx_starkit_commit_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_starkit_root_prefix_fields[] = {
 SX_FIELD("root_tag","uint8",0,1,SX_FLAGS),
 SX_FIELD("schema_size_and_tag","uint8",1,1,SX_FLAGS),
};
const sx_layout sxbx_starkit_root_prefix = {UINT32_C(0x603000b8),"starkit_root_prefix",sxbx_starkit_root_prefix_fields,SX_COUNT(sxbx_starkit_root_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count1_fields[] = {
 SX_FIELD("row_count","metakit_msb128[1]",0,1,SX_COUNT_PROP),
};
const sx_layout sxbx_starkit_row_count1 = {UINT32_C(0x603000b9),"starkit_row_count1",sxbx_starkit_row_count1_fields,SX_COUNT(sxbx_starkit_row_count1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count2_fields[] = {
 SX_FIELD("row_count","metakit_msb128[2]",0,2,SX_COUNT_PROP),
};
const sx_layout sxbx_starkit_row_count2 = {UINT32_C(0x603000ba),"starkit_row_count2",sxbx_starkit_row_count2_fields,SX_COUNT(sxbx_starkit_row_count2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count3_fields[] = {
 SX_FIELD("row_count","metakit_msb128[3]",0,3,SX_COUNT_PROP),
};
const sx_layout sxbx_starkit_row_count3 = {UINT32_C(0x603000bb),"starkit_row_count3",sxbx_starkit_row_count3_fields,SX_COUNT(sxbx_starkit_row_count3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count4_fields[] = {
 SX_FIELD("row_count","metakit_msb128[4]",0,4,SX_COUNT_PROP),
};
const sx_layout sxbx_starkit_row_count4 = {UINT32_C(0x603000bc),"starkit_row_count4",sxbx_starkit_row_count4_fields,SX_COUNT(sxbx_starkit_row_count4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count5_fields[] = {
 SX_FIELD("row_count","metakit_msb128[5]",0,5,SX_COUNT_PROP),
};
const sx_layout sxbx_starkit_row_count5 = {UINT32_C(0x603000bd),"starkit_row_count5",sxbx_starkit_row_count5_fields,SX_COUNT(sxbx_starkit_row_count5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count6_fields[] = {
 SX_FIELD("row_count","metakit_msb128[6]",0,6,SX_COUNT_PROP),
};
const sx_layout sxbx_starkit_row_count6 = {UINT32_C(0x603000be),"starkit_row_count6",sxbx_starkit_row_count6_fields,SX_COUNT(sxbx_starkit_row_count6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count7_fields[] = {
 SX_FIELD("row_count","metakit_msb128[7]",0,7,SX_COUNT_PROP),
};
const sx_layout sxbx_starkit_row_count7 = {UINT32_C(0x603000bf),"starkit_row_count7",sxbx_starkit_row_count7_fields,SX_COUNT(sxbx_starkit_row_count7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count8_fields[] = {
 SX_FIELD("row_count","metakit_msb128[8]",0,8,SX_COUNT_PROP),
};
const sx_layout sxbx_starkit_row_count8 = {UINT32_C(0x603000c0),"starkit_row_count8",sxbx_starkit_row_count8_fields,SX_COUNT(sxbx_starkit_row_count8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_row_count9_fields[] = {
 SX_FIELD("row_count","metakit_msb128[9]",0,9,SX_COUNT_PROP),
};
const sx_layout sxbx_starkit_row_count9 = {UINT32_C(0x603000c1),"starkit_row_count9",sxbx_starkit_row_count9_fields,SX_COUNT(sxbx_starkit_row_count9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size1_fields[] = {
 SX_FIELD("column_size","metakit_msb128[1]",0,1,SX_SIZE),
};
const sx_layout sxbx_starkit_column_size1 = {UINT32_C(0x603000c2),"starkit_column_size1",sxbx_starkit_column_size1_fields,SX_COUNT(sxbx_starkit_column_size1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size2_fields[] = {
 SX_FIELD("column_size","metakit_msb128[2]",0,2,SX_SIZE),
};
const sx_layout sxbx_starkit_column_size2 = {UINT32_C(0x603000c3),"starkit_column_size2",sxbx_starkit_column_size2_fields,SX_COUNT(sxbx_starkit_column_size2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size3_fields[] = {
 SX_FIELD("column_size","metakit_msb128[3]",0,3,SX_SIZE),
};
const sx_layout sxbx_starkit_column_size3 = {UINT32_C(0x603000c4),"starkit_column_size3",sxbx_starkit_column_size3_fields,SX_COUNT(sxbx_starkit_column_size3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size4_fields[] = {
 SX_FIELD("column_size","metakit_msb128[4]",0,4,SX_SIZE),
};
const sx_layout sxbx_starkit_column_size4 = {UINT32_C(0x603000c5),"starkit_column_size4",sxbx_starkit_column_size4_fields,SX_COUNT(sxbx_starkit_column_size4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size5_fields[] = {
 SX_FIELD("column_size","metakit_msb128[5]",0,5,SX_SIZE),
};
const sx_layout sxbx_starkit_column_size5 = {UINT32_C(0x603000c6),"starkit_column_size5",sxbx_starkit_column_size5_fields,SX_COUNT(sxbx_starkit_column_size5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size6_fields[] = {
 SX_FIELD("column_size","metakit_msb128[6]",0,6,SX_SIZE),
};
const sx_layout sxbx_starkit_column_size6 = {UINT32_C(0x603000c7),"starkit_column_size6",sxbx_starkit_column_size6_fields,SX_COUNT(sxbx_starkit_column_size6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size7_fields[] = {
 SX_FIELD("column_size","metakit_msb128[7]",0,7,SX_SIZE),
};
const sx_layout sxbx_starkit_column_size7 = {UINT32_C(0x603000c8),"starkit_column_size7",sxbx_starkit_column_size7_fields,SX_COUNT(sxbx_starkit_column_size7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size8_fields[] = {
 SX_FIELD("column_size","metakit_msb128[8]",0,8,SX_SIZE),
};
const sx_layout sxbx_starkit_column_size8 = {UINT32_C(0x603000c9),"starkit_column_size8",sxbx_starkit_column_size8_fields,SX_COUNT(sxbx_starkit_column_size8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_size9_fields[] = {
 SX_FIELD("column_size","metakit_msb128[9]",0,9,SX_SIZE),
};
const sx_layout sxbx_starkit_column_size9 = {UINT32_C(0x603000ca),"starkit_column_size9",sxbx_starkit_column_size9_fields,SX_COUNT(sxbx_starkit_column_size9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset1_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[1]",0,1,SX_OFFSET),
};
const sx_layout sxbx_starkit_column_offset1 = {UINT32_C(0x603000cb),"starkit_column_offset1",sxbx_starkit_column_offset1_fields,SX_COUNT(sxbx_starkit_column_offset1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset2_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[2]",0,2,SX_OFFSET),
};
const sx_layout sxbx_starkit_column_offset2 = {UINT32_C(0x603000cc),"starkit_column_offset2",sxbx_starkit_column_offset2_fields,SX_COUNT(sxbx_starkit_column_offset2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset3_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[3]",0,3,SX_OFFSET),
};
const sx_layout sxbx_starkit_column_offset3 = {UINT32_C(0x603000cd),"starkit_column_offset3",sxbx_starkit_column_offset3_fields,SX_COUNT(sxbx_starkit_column_offset3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset4_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[4]",0,4,SX_OFFSET),
};
const sx_layout sxbx_starkit_column_offset4 = {UINT32_C(0x603000ce),"starkit_column_offset4",sxbx_starkit_column_offset4_fields,SX_COUNT(sxbx_starkit_column_offset4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset5_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[5]",0,5,SX_OFFSET),
};
const sx_layout sxbx_starkit_column_offset5 = {UINT32_C(0x603000cf),"starkit_column_offset5",sxbx_starkit_column_offset5_fields,SX_COUNT(sxbx_starkit_column_offset5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset6_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[6]",0,6,SX_OFFSET),
};
const sx_layout sxbx_starkit_column_offset6 = {UINT32_C(0x603000d0),"starkit_column_offset6",sxbx_starkit_column_offset6_fields,SX_COUNT(sxbx_starkit_column_offset6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset7_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[7]",0,7,SX_OFFSET),
};
const sx_layout sxbx_starkit_column_offset7 = {UINT32_C(0x603000d1),"starkit_column_offset7",sxbx_starkit_column_offset7_fields,SX_COUNT(sxbx_starkit_column_offset7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset8_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[8]",0,8,SX_OFFSET),
};
const sx_layout sxbx_starkit_column_offset8 = {UINT32_C(0x603000d2),"starkit_column_offset8",sxbx_starkit_column_offset8_fields,SX_COUNT(sxbx_starkit_column_offset8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_column_offset9_fields[] = {
 SX_FIELD("column_offset","metakit_msb128[9]",0,9,SX_OFFSET),
};
const sx_layout sxbx_starkit_column_offset9 = {UINT32_C(0x603000d3),"starkit_column_offset9",sxbx_starkit_column_offset9_fields,SX_COUNT(sxbx_starkit_column_offset9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta1_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[1]",0,1,SX_NONE),
};
const sx_layout sxbx_starkit_memo_row_delta1 = {UINT32_C(0x603000d4),"starkit_memo_row_delta1",sxbx_starkit_memo_row_delta1_fields,SX_COUNT(sxbx_starkit_memo_row_delta1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta2_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[2]",0,2,SX_NONE),
};
const sx_layout sxbx_starkit_memo_row_delta2 = {UINT32_C(0x603000d5),"starkit_memo_row_delta2",sxbx_starkit_memo_row_delta2_fields,SX_COUNT(sxbx_starkit_memo_row_delta2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta3_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[3]",0,3,SX_NONE),
};
const sx_layout sxbx_starkit_memo_row_delta3 = {UINT32_C(0x603000d6),"starkit_memo_row_delta3",sxbx_starkit_memo_row_delta3_fields,SX_COUNT(sxbx_starkit_memo_row_delta3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta4_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[4]",0,4,SX_NONE),
};
const sx_layout sxbx_starkit_memo_row_delta4 = {UINT32_C(0x603000d7),"starkit_memo_row_delta4",sxbx_starkit_memo_row_delta4_fields,SX_COUNT(sxbx_starkit_memo_row_delta4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta5_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[5]",0,5,SX_NONE),
};
const sx_layout sxbx_starkit_memo_row_delta5 = {UINT32_C(0x603000d8),"starkit_memo_row_delta5",sxbx_starkit_memo_row_delta5_fields,SX_COUNT(sxbx_starkit_memo_row_delta5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta6_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[6]",0,6,SX_NONE),
};
const sx_layout sxbx_starkit_memo_row_delta6 = {UINT32_C(0x603000d9),"starkit_memo_row_delta6",sxbx_starkit_memo_row_delta6_fields,SX_COUNT(sxbx_starkit_memo_row_delta6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta7_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[7]",0,7,SX_NONE),
};
const sx_layout sxbx_starkit_memo_row_delta7 = {UINT32_C(0x603000da),"starkit_memo_row_delta7",sxbx_starkit_memo_row_delta7_fields,SX_COUNT(sxbx_starkit_memo_row_delta7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta8_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[8]",0,8,SX_NONE),
};
const sx_layout sxbx_starkit_memo_row_delta8 = {UINT32_C(0x603000db),"starkit_memo_row_delta8",sxbx_starkit_memo_row_delta8_fields,SX_COUNT(sxbx_starkit_memo_row_delta8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_memo_row_delta9_fields[] = {
 SX_FIELD("memo_row_delta","metakit_msb128[9]",0,9,SX_NONE),
};
const sx_layout sxbx_starkit_memo_row_delta9 = {UINT32_C(0x603000dc),"starkit_memo_row_delta9",sxbx_starkit_memo_row_delta9_fields,SX_COUNT(sxbx_starkit_memo_row_delta9_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag1_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[1]",0,1,SX_NONE),
};
const sx_layout sxbx_starkit_view_tag1 = {UINT32_C(0x603000dd),"starkit_view_tag1",sxbx_starkit_view_tag1_fields,SX_COUNT(sxbx_starkit_view_tag1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag2_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[2]",0,2,SX_NONE),
};
const sx_layout sxbx_starkit_view_tag2 = {UINT32_C(0x603000de),"starkit_view_tag2",sxbx_starkit_view_tag2_fields,SX_COUNT(sxbx_starkit_view_tag2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag3_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[3]",0,3,SX_NONE),
};
const sx_layout sxbx_starkit_view_tag3 = {UINT32_C(0x603000df),"starkit_view_tag3",sxbx_starkit_view_tag3_fields,SX_COUNT(sxbx_starkit_view_tag3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag4_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[4]",0,4,SX_NONE),
};
const sx_layout sxbx_starkit_view_tag4 = {UINT32_C(0x603000e0),"starkit_view_tag4",sxbx_starkit_view_tag4_fields,SX_COUNT(sxbx_starkit_view_tag4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag5_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[5]",0,5,SX_NONE),
};
const sx_layout sxbx_starkit_view_tag5 = {UINT32_C(0x603000e1),"starkit_view_tag5",sxbx_starkit_view_tag5_fields,SX_COUNT(sxbx_starkit_view_tag5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag6_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[6]",0,6,SX_NONE),
};
const sx_layout sxbx_starkit_view_tag6 = {UINT32_C(0x603000e2),"starkit_view_tag6",sxbx_starkit_view_tag6_fields,SX_COUNT(sxbx_starkit_view_tag6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag7_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[7]",0,7,SX_NONE),
};
const sx_layout sxbx_starkit_view_tag7 = {UINT32_C(0x603000e3),"starkit_view_tag7",sxbx_starkit_view_tag7_fields,SX_COUNT(sxbx_starkit_view_tag7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag8_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[8]",0,8,SX_NONE),
};
const sx_layout sxbx_starkit_view_tag8 = {UINT32_C(0x603000e4),"starkit_view_tag8",sxbx_starkit_view_tag8_fields,SX_COUNT(sxbx_starkit_view_tag8_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_starkit_view_tag9_fields[] = {
 SX_FIELD("view_tag","metakit_msb128[9]",0,9,SX_NONE),
};
const sx_layout sxbx_starkit_view_tag9 = {UINT32_C(0x603000e5),"starkit_view_tag9",sxbx_starkit_view_tag9_fields,SX_COUNT(sxbx_starkit_view_tag9_fields),SX_LE};
#define SXBX_LIMIT 20000U
static const sx_layout *const sxbx_starkit_row_count[] = {&sxbx_starkit_row_count1,&sxbx_starkit_row_count2,&sxbx_starkit_row_count3,&sxbx_starkit_row_count4,&sxbx_starkit_row_count5,&sxbx_starkit_row_count6,&sxbx_starkit_row_count7,&sxbx_starkit_row_count8,&sxbx_starkit_row_count9};
static const sx_layout *const sxbx_starkit_column_size[] = {&sxbx_starkit_column_size1,&sxbx_starkit_column_size2,&sxbx_starkit_column_size3,&sxbx_starkit_column_size4,&sxbx_starkit_column_size5,&sxbx_starkit_column_size6,&sxbx_starkit_column_size7,&sxbx_starkit_column_size8,&sxbx_starkit_column_size9};
static const sx_layout *const sxbx_starkit_column_offset[] = {&sxbx_starkit_column_offset1,&sxbx_starkit_column_offset2,&sxbx_starkit_column_offset3,&sxbx_starkit_column_offset4,&sxbx_starkit_column_offset5,&sxbx_starkit_column_offset6,&sxbx_starkit_column_offset7,&sxbx_starkit_column_offset8,&sxbx_starkit_column_offset9};
static const sx_layout *const sxbx_starkit_memo_row_delta[] = {&sxbx_starkit_memo_row_delta1,&sxbx_starkit_memo_row_delta2,&sxbx_starkit_memo_row_delta3,&sxbx_starkit_memo_row_delta4,&sxbx_starkit_memo_row_delta5,&sxbx_starkit_memo_row_delta6,&sxbx_starkit_memo_row_delta7,&sxbx_starkit_memo_row_delta8,&sxbx_starkit_memo_row_delta9};
static const sx_layout *const sxbx_starkit_view_tag[] = {&sxbx_starkit_view_tag1,&sxbx_starkit_view_tag2,&sxbx_starkit_view_tag3,&sxbx_starkit_view_tag4,&sxbx_starkit_view_tag5,&sxbx_starkit_view_tag6,&sxbx_starkit_view_tag7,&sxbx_starkit_view_tag8,&sxbx_starkit_view_tag9};
static bool sxbx_mkvar(sx_context*c,uint64_t*p,uint64_t end,const sx_layout*const*ls,uint64_t*v){uint64_t start=*p;*v=0;for(unsigned i=0;i<9;i++){uint64_t b;if(*p>=end||!sxbx_word(c,(*p)++,1,false,&b))return false;*v=(*v<<7)|(b&127);if(b&128)return sxbx_add(c,ls[i],start);}return false;}
typedef struct sxbx_col {uint64_t size,offset;}sxbx_col;
static bool sxbx_mkcol(sx_context*c,uint64_t base,uint64_t*p,uint64_t end,sxbx_col*out){out->offset=0;if(!sxbx_mkvar(c,p,end,sxbx_starkit_column_size,&out->size))return false;if(out->size&&(!sxbx_mkvar(c,p,end,sxbx_starkit_column_offset,&out->offset)||out->offset>UINT64_MAX-base||!sxbx_span(c,base+out->offset,out->size)))return false;out->offset+=base;return true;}
static bool sxbx_mkprop(sx_context*c,uint64_t base,uint64_t*p,uint64_t end,sxbx_col out[3]){xx_mem_zero(out,3*sizeof(*out));return sxbx_mkcol(c,base,p,end,out)&&(!out[0].size||sxbx_mkcol(c,base,p,end,out+1))&&sxbx_mkcol(c,base,p,end,out+2);}
bool sxbx_starkit(sx_context*c){uint64_t base=0,end=(uint64_t)c->size,size,root,footer;uint8_t b[8];if(end<24||!sxbx_read(c,0,b,8))return false;if(xx_rt_memcmp(b,"JL\x1a\0",4)){if(b[0]!='M'||b[1]!='Z'||!sxbx_word(c,end-12,4,true,&footer)||footer+16>end)return false;base=end-footer-16;if(!sxbx_read(c,base,b,8)||xx_rt_memcmp(b,"JL\x1a\0",4))return false;}if(!sxbx_add(c,&sxbx_starkit_header,base)||!sxbx_add(c,&sxbx_starkit_commit,end-16)||!sxbx_word(c,end-8,4,true,&size)||!sxbx_word(c,end-4,4,true,&root))return false;size&=0x7fffffff;root+=base;if(size<3||size>4096||!sxbx_span(c,root,size)||!sxbx_read(c,root,b,2)||b[0]!=128||!(b[1]&128)||!sxbx_add(c,&sxbx_starkit_root_prefix,root))return true;uint64_t p=root+2+(b[1]&127),stop=root+size,rows;sxbx_col dirs;if(!sxbx_mkvar(c,&p,stop,sxbx_starkit_row_count,&rows)||!sxbx_mkcol(c,base,&p,stop,&dirs)||!dirs.size)return true;p=dirs.offset;stop=p+dirs.size;sxbx_col name[3],parents,views;if(!sxbx_mkvar(c,&p,stop,sxbx_starkit_view_tag,&rows)||!sxbx_mkvar(c,&p,stop,sxbx_starkit_row_count,&rows)||!rows||rows>SXBX_LIMIT||!sxbx_mkprop(c,base,&p,stop,name)||!sxbx_mkcol(c,base,&p,stop,&parents)||!sxbx_mkcol(c,base,&p,stop,&views))return true;p=views.offset;stop=p+views.size;for(uint64_t i=0;i<rows&&c->count<SXBX_LIMIT;i++){uint64_t n;size_t keep=c->count;sxbx_col filename[3],bytes,date,contents[3];if(!sxbx_mkvar(c,&p,stop,sxbx_starkit_view_tag,&n)||!sxbx_mkvar(c,&p,stop,sxbx_starkit_row_count,&n)){c->count=keep;break;}if(!n)continue;if(n>SXBX_LIMIT||!sxbx_mkprop(c,base,&p,stop,filename)||!sxbx_mkcol(c,base,&p,stop,&bytes)||!sxbx_mkcol(c,base,&p,stop,&date)||!sxbx_mkprop(c,base,&p,stop,contents)){c->count=keep;break;}uint64_t q=contents[2].offset,mend=q+contents[2].size;for(unsigned memo=0;q<mend&&memo<SXBX_LIMIT&&c->count<SXBX_LIMIT;memo++){uint64_t v;if(!sxbx_mkvar(c,&q,mend,sxbx_starkit_memo_row_delta,&v)||!sxbx_mkvar(c,&q,mend,sxbx_starkit_column_size,&v)||!sxbx_mkvar(c,&q,mend,sxbx_starkit_column_offset,&v))break;}}return true;}
bool sx_starkit_build(sx_context*c)
{
 return sxbx_starkit(c);
}
