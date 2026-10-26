/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * thrift compact data structures, moved out of the binarylater schema family. */
#include "../../xx_format_schema_binarylater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbl_thrift_field_tag_fields[] = {
 SX_FIELD("type_and_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxbl_thrift_field_tag = {UINT32_C(0x6035003b),"thrift_field_tag",sxbl_thrift_field_tag_fields,SX_COUNT(sxbl_thrift_field_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_thrift_collection_tag_fields[] = {
 SX_FIELD("type_and_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxbl_thrift_collection_tag = {UINT32_C(0x6035003c),"thrift_collection_tag",sxbl_thrift_collection_tag_fields,SX_COUNT(sxbl_thrift_collection_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_thrift_map_tag_fields[] = {
 SX_FIELD("type_and_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxbl_thrift_map_tag = {UINT32_C(0x6035003d),"thrift_map_tag",sxbl_thrift_map_tag_fields,SX_COUNT(sxbl_thrift_map_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_thrift_message_fields[] = {
 SX_FIELD("protocol","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("version_and_message_type","uint8",1,1,SX_FLAGS),
};
const sx_layout sxbl_thrift_message = {UINT32_C(0x603500d7),"thrift_message",sxbl_thrift_message_fields,SX_COUNT(sxbl_thrift_message_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_thrift_uuid_fields[] = {
 SX_FIELD("uuid","uint8[16]",0,16,SX_NONE),
};
const sx_layout sxbl_thrift_uuid = {UINT32_C(0x603500d8),"thrift_uuid",sxbl_thrift_uuid_fields,SX_COUNT(sxbl_thrift_uuid_fields),SX_LE};
#define SXBL_LIMIT 20000U
static bool sxbl_thrift_value(sx_context*,uint64_t*,uint64_t,unsigned,unsigned,bool);
static bool sxbl_thrift_struct(sx_context*c,uint64_t*p,uint64_t end,unsigned depth){for(unsigned i=0;i<256;i++){uint8_t t;uint64_t id;if(!sxbl_byte(c,*p,&t)||!sxbl_emit(c,p,end,&sxbl_thrift_field_tag))return false;if(!t)return true;if(!(t>>4)&&!sxbl_var(c,p,end,6,&id))return false;if(!sxbl_thrift_value(c,p,end,t&15,depth+1,true))return false;}return false;}
static bool sxbl_thrift_value(sx_context*c,uint64_t*p,uint64_t end,unsigned kind,unsigned depth,bool field){uint64_t n,v;if(depth>32)return false;if(kind==1||kind==2)return field||sxbl_numeric(c,p,end,1,false,false);if(kind==3)return sxbl_numeric(c,p,end,1,true,false);if(kind>=4&&kind<=6)return sxbl_var(c,p,end,2,&v);if(kind==7)return sxbl_float(c,p,end,8,false);if(kind==13)return sxbl_emit(c,p,end,&sxbl_thrift_uuid);if(kind==8)return sxbl_var(c,p,end,4,&n)&&sxbl_skip(c,p,end,n);if(kind==12)return sxbl_thrift_struct(c,p,end,depth);uint8_t t;
 if(kind==9||kind==10){if(!sxbl_byte(c,*p,&t)||!sxbl_emit(c,p,end,&sxbl_thrift_collection_tag))return false;n=t>>4;if(n==15&&!sxbl_var(c,p,end,5,&n))return false;if(n>SXBL_LIMIT)return false;for(uint64_t i=0;i<n;i++)if(!sxbl_thrift_value(c,p,end,t&15,depth+1,false))return false;return true;}
 if(kind==11){if(!sxbl_var(c,p,end,5,&n)||n>SXBL_LIMIT)return false;if(!n)return true;if(!sxbl_byte(c,*p,&t)||!sxbl_emit(c,p,end,&sxbl_thrift_map_tag))return false;for(uint64_t i=0;i<n;i++)if(!sxbl_thrift_value(c,p,end,t>>4,depth+1,false)||!sxbl_thrift_value(c,p,end,t&15,depth+1,false))return false;return true;}return false;}
static bool sxbl_thrift(sx_context*c){uint64_t p=0,end=(uint64_t)c->size;for(unsigned i=0;p<end&&i<256;i++){uint64_t v,n;if(!sxbl_emit(c,&p,end,&sxbl_thrift_message)||!sxbl_var(c,&p,end,3,&v)||!sxbl_var(c,&p,end,4,&n)||!sxbl_skip(c,&p,end,n)||!sxbl_thrift_struct(c,&p,end,0))return false;}return p==end;}
bool sx_thrift_compact_build(sx_context*c)
{
 return sxbl_thrift(c);
}
