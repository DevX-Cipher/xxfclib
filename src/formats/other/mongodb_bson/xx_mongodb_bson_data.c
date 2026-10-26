/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * mongodb bson data structures, moved out of the binarylater schema family. */
#include "../../xx_format_schema_binarylater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbl_bson_tag_fields[] = {
 SX_FIELD("type_and_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxbl_bson_tag = {UINT32_C(0x60350035),"bson_tag",sxbl_bson_tag_fields,SX_COUNT(sxbl_bson_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_bson_document_size_fields[] = {
 SX_FIELD("document_size","int32",0,4,SX_SIZE),
};
const sx_layout sxbl_bson_document_size = {UINT32_C(0x60350088),"bson_document_size",sxbl_bson_document_size_fields,SX_COUNT(sxbl_bson_document_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_bson_string_size_fields[] = {
 SX_FIELD("string_size","int32",0,4,SX_SIZE),
};
const sx_layout sxbl_bson_string_size = {UINT32_C(0x60350089),"bson_string_size",sxbl_bson_string_size_fields,SX_COUNT(sxbl_bson_string_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_bson_terminator_fields[] = {
 SX_FIELD("terminator","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxbl_bson_terminator = {UINT32_C(0x6035008a),"bson_terminator",sxbl_bson_terminator_fields,SX_COUNT(sxbl_bson_terminator_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_bson_binary_header_fields[] = {
 SX_FIELD("binary_size","int32",0,4,SX_SIZE),
 SX_FIELD("subtype","uint8",4,1,SX_ID),
};
const sx_layout sxbl_bson_binary_header = {UINT32_C(0x6035008b),"bson_binary_header",sxbl_bson_binary_header_fields,SX_COUNT(sxbl_bson_binary_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_bson_object_id_fields[] = {
 SX_FIELD("timestamp","uint32be",0,4,SX_NONE),
 SX_FIELD("process_random","uint8[5]",4,5,SX_NONE),
 SX_FIELD("counter","uint24be",9,3,SX_NONE),
};
const sx_layout sxbl_bson_object_id = {UINT32_C(0x6035008c),"bson_object_id",sxbl_bson_object_id_fields,SX_COUNT(sxbl_bson_object_id_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_bson_timestamp_fields[] = {
 SX_FIELD("increment","uint32",0,4,SX_NONE),
 SX_FIELD("seconds","uint32",4,4,SX_NONE),
};
const sx_layout sxbl_bson_timestamp = {UINT32_C(0x6035008d),"bson_timestamp",sxbl_bson_timestamp_fields,SX_COUNT(sxbl_bson_timestamp_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_bson_decimal128_fields[] = {
 SX_FIELD("encoded_decimal","uint8[16]",0,16,SX_NONE),
};
const sx_layout sxbl_bson_decimal128 = {UINT32_C(0x6035008e),"bson_decimal128",sxbl_bson_decimal128_fields,SX_COUNT(sxbl_bson_decimal128_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_bson_bool_fields[] = {
 SX_FIELD("boolean","uint8",0,1,SX_NONE),
};
const sx_layout sxbl_bson_bool = {UINT32_C(0x6035008f),"bson_bool",sxbl_bson_bool_fields,SX_COUNT(sxbl_bson_bool_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_bson_code_scope_size_fields[] = {
 SX_FIELD("total_size","int32",0,4,SX_SIZE),
};
const sx_layout sxbl_bson_code_scope_size = {UINT32_C(0x60350090),"bson_code_scope_size",sxbl_bson_code_scope_size_fields,SX_COUNT(sxbl_bson_code_scope_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_bson_datetime_fields[] = {
 SX_FIELD("milliseconds_since_unix_epoch","int64",0,8,SX_NONE),
};
const sx_layout sxbl_bson_datetime = {UINT32_C(0x60350091),"bson_datetime",sxbl_bson_datetime_fields,SX_COUNT(sxbl_bson_datetime_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_bson_legacy_binary_size_fields[] = {
 SX_FIELD("binary_size","int32",0,4,SX_SIZE),
};
const sx_layout sxbl_bson_legacy_binary_size = {UINT32_C(0x603500fa),"bson_legacy_binary_size",sxbl_bson_legacy_binary_size_fields,SX_COUNT(sxbl_bson_legacy_binary_size_fields),SX_LE};
#define SXBL_LIMIT 20000U
static bool sxbl_zero(sx_context*c,uint64_t*p,uint64_t end){uint8_t b;for(unsigned i=0;i<65536;i++){if(*p>=end||!sxbl_byte(c,(*p)++,&b))return false;if(!b)return true;}return false;}
static bool sxbl_bson(sx_context*c,uint64_t*p,uint64_t end,unsigned depth){uint64_t n,stop;if(depth>32||!sxbl_word(c,*p,4,false,&n)||n<5||*p>end||n>end-*p)return false;stop=*p+n;if(!sxbl_emit(c,p,stop,&sxbl_bson_document_size))return false;while(*p<stop-1&&c->count<SXBL_LIMIT){uint8_t t;if(!sxbl_byte(c,*p,&t)||!sxbl_emit(c,p,stop,&sxbl_bson_tag)||!sxbl_zero(c,p,stop-1))return false;uint64_t z;
 switch(t){case 1:if(!sxbl_float(c,p,stop-1,8,false))return false;break;case 9:if(!sxbl_emit(c,p,stop-1,&sxbl_bson_datetime))return false;break;case 0x11:if(!sxbl_emit(c,p,stop-1,&sxbl_bson_timestamp))return false;break;case 0x12:if(!sxbl_numeric(c,p,stop-1,8,true,false))return false;break;
 case 2:case 13:case 14:if(!sxbl_word(c,*p,4,false,&z)||!sxbl_emit(c,p,stop-1,&sxbl_bson_string_size)||!sxbl_skip(c,p,stop-1,z))return false;break;
 case 3:case 4:if(!sxbl_bson(c,p,stop-1,depth+1))return false;break;
 case 5:{uint8_t subtype;if(!sxbl_word(c,*p,4,false,&z)||!sxbl_byte(c,*p+4,&subtype)||!sxbl_emit(c,p,stop-1,&sxbl_bson_binary_header)||z>stop-1-*p)return false;if(subtype==2){if(z<4||!sxbl_emit(c,p,stop-1,&sxbl_bson_legacy_binary_size))return false;z-=4;}if(!sxbl_skip(c,p,stop-1,z))return false;break;}
 case 6:case 10:case 127:case 255:break;case 7:if(!sxbl_emit(c,p,stop-1,&sxbl_bson_object_id))return false;break;case 8:if(!sxbl_emit(c,p,stop-1,&sxbl_bson_bool))return false;break;
 case 11:if(!sxbl_zero(c,p,stop-1)||!sxbl_zero(c,p,stop-1))return false;break;
 case 12:if(!sxbl_word(c,*p,4,false,&z)||!sxbl_emit(c,p,stop-1,&sxbl_bson_string_size)||!sxbl_skip(c,p,stop-1,z)||!sxbl_emit(c,p,stop-1,&sxbl_bson_object_id))return false;break;
 case 15:{uint64_t lim;if(!sxbl_word(c,*p,4,false,&z)||z<14||z>stop-1-*p)return false;lim=*p+z;if(!sxbl_emit(c,p,lim,&sxbl_bson_code_scope_size)||!sxbl_word(c,*p,4,false,&z)||!sxbl_emit(c,p,lim,&sxbl_bson_string_size)||!sxbl_skip(c,p,lim,z)||!sxbl_bson(c,p,lim,depth+1)||*p!=lim)return false;break;}
 case 16:if(!sxbl_numeric(c,p,stop-1,4,true,false))return false;break;case 19:if(!sxbl_emit(c,p,stop-1,&sxbl_bson_decimal128))return false;break;default:return false;}}
 return *p==stop-1&&sxbl_emit(c,p,stop,&sxbl_bson_terminator);}
bool sx_mongodb_bson_build(sx_context*c)
{
 uint64_t p=0,end=(uint64_t)c->size;bool ok=false;ok=true;while(p<end&&ok)ok=sxbl_bson(c,&p,end,0);return ok;
}
