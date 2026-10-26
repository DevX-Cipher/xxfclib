/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * StuffIt X data structures, moved out of the archivetransport schema family. */
#include "../../xx_format_schema_archivetransport.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxatp_stuffitx_signature_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
};
const sx_layout sxatp_stuffitx_signature={UINT32_C(0x60890007),"stuffitx_signature",sxatp_stuffitx_signature_fields,SX_COUNT(sxatp_stuffitx_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_element_flag_fields[]={
 SX_FIELD("flag","lsb_bits[0,1]",0,1,SX_FLAGS),
};
const sx_layout sxatp_stuffitx_element_flag={UINT32_C(0x60890008),"stuffitx_element_flag",sxatp_stuffitx_element_flag_fields,SX_COUNT(sxatp_stuffitx_element_flag_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_element_type_bit1_fields[]={
 SX_FIELD("element_type","stuffitx_p2_1",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_element_type_bit1={UINT32_C(0x60890009),"stuffitx_element_type_bit1",sxatp_stuffitx_element_type_bit1_fields,SX_COUNT(sxatp_stuffitx_element_type_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit0_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_0",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_attribute_key_bit0={UINT32_C(0x6089000a),"stuffitx_attribute_key_bit0",sxatp_stuffitx_attribute_key_bit0_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit1_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_1",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_attribute_key_bit1={UINT32_C(0x6089000b),"stuffitx_attribute_key_bit1",sxatp_stuffitx_attribute_key_bit1_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit2_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_2",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_attribute_key_bit2={UINT32_C(0x6089000c),"stuffitx_attribute_key_bit2",sxatp_stuffitx_attribute_key_bit2_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit3_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_3",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_attribute_key_bit3={UINT32_C(0x6089000d),"stuffitx_attribute_key_bit3",sxatp_stuffitx_attribute_key_bit3_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit4_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_4",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_attribute_key_bit4={UINT32_C(0x6089000e),"stuffitx_attribute_key_bit4",sxatp_stuffitx_attribute_key_bit4_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit5_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_5",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_attribute_key_bit5={UINT32_C(0x6089000f),"stuffitx_attribute_key_bit5",sxatp_stuffitx_attribute_key_bit5_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit6_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_6",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_attribute_key_bit6={UINT32_C(0x60890010),"stuffitx_attribute_key_bit6",sxatp_stuffitx_attribute_key_bit6_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_key_bit7_fields[]={
 SX_FIELD("attribute_key","stuffitx_p2_7",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_attribute_key_bit7={UINT32_C(0x60890011),"stuffitx_attribute_key_bit7",sxatp_stuffitx_attribute_key_bit7_fields,SX_COUNT(sxatp_stuffitx_attribute_key_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit0_fields[]={
 SX_FIELD("object_id","stuffitx_p2_0",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_object_id_bit0={UINT32_C(0x60890012),"stuffitx_object_id_bit0",sxatp_stuffitx_object_id_bit0_fields,SX_COUNT(sxatp_stuffitx_object_id_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit1_fields[]={
 SX_FIELD("object_id","stuffitx_p2_1",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_object_id_bit1={UINT32_C(0x60890013),"stuffitx_object_id_bit1",sxatp_stuffitx_object_id_bit1_fields,SX_COUNT(sxatp_stuffitx_object_id_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit2_fields[]={
 SX_FIELD("object_id","stuffitx_p2_2",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_object_id_bit2={UINT32_C(0x60890014),"stuffitx_object_id_bit2",sxatp_stuffitx_object_id_bit2_fields,SX_COUNT(sxatp_stuffitx_object_id_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit3_fields[]={
 SX_FIELD("object_id","stuffitx_p2_3",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_object_id_bit3={UINT32_C(0x60890015),"stuffitx_object_id_bit3",sxatp_stuffitx_object_id_bit3_fields,SX_COUNT(sxatp_stuffitx_object_id_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit4_fields[]={
 SX_FIELD("object_id","stuffitx_p2_4",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_object_id_bit4={UINT32_C(0x60890016),"stuffitx_object_id_bit4",sxatp_stuffitx_object_id_bit4_fields,SX_COUNT(sxatp_stuffitx_object_id_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit5_fields[]={
 SX_FIELD("object_id","stuffitx_p2_5",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_object_id_bit5={UINT32_C(0x60890017),"stuffitx_object_id_bit5",sxatp_stuffitx_object_id_bit5_fields,SX_COUNT(sxatp_stuffitx_object_id_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit6_fields[]={
 SX_FIELD("object_id","stuffitx_p2_6",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_object_id_bit6={UINT32_C(0x60890018),"stuffitx_object_id_bit6",sxatp_stuffitx_object_id_bit6_fields,SX_COUNT(sxatp_stuffitx_object_id_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_object_id_bit7_fields[]={
 SX_FIELD("object_id","stuffitx_p2_7",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_object_id_bit7={UINT32_C(0x60890019),"stuffitx_object_id_bit7",sxatp_stuffitx_object_id_bit7_fields,SX_COUNT(sxatp_stuffitx_object_id_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit0_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_0",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_parent_id_bit0={UINT32_C(0x6089001a),"stuffitx_parent_id_bit0",sxatp_stuffitx_parent_id_bit0_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit1_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_1",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_parent_id_bit1={UINT32_C(0x6089001b),"stuffitx_parent_id_bit1",sxatp_stuffitx_parent_id_bit1_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit2_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_2",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_parent_id_bit2={UINT32_C(0x6089001c),"stuffitx_parent_id_bit2",sxatp_stuffitx_parent_id_bit2_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit3_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_3",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_parent_id_bit3={UINT32_C(0x6089001d),"stuffitx_parent_id_bit3",sxatp_stuffitx_parent_id_bit3_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit4_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_4",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_parent_id_bit4={UINT32_C(0x6089001e),"stuffitx_parent_id_bit4",sxatp_stuffitx_parent_id_bit4_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit5_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_5",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_parent_id_bit5={UINT32_C(0x6089001f),"stuffitx_parent_id_bit5",sxatp_stuffitx_parent_id_bit5_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit6_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_6",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_parent_id_bit6={UINT32_C(0x60890020),"stuffitx_parent_id_bit6",sxatp_stuffitx_parent_id_bit6_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_parent_id_bit7_fields[]={
 SX_FIELD("parent_id","stuffitx_p2_7",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_parent_id_bit7={UINT32_C(0x60890021),"stuffitx_parent_id_bit7",sxatp_stuffitx_parent_id_bit7_fields,SX_COUNT(sxatp_stuffitx_parent_id_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit0_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_0",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_stream_id_bit0={UINT32_C(0x60890022),"stuffitx_stream_id_bit0",sxatp_stuffitx_stream_id_bit0_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit1_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_1",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_stream_id_bit1={UINT32_C(0x60890023),"stuffitx_stream_id_bit1",sxatp_stuffitx_stream_id_bit1_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit2_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_2",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_stream_id_bit2={UINT32_C(0x60890024),"stuffitx_stream_id_bit2",sxatp_stuffitx_stream_id_bit2_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit3_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_3",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_stream_id_bit3={UINT32_C(0x60890025),"stuffitx_stream_id_bit3",sxatp_stuffitx_stream_id_bit3_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit4_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_4",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_stream_id_bit4={UINT32_C(0x60890026),"stuffitx_stream_id_bit4",sxatp_stuffitx_stream_id_bit4_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit5_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_5",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_stream_id_bit5={UINT32_C(0x60890027),"stuffitx_stream_id_bit5",sxatp_stuffitx_stream_id_bit5_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit6_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_6",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_stream_id_bit6={UINT32_C(0x60890028),"stuffitx_stream_id_bit6",sxatp_stuffitx_stream_id_bit6_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_stream_id_bit7_fields[]={
 SX_FIELD("stream_id","stuffitx_p2_7",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_stream_id_bit7={UINT32_C(0x60890029),"stuffitx_stream_id_bit7",sxatp_stuffitx_stream_id_bit7_fields,SX_COUNT(sxatp_stuffitx_stream_id_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit0_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_0",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_fork_index_bit0={UINT32_C(0x6089002a),"stuffitx_fork_index_bit0",sxatp_stuffitx_fork_index_bit0_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit1_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_1",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_fork_index_bit1={UINT32_C(0x6089002b),"stuffitx_fork_index_bit1",sxatp_stuffitx_fork_index_bit1_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit2_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_2",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_fork_index_bit2={UINT32_C(0x6089002c),"stuffitx_fork_index_bit2",sxatp_stuffitx_fork_index_bit2_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit3_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_3",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_fork_index_bit3={UINT32_C(0x6089002d),"stuffitx_fork_index_bit3",sxatp_stuffitx_fork_index_bit3_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit4_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_4",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_fork_index_bit4={UINT32_C(0x6089002e),"stuffitx_fork_index_bit4",sxatp_stuffitx_fork_index_bit4_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit5_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_5",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_fork_index_bit5={UINT32_C(0x6089002f),"stuffitx_fork_index_bit5",sxatp_stuffitx_fork_index_bit5_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit6_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_6",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_fork_index_bit6={UINT32_C(0x60890030),"stuffitx_fork_index_bit6",sxatp_stuffitx_fork_index_bit6_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_index_bit7_fields[]={
 SX_FIELD("fork_index","stuffitx_p2_7",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_fork_index_bit7={UINT32_C(0x60890031),"stuffitx_fork_index_bit7",sxatp_stuffitx_fork_index_bit7_fields,SX_COUNT(sxatp_stuffitx_fork_index_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit0_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_0",0,0,SX_SIZE),
};
const sx_layout sxatp_stuffitx_declared_size_bit0={UINT32_C(0x60890032),"stuffitx_declared_size_bit0",sxatp_stuffitx_declared_size_bit0_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit1_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_1",0,0,SX_SIZE),
};
const sx_layout sxatp_stuffitx_declared_size_bit1={UINT32_C(0x60890033),"stuffitx_declared_size_bit1",sxatp_stuffitx_declared_size_bit1_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit2_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_2",0,0,SX_SIZE),
};
const sx_layout sxatp_stuffitx_declared_size_bit2={UINT32_C(0x60890034),"stuffitx_declared_size_bit2",sxatp_stuffitx_declared_size_bit2_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit3_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_3",0,0,SX_SIZE),
};
const sx_layout sxatp_stuffitx_declared_size_bit3={UINT32_C(0x60890035),"stuffitx_declared_size_bit3",sxatp_stuffitx_declared_size_bit3_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit4_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_4",0,0,SX_SIZE),
};
const sx_layout sxatp_stuffitx_declared_size_bit4={UINT32_C(0x60890036),"stuffitx_declared_size_bit4",sxatp_stuffitx_declared_size_bit4_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit5_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_5",0,0,SX_SIZE),
};
const sx_layout sxatp_stuffitx_declared_size_bit5={UINT32_C(0x60890037),"stuffitx_declared_size_bit5",sxatp_stuffitx_declared_size_bit5_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit6_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_6",0,0,SX_SIZE),
};
const sx_layout sxatp_stuffitx_declared_size_bit6={UINT32_C(0x60890038),"stuffitx_declared_size_bit6",sxatp_stuffitx_declared_size_bit6_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_declared_size_bit7_fields[]={
 SX_FIELD("declared_size","stuffitx_p2_7",0,0,SX_SIZE),
};
const sx_layout sxatp_stuffitx_declared_size_bit7={UINT32_C(0x60890039),"stuffitx_declared_size_bit7",sxatp_stuffitx_declared_size_bit7_fields,SX_COUNT(sxatp_stuffitx_declared_size_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit0_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_0",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_attribute_value_bit0={UINT32_C(0x6089003a),"stuffitx_attribute_value_bit0",sxatp_stuffitx_attribute_value_bit0_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit1_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_1",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_attribute_value_bit1={UINT32_C(0x6089003b),"stuffitx_attribute_value_bit1",sxatp_stuffitx_attribute_value_bit1_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit2_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_2",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_attribute_value_bit2={UINT32_C(0x6089003c),"stuffitx_attribute_value_bit2",sxatp_stuffitx_attribute_value_bit2_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit3_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_3",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_attribute_value_bit3={UINT32_C(0x6089003d),"stuffitx_attribute_value_bit3",sxatp_stuffitx_attribute_value_bit3_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit4_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_4",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_attribute_value_bit4={UINT32_C(0x6089003e),"stuffitx_attribute_value_bit4",sxatp_stuffitx_attribute_value_bit4_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit5_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_5",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_attribute_value_bit5={UINT32_C(0x6089003f),"stuffitx_attribute_value_bit5",sxatp_stuffitx_attribute_value_bit5_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit6_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_6",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_attribute_value_bit6={UINT32_C(0x60890040),"stuffitx_attribute_value_bit6",sxatp_stuffitx_attribute_value_bit6_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_attribute_value_bit7_fields[]={
 SX_FIELD("attribute_value","stuffitx_p2_7",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_attribute_value_bit7={UINT32_C(0x60890041),"stuffitx_attribute_value_bit7",sxatp_stuffitx_attribute_value_bit7_fields,SX_COUNT(sxatp_stuffitx_attribute_value_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit0_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_0",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_algorithm_key_bit0={UINT32_C(0x60890042),"stuffitx_algorithm_key_bit0",sxatp_stuffitx_algorithm_key_bit0_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit1_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_1",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_algorithm_key_bit1={UINT32_C(0x60890043),"stuffitx_algorithm_key_bit1",sxatp_stuffitx_algorithm_key_bit1_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit2_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_2",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_algorithm_key_bit2={UINT32_C(0x60890044),"stuffitx_algorithm_key_bit2",sxatp_stuffitx_algorithm_key_bit2_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit3_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_3",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_algorithm_key_bit3={UINT32_C(0x60890045),"stuffitx_algorithm_key_bit3",sxatp_stuffitx_algorithm_key_bit3_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit4_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_4",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_algorithm_key_bit4={UINT32_C(0x60890046),"stuffitx_algorithm_key_bit4",sxatp_stuffitx_algorithm_key_bit4_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit5_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_5",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_algorithm_key_bit5={UINT32_C(0x60890047),"stuffitx_algorithm_key_bit5",sxatp_stuffitx_algorithm_key_bit5_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit6_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_6",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_algorithm_key_bit6={UINT32_C(0x60890048),"stuffitx_algorithm_key_bit6",sxatp_stuffitx_algorithm_key_bit6_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_key_bit7_fields[]={
 SX_FIELD("algorithm_key","stuffitx_p2_7",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_algorithm_key_bit7={UINT32_C(0x60890049),"stuffitx_algorithm_key_bit7",sxatp_stuffitx_algorithm_key_bit7_fields,SX_COUNT(sxatp_stuffitx_algorithm_key_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit0_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_0",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_algorithm_value_bit0={UINT32_C(0x6089004a),"stuffitx_algorithm_value_bit0",sxatp_stuffitx_algorithm_value_bit0_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit1_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_1",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_algorithm_value_bit1={UINT32_C(0x6089004b),"stuffitx_algorithm_value_bit1",sxatp_stuffitx_algorithm_value_bit1_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit2_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_2",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_algorithm_value_bit2={UINT32_C(0x6089004c),"stuffitx_algorithm_value_bit2",sxatp_stuffitx_algorithm_value_bit2_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit3_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_3",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_algorithm_value_bit3={UINT32_C(0x6089004d),"stuffitx_algorithm_value_bit3",sxatp_stuffitx_algorithm_value_bit3_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit4_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_4",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_algorithm_value_bit4={UINT32_C(0x6089004e),"stuffitx_algorithm_value_bit4",sxatp_stuffitx_algorithm_value_bit4_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit5_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_5",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_algorithm_value_bit5={UINT32_C(0x6089004f),"stuffitx_algorithm_value_bit5",sxatp_stuffitx_algorithm_value_bit5_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit6_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_6",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_algorithm_value_bit6={UINT32_C(0x60890050),"stuffitx_algorithm_value_bit6",sxatp_stuffitx_algorithm_value_bit6_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_algorithm_value_bit7_fields[]={
 SX_FIELD("algorithm_value","stuffitx_p2_7",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_algorithm_value_bit7={UINT32_C(0x60890051),"stuffitx_algorithm_value_bit7",sxatp_stuffitx_algorithm_value_bit7_fields,SX_COUNT(sxatp_stuffitx_algorithm_value_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit0_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_0",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_cipher_extra_bit0={UINT32_C(0x60890052),"stuffitx_cipher_extra_bit0",sxatp_stuffitx_cipher_extra_bit0_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit1_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_1",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_cipher_extra_bit1={UINT32_C(0x60890053),"stuffitx_cipher_extra_bit1",sxatp_stuffitx_cipher_extra_bit1_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit2_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_2",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_cipher_extra_bit2={UINT32_C(0x60890054),"stuffitx_cipher_extra_bit2",sxatp_stuffitx_cipher_extra_bit2_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit3_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_3",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_cipher_extra_bit3={UINT32_C(0x60890055),"stuffitx_cipher_extra_bit3",sxatp_stuffitx_cipher_extra_bit3_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit4_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_4",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_cipher_extra_bit4={UINT32_C(0x60890056),"stuffitx_cipher_extra_bit4",sxatp_stuffitx_cipher_extra_bit4_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit5_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_5",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_cipher_extra_bit5={UINT32_C(0x60890057),"stuffitx_cipher_extra_bit5",sxatp_stuffitx_cipher_extra_bit5_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit6_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_6",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_cipher_extra_bit6={UINT32_C(0x60890058),"stuffitx_cipher_extra_bit6",sxatp_stuffitx_cipher_extra_bit6_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_cipher_extra_bit7_fields[]={
 SX_FIELD("cipher_extra","stuffitx_p2_7",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_cipher_extra_bit7={UINT32_C(0x60890059),"stuffitx_cipher_extra_bit7",sxatp_stuffitx_cipher_extra_bit7_fields,SX_COUNT(sxatp_stuffitx_cipher_extra_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit0_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_0",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_fork_type_bit0={UINT32_C(0x6089005a),"stuffitx_fork_type_bit0",sxatp_stuffitx_fork_type_bit0_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit1_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_1",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_fork_type_bit1={UINT32_C(0x6089005b),"stuffitx_fork_type_bit1",sxatp_stuffitx_fork_type_bit1_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit2_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_2",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_fork_type_bit2={UINT32_C(0x6089005c),"stuffitx_fork_type_bit2",sxatp_stuffitx_fork_type_bit2_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit3_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_3",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_fork_type_bit3={UINT32_C(0x6089005d),"stuffitx_fork_type_bit3",sxatp_stuffitx_fork_type_bit3_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit4_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_4",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_fork_type_bit4={UINT32_C(0x6089005e),"stuffitx_fork_type_bit4",sxatp_stuffitx_fork_type_bit4_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit5_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_5",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_fork_type_bit5={UINT32_C(0x6089005f),"stuffitx_fork_type_bit5",sxatp_stuffitx_fork_type_bit5_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit6_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_6",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_fork_type_bit6={UINT32_C(0x60890060),"stuffitx_fork_type_bit6",sxatp_stuffitx_fork_type_bit6_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_fork_type_bit7_fields[]={
 SX_FIELD("fork_type","stuffitx_p2_7",0,0,SX_ID),
};
const sx_layout sxatp_stuffitx_fork_type_bit7={UINT32_C(0x60890061),"stuffitx_fork_type_bit7",sxatp_stuffitx_fork_type_bit7_fields,SX_COUNT(sxatp_stuffitx_fork_type_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit0_fields[]={
 SX_FIELD("root_value","stuffitx_p2_0",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_root_value_bit0={UINT32_C(0x60890062),"stuffitx_root_value_bit0",sxatp_stuffitx_root_value_bit0_fields,SX_COUNT(sxatp_stuffitx_root_value_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit1_fields[]={
 SX_FIELD("root_value","stuffitx_p2_1",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_root_value_bit1={UINT32_C(0x60890063),"stuffitx_root_value_bit1",sxatp_stuffitx_root_value_bit1_fields,SX_COUNT(sxatp_stuffitx_root_value_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit2_fields[]={
 SX_FIELD("root_value","stuffitx_p2_2",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_root_value_bit2={UINT32_C(0x60890064),"stuffitx_root_value_bit2",sxatp_stuffitx_root_value_bit2_fields,SX_COUNT(sxatp_stuffitx_root_value_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit3_fields[]={
 SX_FIELD("root_value","stuffitx_p2_3",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_root_value_bit3={UINT32_C(0x60890065),"stuffitx_root_value_bit3",sxatp_stuffitx_root_value_bit3_fields,SX_COUNT(sxatp_stuffitx_root_value_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit4_fields[]={
 SX_FIELD("root_value","stuffitx_p2_4",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_root_value_bit4={UINT32_C(0x60890066),"stuffitx_root_value_bit4",sxatp_stuffitx_root_value_bit4_fields,SX_COUNT(sxatp_stuffitx_root_value_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit5_fields[]={
 SX_FIELD("root_value","stuffitx_p2_5",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_root_value_bit5={UINT32_C(0x60890067),"stuffitx_root_value_bit5",sxatp_stuffitx_root_value_bit5_fields,SX_COUNT(sxatp_stuffitx_root_value_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit6_fields[]={
 SX_FIELD("root_value","stuffitx_p2_6",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_root_value_bit6={UINT32_C(0x60890068),"stuffitx_root_value_bit6",sxatp_stuffitx_root_value_bit6_fields,SX_COUNT(sxatp_stuffitx_root_value_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_root_value_bit7_fields[]={
 SX_FIELD("root_value","stuffitx_p2_7",0,0,SX_NONE),
};
const sx_layout sxatp_stuffitx_root_value_bit7={UINT32_C(0x60890069),"stuffitx_root_value_bit7",sxatp_stuffitx_root_value_bit7_fields,SX_COUNT(sxatp_stuffitx_root_value_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_block_size_bit0_fields[]={
 SX_FIELD("block_size","stuffitx_p2_0",0,0,SX_SIZE),
};
const sx_layout sxatp_stuffitx_block_size_bit0={UINT32_C(0x6089006a),"stuffitx_block_size_bit0",sxatp_stuffitx_block_size_bit0_fields,SX_COUNT(sxatp_stuffitx_block_size_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_trailer_size_bit0_fields[]={
 SX_FIELD("trailer_size","stuffitx_p2_0",0,0,SX_SIZE),
};
const sx_layout sxatp_stuffitx_trailer_size_bit0={UINT32_C(0x6089006b),"stuffitx_trailer_size_bit0",sxatp_stuffitx_trailer_size_bit0_fields,SX_COUNT(sxatp_stuffitx_trailer_size_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_stuffitx_crc32_fields[]={
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxatp_stuffitx_crc32={UINT32_C(0x6089006c),"stuffitx_crc32",sxatp_stuffitx_crc32_fields,SX_COUNT(sxatp_stuffitx_crc32_fields),SX_BE};
static const sx_layout*const sxatp_p2_element_type[8]={NULL,&sxatp_stuffitx_element_type_bit1,NULL,NULL,NULL,NULL,NULL,NULL};
static const sx_layout*const sxatp_p2_attribute_key[8]={&sxatp_stuffitx_attribute_key_bit0,&sxatp_stuffitx_attribute_key_bit1,&sxatp_stuffitx_attribute_key_bit2,&sxatp_stuffitx_attribute_key_bit3,&sxatp_stuffitx_attribute_key_bit4,&sxatp_stuffitx_attribute_key_bit5,&sxatp_stuffitx_attribute_key_bit6,&sxatp_stuffitx_attribute_key_bit7};
static const sx_layout*const sxatp_p2_object_id[8]={&sxatp_stuffitx_object_id_bit0,&sxatp_stuffitx_object_id_bit1,&sxatp_stuffitx_object_id_bit2,&sxatp_stuffitx_object_id_bit3,&sxatp_stuffitx_object_id_bit4,&sxatp_stuffitx_object_id_bit5,&sxatp_stuffitx_object_id_bit6,&sxatp_stuffitx_object_id_bit7};
static const sx_layout*const sxatp_p2_parent_id[8]={&sxatp_stuffitx_parent_id_bit0,&sxatp_stuffitx_parent_id_bit1,&sxatp_stuffitx_parent_id_bit2,&sxatp_stuffitx_parent_id_bit3,&sxatp_stuffitx_parent_id_bit4,&sxatp_stuffitx_parent_id_bit5,&sxatp_stuffitx_parent_id_bit6,&sxatp_stuffitx_parent_id_bit7};
static const sx_layout*const sxatp_p2_stream_id[8]={&sxatp_stuffitx_stream_id_bit0,&sxatp_stuffitx_stream_id_bit1,&sxatp_stuffitx_stream_id_bit2,&sxatp_stuffitx_stream_id_bit3,&sxatp_stuffitx_stream_id_bit4,&sxatp_stuffitx_stream_id_bit5,&sxatp_stuffitx_stream_id_bit6,&sxatp_stuffitx_stream_id_bit7};
static const sx_layout*const sxatp_p2_fork_index[8]={&sxatp_stuffitx_fork_index_bit0,&sxatp_stuffitx_fork_index_bit1,&sxatp_stuffitx_fork_index_bit2,&sxatp_stuffitx_fork_index_bit3,&sxatp_stuffitx_fork_index_bit4,&sxatp_stuffitx_fork_index_bit5,&sxatp_stuffitx_fork_index_bit6,&sxatp_stuffitx_fork_index_bit7};
static const sx_layout*const sxatp_p2_declared_size[8]={&sxatp_stuffitx_declared_size_bit0,&sxatp_stuffitx_declared_size_bit1,&sxatp_stuffitx_declared_size_bit2,&sxatp_stuffitx_declared_size_bit3,&sxatp_stuffitx_declared_size_bit4,&sxatp_stuffitx_declared_size_bit5,&sxatp_stuffitx_declared_size_bit6,&sxatp_stuffitx_declared_size_bit7};
static const sx_layout*const sxatp_p2_attribute_value[8]={&sxatp_stuffitx_attribute_value_bit0,&sxatp_stuffitx_attribute_value_bit1,&sxatp_stuffitx_attribute_value_bit2,&sxatp_stuffitx_attribute_value_bit3,&sxatp_stuffitx_attribute_value_bit4,&sxatp_stuffitx_attribute_value_bit5,&sxatp_stuffitx_attribute_value_bit6,&sxatp_stuffitx_attribute_value_bit7};
static const sx_layout*const sxatp_p2_algorithm_key[8]={&sxatp_stuffitx_algorithm_key_bit0,&sxatp_stuffitx_algorithm_key_bit1,&sxatp_stuffitx_algorithm_key_bit2,&sxatp_stuffitx_algorithm_key_bit3,&sxatp_stuffitx_algorithm_key_bit4,&sxatp_stuffitx_algorithm_key_bit5,&sxatp_stuffitx_algorithm_key_bit6,&sxatp_stuffitx_algorithm_key_bit7};
static const sx_layout*const sxatp_p2_algorithm_value[8]={&sxatp_stuffitx_algorithm_value_bit0,&sxatp_stuffitx_algorithm_value_bit1,&sxatp_stuffitx_algorithm_value_bit2,&sxatp_stuffitx_algorithm_value_bit3,&sxatp_stuffitx_algorithm_value_bit4,&sxatp_stuffitx_algorithm_value_bit5,&sxatp_stuffitx_algorithm_value_bit6,&sxatp_stuffitx_algorithm_value_bit7};
static const sx_layout*const sxatp_p2_cipher_extra[8]={&sxatp_stuffitx_cipher_extra_bit0,&sxatp_stuffitx_cipher_extra_bit1,&sxatp_stuffitx_cipher_extra_bit2,&sxatp_stuffitx_cipher_extra_bit3,&sxatp_stuffitx_cipher_extra_bit4,&sxatp_stuffitx_cipher_extra_bit5,&sxatp_stuffitx_cipher_extra_bit6,&sxatp_stuffitx_cipher_extra_bit7};
static const sx_layout*const sxatp_p2_fork_type[8]={&sxatp_stuffitx_fork_type_bit0,&sxatp_stuffitx_fork_type_bit1,&sxatp_stuffitx_fork_type_bit2,&sxatp_stuffitx_fork_type_bit3,&sxatp_stuffitx_fork_type_bit4,&sxatp_stuffitx_fork_type_bit5,&sxatp_stuffitx_fork_type_bit6,&sxatp_stuffitx_fork_type_bit7};
static const sx_layout*const sxatp_p2_root_value[8]={&sxatp_stuffitx_root_value_bit0,&sxatp_stuffitx_root_value_bit1,&sxatp_stuffitx_root_value_bit2,&sxatp_stuffitx_root_value_bit3,&sxatp_stuffitx_root_value_bit4,&sxatp_stuffitx_root_value_bit5,&sxatp_stuffitx_root_value_bit6,&sxatp_stuffitx_root_value_bit7};
static const sx_layout*const sxatp_p2_block_size[8]={&sxatp_stuffitx_block_size_bit0,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
static const sx_layout*const sxatp_p2_trailer_size[8]={&sxatp_stuffitx_trailer_size_bit0,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
typedef struct sxatp_bits{uint64_t pos;unsigned bit;}sxatp_bits;
static void sxatp_align(sxatp_bits*b){if(b->bit){b->pos++;b->bit=0;}}
static bool sxatp_bit(sx_context*c,sxatp_bits*b,unsigned*v){uint8_t x;if(!sxatp_read(c,b->pos,&x,1))return false;*v=(x>>b->bit)&1U;if(++b->bit==8){b->pos++;b->bit=0;}return true;}
static bool sxatp_p2(sx_context*c,sxatp_bits*b,const sx_layout*const rows[8],uint64_t*v){sxatp_bits first=*b;unsigned ones=1,pos=0,x;uint64_t value=0;for(;;){if(!sxatp_bit(c,b,&x))return false;if(!x)break;if(++ones>=64)return false;}while(ones){if(pos>=64||!sxatp_bit(c,b,&x))return false;if(x){value|=UINT64_C(1)<<pos;ones--;}pos++;}*v=value-1;uint64_t bytes=b->pos+(b->bit!=0)-first.pos;if(!bytes||bytes>17)return false;return sxatp_put(c,rows[first.bit],first.pos,bytes,true);}
static bool sxatp_sxblocks(sx_context*c,sxatp_bits*b){uint64_t n;sxatp_align(b);for(unsigned i=0;i<SXATP_LIMIT;i++){if(!sxatp_p2(c,b,sxatp_p2_block_size,&n))return false;if(!n)break;sxatp_align(b);if(!sxatp_span(c,b->pos,n))return false;b->pos+=n;}sxatp_align(b);bool first=true;for(unsigned i=0;i<SXATP_LIMIT;i++){if(!sxatp_p2(c,b,sxatp_p2_trailer_size,&n))return false;if(!n)return true;sxatp_align(b);if(!sxatp_span(c,b->pos,n))return false;if(first&&n==4&&!sxatp_add(c,&sxatp_stuffitx_crc32,b->pos))return false;b->pos+=n;first=false;}return false;}
static bool sxatp_stuffitx(sx_context*c){if(!sxatp_add(c,&sxatp_stuffitx_signature,0))return false;sxatp_bits b={8,0};for(unsigned e=0;e<SXATP_LIMIT;e++){sxatp_align(&b);if(!sxatp_put(c,&sxatp_stuffitx_element_flag,b.pos,1,true))return false;unsigned flag;if(!sxatp_bit(c,&b,&flag))return false;uint64_t type,key,value,size=0;bool has_size=false;if(!sxatp_p2(c,&b,sxatp_p2_element_type,&type))return false;for(unsigned k=0;;k++){if(k>256||!sxatp_p2(c,&b,sxatp_p2_attribute_key,&key))return false;if(!key)break;const sx_layout*const*rows=key==1?sxatp_p2_object_id:key==2?sxatp_p2_parent_id:key==3?sxatp_p2_stream_id:key==4?sxatp_p2_fork_index:key==5?sxatp_p2_declared_size:sxatp_p2_attribute_value;if(!sxatp_p2(c,&b,rows,&value))return false;if(key==5)size=value,has_size=true;}
 for(unsigned k=0;;k++){if(k>256||!sxatp_p2(c,&b,sxatp_p2_algorithm_key,&key))return false;if(!key)break;if(!sxatp_p2(c,&b,sxatp_p2_algorithm_value,&value))return false;if(key==4&&!sxatp_p2(c,&b,sxatp_p2_cipher_extra,&value))return false;}
 if(type==0)return true;if(type==1||type==5||type>10){if(!sxatp_sxblocks(c,&b))return false;}else if(type==3){if(!sxatp_p2(c,&b,sxatp_p2_fork_type,&value))return false;}else if(type==7){if(!sxatp_p2(c,&b,sxatp_p2_root_value,&value))return false;}else if(type==6){if(!has_size)return false;if(size){sxatp_align(&b);if(!sxatp_span(c,b.pos,size))return false;b.pos+=size;}}else if(type==10)return false;}return false;}
bool sx_stuffitx_build(sx_context*c)
{
 return sxatp_stuffitx(c);
}
