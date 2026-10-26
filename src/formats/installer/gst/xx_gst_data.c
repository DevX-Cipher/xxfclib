/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GST data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_gst_member_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("stamp","uint32",2,4,SX_NONE),
 SX_FIELD("flags","uint8",6,1,SX_FLAGS),
 SX_FIELD("method","uint8",7,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("name","char[12]",16,12,SX_NONE),
 SX_FIELD("crc32","uint32",28,4,SX_CHECKSUM),
};
const sx_layout sxat_gst_member = {UINT32_C(0x60640011),"gst_member",sxat_gst_member_fields,SX_COUNT(sxat_gst_member_fields),SX_LE};
static bool sxat_gst(sx_context*c){uint64_t p=0;while(sxat_span(c,p,32)){uint8_t h[32];if(!sxat_read(c,p,h,32))return false;uint64_t z=sxat_uint(h+12,4,false);if(!sxat_add(c,&sxat_gst_member,p))return false;p+=32;if(!sxat_span(c,p,z))return true;if(h[7]==1&&!sxat_dcl(c,p,z))return false;p+=z;}return true;}
bool sx_gst_build(sx_context*c)
{
 return sxat_gst(c);
}
