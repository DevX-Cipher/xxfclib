/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RESOURCEFORK data structures, moved out of the executablemore schema family. */
#include "../../xx_format_schema_executablemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxexm_resource_fork_header_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("map_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",8,4,SX_SIZE),
 SX_FIELD("map_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxexm_resource_fork_header = {UINT32_C(0x602b0011),"resource_fork_header",sxexm_resource_fork_header_fields,SX_COUNT(sxexm_resource_fork_header_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_resource_map_header_fields[] = {
 SX_FIELD("data_offset_copy","uint32",0,4,SX_OFFSET),
 SX_FIELD("map_offset_copy","uint32",4,4,SX_OFFSET),
 SX_FIELD("data_size_copy","uint32",8,4,SX_SIZE),
 SX_FIELD("map_size_copy","uint32",12,4,SX_SIZE),
 SX_FIELD("next_map_handle","uint32",16,4,SX_POINTER),
 SX_FIELD("file_reference","int16",20,2,SX_ID),
 SX_FIELD("attributes","uint16",22,2,SX_FLAGS),
 SX_FIELD("type_list_offset","uint16",24,2,SX_OFFSET),
 SX_FIELD("name_list_offset","uint16",26,2,SX_OFFSET),
};
const sx_layout sxexm_resource_map_header = {UINT32_C(0x602b0012),"resource_map_header",sxexm_resource_map_header_fields,SX_COUNT(sxexm_resource_map_header_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_resource_type_count_fields[] = {
 SX_FIELD("type_count_minus_one","uint16",0,2,SX_NONE),
};
const sx_layout sxexm_resource_type_count = {UINT32_C(0x602b0013),"resource_type_count",sxexm_resource_type_count_fields,SX_COUNT(sxexm_resource_type_count_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_resource_type_entry_fields[] = {
 SX_FIELD("resource_type","char[4]",0,4,SX_ID),
 SX_FIELD("resource_count_minus_one","uint16",4,2,SX_NONE),
 SX_FIELD("references_offset","uint16",6,2,SX_OFFSET),
};
const sx_layout sxexm_resource_type_entry = {UINT32_C(0x602b0014),"resource_type_entry",sxexm_resource_type_entry_fields,SX_COUNT(sxexm_resource_type_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_resource_reference_fields[] = {
 SX_FIELD("resource_id","int16",0,2,SX_ID),
 SX_FIELD("name_offset","uint16",2,2,SX_OFFSET),
 SX_FIELD("attributes","uint8",4,1,SX_FLAGS),
 SX_FIELD("data_offset","uint24",5,3,SX_OFFSET),
 SX_FIELD("handle","uint32",8,4,SX_POINTER),
};
const sx_layout sxexm_resource_reference = {UINT32_C(0x602b0015),"resource_reference",sxexm_resource_reference_fields,SX_COUNT(sxexm_resource_reference_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_resource_data_length_fields[] = {
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxexm_resource_data_length = {UINT32_C(0x602b0016),"resource_data_length",sxexm_resource_data_length_fields,SX_COUNT(sxexm_resource_data_length_fields),SX_BE};
static const xx_data_struct_field_desc sxexm_resource_name_length_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxexm_resource_name_length = {UINT32_C(0x602b0017),"resource_name_length",sxexm_resource_name_length_fields,SX_COUNT(sxexm_resource_name_length_fields),SX_BE};
#define SXEXM_LIMIT 20000U
static bool sxexm_resource(sx_context *c){uint8_t h[28];if(!sxexm_read(c,0,h,16)||!sxexm_add(c,&sxexm_resource_fork_header,0))return false;uint64_t data=sxexm32(h,true),map=sxexm32(h+4,true),ds=sxexm32(h+8,true),ms=sxexm32(h+12,true);if(ms<28||!sxexm_span(c,map,ms)||!sxexm_span(c,data,ds)||!sxexm_read(c,map,h,28))return true;if(!sxexm_add(c,&sxexm_resource_map_header,map))return false;uint64_t t=sxexm16(h+24,true),names=sxexm16(h+26,true),count;if(t>ms||ms-t<2||!sxexm_word(c,map+t,2,true,&count))return true;if(!sxexm_add(c,&sxexm_resource_type_count,map+t))return false;count=count==65535?0:count+1;if(count>SXEXM_LIMIT||count>(ms-t-2)/8)return true;if(!sxexm_table(c,&sxexm_resource_type_entry,map+t+2,count))return false;
 for(uint64_t i=0;i<count&&c->count<SXEXM_LIMIT;i++){if(!sxexm_read(c,map+t+2+i*8,h,8))break;uint64_t n=(uint64_t)sxexm16(h+4,true)+1,p=t+sxexm16(h+6,true);if(n>SXEXM_LIMIT||p>ms||n>(ms-p)/12)continue;if(!sxexm_table(c,&sxexm_resource_reference,map+p,n))return false;for(uint64_t j=0;j<n&&c->count<SXEXM_LIMIT;j++){if(!sxexm_read(c,map+p+j*12,h,12))break;uint64_t off=sxexm_uint(h+5,3,true),name=sxexm16(h+2,true),z;if(off<=ds&&ds-off>=4&&sxexm_word(c,data+off,4,true,&z)&&z<=ds-off-4&&!sxexm_add(c,&sxexm_resource_data_length,data+off))return false;if(name!=65535&&names<=ms&&name<ms-names&&sxexm_word(c,map+names+name,1,true,&z)&&z<ms-names-name&&!sxexm_add(c,&sxexm_resource_name_length,map+names+name))return false;}}return true;}
bool sx_resourcefork_build(sx_context*c)
{
bool ok=false;
ok=sxexm_resource(c);
return ok&&sxexm_finish(c);
}
