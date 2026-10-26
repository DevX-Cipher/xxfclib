/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SCO UNIX compress data structures, moved out of the archivewire schema family. */
#include "../../xx_format_schema_archivewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarwire_sco_signature_fields[]={
 SX_FIELD("signature","uint8[2]",0,2,SX_SIGNATURE),
};
const sx_layout sxarwire_sco_signature={UINT32_C(0x608d00c8),"sco_signature",sxarwire_sco_signature_fields,SX_COUNT(sxarwire_sco_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_block_count_bit0_fields[]={
 SX_FIELD("symbol_count","msb_bits[0,16]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_block_count_bit0={UINT32_C(0x608d00c9),"sco_block_count_bit0",sxarwire_sco_block_count_bit0_fields,SX_COUNT(sxarwire_sco_block_count_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_block_count_bit1_fields[]={
 SX_FIELD("symbol_count","msb_bits[1,16]",0,3,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_block_count_bit1={UINT32_C(0x608d00ca),"sco_block_count_bit1",sxarwire_sco_block_count_bit1_fields,SX_COUNT(sxarwire_sco_block_count_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_block_count_bit2_fields[]={
 SX_FIELD("symbol_count","msb_bits[2,16]",0,3,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_block_count_bit2={UINT32_C(0x608d00cb),"sco_block_count_bit2",sxarwire_sco_block_count_bit2_fields,SX_COUNT(sxarwire_sco_block_count_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_block_count_bit3_fields[]={
 SX_FIELD("symbol_count","msb_bits[3,16]",0,3,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_block_count_bit3={UINT32_C(0x608d00cc),"sco_block_count_bit3",sxarwire_sco_block_count_bit3_fields,SX_COUNT(sxarwire_sco_block_count_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_block_count_bit4_fields[]={
 SX_FIELD("symbol_count","msb_bits[4,16]",0,3,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_block_count_bit4={UINT32_C(0x608d00cd),"sco_block_count_bit4",sxarwire_sco_block_count_bit4_fields,SX_COUNT(sxarwire_sco_block_count_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_block_count_bit5_fields[]={
 SX_FIELD("symbol_count","msb_bits[5,16]",0,3,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_block_count_bit5={UINT32_C(0x608d00ce),"sco_block_count_bit5",sxarwire_sco_block_count_bit5_fields,SX_COUNT(sxarwire_sco_block_count_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_block_count_bit6_fields[]={
 SX_FIELD("symbol_count","msb_bits[6,16]",0,3,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_block_count_bit6={UINT32_C(0x608d00cf),"sco_block_count_bit6",sxarwire_sco_block_count_bit6_fields,SX_COUNT(sxarwire_sco_block_count_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_block_count_bit7_fields[]={
 SX_FIELD("symbol_count","msb_bits[7,16]",0,3,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_block_count_bit7={UINT32_C(0x608d00d0),"sco_block_count_bit7",sxarwire_sco_block_count_bit7_fields,SX_COUNT(sxarwire_sco_block_count_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_count_bit0_fields[]={
 SX_FIELD("code_length_count","msb_bits[0,5]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_pretree_count_bit0={UINT32_C(0x608d00d1),"sco_pretree_count_bit0",sxarwire_sco_pretree_count_bit0_fields,SX_COUNT(sxarwire_sco_pretree_count_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_count_bit1_fields[]={
 SX_FIELD("code_length_count","msb_bits[1,5]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_pretree_count_bit1={UINT32_C(0x608d00d2),"sco_pretree_count_bit1",sxarwire_sco_pretree_count_bit1_fields,SX_COUNT(sxarwire_sco_pretree_count_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_count_bit2_fields[]={
 SX_FIELD("code_length_count","msb_bits[2,5]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_pretree_count_bit2={UINT32_C(0x608d00d3),"sco_pretree_count_bit2",sxarwire_sco_pretree_count_bit2_fields,SX_COUNT(sxarwire_sco_pretree_count_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_count_bit3_fields[]={
 SX_FIELD("code_length_count","msb_bits[3,5]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_pretree_count_bit3={UINT32_C(0x608d00d4),"sco_pretree_count_bit3",sxarwire_sco_pretree_count_bit3_fields,SX_COUNT(sxarwire_sco_pretree_count_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_count_bit4_fields[]={
 SX_FIELD("code_length_count","msb_bits[4,5]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_pretree_count_bit4={UINT32_C(0x608d00d5),"sco_pretree_count_bit4",sxarwire_sco_pretree_count_bit4_fields,SX_COUNT(sxarwire_sco_pretree_count_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_count_bit5_fields[]={
 SX_FIELD("code_length_count","msb_bits[5,5]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_pretree_count_bit5={UINT32_C(0x608d00d6),"sco_pretree_count_bit5",sxarwire_sco_pretree_count_bit5_fields,SX_COUNT(sxarwire_sco_pretree_count_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_count_bit6_fields[]={
 SX_FIELD("code_length_count","msb_bits[6,5]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_pretree_count_bit6={UINT32_C(0x608d00d7),"sco_pretree_count_bit6",sxarwire_sco_pretree_count_bit6_fields,SX_COUNT(sxarwire_sco_pretree_count_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_count_bit7_fields[]={
 SX_FIELD("code_length_count","msb_bits[7,5]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_pretree_count_bit7={UINT32_C(0x608d00d8),"sco_pretree_count_bit7",sxarwire_sco_pretree_count_bit7_fields,SX_COUNT(sxarwire_sco_pretree_count_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_single_bit0_fields[]={
 SX_FIELD("single_code_length_symbol","msb_bits[0,5]",0,1,SX_ID),
};
const sx_layout sxarwire_sco_pretree_single_bit0={UINT32_C(0x608d00d9),"sco_pretree_single_bit0",sxarwire_sco_pretree_single_bit0_fields,SX_COUNT(sxarwire_sco_pretree_single_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_single_bit1_fields[]={
 SX_FIELD("single_code_length_symbol","msb_bits[1,5]",0,1,SX_ID),
};
const sx_layout sxarwire_sco_pretree_single_bit1={UINT32_C(0x608d00da),"sco_pretree_single_bit1",sxarwire_sco_pretree_single_bit1_fields,SX_COUNT(sxarwire_sco_pretree_single_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_single_bit2_fields[]={
 SX_FIELD("single_code_length_symbol","msb_bits[2,5]",0,1,SX_ID),
};
const sx_layout sxarwire_sco_pretree_single_bit2={UINT32_C(0x608d00db),"sco_pretree_single_bit2",sxarwire_sco_pretree_single_bit2_fields,SX_COUNT(sxarwire_sco_pretree_single_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_single_bit3_fields[]={
 SX_FIELD("single_code_length_symbol","msb_bits[3,5]",0,1,SX_ID),
};
const sx_layout sxarwire_sco_pretree_single_bit3={UINT32_C(0x608d00dc),"sco_pretree_single_bit3",sxarwire_sco_pretree_single_bit3_fields,SX_COUNT(sxarwire_sco_pretree_single_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_single_bit4_fields[]={
 SX_FIELD("single_code_length_symbol","msb_bits[4,5]",0,2,SX_ID),
};
const sx_layout sxarwire_sco_pretree_single_bit4={UINT32_C(0x608d00dd),"sco_pretree_single_bit4",sxarwire_sco_pretree_single_bit4_fields,SX_COUNT(sxarwire_sco_pretree_single_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_single_bit5_fields[]={
 SX_FIELD("single_code_length_symbol","msb_bits[5,5]",0,2,SX_ID),
};
const sx_layout sxarwire_sco_pretree_single_bit5={UINT32_C(0x608d00de),"sco_pretree_single_bit5",sxarwire_sco_pretree_single_bit5_fields,SX_COUNT(sxarwire_sco_pretree_single_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_single_bit6_fields[]={
 SX_FIELD("single_code_length_symbol","msb_bits[6,5]",0,2,SX_ID),
};
const sx_layout sxarwire_sco_pretree_single_bit6={UINT32_C(0x608d00df),"sco_pretree_single_bit6",sxarwire_sco_pretree_single_bit6_fields,SX_COUNT(sxarwire_sco_pretree_single_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_single_bit7_fields[]={
 SX_FIELD("single_code_length_symbol","msb_bits[7,5]",0,2,SX_ID),
};
const sx_layout sxarwire_sco_pretree_single_bit7={UINT32_C(0x608d00e0),"sco_pretree_single_bit7",sxarwire_sco_pretree_single_bit7_fields,SX_COUNT(sxarwire_sco_pretree_single_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_bit0_fields[]={
 SX_FIELD("code_length_prefix","msb_bits[0,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_code_length_bit0={UINT32_C(0x608d00e1),"sco_code_length_bit0",sxarwire_sco_code_length_bit0_fields,SX_COUNT(sxarwire_sco_code_length_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_bit1_fields[]={
 SX_FIELD("code_length_prefix","msb_bits[1,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_code_length_bit1={UINT32_C(0x608d00e2),"sco_code_length_bit1",sxarwire_sco_code_length_bit1_fields,SX_COUNT(sxarwire_sco_code_length_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_bit2_fields[]={
 SX_FIELD("code_length_prefix","msb_bits[2,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_code_length_bit2={UINT32_C(0x608d00e3),"sco_code_length_bit2",sxarwire_sco_code_length_bit2_fields,SX_COUNT(sxarwire_sco_code_length_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_bit3_fields[]={
 SX_FIELD("code_length_prefix","msb_bits[3,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_code_length_bit3={UINT32_C(0x608d00e4),"sco_code_length_bit3",sxarwire_sco_code_length_bit3_fields,SX_COUNT(sxarwire_sco_code_length_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_bit4_fields[]={
 SX_FIELD("code_length_prefix","msb_bits[4,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_code_length_bit4={UINT32_C(0x608d00e5),"sco_code_length_bit4",sxarwire_sco_code_length_bit4_fields,SX_COUNT(sxarwire_sco_code_length_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_bit5_fields[]={
 SX_FIELD("code_length_prefix","msb_bits[5,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_code_length_bit5={UINT32_C(0x608d00e6),"sco_code_length_bit5",sxarwire_sco_code_length_bit5_fields,SX_COUNT(sxarwire_sco_code_length_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_bit6_fields[]={
 SX_FIELD("code_length_prefix","msb_bits[6,3]",0,2,SX_NONE),
};
const sx_layout sxarwire_sco_code_length_bit6={UINT32_C(0x608d00e7),"sco_code_length_bit6",sxarwire_sco_code_length_bit6_fields,SX_COUNT(sxarwire_sco_code_length_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_bit7_fields[]={
 SX_FIELD("code_length_prefix","msb_bits[7,3]",0,2,SX_NONE),
};
const sx_layout sxarwire_sco_code_length_bit7={UINT32_C(0x608d00e8),"sco_code_length_bit7",sxarwire_sco_code_length_bit7_fields,SX_COUNT(sxarwire_sco_code_length_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_more_bit0_fields[]={
 SX_FIELD("length_extension_bit","msb_bits[0,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_sco_code_length_more_bit0={UINT32_C(0x608d00e9),"sco_code_length_more_bit0",sxarwire_sco_code_length_more_bit0_fields,SX_COUNT(sxarwire_sco_code_length_more_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_more_bit1_fields[]={
 SX_FIELD("length_extension_bit","msb_bits[1,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_sco_code_length_more_bit1={UINT32_C(0x608d00ea),"sco_code_length_more_bit1",sxarwire_sco_code_length_more_bit1_fields,SX_COUNT(sxarwire_sco_code_length_more_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_more_bit2_fields[]={
 SX_FIELD("length_extension_bit","msb_bits[2,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_sco_code_length_more_bit2={UINT32_C(0x608d00eb),"sco_code_length_more_bit2",sxarwire_sco_code_length_more_bit2_fields,SX_COUNT(sxarwire_sco_code_length_more_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_more_bit3_fields[]={
 SX_FIELD("length_extension_bit","msb_bits[3,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_sco_code_length_more_bit3={UINT32_C(0x608d00ec),"sco_code_length_more_bit3",sxarwire_sco_code_length_more_bit3_fields,SX_COUNT(sxarwire_sco_code_length_more_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_more_bit4_fields[]={
 SX_FIELD("length_extension_bit","msb_bits[4,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_sco_code_length_more_bit4={UINT32_C(0x608d00ed),"sco_code_length_more_bit4",sxarwire_sco_code_length_more_bit4_fields,SX_COUNT(sxarwire_sco_code_length_more_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_more_bit5_fields[]={
 SX_FIELD("length_extension_bit","msb_bits[5,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_sco_code_length_more_bit5={UINT32_C(0x608d00ee),"sco_code_length_more_bit5",sxarwire_sco_code_length_more_bit5_fields,SX_COUNT(sxarwire_sco_code_length_more_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_more_bit6_fields[]={
 SX_FIELD("length_extension_bit","msb_bits[6,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_sco_code_length_more_bit6={UINT32_C(0x608d00ef),"sco_code_length_more_bit6",sxarwire_sco_code_length_more_bit6_fields,SX_COUNT(sxarwire_sco_code_length_more_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_code_length_more_bit7_fields[]={
 SX_FIELD("length_extension_bit","msb_bits[7,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_sco_code_length_more_bit7={UINT32_C(0x608d00f0),"sco_code_length_more_bit7",sxarwire_sco_code_length_more_bit7_fields,SX_COUNT(sxarwire_sco_code_length_more_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_zeros_bit0_fields[]={
 SX_FIELD("zero_length_run","msb_bits[0,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_pretree_zeros_bit0={UINT32_C(0x608d00f1),"sco_pretree_zeros_bit0",sxarwire_sco_pretree_zeros_bit0_fields,SX_COUNT(sxarwire_sco_pretree_zeros_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_zeros_bit1_fields[]={
 SX_FIELD("zero_length_run","msb_bits[1,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_pretree_zeros_bit1={UINT32_C(0x608d00f2),"sco_pretree_zeros_bit1",sxarwire_sco_pretree_zeros_bit1_fields,SX_COUNT(sxarwire_sco_pretree_zeros_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_zeros_bit2_fields[]={
 SX_FIELD("zero_length_run","msb_bits[2,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_pretree_zeros_bit2={UINT32_C(0x608d00f3),"sco_pretree_zeros_bit2",sxarwire_sco_pretree_zeros_bit2_fields,SX_COUNT(sxarwire_sco_pretree_zeros_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_zeros_bit3_fields[]={
 SX_FIELD("zero_length_run","msb_bits[3,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_pretree_zeros_bit3={UINT32_C(0x608d00f4),"sco_pretree_zeros_bit3",sxarwire_sco_pretree_zeros_bit3_fields,SX_COUNT(sxarwire_sco_pretree_zeros_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_zeros_bit4_fields[]={
 SX_FIELD("zero_length_run","msb_bits[4,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_pretree_zeros_bit4={UINT32_C(0x608d00f5),"sco_pretree_zeros_bit4",sxarwire_sco_pretree_zeros_bit4_fields,SX_COUNT(sxarwire_sco_pretree_zeros_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_zeros_bit5_fields[]={
 SX_FIELD("zero_length_run","msb_bits[5,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_pretree_zeros_bit5={UINT32_C(0x608d00f6),"sco_pretree_zeros_bit5",sxarwire_sco_pretree_zeros_bit5_fields,SX_COUNT(sxarwire_sco_pretree_zeros_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_zeros_bit6_fields[]={
 SX_FIELD("zero_length_run","msb_bits[6,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_pretree_zeros_bit6={UINT32_C(0x608d00f7),"sco_pretree_zeros_bit6",sxarwire_sco_pretree_zeros_bit6_fields,SX_COUNT(sxarwire_sco_pretree_zeros_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_pretree_zeros_bit7_fields[]={
 SX_FIELD("zero_length_run","msb_bits[7,2]",0,2,SX_NONE),
};
const sx_layout sxarwire_sco_pretree_zeros_bit7={UINT32_C(0x608d00f8),"sco_pretree_zeros_bit7",sxarwire_sco_pretree_zeros_bit7_fields,SX_COUNT(sxarwire_sco_pretree_zeros_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_count_bit0_fields[]={
 SX_FIELD("literal_length_code_count","msb_bits[0,9]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_literal_count_bit0={UINT32_C(0x608d00f9),"sco_literal_count_bit0",sxarwire_sco_literal_count_bit0_fields,SX_COUNT(sxarwire_sco_literal_count_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_count_bit1_fields[]={
 SX_FIELD("literal_length_code_count","msb_bits[1,9]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_literal_count_bit1={UINT32_C(0x608d00fa),"sco_literal_count_bit1",sxarwire_sco_literal_count_bit1_fields,SX_COUNT(sxarwire_sco_literal_count_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_count_bit2_fields[]={
 SX_FIELD("literal_length_code_count","msb_bits[2,9]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_literal_count_bit2={UINT32_C(0x608d00fb),"sco_literal_count_bit2",sxarwire_sco_literal_count_bit2_fields,SX_COUNT(sxarwire_sco_literal_count_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_count_bit3_fields[]={
 SX_FIELD("literal_length_code_count","msb_bits[3,9]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_literal_count_bit3={UINT32_C(0x608d00fc),"sco_literal_count_bit3",sxarwire_sco_literal_count_bit3_fields,SX_COUNT(sxarwire_sco_literal_count_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_count_bit4_fields[]={
 SX_FIELD("literal_length_code_count","msb_bits[4,9]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_literal_count_bit4={UINT32_C(0x608d00fd),"sco_literal_count_bit4",sxarwire_sco_literal_count_bit4_fields,SX_COUNT(sxarwire_sco_literal_count_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_count_bit5_fields[]={
 SX_FIELD("literal_length_code_count","msb_bits[5,9]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_literal_count_bit5={UINT32_C(0x608d00fe),"sco_literal_count_bit5",sxarwire_sco_literal_count_bit5_fields,SX_COUNT(sxarwire_sco_literal_count_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_count_bit6_fields[]={
 SX_FIELD("literal_length_code_count","msb_bits[6,9]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_literal_count_bit6={UINT32_C(0x608d00ff),"sco_literal_count_bit6",sxarwire_sco_literal_count_bit6_fields,SX_COUNT(sxarwire_sco_literal_count_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_count_bit7_fields[]={
 SX_FIELD("literal_length_code_count","msb_bits[7,9]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_literal_count_bit7={UINT32_C(0x608d0100),"sco_literal_count_bit7",sxarwire_sco_literal_count_bit7_fields,SX_COUNT(sxarwire_sco_literal_count_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_single_bit0_fields[]={
 SX_FIELD("single_literal_length_symbol","msb_bits[0,9]",0,2,SX_ID),
};
const sx_layout sxarwire_sco_literal_single_bit0={UINT32_C(0x608d0101),"sco_literal_single_bit0",sxarwire_sco_literal_single_bit0_fields,SX_COUNT(sxarwire_sco_literal_single_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_single_bit1_fields[]={
 SX_FIELD("single_literal_length_symbol","msb_bits[1,9]",0,2,SX_ID),
};
const sx_layout sxarwire_sco_literal_single_bit1={UINT32_C(0x608d0102),"sco_literal_single_bit1",sxarwire_sco_literal_single_bit1_fields,SX_COUNT(sxarwire_sco_literal_single_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_single_bit2_fields[]={
 SX_FIELD("single_literal_length_symbol","msb_bits[2,9]",0,2,SX_ID),
};
const sx_layout sxarwire_sco_literal_single_bit2={UINT32_C(0x608d0103),"sco_literal_single_bit2",sxarwire_sco_literal_single_bit2_fields,SX_COUNT(sxarwire_sco_literal_single_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_single_bit3_fields[]={
 SX_FIELD("single_literal_length_symbol","msb_bits[3,9]",0,2,SX_ID),
};
const sx_layout sxarwire_sco_literal_single_bit3={UINT32_C(0x608d0104),"sco_literal_single_bit3",sxarwire_sco_literal_single_bit3_fields,SX_COUNT(sxarwire_sco_literal_single_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_single_bit4_fields[]={
 SX_FIELD("single_literal_length_symbol","msb_bits[4,9]",0,2,SX_ID),
};
const sx_layout sxarwire_sco_literal_single_bit4={UINT32_C(0x608d0105),"sco_literal_single_bit4",sxarwire_sco_literal_single_bit4_fields,SX_COUNT(sxarwire_sco_literal_single_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_single_bit5_fields[]={
 SX_FIELD("single_literal_length_symbol","msb_bits[5,9]",0,2,SX_ID),
};
const sx_layout sxarwire_sco_literal_single_bit5={UINT32_C(0x608d0106),"sco_literal_single_bit5",sxarwire_sco_literal_single_bit5_fields,SX_COUNT(sxarwire_sco_literal_single_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_single_bit6_fields[]={
 SX_FIELD("single_literal_length_symbol","msb_bits[6,9]",0,2,SX_ID),
};
const sx_layout sxarwire_sco_literal_single_bit6={UINT32_C(0x608d0107),"sco_literal_single_bit6",sxarwire_sco_literal_single_bit6_fields,SX_COUNT(sxarwire_sco_literal_single_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_literal_single_bit7_fields[]={
 SX_FIELD("single_literal_length_symbol","msb_bits[7,9]",0,2,SX_ID),
};
const sx_layout sxarwire_sco_literal_single_bit7={UINT32_C(0x608d0108),"sco_literal_single_bit7",sxarwire_sco_literal_single_bit7_fields,SX_COUNT(sxarwire_sco_literal_single_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_count_bit0_fields[]={
 SX_FIELD("position_code_count","msb_bits[0,4]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_position_count_bit0={UINT32_C(0x608d0109),"sco_position_count_bit0",sxarwire_sco_position_count_bit0_fields,SX_COUNT(sxarwire_sco_position_count_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_count_bit1_fields[]={
 SX_FIELD("position_code_count","msb_bits[1,4]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_position_count_bit1={UINT32_C(0x608d010a),"sco_position_count_bit1",sxarwire_sco_position_count_bit1_fields,SX_COUNT(sxarwire_sco_position_count_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_count_bit2_fields[]={
 SX_FIELD("position_code_count","msb_bits[2,4]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_position_count_bit2={UINT32_C(0x608d010b),"sco_position_count_bit2",sxarwire_sco_position_count_bit2_fields,SX_COUNT(sxarwire_sco_position_count_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_count_bit3_fields[]={
 SX_FIELD("position_code_count","msb_bits[3,4]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_position_count_bit3={UINT32_C(0x608d010c),"sco_position_count_bit3",sxarwire_sco_position_count_bit3_fields,SX_COUNT(sxarwire_sco_position_count_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_count_bit4_fields[]={
 SX_FIELD("position_code_count","msb_bits[4,4]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_position_count_bit4={UINT32_C(0x608d010d),"sco_position_count_bit4",sxarwire_sco_position_count_bit4_fields,SX_COUNT(sxarwire_sco_position_count_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_count_bit5_fields[]={
 SX_FIELD("position_code_count","msb_bits[5,4]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_position_count_bit5={UINT32_C(0x608d010e),"sco_position_count_bit5",sxarwire_sco_position_count_bit5_fields,SX_COUNT(sxarwire_sco_position_count_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_count_bit6_fields[]={
 SX_FIELD("position_code_count","msb_bits[6,4]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_position_count_bit6={UINT32_C(0x608d010f),"sco_position_count_bit6",sxarwire_sco_position_count_bit6_fields,SX_COUNT(sxarwire_sco_position_count_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_count_bit7_fields[]={
 SX_FIELD("position_code_count","msb_bits[7,4]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_sco_position_count_bit7={UINT32_C(0x608d0110),"sco_position_count_bit7",sxarwire_sco_position_count_bit7_fields,SX_COUNT(sxarwire_sco_position_count_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_single_bit0_fields[]={
 SX_FIELD("single_position_symbol","msb_bits[0,4]",0,1,SX_ID),
};
const sx_layout sxarwire_sco_position_single_bit0={UINT32_C(0x608d0111),"sco_position_single_bit0",sxarwire_sco_position_single_bit0_fields,SX_COUNT(sxarwire_sco_position_single_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_single_bit1_fields[]={
 SX_FIELD("single_position_symbol","msb_bits[1,4]",0,1,SX_ID),
};
const sx_layout sxarwire_sco_position_single_bit1={UINT32_C(0x608d0112),"sco_position_single_bit1",sxarwire_sco_position_single_bit1_fields,SX_COUNT(sxarwire_sco_position_single_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_single_bit2_fields[]={
 SX_FIELD("single_position_symbol","msb_bits[2,4]",0,1,SX_ID),
};
const sx_layout sxarwire_sco_position_single_bit2={UINT32_C(0x608d0113),"sco_position_single_bit2",sxarwire_sco_position_single_bit2_fields,SX_COUNT(sxarwire_sco_position_single_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_single_bit3_fields[]={
 SX_FIELD("single_position_symbol","msb_bits[3,4]",0,1,SX_ID),
};
const sx_layout sxarwire_sco_position_single_bit3={UINT32_C(0x608d0114),"sco_position_single_bit3",sxarwire_sco_position_single_bit3_fields,SX_COUNT(sxarwire_sco_position_single_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_single_bit4_fields[]={
 SX_FIELD("single_position_symbol","msb_bits[4,4]",0,1,SX_ID),
};
const sx_layout sxarwire_sco_position_single_bit4={UINT32_C(0x608d0115),"sco_position_single_bit4",sxarwire_sco_position_single_bit4_fields,SX_COUNT(sxarwire_sco_position_single_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_single_bit5_fields[]={
 SX_FIELD("single_position_symbol","msb_bits[5,4]",0,2,SX_ID),
};
const sx_layout sxarwire_sco_position_single_bit5={UINT32_C(0x608d0116),"sco_position_single_bit5",sxarwire_sco_position_single_bit5_fields,SX_COUNT(sxarwire_sco_position_single_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_single_bit6_fields[]={
 SX_FIELD("single_position_symbol","msb_bits[6,4]",0,2,SX_ID),
};
const sx_layout sxarwire_sco_position_single_bit6={UINT32_C(0x608d0117),"sco_position_single_bit6",sxarwire_sco_position_single_bit6_fields,SX_COUNT(sxarwire_sco_position_single_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_position_single_bit7_fields[]={
 SX_FIELD("single_position_symbol","msb_bits[7,4]",0,2,SX_ID),
};
const sx_layout sxarwire_sco_position_single_bit7={UINT32_C(0x608d0118),"sco_position_single_bit7",sxarwire_sco_position_single_bit7_fields,SX_COUNT(sxarwire_sco_position_single_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat4_bit0_fields[]={
 SX_FIELD("repeat_extra","msb_bits[0,4]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat4_bit0={UINT32_C(0x608d0119),"sco_zero_repeat4_bit0",sxarwire_sco_zero_repeat4_bit0_fields,SX_COUNT(sxarwire_sco_zero_repeat4_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat4_bit1_fields[]={
 SX_FIELD("repeat_extra","msb_bits[1,4]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat4_bit1={UINT32_C(0x608d011a),"sco_zero_repeat4_bit1",sxarwire_sco_zero_repeat4_bit1_fields,SX_COUNT(sxarwire_sco_zero_repeat4_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat4_bit2_fields[]={
 SX_FIELD("repeat_extra","msb_bits[2,4]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat4_bit2={UINT32_C(0x608d011b),"sco_zero_repeat4_bit2",sxarwire_sco_zero_repeat4_bit2_fields,SX_COUNT(sxarwire_sco_zero_repeat4_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat4_bit3_fields[]={
 SX_FIELD("repeat_extra","msb_bits[3,4]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat4_bit3={UINT32_C(0x608d011c),"sco_zero_repeat4_bit3",sxarwire_sco_zero_repeat4_bit3_fields,SX_COUNT(sxarwire_sco_zero_repeat4_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat4_bit4_fields[]={
 SX_FIELD("repeat_extra","msb_bits[4,4]",0,1,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat4_bit4={UINT32_C(0x608d011d),"sco_zero_repeat4_bit4",sxarwire_sco_zero_repeat4_bit4_fields,SX_COUNT(sxarwire_sco_zero_repeat4_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat4_bit5_fields[]={
 SX_FIELD("repeat_extra","msb_bits[5,4]",0,2,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat4_bit5={UINT32_C(0x608d011e),"sco_zero_repeat4_bit5",sxarwire_sco_zero_repeat4_bit5_fields,SX_COUNT(sxarwire_sco_zero_repeat4_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat4_bit6_fields[]={
 SX_FIELD("repeat_extra","msb_bits[6,4]",0,2,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat4_bit6={UINT32_C(0x608d011f),"sco_zero_repeat4_bit6",sxarwire_sco_zero_repeat4_bit6_fields,SX_COUNT(sxarwire_sco_zero_repeat4_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat4_bit7_fields[]={
 SX_FIELD("repeat_extra","msb_bits[7,4]",0,2,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat4_bit7={UINT32_C(0x608d0120),"sco_zero_repeat4_bit7",sxarwire_sco_zero_repeat4_bit7_fields,SX_COUNT(sxarwire_sco_zero_repeat4_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat9_bit0_fields[]={
 SX_FIELD("repeat_extra","msb_bits[0,9]",0,2,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat9_bit0={UINT32_C(0x608d0121),"sco_zero_repeat9_bit0",sxarwire_sco_zero_repeat9_bit0_fields,SX_COUNT(sxarwire_sco_zero_repeat9_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat9_bit1_fields[]={
 SX_FIELD("repeat_extra","msb_bits[1,9]",0,2,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat9_bit1={UINT32_C(0x608d0122),"sco_zero_repeat9_bit1",sxarwire_sco_zero_repeat9_bit1_fields,SX_COUNT(sxarwire_sco_zero_repeat9_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat9_bit2_fields[]={
 SX_FIELD("repeat_extra","msb_bits[2,9]",0,2,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat9_bit2={UINT32_C(0x608d0123),"sco_zero_repeat9_bit2",sxarwire_sco_zero_repeat9_bit2_fields,SX_COUNT(sxarwire_sco_zero_repeat9_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat9_bit3_fields[]={
 SX_FIELD("repeat_extra","msb_bits[3,9]",0,2,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat9_bit3={UINT32_C(0x608d0124),"sco_zero_repeat9_bit3",sxarwire_sco_zero_repeat9_bit3_fields,SX_COUNT(sxarwire_sco_zero_repeat9_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat9_bit4_fields[]={
 SX_FIELD("repeat_extra","msb_bits[4,9]",0,2,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat9_bit4={UINT32_C(0x608d0125),"sco_zero_repeat9_bit4",sxarwire_sco_zero_repeat9_bit4_fields,SX_COUNT(sxarwire_sco_zero_repeat9_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat9_bit5_fields[]={
 SX_FIELD("repeat_extra","msb_bits[5,9]",0,2,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat9_bit5={UINT32_C(0x608d0126),"sco_zero_repeat9_bit5",sxarwire_sco_zero_repeat9_bit5_fields,SX_COUNT(sxarwire_sco_zero_repeat9_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat9_bit6_fields[]={
 SX_FIELD("repeat_extra","msb_bits[6,9]",0,2,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat9_bit6={UINT32_C(0x608d0127),"sco_zero_repeat9_bit6",sxarwire_sco_zero_repeat9_bit6_fields,SX_COUNT(sxarwire_sco_zero_repeat9_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_zero_repeat9_bit7_fields[]={
 SX_FIELD("repeat_extra","msb_bits[7,9]",0,2,SX_NONE),
};
const sx_layout sxarwire_sco_zero_repeat9_bit7={UINT32_C(0x608d0128),"sco_zero_repeat9_bit7",sxarwire_sco_zero_repeat9_bit7_fields,SX_COUNT(sxarwire_sco_zero_repeat9_bit7_fields),SX_LE};
static const sx_layout *const sxarwire_set_sco_block_count[]={&sxarwire_sco_block_count_bit0,&sxarwire_sco_block_count_bit1,&sxarwire_sco_block_count_bit2,&sxarwire_sco_block_count_bit3,&sxarwire_sco_block_count_bit4,&sxarwire_sco_block_count_bit5,&sxarwire_sco_block_count_bit6,&sxarwire_sco_block_count_bit7};
static const sx_layout *const sxarwire_set_sco_pretree_count[]={&sxarwire_sco_pretree_count_bit0,&sxarwire_sco_pretree_count_bit1,&sxarwire_sco_pretree_count_bit2,&sxarwire_sco_pretree_count_bit3,&sxarwire_sco_pretree_count_bit4,&sxarwire_sco_pretree_count_bit5,&sxarwire_sco_pretree_count_bit6,&sxarwire_sco_pretree_count_bit7};
static const sx_layout *const sxarwire_set_sco_pretree_single[]={&sxarwire_sco_pretree_single_bit0,&sxarwire_sco_pretree_single_bit1,&sxarwire_sco_pretree_single_bit2,&sxarwire_sco_pretree_single_bit3,&sxarwire_sco_pretree_single_bit4,&sxarwire_sco_pretree_single_bit5,&sxarwire_sco_pretree_single_bit6,&sxarwire_sco_pretree_single_bit7};
static const sx_layout *const sxarwire_set_sco_code_length[]={&sxarwire_sco_code_length_bit0,&sxarwire_sco_code_length_bit1,&sxarwire_sco_code_length_bit2,&sxarwire_sco_code_length_bit3,&sxarwire_sco_code_length_bit4,&sxarwire_sco_code_length_bit5,&sxarwire_sco_code_length_bit6,&sxarwire_sco_code_length_bit7};
static const sx_layout *const sxarwire_set_sco_code_length_more[]={&sxarwire_sco_code_length_more_bit0,&sxarwire_sco_code_length_more_bit1,&sxarwire_sco_code_length_more_bit2,&sxarwire_sco_code_length_more_bit3,&sxarwire_sco_code_length_more_bit4,&sxarwire_sco_code_length_more_bit5,&sxarwire_sco_code_length_more_bit6,&sxarwire_sco_code_length_more_bit7};
static const sx_layout *const sxarwire_set_sco_pretree_zeros[]={&sxarwire_sco_pretree_zeros_bit0,&sxarwire_sco_pretree_zeros_bit1,&sxarwire_sco_pretree_zeros_bit2,&sxarwire_sco_pretree_zeros_bit3,&sxarwire_sco_pretree_zeros_bit4,&sxarwire_sco_pretree_zeros_bit5,&sxarwire_sco_pretree_zeros_bit6,&sxarwire_sco_pretree_zeros_bit7};
static const sx_layout *const sxarwire_set_sco_literal_count[]={&sxarwire_sco_literal_count_bit0,&sxarwire_sco_literal_count_bit1,&sxarwire_sco_literal_count_bit2,&sxarwire_sco_literal_count_bit3,&sxarwire_sco_literal_count_bit4,&sxarwire_sco_literal_count_bit5,&sxarwire_sco_literal_count_bit6,&sxarwire_sco_literal_count_bit7};
static const sx_layout *const sxarwire_set_sco_literal_single[]={&sxarwire_sco_literal_single_bit0,&sxarwire_sco_literal_single_bit1,&sxarwire_sco_literal_single_bit2,&sxarwire_sco_literal_single_bit3,&sxarwire_sco_literal_single_bit4,&sxarwire_sco_literal_single_bit5,&sxarwire_sco_literal_single_bit6,&sxarwire_sco_literal_single_bit7};
static const sx_layout *const sxarwire_set_sco_position_count[]={&sxarwire_sco_position_count_bit0,&sxarwire_sco_position_count_bit1,&sxarwire_sco_position_count_bit2,&sxarwire_sco_position_count_bit3,&sxarwire_sco_position_count_bit4,&sxarwire_sco_position_count_bit5,&sxarwire_sco_position_count_bit6,&sxarwire_sco_position_count_bit7};
static const sx_layout *const sxarwire_set_sco_position_single[]={&sxarwire_sco_position_single_bit0,&sxarwire_sco_position_single_bit1,&sxarwire_sco_position_single_bit2,&sxarwire_sco_position_single_bit3,&sxarwire_sco_position_single_bit4,&sxarwire_sco_position_single_bit5,&sxarwire_sco_position_single_bit6,&sxarwire_sco_position_single_bit7};
static const sx_layout *const sxarwire_set_sco_zero_repeat4[]={&sxarwire_sco_zero_repeat4_bit0,&sxarwire_sco_zero_repeat4_bit1,&sxarwire_sco_zero_repeat4_bit2,&sxarwire_sco_zero_repeat4_bit3,&sxarwire_sco_zero_repeat4_bit4,&sxarwire_sco_zero_repeat4_bit5,&sxarwire_sco_zero_repeat4_bit6,&sxarwire_sco_zero_repeat4_bit7};
static const sx_layout *const sxarwire_set_sco_zero_repeat9[]={&sxarwire_sco_zero_repeat9_bit0,&sxarwire_sco_zero_repeat9_bit1,&sxarwire_sco_zero_repeat9_bit2,&sxarwire_sco_zero_repeat9_bit3,&sxarwire_sco_zero_repeat9_bit4,&sxarwire_sco_zero_repeat9_bit5,&sxarwire_sco_zero_repeat9_bit6,&sxarwire_sco_zero_repeat9_bit7};
#define SXARWIRE_LIMIT 20000U
static bool sxarwire_sco_pt(sxarwire_bits*b,sxarwire_huff*h,bool position){uint64_t n,v;uint8_t lengths[19]={0};unsigned size=position?14:19,width=position?4:5;
 if(!sxarwire_field(b,position?sxarwire_set_sco_position_count:sxarwire_set_sco_pretree_count,width,&n))return false;
 if(!n){if(!sxarwire_field(b,position?sxarwire_set_sco_position_single:sxarwire_set_sco_pretree_single,width,&v)||v>=size)return false;xx_rt_memset(h,0,sizeof(*h));h->single=true;h->one=(unsigned)v;return true;}
 if(n>size)return false;for(unsigned i=0;i<n;){if(!sxarwire_field(b,sxarwire_set_sco_code_length,3,&v))return false;unsigned len=(unsigned)v;if(len==7){do{if(!sxarwire_field(b,sxarwire_set_sco_code_length_more,1,&v))return false;if(v&&++len>16)return false;}while(v);}lengths[i++]=(uint8_t)len;
  if(!position&&i==3){if(!sxarwire_field(b,sxarwire_set_sco_pretree_zeros,2,&v)||v>n-i)return false;i+=(unsigned)v;}}
 return sxarwire_hbuild(h,lengths,(unsigned)n,16);
}
static bool sxarwire_sco_literal(sxarwire_bits*b,const sxarwire_huff*pre,sxarwire_huff*h){uint64_t n,v;uint8_t lengths[510]={0};if(!sxarwire_field(b,sxarwire_set_sco_literal_count,9,&n))return false;if(!n){if(!sxarwire_field(b,sxarwire_set_sco_literal_single,9,&v)||v>=510)return false;xx_rt_memset(h,0,sizeof(*h));h->single=true;h->one=(unsigned)v;return true;}if(n>510)return false;
 for(unsigned i=0;i<n;){unsigned sym;if(!sxarwire_table_code(b,pre,&sym))return false;if(sym>2){if(sym>18)return false;lengths[i++]=(uint8_t)(sym-2);}else if(!sym)i++;else{unsigned bits=sym==1?4:9;if(!sxarwire_field(b,bits==4?sxarwire_set_sco_zero_repeat4:sxarwire_set_sco_zero_repeat9,bits,&v))return false;v+=bits==4?3:20;if(v>n-i)return false;i+=(unsigned)v;}}
 return sxarwire_hbuild(h,lengths,(unsigned)n,16);
}
static bool sxarwire_sco(sx_context*c){if(!sxarwire_put(c,&sxarwire_sco_signature,0))return false;sxarwire_bits b={c,16,false,0,0,false};unsigned work=0;while(c->count<SXARWIRE_LIMIT){uint64_t n,x;if(!sxarwire_field(&b,sxarwire_set_sco_block_count,16,&n))return false;if(!n)return true;sxarwire_huff pre,lit,pos;if(!sxarwire_sco_pt(&b,&pre,false)||!sxarwire_sco_literal(&b,&pre,&lit)||!sxarwire_sco_pt(&b,&pos,true))return false;
  for(unsigned i=0;i<n;i++){unsigned sym;if(++work>2000000U)return true;if(!sxarwire_hread(&b,&lit,&sym))return false;if(sym>=256){if(sym>=510||!sxarwire_hread(&b,&pos,&sym)||sym>=14)return false;if(sym>1&&!sxarwire_take(&b,sym-1,&x))return false;}}
 }return true;}
bool sx_sco_build(sx_context*c)
{
 return sxarwire_sco(c);
}
