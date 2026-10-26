/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * vice snapshot data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_vice_snapshot_header_fields[] = {
 SX_FIELD("signature","char[19]",0,19,SX_SIGNATURE),
 SX_FIELD("major","uint8",19,1,SX_NONE),
 SX_FIELD("minor","uint8",20,1,SX_NONE),
 SX_FIELD("machine","char[16]",21,16,SX_NONE),
};
const sx_layout sxbx_vice_snapshot_header = {UINT32_C(0x6030000a),"vice_snapshot_header",sxbx_vice_snapshot_header_fields,SX_COUNT(sxbx_vice_snapshot_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_vice_version_header_fields[] = {
 SX_FIELD("signature","char[13]",0,13,SX_SIGNATURE),
 SX_FIELD("major","uint8",13,1,SX_NONE),
 SX_FIELD("minor","uint8",14,1,SX_NONE),
 SX_FIELD("build","uint8",15,1,SX_NONE),
 SX_FIELD("revision","uint8",16,1,SX_NONE),
 SX_FIELD("svn_revision","uint32",17,4,SX_NONE),
};
const sx_layout sxbx_vice_version_header = {UINT32_C(0x6030000b),"vice_version_header",sxbx_vice_version_header_fields,SX_COUNT(sxbx_vice_version_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_vice_module_header_fields[] = {
 SX_FIELD("name","char[16]",0,16,SX_NONE),
 SX_FIELD("major","uint8",16,1,SX_NONE),
 SX_FIELD("minor","uint8",17,1,SX_NONE),
 SX_FIELD("module_size","uint32",18,4,SX_SIZE),
};
const sx_layout sxbx_vice_module_header = {UINT32_C(0x6030000c),"vice_module_header",sxbx_vice_module_header_fields,SX_COUNT(sxbx_vice_module_header_fields),SX_LE};
#define SXBX_LIMIT 20000U
static bool sxbx_vice(sx_context*c){uint8_t b[22];uint64_t p=37;if(!sxbx_add(c,&sxbx_vice_snapshot_header,0))return false;if(sxbx_read(c,p,b,21)&&!xx_rt_memcmp(b,"VICE Version\x1a",13)){if(!sxbx_add(c,&sxbx_vice_version_header,p))return false;p+=21;}for(unsigned i=0;i<4096&&c->count<SXBX_LIMIT;i++){if(!sxbx_read(c,p,b,22))break;uint64_t z=sxbx32(b+18,false);if(z<=22||!sxbx_span(c,p,z))break;if(!sxbx_add(c,&sxbx_vice_module_header,p))return false;p+=z;}return true;}
bool sx_vice_snapshot_build(sx_context*c)
{
 return sxbx_vice(c);
}
