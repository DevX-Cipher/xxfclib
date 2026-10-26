/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AMIGALZX data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_amigalzx_header_fields[] = {
    SX_FIELD("magic","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("flags_and_info","uint8[7]",3,7,SX_NONE),
};
const sx_layout sxae_amigalzx_header = {UINT32_C(0x60170034),"amigalzx_header",sxae_amigalzx_header_fields,SX_COUNT(sxae_amigalzx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_amigalzx_member_fields[] = {
    SX_FIELD("attributes","uint8",0,1,SX_FLAGS),
    SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
    SX_FIELD("unpacked_size","uint32",2,4,SX_SIZE),
    SX_FIELD("group_packed_size","uint32",6,4,SX_SIZE),
    SX_FIELD("machine","uint8",10,1,SX_ID),
    SX_FIELD("method","uint8",11,1,SX_ID),
    SX_FIELD("flags","uint8",12,1,SX_FLAGS),
    SX_FIELD("reserved13","uint8",13,1,SX_RESERVED),
    SX_FIELD("comment_size","uint8",14,1,SX_SIZE),
    SX_FIELD("extract_version","uint8",15,1,SX_NONE),
    SX_FIELD("reserved16","uint16",16,2,SX_RESERVED),
    SX_FIELD("date_time","uint32",18,4,SX_NONE),
    SX_FIELD("crc32","uint32",22,4,SX_CHECKSUM),
    SX_FIELD("header_crc32","uint32",26,4,SX_CHECKSUM),
    SX_FIELD("name_size","uint8",30,1,SX_SIZE),
};
const sx_layout sxae_amigalzx_member = {UINT32_C(0x60170035),"amigalzx_member",sxae_amigalzx_member_fields,SX_COUNT(sxae_amigalzx_member_fields),SX_LE};
static bool sxae_amigalzx(sx_context *c)
{
 uint8_t b[31];int64_t p=10;if(!sx_read(c,0,b,10)||xx_rt_memcmp(b,"LZX",3)||!sxae_add(c,&sxae_amigalzx_header,0))return false;
 for(unsigned i=0;p<c->size&&i<20000;i++){if(!sx_read(c,p,b,31)||!b[30]||!sxae_add(c,&sxae_amigalzx_member,p))return false;int64_t n=31+b[14]+b[30];uint32_t z=sxae32(b+6);if(!sxae_bound(c,p,n)||!sxae_data(c,p+n,z))return false;p+=n+z;}return p==c->size;
}
bool sx_amigalzx_build(sx_context*c)
{
 return sxae_amigalzx(c);
}
