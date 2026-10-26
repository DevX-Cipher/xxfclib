/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Clay archives (*.cmz) data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_clay_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",12,2,SX_NONE),
 SX_FIELD("dos_time","uint16",14,2,SX_NONE),
 SX_FIELD("name_size","uint16",16,2,SX_SIZE),
 SX_FIELD("unused","uint16",18,2,SX_NONE),
};
const sx_layout sxafr_clay_member = {UINT32_C(0x6054002b),"clay_member",sxafr_clay_member_fields,SX_COUNT(sxafr_clay_member_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_clay_prefix_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("window_exponent","uint8",1,1,SX_NONE),
};
const sx_layout sxafr_clay_prefix = {UINT32_C(0x6054002d),"clay_prefix",sxafr_clay_prefix_fields,SX_COUNT(sxafr_clay_prefix_fields),SX_LE};
static bool sxafr_clay(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){uint8_t h[20];if(!sxafr_read(c,p,h,20)||xx_rt_memcmp(h,"Clay",4))return false;uint64_t z=sxafr_uint(h+4,4,false),names=sxafr_uint(h+16,2,false);if(!names||names>4096||!sxafr_span(c,p+20,names)||!sxafr_add(c,&sxafr_clay_member,p))return false;p+=20+names;if(z>=2&&sxafr_span(c,p,2)&&!sxafr_add(c,&sxafr_clay_prefix,p))return false;if(!sxafr_span(c,p,z))return true;p+=z;}return true;}
bool sx_claylz_build(sx_context*c)
{
 return sxafr_clay(c);
}
