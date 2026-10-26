/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MI10 crunched block chains data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_mi10_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",12,4,SX_SIZE),
};
const sx_layout sxafr_mi10_member = {UINT32_C(0x60540004),"mi10_member",sxafr_mi10_member_fields,SX_COUNT(sxafr_mi10_member_fields),SX_BE};
static const xx_data_struct_field_desc sxafr_mi10_prefix_fields[] = {
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("escape","uint8",1,1,SX_NONE),
};
const sx_layout sxafr_mi10_prefix = {UINT32_C(0x60540005),"mi10_prefix",sxafr_mi10_prefix_fields,SX_COUNT(sxafr_mi10_prefix_fields),SX_LE};
static bool sxafr_mi10(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){uint8_t h[16];if((p&1)||!sxafr_read(c,p,h,16)||xx_rt_memcmp(h,"MI10",4))return false;uint64_t z=sxafr_uint(h+12,4,true);if(!z||!sxafr_span(c,p+16,z+2)||!sxafr_add(c,&sxafr_mi10_member,p)||!sxafr_add(c,&sxafr_mi10_prefix,p+16))return false;p+=18+z;for(unsigned i=0;i<2&&p<(uint64_t)c->size;i++){uint8_t b;if(!sxafr_read(c,p,&b,1))return false;if(b!=0x6b)break;p++;}}return true;}
bool sx_mi10_build(sx_context*c)
{
 return sxafr_mi10(c);
}
