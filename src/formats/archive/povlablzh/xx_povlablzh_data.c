/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * POV-Lab LZH data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_povlab_header_fields[] = {
 SX_FIELD("header_payload_size","uint8",0,1,SX_SIZE),
 SX_FIELD("checksum","uint8",1,1,SX_CHECKSUM),
 SX_FIELD("method","char[5]",2,5,SX_NONE),
 SX_FIELD("skip_size","uint32",7,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",11,4,SX_SIZE),
 SX_FIELD("dos_timestamp","uint32",15,4,SX_NONE),
 SX_FIELD("attributes","uint8",19,1,SX_NONE),
 SX_FIELD("level","uint8",20,1,SX_NONE),
 SX_FIELD("name_size","uint8",21,1,SX_SIZE),
};
const sx_layout sxasy_povlab_header = {UINT32_C(0x6044001e),"povlab_header",sxasy_povlab_header_fields,SX_COUNT(sxasy_povlab_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_povlab_attributes_fields[] = {
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
 SX_FIELD("origin_os","uint8",2,1,SX_NONE),
};
const sx_layout sxasy_povlab_attributes = {UINT32_C(0x6044001f),"povlab_attributes",sxasy_povlab_attributes_fields,SX_COUNT(sxasy_povlab_attributes_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_povlab_extension_size_fields[] = {
 SX_FIELD("next_header_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxasy_povlab_extension_size = {UINT32_C(0x60440020),"povlab_extension_size",sxasy_povlab_extension_size_fields,SX_COUNT(sxasy_povlab_extension_size_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_povlab_extension_type_fields[] = {
 SX_FIELD("type","uint8",0,1,SX_NONE),
};
const sx_layout sxasy_povlab_extension_type = {UINT32_C(0x60440021),"povlab_extension_type",sxasy_povlab_extension_type_fields,SX_COUNT(sxasy_povlab_extension_type_fields),SX_LE};
static bool sxasy_pov(sx_context*c){uint64_t p=0;for(unsigned i=0;i<SXASY_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[22];if(!sxasy_read(c,p,h,1)||!h[0])return true;if(!sxasy_read(c,p,h,22))return false;uint64_t hs=h[0]+2,z=sxasy_uint(h+7,4,false),n=h[21],ex,q;if(hs<27+n||!sxasy_span(c,p,hs)||!sxasy_span(c,p+hs,z)||!sxasy_add(c,&sxasy_povlab_header,p)||!sxasy_add(c,&sxasy_povlab_attributes,p+22+n)||!sxasy_add(c,&sxasy_povlab_extension_size,p+hs-2)||!sxasy_word(c,p+hs-2,2,false,&ex))return false;q=p+hs;uint64_t used=0;while(ex){if(ex<3||ex>z-used||!sxasy_span(c,q,ex)||!sxasy_add(c,&sxasy_povlab_extension_type,q)||!sxasy_add(c,&sxasy_povlab_extension_size,q+ex-2))return false;used+=ex;q+=ex;if(!sxasy_word(c,q-2,2,false,&ex))return false;}p+=hs+z;}return true;}
bool sx_povlablzh_build(sx_context*c)
{
 return sxasy_pov(c);
}
