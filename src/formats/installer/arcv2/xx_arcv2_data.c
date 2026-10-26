/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ARC v2 data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_arcv2_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("volume_flags","uint32",8,4,SX_NONE),
 SX_FIELD("disk_number","uint16",12,2,SX_NONE),
};
const sx_layout sxasy_arcv2_header = {UINT32_C(0x60440001),"arcv2_header",sxasy_arcv2_header_fields,SX_COUNT(sxasy_arcv2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_arcv2_block_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("flags","uint32",8,4,SX_NONE),
 SX_FIELD("volume_payload_size","uint32",12,4,SX_SIZE),
 SX_FIELD("name_size","uint8",16,1,SX_SIZE),
};
const sx_layout sxasy_arcv2_block = {UINT32_C(0x60440002),"arcv2_block",sxasy_arcv2_block_fields,SX_COUNT(sxasy_arcv2_block_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_arcv2_attributes_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("attributes","uint32",8,4,SX_NONE),
 SX_FIELD("dos_timestamp","uint32",12,4,SX_NONE),
 SX_FIELD("opaque","uint8[8]",16,8,SX_NONE),
 SX_FIELD("packed_crc32","uint32",24,4,SX_CHECKSUM),
};
const sx_layout sxasy_arcv2_attributes = {UINT32_C(0x60440003),"arcv2_attributes",sxasy_arcv2_attributes_fields,SX_COUNT(sxasy_arcv2_attributes_fields),SX_LE};
static bool sxasy_arcv2(sx_context*c){uint64_t p=14;if(!sxasy_add(c,&sxasy_arcv2_header,0))return false;for(unsigned i=0;i<SXASY_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[17];if(!sxasy_read(c,p,h,17)||xx_rt_memcmp(h,"BLCK",4))return false;uint64_t hs=sxasy_uint(h+6,2,false),z=sxasy_uint(h+12,4,false);if(hs!=45U+h[16]||!sxasy_span(c,p,hs)||!sxasy_span(c,p+hs,z)||!sxasy_add(c,&sxasy_arcv2_block,p)||!sxasy_add(c,&sxasy_arcv2_attributes,p+17+h[16]))return false;p+=hs+z;}return p==(uint64_t)c->size;}
bool sx_arcv2_build(sx_context*c)
{
 return sxasy_arcv2(c);
}
