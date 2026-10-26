/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MDCD data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_mdcd_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_NONE),
 SX_FIELD("header_type","uint8",5,1,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("unused","uint8[16]",8,16,SX_NONE),
 SX_FIELD("method","uint8",24,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",25,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",29,4,SX_SIZE),
 SX_FIELD("attributes","uint16",33,2,SX_FLAGS),
 SX_FIELD("dos_time","uint16",35,2,SX_NONE),
 SX_FIELD("dos_date","uint16",37,2,SX_NONE),
 SX_FIELD("crc16","uint16",39,2,SX_CHECKSUM),
 SX_FIELD("name_size","uint8",41,1,SX_SIZE),
 SX_FIELD("name","char[12]",42,12,SX_NONE),
};
const sx_layout sxat_mdcd_member = {UINT32_C(0x60640022),"mdcd_member",sxat_mdcd_member_fields,SX_COUNT(sxat_mdcd_member_fields),SX_LE};
static const xx_data_struct_field_desc sxat_mdcd_path_fields[] = {
 SX_FIELD("path_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxat_mdcd_path = {UINT32_C(0x60640023),"mdcd_path",sxat_mdcd_path_fields,SX_COUNT(sxat_mdcd_path_fields),SX_LE};
static bool sxat_mdcd(sx_context*c){uint64_t p=0;while(sxat_span(c,p,54)){uint8_t h[54];if(!sxat_read(c,p,h,54)||xx_rt_memcmp(h,"MDmd",4))return true;uint64_t hs=sxat_uint(h+6,2,false),z=sxat_uint(h+29,4,false);if(hs<54||!sxat_span(c,p,hs)||!sxat_add(c,&sxat_mdcd_member,p))return false;if(hs>=55&&!sxat_add(c,&sxat_mdcd_path,p+54))return false;p+=hs;if(!sxat_span(c,p,z))return true;p+=z;}return true;}
bool sx_mdcd_build(sx_context*c)
{
 return sxat_mdcd(c);
}
