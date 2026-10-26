/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Raw LZW15V members data structures, moved out of the archivewire schema family. */
#include "../../xx_format_schema_archivewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarwire_lzw15v_code9_bit0_fields[]={
 SX_FIELD("dictionary_code","msb_bits[0,9]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code9_bit0={UINT32_C(0x608d0046),"lzw15v_code9_bit0",sxarwire_lzw15v_code9_bit0_fields,SX_COUNT(sxarwire_lzw15v_code9_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code9_bit1_fields[]={
 SX_FIELD("dictionary_code","msb_bits[1,9]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code9_bit1={UINT32_C(0x608d0047),"lzw15v_code9_bit1",sxarwire_lzw15v_code9_bit1_fields,SX_COUNT(sxarwire_lzw15v_code9_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code9_bit2_fields[]={
 SX_FIELD("dictionary_code","msb_bits[2,9]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code9_bit2={UINT32_C(0x608d0048),"lzw15v_code9_bit2",sxarwire_lzw15v_code9_bit2_fields,SX_COUNT(sxarwire_lzw15v_code9_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code9_bit3_fields[]={
 SX_FIELD("dictionary_code","msb_bits[3,9]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code9_bit3={UINT32_C(0x608d0049),"lzw15v_code9_bit3",sxarwire_lzw15v_code9_bit3_fields,SX_COUNT(sxarwire_lzw15v_code9_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code9_bit4_fields[]={
 SX_FIELD("dictionary_code","msb_bits[4,9]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code9_bit4={UINT32_C(0x608d004a),"lzw15v_code9_bit4",sxarwire_lzw15v_code9_bit4_fields,SX_COUNT(sxarwire_lzw15v_code9_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code9_bit5_fields[]={
 SX_FIELD("dictionary_code","msb_bits[5,9]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code9_bit5={UINT32_C(0x608d004b),"lzw15v_code9_bit5",sxarwire_lzw15v_code9_bit5_fields,SX_COUNT(sxarwire_lzw15v_code9_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code9_bit6_fields[]={
 SX_FIELD("dictionary_code","msb_bits[6,9]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code9_bit6={UINT32_C(0x608d004c),"lzw15v_code9_bit6",sxarwire_lzw15v_code9_bit6_fields,SX_COUNT(sxarwire_lzw15v_code9_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code9_bit7_fields[]={
 SX_FIELD("dictionary_code","msb_bits[7,9]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code9_bit7={UINT32_C(0x608d004d),"lzw15v_code9_bit7",sxarwire_lzw15v_code9_bit7_fields,SX_COUNT(sxarwire_lzw15v_code9_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code10_bit0_fields[]={
 SX_FIELD("dictionary_code","msb_bits[0,10]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code10_bit0={UINT32_C(0x608d004e),"lzw15v_code10_bit0",sxarwire_lzw15v_code10_bit0_fields,SX_COUNT(sxarwire_lzw15v_code10_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code10_bit1_fields[]={
 SX_FIELD("dictionary_code","msb_bits[1,10]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code10_bit1={UINT32_C(0x608d004f),"lzw15v_code10_bit1",sxarwire_lzw15v_code10_bit1_fields,SX_COUNT(sxarwire_lzw15v_code10_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code10_bit2_fields[]={
 SX_FIELD("dictionary_code","msb_bits[2,10]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code10_bit2={UINT32_C(0x608d0050),"lzw15v_code10_bit2",sxarwire_lzw15v_code10_bit2_fields,SX_COUNT(sxarwire_lzw15v_code10_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code10_bit3_fields[]={
 SX_FIELD("dictionary_code","msb_bits[3,10]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code10_bit3={UINT32_C(0x608d0051),"lzw15v_code10_bit3",sxarwire_lzw15v_code10_bit3_fields,SX_COUNT(sxarwire_lzw15v_code10_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code10_bit4_fields[]={
 SX_FIELD("dictionary_code","msb_bits[4,10]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code10_bit4={UINT32_C(0x608d0052),"lzw15v_code10_bit4",sxarwire_lzw15v_code10_bit4_fields,SX_COUNT(sxarwire_lzw15v_code10_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code10_bit5_fields[]={
 SX_FIELD("dictionary_code","msb_bits[5,10]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code10_bit5={UINT32_C(0x608d0053),"lzw15v_code10_bit5",sxarwire_lzw15v_code10_bit5_fields,SX_COUNT(sxarwire_lzw15v_code10_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code10_bit6_fields[]={
 SX_FIELD("dictionary_code","msb_bits[6,10]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code10_bit6={UINT32_C(0x608d0054),"lzw15v_code10_bit6",sxarwire_lzw15v_code10_bit6_fields,SX_COUNT(sxarwire_lzw15v_code10_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code10_bit7_fields[]={
 SX_FIELD("dictionary_code","msb_bits[7,10]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code10_bit7={UINT32_C(0x608d0055),"lzw15v_code10_bit7",sxarwire_lzw15v_code10_bit7_fields,SX_COUNT(sxarwire_lzw15v_code10_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code11_bit0_fields[]={
 SX_FIELD("dictionary_code","msb_bits[0,11]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code11_bit0={UINT32_C(0x608d0056),"lzw15v_code11_bit0",sxarwire_lzw15v_code11_bit0_fields,SX_COUNT(sxarwire_lzw15v_code11_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code11_bit1_fields[]={
 SX_FIELD("dictionary_code","msb_bits[1,11]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code11_bit1={UINT32_C(0x608d0057),"lzw15v_code11_bit1",sxarwire_lzw15v_code11_bit1_fields,SX_COUNT(sxarwire_lzw15v_code11_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code11_bit2_fields[]={
 SX_FIELD("dictionary_code","msb_bits[2,11]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code11_bit2={UINT32_C(0x608d0058),"lzw15v_code11_bit2",sxarwire_lzw15v_code11_bit2_fields,SX_COUNT(sxarwire_lzw15v_code11_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code11_bit3_fields[]={
 SX_FIELD("dictionary_code","msb_bits[3,11]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code11_bit3={UINT32_C(0x608d0059),"lzw15v_code11_bit3",sxarwire_lzw15v_code11_bit3_fields,SX_COUNT(sxarwire_lzw15v_code11_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code11_bit4_fields[]={
 SX_FIELD("dictionary_code","msb_bits[4,11]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code11_bit4={UINT32_C(0x608d005a),"lzw15v_code11_bit4",sxarwire_lzw15v_code11_bit4_fields,SX_COUNT(sxarwire_lzw15v_code11_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code11_bit5_fields[]={
 SX_FIELD("dictionary_code","msb_bits[5,11]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code11_bit5={UINT32_C(0x608d005b),"lzw15v_code11_bit5",sxarwire_lzw15v_code11_bit5_fields,SX_COUNT(sxarwire_lzw15v_code11_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code11_bit6_fields[]={
 SX_FIELD("dictionary_code","msb_bits[6,11]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code11_bit6={UINT32_C(0x608d005c),"lzw15v_code11_bit6",sxarwire_lzw15v_code11_bit6_fields,SX_COUNT(sxarwire_lzw15v_code11_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code11_bit7_fields[]={
 SX_FIELD("dictionary_code","msb_bits[7,11]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code11_bit7={UINT32_C(0x608d005d),"lzw15v_code11_bit7",sxarwire_lzw15v_code11_bit7_fields,SX_COUNT(sxarwire_lzw15v_code11_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code12_bit0_fields[]={
 SX_FIELD("dictionary_code","msb_bits[0,12]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code12_bit0={UINT32_C(0x608d005e),"lzw15v_code12_bit0",sxarwire_lzw15v_code12_bit0_fields,SX_COUNT(sxarwire_lzw15v_code12_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code12_bit1_fields[]={
 SX_FIELD("dictionary_code","msb_bits[1,12]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code12_bit1={UINT32_C(0x608d005f),"lzw15v_code12_bit1",sxarwire_lzw15v_code12_bit1_fields,SX_COUNT(sxarwire_lzw15v_code12_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code12_bit2_fields[]={
 SX_FIELD("dictionary_code","msb_bits[2,12]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code12_bit2={UINT32_C(0x608d0060),"lzw15v_code12_bit2",sxarwire_lzw15v_code12_bit2_fields,SX_COUNT(sxarwire_lzw15v_code12_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code12_bit3_fields[]={
 SX_FIELD("dictionary_code","msb_bits[3,12]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code12_bit3={UINT32_C(0x608d0061),"lzw15v_code12_bit3",sxarwire_lzw15v_code12_bit3_fields,SX_COUNT(sxarwire_lzw15v_code12_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code12_bit4_fields[]={
 SX_FIELD("dictionary_code","msb_bits[4,12]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code12_bit4={UINT32_C(0x608d0062),"lzw15v_code12_bit4",sxarwire_lzw15v_code12_bit4_fields,SX_COUNT(sxarwire_lzw15v_code12_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code12_bit5_fields[]={
 SX_FIELD("dictionary_code","msb_bits[5,12]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code12_bit5={UINT32_C(0x608d0063),"lzw15v_code12_bit5",sxarwire_lzw15v_code12_bit5_fields,SX_COUNT(sxarwire_lzw15v_code12_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code12_bit6_fields[]={
 SX_FIELD("dictionary_code","msb_bits[6,12]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code12_bit6={UINT32_C(0x608d0064),"lzw15v_code12_bit6",sxarwire_lzw15v_code12_bit6_fields,SX_COUNT(sxarwire_lzw15v_code12_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code12_bit7_fields[]={
 SX_FIELD("dictionary_code","msb_bits[7,12]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code12_bit7={UINT32_C(0x608d0065),"lzw15v_code12_bit7",sxarwire_lzw15v_code12_bit7_fields,SX_COUNT(sxarwire_lzw15v_code12_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code13_bit0_fields[]={
 SX_FIELD("dictionary_code","msb_bits[0,13]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code13_bit0={UINT32_C(0x608d0066),"lzw15v_code13_bit0",sxarwire_lzw15v_code13_bit0_fields,SX_COUNT(sxarwire_lzw15v_code13_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code13_bit1_fields[]={
 SX_FIELD("dictionary_code","msb_bits[1,13]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code13_bit1={UINT32_C(0x608d0067),"lzw15v_code13_bit1",sxarwire_lzw15v_code13_bit1_fields,SX_COUNT(sxarwire_lzw15v_code13_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code13_bit2_fields[]={
 SX_FIELD("dictionary_code","msb_bits[2,13]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code13_bit2={UINT32_C(0x608d0068),"lzw15v_code13_bit2",sxarwire_lzw15v_code13_bit2_fields,SX_COUNT(sxarwire_lzw15v_code13_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code13_bit3_fields[]={
 SX_FIELD("dictionary_code","msb_bits[3,13]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code13_bit3={UINT32_C(0x608d0069),"lzw15v_code13_bit3",sxarwire_lzw15v_code13_bit3_fields,SX_COUNT(sxarwire_lzw15v_code13_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code13_bit4_fields[]={
 SX_FIELD("dictionary_code","msb_bits[4,13]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code13_bit4={UINT32_C(0x608d006a),"lzw15v_code13_bit4",sxarwire_lzw15v_code13_bit4_fields,SX_COUNT(sxarwire_lzw15v_code13_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code13_bit5_fields[]={
 SX_FIELD("dictionary_code","msb_bits[5,13]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code13_bit5={UINT32_C(0x608d006b),"lzw15v_code13_bit5",sxarwire_lzw15v_code13_bit5_fields,SX_COUNT(sxarwire_lzw15v_code13_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code13_bit6_fields[]={
 SX_FIELD("dictionary_code","msb_bits[6,13]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code13_bit6={UINT32_C(0x608d006c),"lzw15v_code13_bit6",sxarwire_lzw15v_code13_bit6_fields,SX_COUNT(sxarwire_lzw15v_code13_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code13_bit7_fields[]={
 SX_FIELD("dictionary_code","msb_bits[7,13]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code13_bit7={UINT32_C(0x608d006d),"lzw15v_code13_bit7",sxarwire_lzw15v_code13_bit7_fields,SX_COUNT(sxarwire_lzw15v_code13_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code14_bit0_fields[]={
 SX_FIELD("dictionary_code","msb_bits[0,14]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code14_bit0={UINT32_C(0x608d006e),"lzw15v_code14_bit0",sxarwire_lzw15v_code14_bit0_fields,SX_COUNT(sxarwire_lzw15v_code14_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code14_bit1_fields[]={
 SX_FIELD("dictionary_code","msb_bits[1,14]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code14_bit1={UINT32_C(0x608d006f),"lzw15v_code14_bit1",sxarwire_lzw15v_code14_bit1_fields,SX_COUNT(sxarwire_lzw15v_code14_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code14_bit2_fields[]={
 SX_FIELD("dictionary_code","msb_bits[2,14]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code14_bit2={UINT32_C(0x608d0070),"lzw15v_code14_bit2",sxarwire_lzw15v_code14_bit2_fields,SX_COUNT(sxarwire_lzw15v_code14_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code14_bit3_fields[]={
 SX_FIELD("dictionary_code","msb_bits[3,14]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code14_bit3={UINT32_C(0x608d0071),"lzw15v_code14_bit3",sxarwire_lzw15v_code14_bit3_fields,SX_COUNT(sxarwire_lzw15v_code14_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code14_bit4_fields[]={
 SX_FIELD("dictionary_code","msb_bits[4,14]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code14_bit4={UINT32_C(0x608d0072),"lzw15v_code14_bit4",sxarwire_lzw15v_code14_bit4_fields,SX_COUNT(sxarwire_lzw15v_code14_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code14_bit5_fields[]={
 SX_FIELD("dictionary_code","msb_bits[5,14]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code14_bit5={UINT32_C(0x608d0073),"lzw15v_code14_bit5",sxarwire_lzw15v_code14_bit5_fields,SX_COUNT(sxarwire_lzw15v_code14_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code14_bit6_fields[]={
 SX_FIELD("dictionary_code","msb_bits[6,14]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code14_bit6={UINT32_C(0x608d0074),"lzw15v_code14_bit6",sxarwire_lzw15v_code14_bit6_fields,SX_COUNT(sxarwire_lzw15v_code14_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code14_bit7_fields[]={
 SX_FIELD("dictionary_code","msb_bits[7,14]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code14_bit7={UINT32_C(0x608d0075),"lzw15v_code14_bit7",sxarwire_lzw15v_code14_bit7_fields,SX_COUNT(sxarwire_lzw15v_code14_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code15_bit0_fields[]={
 SX_FIELD("dictionary_code","msb_bits[0,15]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code15_bit0={UINT32_C(0x608d0076),"lzw15v_code15_bit0",sxarwire_lzw15v_code15_bit0_fields,SX_COUNT(sxarwire_lzw15v_code15_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code15_bit1_fields[]={
 SX_FIELD("dictionary_code","msb_bits[1,15]",0,2,SX_ID),
};
const sx_layout sxarwire_lzw15v_code15_bit1={UINT32_C(0x608d0077),"lzw15v_code15_bit1",sxarwire_lzw15v_code15_bit1_fields,SX_COUNT(sxarwire_lzw15v_code15_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code15_bit2_fields[]={
 SX_FIELD("dictionary_code","msb_bits[2,15]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code15_bit2={UINT32_C(0x608d0078),"lzw15v_code15_bit2",sxarwire_lzw15v_code15_bit2_fields,SX_COUNT(sxarwire_lzw15v_code15_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code15_bit3_fields[]={
 SX_FIELD("dictionary_code","msb_bits[3,15]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code15_bit3={UINT32_C(0x608d0079),"lzw15v_code15_bit3",sxarwire_lzw15v_code15_bit3_fields,SX_COUNT(sxarwire_lzw15v_code15_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code15_bit4_fields[]={
 SX_FIELD("dictionary_code","msb_bits[4,15]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code15_bit4={UINT32_C(0x608d007a),"lzw15v_code15_bit4",sxarwire_lzw15v_code15_bit4_fields,SX_COUNT(sxarwire_lzw15v_code15_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code15_bit5_fields[]={
 SX_FIELD("dictionary_code","msb_bits[5,15]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code15_bit5={UINT32_C(0x608d007b),"lzw15v_code15_bit5",sxarwire_lzw15v_code15_bit5_fields,SX_COUNT(sxarwire_lzw15v_code15_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code15_bit6_fields[]={
 SX_FIELD("dictionary_code","msb_bits[6,15]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code15_bit6={UINT32_C(0x608d007c),"lzw15v_code15_bit6",sxarwire_lzw15v_code15_bit6_fields,SX_COUNT(sxarwire_lzw15v_code15_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_lzw15v_code15_bit7_fields[]={
 SX_FIELD("dictionary_code","msb_bits[7,15]",0,3,SX_ID),
};
const sx_layout sxarwire_lzw15v_code15_bit7={UINT32_C(0x608d007d),"lzw15v_code15_bit7",sxarwire_lzw15v_code15_bit7_fields,SX_COUNT(sxarwire_lzw15v_code15_bit7_fields),SX_LE};
static const sx_layout *const sxarwire_set_lzw15v_code9[]={&sxarwire_lzw15v_code9_bit0,&sxarwire_lzw15v_code9_bit1,&sxarwire_lzw15v_code9_bit2,&sxarwire_lzw15v_code9_bit3,&sxarwire_lzw15v_code9_bit4,&sxarwire_lzw15v_code9_bit5,&sxarwire_lzw15v_code9_bit6,&sxarwire_lzw15v_code9_bit7};
static const sx_layout *const sxarwire_set_lzw15v_code10[]={&sxarwire_lzw15v_code10_bit0,&sxarwire_lzw15v_code10_bit1,&sxarwire_lzw15v_code10_bit2,&sxarwire_lzw15v_code10_bit3,&sxarwire_lzw15v_code10_bit4,&sxarwire_lzw15v_code10_bit5,&sxarwire_lzw15v_code10_bit6,&sxarwire_lzw15v_code10_bit7};
static const sx_layout *const sxarwire_set_lzw15v_code11[]={&sxarwire_lzw15v_code11_bit0,&sxarwire_lzw15v_code11_bit1,&sxarwire_lzw15v_code11_bit2,&sxarwire_lzw15v_code11_bit3,&sxarwire_lzw15v_code11_bit4,&sxarwire_lzw15v_code11_bit5,&sxarwire_lzw15v_code11_bit6,&sxarwire_lzw15v_code11_bit7};
static const sx_layout *const sxarwire_set_lzw15v_code12[]={&sxarwire_lzw15v_code12_bit0,&sxarwire_lzw15v_code12_bit1,&sxarwire_lzw15v_code12_bit2,&sxarwire_lzw15v_code12_bit3,&sxarwire_lzw15v_code12_bit4,&sxarwire_lzw15v_code12_bit5,&sxarwire_lzw15v_code12_bit6,&sxarwire_lzw15v_code12_bit7};
static const sx_layout *const sxarwire_set_lzw15v_code13[]={&sxarwire_lzw15v_code13_bit0,&sxarwire_lzw15v_code13_bit1,&sxarwire_lzw15v_code13_bit2,&sxarwire_lzw15v_code13_bit3,&sxarwire_lzw15v_code13_bit4,&sxarwire_lzw15v_code13_bit5,&sxarwire_lzw15v_code13_bit6,&sxarwire_lzw15v_code13_bit7};
static const sx_layout *const sxarwire_set_lzw15v_code14[]={&sxarwire_lzw15v_code14_bit0,&sxarwire_lzw15v_code14_bit1,&sxarwire_lzw15v_code14_bit2,&sxarwire_lzw15v_code14_bit3,&sxarwire_lzw15v_code14_bit4,&sxarwire_lzw15v_code14_bit5,&sxarwire_lzw15v_code14_bit6,&sxarwire_lzw15v_code14_bit7};
static const sx_layout *const sxarwire_set_lzw15v_code15[]={&sxarwire_lzw15v_code15_bit0,&sxarwire_lzw15v_code15_bit1,&sxarwire_lzw15v_code15_bit2,&sxarwire_lzw15v_code15_bit3,&sxarwire_lzw15v_code15_bit4,&sxarwire_lzw15v_code15_bit5,&sxarwire_lzw15v_code15_bit6,&sxarwire_lzw15v_code15_bit7};
#define SXARWIRE_LIMIT 20000U
static const sx_layout*const*sxarwire_lzw_set(unsigned n){switch(n){case 9:return sxarwire_set_lzw15v_code9;case 10:return sxarwire_set_lzw15v_code10;case 11:return sxarwire_set_lzw15v_code11;case 12:return sxarwire_set_lzw15v_code12;case 13:return sxarwire_set_lzw15v_code13;case 14:return sxarwire_set_lzw15v_code14;case 15:return sxarwire_set_lzw15v_code15;default:return NULL;}}
static bool sxarwire_lzw(sx_context*c){sxarwire_bits b={c,0,false,0,0,false};unsigned width=9;bool first=true;uint64_t code,next=259;
 while(c->count<SXARWIRE_LIMIT){if(!sxarwire_field(&b,sxarwire_lzw_set(width),width,&code))return false;if(code==256)return true;
  if(first){if(code>255)return false;first=false;next=259;continue;}if(code==257){if(width==15)return false;width++;continue;}if(code==258){width=9;first=true;continue;}
  if(code>next||next>(UINT64_C(1)<<width))return false;if(next<32768)next++;
 }return true;}
bool sx_lzw15v_build(sx_context*c)
{
 return sxarwire_lzw(c);
}
