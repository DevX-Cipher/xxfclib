/* SPDX-License-Identifier: MIT. Physical wire fields; see permanent archivewire scope. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archivewire.h"
static const xx_data_struct_field_desc sxarwire_npack_signature_fields[]={
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
};
static const sx_layout sxarwire_npack_signature={UINT32_C(0x608d0001),"npack_signature",sxarwire_npack_signature_fields,SX_COUNT(sxarwire_npack_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_stac_signature_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxarwire_stac_signature={UINT32_C(0x608d0002),"stac_signature",sxarwire_stac_signature_fields,SX_COUNT(sxarwire_stac_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_is_match_bit0_fields[]={
 SX_FIELD("is_match","msb_bits[0,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_is_match_bit0={UINT32_C(0x608d0006),"lzs_is_match_bit0",sxarwire_lzs_is_match_bit0_fields,SX_COUNT(sxarwire_lzs_is_match_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_is_match_bit1_fields[]={
 SX_FIELD("is_match","msb_bits[1,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_is_match_bit1={UINT32_C(0x608d0007),"lzs_is_match_bit1",sxarwire_lzs_is_match_bit1_fields,SX_COUNT(sxarwire_lzs_is_match_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_is_match_bit2_fields[]={
 SX_FIELD("is_match","msb_bits[2,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_is_match_bit2={UINT32_C(0x608d0008),"lzs_is_match_bit2",sxarwire_lzs_is_match_bit2_fields,SX_COUNT(sxarwire_lzs_is_match_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_is_match_bit3_fields[]={
 SX_FIELD("is_match","msb_bits[3,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_is_match_bit3={UINT32_C(0x608d0009),"lzs_is_match_bit3",sxarwire_lzs_is_match_bit3_fields,SX_COUNT(sxarwire_lzs_is_match_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_is_match_bit4_fields[]={
 SX_FIELD("is_match","msb_bits[4,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_is_match_bit4={UINT32_C(0x608d000a),"lzs_is_match_bit4",sxarwire_lzs_is_match_bit4_fields,SX_COUNT(sxarwire_lzs_is_match_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_is_match_bit5_fields[]={
 SX_FIELD("is_match","msb_bits[5,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_is_match_bit5={UINT32_C(0x608d000b),"lzs_is_match_bit5",sxarwire_lzs_is_match_bit5_fields,SX_COUNT(sxarwire_lzs_is_match_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_is_match_bit6_fields[]={
 SX_FIELD("is_match","msb_bits[6,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_is_match_bit6={UINT32_C(0x608d000c),"lzs_is_match_bit6",sxarwire_lzs_is_match_bit6_fields,SX_COUNT(sxarwire_lzs_is_match_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_is_match_bit7_fields[]={
 SX_FIELD("is_match","msb_bits[7,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_is_match_bit7={UINT32_C(0x608d000d),"lzs_is_match_bit7",sxarwire_lzs_is_match_bit7_fields,SX_COUNT(sxarwire_lzs_is_match_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_short_distance_bit0_fields[]={
 SX_FIELD("short_distance","msb_bits[0,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_short_distance_bit0={UINT32_C(0x608d000e),"lzs_short_distance_bit0",sxarwire_lzs_short_distance_bit0_fields,SX_COUNT(sxarwire_lzs_short_distance_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_short_distance_bit1_fields[]={
 SX_FIELD("short_distance","msb_bits[1,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_short_distance_bit1={UINT32_C(0x608d000f),"lzs_short_distance_bit1",sxarwire_lzs_short_distance_bit1_fields,SX_COUNT(sxarwire_lzs_short_distance_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_short_distance_bit2_fields[]={
 SX_FIELD("short_distance","msb_bits[2,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_short_distance_bit2={UINT32_C(0x608d0010),"lzs_short_distance_bit2",sxarwire_lzs_short_distance_bit2_fields,SX_COUNT(sxarwire_lzs_short_distance_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_short_distance_bit3_fields[]={
 SX_FIELD("short_distance","msb_bits[3,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_short_distance_bit3={UINT32_C(0x608d0011),"lzs_short_distance_bit3",sxarwire_lzs_short_distance_bit3_fields,SX_COUNT(sxarwire_lzs_short_distance_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_short_distance_bit4_fields[]={
 SX_FIELD("short_distance","msb_bits[4,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_short_distance_bit4={UINT32_C(0x608d0012),"lzs_short_distance_bit4",sxarwire_lzs_short_distance_bit4_fields,SX_COUNT(sxarwire_lzs_short_distance_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_short_distance_bit5_fields[]={
 SX_FIELD("short_distance","msb_bits[5,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_short_distance_bit5={UINT32_C(0x608d0013),"lzs_short_distance_bit5",sxarwire_lzs_short_distance_bit5_fields,SX_COUNT(sxarwire_lzs_short_distance_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_short_distance_bit6_fields[]={
 SX_FIELD("short_distance","msb_bits[6,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_short_distance_bit6={UINT32_C(0x608d0014),"lzs_short_distance_bit6",sxarwire_lzs_short_distance_bit6_fields,SX_COUNT(sxarwire_lzs_short_distance_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_short_distance_bit7_fields[]={
 SX_FIELD("short_distance","msb_bits[7,1]",0,1,SX_FLAGS),
};
static const sx_layout sxarwire_lzs_short_distance_bit7={UINT32_C(0x608d0015),"lzs_short_distance_bit7",sxarwire_lzs_short_distance_bit7_fields,SX_COUNT(sxarwire_lzs_short_distance_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_literal_bit0_fields[]={
 SX_FIELD("literal_byte","msb_bits[0,8]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_literal_bit0={UINT32_C(0x608d0016),"lzs_literal_bit0",sxarwire_lzs_literal_bit0_fields,SX_COUNT(sxarwire_lzs_literal_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_literal_bit1_fields[]={
 SX_FIELD("literal_byte","msb_bits[1,8]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_literal_bit1={UINT32_C(0x608d0017),"lzs_literal_bit1",sxarwire_lzs_literal_bit1_fields,SX_COUNT(sxarwire_lzs_literal_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_literal_bit2_fields[]={
 SX_FIELD("literal_byte","msb_bits[2,8]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_literal_bit2={UINT32_C(0x608d0018),"lzs_literal_bit2",sxarwire_lzs_literal_bit2_fields,SX_COUNT(sxarwire_lzs_literal_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_literal_bit3_fields[]={
 SX_FIELD("literal_byte","msb_bits[3,8]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_literal_bit3={UINT32_C(0x608d0019),"lzs_literal_bit3",sxarwire_lzs_literal_bit3_fields,SX_COUNT(sxarwire_lzs_literal_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_literal_bit4_fields[]={
 SX_FIELD("literal_byte","msb_bits[4,8]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_literal_bit4={UINT32_C(0x608d001a),"lzs_literal_bit4",sxarwire_lzs_literal_bit4_fields,SX_COUNT(sxarwire_lzs_literal_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_literal_bit5_fields[]={
 SX_FIELD("literal_byte","msb_bits[5,8]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_literal_bit5={UINT32_C(0x608d001b),"lzs_literal_bit5",sxarwire_lzs_literal_bit5_fields,SX_COUNT(sxarwire_lzs_literal_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_literal_bit6_fields[]={
 SX_FIELD("literal_byte","msb_bits[6,8]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_literal_bit6={UINT32_C(0x608d001c),"lzs_literal_bit6",sxarwire_lzs_literal_bit6_fields,SX_COUNT(sxarwire_lzs_literal_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_literal_bit7_fields[]={
 SX_FIELD("literal_byte","msb_bits[7,8]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_literal_bit7={UINT32_C(0x608d001d),"lzs_literal_bit7",sxarwire_lzs_literal_bit7_fields,SX_COUNT(sxarwire_lzs_literal_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance7_bit0_fields[]={
 SX_FIELD("distance","msb_bits[0,7]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance7_bit0={UINT32_C(0x608d001e),"lzs_distance7_bit0",sxarwire_lzs_distance7_bit0_fields,SX_COUNT(sxarwire_lzs_distance7_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance7_bit1_fields[]={
 SX_FIELD("distance","msb_bits[1,7]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance7_bit1={UINT32_C(0x608d001f),"lzs_distance7_bit1",sxarwire_lzs_distance7_bit1_fields,SX_COUNT(sxarwire_lzs_distance7_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance7_bit2_fields[]={
 SX_FIELD("distance","msb_bits[2,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance7_bit2={UINT32_C(0x608d0020),"lzs_distance7_bit2",sxarwire_lzs_distance7_bit2_fields,SX_COUNT(sxarwire_lzs_distance7_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance7_bit3_fields[]={
 SX_FIELD("distance","msb_bits[3,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance7_bit3={UINT32_C(0x608d0021),"lzs_distance7_bit3",sxarwire_lzs_distance7_bit3_fields,SX_COUNT(sxarwire_lzs_distance7_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance7_bit4_fields[]={
 SX_FIELD("distance","msb_bits[4,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance7_bit4={UINT32_C(0x608d0022),"lzs_distance7_bit4",sxarwire_lzs_distance7_bit4_fields,SX_COUNT(sxarwire_lzs_distance7_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance7_bit5_fields[]={
 SX_FIELD("distance","msb_bits[5,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance7_bit5={UINT32_C(0x608d0023),"lzs_distance7_bit5",sxarwire_lzs_distance7_bit5_fields,SX_COUNT(sxarwire_lzs_distance7_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance7_bit6_fields[]={
 SX_FIELD("distance","msb_bits[6,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance7_bit6={UINT32_C(0x608d0024),"lzs_distance7_bit6",sxarwire_lzs_distance7_bit6_fields,SX_COUNT(sxarwire_lzs_distance7_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance7_bit7_fields[]={
 SX_FIELD("distance","msb_bits[7,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance7_bit7={UINT32_C(0x608d0025),"lzs_distance7_bit7",sxarwire_lzs_distance7_bit7_fields,SX_COUNT(sxarwire_lzs_distance7_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance11_bit0_fields[]={
 SX_FIELD("distance","msb_bits[0,11]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance11_bit0={UINT32_C(0x608d0026),"lzs_distance11_bit0",sxarwire_lzs_distance11_bit0_fields,SX_COUNT(sxarwire_lzs_distance11_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance11_bit1_fields[]={
 SX_FIELD("distance","msb_bits[1,11]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance11_bit1={UINT32_C(0x608d0027),"lzs_distance11_bit1",sxarwire_lzs_distance11_bit1_fields,SX_COUNT(sxarwire_lzs_distance11_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance11_bit2_fields[]={
 SX_FIELD("distance","msb_bits[2,11]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance11_bit2={UINT32_C(0x608d0028),"lzs_distance11_bit2",sxarwire_lzs_distance11_bit2_fields,SX_COUNT(sxarwire_lzs_distance11_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance11_bit3_fields[]={
 SX_FIELD("distance","msb_bits[3,11]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance11_bit3={UINT32_C(0x608d0029),"lzs_distance11_bit3",sxarwire_lzs_distance11_bit3_fields,SX_COUNT(sxarwire_lzs_distance11_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance11_bit4_fields[]={
 SX_FIELD("distance","msb_bits[4,11]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance11_bit4={UINT32_C(0x608d002a),"lzs_distance11_bit4",sxarwire_lzs_distance11_bit4_fields,SX_COUNT(sxarwire_lzs_distance11_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance11_bit5_fields[]={
 SX_FIELD("distance","msb_bits[5,11]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance11_bit5={UINT32_C(0x608d002b),"lzs_distance11_bit5",sxarwire_lzs_distance11_bit5_fields,SX_COUNT(sxarwire_lzs_distance11_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance11_bit6_fields[]={
 SX_FIELD("distance","msb_bits[6,11]",0,3,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance11_bit6={UINT32_C(0x608d002c),"lzs_distance11_bit6",sxarwire_lzs_distance11_bit6_fields,SX_COUNT(sxarwire_lzs_distance11_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_distance11_bit7_fields[]={
 SX_FIELD("distance","msb_bits[7,11]",0,3,SX_NONE),
};
static const sx_layout sxarwire_lzs_distance11_bit7={UINT32_C(0x608d002d),"lzs_distance11_bit7",sxarwire_lzs_distance11_bit7_fields,SX_COUNT(sxarwire_lzs_distance11_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_prefix_bit0_fields[]={
 SX_FIELD("length_prefix","msb_bits[0,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_prefix_bit0={UINT32_C(0x608d002e),"lzs_length_prefix_bit0",sxarwire_lzs_length_prefix_bit0_fields,SX_COUNT(sxarwire_lzs_length_prefix_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_prefix_bit1_fields[]={
 SX_FIELD("length_prefix","msb_bits[1,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_prefix_bit1={UINT32_C(0x608d002f),"lzs_length_prefix_bit1",sxarwire_lzs_length_prefix_bit1_fields,SX_COUNT(sxarwire_lzs_length_prefix_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_prefix_bit2_fields[]={
 SX_FIELD("length_prefix","msb_bits[2,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_prefix_bit2={UINT32_C(0x608d0030),"lzs_length_prefix_bit2",sxarwire_lzs_length_prefix_bit2_fields,SX_COUNT(sxarwire_lzs_length_prefix_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_prefix_bit3_fields[]={
 SX_FIELD("length_prefix","msb_bits[3,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_prefix_bit3={UINT32_C(0x608d0031),"lzs_length_prefix_bit3",sxarwire_lzs_length_prefix_bit3_fields,SX_COUNT(sxarwire_lzs_length_prefix_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_prefix_bit4_fields[]={
 SX_FIELD("length_prefix","msb_bits[4,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_prefix_bit4={UINT32_C(0x608d0032),"lzs_length_prefix_bit4",sxarwire_lzs_length_prefix_bit4_fields,SX_COUNT(sxarwire_lzs_length_prefix_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_prefix_bit5_fields[]={
 SX_FIELD("length_prefix","msb_bits[5,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_prefix_bit5={UINT32_C(0x608d0033),"lzs_length_prefix_bit5",sxarwire_lzs_length_prefix_bit5_fields,SX_COUNT(sxarwire_lzs_length_prefix_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_prefix_bit6_fields[]={
 SX_FIELD("length_prefix","msb_bits[6,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_prefix_bit6={UINT32_C(0x608d0034),"lzs_length_prefix_bit6",sxarwire_lzs_length_prefix_bit6_fields,SX_COUNT(sxarwire_lzs_length_prefix_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_prefix_bit7_fields[]={
 SX_FIELD("length_prefix","msb_bits[7,2]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_prefix_bit7={UINT32_C(0x608d0035),"lzs_length_prefix_bit7",sxarwire_lzs_length_prefix_bit7_fields,SX_COUNT(sxarwire_lzs_length_prefix_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_secondary_bit0_fields[]={
 SX_FIELD("length_secondary","msb_bits[0,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_secondary_bit0={UINT32_C(0x608d0036),"lzs_length_secondary_bit0",sxarwire_lzs_length_secondary_bit0_fields,SX_COUNT(sxarwire_lzs_length_secondary_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_secondary_bit1_fields[]={
 SX_FIELD("length_secondary","msb_bits[1,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_secondary_bit1={UINT32_C(0x608d0037),"lzs_length_secondary_bit1",sxarwire_lzs_length_secondary_bit1_fields,SX_COUNT(sxarwire_lzs_length_secondary_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_secondary_bit2_fields[]={
 SX_FIELD("length_secondary","msb_bits[2,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_secondary_bit2={UINT32_C(0x608d0038),"lzs_length_secondary_bit2",sxarwire_lzs_length_secondary_bit2_fields,SX_COUNT(sxarwire_lzs_length_secondary_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_secondary_bit3_fields[]={
 SX_FIELD("length_secondary","msb_bits[3,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_secondary_bit3={UINT32_C(0x608d0039),"lzs_length_secondary_bit3",sxarwire_lzs_length_secondary_bit3_fields,SX_COUNT(sxarwire_lzs_length_secondary_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_secondary_bit4_fields[]={
 SX_FIELD("length_secondary","msb_bits[4,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_secondary_bit4={UINT32_C(0x608d003a),"lzs_length_secondary_bit4",sxarwire_lzs_length_secondary_bit4_fields,SX_COUNT(sxarwire_lzs_length_secondary_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_secondary_bit5_fields[]={
 SX_FIELD("length_secondary","msb_bits[5,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_secondary_bit5={UINT32_C(0x608d003b),"lzs_length_secondary_bit5",sxarwire_lzs_length_secondary_bit5_fields,SX_COUNT(sxarwire_lzs_length_secondary_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_secondary_bit6_fields[]={
 SX_FIELD("length_secondary","msb_bits[6,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_secondary_bit6={UINT32_C(0x608d003c),"lzs_length_secondary_bit6",sxarwire_lzs_length_secondary_bit6_fields,SX_COUNT(sxarwire_lzs_length_secondary_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_secondary_bit7_fields[]={
 SX_FIELD("length_secondary","msb_bits[7,2]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_secondary_bit7={UINT32_C(0x608d003d),"lzs_length_secondary_bit7",sxarwire_lzs_length_secondary_bit7_fields,SX_COUNT(sxarwire_lzs_length_secondary_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_extension_bit0_fields[]={
 SX_FIELD("length_extension","msb_bits[0,4]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_extension_bit0={UINT32_C(0x608d003e),"lzs_length_extension_bit0",sxarwire_lzs_length_extension_bit0_fields,SX_COUNT(sxarwire_lzs_length_extension_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_extension_bit1_fields[]={
 SX_FIELD("length_extension","msb_bits[1,4]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_extension_bit1={UINT32_C(0x608d003f),"lzs_length_extension_bit1",sxarwire_lzs_length_extension_bit1_fields,SX_COUNT(sxarwire_lzs_length_extension_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_extension_bit2_fields[]={
 SX_FIELD("length_extension","msb_bits[2,4]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_extension_bit2={UINT32_C(0x608d0040),"lzs_length_extension_bit2",sxarwire_lzs_length_extension_bit2_fields,SX_COUNT(sxarwire_lzs_length_extension_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_extension_bit3_fields[]={
 SX_FIELD("length_extension","msb_bits[3,4]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_extension_bit3={UINT32_C(0x608d0041),"lzs_length_extension_bit3",sxarwire_lzs_length_extension_bit3_fields,SX_COUNT(sxarwire_lzs_length_extension_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_extension_bit4_fields[]={
 SX_FIELD("length_extension","msb_bits[4,4]",0,1,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_extension_bit4={UINT32_C(0x608d0042),"lzs_length_extension_bit4",sxarwire_lzs_length_extension_bit4_fields,SX_COUNT(sxarwire_lzs_length_extension_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_extension_bit5_fields[]={
 SX_FIELD("length_extension","msb_bits[5,4]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_extension_bit5={UINT32_C(0x608d0043),"lzs_length_extension_bit5",sxarwire_lzs_length_extension_bit5_fields,SX_COUNT(sxarwire_lzs_length_extension_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_extension_bit6_fields[]={
 SX_FIELD("length_extension","msb_bits[6,4]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_extension_bit6={UINT32_C(0x608d0044),"lzs_length_extension_bit6",sxarwire_lzs_length_extension_bit6_fields,SX_COUNT(sxarwire_lzs_length_extension_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzs_length_extension_bit7_fields[]={
 SX_FIELD("length_extension","msb_bits[7,4]",0,2,SX_NONE),
};
static const sx_layout sxarwire_lzs_length_extension_bit7={UINT32_C(0x608d0045),"lzs_length_extension_bit7",sxarwire_lzs_length_extension_bit7_fields,SX_COUNT(sxarwire_lzs_length_extension_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix1_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix1_bit0={UINT32_C(0x608d01d6),"sco_table_prefix1_bit0",sxarwire_sco_table_prefix1_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix1_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix1_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix1_bit1={UINT32_C(0x608d01d7),"sco_table_prefix1_bit1",sxarwire_sco_table_prefix1_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix1_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix1_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix1_bit2={UINT32_C(0x608d01d8),"sco_table_prefix1_bit2",sxarwire_sco_table_prefix1_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix1_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix1_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix1_bit3={UINT32_C(0x608d01d9),"sco_table_prefix1_bit3",sxarwire_sco_table_prefix1_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix1_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix1_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix1_bit4={UINT32_C(0x608d01da),"sco_table_prefix1_bit4",sxarwire_sco_table_prefix1_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix1_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix1_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix1_bit5={UINT32_C(0x608d01db),"sco_table_prefix1_bit5",sxarwire_sco_table_prefix1_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix1_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix1_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix1_bit6={UINT32_C(0x608d01dc),"sco_table_prefix1_bit6",sxarwire_sco_table_prefix1_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix1_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix1_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix1_bit7={UINT32_C(0x608d01dd),"sco_table_prefix1_bit7",sxarwire_sco_table_prefix1_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix1_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix2_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix2_bit0={UINT32_C(0x608d01de),"sco_table_prefix2_bit0",sxarwire_sco_table_prefix2_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix2_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix2_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix2_bit1={UINT32_C(0x608d01df),"sco_table_prefix2_bit1",sxarwire_sco_table_prefix2_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix2_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix2_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix2_bit2={UINT32_C(0x608d01e0),"sco_table_prefix2_bit2",sxarwire_sco_table_prefix2_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix2_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix2_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix2_bit3={UINT32_C(0x608d01e1),"sco_table_prefix2_bit3",sxarwire_sco_table_prefix2_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix2_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix2_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix2_bit4={UINT32_C(0x608d01e2),"sco_table_prefix2_bit4",sxarwire_sco_table_prefix2_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix2_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix2_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix2_bit5={UINT32_C(0x608d01e3),"sco_table_prefix2_bit5",sxarwire_sco_table_prefix2_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix2_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix2_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix2_bit6={UINT32_C(0x608d01e4),"sco_table_prefix2_bit6",sxarwire_sco_table_prefix2_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix2_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix2_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,2]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix2_bit7={UINT32_C(0x608d01e5),"sco_table_prefix2_bit7",sxarwire_sco_table_prefix2_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix2_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix3_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,3]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix3_bit0={UINT32_C(0x608d01e6),"sco_table_prefix3_bit0",sxarwire_sco_table_prefix3_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix3_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix3_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,3]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix3_bit1={UINT32_C(0x608d01e7),"sco_table_prefix3_bit1",sxarwire_sco_table_prefix3_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix3_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix3_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,3]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix3_bit2={UINT32_C(0x608d01e8),"sco_table_prefix3_bit2",sxarwire_sco_table_prefix3_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix3_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix3_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,3]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix3_bit3={UINT32_C(0x608d01e9),"sco_table_prefix3_bit3",sxarwire_sco_table_prefix3_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix3_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix3_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,3]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix3_bit4={UINT32_C(0x608d01ea),"sco_table_prefix3_bit4",sxarwire_sco_table_prefix3_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix3_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix3_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,3]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix3_bit5={UINT32_C(0x608d01eb),"sco_table_prefix3_bit5",sxarwire_sco_table_prefix3_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix3_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix3_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,3]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix3_bit6={UINT32_C(0x608d01ec),"sco_table_prefix3_bit6",sxarwire_sco_table_prefix3_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix3_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix3_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,3]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix3_bit7={UINT32_C(0x608d01ed),"sco_table_prefix3_bit7",sxarwire_sco_table_prefix3_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix3_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix4_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,4]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix4_bit0={UINT32_C(0x608d01ee),"sco_table_prefix4_bit0",sxarwire_sco_table_prefix4_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix4_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix4_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,4]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix4_bit1={UINT32_C(0x608d01ef),"sco_table_prefix4_bit1",sxarwire_sco_table_prefix4_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix4_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix4_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,4]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix4_bit2={UINT32_C(0x608d01f0),"sco_table_prefix4_bit2",sxarwire_sco_table_prefix4_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix4_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix4_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,4]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix4_bit3={UINT32_C(0x608d01f1),"sco_table_prefix4_bit3",sxarwire_sco_table_prefix4_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix4_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix4_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,4]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix4_bit4={UINT32_C(0x608d01f2),"sco_table_prefix4_bit4",sxarwire_sco_table_prefix4_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix4_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix4_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,4]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix4_bit5={UINT32_C(0x608d01f3),"sco_table_prefix4_bit5",sxarwire_sco_table_prefix4_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix4_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix4_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,4]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix4_bit6={UINT32_C(0x608d01f4),"sco_table_prefix4_bit6",sxarwire_sco_table_prefix4_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix4_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix4_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,4]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix4_bit7={UINT32_C(0x608d01f5),"sco_table_prefix4_bit7",sxarwire_sco_table_prefix4_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix4_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix5_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,5]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix5_bit0={UINT32_C(0x608d01f6),"sco_table_prefix5_bit0",sxarwire_sco_table_prefix5_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix5_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix5_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,5]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix5_bit1={UINT32_C(0x608d01f7),"sco_table_prefix5_bit1",sxarwire_sco_table_prefix5_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix5_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix5_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,5]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix5_bit2={UINT32_C(0x608d01f8),"sco_table_prefix5_bit2",sxarwire_sco_table_prefix5_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix5_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix5_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,5]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix5_bit3={UINT32_C(0x608d01f9),"sco_table_prefix5_bit3",sxarwire_sco_table_prefix5_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix5_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix5_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,5]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix5_bit4={UINT32_C(0x608d01fa),"sco_table_prefix5_bit4",sxarwire_sco_table_prefix5_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix5_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix5_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,5]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix5_bit5={UINT32_C(0x608d01fb),"sco_table_prefix5_bit5",sxarwire_sco_table_prefix5_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix5_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix5_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,5]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix5_bit6={UINT32_C(0x608d01fc),"sco_table_prefix5_bit6",sxarwire_sco_table_prefix5_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix5_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix5_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,5]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix5_bit7={UINT32_C(0x608d01fd),"sco_table_prefix5_bit7",sxarwire_sco_table_prefix5_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix5_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix6_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,6]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix6_bit0={UINT32_C(0x608d01fe),"sco_table_prefix6_bit0",sxarwire_sco_table_prefix6_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix6_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix6_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,6]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix6_bit1={UINT32_C(0x608d01ff),"sco_table_prefix6_bit1",sxarwire_sco_table_prefix6_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix6_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix6_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,6]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix6_bit2={UINT32_C(0x608d0200),"sco_table_prefix6_bit2",sxarwire_sco_table_prefix6_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix6_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix6_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,6]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix6_bit3={UINT32_C(0x608d0201),"sco_table_prefix6_bit3",sxarwire_sco_table_prefix6_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix6_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix6_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,6]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix6_bit4={UINT32_C(0x608d0202),"sco_table_prefix6_bit4",sxarwire_sco_table_prefix6_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix6_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix6_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,6]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix6_bit5={UINT32_C(0x608d0203),"sco_table_prefix6_bit5",sxarwire_sco_table_prefix6_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix6_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix6_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,6]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix6_bit6={UINT32_C(0x608d0204),"sco_table_prefix6_bit6",sxarwire_sco_table_prefix6_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix6_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix6_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,6]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix6_bit7={UINT32_C(0x608d0205),"sco_table_prefix6_bit7",sxarwire_sco_table_prefix6_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix6_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix7_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,7]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix7_bit0={UINT32_C(0x608d0206),"sco_table_prefix7_bit0",sxarwire_sco_table_prefix7_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix7_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix7_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,7]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix7_bit1={UINT32_C(0x608d0207),"sco_table_prefix7_bit1",sxarwire_sco_table_prefix7_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix7_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix7_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix7_bit2={UINT32_C(0x608d0208),"sco_table_prefix7_bit2",sxarwire_sco_table_prefix7_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix7_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix7_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix7_bit3={UINT32_C(0x608d0209),"sco_table_prefix7_bit3",sxarwire_sco_table_prefix7_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix7_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix7_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix7_bit4={UINT32_C(0x608d020a),"sco_table_prefix7_bit4",sxarwire_sco_table_prefix7_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix7_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix7_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix7_bit5={UINT32_C(0x608d020b),"sco_table_prefix7_bit5",sxarwire_sco_table_prefix7_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix7_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix7_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix7_bit6={UINT32_C(0x608d020c),"sco_table_prefix7_bit6",sxarwire_sco_table_prefix7_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix7_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix7_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix7_bit7={UINT32_C(0x608d020d),"sco_table_prefix7_bit7",sxarwire_sco_table_prefix7_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix7_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix8_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,8]",0,1,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix8_bit0={UINT32_C(0x608d020e),"sco_table_prefix8_bit0",sxarwire_sco_table_prefix8_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix8_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix8_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,8]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix8_bit1={UINT32_C(0x608d020f),"sco_table_prefix8_bit1",sxarwire_sco_table_prefix8_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix8_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix8_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,8]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix8_bit2={UINT32_C(0x608d0210),"sco_table_prefix8_bit2",sxarwire_sco_table_prefix8_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix8_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix8_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,8]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix8_bit3={UINT32_C(0x608d0211),"sco_table_prefix8_bit3",sxarwire_sco_table_prefix8_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix8_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix8_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,8]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix8_bit4={UINT32_C(0x608d0212),"sco_table_prefix8_bit4",sxarwire_sco_table_prefix8_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix8_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix8_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,8]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix8_bit5={UINT32_C(0x608d0213),"sco_table_prefix8_bit5",sxarwire_sco_table_prefix8_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix8_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix8_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,8]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix8_bit6={UINT32_C(0x608d0214),"sco_table_prefix8_bit6",sxarwire_sco_table_prefix8_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix8_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix8_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,8]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix8_bit7={UINT32_C(0x608d0215),"sco_table_prefix8_bit7",sxarwire_sco_table_prefix8_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix8_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix9_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,9]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix9_bit0={UINT32_C(0x608d0216),"sco_table_prefix9_bit0",sxarwire_sco_table_prefix9_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix9_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix9_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,9]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix9_bit1={UINT32_C(0x608d0217),"sco_table_prefix9_bit1",sxarwire_sco_table_prefix9_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix9_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix9_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,9]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix9_bit2={UINT32_C(0x608d0218),"sco_table_prefix9_bit2",sxarwire_sco_table_prefix9_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix9_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix9_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,9]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix9_bit3={UINT32_C(0x608d0219),"sco_table_prefix9_bit3",sxarwire_sco_table_prefix9_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix9_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix9_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,9]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix9_bit4={UINT32_C(0x608d021a),"sco_table_prefix9_bit4",sxarwire_sco_table_prefix9_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix9_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix9_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,9]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix9_bit5={UINT32_C(0x608d021b),"sco_table_prefix9_bit5",sxarwire_sco_table_prefix9_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix9_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix9_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,9]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix9_bit6={UINT32_C(0x608d021c),"sco_table_prefix9_bit6",sxarwire_sco_table_prefix9_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix9_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix9_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,9]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix9_bit7={UINT32_C(0x608d021d),"sco_table_prefix9_bit7",sxarwire_sco_table_prefix9_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix9_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix10_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,10]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix10_bit0={UINT32_C(0x608d021e),"sco_table_prefix10_bit0",sxarwire_sco_table_prefix10_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix10_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix10_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,10]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix10_bit1={UINT32_C(0x608d021f),"sco_table_prefix10_bit1",sxarwire_sco_table_prefix10_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix10_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix10_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,10]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix10_bit2={UINT32_C(0x608d0220),"sco_table_prefix10_bit2",sxarwire_sco_table_prefix10_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix10_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix10_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,10]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix10_bit3={UINT32_C(0x608d0221),"sco_table_prefix10_bit3",sxarwire_sco_table_prefix10_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix10_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix10_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,10]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix10_bit4={UINT32_C(0x608d0222),"sco_table_prefix10_bit4",sxarwire_sco_table_prefix10_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix10_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix10_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,10]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix10_bit5={UINT32_C(0x608d0223),"sco_table_prefix10_bit5",sxarwire_sco_table_prefix10_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix10_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix10_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,10]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix10_bit6={UINT32_C(0x608d0224),"sco_table_prefix10_bit6",sxarwire_sco_table_prefix10_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix10_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix10_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,10]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix10_bit7={UINT32_C(0x608d0225),"sco_table_prefix10_bit7",sxarwire_sco_table_prefix10_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix10_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix11_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,11]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix11_bit0={UINT32_C(0x608d0226),"sco_table_prefix11_bit0",sxarwire_sco_table_prefix11_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix11_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix11_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,11]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix11_bit1={UINT32_C(0x608d0227),"sco_table_prefix11_bit1",sxarwire_sco_table_prefix11_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix11_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix11_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,11]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix11_bit2={UINT32_C(0x608d0228),"sco_table_prefix11_bit2",sxarwire_sco_table_prefix11_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix11_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix11_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,11]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix11_bit3={UINT32_C(0x608d0229),"sco_table_prefix11_bit3",sxarwire_sco_table_prefix11_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix11_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix11_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,11]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix11_bit4={UINT32_C(0x608d022a),"sco_table_prefix11_bit4",sxarwire_sco_table_prefix11_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix11_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix11_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,11]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix11_bit5={UINT32_C(0x608d022b),"sco_table_prefix11_bit5",sxarwire_sco_table_prefix11_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix11_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix11_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,11]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix11_bit6={UINT32_C(0x608d022c),"sco_table_prefix11_bit6",sxarwire_sco_table_prefix11_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix11_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix11_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,11]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix11_bit7={UINT32_C(0x608d022d),"sco_table_prefix11_bit7",sxarwire_sco_table_prefix11_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix11_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix12_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,12]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix12_bit0={UINT32_C(0x608d022e),"sco_table_prefix12_bit0",sxarwire_sco_table_prefix12_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix12_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix12_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,12]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix12_bit1={UINT32_C(0x608d022f),"sco_table_prefix12_bit1",sxarwire_sco_table_prefix12_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix12_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix12_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,12]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix12_bit2={UINT32_C(0x608d0230),"sco_table_prefix12_bit2",sxarwire_sco_table_prefix12_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix12_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix12_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,12]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix12_bit3={UINT32_C(0x608d0231),"sco_table_prefix12_bit3",sxarwire_sco_table_prefix12_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix12_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix12_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,12]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix12_bit4={UINT32_C(0x608d0232),"sco_table_prefix12_bit4",sxarwire_sco_table_prefix12_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix12_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix12_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,12]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix12_bit5={UINT32_C(0x608d0233),"sco_table_prefix12_bit5",sxarwire_sco_table_prefix12_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix12_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix12_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,12]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix12_bit6={UINT32_C(0x608d0234),"sco_table_prefix12_bit6",sxarwire_sco_table_prefix12_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix12_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix12_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,12]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix12_bit7={UINT32_C(0x608d0235),"sco_table_prefix12_bit7",sxarwire_sco_table_prefix12_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix12_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix13_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,13]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix13_bit0={UINT32_C(0x608d0236),"sco_table_prefix13_bit0",sxarwire_sco_table_prefix13_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix13_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix13_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,13]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix13_bit1={UINT32_C(0x608d0237),"sco_table_prefix13_bit1",sxarwire_sco_table_prefix13_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix13_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix13_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,13]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix13_bit2={UINT32_C(0x608d0238),"sco_table_prefix13_bit2",sxarwire_sco_table_prefix13_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix13_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix13_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,13]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix13_bit3={UINT32_C(0x608d0239),"sco_table_prefix13_bit3",sxarwire_sco_table_prefix13_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix13_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix13_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,13]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix13_bit4={UINT32_C(0x608d023a),"sco_table_prefix13_bit4",sxarwire_sco_table_prefix13_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix13_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix13_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,13]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix13_bit5={UINT32_C(0x608d023b),"sco_table_prefix13_bit5",sxarwire_sco_table_prefix13_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix13_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix13_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,13]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix13_bit6={UINT32_C(0x608d023c),"sco_table_prefix13_bit6",sxarwire_sco_table_prefix13_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix13_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix13_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,13]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix13_bit7={UINT32_C(0x608d023d),"sco_table_prefix13_bit7",sxarwire_sco_table_prefix13_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix13_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix14_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,14]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix14_bit0={UINT32_C(0x608d023e),"sco_table_prefix14_bit0",sxarwire_sco_table_prefix14_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix14_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix14_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,14]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix14_bit1={UINT32_C(0x608d023f),"sco_table_prefix14_bit1",sxarwire_sco_table_prefix14_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix14_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix14_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,14]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix14_bit2={UINT32_C(0x608d0240),"sco_table_prefix14_bit2",sxarwire_sco_table_prefix14_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix14_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix14_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,14]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix14_bit3={UINT32_C(0x608d0241),"sco_table_prefix14_bit3",sxarwire_sco_table_prefix14_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix14_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix14_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,14]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix14_bit4={UINT32_C(0x608d0242),"sco_table_prefix14_bit4",sxarwire_sco_table_prefix14_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix14_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix14_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,14]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix14_bit5={UINT32_C(0x608d0243),"sco_table_prefix14_bit5",sxarwire_sco_table_prefix14_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix14_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix14_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,14]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix14_bit6={UINT32_C(0x608d0244),"sco_table_prefix14_bit6",sxarwire_sco_table_prefix14_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix14_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix14_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,14]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix14_bit7={UINT32_C(0x608d0245),"sco_table_prefix14_bit7",sxarwire_sco_table_prefix14_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix14_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix15_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,15]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix15_bit0={UINT32_C(0x608d0246),"sco_table_prefix15_bit0",sxarwire_sco_table_prefix15_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix15_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix15_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,15]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix15_bit1={UINT32_C(0x608d0247),"sco_table_prefix15_bit1",sxarwire_sco_table_prefix15_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix15_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix15_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,15]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix15_bit2={UINT32_C(0x608d0248),"sco_table_prefix15_bit2",sxarwire_sco_table_prefix15_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix15_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix15_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,15]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix15_bit3={UINT32_C(0x608d0249),"sco_table_prefix15_bit3",sxarwire_sco_table_prefix15_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix15_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix15_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,15]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix15_bit4={UINT32_C(0x608d024a),"sco_table_prefix15_bit4",sxarwire_sco_table_prefix15_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix15_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix15_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,15]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix15_bit5={UINT32_C(0x608d024b),"sco_table_prefix15_bit5",sxarwire_sco_table_prefix15_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix15_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix15_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,15]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix15_bit6={UINT32_C(0x608d024c),"sco_table_prefix15_bit6",sxarwire_sco_table_prefix15_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix15_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix15_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,15]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix15_bit7={UINT32_C(0x608d024d),"sco_table_prefix15_bit7",sxarwire_sco_table_prefix15_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix15_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix16_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[0,16]",0,2,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix16_bit0={UINT32_C(0x608d024e),"sco_table_prefix16_bit0",sxarwire_sco_table_prefix16_bit0_fields,SX_COUNT(sxarwire_sco_table_prefix16_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix16_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[1,16]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix16_bit1={UINT32_C(0x608d024f),"sco_table_prefix16_bit1",sxarwire_sco_table_prefix16_bit1_fields,SX_COUNT(sxarwire_sco_table_prefix16_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix16_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[2,16]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix16_bit2={UINT32_C(0x608d0250),"sco_table_prefix16_bit2",sxarwire_sco_table_prefix16_bit2_fields,SX_COUNT(sxarwire_sco_table_prefix16_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix16_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[3,16]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix16_bit3={UINT32_C(0x608d0251),"sco_table_prefix16_bit3",sxarwire_sco_table_prefix16_bit3_fields,SX_COUNT(sxarwire_sco_table_prefix16_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix16_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[4,16]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix16_bit4={UINT32_C(0x608d0252),"sco_table_prefix16_bit4",sxarwire_sco_table_prefix16_bit4_fields,SX_COUNT(sxarwire_sco_table_prefix16_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix16_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[5,16]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix16_bit5={UINT32_C(0x608d0253),"sco_table_prefix16_bit5",sxarwire_sco_table_prefix16_bit5_fields,SX_COUNT(sxarwire_sco_table_prefix16_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix16_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[6,16]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix16_bit6={UINT32_C(0x608d0254),"sco_table_prefix16_bit6",sxarwire_sco_table_prefix16_bit6_fields,SX_COUNT(sxarwire_sco_table_prefix16_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_sco_table_prefix16_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","msb_bits[7,16]",0,3,SX_NONE),
};
static const sx_layout sxarwire_sco_table_prefix16_bit7={UINT32_C(0x608d0255),"sco_table_prefix16_bit7",sxarwire_sco_table_prefix16_bit7_fields,SX_COUNT(sxarwire_sco_table_prefix16_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix1_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[0,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix1_bit0={UINT32_C(0x608d0256),"deflate_table_prefix1_bit0",sxarwire_deflate_table_prefix1_bit0_fields,SX_COUNT(sxarwire_deflate_table_prefix1_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix1_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[1,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix1_bit1={UINT32_C(0x608d0257),"deflate_table_prefix1_bit1",sxarwire_deflate_table_prefix1_bit1_fields,SX_COUNT(sxarwire_deflate_table_prefix1_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix1_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[2,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix1_bit2={UINT32_C(0x608d0258),"deflate_table_prefix1_bit2",sxarwire_deflate_table_prefix1_bit2_fields,SX_COUNT(sxarwire_deflate_table_prefix1_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix1_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[3,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix1_bit3={UINT32_C(0x608d0259),"deflate_table_prefix1_bit3",sxarwire_deflate_table_prefix1_bit3_fields,SX_COUNT(sxarwire_deflate_table_prefix1_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix1_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[4,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix1_bit4={UINT32_C(0x608d025a),"deflate_table_prefix1_bit4",sxarwire_deflate_table_prefix1_bit4_fields,SX_COUNT(sxarwire_deflate_table_prefix1_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix1_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[5,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix1_bit5={UINT32_C(0x608d025b),"deflate_table_prefix1_bit5",sxarwire_deflate_table_prefix1_bit5_fields,SX_COUNT(sxarwire_deflate_table_prefix1_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix1_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[6,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix1_bit6={UINT32_C(0x608d025c),"deflate_table_prefix1_bit6",sxarwire_deflate_table_prefix1_bit6_fields,SX_COUNT(sxarwire_deflate_table_prefix1_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix1_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[7,1]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix1_bit7={UINT32_C(0x608d025d),"deflate_table_prefix1_bit7",sxarwire_deflate_table_prefix1_bit7_fields,SX_COUNT(sxarwire_deflate_table_prefix1_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix2_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[0,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix2_bit0={UINT32_C(0x608d025e),"deflate_table_prefix2_bit0",sxarwire_deflate_table_prefix2_bit0_fields,SX_COUNT(sxarwire_deflate_table_prefix2_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix2_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[1,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix2_bit1={UINT32_C(0x608d025f),"deflate_table_prefix2_bit1",sxarwire_deflate_table_prefix2_bit1_fields,SX_COUNT(sxarwire_deflate_table_prefix2_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix2_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[2,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix2_bit2={UINT32_C(0x608d0260),"deflate_table_prefix2_bit2",sxarwire_deflate_table_prefix2_bit2_fields,SX_COUNT(sxarwire_deflate_table_prefix2_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix2_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[3,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix2_bit3={UINT32_C(0x608d0261),"deflate_table_prefix2_bit3",sxarwire_deflate_table_prefix2_bit3_fields,SX_COUNT(sxarwire_deflate_table_prefix2_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix2_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[4,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix2_bit4={UINT32_C(0x608d0262),"deflate_table_prefix2_bit4",sxarwire_deflate_table_prefix2_bit4_fields,SX_COUNT(sxarwire_deflate_table_prefix2_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix2_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[5,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix2_bit5={UINT32_C(0x608d0263),"deflate_table_prefix2_bit5",sxarwire_deflate_table_prefix2_bit5_fields,SX_COUNT(sxarwire_deflate_table_prefix2_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix2_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[6,2]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix2_bit6={UINT32_C(0x608d0264),"deflate_table_prefix2_bit6",sxarwire_deflate_table_prefix2_bit6_fields,SX_COUNT(sxarwire_deflate_table_prefix2_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix2_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[7,2]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix2_bit7={UINT32_C(0x608d0265),"deflate_table_prefix2_bit7",sxarwire_deflate_table_prefix2_bit7_fields,SX_COUNT(sxarwire_deflate_table_prefix2_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix3_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[0,3]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix3_bit0={UINT32_C(0x608d0266),"deflate_table_prefix3_bit0",sxarwire_deflate_table_prefix3_bit0_fields,SX_COUNT(sxarwire_deflate_table_prefix3_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix3_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[1,3]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix3_bit1={UINT32_C(0x608d0267),"deflate_table_prefix3_bit1",sxarwire_deflate_table_prefix3_bit1_fields,SX_COUNT(sxarwire_deflate_table_prefix3_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix3_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[2,3]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix3_bit2={UINT32_C(0x608d0268),"deflate_table_prefix3_bit2",sxarwire_deflate_table_prefix3_bit2_fields,SX_COUNT(sxarwire_deflate_table_prefix3_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix3_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[3,3]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix3_bit3={UINT32_C(0x608d0269),"deflate_table_prefix3_bit3",sxarwire_deflate_table_prefix3_bit3_fields,SX_COUNT(sxarwire_deflate_table_prefix3_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix3_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[4,3]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix3_bit4={UINT32_C(0x608d026a),"deflate_table_prefix3_bit4",sxarwire_deflate_table_prefix3_bit4_fields,SX_COUNT(sxarwire_deflate_table_prefix3_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix3_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[5,3]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix3_bit5={UINT32_C(0x608d026b),"deflate_table_prefix3_bit5",sxarwire_deflate_table_prefix3_bit5_fields,SX_COUNT(sxarwire_deflate_table_prefix3_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix3_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[6,3]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix3_bit6={UINT32_C(0x608d026c),"deflate_table_prefix3_bit6",sxarwire_deflate_table_prefix3_bit6_fields,SX_COUNT(sxarwire_deflate_table_prefix3_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix3_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[7,3]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix3_bit7={UINT32_C(0x608d026d),"deflate_table_prefix3_bit7",sxarwire_deflate_table_prefix3_bit7_fields,SX_COUNT(sxarwire_deflate_table_prefix3_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix4_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[0,4]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix4_bit0={UINT32_C(0x608d026e),"deflate_table_prefix4_bit0",sxarwire_deflate_table_prefix4_bit0_fields,SX_COUNT(sxarwire_deflate_table_prefix4_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix4_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[1,4]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix4_bit1={UINT32_C(0x608d026f),"deflate_table_prefix4_bit1",sxarwire_deflate_table_prefix4_bit1_fields,SX_COUNT(sxarwire_deflate_table_prefix4_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix4_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[2,4]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix4_bit2={UINT32_C(0x608d0270),"deflate_table_prefix4_bit2",sxarwire_deflate_table_prefix4_bit2_fields,SX_COUNT(sxarwire_deflate_table_prefix4_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix4_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[3,4]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix4_bit3={UINT32_C(0x608d0271),"deflate_table_prefix4_bit3",sxarwire_deflate_table_prefix4_bit3_fields,SX_COUNT(sxarwire_deflate_table_prefix4_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix4_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[4,4]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix4_bit4={UINT32_C(0x608d0272),"deflate_table_prefix4_bit4",sxarwire_deflate_table_prefix4_bit4_fields,SX_COUNT(sxarwire_deflate_table_prefix4_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix4_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[5,4]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix4_bit5={UINT32_C(0x608d0273),"deflate_table_prefix4_bit5",sxarwire_deflate_table_prefix4_bit5_fields,SX_COUNT(sxarwire_deflate_table_prefix4_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix4_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[6,4]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix4_bit6={UINT32_C(0x608d0274),"deflate_table_prefix4_bit6",sxarwire_deflate_table_prefix4_bit6_fields,SX_COUNT(sxarwire_deflate_table_prefix4_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix4_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[7,4]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix4_bit7={UINT32_C(0x608d0275),"deflate_table_prefix4_bit7",sxarwire_deflate_table_prefix4_bit7_fields,SX_COUNT(sxarwire_deflate_table_prefix4_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix5_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[0,5]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix5_bit0={UINT32_C(0x608d0276),"deflate_table_prefix5_bit0",sxarwire_deflate_table_prefix5_bit0_fields,SX_COUNT(sxarwire_deflate_table_prefix5_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix5_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[1,5]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix5_bit1={UINT32_C(0x608d0277),"deflate_table_prefix5_bit1",sxarwire_deflate_table_prefix5_bit1_fields,SX_COUNT(sxarwire_deflate_table_prefix5_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix5_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[2,5]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix5_bit2={UINT32_C(0x608d0278),"deflate_table_prefix5_bit2",sxarwire_deflate_table_prefix5_bit2_fields,SX_COUNT(sxarwire_deflate_table_prefix5_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix5_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[3,5]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix5_bit3={UINT32_C(0x608d0279),"deflate_table_prefix5_bit3",sxarwire_deflate_table_prefix5_bit3_fields,SX_COUNT(sxarwire_deflate_table_prefix5_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix5_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[4,5]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix5_bit4={UINT32_C(0x608d027a),"deflate_table_prefix5_bit4",sxarwire_deflate_table_prefix5_bit4_fields,SX_COUNT(sxarwire_deflate_table_prefix5_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix5_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[5,5]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix5_bit5={UINT32_C(0x608d027b),"deflate_table_prefix5_bit5",sxarwire_deflate_table_prefix5_bit5_fields,SX_COUNT(sxarwire_deflate_table_prefix5_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix5_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[6,5]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix5_bit6={UINT32_C(0x608d027c),"deflate_table_prefix5_bit6",sxarwire_deflate_table_prefix5_bit6_fields,SX_COUNT(sxarwire_deflate_table_prefix5_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix5_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[7,5]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix5_bit7={UINT32_C(0x608d027d),"deflate_table_prefix5_bit7",sxarwire_deflate_table_prefix5_bit7_fields,SX_COUNT(sxarwire_deflate_table_prefix5_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix6_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[0,6]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix6_bit0={UINT32_C(0x608d027e),"deflate_table_prefix6_bit0",sxarwire_deflate_table_prefix6_bit0_fields,SX_COUNT(sxarwire_deflate_table_prefix6_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix6_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[1,6]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix6_bit1={UINT32_C(0x608d027f),"deflate_table_prefix6_bit1",sxarwire_deflate_table_prefix6_bit1_fields,SX_COUNT(sxarwire_deflate_table_prefix6_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix6_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[2,6]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix6_bit2={UINT32_C(0x608d0280),"deflate_table_prefix6_bit2",sxarwire_deflate_table_prefix6_bit2_fields,SX_COUNT(sxarwire_deflate_table_prefix6_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix6_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[3,6]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix6_bit3={UINT32_C(0x608d0281),"deflate_table_prefix6_bit3",sxarwire_deflate_table_prefix6_bit3_fields,SX_COUNT(sxarwire_deflate_table_prefix6_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix6_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[4,6]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix6_bit4={UINT32_C(0x608d0282),"deflate_table_prefix6_bit4",sxarwire_deflate_table_prefix6_bit4_fields,SX_COUNT(sxarwire_deflate_table_prefix6_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix6_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[5,6]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix6_bit5={UINT32_C(0x608d0283),"deflate_table_prefix6_bit5",sxarwire_deflate_table_prefix6_bit5_fields,SX_COUNT(sxarwire_deflate_table_prefix6_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix6_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[6,6]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix6_bit6={UINT32_C(0x608d0284),"deflate_table_prefix6_bit6",sxarwire_deflate_table_prefix6_bit6_fields,SX_COUNT(sxarwire_deflate_table_prefix6_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix6_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[7,6]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix6_bit7={UINT32_C(0x608d0285),"deflate_table_prefix6_bit7",sxarwire_deflate_table_prefix6_bit7_fields,SX_COUNT(sxarwire_deflate_table_prefix6_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix7_bit0_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[0,7]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix7_bit0={UINT32_C(0x608d0286),"deflate_table_prefix7_bit0",sxarwire_deflate_table_prefix7_bit0_fields,SX_COUNT(sxarwire_deflate_table_prefix7_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix7_bit1_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[1,7]",0,1,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix7_bit1={UINT32_C(0x608d0287),"deflate_table_prefix7_bit1",sxarwire_deflate_table_prefix7_bit1_fields,SX_COUNT(sxarwire_deflate_table_prefix7_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix7_bit2_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[2,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix7_bit2={UINT32_C(0x608d0288),"deflate_table_prefix7_bit2",sxarwire_deflate_table_prefix7_bit2_fields,SX_COUNT(sxarwire_deflate_table_prefix7_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix7_bit3_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[3,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix7_bit3={UINT32_C(0x608d0289),"deflate_table_prefix7_bit3",sxarwire_deflate_table_prefix7_bit3_fields,SX_COUNT(sxarwire_deflate_table_prefix7_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix7_bit4_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[4,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix7_bit4={UINT32_C(0x608d028a),"deflate_table_prefix7_bit4",sxarwire_deflate_table_prefix7_bit4_fields,SX_COUNT(sxarwire_deflate_table_prefix7_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix7_bit5_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[5,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix7_bit5={UINT32_C(0x608d028b),"deflate_table_prefix7_bit5",sxarwire_deflate_table_prefix7_bit5_fields,SX_COUNT(sxarwire_deflate_table_prefix7_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix7_bit6_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[6,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix7_bit6={UINT32_C(0x608d028c),"deflate_table_prefix7_bit6",sxarwire_deflate_table_prefix7_bit6_fields,SX_COUNT(sxarwire_deflate_table_prefix7_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_deflate_table_prefix7_bit7_fields[]={
 SX_FIELD("encoded_code_length_symbol","lsb_bits[7,7]",0,2,SX_NONE),
};
static const sx_layout sxarwire_deflate_table_prefix7_bit7={UINT32_C(0x608d028d),"deflate_table_prefix7_bit7",sxarwire_deflate_table_prefix7_bit7_fields,SX_COUNT(sxarwire_deflate_table_prefix7_bit7_fields),SX_LE};
static const sx_layout *const sxarwire_set_lzs_is_match[]={&sxarwire_lzs_is_match_bit0,&sxarwire_lzs_is_match_bit1,&sxarwire_lzs_is_match_bit2,&sxarwire_lzs_is_match_bit3,&sxarwire_lzs_is_match_bit4,&sxarwire_lzs_is_match_bit5,&sxarwire_lzs_is_match_bit6,&sxarwire_lzs_is_match_bit7};
static const sx_layout *const sxarwire_set_lzs_short_distance[]={&sxarwire_lzs_short_distance_bit0,&sxarwire_lzs_short_distance_bit1,&sxarwire_lzs_short_distance_bit2,&sxarwire_lzs_short_distance_bit3,&sxarwire_lzs_short_distance_bit4,&sxarwire_lzs_short_distance_bit5,&sxarwire_lzs_short_distance_bit6,&sxarwire_lzs_short_distance_bit7};
static const sx_layout *const sxarwire_set_lzs_literal[]={&sxarwire_lzs_literal_bit0,&sxarwire_lzs_literal_bit1,&sxarwire_lzs_literal_bit2,&sxarwire_lzs_literal_bit3,&sxarwire_lzs_literal_bit4,&sxarwire_lzs_literal_bit5,&sxarwire_lzs_literal_bit6,&sxarwire_lzs_literal_bit7};
static const sx_layout *const sxarwire_set_lzs_distance7[]={&sxarwire_lzs_distance7_bit0,&sxarwire_lzs_distance7_bit1,&sxarwire_lzs_distance7_bit2,&sxarwire_lzs_distance7_bit3,&sxarwire_lzs_distance7_bit4,&sxarwire_lzs_distance7_bit5,&sxarwire_lzs_distance7_bit6,&sxarwire_lzs_distance7_bit7};
static const sx_layout *const sxarwire_set_lzs_distance11[]={&sxarwire_lzs_distance11_bit0,&sxarwire_lzs_distance11_bit1,&sxarwire_lzs_distance11_bit2,&sxarwire_lzs_distance11_bit3,&sxarwire_lzs_distance11_bit4,&sxarwire_lzs_distance11_bit5,&sxarwire_lzs_distance11_bit6,&sxarwire_lzs_distance11_bit7};
static const sx_layout *const sxarwire_set_lzs_length_prefix[]={&sxarwire_lzs_length_prefix_bit0,&sxarwire_lzs_length_prefix_bit1,&sxarwire_lzs_length_prefix_bit2,&sxarwire_lzs_length_prefix_bit3,&sxarwire_lzs_length_prefix_bit4,&sxarwire_lzs_length_prefix_bit5,&sxarwire_lzs_length_prefix_bit6,&sxarwire_lzs_length_prefix_bit7};
static const sx_layout *const sxarwire_set_lzs_length_secondary[]={&sxarwire_lzs_length_secondary_bit0,&sxarwire_lzs_length_secondary_bit1,&sxarwire_lzs_length_secondary_bit2,&sxarwire_lzs_length_secondary_bit3,&sxarwire_lzs_length_secondary_bit4,&sxarwire_lzs_length_secondary_bit5,&sxarwire_lzs_length_secondary_bit6,&sxarwire_lzs_length_secondary_bit7};
static const sx_layout *const sxarwire_set_lzs_length_extension[]={&sxarwire_lzs_length_extension_bit0,&sxarwire_lzs_length_extension_bit1,&sxarwire_lzs_length_extension_bit2,&sxarwire_lzs_length_extension_bit3,&sxarwire_lzs_length_extension_bit4,&sxarwire_lzs_length_extension_bit5,&sxarwire_lzs_length_extension_bit6,&sxarwire_lzs_length_extension_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix1[]={&sxarwire_sco_table_prefix1_bit0,&sxarwire_sco_table_prefix1_bit1,&sxarwire_sco_table_prefix1_bit2,&sxarwire_sco_table_prefix1_bit3,&sxarwire_sco_table_prefix1_bit4,&sxarwire_sco_table_prefix1_bit5,&sxarwire_sco_table_prefix1_bit6,&sxarwire_sco_table_prefix1_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix2[]={&sxarwire_sco_table_prefix2_bit0,&sxarwire_sco_table_prefix2_bit1,&sxarwire_sco_table_prefix2_bit2,&sxarwire_sco_table_prefix2_bit3,&sxarwire_sco_table_prefix2_bit4,&sxarwire_sco_table_prefix2_bit5,&sxarwire_sco_table_prefix2_bit6,&sxarwire_sco_table_prefix2_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix3[]={&sxarwire_sco_table_prefix3_bit0,&sxarwire_sco_table_prefix3_bit1,&sxarwire_sco_table_prefix3_bit2,&sxarwire_sco_table_prefix3_bit3,&sxarwire_sco_table_prefix3_bit4,&sxarwire_sco_table_prefix3_bit5,&sxarwire_sco_table_prefix3_bit6,&sxarwire_sco_table_prefix3_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix4[]={&sxarwire_sco_table_prefix4_bit0,&sxarwire_sco_table_prefix4_bit1,&sxarwire_sco_table_prefix4_bit2,&sxarwire_sco_table_prefix4_bit3,&sxarwire_sco_table_prefix4_bit4,&sxarwire_sco_table_prefix4_bit5,&sxarwire_sco_table_prefix4_bit6,&sxarwire_sco_table_prefix4_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix5[]={&sxarwire_sco_table_prefix5_bit0,&sxarwire_sco_table_prefix5_bit1,&sxarwire_sco_table_prefix5_bit2,&sxarwire_sco_table_prefix5_bit3,&sxarwire_sco_table_prefix5_bit4,&sxarwire_sco_table_prefix5_bit5,&sxarwire_sco_table_prefix5_bit6,&sxarwire_sco_table_prefix5_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix6[]={&sxarwire_sco_table_prefix6_bit0,&sxarwire_sco_table_prefix6_bit1,&sxarwire_sco_table_prefix6_bit2,&sxarwire_sco_table_prefix6_bit3,&sxarwire_sco_table_prefix6_bit4,&sxarwire_sco_table_prefix6_bit5,&sxarwire_sco_table_prefix6_bit6,&sxarwire_sco_table_prefix6_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix7[]={&sxarwire_sco_table_prefix7_bit0,&sxarwire_sco_table_prefix7_bit1,&sxarwire_sco_table_prefix7_bit2,&sxarwire_sco_table_prefix7_bit3,&sxarwire_sco_table_prefix7_bit4,&sxarwire_sco_table_prefix7_bit5,&sxarwire_sco_table_prefix7_bit6,&sxarwire_sco_table_prefix7_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix8[]={&sxarwire_sco_table_prefix8_bit0,&sxarwire_sco_table_prefix8_bit1,&sxarwire_sco_table_prefix8_bit2,&sxarwire_sco_table_prefix8_bit3,&sxarwire_sco_table_prefix8_bit4,&sxarwire_sco_table_prefix8_bit5,&sxarwire_sco_table_prefix8_bit6,&sxarwire_sco_table_prefix8_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix9[]={&sxarwire_sco_table_prefix9_bit0,&sxarwire_sco_table_prefix9_bit1,&sxarwire_sco_table_prefix9_bit2,&sxarwire_sco_table_prefix9_bit3,&sxarwire_sco_table_prefix9_bit4,&sxarwire_sco_table_prefix9_bit5,&sxarwire_sco_table_prefix9_bit6,&sxarwire_sco_table_prefix9_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix10[]={&sxarwire_sco_table_prefix10_bit0,&sxarwire_sco_table_prefix10_bit1,&sxarwire_sco_table_prefix10_bit2,&sxarwire_sco_table_prefix10_bit3,&sxarwire_sco_table_prefix10_bit4,&sxarwire_sco_table_prefix10_bit5,&sxarwire_sco_table_prefix10_bit6,&sxarwire_sco_table_prefix10_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix11[]={&sxarwire_sco_table_prefix11_bit0,&sxarwire_sco_table_prefix11_bit1,&sxarwire_sco_table_prefix11_bit2,&sxarwire_sco_table_prefix11_bit3,&sxarwire_sco_table_prefix11_bit4,&sxarwire_sco_table_prefix11_bit5,&sxarwire_sco_table_prefix11_bit6,&sxarwire_sco_table_prefix11_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix12[]={&sxarwire_sco_table_prefix12_bit0,&sxarwire_sco_table_prefix12_bit1,&sxarwire_sco_table_prefix12_bit2,&sxarwire_sco_table_prefix12_bit3,&sxarwire_sco_table_prefix12_bit4,&sxarwire_sco_table_prefix12_bit5,&sxarwire_sco_table_prefix12_bit6,&sxarwire_sco_table_prefix12_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix13[]={&sxarwire_sco_table_prefix13_bit0,&sxarwire_sco_table_prefix13_bit1,&sxarwire_sco_table_prefix13_bit2,&sxarwire_sco_table_prefix13_bit3,&sxarwire_sco_table_prefix13_bit4,&sxarwire_sco_table_prefix13_bit5,&sxarwire_sco_table_prefix13_bit6,&sxarwire_sco_table_prefix13_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix14[]={&sxarwire_sco_table_prefix14_bit0,&sxarwire_sco_table_prefix14_bit1,&sxarwire_sco_table_prefix14_bit2,&sxarwire_sco_table_prefix14_bit3,&sxarwire_sco_table_prefix14_bit4,&sxarwire_sco_table_prefix14_bit5,&sxarwire_sco_table_prefix14_bit6,&sxarwire_sco_table_prefix14_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix15[]={&sxarwire_sco_table_prefix15_bit0,&sxarwire_sco_table_prefix15_bit1,&sxarwire_sco_table_prefix15_bit2,&sxarwire_sco_table_prefix15_bit3,&sxarwire_sco_table_prefix15_bit4,&sxarwire_sco_table_prefix15_bit5,&sxarwire_sco_table_prefix15_bit6,&sxarwire_sco_table_prefix15_bit7};
static const sx_layout *const sxarwire_set_sco_table_prefix16[]={&sxarwire_sco_table_prefix16_bit0,&sxarwire_sco_table_prefix16_bit1,&sxarwire_sco_table_prefix16_bit2,&sxarwire_sco_table_prefix16_bit3,&sxarwire_sco_table_prefix16_bit4,&sxarwire_sco_table_prefix16_bit5,&sxarwire_sco_table_prefix16_bit6,&sxarwire_sco_table_prefix16_bit7};
static const sx_layout *const sxarwire_set_deflate_table_prefix1[]={&sxarwire_deflate_table_prefix1_bit0,&sxarwire_deflate_table_prefix1_bit1,&sxarwire_deflate_table_prefix1_bit2,&sxarwire_deflate_table_prefix1_bit3,&sxarwire_deflate_table_prefix1_bit4,&sxarwire_deflate_table_prefix1_bit5,&sxarwire_deflate_table_prefix1_bit6,&sxarwire_deflate_table_prefix1_bit7};
static const sx_layout *const sxarwire_set_deflate_table_prefix2[]={&sxarwire_deflate_table_prefix2_bit0,&sxarwire_deflate_table_prefix2_bit1,&sxarwire_deflate_table_prefix2_bit2,&sxarwire_deflate_table_prefix2_bit3,&sxarwire_deflate_table_prefix2_bit4,&sxarwire_deflate_table_prefix2_bit5,&sxarwire_deflate_table_prefix2_bit6,&sxarwire_deflate_table_prefix2_bit7};
static const sx_layout *const sxarwire_set_deflate_table_prefix3[]={&sxarwire_deflate_table_prefix3_bit0,&sxarwire_deflate_table_prefix3_bit1,&sxarwire_deflate_table_prefix3_bit2,&sxarwire_deflate_table_prefix3_bit3,&sxarwire_deflate_table_prefix3_bit4,&sxarwire_deflate_table_prefix3_bit5,&sxarwire_deflate_table_prefix3_bit6,&sxarwire_deflate_table_prefix3_bit7};
static const sx_layout *const sxarwire_set_deflate_table_prefix4[]={&sxarwire_deflate_table_prefix4_bit0,&sxarwire_deflate_table_prefix4_bit1,&sxarwire_deflate_table_prefix4_bit2,&sxarwire_deflate_table_prefix4_bit3,&sxarwire_deflate_table_prefix4_bit4,&sxarwire_deflate_table_prefix4_bit5,&sxarwire_deflate_table_prefix4_bit6,&sxarwire_deflate_table_prefix4_bit7};
static const sx_layout *const sxarwire_set_deflate_table_prefix5[]={&sxarwire_deflate_table_prefix5_bit0,&sxarwire_deflate_table_prefix5_bit1,&sxarwire_deflate_table_prefix5_bit2,&sxarwire_deflate_table_prefix5_bit3,&sxarwire_deflate_table_prefix5_bit4,&sxarwire_deflate_table_prefix5_bit5,&sxarwire_deflate_table_prefix5_bit6,&sxarwire_deflate_table_prefix5_bit7};
static const sx_layout *const sxarwire_set_deflate_table_prefix6[]={&sxarwire_deflate_table_prefix6_bit0,&sxarwire_deflate_table_prefix6_bit1,&sxarwire_deflate_table_prefix6_bit2,&sxarwire_deflate_table_prefix6_bit3,&sxarwire_deflate_table_prefix6_bit4,&sxarwire_deflate_table_prefix6_bit5,&sxarwire_deflate_table_prefix6_bit6,&sxarwire_deflate_table_prefix6_bit7};
static const sx_layout *const sxarwire_set_deflate_table_prefix7[]={&sxarwire_deflate_table_prefix7_bit0,&sxarwire_deflate_table_prefix7_bit1,&sxarwire_deflate_table_prefix7_bit2,&sxarwire_deflate_table_prefix7_bit3,&sxarwire_deflate_table_prefix7_bit4,&sxarwire_deflate_table_prefix7_bit5,&sxarwire_deflate_table_prefix7_bit6,&sxarwire_deflate_table_prefix7_bit7};
static const sx_layout *const sx_archivewire_layouts[]={
 &sxarwire_npack_signature,
 &sxarwire_stac_signature,
 &sxarwire_ibmspack_tag,
 &sxarwire_terse_spack_signature,
 &sxarwire_terse_profile,
 &sxarwire_lzs_is_match_bit0,
 &sxarwire_lzs_is_match_bit1,
 &sxarwire_lzs_is_match_bit2,
 &sxarwire_lzs_is_match_bit3,
 &sxarwire_lzs_is_match_bit4,
 &sxarwire_lzs_is_match_bit5,
 &sxarwire_lzs_is_match_bit6,
 &sxarwire_lzs_is_match_bit7,
 &sxarwire_lzs_short_distance_bit0,
 &sxarwire_lzs_short_distance_bit1,
 &sxarwire_lzs_short_distance_bit2,
 &sxarwire_lzs_short_distance_bit3,
 &sxarwire_lzs_short_distance_bit4,
 &sxarwire_lzs_short_distance_bit5,
 &sxarwire_lzs_short_distance_bit6,
 &sxarwire_lzs_short_distance_bit7,
 &sxarwire_lzs_literal_bit0,
 &sxarwire_lzs_literal_bit1,
 &sxarwire_lzs_literal_bit2,
 &sxarwire_lzs_literal_bit3,
 &sxarwire_lzs_literal_bit4,
 &sxarwire_lzs_literal_bit5,
 &sxarwire_lzs_literal_bit6,
 &sxarwire_lzs_literal_bit7,
 &sxarwire_lzs_distance7_bit0,
 &sxarwire_lzs_distance7_bit1,
 &sxarwire_lzs_distance7_bit2,
 &sxarwire_lzs_distance7_bit3,
 &sxarwire_lzs_distance7_bit4,
 &sxarwire_lzs_distance7_bit5,
 &sxarwire_lzs_distance7_bit6,
 &sxarwire_lzs_distance7_bit7,
 &sxarwire_lzs_distance11_bit0,
 &sxarwire_lzs_distance11_bit1,
 &sxarwire_lzs_distance11_bit2,
 &sxarwire_lzs_distance11_bit3,
 &sxarwire_lzs_distance11_bit4,
 &sxarwire_lzs_distance11_bit5,
 &sxarwire_lzs_distance11_bit6,
 &sxarwire_lzs_distance11_bit7,
 &sxarwire_lzs_length_prefix_bit0,
 &sxarwire_lzs_length_prefix_bit1,
 &sxarwire_lzs_length_prefix_bit2,
 &sxarwire_lzs_length_prefix_bit3,
 &sxarwire_lzs_length_prefix_bit4,
 &sxarwire_lzs_length_prefix_bit5,
 &sxarwire_lzs_length_prefix_bit6,
 &sxarwire_lzs_length_prefix_bit7,
 &sxarwire_lzs_length_secondary_bit0,
 &sxarwire_lzs_length_secondary_bit1,
 &sxarwire_lzs_length_secondary_bit2,
 &sxarwire_lzs_length_secondary_bit3,
 &sxarwire_lzs_length_secondary_bit4,
 &sxarwire_lzs_length_secondary_bit5,
 &sxarwire_lzs_length_secondary_bit6,
 &sxarwire_lzs_length_secondary_bit7,
 &sxarwire_lzs_length_extension_bit0,
 &sxarwire_lzs_length_extension_bit1,
 &sxarwire_lzs_length_extension_bit2,
 &sxarwire_lzs_length_extension_bit3,
 &sxarwire_lzs_length_extension_bit4,
 &sxarwire_lzs_length_extension_bit5,
 &sxarwire_lzs_length_extension_bit6,
 &sxarwire_lzs_length_extension_bit7,
 &sxarwire_lzw15v_code9_bit0,
 &sxarwire_lzw15v_code9_bit1,
 &sxarwire_lzw15v_code9_bit2,
 &sxarwire_lzw15v_code9_bit3,
 &sxarwire_lzw15v_code9_bit4,
 &sxarwire_lzw15v_code9_bit5,
 &sxarwire_lzw15v_code9_bit6,
 &sxarwire_lzw15v_code9_bit7,
 &sxarwire_lzw15v_code10_bit0,
 &sxarwire_lzw15v_code10_bit1,
 &sxarwire_lzw15v_code10_bit2,
 &sxarwire_lzw15v_code10_bit3,
 &sxarwire_lzw15v_code10_bit4,
 &sxarwire_lzw15v_code10_bit5,
 &sxarwire_lzw15v_code10_bit6,
 &sxarwire_lzw15v_code10_bit7,
 &sxarwire_lzw15v_code11_bit0,
 &sxarwire_lzw15v_code11_bit1,
 &sxarwire_lzw15v_code11_bit2,
 &sxarwire_lzw15v_code11_bit3,
 &sxarwire_lzw15v_code11_bit4,
 &sxarwire_lzw15v_code11_bit5,
 &sxarwire_lzw15v_code11_bit6,
 &sxarwire_lzw15v_code11_bit7,
 &sxarwire_lzw15v_code12_bit0,
 &sxarwire_lzw15v_code12_bit1,
 &sxarwire_lzw15v_code12_bit2,
 &sxarwire_lzw15v_code12_bit3,
 &sxarwire_lzw15v_code12_bit4,
 &sxarwire_lzw15v_code12_bit5,
 &sxarwire_lzw15v_code12_bit6,
 &sxarwire_lzw15v_code12_bit7,
 &sxarwire_lzw15v_code13_bit0,
 &sxarwire_lzw15v_code13_bit1,
 &sxarwire_lzw15v_code13_bit2,
 &sxarwire_lzw15v_code13_bit3,
 &sxarwire_lzw15v_code13_bit4,
 &sxarwire_lzw15v_code13_bit5,
 &sxarwire_lzw15v_code13_bit6,
 &sxarwire_lzw15v_code13_bit7,
 &sxarwire_lzw15v_code14_bit0,
 &sxarwire_lzw15v_code14_bit1,
 &sxarwire_lzw15v_code14_bit2,
 &sxarwire_lzw15v_code14_bit3,
 &sxarwire_lzw15v_code14_bit4,
 &sxarwire_lzw15v_code14_bit5,
 &sxarwire_lzw15v_code14_bit6,
 &sxarwire_lzw15v_code14_bit7,
 &sxarwire_lzw15v_code15_bit0,
 &sxarwire_lzw15v_code15_bit1,
 &sxarwire_lzw15v_code15_bit2,
 &sxarwire_lzw15v_code15_bit3,
 &sxarwire_lzw15v_code15_bit4,
 &sxarwire_lzw15v_code15_bit5,
 &sxarwire_lzw15v_code15_bit6,
 &sxarwire_lzw15v_code15_bit7,
 &sxarwire_terse_code_bit0,
 &sxarwire_terse_code_bit4,
 &sxarwire_fls_first_class_bit0,
 &sxarwire_fls_first_class_bit1,
 &sxarwire_fls_first_class_bit2,
 &sxarwire_fls_first_class_bit3,
 &sxarwire_fls_first_class_bit4,
 &sxarwire_fls_first_class_bit5,
 &sxarwire_fls_first_class_bit6,
 &sxarwire_fls_first_class_bit7,
 &sxarwire_fls_second_class_bit0,
 &sxarwire_fls_second_class_bit1,
 &sxarwire_fls_second_class_bit2,
 &sxarwire_fls_second_class_bit3,
 &sxarwire_fls_second_class_bit4,
 &sxarwire_fls_second_class_bit5,
 &sxarwire_fls_second_class_bit6,
 &sxarwire_fls_second_class_bit7,
 &sxarwire_fls_selector_prefix_bit0,
 &sxarwire_fls_selector_prefix_bit1,
 &sxarwire_fls_selector_prefix_bit2,
 &sxarwire_fls_selector_prefix_bit3,
 &sxarwire_fls_selector_prefix_bit4,
 &sxarwire_fls_selector_prefix_bit5,
 &sxarwire_fls_selector_prefix_bit6,
 &sxarwire_fls_selector_prefix_bit7,
 &sxarwire_fls_selector_extension_bit0,
 &sxarwire_fls_selector_extension_bit1,
 &sxarwire_fls_selector_extension_bit2,
 &sxarwire_fls_selector_extension_bit3,
 &sxarwire_fls_selector_extension_bit4,
 &sxarwire_fls_selector_extension_bit5,
 &sxarwire_fls_selector_extension_bit6,
 &sxarwire_fls_selector_extension_bit7,
 &sxarwire_fls_code6_bit0,
 &sxarwire_fls_code6_bit1,
 &sxarwire_fls_code6_bit2,
 &sxarwire_fls_code6_bit3,
 &sxarwire_fls_code6_bit4,
 &sxarwire_fls_code6_bit5,
 &sxarwire_fls_code6_bit6,
 &sxarwire_fls_code6_bit7,
 &sxarwire_fls_code7_bit0,
 &sxarwire_fls_code7_bit1,
 &sxarwire_fls_code7_bit2,
 &sxarwire_fls_code7_bit3,
 &sxarwire_fls_code7_bit4,
 &sxarwire_fls_code7_bit5,
 &sxarwire_fls_code7_bit6,
 &sxarwire_fls_code7_bit7,
 &sxarwire_fls_code8_bit0,
 &sxarwire_fls_code8_bit1,
 &sxarwire_fls_code8_bit2,
 &sxarwire_fls_code8_bit3,
 &sxarwire_fls_code8_bit4,
 &sxarwire_fls_code8_bit5,
 &sxarwire_fls_code8_bit6,
 &sxarwire_fls_code8_bit7,
 &sxarwire_fls_code10_bit0,
 &sxarwire_fls_code10_bit1,
 &sxarwire_fls_code10_bit2,
 &sxarwire_fls_code10_bit3,
 &sxarwire_fls_code10_bit4,
 &sxarwire_fls_code10_bit5,
 &sxarwire_fls_code10_bit6,
 &sxarwire_fls_code10_bit7,
 &sxarwire_fls_code12_bit0,
 &sxarwire_fls_code12_bit1,
 &sxarwire_fls_code12_bit2,
 &sxarwire_fls_code12_bit3,
 &sxarwire_fls_code12_bit4,
 &sxarwire_fls_code12_bit5,
 &sxarwire_fls_code12_bit6,
 &sxarwire_fls_code12_bit7,
 &sxarwire_sco_signature,
 &sxarwire_sco_block_count_bit0,
 &sxarwire_sco_block_count_bit1,
 &sxarwire_sco_block_count_bit2,
 &sxarwire_sco_block_count_bit3,
 &sxarwire_sco_block_count_bit4,
 &sxarwire_sco_block_count_bit5,
 &sxarwire_sco_block_count_bit6,
 &sxarwire_sco_block_count_bit7,
 &sxarwire_sco_pretree_count_bit0,
 &sxarwire_sco_pretree_count_bit1,
 &sxarwire_sco_pretree_count_bit2,
 &sxarwire_sco_pretree_count_bit3,
 &sxarwire_sco_pretree_count_bit4,
 &sxarwire_sco_pretree_count_bit5,
 &sxarwire_sco_pretree_count_bit6,
 &sxarwire_sco_pretree_count_bit7,
 &sxarwire_sco_pretree_single_bit0,
 &sxarwire_sco_pretree_single_bit1,
 &sxarwire_sco_pretree_single_bit2,
 &sxarwire_sco_pretree_single_bit3,
 &sxarwire_sco_pretree_single_bit4,
 &sxarwire_sco_pretree_single_bit5,
 &sxarwire_sco_pretree_single_bit6,
 &sxarwire_sco_pretree_single_bit7,
 &sxarwire_sco_code_length_bit0,
 &sxarwire_sco_code_length_bit1,
 &sxarwire_sco_code_length_bit2,
 &sxarwire_sco_code_length_bit3,
 &sxarwire_sco_code_length_bit4,
 &sxarwire_sco_code_length_bit5,
 &sxarwire_sco_code_length_bit6,
 &sxarwire_sco_code_length_bit7,
 &sxarwire_sco_code_length_more_bit0,
 &sxarwire_sco_code_length_more_bit1,
 &sxarwire_sco_code_length_more_bit2,
 &sxarwire_sco_code_length_more_bit3,
 &sxarwire_sco_code_length_more_bit4,
 &sxarwire_sco_code_length_more_bit5,
 &sxarwire_sco_code_length_more_bit6,
 &sxarwire_sco_code_length_more_bit7,
 &sxarwire_sco_pretree_zeros_bit0,
 &sxarwire_sco_pretree_zeros_bit1,
 &sxarwire_sco_pretree_zeros_bit2,
 &sxarwire_sco_pretree_zeros_bit3,
 &sxarwire_sco_pretree_zeros_bit4,
 &sxarwire_sco_pretree_zeros_bit5,
 &sxarwire_sco_pretree_zeros_bit6,
 &sxarwire_sco_pretree_zeros_bit7,
 &sxarwire_sco_literal_count_bit0,
 &sxarwire_sco_literal_count_bit1,
 &sxarwire_sco_literal_count_bit2,
 &sxarwire_sco_literal_count_bit3,
 &sxarwire_sco_literal_count_bit4,
 &sxarwire_sco_literal_count_bit5,
 &sxarwire_sco_literal_count_bit6,
 &sxarwire_sco_literal_count_bit7,
 &sxarwire_sco_literal_single_bit0,
 &sxarwire_sco_literal_single_bit1,
 &sxarwire_sco_literal_single_bit2,
 &sxarwire_sco_literal_single_bit3,
 &sxarwire_sco_literal_single_bit4,
 &sxarwire_sco_literal_single_bit5,
 &sxarwire_sco_literal_single_bit6,
 &sxarwire_sco_literal_single_bit7,
 &sxarwire_sco_position_count_bit0,
 &sxarwire_sco_position_count_bit1,
 &sxarwire_sco_position_count_bit2,
 &sxarwire_sco_position_count_bit3,
 &sxarwire_sco_position_count_bit4,
 &sxarwire_sco_position_count_bit5,
 &sxarwire_sco_position_count_bit6,
 &sxarwire_sco_position_count_bit7,
 &sxarwire_sco_position_single_bit0,
 &sxarwire_sco_position_single_bit1,
 &sxarwire_sco_position_single_bit2,
 &sxarwire_sco_position_single_bit3,
 &sxarwire_sco_position_single_bit4,
 &sxarwire_sco_position_single_bit5,
 &sxarwire_sco_position_single_bit6,
 &sxarwire_sco_position_single_bit7,
 &sxarwire_sco_zero_repeat4_bit0,
 &sxarwire_sco_zero_repeat4_bit1,
 &sxarwire_sco_zero_repeat4_bit2,
 &sxarwire_sco_zero_repeat4_bit3,
 &sxarwire_sco_zero_repeat4_bit4,
 &sxarwire_sco_zero_repeat4_bit5,
 &sxarwire_sco_zero_repeat4_bit6,
 &sxarwire_sco_zero_repeat4_bit7,
 &sxarwire_sco_zero_repeat9_bit0,
 &sxarwire_sco_zero_repeat9_bit1,
 &sxarwire_sco_zero_repeat9_bit2,
 &sxarwire_sco_zero_repeat9_bit3,
 &sxarwire_sco_zero_repeat9_bit4,
 &sxarwire_sco_zero_repeat9_bit5,
 &sxarwire_sco_zero_repeat9_bit6,
 &sxarwire_sco_zero_repeat9_bit7,
 &sxarwire_ardi_geometry_record,
 &sxarwire_ardi_trailer,
 &sxarwire_brotli_window1_bit0,
 &sxarwire_brotli_window4_bit0,
 &sxarwire_brotli_window7_bit0,
 &sxarwire_brotli_last_bit0,
 &sxarwire_brotli_last_bit1,
 &sxarwire_brotli_last_bit2,
 &sxarwire_brotli_last_bit3,
 &sxarwire_brotli_last_bit4,
 &sxarwire_brotli_last_bit5,
 &sxarwire_brotli_last_bit6,
 &sxarwire_brotli_last_bit7,
 &sxarwire_brotli_empty_bit0,
 &sxarwire_brotli_empty_bit1,
 &sxarwire_brotli_empty_bit2,
 &sxarwire_brotli_empty_bit3,
 &sxarwire_brotli_empty_bit4,
 &sxarwire_brotli_empty_bit5,
 &sxarwire_brotli_empty_bit6,
 &sxarwire_brotli_empty_bit7,
 &sxarwire_brotli_nibbles_bit0,
 &sxarwire_brotli_nibbles_bit1,
 &sxarwire_brotli_nibbles_bit2,
 &sxarwire_brotli_nibbles_bit3,
 &sxarwire_brotli_nibbles_bit4,
 &sxarwire_brotli_nibbles_bit5,
 &sxarwire_brotli_nibbles_bit6,
 &sxarwire_brotli_nibbles_bit7,
 &sxarwire_brotli_reserved_bit0,
 &sxarwire_brotli_reserved_bit1,
 &sxarwire_brotli_reserved_bit2,
 &sxarwire_brotli_reserved_bit3,
 &sxarwire_brotli_reserved_bit4,
 &sxarwire_brotli_reserved_bit5,
 &sxarwire_brotli_reserved_bit6,
 &sxarwire_brotli_reserved_bit7,
 &sxarwire_brotli_skipbytes_bit0,
 &sxarwire_brotli_skipbytes_bit1,
 &sxarwire_brotli_skipbytes_bit2,
 &sxarwire_brotli_skipbytes_bit3,
 &sxarwire_brotli_skipbytes_bit4,
 &sxarwire_brotli_skipbytes_bit5,
 &sxarwire_brotli_skipbytes_bit6,
 &sxarwire_brotli_skipbytes_bit7,
 &sxarwire_brotli_skiplen8_bit0,
 &sxarwire_brotli_skiplen8_bit1,
 &sxarwire_brotli_skiplen8_bit2,
 &sxarwire_brotli_skiplen8_bit3,
 &sxarwire_brotli_skiplen8_bit4,
 &sxarwire_brotli_skiplen8_bit5,
 &sxarwire_brotli_skiplen8_bit6,
 &sxarwire_brotli_skiplen8_bit7,
 &sxarwire_brotli_skiplen16_bit0,
 &sxarwire_brotli_skiplen16_bit1,
 &sxarwire_brotli_skiplen16_bit2,
 &sxarwire_brotli_skiplen16_bit3,
 &sxarwire_brotli_skiplen16_bit4,
 &sxarwire_brotli_skiplen16_bit5,
 &sxarwire_brotli_skiplen16_bit6,
 &sxarwire_brotli_skiplen16_bit7,
 &sxarwire_brotli_skiplen24_bit0,
 &sxarwire_brotli_skiplen24_bit1,
 &sxarwire_brotli_skiplen24_bit2,
 &sxarwire_brotli_skiplen24_bit3,
 &sxarwire_brotli_skiplen24_bit4,
 &sxarwire_brotli_skiplen24_bit5,
 &sxarwire_brotli_skiplen24_bit6,
 &sxarwire_brotli_skiplen24_bit7,
 &sxarwire_brotli_length16_bit0,
 &sxarwire_brotli_length16_bit1,
 &sxarwire_brotli_length16_bit2,
 &sxarwire_brotli_length16_bit3,
 &sxarwire_brotli_length16_bit4,
 &sxarwire_brotli_length16_bit5,
 &sxarwire_brotli_length16_bit6,
 &sxarwire_brotli_length16_bit7,
 &sxarwire_brotli_length20_bit0,
 &sxarwire_brotli_length20_bit1,
 &sxarwire_brotli_length20_bit2,
 &sxarwire_brotli_length20_bit3,
 &sxarwire_brotli_length20_bit4,
 &sxarwire_brotli_length20_bit5,
 &sxarwire_brotli_length20_bit6,
 &sxarwire_brotli_length20_bit7,
 &sxarwire_brotli_length24_bit0,
 &sxarwire_brotli_length24_bit1,
 &sxarwire_brotli_length24_bit2,
 &sxarwire_brotli_length24_bit3,
 &sxarwire_brotli_length24_bit4,
 &sxarwire_brotli_length24_bit5,
 &sxarwire_brotli_length24_bit6,
 &sxarwire_brotli_length24_bit7,
 &sxarwire_brotli_uncompressed_bit0,
 &sxarwire_brotli_uncompressed_bit1,
 &sxarwire_brotli_uncompressed_bit2,
 &sxarwire_brotli_uncompressed_bit3,
 &sxarwire_brotli_uncompressed_bit4,
 &sxarwire_brotli_uncompressed_bit5,
 &sxarwire_brotli_uncompressed_bit6,
 &sxarwire_brotli_uncompressed_bit7,
 &sxarwire_brotli_fill1_bit7,
 &sxarwire_brotli_fill2_bit6,
 &sxarwire_brotli_fill3_bit5,
 &sxarwire_brotli_fill4_bit4,
 &sxarwire_brotli_fill5_bit3,
 &sxarwire_brotli_fill6_bit2,
 &sxarwire_brotli_fill7_bit1,
 &sxarwire_deflate_block_bit0,
 &sxarwire_deflate_block_bit1,
 &sxarwire_deflate_block_bit2,
 &sxarwire_deflate_block_bit3,
 &sxarwire_deflate_block_bit4,
 &sxarwire_deflate_block_bit5,
 &sxarwire_deflate_block_bit6,
 &sxarwire_deflate_block_bit7,
 &sxarwire_deflate_stored_lengths,
 &sxarwire_deflate_hlit_bit0,
 &sxarwire_deflate_hlit_bit1,
 &sxarwire_deflate_hlit_bit2,
 &sxarwire_deflate_hlit_bit3,
 &sxarwire_deflate_hlit_bit4,
 &sxarwire_deflate_hlit_bit5,
 &sxarwire_deflate_hlit_bit6,
 &sxarwire_deflate_hlit_bit7,
 &sxarwire_deflate_hdist_bit0,
 &sxarwire_deflate_hdist_bit1,
 &sxarwire_deflate_hdist_bit2,
 &sxarwire_deflate_hdist_bit3,
 &sxarwire_deflate_hdist_bit4,
 &sxarwire_deflate_hdist_bit5,
 &sxarwire_deflate_hdist_bit6,
 &sxarwire_deflate_hdist_bit7,
 &sxarwire_deflate_hclen_bit0,
 &sxarwire_deflate_hclen_bit1,
 &sxarwire_deflate_hclen_bit2,
 &sxarwire_deflate_hclen_bit3,
 &sxarwire_deflate_hclen_bit4,
 &sxarwire_deflate_hclen_bit5,
 &sxarwire_deflate_hclen_bit6,
 &sxarwire_deflate_hclen_bit7,
 &sxarwire_deflate_code_length_bit0,
 &sxarwire_deflate_code_length_bit1,
 &sxarwire_deflate_code_length_bit2,
 &sxarwire_deflate_code_length_bit3,
 &sxarwire_deflate_code_length_bit4,
 &sxarwire_deflate_code_length_bit5,
 &sxarwire_deflate_code_length_bit6,
 &sxarwire_deflate_code_length_bit7,
 &sxarwire_deflate_repeat2_bit0,
 &sxarwire_deflate_repeat2_bit1,
 &sxarwire_deflate_repeat2_bit2,
 &sxarwire_deflate_repeat2_bit3,
 &sxarwire_deflate_repeat2_bit4,
 &sxarwire_deflate_repeat2_bit5,
 &sxarwire_deflate_repeat2_bit6,
 &sxarwire_deflate_repeat2_bit7,
 &sxarwire_deflate_repeat3_bit0,
 &sxarwire_deflate_repeat3_bit1,
 &sxarwire_deflate_repeat3_bit2,
 &sxarwire_deflate_repeat3_bit3,
 &sxarwire_deflate_repeat3_bit4,
 &sxarwire_deflate_repeat3_bit5,
 &sxarwire_deflate_repeat3_bit6,
 &sxarwire_deflate_repeat3_bit7,
 &sxarwire_deflate_repeat7_bit0,
 &sxarwire_deflate_repeat7_bit1,
 &sxarwire_deflate_repeat7_bit2,
 &sxarwire_deflate_repeat7_bit3,
 &sxarwire_deflate_repeat7_bit4,
 &sxarwire_deflate_repeat7_bit5,
 &sxarwire_deflate_repeat7_bit6,
 &sxarwire_deflate_repeat7_bit7,
 &sxarwire_sco_table_prefix1_bit0,
 &sxarwire_sco_table_prefix1_bit1,
 &sxarwire_sco_table_prefix1_bit2,
 &sxarwire_sco_table_prefix1_bit3,
 &sxarwire_sco_table_prefix1_bit4,
 &sxarwire_sco_table_prefix1_bit5,
 &sxarwire_sco_table_prefix1_bit6,
 &sxarwire_sco_table_prefix1_bit7,
 &sxarwire_sco_table_prefix2_bit0,
 &sxarwire_sco_table_prefix2_bit1,
 &sxarwire_sco_table_prefix2_bit2,
 &sxarwire_sco_table_prefix2_bit3,
 &sxarwire_sco_table_prefix2_bit4,
 &sxarwire_sco_table_prefix2_bit5,
 &sxarwire_sco_table_prefix2_bit6,
 &sxarwire_sco_table_prefix2_bit7,
 &sxarwire_sco_table_prefix3_bit0,
 &sxarwire_sco_table_prefix3_bit1,
 &sxarwire_sco_table_prefix3_bit2,
 &sxarwire_sco_table_prefix3_bit3,
 &sxarwire_sco_table_prefix3_bit4,
 &sxarwire_sco_table_prefix3_bit5,
 &sxarwire_sco_table_prefix3_bit6,
 &sxarwire_sco_table_prefix3_bit7,
 &sxarwire_sco_table_prefix4_bit0,
 &sxarwire_sco_table_prefix4_bit1,
 &sxarwire_sco_table_prefix4_bit2,
 &sxarwire_sco_table_prefix4_bit3,
 &sxarwire_sco_table_prefix4_bit4,
 &sxarwire_sco_table_prefix4_bit5,
 &sxarwire_sco_table_prefix4_bit6,
 &sxarwire_sco_table_prefix4_bit7,
 &sxarwire_sco_table_prefix5_bit0,
 &sxarwire_sco_table_prefix5_bit1,
 &sxarwire_sco_table_prefix5_bit2,
 &sxarwire_sco_table_prefix5_bit3,
 &sxarwire_sco_table_prefix5_bit4,
 &sxarwire_sco_table_prefix5_bit5,
 &sxarwire_sco_table_prefix5_bit6,
 &sxarwire_sco_table_prefix5_bit7,
 &sxarwire_sco_table_prefix6_bit0,
 &sxarwire_sco_table_prefix6_bit1,
 &sxarwire_sco_table_prefix6_bit2,
 &sxarwire_sco_table_prefix6_bit3,
 &sxarwire_sco_table_prefix6_bit4,
 &sxarwire_sco_table_prefix6_bit5,
 &sxarwire_sco_table_prefix6_bit6,
 &sxarwire_sco_table_prefix6_bit7,
 &sxarwire_sco_table_prefix7_bit0,
 &sxarwire_sco_table_prefix7_bit1,
 &sxarwire_sco_table_prefix7_bit2,
 &sxarwire_sco_table_prefix7_bit3,
 &sxarwire_sco_table_prefix7_bit4,
 &sxarwire_sco_table_prefix7_bit5,
 &sxarwire_sco_table_prefix7_bit6,
 &sxarwire_sco_table_prefix7_bit7,
 &sxarwire_sco_table_prefix8_bit0,
 &sxarwire_sco_table_prefix8_bit1,
 &sxarwire_sco_table_prefix8_bit2,
 &sxarwire_sco_table_prefix8_bit3,
 &sxarwire_sco_table_prefix8_bit4,
 &sxarwire_sco_table_prefix8_bit5,
 &sxarwire_sco_table_prefix8_bit6,
 &sxarwire_sco_table_prefix8_bit7,
 &sxarwire_sco_table_prefix9_bit0,
 &sxarwire_sco_table_prefix9_bit1,
 &sxarwire_sco_table_prefix9_bit2,
 &sxarwire_sco_table_prefix9_bit3,
 &sxarwire_sco_table_prefix9_bit4,
 &sxarwire_sco_table_prefix9_bit5,
 &sxarwire_sco_table_prefix9_bit6,
 &sxarwire_sco_table_prefix9_bit7,
 &sxarwire_sco_table_prefix10_bit0,
 &sxarwire_sco_table_prefix10_bit1,
 &sxarwire_sco_table_prefix10_bit2,
 &sxarwire_sco_table_prefix10_bit3,
 &sxarwire_sco_table_prefix10_bit4,
 &sxarwire_sco_table_prefix10_bit5,
 &sxarwire_sco_table_prefix10_bit6,
 &sxarwire_sco_table_prefix10_bit7,
 &sxarwire_sco_table_prefix11_bit0,
 &sxarwire_sco_table_prefix11_bit1,
 &sxarwire_sco_table_prefix11_bit2,
 &sxarwire_sco_table_prefix11_bit3,
 &sxarwire_sco_table_prefix11_bit4,
 &sxarwire_sco_table_prefix11_bit5,
 &sxarwire_sco_table_prefix11_bit6,
 &sxarwire_sco_table_prefix11_bit7,
 &sxarwire_sco_table_prefix12_bit0,
 &sxarwire_sco_table_prefix12_bit1,
 &sxarwire_sco_table_prefix12_bit2,
 &sxarwire_sco_table_prefix12_bit3,
 &sxarwire_sco_table_prefix12_bit4,
 &sxarwire_sco_table_prefix12_bit5,
 &sxarwire_sco_table_prefix12_bit6,
 &sxarwire_sco_table_prefix12_bit7,
 &sxarwire_sco_table_prefix13_bit0,
 &sxarwire_sco_table_prefix13_bit1,
 &sxarwire_sco_table_prefix13_bit2,
 &sxarwire_sco_table_prefix13_bit3,
 &sxarwire_sco_table_prefix13_bit4,
 &sxarwire_sco_table_prefix13_bit5,
 &sxarwire_sco_table_prefix13_bit6,
 &sxarwire_sco_table_prefix13_bit7,
 &sxarwire_sco_table_prefix14_bit0,
 &sxarwire_sco_table_prefix14_bit1,
 &sxarwire_sco_table_prefix14_bit2,
 &sxarwire_sco_table_prefix14_bit3,
 &sxarwire_sco_table_prefix14_bit4,
 &sxarwire_sco_table_prefix14_bit5,
 &sxarwire_sco_table_prefix14_bit6,
 &sxarwire_sco_table_prefix14_bit7,
 &sxarwire_sco_table_prefix15_bit0,
 &sxarwire_sco_table_prefix15_bit1,
 &sxarwire_sco_table_prefix15_bit2,
 &sxarwire_sco_table_prefix15_bit3,
 &sxarwire_sco_table_prefix15_bit4,
 &sxarwire_sco_table_prefix15_bit5,
 &sxarwire_sco_table_prefix15_bit6,
 &sxarwire_sco_table_prefix15_bit7,
 &sxarwire_sco_table_prefix16_bit0,
 &sxarwire_sco_table_prefix16_bit1,
 &sxarwire_sco_table_prefix16_bit2,
 &sxarwire_sco_table_prefix16_bit3,
 &sxarwire_sco_table_prefix16_bit4,
 &sxarwire_sco_table_prefix16_bit5,
 &sxarwire_sco_table_prefix16_bit6,
 &sxarwire_sco_table_prefix16_bit7,
 &sxarwire_deflate_table_prefix1_bit0,
 &sxarwire_deflate_table_prefix1_bit1,
 &sxarwire_deflate_table_prefix1_bit2,
 &sxarwire_deflate_table_prefix1_bit3,
 &sxarwire_deflate_table_prefix1_bit4,
 &sxarwire_deflate_table_prefix1_bit5,
 &sxarwire_deflate_table_prefix1_bit6,
 &sxarwire_deflate_table_prefix1_bit7,
 &sxarwire_deflate_table_prefix2_bit0,
 &sxarwire_deflate_table_prefix2_bit1,
 &sxarwire_deflate_table_prefix2_bit2,
 &sxarwire_deflate_table_prefix2_bit3,
 &sxarwire_deflate_table_prefix2_bit4,
 &sxarwire_deflate_table_prefix2_bit5,
 &sxarwire_deflate_table_prefix2_bit6,
 &sxarwire_deflate_table_prefix2_bit7,
 &sxarwire_deflate_table_prefix3_bit0,
 &sxarwire_deflate_table_prefix3_bit1,
 &sxarwire_deflate_table_prefix3_bit2,
 &sxarwire_deflate_table_prefix3_bit3,
 &sxarwire_deflate_table_prefix3_bit4,
 &sxarwire_deflate_table_prefix3_bit5,
 &sxarwire_deflate_table_prefix3_bit6,
 &sxarwire_deflate_table_prefix3_bit7,
 &sxarwire_deflate_table_prefix4_bit0,
 &sxarwire_deflate_table_prefix4_bit1,
 &sxarwire_deflate_table_prefix4_bit2,
 &sxarwire_deflate_table_prefix4_bit3,
 &sxarwire_deflate_table_prefix4_bit4,
 &sxarwire_deflate_table_prefix4_bit5,
 &sxarwire_deflate_table_prefix4_bit6,
 &sxarwire_deflate_table_prefix4_bit7,
 &sxarwire_deflate_table_prefix5_bit0,
 &sxarwire_deflate_table_prefix5_bit1,
 &sxarwire_deflate_table_prefix5_bit2,
 &sxarwire_deflate_table_prefix5_bit3,
 &sxarwire_deflate_table_prefix5_bit4,
 &sxarwire_deflate_table_prefix5_bit5,
 &sxarwire_deflate_table_prefix5_bit6,
 &sxarwire_deflate_table_prefix5_bit7,
 &sxarwire_deflate_table_prefix6_bit0,
 &sxarwire_deflate_table_prefix6_bit1,
 &sxarwire_deflate_table_prefix6_bit2,
 &sxarwire_deflate_table_prefix6_bit3,
 &sxarwire_deflate_table_prefix6_bit4,
 &sxarwire_deflate_table_prefix6_bit5,
 &sxarwire_deflate_table_prefix6_bit6,
 &sxarwire_deflate_table_prefix6_bit7,
 &sxarwire_deflate_table_prefix7_bit0,
 &sxarwire_deflate_table_prefix7_bit1,
 &sxarwire_deflate_table_prefix7_bit2,
 &sxarwire_deflate_table_prefix7_bit3,
 &sxarwire_deflate_table_prefix7_bit4,
 &sxarwire_deflate_table_prefix7_bit5,
 &sxarwire_deflate_table_prefix7_bit6,
 &sxarwire_deflate_table_prefix7_bit7,
 &sxarwire_brotli_mt_frame,
};
static bool sx_archivewire_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x608d0000U||id>=0x608e0000U)return true;const wchar_t*text=NULL;switch(id){
 case 0x608d0003U:text=L"FLS adaptive-phrase stream tag0x53; not a member header.";break;
 case 0x608d0005U:text=L"Native-supported12-byte SPACK profile. Remaining profile bytes are preserved without inferred length or address semantics.";break;
 case 0x608d0006U:text=L"0=literal8-bit byte;1=match or stream terminator.";break;
 case 0x608d0007U:text=L"0=literal8-bit byte;1=match or stream terminator.";break;
 case 0x608d0008U:text=L"0=literal8-bit byte;1=match or stream terminator.";break;
 case 0x608d0009U:text=L"0=literal8-bit byte;1=match or stream terminator.";break;
 case 0x608d000aU:text=L"0=literal8-bit byte;1=match or stream terminator.";break;
 case 0x608d000bU:text=L"0=literal8-bit byte;1=match or stream terminator.";break;
 case 0x608d000cU:text=L"0=literal8-bit byte;1=match or stream terminator.";break;
 case 0x608d000dU:text=L"0=literal8-bit byte;1=match or stream terminator.";break;
 case 0x608d000eU:text=L"1 selects7-bit distance;0 selects11-bit distance.";break;
 case 0x608d000fU:text=L"1 selects7-bit distance;0 selects11-bit distance.";break;
 case 0x608d0010U:text=L"1 selects7-bit distance;0 selects11-bit distance.";break;
 case 0x608d0011U:text=L"1 selects7-bit distance;0 selects11-bit distance.";break;
 case 0x608d0012U:text=L"1 selects7-bit distance;0 selects11-bit distance.";break;
 case 0x608d0013U:text=L"1 selects7-bit distance;0 selects11-bit distance.";break;
 case 0x608d0014U:text=L"1 selects7-bit distance;0 selects11-bit distance.";break;
 case 0x608d0015U:text=L"1 selects7-bit distance;0 selects11-bit distance.";break;
 case 0x608d001eU:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d001fU:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d0020U:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d0021U:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d0022U:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d0023U:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d0024U:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d0025U:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d0026U:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d0027U:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d0028U:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d0029U:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d002aU:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d002bU:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d002cU:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d002dU:text=L"Distance back in decoded output bytes, not a physical file offset. Short distance0 is the end marker.";break;
 case 0x608d002eU:text=L"First2bits:0..2 means length2..4;3 introduces a second2-bit prefix.";break;
 case 0x608d002fU:text=L"First2bits:0..2 means length2..4;3 introduces a second2-bit prefix.";break;
 case 0x608d0030U:text=L"First2bits:0..2 means length2..4;3 introduces a second2-bit prefix.";break;
 case 0x608d0031U:text=L"First2bits:0..2 means length2..4;3 introduces a second2-bit prefix.";break;
 case 0x608d0032U:text=L"First2bits:0..2 means length2..4;3 introduces a second2-bit prefix.";break;
 case 0x608d0033U:text=L"First2bits:0..2 means length2..4;3 introduces a second2-bit prefix.";break;
 case 0x608d0034U:text=L"First2bits:0..2 means length2..4;3 introduces a second2-bit prefix.";break;
 case 0x608d0035U:text=L"First2bits:0..2 means length2..4;3 introduces a second2-bit prefix.";break;
 case 0x608d0036U:text=L"Second2bits:0..2 means length5..7;3 introduces4-bit extension groups.";break;
 case 0x608d0037U:text=L"Second2bits:0..2 means length5..7;3 introduces4-bit extension groups.";break;
 case 0x608d0038U:text=L"Second2bits:0..2 means length5..7;3 introduces4-bit extension groups.";break;
 case 0x608d0039U:text=L"Second2bits:0..2 means length5..7;3 introduces4-bit extension groups.";break;
 case 0x608d003aU:text=L"Second2bits:0..2 means length5..7;3 introduces4-bit extension groups.";break;
 case 0x608d003bU:text=L"Second2bits:0..2 means length5..7;3 introduces4-bit extension groups.";break;
 case 0x608d003cU:text=L"Second2bits:0..2 means length5..7;3 introduces4-bit extension groups.";break;
 case 0x608d003dU:text=L"Second2bits:0..2 means length5..7;3 introduces4-bit extension groups.";break;
 case 0x608d003eU:text=L"Extension nibble adds to a base length8;15 requires another extension nibble. Physical encoded value is retained.";break;
 case 0x608d003fU:text=L"Extension nibble adds to a base length8;15 requires another extension nibble. Physical encoded value is retained.";break;
 case 0x608d0040U:text=L"Extension nibble adds to a base length8;15 requires another extension nibble. Physical encoded value is retained.";break;
 case 0x608d0041U:text=L"Extension nibble adds to a base length8;15 requires another extension nibble. Physical encoded value is retained.";break;
 case 0x608d0042U:text=L"Extension nibble adds to a base length8;15 requires another extension nibble. Physical encoded value is retained.";break;
 case 0x608d0043U:text=L"Extension nibble adds to a base length8;15 requires another extension nibble. Physical encoded value is retained.";break;
 case 0x608d0044U:text=L"Extension nibble adds to a base length8;15 requires another extension nibble. Physical encoded value is retained.";break;
 case 0x608d0045U:text=L"Extension nibble adds to a base length8;15 requires another extension nibble. Physical encoded value is retained.";break;
 case 0x608d0046U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0047U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0048U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0049U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d004aU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d004bU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d004cU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d004dU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d004eU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d004fU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0050U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0051U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0052U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0053U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0054U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0055U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0056U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0057U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0058U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0059U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d005aU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d005bU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d005cU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d005dU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d005eU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d005fU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0060U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0061U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0062U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0063U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0064U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0065U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0066U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0067U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0068U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0069U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d006aU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d006bU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d006cU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d006dU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d006eU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d006fU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0070U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0071U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0072U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0073U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0074U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0075U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0076U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0077U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0078U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d0079U:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d007aU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d007bU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d007cU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d007dU:text=L"0..255 literal;256 END;257 BUMP increments stored code width;258 CLEAR resets to9bits. Larger codes reference the adaptive dictionary.";break;
 case 0x608d007eU:text=L"Stored SPACK12-bit code:0 ends stream; otherwise subtract1 to obtain literal/pair-tree code.";break;
 case 0x608d007fU:text=L"Stored SPACK12-bit code:0 ends stream; otherwise subtract1 to obtain literal/pair-tree code.";break;
 case 0x608d0080U:text=L"First of six code-width classes, stored anew every500 tokens; must be0..5.";break;
 case 0x608d0081U:text=L"First of six code-width classes, stored anew every500 tokens; must be0..5.";break;
 case 0x608d0082U:text=L"First of six code-width classes, stored anew every500 tokens; must be0..5.";break;
 case 0x608d0083U:text=L"First of six code-width classes, stored anew every500 tokens; must be0..5.";break;
 case 0x608d0084U:text=L"First of six code-width classes, stored anew every500 tokens; must be0..5.";break;
 case 0x608d0085U:text=L"First of six code-width classes, stored anew every500 tokens; must be0..5.";break;
 case 0x608d0086U:text=L"First of six code-width classes, stored anew every500 tokens; must be0..5.";break;
 case 0x608d0087U:text=L"First of six code-width classes, stored anew every500 tokens; must be0..5.";break;
 case 0x608d0088U:text=L"Second distinct code-width class. The other classes follow in ascending order.";break;
 case 0x608d0089U:text=L"Second distinct code-width class. The other classes follow in ascending order.";break;
 case 0x608d008aU:text=L"Second distinct code-width class. The other classes follow in ascending order.";break;
 case 0x608d008bU:text=L"Second distinct code-width class. The other classes follow in ascending order.";break;
 case 0x608d008cU:text=L"Second distinct code-width class. The other classes follow in ascending order.";break;
 case 0x608d008dU:text=L"Second distinct code-width class. The other classes follow in ascending order.";break;
 case 0x608d008eU:text=L"Second distinct code-width class. The other classes follow in ascending order.";break;
 case 0x608d008fU:text=L"Second distinct code-width class. The other classes follow in ascending order.";break;
 case 0x608d0090U:text=L"0/1 select first/second class;2/3 introduce one extra selector bit.";break;
 case 0x608d0091U:text=L"0/1 select first/second class;2/3 introduce one extra selector bit.";break;
 case 0x608d0092U:text=L"0/1 select first/second class;2/3 introduce one extra selector bit.";break;
 case 0x608d0093U:text=L"0/1 select first/second class;2/3 introduce one extra selector bit.";break;
 case 0x608d0094U:text=L"0/1 select first/second class;2/3 introduce one extra selector bit.";break;
 case 0x608d0095U:text=L"0/1 select first/second class;2/3 introduce one extra selector bit.";break;
 case 0x608d0096U:text=L"0/1 select first/second class;2/3 introduce one extra selector bit.";break;
 case 0x608d0097U:text=L"0/1 select first/second class;2/3 introduce one extra selector bit.";break;
 case 0x608d0098U:text=L"For prefix2/3, selected rank is2*prefix-2+this bit.";break;
 case 0x608d0099U:text=L"For prefix2/3, selected rank is2*prefix-2+this bit.";break;
 case 0x608d009aU:text=L"For prefix2/3, selected rank is2*prefix-2+this bit.";break;
 case 0x608d009bU:text=L"For prefix2/3, selected rank is2*prefix-2+this bit.";break;
 case 0x608d009cU:text=L"For prefix2/3, selected rank is2*prefix-2+this bit.";break;
 case 0x608d009dU:text=L"For prefix2/3, selected rank is2*prefix-2+this bit.";break;
 case 0x608d009eU:text=L"For prefix2/3, selected rank is2*prefix-2+this bit.";break;
 case 0x608d009fU:text=L"For prefix2/3, selected rank is2*prefix-2+this bit.";break;
 case 0x608d00a0U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00a1U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00a2U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00a3U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00a4U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00a5U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00a6U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00a7U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00a8U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00a9U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00aaU:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00abU:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00acU:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00adU:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00aeU:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00afU:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00b0U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00b1U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00b2U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00b3U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00b4U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00b5U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00b6U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00b7U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00b8U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00b9U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00baU:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00bbU:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00bcU:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00bdU:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00beU:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00bfU:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00c0U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00c1U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00c2U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00c3U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00c4U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00c5U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00c6U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00c7U:text=L"Physical class-relative code. Class bases0,128,192,320,576,1600; code5695 ends stream. Reconstructing phrases is outside member display.";break;
 case 0x608d00c9U:text=L"Number of Huffman symbols in this block; zero terminates the stream.";break;
 case 0x608d00caU:text=L"Number of Huffman symbols in this block; zero terminates the stream.";break;
 case 0x608d00cbU:text=L"Number of Huffman symbols in this block; zero terminates the stream.";break;
 case 0x608d00ccU:text=L"Number of Huffman symbols in this block; zero terminates the stream.";break;
 case 0x608d00cdU:text=L"Number of Huffman symbols in this block; zero terminates the stream.";break;
 case 0x608d00ceU:text=L"Number of Huffman symbols in this block; zero terminates the stream.";break;
 case 0x608d00cfU:text=L"Number of Huffman symbols in this block; zero terminates the stream.";break;
 case 0x608d00d0U:text=L"Number of Huffman symbols in this block; zero terminates the stream.";break;
 case 0x608d00e1U:text=L"Stored prefix:0..6 code length;7 extends by a unary run of1 bits terminated by0.";break;
 case 0x608d00e2U:text=L"Stored prefix:0..6 code length;7 extends by a unary run of1 bits terminated by0.";break;
 case 0x608d00e3U:text=L"Stored prefix:0..6 code length;7 extends by a unary run of1 bits terminated by0.";break;
 case 0x608d00e4U:text=L"Stored prefix:0..6 code length;7 extends by a unary run of1 bits terminated by0.";break;
 case 0x608d00e5U:text=L"Stored prefix:0..6 code length;7 extends by a unary run of1 bits terminated by0.";break;
 case 0x608d00e6U:text=L"Stored prefix:0..6 code length;7 extends by a unary run of1 bits terminated by0.";break;
 case 0x608d00e7U:text=L"Stored prefix:0..6 code length;7 extends by a unary run of1 bits terminated by0.";break;
 case 0x608d00e8U:text=L"Stored prefix:0..6 code length;7 extends by a unary run of1 bits terminated by0.";break;
 case 0x608d00f1U:text=L"Number of additional zero-length entries inserted after the third pretree code.";break;
 case 0x608d00f2U:text=L"Number of additional zero-length entries inserted after the third pretree code.";break;
 case 0x608d00f3U:text=L"Number of additional zero-length entries inserted after the third pretree code.";break;
 case 0x608d00f4U:text=L"Number of additional zero-length entries inserted after the third pretree code.";break;
 case 0x608d00f5U:text=L"Number of additional zero-length entries inserted after the third pretree code.";break;
 case 0x608d00f6U:text=L"Number of additional zero-length entries inserted after the third pretree code.";break;
 case 0x608d00f7U:text=L"Number of additional zero-length entries inserted after the third pretree code.";break;
 case 0x608d00f8U:text=L"Number of additional zero-length entries inserted after the third pretree code.";break;
 case 0x608d0119U:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d011aU:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d011bU:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d011cU:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d011dU:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d011eU:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d011fU:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d0120U:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d0121U:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d0122U:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d0123U:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d0124U:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d0125U:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d0126U:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d0127U:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d0128U:text=L"Code-length repeat extra bits:4bits add3,9bits add20; decoded count is not a stored field.";break;
 case 0x608d0129U:text=L"Physical copy of diskette BPB plus declared compressed stream size and CRC32 of decoded disk image. Sector counts are not byte offsets. Geometry bytes retain unknown subfields.";break;
 case 0x608d012aU:text=L"Final51-byte ARDI trailer. Copyright year is decimal text, not a timestamp.";break;
 case 0x608d012bU:text=L"Encoded WBITS prefix from RFC7932, not a byte count. Window size is(1<<WBITS)-16 after decoding the prefix.";break;
 case 0x608d012cU:text=L"Encoded WBITS prefix from RFC7932, not a byte count. Window size is(1<<WBITS)-16 after decoding the prefix.";break;
 case 0x608d012dU:text=L"Encoded WBITS prefix from RFC7932, not a byte count. Window size is(1<<WBITS)-16 after decoding the prefix.";break;
 case 0x608d013eU:text=L"Encoded0/1/2 mean4/5/6 nibbles;3 selects a metadata-only meta-block.";break;
 case 0x608d013fU:text=L"Encoded0/1/2 mean4/5/6 nibbles;3 selects a metadata-only meta-block.";break;
 case 0x608d0140U:text=L"Encoded0/1/2 mean4/5/6 nibbles;3 selects a metadata-only meta-block.";break;
 case 0x608d0141U:text=L"Encoded0/1/2 mean4/5/6 nibbles;3 selects a metadata-only meta-block.";break;
 case 0x608d0142U:text=L"Encoded0/1/2 mean4/5/6 nibbles;3 selects a metadata-only meta-block.";break;
 case 0x608d0143U:text=L"Encoded0/1/2 mean4/5/6 nibbles;3 selects a metadata-only meta-block.";break;
 case 0x608d0144U:text=L"Encoded0/1/2 mean4/5/6 nibbles;3 selects a metadata-only meta-block.";break;
 case 0x608d0145U:text=L"Encoded0/1/2 mean4/5/6 nibbles;3 selects a metadata-only meta-block.";break;
 case 0x608d0146U:text=L"Explicit metadata-only reserved bit; must be zero.";break;
 case 0x608d0147U:text=L"Explicit metadata-only reserved bit; must be zero.";break;
 case 0x608d0148U:text=L"Explicit metadata-only reserved bit; must be zero.";break;
 case 0x608d0149U:text=L"Explicit metadata-only reserved bit; must be zero.";break;
 case 0x608d014aU:text=L"Explicit metadata-only reserved bit; must be zero.";break;
 case 0x608d014bU:text=L"Explicit metadata-only reserved bit; must be zero.";break;
 case 0x608d014cU:text=L"Explicit metadata-only reserved bit; must be zero.";break;
 case 0x608d014dU:text=L"Explicit metadata-only reserved bit; must be zero.";break;
 case 0x608d0156U:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d0157U:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d0158U:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d0159U:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d015aU:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d015bU:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d015cU:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d015dU:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d015eU:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d015fU:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d0160U:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d0161U:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d0162U:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d0163U:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d0164U:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d0165U:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d0166U:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d0167U:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d0168U:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d0169U:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d016aU:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d016bU:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d016cU:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d016dU:text=L"Stored metadata byte length minus1; applies only when length-byte count is nonzero.";break;
 case 0x608d016eU:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d016fU:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0170U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0171U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0172U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0173U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0174U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0175U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0176U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0177U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0178U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0179U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d017aU:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d017bU:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d017cU:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d017dU:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d017eU:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d017fU:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0180U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0181U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0182U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0183U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0184U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d0185U:text=L"Stored meta-block output byte length minus1; this is not the physical compressed extent.";break;
 case 0x608d018eU:text=L"Explicit zero fill to the next byte boundary; compressed payload bits are never labeled padding.";break;
 case 0x608d018fU:text=L"Explicit zero fill to the next byte boundary; compressed payload bits are never labeled padding.";break;
 case 0x608d0190U:text=L"Explicit zero fill to the next byte boundary; compressed payload bits are never labeled padding.";break;
 case 0x608d0191U:text=L"Explicit zero fill to the next byte boundary; compressed payload bits are never labeled padding.";break;
 case 0x608d0192U:text=L"Explicit zero fill to the next byte boundary; compressed payload bits are never labeled padding.";break;
 case 0x608d0193U:text=L"Explicit zero fill to the next byte boundary; compressed payload bits are never labeled padding.";break;
 case 0x608d0194U:text=L"Explicit zero fill to the next byte boundary; compressed payload bits are never labeled padding.";break;
 case 0x608d0195U:text=L"BFINAL and BTYPE:0 stored,1 fixed Huffman,2 dynamic Huffman,3 invalid.";break;
 case 0x608d0196U:text=L"BFINAL and BTYPE:0 stored,1 fixed Huffman,2 dynamic Huffman,3 invalid.";break;
 case 0x608d0197U:text=L"BFINAL and BTYPE:0 stored,1 fixed Huffman,2 dynamic Huffman,3 invalid.";break;
 case 0x608d0198U:text=L"BFINAL and BTYPE:0 stored,1 fixed Huffman,2 dynamic Huffman,3 invalid.";break;
 case 0x608d0199U:text=L"BFINAL and BTYPE:0 stored,1 fixed Huffman,2 dynamic Huffman,3 invalid.";break;
 case 0x608d019aU:text=L"BFINAL and BTYPE:0 stored,1 fixed Huffman,2 dynamic Huffman,3 invalid.";break;
 case 0x608d019bU:text=L"BFINAL and BTYPE:0 stored,1 fixed Huffman,2 dynamic Huffman,3 invalid.";break;
 case 0x608d019cU:text=L"BFINAL and BTYPE:0 stored,1 fixed Huffman,2 dynamic Huffman,3 invalid.";break;
 case 0x608d019dU:text=L"LEN and bitwise complement NLEN; declared stored bytes follow. NLEN is not another size.";break;
 case 0x608d01b6U:text=L"Three-bit code length in RFC1951 permutation16,17,18,0,8,7,9,6,10,5,11,4,12,3,13,2,14,1,15.";break;
 case 0x608d01b7U:text=L"Three-bit code length in RFC1951 permutation16,17,18,0,8,7,9,6,10,5,11,4,12,3,13,2,14,1,15.";break;
 case 0x608d01b8U:text=L"Three-bit code length in RFC1951 permutation16,17,18,0,8,7,9,6,10,5,11,4,12,3,13,2,14,1,15.";break;
 case 0x608d01b9U:text=L"Three-bit code length in RFC1951 permutation16,17,18,0,8,7,9,6,10,5,11,4,12,3,13,2,14,1,15.";break;
 case 0x608d01baU:text=L"Three-bit code length in RFC1951 permutation16,17,18,0,8,7,9,6,10,5,11,4,12,3,13,2,14,1,15.";break;
 case 0x608d01bbU:text=L"Three-bit code length in RFC1951 permutation16,17,18,0,8,7,9,6,10,5,11,4,12,3,13,2,14,1,15.";break;
 case 0x608d01bcU:text=L"Three-bit code length in RFC1951 permutation16,17,18,0,8,7,9,6,10,5,11,4,12,3,13,2,14,1,15.";break;
 case 0x608d01bdU:text=L"Three-bit code length in RFC1951 permutation16,17,18,0,8,7,9,6,10,5,11,4,12,3,13,2,14,1,15.";break;
 case 0x608d01beU:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01bfU:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01c0U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01c1U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01c2U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01c3U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01c4U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01c5U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01c6U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01c7U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01c8U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01c9U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01caU:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01cbU:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01ccU:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01cdU:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01ceU:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01cfU:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01d0U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01d1U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01d2U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01d3U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01d4U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01d5U:text=L"Physical repeat extra bits: widths2/3 add3, width7 adds11. Previous decoded prefix selects repeat meaning.";break;
 case 0x608d01d6U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01d7U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01d8U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01d9U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01daU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01dbU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01dcU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01ddU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01deU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01dfU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01e0U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01e1U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01e2U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01e3U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01e4U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01e5U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01e6U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01e7U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01e8U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01e9U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01eaU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01ebU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01ecU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01edU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01eeU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01efU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01f0U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01f1U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01f2U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01f3U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01f4U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01f5U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01f6U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01f7U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01f8U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01f9U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01faU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01fbU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01fcU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01fdU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01feU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d01ffU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0200U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0201U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0202U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0203U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0204U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0205U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0206U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0207U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0208U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0209U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d020aU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d020bU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d020cU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d020dU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d020eU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d020fU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0210U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0211U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0212U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0213U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0214U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0215U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0216U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0217U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0218U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0219U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d021aU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d021bU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d021cU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d021dU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d021eU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d021fU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0220U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0221U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0222U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0223U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0224U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0225U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0226U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0227U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0228U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0229U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d022aU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d022bU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d022cU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d022dU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d022eU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d022fU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0230U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0231U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0232U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0233U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0234U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0235U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0236U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0237U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0238U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0239U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d023aU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d023bU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d023cU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d023dU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d023eU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d023fU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0240U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0241U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0242U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0243U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0244U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0245U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0246U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0247U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0248U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0249U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d024aU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d024bU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d024cU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d024dU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d024eU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d024fU:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0250U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0251U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0252U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0253U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0254U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0255U:text=L"Physical Huffman prefix bits interpreted using preceding pretree; numeric bit pattern is not a decoded symbol value.";break;
 case 0x608d0256U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0257U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0258U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0259U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d025aU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d025bU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d025cU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d025dU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d025eU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d025fU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0260U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0261U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0262U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0263U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0264U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0265U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0266U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0267U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0268U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0269U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d026aU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d026bU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d026cU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d026dU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d026eU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d026fU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0270U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0271U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0272U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0273U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0274U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0275U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0276U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0277U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0278U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0279U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d027aU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d027bU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d027cU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d027dU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d027eU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d027fU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0280U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0281U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0282U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0283U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0284U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0285U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0286U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0287U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0288U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d0289U:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d028aU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d028bU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d028cU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d028dU:text=L"Physical Huffman prefix window interpreted using preceding code-length tree. Display preserves LSB-window bit value, not the decoded symbol.";break;
 case 0x608d028eU:text=L"7-Zip Brotli MT framing: header payload size is8; compressed bytes follow the16-byte frame header. The output limit is stored in65536-byte units, not bytes. Each frame contains an independent raw Brotli stream.";break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXARWIRE_LIMIT 20000U
bool sxarwire_span(sx_context*c,uint64_t p,uint64_t n){return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
bool sxarwire_read(sx_context*c,uint64_t p,void*b,size_t n){return sxarwire_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxarwire_num(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static uint64_t sxarwire_width(const sx_layout*l){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;return (uint64_t)(f->rel_offset+f->size);}
bool sxarwire_put(sx_context*c,const sx_layout*l,uint64_t p){uint64_t n=sxarwire_width(l);return c->count<SXARWIRE_LIMIT&&n&&sxarwire_span(c,p,n)&&sx_add(c,l,(int64_t)p,(int64_t)n);}
/* Bit windows intentionally share byte boundaries. Their bit ranges do not
 * overlap; raw gaps use the union of the minimal enclosing byte windows. */
static int sxarwire_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxarwire_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxarwire_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<0||z<=0||p>c->size||z>c->size-p)return false;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+z>end)end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxarwire_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
bool sxarwire_take(sxarwire_bits*b,unsigned n,uint64_t*v){if(!n||n>64||xx_pd_is_stopped(b->c->pd)||b->bit>UINT64_MAX-n)return false;uint64_t out=0;for(unsigned i=0;i<n;i++){uint64_t at=b->bit/8;if(!b->have||at!=b->cached_at){if(!sxarwire_read(b->c,at,&b->cached,1))return false;b->cached_at=at;b->have=true;}unsigned bit=(b->cached>>(b->lsb?(b->bit&7):7-(b->bit&7)))&1U;if(b->lsb)out|=(uint64_t)bit<<i;else out=(out<<1)|bit;b->bit++;}*v=out;return true;}
bool sxarwire_field(sxarwire_bits*b,const sx_layout*const*set,unsigned n,uint64_t*v){uint64_t begin=b->bit;if(!sxarwire_take(b,n,v))return false;return sxarwire_put(b->c,set[begin&7],begin/8);}
bool sxarwire_lzs(sx_context*c,unsigned prefix){
 if(prefix&&!sxarwire_put(c,prefix==5?&sxarwire_npack_signature:&sxarwire_stac_signature,0))return false;
 sxarwire_bits b={c,(uint64_t)prefix*8,false,0,0,false};uint64_t produced=0;
 while(c->count<SXARWIRE_LIMIT){uint64_t match,short_form,dist,len,x;
  if(!sxarwire_field(&b,sxarwire_set_lzs_is_match,1,&match))return false;
  if(!match){if(!sxarwire_field(&b,sxarwire_set_lzs_literal,8,&x)||produced==UINT64_MAX)return false;produced++;continue;}
  if(!sxarwire_field(&b,sxarwire_set_lzs_short_distance,1,&short_form)||!sxarwire_field(&b,short_form?sxarwire_set_lzs_distance7:sxarwire_set_lzs_distance11,short_form?7:11,&dist))return false;
  if(!dist)return short_form!=0;if(dist>produced)return false;
  if(!sxarwire_field(&b,sxarwire_set_lzs_length_prefix,2,&x))return false;len=x+2;
  if(x==3){if(!sxarwire_field(&b,sxarwire_set_lzs_length_secondary,2,&x))return false;len=x+5;if(x==3){len=8;do{if(!sxarwire_field(&b,sxarwire_set_lzs_length_extension,4,&x)||len>UINT64_MAX-x)return false;len+=x;}while(x==15);}}
  if(produced>UINT64_MAX-len)return false;produced+=len;
 }return true;
}
bool sxarwire_hbuild(sxarwire_huff*h,const uint8_t*l,unsigned n,unsigned max){unsigned offsets[17]={0};int left=1;xx_rt_memset(h,0,sizeof(*h));if(n>510||max>16)return false;for(unsigned i=0;i<n;i++){if(l[i]>max)return false;h->count[l[i]]++;if(l[i]>h->maximum)h->maximum=l[i];}if(!h->maximum)return false;
 for(unsigned i=1;i<=max;i++){left=2*left-h->count[i];if(left<0)return false;}for(unsigned i=2;i<=max;i++)offsets[i]=offsets[i-1]+h->count[i-1];for(unsigned i=0;i<n;i++)if(l[i])h->symbol[offsets[l[i]]++]=(uint16_t)i;return true;}
bool sxarwire_hread(sxarwire_bits*b,const sxarwire_huff*h,unsigned*out){if(h->single){*out=h->one;return true;}unsigned code=0,first=0,index=0;for(unsigned n=1;n<=h->maximum;n++){uint64_t bit;if(!sxarwire_take(b,1,&bit))return false;code=(code<<1)|(unsigned)bit;unsigned count=h->count[n];if(code>=first&&code-first<count){*out=h->symbol[index+code-first];return true;}index+=count;first=(first+count)<<1;}return false;}
bool sxarwire_table_code(sxarwire_bits*b,const sxarwire_huff*h,unsigned*out){uint64_t start=b->bit;if(!sxarwire_hread(b,h,out))return false;unsigned n=(unsigned)(b->bit-start);if(!n)return true;const sx_layout*const*set=NULL;
 if(b->lsb){switch(n){case 1:set=sxarwire_set_deflate_table_prefix1;break;case 2:set=sxarwire_set_deflate_table_prefix2;break;case 3:set=sxarwire_set_deflate_table_prefix3;break;case 4:set=sxarwire_set_deflate_table_prefix4;break;case 5:set=sxarwire_set_deflate_table_prefix5;break;case 6:set=sxarwire_set_deflate_table_prefix6;break;case 7:set=sxarwire_set_deflate_table_prefix7;break;default:return false;}}
 else{switch(n){case 1:set=sxarwire_set_sco_table_prefix1;break;case 2:set=sxarwire_set_sco_table_prefix2;break;case 3:set=sxarwire_set_sco_table_prefix3;break;case 4:set=sxarwire_set_sco_table_prefix4;break;case 5:set=sxarwire_set_sco_table_prefix5;break;case 6:set=sxarwire_set_sco_table_prefix6;break;case 7:set=sxarwire_set_sco_table_prefix7;break;case 8:set=sxarwire_set_sco_table_prefix8;break;case 9:set=sxarwire_set_sco_table_prefix9;break;case 10:set=sxarwire_set_sco_table_prefix10;break;case 11:set=sxarwire_set_sco_table_prefix11;break;case 12:set=sxarwire_set_sco_table_prefix12;break;case 13:set=sxarwire_set_sco_table_prefix13;break;case 14:set=sxarwire_set_sco_table_prefix14;break;case 15:set=sxarwire_set_sco_table_prefix15;break;case 16:set=sxarwire_set_sco_table_prefix16;break;default:return false;}}
 return sxarwire_put(b->c,set[start&7],start/8);}
static bool sx_archivewire_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_BROTLI:case XX_FILE_TYPE_NPACK:case XX_FILE_TYPE_IBMSPACK:case XX_FILE_TYPE_TERSE:case XX_FILE_TYPE_RAW_LZW15V:case XX_FILE_TYPE_SCO:case XX_FILE_TYPE_STAC:case XX_FILE_TYPE_RAWSTAC:case XX_FILE_TYPE_SFX_ARDI_DISKETTE_IMAGE:case XX_FILE_TYPE_RAW_DEFLATE_COMPRESSED_DATA:return true;default:return false;}}
static bool sx_archivewire_build(sx_context*c){if(!c||!c->f||c->size<0||(uint64_t)c->size>UINT64_MAX/8||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_BROTLI:ok=sx_brotli_build(c);break;case XX_FILE_TYPE_NPACK:ok=sx_npack_build(c);break;case XX_FILE_TYPE_STAC:ok=sx_stac_build(c);break;case XX_FILE_TYPE_RAWSTAC:ok=sx_rawstac_build(c);break;case XX_FILE_TYPE_IBMSPACK:ok=sx_ibmspack_build(c);break;case XX_FILE_TYPE_TERSE:ok=sx_terse_build(c);break;case XX_FILE_TYPE_RAW_LZW15V:ok=sx_lzw15v_build(c);break;case XX_FILE_TYPE_SCO:ok=sx_sco_build(c);break;case XX_FILE_TYPE_SFX_ARDI_DISKETTE_IMAGE:ok=sx_sfx_ardi_diskette_image_build(c);break;case XX_FILE_TYPE_RAW_DEFLATE_COMPRESSED_DATA:ok=sx_raw_deflate_compressed_data_build(c);break;default:return false;}(void)ok;return c->count&&sxarwire_finish(c);}
const sx_family sx_archivewire_family={sx_archivewire_supports,sx_archivewire_build,sx_archivewire_layouts,SX_COUNT(sx_archivewire_layouts),sx_archivewire_comment};
