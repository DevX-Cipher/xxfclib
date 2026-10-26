/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ARC v4 data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_arcv4_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("subvariant","uint16",6,2,SX_NONE),
};
const sx_layout sxasy_arcv4_header = {UINT32_C(0x60440004),"arcv4_header",sxasy_arcv4_header_fields,SX_COUNT(sxasy_arcv4_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_arcv4_record_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("chunk_type","uint32",4,4,SX_NONE),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("record_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxasy_arcv4_record = {UINT32_C(0x60440005),"arcv4_record",sxasy_arcv4_record_fields,SX_COUNT(sxasy_arcv4_record_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_arcv4_tag_size_fields[] = {
 SX_FIELD("tag_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxasy_arcv4_tag_size = {UINT32_C(0x60440006),"arcv4_tag_size",sxasy_arcv4_tag_size_fields,SX_COUNT(sxasy_arcv4_tag_size_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_arcv4_name_size_fields[] = {
 SX_FIELD("name_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxasy_arcv4_name_size = {UINT32_C(0x60440007),"arcv4_name_size",sxasy_arcv4_name_size_fields,SX_COUNT(sxasy_arcv4_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_arcv4_attributes_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("flags","uint32",4,4,SX_NONE),
 SX_FIELD("filetime","uint64",8,8,SX_NONE),
 SX_FIELD("opaque","uint8[8]",16,8,SX_NONE),
 SX_FIELD("compressed_size","uint32",24,4,SX_SIZE),
 SX_FIELD("method","uint32",28,4,SX_NONE),
};
const sx_layout sxasy_arcv4_attributes = {UINT32_C(0x60440008),"arcv4_attributes",sxasy_arcv4_attributes_fields,SX_COUNT(sxasy_arcv4_attributes_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_arcv4_data_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("chunk_type","uint32",4,4,SX_NONE),
 SX_FIELD("header_size","uint32",8,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("reserved1","uint32",16,4,SX_NONE),
 SX_FIELD("crc32","uint32",20,4,SX_CHECKSUM),
 SX_FIELD("reserved2","uint32",24,4,SX_NONE),
 SX_FIELD("reserved3","uint32",28,4,SX_NONE),
};
const sx_layout sxasy_arcv4_data = {UINT32_C(0x60440009),"arcv4_data",sxasy_arcv4_data_fields,SX_COUNT(sxasy_arcv4_data_fields),SX_LE};
static bool sxasy_arcv4(sx_context*c){uint64_t p=0x79c;if(!sxasy_span(c,0,p)||!sxasy_add(c,&sxasy_arcv4_header,0))return false;for(unsigned i=0;i<SXASY_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[32];if(!sxasy_read(c,p,h,16))return false;uint64_t hs=sxasy_uint(h+8,4,false),z=sxasy_uint(h+12,4,false);if(hs!=16||!sxasy_span(c,p+16,z)||(!xx_rt_memcmp(h,"EOFM",4)&&z))return false;if(!sxasy_add(c,&sxasy_arcv4_record,p))return false;if(!xx_rt_memcmp(h,"EOFM",4))return true;if(xx_rt_memcmp(h,"FILE",4))return false;uint64_t end=p+16+z,q=p+16,n;if(end-q<4||!sxasy_word(c,q,4,false,&n)||n>end-q-4||!sxasy_add(c,&sxasy_arcv4_tag_size,q))return false;q+=4+n;if(q>end||end-q<4||!sxasy_word(c,q,4,false,&n)||n>end-q-4||!sxasy_add(c,&sxasy_arcv4_name_size,q))return false;q+=4+n;if(end-q<32||!sxasy_add(c,&sxasy_arcv4_attributes,q))return false;p=end;if(!sxasy_read(c,p,h,32)||xx_rt_memcmp(h,"DATA",4)||sxasy_uint(h+8,4,false)!=32)return false;z=sxasy_uint(h+12,4,false);if(!sxasy_span(c,p+32,z)||!sxasy_add(c,&sxasy_arcv4_data,p))return false;p+=32+z;}return false;}
bool sx_arcv4_build(sx_context*c)
{
 return sxasy_arcv4(c);
}
