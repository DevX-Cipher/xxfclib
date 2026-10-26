/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * hp3000 wrq data structures, moved out of the documentwire schema family. */
#include "../../xx_format_schema_documentwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdw_wrq_record_size_fields[]={
 SX_FIELD("wrq_record_size","ascii_signed",0,0,SX_SIZE),
};
const sx_layout sxdw_wrq_record_size={0x60740027U,"documentwire_wrq_record_size",sxdw_wrq_record_size_fields,SX_COUNT(sxdw_wrq_record_size_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_wrq_block_factor_fields[]={
 SX_FIELD("wrq_block_factor","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxdw_wrq_block_factor={0x60740028U,"documentwire_wrq_block_factor",sxdw_wrq_block_factor_fields,SX_COUNT(sxdw_wrq_block_factor_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_wrq_file_code_fields[]={
 SX_FIELD("wrq_file_code","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxdw_wrq_file_code={0x60740029U,"documentwire_wrq_file_code",sxdw_wrq_file_code_fields,SX_COUNT(sxdw_wrq_file_code_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_wrq_extents_fields[]={
 SX_FIELD("wrq_extents","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxdw_wrq_extents={0x6074002aU,"documentwire_wrq_extents",sxdw_wrq_extents_fields,SX_COUNT(sxdw_wrq_extents_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_wrq_record_count_fields[]={
 SX_FIELD("wrq_record_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxdw_wrq_record_count={0x6074002bU,"documentwire_wrq_record_count",sxdw_wrq_record_count_fields,SX_COUNT(sxdw_wrq_record_count_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_wrq_format_fields[]={
 SX_FIELD("format","char[1]",0,1,SX_ID),
};
const sx_layout sxdw_wrq_format={0x6074002fU,"documentwire_wrq_format",sxdw_wrq_format_fields,SX_COUNT(sxdw_wrq_format_fields),SX_LE};
static bool sxdw_wrq(sxdw_cursor*q)
{
 const char*keys[]={"RECSIZE=","BLOCKFACTOR=","CODE=","EXTENTS=","FILESIZE=","FORMAT="};
 const sx_layout*fields[]={&sxdw_wrq_record_size,&sxdw_wrq_block_factor,&sxdw_wrq_file_code,&sxdw_wrq_extents,&sxdw_wrq_record_count};
 for(unsigned i=0;i<6;i++){size_t k=xx_rt_strlen(keys[i]);if(!sxdw_prefix(q,q->p,q->n,keys[i]))return false;q->p+=(int64_t)k;if(i==5)return sxdw_emit(q,&sxdw_wrq_format,q->p,1);
  int64_t a=q->p;while(q->p<q->n&&q->b[q->p]>='0'&&q->b[q->p]<='9')q->p++;uint64_t value;if(!sxdw_decimal(q,a,q->p,&value)||!sxdw_value(q,fields[i],a,q->p-a)||q->p>=q->n||q->b[q->p++]!=';')return false;
 }return true;
}
bool sx_hp3000_wrq_build(sxdw_cursor*q)
{
 return sxdw_wrq(q);
}
