/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * fromsoftware_binder data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_bnd3_header_le_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","char[8]",4,8,SX_STRING),
 SX_FIELD("format_bits","uint8",12,1,SX_FLAGS),
 SX_FIELD("big_endian","uint8",13,1,SX_FLAGS),
 SX_FIELD("bit_big_endian","uint8",14,1,SX_FLAGS),
 SX_FIELD("reserved","uint8",15,1,SX_RESERVED),
 SX_FIELD("file_count","int32",16,4,SX_COUNT_PROP),
 SX_FIELD("headers_end","int32",20,4,SX_OFFSET),
 SX_FIELD("unknown18","uint32",24,4,SX_NONE),
 SX_FIELD("reserved_tail","uint32",28,4,SX_RESERVED),
};
const sx_layout sxgp_bnd3_header_le={UINT32_C(0x60360045),"bnd3_header_le",sxgp_bnd3_header_le_fields,SX_COUNT(sxgp_bnd3_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd4_header_le_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("unknown04","uint8",4,1,SX_NONE),
 SX_FIELD("unknown05","uint8",5,1,SX_NONE),
 SX_FIELD("reserved","bytes",6,3,SX_RESERVED),
 SX_FIELD("big_endian","uint8",9,1,SX_FLAGS),
 SX_FIELD("reversed_bit_order","uint8",10,1,SX_FLAGS),
 SX_FIELD("reserved2","uint8",11,1,SX_RESERVED),
 SX_FIELD("file_count","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("header_size","int64",16,8,SX_SIZE),
 SX_FIELD("version","char[8]",24,8,SX_STRING),
 SX_FIELD("entry_size","int64",32,8,SX_SIZE),
 SX_FIELD("headers_end","int64",40,8,SX_OFFSET),
 SX_FIELD("unicode_names","uint8",48,1,SX_FLAGS),
 SX_FIELD("format_bits","uint8",49,1,SX_FLAGS),
 SX_FIELD("extended","uint8",50,1,SX_FLAGS),
 SX_FIELD("reserved3","uint8",51,1,SX_RESERVED),
 SX_FIELD("reserved4","uint32",52,4,SX_RESERVED),
 SX_FIELD("hash_table_offset","int64",56,8,SX_OFFSET),
};
const sx_layout sxgp_bnd4_header_le={UINT32_C(0x60360046),"bnd4_header_le",sxgp_bnd4_header_le_fields,SX_COUNT(sxgp_bnd4_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd3_entry_le_fields[]={
 SX_FIELD("file_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved","bytes",1,3,SX_RESERVED),
 SX_FIELD("compressed_size","int32",4,4,SX_SIZE),
};
const sx_layout sxgp_bnd3_entry_le={UINT32_C(0x60360047),"bnd3_entry_le",sxgp_bnd3_entry_le_fields,SX_COUNT(sxgp_bnd3_entry_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd4_entry_le_fields[]={
 SX_FIELD("file_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved","bytes",1,3,SX_RESERVED),
 SX_FIELD("sentinel","int32",4,4,SX_NONE),
 SX_FIELD("compressed_size","int64",8,8,SX_SIZE),
};
const sx_layout sxgp_bnd4_entry_le={UINT32_C(0x60360048),"bnd4_entry_le",sxgp_bnd4_entry_le_fields,SX_COUNT(sxgp_bnd4_entry_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd_offset32_le_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxgp_bnd_offset32_le={UINT32_C(0x60360049),"bnd_offset32_le",sxgp_bnd_offset32_le_fields,SX_COUNT(sxgp_bnd_offset32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd_offset64_le_fields[]={
 SX_FIELD("data_offset","int64",0,8,SX_OFFSET),
};
const sx_layout sxgp_bnd_offset64_le={UINT32_C(0x6036004A),"bnd_offset64_le",sxgp_bnd_offset64_le_fields,SX_COUNT(sxgp_bnd_offset64_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd_id_le_fields[]={
 SX_FIELD("file_id","int32",0,4,SX_ID),
};
const sx_layout sxgp_bnd_id_le={UINT32_C(0x6036004B),"bnd_id_le",sxgp_bnd_id_le_fields,SX_COUNT(sxgp_bnd_id_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd3_name_le_fields[]={
 SX_FIELD("name_offset","int32",0,4,SX_OFFSET),
};
const sx_layout sxgp_bnd3_name_le={UINT32_C(0x6036004C),"bnd3_name_le",sxgp_bnd3_name_le_fields,SX_COUNT(sxgp_bnd3_name_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd4_name_le_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxgp_bnd4_name_le={UINT32_C(0x6036004D),"bnd4_name_le",sxgp_bnd4_name_le_fields,SX_COUNT(sxgp_bnd4_name_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd_raw32_le_fields[]={
 SX_FIELD("uncompressed_size","int32",0,4,SX_SIZE),
};
const sx_layout sxgp_bnd_raw32_le={UINT32_C(0x6036004E),"bnd_raw32_le",sxgp_bnd_raw32_le_fields,SX_COUNT(sxgp_bnd_raw32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd_raw64_le_fields[]={
 SX_FIELD("uncompressed_size","int64",0,8,SX_SIZE),
};
const sx_layout sxgp_bnd_raw64_le={UINT32_C(0x6036004F),"bnd_raw64_le",sxgp_bnd_raw64_le_fields,SX_COUNT(sxgp_bnd_raw64_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd4_names_extra_le_fields[]={
 SX_FIELD("unknown_value","int32",0,4,SX_NONE),
 SX_FIELD("reserved","int32",4,4,SX_RESERVED),
};
const sx_layout sxgp_bnd4_names_extra_le={UINT32_C(0x60360050),"bnd4_names_extra_le",sxgp_bnd4_names_extra_le_fields,SX_COUNT(sxgp_bnd4_names_extra_le_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_bnd3_header_be_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","char[8]",4,8,SX_STRING),
 SX_FIELD("format_bits","uint8",12,1,SX_FLAGS),
 SX_FIELD("big_endian","uint8",13,1,SX_FLAGS),
 SX_FIELD("bit_big_endian","uint8",14,1,SX_FLAGS),
 SX_FIELD("reserved","uint8",15,1,SX_RESERVED),
 SX_FIELD("file_count","int32",16,4,SX_COUNT_PROP),
 SX_FIELD("headers_end","int32",20,4,SX_OFFSET),
 SX_FIELD("unknown18","uint32",24,4,SX_NONE),
 SX_FIELD("reserved_tail","uint32",28,4,SX_RESERVED),
};
const sx_layout sxgp_bnd3_header_be={UINT32_C(0x60360051),"bnd3_header_be",sxgp_bnd3_header_be_fields,SX_COUNT(sxgp_bnd3_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd4_header_be_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("unknown04","uint8",4,1,SX_NONE),
 SX_FIELD("unknown05","uint8",5,1,SX_NONE),
 SX_FIELD("reserved","bytes",6,3,SX_RESERVED),
 SX_FIELD("big_endian","uint8",9,1,SX_FLAGS),
 SX_FIELD("reversed_bit_order","uint8",10,1,SX_FLAGS),
 SX_FIELD("reserved2","uint8",11,1,SX_RESERVED),
 SX_FIELD("file_count","int32",12,4,SX_COUNT_PROP),
 SX_FIELD("header_size","int64",16,8,SX_SIZE),
 SX_FIELD("version","char[8]",24,8,SX_STRING),
 SX_FIELD("entry_size","int64",32,8,SX_SIZE),
 SX_FIELD("headers_end","int64",40,8,SX_OFFSET),
 SX_FIELD("unicode_names","uint8",48,1,SX_FLAGS),
 SX_FIELD("format_bits","uint8",49,1,SX_FLAGS),
 SX_FIELD("extended","uint8",50,1,SX_FLAGS),
 SX_FIELD("reserved3","uint8",51,1,SX_RESERVED),
 SX_FIELD("reserved4","uint32",52,4,SX_RESERVED),
 SX_FIELD("hash_table_offset","int64",56,8,SX_OFFSET),
};
const sx_layout sxgp_bnd4_header_be={UINT32_C(0x60360052),"bnd4_header_be",sxgp_bnd4_header_be_fields,SX_COUNT(sxgp_bnd4_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd3_entry_be_fields[]={
 SX_FIELD("file_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved","bytes",1,3,SX_RESERVED),
 SX_FIELD("compressed_size","int32",4,4,SX_SIZE),
};
const sx_layout sxgp_bnd3_entry_be={UINT32_C(0x60360053),"bnd3_entry_be",sxgp_bnd3_entry_be_fields,SX_COUNT(sxgp_bnd3_entry_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd4_entry_be_fields[]={
 SX_FIELD("file_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved","bytes",1,3,SX_RESERVED),
 SX_FIELD("sentinel","int32",4,4,SX_NONE),
 SX_FIELD("compressed_size","int64",8,8,SX_SIZE),
};
const sx_layout sxgp_bnd4_entry_be={UINT32_C(0x60360054),"bnd4_entry_be",sxgp_bnd4_entry_be_fields,SX_COUNT(sxgp_bnd4_entry_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd_offset32_be_fields[]={
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxgp_bnd_offset32_be={UINT32_C(0x60360055),"bnd_offset32_be",sxgp_bnd_offset32_be_fields,SX_COUNT(sxgp_bnd_offset32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd_offset64_be_fields[]={
 SX_FIELD("data_offset","int64",0,8,SX_OFFSET),
};
const sx_layout sxgp_bnd_offset64_be={UINT32_C(0x60360056),"bnd_offset64_be",sxgp_bnd_offset64_be_fields,SX_COUNT(sxgp_bnd_offset64_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd_id_be_fields[]={
 SX_FIELD("file_id","int32",0,4,SX_ID),
};
const sx_layout sxgp_bnd_id_be={UINT32_C(0x60360057),"bnd_id_be",sxgp_bnd_id_be_fields,SX_COUNT(sxgp_bnd_id_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd3_name_be_fields[]={
 SX_FIELD("name_offset","int32",0,4,SX_OFFSET),
};
const sx_layout sxgp_bnd3_name_be={UINT32_C(0x60360058),"bnd3_name_be",sxgp_bnd3_name_be_fields,SX_COUNT(sxgp_bnd3_name_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd4_name_be_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxgp_bnd4_name_be={UINT32_C(0x60360059),"bnd4_name_be",sxgp_bnd4_name_be_fields,SX_COUNT(sxgp_bnd4_name_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd_raw32_be_fields[]={
 SX_FIELD("uncompressed_size","int32",0,4,SX_SIZE),
};
const sx_layout sxgp_bnd_raw32_be={UINT32_C(0x6036005A),"bnd_raw32_be",sxgp_bnd_raw32_be_fields,SX_COUNT(sxgp_bnd_raw32_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd_raw64_be_fields[]={
 SX_FIELD("uncompressed_size","int64",0,8,SX_SIZE),
};
const sx_layout sxgp_bnd_raw64_be={UINT32_C(0x6036005B),"bnd_raw64_be",sxgp_bnd_raw64_be_fields,SX_COUNT(sxgp_bnd_raw64_be_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_bnd4_names_extra_be_fields[]={
 SX_FIELD("unknown_value","int32",0,4,SX_NONE),
 SX_FIELD("reserved","int32",4,4,SX_RESERVED),
};
const sx_layout sxgp_bnd4_names_extra_be={UINT32_C(0x6036005C),"bnd4_names_extra_be",sxgp_bnd4_names_extra_be_fields,SX_COUNT(sxgp_bnd4_names_extra_be_fields),SX_BE};
static uint8_t sxgp_reverse(uint8_t b){b=(uint8_t)((b>>4)|(b<<4));b=(uint8_t)(((b&204)>>2)|((b&51)<<2));return(uint8_t)(((b&170)>>1)|((b&85)<<1));}
static bool sxgp_binder(sxgp_view*v)
{uint8_t h[64];uint64_t end=(uint64_t)v->c->size,n,entry,p;bool four,be,bitbe;unsigned fmt;if(!sxgp_read(v,0,h,32,end))return false;four=h[3]=='4';if(four){if(!sxgp_read(v,0,h,64,end))return false;be=h[9]!=0;bitbe=!h[10];fmt=bitbe||((h[49]&1)&&!(h[49]&128))?h[49]:sxgp_reverse(h[49]);n=xx_data_get_u32(h+12,4,0,be);entry=16+((fmt&16)?8:4)+((fmt&32)?8:0)+((fmt&2)?4:0)+((fmt&12)?4:0)+(fmt==4?8:0);p=64;}
 else{bitbe=h[14]!=0;fmt=bitbe||((h[12]&1)&&!(h[12]&128))?h[12]:sxgp_reverse(h[12]);be=h[13]||(fmt&1);n=xx_data_get_u32(h+16,4,0,be);entry=8+((fmt&16)?8:4)+((fmt&2)?4:0)+((fmt&12)?4:0)+((fmt&32)?4:0);p=32;}
 const sx_layout*header=four?(be?&sxgp_bnd4_header_be:&sxgp_bnd4_header_le):(be?&sxgp_bnd3_header_be:&sxgp_bnd3_header_le);
 if(n>65536||!sxgp_row(v,header,0,end)||!sxgp_span(v,p,n*entry,end))return false;
 for(uint64_t i=0;i<n;i++){uint64_t stop=p+entry;const sx_layout*prefix=four?(be?&sxgp_bnd4_entry_be:&sxgp_bnd4_entry_le):(be?&sxgp_bnd3_entry_be:&sxgp_bnd3_entry_le);if(!sxgp_row(v,prefix,p,stop))return false;p+=four?16:8;
  if(four&&(fmt&32)){if(!sxgp_row(v,be?&sxgp_bnd_raw64_be:&sxgp_bnd_raw64_le,p,stop))return false;p+=8;}
  if(!sxgp_row(v,fmt&16?(be?&sxgp_bnd_offset64_be:&sxgp_bnd_offset64_le):(be?&sxgp_bnd_offset32_be:&sxgp_bnd_offset32_le),p,stop))return false;p+=fmt&16?8:4;
  if(fmt&2){if(!sxgp_row(v,be?&sxgp_bnd_id_be:&sxgp_bnd_id_le,p,stop))return false;p+=4;}
  if(fmt&12){if(!sxgp_row(v,four?(be?&sxgp_bnd4_name_be:&sxgp_bnd4_name_le):(be?&sxgp_bnd3_name_be:&sxgp_bnd3_name_le),p,stop))return false;p+=4;}
  if(!four&&(fmt&32)){if(!sxgp_row(v,be?&sxgp_bnd_raw32_be:&sxgp_bnd_raw32_le,p,stop))return false;p+=4;}
  if(four&&fmt==4){if(!sxgp_row(v,be?&sxgp_bnd4_names_extra_be:&sxgp_bnd4_names_extra_le,p,stop))return false;p+=8;}
  if(p!=stop)return false;
 }return true;}
bool sx_fromsoftware_binder_build(sxgp_view*v)
{
 return sxgp_binder(v);
}
