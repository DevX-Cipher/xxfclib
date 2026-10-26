/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IzPack (com.izforge.izpack) installer pack file data structures, moved out of the installerwire schema family. */
#include "../../xx_format_schema_installerwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/executable/binsh_starkit/xx_binsh_starkit.h"
#endif

static const xx_data_struct_field_desc sxiw_izpack_stream_header_fields[]={
 SX_FIELD("stream_magic","uint16be",0,2,SX_SIGNATURE),
 SX_FIELD("stream_version","uint16be",2,2,SX_NONE),
 SX_FIELD("block_data_tag","uint8",4,1,SX_ID),
 SX_FIELD("count_block_size","uint8",5,1,SX_SIZE),
 SX_FIELD("record_count","int32be",6,4,SX_COUNT_PROP),
};
const sx_layout sxiw_izpack_stream_header={UINT32_C(0x60790002),"izpack_stream_header",sxiw_izpack_stream_header_fields,SX_COUNT(sxiw_izpack_stream_header_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_object_tag_fields[]={
 SX_FIELD("object_tag","uint8",0,1,SX_ID),
};
const sx_layout sxiw_java_object_tag={UINT32_C(0x60790003),"java_object_tag",sxiw_java_object_tag_fields,SX_COUNT(sxiw_java_object_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_class_tag_fields[]={
 SX_FIELD("class_descriptor_tag","uint8",0,1,SX_ID),
};
const sx_layout sxiw_java_class_tag={UINT32_C(0x60790004),"java_class_tag",sxiw_java_class_tag_fields,SX_COUNT(sxiw_java_class_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_utf_length_fields[]={
 SX_FIELD("modified_utf8_length","uint16be",0,2,SX_SIZE),
};
const sx_layout sxiw_java_utf_length={UINT32_C(0x60790005),"java_utf_length",sxiw_java_utf_length_fields,SX_COUNT(sxiw_java_utf_length_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_class_metadata_fields[]={
 SX_FIELD("serial_version_uid","uint64be",0,8,SX_ID),
 SX_FIELD("class_flags","uint8",8,1,SX_FLAGS),
 SX_FIELD("field_count","uint16be",9,2,SX_COUNT_PROP),
};
const sx_layout sxiw_java_class_metadata={UINT32_C(0x60790006),"java_class_metadata",sxiw_java_class_metadata_fields,SX_COUNT(sxiw_java_class_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_field_type_fields[]={
 SX_FIELD("type_code","char[1]",0,1,SX_ID),
};
const sx_layout sxiw_java_field_type={UINT32_C(0x60790007),"java_field_type",sxiw_java_field_type_fields,SX_COUNT(sxiw_java_field_type_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_reference_fields[]={
 SX_FIELD("reference_tag","uint8",0,1,SX_ID),
 SX_FIELD("wire_handle","uint32be",1,4,SX_ID),
};
const sx_layout sxiw_java_reference={UINT32_C(0x60790008),"java_reference",sxiw_java_reference_fields,SX_COUNT(sxiw_java_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_string_fields[]={
 SX_FIELD("string_tag","uint8",0,1,SX_ID),
 SX_FIELD("modified_utf8_length","uint16be",1,2,SX_SIZE),
};
const sx_layout sxiw_java_string={UINT32_C(0x60790009),"java_string",sxiw_java_string_fields,SX_COUNT(sxiw_java_string_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_long_string_fields[]={
 SX_FIELD("string_tag","uint8",0,1,SX_ID),
 SX_FIELD("modified_utf8_length","uint64be",1,8,SX_SIZE),
};
const sx_layout sxiw_java_long_string={UINT32_C(0x6079000a),"java_long_string",sxiw_java_long_string_fields,SX_COUNT(sxiw_java_long_string_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_block_fields[]={
 SX_FIELD("block_tag","uint8",0,1,SX_ID),
 SX_FIELD("block_length","uint8",1,1,SX_SIZE),
};
const sx_layout sxiw_java_block={UINT32_C(0x6079000b),"java_block",sxiw_java_block_fields,SX_COUNT(sxiw_java_block_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_long_block_fields[]={
 SX_FIELD("block_tag","uint8",0,1,SX_ID),
 SX_FIELD("block_length","uint32be",1,4,SX_SIZE),
};
const sx_layout sxiw_java_long_block={UINT32_C(0x6079000c),"java_long_block",sxiw_java_long_block_fields,SX_COUNT(sxiw_java_long_block_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_java_boolean_fields[]={
 SX_FIELD("boolean","uint8",0,1,SX_FLAGS),
};
const sx_layout sxiw_java_boolean={UINT32_C(0x6079000d),"java_boolean",sxiw_java_boolean_fields,SX_COUNT(sxiw_java_boolean_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_java_byte_fields[]={
 SX_FIELD("byte","int8",0,1,SX_NONE),
};
const sx_layout sxiw_java_byte={UINT32_C(0x6079000e),"java_byte",sxiw_java_byte_fields,SX_COUNT(sxiw_java_byte_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_java_char_fields[]={
 SX_FIELD("char","uint16be",0,2,SX_NONE),
};
const sx_layout sxiw_java_char={UINT32_C(0x6079000f),"java_char",sxiw_java_char_fields,SX_COUNT(sxiw_java_char_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_java_short_fields[]={
 SX_FIELD("short","int16be",0,2,SX_NONE),
};
const sx_layout sxiw_java_short={UINT32_C(0x60790010),"java_short",sxiw_java_short_fields,SX_COUNT(sxiw_java_short_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_java_int_fields[]={
 SX_FIELD("int","int32be",0,4,SX_NONE),
};
const sx_layout sxiw_java_int={UINT32_C(0x60790011),"java_int",sxiw_java_int_fields,SX_COUNT(sxiw_java_int_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_java_long_fields[]={
 SX_FIELD("long","int64be",0,8,SX_NONE),
};
const sx_layout sxiw_java_long={UINT32_C(0x60790012),"java_long",sxiw_java_long_fields,SX_COUNT(sxiw_java_long_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_java_float_fields[]={
 SX_FIELD("float","float",0,4,SX_NONE),
};
const sx_layout sxiw_java_float={UINT32_C(0x60790013),"java_float",sxiw_java_float_fields,SX_COUNT(sxiw_java_float_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_java_double_fields[]={
 SX_FIELD("double","double",0,8,SX_NONE),
};
const sx_layout sxiw_java_double={UINT32_C(0x60790014),"java_double",sxiw_java_double_fields,SX_COUNT(sxiw_java_double_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_java_modified_utf8_fields[]={
 SX_FIELD("java_modified_utf8","uint8",0,0,SX_NONE),
};
const sx_layout sxiw_java_modified_utf8={UINT32_C(0x6079004e),"java_modified_utf8",sxiw_java_modified_utf8_fields,SX_COUNT(sxiw_java_modified_utf8_fields),SX_LE};
static const xx_data_struct_field_desc sxiw_izpack_record_v1_fields[]={
 SX_FIELD("length","int64be",0,8,SX_SIZE),
};
const sx_layout sxiw_izpack_record_v1={UINT32_C(0x60790067),"izpack_record_v1",sxiw_izpack_record_v1_fields,SX_COUNT(sxiw_izpack_record_v1_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_izpack_record_v2_fields[]={
 SX_FIELD("length","int64be",0,8,SX_SIZE),
 SX_FIELD("modification_time_ms","int64be",8,8,SX_NONE),
 SX_FIELD("override_or_previous_pack_number","int32be",16,4,SX_NONE),
};
const sx_layout sxiw_izpack_record_v2={UINT32_C(0x60790068),"izpack_record_v2",sxiw_izpack_record_v2_fields,SX_COUNT(sxiw_izpack_record_v2_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_izpack_record_v3_fields[]={
 SX_FIELD("length","int64be",0,8,SX_SIZE),
 SX_FIELD("modification_time_ms","int64be",8,8,SX_NONE),
 SX_FIELD("offset_in_previous_pack","int64be",16,8,SX_OFFSET),
 SX_FIELD("override_or_previous_pack_number","int32be",24,4,SX_NONE),
 SX_FIELD("previous_pack_number","int32be",28,4,SX_NONE),
};
const sx_layout sxiw_izpack_record_v3={UINT32_C(0x60790069),"izpack_record_v3",sxiw_izpack_record_v3_fields,SX_COUNT(sxiw_izpack_record_v3_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_izpack_record_v4_fields[]={
 SX_FIELD("is_directory","uint8",0,1,SX_FLAGS),
 SX_FIELD("length","int64be",1,8,SX_SIZE),
 SX_FIELD("modification_time_ms","int64be",9,8,SX_NONE),
 SX_FIELD("offset_in_previous_pack","int64be",17,8,SX_OFFSET),
 SX_FIELD("override_or_previous_pack_number","int32be",25,4,SX_NONE),
 SX_FIELD("previous_pack_number","int32be",29,4,SX_NONE),
};
const sx_layout sxiw_izpack_record_v4={UINT32_C(0x6079006a),"izpack_record_v4",sxiw_izpack_record_v4_fields,SX_COUNT(sxiw_izpack_record_v4_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_izpack_record_v5_fields[]={
 SX_FIELD("is_directory","uint8",0,1,SX_FLAGS),
 SX_FIELD("length","int64be",1,8,SX_SIZE),
 SX_FIELD("modification_time_ms","int64be",9,8,SX_NONE),
 SX_FIELD("offset_in_previous_pack","int64be",17,8,SX_OFFSET),
 SX_FIELD("override_or_previous_pack_number","int32be",25,4,SX_NONE),
 SX_FIELD("previous_pack_number","int32be",29,4,SX_NONE),
};
const sx_layout sxiw_izpack_record_v5={UINT32_C(0x6079006b),"izpack_record_v5",sxiw_izpack_record_v5_fields,SX_COUNT(sxiw_izpack_record_v5_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_izpack_record_v6_fields[]={
 SX_FIELD("is_directory","uint8",0,1,SX_FLAGS),
 SX_FIELD("length","int64be",1,8,SX_SIZE),
 SX_FIELD("modification_time_ms","int64be",9,8,SX_NONE),
 SX_FIELD("offset_in_previous_pack","int64be",17,8,SX_OFFSET),
 SX_FIELD("override_or_previous_pack_number","int32be",25,4,SX_NONE),
};
const sx_layout sxiw_izpack_record_v6={UINT32_C(0x6079006c),"izpack_record_v6",sxiw_izpack_record_v6_fields,SX_COUNT(sxiw_izpack_record_v6_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_izpack_record_v7_fields[]={
 SX_FIELD("is_directory","uint8",0,1,SX_FLAGS),
 SX_FIELD("length","int64be",1,8,SX_SIZE),
 SX_FIELD("modification_time_ms","int64be",9,8,SX_NONE),
 SX_FIELD("offset_in_previous_pack","int64be",17,8,SX_OFFSET),
 SX_FIELD("override_or_previous_pack_number","int32be",25,4,SX_NONE),
 SX_FIELD("pack200","uint8",29,1,SX_FLAGS),
};
const sx_layout sxiw_izpack_record_v7={UINT32_C(0x6079006d),"izpack_record_v7",sxiw_izpack_record_v7_fields,SX_COUNT(sxiw_izpack_record_v7_fields),SX_BE};
static const xx_data_struct_field_desc sxiw_izpack_list_count_fields[]={
 SX_FIELD("element_count","int32be",0,4,SX_COUNT_PROP),
};
const sx_layout sxiw_izpack_list_count={UINT32_C(0x60790071),"izpack_list_count",sxiw_izpack_list_count_fields,SX_COUNT(sxiw_izpack_list_count_fields),SX_BE};
#define SXIW_LIMIT 20000U
typedef struct sxiw_java_handle {uint8_t*types;uint16_t count;}sxiw_java_handle;
typedef struct sxiw_java {sx_context*c;uint64_t p,end;sxiw_java_handle h[4096];unsigned count;}sxiw_java;
static bool sxiw_jreserve(sxiw_java*j,unsigned*index){if(j->count>=4096)return false;*index=j->count++;return true;}
static bool sxiw_jvalue(sxiw_java*j,unsigned depth);
static bool sxiw_jutf(sxiw_java*j){uint64_t n;if(!sxiw_word(j->c,j->p,2,true,&n)||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_utf_length)||n>j->end-j->p||!sxiw_text(j->c,&sxiw_java_modified_utf8,j->p,n,false))return false;j->p+=n;return true;}
static bool sxiw_jclass(sxiw_java*j,unsigned depth,unsigned*handle){uint64_t tag,n;unsigned h;if(depth>32||!sxiw_word(j->c,j->p,1,false,&tag))return false;if(tag==0x71){if(!sxiw_word(j->c,j->p+1,4,true,&n)||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_reference)||n<0x7e0000||n-0x7e0000>=j->count||!j->h[n-0x7e0000].types)return false;*handle=(unsigned)(n-0x7e0000);return true;}if(tag!=0x72||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_class_tag)||!sxiw_jutf(j)||j->end-j->p<11||!sxiw_word(j->c,j->p+9,2,true,&n)||n>4096||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_class_metadata)||!sxiw_jreserve(j,&h))return false;
 j->h[h].types=xx_mem_alloc(n?n:1);if(!j->h[h].types)return false;j->h[h].count=(uint16_t)n;
 for(unsigned i=0;i<n;i++){uint64_t t;if(!sxiw_word(j->c,j->p,1,false,&t)||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_field_type)||!sxiw_jutf(j))return false;j->h[h].types[i]=(uint8_t)t;if((t=='L'||t=='[')&&!sxiw_jvalue(j,depth+1))return false;}
 for(unsigned i=0;i<2;i++){if(!sxiw_word(j->c,j->p,1,false,&tag)||tag!=(i?0x70:0x78)||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_object_tag))return false;}*handle=h;return true;}
static bool sxiw_jvalue(sxiw_java*j,unsigned depth){uint64_t tag,n;unsigned idx;if(depth>32||j->c->count>=SXIW_LIMIT||!sxiw_word(j->c,j->p,1,false,&tag))return false;
 if(tag==0x70||tag==0x78)return sxiw_emit(j->c,&j->p,j->end,&sxiw_java_object_tag);
 if(tag==0x71)return sxiw_emit(j->c,&j->p,j->end,&sxiw_java_reference);
 if(tag==0x74||tag==0x7c){unsigned width=tag==0x74?2:8;if(!sxiw_word(j->c,j->p+1,width,true,&n)||!sxiw_emit(j->c,&j->p,j->end,tag==0x74?&sxiw_java_string:&sxiw_java_long_string)||n>j->end-j->p||!sxiw_text(j->c,&sxiw_java_modified_utf8,j->p,n,false)||!sxiw_jreserve(j,&idx))return false;j->p+=n;return true;}
 if(tag==0x77||tag==0x7a){if(!sxiw_word(j->c,j->p+1,tag==0x77?1:4,true,&n)||!sxiw_emit(j->c,&j->p,j->end,tag==0x77?&sxiw_java_block:&sxiw_java_long_block)||n>j->end-j->p)return false;j->p+=n;return true;}
 if(tag==0x72)return sxiw_jclass(j,depth+1,&idx);
 if(tag!=0x73||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_object_tag)||!sxiw_jclass(j,depth+1,&idx))return false;unsigned reserved;if(!sxiw_jreserve(j,&reserved))return false;
 for(unsigned i=0;i<j->h[idx].count;i++){uint8_t t=j->h[idx].types[i];const sx_layout*l=NULL;switch(t){case'B':l=&sxiw_java_byte;break;case'C':l=&sxiw_java_char;break;case'D':l=&sxiw_java_double;break;case'F':l=&sxiw_java_float;break;case'I':l=&sxiw_java_int;break;case'J':l=&sxiw_java_long;break;case'S':l=&sxiw_java_short;break;case'Z':l=&sxiw_java_boolean;break;case'L':case'[':if(!sxiw_jvalue(j,depth+1))return false;break;default:return false;}if(l&&!sxiw_emit(j->c,&j->p,j->end,l))return false;}return true;}
static bool sxiw_jlist(sxiw_java*j){uint64_t tag,n;unsigned h;if(!sxiw_word(j->c,j->p,1,false,&tag))return false;if(tag==0x71)return sxiw_jvalue(j,0);if(tag!=0x73||!sxiw_emit(j->c,&j->p,j->end,&sxiw_java_object_tag)||!sxiw_jclass(j,0,&h)||!sxiw_jreserve(j,&h)||!sxiw_word(j->c,j->p,4,true,&n)||n>4096||!sxiw_emit(j->c,&j->p,j->end,&sxiw_izpack_list_count)||!sxiw_jvalue(j,0))return false;for(uint64_t i=0;i<n;i++)if(!sxiw_jvalue(j,0))return false;return sxiw_word(j->c,j->p,1,false,&tag)&&tag==0x78&&sxiw_emit(j->c,&j->p,j->end,&sxiw_java_object_tag);}
static bool sxiw_izpack(sx_context*c){sxiw_java*j=xx_mem_calloc(1,sizeof(*j));if(!j)return false;j->c=c;j->p=10;j->end=(uint64_t)c->size;uint64_t count,uid,n;bool ok=false;unsigned version=0;
 if(!sxiw_add(c,&sxiw_izpack_stream_header,0)||!sxiw_word(c,6,4,true,&count)||count>1000000||!sxiw_word(c,41,8,true,&uid)||!sxiw_word(c,50,2,true,&n))goto done;
 if(uid==UINT64_C(0x76a523b293a5e5c3)&&n==2)version=1;else if(uid==UINT64_C(0x11e206a67610577a)&&n==5)version=2;else if(uid==UINT64_C(0x9856d67cc286140e)&&n==7)version=3;else if(uid==UINT64_C(0x99e53bc9ae638cb7)&&n==8)version=4;else if(uid==UINT64_C(0xf46bb277b6f32403)&&n>=10&&n<=12)version=(unsigned)n-5;else goto done;
 const sx_layout*records[]={&sxiw_izpack_record_v1,&sxiw_izpack_record_v2,&sxiw_izpack_record_v3,&sxiw_izpack_record_v4,&sxiw_izpack_record_v5,&sxiw_izpack_record_v6,&sxiw_izpack_record_v7};
 for(uint64_t i=0;i<count&&c->count<SXIW_LIMIT;i++){uint64_t tag,len,previous=UINT64_MAX,directory=0,pack=0;unsigned h;if(!sxiw_word(c,j->p,1,false,&tag)||tag!=0x73||!sxiw_emit(c,&j->p,j->end,&sxiw_java_object_tag)||!sxiw_jclass(j,0,&h)||!sxiw_jreserve(j,&h))goto done;uint64_t a=j->p;
 if(version>=4&&!sxiw_word(c,a++,1,false,&directory))goto done;if(!sxiw_word(c,a,8,true,&len))goto done;a+=8;if(version!=1)a+=8;if(version>=3&&!sxiw_word(c,a,8,true,&previous))goto done;if(!sxiw_emit(c,&j->p,j->end,records[version-1]))goto done;if(version==7&&!sxiw_word(c,j->p-1,1,false,&pack))goto done;
 if(version>=5&&!sxiw_jvalue(j,0))goto done;if(version>=6&&!sxiw_jvalue(j,0))goto done;if(version!=1&&!sxiw_jlist(j))goto done;if(version>=6&&!sxiw_jvalue(j,0))goto done;if(version>=5&&!sxiw_jvalue(j,0))goto done;if(!sxiw_jvalue(j,0))goto done;if(previous!=UINT64_MAX)continue;
 uint64_t left=pack?4:directory?0:len;while(left){uint64_t z;if(!sxiw_word(c,j->p,1,false,&tag)||(tag!=0x77&&tag!=0x7a)||!sxiw_word(c,j->p+1,tag==0x77?1:4,true,&z)||!z||!sxiw_emit(c,&j->p,j->end,tag==0x77?&sxiw_java_block:&sxiw_java_long_block)||z>j->end-j->p)goto done;j->p+=z;if(z>=left)left=0;else left-=z;}}
 ok=true;done:for(unsigned i=0;i<j->count;i++)xx_mem_free(j->h[i].types);xx_mem_free(j);return ok;}
bool sx_izpack_build(sx_context*c)
{
 return sxiw_izpack(c);
}
