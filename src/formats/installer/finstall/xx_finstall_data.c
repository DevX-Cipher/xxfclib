/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FINSTALL data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_finstall_header_fields[] = {
 SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("signature","char[10]",1,10,SX_SIGNATURE),
 SX_FIELD("version","char[1]",11,1,SX_NONE),
 SX_FIELD("capacity","uint32",12,4,SX_SIZE),
 SX_FIELD("member_count","uint16",16,2,SX_COUNT_PROP),
};
const sx_layout sxan_finstall_header = {UINT32_C(0x60770015),"finstall_header",sxan_finstall_header_fields,SX_COUNT(sxan_finstall_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_finstall_member_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("name","char[16]",8,16,SX_NONE),
};
const sx_layout sxan_finstall_member = {UINT32_C(0x60770016),"finstall_member",sxan_finstall_member_fields,SX_COUNT(sxan_finstall_member_fields),SX_LE};
static bool sxan_finstall(sx_context*c){uint64_t n;return sxan_add(c,&sxan_finstall_header,0)&&sxan_word(c,16,2,false,&n)&&sxan_table(c,&sxan_finstall_member,18,24,n);}
bool sx_finstall_build(sx_context*c)
{
bool ok=false;
ok=sxan_finstall(c);
(void)ok;return c->count&&sxan_finish(c);
}
