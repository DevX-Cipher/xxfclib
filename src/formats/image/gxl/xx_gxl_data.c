/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GXL data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_gxl_header_fields[] = {
    SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("copyright","char[50]",2,50,SX_STRING),
    SX_FIELD("version","uint16",52,2,SX_NONE),
    SX_FIELD("volume","char[40]",54,40,SX_STRING),
    SX_FIELD("member_count","uint16",94,2,SX_COUNT_PROP),
    SX_FIELD("unused","uint8[32]",96,32,SX_RESERVED),
};
const sx_layout sxae_gxl_header = {UINT32_C(0x6017000b),"gxl_header",sxae_gxl_header_fields,SX_COUNT(sxae_gxl_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_gxl_member_fields[] = {
    SX_FIELD("method","uint8",0,1,SX_ID),
    SX_FIELD("base_name","char[8]",1,8,SX_STRING),
    SX_FIELD("extension","char[4]",9,4,SX_STRING),
    SX_FIELD("unused","uint8",13,1,SX_RESERVED),
    SX_FIELD("data_offset","uint32",14,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",18,4,SX_SIZE),
    SX_FIELD("time","uint16",22,2,SX_NONE),
    SX_FIELD("date","uint16",24,2,SX_NONE),
};
const sx_layout sxae_gxl_member = {UINT32_C(0x6017000c),"gxl_member",sxae_gxl_member_fields,SX_COUNT(sxae_gxl_member_fields),SX_LE};
static bool sxae_gxl(sx_context *c)
{
 uint8_t b[128];if(!sx_read(c,0,b,128)||sxae16(b)!=0xca01)return false;uint16_t n=sxae16(b+94);int64_t e=128+(int64_t)n*26;
 if(!n||n>20000||!sxae_bound(c,0,e)||!sxae_add(c,&sxae_gxl_header,0)||!sx_table(c,&sxae_gxl_member,128,26,n))return false;
 for(unsigned i=0;i<n;i++){uint8_t r[26];if(!sx_read(c,128+(int64_t)i*26,r,26))return false;uint32_t o=sxae32(r+14),z=sxae32(r+18);if(o<e||!sxae_bound(c,o,z))return false;}return true;
}
bool sx_gxl_build(sx_context*c)
{
 return sxae_gxl(c);
}
