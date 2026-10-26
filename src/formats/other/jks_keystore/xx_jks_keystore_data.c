/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * jks keystore data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_jks_header_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
 SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxbx_jks_header = {UINT32_C(0x60300084),"jks_header",sxbx_jks_header_fields,SX_COUNT(sxbx_jks_header_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_jks_entry_tag_fields[] = {
 SX_FIELD("tag","uint32",0,4,SX_ID),
};
const sx_layout sxbx_jks_entry_tag = {UINT32_C(0x60300085),"jks_entry_tag",sxbx_jks_entry_tag_fields,SX_COUNT(sxbx_jks_entry_tag_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_jks_string_size_fields[] = {
 SX_FIELD("modified_utf8_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxbx_jks_string_size = {UINT32_C(0x60300086),"jks_string_size",sxbx_jks_string_size_fields,SX_COUNT(sxbx_jks_string_size_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_jks_timestamp_fields[] = {
 SX_FIELD("timestamp","int64",0,8,SX_NONE),
};
const sx_layout sxbx_jks_timestamp = {UINT32_C(0x60300087),"jks_timestamp",sxbx_jks_timestamp_fields,SX_COUNT(sxbx_jks_timestamp_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_jks_blob_size_fields[] = {
 SX_FIELD("byte_size","int32",0,4,SX_SIZE),
};
const sx_layout sxbx_jks_blob_size = {UINT32_C(0x60300088),"jks_blob_size",sxbx_jks_blob_size_fields,SX_COUNT(sxbx_jks_blob_size_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_jks_certificate_count_fields[] = {
 SX_FIELD("certificate_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxbx_jks_certificate_count = {UINT32_C(0x60300089),"jks_certificate_count",sxbx_jks_certificate_count_fields,SX_COUNT(sxbx_jks_certificate_count_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_jks_digest_fields[] = {
 SX_FIELD("sha1","uint8[20]",0,20,SX_CHECKSUM),
};
const sx_layout sxbx_jks_digest = {UINT32_C(0x6030008a),"jks_digest",sxbx_jks_digest_fields,SX_COUNT(sxbx_jks_digest_fields),SX_LE};
#define SXBX_LIMIT 20000U
static bool sxbx_jks(sx_context*c){uint64_t p=12,end=(uint64_t)c->size,n;if(end<32||!sxbx_add(c,&sxbx_jks_header,0)||!sxbx_add(c,&sxbx_jks_digest,end-20)||!sxbx_word(c,8,4,true,&n))return false;end-=20;if(n>256)return true;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++){uint64_t tag,certs=1;size_t keep=c->count;if(end-p<4||!sxbx_word(c,p,4,true,&tag)||!sxbx_add(c,&sxbx_jks_entry_tag,p)){c->count=keep;break;}p+=4;if(!sxbx_counted(c,&p,end,&sxbx_jks_string_size,2,true,1)||end-p<8||!sxbx_add(c,&sxbx_jks_timestamp,p)){c->count=keep;break;}p+=8;if(tag==1){if(!sxbx_counted(c,&p,end,&sxbx_jks_blob_size,4,true,1)||end-p<4||!sxbx_word(c,p,4,true,&certs)||certs>16||!sxbx_add(c,&sxbx_jks_certificate_count,p)){c->count=keep;break;}p+=4;}else if(tag!=2){c->count=keep;break;}bool ok=true;for(uint64_t j=0;j<certs;j++)if(!sxbx_counted(c,&p,end,&sxbx_jks_string_size,2,true,1)||!sxbx_counted(c,&p,end,&sxbx_jks_blob_size,4,true,1)){ok=false;break;}if(!ok){c->count=keep;break;}}return true;}
bool sx_jks_keystore_build(sx_context*c)
{
 return sxbx_jks(c);
}
