/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HAP data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_hap_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("reserved","uint8[11]",4,11,SX_RESERVED),
};
const sx_layout sxae_hap_header = {UINT32_C(0x6017001c),"hap_header",sxae_hap_header_fields,SX_COUNT(sxae_hap_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_hap_member_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("packed_size","int32",4,4,SX_SIZE),
    SX_FIELD("crc32","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("unknown","uint8[4]",12,4,SX_NONE),
    SX_FIELD("flags","uint8",16,1,SX_FLAGS),
    SX_FIELD("unknown17","uint8",17,1,SX_NONE),
    SX_FIELD("time","uint16",18,2,SX_NONE),
    SX_FIELD("date","uint16",20,2,SX_NONE),
    SX_FIELD("unpacked_size","int32",22,4,SX_SIZE),
    SX_FIELD("name","char[13]",26,13,SX_STRING),
    SX_FIELD("method","uint8",39,1,SX_ID),
};
const sx_layout sxae_hap_member = {UINT32_C(0x6017001d),"hap_member",sxae_hap_member_fields,SX_COUNT(sxae_hap_member_fields),SX_LE};
static bool sxae_hap(sx_context *c)
{
 uint8_t b[40];int64_t p=15;if(!sx_read(c,0,b,15)||sxae32(b)!=UINT32_C(0x46483391)||!sxae_add(c,&sxae_hap_header,0))return false;
 for(unsigned i=0;p<c->size&&i<20000;i++){if(!sx_read(c,p,b,40)||sxae32(b)!=UINT32_C(0x574a688e)||!sxae_add(c,&sxae_hap_member,p))return false;uint32_t n=sxae32(b+4);if(n>INT32_MAX||!sxae_data(c,p+40,n))return false;p+=40+n;}return p==c->size;
}
bool sx_hap_build(sx_context*c)
{
 return sxae_hap(c);
}
