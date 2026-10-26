/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Snatchit Cp2 data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_cp2_header_fields[] = {
    SX_FIELD("producer","char[16]",0,16,SX_NONE),
    SX_FIELD("release_label","char[8]",16,8,SX_NONE),
    SX_FIELD("version","char[4]",24,4,SX_ID),
    SX_FIELD("suffix","char[2]",28,2,SX_SIGNATURE),
};
const sx_layout sxdn_cp2_header = {0x6078001bU,"cp2_header",sxdn_cp2_header_fields,SX_COUNT(sxdn_cp2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_cp2_segment_header_fields[] = {
    SX_FIELD("track_headers_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxdn_cp2_segment_header = {0x6078001cU,"cp2_segment_header",sxdn_cp2_segment_header_fields,SX_COUNT(sxdn_cp2_segment_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_cp2_track_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_NONE),
    SX_FIELD("head","uint8",1,1,SX_NONE),
    SX_FIELD("sector_count","uint8",2,1,SX_COUNT_PROP),
};
const sx_layout sxdn_cp2_track = {0x6078001dU,"cp2_track",sxdn_cp2_track_fields,SX_COUNT(sxdn_cp2_track_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_cp2_sector_fields[] = {
    SX_FIELD("status","byte[4]",0,4,SX_NONE),
    SX_FIELD("cylinder","uint8",4,1,SX_NONE),
    SX_FIELD("head","uint8",5,1,SX_NONE),
    SX_FIELD("sector_id","uint8",6,1,SX_ID),
    SX_FIELD("sector_size_code","uint8",7,1,SX_NONE),
    SX_FIELD("biased_payload_offset","uint16",8,2,SX_OFFSET),
    SX_FIELD("unknown","byte[6]",10,6,SX_NONE),
};
const sx_layout sxdn_cp2_sector = {0x6078001eU,"cp2_sector",sxdn_cp2_sector_fields,SX_COUNT(sxdn_cp2_sector_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_cp2_header_checksum_fields[] = {
    SX_FIELD("checksum","uint8",0,1,SX_CHECKSUM),
};
const sx_layout sxdn_cp2_header_checksum = {0x6078001fU,"cp2_header_checksum",sxdn_cp2_header_checksum_fields,SX_COUNT(sxdn_cp2_header_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_cp2_segment_payload_fields[] = {
    SX_FIELD("payload_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxdn_cp2_segment_payload = {0x60780020U,"cp2_segment_payload",sxdn_cp2_segment_payload_fields,SX_COUNT(sxdn_cp2_segment_payload_fields),SX_LE};
#define SXDN_LIMIT 24000U
#define SXDN_ADD(c,l,p) sxdn_put(c,&sxdn_##l,p,1)
#define SXDN_TABLE(c,l,p,n) sxdn_put(c,&sxdn_##l,p,n)
static bool sxdn_cp2(sx_context*c){uint8_t h[3];if(!SXDN_ADD(c,cp2_header,0))return false;for(uint64_t p=30;p<(uint64_t)c->size&&c->count<SXDN_LIMIT;){if(!sxdn_read(c,p,h,2))break;uint64_t z=sxdn16(h,0);if(z<388||(z-1)%387||z>387*32+1||!sxdn_span(c,p,4+z)||!SXDN_ADD(c,cp2_segment_header,p))break;for(uint64_t i=0;i<(z-1)/387;i++){uint64_t a=p+2+i*387;if(!sxdn_read(c,a,h,3)||h[2]>24||!SXDN_ADD(c,cp2_track,a)||!SXDN_TABLE(c,cp2_sector,a+3,h[2]))return false;}if(!SXDN_ADD(c,cp2_header_checksum,p+1+z)||!SXDN_ADD(c,cp2_segment_payload,p+2+z)||!sxdn_read(c,p+2+z,h,2))return false;uint64_t n=sxdn16(h,0);p+=4+z;if(!sxdn_span(c,p,n))break;p+=n;}return true;}
bool sx_snatchit_cp2_build(sx_context*c)
{
 return sxdn_cp2(c);
}
#undef SXDN_LIMIT
#undef SXDN_ADD
#undef SXDN_TABLE
