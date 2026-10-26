/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NVP image/configuration container data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_nvp_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxbx_nvp_header = {UINT32_C(0x6030009d),"nvp_header",sxbx_nvp_header_fields,SX_COUNT(sxbx_nvp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_nvp_directory_fields[] = {
 SX_FIELD("unknown","uint8[3]",0,3,SX_NONE),
 SX_FIELD("record_count","uint16",3,2,SX_COUNT_PROP),
};
const sx_layout sxbx_nvp_directory = {UINT32_C(0x6030009e),"nvp_directory",sxbx_nvp_directory_fields,SX_COUNT(sxbx_nvp_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_nvp_record_fields[] = {
 SX_FIELD("type","uint32",0,4,SX_ID),
 SX_FIELD("size_and_flags","uint32",4,4,SX_FLAGS),
};
const sx_layout sxbx_nvp_record = {UINT32_C(0x6030009f),"nvp_record",sxbx_nvp_record_fields,SX_COUNT(sxbx_nvp_record_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_nvp_jpeg_size_fields[] = {
 SX_FIELD("jpeg_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxbx_nvp_jpeg_size = {UINT32_C(0x603000a0),"nvp_jpeg_size",sxbx_nvp_jpeg_size_fields,SX_COUNT(sxbx_nvp_jpeg_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_nvp_string_list_fields[] = {
 SX_FIELD("string_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxbx_nvp_string_list = {UINT32_C(0x603000a1),"nvp_string_list",sxbx_nvp_string_list_fields,SX_COUNT(sxbx_nvp_string_list_fields),SX_LE};
#define SXBX_LIMIT 20000U
static bool sxbx_nvp_lists(sx_context*c,uint64_t*p,uint64_t end){uint64_t n;if(*p>=end||!sxbx_word(c,*p,1,false,&n)||!sxbx_add(c,&sxbx_nvp_string_list,(*p)++))return false;for(uint64_t i=0;i<n;i++)if(!sxbx_zero_string(c,p,end,1))return false;return true;}
static bool sxbx_nvp(sx_context*c){uint64_t p=4,end=(uint64_t)c->size,n;if(!sxbx_add(c,&sxbx_nvp_header,0)||!sxbx_zero_string(c,&p,end,1)||!sxbx_word(c,p+3,2,false,&n)||!sxbx_add(c,&sxbx_nvp_directory,p))return false;p+=5;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++){uint8_t b[8];if(!sxbx_read(c,p,b,8))break;uint64_t z=sxbx32(b+4,false)&0x7fffffffU;unsigned type=sxbx32(b,false);if(!sxbx_span(c,p+8,z)||!sxbx_add(c,&sxbx_nvp_record,p))break;uint64_t q=p+8,stop=q+z;if(type==4005||type==2203){if(z>=4&&!sxbx_add(c,&sxbx_nvp_jpeg_size,q))return false;}else if(type==1500||type==1502){unsigned skip=type==1500?17:13;if(z>=skip+4&&!sxbx_add(c,&sxbx_nvp_jpeg_size,q+skip))return false;}else if(type==1503){size_t keep=c->count;bool ok=sxbx_nvp_lists(c,&q,stop)&&sxbx_nvp_lists(c,&q,stop)&&stop-q>=3;q+=ok?3:0;ok=ok&&sxbx_nvp_lists(c,&q,stop)&&sxbx_nvp_lists(c,&q,stop)&&stop-q>=6;if(ok){q+=2;ok=sxbx_add(c,&sxbx_nvp_jpeg_size,q);}if(!ok)c->count=keep;}p=stop;}return true;}
bool sx_nvp_build(sx_context*c)
{
 return sxbx_nvp(c);
}
