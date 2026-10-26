/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LHWARP data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_lhwarp_header0_fields[] = {
    SX_FIELD("major_version","uint8",0,1,SX_ID),
    SX_FIELD("revision","uint8",1,1,SX_ID),
    SX_FIELD("minor_version","uint8",2,1,SX_ID),
    SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
    SX_FIELD("first_cylinder","uint16",4,2,SX_NONE),
    SX_FIELD("last_cylinder","uint16",6,2,SX_NONE),
    SX_FIELD("comment_size","uint32",8,4,SX_SIZE),
    SX_FIELD("packed_comment_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxst_lhwarp_header0 = {0x60370018U,"lhwarp_header0",sxst_lhwarp_header0_fields,SX_COUNT(sxst_lhwarp_header0_fields),SX_BE};
static const xx_data_struct_field_desc sxst_lhwarp_header3_fields[] = {
    SX_FIELD("major_version","uint8",0,1,SX_ID),
    SX_FIELD("revision","uint8",1,1,SX_ID),
    SX_FIELD("minor_version","uint8",2,1,SX_ID),
    SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
    SX_FIELD("first_cylinder","uint16",4,2,SX_NONE),
    SX_FIELD("last_cylinder","uint16",6,2,SX_NONE),
    SX_FIELD("comment_size","uint32",8,4,SX_SIZE),
    SX_FIELD("packed_comment_size","uint32",12,4,SX_SIZE),
    SX_FIELD("file_size","uint32",16,4,SX_SIZE),
};
const sx_layout sxst_lhwarp_header3 = {0x60370019U,"lhwarp_header3",sxst_lhwarp_header3_fields,SX_COUNT(sxst_lhwarp_header3_fields),SX_BE};
static const xx_data_struct_field_desc sxst_lhwarp_cylinder0_fields[] = {
    SX_FIELD("unknown_00","byte[2]",0,2,SX_NONE),
    SX_FIELD("cylinder","uint8",2,1,SX_NONE),
    SX_FIELD("unknown_03","uint8",3,1,SX_NONE),
    SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("byte_sum","uint32",12,4,SX_SIGNATURE),
};
const sx_layout sxst_lhwarp_cylinder0 = {0x6037001aU,"lhwarp_cylinder0",sxst_lhwarp_cylinder0_fields,SX_COUNT(sxst_lhwarp_cylinder0_fields),SX_BE};
static const xx_data_struct_field_desc sxst_lhwarp_cylinder_fields[] = {
    SX_FIELD("compression","uint8",0,1,SX_ID),
    SX_FIELD("flags","uint8",1,1,SX_FLAGS),
    SX_FIELD("cylinder","uint8",2,1,SX_NONE),
    SX_FIELD("unknown_03","uint8",3,1,SX_NONE),
    SX_FIELD("presence_bitmap","uint24le",4,3,SX_FLAGS),
    SX_FIELD("old_mode","uint8",7,1,SX_NONE),
    SX_FIELD("unpacked_size","uint32",8,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",12,4,SX_SIZE),
    SX_FIELD("data_crc","uint32",16,4,SX_CHECKSUM),
};
const sx_layout sxst_lhwarp_cylinder = {0x6037001bU,"lhwarp_cylinder",sxst_lhwarp_cylinder_fields,SX_COUNT(sxst_lhwarp_cylinder_fields),SX_BE};
static bool sxst_lhwarp(sx_context*c){uint8_t h[20],b[20];if(!sxst_read(c,0,h,16))return false;unsigned rev=h[1];uint64_t p=rev<3?16:20,low=sxst_uint(h+4,2,true),high=sxst_uint(h+6,2,true),z=sxst_uint(h+12,4,true);if(rev>3||!sxst_put(c,rev<3?&sxst_lhwarp_header0:&sxst_lhwarp_header3,0,1))return false;if(low>high||high>=80||!sxst_span(c,p,z))return true;p+=z;for(uint64_t i=low;i<=high;i++){unsigned hs=rev?20:16;if(!sxst_read(c,p,b,hs))break;z=sxst_uint(b+(rev?12:8),4,true);if(!sxst_span(c,p+hs,z)||!sxst_put(c,rev?&sxst_lhwarp_cylinder:&sxst_lhwarp_cylinder0,p,1))break;p+=hs+z;}return true;}
bool sx_lhwarp_build(sx_context*c)
{
 return sxst_lhwarp(c);
}
