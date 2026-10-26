/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FPAK data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_fpak_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("set_compressed_size","uint32",6,4,SX_SIZE),
 SX_FIELD("set_uncompressed_size","uint32",10,4,SX_SIZE),
 SX_FIELD("description_size","uint16",14,2,SX_SIZE),
};
const sx_layout sxat_fpak_header = {UINT32_C(0x6064000d),"fpak_header",sxat_fpak_header_fields,SX_COUNT(sxat_fpak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_fpac_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxat_fpac_header = {UINT32_C(0x6064000e),"fpac_header",sxat_fpac_header_fields,SX_COUNT(sxat_fpac_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_fpak_segment_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("flags","uint16",4,2,SX_FLAGS),
 SX_FIELD("method","uint16",6,2,SX_NONE),
 SX_FIELD("dos_time","uint16",8,2,SX_NONE),
 SX_FIELD("dos_date","uint16",10,2,SX_NONE),
 SX_FIELD("crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("compressed_size","uint32",16,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("segment_size","uint32",24,4,SX_SIZE),
 SX_FIELD("name_size","uint16",28,2,SX_SIZE),
};
const sx_layout sxat_fpak_segment = {UINT32_C(0x6064000f),"fpak_segment",sxat_fpak_segment_fields,SX_COUNT(sxat_fpak_segment_fields),SX_LE};
static bool sxat_fpak(sx_context*c){uint8_t magic[4];uint64_t p,n;if(!sxat_read(c,0,magic,4))return false;if(!xx_rt_memcmp(magic,"FPAK",4)){if(!sxat_word(c,14,2,false,&n)||!sxat_add(c,&sxat_fpak_header,0)||!sxat_span(c,16,n))return false;p=16+n;}else if(!xx_rt_memcmp(magic,"FPAC",4)){if(!sxat_add(c,&sxat_fpac_header,0))return false;p=4;}else return false;while(sxat_span(c,p,30)){uint8_t h[30];if(!sxat_read(c,p,h,30)||xx_rt_memcmp(h,"FPPF",4))return true;uint64_t z=sxat_uint(h+24,4,false),name=sxat_uint(h+28,2,false);if(!sxat_add(c,&sxat_fpak_segment,p)||!sxat_span(c,p+30,name))return false;p+=30+name;if(!sxat_span(c,p,z))return true;p+=z;}return true;}
bool sx_fpak_build(sx_context*c)
{
 return sxat_fpak(c);
}
