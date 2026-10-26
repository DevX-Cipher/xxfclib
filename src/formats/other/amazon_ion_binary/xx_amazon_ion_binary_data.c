/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * amazon ion binary data structures, moved out of the binarylater schema family. */
#include "../../xx_format_schema_binarylater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbl_ion_tag_fields[] = {
 SX_FIELD("type_and_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxbl_ion_tag = {UINT32_C(0x6035003a),"ion_tag",sxbl_ion_tag_fields,SX_COUNT(sxbl_ion_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_version_fields[] = {
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("major","uint8",1,1,SX_ID),
 SX_FIELD("minor","uint8",2,1,SX_ID),
 SX_FIELD("terminator","uint8",3,1,SX_SIGNATURE),
};
const sx_layout sxbl_ion_version = {UINT32_C(0x603500a4),"ion_version",sxbl_ion_version_fields,SX_COUNT(sxbl_ion_version_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_length1_fields[] = {
 SX_FIELD("length","ion_varuint[1]",0,1,SX_SIZE),
};
const sx_layout sxbl_ion_length1 = {UINT32_C(0x603500a5),"ion_length1",sxbl_ion_length1_fields,SX_COUNT(sxbl_ion_length1_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_field_id1_fields[] = {
 SX_FIELD("field_id","ion_varuint[1]",0,1,SX_ID),
};
const sx_layout sxbl_ion_field_id1 = {UINT32_C(0x603500a6),"ion_field_id1",sxbl_ion_field_id1_fields,SX_COUNT(sxbl_ion_field_id1_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_length1_fields[] = {
 SX_FIELD("annotation_length","ion_varuint[1]",0,1,SX_SIZE),
};
const sx_layout sxbl_ion_annotation_length1 = {UINT32_C(0x603500a7),"ion_annotation_length1",sxbl_ion_annotation_length1_fields,SX_COUNT(sxbl_ion_annotation_length1_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_id1_fields[] = {
 SX_FIELD("annotation_id","ion_varuint[1]",0,1,SX_ID),
};
const sx_layout sxbl_ion_annotation_id1 = {UINT32_C(0x603500a8),"ion_annotation_id1",sxbl_ion_annotation_id1_fields,SX_COUNT(sxbl_ion_annotation_id1_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_decimal_exponent1_fields[] = {
 SX_FIELD("decimal_exponent","ion_varint[1]",0,1,SX_NONE),
};
const sx_layout sxbl_ion_decimal_exponent1 = {UINT32_C(0x603500a9),"ion_decimal_exponent1",sxbl_ion_decimal_exponent1_fields,SX_COUNT(sxbl_ion_decimal_exponent1_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_length2_fields[] = {
 SX_FIELD("length","ion_varuint[2]",0,2,SX_SIZE),
};
const sx_layout sxbl_ion_length2 = {UINT32_C(0x603500aa),"ion_length2",sxbl_ion_length2_fields,SX_COUNT(sxbl_ion_length2_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_field_id2_fields[] = {
 SX_FIELD("field_id","ion_varuint[2]",0,2,SX_ID),
};
const sx_layout sxbl_ion_field_id2 = {UINT32_C(0x603500ab),"ion_field_id2",sxbl_ion_field_id2_fields,SX_COUNT(sxbl_ion_field_id2_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_length2_fields[] = {
 SX_FIELD("annotation_length","ion_varuint[2]",0,2,SX_SIZE),
};
const sx_layout sxbl_ion_annotation_length2 = {UINT32_C(0x603500ac),"ion_annotation_length2",sxbl_ion_annotation_length2_fields,SX_COUNT(sxbl_ion_annotation_length2_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_id2_fields[] = {
 SX_FIELD("annotation_id","ion_varuint[2]",0,2,SX_ID),
};
const sx_layout sxbl_ion_annotation_id2 = {UINT32_C(0x603500ad),"ion_annotation_id2",sxbl_ion_annotation_id2_fields,SX_COUNT(sxbl_ion_annotation_id2_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_decimal_exponent2_fields[] = {
 SX_FIELD("decimal_exponent","ion_varint[2]",0,2,SX_NONE),
};
const sx_layout sxbl_ion_decimal_exponent2 = {UINT32_C(0x603500ae),"ion_decimal_exponent2",sxbl_ion_decimal_exponent2_fields,SX_COUNT(sxbl_ion_decimal_exponent2_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_length3_fields[] = {
 SX_FIELD("length","ion_varuint[3]",0,3,SX_SIZE),
};
const sx_layout sxbl_ion_length3 = {UINT32_C(0x603500af),"ion_length3",sxbl_ion_length3_fields,SX_COUNT(sxbl_ion_length3_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_field_id3_fields[] = {
 SX_FIELD("field_id","ion_varuint[3]",0,3,SX_ID),
};
const sx_layout sxbl_ion_field_id3 = {UINT32_C(0x603500b0),"ion_field_id3",sxbl_ion_field_id3_fields,SX_COUNT(sxbl_ion_field_id3_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_length3_fields[] = {
 SX_FIELD("annotation_length","ion_varuint[3]",0,3,SX_SIZE),
};
const sx_layout sxbl_ion_annotation_length3 = {UINT32_C(0x603500b1),"ion_annotation_length3",sxbl_ion_annotation_length3_fields,SX_COUNT(sxbl_ion_annotation_length3_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_id3_fields[] = {
 SX_FIELD("annotation_id","ion_varuint[3]",0,3,SX_ID),
};
const sx_layout sxbl_ion_annotation_id3 = {UINT32_C(0x603500b2),"ion_annotation_id3",sxbl_ion_annotation_id3_fields,SX_COUNT(sxbl_ion_annotation_id3_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_decimal_exponent3_fields[] = {
 SX_FIELD("decimal_exponent","ion_varint[3]",0,3,SX_NONE),
};
const sx_layout sxbl_ion_decimal_exponent3 = {UINT32_C(0x603500b3),"ion_decimal_exponent3",sxbl_ion_decimal_exponent3_fields,SX_COUNT(sxbl_ion_decimal_exponent3_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_length4_fields[] = {
 SX_FIELD("length","ion_varuint[4]",0,4,SX_SIZE),
};
const sx_layout sxbl_ion_length4 = {UINT32_C(0x603500b4),"ion_length4",sxbl_ion_length4_fields,SX_COUNT(sxbl_ion_length4_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_field_id4_fields[] = {
 SX_FIELD("field_id","ion_varuint[4]",0,4,SX_ID),
};
const sx_layout sxbl_ion_field_id4 = {UINT32_C(0x603500b5),"ion_field_id4",sxbl_ion_field_id4_fields,SX_COUNT(sxbl_ion_field_id4_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_length4_fields[] = {
 SX_FIELD("annotation_length","ion_varuint[4]",0,4,SX_SIZE),
};
const sx_layout sxbl_ion_annotation_length4 = {UINT32_C(0x603500b6),"ion_annotation_length4",sxbl_ion_annotation_length4_fields,SX_COUNT(sxbl_ion_annotation_length4_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_id4_fields[] = {
 SX_FIELD("annotation_id","ion_varuint[4]",0,4,SX_ID),
};
const sx_layout sxbl_ion_annotation_id4 = {UINT32_C(0x603500b7),"ion_annotation_id4",sxbl_ion_annotation_id4_fields,SX_COUNT(sxbl_ion_annotation_id4_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_decimal_exponent4_fields[] = {
 SX_FIELD("decimal_exponent","ion_varint[4]",0,4,SX_NONE),
};
const sx_layout sxbl_ion_decimal_exponent4 = {UINT32_C(0x603500b8),"ion_decimal_exponent4",sxbl_ion_decimal_exponent4_fields,SX_COUNT(sxbl_ion_decimal_exponent4_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_length5_fields[] = {
 SX_FIELD("length","ion_varuint[5]",0,5,SX_SIZE),
};
const sx_layout sxbl_ion_length5 = {UINT32_C(0x603500b9),"ion_length5",sxbl_ion_length5_fields,SX_COUNT(sxbl_ion_length5_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_field_id5_fields[] = {
 SX_FIELD("field_id","ion_varuint[5]",0,5,SX_ID),
};
const sx_layout sxbl_ion_field_id5 = {UINT32_C(0x603500ba),"ion_field_id5",sxbl_ion_field_id5_fields,SX_COUNT(sxbl_ion_field_id5_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_length5_fields[] = {
 SX_FIELD("annotation_length","ion_varuint[5]",0,5,SX_SIZE),
};
const sx_layout sxbl_ion_annotation_length5 = {UINT32_C(0x603500bb),"ion_annotation_length5",sxbl_ion_annotation_length5_fields,SX_COUNT(sxbl_ion_annotation_length5_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_id5_fields[] = {
 SX_FIELD("annotation_id","ion_varuint[5]",0,5,SX_ID),
};
const sx_layout sxbl_ion_annotation_id5 = {UINT32_C(0x603500bc),"ion_annotation_id5",sxbl_ion_annotation_id5_fields,SX_COUNT(sxbl_ion_annotation_id5_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_decimal_exponent5_fields[] = {
 SX_FIELD("decimal_exponent","ion_varint[5]",0,5,SX_NONE),
};
const sx_layout sxbl_ion_decimal_exponent5 = {UINT32_C(0x603500bd),"ion_decimal_exponent5",sxbl_ion_decimal_exponent5_fields,SX_COUNT(sxbl_ion_decimal_exponent5_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_length6_fields[] = {
 SX_FIELD("length","ion_varuint[6]",0,6,SX_SIZE),
};
const sx_layout sxbl_ion_length6 = {UINT32_C(0x603500be),"ion_length6",sxbl_ion_length6_fields,SX_COUNT(sxbl_ion_length6_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_field_id6_fields[] = {
 SX_FIELD("field_id","ion_varuint[6]",0,6,SX_ID),
};
const sx_layout sxbl_ion_field_id6 = {UINT32_C(0x603500bf),"ion_field_id6",sxbl_ion_field_id6_fields,SX_COUNT(sxbl_ion_field_id6_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_length6_fields[] = {
 SX_FIELD("annotation_length","ion_varuint[6]",0,6,SX_SIZE),
};
const sx_layout sxbl_ion_annotation_length6 = {UINT32_C(0x603500c0),"ion_annotation_length6",sxbl_ion_annotation_length6_fields,SX_COUNT(sxbl_ion_annotation_length6_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_id6_fields[] = {
 SX_FIELD("annotation_id","ion_varuint[6]",0,6,SX_ID),
};
const sx_layout sxbl_ion_annotation_id6 = {UINT32_C(0x603500c1),"ion_annotation_id6",sxbl_ion_annotation_id6_fields,SX_COUNT(sxbl_ion_annotation_id6_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_decimal_exponent6_fields[] = {
 SX_FIELD("decimal_exponent","ion_varint[6]",0,6,SX_NONE),
};
const sx_layout sxbl_ion_decimal_exponent6 = {UINT32_C(0x603500c2),"ion_decimal_exponent6",sxbl_ion_decimal_exponent6_fields,SX_COUNT(sxbl_ion_decimal_exponent6_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_length7_fields[] = {
 SX_FIELD("length","ion_varuint[7]",0,7,SX_SIZE),
};
const sx_layout sxbl_ion_length7 = {UINT32_C(0x603500c3),"ion_length7",sxbl_ion_length7_fields,SX_COUNT(sxbl_ion_length7_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_field_id7_fields[] = {
 SX_FIELD("field_id","ion_varuint[7]",0,7,SX_ID),
};
const sx_layout sxbl_ion_field_id7 = {UINT32_C(0x603500c4),"ion_field_id7",sxbl_ion_field_id7_fields,SX_COUNT(sxbl_ion_field_id7_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_length7_fields[] = {
 SX_FIELD("annotation_length","ion_varuint[7]",0,7,SX_SIZE),
};
const sx_layout sxbl_ion_annotation_length7 = {UINT32_C(0x603500c5),"ion_annotation_length7",sxbl_ion_annotation_length7_fields,SX_COUNT(sxbl_ion_annotation_length7_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_id7_fields[] = {
 SX_FIELD("annotation_id","ion_varuint[7]",0,7,SX_ID),
};
const sx_layout sxbl_ion_annotation_id7 = {UINT32_C(0x603500c6),"ion_annotation_id7",sxbl_ion_annotation_id7_fields,SX_COUNT(sxbl_ion_annotation_id7_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_decimal_exponent7_fields[] = {
 SX_FIELD("decimal_exponent","ion_varint[7]",0,7,SX_NONE),
};
const sx_layout sxbl_ion_decimal_exponent7 = {UINT32_C(0x603500c7),"ion_decimal_exponent7",sxbl_ion_decimal_exponent7_fields,SX_COUNT(sxbl_ion_decimal_exponent7_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_length8_fields[] = {
 SX_FIELD("length","ion_varuint[8]",0,8,SX_SIZE),
};
const sx_layout sxbl_ion_length8 = {UINT32_C(0x603500c8),"ion_length8",sxbl_ion_length8_fields,SX_COUNT(sxbl_ion_length8_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_field_id8_fields[] = {
 SX_FIELD("field_id","ion_varuint[8]",0,8,SX_ID),
};
const sx_layout sxbl_ion_field_id8 = {UINT32_C(0x603500c9),"ion_field_id8",sxbl_ion_field_id8_fields,SX_COUNT(sxbl_ion_field_id8_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_length8_fields[] = {
 SX_FIELD("annotation_length","ion_varuint[8]",0,8,SX_SIZE),
};
const sx_layout sxbl_ion_annotation_length8 = {UINT32_C(0x603500ca),"ion_annotation_length8",sxbl_ion_annotation_length8_fields,SX_COUNT(sxbl_ion_annotation_length8_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_id8_fields[] = {
 SX_FIELD("annotation_id","ion_varuint[8]",0,8,SX_ID),
};
const sx_layout sxbl_ion_annotation_id8 = {UINT32_C(0x603500cb),"ion_annotation_id8",sxbl_ion_annotation_id8_fields,SX_COUNT(sxbl_ion_annotation_id8_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_decimal_exponent8_fields[] = {
 SX_FIELD("decimal_exponent","ion_varint[8]",0,8,SX_NONE),
};
const sx_layout sxbl_ion_decimal_exponent8 = {UINT32_C(0x603500cc),"ion_decimal_exponent8",sxbl_ion_decimal_exponent8_fields,SX_COUNT(sxbl_ion_decimal_exponent8_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_length9_fields[] = {
 SX_FIELD("length","ion_varuint[9]",0,9,SX_SIZE),
};
const sx_layout sxbl_ion_length9 = {UINT32_C(0x603500cd),"ion_length9",sxbl_ion_length9_fields,SX_COUNT(sxbl_ion_length9_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_field_id9_fields[] = {
 SX_FIELD("field_id","ion_varuint[9]",0,9,SX_ID),
};
const sx_layout sxbl_ion_field_id9 = {UINT32_C(0x603500ce),"ion_field_id9",sxbl_ion_field_id9_fields,SX_COUNT(sxbl_ion_field_id9_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_length9_fields[] = {
 SX_FIELD("annotation_length","ion_varuint[9]",0,9,SX_SIZE),
};
const sx_layout sxbl_ion_annotation_length9 = {UINT32_C(0x603500cf),"ion_annotation_length9",sxbl_ion_annotation_length9_fields,SX_COUNT(sxbl_ion_annotation_length9_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_id9_fields[] = {
 SX_FIELD("annotation_id","ion_varuint[9]",0,9,SX_ID),
};
const sx_layout sxbl_ion_annotation_id9 = {UINT32_C(0x603500d0),"ion_annotation_id9",sxbl_ion_annotation_id9_fields,SX_COUNT(sxbl_ion_annotation_id9_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_decimal_exponent9_fields[] = {
 SX_FIELD("decimal_exponent","ion_varint[9]",0,9,SX_NONE),
};
const sx_layout sxbl_ion_decimal_exponent9 = {UINT32_C(0x603500d1),"ion_decimal_exponent9",sxbl_ion_decimal_exponent9_fields,SX_COUNT(sxbl_ion_decimal_exponent9_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_length10_fields[] = {
 SX_FIELD("length","ion_varuint[10]",0,10,SX_SIZE),
};
const sx_layout sxbl_ion_length10 = {UINT32_C(0x603500d2),"ion_length10",sxbl_ion_length10_fields,SX_COUNT(sxbl_ion_length10_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_field_id10_fields[] = {
 SX_FIELD("field_id","ion_varuint[10]",0,10,SX_ID),
};
const sx_layout sxbl_ion_field_id10 = {UINT32_C(0x603500d3),"ion_field_id10",sxbl_ion_field_id10_fields,SX_COUNT(sxbl_ion_field_id10_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_length10_fields[] = {
 SX_FIELD("annotation_length","ion_varuint[10]",0,10,SX_SIZE),
};
const sx_layout sxbl_ion_annotation_length10 = {UINT32_C(0x603500d4),"ion_annotation_length10",sxbl_ion_annotation_length10_fields,SX_COUNT(sxbl_ion_annotation_length10_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_annotation_id10_fields[] = {
 SX_FIELD("annotation_id","ion_varuint[10]",0,10,SX_ID),
};
const sx_layout sxbl_ion_annotation_id10 = {UINT32_C(0x603500d5),"ion_annotation_id10",sxbl_ion_annotation_id10_fields,SX_COUNT(sxbl_ion_annotation_id10_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_decimal_exponent10_fields[] = {
 SX_FIELD("decimal_exponent","ion_varint[10]",0,10,SX_NONE),
};
const sx_layout sxbl_ion_decimal_exponent10 = {UINT32_C(0x603500d6),"ion_decimal_exponent10",sxbl_ion_decimal_exponent10_fields,SX_COUNT(sxbl_ion_decimal_exponent10_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ion_negative_magnitude1_fields[] = {
 SX_FIELD("absolute_magnitude","uint8",0,1,SX_NONE),
};
const sx_layout sxbl_ion_negative_magnitude1 = {UINT32_C(0x603500fc),"ion_negative_magnitude1",sxbl_ion_negative_magnitude1_fields,SX_COUNT(sxbl_ion_negative_magnitude1_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ion_negative_magnitude2_fields[] = {
 SX_FIELD("absolute_magnitude","uint16",0,2,SX_NONE),
};
const sx_layout sxbl_ion_negative_magnitude2 = {UINT32_C(0x603500fe),"ion_negative_magnitude2",sxbl_ion_negative_magnitude2_fields,SX_COUNT(sxbl_ion_negative_magnitude2_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ion_negative_magnitude3_fields[] = {
 SX_FIELD("absolute_magnitude","uint24",0,3,SX_NONE),
};
const sx_layout sxbl_ion_negative_magnitude3 = {UINT32_C(0x60350100),"ion_negative_magnitude3",sxbl_ion_negative_magnitude3_fields,SX_COUNT(sxbl_ion_negative_magnitude3_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ion_negative_magnitude4_fields[] = {
 SX_FIELD("absolute_magnitude","uint32",0,4,SX_NONE),
};
const sx_layout sxbl_ion_negative_magnitude4 = {UINT32_C(0x60350102),"ion_negative_magnitude4",sxbl_ion_negative_magnitude4_fields,SX_COUNT(sxbl_ion_negative_magnitude4_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ion_negative_magnitude5_fields[] = {
 SX_FIELD("absolute_magnitude","uint40",0,5,SX_NONE),
};
const sx_layout sxbl_ion_negative_magnitude5 = {UINT32_C(0x60350104),"ion_negative_magnitude5",sxbl_ion_negative_magnitude5_fields,SX_COUNT(sxbl_ion_negative_magnitude5_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ion_negative_magnitude6_fields[] = {
 SX_FIELD("absolute_magnitude","uint48",0,6,SX_NONE),
};
const sx_layout sxbl_ion_negative_magnitude6 = {UINT32_C(0x60350106),"ion_negative_magnitude6",sxbl_ion_negative_magnitude6_fields,SX_COUNT(sxbl_ion_negative_magnitude6_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ion_negative_magnitude7_fields[] = {
 SX_FIELD("absolute_magnitude","uint56",0,7,SX_NONE),
};
const sx_layout sxbl_ion_negative_magnitude7 = {UINT32_C(0x60350108),"ion_negative_magnitude7",sxbl_ion_negative_magnitude7_fields,SX_COUNT(sxbl_ion_negative_magnitude7_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ion_negative_magnitude8_fields[] = {
 SX_FIELD("absolute_magnitude","uint64",0,8,SX_NONE),
};
const sx_layout sxbl_ion_negative_magnitude8 = {UINT32_C(0x6035010a),"ion_negative_magnitude8",sxbl_ion_negative_magnitude8_fields,SX_COUNT(sxbl_ion_negative_magnitude8_fields),SX_BE};
static bool sxbl_ionvar(sx_context*c,uint64_t*p,uint64_t end,unsigned role,bool sign,uint64_t*out){
 const sx_layout*const v0[]={&sxbl_ion_length1,&sxbl_ion_length2,&sxbl_ion_length3,&sxbl_ion_length4,&sxbl_ion_length5,&sxbl_ion_length6,&sxbl_ion_length7,&sxbl_ion_length8,&sxbl_ion_length9,&sxbl_ion_length10};
 const sx_layout*const v1[]={&sxbl_ion_field_id1,&sxbl_ion_field_id2,&sxbl_ion_field_id3,&sxbl_ion_field_id4,&sxbl_ion_field_id5,&sxbl_ion_field_id6,&sxbl_ion_field_id7,&sxbl_ion_field_id8,&sxbl_ion_field_id9,&sxbl_ion_field_id10};
 const sx_layout*const v2[]={&sxbl_ion_annotation_length1,&sxbl_ion_annotation_length2,&sxbl_ion_annotation_length3,&sxbl_ion_annotation_length4,&sxbl_ion_annotation_length5,&sxbl_ion_annotation_length6,&sxbl_ion_annotation_length7,&sxbl_ion_annotation_length8,&sxbl_ion_annotation_length9,&sxbl_ion_annotation_length10};
 const sx_layout*const v3[]={&sxbl_ion_annotation_id1,&sxbl_ion_annotation_id2,&sxbl_ion_annotation_id3,&sxbl_ion_annotation_id4,&sxbl_ion_annotation_id5,&sxbl_ion_annotation_id6,&sxbl_ion_annotation_id7,&sxbl_ion_annotation_id8,&sxbl_ion_annotation_id9,&sxbl_ion_annotation_id10};
 const sx_layout*const v4[]={&sxbl_ion_decimal_exponent1,&sxbl_ion_decimal_exponent2,&sxbl_ion_decimal_exponent3,&sxbl_ion_decimal_exponent4,&sxbl_ion_decimal_exponent5,&sxbl_ion_decimal_exponent6,&sxbl_ion_decimal_exponent7,&sxbl_ion_decimal_exponent8,&sxbl_ion_decimal_exponent9,&sxbl_ion_decimal_exponent10};
 const sx_layout*const *arrays[]={v0,v1,v2,v3,v4};if(role>4)return false;uint64_t at=*p,v=0;unsigned n=0;uint8_t b;do{if(*p>=end||n==10||!sxbl_byte(c,(*p)++,&b))return false;unsigned bits=b&(sign&&!n?63:127);if(v>(UINT64_MAX-bits)/128)return false;v=v*128+bits;n++;}while(!(b&128));if(!sxbl_add(c,arrays[role][n-1],at))return false;*out=v;return true;}
static bool sxbl_ion(sx_context*c,uint64_t*p,uint64_t end,unsigned depth){uint8_t t;if(depth>32||!sxbl_byte(c,*p,&t)||!sxbl_emit(c,p,end,&sxbl_ion_tag))return false;unsigned kind=t>>4,l=t&15;uint64_t n=l;if(kind==15)return false;if(l==15||kind==1)return true;if((l==14||(kind==13&&l==1))&&!sxbl_ionvar(c,p,end,0,false,&n))return false;if(*p>end||n>end-*p)return false;uint64_t stop=*p+n;
 if(kind==11||kind==12||kind==13){while(*p<stop){uint64_t id;if(kind==13&&!sxbl_ionvar(c,p,stop,1,false,&id))return false;if(!sxbl_ion(c,p,stop,depth+1))return false;}return true;}
 if(kind==14){uint64_t z,id;if(!sxbl_ionvar(c,p,stop,2,false,&z)||z>stop-*p)return false;uint64_t lim=*p+z;while(*p<lim)if(!sxbl_ionvar(c,p,lim,3,false,&id))return false;return sxbl_ion(c,p,stop,depth+1)&&*p==stop;}
 if(kind==4&&(n==4||n==8))return sxbl_float(c,p,stop,(unsigned)n,true);if(kind==3&&n&&n<=8){const sx_layout*const a[]={&sxbl_ion_negative_magnitude1,&sxbl_ion_negative_magnitude2,&sxbl_ion_negative_magnitude3,&sxbl_ion_negative_magnitude4,&sxbl_ion_negative_magnitude5,&sxbl_ion_negative_magnitude6,&sxbl_ion_negative_magnitude7,&sxbl_ion_negative_magnitude8};return sxbl_emit(c,p,stop,a[n-1]);}if((kind==2||kind==7)&&n&&n<=8)return sxbl_numeric(c,p,stop,(unsigned)n,false,true);if(kind==5&&n){uint64_t exp;if(!sxbl_ionvar(c,p,stop,4,true,&exp))return false;}*p=stop;return true;}
bool sx_amazon_ion_binary_build(sx_context*c)
{
 uint64_t p=0,end=(uint64_t)c->size;bool ok=false;ok=sxbl_emit(c,&p,end,&sxbl_ion_version);while(p<end&&ok)ok=sxbl_ion(c,&p,end,0);return ok;
}
