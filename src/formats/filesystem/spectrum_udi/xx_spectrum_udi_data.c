/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SPECTRUM_UDI data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_udi_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("size_without_crc","uint32",4,4,SX_SIZE),
    SX_FIELD("version","uint8",8,1,SX_NONE),
    SX_FIELD("last_cylinder","uint8",9,1,SX_NONE),
    SX_FIELD("last_head","uint8",10,1,SX_NONE),
    SX_FIELD("reserved","uint8",11,1,SX_RESERVED),
    SX_FIELD("extended_header_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxsl_udi_header = {0x6033002aU,"udi_header",sxsl_udi_header_fields,SX_COUNT(sxsl_udi_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_udi_track_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
    SX_FIELD("track_size","uint16",1,2,SX_SIZE),
};
const sx_layout sxsl_udi_track = {0x6033002bU,"udi_track",sxsl_udi_track_fields,SX_COUNT(sxsl_udi_track_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_udi_compressed_track_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
    SX_FIELD("compressed_size_minus_one","uint16",1,2,SX_NONE),
    SX_FIELD("original_type","uint8",3,1,SX_ID),
    SX_FIELD("track_size","uint16",4,2,SX_SIZE),
};
const sx_layout sxsl_udi_compressed_track = {0x6033002cU,"udi_compressed_track",sxsl_udi_compressed_track_fields,SX_COUNT(sxsl_udi_compressed_track_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_udi_checksum_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxsl_udi_checksum = {0x6033002dU,"udi_checksum",sxsl_udi_checksum_fields,SX_COUNT(sxsl_udi_checksum_fields),SX_LE};
#define SXSL_LIMIT 24000U
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
static bool sxsl_udi(sx_context*c){uint8_t h[16],b[6];if(!sxsl_read(c,0,h,16)||!SXSL_ADD(c,udi_header,0))return false;uint64_t end=sxsl32(h+4),p=16+(uint64_t)sxsl32(h+12),n=((uint64_t)h[9]+1)*(h[10]+1);if(end>=(uint64_t)c->size||!sxsl_span(c,end,4)||p>end||n>512)return true;if(!SXSL_ADD(c,udi_checksum,end))return false;for(uint64_t i=0;i<n&&c->count<SXSL_LIMIT;i++){if(p>end||end-p<3||!sxsl_read(c,p,b,3))break;uint64_t z;if(b[0]==0xf0){if(end-p<6||!sxsl_read(c,p,b,6))break;z=6+(uint64_t)sxsl16(b+1)+1;if(z>end-p||!SXSL_ADD(c,udi_compressed_track,p))break;}else{unsigned maps=b[0]<=1?1:b[0]==2||b[0]==0x80||b[0]==0x81?2:b[0]==0x82?3:0;uint64_t raw=sxsl16(b+1);if(!maps)break;z=3+raw+(raw+7)/8*maps;if(z>end-p||!SXSL_ADD(c,udi_track,p))break;}p+=z;}return true;}
bool sx_spectrum_udi_build(sx_context*c)
{
bool ok=false;
ok=sxsl_udi(c);
return ok&&sxsl_finish(c);
}
