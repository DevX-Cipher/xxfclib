/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Gbi data structures, moved out of the volumeimages schema family. */
#include "../../xx_format_schema_volumeimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvi_gbi_header100_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("table_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("version","uint32",20,4,SX_ID),
    SX_FIELD("data_offset","uint32",24,4,SX_OFFSET),
    SX_FIELD("marker","uint32",28,4,SX_SIGNATURE),
    SX_FIELD("reserved0","uint32",32,4,SX_RESERVED),
    SX_FIELD("chunk_size","uint32",36,4,SX_SIZE),
    SX_FIELD("image_size","uint64",40,8,SX_SIZE),
    SX_FIELD("container_size","uint64",48,8,SX_SIZE),
    SX_FIELD("reserved1","byte[16]",56,16,SX_RESERVED),
    SX_FIELD("crc32","uint32",72,4,SX_CHECKSUM),
};
const sx_layout sxvi_gbi_header100 = {0x6053001eU,"gbi_header100",sxvi_gbi_header100_fields,SX_COUNT(sxvi_gbi_header100_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_gbi_header110_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("table_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("version","uint32",20,4,SX_ID),
    SX_FIELD("encoded_data_offset","uint32",24,4,SX_FLAGS),
    SX_FIELD("marker","uint32",28,4,SX_SIGNATURE),
    SX_FIELD("reserved0","uint32",32,4,SX_RESERVED),
    SX_FIELD("chunk_size_and_flags","uint32",36,4,SX_FLAGS),
    SX_FIELD("image_size","uint64",40,8,SX_SIZE),
    SX_FIELD("container_size","uint64",48,8,SX_SIZE),
    SX_FIELD("profile","uint8",56,1,SX_ID),
    SX_FIELD("compressed_table_size","uint32",57,4,SX_SIZE),
    SX_FIELD("table_bit_widths","uint8",61,1,SX_FLAGS),
    SX_FIELD("lzma_filter","uint8",62,1,SX_ID),
    SX_FIELD("lzma_properties","byte[5]",63,5,SX_NONE),
    SX_FIELD("reserved1","byte[4]",68,4,SX_RESERVED),
    SX_FIELD("crc32","uint32",72,4,SX_CHECKSUM),
};
const sx_layout sxvi_gbi_header110 = {0x6053001fU,"gbi_header110",sxvi_gbi_header110_fields,SX_COUNT(sxvi_gbi_header110_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_gbi_descriptor_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_ID),
    SX_FIELD("size","uint32",4,4,SX_SIZE),
};
const sx_layout sxvi_gbi_descriptor = {0x60530020U,"gbi_descriptor",sxvi_gbi_descriptor_fields,SX_COUNT(sxvi_gbi_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_gbi_part_count_fields[] = {
    SX_FIELD("part_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxvi_gbi_part_count = {0x60530021U,"gbi_part_count",sxvi_gbi_part_count_fields,SX_COUNT(sxvi_gbi_part_count_fields),SX_LE};
#define SXVI_LIMIT 24000U
#define SXVI_ADD(c,l,p) sxvi_put(c,&sxvi_##l,p,1)
static bool sxvi_gbi(sx_context*c){uint8_t h[76],b[12];if(!sxvi_read(c,0,h,76)||xx_rt_memcmp(h,"GBI\0",4))return false;uint32_t v=sxvi32(h+20,0);if(v!=0x100&&v!=0x110)return false;if(!sxvi_put(c,v==0x100?&sxvi_gbi_header100:&sxvi_gbi_header110,0,1))return false;uint64_t end=sxvi32(h+16,0);if(end<76||end>(uint64_t)c->size)return true;
 for(uint64_t p=76;p+8<=end&&c->count<SXVI_LIMIT;){if(!sxvi_read(c,p,b,8))return false;uint64_t z=sxvi32(b+4,0);if(z<8||z>end-p)break;if(!SXVI_ADD(c,gbi_descriptor,p))return false;if(sxvi32(b,0)==2&&z>=16&&!SXVI_ADD(c,gbi_part_count,p+8))return false;p+=z;}return true;
}
bool sx_gbi_build(sx_context*c)
{
 return sxvi_gbi(c);
}
#undef SXVI_LIMIT
#undef SXVI_ADD
