/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * safetensors data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxtw_json_key_fields[]={
 SX_FIELD("json_key","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_json_key={0x6071001aU,"textwire_json_key",sxtw_json_key_fields,SX_COUNT(sxtw_json_key_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_json_string_fields[]={
 SX_FIELD("json_string","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_json_string={0x6071001bU,"textwire_json_string",sxtw_json_string_fields,SX_COUNT(sxtw_json_string_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_tensor_dtype_fields[]={
 SX_FIELD("tensor_dtype","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_tensor_dtype={0x6071001cU,"textwire_tensor_dtype",sxtw_tensor_dtype_fields,SX_COUNT(sxtw_tensor_dtype_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_shape_dimension_fields[]={
 SX_FIELD("shape_dimension","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxtw_shape_dimension={0x60710031U,"textwire_shape_dimension",sxtw_shape_dimension_fields,SX_COUNT(sxtw_shape_dimension_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_tensor_data_offset_fields[]={
 SX_FIELD("tensor_data_offset","ascii_signed",0,0,SX_OFFSET),
};
const sx_layout sxtw_tensor_data_offset={0x60710041U,"textwire_tensor_data_offset",sxtw_tensor_data_offset_fields,SX_COUNT(sxtw_tensor_data_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_safetensors_header_fields[]={
 SX_FIELD("json_header_bytes","uint64le",0,8,SX_SIZE),
};
const sx_layout sxtw_safetensors_header={0x60710049U,"textwire_safetensors_header",sxtw_safetensors_header_fields,SX_COUNT(sxtw_safetensors_header_fields),SX_LE};
#define TW_EMIT(n,a,z) do{if(!sxtw_emit(q,&sxtw_##n,(a),(z)))return false;}while(0)
/* Match semantic ASCII JSON member names while preserving their source spelling. */
static bool sxtw_json_key_matches(sxtw_cursor*q,int64_t a,int64_t n,const char*want)
{
 size_t k=0;int64_t end=a+n;while(a<end){unsigned c=q->b[a++];if(c=='\\'){if(a==end)return false;c=q->b[a++];if(c=='u'){uint64_t v;if(end-a<4||!sxtw_number(q,a,4,16,&v)||v>127)return false;c=(unsigned)v;a+=4;}else if(c=='b')c=8;else if(c=='f')c=12;else if(c=='n')c=10;else if(c=='r')c=13;else if(c=='t')c=9;else if(c!='"'&&c!='\\'&&c!='/')return false;}if(!want[k]||(unsigned char)want[k++]!=c)return false;}return want[k]==0;
}
static bool sxtw_safetensors(sxtw_cursor*q)
{
 if(q->n<8)return false;uint64_t n=xx_data_get_u64(q->b,8,0,false);if(n>(uint64_t)q->n-8||n>1048576)return false;TW_EMIT(safetensors_header,0,8);int64_t p=8,end=8+(int64_t)n;unsigned depth=0,array=0;bool metadata=false;const sx_layout*number=&sxtw_integer_value;const sx_layout*string=&sxtw_json_string;
 while(p<end){if(q->c->count>=32000)return true;if(xx_pd_is_stopped(q->c->pd))return false;unsigned c=q->b[p];
  if(c=='"'){int64_t a=++p;while(p<end&&q->b[p]!='"'){if(q->b[p]=='\\'){if(++p==end)return false;}p++;}if(p==end)return false;int64_t z=p-a;p++;int64_t next=p;while(next<end&&sxtw_space(q->b[next]))next++;bool key=next<end&&q->b[next]==':';if(key){TW_EMIT(json_key,a,z);number=&sxtw_integer_value;string=&sxtw_json_string;if(depth==1)metadata=sxtw_json_key_matches(q,a,z,"__metadata__");if(depth==2&&!metadata){if(sxtw_json_key_matches(q,a,z,"data_offsets"))number=&sxtw_tensor_data_offset;else if(sxtw_json_key_matches(q,a,z,"shape"))number=&sxtw_shape_dimension;else if(sxtw_json_key_matches(q,a,z,"dtype"))string=&sxtw_tensor_dtype;}}else if(!sxtw_emit(q,string,a,z))return false;continue;}
  if(c=='{'){depth++;p++;continue;}if(c=='}'){if(!depth)return false;depth--;number=&sxtw_integer_value;string=&sxtw_json_string;p++;continue;}if(c=='['){array++;p++;continue;}if(c==']'){if(!array)return false;array--;p++;continue;}
  if(c>='0'&&c<='9'){int64_t a=p;while(p<end&&q->b[p]>='0'&&q->b[p]<='9')p++;if(!sxtw_emit(q,number,a,p-a))return false;continue;}
  if(c==':'||c==','||sxtw_space(c)){p++;continue;}return false;
 }return depth==0&&array==0;
}
bool sx_safetensors_build(sxtw_cursor*q)
{
 return sxtw_safetensors(q);
}
#undef TW_EMIT
