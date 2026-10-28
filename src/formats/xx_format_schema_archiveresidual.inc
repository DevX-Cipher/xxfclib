/* SPDX-License-Identifier: MIT. Physical wire fields; see permanent archiveresidual scope. */
static const xx_data_struct_field_desc sxarfinal_pcsecure_physical_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("encrypted_header","uint8[56]",4,56,SX_NONE),
 SX_FIELD("wrapped_file_key","uint8[8]",60,8,SX_NONE),
};
static const sx_layout sxarfinal_pcsecure_physical_header={UINT32_C(0x60920001),"pcsecure_physical_header",sxarfinal_pcsecure_physical_header_fields,SX_COUNT(sxarfinal_pcsecure_physical_header_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_prefix_fields[]={
 SX_FIELD("signature","uint8[2]",0,2,SX_SIGNATURE),
 SX_FIELD("first_literal","uint8",2,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_prefix={UINT32_C(0x60920002),"unixcompact_prefix",sxarfinal_unixcompact_prefix_fields,SX_COUNT(sxarfinal_unixcompact_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code1_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,1]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code1_bit0={UINT32_C(0x60920003),"unixcompact_code1_bit0",sxarfinal_unixcompact_code1_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code1_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code1_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,1]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code1_bit1={UINT32_C(0x60920004),"unixcompact_code1_bit1",sxarfinal_unixcompact_code1_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code1_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code1_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,1]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code1_bit2={UINT32_C(0x60920005),"unixcompact_code1_bit2",sxarfinal_unixcompact_code1_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code1_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code1_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,1]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code1_bit3={UINT32_C(0x60920006),"unixcompact_code1_bit3",sxarfinal_unixcompact_code1_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code1_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code1_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,1]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code1_bit4={UINT32_C(0x60920007),"unixcompact_code1_bit4",sxarfinal_unixcompact_code1_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code1_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code1_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,1]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code1_bit5={UINT32_C(0x60920008),"unixcompact_code1_bit5",sxarfinal_unixcompact_code1_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code1_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code1_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,1]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code1_bit6={UINT32_C(0x60920009),"unixcompact_code1_bit6",sxarfinal_unixcompact_code1_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code1_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code1_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,1]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code1_bit7={UINT32_C(0x6092000a),"unixcompact_code1_bit7",sxarfinal_unixcompact_code1_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code1_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code2_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,2]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code2_bit0={UINT32_C(0x6092000b),"unixcompact_code2_bit0",sxarfinal_unixcompact_code2_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code2_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code2_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,2]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code2_bit1={UINT32_C(0x6092000c),"unixcompact_code2_bit1",sxarfinal_unixcompact_code2_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code2_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code2_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,2]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code2_bit2={UINT32_C(0x6092000d),"unixcompact_code2_bit2",sxarfinal_unixcompact_code2_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code2_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code2_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,2]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code2_bit3={UINT32_C(0x6092000e),"unixcompact_code2_bit3",sxarfinal_unixcompact_code2_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code2_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code2_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,2]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code2_bit4={UINT32_C(0x6092000f),"unixcompact_code2_bit4",sxarfinal_unixcompact_code2_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code2_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code2_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,2]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code2_bit5={UINT32_C(0x60920010),"unixcompact_code2_bit5",sxarfinal_unixcompact_code2_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code2_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code2_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,2]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code2_bit6={UINT32_C(0x60920011),"unixcompact_code2_bit6",sxarfinal_unixcompact_code2_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code2_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code2_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,2]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code2_bit7={UINT32_C(0x60920012),"unixcompact_code2_bit7",sxarfinal_unixcompact_code2_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code2_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code3_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,3]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code3_bit0={UINT32_C(0x60920013),"unixcompact_code3_bit0",sxarfinal_unixcompact_code3_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code3_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code3_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,3]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code3_bit1={UINT32_C(0x60920014),"unixcompact_code3_bit1",sxarfinal_unixcompact_code3_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code3_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code3_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,3]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code3_bit2={UINT32_C(0x60920015),"unixcompact_code3_bit2",sxarfinal_unixcompact_code3_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code3_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code3_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,3]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code3_bit3={UINT32_C(0x60920016),"unixcompact_code3_bit3",sxarfinal_unixcompact_code3_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code3_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code3_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,3]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code3_bit4={UINT32_C(0x60920017),"unixcompact_code3_bit4",sxarfinal_unixcompact_code3_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code3_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code3_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,3]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code3_bit5={UINT32_C(0x60920018),"unixcompact_code3_bit5",sxarfinal_unixcompact_code3_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code3_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code3_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,3]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code3_bit6={UINT32_C(0x60920019),"unixcompact_code3_bit6",sxarfinal_unixcompact_code3_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code3_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code3_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,3]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code3_bit7={UINT32_C(0x6092001a),"unixcompact_code3_bit7",sxarfinal_unixcompact_code3_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code3_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code4_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,4]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code4_bit0={UINT32_C(0x6092001b),"unixcompact_code4_bit0",sxarfinal_unixcompact_code4_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code4_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code4_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,4]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code4_bit1={UINT32_C(0x6092001c),"unixcompact_code4_bit1",sxarfinal_unixcompact_code4_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code4_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code4_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,4]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code4_bit2={UINT32_C(0x6092001d),"unixcompact_code4_bit2",sxarfinal_unixcompact_code4_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code4_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code4_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,4]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code4_bit3={UINT32_C(0x6092001e),"unixcompact_code4_bit3",sxarfinal_unixcompact_code4_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code4_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code4_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,4]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code4_bit4={UINT32_C(0x6092001f),"unixcompact_code4_bit4",sxarfinal_unixcompact_code4_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code4_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code4_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,4]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code4_bit5={UINT32_C(0x60920020),"unixcompact_code4_bit5",sxarfinal_unixcompact_code4_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code4_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code4_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,4]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code4_bit6={UINT32_C(0x60920021),"unixcompact_code4_bit6",sxarfinal_unixcompact_code4_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code4_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code4_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,4]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code4_bit7={UINT32_C(0x60920022),"unixcompact_code4_bit7",sxarfinal_unixcompact_code4_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code4_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code5_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,5]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code5_bit0={UINT32_C(0x60920023),"unixcompact_code5_bit0",sxarfinal_unixcompact_code5_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code5_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code5_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,5]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code5_bit1={UINT32_C(0x60920024),"unixcompact_code5_bit1",sxarfinal_unixcompact_code5_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code5_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code5_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,5]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code5_bit2={UINT32_C(0x60920025),"unixcompact_code5_bit2",sxarfinal_unixcompact_code5_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code5_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code5_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,5]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code5_bit3={UINT32_C(0x60920026),"unixcompact_code5_bit3",sxarfinal_unixcompact_code5_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code5_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code5_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,5]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code5_bit4={UINT32_C(0x60920027),"unixcompact_code5_bit4",sxarfinal_unixcompact_code5_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code5_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code5_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,5]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code5_bit5={UINT32_C(0x60920028),"unixcompact_code5_bit5",sxarfinal_unixcompact_code5_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code5_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code5_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,5]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code5_bit6={UINT32_C(0x60920029),"unixcompact_code5_bit6",sxarfinal_unixcompact_code5_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code5_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code5_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,5]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code5_bit7={UINT32_C(0x6092002a),"unixcompact_code5_bit7",sxarfinal_unixcompact_code5_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code5_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code6_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,6]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code6_bit0={UINT32_C(0x6092002b),"unixcompact_code6_bit0",sxarfinal_unixcompact_code6_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code6_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code6_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,6]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code6_bit1={UINT32_C(0x6092002c),"unixcompact_code6_bit1",sxarfinal_unixcompact_code6_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code6_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code6_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,6]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code6_bit2={UINT32_C(0x6092002d),"unixcompact_code6_bit2",sxarfinal_unixcompact_code6_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code6_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code6_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,6]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code6_bit3={UINT32_C(0x6092002e),"unixcompact_code6_bit3",sxarfinal_unixcompact_code6_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code6_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code6_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,6]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code6_bit4={UINT32_C(0x6092002f),"unixcompact_code6_bit4",sxarfinal_unixcompact_code6_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code6_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code6_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,6]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code6_bit5={UINT32_C(0x60920030),"unixcompact_code6_bit5",sxarfinal_unixcompact_code6_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code6_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code6_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,6]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code6_bit6={UINT32_C(0x60920031),"unixcompact_code6_bit6",sxarfinal_unixcompact_code6_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code6_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code6_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,6]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code6_bit7={UINT32_C(0x60920032),"unixcompact_code6_bit7",sxarfinal_unixcompact_code6_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code6_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code7_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,7]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code7_bit0={UINT32_C(0x60920033),"unixcompact_code7_bit0",sxarfinal_unixcompact_code7_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code7_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code7_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,7]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code7_bit1={UINT32_C(0x60920034),"unixcompact_code7_bit1",sxarfinal_unixcompact_code7_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code7_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code7_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,7]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code7_bit2={UINT32_C(0x60920035),"unixcompact_code7_bit2",sxarfinal_unixcompact_code7_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code7_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code7_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,7]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code7_bit3={UINT32_C(0x60920036),"unixcompact_code7_bit3",sxarfinal_unixcompact_code7_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code7_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code7_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,7]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code7_bit4={UINT32_C(0x60920037),"unixcompact_code7_bit4",sxarfinal_unixcompact_code7_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code7_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code7_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,7]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code7_bit5={UINT32_C(0x60920038),"unixcompact_code7_bit5",sxarfinal_unixcompact_code7_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code7_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code7_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,7]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code7_bit6={UINT32_C(0x60920039),"unixcompact_code7_bit6",sxarfinal_unixcompact_code7_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code7_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code7_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,7]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code7_bit7={UINT32_C(0x6092003a),"unixcompact_code7_bit7",sxarfinal_unixcompact_code7_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code7_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code8_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,8]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code8_bit0={UINT32_C(0x6092003b),"unixcompact_code8_bit0",sxarfinal_unixcompact_code8_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code8_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code8_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,8]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code8_bit1={UINT32_C(0x6092003c),"unixcompact_code8_bit1",sxarfinal_unixcompact_code8_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code8_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code8_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,8]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code8_bit2={UINT32_C(0x6092003d),"unixcompact_code8_bit2",sxarfinal_unixcompact_code8_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code8_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code8_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,8]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code8_bit3={UINT32_C(0x6092003e),"unixcompact_code8_bit3",sxarfinal_unixcompact_code8_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code8_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code8_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,8]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code8_bit4={UINT32_C(0x6092003f),"unixcompact_code8_bit4",sxarfinal_unixcompact_code8_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code8_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code8_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,8]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code8_bit5={UINT32_C(0x60920040),"unixcompact_code8_bit5",sxarfinal_unixcompact_code8_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code8_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code8_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,8]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code8_bit6={UINT32_C(0x60920041),"unixcompact_code8_bit6",sxarfinal_unixcompact_code8_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code8_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code8_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,8]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code8_bit7={UINT32_C(0x60920042),"unixcompact_code8_bit7",sxarfinal_unixcompact_code8_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code8_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code9_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,9]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code9_bit0={UINT32_C(0x60920043),"unixcompact_code9_bit0",sxarfinal_unixcompact_code9_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code9_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code9_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,9]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code9_bit1={UINT32_C(0x60920044),"unixcompact_code9_bit1",sxarfinal_unixcompact_code9_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code9_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code9_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,9]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code9_bit2={UINT32_C(0x60920045),"unixcompact_code9_bit2",sxarfinal_unixcompact_code9_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code9_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code9_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,9]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code9_bit3={UINT32_C(0x60920046),"unixcompact_code9_bit3",sxarfinal_unixcompact_code9_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code9_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code9_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,9]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code9_bit4={UINT32_C(0x60920047),"unixcompact_code9_bit4",sxarfinal_unixcompact_code9_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code9_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code9_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,9]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code9_bit5={UINT32_C(0x60920048),"unixcompact_code9_bit5",sxarfinal_unixcompact_code9_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code9_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code9_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,9]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code9_bit6={UINT32_C(0x60920049),"unixcompact_code9_bit6",sxarfinal_unixcompact_code9_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code9_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code9_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,9]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code9_bit7={UINT32_C(0x6092004a),"unixcompact_code9_bit7",sxarfinal_unixcompact_code9_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code9_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code10_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,10]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code10_bit0={UINT32_C(0x6092004b),"unixcompact_code10_bit0",sxarfinal_unixcompact_code10_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code10_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code10_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,10]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code10_bit1={UINT32_C(0x6092004c),"unixcompact_code10_bit1",sxarfinal_unixcompact_code10_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code10_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code10_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,10]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code10_bit2={UINT32_C(0x6092004d),"unixcompact_code10_bit2",sxarfinal_unixcompact_code10_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code10_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code10_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,10]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code10_bit3={UINT32_C(0x6092004e),"unixcompact_code10_bit3",sxarfinal_unixcompact_code10_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code10_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code10_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,10]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code10_bit4={UINT32_C(0x6092004f),"unixcompact_code10_bit4",sxarfinal_unixcompact_code10_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code10_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code10_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,10]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code10_bit5={UINT32_C(0x60920050),"unixcompact_code10_bit5",sxarfinal_unixcompact_code10_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code10_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code10_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,10]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code10_bit6={UINT32_C(0x60920051),"unixcompact_code10_bit6",sxarfinal_unixcompact_code10_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code10_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code10_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,10]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code10_bit7={UINT32_C(0x60920052),"unixcompact_code10_bit7",sxarfinal_unixcompact_code10_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code10_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code11_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,11]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code11_bit0={UINT32_C(0x60920053),"unixcompact_code11_bit0",sxarfinal_unixcompact_code11_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code11_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code11_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,11]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code11_bit1={UINT32_C(0x60920054),"unixcompact_code11_bit1",sxarfinal_unixcompact_code11_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code11_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code11_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,11]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code11_bit2={UINT32_C(0x60920055),"unixcompact_code11_bit2",sxarfinal_unixcompact_code11_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code11_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code11_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,11]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code11_bit3={UINT32_C(0x60920056),"unixcompact_code11_bit3",sxarfinal_unixcompact_code11_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code11_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code11_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,11]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code11_bit4={UINT32_C(0x60920057),"unixcompact_code11_bit4",sxarfinal_unixcompact_code11_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code11_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code11_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,11]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code11_bit5={UINT32_C(0x60920058),"unixcompact_code11_bit5",sxarfinal_unixcompact_code11_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code11_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code11_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,11]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code11_bit6={UINT32_C(0x60920059),"unixcompact_code11_bit6",sxarfinal_unixcompact_code11_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code11_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code11_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,11]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code11_bit7={UINT32_C(0x6092005a),"unixcompact_code11_bit7",sxarfinal_unixcompact_code11_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code11_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code12_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,12]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code12_bit0={UINT32_C(0x6092005b),"unixcompact_code12_bit0",sxarfinal_unixcompact_code12_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code12_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code12_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,12]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code12_bit1={UINT32_C(0x6092005c),"unixcompact_code12_bit1",sxarfinal_unixcompact_code12_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code12_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code12_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,12]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code12_bit2={UINT32_C(0x6092005d),"unixcompact_code12_bit2",sxarfinal_unixcompact_code12_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code12_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code12_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,12]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code12_bit3={UINT32_C(0x6092005e),"unixcompact_code12_bit3",sxarfinal_unixcompact_code12_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code12_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code12_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,12]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code12_bit4={UINT32_C(0x6092005f),"unixcompact_code12_bit4",sxarfinal_unixcompact_code12_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code12_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code12_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,12]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code12_bit5={UINT32_C(0x60920060),"unixcompact_code12_bit5",sxarfinal_unixcompact_code12_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code12_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code12_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,12]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code12_bit6={UINT32_C(0x60920061),"unixcompact_code12_bit6",sxarfinal_unixcompact_code12_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code12_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code12_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,12]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code12_bit7={UINT32_C(0x60920062),"unixcompact_code12_bit7",sxarfinal_unixcompact_code12_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code12_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code13_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,13]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code13_bit0={UINT32_C(0x60920063),"unixcompact_code13_bit0",sxarfinal_unixcompact_code13_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code13_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code13_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,13]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code13_bit1={UINT32_C(0x60920064),"unixcompact_code13_bit1",sxarfinal_unixcompact_code13_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code13_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code13_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,13]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code13_bit2={UINT32_C(0x60920065),"unixcompact_code13_bit2",sxarfinal_unixcompact_code13_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code13_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code13_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,13]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code13_bit3={UINT32_C(0x60920066),"unixcompact_code13_bit3",sxarfinal_unixcompact_code13_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code13_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code13_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,13]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code13_bit4={UINT32_C(0x60920067),"unixcompact_code13_bit4",sxarfinal_unixcompact_code13_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code13_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code13_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,13]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code13_bit5={UINT32_C(0x60920068),"unixcompact_code13_bit5",sxarfinal_unixcompact_code13_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code13_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code13_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,13]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code13_bit6={UINT32_C(0x60920069),"unixcompact_code13_bit6",sxarfinal_unixcompact_code13_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code13_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code13_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,13]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code13_bit7={UINT32_C(0x6092006a),"unixcompact_code13_bit7",sxarfinal_unixcompact_code13_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code13_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code14_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,14]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code14_bit0={UINT32_C(0x6092006b),"unixcompact_code14_bit0",sxarfinal_unixcompact_code14_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code14_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code14_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,14]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code14_bit1={UINT32_C(0x6092006c),"unixcompact_code14_bit1",sxarfinal_unixcompact_code14_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code14_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code14_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,14]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code14_bit2={UINT32_C(0x6092006d),"unixcompact_code14_bit2",sxarfinal_unixcompact_code14_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code14_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code14_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,14]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code14_bit3={UINT32_C(0x6092006e),"unixcompact_code14_bit3",sxarfinal_unixcompact_code14_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code14_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code14_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,14]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code14_bit4={UINT32_C(0x6092006f),"unixcompact_code14_bit4",sxarfinal_unixcompact_code14_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code14_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code14_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,14]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code14_bit5={UINT32_C(0x60920070),"unixcompact_code14_bit5",sxarfinal_unixcompact_code14_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code14_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code14_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,14]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code14_bit6={UINT32_C(0x60920071),"unixcompact_code14_bit6",sxarfinal_unixcompact_code14_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code14_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code14_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,14]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code14_bit7={UINT32_C(0x60920072),"unixcompact_code14_bit7",sxarfinal_unixcompact_code14_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code14_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code15_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,15]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code15_bit0={UINT32_C(0x60920073),"unixcompact_code15_bit0",sxarfinal_unixcompact_code15_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code15_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code15_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,15]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code15_bit1={UINT32_C(0x60920074),"unixcompact_code15_bit1",sxarfinal_unixcompact_code15_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code15_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code15_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,15]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code15_bit2={UINT32_C(0x60920075),"unixcompact_code15_bit2",sxarfinal_unixcompact_code15_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code15_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code15_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,15]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code15_bit3={UINT32_C(0x60920076),"unixcompact_code15_bit3",sxarfinal_unixcompact_code15_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code15_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code15_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,15]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code15_bit4={UINT32_C(0x60920077),"unixcompact_code15_bit4",sxarfinal_unixcompact_code15_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code15_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code15_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,15]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code15_bit5={UINT32_C(0x60920078),"unixcompact_code15_bit5",sxarfinal_unixcompact_code15_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code15_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code15_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,15]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code15_bit6={UINT32_C(0x60920079),"unixcompact_code15_bit6",sxarfinal_unixcompact_code15_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code15_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code15_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,15]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code15_bit7={UINT32_C(0x6092007a),"unixcompact_code15_bit7",sxarfinal_unixcompact_code15_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code15_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code16_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,16]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code16_bit0={UINT32_C(0x6092007b),"unixcompact_code16_bit0",sxarfinal_unixcompact_code16_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code16_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code16_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,16]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code16_bit1={UINT32_C(0x6092007c),"unixcompact_code16_bit1",sxarfinal_unixcompact_code16_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code16_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code16_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,16]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code16_bit2={UINT32_C(0x6092007d),"unixcompact_code16_bit2",sxarfinal_unixcompact_code16_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code16_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code16_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,16]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code16_bit3={UINT32_C(0x6092007e),"unixcompact_code16_bit3",sxarfinal_unixcompact_code16_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code16_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code16_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,16]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code16_bit4={UINT32_C(0x6092007f),"unixcompact_code16_bit4",sxarfinal_unixcompact_code16_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code16_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code16_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,16]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code16_bit5={UINT32_C(0x60920080),"unixcompact_code16_bit5",sxarfinal_unixcompact_code16_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code16_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code16_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,16]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code16_bit6={UINT32_C(0x60920081),"unixcompact_code16_bit6",sxarfinal_unixcompact_code16_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code16_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code16_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,16]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code16_bit7={UINT32_C(0x60920082),"unixcompact_code16_bit7",sxarfinal_unixcompact_code16_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code16_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code17_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,17]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code17_bit0={UINT32_C(0x60920083),"unixcompact_code17_bit0",sxarfinal_unixcompact_code17_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code17_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code17_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,17]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code17_bit1={UINT32_C(0x60920084),"unixcompact_code17_bit1",sxarfinal_unixcompact_code17_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code17_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code17_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,17]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code17_bit2={UINT32_C(0x60920085),"unixcompact_code17_bit2",sxarfinal_unixcompact_code17_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code17_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code17_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,17]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code17_bit3={UINT32_C(0x60920086),"unixcompact_code17_bit3",sxarfinal_unixcompact_code17_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code17_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code17_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,17]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code17_bit4={UINT32_C(0x60920087),"unixcompact_code17_bit4",sxarfinal_unixcompact_code17_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code17_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code17_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,17]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code17_bit5={UINT32_C(0x60920088),"unixcompact_code17_bit5",sxarfinal_unixcompact_code17_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code17_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code17_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,17]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code17_bit6={UINT32_C(0x60920089),"unixcompact_code17_bit6",sxarfinal_unixcompact_code17_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code17_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code17_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,17]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code17_bit7={UINT32_C(0x6092008a),"unixcompact_code17_bit7",sxarfinal_unixcompact_code17_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code17_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code18_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,18]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code18_bit0={UINT32_C(0x6092008b),"unixcompact_code18_bit0",sxarfinal_unixcompact_code18_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code18_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code18_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,18]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code18_bit1={UINT32_C(0x6092008c),"unixcompact_code18_bit1",sxarfinal_unixcompact_code18_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code18_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code18_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,18]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code18_bit2={UINT32_C(0x6092008d),"unixcompact_code18_bit2",sxarfinal_unixcompact_code18_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code18_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code18_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,18]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code18_bit3={UINT32_C(0x6092008e),"unixcompact_code18_bit3",sxarfinal_unixcompact_code18_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code18_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code18_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,18]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code18_bit4={UINT32_C(0x6092008f),"unixcompact_code18_bit4",sxarfinal_unixcompact_code18_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code18_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code18_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,18]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code18_bit5={UINT32_C(0x60920090),"unixcompact_code18_bit5",sxarfinal_unixcompact_code18_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code18_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code18_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,18]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code18_bit6={UINT32_C(0x60920091),"unixcompact_code18_bit6",sxarfinal_unixcompact_code18_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code18_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code18_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,18]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code18_bit7={UINT32_C(0x60920092),"unixcompact_code18_bit7",sxarfinal_unixcompact_code18_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code18_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code19_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,19]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code19_bit0={UINT32_C(0x60920093),"unixcompact_code19_bit0",sxarfinal_unixcompact_code19_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code19_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code19_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,19]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code19_bit1={UINT32_C(0x60920094),"unixcompact_code19_bit1",sxarfinal_unixcompact_code19_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code19_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code19_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,19]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code19_bit2={UINT32_C(0x60920095),"unixcompact_code19_bit2",sxarfinal_unixcompact_code19_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code19_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code19_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,19]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code19_bit3={UINT32_C(0x60920096),"unixcompact_code19_bit3",sxarfinal_unixcompact_code19_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code19_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code19_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,19]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code19_bit4={UINT32_C(0x60920097),"unixcompact_code19_bit4",sxarfinal_unixcompact_code19_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code19_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code19_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,19]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code19_bit5={UINT32_C(0x60920098),"unixcompact_code19_bit5",sxarfinal_unixcompact_code19_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code19_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code19_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,19]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code19_bit6={UINT32_C(0x60920099),"unixcompact_code19_bit6",sxarfinal_unixcompact_code19_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code19_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code19_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,19]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code19_bit7={UINT32_C(0x6092009a),"unixcompact_code19_bit7",sxarfinal_unixcompact_code19_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code19_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code20_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,20]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code20_bit0={UINT32_C(0x6092009b),"unixcompact_code20_bit0",sxarfinal_unixcompact_code20_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code20_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code20_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,20]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code20_bit1={UINT32_C(0x6092009c),"unixcompact_code20_bit1",sxarfinal_unixcompact_code20_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code20_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code20_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,20]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code20_bit2={UINT32_C(0x6092009d),"unixcompact_code20_bit2",sxarfinal_unixcompact_code20_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code20_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code20_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,20]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code20_bit3={UINT32_C(0x6092009e),"unixcompact_code20_bit3",sxarfinal_unixcompact_code20_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code20_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code20_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,20]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code20_bit4={UINT32_C(0x6092009f),"unixcompact_code20_bit4",sxarfinal_unixcompact_code20_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code20_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code20_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,20]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code20_bit5={UINT32_C(0x609200a0),"unixcompact_code20_bit5",sxarfinal_unixcompact_code20_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code20_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code20_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,20]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code20_bit6={UINT32_C(0x609200a1),"unixcompact_code20_bit6",sxarfinal_unixcompact_code20_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code20_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code20_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,20]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code20_bit7={UINT32_C(0x609200a2),"unixcompact_code20_bit7",sxarfinal_unixcompact_code20_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code20_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code21_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,21]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code21_bit0={UINT32_C(0x609200a3),"unixcompact_code21_bit0",sxarfinal_unixcompact_code21_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code21_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code21_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,21]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code21_bit1={UINT32_C(0x609200a4),"unixcompact_code21_bit1",sxarfinal_unixcompact_code21_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code21_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code21_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,21]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code21_bit2={UINT32_C(0x609200a5),"unixcompact_code21_bit2",sxarfinal_unixcompact_code21_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code21_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code21_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,21]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code21_bit3={UINT32_C(0x609200a6),"unixcompact_code21_bit3",sxarfinal_unixcompact_code21_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code21_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code21_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,21]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code21_bit4={UINT32_C(0x609200a7),"unixcompact_code21_bit4",sxarfinal_unixcompact_code21_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code21_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code21_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,21]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code21_bit5={UINT32_C(0x609200a8),"unixcompact_code21_bit5",sxarfinal_unixcompact_code21_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code21_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code21_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,21]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code21_bit6={UINT32_C(0x609200a9),"unixcompact_code21_bit6",sxarfinal_unixcompact_code21_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code21_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code21_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,21]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code21_bit7={UINT32_C(0x609200aa),"unixcompact_code21_bit7",sxarfinal_unixcompact_code21_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code21_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code22_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,22]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code22_bit0={UINT32_C(0x609200ab),"unixcompact_code22_bit0",sxarfinal_unixcompact_code22_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code22_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code22_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,22]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code22_bit1={UINT32_C(0x609200ac),"unixcompact_code22_bit1",sxarfinal_unixcompact_code22_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code22_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code22_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,22]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code22_bit2={UINT32_C(0x609200ad),"unixcompact_code22_bit2",sxarfinal_unixcompact_code22_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code22_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code22_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,22]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code22_bit3={UINT32_C(0x609200ae),"unixcompact_code22_bit3",sxarfinal_unixcompact_code22_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code22_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code22_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,22]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code22_bit4={UINT32_C(0x609200af),"unixcompact_code22_bit4",sxarfinal_unixcompact_code22_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code22_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code22_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,22]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code22_bit5={UINT32_C(0x609200b0),"unixcompact_code22_bit5",sxarfinal_unixcompact_code22_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code22_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code22_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,22]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code22_bit6={UINT32_C(0x609200b1),"unixcompact_code22_bit6",sxarfinal_unixcompact_code22_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code22_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code22_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,22]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code22_bit7={UINT32_C(0x609200b2),"unixcompact_code22_bit7",sxarfinal_unixcompact_code22_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code22_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code23_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,23]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code23_bit0={UINT32_C(0x609200b3),"unixcompact_code23_bit0",sxarfinal_unixcompact_code23_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code23_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code23_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,23]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code23_bit1={UINT32_C(0x609200b4),"unixcompact_code23_bit1",sxarfinal_unixcompact_code23_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code23_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code23_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,23]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code23_bit2={UINT32_C(0x609200b5),"unixcompact_code23_bit2",sxarfinal_unixcompact_code23_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code23_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code23_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,23]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code23_bit3={UINT32_C(0x609200b6),"unixcompact_code23_bit3",sxarfinal_unixcompact_code23_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code23_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code23_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,23]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code23_bit4={UINT32_C(0x609200b7),"unixcompact_code23_bit4",sxarfinal_unixcompact_code23_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code23_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code23_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,23]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code23_bit5={UINT32_C(0x609200b8),"unixcompact_code23_bit5",sxarfinal_unixcompact_code23_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code23_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code23_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,23]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code23_bit6={UINT32_C(0x609200b9),"unixcompact_code23_bit6",sxarfinal_unixcompact_code23_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code23_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code23_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,23]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code23_bit7={UINT32_C(0x609200ba),"unixcompact_code23_bit7",sxarfinal_unixcompact_code23_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code23_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code24_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,24]",0,3,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code24_bit0={UINT32_C(0x609200bb),"unixcompact_code24_bit0",sxarfinal_unixcompact_code24_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code24_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code24_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,24]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code24_bit1={UINT32_C(0x609200bc),"unixcompact_code24_bit1",sxarfinal_unixcompact_code24_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code24_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code24_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,24]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code24_bit2={UINT32_C(0x609200bd),"unixcompact_code24_bit2",sxarfinal_unixcompact_code24_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code24_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code24_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,24]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code24_bit3={UINT32_C(0x609200be),"unixcompact_code24_bit3",sxarfinal_unixcompact_code24_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code24_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code24_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,24]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code24_bit4={UINT32_C(0x609200bf),"unixcompact_code24_bit4",sxarfinal_unixcompact_code24_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code24_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code24_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,24]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code24_bit5={UINT32_C(0x609200c0),"unixcompact_code24_bit5",sxarfinal_unixcompact_code24_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code24_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code24_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,24]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code24_bit6={UINT32_C(0x609200c1),"unixcompact_code24_bit6",sxarfinal_unixcompact_code24_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code24_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code24_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,24]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code24_bit7={UINT32_C(0x609200c2),"unixcompact_code24_bit7",sxarfinal_unixcompact_code24_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code24_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code25_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,25]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code25_bit0={UINT32_C(0x609200c3),"unixcompact_code25_bit0",sxarfinal_unixcompact_code25_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code25_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code25_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,25]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code25_bit1={UINT32_C(0x609200c4),"unixcompact_code25_bit1",sxarfinal_unixcompact_code25_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code25_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code25_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,25]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code25_bit2={UINT32_C(0x609200c5),"unixcompact_code25_bit2",sxarfinal_unixcompact_code25_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code25_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code25_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,25]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code25_bit3={UINT32_C(0x609200c6),"unixcompact_code25_bit3",sxarfinal_unixcompact_code25_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code25_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code25_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,25]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code25_bit4={UINT32_C(0x609200c7),"unixcompact_code25_bit4",sxarfinal_unixcompact_code25_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code25_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code25_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,25]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code25_bit5={UINT32_C(0x609200c8),"unixcompact_code25_bit5",sxarfinal_unixcompact_code25_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code25_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code25_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,25]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code25_bit6={UINT32_C(0x609200c9),"unixcompact_code25_bit6",sxarfinal_unixcompact_code25_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code25_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code25_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,25]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code25_bit7={UINT32_C(0x609200ca),"unixcompact_code25_bit7",sxarfinal_unixcompact_code25_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code25_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code26_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,26]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code26_bit0={UINT32_C(0x609200cb),"unixcompact_code26_bit0",sxarfinal_unixcompact_code26_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code26_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code26_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,26]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code26_bit1={UINT32_C(0x609200cc),"unixcompact_code26_bit1",sxarfinal_unixcompact_code26_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code26_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code26_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,26]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code26_bit2={UINT32_C(0x609200cd),"unixcompact_code26_bit2",sxarfinal_unixcompact_code26_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code26_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code26_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,26]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code26_bit3={UINT32_C(0x609200ce),"unixcompact_code26_bit3",sxarfinal_unixcompact_code26_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code26_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code26_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,26]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code26_bit4={UINT32_C(0x609200cf),"unixcompact_code26_bit4",sxarfinal_unixcompact_code26_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code26_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code26_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,26]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code26_bit5={UINT32_C(0x609200d0),"unixcompact_code26_bit5",sxarfinal_unixcompact_code26_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code26_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code26_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,26]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code26_bit6={UINT32_C(0x609200d1),"unixcompact_code26_bit6",sxarfinal_unixcompact_code26_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code26_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code26_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,26]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code26_bit7={UINT32_C(0x609200d2),"unixcompact_code26_bit7",sxarfinal_unixcompact_code26_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code26_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code27_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,27]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code27_bit0={UINT32_C(0x609200d3),"unixcompact_code27_bit0",sxarfinal_unixcompact_code27_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code27_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code27_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,27]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code27_bit1={UINT32_C(0x609200d4),"unixcompact_code27_bit1",sxarfinal_unixcompact_code27_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code27_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code27_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,27]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code27_bit2={UINT32_C(0x609200d5),"unixcompact_code27_bit2",sxarfinal_unixcompact_code27_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code27_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code27_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,27]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code27_bit3={UINT32_C(0x609200d6),"unixcompact_code27_bit3",sxarfinal_unixcompact_code27_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code27_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code27_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,27]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code27_bit4={UINT32_C(0x609200d7),"unixcompact_code27_bit4",sxarfinal_unixcompact_code27_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code27_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code27_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,27]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code27_bit5={UINT32_C(0x609200d8),"unixcompact_code27_bit5",sxarfinal_unixcompact_code27_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code27_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code27_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,27]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code27_bit6={UINT32_C(0x609200d9),"unixcompact_code27_bit6",sxarfinal_unixcompact_code27_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code27_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code27_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,27]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code27_bit7={UINT32_C(0x609200da),"unixcompact_code27_bit7",sxarfinal_unixcompact_code27_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code27_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code28_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,28]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code28_bit0={UINT32_C(0x609200db),"unixcompact_code28_bit0",sxarfinal_unixcompact_code28_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code28_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code28_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,28]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code28_bit1={UINT32_C(0x609200dc),"unixcompact_code28_bit1",sxarfinal_unixcompact_code28_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code28_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code28_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,28]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code28_bit2={UINT32_C(0x609200dd),"unixcompact_code28_bit2",sxarfinal_unixcompact_code28_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code28_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code28_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,28]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code28_bit3={UINT32_C(0x609200de),"unixcompact_code28_bit3",sxarfinal_unixcompact_code28_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code28_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code28_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,28]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code28_bit4={UINT32_C(0x609200df),"unixcompact_code28_bit4",sxarfinal_unixcompact_code28_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code28_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code28_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,28]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code28_bit5={UINT32_C(0x609200e0),"unixcompact_code28_bit5",sxarfinal_unixcompact_code28_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code28_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code28_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,28]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code28_bit6={UINT32_C(0x609200e1),"unixcompact_code28_bit6",sxarfinal_unixcompact_code28_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code28_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code28_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,28]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code28_bit7={UINT32_C(0x609200e2),"unixcompact_code28_bit7",sxarfinal_unixcompact_code28_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code28_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code29_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,29]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code29_bit0={UINT32_C(0x609200e3),"unixcompact_code29_bit0",sxarfinal_unixcompact_code29_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code29_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code29_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,29]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code29_bit1={UINT32_C(0x609200e4),"unixcompact_code29_bit1",sxarfinal_unixcompact_code29_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code29_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code29_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,29]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code29_bit2={UINT32_C(0x609200e5),"unixcompact_code29_bit2",sxarfinal_unixcompact_code29_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code29_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code29_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,29]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code29_bit3={UINT32_C(0x609200e6),"unixcompact_code29_bit3",sxarfinal_unixcompact_code29_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code29_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code29_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,29]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code29_bit4={UINT32_C(0x609200e7),"unixcompact_code29_bit4",sxarfinal_unixcompact_code29_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code29_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code29_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,29]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code29_bit5={UINT32_C(0x609200e8),"unixcompact_code29_bit5",sxarfinal_unixcompact_code29_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code29_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code29_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,29]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code29_bit6={UINT32_C(0x609200e9),"unixcompact_code29_bit6",sxarfinal_unixcompact_code29_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code29_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code29_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,29]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code29_bit7={UINT32_C(0x609200ea),"unixcompact_code29_bit7",sxarfinal_unixcompact_code29_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code29_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code30_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,30]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code30_bit0={UINT32_C(0x609200eb),"unixcompact_code30_bit0",sxarfinal_unixcompact_code30_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code30_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code30_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,30]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code30_bit1={UINT32_C(0x609200ec),"unixcompact_code30_bit1",sxarfinal_unixcompact_code30_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code30_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code30_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,30]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code30_bit2={UINT32_C(0x609200ed),"unixcompact_code30_bit2",sxarfinal_unixcompact_code30_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code30_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code30_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,30]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code30_bit3={UINT32_C(0x609200ee),"unixcompact_code30_bit3",sxarfinal_unixcompact_code30_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code30_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code30_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,30]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code30_bit4={UINT32_C(0x609200ef),"unixcompact_code30_bit4",sxarfinal_unixcompact_code30_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code30_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code30_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,30]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code30_bit5={UINT32_C(0x609200f0),"unixcompact_code30_bit5",sxarfinal_unixcompact_code30_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code30_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code30_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,30]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code30_bit6={UINT32_C(0x609200f1),"unixcompact_code30_bit6",sxarfinal_unixcompact_code30_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code30_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code30_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,30]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code30_bit7={UINT32_C(0x609200f2),"unixcompact_code30_bit7",sxarfinal_unixcompact_code30_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code30_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code31_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,31]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code31_bit0={UINT32_C(0x609200f3),"unixcompact_code31_bit0",sxarfinal_unixcompact_code31_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code31_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code31_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,31]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code31_bit1={UINT32_C(0x609200f4),"unixcompact_code31_bit1",sxarfinal_unixcompact_code31_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code31_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code31_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,31]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code31_bit2={UINT32_C(0x609200f5),"unixcompact_code31_bit2",sxarfinal_unixcompact_code31_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code31_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code31_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,31]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code31_bit3={UINT32_C(0x609200f6),"unixcompact_code31_bit3",sxarfinal_unixcompact_code31_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code31_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code31_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,31]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code31_bit4={UINT32_C(0x609200f7),"unixcompact_code31_bit4",sxarfinal_unixcompact_code31_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code31_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code31_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,31]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code31_bit5={UINT32_C(0x609200f8),"unixcompact_code31_bit5",sxarfinal_unixcompact_code31_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code31_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code31_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,31]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code31_bit6={UINT32_C(0x609200f9),"unixcompact_code31_bit6",sxarfinal_unixcompact_code31_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code31_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code31_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,31]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code31_bit7={UINT32_C(0x609200fa),"unixcompact_code31_bit7",sxarfinal_unixcompact_code31_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code31_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code32_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,32]",0,4,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code32_bit0={UINT32_C(0x609200fb),"unixcompact_code32_bit0",sxarfinal_unixcompact_code32_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code32_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code32_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,32]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code32_bit1={UINT32_C(0x609200fc),"unixcompact_code32_bit1",sxarfinal_unixcompact_code32_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code32_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code32_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,32]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code32_bit2={UINT32_C(0x609200fd),"unixcompact_code32_bit2",sxarfinal_unixcompact_code32_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code32_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code32_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,32]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code32_bit3={UINT32_C(0x609200fe),"unixcompact_code32_bit3",sxarfinal_unixcompact_code32_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code32_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code32_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,32]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code32_bit4={UINT32_C(0x609200ff),"unixcompact_code32_bit4",sxarfinal_unixcompact_code32_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code32_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code32_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,32]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code32_bit5={UINT32_C(0x60920100),"unixcompact_code32_bit5",sxarfinal_unixcompact_code32_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code32_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code32_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,32]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code32_bit6={UINT32_C(0x60920101),"unixcompact_code32_bit6",sxarfinal_unixcompact_code32_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code32_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code32_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,32]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code32_bit7={UINT32_C(0x60920102),"unixcompact_code32_bit7",sxarfinal_unixcompact_code32_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code32_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code33_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,33]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code33_bit0={UINT32_C(0x60920103),"unixcompact_code33_bit0",sxarfinal_unixcompact_code33_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code33_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code33_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,33]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code33_bit1={UINT32_C(0x60920104),"unixcompact_code33_bit1",sxarfinal_unixcompact_code33_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code33_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code33_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,33]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code33_bit2={UINT32_C(0x60920105),"unixcompact_code33_bit2",sxarfinal_unixcompact_code33_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code33_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code33_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,33]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code33_bit3={UINT32_C(0x60920106),"unixcompact_code33_bit3",sxarfinal_unixcompact_code33_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code33_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code33_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,33]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code33_bit4={UINT32_C(0x60920107),"unixcompact_code33_bit4",sxarfinal_unixcompact_code33_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code33_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code33_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,33]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code33_bit5={UINT32_C(0x60920108),"unixcompact_code33_bit5",sxarfinal_unixcompact_code33_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code33_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code33_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,33]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code33_bit6={UINT32_C(0x60920109),"unixcompact_code33_bit6",sxarfinal_unixcompact_code33_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code33_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code33_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,33]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code33_bit7={UINT32_C(0x6092010a),"unixcompact_code33_bit7",sxarfinal_unixcompact_code33_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code33_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code34_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,34]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code34_bit0={UINT32_C(0x6092010b),"unixcompact_code34_bit0",sxarfinal_unixcompact_code34_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code34_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code34_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,34]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code34_bit1={UINT32_C(0x6092010c),"unixcompact_code34_bit1",sxarfinal_unixcompact_code34_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code34_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code34_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,34]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code34_bit2={UINT32_C(0x6092010d),"unixcompact_code34_bit2",sxarfinal_unixcompact_code34_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code34_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code34_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,34]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code34_bit3={UINT32_C(0x6092010e),"unixcompact_code34_bit3",sxarfinal_unixcompact_code34_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code34_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code34_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,34]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code34_bit4={UINT32_C(0x6092010f),"unixcompact_code34_bit4",sxarfinal_unixcompact_code34_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code34_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code34_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,34]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code34_bit5={UINT32_C(0x60920110),"unixcompact_code34_bit5",sxarfinal_unixcompact_code34_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code34_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code34_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,34]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code34_bit6={UINT32_C(0x60920111),"unixcompact_code34_bit6",sxarfinal_unixcompact_code34_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code34_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code34_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,34]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code34_bit7={UINT32_C(0x60920112),"unixcompact_code34_bit7",sxarfinal_unixcompact_code34_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code34_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code35_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,35]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code35_bit0={UINT32_C(0x60920113),"unixcompact_code35_bit0",sxarfinal_unixcompact_code35_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code35_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code35_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,35]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code35_bit1={UINT32_C(0x60920114),"unixcompact_code35_bit1",sxarfinal_unixcompact_code35_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code35_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code35_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,35]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code35_bit2={UINT32_C(0x60920115),"unixcompact_code35_bit2",sxarfinal_unixcompact_code35_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code35_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code35_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,35]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code35_bit3={UINT32_C(0x60920116),"unixcompact_code35_bit3",sxarfinal_unixcompact_code35_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code35_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code35_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,35]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code35_bit4={UINT32_C(0x60920117),"unixcompact_code35_bit4",sxarfinal_unixcompact_code35_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code35_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code35_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,35]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code35_bit5={UINT32_C(0x60920118),"unixcompact_code35_bit5",sxarfinal_unixcompact_code35_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code35_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code35_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,35]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code35_bit6={UINT32_C(0x60920119),"unixcompact_code35_bit6",sxarfinal_unixcompact_code35_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code35_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code35_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,35]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code35_bit7={UINT32_C(0x6092011a),"unixcompact_code35_bit7",sxarfinal_unixcompact_code35_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code35_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code36_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,36]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code36_bit0={UINT32_C(0x6092011b),"unixcompact_code36_bit0",sxarfinal_unixcompact_code36_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code36_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code36_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,36]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code36_bit1={UINT32_C(0x6092011c),"unixcompact_code36_bit1",sxarfinal_unixcompact_code36_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code36_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code36_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,36]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code36_bit2={UINT32_C(0x6092011d),"unixcompact_code36_bit2",sxarfinal_unixcompact_code36_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code36_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code36_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,36]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code36_bit3={UINT32_C(0x6092011e),"unixcompact_code36_bit3",sxarfinal_unixcompact_code36_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code36_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code36_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,36]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code36_bit4={UINT32_C(0x6092011f),"unixcompact_code36_bit4",sxarfinal_unixcompact_code36_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code36_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code36_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,36]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code36_bit5={UINT32_C(0x60920120),"unixcompact_code36_bit5",sxarfinal_unixcompact_code36_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code36_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code36_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,36]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code36_bit6={UINT32_C(0x60920121),"unixcompact_code36_bit6",sxarfinal_unixcompact_code36_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code36_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code36_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,36]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code36_bit7={UINT32_C(0x60920122),"unixcompact_code36_bit7",sxarfinal_unixcompact_code36_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code36_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code37_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,37]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code37_bit0={UINT32_C(0x60920123),"unixcompact_code37_bit0",sxarfinal_unixcompact_code37_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code37_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code37_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,37]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code37_bit1={UINT32_C(0x60920124),"unixcompact_code37_bit1",sxarfinal_unixcompact_code37_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code37_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code37_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,37]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code37_bit2={UINT32_C(0x60920125),"unixcompact_code37_bit2",sxarfinal_unixcompact_code37_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code37_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code37_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,37]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code37_bit3={UINT32_C(0x60920126),"unixcompact_code37_bit3",sxarfinal_unixcompact_code37_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code37_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code37_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,37]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code37_bit4={UINT32_C(0x60920127),"unixcompact_code37_bit4",sxarfinal_unixcompact_code37_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code37_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code37_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,37]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code37_bit5={UINT32_C(0x60920128),"unixcompact_code37_bit5",sxarfinal_unixcompact_code37_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code37_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code37_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,37]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code37_bit6={UINT32_C(0x60920129),"unixcompact_code37_bit6",sxarfinal_unixcompact_code37_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code37_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code37_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,37]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code37_bit7={UINT32_C(0x6092012a),"unixcompact_code37_bit7",sxarfinal_unixcompact_code37_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code37_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code38_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,38]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code38_bit0={UINT32_C(0x6092012b),"unixcompact_code38_bit0",sxarfinal_unixcompact_code38_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code38_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code38_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,38]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code38_bit1={UINT32_C(0x6092012c),"unixcompact_code38_bit1",sxarfinal_unixcompact_code38_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code38_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code38_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,38]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code38_bit2={UINT32_C(0x6092012d),"unixcompact_code38_bit2",sxarfinal_unixcompact_code38_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code38_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code38_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,38]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code38_bit3={UINT32_C(0x6092012e),"unixcompact_code38_bit3",sxarfinal_unixcompact_code38_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code38_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code38_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,38]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code38_bit4={UINT32_C(0x6092012f),"unixcompact_code38_bit4",sxarfinal_unixcompact_code38_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code38_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code38_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,38]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code38_bit5={UINT32_C(0x60920130),"unixcompact_code38_bit5",sxarfinal_unixcompact_code38_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code38_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code38_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,38]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code38_bit6={UINT32_C(0x60920131),"unixcompact_code38_bit6",sxarfinal_unixcompact_code38_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code38_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code38_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,38]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code38_bit7={UINT32_C(0x60920132),"unixcompact_code38_bit7",sxarfinal_unixcompact_code38_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code38_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code39_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,39]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code39_bit0={UINT32_C(0x60920133),"unixcompact_code39_bit0",sxarfinal_unixcompact_code39_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code39_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code39_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,39]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code39_bit1={UINT32_C(0x60920134),"unixcompact_code39_bit1",sxarfinal_unixcompact_code39_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code39_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code39_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,39]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code39_bit2={UINT32_C(0x60920135),"unixcompact_code39_bit2",sxarfinal_unixcompact_code39_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code39_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code39_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,39]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code39_bit3={UINT32_C(0x60920136),"unixcompact_code39_bit3",sxarfinal_unixcompact_code39_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code39_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code39_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,39]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code39_bit4={UINT32_C(0x60920137),"unixcompact_code39_bit4",sxarfinal_unixcompact_code39_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code39_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code39_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,39]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code39_bit5={UINT32_C(0x60920138),"unixcompact_code39_bit5",sxarfinal_unixcompact_code39_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code39_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code39_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,39]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code39_bit6={UINT32_C(0x60920139),"unixcompact_code39_bit6",sxarfinal_unixcompact_code39_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code39_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code39_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,39]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code39_bit7={UINT32_C(0x6092013a),"unixcompact_code39_bit7",sxarfinal_unixcompact_code39_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code39_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code40_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,40]",0,5,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code40_bit0={UINT32_C(0x6092013b),"unixcompact_code40_bit0",sxarfinal_unixcompact_code40_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code40_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code40_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,40]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code40_bit1={UINT32_C(0x6092013c),"unixcompact_code40_bit1",sxarfinal_unixcompact_code40_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code40_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code40_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,40]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code40_bit2={UINT32_C(0x6092013d),"unixcompact_code40_bit2",sxarfinal_unixcompact_code40_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code40_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code40_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,40]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code40_bit3={UINT32_C(0x6092013e),"unixcompact_code40_bit3",sxarfinal_unixcompact_code40_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code40_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code40_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,40]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code40_bit4={UINT32_C(0x6092013f),"unixcompact_code40_bit4",sxarfinal_unixcompact_code40_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code40_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code40_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,40]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code40_bit5={UINT32_C(0x60920140),"unixcompact_code40_bit5",sxarfinal_unixcompact_code40_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code40_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code40_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,40]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code40_bit6={UINT32_C(0x60920141),"unixcompact_code40_bit6",sxarfinal_unixcompact_code40_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code40_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code40_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,40]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code40_bit7={UINT32_C(0x60920142),"unixcompact_code40_bit7",sxarfinal_unixcompact_code40_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code40_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code41_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,41]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code41_bit0={UINT32_C(0x60920143),"unixcompact_code41_bit0",sxarfinal_unixcompact_code41_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code41_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code41_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,41]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code41_bit1={UINT32_C(0x60920144),"unixcompact_code41_bit1",sxarfinal_unixcompact_code41_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code41_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code41_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,41]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code41_bit2={UINT32_C(0x60920145),"unixcompact_code41_bit2",sxarfinal_unixcompact_code41_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code41_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code41_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,41]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code41_bit3={UINT32_C(0x60920146),"unixcompact_code41_bit3",sxarfinal_unixcompact_code41_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code41_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code41_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,41]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code41_bit4={UINT32_C(0x60920147),"unixcompact_code41_bit4",sxarfinal_unixcompact_code41_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code41_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code41_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,41]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code41_bit5={UINT32_C(0x60920148),"unixcompact_code41_bit5",sxarfinal_unixcompact_code41_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code41_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code41_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,41]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code41_bit6={UINT32_C(0x60920149),"unixcompact_code41_bit6",sxarfinal_unixcompact_code41_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code41_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code41_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,41]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code41_bit7={UINT32_C(0x6092014a),"unixcompact_code41_bit7",sxarfinal_unixcompact_code41_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code41_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code42_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,42]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code42_bit0={UINT32_C(0x6092014b),"unixcompact_code42_bit0",sxarfinal_unixcompact_code42_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code42_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code42_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,42]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code42_bit1={UINT32_C(0x6092014c),"unixcompact_code42_bit1",sxarfinal_unixcompact_code42_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code42_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code42_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,42]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code42_bit2={UINT32_C(0x6092014d),"unixcompact_code42_bit2",sxarfinal_unixcompact_code42_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code42_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code42_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,42]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code42_bit3={UINT32_C(0x6092014e),"unixcompact_code42_bit3",sxarfinal_unixcompact_code42_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code42_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code42_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,42]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code42_bit4={UINT32_C(0x6092014f),"unixcompact_code42_bit4",sxarfinal_unixcompact_code42_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code42_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code42_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,42]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code42_bit5={UINT32_C(0x60920150),"unixcompact_code42_bit5",sxarfinal_unixcompact_code42_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code42_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code42_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,42]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code42_bit6={UINT32_C(0x60920151),"unixcompact_code42_bit6",sxarfinal_unixcompact_code42_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code42_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code42_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,42]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code42_bit7={UINT32_C(0x60920152),"unixcompact_code42_bit7",sxarfinal_unixcompact_code42_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code42_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code43_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,43]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code43_bit0={UINT32_C(0x60920153),"unixcompact_code43_bit0",sxarfinal_unixcompact_code43_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code43_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code43_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,43]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code43_bit1={UINT32_C(0x60920154),"unixcompact_code43_bit1",sxarfinal_unixcompact_code43_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code43_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code43_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,43]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code43_bit2={UINT32_C(0x60920155),"unixcompact_code43_bit2",sxarfinal_unixcompact_code43_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code43_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code43_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,43]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code43_bit3={UINT32_C(0x60920156),"unixcompact_code43_bit3",sxarfinal_unixcompact_code43_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code43_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code43_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,43]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code43_bit4={UINT32_C(0x60920157),"unixcompact_code43_bit4",sxarfinal_unixcompact_code43_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code43_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code43_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,43]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code43_bit5={UINT32_C(0x60920158),"unixcompact_code43_bit5",sxarfinal_unixcompact_code43_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code43_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code43_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,43]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code43_bit6={UINT32_C(0x60920159),"unixcompact_code43_bit6",sxarfinal_unixcompact_code43_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code43_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code43_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,43]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code43_bit7={UINT32_C(0x6092015a),"unixcompact_code43_bit7",sxarfinal_unixcompact_code43_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code43_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code44_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,44]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code44_bit0={UINT32_C(0x6092015b),"unixcompact_code44_bit0",sxarfinal_unixcompact_code44_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code44_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code44_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,44]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code44_bit1={UINT32_C(0x6092015c),"unixcompact_code44_bit1",sxarfinal_unixcompact_code44_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code44_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code44_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,44]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code44_bit2={UINT32_C(0x6092015d),"unixcompact_code44_bit2",sxarfinal_unixcompact_code44_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code44_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code44_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,44]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code44_bit3={UINT32_C(0x6092015e),"unixcompact_code44_bit3",sxarfinal_unixcompact_code44_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code44_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code44_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,44]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code44_bit4={UINT32_C(0x6092015f),"unixcompact_code44_bit4",sxarfinal_unixcompact_code44_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code44_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code44_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,44]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code44_bit5={UINT32_C(0x60920160),"unixcompact_code44_bit5",sxarfinal_unixcompact_code44_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code44_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code44_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,44]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code44_bit6={UINT32_C(0x60920161),"unixcompact_code44_bit6",sxarfinal_unixcompact_code44_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code44_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code44_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,44]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code44_bit7={UINT32_C(0x60920162),"unixcompact_code44_bit7",sxarfinal_unixcompact_code44_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code44_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code45_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,45]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code45_bit0={UINT32_C(0x60920163),"unixcompact_code45_bit0",sxarfinal_unixcompact_code45_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code45_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code45_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,45]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code45_bit1={UINT32_C(0x60920164),"unixcompact_code45_bit1",sxarfinal_unixcompact_code45_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code45_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code45_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,45]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code45_bit2={UINT32_C(0x60920165),"unixcompact_code45_bit2",sxarfinal_unixcompact_code45_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code45_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code45_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,45]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code45_bit3={UINT32_C(0x60920166),"unixcompact_code45_bit3",sxarfinal_unixcompact_code45_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code45_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code45_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,45]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code45_bit4={UINT32_C(0x60920167),"unixcompact_code45_bit4",sxarfinal_unixcompact_code45_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code45_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code45_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,45]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code45_bit5={UINT32_C(0x60920168),"unixcompact_code45_bit5",sxarfinal_unixcompact_code45_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code45_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code45_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,45]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code45_bit6={UINT32_C(0x60920169),"unixcompact_code45_bit6",sxarfinal_unixcompact_code45_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code45_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code45_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,45]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code45_bit7={UINT32_C(0x6092016a),"unixcompact_code45_bit7",sxarfinal_unixcompact_code45_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code45_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code46_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,46]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code46_bit0={UINT32_C(0x6092016b),"unixcompact_code46_bit0",sxarfinal_unixcompact_code46_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code46_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code46_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,46]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code46_bit1={UINT32_C(0x6092016c),"unixcompact_code46_bit1",sxarfinal_unixcompact_code46_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code46_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code46_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,46]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code46_bit2={UINT32_C(0x6092016d),"unixcompact_code46_bit2",sxarfinal_unixcompact_code46_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code46_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code46_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,46]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code46_bit3={UINT32_C(0x6092016e),"unixcompact_code46_bit3",sxarfinal_unixcompact_code46_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code46_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code46_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,46]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code46_bit4={UINT32_C(0x6092016f),"unixcompact_code46_bit4",sxarfinal_unixcompact_code46_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code46_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code46_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,46]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code46_bit5={UINT32_C(0x60920170),"unixcompact_code46_bit5",sxarfinal_unixcompact_code46_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code46_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code46_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,46]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code46_bit6={UINT32_C(0x60920171),"unixcompact_code46_bit6",sxarfinal_unixcompact_code46_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code46_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code46_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,46]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code46_bit7={UINT32_C(0x60920172),"unixcompact_code46_bit7",sxarfinal_unixcompact_code46_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code46_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code47_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,47]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code47_bit0={UINT32_C(0x60920173),"unixcompact_code47_bit0",sxarfinal_unixcompact_code47_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code47_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code47_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,47]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code47_bit1={UINT32_C(0x60920174),"unixcompact_code47_bit1",sxarfinal_unixcompact_code47_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code47_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code47_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,47]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code47_bit2={UINT32_C(0x60920175),"unixcompact_code47_bit2",sxarfinal_unixcompact_code47_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code47_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code47_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,47]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code47_bit3={UINT32_C(0x60920176),"unixcompact_code47_bit3",sxarfinal_unixcompact_code47_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code47_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code47_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,47]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code47_bit4={UINT32_C(0x60920177),"unixcompact_code47_bit4",sxarfinal_unixcompact_code47_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code47_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code47_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,47]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code47_bit5={UINT32_C(0x60920178),"unixcompact_code47_bit5",sxarfinal_unixcompact_code47_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code47_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code47_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,47]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code47_bit6={UINT32_C(0x60920179),"unixcompact_code47_bit6",sxarfinal_unixcompact_code47_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code47_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code47_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,47]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code47_bit7={UINT32_C(0x6092017a),"unixcompact_code47_bit7",sxarfinal_unixcompact_code47_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code47_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code48_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,48]",0,6,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code48_bit0={UINT32_C(0x6092017b),"unixcompact_code48_bit0",sxarfinal_unixcompact_code48_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code48_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code48_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,48]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code48_bit1={UINT32_C(0x6092017c),"unixcompact_code48_bit1",sxarfinal_unixcompact_code48_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code48_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code48_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,48]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code48_bit2={UINT32_C(0x6092017d),"unixcompact_code48_bit2",sxarfinal_unixcompact_code48_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code48_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code48_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,48]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code48_bit3={UINT32_C(0x6092017e),"unixcompact_code48_bit3",sxarfinal_unixcompact_code48_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code48_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code48_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,48]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code48_bit4={UINT32_C(0x6092017f),"unixcompact_code48_bit4",sxarfinal_unixcompact_code48_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code48_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code48_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,48]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code48_bit5={UINT32_C(0x60920180),"unixcompact_code48_bit5",sxarfinal_unixcompact_code48_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code48_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code48_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,48]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code48_bit6={UINT32_C(0x60920181),"unixcompact_code48_bit6",sxarfinal_unixcompact_code48_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code48_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code48_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,48]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code48_bit7={UINT32_C(0x60920182),"unixcompact_code48_bit7",sxarfinal_unixcompact_code48_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code48_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code49_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,49]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code49_bit0={UINT32_C(0x60920183),"unixcompact_code49_bit0",sxarfinal_unixcompact_code49_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code49_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code49_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,49]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code49_bit1={UINT32_C(0x60920184),"unixcompact_code49_bit1",sxarfinal_unixcompact_code49_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code49_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code49_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,49]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code49_bit2={UINT32_C(0x60920185),"unixcompact_code49_bit2",sxarfinal_unixcompact_code49_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code49_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code49_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,49]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code49_bit3={UINT32_C(0x60920186),"unixcompact_code49_bit3",sxarfinal_unixcompact_code49_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code49_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code49_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,49]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code49_bit4={UINT32_C(0x60920187),"unixcompact_code49_bit4",sxarfinal_unixcompact_code49_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code49_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code49_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,49]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code49_bit5={UINT32_C(0x60920188),"unixcompact_code49_bit5",sxarfinal_unixcompact_code49_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code49_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code49_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,49]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code49_bit6={UINT32_C(0x60920189),"unixcompact_code49_bit6",sxarfinal_unixcompact_code49_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code49_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code49_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,49]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code49_bit7={UINT32_C(0x6092018a),"unixcompact_code49_bit7",sxarfinal_unixcompact_code49_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code49_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code50_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,50]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code50_bit0={UINT32_C(0x6092018b),"unixcompact_code50_bit0",sxarfinal_unixcompact_code50_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code50_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code50_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,50]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code50_bit1={UINT32_C(0x6092018c),"unixcompact_code50_bit1",sxarfinal_unixcompact_code50_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code50_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code50_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,50]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code50_bit2={UINT32_C(0x6092018d),"unixcompact_code50_bit2",sxarfinal_unixcompact_code50_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code50_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code50_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,50]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code50_bit3={UINT32_C(0x6092018e),"unixcompact_code50_bit3",sxarfinal_unixcompact_code50_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code50_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code50_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,50]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code50_bit4={UINT32_C(0x6092018f),"unixcompact_code50_bit4",sxarfinal_unixcompact_code50_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code50_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code50_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,50]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code50_bit5={UINT32_C(0x60920190),"unixcompact_code50_bit5",sxarfinal_unixcompact_code50_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code50_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code50_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,50]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code50_bit6={UINT32_C(0x60920191),"unixcompact_code50_bit6",sxarfinal_unixcompact_code50_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code50_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code50_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,50]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code50_bit7={UINT32_C(0x60920192),"unixcompact_code50_bit7",sxarfinal_unixcompact_code50_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code50_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code51_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,51]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code51_bit0={UINT32_C(0x60920193),"unixcompact_code51_bit0",sxarfinal_unixcompact_code51_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code51_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code51_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,51]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code51_bit1={UINT32_C(0x60920194),"unixcompact_code51_bit1",sxarfinal_unixcompact_code51_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code51_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code51_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,51]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code51_bit2={UINT32_C(0x60920195),"unixcompact_code51_bit2",sxarfinal_unixcompact_code51_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code51_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code51_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,51]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code51_bit3={UINT32_C(0x60920196),"unixcompact_code51_bit3",sxarfinal_unixcompact_code51_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code51_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code51_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,51]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code51_bit4={UINT32_C(0x60920197),"unixcompact_code51_bit4",sxarfinal_unixcompact_code51_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code51_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code51_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,51]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code51_bit5={UINT32_C(0x60920198),"unixcompact_code51_bit5",sxarfinal_unixcompact_code51_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code51_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code51_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,51]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code51_bit6={UINT32_C(0x60920199),"unixcompact_code51_bit6",sxarfinal_unixcompact_code51_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code51_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code51_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,51]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code51_bit7={UINT32_C(0x6092019a),"unixcompact_code51_bit7",sxarfinal_unixcompact_code51_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code51_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code52_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,52]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code52_bit0={UINT32_C(0x6092019b),"unixcompact_code52_bit0",sxarfinal_unixcompact_code52_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code52_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code52_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,52]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code52_bit1={UINT32_C(0x6092019c),"unixcompact_code52_bit1",sxarfinal_unixcompact_code52_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code52_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code52_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,52]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code52_bit2={UINT32_C(0x6092019d),"unixcompact_code52_bit2",sxarfinal_unixcompact_code52_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code52_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code52_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,52]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code52_bit3={UINT32_C(0x6092019e),"unixcompact_code52_bit3",sxarfinal_unixcompact_code52_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code52_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code52_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,52]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code52_bit4={UINT32_C(0x6092019f),"unixcompact_code52_bit4",sxarfinal_unixcompact_code52_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code52_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code52_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,52]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code52_bit5={UINT32_C(0x609201a0),"unixcompact_code52_bit5",sxarfinal_unixcompact_code52_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code52_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code52_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,52]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code52_bit6={UINT32_C(0x609201a1),"unixcompact_code52_bit6",sxarfinal_unixcompact_code52_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code52_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code52_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,52]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code52_bit7={UINT32_C(0x609201a2),"unixcompact_code52_bit7",sxarfinal_unixcompact_code52_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code52_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code53_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,53]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code53_bit0={UINT32_C(0x609201a3),"unixcompact_code53_bit0",sxarfinal_unixcompact_code53_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code53_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code53_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,53]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code53_bit1={UINT32_C(0x609201a4),"unixcompact_code53_bit1",sxarfinal_unixcompact_code53_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code53_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code53_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,53]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code53_bit2={UINT32_C(0x609201a5),"unixcompact_code53_bit2",sxarfinal_unixcompact_code53_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code53_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code53_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,53]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code53_bit3={UINT32_C(0x609201a6),"unixcompact_code53_bit3",sxarfinal_unixcompact_code53_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code53_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code53_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,53]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code53_bit4={UINT32_C(0x609201a7),"unixcompact_code53_bit4",sxarfinal_unixcompact_code53_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code53_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code53_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,53]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code53_bit5={UINT32_C(0x609201a8),"unixcompact_code53_bit5",sxarfinal_unixcompact_code53_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code53_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code53_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,53]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code53_bit6={UINT32_C(0x609201a9),"unixcompact_code53_bit6",sxarfinal_unixcompact_code53_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code53_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code53_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,53]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code53_bit7={UINT32_C(0x609201aa),"unixcompact_code53_bit7",sxarfinal_unixcompact_code53_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code53_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code54_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,54]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code54_bit0={UINT32_C(0x609201ab),"unixcompact_code54_bit0",sxarfinal_unixcompact_code54_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code54_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code54_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,54]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code54_bit1={UINT32_C(0x609201ac),"unixcompact_code54_bit1",sxarfinal_unixcompact_code54_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code54_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code54_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,54]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code54_bit2={UINT32_C(0x609201ad),"unixcompact_code54_bit2",sxarfinal_unixcompact_code54_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code54_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code54_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,54]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code54_bit3={UINT32_C(0x609201ae),"unixcompact_code54_bit3",sxarfinal_unixcompact_code54_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code54_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code54_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,54]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code54_bit4={UINT32_C(0x609201af),"unixcompact_code54_bit4",sxarfinal_unixcompact_code54_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code54_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code54_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,54]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code54_bit5={UINT32_C(0x609201b0),"unixcompact_code54_bit5",sxarfinal_unixcompact_code54_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code54_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code54_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,54]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code54_bit6={UINT32_C(0x609201b1),"unixcompact_code54_bit6",sxarfinal_unixcompact_code54_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code54_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code54_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,54]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code54_bit7={UINT32_C(0x609201b2),"unixcompact_code54_bit7",sxarfinal_unixcompact_code54_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code54_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code55_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,55]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code55_bit0={UINT32_C(0x609201b3),"unixcompact_code55_bit0",sxarfinal_unixcompact_code55_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code55_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code55_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,55]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code55_bit1={UINT32_C(0x609201b4),"unixcompact_code55_bit1",sxarfinal_unixcompact_code55_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code55_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code55_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,55]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code55_bit2={UINT32_C(0x609201b5),"unixcompact_code55_bit2",sxarfinal_unixcompact_code55_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code55_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code55_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,55]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code55_bit3={UINT32_C(0x609201b6),"unixcompact_code55_bit3",sxarfinal_unixcompact_code55_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code55_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code55_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,55]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code55_bit4={UINT32_C(0x609201b7),"unixcompact_code55_bit4",sxarfinal_unixcompact_code55_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code55_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code55_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,55]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code55_bit5={UINT32_C(0x609201b8),"unixcompact_code55_bit5",sxarfinal_unixcompact_code55_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code55_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code55_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,55]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code55_bit6={UINT32_C(0x609201b9),"unixcompact_code55_bit6",sxarfinal_unixcompact_code55_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code55_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code55_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,55]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code55_bit7={UINT32_C(0x609201ba),"unixcompact_code55_bit7",sxarfinal_unixcompact_code55_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code55_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code56_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,56]",0,7,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code56_bit0={UINT32_C(0x609201bb),"unixcompact_code56_bit0",sxarfinal_unixcompact_code56_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code56_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code56_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,56]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code56_bit1={UINT32_C(0x609201bc),"unixcompact_code56_bit1",sxarfinal_unixcompact_code56_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code56_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code56_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,56]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code56_bit2={UINT32_C(0x609201bd),"unixcompact_code56_bit2",sxarfinal_unixcompact_code56_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code56_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code56_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,56]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code56_bit3={UINT32_C(0x609201be),"unixcompact_code56_bit3",sxarfinal_unixcompact_code56_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code56_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code56_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,56]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code56_bit4={UINT32_C(0x609201bf),"unixcompact_code56_bit4",sxarfinal_unixcompact_code56_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code56_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code56_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,56]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code56_bit5={UINT32_C(0x609201c0),"unixcompact_code56_bit5",sxarfinal_unixcompact_code56_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code56_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code56_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,56]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code56_bit6={UINT32_C(0x609201c1),"unixcompact_code56_bit6",sxarfinal_unixcompact_code56_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code56_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code56_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,56]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code56_bit7={UINT32_C(0x609201c2),"unixcompact_code56_bit7",sxarfinal_unixcompact_code56_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code56_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code57_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,57]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code57_bit0={UINT32_C(0x609201c3),"unixcompact_code57_bit0",sxarfinal_unixcompact_code57_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code57_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code57_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,57]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code57_bit1={UINT32_C(0x609201c4),"unixcompact_code57_bit1",sxarfinal_unixcompact_code57_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code57_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code57_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,57]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code57_bit2={UINT32_C(0x609201c5),"unixcompact_code57_bit2",sxarfinal_unixcompact_code57_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code57_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code57_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,57]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code57_bit3={UINT32_C(0x609201c6),"unixcompact_code57_bit3",sxarfinal_unixcompact_code57_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code57_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code57_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,57]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code57_bit4={UINT32_C(0x609201c7),"unixcompact_code57_bit4",sxarfinal_unixcompact_code57_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code57_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code57_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,57]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code57_bit5={UINT32_C(0x609201c8),"unixcompact_code57_bit5",sxarfinal_unixcompact_code57_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code57_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code57_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,57]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code57_bit6={UINT32_C(0x609201c9),"unixcompact_code57_bit6",sxarfinal_unixcompact_code57_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code57_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code57_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,57]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code57_bit7={UINT32_C(0x609201ca),"unixcompact_code57_bit7",sxarfinal_unixcompact_code57_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code57_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code58_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,58]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code58_bit0={UINT32_C(0x609201cb),"unixcompact_code58_bit0",sxarfinal_unixcompact_code58_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code58_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code58_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,58]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code58_bit1={UINT32_C(0x609201cc),"unixcompact_code58_bit1",sxarfinal_unixcompact_code58_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code58_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code58_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,58]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code58_bit2={UINT32_C(0x609201cd),"unixcompact_code58_bit2",sxarfinal_unixcompact_code58_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code58_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code58_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,58]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code58_bit3={UINT32_C(0x609201ce),"unixcompact_code58_bit3",sxarfinal_unixcompact_code58_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code58_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code58_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,58]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code58_bit4={UINT32_C(0x609201cf),"unixcompact_code58_bit4",sxarfinal_unixcompact_code58_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code58_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code58_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,58]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code58_bit5={UINT32_C(0x609201d0),"unixcompact_code58_bit5",sxarfinal_unixcompact_code58_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code58_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code58_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,58]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code58_bit6={UINT32_C(0x609201d1),"unixcompact_code58_bit6",sxarfinal_unixcompact_code58_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code58_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code58_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,58]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code58_bit7={UINT32_C(0x609201d2),"unixcompact_code58_bit7",sxarfinal_unixcompact_code58_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code58_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code59_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,59]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code59_bit0={UINT32_C(0x609201d3),"unixcompact_code59_bit0",sxarfinal_unixcompact_code59_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code59_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code59_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,59]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code59_bit1={UINT32_C(0x609201d4),"unixcompact_code59_bit1",sxarfinal_unixcompact_code59_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code59_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code59_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,59]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code59_bit2={UINT32_C(0x609201d5),"unixcompact_code59_bit2",sxarfinal_unixcompact_code59_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code59_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code59_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,59]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code59_bit3={UINT32_C(0x609201d6),"unixcompact_code59_bit3",sxarfinal_unixcompact_code59_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code59_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code59_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,59]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code59_bit4={UINT32_C(0x609201d7),"unixcompact_code59_bit4",sxarfinal_unixcompact_code59_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code59_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code59_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,59]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code59_bit5={UINT32_C(0x609201d8),"unixcompact_code59_bit5",sxarfinal_unixcompact_code59_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code59_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code59_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,59]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code59_bit6={UINT32_C(0x609201d9),"unixcompact_code59_bit6",sxarfinal_unixcompact_code59_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code59_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code59_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,59]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code59_bit7={UINT32_C(0x609201da),"unixcompact_code59_bit7",sxarfinal_unixcompact_code59_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code59_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code60_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,60]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code60_bit0={UINT32_C(0x609201db),"unixcompact_code60_bit0",sxarfinal_unixcompact_code60_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code60_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code60_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,60]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code60_bit1={UINT32_C(0x609201dc),"unixcompact_code60_bit1",sxarfinal_unixcompact_code60_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code60_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code60_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,60]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code60_bit2={UINT32_C(0x609201dd),"unixcompact_code60_bit2",sxarfinal_unixcompact_code60_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code60_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code60_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,60]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code60_bit3={UINT32_C(0x609201de),"unixcompact_code60_bit3",sxarfinal_unixcompact_code60_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code60_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code60_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,60]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code60_bit4={UINT32_C(0x609201df),"unixcompact_code60_bit4",sxarfinal_unixcompact_code60_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code60_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code60_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,60]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code60_bit5={UINT32_C(0x609201e0),"unixcompact_code60_bit5",sxarfinal_unixcompact_code60_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code60_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code60_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,60]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code60_bit6={UINT32_C(0x609201e1),"unixcompact_code60_bit6",sxarfinal_unixcompact_code60_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code60_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code60_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,60]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code60_bit7={UINT32_C(0x609201e2),"unixcompact_code60_bit7",sxarfinal_unixcompact_code60_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code60_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code61_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,61]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code61_bit0={UINT32_C(0x609201e3),"unixcompact_code61_bit0",sxarfinal_unixcompact_code61_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code61_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code61_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,61]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code61_bit1={UINT32_C(0x609201e4),"unixcompact_code61_bit1",sxarfinal_unixcompact_code61_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code61_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code61_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,61]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code61_bit2={UINT32_C(0x609201e5),"unixcompact_code61_bit2",sxarfinal_unixcompact_code61_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code61_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code61_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,61]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code61_bit3={UINT32_C(0x609201e6),"unixcompact_code61_bit3",sxarfinal_unixcompact_code61_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code61_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code61_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,61]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code61_bit4={UINT32_C(0x609201e7),"unixcompact_code61_bit4",sxarfinal_unixcompact_code61_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code61_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code61_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,61]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code61_bit5={UINT32_C(0x609201e8),"unixcompact_code61_bit5",sxarfinal_unixcompact_code61_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code61_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code61_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,61]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code61_bit6={UINT32_C(0x609201e9),"unixcompact_code61_bit6",sxarfinal_unixcompact_code61_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code61_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code61_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,61]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code61_bit7={UINT32_C(0x609201ea),"unixcompact_code61_bit7",sxarfinal_unixcompact_code61_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code61_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code62_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,62]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code62_bit0={UINT32_C(0x609201eb),"unixcompact_code62_bit0",sxarfinal_unixcompact_code62_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code62_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code62_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,62]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code62_bit1={UINT32_C(0x609201ec),"unixcompact_code62_bit1",sxarfinal_unixcompact_code62_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code62_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code62_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,62]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code62_bit2={UINT32_C(0x609201ed),"unixcompact_code62_bit2",sxarfinal_unixcompact_code62_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code62_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code62_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,62]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code62_bit3={UINT32_C(0x609201ee),"unixcompact_code62_bit3",sxarfinal_unixcompact_code62_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code62_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code62_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,62]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code62_bit4={UINT32_C(0x609201ef),"unixcompact_code62_bit4",sxarfinal_unixcompact_code62_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code62_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code62_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,62]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code62_bit5={UINT32_C(0x609201f0),"unixcompact_code62_bit5",sxarfinal_unixcompact_code62_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code62_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code62_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,62]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code62_bit6={UINT32_C(0x609201f1),"unixcompact_code62_bit6",sxarfinal_unixcompact_code62_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code62_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code62_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,62]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code62_bit7={UINT32_C(0x609201f2),"unixcompact_code62_bit7",sxarfinal_unixcompact_code62_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code62_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code63_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,63]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code63_bit0={UINT32_C(0x609201f3),"unixcompact_code63_bit0",sxarfinal_unixcompact_code63_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code63_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code63_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,63]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code63_bit1={UINT32_C(0x609201f4),"unixcompact_code63_bit1",sxarfinal_unixcompact_code63_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code63_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code63_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,63]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code63_bit2={UINT32_C(0x609201f5),"unixcompact_code63_bit2",sxarfinal_unixcompact_code63_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code63_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code63_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,63]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code63_bit3={UINT32_C(0x609201f6),"unixcompact_code63_bit3",sxarfinal_unixcompact_code63_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code63_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code63_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,63]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code63_bit4={UINT32_C(0x609201f7),"unixcompact_code63_bit4",sxarfinal_unixcompact_code63_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code63_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code63_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,63]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code63_bit5={UINT32_C(0x609201f8),"unixcompact_code63_bit5",sxarfinal_unixcompact_code63_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code63_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code63_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,63]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code63_bit6={UINT32_C(0x609201f9),"unixcompact_code63_bit6",sxarfinal_unixcompact_code63_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code63_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code63_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,63]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code63_bit7={UINT32_C(0x609201fa),"unixcompact_code63_bit7",sxarfinal_unixcompact_code63_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code63_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code64_bit0_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[0,64]",0,8,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code64_bit0={UINT32_C(0x609201fb),"unixcompact_code64_bit0",sxarfinal_unixcompact_code64_bit0_fields,SX_COUNT(sxarfinal_unixcompact_code64_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code64_bit1_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[1,64]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code64_bit1={UINT32_C(0x609201fc),"unixcompact_code64_bit1",sxarfinal_unixcompact_code64_bit1_fields,SX_COUNT(sxarfinal_unixcompact_code64_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code64_bit2_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[2,64]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code64_bit2={UINT32_C(0x609201fd),"unixcompact_code64_bit2",sxarfinal_unixcompact_code64_bit2_fields,SX_COUNT(sxarfinal_unixcompact_code64_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code64_bit3_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[3,64]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code64_bit3={UINT32_C(0x609201fe),"unixcompact_code64_bit3",sxarfinal_unixcompact_code64_bit3_fields,SX_COUNT(sxarfinal_unixcompact_code64_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code64_bit4_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[4,64]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code64_bit4={UINT32_C(0x609201ff),"unixcompact_code64_bit4",sxarfinal_unixcompact_code64_bit4_fields,SX_COUNT(sxarfinal_unixcompact_code64_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code64_bit5_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[5,64]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code64_bit5={UINT32_C(0x60920200),"unixcompact_code64_bit5",sxarfinal_unixcompact_code64_bit5_fields,SX_COUNT(sxarfinal_unixcompact_code64_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code64_bit6_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[6,64]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code64_bit6={UINT32_C(0x60920201),"unixcompact_code64_bit6",sxarfinal_unixcompact_code64_bit6_fields,SX_COUNT(sxarfinal_unixcompact_code64_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_code64_bit7_fields[]={
 SX_FIELD("huffman_prefix_bits","msb_bits[7,64]",0,9,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_code64_bit7={UINT32_C(0x60920202),"unixcompact_code64_bit7",sxarfinal_unixcompact_code64_bit7_fields,SX_COUNT(sxarfinal_unixcompact_code64_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_new_literal_bit0_fields[]={
 SX_FIELD("new_literal","msb_bits[0,8]",0,1,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_new_literal_bit0={UINT32_C(0x60920203),"unixcompact_new_literal_bit0",sxarfinal_unixcompact_new_literal_bit0_fields,SX_COUNT(sxarfinal_unixcompact_new_literal_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_new_literal_bit1_fields[]={
 SX_FIELD("new_literal","msb_bits[1,8]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_new_literal_bit1={UINT32_C(0x60920204),"unixcompact_new_literal_bit1",sxarfinal_unixcompact_new_literal_bit1_fields,SX_COUNT(sxarfinal_unixcompact_new_literal_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_new_literal_bit2_fields[]={
 SX_FIELD("new_literal","msb_bits[2,8]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_new_literal_bit2={UINT32_C(0x60920205),"unixcompact_new_literal_bit2",sxarfinal_unixcompact_new_literal_bit2_fields,SX_COUNT(sxarfinal_unixcompact_new_literal_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_new_literal_bit3_fields[]={
 SX_FIELD("new_literal","msb_bits[3,8]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_new_literal_bit3={UINT32_C(0x60920206),"unixcompact_new_literal_bit3",sxarfinal_unixcompact_new_literal_bit3_fields,SX_COUNT(sxarfinal_unixcompact_new_literal_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_new_literal_bit4_fields[]={
 SX_FIELD("new_literal","msb_bits[4,8]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_new_literal_bit4={UINT32_C(0x60920207),"unixcompact_new_literal_bit4",sxarfinal_unixcompact_new_literal_bit4_fields,SX_COUNT(sxarfinal_unixcompact_new_literal_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_new_literal_bit5_fields[]={
 SX_FIELD("new_literal","msb_bits[5,8]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_new_literal_bit5={UINT32_C(0x60920208),"unixcompact_new_literal_bit5",sxarfinal_unixcompact_new_literal_bit5_fields,SX_COUNT(sxarfinal_unixcompact_new_literal_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_new_literal_bit6_fields[]={
 SX_FIELD("new_literal","msb_bits[6,8]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_new_literal_bit6={UINT32_C(0x60920209),"unixcompact_new_literal_bit6",sxarfinal_unixcompact_new_literal_bit6_fields,SX_COUNT(sxarfinal_unixcompact_new_literal_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_unixcompact_new_literal_bit7_fields[]={
 SX_FIELD("new_literal","msb_bits[7,8]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_unixcompact_new_literal_bit7={UINT32_C(0x6092020a),"unixcompact_new_literal_bit7",sxarfinal_unixcompact_new_literal_bit7_fields,SX_COUNT(sxarfinal_unixcompact_new_literal_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_tarx1_transport_prefix_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxarfinal_tarx1_transport_prefix={UINT32_C(0x6092020b),"tarx1_transport_prefix",sxarfinal_tarx1_transport_prefix_fields,SX_COUNT(sxarfinal_tarx1_transport_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_tarx1_encrypted_tar_core_fields[]={
 SX_FIELD("encoded_name","uint8[100]",0,100,SX_NONE),
 SX_FIELD("encoded_mode","uint8[8]",100,8,SX_NONE),
 SX_FIELD("encoded_uid","uint8[8]",108,8,SX_NONE),
 SX_FIELD("encoded_gid","uint8[8]",116,8,SX_NONE),
 SX_FIELD("encoded_size","uint8[12]",124,12,SX_NONE),
 SX_FIELD("encoded_mtime","uint8[12]",136,12,SX_NONE),
 SX_FIELD("encoded_checksum","uint8[8]",148,8,SX_NONE),
 SX_FIELD("encoded_typeflag","uint8[1]",156,1,SX_NONE),
 SX_FIELD("encoded_linkname","uint8[100]",157,100,SX_NONE),
};
static const sx_layout sxarfinal_tarx1_encrypted_tar_core={UINT32_C(0x6092020c),"tarx1_encrypted_tar_core",sxarfinal_tarx1_encrypted_tar_core_fields,SX_COUNT(sxarfinal_tarx1_encrypted_tar_core_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_paq8l_stored_header_fields[]={
 SX_FIELD("revision","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("space","uint8",5,1,SX_NONE),
 SX_FIELD("option_prefix","uint8",6,1,SX_NONE),
 SX_FIELD("compression_level","ascii_decimal[1]",7,1,SX_NONE),
 SX_FIELD("line_ending","uint8[2]",8,2,SX_NONE),
};
static const sx_layout sxarfinal_paq8l_stored_header={UINT32_C(0x6092020d),"paq8l_stored_header",sxarfinal_paq8l_stored_header_fields,SX_COUNT(sxarfinal_paq8l_stored_header_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_paq8_member_size_fields[]={
 SX_FIELD("uncompressed_size","ascii_decimal",0,0,SX_SIZE),
};
static const sx_layout sxarfinal_paq8_member_size={UINT32_C(0x6092020e),"paq8_member_size",sxarfinal_paq8_member_size_fields,SX_COUNT(sxarfinal_paq8_member_size_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_paq8_member_name_fields[]={
 SX_FIELD("name","char",0,0,SX_NONE),
};
static const sx_layout sxarfinal_paq8_member_name={UINT32_C(0x6092020f),"paq8_member_name",sxarfinal_paq8_member_name_fields,SX_COUNT(sxarfinal_paq8_member_name_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_paq8_tab_fields[]={
 SX_FIELD("tab","uint8",0,1,SX_NONE),
};
static const sx_layout sxarfinal_paq8_tab={UINT32_C(0x60920210),"paq8_tab",sxarfinal_paq8_tab_fields,SX_COUNT(sxarfinal_paq8_tab_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_paq8_line_ending_fields[]={
 SX_FIELD("line_ending","uint8[2]",0,2,SX_NONE),
};
static const sx_layout sxarfinal_paq8_line_ending={UINT32_C(0x60920211),"paq8_line_ending",sxarfinal_paq8_line_ending_fields,SX_COUNT(sxarfinal_paq8_line_ending_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_paq8_directory_end_fields[]={
 SX_FIELD("directory_terminator","uint8",0,1,SX_NONE),
};
static const sx_layout sxarfinal_paq8_directory_end={UINT32_C(0x60920212),"paq8_directory_end",sxarfinal_paq8_directory_end_fields,SX_COUNT(sxarfinal_paq8_directory_end_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_paq8l_stored_frame_fields[]={
 SX_FIELD("preprocessor_type","uint8",0,1,SX_ID),
 SX_FIELD("uncompressed_bytes","int32",1,4,SX_SIZE),
};
static const sx_layout sxarfinal_paq8l_stored_frame={UINT32_C(0x60920213),"paq8l_stored_frame",sxarfinal_paq8l_stored_frame_fields,SX_COUNT(sxarfinal_paq8l_stored_frame_fields),SX_BE};
static const xx_data_struct_field_desc sxarfinal_grzip_stream_header_fields[]={
 SX_FIELD("signature","uint8[12]",0,12,SX_SIGNATURE),
};
static const sx_layout sxarfinal_grzip_stream_header={UINT32_C(0x60920214),"grzip_stream_header",sxarfinal_grzip_stream_header_fields,SX_COUNT(sxarfinal_grzip_stream_header_fields),SX_LE};
static const xx_data_struct_field_desc sxarfinal_grzip_block_header_fields[]={
 SX_FIELD("uncompressed_size","int32",0,4,SX_SIZE),
 SX_FIELD("compression_mode","int32",4,4,SX_FLAGS),
 SX_FIELD("mode_parameter","int32",8,4,SX_NONE),
 SX_FIELD("transform_parameter","int32",12,4,SX_NONE),
 SX_FIELD("stored_size","int32",16,4,SX_SIZE),
 SX_FIELD("payload_crc32","uint32",20,4,SX_CHECKSUM),
 SX_FIELD("header_crc32","uint32",24,4,SX_CHECKSUM),
};
static const sx_layout sxarfinal_grzip_block_header={UINT32_C(0x60920215),"grzip_block_header",sxarfinal_grzip_block_header_fields,SX_COUNT(sxarfinal_grzip_block_header_fields),SX_LE};
static const sx_layout *const sxarfinal_set_unixcompact_code1[]={&sxarfinal_unixcompact_code1_bit0,&sxarfinal_unixcompact_code1_bit1,&sxarfinal_unixcompact_code1_bit2,&sxarfinal_unixcompact_code1_bit3,&sxarfinal_unixcompact_code1_bit4,&sxarfinal_unixcompact_code1_bit5,&sxarfinal_unixcompact_code1_bit6,&sxarfinal_unixcompact_code1_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code2[]={&sxarfinal_unixcompact_code2_bit0,&sxarfinal_unixcompact_code2_bit1,&sxarfinal_unixcompact_code2_bit2,&sxarfinal_unixcompact_code2_bit3,&sxarfinal_unixcompact_code2_bit4,&sxarfinal_unixcompact_code2_bit5,&sxarfinal_unixcompact_code2_bit6,&sxarfinal_unixcompact_code2_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code3[]={&sxarfinal_unixcompact_code3_bit0,&sxarfinal_unixcompact_code3_bit1,&sxarfinal_unixcompact_code3_bit2,&sxarfinal_unixcompact_code3_bit3,&sxarfinal_unixcompact_code3_bit4,&sxarfinal_unixcompact_code3_bit5,&sxarfinal_unixcompact_code3_bit6,&sxarfinal_unixcompact_code3_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code4[]={&sxarfinal_unixcompact_code4_bit0,&sxarfinal_unixcompact_code4_bit1,&sxarfinal_unixcompact_code4_bit2,&sxarfinal_unixcompact_code4_bit3,&sxarfinal_unixcompact_code4_bit4,&sxarfinal_unixcompact_code4_bit5,&sxarfinal_unixcompact_code4_bit6,&sxarfinal_unixcompact_code4_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code5[]={&sxarfinal_unixcompact_code5_bit0,&sxarfinal_unixcompact_code5_bit1,&sxarfinal_unixcompact_code5_bit2,&sxarfinal_unixcompact_code5_bit3,&sxarfinal_unixcompact_code5_bit4,&sxarfinal_unixcompact_code5_bit5,&sxarfinal_unixcompact_code5_bit6,&sxarfinal_unixcompact_code5_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code6[]={&sxarfinal_unixcompact_code6_bit0,&sxarfinal_unixcompact_code6_bit1,&sxarfinal_unixcompact_code6_bit2,&sxarfinal_unixcompact_code6_bit3,&sxarfinal_unixcompact_code6_bit4,&sxarfinal_unixcompact_code6_bit5,&sxarfinal_unixcompact_code6_bit6,&sxarfinal_unixcompact_code6_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code7[]={&sxarfinal_unixcompact_code7_bit0,&sxarfinal_unixcompact_code7_bit1,&sxarfinal_unixcompact_code7_bit2,&sxarfinal_unixcompact_code7_bit3,&sxarfinal_unixcompact_code7_bit4,&sxarfinal_unixcompact_code7_bit5,&sxarfinal_unixcompact_code7_bit6,&sxarfinal_unixcompact_code7_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code8[]={&sxarfinal_unixcompact_code8_bit0,&sxarfinal_unixcompact_code8_bit1,&sxarfinal_unixcompact_code8_bit2,&sxarfinal_unixcompact_code8_bit3,&sxarfinal_unixcompact_code8_bit4,&sxarfinal_unixcompact_code8_bit5,&sxarfinal_unixcompact_code8_bit6,&sxarfinal_unixcompact_code8_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code9[]={&sxarfinal_unixcompact_code9_bit0,&sxarfinal_unixcompact_code9_bit1,&sxarfinal_unixcompact_code9_bit2,&sxarfinal_unixcompact_code9_bit3,&sxarfinal_unixcompact_code9_bit4,&sxarfinal_unixcompact_code9_bit5,&sxarfinal_unixcompact_code9_bit6,&sxarfinal_unixcompact_code9_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code10[]={&sxarfinal_unixcompact_code10_bit0,&sxarfinal_unixcompact_code10_bit1,&sxarfinal_unixcompact_code10_bit2,&sxarfinal_unixcompact_code10_bit3,&sxarfinal_unixcompact_code10_bit4,&sxarfinal_unixcompact_code10_bit5,&sxarfinal_unixcompact_code10_bit6,&sxarfinal_unixcompact_code10_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code11[]={&sxarfinal_unixcompact_code11_bit0,&sxarfinal_unixcompact_code11_bit1,&sxarfinal_unixcompact_code11_bit2,&sxarfinal_unixcompact_code11_bit3,&sxarfinal_unixcompact_code11_bit4,&sxarfinal_unixcompact_code11_bit5,&sxarfinal_unixcompact_code11_bit6,&sxarfinal_unixcompact_code11_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code12[]={&sxarfinal_unixcompact_code12_bit0,&sxarfinal_unixcompact_code12_bit1,&sxarfinal_unixcompact_code12_bit2,&sxarfinal_unixcompact_code12_bit3,&sxarfinal_unixcompact_code12_bit4,&sxarfinal_unixcompact_code12_bit5,&sxarfinal_unixcompact_code12_bit6,&sxarfinal_unixcompact_code12_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code13[]={&sxarfinal_unixcompact_code13_bit0,&sxarfinal_unixcompact_code13_bit1,&sxarfinal_unixcompact_code13_bit2,&sxarfinal_unixcompact_code13_bit3,&sxarfinal_unixcompact_code13_bit4,&sxarfinal_unixcompact_code13_bit5,&sxarfinal_unixcompact_code13_bit6,&sxarfinal_unixcompact_code13_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code14[]={&sxarfinal_unixcompact_code14_bit0,&sxarfinal_unixcompact_code14_bit1,&sxarfinal_unixcompact_code14_bit2,&sxarfinal_unixcompact_code14_bit3,&sxarfinal_unixcompact_code14_bit4,&sxarfinal_unixcompact_code14_bit5,&sxarfinal_unixcompact_code14_bit6,&sxarfinal_unixcompact_code14_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code15[]={&sxarfinal_unixcompact_code15_bit0,&sxarfinal_unixcompact_code15_bit1,&sxarfinal_unixcompact_code15_bit2,&sxarfinal_unixcompact_code15_bit3,&sxarfinal_unixcompact_code15_bit4,&sxarfinal_unixcompact_code15_bit5,&sxarfinal_unixcompact_code15_bit6,&sxarfinal_unixcompact_code15_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code16[]={&sxarfinal_unixcompact_code16_bit0,&sxarfinal_unixcompact_code16_bit1,&sxarfinal_unixcompact_code16_bit2,&sxarfinal_unixcompact_code16_bit3,&sxarfinal_unixcompact_code16_bit4,&sxarfinal_unixcompact_code16_bit5,&sxarfinal_unixcompact_code16_bit6,&sxarfinal_unixcompact_code16_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code17[]={&sxarfinal_unixcompact_code17_bit0,&sxarfinal_unixcompact_code17_bit1,&sxarfinal_unixcompact_code17_bit2,&sxarfinal_unixcompact_code17_bit3,&sxarfinal_unixcompact_code17_bit4,&sxarfinal_unixcompact_code17_bit5,&sxarfinal_unixcompact_code17_bit6,&sxarfinal_unixcompact_code17_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code18[]={&sxarfinal_unixcompact_code18_bit0,&sxarfinal_unixcompact_code18_bit1,&sxarfinal_unixcompact_code18_bit2,&sxarfinal_unixcompact_code18_bit3,&sxarfinal_unixcompact_code18_bit4,&sxarfinal_unixcompact_code18_bit5,&sxarfinal_unixcompact_code18_bit6,&sxarfinal_unixcompact_code18_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code19[]={&sxarfinal_unixcompact_code19_bit0,&sxarfinal_unixcompact_code19_bit1,&sxarfinal_unixcompact_code19_bit2,&sxarfinal_unixcompact_code19_bit3,&sxarfinal_unixcompact_code19_bit4,&sxarfinal_unixcompact_code19_bit5,&sxarfinal_unixcompact_code19_bit6,&sxarfinal_unixcompact_code19_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code20[]={&sxarfinal_unixcompact_code20_bit0,&sxarfinal_unixcompact_code20_bit1,&sxarfinal_unixcompact_code20_bit2,&sxarfinal_unixcompact_code20_bit3,&sxarfinal_unixcompact_code20_bit4,&sxarfinal_unixcompact_code20_bit5,&sxarfinal_unixcompact_code20_bit6,&sxarfinal_unixcompact_code20_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code21[]={&sxarfinal_unixcompact_code21_bit0,&sxarfinal_unixcompact_code21_bit1,&sxarfinal_unixcompact_code21_bit2,&sxarfinal_unixcompact_code21_bit3,&sxarfinal_unixcompact_code21_bit4,&sxarfinal_unixcompact_code21_bit5,&sxarfinal_unixcompact_code21_bit6,&sxarfinal_unixcompact_code21_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code22[]={&sxarfinal_unixcompact_code22_bit0,&sxarfinal_unixcompact_code22_bit1,&sxarfinal_unixcompact_code22_bit2,&sxarfinal_unixcompact_code22_bit3,&sxarfinal_unixcompact_code22_bit4,&sxarfinal_unixcompact_code22_bit5,&sxarfinal_unixcompact_code22_bit6,&sxarfinal_unixcompact_code22_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code23[]={&sxarfinal_unixcompact_code23_bit0,&sxarfinal_unixcompact_code23_bit1,&sxarfinal_unixcompact_code23_bit2,&sxarfinal_unixcompact_code23_bit3,&sxarfinal_unixcompact_code23_bit4,&sxarfinal_unixcompact_code23_bit5,&sxarfinal_unixcompact_code23_bit6,&sxarfinal_unixcompact_code23_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code24[]={&sxarfinal_unixcompact_code24_bit0,&sxarfinal_unixcompact_code24_bit1,&sxarfinal_unixcompact_code24_bit2,&sxarfinal_unixcompact_code24_bit3,&sxarfinal_unixcompact_code24_bit4,&sxarfinal_unixcompact_code24_bit5,&sxarfinal_unixcompact_code24_bit6,&sxarfinal_unixcompact_code24_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code25[]={&sxarfinal_unixcompact_code25_bit0,&sxarfinal_unixcompact_code25_bit1,&sxarfinal_unixcompact_code25_bit2,&sxarfinal_unixcompact_code25_bit3,&sxarfinal_unixcompact_code25_bit4,&sxarfinal_unixcompact_code25_bit5,&sxarfinal_unixcompact_code25_bit6,&sxarfinal_unixcompact_code25_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code26[]={&sxarfinal_unixcompact_code26_bit0,&sxarfinal_unixcompact_code26_bit1,&sxarfinal_unixcompact_code26_bit2,&sxarfinal_unixcompact_code26_bit3,&sxarfinal_unixcompact_code26_bit4,&sxarfinal_unixcompact_code26_bit5,&sxarfinal_unixcompact_code26_bit6,&sxarfinal_unixcompact_code26_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code27[]={&sxarfinal_unixcompact_code27_bit0,&sxarfinal_unixcompact_code27_bit1,&sxarfinal_unixcompact_code27_bit2,&sxarfinal_unixcompact_code27_bit3,&sxarfinal_unixcompact_code27_bit4,&sxarfinal_unixcompact_code27_bit5,&sxarfinal_unixcompact_code27_bit6,&sxarfinal_unixcompact_code27_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code28[]={&sxarfinal_unixcompact_code28_bit0,&sxarfinal_unixcompact_code28_bit1,&sxarfinal_unixcompact_code28_bit2,&sxarfinal_unixcompact_code28_bit3,&sxarfinal_unixcompact_code28_bit4,&sxarfinal_unixcompact_code28_bit5,&sxarfinal_unixcompact_code28_bit6,&sxarfinal_unixcompact_code28_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code29[]={&sxarfinal_unixcompact_code29_bit0,&sxarfinal_unixcompact_code29_bit1,&sxarfinal_unixcompact_code29_bit2,&sxarfinal_unixcompact_code29_bit3,&sxarfinal_unixcompact_code29_bit4,&sxarfinal_unixcompact_code29_bit5,&sxarfinal_unixcompact_code29_bit6,&sxarfinal_unixcompact_code29_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code30[]={&sxarfinal_unixcompact_code30_bit0,&sxarfinal_unixcompact_code30_bit1,&sxarfinal_unixcompact_code30_bit2,&sxarfinal_unixcompact_code30_bit3,&sxarfinal_unixcompact_code30_bit4,&sxarfinal_unixcompact_code30_bit5,&sxarfinal_unixcompact_code30_bit6,&sxarfinal_unixcompact_code30_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code31[]={&sxarfinal_unixcompact_code31_bit0,&sxarfinal_unixcompact_code31_bit1,&sxarfinal_unixcompact_code31_bit2,&sxarfinal_unixcompact_code31_bit3,&sxarfinal_unixcompact_code31_bit4,&sxarfinal_unixcompact_code31_bit5,&sxarfinal_unixcompact_code31_bit6,&sxarfinal_unixcompact_code31_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code32[]={&sxarfinal_unixcompact_code32_bit0,&sxarfinal_unixcompact_code32_bit1,&sxarfinal_unixcompact_code32_bit2,&sxarfinal_unixcompact_code32_bit3,&sxarfinal_unixcompact_code32_bit4,&sxarfinal_unixcompact_code32_bit5,&sxarfinal_unixcompact_code32_bit6,&sxarfinal_unixcompact_code32_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code33[]={&sxarfinal_unixcompact_code33_bit0,&sxarfinal_unixcompact_code33_bit1,&sxarfinal_unixcompact_code33_bit2,&sxarfinal_unixcompact_code33_bit3,&sxarfinal_unixcompact_code33_bit4,&sxarfinal_unixcompact_code33_bit5,&sxarfinal_unixcompact_code33_bit6,&sxarfinal_unixcompact_code33_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code34[]={&sxarfinal_unixcompact_code34_bit0,&sxarfinal_unixcompact_code34_bit1,&sxarfinal_unixcompact_code34_bit2,&sxarfinal_unixcompact_code34_bit3,&sxarfinal_unixcompact_code34_bit4,&sxarfinal_unixcompact_code34_bit5,&sxarfinal_unixcompact_code34_bit6,&sxarfinal_unixcompact_code34_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code35[]={&sxarfinal_unixcompact_code35_bit0,&sxarfinal_unixcompact_code35_bit1,&sxarfinal_unixcompact_code35_bit2,&sxarfinal_unixcompact_code35_bit3,&sxarfinal_unixcompact_code35_bit4,&sxarfinal_unixcompact_code35_bit5,&sxarfinal_unixcompact_code35_bit6,&sxarfinal_unixcompact_code35_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code36[]={&sxarfinal_unixcompact_code36_bit0,&sxarfinal_unixcompact_code36_bit1,&sxarfinal_unixcompact_code36_bit2,&sxarfinal_unixcompact_code36_bit3,&sxarfinal_unixcompact_code36_bit4,&sxarfinal_unixcompact_code36_bit5,&sxarfinal_unixcompact_code36_bit6,&sxarfinal_unixcompact_code36_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code37[]={&sxarfinal_unixcompact_code37_bit0,&sxarfinal_unixcompact_code37_bit1,&sxarfinal_unixcompact_code37_bit2,&sxarfinal_unixcompact_code37_bit3,&sxarfinal_unixcompact_code37_bit4,&sxarfinal_unixcompact_code37_bit5,&sxarfinal_unixcompact_code37_bit6,&sxarfinal_unixcompact_code37_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code38[]={&sxarfinal_unixcompact_code38_bit0,&sxarfinal_unixcompact_code38_bit1,&sxarfinal_unixcompact_code38_bit2,&sxarfinal_unixcompact_code38_bit3,&sxarfinal_unixcompact_code38_bit4,&sxarfinal_unixcompact_code38_bit5,&sxarfinal_unixcompact_code38_bit6,&sxarfinal_unixcompact_code38_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code39[]={&sxarfinal_unixcompact_code39_bit0,&sxarfinal_unixcompact_code39_bit1,&sxarfinal_unixcompact_code39_bit2,&sxarfinal_unixcompact_code39_bit3,&sxarfinal_unixcompact_code39_bit4,&sxarfinal_unixcompact_code39_bit5,&sxarfinal_unixcompact_code39_bit6,&sxarfinal_unixcompact_code39_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code40[]={&sxarfinal_unixcompact_code40_bit0,&sxarfinal_unixcompact_code40_bit1,&sxarfinal_unixcompact_code40_bit2,&sxarfinal_unixcompact_code40_bit3,&sxarfinal_unixcompact_code40_bit4,&sxarfinal_unixcompact_code40_bit5,&sxarfinal_unixcompact_code40_bit6,&sxarfinal_unixcompact_code40_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code41[]={&sxarfinal_unixcompact_code41_bit0,&sxarfinal_unixcompact_code41_bit1,&sxarfinal_unixcompact_code41_bit2,&sxarfinal_unixcompact_code41_bit3,&sxarfinal_unixcompact_code41_bit4,&sxarfinal_unixcompact_code41_bit5,&sxarfinal_unixcompact_code41_bit6,&sxarfinal_unixcompact_code41_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code42[]={&sxarfinal_unixcompact_code42_bit0,&sxarfinal_unixcompact_code42_bit1,&sxarfinal_unixcompact_code42_bit2,&sxarfinal_unixcompact_code42_bit3,&sxarfinal_unixcompact_code42_bit4,&sxarfinal_unixcompact_code42_bit5,&sxarfinal_unixcompact_code42_bit6,&sxarfinal_unixcompact_code42_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code43[]={&sxarfinal_unixcompact_code43_bit0,&sxarfinal_unixcompact_code43_bit1,&sxarfinal_unixcompact_code43_bit2,&sxarfinal_unixcompact_code43_bit3,&sxarfinal_unixcompact_code43_bit4,&sxarfinal_unixcompact_code43_bit5,&sxarfinal_unixcompact_code43_bit6,&sxarfinal_unixcompact_code43_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code44[]={&sxarfinal_unixcompact_code44_bit0,&sxarfinal_unixcompact_code44_bit1,&sxarfinal_unixcompact_code44_bit2,&sxarfinal_unixcompact_code44_bit3,&sxarfinal_unixcompact_code44_bit4,&sxarfinal_unixcompact_code44_bit5,&sxarfinal_unixcompact_code44_bit6,&sxarfinal_unixcompact_code44_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code45[]={&sxarfinal_unixcompact_code45_bit0,&sxarfinal_unixcompact_code45_bit1,&sxarfinal_unixcompact_code45_bit2,&sxarfinal_unixcompact_code45_bit3,&sxarfinal_unixcompact_code45_bit4,&sxarfinal_unixcompact_code45_bit5,&sxarfinal_unixcompact_code45_bit6,&sxarfinal_unixcompact_code45_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code46[]={&sxarfinal_unixcompact_code46_bit0,&sxarfinal_unixcompact_code46_bit1,&sxarfinal_unixcompact_code46_bit2,&sxarfinal_unixcompact_code46_bit3,&sxarfinal_unixcompact_code46_bit4,&sxarfinal_unixcompact_code46_bit5,&sxarfinal_unixcompact_code46_bit6,&sxarfinal_unixcompact_code46_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code47[]={&sxarfinal_unixcompact_code47_bit0,&sxarfinal_unixcompact_code47_bit1,&sxarfinal_unixcompact_code47_bit2,&sxarfinal_unixcompact_code47_bit3,&sxarfinal_unixcompact_code47_bit4,&sxarfinal_unixcompact_code47_bit5,&sxarfinal_unixcompact_code47_bit6,&sxarfinal_unixcompact_code47_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code48[]={&sxarfinal_unixcompact_code48_bit0,&sxarfinal_unixcompact_code48_bit1,&sxarfinal_unixcompact_code48_bit2,&sxarfinal_unixcompact_code48_bit3,&sxarfinal_unixcompact_code48_bit4,&sxarfinal_unixcompact_code48_bit5,&sxarfinal_unixcompact_code48_bit6,&sxarfinal_unixcompact_code48_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code49[]={&sxarfinal_unixcompact_code49_bit0,&sxarfinal_unixcompact_code49_bit1,&sxarfinal_unixcompact_code49_bit2,&sxarfinal_unixcompact_code49_bit3,&sxarfinal_unixcompact_code49_bit4,&sxarfinal_unixcompact_code49_bit5,&sxarfinal_unixcompact_code49_bit6,&sxarfinal_unixcompact_code49_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code50[]={&sxarfinal_unixcompact_code50_bit0,&sxarfinal_unixcompact_code50_bit1,&sxarfinal_unixcompact_code50_bit2,&sxarfinal_unixcompact_code50_bit3,&sxarfinal_unixcompact_code50_bit4,&sxarfinal_unixcompact_code50_bit5,&sxarfinal_unixcompact_code50_bit6,&sxarfinal_unixcompact_code50_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code51[]={&sxarfinal_unixcompact_code51_bit0,&sxarfinal_unixcompact_code51_bit1,&sxarfinal_unixcompact_code51_bit2,&sxarfinal_unixcompact_code51_bit3,&sxarfinal_unixcompact_code51_bit4,&sxarfinal_unixcompact_code51_bit5,&sxarfinal_unixcompact_code51_bit6,&sxarfinal_unixcompact_code51_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code52[]={&sxarfinal_unixcompact_code52_bit0,&sxarfinal_unixcompact_code52_bit1,&sxarfinal_unixcompact_code52_bit2,&sxarfinal_unixcompact_code52_bit3,&sxarfinal_unixcompact_code52_bit4,&sxarfinal_unixcompact_code52_bit5,&sxarfinal_unixcompact_code52_bit6,&sxarfinal_unixcompact_code52_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code53[]={&sxarfinal_unixcompact_code53_bit0,&sxarfinal_unixcompact_code53_bit1,&sxarfinal_unixcompact_code53_bit2,&sxarfinal_unixcompact_code53_bit3,&sxarfinal_unixcompact_code53_bit4,&sxarfinal_unixcompact_code53_bit5,&sxarfinal_unixcompact_code53_bit6,&sxarfinal_unixcompact_code53_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code54[]={&sxarfinal_unixcompact_code54_bit0,&sxarfinal_unixcompact_code54_bit1,&sxarfinal_unixcompact_code54_bit2,&sxarfinal_unixcompact_code54_bit3,&sxarfinal_unixcompact_code54_bit4,&sxarfinal_unixcompact_code54_bit5,&sxarfinal_unixcompact_code54_bit6,&sxarfinal_unixcompact_code54_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code55[]={&sxarfinal_unixcompact_code55_bit0,&sxarfinal_unixcompact_code55_bit1,&sxarfinal_unixcompact_code55_bit2,&sxarfinal_unixcompact_code55_bit3,&sxarfinal_unixcompact_code55_bit4,&sxarfinal_unixcompact_code55_bit5,&sxarfinal_unixcompact_code55_bit6,&sxarfinal_unixcompact_code55_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code56[]={&sxarfinal_unixcompact_code56_bit0,&sxarfinal_unixcompact_code56_bit1,&sxarfinal_unixcompact_code56_bit2,&sxarfinal_unixcompact_code56_bit3,&sxarfinal_unixcompact_code56_bit4,&sxarfinal_unixcompact_code56_bit5,&sxarfinal_unixcompact_code56_bit6,&sxarfinal_unixcompact_code56_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code57[]={&sxarfinal_unixcompact_code57_bit0,&sxarfinal_unixcompact_code57_bit1,&sxarfinal_unixcompact_code57_bit2,&sxarfinal_unixcompact_code57_bit3,&sxarfinal_unixcompact_code57_bit4,&sxarfinal_unixcompact_code57_bit5,&sxarfinal_unixcompact_code57_bit6,&sxarfinal_unixcompact_code57_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code58[]={&sxarfinal_unixcompact_code58_bit0,&sxarfinal_unixcompact_code58_bit1,&sxarfinal_unixcompact_code58_bit2,&sxarfinal_unixcompact_code58_bit3,&sxarfinal_unixcompact_code58_bit4,&sxarfinal_unixcompact_code58_bit5,&sxarfinal_unixcompact_code58_bit6,&sxarfinal_unixcompact_code58_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code59[]={&sxarfinal_unixcompact_code59_bit0,&sxarfinal_unixcompact_code59_bit1,&sxarfinal_unixcompact_code59_bit2,&sxarfinal_unixcompact_code59_bit3,&sxarfinal_unixcompact_code59_bit4,&sxarfinal_unixcompact_code59_bit5,&sxarfinal_unixcompact_code59_bit6,&sxarfinal_unixcompact_code59_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code60[]={&sxarfinal_unixcompact_code60_bit0,&sxarfinal_unixcompact_code60_bit1,&sxarfinal_unixcompact_code60_bit2,&sxarfinal_unixcompact_code60_bit3,&sxarfinal_unixcompact_code60_bit4,&sxarfinal_unixcompact_code60_bit5,&sxarfinal_unixcompact_code60_bit6,&sxarfinal_unixcompact_code60_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code61[]={&sxarfinal_unixcompact_code61_bit0,&sxarfinal_unixcompact_code61_bit1,&sxarfinal_unixcompact_code61_bit2,&sxarfinal_unixcompact_code61_bit3,&sxarfinal_unixcompact_code61_bit4,&sxarfinal_unixcompact_code61_bit5,&sxarfinal_unixcompact_code61_bit6,&sxarfinal_unixcompact_code61_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code62[]={&sxarfinal_unixcompact_code62_bit0,&sxarfinal_unixcompact_code62_bit1,&sxarfinal_unixcompact_code62_bit2,&sxarfinal_unixcompact_code62_bit3,&sxarfinal_unixcompact_code62_bit4,&sxarfinal_unixcompact_code62_bit5,&sxarfinal_unixcompact_code62_bit6,&sxarfinal_unixcompact_code62_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code63[]={&sxarfinal_unixcompact_code63_bit0,&sxarfinal_unixcompact_code63_bit1,&sxarfinal_unixcompact_code63_bit2,&sxarfinal_unixcompact_code63_bit3,&sxarfinal_unixcompact_code63_bit4,&sxarfinal_unixcompact_code63_bit5,&sxarfinal_unixcompact_code63_bit6,&sxarfinal_unixcompact_code63_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_code64[]={&sxarfinal_unixcompact_code64_bit0,&sxarfinal_unixcompact_code64_bit1,&sxarfinal_unixcompact_code64_bit2,&sxarfinal_unixcompact_code64_bit3,&sxarfinal_unixcompact_code64_bit4,&sxarfinal_unixcompact_code64_bit5,&sxarfinal_unixcompact_code64_bit6,&sxarfinal_unixcompact_code64_bit7};
static const sx_layout *const sxarfinal_set_unixcompact_new_literal[]={&sxarfinal_unixcompact_new_literal_bit0,&sxarfinal_unixcompact_new_literal_bit1,&sxarfinal_unixcompact_new_literal_bit2,&sxarfinal_unixcompact_new_literal_bit3,&sxarfinal_unixcompact_new_literal_bit4,&sxarfinal_unixcompact_new_literal_bit5,&sxarfinal_unixcompact_new_literal_bit6,&sxarfinal_unixcompact_new_literal_bit7};
static const sx_layout *const sx_archiveresidual_layouts[]={
 &sxarfinal_pcsecure_physical_header,
 &sxarfinal_unixcompact_prefix,
 &sxarfinal_unixcompact_code1_bit0,
 &sxarfinal_unixcompact_code1_bit1,
 &sxarfinal_unixcompact_code1_bit2,
 &sxarfinal_unixcompact_code1_bit3,
 &sxarfinal_unixcompact_code1_bit4,
 &sxarfinal_unixcompact_code1_bit5,
 &sxarfinal_unixcompact_code1_bit6,
 &sxarfinal_unixcompact_code1_bit7,
 &sxarfinal_unixcompact_code2_bit0,
 &sxarfinal_unixcompact_code2_bit1,
 &sxarfinal_unixcompact_code2_bit2,
 &sxarfinal_unixcompact_code2_bit3,
 &sxarfinal_unixcompact_code2_bit4,
 &sxarfinal_unixcompact_code2_bit5,
 &sxarfinal_unixcompact_code2_bit6,
 &sxarfinal_unixcompact_code2_bit7,
 &sxarfinal_unixcompact_code3_bit0,
 &sxarfinal_unixcompact_code3_bit1,
 &sxarfinal_unixcompact_code3_bit2,
 &sxarfinal_unixcompact_code3_bit3,
 &sxarfinal_unixcompact_code3_bit4,
 &sxarfinal_unixcompact_code3_bit5,
 &sxarfinal_unixcompact_code3_bit6,
 &sxarfinal_unixcompact_code3_bit7,
 &sxarfinal_unixcompact_code4_bit0,
 &sxarfinal_unixcompact_code4_bit1,
 &sxarfinal_unixcompact_code4_bit2,
 &sxarfinal_unixcompact_code4_bit3,
 &sxarfinal_unixcompact_code4_bit4,
 &sxarfinal_unixcompact_code4_bit5,
 &sxarfinal_unixcompact_code4_bit6,
 &sxarfinal_unixcompact_code4_bit7,
 &sxarfinal_unixcompact_code5_bit0,
 &sxarfinal_unixcompact_code5_bit1,
 &sxarfinal_unixcompact_code5_bit2,
 &sxarfinal_unixcompact_code5_bit3,
 &sxarfinal_unixcompact_code5_bit4,
 &sxarfinal_unixcompact_code5_bit5,
 &sxarfinal_unixcompact_code5_bit6,
 &sxarfinal_unixcompact_code5_bit7,
 &sxarfinal_unixcompact_code6_bit0,
 &sxarfinal_unixcompact_code6_bit1,
 &sxarfinal_unixcompact_code6_bit2,
 &sxarfinal_unixcompact_code6_bit3,
 &sxarfinal_unixcompact_code6_bit4,
 &sxarfinal_unixcompact_code6_bit5,
 &sxarfinal_unixcompact_code6_bit6,
 &sxarfinal_unixcompact_code6_bit7,
 &sxarfinal_unixcompact_code7_bit0,
 &sxarfinal_unixcompact_code7_bit1,
 &sxarfinal_unixcompact_code7_bit2,
 &sxarfinal_unixcompact_code7_bit3,
 &sxarfinal_unixcompact_code7_bit4,
 &sxarfinal_unixcompact_code7_bit5,
 &sxarfinal_unixcompact_code7_bit6,
 &sxarfinal_unixcompact_code7_bit7,
 &sxarfinal_unixcompact_code8_bit0,
 &sxarfinal_unixcompact_code8_bit1,
 &sxarfinal_unixcompact_code8_bit2,
 &sxarfinal_unixcompact_code8_bit3,
 &sxarfinal_unixcompact_code8_bit4,
 &sxarfinal_unixcompact_code8_bit5,
 &sxarfinal_unixcompact_code8_bit6,
 &sxarfinal_unixcompact_code8_bit7,
 &sxarfinal_unixcompact_code9_bit0,
 &sxarfinal_unixcompact_code9_bit1,
 &sxarfinal_unixcompact_code9_bit2,
 &sxarfinal_unixcompact_code9_bit3,
 &sxarfinal_unixcompact_code9_bit4,
 &sxarfinal_unixcompact_code9_bit5,
 &sxarfinal_unixcompact_code9_bit6,
 &sxarfinal_unixcompact_code9_bit7,
 &sxarfinal_unixcompact_code10_bit0,
 &sxarfinal_unixcompact_code10_bit1,
 &sxarfinal_unixcompact_code10_bit2,
 &sxarfinal_unixcompact_code10_bit3,
 &sxarfinal_unixcompact_code10_bit4,
 &sxarfinal_unixcompact_code10_bit5,
 &sxarfinal_unixcompact_code10_bit6,
 &sxarfinal_unixcompact_code10_bit7,
 &sxarfinal_unixcompact_code11_bit0,
 &sxarfinal_unixcompact_code11_bit1,
 &sxarfinal_unixcompact_code11_bit2,
 &sxarfinal_unixcompact_code11_bit3,
 &sxarfinal_unixcompact_code11_bit4,
 &sxarfinal_unixcompact_code11_bit5,
 &sxarfinal_unixcompact_code11_bit6,
 &sxarfinal_unixcompact_code11_bit7,
 &sxarfinal_unixcompact_code12_bit0,
 &sxarfinal_unixcompact_code12_bit1,
 &sxarfinal_unixcompact_code12_bit2,
 &sxarfinal_unixcompact_code12_bit3,
 &sxarfinal_unixcompact_code12_bit4,
 &sxarfinal_unixcompact_code12_bit5,
 &sxarfinal_unixcompact_code12_bit6,
 &sxarfinal_unixcompact_code12_bit7,
 &sxarfinal_unixcompact_code13_bit0,
 &sxarfinal_unixcompact_code13_bit1,
 &sxarfinal_unixcompact_code13_bit2,
 &sxarfinal_unixcompact_code13_bit3,
 &sxarfinal_unixcompact_code13_bit4,
 &sxarfinal_unixcompact_code13_bit5,
 &sxarfinal_unixcompact_code13_bit6,
 &sxarfinal_unixcompact_code13_bit7,
 &sxarfinal_unixcompact_code14_bit0,
 &sxarfinal_unixcompact_code14_bit1,
 &sxarfinal_unixcompact_code14_bit2,
 &sxarfinal_unixcompact_code14_bit3,
 &sxarfinal_unixcompact_code14_bit4,
 &sxarfinal_unixcompact_code14_bit5,
 &sxarfinal_unixcompact_code14_bit6,
 &sxarfinal_unixcompact_code14_bit7,
 &sxarfinal_unixcompact_code15_bit0,
 &sxarfinal_unixcompact_code15_bit1,
 &sxarfinal_unixcompact_code15_bit2,
 &sxarfinal_unixcompact_code15_bit3,
 &sxarfinal_unixcompact_code15_bit4,
 &sxarfinal_unixcompact_code15_bit5,
 &sxarfinal_unixcompact_code15_bit6,
 &sxarfinal_unixcompact_code15_bit7,
 &sxarfinal_unixcompact_code16_bit0,
 &sxarfinal_unixcompact_code16_bit1,
 &sxarfinal_unixcompact_code16_bit2,
 &sxarfinal_unixcompact_code16_bit3,
 &sxarfinal_unixcompact_code16_bit4,
 &sxarfinal_unixcompact_code16_bit5,
 &sxarfinal_unixcompact_code16_bit6,
 &sxarfinal_unixcompact_code16_bit7,
 &sxarfinal_unixcompact_code17_bit0,
 &sxarfinal_unixcompact_code17_bit1,
 &sxarfinal_unixcompact_code17_bit2,
 &sxarfinal_unixcompact_code17_bit3,
 &sxarfinal_unixcompact_code17_bit4,
 &sxarfinal_unixcompact_code17_bit5,
 &sxarfinal_unixcompact_code17_bit6,
 &sxarfinal_unixcompact_code17_bit7,
 &sxarfinal_unixcompact_code18_bit0,
 &sxarfinal_unixcompact_code18_bit1,
 &sxarfinal_unixcompact_code18_bit2,
 &sxarfinal_unixcompact_code18_bit3,
 &sxarfinal_unixcompact_code18_bit4,
 &sxarfinal_unixcompact_code18_bit5,
 &sxarfinal_unixcompact_code18_bit6,
 &sxarfinal_unixcompact_code18_bit7,
 &sxarfinal_unixcompact_code19_bit0,
 &sxarfinal_unixcompact_code19_bit1,
 &sxarfinal_unixcompact_code19_bit2,
 &sxarfinal_unixcompact_code19_bit3,
 &sxarfinal_unixcompact_code19_bit4,
 &sxarfinal_unixcompact_code19_bit5,
 &sxarfinal_unixcompact_code19_bit6,
 &sxarfinal_unixcompact_code19_bit7,
 &sxarfinal_unixcompact_code20_bit0,
 &sxarfinal_unixcompact_code20_bit1,
 &sxarfinal_unixcompact_code20_bit2,
 &sxarfinal_unixcompact_code20_bit3,
 &sxarfinal_unixcompact_code20_bit4,
 &sxarfinal_unixcompact_code20_bit5,
 &sxarfinal_unixcompact_code20_bit6,
 &sxarfinal_unixcompact_code20_bit7,
 &sxarfinal_unixcompact_code21_bit0,
 &sxarfinal_unixcompact_code21_bit1,
 &sxarfinal_unixcompact_code21_bit2,
 &sxarfinal_unixcompact_code21_bit3,
 &sxarfinal_unixcompact_code21_bit4,
 &sxarfinal_unixcompact_code21_bit5,
 &sxarfinal_unixcompact_code21_bit6,
 &sxarfinal_unixcompact_code21_bit7,
 &sxarfinal_unixcompact_code22_bit0,
 &sxarfinal_unixcompact_code22_bit1,
 &sxarfinal_unixcompact_code22_bit2,
 &sxarfinal_unixcompact_code22_bit3,
 &sxarfinal_unixcompact_code22_bit4,
 &sxarfinal_unixcompact_code22_bit5,
 &sxarfinal_unixcompact_code22_bit6,
 &sxarfinal_unixcompact_code22_bit7,
 &sxarfinal_unixcompact_code23_bit0,
 &sxarfinal_unixcompact_code23_bit1,
 &sxarfinal_unixcompact_code23_bit2,
 &sxarfinal_unixcompact_code23_bit3,
 &sxarfinal_unixcompact_code23_bit4,
 &sxarfinal_unixcompact_code23_bit5,
 &sxarfinal_unixcompact_code23_bit6,
 &sxarfinal_unixcompact_code23_bit7,
 &sxarfinal_unixcompact_code24_bit0,
 &sxarfinal_unixcompact_code24_bit1,
 &sxarfinal_unixcompact_code24_bit2,
 &sxarfinal_unixcompact_code24_bit3,
 &sxarfinal_unixcompact_code24_bit4,
 &sxarfinal_unixcompact_code24_bit5,
 &sxarfinal_unixcompact_code24_bit6,
 &sxarfinal_unixcompact_code24_bit7,
 &sxarfinal_unixcompact_code25_bit0,
 &sxarfinal_unixcompact_code25_bit1,
 &sxarfinal_unixcompact_code25_bit2,
 &sxarfinal_unixcompact_code25_bit3,
 &sxarfinal_unixcompact_code25_bit4,
 &sxarfinal_unixcompact_code25_bit5,
 &sxarfinal_unixcompact_code25_bit6,
 &sxarfinal_unixcompact_code25_bit7,
 &sxarfinal_unixcompact_code26_bit0,
 &sxarfinal_unixcompact_code26_bit1,
 &sxarfinal_unixcompact_code26_bit2,
 &sxarfinal_unixcompact_code26_bit3,
 &sxarfinal_unixcompact_code26_bit4,
 &sxarfinal_unixcompact_code26_bit5,
 &sxarfinal_unixcompact_code26_bit6,
 &sxarfinal_unixcompact_code26_bit7,
 &sxarfinal_unixcompact_code27_bit0,
 &sxarfinal_unixcompact_code27_bit1,
 &sxarfinal_unixcompact_code27_bit2,
 &sxarfinal_unixcompact_code27_bit3,
 &sxarfinal_unixcompact_code27_bit4,
 &sxarfinal_unixcompact_code27_bit5,
 &sxarfinal_unixcompact_code27_bit6,
 &sxarfinal_unixcompact_code27_bit7,
 &sxarfinal_unixcompact_code28_bit0,
 &sxarfinal_unixcompact_code28_bit1,
 &sxarfinal_unixcompact_code28_bit2,
 &sxarfinal_unixcompact_code28_bit3,
 &sxarfinal_unixcompact_code28_bit4,
 &sxarfinal_unixcompact_code28_bit5,
 &sxarfinal_unixcompact_code28_bit6,
 &sxarfinal_unixcompact_code28_bit7,
 &sxarfinal_unixcompact_code29_bit0,
 &sxarfinal_unixcompact_code29_bit1,
 &sxarfinal_unixcompact_code29_bit2,
 &sxarfinal_unixcompact_code29_bit3,
 &sxarfinal_unixcompact_code29_bit4,
 &sxarfinal_unixcompact_code29_bit5,
 &sxarfinal_unixcompact_code29_bit6,
 &sxarfinal_unixcompact_code29_bit7,
 &sxarfinal_unixcompact_code30_bit0,
 &sxarfinal_unixcompact_code30_bit1,
 &sxarfinal_unixcompact_code30_bit2,
 &sxarfinal_unixcompact_code30_bit3,
 &sxarfinal_unixcompact_code30_bit4,
 &sxarfinal_unixcompact_code30_bit5,
 &sxarfinal_unixcompact_code30_bit6,
 &sxarfinal_unixcompact_code30_bit7,
 &sxarfinal_unixcompact_code31_bit0,
 &sxarfinal_unixcompact_code31_bit1,
 &sxarfinal_unixcompact_code31_bit2,
 &sxarfinal_unixcompact_code31_bit3,
 &sxarfinal_unixcompact_code31_bit4,
 &sxarfinal_unixcompact_code31_bit5,
 &sxarfinal_unixcompact_code31_bit6,
 &sxarfinal_unixcompact_code31_bit7,
 &sxarfinal_unixcompact_code32_bit0,
 &sxarfinal_unixcompact_code32_bit1,
 &sxarfinal_unixcompact_code32_bit2,
 &sxarfinal_unixcompact_code32_bit3,
 &sxarfinal_unixcompact_code32_bit4,
 &sxarfinal_unixcompact_code32_bit5,
 &sxarfinal_unixcompact_code32_bit6,
 &sxarfinal_unixcompact_code32_bit7,
 &sxarfinal_unixcompact_code33_bit0,
 &sxarfinal_unixcompact_code33_bit1,
 &sxarfinal_unixcompact_code33_bit2,
 &sxarfinal_unixcompact_code33_bit3,
 &sxarfinal_unixcompact_code33_bit4,
 &sxarfinal_unixcompact_code33_bit5,
 &sxarfinal_unixcompact_code33_bit6,
 &sxarfinal_unixcompact_code33_bit7,
 &sxarfinal_unixcompact_code34_bit0,
 &sxarfinal_unixcompact_code34_bit1,
 &sxarfinal_unixcompact_code34_bit2,
 &sxarfinal_unixcompact_code34_bit3,
 &sxarfinal_unixcompact_code34_bit4,
 &sxarfinal_unixcompact_code34_bit5,
 &sxarfinal_unixcompact_code34_bit6,
 &sxarfinal_unixcompact_code34_bit7,
 &sxarfinal_unixcompact_code35_bit0,
 &sxarfinal_unixcompact_code35_bit1,
 &sxarfinal_unixcompact_code35_bit2,
 &sxarfinal_unixcompact_code35_bit3,
 &sxarfinal_unixcompact_code35_bit4,
 &sxarfinal_unixcompact_code35_bit5,
 &sxarfinal_unixcompact_code35_bit6,
 &sxarfinal_unixcompact_code35_bit7,
 &sxarfinal_unixcompact_code36_bit0,
 &sxarfinal_unixcompact_code36_bit1,
 &sxarfinal_unixcompact_code36_bit2,
 &sxarfinal_unixcompact_code36_bit3,
 &sxarfinal_unixcompact_code36_bit4,
 &sxarfinal_unixcompact_code36_bit5,
 &sxarfinal_unixcompact_code36_bit6,
 &sxarfinal_unixcompact_code36_bit7,
 &sxarfinal_unixcompact_code37_bit0,
 &sxarfinal_unixcompact_code37_bit1,
 &sxarfinal_unixcompact_code37_bit2,
 &sxarfinal_unixcompact_code37_bit3,
 &sxarfinal_unixcompact_code37_bit4,
 &sxarfinal_unixcompact_code37_bit5,
 &sxarfinal_unixcompact_code37_bit6,
 &sxarfinal_unixcompact_code37_bit7,
 &sxarfinal_unixcompact_code38_bit0,
 &sxarfinal_unixcompact_code38_bit1,
 &sxarfinal_unixcompact_code38_bit2,
 &sxarfinal_unixcompact_code38_bit3,
 &sxarfinal_unixcompact_code38_bit4,
 &sxarfinal_unixcompact_code38_bit5,
 &sxarfinal_unixcompact_code38_bit6,
 &sxarfinal_unixcompact_code38_bit7,
 &sxarfinal_unixcompact_code39_bit0,
 &sxarfinal_unixcompact_code39_bit1,
 &sxarfinal_unixcompact_code39_bit2,
 &sxarfinal_unixcompact_code39_bit3,
 &sxarfinal_unixcompact_code39_bit4,
 &sxarfinal_unixcompact_code39_bit5,
 &sxarfinal_unixcompact_code39_bit6,
 &sxarfinal_unixcompact_code39_bit7,
 &sxarfinal_unixcompact_code40_bit0,
 &sxarfinal_unixcompact_code40_bit1,
 &sxarfinal_unixcompact_code40_bit2,
 &sxarfinal_unixcompact_code40_bit3,
 &sxarfinal_unixcompact_code40_bit4,
 &sxarfinal_unixcompact_code40_bit5,
 &sxarfinal_unixcompact_code40_bit6,
 &sxarfinal_unixcompact_code40_bit7,
 &sxarfinal_unixcompact_code41_bit0,
 &sxarfinal_unixcompact_code41_bit1,
 &sxarfinal_unixcompact_code41_bit2,
 &sxarfinal_unixcompact_code41_bit3,
 &sxarfinal_unixcompact_code41_bit4,
 &sxarfinal_unixcompact_code41_bit5,
 &sxarfinal_unixcompact_code41_bit6,
 &sxarfinal_unixcompact_code41_bit7,
 &sxarfinal_unixcompact_code42_bit0,
 &sxarfinal_unixcompact_code42_bit1,
 &sxarfinal_unixcompact_code42_bit2,
 &sxarfinal_unixcompact_code42_bit3,
 &sxarfinal_unixcompact_code42_bit4,
 &sxarfinal_unixcompact_code42_bit5,
 &sxarfinal_unixcompact_code42_bit6,
 &sxarfinal_unixcompact_code42_bit7,
 &sxarfinal_unixcompact_code43_bit0,
 &sxarfinal_unixcompact_code43_bit1,
 &sxarfinal_unixcompact_code43_bit2,
 &sxarfinal_unixcompact_code43_bit3,
 &sxarfinal_unixcompact_code43_bit4,
 &sxarfinal_unixcompact_code43_bit5,
 &sxarfinal_unixcompact_code43_bit6,
 &sxarfinal_unixcompact_code43_bit7,
 &sxarfinal_unixcompact_code44_bit0,
 &sxarfinal_unixcompact_code44_bit1,
 &sxarfinal_unixcompact_code44_bit2,
 &sxarfinal_unixcompact_code44_bit3,
 &sxarfinal_unixcompact_code44_bit4,
 &sxarfinal_unixcompact_code44_bit5,
 &sxarfinal_unixcompact_code44_bit6,
 &sxarfinal_unixcompact_code44_bit7,
 &sxarfinal_unixcompact_code45_bit0,
 &sxarfinal_unixcompact_code45_bit1,
 &sxarfinal_unixcompact_code45_bit2,
 &sxarfinal_unixcompact_code45_bit3,
 &sxarfinal_unixcompact_code45_bit4,
 &sxarfinal_unixcompact_code45_bit5,
 &sxarfinal_unixcompact_code45_bit6,
 &sxarfinal_unixcompact_code45_bit7,
 &sxarfinal_unixcompact_code46_bit0,
 &sxarfinal_unixcompact_code46_bit1,
 &sxarfinal_unixcompact_code46_bit2,
 &sxarfinal_unixcompact_code46_bit3,
 &sxarfinal_unixcompact_code46_bit4,
 &sxarfinal_unixcompact_code46_bit5,
 &sxarfinal_unixcompact_code46_bit6,
 &sxarfinal_unixcompact_code46_bit7,
 &sxarfinal_unixcompact_code47_bit0,
 &sxarfinal_unixcompact_code47_bit1,
 &sxarfinal_unixcompact_code47_bit2,
 &sxarfinal_unixcompact_code47_bit3,
 &sxarfinal_unixcompact_code47_bit4,
 &sxarfinal_unixcompact_code47_bit5,
 &sxarfinal_unixcompact_code47_bit6,
 &sxarfinal_unixcompact_code47_bit7,
 &sxarfinal_unixcompact_code48_bit0,
 &sxarfinal_unixcompact_code48_bit1,
 &sxarfinal_unixcompact_code48_bit2,
 &sxarfinal_unixcompact_code48_bit3,
 &sxarfinal_unixcompact_code48_bit4,
 &sxarfinal_unixcompact_code48_bit5,
 &sxarfinal_unixcompact_code48_bit6,
 &sxarfinal_unixcompact_code48_bit7,
 &sxarfinal_unixcompact_code49_bit0,
 &sxarfinal_unixcompact_code49_bit1,
 &sxarfinal_unixcompact_code49_bit2,
 &sxarfinal_unixcompact_code49_bit3,
 &sxarfinal_unixcompact_code49_bit4,
 &sxarfinal_unixcompact_code49_bit5,
 &sxarfinal_unixcompact_code49_bit6,
 &sxarfinal_unixcompact_code49_bit7,
 &sxarfinal_unixcompact_code50_bit0,
 &sxarfinal_unixcompact_code50_bit1,
 &sxarfinal_unixcompact_code50_bit2,
 &sxarfinal_unixcompact_code50_bit3,
 &sxarfinal_unixcompact_code50_bit4,
 &sxarfinal_unixcompact_code50_bit5,
 &sxarfinal_unixcompact_code50_bit6,
 &sxarfinal_unixcompact_code50_bit7,
 &sxarfinal_unixcompact_code51_bit0,
 &sxarfinal_unixcompact_code51_bit1,
 &sxarfinal_unixcompact_code51_bit2,
 &sxarfinal_unixcompact_code51_bit3,
 &sxarfinal_unixcompact_code51_bit4,
 &sxarfinal_unixcompact_code51_bit5,
 &sxarfinal_unixcompact_code51_bit6,
 &sxarfinal_unixcompact_code51_bit7,
 &sxarfinal_unixcompact_code52_bit0,
 &sxarfinal_unixcompact_code52_bit1,
 &sxarfinal_unixcompact_code52_bit2,
 &sxarfinal_unixcompact_code52_bit3,
 &sxarfinal_unixcompact_code52_bit4,
 &sxarfinal_unixcompact_code52_bit5,
 &sxarfinal_unixcompact_code52_bit6,
 &sxarfinal_unixcompact_code52_bit7,
 &sxarfinal_unixcompact_code53_bit0,
 &sxarfinal_unixcompact_code53_bit1,
 &sxarfinal_unixcompact_code53_bit2,
 &sxarfinal_unixcompact_code53_bit3,
 &sxarfinal_unixcompact_code53_bit4,
 &sxarfinal_unixcompact_code53_bit5,
 &sxarfinal_unixcompact_code53_bit6,
 &sxarfinal_unixcompact_code53_bit7,
 &sxarfinal_unixcompact_code54_bit0,
 &sxarfinal_unixcompact_code54_bit1,
 &sxarfinal_unixcompact_code54_bit2,
 &sxarfinal_unixcompact_code54_bit3,
 &sxarfinal_unixcompact_code54_bit4,
 &sxarfinal_unixcompact_code54_bit5,
 &sxarfinal_unixcompact_code54_bit6,
 &sxarfinal_unixcompact_code54_bit7,
 &sxarfinal_unixcompact_code55_bit0,
 &sxarfinal_unixcompact_code55_bit1,
 &sxarfinal_unixcompact_code55_bit2,
 &sxarfinal_unixcompact_code55_bit3,
 &sxarfinal_unixcompact_code55_bit4,
 &sxarfinal_unixcompact_code55_bit5,
 &sxarfinal_unixcompact_code55_bit6,
 &sxarfinal_unixcompact_code55_bit7,
 &sxarfinal_unixcompact_code56_bit0,
 &sxarfinal_unixcompact_code56_bit1,
 &sxarfinal_unixcompact_code56_bit2,
 &sxarfinal_unixcompact_code56_bit3,
 &sxarfinal_unixcompact_code56_bit4,
 &sxarfinal_unixcompact_code56_bit5,
 &sxarfinal_unixcompact_code56_bit6,
 &sxarfinal_unixcompact_code56_bit7,
 &sxarfinal_unixcompact_code57_bit0,
 &sxarfinal_unixcompact_code57_bit1,
 &sxarfinal_unixcompact_code57_bit2,
 &sxarfinal_unixcompact_code57_bit3,
 &sxarfinal_unixcompact_code57_bit4,
 &sxarfinal_unixcompact_code57_bit5,
 &sxarfinal_unixcompact_code57_bit6,
 &sxarfinal_unixcompact_code57_bit7,
 &sxarfinal_unixcompact_code58_bit0,
 &sxarfinal_unixcompact_code58_bit1,
 &sxarfinal_unixcompact_code58_bit2,
 &sxarfinal_unixcompact_code58_bit3,
 &sxarfinal_unixcompact_code58_bit4,
 &sxarfinal_unixcompact_code58_bit5,
 &sxarfinal_unixcompact_code58_bit6,
 &sxarfinal_unixcompact_code58_bit7,
 &sxarfinal_unixcompact_code59_bit0,
 &sxarfinal_unixcompact_code59_bit1,
 &sxarfinal_unixcompact_code59_bit2,
 &sxarfinal_unixcompact_code59_bit3,
 &sxarfinal_unixcompact_code59_bit4,
 &sxarfinal_unixcompact_code59_bit5,
 &sxarfinal_unixcompact_code59_bit6,
 &sxarfinal_unixcompact_code59_bit7,
 &sxarfinal_unixcompact_code60_bit0,
 &sxarfinal_unixcompact_code60_bit1,
 &sxarfinal_unixcompact_code60_bit2,
 &sxarfinal_unixcompact_code60_bit3,
 &sxarfinal_unixcompact_code60_bit4,
 &sxarfinal_unixcompact_code60_bit5,
 &sxarfinal_unixcompact_code60_bit6,
 &sxarfinal_unixcompact_code60_bit7,
 &sxarfinal_unixcompact_code61_bit0,
 &sxarfinal_unixcompact_code61_bit1,
 &sxarfinal_unixcompact_code61_bit2,
 &sxarfinal_unixcompact_code61_bit3,
 &sxarfinal_unixcompact_code61_bit4,
 &sxarfinal_unixcompact_code61_bit5,
 &sxarfinal_unixcompact_code61_bit6,
 &sxarfinal_unixcompact_code61_bit7,
 &sxarfinal_unixcompact_code62_bit0,
 &sxarfinal_unixcompact_code62_bit1,
 &sxarfinal_unixcompact_code62_bit2,
 &sxarfinal_unixcompact_code62_bit3,
 &sxarfinal_unixcompact_code62_bit4,
 &sxarfinal_unixcompact_code62_bit5,
 &sxarfinal_unixcompact_code62_bit6,
 &sxarfinal_unixcompact_code62_bit7,
 &sxarfinal_unixcompact_code63_bit0,
 &sxarfinal_unixcompact_code63_bit1,
 &sxarfinal_unixcompact_code63_bit2,
 &sxarfinal_unixcompact_code63_bit3,
 &sxarfinal_unixcompact_code63_bit4,
 &sxarfinal_unixcompact_code63_bit5,
 &sxarfinal_unixcompact_code63_bit6,
 &sxarfinal_unixcompact_code63_bit7,
 &sxarfinal_unixcompact_code64_bit0,
 &sxarfinal_unixcompact_code64_bit1,
 &sxarfinal_unixcompact_code64_bit2,
 &sxarfinal_unixcompact_code64_bit3,
 &sxarfinal_unixcompact_code64_bit4,
 &sxarfinal_unixcompact_code64_bit5,
 &sxarfinal_unixcompact_code64_bit6,
 &sxarfinal_unixcompact_code64_bit7,
 &sxarfinal_unixcompact_new_literal_bit0,
 &sxarfinal_unixcompact_new_literal_bit1,
 &sxarfinal_unixcompact_new_literal_bit2,
 &sxarfinal_unixcompact_new_literal_bit3,
 &sxarfinal_unixcompact_new_literal_bit4,
 &sxarfinal_unixcompact_new_literal_bit5,
 &sxarfinal_unixcompact_new_literal_bit6,
 &sxarfinal_unixcompact_new_literal_bit7,
 &sxarfinal_tarx1_transport_prefix,
 &sxarfinal_tarx1_encrypted_tar_core,
 &sxarfinal_paq8l_stored_header,
 &sxarfinal_paq8_member_size,
 &sxarfinal_paq8_member_name,
 &sxarfinal_paq8_tab,
 &sxarfinal_paq8_line_ending,
 &sxarfinal_paq8_directory_end,
 &sxarfinal_paq8l_stored_frame,
 &sxarfinal_grzip_stream_header,
 &sxarfinal_grzip_block_header,
};
static bool sx_archiveresidual_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60920000U||id>=0x60930000U)return true;const wchar_t*text=NULL;switch(id){
 case 0x60920001U:text=L"Signature is clear. Bytes4..59 are seven encrypted DES header blocks and cannot be split into plaintext numeric fields. Nonzero final8 bytes wrap a user file key under a fixed DES key; zero selects built-in key candidates. Stored ciphertext is retained; no password or integrity claim.";break;
 case 0x60920002U:text=L"The first decoded byte is physically stored at offset2 and initializes the adaptive Huffman tree. No stored output length or checksum exists.";break;
 case 0x60920003U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920004U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920005U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920006U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920007U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920008U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920009U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092000aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092000bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092000cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092000dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092000eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092000fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920010U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920011U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920012U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920013U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920014U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920015U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920016U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920017U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920018U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920019U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092001aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092001bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092001cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092001dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092001eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092001fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920020U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920021U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920022U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920023U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920024U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920025U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920026U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920027U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920028U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920029U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092002aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092002bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092002cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092002dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092002eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092002fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920030U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920031U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920032U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920033U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920034U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920035U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920036U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920037U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920038U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920039U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092003aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092003bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092003cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092003dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092003eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092003fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920040U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920041U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920042U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920043U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920044U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920045U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920046U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920047U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920048U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920049U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092004aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092004bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092004cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092004dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092004eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092004fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920050U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920051U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920052U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920053U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920054U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920055U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920056U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920057U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920058U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920059U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092005aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092005bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092005cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092005dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092005eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092005fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920060U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920061U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920062U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920063U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920064U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920065U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920066U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920067U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920068U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920069U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092006aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092006bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092006cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092006dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092006eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092006fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920070U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920071U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920072U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920073U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920074U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920075U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920076U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920077U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920078U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920079U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092007aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092007bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092007cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092007dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092007eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092007fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920080U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920081U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920082U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920083U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920084U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920085U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920086U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920087U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920088U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920089U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092008aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092008bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092008cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092008dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092008eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092008fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920090U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920091U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920092U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920093U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920094U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920095U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920096U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920097U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920098U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920099U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092009aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092009bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092009cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092009dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092009eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092009fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200a9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200aaU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200abU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200acU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200adU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200aeU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200afU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200b9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200baU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200bbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200bcU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200bdU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200beU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200bfU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200c9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200caU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200cbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200ccU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200cdU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200ceU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200cfU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200d9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200daU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200dbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200dcU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200ddU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200deU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200dfU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200e9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200eaU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200ebU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200ecU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200edU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200eeU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200efU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200f9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200faU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200fbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200fcU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200fdU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200feU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609200ffU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920100U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920101U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920102U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920103U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920104U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920105U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920106U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920107U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920108U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920109U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092010aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092010bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092010cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092010dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092010eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092010fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920110U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920111U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920112U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920113U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920114U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920115U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920116U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920117U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920118U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920119U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092011aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092011bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092011cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092011dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092011eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092011fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920120U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920121U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920122U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920123U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920124U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920125U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920126U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920127U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920128U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920129U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092012aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092012bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092012cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092012dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092012eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092012fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920130U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920131U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920132U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920133U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920134U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920135U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920136U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920137U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920138U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920139U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092013aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092013bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092013cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092013dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092013eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092013fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920140U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920141U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920142U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920143U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920144U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920145U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920146U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920147U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920148U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920149U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092014aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092014bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092014cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092014dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092014eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092014fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920150U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920151U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920152U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920153U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920154U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920155U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920156U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920157U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920158U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920159U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092015aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092015bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092015cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092015dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092015eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092015fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920160U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920161U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920162U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920163U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920164U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920165U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920166U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920167U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920168U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920169U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092016aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092016bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092016cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092016dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092016eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092016fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920170U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920171U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920172U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920173U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920174U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920175U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920176U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920177U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920178U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920179U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092017aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092017bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092017cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092017dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092017eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092017fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920180U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920181U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920182U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920183U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920184U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920185U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920186U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920187U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920188U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920189U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092018aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092018bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092018cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092018dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092018eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092018fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920190U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920191U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920192U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920193U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920194U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920195U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920196U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920197U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920198U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920199U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092019aU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092019bU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092019cU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092019dU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092019eU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x6092019fU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201a9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201aaU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201abU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201acU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201adU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201aeU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201afU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201b9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201baU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201bbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201bcU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201bdU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201beU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201bfU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201c9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201caU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201cbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201ccU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201cdU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201ceU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201cfU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201d9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201daU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201dbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201dcU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201ddU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201deU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201dfU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201e9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201eaU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201ebU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201ecU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201edU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201eeU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201efU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f0U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f1U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f2U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f3U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f4U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f5U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f6U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f7U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f8U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201f9U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201faU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201fbU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201fcU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201fdU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201feU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x609201ffU:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920200U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920201U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920202U:text=L"Physical adaptive Huffman code bits, not the decoded byte/symbol. Following an ESC code, a new literal is stored in8 MSB-first bits. EOF is an in-band adaptive code; trailing bits are raw, not declared padding.";break;
 case 0x60920203U:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x60920204U:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x60920205U:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x60920206U:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x60920207U:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x60920208U:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x60920209U:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x6092020aU:text=L"Eight physical MSB-first literal bits after an adaptive ESC code. This introduces a byte not previously seen.";break;
 case 0x6092020bU:text=L"Clear TARX1 transport signature. Encrypted TAR byte0 is stored at physical byte4; the cipher preserves all subsequent byte positions.";break;
 case 0x6092020cU:text=L"Stored ciphertext bytes at a native-authenticated decoded TAR member header. TARX1 preserves byte boundaries but values here remain encoded, including size, timestamp and checksum. The common257-byte TAR prefix is covered; variant-specific extensions and remaining header bytes stay raw. Decoded archive offsets gain the four-byte clear transport prefix.";break;
 case 0x6092020dU:text=L"PAQ8L level0 physical header. The optional standalone helper currently accepts only level0 DEFAULT stored frames; other PAQ8 revisions/levels/modes remain unsupported by that helper.";break;
 case 0x6092020eU:text=L"Decimal decoded member byte length in the clear PAQ8 directory. The corresponding payload is part of the solid body, not located at this text position.";break;
 case 0x6092020fU:text=L"Physical clear directory name, excluding the preceding TAB and following CRLF. No file is extracted by this schema.";break;
 case 0x60920212U:text=L"Physical byte0x1A ends the clear member directory; it is not part of any decoded member.";break;
 case 0x60920213U:text=L"Level0 DEFAULT type0 frame; four-byte big-endian length counts following untransformed bytes. Entropy-coded and EXE/JPEG preprocessing variants are not interpreted here.";break;
 case 0x60920215U:text=L"GRZipII stored block fields. Mode-1/parameter0 stores bytes verbatim; transform_parameter is written zero in that mode. Other modes use these parameter words for LZP/filter/sorting state. CRC values are stored metadata; this schema does not claim independent integrity verification.";break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}

#define SXARFINAL_LIMIT 20000U
static bool sxarfinal_span(sx_context*c,uint64_t p,uint64_t n){return c&&c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p&&!xx_pd_is_stopped(c->pd);}
static bool sxarfinal_read(sx_context*c,uint64_t p,void*b,size_t n){return sxarfinal_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
static uint64_t sxarfinal_num(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static uint64_t sxarfinal_width(const sx_layout*l){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;return (uint64_t)(f->rel_offset+f->size);}
static bool sxarfinal_put(sx_context*c,const sx_layout*l,uint64_t p){uint64_t n=sxarfinal_width(l);return c->count<SXARFINAL_LIMIT&&n&&sxarfinal_span(c,p,n)&&sx_add(c,l,(int64_t)p,(int64_t)n);}
/* Bit windows intentionally share byte boundaries. Their bit ranges do not
 * overlap; raw gaps use the union of the minimal enclosing byte windows. */
static int sxarfinal_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxarfinal_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxarfinal_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<0||z<=0||p>c->size||z>c->size-p)return false;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+z>end)end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxarfinal_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
typedef struct sxarfinal_bits{sx_context*c;uint64_t bit;bool lsb;uint64_t cached_at;uint8_t cached;bool have;}sxarfinal_bits;
static bool sxarfinal_take(sxarfinal_bits*b,unsigned n,uint64_t*v){if(!n||n>64||xx_pd_is_stopped(b->c->pd)||b->bit>UINT64_MAX-n)return false;uint64_t out=0;for(unsigned i=0;i<n;i++){uint64_t at=b->bit/8;if(!b->have||at!=b->cached_at){if(!sxarfinal_read(b->c,at,&b->cached,1))return false;b->cached_at=at;b->have=true;}unsigned bit=(b->cached>>(b->lsb?(b->bit&7):7-(b->bit&7)))&1U;if(b->lsb)out|=(uint64_t)bit<<i;else out=(out<<1)|bit;b->bit++;}*v=out;return true;}
static bool sxarfinal_field(sxarfinal_bits*b,const sx_layout*const*set,unsigned n,uint64_t*v){uint64_t begin=b->bit;if(!sxarfinal_take(b,n,v))return false;return sxarfinal_put(b->c,set[begin&7],begin/8);}
static bool sxarfinal_variable(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){return n&&n<=4096&&c->count<SXARFINAL_LIMIT&&sxarfinal_span(c,p,n)&&sx_add(c,l,(int64_t)p,(int64_t)n);}

/* SPDX-License-Identifier: MIT. Bounded adaptive tree from the native Unix compact reader. No plaintext output buffer is created. */
#define SXARFINAL_COMPACT_SYM_EOF 0x100
#define SXARFINAL_COMPACT_SYM_ESC 0x101
#define SXARFINAL_COMPACT_SYM_COUNT 0x102
/* Two nodes to start and one per byte value that is introduced after the
 * first, so 2 + 255. */
#define SXARFINAL_COMPACT_MAX_NODES 258
/* One block per slot in the worst case, plus the list head sentinel. */
#define SXARFINAL_COMPACT_MAX_BLOCKS (2 * SXARFINAL_COMPACT_MAX_NODES + 2)
/* Slot 0 of a node is a leaf. */
#define SXARFINAL_COMPACT_LEAF0 8U
/* Slot 1 of a node is a leaf. */
#define SXARFINAL_COMPACT_LEAF1 4U
/* This node is slot 1 of its parent. */
#define SXARFINAL_COMPACT_ISRIGHT 1U
/* A runaway guard: nothing in the file bounds the plaintext. */
#define SXARFINAL_COMPACT_MAX_OUTPUT ((size_t)256 * 1024 * 1024)
#define SXARFINAL_COMPACT_INITIAL_OUTPUT ((size_t)64 * 1024)

/* One branch of a node: the symbol or child node it leads to, the weight
 * behind it, and the block of equal-weight slots it belongs to. */
typedef struct sxarfinal_compact_slot_s {
    int32_t value;
    int32_t block;
    int32_t count;
} sxarfinal_compact_slot;

typedef struct sxarfinal_compact_node_s {
    int32_t parent;
    uint32_t flags;
    sxarfinal_compact_slot child[2];
} sxarfinal_compact_node;

typedef struct sxarfinal_compact_block_s {
    int32_t node; /* node holding this block's first slot */
    int32_t next; /* next lighter block, -1 at the end */
} sxarfinal_compact_block;

typedef struct sxarfinal_compact_tree_s {
    sxarfinal_compact_node nodes[SXARFINAL_COMPACT_MAX_NODES];
    sxarfinal_compact_block blocks[SXARFINAL_COMPACT_MAX_BLOCKS];
    int32_t block_free;
    int32_t last_node;
    /* Where each symbol's leaf lives: the node, and the slot index with bit 1
     * set to mark the entry live. */
    int32_t leaf_node[SXARFINAL_COMPACT_SYM_COUNT];
    int32_t leaf_info[SXARFINAL_COMPACT_SYM_COUNT];
} sxarfinal_compact_tree;

static void sxarfinal_compact_tree_init(sxarfinal_compact_tree *tree, int first)
{
    int index;

    xx_mem_zero(tree, sizeof(*tree));
    for (index = 0; index < SXARFINAL_COMPACT_SYM_COUNT; ++index) {
        tree->leaf_node[index] = -1;
    }
    /* Block 0 is the list head sentinel, so that the heaviest slot always has
     * a predecessor to link through. */
    tree->blocks[0].node = -1;
    tree->blocks[0].next = 1;
    tree->blocks[1].node = 0; /* weight 2: node0.child0 */
    tree->blocks[1].next = 2;
    tree->blocks[2].node = 0; /* weight 1: node0.child1 onward */
    tree->blocks[2].next = -1;
    for (index = 3; index < SXARFINAL_COMPACT_MAX_BLOCKS; ++index) {
        tree->blocks[index].node = -1;
        tree->blocks[index].next = (index + 1 < SXARFINAL_COMPACT_MAX_BLOCKS) ? (index + 1) : -1;
    }
    tree->block_free = 3;

    tree->nodes[0].parent = -1;
    tree->nodes[0].flags = SXARFINAL_COMPACT_LEAF1;
    tree->nodes[0].child[0].value = 1;
    tree->nodes[0].child[0].block = 1;
    tree->nodes[0].child[0].count = 2;
    tree->nodes[0].child[1].value = first;
    tree->nodes[0].child[1].block = 2;
    tree->nodes[0].child[1].count = 1;

    tree->nodes[1].parent = 0;
    tree->nodes[1].flags = SXARFINAL_COMPACT_LEAF0 | SXARFINAL_COMPACT_LEAF1;
    tree->nodes[1].child[0].value = SXARFINAL_COMPACT_SYM_ESC;
    tree->nodes[1].child[0].block = 2;
    tree->nodes[1].child[0].count = 1;
    tree->nodes[1].child[1].value = SXARFINAL_COMPACT_SYM_EOF;
    tree->nodes[1].child[1].block = 2;
    tree->nodes[1].child[1].count = 1;

    tree->last_node = 1;
    tree->leaf_node[first] = 0;
    tree->leaf_info[first] = 3;
    tree->leaf_node[SXARFINAL_COMPACT_SYM_EOF] = 1;
    tree->leaf_info[SXARFINAL_COMPACT_SYM_EOF] = 3;
    tree->leaf_node[SXARFINAL_COMPACT_SYM_ESC] = 1;
    tree->leaf_info[SXARFINAL_COMPACT_SYM_ESC] = 2;
}

/* A slot's contents moved to (@p new_parent, @p new_index): tell whatever the
 * slot holds -- a child node or a symbol's leaf entry -- where it now lives.
 * @p node and @p child_index say which slot the value CAME FROM, because only
 * that slot's flag bit knows whether the value is a node or a symbol. */
/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private sorting implementation, included where its domain types are visible.
 * Keep the exact ordering and tie behavior of the original implementation.
 */

static void sxarfinal_compact_relink(sxarfinal_compact_tree *tree, int node, int child_index, int value, int new_parent, uint32_t new_index)
{
    const uint32_t mask = (child_index == 0) ? SXARFINAL_COMPACT_LEAF0 : SXARFINAL_COMPACT_LEAF1;

    if ((mask & tree->nodes[node].flags) == 0U) {
        tree->nodes[value].parent = new_parent;
        tree->nodes[value].flags &= ~SXARFINAL_COMPACT_ISRIGHT;
        if (new_index != 0U) tree->nodes[value].flags |= new_index;
    } else {
        tree->leaf_node[value] = new_parent;
        tree->leaf_info[value] &= ~1;
        if (new_index != 0U) tree->leaf_info[value] |= (int)new_index;
    }
}

/* Add one to @p symbol's weight and to every weight above it, restoring the
 * slot ordering as it goes. */
static void sxarfinal_compact_tree_update(sxarfinal_compact_tree *tree, int symbol)
{
    int node = tree->leaf_node[symbol];
    uint32_t index = (uint32_t)tree->leaf_info[symbol];

    if (node < 0) return;
    for (;;) {
        int count;
        int old_block;
        /* "above" is the slot before this one in the array, which is the
         * heavier neighbour; "below" is the lighter one after it. */
        int above_count = 0;
        int above_block = 0;
        int below_count = 0;
        int below_block = -1;
        int below_node = 0;

        index &= 1U;
        tree->nodes[node].child[index].count += 1;
        count = tree->nodes[node].child[index].count;
        old_block = tree->nodes[node].child[index].block;

        for (;;) {
            int leader;
            int leader_index;
            uint32_t is_right;
            int moved_in;
            int moved_out;
            uint32_t mask_here;
            uint32_t mask_there;

            if (index != 0U) {
                below_node = node + 1;
                if (node == tree->last_node) {
                    /* Nothing lighter exists; make the tests below behave as
                     * if the neighbour were two lighter. */
                    below_count = count - 2;
                    below_block = -1;
                } else {
                    below_count = tree->nodes[node + 1].child[0].count;
                    below_block = tree->nodes[node + 1].child[0].block;
                }
                above_count = tree->nodes[node].child[0].count;
                above_block = tree->nodes[node].child[0].block;
            } else {
                below_node = node;
                below_count = tree->nodes[node].child[1].count;
                below_block = tree->nodes[node].child[1].block;
                if (node != 0) {
                    above_count = tree->nodes[node - 1].child[1].count;
                    above_block = tree->nodes[node - 1].child[1].block;
                } else {
                    /* The first slot of all: nothing can be heavier. */
                    above_count = count + 1;
                    above_block = 0;
                }
            }

            if (count <= above_count) break;

            /* Swap with the leader of the block just above. The leader is
             * that block's first slot: slot 0 of its node unless slot 0 is
             * already too heavy to be in the block. */
            leader = tree->blocks[above_block].node;
            leader_index = (count <= tree->nodes[leader].child[0].count) ? 1 : 0;
            is_right = (uint32_t)leader_index;
            moved_in = tree->nodes[leader].child[leader_index].value;
            moved_out = tree->nodes[node].child[index].value;
            tree->nodes[leader].child[leader_index].value = moved_out;
            tree->nodes[node].child[index].value = moved_in;
            sxarfinal_compact_relink(tree, leader, leader_index, moved_in, node, index);
            sxarfinal_compact_relink(tree, node, (int)index, moved_out, leader, is_right);
            mask_here = (index == 0U) ? SXARFINAL_COMPACT_LEAF0 : SXARFINAL_COMPACT_LEAF1;
            mask_there = (is_right == 0U) ? SXARFINAL_COMPACT_LEAF0 : SXARFINAL_COMPACT_LEAF1;
            /* Both sides normalise to the same bit position, so this is just
             * "the two slots disagree about being a leaf". */
            if (((tree->nodes[node].flags & mask_here) << index) != ((tree->nodes[leader].flags & mask_there) << is_right)) {
                tree->nodes[node].flags ^= mask_here;
                tree->nodes[leader].flags ^= mask_there;
            }
            /* The weights stay with the positions, not with the contents. */
            tree->nodes[leader].child[leader_index].count += 1;
            tree->nodes[node].child[index].count -= 1;
            node = leader;
            index = is_right;
            /* The block just lost its first slot to a heavier weight. Its
             * leader moves on, and only crosses into the next node when the
             * slot it lost was the node's second. */
            if (is_right != 0U) tree->blocks[above_block].node += 1;
        }

        if (count == above_count) {
            /* Joins the block above. */
            tree->nodes[node].child[index].block = above_block;
            if (below_count + 1 < count) {
                /* It was alone in its old block, which now disappears. */
                tree->blocks[above_block].next = below_block;
                tree->blocks[old_block].next = tree->block_free;
                tree->block_free = old_block;
            } else if (below_block >= 0) {
                tree->blocks[below_block].node = below_node;
            }
        } else if (count == below_count + 1) {
            /* It left the block it shared with the slot below and is not
             * heavy enough for the one above: it needs a block of its own. */
            int fresh = tree->block_free;
            if (fresh < 0) return;
            tree->block_free = tree->blocks[fresh].next;
            tree->blocks[fresh].next = below_block;
            tree->blocks[fresh].node = node;
            tree->blocks[above_block].next = fresh;
            if (below_block >= 0) tree->blocks[below_block].node = below_node;
            tree->nodes[node].child[index].block = fresh;
        }

        index = tree->nodes[node].flags;
        node = tree->nodes[node].parent;
        if (node < 0) return;
    }
}


/* Give @p symbol a leaf by splitting the lightest slot in the tree. */
static bool sxarfinal_compact_tree_add(sxarfinal_compact_tree *tree, int symbol)
{
    int fresh = tree->block_free;
    int parent = tree->last_node;
    int added;
    int displaced;

    if (fresh < 0) return false;
    if (parent + 1 >= SXARFINAL_COMPACT_MAX_NODES) return false;
    /* The lightest slot must be a leaf; if it is not, the tree is not in a
     * state this format can produce. */
    if ((tree->nodes[parent].flags & SXARFINAL_COMPACT_LEAF1) == 0U) return false;
    displaced = tree->nodes[parent].child[1].value;
    if (displaced < 0 || displaced >= SXARFINAL_COMPACT_SYM_COUNT) return false;

    tree->block_free = tree->blocks[fresh].next;
    added = parent + 1;
    tree->last_node = added;
    tree->nodes[added].parent = parent;
    tree->leaf_info[symbol] = 3;

    tree->blocks[fresh].node = added;
    tree->nodes[parent].child[1].value = added;
    tree->leaf_node[displaced] = added;
    tree->leaf_node[symbol] = added;
    tree->nodes[added].flags = SXARFINAL_COMPACT_LEAF0 | SXARFINAL_COMPACT_LEAF1 | SXARFINAL_COMPACT_ISRIGHT;
    tree->nodes[parent].flags &= ~SXARFINAL_COMPACT_LEAF1;
    tree->leaf_info[displaced] = 2;
    /* The displaced leaf keeps its weight and block; the new one starts at
     * zero in a block of its own, appended below. */
    tree->nodes[added].child[0].value = displaced;
    tree->nodes[added].child[0].count = tree->nodes[parent].child[1].count;
    tree->nodes[added].child[0].block = tree->nodes[parent].child[1].block;
    tree->nodes[added].child[1].value = symbol;
    tree->nodes[added].child[1].count = 0;
    tree->blocks[tree->nodes[parent].child[1].block].next = fresh;
    tree->nodes[added].child[1].block = fresh;
    tree->blocks[fresh].next = -1;
    return true;
}


static const sx_layout*const*const sxarfinal_compact_code_sets[]={sxarfinal_set_unixcompact_code1,sxarfinal_set_unixcompact_code2,sxarfinal_set_unixcompact_code3,sxarfinal_set_unixcompact_code4,sxarfinal_set_unixcompact_code5,sxarfinal_set_unixcompact_code6,sxarfinal_set_unixcompact_code7,sxarfinal_set_unixcompact_code8,sxarfinal_set_unixcompact_code9,sxarfinal_set_unixcompact_code10,sxarfinal_set_unixcompact_code11,sxarfinal_set_unixcompact_code12,sxarfinal_set_unixcompact_code13,sxarfinal_set_unixcompact_code14,sxarfinal_set_unixcompact_code15,sxarfinal_set_unixcompact_code16,sxarfinal_set_unixcompact_code17,sxarfinal_set_unixcompact_code18,sxarfinal_set_unixcompact_code19,sxarfinal_set_unixcompact_code20,sxarfinal_set_unixcompact_code21,sxarfinal_set_unixcompact_code22,sxarfinal_set_unixcompact_code23,sxarfinal_set_unixcompact_code24,sxarfinal_set_unixcompact_code25,sxarfinal_set_unixcompact_code26,sxarfinal_set_unixcompact_code27,sxarfinal_set_unixcompact_code28,sxarfinal_set_unixcompact_code29,sxarfinal_set_unixcompact_code30,sxarfinal_set_unixcompact_code31,sxarfinal_set_unixcompact_code32,sxarfinal_set_unixcompact_code33,sxarfinal_set_unixcompact_code34,sxarfinal_set_unixcompact_code35,sxarfinal_set_unixcompact_code36,sxarfinal_set_unixcompact_code37,sxarfinal_set_unixcompact_code38,sxarfinal_set_unixcompact_code39,sxarfinal_set_unixcompact_code40,sxarfinal_set_unixcompact_code41,sxarfinal_set_unixcompact_code42,sxarfinal_set_unixcompact_code43,sxarfinal_set_unixcompact_code44,sxarfinal_set_unixcompact_code45,sxarfinal_set_unixcompact_code46,sxarfinal_set_unixcompact_code47,sxarfinal_set_unixcompact_code48,sxarfinal_set_unixcompact_code49,sxarfinal_set_unixcompact_code50,sxarfinal_set_unixcompact_code51,sxarfinal_set_unixcompact_code52,sxarfinal_set_unixcompact_code53,sxarfinal_set_unixcompact_code54,sxarfinal_set_unixcompact_code55,sxarfinal_set_unixcompact_code56,sxarfinal_set_unixcompact_code57,sxarfinal_set_unixcompact_code58,sxarfinal_set_unixcompact_code59,sxarfinal_set_unixcompact_code60,sxarfinal_set_unixcompact_code61,sxarfinal_set_unixcompact_code62,sxarfinal_set_unixcompact_code63,sxarfinal_set_unixcompact_code64};
static bool sxarfinal_unixcompact(sx_context*c){
 uint8_t h[3],seen[256];if(!sxarfinal_read(c,0,h,3)||h[0]!=255||h[1]!=31||!sxarfinal_put(c,&sxarfinal_unixcompact_prefix,0))return false;
 sxarfinal_compact_tree*tree=(sxarfinal_compact_tree*)xx_mem_alloc(sizeof(*tree));if(!tree)return false;
 xx_rt_memset(seen,0,sizeof(seen));seen[h[2]]=1;sxarfinal_compact_tree_init(tree,h[2]);
 sxarfinal_bits b={c,24,false,0,0,false};bool ok=false;
 for(unsigned step=0;step<SXARFINAL_LIMIT&&!xx_pd_is_stopped(c->pd);step++){
  int node=0,symbol=-1;uint64_t begin=b.bit;unsigned width=0;
  while(width<64){uint64_t bit;if(!sxarfinal_take(&b,1,&bit))goto done;width++;
   uint32_t mask=bit?SXARFINAL_COMPACT_LEAF1:SXARFINAL_COMPACT_LEAF0;
   if(tree->nodes[node].flags&mask){symbol=tree->nodes[node].child[bit].value;break;}
   node=tree->nodes[node].child[bit].value;if(node<0||node>=SXARFINAL_COMPACT_MAX_NODES)goto done;
  }
  if(symbol<0||width==0||!sxarfinal_put(c,sxarfinal_compact_code_sets[width-1][begin&7],begin/8))goto done;
  if(symbol==SXARFINAL_COMPACT_SYM_EOF){ok=true;goto done;}
  if(symbol==SXARFINAL_COMPACT_SYM_ESC){
   sxarfinal_compact_tree_update(tree,SXARFINAL_COMPACT_SYM_ESC);uint64_t literal;
   if(!sxarfinal_field(&b,sxarfinal_set_unixcompact_new_literal,8,&literal)||seen[literal])goto done;
   symbol=(int)literal;seen[literal]=1;if(!sxarfinal_compact_tree_add(tree,symbol))goto done;
  }else if(symbol>255)goto done;
  sxarfinal_compact_tree_update(tree,symbol);
 }
 ok=!xx_pd_is_stopped(c->pd);
done:xx_mem_free(tree);return ok;
}

/* TARX1's owned inner TAR starts at decoded offset0. Only native member
 * coordinates are translated; none is interpreted as an outer absolute offset. */
static bool sxarfinal_tarx(sx_context*c){
 Abstractformat*f=c->f;uint8_t magic[4];
 if(!sxarfinal_read(c,0,magic,4)||xx_rt_memcmp(magic,"TaRx",4)||!f->create_archive_records_reading||!f->get_current_archive_record||!f->archive_record_move_to_next||!f->free_archive_records_reading)return false;
 xx_archive_record_state*s=(f->create_archive_records_reading)(f,NULL,c->pd);if(!s)return false;bool ok=false;
 if(!sxarfinal_put(c,&sxarfinal_tarx1_transport_prefix,0))goto done;
 for(unsigned i=0;i<SXARFINAL_LIMIT&&!xx_pd_is_stopped(c->pd);i++){
  const xx_archive_record*r=(f->get_current_archive_record)(f,s);if(!r){ok=true;break;}
  if(r->header_offset<0||r->header_size!=512||(uint64_t)r->header_offset>UINT64_MAX-4)goto done;
  uint64_t p=(uint64_t)r->header_offset+4;if(!sxarfinal_span(c,p,512)||!sxarfinal_put(c,&sxarfinal_tarx1_encrypted_tar_core,p))goto done;
  if(!(f->archive_record_move_to_next)(f,s,c->pd)){ok=true;break;}
 }
done:(f->free_archive_records_reading)(f,s);return ok;
}
static bool sxarfinal_pcsecure(sx_context*c){uint8_t h[4];return c->size>68&&sxarfinal_read(c,0,h,4)&&(!xx_rt_memcmp(h,"PCT5",4)||!xx_rt_memcmp(h,"PCT6",4)||!xx_rt_memcmp(h,"PCT7",4)||!xx_rt_memcmp(h,"AfoS",4))&&sxarfinal_put(c,&sxarfinal_pcsecure_physical_header,0);}

static bool sxarfinal_paq8(sx_context*c){
 uint8_t h[10];uint64_t p=10,total=0;unsigned members=0;
 if(!sxarfinal_read(c,0,h,10)||xx_rt_memcmp(h,"paq8l -0\r\n",10)||!sxarfinal_put(c,&sxarfinal_paq8l_stored_header,0))return false;
 for(;members<65536;members++){
  uint8_t v;if(!sxarfinal_read(c,p,&v,1))return false;if(v==26)break;uint64_t start=p,z=0;
  while(v>='0'&&v<='9'){if(z>(UINT64_MAX-(v-'0'))/10||p-start>=24)return false;z=z*10+(v-'0');p++;if(!sxarfinal_read(c,p,&v,1))return false;}
  if(p==start||v!=9||z>UINT64_MAX-total||!sxarfinal_variable(c,&sxarfinal_paq8_member_size,start,p-start)||!sxarfinal_put(c,&sxarfinal_paq8_tab,p))return false;
  total+=z;start=++p;
  while(sxarfinal_read(c,p,&v,1)&&v!=13){if(v<32||v==127||p-start>=4096)return false;p++;}
  if(p==start||!sxarfinal_variable(c,&sxarfinal_paq8_member_name,start,p-start)||!sxarfinal_read(c,p,h,2)||h[0]!=13||h[1]!=10||!sxarfinal_put(c,&sxarfinal_paq8_line_ending,p))return false;p+=2;
 }
 if(!members||members==65536||!sxarfinal_put(c,&sxarfinal_paq8_directory_end,p++))return false;
 uint64_t output=0;for(unsigned block=0;output<total&&block<SXARFINAL_LIMIT;block++){
  if(!sxarfinal_read(c,p,h,5)||h[0])return false;uint64_t z=sxarfinal_num(h+1,4,true);
  if(!z||z>INT32_MAX||z>total-output||!sxarfinal_span(c,p+5,z)||!sxarfinal_put(c,&sxarfinal_paq8l_stored_frame,p))return false;
  output+=z;p+=5+z;
 }
 return output==total;
}
static bool sxarfinal_grzip(sx_context*c){
 static const uint8_t magic[12]={'G','R','Z','i','p','I','I',0,2,4,':',')'};uint8_t h[28];uint64_t p=12;
 if(!sxarfinal_read(c,0,h,12)||xx_rt_memcmp(h,magic,12)||!sxarfinal_put(c,&sxarfinal_grzip_stream_header,0))return false;
 for(unsigned blocks=0;p<(uint64_t)c->size&&blocks<SXARFINAL_LIMIT;blocks++){
  if(!sxarfinal_read(c,p,h,28))return false;uint64_t z=sxarfinal_num(h+16,4,false);
  if(z>INT32_MAX||!sxarfinal_span(c,p+28,z)||!sxarfinal_put(c,&sxarfinal_grzip_block_header,p))return false;p+=28+z;
 }
 return true;
}

static bool sx_archiveresidual_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_PAQ8:case XX_FILE_TYPE_GRZIP:case XX_FILE_TYPE_TARX1:case XX_FILE_TYPE_PCSECURE:case XX_FILE_TYPE_UNIX_COMPACT:return true;default:return false;}}
static bool sx_archiveresidual_build(sx_context*c){bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_PAQ8:ok=sxarfinal_paq8(c);break;case XX_FILE_TYPE_GRZIP:ok=sxarfinal_grzip(c);break;case XX_FILE_TYPE_TARX1:ok=sxarfinal_tarx(c);break;case XX_FILE_TYPE_PCSECURE:ok=sxarfinal_pcsecure(c);break;case XX_FILE_TYPE_UNIX_COMPACT:ok=sxarfinal_unixcompact(c);break;default:return false;}(void)ok;return c->count&&sxarfinal_finish(c);}
