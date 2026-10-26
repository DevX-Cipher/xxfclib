/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MVA data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_mva_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_NONE),
};
const sx_layout sxasy_mva_header = {UINT32_C(0x6044001c),"mva_header",sxasy_mva_header_fields,SX_COUNT(sxasy_mva_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_mva_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("modification_time","uint32",8,4,SX_NONE),
 SX_FIELD("creation_time","uint32",12,4,SX_NONE),
 SX_FIELD("path","char[260]",16,260,SX_NONE),
 SX_FIELD("uncompressed_size","int32",276,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",280,4,SX_SIZE),
 SX_FIELD("checksum1","uint32",284,4,SX_CHECKSUM),
 SX_FIELD("checksum2","uint32",288,4,SX_CHECKSUM),
 SX_FIELD("attributes","uint32",292,4,SX_NONE),
 SX_FIELD("opaque","uint8[50]",296,50,SX_NONE),
};
const sx_layout sxasy_mva_member = {UINT32_C(0x6044001d),"mva_member",sxasy_mva_member_fields,SX_COUNT(sxasy_mva_member_fields),SX_LE};
static bool sxasy_mva(sx_context*c){uint64_t p=8;if(!sxasy_add(c,&sxasy_mva_header,0))return false;for(unsigned i=0;i<SXASY_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[346];if(!sxasy_read(c,p,h,346)||xx_rt_memcmp(h,"mfen",4))return false;uint64_t z=sxasy_uint(h+280,4,false);if(z>INT32_MAX||!sxasy_span(c,p+346,z)||!sxasy_add(c,&sxasy_mva_member,p))return false;p+=346+z;}return true;}
bool sx_mva_build(sx_context*c)
{
 return sxasy_mva(c);
}
