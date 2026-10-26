/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * kerberos ccache data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_ccache_header_fields[] = {
 SX_FIELD("major","uint8",0,1,SX_NONE),
 SX_FIELD("minor","uint8",1,1,SX_NONE),
 SX_FIELD("header_size","uint16",2,2,SX_SIZE),
};
const sx_layout sxbx_ccache_header = {UINT32_C(0x6030007b),"ccache_header",sxbx_ccache_header_fields,SX_COUNT(sxbx_ccache_header_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_tag_fields[] = {
 SX_FIELD("tag","uint16",0,2,SX_ID),
 SX_FIELD("tag_size","uint16",2,2,SX_SIZE),
};
const sx_layout sxbx_ccache_tag = {UINT32_C(0x6030007c),"ccache_tag",sxbx_ccache_tag_fields,SX_COUNT(sxbx_ccache_tag_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_time_offset_fields[] = {
 SX_FIELD("seconds","int32",0,4,SX_NONE),
 SX_FIELD("microseconds","int32",4,4,SX_NONE),
};
const sx_layout sxbx_ccache_time_offset = {UINT32_C(0x6030007d),"ccache_time_offset",sxbx_ccache_time_offset_fields,SX_COUNT(sxbx_ccache_time_offset_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_principal_fields[] = {
 SX_FIELD("name_type","uint32",0,4,SX_ID),
 SX_FIELD("component_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxbx_ccache_principal = {UINT32_C(0x6030007e),"ccache_principal",sxbx_ccache_principal_fields,SX_COUNT(sxbx_ccache_principal_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_blob_size_fields[] = {
 SX_FIELD("byte_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxbx_ccache_blob_size = {UINT32_C(0x6030007f),"ccache_blob_size",sxbx_ccache_blob_size_fields,SX_COUNT(sxbx_ccache_blob_size_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_key_fields[] = {
 SX_FIELD("enctype","uint16",0,2,SX_ID),
 SX_FIELD("key_size","uint32",2,4,SX_SIZE),
};
const sx_layout sxbx_ccache_key = {UINT32_C(0x60300080),"ccache_key",sxbx_ccache_key_fields,SX_COUNT(sxbx_ccache_key_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_times_flags_fields[] = {
 SX_FIELD("auth_time","uint32",0,4,SX_NONE),
 SX_FIELD("start_time","uint32",4,4,SX_NONE),
 SX_FIELD("end_time","uint32",8,4,SX_NONE),
 SX_FIELD("renew_until","uint32",12,4,SX_NONE),
 SX_FIELD("is_skey","uint8",16,1,SX_NONE),
 SX_FIELD("ticket_flags","uint32",17,4,SX_FLAGS),
};
const sx_layout sxbx_ccache_times_flags = {UINT32_C(0x60300081),"ccache_times_flags",sxbx_ccache_times_flags_fields,SX_COUNT(sxbx_ccache_times_flags_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_list_count_fields[] = {
 SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxbx_ccache_list_count = {UINT32_C(0x60300082),"ccache_list_count",sxbx_ccache_list_count_fields,SX_COUNT(sxbx_ccache_list_count_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_ccache_typed_blob_fields[] = {
 SX_FIELD("type","uint16",0,2,SX_ID),
 SX_FIELD("byte_size","uint32",2,4,SX_SIZE),
};
const sx_layout sxbx_ccache_typed_blob = {UINT32_C(0x60300083),"ccache_typed_blob",sxbx_ccache_typed_blob_fields,SX_COUNT(sxbx_ccache_typed_blob_fields),SX_BE};
#define SXBX_LIMIT 20000U
static bool sxbx_cc_principal(sx_context*c,uint64_t*p,uint64_t end){uint64_t n;if(*p>end||end-*p<8||!sxbx_word(c,*p+4,4,true,&n)||!n||n>32||!sxbx_add(c,&sxbx_ccache_principal,*p))return false;*p+=8;for(uint64_t i=0;i<=n;i++)if(!sxbx_counted(c,p,end,&sxbx_ccache_blob_size,4,true,1))return false;return true;}
static bool sxbx_ccache(sx_context*c){uint64_t p=4,end=(uint64_t)c->size,z;if(!sxbx_add(c,&sxbx_ccache_header,0)||!sxbx_word(c,2,2,true,&z)||z>end-4)return false;uint64_t stop=p+z;while(p<stop&&c->count<SXBX_LIMIT){uint64_t tag;if(stop-p<4||!sxbx_word(c,p,2,true,&tag)||!sxbx_word(c,p+2,2,true,&z)||z>stop-p-4||!sxbx_add(c,&sxbx_ccache_tag,p))break;p+=4;if(tag==1&&z==8&&!sxbx_add(c,&sxbx_ccache_time_offset,p))return false;p+=z;}p=stop;if(!sxbx_cc_principal(c,&p,end))return true;for(unsigned entries=0;p<end&&entries<512&&c->count<SXBX_LIMIT;entries++){size_t keep=c->count;if(!sxbx_cc_principal(c,&p,end)||!sxbx_cc_principal(c,&p,end)||end-p<6||!sxbx_word(c,p+2,4,true,&z)||z>end-p-6||!sxbx_add(c,&sxbx_ccache_key,p)){c->count=keep;break;}p+=6+z;if(end-p<21||!sxbx_add(c,&sxbx_ccache_times_flags,p)){c->count=keep;break;}p+=21;bool ok=true;for(unsigned l=0;l<2&&ok;l++){uint64_t count;if(end-p<4||!sxbx_word(c,p,4,true,&count)||count>128||!sxbx_add(c,&sxbx_ccache_list_count,p)){ok=false;break;}p+=4;for(uint64_t i=0;i<count;i++){if(end-p<6||!sxbx_word(c,p+2,4,true,&z)||z>end-p-6||!sxbx_add(c,&sxbx_ccache_typed_blob,p)){ok=false;break;}p+=6+z;}}if(!ok||!sxbx_counted(c,&p,end,&sxbx_ccache_blob_size,4,true,1)||!sxbx_counted(c,&p,end,&sxbx_ccache_blob_size,4,true,1)){c->count=keep;break;}}return true;}
bool sx_kerberos_ccache_build(sx_context*c)
{
 return sxbx_ccache(c);
}
