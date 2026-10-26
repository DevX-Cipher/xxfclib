/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HEATHKIT_H17 data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_h17_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","char[3]",4,3,SX_NONE),
    SX_FIELD("eight_bit_check","uint8",7,1,SX_SIGNATURE),
};
const sx_layout sxst_h17_header = {0x6037003aU,"h17_header",sxst_h17_header_fields,SX_COUNT(sxst_h17_header_fields),SX_BE};
static const xx_data_struct_field_desc sxst_h17_chunk_fields[] = {
    SX_FIELD("type","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxst_h17_chunk = {0x6037003bU,"h17_chunk",sxst_h17_chunk_fields,SX_COUNT(sxst_h17_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxst_h17_disk_format2_fields[] = {
    SX_FIELD("sides","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("tracks_per_side","uint8",1,1,SX_COUNT_PROP),
};
const sx_layout sxst_h17_disk_format2 = {0x6037003cU,"h17_disk_format2",sxst_h17_disk_format2_fields,SX_COUNT(sxst_h17_disk_format2_fields),SX_BE};
static const xx_data_struct_field_desc sxst_h17_disk_format3_fields[] = {
    SX_FIELD("sides","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("tracks_per_side","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("read_only","uint8",2,1,SX_FLAGS),
};
const sx_layout sxst_h17_disk_format3 = {0x6037003dU,"h17_disk_format3",sxst_h17_disk_format3_fields,SX_COUNT(sxst_h17_disk_format3_fields),SX_BE};
static const xx_data_struct_field_desc sxst_h17_parameters1_fields[] = {
    SX_FIELD("distribution_disk","uint8",0,1,SX_ID),
};
const sx_layout sxst_h17_parameters1 = {0x6037003eU,"h17_parameters1",sxst_h17_parameters1_fields,SX_COUNT(sxst_h17_parameters1_fields),SX_BE};
static const xx_data_struct_field_desc sxst_h17_parameters2_fields[] = {
    SX_FIELD("distribution_disk","uint8",0,1,SX_ID),
    SX_FIELD("header_data_source","uint8",1,1,SX_ID),
};
const sx_layout sxst_h17_parameters2 = {0x6037003fU,"h17_parameters2",sxst_h17_parameters2_fields,SX_COUNT(sxst_h17_parameters2_fields),SX_BE};
static const xx_data_struct_field_desc sxst_h17_sector_metadata_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("status","uint8",4,1,SX_FLAGS),
    SX_FIELD("header_sync","uint8",5,1,SX_SIGNATURE),
    SX_FIELD("volume_number","uint8",6,1,SX_NONE),
    SX_FIELD("track","uint8",7,1,SX_NONE),
    SX_FIELD("sector","uint8",8,1,SX_NONE),
    SX_FIELD("header_checksum","uint8",9,1,SX_CHECKSUM),
    SX_FIELD("data_sync","uint8",10,1,SX_SIGNATURE),
    SX_FIELD("data_checksum","uint8",11,1,SX_CHECKSUM),
    SX_FIELD("valid_bytes","uint16",12,2,SX_SIZE),
    SX_FIELD("reserved","byte[2]",14,2,SX_RESERVED),
};
const sx_layout sxst_h17_sector_metadata = {0x60370040U,"h17_sector_metadata",sxst_h17_sector_metadata_fields,SX_COUNT(sxst_h17_sector_metadata_fields),SX_BE};
#define SXST_LIMIT 24000U
#define SXST_ROWS 1048576U
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
#define SXST_TABLE(c,l,p,n) sxst_put(c,&sxst_##l,p,n)
static bool sxst_h17(sx_context*c){uint8_t b[8];uint64_t p=8;if(!SXST_ADD(c,h17_header,0))return false;for(unsigned i=0;i<4096&&c->count<SXST_LIMIT;i++){if(!sxst_read(c,p,b,8))break;uint64_t z=sxst_uint(b+4,4,true),q=p+8;if(!sxst_span(c,q,z)||!SXST_ADD(c,h17_chunk,p))break;if(!xx_rt_memcmp(b,"DskF",4)&&(z==2||z==3)){if(!sxst_put(c,z==2?&sxst_h17_disk_format2:&sxst_h17_disk_format3,q,1))return false;}else if(!xx_rt_memcmp(b,"Parm",4)&&(z==1||z==2)){if(!sxst_put(c,z==1?&sxst_h17_parameters1:&sxst_h17_parameters2,q,1))return false;}else if(!xx_rt_memcmp(b,"SecM",4)&&z%16==0&&z/16<=SXST_ROWS){if(!SXST_TABLE(c,h17_sector_metadata,q,z/16))return false;}p=q+z;}return true;}
bool sx_heathkit_h17_build(sx_context*c)
{
 return sxst_h17(c);
}
#undef SXST_LIMIT
#undef SXST_ROWS
#undef SXST_ADD
#undef SXST_TABLE
