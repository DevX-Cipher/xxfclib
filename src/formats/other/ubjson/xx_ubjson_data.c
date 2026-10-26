/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ubjson data structures, moved out of the binarylater schema family. */
#include "../../xx_format_schema_binarylater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbl_ubjson_tag_fields[] = {
 SX_FIELD("type_and_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxbl_ubjson_tag = {UINT32_C(0x60350038),"ubjson_tag",sxbl_ubjson_tag_fields,SX_COUNT(sxbl_ubjson_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ubjson_optimized_type_fields[] = {
 SX_FIELD("implicit_type","uint8",0,1,SX_ID),
};
const sx_layout sxbl_ubjson_optimized_type = {UINT32_C(0x60350097),"ubjson_optimized_type",sxbl_ubjson_optimized_type_fields,SX_COUNT(sxbl_ubjson_optimized_type_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_ubjson_byte_size1_fields[] = {
 SX_FIELD("byte_size","int8",0,1,SX_SIZE),
};
const sx_layout sxbl_ubjson_byte_size1 = {UINT32_C(0x6035010d),"ubjson_byte_size1",sxbl_ubjson_byte_size1_fields,SX_COUNT(sxbl_ubjson_byte_size1_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ubjson_item_count1_fields[] = {
 SX_FIELD("item_count","int8",0,1,SX_COUNT_PROP),
};
const sx_layout sxbl_ubjson_item_count1 = {UINT32_C(0x6035010e),"ubjson_item_count1",sxbl_ubjson_item_count1_fields,SX_COUNT(sxbl_ubjson_item_count1_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ubjson_byte_size2_fields[] = {
 SX_FIELD("byte_size","int16",0,2,SX_SIZE),
};
const sx_layout sxbl_ubjson_byte_size2 = {UINT32_C(0x60350110),"ubjson_byte_size2",sxbl_ubjson_byte_size2_fields,SX_COUNT(sxbl_ubjson_byte_size2_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ubjson_item_count2_fields[] = {
 SX_FIELD("item_count","int16",0,2,SX_COUNT_PROP),
};
const sx_layout sxbl_ubjson_item_count2 = {UINT32_C(0x60350111),"ubjson_item_count2",sxbl_ubjson_item_count2_fields,SX_COUNT(sxbl_ubjson_item_count2_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ubjson_byte_size4_fields[] = {
 SX_FIELD("byte_size","int32",0,4,SX_SIZE),
};
const sx_layout sxbl_ubjson_byte_size4 = {UINT32_C(0x60350113),"ubjson_byte_size4",sxbl_ubjson_byte_size4_fields,SX_COUNT(sxbl_ubjson_byte_size4_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ubjson_item_count4_fields[] = {
 SX_FIELD("item_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxbl_ubjson_item_count4 = {UINT32_C(0x60350114),"ubjson_item_count4",sxbl_ubjson_item_count4_fields,SX_COUNT(sxbl_ubjson_item_count4_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ubjson_byte_size8_fields[] = {
 SX_FIELD("byte_size","int64",0,8,SX_SIZE),
};
const sx_layout sxbl_ubjson_byte_size8 = {UINT32_C(0x60350116),"ubjson_byte_size8",sxbl_ubjson_byte_size8_fields,SX_COUNT(sxbl_ubjson_byte_size8_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_ubjson_item_count8_fields[] = {
 SX_FIELD("item_count","int64",0,8,SX_COUNT_PROP),
};
const sx_layout sxbl_ubjson_item_count8 = {UINT32_C(0x60350117),"ubjson_item_count8",sxbl_ubjson_item_count8_fields,SX_COUNT(sxbl_ubjson_item_count8_fields),SX_BE};
#define SXBL_LIMIT 20000U
static bool sxbl_ubnumber(sx_context*c,uint64_t*p,uint64_t end,uint64_t*v,bool count){uint8_t t;if(!sxbl_byte(c,*p,&t)||!sxbl_emit(c,p,end,&sxbl_ubjson_tag))return false;unsigned z=t=='i'||t=='U'?1:t=='I'?2:t=='l'?4:t=='L'?8:0;if(!z||!sxbl_word(c,*p,z,true,v))return false;if(t=='U'){uint64_t x;return sxbl_length(c,p,end,z,true,count,&x);}const sx_layout*const a[]={&sxbl_ubjson_byte_size1,&sxbl_ubjson_byte_size2,&sxbl_ubjson_byte_size4,&sxbl_ubjson_byte_size8,&sxbl_ubjson_item_count1,&sxbl_ubjson_item_count2,&sxbl_ubjson_item_count4,&sxbl_ubjson_item_count8};unsigned i=z==1?0:z==2?1:z==4?2:3;return sxbl_emit(c,p,end,a[i+(count?4:0)]);}
static bool sxbl_ubtext(sx_context*c,uint64_t*p,uint64_t end){uint64_t n;return sxbl_ubnumber(c,p,end,&n,false)&&sxbl_skip(c,p,end,n);}
static bool sxbl_ubjson(sx_context*c,uint64_t*p,uint64_t end,unsigned depth,uint8_t fixed){uint8_t t=fixed;if(depth>32)return false;if(!fixed&&(!sxbl_byte(c,*p,&t)||!sxbl_emit(c,p,end,&sxbl_ubjson_tag)))return false;if(t=='Z'||t=='T'||t=='F')return true;if(t=='i'||t=='U'||t=='I'||t=='l'||t=='L')return sxbl_numeric(c,p,end,t=='i'||t=='U'?1:t=='I'?2:t=='l'?4:8,t!='U',true);if(t=='d'||t=='D')return sxbl_float(c,p,end,t=='d'?4:8,true);if(t=='C')return sxbl_numeric(c,p,end,1,false,true);if(t=='S'||t=='H')return sxbl_ubtext(c,p,end);if(t!='['&&t!='{')return false;
 uint8_t next,kind=0;uint64_t n=0;bool counted=false;if(!sxbl_byte(c,*p,&next))return false;if(next=='$'){if(!sxbl_emit(c,p,end,&sxbl_ubjson_tag)||!sxbl_byte(c,*p,&kind)||!sxbl_emit(c,p,end,&sxbl_ubjson_optimized_type)||!sxbl_byte(c,*p,&next))return false;}
 if(next=='#'){if(!sxbl_emit(c,p,end,&sxbl_ubjson_tag)||!sxbl_ubnumber(c,p,end,&n,true)||n>SXBL_LIMIT)return false;counted=true;}
 for(uint64_t i=0;i<SXBL_LIMIT;i++){if(counted&&i==n)return true;if(!counted){if(!sxbl_byte(c,*p,&next))return false;if(next==(t=='['?']':'}'))return sxbl_emit(c,p,end,&sxbl_ubjson_tag);if(next=='N'){if(!sxbl_emit(c,p,end,&sxbl_ubjson_tag))return false;continue;}}if(t=='{'&&!sxbl_ubtext(c,p,end))return false;if(!sxbl_ubjson(c,p,end,depth+1,kind))return false;}return false;}
bool sx_ubjson_build(sx_context*c)
{
 uint64_t p=0,end=(uint64_t)c->size;return sxbl_ubjson(c,&p,end,0,0);
}
