/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MOOF data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_moof_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("binary_marker","byte[4]",4,4,SX_SIGNATURE),
    SX_FIELD("crc32","uint32",8,4,SX_CHECKSUM),
};
const sx_layout sxsl_moof_header = {0x6033002eU,"moof_header",sxsl_moof_header_fields,SX_COUNT(sxsl_moof_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_moof_chunk_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxsl_moof_chunk = {0x6033002fU,"moof_chunk",sxsl_moof_chunk_fields,SX_COUNT(sxsl_moof_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_moof_info_fields[] = {
    SX_FIELD("version","uint8",0,1,SX_NONE),
    SX_FIELD("disk_type","uint8",1,1,SX_ID),
    SX_FIELD("write_protected","uint8",2,1,SX_FLAGS),
    SX_FIELD("synchronized","uint8",3,1,SX_FLAGS),
    SX_FIELD("optimal_bit_timing","uint8",4,1,SX_NONE),
    SX_FIELD("creator","char[32]",5,32,SX_NONE),
    SX_FIELD("reserved","uint8",37,1,SX_RESERVED),
    SX_FIELD("largest_track_blocks","uint16",38,2,SX_COUNT_PROP),
    SX_FIELD("flux_block","uint16",40,2,SX_NONE),
    SX_FIELD("largest_flux_track_blocks","uint16",42,2,SX_COUNT_PROP),
};
const sx_layout sxsl_moof_info = {0x60330030U,"moof_info",sxsl_moof_info_fields,SX_COUNT(sxsl_moof_info_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_moof_track_map_fields[] = {
    SX_FIELD("track_index","uint8",0,1,SX_NONE),
};
const sx_layout sxsl_moof_track_map = {0x60330031U,"moof_track_map",sxsl_moof_track_map_fields,SX_COUNT(sxsl_moof_track_map_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_moof_track_fields[] = {
    SX_FIELD("starting_block","uint16",0,2,SX_NONE),
    SX_FIELD("block_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("bit_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxsl_moof_track = {0x60330032U,"moof_track",sxsl_moof_track_fields,SX_COUNT(sxsl_moof_track_fields),SX_LE};
#define SXSL_LIMIT 24000U
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
#define SXSL_TABLE(c,l,p,n) sxsl_put(c,&sxsl_##l,p,n)
static bool sxsl_moof(sx_context*c){uint8_t b[8];uint64_t p=12;if(!SXSL_ADD(c,moof_header,0))return false;for(unsigned i=0;i<4096&&c->count<SXSL_LIMIT;i++){if(!sxsl_read(c,p,b,8)||!sxsl32(b))break;uint64_t z=sxsl32(b+4),q=p+8;if(!sxsl_span(c,q,z)||!SXSL_ADD(c,moof_chunk,p))break;if(!xx_rt_memcmp(b,"INFO",4)&&z>=44){if(!SXSL_ADD(c,moof_info,q))return false;}else if((!xx_rt_memcmp(b,"TMAP",4)||!xx_rt_memcmp(b,"FLUX",4))&&z>=160){if(!SXSL_TABLE(c,moof_track_map,q,160))return false;}else if(!xx_rt_memcmp(b,"TRKS",4)&&z>=1280){if(!SXSL_TABLE(c,moof_track,q,160))return false;}p=q+z;}return true;}
bool sx_moof_build(sx_context*c)
{
bool ok=false;
ok=sxsl_moof(c);
return ok&&sxsl_finish(c);
}
