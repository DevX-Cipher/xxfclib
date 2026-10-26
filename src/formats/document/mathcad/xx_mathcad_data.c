/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MathCAD data structures, moved out of the documentwire schema family. */
#include "../../xx_format_schema_documentwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdw_mathcad_header_fields[]={
 SX_FIELD("signature","char[15]",0,15,SX_SIGNATURE),
};
const sx_layout sxdw_mathcad_header={0x60740001U,"documentwire_mathcad_header",sxdw_mathcad_header_fields,SX_COUNT(sxdw_mathcad_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit0_fields[]={
 SX_FIELD("literal_flag","msb_bits[0,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[1,8]",0,2,SX_NONE),
};
const sx_layout sxdw_mathcad_literal_bit0={0x60740002U,"documentwire_mathcad_literal_bit0",sxdw_mathcad_literal_bit0_fields,SX_COUNT(sxdw_mathcad_literal_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit0_fields[]={
 SX_FIELD("literal_flag","msb_bits[0,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[1,12]",0,2,SX_NONE),
 SX_FIELD("length_code","msb_bits[5,4]",1,2,SX_NONE),
};
const sx_layout sxdw_mathcad_match_bit0={0x60740003U,"documentwire_mathcad_match_bit0",sxdw_mathcad_match_bit0_fields,SX_COUNT(sxdw_mathcad_match_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit0_fields[]={
 SX_FIELD("literal_flag","msb_bits[0,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[1,12]",0,2,SX_NONE),
};
const sx_layout sxdw_mathcad_end_bit0={0x60740004U,"documentwire_mathcad_end_bit0",sxdw_mathcad_end_bit0_fields,SX_COUNT(sxdw_mathcad_end_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit1_fields[]={
 SX_FIELD("literal_flag","msb_bits[1,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[2,8]",0,2,SX_NONE),
};
const sx_layout sxdw_mathcad_literal_bit1={0x60740005U,"documentwire_mathcad_literal_bit1",sxdw_mathcad_literal_bit1_fields,SX_COUNT(sxdw_mathcad_literal_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit1_fields[]={
 SX_FIELD("literal_flag","msb_bits[1,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[2,12]",0,2,SX_NONE),
 SX_FIELD("length_code","msb_bits[6,4]",1,2,SX_NONE),
};
const sx_layout sxdw_mathcad_match_bit1={0x60740006U,"documentwire_mathcad_match_bit1",sxdw_mathcad_match_bit1_fields,SX_COUNT(sxdw_mathcad_match_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit1_fields[]={
 SX_FIELD("literal_flag","msb_bits[1,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[2,12]",0,2,SX_NONE),
};
const sx_layout sxdw_mathcad_end_bit1={0x60740007U,"documentwire_mathcad_end_bit1",sxdw_mathcad_end_bit1_fields,SX_COUNT(sxdw_mathcad_end_bit1_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit2_fields[]={
 SX_FIELD("literal_flag","msb_bits[2,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[3,8]",0,2,SX_NONE),
};
const sx_layout sxdw_mathcad_literal_bit2={0x60740008U,"documentwire_mathcad_literal_bit2",sxdw_mathcad_literal_bit2_fields,SX_COUNT(sxdw_mathcad_literal_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit2_fields[]={
 SX_FIELD("literal_flag","msb_bits[2,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[3,12]",0,2,SX_NONE),
 SX_FIELD("length_code","msb_bits[7,4]",1,2,SX_NONE),
};
const sx_layout sxdw_mathcad_match_bit2={0x60740009U,"documentwire_mathcad_match_bit2",sxdw_mathcad_match_bit2_fields,SX_COUNT(sxdw_mathcad_match_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit2_fields[]={
 SX_FIELD("literal_flag","msb_bits[2,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[3,12]",0,2,SX_NONE),
};
const sx_layout sxdw_mathcad_end_bit2={0x6074000aU,"documentwire_mathcad_end_bit2",sxdw_mathcad_end_bit2_fields,SX_COUNT(sxdw_mathcad_end_bit2_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit3_fields[]={
 SX_FIELD("literal_flag","msb_bits[3,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[4,8]",0,2,SX_NONE),
};
const sx_layout sxdw_mathcad_literal_bit3={0x6074000bU,"documentwire_mathcad_literal_bit3",sxdw_mathcad_literal_bit3_fields,SX_COUNT(sxdw_mathcad_literal_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit3_fields[]={
 SX_FIELD("literal_flag","msb_bits[3,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[4,12]",0,2,SX_NONE),
 SX_FIELD("length_code","msb_bits[0,4]",2,1,SX_NONE),
};
const sx_layout sxdw_mathcad_match_bit3={0x6074000cU,"documentwire_mathcad_match_bit3",sxdw_mathcad_match_bit3_fields,SX_COUNT(sxdw_mathcad_match_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit3_fields[]={
 SX_FIELD("literal_flag","msb_bits[3,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[4,12]",0,2,SX_NONE),
};
const sx_layout sxdw_mathcad_end_bit3={0x6074000dU,"documentwire_mathcad_end_bit3",sxdw_mathcad_end_bit3_fields,SX_COUNT(sxdw_mathcad_end_bit3_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit4_fields[]={
 SX_FIELD("literal_flag","msb_bits[4,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[5,8]",0,2,SX_NONE),
};
const sx_layout sxdw_mathcad_literal_bit4={0x6074000eU,"documentwire_mathcad_literal_bit4",sxdw_mathcad_literal_bit4_fields,SX_COUNT(sxdw_mathcad_literal_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit4_fields[]={
 SX_FIELD("literal_flag","msb_bits[4,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[5,12]",0,3,SX_NONE),
 SX_FIELD("length_code","msb_bits[1,4]",2,1,SX_NONE),
};
const sx_layout sxdw_mathcad_match_bit4={0x6074000fU,"documentwire_mathcad_match_bit4",sxdw_mathcad_match_bit4_fields,SX_COUNT(sxdw_mathcad_match_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit4_fields[]={
 SX_FIELD("literal_flag","msb_bits[4,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[5,12]",0,3,SX_NONE),
};
const sx_layout sxdw_mathcad_end_bit4={0x60740010U,"documentwire_mathcad_end_bit4",sxdw_mathcad_end_bit4_fields,SX_COUNT(sxdw_mathcad_end_bit4_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit5_fields[]={
 SX_FIELD("literal_flag","msb_bits[5,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[6,8]",0,2,SX_NONE),
};
const sx_layout sxdw_mathcad_literal_bit5={0x60740011U,"documentwire_mathcad_literal_bit5",sxdw_mathcad_literal_bit5_fields,SX_COUNT(sxdw_mathcad_literal_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit5_fields[]={
 SX_FIELD("literal_flag","msb_bits[5,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[6,12]",0,3,SX_NONE),
 SX_FIELD("length_code","msb_bits[2,4]",2,1,SX_NONE),
};
const sx_layout sxdw_mathcad_match_bit5={0x60740012U,"documentwire_mathcad_match_bit5",sxdw_mathcad_match_bit5_fields,SX_COUNT(sxdw_mathcad_match_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit5_fields[]={
 SX_FIELD("literal_flag","msb_bits[5,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[6,12]",0,3,SX_NONE),
};
const sx_layout sxdw_mathcad_end_bit5={0x60740013U,"documentwire_mathcad_end_bit5",sxdw_mathcad_end_bit5_fields,SX_COUNT(sxdw_mathcad_end_bit5_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit6_fields[]={
 SX_FIELD("literal_flag","msb_bits[6,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[7,8]",0,2,SX_NONE),
};
const sx_layout sxdw_mathcad_literal_bit6={0x60740014U,"documentwire_mathcad_literal_bit6",sxdw_mathcad_literal_bit6_fields,SX_COUNT(sxdw_mathcad_literal_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit6_fields[]={
 SX_FIELD("literal_flag","msb_bits[6,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[7,12]",0,3,SX_NONE),
 SX_FIELD("length_code","msb_bits[3,4]",2,1,SX_NONE),
};
const sx_layout sxdw_mathcad_match_bit6={0x60740015U,"documentwire_mathcad_match_bit6",sxdw_mathcad_match_bit6_fields,SX_COUNT(sxdw_mathcad_match_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit6_fields[]={
 SX_FIELD("literal_flag","msb_bits[6,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[7,12]",0,3,SX_NONE),
};
const sx_layout sxdw_mathcad_end_bit6={0x60740016U,"documentwire_mathcad_end_bit6",sxdw_mathcad_end_bit6_fields,SX_COUNT(sxdw_mathcad_end_bit6_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_literal_bit7_fields[]={
 SX_FIELD("literal_flag","msb_bits[7,1]",0,1,SX_FLAGS),
 SX_FIELD("literal_byte","msb_bits[0,8]",1,1,SX_NONE),
};
const sx_layout sxdw_mathcad_literal_bit7={0x60740017U,"documentwire_mathcad_literal_bit7",sxdw_mathcad_literal_bit7_fields,SX_COUNT(sxdw_mathcad_literal_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_match_bit7_fields[]={
 SX_FIELD("literal_flag","msb_bits[7,1]",0,1,SX_FLAGS),
 SX_FIELD("ring_position","msb_bits[0,12]",1,2,SX_NONE),
 SX_FIELD("length_code","msb_bits[4,4]",2,1,SX_NONE),
};
const sx_layout sxdw_mathcad_match_bit7={0x60740018U,"documentwire_mathcad_match_bit7",sxdw_mathcad_match_bit7_fields,SX_COUNT(sxdw_mathcad_match_bit7_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_mathcad_end_bit7_fields[]={
 SX_FIELD("literal_flag","msb_bits[7,1]",0,1,SX_FLAGS),
 SX_FIELD("end_position","msb_bits[0,12]",1,2,SX_NONE),
};
const sx_layout sxdw_mathcad_end_bit7={0x60740019U,"documentwire_mathcad_end_bit7",sxdw_mathcad_end_bit7_fields,SX_COUNT(sxdw_mathcad_end_bit7_fields),SX_LE};
static bool sxdw_take_bits(sxdw_cursor*q,uint64_t*bit,unsigned width,uint64_t*v)
{if(*bit>(uint64_t)q->n*8||width>(uint64_t)q->n*8-*bit)return false;*v=0;for(unsigned i=0;i<width;i++){uint64_t b=(*bit)++;*v=(*v<<1)|((q->b[b/8]>>(7-b%8))&1U);}return true;}
static bool sxdw_mathcad(sxdw_cursor*q)
{
 if(q->n<16||xx_rt_memcmp(q->b,".MCDCOMPRESSION",15)||!sxdw_emit(q,&sxdw_mathcad_header,0,15))return false;
 const sx_layout*literal[]={&sxdw_mathcad_literal_bit0,&sxdw_mathcad_literal_bit1,&sxdw_mathcad_literal_bit2,&sxdw_mathcad_literal_bit3,&sxdw_mathcad_literal_bit4,&sxdw_mathcad_literal_bit5,&sxdw_mathcad_literal_bit6,&sxdw_mathcad_literal_bit7};
 const sx_layout*match[]={&sxdw_mathcad_match_bit0,&sxdw_mathcad_match_bit1,&sxdw_mathcad_match_bit2,&sxdw_mathcad_match_bit3,&sxdw_mathcad_match_bit4,&sxdw_mathcad_match_bit5,&sxdw_mathcad_match_bit6,&sxdw_mathcad_match_bit7};
 const sx_layout*stop[]={&sxdw_mathcad_end_bit0,&sxdw_mathcad_end_bit1,&sxdw_mathcad_end_bit2,&sxdw_mathcad_end_bit3,&sxdw_mathcad_end_bit4,&sxdw_mathcad_end_bit5,&sxdw_mathcad_end_bit6,&sxdw_mathcad_end_bit7};
 uint64_t bit=120;while(q->c->count<32000){if(xx_pd_is_stopped(q->c->pd))return false;uint64_t start=bit,flag,pos,n;const sx_layout*l;bool ended=false;
  if(!sxdw_take_bits(q,&bit,1,&flag))break;if(flag){if(!sxdw_take_bits(q,&bit,8,&n))break;l=literal[start%8];}
  else{if(!sxdw_take_bits(q,&bit,12,&pos))break;if(!pos){l=stop[start%8];ended=true;}else{if(!sxdw_take_bits(q,&bit,4,&n))break;l=match[start%8];}}
  if(!sxdw_emit(q,l,(int64_t)(start/8),(int64_t)((bit+7)/8-start/8)))return false;if(ended)return true;
 }return true;
}
bool sx_mathcad_build(sxdw_cursor*q)
{
 return sxdw_mathcad(q);
}
