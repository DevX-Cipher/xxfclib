/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * JETBBS data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_jetbbs_member_fields[] = {
 SX_FIELD("header_payload_size","uint8",0,1,SX_SIZE),
 SX_FIELD("header_checksum","uint8",1,1,SX_CHECKSUM),
 SX_FIELD("method","char[5]",2,5,SX_NONE),
 SX_FIELD("compressed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",11,4,SX_SIZE),
 SX_FIELD("dos_timestamp","uint32",15,4,SX_NONE),
 SX_FIELD("attributes","uint8",19,1,SX_NONE),
 SX_FIELD("level","uint8",20,1,SX_NONE),
 SX_FIELD("name_size","uint8",21,1,SX_SIZE),
};
const sx_layout sxacl_jetbbs_member = {UINT32_C(0x6050000f),"jetbbs_member",sxacl_jetbbs_member_fields,SX_COUNT(sxacl_jetbbs_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jetbbs_crc16_fields[] = {
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
const sx_layout sxacl_jetbbs_crc16 = {UINT32_C(0x60500010),"jetbbs_crc16",sxacl_jetbbs_crc16_fields,SX_COUNT(sxacl_jetbbs_crc16_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jetbbs_os_fields[] = {
 SX_FIELD("origin_os","uint8",0,1,SX_NONE),
};
const sx_layout sxacl_jetbbs_os = {UINT32_C(0x60500011),"jetbbs_os",sxacl_jetbbs_os_fields,SX_COUNT(sxacl_jetbbs_os_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jetbbs_extension_size_fields[] = {
 SX_FIELD("next_header_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxacl_jetbbs_extension_size = {UINT32_C(0x60500012),"jetbbs_extension_size",sxacl_jetbbs_extension_size_fields,SX_COUNT(sxacl_jetbbs_extension_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jetbbs_extension_type_fields[] = {
 SX_FIELD("type","uint8",0,1,SX_NONE),
};
const sx_layout sxacl_jetbbs_extension_type = {UINT32_C(0x60500013),"jetbbs_extension_type",sxacl_jetbbs_extension_type_fields,SX_COUNT(sxacl_jetbbs_extension_type_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_jetbbs_sizes64_fields[] = {
 SX_FIELD("compressed_size","uint64",0,8,SX_SIZE),
 SX_FIELD("uncompressed_size","uint64",8,8,SX_SIZE),
};
const sx_layout sxacl_jetbbs_sizes64 = {UINT32_C(0x60500014),"jetbbs_sizes64",sxacl_jetbbs_sizes64_fields,SX_COUNT(sxacl_jetbbs_sizes64_fields),SX_LE};
#define SXACL_LIMIT 20000U
static bool sxacl_jet(sx_context*c){uint64_t p=0;for(unsigned i=0;i<SXACL_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[22];if(!sxacl_read(c,p,h,1)||!h[0])return true;if(!sxacl_read(c,p,h,22)||h[20]>1)return false;uint64_t hs=h[0]+2,n=h[21],z=sxacl_uint(h+7,4,false),q=p+hs,used=0;if(hs<(h[20]?27:24)+n||!sxacl_span(c,p,hs)||!sxacl_span(c,q,z)||!sxacl_add(c,&sxacl_jetbbs_member,p)||!sxacl_add(c,&sxacl_jetbbs_crc16,p+22+n))return false;if(h[20]){uint64_t ex;if(!sxacl_add(c,&sxacl_jetbbs_os,p+24+n)||!sxacl_add(c,&sxacl_jetbbs_extension_size,p+hs-2)||!sxacl_word(c,p+hs-2,2,false,&ex))return false;while(ex){uint8_t type;if(ex<3||ex>z-used||!sxacl_read(c,q,&type,1)||!sxacl_add(c,&sxacl_jetbbs_extension_type,q))return false;if(type==0&&ex>=5){if(!sxacl_add(c,&sxacl_jetbbs_crc16,q+1))return false;}else if(type==0x42&&ex>=19){if(!sxacl_add(c,&sxacl_jetbbs_sizes64,q+1))return false;}if(!sxacl_add(c,&sxacl_jetbbs_extension_size,q+ex-2))return false;used+=ex;q+=ex;if(!sxacl_word(c,q-2,2,false,&ex))return false;}}p+=hs+z;}return true;}
bool sx_jetbbs_build(sx_context*c)
{
 return sxacl_jet(c);
}
