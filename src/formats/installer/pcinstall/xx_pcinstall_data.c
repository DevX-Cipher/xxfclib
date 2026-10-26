/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PCINSTALL data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_pcinstall_header_fields[] = {
 SX_FIELD("zero","uint8[13]",0,13,SX_NONE),
 SX_FIELD("tag","uint8",13,1,SX_SIGNATURE),
 SX_FIELD("member_count","uint16",14,2,SX_COUNT_PROP),
 SX_FIELD("tag2","uint32",16,4,SX_SIGNATURE),
 SX_FIELD("reserved","uint8[36]",20,36,SX_NONE),
};
const sx_layout sxan_pcinstall_header = {UINT32_C(0x60770013),"pcinstall_header",sxan_pcinstall_header_fields,SX_COUNT(sxan_pcinstall_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_pcinstall_member_fields[] = {
 SX_FIELD("name","char[20]",0,20,SX_NONE),
 SX_FIELD("compressed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",24,2,SX_NONE),
 SX_FIELD("dos_time","uint16",26,2,SX_NONE),
 SX_FIELD("reserved","uint8[20]",28,20,SX_NONE),
};
const sx_layout sxan_pcinstall_member = {UINT32_C(0x60770014),"pcinstall_member",sxan_pcinstall_member_fields,SX_COUNT(sxan_pcinstall_member_fields),SX_LE};
static bool sxan_pcinstall(sx_context*c){uint64_t n,p=56,z;if(!sxan_add(c,&sxan_pcinstall_header,0)||!sxan_word(c,14,2,false,&n))return false;for(uint64_t i=0;i<n;i++){if(!sxan_add(c,&sxan_pcinstall_member,p)||!sxan_word(c,p+20,4,false,&z))return false;p+=48;if(!sxan_span(c,p,z))return true;p+=z;}return true;}
bool sx_pcinstall_build(sx_context*c)
{
bool ok=false;
ok=sxan_pcinstall(c);
(void)ok;return c->count&&sxan_finish(c);
}
