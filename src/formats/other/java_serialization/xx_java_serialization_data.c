/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * java serialization data structures, moved out of the binarylater schema family. */
#include "../../xx_format_schema_binarylater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbl_java_tag_fields[] = {
 SX_FIELD("type_and_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxbl_java_tag = {UINT32_C(0x60350040),"java_tag",sxbl_java_tag_fields,SX_COUNT(sxbl_java_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_java_stream_fields[] = {
 SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("version","uint16",2,2,SX_ID),
};
const sx_layout sxbl_java_stream = {UINT32_C(0x603500e4),"java_stream",sxbl_java_stream_fields,SX_COUNT(sxbl_java_stream_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_java_handle_fields[] = {
 SX_FIELD("wire_handle","uint32",0,4,SX_ID),
};
const sx_layout sxbl_java_handle = {UINT32_C(0x603500e5),"java_handle",sxbl_java_handle_fields,SX_COUNT(sxbl_java_handle_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_java_array_count_fields[] = {
 SX_FIELD("element_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxbl_java_array_count = {UINT32_C(0x603500e6),"java_array_count",sxbl_java_array_count_fields,SX_COUNT(sxbl_java_array_count_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_java_class_fields_fields[] = {
 SX_FIELD("serial_version_uid","int64",0,8,SX_ID),
 SX_FIELD("flags","uint8",8,1,SX_FLAGS),
 SX_FIELD("field_count","uint16",9,2,SX_COUNT_PROP),
};
const sx_layout sxbl_java_class_fields = {UINT32_C(0x603500e7),"java_class_fields",sxbl_java_class_fields_fields,SX_COUNT(sxbl_java_class_fields_fields),SX_BE};
typedef struct sxbl_java_state{sx_context*c;uint8_t types[4096];unsigned count;}sxbl_java_state;
static bool sxbl_java_reserve(sxbl_java_state*j,uint8_t kind){if(j->count>=4096)return false;j->types[j->count++]=kind;return true;}
static bool sxbl_java_class(sxbl_java_state*j,uint64_t*p,uint64_t end,uint8_t*kind){sx_context*c=j->c;uint8_t t;uint64_t n;if(!sxbl_byte(c,*p,&t)||!sxbl_emit(c,p,end,&sxbl_java_tag))return false;if(t==0x71){if(!sxbl_word(c,*p,4,true,&n)||!sxbl_emit(c,p,end,&sxbl_java_handle)||n<0x7e0000||n-0x7e0000>=j->count)return false;*kind=j->types[n-0x7e0000];return *kind!=0;}
 if(t!=0x72||!sxbl_length(c,p,end,2,true,false,&n)||n<2||!sxbl_byte(c,*p+1,kind)||!sxbl_skip(c,p,end,n)||!sxbl_java_reserve(j,*kind)||!sxbl_emit(c,p,end,&sxbl_java_class_fields)||!sxbl_emit(c,p,end,&sxbl_java_tag)||!sxbl_emit(c,p,end,&sxbl_java_tag))return false;return true;}
static bool sxbl_java_value(sxbl_java_state*j,uint64_t*p,uint64_t end,unsigned depth){sx_context*c=j->c;uint8_t t;uint64_t n;if(depth>32||!sxbl_byte(c,*p,&t)||!sxbl_emit(c,p,end,&sxbl_java_tag))return false;if(t==0x70)return true;if(t==0x71)return sxbl_emit(c,p,end,&sxbl_java_handle);if(t==0x74||t==0x7c)return sxbl_string(c,p,end,t==0x74?2:8,true)&&sxbl_java_reserve(j,0);uint8_t kind;if(t!=0x75||!sxbl_java_class(j,p,end,&kind)||!sxbl_word(c,*p,4,true,&n)||!sxbl_emit(c,p,end,&sxbl_java_array_count)||n>65536||!sxbl_java_reserve(j,0))return false;
 if(kind=='L'){for(uint64_t i=0;i<n;i++)if(!sxbl_java_value(j,p,end,depth+1))return false;return true;}unsigned z=kind=='B'||kind=='Z'?1:kind=='C'||kind=='S'?2:kind=='F'||kind=='I'?4:kind=='D'||kind=='J'?8:0;if(!z||*p>end||n>(end-*p)/z)return false;for(uint64_t i=0;i<n;i++)if(kind=='F'||kind=='D'){if(!sxbl_float(c,p,end,z,true))return false;}else if(!sxbl_numeric(c,p,end,z,kind!='C'&&kind!='Z',true))return false;return true;}
static bool sxbl_java(sx_context*c){sxbl_java_state j;xx_rt_memset(&j,0,sizeof(j));j.c=c;uint64_t p=0,end=(uint64_t)c->size;if(!sxbl_emit(c,&p,end,&sxbl_java_stream))return false;for(unsigned i=0;p<end&&i<1024;i++)if(!sxbl_java_value(&j,&p,end,0))return false;return p==end;}
bool sx_java_serialization_build(sx_context*c)
{
 return sxbl_java(c);
}
