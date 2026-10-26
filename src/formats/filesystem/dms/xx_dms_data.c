/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DMS data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_dms_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unknown_04","byte[6]",4,6,SX_NONE),
    SX_FIELD("general_info","uint16",10,2,SX_FLAGS),
    SX_FIELD("creation_time","uint32",12,4,SX_TIME),
    SX_FIELD("first_track","uint16",16,2,SX_NONE),
    SX_FIELD("last_track","uint16",18,2,SX_NONE),
    SX_FIELD("packed_size","uint32",20,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",24,4,SX_SIZE),
    SX_FIELD("unknown_1c","byte[18]",28,18,SX_NONE),
    SX_FIELD("creator_version","uint16",46,2,SX_NONE),
    SX_FIELD("unknown_30","byte[2]",48,2,SX_NONE),
    SX_FIELD("disk_type","uint16",50,2,SX_ID),
    SX_FIELD("compression_mode","uint16",52,2,SX_ID),
    SX_FIELD("header_crc","uint16",54,2,SX_CHECKSUM),
};
const sx_layout sxsl_dms_header = {0x6033003bU,"dms_header",sxsl_dms_header_fields,SX_COUNT(sxsl_dms_header_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_dms_track_fields[] = {
    SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("track_number","uint16",2,2,SX_NONE),
    SX_FIELD("reserved","uint16",4,2,SX_RESERVED),
    SX_FIELD("packed_size","uint16",6,2,SX_SIZE),
    SX_FIELD("intermediate_size","uint16",8,2,SX_SIZE),
    SX_FIELD("unpacked_size","uint16",10,2,SX_SIZE),
    SX_FIELD("flags","uint8",12,1,SX_FLAGS),
    SX_FIELD("compression_mode","uint8",13,1,SX_ID),
    SX_FIELD("unpacked_checksum","uint16",14,2,SX_CHECKSUM),
    SX_FIELD("packed_crc","uint16",16,2,SX_CHECKSUM),
    SX_FIELD("header_crc","uint16",18,2,SX_CHECKSUM),
};
const sx_layout sxsl_dms_track = {0x6033003cU,"dms_track",sxsl_dms_track_fields,SX_COUNT(sxsl_dms_track_fields),SX_BE};
#define SXSL_LIMIT 24000U
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
static bool sxsl_dms(sx_context*c){uint8_t b[88];uint64_t p=0;if(!sxsl_read(c,0,b,56))return false;if(xx_rt_memcmp(b,"DMS!",4)){if(!sxsl_read(c,0,b,88)||sxsl_uint(b,4,true)!=0x3f3)return false;uint64_t kind=sxsl_uint(b+20,4,true);p=kind==0x1605?0x58c4:kind==0x2462?0x45d0:kind==0x2466?0x45e0:kind==0x3269?0x537c:0;if(!p||!sxsl_read(c,p,b,56)||xx_rt_memcmp(b,"DMS!",4))return false;}if(!SXSL_ADD(c,dms_header,p))return false;p+=56;for(unsigned i=0;i<SXSL_LIMIT&&c->count<SXSL_LIMIT;i++){if(!sxsl_read(c,p,b,20)||xx_rt_memcmp(b,"TR",2))break;uint64_t z=sxsl_uint(b+6,2,true);if(!sxsl_span(c,p+20,z)||!SXSL_ADD(c,dms_track,p))break;p+=20+z;}return true;}
bool sx_dms_build(sx_context*c)
{
bool ok=false;
ok=sxsl_dms(c);
return ok&&sxsl_finish(c);
}
