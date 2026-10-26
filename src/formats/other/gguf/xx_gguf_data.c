/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * gguf data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_gguf_header_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("tensor_count","uint64",8,8,SX_COUNT_PROP),
 SX_FIELD("metadata_count","uint64",16,8,SX_COUNT_PROP),
};
const sx_layout sxbx_gguf_header = {UINT32_C(0x6030008b),"gguf_header",sxbx_gguf_header_fields,SX_COUNT(sxbx_gguf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_string_size_fields[] = {
 SX_FIELD("utf8_size","uint64",0,8,SX_SIZE),
};
const sx_layout sxbx_gguf_string_size = {UINT32_C(0x6030008c),"gguf_string_size",sxbx_gguf_string_size_fields,SX_COUNT(sxbx_gguf_string_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value_type_fields[] = {
 SX_FIELD("type","uint32",0,4,SX_ID),
};
const sx_layout sxbx_gguf_value_type = {UINT32_C(0x6030008d),"gguf_value_type",sxbx_gguf_value_type_fields,SX_COUNT(sxbx_gguf_value_type_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_array_fields[] = {
 SX_FIELD("element_type","uint32",0,4,SX_ID),
 SX_FIELD("element_count","uint64",4,8,SX_COUNT_PROP),
};
const sx_layout sxbx_gguf_array = {UINT32_C(0x6030008e),"gguf_array",sxbx_gguf_array_fields,SX_COUNT(sxbx_gguf_array_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value0_fields[] = {
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
const sx_layout sxbx_gguf_value0 = {UINT32_C(0x6030008f),"gguf_value0",sxbx_gguf_value0_fields,SX_COUNT(sxbx_gguf_value0_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value1_fields[] = {
 SX_FIELD("value","int8",0,1,SX_NONE),
};
const sx_layout sxbx_gguf_value1 = {UINT32_C(0x60300090),"gguf_value1",sxbx_gguf_value1_fields,SX_COUNT(sxbx_gguf_value1_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value2_fields[] = {
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
const sx_layout sxbx_gguf_value2 = {UINT32_C(0x60300091),"gguf_value2",sxbx_gguf_value2_fields,SX_COUNT(sxbx_gguf_value2_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value3_fields[] = {
 SX_FIELD("value","int16",0,2,SX_NONE),
};
const sx_layout sxbx_gguf_value3 = {UINT32_C(0x60300092),"gguf_value3",sxbx_gguf_value3_fields,SX_COUNT(sxbx_gguf_value3_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value4_fields[] = {
 SX_FIELD("value","uint32",0,4,SX_NONE),
};
const sx_layout sxbx_gguf_value4 = {UINT32_C(0x60300093),"gguf_value4",sxbx_gguf_value4_fields,SX_COUNT(sxbx_gguf_value4_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value5_fields[] = {
 SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxbx_gguf_value5 = {UINT32_C(0x60300094),"gguf_value5",sxbx_gguf_value5_fields,SX_COUNT(sxbx_gguf_value5_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value6_fields[] = {
 SX_FIELD("value","float32",0,4,SX_NONE),
};
const sx_layout sxbx_gguf_value6 = {UINT32_C(0x60300095),"gguf_value6",sxbx_gguf_value6_fields,SX_COUNT(sxbx_gguf_value6_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value7_fields[] = {
 SX_FIELD("value","uint8",0,1,SX_NONE),
};
const sx_layout sxbx_gguf_value7 = {UINT32_C(0x60300096),"gguf_value7",sxbx_gguf_value7_fields,SX_COUNT(sxbx_gguf_value7_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value10_fields[] = {
 SX_FIELD("value","uint64",0,8,SX_NONE),
};
const sx_layout sxbx_gguf_value10 = {UINT32_C(0x60300097),"gguf_value10",sxbx_gguf_value10_fields,SX_COUNT(sxbx_gguf_value10_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value11_fields[] = {
 SX_FIELD("value","int64",0,8,SX_NONE),
};
const sx_layout sxbx_gguf_value11 = {UINT32_C(0x60300098),"gguf_value11",sxbx_gguf_value11_fields,SX_COUNT(sxbx_gguf_value11_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_value12_fields[] = {
 SX_FIELD("value","float64",0,8,SX_NONE),
};
const sx_layout sxbx_gguf_value12 = {UINT32_C(0x60300099),"gguf_value12",sxbx_gguf_value12_fields,SX_COUNT(sxbx_gguf_value12_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_dimensions_fields[] = {
 SX_FIELD("dimension_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxbx_gguf_dimensions = {UINT32_C(0x6030009a),"gguf_dimensions",sxbx_gguf_dimensions_fields,SX_COUNT(sxbx_gguf_dimensions_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_dimension_fields[] = {
 SX_FIELD("dimension","uint64",0,8,SX_COUNT_PROP),
};
const sx_layout sxbx_gguf_dimension = {UINT32_C(0x6030009b),"gguf_dimension",sxbx_gguf_dimension_fields,SX_COUNT(sxbx_gguf_dimension_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_gguf_tensor_storage_fields[] = {
 SX_FIELD("tensor_type","uint32",0,4,SX_ID),
 SX_FIELD("data_offset","uint64",4,8,SX_OFFSET),
};
const sx_layout sxbx_gguf_tensor_storage = {UINT32_C(0x6030009c),"gguf_tensor_storage",sxbx_gguf_tensor_storage_fields,SX_COUNT(sxbx_gguf_tensor_storage_fields),SX_LE};
#define SXBX_LIMIT 20000U
static bool sxbx_gg_value(sx_context*c,uint64_t*p,uint64_t end,unsigned type,unsigned depth){static const sx_layout*const ls[]={&sxbx_gguf_value0,&sxbx_gguf_value1,&sxbx_gguf_value2,&sxbx_gguf_value3,&sxbx_gguf_value4,&sxbx_gguf_value5,&sxbx_gguf_value6,&sxbx_gguf_value7,NULL,NULL,&sxbx_gguf_value10,&sxbx_gguf_value11,&sxbx_gguf_value12};static const unsigned widths[]={1,1,2,2,4,4,4,1,0,0,8,8,8};if(type>12||depth>1||c->count>=SXBX_LIMIT)return false;if(type==8)return sxbx_counted(c,p,end,&sxbx_gguf_string_size,8,false,1);if(type==9){uint64_t item,n;if(*p>end||end-*p<12||!sxbx_word(c,*p,4,false,&item)||item>12||item==9||!sxbx_word(c,*p+4,8,false,&n)||n>4096||!sxbx_add(c,&sxbx_gguf_array,*p))return false;*p+=12;for(uint64_t i=0;i<n;i++)if(!sxbx_gg_value(c,p,end,(unsigned)item,depth+1))return false;return true;}if(*p>end||widths[type]>end-*p||!sxbx_add(c,ls[type],*p))return false;*p+=widths[type];return true;}
static bool sxbx_gguf(sx_context*c){uint64_t nt,nk,p=24,end=(uint64_t)c->size;if(!sxbx_add(c,&sxbx_gguf_header,0)||!sxbx_word(c,8,8,false,&nt)||!sxbx_word(c,16,8,false,&nk)||nt>1024||nk>1024)return false;for(uint64_t i=0;i<nk&&c->count<SXBX_LIMIT;i++){uint64_t t;if(!sxbx_counted(c,&p,end,&sxbx_gguf_string_size,8,false,1)||end-p<4||!sxbx_word(c,p,4,false,&t)||!sxbx_add(c,&sxbx_gguf_value_type,p))return true;p+=4;if(!sxbx_gg_value(c,&p,end,(unsigned)t,0))return true;}for(uint64_t i=0;i<nt&&c->count<SXBX_LIMIT;i++){uint64_t n;if(!sxbx_counted(c,&p,end,&sxbx_gguf_string_size,8,false,1)||end-p<4||!sxbx_word(c,p,4,false,&n)||n<1||n>4||!sxbx_add(c,&sxbx_gguf_dimensions,p))break;p+=4;if(n>(end-p)/8||!sxbx_table(c,&sxbx_gguf_dimension,p,n))break;p+=n*8;if(end-p<12||!sxbx_add(c,&sxbx_gguf_tensor_storage,p))break;p+=12;}return true;}
bool sx_gguf_build(sx_context*c)
{
 return sxbx_gguf(c);
}
