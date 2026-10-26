/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FLS data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_fls_count_fields[] = {
 SX_FIELD("record_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxacl_fls_count = {UINT32_C(0x60500028),"fls_count",sxacl_fls_count_fields,SX_COUNT(sxacl_fls_count_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_fls_header_record_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("reserved","uint8",1,1,SX_NONE),
 SX_FIELD("signature","uint8[6]",2,6,SX_SIGNATURE),
 SX_FIELD("opaque1","uint8[15]",8,15,SX_NONE),
 SX_FIELD("name_block_size","uint32",23,4,SX_SIZE),
 SX_FIELD("opaque2","uint8[17]",27,17,SX_NONE),
};
const sx_layout sxacl_fls_header_record = {UINT32_C(0x60500029),"fls_header_record",sxacl_fls_header_record_fields,SX_COUNT(sxacl_fls_header_record_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_fls_member_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("compressed","uint8",1,1,SX_NONE),
 SX_FIELD("signature","uint8[4]",2,4,SX_SIGNATURE),
 SX_FIELD("flag","uint8",6,1,SX_NONE),
 SX_FIELD("letter","char[1]",7,1,SX_NONE),
 SX_FIELD("name_reference","uint32",8,4,SX_OFFSET),
 SX_FIELD("component_count","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("tail_size","uint32",14,4,SX_SIZE),
 SX_FIELD("opaque1","uint8",18,1,SX_NONE),
 SX_FIELD("payload_offset","uint32",19,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",23,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",27,2,SX_NONE),
 SX_FIELD("dos_time","uint16",29,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",31,4,SX_SIZE),
 SX_FIELD("opaque2","uint8[9]",35,9,SX_NONE),
};
const sx_layout sxacl_fls_member = {UINT32_C(0x6050002a),"fls_member",sxacl_fls_member_fields,SX_COUNT(sxacl_fls_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_fls_name_header_fields[] = {
 SX_FIELD("marker","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("signature","char[7]",2,7,SX_SIGNATURE),
};
const sx_layout sxacl_fls_name_header = {UINT32_C(0x6050002b),"fls_name_header",sxacl_fls_name_header_fields,SX_COUNT(sxacl_fls_name_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_fls_component_offset_fields[] = {
 SX_FIELD("component_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxacl_fls_component_offset = {UINT32_C(0x6050002c),"fls_component_offset",sxacl_fls_component_offset_fields,SX_COUNT(sxacl_fls_component_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_fls_component_size_fields[] = {
 SX_FIELD("component_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxacl_fls_component_size = {UINT32_C(0x6050002d),"fls_component_size",sxacl_fls_component_size_fields,SX_COUNT(sxacl_fls_component_size_fields),SX_LE};
static bool sxacl_fls(sx_context*c){uint64_t n,names,base,bytes;if(!sxacl_word(c,0,2,false,&n)||n<2||!sxacl_span(c,2,n*44)||!sxacl_word(c,25,4,false,&bytes)||!sxacl_add(c,&sxacl_fls_count,0)||!sxacl_add(c,&sxacl_fls_header_record,2))return false;base=2+n*44;if(bytes<9||!sxacl_span(c,base,bytes)||!sxacl_add(c,&sxacl_fls_name_header,base))return false;for(uint64_t i=1;i<n;i++)if(!sxacl_add(c,&sxacl_fls_member,2+i*44))return false;for(uint64_t i=1;i<n;i++){uint8_t h[14];if(!sxacl_read(c,2+i*44,h,14))return false;uint64_t off=sxacl_uint(h+8,4,false);names=sxacl_uint(h+12,2,false);if(off>bytes||names>(bytes-off)/4)continue;for(uint64_t j=0;j<names;j++){uint64_t q,z;if(!sxacl_word(c,base+off+j*4,4,false,&q)||!sxacl_add(c,&sxacl_fls_component_offset,base+off+j*4))return false;if(q<9||q>=bytes||!sxacl_word(c,base+q,1,false,&z)||z>bytes-q-1)continue;if(!sxacl_add(c,&sxacl_fls_component_size,base+q))return false;}}return true;}
bool sx_fls_build(sx_context*c)
{
 return sxacl_fls(c);
}
