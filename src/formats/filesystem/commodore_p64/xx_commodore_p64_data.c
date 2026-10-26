/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Commodore P64 data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_p64_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("version","uint32",8,4,SX_NONE),
    SX_FIELD("flags","uint32",12,4,SX_FLAGS),
    SX_FIELD("chunks_size","uint32",16,4,SX_SIZE),
    SX_FIELD("chunks_crc32","uint32",20,4,SX_CHECKSUM),
};
const sx_layout sxse_p64_header = {0x602f0007U,"p64_header",sxse_p64_header_fields,SX_COUNT(sxse_p64_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_p64_chunk_header_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("data_crc32","uint32",8,4,SX_CHECKSUM),
};
const sx_layout sxse_p64_chunk_header = {0x602f0008U,"p64_chunk_header",sxse_p64_chunk_header_fields,SX_COUNT(sxse_p64_chunk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_p64_halftrack_header_fields[] = {
    SX_FIELD("chunk_kind","char[3]",0,3,SX_ID),
    SX_FIELD("halftrack_and_side","uint8",3,1,SX_FLAGS),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("data_crc32","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("pulse_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("encoded_size","uint32",16,4,SX_SIZE),
};
const sx_layout sxse_p64_halftrack_header = {0x602f0009U,"p64_halftrack_header",sxse_p64_halftrack_header_fields,SX_COUNT(sxse_p64_halftrack_header_fields),SX_LE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
static bool sxse_p64(sx_context*c){uint8_t b[24];if(!sxse_read(c,0,b,24)||xx_rt_memcmp(b,"P64-1541",8)||!SXSE_ADD(c,p64_header,0,24))return false;uint64_t end=24+(uint64_t)sxse_u32(b,16,false),p=24;if(!sxse_span(c,24,end-24))return false;for(unsigned visit=0;p<end&&visit<4096;visit++){if(end-p<12||!sxse_read(c,p,b,12))return false;uint64_t z=sxse_u32(b,4,false);if(z>end-p-12)return false;bool ht=!xx_rt_memcmp(b,"HTP",3);if(ht&&z<8)return false;if(!sxse_put(c,ht?&sxse_p64_halftrack_header:&sxse_p64_chunk_header,p,ht?20:12,1))return false;p+=12+z;}return p==end;}
bool sx_commodore_p64_build(sx_context*c)
{
 return sxse_p64(c);
}
#undef SXSE_ADD
