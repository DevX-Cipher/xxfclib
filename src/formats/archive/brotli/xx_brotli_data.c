/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Brotli stream data structures, moved out of the archivewire schema family. */
#include "../../xx_format_schema_archivewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarwire_brotli_window1_bit0_fields[]={
 SX_FIELD("window_bits_code","lsb_bits[0,1]",0,1,SX_NONE),
};
const sx_layout sxarwire_brotli_window1_bit0={UINT32_C(0x608d012b),"brotli_window1_bit0",sxarwire_brotli_window1_bit0_fields,SX_COUNT(sxarwire_brotli_window1_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_window4_bit0_fields[]={
 SX_FIELD("window_bits_code","lsb_bits[0,4]",0,1,SX_NONE),
};
const sx_layout sxarwire_brotli_window4_bit0={UINT32_C(0x608d012c),"brotli_window4_bit0",sxarwire_brotli_window4_bit0_fields,SX_COUNT(sxarwire_brotli_window4_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_window7_bit0_fields[]={
 SX_FIELD("window_bits_code","lsb_bits[0,7]",0,1,SX_NONE),
};
const sx_layout sxarwire_brotli_window7_bit0={UINT32_C(0x608d012d),"brotli_window7_bit0",sxarwire_brotli_window7_bit0_fields,SX_COUNT(sxarwire_brotli_window7_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_last_bit0_fields[]={
 SX_FIELD("is_last","lsb_bits[0,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_last_bit0={UINT32_C(0x608d012e),"brotli_last_bit0",sxarwire_brotli_last_bit0_fields,SX_COUNT(sxarwire_brotli_last_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_last_bit1_fields[]={
 SX_FIELD("is_last","lsb_bits[1,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_last_bit1={UINT32_C(0x608d012f),"brotli_last_bit1",sxarwire_brotli_last_bit1_fields,SX_COUNT(sxarwire_brotli_last_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_last_bit2_fields[]={
 SX_FIELD("is_last","lsb_bits[2,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_last_bit2={UINT32_C(0x608d0130),"brotli_last_bit2",sxarwire_brotli_last_bit2_fields,SX_COUNT(sxarwire_brotli_last_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_last_bit3_fields[]={
 SX_FIELD("is_last","lsb_bits[3,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_last_bit3={UINT32_C(0x608d0131),"brotli_last_bit3",sxarwire_brotli_last_bit3_fields,SX_COUNT(sxarwire_brotli_last_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_last_bit4_fields[]={
 SX_FIELD("is_last","lsb_bits[4,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_last_bit4={UINT32_C(0x608d0132),"brotli_last_bit4",sxarwire_brotli_last_bit4_fields,SX_COUNT(sxarwire_brotli_last_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_last_bit5_fields[]={
 SX_FIELD("is_last","lsb_bits[5,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_last_bit5={UINT32_C(0x608d0133),"brotli_last_bit5",sxarwire_brotli_last_bit5_fields,SX_COUNT(sxarwire_brotli_last_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_last_bit6_fields[]={
 SX_FIELD("is_last","lsb_bits[6,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_last_bit6={UINT32_C(0x608d0134),"brotli_last_bit6",sxarwire_brotli_last_bit6_fields,SX_COUNT(sxarwire_brotli_last_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_last_bit7_fields[]={
 SX_FIELD("is_last","lsb_bits[7,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_last_bit7={UINT32_C(0x608d0135),"brotli_last_bit7",sxarwire_brotli_last_bit7_fields,SX_COUNT(sxarwire_brotli_last_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_empty_bit0_fields[]={
 SX_FIELD("is_last_empty","lsb_bits[0,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_empty_bit0={UINT32_C(0x608d0136),"brotli_empty_bit0",sxarwire_brotli_empty_bit0_fields,SX_COUNT(sxarwire_brotli_empty_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_empty_bit1_fields[]={
 SX_FIELD("is_last_empty","lsb_bits[1,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_empty_bit1={UINT32_C(0x608d0137),"brotli_empty_bit1",sxarwire_brotli_empty_bit1_fields,SX_COUNT(sxarwire_brotli_empty_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_empty_bit2_fields[]={
 SX_FIELD("is_last_empty","lsb_bits[2,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_empty_bit2={UINT32_C(0x608d0138),"brotli_empty_bit2",sxarwire_brotli_empty_bit2_fields,SX_COUNT(sxarwire_brotli_empty_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_empty_bit3_fields[]={
 SX_FIELD("is_last_empty","lsb_bits[3,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_empty_bit3={UINT32_C(0x608d0139),"brotli_empty_bit3",sxarwire_brotli_empty_bit3_fields,SX_COUNT(sxarwire_brotli_empty_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_empty_bit4_fields[]={
 SX_FIELD("is_last_empty","lsb_bits[4,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_empty_bit4={UINT32_C(0x608d013a),"brotli_empty_bit4",sxarwire_brotli_empty_bit4_fields,SX_COUNT(sxarwire_brotli_empty_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_empty_bit5_fields[]={
 SX_FIELD("is_last_empty","lsb_bits[5,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_empty_bit5={UINT32_C(0x608d013b),"brotli_empty_bit5",sxarwire_brotli_empty_bit5_fields,SX_COUNT(sxarwire_brotli_empty_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_empty_bit6_fields[]={
 SX_FIELD("is_last_empty","lsb_bits[6,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_empty_bit6={UINT32_C(0x608d013c),"brotli_empty_bit6",sxarwire_brotli_empty_bit6_fields,SX_COUNT(sxarwire_brotli_empty_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_empty_bit7_fields[]={
 SX_FIELD("is_last_empty","lsb_bits[7,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_empty_bit7={UINT32_C(0x608d013d),"brotli_empty_bit7",sxarwire_brotli_empty_bit7_fields,SX_COUNT(sxarwire_brotli_empty_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_nibbles_bit0_fields[]={
 SX_FIELD("length_nibbles_code","lsb_bits[0,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_brotli_nibbles_bit0={UINT32_C(0x608d013e),"brotli_nibbles_bit0",sxarwire_brotli_nibbles_bit0_fields,SX_COUNT(sxarwire_brotli_nibbles_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_nibbles_bit1_fields[]={
 SX_FIELD("length_nibbles_code","lsb_bits[1,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_brotli_nibbles_bit1={UINT32_C(0x608d013f),"brotli_nibbles_bit1",sxarwire_brotli_nibbles_bit1_fields,SX_COUNT(sxarwire_brotli_nibbles_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_nibbles_bit2_fields[]={
 SX_FIELD("length_nibbles_code","lsb_bits[2,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_brotli_nibbles_bit2={UINT32_C(0x608d0140),"brotli_nibbles_bit2",sxarwire_brotli_nibbles_bit2_fields,SX_COUNT(sxarwire_brotli_nibbles_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_nibbles_bit3_fields[]={
 SX_FIELD("length_nibbles_code","lsb_bits[3,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_brotli_nibbles_bit3={UINT32_C(0x608d0141),"brotli_nibbles_bit3",sxarwire_brotli_nibbles_bit3_fields,SX_COUNT(sxarwire_brotli_nibbles_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_nibbles_bit4_fields[]={
 SX_FIELD("length_nibbles_code","lsb_bits[4,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_brotli_nibbles_bit4={UINT32_C(0x608d0142),"brotli_nibbles_bit4",sxarwire_brotli_nibbles_bit4_fields,SX_COUNT(sxarwire_brotli_nibbles_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_nibbles_bit5_fields[]={
 SX_FIELD("length_nibbles_code","lsb_bits[5,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_brotli_nibbles_bit5={UINT32_C(0x608d0143),"brotli_nibbles_bit5",sxarwire_brotli_nibbles_bit5_fields,SX_COUNT(sxarwire_brotli_nibbles_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_nibbles_bit6_fields[]={
 SX_FIELD("length_nibbles_code","lsb_bits[6,2]",0,1,SX_NONE),
};
const sx_layout sxarwire_brotli_nibbles_bit6={UINT32_C(0x608d0144),"brotli_nibbles_bit6",sxarwire_brotli_nibbles_bit6_fields,SX_COUNT(sxarwire_brotli_nibbles_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_nibbles_bit7_fields[]={
 SX_FIELD("length_nibbles_code","lsb_bits[7,2]",0,2,SX_NONE),
};
const sx_layout sxarwire_brotli_nibbles_bit7={UINT32_C(0x608d0145),"brotli_nibbles_bit7",sxarwire_brotli_nibbles_bit7_fields,SX_COUNT(sxarwire_brotli_nibbles_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_reserved_bit0_fields[]={
 SX_FIELD("reserved","lsb_bits[0,1]",0,1,SX_RESERVED),
};
const sx_layout sxarwire_brotli_reserved_bit0={UINT32_C(0x608d0146),"brotli_reserved_bit0",sxarwire_brotli_reserved_bit0_fields,SX_COUNT(sxarwire_brotli_reserved_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_reserved_bit1_fields[]={
 SX_FIELD("reserved","lsb_bits[1,1]",0,1,SX_RESERVED),
};
const sx_layout sxarwire_brotli_reserved_bit1={UINT32_C(0x608d0147),"brotli_reserved_bit1",sxarwire_brotli_reserved_bit1_fields,SX_COUNT(sxarwire_brotli_reserved_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_reserved_bit2_fields[]={
 SX_FIELD("reserved","lsb_bits[2,1]",0,1,SX_RESERVED),
};
const sx_layout sxarwire_brotli_reserved_bit2={UINT32_C(0x608d0148),"brotli_reserved_bit2",sxarwire_brotli_reserved_bit2_fields,SX_COUNT(sxarwire_brotli_reserved_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_reserved_bit3_fields[]={
 SX_FIELD("reserved","lsb_bits[3,1]",0,1,SX_RESERVED),
};
const sx_layout sxarwire_brotli_reserved_bit3={UINT32_C(0x608d0149),"brotli_reserved_bit3",sxarwire_brotli_reserved_bit3_fields,SX_COUNT(sxarwire_brotli_reserved_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_reserved_bit4_fields[]={
 SX_FIELD("reserved","lsb_bits[4,1]",0,1,SX_RESERVED),
};
const sx_layout sxarwire_brotli_reserved_bit4={UINT32_C(0x608d014a),"brotli_reserved_bit4",sxarwire_brotli_reserved_bit4_fields,SX_COUNT(sxarwire_brotli_reserved_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_reserved_bit5_fields[]={
 SX_FIELD("reserved","lsb_bits[5,1]",0,1,SX_RESERVED),
};
const sx_layout sxarwire_brotli_reserved_bit5={UINT32_C(0x608d014b),"brotli_reserved_bit5",sxarwire_brotli_reserved_bit5_fields,SX_COUNT(sxarwire_brotli_reserved_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_reserved_bit6_fields[]={
 SX_FIELD("reserved","lsb_bits[6,1]",0,1,SX_RESERVED),
};
const sx_layout sxarwire_brotli_reserved_bit6={UINT32_C(0x608d014c),"brotli_reserved_bit6",sxarwire_brotli_reserved_bit6_fields,SX_COUNT(sxarwire_brotli_reserved_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_reserved_bit7_fields[]={
 SX_FIELD("reserved","lsb_bits[7,1]",0,1,SX_RESERVED),
};
const sx_layout sxarwire_brotli_reserved_bit7={UINT32_C(0x608d014d),"brotli_reserved_bit7",sxarwire_brotli_reserved_bit7_fields,SX_COUNT(sxarwire_brotli_reserved_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skipbytes_bit0_fields[]={
 SX_FIELD("metadata_length_bytes","lsb_bits[0,2]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_brotli_skipbytes_bit0={UINT32_C(0x608d014e),"brotli_skipbytes_bit0",sxarwire_brotli_skipbytes_bit0_fields,SX_COUNT(sxarwire_brotli_skipbytes_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skipbytes_bit1_fields[]={
 SX_FIELD("metadata_length_bytes","lsb_bits[1,2]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_brotli_skipbytes_bit1={UINT32_C(0x608d014f),"brotli_skipbytes_bit1",sxarwire_brotli_skipbytes_bit1_fields,SX_COUNT(sxarwire_brotli_skipbytes_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skipbytes_bit2_fields[]={
 SX_FIELD("metadata_length_bytes","lsb_bits[2,2]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_brotli_skipbytes_bit2={UINT32_C(0x608d0150),"brotli_skipbytes_bit2",sxarwire_brotli_skipbytes_bit2_fields,SX_COUNT(sxarwire_brotli_skipbytes_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skipbytes_bit3_fields[]={
 SX_FIELD("metadata_length_bytes","lsb_bits[3,2]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_brotli_skipbytes_bit3={UINT32_C(0x608d0151),"brotli_skipbytes_bit3",sxarwire_brotli_skipbytes_bit3_fields,SX_COUNT(sxarwire_brotli_skipbytes_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skipbytes_bit4_fields[]={
 SX_FIELD("metadata_length_bytes","lsb_bits[4,2]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_brotli_skipbytes_bit4={UINT32_C(0x608d0152),"brotli_skipbytes_bit4",sxarwire_brotli_skipbytes_bit4_fields,SX_COUNT(sxarwire_brotli_skipbytes_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skipbytes_bit5_fields[]={
 SX_FIELD("metadata_length_bytes","lsb_bits[5,2]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_brotli_skipbytes_bit5={UINT32_C(0x608d0153),"brotli_skipbytes_bit5",sxarwire_brotli_skipbytes_bit5_fields,SX_COUNT(sxarwire_brotli_skipbytes_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skipbytes_bit6_fields[]={
 SX_FIELD("metadata_length_bytes","lsb_bits[6,2]",0,1,SX_COUNT_PROP),
};
const sx_layout sxarwire_brotli_skipbytes_bit6={UINT32_C(0x608d0154),"brotli_skipbytes_bit6",sxarwire_brotli_skipbytes_bit6_fields,SX_COUNT(sxarwire_brotli_skipbytes_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skipbytes_bit7_fields[]={
 SX_FIELD("metadata_length_bytes","lsb_bits[7,2]",0,2,SX_COUNT_PROP),
};
const sx_layout sxarwire_brotli_skipbytes_bit7={UINT32_C(0x608d0155),"brotli_skipbytes_bit7",sxarwire_brotli_skipbytes_bit7_fields,SX_COUNT(sxarwire_brotli_skipbytes_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen8_bit0_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[0,8]",0,1,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen8_bit0={UINT32_C(0x608d0156),"brotli_skiplen8_bit0",sxarwire_brotli_skiplen8_bit0_fields,SX_COUNT(sxarwire_brotli_skiplen8_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen8_bit1_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[1,8]",0,2,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen8_bit1={UINT32_C(0x608d0157),"brotli_skiplen8_bit1",sxarwire_brotli_skiplen8_bit1_fields,SX_COUNT(sxarwire_brotli_skiplen8_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen8_bit2_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[2,8]",0,2,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen8_bit2={UINT32_C(0x608d0158),"brotli_skiplen8_bit2",sxarwire_brotli_skiplen8_bit2_fields,SX_COUNT(sxarwire_brotli_skiplen8_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen8_bit3_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[3,8]",0,2,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen8_bit3={UINT32_C(0x608d0159),"brotli_skiplen8_bit3",sxarwire_brotli_skiplen8_bit3_fields,SX_COUNT(sxarwire_brotli_skiplen8_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen8_bit4_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[4,8]",0,2,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen8_bit4={UINT32_C(0x608d015a),"brotli_skiplen8_bit4",sxarwire_brotli_skiplen8_bit4_fields,SX_COUNT(sxarwire_brotli_skiplen8_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen8_bit5_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[5,8]",0,2,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen8_bit5={UINT32_C(0x608d015b),"brotli_skiplen8_bit5",sxarwire_brotli_skiplen8_bit5_fields,SX_COUNT(sxarwire_brotli_skiplen8_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen8_bit6_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[6,8]",0,2,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen8_bit6={UINT32_C(0x608d015c),"brotli_skiplen8_bit6",sxarwire_brotli_skiplen8_bit6_fields,SX_COUNT(sxarwire_brotli_skiplen8_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen8_bit7_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[7,8]",0,2,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen8_bit7={UINT32_C(0x608d015d),"brotli_skiplen8_bit7",sxarwire_brotli_skiplen8_bit7_fields,SX_COUNT(sxarwire_brotli_skiplen8_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen16_bit0_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[0,16]",0,2,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen16_bit0={UINT32_C(0x608d015e),"brotli_skiplen16_bit0",sxarwire_brotli_skiplen16_bit0_fields,SX_COUNT(sxarwire_brotli_skiplen16_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen16_bit1_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[1,16]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen16_bit1={UINT32_C(0x608d015f),"brotli_skiplen16_bit1",sxarwire_brotli_skiplen16_bit1_fields,SX_COUNT(sxarwire_brotli_skiplen16_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen16_bit2_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[2,16]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen16_bit2={UINT32_C(0x608d0160),"brotli_skiplen16_bit2",sxarwire_brotli_skiplen16_bit2_fields,SX_COUNT(sxarwire_brotli_skiplen16_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen16_bit3_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[3,16]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen16_bit3={UINT32_C(0x608d0161),"brotli_skiplen16_bit3",sxarwire_brotli_skiplen16_bit3_fields,SX_COUNT(sxarwire_brotli_skiplen16_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen16_bit4_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[4,16]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen16_bit4={UINT32_C(0x608d0162),"brotli_skiplen16_bit4",sxarwire_brotli_skiplen16_bit4_fields,SX_COUNT(sxarwire_brotli_skiplen16_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen16_bit5_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[5,16]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen16_bit5={UINT32_C(0x608d0163),"brotli_skiplen16_bit5",sxarwire_brotli_skiplen16_bit5_fields,SX_COUNT(sxarwire_brotli_skiplen16_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen16_bit6_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[6,16]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen16_bit6={UINT32_C(0x608d0164),"brotli_skiplen16_bit6",sxarwire_brotli_skiplen16_bit6_fields,SX_COUNT(sxarwire_brotli_skiplen16_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen16_bit7_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[7,16]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen16_bit7={UINT32_C(0x608d0165),"brotli_skiplen16_bit7",sxarwire_brotli_skiplen16_bit7_fields,SX_COUNT(sxarwire_brotli_skiplen16_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen24_bit0_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[0,24]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen24_bit0={UINT32_C(0x608d0166),"brotli_skiplen24_bit0",sxarwire_brotli_skiplen24_bit0_fields,SX_COUNT(sxarwire_brotli_skiplen24_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen24_bit1_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[1,24]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen24_bit1={UINT32_C(0x608d0167),"brotli_skiplen24_bit1",sxarwire_brotli_skiplen24_bit1_fields,SX_COUNT(sxarwire_brotli_skiplen24_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen24_bit2_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[2,24]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen24_bit2={UINT32_C(0x608d0168),"brotli_skiplen24_bit2",sxarwire_brotli_skiplen24_bit2_fields,SX_COUNT(sxarwire_brotli_skiplen24_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen24_bit3_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[3,24]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen24_bit3={UINT32_C(0x608d0169),"brotli_skiplen24_bit3",sxarwire_brotli_skiplen24_bit3_fields,SX_COUNT(sxarwire_brotli_skiplen24_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen24_bit4_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[4,24]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen24_bit4={UINT32_C(0x608d016a),"brotli_skiplen24_bit4",sxarwire_brotli_skiplen24_bit4_fields,SX_COUNT(sxarwire_brotli_skiplen24_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen24_bit5_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[5,24]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen24_bit5={UINT32_C(0x608d016b),"brotli_skiplen24_bit5",sxarwire_brotli_skiplen24_bit5_fields,SX_COUNT(sxarwire_brotli_skiplen24_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen24_bit6_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[6,24]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen24_bit6={UINT32_C(0x608d016c),"brotli_skiplen24_bit6",sxarwire_brotli_skiplen24_bit6_fields,SX_COUNT(sxarwire_brotli_skiplen24_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_skiplen24_bit7_fields[]={
 SX_FIELD("metadata_length_minus_one","lsb_bits[7,24]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_skiplen24_bit7={UINT32_C(0x608d016d),"brotli_skiplen24_bit7",sxarwire_brotli_skiplen24_bit7_fields,SX_COUNT(sxarwire_brotli_skiplen24_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length16_bit0_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[0,16]",0,2,SX_NONE),
};
const sx_layout sxarwire_brotli_length16_bit0={UINT32_C(0x608d016e),"brotli_length16_bit0",sxarwire_brotli_length16_bit0_fields,SX_COUNT(sxarwire_brotli_length16_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length16_bit1_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[1,16]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_length16_bit1={UINT32_C(0x608d016f),"brotli_length16_bit1",sxarwire_brotli_length16_bit1_fields,SX_COUNT(sxarwire_brotli_length16_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length16_bit2_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[2,16]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_length16_bit2={UINT32_C(0x608d0170),"brotli_length16_bit2",sxarwire_brotli_length16_bit2_fields,SX_COUNT(sxarwire_brotli_length16_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length16_bit3_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[3,16]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_length16_bit3={UINT32_C(0x608d0171),"brotli_length16_bit3",sxarwire_brotli_length16_bit3_fields,SX_COUNT(sxarwire_brotli_length16_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length16_bit4_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[4,16]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_length16_bit4={UINT32_C(0x608d0172),"brotli_length16_bit4",sxarwire_brotli_length16_bit4_fields,SX_COUNT(sxarwire_brotli_length16_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length16_bit5_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[5,16]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_length16_bit5={UINT32_C(0x608d0173),"brotli_length16_bit5",sxarwire_brotli_length16_bit5_fields,SX_COUNT(sxarwire_brotli_length16_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length16_bit6_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[6,16]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_length16_bit6={UINT32_C(0x608d0174),"brotli_length16_bit6",sxarwire_brotli_length16_bit6_fields,SX_COUNT(sxarwire_brotli_length16_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length16_bit7_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[7,16]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_length16_bit7={UINT32_C(0x608d0175),"brotli_length16_bit7",sxarwire_brotli_length16_bit7_fields,SX_COUNT(sxarwire_brotli_length16_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length20_bit0_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[0,20]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_length20_bit0={UINT32_C(0x608d0176),"brotli_length20_bit0",sxarwire_brotli_length20_bit0_fields,SX_COUNT(sxarwire_brotli_length20_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length20_bit1_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[1,20]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_length20_bit1={UINT32_C(0x608d0177),"brotli_length20_bit1",sxarwire_brotli_length20_bit1_fields,SX_COUNT(sxarwire_brotli_length20_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length20_bit2_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[2,20]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_length20_bit2={UINT32_C(0x608d0178),"brotli_length20_bit2",sxarwire_brotli_length20_bit2_fields,SX_COUNT(sxarwire_brotli_length20_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length20_bit3_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[3,20]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_length20_bit3={UINT32_C(0x608d0179),"brotli_length20_bit3",sxarwire_brotli_length20_bit3_fields,SX_COUNT(sxarwire_brotli_length20_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length20_bit4_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[4,20]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_length20_bit4={UINT32_C(0x608d017a),"brotli_length20_bit4",sxarwire_brotli_length20_bit4_fields,SX_COUNT(sxarwire_brotli_length20_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length20_bit5_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[5,20]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_length20_bit5={UINT32_C(0x608d017b),"brotli_length20_bit5",sxarwire_brotli_length20_bit5_fields,SX_COUNT(sxarwire_brotli_length20_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length20_bit6_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[6,20]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_length20_bit6={UINT32_C(0x608d017c),"brotli_length20_bit6",sxarwire_brotli_length20_bit6_fields,SX_COUNT(sxarwire_brotli_length20_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length20_bit7_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[7,20]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_length20_bit7={UINT32_C(0x608d017d),"brotli_length20_bit7",sxarwire_brotli_length20_bit7_fields,SX_COUNT(sxarwire_brotli_length20_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length24_bit0_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[0,24]",0,3,SX_NONE),
};
const sx_layout sxarwire_brotli_length24_bit0={UINT32_C(0x608d017e),"brotli_length24_bit0",sxarwire_brotli_length24_bit0_fields,SX_COUNT(sxarwire_brotli_length24_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length24_bit1_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[1,24]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_length24_bit1={UINT32_C(0x608d017f),"brotli_length24_bit1",sxarwire_brotli_length24_bit1_fields,SX_COUNT(sxarwire_brotli_length24_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length24_bit2_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[2,24]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_length24_bit2={UINT32_C(0x608d0180),"brotli_length24_bit2",sxarwire_brotli_length24_bit2_fields,SX_COUNT(sxarwire_brotli_length24_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length24_bit3_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[3,24]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_length24_bit3={UINT32_C(0x608d0181),"brotli_length24_bit3",sxarwire_brotli_length24_bit3_fields,SX_COUNT(sxarwire_brotli_length24_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length24_bit4_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[4,24]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_length24_bit4={UINT32_C(0x608d0182),"brotli_length24_bit4",sxarwire_brotli_length24_bit4_fields,SX_COUNT(sxarwire_brotli_length24_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length24_bit5_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[5,24]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_length24_bit5={UINT32_C(0x608d0183),"brotli_length24_bit5",sxarwire_brotli_length24_bit5_fields,SX_COUNT(sxarwire_brotli_length24_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length24_bit6_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[6,24]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_length24_bit6={UINT32_C(0x608d0184),"brotli_length24_bit6",sxarwire_brotli_length24_bit6_fields,SX_COUNT(sxarwire_brotli_length24_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_length24_bit7_fields[]={
 SX_FIELD("uncompressed_length_minus_one","lsb_bits[7,24]",0,4,SX_NONE),
};
const sx_layout sxarwire_brotli_length24_bit7={UINT32_C(0x608d0185),"brotli_length24_bit7",sxarwire_brotli_length24_bit7_fields,SX_COUNT(sxarwire_brotli_length24_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_uncompressed_bit0_fields[]={
 SX_FIELD("is_uncompressed","lsb_bits[0,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_uncompressed_bit0={UINT32_C(0x608d0186),"brotli_uncompressed_bit0",sxarwire_brotli_uncompressed_bit0_fields,SX_COUNT(sxarwire_brotli_uncompressed_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_uncompressed_bit1_fields[]={
 SX_FIELD("is_uncompressed","lsb_bits[1,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_uncompressed_bit1={UINT32_C(0x608d0187),"brotli_uncompressed_bit1",sxarwire_brotli_uncompressed_bit1_fields,SX_COUNT(sxarwire_brotli_uncompressed_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_uncompressed_bit2_fields[]={
 SX_FIELD("is_uncompressed","lsb_bits[2,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_uncompressed_bit2={UINT32_C(0x608d0188),"brotli_uncompressed_bit2",sxarwire_brotli_uncompressed_bit2_fields,SX_COUNT(sxarwire_brotli_uncompressed_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_uncompressed_bit3_fields[]={
 SX_FIELD("is_uncompressed","lsb_bits[3,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_uncompressed_bit3={UINT32_C(0x608d0189),"brotli_uncompressed_bit3",sxarwire_brotli_uncompressed_bit3_fields,SX_COUNT(sxarwire_brotli_uncompressed_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_uncompressed_bit4_fields[]={
 SX_FIELD("is_uncompressed","lsb_bits[4,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_uncompressed_bit4={UINT32_C(0x608d018a),"brotli_uncompressed_bit4",sxarwire_brotli_uncompressed_bit4_fields,SX_COUNT(sxarwire_brotli_uncompressed_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_uncompressed_bit5_fields[]={
 SX_FIELD("is_uncompressed","lsb_bits[5,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_uncompressed_bit5={UINT32_C(0x608d018b),"brotli_uncompressed_bit5",sxarwire_brotli_uncompressed_bit5_fields,SX_COUNT(sxarwire_brotli_uncompressed_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_uncompressed_bit6_fields[]={
 SX_FIELD("is_uncompressed","lsb_bits[6,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_uncompressed_bit6={UINT32_C(0x608d018c),"brotli_uncompressed_bit6",sxarwire_brotli_uncompressed_bit6_fields,SX_COUNT(sxarwire_brotli_uncompressed_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_uncompressed_bit7_fields[]={
 SX_FIELD("is_uncompressed","lsb_bits[7,1]",0,1,SX_FLAGS),
};
const sx_layout sxarwire_brotli_uncompressed_bit7={UINT32_C(0x608d018d),"brotli_uncompressed_bit7",sxarwire_brotli_uncompressed_bit7_fields,SX_COUNT(sxarwire_brotli_uncompressed_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_fill1_bit7_fields[]={
 SX_FIELD("zero_fill_bits","lsb_bits[7,1]",0,1,SX_RESERVED),
};
const sx_layout sxarwire_brotli_fill1_bit7={UINT32_C(0x608d018e),"brotli_fill1_bit7",sxarwire_brotli_fill1_bit7_fields,SX_COUNT(sxarwire_brotli_fill1_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_fill2_bit6_fields[]={
 SX_FIELD("zero_fill_bits","lsb_bits[6,2]",0,1,SX_RESERVED),
};
const sx_layout sxarwire_brotli_fill2_bit6={UINT32_C(0x608d018f),"brotli_fill2_bit6",sxarwire_brotli_fill2_bit6_fields,SX_COUNT(sxarwire_brotli_fill2_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_fill3_bit5_fields[]={
 SX_FIELD("zero_fill_bits","lsb_bits[5,3]",0,1,SX_RESERVED),
};
const sx_layout sxarwire_brotli_fill3_bit5={UINT32_C(0x608d0190),"brotli_fill3_bit5",sxarwire_brotli_fill3_bit5_fields,SX_COUNT(sxarwire_brotli_fill3_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_fill4_bit4_fields[]={
 SX_FIELD("zero_fill_bits","lsb_bits[4,4]",0,1,SX_RESERVED),
};
const sx_layout sxarwire_brotli_fill4_bit4={UINT32_C(0x608d0191),"brotli_fill4_bit4",sxarwire_brotli_fill4_bit4_fields,SX_COUNT(sxarwire_brotli_fill4_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_fill5_bit3_fields[]={
 SX_FIELD("zero_fill_bits","lsb_bits[3,5]",0,1,SX_RESERVED),
};
const sx_layout sxarwire_brotli_fill5_bit3={UINT32_C(0x608d0192),"brotli_fill5_bit3",sxarwire_brotli_fill5_bit3_fields,SX_COUNT(sxarwire_brotli_fill5_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_fill6_bit2_fields[]={
 SX_FIELD("zero_fill_bits","lsb_bits[2,6]",0,1,SX_RESERVED),
};
const sx_layout sxarwire_brotli_fill6_bit2={UINT32_C(0x608d0193),"brotli_fill6_bit2",sxarwire_brotli_fill6_bit2_fields,SX_COUNT(sxarwire_brotli_fill6_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_fill7_bit1_fields[]={
 SX_FIELD("zero_fill_bits","lsb_bits[1,7]",0,1,SX_RESERVED),
};
const sx_layout sxarwire_brotli_fill7_bit1={UINT32_C(0x608d0194),"brotli_fill7_bit1",sxarwire_brotli_fill7_bit1_fields,SX_COUNT(sxarwire_brotli_fill7_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_brotli_mt_frame_fields[]={
 SX_FIELD("frame_magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("header_payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("codec_magic","char[2]",12,2,SX_SIGNATURE),
 SX_FIELD("output_limit_64k_units","uint16",14,2,SX_NONE),
};
const sx_layout sxarwire_brotli_mt_frame={UINT32_C(0x608d028e),"brotli_mt_frame",sxarwire_brotli_mt_frame_fields,SX_COUNT(sxarwire_brotli_mt_frame_fields),SX_LE};
static const sx_layout *const sxarwire_set_brotli_window1[]={&sxarwire_brotli_window1_bit0};
static const sx_layout *const sxarwire_set_brotli_window4[]={&sxarwire_brotli_window4_bit0};
static const sx_layout *const sxarwire_set_brotli_window7[]={&sxarwire_brotli_window7_bit0};
static const sx_layout *const sxarwire_set_brotli_last[]={&sxarwire_brotli_last_bit0,&sxarwire_brotli_last_bit1,&sxarwire_brotli_last_bit2,&sxarwire_brotli_last_bit3,&sxarwire_brotli_last_bit4,&sxarwire_brotli_last_bit5,&sxarwire_brotli_last_bit6,&sxarwire_brotli_last_bit7};
static const sx_layout *const sxarwire_set_brotli_empty[]={&sxarwire_brotli_empty_bit0,&sxarwire_brotli_empty_bit1,&sxarwire_brotli_empty_bit2,&sxarwire_brotli_empty_bit3,&sxarwire_brotli_empty_bit4,&sxarwire_brotli_empty_bit5,&sxarwire_brotli_empty_bit6,&sxarwire_brotli_empty_bit7};
static const sx_layout *const sxarwire_set_brotli_nibbles[]={&sxarwire_brotli_nibbles_bit0,&sxarwire_brotli_nibbles_bit1,&sxarwire_brotli_nibbles_bit2,&sxarwire_brotli_nibbles_bit3,&sxarwire_brotli_nibbles_bit4,&sxarwire_brotli_nibbles_bit5,&sxarwire_brotli_nibbles_bit6,&sxarwire_brotli_nibbles_bit7};
static const sx_layout *const sxarwire_set_brotli_reserved[]={&sxarwire_brotli_reserved_bit0,&sxarwire_brotli_reserved_bit1,&sxarwire_brotli_reserved_bit2,&sxarwire_brotli_reserved_bit3,&sxarwire_brotli_reserved_bit4,&sxarwire_brotli_reserved_bit5,&sxarwire_brotli_reserved_bit6,&sxarwire_brotli_reserved_bit7};
static const sx_layout *const sxarwire_set_brotli_skipbytes[]={&sxarwire_brotli_skipbytes_bit0,&sxarwire_brotli_skipbytes_bit1,&sxarwire_brotli_skipbytes_bit2,&sxarwire_brotli_skipbytes_bit3,&sxarwire_brotli_skipbytes_bit4,&sxarwire_brotli_skipbytes_bit5,&sxarwire_brotli_skipbytes_bit6,&sxarwire_brotli_skipbytes_bit7};
static const sx_layout *const sxarwire_set_brotli_skiplen8[]={&sxarwire_brotli_skiplen8_bit0,&sxarwire_brotli_skiplen8_bit1,&sxarwire_brotli_skiplen8_bit2,&sxarwire_brotli_skiplen8_bit3,&sxarwire_brotli_skiplen8_bit4,&sxarwire_brotli_skiplen8_bit5,&sxarwire_brotli_skiplen8_bit6,&sxarwire_brotli_skiplen8_bit7};
static const sx_layout *const sxarwire_set_brotli_skiplen16[]={&sxarwire_brotli_skiplen16_bit0,&sxarwire_brotli_skiplen16_bit1,&sxarwire_brotli_skiplen16_bit2,&sxarwire_brotli_skiplen16_bit3,&sxarwire_brotli_skiplen16_bit4,&sxarwire_brotli_skiplen16_bit5,&sxarwire_brotli_skiplen16_bit6,&sxarwire_brotli_skiplen16_bit7};
static const sx_layout *const sxarwire_set_brotli_skiplen24[]={&sxarwire_brotli_skiplen24_bit0,&sxarwire_brotli_skiplen24_bit1,&sxarwire_brotli_skiplen24_bit2,&sxarwire_brotli_skiplen24_bit3,&sxarwire_brotli_skiplen24_bit4,&sxarwire_brotli_skiplen24_bit5,&sxarwire_brotli_skiplen24_bit6,&sxarwire_brotli_skiplen24_bit7};
static const sx_layout *const sxarwire_set_brotli_length16[]={&sxarwire_brotli_length16_bit0,&sxarwire_brotli_length16_bit1,&sxarwire_brotli_length16_bit2,&sxarwire_brotli_length16_bit3,&sxarwire_brotli_length16_bit4,&sxarwire_brotli_length16_bit5,&sxarwire_brotli_length16_bit6,&sxarwire_brotli_length16_bit7};
static const sx_layout *const sxarwire_set_brotli_length20[]={&sxarwire_brotli_length20_bit0,&sxarwire_brotli_length20_bit1,&sxarwire_brotli_length20_bit2,&sxarwire_brotli_length20_bit3,&sxarwire_brotli_length20_bit4,&sxarwire_brotli_length20_bit5,&sxarwire_brotli_length20_bit6,&sxarwire_brotli_length20_bit7};
static const sx_layout *const sxarwire_set_brotli_length24[]={&sxarwire_brotli_length24_bit0,&sxarwire_brotli_length24_bit1,&sxarwire_brotli_length24_bit2,&sxarwire_brotli_length24_bit3,&sxarwire_brotli_length24_bit4,&sxarwire_brotli_length24_bit5,&sxarwire_brotli_length24_bit6,&sxarwire_brotli_length24_bit7};
static const sx_layout *const sxarwire_set_brotli_uncompressed[]={&sxarwire_brotli_uncompressed_bit0,&sxarwire_brotli_uncompressed_bit1,&sxarwire_brotli_uncompressed_bit2,&sxarwire_brotli_uncompressed_bit3,&sxarwire_brotli_uncompressed_bit4,&sxarwire_brotli_uncompressed_bit5,&sxarwire_brotli_uncompressed_bit6,&sxarwire_brotli_uncompressed_bit7};
static const sx_layout *const sxarwire_set_brotli_fill1[]={&sxarwire_brotli_fill1_bit7};
static const sx_layout *const sxarwire_set_brotli_fill2[]={&sxarwire_brotli_fill2_bit6};
static const sx_layout *const sxarwire_set_brotli_fill3[]={&sxarwire_brotli_fill3_bit5};
static const sx_layout *const sxarwire_set_brotli_fill4[]={&sxarwire_brotli_fill4_bit4};
static const sx_layout *const sxarwire_set_brotli_fill5[]={&sxarwire_brotli_fill5_bit3};
static const sx_layout *const sxarwire_set_brotli_fill6[]={&sxarwire_brotli_fill6_bit2};
static const sx_layout *const sxarwire_set_brotli_fill7[]={&sxarwire_brotli_fill7_bit1};
#define SXARWIRE_LIMIT 20000U
static bool sxarwire_brotli_align(sxarwire_bits*b){unsigned n=(unsigned)((8-(b->bit&7))&7);if(!n)return true;uint64_t start=b->bit,v;if(!sxarwire_take(b,n,&v)||v)return false;const sx_layout*l=NULL;switch(n){
 case 1:l=sxarwire_set_brotli_fill1[0];break;case 2:l=sxarwire_set_brotli_fill2[0];break;case 3:l=sxarwire_set_brotli_fill3[0];break;case 4:l=sxarwire_set_brotli_fill4[0];break;case 5:l=sxarwire_set_brotli_fill5[0];break;case 6:l=sxarwire_set_brotli_fill6[0];break;case 7:l=sxarwire_set_brotli_fill7[0];break;}
 return l&&sxarwire_put(b->c,l,start/8);}
static bool sxarwire_brotli_raw(sx_context*c,uint64_t base){sxarwire_bits b={c,base*8,true,0,0,false};uint64_t v,x;unsigned width=1;if(!sxarwire_take(&b,1,&v))return false;if(v){if(!sxarwire_take(&b,3,&v))return false;width=4;if(!v){if(!sxarwire_take(&b,3,&v)||v==1)return false;width=7;}}
 if(!sxarwire_put(c,width==1?sxarwire_set_brotli_window1[0]:width==4?sxarwire_set_brotli_window4[0]:sxarwire_set_brotli_window7[0],base))return false;
 while(c->count<SXARWIRE_LIMIT){uint64_t last,nib,len,uncompressed=0;if(!sxarwire_field(&b,sxarwire_set_brotli_last,1,&last))return false;
  if(last){if(!sxarwire_field(&b,sxarwire_set_brotli_empty,1,&x))return false;if(x)return sxarwire_brotli_align(&b);}
  if(!sxarwire_field(&b,sxarwire_set_brotli_nibbles,2,&nib))return false;
  if(nib==3){if(!sxarwire_field(&b,sxarwire_set_brotli_reserved,1,&x)||x||!sxarwire_field(&b,sxarwire_set_brotli_skipbytes,2,&x))return false;len=0;if(x){unsigned bits=(unsigned)x*8;const sx_layout*const*set=bits==8?sxarwire_set_brotli_skiplen8:bits==16?sxarwire_set_brotli_skiplen16:sxarwire_set_brotli_skiplen24;if(!sxarwire_field(&b,set,bits,&len)||(x>1&&!(len>>(bits-8))))return false;len++;}
   if(!sxarwire_brotli_align(&b)||!sxarwire_span(c,b.bit/8,len)||len>(UINT64_MAX-b.bit)/8)return false;b.bit+=len*8;if(last)return true;continue;}
  unsigned bits=16+4*(unsigned)nib;const sx_layout*const*set=bits==16?sxarwire_set_brotli_length16:bits==20?sxarwire_set_brotli_length20:sxarwire_set_brotli_length24;if(!sxarwire_field(&b,set,bits,&len)||(nib&&!(len>>(bits-4))))return false;len++;
  if(!last&&!sxarwire_field(&b,sxarwire_set_brotli_uncompressed,1,&uncompressed))return false;
  if(!uncompressed)return true; /* Compressed Huffman/context payload remains raw. */
  if(!sxarwire_brotli_align(&b)||!sxarwire_span(c,b.bit/8,len)||len>(UINT64_MAX-b.bit)/8)return false;b.bit+=len*8;
 }return true;
}
/* 7-Zip MT frames have independent raw bitstreams. Clamp the physical reader
 * to each authenticated framing extent before inspecting its meta-blocks. */
static bool sxarwire_brotli_mt_header(const uint8_t*h){return sxarwire_num(h,4,false)==UINT32_C(0x184D2A50)&&sxarwire_num(h+4,4,false)==8&&h[12]=='B'&&h[13]=='R';}
static bool sxarwire_brotli(sx_context*c){uint8_t h[16];if(!sxarwire_read(c,0,h,16)||!sxarwire_brotli_mt_header(h))return sxarwire_brotli_raw(c,0);
 uint64_t p=0;while(p<(uint64_t)c->size&&c->count<SXARWIRE_LIMIT){if(!sxarwire_read(c,p,h,16)||!sxarwire_brotli_mt_header(h))return false;uint64_t n=sxarwire_num(h+8,4,false);if(!n||!sxarwire_num(h+14,2,false)||!sxarwire_span(c,p+16,n)||!sxarwire_put(c,&sxarwire_brotli_mt_frame,p))return false;
  int64_t saved_size=c->size;c->size=(int64_t)(p+16+n);bool framed=sxarwire_brotli_raw(c,p+16);c->size=saved_size;if(c->failed||xx_pd_is_stopped(c->pd))return false;(void)framed; /* Optional inner metadata may remain raw; the next frame is independently bounded. */
  p+=16+n;
 }return true;
}
bool sx_brotli_build(sx_context*c)
{
 return sxarwire_brotli(c);
}
