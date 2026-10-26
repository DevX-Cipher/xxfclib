/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IBM install-diskette packed files data structures, moved out of the archivewire schema family. */
#include "../../xx_format_schema_archivewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarwire_ibmspack_tag_fields[]={
 SX_FIELD("stream_tag","uint8",0,1,SX_ID),
};
const sx_layout sxarwire_ibmspack_tag={UINT32_C(0x608d0003),"ibmspack_tag",sxarwire_ibmspack_tag_fields,SX_COUNT(sxarwire_ibmspack_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_first_class_bit0_fields[]={
 SX_FIELD("first_class","msb_bits[0,3]",0,1,SX_ID),
};
const sx_layout sxarwire_fls_first_class_bit0={UINT32_C(0x608d0080),"fls_first_class_bit0",sxarwire_fls_first_class_bit0_fields,SX_COUNT(sxarwire_fls_first_class_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_first_class_bit1_fields[]={
 SX_FIELD("first_class","msb_bits[1,3]",0,1,SX_ID),
};
const sx_layout sxarwire_fls_first_class_bit1={UINT32_C(0x608d0081),"fls_first_class_bit1",sxarwire_fls_first_class_bit1_fields,SX_COUNT(sxarwire_fls_first_class_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_first_class_bit2_fields[]={
 SX_FIELD("first_class","msb_bits[2,3]",0,1,SX_ID),
};
const sx_layout sxarwire_fls_first_class_bit2={UINT32_C(0x608d0082),"fls_first_class_bit2",sxarwire_fls_first_class_bit2_fields,SX_COUNT(sxarwire_fls_first_class_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_first_class_bit3_fields[]={
 SX_FIELD("first_class","msb_bits[3,3]",0,1,SX_ID),
};
const sx_layout sxarwire_fls_first_class_bit3={UINT32_C(0x608d0083),"fls_first_class_bit3",sxarwire_fls_first_class_bit3_fields,SX_COUNT(sxarwire_fls_first_class_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_first_class_bit4_fields[]={
 SX_FIELD("first_class","msb_bits[4,3]",0,1,SX_ID),
};
const sx_layout sxarwire_fls_first_class_bit4={UINT32_C(0x608d0084),"fls_first_class_bit4",sxarwire_fls_first_class_bit4_fields,SX_COUNT(sxarwire_fls_first_class_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_first_class_bit5_fields[]={
 SX_FIELD("first_class","msb_bits[5,3]",0,1,SX_ID),
};
const sx_layout sxarwire_fls_first_class_bit5={UINT32_C(0x608d0085),"fls_first_class_bit5",sxarwire_fls_first_class_bit5_fields,SX_COUNT(sxarwire_fls_first_class_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_first_class_bit6_fields[]={
 SX_FIELD("first_class","msb_bits[6,3]",0,2,SX_ID),
};
const sx_layout sxarwire_fls_first_class_bit6={UINT32_C(0x608d0086),"fls_first_class_bit6",sxarwire_fls_first_class_bit6_fields,SX_COUNT(sxarwire_fls_first_class_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_first_class_bit7_fields[]={
 SX_FIELD("first_class","msb_bits[7,3]",0,2,SX_ID),
};
const sx_layout sxarwire_fls_first_class_bit7={UINT32_C(0x608d0087),"fls_first_class_bit7",sxarwire_fls_first_class_bit7_fields,SX_COUNT(sxarwire_fls_first_class_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_second_class_bit0_fields[]={
 SX_FIELD("second_class","msb_bits[0,3]",0,1,SX_ID),
};
const sx_layout sxarwire_fls_second_class_bit0={UINT32_C(0x608d0088),"fls_second_class_bit0",sxarwire_fls_second_class_bit0_fields,SX_COUNT(sxarwire_fls_second_class_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_second_class_bit1_fields[]={
 SX_FIELD("second_class","msb_bits[1,3]",0,1,SX_ID),
};
const sx_layout sxarwire_fls_second_class_bit1={UINT32_C(0x608d0089),"fls_second_class_bit1",sxarwire_fls_second_class_bit1_fields,SX_COUNT(sxarwire_fls_second_class_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_second_class_bit2_fields[]={
 SX_FIELD("second_class","msb_bits[2,3]",0,1,SX_ID),
};
const sx_layout sxarwire_fls_second_class_bit2={UINT32_C(0x608d008a),"fls_second_class_bit2",sxarwire_fls_second_class_bit2_fields,SX_COUNT(sxarwire_fls_second_class_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_second_class_bit3_fields[]={
 SX_FIELD("second_class","msb_bits[3,3]",0,1,SX_ID),
};
const sx_layout sxarwire_fls_second_class_bit3={UINT32_C(0x608d008b),"fls_second_class_bit3",sxarwire_fls_second_class_bit3_fields,SX_COUNT(sxarwire_fls_second_class_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_second_class_bit4_fields[]={
 SX_FIELD("second_class","msb_bits[4,3]",0,1,SX_ID),
};
const sx_layout sxarwire_fls_second_class_bit4={UINT32_C(0x608d008c),"fls_second_class_bit4",sxarwire_fls_second_class_bit4_fields,SX_COUNT(sxarwire_fls_second_class_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_second_class_bit5_fields[]={
 SX_FIELD("second_class","msb_bits[5,3]",0,1,SX_ID),
};
const sx_layout sxarwire_fls_second_class_bit5={UINT32_C(0x608d008d),"fls_second_class_bit5",sxarwire_fls_second_class_bit5_fields,SX_COUNT(sxarwire_fls_second_class_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_second_class_bit6_fields[]={
 SX_FIELD("second_class","msb_bits[6,3]",0,2,SX_ID),
};
const sx_layout sxarwire_fls_second_class_bit6={UINT32_C(0x608d008e),"fls_second_class_bit6",sxarwire_fls_second_class_bit6_fields,SX_COUNT(sxarwire_fls_second_class_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_second_class_bit7_fields[]={
 SX_FIELD("second_class","msb_bits[7,3]",0,2,SX_ID),
};
const sx_layout sxarwire_fls_second_class_bit7={UINT32_C(0x608d008f),"fls_second_class_bit7",sxarwire_fls_second_class_bit7_fields,SX_COUNT(sxarwire_fls_second_class_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_prefix_bit0_fields[]={
 SX_FIELD("selector_prefix","msb_bits[0,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_selector_prefix_bit0={UINT32_C(0x608d0090),"fls_selector_prefix_bit0",sxarwire_fls_selector_prefix_bit0_fields,SX_COUNT(sxarwire_fls_selector_prefix_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_prefix_bit1_fields[]={
 SX_FIELD("selector_prefix","msb_bits[1,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_selector_prefix_bit1={UINT32_C(0x608d0091),"fls_selector_prefix_bit1",sxarwire_fls_selector_prefix_bit1_fields,SX_COUNT(sxarwire_fls_selector_prefix_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_prefix_bit2_fields[]={
 SX_FIELD("selector_prefix","msb_bits[2,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_selector_prefix_bit2={UINT32_C(0x608d0092),"fls_selector_prefix_bit2",sxarwire_fls_selector_prefix_bit2_fields,SX_COUNT(sxarwire_fls_selector_prefix_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_prefix_bit3_fields[]={
 SX_FIELD("selector_prefix","msb_bits[3,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_selector_prefix_bit3={UINT32_C(0x608d0093),"fls_selector_prefix_bit3",sxarwire_fls_selector_prefix_bit3_fields,SX_COUNT(sxarwire_fls_selector_prefix_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_prefix_bit4_fields[]={
 SX_FIELD("selector_prefix","msb_bits[4,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_selector_prefix_bit4={UINT32_C(0x608d0094),"fls_selector_prefix_bit4",sxarwire_fls_selector_prefix_bit4_fields,SX_COUNT(sxarwire_fls_selector_prefix_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_prefix_bit5_fields[]={
 SX_FIELD("selector_prefix","msb_bits[5,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_selector_prefix_bit5={UINT32_C(0x608d0095),"fls_selector_prefix_bit5",sxarwire_fls_selector_prefix_bit5_fields,SX_COUNT(sxarwire_fls_selector_prefix_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_prefix_bit6_fields[]={
 SX_FIELD("selector_prefix","msb_bits[6,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_selector_prefix_bit6={UINT32_C(0x608d0096),"fls_selector_prefix_bit6",sxarwire_fls_selector_prefix_bit6_fields,SX_COUNT(sxarwire_fls_selector_prefix_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_prefix_bit7_fields[]={
 SX_FIELD("selector_prefix","msb_bits[7,2]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_selector_prefix_bit7={UINT32_C(0x608d0097),"fls_selector_prefix_bit7",sxarwire_fls_selector_prefix_bit7_fields,SX_COUNT(sxarwire_fls_selector_prefix_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_extension_bit0_fields[]={
 SX_FIELD("selector_extension","msb_bits[0,1]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_selector_extension_bit0={UINT32_C(0x608d0098),"fls_selector_extension_bit0",sxarwire_fls_selector_extension_bit0_fields,SX_COUNT(sxarwire_fls_selector_extension_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_extension_bit1_fields[]={
 SX_FIELD("selector_extension","msb_bits[1,1]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_selector_extension_bit1={UINT32_C(0x608d0099),"fls_selector_extension_bit1",sxarwire_fls_selector_extension_bit1_fields,SX_COUNT(sxarwire_fls_selector_extension_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_extension_bit2_fields[]={
 SX_FIELD("selector_extension","msb_bits[2,1]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_selector_extension_bit2={UINT32_C(0x608d009a),"fls_selector_extension_bit2",sxarwire_fls_selector_extension_bit2_fields,SX_COUNT(sxarwire_fls_selector_extension_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_extension_bit3_fields[]={
 SX_FIELD("selector_extension","msb_bits[3,1]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_selector_extension_bit3={UINT32_C(0x608d009b),"fls_selector_extension_bit3",sxarwire_fls_selector_extension_bit3_fields,SX_COUNT(sxarwire_fls_selector_extension_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_extension_bit4_fields[]={
 SX_FIELD("selector_extension","msb_bits[4,1]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_selector_extension_bit4={UINT32_C(0x608d009c),"fls_selector_extension_bit4",sxarwire_fls_selector_extension_bit4_fields,SX_COUNT(sxarwire_fls_selector_extension_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_extension_bit5_fields[]={
 SX_FIELD("selector_extension","msb_bits[5,1]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_selector_extension_bit5={UINT32_C(0x608d009d),"fls_selector_extension_bit5",sxarwire_fls_selector_extension_bit5_fields,SX_COUNT(sxarwire_fls_selector_extension_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_extension_bit6_fields[]={
 SX_FIELD("selector_extension","msb_bits[6,1]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_selector_extension_bit6={UINT32_C(0x608d009e),"fls_selector_extension_bit6",sxarwire_fls_selector_extension_bit6_fields,SX_COUNT(sxarwire_fls_selector_extension_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_selector_extension_bit7_fields[]={
 SX_FIELD("selector_extension","msb_bits[7,1]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_selector_extension_bit7={UINT32_C(0x608d009f),"fls_selector_extension_bit7",sxarwire_fls_selector_extension_bit7_fields,SX_COUNT(sxarwire_fls_selector_extension_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code6_bit0_fields[]={
 SX_FIELD("class_code","msb_bits[0,6]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_code6_bit0={UINT32_C(0x608d00a0),"fls_code6_bit0",sxarwire_fls_code6_bit0_fields,SX_COUNT(sxarwire_fls_code6_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code6_bit1_fields[]={
 SX_FIELD("class_code","msb_bits[1,6]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_code6_bit1={UINT32_C(0x608d00a1),"fls_code6_bit1",sxarwire_fls_code6_bit1_fields,SX_COUNT(sxarwire_fls_code6_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code6_bit2_fields[]={
 SX_FIELD("class_code","msb_bits[2,6]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_code6_bit2={UINT32_C(0x608d00a2),"fls_code6_bit2",sxarwire_fls_code6_bit2_fields,SX_COUNT(sxarwire_fls_code6_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code6_bit3_fields[]={
 SX_FIELD("class_code","msb_bits[3,6]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code6_bit3={UINT32_C(0x608d00a3),"fls_code6_bit3",sxarwire_fls_code6_bit3_fields,SX_COUNT(sxarwire_fls_code6_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code6_bit4_fields[]={
 SX_FIELD("class_code","msb_bits[4,6]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code6_bit4={UINT32_C(0x608d00a4),"fls_code6_bit4",sxarwire_fls_code6_bit4_fields,SX_COUNT(sxarwire_fls_code6_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code6_bit5_fields[]={
 SX_FIELD("class_code","msb_bits[5,6]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code6_bit5={UINT32_C(0x608d00a5),"fls_code6_bit5",sxarwire_fls_code6_bit5_fields,SX_COUNT(sxarwire_fls_code6_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code6_bit6_fields[]={
 SX_FIELD("class_code","msb_bits[6,6]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code6_bit6={UINT32_C(0x608d00a6),"fls_code6_bit6",sxarwire_fls_code6_bit6_fields,SX_COUNT(sxarwire_fls_code6_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code6_bit7_fields[]={
 SX_FIELD("class_code","msb_bits[7,6]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code6_bit7={UINT32_C(0x608d00a7),"fls_code6_bit7",sxarwire_fls_code6_bit7_fields,SX_COUNT(sxarwire_fls_code6_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code7_bit0_fields[]={
 SX_FIELD("class_code","msb_bits[0,7]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_code7_bit0={UINT32_C(0x608d00a8),"fls_code7_bit0",sxarwire_fls_code7_bit0_fields,SX_COUNT(sxarwire_fls_code7_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code7_bit1_fields[]={
 SX_FIELD("class_code","msb_bits[1,7]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_code7_bit1={UINT32_C(0x608d00a9),"fls_code7_bit1",sxarwire_fls_code7_bit1_fields,SX_COUNT(sxarwire_fls_code7_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code7_bit2_fields[]={
 SX_FIELD("class_code","msb_bits[2,7]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code7_bit2={UINT32_C(0x608d00aa),"fls_code7_bit2",sxarwire_fls_code7_bit2_fields,SX_COUNT(sxarwire_fls_code7_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code7_bit3_fields[]={
 SX_FIELD("class_code","msb_bits[3,7]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code7_bit3={UINT32_C(0x608d00ab),"fls_code7_bit3",sxarwire_fls_code7_bit3_fields,SX_COUNT(sxarwire_fls_code7_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code7_bit4_fields[]={
 SX_FIELD("class_code","msb_bits[4,7]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code7_bit4={UINT32_C(0x608d00ac),"fls_code7_bit4",sxarwire_fls_code7_bit4_fields,SX_COUNT(sxarwire_fls_code7_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code7_bit5_fields[]={
 SX_FIELD("class_code","msb_bits[5,7]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code7_bit5={UINT32_C(0x608d00ad),"fls_code7_bit5",sxarwire_fls_code7_bit5_fields,SX_COUNT(sxarwire_fls_code7_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code7_bit6_fields[]={
 SX_FIELD("class_code","msb_bits[6,7]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code7_bit6={UINT32_C(0x608d00ae),"fls_code7_bit6",sxarwire_fls_code7_bit6_fields,SX_COUNT(sxarwire_fls_code7_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code7_bit7_fields[]={
 SX_FIELD("class_code","msb_bits[7,7]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code7_bit7={UINT32_C(0x608d00af),"fls_code7_bit7",sxarwire_fls_code7_bit7_fields,SX_COUNT(sxarwire_fls_code7_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code8_bit0_fields[]={
 SX_FIELD("class_code","msb_bits[0,8]",0,1,SX_NONE),
};
const sx_layout sxarwire_fls_code8_bit0={UINT32_C(0x608d00b0),"fls_code8_bit0",sxarwire_fls_code8_bit0_fields,SX_COUNT(sxarwire_fls_code8_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code8_bit1_fields[]={
 SX_FIELD("class_code","msb_bits[1,8]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code8_bit1={UINT32_C(0x608d00b1),"fls_code8_bit1",sxarwire_fls_code8_bit1_fields,SX_COUNT(sxarwire_fls_code8_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code8_bit2_fields[]={
 SX_FIELD("class_code","msb_bits[2,8]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code8_bit2={UINT32_C(0x608d00b2),"fls_code8_bit2",sxarwire_fls_code8_bit2_fields,SX_COUNT(sxarwire_fls_code8_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code8_bit3_fields[]={
 SX_FIELD("class_code","msb_bits[3,8]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code8_bit3={UINT32_C(0x608d00b3),"fls_code8_bit3",sxarwire_fls_code8_bit3_fields,SX_COUNT(sxarwire_fls_code8_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code8_bit4_fields[]={
 SX_FIELD("class_code","msb_bits[4,8]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code8_bit4={UINT32_C(0x608d00b4),"fls_code8_bit4",sxarwire_fls_code8_bit4_fields,SX_COUNT(sxarwire_fls_code8_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code8_bit5_fields[]={
 SX_FIELD("class_code","msb_bits[5,8]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code8_bit5={UINT32_C(0x608d00b5),"fls_code8_bit5",sxarwire_fls_code8_bit5_fields,SX_COUNT(sxarwire_fls_code8_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code8_bit6_fields[]={
 SX_FIELD("class_code","msb_bits[6,8]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code8_bit6={UINT32_C(0x608d00b6),"fls_code8_bit6",sxarwire_fls_code8_bit6_fields,SX_COUNT(sxarwire_fls_code8_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code8_bit7_fields[]={
 SX_FIELD("class_code","msb_bits[7,8]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code8_bit7={UINT32_C(0x608d00b7),"fls_code8_bit7",sxarwire_fls_code8_bit7_fields,SX_COUNT(sxarwire_fls_code8_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code10_bit0_fields[]={
 SX_FIELD("class_code","msb_bits[0,10]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code10_bit0={UINT32_C(0x608d00b8),"fls_code10_bit0",sxarwire_fls_code10_bit0_fields,SX_COUNT(sxarwire_fls_code10_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code10_bit1_fields[]={
 SX_FIELD("class_code","msb_bits[1,10]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code10_bit1={UINT32_C(0x608d00b9),"fls_code10_bit1",sxarwire_fls_code10_bit1_fields,SX_COUNT(sxarwire_fls_code10_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code10_bit2_fields[]={
 SX_FIELD("class_code","msb_bits[2,10]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code10_bit2={UINT32_C(0x608d00ba),"fls_code10_bit2",sxarwire_fls_code10_bit2_fields,SX_COUNT(sxarwire_fls_code10_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code10_bit3_fields[]={
 SX_FIELD("class_code","msb_bits[3,10]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code10_bit3={UINT32_C(0x608d00bb),"fls_code10_bit3",sxarwire_fls_code10_bit3_fields,SX_COUNT(sxarwire_fls_code10_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code10_bit4_fields[]={
 SX_FIELD("class_code","msb_bits[4,10]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code10_bit4={UINT32_C(0x608d00bc),"fls_code10_bit4",sxarwire_fls_code10_bit4_fields,SX_COUNT(sxarwire_fls_code10_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code10_bit5_fields[]={
 SX_FIELD("class_code","msb_bits[5,10]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code10_bit5={UINT32_C(0x608d00bd),"fls_code10_bit5",sxarwire_fls_code10_bit5_fields,SX_COUNT(sxarwire_fls_code10_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code10_bit6_fields[]={
 SX_FIELD("class_code","msb_bits[6,10]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code10_bit6={UINT32_C(0x608d00be),"fls_code10_bit6",sxarwire_fls_code10_bit6_fields,SX_COUNT(sxarwire_fls_code10_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code10_bit7_fields[]={
 SX_FIELD("class_code","msb_bits[7,10]",0,3,SX_NONE),
};
const sx_layout sxarwire_fls_code10_bit7={UINT32_C(0x608d00bf),"fls_code10_bit7",sxarwire_fls_code10_bit7_fields,SX_COUNT(sxarwire_fls_code10_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code12_bit0_fields[]={
 SX_FIELD("class_code","msb_bits[0,12]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code12_bit0={UINT32_C(0x608d00c0),"fls_code12_bit0",sxarwire_fls_code12_bit0_fields,SX_COUNT(sxarwire_fls_code12_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code12_bit1_fields[]={
 SX_FIELD("class_code","msb_bits[1,12]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code12_bit1={UINT32_C(0x608d00c1),"fls_code12_bit1",sxarwire_fls_code12_bit1_fields,SX_COUNT(sxarwire_fls_code12_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code12_bit2_fields[]={
 SX_FIELD("class_code","msb_bits[2,12]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code12_bit2={UINT32_C(0x608d00c2),"fls_code12_bit2",sxarwire_fls_code12_bit2_fields,SX_COUNT(sxarwire_fls_code12_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code12_bit3_fields[]={
 SX_FIELD("class_code","msb_bits[3,12]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code12_bit3={UINT32_C(0x608d00c3),"fls_code12_bit3",sxarwire_fls_code12_bit3_fields,SX_COUNT(sxarwire_fls_code12_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code12_bit4_fields[]={
 SX_FIELD("class_code","msb_bits[4,12]",0,2,SX_NONE),
};
const sx_layout sxarwire_fls_code12_bit4={UINT32_C(0x608d00c4),"fls_code12_bit4",sxarwire_fls_code12_bit4_fields,SX_COUNT(sxarwire_fls_code12_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code12_bit5_fields[]={
 SX_FIELD("class_code","msb_bits[5,12]",0,3,SX_NONE),
};
const sx_layout sxarwire_fls_code12_bit5={UINT32_C(0x608d00c5),"fls_code12_bit5",sxarwire_fls_code12_bit5_fields,SX_COUNT(sxarwire_fls_code12_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code12_bit6_fields[]={
 SX_FIELD("class_code","msb_bits[6,12]",0,3,SX_NONE),
};
const sx_layout sxarwire_fls_code12_bit6={UINT32_C(0x608d00c6),"fls_code12_bit6",sxarwire_fls_code12_bit6_fields,SX_COUNT(sxarwire_fls_code12_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_fls_code12_bit7_fields[]={
 SX_FIELD("class_code","msb_bits[7,12]",0,3,SX_NONE),
};
const sx_layout sxarwire_fls_code12_bit7={UINT32_C(0x608d00c7),"fls_code12_bit7",sxarwire_fls_code12_bit7_fields,SX_COUNT(sxarwire_fls_code12_bit7_fields),SX_LE};
static const sx_layout *const sxarwire_set_fls_first_class[]={&sxarwire_fls_first_class_bit0,&sxarwire_fls_first_class_bit1,&sxarwire_fls_first_class_bit2,&sxarwire_fls_first_class_bit3,&sxarwire_fls_first_class_bit4,&sxarwire_fls_first_class_bit5,&sxarwire_fls_first_class_bit6,&sxarwire_fls_first_class_bit7};
static const sx_layout *const sxarwire_set_fls_second_class[]={&sxarwire_fls_second_class_bit0,&sxarwire_fls_second_class_bit1,&sxarwire_fls_second_class_bit2,&sxarwire_fls_second_class_bit3,&sxarwire_fls_second_class_bit4,&sxarwire_fls_second_class_bit5,&sxarwire_fls_second_class_bit6,&sxarwire_fls_second_class_bit7};
static const sx_layout *const sxarwire_set_fls_selector_prefix[]={&sxarwire_fls_selector_prefix_bit0,&sxarwire_fls_selector_prefix_bit1,&sxarwire_fls_selector_prefix_bit2,&sxarwire_fls_selector_prefix_bit3,&sxarwire_fls_selector_prefix_bit4,&sxarwire_fls_selector_prefix_bit5,&sxarwire_fls_selector_prefix_bit6,&sxarwire_fls_selector_prefix_bit7};
static const sx_layout *const sxarwire_set_fls_selector_extension[]={&sxarwire_fls_selector_extension_bit0,&sxarwire_fls_selector_extension_bit1,&sxarwire_fls_selector_extension_bit2,&sxarwire_fls_selector_extension_bit3,&sxarwire_fls_selector_extension_bit4,&sxarwire_fls_selector_extension_bit5,&sxarwire_fls_selector_extension_bit6,&sxarwire_fls_selector_extension_bit7};
static const sx_layout *const sxarwire_set_fls_code6[]={&sxarwire_fls_code6_bit0,&sxarwire_fls_code6_bit1,&sxarwire_fls_code6_bit2,&sxarwire_fls_code6_bit3,&sxarwire_fls_code6_bit4,&sxarwire_fls_code6_bit5,&sxarwire_fls_code6_bit6,&sxarwire_fls_code6_bit7};
static const sx_layout *const sxarwire_set_fls_code7[]={&sxarwire_fls_code7_bit0,&sxarwire_fls_code7_bit1,&sxarwire_fls_code7_bit2,&sxarwire_fls_code7_bit3,&sxarwire_fls_code7_bit4,&sxarwire_fls_code7_bit5,&sxarwire_fls_code7_bit6,&sxarwire_fls_code7_bit7};
static const sx_layout *const sxarwire_set_fls_code8[]={&sxarwire_fls_code8_bit0,&sxarwire_fls_code8_bit1,&sxarwire_fls_code8_bit2,&sxarwire_fls_code8_bit3,&sxarwire_fls_code8_bit4,&sxarwire_fls_code8_bit5,&sxarwire_fls_code8_bit6,&sxarwire_fls_code8_bit7};
static const sx_layout *const sxarwire_set_fls_code10[]={&sxarwire_fls_code10_bit0,&sxarwire_fls_code10_bit1,&sxarwire_fls_code10_bit2,&sxarwire_fls_code10_bit3,&sxarwire_fls_code10_bit4,&sxarwire_fls_code10_bit5,&sxarwire_fls_code10_bit6,&sxarwire_fls_code10_bit7};
static const sx_layout *const sxarwire_set_fls_code12[]={&sxarwire_fls_code12_bit0,&sxarwire_fls_code12_bit1,&sxarwire_fls_code12_bit2,&sxarwire_fls_code12_bit3,&sxarwire_fls_code12_bit4,&sxarwire_fls_code12_bit5,&sxarwire_fls_code12_bit6,&sxarwire_fls_code12_bit7};
#define SXARWIRE_LIMIT 20000U
static const sx_layout*const*sxarwire_fls_set(unsigned n){switch(n){case 6:return sxarwire_set_fls_code6;case 7:return sxarwire_set_fls_code7;case 8:return sxarwire_set_fls_code8;case 10:return sxarwire_set_fls_code10;case 12:return sxarwire_set_fls_code12;default:return NULL;}}
static bool sxarwire_fls(sx_context*c){
 static const unsigned widths[6]={7,6,7,8,10,12},bases[6]={0,128,192,320,576,1600};unsigned order[6]={0},counter=499;
 if(!sxarwire_put(c,&sxarwire_ibmspack_tag,0))return false;sxarwire_bits b={c,8,false,0,0,false};
 while(c->count<SXARWIRE_LIMIT){uint64_t a,z,v;if(++counter==500){if(!sxarwire_field(&b,sxarwire_set_fls_first_class,3,&a)||!sxarwire_field(&b,sxarwire_set_fls_second_class,3,&z)||a>=6||z>=6||a==z)return false;order[0]=(unsigned)a;order[1]=(unsigned)z;unsigned out=2;for(unsigned i=0;i<6;i++)if(i!=a&&i!=z)order[out++]=i;counter=0;}
  if(!sxarwire_field(&b,sxarwire_set_fls_selector_prefix,2,&a))return false;if(a>=2){if(!sxarwire_field(&b,sxarwire_set_fls_selector_extension,1,&z))return false;a=2*a-2+z;}unsigned cl=order[a];if(!sxarwire_field(&b,sxarwire_fls_set(widths[cl]),widths[cl],&v))return false;if(v+bases[cl]==5695)return true;
 }return true;
}
bool sx_ibmspack_build(sx_context*c)
{
 return sxarwire_fls(c);
}
