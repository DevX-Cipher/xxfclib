/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Raw DEFLATE compressed data data structures, moved out of the archivewire schema family. */
#include "../../xx_format_schema_archivewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarwire_deflate_block_bit0_fields[]={
 SX_FIELD("is_final","lsb_bits[0,1]",0,1,SX_FLAGS),
 SX_FIELD("block_type","lsb_bits[1,2]",0,1,SX_ID),
};
const sx_layout sxarwire_deflate_block_bit0={UINT32_C(0x608d0195),"deflate_block_bit0",sxarwire_deflate_block_bit0_fields,SX_COUNT(sxarwire_deflate_block_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_block_bit1_fields[]={
 SX_FIELD("is_final","lsb_bits[1,1]",0,1,SX_FLAGS),
 SX_FIELD("block_type","lsb_bits[2,2]",0,1,SX_ID),
};
const sx_layout sxarwire_deflate_block_bit1={UINT32_C(0x608d0196),"deflate_block_bit1",sxarwire_deflate_block_bit1_fields,SX_COUNT(sxarwire_deflate_block_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_block_bit2_fields[]={
 SX_FIELD("is_final","lsb_bits[2,1]",0,1,SX_FLAGS),
 SX_FIELD("block_type","lsb_bits[3,2]",0,1,SX_ID),
};
const sx_layout sxarwire_deflate_block_bit2={UINT32_C(0x608d0197),"deflate_block_bit2",sxarwire_deflate_block_bit2_fields,SX_COUNT(sxarwire_deflate_block_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_block_bit3_fields[]={
 SX_FIELD("is_final","lsb_bits[3,1]",0,1,SX_FLAGS),
 SX_FIELD("block_type","lsb_bits[4,2]",0,1,SX_ID),
};
const sx_layout sxarwire_deflate_block_bit3={UINT32_C(0x608d0198),"deflate_block_bit3",sxarwire_deflate_block_bit3_fields,SX_COUNT(sxarwire_deflate_block_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_block_bit4_fields[]={
 SX_FIELD("is_final","lsb_bits[4,1]",0,1,SX_FLAGS),
 SX_FIELD("block_type","lsb_bits[5,2]",0,1,SX_ID),
};
const sx_layout sxarwire_deflate_block_bit4={UINT32_C(0x608d0199),"deflate_block_bit4",sxarwire_deflate_block_bit4_fields,SX_COUNT(sxarwire_deflate_block_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_block_bit5_fields[]={
 SX_FIELD("is_final","lsb_bits[5,1]",0,1,SX_FLAGS),
 SX_FIELD("block_type","lsb_bits[6,2]",0,1,SX_ID),
};
const sx_layout sxarwire_deflate_block_bit5={UINT32_C(0x608d019a),"deflate_block_bit5",sxarwire_deflate_block_bit5_fields,SX_COUNT(sxarwire_deflate_block_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_block_bit6_fields[]={
 SX_FIELD("is_final","lsb_bits[6,1]",0,1,SX_FLAGS),
 SX_FIELD("block_type","lsb_bits[7,2]",0,2,SX_ID),
};
const sx_layout sxarwire_deflate_block_bit6={UINT32_C(0x608d019b),"deflate_block_bit6",sxarwire_deflate_block_bit6_fields,SX_COUNT(sxarwire_deflate_block_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_block_bit7_fields[]={
 SX_FIELD("is_final","lsb_bits[7,1]",0,1,SX_FLAGS),
 SX_FIELD("block_type","lsb_bits[0,2]",1,1,SX_ID),
};
const sx_layout sxarwire_deflate_block_bit7={UINT32_C(0x608d019c),"deflate_block_bit7",sxarwire_deflate_block_bit7_fields,SX_COUNT(sxarwire_deflate_block_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_stored_lengths_fields[]={
 SX_FIELD("length","uint16",0,2,SX_SIZE),
 SX_FIELD("length_complement","uint16",2,2,SX_NONE),
};
const sx_layout sxarwire_deflate_stored_lengths={UINT32_C(0x608d019d),"deflate_stored_lengths",sxarwire_deflate_stored_lengths_fields,SX_COUNT(sxarwire_deflate_stored_lengths_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hlit_bit0_fields[]={
 SX_FIELD("literal_length_codes_minus_257","lsb_bits[0,5]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_hlit_bit0={UINT32_C(0x608d019e),"deflate_hlit_bit0",sxarwire_deflate_hlit_bit0_fields,SX_COUNT(sxarwire_deflate_hlit_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hlit_bit1_fields[]={
 SX_FIELD("literal_length_codes_minus_257","lsb_bits[1,5]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_hlit_bit1={UINT32_C(0x608d019f),"deflate_hlit_bit1",sxarwire_deflate_hlit_bit1_fields,SX_COUNT(sxarwire_deflate_hlit_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hlit_bit2_fields[]={
 SX_FIELD("literal_length_codes_minus_257","lsb_bits[2,5]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_hlit_bit2={UINT32_C(0x608d01a0),"deflate_hlit_bit2",sxarwire_deflate_hlit_bit2_fields,SX_COUNT(sxarwire_deflate_hlit_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hlit_bit3_fields[]={
 SX_FIELD("literal_length_codes_minus_257","lsb_bits[3,5]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_hlit_bit3={UINT32_C(0x608d01a1),"deflate_hlit_bit3",sxarwire_deflate_hlit_bit3_fields,SX_COUNT(sxarwire_deflate_hlit_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hlit_bit4_fields[]={
 SX_FIELD("literal_length_codes_minus_257","lsb_bits[4,5]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_hlit_bit4={UINT32_C(0x608d01a2),"deflate_hlit_bit4",sxarwire_deflate_hlit_bit4_fields,SX_COUNT(sxarwire_deflate_hlit_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hlit_bit5_fields[]={
 SX_FIELD("literal_length_codes_minus_257","lsb_bits[5,5]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_hlit_bit5={UINT32_C(0x608d01a3),"deflate_hlit_bit5",sxarwire_deflate_hlit_bit5_fields,SX_COUNT(sxarwire_deflate_hlit_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hlit_bit6_fields[]={
 SX_FIELD("literal_length_codes_minus_257","lsb_bits[6,5]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_hlit_bit6={UINT32_C(0x608d01a4),"deflate_hlit_bit6",sxarwire_deflate_hlit_bit6_fields,SX_COUNT(sxarwire_deflate_hlit_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hlit_bit7_fields[]={
 SX_FIELD("literal_length_codes_minus_257","lsb_bits[7,5]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_hlit_bit7={UINT32_C(0x608d01a5),"deflate_hlit_bit7",sxarwire_deflate_hlit_bit7_fields,SX_COUNT(sxarwire_deflate_hlit_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hdist_bit0_fields[]={
 SX_FIELD("distance_codes_minus_one","lsb_bits[0,5]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_hdist_bit0={UINT32_C(0x608d01a6),"deflate_hdist_bit0",sxarwire_deflate_hdist_bit0_fields,SX_COUNT(sxarwire_deflate_hdist_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hdist_bit1_fields[]={
 SX_FIELD("distance_codes_minus_one","lsb_bits[1,5]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_hdist_bit1={UINT32_C(0x608d01a7),"deflate_hdist_bit1",sxarwire_deflate_hdist_bit1_fields,SX_COUNT(sxarwire_deflate_hdist_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hdist_bit2_fields[]={
 SX_FIELD("distance_codes_minus_one","lsb_bits[2,5]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_hdist_bit2={UINT32_C(0x608d01a8),"deflate_hdist_bit2",sxarwire_deflate_hdist_bit2_fields,SX_COUNT(sxarwire_deflate_hdist_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hdist_bit3_fields[]={
 SX_FIELD("distance_codes_minus_one","lsb_bits[3,5]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_hdist_bit3={UINT32_C(0x608d01a9),"deflate_hdist_bit3",sxarwire_deflate_hdist_bit3_fields,SX_COUNT(sxarwire_deflate_hdist_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hdist_bit4_fields[]={
 SX_FIELD("distance_codes_minus_one","lsb_bits[4,5]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_hdist_bit4={UINT32_C(0x608d01aa),"deflate_hdist_bit4",sxarwire_deflate_hdist_bit4_fields,SX_COUNT(sxarwire_deflate_hdist_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hdist_bit5_fields[]={
 SX_FIELD("distance_codes_minus_one","lsb_bits[5,5]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_hdist_bit5={UINT32_C(0x608d01ab),"deflate_hdist_bit5",sxarwire_deflate_hdist_bit5_fields,SX_COUNT(sxarwire_deflate_hdist_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hdist_bit6_fields[]={
 SX_FIELD("distance_codes_minus_one","lsb_bits[6,5]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_hdist_bit6={UINT32_C(0x608d01ac),"deflate_hdist_bit6",sxarwire_deflate_hdist_bit6_fields,SX_COUNT(sxarwire_deflate_hdist_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hdist_bit7_fields[]={
 SX_FIELD("distance_codes_minus_one","lsb_bits[7,5]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_hdist_bit7={UINT32_C(0x608d01ad),"deflate_hdist_bit7",sxarwire_deflate_hdist_bit7_fields,SX_COUNT(sxarwire_deflate_hdist_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hclen_bit0_fields[]={
 SX_FIELD("code_length_codes_minus_four","lsb_bits[0,4]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_hclen_bit0={UINT32_C(0x608d01ae),"deflate_hclen_bit0",sxarwire_deflate_hclen_bit0_fields,SX_COUNT(sxarwire_deflate_hclen_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hclen_bit1_fields[]={
 SX_FIELD("code_length_codes_minus_four","lsb_bits[1,4]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_hclen_bit1={UINT32_C(0x608d01af),"deflate_hclen_bit1",sxarwire_deflate_hclen_bit1_fields,SX_COUNT(sxarwire_deflate_hclen_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hclen_bit2_fields[]={
 SX_FIELD("code_length_codes_minus_four","lsb_bits[2,4]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_hclen_bit2={UINT32_C(0x608d01b0),"deflate_hclen_bit2",sxarwire_deflate_hclen_bit2_fields,SX_COUNT(sxarwire_deflate_hclen_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hclen_bit3_fields[]={
 SX_FIELD("code_length_codes_minus_four","lsb_bits[3,4]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_hclen_bit3={UINT32_C(0x608d01b1),"deflate_hclen_bit3",sxarwire_deflate_hclen_bit3_fields,SX_COUNT(sxarwire_deflate_hclen_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hclen_bit4_fields[]={
 SX_FIELD("code_length_codes_minus_four","lsb_bits[4,4]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_hclen_bit4={UINT32_C(0x608d01b2),"deflate_hclen_bit4",sxarwire_deflate_hclen_bit4_fields,SX_COUNT(sxarwire_deflate_hclen_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hclen_bit5_fields[]={
 SX_FIELD("code_length_codes_minus_four","lsb_bits[5,4]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_hclen_bit5={UINT32_C(0x608d01b3),"deflate_hclen_bit5",sxarwire_deflate_hclen_bit5_fields,SX_COUNT(sxarwire_deflate_hclen_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hclen_bit6_fields[]={
 SX_FIELD("code_length_codes_minus_four","lsb_bits[6,4]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_hclen_bit6={UINT32_C(0x608d01b4),"deflate_hclen_bit6",sxarwire_deflate_hclen_bit6_fields,SX_COUNT(sxarwire_deflate_hclen_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_hclen_bit7_fields[]={
 SX_FIELD("code_length_codes_minus_four","lsb_bits[7,4]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_hclen_bit7={UINT32_C(0x608d01b5),"deflate_hclen_bit7",sxarwire_deflate_hclen_bit7_fields,SX_COUNT(sxarwire_deflate_hclen_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_code_length_bit0_fields[]={
 SX_FIELD("code_length","lsb_bits[0,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_code_length_bit0={UINT32_C(0x608d01b6),"deflate_code_length_bit0",sxarwire_deflate_code_length_bit0_fields,SX_COUNT(sxarwire_deflate_code_length_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_code_length_bit1_fields[]={
 SX_FIELD("code_length","lsb_bits[1,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_code_length_bit1={UINT32_C(0x608d01b7),"deflate_code_length_bit1",sxarwire_deflate_code_length_bit1_fields,SX_COUNT(sxarwire_deflate_code_length_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_code_length_bit2_fields[]={
 SX_FIELD("code_length","lsb_bits[2,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_code_length_bit2={UINT32_C(0x608d01b8),"deflate_code_length_bit2",sxarwire_deflate_code_length_bit2_fields,SX_COUNT(sxarwire_deflate_code_length_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_code_length_bit3_fields[]={
 SX_FIELD("code_length","lsb_bits[3,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_code_length_bit3={UINT32_C(0x608d01b9),"deflate_code_length_bit3",sxarwire_deflate_code_length_bit3_fields,SX_COUNT(sxarwire_deflate_code_length_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_code_length_bit4_fields[]={
 SX_FIELD("code_length","lsb_bits[4,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_code_length_bit4={UINT32_C(0x608d01ba),"deflate_code_length_bit4",sxarwire_deflate_code_length_bit4_fields,SX_COUNT(sxarwire_deflate_code_length_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_code_length_bit5_fields[]={
 SX_FIELD("code_length","lsb_bits[5,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_code_length_bit5={UINT32_C(0x608d01bb),"deflate_code_length_bit5",sxarwire_deflate_code_length_bit5_fields,SX_COUNT(sxarwire_deflate_code_length_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_code_length_bit6_fields[]={
 SX_FIELD("code_length","lsb_bits[6,3]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_code_length_bit6={UINT32_C(0x608d01bc),"deflate_code_length_bit6",sxarwire_deflate_code_length_bit6_fields,SX_COUNT(sxarwire_deflate_code_length_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_code_length_bit7_fields[]={
 SX_FIELD("code_length","lsb_bits[7,3]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_code_length_bit7={UINT32_C(0x608d01bd),"deflate_code_length_bit7",sxarwire_deflate_code_length_bit7_fields,SX_COUNT(sxarwire_deflate_code_length_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat2_bit0_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[0,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat2_bit0={UINT32_C(0x608d01be),"deflate_repeat2_bit0",sxarwire_deflate_repeat2_bit0_fields,SX_COUNT(sxarwire_deflate_repeat2_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat2_bit1_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[1,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat2_bit1={UINT32_C(0x608d01bf),"deflate_repeat2_bit1",sxarwire_deflate_repeat2_bit1_fields,SX_COUNT(sxarwire_deflate_repeat2_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat2_bit2_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[2,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat2_bit2={UINT32_C(0x608d01c0),"deflate_repeat2_bit2",sxarwire_deflate_repeat2_bit2_fields,SX_COUNT(sxarwire_deflate_repeat2_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat2_bit3_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[3,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat2_bit3={UINT32_C(0x608d01c1),"deflate_repeat2_bit3",sxarwire_deflate_repeat2_bit3_fields,SX_COUNT(sxarwire_deflate_repeat2_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat2_bit4_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[4,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat2_bit4={UINT32_C(0x608d01c2),"deflate_repeat2_bit4",sxarwire_deflate_repeat2_bit4_fields,SX_COUNT(sxarwire_deflate_repeat2_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat2_bit5_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[5,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat2_bit5={UINT32_C(0x608d01c3),"deflate_repeat2_bit5",sxarwire_deflate_repeat2_bit5_fields,SX_COUNT(sxarwire_deflate_repeat2_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat2_bit6_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[6,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat2_bit6={UINT32_C(0x608d01c4),"deflate_repeat2_bit6",sxarwire_deflate_repeat2_bit6_fields,SX_COUNT(sxarwire_deflate_repeat2_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat2_bit7_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[7,2]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat2_bit7={UINT32_C(0x608d01c5),"deflate_repeat2_bit7",sxarwire_deflate_repeat2_bit7_fields,SX_COUNT(sxarwire_deflate_repeat2_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat3_bit0_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[0,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat3_bit0={UINT32_C(0x608d01c6),"deflate_repeat3_bit0",sxarwire_deflate_repeat3_bit0_fields,SX_COUNT(sxarwire_deflate_repeat3_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat3_bit1_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[1,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat3_bit1={UINT32_C(0x608d01c7),"deflate_repeat3_bit1",sxarwire_deflate_repeat3_bit1_fields,SX_COUNT(sxarwire_deflate_repeat3_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat3_bit2_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[2,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat3_bit2={UINT32_C(0x608d01c8),"deflate_repeat3_bit2",sxarwire_deflate_repeat3_bit2_fields,SX_COUNT(sxarwire_deflate_repeat3_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat3_bit3_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[3,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat3_bit3={UINT32_C(0x608d01c9),"deflate_repeat3_bit3",sxarwire_deflate_repeat3_bit3_fields,SX_COUNT(sxarwire_deflate_repeat3_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat3_bit4_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[4,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat3_bit4={UINT32_C(0x608d01ca),"deflate_repeat3_bit4",sxarwire_deflate_repeat3_bit4_fields,SX_COUNT(sxarwire_deflate_repeat3_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat3_bit5_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[5,3]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat3_bit5={UINT32_C(0x608d01cb),"deflate_repeat3_bit5",sxarwire_deflate_repeat3_bit5_fields,SX_COUNT(sxarwire_deflate_repeat3_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat3_bit6_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[6,3]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat3_bit6={UINT32_C(0x608d01cc),"deflate_repeat3_bit6",sxarwire_deflate_repeat3_bit6_fields,SX_COUNT(sxarwire_deflate_repeat3_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat3_bit7_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[7,3]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat3_bit7={UINT32_C(0x608d01cd),"deflate_repeat3_bit7",sxarwire_deflate_repeat3_bit7_fields,SX_COUNT(sxarwire_deflate_repeat3_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat7_bit0_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[0,7]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat7_bit0={UINT32_C(0x608d01ce),"deflate_repeat7_bit0",sxarwire_deflate_repeat7_bit0_fields,SX_COUNT(sxarwire_deflate_repeat7_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat7_bit1_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[1,7]",0,1,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat7_bit1={UINT32_C(0x608d01cf),"deflate_repeat7_bit1",sxarwire_deflate_repeat7_bit1_fields,SX_COUNT(sxarwire_deflate_repeat7_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat7_bit2_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[2,7]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat7_bit2={UINT32_C(0x608d01d0),"deflate_repeat7_bit2",sxarwire_deflate_repeat7_bit2_fields,SX_COUNT(sxarwire_deflate_repeat7_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat7_bit3_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[3,7]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat7_bit3={UINT32_C(0x608d01d1),"deflate_repeat7_bit3",sxarwire_deflate_repeat7_bit3_fields,SX_COUNT(sxarwire_deflate_repeat7_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat7_bit4_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[4,7]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat7_bit4={UINT32_C(0x608d01d2),"deflate_repeat7_bit4",sxarwire_deflate_repeat7_bit4_fields,SX_COUNT(sxarwire_deflate_repeat7_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat7_bit5_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[5,7]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat7_bit5={UINT32_C(0x608d01d3),"deflate_repeat7_bit5",sxarwire_deflate_repeat7_bit5_fields,SX_COUNT(sxarwire_deflate_repeat7_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat7_bit6_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[6,7]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat7_bit6={UINT32_C(0x608d01d4),"deflate_repeat7_bit6",sxarwire_deflate_repeat7_bit6_fields,SX_COUNT(sxarwire_deflate_repeat7_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_repeat7_bit7_fields[]={
 SX_FIELD("repeat_extra","lsb_bits[7,7]",0,2,SX_NONE),
};
const sx_layout sxarwire_deflate_repeat7_bit7={UINT32_C(0x608d01d5),"deflate_repeat7_bit7",sxarwire_deflate_repeat7_bit7_fields,SX_COUNT(sxarwire_deflate_repeat7_bit7_fields),SX_LE};
static const sx_layout *const sxarwire_set_deflate_block[]={&sxarwire_deflate_block_bit0,&sxarwire_deflate_block_bit1,&sxarwire_deflate_block_bit2,&sxarwire_deflate_block_bit3,&sxarwire_deflate_block_bit4,&sxarwire_deflate_block_bit5,&sxarwire_deflate_block_bit6,&sxarwire_deflate_block_bit7};
static const sx_layout *const sxarwire_set_deflate_hlit[]={&sxarwire_deflate_hlit_bit0,&sxarwire_deflate_hlit_bit1,&sxarwire_deflate_hlit_bit2,&sxarwire_deflate_hlit_bit3,&sxarwire_deflate_hlit_bit4,&sxarwire_deflate_hlit_bit5,&sxarwire_deflate_hlit_bit6,&sxarwire_deflate_hlit_bit7};
static const sx_layout *const sxarwire_set_deflate_hdist[]={&sxarwire_deflate_hdist_bit0,&sxarwire_deflate_hdist_bit1,&sxarwire_deflate_hdist_bit2,&sxarwire_deflate_hdist_bit3,&sxarwire_deflate_hdist_bit4,&sxarwire_deflate_hdist_bit5,&sxarwire_deflate_hdist_bit6,&sxarwire_deflate_hdist_bit7};
static const sx_layout *const sxarwire_set_deflate_hclen[]={&sxarwire_deflate_hclen_bit0,&sxarwire_deflate_hclen_bit1,&sxarwire_deflate_hclen_bit2,&sxarwire_deflate_hclen_bit3,&sxarwire_deflate_hclen_bit4,&sxarwire_deflate_hclen_bit5,&sxarwire_deflate_hclen_bit6,&sxarwire_deflate_hclen_bit7};
static const sx_layout *const sxarwire_set_deflate_code_length[]={&sxarwire_deflate_code_length_bit0,&sxarwire_deflate_code_length_bit1,&sxarwire_deflate_code_length_bit2,&sxarwire_deflate_code_length_bit3,&sxarwire_deflate_code_length_bit4,&sxarwire_deflate_code_length_bit5,&sxarwire_deflate_code_length_bit6,&sxarwire_deflate_code_length_bit7};
static const sx_layout *const sxarwire_set_deflate_repeat2[]={&sxarwire_deflate_repeat2_bit0,&sxarwire_deflate_repeat2_bit1,&sxarwire_deflate_repeat2_bit2,&sxarwire_deflate_repeat2_bit3,&sxarwire_deflate_repeat2_bit4,&sxarwire_deflate_repeat2_bit5,&sxarwire_deflate_repeat2_bit6,&sxarwire_deflate_repeat2_bit7};
static const sx_layout *const sxarwire_set_deflate_repeat3[]={&sxarwire_deflate_repeat3_bit0,&sxarwire_deflate_repeat3_bit1,&sxarwire_deflate_repeat3_bit2,&sxarwire_deflate_repeat3_bit3,&sxarwire_deflate_repeat3_bit4,&sxarwire_deflate_repeat3_bit5,&sxarwire_deflate_repeat3_bit6,&sxarwire_deflate_repeat3_bit7};
static const sx_layout *const sxarwire_set_deflate_repeat7[]={&sxarwire_deflate_repeat7_bit0,&sxarwire_deflate_repeat7_bit1,&sxarwire_deflate_repeat7_bit2,&sxarwire_deflate_repeat7_bit3,&sxarwire_deflate_repeat7_bit4,&sxarwire_deflate_repeat7_bit5,&sxarwire_deflate_repeat7_bit6,&sxarwire_deflate_repeat7_bit7};
#define SXARWIRE_LIMIT 20000U
static bool sxarwire_deflate_dynamic(sxarwire_bits*b,sxarwire_huff*lit,sxarwire_huff*dist){
 static const unsigned order[19]={16,17,18,0,8,7,9,6,10,5,11,4,12,3,13,2,14,1,15};uint64_t a,z,k,v;uint8_t cl[19]={0},lengths[318]={0};sxarwire_huff ch;
 if(!sxarwire_field(b,sxarwire_set_deflate_hlit,5,&a)||!sxarwire_field(b,sxarwire_set_deflate_hdist,5,&z)||!sxarwire_field(b,sxarwire_set_deflate_hclen,4,&k))return false;a+=257;z++;k+=4;if(a>286||z>30)return false;
 for(unsigned i=0;i<k;i++){if(!sxarwire_field(b,sxarwire_set_deflate_code_length,3,&v))return false;cl[order[i]]=(uint8_t)v;}
 if(!sxarwire_hbuild(&ch,cl,19,7))return false;
 for(unsigned i=0;i<a+z;){unsigned sym,run;if(!sxarwire_table_code(b,&ch,&sym))return false;if(sym<16){lengths[i++]=(uint8_t)sym;continue;}
  if(sym==16){if(!i||!sxarwire_field(b,sxarwire_set_deflate_repeat2,2,&v))return false;run=3+(unsigned)v;v=lengths[i-1];}
  else if(sym==17){if(!sxarwire_field(b,sxarwire_set_deflate_repeat3,3,&v))return false;run=3+(unsigned)v;v=0;}
  else if(sym==18){if(!sxarwire_field(b,sxarwire_set_deflate_repeat7,7,&v))return false;run=11+(unsigned)v;v=0;}
  else return false;if(run>a+z-i)return false;while(run--)lengths[i++]=(uint8_t)v;
 }
 if(!lengths[256]||!sxarwire_hbuild(lit,lengths,(unsigned)a,15))return false;
 bool any=false;for(unsigned i=0;i<z;i++)if(lengths[a+i])any=true;
 if(any)return sxarwire_hbuild(dist,lengths+a,(unsigned)z,15);xx_rt_memset(dist,0,sizeof(*dist));return true;
}
static bool sxarwire_deflate(sx_context*c){
 static const unsigned lex[29]={0,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,0};
 sxarwire_bits b={c,0,true,0,0,false};unsigned work=0;
 while(c->count<SXARWIRE_LIMIT&&work<2000000U){uint64_t start=b.bit,last,type,x;if(!sxarwire_take(&b,1,&last)||!sxarwire_take(&b,2,&type)||!sxarwire_put(c,sxarwire_set_deflate_block[start&7],start/8))return false;
  if(type==0){b.bit=(b.bit+7)&~UINT64_C(7);uint8_t h[4];if(!sxarwire_read(c,b.bit/8,h,4)||!sxarwire_put(c,&sxarwire_deflate_stored_lengths,b.bit/8))return false;unsigned n=(unsigned)sxarwire_num(h,2,false),inv=(unsigned)sxarwire_num(h+2,2,false);if((n^inv)!=65535||!sxarwire_span(c,b.bit/8+4,n))return false;b.bit+=32+(uint64_t)n*8;}
  else if(type==1||type==2){sxarwire_huff lit,dist;if(type==1){uint8_t lengths[288],d[32];for(unsigned i=0;i<288;i++)lengths[i]=(uint8_t)(i<144?8:i<256?9:i<280?7:8);xx_rt_memset(d,5,sizeof(d));if(!sxarwire_hbuild(&lit,lengths,288,15)||!sxarwire_hbuild(&dist,d,32,15))return false;}else if(!sxarwire_deflate_dynamic(&b,&lit,&dist))return false;
   for(;;){unsigned sym;if(++work>2000000U)return true;if(!sxarwire_hread(&b,&lit,&sym))return false;if(sym<256)continue;if(sym==256)break;if(sym>285)return false;unsigned extra=lex[sym-257];if(extra&&!sxarwire_take(&b,extra,&x))return false;if(!sxarwire_hread(&b,&dist,&sym)||sym>29)return false;extra=sym<4?0:sym/2-1;if(extra&&!sxarwire_take(&b,extra,&x))return false;}
  }else return false;if(last)return true;
 }return true;
}
bool sx_raw_deflate_compressed_data_build(sx_context*c)
{
 return sxarwire_deflate(c);
}
