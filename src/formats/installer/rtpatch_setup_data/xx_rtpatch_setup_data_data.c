/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RTPATCH_SETUP_DATA data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_rtpatch_setup_member_fields[] = {
 SX_FIELD("compressed_size","int32",0,4,SX_SIZE),
 SX_FIELD("uncompressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("attributes","uint16",8,2,SX_FLAGS),
 SX_FIELD("dos_date","uint16",10,2,SX_NONE),
 SX_FIELD("dos_time","uint16",12,2,SX_NONE),
 SX_FIELD("name_size","uint16",14,2,SX_SIZE),
};
const sx_layout sxan_rtpatch_setup_member = {UINT32_C(0x60770020),"rtpatch_setup_member",sxan_rtpatch_setup_member_fields,SX_COUNT(sxan_rtpatch_setup_member_fields),SX_LE};
static bool sxan_rtsetup(sx_context*c){uint64_t p=0,n,z;while(sxan_span(c,p,16)){if(!sxan_word(c,p,4,false,&z)||z>INT32_MAX||!sxan_word(c,p+14,2,false,&n)||n<2||n>13||!sxan_add(c,&sxan_rtpatch_setup_member,p)||!sxan_named(c,p+16,n))return false;p+=16+n;if(!sxan_span(c,p,z))return true;p+=z;}return true;}
bool sx_rtpatch_setup_data_build(sx_context*c)
{
bool ok=false;
ok=sxan_rtsetup(c);
(void)ok;return c->count&&sxan_finish(c);
}
